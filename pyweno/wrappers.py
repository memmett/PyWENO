"""PyWENO code generation module (wrappers)."""

import kernels
from kernels import mstr

###############################################################################
# WrapperGenerator

class WrapperGenerator(kernels.KernelGenerator):
  """Generate kernals and wrappers for WENO reconstructions.

  Each method generates a function (and optionallly a Python wrapper)
  for a specific WENO operation: computing smoothness indicators,
  non-linear weights, and reconstructions.

  :param lang: ``'c'``, ``'opencl'``, or ``'fortran'``

  """

  def __init__(self, *args, **kwargs):
    super(WrapperGenerator, self).__init__(*args, **kwargs)

    self.wrappers = []


  def header(self, module=''):
    """Return C Python extension module header."""

    t = templates[self.lang]

    self.module = module

    return t['header'].format(module=module)


  def footer(self):
    """Return C Python extension module footer."""

    t = templates[self.lang]

    if self.wrappers:

      wrappers = [ t['wrapper'].format(
        pyfunc = wrapper[0],
        func   = wrapper[1]) for wrapper in self.wrappers ]

      return t['footer'].format(
        module=self.module, wrappers=',\n'.join(wrappers))

    if self.lang in ('fortran'):
      return t['footer'].format(module=self.module, wrappers='')

    return ''


  def variable_join(self, l):

    if self.lang == 'fortran':
      return ', &\n'.join(l)

    return ', '.join(l)


  def set_smoothness(self, *args):

    t = templates[self.lang]

    super(WrapperGenerator, self).set_smoothness(*args)

    self.global_sigma = {}
    for r in range(0, self.k):
      self.global_sigma[r] = mstr(t['sigma'].format(r=r))


  def set_optimal_weights(self, *args):

    t = templates[self.lang]

    super(WrapperGenerator, self).set_optimal_weights(*args)

    self.global_omega = {}
    pm = ['p', 'm']
    for l in range(self.n):
      if self.split[l]:
        for r in range(self.k):
          for s in (0, 1):
            self.global_omega[l,r,s] = mstr(t['omega'].format(l=l, r=r, s=s))

      else:
        for r in range(self.k):
            self.global_omega[l,r] = mstr(t['omega'].format(l=l, r=r, s=0))


  def set_reconstruction_coefficients(self, *args):

    t = templates[self.lang]

    super(WrapperGenerator, self).set_reconstruction_coefficients(*args)

    self.global_f_star = {}
    for l in range(self.n):
      self.global_f_star[l] = mstr(t['fs'].format(l=l))


  def set_vars(self, dest, source):
    src = []
    for k in sorted(source.keys()):
      if isinstance(k, tuple) or isinstance(k, int):
        d = dest[k]
        if not isinstance(dest[k], mstr):
          d = mstr(dest[k])
        src.append(d.assign(source[k]))
    return '\n'.join(src)


  #############################################################################
  # wrappers

  def smoothness(self, function='smoothness', wrapper=False):
    """Smoothness function."""

    t = templates[self.lang]

    kernel = [ super(WrapperGenerator, self).smoothness() ]
    kernel.append(self.set_vars(self.global_sigma, self.sigma))

    src = t['smoothness'].format(
      function = function, k=self.k, rmax=self.k-1,
      variables= self.variable_join(self.sigma.values()),
      kernel   = '\n'.join(kernel))

    if wrapper:
      wrapper = ('py_' + function, function)
      self.wrappers.append(wrapper)
      src += t['smoothness_wrapper'].format(
        wrapper=wrapper[0],
        function=wrapper[1])

    return src
      

  #############################################################################
                    
  def weights(self, function='weights', wrapper=False):
    """Weights function."""

    t = templates[self.lang]
    k = self.k
    n = self.n

    kernel = []
    kernel.append(self.set_vars(self.sigma, self.global_sigma))
    kernel.append(super(WrapperGenerator, self).weights())
    kernel.append(self.set_vars(self.global_omega, self.omega))

    variables = [ 'acc' ]
    variables += self.sigma.values()
    variables += self.omega.values()    

    src = t['weights'].format(
      function = function, k=k, rmax=k-1, n=n,
      variables= ', '.join(variables),
      kernel   = '\n'.join(kernel))

    if wrapper:
      wrapper = ('py_' + function, function)
      self.wrappers.append(wrapper)
      src += t['weights_wrapper'].format(
        wrapper=wrapper[0],
        function=wrapper[1])

    return src


  #############################################################################

  def reconstruction(self, function='reconstruct',
                     compute_smoothness=False,
                     compute_weights=False,
                     wrapper=False):
    """Recontruction function."""
    
    t = templates[self.lang]
    n = self.n
    k = self.k

    kernel = []

    if compute_smoothness:
      kernel.append(super(WrapperGenerator, self).smoothness())

    if compute_weights:
      if not compute_smoothness:
        kernel.append(self.set_vars(self.sigma, self.global_sigma))            
      kernel.append(super(WrapperGenerator, self).weights())
    else:
      kernel.append(self.set_vars(self.omega, self.global_omega))      
      
    kernel.append(super(WrapperGenerator, self).reconstruction())
    kernel.append(self.set_vars(self.global_f_star, self.fs))

    variables = []
    if compute_smoothness:
      template  = t['reconstruct_compute_smoothness']
      variables += [ 'acc' ]
      variables += self.sigma.values()
      variables += self.omega.values()
    elif compute_weights:
      template  = t['reconstruct_compute_weights']
      variables += [ 'acc' ]
      variables += self.sigma.values()      
      variables += self.omega.values()
    else:
      template  = t['reconstruct']
      variables += self.omega.values()
      
    variables += self.fs.values()
    variables += self.fr.values()

    src = template.format(
        function = function, k=k, n=n, rmax=k-1,
        variables= self.variable_join(variables),
        kernel   = '\n'.join(kernel))

    if wrapper:
      wrapper = ('py_' + function, function)
      self.wrappers.append(wrapper)

      if compute_smoothness:
        template = t['reconstruct_compute_smoothness_wrapper']
      elif compute_weights:
        template = t['reconstruct_compute_weights_wrapper']
      else:
        template = t['reconstruct_wrapper']

      src += template.format(
        wrapper=wrapper[0],
        function=wrapper[1])

    return src


###############################################################################
# templates

templates = {

  'c': {

    'sigma': 'sigma[i*ssi+{r}*ssr]',
    'omega': 'omega[i*wsi+{l}*wsl+{r}*wsr+{s}]',
    'fs':    'fr[i*frsi+{l}*frsl]',

    'smoothness': '''
      void {function}(const double *restrict f, int n, int fsi,
                      double *restrict sigma, int ssi, int ssr)
      {{
        int i;
        double {variables};
        for (i={k}-1; i<n-{k}+1; i++) {{
          {kernel}
        }}
      }}
      ''',
    
    'weights': '''
      void {function}(const double *restrict sigma, int n, int ssi, int ssr,
                      double *restrict omega, int wsi, int wsl, int wsr)
      {{
        int i;
        double {variables};
        for (i={k}-1; i<n-{k}+1; i++) {{
          {kernel}
        }}
      }}  
      ''',
    
    'reconstruct': '''
      void {function}(const double *restrict f, int n, int fsi,
                      const double *restrict omega, int wsi, int wsl, int wsr,
                      double *restrict fr, int frsi, int frsl)
      {{
        int i;
        double {variables};
        for (i={k}-1; i<n-{k}+1; i++) {{
          {kernel}
        }}
      }}
      ''',

    'reconstruct_compute_weights': '''
      void {function}(const double *restrict f, int n, int fsi,
                      const double *restrict sigma, int ssi, int ssr,
                      double *restrict fr, int frsi, int frsl)
      {{
        int i;
        double {variables};
        for (i={k}-1; i<n-{k}+1; i++) {{
          {kernel}
        }}
      }}
      ''',

    'reconstruct_compute_smoothness': '''
      void {function}(const double *restrict f, int n, int fsi,
                      double *restrict fr, int frsi, int frsl)
      {{
        int i;
        double {variables};
        for (i={k}-1; i<n-{k}+1; i++) {{
          {kernel}
        }}
      }}
      ''',

    'header': '''
      #define PY_ARRAY_UNIQUE_SYMBOL {module}_ARRAY_API
      #include <stdio.h>
      #include <Python.h>
      #include <numpy/ndarrayobject.h>
    ''',

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

    'reconstruct_compute_weights_wrapper': '''
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

    'reconstruct_wrapper_compute_smoothness': '''
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
    
    'sigma': 'sigma[i*ssi+{r}*ssr]',
    'omega': 'omega[i*wsi+{l}*wsl+{r}*wsr+{s}]',
    'fs':    'fr[i*frsi+{l}*frsl]',

    'smoothness': '''
      __kernel void {function}(__global const double *f, int fsi,
                               __global const double *sigma, int ssi, int ssr)
      {{
        int i = get_global_id(0);
        double {variables};
        {kernel}
      }}
      ''',

    
    'weights': '''
      __kernel void {function}(__global const double *sigma, int ssi, int ssr,
                               __global const double *omega, int wsi, int wsl, int wsr)
      {{
        int i = get_global_id(0);
        double {variables};
        {kernel}
      }}
      ''',  
    

    'reconstruct': '''
      __kernel void {function}(__global const double *f, int fsi,
                               __global const double *omega, int wsi, int wsl, int wsr,
                               __global double *fr, int frsi, int frsl)
      {{
        int i = get_global_id(0);
        double {variables};
        {kernel}
      }}
      ''',

    'reconstruct_compute_weights': '''
      __kernel void {function}(__global const double *f, int fsi,
                               __global const double *sigma, int ssi, int ssr,
                               __global double *fr, int frsi, int frsl)
      {{
        int i = get_global_id(0);
        double {variables};
        {kernel}
      }}
      ''',

    'reconstruct_compute_smoothness': '''
      __kernel void {function}(__global const double *f, int fsi,
                               __global double *fr, int frsi, int frsl)
      {{
        int i = get_global_id(0);
        double {variables};
        {kernel}
      }}
      ''',


    },
  
  'fortran': {
    
    'sigma': 'sigma(i,{r})',
    'omega': 'omega(i,{l},{r},{s})',
    'fs':    'fr(i,{l})',

    'smoothness': '''
      subroutine {function}(f, n, sigma)

        implicit none
            
        real(kind=8), intent(in) :: f(n)
        integer, intent(in) :: n
        real(kind=8), intent(out) :: sigma(n,0:{rmax})
        integer :: i
        real(kind=8) :: {variables}

        do i={k}, n-{k}
          {kernel}
        end do
      end subroutine
      ''',

    'weights': '''
      subroutine {function}(sigma, n, omega)

        implicit none

        real(kind=8), intent(in) :: sigma(n,0:{rmax})
        integer, intent(in) :: n
        real(kind=8), intent(out) :: omega(n,{n},0:{rmax},2)
        integer :: i
        real(kind=8) :: variables        

        do i={k}, n-{k}
          {kernel}
        end do
      end subroutine  
      ''',
    
    'reconstruct': '''
       subroutine {function}(f, n, omega, fr)

         implicit none
            
         real(kind=8), intent(in) :: f(n)
         integer, intent(in) :: n
         real(kind=8), intent(in) :: omega(n,{n},0:{rmax},2)
         real(kind=8), intent(out) :: fr(n,0:{n}-1)              
         integer :: i
         real(kind=8) :: {variables}

         do i={k}, n-{k}
           {kernel}
         end do
       end subroutine
       ''',
    
    'reconstruct_compute_weights': '''
       subroutine {function}(f, n, sigma, fr)

         implicit none
            
         real(kind=8), intent(in) :: f(n)
         integer, intent(in) :: n
         real(kind=8), intent(in) :: sigma(n,0:{rmax})         
         real(kind=8), intent(out) :: fr(n,0:{n}-1)              
         integer :: i
         real(kind=8) :: {variables}

         do i={k}, n-{k}
           {kernel}
         end do
       end subroutine
       ''',
    
    'reconstruct_compute_smoothness': '''
       subroutine {function}(f, n, fr)

         implicit none
            
         real(kind=8), intent(in) :: f(n)
         integer, intent(in) :: n
         real(kind=8), intent(out) :: fr(n,0:{n}-1)              
         integer :: i
         real(kind=8) :: {variables}

         do i={k}, n-{k}
           {kernel}
         end do
       end subroutine
       ''',
    

    'header': '''
    module {module}
    contains
    ''',

    'footer': '''
    end module {module}
    '''
    
    },
  }
