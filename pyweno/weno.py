"""PyWENO WENO class.

   In the PyWENO documentation, the first cell has an index of 1.

   In the PyWENO code, the first cell has an index of 0.

"""

import math
import sys

import numpy as np
import scipy.optimize

import pyweno.grid
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
       * *cs* - order 2k-|s|-1 reconstruction coeffs (c^*), indexed as
          cs[j], where j is modified by the biasing
       * *c* - order k reconstruction coeffs (c^r), indexed as
          c[r,j], where r is not modified by the biasing

    """

    err = cs.copy()

    k = c.shape[0]

    for j in xrange(2*k-abs(s)-1):      # cycle through all entries of cs[j]

        js = j - min(0,s)               # if s were 0, j would be js

        r_min = max(0, (k-1)-js)
        r_max = min(k-1, 2*(k-1)-js)

        # remove any r's that don't apply due to biasing
        rs = range(r_min, r_max+1)
        if (s < 0):
            for r in range(abs(s)):
                if k-1-r in rs:
                    rs.remove(k-1-r)
        elif (s > 0):
            for r in range(abs(s)):
                if r in rs:
                    rs.remove(r)

        # giv'r
        for r in rs:
            err[j] = err[j] - omega[r-max(0,s)] * c[r,r-(k-1)+js]

    return np.linalg.norm(err)


def _makecons(j):
    """Helper function for creating optimisation constraints."""
    return lambda x: x[j]


def _varpi(key, k, s, cs, c, verbose=True):

    wc = np.zeros(k)

    # function to minimise and initial guess
    f = lambda x: _omegaerr(x, s, cs[:], c[:,:])
    x0 = np.ones(k - abs(s)) / (k - abs(s))

    # constraints: w^r_i >= 0, sum_{r=0}^{k-1} w^r_i = 1
    cons = list(range(k-abs(s)))
    for j in xrange(k-abs(s)):
        cons[j] = _makecons(j)
    cons.append(lambda x: 1.0 - sum(x))
    cons.append(lambda x: sum(x) - 1.0)

    x = scipy.optimize.fmin_cobyla(f, x0, cons, rhoend=1e-12, iprint=0)
    wc[0+max(0,s):k-abs(s)+max(0,s)] = x[:]

    # use equal weights when good optimal weights can't be found
    method = 'minimised'
    if f(x) > 1e-5:
        x = np.ones(k - abs(s)) / (k - abs(s))
        wc[0+max(0,s):k-abs(s)+max(0,s)] = x0[:]
        method = 'equal'

    if verbose:
        print "optimal weights (%s, s=%+d, %s) error: %g" % (key, s, method, f(x))

    # reset w^r_i to 0.0 if w^r_i <= 1e-12
    for j in xrange(k):
        if wc[j] <= 1e-12:
            wc[j] = 0.0

    return wc


######################################################################
# WENO
#

class WENO(object):
    """Weighted Essentially Non-Oscillatory reconstruction class.

    **Basic usage**

    From scratch::

    >>> weno = pyweno.weno.WENO(order=k, grid=grid)

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
    wr = {}                             # current weights
    qr = {}                             # dictionary of working space

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

        self.sigma = np.zeros((N,k))


    def _init_with_cache(self, cache, order, format):

        self.order = order

        self.c = {}
        self.w = {}

        if format is 'h5py':
            import h5py as h5
            import re

            self.grid = pyweno.grid.Grid(cache=cache, format='h5py')

            hdf = h5.File(cache, 'r')

            try:
                k_sgrp = hdf['weno/k%d' % (self.order)]

                dst = k_sgrp['beta']
                self.beta = np.zeros(dst.shape)
                dst.read_direct(self.beta)

                for key in k_sgrp:

                    if key == 'beta':
                        continue

                    key_sgrp = k_sgrp[key]

                    dst = key_sgrp['c']
                    self.c[key] = np.zeros(dst.shape)
                    dst.read_direct(self.c[key])

                    dst = key_sgrp['w']
                    self.w[key] = np.zeros(dst.shape)
                    dst.read_direct(self.w[key])

                    self._pre_allocate_key(key)

            finally:
                hdf.close()

        elif format is 'mat':
            import scipy.io as sio
            import re

            self.grid = pyweno.grid.Grid(cache=cache, format='mat')

            mat = sio.loadmat(cache) # , struct_as_record=True)

            for key in mat:
                m = re.match(r'weno.k(\d+)\.c\.(.+)', key)
                if (m is not None) and (int(m.group(1)) == order):
                    self.c[m.group(2)] = np.ascontiguousarray(mat[m.group(0)])

                m = re.match(r'weno.k(\d+)\.w\.(.+)', key)
                if (m is not None) and (int(m.group(1)) == order):
                    self.w[m.group(2)] = np.ascontiguousarray(mat[m.group(0)])


            for key in self.c:
                self._pre_allocate_key(key)

            self.beta = np.ascontiguousarray(mat['weno.beta'])

        else:
            raise ValueError, "cache format '%s' not supported" % (format)


    def _init_with_grid(self, grid, order, smoothness):

        self.grid  = grid
        self.order = order

        N = self.grid.size
        k = self.order

        # allocate beta and precompute
        if self.grid.uniform:
            self.beta = np.zeros((k,2*k-1,2*k-1))
        else:
            self.beta = np.zeros((N,k,2*k-1,2*k-1))

        pyweno.smoothness.beta(smoothness, self.grid, self.order, self.beta)


    def _pre_allocate_key(self, key):

        # indexing: c[N,l,r,k] or c[l,r,k]

        shape = self.c[key].shape

        if len(shape) == 4:
            N = self.grid.N
            n = shape[1]
            k = shape[2]

        elif len(shape) == 3:
            N = self.grid.N
            n = shape[0]
            k = shape[1]

        else:
            raise ValueError

        self.qr[key] = np.zeros((N,n,k))
        self.wr[key] = np.zeros((N,n,k))

        # indexing: varpi: N,s,l,r or s,l,r
        #           wr:    N,l,r


    ##################################################################
    # reconstruction
    #

    def precompute_reconstruction(self, key, xi=None, verbose=True):
        """Precompute reconstruction coefficients and optimal weights.

           **Arguments:**

           * *key* - see pyweno.stencil.reconstruction_coeffs
           * *xi* - see pyweno.stencil.reconstruction_coeffs

           In this function, s is the biasing parameter.  If s > 0 the
           reconstruction will be left-biased and cells with r < s
           will be ignored.  If s < 0 the reconstruction will be
           right-biased and cells with r > k - |s| - 1 will be
           ignored.

           Intuitively: if s > 0, then s is also the number of cells
           to exlude from the right; if s < 0, then |s| is also the
           number of cells to exlude from the left.

           The biasing parameter s takes values from -(k-1) to (k-1).
           There are 2k-1 possible values of s.  An index of 0 for s
           corresponds to a values of -(k-1) for s (ie, s_value =
           s_index - (k-1)).

        """

        grid = self.grid
        N = self.grid.size
        k = self.order

        # get shape of order k coeffs
        stncl = pyweno.stencil.Stencil(grid=grid, order=k, shift=0)
        stncl.reconstruction_coeffs(key, xi)

        if grid.uniform:
            shape = stncl.c[key].shape
            if len(shape) > 1:
                n = shape[0]
            else:
                n = 1
        else:
            shape = stncl.c[key].shape
            if len(shape) > 2:
                n = shape[1]
            else:
                n = 1

        #### optimal weights (varpi)
        if grid.uniform:

            c = np.zeros((n,k,k))
            w = np.zeros((2*k-1,n,k))

            if n == 1:
                for r in xrange(k):
                    stncl = pyweno.stencil.Stencil(grid=grid, order=k, shift=r)
                    stncl.reconstruction_coeffs(key, xi)
                    c[0,r,:] = stncl.c[key][:]

            else:
                for r in xrange(k):
                    stncl = pyweno.stencil.Stencil(grid=grid, order=k, shift=r)
                    stncl.reconstruction_coeffs(key, xi)
                    c[:,r,:] = stncl.c[key][:,:]

            self.c[key] = c
            self.w[key] = w

            if verbose:
                print "weights (%s): uniform grid..." % key

            #### uniform grid, only do one cell

            for s in range(-(k-1), k):

                # order 2k-abs(s)-1 coeffs (c^*)
                order = 2*k-abs(s)-1
                shift = k + min(0,s) - 1
                stncl = pyweno.stencil.Stencil(grid=grid, order=order, shift=shift)
                stncl.reconstruction_coeffs(key, xi)
                cstar = np.zeros((n,order))
                if n == 1:
                    cstar[0,:] = stncl.c[key][:]
                else:
                    cstar[:,:] = stncl.c[key][:,:]

                for l in range(n):
                    wc = _varpi(key, k, s, cstar[l,:], c[l,:,:], verbose)
                    self.w[key][s+(k-1),l,:] = wc[:]


            if verbose:
                print "weights (%s): uniform grid... done." % key

        else:

            raise NotImplemented, 'not finished yet...'

            #### non-uniform grid, cycle through all cells

            # c indexing should be: N,l,r,k

            # XXX

            shape = stncl.c[key].shape
            if len(shape) > 2:
                n = shape[1]
                c = np.zeros((N,k,n,k))
            else:
                c = np.zeros((N,k,k))

            # XXX
            for r in xrange(k):
                stncl = pyweno.stencil.Stencil(grid=grid, order=k, shift=r)
                stncl.reconstruction_coeffs(key, xi)
                c[:,r,:,:] = stncl.c[key][:,:,:]

            for s in range(-(k-1), k):

                w = np.zeros((N,k))

                # order 2k-abs(s)-1 coeffs (c^*)
                order = 2*k-abs(s)-1
                shift = k + min(0,s) - 1
                stncl = pyweno.stencil.Stencil(grid=grid, order=order, shift=shift)
                stncl.reconstruction_coeffs(key, xi)
                cstar = stncl.c[key]

                for i in xrange(shift,N-order+shift+1):

                    # function to minimise and initial guess
                    f = lambda x: _omegaerr(x, s, cstar[i,:,:], c[i,:,:,:])
                    x0 = 0.5 * np.ones(k - abs(s))

                    # constraints: w^r_i >= 0, sum_{r=0}^{k-1} w^r_i = 1
                    cons = list(range(k-abs(s)))
                    for j in xrange(k-abs(s)):
                        cons[j] = _makecons(j)
                    cons.append(lambda x: 1.0 - sum(x))
                    cons.append(lambda x: sum(x) - 1.0)

                    x = scipy.optimize.fmin_cobyla(f, x0, cons, rhoend=1e-12, iprint=0)
                    w[i,0+max(0,s):k-abs(s)+max(0,s)] = x[:]

                    # reset w^r_i to 0.0 if w^r_i <= 1e-12
                    for j in xrange(k):
                        if w[i,j] <= 1e-12:
                            w[i,j] = 0.0

                self.w[key][s+(k-1),:,:] = w[:,:]


        # pre-allocate work space
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
                    key_sgrp.create_dataset('w', data=self.w[key])

                k_sgrp.create_dataset('beta', data=self.beta)

            finally:
                hdf.close()

        elif format is 'mat':
            import scipy.io as sio

            try:
                mat = sio.loadmat(output) #, struct_as_record=True)
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

    def smoothness(self, q, imin=0, imax=-1):
        """Compute smoothness indicators of *q*."""

        if imax == -1:
            imax = self.grid.size - 1

        if self.grid.uniform:
            sigma = pyweno.csmoothness.sigma_uniform
        else:
            sigma = pyweno.csmoothness.sigma_nonuniform

        sigma(q, imin, imax, self.beta, self.sigma)


    def weights(self, key, imin=0, imax=-1, s=0):
        """Compute weights associated with *key* using the last set of
           smoothness indicators computed.

           **Arguments**

           * *key* -
           * *imin* - minimum cell index
           * *imax* - maximum cell index
           * *s* - biasing

           The default values of *imin* and *imax* are taken to be the
           full domain excluding cells near the edges.

           """

        N = self.grid.size
        k = self.order

        if imax == -1:
            imax = N - 1

        if self.grid.uniform:
            weights = pyweno.cweno.weights_uniform
        else:
            weights = pyweno.cweno.weights_nonuniform

        sigma = self.sigma
        varpi = self.w[key][s+(k-1),:,:]
        wr    = self.wr[key]

        if (imin >= k-1) and (imax <= N-k):
            weights(imin, imax, sigma, varpi, wr)

        else:
            # interior cells
            weights(k-1, N-k, sigma, varpi, wr)

            # left edge cells
            for i in xrange(imin, k-1):
                s = i - k + 1
                varpi = self.w[key][s+(k-1),:,:]
                weights(i, i, sigma, varpi, wr)

            # right edge cells
            for i in xrange(N-k+1, N):
                s = i - (N - k + 1) + 1
                varpi = self.w[key][s+(k-1),:,:]
                weights(i, i, sigma, varpi, wr)


    def reconstruct(self, q, key, qs, imin=0, imax=-1, s=0, compute_weights=True):
        """Reconstruct *q* at the points specified by *key* and store
           result in *qs*.

           **Arguments:**

           * *q* - cell averages of function to reconstruct
           * *key* -
           * *qs* - store results here
           * *s* - biasing (defaults to no biasing)
           * *imin* - left-most cell to reconstruct within
           * *imax* - right-most cell to reconstruct within
           * *compute_weights* -

           Use the weights corresponding to the key *weights*.  If
           *compute_weights* is True, compute the weights associated
           with they key *key* and use them.  Otherwise, we assume
           that the weights have been computed explicity already.

           NOTE: if you are reconstructing near a domain boundary, and
           you have constructed your own weights (ie,
           compute_weights=False), then the weights that you have
           computed should be appropriately biased near the boundary.

        """

        N = self.grid.size
        k = self.order

        if imax == -1:
            imax = N - 1

        if compute_weights:
            self.weights(key, imin, imax, s)

        if self.grid.uniform:
            reconstruct = pyweno.cweno.reconstruct_uniform
        else:
            reconstruct = pyweno.cweno.reconstruct_nonuniform

        c = self.c[key]
        wr = self.wr[key]
        qr = self.qr[key]

        if len(qr.shape) == 3:
            for l in range(qr.shape[0]):
                pass
        else:
            pass

        if (imin >= k-1) and (imax <= N-k):

            reconstruct(q, s, imin, imax, c, wr, qr, qs)

        else:

            # interior cells
            reconstruct(q, s, k-1, N-k, c, wr, qr, qs)

            # left edge cells
            for i in xrange(imin, k-1):
                s = i - k + 1
                reconstruct(q, s, i, i, c, wr, qr, qs)

            # right edge cells
            for i in xrange(N-k+1, N):
                s = i - (N - k + 1) + 1
                reconstruct(q, s, i, i, c, wr, qr, qs)

