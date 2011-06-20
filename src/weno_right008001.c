#include <Python.h>
#include <numpy/ndarrayobject.h>

void
right008001 (const double *restrict f, int n, int fsi,
	     const double *restrict sigma, int ssi, int ssr,
	     double *restrict fr, int frsi, int frsl)
{
  int i;
  double sigma0, sigma1, sigma2, sigma3, sigma4, sigma5, sigma6, sigma7, omega1, omega0, omega7,
    omega6, omega5, omega4, omega3, omega2, accumulator, f1, f0, f7, f6, f5, f4, f3, f2, fr0;
  for (i = 8; i < n - 8; i++)
    {
      sigma0 = sigma[i * ssi + 0 * ssr];
      sigma1 = sigma[i * ssi + 1 * ssr];
      sigma2 = sigma[i * ssi + 2 * ssr];
      sigma3 = sigma[i * ssi + 3 * ssr];
      sigma4 = sigma[i * ssi + 4 * ssr];
      sigma5 = sigma[i * ssi + 5 * ssr];
      sigma6 = sigma[i * ssi + 6 * ssr];
      sigma7 = sigma[i * ssi + 7 * ssr];
      accumulator = 0.0;
      omega0 = +0.00124320124320124 / (1.0e-6 + sigma0) / (1.0e-6 + sigma0);
      accumulator += omega0;
      omega1 = +0.0304584304584305 / (1.0e-6 + sigma1) / (1.0e-6 + sigma1);
      accumulator += omega1;
      omega2 = +0.182750582750583 / (1.0e-6 + sigma2) / (1.0e-6 + sigma2);
      accumulator += omega2;
      omega3 = +0.380730380730381 / (1.0e-6 + sigma3) / (1.0e-6 + sigma3);
      accumulator += omega3;
      omega4 = +0.304584304584305 / (1.0e-6 + sigma4) / (1.0e-6 + sigma4);
      accumulator += omega4;
      omega5 = +0.0913752913752914 / (1.0e-6 + sigma5) / (1.0e-6 + sigma5);
      accumulator += omega5;
      omega6 = +0.0087024087024087 / (1.0e-6 + sigma6) / (1.0e-6 + sigma6);
      accumulator += omega6;
      omega7 = +0.000155400155400155 / (1.0e-6 + sigma7) / (1.0e-6 + sigma7);
      accumulator += omega7;
      omega0 /= accumulator;
      omega1 /= accumulator;
      omega2 /= accumulator;
      omega3 /= accumulator;
      omega4 /= accumulator;
      omega5 /= accumulator;
      omega6 /= accumulator;
      omega7 /= accumulator;
      f0 =
	+0.125 * f[(i + 0) * fsi] + 1.71785714285714 * f[(i + 1) * fsi] -
	1.78214285714286 * f[(i + 2) * fsi] + 1.71785714285714 * f[(i + 3) * fsi] -
	1.19880952380952 * f[(i + 4) * fsi] + 0.551190476190476 * f[(i + 5) * fsi] -
	0.148809523809524 * f[(i + 6) * fsi] + 0.0178571428571429 * f[(i + 7) * fsi];
      f1 =
	-0.0178571428571429 * f[(i - 1) * fsi] + 0.267857142857143 * f[(i + 0) * fsi] +
	1.21785714285714 * f[(i + 1) * fsi] - 0.782142857142857 * f[(i + 2) * fsi] +
	0.467857142857143 * f[(i + 3) * fsi] - 0.198809523809524 * f[(i + 4) * fsi] +
	0.0511904761904762 * f[(i + 5) * fsi] - 0.00595238095238095 * f[(i + 6) * fsi];
      f2 =
	+0.00595238095238095 * f[(i - 2) * fsi] - 0.0654761904761905 * f[(i - 1) * fsi] +
	0.43452380952381 * f[(i + 0) * fsi] + 0.884523809523809 * f[(i + 1) * fsi] -
	0.36547619047619 * f[(i + 2) * fsi] + 0.13452380952381 * f[(i + 3) * fsi] -
	0.0321428571428571 * f[(i + 4) * fsi] + 0.00357142857142857 * f[(i + 5) * fsi];
      f3 =
	-0.00357142857142857 * f[(i - 3) * fsi] + 0.0345238095238095 * f[(i - 2) * fsi] -
	0.16547619047619 * f[(i - 1) * fsi] + 0.634523809523809 * f[(i + 0) * fsi] +
	0.634523809523809 * f[(i + 1) * fsi] - 0.16547619047619 * f[(i + 2) * fsi] +
	0.0345238095238095 * f[(i + 3) * fsi] - 0.00357142857142857 * f[(i + 4) * fsi];
      f4 =
	+0.00357142857142857 * f[(i - 4) * fsi] - 0.0321428571428571 * f[(i - 3) * fsi] +
	0.13452380952381 * f[(i - 2) * fsi] - 0.36547619047619 * f[(i - 1) * fsi] +
	0.884523809523809 * f[(i + 0) * fsi] + 0.43452380952381 * f[(i + 1) * fsi] -
	0.0654761904761905 * f[(i + 2) * fsi] + 0.00595238095238095 * f[(i + 3) * fsi];
      f5 =
	-0.00595238095238095 * f[(i - 5) * fsi] + 0.0511904761904762 * f[(i - 4) * fsi] -
	0.198809523809524 * f[(i - 3) * fsi] + 0.467857142857143 * f[(i - 2) * fsi] -
	0.782142857142857 * f[(i - 1) * fsi] + 1.21785714285714 * f[(i + 0) * fsi] +
	0.267857142857143 * f[(i + 1) * fsi] - 0.0178571428571429 * f[(i + 2) * fsi];
      f6 =
	+0.0178571428571429 * f[(i - 6) * fsi] - 0.148809523809524 * f[(i - 5) * fsi] +
	0.551190476190476 * f[(i - 4) * fsi] - 1.19880952380952 * f[(i - 3) * fsi] +
	1.71785714285714 * f[(i - 2) * fsi] - 1.78214285714286 * f[(i - 1) * fsi] +
	1.71785714285714 * f[(i + 0) * fsi] + 0.125 * f[(i + 1) * fsi];
      f7 =
	-0.125 * f[(i - 7) * fsi] + 1.01785714285714 * f[(i - 6) * fsi] -
	3.64880952380952 * f[(i - 5) * fsi] + 7.55119047619048 * f[(i - 4) * fsi] -
	9.94880952380952 * f[(i - 3) * fsi] + 8.71785714285714 * f[(i - 2) * fsi] -
	5.28214285714286 * f[(i - 1) * fsi] + 2.71785714285714 * f[(i + 0) * fsi];
      fr0 =
	f0 * omega0 + f1 * omega1 + f2 * omega2 + f3 * omega3 + f4 * omega4 + f5 * omega5 +
	f6 * omega6 + f7 * omega7;
      fr[i * frsi + 0 * frsl] = fr0;
    }
}

PyObject *
py_right008001 (PyObject * self, PyObject * args)
{
  double *f, *sigma, *fr;
  PyArrayObject *f_py, *sigma_py, *fr_py;

  long int n;
  int fsi, frsi, frsl, ssi, ssr;

  /* parse options */

  if (!PyArg_ParseTuple (args, "OOO", &f_py, &sigma_py, &fr_py))
    return NULL;

  if (f_py->nd != 1 || f_py->descr->type_num != PyArray_DOUBLE)
    {
      PyErr_SetString (PyExc_ValueError, "f must be one-dimensional and of type float");
      return NULL;
    }

  if (fr_py->descr->type_num != PyArray_DOUBLE)
    {
      PyErr_SetString (PyExc_ValueError, "fr must be of type float");
      return NULL;
    }

  if (!(fr_py->nd == 1 || fr_py->nd == 2))
    {
      PyErr_SetString (PyExc_ValueError, "fr must be one or two dimensional");
      return NULL;
    }

  if (sigma_py->nd != 2 || sigma_py->descr->type_num != PyArray_DOUBLE)
    {
      PyErr_SetString (PyExc_ValueError, "sigma must be two-dimensional and of type float");
      return NULL;
    }

  /* get data, n, strides */
  f = (double *) PyArray_DATA (f_py);
  fr = (double *) PyArray_DATA (fr_py);
  sigma = (double *) PyArray_DATA (sigma_py);

  n = PyArray_DIM (f_py, 0);

  fsi = f_py->strides[0] / sizeof (double);
  frsi = fr_py->strides[0] / sizeof (double);

  if (n == 1)
    {
      frsl = 0;
    }
  else
    {
      frsl = fr_py->strides[1] / sizeof (double);
    }

  ssi = sigma_py->strides[0] / sizeof (double);
  ssr = sigma_py->strides[1] / sizeof (double);

  right008001 (f, n, fsi, sigma, ssi, ssr, fr, frsi, frsl);

  Py_INCREF (Py_None);
  return Py_None;
}
