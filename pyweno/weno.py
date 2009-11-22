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
import pyweno.csmoothness
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
      * *format* - format of cache file (default is 'mat')

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
                 order=3,
                 cache=None,
                 format='mat',
                 smoothness='jiang_shu',
                 grid=None):

        # compute or load from cache
        if (grid is None) and (cache is None):
            raise ValueError, 'one of grid or cache must be specified'
        elif (grid is not None) and (cache is not None):
            raise ValueError, 'both grid and cache cannot be specified'
        elif (grid is not None):
            self._init_with_grid(grid, order, smoothness)
        else:
            self._init_with_cache(cache, order, format)


    def _init_with_cache(self, cache, order, format):

        self.order = order

        if format is 'h5py':
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

                    self._pre_allocate_key(key)

                dst = k_sgrp['beta']
                self.beta = np.zeros(dst.shape)
                self.beta[:,:,:,:] = dst[:,:,:,]

            finally:
                hdf.close()

            self.grid = pyweno.grid.Grid(cache=cache, format='h5py')

        elif format is 'mat':
            import scipy.io as sio
            import re

            mat = sio.loadmat(cache, struct_as_record=True)

            self.c = {}
            self.w = {}
            for key in mat:
                m = re.match(r'weno.k(\d+).c.(.+)', key)
                if (m is not None) and (int(m.group(1)) == order):
                    self.c[m.group(2)] = mat[m.group(0)]

                m = re.match(r'weno.k(\d+).w.(.+)', key)
                if (m is not None) and (int(m.group(1)) == order):
                    self.w[m.group(2)] = mat[m.group(0)]
                    self._pre_allocate_key(m.group(2))

            self.beta = mat['weno.beta']
            self.grid = pyweno.grid.Grid(cache=cache, format='mat')

        else:
            raise ValueError, "cache format '%s' not supported" % (format)


    def _init_with_grid(self, grid, order, smoothness):

        self.grid  = grid
        self.order = order

        N = self.grid.size
        k = self.order

        # allocate beta, sigma
        self.sigma = np.zeros((N,k))
        self.beta = np.zeros((N,k,2*k-1,2*k-1))

        # pre-compute beta
        pyweno.smoothness.beta(smoothness, self.grid, self.order, self.beta)


    def _pre_allocate_key(self, key):

        shape = self.c[key].shape

        N = shape[0]
        k = shape[1]
        n = shape[2]

        self._q[key] = np.zeros((N,k,n))
        self._w[key] = np.zeros((N,k))


    ##################################################################
    # reconstruction
    #

    def precompute_reconstruction(self, key, xi=None):
        """Precompute reconstruction coefficients and optimal weights
           for reconstructing at the points specified by *key*.

           If *xi* is None, XXX

           If *xi* isn't None, XXX

        """

        grid = self.grid
        N = self.grid.size
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

        #### optimal weights (varpi)
        w = np.zeros((N,k))

        if grid.structured:

            #### structured grid, only do one cell

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

            # copy weights to other cells
            for i in xrange(k,N-k):
                w[i,:] = wc[:]

        else:

            #### unstructured grid, cycle through all cells

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
        self._omega_error[key] = merr

        self._pre_allocate_key(key)


    ##################################################################
    # cache
    #

    def cache(self, output, format='mat'):
        """Cache grid, reconstruction coefficients, and optimal
           weights.
        """

        k = self.order

        self.grid.cache(output, format)

        if format is 'h5py':
            import h5py as h5

            hdf = h5.File(output, 'a')

            try:
                if 'weno' in hdf:
                    sgrp = hdf['weno']
                else:
                    sgrp = hdf.create_group('weno')

                kstr = 'k%d' % (k)
                if kstr in sgrp:
                    del sgrp[kstr]

                k_sgrp = sgrp.create_group(kstr)

                for key in self.c:
                    key_sgrp = k_sgrp.create_group(key)
                    key_sgrp.create_dataset('c', data=self.c[key])
                    key_sgrp.create_dataset('w', data=self.w[key])

                k_sgrp.create_dataset('beta', data=self.beta)

            finally:
                hdf.close()

        elif format is 'mat':
            import scipy.io as sio

            try:
                mat = sio.loadmat(output, struct_as_record=True)
            except:
                mat = {}

            for key in self.c:
                mat['weno.k%d.c.%s' % (k, key)] = self.c[key]
                mat['weno.k%d.w.%s' % (k, key)] = self.w[key]

            mat['weno.beta'] = self.beta

            sio.savemat(output, mat)

        else:
            raise ValueError, "cache format '%s' not supported" % (format)


    ##################################################################
    # smoothness and reconstruct wrappers
    #

    def smoothness(self, q):
        """Compute smoothness indicators of *q*."""

        return pyweno.cmoothness.sigma(q, self.beta, self.sigma)


    def reconstruct(self, q, key, qs):
        """Reconstruct *q* at the points specified by *key* and store
           result in *qs*.
        """

        c = self.c[key]
        w = self.w[key]

        _q = self._q[key]
        _w = self._w[key]

        pyweno.cweno.reconstruct(q,
                                 self.sigma,
                                 self.c[key],
                                 self.w[key],
                                 self._q[key],
                                 self._w[key],
                                 qs)
