"""Test WENO reconstruction on an unstructured grid."""

import os
import math

import numpy as np

import pyweno.grid
import pyweno.weno


######################################################################
# test cache

# XXX
# def test_cache():
#     raise NotImplementedError

######################################################################
# test by reconstructing

def f(x):
    return 1.0 - x + x*x
uf = np.frompyfunc(f, 1, 1)

def fp(x):
    return -1.0 + 2.0*x
ufp = np.frompyfunc(fp, 1, 1)

<<<<<<< HEAD:tests/test-weno.py
def test_by_reconstructing_uniform():

    K = range(3, 5)
=======
def test_reconstruction():

    K = range(3, 4)
>>>>>>> f0a56b840fe9993b98b3f55d40ca4ce2c1d546e3:tests/test-weno.py
    x = np.linspace(0.0, 1.0)
    grid = pyweno.grid.Grid(boundaries=x)

    # f and f' evaluated at boundaries
    fbndry = uf(x)
    fpbndry = ufp(x)

    # average of f (we're testing striding too, hence the extra component)
    fbar = np.zeros((3,grid.N))
    fbar[0,:] = grid.average(f)

    for k in K:

        for s in (0,):                  # XXX: test more s values

            weno = pyweno.weno.WENO(grid=grid, order=k)
            weno.precompute_reconstruction('left')
            weno.precompute_reconstruction('d|left')

            # f reconstructed at boundaries
            frcnst = np.zeros((grid.N,3))
            fprcnst = np.zeros((grid.N,3))

            weno.smoothness(fbar[0,:])
            weno.reconstruct(fbar[0,:], 'left', frcnst[:,0], s=s)
            weno.reconstruct(fbar[0,:], 'd|left', fprcnst[:,0], s=s)

            # assert
            d  = fbndry[:-1] - frcnst[:,0]
            l2 = math.sqrt(np.dot(d, d))

            assert l2 < 1e-10, "WENO (k=%d, left) is broken" % (k)

            d  = fpbndry[:-1] - fprcnst[:,0]
            l2 = math.sqrt(np.dot(d, d))

            assert l2 < 1e-10, "WENO (k=%d, d|left) is broken" % (k)


######################################################################
# test coefficients

def f(x):
    return 1.0 - x + x*x
uf = np.frompyfunc(f, 1, 1)

def fp(x):
    return -1.0 + 2.0*x
ufp = np.frompyfunc(fp, 1, 1)


def test_coefficients_uniform():

    k = 3
    x = np.linspace(0.0, 1.0, 6)
    grid = pyweno.grid.Grid(boundaries=x)

    fbar = grid.average(f)

    weno = pyweno.weno.WENO(grid=grid, order=k)
    weno.precompute_reconstruction('left')

    frcnst = np.zeros((grid.N,3))

    weno.smoothness(fbar)
    weno.reconstruct(fbar, 'left', frcnst)

    sigma_exact = np.array([[0.032533333333327259, 0.0, 0.0],
                            [0.0133333333333289, 0.013333333333333242, 0.0],
                            [0.0069333333333292512, 0.0069333333333333157, 0.006933333333333281],
                            [0.0, 0.013333333333333214, 0.01333333333333335], [0.0, 0.0, 0.0]])
    wr_exact = np.array([[[1.0, 0.0, 0.0]],
                         [[0.2500000000011281, 0.74999999999887201, 0.0]],
                         [[0.099999999998186304, 0.60000000000776998, 0.2999999999940437]],
                         [[0.0, 0.49999999999929795, 0.50000000000070211]],
                         [[0.0, 0.0, 1.0]]])

    assert np.max(abs(sigma_exact - weno.sigma)) < 1e-10
    assert np.max(abs(wr_exact - weno.wr['left'])) < 1e-10
