"""Test WENO reconstruction on an unstructured grid."""

import os
import math

import numpy as np
import pyopencl as cl

import pyweno.grid
import pyweno.clweno

ctx = cl.create_some_context(interactive=False)


######################################################################
# test by reconstructing

def f(x):
    if x < 0.0:
        return math.sin(x)

    return math.cos(x)

uf = np.frompyfunc(f, 1, 1)

def test_by_reconstructing_uniform():

    K = range(3, 4)
    x = np.linspace(-1.0, 1.0, 1001)
    grid = pyweno.grid.Grid(boundaries=x)

    # f and f' evaluated at boundaries
    fbndry = uf(x)

    # average of f
    fbar = grid.average(f)

    for k in K:

        for s in (0,):                  # XXX: test more s values

            weno = pyweno.clweno.CLWENO(ctx=ctx, grid=grid, order=k)
            weno.precompute_reconstruction('left')

            weno2 = pyweno.weno.WENO(grid=grid, order=k)
            weno2.precompute_reconstruction('left')

            # f reconstructed at boundaries
            frcnst = np.zeros(grid.N)

            weno.smoothness(fbar)
            weno2.smoothness(fbar)

            weno.weights('left')
#            weno.weights('left')
            weno2.weights('left')

            print weno.wr['left']
            print weno2.wr['left']
            
            weno.reconstruct(fbar, 'left', frcnst, s=s) #, compute_weights=False)
#            print weno.wr['left']
#            print weno2.wr['left']

            # assert
            d  = fbndry[:-1] - frcnst[:]
            l2 = math.sqrt(np.dot(d, d))

            print l2

            assert l2 < 1e-8, "WENO (k=%d, left) is broken" % (k)



if __name__ == '__main__':
    test_by_reconstructing_uniform()
