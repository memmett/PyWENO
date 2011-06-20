#include <Python.h>
#include <numpy/ndarrayobject.h>

void
weights_gauss_radau006005 (const double *restrict sigma, int n, int ssi, int ssr,
			   double *restrict omega, int wsi, int wsl, int wsr)
{
  int i;
  double acc, sigma0, sigma1, sigma2, sigma3, sigma4, sigma5, omega9, omega18, omega15p, omega16m,
    omega14p, omega3, omega24, omega8, omega16p, omega19, omega21, omega28, omega15m, omega11,
    omega12m, omega4, omega29, omega25, omega12p, omega20, omega0, omega17p, omega10, omega17m,
    omega5, omega26, omega6, omega23, omega1, omega13p, omega14m, omega13m, omega7, omega27,
    omega22, omega2;
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
      omega6 = (+0.00426824262664219) / ((sigma0 + 1.0e-6) * (sigma0 + 1.0e-6));
      acc = acc + omega6;
      omega7 = (+0.0891765249448771) / ((sigma1 + 1.0e-6) * (sigma1 + 1.0e-6));
      acc = acc + omega7;
      omega8 = (+0.361654578424202) / ((sigma2 + 1.0e-6) * (sigma2 + 1.0e-6));
      acc = acc + omega8;
      omega9 = (+0.407020388815206) / ((sigma3 + 1.0e-6) * (sigma3 + 1.0e-6));
      acc = acc + omega9;
      omega10 = (+0.129362676595996) / ((sigma4 + 1.0e-6) * (sigma4 + 1.0e-6));
      acc = acc + omega10;
      omega11 = (+0.00851758859307624) / ((sigma5 + 1.0e-6) * (sigma5 + 1.0e-6));
      acc = acc + omega11;
      omega6 = (omega6) / (acc);
      omega7 = (omega7) / (acc);
      omega8 = (omega8) / (acc);
      omega9 = (omega9) / (acc);
      omega10 = (omega10) / (acc);
      omega11 = (omega11) / (acc);
      acc = 0.0;
      omega12p =
	((+0.00606922515724062) / (+3.24868642929383)) / ((sigma0 + 1.0e-6) * (sigma0 + 1.0e-6));
      acc = acc + omega12p;
      omega13p =
	((+2.34878176944526) / (+3.24868642929383)) / ((sigma1 + 1.0e-6) * (sigma1 + 1.0e-6));
      acc = acc + omega13p;
      omega14p =
	((+0.410159584607371) / (+3.24868642929383)) / ((sigma2 + 1.0e-6) * (sigma2 + 1.0e-6));
      acc = acc + omega14p;
      omega15p =
	((+0.392736766003681) / (+3.24868642929383)) / ((sigma3 + 1.0e-6) * (sigma3 + 1.0e-6));
      acc = acc + omega15p;
      omega16p =
	((+0.087262024268935) / (+3.24868642929383)) / ((sigma4 + 1.0e-6) * (sigma4 + 1.0e-6));
      acc = acc + omega16p;
      omega17p =
	((+0.00367705981134819) / (+3.24868642929383)) / ((sigma5 + 1.0e-6) * (sigma5 + 1.0e-6));
      acc = acc + omega17p;
      omega12p = (omega12p) / (acc);
      omega13p = (omega13p) / (acc);
      omega14p = (omega14p) / (acc);
      omega15p = (omega15p) / (acc);
      omega16p = (omega16p) / (acc);
      omega17p = (omega17p) / (acc);
      acc = 0.0;
      omega12m =
	((+0.0121384503144812) / (+2.24868642929383)) / ((sigma0 + 1.0e-6) * (sigma0 + 1.0e-6));
      acc = acc + omega12m;
      omega13m =
	((+1.17439088472263) / (+2.24868642929383)) / ((sigma1 + 1.0e-6) * (sigma1 + 1.0e-6));
      acc = acc + omega13m;
      omega14m =
	((+0.820319169214742) / (+2.24868642929383)) / ((sigma2 + 1.0e-6) * (sigma2 + 1.0e-6));
      acc = acc + omega14m;
      omega15m =
	((+0.19636838300184) / (+2.24868642929383)) / ((sigma3 + 1.0e-6) * (sigma3 + 1.0e-6));
      acc = acc + omega15m;
      omega16m =
	((+0.0436310121344675) / (+2.24868642929383)) / ((sigma4 + 1.0e-6) * (sigma4 + 1.0e-6));
      acc = acc + omega16m;
      omega17m =
	((+0.0018385299056741) / (+2.24868642929383)) / ((sigma5 + 1.0e-6) * (sigma5 + 1.0e-6));
      acc = acc + omega17m;
      omega12m = (omega12m) / (acc);
      omega13m = (omega13m) / (acc);
      omega14m = (omega14m) / (acc);
      omega15m = (omega15m) / (acc);
      omega16m = (omega16m) / (acc);
      omega17m = (omega17m) / (acc);
      acc = 0.0;
      omega18 = (+0.00509752056089433) / ((sigma0 + 1.0e-6) * (sigma0 + 1.0e-6));
      acc = acc + omega18;
      omega19 = (+0.0953592272030808) / ((sigma1 + 1.0e-6) * (sigma1 + 1.0e-6));
      acc = acc + omega19;
      omega20 = (+0.361443965126561) / ((sigma2 + 1.0e-6) * (sigma2 + 1.0e-6));
      acc = acc + omega20;
      omega21 = (+0.39505934648208) / ((sigma3 + 1.0e-6) * (sigma3 + 1.0e-6));
      acc = acc + omega21;
      omega22 = (+0.129722568471249) / ((sigma4 + 1.0e-6) * (sigma4 + 1.0e-6));
      acc = acc + omega22;
      omega23 = (+0.0133173721561354) / ((sigma5 + 1.0e-6) * (sigma5 + 1.0e-6));
      acc = acc + omega23;
      omega18 = (omega18) / (acc);
      omega19 = (omega19) / (acc);
      omega20 = (omega20) / (acc);
      omega21 = (omega21) / (acc);
      omega22 = (omega22) / (acc);
      omega23 = (omega23) / (acc);
      acc = 0.0;
      omega24 = (+0.0109882663243742) / ((sigma0 + 1.0e-6) * (sigma0 + 1.0e-6));
      acc = acc + omega24;
      omega25 = (+0.148687067908692) / ((sigma1 + 1.0e-6) * (sigma1 + 1.0e-6));
      acc = acc + omega25;
      omega26 = (+0.423804109061958) / ((sigma2 + 1.0e-6) * (sigma2 + 1.0e-6));
      acc = acc + omega26;
      omega27 = (+0.339947422860076) / ((sigma3 + 1.0e-6) * (sigma3 + 1.0e-6));
      acc = acc + omega27;
      omega28 = (+0.0737548471045655) / ((sigma4 + 1.0e-6) * (sigma4 + 1.0e-6));
      acc = acc + omega28;
      omega29 = (+0.00281828674034706) / ((sigma5 + 1.0e-6) * (sigma5 + 1.0e-6));
      acc = acc + omega29;
      omega24 = (omega24) / (acc);
      omega25 = (omega25) / (acc);
      omega26 = (omega26) / (acc);
      omega27 = (omega27) / (acc);
      omega28 = (omega28) / (acc);
      omega29 = (omega29) / (acc);
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
      omega[i * wsi + 3 * wsl + 0 * wsr + 0] = omega18;
      omega[i * wsi + 3 * wsl + 1 * wsr + 0] = omega19;
      omega[i * wsi + 3 * wsl + 2 * wsr + 0] = omega20;
      omega[i * wsi + 3 * wsl + 3 * wsr + 0] = omega21;
      omega[i * wsi + 3 * wsl + 4 * wsr + 0] = omega22;
      omega[i * wsi + 3 * wsl + 5 * wsr + 0] = omega23;
      omega[i * wsi + 4 * wsl + 0 * wsr + 0] = omega24;
      omega[i * wsi + 4 * wsl + 1 * wsr + 0] = omega25;
      omega[i * wsi + 4 * wsl + 2 * wsr + 0] = omega26;
      omega[i * wsi + 4 * wsl + 3 * wsr + 0] = omega27;
      omega[i * wsi + 4 * wsl + 4 * wsr + 0] = omega28;
      omega[i * wsi + 4 * wsl + 5 * wsr + 0] = omega29;
    }
}

PyObject *
py_weights_gauss_radau006005 (PyObject * self, PyObject * args)
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

  weights_gauss_radau006005 (sigma, n, ssi, ssr, omega, wsi, wsl, wsr);

  Py_INCREF (Py_None);
  return Py_None;
}

void
reconstruct_gauss_radau006005 (const double *restrict f, int n, int fsi,
			       const double *restrict omega, int wsi, int wsl, int wsr,
			       double *restrict fr, int frsi, int frsl)
{
  int i;
  double omega9, omega18, omega15p, omega16m, omega14p, omega3, omega24, omega8, omega16p, omega19,
    omega21, omega28, omega15m, omega11, omega12m, omega4, omega29, omega25, omega12p, omega20,
    omega0, omega17p, omega10, omega17m, omega5, omega26, omega6, omega23, omega1, omega13p,
    omega14m, omega13m, omega7, omega27, omega22, omega2, fs0, fs1, fs2, fs3, fs4, fr9, fr18, fr13,
    fr17, fr3, fr24, fr8, fr21, fr28, fr11, fr14, fr25, fr7, fr20, fr0, fr29, fr4, fr10, fr5, fr26,
    fr6, fr23, fr1, fr19, fr2, fr12, fr27, fr15, fr22, fr16;
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
      omega18 = omega[i * wsi + 3 * wsl + 0 * wsr + 0];
      omega19 = omega[i * wsi + 3 * wsl + 1 * wsr + 0];
      omega20 = omega[i * wsi + 3 * wsl + 2 * wsr + 0];
      omega21 = omega[i * wsi + 3 * wsl + 3 * wsr + 0];
      omega22 = omega[i * wsi + 3 * wsl + 4 * wsr + 0];
      omega23 = omega[i * wsi + 3 * wsl + 5 * wsr + 0];
      omega24 = omega[i * wsi + 4 * wsl + 0 * wsr + 0];
      omega25 = omega[i * wsi + 4 * wsl + 1 * wsr + 0];
      omega26 = omega[i * wsi + 4 * wsl + 2 * wsr + 0];
      omega27 = omega[i * wsi + 4 * wsl + 3 * wsr + 0];
      omega28 = omega[i * wsi + 4 * wsl + 4 * wsr + 0];
      omega29 = omega[i * wsi + 4 * wsl + 5 * wsr + 0];
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
	(+1.87674810537772) * (f[(i + 0) * fsi]) + (-1.96086691163882) * (f[(i + 1) * fsi]) +
	(+1.98352846494727) * (f[(i + 2) * fsi]) + (-1.30856455733092) * (f[(i + 3) * fsi]) +
	(+0.48651097514296) * (f[(i + 4) * fsi]) + (-0.0773560764982009) * (f[(i + 5) * fsi]);
      fr7 =
	(+0.0773560764982009) * (f[(i - 1) * fsi]) + (+1.41261164638851) * (f[(i + 0) * fsi]) +
	(-0.800525764165805) * (f[(i + 1) * fsi]) + (+0.436406934983249) * (f[(i + 2) * fsi]) +
	(-0.14822340985791) * (f[(i + 3) * fsi]) + (+0.022374516153755) * (f[(i + 4) * fsi]);
      fr8 =
	(-0.022374516153755) * (f[(i - 2) * fsi]) + (+0.211603173420731) * (f[(i - 1) * fsi]) +
	(+1.07699390408219) * (f[(i + 0) * fsi]) + (-0.353035441090705) * (f[(i + 1) * fsi]) +
	(+0.100789192676924) * (f[(i + 2) * fsi]) + (-0.0139763129353804) * (f[(i + 3) * fsi]);
      fr9 =
	(+0.0139763129353804) * (f[(i - 3) * fsi]) + (-0.106232393766037) * (f[(i - 2) * fsi]) +
	(+0.421247867451436) * (f[(i - 1) * fsi]) + (+0.797467645374579) * (f[(i + 0) * fsi]) +
	(-0.14339074706) * (f[(i + 1) * fsi]) + (+0.0169313150646417) * (f[(i + 2) * fsi]);
      fr10 =
	(-0.0169313150646417) * (f[(i - 4) * fsi]) + (+0.115564203323231) * (f[(i - 3) * fsi]) +
	(-0.360202119735663) * (f[(i - 2) * fsi]) + (+0.759874168744271) * (f[(i - 1) * fsi]) +
	(+0.543497919404953) * (f[(i + 0) * fsi]) + (-0.0418028566721494) * (f[(i + 1) * fsi]);
      fr11 =
	(+0.0418028566721494) * (f[(i - 5) * fsi]) + (-0.267748455097538) * (f[(i - 4) * fsi]) +
	(+0.742607053405472) * (f[(i - 3) * fsi]) + (-1.19625925317865) * (f[(i - 2) * fsi]) +
	(+1.38691701882651) * (f[(i - 1) * fsi]) + (+0.292680779372056) * (f[(i + 0) * fsi]);
      fr12 =
	(+1.03664015946106) * (f[(i + 0) * fsi]) + (+0.116536489045991) * (f[(i + 1) * fsi]) +
	(-0.333833365073552) * (f[(i + 2) * fsi]) + (+0.273863525519408) * (f[(i + 3) * fsi]) +
	(-0.111983276938492) * (f[(i + 4) * fsi]) + (+0.0187764679855883) * (f[(i + 5) * fsi]);
      fr13 =
	(-0.0187764679855884) * (f[(i - 1) * fsi]) + (+1.14929896737459) * (f[(i + 0) * fsi]) +
	(-0.165110530737835) * (f[(i + 1) * fsi]) + (+0.0416959946382148) * (f[(i + 2) * fsi]) +
	(-0.00778349426441781) * (f[(i + 3) * fsi]) + (+0.000675530975038341) * (f[(i + 4) * fsi]);
      fr14 =
	(-0.000675530975038339) * (f[(i - 2) * fsi]) + (-0.0147232821353584) * (f[(i - 1) * fsi]) +
	(+1.13916600274901) * (f[(i + 0) * fsi]) + (-0.151599911237068) * (f[(i + 1) * fsi]) +
	(+0.0315630300126396) * (f[(i + 2) * fsi]) + (-0.00373030841418776) * (f[(i + 3) * fsi]);
      fr15 =
	(+0.00373030841418776) * (f[(i - 3) * fsi]) + (-0.0230573814601649) * (f[(i - 2) * fsi]) +
	(+0.041231344077458) * (f[(i - 1) * fsi]) + (+1.06455983446526) * (f[(i + 0) * fsi]) +
	(-0.0956452850242515) * (f[(i + 1) * fsi]) + (+0.00918117952751308) * (f[(i + 2) * fsi]);
      fr16 =
	(-0.00918117952751308) * (f[(i - 4) * fsi]) + (+0.0588173855792662) * (f[(i - 3) * fsi]) +
	(-0.160775074372861) * (f[(i - 2) * fsi]) + (+0.22485493462772) * (f[(i - 1) * fsi]) +
	(+0.926842141552561) * (f[(i + 0) * fsi]) + (-0.040558207859173) * (f[(i + 1) * fsi]);
      fr17 =
	(+0.040558207859173) * (f[(i - 5) * fsi]) + (-0.252530426682551) * (f[(i - 4) * fsi]) +
	(+0.667190503466861) * (f[(i - 3) * fsi]) + (-0.971939231556321) * (f[(i - 2) * fsi]) +
	(+0.833228052515315) * (f[(i - 1) * fsi]) + (+0.683492894397523) * (f[(i + 0) * fsi]);
      fr18 =
	(+0.459871837949955) * (f[(i + 0) * fsi]) + (+1.19585346871647) * (f[(i + 1) * fsi]) +
	(-1.18981785928007) * (f[(i + 2) * fsi]) + (+0.774640801027807) * (f[(i + 3) * fsi]) +
	(-0.285758075192918) * (f[(i + 4) * fsi]) + (+0.0452098267787614) * (f[(i + 5) * fsi]);
      fr19 =
	(-0.0452098267787614) * (f[(i - 1) * fsi]) + (+0.731130798622524) * (f[(i + 0) * fsi]) +
	(+0.517706067035047) * (f[(i + 1) * fsi]) + (-0.285621323704844) * (f[(i + 2) * fsi]) +
	(+0.0964933993463848) * (f[(i + 3) * fsi]) + (-0.0144991145203493) * (f[(i + 4) * fsi]);
      fr20 =
	(+0.0144991145203493) * (f[(i - 2) * fsi]) + (-0.132204513900857) * (f[(i - 1) * fsi]) +
	(+0.948617516427763) * (f[(i + 0) * fsi]) + (+0.22772377662806) * (f[(i + 1) * fsi]) +
	(-0.0681346058996048) * (f[(i + 2) * fsi]) + (+0.0094987122242889) * (f[(i + 3) * fsi]);
      fr21 =
	(-0.0094987122242889) * (f[(i - 3) * fsi]) + (+0.0714913878660827) * (f[(i - 2) * fsi]) +
	(-0.274685197265191) * (f[(i - 1) * fsi]) + (+1.13859176091354) * (f[(i + 0) * fsi]) +
	(+0.0852430932637269) * (f[(i + 1) * fsi]) + (-0.0111423325538714) * (f[(i + 2) * fsi]);
      fr22 =
	(+0.0111423325538714) * (f[(i - 4) * fsi]) + (-0.0763527075475172) * (f[(i - 3) * fsi]) +
	(+0.238626376174153) * (f[(i - 2) * fsi]) + (-0.497531848342618) * (f[(i - 1) * fsi]) +
	(+1.30572674922161) * (f[(i + 0) * fsi]) + (+0.0183890979404986) * (f[(i + 1) * fsi]);
      fr23 =
	(-0.0183890979404986) * (f[(i - 5) * fsi]) + (+0.121476920196863) * (f[(i - 4) * fsi]) +
	(-0.352189176654996) * (f[(i - 3) * fsi]) + (+0.606408334984125) * (f[(i - 2) * fsi]) +
	(-0.773368317450097) * (f[(i - 1) * fsi]) + (+1.4160613368646) * (f[(i + 0) * fsi]);
      fr24 =
	(+0.213275433880172) * (f[(i + 0) * fsi]) + (+1.43811983722828) * (f[(i + 1) * fsi]) +
	(-1.12496293617011) * (f[(i + 2) * fsi]) + (+0.67679600873729) * (f[(i + 3) * fsi]) +
	(-0.240455531163699) * (f[(i + 4) * fsi]) + (+0.0372271874880712) * (f[(i + 5) * fsi]);
      fr25 =
	(-0.0372271874880712) * (f[(i - 1) * fsi]) + (+0.436638558808599) * (f[(i + 0) * fsi]) +
	(+0.879712024907211) * (f[(i + 1) * fsi]) + (-0.380419186408689) * (f[(i + 2) * fsi]) +
	(+0.11838819641622) * (f[(i + 3) * fsi]) + (-0.0170924062352705) * (f[(i + 4) * fsi]);
      fr26 =
	(+0.0170924062352705) * (f[(i - 2) * fsi]) + (-0.139781624899694) * (f[(i - 1) * fsi]) +
	(+0.693024652337657) * (f[(i + 0) * fsi]) + (+0.537863900201801) * (f[(i + 1) * fsi]) +
	(-0.124033092879631) * (f[(i + 2) * fsi]) + (+0.0158337590045966) * (f[(i + 3) * fsi]);
      fr27 =
	(-0.0158337590045966) * (f[(i - 3) * fsi]) + (+0.11209496026285) * (f[(i - 2) * fsi]) +
	(-0.377288009968643) * (f[(i - 1) * fsi]) + (+1.00969983242959) * (f[(i + 0) * fsi]) +
	(+0.300357515132853) * (f[(i + 1) * fsi]) + (-0.0290305388520515) * (f[(i + 2) * fsi]);
      fr28 =
	(+0.0290305388520515) * (f[(i - 4) * fsi]) + (-0.190016992116906) * (f[(i - 3) * fsi]) +
	(+0.547553043043622) * (f[(i - 2) * fsi]) + (-0.957898787009673) * (f[(i - 1) * fsi]) +
	(+1.44515791521036) * (f[(i + 0) * fsi]) + (+0.126174282020544) * (f[(i + 1) * fsi]);
      fr29 =
	(-0.126174282020544) * (f[(i - 5) * fsi]) + (+0.786076230975313) * (f[(i - 4) * fsi]) +
	(-2.08263122242506) * (f[(i - 3) * fsi]) + (+3.0710386834545) * (f[(i - 2) * fsi]) +
	(-2.85051301731783) * (f[(i - 1) * fsi]) + (+2.20220360733362) * (f[(i + 0) * fsi]);
      fs0 =
	(omega0) * (fr0) + (omega1) * (fr1) + (omega2) * (fr2) + (omega3) * (fr3) +
	(omega4) * (fr4) + (omega5) * (fr5);
      fs1 =
	(omega6) * (fr6) + (omega7) * (fr7) + (omega8) * (fr8) + (omega9) * (fr9) +
	(omega10) * (fr10) + (omega11) * (fr11);
      fs2 =
	((+3.24868642929383) *
	 ((omega12p) * (fr12) + (omega13p) * (fr13) + (omega14p) * (fr14) + (omega15p) * (fr15) +
	  (omega16p) * (fr16) + (omega17p) * (fr17))) -
	((+2.24868642929383) *
	 ((omega12m) * (fr12) + (omega13m) * (fr13) + (omega14m) * (fr14) + (omega15m) * (fr15) +
	  (omega16m) * (fr16) + (omega17m) * (fr17)));
      fs3 =
	(omega18) * (fr18) + (omega19) * (fr19) + (omega20) * (fr20) + (omega21) * (fr21) +
	(omega22) * (fr22) + (omega23) * (fr23);
      fs4 =
	(omega24) * (fr24) + (omega25) * (fr25) + (omega26) * (fr26) + (omega27) * (fr27) +
	(omega28) * (fr28) + (omega29) * (fr29);
      fr[i * frsi + 0 * frsl] = fs0;
      fr[i * frsi + 1 * frsl] = fs1;
      fr[i * frsi + 2 * frsl] = fs2;
      fr[i * frsi + 3 * frsl] = fs3;
      fr[i * frsi + 4 * frsl] = fs4;
    }
}

PyObject *
py_reconstruct_gauss_radau006005 (PyObject * self, PyObject * args)
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

  reconstruct_gauss_radau006005 (f, n, fsi, omega, wsi, wsl, wsr, fr, frsi, frsl);

  Py_INCREF (Py_None);
  return Py_None;
}
