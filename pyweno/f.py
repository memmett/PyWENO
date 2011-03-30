"""PyWENO Fortran 90 code generation module.

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
        return "%+.15g" % coeff

    try:
        coeff = coeff.evalf()
        return "%+.15g" % coeff

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

        if len(kwargs) == 0:
            self.s.append(template)
        else:
            self.s.append(template.format(**kwargs))

    def src(self, sep="\n", **kwargs):
        """Return accumulated code and apply formatting.

        Formatting is applied only when keyword arguments are passed.
        """

        s = sep.join(self.s)

        if len(kwargs) > 0:
            return s.format(**kwargs)

        return s


######################################################################
# CodeGenerator

class F90CodeGenerator(object):
    """Generate F90 code kernels for WENO reconstructions.

    Each method generates a Fortran 'kernel' for a specific WENO
    operation: computing smoothness indicators, non-linear weights,
    and reconstructions.  These code snippets can, in-turn, be used to
    create seperate functions or larger kernels.

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

    """

    basenames = {
        'sigma': 'sigmaX',
        'omega': 'omegaX',
        'fr':    'frX',
        }

    def __init__(self, **kwargs):

        self.n = None
        self.k = None


    def omegas(self):
        """Return list of 'omega' names."""

        n = self.n
        k = self.k

        w = 0
        omega = []
        for l in range(n):
            if not self.split[l]:
                for r in range(k):
                    array = 'omega(i,{l},{r},1)'.format(l=l+1, r=r)
                    local = self.omega[w+r]
                    omega.append((array, local))
                w += k
            else:
                for s, pm in enumerate(('p', 'm')):
                    for r in range(k):
                        array = 'omega(i,{l},{r},{s})'.format(l=l+1, r=r, s=s+1)
                        local = self.omega[w+r]
                        omega.append((array, local))
                    w += k

        return omega


    def get_omegas(self):
        """Return code to set omega variables from the appropriate
        elements of the omega array."""

        s = []
        for (array, local) in self.omegas():
            s.append(local + ' = ' + array)

        return '\n'.join(s)


    def set_omegas(self):
        """Return code to set the appropriate elemtes of the omega
        array from the omega variables."""

        s = []
        for (array, local) in self.omegas():
            s.append(array + ' = ' + local)

        return '\n'.join(s)


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


    def uniform_smoothness(self, function=False):
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
        if function:
            s.add('''
            subroutine {function}(f, n, sigma)

              implicit none
            
              real(kind=8), intent(in) :: f(n)
              integer, intent(in) :: n
              real(kind=8), intent(out) :: sigma(n,0:{k})
              integer :: i
              ''', function=function, k=k-1)

            s.add('do i={k}, n-{k}', k=k)
        
        for r in range(0, k):

            dot = src()
            for m in range(k-r-1, 2*k-r-1):
                for n in range(m, 2*k-r-1):
                    pm = -(k-1) + m
                    pn = -(k-1) + n

                    dot.add('{beta} * f(i{pm:+d}) * f(i{pn:+d})',
                            sigma  = self.sigma[r],
                            pm     = pm,
                            pn     = pn,
                            beta   = _to_string(self.beta[r,m,n]))

            s.add('{sigma} = {dot}',
                  sigma = self.sigma[r],
                  dot=dot.src(' &\n'))

        if function:
            s.add('end do')
            s.add('end subroutine')
            s.add('')            

        return s.src()


    ######################################################################

    def uniform_weights(self, function=False):
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

        if function:
            s.add('''
            subroutine {function}(sigma, n, omega)

              implicit none

              real(kind=8), intent(in) :: sigma(n,0:{k})
              integer, intent(in) :: n
              real(kind=8), intent(out) :: omega(n,{n},0:{k},2)
              integer :: i
              real(kind=8) :: accumulator
              ''', function=function, k=k-1, n=n)

            s.add('real(kind=8) :: ' + ', '.join(self.omega))
            s.add('do i={k}, n-{k}', k=k)
        
        for l in range(n):

            if not self.split[l]:
                s.add('accumulator = 0.0')

                for r in range(0, k):
                    s.add('{omega} = {varpi} / (10e-6 + {sigma}) / (10e-6 + {sigma})',
                          omega = self.omega[w+r],
                          varpi = _to_string(self.varpi[l,r]),
                          sigma = self.sigma[r])

                    s.add('accumulator = accumulator + {omega}',
                          omega = self.omega[w+r])

                for r in range(0, k):

                    s.add('{omega} = {omega} / accumulator',
                          omega = self.omega[w+r])

                w += k

            else:
                for sc, pm in enumerate(('p', 'm')):

                    s.add('accumulator = 0.0')

                    for r in range(0, k):

                        s.add('{omega} = {varpi} / {scale} / (10e-6 + {sigma}) / (10e-6 + {sigma})',
                              omega = self.omega[w+r],
                              varpi = _to_string(self.varpi[l,r][sc]),
                              scale = self.scale[l][sc],
                              sigma = self.sigma[r])

                        s.add('accumulator = accumulator + {omega}',
                              omega = self.omega[w+r])

                    for r in range(0, k):

                        s.add('{omega} = {omega} / accumulator',
                              scale = self.scale[l][sc],
                              omega = self.omega[w+r])

                    w += k

        if function:
            s.add(self.set_omegas())
            s.add('end do')
            s.add('end subroutine')

        return s.src()


    ######################################################################

    def uniform_reconstruction(self, fr='fr(i,X)', function=False):
        r"""Fully un-rolled reconstruction kernel for uniform grids.

        The reconstruction kernel computes the WENO reconstruction
        based on the weights *omega* (which have already been
        computed) and the reconstruction coefficients *coeffs*.

        Returns: OpenCL source code (as a string).

        """

        n = self.n
        k = self.k

        s = src()
        if function:
            # XXX: special n == 1 case
            s.add('''
            subroutine {function}(f, n, omega, fr)

              implicit none
            
              real(kind=8), intent(in) :: f(n)
              integer, intent(in) :: n
              real(kind=8), intent(in) :: omega(n,{n},0:{k},2)
              real(kind=8), intent(out) :: fr(n,{n})              
              integer :: i
              real(kind=8) :: accumulator
              ''', function=function, k=k-1, n=n)

            s.add('real(kind=8) :: ' + ', '.join(self.omega))
            s.add('real(kind=8) :: ' + ', '.join(self.fr))            
            s.add('do i={k}, n-{k}', k=k)
            s.add(self.get_omegas())            
        
            
        for l in range(n):
            for r in range(k):

                rec = src()
                for j in range(k):
                    rec.add('{coeff} * f(i{shift:+d})',
                            coeff  = _to_string(self.coeffs[l,r,j]),
                            shift  = -r+j)

                s.add('{fr} = {rec}',
                      fr  = self.fr[l*k+r],
                      rec = rec.src(' &\n'))

        # weighted reconstruction
        w = 0
        for l in range(n):

            if not self.split[l]:

                rec = src()
                for r in range(k):
                    rec.add('{fr} * {omega}',
                            fr    = self.fr[l*k+r],
                            omega = self.omega[w+r])

                s.add('{fr} = {rec}',
                      fr  = fr.replace('X', str(l+1)),
                      rec = rec.src(' + &\n'))

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
                            pmrec = pmrec.src(' + &\n'))

                s.add('{fr} = {rec}',
                      fr  = fr.replace('X', str(l+1)),
                      rec = rec.src(' - '))

        if function:
            s.add('end do')
            s.add('end subroutine')

        return s.src()

