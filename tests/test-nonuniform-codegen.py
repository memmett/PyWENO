import sympy
from pyweno.nonuniform_codegen import polynomial_interpolator, smoothness
from pyweno.nonuniform_codegen import primitive_polynomial_interpolator, _pt, coeffs


def test_polynomial_interpolator():
    x = [1.0, 2.0, 3.0]
    y = [2.0, 1.0, 2.0]
    p = polynomial_interpolator(x, y)
    x = sympy.var('x')
    assert(p.subs(x, 1.0) == 2.0)
    assert(p.subs(x, 2.0) == 1.0)
    assert(p.subs(x, 3.0) == 2.0)
    # polynomial should be a quadratic (x-1)**2
    assert(p.subs(x, 4.0) == 5.0)


def test_prim_polynomial_interpolator():
    x = [1.0, 2.0, 3.0]
    y = [2.0, 1.0]
    p = primitive_polynomial_interpolator(x, y)
    x = sympy.var('x')
    assert(p.subs(x, 1.0) == 0.0)
    assert(p.subs(x, 2.0) == 2.0)
    assert(p.subs(x, 3.0) == 3.0)
    assert(p.subs(x, 4.0) == 3.0)


def test_pt():
    assert(_pt(-2.0, 0.0, 0.5) == -0.5)
    assert(_pt(0.0, 3.0, 0.3) == 1.95)
    assert(_pt(-3.0, 1.0, 0.0) == -1.0)
    assert(_pt(-3.0, 1.0, 0.0) == -1.0)
    x = sympy.var('x')
    a = sympy.var('a')
    assert(_pt(a, 0, x) == 0.5 * (-a * x + a))


# These two tests actually generate the source. They take a long time.
# so only run them if necessary.
# def test_reconstruction_coeffs_gen():
#     result = coeffs(3, 0)
#     assert(len(result) == 3)
#     assert(result[0][0] != 0)
#     assert(result[1][2].count(sympy.var('x1')) == 1)
#     result2 = coeffs(3, 2)
#     assert(result2)
#     pass  # how to test code generation? probably just wait until we get the results
#
#
# def test_jiang_shu_smoothness_create():
#     assert(smoothness(3))
