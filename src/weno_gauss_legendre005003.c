#include <Python.h>
#include <numpy/ndarrayobject.h>

void
weights_gauss_legendre005003 (const double *restrict sigma, int n, int ssi, int ssr,
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
      omega0 = (+0.0128660997926876) / ((sigma0 + 1.0e-6) * (sigma0 + 1.0e-6));
      acc = acc + omega0;
      omega1 = (+0.193161100352692) / ((sigma1 + 1.0e-6) * (sigma1 + 1.0e-6));
      acc = acc + omega1;
      omega2 = (+0.486295489821503) / ((sigma2 + 1.0e-6) * (sigma2 + 1.0e-6));
      acc = acc + omega2;
      omega3 = (+0.278295502287896) / ((sigma3 + 1.0e-6) * (sigma3 + 1.0e-6));
      acc = acc + omega3;
      omega4 = (+0.0293818077452212) / ((sigma4 + 1.0e-6) * (sigma4 + 1.0e-6));
      acc = acc + omega4;
      omega0 = (omega0) / (acc);
      omega1 = (omega1) / (acc);
      omega2 = (omega2) / (acc);
      omega3 = (omega3) / (acc);
      omega4 = (omega4) / (acc);
      acc = 0.0;
      omega5p =
	((+0.0032093603286385) / (+3.34858630952381)) / ((sigma0 + 1.0e-6) * (sigma0 + 1.0e-6));
      acc = acc + omega5p;
      omega6p =
	((+0.221555024591996) / (+3.34858630952381)) / ((sigma1 + 1.0e-6) * (sigma1 + 1.0e-6));
      acc = acc + omega6p;
      omega7p =
	((+2.89905753968254) / (+3.34858630952381)) / ((sigma2 + 1.0e-6) * (sigma2 + 1.0e-6));
      acc = acc + omega7p;
      omega8p =
	((+0.221555024591996) / (+3.34858630952381)) / ((sigma3 + 1.0e-6) * (sigma3 + 1.0e-6));
      acc = acc + omega8p;
      omega9p =
	((+0.0032093603286385) / (+3.34858630952381)) / ((sigma4 + 1.0e-6) * (sigma4 + 1.0e-6));
      acc = acc + omega9p;
      omega5p = (omega5p) / (acc);
      omega6p = (omega6p) / (acc);
      omega7p = (omega7p) / (acc);
      omega8p = (omega8p) / (acc);
      omega9p = (omega9p) / (acc);
      acc = 0.0;
      omega5m =
	((+0.006418720657277) / (+2.34858630952381)) / ((sigma0 + 1.0e-6) * (sigma0 + 1.0e-6));
      acc = acc + omega5m;
      omega6m =
	((+0.443110049183993) / (+2.34858630952381)) / ((sigma1 + 1.0e-6) * (sigma1 + 1.0e-6));
      acc = acc + omega6m;
      omega7m =
	((+1.44952876984127) / (+2.34858630952381)) / ((sigma2 + 1.0e-6) * (sigma2 + 1.0e-6));
      acc = acc + omega7m;
      omega8m =
	((+0.443110049183993) / (+2.34858630952381)) / ((sigma3 + 1.0e-6) * (sigma3 + 1.0e-6));
      acc = acc + omega8m;
      omega9m =
	((+0.006418720657277) / (+2.34858630952381)) / ((sigma4 + 1.0e-6) * (sigma4 + 1.0e-6));
      acc = acc + omega9m;
      omega5m = (omega5m) / (acc);
      omega6m = (omega6m) / (acc);
      omega7m = (omega7m) / (acc);
      omega8m = (omega8m) / (acc);
      omega9m = (omega9m) / (acc);
      acc = 0.0;
      omega10 = (+0.0293818077452197) / ((sigma0 + 1.0e-6) * (sigma0 + 1.0e-6));
      acc = acc + omega10;
      omega11 = (+0.278295502287894) / ((sigma1 + 1.0e-6) * (sigma1 + 1.0e-6));
      acc = acc + omega11;
      omega12 = (+0.486295489821505) / ((sigma2 + 1.0e-6) * (sigma2 + 1.0e-6));
      acc = acc + omega12;
      omega13 = (+0.193161100352692) / ((sigma3 + 1.0e-6) * (sigma3 + 1.0e-6));
      acc = acc + omega13;
      omega14 = (+0.0128660997926873) / ((sigma4 + 1.0e-6) * (sigma4 + 1.0e-6));
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
py_weights_gauss_legendre005003 (PyObject * self, PyObject * args)
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

  weights_gauss_legendre005003 (sigma, n, ssi, ssr, omega, wsi, wsl, wsr);

  Py_INCREF (Py_None);
  return Py_None;
}

void
reconstruct_gauss_legendre005003 (const double *restrict f, int n, int fsi,
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
	(+1.88698409985068) * (f[(i + 0) * fsi]) + (-1.77609858828986) * (f[(i + 1) * fsi]) +
	(+1.39526867027141) * (f[(i + 2) * fsi]) + (-0.622879640455236) * (f[(i + 3) * fsi]) +
	(+0.116725458623) * (f[(i + 4) * fsi]);
      fr1 =
	(+0.116725458623) * (f[(i - 1) * fsi]) + (+1.30335680673568) * (f[(i + 0) * fsi]) +
	(-0.608844002059853) * (f[(i + 1) * fsi]) + (+0.228014084041408) * (f[(i + 2) * fsi]) +
	(-0.0392523473402347) * (f[(i + 3) * fsi]);
      fr2 =
	(-0.0392523473402347) * (f[(i - 2) * fsi]) + (+0.312987195324174) * (f[(i - 1) * fsi]) +
	(+0.910833333333333) * (f[(i + 0) * fsi]) + (-0.216320528657507) * (f[(i + 1) * fsi]) +
	(+0.0317523473402347) * (f[(i + 2) * fsi]);
      fr3 =
	(+0.0317523473402347) * (f[(i - 3) * fsi]) + (-0.198014084041408) * (f[(i - 2) * fsi]) +
	(+0.63051066872652) * (f[(i - 1) * fsi]) + (+0.593309859930987) * (f[(i + 0) * fsi]) +
	(-0.0575587919563335) * (f[(i + 1) * fsi]);
      fr4 =
	(-0.0575587919563336) * (f[(i - 4) * fsi]) + (+0.319546307121902) * (f[(i - 3) * fsi]) +
	(-0.773602003604743) * (f[(i - 2) * fsi]) + (+1.20609858828986) * (f[(i - 1) * fsi]) +
	(+0.305515900149319) * (f[(i + 0) * fsi]);
      fr5 =
	(+0.8796875) * (f[(i + 0) * fsi]) + (+0.35625) * (f[(i + 1) * fsi]) +
	(-0.388541666666667) * (f[(i + 2) * fsi]) + (+0.189583333333333) * (f[(i + 3) * fsi]) +
	(-0.0369791666666667) * (f[(i + 4) * fsi]);
      fr6 =
	(-0.0369791666666667) * (f[(i - 1) * fsi]) + (+1.06458333333333) * (f[(i + 0) * fsi]) +
	(-0.0135416666666667) * (f[(i + 1) * fsi]) + (-0.01875) * (f[(i + 2) * fsi]) +
	(+0.0046875) * (f[(i + 3) * fsi]);
      fr7 =
	(+0.0046875) * (f[(i - 2) * fsi]) + (-0.0604166666666667) * (f[(i - 1) * fsi]) +
	(+1.11145833333333) * (f[(i + 0) * fsi]) + (-0.0604166666666667) * (f[(i + 1) * fsi]) +
	(+0.0046875) * (f[(i + 2) * fsi]);
      fr8 =
	(+0.0046875) * (f[(i - 3) * fsi]) + (-0.01875) * (f[(i - 2) * fsi]) +
	(-0.0135416666666667) * (f[(i - 1) * fsi]) + (+1.06458333333333) * (f[(i + 0) * fsi]) +
	(-0.0369791666666667) * (f[(i + 1) * fsi]);
      fr9 =
	(-0.0369791666666667) * (f[(i - 4) * fsi]) + (+0.189583333333333) * (f[(i - 3) * fsi]) +
	(-0.388541666666667) * (f[(i - 2) * fsi]) + (+0.35625) * (f[(i - 1) * fsi]) +
	(+0.8796875) * (f[(i + 0) * fsi]);
      fr10 =
	(+0.305515900149319) * (f[(i + 0) * fsi]) + (+1.20609858828986) * (f[(i + 1) * fsi]) +
	(-0.773602003604743) * (f[(i + 2) * fsi]) + (+0.319546307121903) * (f[(i + 3) * fsi]) +
	(-0.0575587919563334) * (f[(i + 4) * fsi]);
      fr11 =
	(-0.0575587919563335) * (f[(i - 1) * fsi]) + (+0.593309859930987) * (f[(i + 0) * fsi]) +
	(+0.63051066872652) * (f[(i + 1) * fsi]) + (-0.198014084041408) * (f[(i + 2) * fsi]) +
	(+0.0317523473402346) * (f[(i + 3) * fsi]);
      fr12 =
	(+0.0317523473402346) * (f[(i - 2) * fsi]) + (-0.216320528657507) * (f[(i - 1) * fsi]) +
	(+0.910833333333333) * (f[(i + 0) * fsi]) + (+0.312987195324174) * (f[(i + 1) * fsi]) +
	(-0.0392523473402347) * (f[(i + 2) * fsi]);
      fr13 =
	(-0.0392523473402347) * (f[(i - 3) * fsi]) + (+0.228014084041408) * (f[(i - 2) * fsi]) +
	(-0.608844002059853) * (f[(i - 1) * fsi]) + (+1.30335680673568) * (f[(i + 0) * fsi]) +
	(+0.116725458623) * (f[(i + 1) * fsi]);
      fr14 =
	(+0.116725458623) * (f[(i - 4) * fsi]) + (-0.622879640455236) * (f[(i - 3) * fsi]) +
	(+1.39526867027141) * (f[(i - 2) * fsi]) + (-1.77609858828986) * (f[(i - 1) * fsi]) +
	(+1.88698409985068) * (f[(i + 0) * fsi]);
      fs0 =
	(omega0) * (fr0) + (omega1) * (fr1) + (omega2) * (fr2) + (omega3) * (fr3) +
	(omega4) * (fr4);
      fs1 =
	((+3.34858630952381) *
	 ((omega5p) * (fr5) + (omega6p) * (fr6) + (omega7p) * (fr7) + (omega8p) * (fr8) +
	  (omega9p) * (fr9))) - ((+2.34858630952381) * ((omega5m) * (fr5) + (omega6m) * (fr6) +
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
py_reconstruct_gauss_legendre005003 (PyObject * self, PyObject * args)
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

  reconstruct_gauss_legendre005003 (f, n, fsi, omega, wsi, wsl, wsr, fr, frsi, frsl);

  Py_INCREF (Py_None);
  return Py_None;
}
