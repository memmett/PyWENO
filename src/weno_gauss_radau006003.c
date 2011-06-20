#include <Python.h>
#include <numpy/ndarrayobject.h>

void
weights_gauss_radau006003 (const double *restrict sigma, int n, int ssi, int ssr,
			   double *restrict omega, int wsi, int wsl, int wsr)
{
  int i;
  double acc, sigma0, sigma1, sigma2, sigma3, sigma4, sigma5, omega6p, omega9m, omega13, omega6m,
    omega9p, omega3, omega17, omega10p, omega10m, omega14, omega8p, omega8m, omega0, omega4, omega5,
    omega16, omega7m, omega1, omega7p, omega2, omega12, omega11m, omega15, omega11p;
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
	((+0.0358190908385941) / (+2.10745727251578)) / ((sigma0 + 1.0e-6) * (sigma0 + 1.0e-6));
      acc = acc + omega6p;
      omega7p =
	((+0.533709308944668) / (+2.10745727251578)) / ((sigma1 + 1.0e-6) * (sigma1 + 1.0e-6));
      acc = acc + omega7p;
      omega8p =
	((+0.776703467243817) / (+2.10745727251578)) / ((sigma2 + 1.0e-6) * (sigma2 + 1.0e-6));
      acc = acc + omega8p;
      omega9p =
	((+0.612651560297567) / (+2.10745727251578)) / ((sigma3 + 1.0e-6) * (sigma3 + 1.0e-6));
      acc = acc + omega9p;
      omega10p =
	((+0.141959793178718) / (+2.10745727251578)) / ((sigma4 + 1.0e-6) * (sigma4 + 1.0e-6));
      acc = acc + omega10p;
      omega11p =
	((+0.0066140520124192) / (+2.10745727251578)) / ((sigma5 + 1.0e-6) * (sigma5 + 1.0e-6));
      acc = acc + omega11p;
      omega6p = (omega6p) / (acc);
      omega7p = (omega7p) / (acc);
      omega8p = (omega8p) / (acc);
      omega9p = (omega9p) / (acc);
      omega10p = (omega10p) / (acc);
      omega11p = (omega11p) / (acc);
      acc = 0.0;
      omega6m =
	((+0.0716381816771881) / (+1.10745727251578)) / ((sigma0 + 1.0e-6) * (sigma0 + 1.0e-6));
      acc = acc + omega6m;
      omega7m =
	((+0.266854654472334) / (+1.10745727251578)) / ((sigma1 + 1.0e-6) * (sigma1 + 1.0e-6));
      acc = acc + omega7m;
      omega8m =
	((+0.388351733621908) / (+1.10745727251578)) / ((sigma2 + 1.0e-6) * (sigma2 + 1.0e-6));
      acc = acc + omega8m;
      omega9m =
	((+0.306325780148783) / (+1.10745727251578)) / ((sigma3 + 1.0e-6) * (sigma3 + 1.0e-6));
      acc = acc + omega9m;
      omega10m =
	((+0.070979896589359) / (+1.10745727251578)) / ((sigma4 + 1.0e-6) * (sigma4 + 1.0e-6));
      acc = acc + omega10m;
      omega11m =
	((+0.0033070260062096) / (+1.10745727251578)) / ((sigma5 + 1.0e-6) * (sigma5 + 1.0e-6));
      acc = acc + omega11m;
      omega6m = (omega6m) / (acc);
      omega7m = (omega7m) / (acc);
      omega8m = (omega8m) / (acc);
      omega9m = (omega9m) / (acc);
      omega10m = (omega10m) / (acc);
      omega11m = (omega11m) / (acc);
      acc = 0.0;
      omega12 = (+0.00810211387074406) / ((sigma0 + 1.0e-6) * (sigma0 + 1.0e-6));
      acc = acc + omega12;
      omega13 = (+0.125772408126594) / ((sigma1 + 1.0e-6) * (sigma1 + 1.0e-6));
      acc = acc + omega13;
      omega14 = (+0.403307797143423) / ((sigma2 + 1.0e-6) * (sigma2 + 1.0e-6));
      acc = acc + omega14;
      omega15 = (+0.365634456729938) / ((sigma3 + 1.0e-6) * (sigma3 + 1.0e-6));
      acc = acc + omega15;
      omega16 = (+0.0925321033814905) / ((sigma4 + 1.0e-6) * (sigma4 + 1.0e-6));
      acc = acc + omega16;
      omega17 = (+0.00465112074781078) / ((sigma5 + 1.0e-6) * (sigma5 + 1.0e-6));
      acc = acc + omega17;
      omega12 = (omega12) / (acc);
      omega13 = (omega13) / (acc);
      omega14 = (omega14) / (acc);
      omega15 = (omega15) / (acc);
      omega16 = (omega16) / (acc);
      omega17 = (omega17) / (acc);
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
      omega[i * wsi + 2 * wsl + 0 * wsr + 0] = omega12;
      omega[i * wsi + 2 * wsl + 1 * wsr + 0] = omega13;
      omega[i * wsi + 2 * wsl + 2 * wsr + 0] = omega14;
      omega[i * wsi + 2 * wsl + 3 * wsr + 0] = omega15;
      omega[i * wsi + 2 * wsl + 4 * wsr + 0] = omega16;
      omega[i * wsi + 2 * wsl + 5 * wsr + 0] = omega17;
    }
}

PyObject *
py_weights_gauss_radau006003 (PyObject * self, PyObject * args)
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

  weights_gauss_radau006003 (sigma, n, ssi, ssr, omega, wsi, wsl, wsr);

  Py_INCREF (Py_None);
  return Py_None;
}

void
reconstruct_gauss_radau006003 (const double *restrict f, int n, int fsi,
			       const double *restrict omega, int wsi, int wsl, int wsr,
			       double *restrict fr, int frsi, int frsl)
{
  int i;
  double omega6p, omega9m, omega13, omega6m, omega9p, omega3, omega17, omega10p, omega10m, omega14,
    omega8p, omega8m, omega0, omega4, omega5, omega16, omega7m, omega1, omega7p, omega2, omega12,
    omega11m, omega15, omega11p, fs0, fs1, fs2, fr1, fr8, fr16, fr0, fr12, fr14, fr10, fr7, fr11,
    fr9, fr5, fr13, fr17, fr4, fr6, fr15, fr3, fr2;
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
      omega12 = omega[i * wsi + 2 * wsl + 0 * wsr + 0];
      omega13 = omega[i * wsi + 2 * wsl + 1 * wsr + 0];
      omega14 = omega[i * wsi + 2 * wsl + 2 * wsr + 0];
      omega15 = omega[i * wsi + 2 * wsl + 3 * wsr + 0];
      omega16 = omega[i * wsi + 2 * wsl + 4 * wsr + 0];
      omega17 = omega[i * wsi + 2 * wsl + 5 * wsr + 0];
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
	(+1.19314348740629) * (f[(i + 0) * fsi]) + (-0.238566719203405) * (f[(i + 1) * fsi]) +
	(+0.0280874055720997) * (f[(i + 2) * fsi]) + (+0.0368120445991384) * (f[(i + 3) * fsi]) +
	(-0.024387891854098) * (f[(i + 4) * fsi]) + (+0.00491167347997348) * (f[(i + 5) * fsi]);
      fr7 =
	(-0.00491167347997348) * (f[(i - 1) * fsi]) + (+1.22261352828613) * (f[(i + 0) * fsi]) +
	(-0.312241821403008) * (f[(i + 1) * fsi]) + (+0.126320875171568) * (f[(i + 2) * fsi]) +
	(-0.0368630576004633) * (f[(i + 3) * fsi]) + (+0.0050821490257427) * (f[(i + 4) * fsi]);
      fr8 =
	(-0.0050821490257427) * (f[(i - 2) * fsi]) + (+0.0255812206744828) * (f[(i - 1) * fsi]) +
	(+1.14638129289999) * (f[(i + 0) * fsi]) + (-0.210598840888154) * (f[(i + 1) * fsi]) +
	(+0.0500886397854271) * (f[(i + 2) * fsi]) + (-0.00637016344600709) * (f[(i + 3) * fsi]);
      fr9 =
	(+0.00637016344600709) * (f[(i - 3) * fsi]) + (-0.0433031297017852) * (f[(i - 2) * fsi]) +
	(+0.121133672364589) * (f[(i - 1) * fsi]) + (+1.01897802397985) * (f[(i + 0) * fsi]) +
	(-0.115046389198047) * (f[(i + 1) * fsi]) + (+0.0118676591093846) * (f[(i + 2) * fsi]);
      fr10 =
	(-0.0118676591093846) * (f[(i - 4) * fsi]) + (+0.0775761181023145) * (f[(i - 3) * fsi]) +
	(-0.221318016342554) * (f[(i - 2) * fsi]) + (+0.35848685455228) * (f[(i - 1) * fsi]) +
	(+0.840963137339083) * (f[(i + 0) * fsi]) + (-0.0438404345417397) * (f[(i + 1) * fsi]);
      fr11 =
	(+0.0438404345417397) * (f[(i - 5) * fsi]) + (-0.274910266359823) * (f[(i - 4) * fsi]) +
	(+0.73518263622841) * (f[(i - 3) * fsi]) + (-1.09812670717735) * (f[(i - 2) * fsi]) +
	(+1.01609337267838) * (f[(i - 1) * fsi]) + (+0.577920530088645) * (f[(i + 0) * fsi]);
      fr12 =
	(+0.309037179260374) * (f[(i + 0) * fsi]) + (+1.37256338587007) * (f[(i + 1) * fsi]) +
	(-1.20388073890543) * (f[(i + 2) * fsi]) + (+0.751447955400861) * (f[(i + 3) * fsi]) +
	(-0.271642108145902) * (f[(i + 4) * fsi]) + (+0.0424743265200265) * (f[(i + 5) * fsi]);
      fr13 =
	(-0.0424743265200265) * (f[(i - 1) * fsi]) + (+0.563883138380533) * (f[(i + 0) * fsi]) +
	(+0.735448488069674) * (f[(i + 1) * fsi]) + (-0.354394208504901) * (f[(i + 2) * fsi]) +
	(+0.114333057600463) * (f[(i + 3) * fsi]) + (-0.0167961490257427) * (f[(i + 4) * fsi]);
      fr14 =
	(+0.0167961490257427) * (f[(i - 2) * fsi]) + (-0.143251220674483) * (f[(i - 1) * fsi]) +
	(+0.815825373766673) * (f[(i + 0) * fsi]) + (+0.39952550755482) * (f[(i + 1) * fsi]) +
	(-0.10245197311876) * (f[(i + 2) * fsi]) + (+0.0135561634460071) * (f[(i + 3) * fsi]);
      fr15 =
	(-0.0135561634460071) * (f[(i - 3) * fsi]) + (+0.0981331297017853) * (f[(i - 2) * fsi]) +
	(-0.346593672364589) * (f[(i - 1) * fsi]) + (+1.08694864268682) * (f[(i + 0) * fsi]) +
	(+0.196183055864714) * (f[(i + 1) * fsi]) + (-0.0211149924427179) * (f[(i + 2) * fsi]);
      fr16 =
	(+0.0211149924427179) * (f[(i - 4) * fsi]) + (-0.140246118102315) * (f[(i - 3) * fsi]) +
	(+0.414858016342554) * (f[(i - 2) * fsi]) + (-0.768893521218947) * (f[(i - 1) * fsi]) +
	(+1.40367352932758) * (f[(i + 0) * fsi]) + (+0.0694931012084064) * (f[(i + 1) * fsi]);
      fr17 =
	(-0.0694931012084064) * (f[(i - 5) * fsi]) + (+0.438073599693156) * (f[(i - 4) * fsi]) +
	(-1.18264263622841) * (f[(i - 3) * fsi]) + (+1.80472004051068) * (f[(i - 2) * fsi]) +
	(-1.81129003934504) * (f[(i - 1) * fsi]) + (+1.82063213657802) * (f[(i + 0) * fsi]);
      fs0 =
	(omega0) * (fr0) + (omega1) * (fr1) + (omega2) * (fr2) + (omega3) * (fr3) +
	(omega4) * (fr4) + (omega5) * (fr5);
      fs1 =
	((+2.10745727251578) *
	 ((omega6p) * (fr6) + (omega7p) * (fr7) + (omega8p) * (fr8) + (omega9p) * (fr9) +
	  (omega10p) * (fr10) + (omega11p) * (fr11))) - ((+1.10745727251578) * ((omega6m) * (fr6) +
										(omega7m) * (fr7) +
										(omega8m) * (fr8) +
										(omega9m) * (fr9) +
										(omega10m) *
										(fr10) +
										(omega11m) *
										(fr11)));
      fs2 =
	(omega12) * (fr12) + (omega13) * (fr13) + (omega14) * (fr14) + (omega15) * (fr15) +
	(omega16) * (fr16) + (omega17) * (fr17);
      fr[i * frsi + 0 * frsl] = fs0;
      fr[i * frsi + 1 * frsl] = fs1;
      fr[i * frsi + 2 * frsl] = fs2;
    }
}

PyObject *
py_reconstruct_gauss_radau006003 (PyObject * self, PyObject * args)
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

  reconstruct_gauss_radau006003 (f, n, fsi, omega, wsi, wsl, wsr, fr, frsi, frsl);

  Py_INCREF (Py_None);
  return Py_None;
}
