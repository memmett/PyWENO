"""Test smoothness indicators on an unstructured grid."""

import math

import numpy as np

import pyweno.grid
import pyweno.weno


# test function and it's derivative

def f(x):
    return 1.0 - x + x*x
uf = np.frompyfunc(f, 1, 1)

def fp(x):
    return -1.0 + 2.0*x
ufp = np.frompyfunc(fp, 1, 1)


######################################################################

def test_smoothness():

    # XXX

    pass
