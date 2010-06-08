"""PyWENO Grid class.

"""

import math

import numpy as np
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

    Cache to a MATLAB file (through SciPy)::

    >>> grid.cache('mycache.mat')

    Cache to an HDF5 file (through H5PY)::

    >>> grid.cache('mycache.h5', format='h5py')

    **Instance variables**

    * *size* - number of cells (also *N*)
    * *x*    - grid boundaries

    The constructor precomputes the cell centres and sizes from the
    cell boundaries.

    **Keyword arguments (without cache)**

    * *boundaries* - list of grid cell boundaries, eg,
      ``numpy.linspace(-1.0, 1.0, 20+1)``

    The cell boundaries do **not** have to be uniform.

    **Keyword arguments (with cache)**

    * *cache*  - cache filename
    * *format* - cache format (default is 'mat')

    **Methods**

    """

    def __init__(self,
                 boundaries=None,
                 cache=None, format='mat'
                 ):

        if (boundaries is not None) and (cache is None):
            self._init_with_boundaries(boundaries)
        elif (cache is not None) and (boundaries is None):
            self._init_with_cache(cache, format)
        else:
            ValueError, 'both boundaries and cache specified'


    def _init_with_boundaries(self, boundaries):

        x = boundaries

        # cell centres
        cntr = np.zeros(x.size-1)
        for i in xrange(cntr.size):
            cntr[i] = (x[i+1] + x[i]) / 2.0

        # cell sizes
        sz = np.zeros(x.size-1)
        for i in xrange(sz.size):
            sz[i] = x[i+1] - x[i]

        self.uniform = False
        if abs(max(sz) - min(sz)) < 1e-10:
            self.uniform = True

        # init self
        self._cntr      = cntr
        self._sz        = sz
        self.size       = cntr.size
        self.N          = cntr.size
        self.x          = x

    def _init_with_cache(self, cache, format):

        if format is 'h5py':
            import h5py as h5

            hdf = h5.File(cache, "r")
            dst = hdf["grid/bndry"]
            boundaries = np.zeros(dst.shape)
            boundaries[:] = dst[:]

            self._init_with_boundaries(boundaries)

            hdf.close()

        elif format is 'mat':
            import scipy.io as sio

            mat = sio.loadmat(cache, struct_as_record=True)
            boundaries = mat['grid.bndry']

            self._init_with_boundaries(boundaries)

        else:

            raise NotImplementedError, "cache format '%s' not supported" % (format)


    def cache(self, output, format='mat'):
        """Store cell boundaries in the cache file *output*.

           Supported formats are:

           * ``'mat'`` - MATLAB compatible matrix file (through SciPy)
           * ``'h5py'`` - HDF5 file (through H5PY)

           The cell boundaries are *appended* to the cache file.  That
           is, they are overwritten if they previously existed, but
           all other contents are preserved.
        """

        if format is 'h5py':
            import h5py as h5

            hdf = h5.File(output, "a")
            sgrp = hdf.create_group("grid")
            sgrp.create_dataset("bndry", data=self.x)
            hdf.close()

        elif format is 'mat':
            import scipy.io as sio

            try:
                mat = sio.loadmat(output, struct_as_record=True)
            except:
                mat = {}

            mat['grid.bndry'] = self.x
            sio.savemat(output, mat)

        else:

            raise NotImplementedError, "cache format '%s' not supported" % (format)


    def boundaries(self):
        """Return array of *N+1* cell boundaries."""
        return self.x

    def centres(self):
        """Return array of *N* cell centres."""
        return self._cntr

    def centers(self):
        """Return array of *N* cell centers."""
        return self._cntr

    def sizes(self):
        """Return array of *N* cell sizes."""
        return self._sz

    def average(self, f):
        """Return cell averages of *f*."""

        x = self.x
        a = np.zeros(x.size-1)

        for i in xrange(x.size-1):
            (a[i], err) = scipy.integrate.quad(f, x[i], x[i+1]) / (x[i+1] - x[i])

        return a
