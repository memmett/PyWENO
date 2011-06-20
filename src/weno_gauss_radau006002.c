#include <Python.h>
#include <numpy/ndarrayobject.h>

void
weights_gauss_radau006002 (const double *restrict sigma, int n, int ssi, int ssr,
			   double *restrict omega, int wsi, int wsl, int wsr)
{
  int i;
  double acc, sigma0, sigma1, sigma2, sigma3, sigma4, sigma5, omega1, omega7p, omega0, omega10p,
    omega11p, omega8m, omega6p, omega10m, omega9m, omega6m, omega7m, omega8p, omega5, omega11m,
    omega4, omega3, omega9p, omega2;
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
      omega6p =
	((+0.00760941010268561) / (+2.08063961830654)) / ((sigma0 + 1.0e-6) * (sigma0 + 1.0e-6));
      acc = acc + omega6p;
      omega7p =
	((+0.156977548722928) / (+2.08063961830654)) / ((sigma1 + 1.0e-6) * (sigma1 + 1.0e-6));
      acc = acc + omega7p;
      omega8p =
	((+0.652544680574857) / (+2.08063961830654)) / ((sigma2 + 1.0e-6) * (sigma2 + 1.0e-6));
      acc = acc + omega8p;
      omega9p =
	((+0.796246661640555) / (+2.08063961830654)) / ((sigma3 + 1.0e-6) * (sigma3 + 1.0e-6));
      acc = acc + omega9p;
      omega10p =
	((+0.0268798727688455) / (+2.08063961830654)) / ((sigma4 + 1.0e-6) * (sigma4 + 1.0e-6));
      acc = acc + omega10p;
      omega11p =
	((+0.440381444496674) / (+2.08063961830654)) / ((sigma5 + 1.0e-6) * (sigma5 + 1.0e-6));
      acc = acc + omega11p;
      omega6p = (omega6p) / (acc);
      omega7p = (omega7p) / (acc);
      omega8p = (omega8p) / (acc);
      omega9p = (omega9p) / (acc);
      omega10p = (omega10p) / (acc);
      omega11p = (omega11p) / (acc);
      acc = 0.0;
      omega6m =
	((+0.0038047050513428) / (+1.08063961830654)) / ((sigma0 + 1.0e-6) * (sigma0 + 1.0e-6));
      acc = acc + omega6m;
      omega7m =
	((+0.0784887743614638) / (+1.08063961830654)) / ((sigma1 + 1.0e-6) * (sigma1 + 1.0e-6));
      acc = acc + omega7m;
      omega8m =
	((+0.326272340287429) / (+1.08063961830654)) / ((sigma2 + 1.0e-6) * (sigma2 + 1.0e-6));
      acc = acc + omega8m;
      omega9m =
	((+0.398123330820277) / (+1.08063961830654)) / ((sigma3 + 1.0e-6) * (sigma3 + 1.0e-6));
      acc = acc + omega9m;
      omega10m =
	((+0.053759745537691) / (+1.08063961830654)) / ((sigma4 + 1.0e-6) * (sigma4 + 1.0e-6));
      acc = acc + omega10m;
      omega11m =
	((+0.220190722248337) / (+1.08063961830654)) / ((sigma5 + 1.0e-6) * (sigma5 + 1.0e-6));
      acc = acc + omega11m;
      omega6m = (omega6m) / (acc);
      omega7m = (omega7m) / (acc);
      omega8m = (omega8m) / (acc);
      omega9m = (omega9m) / (acc);
      omega10m = (omega10m) / (acc);
      omega11m = (omega11m) / (acc);
      omega[i * wsi + 0 * wsl + 0 * wsr + 0] = omega0;
      omega[i * wsi + 0 * wsl + 1 * wsr + 0] = omega1;
      omega[i * wsi + 0 * wsl + 2 * wsr + 0] = omega2;
      omega[i * wsi + 0 * wsl + 3 * wsr + 0] = omega3;
      omega[i * wsi + 0 * wsl + 4 * wsr + 0] = omega4;
      omega[i * wsi + 0 * wsl + 5 * wsr + 0] = omega5;
      omega[i * wsi + 1 * wsl + 0 * wsr + 0] = omega6p;
      omega[i * wsi + 1 * wsl + 0 * wsr + 1] = omega6m;
      omega[i * wsi + 1 * wsl + 1 * wsr + 0] = omega7p;
      omega[i * wsi + 1 * wsl + 1 * wsr + 1] = omega7m;
      omega[i * wsi + 1 * wsl + 2 * wsr + 0] = omega8p;
      omega[i * wsi + 1 * wsl + 2 * wsr + 1] = omega8m;
      omega[i * wsi + 1 * wsl + 3 * wsr + 0] = omega9p;
      omega[i * wsi + 1 * wsl + 3 * wsr + 1] = omega9m;
      omega[i * wsi + 1 * wsl + 4 * wsr + 0] = omega10p;
      omega[i * wsi + 1 * wsl + 4 * wsr + 1] = omega10m;
      omega[i * wsi + 1 * wsl + 5 * wsr + 0] = omega11p;
      omega[i * wsi + 1 * wsl + 5 * wsr + 1] = omega11m;
    }
}

PyObject *
py_weights_gauss_radau006002 (PyObject * self, PyObject * args)
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

  weights_gauss_radau006002 (sigma, n, ssi, ssr, omega, wsi, wsl, wsr);

  Py_INCREF (Py_None);
  return Py_None;
}

void
reconstruct_gauss_radau006002 (const double *restrict f, int n, int fsi,
			       const double *restrict omega, int wsi, int wsl, int wsr,
			       double *restrict fr, int frsi, int frsl)
{
  int i;
  double omega1, omega7p, omega0, omega10p, omega11p, omega8m, omega6p, omega10m, omega9m, omega6m,
    omega7m, omega8p, omega5, omega11m, omega4, omega3, omega9p, omega2, fs0, fs1, fr1, fr8, fr0,
    fr10, fr7, fr11, fr9, fr5, fr4, fr6, fr3, fr2;
  for (i = 6; i < n - 6; i++)
    {
      omega0 = omega[i * wsi + 0 * wsl + 0 * wsr + 0];
      omega1 = omega[i * wsi + 0 * wsl + 1 * wsr + 0];
      omega2 = omega[i * wsi + 0 * wsl + 2 * wsr + 0];
      omega3 = omega[i * wsi + 0 * wsl + 3 * wsr + 0];
      omega4 = omega[i * wsi + 0 * wsl + 4 * wsr + 0];
      omega5 = omega[i * wsi + 0 * wsl + 5 * wsr + 0];
      omega6p = omega[i * wsi + 1 * wsl + 0 * wsr + 0];
      omega6m = omega[i * wsi + 1 * wsl + 0 * wsr + 1];
      omega7p = omega[i * wsi + 1 * wsl + 1 * wsr + 0];
      omega7m = omega[i * wsi + 1 * wsl + 1 * wsr + 1];
      omega8p = omega[i * wsi + 1 * wsl + 2 * wsr + 0];
      omega8m = omega[i * wsi + 1 * wsl + 2 * wsr + 1];
      omega9p = omega[i * wsi + 1 * wsl + 3 * wsr + 0];
      omega9m = omega[i * wsi + 1 * wsl + 3 * wsr + 1];
      omega10p = omega[i * wsi + 1 * wsl + 4 * wsr + 0];
      omega10m = omega[i * wsi + 1 * wsl + 4 * wsr + 1];
      omega11p = omega[i * wsi + 1 * wsl + 5 * wsr + 0];
      omega11m = omega[i * wsi + 1 * wsl + 5 * wsr + 1];
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
	(+0.543347050754459) * (f[(i + 0) * fsi]) + (+1.07174211248285) * (f[(i + 1) * fsi]) +
	(-1.13093278463649) * (f[(i + 2) * fsi]) + (+0.751097393689986) * (f[(i + 3) * fsi]) +
	(-0.279766803840878) * (f[(i + 4) * fsi]) + (+0.0445130315500685) * (f[(i + 5) * fsi]);
      fr7 =
	(-0.0445130315500686) * (f[(i - 1) * fsi]) + (+0.81042524005487) * (f[(i + 0) * fsi]) +
	(+0.404046639231824) * (f[(i + 1) * fsi]) + (-0.240672153635116) * (f[(i + 2) * fsi]) +
	(+0.0834019204389575) * (f[(i + 3) * fsi]) + (-0.0126886145404664) * (f[(i + 4) * fsi]);
      fr8 =
	(+0.0126886145404664) * (f[(i - 2) * fsi]) + (-0.120644718792867) * (f[(i - 1) * fsi]) +
	(+1.00075445816187) * (f[(i + 0) * fsi]) + (+0.150274348422497) * (f[(i + 1) * fsi]) +
	(-0.0503429355281207) * (f[(i + 2) * fsi]) + (+0.00727023319615912) * (f[(i + 3) * fsi]);
      fr9 =
	(-0.00727023319615912) * (f[(i - 3) * fsi]) + (+0.0563100137174211) * (f[(i - 2) * fsi]) +
	(-0.229698216735254) * (f[(i - 1) * fsi]) + (+1.14615912208505) * (f[(i + 0) * fsi]) +
	(+0.0412208504801097) * (f[(i + 1) * fsi]) + (-0.00672153635116598) * (f[(i + 2) * fsi]);
      fr10 =
	(+0.00672153635116598) * (f[(i - 4) * fsi]) + (-0.047599451303155) * (f[(i - 3) * fsi]) +
	(+0.157133058984911) * (f[(i - 2) * fsi]) + (-0.364128943758573) * (f[(i - 1) * fsi]) +
	(+1.24698216735254) * (f[(i + 0) * fsi]) + (+0.000891632373113849) * (f[(i + 1) * fsi]);
      fr11 =
	(-0.000891632373113849) * (f[(i - 5) * fsi]) + (+0.012071330589849) * (f[(i - 4) * fsi]) +
	(-0.0609739368998626) * (f[(i - 3) * fsi]) + (+0.174965706447187) * (f[(i - 2) * fsi]) +
	(-0.377503429355281) * (f[(i - 1) * fsi]) + (+1.25233196159122) * (f[(i + 0) * fsi]);
      fs0 =
	(omega0) * (fr0) + (omega1) * (fr1) + (omega2) * (fr2) + (omega3) * (fr3) +
	(omega4) * (fr4) + (omega5) * (fr5);
      fs1 =
	((+2.08063961830654) *
	 ((omega6p) * (fr6) + (omega7p) * (fr7) + (omega8p) * (fr8) + (omega9p) * (fr9) +
	  (omega10p) * (fr10) + (omega11p) * (fr11))) - ((+1.08063961830654) * ((omega6m) * (fr6) +
										(omega7m) * (fr7) +
										(omega8m) * (fr8) +
										(omega9m) * (fr9) +
										(omega10m) *
										(fr10) +
										(omega11m) *
										(fr11)));
      fr[i * frsi + 0 * frsl] = fs0;
      fr[i * frsi + 1 * frsl] = fs1;
    }
}

PyObject *
py_reconstruct_gauss_radau006002 (PyObject * self, PyObject * args)
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

  reconstruct_gauss_radau006002 (f, n, fsi, omega, wsi, wsl, wsr, fr, frsi, frsl);

  Py_INCREF (Py_None);
  return Py_None;
}
