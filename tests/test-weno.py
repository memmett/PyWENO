"""Test WENO reconstruction on an unstructured grid."""

import math

import numpy as np

import pyweno.grid
import pyweno.weno


def f(x):
    """Test function (quadratic)."""

    return 1.0 - x + x*x

def fp(x):
    """Derivative of test function."""

    return -1.0 + 2.0*x


def test_weno():

    K = range(3, 5)

    x = np.array([-4.0, -3.5, -3.0, -2.5, -2.0, -1.5,
                  -1.0, -0.8, -0.6, -0.4,
                  -0.3, -0.2, -0.1, 0.0, 0.1, 0.2, 0.3,
                  0.4, 0.6, 0.8, 1.0,
                  1.5, 2.0, 2.5, 3.0, 3.5, 4.0])
    grid = pyweno.grid.Grid(boundaries=x)

    # f and f' evaluated at boundaries
    fbndry = np.zeros(x.size)
    fpbndry = np.zeros(x.size)
    for i in range(x.size):
        fbndry[i]  = f(x[i])
        fpbndry[i] = fp(x[i])

    # average of f
    fbar = grid.average(f)

    for k in K:
        sigma = np.zeros((grid.N+1,k))
        weno = pyweno.weno.WENO(grid=grid, order=k)
        weno.reconstruction('left')
        weno.reconstruction('d|left')

        # f reconstructed at boundaries
        frcnst = np.zeros(x.size)
        fprcnst = np.zeros(x.size)

        weno.smoothness(fbar, sigma)
        weno.reconstruct(fbar, 'left', sigma, frcnst)
        weno.reconstruct(fbar, 'd|left', sigma, fprcnst)

        print fbndry
        print frcnst

        print fpbndry
        print fprcnst

        # assert
        d  = fbndry[k+1:-k-1] - frcnst[k+1:-k-1]
        l2 = math.sqrt(np.dot(d, d))
        assert l2 < 1e-10, "WENO (k=%d, left) is broken" % (k)

        d  = fpbndry[k+1:-k-1] - fprcnst[k+1:-k-1]
        l2 = math.sqrt(np.dot(d, d))
        assert l2 < 1e-10, "WENO (k=%d, d|left) is broken" % (k)

