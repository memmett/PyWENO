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
    """Compute the reconstruction coefficients c_j and store the
    results in *c* (indexed as c[j]).

    The reconstruction coefficients c_j are used to approximate the
    d'th derivative of a function v given its cell averages v_j
    according to

    ..math:: v^{(d)}(\\xi) \approx \sum_{j=0}^k c_j v_{i-r+j}.

    The reconstruction coefficients c_j depend on the point xi, cell
    i, shift r, order k, derivative d, and grid x; but *not* on the
    function v.

    This function wraps a fast C implementation.

    Arguments:

      * *xi* - reconstruction point
      * *i* - cell index
      * *r* - left shift
      * *k* - order
      * *d* - order of derivative (defaults to 0)
      * *x* - cell boundaries
      * *c* - computed reconstruction coefficients (returned)

    Return: the reconstruction coefficients are stored in *c*.

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

    The cell averages v_i of a function v can be used to approximate
    the value of v (and its derivatives) according to

    ..math:: v^{(d)}(\\xi) \approx \sum_{j=0}^k c_j v_{i-r+j}

    where the coefficients c_j are the *reconstruction coefficients*.
    The reconstruction coefficients depend on the point xi, cell i,
    shift r, order k, derivative d, and grid x; but *not* on the
    function v.

    The Stencil class is used to precompute various sets of
    reconstruction coefficients and cache them.  For example::

      >>> stencil = pyweno.stencil.Stencil(order=k, shift=r, grid=grid)
      >>> stencil.reconstruction_coeffs('left')
      >>> stencil.reconstruction_coeffs('right')

    pre-computes the reconstruction coefficients c_j of order k and
    left-shift r at the left and right boundaries of each cell in the
    grid.  Subsequently::

      >>> c = stencil.c['left'][i,:]
      >>> y = numpy.dot(c, v[i-r:i-r+k])

    approximates the function v at the left edge of the i'th cell.
    That is::

      .. math:: y \approx v(x_{i-1/2}).

    Instance variables:

      * *c*     - dictionary of reconstruction coefficients
      * *order* - order of approximation (usually denoted k)
      * *k*     - as above
      * *shift* - left shift (usually denoted r)
      * *r*     - as above
      * *grid*  - spatial grid (''pyweno.Grid'')

    Keyword arguments (without cache):

      * *order* - order of approximation
      * *shift* - left shift of the stencil or ''None''
      * *grid*  - spatial grid (''pyweno.Grid'')

    The default shift (computed when shift is ''None'') is a centered
    difference shift (ie, shift = order/2 + order%2).

    The left shift *shift* can take values from 0 to *order*-1.

    Keyword arguments (with cache):

      * *order*  - order of approximation
      * *shift*  - left shift of the stencil or ''None''
      * *cache*  - cache filename
      * *format* - cache format (default is HDF5)

    """

    def __init__(self,
                 grid=None, order=None, quad=None, shift=None,
                 cache=None, format='hdf5'
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

        if format is 'hdf5':
            import h5py as h5

            hdf = h5.File(cache, "r")

            r_sgrp = hdf["stencil/k%d/r%d" % (k, r)]

            for key in r_sgrp:
                dst = r_sgrp[key + '/c']
                self.c[key] = np.array(dst)

            hdf.close()

        else:
            raise ValueError, "cache format '%s' not supported" % (format)


    def reconstruction_coeffs(self, key, xi=None):
        """XXX"""

        N = self.grid.size
        k = self.order
        r = self.shift
        x = self.grid.x

        if key.find('|') > 0:
            (dstr, pkey) = key.rsplit('|')
        else:
            (dstr, pkey) = ('', key)

        d = len(dstr)

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

        # number of pts

        if isinstance(xi(0), float):
            n = 1
        else:
            n = len(xi(0))

        # compute reconstruction coeffs
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


    def cache(self, output, format='hdf5'):
        """Cache reconstruction coeffs and quadrature coeffs (if
        defined)."""

        if format is 'hdf5':
            import h5py as h5

            hdf = h5.File(output, "a")

            if "stencil" in hdf:
                sgrp = hdf["stencil"]
            else:
                sgrp = hdf.create_group("stencil")

            kstr = "k%d" % (self.order)
            if kstr in sgrp:
                sgrp = sgrp[kstr]
            else:
                sgrp = sgrp.create_group(kstr)

            rstr = "r%d" % (self.shift)
            if rstr in sgrp:
                del sgrp[rstr]

            r_sgrp = sgrp.create_group(rstr)

            for key in self.c:
                c_sgrp = r_sgrp.create_group(key)
                c_sgrp.create_dataset("c", data=self.c[key])

            hdf.close()

        else:
            raise ValueError, "cache format '%s' not supported" % (format)

