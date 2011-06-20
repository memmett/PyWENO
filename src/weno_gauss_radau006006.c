#include <Python.h>
#include <numpy/ndarrayobject.h>

void
weights_gauss_radau006006 (const double *restrict sigma, int n, int ssi, int ssr,
			   double *restrict omega, int wsi, int wsl, int wsr)
{
  int i;
  double acc, sigma0, sigma1, sigma2, sigma3, sigma4, sigma5, omega9, omega13, omega21m, omega22m,
    omega26, omega21p, omega17, omega3, omega24, omega8, omega35, omega28, omega11, omega30,
    omega14, omega25, omega7, omega20p, omega23m, omega34, omega0, omega19m, omega20m, omega29,
    omega19p, omega10, omega5, omega22p, omega18m, omega4, omega6, omega33, omega1, omega23p,
    omega2, omega12, omega18p, omega27, omega31, omega15, omega32, omega16;
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
      omega6 = (+0.00344322089369646) / ((sigma0 + 1.0e-6) * (sigma0 + 1.0e-6));
      acc = acc + omega6;
      omega7 = (+0.0809943954095872) / ((sigma1 + 1.0e-6) * (sigma1 + 1.0e-6));
      acc = acc + omega7;
      omega8 = (+0.350869292952643) / ((sigma2 + 1.0e-6) * (sigma2 + 1.0e-6));
      acc = acc + omega8;
      omega9 = (+0.41600909486625) / ((sigma3 + 1.0e-6) * (sigma3 + 1.0e-6));
      acc = acc + omega9;
      omega10 = (+0.138986342797302) / ((sigma4 + 1.0e-6) * (sigma4 + 1.0e-6));
      acc = acc + omega10;
      omega11 = (+0.00969765308052086) / ((sigma5 + 1.0e-6) * (sigma5 + 1.0e-6));
      acc = acc + omega11;
      omega6 = (omega6) / (acc);
      omega7 = (omega7) / (acc);
      omega8 = (omega8) / (acc);
      omega9 = (omega9) / (acc);
      omega10 = (omega10) / (acc);
      omega11 = (omega11) / (acc);
      acc = 0.0;
      omega12 = (+0.0237021146233157) / ((sigma0 + 1.0e-6) * (sigma0 + 1.0e-6));
      acc = acc + omega12;
      omega13 = (+0.138910726479989) / ((sigma1 + 1.0e-6) * (sigma1 + 1.0e-6));
      acc = acc + omega13;
      omega14 = (+0.399042547903221) / ((sigma2 + 1.0e-6) * (sigma2 + 1.0e-6));
      acc = acc + omega14;
      omega15 = (+0.346415528807717) / ((sigma3 + 1.0e-6) * (sigma3 + 1.0e-6));
      acc = acc + omega15;
      omega16 = (+0.0874675911960257) / ((sigma4 + 1.0e-6) * (sigma4 + 1.0e-6));
      acc = acc + omega16;
      omega17 = (+0.00446149098973179) / ((sigma5 + 1.0e-6) * (sigma5 + 1.0e-6));
      acc = acc + omega17;
      omega12 = (omega12) / (acc);
      omega13 = (omega13) / (acc);
      omega14 = (omega14) / (acc);
      omega15 = (omega15) / (acc);
      omega16 = (omega16) / (acc);
      omega17 = (omega17) / (acc);
      acc = 0.0;
      omega18p =
	((+0.00255056111799865) / (+4.46578648904075)) / ((sigma0 + 1.0e-6) * (sigma0 + 1.0e-6));
      acc = acc + omega18p;
      omega19p =
	((+0.0602107426660585) / (+4.46578648904075)) / ((sigma1 + 1.0e-6) * (sigma1 + 1.0e-6));
      acc = acc + omega19p;
      omega20p =
	((+0.210563974533318) / (+4.46578648904075)) / ((sigma2 + 1.0e-6) * (sigma2 + 1.0e-6));
      acc = acc + omega20p;
      omega21p =
	((+3.37053238104312) / (+4.46578648904075)) / ((sigma3 + 1.0e-6) * (sigma3 + 1.0e-6));
      acc = acc + omega21p;
      omega22p =
	((+0.81794619075939) / (+4.46578648904075)) / ((sigma4 + 1.0e-6) * (sigma4 + 1.0e-6));
      acc = acc + omega22p;
      omega23p =
	((+0.0039826389208587) / (+4.46578648904075)) / ((sigma5 + 1.0e-6) * (sigma5 + 1.0e-6));
      acc = acc + omega23p;
      omega18p = (omega18p) / (acc);
      omega19p = (omega19p) / (acc);
      omega20p = (omega20p) / (acc);
      omega21p = (omega21p) / (acc);
      omega22p = (omega22p) / (acc);
      omega23p = (omega23p) / (acc);
      acc = 0.0;
      omega18m =
	((+0.00127528055899932) / (+3.46578648904075)) / ((sigma0 + 1.0e-6) * (sigma0 + 1.0e-6));
      acc = acc + omega18m;
      omega19m =
	((+0.0301053713330293) / (+3.46578648904075)) / ((sigma1 + 1.0e-6) * (sigma1 + 1.0e-6));
      acc = acc + omega19m;
      omega20m =
	((+0.105281987266659) / (+3.46578648904075)) / ((sigma2 + 1.0e-6) * (sigma2 + 1.0e-6));
      acc = acc + omega20m;
      omega21m =
	((+1.68526619052156) / (+3.46578648904075)) / ((sigma3 + 1.0e-6) * (sigma3 + 1.0e-6));
      acc = acc + omega21m;
      omega22m =
	((+1.63589238151878) / (+3.46578648904075)) / ((sigma4 + 1.0e-6) * (sigma4 + 1.0e-6));
      acc = acc + omega22m;
      omega23m =
	((+0.00796527784171741) / (+3.46578648904075)) / ((sigma5 + 1.0e-6) * (sigma5 + 1.0e-6));
      acc = acc + omega23m;
      omega18m = (omega18m) / (acc);
      omega19m = (omega19m) / (acc);
      omega20m = (omega20m) / (acc);
      omega21m = (omega21m) / (acc);
      omega22m = (omega22m) / (acc);
      omega23m = (omega23m) / (acc);
      acc = 0.0;
      omega24 = (+0.00698842806919628) / ((sigma0 + 1.0e-6) * (sigma0 + 1.0e-6));
      acc = acc + omega24;
      omega25 = (+0.11552604874613) / ((sigma1 + 1.0e-6) * (sigma1 + 1.0e-6));
      acc = acc + omega25;
      omega26 = (+0.391481816848408) / ((sigma2 + 1.0e-6) * (sigma2 + 1.0e-6));
      acc = acc + omega26;
      omega27 = (+0.376703950048434) / ((sigma3 + 1.0e-6) * (sigma3 + 1.0e-6));
      acc = acc + omega27;
      omega28 = (+0.103200874821433) / ((sigma4 + 1.0e-6) * (sigma4 + 1.0e-6));
      acc = acc + omega28;
      omega29 = (+0.00609888146639744) / ((sigma5 + 1.0e-6) * (sigma5 + 1.0e-6));
      acc = acc + omega29;
      omega24 = (omega24) / (acc);
      omega25 = (omega25) / (acc);
      omega26 = (omega26) / (acc);
      omega27 = (omega27) / (acc);
      omega28 = (omega28) / (acc);
      omega29 = (omega29) / (acc);
      acc = 0.0;
      omega30 = (+0.0115638285059589) / ((sigma0 + 1.0e-6) * (sigma0 + 1.0e-6));
      acc = acc + omega30;
      omega31 = (+0.152775399785074) / ((sigma1 + 1.0e-6) * (sigma1 + 1.0e-6));
      acc = acc + omega31;
      omega32 = (+0.426746396713148) / ((sigma2 + 1.0e-6) * (sigma2 + 1.0e-6));
      acc = acc + omega32;
      omega33 = (+0.335354901271233) / ((sigma3 + 1.0e-6) * (sigma3 + 1.0e-6));
      acc = acc + omega33;
      omega34 = (+0.070960183794312) / ((sigma4 + 1.0e-6) * (sigma4 + 1.0e-6));
      acc = acc + omega34;
      omega35 = (+0.00259928993027372) / ((sigma5 + 1.0e-6) * (sigma5 + 1.0e-6));
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
      omega[i * wsi + 2 * wsl + 0 * wsr + 0] = omega12;
      omega[i * wsi + 2 * wsl + 1 * wsr + 0] = omega13;
      omega[i * wsi + 2 * wsl + 2 * wsr + 0] = omega14;
      omega[i * wsi + 2 * wsl + 3 * wsr + 0] = omega15;
      omega[i * wsi + 2 * wsl + 4 * wsr + 0] = omega16;
      omega[i * wsi + 2 * wsl + 5 * wsr + 0] = omega17;
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
py_weights_gauss_radau006006 (PyObject * self, PyObject * args)
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

  weights_gauss_radau006006 (sigma, n, ssi, ssr, omega, wsi, wsl, wsr);

  Py_INCREF (Py_None);
  return Py_None;
}

void
reconstruct_gauss_radau006006 (const double *restrict f, int n, int fsi,
			       const double *restrict omega, int wsi, int wsl, int wsr,
			       double *restrict fr, int frsi, int frsl)
{
  int i;
  double omega9, omega13, omega21m, omega22m, omega26, omega21p, omega17, omega3, omega24, omega8,
    omega35, omega28, omega11, omega30, omega14, omega25, omega7, omega20p, omega23m, omega34,
    omega0, omega19m, omega20m, omega29, omega19p, omega10, omega5, omega22p, omega18m, omega4,
    omega6, omega33, omega1, omega23p, omega2, omega12, omega18p, omega27, omega31, omega15,
    omega32, omega16, fs0, fs1, fs2, fs3, fs4, fs5, fr9, fr18, fr34, fr13, fr31, fr17, fr3, fr24,
    fr8, fr21, fr28, fr11, fr30, fr14, fr33, fr25, fr7, fr20, fr0, fr29, fr4, fr35, fr10, fr5, fr26,
    fr6, fr23, fr1, fr32, fr19, fr2, fr12, fr27, fr15, fr22, fr16;
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
	(+2.03431514329282) * (f[(i + 0) * fsi]) + (-2.38709240636543) * (f[(i + 1) * fsi]) +
	(+2.49976475987493) * (f[(i + 2) * fsi]) + (-1.67437878845445) * (f[(i + 3) * fsi]) +
	(+0.627722120482944) * (f[(i + 4) * fsi]) + (-0.100330828830804) * (f[(i + 5) * fsi]);
      fr7 =
	(+0.100330828830804) * (f[(i - 1) * fsi]) + (+1.43233017030799) * (f[(i + 0) * fsi]) +
	(-0.882129973903373) * (f[(i + 1) * fsi]) + (+0.49314818325885) * (f[(i + 2) * fsi]) +
	(-0.169416355992393) * (f[(i + 3) * fsi]) + (+0.0257371474981204) * (f[(i + 4) * fsi]);
      fr8 =
	(-0.0257371474981204) * (f[(i - 2) * fsi]) + (+0.254753713819526) * (f[(i - 1) * fsi]) +
	(+1.04627295783618) * (f[(i + 0) * fsi]) + (-0.367387023940965) * (f[(i + 1) * fsi]) +
	(+0.107090970787044) * (f[(i + 2) * fsi]) + (-0.0149934710036704) * (f[(i + 3) * fsi]);
      fr9 =
	(+0.0149934710036704) * (f[(i - 3) * fsi]) + (-0.115697973520143) * (f[(i - 2) * fsi]) +
	(+0.479655778874583) * (f[(i - 1) * fsi]) + (+0.746403537762776) * (f[(i + 0) * fsi]) +
	(-0.142484958885908) * (f[(i + 1) * fsi]) + (+0.0171301447650214) * (f[(i + 2) * fsi]);
      fr10 =
	(-0.0171301447650214) * (f[(i - 4) * fsi]) + (+0.117774339593799) * (f[(i - 3) * fsi]) +
	(-0.372650144995464) * (f[(i - 2) * fsi]) + (+0.822258674175011) * (f[(i - 1) * fsi]) +
	(+0.489451366287455) * (f[(i + 0) * fsi]) + (-0.0397040902957796) * (f[(i + 1) * fsi]);
      fr11 =
	(+0.0397040902957796) * (f[(i - 5) * fsi]) + (-0.255354686539699) * (f[(i - 4) * fsi]) +
	(+0.713335694030494) * (f[(i - 3) * fsi]) + (-1.16673195091106) * (f[(i - 2) * fsi]) +
	(+1.41782002861171) * (f[(i - 1) * fsi]) + (+0.251226824512777) * (f[(i + 0) * fsi]);
      fr12 =
	(+1.33400167797179) * (f[(i + 0) * fsi]) + (-0.572948921677828) * (f[(i + 1) * fsi]) +
	(+0.385761928385747) * (f[(i + 2) * fsi]) + (-0.202583330304638) * (f[(i + 3) * fsi]) +
	(+0.0651324456580355) * (f[(i + 4) * fsi]) + (-0.00936380003310622) * (f[(i + 5) * fsi]);
      fr13 =
	(+0.00936380003310619) * (f[(i - 1) * fsi]) + (+1.27781887777315) * (f[(i + 0) * fsi]) +
	(-0.432491921181235) * (f[(i + 1) * fsi]) + (+0.198485927723624) * (f[(i + 2) * fsi]) +
	(-0.0621263298080452) * (f[(i + 3) * fsi]) + (+0.00894964545939827) * (f[(i + 4) * fsi]);
      fr14 =
	(-0.00894964545939828) * (f[(i - 2) * fsi]) + (+0.0630616727894959) * (f[(i - 1) * fsi]) +
	(+1.14357419588218) * (f[(i + 0) * fsi]) + (-0.253499011993269) * (f[(i + 1) * fsi]) +
	(+0.0642412458326496) * (f[(i + 2) * fsi]) + (-0.00842845705165558) * (f[(i + 3) * fsi]);
      fr15 =
	(+0.00842845705165558) * (f[(i - 3) * fsi]) + (-0.0595203877693318) * (f[(i - 2) * fsi]) +
	(+0.18948852856433) * (f[(i - 1) * fsi]) + (+0.975005054849066) * (f[(i + 0) * fsi]) +
	(-0.127072156218435) * (f[(i + 1) * fsi]) + (+0.0136705035227161) * (f[(i + 2) * fsi]);
      fr16 =
	(-0.0136705035227161) * (f[(i - 4) * fsi]) + (+0.0904514781879521) * (f[(i - 3) * fsi]) +
	(-0.264577940610073) * (f[(i - 2) * fsi]) + (+0.462898599018651) * (f[(i - 1) * fsi]) +
	(+0.769947502008325) * (f[(i + 0) * fsi]) + (-0.045049135082139) * (f[(i + 1) * fsi]);
      fr17 =
	(+0.045049135082139) * (f[(i - 5) * fsi]) + (-0.28396531401555) * (f[(i - 4) * fsi]) +
	(+0.766188504420036) * (f[(i - 3) * fsi]) + (-1.16556064225285) * (f[(i - 2) * fsi]) +
	(+1.13863562525074) * (f[(i - 1) * fsi]) + (+0.499652691515491) * (f[(i + 0) * fsi]);
      fr18 =
	(+0.72348729008556) * (f[(i + 0) * fsi]) + (+0.75946377189135) * (f[(i + 1) * fsi]) +
	(-0.915019780016788) * (f[(i + 2) * fsi]) + (+0.634547349375173) * (f[(i + 3) * fsi]) +
	(-0.241352086445787) * (f[(i + 4) * fsi]) + (+0.0388734551104938) * (f[(i + 5) * fsi]);
      fr19 =
	(-0.0388734551104938) * (f[(i - 1) * fsi]) + (+0.956728020748522) * (f[(i + 0) * fsi]) +
	(+0.176361945233942) * (f[(i + 1) * fsi]) + (-0.137550677806913) * (f[(i + 2) * fsi]) +
	(+0.0514455227177661) * (f[(i + 3) * fsi]) + (-0.00811135578282351) * (f[(i + 4) * fsi]);
      fr20 =
	(+0.00811135578282351) * (f[(i - 2) * fsi]) + (-0.0875415898074349) * (f[(i - 1) * fsi]) +
	(+1.07839835749087) * (f[(i + 0) * fsi]) + (+0.0141348295774719) * (f[(i + 1) * fsi]) +
	(-0.0158803410645606) * (f[(i + 2) * fsi]) + (+0.00277738802082507) * (f[(i + 3) * fsi]);
      fr21 =
	(-0.00277738802082507) * (f[(i - 3) * fsi]) + (+0.0247756839077739) * (f[(i - 2) * fsi]) +
	(-0.129202410119811) * (f[(i - 1) * fsi]) + (+1.13394611790738) * (f[(i + 0) * fsi]) +
	(-0.0275259907349042) * (f[(i + 1) * fsi]) + (+0.00078398706038986) * (f[(i + 2) * fsi]);
      fr22 =
	(-0.00078398706038986) * (f[(i - 4) * fsi]) + (+0.00192653434151408) * (f[(i - 3) * fsi]) +
	(+0.013015878001926) * (f[(i - 2) * fsi]) + (-0.113522668912014) * (f[(i - 1) * fsi]) +
	(+1.12218631200153) * (f[(i + 0) * fsi]) + (-0.022822068372565) * (f[(i + 1) * fsi]);
      fr23 =
	(+0.022822068372565) * (f[(i - 5) * fsi]) + (-0.13771639729578) * (f[(i - 4) * fsi]) +
	(+0.344257559929989) * (f[(i - 3) * fsi]) + (-0.443425489449374) * (f[(i - 2) * fsi]) +
	(+0.228808356676461) * (f[(i - 1) * fsi]) + (+0.985253901766138) * (f[(i + 0) * fsi]);
      fr24 =
	(+0.357964609549608) * (f[(i + 0) * fsi]) + (+1.32332643633439) * (f[(i + 1) * fsi]) +
	(-1.21479549114501) * (f[(i + 2) * fsi]) + (+0.76977342158935) * (f[(i + 3) * fsi]) +
	(-0.280275744955676) * (f[(i + 4) * fsi]) + (+0.0440067686273339) * (f[(i + 5) * fsi]);
      fr25 =
	(-0.044006768627334) * (f[(i - 1) * fsi]) + (+0.622005221313612) * (f[(i + 0) * fsi]) +
	(+0.663224906924382) * (f[(i + 1) * fsi]) + (-0.334660118598329) * (f[(i + 2) * fsi]) +
	(+0.10967189217934) * (f[(i + 3) * fsi]) + (-0.0162351331916716) * (f[(i + 4) * fsi]);
      fr26 =
	(+0.0162351331916716) * (f[(i - 2) * fsi]) + (-0.141417567777364) * (f[(i - 1) * fsi]) +
	(+0.865532219188687) * (f[(i + 0) * fsi]) + (+0.33852224309095) * (f[(i + 1) * fsi]) +
	(-0.0911331207232546) * (f[(i + 2) * fsi]) + (+0.0122610930293103) * (f[(i + 3) * fsi]);
      fr27 =
	(-0.0122610930293103) * (f[(i - 3) * fsi]) + (+0.0898016913675334) * (f[(i - 2) * fsi]) +
	(-0.325333963217018) * (f[(i - 1) * fsi]) + (+1.11075407977489) * (f[(i + 0) * fsi]) +
	(+0.154605847651295) * (f[(i + 1) * fsi]) + (-0.0175665625473928) * (f[(i + 2) * fsi]);
      fr28 =
	(+0.0175665625473928) * (f[(i - 4) * fsi]) + (-0.117660468313667) * (f[(i - 3) * fsi]) +
	(+0.353300129578426) * (f[(i - 2) * fsi]) + (-0.676665214164875) * (f[(i - 1) * fsi]) +
	(+1.37425251798579) * (f[(i + 0) * fsi]) + (+0.0492064723669383) * (f[(i + 1) * fsi]);
      fr29 =
	(-0.0492064723669383) * (f[(i - 5) * fsi]) + (+0.312805396749023) * (f[(i - 4) * fsi]) +
	(-0.855757553817741) * (f[(i - 3) * fsi]) + (+1.33742957691719) * (f[(i - 2) * fsi]) +
	(-1.41476229966895) * (f[(i - 1) * fsi]) + (+1.66949135218741) * (f[(i + 0) * fsi]);
      fr30 =
	(+0.198482220116349) * (f[(i + 0) * fsi]) + (+1.44360859969696) * (f[(i + 1) * fsi]) +
	(-1.10426432053191) * (f[(i + 2) * fsi]) + (+0.659684336148942) * (f[(i + 3) * fsi]) +
	(-0.23361135302025) * (f[(i + 4) * fsi]) + (+0.0361005175899148) * (f[(i + 5) * fsi]);
      fr31 =
	(-0.0361005175899149) * (f[(i - 1) * fsi]) + (+0.415085325655839) * (f[(i + 0) * fsi]) +
	(+0.902100835848234) * (f[(i + 1) * fsi]) + (-0.382253968733615) * (f[(i + 2) * fsi]) +
	(+0.118176572300218) * (f[(i + 3) * fsi]) + (-0.0170082474807601) * (f[(i + 4) * fsi]);
      fr32 =
	(+0.0170082474807601) * (f[(i - 2) * fsi]) + (-0.138150002474475) * (f[(i - 1) * fsi]) +
	(+0.67020903786724) * (f[(i + 0) * fsi]) + (+0.561935886233032) * (f[(i + 1) * fsi]) +
	(-0.127130256522214) * (f[(i + 2) * fsi]) + (+0.0161270874156571) * (f[(i + 3) * fsi]);
      fr33 =
	(-0.0161270874156571) * (f[(i - 3) * fsi]) + (+0.113770771974703) * (f[(i - 2) * fsi]) +
	(-0.380056313709332) * (f[(i - 1) * fsi]) + (+0.992750786180382) * (f[(i + 0) * fsi]) +
	(+0.320029574998175) * (f[(i + 1) * fsi]) + (-0.0303677320282709) * (f[(i + 2) * fsi]);
      fr34 =
	(+0.0303677320282709) * (f[(i - 4) * fsi]) + (-0.198333479585283) * (f[(i - 3) * fsi]) +
	(+0.569286752398767) * (f[(i - 2) * fsi]) + (-0.987410954274751) * (f[(i - 1) * fsi]) +
	(+1.44826676660445) * (f[(i + 0) * fsi]) + (+0.13782318282855) * (f[(i + 1) * fsi]);
      fr35 =
	(-0.13782318282855) * (f[(i - 5) * fsi]) + (+0.857306828999569) * (f[(i - 4) * fsi]) +
	(-2.26568122201353) * (f[(i - 3) * fsi]) + (+3.32575040896976) * (f[(i - 2) * fsi]) +
	(-3.054758696703) * (f[(i - 1) * fsi]) + (+2.27520586357574) * (f[(i + 0) * fsi]);
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
	((+4.46578648904075) *
	 ((omega18p) * (fr18) + (omega19p) * (fr19) + (omega20p) * (fr20) + (omega21p) * (fr21) +
	  (omega22p) * (fr22) + (omega23p) * (fr23))) -
	((+3.46578648904075) *
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
py_reconstruct_gauss_radau006006 (PyObject * self, PyObject * args)
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

  reconstruct_gauss_radau006006 (f, n, fsi, omega, wsi, wsl, wsr, fr, frsi, frsl);

  Py_INCREF (Py_None);
  return Py_None;
}
