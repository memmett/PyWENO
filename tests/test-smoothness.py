"""Test smoothness indicators (Jiang Shu)."""

import pyweno.symbolic
import sympy

K = range(3, 4)

exact = {
    3: {
        (0, 1, 1): sympy.sympify('25/3'),
        (2, 1, 1): sympy.sympify('25/3'),
        (0, 0, 2): sympy.sympify('11/3'),
        (2, 2, 2): sympy.sympify('10/3'),
        (0, 1, 2): sympy.sympify('-19/3'),
        (2, 0, 2): sympy.sympify('11/3'),
        (0, 0, 1): sympy.sympify('-31/3'),
        (0, 2, 2): sympy.sympify('4/3'),
        (2, 0, 0): sympy.sympify('4/3'),
        (1, 0, 0): sympy.sympify('4/3'),
        (0, 0, 0): sympy.sympify('10/3'),
        (2, 1, 2): sympy.sympify('-31/3'),
        (2, 0, 1): sympy.sympify('-19/3'),
        (1, 2, 2): sympy.sympify('4/3'),
        (1, 0, 2): sympy.sympify('5/3'),
        (1, 0, 1): sympy.sympify('-13/3'),
        (1, 1, 1): sympy.sympify('13/3'),
        (1, 1, 2): sympy.sympify('-13/3')
        }
    }

######################################################################

def test_smoothness():

    for k in K:
        beta = pyweno.symbolic.jiang_shu_smoothness_coefficients(k)
        print beta
        for key in exact[k]:
            assert(exact[k][key] == beta[key])


######################################################################


if __name__ == '__main__':
    test_smoothness()
