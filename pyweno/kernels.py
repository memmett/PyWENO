"""PyWENO code generation tool kit (kernels)."""

import sympy
import codeprinters

import symbolic

class KernelGenerator(object):
  """Generate kernels for WENO reconstructions.

  Each method generates a 'kernel' for a specific WENO operation:
  computing smoothness indicators, non-linear weights, and
  reconstructions.  These code snippets can, in-turn, be used to
  create seperate functions or larger kernels.

  The pyweno.symbols.names object is used to define naming conventions:

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

  def __init__(self, lang, order=None, xi=None, **kwargs):
    import symbols
    if order is not None:
      self.k = (order + 1) / 2
      self.xi = xi
    self.lang = lang.lower()
    self.weights_normalised = False
    symbols.names.lang = lang.lower()


  #############################################################################

  def smoothness(self, reuse=False, beta=None):
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

    from symbols import sigma, fmn, f

    kernel = Kernel()

    if beta is None:
      beta = getattr(self, 'beta', symbolic.jiang_shu_smoothness_coefficients(self.k))

    k  = beta.get('k', 0)
    nc = beta.get('l', k)

    if not reuse:
      for r in range(k):
        v = sum([ beta[r,m,n] * f[-r+m] * f[-r+n]
                  for m in range(nc)
                  for n in range(m, nc) ])
        kernel.assign(sigma[r], v)

    else:

      # first pass: compute all unique combinations of f[i-r+m] * f[i-r+n]
      #             usually this would be done for i=k once
      burnin = Kernel()
      burnt  = {}
      for r in range(k):
        for m in range(nc):
          for n in range(m, nc):
            if (-r+m,-r+n) not in burnt:
              burnin.assign(fmn[-r+m,-r+n], f[-r+m] * f[-r+n])
            burnt[-r+m,-r+n] = fmn[-r+m,-r+n]

      # second pass: assuming all unique f[i-r+m] * f[i-r+n] have already been computed,
      #              set/compute all unique f[i+1-r+m] * f[i+1-r+n]
      cache   = {}
      delayed = Kernel()
      for r in range(k):
        for m in range(nc):
          for n in range(m, nc):
            if (-r+m,-r+n) in cache:
              continue
            if (1-r+m,1-r+n) in burnt:
              # set fmn[-r+m,-r+n] from previous pass
              kernel.assign(fmn[-r+m,-r+n], fmn[1-r+m,1-r+n])
            else:
              # compute new fmn[-r+m,-r+n], delay until after all copies are done
              delayed.assign(fmn[-r+m,-r+n], f[-r+m] * f[-r+n])
            cache[-r+m,-r+n] = True

      kernel.src.extend(delayed.src)

      self.burnin = burnin.body()

      # finally, using above compute sigma
      for r in range(k):
        v = sum([ beta[r,m,n] * fmn[-r+m,-r+n]
                  for m in range(nc)
                  for n in range(m, nc) ])
        kernel.assign(sigma[r], v)


    self.beta = beta
    return kernel.body()


  #############################################################################

  def weights(self, varpi=None, split=None, normalise=False, power=2, epsilon='1.0e-6'):
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

    from symbols import real, omega, sigma

    kernel = Kernel()

    varpi = getattr(self, 'varpi', None)
    split = getattr(self, 'split', None)
    if varpi is None:
      varpi, split = symbolic.optimal_weights(self.k, self.xi)

    n  = varpi.get('n')
    k  = varpi.get('k')
    nc = varpi.get('l', k)

    scale = { (l,s): sum([ varpi[l,r][s] for r in range(0, k) ])
                                         for l in range(n)
                                         for s in (0, 1) if split[l] }

    self.weights_normalised = normalise

    epsilon = real(epsilon)
    accsym  = real('acc')

    for l in range(n):

      if not split[l]:
        for r in range(0, k):
          kernel.assign(omega[l,r], varpi[l,r] / (sigma[r] + epsilon)**power)
        if normalise:
          kernel.assign(accsym, sum([ omega[l,r] for r in range(0, k) ]))
          for r in range(0, k):
            kernel.assign(omega[l,r], omega[l,r] / accsym)

      else:
        for s, pm in enumerate(('p', 'm')):
          for r in range(0, k):
            kernel.assign(omega[l,r,s], varpi[l,r][s] / scale[l,s] / (sigma[r] + epsilon)**power)
          if normalise:
            kernel.assign(accsym, sum([ omega[l,r,s] for r in range(0, k) ]))
            for r in range(0, k):
              kernel.assign(omega[l,r,s], omega[l,r,s] / accsym)

    self.varpi = varpi
    self.split = split
    return kernel.body()


  #############################################################################

  def reconstruction(self, coeffs=None):
    r"""Fully un-rolled reconstruction kernel for uniform grids.

    The reconstruction kernel computes the WENO reconstruction
    based on the weights *omega* (which have already been
    computed) and the reconstruction coefficients *coeffs*.

    """

    from symbols import omega, fs, fr, f

    kernel = Kernel()

    if coeffs is None:
      coeffs = getattr(self, 'coeffs', symbolic.reconstruction_coefficients(self.k, self.xi))

    n  = coeffs.get('n')
    k  = coeffs.get('k')
    nc = coeffs.get('l', k)

    varpi = getattr(self, 'varpi', None)
    split = getattr(self, 'split', None)
    if varpi is None:
      varpi, split = symbolic.optimal_weights(self.k, self.xi)

    scale = { (l,s): sum([ varpi[l,r][s] for r in range(0, k) ])
                                         for l in range(n)
                                         for s in (0, 1) if split[l] }

    # reconstructions
    for l in range(n):
      for r in range(k):
        v = sum([ coeffs[l,r,j] * f[-r+j] for j in range(nc) ])
        kernel.assign(fr[l,r], v)

    # weighted reconstruction
    for l in range(n):
      if not split[l]:
        v = sum([ omega[l,r] * fr[l,r] for r in range(k) ])
        if not self.weights_normalised:
           v /= sum([ omega[l,r] for r in range(k) ])
      else:
        vp = sum([ omega[l,r,0] * fr[l,r] for r in range(k) ])
        if not self.weights_normalised:
          vp /= sum([ omega[l,r,0] for r in range(k) ])
        vm = sum([ omega[l,r,1] * fr[l,r] for r in range(k) ])
        if not self.weights_normalised:
          vm /= sum([ omega[l,r,1] for r in range(k) ])
        v = scale[l,0] * vp - scale[l,1] * vm

      kernel.assign(fs[l], v)

    return kernel.body()


###############################################################################
# helpers

class Kernel(object):
  def __init__(self):
    import symbols
    if symbols.names.lang == 'fortran':
      self.code = codeprinters.FCodePrinter(settings={'source_format': 'free'})
    else:
      self.code = codeprinters.CCodePrinter()
    self.src = []
  def assign(self, dest, value):
    if isinstance(self.code, codeprinters.CCodePrinter):
      self.src.append(str(dest) + ' = ' + self.code.doprint(value.evalf(35)) + ';')
    else:
      self.src.append(str(dest) + ' = ' + self.code.doprint(value.evalf(35)))
  def body(self):
    return '\n'.join(self.src)
