"""Test pyweno.smoothness module (jiang_shu smoothness indicators)."""

import math

import numpy as np

import pyweno.grid
import pyweno.smoothness
import pyweno.weno


######################################################################

def test_smoothness():

    x = np.linspace(-1.0, 1.0, 21)
    grid = pyweno.grid.Grid(boundaries=x)

    k = 3
    N = x.shape[0] - 1

    beta = np.zeros((k,2*k-1,2*k-1))

    pyweno.smoothness.beta('jiang_shu', grid, k, beta)

    print beta

    # XXX: add an assert somewhere!

######################################################################


if __name__ == '__main__':
    test_smoothness()
