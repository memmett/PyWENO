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
    self.nonuniform = False


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


  def set_nonuniform(self, k, n):
    """Set reconstruction coeffs, optimal weights, and smoothness
    coeffs to symbols appropriate for non-uniform reconstructions."""

    t = templates[self.lang]
    self.nonuniform = True

    self.k = k
    self.n = n

    # reconstruction coeffs
    c = { 'n': n, 'k': k }
    for l in range(n):
      for r in range(k):
        for j in range(k):
          c[l,r,j] = symbol(t['coeffs'].format(l=l, r=r, j=j))

    self.set_reconstruction_coefficients(c)

    # optimal weights
    varpi = { 'n': n, 'k': k }
    split = { 'n': n }
    for l in range(n):
      split[l] = False

      for r in range(k):
        varpi[l,r] = symbol(t['varpi'].format(l=l, r=r))

    self.set_optimal_weights(varpi, split)

    # smoothness coeffs
    beta = { 'k': k }
    for r in range(k):
      for m in range(k):
        for n in range(m, k):
          beta[r,m,n] = symbol(t['beta'].format(r=r, m=m, n=n))

    self.set_smoothness(beta)


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

    a = {}
    for x in args:
      a[x[0]] = x

    for arg in [ 'f', 'beta', 'sigma', 'varpi', 'omega', 'coeffs', 'fs' ]:
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
      if self.vectorize:
        variables.append('sigma(0:%d)' % (self.k-1))
      else:
        variables.extend(self.sigma.itervalues())

      if self.nonuniform:
        args.add(('beta', 'in'))

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
      if self.vectorize:
        for n in range(self.n):
          variables.append('omega%d(0:%d)' % (n, self.k-1))
      else:
        variables.extend(self.omega.itervalues())

      if self.nonuniform:
        args.add(('varpi', 'in'))

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

      if self.nonuniform:
        args.add(('coeffs', 'in'))

      kernel.append(super(FunctionGenerator, self).reconstruction())

      kernel.append(self._set_vars(self.global_f_star, self.fs))

      if self.vectorize:
        for n in range(self.n):
          variables.append('fr%d(0:%d)' % (n, self.k-1))
      else:
        variables.extend(self.fr.itervalues())
      variables.extend(self.fs.itervalues())


    # generate function
    k=getattr(self, 'k', 0)
    n=getattr(self, 'n', 0)

    args, defs = self._build_arguments(args)

    src = t['callable'].format(
      k=k, n=n,
      function=function, args=args, defs=defs,
      variables=self._variable_join(variables),
      kernel = '\n'.join(kernel),
      )

    src = src.format(k=k, n=n, rmax=k-1)

    return src
