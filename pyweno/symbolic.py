"""PyWENO symbolic tool kit."""

import warnings

import sympy

###############################################################################

def polynomial_interpolator(x, y):
  """Build a symbolic polynomial that interpolates the points (x_i, y_i).

     The returned polynomial is a function of the SymPy variable x.

  """

  xi = sympy.var('x')

  # build polynomial interpolant in Lagrange form
  k = len(x)
  sum_i = 0
  for i in range(k):

    ns = range(0,k)
    ns.remove(i)

    prod_n = 1
    for n in ns:
      prod_n = prod_n * (xi - x[n])

    prod_m = 1
    for m in ns:
      prod_m = prod_m * (x[i] - x[m])

    sum_i = sum_i + prod_n / prod_m * y[i]

  return sum_i


###############################################################################

def primitive_polynomial_interpolator(x, y):
  """Build a symbolic polynomial that approximates the primitive
     function f such that f(x_i) = sum_j y_j * (x_{j+1} - x_{j}).

     The returned polynomial is a function of the SymPy variable 'x'.

  """

  Y = [0]
  for i in range(0, len(y)):
    Y.append(Y[-1] + (x[i+1] - x[i]) * y[i])

  return polynomial_interpolator(x, Y)


###############################################################################

def _pt(a, b, x):
  """Map x in [-1, 1] to x in [a, b]."""

  half = sympy.sympify('1/2')

  w = half * (b - a)
  c = half * (a + b)

  return w * x + c


def reconstruction_coefficients(k, xi):
  r"""Compute the reconstruction coefficients for a 2k-1 order WENO
    scheme corresponding to the reconstruction points in *xi*.

    The reconstruction points in *xi* should in :math:`[-1, 1]`.  This
    interval is then mapped to the cell :math:`[x_{i-1/2}, x_{i+1/2}]`.

    The returned coefficients are stored as SymPy variables in an
    ndarray indexed according to ``c[l,r,j]``.  That is

    .. math::

      f^r(\xi_l) \approx \sum_j c^{l,r}_j \, f_{i-r+j}

    for each :math:`l` from 0 to ``len(xi)``.

  """

  i = k-1
  (x, dx) = sympy.var('x dx')

  # build array of cell boundaries (sympy vars x[i])
  xs = []
  for j in range(-k+1, k+1):
    xs.append(j*dx)

  # build array of cell averages (sympy vars f[i])
  fs = []
  for j in range(-k+1, k):
    fs.append(sympy.var('f[i%+d]' % j))

  # set reconstruction point xi
  n = len(xi)

  # compute reconstruction coefficients for each left shift r
  c = { 'n': n, 'k': k }

  for l in range(n):
    for r in range(0, k):
      p = primitive_polynomial_interpolator(
        xs[i-r:i-r+k+1], fs[i-r:i-r+k]).diff(x)

      for j in range(0, k):
        p = p.expand()

        z = _pt(xs[i], xs[i+1], xi[l])
        c[l,r,j] = p.subs(x, z).coeff(fs[i-r+j])

        if c[l,r,j] is None:
          raise ValueError, 'obtained a zero coefficient'

  return c


###############################################################################

def optimal_weights(k, xi):
  r"""Compute the optimal weights for a 2k-1 order WENO scheme
    corresponding to the reconstruction points in *xi*.

    The coefficients are stored as SymPy variables in an ndarray
    indexed according to ``w[l,r]``.  That is

    .. math::

      f(\xi^l) \approx \sum_r w^r f^r

    for each :math:`l` from 0 to ``len(xi)``.

  """

  n = len(xi)

  c   = reconstruction_coefficients(k, xi)
  c2k = reconstruction_coefficients(2*k-1, xi) #[:,k-1,:]

  omega = []
  for r in range(k):
    omega.append(sympy.var('omega%d' % r))

  varpi = { 'n': n, 'k': k }
  split = { 'n': n }

  for l in range(n):
    eqns = []

    #for j in range(2*k-1):
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

    # XXX: The j loop above stops at k, whereas it should
    # technically stop at 2*k-1.  That is, the system that should
    # be solved is overdetermined, but we are stopping when we
    # have enough equations.  As such, the solutions obtained
    # above should be checked...

    sol = sympy.solve(eqns, omega)

    if min(sol.values()) < 0:
      split[l] = True
    else:
      split[l] = False

    for r in range(k):
      if split[l]:
        w  = sol[omega[r]]
        wp = (w + 3*abs(w))/2
        wm = wp - w
        varpi[l,r] = (wp, wm)
      else:
        varpi[l,r] = sol[omega[r]]

  return (varpi, split)



###############################################################################n

def jiang_shu_smoothness_coefficients(k):
  r"""Compute the Jiang-Shu smoothness coefficients for a 2k-1 order
    WENO scheme.

    The coefficients are stored as SymPy variables in an array
    indexed according to ``beta[r,m,n]``.  That is

    .. math::

      \sigma^r = \sum_{m=1}^{2k-1} \sum_{n=1}^{2k-1}
        \beta_{r,m,n}\, \overline{f}_{i-k+m}\, \overline{f}_{i-k+n}.

  """

  i = k-1
  (x, dx) = sympy.var('x dx')
  xi = sympy.var('x')

  # build array of cell boundaries (sympy vars x[i])
  xs = []
  for j in range(-k+1, k+1):
    xs.append(j*dx)

  # build array of cell averages (sympy vars f[i])
  fs = []
  for j in range(-k+1, k):
    fs.append(sympy.var('f[i%+d]' % j))

  # compute reconstruction coefficients for each left shift r
  beta = { 'k': k }
  for r in range(0, k):
    p = primitive_polynomial_interpolator(xs[i-r:i-r+k+1],
                        fs[i-r:i-r+k]).diff(x)
    # sum of L^2 norms of derivatives
    s = 0
    for j in range(1, k):
      pp = (sympy.diff(p, xi, j))**2
      pp = pp.as_poly(x)
      pp = pp.integrate(x)
      pp = (xs[i+1] - xs[i])**(2*j-1) * (
        pp.subs(x, xs[i+1]) - pp.subs(x, xs[i]) )
      pp = pp.expand()
      s = s + pp

    s = s.expand()

    # pick out coefficients
    for m in range(2*k-1):
      for n in range(m, 2*k-1):
        c = s.coeff(fs[m]*fs[n])
        if c is not None:
          beta[r,m,n] = c

  return beta
