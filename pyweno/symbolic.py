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

def primative_polynomial_interpolator(x, y):
    """Build a symbolic polynomial that approximates the primative
       function f such that f(x_i) = sum_j y_j * (x_{j+1} - x_{j}).

       The returned polynomial is a function of the SymPy variable x.
       """

    Y = [0]
    for i in range(0, len(y)):
        Y.append(Y[-1] + (x[i+1] - x[i]) * y[i])

    return polynomial_interpolator(x, Y)


######################################################################

def weno_reconstruction_coefficients(k, xi, uniform=True):
    r"""Compute the reconstruction coefficients for a 2k-1 order WENO
        scheme corresponding to the reconstruction point *xi*.

        The coefficients are stored as SymPy variables in an ndarray
        indexed according to ``c[r,j]``.  That is

        .. math::

          f^r(\xi) \approx \sum_j c^r_j * f_{i-r+j}.


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
    if xi == 'left':
        xi = xs[i]
    elif xi == 'right':
        xi = xs[i+1]
    elif xi == 'gauss_quad3':
        # XXX
        raise NotImplementedError
    else:
        raise ValueError, "reconstruction point '%s' not understood." % str(xi)

    # compute reconstruction coefficients for each left shift r
    c = np.zeros((k,k), dtype=np.dtype(object))

    for r in range(0, k):
        p = primative_polynomial_interpolator(xs[i-r:i-r+k+1], fs[i-r:i-r+k]).diff(x)

        for j in range(0, k):
            c[r,j] = p.subs(x, xi).coeff(fs[i-r+j])

    return c


######################################################################

def jiang_shu_smoothness_coefficients(k, uniform=True, boundaries=None):
    r"""Compute the Jiang-Shu smoothness coefficients for a 2k-1 order
        WENO scheme.

        The coefficients are stored as SymPy variables in an array
        indexed according to ``beta[r][m][n]``.  That is

        .. math::

          \sigma^r = \sum_{m=1}^{2k-1} \sum_{n=1}^{2k-1} \\beta_{i,r,m,n}\, \overline{f}_{i-k+m}\, \overline{f}_{i-k+n}.
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
        p = primative_polynomial_interpolator(xs[i-r:i-r+k+1],
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
