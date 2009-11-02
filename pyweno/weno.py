"""PyWENO WENO class.

   Indexing conventions:

     * There are N cells C_i, where i=1,...,N.

     * A quantity X that depends on the cell C_i is indexed as X[i-1].

     * A quantity X that depends on the cell boundary at x_{i-1/2} is
       indexed as X[i-1].

"""

import math
import sys

import numpy as np
import scipy.optimize

import pyweno.stencil
import pyweno.smoothness

######################################################################
# private helpers
#

def _omegaerr(omega, cs, c):
    """Helper function for computing the sum of squared errors."""

    k   = omega.size
    err = np.zeros(2*k-1)

    for j in xrange(2*k-1):
        err[j] = cs[j]

        ll = max(0,j-k+1)
        lu = min(k-1,j)
        for l in xrange(ll,lu+1):
            err[j] = err[j] - omega[k-(j+1)+l] * c[k-(j+1)+l,l]

    return np.linalg.norm(err)

def _makecons(j):
    """Helper function for creating optimisation constraints."""

    return lambda x: x[j]


######################################################################
# WENO
#

class WENO(object):
    """Weighted Essentially Non-Oscillatory reconstruction.

    The basic idea of WENO is to use a convex combination of several
    stencils to form the reconstruction of :math:`v` at cell
    boundaries, and, if a stencil contains a discontinuity, its weight
    :math:`\omega` should be close to zero.  In smooth regions, using
    several stencils will also serve to increase the order of
    accuracy.

    Briefly, a WENO reconstruction takes a convex combination of all
    :math:`v_{i+1/2}^r` defined by

      :math:`v_{i+1/2}^r = \sum_{j=0}^{k-1}\; c_{ij}^r \\bar{v}_{i-r+j} \quad \\text{ for } \quad r=0,\dots,k-1`

    as a new approximation to :math:`v_{i+1/2}` according to

      :math:`v_{i+1/2} = \sum_{r=0}^{k-1} \omega_i^r v_{i+1/2}^r`

    where we require :math:`\omega_i^r \geq 0` and :math:`\sum_{r=0}^{k-1} \omega_i^r = 1`.

    Instance variables:

      * *grid*  - spatial grid (''pyweno.Grid'')
      * *order* - order of approximation
      * *c_l*   - matrix of coefficients :math:`\\tilde{c}^r_{ij}` (indexed as c_l[i,r,j])
      * *c_r*   - matrix of coefficients :math:`c^r_{ij}` (indexed as c_r[i,r,j])
      * *w_l*   - matrix of optimal weights :math:`\\tilde{\\varpi}^r_i` (indexed as w_l[i,r])
      * *w_r*   - matrix of optimal weights :math:`\\varpi^r_i` (indexed as w_r[i,r])

    The constructor precomputes the reconstruction coefficients
    :math:`c^r_{ij}` of order *order* and the optimal weights
    :math:`\\varpi^{r}_{i}` for the unstructered grid *grid*, or loads
    them from a cache.

    Arguments (without cache):

      * *grid*    - spatial grid (*Grid*)
      * *order*   - order of approximation

    Arguments (with cache):

      * *cache*  - cache file
      * *format* - format of cache file (hdf5 by default)

    """

    ##################################################################
    # init
    #

    def __init__(self,
                 order,
                 cache=None,
                 format='hdf5',
                 smoothness=pyweno.smoothness.szs3,
                 grid=None):

        # compute or load from cache
        if (grid is None) and (cache is None):
            raise ValueError, 'one of grid or cache must be specified'
        elif (grid is not None) and (cache is not None):
            raise ValueError, 'both grid and cache cannot be specified'
        elif (grid is not None):
            self._init_with_grid(grid, order)
        else:
            self._init_with_cache(cache, order, format)

        # smoothness
        self._smoothness = smoothness

        # pre-allocate
        N = self.grid.N
        k = self.order

        self.sigma = np.zeros((N+1,k))
        self.alpha_l = np.zeros((N+1,k))
        self.alpha_r = np.zeros((N+1,k))
        self.omega_l = np.zeros((N+1,k))
        self.omega_r = np.zeros((N+1,k))
        self.vr_l = np.zeros((N,k))
        self.vr_r = np.zeros((N,k))


    def _init_with_cache(self, cache, order, format):

        self.order = order

        if format is 'hdf5':
            import h5py as h5

            hdf = h5.File(cache, "r")

            try:
                grp = hdf["weno/%d" % (self.order)]

                dst = grp["c_l"]
                self.c_l = dst[:,:,:]
                dst = grp["c_r"]
                self.c_r = dst[:,:,:]
                dst = grp["w_l"]
                self.w_l = dst[:,:]
                dst = grp["w_r"]
                self.w_r = dst[:,:]

            finally:
                hdf.close()

            self.grid = pyweno.grid.Grid(cache=cache, format='hdf5')

        else:
            raise ValueError, "cache format '%s' not supported" % (format)


    def _init_with_grid(self, grid, order):

        self.grid  = grid
        self.order = order

        N = self.grid.N
        k = self.order

        #
        # compute optimal weights $\varpi$
        #

        stncl  = pyweno.stencil.Stencil(grid=grid, order=2*k-1, shift=k-1)
        stncl.reconstruction_coeffs('left')
        stncl.reconstruction_coeffs('right')
        cstarm = stncl.c['left']
        cstarp = stncl.c['right']

        # order k coeffs: c[i,r,j]
        c_l = np.zeros((N,k,k))
        c_r = np.zeros((N,k,k))
        for l in xrange(k):
            stncl = pyweno.stencil.Stencil(grid=grid, order=k, shift=l)
            stncl.reconstruction_coeffs('left')
            stncl.reconstruction_coeffs('right')
            c_l[:,l,:] = stncl.c['left'][:,:]
            c_r[:,l,:] = stncl.c['right'][:,:]


        # weights
        w_l = np.zeros((N,k))
        w_r = np.zeros((N,k))

        merr = 0.0
        for i in xrange(k,N-k):

            # function to minimise and initial guess
            fm = lambda x: _omegaerr(x, cstarm[i,:], c_l[i,:,:])
            fp = lambda x: _omegaerr(x, cstarp[i,:], c_r[i,:,:])
            x0 = 0.5 * np.ones(k)

            # constraints: w^r_i >= 0, sum_{r=0}^{k-1} w^r_i = 1
            cons = list(range(k))
            for j in xrange(k):
                cons[j] = _makecons(j)
            cons.append(lambda x: 1.0 - sum(x))
            cons.append(lambda x: sum(x) - 1.0)

            # XXX: the second call isn't necessary (by symmetry)
            w_r[i,:] = scipy.optimize.fmin_cobyla(fp, x0, cons, rhoend=1e-12, iprint=0)
            w_l[i,:] = scipy.optimize.fmin_cobyla(fm, x0, cons, rhoend=1e-12, iprint=0)

            # reset w^r_i to 0.0 if w^r_i <= 1e-12
            for j in xrange(k):
                if w_l[i,j] <= 1e-12:
                    w_l[i,j] = 0.0
                if w_r[i,j] <= 1e-12:
                    w_r[i,j] = 0.0

            # maximum error
            err = fp(w_r[i,:])
            if err > merr:
                merr = err

            err = fm(w_l[i,:])
            if err > merr:
                merr = err

        # done
        self.c_l = c_l
        self.c_r = c_r
        self.w_l = w_l
        self.w_r = w_r
        self._omega_error = merr


    ##################################################################
    # cache
    #

    def cache(self, output, format='hdf5'):
        """Cache spatial grid, reconstruction coefficients, and
           optimal weights."""

        if format is 'hdf5':
            import h5py as h5

            hdf = h5.File(output, "a")

            try:
                if "weno" in hdf:
                    del hdf["weno"]

                sgrp = hdf.create_group("weno")
                sgrp = sgrp.create_group("%d" % (self.order))
                sgrp.create_dataset("c_l", data=self.c_l)
                sgrp.create_dataset("c_r", data=self.c_r)
                sgrp.create_dataset("w_l", data=self.w_l)
                sgrp.create_dataset("w_r", data=self.w_r)

            finally:
                hdf.close()

            self.grid.cache(output, 'hdf5')

        else:
            raise ValueError, "cache format '%s' not supported" % (format)




    ##################################################################
    # smoothness, omega
    #

    def smoothness(self, q, sigma):
        """Return array of the smoothness indicators of q."""

        return self._smoothness(self.grid, self.grid.N, self.order, q, sigma)


    def omega(self, q, vr_l, vr_r, omega_l, omega_r):
        """Return arrays of adjusted weights."""

        N   = self.grid.N
        k   = self.order
        w_l = self.w_l
        w_r = self.w_r

        sigma = self.sigma
        alpha_l = self.alpha_l
        alpha_r = self.alpha_r

        self.smoothness(q, sigma)

        for i in xrange(k,N-(k-1)+1):
            for r in xrange(k):
                alpha_l[i,r] = w_l[i,r] / (10e-6 + sigma[i,r]) / (10e-6 + sigma[i,r])
                alpha_r[i,r] = w_r[i,r] / (10e-6 + sigma[i,r]) / (10e-6 + sigma[i,r])

            a_l = sum(alpha_l[i,:])
            a_r = sum(alpha_r[i,:])
            for r in xrange(k):
                omega_l[i,r] = alpha_l[i,r] / a_l
                omega_r[i,r] = alpha_r[i,r] / a_r


    ##################################################################
    # reconstruct!
    #

    def reconstruct(self, q, v_m, v_p):
        """Reconstruct q.

           XXX: more info here

           XXX: quadrature?
        """

        N   = self.grid.N
        k   = self.order

        c_l = self.c_l
        c_r = self.c_r
        vr_l = self.vr_l
        vr_r = self.vr_r
        omega_l = self.omega_l
        omega_r = self.omega_r

        # XXX: this is slow, move to C
        for i in xrange(k,N-k):
            for r in xrange(k):
                vr_l[i,r] = np.dot(c_l[i,r,:], q[i-r:i-r+k])
                vr_r[i,r] = np.dot(c_r[i,r,:], q[i-r:i-r+k])

        self.omega(q, vr_l, vr_r, omega_l, omega_r)

        for i in xrange(k,N-k):
            v_p[i] = np.dot(vr_l[i,:], omega_l[i,:])
            v_m[i] = np.dot(vr_r[i-1,:], omega_r[i-1,:])
