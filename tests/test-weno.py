"""Test WENO reconstruction on an unstructured grid."""

import math

import numpy as np

import pyweno.grid
import pyweno.weno


def f(x):
    """Test function (quadratic)."""

    return x * x


def test_weno():
    r = 2
    k = 5

    x = np.array([-4.0, -3.5, -3.0, -2.5, -2.0, -1.5,
                  -1.0, -0.8, -0.6, -0.4,
                  -0.3, -0.2, -0.1, 0.0, 0.1, 0.2, 0.3,
                  0.4, 0.6, 0.8, 1.0,
                  1.5, 2.0, 2.5, 3.0, 3.5, 4.0])

    grid = pyweno.grid.Grid(boundaries=x)
    weno = pyweno.weno.WENO(grid=grid, order=k)

    # average values of f
    fbar = grid.average(f)

    # f at boundaries
    fbndry = np.zeros(x.size)
    for i in range(x.size):
        fbndry[i] = f(x[i])

    # f reconstructed at boundaries
    frcnst_m = np.zeros(x.size)
    frcnst_p = np.zeros(x.size)

    weno.reconstruct(fbar, frcnst_m, frcnst_p)

    # assert
    d  = fbndry[k:-k-1] - frcnst_m[k:-k-1]
    l2 = math.sqrt(np.dot(d, d))
    assert l2 < 1e-10, "WENO (-) is broken"

    d  = fbndry[k+1:-k] - frcnst_p[k:-k-1]
    l2 = math.sqrt(np.dot(d, d))
    assert l2 < 1e-10, "WENO (+) is broken"
