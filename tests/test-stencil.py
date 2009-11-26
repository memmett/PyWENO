"""Test stencil reconstruction coefficients on an unstructured grid."""

import math

import numpy as np

import pyweno.grid
import pyweno.stencil

# test function and it's derivative

def f(x):
    return 1.0 - x + x*x
uf = np.frompyfunc(f, 1, 1)

def fp(x):
    return -1.0 + 2.0*x
ufp = np.frompyfunc(fp, 1, 1)

######################################################################

def test_stencils():

    K = range(5, 9)
    x = np.array([-4.0, -3.5, -3.0, -2.5, -2.0, -1.5,
                  -1.0, -0.8, -0.6, -0.4,
                  -0.3, -0.2, -0.1, 0.0, 0.1, 0.2, 0.3,
                  0.4, 0.6, 0.8, 1.0,
                  1.5, 2.0, 2.5, 3.0, 3.5, 4.0])
    grid = pyweno.grid.Grid(boundaries=x)

    # f and f' evaluated at boundaries
    fbndry = uf(x)
    fpbndry = ufp(x)

    # average of f
    fbar = grid.average(f)

    for k in K:
        for r in range(0, k):

            stencil = pyweno.stencil.Stencil(grid=grid, order=k, shift=r)
            stencil.reconstruction_coeffs('left')
            stencil.reconstruction_coeffs('d|left')

            # f and f' reconstructed at boundaries
            frcnst = np.zeros(x.size)
            fprcnst = np.zeros(x.size)
            for i in range(k, x.size-k):
                frcnst[i] = np.dot(stencil.c['left'][i,:], fbar[i-r:i-r+k])
                fprcnst[i] = np.dot(stencil.c['d|left'][i,:], fbar[i-r:i-r+k])

            # assert
            d  = fbndry[k:-k] - frcnst[k:-k]
            l2 = math.sqrt(np.dot(d, d))
            assert l2 < 1e-10, "stencil coeffs (k=%d, r=%d) are broken" % (k, r)

            d  = fpbndry[k+1:-k] - fprcnst[k+1:-k]
            l2 = math.sqrt(np.dot(d, d))
            assert l2 < 1e-10, "stencil coeffs (k=%d, r=%d, prime) are broken" % (k, r)
