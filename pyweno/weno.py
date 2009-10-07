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
      * *c_m*   - matrix of coefficients :math:`\\tilde{c}^r_{ij}` (indexed as c_m[i,r,j])
      * *c_p*   - matrix of coefficients :math:`c^r_{ij}` (indexed as c_p[i,r,j])
      * *w_m*   - matrix of optimal weights :math:`\\tilde{\\varpi}^r_i` (indexed as w_m[i,r])
      * *w_p*   - matrix of optimal weights :math:`\\varpi^r_i` (indexed as w_p[i,r])

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
        self.alpha_m = np.zeros((N+1,k))
        self.alpha_p = np.zeros((N+1,k))
        self.omega_m = np.zeros((N+1,k))
        self.omega_p = np.zeros((N+1,k))
        self.vr_m = np.zeros((N,k))
        self.vr_p = np.zeros((N,k))


    def _init_with_cache(self, cache, order, format):

        self.order = order

        if format is 'hdf5':
            import h5py as h5

            hdf = h5.File(cache, "r")

            try:
                grp = hdf["weno/%d" % (self.order)]

                dst = grp["c_m"]
                self.c_m = dst[:,:,:]
                dst = grp["c_p"]
                self.c_p = dst[:,:,:]
                dst = grp["w_m"]
                self.w_m = dst[:,:]
                dst = grp["w_p"]
                self.w_p = dst[:,:]

            finally:
                hdf.close()

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
        cstarm = stncl.c_m
        cstarp = stncl.c_p

        # order k coeffs: c[i,r,j]
        c_m = np.zeros((N,k,k))
        c_p = np.zeros((N,k,k))
        for l in xrange(k):
            stncl      = pyweno.stencil.Stencil(grid=grid, order=k, shift=l)
            c_m[:,l,:] = stncl.c_m[:,:]
            c_p[:,l,:] = stncl.c_p[:,:]


        # weights
        w_m = np.zeros((N,k))
        w_p = np.zeros((N,k))

        merr = 0.0
        for i in xrange(k,N-k):

            # function to minimise and initial guess
            fm = lambda x: _omegaerr(x, cstarm[i,:], c_m[i,:,:])
            fp = lambda x: _omegaerr(x, cstarp[i,:], c_p[i,:,:])
            x0 = 0.5 * np.ones(k)

            # constraints: w^r_i >= 0, sum_{r=0}^{k-1} w^r_i = 1
            cons = list(range(k))
            for j in xrange(k):
                cons[j] = _makecons(j)
            cons.append(lambda x: 1.0 - sum(x))
            cons.append(lambda x: sum(x) - 1.0)

            w_p[i,:] = scipy.optimize.fmin_cobyla(fp, x0, cons, rhoend=1e-12, iprint=0)
            w_m[i,:] = scipy.optimize.fmin_cobyla(fm, x0, cons, rhoend=1e-12, iprint=0) # XXX: this isn't necessary (by symmetry)

            # reset w^r_i to 0.0 if w^r_i <= 1e-12
            for j in xrange(k):
                if w_m[i,j] <= 1e-12:
                    w_m[i,j] = 0.0
                if w_p[i,j] <= 1e-12:
                    w_p[i,j] = 0.0

            # maximum error
            err = fp(w_p[i,:])
            if err > merr:
                merr = err

            err = fm(w_m[i,:])
            if err > merr:
                merr = err

        # done
        self.c_m = c_m
        self.c_p = c_p
        self.w_m = w_m
        self.w_p = w_p
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
                sgrp.create_dataset("c_m", data=self.c_m)
                sgrp.create_dataset("c_p", data=self.c_p)
                sgrp.create_dataset("w_m", data=self.w_m)
                sgrp.create_dataset("w_p", data=self.w_p)

            finally:
                hdf.close()

        else:
            raise ValueError, "cache format '%s' not supported" % (format)


    ##################################################################
    # smoothness, omega
    #

    def smoothness(self, q, sigma):
        """Return array of the smoothness indicators of q."""

        return self._smoothness(self.grid, self.grid.N, self.order, q, sigma)


    def omega(self, q, vr_m, vr_p, omega_m, omega_p):
        """Return arrays of adjusted weights."""

        N   = self.grid.N
        k   = self.order
        w_m = self.w_m
        w_p = self.w_p

        sigma = self.sigma
        alpha_m = self.alpha_m
        alpha_p = self.alpha_p

        self.smoothness(q, sigma)

        for i in xrange(k,N-(k-1)+1):
            for r in xrange(k):
                alpha_m[i,r] = w_m[i,r] / (10e-6 + sigma[i,r]) / (10e-6 + sigma[i,r])
                alpha_p[i,r] = w_p[i,r] / (10e-6 + sigma[i,r]) / (10e-6 + sigma[i,r])

            a_m = sum(alpha_m[i,:])
            a_p = sum(alpha_p[i,:])
            for r in xrange(k):
                omega_m[i,r] = alpha_m[i,r] / a_m
                omega_p[i,r] = alpha_p[i,r] / a_p


    ##################################################################
    # reconstruct!
    #

    def reconstruct(self, q, v_m, v_p):
        """Reconstruct q.

           XXX: expand this...

           XXX: quadrature?
        """

        N   = self.grid.N
        k   = self.order

        c_m = self.c_m
        c_p = self.c_p
        vr_m = self.vr_m
        vr_p = self.vr_p
        omega_m = self.omega_m
        omega_p = self.omega_p

        # XXX: this is slow, move to C
        for i in xrange(k,N-k):
            for r in xrange(k):
                vr_m[i,r] = np.dot(c_m[i,r,:], q[i-r:i-r+k])
                vr_p[i,r] = np.dot(c_p[i,r,:], q[i-r:i-r+k])

        self.omega(q, vr_m, vr_p, omega_m, omega_p)

        for i in xrange(k,N-k):
            v_m[i] = np.dot(vr_m[i,:], omega_m[i,:])
            v_p[i] = np.dot(vr_p[i,:], omega_p[i,:])
