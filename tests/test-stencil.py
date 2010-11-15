"""Test pyweno.stencil module."""

import math
import os

import numpy as np

import pyweno.grid
import pyweno.stencil


######################################################################
# cache

def test_cache():

    try:
        os.unlink('cache.h5')
    except:
        pass

    k = 3
    x = np.linspace(0.0, 10.0)
    grid = pyweno.grid.Grid(x)

    stncl = pyweno.stencil.Stencil(grid=grid, order=k)
    stncl.reconstruction_coeffs('left')
    stncl.reconstruction_coeffs('right')
    stncl.cache('cache.h5')

    stncl2 = pyweno.stencil.Stencil(order=k, cache='cache.h5')

    assert(np.all(stncl.c['left'] == stncl2.c['left']))
    assert(np.all(stncl.c['right'] == stncl2.c['right']))


######################################################################
# reconstructions

def f(x):
    return 1.0 - x + x*x
uf = np.frompyfunc(f, 1, 1)

def fp(x):
    return -1.0 + 2.0*x
ufp = np.frompyfunc(fp, 1, 1)


def test_by_reconstructing():

    K = range(3, 6)
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

            d  = fpbndry[k:-k] - fprcnst[k:-k]
            l2 = math.sqrt(np.dot(d, d))
            assert l2 < 1e-10, "stencil coeffs (k=%d, r=%d, prime) are broken" % (k, r)


######################################################################
# coefficients

def test_coefficients():

    x = np.linspace(0.0, 1.0)
    grid = pyweno.grid.Grid(boundaries=x)
    stencil = pyweno.stencil.Stencil(grid=grid, order=3, shift=0)

    stencil.reconstruction_coeffs('left')
    c = stencil.c['left']
    c_exact = np.array([1.8333333333333337, -1.166666666666667, 0.33333333333333348])

    assert np.max(abs(c - c_exact)) < 1e-10, 'left coefficients are broken'

    stencil.reconstruction_coeffs('right')
    c = stencil.c['right']
    c_exact = np.array([0.3333333333333332, 0.83333333333333348, -0.16666666666666671])

    assert np.max(abs(c - c_exact)) < 1e-10, 'right coefficients are broken'

