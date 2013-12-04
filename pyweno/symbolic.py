"""PyWENO symbolic tool kit."""

import sympy
from itertools import product

from sympy import Symbol as sym


###############################################################################

def polynomial_interpolator(x, y):
  """Build a symbolic polynomial that interpolates the points (x_i, y_i).

  The returned polynomial is a function of the SymPy variable x.
  """

  k, xi = len(x), sym('x')

  sum_i = 0
  for i in range(k):
    ns = range(k)
    ns.remove(i)

    num, den = 1, 1
    for n in ns:
      num *= xi   - x[n]
      den *= x[i] - x[n]

    sum_i += num / den * y[i]

  return sum_i


###############################################################################

def primitive_polynomial_interpolator(x, y):
  """Build a symbolic polynomial that approximates the primitive
  function f such that f(x_i) = sum_j y_j * (x_{j+1} - x_{j}).

  Note: The x argument should be list that is one element longer
  than the y list.

  The returned polynomial is a function of the SymPy variable 'x'.
  """

  Y = [0]
  for i in range(len(y)):
    Y.append(Y[-1] + (x[i+1] - x[i]) * y[i])

  return polynomial_interpolator(x, Y)

ppi = primitive_polynomial_interpolator


###############################################################################

def _pt(a, b, x):
  """Map x in [-1, 1] to x in [a, b]."""

  half = sympy.sympify('1/2')

  w = half * (b - a)
  c = half * (a + b)

  return w * x + c


def reconstruction_coefficients(k, xi, d=0):
  r"""Compute the reconstruction coefficients for a 2k-1 order WENO
  scheme corresponding to the reconstruction points in *xi*.

  The reconstruction points in *xi* should in :math:`[-1, 1]`.  This
  interval is then mapped to the cell :math:`[x_{i-1/2}, x_{i+1/2}]`.

  The returned coefficients are stored as SymPy variables in a
  dictionary indexed according to ``c[l, r, j]``.  That is

  .. math::

    f^r(\xi_l) \approx \sum_j c^{l,r}_j \, f_{i-r+j}

  for each :math:`l` from 0 to ``len(xi)``.
  """

  i, n, x, dx  = k-1, len(xi), sym('x'), sym('dx')

  # build arrays of cell boundaries and cell averages
  xs = [ j*dx               for j in range(-k+1, k+1) ]
  fs = [ sym('f[i%+d]' % j) for j in range(-k+1, k)   ]

  c = { 'n': n, 'k': k, 'd': d }

  # compute reconstruction coefficients for each left shift r
  for l, r in product(range(n), range(k)):
    p = ppi(xs[i-r:i-r+k+1], fs[i-r:i-r+k]).diff(x, d+1)

    for j in range(k):
      z = _pt(xs[i], xs[i+1], xi[l])
      c[l, r, j] = p.subs(x, z).expand().coeff(fs[i-r+j])

      if c[l, r, j] is None:
        c[l, r, j] = 0

      c[l, r, j] *= dx**d

  return c


###############################################################################

def optimal_weights(k, xi, **kwargs):
  r"""Compute the optimal weights for a 2k-1 order WENO scheme
  corresponding to the reconstruction points in *xi*.

  The coefficients are stored as SymPy variables in a dictionary
  indexed according to ``w[l,r]``.  That is

  .. math::

    f(\xi^l) \approx \sum_r w^r f^r

  for each :math:`l` from 0 to ``len(xi)``.
  """

  n = len(xi)

  c   = reconstruction_coefficients(k, xi, **kwargs)
  c2k = reconstruction_coefficients(2*k-1, xi, **kwargs)

  omega = [ sym('omega%d' % r) for r in range(k) ]
  varpi = { 'n': n, 'k': k }
  split = { 'n': n }

  for l in range(n):

    # use first k eqns since weight system is overdetermined
    eqns = []
    for j in range(k):
      rmin, rmax = max(0, (k-1)-j), min(k-1, 2*(k-1)-j)
      terms = [ omega[r] * c[l, r, r-(k-1)+j] for r in range(rmin, rmax+1) ]
      eqns.append(sum(terms) - c2k[l, k-1, j])

    # XXX: Should make sure that when mpmath.mpf's are passed in
    # (in xi), that the solution obtained above is a high
    # precision solution.

    sol = sympy.solve(eqns, omega)

    # now check all 2*k-1 eqns to make sure the weights work out properly
    for j in range(2*k-1):
      rmin, rmax = max(0, (k-1)-j), min(k-1, 2*(k-1)-j)
      terms = [ omega[r] * c[l, r, r-(k-1)+j] for r in range(rmin, rmax+1) ]
      eqn = sum(terms) - c2k[l, k-1, j]
      err = eqn.subs(sol)
      if abs(err) > 1e-15:
        raise ValueError("optimal weight %d failed with error %s" % (j, err))

    # set weight or split as appropriate
    split[l] = min(sol.values()) < 0
    for r in range(k):
      if split[l]:
        w  = sol[omega[r]]
        wp = (w + 3*abs(w))/2
        wm = wp - w
        varpi[l, r] = (wp, wm)
      else:
        varpi[l, r] = sol[omega[r]]

  return varpi, split


###############################################################################

def jiang_shu_smoothness_coefficients(k):
  r"""Compute the Jiang-Shu smoothness coefficients for a 2k-1 order
  WENO scheme.

  The coefficients are stored as SymPy variables in a dictionary
  indexed according to ``beta[r, m, n]``.  That is

  .. math::

    \sigma^r = \sum_{m=1}^{2k-1} \sum_{n=1}^{2k-1}
      \beta_{r,m,n}\, \overline{f}_{i-k+m}\, \overline{f}_{i-k+n}.
  """

  x, dx, xi = sym('x'), sym('dx'), sym('x')

  # build arrays of cell boundaries and cell averages
  xs = [ j*dx               for j in range(-k+1, k+1) ]
  fs = [ sym('f[i%+d]' % j) for j in range(-k+1, k)   ]

  beta = { 'k': k }

  # compute smoothness coefficients for each left shift r
  for r in range(k):
    p = ppi(xs[k-1-r:2*k-r], fs[k-1-r:2*k-1-r]).diff(x)

    # sum of L^2 norms of derivatives
    s = 0
    for j in range(1, k):
      pp = sympy.diff(p, xi, j)**2
      pp = pp.as_poly(x)
      pp = pp.integrate(x)
      pp = dx**(2*j-1) * ( pp.subs(x, xs[k]) - pp.subs(x, xs[k-1]) )
      s += pp.expand()

    # pick out coefficients
    for m in range(k):
      for n in range(m, k):
        c = s.coeff(fs[k-1-r+m]*fs[k-1-r+n])
        if c is not None:
          beta[r, m, n] = c

  return beta


###############################################################################

def reconstruction_coefficients_for_derivative(k, bias):
  """XXX"""

  i = k-1
  (x, dx) = sympy.var('x dx')

  # build array of grid points (sympy vars x[i])
  xs = []
  for j in range(-k+1, k+1):
    xs.append(j*dx)

  # build array of point values (sympy vars f[i])
  fs = []
  for j in range(-k+1, k+1):
    fs.append(sympy.var('f[i%+d]' % j))

  n = 1

  # compute reconstruction coefficients for each left shift r
  c = { 'n': n, 'k': k, 'l': k+1 }

  for l in range(n):
    for r in range(0, k):
      p = polynomial_interpolator(xs[i-r:i-r+k+1], fs[i-r:i-r+k+1]).diff(x)

      z = xs[i] if bias=='+' else xs[i+1]

      for j in range(0, k+1):
        p = p.expand()
        c[l,r,j] = p.subs(x, z).coeff(fs[i-r+j])

        if c[l,r,j] is None:
          c[l,r,j] = 0 # i think it may be zero for k=2
        c[l,r,j] *= dx

  return c


###############################################################################

def optimal_weights_for_derivative(k, bias):
  """XXX"""

  n = 1
  c   = reconstruction_coefficients_for_derivative(k, bias)
  c2k = reconstruction_coefficients_for_derivative(2*k-1, bias)

  omega = []
  for r in range(k):
    omega.append(sympy.var('omega%d' % r))

  varpi = { 'n': n, 'k': k }
  split = { 'n': n }

  for l in range(n):
    eqns = []

    # we'll just use the first k eqns since the system is overdetermined
    for j in range(k):

      rmin = max(0, (k-1)-j)
      rmax = min(k-1, 2*(k-1)-j)

      accum = 0
      for r in range(rmin, rmax+1):
        accum = accum + omega[r] * c[l,r,r-(k-1)+j]

      eqns.append(accum - c2k[l,k-1,j])

    # XXX: Should make sure that when mpmath.mpf's are passed in
    # (in xi), that the solution obtained above is a high
    # precision solution.

    sol = sympy.solve(eqns, omega)

    # now check all 2*k-1 eqns to make sure the weights work out properly
    for j in range(2*k-1):

      rmin = max(0, (k-1)-j)
      rmax = min(k-1, 2*(k-1)-j)

      accum = 0
      for r in range(rmin, rmax+1):
        accum = accum + omega[r] * c[l,r,r-(k-1)+j]

      eqn = accum - c2k[l,k-1,j]
      eqn.subs(sol)             # XXX: check this

    # check for negative weights and mark as split
    if min(sol.values()) < 0:
      split[l] = True
    else:
      split[l] = False

    # split as appropriate
    for r in range(k):
      if split[l]:
        w  = sol[omega[r]]
        wp = (w + 3*abs(w))/2
        wm = wp - w
        varpi[l,r] = (wp, wm)
      else:
        varpi[l,r] = sol[omega[r]]

  return (varpi, split)


###############################################################################

def jiang_shu_smoothness_coefficients_for_derivative(k, bias):
  """XXX"""

  (x, dx) = sympy.var('x dx')

  # build array of grid points (sympy vars x[i])
  xs = []
  for j in range(-k+1, k+1):
    xs.append(j*dx)

  # build array of point values (sympy vars f[i])
  fs = []
  for j in range(-k+1, k+1):
    fs.append(sympy.var('f[i%+d]' % j))

  # compute reconstruction coefficients for each left shift r
  beta = { 'k': k, 'l' : k+1 }
  for r in range(0, k):
    p = polynomial_interpolator(xs[k-1-r:2*k-r], fs[k-1-r:2*k-r])
    # sum of L^2 norms of derivatives
    s = 0
    for j in range(2, k+1):
      # start at the second derivative since we are
      # interested in the smoothness of the derivative of p
      pp = (sympy.diff(p, x, j))**2
      pp = sympy.integrate(pp, x)
      q = (-1 if bias=='+' else 1) * dx/2
      pp = (xs[k] - xs[k-1])**(2*j-1) * (
        pp.subs(x, xs[k]) - pp.subs(x, xs[k-1]) )
      pp = pp.expand()
      s = s + pp

    # pick out coefficients
    for m in range(k+1):
      for n in range(m, k+1):
        c = s.coeff(fs[k-1-r+m]*fs[k-1-r+n])
        if c is not None:
          beta[r,m,n] = c

  return beta

