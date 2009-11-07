"""PyWENO smoothness indicators.

"""

import numpy as np

import pyweno.csmoothness


def uszs3(grid, k, f, sigma):
    """Unstructured Zhang and Shu smoothness indicator (not yet implemented)."""
    raise NotImplementedError, 'uszs3 smoothness indicator not yet implemented'


def szs3(grid, k, f, sigma):
    """Structured Zhang and Shu smoothness indicator.

       XXX: more info here
    """

    if __debug__:
        if not grid.structured:
            raise ValueError, 'szs3 smoothness indicator works for structured grids only'

        if k != 3:
            raise ValueError, 'szs3 smoothness indicator works for k=3 only'


    pyweno.csmoothness.szs3(f, sigma)
