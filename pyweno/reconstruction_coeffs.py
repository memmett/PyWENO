"""PyWENO non-uniform reconstruction coefficients."""

import numpy as np
import pyweno.ccoeffs


def reconstruction_coeffs(xi, i, r, k, x):
  """Numerically compute the reconstruction coefficients.

  The reconstruction coefficients *c_j* are used to approximate the
  function *f* given its cell averages *f_j* according to

  .. math::

    f(\\xi) \\approx \sum_{j=0}^{k-1} c_j\, \overline{f}_{i-r+j}.

  :param xi: reconstruction point
  :param i: cell index (ie, index of the cell that containts *xi*)
  :param r: left shift
  :param k: order
  :param x: cell boundaries


  """

  c = np.empty(k)

  try:
    pyweno.ccoeffs.reconstruction_coeffs(xi, i, r, k, x, c)
  except:
    raise NotImplementedError, "reconstruction coeffs for k = %d not implemented yet" % (k)

  return c
