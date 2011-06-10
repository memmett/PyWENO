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

class CodeGenerator(object):
  """Generate code kernels for WENO reconstructions.

  Each method generates a 'kernel' (inlined or wrapped) for a specific
  WENO operation: computing smoothness indicators, non-linear weights,
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

    self.lang = lang
    self.wrappers = []

    self.strides = {
      'f': 'fsi',
      'sigma': ('ssi', 'ssr'),
      'omega': ('wsi', 'wsl', 'wsr'),
      'recon': ('frsi', 'frsl')
      }

    self.basenames = {
      'sigma': 'sigmaX',
      'omega': 'omegaX',
      'fr':    'fX',
      'recon': 'frX',
      }


  def omega(self, r, l, s, lang, local):
    '''Return *omega* (weight) variable name.'''

    n = self.n
    k = self.k

    pm = ['p', 'm']

    if local:
      if self.split[l]:
        return self.basenames['omega'].replace('X', str(k*l+r) + pm[s])
      else:
        return self.basenames['omega'].replace('X', str(k*l+r))

    return templates[lang]['omega_idx'].format(
      r = r, l = l, s = s, 
      wsi = self.strides['omega'][0],
      wsl = self.strides['omega'][1],
      wsr = self.strides['omega'][2])


  def sigma(self, r, lang, local):
    '''Return *sigma* (smoothness indicator) variable name.'''

    if local:
      return self.basenames['sigma'].replace('X', str(r))

    return templates[lang]['sigma_idx'].format(
      r=r,
      ssi=self.strides['sigma'][0],
      ssr=self.strides['sigma'][1])


  def recon(self, l, lang, local):
    '''Return *recon* (reconstruction) variable name.'''

    if local:
      return self.basenames['recon'].replace('X', str(l))

    return templates[lang]['recon_idx'].format(
      l=l,
      frsi=self.strides['recon'][0],
      frsl=self.strides['recon'][1])


  def header(self, module=''):
    '''Return C Python extension module header.'''

    self.module = module

    return templates[self.lang]['header'].format(
      module=module)


  def footer(self):
    '''Return C Python extension module footer.'''

    if self.wrappers:

      wrappers = [ templates[self.lang]['wrapper'].format(
        pyfunc = wrapper[0],
        func = wrapper[1]) for wrapper in self.wrappers ]

      return templates[self.lang]['footer'].format(
        module=self.module, wrappers=',\n'.join(wrappers))

    return ''


  ##################################################################
  # set methods

  def set_smoothness(self, beta):
    '''Set the smoothness indicator coefficients to be used
    throughout.

    See :py:meth:`~pyweno.codegen.CodeGenerator.smoothness`.
    '''

    self.beta = np.array(beta)
    self.k    = self.beta.shape[0]
    

  def set_reconstruction_coefficients(self, coeffs):
    '''Set the reconstruction coefficients to be used throughout.

    See :py:meth:`~pyweno.codegen.CodeGenerator.reconstruction`.
    '''
      
    if len(coeffs.shape) == 2:
      k = coeffs.shape[0]
      coeffs = np.reshape(coeffs, (1, k, k))

    self.coeffs = np.array(coeffs)

    self.n = coeffs.shape[0]
    self.k = coeffs.shape[1]

    self.fr = []
    for r in range(self.k*self.n):
      self.fr.append(self.basenames['fr'].replace('X', str(r)))


  def set_optimal_weights(self, varpi, split):
    '''Set the optimal weights (linear weights) to be used throughout.

    See :py:meth:`~pyweno.codegen.CodeGenerator.weights`.
    '''

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


  def smoothness(self, function=False, wrapper=False):
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
    lang = self.lang
    
    local = True
    if function:
      local = False

    if wrapper is True:
      wrapper = ('py_' + function, function)

    kernel = []
    for r in range(0, k):

      sum_beta = []
      for m in range(k-r-1, 2*k-r-1):
        for n in range(m, 2*k-r-1):
          pm = -(k-1) + m
          pn = -(k-1) + n

          sum_beta.append(templates[lang]['beta'].format(
            fsi  = self.strides['f'],
            pm   = pm,
            pn   = pn,
            beta = _to_string(self.beta[r,m,n])
            ))

      kernel.append(templates[lang]['sigma'].format(
        sigma    = self.sigma(r, lang, local),
        sum_beta = ' '.join(sum_beta)))

    if local:
      return '\n'.join(kernel)
    
    src = templates[lang]['smoothness'].format(
      function=function, k=k, rmax=n-1,
      kernel='\n'.join(kernel))

    if wrapper:
      self.wrappers.append(wrapper)
      src += templates[lang]['smoothness_wrapper'].format(
        wrapper=wrapper[0],
        function=wrapper[1])

    return src

  
      
      

  ######################################################################

  def weights(self, epsilon='1.0e-6', function=False, wrapper=False):
    r"""Fully un-rolled weights kernel for uniform grids.

    The weights kernel computes the weights *omega* determined by
    the smoothness coefficients *sigma* (which have already been
    computed).
    
    """

    n = self.n
    k = self.k

    lang = self.lang

    local = True
    if function:
      local = False

    if wrapper is True:
      wrapper = ('py_' + function, function)

    kernel = []

    for l in range(n):

      if not self.split[l]:
        kernel.append(templates[lang]['acc_zero'])
        
        for r in range(0, k):
          omega = self.omega(r, l, 0, lang, local)
          sigma = self.sigma(r, lang, local)
          
          kernel.append(templates[lang]['omega'].format(
            omega = omega,
            epsilon = epsilon,
            varpi = _to_string(self.varpi[l,r]),
            sigma = self.sigma(r, lang, local)))

          kernel.append(templates[lang]['acc_incr'].format(
            omega = omega))

        for r in range(0, k):
          omega = self.omega(r, l, 0, lang, local)
          kernel.append(templates[lang]['omega_norm'].format(
            omega = omega))

      else:

        for s, pm in enumerate(('p', 'm')):
          kernel.append(templates[lang]['acc_zero'])

          for r in range(0, k):
            omega = self.omega(r, l, s, lang, local)
            sigma = self.sigma(r, lang, local)

            kernel.append(templates[lang]['omega_scale'].format(
              omega = omega,
              scale = self.scale[l][s],
              epsilon = epsilon,
              varpi = _to_string(self.varpi[l,r][s]),
              sigma = self.sigma(r, lang, local)))

            kernel.append(templates[lang]['acc_incr'].format(
              omega = omega))

          for r in range(0, k):
            omega = self.omega(r, l, s, lang, local)
            kernel.append(templates[lang]['omega_norm'].format(
              omega = omega))

    if local:
      return '\n'.join(kernel)
    
    src= templates[lang]['weights'].format(
      function=function, k=k, rmax=n-1,
      kernel='\n'.join(kernel))

    if wrapper:
      self.wrappers.append(wrapper)
      src += templates[lang]['weights_wrapper'].format(
        wrapper=wrapper[0],
        function=wrapper[1])

    return src
  


  ######################################################################

  def reconstruction(self, function=False, wrapper=False):
    r"""Fully un-rolled reconstruction kernel for uniform grids.
    
    The reconstruction kernel computes the WENO reconstruction
    based on the weights *omega* (which have already been
    computed) and the reconstruction coefficients *coeffs*.
    
    """
    
    n = self.n
    k = self.k

    lang = self.lang

    local = True
    if function:
      local = False

    if wrapper is True:
      wrapper = ('py_' + function, function)

    kernel = []

    # reconstructions
    for l in range(n):
      for r in range(k):

        sum_coeff = []
        for j in range(k):
          sum_coeff.append(templates[lang]['coeff'].format(
            coeff  = _to_string(self.coeffs[l,r,j]),
            shift  = -r+j,
            fsi = self.strides['f']))

        kernel.append(templates[lang]['recon'].format(
          recon = self.fr[l*k+r],
          sum_weighted = ' '.join(sum_coeff)))
          
          
    # weighted reconstruction
    for l in range(n):
      if not self.split[l]:

        sum_weighted = []
        for r in range(k):
          sum_weighted.append(templates[lang]['weighted'].format(
            fr = self.fr[l*k+r],
            omega = self.omega(r, l, 0, lang, local)))

        kernel.append(templates[lang]['recon'].format(
          recon = self.recon(l, lang, local),
          sum_weighted = ' + '.join(sum_weighted)))

      else:

        sum_weighted = []
        for s, pm in enumerate(('p', 'm')):

          pm_weighted = []
          for r in range(k):
            pm_weighted.append(templates[lang]['weighted'].format(
              fr = self.fr[l*k+r],
              omega = self.omega(r, l, s, lang, local)))

          sum_weighted.append(templates[lang]['scale'].format(
            scale = self.scale[l][s],
            pm_weighted = ' + '.join(pm_weighted)))

        kernel.append(templates[lang]['recon'].format(
          recon = self.recon(l, lang, local),
          sum_weighted = ' - '.join(sum_weighted)))

    if local:
      return '\n'.join(kernel)
    
    src = templates[lang]['reconstruct'].format(
      function=function, k=k, n=n, rmax=n-1,
      frs = ', '.join(self.fr),
      kernel='\n'.join(kernel))

    if wrapper:
      self.wrappers.append(wrapper)
      src += templates[lang]['reconstruct_wrapper'].format(
        wrapper=wrapper[0],
        function=wrapper[1])

    return src


templates = {

  'c': {

    'acc_zero':  'accumulator = 0.0;',
    'acc_incr':  'accumulator += {omega};',

    'sigma_idx': 'sigma[i*{ssi}+{r}*{ssr}]',
    'sigma':     '{sigma} = {sum_beta};',
    'beta':      '{beta} * f[(i{pm:+d})*{fsi}] * f[(i{pn:+d})*{fsi}]',

    'smoothness': """
      void {function}(const double *restrict f, int n, int fsi,
                      double *restrict sigma, int ssi, int ssr)
      {{
        int i;
        for (i={k}; i<n-{k}; i++) {{
          {kernel}
        }}
      }}
      """,

    'omega_idx': 'omega[i*{wsi}+{l}*wsl+{r}*{wsr}+{s}]',
    'omega': '{omega} = {varpi} / ({epsilon} + {sigma}) / ({epsilon} + {sigma});',
    'omega_scale': '{omega} = {varpi} / {scale} / ({epsilon} + {sigma}) / ({epsilon} + {sigma});',    
    'omega_norm': '{omega} /= accumulator;',
    
    'weights': """
      void {function}(const double *restrict sigma, int n, int ssi, int ssr,
                      double *restrict omega, int wsi, int wsl, int wsr)
      {{
        int i;
        double accumulator;
        for (i={k}; i<n-{k}; i++) {{
          {kernel}
        }}
      }}  
      """,
    
    'fr': '{fr} = {sum_coeff};',
    'coeff': '{coeff} * f[(i{shift:+d})*{fsi}]',
    'weighted': '{fr} * {omega}',
    'recon': '{recon} = {sum_weighted};',
    'scale': '{scale} * ({pm_weighted})',

    'recon_idx': 'fr[i*{frsi}+{l}*{frsl}]',

    'reconstruct': """
      void {function}(const double *restrict f, int n, int fsi,
                      const double *restrict omega, int wsi, int wsl, int wsr,
                      double *restrict fr, int frsi, int frsl)
      {{
        int i;
        double {frs};
        for (i={k}; i<n-{k}; i++) {{
          {kernel}
        }}
      }}
      """,

    'header': """
      #define PY_ARRAY_UNIQUE_SYMBOL {module}_ARRAY_API
      #include <stdio.h>
      #include <Python.h>
      #include <numpy/ndarrayobject.h>
    """,

    'wrapper': '{{"{pyfunc}", {func}, METH_VARARGS, ""}}',
    
    'footer': '''
      static PyMethodDef {module}methods[] = {{
      {wrappers},
      {{NULL, NULL, 0, NULL}}}};

      PyMODINIT_FUNC
      init{module}(void)
      {{
        (void) Py_InitModule("{module}", {module}methods);
        import_array();
      }}      
      ''',

    'smoothness_wrapper': '''
      PyObject *
      {wrapper}(PyObject *self, PyObject *args)
      {{
        double *sigma, *f;
        PyArrayObject *f_py, *sigma_py;

        long int n;
        int ssi, ssr, fsi;

        /* parse options */

        if (! PyArg_ParseTuple(args, "OO", &f_py, &sigma_py))
          return NULL;

        if (sigma_py->nd != 2 || sigma_py->descr->type_num != PyArray_DOUBLE) {{
          PyErr_SetString(PyExc_ValueError, "sigma must be two-dimensional and of type float");
          return NULL;
        }}

        if (f_py->nd != 1 || f_py->descr->type_num != PyArray_DOUBLE) {{
          PyErr_SetString(PyExc_ValueError, "f must be one-dimensional and of type float");
          return NULL;
        }}

        /* get data, n, strides */
        sigma = (double *) PyArray_DATA(sigma_py);
        f     = (double *) PyArray_DATA(f_py);

        n = PyArray_DIM(f_py, 0);

        ssi = sigma_py->strides[0] / sizeof(double);
        ssr = sigma_py->strides[1] / sizeof(double);

        fsi = f_py->strides[0] / sizeof(double);

        {function}(f, n, fsi, sigma, ssi, ssr);

        Py_INCREF(Py_None);
        return Py_None;
      }}''',

    'weights_wrapper': '''
      PyObject *
      {wrapper}(PyObject *self, PyObject *args)
      {{
        double *sigma, *omega;
        PyArrayObject *sigma_py, *omega_py;

        long int n;
        int ssi, ssr, wsi, wsl, wsr;

        /* parse options */

        if (! PyArg_ParseTuple(args, "OO", &sigma_py, &omega_py))
          return NULL;

        if (sigma_py->nd != 2 || sigma_py->descr->type_num != PyArray_DOUBLE) {{
          PyErr_SetString(PyExc_ValueError, "sigma must be two-dimensional and of type float");
          return NULL;
        }}

        if (omega_py->descr->type_num != PyArray_DOUBLE) {{
          PyErr_SetString(PyExc_ValueError, "omega must be of type float");
          return NULL;
        }}

        if (! (omega_py->nd >= 2 && omega_py->nd <= 4)) {{
          PyErr_SetString(PyExc_ValueError, "omega must be two, three, or four dimensional");
          return NULL;
        }}

        /* get data, n, strides */
        sigma = (double *) PyArray_DATA(sigma_py);
        omega = (double *) PyArray_DATA(omega_py);

        n = PyArray_DIM(omega_py, 0);

        ssi = sigma_py->strides[0] / sizeof(double);
        ssr = sigma_py->strides[1] / sizeof(double);

        wsi = omega_py->strides[0] / sizeof(double);
        if (omega_py-> nd == 3) {{
          wsl = omega_py->strides[1] / sizeof(double);
          wsr = omega_py->strides[2] / sizeof(double);
        }} else {{
          wsl = 0;
          wsr = omega_py->strides[1] / sizeof(double);
        }}

        {function}(sigma, n, ssi, ssr, omega, wsi, wsl, wsr);

        Py_INCREF(Py_None);
        return Py_None;
      }}
      ''',

    'reconstruct_wrapper': '''
      PyObject *
      {wrapper}(PyObject *self, PyObject *args)
      {{
        double *f, *omega, *fr;
        PyArrayObject *f_py, *omega_py, *fr_py;

        long int n;
        int fsi, frsi, frsl, wsi, wsl, wsr;

        /* parse options */

        if (! PyArg_ParseTuple(args, "OOO", &f_py, &omega_py, &fr_py))
          return NULL;

        if (f_py->nd != 1 || f_py->descr->type_num != PyArray_DOUBLE) {{
          PyErr_SetString(PyExc_ValueError, "f must be one-dimensional and of type float");
          return NULL;
        }}

        if (fr_py->descr->type_num != PyArray_DOUBLE) {{
          PyErr_SetString(PyExc_ValueError, "fr must be of type float");
          return NULL;
        }}

        if (! (fr_py->nd == 1 || fr_py->nd == 2)) {{
          PyErr_SetString(PyExc_ValueError, "fr must be one or two dimensional");
          return NULL;
        }}

        if (omega_py->descr->type_num != PyArray_DOUBLE) {{
          PyErr_SetString(PyExc_ValueError, "omega must be of type float");
          return NULL;
        }}

        if (! (omega_py->nd >= 2 && omega_py->nd <= 4)) {{
          PyErr_SetString(PyExc_ValueError, "omega must be two, three, or four dimensional");
          return NULL;
        }}

        /* get data, n, strides */
        f     = (double *) PyArray_DATA(f_py);
        fr    = (double *) PyArray_DATA(fr_py);
        omega = (double *) PyArray_DATA(omega_py);

        n = PyArray_DIM(omega_py, 0);

        fsi  =  f_py->strides[0] / sizeof(double);
        frsi = fr_py->strides[0] / sizeof(double);

        if (n == 1) {{
          frsl = 0;
        }} else {{
          frsl = fr_py->strides[1] / sizeof(double);
        }}

        wsi = omega_py->strides[0] / sizeof(double);
        if (omega_py-> nd == 3) {{
          wsl = omega_py->strides[1] / sizeof(double);
          wsr = omega_py->strides[2] / sizeof(double);
        }} else {{
          wsl = 0;
          wsr = omega_py->strides[1] / sizeof(double);
        }}

        {function}(f, n, fsi, omega, wsi, wsl, wsr, fr, frsi, frsl);

        Py_INCREF(Py_None);
        return Py_None;
      }}
      '''
    },
  
  'opencl': {
    
    'acc_zero':  'accumulator = 0.0;',
    'acc_incr':  'accumulator += {omega};',

    'sigma_idx': 'sigma[i*{ssi}+{r}*{ssr}]',
    'sigma':     '{sigma} = {sum_beta};',
    'beta':      '{beta} * f[(i{pm:+d})*{fsi}] * f[(i{pn:+d})*{fsi}]',

    'smoothness': """
      __kernel void {function}(__global const float *f, int fsi,
                               __global const float *sigma, int ssi, int ssr)
      {{
        int i = get_global_id(0);
        {kernel}
      }}
      """,

    'omega_idx': 'omega[i*{wsi}+{l}*wsl+{r}*{wsr}+{s}]',
    'omega': '{omega} = {varpi} / ({epsilon} + {sigma}) / ({epsilon} + {sigma});',
    'omega_scale': '{omega} = {varpi} / {scale} / ({epsilon} + {sigma}) / ({epsilon} + {sigma});',    
    'omega_norm': '{omega} /= accumulator;',
    
    'weights': """
      __kernel void {function}(__global const float *sigma, int ssi, int ssr,
                               __global const float *omega, int wsi, int wsl, int wsr)
      {{
        int i = get_global_id(0);
        {kernel}
      }}
      """,  
    
    'fr': '{fr} = {sum_coeff};',
    'coeff': '{coeff} * f[(i{shift:+d})*{fsi}]',
    'weighted': '{fr} * {omega}',
    'recon': '{recon} = {sum_weighted};',
    'scale': '{scale} * ({pm_weighted})',

    'recon_idx': 'fr[i*{frsi}+{l}*{frsl}]',

    'reconstruct': """
      __kernel void {function}(__global const float *f, int fsi,
                               __global const float *omega, int wsi, int wsl, int wsr,
                               __global float *fr, int frsi, int frsl)
      {{
        int i = get_global_id(0);
        float {frs};
        {kernel}
      }}
      """,

    'header': """
    """,

    'footer': """
    """
    
    },
  
  'fortran': {
    
    'acc_zero':  'accumulator = 0.0',
    'acc_incr':  'accumulator = accumulator + {omega};',

    'sigma_idx': 'sigma(i,{r})',
    'sigma':     '{sigma} = {sum_beta}',
    'beta':      '{beta} * f(i{pm:+d}) * f(i{pn:+d})',

    'smoothness': """
      subroutine {function}(f, n, sigma)

        implicit none
            
        real(kind=8), intent(in) :: f(n)
        integer, intent(in) :: n
        real(kind=8), intent(out) :: sigma(n,0:{rmax})
        integer :: i

        do i={k}, n-{k}
          {kernel}
        end do
      end subroutine
      """,

    'omega_idx': 'omega(i,{l},{r},{s})',
    'omega': '{omega} = {varpi} / ({epsilon} + {sigma})**2',
    'omega_scale': '{omega} = {varpi} / {scale} / ({epsilon} + {sigma})**2',
    'omega_norm': '{omega} = {omega} / accumulator;',
    
    'weights': """
      subroutine {function}(sigma, n, omega)

        implicit none

        real(kind=8), intent(in) :: sigma(n,0:{rmax})
        integer, intent(in) :: n
        real(kind=8), intent(out) :: omega(n,{n},0:{rmax},2)
        integer :: i
        real(kind=8) :: accumulator

        do i={k}, n-{k}
          {kernel}
        end do
      end subroutine  
      """,
    
    'fr': '{fr} = {sum_coeff}',
    'coeff': '{coeff} * f(i{shift:+d})',
    'weighted': '{fr} * {omega}',
    'recon': '{recon} = {sum_weighted}',
    'scale': '{scale} * ({pm_weighted})',

    'recon_idx': 'fr(i,{l})',

    'reconstruct': """
       subroutine {function}(f, n, omega, fr)

         implicit none
            
         real(kind=8), intent(in) :: f(n)
         integer, intent(in) :: n
         real(kind=8), intent(in) :: omega(n,{n},0:{rmax},2)
         real(kind=8), intent(out) :: fr(n,{n})              
         integer :: i
         real(kind=8) :: accumulator
         real(kind=8) :: {frs}

         do i={k}, n-{k}
           {kernel}
         end do
       end subroutine
       """,
    
    'header': """
    module {module}
    contains
    """,

    'footer': """
    end module {module}
    """
    
    },
  }
