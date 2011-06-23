#include <Python.h>
#include <numpy/ndarrayobject.h>

void
smoothness004 (const double *restrict f, int n, int fsi, double *restrict sigma, int ssi, int ssr)
{
  int i;
  double sigma0, sigma1, sigma2, sigma3;
  for (i = 4; i < n - 4; i++)
    {
      sigma0 =
	((+8.77916666666667) * (f[(i + 0) * fsi])) * (f[(i + 0) * fsi]) +
	((-39.175) * (f[(i + 0) * fsi])) * (f[(i + 1) * fsi]) +
	((+29.3416666666667) * (f[(i + 0) * fsi])) * (f[(i + 2) * fsi]) +
	((-7.725) * (f[(i + 0) * fsi])) * (f[(i + 3) * fsi]) +
	((+45.8458333333333) * (f[(i + 1) * fsi])) * (f[(i + 1) * fsi]) +
	((-71.8583333333333) * (f[(i + 1) * fsi])) * (f[(i + 2) * fsi]) +
	((+19.3416666666667) * (f[(i + 1) * fsi])) * (f[(i + 3) * fsi]) +
	((+29.3458333333333) * (f[(i + 2) * fsi])) * (f[(i + 2) * fsi]) +
	((-16.175) * (f[(i + 2) * fsi])) * (f[(i + 3) * fsi]) +
	((+2.27916666666667) * (f[(i + 3) * fsi])) * (f[(i + 3) * fsi]);
      sigma1 =
	((+2.27916666666667) * (f[(i - 1) * fsi])) * (f[(i - 1) * fsi]) +
	((-10.5083333333333) * (f[(i - 1) * fsi])) * (f[(i + 0) * fsi]) +
	((+8.00833333333333) * (f[(i - 1) * fsi])) * (f[(i + 1) * fsi]) +
	((-2.05833333333333) * (f[(i - 1) * fsi])) * (f[(i + 2) * fsi]) +
	((+14.3458333333333) * (f[(i + 0) * fsi])) * (f[(i + 0) * fsi]) +
	((-24.8583333333333) * (f[(i + 0) * fsi])) * (f[(i + 1) * fsi]) +
	((+6.675) * (f[(i + 0) * fsi])) * (f[(i + 2) * fsi]) +
	((+11.8458333333333) * (f[(i + 1) * fsi])) * (f[(i + 1) * fsi]) +
	((-6.84166666666667) * (f[(i + 1) * fsi])) * (f[(i + 2) * fsi]) +
	((+1.1125) * (f[(i + 2) * fsi])) * (f[(i + 2) * fsi]);
      sigma2 =
	((+1.1125) * (f[(i - 2) * fsi])) * (f[(i - 2) * fsi]) +
	((-6.84166666666667) * (f[(i - 2) * fsi])) * (f[(i - 1) * fsi]) +
	((+6.675) * (f[(i - 2) * fsi])) * (f[(i + 0) * fsi]) +
	((-2.05833333333333) * (f[(i - 2) * fsi])) * (f[(i + 1) * fsi]) +
	((+11.8458333333333) * (f[(i - 1) * fsi])) * (f[(i - 1) * fsi]) +
	((-24.8583333333333) * (f[(i - 1) * fsi])) * (f[(i + 0) * fsi]) +
	((+8.00833333333333) * (f[(i - 1) * fsi])) * (f[(i + 1) * fsi]) +
	((+14.3458333333333) * (f[(i + 0) * fsi])) * (f[(i + 0) * fsi]) +
	((-10.5083333333333) * (f[(i + 0) * fsi])) * (f[(i + 1) * fsi]) +
	((+2.27916666666667) * (f[(i + 1) * fsi])) * (f[(i + 1) * fsi]);
      sigma3 =
	((+2.27916666666667) * (f[(i - 3) * fsi])) * (f[(i - 3) * fsi]) +
	((-16.175) * (f[(i - 3) * fsi])) * (f[(i - 2) * fsi]) +
	((+19.3416666666667) * (f[(i - 3) * fsi])) * (f[(i - 1) * fsi]) +
	((-7.725) * (f[(i - 3) * fsi])) * (f[(i + 0) * fsi]) +
	((+29.3458333333333) * (f[(i - 2) * fsi])) * (f[(i - 2) * fsi]) +
	((-71.8583333333333) * (f[(i - 2) * fsi])) * (f[(i - 1) * fsi]) +
	((+29.3416666666667) * (f[(i - 2) * fsi])) * (f[(i + 0) * fsi]) +
	((+45.8458333333333) * (f[(i - 1) * fsi])) * (f[(i - 1) * fsi]) +
	((-39.175) * (f[(i - 1) * fsi])) * (f[(i + 0) * fsi]) +
	((+8.77916666666667) * (f[(i + 0) * fsi])) * (f[(i + 0) * fsi]);
      sigma[i * ssi + 0 * ssr] = sigma0;
      sigma[i * ssi + 1 * ssr] = sigma1;
      sigma[i * ssi + 2 * ssr] = sigma2;
      sigma[i * ssi + 3 * ssr] = sigma3;
    }
}

PyObject *
py_smoothness004 (PyObject * self, PyObject * args)
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

  smoothness004 (f, n, fsi, sigma, ssi, ssr);

  Py_INCREF (Py_None);
  return Py_None;
}
