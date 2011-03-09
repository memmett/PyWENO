"""PyWENO symbolic toolkit."""

import warnings

import numpy as np
import sympy


######################################################################

def polynomial_interpolator(x, y):
    """Build a symbolic polynomial that interpolates the points (x_i,
       y_i).

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


######################################################################

def primitive_polynomial_interpolator(x, y):
    """Build a symbolic polynomial that approximates the primitive
       function f such that f(x_i) = sum_j y_j * (x_{j+1} - x_{j}).

       The returned polynomial is a function of the SymPy variable x.
       """

    Y = [0]
    for i in range(0, len(y)):
        Y.append(Y[-1] + (x[i+1] - x[i]) * y[i])

    return polynomial_interpolator(x, Y)


######################################################################

def _quad_pts(a, b, x):

    half = sympy.sympify('1/2')

    w = half * (b - a)
    c = half * (a + b)

    return w * x + c

def _xi_pts(xi):

    if xi == 'gauss_quad3':
        return 3

    return 1


def reconstruction_coefficients(k, xi, uniform=True):
    r"""Compute the reconstruction coefficients for a 2k-1 order WENO
        scheme corresponding to the reconstruction point *xi*.

        The coefficients are stored as SymPy variables in an ndarray
        indexed according to ``c[r,j]``.  That is

        .. math::

          f^r(\xi) \approx \sum_j c^r_j \, f_{i-r+j}.


        """

    i = k-1
    (x, dx) = sympy.var('x dx')

    # build array of cell boundaries (sympy vars x[i])
    xs = []
    if uniform:
        for j in range(-k+1, k+1):
            xs.append(j*dx)
    else:
        for j in range(-k+1, k+1):
            xs.append(sympy.var('x[i%+d]' % j))

    # build array of cell averages (sympy vars f[i])
    fs = []
    for j in range(-k+1, k):
        fs.append(sympy.var('f[i%+d]' % j))

    # set reconstruction point xi
    n = _xi_pts(xi)

    if xi == 'left':
        xi = [ xs[i] ]
    elif xi == 'right':
        xi = [ xs[i+1] ]
    elif xi == 'gauss_quad3':
        xi = [ _quad_pts(xs[i], xs[i+1], -sympy.sqrt(15)/5),
               _quad_pts(xs[i], xs[i+1], 0),
               _quad_pts(xs[i], xs[i+1], sympy.sqrt(15)/5) ]
    else:
        raise ValueError, "reconstruction point '%s' not understood." % str(xi)

    # compute reconstruction coefficients for each left shift r
    c = np.zeros((n,k,k), dtype=np.dtype(object))

    for l in range(n):
        for r in range(0, k):
            p = primitive_polynomial_interpolator(xs[i-r:i-r+k+1], fs[i-r:i-r+k]).diff(x)

            for j in range(0, k):
                c[l,r,j] = p.subs(x, xi[l]).coeff(fs[i-r+j])

    if n == 1:
        return np.reshape(c, (k,k))

    return c


######################################################################

def optimal_weights(k, xi, uniform=True):
    r"""Compute the optimal weights for a 2k-1 order WENO scheme
        corresponding to the reconstruction point *xi*.

        The coefficients are stored as SymPy variables in an ndarray
        indexed according to ``w[r]``.  That is

        .. math::

          f(\xi) \approx \sum_r w^r f^r.

        """

    if not uniform:
        raise ValueError, "symbolic optimal weights haven't been implemented for non-uniform grids"

    n = _xi_pts(xi)

    c   = reconstruction_coefficients(k, xi, uniform=True)
    if n > 1:
        c2k = reconstruction_coefficients(2*k-1, xi, uniform=True)[:,k-1,:]
    else:
        c2k = reconstruction_coefficients(2*k-1, xi, uniform=True)[k-1,:]

    c   = np.reshape(c, (n, k, k))
    c2k = np.reshape(c2k, (n, 2*k-1))


    omega = []
    for r in range(k):
        omega.append(sympy.var('omega%d' % r))

    varpi = []
    split = []
    for l in range(n):
        eqns = []
        for j in range(2*k-1):

            rmin = max(0, (k-1)-j)
            rmax = min(k-1, 2*(k-1)-j)

            accum = 0
            for r in range(rmin, rmax+1):
                accum = accum + omega[r] * c[l,r,r-(k-1)+j]

            eqns.append(accum - c2k[l,j])

        sol = sympy.solve(eqns, omega)

        if min(sol.values()) < 0:
            split.append(True)
        else:
            split.append(False)

        for r in range(k):
            if split[-1]:
                w  = sol[omega[r]]
                wp = (w + 3*abs(w))/2
                wm = wp - w
                varpi.append((wp, wm))
            else:
                varpi.append(sol[omega[r]])

    varpi = np.array(varpi, dtype=object)
    split = np.array(split)

    if n == 1:
        return (varpi, split)

    return (np.reshape(varpi, (n, k)), split)



######################################################################

def jiang_shu_smoothness_coefficients(k, uniform=True, boundaries=None):
    r"""Compute the Jiang-Shu smoothness coefficients for a 2k-1 order
        WENO scheme.

        The coefficients are stored as SymPy variables in an array
        indexed according to ``beta[r,m,n]``.  That is

        .. math::

          \sigma^r = \sum_{m=1}^{2k-1} \sum_{n=1}^{2k-1} \beta_{r,m,n}\, \overline{f}_{i-k+m}\, \overline{f}_{i-k+n}.

        """

    i = k-1
    (x, dx) = sympy.var('x dx')
    xi = sympy.var('x')

    # build array of cell boundaries (sympy vars x[i])
    xs = []
    if uniform:
        for j in range(-k+1, k+1):
            xs.append(j*dx)
    else:
        if boundaries is not None:
            if len(boundaries) != 2*k:
                raise ValueError, 'the length of the boundaries array should be 2*k'
            for j in range(2*k):
                xs.append(boundaries[j] - boundaries[0])
        else:
            warnings.warn('Computing arbitrary non-uniform Jiang-Shu smoothness coefficients is extremely slow.')
            for j in range(-k+1, k+1):
                xs.append(sympy.var('x[i%+d]' % j))

    # build array of cell averages (sympy vars f[i])
    fs = []
    for j in range(-k+1, k):
        fs.append(sympy.var('f[i%+d]' % j))


    # compute reconstruction coefficients for each left shift r
    beta = np.zeros((k,2*k-1,2*k-1), dtype=np.dtype(object))

    for r in range(0, k):
        p = primitive_polynomial_interpolator(xs[i-r:i-r+k+1],
                                              fs[i-r:i-r+k]).diff(x)

        # sum of L^2 norms of derivatives
        s = 0
        for j in range(1, k):
            pp = (sympy.diff(p, xi, j))**2
            pp = pp.as_poly(x)
            pp = pp.integrate(x)
            pp = pp.as_basic()
            pp = (xs[i+1] - xs[i])**(2*j-1) * (
                pp.subs(x, xs[i+1]) - pp.subs(x, xs[i]) )
            s = s + pp

        # pick out coefficients
        for m in range(2*k-1):
            for n in range(m, 2*k-1):
                c = s.coeff(fs[m]*fs[n])
                if c is not None:
                    beta[r,m,n] = c

    return beta
