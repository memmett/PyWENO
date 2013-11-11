"""
PyWENO non-uniform reconstruction routines.

Original code written by Matthew Emmett as part of PyWENO.
Edited by Ben Thompson.
"""
import os
import subprocess
import sympy
from sympy.utilities.codegen import codegen
from sympy.core.cache import clear_cache
from pyweno.nonuniform import smoothness_fnc_name, coeffs_fnc_name


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


def coeffs(k, d):
    # build arrays of cell boundaries and cell averages
    xs = [sympy.var('x%d' % j) for j in range(k + 1)]
    fs = [sympy.var('f%d' % j) for j in range(k)]

    x = sympy.var('x')
    # z = _pt(xs[k - 1], xs[k], x)

    # compute reconstruction coefficients for each left shift r
    # Interpolate the polynomial
    poly = primitive_polynomial_interpolator(xs, fs).diff(x, d + 1)
    # We have to do .simplify().expand() in order to get the proper symbolic
    # coefficients
    poly = poly.simplify().expand()
    for j in range(k):
        args = xs[:]
        args.append(x)
        fnc = poly.coeff(fs[j]).simplify()
        fnc_name = coeffs_fnc_name(k, d, j)
        save_fnc(k, fnc, fnc_name, args)




def smoothness(k):
    """
    Compute the Jiang-Shu smoothness coefficient functions and output them in a form ready
    to be compiled to fortran.
    """

    # the integration variable (represents position within the cell)
    x = sympy.var('x')

    # build array of cell boundaries and cell averages (sympy vars x[i])
    xs = []
    for j in range(k + 1):
        xs.append(sympy.var('x%d' % j))
    # and build the array of cell averages
    ys = []
    for j in range(k):
        ys.append(sympy.var('y%d' % j))

    # The upper and lower boundaries of the cell, used as the integration
    # bounds.
    b1 = sympy.var('b1')
    b2 = sympy.var('b2')

    # Interpolate the polynomial
    p = primitive_polynomial_interpolator(xs, ys)
    p = p.as_poly(x)
    p = p.diff(x)

    ppp = []
    for r in range(0, k):
        # The smoothness is measured as the sum of L^2 norms of derivatives
        s = 0
        for j in range(1, k):
            pp = (p.diff((0, j))) ** 2
            pp = pp.integrate(x)
            pp = (b2 - b1) ** (2 * j - 1) * (
                pp.subs(x, b2) - pp.subs(x, b1))
            s = s + pp
        # We have to do .simplify().expand() in order to get the proper
        # symbolic coefficients
        ppp.append(s.simplify().expand())

    # Saves functions and arguments in a form ready to be compiled to fortran
    # expressions that can be called from the live code.
    for r in range(0, k):
        for i in range(0, k):
            for j in range(0, k):
                args = [xs[m] for m in range(0, k + 1)]
                # I suspect that I could carefully redesign this so that
                # b1 and b2 would be drawn from the xs array
                args.append(b1)
                args.append(b2)
                fnc = ppp[r].coeff(ys[i] * ys[j]).simplify()
                fnc_name = smoothness_fnc_name(k, r, i, j)
                save_fnc(k, fnc, fnc_name, args)


def save_fnc(k, fnc, fnc_name, args):
    # Build the code using the sympy codegen module
    code = codegen((fnc_name, fnc), "F95", "autoweno",
                   argument_sequence=args)
    filename_prefix = get_filename_prefix(k)
    source_file = filename_prefix + '.f90'
    # Save it to the proper file.
    with open(source_file, 'a') as ff:
        ff.write(code[0][1])
    # Clear the sympy cache so that we don't completely fill up RAM.
    clear_cache()


def get_filename_prefix(k):
    root = os.path.dirname(os.path.abspath(__file__))
    return os.path.join(root, 'nonuniform_weno_' + str(k))


def create_fncs(k, force=False):
    """
    This function uses the sympy autowrap module to create fortran functions
    with f2py. It is massively faster at runtime than directly calling the
    sympy functions using subs. As a tradeoff, this takes a long time
    to generate the fortran functions (sympy can be slow!).

    Note: if the library already exists, this will do nothing. Delete the
    weno_k.so file to rebuild it.
    """
    filename_prefix = get_filename_prefix(k)
    source_file = filename_prefix + '.f90'

    # Check if the library already exists.
    if (not force) and os.path.exists(filename_prefix + '.so'):
        return

    # Delete the old source
    if os.path.exists(source_file):
        os.remove(source_file)

    # Build the new source
    for d in range(0, 1):
        coeffs(k, d)
    # smoothness(k)
    # Compile!
    subprocess.call('f2py -c ' + source_file + ' -m ' + filename_prefix,
                    shell=True)
    # Test the module
    module = __import__(filename_prefix)
    assert(module)


def create_standard():
    create_fncs(3)
    # create_fncs(5)

if __name__ == "__main__":
    create_standard()
