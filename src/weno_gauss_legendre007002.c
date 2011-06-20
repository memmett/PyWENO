#include <Python.h>
#include <numpy/ndarrayobject.h>

void
gauss_legendre007002 (const double *restrict f, int n, int fsi,
		      const double *restrict sigma, int ssi, int ssr,
		      double *restrict fr, int frsi, int frsl)
{
  int i;
  double sigma0, sigma1, sigma2, sigma3, sigma4, sigma5, sigma6, omega1, omega9, omega0, omega12,
    omega11, omega8, omega6, omega10, omega5, omega4, omega7, omega13, omega3, omega2, accumulator,
    f1, f9, f0, f12, f11, f8, f6, f10, f5, f4, f7, f13, f3, f2, fr0, fr1;
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
      omega0 = +0.00203723184098822 / (1.0e-6 + sigma0) / (1.0e-6 + sigma0);
      accumulator += omega0;
      omega1 = +0.0448212334471436 / (1.0e-6 + sigma1) / (1.0e-6 + sigma1);
      accumulator += omega1;
      omega2 = +0.24037751296717 / (1.0e-6 + sigma2) / (1.0e-6 + sigma2);
      accumulator += omega2;
      omega3 = +0.415089587037575 / (1.0e-6 + sigma3) / (1.0e-6 + sigma3);
      accumulator += omega3;
      omega4 = +0.24841765649086 / (1.0e-6 + sigma4) / (1.0e-6 + sigma4);
      accumulator += omega4;
      omega5 = +0.0472764176538895 / (1.0e-6 + sigma5) / (1.0e-6 + sigma5);
      accumulator += omega5;
      omega6 = +0.00198036056237341 / (1.0e-6 + sigma6) / (1.0e-6 + sigma6);
      accumulator += omega6;
      omega0 /= accumulator;
      omega1 /= accumulator;
      omega2 /= accumulator;
      omega3 /= accumulator;
      omega4 /= accumulator;
      omega5 /= accumulator;
      omega6 /= accumulator;
      accumulator = 0.0;
      omega7 = +0.00198036056236228 / (1.0e-6 + sigma0) / (1.0e-6 + sigma0);
      accumulator += omega7;
      omega8 = +0.0472764176538959 / (1.0e-6 + sigma1) / (1.0e-6 + sigma1);
      accumulator += omega8;
      omega9 = +0.248417656490862 / (1.0e-6 + sigma2) / (1.0e-6 + sigma2);
      accumulator += omega9;
      omega10 = +0.415089587037573 / (1.0e-6 + sigma3) / (1.0e-6 + sigma3);
      accumulator += omega10;
      omega11 = +0.240377512967167 / (1.0e-6 + sigma4) / (1.0e-6 + sigma4);
      accumulator += omega11;
      omega12 = +0.044821233447153 / (1.0e-6 + sigma5) / (1.0e-6 + sigma5);
      accumulator += omega12;
      omega13 = +0.00203723184098284 / (1.0e-6 + sigma6) / (1.0e-6 + sigma6);
      accumulator += omega13;
      omega7 /= accumulator;
      omega8 /= accumulator;
      omega9 /= accumulator;
      omega10 /= accumulator;
      omega11 /= accumulator;
      omega12 /= accumulator;
      omega13 /= accumulator;
      f0 =
	+1.6574978940361 * f[(i + 0) * fsi] - 1.49638449179948 * f[(i + 1) * fsi] +
	1.6967588431261 * f[(i + 2) * fsi] - 1.42084042896771 * f[(i + 3) * fsi] +
	0.771057975871269 * f[(i + 4) * fsi] - 0.241019807968201 * f[(i + 5) * fsi] +
	0.0329300157019227 * f[(i + 6) * fsi];
      f1 =
	+0.0329300157019227 * f[(i - 1) * fsi] + 1.42698778412265 * f[(i + 0) * fsi] -
	0.804854162059106 * f[(i + 1) * fsi] + 0.544208293558806 * f[(i + 2) * fsi] -
	0.268289879400418 * f[(i + 3) * fsi] + 0.0795276461308923 * f[(i + 4) * fsi] -
	0.0105096980547421 * f[(i + 5) * fsi];
      f2 =
	-0.0105096980547421 * f[(i - 2) * fsi] + 0.106497902085117 * f[(i - 1) * fsi] +
	1.20628412497306 * f[(i + 0) * fsi] - 0.437014730143132 * f[(i + 1) * fsi] +
	0.176368861642832 * f[(i + 2) * fsi] - 0.0475862202508342 * f[(i + 3) * fsi] +
	0.0059597597476976 * f[(i + 4) * fsi];
      f3 =
	+0.0059597597476976 * f[(i - 3) * fsi] - 0.0522280162886253 * f[(i - 2) * fsi] +
	0.231652856786767 * f[(i - 1) * fsi] + 0.997692533803645 * f[(i + 0) * fsi] -
	0.228423138973716 * f[(i + 1) * fsi] + 0.0512139069411826 * f[(i + 2) * fsi] -
	0.00586790201695098 * f[(i + 3) * fsi];
      f4 =
	-0.00586790201695098 * f[(i - 4) * fsi] + 0.0470350738663545 * f[(i - 3) * fsi] -
	0.175453958644596 * f[(i - 2) * fsi] + 0.437029427380051 * f[(i - 1) * fsi] +
	0.792315963210361 * f[(i + 0) * fsi] - 0.105197196617745 * f[(i + 1) * fsi] +
	0.0101385928225258 * f[(i + 2) * fsi];
      f5 =
	+0.0101385928225258 * f[(i - 5) * fsi] - 0.0768380517746313 * f[(i - 4) * fsi] +
	0.259945523139395 * f[(i - 3) * fsi] - 0.530304707432998 * f[(i - 2) * fsi] +
	0.791880176168453 * f[(i - 1) * fsi] + 0.57940551393732 * f[(i + 0) * fsi] -
	0.034227046860065 * f[(i + 1) * fsi];
      f6 =
	-0.034227046860065 * f[(i - 6) * fsi] + 0.249727920842981 * f[(i - 5) * fsi] -
	0.795606035835996 * f[(i - 4) * fsi] + 1.45789216324167 * f[(i - 3) * fsi] -
	1.72825134753527 * f[(i - 2) * fsi] + 1.51064816022982 * f[(i - 1) * fsi] +
	0.339816185916865 * f[(i + 0) * fsi];
      f7 =
	+0.339816185916865 * f[(i + 0) * fsi] + 1.51064816022982 * f[(i + 1) * fsi] -
	1.72825134753527 * f[(i + 2) * fsi] + 1.45789216324166 * f[(i + 3) * fsi] -
	0.795606035835998 * f[(i + 4) * fsi] + 0.249727920842981 * f[(i + 5) * fsi] -
	0.0342270468600651 * f[(i + 6) * fsi];
      f8 =
	-0.0342270468600649 * f[(i - 1) * fsi] + 0.57940551393732 * f[(i + 0) * fsi] +
	0.791880176168453 * f[(i + 1) * fsi] - 0.530304707432998 * f[(i + 2) * fsi] +
	0.259945523139396 * f[(i + 3) * fsi] - 0.0768380517746313 * f[(i + 4) * fsi] +
	0.0101385928225258 * f[(i + 5) * fsi];
      f9 =
	+0.0101385928225258 * f[(i - 2) * fsi] - 0.105197196617745 * f[(i - 1) * fsi] +
	0.79231596321036 * f[(i + 0) * fsi] + 0.437029427380051 * f[(i + 1) * fsi] -
	0.175453958644596 * f[(i + 2) * fsi] + 0.0470350738663545 * f[(i + 3) * fsi] -
	0.00586790201695098 * f[(i + 4) * fsi];
      f10 =
	-0.00586790201695099 * f[(i - 3) * fsi] + 0.0512139069411827 * f[(i - 2) * fsi] -
	0.228423138973716 * f[(i - 1) * fsi] + 0.997692533803645 * f[(i + 0) * fsi] +
	0.231652856786767 * f[(i + 1) * fsi] - 0.0522280162886253 * f[(i + 2) * fsi] +
	0.0059597597476976 * f[(i + 3) * fsi];
      f11 =
	+0.0059597597476976 * f[(i - 4) * fsi] - 0.0475862202508342 * f[(i - 3) * fsi] +
	0.176368861642832 * f[(i - 2) * fsi] - 0.437014730143132 * f[(i - 1) * fsi] +
	1.20628412497306 * f[(i + 0) * fsi] + 0.106497902085117 * f[(i + 1) * fsi] -
	0.0105096980547421 * f[(i + 2) * fsi];
      f12 =
	-0.0105096980547421 * f[(i - 5) * fsi] + 0.0795276461308923 * f[(i - 4) * fsi] -
	0.268289879400418 * f[(i - 3) * fsi] + 0.544208293558806 * f[(i - 2) * fsi] -
	0.804854162059106 * f[(i - 1) * fsi] + 1.42698778412265 * f[(i + 0) * fsi] +
	0.0329300157019227 * f[(i + 1) * fsi];
      f13 =
	+0.0329300157019227 * f[(i - 6) * fsi] - 0.241019807968201 * f[(i - 5) * fsi] +
	0.771057975871269 * f[(i - 4) * fsi] - 1.42084042896771 * f[(i - 3) * fsi] +
	1.6967588431261 * f[(i - 2) * fsi] - 1.49638449179948 * f[(i - 1) * fsi] +
	1.6574978940361 * f[(i + 0) * fsi];
      fr0 =
	f0 * omega0 + f1 * omega1 + f2 * omega2 + f3 * omega3 + f4 * omega4 + f5 * omega5 +
	f6 * omega6;
      fr1 =
	f7 * omega7 + f8 * omega8 + f9 * omega9 + f10 * omega10 + f11 * omega11 + f12 * omega12 +
	f13 * omega13;
      fr[i * frsi + 0 * frsl] = fr0;
      fr[i * frsi + 1 * frsl] = fr1;
    }
}

PyObject *
py_gauss_legendre007002 (PyObject * self, PyObject * args)
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

  gauss_legendre007002 (f, n, fsi, sigma, ssi, ssr, fr, frsi, frsl);

  Py_INCREF (Py_None);
  return Py_None;
}
