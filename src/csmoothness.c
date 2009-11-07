#define PY_ARRAY_UNIQUE_SYMBOL PYWENO_ARRAY_API

#include <stdio.h>

#include <Python.h>
#include <numpy/ndarrayobject.h>

PyObject *
szs3(PyObject *self, PyObject *args)
{
  double *f, *sigma;
  PyObject *f_py, *sigma_py;

  long int N, i;
  int f_stride;

  /*
   * parse options
   */

  if (! PyArg_ParseTuple(args, "OO", &f_py, &sigma_py))
    return NULL;

  if ((PyArray_FLAGS(sigma_py) & NPY_IN_ARRAY) != NPY_IN_ARRAY) {
    PyErr_SetString(PyExc_TypeError, "sigma is not contiguous and/or aligned");
    return NULL;
  }

  /*
   * giv'r
   */

  N = PyArray_DIM(f_py, 0);

  /*
   * k order reconstructions
   */

  f_stride = ((double *) PyArray_GETPTR1(f_py, 1)) - ((double *) PyArray_GETPTR1(f_py, 0));

  f = (double *) PyArray_GETPTR1(f_py, 3);
  sigma = (double *) PyArray_GETPTR2(sigma_py, 3, 0);

  for (i=3; i<N-3; i++) {
    sigma[0] = f[-2] - 4.0 * f[-1] + 3.0 * f[0];
    sigma[0] *= sigma[0];

    sigma[1] = f[-1] - f[1];
    sigma[1] *= sigma[1];

    sigma[2] = 3.0 * f[0] - 4.0 * f[1] + f[2];
    sigma[2] *= sigma[2];

    sigma += 3;
    f++;
  }

  /*
   * done
   */
  Py_INCREF(Py_None);
  return Py_None;
}

static PyMethodDef CSmoothnessMethods[] = {
  {"szs3", szs3, METH_VARARGS, "XXX"},
  {NULL, NULL, 0, NULL}
};

PyMODINIT_FUNC
initcsmoothness(void)
{
  (void) Py_InitModule("csmoothness", CSmoothnessMethods);
  import_array();
}
