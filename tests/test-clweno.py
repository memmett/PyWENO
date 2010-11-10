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
            weno.smoothness(fbar)

            # weno.precompute_reconstruction('left')
            # weno.precompute_reconstruction('d|left')

            # # f reconstructed at boundaries
            # frcnst = np.zeros((grid.N,3))
            # fprcnst = np.zeros((grid.N,3))

            # weno.smoothness(fbar[0,:])
            # weno.reconstruct(fbar[0,:], 'left', frcnst[:,0], s=s)
            # weno.reconstruct(fbar[0,:], 'd|left', fprcnst[:,0], s=s)

            # # assert
            # d  = fbndry[:-1] - frcnst[:,0]
            # l2 = math.sqrt(np.dot(d, d))

            # assert l2 < 1e-10, "WENO (k=%d, left) is broken" % (k)

            # d  = fpbndry[:-1] - fprcnst[:,0]
            # l2 = math.sqrt(np.dot(d, d))

            # assert l2 < 1e-10, "WENO (k=%d, d|left) is broken" % (k)



if __name__ == '__main__':
    test_by_reconstructing_uniform()
