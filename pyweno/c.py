
import numpy as np
import pyweno.code

from pyweno.code import src

class CCodeGenerator(pyweno.code.CodeGenerator):

    def __init__(self, **kwargs):

        pyweno.code.CodeGenerator.__init__(self, **kwargs)

        self.wrappers = []

    def omegas(self):
        """Return list of 'omega' names."""

        n = self.n
        k = self.k

        w = 0
        omega = []
        for l in range(n):
            if not self.split[l]:
                for r in range(k):
                    array = 'omega[i*wsi+{l}*wsl+{r}*wsr]'.format(l=l, r=r)
                    local = self.omega[w+r]
                    omega.append((array, local))
                w += k
            else:
                for s, pm in enumerate(('p', 'm')):
                    for r in range(k):
                        array = 'omega[i*wsi+{l}*wsl+{r}*wsr+{s}]'.format(l=l, r=r, s=s)
                        local = self.omega[w+r]
                        omega.append((array, local))
                    w += k

        return omega

    def get_omegas(self):
        """Return code to set omega variables from the appropriate
        elements of the omega array."""

        s = []
        for (array, local) in self.omegas():
            s.append(local + ' = ' + array + ';')

        return '\n'.join(s)

    def set_omegas(self):
        """Return code to set the appropriate elemtes of the omega
        array from the omega variables."""

        s = []
        for (array, local) in self.omegas():
            s.append(array + ' = ' + local + ';')

        return '\n'.join(s)


    def uniform_smoothness(self, function='smoothness', wrapper=False, **kwargs):
        """Uniform smoothness function."""

        k = self.k

        if wrapper is True:
            wrapper = ('py_' + function, function)

        s = src()
        s.add('''void {function}(double *f, int n, int fsi,
                                 double *sigma, int ssi, int ssr)
               {{ int i;''')

        s.add('double ' + ', '.join(self.sigma) + ';')
        s.add('for (i={k}; i<n-{k}; i++) {{{{', k=k-1)

        s.add(pyweno.code.CodeGenerator.uniform_smoothness(self))
        for r in range(k):
            s.add('sigma[i*ssi+{r}*ssr] = {sigma};',
                  r = r,
                  sigma = self.sigma[r])

        s.add('}} }}\n')

        if wrapper:
            s.add(smoothness_wrapper)
            self.wrappers.append(wrapper)

        return s.src(function=function, wrapper=wrapper[0])


    def uniform_weights(self, function='weights', wrapper=False, **kwargs):
        """Uniform weights function."""

        k = self.k
        n = self.n

        if wrapper is True:
            wrapper = ('py_' + function, function)

        s = src()

        s.add('''void {function}(double *sigma, int n, int ssi, int ssr,
                                 double *omega, int wsi, int wsl, int wsr)
               {{  int i;''')
        s.add('double accumulator;')
        s.add('double ' + ', '.join(self.sigma) + ';')
        s.add('double ' + ', '.join(self.omega) + ';')
        s.add('for (i={k}; i<n-{k}; i++) {{{{', k=k-1)

        for r in range(k):
            s.add('{sigma} = sigma[i*ssi+{r}*ssr];',
                  r = r,
                  sigma = self.sigma[r])
        s.add(pyweno.code.CodeGenerator.uniform_weights(self))
        s.add(self.set_omegas())

        s.add('}} }}\n\n')

        if wrapper:
            s.add(weights_wrapper)
            self.wrappers.append(wrapper)

        return s.src(function=function, wrapper=wrapper[0])


    def uniform_reconstruction(self, function='reconstruct', wrapper=False, **kwargs):
        """Uniform reconstruction function."""

        k = self.k
        n = self.n

        if wrapper is True:
            wrapper = ('py_' + function, function)

        s = src()

        s.add('''void {function}(double *f, int n, int fsi,
                                 double *omega, int wsi, int wsl, int wsr,
                                 double *fr, int frsi, int frsl)
              {{ int i;''')

        s.add('double ' + ', '.join(self.fr) + ';')
        s.add('double ' + ', '.join(self.omega) + ';')
        s.add('for (i={k}; i<n-{k}; i++) {{{{', k=k-1)

        s.add(self.get_omegas())
        s.add(pyweno.code.CodeGenerator.uniform_reconstruction(
            self, fr='fr[i*frsi + X*frsl]'))

        s.add('}} }}')

        if wrapper:
            s.add(reconstruct_wrapper)
            self.wrappers.append(wrapper)

        return s.src(function=function, wrapper=wrapper[0])


    def wrapper_head(self, module):

        self.module = module

        return '''
          #define PY_ARRAY_UNIQUE_SYMBOL {module}_ARRAY_API

          #include <stdio.h>

          #include <Python.h>
          #include <numpy/ndarrayobject.h>

        '''.format(module=self.module)


    def wrapper_foot(self):

        s = src()

        s.add('static PyMethodDef {module}methods[] = {{',
              module = self.module)

        for wrapper in self.wrappers:
            s.add('{{"{wrapper}", {pywrapper}, METH_VARARGS, ""}},',
                  wrapper=wrapper[1], pywrapper=wrapper[0])

        s.add('{NULL, NULL, 0, NULL}};')

        s.add('''
          PyMODINIT_FUNC
          init{module}(void)
          {{
            (void) Py_InitModule("{module}", {module}methods);
            import_array();
          }}''', module=self.module)

        return "\n".join(s.s)



######################################################################
# wrappers


smoothness_wrapper = '''
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
}}'''


weights_wrapper = '''
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
'''


reconstruct_wrapper = '''
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
