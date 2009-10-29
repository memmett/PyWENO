#define PY_ARRAY_UNIQUE_SYMBOL PYWENO_ARRAY_API

#include <stdio.h>

#include <Python.h>
#include <numpy/ndarrayobject.h>

void
reconstruction_coeffs_k3_d0(double xi, long int i, int r, double *x, double *c)
{
  double sum_l, sum_m, prod_n, prod_m;

  /*
   * compute reconstruction coeffs of order 3
   */


  /* j = 0 */
  sum_l = 0.0;

  /* l = 1 */
  sum_m = 0.0;

  /* m = 0 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  sum_m += prod_n;

  /* m = 2 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  sum_m += prod_n;

  /* m = 3 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  sum_m += prod_n;

  prod_m = 1.0;
  prod_m *= x[i-r+1] - x[i-r+0];
  prod_m *= x[i-r+1] - x[i-r+2];
  prod_m *= x[i-r+1] - x[i-r+3];

  sum_l += sum_m / prod_m * (x[i-r+0+1] - x[i-r+0]);

  /* l = 2 */
  sum_m = 0.0;

  /* m = 0 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  sum_m += prod_n;

  /* m = 1 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  sum_m += prod_n;

  /* m = 3 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  sum_m += prod_n;

  prod_m = 1.0;
  prod_m *= x[i-r+2] - x[i-r+0];
  prod_m *= x[i-r+2] - x[i-r+1];
  prod_m *= x[i-r+2] - x[i-r+3];

  sum_l += sum_m / prod_m * (x[i-r+0+1] - x[i-r+0]);

  /* l = 3 */
  sum_m = 0.0;

  /* m = 0 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  sum_m += prod_n;

  /* m = 1 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  sum_m += prod_n;

  /* m = 2 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  sum_m += prod_n;

  prod_m = 1.0;
  prod_m *= x[i-r+3] - x[i-r+0];
  prod_m *= x[i-r+3] - x[i-r+1];
  prod_m *= x[i-r+3] - x[i-r+2];

  sum_l += sum_m / prod_m * (x[i-r+0+1] - x[i-r+0]);

  c[0] = sum_l;

  /* j = 1 */
  sum_l = 0.0;

  /* l = 2 */
  sum_m = 0.0;

  /* m = 0 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  sum_m += prod_n;

  /* m = 1 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  sum_m += prod_n;

  /* m = 3 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  sum_m += prod_n;

  prod_m = 1.0;
  prod_m *= x[i-r+2] - x[i-r+0];
  prod_m *= x[i-r+2] - x[i-r+1];
  prod_m *= x[i-r+2] - x[i-r+3];

  sum_l += sum_m / prod_m * (x[i-r+1+1] - x[i-r+1]);

  /* l = 3 */
  sum_m = 0.0;

  /* m = 0 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  sum_m += prod_n;

  /* m = 1 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  sum_m += prod_n;

  /* m = 2 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  sum_m += prod_n;

  prod_m = 1.0;
  prod_m *= x[i-r+3] - x[i-r+0];
  prod_m *= x[i-r+3] - x[i-r+1];
  prod_m *= x[i-r+3] - x[i-r+2];

  sum_l += sum_m / prod_m * (x[i-r+1+1] - x[i-r+1]);

  c[1] = sum_l;

  /* j = 2 */
  sum_l = 0.0;

  /* l = 3 */
  sum_m = 0.0;

  /* m = 0 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  sum_m += prod_n;

  /* m = 1 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  sum_m += prod_n;

  /* m = 2 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  sum_m += prod_n;

  prod_m = 1.0;
  prod_m *= x[i-r+3] - x[i-r+0];
  prod_m *= x[i-r+3] - x[i-r+1];
  prod_m *= x[i-r+3] - x[i-r+2];

  sum_l += sum_m / prod_m * (x[i-r+2+1] - x[i-r+2]);

  c[2] = sum_l;
}

PyObject *
reconstruction_coeffs_k3_d0_py(PyObject *self, PyObject *args)
{
  double *x, *c, xi;
  long int i;
  int r;

  PyObject *bndry, *coeffs;

  /*
   * parse options
   */

  if (! PyArg_ParseTuple(args, "dlidOO", &xi, &i, &r, &bndry, &coeffs))
    return NULL;

  if ((PyArray_FLAGS(bndry) & NPY_IN_ARRAY) != NPY_IN_ARRAY) {
    PyErr_SetString(PyExc_TypeError, "bndry is not contiguous and/or aligned");
    return NULL;
  }
  Py_INCREF(bndry);
  x = (double *) PyArray_DATA(bndry);

  if ((PyArray_FLAGS(coeffs) & NPY_IN_ARRAY) != NPY_IN_ARRAY) {
    PyErr_SetString(PyExc_TypeError, "coeffs is not contiguous and/or aligned");
    return NULL;
  }
  Py_INCREF(coeffs);
  c = (double *) PyArray_DATA(coeffs);

  /*
   * dispatch
   */

  reconstruction_coeffs_k3_d0(xi, i, r, x, c);

  /*
   * done
   */
  Py_INCREF(Py_None);
  return Py_None;
}

void
reconstruction_coeffs_k4_d0(double xi, long int i, int r, double *x, double *c)
{
  double sum_l, sum_m, prod_n, prod_m;

  /*
   * compute reconstruction coeffs of order 4
   */


  /* j = 0 */
  sum_l = 0.0;

  /* l = 1 */
  sum_m = 0.0;

  /* m = 0 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  prod_n *= xi - x[i-r+4];  /* n = 4 */
  sum_m += prod_n;

  /* m = 2 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  prod_n *= xi - x[i-r+4];  /* n = 4 */
  sum_m += prod_n;

  /* m = 3 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+4];  /* n = 4 */
  sum_m += prod_n;

  /* m = 4 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  sum_m += prod_n;

  prod_m = 1.0;
  prod_m *= x[i-r+1] - x[i-r+0];
  prod_m *= x[i-r+1] - x[i-r+2];
  prod_m *= x[i-r+1] - x[i-r+3];
  prod_m *= x[i-r+1] - x[i-r+4];

  sum_l += sum_m / prod_m * (x[i-r+0+1] - x[i-r+0]);

  /* l = 2 */
  sum_m = 0.0;

  /* m = 0 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  prod_n *= xi - x[i-r+4];  /* n = 4 */
  sum_m += prod_n;

  /* m = 1 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  prod_n *= xi - x[i-r+4];  /* n = 4 */
  sum_m += prod_n;

  /* m = 3 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+4];  /* n = 4 */
  sum_m += prod_n;

  /* m = 4 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  sum_m += prod_n;

  prod_m = 1.0;
  prod_m *= x[i-r+2] - x[i-r+0];
  prod_m *= x[i-r+2] - x[i-r+1];
  prod_m *= x[i-r+2] - x[i-r+3];
  prod_m *= x[i-r+2] - x[i-r+4];

  sum_l += sum_m / prod_m * (x[i-r+0+1] - x[i-r+0]);

  /* l = 3 */
  sum_m = 0.0;

  /* m = 0 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+4];  /* n = 4 */
  sum_m += prod_n;

  /* m = 1 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+4];  /* n = 4 */
  sum_m += prod_n;

  /* m = 2 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+4];  /* n = 4 */
  sum_m += prod_n;

  /* m = 4 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  sum_m += prod_n;

  prod_m = 1.0;
  prod_m *= x[i-r+3] - x[i-r+0];
  prod_m *= x[i-r+3] - x[i-r+1];
  prod_m *= x[i-r+3] - x[i-r+2];
  prod_m *= x[i-r+3] - x[i-r+4];

  sum_l += sum_m / prod_m * (x[i-r+0+1] - x[i-r+0]);

  /* l = 4 */
  sum_m = 0.0;

  /* m = 0 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  sum_m += prod_n;

  /* m = 1 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  sum_m += prod_n;

  /* m = 2 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  sum_m += prod_n;

  /* m = 3 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  sum_m += prod_n;

  prod_m = 1.0;
  prod_m *= x[i-r+4] - x[i-r+0];
  prod_m *= x[i-r+4] - x[i-r+1];
  prod_m *= x[i-r+4] - x[i-r+2];
  prod_m *= x[i-r+4] - x[i-r+3];

  sum_l += sum_m / prod_m * (x[i-r+0+1] - x[i-r+0]);

  c[0] = sum_l;

  /* j = 1 */
  sum_l = 0.0;

  /* l = 2 */
  sum_m = 0.0;

  /* m = 0 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  prod_n *= xi - x[i-r+4];  /* n = 4 */
  sum_m += prod_n;

  /* m = 1 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  prod_n *= xi - x[i-r+4];  /* n = 4 */
  sum_m += prod_n;

  /* m = 3 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+4];  /* n = 4 */
  sum_m += prod_n;

  /* m = 4 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  sum_m += prod_n;

  prod_m = 1.0;
  prod_m *= x[i-r+2] - x[i-r+0];
  prod_m *= x[i-r+2] - x[i-r+1];
  prod_m *= x[i-r+2] - x[i-r+3];
  prod_m *= x[i-r+2] - x[i-r+4];

  sum_l += sum_m / prod_m * (x[i-r+1+1] - x[i-r+1]);

  /* l = 3 */
  sum_m = 0.0;

  /* m = 0 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+4];  /* n = 4 */
  sum_m += prod_n;

  /* m = 1 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+4];  /* n = 4 */
  sum_m += prod_n;

  /* m = 2 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+4];  /* n = 4 */
  sum_m += prod_n;

  /* m = 4 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  sum_m += prod_n;

  prod_m = 1.0;
  prod_m *= x[i-r+3] - x[i-r+0];
  prod_m *= x[i-r+3] - x[i-r+1];
  prod_m *= x[i-r+3] - x[i-r+2];
  prod_m *= x[i-r+3] - x[i-r+4];

  sum_l += sum_m / prod_m * (x[i-r+1+1] - x[i-r+1]);

  /* l = 4 */
  sum_m = 0.0;

  /* m = 0 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  sum_m += prod_n;

  /* m = 1 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  sum_m += prod_n;

  /* m = 2 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  sum_m += prod_n;

  /* m = 3 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  sum_m += prod_n;

  prod_m = 1.0;
  prod_m *= x[i-r+4] - x[i-r+0];
  prod_m *= x[i-r+4] - x[i-r+1];
  prod_m *= x[i-r+4] - x[i-r+2];
  prod_m *= x[i-r+4] - x[i-r+3];

  sum_l += sum_m / prod_m * (x[i-r+1+1] - x[i-r+1]);

  c[1] = sum_l;

  /* j = 2 */
  sum_l = 0.0;

  /* l = 3 */
  sum_m = 0.0;

  /* m = 0 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+4];  /* n = 4 */
  sum_m += prod_n;

  /* m = 1 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+4];  /* n = 4 */
  sum_m += prod_n;

  /* m = 2 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+4];  /* n = 4 */
  sum_m += prod_n;

  /* m = 4 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  sum_m += prod_n;

  prod_m = 1.0;
  prod_m *= x[i-r+3] - x[i-r+0];
  prod_m *= x[i-r+3] - x[i-r+1];
  prod_m *= x[i-r+3] - x[i-r+2];
  prod_m *= x[i-r+3] - x[i-r+4];

  sum_l += sum_m / prod_m * (x[i-r+2+1] - x[i-r+2]);

  /* l = 4 */
  sum_m = 0.0;

  /* m = 0 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  sum_m += prod_n;

  /* m = 1 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  sum_m += prod_n;

  /* m = 2 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  sum_m += prod_n;

  /* m = 3 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  sum_m += prod_n;

  prod_m = 1.0;
  prod_m *= x[i-r+4] - x[i-r+0];
  prod_m *= x[i-r+4] - x[i-r+1];
  prod_m *= x[i-r+4] - x[i-r+2];
  prod_m *= x[i-r+4] - x[i-r+3];

  sum_l += sum_m / prod_m * (x[i-r+2+1] - x[i-r+2]);

  c[2] = sum_l;

  /* j = 3 */
  sum_l = 0.0;

  /* l = 4 */
  sum_m = 0.0;

  /* m = 0 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  sum_m += prod_n;

  /* m = 1 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  sum_m += prod_n;

  /* m = 2 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  sum_m += prod_n;

  /* m = 3 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  sum_m += prod_n;

  prod_m = 1.0;
  prod_m *= x[i-r+4] - x[i-r+0];
  prod_m *= x[i-r+4] - x[i-r+1];
  prod_m *= x[i-r+4] - x[i-r+2];
  prod_m *= x[i-r+4] - x[i-r+3];

  sum_l += sum_m / prod_m * (x[i-r+3+1] - x[i-r+3]);

  c[3] = sum_l;
}

PyObject *
reconstruction_coeffs_k4_d0_py(PyObject *self, PyObject *args)
{
  double *x, *c, xi;
  long int i;
  int r;

  PyObject *bndry, *coeffs;

  /*
   * parse options
   */

  if (! PyArg_ParseTuple(args, "dlidOO", &xi, &i, &r, &bndry, &coeffs))
    return NULL;

  if ((PyArray_FLAGS(bndry) & NPY_IN_ARRAY) != NPY_IN_ARRAY) {
    PyErr_SetString(PyExc_TypeError, "bndry is not contiguous and/or aligned");
    return NULL;
  }
  Py_INCREF(bndry);
  x = (double *) PyArray_DATA(bndry);

  if ((PyArray_FLAGS(coeffs) & NPY_IN_ARRAY) != NPY_IN_ARRAY) {
    PyErr_SetString(PyExc_TypeError, "coeffs is not contiguous and/or aligned");
    return NULL;
  }
  Py_INCREF(coeffs);
  c = (double *) PyArray_DATA(coeffs);

  /*
   * dispatch
   */

  reconstruction_coeffs_k4_d0(xi, i, r, x, c);

  /*
   * done
   */
  Py_INCREF(Py_None);
  return Py_None;
}

void
reconstruction_coeffs_k5_d0(double xi, long int i, int r, double *x, double *c)
{
  double sum_l, sum_m, prod_n, prod_m;

  /*
   * compute reconstruction coeffs of order 5
   */


  /* j = 0 */
  sum_l = 0.0;

  /* l = 1 */
  sum_m = 0.0;

  /* m = 0 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  prod_n *= xi - x[i-r+4];  /* n = 4 */
  prod_n *= xi - x[i-r+5];  /* n = 5 */
  sum_m += prod_n;

  /* m = 2 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  prod_n *= xi - x[i-r+4];  /* n = 4 */
  prod_n *= xi - x[i-r+5];  /* n = 5 */
  sum_m += prod_n;

  /* m = 3 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+4];  /* n = 4 */
  prod_n *= xi - x[i-r+5];  /* n = 5 */
  sum_m += prod_n;

  /* m = 4 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  prod_n *= xi - x[i-r+5];  /* n = 5 */
  sum_m += prod_n;

  /* m = 5 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  prod_n *= xi - x[i-r+4];  /* n = 4 */
  sum_m += prod_n;

  prod_m = 1.0;
  prod_m *= x[i-r+1] - x[i-r+0];
  prod_m *= x[i-r+1] - x[i-r+2];
  prod_m *= x[i-r+1] - x[i-r+3];
  prod_m *= x[i-r+1] - x[i-r+4];
  prod_m *= x[i-r+1] - x[i-r+5];

  sum_l += sum_m / prod_m * (x[i-r+0+1] - x[i-r+0]);

  /* l = 2 */
  sum_m = 0.0;

  /* m = 0 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  prod_n *= xi - x[i-r+4];  /* n = 4 */
  prod_n *= xi - x[i-r+5];  /* n = 5 */
  sum_m += prod_n;

  /* m = 1 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  prod_n *= xi - x[i-r+4];  /* n = 4 */
  prod_n *= xi - x[i-r+5];  /* n = 5 */
  sum_m += prod_n;

  /* m = 3 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+4];  /* n = 4 */
  prod_n *= xi - x[i-r+5];  /* n = 5 */
  sum_m += prod_n;

  /* m = 4 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  prod_n *= xi - x[i-r+5];  /* n = 5 */
  sum_m += prod_n;

  /* m = 5 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  prod_n *= xi - x[i-r+4];  /* n = 4 */
  sum_m += prod_n;

  prod_m = 1.0;
  prod_m *= x[i-r+2] - x[i-r+0];
  prod_m *= x[i-r+2] - x[i-r+1];
  prod_m *= x[i-r+2] - x[i-r+3];
  prod_m *= x[i-r+2] - x[i-r+4];
  prod_m *= x[i-r+2] - x[i-r+5];

  sum_l += sum_m / prod_m * (x[i-r+0+1] - x[i-r+0]);

  /* l = 3 */
  sum_m = 0.0;

  /* m = 0 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+4];  /* n = 4 */
  prod_n *= xi - x[i-r+5];  /* n = 5 */
  sum_m += prod_n;

  /* m = 1 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+4];  /* n = 4 */
  prod_n *= xi - x[i-r+5];  /* n = 5 */
  sum_m += prod_n;

  /* m = 2 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+4];  /* n = 4 */
  prod_n *= xi - x[i-r+5];  /* n = 5 */
  sum_m += prod_n;

  /* m = 4 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+5];  /* n = 5 */
  sum_m += prod_n;

  /* m = 5 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+4];  /* n = 4 */
  sum_m += prod_n;

  prod_m = 1.0;
  prod_m *= x[i-r+3] - x[i-r+0];
  prod_m *= x[i-r+3] - x[i-r+1];
  prod_m *= x[i-r+3] - x[i-r+2];
  prod_m *= x[i-r+3] - x[i-r+4];
  prod_m *= x[i-r+3] - x[i-r+5];

  sum_l += sum_m / prod_m * (x[i-r+0+1] - x[i-r+0]);

  /* l = 4 */
  sum_m = 0.0;

  /* m = 0 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  prod_n *= xi - x[i-r+5];  /* n = 5 */
  sum_m += prod_n;

  /* m = 1 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  prod_n *= xi - x[i-r+5];  /* n = 5 */
  sum_m += prod_n;

  /* m = 2 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  prod_n *= xi - x[i-r+5];  /* n = 5 */
  sum_m += prod_n;

  /* m = 3 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+5];  /* n = 5 */
  sum_m += prod_n;

  /* m = 5 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  sum_m += prod_n;

  prod_m = 1.0;
  prod_m *= x[i-r+4] - x[i-r+0];
  prod_m *= x[i-r+4] - x[i-r+1];
  prod_m *= x[i-r+4] - x[i-r+2];
  prod_m *= x[i-r+4] - x[i-r+3];
  prod_m *= x[i-r+4] - x[i-r+5];

  sum_l += sum_m / prod_m * (x[i-r+0+1] - x[i-r+0]);

  /* l = 5 */
  sum_m = 0.0;

  /* m = 0 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  prod_n *= xi - x[i-r+4];  /* n = 4 */
  sum_m += prod_n;

  /* m = 1 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  prod_n *= xi - x[i-r+4];  /* n = 4 */
  sum_m += prod_n;

  /* m = 2 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  prod_n *= xi - x[i-r+4];  /* n = 4 */
  sum_m += prod_n;

  /* m = 3 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+4];  /* n = 4 */
  sum_m += prod_n;

  /* m = 4 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  sum_m += prod_n;

  prod_m = 1.0;
  prod_m *= x[i-r+5] - x[i-r+0];
  prod_m *= x[i-r+5] - x[i-r+1];
  prod_m *= x[i-r+5] - x[i-r+2];
  prod_m *= x[i-r+5] - x[i-r+3];
  prod_m *= x[i-r+5] - x[i-r+4];

  sum_l += sum_m / prod_m * (x[i-r+0+1] - x[i-r+0]);

  c[0] = sum_l;

  /* j = 1 */
  sum_l = 0.0;

  /* l = 2 */
  sum_m = 0.0;

  /* m = 0 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  prod_n *= xi - x[i-r+4];  /* n = 4 */
  prod_n *= xi - x[i-r+5];  /* n = 5 */
  sum_m += prod_n;

  /* m = 1 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  prod_n *= xi - x[i-r+4];  /* n = 4 */
  prod_n *= xi - x[i-r+5];  /* n = 5 */
  sum_m += prod_n;

  /* m = 3 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+4];  /* n = 4 */
  prod_n *= xi - x[i-r+5];  /* n = 5 */
  sum_m += prod_n;

  /* m = 4 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  prod_n *= xi - x[i-r+5];  /* n = 5 */
  sum_m += prod_n;

  /* m = 5 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  prod_n *= xi - x[i-r+4];  /* n = 4 */
  sum_m += prod_n;

  prod_m = 1.0;
  prod_m *= x[i-r+2] - x[i-r+0];
  prod_m *= x[i-r+2] - x[i-r+1];
  prod_m *= x[i-r+2] - x[i-r+3];
  prod_m *= x[i-r+2] - x[i-r+4];
  prod_m *= x[i-r+2] - x[i-r+5];

  sum_l += sum_m / prod_m * (x[i-r+1+1] - x[i-r+1]);

  /* l = 3 */
  sum_m = 0.0;

  /* m = 0 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+4];  /* n = 4 */
  prod_n *= xi - x[i-r+5];  /* n = 5 */
  sum_m += prod_n;

  /* m = 1 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+4];  /* n = 4 */
  prod_n *= xi - x[i-r+5];  /* n = 5 */
  sum_m += prod_n;

  /* m = 2 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+4];  /* n = 4 */
  prod_n *= xi - x[i-r+5];  /* n = 5 */
  sum_m += prod_n;

  /* m = 4 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+5];  /* n = 5 */
  sum_m += prod_n;

  /* m = 5 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+4];  /* n = 4 */
  sum_m += prod_n;

  prod_m = 1.0;
  prod_m *= x[i-r+3] - x[i-r+0];
  prod_m *= x[i-r+3] - x[i-r+1];
  prod_m *= x[i-r+3] - x[i-r+2];
  prod_m *= x[i-r+3] - x[i-r+4];
  prod_m *= x[i-r+3] - x[i-r+5];

  sum_l += sum_m / prod_m * (x[i-r+1+1] - x[i-r+1]);

  /* l = 4 */
  sum_m = 0.0;

  /* m = 0 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  prod_n *= xi - x[i-r+5];  /* n = 5 */
  sum_m += prod_n;

  /* m = 1 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  prod_n *= xi - x[i-r+5];  /* n = 5 */
  sum_m += prod_n;

  /* m = 2 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  prod_n *= xi - x[i-r+5];  /* n = 5 */
  sum_m += prod_n;

  /* m = 3 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+5];  /* n = 5 */
  sum_m += prod_n;

  /* m = 5 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  sum_m += prod_n;

  prod_m = 1.0;
  prod_m *= x[i-r+4] - x[i-r+0];
  prod_m *= x[i-r+4] - x[i-r+1];
  prod_m *= x[i-r+4] - x[i-r+2];
  prod_m *= x[i-r+4] - x[i-r+3];
  prod_m *= x[i-r+4] - x[i-r+5];

  sum_l += sum_m / prod_m * (x[i-r+1+1] - x[i-r+1]);

  /* l = 5 */
  sum_m = 0.0;

  /* m = 0 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  prod_n *= xi - x[i-r+4];  /* n = 4 */
  sum_m += prod_n;

  /* m = 1 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  prod_n *= xi - x[i-r+4];  /* n = 4 */
  sum_m += prod_n;

  /* m = 2 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  prod_n *= xi - x[i-r+4];  /* n = 4 */
  sum_m += prod_n;

  /* m = 3 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+4];  /* n = 4 */
  sum_m += prod_n;

  /* m = 4 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  sum_m += prod_n;

  prod_m = 1.0;
  prod_m *= x[i-r+5] - x[i-r+0];
  prod_m *= x[i-r+5] - x[i-r+1];
  prod_m *= x[i-r+5] - x[i-r+2];
  prod_m *= x[i-r+5] - x[i-r+3];
  prod_m *= x[i-r+5] - x[i-r+4];

  sum_l += sum_m / prod_m * (x[i-r+1+1] - x[i-r+1]);

  c[1] = sum_l;

  /* j = 2 */
  sum_l = 0.0;

  /* l = 3 */
  sum_m = 0.0;

  /* m = 0 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+4];  /* n = 4 */
  prod_n *= xi - x[i-r+5];  /* n = 5 */
  sum_m += prod_n;

  /* m = 1 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+4];  /* n = 4 */
  prod_n *= xi - x[i-r+5];  /* n = 5 */
  sum_m += prod_n;

  /* m = 2 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+4];  /* n = 4 */
  prod_n *= xi - x[i-r+5];  /* n = 5 */
  sum_m += prod_n;

  /* m = 4 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+5];  /* n = 5 */
  sum_m += prod_n;

  /* m = 5 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+4];  /* n = 4 */
  sum_m += prod_n;

  prod_m = 1.0;
  prod_m *= x[i-r+3] - x[i-r+0];
  prod_m *= x[i-r+3] - x[i-r+1];
  prod_m *= x[i-r+3] - x[i-r+2];
  prod_m *= x[i-r+3] - x[i-r+4];
  prod_m *= x[i-r+3] - x[i-r+5];

  sum_l += sum_m / prod_m * (x[i-r+2+1] - x[i-r+2]);

  /* l = 4 */
  sum_m = 0.0;

  /* m = 0 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  prod_n *= xi - x[i-r+5];  /* n = 5 */
  sum_m += prod_n;

  /* m = 1 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  prod_n *= xi - x[i-r+5];  /* n = 5 */
  sum_m += prod_n;

  /* m = 2 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  prod_n *= xi - x[i-r+5];  /* n = 5 */
  sum_m += prod_n;

  /* m = 3 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+5];  /* n = 5 */
  sum_m += prod_n;

  /* m = 5 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  sum_m += prod_n;

  prod_m = 1.0;
  prod_m *= x[i-r+4] - x[i-r+0];
  prod_m *= x[i-r+4] - x[i-r+1];
  prod_m *= x[i-r+4] - x[i-r+2];
  prod_m *= x[i-r+4] - x[i-r+3];
  prod_m *= x[i-r+4] - x[i-r+5];

  sum_l += sum_m / prod_m * (x[i-r+2+1] - x[i-r+2]);

  /* l = 5 */
  sum_m = 0.0;

  /* m = 0 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  prod_n *= xi - x[i-r+4];  /* n = 4 */
  sum_m += prod_n;

  /* m = 1 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  prod_n *= xi - x[i-r+4];  /* n = 4 */
  sum_m += prod_n;

  /* m = 2 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  prod_n *= xi - x[i-r+4];  /* n = 4 */
  sum_m += prod_n;

  /* m = 3 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+4];  /* n = 4 */
  sum_m += prod_n;

  /* m = 4 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  sum_m += prod_n;

  prod_m = 1.0;
  prod_m *= x[i-r+5] - x[i-r+0];
  prod_m *= x[i-r+5] - x[i-r+1];
  prod_m *= x[i-r+5] - x[i-r+2];
  prod_m *= x[i-r+5] - x[i-r+3];
  prod_m *= x[i-r+5] - x[i-r+4];

  sum_l += sum_m / prod_m * (x[i-r+2+1] - x[i-r+2]);

  c[2] = sum_l;

  /* j = 3 */
  sum_l = 0.0;

  /* l = 4 */
  sum_m = 0.0;

  /* m = 0 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  prod_n *= xi - x[i-r+5];  /* n = 5 */
  sum_m += prod_n;

  /* m = 1 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  prod_n *= xi - x[i-r+5];  /* n = 5 */
  sum_m += prod_n;

  /* m = 2 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  prod_n *= xi - x[i-r+5];  /* n = 5 */
  sum_m += prod_n;

  /* m = 3 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+5];  /* n = 5 */
  sum_m += prod_n;

  /* m = 5 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  sum_m += prod_n;

  prod_m = 1.0;
  prod_m *= x[i-r+4] - x[i-r+0];
  prod_m *= x[i-r+4] - x[i-r+1];
  prod_m *= x[i-r+4] - x[i-r+2];
  prod_m *= x[i-r+4] - x[i-r+3];
  prod_m *= x[i-r+4] - x[i-r+5];

  sum_l += sum_m / prod_m * (x[i-r+3+1] - x[i-r+3]);

  /* l = 5 */
  sum_m = 0.0;

  /* m = 0 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  prod_n *= xi - x[i-r+4];  /* n = 4 */
  sum_m += prod_n;

  /* m = 1 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  prod_n *= xi - x[i-r+4];  /* n = 4 */
  sum_m += prod_n;

  /* m = 2 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  prod_n *= xi - x[i-r+4];  /* n = 4 */
  sum_m += prod_n;

  /* m = 3 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+4];  /* n = 4 */
  sum_m += prod_n;

  /* m = 4 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  sum_m += prod_n;

  prod_m = 1.0;
  prod_m *= x[i-r+5] - x[i-r+0];
  prod_m *= x[i-r+5] - x[i-r+1];
  prod_m *= x[i-r+5] - x[i-r+2];
  prod_m *= x[i-r+5] - x[i-r+3];
  prod_m *= x[i-r+5] - x[i-r+4];

  sum_l += sum_m / prod_m * (x[i-r+3+1] - x[i-r+3]);

  c[3] = sum_l;

  /* j = 4 */
  sum_l = 0.0;

  /* l = 5 */
  sum_m = 0.0;

  /* m = 0 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  prod_n *= xi - x[i-r+4];  /* n = 4 */
  sum_m += prod_n;

  /* m = 1 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  prod_n *= xi - x[i-r+4];  /* n = 4 */
  sum_m += prod_n;

  /* m = 2 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  prod_n *= xi - x[i-r+4];  /* n = 4 */
  sum_m += prod_n;

  /* m = 3 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+4];  /* n = 4 */
  sum_m += prod_n;

  /* m = 4 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  sum_m += prod_n;

  prod_m = 1.0;
  prod_m *= x[i-r+5] - x[i-r+0];
  prod_m *= x[i-r+5] - x[i-r+1];
  prod_m *= x[i-r+5] - x[i-r+2];
  prod_m *= x[i-r+5] - x[i-r+3];
  prod_m *= x[i-r+5] - x[i-r+4];

  sum_l += sum_m / prod_m * (x[i-r+4+1] - x[i-r+4]);

  c[4] = sum_l;
}

PyObject *
reconstruction_coeffs_k5_d0_py(PyObject *self, PyObject *args)
{
  double *x, *c, xi;
  long int i;
  int r;

  PyObject *bndry, *coeffs;

  /*
   * parse options
   */

  if (! PyArg_ParseTuple(args, "dlidOO", &xi, &i, &r, &bndry, &coeffs))
    return NULL;

  if ((PyArray_FLAGS(bndry) & NPY_IN_ARRAY) != NPY_IN_ARRAY) {
    PyErr_SetString(PyExc_TypeError, "bndry is not contiguous and/or aligned");
    return NULL;
  }
  Py_INCREF(bndry);
  x = (double *) PyArray_DATA(bndry);

  if ((PyArray_FLAGS(coeffs) & NPY_IN_ARRAY) != NPY_IN_ARRAY) {
    PyErr_SetString(PyExc_TypeError, "coeffs is not contiguous and/or aligned");
    return NULL;
  }
  Py_INCREF(coeffs);
  c = (double *) PyArray_DATA(coeffs);

  /*
   * dispatch
   */

  reconstruction_coeffs_k5_d0(xi, i, r, x, c);

  /*
   * done
   */
  Py_INCREF(Py_None);
  return Py_None;
}

void
reconstruction_coeffs_k6_d0(double xi, long int i, int r, double *x, double *c)
{
  double sum_l, sum_m, prod_n, prod_m;

  /*
   * compute reconstruction coeffs of order 6
   */


  /* j = 0 */
  sum_l = 0.0;

  /* l = 1 */
  sum_m = 0.0;

  /* m = 0 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  prod_n *= xi - x[i-r+4];  /* n = 4 */
  prod_n *= xi - x[i-r+5];  /* n = 5 */
  prod_n *= xi - x[i-r+6];  /* n = 6 */
  sum_m += prod_n;

  /* m = 2 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  prod_n *= xi - x[i-r+4];  /* n = 4 */
  prod_n *= xi - x[i-r+5];  /* n = 5 */
  prod_n *= xi - x[i-r+6];  /* n = 6 */
  sum_m += prod_n;

  /* m = 3 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+4];  /* n = 4 */
  prod_n *= xi - x[i-r+5];  /* n = 5 */
  prod_n *= xi - x[i-r+6];  /* n = 6 */
  sum_m += prod_n;

  /* m = 4 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  prod_n *= xi - x[i-r+5];  /* n = 5 */
  prod_n *= xi - x[i-r+6];  /* n = 6 */
  sum_m += prod_n;

  /* m = 5 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  prod_n *= xi - x[i-r+4];  /* n = 4 */
  prod_n *= xi - x[i-r+6];  /* n = 6 */
  sum_m += prod_n;

  /* m = 6 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  prod_n *= xi - x[i-r+4];  /* n = 4 */
  prod_n *= xi - x[i-r+5];  /* n = 5 */
  sum_m += prod_n;

  prod_m = 1.0;
  prod_m *= x[i-r+1] - x[i-r+0];
  prod_m *= x[i-r+1] - x[i-r+2];
  prod_m *= x[i-r+1] - x[i-r+3];
  prod_m *= x[i-r+1] - x[i-r+4];
  prod_m *= x[i-r+1] - x[i-r+5];
  prod_m *= x[i-r+1] - x[i-r+6];

  sum_l += sum_m / prod_m * (x[i-r+0+1] - x[i-r+0]);

  /* l = 2 */
  sum_m = 0.0;

  /* m = 0 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  prod_n *= xi - x[i-r+4];  /* n = 4 */
  prod_n *= xi - x[i-r+5];  /* n = 5 */
  prod_n *= xi - x[i-r+6];  /* n = 6 */
  sum_m += prod_n;

  /* m = 1 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  prod_n *= xi - x[i-r+4];  /* n = 4 */
  prod_n *= xi - x[i-r+5];  /* n = 5 */
  prod_n *= xi - x[i-r+6];  /* n = 6 */
  sum_m += prod_n;

  /* m = 3 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+4];  /* n = 4 */
  prod_n *= xi - x[i-r+5];  /* n = 5 */
  prod_n *= xi - x[i-r+6];  /* n = 6 */
  sum_m += prod_n;

  /* m = 4 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  prod_n *= xi - x[i-r+5];  /* n = 5 */
  prod_n *= xi - x[i-r+6];  /* n = 6 */
  sum_m += prod_n;

  /* m = 5 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  prod_n *= xi - x[i-r+4];  /* n = 4 */
  prod_n *= xi - x[i-r+6];  /* n = 6 */
  sum_m += prod_n;

  /* m = 6 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  prod_n *= xi - x[i-r+4];  /* n = 4 */
  prod_n *= xi - x[i-r+5];  /* n = 5 */
  sum_m += prod_n;

  prod_m = 1.0;
  prod_m *= x[i-r+2] - x[i-r+0];
  prod_m *= x[i-r+2] - x[i-r+1];
  prod_m *= x[i-r+2] - x[i-r+3];
  prod_m *= x[i-r+2] - x[i-r+4];
  prod_m *= x[i-r+2] - x[i-r+5];
  prod_m *= x[i-r+2] - x[i-r+6];

  sum_l += sum_m / prod_m * (x[i-r+0+1] - x[i-r+0]);

  /* l = 3 */
  sum_m = 0.0;

  /* m = 0 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+4];  /* n = 4 */
  prod_n *= xi - x[i-r+5];  /* n = 5 */
  prod_n *= xi - x[i-r+6];  /* n = 6 */
  sum_m += prod_n;

  /* m = 1 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+4];  /* n = 4 */
  prod_n *= xi - x[i-r+5];  /* n = 5 */
  prod_n *= xi - x[i-r+6];  /* n = 6 */
  sum_m += prod_n;

  /* m = 2 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+4];  /* n = 4 */
  prod_n *= xi - x[i-r+5];  /* n = 5 */
  prod_n *= xi - x[i-r+6];  /* n = 6 */
  sum_m += prod_n;

  /* m = 4 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+5];  /* n = 5 */
  prod_n *= xi - x[i-r+6];  /* n = 6 */
  sum_m += prod_n;

  /* m = 5 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+4];  /* n = 4 */
  prod_n *= xi - x[i-r+6];  /* n = 6 */
  sum_m += prod_n;

  /* m = 6 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+4];  /* n = 4 */
  prod_n *= xi - x[i-r+5];  /* n = 5 */
  sum_m += prod_n;

  prod_m = 1.0;
  prod_m *= x[i-r+3] - x[i-r+0];
  prod_m *= x[i-r+3] - x[i-r+1];
  prod_m *= x[i-r+3] - x[i-r+2];
  prod_m *= x[i-r+3] - x[i-r+4];
  prod_m *= x[i-r+3] - x[i-r+5];
  prod_m *= x[i-r+3] - x[i-r+6];

  sum_l += sum_m / prod_m * (x[i-r+0+1] - x[i-r+0]);

  /* l = 4 */
  sum_m = 0.0;

  /* m = 0 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  prod_n *= xi - x[i-r+5];  /* n = 5 */
  prod_n *= xi - x[i-r+6];  /* n = 6 */
  sum_m += prod_n;

  /* m = 1 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  prod_n *= xi - x[i-r+5];  /* n = 5 */
  prod_n *= xi - x[i-r+6];  /* n = 6 */
  sum_m += prod_n;

  /* m = 2 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  prod_n *= xi - x[i-r+5];  /* n = 5 */
  prod_n *= xi - x[i-r+6];  /* n = 6 */
  sum_m += prod_n;

  /* m = 3 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+5];  /* n = 5 */
  prod_n *= xi - x[i-r+6];  /* n = 6 */
  sum_m += prod_n;

  /* m = 5 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  prod_n *= xi - x[i-r+6];  /* n = 6 */
  sum_m += prod_n;

  /* m = 6 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  prod_n *= xi - x[i-r+5];  /* n = 5 */
  sum_m += prod_n;

  prod_m = 1.0;
  prod_m *= x[i-r+4] - x[i-r+0];
  prod_m *= x[i-r+4] - x[i-r+1];
  prod_m *= x[i-r+4] - x[i-r+2];
  prod_m *= x[i-r+4] - x[i-r+3];
  prod_m *= x[i-r+4] - x[i-r+5];
  prod_m *= x[i-r+4] - x[i-r+6];

  sum_l += sum_m / prod_m * (x[i-r+0+1] - x[i-r+0]);

  /* l = 5 */
  sum_m = 0.0;

  /* m = 0 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  prod_n *= xi - x[i-r+4];  /* n = 4 */
  prod_n *= xi - x[i-r+6];  /* n = 6 */
  sum_m += prod_n;

  /* m = 1 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  prod_n *= xi - x[i-r+4];  /* n = 4 */
  prod_n *= xi - x[i-r+6];  /* n = 6 */
  sum_m += prod_n;

  /* m = 2 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  prod_n *= xi - x[i-r+4];  /* n = 4 */
  prod_n *= xi - x[i-r+6];  /* n = 6 */
  sum_m += prod_n;

  /* m = 3 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+4];  /* n = 4 */
  prod_n *= xi - x[i-r+6];  /* n = 6 */
  sum_m += prod_n;

  /* m = 4 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  prod_n *= xi - x[i-r+6];  /* n = 6 */
  sum_m += prod_n;

  /* m = 6 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  prod_n *= xi - x[i-r+4];  /* n = 4 */
  sum_m += prod_n;

  prod_m = 1.0;
  prod_m *= x[i-r+5] - x[i-r+0];
  prod_m *= x[i-r+5] - x[i-r+1];
  prod_m *= x[i-r+5] - x[i-r+2];
  prod_m *= x[i-r+5] - x[i-r+3];
  prod_m *= x[i-r+5] - x[i-r+4];
  prod_m *= x[i-r+5] - x[i-r+6];

  sum_l += sum_m / prod_m * (x[i-r+0+1] - x[i-r+0]);

  /* l = 6 */
  sum_m = 0.0;

  /* m = 0 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  prod_n *= xi - x[i-r+4];  /* n = 4 */
  prod_n *= xi - x[i-r+5];  /* n = 5 */
  sum_m += prod_n;

  /* m = 1 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  prod_n *= xi - x[i-r+4];  /* n = 4 */
  prod_n *= xi - x[i-r+5];  /* n = 5 */
  sum_m += prod_n;

  /* m = 2 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  prod_n *= xi - x[i-r+4];  /* n = 4 */
  prod_n *= xi - x[i-r+5];  /* n = 5 */
  sum_m += prod_n;

  /* m = 3 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+4];  /* n = 4 */
  prod_n *= xi - x[i-r+5];  /* n = 5 */
  sum_m += prod_n;

  /* m = 4 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  prod_n *= xi - x[i-r+5];  /* n = 5 */
  sum_m += prod_n;

  /* m = 5 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  prod_n *= xi - x[i-r+4];  /* n = 4 */
  sum_m += prod_n;

  prod_m = 1.0;
  prod_m *= x[i-r+6] - x[i-r+0];
  prod_m *= x[i-r+6] - x[i-r+1];
  prod_m *= x[i-r+6] - x[i-r+2];
  prod_m *= x[i-r+6] - x[i-r+3];
  prod_m *= x[i-r+6] - x[i-r+4];
  prod_m *= x[i-r+6] - x[i-r+5];

  sum_l += sum_m / prod_m * (x[i-r+0+1] - x[i-r+0]);

  c[0] = sum_l;

  /* j = 1 */
  sum_l = 0.0;

  /* l = 2 */
  sum_m = 0.0;

  /* m = 0 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  prod_n *= xi - x[i-r+4];  /* n = 4 */
  prod_n *= xi - x[i-r+5];  /* n = 5 */
  prod_n *= xi - x[i-r+6];  /* n = 6 */
  sum_m += prod_n;

  /* m = 1 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  prod_n *= xi - x[i-r+4];  /* n = 4 */
  prod_n *= xi - x[i-r+5];  /* n = 5 */
  prod_n *= xi - x[i-r+6];  /* n = 6 */
  sum_m += prod_n;

  /* m = 3 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+4];  /* n = 4 */
  prod_n *= xi - x[i-r+5];  /* n = 5 */
  prod_n *= xi - x[i-r+6];  /* n = 6 */
  sum_m += prod_n;

  /* m = 4 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  prod_n *= xi - x[i-r+5];  /* n = 5 */
  prod_n *= xi - x[i-r+6];  /* n = 6 */
  sum_m += prod_n;

  /* m = 5 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  prod_n *= xi - x[i-r+4];  /* n = 4 */
  prod_n *= xi - x[i-r+6];  /* n = 6 */
  sum_m += prod_n;

  /* m = 6 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  prod_n *= xi - x[i-r+4];  /* n = 4 */
  prod_n *= xi - x[i-r+5];  /* n = 5 */
  sum_m += prod_n;

  prod_m = 1.0;
  prod_m *= x[i-r+2] - x[i-r+0];
  prod_m *= x[i-r+2] - x[i-r+1];
  prod_m *= x[i-r+2] - x[i-r+3];
  prod_m *= x[i-r+2] - x[i-r+4];
  prod_m *= x[i-r+2] - x[i-r+5];
  prod_m *= x[i-r+2] - x[i-r+6];

  sum_l += sum_m / prod_m * (x[i-r+1+1] - x[i-r+1]);

  /* l = 3 */
  sum_m = 0.0;

  /* m = 0 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+4];  /* n = 4 */
  prod_n *= xi - x[i-r+5];  /* n = 5 */
  prod_n *= xi - x[i-r+6];  /* n = 6 */
  sum_m += prod_n;

  /* m = 1 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+4];  /* n = 4 */
  prod_n *= xi - x[i-r+5];  /* n = 5 */
  prod_n *= xi - x[i-r+6];  /* n = 6 */
  sum_m += prod_n;

  /* m = 2 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+4];  /* n = 4 */
  prod_n *= xi - x[i-r+5];  /* n = 5 */
  prod_n *= xi - x[i-r+6];  /* n = 6 */
  sum_m += prod_n;

  /* m = 4 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+5];  /* n = 5 */
  prod_n *= xi - x[i-r+6];  /* n = 6 */
  sum_m += prod_n;

  /* m = 5 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+4];  /* n = 4 */
  prod_n *= xi - x[i-r+6];  /* n = 6 */
  sum_m += prod_n;

  /* m = 6 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+4];  /* n = 4 */
  prod_n *= xi - x[i-r+5];  /* n = 5 */
  sum_m += prod_n;

  prod_m = 1.0;
  prod_m *= x[i-r+3] - x[i-r+0];
  prod_m *= x[i-r+3] - x[i-r+1];
  prod_m *= x[i-r+3] - x[i-r+2];
  prod_m *= x[i-r+3] - x[i-r+4];
  prod_m *= x[i-r+3] - x[i-r+5];
  prod_m *= x[i-r+3] - x[i-r+6];

  sum_l += sum_m / prod_m * (x[i-r+1+1] - x[i-r+1]);

  /* l = 4 */
  sum_m = 0.0;

  /* m = 0 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  prod_n *= xi - x[i-r+5];  /* n = 5 */
  prod_n *= xi - x[i-r+6];  /* n = 6 */
  sum_m += prod_n;

  /* m = 1 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  prod_n *= xi - x[i-r+5];  /* n = 5 */
  prod_n *= xi - x[i-r+6];  /* n = 6 */
  sum_m += prod_n;

  /* m = 2 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  prod_n *= xi - x[i-r+5];  /* n = 5 */
  prod_n *= xi - x[i-r+6];  /* n = 6 */
  sum_m += prod_n;

  /* m = 3 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+5];  /* n = 5 */
  prod_n *= xi - x[i-r+6];  /* n = 6 */
  sum_m += prod_n;

  /* m = 5 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  prod_n *= xi - x[i-r+6];  /* n = 6 */
  sum_m += prod_n;

  /* m = 6 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  prod_n *= xi - x[i-r+5];  /* n = 5 */
  sum_m += prod_n;

  prod_m = 1.0;
  prod_m *= x[i-r+4] - x[i-r+0];
  prod_m *= x[i-r+4] - x[i-r+1];
  prod_m *= x[i-r+4] - x[i-r+2];
  prod_m *= x[i-r+4] - x[i-r+3];
  prod_m *= x[i-r+4] - x[i-r+5];
  prod_m *= x[i-r+4] - x[i-r+6];

  sum_l += sum_m / prod_m * (x[i-r+1+1] - x[i-r+1]);

  /* l = 5 */
  sum_m = 0.0;

  /* m = 0 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  prod_n *= xi - x[i-r+4];  /* n = 4 */
  prod_n *= xi - x[i-r+6];  /* n = 6 */
  sum_m += prod_n;

  /* m = 1 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  prod_n *= xi - x[i-r+4];  /* n = 4 */
  prod_n *= xi - x[i-r+6];  /* n = 6 */
  sum_m += prod_n;

  /* m = 2 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  prod_n *= xi - x[i-r+4];  /* n = 4 */
  prod_n *= xi - x[i-r+6];  /* n = 6 */
  sum_m += prod_n;

  /* m = 3 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+4];  /* n = 4 */
  prod_n *= xi - x[i-r+6];  /* n = 6 */
  sum_m += prod_n;

  /* m = 4 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  prod_n *= xi - x[i-r+6];  /* n = 6 */
  sum_m += prod_n;

  /* m = 6 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  prod_n *= xi - x[i-r+4];  /* n = 4 */
  sum_m += prod_n;

  prod_m = 1.0;
  prod_m *= x[i-r+5] - x[i-r+0];
  prod_m *= x[i-r+5] - x[i-r+1];
  prod_m *= x[i-r+5] - x[i-r+2];
  prod_m *= x[i-r+5] - x[i-r+3];
  prod_m *= x[i-r+5] - x[i-r+4];
  prod_m *= x[i-r+5] - x[i-r+6];

  sum_l += sum_m / prod_m * (x[i-r+1+1] - x[i-r+1]);

  /* l = 6 */
  sum_m = 0.0;

  /* m = 0 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  prod_n *= xi - x[i-r+4];  /* n = 4 */
  prod_n *= xi - x[i-r+5];  /* n = 5 */
  sum_m += prod_n;

  /* m = 1 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  prod_n *= xi - x[i-r+4];  /* n = 4 */
  prod_n *= xi - x[i-r+5];  /* n = 5 */
  sum_m += prod_n;

  /* m = 2 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  prod_n *= xi - x[i-r+4];  /* n = 4 */
  prod_n *= xi - x[i-r+5];  /* n = 5 */
  sum_m += prod_n;

  /* m = 3 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+4];  /* n = 4 */
  prod_n *= xi - x[i-r+5];  /* n = 5 */
  sum_m += prod_n;

  /* m = 4 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  prod_n *= xi - x[i-r+5];  /* n = 5 */
  sum_m += prod_n;

  /* m = 5 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  prod_n *= xi - x[i-r+4];  /* n = 4 */
  sum_m += prod_n;

  prod_m = 1.0;
  prod_m *= x[i-r+6] - x[i-r+0];
  prod_m *= x[i-r+6] - x[i-r+1];
  prod_m *= x[i-r+6] - x[i-r+2];
  prod_m *= x[i-r+6] - x[i-r+3];
  prod_m *= x[i-r+6] - x[i-r+4];
  prod_m *= x[i-r+6] - x[i-r+5];

  sum_l += sum_m / prod_m * (x[i-r+1+1] - x[i-r+1]);

  c[1] = sum_l;

  /* j = 2 */
  sum_l = 0.0;

  /* l = 3 */
  sum_m = 0.0;

  /* m = 0 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+4];  /* n = 4 */
  prod_n *= xi - x[i-r+5];  /* n = 5 */
  prod_n *= xi - x[i-r+6];  /* n = 6 */
  sum_m += prod_n;

  /* m = 1 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+4];  /* n = 4 */
  prod_n *= xi - x[i-r+5];  /* n = 5 */
  prod_n *= xi - x[i-r+6];  /* n = 6 */
  sum_m += prod_n;

  /* m = 2 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+4];  /* n = 4 */
  prod_n *= xi - x[i-r+5];  /* n = 5 */
  prod_n *= xi - x[i-r+6];  /* n = 6 */
  sum_m += prod_n;

  /* m = 4 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+5];  /* n = 5 */
  prod_n *= xi - x[i-r+6];  /* n = 6 */
  sum_m += prod_n;

  /* m = 5 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+4];  /* n = 4 */
  prod_n *= xi - x[i-r+6];  /* n = 6 */
  sum_m += prod_n;

  /* m = 6 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+4];  /* n = 4 */
  prod_n *= xi - x[i-r+5];  /* n = 5 */
  sum_m += prod_n;

  prod_m = 1.0;
  prod_m *= x[i-r+3] - x[i-r+0];
  prod_m *= x[i-r+3] - x[i-r+1];
  prod_m *= x[i-r+3] - x[i-r+2];
  prod_m *= x[i-r+3] - x[i-r+4];
  prod_m *= x[i-r+3] - x[i-r+5];
  prod_m *= x[i-r+3] - x[i-r+6];

  sum_l += sum_m / prod_m * (x[i-r+2+1] - x[i-r+2]);

  /* l = 4 */
  sum_m = 0.0;

  /* m = 0 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  prod_n *= xi - x[i-r+5];  /* n = 5 */
  prod_n *= xi - x[i-r+6];  /* n = 6 */
  sum_m += prod_n;

  /* m = 1 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  prod_n *= xi - x[i-r+5];  /* n = 5 */
  prod_n *= xi - x[i-r+6];  /* n = 6 */
  sum_m += prod_n;

  /* m = 2 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  prod_n *= xi - x[i-r+5];  /* n = 5 */
  prod_n *= xi - x[i-r+6];  /* n = 6 */
  sum_m += prod_n;

  /* m = 3 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+5];  /* n = 5 */
  prod_n *= xi - x[i-r+6];  /* n = 6 */
  sum_m += prod_n;

  /* m = 5 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  prod_n *= xi - x[i-r+6];  /* n = 6 */
  sum_m += prod_n;

  /* m = 6 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  prod_n *= xi - x[i-r+5];  /* n = 5 */
  sum_m += prod_n;

  prod_m = 1.0;
  prod_m *= x[i-r+4] - x[i-r+0];
  prod_m *= x[i-r+4] - x[i-r+1];
  prod_m *= x[i-r+4] - x[i-r+2];
  prod_m *= x[i-r+4] - x[i-r+3];
  prod_m *= x[i-r+4] - x[i-r+5];
  prod_m *= x[i-r+4] - x[i-r+6];

  sum_l += sum_m / prod_m * (x[i-r+2+1] - x[i-r+2]);

  /* l = 5 */
  sum_m = 0.0;

  /* m = 0 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  prod_n *= xi - x[i-r+4];  /* n = 4 */
  prod_n *= xi - x[i-r+6];  /* n = 6 */
  sum_m += prod_n;

  /* m = 1 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  prod_n *= xi - x[i-r+4];  /* n = 4 */
  prod_n *= xi - x[i-r+6];  /* n = 6 */
  sum_m += prod_n;

  /* m = 2 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  prod_n *= xi - x[i-r+4];  /* n = 4 */
  prod_n *= xi - x[i-r+6];  /* n = 6 */
  sum_m += prod_n;

  /* m = 3 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+4];  /* n = 4 */
  prod_n *= xi - x[i-r+6];  /* n = 6 */
  sum_m += prod_n;

  /* m = 4 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  prod_n *= xi - x[i-r+6];  /* n = 6 */
  sum_m += prod_n;

  /* m = 6 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  prod_n *= xi - x[i-r+4];  /* n = 4 */
  sum_m += prod_n;

  prod_m = 1.0;
  prod_m *= x[i-r+5] - x[i-r+0];
  prod_m *= x[i-r+5] - x[i-r+1];
  prod_m *= x[i-r+5] - x[i-r+2];
  prod_m *= x[i-r+5] - x[i-r+3];
  prod_m *= x[i-r+5] - x[i-r+4];
  prod_m *= x[i-r+5] - x[i-r+6];

  sum_l += sum_m / prod_m * (x[i-r+2+1] - x[i-r+2]);

  /* l = 6 */
  sum_m = 0.0;

  /* m = 0 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  prod_n *= xi - x[i-r+4];  /* n = 4 */
  prod_n *= xi - x[i-r+5];  /* n = 5 */
  sum_m += prod_n;

  /* m = 1 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  prod_n *= xi - x[i-r+4];  /* n = 4 */
  prod_n *= xi - x[i-r+5];  /* n = 5 */
  sum_m += prod_n;

  /* m = 2 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  prod_n *= xi - x[i-r+4];  /* n = 4 */
  prod_n *= xi - x[i-r+5];  /* n = 5 */
  sum_m += prod_n;

  /* m = 3 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+4];  /* n = 4 */
  prod_n *= xi - x[i-r+5];  /* n = 5 */
  sum_m += prod_n;

  /* m = 4 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  prod_n *= xi - x[i-r+5];  /* n = 5 */
  sum_m += prod_n;

  /* m = 5 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  prod_n *= xi - x[i-r+4];  /* n = 4 */
  sum_m += prod_n;

  prod_m = 1.0;
  prod_m *= x[i-r+6] - x[i-r+0];
  prod_m *= x[i-r+6] - x[i-r+1];
  prod_m *= x[i-r+6] - x[i-r+2];
  prod_m *= x[i-r+6] - x[i-r+3];
  prod_m *= x[i-r+6] - x[i-r+4];
  prod_m *= x[i-r+6] - x[i-r+5];

  sum_l += sum_m / prod_m * (x[i-r+2+1] - x[i-r+2]);

  c[2] = sum_l;

  /* j = 3 */
  sum_l = 0.0;

  /* l = 4 */
  sum_m = 0.0;

  /* m = 0 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  prod_n *= xi - x[i-r+5];  /* n = 5 */
  prod_n *= xi - x[i-r+6];  /* n = 6 */
  sum_m += prod_n;

  /* m = 1 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  prod_n *= xi - x[i-r+5];  /* n = 5 */
  prod_n *= xi - x[i-r+6];  /* n = 6 */
  sum_m += prod_n;

  /* m = 2 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  prod_n *= xi - x[i-r+5];  /* n = 5 */
  prod_n *= xi - x[i-r+6];  /* n = 6 */
  sum_m += prod_n;

  /* m = 3 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+5];  /* n = 5 */
  prod_n *= xi - x[i-r+6];  /* n = 6 */
  sum_m += prod_n;

  /* m = 5 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  prod_n *= xi - x[i-r+6];  /* n = 6 */
  sum_m += prod_n;

  /* m = 6 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  prod_n *= xi - x[i-r+5];  /* n = 5 */
  sum_m += prod_n;

  prod_m = 1.0;
  prod_m *= x[i-r+4] - x[i-r+0];
  prod_m *= x[i-r+4] - x[i-r+1];
  prod_m *= x[i-r+4] - x[i-r+2];
  prod_m *= x[i-r+4] - x[i-r+3];
  prod_m *= x[i-r+4] - x[i-r+5];
  prod_m *= x[i-r+4] - x[i-r+6];

  sum_l += sum_m / prod_m * (x[i-r+3+1] - x[i-r+3]);

  /* l = 5 */
  sum_m = 0.0;

  /* m = 0 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  prod_n *= xi - x[i-r+4];  /* n = 4 */
  prod_n *= xi - x[i-r+6];  /* n = 6 */
  sum_m += prod_n;

  /* m = 1 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  prod_n *= xi - x[i-r+4];  /* n = 4 */
  prod_n *= xi - x[i-r+6];  /* n = 6 */
  sum_m += prod_n;

  /* m = 2 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  prod_n *= xi - x[i-r+4];  /* n = 4 */
  prod_n *= xi - x[i-r+6];  /* n = 6 */
  sum_m += prod_n;

  /* m = 3 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+4];  /* n = 4 */
  prod_n *= xi - x[i-r+6];  /* n = 6 */
  sum_m += prod_n;

  /* m = 4 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  prod_n *= xi - x[i-r+6];  /* n = 6 */
  sum_m += prod_n;

  /* m = 6 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  prod_n *= xi - x[i-r+4];  /* n = 4 */
  sum_m += prod_n;

  prod_m = 1.0;
  prod_m *= x[i-r+5] - x[i-r+0];
  prod_m *= x[i-r+5] - x[i-r+1];
  prod_m *= x[i-r+5] - x[i-r+2];
  prod_m *= x[i-r+5] - x[i-r+3];
  prod_m *= x[i-r+5] - x[i-r+4];
  prod_m *= x[i-r+5] - x[i-r+6];

  sum_l += sum_m / prod_m * (x[i-r+3+1] - x[i-r+3]);

  /* l = 6 */
  sum_m = 0.0;

  /* m = 0 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  prod_n *= xi - x[i-r+4];  /* n = 4 */
  prod_n *= xi - x[i-r+5];  /* n = 5 */
  sum_m += prod_n;

  /* m = 1 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  prod_n *= xi - x[i-r+4];  /* n = 4 */
  prod_n *= xi - x[i-r+5];  /* n = 5 */
  sum_m += prod_n;

  /* m = 2 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  prod_n *= xi - x[i-r+4];  /* n = 4 */
  prod_n *= xi - x[i-r+5];  /* n = 5 */
  sum_m += prod_n;

  /* m = 3 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+4];  /* n = 4 */
  prod_n *= xi - x[i-r+5];  /* n = 5 */
  sum_m += prod_n;

  /* m = 4 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  prod_n *= xi - x[i-r+5];  /* n = 5 */
  sum_m += prod_n;

  /* m = 5 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  prod_n *= xi - x[i-r+4];  /* n = 4 */
  sum_m += prod_n;

  prod_m = 1.0;
  prod_m *= x[i-r+6] - x[i-r+0];
  prod_m *= x[i-r+6] - x[i-r+1];
  prod_m *= x[i-r+6] - x[i-r+2];
  prod_m *= x[i-r+6] - x[i-r+3];
  prod_m *= x[i-r+6] - x[i-r+4];
  prod_m *= x[i-r+6] - x[i-r+5];

  sum_l += sum_m / prod_m * (x[i-r+3+1] - x[i-r+3]);

  c[3] = sum_l;

  /* j = 4 */
  sum_l = 0.0;

  /* l = 5 */
  sum_m = 0.0;

  /* m = 0 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  prod_n *= xi - x[i-r+4];  /* n = 4 */
  prod_n *= xi - x[i-r+6];  /* n = 6 */
  sum_m += prod_n;

  /* m = 1 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  prod_n *= xi - x[i-r+4];  /* n = 4 */
  prod_n *= xi - x[i-r+6];  /* n = 6 */
  sum_m += prod_n;

  /* m = 2 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  prod_n *= xi - x[i-r+4];  /* n = 4 */
  prod_n *= xi - x[i-r+6];  /* n = 6 */
  sum_m += prod_n;

  /* m = 3 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+4];  /* n = 4 */
  prod_n *= xi - x[i-r+6];  /* n = 6 */
  sum_m += prod_n;

  /* m = 4 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  prod_n *= xi - x[i-r+6];  /* n = 6 */
  sum_m += prod_n;

  /* m = 6 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  prod_n *= xi - x[i-r+4];  /* n = 4 */
  sum_m += prod_n;

  prod_m = 1.0;
  prod_m *= x[i-r+5] - x[i-r+0];
  prod_m *= x[i-r+5] - x[i-r+1];
  prod_m *= x[i-r+5] - x[i-r+2];
  prod_m *= x[i-r+5] - x[i-r+3];
  prod_m *= x[i-r+5] - x[i-r+4];
  prod_m *= x[i-r+5] - x[i-r+6];

  sum_l += sum_m / prod_m * (x[i-r+4+1] - x[i-r+4]);

  /* l = 6 */
  sum_m = 0.0;

  /* m = 0 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  prod_n *= xi - x[i-r+4];  /* n = 4 */
  prod_n *= xi - x[i-r+5];  /* n = 5 */
  sum_m += prod_n;

  /* m = 1 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  prod_n *= xi - x[i-r+4];  /* n = 4 */
  prod_n *= xi - x[i-r+5];  /* n = 5 */
  sum_m += prod_n;

  /* m = 2 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  prod_n *= xi - x[i-r+4];  /* n = 4 */
  prod_n *= xi - x[i-r+5];  /* n = 5 */
  sum_m += prod_n;

  /* m = 3 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+4];  /* n = 4 */
  prod_n *= xi - x[i-r+5];  /* n = 5 */
  sum_m += prod_n;

  /* m = 4 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  prod_n *= xi - x[i-r+5];  /* n = 5 */
  sum_m += prod_n;

  /* m = 5 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  prod_n *= xi - x[i-r+4];  /* n = 4 */
  sum_m += prod_n;

  prod_m = 1.0;
  prod_m *= x[i-r+6] - x[i-r+0];
  prod_m *= x[i-r+6] - x[i-r+1];
  prod_m *= x[i-r+6] - x[i-r+2];
  prod_m *= x[i-r+6] - x[i-r+3];
  prod_m *= x[i-r+6] - x[i-r+4];
  prod_m *= x[i-r+6] - x[i-r+5];

  sum_l += sum_m / prod_m * (x[i-r+4+1] - x[i-r+4]);

  c[4] = sum_l;

  /* j = 5 */
  sum_l = 0.0;

  /* l = 6 */
  sum_m = 0.0;

  /* m = 0 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  prod_n *= xi - x[i-r+4];  /* n = 4 */
  prod_n *= xi - x[i-r+5];  /* n = 5 */
  sum_m += prod_n;

  /* m = 1 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  prod_n *= xi - x[i-r+4];  /* n = 4 */
  prod_n *= xi - x[i-r+5];  /* n = 5 */
  sum_m += prod_n;

  /* m = 2 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  prod_n *= xi - x[i-r+4];  /* n = 4 */
  prod_n *= xi - x[i-r+5];  /* n = 5 */
  sum_m += prod_n;

  /* m = 3 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+4];  /* n = 4 */
  prod_n *= xi - x[i-r+5];  /* n = 5 */
  sum_m += prod_n;

  /* m = 4 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  prod_n *= xi - x[i-r+5];  /* n = 5 */
  sum_m += prod_n;

  /* m = 5 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  prod_n *= xi - x[i-r+4];  /* n = 4 */
  sum_m += prod_n;

  prod_m = 1.0;
  prod_m *= x[i-r+6] - x[i-r+0];
  prod_m *= x[i-r+6] - x[i-r+1];
  prod_m *= x[i-r+6] - x[i-r+2];
  prod_m *= x[i-r+6] - x[i-r+3];
  prod_m *= x[i-r+6] - x[i-r+4];
  prod_m *= x[i-r+6] - x[i-r+5];

  sum_l += sum_m / prod_m * (x[i-r+5+1] - x[i-r+5]);

  c[5] = sum_l;
}

PyObject *
reconstruction_coeffs_k6_d0_py(PyObject *self, PyObject *args)
{
  double *x, *c, xi;
  long int i;
  int r;

  PyObject *bndry, *coeffs;

  /*
   * parse options
   */

  if (! PyArg_ParseTuple(args, "dlidOO", &xi, &i, &r, &bndry, &coeffs))
    return NULL;

  if ((PyArray_FLAGS(bndry) & NPY_IN_ARRAY) != NPY_IN_ARRAY) {
    PyErr_SetString(PyExc_TypeError, "bndry is not contiguous and/or aligned");
    return NULL;
  }
  Py_INCREF(bndry);
  x = (double *) PyArray_DATA(bndry);

  if ((PyArray_FLAGS(coeffs) & NPY_IN_ARRAY) != NPY_IN_ARRAY) {
    PyErr_SetString(PyExc_TypeError, "coeffs is not contiguous and/or aligned");
    return NULL;
  }
  Py_INCREF(coeffs);
  c = (double *) PyArray_DATA(coeffs);

  /*
   * dispatch
   */

  reconstruction_coeffs_k6_d0(xi, i, r, x, c);

  /*
   * done
   */
  Py_INCREF(Py_None);
  return Py_None;
}

void
reconstruction_coeffs_k7_d0(double xi, long int i, int r, double *x, double *c)
{
  double sum_l, sum_m, prod_n, prod_m;

  /*
   * compute reconstruction coeffs of order 7
   */


  /* j = 0 */
  sum_l = 0.0;

  /* l = 1 */
  sum_m = 0.0;

  /* m = 0 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  prod_n *= xi - x[i-r+4];  /* n = 4 */
  prod_n *= xi - x[i-r+5];  /* n = 5 */
  prod_n *= xi - x[i-r+6];  /* n = 6 */
  prod_n *= xi - x[i-r+7];  /* n = 7 */
  sum_m += prod_n;

  /* m = 2 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  prod_n *= xi - x[i-r+4];  /* n = 4 */
  prod_n *= xi - x[i-r+5];  /* n = 5 */
  prod_n *= xi - x[i-r+6];  /* n = 6 */
  prod_n *= xi - x[i-r+7];  /* n = 7 */
  sum_m += prod_n;

  /* m = 3 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+4];  /* n = 4 */
  prod_n *= xi - x[i-r+5];  /* n = 5 */
  prod_n *= xi - x[i-r+6];  /* n = 6 */
  prod_n *= xi - x[i-r+7];  /* n = 7 */
  sum_m += prod_n;

  /* m = 4 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  prod_n *= xi - x[i-r+5];  /* n = 5 */
  prod_n *= xi - x[i-r+6];  /* n = 6 */
  prod_n *= xi - x[i-r+7];  /* n = 7 */
  sum_m += prod_n;

  /* m = 5 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  prod_n *= xi - x[i-r+4];  /* n = 4 */
  prod_n *= xi - x[i-r+6];  /* n = 6 */
  prod_n *= xi - x[i-r+7];  /* n = 7 */
  sum_m += prod_n;

  /* m = 6 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  prod_n *= xi - x[i-r+4];  /* n = 4 */
  prod_n *= xi - x[i-r+5];  /* n = 5 */
  prod_n *= xi - x[i-r+7];  /* n = 7 */
  sum_m += prod_n;

  /* m = 7 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  prod_n *= xi - x[i-r+4];  /* n = 4 */
  prod_n *= xi - x[i-r+5];  /* n = 5 */
  prod_n *= xi - x[i-r+6];  /* n = 6 */
  sum_m += prod_n;

  prod_m = 1.0;
  prod_m *= x[i-r+1] - x[i-r+0];
  prod_m *= x[i-r+1] - x[i-r+2];
  prod_m *= x[i-r+1] - x[i-r+3];
  prod_m *= x[i-r+1] - x[i-r+4];
  prod_m *= x[i-r+1] - x[i-r+5];
  prod_m *= x[i-r+1] - x[i-r+6];
  prod_m *= x[i-r+1] - x[i-r+7];

  sum_l += sum_m / prod_m * (x[i-r+0+1] - x[i-r+0]);

  /* l = 2 */
  sum_m = 0.0;

  /* m = 0 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  prod_n *= xi - x[i-r+4];  /* n = 4 */
  prod_n *= xi - x[i-r+5];  /* n = 5 */
  prod_n *= xi - x[i-r+6];  /* n = 6 */
  prod_n *= xi - x[i-r+7];  /* n = 7 */
  sum_m += prod_n;

  /* m = 1 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  prod_n *= xi - x[i-r+4];  /* n = 4 */
  prod_n *= xi - x[i-r+5];  /* n = 5 */
  prod_n *= xi - x[i-r+6];  /* n = 6 */
  prod_n *= xi - x[i-r+7];  /* n = 7 */
  sum_m += prod_n;

  /* m = 3 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+4];  /* n = 4 */
  prod_n *= xi - x[i-r+5];  /* n = 5 */
  prod_n *= xi - x[i-r+6];  /* n = 6 */
  prod_n *= xi - x[i-r+7];  /* n = 7 */
  sum_m += prod_n;

  /* m = 4 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  prod_n *= xi - x[i-r+5];  /* n = 5 */
  prod_n *= xi - x[i-r+6];  /* n = 6 */
  prod_n *= xi - x[i-r+7];  /* n = 7 */
  sum_m += prod_n;

  /* m = 5 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  prod_n *= xi - x[i-r+4];  /* n = 4 */
  prod_n *= xi - x[i-r+6];  /* n = 6 */
  prod_n *= xi - x[i-r+7];  /* n = 7 */
  sum_m += prod_n;

  /* m = 6 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  prod_n *= xi - x[i-r+4];  /* n = 4 */
  prod_n *= xi - x[i-r+5];  /* n = 5 */
  prod_n *= xi - x[i-r+7];  /* n = 7 */
  sum_m += prod_n;

  /* m = 7 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  prod_n *= xi - x[i-r+4];  /* n = 4 */
  prod_n *= xi - x[i-r+5];  /* n = 5 */
  prod_n *= xi - x[i-r+6];  /* n = 6 */
  sum_m += prod_n;

  prod_m = 1.0;
  prod_m *= x[i-r+2] - x[i-r+0];
  prod_m *= x[i-r+2] - x[i-r+1];
  prod_m *= x[i-r+2] - x[i-r+3];
  prod_m *= x[i-r+2] - x[i-r+4];
  prod_m *= x[i-r+2] - x[i-r+5];
  prod_m *= x[i-r+2] - x[i-r+6];
  prod_m *= x[i-r+2] - x[i-r+7];

  sum_l += sum_m / prod_m * (x[i-r+0+1] - x[i-r+0]);

  /* l = 3 */
  sum_m = 0.0;

  /* m = 0 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+4];  /* n = 4 */
  prod_n *= xi - x[i-r+5];  /* n = 5 */
  prod_n *= xi - x[i-r+6];  /* n = 6 */
  prod_n *= xi - x[i-r+7];  /* n = 7 */
  sum_m += prod_n;

  /* m = 1 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+4];  /* n = 4 */
  prod_n *= xi - x[i-r+5];  /* n = 5 */
  prod_n *= xi - x[i-r+6];  /* n = 6 */
  prod_n *= xi - x[i-r+7];  /* n = 7 */
  sum_m += prod_n;

  /* m = 2 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+4];  /* n = 4 */
  prod_n *= xi - x[i-r+5];  /* n = 5 */
  prod_n *= xi - x[i-r+6];  /* n = 6 */
  prod_n *= xi - x[i-r+7];  /* n = 7 */
  sum_m += prod_n;

  /* m = 4 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+5];  /* n = 5 */
  prod_n *= xi - x[i-r+6];  /* n = 6 */
  prod_n *= xi - x[i-r+7];  /* n = 7 */
  sum_m += prod_n;

  /* m = 5 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+4];  /* n = 4 */
  prod_n *= xi - x[i-r+6];  /* n = 6 */
  prod_n *= xi - x[i-r+7];  /* n = 7 */
  sum_m += prod_n;

  /* m = 6 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+4];  /* n = 4 */
  prod_n *= xi - x[i-r+5];  /* n = 5 */
  prod_n *= xi - x[i-r+7];  /* n = 7 */
  sum_m += prod_n;

  /* m = 7 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+4];  /* n = 4 */
  prod_n *= xi - x[i-r+5];  /* n = 5 */
  prod_n *= xi - x[i-r+6];  /* n = 6 */
  sum_m += prod_n;

  prod_m = 1.0;
  prod_m *= x[i-r+3] - x[i-r+0];
  prod_m *= x[i-r+3] - x[i-r+1];
  prod_m *= x[i-r+3] - x[i-r+2];
  prod_m *= x[i-r+3] - x[i-r+4];
  prod_m *= x[i-r+3] - x[i-r+5];
  prod_m *= x[i-r+3] - x[i-r+6];
  prod_m *= x[i-r+3] - x[i-r+7];

  sum_l += sum_m / prod_m * (x[i-r+0+1] - x[i-r+0]);

  /* l = 4 */
  sum_m = 0.0;

  /* m = 0 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  prod_n *= xi - x[i-r+5];  /* n = 5 */
  prod_n *= xi - x[i-r+6];  /* n = 6 */
  prod_n *= xi - x[i-r+7];  /* n = 7 */
  sum_m += prod_n;

  /* m = 1 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  prod_n *= xi - x[i-r+5];  /* n = 5 */
  prod_n *= xi - x[i-r+6];  /* n = 6 */
  prod_n *= xi - x[i-r+7];  /* n = 7 */
  sum_m += prod_n;

  /* m = 2 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  prod_n *= xi - x[i-r+5];  /* n = 5 */
  prod_n *= xi - x[i-r+6];  /* n = 6 */
  prod_n *= xi - x[i-r+7];  /* n = 7 */
  sum_m += prod_n;

  /* m = 3 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+5];  /* n = 5 */
  prod_n *= xi - x[i-r+6];  /* n = 6 */
  prod_n *= xi - x[i-r+7];  /* n = 7 */
  sum_m += prod_n;

  /* m = 5 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  prod_n *= xi - x[i-r+6];  /* n = 6 */
  prod_n *= xi - x[i-r+7];  /* n = 7 */
  sum_m += prod_n;

  /* m = 6 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  prod_n *= xi - x[i-r+5];  /* n = 5 */
  prod_n *= xi - x[i-r+7];  /* n = 7 */
  sum_m += prod_n;

  /* m = 7 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  prod_n *= xi - x[i-r+5];  /* n = 5 */
  prod_n *= xi - x[i-r+6];  /* n = 6 */
  sum_m += prod_n;

  prod_m = 1.0;
  prod_m *= x[i-r+4] - x[i-r+0];
  prod_m *= x[i-r+4] - x[i-r+1];
  prod_m *= x[i-r+4] - x[i-r+2];
  prod_m *= x[i-r+4] - x[i-r+3];
  prod_m *= x[i-r+4] - x[i-r+5];
  prod_m *= x[i-r+4] - x[i-r+6];
  prod_m *= x[i-r+4] - x[i-r+7];

  sum_l += sum_m / prod_m * (x[i-r+0+1] - x[i-r+0]);

  /* l = 5 */
  sum_m = 0.0;

  /* m = 0 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  prod_n *= xi - x[i-r+4];  /* n = 4 */
  prod_n *= xi - x[i-r+6];  /* n = 6 */
  prod_n *= xi - x[i-r+7];  /* n = 7 */
  sum_m += prod_n;

  /* m = 1 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  prod_n *= xi - x[i-r+4];  /* n = 4 */
  prod_n *= xi - x[i-r+6];  /* n = 6 */
  prod_n *= xi - x[i-r+7];  /* n = 7 */
  sum_m += prod_n;

  /* m = 2 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  prod_n *= xi - x[i-r+4];  /* n = 4 */
  prod_n *= xi - x[i-r+6];  /* n = 6 */
  prod_n *= xi - x[i-r+7];  /* n = 7 */
  sum_m += prod_n;

  /* m = 3 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+4];  /* n = 4 */
  prod_n *= xi - x[i-r+6];  /* n = 6 */
  prod_n *= xi - x[i-r+7];  /* n = 7 */
  sum_m += prod_n;

  /* m = 4 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  prod_n *= xi - x[i-r+6];  /* n = 6 */
  prod_n *= xi - x[i-r+7];  /* n = 7 */
  sum_m += prod_n;

  /* m = 6 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  prod_n *= xi - x[i-r+4];  /* n = 4 */
  prod_n *= xi - x[i-r+7];  /* n = 7 */
  sum_m += prod_n;

  /* m = 7 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  prod_n *= xi - x[i-r+4];  /* n = 4 */
  prod_n *= xi - x[i-r+6];  /* n = 6 */
  sum_m += prod_n;

  prod_m = 1.0;
  prod_m *= x[i-r+5] - x[i-r+0];
  prod_m *= x[i-r+5] - x[i-r+1];
  prod_m *= x[i-r+5] - x[i-r+2];
  prod_m *= x[i-r+5] - x[i-r+3];
  prod_m *= x[i-r+5] - x[i-r+4];
  prod_m *= x[i-r+5] - x[i-r+6];
  prod_m *= x[i-r+5] - x[i-r+7];

  sum_l += sum_m / prod_m * (x[i-r+0+1] - x[i-r+0]);

  /* l = 6 */
  sum_m = 0.0;

  /* m = 0 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  prod_n *= xi - x[i-r+4];  /* n = 4 */
  prod_n *= xi - x[i-r+5];  /* n = 5 */
  prod_n *= xi - x[i-r+7];  /* n = 7 */
  sum_m += prod_n;

  /* m = 1 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  prod_n *= xi - x[i-r+4];  /* n = 4 */
  prod_n *= xi - x[i-r+5];  /* n = 5 */
  prod_n *= xi - x[i-r+7];  /* n = 7 */
  sum_m += prod_n;

  /* m = 2 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  prod_n *= xi - x[i-r+4];  /* n = 4 */
  prod_n *= xi - x[i-r+5];  /* n = 5 */
  prod_n *= xi - x[i-r+7];  /* n = 7 */
  sum_m += prod_n;

  /* m = 3 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+4];  /* n = 4 */
  prod_n *= xi - x[i-r+5];  /* n = 5 */
  prod_n *= xi - x[i-r+7];  /* n = 7 */
  sum_m += prod_n;

  /* m = 4 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  prod_n *= xi - x[i-r+5];  /* n = 5 */
  prod_n *= xi - x[i-r+7];  /* n = 7 */
  sum_m += prod_n;

  /* m = 5 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  prod_n *= xi - x[i-r+4];  /* n = 4 */
  prod_n *= xi - x[i-r+7];  /* n = 7 */
  sum_m += prod_n;

  /* m = 7 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  prod_n *= xi - x[i-r+4];  /* n = 4 */
  prod_n *= xi - x[i-r+5];  /* n = 5 */
  sum_m += prod_n;

  prod_m = 1.0;
  prod_m *= x[i-r+6] - x[i-r+0];
  prod_m *= x[i-r+6] - x[i-r+1];
  prod_m *= x[i-r+6] - x[i-r+2];
  prod_m *= x[i-r+6] - x[i-r+3];
  prod_m *= x[i-r+6] - x[i-r+4];
  prod_m *= x[i-r+6] - x[i-r+5];
  prod_m *= x[i-r+6] - x[i-r+7];

  sum_l += sum_m / prod_m * (x[i-r+0+1] - x[i-r+0]);

  /* l = 7 */
  sum_m = 0.0;

  /* m = 0 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  prod_n *= xi - x[i-r+4];  /* n = 4 */
  prod_n *= xi - x[i-r+5];  /* n = 5 */
  prod_n *= xi - x[i-r+6];  /* n = 6 */
  sum_m += prod_n;

  /* m = 1 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  prod_n *= xi - x[i-r+4];  /* n = 4 */
  prod_n *= xi - x[i-r+5];  /* n = 5 */
  prod_n *= xi - x[i-r+6];  /* n = 6 */
  sum_m += prod_n;

  /* m = 2 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  prod_n *= xi - x[i-r+4];  /* n = 4 */
  prod_n *= xi - x[i-r+5];  /* n = 5 */
  prod_n *= xi - x[i-r+6];  /* n = 6 */
  sum_m += prod_n;

  /* m = 3 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+4];  /* n = 4 */
  prod_n *= xi - x[i-r+5];  /* n = 5 */
  prod_n *= xi - x[i-r+6];  /* n = 6 */
  sum_m += prod_n;

  /* m = 4 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  prod_n *= xi - x[i-r+5];  /* n = 5 */
  prod_n *= xi - x[i-r+6];  /* n = 6 */
  sum_m += prod_n;

  /* m = 5 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  prod_n *= xi - x[i-r+4];  /* n = 4 */
  prod_n *= xi - x[i-r+6];  /* n = 6 */
  sum_m += prod_n;

  /* m = 6 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  prod_n *= xi - x[i-r+4];  /* n = 4 */
  prod_n *= xi - x[i-r+5];  /* n = 5 */
  sum_m += prod_n;

  prod_m = 1.0;
  prod_m *= x[i-r+7] - x[i-r+0];
  prod_m *= x[i-r+7] - x[i-r+1];
  prod_m *= x[i-r+7] - x[i-r+2];
  prod_m *= x[i-r+7] - x[i-r+3];
  prod_m *= x[i-r+7] - x[i-r+4];
  prod_m *= x[i-r+7] - x[i-r+5];
  prod_m *= x[i-r+7] - x[i-r+6];

  sum_l += sum_m / prod_m * (x[i-r+0+1] - x[i-r+0]);

  c[0] = sum_l;

  /* j = 1 */
  sum_l = 0.0;

  /* l = 2 */
  sum_m = 0.0;

  /* m = 0 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  prod_n *= xi - x[i-r+4];  /* n = 4 */
  prod_n *= xi - x[i-r+5];  /* n = 5 */
  prod_n *= xi - x[i-r+6];  /* n = 6 */
  prod_n *= xi - x[i-r+7];  /* n = 7 */
  sum_m += prod_n;

  /* m = 1 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  prod_n *= xi - x[i-r+4];  /* n = 4 */
  prod_n *= xi - x[i-r+5];  /* n = 5 */
  prod_n *= xi - x[i-r+6];  /* n = 6 */
  prod_n *= xi - x[i-r+7];  /* n = 7 */
  sum_m += prod_n;

  /* m = 3 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+4];  /* n = 4 */
  prod_n *= xi - x[i-r+5];  /* n = 5 */
  prod_n *= xi - x[i-r+6];  /* n = 6 */
  prod_n *= xi - x[i-r+7];  /* n = 7 */
  sum_m += prod_n;

  /* m = 4 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  prod_n *= xi - x[i-r+5];  /* n = 5 */
  prod_n *= xi - x[i-r+6];  /* n = 6 */
  prod_n *= xi - x[i-r+7];  /* n = 7 */
  sum_m += prod_n;

  /* m = 5 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  prod_n *= xi - x[i-r+4];  /* n = 4 */
  prod_n *= xi - x[i-r+6];  /* n = 6 */
  prod_n *= xi - x[i-r+7];  /* n = 7 */
  sum_m += prod_n;

  /* m = 6 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  prod_n *= xi - x[i-r+4];  /* n = 4 */
  prod_n *= xi - x[i-r+5];  /* n = 5 */
  prod_n *= xi - x[i-r+7];  /* n = 7 */
  sum_m += prod_n;

  /* m = 7 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  prod_n *= xi - x[i-r+4];  /* n = 4 */
  prod_n *= xi - x[i-r+5];  /* n = 5 */
  prod_n *= xi - x[i-r+6];  /* n = 6 */
  sum_m += prod_n;

  prod_m = 1.0;
  prod_m *= x[i-r+2] - x[i-r+0];
  prod_m *= x[i-r+2] - x[i-r+1];
  prod_m *= x[i-r+2] - x[i-r+3];
  prod_m *= x[i-r+2] - x[i-r+4];
  prod_m *= x[i-r+2] - x[i-r+5];
  prod_m *= x[i-r+2] - x[i-r+6];
  prod_m *= x[i-r+2] - x[i-r+7];

  sum_l += sum_m / prod_m * (x[i-r+1+1] - x[i-r+1]);

  /* l = 3 */
  sum_m = 0.0;

  /* m = 0 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+4];  /* n = 4 */
  prod_n *= xi - x[i-r+5];  /* n = 5 */
  prod_n *= xi - x[i-r+6];  /* n = 6 */
  prod_n *= xi - x[i-r+7];  /* n = 7 */
  sum_m += prod_n;

  /* m = 1 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+4];  /* n = 4 */
  prod_n *= xi - x[i-r+5];  /* n = 5 */
  prod_n *= xi - x[i-r+6];  /* n = 6 */
  prod_n *= xi - x[i-r+7];  /* n = 7 */
  sum_m += prod_n;

  /* m = 2 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+4];  /* n = 4 */
  prod_n *= xi - x[i-r+5];  /* n = 5 */
  prod_n *= xi - x[i-r+6];  /* n = 6 */
  prod_n *= xi - x[i-r+7];  /* n = 7 */
  sum_m += prod_n;

  /* m = 4 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+5];  /* n = 5 */
  prod_n *= xi - x[i-r+6];  /* n = 6 */
  prod_n *= xi - x[i-r+7];  /* n = 7 */
  sum_m += prod_n;

  /* m = 5 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+4];  /* n = 4 */
  prod_n *= xi - x[i-r+6];  /* n = 6 */
  prod_n *= xi - x[i-r+7];  /* n = 7 */
  sum_m += prod_n;

  /* m = 6 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+4];  /* n = 4 */
  prod_n *= xi - x[i-r+5];  /* n = 5 */
  prod_n *= xi - x[i-r+7];  /* n = 7 */
  sum_m += prod_n;

  /* m = 7 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+4];  /* n = 4 */
  prod_n *= xi - x[i-r+5];  /* n = 5 */
  prod_n *= xi - x[i-r+6];  /* n = 6 */
  sum_m += prod_n;

  prod_m = 1.0;
  prod_m *= x[i-r+3] - x[i-r+0];
  prod_m *= x[i-r+3] - x[i-r+1];
  prod_m *= x[i-r+3] - x[i-r+2];
  prod_m *= x[i-r+3] - x[i-r+4];
  prod_m *= x[i-r+3] - x[i-r+5];
  prod_m *= x[i-r+3] - x[i-r+6];
  prod_m *= x[i-r+3] - x[i-r+7];

  sum_l += sum_m / prod_m * (x[i-r+1+1] - x[i-r+1]);

  /* l = 4 */
  sum_m = 0.0;

  /* m = 0 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  prod_n *= xi - x[i-r+5];  /* n = 5 */
  prod_n *= xi - x[i-r+6];  /* n = 6 */
  prod_n *= xi - x[i-r+7];  /* n = 7 */
  sum_m += prod_n;

  /* m = 1 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  prod_n *= xi - x[i-r+5];  /* n = 5 */
  prod_n *= xi - x[i-r+6];  /* n = 6 */
  prod_n *= xi - x[i-r+7];  /* n = 7 */
  sum_m += prod_n;

  /* m = 2 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  prod_n *= xi - x[i-r+5];  /* n = 5 */
  prod_n *= xi - x[i-r+6];  /* n = 6 */
  prod_n *= xi - x[i-r+7];  /* n = 7 */
  sum_m += prod_n;

  /* m = 3 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+5];  /* n = 5 */
  prod_n *= xi - x[i-r+6];  /* n = 6 */
  prod_n *= xi - x[i-r+7];  /* n = 7 */
  sum_m += prod_n;

  /* m = 5 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  prod_n *= xi - x[i-r+6];  /* n = 6 */
  prod_n *= xi - x[i-r+7];  /* n = 7 */
  sum_m += prod_n;

  /* m = 6 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  prod_n *= xi - x[i-r+5];  /* n = 5 */
  prod_n *= xi - x[i-r+7];  /* n = 7 */
  sum_m += prod_n;

  /* m = 7 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  prod_n *= xi - x[i-r+5];  /* n = 5 */
  prod_n *= xi - x[i-r+6];  /* n = 6 */
  sum_m += prod_n;

  prod_m = 1.0;
  prod_m *= x[i-r+4] - x[i-r+0];
  prod_m *= x[i-r+4] - x[i-r+1];
  prod_m *= x[i-r+4] - x[i-r+2];
  prod_m *= x[i-r+4] - x[i-r+3];
  prod_m *= x[i-r+4] - x[i-r+5];
  prod_m *= x[i-r+4] - x[i-r+6];
  prod_m *= x[i-r+4] - x[i-r+7];

  sum_l += sum_m / prod_m * (x[i-r+1+1] - x[i-r+1]);

  /* l = 5 */
  sum_m = 0.0;

  /* m = 0 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  prod_n *= xi - x[i-r+4];  /* n = 4 */
  prod_n *= xi - x[i-r+6];  /* n = 6 */
  prod_n *= xi - x[i-r+7];  /* n = 7 */
  sum_m += prod_n;

  /* m = 1 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  prod_n *= xi - x[i-r+4];  /* n = 4 */
  prod_n *= xi - x[i-r+6];  /* n = 6 */
  prod_n *= xi - x[i-r+7];  /* n = 7 */
  sum_m += prod_n;

  /* m = 2 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  prod_n *= xi - x[i-r+4];  /* n = 4 */
  prod_n *= xi - x[i-r+6];  /* n = 6 */
  prod_n *= xi - x[i-r+7];  /* n = 7 */
  sum_m += prod_n;

  /* m = 3 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+4];  /* n = 4 */
  prod_n *= xi - x[i-r+6];  /* n = 6 */
  prod_n *= xi - x[i-r+7];  /* n = 7 */
  sum_m += prod_n;

  /* m = 4 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  prod_n *= xi - x[i-r+6];  /* n = 6 */
  prod_n *= xi - x[i-r+7];  /* n = 7 */
  sum_m += prod_n;

  /* m = 6 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  prod_n *= xi - x[i-r+4];  /* n = 4 */
  prod_n *= xi - x[i-r+7];  /* n = 7 */
  sum_m += prod_n;

  /* m = 7 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  prod_n *= xi - x[i-r+4];  /* n = 4 */
  prod_n *= xi - x[i-r+6];  /* n = 6 */
  sum_m += prod_n;

  prod_m = 1.0;
  prod_m *= x[i-r+5] - x[i-r+0];
  prod_m *= x[i-r+5] - x[i-r+1];
  prod_m *= x[i-r+5] - x[i-r+2];
  prod_m *= x[i-r+5] - x[i-r+3];
  prod_m *= x[i-r+5] - x[i-r+4];
  prod_m *= x[i-r+5] - x[i-r+6];
  prod_m *= x[i-r+5] - x[i-r+7];

  sum_l += sum_m / prod_m * (x[i-r+1+1] - x[i-r+1]);

  /* l = 6 */
  sum_m = 0.0;

  /* m = 0 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  prod_n *= xi - x[i-r+4];  /* n = 4 */
  prod_n *= xi - x[i-r+5];  /* n = 5 */
  prod_n *= xi - x[i-r+7];  /* n = 7 */
  sum_m += prod_n;

  /* m = 1 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  prod_n *= xi - x[i-r+4];  /* n = 4 */
  prod_n *= xi - x[i-r+5];  /* n = 5 */
  prod_n *= xi - x[i-r+7];  /* n = 7 */
  sum_m += prod_n;

  /* m = 2 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  prod_n *= xi - x[i-r+4];  /* n = 4 */
  prod_n *= xi - x[i-r+5];  /* n = 5 */
  prod_n *= xi - x[i-r+7];  /* n = 7 */
  sum_m += prod_n;

  /* m = 3 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+4];  /* n = 4 */
  prod_n *= xi - x[i-r+5];  /* n = 5 */
  prod_n *= xi - x[i-r+7];  /* n = 7 */
  sum_m += prod_n;

  /* m = 4 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  prod_n *= xi - x[i-r+5];  /* n = 5 */
  prod_n *= xi - x[i-r+7];  /* n = 7 */
  sum_m += prod_n;

  /* m = 5 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  prod_n *= xi - x[i-r+4];  /* n = 4 */
  prod_n *= xi - x[i-r+7];  /* n = 7 */
  sum_m += prod_n;

  /* m = 7 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  prod_n *= xi - x[i-r+4];  /* n = 4 */
  prod_n *= xi - x[i-r+5];  /* n = 5 */
  sum_m += prod_n;

  prod_m = 1.0;
  prod_m *= x[i-r+6] - x[i-r+0];
  prod_m *= x[i-r+6] - x[i-r+1];
  prod_m *= x[i-r+6] - x[i-r+2];
  prod_m *= x[i-r+6] - x[i-r+3];
  prod_m *= x[i-r+6] - x[i-r+4];
  prod_m *= x[i-r+6] - x[i-r+5];
  prod_m *= x[i-r+6] - x[i-r+7];

  sum_l += sum_m / prod_m * (x[i-r+1+1] - x[i-r+1]);

  /* l = 7 */
  sum_m = 0.0;

  /* m = 0 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  prod_n *= xi - x[i-r+4];  /* n = 4 */
  prod_n *= xi - x[i-r+5];  /* n = 5 */
  prod_n *= xi - x[i-r+6];  /* n = 6 */
  sum_m += prod_n;

  /* m = 1 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  prod_n *= xi - x[i-r+4];  /* n = 4 */
  prod_n *= xi - x[i-r+5];  /* n = 5 */
  prod_n *= xi - x[i-r+6];  /* n = 6 */
  sum_m += prod_n;

  /* m = 2 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  prod_n *= xi - x[i-r+4];  /* n = 4 */
  prod_n *= xi - x[i-r+5];  /* n = 5 */
  prod_n *= xi - x[i-r+6];  /* n = 6 */
  sum_m += prod_n;

  /* m = 3 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+4];  /* n = 4 */
  prod_n *= xi - x[i-r+5];  /* n = 5 */
  prod_n *= xi - x[i-r+6];  /* n = 6 */
  sum_m += prod_n;

  /* m = 4 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  prod_n *= xi - x[i-r+5];  /* n = 5 */
  prod_n *= xi - x[i-r+6];  /* n = 6 */
  sum_m += prod_n;

  /* m = 5 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  prod_n *= xi - x[i-r+4];  /* n = 4 */
  prod_n *= xi - x[i-r+6];  /* n = 6 */
  sum_m += prod_n;

  /* m = 6 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  prod_n *= xi - x[i-r+4];  /* n = 4 */
  prod_n *= xi - x[i-r+5];  /* n = 5 */
  sum_m += prod_n;

  prod_m = 1.0;
  prod_m *= x[i-r+7] - x[i-r+0];
  prod_m *= x[i-r+7] - x[i-r+1];
  prod_m *= x[i-r+7] - x[i-r+2];
  prod_m *= x[i-r+7] - x[i-r+3];
  prod_m *= x[i-r+7] - x[i-r+4];
  prod_m *= x[i-r+7] - x[i-r+5];
  prod_m *= x[i-r+7] - x[i-r+6];

  sum_l += sum_m / prod_m * (x[i-r+1+1] - x[i-r+1]);

  c[1] = sum_l;

  /* j = 2 */
  sum_l = 0.0;

  /* l = 3 */
  sum_m = 0.0;

  /* m = 0 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+4];  /* n = 4 */
  prod_n *= xi - x[i-r+5];  /* n = 5 */
  prod_n *= xi - x[i-r+6];  /* n = 6 */
  prod_n *= xi - x[i-r+7];  /* n = 7 */
  sum_m += prod_n;

  /* m = 1 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+4];  /* n = 4 */
  prod_n *= xi - x[i-r+5];  /* n = 5 */
  prod_n *= xi - x[i-r+6];  /* n = 6 */
  prod_n *= xi - x[i-r+7];  /* n = 7 */
  sum_m += prod_n;

  /* m = 2 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+4];  /* n = 4 */
  prod_n *= xi - x[i-r+5];  /* n = 5 */
  prod_n *= xi - x[i-r+6];  /* n = 6 */
  prod_n *= xi - x[i-r+7];  /* n = 7 */
  sum_m += prod_n;

  /* m = 4 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+5];  /* n = 5 */
  prod_n *= xi - x[i-r+6];  /* n = 6 */
  prod_n *= xi - x[i-r+7];  /* n = 7 */
  sum_m += prod_n;

  /* m = 5 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+4];  /* n = 4 */
  prod_n *= xi - x[i-r+6];  /* n = 6 */
  prod_n *= xi - x[i-r+7];  /* n = 7 */
  sum_m += prod_n;

  /* m = 6 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+4];  /* n = 4 */
  prod_n *= xi - x[i-r+5];  /* n = 5 */
  prod_n *= xi - x[i-r+7];  /* n = 7 */
  sum_m += prod_n;

  /* m = 7 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+4];  /* n = 4 */
  prod_n *= xi - x[i-r+5];  /* n = 5 */
  prod_n *= xi - x[i-r+6];  /* n = 6 */
  sum_m += prod_n;

  prod_m = 1.0;
  prod_m *= x[i-r+3] - x[i-r+0];
  prod_m *= x[i-r+3] - x[i-r+1];
  prod_m *= x[i-r+3] - x[i-r+2];
  prod_m *= x[i-r+3] - x[i-r+4];
  prod_m *= x[i-r+3] - x[i-r+5];
  prod_m *= x[i-r+3] - x[i-r+6];
  prod_m *= x[i-r+3] - x[i-r+7];

  sum_l += sum_m / prod_m * (x[i-r+2+1] - x[i-r+2]);

  /* l = 4 */
  sum_m = 0.0;

  /* m = 0 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  prod_n *= xi - x[i-r+5];  /* n = 5 */
  prod_n *= xi - x[i-r+6];  /* n = 6 */
  prod_n *= xi - x[i-r+7];  /* n = 7 */
  sum_m += prod_n;

  /* m = 1 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  prod_n *= xi - x[i-r+5];  /* n = 5 */
  prod_n *= xi - x[i-r+6];  /* n = 6 */
  prod_n *= xi - x[i-r+7];  /* n = 7 */
  sum_m += prod_n;

  /* m = 2 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  prod_n *= xi - x[i-r+5];  /* n = 5 */
  prod_n *= xi - x[i-r+6];  /* n = 6 */
  prod_n *= xi - x[i-r+7];  /* n = 7 */
  sum_m += prod_n;

  /* m = 3 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+5];  /* n = 5 */
  prod_n *= xi - x[i-r+6];  /* n = 6 */
  prod_n *= xi - x[i-r+7];  /* n = 7 */
  sum_m += prod_n;

  /* m = 5 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  prod_n *= xi - x[i-r+6];  /* n = 6 */
  prod_n *= xi - x[i-r+7];  /* n = 7 */
  sum_m += prod_n;

  /* m = 6 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  prod_n *= xi - x[i-r+5];  /* n = 5 */
  prod_n *= xi - x[i-r+7];  /* n = 7 */
  sum_m += prod_n;

  /* m = 7 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  prod_n *= xi - x[i-r+5];  /* n = 5 */
  prod_n *= xi - x[i-r+6];  /* n = 6 */
  sum_m += prod_n;

  prod_m = 1.0;
  prod_m *= x[i-r+4] - x[i-r+0];
  prod_m *= x[i-r+4] - x[i-r+1];
  prod_m *= x[i-r+4] - x[i-r+2];
  prod_m *= x[i-r+4] - x[i-r+3];
  prod_m *= x[i-r+4] - x[i-r+5];
  prod_m *= x[i-r+4] - x[i-r+6];
  prod_m *= x[i-r+4] - x[i-r+7];

  sum_l += sum_m / prod_m * (x[i-r+2+1] - x[i-r+2]);

  /* l = 5 */
  sum_m = 0.0;

  /* m = 0 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  prod_n *= xi - x[i-r+4];  /* n = 4 */
  prod_n *= xi - x[i-r+6];  /* n = 6 */
  prod_n *= xi - x[i-r+7];  /* n = 7 */
  sum_m += prod_n;

  /* m = 1 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  prod_n *= xi - x[i-r+4];  /* n = 4 */
  prod_n *= xi - x[i-r+6];  /* n = 6 */
  prod_n *= xi - x[i-r+7];  /* n = 7 */
  sum_m += prod_n;

  /* m = 2 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  prod_n *= xi - x[i-r+4];  /* n = 4 */
  prod_n *= xi - x[i-r+6];  /* n = 6 */
  prod_n *= xi - x[i-r+7];  /* n = 7 */
  sum_m += prod_n;

  /* m = 3 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+4];  /* n = 4 */
  prod_n *= xi - x[i-r+6];  /* n = 6 */
  prod_n *= xi - x[i-r+7];  /* n = 7 */
  sum_m += prod_n;

  /* m = 4 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  prod_n *= xi - x[i-r+6];  /* n = 6 */
  prod_n *= xi - x[i-r+7];  /* n = 7 */
  sum_m += prod_n;

  /* m = 6 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  prod_n *= xi - x[i-r+4];  /* n = 4 */
  prod_n *= xi - x[i-r+7];  /* n = 7 */
  sum_m += prod_n;

  /* m = 7 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  prod_n *= xi - x[i-r+4];  /* n = 4 */
  prod_n *= xi - x[i-r+6];  /* n = 6 */
  sum_m += prod_n;

  prod_m = 1.0;
  prod_m *= x[i-r+5] - x[i-r+0];
  prod_m *= x[i-r+5] - x[i-r+1];
  prod_m *= x[i-r+5] - x[i-r+2];
  prod_m *= x[i-r+5] - x[i-r+3];
  prod_m *= x[i-r+5] - x[i-r+4];
  prod_m *= x[i-r+5] - x[i-r+6];
  prod_m *= x[i-r+5] - x[i-r+7];

  sum_l += sum_m / prod_m * (x[i-r+2+1] - x[i-r+2]);

  /* l = 6 */
  sum_m = 0.0;

  /* m = 0 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  prod_n *= xi - x[i-r+4];  /* n = 4 */
  prod_n *= xi - x[i-r+5];  /* n = 5 */
  prod_n *= xi - x[i-r+7];  /* n = 7 */
  sum_m += prod_n;

  /* m = 1 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  prod_n *= xi - x[i-r+4];  /* n = 4 */
  prod_n *= xi - x[i-r+5];  /* n = 5 */
  prod_n *= xi - x[i-r+7];  /* n = 7 */
  sum_m += prod_n;

  /* m = 2 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  prod_n *= xi - x[i-r+4];  /* n = 4 */
  prod_n *= xi - x[i-r+5];  /* n = 5 */
  prod_n *= xi - x[i-r+7];  /* n = 7 */
  sum_m += prod_n;

  /* m = 3 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+4];  /* n = 4 */
  prod_n *= xi - x[i-r+5];  /* n = 5 */
  prod_n *= xi - x[i-r+7];  /* n = 7 */
  sum_m += prod_n;

  /* m = 4 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  prod_n *= xi - x[i-r+5];  /* n = 5 */
  prod_n *= xi - x[i-r+7];  /* n = 7 */
  sum_m += prod_n;

  /* m = 5 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  prod_n *= xi - x[i-r+4];  /* n = 4 */
  prod_n *= xi - x[i-r+7];  /* n = 7 */
  sum_m += prod_n;

  /* m = 7 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  prod_n *= xi - x[i-r+4];  /* n = 4 */
  prod_n *= xi - x[i-r+5];  /* n = 5 */
  sum_m += prod_n;

  prod_m = 1.0;
  prod_m *= x[i-r+6] - x[i-r+0];
  prod_m *= x[i-r+6] - x[i-r+1];
  prod_m *= x[i-r+6] - x[i-r+2];
  prod_m *= x[i-r+6] - x[i-r+3];
  prod_m *= x[i-r+6] - x[i-r+4];
  prod_m *= x[i-r+6] - x[i-r+5];
  prod_m *= x[i-r+6] - x[i-r+7];

  sum_l += sum_m / prod_m * (x[i-r+2+1] - x[i-r+2]);

  /* l = 7 */
  sum_m = 0.0;

  /* m = 0 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  prod_n *= xi - x[i-r+4];  /* n = 4 */
  prod_n *= xi - x[i-r+5];  /* n = 5 */
  prod_n *= xi - x[i-r+6];  /* n = 6 */
  sum_m += prod_n;

  /* m = 1 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  prod_n *= xi - x[i-r+4];  /* n = 4 */
  prod_n *= xi - x[i-r+5];  /* n = 5 */
  prod_n *= xi - x[i-r+6];  /* n = 6 */
  sum_m += prod_n;

  /* m = 2 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  prod_n *= xi - x[i-r+4];  /* n = 4 */
  prod_n *= xi - x[i-r+5];  /* n = 5 */
  prod_n *= xi - x[i-r+6];  /* n = 6 */
  sum_m += prod_n;

  /* m = 3 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+4];  /* n = 4 */
  prod_n *= xi - x[i-r+5];  /* n = 5 */
  prod_n *= xi - x[i-r+6];  /* n = 6 */
  sum_m += prod_n;

  /* m = 4 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  prod_n *= xi - x[i-r+5];  /* n = 5 */
  prod_n *= xi - x[i-r+6];  /* n = 6 */
  sum_m += prod_n;

  /* m = 5 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  prod_n *= xi - x[i-r+4];  /* n = 4 */
  prod_n *= xi - x[i-r+6];  /* n = 6 */
  sum_m += prod_n;

  /* m = 6 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  prod_n *= xi - x[i-r+4];  /* n = 4 */
  prod_n *= xi - x[i-r+5];  /* n = 5 */
  sum_m += prod_n;

  prod_m = 1.0;
  prod_m *= x[i-r+7] - x[i-r+0];
  prod_m *= x[i-r+7] - x[i-r+1];
  prod_m *= x[i-r+7] - x[i-r+2];
  prod_m *= x[i-r+7] - x[i-r+3];
  prod_m *= x[i-r+7] - x[i-r+4];
  prod_m *= x[i-r+7] - x[i-r+5];
  prod_m *= x[i-r+7] - x[i-r+6];

  sum_l += sum_m / prod_m * (x[i-r+2+1] - x[i-r+2]);

  c[2] = sum_l;

  /* j = 3 */
  sum_l = 0.0;

  /* l = 4 */
  sum_m = 0.0;

  /* m = 0 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  prod_n *= xi - x[i-r+5];  /* n = 5 */
  prod_n *= xi - x[i-r+6];  /* n = 6 */
  prod_n *= xi - x[i-r+7];  /* n = 7 */
  sum_m += prod_n;

  /* m = 1 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  prod_n *= xi - x[i-r+5];  /* n = 5 */
  prod_n *= xi - x[i-r+6];  /* n = 6 */
  prod_n *= xi - x[i-r+7];  /* n = 7 */
  sum_m += prod_n;

  /* m = 2 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  prod_n *= xi - x[i-r+5];  /* n = 5 */
  prod_n *= xi - x[i-r+6];  /* n = 6 */
  prod_n *= xi - x[i-r+7];  /* n = 7 */
  sum_m += prod_n;

  /* m = 3 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+5];  /* n = 5 */
  prod_n *= xi - x[i-r+6];  /* n = 6 */
  prod_n *= xi - x[i-r+7];  /* n = 7 */
  sum_m += prod_n;

  /* m = 5 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  prod_n *= xi - x[i-r+6];  /* n = 6 */
  prod_n *= xi - x[i-r+7];  /* n = 7 */
  sum_m += prod_n;

  /* m = 6 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  prod_n *= xi - x[i-r+5];  /* n = 5 */
  prod_n *= xi - x[i-r+7];  /* n = 7 */
  sum_m += prod_n;

  /* m = 7 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  prod_n *= xi - x[i-r+5];  /* n = 5 */
  prod_n *= xi - x[i-r+6];  /* n = 6 */
  sum_m += prod_n;

  prod_m = 1.0;
  prod_m *= x[i-r+4] - x[i-r+0];
  prod_m *= x[i-r+4] - x[i-r+1];
  prod_m *= x[i-r+4] - x[i-r+2];
  prod_m *= x[i-r+4] - x[i-r+3];
  prod_m *= x[i-r+4] - x[i-r+5];
  prod_m *= x[i-r+4] - x[i-r+6];
  prod_m *= x[i-r+4] - x[i-r+7];

  sum_l += sum_m / prod_m * (x[i-r+3+1] - x[i-r+3]);

  /* l = 5 */
  sum_m = 0.0;

  /* m = 0 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  prod_n *= xi - x[i-r+4];  /* n = 4 */
  prod_n *= xi - x[i-r+6];  /* n = 6 */
  prod_n *= xi - x[i-r+7];  /* n = 7 */
  sum_m += prod_n;

  /* m = 1 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  prod_n *= xi - x[i-r+4];  /* n = 4 */
  prod_n *= xi - x[i-r+6];  /* n = 6 */
  prod_n *= xi - x[i-r+7];  /* n = 7 */
  sum_m += prod_n;

  /* m = 2 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  prod_n *= xi - x[i-r+4];  /* n = 4 */
  prod_n *= xi - x[i-r+6];  /* n = 6 */
  prod_n *= xi - x[i-r+7];  /* n = 7 */
  sum_m += prod_n;

  /* m = 3 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+4];  /* n = 4 */
  prod_n *= xi - x[i-r+6];  /* n = 6 */
  prod_n *= xi - x[i-r+7];  /* n = 7 */
  sum_m += prod_n;

  /* m = 4 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  prod_n *= xi - x[i-r+6];  /* n = 6 */
  prod_n *= xi - x[i-r+7];  /* n = 7 */
  sum_m += prod_n;

  /* m = 6 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  prod_n *= xi - x[i-r+4];  /* n = 4 */
  prod_n *= xi - x[i-r+7];  /* n = 7 */
  sum_m += prod_n;

  /* m = 7 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  prod_n *= xi - x[i-r+4];  /* n = 4 */
  prod_n *= xi - x[i-r+6];  /* n = 6 */
  sum_m += prod_n;

  prod_m = 1.0;
  prod_m *= x[i-r+5] - x[i-r+0];
  prod_m *= x[i-r+5] - x[i-r+1];
  prod_m *= x[i-r+5] - x[i-r+2];
  prod_m *= x[i-r+5] - x[i-r+3];
  prod_m *= x[i-r+5] - x[i-r+4];
  prod_m *= x[i-r+5] - x[i-r+6];
  prod_m *= x[i-r+5] - x[i-r+7];

  sum_l += sum_m / prod_m * (x[i-r+3+1] - x[i-r+3]);

  /* l = 6 */
  sum_m = 0.0;

  /* m = 0 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  prod_n *= xi - x[i-r+4];  /* n = 4 */
  prod_n *= xi - x[i-r+5];  /* n = 5 */
  prod_n *= xi - x[i-r+7];  /* n = 7 */
  sum_m += prod_n;

  /* m = 1 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  prod_n *= xi - x[i-r+4];  /* n = 4 */
  prod_n *= xi - x[i-r+5];  /* n = 5 */
  prod_n *= xi - x[i-r+7];  /* n = 7 */
  sum_m += prod_n;

  /* m = 2 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  prod_n *= xi - x[i-r+4];  /* n = 4 */
  prod_n *= xi - x[i-r+5];  /* n = 5 */
  prod_n *= xi - x[i-r+7];  /* n = 7 */
  sum_m += prod_n;

  /* m = 3 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+4];  /* n = 4 */
  prod_n *= xi - x[i-r+5];  /* n = 5 */
  prod_n *= xi - x[i-r+7];  /* n = 7 */
  sum_m += prod_n;

  /* m = 4 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  prod_n *= xi - x[i-r+5];  /* n = 5 */
  prod_n *= xi - x[i-r+7];  /* n = 7 */
  sum_m += prod_n;

  /* m = 5 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  prod_n *= xi - x[i-r+4];  /* n = 4 */
  prod_n *= xi - x[i-r+7];  /* n = 7 */
  sum_m += prod_n;

  /* m = 7 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  prod_n *= xi - x[i-r+4];  /* n = 4 */
  prod_n *= xi - x[i-r+5];  /* n = 5 */
  sum_m += prod_n;

  prod_m = 1.0;
  prod_m *= x[i-r+6] - x[i-r+0];
  prod_m *= x[i-r+6] - x[i-r+1];
  prod_m *= x[i-r+6] - x[i-r+2];
  prod_m *= x[i-r+6] - x[i-r+3];
  prod_m *= x[i-r+6] - x[i-r+4];
  prod_m *= x[i-r+6] - x[i-r+5];
  prod_m *= x[i-r+6] - x[i-r+7];

  sum_l += sum_m / prod_m * (x[i-r+3+1] - x[i-r+3]);

  /* l = 7 */
  sum_m = 0.0;

  /* m = 0 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  prod_n *= xi - x[i-r+4];  /* n = 4 */
  prod_n *= xi - x[i-r+5];  /* n = 5 */
  prod_n *= xi - x[i-r+6];  /* n = 6 */
  sum_m += prod_n;

  /* m = 1 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  prod_n *= xi - x[i-r+4];  /* n = 4 */
  prod_n *= xi - x[i-r+5];  /* n = 5 */
  prod_n *= xi - x[i-r+6];  /* n = 6 */
  sum_m += prod_n;

  /* m = 2 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  prod_n *= xi - x[i-r+4];  /* n = 4 */
  prod_n *= xi - x[i-r+5];  /* n = 5 */
  prod_n *= xi - x[i-r+6];  /* n = 6 */
  sum_m += prod_n;

  /* m = 3 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+4];  /* n = 4 */
  prod_n *= xi - x[i-r+5];  /* n = 5 */
  prod_n *= xi - x[i-r+6];  /* n = 6 */
  sum_m += prod_n;

  /* m = 4 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  prod_n *= xi - x[i-r+5];  /* n = 5 */
  prod_n *= xi - x[i-r+6];  /* n = 6 */
  sum_m += prod_n;

  /* m = 5 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  prod_n *= xi - x[i-r+4];  /* n = 4 */
  prod_n *= xi - x[i-r+6];  /* n = 6 */
  sum_m += prod_n;

  /* m = 6 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  prod_n *= xi - x[i-r+4];  /* n = 4 */
  prod_n *= xi - x[i-r+5];  /* n = 5 */
  sum_m += prod_n;

  prod_m = 1.0;
  prod_m *= x[i-r+7] - x[i-r+0];
  prod_m *= x[i-r+7] - x[i-r+1];
  prod_m *= x[i-r+7] - x[i-r+2];
  prod_m *= x[i-r+7] - x[i-r+3];
  prod_m *= x[i-r+7] - x[i-r+4];
  prod_m *= x[i-r+7] - x[i-r+5];
  prod_m *= x[i-r+7] - x[i-r+6];

  sum_l += sum_m / prod_m * (x[i-r+3+1] - x[i-r+3]);

  c[3] = sum_l;

  /* j = 4 */
  sum_l = 0.0;

  /* l = 5 */
  sum_m = 0.0;

  /* m = 0 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  prod_n *= xi - x[i-r+4];  /* n = 4 */
  prod_n *= xi - x[i-r+6];  /* n = 6 */
  prod_n *= xi - x[i-r+7];  /* n = 7 */
  sum_m += prod_n;

  /* m = 1 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  prod_n *= xi - x[i-r+4];  /* n = 4 */
  prod_n *= xi - x[i-r+6];  /* n = 6 */
  prod_n *= xi - x[i-r+7];  /* n = 7 */
  sum_m += prod_n;

  /* m = 2 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  prod_n *= xi - x[i-r+4];  /* n = 4 */
  prod_n *= xi - x[i-r+6];  /* n = 6 */
  prod_n *= xi - x[i-r+7];  /* n = 7 */
  sum_m += prod_n;

  /* m = 3 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+4];  /* n = 4 */
  prod_n *= xi - x[i-r+6];  /* n = 6 */
  prod_n *= xi - x[i-r+7];  /* n = 7 */
  sum_m += prod_n;

  /* m = 4 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  prod_n *= xi - x[i-r+6];  /* n = 6 */
  prod_n *= xi - x[i-r+7];  /* n = 7 */
  sum_m += prod_n;

  /* m = 6 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  prod_n *= xi - x[i-r+4];  /* n = 4 */
  prod_n *= xi - x[i-r+7];  /* n = 7 */
  sum_m += prod_n;

  /* m = 7 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  prod_n *= xi - x[i-r+4];  /* n = 4 */
  prod_n *= xi - x[i-r+6];  /* n = 6 */
  sum_m += prod_n;

  prod_m = 1.0;
  prod_m *= x[i-r+5] - x[i-r+0];
  prod_m *= x[i-r+5] - x[i-r+1];
  prod_m *= x[i-r+5] - x[i-r+2];
  prod_m *= x[i-r+5] - x[i-r+3];
  prod_m *= x[i-r+5] - x[i-r+4];
  prod_m *= x[i-r+5] - x[i-r+6];
  prod_m *= x[i-r+5] - x[i-r+7];

  sum_l += sum_m / prod_m * (x[i-r+4+1] - x[i-r+4]);

  /* l = 6 */
  sum_m = 0.0;

  /* m = 0 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  prod_n *= xi - x[i-r+4];  /* n = 4 */
  prod_n *= xi - x[i-r+5];  /* n = 5 */
  prod_n *= xi - x[i-r+7];  /* n = 7 */
  sum_m += prod_n;

  /* m = 1 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  prod_n *= xi - x[i-r+4];  /* n = 4 */
  prod_n *= xi - x[i-r+5];  /* n = 5 */
  prod_n *= xi - x[i-r+7];  /* n = 7 */
  sum_m += prod_n;

  /* m = 2 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  prod_n *= xi - x[i-r+4];  /* n = 4 */
  prod_n *= xi - x[i-r+5];  /* n = 5 */
  prod_n *= xi - x[i-r+7];  /* n = 7 */
  sum_m += prod_n;

  /* m = 3 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+4];  /* n = 4 */
  prod_n *= xi - x[i-r+5];  /* n = 5 */
  prod_n *= xi - x[i-r+7];  /* n = 7 */
  sum_m += prod_n;

  /* m = 4 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  prod_n *= xi - x[i-r+5];  /* n = 5 */
  prod_n *= xi - x[i-r+7];  /* n = 7 */
  sum_m += prod_n;

  /* m = 5 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  prod_n *= xi - x[i-r+4];  /* n = 4 */
  prod_n *= xi - x[i-r+7];  /* n = 7 */
  sum_m += prod_n;

  /* m = 7 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  prod_n *= xi - x[i-r+4];  /* n = 4 */
  prod_n *= xi - x[i-r+5];  /* n = 5 */
  sum_m += prod_n;

  prod_m = 1.0;
  prod_m *= x[i-r+6] - x[i-r+0];
  prod_m *= x[i-r+6] - x[i-r+1];
  prod_m *= x[i-r+6] - x[i-r+2];
  prod_m *= x[i-r+6] - x[i-r+3];
  prod_m *= x[i-r+6] - x[i-r+4];
  prod_m *= x[i-r+6] - x[i-r+5];
  prod_m *= x[i-r+6] - x[i-r+7];

  sum_l += sum_m / prod_m * (x[i-r+4+1] - x[i-r+4]);

  /* l = 7 */
  sum_m = 0.0;

  /* m = 0 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  prod_n *= xi - x[i-r+4];  /* n = 4 */
  prod_n *= xi - x[i-r+5];  /* n = 5 */
  prod_n *= xi - x[i-r+6];  /* n = 6 */
  sum_m += prod_n;

  /* m = 1 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  prod_n *= xi - x[i-r+4];  /* n = 4 */
  prod_n *= xi - x[i-r+5];  /* n = 5 */
  prod_n *= xi - x[i-r+6];  /* n = 6 */
  sum_m += prod_n;

  /* m = 2 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  prod_n *= xi - x[i-r+4];  /* n = 4 */
  prod_n *= xi - x[i-r+5];  /* n = 5 */
  prod_n *= xi - x[i-r+6];  /* n = 6 */
  sum_m += prod_n;

  /* m = 3 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+4];  /* n = 4 */
  prod_n *= xi - x[i-r+5];  /* n = 5 */
  prod_n *= xi - x[i-r+6];  /* n = 6 */
  sum_m += prod_n;

  /* m = 4 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  prod_n *= xi - x[i-r+5];  /* n = 5 */
  prod_n *= xi - x[i-r+6];  /* n = 6 */
  sum_m += prod_n;

  /* m = 5 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  prod_n *= xi - x[i-r+4];  /* n = 4 */
  prod_n *= xi - x[i-r+6];  /* n = 6 */
  sum_m += prod_n;

  /* m = 6 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  prod_n *= xi - x[i-r+4];  /* n = 4 */
  prod_n *= xi - x[i-r+5];  /* n = 5 */
  sum_m += prod_n;

  prod_m = 1.0;
  prod_m *= x[i-r+7] - x[i-r+0];
  prod_m *= x[i-r+7] - x[i-r+1];
  prod_m *= x[i-r+7] - x[i-r+2];
  prod_m *= x[i-r+7] - x[i-r+3];
  prod_m *= x[i-r+7] - x[i-r+4];
  prod_m *= x[i-r+7] - x[i-r+5];
  prod_m *= x[i-r+7] - x[i-r+6];

  sum_l += sum_m / prod_m * (x[i-r+4+1] - x[i-r+4]);

  c[4] = sum_l;

  /* j = 5 */
  sum_l = 0.0;

  /* l = 6 */
  sum_m = 0.0;

  /* m = 0 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  prod_n *= xi - x[i-r+4];  /* n = 4 */
  prod_n *= xi - x[i-r+5];  /* n = 5 */
  prod_n *= xi - x[i-r+7];  /* n = 7 */
  sum_m += prod_n;

  /* m = 1 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  prod_n *= xi - x[i-r+4];  /* n = 4 */
  prod_n *= xi - x[i-r+5];  /* n = 5 */
  prod_n *= xi - x[i-r+7];  /* n = 7 */
  sum_m += prod_n;

  /* m = 2 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  prod_n *= xi - x[i-r+4];  /* n = 4 */
  prod_n *= xi - x[i-r+5];  /* n = 5 */
  prod_n *= xi - x[i-r+7];  /* n = 7 */
  sum_m += prod_n;

  /* m = 3 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+4];  /* n = 4 */
  prod_n *= xi - x[i-r+5];  /* n = 5 */
  prod_n *= xi - x[i-r+7];  /* n = 7 */
  sum_m += prod_n;

  /* m = 4 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  prod_n *= xi - x[i-r+5];  /* n = 5 */
  prod_n *= xi - x[i-r+7];  /* n = 7 */
  sum_m += prod_n;

  /* m = 5 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  prod_n *= xi - x[i-r+4];  /* n = 4 */
  prod_n *= xi - x[i-r+7];  /* n = 7 */
  sum_m += prod_n;

  /* m = 7 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  prod_n *= xi - x[i-r+4];  /* n = 4 */
  prod_n *= xi - x[i-r+5];  /* n = 5 */
  sum_m += prod_n;

  prod_m = 1.0;
  prod_m *= x[i-r+6] - x[i-r+0];
  prod_m *= x[i-r+6] - x[i-r+1];
  prod_m *= x[i-r+6] - x[i-r+2];
  prod_m *= x[i-r+6] - x[i-r+3];
  prod_m *= x[i-r+6] - x[i-r+4];
  prod_m *= x[i-r+6] - x[i-r+5];
  prod_m *= x[i-r+6] - x[i-r+7];

  sum_l += sum_m / prod_m * (x[i-r+5+1] - x[i-r+5]);

  /* l = 7 */
  sum_m = 0.0;

  /* m = 0 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  prod_n *= xi - x[i-r+4];  /* n = 4 */
  prod_n *= xi - x[i-r+5];  /* n = 5 */
  prod_n *= xi - x[i-r+6];  /* n = 6 */
  sum_m += prod_n;

  /* m = 1 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  prod_n *= xi - x[i-r+4];  /* n = 4 */
  prod_n *= xi - x[i-r+5];  /* n = 5 */
  prod_n *= xi - x[i-r+6];  /* n = 6 */
  sum_m += prod_n;

  /* m = 2 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  prod_n *= xi - x[i-r+4];  /* n = 4 */
  prod_n *= xi - x[i-r+5];  /* n = 5 */
  prod_n *= xi - x[i-r+6];  /* n = 6 */
  sum_m += prod_n;

  /* m = 3 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+4];  /* n = 4 */
  prod_n *= xi - x[i-r+5];  /* n = 5 */
  prod_n *= xi - x[i-r+6];  /* n = 6 */
  sum_m += prod_n;

  /* m = 4 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  prod_n *= xi - x[i-r+5];  /* n = 5 */
  prod_n *= xi - x[i-r+6];  /* n = 6 */
  sum_m += prod_n;

  /* m = 5 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  prod_n *= xi - x[i-r+4];  /* n = 4 */
  prod_n *= xi - x[i-r+6];  /* n = 6 */
  sum_m += prod_n;

  /* m = 6 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  prod_n *= xi - x[i-r+4];  /* n = 4 */
  prod_n *= xi - x[i-r+5];  /* n = 5 */
  sum_m += prod_n;

  prod_m = 1.0;
  prod_m *= x[i-r+7] - x[i-r+0];
  prod_m *= x[i-r+7] - x[i-r+1];
  prod_m *= x[i-r+7] - x[i-r+2];
  prod_m *= x[i-r+7] - x[i-r+3];
  prod_m *= x[i-r+7] - x[i-r+4];
  prod_m *= x[i-r+7] - x[i-r+5];
  prod_m *= x[i-r+7] - x[i-r+6];

  sum_l += sum_m / prod_m * (x[i-r+5+1] - x[i-r+5]);

  c[5] = sum_l;

  /* j = 6 */
  sum_l = 0.0;

  /* l = 7 */
  sum_m = 0.0;

  /* m = 0 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  prod_n *= xi - x[i-r+4];  /* n = 4 */
  prod_n *= xi - x[i-r+5];  /* n = 5 */
  prod_n *= xi - x[i-r+6];  /* n = 6 */
  sum_m += prod_n;

  /* m = 1 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  prod_n *= xi - x[i-r+4];  /* n = 4 */
  prod_n *= xi - x[i-r+5];  /* n = 5 */
  prod_n *= xi - x[i-r+6];  /* n = 6 */
  sum_m += prod_n;

  /* m = 2 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  prod_n *= xi - x[i-r+4];  /* n = 4 */
  prod_n *= xi - x[i-r+5];  /* n = 5 */
  prod_n *= xi - x[i-r+6];  /* n = 6 */
  sum_m += prod_n;

  /* m = 3 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+4];  /* n = 4 */
  prod_n *= xi - x[i-r+5];  /* n = 5 */
  prod_n *= xi - x[i-r+6];  /* n = 6 */
  sum_m += prod_n;

  /* m = 4 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  prod_n *= xi - x[i-r+5];  /* n = 5 */
  prod_n *= xi - x[i-r+6];  /* n = 6 */
  sum_m += prod_n;

  /* m = 5 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  prod_n *= xi - x[i-r+4];  /* n = 4 */
  prod_n *= xi - x[i-r+6];  /* n = 6 */
  sum_m += prod_n;

  /* m = 6 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  prod_n *= xi - x[i-r+4];  /* n = 4 */
  prod_n *= xi - x[i-r+5];  /* n = 5 */
  sum_m += prod_n;

  prod_m = 1.0;
  prod_m *= x[i-r+7] - x[i-r+0];
  prod_m *= x[i-r+7] - x[i-r+1];
  prod_m *= x[i-r+7] - x[i-r+2];
  prod_m *= x[i-r+7] - x[i-r+3];
  prod_m *= x[i-r+7] - x[i-r+4];
  prod_m *= x[i-r+7] - x[i-r+5];
  prod_m *= x[i-r+7] - x[i-r+6];

  sum_l += sum_m / prod_m * (x[i-r+6+1] - x[i-r+6]);

  c[6] = sum_l;
}

PyObject *
reconstruction_coeffs_k7_d0_py(PyObject *self, PyObject *args)
{
  double *x, *c, xi;
  long int i;
  int r;

  PyObject *bndry, *coeffs;

  /*
   * parse options
   */

  if (! PyArg_ParseTuple(args, "dlidOO", &xi, &i, &r, &bndry, &coeffs))
    return NULL;

  if ((PyArray_FLAGS(bndry) & NPY_IN_ARRAY) != NPY_IN_ARRAY) {
    PyErr_SetString(PyExc_TypeError, "bndry is not contiguous and/or aligned");
    return NULL;
  }
  Py_INCREF(bndry);
  x = (double *) PyArray_DATA(bndry);

  if ((PyArray_FLAGS(coeffs) & NPY_IN_ARRAY) != NPY_IN_ARRAY) {
    PyErr_SetString(PyExc_TypeError, "coeffs is not contiguous and/or aligned");
    return NULL;
  }
  Py_INCREF(coeffs);
  c = (double *) PyArray_DATA(coeffs);

  /*
   * dispatch
   */

  reconstruction_coeffs_k7_d0(xi, i, r, x, c);

  /*
   * done
   */
  Py_INCREF(Py_None);
  return Py_None;
}

void
reconstruction_coeffs_k8_d0(double xi, long int i, int r, double *x, double *c)
{
  double sum_l, sum_m, prod_n, prod_m;

  /*
   * compute reconstruction coeffs of order 8
   */


  /* j = 0 */
  sum_l = 0.0;

  /* l = 1 */
  sum_m = 0.0;

  /* m = 0 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  prod_n *= xi - x[i-r+4];  /* n = 4 */
  prod_n *= xi - x[i-r+5];  /* n = 5 */
  prod_n *= xi - x[i-r+6];  /* n = 6 */
  prod_n *= xi - x[i-r+7];  /* n = 7 */
  prod_n *= xi - x[i-r+8];  /* n = 8 */
  sum_m += prod_n;

  /* m = 2 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  prod_n *= xi - x[i-r+4];  /* n = 4 */
  prod_n *= xi - x[i-r+5];  /* n = 5 */
  prod_n *= xi - x[i-r+6];  /* n = 6 */
  prod_n *= xi - x[i-r+7];  /* n = 7 */
  prod_n *= xi - x[i-r+8];  /* n = 8 */
  sum_m += prod_n;

  /* m = 3 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+4];  /* n = 4 */
  prod_n *= xi - x[i-r+5];  /* n = 5 */
  prod_n *= xi - x[i-r+6];  /* n = 6 */
  prod_n *= xi - x[i-r+7];  /* n = 7 */
  prod_n *= xi - x[i-r+8];  /* n = 8 */
  sum_m += prod_n;

  /* m = 4 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  prod_n *= xi - x[i-r+5];  /* n = 5 */
  prod_n *= xi - x[i-r+6];  /* n = 6 */
  prod_n *= xi - x[i-r+7];  /* n = 7 */
  prod_n *= xi - x[i-r+8];  /* n = 8 */
  sum_m += prod_n;

  /* m = 5 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  prod_n *= xi - x[i-r+4];  /* n = 4 */
  prod_n *= xi - x[i-r+6];  /* n = 6 */
  prod_n *= xi - x[i-r+7];  /* n = 7 */
  prod_n *= xi - x[i-r+8];  /* n = 8 */
  sum_m += prod_n;

  /* m = 6 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  prod_n *= xi - x[i-r+4];  /* n = 4 */
  prod_n *= xi - x[i-r+5];  /* n = 5 */
  prod_n *= xi - x[i-r+7];  /* n = 7 */
  prod_n *= xi - x[i-r+8];  /* n = 8 */
  sum_m += prod_n;

  /* m = 7 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  prod_n *= xi - x[i-r+4];  /* n = 4 */
  prod_n *= xi - x[i-r+5];  /* n = 5 */
  prod_n *= xi - x[i-r+6];  /* n = 6 */
  prod_n *= xi - x[i-r+8];  /* n = 8 */
  sum_m += prod_n;

  /* m = 8 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  prod_n *= xi - x[i-r+4];  /* n = 4 */
  prod_n *= xi - x[i-r+5];  /* n = 5 */
  prod_n *= xi - x[i-r+6];  /* n = 6 */
  prod_n *= xi - x[i-r+7];  /* n = 7 */
  sum_m += prod_n;

  prod_m = 1.0;
  prod_m *= x[i-r+1] - x[i-r+0];
  prod_m *= x[i-r+1] - x[i-r+2];
  prod_m *= x[i-r+1] - x[i-r+3];
  prod_m *= x[i-r+1] - x[i-r+4];
  prod_m *= x[i-r+1] - x[i-r+5];
  prod_m *= x[i-r+1] - x[i-r+6];
  prod_m *= x[i-r+1] - x[i-r+7];
  prod_m *= x[i-r+1] - x[i-r+8];

  sum_l += sum_m / prod_m * (x[i-r+0+1] - x[i-r+0]);

  /* l = 2 */
  sum_m = 0.0;

  /* m = 0 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  prod_n *= xi - x[i-r+4];  /* n = 4 */
  prod_n *= xi - x[i-r+5];  /* n = 5 */
  prod_n *= xi - x[i-r+6];  /* n = 6 */
  prod_n *= xi - x[i-r+7];  /* n = 7 */
  prod_n *= xi - x[i-r+8];  /* n = 8 */
  sum_m += prod_n;

  /* m = 1 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  prod_n *= xi - x[i-r+4];  /* n = 4 */
  prod_n *= xi - x[i-r+5];  /* n = 5 */
  prod_n *= xi - x[i-r+6];  /* n = 6 */
  prod_n *= xi - x[i-r+7];  /* n = 7 */
  prod_n *= xi - x[i-r+8];  /* n = 8 */
  sum_m += prod_n;

  /* m = 3 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+4];  /* n = 4 */
  prod_n *= xi - x[i-r+5];  /* n = 5 */
  prod_n *= xi - x[i-r+6];  /* n = 6 */
  prod_n *= xi - x[i-r+7];  /* n = 7 */
  prod_n *= xi - x[i-r+8];  /* n = 8 */
  sum_m += prod_n;

  /* m = 4 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  prod_n *= xi - x[i-r+5];  /* n = 5 */
  prod_n *= xi - x[i-r+6];  /* n = 6 */
  prod_n *= xi - x[i-r+7];  /* n = 7 */
  prod_n *= xi - x[i-r+8];  /* n = 8 */
  sum_m += prod_n;

  /* m = 5 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  prod_n *= xi - x[i-r+4];  /* n = 4 */
  prod_n *= xi - x[i-r+6];  /* n = 6 */
  prod_n *= xi - x[i-r+7];  /* n = 7 */
  prod_n *= xi - x[i-r+8];  /* n = 8 */
  sum_m += prod_n;

  /* m = 6 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  prod_n *= xi - x[i-r+4];  /* n = 4 */
  prod_n *= xi - x[i-r+5];  /* n = 5 */
  prod_n *= xi - x[i-r+7];  /* n = 7 */
  prod_n *= xi - x[i-r+8];  /* n = 8 */
  sum_m += prod_n;

  /* m = 7 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  prod_n *= xi - x[i-r+4];  /* n = 4 */
  prod_n *= xi - x[i-r+5];  /* n = 5 */
  prod_n *= xi - x[i-r+6];  /* n = 6 */
  prod_n *= xi - x[i-r+8];  /* n = 8 */
  sum_m += prod_n;

  /* m = 8 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  prod_n *= xi - x[i-r+4];  /* n = 4 */
  prod_n *= xi - x[i-r+5];  /* n = 5 */
  prod_n *= xi - x[i-r+6];  /* n = 6 */
  prod_n *= xi - x[i-r+7];  /* n = 7 */
  sum_m += prod_n;

  prod_m = 1.0;
  prod_m *= x[i-r+2] - x[i-r+0];
  prod_m *= x[i-r+2] - x[i-r+1];
  prod_m *= x[i-r+2] - x[i-r+3];
  prod_m *= x[i-r+2] - x[i-r+4];
  prod_m *= x[i-r+2] - x[i-r+5];
  prod_m *= x[i-r+2] - x[i-r+6];
  prod_m *= x[i-r+2] - x[i-r+7];
  prod_m *= x[i-r+2] - x[i-r+8];

  sum_l += sum_m / prod_m * (x[i-r+0+1] - x[i-r+0]);

  /* l = 3 */
  sum_m = 0.0;

  /* m = 0 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+4];  /* n = 4 */
  prod_n *= xi - x[i-r+5];  /* n = 5 */
  prod_n *= xi - x[i-r+6];  /* n = 6 */
  prod_n *= xi - x[i-r+7];  /* n = 7 */
  prod_n *= xi - x[i-r+8];  /* n = 8 */
  sum_m += prod_n;

  /* m = 1 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+4];  /* n = 4 */
  prod_n *= xi - x[i-r+5];  /* n = 5 */
  prod_n *= xi - x[i-r+6];  /* n = 6 */
  prod_n *= xi - x[i-r+7];  /* n = 7 */
  prod_n *= xi - x[i-r+8];  /* n = 8 */
  sum_m += prod_n;

  /* m = 2 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+4];  /* n = 4 */
  prod_n *= xi - x[i-r+5];  /* n = 5 */
  prod_n *= xi - x[i-r+6];  /* n = 6 */
  prod_n *= xi - x[i-r+7];  /* n = 7 */
  prod_n *= xi - x[i-r+8];  /* n = 8 */
  sum_m += prod_n;

  /* m = 4 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+5];  /* n = 5 */
  prod_n *= xi - x[i-r+6];  /* n = 6 */
  prod_n *= xi - x[i-r+7];  /* n = 7 */
  prod_n *= xi - x[i-r+8];  /* n = 8 */
  sum_m += prod_n;

  /* m = 5 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+4];  /* n = 4 */
  prod_n *= xi - x[i-r+6];  /* n = 6 */
  prod_n *= xi - x[i-r+7];  /* n = 7 */
  prod_n *= xi - x[i-r+8];  /* n = 8 */
  sum_m += prod_n;

  /* m = 6 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+4];  /* n = 4 */
  prod_n *= xi - x[i-r+5];  /* n = 5 */
  prod_n *= xi - x[i-r+7];  /* n = 7 */
  prod_n *= xi - x[i-r+8];  /* n = 8 */
  sum_m += prod_n;

  /* m = 7 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+4];  /* n = 4 */
  prod_n *= xi - x[i-r+5];  /* n = 5 */
  prod_n *= xi - x[i-r+6];  /* n = 6 */
  prod_n *= xi - x[i-r+8];  /* n = 8 */
  sum_m += prod_n;

  /* m = 8 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+4];  /* n = 4 */
  prod_n *= xi - x[i-r+5];  /* n = 5 */
  prod_n *= xi - x[i-r+6];  /* n = 6 */
  prod_n *= xi - x[i-r+7];  /* n = 7 */
  sum_m += prod_n;

  prod_m = 1.0;
  prod_m *= x[i-r+3] - x[i-r+0];
  prod_m *= x[i-r+3] - x[i-r+1];
  prod_m *= x[i-r+3] - x[i-r+2];
  prod_m *= x[i-r+3] - x[i-r+4];
  prod_m *= x[i-r+3] - x[i-r+5];
  prod_m *= x[i-r+3] - x[i-r+6];
  prod_m *= x[i-r+3] - x[i-r+7];
  prod_m *= x[i-r+3] - x[i-r+8];

  sum_l += sum_m / prod_m * (x[i-r+0+1] - x[i-r+0]);

  /* l = 4 */
  sum_m = 0.0;

  /* m = 0 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  prod_n *= xi - x[i-r+5];  /* n = 5 */
  prod_n *= xi - x[i-r+6];  /* n = 6 */
  prod_n *= xi - x[i-r+7];  /* n = 7 */
  prod_n *= xi - x[i-r+8];  /* n = 8 */
  sum_m += prod_n;

  /* m = 1 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  prod_n *= xi - x[i-r+5];  /* n = 5 */
  prod_n *= xi - x[i-r+6];  /* n = 6 */
  prod_n *= xi - x[i-r+7];  /* n = 7 */
  prod_n *= xi - x[i-r+8];  /* n = 8 */
  sum_m += prod_n;

  /* m = 2 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  prod_n *= xi - x[i-r+5];  /* n = 5 */
  prod_n *= xi - x[i-r+6];  /* n = 6 */
  prod_n *= xi - x[i-r+7];  /* n = 7 */
  prod_n *= xi - x[i-r+8];  /* n = 8 */
  sum_m += prod_n;

  /* m = 3 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+5];  /* n = 5 */
  prod_n *= xi - x[i-r+6];  /* n = 6 */
  prod_n *= xi - x[i-r+7];  /* n = 7 */
  prod_n *= xi - x[i-r+8];  /* n = 8 */
  sum_m += prod_n;

  /* m = 5 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  prod_n *= xi - x[i-r+6];  /* n = 6 */
  prod_n *= xi - x[i-r+7];  /* n = 7 */
  prod_n *= xi - x[i-r+8];  /* n = 8 */
  sum_m += prod_n;

  /* m = 6 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  prod_n *= xi - x[i-r+5];  /* n = 5 */
  prod_n *= xi - x[i-r+7];  /* n = 7 */
  prod_n *= xi - x[i-r+8];  /* n = 8 */
  sum_m += prod_n;

  /* m = 7 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  prod_n *= xi - x[i-r+5];  /* n = 5 */
  prod_n *= xi - x[i-r+6];  /* n = 6 */
  prod_n *= xi - x[i-r+8];  /* n = 8 */
  sum_m += prod_n;

  /* m = 8 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  prod_n *= xi - x[i-r+5];  /* n = 5 */
  prod_n *= xi - x[i-r+6];  /* n = 6 */
  prod_n *= xi - x[i-r+7];  /* n = 7 */
  sum_m += prod_n;

  prod_m = 1.0;
  prod_m *= x[i-r+4] - x[i-r+0];
  prod_m *= x[i-r+4] - x[i-r+1];
  prod_m *= x[i-r+4] - x[i-r+2];
  prod_m *= x[i-r+4] - x[i-r+3];
  prod_m *= x[i-r+4] - x[i-r+5];
  prod_m *= x[i-r+4] - x[i-r+6];
  prod_m *= x[i-r+4] - x[i-r+7];
  prod_m *= x[i-r+4] - x[i-r+8];

  sum_l += sum_m / prod_m * (x[i-r+0+1] - x[i-r+0]);

  /* l = 5 */
  sum_m = 0.0;

  /* m = 0 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  prod_n *= xi - x[i-r+4];  /* n = 4 */
  prod_n *= xi - x[i-r+6];  /* n = 6 */
  prod_n *= xi - x[i-r+7];  /* n = 7 */
  prod_n *= xi - x[i-r+8];  /* n = 8 */
  sum_m += prod_n;

  /* m = 1 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  prod_n *= xi - x[i-r+4];  /* n = 4 */
  prod_n *= xi - x[i-r+6];  /* n = 6 */
  prod_n *= xi - x[i-r+7];  /* n = 7 */
  prod_n *= xi - x[i-r+8];  /* n = 8 */
  sum_m += prod_n;

  /* m = 2 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  prod_n *= xi - x[i-r+4];  /* n = 4 */
  prod_n *= xi - x[i-r+6];  /* n = 6 */
  prod_n *= xi - x[i-r+7];  /* n = 7 */
  prod_n *= xi - x[i-r+8];  /* n = 8 */
  sum_m += prod_n;

  /* m = 3 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+4];  /* n = 4 */
  prod_n *= xi - x[i-r+6];  /* n = 6 */
  prod_n *= xi - x[i-r+7];  /* n = 7 */
  prod_n *= xi - x[i-r+8];  /* n = 8 */
  sum_m += prod_n;

  /* m = 4 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  prod_n *= xi - x[i-r+6];  /* n = 6 */
  prod_n *= xi - x[i-r+7];  /* n = 7 */
  prod_n *= xi - x[i-r+8];  /* n = 8 */
  sum_m += prod_n;

  /* m = 6 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  prod_n *= xi - x[i-r+4];  /* n = 4 */
  prod_n *= xi - x[i-r+7];  /* n = 7 */
  prod_n *= xi - x[i-r+8];  /* n = 8 */
  sum_m += prod_n;

  /* m = 7 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  prod_n *= xi - x[i-r+4];  /* n = 4 */
  prod_n *= xi - x[i-r+6];  /* n = 6 */
  prod_n *= xi - x[i-r+8];  /* n = 8 */
  sum_m += prod_n;

  /* m = 8 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  prod_n *= xi - x[i-r+4];  /* n = 4 */
  prod_n *= xi - x[i-r+6];  /* n = 6 */
  prod_n *= xi - x[i-r+7];  /* n = 7 */
  sum_m += prod_n;

  prod_m = 1.0;
  prod_m *= x[i-r+5] - x[i-r+0];
  prod_m *= x[i-r+5] - x[i-r+1];
  prod_m *= x[i-r+5] - x[i-r+2];
  prod_m *= x[i-r+5] - x[i-r+3];
  prod_m *= x[i-r+5] - x[i-r+4];
  prod_m *= x[i-r+5] - x[i-r+6];
  prod_m *= x[i-r+5] - x[i-r+7];
  prod_m *= x[i-r+5] - x[i-r+8];

  sum_l += sum_m / prod_m * (x[i-r+0+1] - x[i-r+0]);

  /* l = 6 */
  sum_m = 0.0;

  /* m = 0 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  prod_n *= xi - x[i-r+4];  /* n = 4 */
  prod_n *= xi - x[i-r+5];  /* n = 5 */
  prod_n *= xi - x[i-r+7];  /* n = 7 */
  prod_n *= xi - x[i-r+8];  /* n = 8 */
  sum_m += prod_n;

  /* m = 1 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  prod_n *= xi - x[i-r+4];  /* n = 4 */
  prod_n *= xi - x[i-r+5];  /* n = 5 */
  prod_n *= xi - x[i-r+7];  /* n = 7 */
  prod_n *= xi - x[i-r+8];  /* n = 8 */
  sum_m += prod_n;

  /* m = 2 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  prod_n *= xi - x[i-r+4];  /* n = 4 */
  prod_n *= xi - x[i-r+5];  /* n = 5 */
  prod_n *= xi - x[i-r+7];  /* n = 7 */
  prod_n *= xi - x[i-r+8];  /* n = 8 */
  sum_m += prod_n;

  /* m = 3 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+4];  /* n = 4 */
  prod_n *= xi - x[i-r+5];  /* n = 5 */
  prod_n *= xi - x[i-r+7];  /* n = 7 */
  prod_n *= xi - x[i-r+8];  /* n = 8 */
  sum_m += prod_n;

  /* m = 4 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  prod_n *= xi - x[i-r+5];  /* n = 5 */
  prod_n *= xi - x[i-r+7];  /* n = 7 */
  prod_n *= xi - x[i-r+8];  /* n = 8 */
  sum_m += prod_n;

  /* m = 5 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  prod_n *= xi - x[i-r+4];  /* n = 4 */
  prod_n *= xi - x[i-r+7];  /* n = 7 */
  prod_n *= xi - x[i-r+8];  /* n = 8 */
  sum_m += prod_n;

  /* m = 7 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  prod_n *= xi - x[i-r+4];  /* n = 4 */
  prod_n *= xi - x[i-r+5];  /* n = 5 */
  prod_n *= xi - x[i-r+8];  /* n = 8 */
  sum_m += prod_n;

  /* m = 8 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  prod_n *= xi - x[i-r+4];  /* n = 4 */
  prod_n *= xi - x[i-r+5];  /* n = 5 */
  prod_n *= xi - x[i-r+7];  /* n = 7 */
  sum_m += prod_n;

  prod_m = 1.0;
  prod_m *= x[i-r+6] - x[i-r+0];
  prod_m *= x[i-r+6] - x[i-r+1];
  prod_m *= x[i-r+6] - x[i-r+2];
  prod_m *= x[i-r+6] - x[i-r+3];
  prod_m *= x[i-r+6] - x[i-r+4];
  prod_m *= x[i-r+6] - x[i-r+5];
  prod_m *= x[i-r+6] - x[i-r+7];
  prod_m *= x[i-r+6] - x[i-r+8];

  sum_l += sum_m / prod_m * (x[i-r+0+1] - x[i-r+0]);

  /* l = 7 */
  sum_m = 0.0;

  /* m = 0 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  prod_n *= xi - x[i-r+4];  /* n = 4 */
  prod_n *= xi - x[i-r+5];  /* n = 5 */
  prod_n *= xi - x[i-r+6];  /* n = 6 */
  prod_n *= xi - x[i-r+8];  /* n = 8 */
  sum_m += prod_n;

  /* m = 1 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  prod_n *= xi - x[i-r+4];  /* n = 4 */
  prod_n *= xi - x[i-r+5];  /* n = 5 */
  prod_n *= xi - x[i-r+6];  /* n = 6 */
  prod_n *= xi - x[i-r+8];  /* n = 8 */
  sum_m += prod_n;

  /* m = 2 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  prod_n *= xi - x[i-r+4];  /* n = 4 */
  prod_n *= xi - x[i-r+5];  /* n = 5 */
  prod_n *= xi - x[i-r+6];  /* n = 6 */
  prod_n *= xi - x[i-r+8];  /* n = 8 */
  sum_m += prod_n;

  /* m = 3 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+4];  /* n = 4 */
  prod_n *= xi - x[i-r+5];  /* n = 5 */
  prod_n *= xi - x[i-r+6];  /* n = 6 */
  prod_n *= xi - x[i-r+8];  /* n = 8 */
  sum_m += prod_n;

  /* m = 4 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  prod_n *= xi - x[i-r+5];  /* n = 5 */
  prod_n *= xi - x[i-r+6];  /* n = 6 */
  prod_n *= xi - x[i-r+8];  /* n = 8 */
  sum_m += prod_n;

  /* m = 5 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  prod_n *= xi - x[i-r+4];  /* n = 4 */
  prod_n *= xi - x[i-r+6];  /* n = 6 */
  prod_n *= xi - x[i-r+8];  /* n = 8 */
  sum_m += prod_n;

  /* m = 6 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  prod_n *= xi - x[i-r+4];  /* n = 4 */
  prod_n *= xi - x[i-r+5];  /* n = 5 */
  prod_n *= xi - x[i-r+8];  /* n = 8 */
  sum_m += prod_n;

  /* m = 8 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  prod_n *= xi - x[i-r+4];  /* n = 4 */
  prod_n *= xi - x[i-r+5];  /* n = 5 */
  prod_n *= xi - x[i-r+6];  /* n = 6 */
  sum_m += prod_n;

  prod_m = 1.0;
  prod_m *= x[i-r+7] - x[i-r+0];
  prod_m *= x[i-r+7] - x[i-r+1];
  prod_m *= x[i-r+7] - x[i-r+2];
  prod_m *= x[i-r+7] - x[i-r+3];
  prod_m *= x[i-r+7] - x[i-r+4];
  prod_m *= x[i-r+7] - x[i-r+5];
  prod_m *= x[i-r+7] - x[i-r+6];
  prod_m *= x[i-r+7] - x[i-r+8];

  sum_l += sum_m / prod_m * (x[i-r+0+1] - x[i-r+0]);

  /* l = 8 */
  sum_m = 0.0;

  /* m = 0 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  prod_n *= xi - x[i-r+4];  /* n = 4 */
  prod_n *= xi - x[i-r+5];  /* n = 5 */
  prod_n *= xi - x[i-r+6];  /* n = 6 */
  prod_n *= xi - x[i-r+7];  /* n = 7 */
  sum_m += prod_n;

  /* m = 1 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  prod_n *= xi - x[i-r+4];  /* n = 4 */
  prod_n *= xi - x[i-r+5];  /* n = 5 */
  prod_n *= xi - x[i-r+6];  /* n = 6 */
  prod_n *= xi - x[i-r+7];  /* n = 7 */
  sum_m += prod_n;

  /* m = 2 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  prod_n *= xi - x[i-r+4];  /* n = 4 */
  prod_n *= xi - x[i-r+5];  /* n = 5 */
  prod_n *= xi - x[i-r+6];  /* n = 6 */
  prod_n *= xi - x[i-r+7];  /* n = 7 */
  sum_m += prod_n;

  /* m = 3 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+4];  /* n = 4 */
  prod_n *= xi - x[i-r+5];  /* n = 5 */
  prod_n *= xi - x[i-r+6];  /* n = 6 */
  prod_n *= xi - x[i-r+7];  /* n = 7 */
  sum_m += prod_n;

  /* m = 4 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  prod_n *= xi - x[i-r+5];  /* n = 5 */
  prod_n *= xi - x[i-r+6];  /* n = 6 */
  prod_n *= xi - x[i-r+7];  /* n = 7 */
  sum_m += prod_n;

  /* m = 5 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  prod_n *= xi - x[i-r+4];  /* n = 4 */
  prod_n *= xi - x[i-r+6];  /* n = 6 */
  prod_n *= xi - x[i-r+7];  /* n = 7 */
  sum_m += prod_n;

  /* m = 6 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  prod_n *= xi - x[i-r+4];  /* n = 4 */
  prod_n *= xi - x[i-r+5];  /* n = 5 */
  prod_n *= xi - x[i-r+7];  /* n = 7 */
  sum_m += prod_n;

  /* m = 7 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  prod_n *= xi - x[i-r+4];  /* n = 4 */
  prod_n *= xi - x[i-r+5];  /* n = 5 */
  prod_n *= xi - x[i-r+6];  /* n = 6 */
  sum_m += prod_n;

  prod_m = 1.0;
  prod_m *= x[i-r+8] - x[i-r+0];
  prod_m *= x[i-r+8] - x[i-r+1];
  prod_m *= x[i-r+8] - x[i-r+2];
  prod_m *= x[i-r+8] - x[i-r+3];
  prod_m *= x[i-r+8] - x[i-r+4];
  prod_m *= x[i-r+8] - x[i-r+5];
  prod_m *= x[i-r+8] - x[i-r+6];
  prod_m *= x[i-r+8] - x[i-r+7];

  sum_l += sum_m / prod_m * (x[i-r+0+1] - x[i-r+0]);

  c[0] = sum_l;

  /* j = 1 */
  sum_l = 0.0;

  /* l = 2 */
  sum_m = 0.0;

  /* m = 0 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  prod_n *= xi - x[i-r+4];  /* n = 4 */
  prod_n *= xi - x[i-r+5];  /* n = 5 */
  prod_n *= xi - x[i-r+6];  /* n = 6 */
  prod_n *= xi - x[i-r+7];  /* n = 7 */
  prod_n *= xi - x[i-r+8];  /* n = 8 */
  sum_m += prod_n;

  /* m = 1 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  prod_n *= xi - x[i-r+4];  /* n = 4 */
  prod_n *= xi - x[i-r+5];  /* n = 5 */
  prod_n *= xi - x[i-r+6];  /* n = 6 */
  prod_n *= xi - x[i-r+7];  /* n = 7 */
  prod_n *= xi - x[i-r+8];  /* n = 8 */
  sum_m += prod_n;

  /* m = 3 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+4];  /* n = 4 */
  prod_n *= xi - x[i-r+5];  /* n = 5 */
  prod_n *= xi - x[i-r+6];  /* n = 6 */
  prod_n *= xi - x[i-r+7];  /* n = 7 */
  prod_n *= xi - x[i-r+8];  /* n = 8 */
  sum_m += prod_n;

  /* m = 4 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  prod_n *= xi - x[i-r+5];  /* n = 5 */
  prod_n *= xi - x[i-r+6];  /* n = 6 */
  prod_n *= xi - x[i-r+7];  /* n = 7 */
  prod_n *= xi - x[i-r+8];  /* n = 8 */
  sum_m += prod_n;

  /* m = 5 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  prod_n *= xi - x[i-r+4];  /* n = 4 */
  prod_n *= xi - x[i-r+6];  /* n = 6 */
  prod_n *= xi - x[i-r+7];  /* n = 7 */
  prod_n *= xi - x[i-r+8];  /* n = 8 */
  sum_m += prod_n;

  /* m = 6 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  prod_n *= xi - x[i-r+4];  /* n = 4 */
  prod_n *= xi - x[i-r+5];  /* n = 5 */
  prod_n *= xi - x[i-r+7];  /* n = 7 */
  prod_n *= xi - x[i-r+8];  /* n = 8 */
  sum_m += prod_n;

  /* m = 7 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  prod_n *= xi - x[i-r+4];  /* n = 4 */
  prod_n *= xi - x[i-r+5];  /* n = 5 */
  prod_n *= xi - x[i-r+6];  /* n = 6 */
  prod_n *= xi - x[i-r+8];  /* n = 8 */
  sum_m += prod_n;

  /* m = 8 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  prod_n *= xi - x[i-r+4];  /* n = 4 */
  prod_n *= xi - x[i-r+5];  /* n = 5 */
  prod_n *= xi - x[i-r+6];  /* n = 6 */
  prod_n *= xi - x[i-r+7];  /* n = 7 */
  sum_m += prod_n;

  prod_m = 1.0;
  prod_m *= x[i-r+2] - x[i-r+0];
  prod_m *= x[i-r+2] - x[i-r+1];
  prod_m *= x[i-r+2] - x[i-r+3];
  prod_m *= x[i-r+2] - x[i-r+4];
  prod_m *= x[i-r+2] - x[i-r+5];
  prod_m *= x[i-r+2] - x[i-r+6];
  prod_m *= x[i-r+2] - x[i-r+7];
  prod_m *= x[i-r+2] - x[i-r+8];

  sum_l += sum_m / prod_m * (x[i-r+1+1] - x[i-r+1]);

  /* l = 3 */
  sum_m = 0.0;

  /* m = 0 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+4];  /* n = 4 */
  prod_n *= xi - x[i-r+5];  /* n = 5 */
  prod_n *= xi - x[i-r+6];  /* n = 6 */
  prod_n *= xi - x[i-r+7];  /* n = 7 */
  prod_n *= xi - x[i-r+8];  /* n = 8 */
  sum_m += prod_n;

  /* m = 1 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+4];  /* n = 4 */
  prod_n *= xi - x[i-r+5];  /* n = 5 */
  prod_n *= xi - x[i-r+6];  /* n = 6 */
  prod_n *= xi - x[i-r+7];  /* n = 7 */
  prod_n *= xi - x[i-r+8];  /* n = 8 */
  sum_m += prod_n;

  /* m = 2 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+4];  /* n = 4 */
  prod_n *= xi - x[i-r+5];  /* n = 5 */
  prod_n *= xi - x[i-r+6];  /* n = 6 */
  prod_n *= xi - x[i-r+7];  /* n = 7 */
  prod_n *= xi - x[i-r+8];  /* n = 8 */
  sum_m += prod_n;

  /* m = 4 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+5];  /* n = 5 */
  prod_n *= xi - x[i-r+6];  /* n = 6 */
  prod_n *= xi - x[i-r+7];  /* n = 7 */
  prod_n *= xi - x[i-r+8];  /* n = 8 */
  sum_m += prod_n;

  /* m = 5 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+4];  /* n = 4 */
  prod_n *= xi - x[i-r+6];  /* n = 6 */
  prod_n *= xi - x[i-r+7];  /* n = 7 */
  prod_n *= xi - x[i-r+8];  /* n = 8 */
  sum_m += prod_n;

  /* m = 6 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+4];  /* n = 4 */
  prod_n *= xi - x[i-r+5];  /* n = 5 */
  prod_n *= xi - x[i-r+7];  /* n = 7 */
  prod_n *= xi - x[i-r+8];  /* n = 8 */
  sum_m += prod_n;

  /* m = 7 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+4];  /* n = 4 */
  prod_n *= xi - x[i-r+5];  /* n = 5 */
  prod_n *= xi - x[i-r+6];  /* n = 6 */
  prod_n *= xi - x[i-r+8];  /* n = 8 */
  sum_m += prod_n;

  /* m = 8 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+4];  /* n = 4 */
  prod_n *= xi - x[i-r+5];  /* n = 5 */
  prod_n *= xi - x[i-r+6];  /* n = 6 */
  prod_n *= xi - x[i-r+7];  /* n = 7 */
  sum_m += prod_n;

  prod_m = 1.0;
  prod_m *= x[i-r+3] - x[i-r+0];
  prod_m *= x[i-r+3] - x[i-r+1];
  prod_m *= x[i-r+3] - x[i-r+2];
  prod_m *= x[i-r+3] - x[i-r+4];
  prod_m *= x[i-r+3] - x[i-r+5];
  prod_m *= x[i-r+3] - x[i-r+6];
  prod_m *= x[i-r+3] - x[i-r+7];
  prod_m *= x[i-r+3] - x[i-r+8];

  sum_l += sum_m / prod_m * (x[i-r+1+1] - x[i-r+1]);

  /* l = 4 */
  sum_m = 0.0;

  /* m = 0 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  prod_n *= xi - x[i-r+5];  /* n = 5 */
  prod_n *= xi - x[i-r+6];  /* n = 6 */
  prod_n *= xi - x[i-r+7];  /* n = 7 */
  prod_n *= xi - x[i-r+8];  /* n = 8 */
  sum_m += prod_n;

  /* m = 1 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  prod_n *= xi - x[i-r+5];  /* n = 5 */
  prod_n *= xi - x[i-r+6];  /* n = 6 */
  prod_n *= xi - x[i-r+7];  /* n = 7 */
  prod_n *= xi - x[i-r+8];  /* n = 8 */
  sum_m += prod_n;

  /* m = 2 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  prod_n *= xi - x[i-r+5];  /* n = 5 */
  prod_n *= xi - x[i-r+6];  /* n = 6 */
  prod_n *= xi - x[i-r+7];  /* n = 7 */
  prod_n *= xi - x[i-r+8];  /* n = 8 */
  sum_m += prod_n;

  /* m = 3 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+5];  /* n = 5 */
  prod_n *= xi - x[i-r+6];  /* n = 6 */
  prod_n *= xi - x[i-r+7];  /* n = 7 */
  prod_n *= xi - x[i-r+8];  /* n = 8 */
  sum_m += prod_n;

  /* m = 5 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  prod_n *= xi - x[i-r+6];  /* n = 6 */
  prod_n *= xi - x[i-r+7];  /* n = 7 */
  prod_n *= xi - x[i-r+8];  /* n = 8 */
  sum_m += prod_n;

  /* m = 6 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  prod_n *= xi - x[i-r+5];  /* n = 5 */
  prod_n *= xi - x[i-r+7];  /* n = 7 */
  prod_n *= xi - x[i-r+8];  /* n = 8 */
  sum_m += prod_n;

  /* m = 7 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  prod_n *= xi - x[i-r+5];  /* n = 5 */
  prod_n *= xi - x[i-r+6];  /* n = 6 */
  prod_n *= xi - x[i-r+8];  /* n = 8 */
  sum_m += prod_n;

  /* m = 8 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  prod_n *= xi - x[i-r+5];  /* n = 5 */
  prod_n *= xi - x[i-r+6];  /* n = 6 */
  prod_n *= xi - x[i-r+7];  /* n = 7 */
  sum_m += prod_n;

  prod_m = 1.0;
  prod_m *= x[i-r+4] - x[i-r+0];
  prod_m *= x[i-r+4] - x[i-r+1];
  prod_m *= x[i-r+4] - x[i-r+2];
  prod_m *= x[i-r+4] - x[i-r+3];
  prod_m *= x[i-r+4] - x[i-r+5];
  prod_m *= x[i-r+4] - x[i-r+6];
  prod_m *= x[i-r+4] - x[i-r+7];
  prod_m *= x[i-r+4] - x[i-r+8];

  sum_l += sum_m / prod_m * (x[i-r+1+1] - x[i-r+1]);

  /* l = 5 */
  sum_m = 0.0;

  /* m = 0 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  prod_n *= xi - x[i-r+4];  /* n = 4 */
  prod_n *= xi - x[i-r+6];  /* n = 6 */
  prod_n *= xi - x[i-r+7];  /* n = 7 */
  prod_n *= xi - x[i-r+8];  /* n = 8 */
  sum_m += prod_n;

  /* m = 1 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  prod_n *= xi - x[i-r+4];  /* n = 4 */
  prod_n *= xi - x[i-r+6];  /* n = 6 */
  prod_n *= xi - x[i-r+7];  /* n = 7 */
  prod_n *= xi - x[i-r+8];  /* n = 8 */
  sum_m += prod_n;

  /* m = 2 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  prod_n *= xi - x[i-r+4];  /* n = 4 */
  prod_n *= xi - x[i-r+6];  /* n = 6 */
  prod_n *= xi - x[i-r+7];  /* n = 7 */
  prod_n *= xi - x[i-r+8];  /* n = 8 */
  sum_m += prod_n;

  /* m = 3 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+4];  /* n = 4 */
  prod_n *= xi - x[i-r+6];  /* n = 6 */
  prod_n *= xi - x[i-r+7];  /* n = 7 */
  prod_n *= xi - x[i-r+8];  /* n = 8 */
  sum_m += prod_n;

  /* m = 4 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  prod_n *= xi - x[i-r+6];  /* n = 6 */
  prod_n *= xi - x[i-r+7];  /* n = 7 */
  prod_n *= xi - x[i-r+8];  /* n = 8 */
  sum_m += prod_n;

  /* m = 6 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  prod_n *= xi - x[i-r+4];  /* n = 4 */
  prod_n *= xi - x[i-r+7];  /* n = 7 */
  prod_n *= xi - x[i-r+8];  /* n = 8 */
  sum_m += prod_n;

  /* m = 7 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  prod_n *= xi - x[i-r+4];  /* n = 4 */
  prod_n *= xi - x[i-r+6];  /* n = 6 */
  prod_n *= xi - x[i-r+8];  /* n = 8 */
  sum_m += prod_n;

  /* m = 8 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  prod_n *= xi - x[i-r+4];  /* n = 4 */
  prod_n *= xi - x[i-r+6];  /* n = 6 */
  prod_n *= xi - x[i-r+7];  /* n = 7 */
  sum_m += prod_n;

  prod_m = 1.0;
  prod_m *= x[i-r+5] - x[i-r+0];
  prod_m *= x[i-r+5] - x[i-r+1];
  prod_m *= x[i-r+5] - x[i-r+2];
  prod_m *= x[i-r+5] - x[i-r+3];
  prod_m *= x[i-r+5] - x[i-r+4];
  prod_m *= x[i-r+5] - x[i-r+6];
  prod_m *= x[i-r+5] - x[i-r+7];
  prod_m *= x[i-r+5] - x[i-r+8];

  sum_l += sum_m / prod_m * (x[i-r+1+1] - x[i-r+1]);

  /* l = 6 */
  sum_m = 0.0;

  /* m = 0 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  prod_n *= xi - x[i-r+4];  /* n = 4 */
  prod_n *= xi - x[i-r+5];  /* n = 5 */
  prod_n *= xi - x[i-r+7];  /* n = 7 */
  prod_n *= xi - x[i-r+8];  /* n = 8 */
  sum_m += prod_n;

  /* m = 1 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  prod_n *= xi - x[i-r+4];  /* n = 4 */
  prod_n *= xi - x[i-r+5];  /* n = 5 */
  prod_n *= xi - x[i-r+7];  /* n = 7 */
  prod_n *= xi - x[i-r+8];  /* n = 8 */
  sum_m += prod_n;

  /* m = 2 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  prod_n *= xi - x[i-r+4];  /* n = 4 */
  prod_n *= xi - x[i-r+5];  /* n = 5 */
  prod_n *= xi - x[i-r+7];  /* n = 7 */
  prod_n *= xi - x[i-r+8];  /* n = 8 */
  sum_m += prod_n;

  /* m = 3 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+4];  /* n = 4 */
  prod_n *= xi - x[i-r+5];  /* n = 5 */
  prod_n *= xi - x[i-r+7];  /* n = 7 */
  prod_n *= xi - x[i-r+8];  /* n = 8 */
  sum_m += prod_n;

  /* m = 4 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  prod_n *= xi - x[i-r+5];  /* n = 5 */
  prod_n *= xi - x[i-r+7];  /* n = 7 */
  prod_n *= xi - x[i-r+8];  /* n = 8 */
  sum_m += prod_n;

  /* m = 5 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  prod_n *= xi - x[i-r+4];  /* n = 4 */
  prod_n *= xi - x[i-r+7];  /* n = 7 */
  prod_n *= xi - x[i-r+8];  /* n = 8 */
  sum_m += prod_n;

  /* m = 7 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  prod_n *= xi - x[i-r+4];  /* n = 4 */
  prod_n *= xi - x[i-r+5];  /* n = 5 */
  prod_n *= xi - x[i-r+8];  /* n = 8 */
  sum_m += prod_n;

  /* m = 8 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  prod_n *= xi - x[i-r+4];  /* n = 4 */
  prod_n *= xi - x[i-r+5];  /* n = 5 */
  prod_n *= xi - x[i-r+7];  /* n = 7 */
  sum_m += prod_n;

  prod_m = 1.0;
  prod_m *= x[i-r+6] - x[i-r+0];
  prod_m *= x[i-r+6] - x[i-r+1];
  prod_m *= x[i-r+6] - x[i-r+2];
  prod_m *= x[i-r+6] - x[i-r+3];
  prod_m *= x[i-r+6] - x[i-r+4];
  prod_m *= x[i-r+6] - x[i-r+5];
  prod_m *= x[i-r+6] - x[i-r+7];
  prod_m *= x[i-r+6] - x[i-r+8];

  sum_l += sum_m / prod_m * (x[i-r+1+1] - x[i-r+1]);

  /* l = 7 */
  sum_m = 0.0;

  /* m = 0 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  prod_n *= xi - x[i-r+4];  /* n = 4 */
  prod_n *= xi - x[i-r+5];  /* n = 5 */
  prod_n *= xi - x[i-r+6];  /* n = 6 */
  prod_n *= xi - x[i-r+8];  /* n = 8 */
  sum_m += prod_n;

  /* m = 1 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  prod_n *= xi - x[i-r+4];  /* n = 4 */
  prod_n *= xi - x[i-r+5];  /* n = 5 */
  prod_n *= xi - x[i-r+6];  /* n = 6 */
  prod_n *= xi - x[i-r+8];  /* n = 8 */
  sum_m += prod_n;

  /* m = 2 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  prod_n *= xi - x[i-r+4];  /* n = 4 */
  prod_n *= xi - x[i-r+5];  /* n = 5 */
  prod_n *= xi - x[i-r+6];  /* n = 6 */
  prod_n *= xi - x[i-r+8];  /* n = 8 */
  sum_m += prod_n;

  /* m = 3 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+4];  /* n = 4 */
  prod_n *= xi - x[i-r+5];  /* n = 5 */
  prod_n *= xi - x[i-r+6];  /* n = 6 */
  prod_n *= xi - x[i-r+8];  /* n = 8 */
  sum_m += prod_n;

  /* m = 4 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  prod_n *= xi - x[i-r+5];  /* n = 5 */
  prod_n *= xi - x[i-r+6];  /* n = 6 */
  prod_n *= xi - x[i-r+8];  /* n = 8 */
  sum_m += prod_n;

  /* m = 5 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  prod_n *= xi - x[i-r+4];  /* n = 4 */
  prod_n *= xi - x[i-r+6];  /* n = 6 */
  prod_n *= xi - x[i-r+8];  /* n = 8 */
  sum_m += prod_n;

  /* m = 6 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  prod_n *= xi - x[i-r+4];  /* n = 4 */
  prod_n *= xi - x[i-r+5];  /* n = 5 */
  prod_n *= xi - x[i-r+8];  /* n = 8 */
  sum_m += prod_n;

  /* m = 8 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  prod_n *= xi - x[i-r+4];  /* n = 4 */
  prod_n *= xi - x[i-r+5];  /* n = 5 */
  prod_n *= xi - x[i-r+6];  /* n = 6 */
  sum_m += prod_n;

  prod_m = 1.0;
  prod_m *= x[i-r+7] - x[i-r+0];
  prod_m *= x[i-r+7] - x[i-r+1];
  prod_m *= x[i-r+7] - x[i-r+2];
  prod_m *= x[i-r+7] - x[i-r+3];
  prod_m *= x[i-r+7] - x[i-r+4];
  prod_m *= x[i-r+7] - x[i-r+5];
  prod_m *= x[i-r+7] - x[i-r+6];
  prod_m *= x[i-r+7] - x[i-r+8];

  sum_l += sum_m / prod_m * (x[i-r+1+1] - x[i-r+1]);

  /* l = 8 */
  sum_m = 0.0;

  /* m = 0 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  prod_n *= xi - x[i-r+4];  /* n = 4 */
  prod_n *= xi - x[i-r+5];  /* n = 5 */
  prod_n *= xi - x[i-r+6];  /* n = 6 */
  prod_n *= xi - x[i-r+7];  /* n = 7 */
  sum_m += prod_n;

  /* m = 1 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  prod_n *= xi - x[i-r+4];  /* n = 4 */
  prod_n *= xi - x[i-r+5];  /* n = 5 */
  prod_n *= xi - x[i-r+6];  /* n = 6 */
  prod_n *= xi - x[i-r+7];  /* n = 7 */
  sum_m += prod_n;

  /* m = 2 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  prod_n *= xi - x[i-r+4];  /* n = 4 */
  prod_n *= xi - x[i-r+5];  /* n = 5 */
  prod_n *= xi - x[i-r+6];  /* n = 6 */
  prod_n *= xi - x[i-r+7];  /* n = 7 */
  sum_m += prod_n;

  /* m = 3 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+4];  /* n = 4 */
  prod_n *= xi - x[i-r+5];  /* n = 5 */
  prod_n *= xi - x[i-r+6];  /* n = 6 */
  prod_n *= xi - x[i-r+7];  /* n = 7 */
  sum_m += prod_n;

  /* m = 4 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  prod_n *= xi - x[i-r+5];  /* n = 5 */
  prod_n *= xi - x[i-r+6];  /* n = 6 */
  prod_n *= xi - x[i-r+7];  /* n = 7 */
  sum_m += prod_n;

  /* m = 5 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  prod_n *= xi - x[i-r+4];  /* n = 4 */
  prod_n *= xi - x[i-r+6];  /* n = 6 */
  prod_n *= xi - x[i-r+7];  /* n = 7 */
  sum_m += prod_n;

  /* m = 6 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  prod_n *= xi - x[i-r+4];  /* n = 4 */
  prod_n *= xi - x[i-r+5];  /* n = 5 */
  prod_n *= xi - x[i-r+7];  /* n = 7 */
  sum_m += prod_n;

  /* m = 7 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  prod_n *= xi - x[i-r+4];  /* n = 4 */
  prod_n *= xi - x[i-r+5];  /* n = 5 */
  prod_n *= xi - x[i-r+6];  /* n = 6 */
  sum_m += prod_n;

  prod_m = 1.0;
  prod_m *= x[i-r+8] - x[i-r+0];
  prod_m *= x[i-r+8] - x[i-r+1];
  prod_m *= x[i-r+8] - x[i-r+2];
  prod_m *= x[i-r+8] - x[i-r+3];
  prod_m *= x[i-r+8] - x[i-r+4];
  prod_m *= x[i-r+8] - x[i-r+5];
  prod_m *= x[i-r+8] - x[i-r+6];
  prod_m *= x[i-r+8] - x[i-r+7];

  sum_l += sum_m / prod_m * (x[i-r+1+1] - x[i-r+1]);

  c[1] = sum_l;

  /* j = 2 */
  sum_l = 0.0;

  /* l = 3 */
  sum_m = 0.0;

  /* m = 0 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+4];  /* n = 4 */
  prod_n *= xi - x[i-r+5];  /* n = 5 */
  prod_n *= xi - x[i-r+6];  /* n = 6 */
  prod_n *= xi - x[i-r+7];  /* n = 7 */
  prod_n *= xi - x[i-r+8];  /* n = 8 */
  sum_m += prod_n;

  /* m = 1 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+4];  /* n = 4 */
  prod_n *= xi - x[i-r+5];  /* n = 5 */
  prod_n *= xi - x[i-r+6];  /* n = 6 */
  prod_n *= xi - x[i-r+7];  /* n = 7 */
  prod_n *= xi - x[i-r+8];  /* n = 8 */
  sum_m += prod_n;

  /* m = 2 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+4];  /* n = 4 */
  prod_n *= xi - x[i-r+5];  /* n = 5 */
  prod_n *= xi - x[i-r+6];  /* n = 6 */
  prod_n *= xi - x[i-r+7];  /* n = 7 */
  prod_n *= xi - x[i-r+8];  /* n = 8 */
  sum_m += prod_n;

  /* m = 4 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+5];  /* n = 5 */
  prod_n *= xi - x[i-r+6];  /* n = 6 */
  prod_n *= xi - x[i-r+7];  /* n = 7 */
  prod_n *= xi - x[i-r+8];  /* n = 8 */
  sum_m += prod_n;

  /* m = 5 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+4];  /* n = 4 */
  prod_n *= xi - x[i-r+6];  /* n = 6 */
  prod_n *= xi - x[i-r+7];  /* n = 7 */
  prod_n *= xi - x[i-r+8];  /* n = 8 */
  sum_m += prod_n;

  /* m = 6 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+4];  /* n = 4 */
  prod_n *= xi - x[i-r+5];  /* n = 5 */
  prod_n *= xi - x[i-r+7];  /* n = 7 */
  prod_n *= xi - x[i-r+8];  /* n = 8 */
  sum_m += prod_n;

  /* m = 7 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+4];  /* n = 4 */
  prod_n *= xi - x[i-r+5];  /* n = 5 */
  prod_n *= xi - x[i-r+6];  /* n = 6 */
  prod_n *= xi - x[i-r+8];  /* n = 8 */
  sum_m += prod_n;

  /* m = 8 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+4];  /* n = 4 */
  prod_n *= xi - x[i-r+5];  /* n = 5 */
  prod_n *= xi - x[i-r+6];  /* n = 6 */
  prod_n *= xi - x[i-r+7];  /* n = 7 */
  sum_m += prod_n;

  prod_m = 1.0;
  prod_m *= x[i-r+3] - x[i-r+0];
  prod_m *= x[i-r+3] - x[i-r+1];
  prod_m *= x[i-r+3] - x[i-r+2];
  prod_m *= x[i-r+3] - x[i-r+4];
  prod_m *= x[i-r+3] - x[i-r+5];
  prod_m *= x[i-r+3] - x[i-r+6];
  prod_m *= x[i-r+3] - x[i-r+7];
  prod_m *= x[i-r+3] - x[i-r+8];

  sum_l += sum_m / prod_m * (x[i-r+2+1] - x[i-r+2]);

  /* l = 4 */
  sum_m = 0.0;

  /* m = 0 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  prod_n *= xi - x[i-r+5];  /* n = 5 */
  prod_n *= xi - x[i-r+6];  /* n = 6 */
  prod_n *= xi - x[i-r+7];  /* n = 7 */
  prod_n *= xi - x[i-r+8];  /* n = 8 */
  sum_m += prod_n;

  /* m = 1 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  prod_n *= xi - x[i-r+5];  /* n = 5 */
  prod_n *= xi - x[i-r+6];  /* n = 6 */
  prod_n *= xi - x[i-r+7];  /* n = 7 */
  prod_n *= xi - x[i-r+8];  /* n = 8 */
  sum_m += prod_n;

  /* m = 2 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  prod_n *= xi - x[i-r+5];  /* n = 5 */
  prod_n *= xi - x[i-r+6];  /* n = 6 */
  prod_n *= xi - x[i-r+7];  /* n = 7 */
  prod_n *= xi - x[i-r+8];  /* n = 8 */
  sum_m += prod_n;

  /* m = 3 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+5];  /* n = 5 */
  prod_n *= xi - x[i-r+6];  /* n = 6 */
  prod_n *= xi - x[i-r+7];  /* n = 7 */
  prod_n *= xi - x[i-r+8];  /* n = 8 */
  sum_m += prod_n;

  /* m = 5 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  prod_n *= xi - x[i-r+6];  /* n = 6 */
  prod_n *= xi - x[i-r+7];  /* n = 7 */
  prod_n *= xi - x[i-r+8];  /* n = 8 */
  sum_m += prod_n;

  /* m = 6 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  prod_n *= xi - x[i-r+5];  /* n = 5 */
  prod_n *= xi - x[i-r+7];  /* n = 7 */
  prod_n *= xi - x[i-r+8];  /* n = 8 */
  sum_m += prod_n;

  /* m = 7 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  prod_n *= xi - x[i-r+5];  /* n = 5 */
  prod_n *= xi - x[i-r+6];  /* n = 6 */
  prod_n *= xi - x[i-r+8];  /* n = 8 */
  sum_m += prod_n;

  /* m = 8 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  prod_n *= xi - x[i-r+5];  /* n = 5 */
  prod_n *= xi - x[i-r+6];  /* n = 6 */
  prod_n *= xi - x[i-r+7];  /* n = 7 */
  sum_m += prod_n;

  prod_m = 1.0;
  prod_m *= x[i-r+4] - x[i-r+0];
  prod_m *= x[i-r+4] - x[i-r+1];
  prod_m *= x[i-r+4] - x[i-r+2];
  prod_m *= x[i-r+4] - x[i-r+3];
  prod_m *= x[i-r+4] - x[i-r+5];
  prod_m *= x[i-r+4] - x[i-r+6];
  prod_m *= x[i-r+4] - x[i-r+7];
  prod_m *= x[i-r+4] - x[i-r+8];

  sum_l += sum_m / prod_m * (x[i-r+2+1] - x[i-r+2]);

  /* l = 5 */
  sum_m = 0.0;

  /* m = 0 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  prod_n *= xi - x[i-r+4];  /* n = 4 */
  prod_n *= xi - x[i-r+6];  /* n = 6 */
  prod_n *= xi - x[i-r+7];  /* n = 7 */
  prod_n *= xi - x[i-r+8];  /* n = 8 */
  sum_m += prod_n;

  /* m = 1 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  prod_n *= xi - x[i-r+4];  /* n = 4 */
  prod_n *= xi - x[i-r+6];  /* n = 6 */
  prod_n *= xi - x[i-r+7];  /* n = 7 */
  prod_n *= xi - x[i-r+8];  /* n = 8 */
  sum_m += prod_n;

  /* m = 2 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  prod_n *= xi - x[i-r+4];  /* n = 4 */
  prod_n *= xi - x[i-r+6];  /* n = 6 */
  prod_n *= xi - x[i-r+7];  /* n = 7 */
  prod_n *= xi - x[i-r+8];  /* n = 8 */
  sum_m += prod_n;

  /* m = 3 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+4];  /* n = 4 */
  prod_n *= xi - x[i-r+6];  /* n = 6 */
  prod_n *= xi - x[i-r+7];  /* n = 7 */
  prod_n *= xi - x[i-r+8];  /* n = 8 */
  sum_m += prod_n;

  /* m = 4 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  prod_n *= xi - x[i-r+6];  /* n = 6 */
  prod_n *= xi - x[i-r+7];  /* n = 7 */
  prod_n *= xi - x[i-r+8];  /* n = 8 */
  sum_m += prod_n;

  /* m = 6 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  prod_n *= xi - x[i-r+4];  /* n = 4 */
  prod_n *= xi - x[i-r+7];  /* n = 7 */
  prod_n *= xi - x[i-r+8];  /* n = 8 */
  sum_m += prod_n;

  /* m = 7 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  prod_n *= xi - x[i-r+4];  /* n = 4 */
  prod_n *= xi - x[i-r+6];  /* n = 6 */
  prod_n *= xi - x[i-r+8];  /* n = 8 */
  sum_m += prod_n;

  /* m = 8 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  prod_n *= xi - x[i-r+4];  /* n = 4 */
  prod_n *= xi - x[i-r+6];  /* n = 6 */
  prod_n *= xi - x[i-r+7];  /* n = 7 */
  sum_m += prod_n;

  prod_m = 1.0;
  prod_m *= x[i-r+5] - x[i-r+0];
  prod_m *= x[i-r+5] - x[i-r+1];
  prod_m *= x[i-r+5] - x[i-r+2];
  prod_m *= x[i-r+5] - x[i-r+3];
  prod_m *= x[i-r+5] - x[i-r+4];
  prod_m *= x[i-r+5] - x[i-r+6];
  prod_m *= x[i-r+5] - x[i-r+7];
  prod_m *= x[i-r+5] - x[i-r+8];

  sum_l += sum_m / prod_m * (x[i-r+2+1] - x[i-r+2]);

  /* l = 6 */
  sum_m = 0.0;

  /* m = 0 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  prod_n *= xi - x[i-r+4];  /* n = 4 */
  prod_n *= xi - x[i-r+5];  /* n = 5 */
  prod_n *= xi - x[i-r+7];  /* n = 7 */
  prod_n *= xi - x[i-r+8];  /* n = 8 */
  sum_m += prod_n;

  /* m = 1 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  prod_n *= xi - x[i-r+4];  /* n = 4 */
  prod_n *= xi - x[i-r+5];  /* n = 5 */
  prod_n *= xi - x[i-r+7];  /* n = 7 */
  prod_n *= xi - x[i-r+8];  /* n = 8 */
  sum_m += prod_n;

  /* m = 2 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  prod_n *= xi - x[i-r+4];  /* n = 4 */
  prod_n *= xi - x[i-r+5];  /* n = 5 */
  prod_n *= xi - x[i-r+7];  /* n = 7 */
  prod_n *= xi - x[i-r+8];  /* n = 8 */
  sum_m += prod_n;

  /* m = 3 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+4];  /* n = 4 */
  prod_n *= xi - x[i-r+5];  /* n = 5 */
  prod_n *= xi - x[i-r+7];  /* n = 7 */
  prod_n *= xi - x[i-r+8];  /* n = 8 */
  sum_m += prod_n;

  /* m = 4 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  prod_n *= xi - x[i-r+5];  /* n = 5 */
  prod_n *= xi - x[i-r+7];  /* n = 7 */
  prod_n *= xi - x[i-r+8];  /* n = 8 */
  sum_m += prod_n;

  /* m = 5 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  prod_n *= xi - x[i-r+4];  /* n = 4 */
  prod_n *= xi - x[i-r+7];  /* n = 7 */
  prod_n *= xi - x[i-r+8];  /* n = 8 */
  sum_m += prod_n;

  /* m = 7 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  prod_n *= xi - x[i-r+4];  /* n = 4 */
  prod_n *= xi - x[i-r+5];  /* n = 5 */
  prod_n *= xi - x[i-r+8];  /* n = 8 */
  sum_m += prod_n;

  /* m = 8 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  prod_n *= xi - x[i-r+4];  /* n = 4 */
  prod_n *= xi - x[i-r+5];  /* n = 5 */
  prod_n *= xi - x[i-r+7];  /* n = 7 */
  sum_m += prod_n;

  prod_m = 1.0;
  prod_m *= x[i-r+6] - x[i-r+0];
  prod_m *= x[i-r+6] - x[i-r+1];
  prod_m *= x[i-r+6] - x[i-r+2];
  prod_m *= x[i-r+6] - x[i-r+3];
  prod_m *= x[i-r+6] - x[i-r+4];
  prod_m *= x[i-r+6] - x[i-r+5];
  prod_m *= x[i-r+6] - x[i-r+7];
  prod_m *= x[i-r+6] - x[i-r+8];

  sum_l += sum_m / prod_m * (x[i-r+2+1] - x[i-r+2]);

  /* l = 7 */
  sum_m = 0.0;

  /* m = 0 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  prod_n *= xi - x[i-r+4];  /* n = 4 */
  prod_n *= xi - x[i-r+5];  /* n = 5 */
  prod_n *= xi - x[i-r+6];  /* n = 6 */
  prod_n *= xi - x[i-r+8];  /* n = 8 */
  sum_m += prod_n;

  /* m = 1 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  prod_n *= xi - x[i-r+4];  /* n = 4 */
  prod_n *= xi - x[i-r+5];  /* n = 5 */
  prod_n *= xi - x[i-r+6];  /* n = 6 */
  prod_n *= xi - x[i-r+8];  /* n = 8 */
  sum_m += prod_n;

  /* m = 2 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  prod_n *= xi - x[i-r+4];  /* n = 4 */
  prod_n *= xi - x[i-r+5];  /* n = 5 */
  prod_n *= xi - x[i-r+6];  /* n = 6 */
  prod_n *= xi - x[i-r+8];  /* n = 8 */
  sum_m += prod_n;

  /* m = 3 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+4];  /* n = 4 */
  prod_n *= xi - x[i-r+5];  /* n = 5 */
  prod_n *= xi - x[i-r+6];  /* n = 6 */
  prod_n *= xi - x[i-r+8];  /* n = 8 */
  sum_m += prod_n;

  /* m = 4 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  prod_n *= xi - x[i-r+5];  /* n = 5 */
  prod_n *= xi - x[i-r+6];  /* n = 6 */
  prod_n *= xi - x[i-r+8];  /* n = 8 */
  sum_m += prod_n;

  /* m = 5 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  prod_n *= xi - x[i-r+4];  /* n = 4 */
  prod_n *= xi - x[i-r+6];  /* n = 6 */
  prod_n *= xi - x[i-r+8];  /* n = 8 */
  sum_m += prod_n;

  /* m = 6 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  prod_n *= xi - x[i-r+4];  /* n = 4 */
  prod_n *= xi - x[i-r+5];  /* n = 5 */
  prod_n *= xi - x[i-r+8];  /* n = 8 */
  sum_m += prod_n;

  /* m = 8 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  prod_n *= xi - x[i-r+4];  /* n = 4 */
  prod_n *= xi - x[i-r+5];  /* n = 5 */
  prod_n *= xi - x[i-r+6];  /* n = 6 */
  sum_m += prod_n;

  prod_m = 1.0;
  prod_m *= x[i-r+7] - x[i-r+0];
  prod_m *= x[i-r+7] - x[i-r+1];
  prod_m *= x[i-r+7] - x[i-r+2];
  prod_m *= x[i-r+7] - x[i-r+3];
  prod_m *= x[i-r+7] - x[i-r+4];
  prod_m *= x[i-r+7] - x[i-r+5];
  prod_m *= x[i-r+7] - x[i-r+6];
  prod_m *= x[i-r+7] - x[i-r+8];

  sum_l += sum_m / prod_m * (x[i-r+2+1] - x[i-r+2]);

  /* l = 8 */
  sum_m = 0.0;

  /* m = 0 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  prod_n *= xi - x[i-r+4];  /* n = 4 */
  prod_n *= xi - x[i-r+5];  /* n = 5 */
  prod_n *= xi - x[i-r+6];  /* n = 6 */
  prod_n *= xi - x[i-r+7];  /* n = 7 */
  sum_m += prod_n;

  /* m = 1 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  prod_n *= xi - x[i-r+4];  /* n = 4 */
  prod_n *= xi - x[i-r+5];  /* n = 5 */
  prod_n *= xi - x[i-r+6];  /* n = 6 */
  prod_n *= xi - x[i-r+7];  /* n = 7 */
  sum_m += prod_n;

  /* m = 2 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  prod_n *= xi - x[i-r+4];  /* n = 4 */
  prod_n *= xi - x[i-r+5];  /* n = 5 */
  prod_n *= xi - x[i-r+6];  /* n = 6 */
  prod_n *= xi - x[i-r+7];  /* n = 7 */
  sum_m += prod_n;

  /* m = 3 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+4];  /* n = 4 */
  prod_n *= xi - x[i-r+5];  /* n = 5 */
  prod_n *= xi - x[i-r+6];  /* n = 6 */
  prod_n *= xi - x[i-r+7];  /* n = 7 */
  sum_m += prod_n;

  /* m = 4 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  prod_n *= xi - x[i-r+5];  /* n = 5 */
  prod_n *= xi - x[i-r+6];  /* n = 6 */
  prod_n *= xi - x[i-r+7];  /* n = 7 */
  sum_m += prod_n;

  /* m = 5 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  prod_n *= xi - x[i-r+4];  /* n = 4 */
  prod_n *= xi - x[i-r+6];  /* n = 6 */
  prod_n *= xi - x[i-r+7];  /* n = 7 */
  sum_m += prod_n;

  /* m = 6 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  prod_n *= xi - x[i-r+4];  /* n = 4 */
  prod_n *= xi - x[i-r+5];  /* n = 5 */
  prod_n *= xi - x[i-r+7];  /* n = 7 */
  sum_m += prod_n;

  /* m = 7 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  prod_n *= xi - x[i-r+4];  /* n = 4 */
  prod_n *= xi - x[i-r+5];  /* n = 5 */
  prod_n *= xi - x[i-r+6];  /* n = 6 */
  sum_m += prod_n;

  prod_m = 1.0;
  prod_m *= x[i-r+8] - x[i-r+0];
  prod_m *= x[i-r+8] - x[i-r+1];
  prod_m *= x[i-r+8] - x[i-r+2];
  prod_m *= x[i-r+8] - x[i-r+3];
  prod_m *= x[i-r+8] - x[i-r+4];
  prod_m *= x[i-r+8] - x[i-r+5];
  prod_m *= x[i-r+8] - x[i-r+6];
  prod_m *= x[i-r+8] - x[i-r+7];

  sum_l += sum_m / prod_m * (x[i-r+2+1] - x[i-r+2]);

  c[2] = sum_l;

  /* j = 3 */
  sum_l = 0.0;

  /* l = 4 */
  sum_m = 0.0;

  /* m = 0 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  prod_n *= xi - x[i-r+5];  /* n = 5 */
  prod_n *= xi - x[i-r+6];  /* n = 6 */
  prod_n *= xi - x[i-r+7];  /* n = 7 */
  prod_n *= xi - x[i-r+8];  /* n = 8 */
  sum_m += prod_n;

  /* m = 1 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  prod_n *= xi - x[i-r+5];  /* n = 5 */
  prod_n *= xi - x[i-r+6];  /* n = 6 */
  prod_n *= xi - x[i-r+7];  /* n = 7 */
  prod_n *= xi - x[i-r+8];  /* n = 8 */
  sum_m += prod_n;

  /* m = 2 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  prod_n *= xi - x[i-r+5];  /* n = 5 */
  prod_n *= xi - x[i-r+6];  /* n = 6 */
  prod_n *= xi - x[i-r+7];  /* n = 7 */
  prod_n *= xi - x[i-r+8];  /* n = 8 */
  sum_m += prod_n;

  /* m = 3 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+5];  /* n = 5 */
  prod_n *= xi - x[i-r+6];  /* n = 6 */
  prod_n *= xi - x[i-r+7];  /* n = 7 */
  prod_n *= xi - x[i-r+8];  /* n = 8 */
  sum_m += prod_n;

  /* m = 5 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  prod_n *= xi - x[i-r+6];  /* n = 6 */
  prod_n *= xi - x[i-r+7];  /* n = 7 */
  prod_n *= xi - x[i-r+8];  /* n = 8 */
  sum_m += prod_n;

  /* m = 6 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  prod_n *= xi - x[i-r+5];  /* n = 5 */
  prod_n *= xi - x[i-r+7];  /* n = 7 */
  prod_n *= xi - x[i-r+8];  /* n = 8 */
  sum_m += prod_n;

  /* m = 7 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  prod_n *= xi - x[i-r+5];  /* n = 5 */
  prod_n *= xi - x[i-r+6];  /* n = 6 */
  prod_n *= xi - x[i-r+8];  /* n = 8 */
  sum_m += prod_n;

  /* m = 8 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  prod_n *= xi - x[i-r+5];  /* n = 5 */
  prod_n *= xi - x[i-r+6];  /* n = 6 */
  prod_n *= xi - x[i-r+7];  /* n = 7 */
  sum_m += prod_n;

  prod_m = 1.0;
  prod_m *= x[i-r+4] - x[i-r+0];
  prod_m *= x[i-r+4] - x[i-r+1];
  prod_m *= x[i-r+4] - x[i-r+2];
  prod_m *= x[i-r+4] - x[i-r+3];
  prod_m *= x[i-r+4] - x[i-r+5];
  prod_m *= x[i-r+4] - x[i-r+6];
  prod_m *= x[i-r+4] - x[i-r+7];
  prod_m *= x[i-r+4] - x[i-r+8];

  sum_l += sum_m / prod_m * (x[i-r+3+1] - x[i-r+3]);

  /* l = 5 */
  sum_m = 0.0;

  /* m = 0 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  prod_n *= xi - x[i-r+4];  /* n = 4 */
  prod_n *= xi - x[i-r+6];  /* n = 6 */
  prod_n *= xi - x[i-r+7];  /* n = 7 */
  prod_n *= xi - x[i-r+8];  /* n = 8 */
  sum_m += prod_n;

  /* m = 1 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  prod_n *= xi - x[i-r+4];  /* n = 4 */
  prod_n *= xi - x[i-r+6];  /* n = 6 */
  prod_n *= xi - x[i-r+7];  /* n = 7 */
  prod_n *= xi - x[i-r+8];  /* n = 8 */
  sum_m += prod_n;

  /* m = 2 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  prod_n *= xi - x[i-r+4];  /* n = 4 */
  prod_n *= xi - x[i-r+6];  /* n = 6 */
  prod_n *= xi - x[i-r+7];  /* n = 7 */
  prod_n *= xi - x[i-r+8];  /* n = 8 */
  sum_m += prod_n;

  /* m = 3 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+4];  /* n = 4 */
  prod_n *= xi - x[i-r+6];  /* n = 6 */
  prod_n *= xi - x[i-r+7];  /* n = 7 */
  prod_n *= xi - x[i-r+8];  /* n = 8 */
  sum_m += prod_n;

  /* m = 4 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  prod_n *= xi - x[i-r+6];  /* n = 6 */
  prod_n *= xi - x[i-r+7];  /* n = 7 */
  prod_n *= xi - x[i-r+8];  /* n = 8 */
  sum_m += prod_n;

  /* m = 6 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  prod_n *= xi - x[i-r+4];  /* n = 4 */
  prod_n *= xi - x[i-r+7];  /* n = 7 */
  prod_n *= xi - x[i-r+8];  /* n = 8 */
  sum_m += prod_n;

  /* m = 7 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  prod_n *= xi - x[i-r+4];  /* n = 4 */
  prod_n *= xi - x[i-r+6];  /* n = 6 */
  prod_n *= xi - x[i-r+8];  /* n = 8 */
  sum_m += prod_n;

  /* m = 8 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  prod_n *= xi - x[i-r+4];  /* n = 4 */
  prod_n *= xi - x[i-r+6];  /* n = 6 */
  prod_n *= xi - x[i-r+7];  /* n = 7 */
  sum_m += prod_n;

  prod_m = 1.0;
  prod_m *= x[i-r+5] - x[i-r+0];
  prod_m *= x[i-r+5] - x[i-r+1];
  prod_m *= x[i-r+5] - x[i-r+2];
  prod_m *= x[i-r+5] - x[i-r+3];
  prod_m *= x[i-r+5] - x[i-r+4];
  prod_m *= x[i-r+5] - x[i-r+6];
  prod_m *= x[i-r+5] - x[i-r+7];
  prod_m *= x[i-r+5] - x[i-r+8];

  sum_l += sum_m / prod_m * (x[i-r+3+1] - x[i-r+3]);

  /* l = 6 */
  sum_m = 0.0;

  /* m = 0 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  prod_n *= xi - x[i-r+4];  /* n = 4 */
  prod_n *= xi - x[i-r+5];  /* n = 5 */
  prod_n *= xi - x[i-r+7];  /* n = 7 */
  prod_n *= xi - x[i-r+8];  /* n = 8 */
  sum_m += prod_n;

  /* m = 1 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  prod_n *= xi - x[i-r+4];  /* n = 4 */
  prod_n *= xi - x[i-r+5];  /* n = 5 */
  prod_n *= xi - x[i-r+7];  /* n = 7 */
  prod_n *= xi - x[i-r+8];  /* n = 8 */
  sum_m += prod_n;

  /* m = 2 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  prod_n *= xi - x[i-r+4];  /* n = 4 */
  prod_n *= xi - x[i-r+5];  /* n = 5 */
  prod_n *= xi - x[i-r+7];  /* n = 7 */
  prod_n *= xi - x[i-r+8];  /* n = 8 */
  sum_m += prod_n;

  /* m = 3 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+4];  /* n = 4 */
  prod_n *= xi - x[i-r+5];  /* n = 5 */
  prod_n *= xi - x[i-r+7];  /* n = 7 */
  prod_n *= xi - x[i-r+8];  /* n = 8 */
  sum_m += prod_n;

  /* m = 4 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  prod_n *= xi - x[i-r+5];  /* n = 5 */
  prod_n *= xi - x[i-r+7];  /* n = 7 */
  prod_n *= xi - x[i-r+8];  /* n = 8 */
  sum_m += prod_n;

  /* m = 5 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  prod_n *= xi - x[i-r+4];  /* n = 4 */
  prod_n *= xi - x[i-r+7];  /* n = 7 */
  prod_n *= xi - x[i-r+8];  /* n = 8 */
  sum_m += prod_n;

  /* m = 7 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  prod_n *= xi - x[i-r+4];  /* n = 4 */
  prod_n *= xi - x[i-r+5];  /* n = 5 */
  prod_n *= xi - x[i-r+8];  /* n = 8 */
  sum_m += prod_n;

  /* m = 8 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  prod_n *= xi - x[i-r+4];  /* n = 4 */
  prod_n *= xi - x[i-r+5];  /* n = 5 */
  prod_n *= xi - x[i-r+7];  /* n = 7 */
  sum_m += prod_n;

  prod_m = 1.0;
  prod_m *= x[i-r+6] - x[i-r+0];
  prod_m *= x[i-r+6] - x[i-r+1];
  prod_m *= x[i-r+6] - x[i-r+2];
  prod_m *= x[i-r+6] - x[i-r+3];
  prod_m *= x[i-r+6] - x[i-r+4];
  prod_m *= x[i-r+6] - x[i-r+5];
  prod_m *= x[i-r+6] - x[i-r+7];
  prod_m *= x[i-r+6] - x[i-r+8];

  sum_l += sum_m / prod_m * (x[i-r+3+1] - x[i-r+3]);

  /* l = 7 */
  sum_m = 0.0;

  /* m = 0 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  prod_n *= xi - x[i-r+4];  /* n = 4 */
  prod_n *= xi - x[i-r+5];  /* n = 5 */
  prod_n *= xi - x[i-r+6];  /* n = 6 */
  prod_n *= xi - x[i-r+8];  /* n = 8 */
  sum_m += prod_n;

  /* m = 1 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  prod_n *= xi - x[i-r+4];  /* n = 4 */
  prod_n *= xi - x[i-r+5];  /* n = 5 */
  prod_n *= xi - x[i-r+6];  /* n = 6 */
  prod_n *= xi - x[i-r+8];  /* n = 8 */
  sum_m += prod_n;

  /* m = 2 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  prod_n *= xi - x[i-r+4];  /* n = 4 */
  prod_n *= xi - x[i-r+5];  /* n = 5 */
  prod_n *= xi - x[i-r+6];  /* n = 6 */
  prod_n *= xi - x[i-r+8];  /* n = 8 */
  sum_m += prod_n;

  /* m = 3 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+4];  /* n = 4 */
  prod_n *= xi - x[i-r+5];  /* n = 5 */
  prod_n *= xi - x[i-r+6];  /* n = 6 */
  prod_n *= xi - x[i-r+8];  /* n = 8 */
  sum_m += prod_n;

  /* m = 4 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  prod_n *= xi - x[i-r+5];  /* n = 5 */
  prod_n *= xi - x[i-r+6];  /* n = 6 */
  prod_n *= xi - x[i-r+8];  /* n = 8 */
  sum_m += prod_n;

  /* m = 5 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  prod_n *= xi - x[i-r+4];  /* n = 4 */
  prod_n *= xi - x[i-r+6];  /* n = 6 */
  prod_n *= xi - x[i-r+8];  /* n = 8 */
  sum_m += prod_n;

  /* m = 6 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  prod_n *= xi - x[i-r+4];  /* n = 4 */
  prod_n *= xi - x[i-r+5];  /* n = 5 */
  prod_n *= xi - x[i-r+8];  /* n = 8 */
  sum_m += prod_n;

  /* m = 8 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  prod_n *= xi - x[i-r+4];  /* n = 4 */
  prod_n *= xi - x[i-r+5];  /* n = 5 */
  prod_n *= xi - x[i-r+6];  /* n = 6 */
  sum_m += prod_n;

  prod_m = 1.0;
  prod_m *= x[i-r+7] - x[i-r+0];
  prod_m *= x[i-r+7] - x[i-r+1];
  prod_m *= x[i-r+7] - x[i-r+2];
  prod_m *= x[i-r+7] - x[i-r+3];
  prod_m *= x[i-r+7] - x[i-r+4];
  prod_m *= x[i-r+7] - x[i-r+5];
  prod_m *= x[i-r+7] - x[i-r+6];
  prod_m *= x[i-r+7] - x[i-r+8];

  sum_l += sum_m / prod_m * (x[i-r+3+1] - x[i-r+3]);

  /* l = 8 */
  sum_m = 0.0;

  /* m = 0 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  prod_n *= xi - x[i-r+4];  /* n = 4 */
  prod_n *= xi - x[i-r+5];  /* n = 5 */
  prod_n *= xi - x[i-r+6];  /* n = 6 */
  prod_n *= xi - x[i-r+7];  /* n = 7 */
  sum_m += prod_n;

  /* m = 1 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  prod_n *= xi - x[i-r+4];  /* n = 4 */
  prod_n *= xi - x[i-r+5];  /* n = 5 */
  prod_n *= xi - x[i-r+6];  /* n = 6 */
  prod_n *= xi - x[i-r+7];  /* n = 7 */
  sum_m += prod_n;

  /* m = 2 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  prod_n *= xi - x[i-r+4];  /* n = 4 */
  prod_n *= xi - x[i-r+5];  /* n = 5 */
  prod_n *= xi - x[i-r+6];  /* n = 6 */
  prod_n *= xi - x[i-r+7];  /* n = 7 */
  sum_m += prod_n;

  /* m = 3 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+4];  /* n = 4 */
  prod_n *= xi - x[i-r+5];  /* n = 5 */
  prod_n *= xi - x[i-r+6];  /* n = 6 */
  prod_n *= xi - x[i-r+7];  /* n = 7 */
  sum_m += prod_n;

  /* m = 4 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  prod_n *= xi - x[i-r+5];  /* n = 5 */
  prod_n *= xi - x[i-r+6];  /* n = 6 */
  prod_n *= xi - x[i-r+7];  /* n = 7 */
  sum_m += prod_n;

  /* m = 5 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  prod_n *= xi - x[i-r+4];  /* n = 4 */
  prod_n *= xi - x[i-r+6];  /* n = 6 */
  prod_n *= xi - x[i-r+7];  /* n = 7 */
  sum_m += prod_n;

  /* m = 6 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  prod_n *= xi - x[i-r+4];  /* n = 4 */
  prod_n *= xi - x[i-r+5];  /* n = 5 */
  prod_n *= xi - x[i-r+7];  /* n = 7 */
  sum_m += prod_n;

  /* m = 7 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  prod_n *= xi - x[i-r+4];  /* n = 4 */
  prod_n *= xi - x[i-r+5];  /* n = 5 */
  prod_n *= xi - x[i-r+6];  /* n = 6 */
  sum_m += prod_n;

  prod_m = 1.0;
  prod_m *= x[i-r+8] - x[i-r+0];
  prod_m *= x[i-r+8] - x[i-r+1];
  prod_m *= x[i-r+8] - x[i-r+2];
  prod_m *= x[i-r+8] - x[i-r+3];
  prod_m *= x[i-r+8] - x[i-r+4];
  prod_m *= x[i-r+8] - x[i-r+5];
  prod_m *= x[i-r+8] - x[i-r+6];
  prod_m *= x[i-r+8] - x[i-r+7];

  sum_l += sum_m / prod_m * (x[i-r+3+1] - x[i-r+3]);

  c[3] = sum_l;

  /* j = 4 */
  sum_l = 0.0;

  /* l = 5 */
  sum_m = 0.0;

  /* m = 0 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  prod_n *= xi - x[i-r+4];  /* n = 4 */
  prod_n *= xi - x[i-r+6];  /* n = 6 */
  prod_n *= xi - x[i-r+7];  /* n = 7 */
  prod_n *= xi - x[i-r+8];  /* n = 8 */
  sum_m += prod_n;

  /* m = 1 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  prod_n *= xi - x[i-r+4];  /* n = 4 */
  prod_n *= xi - x[i-r+6];  /* n = 6 */
  prod_n *= xi - x[i-r+7];  /* n = 7 */
  prod_n *= xi - x[i-r+8];  /* n = 8 */
  sum_m += prod_n;

  /* m = 2 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  prod_n *= xi - x[i-r+4];  /* n = 4 */
  prod_n *= xi - x[i-r+6];  /* n = 6 */
  prod_n *= xi - x[i-r+7];  /* n = 7 */
  prod_n *= xi - x[i-r+8];  /* n = 8 */
  sum_m += prod_n;

  /* m = 3 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+4];  /* n = 4 */
  prod_n *= xi - x[i-r+6];  /* n = 6 */
  prod_n *= xi - x[i-r+7];  /* n = 7 */
  prod_n *= xi - x[i-r+8];  /* n = 8 */
  sum_m += prod_n;

  /* m = 4 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  prod_n *= xi - x[i-r+6];  /* n = 6 */
  prod_n *= xi - x[i-r+7];  /* n = 7 */
  prod_n *= xi - x[i-r+8];  /* n = 8 */
  sum_m += prod_n;

  /* m = 6 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  prod_n *= xi - x[i-r+4];  /* n = 4 */
  prod_n *= xi - x[i-r+7];  /* n = 7 */
  prod_n *= xi - x[i-r+8];  /* n = 8 */
  sum_m += prod_n;

  /* m = 7 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  prod_n *= xi - x[i-r+4];  /* n = 4 */
  prod_n *= xi - x[i-r+6];  /* n = 6 */
  prod_n *= xi - x[i-r+8];  /* n = 8 */
  sum_m += prod_n;

  /* m = 8 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  prod_n *= xi - x[i-r+4];  /* n = 4 */
  prod_n *= xi - x[i-r+6];  /* n = 6 */
  prod_n *= xi - x[i-r+7];  /* n = 7 */
  sum_m += prod_n;

  prod_m = 1.0;
  prod_m *= x[i-r+5] - x[i-r+0];
  prod_m *= x[i-r+5] - x[i-r+1];
  prod_m *= x[i-r+5] - x[i-r+2];
  prod_m *= x[i-r+5] - x[i-r+3];
  prod_m *= x[i-r+5] - x[i-r+4];
  prod_m *= x[i-r+5] - x[i-r+6];
  prod_m *= x[i-r+5] - x[i-r+7];
  prod_m *= x[i-r+5] - x[i-r+8];

  sum_l += sum_m / prod_m * (x[i-r+4+1] - x[i-r+4]);

  /* l = 6 */
  sum_m = 0.0;

  /* m = 0 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  prod_n *= xi - x[i-r+4];  /* n = 4 */
  prod_n *= xi - x[i-r+5];  /* n = 5 */
  prod_n *= xi - x[i-r+7];  /* n = 7 */
  prod_n *= xi - x[i-r+8];  /* n = 8 */
  sum_m += prod_n;

  /* m = 1 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  prod_n *= xi - x[i-r+4];  /* n = 4 */
  prod_n *= xi - x[i-r+5];  /* n = 5 */
  prod_n *= xi - x[i-r+7];  /* n = 7 */
  prod_n *= xi - x[i-r+8];  /* n = 8 */
  sum_m += prod_n;

  /* m = 2 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  prod_n *= xi - x[i-r+4];  /* n = 4 */
  prod_n *= xi - x[i-r+5];  /* n = 5 */
  prod_n *= xi - x[i-r+7];  /* n = 7 */
  prod_n *= xi - x[i-r+8];  /* n = 8 */
  sum_m += prod_n;

  /* m = 3 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+4];  /* n = 4 */
  prod_n *= xi - x[i-r+5];  /* n = 5 */
  prod_n *= xi - x[i-r+7];  /* n = 7 */
  prod_n *= xi - x[i-r+8];  /* n = 8 */
  sum_m += prod_n;

  /* m = 4 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  prod_n *= xi - x[i-r+5];  /* n = 5 */
  prod_n *= xi - x[i-r+7];  /* n = 7 */
  prod_n *= xi - x[i-r+8];  /* n = 8 */
  sum_m += prod_n;

  /* m = 5 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  prod_n *= xi - x[i-r+4];  /* n = 4 */
  prod_n *= xi - x[i-r+7];  /* n = 7 */
  prod_n *= xi - x[i-r+8];  /* n = 8 */
  sum_m += prod_n;

  /* m = 7 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  prod_n *= xi - x[i-r+4];  /* n = 4 */
  prod_n *= xi - x[i-r+5];  /* n = 5 */
  prod_n *= xi - x[i-r+8];  /* n = 8 */
  sum_m += prod_n;

  /* m = 8 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  prod_n *= xi - x[i-r+4];  /* n = 4 */
  prod_n *= xi - x[i-r+5];  /* n = 5 */
  prod_n *= xi - x[i-r+7];  /* n = 7 */
  sum_m += prod_n;

  prod_m = 1.0;
  prod_m *= x[i-r+6] - x[i-r+0];
  prod_m *= x[i-r+6] - x[i-r+1];
  prod_m *= x[i-r+6] - x[i-r+2];
  prod_m *= x[i-r+6] - x[i-r+3];
  prod_m *= x[i-r+6] - x[i-r+4];
  prod_m *= x[i-r+6] - x[i-r+5];
  prod_m *= x[i-r+6] - x[i-r+7];
  prod_m *= x[i-r+6] - x[i-r+8];

  sum_l += sum_m / prod_m * (x[i-r+4+1] - x[i-r+4]);

  /* l = 7 */
  sum_m = 0.0;

  /* m = 0 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  prod_n *= xi - x[i-r+4];  /* n = 4 */
  prod_n *= xi - x[i-r+5];  /* n = 5 */
  prod_n *= xi - x[i-r+6];  /* n = 6 */
  prod_n *= xi - x[i-r+8];  /* n = 8 */
  sum_m += prod_n;

  /* m = 1 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  prod_n *= xi - x[i-r+4];  /* n = 4 */
  prod_n *= xi - x[i-r+5];  /* n = 5 */
  prod_n *= xi - x[i-r+6];  /* n = 6 */
  prod_n *= xi - x[i-r+8];  /* n = 8 */
  sum_m += prod_n;

  /* m = 2 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  prod_n *= xi - x[i-r+4];  /* n = 4 */
  prod_n *= xi - x[i-r+5];  /* n = 5 */
  prod_n *= xi - x[i-r+6];  /* n = 6 */
  prod_n *= xi - x[i-r+8];  /* n = 8 */
  sum_m += prod_n;

  /* m = 3 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+4];  /* n = 4 */
  prod_n *= xi - x[i-r+5];  /* n = 5 */
  prod_n *= xi - x[i-r+6];  /* n = 6 */
  prod_n *= xi - x[i-r+8];  /* n = 8 */
  sum_m += prod_n;

  /* m = 4 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  prod_n *= xi - x[i-r+5];  /* n = 5 */
  prod_n *= xi - x[i-r+6];  /* n = 6 */
  prod_n *= xi - x[i-r+8];  /* n = 8 */
  sum_m += prod_n;

  /* m = 5 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  prod_n *= xi - x[i-r+4];  /* n = 4 */
  prod_n *= xi - x[i-r+6];  /* n = 6 */
  prod_n *= xi - x[i-r+8];  /* n = 8 */
  sum_m += prod_n;

  /* m = 6 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  prod_n *= xi - x[i-r+4];  /* n = 4 */
  prod_n *= xi - x[i-r+5];  /* n = 5 */
  prod_n *= xi - x[i-r+8];  /* n = 8 */
  sum_m += prod_n;

  /* m = 8 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  prod_n *= xi - x[i-r+4];  /* n = 4 */
  prod_n *= xi - x[i-r+5];  /* n = 5 */
  prod_n *= xi - x[i-r+6];  /* n = 6 */
  sum_m += prod_n;

  prod_m = 1.0;
  prod_m *= x[i-r+7] - x[i-r+0];
  prod_m *= x[i-r+7] - x[i-r+1];
  prod_m *= x[i-r+7] - x[i-r+2];
  prod_m *= x[i-r+7] - x[i-r+3];
  prod_m *= x[i-r+7] - x[i-r+4];
  prod_m *= x[i-r+7] - x[i-r+5];
  prod_m *= x[i-r+7] - x[i-r+6];
  prod_m *= x[i-r+7] - x[i-r+8];

  sum_l += sum_m / prod_m * (x[i-r+4+1] - x[i-r+4]);

  /* l = 8 */
  sum_m = 0.0;

  /* m = 0 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  prod_n *= xi - x[i-r+4];  /* n = 4 */
  prod_n *= xi - x[i-r+5];  /* n = 5 */
  prod_n *= xi - x[i-r+6];  /* n = 6 */
  prod_n *= xi - x[i-r+7];  /* n = 7 */
  sum_m += prod_n;

  /* m = 1 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  prod_n *= xi - x[i-r+4];  /* n = 4 */
  prod_n *= xi - x[i-r+5];  /* n = 5 */
  prod_n *= xi - x[i-r+6];  /* n = 6 */
  prod_n *= xi - x[i-r+7];  /* n = 7 */
  sum_m += prod_n;

  /* m = 2 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  prod_n *= xi - x[i-r+4];  /* n = 4 */
  prod_n *= xi - x[i-r+5];  /* n = 5 */
  prod_n *= xi - x[i-r+6];  /* n = 6 */
  prod_n *= xi - x[i-r+7];  /* n = 7 */
  sum_m += prod_n;

  /* m = 3 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+4];  /* n = 4 */
  prod_n *= xi - x[i-r+5];  /* n = 5 */
  prod_n *= xi - x[i-r+6];  /* n = 6 */
  prod_n *= xi - x[i-r+7];  /* n = 7 */
  sum_m += prod_n;

  /* m = 4 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  prod_n *= xi - x[i-r+5];  /* n = 5 */
  prod_n *= xi - x[i-r+6];  /* n = 6 */
  prod_n *= xi - x[i-r+7];  /* n = 7 */
  sum_m += prod_n;

  /* m = 5 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  prod_n *= xi - x[i-r+4];  /* n = 4 */
  prod_n *= xi - x[i-r+6];  /* n = 6 */
  prod_n *= xi - x[i-r+7];  /* n = 7 */
  sum_m += prod_n;

  /* m = 6 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  prod_n *= xi - x[i-r+4];  /* n = 4 */
  prod_n *= xi - x[i-r+5];  /* n = 5 */
  prod_n *= xi - x[i-r+7];  /* n = 7 */
  sum_m += prod_n;

  /* m = 7 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  prod_n *= xi - x[i-r+4];  /* n = 4 */
  prod_n *= xi - x[i-r+5];  /* n = 5 */
  prod_n *= xi - x[i-r+6];  /* n = 6 */
  sum_m += prod_n;

  prod_m = 1.0;
  prod_m *= x[i-r+8] - x[i-r+0];
  prod_m *= x[i-r+8] - x[i-r+1];
  prod_m *= x[i-r+8] - x[i-r+2];
  prod_m *= x[i-r+8] - x[i-r+3];
  prod_m *= x[i-r+8] - x[i-r+4];
  prod_m *= x[i-r+8] - x[i-r+5];
  prod_m *= x[i-r+8] - x[i-r+6];
  prod_m *= x[i-r+8] - x[i-r+7];

  sum_l += sum_m / prod_m * (x[i-r+4+1] - x[i-r+4]);

  c[4] = sum_l;

  /* j = 5 */
  sum_l = 0.0;

  /* l = 6 */
  sum_m = 0.0;

  /* m = 0 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  prod_n *= xi - x[i-r+4];  /* n = 4 */
  prod_n *= xi - x[i-r+5];  /* n = 5 */
  prod_n *= xi - x[i-r+7];  /* n = 7 */
  prod_n *= xi - x[i-r+8];  /* n = 8 */
  sum_m += prod_n;

  /* m = 1 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  prod_n *= xi - x[i-r+4];  /* n = 4 */
  prod_n *= xi - x[i-r+5];  /* n = 5 */
  prod_n *= xi - x[i-r+7];  /* n = 7 */
  prod_n *= xi - x[i-r+8];  /* n = 8 */
  sum_m += prod_n;

  /* m = 2 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  prod_n *= xi - x[i-r+4];  /* n = 4 */
  prod_n *= xi - x[i-r+5];  /* n = 5 */
  prod_n *= xi - x[i-r+7];  /* n = 7 */
  prod_n *= xi - x[i-r+8];  /* n = 8 */
  sum_m += prod_n;

  /* m = 3 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+4];  /* n = 4 */
  prod_n *= xi - x[i-r+5];  /* n = 5 */
  prod_n *= xi - x[i-r+7];  /* n = 7 */
  prod_n *= xi - x[i-r+8];  /* n = 8 */
  sum_m += prod_n;

  /* m = 4 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  prod_n *= xi - x[i-r+5];  /* n = 5 */
  prod_n *= xi - x[i-r+7];  /* n = 7 */
  prod_n *= xi - x[i-r+8];  /* n = 8 */
  sum_m += prod_n;

  /* m = 5 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  prod_n *= xi - x[i-r+4];  /* n = 4 */
  prod_n *= xi - x[i-r+7];  /* n = 7 */
  prod_n *= xi - x[i-r+8];  /* n = 8 */
  sum_m += prod_n;

  /* m = 7 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  prod_n *= xi - x[i-r+4];  /* n = 4 */
  prod_n *= xi - x[i-r+5];  /* n = 5 */
  prod_n *= xi - x[i-r+8];  /* n = 8 */
  sum_m += prod_n;

  /* m = 8 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  prod_n *= xi - x[i-r+4];  /* n = 4 */
  prod_n *= xi - x[i-r+5];  /* n = 5 */
  prod_n *= xi - x[i-r+7];  /* n = 7 */
  sum_m += prod_n;

  prod_m = 1.0;
  prod_m *= x[i-r+6] - x[i-r+0];
  prod_m *= x[i-r+6] - x[i-r+1];
  prod_m *= x[i-r+6] - x[i-r+2];
  prod_m *= x[i-r+6] - x[i-r+3];
  prod_m *= x[i-r+6] - x[i-r+4];
  prod_m *= x[i-r+6] - x[i-r+5];
  prod_m *= x[i-r+6] - x[i-r+7];
  prod_m *= x[i-r+6] - x[i-r+8];

  sum_l += sum_m / prod_m * (x[i-r+5+1] - x[i-r+5]);

  /* l = 7 */
  sum_m = 0.0;

  /* m = 0 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  prod_n *= xi - x[i-r+4];  /* n = 4 */
  prod_n *= xi - x[i-r+5];  /* n = 5 */
  prod_n *= xi - x[i-r+6];  /* n = 6 */
  prod_n *= xi - x[i-r+8];  /* n = 8 */
  sum_m += prod_n;

  /* m = 1 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  prod_n *= xi - x[i-r+4];  /* n = 4 */
  prod_n *= xi - x[i-r+5];  /* n = 5 */
  prod_n *= xi - x[i-r+6];  /* n = 6 */
  prod_n *= xi - x[i-r+8];  /* n = 8 */
  sum_m += prod_n;

  /* m = 2 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  prod_n *= xi - x[i-r+4];  /* n = 4 */
  prod_n *= xi - x[i-r+5];  /* n = 5 */
  prod_n *= xi - x[i-r+6];  /* n = 6 */
  prod_n *= xi - x[i-r+8];  /* n = 8 */
  sum_m += prod_n;

  /* m = 3 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+4];  /* n = 4 */
  prod_n *= xi - x[i-r+5];  /* n = 5 */
  prod_n *= xi - x[i-r+6];  /* n = 6 */
  prod_n *= xi - x[i-r+8];  /* n = 8 */
  sum_m += prod_n;

  /* m = 4 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  prod_n *= xi - x[i-r+5];  /* n = 5 */
  prod_n *= xi - x[i-r+6];  /* n = 6 */
  prod_n *= xi - x[i-r+8];  /* n = 8 */
  sum_m += prod_n;

  /* m = 5 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  prod_n *= xi - x[i-r+4];  /* n = 4 */
  prod_n *= xi - x[i-r+6];  /* n = 6 */
  prod_n *= xi - x[i-r+8];  /* n = 8 */
  sum_m += prod_n;

  /* m = 6 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  prod_n *= xi - x[i-r+4];  /* n = 4 */
  prod_n *= xi - x[i-r+5];  /* n = 5 */
  prod_n *= xi - x[i-r+8];  /* n = 8 */
  sum_m += prod_n;

  /* m = 8 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  prod_n *= xi - x[i-r+4];  /* n = 4 */
  prod_n *= xi - x[i-r+5];  /* n = 5 */
  prod_n *= xi - x[i-r+6];  /* n = 6 */
  sum_m += prod_n;

  prod_m = 1.0;
  prod_m *= x[i-r+7] - x[i-r+0];
  prod_m *= x[i-r+7] - x[i-r+1];
  prod_m *= x[i-r+7] - x[i-r+2];
  prod_m *= x[i-r+7] - x[i-r+3];
  prod_m *= x[i-r+7] - x[i-r+4];
  prod_m *= x[i-r+7] - x[i-r+5];
  prod_m *= x[i-r+7] - x[i-r+6];
  prod_m *= x[i-r+7] - x[i-r+8];

  sum_l += sum_m / prod_m * (x[i-r+5+1] - x[i-r+5]);

  /* l = 8 */
  sum_m = 0.0;

  /* m = 0 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  prod_n *= xi - x[i-r+4];  /* n = 4 */
  prod_n *= xi - x[i-r+5];  /* n = 5 */
  prod_n *= xi - x[i-r+6];  /* n = 6 */
  prod_n *= xi - x[i-r+7];  /* n = 7 */
  sum_m += prod_n;

  /* m = 1 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  prod_n *= xi - x[i-r+4];  /* n = 4 */
  prod_n *= xi - x[i-r+5];  /* n = 5 */
  prod_n *= xi - x[i-r+6];  /* n = 6 */
  prod_n *= xi - x[i-r+7];  /* n = 7 */
  sum_m += prod_n;

  /* m = 2 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  prod_n *= xi - x[i-r+4];  /* n = 4 */
  prod_n *= xi - x[i-r+5];  /* n = 5 */
  prod_n *= xi - x[i-r+6];  /* n = 6 */
  prod_n *= xi - x[i-r+7];  /* n = 7 */
  sum_m += prod_n;

  /* m = 3 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+4];  /* n = 4 */
  prod_n *= xi - x[i-r+5];  /* n = 5 */
  prod_n *= xi - x[i-r+6];  /* n = 6 */
  prod_n *= xi - x[i-r+7];  /* n = 7 */
  sum_m += prod_n;

  /* m = 4 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  prod_n *= xi - x[i-r+5];  /* n = 5 */
  prod_n *= xi - x[i-r+6];  /* n = 6 */
  prod_n *= xi - x[i-r+7];  /* n = 7 */
  sum_m += prod_n;

  /* m = 5 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  prod_n *= xi - x[i-r+4];  /* n = 4 */
  prod_n *= xi - x[i-r+6];  /* n = 6 */
  prod_n *= xi - x[i-r+7];  /* n = 7 */
  sum_m += prod_n;

  /* m = 6 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  prod_n *= xi - x[i-r+4];  /* n = 4 */
  prod_n *= xi - x[i-r+5];  /* n = 5 */
  prod_n *= xi - x[i-r+7];  /* n = 7 */
  sum_m += prod_n;

  /* m = 7 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  prod_n *= xi - x[i-r+4];  /* n = 4 */
  prod_n *= xi - x[i-r+5];  /* n = 5 */
  prod_n *= xi - x[i-r+6];  /* n = 6 */
  sum_m += prod_n;

  prod_m = 1.0;
  prod_m *= x[i-r+8] - x[i-r+0];
  prod_m *= x[i-r+8] - x[i-r+1];
  prod_m *= x[i-r+8] - x[i-r+2];
  prod_m *= x[i-r+8] - x[i-r+3];
  prod_m *= x[i-r+8] - x[i-r+4];
  prod_m *= x[i-r+8] - x[i-r+5];
  prod_m *= x[i-r+8] - x[i-r+6];
  prod_m *= x[i-r+8] - x[i-r+7];

  sum_l += sum_m / prod_m * (x[i-r+5+1] - x[i-r+5]);

  c[5] = sum_l;

  /* j = 6 */
  sum_l = 0.0;

  /* l = 7 */
  sum_m = 0.0;

  /* m = 0 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  prod_n *= xi - x[i-r+4];  /* n = 4 */
  prod_n *= xi - x[i-r+5];  /* n = 5 */
  prod_n *= xi - x[i-r+6];  /* n = 6 */
  prod_n *= xi - x[i-r+8];  /* n = 8 */
  sum_m += prod_n;

  /* m = 1 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  prod_n *= xi - x[i-r+4];  /* n = 4 */
  prod_n *= xi - x[i-r+5];  /* n = 5 */
  prod_n *= xi - x[i-r+6];  /* n = 6 */
  prod_n *= xi - x[i-r+8];  /* n = 8 */
  sum_m += prod_n;

  /* m = 2 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  prod_n *= xi - x[i-r+4];  /* n = 4 */
  prod_n *= xi - x[i-r+5];  /* n = 5 */
  prod_n *= xi - x[i-r+6];  /* n = 6 */
  prod_n *= xi - x[i-r+8];  /* n = 8 */
  sum_m += prod_n;

  /* m = 3 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+4];  /* n = 4 */
  prod_n *= xi - x[i-r+5];  /* n = 5 */
  prod_n *= xi - x[i-r+6];  /* n = 6 */
  prod_n *= xi - x[i-r+8];  /* n = 8 */
  sum_m += prod_n;

  /* m = 4 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  prod_n *= xi - x[i-r+5];  /* n = 5 */
  prod_n *= xi - x[i-r+6];  /* n = 6 */
  prod_n *= xi - x[i-r+8];  /* n = 8 */
  sum_m += prod_n;

  /* m = 5 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  prod_n *= xi - x[i-r+4];  /* n = 4 */
  prod_n *= xi - x[i-r+6];  /* n = 6 */
  prod_n *= xi - x[i-r+8];  /* n = 8 */
  sum_m += prod_n;

  /* m = 6 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  prod_n *= xi - x[i-r+4];  /* n = 4 */
  prod_n *= xi - x[i-r+5];  /* n = 5 */
  prod_n *= xi - x[i-r+8];  /* n = 8 */
  sum_m += prod_n;

  /* m = 8 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  prod_n *= xi - x[i-r+4];  /* n = 4 */
  prod_n *= xi - x[i-r+5];  /* n = 5 */
  prod_n *= xi - x[i-r+6];  /* n = 6 */
  sum_m += prod_n;

  prod_m = 1.0;
  prod_m *= x[i-r+7] - x[i-r+0];
  prod_m *= x[i-r+7] - x[i-r+1];
  prod_m *= x[i-r+7] - x[i-r+2];
  prod_m *= x[i-r+7] - x[i-r+3];
  prod_m *= x[i-r+7] - x[i-r+4];
  prod_m *= x[i-r+7] - x[i-r+5];
  prod_m *= x[i-r+7] - x[i-r+6];
  prod_m *= x[i-r+7] - x[i-r+8];

  sum_l += sum_m / prod_m * (x[i-r+6+1] - x[i-r+6]);

  /* l = 8 */
  sum_m = 0.0;

  /* m = 0 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  prod_n *= xi - x[i-r+4];  /* n = 4 */
  prod_n *= xi - x[i-r+5];  /* n = 5 */
  prod_n *= xi - x[i-r+6];  /* n = 6 */
  prod_n *= xi - x[i-r+7];  /* n = 7 */
  sum_m += prod_n;

  /* m = 1 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  prod_n *= xi - x[i-r+4];  /* n = 4 */
  prod_n *= xi - x[i-r+5];  /* n = 5 */
  prod_n *= xi - x[i-r+6];  /* n = 6 */
  prod_n *= xi - x[i-r+7];  /* n = 7 */
  sum_m += prod_n;

  /* m = 2 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  prod_n *= xi - x[i-r+4];  /* n = 4 */
  prod_n *= xi - x[i-r+5];  /* n = 5 */
  prod_n *= xi - x[i-r+6];  /* n = 6 */
  prod_n *= xi - x[i-r+7];  /* n = 7 */
  sum_m += prod_n;

  /* m = 3 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+4];  /* n = 4 */
  prod_n *= xi - x[i-r+5];  /* n = 5 */
  prod_n *= xi - x[i-r+6];  /* n = 6 */
  prod_n *= xi - x[i-r+7];  /* n = 7 */
  sum_m += prod_n;

  /* m = 4 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  prod_n *= xi - x[i-r+5];  /* n = 5 */
  prod_n *= xi - x[i-r+6];  /* n = 6 */
  prod_n *= xi - x[i-r+7];  /* n = 7 */
  sum_m += prod_n;

  /* m = 5 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  prod_n *= xi - x[i-r+4];  /* n = 4 */
  prod_n *= xi - x[i-r+6];  /* n = 6 */
  prod_n *= xi - x[i-r+7];  /* n = 7 */
  sum_m += prod_n;

  /* m = 6 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  prod_n *= xi - x[i-r+4];  /* n = 4 */
  prod_n *= xi - x[i-r+5];  /* n = 5 */
  prod_n *= xi - x[i-r+7];  /* n = 7 */
  sum_m += prod_n;

  /* m = 7 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  prod_n *= xi - x[i-r+4];  /* n = 4 */
  prod_n *= xi - x[i-r+5];  /* n = 5 */
  prod_n *= xi - x[i-r+6];  /* n = 6 */
  sum_m += prod_n;

  prod_m = 1.0;
  prod_m *= x[i-r+8] - x[i-r+0];
  prod_m *= x[i-r+8] - x[i-r+1];
  prod_m *= x[i-r+8] - x[i-r+2];
  prod_m *= x[i-r+8] - x[i-r+3];
  prod_m *= x[i-r+8] - x[i-r+4];
  prod_m *= x[i-r+8] - x[i-r+5];
  prod_m *= x[i-r+8] - x[i-r+6];
  prod_m *= x[i-r+8] - x[i-r+7];

  sum_l += sum_m / prod_m * (x[i-r+6+1] - x[i-r+6]);

  c[6] = sum_l;

  /* j = 7 */
  sum_l = 0.0;

  /* l = 8 */
  sum_m = 0.0;

  /* m = 0 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  prod_n *= xi - x[i-r+4];  /* n = 4 */
  prod_n *= xi - x[i-r+5];  /* n = 5 */
  prod_n *= xi - x[i-r+6];  /* n = 6 */
  prod_n *= xi - x[i-r+7];  /* n = 7 */
  sum_m += prod_n;

  /* m = 1 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  prod_n *= xi - x[i-r+4];  /* n = 4 */
  prod_n *= xi - x[i-r+5];  /* n = 5 */
  prod_n *= xi - x[i-r+6];  /* n = 6 */
  prod_n *= xi - x[i-r+7];  /* n = 7 */
  sum_m += prod_n;

  /* m = 2 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  prod_n *= xi - x[i-r+4];  /* n = 4 */
  prod_n *= xi - x[i-r+5];  /* n = 5 */
  prod_n *= xi - x[i-r+6];  /* n = 6 */
  prod_n *= xi - x[i-r+7];  /* n = 7 */
  sum_m += prod_n;

  /* m = 3 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+4];  /* n = 4 */
  prod_n *= xi - x[i-r+5];  /* n = 5 */
  prod_n *= xi - x[i-r+6];  /* n = 6 */
  prod_n *= xi - x[i-r+7];  /* n = 7 */
  sum_m += prod_n;

  /* m = 4 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  prod_n *= xi - x[i-r+5];  /* n = 5 */
  prod_n *= xi - x[i-r+6];  /* n = 6 */
  prod_n *= xi - x[i-r+7];  /* n = 7 */
  sum_m += prod_n;

  /* m = 5 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  prod_n *= xi - x[i-r+4];  /* n = 4 */
  prod_n *= xi - x[i-r+6];  /* n = 6 */
  prod_n *= xi - x[i-r+7];  /* n = 7 */
  sum_m += prod_n;

  /* m = 6 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  prod_n *= xi - x[i-r+4];  /* n = 4 */
  prod_n *= xi - x[i-r+5];  /* n = 5 */
  prod_n *= xi - x[i-r+7];  /* n = 7 */
  sum_m += prod_n;

  /* m = 7 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  prod_n *= xi - x[i-r+4];  /* n = 4 */
  prod_n *= xi - x[i-r+5];  /* n = 5 */
  prod_n *= xi - x[i-r+6];  /* n = 6 */
  sum_m += prod_n;

  prod_m = 1.0;
  prod_m *= x[i-r+8] - x[i-r+0];
  prod_m *= x[i-r+8] - x[i-r+1];
  prod_m *= x[i-r+8] - x[i-r+2];
  prod_m *= x[i-r+8] - x[i-r+3];
  prod_m *= x[i-r+8] - x[i-r+4];
  prod_m *= x[i-r+8] - x[i-r+5];
  prod_m *= x[i-r+8] - x[i-r+6];
  prod_m *= x[i-r+8] - x[i-r+7];

  sum_l += sum_m / prod_m * (x[i-r+7+1] - x[i-r+7]);

  c[7] = sum_l;
}

PyObject *
reconstruction_coeffs_k8_d0_py(PyObject *self, PyObject *args)
{
  double *x, *c, xi;
  long int i;
  int r;

  PyObject *bndry, *coeffs;

  /*
   * parse options
   */

  if (! PyArg_ParseTuple(args, "dlidOO", &xi, &i, &r, &bndry, &coeffs))
    return NULL;

  if ((PyArray_FLAGS(bndry) & NPY_IN_ARRAY) != NPY_IN_ARRAY) {
    PyErr_SetString(PyExc_TypeError, "bndry is not contiguous and/or aligned");
    return NULL;
  }
  Py_INCREF(bndry);
  x = (double *) PyArray_DATA(bndry);

  if ((PyArray_FLAGS(coeffs) & NPY_IN_ARRAY) != NPY_IN_ARRAY) {
    PyErr_SetString(PyExc_TypeError, "coeffs is not contiguous and/or aligned");
    return NULL;
  }
  Py_INCREF(coeffs);
  c = (double *) PyArray_DATA(coeffs);

  /*
   * dispatch
   */

  reconstruction_coeffs_k8_d0(xi, i, r, x, c);

  /*
   * done
   */
  Py_INCREF(Py_None);
  return Py_None;
}

void
reconstruction_coeffs_k9_d0(double xi, long int i, int r, double *x, double *c)
{
  double sum_l, sum_m, prod_n, prod_m;

  /*
   * compute reconstruction coeffs of order 9
   */


  /* j = 0 */
  sum_l = 0.0;

  /* l = 1 */
  sum_m = 0.0;

  /* m = 0 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  prod_n *= xi - x[i-r+4];  /* n = 4 */
  prod_n *= xi - x[i-r+5];  /* n = 5 */
  prod_n *= xi - x[i-r+6];  /* n = 6 */
  prod_n *= xi - x[i-r+7];  /* n = 7 */
  prod_n *= xi - x[i-r+8];  /* n = 8 */
  prod_n *= xi - x[i-r+9];  /* n = 9 */
  sum_m += prod_n;

  /* m = 2 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  prod_n *= xi - x[i-r+4];  /* n = 4 */
  prod_n *= xi - x[i-r+5];  /* n = 5 */
  prod_n *= xi - x[i-r+6];  /* n = 6 */
  prod_n *= xi - x[i-r+7];  /* n = 7 */
  prod_n *= xi - x[i-r+8];  /* n = 8 */
  prod_n *= xi - x[i-r+9];  /* n = 9 */
  sum_m += prod_n;

  /* m = 3 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+4];  /* n = 4 */
  prod_n *= xi - x[i-r+5];  /* n = 5 */
  prod_n *= xi - x[i-r+6];  /* n = 6 */
  prod_n *= xi - x[i-r+7];  /* n = 7 */
  prod_n *= xi - x[i-r+8];  /* n = 8 */
  prod_n *= xi - x[i-r+9];  /* n = 9 */
  sum_m += prod_n;

  /* m = 4 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  prod_n *= xi - x[i-r+5];  /* n = 5 */
  prod_n *= xi - x[i-r+6];  /* n = 6 */
  prod_n *= xi - x[i-r+7];  /* n = 7 */
  prod_n *= xi - x[i-r+8];  /* n = 8 */
  prod_n *= xi - x[i-r+9];  /* n = 9 */
  sum_m += prod_n;

  /* m = 5 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  prod_n *= xi - x[i-r+4];  /* n = 4 */
  prod_n *= xi - x[i-r+6];  /* n = 6 */
  prod_n *= xi - x[i-r+7];  /* n = 7 */
  prod_n *= xi - x[i-r+8];  /* n = 8 */
  prod_n *= xi - x[i-r+9];  /* n = 9 */
  sum_m += prod_n;

  /* m = 6 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  prod_n *= xi - x[i-r+4];  /* n = 4 */
  prod_n *= xi - x[i-r+5];  /* n = 5 */
  prod_n *= xi - x[i-r+7];  /* n = 7 */
  prod_n *= xi - x[i-r+8];  /* n = 8 */
  prod_n *= xi - x[i-r+9];  /* n = 9 */
  sum_m += prod_n;

  /* m = 7 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  prod_n *= xi - x[i-r+4];  /* n = 4 */
  prod_n *= xi - x[i-r+5];  /* n = 5 */
  prod_n *= xi - x[i-r+6];  /* n = 6 */
  prod_n *= xi - x[i-r+8];  /* n = 8 */
  prod_n *= xi - x[i-r+9];  /* n = 9 */
  sum_m += prod_n;

  /* m = 8 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  prod_n *= xi - x[i-r+4];  /* n = 4 */
  prod_n *= xi - x[i-r+5];  /* n = 5 */
  prod_n *= xi - x[i-r+6];  /* n = 6 */
  prod_n *= xi - x[i-r+7];  /* n = 7 */
  prod_n *= xi - x[i-r+9];  /* n = 9 */
  sum_m += prod_n;

  /* m = 9 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  prod_n *= xi - x[i-r+4];  /* n = 4 */
  prod_n *= xi - x[i-r+5];  /* n = 5 */
  prod_n *= xi - x[i-r+6];  /* n = 6 */
  prod_n *= xi - x[i-r+7];  /* n = 7 */
  prod_n *= xi - x[i-r+8];  /* n = 8 */
  sum_m += prod_n;

  prod_m = 1.0;
  prod_m *= x[i-r+1] - x[i-r+0];
  prod_m *= x[i-r+1] - x[i-r+2];
  prod_m *= x[i-r+1] - x[i-r+3];
  prod_m *= x[i-r+1] - x[i-r+4];
  prod_m *= x[i-r+1] - x[i-r+5];
  prod_m *= x[i-r+1] - x[i-r+6];
  prod_m *= x[i-r+1] - x[i-r+7];
  prod_m *= x[i-r+1] - x[i-r+8];
  prod_m *= x[i-r+1] - x[i-r+9];

  sum_l += sum_m / prod_m * (x[i-r+0+1] - x[i-r+0]);

  /* l = 2 */
  sum_m = 0.0;

  /* m = 0 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  prod_n *= xi - x[i-r+4];  /* n = 4 */
  prod_n *= xi - x[i-r+5];  /* n = 5 */
  prod_n *= xi - x[i-r+6];  /* n = 6 */
  prod_n *= xi - x[i-r+7];  /* n = 7 */
  prod_n *= xi - x[i-r+8];  /* n = 8 */
  prod_n *= xi - x[i-r+9];  /* n = 9 */
  sum_m += prod_n;

  /* m = 1 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  prod_n *= xi - x[i-r+4];  /* n = 4 */
  prod_n *= xi - x[i-r+5];  /* n = 5 */
  prod_n *= xi - x[i-r+6];  /* n = 6 */
  prod_n *= xi - x[i-r+7];  /* n = 7 */
  prod_n *= xi - x[i-r+8];  /* n = 8 */
  prod_n *= xi - x[i-r+9];  /* n = 9 */
  sum_m += prod_n;

  /* m = 3 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+4];  /* n = 4 */
  prod_n *= xi - x[i-r+5];  /* n = 5 */
  prod_n *= xi - x[i-r+6];  /* n = 6 */
  prod_n *= xi - x[i-r+7];  /* n = 7 */
  prod_n *= xi - x[i-r+8];  /* n = 8 */
  prod_n *= xi - x[i-r+9];  /* n = 9 */
  sum_m += prod_n;

  /* m = 4 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  prod_n *= xi - x[i-r+5];  /* n = 5 */
  prod_n *= xi - x[i-r+6];  /* n = 6 */
  prod_n *= xi - x[i-r+7];  /* n = 7 */
  prod_n *= xi - x[i-r+8];  /* n = 8 */
  prod_n *= xi - x[i-r+9];  /* n = 9 */
  sum_m += prod_n;

  /* m = 5 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  prod_n *= xi - x[i-r+4];  /* n = 4 */
  prod_n *= xi - x[i-r+6];  /* n = 6 */
  prod_n *= xi - x[i-r+7];  /* n = 7 */
  prod_n *= xi - x[i-r+8];  /* n = 8 */
  prod_n *= xi - x[i-r+9];  /* n = 9 */
  sum_m += prod_n;

  /* m = 6 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  prod_n *= xi - x[i-r+4];  /* n = 4 */
  prod_n *= xi - x[i-r+5];  /* n = 5 */
  prod_n *= xi - x[i-r+7];  /* n = 7 */
  prod_n *= xi - x[i-r+8];  /* n = 8 */
  prod_n *= xi - x[i-r+9];  /* n = 9 */
  sum_m += prod_n;

  /* m = 7 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  prod_n *= xi - x[i-r+4];  /* n = 4 */
  prod_n *= xi - x[i-r+5];  /* n = 5 */
  prod_n *= xi - x[i-r+6];  /* n = 6 */
  prod_n *= xi - x[i-r+8];  /* n = 8 */
  prod_n *= xi - x[i-r+9];  /* n = 9 */
  sum_m += prod_n;

  /* m = 8 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  prod_n *= xi - x[i-r+4];  /* n = 4 */
  prod_n *= xi - x[i-r+5];  /* n = 5 */
  prod_n *= xi - x[i-r+6];  /* n = 6 */
  prod_n *= xi - x[i-r+7];  /* n = 7 */
  prod_n *= xi - x[i-r+9];  /* n = 9 */
  sum_m += prod_n;

  /* m = 9 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  prod_n *= xi - x[i-r+4];  /* n = 4 */
  prod_n *= xi - x[i-r+5];  /* n = 5 */
  prod_n *= xi - x[i-r+6];  /* n = 6 */
  prod_n *= xi - x[i-r+7];  /* n = 7 */
  prod_n *= xi - x[i-r+8];  /* n = 8 */
  sum_m += prod_n;

  prod_m = 1.0;
  prod_m *= x[i-r+2] - x[i-r+0];
  prod_m *= x[i-r+2] - x[i-r+1];
  prod_m *= x[i-r+2] - x[i-r+3];
  prod_m *= x[i-r+2] - x[i-r+4];
  prod_m *= x[i-r+2] - x[i-r+5];
  prod_m *= x[i-r+2] - x[i-r+6];
  prod_m *= x[i-r+2] - x[i-r+7];
  prod_m *= x[i-r+2] - x[i-r+8];
  prod_m *= x[i-r+2] - x[i-r+9];

  sum_l += sum_m / prod_m * (x[i-r+0+1] - x[i-r+0]);

  /* l = 3 */
  sum_m = 0.0;

  /* m = 0 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+4];  /* n = 4 */
  prod_n *= xi - x[i-r+5];  /* n = 5 */
  prod_n *= xi - x[i-r+6];  /* n = 6 */
  prod_n *= xi - x[i-r+7];  /* n = 7 */
  prod_n *= xi - x[i-r+8];  /* n = 8 */
  prod_n *= xi - x[i-r+9];  /* n = 9 */
  sum_m += prod_n;

  /* m = 1 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+4];  /* n = 4 */
  prod_n *= xi - x[i-r+5];  /* n = 5 */
  prod_n *= xi - x[i-r+6];  /* n = 6 */
  prod_n *= xi - x[i-r+7];  /* n = 7 */
  prod_n *= xi - x[i-r+8];  /* n = 8 */
  prod_n *= xi - x[i-r+9];  /* n = 9 */
  sum_m += prod_n;

  /* m = 2 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+4];  /* n = 4 */
  prod_n *= xi - x[i-r+5];  /* n = 5 */
  prod_n *= xi - x[i-r+6];  /* n = 6 */
  prod_n *= xi - x[i-r+7];  /* n = 7 */
  prod_n *= xi - x[i-r+8];  /* n = 8 */
  prod_n *= xi - x[i-r+9];  /* n = 9 */
  sum_m += prod_n;

  /* m = 4 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+5];  /* n = 5 */
  prod_n *= xi - x[i-r+6];  /* n = 6 */
  prod_n *= xi - x[i-r+7];  /* n = 7 */
  prod_n *= xi - x[i-r+8];  /* n = 8 */
  prod_n *= xi - x[i-r+9];  /* n = 9 */
  sum_m += prod_n;

  /* m = 5 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+4];  /* n = 4 */
  prod_n *= xi - x[i-r+6];  /* n = 6 */
  prod_n *= xi - x[i-r+7];  /* n = 7 */
  prod_n *= xi - x[i-r+8];  /* n = 8 */
  prod_n *= xi - x[i-r+9];  /* n = 9 */
  sum_m += prod_n;

  /* m = 6 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+4];  /* n = 4 */
  prod_n *= xi - x[i-r+5];  /* n = 5 */
  prod_n *= xi - x[i-r+7];  /* n = 7 */
  prod_n *= xi - x[i-r+8];  /* n = 8 */
  prod_n *= xi - x[i-r+9];  /* n = 9 */
  sum_m += prod_n;

  /* m = 7 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+4];  /* n = 4 */
  prod_n *= xi - x[i-r+5];  /* n = 5 */
  prod_n *= xi - x[i-r+6];  /* n = 6 */
  prod_n *= xi - x[i-r+8];  /* n = 8 */
  prod_n *= xi - x[i-r+9];  /* n = 9 */
  sum_m += prod_n;

  /* m = 8 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+4];  /* n = 4 */
  prod_n *= xi - x[i-r+5];  /* n = 5 */
  prod_n *= xi - x[i-r+6];  /* n = 6 */
  prod_n *= xi - x[i-r+7];  /* n = 7 */
  prod_n *= xi - x[i-r+9];  /* n = 9 */
  sum_m += prod_n;

  /* m = 9 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+4];  /* n = 4 */
  prod_n *= xi - x[i-r+5];  /* n = 5 */
  prod_n *= xi - x[i-r+6];  /* n = 6 */
  prod_n *= xi - x[i-r+7];  /* n = 7 */
  prod_n *= xi - x[i-r+8];  /* n = 8 */
  sum_m += prod_n;

  prod_m = 1.0;
  prod_m *= x[i-r+3] - x[i-r+0];
  prod_m *= x[i-r+3] - x[i-r+1];
  prod_m *= x[i-r+3] - x[i-r+2];
  prod_m *= x[i-r+3] - x[i-r+4];
  prod_m *= x[i-r+3] - x[i-r+5];
  prod_m *= x[i-r+3] - x[i-r+6];
  prod_m *= x[i-r+3] - x[i-r+7];
  prod_m *= x[i-r+3] - x[i-r+8];
  prod_m *= x[i-r+3] - x[i-r+9];

  sum_l += sum_m / prod_m * (x[i-r+0+1] - x[i-r+0]);

  /* l = 4 */
  sum_m = 0.0;

  /* m = 0 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  prod_n *= xi - x[i-r+5];  /* n = 5 */
  prod_n *= xi - x[i-r+6];  /* n = 6 */
  prod_n *= xi - x[i-r+7];  /* n = 7 */
  prod_n *= xi - x[i-r+8];  /* n = 8 */
  prod_n *= xi - x[i-r+9];  /* n = 9 */
  sum_m += prod_n;

  /* m = 1 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  prod_n *= xi - x[i-r+5];  /* n = 5 */
  prod_n *= xi - x[i-r+6];  /* n = 6 */
  prod_n *= xi - x[i-r+7];  /* n = 7 */
  prod_n *= xi - x[i-r+8];  /* n = 8 */
  prod_n *= xi - x[i-r+9];  /* n = 9 */
  sum_m += prod_n;

  /* m = 2 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  prod_n *= xi - x[i-r+5];  /* n = 5 */
  prod_n *= xi - x[i-r+6];  /* n = 6 */
  prod_n *= xi - x[i-r+7];  /* n = 7 */
  prod_n *= xi - x[i-r+8];  /* n = 8 */
  prod_n *= xi - x[i-r+9];  /* n = 9 */
  sum_m += prod_n;

  /* m = 3 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+5];  /* n = 5 */
  prod_n *= xi - x[i-r+6];  /* n = 6 */
  prod_n *= xi - x[i-r+7];  /* n = 7 */
  prod_n *= xi - x[i-r+8];  /* n = 8 */
  prod_n *= xi - x[i-r+9];  /* n = 9 */
  sum_m += prod_n;

  /* m = 5 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  prod_n *= xi - x[i-r+6];  /* n = 6 */
  prod_n *= xi - x[i-r+7];  /* n = 7 */
  prod_n *= xi - x[i-r+8];  /* n = 8 */
  prod_n *= xi - x[i-r+9];  /* n = 9 */
  sum_m += prod_n;

  /* m = 6 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  prod_n *= xi - x[i-r+5];  /* n = 5 */
  prod_n *= xi - x[i-r+7];  /* n = 7 */
  prod_n *= xi - x[i-r+8];  /* n = 8 */
  prod_n *= xi - x[i-r+9];  /* n = 9 */
  sum_m += prod_n;

  /* m = 7 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  prod_n *= xi - x[i-r+5];  /* n = 5 */
  prod_n *= xi - x[i-r+6];  /* n = 6 */
  prod_n *= xi - x[i-r+8];  /* n = 8 */
  prod_n *= xi - x[i-r+9];  /* n = 9 */
  sum_m += prod_n;

  /* m = 8 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  prod_n *= xi - x[i-r+5];  /* n = 5 */
  prod_n *= xi - x[i-r+6];  /* n = 6 */
  prod_n *= xi - x[i-r+7];  /* n = 7 */
  prod_n *= xi - x[i-r+9];  /* n = 9 */
  sum_m += prod_n;

  /* m = 9 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  prod_n *= xi - x[i-r+5];  /* n = 5 */
  prod_n *= xi - x[i-r+6];  /* n = 6 */
  prod_n *= xi - x[i-r+7];  /* n = 7 */
  prod_n *= xi - x[i-r+8];  /* n = 8 */
  sum_m += prod_n;

  prod_m = 1.0;
  prod_m *= x[i-r+4] - x[i-r+0];
  prod_m *= x[i-r+4] - x[i-r+1];
  prod_m *= x[i-r+4] - x[i-r+2];
  prod_m *= x[i-r+4] - x[i-r+3];
  prod_m *= x[i-r+4] - x[i-r+5];
  prod_m *= x[i-r+4] - x[i-r+6];
  prod_m *= x[i-r+4] - x[i-r+7];
  prod_m *= x[i-r+4] - x[i-r+8];
  prod_m *= x[i-r+4] - x[i-r+9];

  sum_l += sum_m / prod_m * (x[i-r+0+1] - x[i-r+0]);

  /* l = 5 */
  sum_m = 0.0;

  /* m = 0 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  prod_n *= xi - x[i-r+4];  /* n = 4 */
  prod_n *= xi - x[i-r+6];  /* n = 6 */
  prod_n *= xi - x[i-r+7];  /* n = 7 */
  prod_n *= xi - x[i-r+8];  /* n = 8 */
  prod_n *= xi - x[i-r+9];  /* n = 9 */
  sum_m += prod_n;

  /* m = 1 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  prod_n *= xi - x[i-r+4];  /* n = 4 */
  prod_n *= xi - x[i-r+6];  /* n = 6 */
  prod_n *= xi - x[i-r+7];  /* n = 7 */
  prod_n *= xi - x[i-r+8];  /* n = 8 */
  prod_n *= xi - x[i-r+9];  /* n = 9 */
  sum_m += prod_n;

  /* m = 2 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  prod_n *= xi - x[i-r+4];  /* n = 4 */
  prod_n *= xi - x[i-r+6];  /* n = 6 */
  prod_n *= xi - x[i-r+7];  /* n = 7 */
  prod_n *= xi - x[i-r+8];  /* n = 8 */
  prod_n *= xi - x[i-r+9];  /* n = 9 */
  sum_m += prod_n;

  /* m = 3 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+4];  /* n = 4 */
  prod_n *= xi - x[i-r+6];  /* n = 6 */
  prod_n *= xi - x[i-r+7];  /* n = 7 */
  prod_n *= xi - x[i-r+8];  /* n = 8 */
  prod_n *= xi - x[i-r+9];  /* n = 9 */
  sum_m += prod_n;

  /* m = 4 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  prod_n *= xi - x[i-r+6];  /* n = 6 */
  prod_n *= xi - x[i-r+7];  /* n = 7 */
  prod_n *= xi - x[i-r+8];  /* n = 8 */
  prod_n *= xi - x[i-r+9];  /* n = 9 */
  sum_m += prod_n;

  /* m = 6 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  prod_n *= xi - x[i-r+4];  /* n = 4 */
  prod_n *= xi - x[i-r+7];  /* n = 7 */
  prod_n *= xi - x[i-r+8];  /* n = 8 */
  prod_n *= xi - x[i-r+9];  /* n = 9 */
  sum_m += prod_n;

  /* m = 7 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  prod_n *= xi - x[i-r+4];  /* n = 4 */
  prod_n *= xi - x[i-r+6];  /* n = 6 */
  prod_n *= xi - x[i-r+8];  /* n = 8 */
  prod_n *= xi - x[i-r+9];  /* n = 9 */
  sum_m += prod_n;

  /* m = 8 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  prod_n *= xi - x[i-r+4];  /* n = 4 */
  prod_n *= xi - x[i-r+6];  /* n = 6 */
  prod_n *= xi - x[i-r+7];  /* n = 7 */
  prod_n *= xi - x[i-r+9];  /* n = 9 */
  sum_m += prod_n;

  /* m = 9 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  prod_n *= xi - x[i-r+4];  /* n = 4 */
  prod_n *= xi - x[i-r+6];  /* n = 6 */
  prod_n *= xi - x[i-r+7];  /* n = 7 */
  prod_n *= xi - x[i-r+8];  /* n = 8 */
  sum_m += prod_n;

  prod_m = 1.0;
  prod_m *= x[i-r+5] - x[i-r+0];
  prod_m *= x[i-r+5] - x[i-r+1];
  prod_m *= x[i-r+5] - x[i-r+2];
  prod_m *= x[i-r+5] - x[i-r+3];
  prod_m *= x[i-r+5] - x[i-r+4];
  prod_m *= x[i-r+5] - x[i-r+6];
  prod_m *= x[i-r+5] - x[i-r+7];
  prod_m *= x[i-r+5] - x[i-r+8];
  prod_m *= x[i-r+5] - x[i-r+9];

  sum_l += sum_m / prod_m * (x[i-r+0+1] - x[i-r+0]);

  /* l = 6 */
  sum_m = 0.0;

  /* m = 0 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  prod_n *= xi - x[i-r+4];  /* n = 4 */
  prod_n *= xi - x[i-r+5];  /* n = 5 */
  prod_n *= xi - x[i-r+7];  /* n = 7 */
  prod_n *= xi - x[i-r+8];  /* n = 8 */
  prod_n *= xi - x[i-r+9];  /* n = 9 */
  sum_m += prod_n;

  /* m = 1 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  prod_n *= xi - x[i-r+4];  /* n = 4 */
  prod_n *= xi - x[i-r+5];  /* n = 5 */
  prod_n *= xi - x[i-r+7];  /* n = 7 */
  prod_n *= xi - x[i-r+8];  /* n = 8 */
  prod_n *= xi - x[i-r+9];  /* n = 9 */
  sum_m += prod_n;

  /* m = 2 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  prod_n *= xi - x[i-r+4];  /* n = 4 */
  prod_n *= xi - x[i-r+5];  /* n = 5 */
  prod_n *= xi - x[i-r+7];  /* n = 7 */
  prod_n *= xi - x[i-r+8];  /* n = 8 */
  prod_n *= xi - x[i-r+9];  /* n = 9 */
  sum_m += prod_n;

  /* m = 3 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+4];  /* n = 4 */
  prod_n *= xi - x[i-r+5];  /* n = 5 */
  prod_n *= xi - x[i-r+7];  /* n = 7 */
  prod_n *= xi - x[i-r+8];  /* n = 8 */
  prod_n *= xi - x[i-r+9];  /* n = 9 */
  sum_m += prod_n;

  /* m = 4 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  prod_n *= xi - x[i-r+5];  /* n = 5 */
  prod_n *= xi - x[i-r+7];  /* n = 7 */
  prod_n *= xi - x[i-r+8];  /* n = 8 */
  prod_n *= xi - x[i-r+9];  /* n = 9 */
  sum_m += prod_n;

  /* m = 5 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  prod_n *= xi - x[i-r+4];  /* n = 4 */
  prod_n *= xi - x[i-r+7];  /* n = 7 */
  prod_n *= xi - x[i-r+8];  /* n = 8 */
  prod_n *= xi - x[i-r+9];  /* n = 9 */
  sum_m += prod_n;

  /* m = 7 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  prod_n *= xi - x[i-r+4];  /* n = 4 */
  prod_n *= xi - x[i-r+5];  /* n = 5 */
  prod_n *= xi - x[i-r+8];  /* n = 8 */
  prod_n *= xi - x[i-r+9];  /* n = 9 */
  sum_m += prod_n;

  /* m = 8 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  prod_n *= xi - x[i-r+4];  /* n = 4 */
  prod_n *= xi - x[i-r+5];  /* n = 5 */
  prod_n *= xi - x[i-r+7];  /* n = 7 */
  prod_n *= xi - x[i-r+9];  /* n = 9 */
  sum_m += prod_n;

  /* m = 9 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  prod_n *= xi - x[i-r+4];  /* n = 4 */
  prod_n *= xi - x[i-r+5];  /* n = 5 */
  prod_n *= xi - x[i-r+7];  /* n = 7 */
  prod_n *= xi - x[i-r+8];  /* n = 8 */
  sum_m += prod_n;

  prod_m = 1.0;
  prod_m *= x[i-r+6] - x[i-r+0];
  prod_m *= x[i-r+6] - x[i-r+1];
  prod_m *= x[i-r+6] - x[i-r+2];
  prod_m *= x[i-r+6] - x[i-r+3];
  prod_m *= x[i-r+6] - x[i-r+4];
  prod_m *= x[i-r+6] - x[i-r+5];
  prod_m *= x[i-r+6] - x[i-r+7];
  prod_m *= x[i-r+6] - x[i-r+8];
  prod_m *= x[i-r+6] - x[i-r+9];

  sum_l += sum_m / prod_m * (x[i-r+0+1] - x[i-r+0]);

  /* l = 7 */
  sum_m = 0.0;

  /* m = 0 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  prod_n *= xi - x[i-r+4];  /* n = 4 */
  prod_n *= xi - x[i-r+5];  /* n = 5 */
  prod_n *= xi - x[i-r+6];  /* n = 6 */
  prod_n *= xi - x[i-r+8];  /* n = 8 */
  prod_n *= xi - x[i-r+9];  /* n = 9 */
  sum_m += prod_n;

  /* m = 1 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  prod_n *= xi - x[i-r+4];  /* n = 4 */
  prod_n *= xi - x[i-r+5];  /* n = 5 */
  prod_n *= xi - x[i-r+6];  /* n = 6 */
  prod_n *= xi - x[i-r+8];  /* n = 8 */
  prod_n *= xi - x[i-r+9];  /* n = 9 */
  sum_m += prod_n;

  /* m = 2 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  prod_n *= xi - x[i-r+4];  /* n = 4 */
  prod_n *= xi - x[i-r+5];  /* n = 5 */
  prod_n *= xi - x[i-r+6];  /* n = 6 */
  prod_n *= xi - x[i-r+8];  /* n = 8 */
  prod_n *= xi - x[i-r+9];  /* n = 9 */
  sum_m += prod_n;

  /* m = 3 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+4];  /* n = 4 */
  prod_n *= xi - x[i-r+5];  /* n = 5 */
  prod_n *= xi - x[i-r+6];  /* n = 6 */
  prod_n *= xi - x[i-r+8];  /* n = 8 */
  prod_n *= xi - x[i-r+9];  /* n = 9 */
  sum_m += prod_n;

  /* m = 4 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  prod_n *= xi - x[i-r+5];  /* n = 5 */
  prod_n *= xi - x[i-r+6];  /* n = 6 */
  prod_n *= xi - x[i-r+8];  /* n = 8 */
  prod_n *= xi - x[i-r+9];  /* n = 9 */
  sum_m += prod_n;

  /* m = 5 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  prod_n *= xi - x[i-r+4];  /* n = 4 */
  prod_n *= xi - x[i-r+6];  /* n = 6 */
  prod_n *= xi - x[i-r+8];  /* n = 8 */
  prod_n *= xi - x[i-r+9];  /* n = 9 */
  sum_m += prod_n;

  /* m = 6 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  prod_n *= xi - x[i-r+4];  /* n = 4 */
  prod_n *= xi - x[i-r+5];  /* n = 5 */
  prod_n *= xi - x[i-r+8];  /* n = 8 */
  prod_n *= xi - x[i-r+9];  /* n = 9 */
  sum_m += prod_n;

  /* m = 8 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  prod_n *= xi - x[i-r+4];  /* n = 4 */
  prod_n *= xi - x[i-r+5];  /* n = 5 */
  prod_n *= xi - x[i-r+6];  /* n = 6 */
  prod_n *= xi - x[i-r+9];  /* n = 9 */
  sum_m += prod_n;

  /* m = 9 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  prod_n *= xi - x[i-r+4];  /* n = 4 */
  prod_n *= xi - x[i-r+5];  /* n = 5 */
  prod_n *= xi - x[i-r+6];  /* n = 6 */
  prod_n *= xi - x[i-r+8];  /* n = 8 */
  sum_m += prod_n;

  prod_m = 1.0;
  prod_m *= x[i-r+7] - x[i-r+0];
  prod_m *= x[i-r+7] - x[i-r+1];
  prod_m *= x[i-r+7] - x[i-r+2];
  prod_m *= x[i-r+7] - x[i-r+3];
  prod_m *= x[i-r+7] - x[i-r+4];
  prod_m *= x[i-r+7] - x[i-r+5];
  prod_m *= x[i-r+7] - x[i-r+6];
  prod_m *= x[i-r+7] - x[i-r+8];
  prod_m *= x[i-r+7] - x[i-r+9];

  sum_l += sum_m / prod_m * (x[i-r+0+1] - x[i-r+0]);

  /* l = 8 */
  sum_m = 0.0;

  /* m = 0 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  prod_n *= xi - x[i-r+4];  /* n = 4 */
  prod_n *= xi - x[i-r+5];  /* n = 5 */
  prod_n *= xi - x[i-r+6];  /* n = 6 */
  prod_n *= xi - x[i-r+7];  /* n = 7 */
  prod_n *= xi - x[i-r+9];  /* n = 9 */
  sum_m += prod_n;

  /* m = 1 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  prod_n *= xi - x[i-r+4];  /* n = 4 */
  prod_n *= xi - x[i-r+5];  /* n = 5 */
  prod_n *= xi - x[i-r+6];  /* n = 6 */
  prod_n *= xi - x[i-r+7];  /* n = 7 */
  prod_n *= xi - x[i-r+9];  /* n = 9 */
  sum_m += prod_n;

  /* m = 2 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  prod_n *= xi - x[i-r+4];  /* n = 4 */
  prod_n *= xi - x[i-r+5];  /* n = 5 */
  prod_n *= xi - x[i-r+6];  /* n = 6 */
  prod_n *= xi - x[i-r+7];  /* n = 7 */
  prod_n *= xi - x[i-r+9];  /* n = 9 */
  sum_m += prod_n;

  /* m = 3 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+4];  /* n = 4 */
  prod_n *= xi - x[i-r+5];  /* n = 5 */
  prod_n *= xi - x[i-r+6];  /* n = 6 */
  prod_n *= xi - x[i-r+7];  /* n = 7 */
  prod_n *= xi - x[i-r+9];  /* n = 9 */
  sum_m += prod_n;

  /* m = 4 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  prod_n *= xi - x[i-r+5];  /* n = 5 */
  prod_n *= xi - x[i-r+6];  /* n = 6 */
  prod_n *= xi - x[i-r+7];  /* n = 7 */
  prod_n *= xi - x[i-r+9];  /* n = 9 */
  sum_m += prod_n;

  /* m = 5 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  prod_n *= xi - x[i-r+4];  /* n = 4 */
  prod_n *= xi - x[i-r+6];  /* n = 6 */
  prod_n *= xi - x[i-r+7];  /* n = 7 */
  prod_n *= xi - x[i-r+9];  /* n = 9 */
  sum_m += prod_n;

  /* m = 6 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  prod_n *= xi - x[i-r+4];  /* n = 4 */
  prod_n *= xi - x[i-r+5];  /* n = 5 */
  prod_n *= xi - x[i-r+7];  /* n = 7 */
  prod_n *= xi - x[i-r+9];  /* n = 9 */
  sum_m += prod_n;

  /* m = 7 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  prod_n *= xi - x[i-r+4];  /* n = 4 */
  prod_n *= xi - x[i-r+5];  /* n = 5 */
  prod_n *= xi - x[i-r+6];  /* n = 6 */
  prod_n *= xi - x[i-r+9];  /* n = 9 */
  sum_m += prod_n;

  /* m = 9 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  prod_n *= xi - x[i-r+4];  /* n = 4 */
  prod_n *= xi - x[i-r+5];  /* n = 5 */
  prod_n *= xi - x[i-r+6];  /* n = 6 */
  prod_n *= xi - x[i-r+7];  /* n = 7 */
  sum_m += prod_n;

  prod_m = 1.0;
  prod_m *= x[i-r+8] - x[i-r+0];
  prod_m *= x[i-r+8] - x[i-r+1];
  prod_m *= x[i-r+8] - x[i-r+2];
  prod_m *= x[i-r+8] - x[i-r+3];
  prod_m *= x[i-r+8] - x[i-r+4];
  prod_m *= x[i-r+8] - x[i-r+5];
  prod_m *= x[i-r+8] - x[i-r+6];
  prod_m *= x[i-r+8] - x[i-r+7];
  prod_m *= x[i-r+8] - x[i-r+9];

  sum_l += sum_m / prod_m * (x[i-r+0+1] - x[i-r+0]);

  /* l = 9 */
  sum_m = 0.0;

  /* m = 0 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  prod_n *= xi - x[i-r+4];  /* n = 4 */
  prod_n *= xi - x[i-r+5];  /* n = 5 */
  prod_n *= xi - x[i-r+6];  /* n = 6 */
  prod_n *= xi - x[i-r+7];  /* n = 7 */
  prod_n *= xi - x[i-r+8];  /* n = 8 */
  sum_m += prod_n;

  /* m = 1 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  prod_n *= xi - x[i-r+4];  /* n = 4 */
  prod_n *= xi - x[i-r+5];  /* n = 5 */
  prod_n *= xi - x[i-r+6];  /* n = 6 */
  prod_n *= xi - x[i-r+7];  /* n = 7 */
  prod_n *= xi - x[i-r+8];  /* n = 8 */
  sum_m += prod_n;

  /* m = 2 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  prod_n *= xi - x[i-r+4];  /* n = 4 */
  prod_n *= xi - x[i-r+5];  /* n = 5 */
  prod_n *= xi - x[i-r+6];  /* n = 6 */
  prod_n *= xi - x[i-r+7];  /* n = 7 */
  prod_n *= xi - x[i-r+8];  /* n = 8 */
  sum_m += prod_n;

  /* m = 3 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+4];  /* n = 4 */
  prod_n *= xi - x[i-r+5];  /* n = 5 */
  prod_n *= xi - x[i-r+6];  /* n = 6 */
  prod_n *= xi - x[i-r+7];  /* n = 7 */
  prod_n *= xi - x[i-r+8];  /* n = 8 */
  sum_m += prod_n;

  /* m = 4 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  prod_n *= xi - x[i-r+5];  /* n = 5 */
  prod_n *= xi - x[i-r+6];  /* n = 6 */
  prod_n *= xi - x[i-r+7];  /* n = 7 */
  prod_n *= xi - x[i-r+8];  /* n = 8 */
  sum_m += prod_n;

  /* m = 5 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  prod_n *= xi - x[i-r+4];  /* n = 4 */
  prod_n *= xi - x[i-r+6];  /* n = 6 */
  prod_n *= xi - x[i-r+7];  /* n = 7 */
  prod_n *= xi - x[i-r+8];  /* n = 8 */
  sum_m += prod_n;

  /* m = 6 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  prod_n *= xi - x[i-r+4];  /* n = 4 */
  prod_n *= xi - x[i-r+5];  /* n = 5 */
  prod_n *= xi - x[i-r+7];  /* n = 7 */
  prod_n *= xi - x[i-r+8];  /* n = 8 */
  sum_m += prod_n;

  /* m = 7 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  prod_n *= xi - x[i-r+4];  /* n = 4 */
  prod_n *= xi - x[i-r+5];  /* n = 5 */
  prod_n *= xi - x[i-r+6];  /* n = 6 */
  prod_n *= xi - x[i-r+8];  /* n = 8 */
  sum_m += prod_n;

  /* m = 8 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  prod_n *= xi - x[i-r+4];  /* n = 4 */
  prod_n *= xi - x[i-r+5];  /* n = 5 */
  prod_n *= xi - x[i-r+6];  /* n = 6 */
  prod_n *= xi - x[i-r+7];  /* n = 7 */
  sum_m += prod_n;

  prod_m = 1.0;
  prod_m *= x[i-r+9] - x[i-r+0];
  prod_m *= x[i-r+9] - x[i-r+1];
  prod_m *= x[i-r+9] - x[i-r+2];
  prod_m *= x[i-r+9] - x[i-r+3];
  prod_m *= x[i-r+9] - x[i-r+4];
  prod_m *= x[i-r+9] - x[i-r+5];
  prod_m *= x[i-r+9] - x[i-r+6];
  prod_m *= x[i-r+9] - x[i-r+7];
  prod_m *= x[i-r+9] - x[i-r+8];

  sum_l += sum_m / prod_m * (x[i-r+0+1] - x[i-r+0]);

  c[0] = sum_l;

  /* j = 1 */
  sum_l = 0.0;

  /* l = 2 */
  sum_m = 0.0;

  /* m = 0 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  prod_n *= xi - x[i-r+4];  /* n = 4 */
  prod_n *= xi - x[i-r+5];  /* n = 5 */
  prod_n *= xi - x[i-r+6];  /* n = 6 */
  prod_n *= xi - x[i-r+7];  /* n = 7 */
  prod_n *= xi - x[i-r+8];  /* n = 8 */
  prod_n *= xi - x[i-r+9];  /* n = 9 */
  sum_m += prod_n;

  /* m = 1 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  prod_n *= xi - x[i-r+4];  /* n = 4 */
  prod_n *= xi - x[i-r+5];  /* n = 5 */
  prod_n *= xi - x[i-r+6];  /* n = 6 */
  prod_n *= xi - x[i-r+7];  /* n = 7 */
  prod_n *= xi - x[i-r+8];  /* n = 8 */
  prod_n *= xi - x[i-r+9];  /* n = 9 */
  sum_m += prod_n;

  /* m = 3 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+4];  /* n = 4 */
  prod_n *= xi - x[i-r+5];  /* n = 5 */
  prod_n *= xi - x[i-r+6];  /* n = 6 */
  prod_n *= xi - x[i-r+7];  /* n = 7 */
  prod_n *= xi - x[i-r+8];  /* n = 8 */
  prod_n *= xi - x[i-r+9];  /* n = 9 */
  sum_m += prod_n;

  /* m = 4 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  prod_n *= xi - x[i-r+5];  /* n = 5 */
  prod_n *= xi - x[i-r+6];  /* n = 6 */
  prod_n *= xi - x[i-r+7];  /* n = 7 */
  prod_n *= xi - x[i-r+8];  /* n = 8 */
  prod_n *= xi - x[i-r+9];  /* n = 9 */
  sum_m += prod_n;

  /* m = 5 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  prod_n *= xi - x[i-r+4];  /* n = 4 */
  prod_n *= xi - x[i-r+6];  /* n = 6 */
  prod_n *= xi - x[i-r+7];  /* n = 7 */
  prod_n *= xi - x[i-r+8];  /* n = 8 */
  prod_n *= xi - x[i-r+9];  /* n = 9 */
  sum_m += prod_n;

  /* m = 6 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  prod_n *= xi - x[i-r+4];  /* n = 4 */
  prod_n *= xi - x[i-r+5];  /* n = 5 */
  prod_n *= xi - x[i-r+7];  /* n = 7 */
  prod_n *= xi - x[i-r+8];  /* n = 8 */
  prod_n *= xi - x[i-r+9];  /* n = 9 */
  sum_m += prod_n;

  /* m = 7 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  prod_n *= xi - x[i-r+4];  /* n = 4 */
  prod_n *= xi - x[i-r+5];  /* n = 5 */
  prod_n *= xi - x[i-r+6];  /* n = 6 */
  prod_n *= xi - x[i-r+8];  /* n = 8 */
  prod_n *= xi - x[i-r+9];  /* n = 9 */
  sum_m += prod_n;

  /* m = 8 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  prod_n *= xi - x[i-r+4];  /* n = 4 */
  prod_n *= xi - x[i-r+5];  /* n = 5 */
  prod_n *= xi - x[i-r+6];  /* n = 6 */
  prod_n *= xi - x[i-r+7];  /* n = 7 */
  prod_n *= xi - x[i-r+9];  /* n = 9 */
  sum_m += prod_n;

  /* m = 9 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  prod_n *= xi - x[i-r+4];  /* n = 4 */
  prod_n *= xi - x[i-r+5];  /* n = 5 */
  prod_n *= xi - x[i-r+6];  /* n = 6 */
  prod_n *= xi - x[i-r+7];  /* n = 7 */
  prod_n *= xi - x[i-r+8];  /* n = 8 */
  sum_m += prod_n;

  prod_m = 1.0;
  prod_m *= x[i-r+2] - x[i-r+0];
  prod_m *= x[i-r+2] - x[i-r+1];
  prod_m *= x[i-r+2] - x[i-r+3];
  prod_m *= x[i-r+2] - x[i-r+4];
  prod_m *= x[i-r+2] - x[i-r+5];
  prod_m *= x[i-r+2] - x[i-r+6];
  prod_m *= x[i-r+2] - x[i-r+7];
  prod_m *= x[i-r+2] - x[i-r+8];
  prod_m *= x[i-r+2] - x[i-r+9];

  sum_l += sum_m / prod_m * (x[i-r+1+1] - x[i-r+1]);

  /* l = 3 */
  sum_m = 0.0;

  /* m = 0 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+4];  /* n = 4 */
  prod_n *= xi - x[i-r+5];  /* n = 5 */
  prod_n *= xi - x[i-r+6];  /* n = 6 */
  prod_n *= xi - x[i-r+7];  /* n = 7 */
  prod_n *= xi - x[i-r+8];  /* n = 8 */
  prod_n *= xi - x[i-r+9];  /* n = 9 */
  sum_m += prod_n;

  /* m = 1 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+4];  /* n = 4 */
  prod_n *= xi - x[i-r+5];  /* n = 5 */
  prod_n *= xi - x[i-r+6];  /* n = 6 */
  prod_n *= xi - x[i-r+7];  /* n = 7 */
  prod_n *= xi - x[i-r+8];  /* n = 8 */
  prod_n *= xi - x[i-r+9];  /* n = 9 */
  sum_m += prod_n;

  /* m = 2 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+4];  /* n = 4 */
  prod_n *= xi - x[i-r+5];  /* n = 5 */
  prod_n *= xi - x[i-r+6];  /* n = 6 */
  prod_n *= xi - x[i-r+7];  /* n = 7 */
  prod_n *= xi - x[i-r+8];  /* n = 8 */
  prod_n *= xi - x[i-r+9];  /* n = 9 */
  sum_m += prod_n;

  /* m = 4 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+5];  /* n = 5 */
  prod_n *= xi - x[i-r+6];  /* n = 6 */
  prod_n *= xi - x[i-r+7];  /* n = 7 */
  prod_n *= xi - x[i-r+8];  /* n = 8 */
  prod_n *= xi - x[i-r+9];  /* n = 9 */
  sum_m += prod_n;

  /* m = 5 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+4];  /* n = 4 */
  prod_n *= xi - x[i-r+6];  /* n = 6 */
  prod_n *= xi - x[i-r+7];  /* n = 7 */
  prod_n *= xi - x[i-r+8];  /* n = 8 */
  prod_n *= xi - x[i-r+9];  /* n = 9 */
  sum_m += prod_n;

  /* m = 6 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+4];  /* n = 4 */
  prod_n *= xi - x[i-r+5];  /* n = 5 */
  prod_n *= xi - x[i-r+7];  /* n = 7 */
  prod_n *= xi - x[i-r+8];  /* n = 8 */
  prod_n *= xi - x[i-r+9];  /* n = 9 */
  sum_m += prod_n;

  /* m = 7 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+4];  /* n = 4 */
  prod_n *= xi - x[i-r+5];  /* n = 5 */
  prod_n *= xi - x[i-r+6];  /* n = 6 */
  prod_n *= xi - x[i-r+8];  /* n = 8 */
  prod_n *= xi - x[i-r+9];  /* n = 9 */
  sum_m += prod_n;

  /* m = 8 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+4];  /* n = 4 */
  prod_n *= xi - x[i-r+5];  /* n = 5 */
  prod_n *= xi - x[i-r+6];  /* n = 6 */
  prod_n *= xi - x[i-r+7];  /* n = 7 */
  prod_n *= xi - x[i-r+9];  /* n = 9 */
  sum_m += prod_n;

  /* m = 9 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+4];  /* n = 4 */
  prod_n *= xi - x[i-r+5];  /* n = 5 */
  prod_n *= xi - x[i-r+6];  /* n = 6 */
  prod_n *= xi - x[i-r+7];  /* n = 7 */
  prod_n *= xi - x[i-r+8];  /* n = 8 */
  sum_m += prod_n;

  prod_m = 1.0;
  prod_m *= x[i-r+3] - x[i-r+0];
  prod_m *= x[i-r+3] - x[i-r+1];
  prod_m *= x[i-r+3] - x[i-r+2];
  prod_m *= x[i-r+3] - x[i-r+4];
  prod_m *= x[i-r+3] - x[i-r+5];
  prod_m *= x[i-r+3] - x[i-r+6];
  prod_m *= x[i-r+3] - x[i-r+7];
  prod_m *= x[i-r+3] - x[i-r+8];
  prod_m *= x[i-r+3] - x[i-r+9];

  sum_l += sum_m / prod_m * (x[i-r+1+1] - x[i-r+1]);

  /* l = 4 */
  sum_m = 0.0;

  /* m = 0 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  prod_n *= xi - x[i-r+5];  /* n = 5 */
  prod_n *= xi - x[i-r+6];  /* n = 6 */
  prod_n *= xi - x[i-r+7];  /* n = 7 */
  prod_n *= xi - x[i-r+8];  /* n = 8 */
  prod_n *= xi - x[i-r+9];  /* n = 9 */
  sum_m += prod_n;

  /* m = 1 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  prod_n *= xi - x[i-r+5];  /* n = 5 */
  prod_n *= xi - x[i-r+6];  /* n = 6 */
  prod_n *= xi - x[i-r+7];  /* n = 7 */
  prod_n *= xi - x[i-r+8];  /* n = 8 */
  prod_n *= xi - x[i-r+9];  /* n = 9 */
  sum_m += prod_n;

  /* m = 2 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  prod_n *= xi - x[i-r+5];  /* n = 5 */
  prod_n *= xi - x[i-r+6];  /* n = 6 */
  prod_n *= xi - x[i-r+7];  /* n = 7 */
  prod_n *= xi - x[i-r+8];  /* n = 8 */
  prod_n *= xi - x[i-r+9];  /* n = 9 */
  sum_m += prod_n;

  /* m = 3 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+5];  /* n = 5 */
  prod_n *= xi - x[i-r+6];  /* n = 6 */
  prod_n *= xi - x[i-r+7];  /* n = 7 */
  prod_n *= xi - x[i-r+8];  /* n = 8 */
  prod_n *= xi - x[i-r+9];  /* n = 9 */
  sum_m += prod_n;

  /* m = 5 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  prod_n *= xi - x[i-r+6];  /* n = 6 */
  prod_n *= xi - x[i-r+7];  /* n = 7 */
  prod_n *= xi - x[i-r+8];  /* n = 8 */
  prod_n *= xi - x[i-r+9];  /* n = 9 */
  sum_m += prod_n;

  /* m = 6 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  prod_n *= xi - x[i-r+5];  /* n = 5 */
  prod_n *= xi - x[i-r+7];  /* n = 7 */
  prod_n *= xi - x[i-r+8];  /* n = 8 */
  prod_n *= xi - x[i-r+9];  /* n = 9 */
  sum_m += prod_n;

  /* m = 7 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  prod_n *= xi - x[i-r+5];  /* n = 5 */
  prod_n *= xi - x[i-r+6];  /* n = 6 */
  prod_n *= xi - x[i-r+8];  /* n = 8 */
  prod_n *= xi - x[i-r+9];  /* n = 9 */
  sum_m += prod_n;

  /* m = 8 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  prod_n *= xi - x[i-r+5];  /* n = 5 */
  prod_n *= xi - x[i-r+6];  /* n = 6 */
  prod_n *= xi - x[i-r+7];  /* n = 7 */
  prod_n *= xi - x[i-r+9];  /* n = 9 */
  sum_m += prod_n;

  /* m = 9 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  prod_n *= xi - x[i-r+5];  /* n = 5 */
  prod_n *= xi - x[i-r+6];  /* n = 6 */
  prod_n *= xi - x[i-r+7];  /* n = 7 */
  prod_n *= xi - x[i-r+8];  /* n = 8 */
  sum_m += prod_n;

  prod_m = 1.0;
  prod_m *= x[i-r+4] - x[i-r+0];
  prod_m *= x[i-r+4] - x[i-r+1];
  prod_m *= x[i-r+4] - x[i-r+2];
  prod_m *= x[i-r+4] - x[i-r+3];
  prod_m *= x[i-r+4] - x[i-r+5];
  prod_m *= x[i-r+4] - x[i-r+6];
  prod_m *= x[i-r+4] - x[i-r+7];
  prod_m *= x[i-r+4] - x[i-r+8];
  prod_m *= x[i-r+4] - x[i-r+9];

  sum_l += sum_m / prod_m * (x[i-r+1+1] - x[i-r+1]);

  /* l = 5 */
  sum_m = 0.0;

  /* m = 0 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  prod_n *= xi - x[i-r+4];  /* n = 4 */
  prod_n *= xi - x[i-r+6];  /* n = 6 */
  prod_n *= xi - x[i-r+7];  /* n = 7 */
  prod_n *= xi - x[i-r+8];  /* n = 8 */
  prod_n *= xi - x[i-r+9];  /* n = 9 */
  sum_m += prod_n;

  /* m = 1 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  prod_n *= xi - x[i-r+4];  /* n = 4 */
  prod_n *= xi - x[i-r+6];  /* n = 6 */
  prod_n *= xi - x[i-r+7];  /* n = 7 */
  prod_n *= xi - x[i-r+8];  /* n = 8 */
  prod_n *= xi - x[i-r+9];  /* n = 9 */
  sum_m += prod_n;

  /* m = 2 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  prod_n *= xi - x[i-r+4];  /* n = 4 */
  prod_n *= xi - x[i-r+6];  /* n = 6 */
  prod_n *= xi - x[i-r+7];  /* n = 7 */
  prod_n *= xi - x[i-r+8];  /* n = 8 */
  prod_n *= xi - x[i-r+9];  /* n = 9 */
  sum_m += prod_n;

  /* m = 3 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+4];  /* n = 4 */
  prod_n *= xi - x[i-r+6];  /* n = 6 */
  prod_n *= xi - x[i-r+7];  /* n = 7 */
  prod_n *= xi - x[i-r+8];  /* n = 8 */
  prod_n *= xi - x[i-r+9];  /* n = 9 */
  sum_m += prod_n;

  /* m = 4 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  prod_n *= xi - x[i-r+6];  /* n = 6 */
  prod_n *= xi - x[i-r+7];  /* n = 7 */
  prod_n *= xi - x[i-r+8];  /* n = 8 */
  prod_n *= xi - x[i-r+9];  /* n = 9 */
  sum_m += prod_n;

  /* m = 6 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  prod_n *= xi - x[i-r+4];  /* n = 4 */
  prod_n *= xi - x[i-r+7];  /* n = 7 */
  prod_n *= xi - x[i-r+8];  /* n = 8 */
  prod_n *= xi - x[i-r+9];  /* n = 9 */
  sum_m += prod_n;

  /* m = 7 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  prod_n *= xi - x[i-r+4];  /* n = 4 */
  prod_n *= xi - x[i-r+6];  /* n = 6 */
  prod_n *= xi - x[i-r+8];  /* n = 8 */
  prod_n *= xi - x[i-r+9];  /* n = 9 */
  sum_m += prod_n;

  /* m = 8 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  prod_n *= xi - x[i-r+4];  /* n = 4 */
  prod_n *= xi - x[i-r+6];  /* n = 6 */
  prod_n *= xi - x[i-r+7];  /* n = 7 */
  prod_n *= xi - x[i-r+9];  /* n = 9 */
  sum_m += prod_n;

  /* m = 9 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  prod_n *= xi - x[i-r+4];  /* n = 4 */
  prod_n *= xi - x[i-r+6];  /* n = 6 */
  prod_n *= xi - x[i-r+7];  /* n = 7 */
  prod_n *= xi - x[i-r+8];  /* n = 8 */
  sum_m += prod_n;

  prod_m = 1.0;
  prod_m *= x[i-r+5] - x[i-r+0];
  prod_m *= x[i-r+5] - x[i-r+1];
  prod_m *= x[i-r+5] - x[i-r+2];
  prod_m *= x[i-r+5] - x[i-r+3];
  prod_m *= x[i-r+5] - x[i-r+4];
  prod_m *= x[i-r+5] - x[i-r+6];
  prod_m *= x[i-r+5] - x[i-r+7];
  prod_m *= x[i-r+5] - x[i-r+8];
  prod_m *= x[i-r+5] - x[i-r+9];

  sum_l += sum_m / prod_m * (x[i-r+1+1] - x[i-r+1]);

  /* l = 6 */
  sum_m = 0.0;

  /* m = 0 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  prod_n *= xi - x[i-r+4];  /* n = 4 */
  prod_n *= xi - x[i-r+5];  /* n = 5 */
  prod_n *= xi - x[i-r+7];  /* n = 7 */
  prod_n *= xi - x[i-r+8];  /* n = 8 */
  prod_n *= xi - x[i-r+9];  /* n = 9 */
  sum_m += prod_n;

  /* m = 1 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  prod_n *= xi - x[i-r+4];  /* n = 4 */
  prod_n *= xi - x[i-r+5];  /* n = 5 */
  prod_n *= xi - x[i-r+7];  /* n = 7 */
  prod_n *= xi - x[i-r+8];  /* n = 8 */
  prod_n *= xi - x[i-r+9];  /* n = 9 */
  sum_m += prod_n;

  /* m = 2 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  prod_n *= xi - x[i-r+4];  /* n = 4 */
  prod_n *= xi - x[i-r+5];  /* n = 5 */
  prod_n *= xi - x[i-r+7];  /* n = 7 */
  prod_n *= xi - x[i-r+8];  /* n = 8 */
  prod_n *= xi - x[i-r+9];  /* n = 9 */
  sum_m += prod_n;

  /* m = 3 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+4];  /* n = 4 */
  prod_n *= xi - x[i-r+5];  /* n = 5 */
  prod_n *= xi - x[i-r+7];  /* n = 7 */
  prod_n *= xi - x[i-r+8];  /* n = 8 */
  prod_n *= xi - x[i-r+9];  /* n = 9 */
  sum_m += prod_n;

  /* m = 4 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  prod_n *= xi - x[i-r+5];  /* n = 5 */
  prod_n *= xi - x[i-r+7];  /* n = 7 */
  prod_n *= xi - x[i-r+8];  /* n = 8 */
  prod_n *= xi - x[i-r+9];  /* n = 9 */
  sum_m += prod_n;

  /* m = 5 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  prod_n *= xi - x[i-r+4];  /* n = 4 */
  prod_n *= xi - x[i-r+7];  /* n = 7 */
  prod_n *= xi - x[i-r+8];  /* n = 8 */
  prod_n *= xi - x[i-r+9];  /* n = 9 */
  sum_m += prod_n;

  /* m = 7 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  prod_n *= xi - x[i-r+4];  /* n = 4 */
  prod_n *= xi - x[i-r+5];  /* n = 5 */
  prod_n *= xi - x[i-r+8];  /* n = 8 */
  prod_n *= xi - x[i-r+9];  /* n = 9 */
  sum_m += prod_n;

  /* m = 8 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  prod_n *= xi - x[i-r+4];  /* n = 4 */
  prod_n *= xi - x[i-r+5];  /* n = 5 */
  prod_n *= xi - x[i-r+7];  /* n = 7 */
  prod_n *= xi - x[i-r+9];  /* n = 9 */
  sum_m += prod_n;

  /* m = 9 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  prod_n *= xi - x[i-r+4];  /* n = 4 */
  prod_n *= xi - x[i-r+5];  /* n = 5 */
  prod_n *= xi - x[i-r+7];  /* n = 7 */
  prod_n *= xi - x[i-r+8];  /* n = 8 */
  sum_m += prod_n;

  prod_m = 1.0;
  prod_m *= x[i-r+6] - x[i-r+0];
  prod_m *= x[i-r+6] - x[i-r+1];
  prod_m *= x[i-r+6] - x[i-r+2];
  prod_m *= x[i-r+6] - x[i-r+3];
  prod_m *= x[i-r+6] - x[i-r+4];
  prod_m *= x[i-r+6] - x[i-r+5];
  prod_m *= x[i-r+6] - x[i-r+7];
  prod_m *= x[i-r+6] - x[i-r+8];
  prod_m *= x[i-r+6] - x[i-r+9];

  sum_l += sum_m / prod_m * (x[i-r+1+1] - x[i-r+1]);

  /* l = 7 */
  sum_m = 0.0;

  /* m = 0 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  prod_n *= xi - x[i-r+4];  /* n = 4 */
  prod_n *= xi - x[i-r+5];  /* n = 5 */
  prod_n *= xi - x[i-r+6];  /* n = 6 */
  prod_n *= xi - x[i-r+8];  /* n = 8 */
  prod_n *= xi - x[i-r+9];  /* n = 9 */
  sum_m += prod_n;

  /* m = 1 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  prod_n *= xi - x[i-r+4];  /* n = 4 */
  prod_n *= xi - x[i-r+5];  /* n = 5 */
  prod_n *= xi - x[i-r+6];  /* n = 6 */
  prod_n *= xi - x[i-r+8];  /* n = 8 */
  prod_n *= xi - x[i-r+9];  /* n = 9 */
  sum_m += prod_n;

  /* m = 2 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  prod_n *= xi - x[i-r+4];  /* n = 4 */
  prod_n *= xi - x[i-r+5];  /* n = 5 */
  prod_n *= xi - x[i-r+6];  /* n = 6 */
  prod_n *= xi - x[i-r+8];  /* n = 8 */
  prod_n *= xi - x[i-r+9];  /* n = 9 */
  sum_m += prod_n;

  /* m = 3 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+4];  /* n = 4 */
  prod_n *= xi - x[i-r+5];  /* n = 5 */
  prod_n *= xi - x[i-r+6];  /* n = 6 */
  prod_n *= xi - x[i-r+8];  /* n = 8 */
  prod_n *= xi - x[i-r+9];  /* n = 9 */
  sum_m += prod_n;

  /* m = 4 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  prod_n *= xi - x[i-r+5];  /* n = 5 */
  prod_n *= xi - x[i-r+6];  /* n = 6 */
  prod_n *= xi - x[i-r+8];  /* n = 8 */
  prod_n *= xi - x[i-r+9];  /* n = 9 */
  sum_m += prod_n;

  /* m = 5 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  prod_n *= xi - x[i-r+4];  /* n = 4 */
  prod_n *= xi - x[i-r+6];  /* n = 6 */
  prod_n *= xi - x[i-r+8];  /* n = 8 */
  prod_n *= xi - x[i-r+9];  /* n = 9 */
  sum_m += prod_n;

  /* m = 6 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  prod_n *= xi - x[i-r+4];  /* n = 4 */
  prod_n *= xi - x[i-r+5];  /* n = 5 */
  prod_n *= xi - x[i-r+8];  /* n = 8 */
  prod_n *= xi - x[i-r+9];  /* n = 9 */
  sum_m += prod_n;

  /* m = 8 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  prod_n *= xi - x[i-r+4];  /* n = 4 */
  prod_n *= xi - x[i-r+5];  /* n = 5 */
  prod_n *= xi - x[i-r+6];  /* n = 6 */
  prod_n *= xi - x[i-r+9];  /* n = 9 */
  sum_m += prod_n;

  /* m = 9 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  prod_n *= xi - x[i-r+4];  /* n = 4 */
  prod_n *= xi - x[i-r+5];  /* n = 5 */
  prod_n *= xi - x[i-r+6];  /* n = 6 */
  prod_n *= xi - x[i-r+8];  /* n = 8 */
  sum_m += prod_n;

  prod_m = 1.0;
  prod_m *= x[i-r+7] - x[i-r+0];
  prod_m *= x[i-r+7] - x[i-r+1];
  prod_m *= x[i-r+7] - x[i-r+2];
  prod_m *= x[i-r+7] - x[i-r+3];
  prod_m *= x[i-r+7] - x[i-r+4];
  prod_m *= x[i-r+7] - x[i-r+5];
  prod_m *= x[i-r+7] - x[i-r+6];
  prod_m *= x[i-r+7] - x[i-r+8];
  prod_m *= x[i-r+7] - x[i-r+9];

  sum_l += sum_m / prod_m * (x[i-r+1+1] - x[i-r+1]);

  /* l = 8 */
  sum_m = 0.0;

  /* m = 0 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  prod_n *= xi - x[i-r+4];  /* n = 4 */
  prod_n *= xi - x[i-r+5];  /* n = 5 */
  prod_n *= xi - x[i-r+6];  /* n = 6 */
  prod_n *= xi - x[i-r+7];  /* n = 7 */
  prod_n *= xi - x[i-r+9];  /* n = 9 */
  sum_m += prod_n;

  /* m = 1 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  prod_n *= xi - x[i-r+4];  /* n = 4 */
  prod_n *= xi - x[i-r+5];  /* n = 5 */
  prod_n *= xi - x[i-r+6];  /* n = 6 */
  prod_n *= xi - x[i-r+7];  /* n = 7 */
  prod_n *= xi - x[i-r+9];  /* n = 9 */
  sum_m += prod_n;

  /* m = 2 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  prod_n *= xi - x[i-r+4];  /* n = 4 */
  prod_n *= xi - x[i-r+5];  /* n = 5 */
  prod_n *= xi - x[i-r+6];  /* n = 6 */
  prod_n *= xi - x[i-r+7];  /* n = 7 */
  prod_n *= xi - x[i-r+9];  /* n = 9 */
  sum_m += prod_n;

  /* m = 3 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+4];  /* n = 4 */
  prod_n *= xi - x[i-r+5];  /* n = 5 */
  prod_n *= xi - x[i-r+6];  /* n = 6 */
  prod_n *= xi - x[i-r+7];  /* n = 7 */
  prod_n *= xi - x[i-r+9];  /* n = 9 */
  sum_m += prod_n;

  /* m = 4 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  prod_n *= xi - x[i-r+5];  /* n = 5 */
  prod_n *= xi - x[i-r+6];  /* n = 6 */
  prod_n *= xi - x[i-r+7];  /* n = 7 */
  prod_n *= xi - x[i-r+9];  /* n = 9 */
  sum_m += prod_n;

  /* m = 5 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  prod_n *= xi - x[i-r+4];  /* n = 4 */
  prod_n *= xi - x[i-r+6];  /* n = 6 */
  prod_n *= xi - x[i-r+7];  /* n = 7 */
  prod_n *= xi - x[i-r+9];  /* n = 9 */
  sum_m += prod_n;

  /* m = 6 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  prod_n *= xi - x[i-r+4];  /* n = 4 */
  prod_n *= xi - x[i-r+5];  /* n = 5 */
  prod_n *= xi - x[i-r+7];  /* n = 7 */
  prod_n *= xi - x[i-r+9];  /* n = 9 */
  sum_m += prod_n;

  /* m = 7 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  prod_n *= xi - x[i-r+4];  /* n = 4 */
  prod_n *= xi - x[i-r+5];  /* n = 5 */
  prod_n *= xi - x[i-r+6];  /* n = 6 */
  prod_n *= xi - x[i-r+9];  /* n = 9 */
  sum_m += prod_n;

  /* m = 9 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  prod_n *= xi - x[i-r+4];  /* n = 4 */
  prod_n *= xi - x[i-r+5];  /* n = 5 */
  prod_n *= xi - x[i-r+6];  /* n = 6 */
  prod_n *= xi - x[i-r+7];  /* n = 7 */
  sum_m += prod_n;

  prod_m = 1.0;
  prod_m *= x[i-r+8] - x[i-r+0];
  prod_m *= x[i-r+8] - x[i-r+1];
  prod_m *= x[i-r+8] - x[i-r+2];
  prod_m *= x[i-r+8] - x[i-r+3];
  prod_m *= x[i-r+8] - x[i-r+4];
  prod_m *= x[i-r+8] - x[i-r+5];
  prod_m *= x[i-r+8] - x[i-r+6];
  prod_m *= x[i-r+8] - x[i-r+7];
  prod_m *= x[i-r+8] - x[i-r+9];

  sum_l += sum_m / prod_m * (x[i-r+1+1] - x[i-r+1]);

  /* l = 9 */
  sum_m = 0.0;

  /* m = 0 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  prod_n *= xi - x[i-r+4];  /* n = 4 */
  prod_n *= xi - x[i-r+5];  /* n = 5 */
  prod_n *= xi - x[i-r+6];  /* n = 6 */
  prod_n *= xi - x[i-r+7];  /* n = 7 */
  prod_n *= xi - x[i-r+8];  /* n = 8 */
  sum_m += prod_n;

  /* m = 1 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  prod_n *= xi - x[i-r+4];  /* n = 4 */
  prod_n *= xi - x[i-r+5];  /* n = 5 */
  prod_n *= xi - x[i-r+6];  /* n = 6 */
  prod_n *= xi - x[i-r+7];  /* n = 7 */
  prod_n *= xi - x[i-r+8];  /* n = 8 */
  sum_m += prod_n;

  /* m = 2 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  prod_n *= xi - x[i-r+4];  /* n = 4 */
  prod_n *= xi - x[i-r+5];  /* n = 5 */
  prod_n *= xi - x[i-r+6];  /* n = 6 */
  prod_n *= xi - x[i-r+7];  /* n = 7 */
  prod_n *= xi - x[i-r+8];  /* n = 8 */
  sum_m += prod_n;

  /* m = 3 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+4];  /* n = 4 */
  prod_n *= xi - x[i-r+5];  /* n = 5 */
  prod_n *= xi - x[i-r+6];  /* n = 6 */
  prod_n *= xi - x[i-r+7];  /* n = 7 */
  prod_n *= xi - x[i-r+8];  /* n = 8 */
  sum_m += prod_n;

  /* m = 4 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  prod_n *= xi - x[i-r+5];  /* n = 5 */
  prod_n *= xi - x[i-r+6];  /* n = 6 */
  prod_n *= xi - x[i-r+7];  /* n = 7 */
  prod_n *= xi - x[i-r+8];  /* n = 8 */
  sum_m += prod_n;

  /* m = 5 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  prod_n *= xi - x[i-r+4];  /* n = 4 */
  prod_n *= xi - x[i-r+6];  /* n = 6 */
  prod_n *= xi - x[i-r+7];  /* n = 7 */
  prod_n *= xi - x[i-r+8];  /* n = 8 */
  sum_m += prod_n;

  /* m = 6 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  prod_n *= xi - x[i-r+4];  /* n = 4 */
  prod_n *= xi - x[i-r+5];  /* n = 5 */
  prod_n *= xi - x[i-r+7];  /* n = 7 */
  prod_n *= xi - x[i-r+8];  /* n = 8 */
  sum_m += prod_n;

  /* m = 7 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  prod_n *= xi - x[i-r+4];  /* n = 4 */
  prod_n *= xi - x[i-r+5];  /* n = 5 */
  prod_n *= xi - x[i-r+6];  /* n = 6 */
  prod_n *= xi - x[i-r+8];  /* n = 8 */
  sum_m += prod_n;

  /* m = 8 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  prod_n *= xi - x[i-r+4];  /* n = 4 */
  prod_n *= xi - x[i-r+5];  /* n = 5 */
  prod_n *= xi - x[i-r+6];  /* n = 6 */
  prod_n *= xi - x[i-r+7];  /* n = 7 */
  sum_m += prod_n;

  prod_m = 1.0;
  prod_m *= x[i-r+9] - x[i-r+0];
  prod_m *= x[i-r+9] - x[i-r+1];
  prod_m *= x[i-r+9] - x[i-r+2];
  prod_m *= x[i-r+9] - x[i-r+3];
  prod_m *= x[i-r+9] - x[i-r+4];
  prod_m *= x[i-r+9] - x[i-r+5];
  prod_m *= x[i-r+9] - x[i-r+6];
  prod_m *= x[i-r+9] - x[i-r+7];
  prod_m *= x[i-r+9] - x[i-r+8];

  sum_l += sum_m / prod_m * (x[i-r+1+1] - x[i-r+1]);

  c[1] = sum_l;

  /* j = 2 */
  sum_l = 0.0;

  /* l = 3 */
  sum_m = 0.0;

  /* m = 0 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+4];  /* n = 4 */
  prod_n *= xi - x[i-r+5];  /* n = 5 */
  prod_n *= xi - x[i-r+6];  /* n = 6 */
  prod_n *= xi - x[i-r+7];  /* n = 7 */
  prod_n *= xi - x[i-r+8];  /* n = 8 */
  prod_n *= xi - x[i-r+9];  /* n = 9 */
  sum_m += prod_n;

  /* m = 1 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+4];  /* n = 4 */
  prod_n *= xi - x[i-r+5];  /* n = 5 */
  prod_n *= xi - x[i-r+6];  /* n = 6 */
  prod_n *= xi - x[i-r+7];  /* n = 7 */
  prod_n *= xi - x[i-r+8];  /* n = 8 */
  prod_n *= xi - x[i-r+9];  /* n = 9 */
  sum_m += prod_n;

  /* m = 2 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+4];  /* n = 4 */
  prod_n *= xi - x[i-r+5];  /* n = 5 */
  prod_n *= xi - x[i-r+6];  /* n = 6 */
  prod_n *= xi - x[i-r+7];  /* n = 7 */
  prod_n *= xi - x[i-r+8];  /* n = 8 */
  prod_n *= xi - x[i-r+9];  /* n = 9 */
  sum_m += prod_n;

  /* m = 4 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+5];  /* n = 5 */
  prod_n *= xi - x[i-r+6];  /* n = 6 */
  prod_n *= xi - x[i-r+7];  /* n = 7 */
  prod_n *= xi - x[i-r+8];  /* n = 8 */
  prod_n *= xi - x[i-r+9];  /* n = 9 */
  sum_m += prod_n;

  /* m = 5 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+4];  /* n = 4 */
  prod_n *= xi - x[i-r+6];  /* n = 6 */
  prod_n *= xi - x[i-r+7];  /* n = 7 */
  prod_n *= xi - x[i-r+8];  /* n = 8 */
  prod_n *= xi - x[i-r+9];  /* n = 9 */
  sum_m += prod_n;

  /* m = 6 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+4];  /* n = 4 */
  prod_n *= xi - x[i-r+5];  /* n = 5 */
  prod_n *= xi - x[i-r+7];  /* n = 7 */
  prod_n *= xi - x[i-r+8];  /* n = 8 */
  prod_n *= xi - x[i-r+9];  /* n = 9 */
  sum_m += prod_n;

  /* m = 7 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+4];  /* n = 4 */
  prod_n *= xi - x[i-r+5];  /* n = 5 */
  prod_n *= xi - x[i-r+6];  /* n = 6 */
  prod_n *= xi - x[i-r+8];  /* n = 8 */
  prod_n *= xi - x[i-r+9];  /* n = 9 */
  sum_m += prod_n;

  /* m = 8 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+4];  /* n = 4 */
  prod_n *= xi - x[i-r+5];  /* n = 5 */
  prod_n *= xi - x[i-r+6];  /* n = 6 */
  prod_n *= xi - x[i-r+7];  /* n = 7 */
  prod_n *= xi - x[i-r+9];  /* n = 9 */
  sum_m += prod_n;

  /* m = 9 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+4];  /* n = 4 */
  prod_n *= xi - x[i-r+5];  /* n = 5 */
  prod_n *= xi - x[i-r+6];  /* n = 6 */
  prod_n *= xi - x[i-r+7];  /* n = 7 */
  prod_n *= xi - x[i-r+8];  /* n = 8 */
  sum_m += prod_n;

  prod_m = 1.0;
  prod_m *= x[i-r+3] - x[i-r+0];
  prod_m *= x[i-r+3] - x[i-r+1];
  prod_m *= x[i-r+3] - x[i-r+2];
  prod_m *= x[i-r+3] - x[i-r+4];
  prod_m *= x[i-r+3] - x[i-r+5];
  prod_m *= x[i-r+3] - x[i-r+6];
  prod_m *= x[i-r+3] - x[i-r+7];
  prod_m *= x[i-r+3] - x[i-r+8];
  prod_m *= x[i-r+3] - x[i-r+9];

  sum_l += sum_m / prod_m * (x[i-r+2+1] - x[i-r+2]);

  /* l = 4 */
  sum_m = 0.0;

  /* m = 0 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  prod_n *= xi - x[i-r+5];  /* n = 5 */
  prod_n *= xi - x[i-r+6];  /* n = 6 */
  prod_n *= xi - x[i-r+7];  /* n = 7 */
  prod_n *= xi - x[i-r+8];  /* n = 8 */
  prod_n *= xi - x[i-r+9];  /* n = 9 */
  sum_m += prod_n;

  /* m = 1 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  prod_n *= xi - x[i-r+5];  /* n = 5 */
  prod_n *= xi - x[i-r+6];  /* n = 6 */
  prod_n *= xi - x[i-r+7];  /* n = 7 */
  prod_n *= xi - x[i-r+8];  /* n = 8 */
  prod_n *= xi - x[i-r+9];  /* n = 9 */
  sum_m += prod_n;

  /* m = 2 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  prod_n *= xi - x[i-r+5];  /* n = 5 */
  prod_n *= xi - x[i-r+6];  /* n = 6 */
  prod_n *= xi - x[i-r+7];  /* n = 7 */
  prod_n *= xi - x[i-r+8];  /* n = 8 */
  prod_n *= xi - x[i-r+9];  /* n = 9 */
  sum_m += prod_n;

  /* m = 3 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+5];  /* n = 5 */
  prod_n *= xi - x[i-r+6];  /* n = 6 */
  prod_n *= xi - x[i-r+7];  /* n = 7 */
  prod_n *= xi - x[i-r+8];  /* n = 8 */
  prod_n *= xi - x[i-r+9];  /* n = 9 */
  sum_m += prod_n;

  /* m = 5 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  prod_n *= xi - x[i-r+6];  /* n = 6 */
  prod_n *= xi - x[i-r+7];  /* n = 7 */
  prod_n *= xi - x[i-r+8];  /* n = 8 */
  prod_n *= xi - x[i-r+9];  /* n = 9 */
  sum_m += prod_n;

  /* m = 6 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  prod_n *= xi - x[i-r+5];  /* n = 5 */
  prod_n *= xi - x[i-r+7];  /* n = 7 */
  prod_n *= xi - x[i-r+8];  /* n = 8 */
  prod_n *= xi - x[i-r+9];  /* n = 9 */
  sum_m += prod_n;

  /* m = 7 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  prod_n *= xi - x[i-r+5];  /* n = 5 */
  prod_n *= xi - x[i-r+6];  /* n = 6 */
  prod_n *= xi - x[i-r+8];  /* n = 8 */
  prod_n *= xi - x[i-r+9];  /* n = 9 */
  sum_m += prod_n;

  /* m = 8 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  prod_n *= xi - x[i-r+5];  /* n = 5 */
  prod_n *= xi - x[i-r+6];  /* n = 6 */
  prod_n *= xi - x[i-r+7];  /* n = 7 */
  prod_n *= xi - x[i-r+9];  /* n = 9 */
  sum_m += prod_n;

  /* m = 9 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  prod_n *= xi - x[i-r+5];  /* n = 5 */
  prod_n *= xi - x[i-r+6];  /* n = 6 */
  prod_n *= xi - x[i-r+7];  /* n = 7 */
  prod_n *= xi - x[i-r+8];  /* n = 8 */
  sum_m += prod_n;

  prod_m = 1.0;
  prod_m *= x[i-r+4] - x[i-r+0];
  prod_m *= x[i-r+4] - x[i-r+1];
  prod_m *= x[i-r+4] - x[i-r+2];
  prod_m *= x[i-r+4] - x[i-r+3];
  prod_m *= x[i-r+4] - x[i-r+5];
  prod_m *= x[i-r+4] - x[i-r+6];
  prod_m *= x[i-r+4] - x[i-r+7];
  prod_m *= x[i-r+4] - x[i-r+8];
  prod_m *= x[i-r+4] - x[i-r+9];

  sum_l += sum_m / prod_m * (x[i-r+2+1] - x[i-r+2]);

  /* l = 5 */
  sum_m = 0.0;

  /* m = 0 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  prod_n *= xi - x[i-r+4];  /* n = 4 */
  prod_n *= xi - x[i-r+6];  /* n = 6 */
  prod_n *= xi - x[i-r+7];  /* n = 7 */
  prod_n *= xi - x[i-r+8];  /* n = 8 */
  prod_n *= xi - x[i-r+9];  /* n = 9 */
  sum_m += prod_n;

  /* m = 1 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  prod_n *= xi - x[i-r+4];  /* n = 4 */
  prod_n *= xi - x[i-r+6];  /* n = 6 */
  prod_n *= xi - x[i-r+7];  /* n = 7 */
  prod_n *= xi - x[i-r+8];  /* n = 8 */
  prod_n *= xi - x[i-r+9];  /* n = 9 */
  sum_m += prod_n;

  /* m = 2 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  prod_n *= xi - x[i-r+4];  /* n = 4 */
  prod_n *= xi - x[i-r+6];  /* n = 6 */
  prod_n *= xi - x[i-r+7];  /* n = 7 */
  prod_n *= xi - x[i-r+8];  /* n = 8 */
  prod_n *= xi - x[i-r+9];  /* n = 9 */
  sum_m += prod_n;

  /* m = 3 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+4];  /* n = 4 */
  prod_n *= xi - x[i-r+6];  /* n = 6 */
  prod_n *= xi - x[i-r+7];  /* n = 7 */
  prod_n *= xi - x[i-r+8];  /* n = 8 */
  prod_n *= xi - x[i-r+9];  /* n = 9 */
  sum_m += prod_n;

  /* m = 4 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  prod_n *= xi - x[i-r+6];  /* n = 6 */
  prod_n *= xi - x[i-r+7];  /* n = 7 */
  prod_n *= xi - x[i-r+8];  /* n = 8 */
  prod_n *= xi - x[i-r+9];  /* n = 9 */
  sum_m += prod_n;

  /* m = 6 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  prod_n *= xi - x[i-r+4];  /* n = 4 */
  prod_n *= xi - x[i-r+7];  /* n = 7 */
  prod_n *= xi - x[i-r+8];  /* n = 8 */
  prod_n *= xi - x[i-r+9];  /* n = 9 */
  sum_m += prod_n;

  /* m = 7 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  prod_n *= xi - x[i-r+4];  /* n = 4 */
  prod_n *= xi - x[i-r+6];  /* n = 6 */
  prod_n *= xi - x[i-r+8];  /* n = 8 */
  prod_n *= xi - x[i-r+9];  /* n = 9 */
  sum_m += prod_n;

  /* m = 8 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  prod_n *= xi - x[i-r+4];  /* n = 4 */
  prod_n *= xi - x[i-r+6];  /* n = 6 */
  prod_n *= xi - x[i-r+7];  /* n = 7 */
  prod_n *= xi - x[i-r+9];  /* n = 9 */
  sum_m += prod_n;

  /* m = 9 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  prod_n *= xi - x[i-r+4];  /* n = 4 */
  prod_n *= xi - x[i-r+6];  /* n = 6 */
  prod_n *= xi - x[i-r+7];  /* n = 7 */
  prod_n *= xi - x[i-r+8];  /* n = 8 */
  sum_m += prod_n;

  prod_m = 1.0;
  prod_m *= x[i-r+5] - x[i-r+0];
  prod_m *= x[i-r+5] - x[i-r+1];
  prod_m *= x[i-r+5] - x[i-r+2];
  prod_m *= x[i-r+5] - x[i-r+3];
  prod_m *= x[i-r+5] - x[i-r+4];
  prod_m *= x[i-r+5] - x[i-r+6];
  prod_m *= x[i-r+5] - x[i-r+7];
  prod_m *= x[i-r+5] - x[i-r+8];
  prod_m *= x[i-r+5] - x[i-r+9];

  sum_l += sum_m / prod_m * (x[i-r+2+1] - x[i-r+2]);

  /* l = 6 */
  sum_m = 0.0;

  /* m = 0 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  prod_n *= xi - x[i-r+4];  /* n = 4 */
  prod_n *= xi - x[i-r+5];  /* n = 5 */
  prod_n *= xi - x[i-r+7];  /* n = 7 */
  prod_n *= xi - x[i-r+8];  /* n = 8 */
  prod_n *= xi - x[i-r+9];  /* n = 9 */
  sum_m += prod_n;

  /* m = 1 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  prod_n *= xi - x[i-r+4];  /* n = 4 */
  prod_n *= xi - x[i-r+5];  /* n = 5 */
  prod_n *= xi - x[i-r+7];  /* n = 7 */
  prod_n *= xi - x[i-r+8];  /* n = 8 */
  prod_n *= xi - x[i-r+9];  /* n = 9 */
  sum_m += prod_n;

  /* m = 2 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  prod_n *= xi - x[i-r+4];  /* n = 4 */
  prod_n *= xi - x[i-r+5];  /* n = 5 */
  prod_n *= xi - x[i-r+7];  /* n = 7 */
  prod_n *= xi - x[i-r+8];  /* n = 8 */
  prod_n *= xi - x[i-r+9];  /* n = 9 */
  sum_m += prod_n;

  /* m = 3 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+4];  /* n = 4 */
  prod_n *= xi - x[i-r+5];  /* n = 5 */
  prod_n *= xi - x[i-r+7];  /* n = 7 */
  prod_n *= xi - x[i-r+8];  /* n = 8 */
  prod_n *= xi - x[i-r+9];  /* n = 9 */
  sum_m += prod_n;

  /* m = 4 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  prod_n *= xi - x[i-r+5];  /* n = 5 */
  prod_n *= xi - x[i-r+7];  /* n = 7 */
  prod_n *= xi - x[i-r+8];  /* n = 8 */
  prod_n *= xi - x[i-r+9];  /* n = 9 */
  sum_m += prod_n;

  /* m = 5 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  prod_n *= xi - x[i-r+4];  /* n = 4 */
  prod_n *= xi - x[i-r+7];  /* n = 7 */
  prod_n *= xi - x[i-r+8];  /* n = 8 */
  prod_n *= xi - x[i-r+9];  /* n = 9 */
  sum_m += prod_n;

  /* m = 7 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  prod_n *= xi - x[i-r+4];  /* n = 4 */
  prod_n *= xi - x[i-r+5];  /* n = 5 */
  prod_n *= xi - x[i-r+8];  /* n = 8 */
  prod_n *= xi - x[i-r+9];  /* n = 9 */
  sum_m += prod_n;

  /* m = 8 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  prod_n *= xi - x[i-r+4];  /* n = 4 */
  prod_n *= xi - x[i-r+5];  /* n = 5 */
  prod_n *= xi - x[i-r+7];  /* n = 7 */
  prod_n *= xi - x[i-r+9];  /* n = 9 */
  sum_m += prod_n;

  /* m = 9 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  prod_n *= xi - x[i-r+4];  /* n = 4 */
  prod_n *= xi - x[i-r+5];  /* n = 5 */
  prod_n *= xi - x[i-r+7];  /* n = 7 */
  prod_n *= xi - x[i-r+8];  /* n = 8 */
  sum_m += prod_n;

  prod_m = 1.0;
  prod_m *= x[i-r+6] - x[i-r+0];
  prod_m *= x[i-r+6] - x[i-r+1];
  prod_m *= x[i-r+6] - x[i-r+2];
  prod_m *= x[i-r+6] - x[i-r+3];
  prod_m *= x[i-r+6] - x[i-r+4];
  prod_m *= x[i-r+6] - x[i-r+5];
  prod_m *= x[i-r+6] - x[i-r+7];
  prod_m *= x[i-r+6] - x[i-r+8];
  prod_m *= x[i-r+6] - x[i-r+9];

  sum_l += sum_m / prod_m * (x[i-r+2+1] - x[i-r+2]);

  /* l = 7 */
  sum_m = 0.0;

  /* m = 0 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  prod_n *= xi - x[i-r+4];  /* n = 4 */
  prod_n *= xi - x[i-r+5];  /* n = 5 */
  prod_n *= xi - x[i-r+6];  /* n = 6 */
  prod_n *= xi - x[i-r+8];  /* n = 8 */
  prod_n *= xi - x[i-r+9];  /* n = 9 */
  sum_m += prod_n;

  /* m = 1 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  prod_n *= xi - x[i-r+4];  /* n = 4 */
  prod_n *= xi - x[i-r+5];  /* n = 5 */
  prod_n *= xi - x[i-r+6];  /* n = 6 */
  prod_n *= xi - x[i-r+8];  /* n = 8 */
  prod_n *= xi - x[i-r+9];  /* n = 9 */
  sum_m += prod_n;

  /* m = 2 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  prod_n *= xi - x[i-r+4];  /* n = 4 */
  prod_n *= xi - x[i-r+5];  /* n = 5 */
  prod_n *= xi - x[i-r+6];  /* n = 6 */
  prod_n *= xi - x[i-r+8];  /* n = 8 */
  prod_n *= xi - x[i-r+9];  /* n = 9 */
  sum_m += prod_n;

  /* m = 3 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+4];  /* n = 4 */
  prod_n *= xi - x[i-r+5];  /* n = 5 */
  prod_n *= xi - x[i-r+6];  /* n = 6 */
  prod_n *= xi - x[i-r+8];  /* n = 8 */
  prod_n *= xi - x[i-r+9];  /* n = 9 */
  sum_m += prod_n;

  /* m = 4 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  prod_n *= xi - x[i-r+5];  /* n = 5 */
  prod_n *= xi - x[i-r+6];  /* n = 6 */
  prod_n *= xi - x[i-r+8];  /* n = 8 */
  prod_n *= xi - x[i-r+9];  /* n = 9 */
  sum_m += prod_n;

  /* m = 5 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  prod_n *= xi - x[i-r+4];  /* n = 4 */
  prod_n *= xi - x[i-r+6];  /* n = 6 */
  prod_n *= xi - x[i-r+8];  /* n = 8 */
  prod_n *= xi - x[i-r+9];  /* n = 9 */
  sum_m += prod_n;

  /* m = 6 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  prod_n *= xi - x[i-r+4];  /* n = 4 */
  prod_n *= xi - x[i-r+5];  /* n = 5 */
  prod_n *= xi - x[i-r+8];  /* n = 8 */
  prod_n *= xi - x[i-r+9];  /* n = 9 */
  sum_m += prod_n;

  /* m = 8 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  prod_n *= xi - x[i-r+4];  /* n = 4 */
  prod_n *= xi - x[i-r+5];  /* n = 5 */
  prod_n *= xi - x[i-r+6];  /* n = 6 */
  prod_n *= xi - x[i-r+9];  /* n = 9 */
  sum_m += prod_n;

  /* m = 9 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  prod_n *= xi - x[i-r+4];  /* n = 4 */
  prod_n *= xi - x[i-r+5];  /* n = 5 */
  prod_n *= xi - x[i-r+6];  /* n = 6 */
  prod_n *= xi - x[i-r+8];  /* n = 8 */
  sum_m += prod_n;

  prod_m = 1.0;
  prod_m *= x[i-r+7] - x[i-r+0];
  prod_m *= x[i-r+7] - x[i-r+1];
  prod_m *= x[i-r+7] - x[i-r+2];
  prod_m *= x[i-r+7] - x[i-r+3];
  prod_m *= x[i-r+7] - x[i-r+4];
  prod_m *= x[i-r+7] - x[i-r+5];
  prod_m *= x[i-r+7] - x[i-r+6];
  prod_m *= x[i-r+7] - x[i-r+8];
  prod_m *= x[i-r+7] - x[i-r+9];

  sum_l += sum_m / prod_m * (x[i-r+2+1] - x[i-r+2]);

  /* l = 8 */
  sum_m = 0.0;

  /* m = 0 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  prod_n *= xi - x[i-r+4];  /* n = 4 */
  prod_n *= xi - x[i-r+5];  /* n = 5 */
  prod_n *= xi - x[i-r+6];  /* n = 6 */
  prod_n *= xi - x[i-r+7];  /* n = 7 */
  prod_n *= xi - x[i-r+9];  /* n = 9 */
  sum_m += prod_n;

  /* m = 1 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  prod_n *= xi - x[i-r+4];  /* n = 4 */
  prod_n *= xi - x[i-r+5];  /* n = 5 */
  prod_n *= xi - x[i-r+6];  /* n = 6 */
  prod_n *= xi - x[i-r+7];  /* n = 7 */
  prod_n *= xi - x[i-r+9];  /* n = 9 */
  sum_m += prod_n;

  /* m = 2 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  prod_n *= xi - x[i-r+4];  /* n = 4 */
  prod_n *= xi - x[i-r+5];  /* n = 5 */
  prod_n *= xi - x[i-r+6];  /* n = 6 */
  prod_n *= xi - x[i-r+7];  /* n = 7 */
  prod_n *= xi - x[i-r+9];  /* n = 9 */
  sum_m += prod_n;

  /* m = 3 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+4];  /* n = 4 */
  prod_n *= xi - x[i-r+5];  /* n = 5 */
  prod_n *= xi - x[i-r+6];  /* n = 6 */
  prod_n *= xi - x[i-r+7];  /* n = 7 */
  prod_n *= xi - x[i-r+9];  /* n = 9 */
  sum_m += prod_n;

  /* m = 4 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  prod_n *= xi - x[i-r+5];  /* n = 5 */
  prod_n *= xi - x[i-r+6];  /* n = 6 */
  prod_n *= xi - x[i-r+7];  /* n = 7 */
  prod_n *= xi - x[i-r+9];  /* n = 9 */
  sum_m += prod_n;

  /* m = 5 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  prod_n *= xi - x[i-r+4];  /* n = 4 */
  prod_n *= xi - x[i-r+6];  /* n = 6 */
  prod_n *= xi - x[i-r+7];  /* n = 7 */
  prod_n *= xi - x[i-r+9];  /* n = 9 */
  sum_m += prod_n;

  /* m = 6 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  prod_n *= xi - x[i-r+4];  /* n = 4 */
  prod_n *= xi - x[i-r+5];  /* n = 5 */
  prod_n *= xi - x[i-r+7];  /* n = 7 */
  prod_n *= xi - x[i-r+9];  /* n = 9 */
  sum_m += prod_n;

  /* m = 7 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  prod_n *= xi - x[i-r+4];  /* n = 4 */
  prod_n *= xi - x[i-r+5];  /* n = 5 */
  prod_n *= xi - x[i-r+6];  /* n = 6 */
  prod_n *= xi - x[i-r+9];  /* n = 9 */
  sum_m += prod_n;

  /* m = 9 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  prod_n *= xi - x[i-r+4];  /* n = 4 */
  prod_n *= xi - x[i-r+5];  /* n = 5 */
  prod_n *= xi - x[i-r+6];  /* n = 6 */
  prod_n *= xi - x[i-r+7];  /* n = 7 */
  sum_m += prod_n;

  prod_m = 1.0;
  prod_m *= x[i-r+8] - x[i-r+0];
  prod_m *= x[i-r+8] - x[i-r+1];
  prod_m *= x[i-r+8] - x[i-r+2];
  prod_m *= x[i-r+8] - x[i-r+3];
  prod_m *= x[i-r+8] - x[i-r+4];
  prod_m *= x[i-r+8] - x[i-r+5];
  prod_m *= x[i-r+8] - x[i-r+6];
  prod_m *= x[i-r+8] - x[i-r+7];
  prod_m *= x[i-r+8] - x[i-r+9];

  sum_l += sum_m / prod_m * (x[i-r+2+1] - x[i-r+2]);

  /* l = 9 */
  sum_m = 0.0;

  /* m = 0 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  prod_n *= xi - x[i-r+4];  /* n = 4 */
  prod_n *= xi - x[i-r+5];  /* n = 5 */
  prod_n *= xi - x[i-r+6];  /* n = 6 */
  prod_n *= xi - x[i-r+7];  /* n = 7 */
  prod_n *= xi - x[i-r+8];  /* n = 8 */
  sum_m += prod_n;

  /* m = 1 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  prod_n *= xi - x[i-r+4];  /* n = 4 */
  prod_n *= xi - x[i-r+5];  /* n = 5 */
  prod_n *= xi - x[i-r+6];  /* n = 6 */
  prod_n *= xi - x[i-r+7];  /* n = 7 */
  prod_n *= xi - x[i-r+8];  /* n = 8 */
  sum_m += prod_n;

  /* m = 2 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  prod_n *= xi - x[i-r+4];  /* n = 4 */
  prod_n *= xi - x[i-r+5];  /* n = 5 */
  prod_n *= xi - x[i-r+6];  /* n = 6 */
  prod_n *= xi - x[i-r+7];  /* n = 7 */
  prod_n *= xi - x[i-r+8];  /* n = 8 */
  sum_m += prod_n;

  /* m = 3 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+4];  /* n = 4 */
  prod_n *= xi - x[i-r+5];  /* n = 5 */
  prod_n *= xi - x[i-r+6];  /* n = 6 */
  prod_n *= xi - x[i-r+7];  /* n = 7 */
  prod_n *= xi - x[i-r+8];  /* n = 8 */
  sum_m += prod_n;

  /* m = 4 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  prod_n *= xi - x[i-r+5];  /* n = 5 */
  prod_n *= xi - x[i-r+6];  /* n = 6 */
  prod_n *= xi - x[i-r+7];  /* n = 7 */
  prod_n *= xi - x[i-r+8];  /* n = 8 */
  sum_m += prod_n;

  /* m = 5 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  prod_n *= xi - x[i-r+4];  /* n = 4 */
  prod_n *= xi - x[i-r+6];  /* n = 6 */
  prod_n *= xi - x[i-r+7];  /* n = 7 */
  prod_n *= xi - x[i-r+8];  /* n = 8 */
  sum_m += prod_n;

  /* m = 6 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  prod_n *= xi - x[i-r+4];  /* n = 4 */
  prod_n *= xi - x[i-r+5];  /* n = 5 */
  prod_n *= xi - x[i-r+7];  /* n = 7 */
  prod_n *= xi - x[i-r+8];  /* n = 8 */
  sum_m += prod_n;

  /* m = 7 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  prod_n *= xi - x[i-r+4];  /* n = 4 */
  prod_n *= xi - x[i-r+5];  /* n = 5 */
  prod_n *= xi - x[i-r+6];  /* n = 6 */
  prod_n *= xi - x[i-r+8];  /* n = 8 */
  sum_m += prod_n;

  /* m = 8 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  prod_n *= xi - x[i-r+4];  /* n = 4 */
  prod_n *= xi - x[i-r+5];  /* n = 5 */
  prod_n *= xi - x[i-r+6];  /* n = 6 */
  prod_n *= xi - x[i-r+7];  /* n = 7 */
  sum_m += prod_n;

  prod_m = 1.0;
  prod_m *= x[i-r+9] - x[i-r+0];
  prod_m *= x[i-r+9] - x[i-r+1];
  prod_m *= x[i-r+9] - x[i-r+2];
  prod_m *= x[i-r+9] - x[i-r+3];
  prod_m *= x[i-r+9] - x[i-r+4];
  prod_m *= x[i-r+9] - x[i-r+5];
  prod_m *= x[i-r+9] - x[i-r+6];
  prod_m *= x[i-r+9] - x[i-r+7];
  prod_m *= x[i-r+9] - x[i-r+8];

  sum_l += sum_m / prod_m * (x[i-r+2+1] - x[i-r+2]);

  c[2] = sum_l;

  /* j = 3 */
  sum_l = 0.0;

  /* l = 4 */
  sum_m = 0.0;

  /* m = 0 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  prod_n *= xi - x[i-r+5];  /* n = 5 */
  prod_n *= xi - x[i-r+6];  /* n = 6 */
  prod_n *= xi - x[i-r+7];  /* n = 7 */
  prod_n *= xi - x[i-r+8];  /* n = 8 */
  prod_n *= xi - x[i-r+9];  /* n = 9 */
  sum_m += prod_n;

  /* m = 1 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  prod_n *= xi - x[i-r+5];  /* n = 5 */
  prod_n *= xi - x[i-r+6];  /* n = 6 */
  prod_n *= xi - x[i-r+7];  /* n = 7 */
  prod_n *= xi - x[i-r+8];  /* n = 8 */
  prod_n *= xi - x[i-r+9];  /* n = 9 */
  sum_m += prod_n;

  /* m = 2 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  prod_n *= xi - x[i-r+5];  /* n = 5 */
  prod_n *= xi - x[i-r+6];  /* n = 6 */
  prod_n *= xi - x[i-r+7];  /* n = 7 */
  prod_n *= xi - x[i-r+8];  /* n = 8 */
  prod_n *= xi - x[i-r+9];  /* n = 9 */
  sum_m += prod_n;

  /* m = 3 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+5];  /* n = 5 */
  prod_n *= xi - x[i-r+6];  /* n = 6 */
  prod_n *= xi - x[i-r+7];  /* n = 7 */
  prod_n *= xi - x[i-r+8];  /* n = 8 */
  prod_n *= xi - x[i-r+9];  /* n = 9 */
  sum_m += prod_n;

  /* m = 5 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  prod_n *= xi - x[i-r+6];  /* n = 6 */
  prod_n *= xi - x[i-r+7];  /* n = 7 */
  prod_n *= xi - x[i-r+8];  /* n = 8 */
  prod_n *= xi - x[i-r+9];  /* n = 9 */
  sum_m += prod_n;

  /* m = 6 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  prod_n *= xi - x[i-r+5];  /* n = 5 */
  prod_n *= xi - x[i-r+7];  /* n = 7 */
  prod_n *= xi - x[i-r+8];  /* n = 8 */
  prod_n *= xi - x[i-r+9];  /* n = 9 */
  sum_m += prod_n;

  /* m = 7 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  prod_n *= xi - x[i-r+5];  /* n = 5 */
  prod_n *= xi - x[i-r+6];  /* n = 6 */
  prod_n *= xi - x[i-r+8];  /* n = 8 */
  prod_n *= xi - x[i-r+9];  /* n = 9 */
  sum_m += prod_n;

  /* m = 8 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  prod_n *= xi - x[i-r+5];  /* n = 5 */
  prod_n *= xi - x[i-r+6];  /* n = 6 */
  prod_n *= xi - x[i-r+7];  /* n = 7 */
  prod_n *= xi - x[i-r+9];  /* n = 9 */
  sum_m += prod_n;

  /* m = 9 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  prod_n *= xi - x[i-r+5];  /* n = 5 */
  prod_n *= xi - x[i-r+6];  /* n = 6 */
  prod_n *= xi - x[i-r+7];  /* n = 7 */
  prod_n *= xi - x[i-r+8];  /* n = 8 */
  sum_m += prod_n;

  prod_m = 1.0;
  prod_m *= x[i-r+4] - x[i-r+0];
  prod_m *= x[i-r+4] - x[i-r+1];
  prod_m *= x[i-r+4] - x[i-r+2];
  prod_m *= x[i-r+4] - x[i-r+3];
  prod_m *= x[i-r+4] - x[i-r+5];
  prod_m *= x[i-r+4] - x[i-r+6];
  prod_m *= x[i-r+4] - x[i-r+7];
  prod_m *= x[i-r+4] - x[i-r+8];
  prod_m *= x[i-r+4] - x[i-r+9];

  sum_l += sum_m / prod_m * (x[i-r+3+1] - x[i-r+3]);

  /* l = 5 */
  sum_m = 0.0;

  /* m = 0 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  prod_n *= xi - x[i-r+4];  /* n = 4 */
  prod_n *= xi - x[i-r+6];  /* n = 6 */
  prod_n *= xi - x[i-r+7];  /* n = 7 */
  prod_n *= xi - x[i-r+8];  /* n = 8 */
  prod_n *= xi - x[i-r+9];  /* n = 9 */
  sum_m += prod_n;

  /* m = 1 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  prod_n *= xi - x[i-r+4];  /* n = 4 */
  prod_n *= xi - x[i-r+6];  /* n = 6 */
  prod_n *= xi - x[i-r+7];  /* n = 7 */
  prod_n *= xi - x[i-r+8];  /* n = 8 */
  prod_n *= xi - x[i-r+9];  /* n = 9 */
  sum_m += prod_n;

  /* m = 2 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  prod_n *= xi - x[i-r+4];  /* n = 4 */
  prod_n *= xi - x[i-r+6];  /* n = 6 */
  prod_n *= xi - x[i-r+7];  /* n = 7 */
  prod_n *= xi - x[i-r+8];  /* n = 8 */
  prod_n *= xi - x[i-r+9];  /* n = 9 */
  sum_m += prod_n;

  /* m = 3 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+4];  /* n = 4 */
  prod_n *= xi - x[i-r+6];  /* n = 6 */
  prod_n *= xi - x[i-r+7];  /* n = 7 */
  prod_n *= xi - x[i-r+8];  /* n = 8 */
  prod_n *= xi - x[i-r+9];  /* n = 9 */
  sum_m += prod_n;

  /* m = 4 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  prod_n *= xi - x[i-r+6];  /* n = 6 */
  prod_n *= xi - x[i-r+7];  /* n = 7 */
  prod_n *= xi - x[i-r+8];  /* n = 8 */
  prod_n *= xi - x[i-r+9];  /* n = 9 */
  sum_m += prod_n;

  /* m = 6 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  prod_n *= xi - x[i-r+4];  /* n = 4 */
  prod_n *= xi - x[i-r+7];  /* n = 7 */
  prod_n *= xi - x[i-r+8];  /* n = 8 */
  prod_n *= xi - x[i-r+9];  /* n = 9 */
  sum_m += prod_n;

  /* m = 7 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  prod_n *= xi - x[i-r+4];  /* n = 4 */
  prod_n *= xi - x[i-r+6];  /* n = 6 */
  prod_n *= xi - x[i-r+8];  /* n = 8 */
  prod_n *= xi - x[i-r+9];  /* n = 9 */
  sum_m += prod_n;

  /* m = 8 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  prod_n *= xi - x[i-r+4];  /* n = 4 */
  prod_n *= xi - x[i-r+6];  /* n = 6 */
  prod_n *= xi - x[i-r+7];  /* n = 7 */
  prod_n *= xi - x[i-r+9];  /* n = 9 */
  sum_m += prod_n;

  /* m = 9 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  prod_n *= xi - x[i-r+4];  /* n = 4 */
  prod_n *= xi - x[i-r+6];  /* n = 6 */
  prod_n *= xi - x[i-r+7];  /* n = 7 */
  prod_n *= xi - x[i-r+8];  /* n = 8 */
  sum_m += prod_n;

  prod_m = 1.0;
  prod_m *= x[i-r+5] - x[i-r+0];
  prod_m *= x[i-r+5] - x[i-r+1];
  prod_m *= x[i-r+5] - x[i-r+2];
  prod_m *= x[i-r+5] - x[i-r+3];
  prod_m *= x[i-r+5] - x[i-r+4];
  prod_m *= x[i-r+5] - x[i-r+6];
  prod_m *= x[i-r+5] - x[i-r+7];
  prod_m *= x[i-r+5] - x[i-r+8];
  prod_m *= x[i-r+5] - x[i-r+9];

  sum_l += sum_m / prod_m * (x[i-r+3+1] - x[i-r+3]);

  /* l = 6 */
  sum_m = 0.0;

  /* m = 0 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  prod_n *= xi - x[i-r+4];  /* n = 4 */
  prod_n *= xi - x[i-r+5];  /* n = 5 */
  prod_n *= xi - x[i-r+7];  /* n = 7 */
  prod_n *= xi - x[i-r+8];  /* n = 8 */
  prod_n *= xi - x[i-r+9];  /* n = 9 */
  sum_m += prod_n;

  /* m = 1 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  prod_n *= xi - x[i-r+4];  /* n = 4 */
  prod_n *= xi - x[i-r+5];  /* n = 5 */
  prod_n *= xi - x[i-r+7];  /* n = 7 */
  prod_n *= xi - x[i-r+8];  /* n = 8 */
  prod_n *= xi - x[i-r+9];  /* n = 9 */
  sum_m += prod_n;

  /* m = 2 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  prod_n *= xi - x[i-r+4];  /* n = 4 */
  prod_n *= xi - x[i-r+5];  /* n = 5 */
  prod_n *= xi - x[i-r+7];  /* n = 7 */
  prod_n *= xi - x[i-r+8];  /* n = 8 */
  prod_n *= xi - x[i-r+9];  /* n = 9 */
  sum_m += prod_n;

  /* m = 3 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+4];  /* n = 4 */
  prod_n *= xi - x[i-r+5];  /* n = 5 */
  prod_n *= xi - x[i-r+7];  /* n = 7 */
  prod_n *= xi - x[i-r+8];  /* n = 8 */
  prod_n *= xi - x[i-r+9];  /* n = 9 */
  sum_m += prod_n;

  /* m = 4 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  prod_n *= xi - x[i-r+5];  /* n = 5 */
  prod_n *= xi - x[i-r+7];  /* n = 7 */
  prod_n *= xi - x[i-r+8];  /* n = 8 */
  prod_n *= xi - x[i-r+9];  /* n = 9 */
  sum_m += prod_n;

  /* m = 5 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  prod_n *= xi - x[i-r+4];  /* n = 4 */
  prod_n *= xi - x[i-r+7];  /* n = 7 */
  prod_n *= xi - x[i-r+8];  /* n = 8 */
  prod_n *= xi - x[i-r+9];  /* n = 9 */
  sum_m += prod_n;

  /* m = 7 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  prod_n *= xi - x[i-r+4];  /* n = 4 */
  prod_n *= xi - x[i-r+5];  /* n = 5 */
  prod_n *= xi - x[i-r+8];  /* n = 8 */
  prod_n *= xi - x[i-r+9];  /* n = 9 */
  sum_m += prod_n;

  /* m = 8 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  prod_n *= xi - x[i-r+4];  /* n = 4 */
  prod_n *= xi - x[i-r+5];  /* n = 5 */
  prod_n *= xi - x[i-r+7];  /* n = 7 */
  prod_n *= xi - x[i-r+9];  /* n = 9 */
  sum_m += prod_n;

  /* m = 9 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  prod_n *= xi - x[i-r+4];  /* n = 4 */
  prod_n *= xi - x[i-r+5];  /* n = 5 */
  prod_n *= xi - x[i-r+7];  /* n = 7 */
  prod_n *= xi - x[i-r+8];  /* n = 8 */
  sum_m += prod_n;

  prod_m = 1.0;
  prod_m *= x[i-r+6] - x[i-r+0];
  prod_m *= x[i-r+6] - x[i-r+1];
  prod_m *= x[i-r+6] - x[i-r+2];
  prod_m *= x[i-r+6] - x[i-r+3];
  prod_m *= x[i-r+6] - x[i-r+4];
  prod_m *= x[i-r+6] - x[i-r+5];
  prod_m *= x[i-r+6] - x[i-r+7];
  prod_m *= x[i-r+6] - x[i-r+8];
  prod_m *= x[i-r+6] - x[i-r+9];

  sum_l += sum_m / prod_m * (x[i-r+3+1] - x[i-r+3]);

  /* l = 7 */
  sum_m = 0.0;

  /* m = 0 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  prod_n *= xi - x[i-r+4];  /* n = 4 */
  prod_n *= xi - x[i-r+5];  /* n = 5 */
  prod_n *= xi - x[i-r+6];  /* n = 6 */
  prod_n *= xi - x[i-r+8];  /* n = 8 */
  prod_n *= xi - x[i-r+9];  /* n = 9 */
  sum_m += prod_n;

  /* m = 1 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  prod_n *= xi - x[i-r+4];  /* n = 4 */
  prod_n *= xi - x[i-r+5];  /* n = 5 */
  prod_n *= xi - x[i-r+6];  /* n = 6 */
  prod_n *= xi - x[i-r+8];  /* n = 8 */
  prod_n *= xi - x[i-r+9];  /* n = 9 */
  sum_m += prod_n;

  /* m = 2 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  prod_n *= xi - x[i-r+4];  /* n = 4 */
  prod_n *= xi - x[i-r+5];  /* n = 5 */
  prod_n *= xi - x[i-r+6];  /* n = 6 */
  prod_n *= xi - x[i-r+8];  /* n = 8 */
  prod_n *= xi - x[i-r+9];  /* n = 9 */
  sum_m += prod_n;

  /* m = 3 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+4];  /* n = 4 */
  prod_n *= xi - x[i-r+5];  /* n = 5 */
  prod_n *= xi - x[i-r+6];  /* n = 6 */
  prod_n *= xi - x[i-r+8];  /* n = 8 */
  prod_n *= xi - x[i-r+9];  /* n = 9 */
  sum_m += prod_n;

  /* m = 4 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  prod_n *= xi - x[i-r+5];  /* n = 5 */
  prod_n *= xi - x[i-r+6];  /* n = 6 */
  prod_n *= xi - x[i-r+8];  /* n = 8 */
  prod_n *= xi - x[i-r+9];  /* n = 9 */
  sum_m += prod_n;

  /* m = 5 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  prod_n *= xi - x[i-r+4];  /* n = 4 */
  prod_n *= xi - x[i-r+6];  /* n = 6 */
  prod_n *= xi - x[i-r+8];  /* n = 8 */
  prod_n *= xi - x[i-r+9];  /* n = 9 */
  sum_m += prod_n;

  /* m = 6 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  prod_n *= xi - x[i-r+4];  /* n = 4 */
  prod_n *= xi - x[i-r+5];  /* n = 5 */
  prod_n *= xi - x[i-r+8];  /* n = 8 */
  prod_n *= xi - x[i-r+9];  /* n = 9 */
  sum_m += prod_n;

  /* m = 8 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  prod_n *= xi - x[i-r+4];  /* n = 4 */
  prod_n *= xi - x[i-r+5];  /* n = 5 */
  prod_n *= xi - x[i-r+6];  /* n = 6 */
  prod_n *= xi - x[i-r+9];  /* n = 9 */
  sum_m += prod_n;

  /* m = 9 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  prod_n *= xi - x[i-r+4];  /* n = 4 */
  prod_n *= xi - x[i-r+5];  /* n = 5 */
  prod_n *= xi - x[i-r+6];  /* n = 6 */
  prod_n *= xi - x[i-r+8];  /* n = 8 */
  sum_m += prod_n;

  prod_m = 1.0;
  prod_m *= x[i-r+7] - x[i-r+0];
  prod_m *= x[i-r+7] - x[i-r+1];
  prod_m *= x[i-r+7] - x[i-r+2];
  prod_m *= x[i-r+7] - x[i-r+3];
  prod_m *= x[i-r+7] - x[i-r+4];
  prod_m *= x[i-r+7] - x[i-r+5];
  prod_m *= x[i-r+7] - x[i-r+6];
  prod_m *= x[i-r+7] - x[i-r+8];
  prod_m *= x[i-r+7] - x[i-r+9];

  sum_l += sum_m / prod_m * (x[i-r+3+1] - x[i-r+3]);

  /* l = 8 */
  sum_m = 0.0;

  /* m = 0 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  prod_n *= xi - x[i-r+4];  /* n = 4 */
  prod_n *= xi - x[i-r+5];  /* n = 5 */
  prod_n *= xi - x[i-r+6];  /* n = 6 */
  prod_n *= xi - x[i-r+7];  /* n = 7 */
  prod_n *= xi - x[i-r+9];  /* n = 9 */
  sum_m += prod_n;

  /* m = 1 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  prod_n *= xi - x[i-r+4];  /* n = 4 */
  prod_n *= xi - x[i-r+5];  /* n = 5 */
  prod_n *= xi - x[i-r+6];  /* n = 6 */
  prod_n *= xi - x[i-r+7];  /* n = 7 */
  prod_n *= xi - x[i-r+9];  /* n = 9 */
  sum_m += prod_n;

  /* m = 2 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  prod_n *= xi - x[i-r+4];  /* n = 4 */
  prod_n *= xi - x[i-r+5];  /* n = 5 */
  prod_n *= xi - x[i-r+6];  /* n = 6 */
  prod_n *= xi - x[i-r+7];  /* n = 7 */
  prod_n *= xi - x[i-r+9];  /* n = 9 */
  sum_m += prod_n;

  /* m = 3 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+4];  /* n = 4 */
  prod_n *= xi - x[i-r+5];  /* n = 5 */
  prod_n *= xi - x[i-r+6];  /* n = 6 */
  prod_n *= xi - x[i-r+7];  /* n = 7 */
  prod_n *= xi - x[i-r+9];  /* n = 9 */
  sum_m += prod_n;

  /* m = 4 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  prod_n *= xi - x[i-r+5];  /* n = 5 */
  prod_n *= xi - x[i-r+6];  /* n = 6 */
  prod_n *= xi - x[i-r+7];  /* n = 7 */
  prod_n *= xi - x[i-r+9];  /* n = 9 */
  sum_m += prod_n;

  /* m = 5 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  prod_n *= xi - x[i-r+4];  /* n = 4 */
  prod_n *= xi - x[i-r+6];  /* n = 6 */
  prod_n *= xi - x[i-r+7];  /* n = 7 */
  prod_n *= xi - x[i-r+9];  /* n = 9 */
  sum_m += prod_n;

  /* m = 6 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  prod_n *= xi - x[i-r+4];  /* n = 4 */
  prod_n *= xi - x[i-r+5];  /* n = 5 */
  prod_n *= xi - x[i-r+7];  /* n = 7 */
  prod_n *= xi - x[i-r+9];  /* n = 9 */
  sum_m += prod_n;

  /* m = 7 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  prod_n *= xi - x[i-r+4];  /* n = 4 */
  prod_n *= xi - x[i-r+5];  /* n = 5 */
  prod_n *= xi - x[i-r+6];  /* n = 6 */
  prod_n *= xi - x[i-r+9];  /* n = 9 */
  sum_m += prod_n;

  /* m = 9 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  prod_n *= xi - x[i-r+4];  /* n = 4 */
  prod_n *= xi - x[i-r+5];  /* n = 5 */
  prod_n *= xi - x[i-r+6];  /* n = 6 */
  prod_n *= xi - x[i-r+7];  /* n = 7 */
  sum_m += prod_n;

  prod_m = 1.0;
  prod_m *= x[i-r+8] - x[i-r+0];
  prod_m *= x[i-r+8] - x[i-r+1];
  prod_m *= x[i-r+8] - x[i-r+2];
  prod_m *= x[i-r+8] - x[i-r+3];
  prod_m *= x[i-r+8] - x[i-r+4];
  prod_m *= x[i-r+8] - x[i-r+5];
  prod_m *= x[i-r+8] - x[i-r+6];
  prod_m *= x[i-r+8] - x[i-r+7];
  prod_m *= x[i-r+8] - x[i-r+9];

  sum_l += sum_m / prod_m * (x[i-r+3+1] - x[i-r+3]);

  /* l = 9 */
  sum_m = 0.0;

  /* m = 0 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  prod_n *= xi - x[i-r+4];  /* n = 4 */
  prod_n *= xi - x[i-r+5];  /* n = 5 */
  prod_n *= xi - x[i-r+6];  /* n = 6 */
  prod_n *= xi - x[i-r+7];  /* n = 7 */
  prod_n *= xi - x[i-r+8];  /* n = 8 */
  sum_m += prod_n;

  /* m = 1 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  prod_n *= xi - x[i-r+4];  /* n = 4 */
  prod_n *= xi - x[i-r+5];  /* n = 5 */
  prod_n *= xi - x[i-r+6];  /* n = 6 */
  prod_n *= xi - x[i-r+7];  /* n = 7 */
  prod_n *= xi - x[i-r+8];  /* n = 8 */
  sum_m += prod_n;

  /* m = 2 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  prod_n *= xi - x[i-r+4];  /* n = 4 */
  prod_n *= xi - x[i-r+5];  /* n = 5 */
  prod_n *= xi - x[i-r+6];  /* n = 6 */
  prod_n *= xi - x[i-r+7];  /* n = 7 */
  prod_n *= xi - x[i-r+8];  /* n = 8 */
  sum_m += prod_n;

  /* m = 3 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+4];  /* n = 4 */
  prod_n *= xi - x[i-r+5];  /* n = 5 */
  prod_n *= xi - x[i-r+6];  /* n = 6 */
  prod_n *= xi - x[i-r+7];  /* n = 7 */
  prod_n *= xi - x[i-r+8];  /* n = 8 */
  sum_m += prod_n;

  /* m = 4 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  prod_n *= xi - x[i-r+5];  /* n = 5 */
  prod_n *= xi - x[i-r+6];  /* n = 6 */
  prod_n *= xi - x[i-r+7];  /* n = 7 */
  prod_n *= xi - x[i-r+8];  /* n = 8 */
  sum_m += prod_n;

  /* m = 5 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  prod_n *= xi - x[i-r+4];  /* n = 4 */
  prod_n *= xi - x[i-r+6];  /* n = 6 */
  prod_n *= xi - x[i-r+7];  /* n = 7 */
  prod_n *= xi - x[i-r+8];  /* n = 8 */
  sum_m += prod_n;

  /* m = 6 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  prod_n *= xi - x[i-r+4];  /* n = 4 */
  prod_n *= xi - x[i-r+5];  /* n = 5 */
  prod_n *= xi - x[i-r+7];  /* n = 7 */
  prod_n *= xi - x[i-r+8];  /* n = 8 */
  sum_m += prod_n;

  /* m = 7 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  prod_n *= xi - x[i-r+4];  /* n = 4 */
  prod_n *= xi - x[i-r+5];  /* n = 5 */
  prod_n *= xi - x[i-r+6];  /* n = 6 */
  prod_n *= xi - x[i-r+8];  /* n = 8 */
  sum_m += prod_n;

  /* m = 8 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  prod_n *= xi - x[i-r+4];  /* n = 4 */
  prod_n *= xi - x[i-r+5];  /* n = 5 */
  prod_n *= xi - x[i-r+6];  /* n = 6 */
  prod_n *= xi - x[i-r+7];  /* n = 7 */
  sum_m += prod_n;

  prod_m = 1.0;
  prod_m *= x[i-r+9] - x[i-r+0];
  prod_m *= x[i-r+9] - x[i-r+1];
  prod_m *= x[i-r+9] - x[i-r+2];
  prod_m *= x[i-r+9] - x[i-r+3];
  prod_m *= x[i-r+9] - x[i-r+4];
  prod_m *= x[i-r+9] - x[i-r+5];
  prod_m *= x[i-r+9] - x[i-r+6];
  prod_m *= x[i-r+9] - x[i-r+7];
  prod_m *= x[i-r+9] - x[i-r+8];

  sum_l += sum_m / prod_m * (x[i-r+3+1] - x[i-r+3]);

  c[3] = sum_l;

  /* j = 4 */
  sum_l = 0.0;

  /* l = 5 */
  sum_m = 0.0;

  /* m = 0 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  prod_n *= xi - x[i-r+4];  /* n = 4 */
  prod_n *= xi - x[i-r+6];  /* n = 6 */
  prod_n *= xi - x[i-r+7];  /* n = 7 */
  prod_n *= xi - x[i-r+8];  /* n = 8 */
  prod_n *= xi - x[i-r+9];  /* n = 9 */
  sum_m += prod_n;

  /* m = 1 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  prod_n *= xi - x[i-r+4];  /* n = 4 */
  prod_n *= xi - x[i-r+6];  /* n = 6 */
  prod_n *= xi - x[i-r+7];  /* n = 7 */
  prod_n *= xi - x[i-r+8];  /* n = 8 */
  prod_n *= xi - x[i-r+9];  /* n = 9 */
  sum_m += prod_n;

  /* m = 2 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  prod_n *= xi - x[i-r+4];  /* n = 4 */
  prod_n *= xi - x[i-r+6];  /* n = 6 */
  prod_n *= xi - x[i-r+7];  /* n = 7 */
  prod_n *= xi - x[i-r+8];  /* n = 8 */
  prod_n *= xi - x[i-r+9];  /* n = 9 */
  sum_m += prod_n;

  /* m = 3 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+4];  /* n = 4 */
  prod_n *= xi - x[i-r+6];  /* n = 6 */
  prod_n *= xi - x[i-r+7];  /* n = 7 */
  prod_n *= xi - x[i-r+8];  /* n = 8 */
  prod_n *= xi - x[i-r+9];  /* n = 9 */
  sum_m += prod_n;

  /* m = 4 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  prod_n *= xi - x[i-r+6];  /* n = 6 */
  prod_n *= xi - x[i-r+7];  /* n = 7 */
  prod_n *= xi - x[i-r+8];  /* n = 8 */
  prod_n *= xi - x[i-r+9];  /* n = 9 */
  sum_m += prod_n;

  /* m = 6 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  prod_n *= xi - x[i-r+4];  /* n = 4 */
  prod_n *= xi - x[i-r+7];  /* n = 7 */
  prod_n *= xi - x[i-r+8];  /* n = 8 */
  prod_n *= xi - x[i-r+9];  /* n = 9 */
  sum_m += prod_n;

  /* m = 7 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  prod_n *= xi - x[i-r+4];  /* n = 4 */
  prod_n *= xi - x[i-r+6];  /* n = 6 */
  prod_n *= xi - x[i-r+8];  /* n = 8 */
  prod_n *= xi - x[i-r+9];  /* n = 9 */
  sum_m += prod_n;

  /* m = 8 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  prod_n *= xi - x[i-r+4];  /* n = 4 */
  prod_n *= xi - x[i-r+6];  /* n = 6 */
  prod_n *= xi - x[i-r+7];  /* n = 7 */
  prod_n *= xi - x[i-r+9];  /* n = 9 */
  sum_m += prod_n;

  /* m = 9 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  prod_n *= xi - x[i-r+4];  /* n = 4 */
  prod_n *= xi - x[i-r+6];  /* n = 6 */
  prod_n *= xi - x[i-r+7];  /* n = 7 */
  prod_n *= xi - x[i-r+8];  /* n = 8 */
  sum_m += prod_n;

  prod_m = 1.0;
  prod_m *= x[i-r+5] - x[i-r+0];
  prod_m *= x[i-r+5] - x[i-r+1];
  prod_m *= x[i-r+5] - x[i-r+2];
  prod_m *= x[i-r+5] - x[i-r+3];
  prod_m *= x[i-r+5] - x[i-r+4];
  prod_m *= x[i-r+5] - x[i-r+6];
  prod_m *= x[i-r+5] - x[i-r+7];
  prod_m *= x[i-r+5] - x[i-r+8];
  prod_m *= x[i-r+5] - x[i-r+9];

  sum_l += sum_m / prod_m * (x[i-r+4+1] - x[i-r+4]);

  /* l = 6 */
  sum_m = 0.0;

  /* m = 0 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  prod_n *= xi - x[i-r+4];  /* n = 4 */
  prod_n *= xi - x[i-r+5];  /* n = 5 */
  prod_n *= xi - x[i-r+7];  /* n = 7 */
  prod_n *= xi - x[i-r+8];  /* n = 8 */
  prod_n *= xi - x[i-r+9];  /* n = 9 */
  sum_m += prod_n;

  /* m = 1 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  prod_n *= xi - x[i-r+4];  /* n = 4 */
  prod_n *= xi - x[i-r+5];  /* n = 5 */
  prod_n *= xi - x[i-r+7];  /* n = 7 */
  prod_n *= xi - x[i-r+8];  /* n = 8 */
  prod_n *= xi - x[i-r+9];  /* n = 9 */
  sum_m += prod_n;

  /* m = 2 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  prod_n *= xi - x[i-r+4];  /* n = 4 */
  prod_n *= xi - x[i-r+5];  /* n = 5 */
  prod_n *= xi - x[i-r+7];  /* n = 7 */
  prod_n *= xi - x[i-r+8];  /* n = 8 */
  prod_n *= xi - x[i-r+9];  /* n = 9 */
  sum_m += prod_n;

  /* m = 3 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+4];  /* n = 4 */
  prod_n *= xi - x[i-r+5];  /* n = 5 */
  prod_n *= xi - x[i-r+7];  /* n = 7 */
  prod_n *= xi - x[i-r+8];  /* n = 8 */
  prod_n *= xi - x[i-r+9];  /* n = 9 */
  sum_m += prod_n;

  /* m = 4 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  prod_n *= xi - x[i-r+5];  /* n = 5 */
  prod_n *= xi - x[i-r+7];  /* n = 7 */
  prod_n *= xi - x[i-r+8];  /* n = 8 */
  prod_n *= xi - x[i-r+9];  /* n = 9 */
  sum_m += prod_n;

  /* m = 5 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  prod_n *= xi - x[i-r+4];  /* n = 4 */
  prod_n *= xi - x[i-r+7];  /* n = 7 */
  prod_n *= xi - x[i-r+8];  /* n = 8 */
  prod_n *= xi - x[i-r+9];  /* n = 9 */
  sum_m += prod_n;

  /* m = 7 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  prod_n *= xi - x[i-r+4];  /* n = 4 */
  prod_n *= xi - x[i-r+5];  /* n = 5 */
  prod_n *= xi - x[i-r+8];  /* n = 8 */
  prod_n *= xi - x[i-r+9];  /* n = 9 */
  sum_m += prod_n;

  /* m = 8 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  prod_n *= xi - x[i-r+4];  /* n = 4 */
  prod_n *= xi - x[i-r+5];  /* n = 5 */
  prod_n *= xi - x[i-r+7];  /* n = 7 */
  prod_n *= xi - x[i-r+9];  /* n = 9 */
  sum_m += prod_n;

  /* m = 9 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  prod_n *= xi - x[i-r+4];  /* n = 4 */
  prod_n *= xi - x[i-r+5];  /* n = 5 */
  prod_n *= xi - x[i-r+7];  /* n = 7 */
  prod_n *= xi - x[i-r+8];  /* n = 8 */
  sum_m += prod_n;

  prod_m = 1.0;
  prod_m *= x[i-r+6] - x[i-r+0];
  prod_m *= x[i-r+6] - x[i-r+1];
  prod_m *= x[i-r+6] - x[i-r+2];
  prod_m *= x[i-r+6] - x[i-r+3];
  prod_m *= x[i-r+6] - x[i-r+4];
  prod_m *= x[i-r+6] - x[i-r+5];
  prod_m *= x[i-r+6] - x[i-r+7];
  prod_m *= x[i-r+6] - x[i-r+8];
  prod_m *= x[i-r+6] - x[i-r+9];

  sum_l += sum_m / prod_m * (x[i-r+4+1] - x[i-r+4]);

  /* l = 7 */
  sum_m = 0.0;

  /* m = 0 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  prod_n *= xi - x[i-r+4];  /* n = 4 */
  prod_n *= xi - x[i-r+5];  /* n = 5 */
  prod_n *= xi - x[i-r+6];  /* n = 6 */
  prod_n *= xi - x[i-r+8];  /* n = 8 */
  prod_n *= xi - x[i-r+9];  /* n = 9 */
  sum_m += prod_n;

  /* m = 1 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  prod_n *= xi - x[i-r+4];  /* n = 4 */
  prod_n *= xi - x[i-r+5];  /* n = 5 */
  prod_n *= xi - x[i-r+6];  /* n = 6 */
  prod_n *= xi - x[i-r+8];  /* n = 8 */
  prod_n *= xi - x[i-r+9];  /* n = 9 */
  sum_m += prod_n;

  /* m = 2 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  prod_n *= xi - x[i-r+4];  /* n = 4 */
  prod_n *= xi - x[i-r+5];  /* n = 5 */
  prod_n *= xi - x[i-r+6];  /* n = 6 */
  prod_n *= xi - x[i-r+8];  /* n = 8 */
  prod_n *= xi - x[i-r+9];  /* n = 9 */
  sum_m += prod_n;

  /* m = 3 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+4];  /* n = 4 */
  prod_n *= xi - x[i-r+5];  /* n = 5 */
  prod_n *= xi - x[i-r+6];  /* n = 6 */
  prod_n *= xi - x[i-r+8];  /* n = 8 */
  prod_n *= xi - x[i-r+9];  /* n = 9 */
  sum_m += prod_n;

  /* m = 4 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  prod_n *= xi - x[i-r+5];  /* n = 5 */
  prod_n *= xi - x[i-r+6];  /* n = 6 */
  prod_n *= xi - x[i-r+8];  /* n = 8 */
  prod_n *= xi - x[i-r+9];  /* n = 9 */
  sum_m += prod_n;

  /* m = 5 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  prod_n *= xi - x[i-r+4];  /* n = 4 */
  prod_n *= xi - x[i-r+6];  /* n = 6 */
  prod_n *= xi - x[i-r+8];  /* n = 8 */
  prod_n *= xi - x[i-r+9];  /* n = 9 */
  sum_m += prod_n;

  /* m = 6 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  prod_n *= xi - x[i-r+4];  /* n = 4 */
  prod_n *= xi - x[i-r+5];  /* n = 5 */
  prod_n *= xi - x[i-r+8];  /* n = 8 */
  prod_n *= xi - x[i-r+9];  /* n = 9 */
  sum_m += prod_n;

  /* m = 8 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  prod_n *= xi - x[i-r+4];  /* n = 4 */
  prod_n *= xi - x[i-r+5];  /* n = 5 */
  prod_n *= xi - x[i-r+6];  /* n = 6 */
  prod_n *= xi - x[i-r+9];  /* n = 9 */
  sum_m += prod_n;

  /* m = 9 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  prod_n *= xi - x[i-r+4];  /* n = 4 */
  prod_n *= xi - x[i-r+5];  /* n = 5 */
  prod_n *= xi - x[i-r+6];  /* n = 6 */
  prod_n *= xi - x[i-r+8];  /* n = 8 */
  sum_m += prod_n;

  prod_m = 1.0;
  prod_m *= x[i-r+7] - x[i-r+0];
  prod_m *= x[i-r+7] - x[i-r+1];
  prod_m *= x[i-r+7] - x[i-r+2];
  prod_m *= x[i-r+7] - x[i-r+3];
  prod_m *= x[i-r+7] - x[i-r+4];
  prod_m *= x[i-r+7] - x[i-r+5];
  prod_m *= x[i-r+7] - x[i-r+6];
  prod_m *= x[i-r+7] - x[i-r+8];
  prod_m *= x[i-r+7] - x[i-r+9];

  sum_l += sum_m / prod_m * (x[i-r+4+1] - x[i-r+4]);

  /* l = 8 */
  sum_m = 0.0;

  /* m = 0 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  prod_n *= xi - x[i-r+4];  /* n = 4 */
  prod_n *= xi - x[i-r+5];  /* n = 5 */
  prod_n *= xi - x[i-r+6];  /* n = 6 */
  prod_n *= xi - x[i-r+7];  /* n = 7 */
  prod_n *= xi - x[i-r+9];  /* n = 9 */
  sum_m += prod_n;

  /* m = 1 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  prod_n *= xi - x[i-r+4];  /* n = 4 */
  prod_n *= xi - x[i-r+5];  /* n = 5 */
  prod_n *= xi - x[i-r+6];  /* n = 6 */
  prod_n *= xi - x[i-r+7];  /* n = 7 */
  prod_n *= xi - x[i-r+9];  /* n = 9 */
  sum_m += prod_n;

  /* m = 2 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  prod_n *= xi - x[i-r+4];  /* n = 4 */
  prod_n *= xi - x[i-r+5];  /* n = 5 */
  prod_n *= xi - x[i-r+6];  /* n = 6 */
  prod_n *= xi - x[i-r+7];  /* n = 7 */
  prod_n *= xi - x[i-r+9];  /* n = 9 */
  sum_m += prod_n;

  /* m = 3 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+4];  /* n = 4 */
  prod_n *= xi - x[i-r+5];  /* n = 5 */
  prod_n *= xi - x[i-r+6];  /* n = 6 */
  prod_n *= xi - x[i-r+7];  /* n = 7 */
  prod_n *= xi - x[i-r+9];  /* n = 9 */
  sum_m += prod_n;

  /* m = 4 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  prod_n *= xi - x[i-r+5];  /* n = 5 */
  prod_n *= xi - x[i-r+6];  /* n = 6 */
  prod_n *= xi - x[i-r+7];  /* n = 7 */
  prod_n *= xi - x[i-r+9];  /* n = 9 */
  sum_m += prod_n;

  /* m = 5 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  prod_n *= xi - x[i-r+4];  /* n = 4 */
  prod_n *= xi - x[i-r+6];  /* n = 6 */
  prod_n *= xi - x[i-r+7];  /* n = 7 */
  prod_n *= xi - x[i-r+9];  /* n = 9 */
  sum_m += prod_n;

  /* m = 6 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  prod_n *= xi - x[i-r+4];  /* n = 4 */
  prod_n *= xi - x[i-r+5];  /* n = 5 */
  prod_n *= xi - x[i-r+7];  /* n = 7 */
  prod_n *= xi - x[i-r+9];  /* n = 9 */
  sum_m += prod_n;

  /* m = 7 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  prod_n *= xi - x[i-r+4];  /* n = 4 */
  prod_n *= xi - x[i-r+5];  /* n = 5 */
  prod_n *= xi - x[i-r+6];  /* n = 6 */
  prod_n *= xi - x[i-r+9];  /* n = 9 */
  sum_m += prod_n;

  /* m = 9 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  prod_n *= xi - x[i-r+4];  /* n = 4 */
  prod_n *= xi - x[i-r+5];  /* n = 5 */
  prod_n *= xi - x[i-r+6];  /* n = 6 */
  prod_n *= xi - x[i-r+7];  /* n = 7 */
  sum_m += prod_n;

  prod_m = 1.0;
  prod_m *= x[i-r+8] - x[i-r+0];
  prod_m *= x[i-r+8] - x[i-r+1];
  prod_m *= x[i-r+8] - x[i-r+2];
  prod_m *= x[i-r+8] - x[i-r+3];
  prod_m *= x[i-r+8] - x[i-r+4];
  prod_m *= x[i-r+8] - x[i-r+5];
  prod_m *= x[i-r+8] - x[i-r+6];
  prod_m *= x[i-r+8] - x[i-r+7];
  prod_m *= x[i-r+8] - x[i-r+9];

  sum_l += sum_m / prod_m * (x[i-r+4+1] - x[i-r+4]);

  /* l = 9 */
  sum_m = 0.0;

  /* m = 0 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  prod_n *= xi - x[i-r+4];  /* n = 4 */
  prod_n *= xi - x[i-r+5];  /* n = 5 */
  prod_n *= xi - x[i-r+6];  /* n = 6 */
  prod_n *= xi - x[i-r+7];  /* n = 7 */
  prod_n *= xi - x[i-r+8];  /* n = 8 */
  sum_m += prod_n;

  /* m = 1 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  prod_n *= xi - x[i-r+4];  /* n = 4 */
  prod_n *= xi - x[i-r+5];  /* n = 5 */
  prod_n *= xi - x[i-r+6];  /* n = 6 */
  prod_n *= xi - x[i-r+7];  /* n = 7 */
  prod_n *= xi - x[i-r+8];  /* n = 8 */
  sum_m += prod_n;

  /* m = 2 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  prod_n *= xi - x[i-r+4];  /* n = 4 */
  prod_n *= xi - x[i-r+5];  /* n = 5 */
  prod_n *= xi - x[i-r+6];  /* n = 6 */
  prod_n *= xi - x[i-r+7];  /* n = 7 */
  prod_n *= xi - x[i-r+8];  /* n = 8 */
  sum_m += prod_n;

  /* m = 3 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+4];  /* n = 4 */
  prod_n *= xi - x[i-r+5];  /* n = 5 */
  prod_n *= xi - x[i-r+6];  /* n = 6 */
  prod_n *= xi - x[i-r+7];  /* n = 7 */
  prod_n *= xi - x[i-r+8];  /* n = 8 */
  sum_m += prod_n;

  /* m = 4 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  prod_n *= xi - x[i-r+5];  /* n = 5 */
  prod_n *= xi - x[i-r+6];  /* n = 6 */
  prod_n *= xi - x[i-r+7];  /* n = 7 */
  prod_n *= xi - x[i-r+8];  /* n = 8 */
  sum_m += prod_n;

  /* m = 5 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  prod_n *= xi - x[i-r+4];  /* n = 4 */
  prod_n *= xi - x[i-r+6];  /* n = 6 */
  prod_n *= xi - x[i-r+7];  /* n = 7 */
  prod_n *= xi - x[i-r+8];  /* n = 8 */
  sum_m += prod_n;

  /* m = 6 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  prod_n *= xi - x[i-r+4];  /* n = 4 */
  prod_n *= xi - x[i-r+5];  /* n = 5 */
  prod_n *= xi - x[i-r+7];  /* n = 7 */
  prod_n *= xi - x[i-r+8];  /* n = 8 */
  sum_m += prod_n;

  /* m = 7 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  prod_n *= xi - x[i-r+4];  /* n = 4 */
  prod_n *= xi - x[i-r+5];  /* n = 5 */
  prod_n *= xi - x[i-r+6];  /* n = 6 */
  prod_n *= xi - x[i-r+8];  /* n = 8 */
  sum_m += prod_n;

  /* m = 8 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  prod_n *= xi - x[i-r+4];  /* n = 4 */
  prod_n *= xi - x[i-r+5];  /* n = 5 */
  prod_n *= xi - x[i-r+6];  /* n = 6 */
  prod_n *= xi - x[i-r+7];  /* n = 7 */
  sum_m += prod_n;

  prod_m = 1.0;
  prod_m *= x[i-r+9] - x[i-r+0];
  prod_m *= x[i-r+9] - x[i-r+1];
  prod_m *= x[i-r+9] - x[i-r+2];
  prod_m *= x[i-r+9] - x[i-r+3];
  prod_m *= x[i-r+9] - x[i-r+4];
  prod_m *= x[i-r+9] - x[i-r+5];
  prod_m *= x[i-r+9] - x[i-r+6];
  prod_m *= x[i-r+9] - x[i-r+7];
  prod_m *= x[i-r+9] - x[i-r+8];

  sum_l += sum_m / prod_m * (x[i-r+4+1] - x[i-r+4]);

  c[4] = sum_l;

  /* j = 5 */
  sum_l = 0.0;

  /* l = 6 */
  sum_m = 0.0;

  /* m = 0 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  prod_n *= xi - x[i-r+4];  /* n = 4 */
  prod_n *= xi - x[i-r+5];  /* n = 5 */
  prod_n *= xi - x[i-r+7];  /* n = 7 */
  prod_n *= xi - x[i-r+8];  /* n = 8 */
  prod_n *= xi - x[i-r+9];  /* n = 9 */
  sum_m += prod_n;

  /* m = 1 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  prod_n *= xi - x[i-r+4];  /* n = 4 */
  prod_n *= xi - x[i-r+5];  /* n = 5 */
  prod_n *= xi - x[i-r+7];  /* n = 7 */
  prod_n *= xi - x[i-r+8];  /* n = 8 */
  prod_n *= xi - x[i-r+9];  /* n = 9 */
  sum_m += prod_n;

  /* m = 2 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  prod_n *= xi - x[i-r+4];  /* n = 4 */
  prod_n *= xi - x[i-r+5];  /* n = 5 */
  prod_n *= xi - x[i-r+7];  /* n = 7 */
  prod_n *= xi - x[i-r+8];  /* n = 8 */
  prod_n *= xi - x[i-r+9];  /* n = 9 */
  sum_m += prod_n;

  /* m = 3 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+4];  /* n = 4 */
  prod_n *= xi - x[i-r+5];  /* n = 5 */
  prod_n *= xi - x[i-r+7];  /* n = 7 */
  prod_n *= xi - x[i-r+8];  /* n = 8 */
  prod_n *= xi - x[i-r+9];  /* n = 9 */
  sum_m += prod_n;

  /* m = 4 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  prod_n *= xi - x[i-r+5];  /* n = 5 */
  prod_n *= xi - x[i-r+7];  /* n = 7 */
  prod_n *= xi - x[i-r+8];  /* n = 8 */
  prod_n *= xi - x[i-r+9];  /* n = 9 */
  sum_m += prod_n;

  /* m = 5 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  prod_n *= xi - x[i-r+4];  /* n = 4 */
  prod_n *= xi - x[i-r+7];  /* n = 7 */
  prod_n *= xi - x[i-r+8];  /* n = 8 */
  prod_n *= xi - x[i-r+9];  /* n = 9 */
  sum_m += prod_n;

  /* m = 7 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  prod_n *= xi - x[i-r+4];  /* n = 4 */
  prod_n *= xi - x[i-r+5];  /* n = 5 */
  prod_n *= xi - x[i-r+8];  /* n = 8 */
  prod_n *= xi - x[i-r+9];  /* n = 9 */
  sum_m += prod_n;

  /* m = 8 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  prod_n *= xi - x[i-r+4];  /* n = 4 */
  prod_n *= xi - x[i-r+5];  /* n = 5 */
  prod_n *= xi - x[i-r+7];  /* n = 7 */
  prod_n *= xi - x[i-r+9];  /* n = 9 */
  sum_m += prod_n;

  /* m = 9 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  prod_n *= xi - x[i-r+4];  /* n = 4 */
  prod_n *= xi - x[i-r+5];  /* n = 5 */
  prod_n *= xi - x[i-r+7];  /* n = 7 */
  prod_n *= xi - x[i-r+8];  /* n = 8 */
  sum_m += prod_n;

  prod_m = 1.0;
  prod_m *= x[i-r+6] - x[i-r+0];
  prod_m *= x[i-r+6] - x[i-r+1];
  prod_m *= x[i-r+6] - x[i-r+2];
  prod_m *= x[i-r+6] - x[i-r+3];
  prod_m *= x[i-r+6] - x[i-r+4];
  prod_m *= x[i-r+6] - x[i-r+5];
  prod_m *= x[i-r+6] - x[i-r+7];
  prod_m *= x[i-r+6] - x[i-r+8];
  prod_m *= x[i-r+6] - x[i-r+9];

  sum_l += sum_m / prod_m * (x[i-r+5+1] - x[i-r+5]);

  /* l = 7 */
  sum_m = 0.0;

  /* m = 0 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  prod_n *= xi - x[i-r+4];  /* n = 4 */
  prod_n *= xi - x[i-r+5];  /* n = 5 */
  prod_n *= xi - x[i-r+6];  /* n = 6 */
  prod_n *= xi - x[i-r+8];  /* n = 8 */
  prod_n *= xi - x[i-r+9];  /* n = 9 */
  sum_m += prod_n;

  /* m = 1 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  prod_n *= xi - x[i-r+4];  /* n = 4 */
  prod_n *= xi - x[i-r+5];  /* n = 5 */
  prod_n *= xi - x[i-r+6];  /* n = 6 */
  prod_n *= xi - x[i-r+8];  /* n = 8 */
  prod_n *= xi - x[i-r+9];  /* n = 9 */
  sum_m += prod_n;

  /* m = 2 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  prod_n *= xi - x[i-r+4];  /* n = 4 */
  prod_n *= xi - x[i-r+5];  /* n = 5 */
  prod_n *= xi - x[i-r+6];  /* n = 6 */
  prod_n *= xi - x[i-r+8];  /* n = 8 */
  prod_n *= xi - x[i-r+9];  /* n = 9 */
  sum_m += prod_n;

  /* m = 3 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+4];  /* n = 4 */
  prod_n *= xi - x[i-r+5];  /* n = 5 */
  prod_n *= xi - x[i-r+6];  /* n = 6 */
  prod_n *= xi - x[i-r+8];  /* n = 8 */
  prod_n *= xi - x[i-r+9];  /* n = 9 */
  sum_m += prod_n;

  /* m = 4 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  prod_n *= xi - x[i-r+5];  /* n = 5 */
  prod_n *= xi - x[i-r+6];  /* n = 6 */
  prod_n *= xi - x[i-r+8];  /* n = 8 */
  prod_n *= xi - x[i-r+9];  /* n = 9 */
  sum_m += prod_n;

  /* m = 5 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  prod_n *= xi - x[i-r+4];  /* n = 4 */
  prod_n *= xi - x[i-r+6];  /* n = 6 */
  prod_n *= xi - x[i-r+8];  /* n = 8 */
  prod_n *= xi - x[i-r+9];  /* n = 9 */
  sum_m += prod_n;

  /* m = 6 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  prod_n *= xi - x[i-r+4];  /* n = 4 */
  prod_n *= xi - x[i-r+5];  /* n = 5 */
  prod_n *= xi - x[i-r+8];  /* n = 8 */
  prod_n *= xi - x[i-r+9];  /* n = 9 */
  sum_m += prod_n;

  /* m = 8 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  prod_n *= xi - x[i-r+4];  /* n = 4 */
  prod_n *= xi - x[i-r+5];  /* n = 5 */
  prod_n *= xi - x[i-r+6];  /* n = 6 */
  prod_n *= xi - x[i-r+9];  /* n = 9 */
  sum_m += prod_n;

  /* m = 9 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  prod_n *= xi - x[i-r+4];  /* n = 4 */
  prod_n *= xi - x[i-r+5];  /* n = 5 */
  prod_n *= xi - x[i-r+6];  /* n = 6 */
  prod_n *= xi - x[i-r+8];  /* n = 8 */
  sum_m += prod_n;

  prod_m = 1.0;
  prod_m *= x[i-r+7] - x[i-r+0];
  prod_m *= x[i-r+7] - x[i-r+1];
  prod_m *= x[i-r+7] - x[i-r+2];
  prod_m *= x[i-r+7] - x[i-r+3];
  prod_m *= x[i-r+7] - x[i-r+4];
  prod_m *= x[i-r+7] - x[i-r+5];
  prod_m *= x[i-r+7] - x[i-r+6];
  prod_m *= x[i-r+7] - x[i-r+8];
  prod_m *= x[i-r+7] - x[i-r+9];

  sum_l += sum_m / prod_m * (x[i-r+5+1] - x[i-r+5]);

  /* l = 8 */
  sum_m = 0.0;

  /* m = 0 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  prod_n *= xi - x[i-r+4];  /* n = 4 */
  prod_n *= xi - x[i-r+5];  /* n = 5 */
  prod_n *= xi - x[i-r+6];  /* n = 6 */
  prod_n *= xi - x[i-r+7];  /* n = 7 */
  prod_n *= xi - x[i-r+9];  /* n = 9 */
  sum_m += prod_n;

  /* m = 1 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  prod_n *= xi - x[i-r+4];  /* n = 4 */
  prod_n *= xi - x[i-r+5];  /* n = 5 */
  prod_n *= xi - x[i-r+6];  /* n = 6 */
  prod_n *= xi - x[i-r+7];  /* n = 7 */
  prod_n *= xi - x[i-r+9];  /* n = 9 */
  sum_m += prod_n;

  /* m = 2 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  prod_n *= xi - x[i-r+4];  /* n = 4 */
  prod_n *= xi - x[i-r+5];  /* n = 5 */
  prod_n *= xi - x[i-r+6];  /* n = 6 */
  prod_n *= xi - x[i-r+7];  /* n = 7 */
  prod_n *= xi - x[i-r+9];  /* n = 9 */
  sum_m += prod_n;

  /* m = 3 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+4];  /* n = 4 */
  prod_n *= xi - x[i-r+5];  /* n = 5 */
  prod_n *= xi - x[i-r+6];  /* n = 6 */
  prod_n *= xi - x[i-r+7];  /* n = 7 */
  prod_n *= xi - x[i-r+9];  /* n = 9 */
  sum_m += prod_n;

  /* m = 4 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  prod_n *= xi - x[i-r+5];  /* n = 5 */
  prod_n *= xi - x[i-r+6];  /* n = 6 */
  prod_n *= xi - x[i-r+7];  /* n = 7 */
  prod_n *= xi - x[i-r+9];  /* n = 9 */
  sum_m += prod_n;

  /* m = 5 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  prod_n *= xi - x[i-r+4];  /* n = 4 */
  prod_n *= xi - x[i-r+6];  /* n = 6 */
  prod_n *= xi - x[i-r+7];  /* n = 7 */
  prod_n *= xi - x[i-r+9];  /* n = 9 */
  sum_m += prod_n;

  /* m = 6 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  prod_n *= xi - x[i-r+4];  /* n = 4 */
  prod_n *= xi - x[i-r+5];  /* n = 5 */
  prod_n *= xi - x[i-r+7];  /* n = 7 */
  prod_n *= xi - x[i-r+9];  /* n = 9 */
  sum_m += prod_n;

  /* m = 7 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  prod_n *= xi - x[i-r+4];  /* n = 4 */
  prod_n *= xi - x[i-r+5];  /* n = 5 */
  prod_n *= xi - x[i-r+6];  /* n = 6 */
  prod_n *= xi - x[i-r+9];  /* n = 9 */
  sum_m += prod_n;

  /* m = 9 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  prod_n *= xi - x[i-r+4];  /* n = 4 */
  prod_n *= xi - x[i-r+5];  /* n = 5 */
  prod_n *= xi - x[i-r+6];  /* n = 6 */
  prod_n *= xi - x[i-r+7];  /* n = 7 */
  sum_m += prod_n;

  prod_m = 1.0;
  prod_m *= x[i-r+8] - x[i-r+0];
  prod_m *= x[i-r+8] - x[i-r+1];
  prod_m *= x[i-r+8] - x[i-r+2];
  prod_m *= x[i-r+8] - x[i-r+3];
  prod_m *= x[i-r+8] - x[i-r+4];
  prod_m *= x[i-r+8] - x[i-r+5];
  prod_m *= x[i-r+8] - x[i-r+6];
  prod_m *= x[i-r+8] - x[i-r+7];
  prod_m *= x[i-r+8] - x[i-r+9];

  sum_l += sum_m / prod_m * (x[i-r+5+1] - x[i-r+5]);

  /* l = 9 */
  sum_m = 0.0;

  /* m = 0 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  prod_n *= xi - x[i-r+4];  /* n = 4 */
  prod_n *= xi - x[i-r+5];  /* n = 5 */
  prod_n *= xi - x[i-r+6];  /* n = 6 */
  prod_n *= xi - x[i-r+7];  /* n = 7 */
  prod_n *= xi - x[i-r+8];  /* n = 8 */
  sum_m += prod_n;

  /* m = 1 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  prod_n *= xi - x[i-r+4];  /* n = 4 */
  prod_n *= xi - x[i-r+5];  /* n = 5 */
  prod_n *= xi - x[i-r+6];  /* n = 6 */
  prod_n *= xi - x[i-r+7];  /* n = 7 */
  prod_n *= xi - x[i-r+8];  /* n = 8 */
  sum_m += prod_n;

  /* m = 2 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  prod_n *= xi - x[i-r+4];  /* n = 4 */
  prod_n *= xi - x[i-r+5];  /* n = 5 */
  prod_n *= xi - x[i-r+6];  /* n = 6 */
  prod_n *= xi - x[i-r+7];  /* n = 7 */
  prod_n *= xi - x[i-r+8];  /* n = 8 */
  sum_m += prod_n;

  /* m = 3 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+4];  /* n = 4 */
  prod_n *= xi - x[i-r+5];  /* n = 5 */
  prod_n *= xi - x[i-r+6];  /* n = 6 */
  prod_n *= xi - x[i-r+7];  /* n = 7 */
  prod_n *= xi - x[i-r+8];  /* n = 8 */
  sum_m += prod_n;

  /* m = 4 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  prod_n *= xi - x[i-r+5];  /* n = 5 */
  prod_n *= xi - x[i-r+6];  /* n = 6 */
  prod_n *= xi - x[i-r+7];  /* n = 7 */
  prod_n *= xi - x[i-r+8];  /* n = 8 */
  sum_m += prod_n;

  /* m = 5 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  prod_n *= xi - x[i-r+4];  /* n = 4 */
  prod_n *= xi - x[i-r+6];  /* n = 6 */
  prod_n *= xi - x[i-r+7];  /* n = 7 */
  prod_n *= xi - x[i-r+8];  /* n = 8 */
  sum_m += prod_n;

  /* m = 6 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  prod_n *= xi - x[i-r+4];  /* n = 4 */
  prod_n *= xi - x[i-r+5];  /* n = 5 */
  prod_n *= xi - x[i-r+7];  /* n = 7 */
  prod_n *= xi - x[i-r+8];  /* n = 8 */
  sum_m += prod_n;

  /* m = 7 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  prod_n *= xi - x[i-r+4];  /* n = 4 */
  prod_n *= xi - x[i-r+5];  /* n = 5 */
  prod_n *= xi - x[i-r+6];  /* n = 6 */
  prod_n *= xi - x[i-r+8];  /* n = 8 */
  sum_m += prod_n;

  /* m = 8 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  prod_n *= xi - x[i-r+4];  /* n = 4 */
  prod_n *= xi - x[i-r+5];  /* n = 5 */
  prod_n *= xi - x[i-r+6];  /* n = 6 */
  prod_n *= xi - x[i-r+7];  /* n = 7 */
  sum_m += prod_n;

  prod_m = 1.0;
  prod_m *= x[i-r+9] - x[i-r+0];
  prod_m *= x[i-r+9] - x[i-r+1];
  prod_m *= x[i-r+9] - x[i-r+2];
  prod_m *= x[i-r+9] - x[i-r+3];
  prod_m *= x[i-r+9] - x[i-r+4];
  prod_m *= x[i-r+9] - x[i-r+5];
  prod_m *= x[i-r+9] - x[i-r+6];
  prod_m *= x[i-r+9] - x[i-r+7];
  prod_m *= x[i-r+9] - x[i-r+8];

  sum_l += sum_m / prod_m * (x[i-r+5+1] - x[i-r+5]);

  c[5] = sum_l;

  /* j = 6 */
  sum_l = 0.0;

  /* l = 7 */
  sum_m = 0.0;

  /* m = 0 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  prod_n *= xi - x[i-r+4];  /* n = 4 */
  prod_n *= xi - x[i-r+5];  /* n = 5 */
  prod_n *= xi - x[i-r+6];  /* n = 6 */
  prod_n *= xi - x[i-r+8];  /* n = 8 */
  prod_n *= xi - x[i-r+9];  /* n = 9 */
  sum_m += prod_n;

  /* m = 1 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  prod_n *= xi - x[i-r+4];  /* n = 4 */
  prod_n *= xi - x[i-r+5];  /* n = 5 */
  prod_n *= xi - x[i-r+6];  /* n = 6 */
  prod_n *= xi - x[i-r+8];  /* n = 8 */
  prod_n *= xi - x[i-r+9];  /* n = 9 */
  sum_m += prod_n;

  /* m = 2 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  prod_n *= xi - x[i-r+4];  /* n = 4 */
  prod_n *= xi - x[i-r+5];  /* n = 5 */
  prod_n *= xi - x[i-r+6];  /* n = 6 */
  prod_n *= xi - x[i-r+8];  /* n = 8 */
  prod_n *= xi - x[i-r+9];  /* n = 9 */
  sum_m += prod_n;

  /* m = 3 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+4];  /* n = 4 */
  prod_n *= xi - x[i-r+5];  /* n = 5 */
  prod_n *= xi - x[i-r+6];  /* n = 6 */
  prod_n *= xi - x[i-r+8];  /* n = 8 */
  prod_n *= xi - x[i-r+9];  /* n = 9 */
  sum_m += prod_n;

  /* m = 4 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  prod_n *= xi - x[i-r+5];  /* n = 5 */
  prod_n *= xi - x[i-r+6];  /* n = 6 */
  prod_n *= xi - x[i-r+8];  /* n = 8 */
  prod_n *= xi - x[i-r+9];  /* n = 9 */
  sum_m += prod_n;

  /* m = 5 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  prod_n *= xi - x[i-r+4];  /* n = 4 */
  prod_n *= xi - x[i-r+6];  /* n = 6 */
  prod_n *= xi - x[i-r+8];  /* n = 8 */
  prod_n *= xi - x[i-r+9];  /* n = 9 */
  sum_m += prod_n;

  /* m = 6 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  prod_n *= xi - x[i-r+4];  /* n = 4 */
  prod_n *= xi - x[i-r+5];  /* n = 5 */
  prod_n *= xi - x[i-r+8];  /* n = 8 */
  prod_n *= xi - x[i-r+9];  /* n = 9 */
  sum_m += prod_n;

  /* m = 8 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  prod_n *= xi - x[i-r+4];  /* n = 4 */
  prod_n *= xi - x[i-r+5];  /* n = 5 */
  prod_n *= xi - x[i-r+6];  /* n = 6 */
  prod_n *= xi - x[i-r+9];  /* n = 9 */
  sum_m += prod_n;

  /* m = 9 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  prod_n *= xi - x[i-r+4];  /* n = 4 */
  prod_n *= xi - x[i-r+5];  /* n = 5 */
  prod_n *= xi - x[i-r+6];  /* n = 6 */
  prod_n *= xi - x[i-r+8];  /* n = 8 */
  sum_m += prod_n;

  prod_m = 1.0;
  prod_m *= x[i-r+7] - x[i-r+0];
  prod_m *= x[i-r+7] - x[i-r+1];
  prod_m *= x[i-r+7] - x[i-r+2];
  prod_m *= x[i-r+7] - x[i-r+3];
  prod_m *= x[i-r+7] - x[i-r+4];
  prod_m *= x[i-r+7] - x[i-r+5];
  prod_m *= x[i-r+7] - x[i-r+6];
  prod_m *= x[i-r+7] - x[i-r+8];
  prod_m *= x[i-r+7] - x[i-r+9];

  sum_l += sum_m / prod_m * (x[i-r+6+1] - x[i-r+6]);

  /* l = 8 */
  sum_m = 0.0;

  /* m = 0 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  prod_n *= xi - x[i-r+4];  /* n = 4 */
  prod_n *= xi - x[i-r+5];  /* n = 5 */
  prod_n *= xi - x[i-r+6];  /* n = 6 */
  prod_n *= xi - x[i-r+7];  /* n = 7 */
  prod_n *= xi - x[i-r+9];  /* n = 9 */
  sum_m += prod_n;

  /* m = 1 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  prod_n *= xi - x[i-r+4];  /* n = 4 */
  prod_n *= xi - x[i-r+5];  /* n = 5 */
  prod_n *= xi - x[i-r+6];  /* n = 6 */
  prod_n *= xi - x[i-r+7];  /* n = 7 */
  prod_n *= xi - x[i-r+9];  /* n = 9 */
  sum_m += prod_n;

  /* m = 2 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  prod_n *= xi - x[i-r+4];  /* n = 4 */
  prod_n *= xi - x[i-r+5];  /* n = 5 */
  prod_n *= xi - x[i-r+6];  /* n = 6 */
  prod_n *= xi - x[i-r+7];  /* n = 7 */
  prod_n *= xi - x[i-r+9];  /* n = 9 */
  sum_m += prod_n;

  /* m = 3 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+4];  /* n = 4 */
  prod_n *= xi - x[i-r+5];  /* n = 5 */
  prod_n *= xi - x[i-r+6];  /* n = 6 */
  prod_n *= xi - x[i-r+7];  /* n = 7 */
  prod_n *= xi - x[i-r+9];  /* n = 9 */
  sum_m += prod_n;

  /* m = 4 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  prod_n *= xi - x[i-r+5];  /* n = 5 */
  prod_n *= xi - x[i-r+6];  /* n = 6 */
  prod_n *= xi - x[i-r+7];  /* n = 7 */
  prod_n *= xi - x[i-r+9];  /* n = 9 */
  sum_m += prod_n;

  /* m = 5 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  prod_n *= xi - x[i-r+4];  /* n = 4 */
  prod_n *= xi - x[i-r+6];  /* n = 6 */
  prod_n *= xi - x[i-r+7];  /* n = 7 */
  prod_n *= xi - x[i-r+9];  /* n = 9 */
  sum_m += prod_n;

  /* m = 6 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  prod_n *= xi - x[i-r+4];  /* n = 4 */
  prod_n *= xi - x[i-r+5];  /* n = 5 */
  prod_n *= xi - x[i-r+7];  /* n = 7 */
  prod_n *= xi - x[i-r+9];  /* n = 9 */
  sum_m += prod_n;

  /* m = 7 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  prod_n *= xi - x[i-r+4];  /* n = 4 */
  prod_n *= xi - x[i-r+5];  /* n = 5 */
  prod_n *= xi - x[i-r+6];  /* n = 6 */
  prod_n *= xi - x[i-r+9];  /* n = 9 */
  sum_m += prod_n;

  /* m = 9 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  prod_n *= xi - x[i-r+4];  /* n = 4 */
  prod_n *= xi - x[i-r+5];  /* n = 5 */
  prod_n *= xi - x[i-r+6];  /* n = 6 */
  prod_n *= xi - x[i-r+7];  /* n = 7 */
  sum_m += prod_n;

  prod_m = 1.0;
  prod_m *= x[i-r+8] - x[i-r+0];
  prod_m *= x[i-r+8] - x[i-r+1];
  prod_m *= x[i-r+8] - x[i-r+2];
  prod_m *= x[i-r+8] - x[i-r+3];
  prod_m *= x[i-r+8] - x[i-r+4];
  prod_m *= x[i-r+8] - x[i-r+5];
  prod_m *= x[i-r+8] - x[i-r+6];
  prod_m *= x[i-r+8] - x[i-r+7];
  prod_m *= x[i-r+8] - x[i-r+9];

  sum_l += sum_m / prod_m * (x[i-r+6+1] - x[i-r+6]);

  /* l = 9 */
  sum_m = 0.0;

  /* m = 0 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  prod_n *= xi - x[i-r+4];  /* n = 4 */
  prod_n *= xi - x[i-r+5];  /* n = 5 */
  prod_n *= xi - x[i-r+6];  /* n = 6 */
  prod_n *= xi - x[i-r+7];  /* n = 7 */
  prod_n *= xi - x[i-r+8];  /* n = 8 */
  sum_m += prod_n;

  /* m = 1 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  prod_n *= xi - x[i-r+4];  /* n = 4 */
  prod_n *= xi - x[i-r+5];  /* n = 5 */
  prod_n *= xi - x[i-r+6];  /* n = 6 */
  prod_n *= xi - x[i-r+7];  /* n = 7 */
  prod_n *= xi - x[i-r+8];  /* n = 8 */
  sum_m += prod_n;

  /* m = 2 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  prod_n *= xi - x[i-r+4];  /* n = 4 */
  prod_n *= xi - x[i-r+5];  /* n = 5 */
  prod_n *= xi - x[i-r+6];  /* n = 6 */
  prod_n *= xi - x[i-r+7];  /* n = 7 */
  prod_n *= xi - x[i-r+8];  /* n = 8 */
  sum_m += prod_n;

  /* m = 3 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+4];  /* n = 4 */
  prod_n *= xi - x[i-r+5];  /* n = 5 */
  prod_n *= xi - x[i-r+6];  /* n = 6 */
  prod_n *= xi - x[i-r+7];  /* n = 7 */
  prod_n *= xi - x[i-r+8];  /* n = 8 */
  sum_m += prod_n;

  /* m = 4 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  prod_n *= xi - x[i-r+5];  /* n = 5 */
  prod_n *= xi - x[i-r+6];  /* n = 6 */
  prod_n *= xi - x[i-r+7];  /* n = 7 */
  prod_n *= xi - x[i-r+8];  /* n = 8 */
  sum_m += prod_n;

  /* m = 5 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  prod_n *= xi - x[i-r+4];  /* n = 4 */
  prod_n *= xi - x[i-r+6];  /* n = 6 */
  prod_n *= xi - x[i-r+7];  /* n = 7 */
  prod_n *= xi - x[i-r+8];  /* n = 8 */
  sum_m += prod_n;

  /* m = 6 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  prod_n *= xi - x[i-r+4];  /* n = 4 */
  prod_n *= xi - x[i-r+5];  /* n = 5 */
  prod_n *= xi - x[i-r+7];  /* n = 7 */
  prod_n *= xi - x[i-r+8];  /* n = 8 */
  sum_m += prod_n;

  /* m = 7 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  prod_n *= xi - x[i-r+4];  /* n = 4 */
  prod_n *= xi - x[i-r+5];  /* n = 5 */
  prod_n *= xi - x[i-r+6];  /* n = 6 */
  prod_n *= xi - x[i-r+8];  /* n = 8 */
  sum_m += prod_n;

  /* m = 8 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  prod_n *= xi - x[i-r+4];  /* n = 4 */
  prod_n *= xi - x[i-r+5];  /* n = 5 */
  prod_n *= xi - x[i-r+6];  /* n = 6 */
  prod_n *= xi - x[i-r+7];  /* n = 7 */
  sum_m += prod_n;

  prod_m = 1.0;
  prod_m *= x[i-r+9] - x[i-r+0];
  prod_m *= x[i-r+9] - x[i-r+1];
  prod_m *= x[i-r+9] - x[i-r+2];
  prod_m *= x[i-r+9] - x[i-r+3];
  prod_m *= x[i-r+9] - x[i-r+4];
  prod_m *= x[i-r+9] - x[i-r+5];
  prod_m *= x[i-r+9] - x[i-r+6];
  prod_m *= x[i-r+9] - x[i-r+7];
  prod_m *= x[i-r+9] - x[i-r+8];

  sum_l += sum_m / prod_m * (x[i-r+6+1] - x[i-r+6]);

  c[6] = sum_l;

  /* j = 7 */
  sum_l = 0.0;

  /* l = 8 */
  sum_m = 0.0;

  /* m = 0 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  prod_n *= xi - x[i-r+4];  /* n = 4 */
  prod_n *= xi - x[i-r+5];  /* n = 5 */
  prod_n *= xi - x[i-r+6];  /* n = 6 */
  prod_n *= xi - x[i-r+7];  /* n = 7 */
  prod_n *= xi - x[i-r+9];  /* n = 9 */
  sum_m += prod_n;

  /* m = 1 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  prod_n *= xi - x[i-r+4];  /* n = 4 */
  prod_n *= xi - x[i-r+5];  /* n = 5 */
  prod_n *= xi - x[i-r+6];  /* n = 6 */
  prod_n *= xi - x[i-r+7];  /* n = 7 */
  prod_n *= xi - x[i-r+9];  /* n = 9 */
  sum_m += prod_n;

  /* m = 2 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  prod_n *= xi - x[i-r+4];  /* n = 4 */
  prod_n *= xi - x[i-r+5];  /* n = 5 */
  prod_n *= xi - x[i-r+6];  /* n = 6 */
  prod_n *= xi - x[i-r+7];  /* n = 7 */
  prod_n *= xi - x[i-r+9];  /* n = 9 */
  sum_m += prod_n;

  /* m = 3 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+4];  /* n = 4 */
  prod_n *= xi - x[i-r+5];  /* n = 5 */
  prod_n *= xi - x[i-r+6];  /* n = 6 */
  prod_n *= xi - x[i-r+7];  /* n = 7 */
  prod_n *= xi - x[i-r+9];  /* n = 9 */
  sum_m += prod_n;

  /* m = 4 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  prod_n *= xi - x[i-r+5];  /* n = 5 */
  prod_n *= xi - x[i-r+6];  /* n = 6 */
  prod_n *= xi - x[i-r+7];  /* n = 7 */
  prod_n *= xi - x[i-r+9];  /* n = 9 */
  sum_m += prod_n;

  /* m = 5 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  prod_n *= xi - x[i-r+4];  /* n = 4 */
  prod_n *= xi - x[i-r+6];  /* n = 6 */
  prod_n *= xi - x[i-r+7];  /* n = 7 */
  prod_n *= xi - x[i-r+9];  /* n = 9 */
  sum_m += prod_n;

  /* m = 6 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  prod_n *= xi - x[i-r+4];  /* n = 4 */
  prod_n *= xi - x[i-r+5];  /* n = 5 */
  prod_n *= xi - x[i-r+7];  /* n = 7 */
  prod_n *= xi - x[i-r+9];  /* n = 9 */
  sum_m += prod_n;

  /* m = 7 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  prod_n *= xi - x[i-r+4];  /* n = 4 */
  prod_n *= xi - x[i-r+5];  /* n = 5 */
  prod_n *= xi - x[i-r+6];  /* n = 6 */
  prod_n *= xi - x[i-r+9];  /* n = 9 */
  sum_m += prod_n;

  /* m = 9 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  prod_n *= xi - x[i-r+4];  /* n = 4 */
  prod_n *= xi - x[i-r+5];  /* n = 5 */
  prod_n *= xi - x[i-r+6];  /* n = 6 */
  prod_n *= xi - x[i-r+7];  /* n = 7 */
  sum_m += prod_n;

  prod_m = 1.0;
  prod_m *= x[i-r+8] - x[i-r+0];
  prod_m *= x[i-r+8] - x[i-r+1];
  prod_m *= x[i-r+8] - x[i-r+2];
  prod_m *= x[i-r+8] - x[i-r+3];
  prod_m *= x[i-r+8] - x[i-r+4];
  prod_m *= x[i-r+8] - x[i-r+5];
  prod_m *= x[i-r+8] - x[i-r+6];
  prod_m *= x[i-r+8] - x[i-r+7];
  prod_m *= x[i-r+8] - x[i-r+9];

  sum_l += sum_m / prod_m * (x[i-r+7+1] - x[i-r+7]);

  /* l = 9 */
  sum_m = 0.0;

  /* m = 0 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  prod_n *= xi - x[i-r+4];  /* n = 4 */
  prod_n *= xi - x[i-r+5];  /* n = 5 */
  prod_n *= xi - x[i-r+6];  /* n = 6 */
  prod_n *= xi - x[i-r+7];  /* n = 7 */
  prod_n *= xi - x[i-r+8];  /* n = 8 */
  sum_m += prod_n;

  /* m = 1 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  prod_n *= xi - x[i-r+4];  /* n = 4 */
  prod_n *= xi - x[i-r+5];  /* n = 5 */
  prod_n *= xi - x[i-r+6];  /* n = 6 */
  prod_n *= xi - x[i-r+7];  /* n = 7 */
  prod_n *= xi - x[i-r+8];  /* n = 8 */
  sum_m += prod_n;

  /* m = 2 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  prod_n *= xi - x[i-r+4];  /* n = 4 */
  prod_n *= xi - x[i-r+5];  /* n = 5 */
  prod_n *= xi - x[i-r+6];  /* n = 6 */
  prod_n *= xi - x[i-r+7];  /* n = 7 */
  prod_n *= xi - x[i-r+8];  /* n = 8 */
  sum_m += prod_n;

  /* m = 3 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+4];  /* n = 4 */
  prod_n *= xi - x[i-r+5];  /* n = 5 */
  prod_n *= xi - x[i-r+6];  /* n = 6 */
  prod_n *= xi - x[i-r+7];  /* n = 7 */
  prod_n *= xi - x[i-r+8];  /* n = 8 */
  sum_m += prod_n;

  /* m = 4 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  prod_n *= xi - x[i-r+5];  /* n = 5 */
  prod_n *= xi - x[i-r+6];  /* n = 6 */
  prod_n *= xi - x[i-r+7];  /* n = 7 */
  prod_n *= xi - x[i-r+8];  /* n = 8 */
  sum_m += prod_n;

  /* m = 5 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  prod_n *= xi - x[i-r+4];  /* n = 4 */
  prod_n *= xi - x[i-r+6];  /* n = 6 */
  prod_n *= xi - x[i-r+7];  /* n = 7 */
  prod_n *= xi - x[i-r+8];  /* n = 8 */
  sum_m += prod_n;

  /* m = 6 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  prod_n *= xi - x[i-r+4];  /* n = 4 */
  prod_n *= xi - x[i-r+5];  /* n = 5 */
  prod_n *= xi - x[i-r+7];  /* n = 7 */
  prod_n *= xi - x[i-r+8];  /* n = 8 */
  sum_m += prod_n;

  /* m = 7 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  prod_n *= xi - x[i-r+4];  /* n = 4 */
  prod_n *= xi - x[i-r+5];  /* n = 5 */
  prod_n *= xi - x[i-r+6];  /* n = 6 */
  prod_n *= xi - x[i-r+8];  /* n = 8 */
  sum_m += prod_n;

  /* m = 8 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  prod_n *= xi - x[i-r+4];  /* n = 4 */
  prod_n *= xi - x[i-r+5];  /* n = 5 */
  prod_n *= xi - x[i-r+6];  /* n = 6 */
  prod_n *= xi - x[i-r+7];  /* n = 7 */
  sum_m += prod_n;

  prod_m = 1.0;
  prod_m *= x[i-r+9] - x[i-r+0];
  prod_m *= x[i-r+9] - x[i-r+1];
  prod_m *= x[i-r+9] - x[i-r+2];
  prod_m *= x[i-r+9] - x[i-r+3];
  prod_m *= x[i-r+9] - x[i-r+4];
  prod_m *= x[i-r+9] - x[i-r+5];
  prod_m *= x[i-r+9] - x[i-r+6];
  prod_m *= x[i-r+9] - x[i-r+7];
  prod_m *= x[i-r+9] - x[i-r+8];

  sum_l += sum_m / prod_m * (x[i-r+7+1] - x[i-r+7]);

  c[7] = sum_l;

  /* j = 8 */
  sum_l = 0.0;

  /* l = 9 */
  sum_m = 0.0;

  /* m = 0 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  prod_n *= xi - x[i-r+4];  /* n = 4 */
  prod_n *= xi - x[i-r+5];  /* n = 5 */
  prod_n *= xi - x[i-r+6];  /* n = 6 */
  prod_n *= xi - x[i-r+7];  /* n = 7 */
  prod_n *= xi - x[i-r+8];  /* n = 8 */
  sum_m += prod_n;

  /* m = 1 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  prod_n *= xi - x[i-r+4];  /* n = 4 */
  prod_n *= xi - x[i-r+5];  /* n = 5 */
  prod_n *= xi - x[i-r+6];  /* n = 6 */
  prod_n *= xi - x[i-r+7];  /* n = 7 */
  prod_n *= xi - x[i-r+8];  /* n = 8 */
  sum_m += prod_n;

  /* m = 2 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  prod_n *= xi - x[i-r+4];  /* n = 4 */
  prod_n *= xi - x[i-r+5];  /* n = 5 */
  prod_n *= xi - x[i-r+6];  /* n = 6 */
  prod_n *= xi - x[i-r+7];  /* n = 7 */
  prod_n *= xi - x[i-r+8];  /* n = 8 */
  sum_m += prod_n;

  /* m = 3 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+4];  /* n = 4 */
  prod_n *= xi - x[i-r+5];  /* n = 5 */
  prod_n *= xi - x[i-r+6];  /* n = 6 */
  prod_n *= xi - x[i-r+7];  /* n = 7 */
  prod_n *= xi - x[i-r+8];  /* n = 8 */
  sum_m += prod_n;

  /* m = 4 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  prod_n *= xi - x[i-r+5];  /* n = 5 */
  prod_n *= xi - x[i-r+6];  /* n = 6 */
  prod_n *= xi - x[i-r+7];  /* n = 7 */
  prod_n *= xi - x[i-r+8];  /* n = 8 */
  sum_m += prod_n;

  /* m = 5 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  prod_n *= xi - x[i-r+4];  /* n = 4 */
  prod_n *= xi - x[i-r+6];  /* n = 6 */
  prod_n *= xi - x[i-r+7];  /* n = 7 */
  prod_n *= xi - x[i-r+8];  /* n = 8 */
  sum_m += prod_n;

  /* m = 6 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  prod_n *= xi - x[i-r+4];  /* n = 4 */
  prod_n *= xi - x[i-r+5];  /* n = 5 */
  prod_n *= xi - x[i-r+7];  /* n = 7 */
  prod_n *= xi - x[i-r+8];  /* n = 8 */
  sum_m += prod_n;

  /* m = 7 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  prod_n *= xi - x[i-r+4];  /* n = 4 */
  prod_n *= xi - x[i-r+5];  /* n = 5 */
  prod_n *= xi - x[i-r+6];  /* n = 6 */
  prod_n *= xi - x[i-r+8];  /* n = 8 */
  sum_m += prod_n;

  /* m = 8 */
  prod_n = 1.0;
  prod_n *= xi - x[i-r+0];  /* n = 0 */
  prod_n *= xi - x[i-r+1];  /* n = 1 */
  prod_n *= xi - x[i-r+2];  /* n = 2 */
  prod_n *= xi - x[i-r+3];  /* n = 3 */
  prod_n *= xi - x[i-r+4];  /* n = 4 */
  prod_n *= xi - x[i-r+5];  /* n = 5 */
  prod_n *= xi - x[i-r+6];  /* n = 6 */
  prod_n *= xi - x[i-r+7];  /* n = 7 */
  sum_m += prod_n;

  prod_m = 1.0;
  prod_m *= x[i-r+9] - x[i-r+0];
  prod_m *= x[i-r+9] - x[i-r+1];
  prod_m *= x[i-r+9] - x[i-r+2];
  prod_m *= x[i-r+9] - x[i-r+3];
  prod_m *= x[i-r+9] - x[i-r+4];
  prod_m *= x[i-r+9] - x[i-r+5];
  prod_m *= x[i-r+9] - x[i-r+6];
  prod_m *= x[i-r+9] - x[i-r+7];
  prod_m *= x[i-r+9] - x[i-r+8];

  sum_l += sum_m / prod_m * (x[i-r+8+1] - x[i-r+8]);

  c[8] = sum_l;
}

PyObject *
reconstruction_coeffs_k9_d0_py(PyObject *self, PyObject *args)
{
  double *x, *c, xi;
  long int i;
  int r;

  PyObject *bndry, *coeffs;

  /*
   * parse options
   */

  if (! PyArg_ParseTuple(args, "dlidOO", &xi, &i, &r, &bndry, &coeffs))
    return NULL;

  if ((PyArray_FLAGS(bndry) & NPY_IN_ARRAY) != NPY_IN_ARRAY) {
    PyErr_SetString(PyExc_TypeError, "bndry is not contiguous and/or aligned");
    return NULL;
  }
  Py_INCREF(bndry);
  x = (double *) PyArray_DATA(bndry);

  if ((PyArray_FLAGS(coeffs) & NPY_IN_ARRAY) != NPY_IN_ARRAY) {
    PyErr_SetString(PyExc_TypeError, "coeffs is not contiguous and/or aligned");
    return NULL;
  }
  Py_INCREF(coeffs);
  c = (double *) PyArray_DATA(coeffs);

  /*
   * dispatch
   */

  reconstruction_coeffs_k9_d0(xi, i, r, x, c);

  /*
   * done
   */
  Py_INCREF(Py_None);
  return Py_None;
}

PyObject *
reconstruction_coeffs_d0_py(PyObject *self, PyObject *args)
{
  double *x, *c, xi;
  long int i;
  int r, k;

  PyObject *bndry, *coeffs;

  /*
   * parse options
   */

  if (! PyArg_ParseTuple(args, "dliiOO", &xi, &i, &r, &k, &bndry, &coeffs))
    return NULL;

  if ((PyArray_FLAGS(bndry) & NPY_IN_ARRAY) != NPY_IN_ARRAY) {
    PyErr_SetString(PyExc_TypeError, "bndry is not contiguous and/or aligned");
    return NULL;
  }
  Py_INCREF(bndry);
  x = (double *) PyArray_DATA(bndry);

  if ((PyArray_FLAGS(coeffs) & NPY_IN_ARRAY) != NPY_IN_ARRAY) {
    PyErr_SetString(PyExc_TypeError, "coeffs is not contiguous and/or aligned");
    return NULL;
  }
  Py_INCREF(coeffs);
  c = (double *) PyArray_DATA(coeffs);

  /*
   * dispatch
   */

  switch (k) {

case 3:
  reconstruction_coeffs_k3_d0(xi, i, r, x, c);
  break;

case 4:
  reconstruction_coeffs_k4_d0(xi, i, r, x, c);
  break;

case 5:
  reconstruction_coeffs_k5_d0(xi, i, r, x, c);
  break;

case 6:
  reconstruction_coeffs_k6_d0(xi, i, r, x, c);
  break;

case 7:
  reconstruction_coeffs_k7_d0(xi, i, r, x, c);
  break;

case 8:
  reconstruction_coeffs_k8_d0(xi, i, r, x, c);
  break;

case 9:
  reconstruction_coeffs_k9_d0(xi, i, r, x, c);
  break;

  }

  /*
   * done
   */
  Py_INCREF(Py_None);
  return Py_None;
}

static PyMethodDef CStencilMethods[] = {
           {"reconstruction_coeffs", reconstruction_coeffs_d0_py, METH_VARARGS, "Compute the reconstruction coefficients to reconstruct at xi."},
      
  {"reconstruction_coeffs_k3_d0", reconstruction_coeffs_k3_d0_py, METH_VARARGS, "Compute the reconstruction coefficients for k=3 to reconstruct at xi."},
  {"reconstruction_coeffs_k4_d0", reconstruction_coeffs_k4_d0_py, METH_VARARGS, "Compute the reconstruction coefficients for k=4 to reconstruct at xi."},
  {"reconstruction_coeffs_k5_d0", reconstruction_coeffs_k5_d0_py, METH_VARARGS, "Compute the reconstruction coefficients for k=5 to reconstruct at xi."},
  {"reconstruction_coeffs_k6_d0", reconstruction_coeffs_k6_d0_py, METH_VARARGS, "Compute the reconstruction coefficients for k=6 to reconstruct at xi."},
  {"reconstruction_coeffs_k7_d0", reconstruction_coeffs_k7_d0_py, METH_VARARGS, "Compute the reconstruction coefficients for k=7 to reconstruct at xi."},
  {"reconstruction_coeffs_k8_d0", reconstruction_coeffs_k8_d0_py, METH_VARARGS, "Compute the reconstruction coefficients for k=8 to reconstruct at xi."},
  {"reconstruction_coeffs_k9_d0", reconstruction_coeffs_k9_d0_py, METH_VARARGS, "Compute the reconstruction coefficients for k=9 to reconstruct at xi."},
  {NULL, NULL, 0, NULL}
};
PyMODINIT_FUNC
initcstencil(void)
{
  (void) Py_InitModule("cstencil", CStencilMethods);
  import_array();
}

