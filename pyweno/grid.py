"""PyWENO Grid class."""

import math

import numpy as np
import h5py as h5
import scipy.integrate


class Grid(object):
    """Non-uniform spatial grid (discretisation).

    **Basic usage**

    From scratch::

    >>> x = numpy.array([-4.0, -1.0, -0.5, 0.0, 0.5, 1.0, 4.0, 10.0])
    >>> grid = pyweno.grid.Grid(x)

    From a cache::

    >>> grid = pyweno.grid.Grid(cache='mycache.mat')

    Averaging a function::

    >>> f = lambda x: x**2
    >>> f_avg = grid.average(f)

    Cache to an HDF5 file (through H5PY)::

    >>> grid.cache('mycache.h5')

    **Instance variables**

    * *N*  - number of cells
    * *x*  - grid boundaries
    * *dx* - cell sizes
    * *uniform* - boolean: is the grid uniform?

    **Keyword arguments**

    * *x* - list of grid cell boundaries, eg,
      ``numpy.linspace(-1.0, 1.0, 20+1)``
    * *cache* - cache filename; *x* is ignored if a cache is used in
       the constructor

    Note: the cell boundaries do **not** have to be uniform.

    **Methods**

    """

    def __init__(self, x=None, y=None, z=None,
                 cache=None, **kwargs):

        if (y is not None) or (z is not None):
            raise NotImplementedError, '2d and 3d grids are not implemented yet.'

        if cache is not None:
            hdf = h5.File(cache, "r")

            dst = hdf["grid/x"]
            x = np.zeros(dst.shape)
            dst.read_direct(x)

            hdf.close()

        else:
            x = np.asarray(x)

        self.N  = x.shape[0] - 1
        self.x  = x
        self.dx = x[1:] - x[:-1]

        self.uniform = False
        if abs(max(self.dx) - min(self.dx)) < 1e-10:
            self.uniform = True


    def cache(self, output):
        """Store cell boundaries in the cache file *output*.

           The cell boundaries are *appended* to the cache file.  That
           is, they are overwritten if they previously existed, but
           all other contents are preserved.
        """

        hdf = h5.File(output, "a")
        if "grid" in hdf:
            raise ValueError, 'a grid cache already exists.'

        sgrp = hdf.create_group("grid")
        sgrp.create_dataset("x", data=self.x)
        hdf.close()

    def centers(self):

        return 0.5 * (self.x[1:] + self.x[:-1])

    def average(self, f):
        """Return cell averages of *f*."""

        x = self.x
        a = np.zeros(x.size-1)

        for i in xrange(x.size-1):
            (a[i], err) = scipy.integrate.quad(f, x[i], x[i+1]) / (x[i+1] - x[i])

        return a
