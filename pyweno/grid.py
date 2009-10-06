"""PyWENO Grid class."""

import math

import numpy as np

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
      * *format* - cache format (default is HDF5)

    """

    def __init__(self,
                 boundaries=None,
                 cache=None, format='hdf5'
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

        # init self
        self._bndry     = bndry
        self._cntr      = cntr
        self._sz        = sz
        self.size       = cntr.size
        self.N          = cntr.size
        self.x          = self._bndry

    def _init_with_cache(self, cache, format):

        if format is 'hdf5':
            import h5py as h5

            hdf = h5.File(cache, "r")

            dst = hdf["grid/bndry"]
            boundaries = dst[:]

            self._init_with_boundaries(boundaries)

            hdf.close()

        else:
            pass


    def cache(self, output, format='hdf5'):
        """Cache grid."""

        if format is 'hdf5':

            import h5py as h5

            hdf = h5.File(output, "a")

            sgrp = hdf.create_group("grid")
            sgrp.create_dataset("bndry", data=self._bndry)

            hdf.close()

        else:
            raise NotImplementedError, "cache format '%s' not supported" % (format)


    def boundaries(self):
        """Return array of *N+1* cell boundaries."""
        return self._bndry

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
        bndry = self._bndry

        fbar = np.zeros(bndry.size-1)

        try:
            import scipy.integrate

        except:
            # use 3-point gaussian quadrature
            x3 = math.sqrt(3.0/5.0)
            x2 = 0.0
            x1 = -x3

            w3 = 5.0/9.0
            w2 = 8.0/9.0
            w1 = 5.0/9.0

            for i in xrange(bndry.size-1):
                b = bndry[i+1]
                a = bndry[i]
                w = (b-a)/2.0
                c = (a+b)/2.0

                fbar[i] = 0.5 * ( w1*f(w*x1+c) + w2*f(w*x2+c) + w3*f(w*x3+c) )

        else:
            # use scipy's quadrature
            for i in xrange(bndry.size-1):
                (fbar[i], abserr) = scipy.integrate.quad(f, bndry[i], bndry[i+1]) / (bndry[i+1] - bndry[i])

        return fbar
