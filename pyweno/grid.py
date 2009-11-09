"""PyWENO Grid class.

"""

import math

import numpy as np
import scipy.integrate


class Grid(object):
    """Unstructured spatial grid (discretisation).

    Instance variables:

      * *size* - number of cells (usually denoted *N*)
      * *N*    - as above
      * *x*    - grid boundaries

    The constructor precomputes cell centres and sizes from the cell
    boundaries *boundaries*.

    Arguments: (without cache)

      * *boundaries* - list of grid cell boundaries (eg,
         ''numpy.linspace(-1.0, 1.0, 20+1)'')

    The cell boundaries do **not** have to be structured (ie,
    uniformly spaced).

    Arguments: (with cache)

      * *cache*  - cache filename
      * *format* - cache format (default is 'mat')

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

        bndry = boundaries

        # cell centres
        cntr = np.zeros(bndry.size-1)
        for i in xrange(cntr.size):
            cntr[i] = (bndry[i+1] + bndry[i]) / 2.0

        # cell sizes
        sz = np.zeros(bndry.size-1)
        for i in xrange(sz.size):
            sz[i] = bndry[i+1] - bndry[i]

        self.structured = False
        if abs(max(sz) - min(sz)) < 1e-12:
            self.structured = True

        # init self
        self._cntr      = cntr
        self._sz        = sz
        self.size       = cntr.size
        self.N          = cntr.size
        self.x          = self.bndry

    def _init_with_cache(self, cache, format):

        if format is 'h5py':
            import h5py as h5

            hdf = h5.File(cache, "r")

            dst = hdf["grid/bndry"]
            boundaries = dst[:]

            self._init_with_boundaries(boundaries)

            hdf.close()

        elif format is 'mat':

            import scipy.io as sio
            mat = sio.loadmat(cache, struct_as_record=True)

            boundaries = mat['grid.bndry']

            self._init_with_boundaries(boundaries)

        else:
            pass


    def cache(self, output, format='mat'):
        """Cache grid.

           XXX.
        """

        if format is 'h5py':
            import h5py as h5

            hdf = h5.File(output, "a")
            sgrp = hdf.create_group("grid")
            sgrp.create_dataset("bndry", data=self.x)
            hdf.close()

        elif format is 'mat':
            import scipy.io as sio

            sio.savemat(output, {'grid.bndry': self.x})

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
