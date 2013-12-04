"""Test the PyWENO reconstructions."""

import numpy as np

from pyweno.weno import reconstruct


######################################################################
# test by reconstructing

# XXX: test more pts, orders, and functions

def f(x):
  return np.sin(x)

def F(a, b):
  return (-np.cos(b) - -np.cos(a))/(b-a)


def test_reconstruction():

  K = (5, 7)
  x = np.linspace(0.0, 2*np.pi, 51)

  # average of f (we're testing striding too, hence the extra component)
  q      = np.zeros((3,x.size-1))
  q[0,:] = F(x[:-1], x[1:])

  for k in K:
    qr = reconstruct(q[0,:], k, 'left')
    err = np.log10(1e-30 + abs(qr[k:-k] - f(x[:-1])[k:-k]).max())

    print 'k: %d, error: %lf' % (k, err)

    assert err < max(-k, -13), "WENO (k=%d, left) is broken" % (k)


if __name__ == '__main__':
  test_reconstruction()
