"""PyWENO code generation module.

   The routines throughout this module are designed to generate
   wrappers for kernels generated in kernels.py.

"""


######################################################################
# WrapperGenerator

class WrapperGenerator(object):
  """Generate wrappers for WENO reconstructions.

  Each method generates a function (and optionallly a Python wrapper)
  for a specific WENO operation: computing smoothness indicators,
  non-linear weights, and reconstructions.

  The *strides* dictionary controls array striding for C and OpenCL:

  * *f*: cell averaged function value strides, default ``'fsi'``
  * *sigma*: tuple: smoothness indicator strides, default ``('ssi', 'ssr')``
  * *omega*: tuple: weight strides, default ``('wsi', 'wsl', 'wsr')``
  * *fr*: tuple: intermediate reconstruction strides, default ``('frsi', 'frsr')``

  :param kernel: pyweno.kernels.KernelGenerator

  """

  def __init__(self, kernel, **kwargs):

    self.kernel = kernel
    self.lang   = kernel.lang.lower()
    self.tmpl   = templates[self.lang]
    self.wrappers = []

    self.strides = {
      'f': 'fsi',
      'sigma': ('ssi', 'ssr'),
      'omega': ('wsi', 'wsl', 'wsr'),
      'recon': ('frsi', 'frsl')
      }


  def omega(self, r, l, s):
    '''Return *omega* (weight) variable name.'''

    t = self.tmpl

    return t['omega'].format(
      r = r, l = l, s = s, 
      wsi = self.strides['omega'][0],
      wsl = self.strides['omega'][1],
      wsr = self.strides['omega'][2])


  def sigma(self, r):
    '''Return *sigma* (smoothness indicator) variable name.'''

    t = self.tmpl

    return t['sigma'].format(
      r=r,
      ssi=self.strides['sigma'][0],
      ssr=self.strides['sigma'][1])


  def recon(self, l):
    '''Return *recon* (reconstruction) variable name.'''

    t = self.tmpl

    return t['recon'].format(
      l=l,
      frsi=self.strides['recon'][0],
      frsl=self.strides['recon'][1])


  def header(self, module=''):
    '''Return C Python extension module header.'''

    t = self.tmpl

    self.module = module

    return t['header'].format(module=module)


  def footer(self):
    '''Return C Python extension module footer.'''

    t = self.tmpl

    if self.wrappers:

      wrappers = [ t['wrapper'].format(
        pyfunc = wrapper[0],
        func   = wrapper[1]) for wrapper in self.wrappers ]

      return t['footer'].format(
        module=self.module, wrappers=',\n'.join(wrappers))

    return ''


  #############################################################################
  # kernels

  def smoothness(self, function='smoothness', wrapper=False):
    '''Smoothness function.'''

    t = self.tmpl
    k = self.kernel.k

    if wrapper is True:
      wrapper = ('py_' + function, function)

    kernel = [ self.kernel.smoothness() ]
    for r in range(0, k):
      kernel.append(t['set'].format(
        arg  = self.sigma(r),
        local= self.kernel.sigmas[r]))

    src = t['smoothness'].format(
      function = function, k=k, rmax=k-1,
      variables= ', '.join(self.kernel.sigmas.values()),
      kernel   = '\n'.join(kernel))

    if wrapper:
      self.wrappers.append(wrapper)
      src += t['smoothness_wrapper'].format(
        wrapper=wrapper[0],
        function=wrapper[1])

    return src
      

  ######################################################################
                    
  def weights(self, function='weights', wrapper=False):
    '''Weights function.'''

    t = self.tmpl
    k = self.kernel.k
    n = self.kernel.n

    lang = self.lang

    if wrapper is True:
      wrapper = ('py_' + function, function)

    kernel = [ self.kernel.weights() ]
    for l in range(n):
      if not self.kernel.split[l]:
        for r in range(0, k):
          kernel.append(t['set'].format(
            arg  = self.omega(r,l,0),
            local= self.kernel.omegas[(r,l)]))

      else:
        for s, pm in enumerate(('p', 'm')):
          for r in range(0, k):
            kernel.append(t['set'].format(
              arg  = self.omega(r,l,s),
              local= self.kernel.omegas[(r,l,s)]))

    src = t['weights'].format(
      function = function, k=k, rmax=n-1,
      variables= ', '.join(self.kernel.omegas.values()),
      kernel   = '\n'.join(kernel))

    if wrapper:
      self.wrappers.append(wrapper)
      src += t['weights_wrapper'].format(
        wrapper=wrapper[0],
        function=wrapper[1])

    return src


  ######################################################################

  def reconstruction(self, function='reconstruct',
                     local_smoothness=False,
                     local_weights=False,
                     wrapper=False):
    '''Recontruction function.'''
    
    t = self.tmpl
    n = self.kernel.n
    k = self.kernel.k

    if wrapper is True:
      wrapper = ('py_' + function, function)

    kernel = []

    if local_smoothness:
      kernel.append(self.kernel.smoothness())
    else:
      for r in range(0, k):
        kernel.append(t['set'].format(
          arg  = self.kernel.sigmas[r],
          local= self.sigma(r)))
      

    if local_weights:
      kernel.append(self.kernel.weights())
    else:
      for l in range(n):
        if not self.kernel.split[l]:
          for r in range(0, k):
            kernel.append(t['set'].format(
              arg  = self.kernel.omegas[(l,r)],
              local= self.omega(r,l,0)))

        else:
          for s, pm in enumerate(('p', 'm')):
            for r in range(0, k):
              kernel.append(t['set'].format(
                arg  = self.kernel.omegas[(l,r,s)],
                local= self.omega(r,l,s)))
      
    kernel.append(self.kernel.reconstruction())
    
    for l in range(n):
      kernel.append(t['set'].format(
        arg  = self.recon(l),
        local= self.kernel.frs[l]))

    variables = []
    if local_smoothness:
      template  = t['reconstruct_local_weights_and_smoothness']
      variables += self.kernel.sigmas.values()
      variables += self.kernel.omegas.values()
      variables += [ 'accumulator' ]
    elif local_weights:
      template  = t['reconstruct_local_weights']
      variables += self.kernel.sigmas.values()      
      variables += self.kernel.omegas.values()
      variables += [ 'accumulator' ]
    else:
      template  = t['reconstruct']

    variables += self.kernel.fs.values()
    variables += self.kernel.frs.values()
    
    src = template.format(
        function = function, k=k, n=n, rmax=n-1,
        variables= ', '.join(variables),
        kernel   = '\n'.join(kernel))

    if wrapper:
      self.wrappers.append(wrapper)
      if local_smoothness:
        template = t['reconstruct_local_weights_and_smoothness_wrapper']
      elif local_weights:
        template = t['reconstruct_local_weights_wrapper']
      else:
        template = t['reconstruct_wrapper']

      src += template.format(
        wrapper=wrapper[0],
        function=wrapper[1])

    return src


templates = {

  'c': {

    'set': '{arg} = {local};',

    'sigma': 'sigma[i*{ssi}+{r}*{ssr}]',

    'smoothness': """
      void {function}(const double *restrict f, int n, int fsi,
                      double *restrict sigma, int ssi, int ssr)
      {{
        int i;
        double {variables};
        for (i={k}; i<n-{k}; i++) {{
          {kernel}
        }}
      }}
      """,

    'omega': 'omega[i*{wsi}+{l}*{wsl}+{r}*{wsr}+{s}]',
    
    'weights': """
      void {function}(const double *restrict sigma, int n, int ssi, int ssr,
                      double *restrict omega, int wsi, int wsl, int wsr)
      {{
        int i;
        double accumulator;
        double {variables};
        for (i={k}; i<n-{k}; i++) {{
          {kernel}
        }}
      }}  
      """,
    
    'recon': 'fr[i*{frsi}+{l}*{frsl}]',

    'reconstruct': """
      void {function}(const double *restrict f, int n, int fsi,
                      const double *restrict omega, int wsi, int wsl, int wsr,
                      double *restrict fr, int frsi, int frsl)
      {{
        int i;
        double {variables};
        for (i={k}; i<n-{k}; i++) {{
          {kernel}
        }}
      }}
      """,

    'reconstruct_local_weights': """
      void {function}(const double *restrict f, int n, int fsi,
                      const double *restrict sigma, int ssi, int ssr,
                      double *restrict fr, int frsi, int frsl)
      {{
        int i;
        double {variables};
        for (i={k}; i<n-{k}; i++) {{
          {kernel}
        }}
      }}
      """,

    'reconstruct_local_weights_and_smoothness': """
      void {function}(const double *restrict f, int n, int fsi,
                      double *restrict fr, int frsi, int frsl)
      {{
        int i;
        double {variables};
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

    'wrapper': '{{"{func}", {pyfunc}, METH_VARARGS, ""}}',
    
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
      ''',

    'reconstruct_local_weights_wrapper': '''
      PyObject *
      {wrapper}(PyObject *self, PyObject *args)
      {{
        double *f, *sigma, *fr;
        PyArrayObject *f_py, *sigma_py, *fr_py;

        long int n;
        int fsi, frsi, frsl, ssi, ssr;

        /* parse options */

        if (! PyArg_ParseTuple(args, "OOO", &f_py, &sigma_py, &fr_py))
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

        if (sigma_py->nd != 2 || sigma_py->descr->type_num != PyArray_DOUBLE) {{
          PyErr_SetString(PyExc_ValueError, "sigma must be two-dimensional and of type float");
          return NULL;
        }}

        /* get data, n, strides */
        f     = (double *) PyArray_DATA(f_py);
        fr    = (double *) PyArray_DATA(fr_py);
        sigma = (double *) PyArray_DATA(sigma_py);

        n = PyArray_DIM(f_py, 0);

        fsi  =  f_py->strides[0] / sizeof(double);
        frsi = fr_py->strides[0] / sizeof(double);

        if (n == 1) {{
          frsl = 0;
        }} else {{
          frsl = fr_py->strides[1] / sizeof(double);
        }}

        ssi = sigma_py->strides[0] / sizeof(double);
        ssr = sigma_py->strides[1] / sizeof(double);

        {function}(f, n, fsi, sigma, ssi, ssr, fr, frsi, frsl);

        Py_INCREF(Py_None);
        return Py_None;
      }}
      ''',

    'reconstruct_wrapper_local_weights_and_smoothness': '''
      PyObject *
      {wrapper}(PyObject *self, PyObject *args)
      {{
        double *f, *fr;
        PyArrayObject *f_py, *fr_py;

        long int n;
        int fsi, frsi, frsl;

        /* parse options */

        if (! PyArg_ParseTuple(args, "OO", &f_py, &fr_py))
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

        /* get data, n, strides */
        f     = (double *) PyArray_DATA(f_py);
        fr    = (double *) PyArray_DATA(fr_py);

        n = PyArray_DIM(f_py, 0);

        fsi  =  f_py->strides[0] / sizeof(double);
        frsi = fr_py->strides[0] / sizeof(double);

        if (n == 1) {{
          frsl = 0;
        }} else {{
          frsl = fr_py->strides[1] / sizeof(double);
        }}

        {function}(f, n, fsi, fr, frsi, frsl);

        Py_INCREF(Py_None);
        return Py_None;
      }}
      '''
    },
  
  'opencl': {
    
    'sigma': 'sigma[i*{ssi}+{r}*{ssr}]',

    'smoothness': """
      __kernel void {function}(__global const double *f, int fsi,
                               __global const double *sigma, int ssi, int ssr)
      {{
        int i = get_global_id(0);
        {kernel}
      }}
      """,

    'omega': 'omega[i*{wsi}+{l}*{wsl}+{r}*{wsr}+{s}]',
    
    'weights': """
      __kernel void {function}(__global const double *sigma, int ssi, int ssr,
                               __global const double *omega, int wsi, int wsl, int wsr)
      {{
        int i = get_global_id(0);
        {kernel}
      }}
      """,  
    
    'recon': 'fr[i*{frsi}+{l}*{frsl}]',

    'reconstruct': """
      __kernel void {function}(__global const double *f, int fsi,
                               __global const double *omega, int wsi, int wsl, int wsr,
                               __global double *fr, int frsi, int frsl)
      {{
        int i = get_global_id(0);
        double {frs};
        {kernel}
      }}
      """,

    'header': """
    """,

    'footer': """
    """
    
    },
  
  'fortran': {
    
    'sigma': 'sigma(i,{r})',

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

    'omega': 'omega(i,{l},{r},{s})',
    
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
    
    'recon': 'fr(i,{l})',

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
