#include <Python.h>
#include <numpy/ndarrayobject.h>

void
weights_{{name}}(const double *restrict sigma, int n, int ssi, int ssr,
  double *restrict omega, int wsi, int wsl, int wsr)
{
  int i;
  double {{variables.weights|join(',')}};
  for (i = {{k-1}}; i < n - {{k-1}}; i++) {
    {%- for r in range(k) %}
    sigma{{r}} = sigma[i * ssi + {{r}} * ssr];
    {%- endfor %}

    {{weights}}

    {%- for o in omega %}
    omega[i * wsi + {{o.l}} * wsl + {{o.r}} * wsr + {{o.s}}] = omega{{o.l}}r{{o.r}}{{o.pm}};
    {%- endfor %}
  }
}

PyObject *
py_weights_{{name}}(PyObject *self, PyObject *args)
{
  double *sigma, *omega;
  PyArrayObject *sigma_py, *omega_py;

  long int n;
  int ssi, ssr, wsi, wsl, wsr;

  /* parse options */

  if (!PyArg_ParseTuple(args, "OO", &sigma_py, &omega_py))
    return NULL;

  if (sigma_py->nd != 2 || sigma_py->descr->type_num != PyArray_DOUBLE) {
    PyErr_SetString(PyExc_ValueError, "sigma must be two-dimensional and of type float");
    return NULL;
  }

  if (omega_py->descr->type_num != PyArray_DOUBLE) {
    PyErr_SetString(PyExc_ValueError, "omega must be of type float");
    return NULL;
  }

  if (!(omega_py->nd >= 2 && omega_py->nd <= 4)) {
    PyErr_SetString(PyExc_ValueError, "omega must be two, three, or four dimensional");
    return NULL;
  }

  /* get data, n, strides */

  sigma = (double *) PyArray_DATA(sigma_py);
  omega = (double *) PyArray_DATA(omega_py);

  n = PyArray_DIM(omega_py, 0);

  ssi = sigma_py->strides[0] / sizeof(double);
  ssr = sigma_py->strides[1] / sizeof(double);

  wsi = omega_py->strides[0] / sizeof(double);
  if (omega_py->nd == 3) {
    wsl = omega_py->strides[1] / sizeof(double);
    wsr = omega_py->strides[2] / sizeof(double);
  } else {
    wsl = 0;
    wsr = omega_py->strides[1] / sizeof(double);
  }

  weights_{{name}}(sigma, n, ssi, ssr, omega, wsi, wsl, wsr);

  Py_INCREF(Py_None);
  return Py_None;
}

void
reconstruct_{{name}}(const double *restrict f, int n, int fsi,
  const double *restrict omega, int wsi, int wsl, int wsr,
  double *restrict fr, int frsi, int frsl)
{
  int i;
  double {{variables.reconstruct|join(', ')}};
  for (i = {{k-1}}; i < n - {{k-1}}; i++)  {
    {%- for o in omega %}
    omega{{o.l}}r{{o.r}}{{o.pm}} = omega[i * wsi + {{o.l}} * wsl + {{o.r}} * wsr + {{o.s}}];
    {%- endfor %}

    {{reconstruction}}

    {%- for l in range(n) %}
    fr[i * frsi + {{l}} * frsl] = fs{{l}};
    {%- endfor %}
  }
}

PyObject *
py_reconstruct_{{name}}(PyObject *self, PyObject *args)
{
  double *f, *omega, *fr;
  PyArrayObject *f_py, *omega_py, *fr_py;

  long int n;
  int fsi, frsi, frsl, wsi, wsl, wsr;

  /* parse options */

  if (!PyArg_ParseTuple(args, "OOO", &f_py, &omega_py, &fr_py))
    return NULL;

  if (f_py->nd != 1 || f_py->descr->type_num != PyArray_DOUBLE) {
    PyErr_SetString(PyExc_ValueError, "f must be one-dimensional and of type float");
    return NULL;
  }

  if (fr_py->descr->type_num != PyArray_DOUBLE) {
    PyErr_SetString(PyExc_ValueError, "fr must be of type float");
    return NULL;
  }

  if (!(fr_py->nd == 1 || fr_py->nd == 2)) {
    PyErr_SetString(PyExc_ValueError, "fr must be one or two dimensional");
    return NULL;
  }

  if (omega_py->descr->type_num != PyArray_DOUBLE) {
    PyErr_SetString(PyExc_ValueError, "omega must be of type float");
    return NULL;
  }

  if (!(omega_py->nd >= 2 && omega_py->nd <= 4)) {
    PyErr_SetString(PyExc_ValueError, "omega must be two, three, or four dimensional");
    return NULL;
  }

  /* get data, n, strides */

  f = (double *) PyArray_DATA(f_py);
  fr = (double *) PyArray_DATA(fr_py);
  omega = (double *) PyArray_DATA(omega_py);

  n = PyArray_DIM(omega_py, 0);

  fsi = f_py->strides[0] / sizeof(double);
  frsi = fr_py->strides[0] / sizeof(double);

  if (n == 1) {
    frsl = 0;
  } else {
    frsl = fr_py->strides[1] / sizeof(double);
  }

  wsi = omega_py->strides[0] / sizeof(double);
  if (omega_py->nd == 3) {
    wsl = omega_py->strides[1] / sizeof(double);
    wsr = omega_py->strides[2] / sizeof(double);
  } else {
    wsl = 0;
    wsr = omega_py->strides[1] / sizeof(double);
  }

  reconstruct_{{name}}(f, n, fsi, omega, wsi, wsl, wsr, fr, frsi, frsl);

  Py_INCREF(Py_None);
  return Py_None;
}
