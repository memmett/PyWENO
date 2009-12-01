#define PY_ARRAY_UNIQUE_SYMBOL PYWENO_ARRAY_API

#include <stdio.h>

#include <Python.h>
#include <numpy/ndarrayobject.h>

/*
 * csmoothness - python extension module for (faster) smoothness
 *               indicators.
 */


/*
 * sigma - compute smoothness indicators s given cell averages f
 */
PyObject *
sigma(PyObject *self, PyObject *args)
{
  double *fm, *fn, *beta, *sigma;
  PyObject *f_py, *beta_py, *sigma_py;

  double sum;
  long int N, i;
  int k, r, m, n;

  /*
   * parse options
   */

  if (! PyArg_ParseTuple(args, "OOO", &f_py, &beta_py, &sigma_py))
    return NULL;

  if ((PyArray_FLAGS(beta_py) & NPY_IN_ARRAY) != NPY_IN_ARRAY) {
    PyErr_SetString(PyExc_TypeError, "beta is not contiguous and/or aligned");
    return NULL;
  }

  if ((PyArray_FLAGS(sigma_py) & NPY_IN_ARRAY) != NPY_IN_ARRAY) {
    PyErr_SetString(PyExc_TypeError, "sigma is not contiguous and/or aligned");
    return NULL;
  }

  /*
   * giv'r!
   *
   * indexing:
   *   - beta: cell, shift, cell, cell: i, r, m, n
   *   - sigma: cell, shift: i, r
   */

  N = PyArray_DIM(beta_py, 0);
  k = PyArray_DIM(beta_py, 1);

  /*
   * compute smoothness indicators sigma given smoothness indicator
   * coefficients beta
   *
   */

  for (i=k; i<N-k; i++) {
    for (r=0; r<k; r++) {

      sum = 0.0;
      for (m=0; m<2*k-1; m++) {   /* XXX: this can be faster */
        for (n=m; n<2*k-1; n++) { /* XXX: this can be faster */

          beta = (double *) PyArray_GETPTR4(beta_py, i, r, m, n);
          fm = (double *) PyArray_GETPTR1(f_py, i-(k-1)+m);
          fn = (double *) PyArray_GETPTR1(f_py, i-(k-1)+n);

          sum += (*beta) * (*fm) * (*fn);
        }
      }

      sigma = (double *) PyArray_GETPTR2(sigma_py, i, r);
      *sigma = sum;

    }
  }

  /*
   * done
   */

  Py_INCREF(Py_None);
  return Py_None;
}


/*
 * init this extension module...
 */

static PyMethodDef csmoothnessmethods[] = {
  {"sigma", sigma, METH_VARARGS, "XXX"},
  {NULL, NULL, 0, NULL}
};

PyMODINIT_FUNC
initcsmoothness(void)
{
  (void) Py_InitModule("csmoothness", csmoothnessmethods);
  import_array();
}
