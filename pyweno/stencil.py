"""PyWENO Stencil class.

   Indexing conventions:

     * There are N cells C_i, where i=1,...,N.

     * A quantity X that depends on the cell C_i is indexed as X[i-1].

     * A quantity X that depends on the cell boundary at x_{i-1/2} is
       indexed as X[i-1].

"""

import math
import numpy as np
import h5py as h5
import pyweno.cstencil


######################################################################
# reconstruction_coeffs (c wrapper)

def reconstruction_coeffs(xi, i, r, k, x, c, d=0):
    """Numerically compute the reconstruction coefficients *c_j* and
    store the results in *c* (indexed as ``c[j]``).

    The reconstruction coefficients *c_j* are used to approximate the
    *d*'th derivative of a function *f* given its cell averages *f_j*
    according to

    .. math::

      f^{(d)}(\\xi) \\approx \sum_{j=0}^k c_j\, \overline{f}_{i-r+j}.

    This function wraps a fast C implementation, and is especially
    useful for non-uniform grids.

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

    try:
        pyweno.cstencil.reconstruction_coeffs(xi, i, r, k, d, x, c)
    except:
        raise NotImplementedError, "reconstruction coeffs for k = %d not implemented yet" % (k)


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

    The Stencil class is usually used by the WENO class, but can be
    used by itself too.

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

    >>> stencil = pyweno.stencil.Stencil(order=k, shift=r, cache='mycache.h5')

    Pre-compute reconstruction coefficients at the left and right boundaries::

    >>> stencil.reconstruction_coeffs('left')
    >>> stencil.reconstruction_coeffs('right')

    Reconstruct a function at the left boundaries::

    >>> c = stencil.c['left'][i,0,:]
    >>> f_left = numpy.dot(c, f_avg[i-r:i-r+k])

    Cache to an HDF5 file (through H5PY)::

    >>> stencil.cache('mycache.h5')

    **Instance variables**

    * *grid*  - spatial grid (``pyweno.grid.Grid``)
    * *order* - order of approximation (also *k*)
    * *shift* - left shift (also *r*)
    * *c*     - dictionary of reconstruction coefficients

    Each entry of the *c* dictionary is indexed as:

    * ``c[j]`` - uniform grid, one reconstruction point per cell
    * ``c[l,j]`` - uniform grid, multiple reconstruction points per cell
    * ``c[i,j]`` - non-uniform grid, one reconstruction point per cell
    * ``c[i,l,j]`` - non-uniform grid, multiple reconstruction points per cell

    **Keyword arguments (without cache)**

    * *order* - order of approximation
    * *shift* - left shift of the stencil or ``None``
    * *grid*  - spatial grid

    The default shift (computed when *shift* is ``None``) is a
    centered difference shift (ie, ``shift = order/2 + order%2``).

    The left shift *shift* can take values from 0 to *order*-1.

    **Keyword arguments (with cache)**

    * *order* (or *k*) - order of approximation
    * *shift* (or *r*) - left shift of the stencil or ``None``
    * *cache*  - cache filename

    **Methods**

    """

    def __init__(self,
                 grid=None,
                 order=None, k=None, shift=None, r=None,
                 cache=None, **kwargs):

        # check order
        if (order is None) and (k is None):
            raise ValueError, 'stencil order must be specified'

        if (order is None):
            order = k

        self.order = order
        self.k     = order

        # centered difference by default
        if (shift is None) and (r is not None):
            shift = r

        if shift is None:
            shift = order / 2

        self.shift = shift
        self.r     = shift

        if (shift > self.k - 1) or (shift < 0):
            raise ValueError, 'invalid shift'

        # initialise
        self.c = {}

        if (grid is not None) and (cache is None):
            self._init_with_grid(grid)
        elif (cache is not None) and (grid is None):
            self._init_with_cache(cache)
        else:
            raise ValueError, 'both grid and cache specified'


    def _init_with_grid(self, grid):

        self.grid = grid


    def _init_with_cache(self, cache):

        k = self.k
        r = self.r

        hdf = h5.File(cache, 'r')
        try:
            r_sgrp = hdf['stencil/k%d/r%d' % (k, r)]
        except:
            raise ValueError, 'order (k) or shift (r) does not exist in cache'

        for key in r_sgrp:
            dst = r_sgrp[key + '/c']
            self.c[key] = np.zeros(dst.shape)
            dst.read_direct(self.c[key])

        hdf.close()


    def reconstruction_coeffs(self, key, xi=None):
        """Pre-compute reconstruction coefficients.

           The reconstruction coeffs *c_j* are computed and stored in
           the instance dictionary *c*.

           **Arguments:**

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

        N = self.grid.N
        k = self.k
        r = self.r
        x = self.grid.x

        # parse key for derivatives: d|key
        if key.find('|') > 0:
            (dstr, pkey) = key.rsplit('|')
        else:
            (dstr, pkey) = ('', key)

        d = len(dstr)

        # redefine x if grid is uniform
        if self.grid.uniform:
            dx = self.grid.x[1] - self.grid.x[0]
            x = dx * np.linspace(0.0, 2.0*k-1.0, 2*k)

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
        if self.grid.uniform:

            if n == 1:
                c = np.zeros(k)
                reconstruction_coeffs(xi(k-1), k-1, r, k, x, c, d)

            else:
                c = np.zeros((n,k))

                for l, z in enumerate(xi(k-1)):
                    reconstruction_coeffs(z, k-1, r, k, x, c[l,:], d)

        else:

            if n == 1:
                c = np.zeros((N,k))
                for i in xrange(r,N-k+r+1):
                    reconstruction_coeffs(xi(i), i, r, k, x, c[i,:], d)
            else:
                c = np.zeros((N,n,k))
                for i in xrange(r,N-k+r+1):
                    for l, z in enumerate(xi(i)):
                        reconstruction_coeffs(z, i, r, k, x, c[i,l,:], d)

        # save and we're done!
        self.c[key] = c


    def cache(self, output):
        """Store all reconstruction coefficients in the cache file *output*.

           The reconstruction coefficients are *appended* to the cache
           file.  That is, they are overwritten if they previously
           existed (for *k* and *r*), but all other contents are
           preserved.
        """


        k = self.k
        r = self.r

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
