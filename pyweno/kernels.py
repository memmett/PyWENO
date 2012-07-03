"""PyWENO code generation tool kit (kernels)."""

from sympy import Symbol
import codeprinters

symbol = lambda x: Symbol(x, real=True)


###############################################################################
# KernelGenerator

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

  def __init__(self, lang, reuse=False, vectorize=False, **kwargs):

    self.n = None
    self.k = None

    self.lang = lang.lower()

    self.sigma = {}
    self.omega = {}
    self.fr    = {}
    self.fs    = {}
    self.f     = {}

    self.weights_normalised = True

    self.reuse = reuse
    self.vectorize = vectorize

    if self.lang == 'fortran':
      self.code = codeprinters.FCodePrinter(settings={'source_format': 'free'})
    else:
      self.code = codeprinters.CCodePrinter()
      self.vectorize = False


  #############################################################################
  # set methods

  def assign(self, dest, value):
    if isinstance(self.code, codeprinters.CCodePrinter):
      return str(dest) + ' = ' + self.code.doprint(value.evalf(35)) + ';'

    return str(dest) + ' = ' + self.code.doprint(value.evalf(35))


  def set_smoothness(self, beta):
    """Set the smoothness indicator coefficients."""

    self.k    = beta['k']              # poly reconstruction order
    self.nc   = beta.get('l', self.k)  # number of coefficients in the stencil
    self.beta = beta

    self.sigma = {}
    for r in range(self.k):
      if self.vectorize:
        self.sigma[r] = symbol('sigma(%r)' % r)
      else:
        self.sigma[r] = symbol(
          local_names['sigma'].replace('X', str(r)))

    self.f = {}
    for r in range(-2*self.k, 2*self.k+1):
      self.f[r] = symbol(global_names[self.lang].format(r=r))


  def set_reconstruction_coefficients(self, coeffs):
    """Set the reconstruction coefficients."""

    self.n  = coeffs['n']
    self.k  = coeffs['k']
    self.nc = coeffs.get('l', self.k)
    self.coeff = coeffs

    self.fr = {}
    for l in range(self.n):
      for r in range(self.k):
        if self.vectorize:
          self.fr[l,r] = symbol(
            'fr%d(%d)' % (l, r))
        else:
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
            if self.vectorize:
              self.omega[l,r,s] = symbol(
                'omega%d%s(%d)' % (l, pm[s], r))
            else:
              self.omega[l,r,s] = symbol(
                local_names['omega'].replace('X', str(self.k*l+r) + pm[s]))
      else:
        for r in range(self.k):
          if self.vectorize:
            self.omega[l,r] = symbol(
              'omega%d(%d)' % (l, r))
          else:
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

    k  = self.k
    f  = self.f
    nc = self.nc
    beta  = self.beta
    sigma = self.sigma

    kernel = []

    if self.reuse:
      pass

    else:
      for r in range(0, k):

        acc = 0
        for m in range(nc):
          for n in range(m, nc):
              acc = beta[r,m,n] * f[-r+m] * f[-r+n] + acc

        kernel.append(self.assign(sigma[r], acc))

    return '\n'.join(kernel)


  #############################################################################

  def weights(self, normalise=True, power=2, epsilon='1.0e-6'):
    r"""Fully un-rolled weights kernel for uniform grids.

    The weights kernel computes the weights :math:`\omega^r`
    determined by the smoothness coefficients :math:`\sigma^r` (which
    have already been computed).  The weights :math:`\omega^r` are
    computed from the optimal weights :math:`\varpi^r` according to:

    .. math::

      \omega^r = \frac{\varpi^r}{(\sigma^r + \epsilon)^p}

    The weights are subsequently renormalised (if requested) according
    to:

    .. math::

      \omega^r = \frac{\omega^r}{\sum_j \omega^j}

    :param normalise: re-normalise the weights?
    :param power: power :math:`p` of the denominator
    :param epsilon: :math:`\epsilon`

    If *normalise* is ``False`` the weights are not re-normalised.
    Instead, the re-normalisation occurs during the reconstruction
    step.  This saves a few divisions if the weights are computed
    during the reconstruction.

    """

    n  = self.n
    k  = self.k
    nc = self.nc

    omega = self.omega
    sigma = self.sigma
    varpi = self.varpi
    scale = self.scale

    self.weights_normalised = normalise

    epsilon = symbol(epsilon)
    accsym = symbol('acc')

    kernel = []
    for l in range(n):

      if not self.split[l]:
        acc = 0
        for r in range(0, k):
          kernel.append(self.assign(
              omega[l,r], varpi[l,r] / (sigma[r] + epsilon)**power))

          acc = omega[l,r] + acc

        if normalise:
          kernel.append(self.assign(accsym, acc))
          for r in range(0, k):
            kernel.append(self.assign(
                omega[l,r], omega[l,r] / accsym))

      else:
        for s, pm in enumerate(('p', 'm')):
          acc = 0

          for r in range(0, k):
            kernel.append(self.assign(
                omega[l,r,s], varpi[l,r][s] / scale[l,s] / (sigma[r] + epsilon)**power))

            acc = omega[l,r,s] + acc

          if normalise:
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

    n  = self.n
    k  = self.k
    nc = self.nc

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
        for j in range(nc):
          try:
            acc = coeff[l,r,j] * f[-r+j] + acc
          except KeyError:
            raise ValueError('smoothness indicators not set')

        kernel.append(self.assign(fr[l,r], acc))

    # weighted reconstruction
    for l in range(n):
      acc = 0

      if not self.split[l]:

        if self.vectorize:
          acc = symbol('dot_product(fr{l}, omega{l})'.format(l=l))

          if not self.weights_normalised:
            acc = acc / symbol('sum(omega{l})'.format(l=l))

        else:
          acc0 = 0
          acc1 = 0

          for r in range(k):
            acc0 = acc0 + omega[l,r] * fr[l,r]
            acc1 = acc1 + omega[l,r]

          if not self.weights_normalised:
            acc0 = acc0 / acc1

          acc = acc0

      else:
        for s, pm in enumerate(('p', 'm')):
          acc0 = 0
          acc1 = 0
          for r in range(k):
            acc0 = omega[l,r,s] * fr[l,r] + acc0
            acc1 = acc1 + omega[l,r,s]

          if not self.weights_normalised:
            acc0 = acc0 / acc1

          if pm == 'p':
            acc = acc + scale[l,s] * acc0
          else:
            acc = acc - scale[l,s] * acc0

      kernel.append(self.assign(fs[l], acc))

    return '\n'.join(kernel)

