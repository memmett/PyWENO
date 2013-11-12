"""
PyWENO non-uniform reconstruction code generation routines

Original code written by Matthew Emmett as part of PyWENO.
Edited by Ben Thompson.

To generate a new fortran module for weno reconstruction of order k, run:

create_fncs(k)
"""
import sys
import os
import subprocess
import sympy
from pyweno.nonuniform import coeffs_fnc_name, smoothness_fnc_name


def polynomial_interpolator(x, y):
    """Build a symbolic polynomial that interpolates the points (x_i, y_i).

    The returned polynomial is a function of the SymPy variable x.
    """
    k, xi = len(x), sympy.var('x')
    sum_i = 0
    for i in range(k):
        ns = range(k)
        ns.remove(i)

        num, den = 1, 1
        for n in ns:
            num *= xi - x[n]
            den *= x[i] - x[n]

        sum_i += num / den * y[i]

    return sum_i


def primitive_polynomial_interpolator(x, y):
    """Build a symbolic polynomial that approximates the primitive
    function f such that f(x_i) = sum_j y_j * (x_{j+1} - x_{j}).

    Note: The x argument should be list that is one element longer
    than the y list.

    The returned polynomial is a function of the SymPy variable 'x'.
    """

    Y = [0]
    for i in range(len(y)):
        Y.append(Y[-1] + (x[i + 1] - x[i]) * y[i])

    return polynomial_interpolator(x, Y)


def _pt(a, b, x):
    """Map x in [-1, 1] to x in [a, b]."""
    half = sympy.sympify(1.0 / 2.0)
    w = half * (b - a)
    c = half * (a + b)

    return w * x + c


def coeffs(k, d, offset):
    # build arrays of cell boundaries and cell averages
    xs = [sympy.var('x%d' % j) for j in range(offset, k + offset + 1)]
    ys = [sympy.var('f%d' % j) for j in range(offset, k + offset)]

    x = sympy.var('x')

    # Interpolate the polynomial
    poly = primitive_polynomial_interpolator(xs, ys).diff(x, d + 1)
    return poly


def smoothness(k, offset):
    """
    Compute the Jiang-Shu smoothness coefficient functions and output them in a form ready
    to be compiled to fortran.
    """

    # the integration variable (represents position within the cell)
    x = sympy.var('x')

    # build array of cell boundaries and cell averages (sympy vars x[i])
    xs = [sympy.var('x%d' % j) for j in range(offset, k + offset + 1)]
    # and build the array of cell averages
    ys = [sympy.var('y%d' % j) for j in range(offset, k + offset)]

    # The upper and lower boundaries of the cell, used as the integration
    # bounds.
    b1 = sympy.var('x%d' % (k - 1))
    b2 = sympy.var('x%d' % k)

    # Interpolate the polynomial
    p = primitive_polynomial_interpolator(xs, ys)
    p = p.as_poly(x)
    p = p.diff(x)

    ppp = []
        # The smoothness is measured as the sum of L^2 norms of derivatives
    s = 0
    for j in range(1, k):
        pp = (p.diff((0, j))) ** 2
        pp = pp.integrate(x)
        pp = (b2 - b1) ** (2 * j - 1) * (
            pp.subs(x, b2) - pp.subs(x, b1))
        s = s + pp
    ppp = s.as_expr()
    return ppp


def create_fncs(k, force=False):
    args = [sympy.var('x%d' % j) for j in range(0, 2 * k)]
    args.extend([sympy.var('y%d' % j) for j in range(0, 2 * k - 1)])
    args.append(sympy.var('x'))

    fncs = []
    for i in range(0, k):
        for d in range(0, k):
            expr = coeffs(k, d, i)
            fncs.append((args, expr, coeffs_fnc_name(k, d, i)))
        expr = smoothness(k, i)
        fncs.append((args, expr, smoothess_fnc_name(k, i))


if __name__ == "__main__":
    create_fncs(int(sys.argv[1]))
