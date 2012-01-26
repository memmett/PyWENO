"""PyWENO non-uniform reconstruction routines."""

import numpy as np
import sympy

import reconstruction_coeffs as rc
import symbolic


###############################################################################

def reconstruction_coefficients(k, xi, x):
  r"""Numerically compute the reconstruction coefficients for a 2k-1
  order WENO scheme corresponding to the reconstruction points in *xi*
  on the non-uniform grid *x*.

  The reconstruction points in *xi* should be in :math:`[-1, 1]`.  This
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

  x = np.array(x)
  N = len(x)-1
  n = len(xi)

  c = np.zeros((N,n,k,k))       # indexed as c[i,l,r,j]

  for i in range(k, N-k):
    for l in range(n):
      z = 0.5*(x[i] + x[i+1]) + 0.5*(x[i+1] - x[i])*xi[l]
      for r in range(k):
        c[i,l,r,:] = rc.reconstruction_coeffs(z, i, r, k, x)

  return c


###############################################################################

def optimal_weights(k, xi, x, tolerance=1e-12):
  r"""Compute the optimal weights for a 2k-1 order WENO scheme
  corresponding to the reconstruction points in *xi* on the
  non-uniform grid *x*.

  The coefficients are stored in a NumPy array that is indexed
  according to ``w[i,l,r]``.  That is

  .. math::

    f(\xi^l) \approx \sum_r w^r f^r

  for each :math:`l` from 0 to ``len(xi)``.
  """

  # XXX: using SymPy to do this is probably inefficient

  x = np.array(x)
  n = len(xi)
  N = len(x)

  c   = reconstruction_coefficients(xi, k, x)
  c2k = reconstruction_coefficients(xi, 2*k-1, x)

  omega = []
  for r in range(k):
    omega.append(sympy.var('omega%d' % r))

  varpi = numpy.zeros((N,l,k))
  # split = { 'n': n }

  for i in range(2*k,N-2*k):
    for l in range(n):
      eqns = []

      # we'll just use the first k eqns since the system is overdetermined
      for j in range(k):

        rmin = max(0, (k-1)-j)
        rmax = min(k-1, 2*(k-1)-j)

        accum = 0
        for r in range(rmin, rmax+1):
          accum = accum + omega[r] * c[i,l,r,r-(k-1)+j]

        eqns.append(accum - c2k[i,l,k-1,j])

      sol = sympy.solve(eqns, omega)

      # now check all 2*k-1 eqns to make sure the weights work out properly
      for j in range(2*k-1):

        rmin = max(0, (k-1)-j)
        rmax = min(k-1, 2*(k-1)-j)

        accum = 0
        for r in range(rmin, rmax+1):
          accum = accum + omega[r] * c[i,l,r,r-(k-1)+j]

        eqn = accum - c2k[i,l,k-1,j]
        if not abs(eqn.subs(sol)) < tolerance:
          raise ValueError('Unable to find optimal weight')

      if min(sol.values()) < 0:
        raise ValueError(
          'Negative optimal weight encountered at cell %d, point %d.' % (i, l))

      for r in range(k):
        varpi[i,l,r] = float(sol[omega[r]])


      # # check for negative weights and mark as split
      # if min(sol.values()) < 0:
      #   split[i,l] = True
      # else:
      #   split[i,l] = False

      # # split as appropriate
      # for r in range(k):
      #   if split[i,l]:
      #     w  = sol[omega[r]]
      #     wp = (w + 3*abs(w))/2
      #     wm = wp - w
      #     varpi[i,l,r] = (wp, wm)
      #   else:
      #     varpi[i,l,r] = sol[omega[r]]

  # return (varpi, split)
  return varpi


###############################################################################

def jiang_shu_smoothness_coefficients(k, x):
  r"""Compute the Jiang-Shu smoothness coefficients for a 2k-1 order
  WENO scheme on the non-uniform grid *x*.

  The coefficients are stored in a NumPy array indexed according to
  ``beta[i,r,m,n]``.  That is

  .. math::

    \sigma^r = \sum_{m=1}^{2k-1} \sum_{n=1}^{2k-1}
      \beta_{r,m,n}\, \overline{f}_{i-k+m}\, \overline{f}_{i-k+n}.
  """

  xs = np.array(x)
  N  = len(xs)
  x  = sympy.var('x')

  # build array of cell averages (sympy vars f[i])
  fs = []
  for j in range(-k+1, k):
    fs.append(sympy.var('f[i%+d]' % j))

  # compute reconstruction coefficients for each left shift r
  beta = np.zeros((N,k,2*k-1,2*k-1))
  for i in range(k, N-k):
    for r in range(0, k):
      p = symbolic.primitive_polynomial_interpolator(xs[i-r:i-r+k+1],
                                                     fs[k-1-r:k-1-r+k]).diff(x)
      # sum of L^2 norms of derivatives
      s = 0
      for j in range(1, k):
        pp = (sympy.diff(p, x, j))**2
        pp = pp.as_poly(x)
        pp = pp.integrate(x)
        #pp = pp.as_basic()
        pp = (xs[i+1] - xs[i])**(2*j-1) * (
          pp.subs(x, xs[i+1]) - pp.subs(x, xs[i]) )
        pp = pp.expand()
        s = s + pp

      #s = s.expand()

      # pick out coefficients
      for m in range(2*k-1):
        for n in range(m, 2*k-1):
          c = s.coeff(fs[m]*fs[n])
          if c is not None:
            beta[i,r,m,n] = float(c)

  return beta


