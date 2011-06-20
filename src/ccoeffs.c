#define PY_ARRAY_UNIQUE_SYMBOL PYWENO_ARRAY_API

#include <stdio.h>

#include <Python.h>
#include <numpy/ndarrayobject.h>

void coeffs003 (double xi, long int i, int r, double *x, double *c);
void coeffs004 (double xi, long int i, int r, double *x, double *c);
void coeffs005 (double xi, long int i, int r, double *x, double *c);
void coeffs006 (double xi, long int i, int r, double *x, double *c);
void coeffs007 (double xi, long int i, int r, double *x, double *c);
void coeffs008 (double xi, long int i, int r, double *x, double *c);
void coeffs009 (double xi, long int i, int r, double *x, double *c);

PyObject *
reconstruction_coeffs_py (PyObject * self, PyObject * args)
{
  double *x, *c, xi;
  long int i;
  int r, k;

  PyObject *bndry, *coeffs;

  /*
   * parse options
   */

  if (!PyArg_ParseTuple (args, "dliiOO", &xi, &i, &r, &k, &bndry, &coeffs))
    return NULL;

  if ((PyArray_FLAGS (bndry) & NPY_IN_ARRAY) != NPY_IN_ARRAY)
    {
      PyErr_SetString (PyExc_TypeError, "bndry is not contiguous and/or aligned");
      return NULL;
    }
  Py_INCREF (bndry);
  x = (double *) PyArray_DATA (bndry);

  if ((PyArray_FLAGS (coeffs) & NPY_IN_ARRAY) != NPY_IN_ARRAY)
    {
      PyErr_SetString (PyExc_TypeError, "coeffs is not contiguous and/or aligned");
      return NULL;
    }
  Py_INCREF (coeffs);
  c = (double *) PyArray_DATA (coeffs);

  /*
   * dispatch
   */

  switch (k)
    {
    case 3:
      coeffs003 (xi, i, r, x, c);
      break;
    case 4:
      coeffs004 (xi, i, r, x, c);
      break;
    case 5:
      coeffs005 (xi, i, r, x, c);
      break;
    case 6:
      coeffs006 (xi, i, r, x, c);
      break;
    case 7:
      coeffs007 (xi, i, r, x, c);
      break;
    case 8:
      coeffs008 (xi, i, r, x, c);
      break;
    case 9:
      coeffs009 (xi, i, r, x, c);
      break;
    default:
      return NULL;
    }

  /*
   * done
   */
  Py_INCREF (Py_None);
  return Py_None;
}

static PyMethodDef ccoeffsmethods[] = {
  {"reconstruction_coeffs", reconstruction_coeffs_py, METH_VARARGS,
   "Compute the reconstruction coefficients to reconstruct at xi."},
  {NULL, NULL, 0, NULL}
};

PyMODINIT_FUNC
initccoeffs (void)
{
  (void) Py_InitModule ("ccoeffs", ccoeffsmethods);
  import_array ();
}
