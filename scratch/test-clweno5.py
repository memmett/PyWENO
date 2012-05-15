"""Test CLWENO5 reconstruction."""

import os
import math

import numpy as np

import pyweno.grid
import pyweno.clweno5

import pyopencl as cl
ctx = cl.create_some_context(interactive=False)


######################################################################
# test by reconstructing

def f(x):
    return math.sin(x)

uf = np.frompyfunc(f, 1, 1)


def test_reconstruction():

    k = 3

    x = np.linspace(-2.0, 2.0)
    grid = pyweno.grid.Grid(boundaries=x)
    fbar = grid.average(f)

    weno5 = pyweno.clweno5.CLWENO5PM(ctx=ctx)

    fbndry = uf(x[:-1])
    fp = np.zeros(grid.N)
    fm = np.zeros(grid.N)

    weno5.reconstruct(fbar, fp, fm)

    d  = fbndry[k+1:-k] - fp[k+1:-k]
    l2 = math.sqrt(np.dot(d, d))

    print d
    print l2

    assert l2 < 1e-5, "CLWENO5PM (+) is broken"

    d  = fbndry[k+1:-k] - fm[k+1:-k]
    l2 = math.sqrt(np.dot(d, d))

    print d
    print l2

    assert l2 < 1e-5, "CLWENO5PM (-) is broken"
