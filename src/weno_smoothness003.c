#include <Python.h>
#include <numpy/ndarrayobject.h>

void
smoothness003 (const double *restrict f, int n, int fsi, double *restrict sigma, int ssi, int ssr)
{
  int i;
  double sigma0, sigma1, sigma2;
  for (i = 3; i < n - 3; i++)
    {
      sigma0 =
	((+3.33333333333333) * (f[(i + 0) * fsi])) * (f[(i + 0) * fsi]) +
	((-10.3333333333333) * (f[(i + 0) * fsi])) * (f[(i + 1) * fsi]) +
	((+3.66666666666667) * (f[(i + 0) * fsi])) * (f[(i + 2) * fsi]) +
	((+8.33333333333333) * (f[(i + 1) * fsi])) * (f[(i + 1) * fsi]) +
	((-6.33333333333333) * (f[(i + 1) * fsi])) * (f[(i + 2) * fsi]) +
	((+1.33333333333333) * (f[(i + 2) * fsi])) * (f[(i + 2) * fsi]);
      sigma1 =
	((+1.33333333333333) * (f[(i - 1) * fsi])) * (f[(i - 1) * fsi]) +
	((-4.33333333333333) * (f[(i - 1) * fsi])) * (f[(i + 0) * fsi]) +
	((+1.66666666666667) * (f[(i - 1) * fsi])) * (f[(i + 1) * fsi]) +
	((+4.33333333333333) * (f[(i + 0) * fsi])) * (f[(i + 0) * fsi]) +
	((-4.33333333333333) * (f[(i + 0) * fsi])) * (f[(i + 1) * fsi]) +
	((+1.33333333333333) * (f[(i + 1) * fsi])) * (f[(i + 1) * fsi]);
      sigma2 =
	((+1.33333333333333) * (f[(i - 2) * fsi])) * (f[(i - 2) * fsi]) +
	((-6.33333333333333) * (f[(i - 2) * fsi])) * (f[(i - 1) * fsi]) +
	((+3.66666666666667) * (f[(i - 2) * fsi])) * (f[(i + 0) * fsi]) +
	((+8.33333333333333) * (f[(i - 1) * fsi])) * (f[(i - 1) * fsi]) +
	((-10.3333333333333) * (f[(i - 1) * fsi])) * (f[(i + 0) * fsi]) +
	((+3.33333333333333) * (f[(i + 0) * fsi])) * (f[(i + 0) * fsi]);
      sigma[i * ssi + 0 * ssr] = sigma0;
      sigma[i * ssi + 1 * ssr] = sigma1;
      sigma[i * ssi + 2 * ssr] = sigma2;
    }
}

PyObject *
py_smoothness003 (PyObject * self, PyObject * args)
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

  smoothness003 (f, n, fsi, sigma, ssi, ssr);

  Py_INCREF (Py_None);
  return Py_None;
}
