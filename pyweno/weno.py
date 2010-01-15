"""PyWENO WENO class.

   In the PyWENO documentation, the first cell has an index of 1.

   In the PyWENO code, the first cell has an index of 0.

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

def _omegaerr(omega, s, cs, c):
    """Helper function for computing the sum of squared errors.

       **Arguments:**

       * *omega* - guess for optimal weights, indexed as omega[r],
          where r is modified by the biasing
       * *cs* - order 2k-|s|-1 reconstruction coeffs (c^*), indexed as cs[n,j]
       * *c* - order k reconstruction coeffs (c^r), indexed as
          c[r,n,j], where r in unmodified

    """

    err = cs.flatten()

    k = c.shape[2]
    n = c.shape[1]

    for l in xrange(n):
        for j in xrange(2*k-abs(s)-1):

            rl = max(0, j-k+abs(s)+1)
            ru = min(k-1, j)

            for r in xrange(rl,ru+1):
                err[l*n+j] = err[l*n+j] - omega[k-abs(s)-(j+1)+r] * c[k+min(0,s)-(j+1)+r,l,r]

    return np.linalg.norm(err)

def _makecons(j):
    """Helper function for creating optimisation constraints."""
    return lambda x: x[j]


######################################################################
# WENO
#

class WENO(object):
    """Weighted Essentially Non-Oscillatory reconstruction class.

    **Basic usage**

    From scratch::

    >>> weno = pyweno.weno.WENO(grid=grid, order=k, shift=r)

    From a cache::

    >>> weno = pyweno.weno.WENO(order=k, cache='mycache.mat')

    Pre-compute reconstruction coefficients and optimal weights at the
    left and right boundaries::

    >>> weno.precompute_reconstruction('left')
    >>> weno.precompute_reconstruction('right')

    Given the cell averages ``f_avg`` of an unkown function *f*,
    reconstruct *f* at the left side of each cell::

    >>> f_left = np.zeros(grid.size)
    >>> weno.smoothness(f_avg)
    >>> weno.reconstruct(f_avg, 'left', f_left)

    Cache to a MATLAB file (through SciPy)::

    >>> weno.cache('mycache.mat')

    Cache to an HDF5 file (through H5PY)::

    >>> weno.cache('mycache.h5', format='h5py')

    **Instance variables**

    * *grid*  - spatial grid
    * *order* - order of stencil approximations
    * *beta*  - smoothness indicator coefficients
    * *c*     - dictionary of reconstruction coefficients
    * *w*     - dictionary of optimal weights

    **Keyword arguments (without cache)**

    * *grid*       - spatial grid (``pyweno.grid.Grid``)
    * *order*      - order of approximation
    * *smoothness* - type of smoothness indicator to use

    **Keyword arguments (with cache)**

    * *cache*  - cache file
    * *order*  - order of stencil approximation
    * *format* - format of cache file (default is ``'mat'``)

    **Methods**

    """

    c = {}                              # dictionary of reconstruction coeffs
    w = {}                              # dictionary of optimal weights
    wr = None                           # current weights
    qr = {}                             # dictionary of working space

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

        # allocate remaining buffers
        N = self.grid.size
        k = self.order

        self.wr = np.zeros((N,k))
        self.sigma = np.zeros((N,k))


    def _init_with_cache(self, cache, order, format):

        self.order = order

        self.c = {}
        self.w = {}

        if format is 'h5py':
            import h5py as h5
            import re

            hdf = h5.File(cache, 'r')

            try:
                k_sgrp = hdf['weno/k%d' % (self.order)]

                dst = k_sgrp['beta']
                self.beta = np.zeros(dst.shape)
                self.beta[:,:,:,:] = dst[:,:,:,:]

                for key in k_sgrp:

                    if key == 'beta':
                        continue

                    if key not in self.w:
                        self.w[key] = {}

                    key_sgrp = k_sgrp[key]

                    dst = key_sgrp['c']
                    self.c[key] = np.zeros(dst.shape)
                    self.c[key][:,:,:,:] = dst[:,:,:,:]

                    for e in key_sgrp:
                        m = re.match(r's(.+)', e)
                        if m is not None:
                            s = int(m.group(1))
                            dst = key_sgrp['s%d/w' % (s)]
                            self.w[key][s] = np.zeros(dst.shape)
                            self.w[key][s][:,:] = dst[:,:]

                    self._pre_allocate_key(key)

            finally:
                hdf.close()

            self.grid = pyweno.grid.Grid(cache=cache, format='h5py')

        elif format is 'mat':
            import scipy.io as sio
            import re

            mat = sio.loadmat(cache, struct_as_record=True)

            for key in mat:
                m = re.match(r'weno.k(\d+).c.(.+)', key)
                if (m is not None) and (int(m.group(1)) == order):
                    self.c[m.group(2)] = np.ascontiguousarray(mat[m.group(0)])

                m = re.match(r'weno.k(\d+).w.(.+).s(.+)', key)
                if (m is not None) and (int(m.group(1)) == order):
                    if m.group(2) not in self.w:
                        self.w[m.group(2)] = {}

                    self.w[m.group(2)][int(m.group(3))] = np.ascontiguousarray(mat[m.group(0)])

            for key in self.c:
                self._pre_allocate_key(key)

            self.beta = np.ascontiguousarray(mat['weno.beta'])
            self.grid = pyweno.grid.Grid(cache=cache, format='mat')

        else:
            raise ValueError, "cache format '%s' not supported" % (format)


    def _init_with_grid(self, grid, order, smoothness):

        self.grid  = grid
        self.order = order

        N = self.grid.size
        k = self.order

        # allocate beta and precompute
        self.beta = np.zeros((N,k,2*k-1,2*k-1))
        pyweno.smoothness.beta(smoothness, self.grid, self.order, self.beta)


    def _pre_allocate_key(self, key):

        shape = self.c[key].shape

        N = shape[0]
        k = shape[1]
        n = shape[2]

        self.qr[key] = np.zeros((N,k,n))


    ##################################################################
    # reconstruction
    #

    def precompute_reconstruction(self, key, xi=None, s=0):
        """Precompute reconstruction coefficients and optimal weights.

           **Arguments:**

           * *key* - see pyweno.stencil.reconstruction_coeffs
           * *xi* - see pyweno.stencil.reconstruction_coeffs
           * *s* - biasing parameter

           If s > 0 the reconstruction will be left-biased and cells
           with r < s will be ignored.  If s < 0 the reconstruction
           will be right-biased and cells with r > k - |s| - 1 will be
           ignored.

           Intuitively: if s > 0, then s is also the number of cells
           to exlude from the right; if s < 0, then |s| is also the
           number of cells to exlude from the left.

        """

        grid = self.grid
        N = self.grid.size
        k = self.order

        # order 2k-abs(s)-1 coeffs (c^*)
        stncl = pyweno.stencil.Stencil(grid=grid, order=2*k-abs(s)-1, shift=k+min(0,s)-1)
        stncl.reconstruction_coeffs(key, xi)

        # XXX: this is annoying.  impose n=1 on stencils?
        shape = stncl.c[key].shape      # (N, 2k-abs(s)-1) or (N, n, 2k-abs(s)-1)
        if (len(shape)) > 2:
            n = shape[1]
            cstar = stncl.c[key]
        else:
            n = 1
            cstar = np.zeros((shape[0],n,shape[1]))
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

            wc = np.zeros(k-abs(s))
            merr = 0.0

            f = lambda x: _omegaerr(x, s, cstar[N/2,:,:], c[N/2,:,:,:])
            x0 = 0.5 * np.ones(k-abs(s))

            # constraints: w^r_i >= 0, sum_{r=0}^{k-1} w^r_i = 1
            cons = list(range(k-abs(s)))
            for j in xrange(k-abs(s)):
                cons[j] = _makecons(j)
            cons.append(lambda x: 1.0 - sum(x))
            cons.append(lambda x: sum(x) - 1.0)

            wc[:] = scipy.optimize.fmin_cobyla(f, x0, cons, rhoend=1e-12, iprint=0)

            # reset w^r_i to 0.0 if w^r_i <= 1e-12
            for j in xrange(k-abs(s)):
                if wc[j] <= 1e-12:
                    wc[j] = 0.0

            # maximum error
            err = f(wc[:])
            if err > merr:
                merr = err

            # copy weights to other cells
            for i in xrange(k,N-k):
                w[i,0-min(0,s):k-abs(s)-min(0,s)] = wc[:]

        else:

            #### unstructured grid, cycle through all cells

            merr = 0.0

            for i in xrange(k,N-k):

                # function to minimise and initial guess
                f = lambda x: _omegaerr(x, s, cstar[i,:,:], c[i,:,:,:])
                x0 = 0.5 * np.ones(k - abs(s))

                # constraints: w^r_i >= 0, sum_{r=0}^{k-1} w^r_i = 1
                cons = list(range(k-abs(s)))
                for j in xrange(k-abs(s)):
                    cons[j] = _makecons(j)
                cons.append(lambda x: 1.0 - sum(x))
                cons.append(lambda x: sum(x) - 1.0)

                w[i,0-min(0,s):k-abs(s)-min(0,s)] = scipy.optimize.fmin_cobyla(f, x0, cons, rhoend=1e-12, iprint=0)

                # reset w^r_i to 0.0 if w^r_i <= 1e-12
                for j in xrange(k):
                    if w[i,j] <= 1e-12:
                        w[i,j] = 0.0

                # maximum error
                err = f(w[i,:])
                if err > merr:
                    merr = err


        # store and pre-allocate
        if key not in self.w:
            self.w[key] = {}

        self.c[key] = c
        self.w[key][s] = w
        self._omega_error[key] = merr

        self._pre_allocate_key(key)


    ##################################################################
    # cache
    #

    def cache(self, output, format='mat'):
        """Store grid, all reconstruction coefficients, all optimal
           weights, and smoothness indicator coefficients in the cache
           file *output*.

           Supported formats are:

           * ``'mat'`` - MATLAB compatible matrix file (through SciPy)
           * ``'h5py'`` - HDF5 file (through H5PY)

           The reconstruction coefficients, optimal weights, and
           smoothness indicator coefficients are *appended* to the
           cache file.  That is, they are overwritten if they
           previously existed (for *k*), but all other contents are
           preserved.
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

                    for s in self.w[key]:
                        s_sgrp = key_sgrp.create_group('s%d' % (s))
                        s_sgrp.create_dataset('w', data=self.w[key][s])

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

                for s in self.w[key]:
                    mat['weno.k%d.w.%s.s%d' % (k, key, s)] = self.w[key][s]

            mat['weno.beta'] = self.beta

            sio.savemat(output, mat)

        else:
            raise ValueError, "cache format '%s' not supported" % (format)


    ##################################################################
    # smoothness and reconstruct wrappers
    #

    def smoothness(self, q):
        """Compute smoothness indicators of *q*."""

        pyweno.csmoothness.sigma(q, self.beta, self.sigma)


    def weights(self, key, s=0):
        """Compute weights associated with last set of smoothness
           indicators computed."""

        pyweno.cweno.weights(self.sigma, self.w[key][s], self.wr)


    def reconstruct(self, q, key, qs, s=0, compute_weights=True):
        """Reconstruct *q* at the points specified by *key* and store
           result in *qs*.

           Use the weights corresponding to the key *weights*.  If
           *weights* is none, compute the weights associated with they
           key *key* and use them.
        """

        if compute_weights:
            self.weights(key, s)

        pyweno.cweno.reconstruct(q,
                                 self.c[key],
                                 self.wr,
                                 self.qr[key],
                                 qs)
