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

def _reconstruction_coeffs(i, r, k, x, c, b='left'):
    """Compute reconstruction coefficients *c_j* and store the result
    in *c* (indexed as c[j]).

    This is a pure Python implementation and is more-or-less deprecated.

    Arguments:

      * *i* - cell number
      * *r* - left shift
      * *k* - order
      * *x* - cell boundaries
      * *c* - computed reconstruction coefficients
      * *b* - boundry: 'right' or 'left'

    """

    if b == 'left':
        i = i - 1
        r = r - 1
        b = 1
    else:
        b = 0

    for j in xrange(k):

        lacc = 0.0
        for l in xrange(j+1, k+1):

            ms = range(0,k+1)
            ms.remove(l)

            macc = 0.0
            for m in ms:

                ns = range(0,k+1)
                ns.remove(l)
                ns.remove(m)

                nacc = 1.0
                for n in ns:
                    nacc = nacc * (x[i+1] - x[i-r+n])

                macc = macc + nacc

            nmrtrp = macc

            macc = 1.0
            for m in ms:
                macc = macc * (x[i-r+l] - x[i-r+m])

            dnmntrp = macc

            lacc = lacc + nmrtrp / dnmntrp * (x[i-r+j+1] - x[i-r+j])

        c[j] = lacc


def reconstruction_coeffs(xi, i, r, k, x, c, d=0):
    """Compute reconstruction coefficients *c_j* and store the result
    in *c* (indexed as c[i,j]).

    This function calls the appropriate C function from
    pyweno.cstencil if available.

    Arguments:

      * *xi* - reconstruction point
      * *i* - cell number
      * *r* - left shift
      * *k* - order
      * *x* - cell boundaries
      * *c* - computed reconstruction coefficients (returned)
      * *d* - derivative (defaults to 0)

    XXX

    Return: the reconstruction coefficients are stored in *c*.

    """

    eval('pyweno.cstencil.reconstruction_coeffs_k%d_d%d(xi, i, r, x, c)' % (k, d))


def gauss_reconstruction_coeffs(n, i, r, k, x, g):
    """Compute the reconstruction coeffs used to compute the
    polynomial approximation at the gaussian n-point quadrature points."""

    if (n != 3):
        raise NotImplementedError, "only 3-point Gaussian quadrature is currently supported (adding more is straight forward, please see pyweno/stencil.py)"

    x3 = math.sqrt(3.0/5.0)
    x2 = 0.0
    x1 = -x3

    b = x[i+1]
    a = x[i]
    w = (b-a)/2.0
    c = (a+b)/2.0

    for l, xl in enumerate([x1, x2, x3]):
        xi = w*xl + c
        reconstruction_coeffs(xi, i, r, k, x, g[l,:])


class Stencil(object):
    """Polynomial approximation stencil.

    The cell averages :math:`\\bar{v}_i` of a function :math:`v` can
    be used to approximate the value of :math:`v` at the cell
    boundaries of the grid.  In the interior of the grid, the
    approximations :math:`v_{i+1/2}` and :math:`v_{i-1/2}` are given
    by

      :math:`v_{i+1/2} = \sum_{j=0}^{k-1} c^r_{ij} \\bar{v}_{i-r+j}`

    and

      :math:`v_{i-1/2} = \sum_{j=0}^{k-1} \\tilde{c}^r_{ij} \\bar{v}_{i-r+j}`

    for :math:`i=0,\ldots,N` where :math:`c^r_{ij}` and
    :math:`\\tilde{c}^r_{ij}` are the *reconstruction coefficients*.

    Instance variables:

      * *grid*  - spatial grid (''pyweno.Grid'')
      * *order* - order of approximation (usually denoted :math:`k`)
      * *k*     - as above
      * *shift* - left shift (usually denoted :math:`r`)
      * *r*     - as above
      * *c_r*   - matrix of coefficients :math:`c^r_{ij}`
      * *c_l*   - matrix of coefficients :math:`\\tilde{c}^r_{ij}`
      * *quad*  - number of quadrature points
      * *c_q*   - matrix of coefficients used to approximate at quadrature points

    The constructor precomputes the polynomial (of order *order*)
    reconstruction coefficients :math:`c^r_{ij}` based on stencils with
    left shift *shift* in the **interior** of the grid (ie, k <= i <=
    N-k).  The matricies *c_m* and *c_p* are padded with zeros for
    cells not in the interior of the grid.

    Arguments: (without cache)

      * *grid*  - spatial grid (''pyweno.Grid'')
      * *order* - order of approximation
      * *quad*  - order of quadrature (defaults to no quadrature)
      * *shift* - left shift of the stencil or ''None''

    The default shift (computed when shift is ''None'') is a centered
    difference shift.

    The left shift *shift* can take values from 0 to *order*-1.

    Arguments: (with cache)

      * *cache*  - cache filename
      * *order*  - order of approximation
      * *shift*  - left shift of the stencil or ''None''
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

        # quadrature
        self.quad = quad

        # initialise
        if (grid is not None) and (cache is None):
            self._init_with_grid(grid)
        elif (cache is not None) and (grid is None):
            self._init_with_cache(cache, format)
        else:
            raise ValueError, 'both grid and cache specified'

    def _init_with_grid(self, grid):

        self.grid  = grid

        N = self.grid.size
        k = self.order
        r = self.shift
        x = self.grid.boundaries()

        # boundary coeffs

        c_r = np.zeros((N,k))
        c_l = np.zeros((N,k))

        for i in xrange(k,N-k+1):
            reconstruction_coeffs(x[i],   i, r, k, x, c_l[i,:])
            reconstruction_coeffs(x[i+1], i, r, k, x, c_r[i,:])

        self.c_r = c_r
        self.c_l = c_l

        # quadrature coeffs

        if self.quad is not None:
            n = self.quad

            c_q = np.zeros((N,n,k))

            for i in xrange(k,N-k+1):
                gauss_reconstruction_coeffs(n, i, r, k, x, c_q[i,:,:])
                gauss_reconstruction_coeffs(n, i, r, k, x, c_q[i,:,:])

            self.c_q = c_q


    def _init_with_cache(self, cache, format):

        k = self.order
        r = self.shift

        if format is 'hdf5':
            import h5py as h5

            hdf = h5.File(cache, "r")

            r_sgrp = hdf["stencil/k%d/r%d" % (k, r)]

            dst = r_sgrp["boundary/c_r"]
            self.c_r = dst[:,:]

            dst = r_sgrp["boundary/c_l"]
            self.c_l = dst[:,:]

            if "quadrature" in r_sgrp:
                self.quad = r_sgrp["quadrature"].attrs["order"]

                dst = r_sgrp["quadrature/c_q"]
                self.c_q = dst[:,:,:]

            hdf.close()

        else:
            raise ValueError, "cache format '%s' not supported" % (format)


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

            c_sgrp = r_sgrp.create_group("boundary")
            c_sgrp.attrs["description"] = "reconstruction coeffs for cell boundaries"
            c_sgrp.create_dataset("c_r", data=self.c_r)
            c_sgrp.create_dataset("c_l", data=self.c_l)

            if self.quad > 0:
                g_sgrp = r_sgrp.create_group("quadrature")
                g_sgrp.attrs["description"] = "reconstruction coeffs for gaussian quadrature points"
                g_sgrp.attrs["order"] = self.quad
                g_sgrp.create_dataset("c_q", data=self.c_q)

            hdf.close()

        else:
            raise ValueError, "cache format '%s' not supported" % (format)


    def max_cell_size(self):
        """Return array of the maximum sizes of the grid cells within
        each stencil."""
        grid = self.grid
        N    = self.grid.size
        k    = self.order
        r    = self.shift

        msz = zeros(N)
        for i in xrange(N):
            msz[i] = max(grid.sz[i-r:i-r+k])

        return msz
