"""PyWENO WENO reconstructor."""

import math
import numpy as np

import cweno

valid_k = (5, 17)
valid_points = [ 'left', 'right', 'middle', '+/-',
                 'gauss', 'gauss_legendre',
                 'gauss_lobatto',
                 'gauss_radau' ]


def reconstruct(q, k, points,
                n=None,
                smoothness=None,
                weights=None,
                return_smoothness=False,
                return_weights=False,
                squeeze=True):
  """Perform WENO reconstruction of q.

  :param q: cell-averaged unknown to reconstruct
  :param k: order of reconstruction (5 to 17)
  :param points: reconstruction points (see below)
  :param n: number of reconstruction points (see below)
  :param smoothness: use as smoothness indicators
  :param weights: use as non-linear weights
  :param return_smoothness: return smoothness indicators?
  :param return_weights: return weights?
  """

  if (k % 2) == 0:
    raise ValueError, 'even order WENO reconstructions are not supported'

  if k < valid_k[0] or k > valid_k[1]:
    raise ValueError, '%d order WENO reconstructions are not supported' % k

  if not (points in valid_points):
    raise ValueError, "'points' must be one of: " + ', '.join(valid_points)

  if points == 'gauss':
    points = 'gauss_legendre'

  N = q.shape[0]
  k = (k+1)/2

  # validate n

  if points in [ 'left', 'right', 'middle' ]:
    n = 1
  elif n is None:
    n = k

  if points in [ '+/-' ]:
    n = 2

  assert(n > 0)

  # smoothness

  if smoothness is None:
    smoothness = np.zeros((N,k))

    func = getattr(cweno, 'smoothness%03d' % k)
    func(q, smoothness)

  assert(smoothness.shape == (N,k))

  # weights, reconstruct

  if weights is None:
    if return_weights:
      # XXX: in generate_weno.py, have to add reconstructions with
      # local_weights=False, corresponding weights functions, and
      # corresponding wrappers to accept weights
      weights = np.zeros((N,n,k))
      raise NotImplementedError

    else:
      qr = np.zeros((N,n))

      if points == '+/-':
        raise NotImplementedError, '+/- not implemented yet'  
      
      try:
        func = getattr(cweno, points + '%03d%03d' % (k, n))
      except AttributeError:
        raise ValueError, 'weno reconstruction not found, unsupported combination of k and n'
    
      func(q, smoothness, qr)

  else:
    # XXX: in generate_weno.py, have to add reconstructions with
    # local_weights=False, and corresponding wrappers to accept weights
    assert(weights.shape == (N,n,k))
    raise NotImplementedError

  # done!
  if squeeze:
    qr      = qr.squeeze()
    if weights and return_weights:
      weights = weights.squeeze()

  if return_smoothness and return_weights:
    return (qr, smoothness, weights)

  if return_smoothness:
    return (qr, smoothness)

  if return_weights:
    return (qr, weights)

  return qr



# XXX: move this to another file...
def reconstruction_coeffs(xi, i, r, k, x, c):
  """Numerically compute the reconstruction coefficients *c_j* and
  store the results in *c* (indexed as ``c[j]``).

  The reconstruction coefficients *c_j* are used to approximate the
  *d*'th derivative of a function *f* given its cell averages *f_j*
  according to

  .. math::

    f^{(d)}(\\xi) \\approx \sum_{j=0}^k c_j\, \overline{f}_{i-r+j}.

  This function wraps a fast C implementation, and is especially
  useful for non-uniform grids.

  Arguments:

  * *xi* - reconstruction point
  * *i* - cell index (ie, index of the cell that containts *xi*)
  * *r* - left shift
  * *k* - order
  * *x* - cell boundaries
  * *c* - computed reconstruction coefficients (returned)

  Return: the reconstruction coefficients are destructively stored
  in *c*.

  """

  import ccoeffs

  try:
    ccoeffs.reconstruction_coeffs(xi, i, r, k, x, c)
  except:
    raise NotImplementedError, "reconstruction coeffs for k = %d not implemented yet" % (k)
