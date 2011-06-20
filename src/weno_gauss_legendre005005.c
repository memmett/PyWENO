#include <Python.h>
#include <numpy/ndarrayobject.h>

void
weights_gauss_legendre005005 (const double *restrict sigma, int n, int ssi, int ssr,
			      double *restrict omega, int wsi, int wsl, int wsr)
{
  int i;
  double acc, sigma0, sigma1, sigma2, sigma3, sigma4, omega16, omega15, omega8, omega13p, omega14m,
    omega12p, omega3, omega20, omega7, omega14p, omega18, omega24, omega13m, omega10m, omega4,
    omega21, omega10p, omega17, omega0, omega9, omega22, omega5, omega1, omega11p, omega12m,
    omega11m, omega6, omega23, omega19, omega2;
  for (i = 5; i < n - 5; i++)
    {
      sigma0 = sigma[i * ssi + 0 * ssr];
      sigma1 = sigma[i * ssi + 1 * ssr];
      sigma2 = sigma[i * ssi + 2 * ssr];
      sigma3 = sigma[i * ssi + 3 * ssr];
      sigma4 = sigma[i * ssi + 4 * ssr];
      acc = 0.0;
      omega0 = (+0.00965851585916853) / ((sigma0 + 1.0e-6) * (sigma0 + 1.0e-6));
      acc = acc + omega0;
      omega1 = (+0.17230397946407) / ((sigma1 + 1.0e-6) * (sigma1 + 1.0e-6));
      acc = acc + omega1;
      omega2 = (+0.481447897995536) / ((sigma2 + 1.0e-6) * (sigma2 + 1.0e-6));
      acc = acc + omega2;
      omega3 = (+0.301456855427839) / ((sigma3 + 1.0e-6) * (sigma3 + 1.0e-6));
      acc = acc + omega3;
      omega4 = (+0.0351327512533857) / ((sigma4 + 1.0e-6) * (sigma4 + 1.0e-6));
      acc = acc + omega4;
      omega0 = (omega0) / (acc);
      omega1 = (omega1) / (acc);
      omega2 = (omega2) / (acc);
      omega3 = (omega3) / (acc);
      omega4 = (omega4) / (acc);
      acc = 0.0;
      omega5 = (+0.0245834031084033) / ((sigma0 + 1.0e-6) * (sigma0 + 1.0e-6));
      acc = acc + omega5;
      omega6 = (+0.239547333598195) / ((sigma1 + 1.0e-6) * (sigma1 + 1.0e-6));
      acc = acc + omega6;
      omega7 = (+0.483908324647345) / ((sigma2 + 1.0e-6) * (sigma2 + 1.0e-6));
      acc = acc + omega7;
      omega8 = (+0.231701231086821) / ((sigma3 + 1.0e-6) * (sigma3 + 1.0e-6));
      acc = acc + omega8;
      omega9 = (+0.0202597075592352) / ((sigma4 + 1.0e-6) * (sigma4 + 1.0e-6));
      acc = acc + omega9;
      omega5 = (omega5) / (acc);
      omega6 = (omega6) / (acc);
      omega7 = (omega7) / (acc);
      omega8 = (omega8) / (acc);
      omega9 = (omega9) / (acc);
      acc = 0.0;
      omega10p =
	((+0.0032093603286385) / (+3.34858630952381)) / ((sigma0 + 1.0e-6) * (sigma0 + 1.0e-6));
      acc = acc + omega10p;
      omega11p =
	((+0.221555024591996) / (+3.34858630952381)) / ((sigma1 + 1.0e-6) * (sigma1 + 1.0e-6));
      acc = acc + omega11p;
      omega12p =
	((+2.89905753968254) / (+3.34858630952381)) / ((sigma2 + 1.0e-6) * (sigma2 + 1.0e-6));
      acc = acc + omega12p;
      omega13p =
	((+0.221555024591996) / (+3.34858630952381)) / ((sigma3 + 1.0e-6) * (sigma3 + 1.0e-6));
      acc = acc + omega13p;
      omega14p =
	((+0.0032093603286385) / (+3.34858630952381)) / ((sigma4 + 1.0e-6) * (sigma4 + 1.0e-6));
      acc = acc + omega14p;
      omega10p = (omega10p) / (acc);
      omega11p = (omega11p) / (acc);
      omega12p = (omega12p) / (acc);
      omega13p = (omega13p) / (acc);
      omega14p = (omega14p) / (acc);
      acc = 0.0;
      omega10m =
	((+0.006418720657277) / (+2.34858630952381)) / ((sigma0 + 1.0e-6) * (sigma0 + 1.0e-6));
      acc = acc + omega10m;
      omega11m =
	((+0.443110049183993) / (+2.34858630952381)) / ((sigma1 + 1.0e-6) * (sigma1 + 1.0e-6));
      acc = acc + omega11m;
      omega12m =
	((+1.44952876984127) / (+2.34858630952381)) / ((sigma2 + 1.0e-6) * (sigma2 + 1.0e-6));
      acc = acc + omega12m;
      omega13m =
	((+0.443110049183993) / (+2.34858630952381)) / ((sigma3 + 1.0e-6) * (sigma3 + 1.0e-6));
      acc = acc + omega13m;
      omega14m =
	((+0.006418720657277) / (+2.34858630952381)) / ((sigma4 + 1.0e-6) * (sigma4 + 1.0e-6));
      acc = acc + omega14m;
      omega10m = (omega10m) / (acc);
      omega11m = (omega11m) / (acc);
      omega12m = (omega12m) / (acc);
      omega13m = (omega13m) / (acc);
      omega14m = (omega14m) / (acc);
      acc = 0.0;
      omega15 = (+0.0202597075592406) / ((sigma0 + 1.0e-6) * (sigma0 + 1.0e-6));
      acc = acc + omega15;
      omega16 = (+0.231701231086814) / ((sigma1 + 1.0e-6) * (sigma1 + 1.0e-6));
      acc = acc + omega16;
      omega17 = (+0.483908324647349) / ((sigma2 + 1.0e-6) * (sigma2 + 1.0e-6));
      acc = acc + omega17;
      omega18 = (+0.239547333598196) / ((sigma3 + 1.0e-6) * (sigma3 + 1.0e-6));
      acc = acc + omega18;
      omega19 = (+0.0245834031084023) / ((sigma4 + 1.0e-6) * (sigma4 + 1.0e-6));
      acc = acc + omega19;
      omega15 = (omega15) / (acc);
      omega16 = (omega16) / (acc);
      omega17 = (omega17) / (acc);
      omega18 = (omega18) / (acc);
      omega19 = (omega19) / (acc);
      acc = 0.0;
      omega20 = (+0.0351327512533764) / ((sigma0 + 1.0e-6) * (sigma0 + 1.0e-6));
      acc = acc + omega20;
      omega21 = (+0.301456855427841) / ((sigma1 + 1.0e-6) * (sigma1 + 1.0e-6));
      acc = acc + omega21;
      omega22 = (+0.481447897995538) / ((sigma2 + 1.0e-6) * (sigma2 + 1.0e-6));
      acc = acc + omega22;
      omega23 = (+0.172303979464071) / ((sigma3 + 1.0e-6) * (sigma3 + 1.0e-6));
      acc = acc + omega23;
      omega24 = (+0.0096585158591681) / ((sigma4 + 1.0e-6) * (sigma4 + 1.0e-6));
      acc = acc + omega24;
      omega20 = (omega20) / (acc);
      omega21 = (omega21) / (acc);
      omega22 = (omega22) / (acc);
      omega23 = (omega23) / (acc);
      omega24 = (omega24) / (acc);
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
      omega[i * wsi + 2 * wsl + 0 * wsr + 0] = omega10p;
      omega[i * wsi + 2 * wsl + 0 * wsr + 1] = omega10m;
      omega[i * wsi + 2 * wsl + 1 * wsr + 0] = omega11p;
      omega[i * wsi + 2 * wsl + 1 * wsr + 1] = omega11m;
      omega[i * wsi + 2 * wsl + 2 * wsr + 0] = omega12p;
      omega[i * wsi + 2 * wsl + 2 * wsr + 1] = omega12m;
      omega[i * wsi + 2 * wsl + 3 * wsr + 0] = omega13p;
      omega[i * wsi + 2 * wsl + 3 * wsr + 1] = omega13m;
      omega[i * wsi + 2 * wsl + 4 * wsr + 0] = omega14p;
      omega[i * wsi + 2 * wsl + 4 * wsr + 1] = omega14m;
      omega[i * wsi + 3 * wsl + 0 * wsr + 0] = omega15;
      omega[i * wsi + 3 * wsl + 1 * wsr + 0] = omega16;
      omega[i * wsi + 3 * wsl + 2 * wsr + 0] = omega17;
      omega[i * wsi + 3 * wsl + 3 * wsr + 0] = omega18;
      omega[i * wsi + 3 * wsl + 4 * wsr + 0] = omega19;
      omega[i * wsi + 4 * wsl + 0 * wsr + 0] = omega20;
      omega[i * wsi + 4 * wsl + 1 * wsr + 0] = omega21;
      omega[i * wsi + 4 * wsl + 2 * wsr + 0] = omega22;
      omega[i * wsi + 4 * wsl + 3 * wsr + 0] = omega23;
      omega[i * wsi + 4 * wsl + 4 * wsr + 0] = omega24;
    }
}

PyObject *
py_weights_gauss_legendre005005 (PyObject * self, PyObject * args)
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

  weights_gauss_legendre005005 (sigma, n, ssi, ssr, omega, wsi, wsl, wsr);

  Py_INCREF (Py_None);
  return Py_None;
}

void
reconstruct_gauss_legendre005005 (const double *restrict f, int n, int fsi,
				  const double *restrict omega, int wsi, int wsl, int wsr,
				  double *restrict fr, int frsi, int frsl)
{
  int i;
  double omega16, omega15, omega8, omega13p, omega14m, omega12p, omega3, omega20, omega7, omega14p,
    omega18, omega24, omega13m, omega10m, omega4, omega21, omega10p, omega17, omega0, omega9,
    omega22, omega5, omega1, omega11p, omega12m, omega11m, omega6, omega23, omega19, omega2, fs0,
    fs1, fs2, fs3, fs4, fr8, fr15, fr11, fr3, fr20, fr7, fr18, fr24, fr12, fr21, fr6, fr17, fr0,
    fr4, fr9, fr13, fr22, fr5, fr1, fr16, fr14, fr10, fr23, fr19, fr2;
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
      omega10p = omega[i * wsi + 2 * wsl + 0 * wsr + 0];
      omega10m = omega[i * wsi + 2 * wsl + 0 * wsr + 1];
      omega11p = omega[i * wsi + 2 * wsl + 1 * wsr + 0];
      omega11m = omega[i * wsi + 2 * wsl + 1 * wsr + 1];
      omega12p = omega[i * wsi + 2 * wsl + 2 * wsr + 0];
      omega12m = omega[i * wsi + 2 * wsl + 2 * wsr + 1];
      omega13p = omega[i * wsi + 2 * wsl + 3 * wsr + 0];
      omega13m = omega[i * wsi + 2 * wsl + 3 * wsr + 1];
      omega14p = omega[i * wsi + 2 * wsl + 4 * wsr + 0];
      omega14m = omega[i * wsi + 2 * wsl + 4 * wsr + 1];
      omega15 = omega[i * wsi + 3 * wsl + 0 * wsr + 0];
      omega16 = omega[i * wsi + 3 * wsl + 1 * wsr + 0];
      omega17 = omega[i * wsi + 3 * wsl + 2 * wsr + 0];
      omega18 = omega[i * wsi + 3 * wsl + 3 * wsr + 0];
      omega19 = omega[i * wsi + 3 * wsl + 4 * wsr + 0];
      omega20 = omega[i * wsi + 4 * wsl + 0 * wsr + 0];
      omega21 = omega[i * wsi + 4 * wsl + 1 * wsr + 0];
      omega22 = omega[i * wsi + 4 * wsl + 2 * wsr + 0];
      omega23 = omega[i * wsi + 4 * wsl + 3 * wsr + 0];
      omega24 = omega[i * wsi + 4 * wsl + 4 * wsr + 0];
      fr0 =
	(+2.11204531219679) * (f[(i + 0) * fsi]) + (-2.30523210409965) * (f[(i + 1) * fsi]) +
	(+1.89021774199236) * (f[(i + 2) * fsi]) + (-0.859830497503616) * (f[(i + 3) * fsi]) +
	(+0.162799547414111) * (f[(i + 4) * fsi]);
      fr1 =
	(+0.162799547414111) * (f[(i - 1) * fsi]) + (+1.29804757512624) * (f[(i + 0) * fsi]) +
	(-0.677236629958534) * (f[(i + 1) * fsi]) + (+0.262222267851247) * (f[(i + 2) * fsi]) +
	(-0.0458327604330604) * (f[(i + 3) * fsi]);
      fr2 =
	(-0.0458327604330605) * (f[(i - 2) * fsi]) + (+0.391963349579413) * (f[(i - 1) * fsi]) +
	(+0.839719970795631) * (f[(i + 0) * fsi]) + (-0.218909025627929) * (f[(i + 1) * fsi]) +
	(+0.0330584656859449) * (f[(i + 2) * fsi]);
      fr3 =
	(+0.0330584656859449) * (f[(i - 3) * fsi]) + (-0.211125088862785) * (f[(i - 2) * fsi]) +
	(+0.722548006438862) * (f[(i - 1) * fsi]) + (+0.509135313936182) * (f[(i + 0) * fsi]) +
	(-0.0536166971982048) * (f[(i + 1) * fsi]);
      fr4 =
	(-0.0536166971982048) * (f[(i - 4) * fsi]) + (+0.301141951676969) * (f[(i - 3) * fsi]) +
	(-0.747292060844833) * (f[(i - 2) * fsi]) + (+1.25871497842091) * (f[(i - 1) * fsi]) +
	(+0.241051827945158) * (f[(i + 0) * fsi]);
      fr5 =
	(+1.52509888693421) * (f[(i + 0) * fsi]) + (-0.957946521734337) * (f[(i + 1) * fsi]) +
	(+0.660144519356729) * (f[(i + 2) * fsi]) + (-0.277610366194454) * (f[(i + 3) * fsi]) +
	(+0.0503134816378496) * (f[(i + 4) * fsi]);
      fr6 =
	(+0.0503134816378496) * (f[(i - 1) * fsi]) + (+1.27353147874496) * (f[(i + 0) * fsi]) +
	(-0.454811705355841) * (f[(i + 1) * fsi]) + (+0.157009702978234) * (f[(i + 2) * fsi]) +
	(-0.0260429580052059) * (f[(i + 3) * fsi]);
      fr7 =
	(-0.026042958005206) * (f[(i - 2) * fsi]) + (+0.180528271663879) * (f[(i - 1) * fsi]) +
	(+1.0131018986929) * (f[(i + 0) * fsi]) + (-0.194382125303782) * (f[(i + 1) * fsi]) +
	(+0.0267949129522039) * (f[(i + 2) * fsi]);
      fr8 =
	(+0.0267949129522039) * (f[(i - 3) * fsi]) + (-0.160017522766225) * (f[(i - 2) * fsi]) +
	(+0.448477401185918) * (f[(i - 1) * fsi]) + (+0.745152769170866) * (f[(i + 0) * fsi]) +
	(-0.0604075605427624) * (f[(i + 1) * fsi]);
      fr9 =
	(-0.0604075605427624) * (f[(i - 4) * fsi]) + (+0.328832715666016) * (f[(i - 3) * fsi]) +
	(-0.764093128193849) * (f[(i - 2) * fsi]) + (+1.05255300661354) * (f[(i - 1) * fsi]) +
	(+0.443114966457054) * (f[(i + 0) * fsi]);
      fr10 =
	(+0.8796875) * (f[(i + 0) * fsi]) + (+0.35625) * (f[(i + 1) * fsi]) +
	(-0.388541666666667) * (f[(i + 2) * fsi]) + (+0.189583333333333) * (f[(i + 3) * fsi]) +
	(-0.0369791666666667) * (f[(i + 4) * fsi]);
      fr11 =
	(-0.0369791666666667) * (f[(i - 1) * fsi]) + (+1.06458333333333) * (f[(i + 0) * fsi]) +
	(-0.0135416666666667) * (f[(i + 1) * fsi]) + (-0.01875) * (f[(i + 2) * fsi]) +
	(+0.0046875) * (f[(i + 3) * fsi]);
      fr12 =
	(+0.0046875) * (f[(i - 2) * fsi]) + (-0.0604166666666667) * (f[(i - 1) * fsi]) +
	(+1.11145833333333) * (f[(i + 0) * fsi]) + (-0.0604166666666667) * (f[(i + 1) * fsi]) +
	(+0.0046875) * (f[(i + 2) * fsi]);
      fr13 =
	(+0.0046875) * (f[(i - 3) * fsi]) + (-0.01875) * (f[(i - 2) * fsi]) +
	(-0.0135416666666667) * (f[(i - 1) * fsi]) + (+1.06458333333333) * (f[(i + 0) * fsi]) +
	(-0.0369791666666667) * (f[(i + 1) * fsi]);
      fr14 =
	(-0.0369791666666667) * (f[(i - 4) * fsi]) + (+0.189583333333333) * (f[(i - 3) * fsi]) +
	(-0.388541666666667) * (f[(i - 2) * fsi]) + (+0.35625) * (f[(i - 1) * fsi]) +
	(+0.8796875) * (f[(i + 0) * fsi]);
      fr15 =
	(+0.443114966457054) * (f[(i + 0) * fsi]) + (+1.05255300661354) * (f[(i + 1) * fsi]) +
	(-0.764093128193849) * (f[(i + 2) * fsi]) + (+0.328832715666015) * (f[(i + 3) * fsi]) +
	(-0.0604075605427624) * (f[(i + 4) * fsi]);
      fr16 =
	(-0.0604075605427624) * (f[(i - 1) * fsi]) + (+0.745152769170866) * (f[(i + 0) * fsi]) +
	(+0.448477401185918) * (f[(i + 1) * fsi]) + (-0.160017522766225) * (f[(i + 2) * fsi]) +
	(+0.0267949129522039) * (f[(i + 3) * fsi]);
      fr17 =
	(+0.0267949129522039) * (f[(i - 2) * fsi]) + (-0.194382125303782) * (f[(i - 1) * fsi]) +
	(+1.0131018986929) * (f[(i + 0) * fsi]) + (+0.180528271663879) * (f[(i + 1) * fsi]) +
	(-0.0260429580052059) * (f[(i + 2) * fsi]);
      fr18 =
	(-0.0260429580052059) * (f[(i - 3) * fsi]) + (+0.157009702978234) * (f[(i - 2) * fsi]) +
	(-0.454811705355841) * (f[(i - 1) * fsi]) + (+1.27353147874496) * (f[(i + 0) * fsi]) +
	(+0.0503134816378496) * (f[(i + 1) * fsi]);
      fr19 =
	(+0.0503134816378496) * (f[(i - 4) * fsi]) + (-0.277610366194454) * (f[(i - 3) * fsi]) +
	(+0.660144519356729) * (f[(i - 2) * fsi]) + (-0.957946521734337) * (f[(i - 1) * fsi]) +
	(+1.52509888693421) * (f[(i + 0) * fsi]);
      fr20 =
	(+0.241051827945158) * (f[(i + 0) * fsi]) + (+1.25871497842091) * (f[(i + 1) * fsi]) +
	(-0.747292060844833) * (f[(i + 2) * fsi]) + (+0.30114195167697) * (f[(i + 3) * fsi]) +
	(-0.0536166971982048) * (f[(i + 4) * fsi]);
      fr21 =
	(-0.0536166971982047) * (f[(i - 1) * fsi]) + (+0.509135313936183) * (f[(i + 0) * fsi]) +
	(+0.722548006438862) * (f[(i + 1) * fsi]) + (-0.211125088862785) * (f[(i + 2) * fsi]) +
	(+0.0330584656859449) * (f[(i + 3) * fsi]);
      fr22 =
	(+0.0330584656859449) * (f[(i - 2) * fsi]) + (-0.218909025627929) * (f[(i - 1) * fsi]) +
	(+0.839719970795632) * (f[(i + 0) * fsi]) + (+0.391963349579413) * (f[(i + 1) * fsi]) +
	(-0.0458327604330604) * (f[(i + 2) * fsi]);
      fr23 =
	(-0.0458327604330604) * (f[(i - 3) * fsi]) + (+0.262222267851247) * (f[(i - 2) * fsi]) +
	(-0.677236629958534) * (f[(i - 1) * fsi]) + (+1.29804757512624) * (f[(i + 0) * fsi]) +
	(+0.162799547414111) * (f[(i + 1) * fsi]);
      fr24 =
	(+0.162799547414111) * (f[(i - 4) * fsi]) + (-0.859830497503616) * (f[(i - 3) * fsi]) +
	(+1.89021774199236) * (f[(i - 2) * fsi]) + (-2.30523210409964) * (f[(i - 1) * fsi]) +
	(+2.11204531219679) * (f[(i + 0) * fsi]);
      fs0 =
	(omega0) * (fr0) + (omega1) * (fr1) + (omega2) * (fr2) + (omega3) * (fr3) +
	(omega4) * (fr4);
      fs1 =
	(omega5) * (fr5) + (omega6) * (fr6) + (omega7) * (fr7) + (omega8) * (fr8) +
	(omega9) * (fr9);
      fs2 =
	((+3.34858630952381) *
	 ((omega10p) * (fr10) + (omega11p) * (fr11) + (omega12p) * (fr12) + (omega13p) * (fr13) +
	  (omega14p) * (fr14))) - ((+2.34858630952381) * ((omega10m) * (fr10) +
							  (omega11m) * (fr11) +
							  (omega12m) * (fr12) +
							  (omega13m) * (fr13) +
							  (omega14m) * (fr14)));
      fs3 =
	(omega15) * (fr15) + (omega16) * (fr16) + (omega17) * (fr17) + (omega18) * (fr18) +
	(omega19) * (fr19);
      fs4 =
	(omega20) * (fr20) + (omega21) * (fr21) + (omega22) * (fr22) + (omega23) * (fr23) +
	(omega24) * (fr24);
      fr[i * frsi + 0 * frsl] = fs0;
      fr[i * frsi + 1 * frsl] = fs1;
      fr[i * frsi + 2 * frsl] = fs2;
      fr[i * frsi + 3 * frsl] = fs3;
      fr[i * frsi + 4 * frsl] = fs4;
    }
}

PyObject *
py_reconstruct_gauss_legendre005005 (PyObject * self, PyObject * args)
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

  reconstruct_gauss_legendre005005 (f, n, fsi, omega, wsi, wsl, wsr, fr, frsi, frsl);

  Py_INCREF (Py_None);
  return Py_None;
}
