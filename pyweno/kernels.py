"""PyWENO code generation tool kit (kernels)."""

import numpy as np


###############################################################################
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


###############################################################################
# CodeGenerator

class KernelGenerator(object):
  """Generate kernels for WENO reconstructions.

  Each method generates a 'kernel' for a specific WENO operation:
  computing smoothness indicators, non-linear weights, and
  reconstructions.  These code snippets can, in-turn, be used to
  create seperate functions or larger kernels.

  The *basenames* dictionary is used to define naming conventions:

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
    mstr.lang = self.lang

    self.sigma = {}
    self.omega = {}
    self.fr    = {}
    self.fs    = {}
    self.f     = {}

    self.acc = mstr('acc')

    self.basenames = {
      'sigma': 'sigmaX',
      'omega': 'omegaX',
      'fs':    'fsX',
      'fr':    'frX',
      }

    self.templates = {
      'c':       'f[(i{r:+d})*fsi]',
      'opencl':  'f[(i{r:+d})*fsi]',
      'fortran': 'f(i{r:+d})'
      }
    

  #############################################################################
  # set methods

  def to_string(self, x):

    convert = lambda x: mstr(_to_string(x))

    d = {}
    for k, v in x.items():
      if isinstance(v, tuple):
        d[k] = tuple(map(convert, list(v)))
      else:
        d[k] = convert(v)

    return d



  def set_smoothness(self, beta):
    """Set the smoothness indicator coefficients."""

    self.k    = beta['k']
    self.beta = self.to_string(beta)

    self.sigma = {}
    for r in range(self.k):
      self.sigma[r] = mstr(
        self.basenames['sigma'].replace('X', str(r)))

    self.f = {}
    for r in range(-2*self.k, 2*self.k+1):
      self.f[r] = mstr(self.templates[self.lang].format(r=r))


  def set_reconstruction_coefficients(self, coeffs):
    """Set the reconstruction coefficients."""

    self.n = coeffs['n']
    self.k = coeffs['k']
    self.coeff = self.to_string(coeffs)

    self.fr = {}
    for l in range(self.n):
      for r in range(self.k):
        self.fr[l,r] = mstr(
          self.basenames['fr'].replace('X', str(l*self.k+r)))

    self.fs = {}
    for l in range(self.n):
      self.fs[l] = mstr(
            self.basenames['fs'].replace('X', str(l)))


  def set_optimal_weights(self, varpi, split):
    """Set the optimal (linear) weights."""

    self.n = varpi['n']
    self.k = varpi['k']
    self.varpi = self.to_string(varpi)

    if split is not None:
      self.split = split
    else:
      self.split = np.array(self.n*[False])

    del self.split['n']

    # XXX: this varpi/scale stuff can probably be tightened up
    scale = {}
    if any(self.split):
      for l in range(self.n):
        if self.split[l]:

          for s in (0, 1):
            scale[l,s] = 0
            for r in range(0, self.k):
              scale[l,s] += varpi[l,r][s]

    self.scale = self.to_string(scale)

#           self.scale[l] = [mstr(''), mstr('')]
#           for s in (0, 1):
#             for r in range(0, self.k):
#               self.scale[l][s] += self.varpi[l,r][s]


    self.omega = {}
    pm = ['p', 'm']
    for l in range(self.n):
      if self.split[l]:
        for r in range(self.k):
          for s in (0, 1):
            self.omega[l,r,s] = mstr(
              self.basenames['omega'].replace('X', str(self.k*l+r) + pm[s]))
      else:
        for r in range(self.k):
          self.omega[l,r] = mstr(
            self.basenames['omega'].replace('X', str(self.k*l+r)))


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

    k    = self.k
    f    = self.f
    beta = self.beta
    sigma = self.sigma

    mstr.cont = True
    
    kernel = []
    for r in range(0, k):

      acc = mstr('')
      for m in range(k-r-1, 2*k-r-1):
        for n in range(m, 2*k-r-1):
          pm = -(k-1) + m
          pn = -(k-1) + n

          acc += beta[r,m,n] * f[m] * f[n]

      kernel.append(sigma[r].assign(acc))

    mstr.cont = False
 
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

    acc   = self.acc
    omega = self.omega
    sigma = self.sigma
    varpi = self.varpi
    scale = self.scale

    kernel = []
    for l in range(n):

      if not self.split[l]:
        kernel.append(acc.assign('0.0'))
        
        for r in range(0, k):
          kernel.append(omega[l,r].assign(
            varpi[l,r] / (sigma[r] + epsilon)**2))

          kernel.append(acc.assign(acc + omega[l,r]))

        for r in range(0, k):
          kernel.append(omega[l,r].assign(omega[l,r] / acc))

      else:
        for s, pm in enumerate(('p', 'm')):
          kernel.append(acc.assign('0.0'))

          for r in range(0, k):
            kernel.append(omega[l,r,s].assign(
              varpi[l,r][s] / scale[l,s] / (sigma[r] + epsilon)**2))

            kernel.append(acc.assign(acc + omega[l,r,s]))

          for r in range(0, k):
            kernel.append(omega[l,r,s].assign(omega[l,r,s] / acc))            

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

    mstr.cont = True

    # reconstructions
    for l in range(n):
      for r in range(k):
        acc = mstr('')
        for j in range(k):
          acc += coeff[l,r,j] * f[-r+j]

        kernel.append(fr[l,r].assign(acc))

    # weighted reconstruction
    for l in range(n):
      acc = mstr('')

      if not self.split[l]:
        for r in range(k):
          acc += omega[l,r] * fr[l,r]
          
      else:
        for s, pm in enumerate(('p', 'm')):
          acc0 = mstr('')
          for r in range(k):
            acc0 += omega[l,r,s] * fr[l,r]

          acc -= scale[l,s] * acc0

      kernel.append(fs[l].assign(acc))

    mstr.cont = False

    return '\n'.join(kernel)


###############################################################################
# mstr

class mstr(str):

  lang = 'c'
  cont = False

  def __new__(cls, string):
    return str.__new__(cls, string)

  def __mul__(self, other):
    return mstr.__new__(mstr, '(' + str(self) + ') * (' + str(other) + ')')

  def __add__(self, other):
    if len(str(self)) == 0:
      return mstr.__new__(mstr, str(other))
    if other is not None and len(str(other)) > 0:
      if not self.cont:
        return mstr.__new__(mstr, str(self) + ' + ' + str(other))
      elif self.lang in ('fortran'):
        return mstr.__new__(mstr, str(self) + ' &\n + ' + str(other))
      else:
        return mstr.__new__(mstr, str(self) + ' + ' + str(other))        
    return self

  def __sub__(self, other):
    if len(str(self)) == 0:
      return mstr.__new__(mstr, str(other))
    if other is not None and len(str(other)) > 0:
      return mstr.__new__(mstr, '(' + str(self) + ') - (' + str(other) + ')')
    return self

  def __div__(self, other):
    return mstr.__new__(mstr, '(' + str(self) + ') / (' + str(other) + ')')

  def __pow__(self, other):
    if self.lang in ('c', 'opencl'):
      if isinstance(other, int):
        return mstr.__new__(mstr, '(' + ')*('.join(other * [str(self)]) + ')')
      else:
        return mstr.__new__(mstr, 'pow(' + str(self) + ', ' + str(other) + ')')
    elif self.lang in ('fortran'):
      return mstr.__new__(mstr, '(' + str(self) + ')**(' + str(other) + ')')

  def assign_to(self, dest):
    if self.lang in ('c', 'opencl'):
      return str.__new__(str, str(dest) + ' = ' + str(self) + ';')
    elif self.lang in ('fortran'):
      return str.__new__(str, str(dest) + ' = ' + str(self))  

  def assign(self, value):
    if self.lang in ('c', 'opencl'):
      return str.__new__(str, str(self) + ' = ' + str(value) + ';')
    elif self.lang in ('fortran'):
      return str.__new__(str, str(self) + ' = ' + str(value))
