"""PyWENO Stencil class.

   Indexing conventions:

     * There are N cells C_i, where i=1,...,N.

     * A quantity X that depends on the cell C_i is indexed as X[i-1].

     * A quantity X that depends on the cell boundary at x_{i-1/2} is
       indexed as X[i-1].

"""

import math

import numpy as np

import pyweno.cstencil

######################################################################
# reconstruction_coeffs (c wrapper)

def reconstruction_coeffs(xi, i, r, k, x, c, d=0):
    """Compute the reconstruction coefficients *c_j* and store the
    results in *c* (indexed as ``c[j]``).

    The reconstruction coefficients *c_j* are used to approximate the
    *d*'th derivative of a function *f* given its cell averages *f_j*
    according to

    .. math::

      f^{(d)}(\\xi) \\approx \sum_{j=0}^k c_j\, \overline{f}_{i-r+j}.

    This function wraps a fast C implementation.

    Arguments:

    * *xi* - reconstruction point
    * *i* - cell index (ie, index of the cell that containts *xi*)
    * *r* - left shift
    * *k* - order
    * *d* - order of derivative (defaults to 0)
    * *x* - cell boundaries
    * *c* - computed reconstruction coefficients (returned)

    Return: the reconstruction coefficients are destructively stored
    in *c*.

    """

    pyweno.cstencil.reconstruction_coeffs(xi, i, r, k, d, x, c)


######################################################################
# quadrature points (helper)

def _quad_pts(a, b, x):

    w = 0.5 * (b - a)
    c = 0.5 * (a + b)

    return w * x + c


######################################################################
# Stencil

class Stencil(object):
    """Polynomial approximation stencil.

    The Stencil class is usually used the WENO class, but can be used
    by itself too.

    The cell averages *f_j* of a function *f* can be used to
    approximate the value of *f* (and its derivatives) according to

    .. math::

      f^{(d)}(\\xi) \\approx \sum_{j=0}^k c_j\, \overline{f}_{i-r+j}.

    where the coefficients *c_j* are the *reconstruction
    coefficients*.  The Stencil class is used to precompute various
    sets of reconstruction coefficients and cache them.

    **Basic usage**

    From scratch::

    >>> stencil = pyweno.stencil.Stencil(order=k, shift=r, grid=grid)

    From a cache::

    >>> stencil = pyweno.stencil.Stencil(orker=k, shift=r, cache='mycache.mat')

    Pre-compute reconstruction coefficients at the left and right boundaries::

    >>> stencil.reconstruction_coeffs('left')
    >>> stencil.reconstruction_coeffs('right')

    Reconstruct a function at the left boundaries::

    >>> c = stencil.c['left'][i,:]
    >>> v_left = numpy.dot(c, v_avg[i-r:i-r+k])

    Cache to a MATLAB file (through SciPy)::

    >>> stencil.cache('mycache.mat')

    Cache to an HDF5 file (through H5PY)::

    >>> stencil.cache('mycache.h5', format='h5py')

    **Instance variables**

    * *grid*  - spatial grid (``pyweno.grid.Grid``)
    * *order* - order of approximation (also *k*)
    * *shift* - left shift (also *r*)
    * *c*     - dictionary of reconstruction coefficients

    **Keyword arguments (without cache)**

    * *order* - order of approximation
    * *shift* - left shift of the stencil or ``None``
    * *grid*  - spatial grid

    The default shift (computed when *shift* is ``None``) is a
    centered difference shift (ie, ``shift = order/2 + order%2``).

    The left shift *shift* can take values from 0 to *order*-1.

    **Keyword arguments (with cache)**

    * *order*  - order of approximation
    * *shift*  - left shift of the stencil or ``None``
    * *cache*  - cache filename
    * *format* - cache format (default is ``'mat'``)

    **Methods**

    """

    def __init__(self,
                 grid=None, order=None, quad=None, shift=None,
                 cache=None, format='mat'
                 ):

        # check order
        if order is None:
            raise ValueError, 'stencil order must be specified'

        self.order = order
        self.k     = order

        # centered difference by default
        if shift is None:
            shift = order / 2

        self.shift = shift
        self.r     = shift

        # initialise
        self.c = {}

        if (grid is not None) and (cache is None):
            self._init_with_grid(grid)
        elif (cache is not None) and (grid is None):
            self._init_with_cache(cache, format)
        else:
            raise ValueError, 'both grid and cache specified'


    def _init_with_grid(self, grid):

        self.grid = grid


    def _init_with_cache(self, cache, format):

        k = self.order
        r = self.shift

        if format is 'h5py':
            import h5py as h5

            hdf = h5.File(cache, 'r')
            r_sgrp = hdf['stencil/k%d/r%d' % (k, r)]

            for key in r_sgrp:
                dst = r_sgrp[key + '/c']
                self.c[key] = np.zeros(dst.shape)
                if len(dst.shape) > 2:
                    self.c[key][:,:,:] = dst[:,:,:]
                else:
                    self.c[key][:,:] = dst[:,:]

            hdf.close()

        elif format is 'mat':
            import scipy.io as sio
            import re

            mat = sio.loadmat(cache, struct_as_record=True)

            self.c = {}
            for key in mat:
                m = re.match(r'stencil.k(\d+).r(\d+).(.+)', key)
                if (m is not None) and (int(m.group(1)) == k) and (int(m.group(2)) == r):
                    self.c[m.group(3)] = mat[m.group(0)]

        else:
            raise ValueError, "cache format '%s' not supported" % (format)


    def reconstruction_coeffs(self, key, xi=None):
        """Pre-compute reconstruction coefficients.

           The reconstruction coeffs *c_j* are computed and stored in
           the instance dictionary *c*.

           Arguments:

           * *key* - key used to store this set of reconstruction coeffs
           * *xi* - callable which returns an array of points within
             each cell at which to compute the reconstruction
             coefficients (called as ``xi(i)``)

           Preceeding the key with ``d|`` will compute the
           reconstruction coefficients to approximate the first
           derivative at the reconstruction points.

           There are several predefined keys:

           * ``'left'`` - the left edge of each cell
           * ``'right'`` - the right edge of each cell
           * ``'gauss_quad3'`` - the Gaussian 3-point quadrature points

           For example, to compute the reconstruction coeffs used to
           reconstruct the derivative of a function f at the left edge
           of each grid cell::

           >>> stencil.reconstruction_ceoffs('d|left')
           >>> c = stencil.c['d|left']

           As another example, to compute the reconstruction coeffs
           used to reconstruct the value of a function at some other
           point(s) within each cell::

           >>> xi_mypts = lambda i: 0.5 * (grid.x[i] + grid.x[i+1])
           >>> stencil.reconstruction_ceoffs('mypts', xi_mypts)
           >>> c = stencil.c['mypts']

        """

        N = self.grid.size
        k = self.order
        r = self.shift
        x = self.grid.x

        # parse key for derivatives: d|key
        if key.find('|') > 0:
            (dstr, pkey) = key.rsplit('|')
        else:
            (dstr, pkey) = ('', key)

        d = len(dstr)

        # if xi is not passed, check key against predefined choices
        if xi is None:
            if pkey == 'left':
                xi = lambda i: x[i]
            elif pkey == 'right':
                xi = lambda i: x[i+1]
            elif pkey == 'gauss_quad3':
                x3 = math.sqrt(3.0/5.0)
                x2 = 0.0
                x1 = -x3
                pts = np.array([x1, x2, x3])

                xi = lambda i: _quad_pts(x[i], x[i+1], pts)

        if xi is None:
            raise ValueError, "xi not passed or key '%s' not recognised" % (pkey)

        # number of points
        if isinstance(xi(0), float):
            n = 1
        else:
            n = len(xi(0))

        # compute reconstruction coeffs
        # XXX: structred grid
        if n == 1:
            c = np.zeros((N,k))
            for i in xrange(k,N-k+1):
                reconstruction_coeffs(xi(i), i, r, k, x, c[i,:], d)
        else:
            c = np.zeros((N,n,k))
            for i in xrange(k,N-k+1):
                for l, z in enumerate(xi(i)):
                    reconstruction_coeffs(z, i, r, k, x, c[i,l,:], d)

        # save and we're done!
        self.c[key] = c


    def cache(self, output, format='mat'):
        """Store all reconstruction coefficients in the cache file *output*.

           Supported formats are:

           * ``'mat'`` - MATLAB compatible matrix file (through SciPy)
           * ``'h5py'`` - HDF5 file (through H5PY)

           The reconstruction coefficients are *appended* to the cache
           file.  That is, they are overwritten if they previously
           existed (for *k* and *r*), but all other contents are
           preserved.
        """


        k = self.order
        r = self.shift

        if format is 'h5py':
            import h5py as h5

            hdf = h5.File(output, 'a')

            # cache in 'stencil/kX/rX'
            if 'stencil' in hdf:
                sgrp = hdf['stencil']
            else:
                sgrp = hdf.create_group('stencil')

            kstr = 'k%d' % (k)
            if kstr in sgrp:
                sgrp = sgrp[kstr]
            else:
                sgrp = sgrp.create_group(kstr)

            rstr = 'r%d' % (r)
            if rstr in sgrp:
                del sgrp[rstr]

            r_sgrp = sgrp.create_group(rstr)

            # create a dataset for each key
            for key in self.c:
                c_sgrp = r_sgrp.create_group(key)
                c_sgrp.create_dataset('c', data=self.c[key])

            # done
            hdf.close()

        elif format is 'mat':
            import scipy.io as sio

            try:
                mat = sio.loadmat(output, struct_as_record=True)
            except:
                mat = {}

            for key in self.c:
                mat['stencil.k%d.r%d.%s' % (k, r, key)] = self.c[key]

            sio.savemat(output, mat)

        else:
            raise ValueError, "cache format '%s' not supported" % (format)
