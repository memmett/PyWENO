"""PyWENO code generation tool kit (kernels)."""

from sympy import Symbol

import codeprinters

symbol = lambda x: Symbol(x, real=True)


###############################################################################
# CodeGenerator

local_names = {
  'sigma':  'sigmaX',
  'omega':  'omegaX',
  'f_star': 'fsX',
  'f_r':    'frX',
  }

global_names = {
  'c':       'f[(i{r:+d})*fsi]',
  'opencl':  'f[(i{r:+d})*fsi]',
  'fortran': 'f(i{r:+d})'
  }

class KernelGenerator(object):
  """Generate kernels for WENO reconstructions.

  Each method generates a 'kernel' for a specific WENO operation:
  computing smoothness indicators, non-linear weights, and
  reconstructions.  These code snippets can, in-turn, be used to
  create seperate functions or larger kernels.

  The *local_names* dictionary is used to define naming conventions:

  * smoothness indicators: *sigma*, default ``sigmaX``
  * weights: *omega*, default ``omegaX``
  * intermediate reconstructions: *fr*, default ``frX``.

  For each of the above, the occurance of ``X`` is replaced by the
  left-shift *r*.  For example, for ``k=3`` and ``omega='omegaX'``,
  the weights are stored in ``omega0``, ``omega1``, and ``omega2``,
  each of which are assumed to be in scope.  In some routines the
  accumulator variable ``acc`` is also assumed to be in scope.

  :param lang: ``'c'``, ``'opencl'``, or ``'fortran'``

  """

  def __init__(self, lang, **kwargs):

    self.n = None
    self.k = None

    self.lang = lang.lower()

    self.sigma = {}
    self.omega = {}
    self.fr    = {}
    self.fs    = {}
    self.f     = {}

    if self.lang == 'fortran':
      self.code = codeprinters.FCodePrinter(settings={'source_format': 'free'})
    else:
      self.code = codeprinters.CCodePrinter()


  #############################################################################
  # set methods

  def assign(self, dest, value):
    if isinstance(self.code, codeprinters.CCodePrinter):
      return str(dest) + ' = ' + self.code.doprint(value.evalf(35)) + ';'

    return str(dest) + ' = ' + self.code.doprint(value.evalf(35))

  def set_smoothness(self, beta):
    """Set the smoothness indicator coefficients."""

    self.k    = beta['k']
    self.beta = beta

    self.sigma = {}
    for r in range(self.k):
      self.sigma[r] = symbol(
        local_names['sigma'].replace('X', str(r)))

    self.f = {}
    for r in range(-2*self.k, 2*self.k+1):
      self.f[r] = symbol(global_names[self.lang].format(r=r))


  def set_reconstruction_coefficients(self, coeffs):
    """Set the reconstruction coefficients."""

    self.n = coeffs['n']
    self.k = coeffs['k']
    self.coeff = coeffs

    self.fr = {}
    for l in range(self.n):
      for r in range(self.k):
        self.fr[l,r] = symbol(
          local_names['f_r'].replace('X', str(l*self.k+r)))

    self.fs = {}
    for l in range(self.n):
      self.fs[l] = symbol(
            local_names['f_star'].replace('X', str(l)))


  def set_optimal_weights(self, varpi, split):
    """Set the optimal (linear) weights."""

    self.n = varpi['n']
    self.k = varpi['k']
    self.varpi = varpi
    self.split = split

    self.scale = {}
    if any(self.split.values()):
      for l in range(self.n):
        if self.split[l]:
          for s in (0, 1):
            self.scale[l,s] = 0
            for r in range(0, self.k):
              self.scale[l,s] += varpi[l,r][s]

    self.omega = {}
    pm = ['p', 'm']
    for l in range(self.n):
      if self.split[l]:
        for r in range(self.k):
          for s in (0, 1):
            self.omega[l,r,s] = symbol(
              local_names['omega'].replace('X', str(self.k*l+r) + pm[s]))
      else:
        for r in range(self.k):
          self.omega[l,r] = symbol(
            local_names['omega'].replace('X', str(self.k*l+r)))


  #############################################################################
  # kernels

  def smoothness(self):
    r"""Fully un-rolled smoothness indicator kernel for uniform
    grids.

    The smoothness indicator kernel computes the smoothness indicators
    *sigma* determined by the coefficients in *beta*.  That is:

    .. math::

      \sigma_r = \sum_{m=1}^{2k-1}
                     \sum_{n=1}^{2k-1}
                         \beta_{r,m,n}\, \overline{f}_{i-k+m}\,
                                         \overline{f}_{i-k+n}.

    """

    k = self.k
    f = self.f
    beta = self.beta
    sigma = self.sigma

    kernel = []
    for r in range(0, k):

      acc = 0
      for m in range(k-r-1, 2*k-r-1):
        for n in range(m, 2*k-r-1):
          pm = -(k-1) + m
          pn = -(k-1) + n

          acc = beta[r,m,n] * f[pm] * f[pn] + acc

      kernel.append(self.assign(sigma[r], acc))

    return '\n'.join(kernel)


  #############################################################################

  def weights(self, epsilon='1.0e-6'):
    r"""Fully un-rolled weights kernel for uniform grids.

    The weights kernel computes the weights *omega* determined by
    the smoothness coefficients *sigma* (which have already been
    computed).

    XXX: have epsilon passed to function
    XXX: pass power...

    """

    n = self.n
    k = self.k

    omega = self.omega
    sigma = self.sigma
    varpi = self.varpi
    scale = self.scale

    epsilon = 1.0e-6

    accsym = symbol('acc')

    kernel = []
    for l in range(n):

      if not self.split[l]:
        acc = 0
        for r in range(0, k):
          kernel.append(self.assign(
              omega[l,r], varpi[l,r] / (sigma[r] + epsilon)**2))

          acc = omega[l,r] + acc

        kernel.append(self.assign(accsym, acc))
        for r in range(0, k):
          kernel.append(self.assign(
              omega[l,r], omega[l,r] / accsym))

      else:
        for s, pm in enumerate(('p', 'm')):
          acc = 0

          for r in range(0, k):
            kernel.append(self.assign(
                omega[l,r,s], varpi[l,r][s] / scale[l,s] / (sigma[r] + epsilon)**2))

            acc = omega[l,r,s] + acc

          kernel.append(self.assign(accsym, acc))
          for r in range(0, k):
            kernel.append(self.assign(
                omega[l,r,s], omega[l,r,s] / accsym))

    return '\n'.join(kernel)


  #############################################################################

  def reconstruction(self):
    r"""Fully un-rolled reconstruction kernel for uniform grids.

    The reconstruction kernel computes the WENO reconstruction
    based on the weights *omega* (which have already been
    computed) and the reconstruction coefficients *coeffs*.

    """

    n = self.n
    k = self.k

    f     = self.f
    fr    = self.fr
    fs    = self.fs
    coeff = self.coeff
    omega = self.omega
    scale = self.scale

    kernel = []

    # reconstructions
    for l in range(n):
      for r in range(k):
        acc = 0
        for j in range(k):
          acc = coeff[l,r,j] * f[-r+j] + acc

        kernel.append(self.assign(fr[l,r], acc))

    # weighted reconstruction
    for l in range(n):
      acc = 0

      if not self.split[l]:
        for r in range(k):
          acc = omega[l,r] * fr[l,r] + acc

      else:
        for s, pm in enumerate(('p', 'm')):
          acc0 = 0
          for r in range(k):
            acc0 = omega[l,r,s] * fr[l,r] + acc0

          acc = acc - scale[l,s] * acc0

      kernel.append(self.assign(fs[l], acc))

    return '\n'.join(kernel)

