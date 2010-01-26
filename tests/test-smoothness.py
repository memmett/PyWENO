"""Test smoothness indicators on an unstructured grid."""

import math

import numpy as np

import pyweno.grid
import pyweno.smoothness
import pyweno.weno


######################################################################

def test_smoothness():

    x = np.array([-4.0, -3.5, -3.0, -2.5, -2.0, -1.5,
                  -1.0, -0.8, -0.6, -0.4,
                  -0.3, -0.2, -0.1, 0.0, 0.1, 0.2, 0.3,
                  0.4, 0.6, 0.8, 1.0,
                  1.5, 2.0, 2.5, 3.0, 3.5, 4.0])
    x = np.linspace(-1.0, 1.0, 21)
    grid = pyweno.grid.Grid(boundaries=x)

    k = 3
    N = x.shape[0] - 1

    beta = np.zeros((N,k,2*k-1,2*k-1))

    pyweno.smoothness.beta('jiang_shu', grid, k, beta)

    print beta[0,:,:,:]

    # XXX: add an assert somewhere!

######################################################################


if __name__ == '__main__':
    test_smoothness()
