"""Test reconstruction coefficients on an unstructured grid."""

import math

import numpy as np

import pyweno.grid
import pyweno.stencil


def f(x):
    """Test function (quadratic)."""

    return 1.0 - x + x*x

def fp(x):
    """Derivative of test function."""

    return -1.0 + 2.0*x


def test_stencils():

    K = range(5, 9)

    x = np.array([-4.0, -3.5, -3.0, -2.5, -2.0, -1.5,
                  -1.0, -0.8, -0.6, -0.4,
                  -0.3, -0.2, -0.1, 0.0, 0.1, 0.2, 0.3,
                  0.4, 0.6, 0.8, 1.0,
                  1.5, 2.0, 2.5, 3.0, 3.5, 4.0])
    grid = pyweno.grid.Grid(boundaries=x)

    for k in K:
        for r in range(0, k):

            stencil = pyweno.stencil.Stencil(grid=grid, order=k, shift=r)
            stencil.reconstruction_coeffs('left', d=0)
            stencil.reconstruction_coeffs('pleft', xi=lambda i: x[i], d=1)

            # average values of f
            fbar = grid.average(f)

            # f and f' evaluated at boundaries
            fbndry = np.zeros(x.size)
            fpbndry = np.zeros(x.size)
            for i in range(x.size):
                fbndry[i]  = f(x[i])
                fpbndry[i] = fp(x[i])

            # f and f' reconstructed at boundaries
            frcnst = np.zeros(x.size)
            fprcnst = np.zeros(x.size)
            for i in range(k, x.size-k):
                frcnst[i] = np.dot(stencil.c['left'][i,:], fbar[i-r:i-r+k])
                fprcnst[i] = np.dot(stencil.c['pleft'][i,:], fbar[i-r:i-r+k])

            print fbndry
            print frcnst

            print fpbndry
            print fprcnst

            # assert
            d  = fbndry[k:-k] - frcnst[k:-k]
            l2 = math.sqrt(np.dot(d, d))
            assert l2 < 1e-10, "stencil coeffs (k=%d, r=%d) are broken" % (k, r)

            d  = fpbndry[k+1:-k] - fprcnst[k+1:-k]
            l2 = math.sqrt(np.dot(d, d))
            assert l2 < 1e-10, "stencil coeffs (k=%d, r=%d, prime) are broken" % (k, r)
