#include <Python.h>
#include <numpy/ndarrayobject.h>

void
{{name}} (const double *restrict f, int n, int fsi, double *restrict sigma, int ssi, int ssr)
{
  int i;
  {% for r in range(k) %}
  double sigma{{r}};
  {%- endfor %}
  i = {{k-1}};
  {{burnin}}
  for (i={{k-1}}; i < n-{{k-1}}; i++)
    {
      {{kernel}}
      {% for r in range(k) %}
      sigma[i * ssi + {{r}} * ssr] = sigma{{r}};
      {%- endfor %}
    }
}

PyObject *
py_{{name}} (PyObject * self, PyObject * args)
{
  double *sigma, *f;
  PyArrayObject *f_py, *sigma_py;

  long int n;
  int ssi, ssr, fsi;

  /* parse options */

  if (!PyArg_ParseTuple (args, "OO", &f_py, &sigma_py))
    return NULL;

  if (sigma_py->nd != 2 || sigma_py->descr->type_num != PyArray_DOUBLE)
    {
      PyErr_SetString (PyExc_ValueError, "sigma must be two-dimensional and of type float");
      return NULL;
    }

  if (f_py->nd != 1 || f_py->descr->type_num != PyArray_DOUBLE)
    {
      PyErr_SetString (PyExc_ValueError, "f must be one-dimensional and of type float");
      return NULL;
    }

  /* get data, n, strides */

  sigma = (double *) PyArray_DATA (sigma_py);
  f = (double *) PyArray_DATA (f_py);

  n = PyArray_DIM (f_py, 0);

  ssi = sigma_py->strides[0] / sizeof (double);
  ssr = sigma_py->strides[1] / sizeof (double);

  fsi = f_py->strides[0] / sizeof (double);

  {{name}}(f, n, fsi, sigma, ssi, ssr);

  Py_INCREF (Py_None);
  return Py_None;
}
