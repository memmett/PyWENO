"""PyWENO smoothness indicators.

"""

import numpy as np


def uszs3(grid, N, k, f, sigma):
    """Unstructured Zhang and Shu smoothness indicator (not yet implemented)."""
    raise NotImplementedError, 'uszs3 smoothness indicator not yet implemented'


def szs3(grid, N, k, f, sigma):
    """Structured Zhang and Shu smoothness indicator."""

    for i in xrange(k,N-(k-1)):
        sigma[i,0] = (3.0*f[i] - 4.0*f[i+1] + f[i+2]) * (3.0*f[i] - 4.0*f[i+1] + f[i+2])
        sigma[i,1] = (f[i-1] - f[i+1]) * (f[i-1] - f[i+1])
        sigma[i,2] = (f[i-2] - 4.0*f[i-1] + 3.0*f[i]) * (f[i-2] - 4.0*f[i-1] + 3.0*f[i])
