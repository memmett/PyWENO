"""PyWENO smoothness indicators.

"""

import numpy as np


def uszs3(grid, N, k, f):
    """Unstructured Zhang and Shu smoothness indicator (not yet implemented)."""
    raise NotImplementedError, 'uszs3 smoothness indicator not yet implemented'


def szs3(grid, N, k, f):
    """Structured Zhang and Shu smoothness indicator."""

    sigma = np.zeros((N+1,k))

    for i in xrange(k,N-(k-1)):
        sigma[i,0] = (3.0*f[i] - 4.0*f[i+1] + f[i+2]) * (3.0*f[i] - 4.0*f[i+1] + f[i+2])
        sigma[i,1] = (f[i-1] - f[i+1]) * (f[i-1] - f[i+1])
        sigma[i,2] = (f[i-2] - 4.0*f[i-1] + 3.0*f[i]) * (f[i-2] - 4.0*f[i-1] + 3.0*f[i])

    return sigma
