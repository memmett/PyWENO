#include <Python.h>
#include <numpy/ndarrayobject.h>

void
gauss_lobatto007004 (const double *restrict f, int n, int fsi,
		     const double *restrict sigma, int ssi, int ssr,
		     double *restrict fr, int frsi, int frsl)
{
  int i;
  double sigma0, sigma1, sigma2, sigma3, sigma4, sigma5, sigma6, omega10, omega21, omega15, omega20,
    omega13, omega19, omega3, omega9, omega24, omega14, omega12, omega27, omega16, omega8, omega23,
    omega0, omega4, omega11, omega17, omega7, omega26, omega1, omega22, omega2, omega6, omega5,
    omega25, omega18, accumulator, f10, f21, f15, f20, f13, f19, f3, f9, f24, f14, f12, f27, f16,
    f8, f23, f0, f4, f11, f17, f7, f26, f1, f22, f2, f6, f5, f25, f18, fr0, fr1, fr2, fr3;
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
      omega7 = +0.00472531504079195 / (1.0e-6 + sigma0) / (1.0e-6 + sigma0);
      accumulator += omega7;
      omega8 = +0.0578318845220515 / (1.0e-6 + sigma1) / (1.0e-6 + sigma1);
      accumulator += omega8;
      omega9 = +0.263515075254581 / (1.0e-6 + sigma2) / (1.0e-6 + sigma2);
      accumulator += omega9;
      omega10 = +0.408746614776945 / (1.0e-6 + sigma3) / (1.0e-6 + sigma3);
      accumulator += omega10;
      omega11 = +0.224366934771187 / (1.0e-6 + sigma4) / (1.0e-6 + sigma4);
      accumulator += omega11;
      omega12 = +0.0393178068269284 / (1.0e-6 + sigma5) / (1.0e-6 + sigma5);
      accumulator += omega12;
      omega13 = +0.00149636880751586 / (1.0e-6 + sigma6) / (1.0e-6 + sigma6);
      accumulator += omega13;
      omega7 /= accumulator;
      omega8 /= accumulator;
      omega9 /= accumulator;
      omega10 /= accumulator;
      omega11 /= accumulator;
      omega12 /= accumulator;
      omega13 /= accumulator;
      accumulator = 0.0;
      omega14 = +0.00149636880750669 / (1.0e-6 + sigma0) / (1.0e-6 + sigma0);
      accumulator += omega14;
      omega15 = +0.0393178068269441 / (1.0e-6 + sigma1) / (1.0e-6 + sigma1);
      accumulator += omega15;
      omega16 = +0.224366934771177 / (1.0e-6 + sigma2) / (1.0e-6 + sigma2);
      accumulator += omega16;
      omega17 = +0.408746614776947 / (1.0e-6 + sigma3) / (1.0e-6 + sigma3);
      accumulator += omega17;
      omega18 = +0.263515075254577 / (1.0e-6 + sigma4) / (1.0e-6 + sigma4);
      accumulator += omega18;
      omega19 = +0.0578318845220617 / (1.0e-6 + sigma5) / (1.0e-6 + sigma5);
      accumulator += omega19;
      omega20 = +0.00472531504078554 / (1.0e-6 + sigma6) / (1.0e-6 + sigma6);
      accumulator += omega20;
      omega14 /= accumulator;
      omega15 /= accumulator;
      omega16 /= accumulator;
      omega17 /= accumulator;
      omega18 /= accumulator;
      omega19 /= accumulator;
      omega20 /= accumulator;
      accumulator = 0.0;
      omega21 = +0.00407925407926976 / (1.0e-6 + sigma0) / (1.0e-6 + sigma0);
      accumulator += omega21;
      omega22 = +0.0734265734265464 / (1.0e-6 + sigma1) / (1.0e-6 + sigma1);
      accumulator += omega22;
      omega23 = +0.305944055944074 / (1.0e-6 + sigma2) / (1.0e-6 + sigma2);
      accumulator += omega23;
      omega24 = +0.407925407925404 / (1.0e-6 + sigma3) / (1.0e-6 + sigma3);
      accumulator += omega24;
      omega25 = +0.183566433566434 / (1.0e-6 + sigma4) / (1.0e-6 + sigma4);
      accumulator += omega25;
      omega26 = +0.0244755244755245 / (1.0e-6 + sigma5) / (1.0e-6 + sigma5);
      accumulator += omega26;
      omega27 = +0.000582750582750583 / (1.0e-6 + sigma6) / (1.0e-6 + sigma6);
      accumulator += omega27;
      omega21 /= accumulator;
      omega22 /= accumulator;
      omega23 /= accumulator;
      omega24 /= accumulator;
      omega25 /= accumulator;
      omega26 /= accumulator;
      omega27 /= accumulator;
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
	+1.42930863061919 * f[(i + 0) * fsi] - 0.848038971111085 * f[(i + 1) * fsi] +
	0.788421244542232 * f[(i + 2) * fsi] - 0.592437600450536 * f[(i + 3) * fsi] +
	0.300716306879381 * f[(i + 4) * fsi] - 0.0898549209858406 * f[(i + 5) * fsi] +
	0.0118853105066545 * f[(i + 6) * fsi];
      f8 =
	+0.0118853105066545 * f[(i - 1) * fsi] + 1.34611145707261 * f[(i + 0) * fsi] -
	0.59844745047134 * f[(i + 1) * fsi] + 0.372435376809325 * f[(i + 2) * fsi] -
	0.176451732717629 * f[(i + 3) * fsi] + 0.0511247862396371 * f[(i + 4) * fsi] -
	0.00665774743925916 * f[(i + 5) * fsi];
      f9 =
	-0.00665774743925916 * f[(i - 2) * fsi] + 0.0584895425814686 * f[(i - 1) * fsi] +
	1.20629876084817 * f[(i + 0) * fsi] - 0.365426290097269 * f[(i + 1) * fsi] +
	0.139414216435255 * f[(i + 2) * fsi] - 0.0366390364931869 * f[(i + 3) * fsi] +
	0.00452055416482296 * f[(i + 4) * fsi];
      f10 =
	+0.00452055416482296 * f[(i - 3) * fsi] - 0.0383016265930199 * f[(i - 2) * fsi] +
	0.153421180042751 * f[(i - 1) * fsi] + 1.04807936507936 * f[(i + 0) * fsi] -
	0.207206894328465 * f[(i + 1) * fsi] + 0.0444825789739723 * f[(i + 2) * fsi] -
	0.00499515733942614 * f[(i + 3) * fsi];
      f11 =
	-0.00499515733942614 * f[(i - 4) * fsi] + 0.0394866555408059 * f[(i - 3) * fsi] -
	0.143199930720969 * f[(i - 2) * fsi] + 0.328251686922666 * f[(i - 1) * fsi] +
	0.87324885819945 * f[(i + 0) * fsi] - 0.102308590200516 * f[(i + 1) * fsi] +
	0.00951647759798932 * f[(i + 2) * fsi];
      f12 =
	+0.00951647759798932 * f[(i - 5) * fsi] - 0.0716105005253514 * f[(i - 4) * fsi] +
	0.239332685098582 * f[(i - 3) * fsi] - 0.476276646650595 * f[(i - 2) * fsi] +
	0.661328402852292 * f[(i - 1) * fsi] + 0.673402828641675 * f[(i + 0) * fsi] -
	0.035693247014591 * f[(i + 1) * fsi];
      f13 =
	-0.035693247014591 * f[(i - 6) * fsi] + 0.259369206700126 * f[(i - 5) * fsi] -
	0.821168687831763 * f[(i - 4) * fsi] + 1.48859633060927 * f[(i - 3) * fsi] -
	1.72554029216128 * f[(i - 2) * fsi] + 1.4108865901587 * f[(i - 1) * fsi] +
	0.423550099539537 * f[(i + 0) * fsi];
      f14 =
	+0.423550099539537 * f[(i + 0) * fsi] + 1.4108865901587 * f[(i + 1) * fsi] -
	1.72554029216128 * f[(i + 2) * fsi] + 1.48859633060927 * f[(i + 3) * fsi] -
	0.821168687831764 * f[(i + 4) * fsi] + 0.259369206700126 * f[(i + 5) * fsi] -
	0.0356932470145911 * f[(i + 6) * fsi];
      f15 =
	-0.0356932470145911 * f[(i - 1) * fsi] + 0.673402828641675 * f[(i + 0) * fsi] +
	0.661328402852292 * f[(i + 1) * fsi] - 0.476276646650595 * f[(i + 2) * fsi] +
	0.239332685098582 * f[(i + 3) * fsi] - 0.0716105005253514 * f[(i + 4) * fsi] +
	0.00951647759798933 * f[(i + 5) * fsi];
      f16 =
	+0.00951647759798932 * f[(i - 2) * fsi] - 0.102308590200516 * f[(i - 1) * fsi] +
	0.87324885819945 * f[(i + 0) * fsi] + 0.328251686922666 * f[(i + 1) * fsi] -
	0.143199930720969 * f[(i + 2) * fsi] + 0.039486655540806 * f[(i + 3) * fsi] -
	0.00499515733942614 * f[(i + 4) * fsi];
      f17 =
	-0.00499515733942614 * f[(i - 3) * fsi] + 0.0444825789739723 * f[(i - 2) * fsi] -
	0.207206894328465 * f[(i - 1) * fsi] + 1.04807936507936 * f[(i + 0) * fsi] +
	0.153421180042751 * f[(i + 1) * fsi] - 0.0383016265930199 * f[(i + 2) * fsi] +
	0.00452055416482297 * f[(i + 3) * fsi];
      f18 =
	+0.00452055416482296 * f[(i - 4) * fsi] - 0.0366390364931869 * f[(i - 3) * fsi] +
	0.139414216435255 * f[(i - 2) * fsi] - 0.365426290097269 * f[(i - 1) * fsi] +
	1.20629876084817 * f[(i + 0) * fsi] + 0.0584895425814686 * f[(i + 1) * fsi] -
	0.00665774743925915 * f[(i + 2) * fsi];
      f19 =
	-0.00665774743925915 * f[(i - 5) * fsi] + 0.0511247862396371 * f[(i - 4) * fsi] -
	0.176451732717629 * f[(i - 3) * fsi] + 0.372435376809325 * f[(i - 2) * fsi] -
	0.59844745047134 * f[(i - 1) * fsi] + 1.34611145707261 * f[(i + 0) * fsi] +
	0.0118853105066545 * f[(i + 1) * fsi];
      f20 =
	+0.0118853105066545 * f[(i - 6) * fsi] - 0.0898549209858406 * f[(i - 5) * fsi] +
	0.300716306879381 * f[(i - 4) * fsi] - 0.592437600450536 * f[(i - 3) * fsi] +
	0.788421244542232 * f[(i - 2) * fsi] - 0.848038971111084 * f[(i - 1) * fsi] +
	1.42930863061919 * f[(i + 0) * fsi];
      f21 =
	+0.142857142857143 * f[(i + 0) * fsi] + 1.59285714285714 * f[(i + 1) * fsi] -
	1.40714285714286 * f[(i + 2) * fsi] + 1.09285714285714 * f[(i + 3) * fsi] -
	0.573809523809524 * f[(i + 4) * fsi] + 0.176190476190476 * f[(i + 5) * fsi] -
	0.0238095238095238 * f[(i + 6) * fsi];
      f22 =
	-0.0238095238095238 * f[(i - 1) * fsi] + 0.30952380952381 * f[(i + 0) * fsi] +
	1.09285714285714 * f[(i + 1) * fsi] - 0.573809523809524 * f[(i + 2) * fsi] +
	0.25952380952381 * f[(i + 3) * fsi] - 0.0738095238095238 * f[(i + 4) * fsi] +
	0.00952380952380954 * f[(i + 5) * fsi];
      f23 =
	+0.00952380952380954 * f[(i - 2) * fsi] - 0.0904761904761906 * f[(i - 1) * fsi] +
	0.50952380952381 * f[(i + 0) * fsi] + 0.759523809523809 * f[(i + 1) * fsi] -
	0.24047619047619 * f[(i + 2) * fsi] + 0.0595238095238095 * f[(i + 3) * fsi] -
	0.00714285714285715 * f[(i + 4) * fsi];
      f24 =
	-0.00714285714285714 * f[(i - 3) * fsi] + 0.0595238095238095 * f[(i - 2) * fsi] -
	0.240476190476191 * f[(i - 1) * fsi] + 0.75952380952381 * f[(i + 0) * fsi] +
	0.50952380952381 * f[(i + 1) * fsi] - 0.0904761904761905 * f[(i + 2) * fsi] +
	0.00952380952380952 * f[(i + 3) * fsi];
      f25 =
	+0.00952380952380952 * f[(i - 4) * fsi] - 0.0738095238095238 * f[(i - 3) * fsi] +
	0.259523809523809 * f[(i - 2) * fsi] - 0.573809523809524 * f[(i - 1) * fsi] +
	1.09285714285714 * f[(i + 0) * fsi] + 0.309523809523809 * f[(i + 1) * fsi] -
	0.0238095238095238 * f[(i + 2) * fsi];
      f26 =
	-0.0238095238095238 * f[(i - 5) * fsi] + 0.176190476190476 * f[(i - 4) * fsi] -
	0.573809523809524 * f[(i - 3) * fsi] + 1.09285714285714 * f[(i - 2) * fsi] -
	1.40714285714286 * f[(i - 1) * fsi] + 1.59285714285714 * f[(i + 0) * fsi] +
	0.142857142857143 * f[(i + 1) * fsi];
      f27 =
	+0.142857142857143 * f[(i - 6) * fsi] - 1.02380952380952 * f[(i - 5) * fsi] +
	3.17619047619048 * f[(i - 4) * fsi] - 5.57380952380953 * f[(i - 3) * fsi] +
	6.09285714285714 * f[(i - 2) * fsi] - 4.40714285714286 * f[(i - 1) * fsi] +
	2.59285714285714 * f[(i + 0) * fsi];
      fr0 =
	f0 * omega0 + f1 * omega1 + f2 * omega2 + f3 * omega3 + f4 * omega4 + f5 * omega5 +
	f6 * omega6;
      fr1 =
	f7 * omega7 + f8 * omega8 + f9 * omega9 + f10 * omega10 + f11 * omega11 + f12 * omega12 +
	f13 * omega13;
      fr2 =
	f14 * omega14 + f15 * omega15 + f16 * omega16 + f17 * omega17 + f18 * omega18 +
	f19 * omega19 + f20 * omega20;
      fr3 =
	f21 * omega21 + f22 * omega22 + f23 * omega23 + f24 * omega24 + f25 * omega25 +
	f26 * omega26 + f27 * omega27;
      fr[i * frsi + 0 * frsl] = fr0;
      fr[i * frsi + 1 * frsl] = fr1;
      fr[i * frsi + 2 * frsl] = fr2;
      fr[i * frsi + 3 * frsl] = fr3;
    }
}

PyObject *
py_gauss_lobatto007004 (PyObject * self, PyObject * args)
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

  gauss_lobatto007004 (f, n, fsi, sigma, ssi, ssr, fr, frsi, frsl);

  Py_INCREF (Py_None);
  return Py_None;
}
