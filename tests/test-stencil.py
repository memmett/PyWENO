"""Test reconstruction coefficients on an unstructured grid."""

import math

import numpy as np

import pyweno.grid
import pyweno.stencil


def f(x):
    """Test function (quadratic)."""

    return x * x

def fp(x):
    """Derivative of test function."""

    return 2.0*x


def test_stencils():

    K = range(3, 9)

    x = np.array([-4.0, -3.5, -3.0, -2.5, -2.0, -1.5,
                  -1.0, -0.8, -0.6, -0.4,
                  -0.3, -0.2, -0.1, 0.0, 0.1, 0.2, 0.3,
                  0.4, 0.6, 0.8, 1.0,
                  1.5, 2.0, 2.5, 3.0, 3.5, 4.0])
    grid = pyweno.grid.Grid(boundaries=x)

    for k in K:
        for r in range(0, k):

            stencil = pyweno.stencil.Stencil(grid=grid, order=k, shift=r)

            # average values of f
            fbar = grid.average(f)

            # f and its first derivative at boundaries
            fbndry = np.zeros(x.size)
            fpbndry = np.zeros(x.size)
            for i in range(x.size):
                fbndry[i]  = f(x[i])
                fpbndry[i] = fp(x[i])

            # f reconstructed at boundaries
            frcnst_l = np.zeros(x.size)
            frcnst_r = np.zeros(x.size)
            for i in range(k, x.size-k):
                frcnst_l[i]   = np.dot(stencil.c_l[i,:], fbar[i-r:i-r+k])
                frcnst_r[i+1] = np.dot(stencil.c_r[i,:], fbar[i-r:i-r+k])

            # f' reconstructed at boundaries
            fprcnst = np.zeros(x.size)
            c = np.zeros(k)
            for i in range(k, x.size-k):
                pyweno.stencil.reconstruction_coeffs(x[i], i, r, k, x, c, d=1)
                fprcnst[i]   = np.dot(c, fbar[i-r:i-r+k])

            # assert
            d  = fbndry[k:-k] - frcnst_l[k:-k]
            l2 = math.sqrt(np.dot(d, d))
            assert l2 < 1e-10, "stencil coeffs (k=%d, r=%d, -) are broken" % (k, r)

            d  = fbndry[k+1:-k] - frcnst_r[k+1:-k]
            l2 = math.sqrt(np.dot(d, d))
            assert l2 < 1e-10, "stencil coeffs (k=%d, r=%d, +) are broken" % (k, r)

            d  = fpbndry[k+1:-k] - fprcnst[k+1:-k]
            l2 = math.sqrt(np.dot(d, d))
            assert l2 < 1e-10, "stencil coeffs (k=%d, r=%d, prime) are broken" % (k, r)
