#include <Python.h>
#include <numpy/ndarrayobject.h>

void
weights_gauss_legendre006006 (const double *restrict sigma, int n, int ssi, int ssr,
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
      omega0 = (+0.00252745991472157) / ((sigma0 + 1.0e-6) * (sigma0 + 1.0e-6));
      acc = acc + omega0;
      omega1 = (+0.0700105625870434) / ((sigma1 + 1.0e-6) * (sigma1 + 1.0e-6));
      acc = acc + omega1;
      omega2 = (+0.333743850302432) / ((sigma2 + 1.0e-6) * (sigma2 + 1.0e-6));
      acc = acc + omega2;
      omega3 = (+0.427735050960922) / ((sigma3 + 1.0e-6) * (sigma3 + 1.0e-6));
      acc = acc + omega3;
      omega4 = (+0.154212356564917) / ((sigma4 + 1.0e-6) * (sigma4 + 1.0e-6));
      acc = acc + omega4;
      omega5 = (+0.0117707196699639) / ((sigma5 + 1.0e-6) * (sigma5 + 1.0e-6));
      acc = acc + omega5;
      omega0 = (omega0) / (acc);
      omega1 = (omega1) / (acc);
      omega2 = (omega2) / (acc);
      omega3 = (omega3) / (acc);
      omega4 = (omega4) / (acc);
      omega5 = (omega5) / (acc);
      acc = 0.0;
      omega6 = (+0.00506309923405956) / ((sigma0 + 1.0e-6) * (sigma0 + 1.0e-6));
      acc = acc + omega6;
      omega7 = (+0.09587232772999) / ((sigma1 + 1.0e-6) * (sigma1 + 1.0e-6));
      acc = acc + omega7;
      omega8 = (+0.369353495566387) / ((sigma2 + 1.0e-6) * (sigma2 + 1.0e-6));
      acc = acc + omega8;
      omega9 = (+0.399606215642361) / ((sigma3 + 1.0e-6) * (sigma3 + 1.0e-6));
      acc = acc + omega9;
      omega10 = (+0.12238288266895) / ((sigma4 + 1.0e-6) * (sigma4 + 1.0e-6));
      acc = acc + omega10;
      omega11 = (+0.00772197915825236) / ((sigma5 + 1.0e-6) * (sigma5 + 1.0e-6));
      acc = acc + omega11;
      omega6 = (omega6) / (acc);
      omega7 = (omega7) / (acc);
      omega8 = (omega8) / (acc);
      omega9 = (omega9) / (acc);
      omega10 = (omega10) / (acc);
      omega11 = (omega11) / (acc);
      acc = 0.0;
      omega12p =
	((+0.0135264534619149) / (+2.04057936038575)) / ((sigma0 + 1.0e-6) * (sigma0 + 1.0e-6));
      acc = acc + omega12p;
      omega13p =
	((+0.664114274304398) / (+2.04057936038575)) / ((sigma1 + 1.0e-6) * (sigma1 + 1.0e-6));
      acc = acc + omega13p;
      omega14p =
	((+0.687666030009182) / (+2.04057936038575)) / ((sigma2 + 1.0e-6) * (sigma2 + 1.0e-6));
      acc = acc + omega14p;
      omega15p =
	((+0.547971984541066) / (+2.04057936038575)) / ((sigma3 + 1.0e-6) * (sigma3 + 1.0e-6));
      acc = acc + omega15p;
      omega16p =
	((+0.121881829197595) / (+2.04057936038575)) / ((sigma4 + 1.0e-6) * (sigma4 + 1.0e-6));
      acc = acc + omega16p;
      omega17p =
	((+0.00541878887159026) / (+2.04057936038575)) / ((sigma5 + 1.0e-6) * (sigma5 + 1.0e-6));
      acc = acc + omega17p;
      omega12p = (omega12p) / (acc);
      omega13p = (omega13p) / (acc);
      omega14p = (omega14p) / (acc);
      omega15p = (omega15p) / (acc);
      omega16p = (omega16p) / (acc);
      omega17p = (omega17p) / (acc);
      acc = 0.0;
      omega12m =
	((+0.0270529069238299) / (+1.04057936038575)) / ((sigma0 + 1.0e-6) * (sigma0 + 1.0e-6));
      acc = acc + omega12m;
      omega13m =
	((+0.332057137152199) / (+1.04057936038575)) / ((sigma1 + 1.0e-6) * (sigma1 + 1.0e-6));
      acc = acc + omega13m;
      omega14m =
	((+0.343833015004591) / (+1.04057936038575)) / ((sigma2 + 1.0e-6) * (sigma2 + 1.0e-6));
      acc = acc + omega14m;
      omega15m =
	((+0.273985992270533) / (+1.04057936038575)) / ((sigma3 + 1.0e-6) * (sigma3 + 1.0e-6));
      acc = acc + omega15m;
      omega16m =
	((+0.0609409145987976) / (+1.04057936038575)) / ((sigma4 + 1.0e-6) * (sigma4 + 1.0e-6));
      acc = acc + omega16m;
      omega17m =
	((+0.00270939443579513) / (+1.04057936038575)) / ((sigma5 + 1.0e-6) * (sigma5 + 1.0e-6));
      acc = acc + omega17m;
      omega12m = (omega12m) / (acc);
      omega13m = (omega13m) / (acc);
      omega14m = (omega14m) / (acc);
      omega15m = (omega15m) / (acc);
      omega16m = (omega16m) / (acc);
      omega17m = (omega17m) / (acc);
      acc = 0.0;
      omega18p =
	((+0.00541878887160147) / (+2.04057936038583)) / ((sigma0 + 1.0e-6) * (sigma0 + 1.0e-6));
      acc = acc + omega18p;
      omega19p =
	((+0.121881829197581) / (+2.04057936038583)) / ((sigma1 + 1.0e-6) * (sigma1 + 1.0e-6));
      acc = acc + omega19p;
      omega20p =
	((+0.547971984541069) / (+2.04057936038583)) / ((sigma2 + 1.0e-6) * (sigma2 + 1.0e-6));
      acc = acc + omega20p;
      omega21p =
	((+0.687666030009216) / (+2.04057936038583)) / ((sigma3 + 1.0e-6) * (sigma3 + 1.0e-6));
      acc = acc + omega21p;
      omega22p =
	((+0.66411427430442) / (+2.04057936038583)) / ((sigma4 + 1.0e-6) * (sigma4 + 1.0e-6));
      acc = acc + omega22p;
      omega23p =
	((+0.0135264534619428) / (+2.04057936038583)) / ((sigma5 + 1.0e-6) * (sigma5 + 1.0e-6));
      acc = acc + omega23p;
      omega18p = (omega18p) / (acc);
      omega19p = (omega19p) / (acc);
      omega20p = (omega20p) / (acc);
      omega21p = (omega21p) / (acc);
      omega22p = (omega22p) / (acc);
      omega23p = (omega23p) / (acc);
      acc = 0.0;
      omega18m =
	((+0.00270939443580073) / (+1.04057936038583)) / ((sigma0 + 1.0e-6) * (sigma0 + 1.0e-6));
      acc = acc + omega18m;
      omega19m =
	((+0.0609409145987905) / (+1.04057936038583)) / ((sigma1 + 1.0e-6) * (sigma1 + 1.0e-6));
      acc = acc + omega19m;
      omega20m =
	((+0.273985992270534) / (+1.04057936038583)) / ((sigma2 + 1.0e-6) * (sigma2 + 1.0e-6));
      acc = acc + omega20m;
      omega21m =
	((+0.343833015004608) / (+1.04057936038583)) / ((sigma3 + 1.0e-6) * (sigma3 + 1.0e-6));
      acc = acc + omega21m;
      omega22m =
	((+0.33205713715221) / (+1.04057936038583)) / ((sigma4 + 1.0e-6) * (sigma4 + 1.0e-6));
      acc = acc + omega22m;
      omega23m =
	((+0.0270529069238855) / (+1.04057936038583)) / ((sigma5 + 1.0e-6) * (sigma5 + 1.0e-6));
      acc = acc + omega23m;
      omega18m = (omega18m) / (acc);
      omega19m = (omega19m) / (acc);
      omega20m = (omega20m) / (acc);
      omega21m = (omega21m) / (acc);
      omega22m = (omega22m) / (acc);
      omega23m = (omega23m) / (acc);
      acc = 0.0;
      omega24 = (+0.00772197915825038) / ((sigma0 + 1.0e-6) * (sigma0 + 1.0e-6));
      acc = acc + omega24;
      omega25 = (+0.12238288266895) / ((sigma1 + 1.0e-6) * (sigma1 + 1.0e-6));
      acc = acc + omega25;
      omega26 = (+0.399606215642361) / ((sigma2 + 1.0e-6) * (sigma2 + 1.0e-6));
      acc = acc + omega26;
      omega27 = (+0.369353495566388) / ((sigma3 + 1.0e-6) * (sigma3 + 1.0e-6));
      acc = acc + omega27;
      omega28 = (+0.0958723277299899) / ((sigma4 + 1.0e-6) * (sigma4 + 1.0e-6));
      acc = acc + omega28;
      omega29 = (+0.0050630992340596) / ((sigma5 + 1.0e-6) * (sigma5 + 1.0e-6));
      acc = acc + omega29;
      omega24 = (omega24) / (acc);
      omega25 = (omega25) / (acc);
      omega26 = (omega26) / (acc);
      omega27 = (omega27) / (acc);
      omega28 = (omega28) / (acc);
      omega29 = (omega29) / (acc);
      acc = 0.0;
      omega30 = (+0.0117707196699603) / ((sigma0 + 1.0e-6) * (sigma0 + 1.0e-6));
      acc = acc + omega30;
      omega31 = (+0.154212356564917) / ((sigma1 + 1.0e-6) * (sigma1 + 1.0e-6));
      acc = acc + omega31;
      omega32 = (+0.427735050960924) / ((sigma2 + 1.0e-6) * (sigma2 + 1.0e-6));
      acc = acc + omega32;
      omega33 = (+0.333743850302432) / ((sigma3 + 1.0e-6) * (sigma3 + 1.0e-6));
      acc = acc + omega33;
      omega34 = (+0.0700105625870426) / ((sigma4 + 1.0e-6) * (sigma4 + 1.0e-6));
      acc = acc + omega34;
      omega35 = (+0.00252745991472214) / ((sigma5 + 1.0e-6) * (sigma5 + 1.0e-6));
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
py_weights_gauss_legendre006006 (PyObject * self, PyObject * args)
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

  weights_gauss_legendre006006 (sigma, n, ssi, ssr, omega, wsi, wsl, wsr);

  Py_INCREF (Py_None);
  return Py_None;
}

void
reconstruct_gauss_legendre006006 (const double *restrict f, int n, int fsi,
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
	(+2.30113553123989) * (f[(i + 0) * fsi]) + (-3.12768275864755) * (f[(i + 1) * fsi]) +
	(+3.41709585369977) * (f[(i + 2) * fsi]) + (-2.33146915695772) * (f[(i + 3) * fsi]) +
	(+0.882938888308441) * (f[(i + 4) * fsi]) + (-0.142018357642836) * (f[(i + 5) * fsi]);
      fr1 =
	(+0.142018357642836) * (f[(i - 1) * fsi]) + (+1.44902538538287) * (f[(i + 0) * fsi]) +
	(-0.997407394005004) * (f[(i + 1) * fsi]) + (+0.576728700843046) * (f[(i + 2) * fsi]) +
	(-0.201193792315175) * (f[(i + 3) * fsi]) + (+0.0308287424514247) * (f[(i + 4) * fsi]);
      fr2 =
	(-0.0308287424514247) * (f[(i - 2) * fsi]) + (+0.326990812351384) * (f[(i - 1) * fsi]) +
	(+0.986594248611503) * (f[(i + 0) * fsi]) + (-0.380832544976511) * (f[(i + 1) * fsi]) +
	(+0.114297564071676) * (f[(i + 2) * fsi]) + (-0.0162213376066272) * (f[(i + 3) * fsi]);
      fr3 =
	(+0.0162213376066272) * (f[(i - 3) * fsi]) + (-0.128156768091188) * (f[(i - 2) * fsi]) +
	(+0.570310876450792) * (f[(i - 1) * fsi]) + (+0.662167496478959) * (f[(i + 0) * fsi]) +
	(-0.137512480877103) * (f[(i + 1) * fsi]) + (+0.0169695384319124) * (f[(i + 2) * fsi]);
      fr4 =
	(-0.0169695384319124) * (f[(i - 4) * fsi]) + (+0.118038568198102) * (f[(i - 3) * fsi]) +
	(-0.382699844569874) * (f[(i - 2) * fsi]) + (+0.909701645089041) * (f[(i - 1) * fsi]) +
	(+0.407624420000272) * (f[(i + 0) * fsi]) + (-0.0356952502856283) * (f[(i + 1) * fsi]);
      fr5 =
	(+0.0356952502856283) * (f[(i - 5) * fsi]) + (-0.231141040145682) * (f[(i - 4) * fsi]) +
	(+0.653467322482526) * (f[(i - 3) * fsi]) + (-1.09660485028244) * (f[(i - 2) * fsi]) +
	(+1.44513039937346) * (f[(i - 1) * fsi]) + (+0.193452918286503) * (f[(i + 0) * fsi]);
      fr6 =
	(+1.76910985955695) * (f[(i + 0) * fsi]) + (-1.67505122795369) * (f[(i + 1) * fsi]) +
	(+1.64302262997854) * (f[(i + 2) * fsi]) + (-1.06915493330672) * (f[(i + 3) * fsi]) +
	(+0.394502283940926) * (f[(i + 4) * fsi]) + (-0.0624286122160162) * (f[(i + 5) * fsi]);
      fr7 =
	(+0.0624286122160162) * (f[(i - 1) * fsi]) + (+1.39453818626086) * (f[(i + 0) * fsi]) +
	(-0.738622044713446) * (f[(i + 1) * fsi]) + (+0.394450385658218) * (f[(i + 2) * fsi]) +
	(-0.132725750066475) * (f[(i + 3) * fsi]) + (+0.0199306106448293) * (f[(i + 4) * fsi]);
      fr8 =
	(-0.0199306106448293) * (f[(i - 2) * fsi]) + (+0.182012276084992) * (f[(i - 1) * fsi]) +
	(+1.09557902658842) * (f[(i + 0) * fsi]) + (-0.34000983181686) * (f[(i + 1) * fsi]) +
	(+0.0954912259857788) * (f[(i + 2) * fsi]) + (-0.0131420861974989) * (f[(i + 3) * fsi]);
      fr9 =
	(+0.0131420861974989) * (f[(i - 3) * fsi]) + (-0.0987831278298225) * (f[(i - 2) * fsi]) +
	(+0.379143569047475) * (f[(i - 1) * fsi]) + (+0.83273730263844) * (f[(i + 0) * fsi]) +
	(-0.142878538854377) * (f[(i + 1) * fsi]) + (+0.0166387088007855) * (f[(i + 2) * fsi]);
      fr10 =
	(-0.0166387088007855) * (f[(i - 4) * fsi]) + (+0.112974339002212) * (f[(i - 3) * fsi]) +
	(-0.348363759841606) * (f[(i - 2) * fsi]) + (+0.711917745063186) * (f[(i - 1) * fsi]) +
	(+0.583156670626657) * (f[(i + 0) * fsi]) + (-0.0430462860496635) * (f[(i + 1) * fsi]);
      fr11 =
	(+0.0430462860496635) * (f[(i - 5) * fsi]) + (-0.274916425098767) * (f[(i - 4) * fsi]) +
	(+0.758668629747165) * (f[(i - 3) * fsi]) + (-1.20928948083488) * (f[(i - 2) * fsi]) +
	(+1.35761203580814) * (f[(i - 1) * fsi]) + (+0.324878954328676) * (f[(i + 0) * fsi]);
      fr12 =
	(+1.12585392577203) * (f[(i + 0) * fsi]) + (-0.0835977480163481) * (f[(i + 1) * fsi]) +
	(-0.132441737607555) * (f[(i + 2) * fsi]) + (+0.142716334716828) * (f[(i + 3) * fsi]) +
	(-0.0636765003641633) * (f[(i + 4) * fsi]) + (+0.0111457254992058) * (f[(i + 5) * fsi]);
      fr13 =
	(-0.0111457254992059) * (f[(i - 1) * fsi]) + (+1.19272827876727) * (f[(i + 0) * fsi]) +
	(-0.250783630504437) * (f[(i + 1) * fsi]) + (+0.0904727723765625) * (f[(i + 2) * fsi]) +
	(-0.0244695477712602) * (f[(i + 3) * fsi]) + (+0.00319785263107209) * (f[(i + 4) * fsi]);
      fr14 =
	(-0.00319785263107209) * (f[(i - 2) * fsi]) + (+0.00804139028722667) * (f[(i - 1) * fsi]) +
	(+1.14476048930119) * (f[(i + 0) * fsi]) + (-0.186826577882995) * (f[(i + 1) * fsi]) +
	(+0.0425049829104811) * (f[(i + 2) * fsi]) + (-0.00528243198482766) * (f[(i + 3) * fsi]);
      fr15 =
	(+0.00528243198482765) * (f[(i - 3) * fsi]) + (-0.034892444540038) * (f[(i - 2) * fsi]) +
	(+0.0872778700596415) * (f[(i - 1) * fsi]) + (+1.03911184960463) * (f[(i + 0) * fsi]) +
	(-0.10759009811058) * (f[(i + 1) * fsi]) + (+0.0108103910015151) * (f[(i + 2) * fsi]);
      fr16 =
	(-0.0108103910015151) * (f[(i - 4) * fsi]) + (+0.0701447779939183) * (f[(i - 3) * fsi]) +
	(-0.197048309562765) * (f[(i - 2) * fsi]) + (+0.303485690089944) * (f[(i - 1) * fsi]) +
	(+0.876955984581907) * (f[(i + 0) * fsi]) + (-0.0427277521014896) * (f[(i + 1) * fsi]);
      fr17 =
	(+0.0427277521014896) * (f[(i - 5) * fsi]) + (-0.267176903610453) * (f[(i - 4) * fsi]) +
	(+0.711061059516262) * (f[(i - 3) * fsi]) + (-1.05160335159256) * (f[(i - 2) * fsi]) +
	(+0.944401971612287) * (f[(i - 1) * fsi]) + (+0.62058947197297) * (f[(i + 0) * fsi]);
      fr18 =
	(+0.62058947197297) * (f[(i + 0) * fsi]) + (+0.944401971612288) * (f[(i + 1) * fsi]) +
	(-1.05160335159255) * (f[(i + 2) * fsi]) + (+0.711061059516262) * (f[(i + 3) * fsi]) +
	(-0.267176903610453) * (f[(i + 4) * fsi]) + (+0.0427277521014895) * (f[(i + 5) * fsi]);
      fr19 =
	(-0.0427277521014895) * (f[(i - 1) * fsi]) + (+0.876955984581907) * (f[(i + 0) * fsi]) +
	(+0.303485690089944) * (f[(i + 1) * fsi]) + (-0.197048309562765) * (f[(i + 2) * fsi]) +
	(+0.0701447779939183) * (f[(i + 3) * fsi]) + (-0.0108103910015151) * (f[(i + 4) * fsi]);
      fr20 =
	(+0.0108103910015151) * (f[(i - 2) * fsi]) + (-0.10759009811058) * (f[(i - 1) * fsi]) +
	(+1.03911184960463) * (f[(i + 0) * fsi]) + (+0.0872778700596415) * (f[(i + 1) * fsi]) +
	(-0.034892444540038) * (f[(i + 2) * fsi]) + (+0.00528243198482766) * (f[(i + 3) * fsi]);
      fr21 =
	(-0.00528243198482766) * (f[(i - 3) * fsi]) + (+0.042504982910481) * (f[(i - 2) * fsi]) +
	(-0.186826577882995) * (f[(i - 1) * fsi]) + (+1.14476048930119) * (f[(i + 0) * fsi]) +
	(+0.00804139028722668) * (f[(i + 1) * fsi]) + (-0.00319785263107209) * (f[(i + 2) * fsi]);
      fr22 =
	(+0.00319785263107209) * (f[(i - 4) * fsi]) + (-0.0244695477712602) * (f[(i - 3) * fsi]) +
	(+0.0904727723765625) * (f[(i - 2) * fsi]) + (-0.250783630504437) * (f[(i - 1) * fsi]) +
	(+1.19272827876727) * (f[(i + 0) * fsi]) + (-0.0111457254992059) * (f[(i + 1) * fsi]);
      fr23 =
	(+0.0111457254992059) * (f[(i - 5) * fsi]) + (-0.063676500364163) * (f[(i - 4) * fsi]) +
	(+0.142716334716828) * (f[(i - 3) * fsi]) + (-0.132441737607555) * (f[(i - 2) * fsi]) +
	(-0.0835977480163492) * (f[(i - 1) * fsi]) + (+1.12585392577203) * (f[(i + 0) * fsi]);
      fr24 =
	(+0.324878954328676) * (f[(i + 0) * fsi]) + (+1.35761203580814) * (f[(i + 1) * fsi]) +
	(-1.20928948083487) * (f[(i + 2) * fsi]) + (+0.758668629747163) * (f[(i + 3) * fsi]) +
	(-0.274916425098766) * (f[(i + 4) * fsi]) + (+0.0430462860496634) * (f[(i + 5) * fsi]);
      fr25 =
	(-0.0430462860496634) * (f[(i - 1) * fsi]) + (+0.583156670626657) * (f[(i + 0) * fsi]) +
	(+0.711917745063186) * (f[(i + 1) * fsi]) + (-0.348363759841606) * (f[(i + 2) * fsi]) +
	(+0.112974339002212) * (f[(i + 3) * fsi]) + (-0.0166387088007855) * (f[(i + 4) * fsi]);
      fr26 =
	(+0.0166387088007855) * (f[(i - 2) * fsi]) + (-0.142878538854377) * (f[(i - 1) * fsi]) +
	(+0.83273730263844) * (f[(i + 0) * fsi]) + (+0.379143569047475) * (f[(i + 1) * fsi]) +
	(-0.0987831278298225) * (f[(i + 2) * fsi]) + (+0.0131420861974989) * (f[(i + 3) * fsi]);
      fr27 =
	(-0.0131420861974989) * (f[(i - 3) * fsi]) + (+0.0954912259857788) * (f[(i - 2) * fsi]) +
	(-0.34000983181686) * (f[(i - 1) * fsi]) + (+1.09557902658842) * (f[(i + 0) * fsi]) +
	(+0.182012276084992) * (f[(i + 1) * fsi]) + (-0.0199306106448293) * (f[(i + 2) * fsi]);
      fr28 =
	(+0.0199306106448293) * (f[(i - 4) * fsi]) + (-0.132725750066475) * (f[(i - 3) * fsi]) +
	(+0.394450385658218) * (f[(i - 2) * fsi]) + (-0.738622044713446) * (f[(i - 1) * fsi]) +
	(+1.39453818626086) * (f[(i + 0) * fsi]) + (+0.0624286122160162) * (f[(i + 1) * fsi]);
      fr29 =
	(-0.0624286122160162) * (f[(i - 5) * fsi]) + (+0.394502283940926) * (f[(i - 4) * fsi]) +
	(-1.06915493330672) * (f[(i - 3) * fsi]) + (+1.64302262997854) * (f[(i - 2) * fsi]) +
	(-1.67505122795369) * (f[(i - 1) * fsi]) + (+1.76910985955695) * (f[(i + 0) * fsi]);
      fr30 =
	(+0.193452918286503) * (f[(i + 0) * fsi]) + (+1.44513039937347) * (f[(i + 1) * fsi]) +
	(-1.09660485028244) * (f[(i + 2) * fsi]) + (+0.653467322482526) * (f[(i + 3) * fsi]) +
	(-0.231141040145683) * (f[(i + 4) * fsi]) + (+0.0356952502856282) * (f[(i + 5) * fsi]);
      fr31 =
	(-0.0356952502856283) * (f[(i - 1) * fsi]) + (+0.407624420000272) * (f[(i + 0) * fsi]) +
	(+0.909701645089041) * (f[(i + 1) * fsi]) + (-0.382699844569874) * (f[(i + 2) * fsi]) +
	(+0.118038568198102) * (f[(i + 3) * fsi]) + (-0.0169695384319124) * (f[(i + 4) * fsi]);
      fr32 =
	(+0.0169695384319124) * (f[(i - 2) * fsi]) + (-0.137512480877103) * (f[(i - 1) * fsi]) +
	(+0.662167496478959) * (f[(i + 0) * fsi]) + (+0.570310876450793) * (f[(i + 1) * fsi]) +
	(-0.128156768091188) * (f[(i + 2) * fsi]) + (+0.0162213376066272) * (f[(i + 3) * fsi]);
      fr33 =
	(-0.0162213376066272) * (f[(i - 3) * fsi]) + (+0.114297564071676) * (f[(i - 2) * fsi]) +
	(-0.380832544976511) * (f[(i - 1) * fsi]) + (+0.986594248611503) * (f[(i + 0) * fsi]) +
	(+0.326990812351384) * (f[(i + 1) * fsi]) + (-0.0308287424514247) * (f[(i + 2) * fsi]);
      fr34 =
	(+0.0308287424514246) * (f[(i - 4) * fsi]) + (-0.201193792315175) * (f[(i - 3) * fsi]) +
	(+0.576728700843046) * (f[(i - 2) * fsi]) + (-0.997407394005005) * (f[(i - 1) * fsi]) +
	(+1.44902538538287) * (f[(i + 0) * fsi]) + (+0.142018357642836) * (f[(i + 1) * fsi]);
      fr35 =
	(-0.142018357642836) * (f[(i - 5) * fsi]) + (+0.882938888308441) * (f[(i - 4) * fsi]) +
	(-2.33146915695772) * (f[(i - 3) * fsi]) + (+3.41709585369977) * (f[(i - 2) * fsi]) +
	(-3.12768275864755) * (f[(i - 1) * fsi]) + (+2.30113553123989) * (f[(i + 0) * fsi]);
      fs0 =
	(omega0) * (fr0) + (omega1) * (fr1) + (omega2) * (fr2) + (omega3) * (fr3) +
	(omega4) * (fr4) + (omega5) * (fr5);
      fs1 =
	(omega6) * (fr6) + (omega7) * (fr7) + (omega8) * (fr8) + (omega9) * (fr9) +
	(omega10) * (fr10) + (omega11) * (fr11);
      fs2 =
	((+2.04057936038575) *
	 ((omega12p) * (fr12) + (omega13p) * (fr13) + (omega14p) * (fr14) + (omega15p) * (fr15) +
	  (omega16p) * (fr16) + (omega17p) * (fr17))) -
	((+1.04057936038575) *
	 ((omega12m) * (fr12) + (omega13m) * (fr13) + (omega14m) * (fr14) + (omega15m) * (fr15) +
	  (omega16m) * (fr16) + (omega17m) * (fr17)));
      fs3 =
	((+2.04057936038583) *
	 ((omega18p) * (fr18) + (omega19p) * (fr19) + (omega20p) * (fr20) + (omega21p) * (fr21) +
	  (omega22p) * (fr22) + (omega23p) * (fr23))) -
	((+1.04057936038583) *
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
py_reconstruct_gauss_legendre006006 (PyObject * self, PyObject * args)
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

  reconstruct_gauss_legendre006006 (f, n, fsi, omega, wsi, wsl, wsr, fr, frsi, frsl);

  Py_INCREF (Py_None);
  return Py_None;
}
