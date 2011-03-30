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

   If *function* is ``None`` or ``False``, inlined code is returned.
   In this case, the various results are stored in the variables named
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
import pyweno.code

from pyweno.code import src


class OpenCLCodeGenerator(pyweno.code.CodeGenerator):


    def __init__(self, **kwargs):

        pyweno.code.CodeGenerator.__init__(self, **kwargs)

        self.wrappers = []


    def uniform_smoothness(self, function='smoothness', **kwargs):
        """Uniform smoothness function."""

        k = self.k

        s = src()
        if function:
            s.add('''__kernel void {function}(__global const float *f, int fsi,
                                              __global const float *sigma, int ssi, int ssr
                                             ) {{
                       int i = get_global_id(0);''')

            s.add('float ' + ', '.join(self.sigma) + ';')

        s.add(pyweno.code.CodeGenerator.uniform_smoothness(self))

        if function:
            for r in range(k):
                s.add('sigma[i*ssi+{r}*ssr] = {sigma};',
                      r = r,
                      sigma = self.sigma[r])

            s.add('}}\n')

        return s.src(function=function)


    def uniform_weights(self, function='weights', **kwargs):
        """Uniform weights function."""

        k = self.k
        n = self.n

        s = src()
        if function:
            s.add('''__kernel void {function}(__global const float *sigma, int ssi, int ssr,
                                              __global const float *omega, int wsi, int wsl, int wsr)
                                             ) {{
                       int i = get_global_id(0);''')

        s.add(pyweno.code.CodeGenerator.uniform_weights(self))
        s.add(self.set_omegas())

        if function:
            s.add('}}\n\n')

        return s.src(function=function)


    def uniform_reconstruction(self,
                               function='reconstruct',
                               fr='fr[i*frsi + X*frsl]',
                               **kwargs):
        """Uniform reconstruction function."""

        k = self.k
        n = self.n

        s = src()
        if function:
            s.add('''__kernel void {function}(__global const float *f, int fsi,
                                              __global const float *omega, int wsi, int wsl, int wsr,
                                              __global float *fr, int frsi, int frsl)
                                             ) {{
                       int i = get_global_id(0);''')

        s.add(pyweno.code.CodeGenerator.uniform_reconstruction(
            self, fr=fr))

        if function:
            s.add('}}')

        return s.src(function=function)



# ######################################################################
# # kernels
# #

# def uniform_smoothness_kernel(k, beta,
#                               function='smoothness',
#                               sigma='sigmaX',
#                               **kwargs):
#     r"""Fully un-rolled smoothness indicator kernel for uniform grids.

#        The smoothness indicator kernel computes the smoothness
#        indicators *sigma* determined by the coefficients in *beta*.
#        That is:

#        .. math::

#          \sigma_r = \sum_{m=1}^{2k-1}
#                     \sum_{n=1}^{2k-1}
#                         \beta_{r,m,n}\, \overline{f}_{i-k+m}\,
#                                         \overline{f}_{i-k+n}.

#        Returns: OpenCL source code (as a string).

#     """

#     beta = np.array(beta)

#     if function:
#         src = [
#           """
#           __kernel void %s(function)(__global const float *f,
#                                      __global float *sigma) {
#           int i = get_global_id(0);
#           float accumulator;
#           """ % { 'function': function }
#           ]
#     else:
#         src = []

#     for r in range(0, k):

#         if function:
#             accumulator = 'accumulator'
#         else:
#             accumulator = sigma.replace('X', str(r))

#         src.append('%s = 0.0;' % accumulator)

#         for m in range(k-r-1, 2*k-r-1):
#             for n in range(m, 2*k-r-1):
#                 pm = -(k-1) + m
#                 pn = -(k-1) + n

#                 _beta = _to_string(beta[r,m,n])

#                 src.append('%(accumulator)s += %(beta)s * f[i%(pm)+d] * f[i%(pn)+d];'
#                            % { 'accumulator': accumulator, 'beta': _beta, 'pm': pm, 'pn': pn })

#         if function:
#             src.append('sigma[i*%(ss)d + %(r)d] = accumulator;' % { 'r': r, 'ss': k })

#     if function:
#         src.append('}')

#     return "\n".join(src)


# ######################################################################

# def uniform_weights_kernel(k, varpi, split,
#                            function='weights',
#                            sigma='sigmaX',
#                            omega='omegaX',
#                            scale='scaleX',
#                            **kwargs):
#     r"""Fully un-rolled weights kernel for uniform grids.

#        The weights kernel computes the weights *omega* determined by
#        the smoothness coefficients *sigma* (which have already been
#        computed).

#        If *n*>1 (the number of reconstruction points within each
#        cell), the caller should flatten the appropriate arrays.

#        Returns: OpenCL source code (as a string).

#     """

#     varpi = np.array(varpi)
#     split = np.array(split)

#     if len(varpi.shape) == 1:
#         varpi = np.reshape(varpi, (1, varpi.shape[0]))

#     n = varpi.shape[0]

#     varpi = np.reshape(varpi, (n, k))

#     if function:
#         src = [
#             """
#             __kernel void %(function)s(__global const float *sigma,
#                                        __global float *omega
#                                       ) {
#               int i = get_global_id(0);
#               float accumulator;
#             """ % { 'function': function }
#             ]
#     else:
#         src = []

#     rmin = 0                    # max(0, i-(N-k))
#     rmax = k                    # min(k-1, i)

#     for l in range(n):
#         if not split[l]:
#             src.append('accumulator = 0.0;')

#             for r in range(rmin, rmax):

#                 if function:
#                     _sigma = 'sigma[i*%(k)d + %(r)d]' % { 'k': k, 'r': r };
#                     _omega = 'omega[i*%(is)d + %(r)d]' % { 'is': n*k, 'r': l*k + r }
#                 else:
#                     _sigma = sigma.replace('X', str(r))
#                     _omega = omega.replace('X', str(l*k+r))

#                 _varpi = _to_string(varpi[l,r])

#                 src.append('%s = %s / (10e-6 + %s) / (10e-6 + %s);' % (_omega, _varpi, _sigma, _sigma))
#                 src.append('accumulator += %s;' % _omega)


#             for r in range(rmin, rmax):

#                 if function:
#                     _omega = 'omega[i*%(is)d + %(r)d]' % { 'is': n*k, 'r': l*k + r }
#                 else:
#                     _omega = omega.replace('X', str(l*k+r))

#                 src.append('%s /= accumulator;' % _omega)

#         else:

#             for s, pm in enumerate(('p', 'm')):
#                 src.append('accumulator = 0.0;')

#                 _scale = scale.replace('X', str(l) + pm)
#                 accum = 0.0
#                 for r in range(rmin, rmax):
#                     accum += varpi[l,r][s]
#                 src.append('%s = %s;' % (_scale, _to_string(accum)))

#                 for r in range(rmin, rmax):

#                     _sigma = sigma.replace('X', str(r))
#                     _omega = omega.replace('X', str(l*k+r) + pm)

#                     _varpi = _to_string(varpi[l,r][s])

#                     src.append('%s = %s / %s / (10e-6 + %s) / (10e-6 + %s);' % (_omega, _varpi, _scale, _sigma, _sigma))
#                     src.append('accumulator += %s;' % _omega)



#                 for r in range(rmin, rmax):

#                     _omega = omega.replace('X', str(l*k+r) + pm)

#                     src.append('%s /= accumulator;' % _omega)

#     if function:
#         src.append('}')

#     return "\n".join(src)


# ######################################################################

# def uniform_reconstruction_kernel(k, coeffs, split,
#                                   function='reconstruct',
#                                   omega='omegaX',
#                                   scale='scaleX',
#                                   fr='fX',
#                                   rf='rf[X]',
#                                   **kwargs):
#     """Fully un-rolled reconstruction kernel for uniform grids.

#        If *n*>1 (the number of reconstruction points within each
#        cell), the caller should flatten the appropriate arrays.

#        Returns: OpenCL source code (as a string).

#     """

#     coeffs = np.array(coeffs)

#     if len(coeffs.shape) == 2:
#         coeffs = np.reshape(coeffs, (coeffs.shape[0], 1, coeffs.shape[1]))

#     n = coeffs.shape[1]

#     if function:
#         src = [
#             """
#             __kernel void %(function)s(__global const float *f,
#                                        __global const float *omega,
#                                        __global float *rf
#                                       ) {
#               int i = get_global_id(0);
#             """ % { 'function': function }
#             ]

#         variables = []
#         for l in range(n):
#             for r in range(k):
#                 variables.append(fr.replace('X', str(l*k+r)))
#         src.append('float ' + ', '.join(variables) + ';')
#     else:
#         src = []

#     # reconstructions
#     for l in range(n):

#         for r in range(k):
#             _f = fr.replace('X', str(l*k+r))

#             reconstruction = []
#             for j in range(k):
#                 _coeff = _to_string(coeffs[l,r,j])
#                 reconstruction.append('%s * f[i%+d]' % (_coeff, -r+j))

#             src.append(_f + ' = ' + ' + '.join(reconstruction) + ';')


#     # weighted reconstruction
#     for l in range(n):

#         if not split[l]:

#             reconstruction = []
#             for r in range(k):
#                 _f = fr.replace('X', str(l*k+r))
#                 _omega = omega.replace('X', str(r))

#                 reconstruction.append('%s * %s' % (_f, _omega))

#             if n > 1:
#                 _rf = rf.replace('X', 'i*%d+%d' % (n, l))
#             else:
#                 _rf = rf.replace('X', 'i')

#             src.append(_rf + ' = ' + ' + '.join(reconstruction) + ';')

#         else:

#             reconstruction = []
#             for s, pm in enumerate(('p', 'm')):
#                 _scale = scale.replace('X', str(l) + pm)

#                 pm_reconstruction = []
#                 for r in range(k):
#                     _f = fr.replace('X', str(l*k+r))
#                     _omega = omega.replace('X', str(l*k+r) + pm)

#                     pm_reconstruction.append('%s * %s' % (_f, _omega))

#                 reconstruction.append(('%s * (' % _scale)
#                                       + ' + '.join(pm_reconstruction)
#                                       + ')')

#             if n > 1:
#                 _rf = rf.replace('X', 'i*%d+%d' % (n, l))
#             else:
#                 _rf = rf.replace('X', 'i')

#             src.append(_rf + ' = ' + ' + '.join(reconstruction) + ';')


#     if function:
#         src.append('}')

#     return "\n".join(src)






# # ######################################################################

# # def nonuniform_smoothness_kernel(N, k):
# #     """Fully un-rolled smoothness kernel for non-uniform grids.
# #     """

# #     src = [r"""
# #       __kernel void smoothness(__global const float *f,
# #                                __global const float *beta,
# #                                __global float *sigma) {
# #       int i = get_global_id(0);
# #       float sum;"""]

# #     # strides
# #     sr = (2*k-1) * (2*k-1)      # beta: r stride
# #     sm = (2*k-1)                # beta: m stride
# #     ss = k                      # sigma: i stride

# #     for r in range(0, k):
# #         src.append('sum = 0.0;')

# #         for m in range(k-r-1, 2*k-r-1):
# #             for n in range(m, 2*k-r-1):
# #                 pm = -(k-1) + m
# #                 pn = -(k-1) + n
# #                 src.append('''sum += beta[%(r)d*%(sr)d + %(m)d*%(sm)d + %(n)d]
# #                                        * f[i%(pm)+d] * f[i%(pn)+d];'''
# #                            % { 'r': r, 'k': k, 'm': m, 'n': n,
# #                                'pm': pm, 'pn': pn, 'sr': sr, 'sm': sm })

# #         src.append('sigma[i*%(ss)d + %(r)d] = sum;' % {'r': r, 'ss': ss })

# #     src.append('}')
# #     return "\n".join(src)
