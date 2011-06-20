#include <Python.h>
#include <numpy/ndarrayobject.h>

void
weights_gauss_radau005004 (const double *restrict sigma, int n, int ssi, int ssr,
			   double *restrict omega, int wsi, int wsl, int wsr)
{
  int i;
  double acc, sigma0, sigma1, sigma2, sigma3, sigma4, omega16, omega15, omega8, omega13p, omega14m,
    omega12p, omega3, omega7, omega14p, omega18, omega13m, omega10m, omega4, omega10p, omega17,
    omega0, omega9, omega5, omega1, omega11p, omega12m, omega11m, omega6, omega19, omega2;
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
      omega5 = (+0.0217060226167778) / ((sigma0 + 1.0e-6) * (sigma0 + 1.0e-6));
      acc = acc + omega5;
      omega6 = (+0.231282544777988) / ((sigma1 + 1.0e-6) * (sigma1 + 1.0e-6));
      acc = acc + omega6;
      omega7 = (+0.48571892727159) / ((sigma2 + 1.0e-6) * (sigma2 + 1.0e-6));
      acc = acc + omega7;
      omega8 = (+0.239676040757904) / ((sigma3 + 1.0e-6) * (sigma3 + 1.0e-6));
      acc = acc + omega8;
      omega9 = (+0.0216164645757406) / ((sigma4 + 1.0e-6) * (sigma4 + 1.0e-6));
      acc = acc + omega9;
      omega5 = (omega5) / (acc);
      omega6 = (omega6) / (acc);
      omega7 = (omega7) / (acc);
      omega8 = (omega8) / (acc);
      omega9 = (omega9) / (acc);
      acc = 0.0;
      omega10p =
	((+0.0135899482983879) / (+2.10235278681252)) / ((sigma0 + 1.0e-6) * (sigma0 + 1.0e-6));
      acc = acc + omega10p;
      omega11p =
	((+0.212518629694485) / (+2.10235278681252)) / ((sigma1 + 1.0e-6) * (sigma1 + 1.0e-6));
      acc = acc + omega11p;
      omega12p =
	((+0.463641859761349) / (+2.10235278681252)) / ((sigma2 + 1.0e-6) * (sigma2 + 1.0e-6));
      acc = acc + omega12p;
      omega13p =
	((+1.37848475345412) / (+2.10235278681252)) / ((sigma3 + 1.0e-6) * (sigma3 + 1.0e-6));
      acc = acc + omega13p;
      omega14p =
	((+0.0341175956041729) / (+2.10235278681252)) / ((sigma4 + 1.0e-6) * (sigma4 + 1.0e-6));
      acc = acc + omega14p;
      omega10p = (omega10p) / (acc);
      omega11p = (omega11p) / (acc);
      omega12p = (omega12p) / (acc);
      omega13p = (omega13p) / (acc);
      omega14p = (omega14p) / (acc);
      acc = 0.0;
      omega10m =
	((+0.00679497414919394) / (+1.10235278681252)) / ((sigma0 + 1.0e-6) * (sigma0 + 1.0e-6));
      acc = acc + omega10m;
      omega11m =
	((+0.106259314847242) / (+1.10235278681252)) / ((sigma1 + 1.0e-6) * (sigma1 + 1.0e-6));
      acc = acc + omega11m;
      omega12m =
	((+0.231820929880674) / (+1.10235278681252)) / ((sigma2 + 1.0e-6) * (sigma2 + 1.0e-6));
      acc = acc + omega12m;
      omega13m =
	((+0.689242376727061) / (+1.10235278681252)) / ((sigma3 + 1.0e-6) * (sigma3 + 1.0e-6));
      acc = acc + omega13m;
      omega14m =
	((+0.0682351912083459) / (+1.10235278681252)) / ((sigma4 + 1.0e-6) * (sigma4 + 1.0e-6));
      acc = acc + omega14m;
      omega10m = (omega10m) / (acc);
      omega11m = (omega11m) / (acc);
      omega12m = (omega12m) / (acc);
      omega13m = (omega13m) / (acc);
      omega14m = (omega14m) / (acc);
      acc = 0.0;
      omega15 = (+0.031417209013405) / ((sigma0 + 1.0e-6) * (sigma0 + 1.0e-6));
      acc = acc + omega15;
      omega16 = (+0.286919889284738) / ((sigma1 + 1.0e-6) * (sigma1 + 1.0e-6));
      acc = acc + omega16;
      omega17 = (+0.484890946111401) / ((sigma2 + 1.0e-6) * (sigma2 + 1.0e-6));
      acc = acc + omega17;
      omega18 = (+0.185219502891762) / ((sigma3 + 1.0e-6) * (sigma3 + 1.0e-6));
      acc = acc + omega18;
      omega19 = (+0.0115524526986958) / ((sigma4 + 1.0e-6) * (sigma4 + 1.0e-6));
      acc = acc + omega19;
      omega15 = (omega15) / (acc);
      omega16 = (omega16) / (acc);
      omega17 = (omega17) / (acc);
      omega18 = (omega18) / (acc);
      omega19 = (omega19) / (acc);
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
    }
}

PyObject *
py_weights_gauss_radau005004 (PyObject * self, PyObject * args)
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

  weights_gauss_radau005004 (sigma, n, ssi, ssr, omega, wsi, wsl, wsr);

  Py_INCREF (Py_None);
  return Py_None;
}

void
reconstruct_gauss_radau005004 (const double *restrict f, int n, int fsi,
			       const double *restrict omega, int wsi, int wsl, int wsr,
			       double *restrict fr, int frsi, int frsl)
{
  int i;
  double omega16, omega15, omega8, omega13p, omega14m, omega12p, omega3, omega7, omega14p, omega18,
    omega13m, omega10m, omega4, omega10p, omega17, omega0, omega9, omega5, omega1, omega11p,
    omega12m, omega11m, omega6, omega19, omega2, fs0, fs1, fs2, fs3, fr1, fr7, fr17, fr0, fr16,
    fr18, fr15, fr12, fr6, fr9, fr2, fr10, fr8, fr13, fr11, fr4, fr14, fr3, fr19, fr5;
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
	(+1.57816703491245) * (f[(i + 0) * fsi]) + (-1.07504046145797) * (f[(i + 1) * fsi]) +
	(+0.762634607365795) * (f[(i + 2) * fsi]) + (-0.325156508246618) * (f[(i + 3) * fsi]) +
	(+0.0593953274263477) * (f[(i + 4) * fsi]);
      fr6 =
	(+0.0593953274263477) * (f[(i - 1) * fsi]) + (+1.28119039778071) * (f[(i + 0) * fsi]) +
	(-0.481087187194497) * (f[(i + 1) * fsi]) + (+0.168681333102318) * (f[(i + 2) * fsi]) +
	(-0.0281798711148796) * (f[(i + 3) * fsi]);
      fr7 =
	(-0.0281798711148796) * (f[(i - 2) * fsi]) + (+0.200294683000746) * (f[(i - 1) * fsi]) +
	(+0.999391686631915) * (f[(i + 0) * fsi]) + (-0.199288476045701) * (f[(i + 1) * fsi]) +
	(+0.0277819775279201) * (f[(i + 2) * fsi]);
      fr8 =
	(+0.0277819775279201) * (f[(i - 3) * fsi]) + (-0.16708975875448) * (f[(i - 2) * fsi]) +
	(+0.478114458279947) * (f[(i - 1) * fsi]) + (+0.721571911352714) * (f[(i + 0) * fsi]) +
	(-0.0603785884061003) * (f[(i + 1) * fsi]);
      fr9 =
	(-0.0603785884061003) * (f[(i - 4) * fsi]) + (+0.329674919558421) * (f[(i - 3) * fsi]) +
	(-0.770875642815483) * (f[(i - 2) * fsi]) + (+1.08190034234095) * (f[(i - 1) * fsi]) +
	(+0.419678969322212) * (f[(i + 0) * fsi]);
      fr10 =
	(+0.71198306235081) * (f[(i + 0) * fsi]) + (+0.650700411424756) * (f[(i + 1) * fsi]) +
	(-0.578434125186126) * (f[(i + 2) * fsi]) + (+0.266301631135479) * (f[(i + 3) * fsi]) +
	(-0.0505509797249192) * (f[(i + 4) * fsi]);
      fr11 =
	(-0.0505509797249192) * (f[(i - 1) * fsi]) + (+0.964737960975406) * (f[(i + 0) * fsi]) +
	(+0.145190614175563) * (f[(i + 1) * fsi]) + (-0.0729243279369333) * (f[(i + 2) * fsi]) +
	(+0.0135467325108831) * (f[(i + 3) * fsi]);
      fr12 =
	(+0.0135467325108831) * (f[(i - 2) * fsi]) + (-0.118284642279335) * (f[(i - 1) * fsi]) +
	(+1.10020528608424) * (f[(i + 0) * fsi]) + (+0.00972328906673214) * (f[(i + 1) * fsi]) +
	(-0.0051906653825177) * (f[(i + 2) * fsi]);
      fr13 =
	(-0.0051906653825177) * (f[(i - 3) * fsi]) + (+0.0395000594234717) * (f[(i - 2) * fsi]) +
	(-0.170191296104512) * (f[(i - 1) * fsi]) + (+1.15211193990941) * (f[(i + 0) * fsi]) +
	(-0.0162300378458564) * (f[(i + 1) * fsi]);
      fr14 =
	(-0.0162300378458564) * (f[(i - 4) * fsi]) + (+0.075959523846764) * (f[(i - 3) * fsi]) +
	(-0.122800319035092) * (f[(i - 2) * fsi]) + (-0.00789091764594829) * (f[(i - 1) * fsi]) +
	(+1.07096175068013) * (f[(i + 0) * fsi]);
      fr15 =
	(+0.280924455006628) * (f[(i + 0) * fsi]) + (+1.22794271558924) * (f[(i + 1) * fsi]) +
	(-0.766353751650724) * (f[(i + 2) * fsi]) + (+0.313769496019927) * (f[(i + 3) * fsi]) +
	(-0.0562829149650685) * (f[(i + 4) * fsi]);
      fr16 =
	(-0.0562829149650685) * (f[(i - 1) * fsi]) + (+0.562339029831972) * (f[(i + 0) * fsi]) +
	(+0.66511356593855) * (f[(i + 1) * fsi]) + (-0.203524602000037) * (f[(i + 2) * fsi]) +
	(+0.0323549211945837) * (f[(i + 3) * fsi]);
      fr17 =
	(+0.0323549211945837) * (f[(i - 2) * fsi]) + (-0.218057520937987) * (f[(i - 1) * fsi]) +
	(+0.885888241777809) * (f[(i + 0) * fsi]) + (+0.341564353992713) * (f[(i + 1) * fsi]) +
	(-0.0417499960271184) * (f[(i + 2) * fsi]);
      fr18 =
	(-0.0417499960271184) * (f[(i - 3) * fsi]) + (+0.241104901330176) * (f[(i - 2) * fsi]) +
	(-0.635557481209171) * (f[(i - 1) * fsi]) + (+1.30338820204899) * (f[(i + 0) * fsi]) +
	(+0.132814373857121) * (f[(i + 1) * fsi]);
      fr19 =
	(+0.132814373857121) * (f[(i - 4) * fsi]) + (-0.705821865312725) * (f[(i - 3) * fsi]) +
	(+1.56924863990139) * (f[(i - 2) * fsi]) + (-1.96370121978038) * (f[(i - 1) * fsi]) +
	(+1.9674600713346) * (f[(i + 0) * fsi]);
      fs0 =
	(omega0) * (fr0) + (omega1) * (fr1) + (omega2) * (fr2) + (omega3) * (fr3) +
	(omega4) * (fr4);
      fs1 =
	(omega5) * (fr5) + (omega6) * (fr6) + (omega7) * (fr7) + (omega8) * (fr8) +
	(omega9) * (fr9);
      fs2 =
	((+2.10235278681252) *
	 ((omega10p) * (fr10) + (omega11p) * (fr11) + (omega12p) * (fr12) + (omega13p) * (fr13) +
	  (omega14p) * (fr14))) - ((+1.10235278681252) * ((omega10m) * (fr10) +
							  (omega11m) * (fr11) +
							  (omega12m) * (fr12) +
							  (omega13m) * (fr13) +
							  (omega14m) * (fr14)));
      fs3 =
	(omega15) * (fr15) + (omega16) * (fr16) + (omega17) * (fr17) + (omega18) * (fr18) +
	(omega19) * (fr19);
      fr[i * frsi + 0 * frsl] = fs0;
      fr[i * frsi + 1 * frsl] = fs1;
      fr[i * frsi + 2 * frsl] = fs2;
      fr[i * frsi + 3 * frsl] = fs3;
    }
}

PyObject *
py_reconstruct_gauss_radau005004 (PyObject * self, PyObject * args)
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

  reconstruct_gauss_radau005004 (f, n, fsi, omega, wsi, wsl, wsr, fr, frsi, frsl);

  Py_INCREF (Py_None);
  return Py_None;
}
