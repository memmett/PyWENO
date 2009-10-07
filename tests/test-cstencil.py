"""Test reconstruction coefficients on an unstructured grid."""

import math

import numpy as np

import pyweno.stencil
import pyweno.cstencil

def test_cstencil():
    r = 2
    k = 5

    x = np.array([-4.0, -3.5, -3.0, -2.5, -2.0, -1.5,
                  -1.0, -0.8, -0.6, -0.4,
                  -0.3, -0.2, -0.1, 0.0, 0.1, 0.2, 0.3,
                  0.4, 0.6, 0.8, 1.0,
                  1.5, 2.0, 2.5, 3.0, 3.5, 4.0])

    c1 = np.zeros((x.size, k))
    c2 = np.zeros((x.size, k))

    for i in range(k, x.size-k):
        pyweno.stencil.reconstruction_coeffs(i, r, k, x, c1[i,:], '-')
        pyweno.cstencil.reconstruction_coeffs_5m(i, r, x, c2[i,:])

    d  = c1.flatten() - c2.flatten()
    l2 = math.sqrt(np.dot(d, d))
    assert l2 < 1e-10, "cstencil coeffs (-) are broken"

    c1 = np.zeros((x.size, k))
    c2 = np.zeros((x.size, k))

    for i in range(k, x.size-k):
        pyweno.stencil.reconstruction_coeffs(i, r, k, x, c1[i,:], '+')
        pyweno.cstencil.reconstruction_coeffs_5p(i, r, x, c2[i,:])

    d  = c1.flatten() - c2.flatten()
    l2 = math.sqrt(np.dot(d, d))
    assert l2 < 1e-10, "cstencil coeffs (+) are broken"
