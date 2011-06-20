#include <Python.h>
#include <numpy/ndarrayobject.h>

void
weights_gauss_radau004004 (const double *restrict sigma, int n, int ssi, int ssr,
			   double *restrict omega, int wsi, int wsl, int wsr)
{
  int i;
  double acc, sigma0, sigma1, sigma2, sigma3, omega1, omega6, omega14, omega0, omega9p, omega8p,
    omega10m, omega9m, omega11p, omega2, omega12, omega7, omega8m, omega4, omega15, omega3,
    omega10p, omega11m, omega5, omega13;
  for (i = 4; i < n - 4; i++)
    {
      sigma0 = sigma[i * ssi + 0 * ssr];
      sigma1 = sigma[i * ssi + 1 * ssr];
      sigma2 = sigma[i * ssi + 2 * ssr];
      sigma3 = sigma[i * ssi + 3 * ssr];
      acc = 0.0;
      omega0 = (+0.0285714285714286) / ((sigma0 + 1.0e-6) * (sigma0 + 1.0e-6));
      acc = acc + omega0;
      omega1 = (+0.342857142857143) / ((sigma1 + 1.0e-6) * (sigma1 + 1.0e-6));
      acc = acc + omega1;
      omega2 = (+0.514285714285714) / ((sigma2 + 1.0e-6) * (sigma2 + 1.0e-6));
      acc = acc + omega2;
      omega3 = (+0.114285714285714) / ((sigma3 + 1.0e-6) * (sigma3 + 1.0e-6));
      acc = acc + omega3;
      omega0 = (omega0) / (acc);
      omega1 = (omega1) / (acc);
      omega2 = (omega2) / (acc);
      omega3 = (omega3) / (acc);
      acc = 0.0;
      omega4 = (+0.0668669246177639) / ((sigma0 + 1.0e-6) * (sigma0 + 1.0e-6));
      acc = acc + omega4;
      omega5 = (+0.428108613216134) / ((sigma1 + 1.0e-6) * (sigma1 + 1.0e-6));
      acc = acc + omega5;
      omega6 = (+0.437668773893216) / ((sigma2 + 1.0e-6) * (sigma2 + 1.0e-6));
      acc = acc + omega6;
      omega7 = (+0.0673556882728853) / ((sigma3 + 1.0e-6) * (sigma3 + 1.0e-6));
      acc = acc + omega7;
      omega4 = (omega4) / (acc);
      omega5 = (omega5) / (acc);
      omega6 = (omega6) / (acc);
      omega7 = (omega7) / (acc);
      acc = 0.0;
      omega8p =
	((+0.0436290416752771) / (+2.71649898472312)) / ((sigma0 + 1.0e-6) * (sigma0 + 1.0e-6));
      acc = acc + omega8p;
      omega9p =
	((+0.37823955468964) / (+2.71649898472312)) / ((sigma1 + 1.0e-6) * (sigma1 + 1.0e-6));
      acc = acc + omega9p;
      omega10p =
	((+2.0557973934505) / (+2.71649898472312)) / ((sigma2 + 1.0e-6) * (sigma2 + 1.0e-6));
      acc = acc + omega10p;
      omega11p =
	((+0.238832994907708) / (+2.71649898472312)) / ((sigma3 + 1.0e-6) * (sigma3 + 1.0e-6));
      acc = acc + omega11p;
      omega8p = (omega8p) / (acc);
      omega9p = (omega9p) / (acc);
      omega10p = (omega10p) / (acc);
      omega11p = (omega11p) / (acc);
      acc = 0.0;
      omega8m =
	((+0.0218145208376385) / (+1.71649898472312)) / ((sigma0 + 1.0e-6) * (sigma0 + 1.0e-6));
      acc = acc + omega8m;
      omega9m =
	((+0.18911977734482) / (+1.71649898472312)) / ((sigma1 + 1.0e-6) * (sigma1 + 1.0e-6));
      acc = acc + omega9m;
      omega10m =
	((+1.02789869672525) / (+1.71649898472312)) / ((sigma2 + 1.0e-6) * (sigma2 + 1.0e-6));
      acc = acc + omega10m;
      omega11m =
	((+0.477665989815417) / (+1.71649898472312)) / ((sigma3 + 1.0e-6) * (sigma3 + 1.0e-6));
      acc = acc + omega11m;
      omega8m = (omega8m) / (acc);
      omega9m = (omega9m) / (acc);
      omega10m = (omega10m) / (acc);
      omega11m = (omega11m) / (acc);
      acc = 0.0;
      omega12 = (+0.0936123855597365) / ((sigma0 + 1.0e-6) * (sigma0 + 1.0e-6));
      acc = acc + omega12;
      omega13 = (+0.488437767302951) / ((sigma1 + 1.0e-6) * (sigma1 + 1.0e-6));
      acc = acc + omega13;
      omega14 = (+0.378338001210826) / ((sigma2 + 1.0e-6) * (sigma2 + 1.0e-6));
      acc = acc + omega14;
      omega15 = (+0.0396118459264837) / ((sigma3 + 1.0e-6) * (sigma3 + 1.0e-6));
      acc = acc + omega15;
      omega12 = (omega12) / (acc);
      omega13 = (omega13) / (acc);
      omega14 = (omega14) / (acc);
      omega15 = (omega15) / (acc);
      omega[i * wsi + 0 * wsl + 0 * wsr + 0] = omega0;
      omega[i * wsi + 0 * wsl + 1 * wsr + 0] = omega1;
      omega[i * wsi + 0 * wsl + 2 * wsr + 0] = omega2;
      omega[i * wsi + 0 * wsl + 3 * wsr + 0] = omega3;
      omega[i * wsi + 1 * wsl + 0 * wsr + 0] = omega4;
      omega[i * wsi + 1 * wsl + 1 * wsr + 0] = omega5;
      omega[i * wsi + 1 * wsl + 2 * wsr + 0] = omega6;
      omega[i * wsi + 1 * wsl + 3 * wsr + 0] = omega7;
      omega[i * wsi + 2 * wsl + 0 * wsr + 0] = omega8p;
      omega[i * wsi + 2 * wsl + 0 * wsr + 1] = omega8m;
      omega[i * wsi + 2 * wsl + 1 * wsr + 0] = omega9p;
      omega[i * wsi + 2 * wsl + 1 * wsr + 1] = omega9m;
      omega[i * wsi + 2 * wsl + 2 * wsr + 0] = omega10p;
      omega[i * wsi + 2 * wsl + 2 * wsr + 1] = omega10m;
      omega[i * wsi + 2 * wsl + 3 * wsr + 0] = omega11p;
      omega[i * wsi + 2 * wsl + 3 * wsr + 1] = omega11m;
      omega[i * wsi + 3 * wsl + 0 * wsr + 0] = omega12;
      omega[i * wsi + 3 * wsl + 1 * wsr + 0] = omega13;
      omega[i * wsi + 3 * wsl + 2 * wsr + 0] = omega14;
      omega[i * wsi + 3 * wsl + 3 * wsr + 0] = omega15;
    }
}

PyObject *
py_weights_gauss_radau004004 (PyObject * self, PyObject * args)
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

  weights_gauss_radau004004 (sigma, n, ssi, ssr, omega, wsi, wsl, wsr);

  Py_INCREF (Py_None);
  return Py_None;
}

void
reconstruct_gauss_radau004004 (const double *restrict f, int n, int fsi,
			       const double *restrict omega, int wsi, int wsl, int wsr,
			       double *restrict fr, int frsi, int frsl)
{
  int i;
  double omega1, omega6, omega14, omega0, omega9p, omega8p, omega10m, omega9m, omega11p, omega2,
    omega12, omega7, omega8m, omega4, omega15, omega3, omega10p, omega11m, omega5, omega13, fs0,
    fs1, fs2, fs3, fr1, fr6, fr14, fr0, fr15, fr12, fr13, fr9, fr2, fr8, fr7, fr11, fr10, fr4, fr3,
    fr5;
  for (i = 4; i < n - 4; i++)
    {
      omega0 = omega[i * wsi + 0 * wsl + 0 * wsr + 0];
      omega1 = omega[i * wsi + 0 * wsl + 1 * wsr + 0];
      omega2 = omega[i * wsi + 0 * wsl + 2 * wsr + 0];
      omega3 = omega[i * wsi + 0 * wsl + 3 * wsr + 0];
      omega4 = omega[i * wsi + 1 * wsl + 0 * wsr + 0];
      omega5 = omega[i * wsi + 1 * wsl + 1 * wsr + 0];
      omega6 = omega[i * wsi + 1 * wsl + 2 * wsr + 0];
      omega7 = omega[i * wsi + 1 * wsl + 3 * wsr + 0];
      omega8p = omega[i * wsi + 2 * wsl + 0 * wsr + 0];
      omega8m = omega[i * wsi + 2 * wsl + 0 * wsr + 1];
      omega9p = omega[i * wsi + 2 * wsl + 1 * wsr + 0];
      omega9m = omega[i * wsi + 2 * wsl + 1 * wsr + 1];
      omega10p = omega[i * wsi + 2 * wsl + 2 * wsr + 0];
      omega10m = omega[i * wsi + 2 * wsl + 2 * wsr + 1];
      omega11p = omega[i * wsi + 2 * wsl + 3 * wsr + 0];
      omega11m = omega[i * wsi + 2 * wsl + 3 * wsr + 1];
      omega12 = omega[i * wsi + 3 * wsl + 0 * wsr + 0];
      omega13 = omega[i * wsi + 3 * wsl + 1 * wsr + 0];
      omega14 = omega[i * wsi + 3 * wsl + 2 * wsr + 0];
      omega15 = omega[i * wsi + 3 * wsl + 3 * wsr + 0];
      fr0 =
	(+2.08333333333333) * (f[(i + 0) * fsi]) + (-1.91666666666667) * (f[(i + 1) * fsi]) +
	(+1.08333333333333) * (f[(i + 2) * fsi]) + (-0.25) * (f[(i + 3) * fsi]);
      fr1 =
	(+0.25) * (f[(i - 1) * fsi]) + (+1.08333333333333) * (f[(i + 0) * fsi]) +
	(-0.416666666666667) * (f[(i + 1) * fsi]) + (+0.0833333333333333) * (f[(i + 2) * fsi]);
      fr2 =
	(-0.0833333333333333) * (f[(i - 2) * fsi]) + (+0.583333333333333) * (f[(i - 1) * fsi]) +
	(+0.583333333333333) * (f[(i + 0) * fsi]) + (-0.0833333333333333) * (f[(i + 1) * fsi]);
      fr3 =
	(+0.0833333333333333) * (f[(i - 3) * fsi]) + (-0.416666666666667) * (f[(i - 2) * fsi]) +
	(+1.08333333333333) * (f[(i - 1) * fsi]) + (+0.25) * (f[(i + 0) * fsi]);
      fr4 =
	(+1.5187717074861) * (f[(i + 0) * fsi]) + (-0.837459151752583) * (f[(i + 1) * fsi]) +
	(+0.406262642807709) * (f[(i + 2) * fsi]) + (-0.0875751985412273) * (f[(i + 3) * fsi]);
      fr5 =
	(+0.0875751985412273) * (f[(i - 1) * fsi]) + (+1.16847091332119) * (f[(i + 0) * fsi]) +
	(-0.312007960505219) * (f[(i + 1) * fsi]) + (+0.0559618486427997) * (f[(i + 2) * fsi]);
      fr6 =
	(-0.0559618486427997) * (f[(i - 2) * fsi]) + (+0.311422593112426) * (f[(i - 1) * fsi]) +
	(+0.832699821464394) * (f[(i + 0) * fsi]) + (-0.0881605659340204) * (f[(i + 1) * fsi]);
      fr7 =
	(+0.0881605659340204) * (f[(i - 3) * fsi]) + (-0.408604112378881) * (f[(i - 2) * fsi]) +
	(+0.840385988716548) * (f[(i - 1) * fsi]) + (+0.480057557728312) * (f[(i + 0) * fsi]);
      fr8 =
	(+0.762534042075729) * (f[(i + 0) * fsi]) + (+0.448496492525079) * (f[(i + 1) * fsi]) +
	(-0.27512824683661) * (f[(i + 2) * fsi]) + (+0.0640977122358023) * (f[(i + 3) * fsi]);
      fr9 =
	(-0.0640977122358023) * (f[(i - 1) * fsi]) + (+1.01892489101894) * (f[(i + 0) * fsi]) +
	(+0.0639102191102646) * (f[(i + 1) * fsi]) + (-0.0187373978934008) * (f[(i + 2) * fsi]);
      fr10 =
	(+0.0187373978934008) * (f[(i - 2) * fsi]) + (-0.139047303809406) * (f[(i - 1) * fsi]) +
	(+1.13134927837934) * (f[(i + 0) * fsi]) + (-0.0110393724633387) * (f[(i + 1) * fsi]);
      fr11 =
	(+0.0110393724633387) * (f[(i - 3) * fsi]) + (-0.0254200919599538) * (f[(i - 2) * fsi]) +
	(-0.0728110690293737) * (f[(i - 1) * fsi]) + (+1.08719178852599) * (f[(i + 0) * fsi]);
      fr12 =
	(+0.337207369971697) * (f[(i + 0) * fsi]) + (+1.00281105572896) * (f[(i + 1) * fsi]) +
	(-0.428656261860312) * (f[(i + 2) * fsi]) + (+0.0886378361596523) * (f[(i + 3) * fsi]);
      fr13 =
	(-0.0886378361596524) * (f[(i - 1) * fsi]) + (+0.691758714610306) * (f[(i + 0) * fsi]) +
	(+0.470984038771048) * (f[(i + 1) * fsi]) + (-0.0741049172217021) * (f[(i + 2) * fsi]);
      fr14 =
	(+0.0741049172217021) * (f[(i - 2) * fsi]) + (-0.385057505046461) * (f[(i - 1) * fsi]) +
	(+1.13638821794052) * (f[(i + 0) * fsi]) + (+0.17456436988424) * (f[(i + 1) * fsi]);
      fr15 =
	(-0.17456436988424) * (f[(i - 3) * fsi]) + (+0.77236239675866) * (f[(i - 2) * fsi]) +
	(-1.4324437243519) * (f[(i - 1) * fsi]) + (+1.83464569747748) * (f[(i + 0) * fsi]);
      fs0 = (omega0) * (fr0) + (omega1) * (fr1) + (omega2) * (fr2) + (omega3) * (fr3);
      fs1 = (omega4) * (fr4) + (omega5) * (fr5) + (omega6) * (fr6) + (omega7) * (fr7);
      fs2 =
	((+2.71649898472312) *
	 ((omega8p) * (fr8) + (omega9p) * (fr9) + (omega10p) * (fr10) + (omega11p) * (fr11))) -
	((+1.71649898472312) *
	 ((omega8m) * (fr8) + (omega9m) * (fr9) + (omega10m) * (fr10) + (omega11m) * (fr11)));
      fs3 = (omega12) * (fr12) + (omega13) * (fr13) + (omega14) * (fr14) + (omega15) * (fr15);
      fr[i * frsi + 0 * frsl] = fs0;
      fr[i * frsi + 1 * frsl] = fs1;
      fr[i * frsi + 2 * frsl] = fs2;
      fr[i * frsi + 3 * frsl] = fs3;
    }
}

PyObject *
py_reconstruct_gauss_radau004004 (PyObject * self, PyObject * args)
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

  reconstruct_gauss_radau004004 (f, n, fsi, omega, wsi, wsl, wsr, fr, frsi, frsl);

  Py_INCREF (Py_None);
  return Py_None;
}
