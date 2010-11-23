"""PyWENO cache example."""

import os
import numpy
import pyweno.grid
import pyweno.weno

# first, define the stencil order k and cache file
k = 3
cache = 'gridk%d.h5' % (k)

# if the cache file isn't present ...
if not os.access(cache, os.F_OK):

    # ... define the grid and weno reconstructor
    x = numpy.array([-4.0, -3.5, -3.0, -2.5, -2.0, -1.5,
                     -1.0, -0.8, -0.6, -0.4,
                     -0.3, -0.2, -0.1, 0.0, 0.1, 0.2, 0.3,
                     0.4, 0.6, 0.8, 1.0,
                     1.5, 2.0, 2.5, 3.0, 3.5, 4.0])

    grid = pyweno.grid.Grid(x)

    weno = pyweno.weno.WENO(grid=grid, order=k)
    weno.precompute_reconstruction('left')
    weno.precompute_reconstruction('right')
#    weno.precompute_reconstruction('gauss_quad3')
#    weno.precompute_reconstruction('d|gauss_quad3')
#    weno.precompute_reconstruction('d|left')
#    weno.precompute_reconstruction('dd|left')

    # cache everything
    weno.cache(cache)
