"""Test reconstruction coefficients on an unstructured grid."""

import math

import numpy as np

import pyweno.grid
import pyweno.stencil


def f(x):
    """Test function (quadratic)."""

    return x * x


def test_stencil():
    r = 2
    k = 5

    x = np.array([-4.0, -3.5, -3.0, -2.5, -2.0, -1.5,
                  -1.0, -0.8, -0.6, -0.4,
                  -0.3, -0.2, -0.1, 0.0, 0.1, 0.2, 0.3,
                  0.4, 0.6, 0.8, 1.0,
                  1.5, 2.0, 2.5, 3.0, 3.5, 4.0])

    grid    = pyweno.grid.Grid(boundaries=x)
    stencil = pyweno.stencil.Stencil(grid=grid, order=k, shift=r)

    # average values of f
    fbar = grid.average(f)

    # f at boundaries
    fbndry = np.zeros(x.size)
    for i in range(x.size):
        fbndry[i] = f(x[i])

    # f reconstructed at boundaries
    frcnst_m = np.zeros(x.size)
    frcnst_p = np.zeros(x.size)
    for i in range(k, x.size-k):
        frcnst_m[i]   = np.dot(stencil.c_m[i,:], fbar[i-r:i-r+k])
        frcnst_p[i+1] = np.dot(stencil.c_p[i,:], fbar[i-r:i-r+k])

    # assert
    d  = fbndry[k:-k] - frcnst_m[k:-k]
    l2 = math.sqrt(np.dot(d, d))
    assert l2 < 1e-10, "stencil coeffs (-) are broken"

    d  = fbndry[k+1:-k] - frcnst_p[k+1:-k]
    l2 = math.sqrt(np.dot(d, d))
    assert l2 < 1e-10, "stencil coeffs (+) are broken"
