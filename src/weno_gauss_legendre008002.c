#include <Python.h>
#include <numpy/ndarrayobject.h>

void
gauss_legendre008002 (const double *restrict f, int n, int fsi,
		      const double *restrict sigma, int ssi, int ssr,
		      double *restrict fr, int frsi, int frsl)
{
  int i;
  double sigma0, sigma1, sigma2, sigma3, sigma4, sigma5, sigma6, sigma7, omega1, omega10, omega0,
    omega13, omega15, omega7, omega9, omega6, omega11, omega5, omega12, omega4, omega8, omega14,
    omega3, omega2, accumulator, f1, f10, f0, f13, f15, f7, f9, f6, f11, f5, f12, f4, f8, f14, f3,
    f2, fr0, fr1;
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
      omega0 = +0.000605390843432627 / (1.0e-6 + sigma0) / (1.0e-6 + sigma0);
      accumulator += omega0;
      omega1 = +0.0174839538148565 / (1.0e-6 + sigma1) / (1.0e-6 + sigma1);
      accumulator += omega1;
      omega2 = +0.131603067557156 / (1.0e-6 + sigma2) / (1.0e-6 + sigma2);
      accumulator += omega2;
      omega3 = +0.344250696753955 / (1.0e-6 + sigma3) / (1.0e-6 + sigma3);
      accumulator += omega3;
      omega4 = +0.34958636872314 / (1.0e-6 + sigma4) / (1.0e-6 + sigma4);
      accumulator += omega4;
      omega5 = +0.137419236826875 / (1.0e-6 + sigma5) / (1.0e-6 + sigma5);
      accumulator += omega5;
      omega6 = +0.0184755182647151 / (1.0e-6 + sigma6) / (1.0e-6 + sigma6);
      accumulator += omega6;
      omega7 = +0.000575767215869653 / (1.0e-6 + sigma7) / (1.0e-6 + sigma7);
      accumulator += omega7;
      omega0 /= accumulator;
      omega1 /= accumulator;
      omega2 /= accumulator;
      omega3 /= accumulator;
      omega4 /= accumulator;
      omega5 /= accumulator;
      omega6 /= accumulator;
      omega7 /= accumulator;
      accumulator = 0.0;
      omega8 = +0.000575767215744102 / (1.0e-6 + sigma0) / (1.0e-6 + sigma0);
      accumulator += omega8;
      omega9 = +0.0184755182649168 / (1.0e-6 + sigma1) / (1.0e-6 + sigma1);
      accumulator += omega9;
      omega10 = +0.137419236826727 / (1.0e-6 + sigma2) / (1.0e-6 + sigma2);
      accumulator += omega10;
      omega11 = +0.349586368723194 / (1.0e-6 + sigma3) / (1.0e-6 + sigma3);
      accumulator += omega11;
      omega12 = +0.344250696753948 / (1.0e-6 + sigma4) / (1.0e-6 + sigma4);
      accumulator += omega12;
      omega13 = +0.131603067557145 / (1.0e-6 + sigma5) / (1.0e-6 + sigma5);
      accumulator += omega13;
      omega14 = +0.0174839538148726 / (1.0e-6 + sigma6) / (1.0e-6 + sigma6);
      accumulator += omega14;
      omega15 = +0.000605390843425299 / (1.0e-6 + sigma7) / (1.0e-6 + sigma7);
      accumulator += omega15;
      omega8 /= accumulator;
      omega9 /= accumulator;
      omega10 /= accumulator;
      omega11 /= accumulator;
      omega12 /= accumulator;
      omega13 /= accumulator;
      omega14 /= accumulator;
      omega15 /= accumulator;
      f0 =
	+1.68327638436316 * f[(i + 0) * fsi] - 1.6768339240889 * f[(i + 1) * fsi] +
	2.23810713999436 * f[(i + 2) * fsi] - 2.32308759041481 * f[(i + 3) * fsi] +
	1.67330513731837 * f[(i + 4) * fsi] - 0.782368104836459 * f[(i + 5) * fsi] +
	0.213379447991342 * f[(i + 6) * fsi] - 0.0257784903270599 * f[(i + 7) * fsi];
      f1 =
	+0.0257784903270599 * f[(i - 1) * fsi] + 1.47704846174668 * f[(i + 0) * fsi] -
	0.955036194931224 * f[(i + 1) * fsi] + 0.794511681679004 * f[(i + 2) * fsi] -
	0.518593267520616 * f[(i + 3) * fsi] + 0.229709679003011 * f[(i + 4) * fsi] -
	0.0605703756787817 * f[(i + 5) * fsi] + 0.0071515253748628 * f[(i + 6) * fsi];
      f2 =
	-0.0071515253748628 * f[(i - 2) * fsi] + 0.0829906933259623 * f[(i - 1) * fsi] +
	1.27680575125053 * f[(i + 0) * fsi] - 0.554550773938908 * f[(i + 1) * fsi] +
	0.293904905438608 * f[(i + 2) * fsi] - 0.1181078465283 * f[(i + 3) * fsi] +
	0.0294669685068527 * f[(i + 4) * fsi] - 0.0033581726798793 * f[(i + 5) * fsi];
      f3 =
	+0.00335817267987931 * f[(i - 3) * fsi] - 0.0340169068138972 * f[(i - 2) * fsi] +
	0.177019528362583 * f[(i - 1) * fsi] + 1.08874808117728 * f[(i + 0) * fsi] -
	0.319478686347356 * f[(i + 1) * fsi] + 0.105847235365367 * f[(i + 2) * fsi] -
	0.024079011491679 * f[(i + 3) * fsi] + 0.0026015870678183 * f[(i + 4) * fsi];
      f4 =
	-0.0026015870678183 * f[(i - 4) * fsi] + 0.0241708692224257 * f[(i - 3) * fsi] -
	0.10686134471281 * f[(i - 2) * fsi] + 0.322708404160407 * f[(i - 1) * fsi] +
	0.906636986430004 * f[(i + 0) * fsi] - 0.173789810549532 * f[(i + 1) * fsi] +
	0.0330027974664546 * f[(i + 2) * fsi] - 0.00326631494913269 * f[(i + 3) * fsi];
      f5 =
	+0.00326631494913269 * f[(i - 5) * fsi] - 0.0287321066608798 * f[(i - 4) * fsi] +
	0.115627687798141 * f[(i - 3) * fsi] - 0.28977498186424 * f[(i - 2) * fsi] +
	0.551350450599695 * f[(i - 1) * fsi] + 0.723723349278574 * f[(i + 0) * fsi] -
	0.0823329919738165 * f[(i + 1) * fsi] + 0.00687227787339307 * f[(i + 2) * fsi];
      f6 =
	-0.00687227787339308 * f[(i - 6) * fsi] + 0.0582445379362773 * f[(i - 5) * fsi] -
	0.221155887115886 * f[(i - 4) * fsi] + 0.500475248708153 * f[(i - 3) * fsi] -
	0.770834433001755 * f[(i - 2) * fsi] + 0.936198011509707 * f[(i - 1) * fsi] +
	0.531299568823568 * f[(i + 0) * fsi] - 0.0273547689866719 * f[(i + 1) * fsi];
      f7 =
	+0.0273547689866719 * f[(i - 7) * fsi] - 0.225710429766768 * f[(i - 6) * fsi] +
	0.824178069563091 * f[(i - 5) * fsi] - 1.75302295036951 * f[(i - 4) * fsi] +
	2.41530907777519 * f[(i - 3) * fsi] - 2.30270149625538 * f[(i - 2) * fsi] +
	1.70213154313652 * f[(i - 1) * fsi] + 0.312461416930193 * f[(i + 0) * fsi];
      f8 =
	+0.312461416930193 * f[(i + 0) * fsi] + 1.70213154313652 * f[(i + 1) * fsi] -
	2.30270149625538 * f[(i + 2) * fsi] + 2.41530907777519 * f[(i + 3) * fsi] -
	1.75302295036951 * f[(i + 4) * fsi] + 0.82417806956309 * f[(i + 5) * fsi] -
	0.225710429766769 * f[(i + 6) * fsi] + 0.0273547689866719 * f[(i + 7) * fsi];
      f9 =
	-0.0273547689866719 * f[(i - 1) * fsi] + 0.531299568823568 * f[(i + 0) * fsi] +
	0.936198011509708 * f[(i + 1) * fsi] - 0.770834433001755 * f[(i + 2) * fsi] +
	0.500475248708153 * f[(i + 3) * fsi] - 0.221155887115886 * f[(i + 4) * fsi] +
	0.0582445379362773 * f[(i + 5) * fsi] - 0.00687227787339308 * f[(i + 6) * fsi];
      f10 =
	+0.00687227787339308 * f[(i - 2) * fsi] - 0.0823329919738164 * f[(i - 1) * fsi] +
	0.723723349278574 * f[(i + 0) * fsi] + 0.551350450599696 * f[(i + 1) * fsi] -
	0.28977498186424 * f[(i + 2) * fsi] + 0.115627687798141 * f[(i + 3) * fsi] -
	0.0287321066608798 * f[(i + 4) * fsi] + 0.00326631494913269 * f[(i + 5) * fsi];
      f11 =
	-0.00326631494913269 * f[(i - 3) * fsi] + 0.0330027974664546 * f[(i - 2) * fsi] -
	0.173789810549532 * f[(i - 1) * fsi] + 0.906636986430004 * f[(i + 0) * fsi] +
	0.322708404160408 * f[(i + 1) * fsi] - 0.10686134471281 * f[(i + 2) * fsi] +
	0.0241708692224257 * f[(i + 3) * fsi] - 0.0026015870678183 * f[(i + 4) * fsi];
      f12 =
	+0.0026015870678183 * f[(i - 4) * fsi] - 0.024079011491679 * f[(i - 3) * fsi] +
	0.105847235365367 * f[(i - 2) * fsi] - 0.319478686347356 * f[(i - 1) * fsi] +
	1.08874808117729 * f[(i + 0) * fsi] + 0.177019528362583 * f[(i + 1) * fsi] -
	0.0340169068138972 * f[(i + 2) * fsi] + 0.00335817267987931 * f[(i + 3) * fsi];
      f13 =
	-0.00335817267987931 * f[(i - 5) * fsi] + 0.0294669685068528 * f[(i - 4) * fsi] -
	0.1181078465283 * f[(i - 3) * fsi] + 0.293904905438608 * f[(i - 2) * fsi] -
	0.554550773938908 * f[(i - 1) * fsi] + 1.27680575125053 * f[(i + 0) * fsi] +
	0.0829906933259623 * f[(i + 1) * fsi] - 0.0071515253748628 * f[(i + 2) * fsi];
      f14 =
	+0.0071515253748628 * f[(i - 6) * fsi] - 0.0605703756787817 * f[(i - 5) * fsi] +
	0.229709679003011 * f[(i - 4) * fsi] - 0.518593267520616 * f[(i - 3) * fsi] +
	0.794511681679004 * f[(i - 2) * fsi] - 0.955036194931224 * f[(i - 1) * fsi] +
	1.47704846174668 * f[(i + 0) * fsi] + 0.0257784903270599 * f[(i + 1) * fsi];
      f15 =
	-0.0257784903270599 * f[(i - 7) * fsi] + 0.213379447991342 * f[(i - 6) * fsi] -
	0.78236810483646 * f[(i - 5) * fsi] + 1.67330513731837 * f[(i - 4) * fsi] -
	2.32308759041481 * f[(i - 3) * fsi] + 2.23810713999436 * f[(i - 2) * fsi] -
	1.6768339240889 * f[(i - 1) * fsi] + 1.68327638436316 * f[(i + 0) * fsi];
      fr0 =
	f0 * omega0 + f1 * omega1 + f2 * omega2 + f3 * omega3 + f4 * omega4 + f5 * omega5 +
	f6 * omega6 + f7 * omega7;
      fr1 =
	f8 * omega8 + f9 * omega9 + f10 * omega10 + f11 * omega11 + f12 * omega12 + f13 * omega13 +
	f14 * omega14 + f15 * omega15;
      fr[i * frsi + 0 * frsl] = fr0;
      fr[i * frsi + 1 * frsl] = fr1;
    }
}

PyObject *
py_gauss_legendre008002 (PyObject * self, PyObject * args)
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

  gauss_legendre008002 (f, n, fsi, sigma, ssi, ssr, fr, frsi, frsl);

  Py_INCREF (Py_None);
  return Py_None;
}
