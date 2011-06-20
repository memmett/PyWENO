#include <Python.h>
#include <numpy/ndarrayobject.h>

void
weights_gauss_lobatto006006 (const double *restrict sigma, int n, int ssi, int ssr,
			     double *restrict omega, int wsi, int wsl, int wsr)
{
  int i;
  double acc, sigma0, sigma1, sigma2, sigma3, sigma4, sigma5, omega9, omega22p, omega21m, omega22m,
    omega15p, omega31, omega21p, omega16m, omega14p, omega3, omega24, omega8, omega16p, omega35,
    omega28, omega15m, omega11, omega12m, omega4, omega29, omega25, omega12p, omega20p, omega23m,
    omega34, omega0, omega19m, omega30, omega20m, omega17p, omega19p, omega10, omega17m, omega5,
    omega26, omega6, omega33, omega1, omega13p, omega23p, omega14m, omega13m, omega7, omega18p,
    omega27, omega18m, omega32, omega2;
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
      omega6 = (+0.00379070936668324) / ((sigma0 + 1.0e-6) * (sigma0 + 1.0e-6));
      acc = acc + omega6;
      omega7 = (+0.0846121752615751) / ((sigma1 + 1.0e-6) * (sigma1 + 1.0e-6));
      acc = acc + omega7;
      omega8 = (+0.355832852352342) / ((sigma2 + 1.0e-6) * (sigma2 + 1.0e-6));
      acc = acc + omega8;
      omega9 = (+0.412050221004584) / ((sigma3 + 1.0e-6) * (sigma3 + 1.0e-6));
      acc = acc + omega9;
      omega10 = (+0.134570060125772) / ((sigma4 + 1.0e-6) * (sigma4 + 1.0e-6));
      acc = acc + omega10;
      omega11 = (+0.00914398188904421) / ((sigma5 + 1.0e-6) * (sigma5 + 1.0e-6));
      acc = acc + omega11;
      omega6 = (omega6) / (acc);
      omega7 = (omega7) / (acc);
      omega8 = (omega8) / (acc);
      omega9 = (omega9) / (acc);
      omega10 = (omega10) / (acc);
      omega11 = (omega11) / (acc);
      acc = 0.0;
      omega12p =
	((+0.0315442426082676) / (+2.0946327278248)) / ((sigma0 + 1.0e-6) * (sigma0 + 1.0e-6));
      acc = acc + omega12p;
      omega13p =
	((+0.535895308584776) / (+2.0946327278248)) / ((sigma1 + 1.0e-6) * (sigma1 + 1.0e-6));
      acc = acc + omega13p;
      omega14p =
	((+0.772745145646633) / (+2.0946327278248)) / ((sigma2 + 1.0e-6) * (sigma2 + 1.0e-6));
      acc = acc + omega14p;
      omega15p =
	((+0.60769117309411) / (+2.0946327278248)) / ((sigma3 + 1.0e-6) * (sigma3 + 1.0e-6));
      acc = acc + omega15p;
      omega16p =
	((+0.140250432861363) / (+2.0946327278248)) / ((sigma4 + 1.0e-6) * (sigma4 + 1.0e-6));
      acc = acc + omega16p;
      omega17p =
	((+0.00650642502965456) / (+2.0946327278248)) / ((sigma5 + 1.0e-6) * (sigma5 + 1.0e-6));
      acc = acc + omega17p;
      omega12p = (omega12p) / (acc);
      omega13p = (omega13p) / (acc);
      omega14p = (omega14p) / (acc);
      omega15p = (omega15p) / (acc);
      omega16p = (omega16p) / (acc);
      omega17p = (omega17p) / (acc);
      acc = 0.0;
      omega12m =
	((+0.0630884852165352) / (+1.0946327278248)) / ((sigma0 + 1.0e-6) * (sigma0 + 1.0e-6));
      acc = acc + omega12m;
      omega13m =
	((+0.267947654292388) / (+1.0946327278248)) / ((sigma1 + 1.0e-6) * (sigma1 + 1.0e-6));
      acc = acc + omega13m;
      omega14m =
	((+0.386372572823316) / (+1.0946327278248)) / ((sigma2 + 1.0e-6) * (sigma2 + 1.0e-6));
      acc = acc + omega14m;
      omega15m =
	((+0.303845586547055) / (+1.0946327278248)) / ((sigma3 + 1.0e-6) * (sigma3 + 1.0e-6));
      acc = acc + omega15m;
      omega16m =
	((+0.0701252164306814) / (+1.0946327278248)) / ((sigma4 + 1.0e-6) * (sigma4 + 1.0e-6));
      acc = acc + omega16m;
      omega17m =
	((+0.00325321251482728) / (+1.0946327278248)) / ((sigma5 + 1.0e-6) * (sigma5 + 1.0e-6));
      acc = acc + omega17m;
      omega12m = (omega12m) / (acc);
      omega13m = (omega13m) / (acc);
      omega14m = (omega14m) / (acc);
      omega15m = (omega15m) / (acc);
      omega16m = (omega16m) / (acc);
      omega17m = (omega17m) / (acc);
      acc = 0.0;
      omega18p =
	((+0.00650642502965749) / (+2.09463272782487)) / ((sigma0 + 1.0e-6) * (sigma0 + 1.0e-6));
      acc = acc + omega18p;
      omega19p =
	((+0.14025043286135) / (+2.09463272782487)) / ((sigma1 + 1.0e-6) * (sigma1 + 1.0e-6));
      acc = acc + omega19p;
      omega20p =
	((+0.607691173094121) / (+2.09463272782487)) / ((sigma2 + 1.0e-6) * (sigma2 + 1.0e-6));
      acc = acc + omega20p;
      omega21p =
	((+0.772745145646637) / (+2.09463272782487)) / ((sigma3 + 1.0e-6) * (sigma3 + 1.0e-6));
      acc = acc + omega21p;
      omega22p =
	((+0.535895308584817) / (+2.09463272782487)) / ((sigma4 + 1.0e-6) * (sigma4 + 1.0e-6));
      acc = acc + omega22p;
      omega23p =
	((+0.0315442426082916) / (+2.09463272782487)) / ((sigma5 + 1.0e-6) * (sigma5 + 1.0e-6));
      acc = acc + omega23p;
      omega18p = (omega18p) / (acc);
      omega19p = (omega19p) / (acc);
      omega20p = (omega20p) / (acc);
      omega21p = (omega21p) / (acc);
      omega22p = (omega22p) / (acc);
      omega23p = (omega23p) / (acc);
      acc = 0.0;
      omega18m =
	((+0.00325321251482875) / (+1.09463272782487)) / ((sigma0 + 1.0e-6) * (sigma0 + 1.0e-6));
      acc = acc + omega18m;
      omega19m =
	((+0.0701252164306749) / (+1.09463272782487)) / ((sigma1 + 1.0e-6) * (sigma1 + 1.0e-6));
      acc = acc + omega19m;
      omega20m =
	((+0.303845586547061) / (+1.09463272782487)) / ((sigma2 + 1.0e-6) * (sigma2 + 1.0e-6));
      acc = acc + omega20m;
      omega21m =
	((+0.386372572823318) / (+1.09463272782487)) / ((sigma3 + 1.0e-6) * (sigma3 + 1.0e-6));
      acc = acc + omega21m;
      omega22m =
	((+0.267947654292408) / (+1.09463272782487)) / ((sigma4 + 1.0e-6) * (sigma4 + 1.0e-6));
      acc = acc + omega22m;
      omega23m =
	((+0.0630884852165833) / (+1.09463272782487)) / ((sigma5 + 1.0e-6) * (sigma5 + 1.0e-6));
      acc = acc + omega23m;
      omega18m = (omega18m) / (acc);
      omega19m = (omega19m) / (acc);
      omega20m = (omega20m) / (acc);
      omega21m = (omega21m) / (acc);
      omega22m = (omega22m) / (acc);
      omega23m = (omega23m) / (acc);
      acc = 0.0;
      omega24 = (+0.00914398188902577) / ((sigma0 + 1.0e-6) * (sigma0 + 1.0e-6));
      acc = acc + omega24;
      omega25 = (+0.134570060125791) / ((sigma1 + 1.0e-6) * (sigma1 + 1.0e-6));
      acc = acc + omega25;
      omega26 = (+0.412050221004576) / ((sigma2 + 1.0e-6) * (sigma2 + 1.0e-6));
      acc = acc + omega26;
      omega27 = (+0.355832852352347) / ((sigma3 + 1.0e-6) * (sigma3 + 1.0e-6));
      acc = acc + omega27;
      omega28 = (+0.0846121752615669) / ((sigma4 + 1.0e-6) * (sigma4 + 1.0e-6));
      acc = acc + omega28;
      omega29 = (+0.00379070936668724) / ((sigma5 + 1.0e-6) * (sigma5 + 1.0e-6));
      acc = acc + omega29;
      omega24 = (omega24) / (acc);
      omega25 = (omega25) / (acc);
      omega26 = (omega26) / (acc);
      omega27 = (omega27) / (acc);
      omega28 = (omega28) / (acc);
      omega29 = (omega29) / (acc);
      acc = 0.0;
      omega30 = (+0.0129870129869969) / ((sigma0 + 1.0e-6) * (sigma0 + 1.0e-6));
      acc = acc + omega30;
      omega31 = (+0.162337662337667) / ((sigma1 + 1.0e-6) * (sigma1 + 1.0e-6));
      acc = acc + omega31;
      omega32 = (+0.432900432900435) / ((sigma2 + 1.0e-6) * (sigma2 + 1.0e-6));
      acc = acc + omega32;
      omega33 = (+0.324675324675325) / ((sigma3 + 1.0e-6) * (sigma3 + 1.0e-6));
      acc = acc + omega33;
      omega34 = (+0.0649350649350649) / ((sigma4 + 1.0e-6) * (sigma4 + 1.0e-6));
      acc = acc + omega34;
      omega35 = (+0.00216450216450216) / ((sigma5 + 1.0e-6) * (sigma5 + 1.0e-6));
      acc = acc + omega35;
      omega30 = (omega30) / (acc);
      omega31 = (omega31) / (acc);
      omega32 = (omega32) / (acc);
      omega33 = (omega33) / (acc);
      omega34 = (omega34) / (acc);
      omega35 = (omega35) / (acc);
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
      omega[i * wsi + 2 * wsl + 0 * wsr + 0] = omega12p;
      omega[i * wsi + 2 * wsl + 0 * wsr + 1] = omega12m;
      omega[i * wsi + 2 * wsl + 1 * wsr + 0] = omega13p;
      omega[i * wsi + 2 * wsl + 1 * wsr + 1] = omega13m;
      omega[i * wsi + 2 * wsl + 2 * wsr + 0] = omega14p;
      omega[i * wsi + 2 * wsl + 2 * wsr + 1] = omega14m;
      omega[i * wsi + 2 * wsl + 3 * wsr + 0] = omega15p;
      omega[i * wsi + 2 * wsl + 3 * wsr + 1] = omega15m;
      omega[i * wsi + 2 * wsl + 4 * wsr + 0] = omega16p;
      omega[i * wsi + 2 * wsl + 4 * wsr + 1] = omega16m;
      omega[i * wsi + 2 * wsl + 5 * wsr + 0] = omega17p;
      omega[i * wsi + 2 * wsl + 5 * wsr + 1] = omega17m;
      omega[i * wsi + 3 * wsl + 0 * wsr + 0] = omega18p;
      omega[i * wsi + 3 * wsl + 0 * wsr + 1] = omega18m;
      omega[i * wsi + 3 * wsl + 1 * wsr + 0] = omega19p;
      omega[i * wsi + 3 * wsl + 1 * wsr + 1] = omega19m;
      omega[i * wsi + 3 * wsl + 2 * wsr + 0] = omega20p;
      omega[i * wsi + 3 * wsl + 2 * wsr + 1] = omega20m;
      omega[i * wsi + 3 * wsl + 3 * wsr + 0] = omega21p;
      omega[i * wsi + 3 * wsl + 3 * wsr + 1] = omega21m;
      omega[i * wsi + 3 * wsl + 4 * wsr + 0] = omega22p;
      omega[i * wsi + 3 * wsl + 4 * wsr + 1] = omega22m;
      omega[i * wsi + 3 * wsl + 5 * wsr + 0] = omega23p;
      omega[i * wsi + 3 * wsl + 5 * wsr + 1] = omega23m;
      omega[i * wsi + 4 * wsl + 0 * wsr + 0] = omega24;
      omega[i * wsi + 4 * wsl + 1 * wsr + 0] = omega25;
      omega[i * wsi + 4 * wsl + 2 * wsr + 0] = omega26;
      omega[i * wsi + 4 * wsl + 3 * wsr + 0] = omega27;
      omega[i * wsi + 4 * wsl + 4 * wsr + 0] = omega28;
      omega[i * wsi + 4 * wsl + 5 * wsr + 0] = omega29;
      omega[i * wsi + 5 * wsl + 0 * wsr + 0] = omega30;
      omega[i * wsi + 5 * wsl + 1 * wsr + 0] = omega31;
      omega[i * wsi + 5 * wsl + 2 * wsr + 0] = omega32;
      omega[i * wsi + 5 * wsl + 3 * wsr + 0] = omega33;
      omega[i * wsi + 5 * wsl + 4 * wsr + 0] = omega34;
      omega[i * wsi + 5 * wsl + 5 * wsr + 0] = omega35;
    }
}

PyObject *
py_weights_gauss_lobatto006006 (PyObject * self, PyObject * args)
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

  weights_gauss_lobatto006006 (sigma, n, ssi, ssr, omega, wsi, wsl, wsr);

  Py_INCREF (Py_None);
  return Py_None;
}

void
reconstruct_gauss_lobatto006006 (const double *restrict f, int n, int fsi,
				 const double *restrict omega, int wsi, int wsl, int wsr,
				 double *restrict fr, int frsi, int frsl)
{
  int i;
  double omega9, omega22p, omega21m, omega22m, omega15p, omega31, omega21p, omega16m, omega14p,
    omega3, omega24, omega8, omega16p, omega35, omega28, omega15m, omega11, omega12m, omega4,
    omega29, omega25, omega12p, omega20p, omega23m, omega34, omega0, omega19m, omega30, omega20m,
    omega17p, omega19p, omega10, omega17m, omega5, omega26, omega6, omega33, omega1, omega13p,
    omega23p, omega14m, omega13m, omega7, omega18p, omega27, omega18m, omega32, omega2, fs0, fs1,
    fs2, fs3, fs4, fs5, fr9, fr18, fr34, fr13, fr31, fr17, fr3, fr24, fr8, fr21, fr28, fr11, fr30,
    fr14, fr33, fr25, fr7, fr20, fr0, fr29, fr4, fr35, fr10, fr5, fr26, fr6, fr23, fr1, fr32, fr19,
    fr2, fr12, fr27, fr15, fr22, fr16;
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
      omega12p = omega[i * wsi + 2 * wsl + 0 * wsr + 0];
      omega12m = omega[i * wsi + 2 * wsl + 0 * wsr + 1];
      omega13p = omega[i * wsi + 2 * wsl + 1 * wsr + 0];
      omega13m = omega[i * wsi + 2 * wsl + 1 * wsr + 1];
      omega14p = omega[i * wsi + 2 * wsl + 2 * wsr + 0];
      omega14m = omega[i * wsi + 2 * wsl + 2 * wsr + 1];
      omega15p = omega[i * wsi + 2 * wsl + 3 * wsr + 0];
      omega15m = omega[i * wsi + 2 * wsl + 3 * wsr + 1];
      omega16p = omega[i * wsi + 2 * wsl + 4 * wsr + 0];
      omega16m = omega[i * wsi + 2 * wsl + 4 * wsr + 1];
      omega17p = omega[i * wsi + 2 * wsl + 5 * wsr + 0];
      omega17m = omega[i * wsi + 2 * wsl + 5 * wsr + 1];
      omega18p = omega[i * wsi + 3 * wsl + 0 * wsr + 0];
      omega18m = omega[i * wsi + 3 * wsl + 0 * wsr + 1];
      omega19p = omega[i * wsi + 3 * wsl + 1 * wsr + 0];
      omega19m = omega[i * wsi + 3 * wsl + 1 * wsr + 1];
      omega20p = omega[i * wsi + 3 * wsl + 2 * wsr + 0];
      omega20m = omega[i * wsi + 3 * wsl + 2 * wsr + 1];
      omega21p = omega[i * wsi + 3 * wsl + 3 * wsr + 0];
      omega21m = omega[i * wsi + 3 * wsl + 3 * wsr + 1];
      omega22p = omega[i * wsi + 3 * wsl + 4 * wsr + 0];
      omega22m = omega[i * wsi + 3 * wsl + 4 * wsr + 1];
      omega23p = omega[i * wsi + 3 * wsl + 5 * wsr + 0];
      omega23m = omega[i * wsi + 3 * wsl + 5 * wsr + 1];
      omega24 = omega[i * wsi + 4 * wsl + 0 * wsr + 0];
      omega25 = omega[i * wsi + 4 * wsl + 1 * wsr + 0];
      omega26 = omega[i * wsi + 4 * wsl + 2 * wsr + 0];
      omega27 = omega[i * wsi + 4 * wsl + 3 * wsr + 0];
      omega28 = omega[i * wsi + 4 * wsl + 4 * wsr + 0];
      omega29 = omega[i * wsi + 4 * wsl + 5 * wsr + 0];
      omega30 = omega[i * wsi + 5 * wsl + 0 * wsr + 0];
      omega31 = omega[i * wsi + 5 * wsl + 1 * wsr + 0];
      omega32 = omega[i * wsi + 5 * wsl + 2 * wsr + 0];
      omega33 = omega[i * wsi + 5 * wsl + 3 * wsr + 0];
      omega34 = omega[i * wsi + 5 * wsl + 4 * wsr + 0];
      omega35 = omega[i * wsi + 5 * wsl + 5 * wsr + 0];
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
	(+1.96078249203886) * (f[(i + 0) * fsi]) + (-2.18707715373115) * (f[(i + 1) * fsi]) +
	(+2.25632893215732) * (f[(i + 2) * fsi]) + (-1.5014772762149) * (f[(i + 3) * fsi]) +
	(+0.560891572652889) * (f[(i + 4) * fsi]) + (-0.0894485669030144) * (f[(i + 5) * fsi]);
      fr7 =
	(+0.0894485669030144) * (f[(i - 1) * fsi]) + (+1.42409109062077) * (f[(i + 0) * fsi]) +
	(-0.845348650185933) * (f[(i + 1) * fsi]) + (+0.467357594097033) * (f[(i + 2) * fsi]) +
	(-0.159748772669687) * (f[(i + 3) * fsi]) + (+0.0242001712348024) * (f[(i + 4) * fsi]);
      fr8 =
	(-0.0242001712348024) * (f[(i - 2) * fsi]) + (+0.234649594311829) * (f[(i - 1) * fsi]) +
	(+1.06108852209873) * (f[(i + 0) * fsi]) + (-0.361345225489885) * (f[(i + 1) * fsi]) +
	(+0.104355025574996) * (f[(i + 2) * fsi]) + (-0.0145477452608721) * (f[(i + 3) * fsi]);
      fr9 =
	(+0.0145477452608721) * (f[(i - 3) * fsi]) + (-0.111486642800035) * (f[(i - 2) * fsi]) +
	(+0.45286577322491) * (f[(i - 1) * fsi]) + (+0.770133616881292) * (f[(i + 0) * fsi]) +
	(-0.143129046576803) * (f[(i + 1) * fsi]) + (+0.0170685540097638) * (f[(i + 2) * fsi]);
      fr10 =
	(-0.0170685540097638) * (f[(i - 4) * fsi]) + (+0.116959069319455) * (f[(i - 3) * fsi]) +
	(-0.367514952946492) * (f[(i - 2) * fsi]) + (+0.794236853420187) * (f[(i - 1) * fsi]) +
	(+0.514105306734835) * (f[(i + 0) * fsi]) + (-0.0407177225182204) * (f[(i + 1) * fsi]);
      fr11 =
	(+0.0407177225182204) * (f[(i - 5) * fsi]) + (-0.261374889119086) * (f[(i - 4) * fsi]) +
	(+0.727724907092762) * (f[(i - 3) * fsi]) + (-1.1818694033109) * (f[(i - 2) * fsi]) +
	(+1.40500269119349) * (f[(i - 1) * fsi]) + (+0.269798971625512) * (f[(i + 0) * fsi]);
      fr12 =
	(+1.18690521046589) * (f[(i + 0) * fsi]) + (-0.224063030770414) * (f[(i + 1) * fsi]) +
	(+0.0129097600759511) * (f[(i + 2) * fsi]) + (+0.0468706723997809) * (f[(i + 3) * fsi]) +
	(-0.0281287960348689) * (f[(i + 4) * fsi]) + (+0.00550618386366469) * (f[(i + 5) * fsi]);
      fr13 =
	(-0.00550618386366469) * (f[(i - 1) * fsi]) + (+1.21994231364787) * (f[(i + 0) * fsi]) +
	(-0.306655788725384) * (f[(i + 1) * fsi]) + (+0.123033437349244) * (f[(i + 2) * fsi]) +
	(-0.0357220855551892) * (f[(i + 3) * fsi]) + (+0.00490830714711897) * (f[(i + 4) * fsi]);
      fr14 =
	(-0.00490830714711897) * (f[(i - 2) * fsi]) + (+0.0239436590190492) * (f[(i - 1) * fsi]) +
	(+1.14631770644109) * (f[(i + 0) * fsi]) + (-0.208489645783004) * (f[(i + 1) * fsi]) +
	(+0.0494088301424595) * (f[(i + 2) * fsi]) + (-0.00627224267247537) * (f[(i + 3) * fsi]);
      fr15 =
	(+0.00627224267247537) * (f[(i - 3) * fsi]) + (-0.0425417631819712) * (f[(i - 2) * fsi]) +
	(+0.11802729910618) * (f[(i - 1) * fsi]) + (+1.02087285299158) * (f[(i + 0) * fsi]) +
	(-0.114406005695874) * (f[(i + 1) * fsi]) + (+0.0117753741076073) * (f[(i + 2) * fsi]);
      fr16 =
	(-0.0117753741076073) * (f[(i - 4) * fsi]) + (+0.0769244873181192) * (f[(i - 3) * fsi]) +
	(-0.219172374796081) * (f[(i - 2) * fsi]) + (+0.353534781258326) * (f[(i - 1) * fsi]) +
	(+0.844242241377473) * (f[(i + 0) * fsi]) + (-0.0437537610502299) * (f[(i + 1) * fsi]);
      fr17 =
	(+0.0437537610502299) * (f[(i - 5) * fsi]) + (-0.274297940408987) * (f[(i - 4) * fsi]) +
	(+0.733230903071567) * (f[(i - 3) * fsi]) + (-1.09424759580068) * (f[(i - 2) * fsi]) +
	(+1.00984119701177) * (f[(i - 1) * fsi]) + (+0.581719675076094) * (f[(i + 0) * fsi]);
      fr18 =
	(+0.581719675076094) * (f[(i + 0) * fsi]) + (+1.00984119701177) * (f[(i + 1) * fsi]) +
	(-1.09424759580068) * (f[(i + 2) * fsi]) + (+0.733230903071567) * (f[(i + 3) * fsi]) +
	(-0.274297940408987) * (f[(i + 4) * fsi]) + (+0.0437537610502298) * (f[(i + 5) * fsi]);
      fr19 =
	(-0.0437537610502299) * (f[(i - 1) * fsi]) + (+0.844242241377473) * (f[(i + 0) * fsi]) +
	(+0.353534781258326) * (f[(i + 1) * fsi]) + (-0.219172374796081) * (f[(i + 2) * fsi]) +
	(+0.0769244873181192) * (f[(i + 3) * fsi]) + (-0.0117753741076073) * (f[(i + 4) * fsi]);
      fr20 =
	(+0.0117753741076073) * (f[(i - 2) * fsi]) + (-0.114406005695874) * (f[(i - 1) * fsi]) +
	(+1.02087285299158) * (f[(i + 0) * fsi]) + (+0.11802729910618) * (f[(i + 1) * fsi]) +
	(-0.0425417631819712) * (f[(i + 2) * fsi]) + (+0.00627224267247538) * (f[(i + 3) * fsi]);
      fr21 =
	(-0.00627224267247537) * (f[(i - 3) * fsi]) + (+0.0494088301424595) * (f[(i - 2) * fsi]) +
	(-0.208489645783004) * (f[(i - 1) * fsi]) + (+1.14631770644109) * (f[(i + 0) * fsi]) +
	(+0.0239436590190492) * (f[(i + 1) * fsi]) + (-0.00490830714711897) * (f[(i + 2) * fsi]);
      fr22 =
	(+0.00490830714711897) * (f[(i - 4) * fsi]) + (-0.0357220855551892) * (f[(i - 3) * fsi]) +
	(+0.123033437349244) * (f[(i - 2) * fsi]) + (-0.306655788725384) * (f[(i - 1) * fsi]) +
	(+1.21994231364787) * (f[(i + 0) * fsi]) + (-0.00550618386366465) * (f[(i + 1) * fsi]);
      fr23 =
	(+0.00550618386366464) * (f[(i - 5) * fsi]) + (-0.0281287960348689) * (f[(i - 4) * fsi]) +
	(+0.0468706723997806) * (f[(i - 3) * fsi]) + (+0.0129097600759509) * (f[(i - 2) * fsi]) +
	(-0.224063030770414) * (f[(i - 1) * fsi]) + (+1.18690521046589) * (f[(i + 0) * fsi]);
      fr24 =
	(+0.269798971625512) * (f[(i + 0) * fsi]) + (+1.40500269119349) * (f[(i + 1) * fsi]) +
	(-1.1818694033109) * (f[(i + 2) * fsi]) + (+0.727724907092761) * (f[(i + 3) * fsi]) +
	(-0.261374889119087) * (f[(i + 4) * fsi]) + (+0.0407177225182204) * (f[(i + 5) * fsi]);
      fr25 =
	(-0.0407177225182205) * (f[(i - 1) * fsi]) + (+0.514105306734835) * (f[(i + 0) * fsi]) +
	(+0.794236853420187) * (f[(i + 1) * fsi]) + (-0.367514952946492) * (f[(i + 2) * fsi]) +
	(+0.116959069319455) * (f[(i + 3) * fsi]) + (-0.0170685540097638) * (f[(i + 4) * fsi]);
      fr26 =
	(+0.0170685540097638) * (f[(i - 2) * fsi]) + (-0.143129046576803) * (f[(i - 1) * fsi]) +
	(+0.770133616881292) * (f[(i + 0) * fsi]) + (+0.45286577322491) * (f[(i + 1) * fsi]) +
	(-0.111486642800035) * (f[(i + 2) * fsi]) + (+0.0145477452608721) * (f[(i + 3) * fsi]);
      fr27 =
	(-0.0145477452608721) * (f[(i - 3) * fsi]) + (+0.104355025574996) * (f[(i - 2) * fsi]) +
	(-0.361345225489885) * (f[(i - 1) * fsi]) + (+1.06108852209873) * (f[(i + 0) * fsi]) +
	(+0.234649594311829) * (f[(i + 1) * fsi]) + (-0.0242001712348024) * (f[(i + 2) * fsi]);
      fr28 =
	(+0.0242001712348024) * (f[(i - 4) * fsi]) + (-0.159748772669687) * (f[(i - 3) * fsi]) +
	(+0.467357594097033) * (f[(i - 2) * fsi]) + (-0.845348650185933) * (f[(i - 1) * fsi]) +
	(+1.42409109062077) * (f[(i + 0) * fsi]) + (+0.0894485669030145) * (f[(i + 1) * fsi]);
      fr29 =
	(-0.0894485669030145) * (f[(i - 5) * fsi]) + (+0.560891572652889) * (f[(i - 4) * fsi]) +
	(-1.5014772762149) * (f[(i - 3) * fsi]) + (+2.25632893215732) * (f[(i - 2) * fsi]) +
	(-2.18707715373115) * (f[(i - 1) * fsi]) + (+1.96078249203886) * (f[(i + 0) * fsi]);
      fr30 =
	(+0.166666666666667) * (f[(i + 0) * fsi]) + (+1.45) * (f[(i + 1) * fsi]) +
	(-1.05) * (f[(i + 2) * fsi]) + (+0.616666666666667) * (f[(i + 3) * fsi]) +
	(-0.216666666666667) * (f[(i + 4) * fsi]) + (+0.0333333333333332) * (f[(i + 5) * fsi]);
      fr31 =
	(-0.0333333333333333) * (f[(i - 1) * fsi]) + (+0.366666666666667) * (f[(i + 0) * fsi]) +
	(+0.95) * (f[(i + 1) * fsi]) + (-0.383333333333333) * (f[(i + 2) * fsi]) +
	(+0.116666666666667) * (f[(i + 3) * fsi]) + (-0.0166666666666667) * (f[(i + 4) * fsi]);
      fr32 =
	(+0.0166666666666667) * (f[(i - 2) * fsi]) + (-0.133333333333333) * (f[(i - 1) * fsi]) +
	(+0.616666666666666) * (f[(i + 0) * fsi]) + (+0.616666666666667) * (f[(i + 1) * fsi]) +
	(-0.133333333333333) * (f[(i + 2) * fsi]) + (+0.0166666666666667) * (f[(i + 3) * fsi]);
      fr33 =
	(-0.0166666666666667) * (f[(i - 3) * fsi]) + (+0.116666666666667) * (f[(i - 2) * fsi]) +
	(-0.383333333333333) * (f[(i - 1) * fsi]) + (+0.95) * (f[(i + 0) * fsi]) +
	(+0.366666666666667) * (f[(i + 1) * fsi]) + (-0.0333333333333333) * (f[(i + 2) * fsi]);
      fr34 =
	(+0.0333333333333333) * (f[(i - 4) * fsi]) + (-0.216666666666667) * (f[(i - 3) * fsi]) +
	(+0.616666666666667) * (f[(i - 2) * fsi]) + (-1.05) * (f[(i - 1) * fsi]) +
	(+1.45) * (f[(i + 0) * fsi]) + (+0.166666666666667) * (f[(i + 1) * fsi]);
      fr35 =
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
	((+2.0946327278248) *
	 ((omega12p) * (fr12) + (omega13p) * (fr13) + (omega14p) * (fr14) + (omega15p) * (fr15) +
	  (omega16p) * (fr16) + (omega17p) * (fr17))) - ((+1.0946327278248) * ((omega12m) * (fr12) +
									       (omega13m) * (fr13) +
									       (omega14m) * (fr14) +
									       (omega15m) * (fr15) +
									       (omega16m) * (fr16) +
									       (omega17m) *
									       (fr17)));
      fs3 =
	((+2.09463272782487) *
	 ((omega18p) * (fr18) + (omega19p) * (fr19) + (omega20p) * (fr20) + (omega21p) * (fr21) +
	  (omega22p) * (fr22) + (omega23p) * (fr23))) -
	((+1.09463272782487) *
	 ((omega18m) * (fr18) + (omega19m) * (fr19) + (omega20m) * (fr20) + (omega21m) * (fr21) +
	  (omega22m) * (fr22) + (omega23m) * (fr23)));
      fs4 =
	(omega24) * (fr24) + (omega25) * (fr25) + (omega26) * (fr26) + (omega27) * (fr27) +
	(omega28) * (fr28) + (omega29) * (fr29);
      fs5 =
	(omega30) * (fr30) + (omega31) * (fr31) + (omega32) * (fr32) + (omega33) * (fr33) +
	(omega34) * (fr34) + (omega35) * (fr35);
      fr[i * frsi + 0 * frsl] = fs0;
      fr[i * frsi + 1 * frsl] = fs1;
      fr[i * frsi + 2 * frsl] = fs2;
      fr[i * frsi + 3 * frsl] = fs3;
      fr[i * frsi + 4 * frsl] = fs4;
      fr[i * frsi + 5 * frsl] = fs5;
    }
}

PyObject *
py_reconstruct_gauss_lobatto006006 (PyObject * self, PyObject * args)
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

  reconstruct_gauss_lobatto006006 (f, n, fsi, omega, wsi, wsl, wsr, fr, frsi, frsl);

  Py_INCREF (Py_None);
  return Py_None;
}
