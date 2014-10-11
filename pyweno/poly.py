"""
Polynomials...

Here we store polynomials as lists of coefficients:

  p(x) = c_0 + c_1 x + c_2 x^2 + ... + c_n x^n

is stored as a list

  p = [ c_0, c_1, ..., c_n ].

"""

from sympy import Rational, Float

# rational coeffs
inv_scale = lambda i: Rational(1,i)

# multi-precision coeffs
#inv_scale = lambda i: Float('1.0')/Float(i)


def poly_add(p1, p2):
    """Return q(x) = p1(x) + p2(x).

    >>> p1 = [ 0, 1, 2 ]
    >>> p2 = [ 1, 1 ]
    >>> poly_add(p1, p2)
    [1, 2, 2]
    >>> poly_add(p2, p1)
    [1, 2, 2]
    """
    if len(p1) < len(p2):
        p1, p2 = p2, p1
    q = list(p1)
    for i in range(len(p2)):
        q[i] += p2[i]
    return q


def poly_scale(a, p):
    """Return q(x) = a p(x).

    >>> poly_scale(2, [ 1, 2, 0, 3 ])
    [2, 4, 0, 6]
    """
    return [ a * e for e in p ]


def poly_legendre(N):
    """Return N'th order Legendre polynomial.

    >>> poly_legendre(2)
    [-1/2, 0, 3/2]
    >>> poly_legendre(3)
    [0, -3/2, 0, 5/2]
    """

    if N == 0:
        return [1]
    if N == 1:
        return [0,1]

    # n P_{n} = (2n - 1) x P_{n-1} - (n-1) P_{n-2}
    pn2 = [1]
    pn1 = [0,1]
    for n in range(2, N+1):
        p1 = [0] + poly_scale(2*n-1, pn1)
        p2 = poly_scale(-n+1, pn2)
        p  = poly_scale(inv_scale(n), poly_add(p1, p2))
        pn2 = pn1
        pn1 = p
    return p


def poly_eval(x, p):
    """Evaluate p(x).

    >>> poly_eval(-1, [-1, 0, 1])
    0
    >>> poly_eval(1.0, [1, 3, 1])
    5.0
    """
    v = p[-1]
    for j in range(2,len(p)+1):
        v = x * v + p[-j]
    return v


def poly_diff(p):
    """Return q(x) = p'(x).

    >>> poly_diff([1, 1, 1])
    [1, 2]
    """
    return [ i * p[i] for i in range(1, len(p)) ]


def poly_int(p):
    """Return q(x) = \int p(x).

    >>> poly_int([1, 1, 1])
    [0, 1, 1/2, 1/3]
    """
    return [0] + [ inv_scale(i+1) * p[i] for i in range(len(p)) ]


def poly_from_roots(r):
    """Return p(x) = (x - r[0])*(x - r[1])*...*(x - r[-1])

    >>> poly_from_roots([-1, 1])
    [-1, 0, 1]
    """
    p = [ 1 ]
    for x in r:
        p = poly_add(poly_scale(-x,p), [0] + p)
    return p


def poly_roots(p, niters=20, precision=50, ztol=1.e-20):
    """Return roots of p(x).

    >>> p = [ -1, 0, 1 ]
    >>> poly_roots(p)
    [mpf('-1.0'), mpf('1.0')]
    """

    import mpmath
    from mpmath import workdps, mpf, mpc

    # normalize
    p = poly_scale(inv_scale(p[-1]), p)

    nroots = len(p)-1

    with workdps(precision):

        # initial guess
        z0 = []
        for i in range(nroots):
            z0.append(mpc('0.4', '0.9')**i)

        # durand-kerne-weierstrass iterations
        for k in range(niters):
            for i in range(nroots):
                num = poly_eval(z0[i], p)
                den = 1
                for j in range(nroots):
                    if i != j:
                        den *= z0[i] - z0[j]
                z0[i] -= num/den

    roots = map(lambda x: x.real, z0)

    for i in range(nroots):
        if abs(roots[i]) < ztol:
            roots[i] = 0.0

    return sorted(roots)


# def gauss_radau_nodes(n):
#     p1 = poly_legendre(n)
#     p2 = poly_legendre(n-1)
#     p = poly_add(p1, p2)
#     print p
#     r = poly_roots(p)
#     r = sorted([ -1.0*x for x in r ])
#     return r


if __name__ == '__main__':
    import doctest
    doctest.testmod()
