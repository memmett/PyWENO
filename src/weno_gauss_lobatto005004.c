#include <Python.h>
#include <numpy/ndarrayobject.h>

void
weights_gauss_lobatto005004 (const double *restrict sigma, int n, int ssi, int ssr,
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
      omega0 = (+0.00793650793650794) / ((sigma0 + 1.0e-6) * (sigma0 + 1.0e-6));
      acc = acc + omega0;
      omega1 = (+0.158730158730159) / ((sigma1 + 1.0e-6) * (sigma1 + 1.0e-6));
      acc = acc + omega1;
      omega2 = (+0.476190476190476) / ((sigma2 + 1.0e-6) * (sigma2 + 1.0e-6));
      acc = acc + omega2;
      omega3 = (+0.317460317460317) / ((sigma3 + 1.0e-6) * (sigma3 + 1.0e-6));
      acc = acc + omega3;
      omega4 = (+0.0396825396825397) / ((sigma4 + 1.0e-6) * (sigma4 + 1.0e-6));
      acc = acc + omega4;
      omega0 = (omega0) / (acc);
      omega1 = (omega1) / (acc);
      omega2 = (omega2) / (acc);
      omega3 = (omega3) / (acc);
      omega4 = (omega4) / (acc);
      acc = 0.0;
      omega5 = (+0.0367116276224507) / ((sigma0 + 1.0e-6) * (sigma0 + 1.0e-6));
      acc = acc + omega5;
      omega6 = (+0.26120990820049) / ((sigma1 + 1.0e-6) * (sigma1 + 1.0e-6));
      acc = acc + omega6;
      omega7 = (+0.475093641926041) / ((sigma2 + 1.0e-6) * (sigma2 + 1.0e-6));
      acc = acc + omega7;
      omega8 = (+0.210036042987715) / ((sigma3 + 1.0e-6) * (sigma3 + 1.0e-6));
      acc = acc + omega8;
      omega9 = (+0.016948779263303) / ((sigma4 + 1.0e-6) * (sigma4 + 1.0e-6));
      acc = acc + omega9;
      omega5 = (omega5) / (acc);
      omega6 = (omega6) / (acc);
      omega7 = (omega7) / (acc);
      omega8 = (omega8) / (acc);
      omega9 = (omega9) / (acc);
      acc = 0.0;
      omega10 = (+0.0169487792633063) / ((sigma0 + 1.0e-6) * (sigma0 + 1.0e-6));
      acc = acc + omega10;
      omega11 = (+0.210036042987713) / ((sigma1 + 1.0e-6) * (sigma1 + 1.0e-6));
      acc = acc + omega11;
      omega12 = (+0.475093641926044) / ((sigma2 + 1.0e-6) * (sigma2 + 1.0e-6));
      acc = acc + omega12;
      omega13 = (+0.261209908200482) / ((sigma3 + 1.0e-6) * (sigma3 + 1.0e-6));
      acc = acc + omega13;
      omega14 = (+0.0367116276224561) / ((sigma4 + 1.0e-6) * (sigma4 + 1.0e-6));
      acc = acc + omega14;
      omega10 = (omega10) / (acc);
      omega11 = (omega11) / (acc);
      omega12 = (omega12) / (acc);
      omega13 = (omega13) / (acc);
      omega14 = (omega14) / (acc);
      acc = 0.0;
      omega15 = (+0.0396825396825571) / ((sigma0 + 1.0e-6) * (sigma0 + 1.0e-6));
      acc = acc + omega15;
      omega16 = (+0.3174603174603) / ((sigma1 + 1.0e-6) * (sigma1 + 1.0e-6));
      acc = acc + omega16;
      omega17 = (+0.476190476190482) / ((sigma2 + 1.0e-6) * (sigma2 + 1.0e-6));
      acc = acc + omega17;
      omega18 = (+0.158730158730158) / ((sigma3 + 1.0e-6) * (sigma3 + 1.0e-6));
      acc = acc + omega18;
      omega19 = (+0.00793650793650794) / ((sigma4 + 1.0e-6) * (sigma4 + 1.0e-6));
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
py_weights_gauss_lobatto005004 (PyObject * self, PyObject * args)
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

  weights_gauss_lobatto005004 (sigma, n, ssi, ssr, omega, wsi, wsl, wsr);

  Py_INCREF (Py_None);
  return Py_None;
}

void
reconstruct_gauss_lobatto005004 (const double *restrict f, int n, int fsi,
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
	(+2.28333333333333) * (f[(i + 0) * fsi]) + (-2.71666666666667) * (f[(i + 1) * fsi]) +
	(+2.28333333333333) * (f[(i + 2) * fsi]) + (-1.05) * (f[(i + 3) * fsi]) +
	(+0.2) * (f[(i + 4) * fsi]);
      fr1 =
	(+0.2) * (f[(i - 1) * fsi]) + (+1.28333333333333) * (f[(i + 0) * fsi]) +
	(-0.716666666666667) * (f[(i + 1) * fsi]) + (+0.283333333333333) * (f[(i + 2) * fsi]) +
	(-0.05) * (f[(i + 3) * fsi]);
      fr2 =
	(-0.05) * (f[(i - 2) * fsi]) + (+0.45) * (f[(i - 1) * fsi]) +
	(+0.783333333333333) * (f[(i + 0) * fsi]) + (-0.216666666666667) * (f[(i + 1) * fsi]) +
	(+0.0333333333333333) * (f[(i + 2) * fsi]);
      fr3 =
	(+0.0333333333333333) * (f[(i - 3) * fsi]) + (-0.216666666666667) * (f[(i - 2) * fsi]) +
	(+0.783333333333333) * (f[(i - 1) * fsi]) + (+0.45) * (f[(i + 0) * fsi]) +
	(-0.05) * (f[(i + 1) * fsi]);
      fr4 =
	(-0.05) * (f[(i - 4) * fsi]) + (+0.283333333333333) * (f[(i - 3) * fsi]) +
	(-0.716666666666667) * (f[(i - 2) * fsi]) + (+1.28333333333333) * (f[(i - 1) * fsi]) +
	(+0.2) * (f[(i + 0) * fsi]);
      fr5 =
	(+1.39888026216662) * (f[(i + 0) * fsi]) + (-0.684011818341589) * (f[(i + 1) * fsi]) +
	(+0.424711007483278) * (f[(i + 2) * fsi]) + (-0.16930081085831) * (f[(i + 3) * fsi]) +
	(+0.0297213595499958) * (f[(i + 4) * fsi]);
      fr6 =
	(+0.0297213595499958) * (f[(i - 1) * fsi]) + (+1.25027346441665) * (f[(i + 0) * fsi]) +
	(-0.386798222841631) * (f[(i + 1) * fsi]) + (+0.127497411983321) * (f[(i + 2) * fsi]) +
	(-0.0206940131083312) * (f[(i + 3) * fsi]);
      fr7 =
	(-0.0206940131083312) * (f[(i - 2) * fsi]) + (+0.133191425091652) * (f[(i - 1) * fsi]) +
	(+1.04333333333333) * (f[(i + 0) * fsi]) + (-0.179858091758319) * (f[(i + 1) * fsi]) +
	(+0.0240273464416646) * (f[(i + 2) * fsi]);
      fr8 =
	(+0.0240273464416646) * (f[(i - 3) * fsi]) + (-0.140830745316654) * (f[(i - 2) * fsi]) +
	(+0.373464889508297) * (f[(i - 1) * fsi]) + (+0.803059868916688) * (f[(i + 0) * fsi]) +
	(-0.0597213595499958) * (f[(i + 1) * fsi]);
      fr9 =
	(-0.0597213595499958) * (f[(i - 4) * fsi]) + (+0.322634144191643) * (f[(i - 3) * fsi]) +
	(-0.738044340816612) * (f[(i - 2) * fsi]) + (+0.970678485008255) * (f[(i - 1) * fsi]) +
	(+0.504453071166709) * (f[(i + 0) * fsi]);
      fr10 =
	(+0.504453071166708) * (f[(i + 0) * fsi]) + (+0.970678485008256) * (f[(i + 1) * fsi]) +
	(-0.738044340816613) * (f[(i + 2) * fsi]) + (+0.322634144191644) * (f[(i + 3) * fsi]) +
	(-0.0597213595499959) * (f[(i + 4) * fsi]);
      fr11 =
	(-0.0597213595499959) * (f[(i - 1) * fsi]) + (+0.803059868916688) * (f[(i + 0) * fsi]) +
	(+0.373464889508297) * (f[(i + 1) * fsi]) + (-0.140830745316654) * (f[(i + 2) * fsi]) +
	(+0.0240273464416646) * (f[(i + 3) * fsi]);
      fr12 =
	(+0.0240273464416646) * (f[(i - 2) * fsi]) + (-0.179858091758319) * (f[(i - 1) * fsi]) +
	(+1.04333333333333) * (f[(i + 0) * fsi]) + (+0.133191425091652) * (f[(i + 1) * fsi]) +
	(-0.0206940131083312) * (f[(i + 2) * fsi]);
      fr13 =
	(-0.0206940131083312) * (f[(i - 3) * fsi]) + (+0.127497411983321) * (f[(i - 2) * fsi]) +
	(-0.386798222841631) * (f[(i - 1) * fsi]) + (+1.25027346441665) * (f[(i + 0) * fsi]) +
	(+0.0297213595499958) * (f[(i + 1) * fsi]);
      fr14 =
	(+0.0297213595499958) * (f[(i - 4) * fsi]) + (-0.16930081085831) * (f[(i - 3) * fsi]) +
	(+0.424711007483278) * (f[(i - 2) * fsi]) + (-0.684011818341589) * (f[(i - 1) * fsi]) +
	(+1.39888026216662) * (f[(i + 0) * fsi]);
      fr15 =
	(+0.2) * (f[(i + 0) * fsi]) + (+1.28333333333333) * (f[(i + 1) * fsi]) +
	(-0.716666666666667) * (f[(i + 2) * fsi]) + (+0.283333333333334) * (f[(i + 3) * fsi]) +
	(-0.05) * (f[(i + 4) * fsi]);
      fr16 =
	(-0.05) * (f[(i - 1) * fsi]) + (+0.45) * (f[(i + 0) * fsi]) +
	(+0.783333333333333) * (f[(i + 1) * fsi]) + (-0.216666666666667) * (f[(i + 2) * fsi]) +
	(+0.0333333333333333) * (f[(i + 3) * fsi]);
      fr17 =
	(+0.0333333333333333) * (f[(i - 2) * fsi]) + (-0.216666666666667) * (f[(i - 1) * fsi]) +
	(+0.783333333333333) * (f[(i + 0) * fsi]) + (+0.45) * (f[(i + 1) * fsi]) +
	(-0.05) * (f[(i + 2) * fsi]);
      fr18 =
	(-0.05) * (f[(i - 3) * fsi]) + (+0.283333333333333) * (f[(i - 2) * fsi]) +
	(-0.716666666666667) * (f[(i - 1) * fsi]) + (+1.28333333333333) * (f[(i + 0) * fsi]) +
	(+0.2) * (f[(i + 1) * fsi]);
      fr19 =
	(+0.2) * (f[(i - 4) * fsi]) + (-1.05) * (f[(i - 3) * fsi]) +
	(+2.28333333333333) * (f[(i - 2) * fsi]) + (-2.71666666666667) * (f[(i - 1) * fsi]) +
	(+2.28333333333333) * (f[(i + 0) * fsi]);
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
py_reconstruct_gauss_lobatto005004 (PyObject * self, PyObject * args)
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

  reconstruct_gauss_lobatto005004 (f, n, fsi, omega, wsi, wsl, wsr, fr, frsi, frsl);

  Py_INCREF (Py_None);
  return Py_None;
}
