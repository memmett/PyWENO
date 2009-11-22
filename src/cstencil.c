#define PY_ARRAY_UNIQUE_SYMBOL PYWENO_ARRAY_API

#include <stdio.h>

#include <Python.h>
#include <numpy/ndarrayobject.h>

void reconstruction_coeffs_k3_d0(double xi, long int i, int r, double *x, double *c);
void reconstruction_coeffs_k3_d1(double xi, long int i, int r, double *x, double *c);
void reconstruction_coeffs_k4_d0(double xi, long int i, int r, double *x, double *c);
void reconstruction_coeffs_k4_d1(double xi, long int i, int r, double *x, double *c);
void reconstruction_coeffs_k5_d0(double xi, long int i, int r, double *x, double *c);
void reconstruction_coeffs_k5_d1(double xi, long int i, int r, double *x, double *c);
void reconstruction_coeffs_k6_d0(double xi, long int i, int r, double *x, double *c);
void reconstruction_coeffs_k6_d1(double xi, long int i, int r, double *x, double *c);
void reconstruction_coeffs_k7_d0(double xi, long int i, int r, double *x, double *c);
void reconstruction_coeffs_k7_d1(double xi, long int i, int r, double *x, double *c);
void reconstruction_coeffs_k8_d0(double xi, long int i, int r, double *x, double *c);
void reconstruction_coeffs_k8_d1(double xi, long int i, int r, double *x, double *c);
void reconstruction_coeffs_k9_d0(double xi, long int i, int r, double *x, double *c);
void reconstruction_coeffs_k9_d1(double xi, long int i, int r, double *x, double *c);


PyObject *
reconstruction_coeffs_py(PyObject *self, PyObject *args)
{
  double *x, *c, xi;
  long int i;
  int r, k, d=0;

  PyObject *bndry, *coeffs;

  /*
   * parse options
   */

  if (! PyArg_ParseTuple(args, "dliiiOO", &xi, &i, &r, &k, &d, &bndry, &coeffs))
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
  if (d==0)
    reconstruction_coeffs_k3_d0(xi, i, r, x, c);
  else if (d==1)
    reconstruction_coeffs_k3_d1(xi, i, r, x, c);
  break;
case 4:
  if (d==0)
    reconstruction_coeffs_k4_d0(xi, i, r, x, c);
  else if (d==1)
    reconstruction_coeffs_k4_d1(xi, i, r, x, c);
  break;
case 5:
  if (d==0)
    reconstruction_coeffs_k5_d0(xi, i, r, x, c);
  else if (d==1)
    reconstruction_coeffs_k5_d1(xi, i, r, x, c);
  break;
case 6:
  if (d==0)
    reconstruction_coeffs_k6_d0(xi, i, r, x, c);
  else if (d==1)
    reconstruction_coeffs_k6_d1(xi, i, r, x, c);
  break;
case 7:
  if (d==0)
    reconstruction_coeffs_k7_d0(xi, i, r, x, c);
  else if (d==1)
    reconstruction_coeffs_k7_d1(xi, i, r, x, c);
  break;
case 8:
  if (d==0)
    reconstruction_coeffs_k8_d0(xi, i, r, x, c);
  else if (d==1)
    reconstruction_coeffs_k8_d1(xi, i, r, x, c);
  break;
case 9:
  if (d==0)
    reconstruction_coeffs_k9_d0(xi, i, r, x, c);
  else if (d==1)
    reconstruction_coeffs_k9_d1(xi, i, r, x, c);
  break;
  }

  /*
   * done
   */
  Py_INCREF(Py_None);
  return Py_None;
}

static PyMethodDef CStencilMethods[] = {
  {"reconstruction_coeffs", reconstruction_coeffs_py, METH_VARARGS, "Compute the reconstruction coefficients to reconstruct at xi."},
  {NULL, NULL, 0, NULL}
};

PyMODINIT_FUNC
initcstencil(void)
{
  (void) Py_InitModule("cstencil", CStencilMethods);
  import_array();
}
