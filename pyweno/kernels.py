"""PyWENO code generation module.

   The routines throughout this module are designed to generate code
   (C, OpenCL, or Fortran) for use in specialized applications.

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


######################################################################
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
  accumulator variable ``accumulator`` is also assumed to be in
  scope.

  The *strides* dictionary controls array striding for C and OpenCL:

  * *f*: cell averaged function value strides, default ``'fsi'``
  * *sigma*: tuple: smoothness indicator strides, default ``('ssi', 'ssr')``
  * *omega*: tuple: weight strides, default ``('wsi', 'wsl', 'wsr')``
  * *fr*: tuple: intermediate reconstruction strides, default ``('frsi', 'frsr')``

  :param lang: ``'c'``, ``'opencl'``, or ``'fortran'``

  """

  def __init__(self, lang, **kwargs):

    self.n = None
    self.k = None

    self.lang = lang.lower()
    self.tmpl = templates[self.lang]

    self.sigmas = {}
    self.omegas = {}
    self.fs     = {}
    self.frs    = {}

    self.basenames = {
      'sigma': 'sigmaX',
      'omega': 'omegaX',
      'f':     'fX',
      'fr':    'frX',
      }

    self.strides = {
      'f': 'fsi',
      'sigma': ('ssi', 'ssr'),
      'omega': ('wsi', 'wsl', 'wsr'),
      'recon': ('frsi', 'frsl')
      }


#   def omega(self, r, l, s):
#     '''Return *omega* (weight) variable name.'''

#     n = self.n
#     k = self.k

#     pm = ['p', 'm']

#     if self.split[l]:
#       return self.basenames['omega'].replace('X', str(k*l+r) + pm[s])
#     else:
#       return self.basenames['omega'].replace('X', str(k*l+r))


#   def sigma(self, r):
#     '''Return *sigma* (smoothness indicator) variable name.'''

#     return self.basenames['sigma'].replace('X', str(r))


#   def recon(self, l):
#     '''Return *recon* (reconstruction) variable name.'''

#     return self.basenames['fr'].replace('X', str(l))


  #############################################################################
  # set methods

  def set_smoothness(self, beta):
    '''Set the smoothness indicator coefficients to be used
    throughout.
    '''

    self.k    = beta.shape[0]
    self.beta = np.array(beta)

    for r in range(self.k):
      self.sigmas[r] = self.basenames['sigma'].replace('X', str(r))


  def set_reconstruction_coefficients(self, coeffs):
    '''Set the reconstruction coefficients to be used throughout.'''
      
    if len(coeffs.shape) == 2:
      k = coeffs.shape[0]
      coeffs = np.reshape(coeffs, (1, k, k))

    self.coeffs = np.array(coeffs)

    self.n = coeffs.shape[0]
    self.k = coeffs.shape[1]

    for l in range(self.n):
      for r in range(self.k):
        self.fs[(l,r)] = self.basenames['f'].replace('X', str(l*self.k+r))

    for l in range(self.n):
      self.frs[l] = self.basenames['fr'].replace('X', str(l))


  def set_optimal_weights(self, varpi, split):
    '''Set the optimal weights (linear weights) to be used throughout.'''

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

    self.scale = self.n*[None]

    if np.any(split):
      for l in range(self.n):
        if self.split[l]:

          scale = [0, 0]
          for s in (0, 1):
            for r in range(0, self.k):
              scale[s] += self.varpi[l,r][s]
            scale[s] = _to_string(scale[s])

          self.scale[l] = scale

    pm = ['p', 'm']
    for l in range(self.n):
      if self.split[l]:
        for r in range(self.k):
          for s in (0, 1):
            self.omegas[(l,r,s)] = self.basenames['omega'].replace('X', str(self.k*l+r) + pm[s])
      else:
        for r in range(self.k):
          self.omegas[(l,r)] = self.basenames['omega'].replace('X', str(self.k*l+r))


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
    t = self.tmpl
    
    kernel = []
    for r in range(0, k):

      sum_beta = []
      for m in range(k-r-1, 2*k-r-1):
        for n in range(m, 2*k-r-1):
          pm = -(k-1) + m
          pn = -(k-1) + n

          sum_beta.append(t['beta*fm*fn'].format(
            fsi = self.strides['f'],
            pm  = pm,
            pn  = pn,
            beta= _to_string(self.beta[r,m,n])
            ))

      kernel.append(t['sigma='].format(
        sigma   = self.sigmas[r],
        sum_beta= ' '.join(sum_beta)))

    return '\n'.join(kernel)
      

  ######################################################################

  def weights(self, epsilon='1.0e-6'):
    r"""Fully un-rolled weights kernel for uniform grids.

    The weights kernel computes the weights *omega* determined by
    the smoothness coefficients *sigma* (which have already been
    computed).

    XXX: have epsilon passed to function
    XXX: pass power...
    
    """

    t = self.tmpl
    n = self.n
    k = self.k

    kernel = []
    for l in range(n):

      if not self.split[l]:
        kernel.append(t['acc=0'])
        
        for r in range(0, k):
          omega = self.omegas[(l,r)]
          sigma = self.sigmas[r]
          
          kernel.append(t['omega='].format(
            omega  = omega,
            sigma  = sigma,
            epsilon= epsilon,
            varpi  = _to_string(self.varpi[l,r])))

          kernel.append(t['acc+='].format(
            omega= omega))

        for r in range(0, k):
          kernel.append(t['omega/=norm'].format(
            omega= self.omegas[(l,r)]))

      else:

        for s, pm in enumerate(('p', 'm')):
          kernel.append(t['acc=0'])

          for r in range(0, k):
            omega = self.omegas[(l,r,s)]
            sigma = self.sigmas[r]

            kernel.append(t['omega=(scaled)'].format(
              omega  = omega,
              sigma  = sigma,
              scale  = self.scale[l][s],
              epsilon= epsilon,
              varpi  = _to_string(self.varpi[l,r][s])))

            kernel.append(t['acc+='].format(
              omega= omega))

          for r in range(0, k):
            kernel.append(t['omega/=norm'].format(
              omega= self.omegas[(l,r,s)]))

    return '\n'.join(kernel)


  ######################################################################

  def reconstruction(self):
    r"""Fully un-rolled reconstruction kernel for uniform grids.
    
    The reconstruction kernel computes the WENO reconstruction
    based on the weights *omega* (which have already been
    computed) and the reconstruction coefficients *coeffs*.
    
    """
    
    t = self.tmpl
    n = self.n
    k = self.k

    kernel = []

    # reconstructions
    for l in range(n):
      for r in range(k):

        sum_coeff = []
        for j in range(k):
          sum_coeff.append(t['c*f'].format(
            coeff= _to_string(self.coeffs[l,r,j]),
            shift= -r+j,
            fsi  = self.strides['f']))

        kernel.append(t['fr='].format(
          recon       = self.fs[(l,r)],
          sum_weighted= ' '.join(sum_coeff)))
          
          
    # weighted reconstruction
    for l in range(n):
      if not self.split[l]:

        sum_weighted = []
        for r in range(k):
          sum_weighted.append(t['omega*fr'].format(
            fr=    self.fs[(l,r)],
            omega= self.omegas[(l,r)]))

        kernel.append(t['fr='].format(
          recon=        self.frs[l],
          sum_weighted= ' + '.join(sum_weighted)))

      else:

        sum_weighted = []
        for s, pm in enumerate(('p', 'm')):

          pm_weighted = []
          for r in range(k):
            pm_weighted.append(t['omega*fr'].format(
              fr=    self.fs[(l,r)],
              omega= self.omegas[(l,r,s)]))

          sum_weighted.append(t['scale*()'].format(
            scale=       self.scale[l][s],
            pm_weighted= ' + '.join(pm_weighted)))

        kernel.append(t['fr='].format(
          recon=        self.frs[l],
          sum_weighted= ' - '.join(sum_weighted)))

    return '\n'.join(kernel)


###############################################################################
# templates

templates = {

  'c': {
    'acc=0':  'accumulator = 0.0;',
    'acc+=':  'accumulator += {omega};',

    'sigma=':     '{sigma} = {sum_beta};',
    'beta*fm*fn': '{beta} * f[(i{pm:+d})*{fsi}] * f[(i{pn:+d})*{fsi}]',

    'omega=':         '{omega} = {varpi} / ({epsilon} + {sigma}) / ({epsilon} + {sigma});',
    'omega=(scaled)': '{omega} = {varpi} / {scale} / ({epsilon} + {sigma}) / ({epsilon} + {sigma});',    
    'omega/=norm':    '{omega} /= accumulator;',
    
    'c*f':      '{coeff} * f[(i{shift:+d})*{fsi}]',
    'omega*fr': '{fr} * {omega}',
    'fr=':      '{recon} = {sum_weighted};',
    'scale*()': '{scale} * ({pm_weighted})',

    },
  
  'fortran': {
    
    'acc=0':  'accumulator = 0.0',
    'acc+=':  'accumulator = accumulator + {omega};',

    'sigma=':     '{sigma} = {sum_beta}',
    'beta*fm*fn': '{beta} * f(i{pm:+d}) * f(i{pn:+d})',

    'omega=':         '{omega} = {varpi} / ({epsilon} + {sigma})**2',
    'omega=(scaled)': '{omega} = {varpi} / {scale} / ({epsilon} + {sigma})**2',
    'omega/=norm':    '{omega} = {omega} / accumulator;',
    
    'c*f':      '{coeff} * f(i{shift:+d})',
    'omega*fr': '{fr} * {omega}',
    'fr=':      '{recon} = {sum_weighted}',
    'scale*()': '{scale} * ({pm_weighted})',

    },
  }

templates['opencl'] = templates['c'];
