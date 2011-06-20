#include <Python.h>
#include <numpy/ndarrayobject.h>

void
weights_gauss_radau005003 (const double *restrict sigma, int n, int ssi, int ssr,
			   double *restrict omega, int wsi, int wsl, int wsr)
{
  int i;
  double acc, sigma0, sigma1, sigma2, sigma3, sigma4, omega1, omega6p, omega0, omega9p, omega7m,
    omega5p, omega9m, omega8m, omega12, omega11, omega5m, omega6m, omega10, omega7p, omega13,
    omega4, omega14, omega3, omega8p, omega2;
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
      omega5p =
	((+9.2839542770609) / (+14.7093846474239)) / ((sigma0 + 1.0e-6) * (sigma0 + 1.0e-6));
      acc = acc + omega5p;
      omega6p =
	((+4.23646154914129) / (+14.7093846474239)) / ((sigma1 + 1.0e-6) * (sigma1 + 1.0e-6));
      acc = acc + omega6p;
      omega7p =
	((+0.844627827498517) / (+14.7093846474239)) / ((sigma2 + 1.0e-6) * (sigma2 + 1.0e-6));
      acc = acc + omega7p;
      omega8p =
	((+0.321988795328485) / (+14.7093846474239)) / ((sigma3 + 1.0e-6) * (sigma3 + 1.0e-6));
      acc = acc + omega8p;
      omega9p =
	((+0.0223521983946644) / (+14.7093846474239)) / ((sigma4 + 1.0e-6) * (sigma4 + 1.0e-6));
      acc = acc + omega9p;
      omega5p = (omega5p) / (acc);
      omega6p = (omega6p) / (acc);
      omega7p = (omega7p) / (acc);
      omega8p = (omega8p) / (acc);
      omega9p = (omega9p) / (acc);
      acc = 0.0;
      omega5m =
	((+4.64197713853045) / (+13.7093846474239)) / ((sigma0 + 1.0e-6) * (sigma0 + 1.0e-6));
      acc = acc + omega5m;
      omega6m =
	((+8.47292309828257) / (+13.7093846474239)) / ((sigma1 + 1.0e-6) * (sigma1 + 1.0e-6));
      acc = acc + omega6m;
      omega7m =
	((+0.422313913749258) / (+13.7093846474239)) / ((sigma2 + 1.0e-6) * (sigma2 + 1.0e-6));
      acc = acc + omega7m;
      omega8m =
	((+0.160994397664242) / (+13.7093846474239)) / ((sigma3 + 1.0e-6) * (sigma3 + 1.0e-6));
      acc = acc + omega8m;
      omega9m =
	((+0.0111760991973322) / (+13.7093846474239)) / ((sigma4 + 1.0e-6) * (sigma4 + 1.0e-6));
      acc = acc + omega9m;
      omega5m = (omega5m) / (acc);
      omega6m = (omega6m) / (acc);
      omega7m = (omega7m) / (acc);
      omega8m = (omega8m) / (acc);
      omega9m = (omega9m) / (acc);
      acc = 0.0;
      omega10 = (+0.0259724883722976) / ((sigma0 + 1.0e-6) * (sigma0 + 1.0e-6));
      acc = acc + omega10;
      omega11 = (+0.26259860445952) / ((sigma1 + 1.0e-6) * (sigma1 + 1.0e-6));
      acc = acc + omega11;
      omega12 = (+0.487517778089392) / ((sigma2 + 1.0e-6) * (sigma2 + 1.0e-6));
      acc = acc + omega12;
      omega13 = (+0.208167585637633) / ((sigma3 + 1.0e-6) * (sigma3 + 1.0e-6));
      acc = acc + omega13;
      omega14 = (+0.0157435434411583) / ((sigma4 + 1.0e-6) * (sigma4 + 1.0e-6));
      acc = acc + omega14;
      omega10 = (omega10) / (acc);
      omega11 = (omega11) / (acc);
      omega12 = (omega12) / (acc);
      omega13 = (omega13) / (acc);
      omega14 = (omega14) / (acc);
      omega[i * wsi + 0 * wsl + 0 * wsr + 0] = omega0;
      omega[i * wsi + 0 * wsl + 1 * wsr + 0] = omega1;
      omega[i * wsi + 0 * wsl + 2 * wsr + 0] = omega2;
      omega[i * wsi + 0 * wsl + 3 * wsr + 0] = omega3;
      omega[i * wsi + 0 * wsl + 4 * wsr + 0] = omega4;
      omega[i * wsi + 1 * wsl + 0 * wsr + 0] = omega5p;
      omega[i * wsi + 1 * wsl + 0 * wsr + 1] = omega5m;
      omega[i * wsi + 1 * wsl + 1 * wsr + 0] = omega6p;
      omega[i * wsi + 1 * wsl + 1 * wsr + 1] = omega6m;
      omega[i * wsi + 1 * wsl + 2 * wsr + 0] = omega7p;
      omega[i * wsi + 1 * wsl + 2 * wsr + 1] = omega7m;
      omega[i * wsi + 1 * wsl + 3 * wsr + 0] = omega8p;
      omega[i * wsi + 1 * wsl + 3 * wsr + 1] = omega8m;
      omega[i * wsi + 1 * wsl + 4 * wsr + 0] = omega9p;
      omega[i * wsi + 1 * wsl + 4 * wsr + 1] = omega9m;
      omega[i * wsi + 2 * wsl + 0 * wsr + 0] = omega10;
      omega[i * wsi + 2 * wsl + 1 * wsr + 0] = omega11;
      omega[i * wsi + 2 * wsl + 2 * wsr + 0] = omega12;
      omega[i * wsi + 2 * wsl + 3 * wsr + 0] = omega13;
      omega[i * wsi + 2 * wsl + 4 * wsr + 0] = omega14;
    }
}

PyObject *
py_weights_gauss_radau005003 (PyObject * self, PyObject * args)
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

  weights_gauss_radau005003 (sigma, n, ssi, ssr, omega, wsi, wsl, wsr);

  Py_INCREF (Py_None);
  return Py_None;
}

void
reconstruct_gauss_radau005003 (const double *restrict f, int n, int fsi,
			       const double *restrict omega, int wsi, int wsl, int wsr,
			       double *restrict fr, int frsi, int frsl)
{
  int i;
  double omega1, omega6p, omega0, omega9p, omega7m, omega5p, omega9m, omega8m, omega12, omega11,
    omega5m, omega6m, omega10, omega7p, omega13, omega4, omega14, omega3, omega8p, omega2, fs0, fs1,
    fs2, fr1, fr7, fr0, fr12, fr6, fr9, fr2, fr10, fr8, fr13, fr11, fr4, fr14, fr3, fr5;
  for (i = 5; i < n - 5; i++)
    {
      omega0 = omega[i * wsi + 0 * wsl + 0 * wsr + 0];
      omega1 = omega[i * wsi + 0 * wsl + 1 * wsr + 0];
      omega2 = omega[i * wsi + 0 * wsl + 2 * wsr + 0];
      omega3 = omega[i * wsi + 0 * wsl + 3 * wsr + 0];
      omega4 = omega[i * wsi + 0 * wsl + 4 * wsr + 0];
      omega5p = omega[i * wsi + 1 * wsl + 0 * wsr + 0];
      omega5m = omega[i * wsi + 1 * wsl + 0 * wsr + 1];
      omega6p = omega[i * wsi + 1 * wsl + 1 * wsr + 0];
      omega6m = omega[i * wsi + 1 * wsl + 1 * wsr + 1];
      omega7p = omega[i * wsi + 1 * wsl + 2 * wsr + 0];
      omega7m = omega[i * wsi + 1 * wsl + 2 * wsr + 1];
      omega8p = omega[i * wsi + 1 * wsl + 3 * wsr + 0];
      omega8m = omega[i * wsi + 1 * wsl + 3 * wsr + 1];
      omega9p = omega[i * wsi + 1 * wsl + 4 * wsr + 0];
      omega9m = omega[i * wsi + 1 * wsl + 4 * wsr + 1];
      omega10 = omega[i * wsi + 2 * wsl + 0 * wsr + 0];
      omega11 = omega[i * wsi + 2 * wsl + 1 * wsr + 0];
      omega12 = omega[i * wsi + 2 * wsl + 2 * wsr + 0];
      omega13 = omega[i * wsi + 2 * wsl + 3 * wsr + 0];
      omega14 = omega[i * wsi + 2 * wsl + 4 * wsr + 0];
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
	(+1.19805516088627) * (f[(i + 0) * fsi]) + (-0.263125086603273) * (f[(i + 1) * fsi]) +
	(+0.0772041403718329) * (f[(i + 2) * fsi]) + (-0.0123046902005961) * (f[(i + 3) * fsi]) +
	(+0.000170475545769212) * (f[(i + 4) * fsi]);
      fr6 =
	(+0.000170475545769211) * (f[(i - 1) * fsi]) + (+1.19720278315742) * (f[(i + 0) * fsi]) +
	(-0.26142033114558) * (f[(i + 1) * fsi]) + (+0.0754993849141406) * (f[(i + 2) * fsi]) +
	(-0.0114523124717498) * (f[(i + 3) * fsi]);
      fr7 =
	(-0.0114523124717498) * (f[(i - 2) * fsi]) + (+0.0574320379045182) * (f[(i - 1) * fsi]) +
	(+1.08267965843992) * (f[(i + 0) * fsi]) + (-0.146897206428083) * (f[(i + 1) * fsi]) +
	(+0.0182378225553917) * (f[(i + 2) * fsi]);
      fr8 =
	(+0.0182378225553917) * (f[(i - 3) * fsi]) + (-0.102641425248708) * (f[(i - 2) * fsi]) +
	(+0.239810263458435) * (f[(i - 1) * fsi]) + (+0.900301432886006) * (f[(i + 0) * fsi]) +
	(-0.0557080936511243) * (f[(i + 1) * fsi]);
      fr9 =
	(-0.0557080936511243) * (f[(i - 4) * fsi]) + (+0.296778290811013) * (f[(i - 3) * fsi]) +
	(-0.659722361759951) * (f[(i - 2) * fsi]) + (+0.796891199969677) * (f[(i - 1) * fsi]) +
	(+0.621760964630385) * (f[(i + 0) * fsi]);
      fr10 =
	(+0.3515115057804) * (f[(i + 0) * fsi]) + (+1.16019175326994) * (f[(i + 1) * fsi]) +
	(-0.779137473705166) * (f[(i + 2) * fsi]) + (+0.326704690200595) * (f[(i + 3) * fsi]) +
	(-0.0592704755457692) * (f[(i + 4) * fsi]);
      fr11 =
	(-0.0592704755457691) * (f[(i - 1) * fsi]) + (+0.647863883509246) * (f[(i + 0) * fsi]) +
	(+0.567486997812247) * (f[(i + 1) * fsi]) + (-0.186432718247474) * (f[(i + 2) * fsi]) +
	(+0.0303523124717498) * (f[(i + 3) * fsi]);
      fr12 =
	(+0.0303523124717498) * (f[(i - 2) * fsi]) + (-0.211032037904518) * (f[(i - 1) * fsi]) +
	(+0.951387008226744) * (f[(i + 0) * fsi]) + (+0.263963873094749) * (f[(i + 1) * fsi]) +
	(-0.034671155888725) * (f[(i + 2) * fsi]);
      fr13 =
	(-0.034671155888725) * (f[(i - 3) * fsi]) + (+0.203708091915375) * (f[(i - 2) * fsi]) +
	(-0.557743596791768) * (f[(i - 1) * fsi]) + (+1.29809856711399) * (f[(i + 0) * fsi]) +
	(+0.0906080936511243) * (f[(i + 1) * fsi]);
      fr14 =
	(+0.0906080936511243) * (f[(i - 4) * fsi]) + (-0.487711624144346) * (f[(i - 3) * fsi]) +
	(+1.10978902842662) * (f[(i - 2) * fsi]) + (-1.46382453330301) * (f[(i - 1) * fsi]) +
	(+1.75113903536962) * (f[(i + 0) * fsi]);
      fs0 =
	(omega0) * (fr0) + (omega1) * (fr1) + (omega2) * (fr2) + (omega3) * (fr3) +
	(omega4) * (fr4);
      fs1 =
	((+14.7093846474239) *
	 ((omega5p) * (fr5) + (omega6p) * (fr6) + (omega7p) * (fr7) + (omega8p) * (fr8) +
	  (omega9p) * (fr9))) - ((+13.7093846474239) * ((omega5m) * (fr5) + (omega6m) * (fr6) +
							(omega7m) * (fr7) + (omega8m) * (fr8) +
							(omega9m) * (fr9)));
      fs2 =
	(omega10) * (fr10) + (omega11) * (fr11) + (omega12) * (fr12) + (omega13) * (fr13) +
	(omega14) * (fr14);
      fr[i * frsi + 0 * frsl] = fs0;
      fr[i * frsi + 1 * frsl] = fs1;
      fr[i * frsi + 2 * frsl] = fs2;
    }
}

PyObject *
py_reconstruct_gauss_radau005003 (PyObject * self, PyObject * args)
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

  reconstruct_gauss_radau005003 (f, n, fsi, omega, wsi, wsl, wsr, fr, frsi, frsl);

  Py_INCREF (Py_None);
  return Py_None;
}
