"""(Py)WENO OpenCL kernels.

   The routines throughout this module are designed to generate OpenCL
   code for use in specialized applications.

   Each function generates either: a stand-alone OpenCL kernel or
   inlined OpenCL code.  Whether a kernel or inlined code is returned
   depends on the value of the keyword argument *function*.

   If *function* is a string, the code for a standalone kernel is
   returned.  Furthermore, the kernel is named according to the value
   of *function*, which defaults to, eg, ``smoothness`` ``weights``,
   etc.

   If *function* is ``None`` or ``False``, inlined code returned.  In
   this case, the various results are stored in the variables named
   according to:

   * smoothness indicators: *sigma*, default ``sigmaX``
   * weights:               *omega*, default ``omegaX``

   in which the occurance of ``X`` is replaced by the left-shift *r*.
   For example, for ``k=3`` and ``omega='omegaX'``, the weights are
   stored in ``omega0``, ``omega1``, and ``omega2``, each of which are
   assumed to be in scope.  Finally, in some routines the the
   accumulator variable ``float accumulator`` is also assumed to be in
   scope.

"""

import numpy as np


######################################################################
# helpers
#

def _to_string(coeff):
    """Return a string representation of *coeff*."""

    if isinstance(coeff, str):
        return coeff

    if isinstance(coeff, float):
        return "%.15g" % coeff

    try:
        coeff = coeff.evalf()
        return "%.15g" % coeff
    except:
        pass

    return str(coeff)


######################################################################
# kernels
#

def uniform_smoothness_kernel(k, beta,
                              function='smoothness',
                              sigma='sigmaX',
                              **kwargs):
    r"""Fully un-rolled smoothness indicator kernel for uniform grids.

       The smoothness indicator kernel computes the smoothness
       indicators *sigma* determined by the coefficients in *beta*.
       That is:

       .. math::

         \sigma_r = \sum_{m=1}^{2k-1}
                    \sum_{n=1}^{2k-1}
                        \beta_{r,m,n}\, \overline{f}_{i-k+m}\,
                                        \overline{f}_{i-k+n}.

       Returns: OpenCL source code (as a string).

    """

    beta = np.array(beta)

    if function:
        src = [
          """
          __kernel void %s(function)(__global const float *f,
                                     __global float *sigma) {
          int i = get_global_id(0);
          float accumulator;
          """ % { 'function': function }
          ]
    else:
        src = []

    for r in range(0, k):

        if function:
            accumulator = 'accumulator'
        else:
            accumulator = sigma.replace('X', str(r))

        src.append('%s = 0.0;' % accumulator)

        for m in range(k-r-1, 2*k-r-1):
            for n in range(m, 2*k-r-1):
                pm = -(k-1) + m
                pn = -(k-1) + n

                _beta = _to_string(beta[r,m,n])

                src.append('%(accumulator)s += %(beta)s * f[i%(pm)+d] * f[i%(pn)+d];'
                           % { 'accumulator': accumulator, 'beta': _beta, 'pm': pm, 'pn': pn })

        if function:
            src.append('sigma[i*%(ss)d + %(r)d] = accumulator;' % { 'r': r, 'ss': k })

    if function:
        src.append('}')

    return "\n".join(src)


######################################################################

def uniform_weights_kernel(k, varpi, n=1,
                           function='weights',
                           sigma='sigmaX',
                           omega='omegaX',
                           **kwargs):
    r"""Fully un-rolled weights kernel for uniform grids.

       The weights kernel computes the weights *omega* determined by
       the smoothness coefficients *sigma* (which have already been
       computed).

       If *n*>1 (the number of reconstruction points within each
       cell), the caller should flatten the appropriate arrays.

       Returns: OpenCL source code (as a string).

    """

    varpi = np.array(varpi)

    if function:
        src = [
            """
            __kernel void %(function)s(__global const float *sigma,
                                       __global float *omega
                                      ) {
              int i = get_global_id(0);
              float accumulator;
            """ % { 'function': function }
            ]
    else:
        src = []

    rmin = 0                    # max(0, i-(N-k))
    rmax = k                    # min(k-1, i)

    for l in range(n):
        src.append('accumulator = 0.0;')

        for r in range(rmin, rmax):

            if function:
                _sigma = 'sigma[i*%(k)d + %(r)d]' % { 'k': k, 'r': r };
                _omega = 'omega[i*%(is)d + %(r)d]' % { 'is': n*k, 'r': l*k + r }
            else:
                _sigma = sigma.replace('X', str(r))
                _omega = omega.replace('X', str(r))

            _varpi = _to_string(varpi[r])

            src.append('%s = %s / (10e-6 + %s) / (10e-6 + %s);' % (_omega, _varpi, _sigma, _sigma))
            src.append('accumulator += %s;' % _omega)

        for r in range(rmin, rmax):

            if function:
                _omega = 'omega[i*%(is)d + %(r)d]' % { 'is': n*k, 'r': l*k + r }
            else:
                _omega = omega.replace('X', str(r))

            src.append('%s /= accumulator;' % _omega)

    if function:
        src.append('}')

    return "\n".join(src)


######################################################################

def uniform_reconstruction_kernel(k, coeffs, n=1,
                                  function='reconstruct',
                                  omega='omegaX',
                                  fr='fX',
                                  rf='rf[i]',
                                  **kwargs):
    """Fully un-rolled reconstruction kernel for uniform grids.

       If *n*>1 (the number of reconstruction points within each
       cell), the caller should flatten the appropriate arrays.

       Returns: OpenCL source code (as a string).

    """

    coeffs = np.array(coeffs)

    if function:
        src = [
            """
            __kernel void %(function)s(__global const float *f,
                                       __global const float *omega,
                                       __global float *rf
                                      ) {
              int i = get_global_id(0);
            """ % { 'function': function }
            ]

        variables = []
        for r in range(k):
            variables.append(fr.replace('X', str(r)))
        src.append('float ' + ', '.join(variables) + ';')
    else:
        src = []

    # reconstructions
    for r in range(k):
        _f = fr.replace('X', str(r))

        reconstruction = []
        for j in range(k):
            _coeff = _to_string(coeffs[r,j])
            reconstruction.append('%s * f[i%+d]' % (_coeff, -r+j))

        src.append(_f + ' = ' + ' + '.join(reconstruction) + ';')

    # weighted reconstruction
    reconstruction = []
    for r in range(k):
        _f = fr.replace('X', str(r))
        _omega = omega.replace('X', str(r))

        reconstruction.append('%s * %s' % (_f, _omega))

    src.append(rf + ' = ' + ' + '.join(reconstruction) + ';')

    if function:
        src.append('}')

    return "\n".join(src)






# ######################################################################

# def nonuniform_smoothness_kernel(N, k):
#     """Fully un-rolled smoothness kernel for non-uniform grids.
#     """

#     src = [r"""
#       __kernel void smoothness(__global const float *f,
#                                __global const float *beta,
#                                __global float *sigma) {
#       int i = get_global_id(0);
#       float sum;"""]

#     # strides
#     sr = (2*k-1) * (2*k-1)      # beta: r stride
#     sm = (2*k-1)                # beta: m stride
#     ss = k                      # sigma: i stride

#     for r in range(0, k):
#         src.append('sum = 0.0;')

#         for m in range(k-r-1, 2*k-r-1):
#             for n in range(m, 2*k-r-1):
#                 pm = -(k-1) + m
#                 pn = -(k-1) + n
#                 src.append('''sum += beta[%(r)d*%(sr)d + %(m)d*%(sm)d + %(n)d]
#                                        * f[i%(pm)+d] * f[i%(pn)+d];'''
#                            % { 'r': r, 'k': k, 'm': m, 'n': n,
#                                'pm': pm, 'pn': pn, 'sr': sr, 'sm': sm })

#         src.append('sigma[i*%(ss)d + %(r)d] = sum;' % {'r': r, 'ss': ss })

#     src.append('}')
#     return "\n".join(src)
