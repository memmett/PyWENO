#include <Python.h>
#include <numpy/ndarrayobject.h>

void
gauss_radau007002 (const double *restrict f, int n, int fsi,
		   const double *restrict sigma, int ssi, int ssr,
		   double *restrict fr, int frsi, int frsl)
{
  int i;
  double sigma0, sigma1, sigma2, sigma3, sigma4, sigma5, sigma6, omega1, omega8p, omega0, omega11p,
    omega12p, omega9m, omega7p, omega13m, omega11m, omega10m, omega7m, omega8m, omega6, omega9p,
    omega5, omega12m, omega4, omega3, omega13p, omega10p, omega2, accumulator, f1, f9, f0, f12, f11,
    f8, f6, f10, f5, f4, f7, f13, f3, f2, fr0, fr1;
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
      omega0 = +0.000582750582750583 / (1.0e-6 + sigma0) / (1.0e-6 + sigma0);
      accumulator += omega0;
      omega1 = +0.0244755244755245 / (1.0e-6 + sigma1) / (1.0e-6 + sigma1);
      accumulator += omega1;
      omega2 = +0.183566433566434 / (1.0e-6 + sigma2) / (1.0e-6 + sigma2);
      accumulator += omega2;
      omega3 = +0.407925407925408 / (1.0e-6 + sigma3) / (1.0e-6 + sigma3);
      accumulator += omega3;
      omega4 = +0.305944055944056 / (1.0e-6 + sigma4) / (1.0e-6 + sigma4);
      accumulator += omega4;
      omega5 = +0.0734265734265734 / (1.0e-6 + sigma5) / (1.0e-6 + sigma5);
      accumulator += omega5;
      omega6 = +0.00407925407925408 / (1.0e-6 + sigma6) / (1.0e-6 + sigma6);
      accumulator += omega6;
      omega0 /= accumulator;
      omega1 /= accumulator;
      omega2 /= accumulator;
      omega3 /= accumulator;
      omega4 /= accumulator;
      omega5 /= accumulator;
      omega6 /= accumulator;
      accumulator = 0.0;
      omega7p = +0.00220201167691643 / +2.05100035827684 / (1.0e-6 + sigma0) / (1.0e-6 + sigma0);
      accumulator += omega7p;
      omega8p = +0.0634159655317075 / +2.05100035827684 / (1.0e-6 + sigma1) / (1.0e-6 + sigma1);
      accumulator += omega8p;
      omega9p = +0.392683926293292 / +2.05100035827684 / (1.0e-6 + sigma2) / (1.0e-6 + sigma2);
      accumulator += omega9p;
      omega10p = +0.78302467440573 / +2.05100035827684 / (1.0e-6 + sigma3) / (1.0e-6 + sigma3);
      accumulator += omega10p;
      omega11p = +0.568073303660456 / +2.05100035827684 / (1.0e-6 + sigma4) / (1.0e-6 + sigma4);
      accumulator += omega11p;
      omega12p = +0.224600357283124 / +2.05100035827684 / (1.0e-6 + sigma5) / (1.0e-6 + sigma5);
      accumulator += omega12p;
      omega13p = +0.0170001194256114 / +2.05100035827684 / (1.0e-6 + sigma6) / (1.0e-6 + sigma6);
      accumulator += omega13p;
      omega7p /= accumulator;
      omega8p /= accumulator;
      omega9p /= accumulator;
      omega10p /= accumulator;
      omega11p /= accumulator;
      omega12p /= accumulator;
      omega13p /= accumulator;
      accumulator = 0.0;
      omega7m = +0.00110100583845822 / +1.05100035827684 / (1.0e-6 + sigma0) / (1.0e-6 + sigma0);
      accumulator += omega7m;
      omega8m = +0.0317079827658538 / +1.05100035827684 / (1.0e-6 + sigma1) / (1.0e-6 + sigma1);
      accumulator += omega8m;
      omega9m = +0.196341963146646 / +1.05100035827684 / (1.0e-6 + sigma2) / (1.0e-6 + sigma2);
      accumulator += omega9m;
      omega10m = +0.391512337202865 / +1.05100035827684 / (1.0e-6 + sigma3) / (1.0e-6 + sigma3);
      accumulator += omega10m;
      omega11m = +0.284036651830228 / +1.05100035827684 / (1.0e-6 + sigma4) / (1.0e-6 + sigma4);
      accumulator += omega11m;
      omega12m = +0.112300178641562 / +1.05100035827684 / (1.0e-6 + sigma5) / (1.0e-6 + sigma5);
      accumulator += omega12m;
      omega13m = +0.0340002388512228 / +1.05100035827684 / (1.0e-6 + sigma6) / (1.0e-6 + sigma6);
      accumulator += omega13m;
      omega7m /= accumulator;
      omega8m /= accumulator;
      omega9m /= accumulator;
      omega10m /= accumulator;
      omega11m /= accumulator;
      omega12m /= accumulator;
      omega13m /= accumulator;
      f0 =
	+2.59285714285714 * f[(i + 0) * fsi] - 4.40714285714286 * f[(i + 1) * fsi] +
	6.09285714285714 * f[(i + 2) * fsi] - 5.57380952380952 * f[(i + 3) * fsi] +
	3.17619047619048 * f[(i + 4) * fsi] - 1.02380952380952 * f[(i + 5) * fsi] +
	0.142857142857143 * f[(i + 6) * fsi];
      f1 =
	+0.142857142857143 * f[(i - 1) * fsi] + 1.59285714285714 * f[(i + 0) * fsi] -
	1.40714285714286 * f[(i + 1) * fsi] + 1.09285714285714 * f[(i + 2) * fsi] -
	0.573809523809524 * f[(i + 3) * fsi] + 0.176190476190476 * f[(i + 4) * fsi] -
	0.0238095238095238 * f[(i + 5) * fsi];
      f2 =
	-0.0238095238095238 * f[(i - 2) * fsi] + 0.30952380952381 * f[(i - 1) * fsi] +
	1.09285714285714 * f[(i + 0) * fsi] - 0.573809523809524 * f[(i + 1) * fsi] +
	0.25952380952381 * f[(i + 2) * fsi] - 0.0738095238095238 * f[(i + 3) * fsi] +
	0.00952380952380952 * f[(i + 4) * fsi];
      f3 =
	+0.00952380952380952 * f[(i - 3) * fsi] - 0.0904761904761905 * f[(i - 2) * fsi] +
	0.509523809523809 * f[(i - 1) * fsi] + 0.759523809523809 * f[(i + 0) * fsi] -
	0.24047619047619 * f[(i + 1) * fsi] + 0.0595238095238095 * f[(i + 2) * fsi] -
	0.00714285714285714 * f[(i + 3) * fsi];
      f4 =
	-0.00714285714285714 * f[(i - 4) * fsi] + 0.0595238095238095 * f[(i - 3) * fsi] -
	0.24047619047619 * f[(i - 2) * fsi] + 0.759523809523809 * f[(i - 1) * fsi] +
	0.509523809523809 * f[(i + 0) * fsi] - 0.0904761904761905 * f[(i + 1) * fsi] +
	0.00952380952380952 * f[(i + 2) * fsi];
      f5 =
	+0.00952380952380952 * f[(i - 5) * fsi] - 0.0738095238095238 * f[(i - 4) * fsi] +
	0.25952380952381 * f[(i - 3) * fsi] - 0.573809523809524 * f[(i - 2) * fsi] +
	1.09285714285714 * f[(i - 1) * fsi] + 0.30952380952381 * f[(i + 0) * fsi] -
	0.0238095238095238 * f[(i + 1) * fsi];
      f6 =
	-0.0238095238095238 * f[(i - 6) * fsi] + 0.176190476190476 * f[(i - 5) * fsi] -
	0.573809523809524 * f[(i - 4) * fsi] + 1.09285714285714 * f[(i - 3) * fsi] -
	1.40714285714286 * f[(i - 2) * fsi] + 1.59285714285714 * f[(i - 1) * fsi] +
	0.142857142857143 * f[(i + 0) * fsi];
      f7 =
	+0.507450954776058 * f[(i + 0) * fsi] + 1.28711868835326 * f[(i + 1) * fsi] -
	1.66937422431249 * f[(i + 2) * fsi] + 1.469019313258 * f[(i + 3) * fsi] -
	0.818208243516885 * f[(i + 4) * fsi] + 0.259889607420472 * f[(i + 5) * fsi] -
	0.0358960959784005 * f[(i + 6) * fsi];
      f8 =
	-0.0358960959784004 * f[(i - 1) * fsi] + 0.758723626624861 * f[(i + 0) * fsi] +
	0.533300672806846 * f[(i + 1) * fsi] - 0.413010865068478 * f[(i + 2) * fsi] +
	0.212655954013979 * f[(i + 3) * fsi] - 0.0643902279704749 * f[(i + 4) * fsi] +
	0.00861693557166809 * f[(i + 5) * fsi];
      f9 =
	+0.00861693557166809 * f[(i - 2) * fsi] - 0.096214644980077 * f[(i - 1) * fsi] +
	0.939679273629891 * f[(i + 0) * fsi] + 0.231707927798463 * f[(i + 1) * fsi] -
	0.111418120060095 * f[(i + 2) * fsi] + 0.031700307008949 * f[(i + 3) * fsi] -
	0.00407167896879831 * f[(i + 4) * fsi];
      f10 =
	-0.00407167896879831 * f[(i - 3) * fsi] + 0.0371186883532563 * f[(i - 2) * fsi] -
	0.181719903324842 * f[(i - 1) * fsi] + 1.08218803753783 * f[(i + 0) * fsi] +
	0.0891991638905219 * f[(i + 1) * fsi] - 0.0259128617153308 * f[(i + 2) * fsi] +
	0.00319855422736081 * f[(i + 3) * fsi];
      f11 =
	+0.00319855422736081 * f[(i - 4) * fsi] - 0.026461558560324 * f[(i - 3) * fsi] +
	0.104288327127833 * f[(i - 2) * fsi] - 0.29366930128247 * f[(i - 1) * fsi] +
	1.19413743549546 * f[(i + 0) * fsi] + 0.0220295251159449 * f[(i + 1) * fsi] -
	0.00352298212380516 * f[(i + 2) * fsi];
      f12 =
	-0.00352298212380516 * f[(i - 5) * fsi] + 0.027859429093997 * f[(i - 4) * fsi] -
	0.100444183160232 * f[(i - 3) * fsi] + 0.227592701461014 * f[(i - 2) * fsi] -
	0.416973675615651 * f[(i - 1) * fsi] + 1.26812006009537 * f[(i + 0) * fsi] -
	0.00263134975069133 * f[(i + 1) * fsi];
      f13 =
	-0.00263134975069133 * f[(i - 6) * fsi] + 0.0148964661310341 * f[(i - 5) * fsi] -
	0.0273989156705209 * f[(i - 4) * fsi] - 0.00834694188603596 * f[(i - 3) * fsi] +
	0.135495460186818 * f[(i - 2) * fsi] - 0.361715330851133 * f[(i - 1) * fsi] +
	1.24970061184053 * f[(i + 0) * fsi];
      fr0 =
	f0 * omega0 + f1 * omega1 + f2 * omega2 + f3 * omega3 + f4 * omega4 + f5 * omega5 +
	f6 * omega6;
      fr1 =
	+2.05100035827684 * (f7 * omega7p + f8 * omega8p + f9 * omega9p + f10 * omega10p +
			     f11 * omega11p + f12 * omega12p + f13 * omega13p) -
	+1.05100035827684 * (f7 * omega7m + f8 * omega8m + f9 * omega9m + f10 * omega10m +
			     f11 * omega11m + f12 * omega12m + f13 * omega13m);
      fr[i * frsi + 0 * frsl] = fr0;
      fr[i * frsi + 1 * frsl] = fr1;
    }
}

PyObject *
py_gauss_radau007002 (PyObject * self, PyObject * args)
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

  gauss_radau007002 (f, n, fsi, sigma, ssi, ssr, fr, frsi, frsl);

  Py_INCREF (Py_None);
  return Py_None;
}
