#include <Python.h>
#include <numpy/ndarrayobject.h>

void
weights_gauss_legendre005004 (const double *restrict sigma, int n, int ssi, int ssr,
			      double *restrict omega, int wsi, int wsl, int wsr)
{
  int i;
  double acc, sigma0, sigma1, sigma2, sigma3, sigma4, omega1, omega7, omega17, omega0, omega16,
    omega18, omega15, omega12, omega6, omega9, omega2, omega10, omega8, omega13, omega11, omega4,
    omega14, omega3, omega19, omega5;
  for (i = 5; i < n - 5; i++)
    {
      sigma0 = sigma[i * ssi + 0 * ssr];
      sigma1 = sigma[i * ssi + 1 * ssr];
      sigma2 = sigma[i * ssi + 2 * ssr];
      sigma3 = sigma[i * ssi + 3 * ssr];
      sigma4 = sigma[i * ssi + 4 * ssr];
      acc = 0.0;
      omega0 = (+0.010630651148362) / ((sigma0 + 1.0e-6) * (sigma0 + 1.0e-6));
      acc = acc + omega0;
      omega1 = (+0.179167577658586) / ((sigma1 + 1.0e-6) * (sigma1 + 1.0e-6));
      acc = acc + omega1;
      omega2 = (+0.483459762131398) / ((sigma2 + 1.0e-6) * (sigma2 + 1.0e-6));
      acc = acc + omega2;
      omega3 = (+0.293650623488538) / ((sigma3 + 1.0e-6) * (sigma3 + 1.0e-6));
      acc = acc + omega3;
      omega4 = (+0.0330913855731154) / ((sigma4 + 1.0e-6) * (sigma4 + 1.0e-6));
      acc = acc + omega4;
      omega0 = (omega0) / (acc);
      omega1 = (omega1) / (acc);
      omega2 = (omega2) / (acc);
      omega3 = (omega3) / (acc);
      omega4 = (omega4) / (acc);
      acc = 0.0;
      omega5 = (+0.101473103447751) / ((sigma0 + 1.0e-6) * (sigma0 + 1.0e-6));
      acc = acc + omega5;
      omega6 = (+0.257732091726853) / ((sigma1 + 1.0e-6) * (sigma1 + 1.0e-6));
      acc = acc + omega6;
      omega7 = (+0.44874785056413) / ((sigma2 + 1.0e-6) * (sigma2 + 1.0e-6));
      acc = acc + omega7;
      omega8 = (+0.178996637781607) / ((sigma3 + 1.0e-6) * (sigma3 + 1.0e-6));
      acc = acc + omega8;
      omega9 = (+0.0130503164796584) / ((sigma4 + 1.0e-6) * (sigma4 + 1.0e-6));
      acc = acc + omega9;
      omega5 = (omega5) / (acc);
      omega6 = (omega6) / (acc);
      omega7 = (omega7) / (acc);
      omega8 = (omega8) / (acc);
      omega9 = (omega9) / (acc);
      acc = 0.0;
      omega10 = (+0.0130503164796628) / ((sigma0 + 1.0e-6) * (sigma0 + 1.0e-6));
      acc = acc + omega10;
      omega11 = (+0.178996637781601) / ((sigma1 + 1.0e-6) * (sigma1 + 1.0e-6));
      acc = acc + omega11;
      omega12 = (+0.448747850564132) / ((sigma2 + 1.0e-6) * (sigma2 + 1.0e-6));
      acc = acc + omega12;
      omega13 = (+0.257732091726865) / ((sigma3 + 1.0e-6) * (sigma3 + 1.0e-6));
      acc = acc + omega13;
      omega14 = (+0.10147310344774) / ((sigma4 + 1.0e-6) * (sigma4 + 1.0e-6));
      acc = acc + omega14;
      omega10 = (omega10) / (acc);
      omega11 = (omega11) / (acc);
      omega12 = (omega12) / (acc);
      omega13 = (omega13) / (acc);
      omega14 = (omega14) / (acc);
      acc = 0.0;
      omega15 = (+0.0330913855731134) / ((sigma0 + 1.0e-6) * (sigma0 + 1.0e-6));
      acc = acc + omega15;
      omega16 = (+0.293650623488536) / ((sigma1 + 1.0e-6) * (sigma1 + 1.0e-6));
      acc = acc + omega16;
      omega17 = (+0.483459762131401) / ((sigma2 + 1.0e-6) * (sigma2 + 1.0e-6));
      acc = acc + omega17;
      omega18 = (+0.179167577658586) / ((sigma3 + 1.0e-6) * (sigma3 + 1.0e-6));
      acc = acc + omega18;
      omega19 = (+0.0106306511483619) / ((sigma4 + 1.0e-6) * (sigma4 + 1.0e-6));
      acc = acc + omega19;
      omega15 = (omega15) / (acc);
      omega16 = (omega16) / (acc);
      omega17 = (omega17) / (acc);
      omega18 = (omega18) / (acc);
      omega19 = (omega19) / (acc);
      omega[i * wsi + 0 * wsl + 0 * wsr + 0] = omega0;
      omega[i * wsi + 0 * wsl + 1 * wsr + 0] = omega1;
      omega[i * wsi + 0 * wsl + 2 * wsr + 0] = omega2;
      omega[i * wsi + 0 * wsl + 3 * wsr + 0] = omega3;
      omega[i * wsi + 0 * wsl + 4 * wsr + 0] = omega4;
      omega[i * wsi + 1 * wsl + 0 * wsr + 0] = omega5;
      omega[i * wsi + 1 * wsl + 1 * wsr + 0] = omega6;
      omega[i * wsi + 1 * wsl + 2 * wsr + 0] = omega7;
      omega[i * wsi + 1 * wsl + 3 * wsr + 0] = omega8;
      omega[i * wsi + 1 * wsl + 4 * wsr + 0] = omega9;
      omega[i * wsi + 2 * wsl + 0 * wsr + 0] = omega10;
      omega[i * wsi + 2 * wsl + 1 * wsr + 0] = omega11;
      omega[i * wsi + 2 * wsl + 2 * wsr + 0] = omega12;
      omega[i * wsi + 2 * wsl + 3 * wsr + 0] = omega13;
      omega[i * wsi + 2 * wsl + 4 * wsr + 0] = omega14;
      omega[i * wsi + 3 * wsl + 0 * wsr + 0] = omega15;
      omega[i * wsi + 3 * wsl + 1 * wsr + 0] = omega16;
      omega[i * wsi + 3 * wsl + 2 * wsr + 0] = omega17;
      omega[i * wsi + 3 * wsl + 3 * wsr + 0] = omega18;
      omega[i * wsi + 3 * wsl + 4 * wsr + 0] = omega19;
    }
}

PyObject *
py_weights_gauss_legendre005004 (PyObject * self, PyObject * args)
{
  double *sigma, *omega;
  PyArrayObject *sigma_py, *omega_py;

  long int n;
  int ssi, ssr, wsi, wsl, wsr;

  /* parse options */

  if (!PyArg_ParseTuple (args, "OO", &sigma_py, &omega_py))
    return NULL;

  if (sigma_py->nd != 2 || sigma_py->descr->type_num != PyArray_DOUBLE)
    {
      PyErr_SetString (PyExc_ValueError, "sigma must be two-dimensional and of type float");
      return NULL;
    }

  if (omega_py->descr->type_num != PyArray_DOUBLE)
    {
      PyErr_SetString (PyExc_ValueError, "omega must be of type float");
      return NULL;
    }

  if (!(omega_py->nd >= 2 && omega_py->nd <= 4))
    {
      PyErr_SetString (PyExc_ValueError, "omega must be two, three, or four dimensional");
      return NULL;
    }

  /* get data, n, strides */
  sigma = (double *) PyArray_DATA (sigma_py);
  omega = (double *) PyArray_DATA (omega_py);

  n = PyArray_DIM (omega_py, 0);

  ssi = sigma_py->strides[0] / sizeof (double);
  ssr = sigma_py->strides[1] / sizeof (double);

  wsi = omega_py->strides[0] / sizeof (double);
  if (omega_py->nd == 3)
    {
      wsl = omega_py->strides[1] / sizeof (double);
      wsr = omega_py->strides[2] / sizeof (double);
    }
  else
    {
      wsl = 0;
      wsr = omega_py->strides[1] / sizeof (double);
    }

  weights_gauss_legendre005004 (sigma, n, ssi, ssr, omega, wsi, wsl, wsr);

  Py_INCREF (Py_None);
  return Py_None;
}

void
reconstruct_gauss_legendre005004 (const double *restrict f, int n, int fsi,
				  const double *restrict omega, int wsi, int wsl, int wsr,
				  double *restrict fr, int frsi, int frsl)
{
  int i;
  double omega1, omega7, omega17, omega0, omega16, omega18, omega15, omega12, omega6, omega9,
    omega2, omega10, omega8, omega13, omega11, omega4, omega14, omega3, omega19, omega5, fs0, fs1,
    fs2, fs3, fr1, fr7, fr17, fr0, fr16, fr18, fr15, fr12, fr6, fr9, fr2, fr10, fr8, fr13, fr11,
    fr4, fr14, fr3, fr19, fr5;
  for (i = 5; i < n - 5; i++)
    {
      omega0 = omega[i * wsi + 0 * wsl + 0 * wsr + 0];
      omega1 = omega[i * wsi + 0 * wsl + 1 * wsr + 0];
      omega2 = omega[i * wsi + 0 * wsl + 2 * wsr + 0];
      omega3 = omega[i * wsi + 0 * wsl + 3 * wsr + 0];
      omega4 = omega[i * wsi + 0 * wsl + 4 * wsr + 0];
      omega5 = omega[i * wsi + 1 * wsl + 0 * wsr + 0];
      omega6 = omega[i * wsi + 1 * wsl + 1 * wsr + 0];
      omega7 = omega[i * wsi + 1 * wsl + 2 * wsr + 0];
      omega8 = omega[i * wsi + 1 * wsl + 3 * wsr + 0];
      omega9 = omega[i * wsi + 1 * wsl + 4 * wsr + 0];
      omega10 = omega[i * wsi + 2 * wsl + 0 * wsr + 0];
      omega11 = omega[i * wsi + 2 * wsl + 1 * wsr + 0];
      omega12 = omega[i * wsi + 2 * wsl + 2 * wsr + 0];
      omega13 = omega[i * wsi + 2 * wsl + 3 * wsr + 0];
      omega14 = omega[i * wsi + 2 * wsl + 4 * wsr + 0];
      omega15 = omega[i * wsi + 3 * wsl + 0 * wsr + 0];
      omega16 = omega[i * wsi + 3 * wsl + 1 * wsr + 0];
      omega17 = omega[i * wsi + 3 * wsl + 2 * wsr + 0];
      omega18 = omega[i * wsi + 3 * wsl + 3 * wsr + 0];
      omega19 = omega[i * wsi + 3 * wsl + 4 * wsr + 0];
      fr0 =
	(+2.0330416876478) * (f[(i + 0) * fsi]) + (-2.11792458134642) * (f[(i + 1) * fsi]) +
	(+1.71353996516857) * (f[(i + 2) * fsi]) + (-0.774904781092089) * (f[(i + 3) * fsi]) +
	(+0.146247709622128) * (f[(i + 4) * fsi]);
      fr1 =
	(+0.146247709622128) * (f[(i - 1) * fsi]) + (+1.30180313953717) * (f[(i + 0) * fsi]) +
	(-0.655447485125139) * (f[(i + 1) * fsi]) + (+0.251062868947296) * (f[(i + 2) * fsi]) +
	(-0.0436662329814502) * (f[(i + 3) * fsi]);
      fr2 =
	(-0.0436662329814502) * (f[(i - 2) * fsi]) + (+0.364578874529379) * (f[(i - 1) * fsi]) +
	(+0.865140809722664) * (f[(i + 0) * fsi]) + (-0.218785155310637) * (f[(i + 1) * fsi]) +
	(+0.0327317040400446) * (f[(i + 2) * fsi]);
      fr3 =
	(+0.0327317040400446) * (f[(i - 3) * fsi]) + (-0.207324753181673) * (f[(i - 2) * fsi]) +
	(+0.691895914929824) * (f[(i - 1) * fsi]) + (+0.537823769322218) * (f[(i + 0) * fsi]) +
	(-0.0551266351104143) * (f[(i + 1) * fsi]);
      fr4 =
	(-0.0551266351104143) * (f[(i - 4) * fsi]) + (+0.308364879592116) * (f[(i - 3) * fsi]) +
	(-0.758591104285816) * (f[(i - 2) * fsi]) + (+1.24316226603397) * (f[(i - 1) * fsi]) +
	(+0.262190593770147) * (f[(i + 0) * fsi]);
      fr5 =
	(+1.25974772564445) * (f[(i + 0) * fsi]) + (-0.390284383922218) * (f[(i + 1) * fsi]) +
	(+0.180115346256389) * (f[(i + 2) * fsi]) + (-0.058377921531515) * (f[(i + 3) * fsi]) +
	(+0.00879923355288892) * (f[(i + 4) * fsi]);
      fr6 =
	(+0.00879923355288892) * (f[(i - 1) * fsi]) + (+1.21575155788001) * (f[(i + 0) * fsi]) +
	(-0.302292048393328) * (f[(i + 1) * fsi]) + (+0.0921230107274998) * (f[(i + 2) * fsi]) +
	(-0.0143817537670701) * (f[(i + 3) * fsi]);
      fr7 =
	(-0.0143817537670701) * (f[(i - 2) * fsi]) + (+0.0807080023882396) * (f[(i - 1) * fsi]) +
	(+1.07193402020931) * (f[(i + 0) * fsi]) + (-0.158474510722627) * (f[(i + 1) * fsi]) +
	(+0.0202142418921492) * (f[(i + 2) * fsi]);
      fr8 =
	(+0.0202142418921492) * (f[(i - 3) * fsi]) + (-0.115452963227816) * (f[(i - 2) * fsi]) +
	(+0.282850421309731) * (f[(i - 1) * fsi]) + (+0.869791601287817) * (f[(i + 0) * fsi]) +
	(-0.0574033012618812) * (f[(i + 1) * fsi]);
      fr9 =
	(-0.0574033012618812) * (f[(i - 4) * fsi]) + (+0.307230748201555) * (f[(i - 3) * fsi]) +
	(-0.689485975846628) * (f[(i - 2) * fsi]) + (+0.856883433928544) * (f[(i - 1) * fsi]) +
	(+0.582775094978411) * (f[(i + 0) * fsi]);
      fr10 =
	(+0.582775094978411) * (f[(i + 0) * fsi]) + (+0.856883433928545) * (f[(i + 1) * fsi]) +
	(-0.689485975846628) * (f[(i + 2) * fsi]) + (+0.307230748201555) * (f[(i + 3) * fsi]) +
	(-0.0574033012618812) * (f[(i + 4) * fsi]);
      fr11 =
	(-0.0574033012618812) * (f[(i - 1) * fsi]) + (+0.869791601287817) * (f[(i + 0) * fsi]) +
	(+0.282850421309732) * (f[(i + 1) * fsi]) + (-0.115452963227816) * (f[(i + 2) * fsi]) +
	(+0.0202142418921492) * (f[(i + 3) * fsi]);
      fr12 =
	(+0.0202142418921492) * (f[(i - 2) * fsi]) + (-0.158474510722627) * (f[(i - 1) * fsi]) +
	(+1.07193402020931) * (f[(i + 0) * fsi]) + (+0.0807080023882396) * (f[(i + 1) * fsi]) +
	(-0.0143817537670701) * (f[(i + 2) * fsi]);
      fr13 =
	(-0.0143817537670701) * (f[(i - 3) * fsi]) + (+0.0921230107274998) * (f[(i - 2) * fsi]) +
	(-0.302292048393329) * (f[(i - 1) * fsi]) + (+1.21575155788001) * (f[(i + 0) * fsi]) +
	(+0.00879923355288895) * (f[(i + 1) * fsi]);
      fr14 =
	(+0.00879923355288894) * (f[(i - 4) * fsi]) + (-0.0583779215315149) * (f[(i - 3) * fsi]) +
	(+0.180115346256389) * (f[(i - 2) * fsi]) + (-0.390284383922218) * (f[(i - 1) * fsi]) +
	(+1.25974772564445) * (f[(i + 0) * fsi]);
      fr15 =
	(+0.262190593770147) * (f[(i + 0) * fsi]) + (+1.24316226603397) * (f[(i + 1) * fsi]) +
	(-0.758591104285816) * (f[(i + 2) * fsi]) + (+0.308364879592116) * (f[(i + 3) * fsi]) +
	(-0.0551266351104144) * (f[(i + 4) * fsi]);
      fr16 =
	(-0.0551266351104143) * (f[(i - 1) * fsi]) + (+0.537823769322218) * (f[(i + 0) * fsi]) +
	(+0.691895914929824) * (f[(i + 1) * fsi]) + (-0.207324753181673) * (f[(i + 2) * fsi]) +
	(+0.0327317040400446) * (f[(i + 3) * fsi]);
      fr17 =
	(+0.0327317040400446) * (f[(i - 2) * fsi]) + (-0.218785155310637) * (f[(i - 1) * fsi]) +
	(+0.865140809722664) * (f[(i + 0) * fsi]) + (+0.364578874529379) * (f[(i + 1) * fsi]) +
	(-0.0436662329814502) * (f[(i + 2) * fsi]);
      fr18 =
	(-0.0436662329814502) * (f[(i - 3) * fsi]) + (+0.251062868947296) * (f[(i - 2) * fsi]) +
	(-0.655447485125139) * (f[(i - 1) * fsi]) + (+1.30180313953717) * (f[(i + 0) * fsi]) +
	(+0.146247709622128) * (f[(i + 1) * fsi]);
      fr19 =
	(+0.146247709622128) * (f[(i - 4) * fsi]) + (-0.774904781092088) * (f[(i - 3) * fsi]) +
	(+1.71353996516857) * (f[(i - 2) * fsi]) + (-2.11792458134642) * (f[(i - 1) * fsi]) +
	(+2.0330416876478) * (f[(i + 0) * fsi]);
      fs0 =
	(omega0) * (fr0) + (omega1) * (fr1) + (omega2) * (fr2) + (omega3) * (fr3) +
	(omega4) * (fr4);
      fs1 =
	(omega5) * (fr5) + (omega6) * (fr6) + (omega7) * (fr7) + (omega8) * (fr8) +
	(omega9) * (fr9);
      fs2 =
	(omega10) * (fr10) + (omega11) * (fr11) + (omega12) * (fr12) + (omega13) * (fr13) +
	(omega14) * (fr14);
      fs3 =
	(omega15) * (fr15) + (omega16) * (fr16) + (omega17) * (fr17) + (omega18) * (fr18) +
	(omega19) * (fr19);
      fr[i * frsi + 0 * frsl] = fs0;
      fr[i * frsi + 1 * frsl] = fs1;
      fr[i * frsi + 2 * frsl] = fs2;
      fr[i * frsi + 3 * frsl] = fs3;
    }
}

PyObject *
py_reconstruct_gauss_legendre005004 (PyObject * self, PyObject * args)
{
  double *f, *omega, *fr;
  PyArrayObject *f_py, *omega_py, *fr_py;

  long int n;
  int fsi, frsi, frsl, wsi, wsl, wsr;

  /* parse options */

  if (!PyArg_ParseTuple (args, "OOO", &f_py, &omega_py, &fr_py))
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

  if (omega_py->descr->type_num != PyArray_DOUBLE)
    {
      PyErr_SetString (PyExc_ValueError, "omega must be of type float");
      return NULL;
    }

  if (!(omega_py->nd >= 2 && omega_py->nd <= 4))
    {
      PyErr_SetString (PyExc_ValueError, "omega must be two, three, or four dimensional");
      return NULL;
    }

  /* get data, n, strides */
  f = (double *) PyArray_DATA (f_py);
  fr = (double *) PyArray_DATA (fr_py);
  omega = (double *) PyArray_DATA (omega_py);

  n = PyArray_DIM (omega_py, 0);

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

  wsi = omega_py->strides[0] / sizeof (double);
  if (omega_py->nd == 3)
    {
      wsl = omega_py->strides[1] / sizeof (double);
      wsr = omega_py->strides[2] / sizeof (double);
    }
  else
    {
      wsl = 0;
      wsr = omega_py->strides[1] / sizeof (double);
    }

  reconstruct_gauss_legendre005004 (f, n, fsi, omega, wsi, wsl, wsr, fr, frsi, frsl);

  Py_INCREF (Py_None);
  return Py_None;
}
