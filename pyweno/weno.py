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
import pyweno.cweno


######################################################################
# private helpers
#

def _omegaerr(omega, cs, c):
    """Helper function for computing the sum of squared errors."""

    n   = cs.shape[0]
    k   = omega.size
    err = np.zeros(n*(2*k-1))

    for l in xrange(n):
        for j in xrange(2*k-1):
            err[l*n+j] = cs[l,j]

            rl = max(0,j-k+1)
            ru = min(k-1,j)
            for r in xrange(rl,ru+1):
                err[l*n+j] = err[l*n+j] - omega[k-(j+1)+r] * c[k-(j+1)+r,l,r]

    return np.linalg.norm(err)

def _makecons(j):
    """Helper function for creating optimisation constraints."""

    return lambda x: x[j]


######################################################################
# WENO
#

class WENO(object):
    """Weighted Essentially Non-Oscillatory reconstruction.

    XXX: this docstring needs work!

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

    c = {}                              # reconstruction coeffs
    w = {}                              # optimal weights

    _q = {}                             # pre-allocated storage
    _w = {}                             # pre-allocated storage

    _omega_error = {}                   # maximum error produced by optimal weights

    ##################################################################
    # init
    #

    def __init__(self,
                 order,
                 cache=None,
                 format='hdf5',
                 smoothness=None,
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
        if smoothness is None:
            self._smoothness = pyweno.smoothness.szs3
        else:
            self._smoothness = smoothness


    def _init_with_cache(self, cache, order, format):

        self.order = order

        if format is 'hdf5':
            import h5py as h5

            hdf = h5.File(cache, 'r')

            try:
                k_sgrp = hdf['weno/k%d' % (self.order)]

                for key in k_sgrp:

                    dst = k_sgrp[key + '/c']
                    self.c[key] = np.zeros(dst.shape)
                    self.c[key][:,:,:,:] = dst[:,:,:,:]

                    dst = k_sgrp[key + '/w']
                    self.w[key] = np.zeros(dst.shape)
                    self.w[key][:,:] = dst[:,:]

                    self.pre_allocate(key)

            finally:
                hdf.close()

            self.grid = pyweno.grid.Grid(cache=cache, format='hdf5')

        else:
            raise ValueError, "cache format '%s' not supported" % (format)


    def _init_with_grid(self, grid, order):

        self.grid  = grid
        self.order = order

    def pre_allocate(self, key):

        shape = self.c[key].shape

        N = shape[0]
        k = shape[1]
        n = shape[2]

        self._q[key] = np.zeros((N,k,n))
        self._w[key] = np.zeros((N,k))


    ##################################################################
    # reconstruction
    #

    def reconstruction(self, key, xi=None):
        """XXX."""

        grid = self.grid
        N = self.grid.N
        k = self.order

        # order 2k-1 coeffs (c^*)
        stncl = pyweno.stencil.Stencil(grid=grid, order=2*k-1, shift=k-1)
        stncl.reconstruction_coeffs(key, xi)

        shape = stncl.c[key].shape      # (N, 2k-1) or (N, n, 2k-1)
        if (len(shape)) > 2:
            n = shape[1]
            cstar = stncl.c[key]
        else:
            n = 1
            cstar = np.empty((N,1,2*k-1))
            cstar[:,0,:] = stncl.c[key][:,:]

        # order k coeffs: c[i,r,l,j]
        c = np.zeros((N,k,n,k))
        for r in xrange(k):
            stncl = pyweno.stencil.Stencil(grid=grid, order=k, shift=r)
            stncl.reconstruction_coeffs(key, xi)
            if n == 1:
                c[:,r,0,:] = stncl.c[key][:,:]
            else:
                c[:,r,:,:] = stncl.c[key][:,:,:]

        # optimal weights (varpi)
        w = np.zeros((N,k))

        if grid.structured:

            # XXX: this can be made better...

            wc = np.zeros(k)
            merr = 0.0

            f = lambda x: _omegaerr(x, cstar[N/2,:,:], c[N/2,:,:,:])
            x0 = 0.5 * np.ones(k)

            # constraints: w^r_i >= 0, sum_{r=0}^{k-1} w^r_i = 1
            cons = list(range(k))
            for j in xrange(k):
                cons[j] = _makecons(j)
            cons.append(lambda x: 1.0 - sum(x))
            cons.append(lambda x: sum(x) - 1.0)

            wc[:] = scipy.optimize.fmin_cobyla(f, x0, cons, rhoend=1e-12, iprint=0)

            # reset w^r_i to 0.0 if w^r_i <= 1e-12
            for j in xrange(k):
                if wc[j] <= 1e-12:
                    wc[j] = 0.0

            # maximum error
            err = f(wc[:])
            if err > merr:
                merr = err

            for i in xrange(k,N-k):
                w[i,:] = wc[:]


        else:
            merr = 0.0
            for i in xrange(k,N-k):

                # function to minimise and initial guess
                f = lambda x: _omegaerr(x, cstar[i,:,:], c[i,:,:,:])
                x0 = 0.5 * np.ones(k)

                # constraints: w^r_i >= 0, sum_{r=0}^{k-1} w^r_i = 1
                cons = list(range(k))
                for j in xrange(k):
                    cons[j] = _makecons(j)
                cons.append(lambda x: 1.0 - sum(x))
                cons.append(lambda x: sum(x) - 1.0)

                w[i,:] = scipy.optimize.fmin_cobyla(f, x0, cons, rhoend=1e-12, iprint=0)

                # reset w^r_i to 0.0 if w^r_i <= 1e-12
                for j in xrange(k):
                    if w[i,j] <= 1e-12:
                        w[i,j] = 0.0

                # maximum error
                err = f(w[i,:])
                if err > merr:
                    merr = err


        # store and pre-allocate
        self.c[key] = c
        self.w[key] = w

        self.pre_allocate(key)

        self._omega_error[key] = merr


    ##################################################################
    # cache
    #

    def cache(self, output, format='hdf5'):
        """Cache spatial grid, reconstruction coefficients, and
           optimal weights."""

        if format is 'hdf5':
            import h5py as h5

            hdf = h5.File(output, 'a')

            try:
                if 'weno' in hdf:
                    sgrp = hdf['weno']
                else:
                    sgrp = hdf.create_group('weno')

                kstr = 'k%d' % (self.order)
                if kstr in sgrp:
                    k_sgrp = sgrp[kstr]
                else:
                    k_sgrp = sgrp.create_group(kstr)

                for key in self.c:
                    key_sgrp = k_sgrp.create_group(key)
                    key_sgrp.create_dataset('c', data=self.c[key])
                    key_sgrp.create_dataset('w', data=self.w[key])

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

        return self._smoothness(self.grid, self.order, q, sigma)


    def omega(self, q, varpi, sigma, w):
        """Return arrays of adjusted weights."""

        # XXX: deprecated

        N   = self.grid.N
        k   = self.order

        alpha = np.zeros((N,k))

        # XXX: move to C
        for i in xrange(k,N-(k-1)+1):
            for r in xrange(k):
                alpha[i,r] = varpi[i,r] / (10e-6 + sigma[i,r]) / (10e-6 + sigma[i,r])

            sum_alpha = sum(alpha[i,:])
            for r in xrange(k):
                w[i,r] = alpha[i,r] / sum_alpha


    ##################################################################
    # reconstruct!
    #

    def reconstruct(self, q, key, sigma, qs):
        """Reconstruct q.

           XXX: more info here

           should be called as, eg:

             weno.smoothness(q, sigma)
             weno.reconstruct(q, 'left', sigma, ql)
             weno.reconstruct(q, 'right', sigma, qr)

        """

        c = self.c[key]
        w = self.w[key]

        _q = self._q[key]
        _w = self._w[key]

        pyweno.cweno.reconstruct(q, sigma, c, w, _q, _w, qs)



#         shape = c.shape
#         N = shape[0]
#         k = shape[1]
#         n = shape[2]

#         qr = self._qr[key]
#         w  = self._w[key]

#         # XXX: move to C
#         for i in xrange(k,N-k):
#             for r in xrange(k):
#                 for l in xrange(n):
#                     qr[i,l,r] = np.dot(c[i,r,l,:], q[i-r:i-r+k])

#         self.omega(q, self.w[key], sigma, w)

#         if n == 1:
#             # XXX: move to C
#             for i in xrange(k,N-k):
#                 qs[i] = np.dot(qr[i,0,:], w[i,:])
#         else:
#             # XXX: move to C
#             for i in xrange(k,N-k):
#                 for l in xrange(n):
#                     qs[i,l] = np.dot(qr[i,l,:], w[i,:])
