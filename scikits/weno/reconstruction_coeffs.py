"""PyWENO non-uniform reconstruction coefficients."""

import ccoeffs


def reconstruction_coeffs(xi, i, r, k, x, c):
  """Numerically compute the reconstruction coefficients *c_j* and
  store the results in *c* (indexed as ``c[j]``).

  The reconstruction coefficients *c_j* are used to approximate the
  function *f* given its cell averages *f_j* according to

  .. math::

    f(\\xi) \\approx \sum_{j=0}^k c_j\, \overline{f}_{i-r+j}.

  :param xi: reconstruction point
  :param i: - cell index (ie, index of the cell that containts *xi*)
  :param r: - left shift
  :param k: - order
  :param x: - cell boundaries
  :param c: - computed reconstruction coefficients (returned)

  Note: the reconstruction coefficients are destructively stored in
  *c*.

  """

  import ccoeffs

  try:
    ccoeffs.reconstruction_coeffs(xi, i, r, k, x, c)
  except:
    raise NotImplementedError, "reconstruction coeffs for k = %d not implemented yet" % (k)
