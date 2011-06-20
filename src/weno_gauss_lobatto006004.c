#include <Python.h>
#include <numpy/ndarrayobject.h>

void
weights_gauss_lobatto006004 (const double *restrict sigma, int n, int ssi, int ssr,
			     double *restrict omega, int wsi, int wsl, int wsr)
{
  int i;
  double acc, sigma0, sigma1, sigma2, sigma3, sigma4, sigma5, omega9, omega18, omega13, omega17,
    omega3, omega8, omega21, omega11, omega14, omega7, omega20, omega0, omega4, omega10, omega5,
    omega6, omega23, omega1, omega19, omega2, omega12, omega15, omega22, omega16;
  for (i = 6; i < n - 6; i++)
    {
      sigma0 = sigma[i * ssi + 0 * ssr];
      sigma1 = sigma[i * ssi + 1 * ssr];
      sigma2 = sigma[i * ssi + 2 * ssr];
      sigma3 = sigma[i * ssi + 3 * ssr];
      sigma4 = sigma[i * ssi + 4 * ssr];
      sigma5 = sigma[i * ssi + 5 * ssr];
      acc = 0.0;
      omega0 = (+0.00216450216450216) / ((sigma0 + 1.0e-6) * (sigma0 + 1.0e-6));
      acc = acc + omega0;
      omega1 = (+0.0649350649350649) / ((sigma1 + 1.0e-6) * (sigma1 + 1.0e-6));
      acc = acc + omega1;
      omega2 = (+0.324675324675325) / ((sigma2 + 1.0e-6) * (sigma2 + 1.0e-6));
      acc = acc + omega2;
      omega3 = (+0.432900432900433) / ((sigma3 + 1.0e-6) * (sigma3 + 1.0e-6));
      acc = acc + omega3;
      omega4 = (+0.162337662337662) / ((sigma4 + 1.0e-6) * (sigma4 + 1.0e-6));
      acc = acc + omega4;
      omega5 = (+0.012987012987013) / ((sigma5 + 1.0e-6) * (sigma5 + 1.0e-6));
      acc = acc + omega5;
      omega0 = (omega0) / (acc);
      omega1 = (omega1) / (acc);
      omega2 = (omega2) / (acc);
      omega3 = (omega3) / (acc);
      omega4 = (omega4) / (acc);
      omega5 = (omega5) / (acc);
      acc = 0.0;
      omega6 = (+0.0132261330023244) / ((sigma0 + 1.0e-6) * (sigma0 + 1.0e-6));
      acc = acc + omega6;
      omega7 = (+0.129546035259454) / ((sigma1 + 1.0e-6) * (sigma1 + 1.0e-6));
      acc = acc + omega7;
      omega8 = (+0.394975071855942) / ((sigma2 + 1.0e-6) * (sigma2 + 1.0e-6));
      acc = acc + omega8;
      omega9 = (+0.361662086804266) / ((sigma3 + 1.0e-6) * (sigma3 + 1.0e-6));
      acc = acc + omega9;
      omega10 = (+0.0954827459517227) / ((sigma4 + 1.0e-6) * (sigma4 + 1.0e-6));
      acc = acc + omega10;
      omega11 = (+0.00510792712629047) / ((sigma5 + 1.0e-6) * (sigma5 + 1.0e-6));
      acc = acc + omega11;
      omega6 = (omega6) / (acc);
      omega7 = (omega7) / (acc);
      omega8 = (omega8) / (acc);
      omega9 = (omega9) / (acc);
      omega10 = (omega10) / (acc);
      omega11 = (omega11) / (acc);
      acc = 0.0;
      omega12 = (+0.00510792712629423) / ((sigma0 + 1.0e-6) * (sigma0 + 1.0e-6));
      acc = acc + omega12;
      omega13 = (+0.0954827459517142) / ((sigma1 + 1.0e-6) * (sigma1 + 1.0e-6));
      acc = acc + omega13;
      omega14 = (+0.361662086804272) / ((sigma2 + 1.0e-6) * (sigma2 + 1.0e-6));
      acc = acc + omega14;
      omega15 = (+0.39497507185594) / ((sigma3 + 1.0e-6) * (sigma3 + 1.0e-6));
      acc = acc + omega15;
      omega16 = (+0.12954603525946) / ((sigma4 + 1.0e-6) * (sigma4 + 1.0e-6));
      acc = acc + omega16;
      omega17 = (+0.0132261330023188) / ((sigma5 + 1.0e-6) * (sigma5 + 1.0e-6));
      acc = acc + omega17;
      omega12 = (omega12) / (acc);
      omega13 = (omega13) / (acc);
      omega14 = (omega14) / (acc);
      omega15 = (omega15) / (acc);
      omega16 = (omega16) / (acc);
      omega17 = (omega17) / (acc);
      acc = 0.0;
      omega18 = (+0.0129870129869969) / ((sigma0 + 1.0e-6) * (sigma0 + 1.0e-6));
      acc = acc + omega18;
      omega19 = (+0.162337662337667) / ((sigma1 + 1.0e-6) * (sigma1 + 1.0e-6));
      acc = acc + omega19;
      omega20 = (+0.432900432900435) / ((sigma2 + 1.0e-6) * (sigma2 + 1.0e-6));
      acc = acc + omega20;
      omega21 = (+0.324675324675325) / ((sigma3 + 1.0e-6) * (sigma3 + 1.0e-6));
      acc = acc + omega21;
      omega22 = (+0.0649350649350649) / ((sigma4 + 1.0e-6) * (sigma4 + 1.0e-6));
      acc = acc + omega22;
      omega23 = (+0.00216450216450216) / ((sigma5 + 1.0e-6) * (sigma5 + 1.0e-6));
      acc = acc + omega23;
      omega18 = (omega18) / (acc);
      omega19 = (omega19) / (acc);
      omega20 = (omega20) / (acc);
      omega21 = (omega21) / (acc);
      omega22 = (omega22) / (acc);
      omega23 = (omega23) / (acc);
      omega[i * wsi + 0 * wsl + 0 * wsr + 0] = omega0;
      omega[i * wsi + 0 * wsl + 1 * wsr + 0] = omega1;
      omega[i * wsi + 0 * wsl + 2 * wsr + 0] = omega2;
      omega[i * wsi + 0 * wsl + 3 * wsr + 0] = omega3;
      omega[i * wsi + 0 * wsl + 4 * wsr + 0] = omega4;
      omega[i * wsi + 0 * wsl + 5 * wsr + 0] = omega5;
      omega[i * wsi + 1 * wsl + 0 * wsr + 0] = omega6;
      omega[i * wsi + 1 * wsl + 1 * wsr + 0] = omega7;
      omega[i * wsi + 1 * wsl + 2 * wsr + 0] = omega8;
      omega[i * wsi + 1 * wsl + 3 * wsr + 0] = omega9;
      omega[i * wsi + 1 * wsl + 4 * wsr + 0] = omega10;
      omega[i * wsi + 1 * wsl + 5 * wsr + 0] = omega11;
      omega[i * wsi + 2 * wsl + 0 * wsr + 0] = omega12;
      omega[i * wsi + 2 * wsl + 1 * wsr + 0] = omega13;
      omega[i * wsi + 2 * wsl + 2 * wsr + 0] = omega14;
      omega[i * wsi + 2 * wsl + 3 * wsr + 0] = omega15;
      omega[i * wsi + 2 * wsl + 4 * wsr + 0] = omega16;
      omega[i * wsi + 2 * wsl + 5 * wsr + 0] = omega17;
      omega[i * wsi + 3 * wsl + 0 * wsr + 0] = omega18;
      omega[i * wsi + 3 * wsl + 1 * wsr + 0] = omega19;
      omega[i * wsi + 3 * wsl + 2 * wsr + 0] = omega20;
      omega[i * wsi + 3 * wsl + 3 * wsr + 0] = omega21;
      omega[i * wsi + 3 * wsl + 4 * wsr + 0] = omega22;
      omega[i * wsi + 3 * wsl + 5 * wsr + 0] = omega23;
    }
}

PyObject *
py_weights_gauss_lobatto006004 (PyObject * self, PyObject * args)
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

  weights_gauss_lobatto006004 (sigma, n, ssi, ssr, omega, wsi, wsl, wsr);

  Py_INCREF (Py_None);
  return Py_None;
}

void
reconstruct_gauss_lobatto006004 (const double *restrict f, int n, int fsi,
				 const double *restrict omega, int wsi, int wsl, int wsr,
				 double *restrict fr, int frsi, int frsl)
{
  int i;
  double omega9, omega18, omega13, omega17, omega3, omega8, omega21, omega11, omega14, omega7,
    omega20, omega0, omega4, omega10, omega5, omega6, omega23, omega1, omega19, omega2, omega12,
    omega15, omega22, omega16, fs0, fs1, fs2, fs3, fr9, fr18, fr13, fr17, fr3, fr8, fr21, fr11,
    fr14, fr7, fr20, fr0, fr4, fr10, fr5, fr6, fr23, fr1, fr19, fr2, fr12, fr15, fr22, fr16;
  for (i = 6; i < n - 6; i++)
    {
      omega0 = omega[i * wsi + 0 * wsl + 0 * wsr + 0];
      omega1 = omega[i * wsi + 0 * wsl + 1 * wsr + 0];
      omega2 = omega[i * wsi + 0 * wsl + 2 * wsr + 0];
      omega3 = omega[i * wsi + 0 * wsl + 3 * wsr + 0];
      omega4 = omega[i * wsi + 0 * wsl + 4 * wsr + 0];
      omega5 = omega[i * wsi + 0 * wsl + 5 * wsr + 0];
      omega6 = omega[i * wsi + 1 * wsl + 0 * wsr + 0];
      omega7 = omega[i * wsi + 1 * wsl + 1 * wsr + 0];
      omega8 = omega[i * wsi + 1 * wsl + 2 * wsr + 0];
      omega9 = omega[i * wsi + 1 * wsl + 3 * wsr + 0];
      omega10 = omega[i * wsi + 1 * wsl + 4 * wsr + 0];
      omega11 = omega[i * wsi + 1 * wsl + 5 * wsr + 0];
      omega12 = omega[i * wsi + 2 * wsl + 0 * wsr + 0];
      omega13 = omega[i * wsi + 2 * wsl + 1 * wsr + 0];
      omega14 = omega[i * wsi + 2 * wsl + 2 * wsr + 0];
      omega15 = omega[i * wsi + 2 * wsl + 3 * wsr + 0];
      omega16 = omega[i * wsi + 2 * wsl + 4 * wsr + 0];
      omega17 = omega[i * wsi + 2 * wsl + 5 * wsr + 0];
      omega18 = omega[i * wsi + 3 * wsl + 0 * wsr + 0];
      omega19 = omega[i * wsi + 3 * wsl + 1 * wsr + 0];
      omega20 = omega[i * wsi + 3 * wsl + 2 * wsr + 0];
      omega21 = omega[i * wsi + 3 * wsl + 3 * wsr + 0];
      omega22 = omega[i * wsi + 3 * wsl + 4 * wsr + 0];
      omega23 = omega[i * wsi + 3 * wsl + 5 * wsr + 0];
      fr0 =
	(+2.45) * (f[(i + 0) * fsi]) + (-3.55) * (f[(i + 1) * fsi]) + (+3.95) * (f[(i + 2) * fsi]) +
	(-2.71666666666667) * (f[(i + 3) * fsi]) + (+1.03333333333333) * (f[(i + 4) * fsi]) +
	(-0.166666666666667) * (f[(i + 5) * fsi]);
      fr1 =
	(+0.166666666666667) * (f[(i - 1) * fsi]) + (+1.45) * (f[(i + 0) * fsi]) +
	(-1.05) * (f[(i + 1) * fsi]) + (+0.616666666666667) * (f[(i + 2) * fsi]) +
	(-0.216666666666667) * (f[(i + 3) * fsi]) + (+0.0333333333333333) * (f[(i + 4) * fsi]);
      fr2 =
	(-0.0333333333333333) * (f[(i - 2) * fsi]) + (+0.366666666666667) * (f[(i - 1) * fsi]) +
	(+0.95) * (f[(i + 0) * fsi]) + (-0.383333333333333) * (f[(i + 1) * fsi]) +
	(+0.116666666666667) * (f[(i + 2) * fsi]) + (-0.0166666666666667) * (f[(i + 3) * fsi]);
      fr3 =
	(+0.0166666666666667) * (f[(i - 3) * fsi]) + (-0.133333333333333) * (f[(i - 2) * fsi]) +
	(+0.616666666666667) * (f[(i - 1) * fsi]) + (+0.616666666666667) * (f[(i + 0) * fsi]) +
	(-0.133333333333333) * (f[(i + 1) * fsi]) + (+0.0166666666666667) * (f[(i + 2) * fsi]);
      fr4 =
	(-0.0166666666666667) * (f[(i - 4) * fsi]) + (+0.116666666666667) * (f[(i - 3) * fsi]) +
	(-0.383333333333333) * (f[(i - 2) * fsi]) + (+0.95) * (f[(i - 1) * fsi]) +
	(+0.366666666666667) * (f[(i + 0) * fsi]) + (-0.0333333333333333) * (f[(i + 1) * fsi]);
      fr5 =
	(+0.0333333333333333) * (f[(i - 5) * fsi]) + (-0.216666666666667) * (f[(i - 4) * fsi]) +
	(+0.616666666666667) * (f[(i - 3) * fsi]) + (-1.05) * (f[(i - 2) * fsi]) +
	(+1.45) * (f[(i - 1) * fsi]) + (+0.166666666666667) * (f[(i + 0) * fsi]);
      fr6 =
	(+1.41742332011254) * (f[(i + 0) * fsi]) + (-0.776727108071157) * (f[(i + 1) * fsi]) +
	(+0.610141586942415) * (f[(i + 2) * fsi]) + (-0.354731390317447) * (f[(i + 3) * fsi]) +
	(+0.122436649279564) * (f[(i + 4) * fsi]) + (-0.0185430579459137) * (f[(i + 5) * fsi]);
      fr7 =
	(+0.0185430579459137) * (f[(i - 1) * fsi]) + (+1.30616497243706) * (f[(i + 0) * fsi]) +
	(-0.498581238882452) * (f[(i + 1) * fsi]) + (+0.239280428024142) * (f[(i + 2) * fsi]) +
	(-0.0765855211287419) * (f[(i + 3) * fsi]) + (+0.0111783016040821) * (f[(i + 4) * fsi]);
      fr8 =
	(-0.0111783016040821) * (f[(i - 2) * fsi]) + (+0.0856128675704064) * (f[(i - 1) * fsi]) +
	(+1.13849044837582) * (f[(i + 0) * fsi]) + (-0.27501520680081) * (f[(i + 1) * fsi]) +
	(+0.0716059039629101) * (f[(i + 2) * fsi]) + (-0.0095157115042491) * (f[(i + 3) * fsi]);
      fr9 =
	(+0.00951571150424911) * (f[(i - 3) * fsi]) + (-0.0682725706295767) * (f[(i - 2) * fsi]) +
	(+0.228348540134143) * (f[(i - 1) * fsi]) + (+0.948176218290842) * (f[(i + 0) * fsi]) +
	(-0.132279534237073) * (f[(i + 1) * fsi]) + (+0.0145116349374155) * (f[(i + 2) * fsi]);
      fr10 =
	(-0.0145116349374155) * (f[(i - 4) * fsi]) + (+0.0965855211287419) * (f[(i - 3) * fsi]) +
	(-0.285947094690809) * (f[(i - 2) * fsi]) + (+0.518581238882452) * (f[(i - 1) * fsi]) +
	(+0.730501694229611) * (f[(i + 0) * fsi]) + (-0.0452097246125803) * (f[(i + 1) * fsi]);
      fr11 =
	(+0.0452097246125803) * (f[(i - 5) * fsi]) + (-0.285769982612897) * (f[(i - 4) * fsi]) +
	(+0.774731390317447) * (f[(i - 3) * fsi]) + (-1.19014158694242) * (f[(i - 2) * fsi]) +
	(+1.19672710807116) * (f[(i - 1) * fsi]) + (+0.459243346554128) * (f[(i + 0) * fsi]);
      fr12 =
	(+0.459243346554129) * (f[(i + 0) * fsi]) + (+1.19672710807116) * (f[(i + 1) * fsi]) +
	(-1.19014158694242) * (f[(i + 2) * fsi]) + (+0.774731390317446) * (f[(i + 3) * fsi]) +
	(-0.285769982612898) * (f[(i + 4) * fsi]) + (+0.0452097246125803) * (f[(i + 5) * fsi]);
      fr13 =
	(-0.0452097246125803) * (f[(i - 1) * fsi]) + (+0.730501694229611) * (f[(i + 0) * fsi]) +
	(+0.518581238882452) * (f[(i + 1) * fsi]) + (-0.285947094690808) * (f[(i + 2) * fsi]) +
	(+0.0965855211287418) * (f[(i + 3) * fsi]) + (-0.0145116349374155) * (f[(i + 4) * fsi]);
      fr14 =
	(+0.0145116349374154) * (f[(i - 2) * fsi]) + (-0.132279534237073) * (f[(i - 1) * fsi]) +
	(+0.948176218290842) * (f[(i + 0) * fsi]) + (+0.228348540134143) * (f[(i + 1) * fsi]) +
	(-0.0682725706295767) * (f[(i + 2) * fsi]) + (+0.0095157115042491) * (f[(i + 3) * fsi]);
      fr15 =
	(-0.0095157115042491) * (f[(i - 3) * fsi]) + (+0.0716059039629101) * (f[(i - 2) * fsi]) +
	(-0.27501520680081) * (f[(i - 1) * fsi]) + (+1.13849044837582) * (f[(i + 0) * fsi]) +
	(+0.0856128675704064) * (f[(i + 1) * fsi]) + (-0.0111783016040821) * (f[(i + 2) * fsi]);
      fr16 =
	(+0.0111783016040821) * (f[(i - 4) * fsi]) + (-0.0765855211287418) * (f[(i - 3) * fsi]) +
	(+0.239280428024142) * (f[(i - 2) * fsi]) + (-0.498581238882452) * (f[(i - 1) * fsi]) +
	(+1.30616497243706) * (f[(i + 0) * fsi]) + (+0.0185430579459137) * (f[(i + 1) * fsi]);
      fr17 =
	(-0.0185430579459137) * (f[(i - 5) * fsi]) + (+0.122436649279564) * (f[(i - 4) * fsi]) +
	(-0.354731390317447) * (f[(i - 3) * fsi]) + (+0.610141586942415) * (f[(i - 2) * fsi]) +
	(-0.776727108071157) * (f[(i - 1) * fsi]) + (+1.41742332011254) * (f[(i + 0) * fsi]);
      fr18 =
	(+0.166666666666667) * (f[(i + 0) * fsi]) + (+1.45) * (f[(i + 1) * fsi]) +
	(-1.05) * (f[(i + 2) * fsi]) + (+0.616666666666667) * (f[(i + 3) * fsi]) +
	(-0.216666666666667) * (f[(i + 4) * fsi]) + (+0.0333333333333332) * (f[(i + 5) * fsi]);
      fr19 =
	(-0.0333333333333333) * (f[(i - 1) * fsi]) + (+0.366666666666667) * (f[(i + 0) * fsi]) +
	(+0.95) * (f[(i + 1) * fsi]) + (-0.383333333333333) * (f[(i + 2) * fsi]) +
	(+0.116666666666667) * (f[(i + 3) * fsi]) + (-0.0166666666666667) * (f[(i + 4) * fsi]);
      fr20 =
	(+0.0166666666666667) * (f[(i - 2) * fsi]) + (-0.133333333333333) * (f[(i - 1) * fsi]) +
	(+0.616666666666666) * (f[(i + 0) * fsi]) + (+0.616666666666667) * (f[(i + 1) * fsi]) +
	(-0.133333333333333) * (f[(i + 2) * fsi]) + (+0.0166666666666667) * (f[(i + 3) * fsi]);
      fr21 =
	(-0.0166666666666667) * (f[(i - 3) * fsi]) + (+0.116666666666667) * (f[(i - 2) * fsi]) +
	(-0.383333333333333) * (f[(i - 1) * fsi]) + (+0.95) * (f[(i + 0) * fsi]) +
	(+0.366666666666667) * (f[(i + 1) * fsi]) + (-0.0333333333333333) * (f[(i + 2) * fsi]);
      fr22 =
	(+0.0333333333333333) * (f[(i - 4) * fsi]) + (-0.216666666666667) * (f[(i - 3) * fsi]) +
	(+0.616666666666667) * (f[(i - 2) * fsi]) + (-1.05) * (f[(i - 1) * fsi]) +
	(+1.45) * (f[(i + 0) * fsi]) + (+0.166666666666667) * (f[(i + 1) * fsi]);
      fr23 =
	(-0.166666666666667) * (f[(i - 5) * fsi]) + (+1.03333333333333) * (f[(i - 4) * fsi]) +
	(-2.71666666666667) * (f[(i - 3) * fsi]) + (+3.95) * (f[(i - 2) * fsi]) +
	(-3.55) * (f[(i - 1) * fsi]) + (+2.45) * (f[(i + 0) * fsi]);
      fs0 =
	(omega0) * (fr0) + (omega1) * (fr1) + (omega2) * (fr2) + (omega3) * (fr3) +
	(omega4) * (fr4) + (omega5) * (fr5);
      fs1 =
	(omega6) * (fr6) + (omega7) * (fr7) + (omega8) * (fr8) + (omega9) * (fr9) +
	(omega10) * (fr10) + (omega11) * (fr11);
      fs2 =
	(omega12) * (fr12) + (omega13) * (fr13) + (omega14) * (fr14) + (omega15) * (fr15) +
	(omega16) * (fr16) + (omega17) * (fr17);
      fs3 =
	(omega18) * (fr18) + (omega19) * (fr19) + (omega20) * (fr20) + (omega21) * (fr21) +
	(omega22) * (fr22) + (omega23) * (fr23);
      fr[i * frsi + 0 * frsl] = fs0;
      fr[i * frsi + 1 * frsl] = fs1;
      fr[i * frsi + 2 * frsl] = fs2;
      fr[i * frsi + 3 * frsl] = fs3;
    }
}

PyObject *
py_reconstruct_gauss_lobatto006004 (PyObject * self, PyObject * args)
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

  reconstruct_gauss_lobatto006004 (f, n, fsi, omega, wsi, wsl, wsr, fr, frsi, frsl);

  Py_INCREF (Py_None);
  return Py_None;
}
