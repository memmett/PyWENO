#include <Python.h>
#include <numpy/ndarrayobject.h>

void
middle007001 (const double *restrict f, int n, int fsi,
	      const double *restrict sigma, int ssi, int ssr,
	      double *restrict fr, int frsi, int frsl)
{
  int i;
  double sigma0, sigma1, sigma2, sigma3, sigma4, sigma5, sigma6, omega1m, omega5m, omega6m, omega2p,
    omega3p, omega6p, omega0m, omega3m, omega4m, omega0p, omega5p, omega1p, omega4p, omega2m,
    accumulator, f1, f0, f6, f5, f4, f3, f2, fr0;
  for (i = 7; i < n - 7; i++)
    {
      sigma0 = sigma[i * ssi + 0 * ssr];
      sigma1 = sigma[i * ssi + 1 * ssr];
      sigma2 = sigma[i * ssi + 2 * ssr];
      sigma3 = sigma[i * ssi + 3 * ssr];
      sigma4 = sigma[i * ssi + 4 * ssr];
      sigma5 = sigma[i * ssi + 5 * ssr];
      sigma6 = sigma[i * ssi + 6 * ssr];
      accumulator = 0.0;
      omega0p = +0.000149691116038702 / +3.94901979530886 / (1.0e-6 + sigma0) / (1.0e-6 + sigma0);
      accumulator += omega0p;
      omega1p = +0.0106349872873979 / +3.94901979530886 / (1.0e-6 + sigma1) / (1.0e-6 + sigma1);
      accumulator += omega1p;
      omega2p = +0.31405195414804 / +3.94901979530886 / (1.0e-6 + sigma2) / (1.0e-6 + sigma2);
      accumulator += omega2p;
      omega3p = +3.29934653020591 / +3.94901979530886 / (1.0e-6 + sigma3) / (1.0e-6 + sigma3);
      accumulator += omega3p;
      omega4p = +0.31405195414804 / +3.94901979530886 / (1.0e-6 + sigma4) / (1.0e-6 + sigma4);
      accumulator += omega4p;
      omega5p = +0.0106349872873979 / +3.94901979530886 / (1.0e-6 + sigma5) / (1.0e-6 + sigma5);
      accumulator += omega5p;
      omega6p = +0.000149691116038702 / +3.94901979530886 / (1.0e-6 + sigma6) / (1.0e-6 + sigma6);
      accumulator += omega6p;
      omega0p /= accumulator;
      omega1p /= accumulator;
      omega2p /= accumulator;
      omega3p /= accumulator;
      omega4p /= accumulator;
      omega5p /= accumulator;
      omega6p /= accumulator;
      accumulator = 0.0;
      omega0m = +0.000299382232077403 / +2.94901979530886 / (1.0e-6 + sigma0) / (1.0e-6 + sigma0);
      accumulator += omega0m;
      omega1m = +0.0212699745747958 / +2.94901979530886 / (1.0e-6 + sigma1) / (1.0e-6 + sigma1);
      accumulator += omega1m;
      omega2m = +0.628103908296079 / +2.94901979530886 / (1.0e-6 + sigma2) / (1.0e-6 + sigma2);
      accumulator += omega2m;
      omega3m = +1.64967326510295 / +2.94901979530886 / (1.0e-6 + sigma3) / (1.0e-6 + sigma3);
      accumulator += omega3m;
      omega4m = +0.628103908296079 / +2.94901979530886 / (1.0e-6 + sigma4) / (1.0e-6 + sigma4);
      accumulator += omega4m;
      omega5m = +0.0212699745747958 / +2.94901979530886 / (1.0e-6 + sigma5) / (1.0e-6 + sigma5);
      accumulator += omega5m;
      omega6m = +0.000299382232077403 / +2.94901979530886 / (1.0e-6 + sigma6) / (1.0e-6 + sigma6);
      accumulator += omega6m;
      omega0m /= accumulator;
      omega1m /= accumulator;
      omega2m /= accumulator;
      omega3m /= accumulator;
      omega4m /= accumulator;
      omega5m /= accumulator;
      omega6m /= accumulator;
      f0 =
	+0.819094122023809 * f[(i + 0) * fsi] + 0.687518601190476 * f[(i + 1) * fsi] -
	1.13598400297619 * f[(i + 2) * fsi] + 1.07853422619048 * f[(i + 3) * fsi] -
	0.622963169642857 * f[(i + 4) * fsi] + 0.20210193452381 * f[(i + 5) * fsi] -
	0.0283017113095238 * f[(i + 6) * fsi];
      f1 =
	-0.0283017113095238 * f[(i - 1) * fsi] + 1.01720610119048 * f[(i + 0) * fsi] +
	0.0931826636904762 * f[(i + 1) * fsi] - 0.145424107142857 * f[(i + 2) * fsi] +
	0.0879743303571429 * f[(i + 3) * fsi] - 0.0286272321428571 * f[(i + 4) * fsi] +
	0.00398995535714286 * f[(i + 5) * fsi];
      f2 =
	+0.00398995535714286 * f[(i - 2) * fsi] - 0.0562313988095238 * f[(i - 1) * fsi] +
	1.10099516369048 * f[(i + 0) * fsi] - 0.0464657738095238 * f[(i + 1) * fsi] -
	0.00577566964285714 * f[(i + 2) * fsi] + 0.00418526785714286 * f[(i + 3) * fsi] -
	0.000697544642857143 * f[(i + 4) * fsi];
      f3 =
	-0.000697544642857143 * f[(i - 3) * fsi] + 0.00887276785714286 * f[(i - 2) * fsi] -
	0.0708798363095238 * f[(i - 1) * fsi] + 1.12540922619048 * f[(i + 0) * fsi] -
	0.0708798363095238 * f[(i + 1) * fsi] + 0.00887276785714286 * f[(i + 2) * fsi] -
	0.000697544642857143 * f[(i + 3) * fsi];
      f4 =
	-0.000697544642857143 * f[(i - 4) * fsi] + 0.00418526785714286 * f[(i - 3) * fsi] -
	0.00577566964285714 * f[(i - 2) * fsi] - 0.0464657738095238 * f[(i - 1) * fsi] +
	1.10099516369048 * f[(i + 0) * fsi] - 0.0562313988095238 * f[(i + 1) * fsi] +
	0.00398995535714286 * f[(i + 2) * fsi];
      f5 =
	+0.00398995535714286 * f[(i - 5) * fsi] - 0.0286272321428571 * f[(i - 4) * fsi] +
	0.0879743303571429 * f[(i - 3) * fsi] - 0.145424107142857 * f[(i - 2) * fsi] +
	0.0931826636904762 * f[(i - 1) * fsi] + 1.01720610119048 * f[(i + 0) * fsi] -
	0.0283017113095238 * f[(i + 1) * fsi];
      f6 =
	-0.0283017113095238 * f[(i - 6) * fsi] + 0.20210193452381 * f[(i - 5) * fsi] -
	0.622963169642857 * f[(i - 4) * fsi] + 1.07853422619048 * f[(i - 3) * fsi] -
	1.13598400297619 * f[(i - 2) * fsi] + 0.687518601190476 * f[(i - 1) * fsi] +
	0.819094122023809 * f[(i + 0) * fsi];
      fr0 =
	+3.94901979530886 * (f0 * omega0p + f1 * omega1p + f2 * omega2p + f3 * omega3p +
			     f4 * omega4p + f5 * omega5p + f6 * omega6p) -
	+2.94901979530886 * (f0 * omega0m + f1 * omega1m + f2 * omega2m + f3 * omega3m +
			     f4 * omega4m + f5 * omega5m + f6 * omega6m);
      fr[i * frsi + 0 * frsl] = fr0;
    }
}

PyObject *
py_middle007001 (PyObject * self, PyObject * args)
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

  middle007001 (f, n, fsi, sigma, ssi, ssr, fr, frsi, frsl);

  Py_INCREF (Py_None);
  return Py_None;
}
