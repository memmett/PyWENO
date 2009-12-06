#define PY_ARRAY_UNIQUE_SYMBOL PYWENO_ARRAY_API

#include <stdio.h>

#include <Python.h>
#include <numpy/ndarrayobject.h>

/*
 * cweno - python extension module for (faster) weno reconstructions.
 *         see 'reconstruct' for the good stuff.
 */


/*
 * dot - compute dot product of vectors u and v
 *
 *   * each vector has length n
 *   * u is contiguous
 *   * v has stride s
 */
double
dot(double *u, double *v, int n, int s)
{
  double d;
  int i;

  d = *u * *v;
  for (i=1; i<n; i++) {
    u++;
    v += s;
    d += *u * *v;
  }

   return d;
}


/*
 * alpha - compute alpha given optimal weight w and smoothness
 *         indicator s
 */
double
alpha(double *w, double *s)
{
  return *w / ( (10e-6 + *s) * (10e-6 + *s) );
}


/*
 * weights - compute weights wr given optimal weights w and smoothness
 *           indicators s
 */
void
weights(PyObject *self, PyObject *args)
{
  double *s, *w, *wr;
  PyObject *s_py, *w_py, *wr_py;

  long int N, i;
  int k, r;
  double sum_alpha;

  /*
   * parse options
   */

  if (! PyArg_ParseTuple(args, "OOO", &s_py, &w_py, &wr_py))
    return NULL;

  if ((PyArray_FLAGS(s_py) & NPY_IN_ARRAY) != NPY_IN_ARRAY) {
    PyErr_SetString(PyExc_TypeError, "s is not contiguous and/or aligned");
    return NULL;
  }

  if ((PyArray_FLAGS(w_py) & NPY_IN_ARRAY) != NPY_IN_ARRAY) {
    PyErr_SetString(PyExc_TypeError, "w is not contiguous and/or aligned");
    return NULL;
  }

  if ((PyArray_FLAGS(wr_py) & NPY_IN_ARRAY) != NPY_IN_ARRAY) {
    PyErr_SetString(PyExc_TypeError, "wr is not contiguous and/or aligned");
    return NULL;
  }

  /*
   * giv'r!
   *
   * indexing:
   *   - s: cell, shift: i, r
   *   - w: cell, shift: i, r
   *   - wr: cell, shift: i, r
   */

  N = PyArray_DIM(w_py, 0);
  k = PyArray_DIM(w_py, 1);

  w  = (double *) PyArray_GETPTR2(w_py, k, 0);
  s  = (double *) PyArray_GETPTR2(s_py, k, 0);

  for (i=k; i<N-k; i++) {
    sum_alpha = 0.0;

    wr = (double *) PyArray_GETPTR2(wr_py, i, 0);
    for (r=0; r<k; r++) {
      *wr = alpha(w, s);

      sum_alpha += *wr;

      wr++;
      w++;
      s++;
    }

    wr = (double *) PyArray_GETPTR2(wr_py, i, 0);
    for (r=0; r<k; r++) {
      *wr /= sum_alpha;
      wr++;
    }
  }
}


/*
 * reconstruct - reconstruct a function given its cell averages q
 */
PyObject *
reconstruct(PyObject *self, PyObject *args)
{
  double *q, *s, *c, *qr, *wr, *qs;
  PyObject *q_py, *s_py, *c_py, *qr_py, *wr_py, *qs_py;

  long int N, i;
  int k, r, n, l;

  int q_stride;

  /*
   * parse options
   */

  if (! PyArg_ParseTuple(args, "OOOOOO", &q_py, &s_py, &c_py, &wr_py, &qr_py, &qs_py))
    return NULL;

  if ((PyArray_FLAGS(s_py) & NPY_IN_ARRAY) != NPY_IN_ARRAY) {
    PyErr_SetString(PyExc_TypeError, "s is not contiguous and/or aligned");
    return NULL;
  }

  if ((PyArray_FLAGS(c_py) & NPY_IN_ARRAY) != NPY_IN_ARRAY) {
    PyErr_SetString(PyExc_TypeError, "c is not contiguous and/or aligned");
    return NULL;
  }

  if ((PyArray_FLAGS(wr_py) & NPY_IN_ARRAY) != NPY_IN_ARRAY) {
    PyErr_SetString(PyExc_TypeError, "wr is not contiguous and/or aligned");
    return NULL;
  }

  if ((PyArray_FLAGS(qr_py) & NPY_IN_ARRAY) != NPY_IN_ARRAY) {
    PyErr_SetString(PyExc_TypeError, "qr is not contiguous and/or aligned");
    return NULL;
  }

  /*
   * giv'r!
   *
   * indexing:
   *   - s: cell, shift: i, r
   *   - c: cell, shift, point, cell: i, r, l, j
   *   - qr: cell, shift, point: i, r, l
   *   - wr: cell, shift: i, r
   *   - qs: cell, point: i, l
   */

  N = PyArray_DIM(c_py, 0);
  k = PyArray_DIM(c_py, 1);
  n = PyArray_DIM(c_py, 2);

  /*
   * k-order - compute k-order reconstructions qr given q and
   *           reconstruction coefficients c
   */

  q_stride = ((double *) PyArray_GETPTR1(q_py, 1)) - ((double *) PyArray_GETPTR1(q_py, 0));

  c  = (double *) PyArray_GETPTR4(c_py,  k, 0, 0, 0);
  qr = (double *) PyArray_GETPTR3(qr_py, k, 0, 0);

  for (i=k; i<N-k; i++) {
    for (r=0; r<k; r++) {
      q = (double *) PyArray_GETPTR1(q_py, i-r);

      for (l=0; l<n; l++) {
        *qr = dot(c, q, k, q_stride);

        c += k;
        qr++;
      }
    }
  }

  /*
   * 2k-1 order - build 2k-1 order reconstructions qs given k-order
   *              recontructions qr and weights wr
   */

  q_stride = ((double *) PyArray_GETPTR2(qs_py, k, 1)) - ((double *) PyArray_GETPTR2(qs_py, k, 0));

  wr = (double *) PyArray_GETPTR2(wr_py, k, 0);

  for (i=k; i<N-k; i++) {
    qs = (double *) PyArray_GETPTR2(qs_py, i, 0);
    qr = (double *) PyArray_GETPTR3(qr_py, i, 0, 0);

    for (l=0; l<n; l++) {
      *qs = dot(wr, qr, k, n);

      qs += q_stride;
      qr++;
    }

    wr += k;
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

static PyMethodDef cwenomethods[] = {
  {"weights", weights, METH_VARARGS, "XXX"},
  {"reconstruct", reconstruct, METH_VARARGS, "XXX"},
  {NULL, NULL, 0, NULL}
};

PyMODINIT_FUNC
initcweno(void)
{
  (void) Py_InitModule("cweno", cwenomethods);
  import_array();
}
