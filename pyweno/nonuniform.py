"""PyWENO non-uniform reconstruction routines."""

import numpy as np

def coefficients(k, xi, x):
    """Numerically compute reconstruction and smoothness coefficients.

    This wraps the "symbolic" C routines in the cnonuniform extension
    module.
    """

    import pyweno.cnonuniform

    x  = np.asarray(x,  np.float64)
    xi = np.asarray(xi, np.float64)

    nc = len(x) - 1
    n  = len(xi)
    c     = np.zeros((nc, n, k, k), np.float64)
    beta  = np.zeros((nc, k, k, k), np.float64)
    varpi = np.zeros((nc, n, k), np.float64)

    pyweno.cnonuniform.nonuniform_coeffs(k, xi, x, c, beta, varpi)

    return c, beta, varpi
