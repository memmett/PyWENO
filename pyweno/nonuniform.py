"""PyWENO non-uniform reconstruction routines."""

import reconstruction_coeffs as rc
import numpy as np

def reconstruction_coeffs(xi, k, x):
  """Numerically compute the reconstruction coefficients for a 2k-1
  order WENO scheme corresponding to the reconstruction points in *xi*
  on the non-uniform grid *x*.

  The reconstruction points in *xi* should in :math:`[-1, 1]`.  This
  interval is then mapped to the cell :math:`[x_{i-1/2}, x_{i+1/2}]`.

  :param xi: list of reconstruction points
  :param k: reconstruction order
  :param x: cell boundaries

  The returned coefficients are stored in a NumPy array that is
  indexed according to ``c[i,l,r,j]``.  That is

  .. math::

    f^r(\xi_l) \approx \sum_j c^{l,r}_{i,j} \, f_{i-r+j}

  for each :math:`l` from 0 to ``len(xi)``.

  """

  N = len(x)-1
  n = len(xi)

  c = np.zeros((N,n,k,k))       # indexed as c[i,l,r,j]

  for i in range(N):
    for l in range(n):
      z = 0.5*(x[i] + x[i+1]) + 0.5*(x[i+1] - x[i])*xi[l]
      for r in range(k):
        rc.reconstruction_coeffs(z, i, r, k, x, c[i,l,r,:])

  return c


def optimal_weights(xi, k, x):
  """XXX"""

  pass
