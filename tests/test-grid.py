"""Test pyweno.grid module."""

import os
import numpy as np

import pyweno.grid
import pyweno.stencil
import pyweno.weno


def test_cache():

    try:
        os.unlink('cache.h5')
    except:
        pass

    x = np.linspace(0.0, 10.0)

    grid = pyweno.grid.Grid(x)
    grid.cache('cache.h5')

    grid2 = pyweno.grid.Grid(cache="cache.h5")

    assert(np.all(grid.x == grid2.x))
