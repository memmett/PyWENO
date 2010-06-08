"""PyWENO smoothness indicators.

"""

import numpy as np
import sympy


def _poly_approximator(i, r, k, x):
    """Compute symbolic polynomial approximator of order *k* and left
       shift *r* with stencil cell boundaries *x*.
    """

    # define xi
    xi = sympy.var('xi')

    # define f_j
    f = []
    for j in range(-r, -r+k):
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
                    prod_n = prod_n * (xi - x[i-r+n])

                sum_m = sum_m + prod_n

            prod_m = 1
            for m in ms:
                prod_m = prod_m * (x[i-r+l] - x[i-r+m])

            sum_l = sum_l + sum_m / prod_m * (x[i-r+j+1] - x[i-r+j]) * f[j]

        sum_j = sum_j + sum_l

    return sum_j


def _jiang_shu(i, r, k, x):
    """Compute symbolic Jiang-Shu smoothness indicators of order *k*
       given the local cell boundaries in *x*.

       Arguments:

         * *k* - order
         * *x* - cell boundaries

    """

    xi = sympy.var('xi')

    # compute symbolic polynomial approximator
    p = _poly_approximator(i, r, k, x)

    # sum L^2 norms of derivatives
    s = 0
    for j in range(1, k):
        pp = (x[i+1] - x[i])**(2*j-1) * sympy.integrate((sympy.diff(p, xi, j))**2, (xi, x[i], x[i+1]))
        s = s + pp

    return s


def beta(smoothness, grid, k, beta):
    """Compute smoothness indicator coefficients and store result in
       *beta*.

       This function is usually called by the WENO class.

       In general, the smoothness indicator *sigma* for the cell *i*
       and stencil with left shift *r* is of the form

       .. math::

         \sigma_r = \sum_{m=1}^{2k-1} \sum_{n=1}^{2k-1} \\beta_{i,r,m,n}\, \overline{f}_{i-k+m}\, \overline{f}_{i-k+n}.

       There is currently only one smoothness indicator type
       implemented (``'jiang_shu'``).

       **Arguments**

       * *smoothness* - smoothness indicator type
       * *grid* - grid (can be unstructured)
       * *k* - order

    """

    N = grid.size

    if smoothness == 'jiang_shu':
        _sigma = _jiang_shu
    else:
        raise NotImplemented, "smoothness indicator '%s' not implemented yet" % (smoothness)

    f = []
    for j in range(-(k-1), k):
        f.append(sympy.var('f_%d' % (j)))

    if grid.uniform:

        print 'smoothness: uniform grid...'

        for r in range(k):

            # use a simple uniform grid for better results
            s = _sigma(k, r, k, np.linspace(1.0,2*k+1,2*k+1))

            for m in range(2*k-1):
                for n in range(m, 2*k-1):
                    c = s.coeff(f[m]*f[n])
                    if c is not None:
                        beta[k,r,m,n] = c

        print 'smoothness: uniform grid... done.'

        for i in range(0, N):
            beta[i,:,:,:] = beta[k,:,:,:]

    else:

        # XXX: this is (most likely) not reliable...
        raise NotImplemented, 'non-uniform smoothness is implemented but not reliable'

        for i in range(0, N):
            for r in range(max(0,i-(N-k)), min(i,k-1)+1):

                s = _sigma(i, r, k, grid.x)

                for m in range(2*k-1):
                    for n in range(m, 2*k-1):
                        c = s.coeff(f[m]*f[n])
                        if c is not None:
                            beta[i,r,m,n] = c
