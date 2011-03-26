"""PyWENO code generation module.

   The routines throughout this module are designed to generate C-like
   code for use in specialized applications.

"""

import numpy as np


######################################################################
# helpers

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


def sigma_names(k, base='sigmaX', local=True):
    """Return a list of k sigma names (eg, sigma0, ...)."""

    sigma = []
    for r in range(0, k):
        if local:
            sigma.append(base.replace('X', str(r)))

    return sigma


def omega_names(k, n, split, base='omegaX', local=True):
    """Return a list of k*n omega names (eg, omega0, ...)."""

    omega = []
    for l in range(n):
        if (split is not None) and (not split[l]):
            for r in range(0, k):
                if local:
                    omega.append(base.replace('X', str(l*k+r)))
        else:
            for s, pm in enumerate(('p', 'm')):
                for r in range(0, k):
                    if local:
                        omega.append(base.replace('X', str(l*k+r) + pm))

    return omega


class src(object):
    """Accumulate source code snippets and apply formatting."""

    def __init__(self):

        self.s = []

    def add(self, template, **kwargs):
        """Add a code snippet and apply formatting.

        Formatting is applied only when keyword arguments are passed.
        """

        if kwargs:
            self.s.append(template)
        else:
            self.s.append(template.format(**kwargs))

    def src(self, sep="\n", **kwargs):
        """Return accumulated code and apply formatting.

        Formatting is applied only when keyword arguments are passed.
        """

        s = sep.join(self.s)

        if kwargs:
            return s.format(**kwargs)

        return s


######################################################################
# CodeGenerator

class CodeGenerator(object):
    """Generate C-like code kernels for WENO reconstructions.

    Each method generates a C-like 'kernel' (ie, inlined C code) for a
    specific WENO operation: computing smoothness indicators,
    non-linear weights, and reconstructions.  These code snippets can,
    in-turn, be used to create seperate functions or larger kernels.

    The *basenames* dictionary is used to define naming conventions:

    * smoothness indicators: *sigma*, default ``sigmaX``
    * weights: *omega*, default ``omegaX``
    * intermediate reconstructions: *fr*, default ``frX``.

    For each of the above, the occurance of ``X`` is replaced by the
    left-shift *r*.  For example, for ``k=3`` and ``omega='omegaX'``,
    the weights are stored in ``omega0``, ``omega1``, and ``omega2``,
    each of which are assumed to be in scope.  In some routines the
    accumulator variable ``accumulator`` is also assumed to be in
    scope.

    The *strides* dictionary controls array striding:

    * *f*: cell averaged function value strides, default ``'fsi'``
    * *sigma*: tuple: smoothness indicator strides, default ``('ssi', 'ssr')``
    * *omega*: tuple: weight strides, default ``('wsi', 'wsl', 'wsr')``
    * *fr*: tuple: intermediate reconstruction strides, default ``('frsi', 'frsr')``

    See also: :py:mod:`pyweno.pyweno.c` and
    :py:mod:`pyweno.pyweno.opencl`.

    """

    strides = {
        'f': 'fsi',
        'sigma': ('ssi', 'ssr'),
        'omega': ('wsi', 'wsl', 'wsr'),
        'fr':    ('frsi', 'frsl')
        }

    basenames = {
        'sigma': 'sigmaX',
        'omega': 'omegaX',
        'fr':    'frX',
        }


    def __init__(self, **kwargs):

        self.n = None
        self.k = None


    ##################################################################
    # set methods

    def set_smoothness(self, beta):

        self.beta = np.array(beta)
        self.k    = self.beta.shape[0]

        self.sigma = sigma_names(self.k, self.basenames['sigma'])


    def set_reconstruction_coefficients(self, coeffs):

        if len(coeffs.shape) == 2:
            k = coeffs.shape[0]
            coeffs = np.reshape(coeffs, (1, k, k))

        self.coeffs = np.array(coeffs)

        self.n = coeffs.shape[0]
        self.k = coeffs.shape[1]

        self.fr = omega_names(
            self.k, self.n, self.n*[False], self.basenames['fr'])

    def set_optimal_weights(self, varpi, split):

        varpi  = np.array(varpi)

        if len(varpi.shape) == 1:
            k = varpi.shape[0]
            varpi = np.reshape(varpi, (1, k))

        self.varpi = varpi

        self.n = varpi.shape[0]
        self.k = varpi.shape[1]

        if split is not None:
            self.split = np.array(split)
        else:
            self.split = np.array(self.n*[False])

        self.omega = omega_names(
            self.k, self.n, self.split, self.basenames['omega'])
        self.scale = self.n*[None]

        if np.any(split):
            self.scale = self.n*[None]

            for l in range(self.n):
                if self.split[l]:

                    scale = [0, 0]
                    for s in (0, 1):
                        for r in range(0, self.k):
                            scale[s] += self.varpi[l,r][s]

                        scale[s] = _to_string(scale[s])

                    self.scale[l] = scale


    def uniform_smoothness(self):
        r"""Fully un-rolled smoothness indicator kernel for uniform
        grids.

        The smoothness indicator kernel computes the smoothness
        indicators *sigma* determined by the coefficients in *beta*.
        That is:

        .. math::

          \sigma_r = \sum_{m=1}^{2k-1}
                     \sum_{n=1}^{2k-1}
                         \beta_{r,m,n}\, \overline{f}_{i-k+m}\,
                                         \overline{f}_{i-k+n}.

        Returns: C-like source code (as a string).

        """

        k = self.k

        s = src()
        for r in range(0, k):

            s.add('{sigma} = 0.0;',
                  sigma = self.sigma[r])

            for m in range(k-r-1, 2*k-r-1):
                for n in range(m, 2*k-r-1):
                    pm = -(k-1) + m
                    pn = -(k-1) + n

                    s.add('{sigma} += {beta} * f[(i{pm:+d})*{stride}] * f[(i{pn:+d})*{stride}];',
                          sigma  = self.sigma[r],
                          stride = self.strides['f'],
                          pm     = pm,
                          pn     = pn,
                          beta   = _to_string(self.beta[r,m,n]))

        return s.src()


    ######################################################################

    def uniform_weights(self):
        r"""Fully un-rolled weights kernel for uniform grids.

        The weights kernel computes the weights *omega* determined by
        the smoothness coefficients *sigma* (which have already been
        computed).

        Returns: C-like source code (as a string).

        """

        n = self.n
        k = self.k

        w = 0
        s = src()
        for l in range(n):

            if not self.split[l]:
                s.add('accumulator = 0.0;')

                for r in range(0, k):
                    s.add('{omega} = {varpi} / (10e-6 + {sigma}) / (10e-6 + {sigma});',
                          omega = self.omega[w+r],
                          varpi = _to_string(self.varpi[l,r]),
                          sigma = self.sigma[r])

                    s.add('accumulator += {omega};',
                          omega = self.omega[w+r])

                for r in range(0, k):

                    s.add('{omega} /= accumulator;',
                          omega = self.omega[w+r])

                w += k

            else:
                for sc, pm in enumerate(('p', 'm')):

                    s.add('accumulator = 0.0;')

                    for r in range(0, k):

                        s.add('{omega} = {varpi} / {scale} / (10e-6 + {sigma}) / (10e-6 + {sigma});',
                              omega = self.omega[w+r],
                              varpi = _to_string(self.varpi[l,r][sc]),
                              scale = self.scale[l][sc],
                              sigma = self.sigma[r])

                        s.add('accumulator += {omega};',
                              omega = self.omega[w+r])

                    for r in range(0, k):

                        s.add('{omega} /= accumulator;',
                              scale = self.scale[l][sc],
                              omega = self.omega[w+r])

                    w += k

        return s.src()


    ######################################################################

    def uniform_reconstruction(self, fr='frX'):
        r"""Fully un-rolled reconstruction kernel for uniform grids.

        The reconstruction kernel computes the WENO reconstruction
        based on the weights *omega* (which have already been
        computed) and the reconstruction coefficients *coeffs*.

        Returns: OpenCL source code (as a string).

        """

        n = self.n
        k = self.k

        # reconstructions
        s = src()
        for l in range(n):
            for r in range(k):

                rec = src()
                for j in range(k):
                    rec.add('{coeff} * f[(i{shift:+d})*{stride}]',
                            coeff  = _to_string(self.coeffs[l,r,j]),
                            shift  = -r+j,
                            stride = self.strides['f'])

                s.add('{fr} = {rec};',
                      fr  = self.fr[l*k+r],
                      rec = rec.src(' + '))

        # weighted reconstruction
        w = 0
        for l in range(n):

            if not self.split[l]:

                rec = src()
                for r in range(k):
                    rec.add('{fr} * {omega}',
                            fr    = self.fr[l*k+r],
                            omega = self.omega[w+r])

                s.add('{fr} = {rec};',
                      fr  = fr.replace('X', str(l)),
                      rec = rec.src(' + '))

                w += k

            else:

                rec = src()
                for sc, pm in enumerate(('p', 'm')):

                    pmrec = src()
                    for r in range(k):
                        pmrec.add('{fr} * {omega}',
                                  fr    = self.fr[l*k+r],
                                  omega = self.omega[w+r])
                    w += k


                    rec.add('{scale} * ({pmrec})',
                            scale = self.scale[l][sc],
                            pmrec = pmrec.src(' + '))

                s.add('{fr} = {rec};',
                      fr  = fr.replace('X', str(l)),
                      rec = rec.src(' - '))

        return s.src()


