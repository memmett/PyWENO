#include <Python.h>
#include <numpy/ndarrayobject.h>

void
weights_gauss_radau006004 (const double *restrict sigma, int n, int ssi, int ssr,
			   double *restrict omega, int wsi, int wsl, int wsr)
{
  int i;
  double acc, sigma0, sigma1, sigma2, sigma3, sigma4, sigma5, omega9, omega18, omega15p, omega16m,
    omega14p, omega3, omega8, omega16p, omega19, omega21, omega15m, omega11, omega12m, omega4,
    omega12p, omega20, omega0, omega17p, omega10, omega17m, omega5, omega6, omega23, omega1,
    omega13p, omega14m, omega13m, omega7, omega22, omega2;
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
      omega6 = (+0.00677201832660494) / ((sigma0 + 1.0e-6) * (sigma0 + 1.0e-6));
      acc = acc + omega6;
      omega7 = (+0.107265913289826) / ((sigma1 + 1.0e-6) * (sigma1 + 1.0e-6));
      acc = acc + omega7;
      omega8 = (+0.380324261915151) / ((sigma2 + 1.0e-6) * (sigma2 + 1.0e-6));
      acc = acc + omega8;
      omega9 = (+0.386977736276944) / ((sigma3 + 1.0e-6) * (sigma3 + 1.0e-6));
      acc = acc + omega9;
      omega10 = (+0.112027858604345) / ((sigma4 + 1.0e-6) * (sigma4 + 1.0e-6));
      acc = acc + omega10;
      omega11 = (+0.00663221158712994) / ((sigma5 + 1.0e-6) * (sigma5 + 1.0e-6));
      acc = acc + omega11;
      omega6 = (omega6) / (acc);
      omega7 = (omega7) / (acc);
      omega8 = (omega8) / (acc);
      omega9 = (omega9) / (acc);
      omega10 = (omega10) / (acc);
      omega11 = (omega11) / (acc);
      acc = 0.0;
      omega12p =
	((+0.00402560307167669) / (+2.02092329375878)) / ((sigma0 + 1.0e-6) * (sigma0 + 1.0e-6));
      acc = acc + omega12p;
      omega13p =
	((+0.0948077070036824) / (+2.02092329375878)) / ((sigma1 + 1.0e-6) * (sigma1 + 1.0e-6));
      acc = acc + omega13p;
      omega14p =
	((+0.432572020266995) / (+2.02092329375878)) / ((sigma2 + 1.0e-6) * (sigma2 + 1.0e-6));
      acc = acc + omega14p;
      omega15p =
	((+0.0239353628232871) / (+2.02092329375878)) / ((sigma3 + 1.0e-6) * (sigma3 + 1.0e-6));
      acc = acc + omega15p;
      omega16p =
	((+1.45860816934021) / (+2.02092329375878)) / ((sigma4 + 1.0e-6) * (sigma4 + 1.0e-6));
      acc = acc + omega16p;
      omega17p =
	((+0.00697443125292721) / (+2.02092329375878)) / ((sigma5 + 1.0e-6) * (sigma5 + 1.0e-6));
      acc = acc + omega17p;
      omega12p = (omega12p) / (acc);
      omega13p = (omega13p) / (acc);
      omega14p = (omega14p) / (acc);
      omega15p = (omega15p) / (acc);
      omega16p = (omega16p) / (acc);
      omega17p = (omega17p) / (acc);
      acc = 0.0;
      omega12m =
	((+0.00201280153583835) / (+1.02092329375878)) / ((sigma0 + 1.0e-6) * (sigma0 + 1.0e-6));
      acc = acc + omega12m;
      omega13m =
	((+0.0474038535018412) / (+1.02092329375878)) / ((sigma1 + 1.0e-6) * (sigma1 + 1.0e-6));
      acc = acc + omega13m;
      omega14m =
	((+0.216286010133497) / (+1.02092329375878)) / ((sigma2 + 1.0e-6) * (sigma2 + 1.0e-6));
      acc = acc + omega14m;
      omega15m =
	((+0.0119676814116435) / (+1.02092329375878)) / ((sigma3 + 1.0e-6) * (sigma3 + 1.0e-6));
      acc = acc + omega15m;
      omega16m =
	((+0.729304084670107) / (+1.02092329375878)) / ((sigma4 + 1.0e-6) * (sigma4 + 1.0e-6));
      acc = acc + omega16m;
      omega17m =
	((+0.0139488625058544) / (+1.02092329375878)) / ((sigma5 + 1.0e-6) * (sigma5 + 1.0e-6));
      acc = acc + omega17m;
      omega12m = (omega12m) / (acc);
      omega13m = (omega13m) / (acc);
      omega14m = (omega14m) / (acc);
      omega15m = (omega15m) / (acc);
      omega16m = (omega16m) / (acc);
      omega17m = (omega17m) / (acc);
      acc = 0.0;
      omega18 = (+0.00999709318423371) / ((sigma0 + 1.0e-6) * (sigma0 + 1.0e-6));
      acc = acc + omega18;
      omega19 = (+0.141307791850495) / ((sigma1 + 1.0e-6) * (sigma1 + 1.0e-6));
      acc = acc + omega19;
      omega20 = (+0.417983745381249) / ((sigma2 + 1.0e-6) * (sigma2 + 1.0e-6));
      acc = acc + omega20;
      omega21 = (+0.348255604187079) / ((sigma3 + 1.0e-6) * (sigma3 + 1.0e-6));
      acc = acc + omega21;
      omega22 = (+0.0791777371169748) / ((sigma4 + 1.0e-6) * (sigma4 + 1.0e-6));
      acc = acc + omega22;
      omega23 = (+0.003278028279983) / ((sigma5 + 1.0e-6) * (sigma5 + 1.0e-6));
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
    }
}

PyObject *
py_weights_gauss_radau006004 (PyObject * self, PyObject * args)
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

  weights_gauss_radau006004 (sigma, n, ssi, ssr, omega, wsi, wsl, wsr);

  Py_INCREF (Py_None);
  return Py_None;
}

void
reconstruct_gauss_radau006004 (const double *restrict f, int n, int fsi,
			       const double *restrict omega, int wsi, int wsl, int wsr,
			       double *restrict fr, int frsi, int frsl)
{
  int i;
  double omega9, omega18, omega15p, omega16m, omega14p, omega3, omega8, omega16p, omega19, omega21,
    omega15m, omega11, omega12m, omega4, omega12p, omega20, omega0, omega17p, omega10, omega17m,
    omega5, omega6, omega23, omega1, omega13p, omega14m, omega13m, omega7, omega22, omega2, fs0,
    fs1, fs2, fs3, fr9, fr18, fr13, fr17, fr3, fr8, fr21, fr11, fr14, fr7, fr20, fr0, fr4, fr10,
    fr5, fr6, fr23, fr1, fr19, fr2, fr12, fr15, fr22, fr16;
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
	(+1.62117649102017) * (f[(i + 0) * fsi]) + (-1.29008774199659) * (f[(i + 1) * fsi]) +
	(+1.19272916844303) * (f[(i + 2) * fsi]) + (-0.755251069323849) * (f[(i + 3) * fsi]) +
	(+0.274442607964963) * (f[(i + 4) * fsi]) + (-0.0430094561077231) * (f[(i + 5) * fsi]);
      fr7 =
	(+0.0430094561077231) * (f[(i - 1) * fsi]) + (+1.36311975437383) * (f[(i + 0) * fsi]) +
	(-0.644945900380743) * (f[(i + 1) * fsi]) + (+0.332540046288564) * (f[(i + 2) * fsi]) +
	(-0.110109227708003) * (f[(i + 3) * fsi]) + (+0.0163858713186246) * (f[(i + 4) * fsi]);
      fr8 =
	(-0.0163858713186246) * (f[(i - 2) * fsi]) + (+0.141324684019471) * (f[(i - 1) * fsi]) +
	(+1.11733168459446) * (f[(i + 0) * fsi]) + (-0.31722847400825) * (f[(i + 1) * fsi]) +
	(+0.0867519765091948) * (f[(i + 2) * fsi]) + (-0.0117939997962549) * (f[(i + 3) * fsi]);
      fr9 =
	(+0.0117939997962549) * (f[(i - 3) * fsi]) + (-0.0871498700961542) * (f[(i - 2) * fsi]) +
	(+0.318234680963295) * (f[(i - 1) * fsi]) + (+0.881451688669366) * (f[(i + 0) * fsi]) +
	(-0.140318477064426) * (f[(i + 1) * fsi]) + (+0.0159879777316652) * (f[(i + 2) * fsi]);
      fr10 =
	(-0.0159879777316652) * (f[(i - 4) * fsi]) + (+0.107721866186246) * (f[(i - 3) * fsi]) +
	(-0.326969536071132) * (f[(i - 2) * fsi]) + (+0.637994235596599) * (f[(i - 1) * fsi]) +
	(+0.641632022694388) * (f[(i + 0) * fsi]) + (-0.0443906106744351) * (f[(i + 1) * fsi]);
      fr11 =
	(+0.0443906106744351) * (f[(i - 5) * fsi]) + (-0.282331641778276) * (f[(i - 4) * fsi]) +
	(+0.773581026302773) * (f[(i - 3) * fsi]) + (-1.21478174955983) * (f[(i - 2) * fsi]) +
	(+1.30385339571313) * (f[(i - 1) * fsi]) + (+0.375288358647777) * (f[(i + 0) * fsi]);
      fr12 =
	(+0.67094398787024) * (f[(i + 0) * fsi]) + (+0.855895783827608) * (f[(i + 1) * fsi]) +
	(-0.988824869991825) * (f[(i + 2) * fsi]) + (+0.67669237594118) * (f[(i + 3) * fsi]) +
	(-0.25574635212777) * (f[(i + 4) * fsi]) + (+0.0410390744805702) * (f[(i + 5) * fsi]);
      fr13 =
	(-0.0410390744805702) * (f[(i - 1) * fsi]) + (+0.91717843475366) * (f[(i + 0) * fsi]) +
	(+0.240309666619054) * (f[(i + 1) * fsi]) + (-0.168043380380424) * (f[(i + 2) * fsi]) +
	(+0.0611062587326286) * (f[(i + 3) * fsi]) + (-0.00951190524434911) * (f[(i + 4) * fsi]);
      fr14 =
	(+0.0095119052443491) * (f[(i - 2) * fsi]) + (-0.0981105059466648) * (f[(i - 1) * fsi]) +
	(+1.0598570134189) * (f[(i + 0) * fsi]) + (+0.0500715617320723) * (f[(i + 1) * fsi]) +
	(-0.0253648017151878) * (f[(i + 2) * fsi]) + (+0.00403482726653401) * (f[(i + 3) * fsi]);
      fr15 =
	(-0.00403482726653401) * (f[(i - 3) * fsi]) + (+0.0337208688435532) * (f[(i - 2) * fsi]) +
	(-0.158632914944675) * (f[(i - 1) * fsi]) + (+1.14055355874958) * (f[(i + 0) * fsi]) +
	(-0.0104508472659379) * (f[(i + 1) * fsi]) + (-0.00115583811598369) * (f[(i + 2) * fsi]);
      fr16 =
	(+0.00115583811598369) * (f[(i - 4) * fsi]) + (-0.0109698559624361) * (f[(i - 3) * fsi]) +
	(+0.0510584405833085) * (f[(i - 2) * fsi]) + (-0.181749677264349) * (f[(i - 1) * fsi]) +
	(+1.15789113048933) * (f[(i + 0) * fsi]) + (-0.01738587596184) * (f[(i + 1) * fsi]);
      fr17 =
	(+0.01738587596184) * (f[(i - 5) * fsi]) + (-0.103159417655056) * (f[(i - 4) * fsi]) +
	(+0.249818283465164) * (f[(i - 3) * fsi]) + (-0.296659078653492) * (f[(i - 2) * fsi]) +
	(+0.0790384621632518) * (f[(i - 1) * fsi]) + (+1.05357587471829) * (f[(i + 0) * fsi]);
      fr18 =
	(+0.241784045018277) * (f[(i + 0) * fsi]) + (+1.423644765531) * (f[(i + 1) * fsi]) +
	(-1.15775785153424) * (f[(i + 2) * fsi]) + (+0.705173595903445) * (f[(i + 3) * fsi]) +
	(-0.251984964906828) * (f[(i + 4) * fsi]) + (+0.0391404099883515) * (f[(i + 5) * fsi]);
      fr19 =
	(-0.0391404099883517) * (f[(i - 1) * fsi]) + (+0.476626504948387) * (f[(i + 0) * fsi]) +
	(+0.836538615705721) * (f[(i + 1) * fsi]) + (-0.374949651767207) * (f[(i + 2) * fsi]) +
	(+0.118067446078169) * (f[(i + 3) * fsi]) + (-0.017142504976717) * (f[(i + 4) * fsi]);
      fr20 =
	(+0.017142504976717) * (f[(i - 2) * fsi]) + (-0.141995439848654) * (f[(i - 1) * fsi]) +
	(+0.733764079599142) * (f[(i + 0) * fsi]) + (+0.49368851617138) * (f[(i + 1) * fsi]) +
	(-0.117812077116452) * (f[(i + 2) * fsi]) + (+0.0152124162178667) * (f[(i + 3) * fsi]);
      fr21 =
	(-0.0152124162178667) * (f[(i - 3) * fsi]) + (+0.108417002283917) * (f[(i - 2) * fsi]) +
	(-0.370181683116655) * (f[(i - 1) * fsi]) + (+1.03801240395648) * (f[(i + 0) * fsi]) +
	(+0.265502272903379) * (f[(i + 1) * fsi]) + (-0.0265375798092516) * (f[(i + 2) * fsi]);
      fr22 =
	(+0.0265375798092516) * (f[(i - 4) * fsi]) + (-0.174437895073377) * (f[(i - 3) * fsi]) +
	(+0.506480699422692) * (f[(i - 2) * fsi]) + (-0.900933279301688) * (f[(i - 1) * fsi]) +
	(+1.43607610109525) * (f[(i + 0) * fsi]) + (+0.10627679404787) * (f[(i + 1) * fsi]);
      fr23 =
	(-0.10627679404787) * (f[(i - 5) * fsi]) + (+0.664198344096469) * (f[(i - 4) * fsi]) +
	(-1.76858980579142) * (f[(i - 3) * fsi]) + (+2.63201658038008) * (f[(i - 2) * fsi]) +
	(-2.49508519001973) * (f[(i - 1) * fsi]) + (+2.07373686538247) * (f[(i + 0) * fsi]);
      fs0 =
	(omega0) * (fr0) + (omega1) * (fr1) + (omega2) * (fr2) + (omega3) * (fr3) +
	(omega4) * (fr4) + (omega5) * (fr5);
      fs1 =
	(omega6) * (fr6) + (omega7) * (fr7) + (omega8) * (fr8) + (omega9) * (fr9) +
	(omega10) * (fr10) + (omega11) * (fr11);
      fs2 =
	((+2.02092329375878) *
	 ((omega12p) * (fr12) + (omega13p) * (fr13) + (omega14p) * (fr14) + (omega15p) * (fr15) +
	  (omega16p) * (fr16) + (omega17p) * (fr17))) -
	((+1.02092329375878) *
	 ((omega12m) * (fr12) + (omega13m) * (fr13) + (omega14m) * (fr14) + (omega15m) * (fr15) +
	  (omega16m) * (fr16) + (omega17m) * (fr17)));
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
py_reconstruct_gauss_radau006004 (PyObject * self, PyObject * args)
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

  reconstruct_gauss_radau006004 (f, n, fsi, omega, wsi, wsl, wsr, fr, frsi, frsl);

  Py_INCREF (Py_None);
  return Py_None;
}
