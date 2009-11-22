"""PyWENO smoothness indicators.

"""

import numpy as np
import sympy


def _poly_approximator(k, r, x):
    """Compute symbolic polynomial approximator of order *k* and left
       shift *r* with stencil cell boundaries *x*.
    """

    # define xi
    xi = sympy.var('xi')

    # define x_j and V_j
    f = []
    for j in range(-r, -r+k+1):
        f.append(sympy.var('f_%d' % (j)))

    # build polynomial approximator (see weno.pdf)
    sum_j = 0
    for j in xrange(k):

        sum_l = 0
        for l in xrange(j+1, k+1):

            ms = range(0,k+1)
            ms.remove(l)

            sum_m = 0
            for m in ms:

                ns = range(0,k+1)
                ns.remove(l)
                ns.remove(m)

                prod_n = 1
                for n in ns:
                    prod_n = prod_n * (xi - x[n])

                sum_m = sum_m + prod_n

            prod_m = 1
            for m in ms:
                prod_m = prod_m * (x[l] - x[m])

            sum_l = sum_l + sum_m / prod_m * (x[j+1] - x[j]) * f[j]

        sum_j = sum_j + sum_l

    return sum_j


def _jiang_shu(k, x):
    """Compute symbolic Jiang-Shu smoothness indicators of order *k*
       given the local cell boundaries in *x*.

       Arguments:

         * *k* - order
         * *x* - local cell boundaries

       The local cell boundaries around the cell *i* are
       ``x[i-(k-1):i+k+1]`` where ``x`` contains the global cell
       boundaries.

    """

    xi = sympy.var('xi')

    # compute symbolic smoothness indicators for each left shift
    beta = []
    for r in range(k):

        # compute symbolic polynomial approximator
        p = _poly_approximator(k, r, x[-r+k-1:-r+2*k])

        # sum L^2 norms of derivatives
        s = 0
        for j in range(1, k):
            pp = (x[k] - x[k-1])**(2*j-1) * sympy.integrate((sympy.diff(p, xi, j))**2, (xi, x[k-1], x[k]))
            s = s + pp

        beta.append(s)

    return beta


def beta(smoothness, grid, k, beta):
    """Compute smoothness indicator coefficients and store result in
       *beta*.

       Arguments:

         * *smoothness* - smoothness indicator type
         * *grid* - grid (can be unstructured)
         * *k* - order

       In general, the smoothness indicator *sigma* for the cell *i*
       and stencil with left shift *r* is of the form

       .. math::

         \sigma = \sum_{m=1}^{2k-1} \sum_{n=1}^{2k-1} \\beta_{i,r,m,n} \overline{f}_{i-k+m}\, \overline{f}_{i-k+n}

       The smoothness indicator type can be one of:

         * ``'jiang_shu'``

    """

    N = grid.size

    if smoothness == 'jiang_shu':
        _sigma = _jiang_shu
    else:
        raise NotImplemented, "smoothness indicator '%s' not implemented yet" % (smoothness)

    f = []
    for j in range(-(k-1), k+1):
        f.append(sympy.var('f_%d' % (j)))

    if grid.structured:

        sigma = _sigma(k, grid.x[0:2*k+1])

        for r, s in enumerate(sigma):
            for m in range(2*k):
                for n in range(m, 2*k):
                    c = s.coeff(f[m]*f[n])
                    if c is not None:
                        beta[k,r,m,n] = c

        for i in range(k+1, N-k-1):
            beta[i,:,:,:] = beta[k,:,:,:]

    else:

        for i in range(k, N-k-1):
            sigma = _sigma(k, grid.x[i-(k-1):i+k+1])

            for r, s in enumerate(sigma):
                for m in range(2*k):
                    for n in range(m, 2*k):
                        c = s.coeff(f[m]*f[n])
                        if c is not None:
                            beta[i,r,m,n] = c



if __name__ == '__main__':
    import pyweno.grid
    import numpy as np

    x = np.linspace(-10.0, 10.0, 21)
    grid = pyweno.grid.Grid(x)

    N = grid.size
    k = 3
    b = np.zeros((N,k,2*k-1,2*k-1))

    beta('jiang_shu', grid, k, b)
    print b[k,:,:,:]
