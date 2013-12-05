"""
PyWENO non-uniform reconstruction routines.

Original code written by Matthew Emmett as part of PyWENO.
Edited by Ben Thompson.
"""

import numpy as np


def coefficients(k, xi, x):
    """Numerically compute reconstruction and smoothness coefficients.

    This wraps the "symbolic" C routines in the cnonuniform extension
    module.

    XXX: Need to implement: higher derivatives, optimal weights.

    XXX: When the above are done, can probably replace all nonuniform
    stuff below with this routine.
    """

    import pyweno.cnonuniform

    x  = np.asarray(x,  np.float64)
    xi = np.asarray(xi, np.float64)

    nc = len(x) - 1
    n  = len(xi)
    c     = np.zeros((nc, n, k, k), np.float64)
    beta  = np.zeros((nc, k, k, k), np.float64)
    varpi = np.zeros((nc, n, k), np.float64)

    pyweno.cnonuniform.nonuniform_coeffs(k, xi, x, c, beta, varpi)

    return c, beta, varpi



def smoothness_fnc_name(k, r, i, j):
    """
    Arguments:
        :param k: The order of the polynomial reconstruction.
        :param i: The first dimension of the smoothness kernel position.
        :param j: The second dimension of the smoothness kernel position.
    """
    return 'smoothness_' + str(k) + '_' + str(r) + '_' + str(i) + '_' + str(j)


def coeffs_fnc_name(k, d, j):
    return 'reconstruction_coeffs_' + str(k) + '_' + str(d) + '_' + str(j)


def call_coeffs(k, d, j, args):
    fnc_name = coeffs_fnc_name(k, d, j)
    return get_weno(k).__dict__[fnc_name](*args)


def reconstruction_coefficients(k, xi, x, d=0):
    r"""Numerically compute the reconstruction coefficients for a 2k-1
    order WENO scheme corresponding to the reconstruction points in *xi*
    on the non-uniform grid *x*.

    The reconstruction points in *xi* should be in :math:`[-1, 1]`.  This
    interval is then mapped to the cell :math:`[x_{i-1/2}, x_{i+1/2}]`.

    :param xi: list of reconstruction points
    :param k: reconstruction order
    :param x: cell boundaries

    The returned coefficients are stored in a NumPy array that is
    indexed according to ``c[i,l,r,j]``.  That is

    .. math::

        f^r(\xi_l) \approx \sum_j c^{l,r}_{i,j} \, f_{i-r+j}

    for each :math:`l` from 0 to ``len(xi)``.

    """
    X = np.array(x)
    N = len(X) - 1
    n = len(xi)

    c = np.zeros((N, n, k, k))       # indexed as c[i,l,r,j]

    args = np.zeros(k + 2)
    for i in range(k - 1, N - k + 1):
        for l in range(n):
            for r in range(k):
                args[0:k + 1] = X[i - r:i - r + k + 1]
                # Map the point under consideration back into original
                # spatial domain, then subtract X[i - r] to get into
                # near-zero coordinates for floating point happiness
                z = 0.5 * (X[i] + X[i + 1]) - X[i - r] + \
                    0.5 * (X[i + 1] - X[i]) * xi[l]
                args[k + 1] = z
                for j in range(k):
                    val = call_coeffs(k, d, j, args)
                    c[i, l, r, j] = val
    return c


def optimal_weights(k, xi, x, tolerance=1e-12):
    r"""Compute the optimal weights for a 2k-1 order WENO scheme
    corresponding to the reconstruction points in *xi* on the
    non-uniform grid *x*.

    The coefficients are stored in a NumPy array that is indexed
    according to ``w[i,l,r]``.  That is

    .. math::

        f(\xi^l) \approx \sum_r w^r f^r

    for each :math:`l` from 0 to ``len(xi)``.
    """

    X = np.array(x)
    n = len(xi)
    N = len(X) - 1

    c = reconstruction_coefficients(k, xi, X)

    # add on a periodic extension...
    X2 = np.zeros(N + 2 * (k) + 1, X.dtype)
    X2[k:-k] = X
    X2[:k] = X[0] - (X[-1] - X[-k - 1:-1])
    X2[-k:] = X[-1] + (X[1:k + 1] - X[0])
    c2k = reconstruction_coefficients(2 * k - 1, xi, X2)

    # chop off the extra bits
    c2k = c2k[k:-k, ...]

    varpi = np.zeros((N, n, k))
    for i in range(k - 1, N - k + 1):
        for l in range(n):

            # we'll just use the first k eqns since the system is
            # overdetermine
            omega = {}
            for j in range(k):

                rmin = max(0, (k - 1) - j)
                rmax = min(k - 1, 2 * (k - 1) - j)

                accum = 0.0
                for r in range(rmin + 1, rmax + 1):
                    accum = accum + omega[r] * c[i, l, r, r - (k - 1) + j]

                omega[rmin] = (c2k[i, l, k - 1, j] - accum) / c[
                    i, l, rmin, rmin - (k - 1) + j]

            # now check all 2*k-1 eqns to make sure the weights
            # work out properly
            for r in range(k):
                varpi[i, l, r] = omega[r]

    return varpi


def call_smoothness(k, r, i, j, args):
    fnc_name = smoothness_fnc_name(k, r, i, j)
    return get_weno(k).__dict__[fnc_name](*args)


def jiang_shu_smoothness_coefficients(k, x):
    r"""Compute the Jiang-Shu smoothness coefficients for a 2k-1 order
    WENO scheme on the non-uniform grid *x*.

    The coefficients are stored in a NumPy array indexed according to
    ``beta[i,r,m,n]``.  That is

    .. math::

        \sigma^r = \sum_{m=1}^{2k-1} \sum_{n=1}^{2k-1}
            \beta_{r,m,n}\, \overline{f}_{i-k+m}\, \overline{f}_{i-k+n}.
    """

    X = np.array(x)
    N = len(X) - 1

    # compute reconstruction coefficients for each left shift r
    beta = np.zeros((N, k, k, k))
    for i in range(k - 1, N - k + 1):
        for r in range(0, k):
            args = []
            for j in range(0, k + 1):
                args.append([X[i - r + j]])
            args.append([X[i]])
            args.append([X[i + 1]])
            # pick out coefficients
            for m in range(k):
                for n in range(m, k):
                    c = call_smoothness(k, r, m, n, args)
                    if c is not None:
                        beta[i, r, m, n] = float(c)
    return beta

wenos = dict()


def get_weno(k):
    try:
        name = 'pyweno.nonuniform_weno_' + str(k)
        if name in wenos:
            wenok = wenos[name]
        else:
            wenok = __import__(name).__dict__['nonuniform_weno_' + str(k)]
        wenos[name] = wenok
        return wenok
    except ImportError as e:
        raise Exception("Nonuniform WENO library file does not exist. "
                        "Please run 'python src/nonuniform_codegen.py' "
                        "from the pyweno source directory (Original Exception: "
                        + str(e) + ")")
