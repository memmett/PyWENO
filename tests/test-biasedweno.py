"""Test biased WENO reconstruction on an unstructured grid."""

import math

import numpy as np

import pyweno.grid
import pyweno.weno


# test function

def f(x):
    return 1.0 - x + x*x
uf = np.frompyfunc(f, 1, 1)


######################################################################

def test_biasedweno():

    K = range(3, 4)
    x = np.array([-4.0, -3.5, -3.0, -2.5, -2.0, -1.5,
                  -1.0, -0.8, -0.6, -0.4,
                  -0.3, -0.2, -0.1, 0.0, 0.1, 0.2, 0.3,
                  0.4, 0.6, 0.8, 1.0,
                  1.5, 2.0, 2.5, 3.0, 3.5, 4.0])
    grid = pyweno.grid.Grid(boundaries=x)

    # f and f' evaluated at boundaries
    fbndry = uf(x)

    # average of f
    fbar = np.zeros(grid.N)
    fbar[:] = grid.average(f)

    for k in K:
        weno = pyweno.weno.WENO(grid=grid, order=k)
        weno.precompute_reconstruction('left', s=-1) # XXX: test more s values

        # f reconstructed at boundaries
        frcnst = np.zeros(x.size)

        weno.smoothness(fbar)
        weno.reconstruct(fbar, 'left', frcnst)

        # assert
        d  = fbndry[k+1:-k-1] - frcnst[k+1:-k-1]
        l2 = math.sqrt(np.dot(d, d))
        assert l2 < 1e-10, "WENO (k=%d, left) is broken" % (k)


if __name__ == '__main__':
    test_biasedweno()

