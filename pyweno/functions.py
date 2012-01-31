"""PyWENO function generation class (callable functions)."""

from kernels import KernelGenerator, symbol
from sympy import Symbol
from templates import templates


###############################################################################
# FunctionGenerator

class FunctionGenerator(KernelGenerator):
  """Generate callable functions for WENO reconstructions.

  Each method generates a function for a specific WENO operation (or
  combinations thereof): computing smoothness indicators, non-linear
  weights, and reconstructions.

  :param lang: ``'c'``, ``'opencl'``, or ``'fortran'``

  """

  def __init__(self, *args, **kwargs):
    super(FunctionGenerator, self).__init__(*args, **kwargs)


  #############################################################################

  def set_smoothness(self, *args):
    """Set the smoothness indicator coefficients."""

    t = templates[self.lang]

    super(FunctionGenerator, self).set_smoothness(*args)

    self.global_sigma = {}
    for r in range(0, self.k):
      self.global_sigma[r] = symbol(t['sigma'].format(r=r))


  def set_optimal_weights(self, *args):
    """Set the optimal (linear) weights."""

    t = templates[self.lang]

    super(FunctionGenerator, self).set_optimal_weights(*args)

    self.global_omega = {}
    pm = ['p', 'm']
    for l in range(self.n):
      if self.split[l]:
        for r in range(self.k):
          for s in (0, 1):
            self.global_omega[l,r,s] = symbol(t['omega'].format(l=l, r=r, s=s))

      else:
        for r in range(self.k):
            self.global_omega[l,r] = symbol(t['omega'].format(l=l, r=r, s=0))


  def set_reconstruction_coefficients(self, *args):
    """Set the reconstruction coefficients."""

    t = templates[self.lang]

    super(FunctionGenerator, self).set_reconstruction_coefficients(*args)

    self.global_f_star = {}
    for l in range(self.n):
      self.global_f_star[l] = symbol(t['fs'].format(l=l))


  #############################################################################

  def _set_vars(self, dest, source):
    """Set local/global variables from global/local variables."""

    src = []
    for k in sorted(source.keys()):
      if isinstance(k, tuple) or isinstance(k, int):
        d = dest[k]
        if not isinstance(dest[k], Symbol):
          d = symbol(dest[k])
        src.append(self.assign(d, source[k]))
    return '\n'.join(src)


  def _build_arguments(self, args):
    """Build list of argument signatures and definitions."""

    t = templates[self.lang]

    sigs = []
    defs = []

    a = { x[0]: x for x in args }
    for arg in [ 'f', 'sigma', 'omega', 'fs' ]:
      if arg in a:
        s, d = t[a[arg]]
        sigs.append(s)
        defs.append(d)

    return ', '.join(sigs), '\n'.join(defs)


  def _variable_join(self, l):
    """Join list of local variables in a manner suitable for the
    language."""

    l = map(lambda x: str(x), l)

    if self.lang == 'fortran':
      return ', &\n'.join(l)

    return ', '.join(l)


  #############################################################################

  def generate(self, function,
               smoothness=True, weights=True, reconstruct=True,
               store_smoothness=False, store_weights=False, normalise=True):
    """Generate WENO function/subroutine called *function*.

    :param function: function/subroutine name
    :param smoothness: compute smoothness indicators (boolean)?
    :param weights: compute non-linear weights (boolean)?
    :param reconstruct: compute WENO reconstruction (boolean)?

    :returns: function source code as a string
    """

    t = templates[self.lang]

    # XXX: make sure arguments are consistent

    kernel = []
    args = set()
    variables = []

    # compute smoothness and store, or set smoothness
    if smoothness:
      args.add(('f', 'in'))

      kernel.append(super(FunctionGenerator, self).smoothness())
      variables.extend(self.sigma.itervalues())

      if store_smoothness:
        args.add(('sigma', 'out'))
        kernel.append(self._set_vars(self.global_sigma, self.sigma))

    elif weights:
      args.add(('sigma', 'in'))
      kernel.append(self._set_vars(self.sigma, self.global_sigma))
      variables.extend(self.sigma.itervalues())

    # compute weights and store, or set weights
    if weights:

      kernel.append(super(FunctionGenerator, self).weights(normalise=normalise))
      variables.extend(self.omega.itervalues())

      if normalise:
        variables.append('acc')

      if store_weights:
        args.add(('omega', 'out'))
        kernel.append(self._set_vars(self.global_omega, self.omega))


    elif reconstruct:
      self.weights_normalised = not normalise

      args.add(('omega', 'in'))
      kernel.append(self._set_vars(self.omega, self.global_omega))
      variables.extend(self.omega.itervalues())

    # compute reconstruction
    if reconstruct:
      args.add(('f', 'in'))
      args.add(('fs', 'out'))

      kernel.append(super(FunctionGenerator, self).reconstruction())

      kernel.append(self._set_vars(self.global_f_star, self.fs))
      variables.extend(self.fs.itervalues())


    # generate function
    args, defs = self._build_arguments(args)

    src = t['callable'].format(
      function=function, args=args, defs=defs,
      variables=self._variable_join(variables),
      k=getattr(self, 'k', 0),
      n=getattr(self, 'n', 0),
      kernel = '\n'.join(kernel),
      )

    return src
