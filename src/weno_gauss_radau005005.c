#include <Python.h>
#include <numpy/ndarrayobject.h>

void
weights_gauss_radau005005 (const double *restrict sigma, int n, int ssi, int ssr,
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
      omega5 = (+0.014602515121165) / ((sigma0 + 1.0e-6) * (sigma0 + 1.0e-6));
      acc = acc + omega5;
      omega6 = (+0.202575019956104) / ((sigma1 + 1.0e-6) * (sigma1 + 1.0e-6));
      acc = acc + omega6;
      omega7 = (+0.487279336481131) / ((sigma2 + 1.0e-6) * (sigma2 + 1.0e-6));
      acc = acc + omega7;
      omega8 = (+0.26836150551925) / ((sigma3 + 1.0e-6) * (sigma3 + 1.0e-6));
      acc = acc + omega8;
      omega9 = (+0.0271816229223495) / ((sigma4 + 1.0e-6) * (sigma4 + 1.0e-6));
      acc = acc + omega9;
      omega5 = (omega5) / (acc);
      omega6 = (omega6) / (acc);
      omega7 = (omega7) / (acc);
      omega8 = (omega8) / (acc);
      omega9 = (omega9) / (acc);
      acc = 0.0;
      omega10p =
	((+0.0288343698463551) / (+2.08650310953906)) / ((sigma0 + 1.0e-6) * (sigma0 + 1.0e-6));
      acc = acc + omega10p;
      omega11p =
	((+1.52478262785997) / (+2.08650310953906)) / ((sigma1 + 1.0e-6) * (sigma1 + 1.0e-6));
      acc = acc + omega11p;
      omega12p =
	((+0.327174165977155) / (+2.08650310953906)) / ((sigma2 + 1.0e-6) * (sigma2 + 1.0e-6));
      acc = acc + omega12p;
      omega13p =
	((+0.193338644843033) / (+2.08650310953906)) / ((sigma3 + 1.0e-6) * (sigma3 + 1.0e-6));
      acc = acc + omega13p;
      omega14p =
	((+0.0123733010125489) / (+2.08650310953906)) / ((sigma4 + 1.0e-6) * (sigma4 + 1.0e-6));
      acc = acc + omega14p;
      omega10p = (omega10p) / (acc);
      omega11p = (omega11p) / (acc);
      omega12p = (omega12p) / (acc);
      omega13p = (omega13p) / (acc);
      omega14p = (omega14p) / (acc);
      acc = 0.0;
      omega10m =
	((+0.0576687396927101) / (+1.08650310953906)) / ((sigma0 + 1.0e-6) * (sigma0 + 1.0e-6));
      acc = acc + omega10m;
      omega11m =
	((+0.762391313929986) / (+1.08650310953906)) / ((sigma1 + 1.0e-6) * (sigma1 + 1.0e-6));
      acc = acc + omega11m;
      omega12m =
	((+0.163587082988578) / (+1.08650310953906)) / ((sigma2 + 1.0e-6) * (sigma2 + 1.0e-6));
      acc = acc + omega12m;
      omega13m =
	((+0.0966693224215167) / (+1.08650310953906)) / ((sigma3 + 1.0e-6) * (sigma3 + 1.0e-6));
      acc = acc + omega13m;
      omega14m =
	((+0.00618665050627443) / (+1.08650310953906)) / ((sigma4 + 1.0e-6) * (sigma4 + 1.0e-6));
      acc = acc + omega14m;
      omega10m = (omega10m) / (acc);
      omega11m = (omega11m) / (acc);
      omega12m = (omega12m) / (acc);
      omega13m = (omega13m) / (acc);
      omega14m = (omega14m) / (acc);
      acc = 0.0;
      omega15 = (+0.0169162987051478) / ((sigma0 + 1.0e-6) * (sigma0 + 1.0e-6));
      acc = acc + omega15;
      omega16 = (+0.209805296138077) / ((sigma1 + 1.0e-6) * (sigma1 + 1.0e-6));
      acc = acc + omega16;
      omega17 = (+0.474964329954543) / ((sigma2 + 1.0e-6) * (sigma2 + 1.0e-6));
      acc = acc + omega17;
      omega18 = (+0.261418699407436) / ((sigma3 + 1.0e-6) * (sigma3 + 1.0e-6));
      acc = acc + omega18;
      omega19 = (+0.0368953757947936) / ((sigma4 + 1.0e-6) * (sigma4 + 1.0e-6));
      acc = acc + omega19;
      omega15 = (omega15) / (acc);
      omega16 = (omega16) / (acc);
      omega17 = (omega17) / (acc);
      omega18 = (omega18) / (acc);
      omega19 = (omega19) / (acc);
      acc = 0.0;
      omega20 = (+0.0341984191200382) / ((sigma0 + 1.0e-6) * (sigma0 + 1.0e-6));
      acc = acc + omega20;
      omega21 = (+0.297936106971335) / ((sigma1 + 1.0e-6) * (sigma1 + 1.0e-6));
      acc = acc + omega21;
      omega22 = (+0.482401240286302) / ((sigma2 + 1.0e-6) * (sigma2 + 1.0e-6));
      acc = acc + omega22;
      omega23 = (+0.175379265507553) / ((sigma3 + 1.0e-6) * (sigma3 + 1.0e-6));
      acc = acc + omega23;
      omega24 = (+0.010084968114772) / ((sigma4 + 1.0e-6) * (sigma4 + 1.0e-6));
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
py_weights_gauss_radau005005 (PyObject * self, PyObject * args)
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

  weights_gauss_radau005005 (sigma, n, ssi, ssr, omega, wsi, wsl, wsr);

  Py_INCREF (Py_None);
  return Py_None;
}

void
reconstruct_gauss_radau005005 (const double *restrict f, int n, int fsi,
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
	(+1.79939202887952) * (f[(i + 0) * fsi]) + (-1.57408652914781) * (f[(i + 1) * fsi]) +
	(+1.20996769996526) * (f[(i + 2) * fsi]) + (-0.535003792348915) * (f[(i + 3) * fsi]) +
	(+0.099730592651956) * (f[(i + 4) * fsi]);
      fr6 =
	(+0.0997305926519559) * (f[(i - 1) * fsi]) + (+1.30073906561974) * (f[(i + 0) * fsi]) +
	(-0.576780602628255) * (f[(i + 1) * fsi]) + (+0.212661773445699) * (f[(i + 2) * fsi]) +
	(-0.0363508290891354) * (f[(i + 3) * fsi]);
      fr7 =
	(-0.0363508290891354) * (f[(i - 2) * fsi]) + (+0.281484738097633) * (f[(i - 1) * fsi]) +
	(+0.937230774728382) * (f[(i + 0) * fsi]) + (-0.213272311736902) * (f[(i + 1) * fsi]) +
	(+0.0309076280000221) * (f[(i + 2) * fsi]);
      fr8 =
	(+0.0309076280000221) * (f[(i - 3) * fsi]) + (-0.190888969089246) * (f[(i - 2) * fsi]) +
	(+0.590561018097854) * (f[(i - 1) * fsi]) + (+0.628154494728161) * (f[(i + 0) * fsi]) +
	(-0.0587341717367912) * (f[(i + 1) * fsi]);
      fr9 =
	(-0.0587341717367912) * (f[(i - 4) * fsi]) + (+0.324578486683978) * (f[(i - 3) * fsi]) +
	(-0.778230686457158) * (f[(i - 2) * fsi]) + (+1.17790273546577) * (f[(i - 1) * fsi]) +
	(+0.334483636044205) * (f[(i + 0) * fsi]);
      fr10 =
	(+1.05541662744665) * (f[(i + 0) * fsi]) + (+0.0226541491180496) * (f[(i + 1) * fsi]) +
	(-0.146068685217669) * (f[(i + 2) * fsi]) + (+0.0860988456635242) * (f[(i + 3) * fsi]) +
	(-0.0181009370105501) * (f[(i + 4) * fsi]);
      fr11 =
	(-0.01810093701055) * (f[(i - 1) * fsi]) + (+1.1459213124994) * (f[(i + 0) * fsi]) +
	(-0.158355220987451) * (f[(i + 1) * fsi]) + (+0.0349406848878313) * (f[(i + 2) * fsi]) +
	(-0.0044058393892261) * (f[(i + 3) * fsi]);
      fr12 =
	(-0.0044058393892261) * (f[(i - 2) * fsi]) + (+0.00392825993558042) * (f[(i - 1) * fsi]) +
	(+1.10186291860714) * (f[(i + 0) * fsi]) + (-0.11429682709519) * (f[(i + 1) * fsi]) +
	(+0.0129114879417008) * (f[(i + 2) * fsi]);
      fr13 =
	(+0.0129114879417008) * (f[(i - 3) * fsi]) + (-0.0689632790977303) * (f[(i - 2) * fsi]) +
	(+0.133043139352589) * (f[(i - 1) * fsi]) + (+0.972748039190127) * (f[(i + 0) * fsi]) +
	(-0.0497393873866861) * (f[(i + 1) * fsi]);
      fr14 =
	(-0.0497393873866861) * (f[(i - 4) * fsi]) + (+0.261608424875131) * (f[(i - 3) * fsi]) +
	(-0.566357152964591) * (f[(i - 2) * fsi]) + (+0.63043701321945) * (f[(i - 1) * fsi]) +
	(+0.724051102256696) * (f[(i + 0) * fsi]);
      fr15 =
	(+0.505081664728717) * (f[(i + 0) * fsi]) + (+0.969804334822662) * (f[(i + 1) * fsi]) +
	(-0.737719591492459) * (f[(i + 2) * fsi]) + (+0.322542533240192) * (f[(i + 3) * fsi]) +
	(-0.0597089412991107) * (f[(i + 4) * fsi]);
      fr16 =
	(-0.0597089412991108) * (f[(i - 1) * fsi]) + (+0.803626371224271) * (f[(i + 0) * fsi]) +
	(+0.372714921831553) * (f[(i + 1) * fsi]) + (-0.140630178501351) * (f[(i + 2) * fsi]) +
	(+0.0239978267446382) * (f[(i + 3) * fsi]);
      fr17 =
	(+0.0239978267446382) * (f[(i - 2) * fsi]) + (-0.179698075022302) * (f[(i - 1) * fsi]) +
	(+1.04360463867065) * (f[(i + 0) * fsi]) + (+0.132736654385171) * (f[(i + 1) * fsi]) +
	(-0.0206410447781603) * (f[(i + 2) * fsi]);
      fr18 =
	(-0.0206410447781603) * (f[(i - 3) * fsi]) + (+0.12720305063544) * (f[(i - 2) * fsi]) +
	(-0.386108522803905) * (f[(i - 1) * fsi]) + (+1.25001508645226) * (f[(i + 0) * fsi]) +
	(+0.02953143049437) * (f[(i + 1) * fsi]);
      fr19 =
	(+0.02953143049437) * (f[(i - 4) * fsi]) + (-0.16829819725001) * (f[(i - 3) * fsi]) +
	(+0.422517355579139) * (f[(i - 2) * fsi]) + (-0.681422827747604) * (f[(i - 1) * fsi]) +
	(+1.3976722389241) * (f[(i + 0) * fsi]);
      fr20 =
	(+0.250502621368243) * (f[(i + 0) * fsi]) + (+1.25198389978792) * (f[(i + 1) * fsi]) +
	(-0.752691061289402) * (f[(i + 2) * fsi]) + (+0.304524133856576) * (f[(i + 3) * fsi]) +
	(-0.0543195937233419) * (f[(i + 4) * fsi]);
      fr21 =
	(-0.0543195937233418) * (f[(i - 1) * fsi]) + (+0.522100589984952) * (f[(i + 0) * fsi]) +
	(+0.708787962554506) * (f[(i + 1) * fsi]) + (-0.209495124055983) * (f[(i + 2) * fsi]) +
	(+0.0329261652398671) * (f[(i + 3) * fsi]);
      fr22 =
	(+0.0329261652398671) * (f[(i - 2) * fsi]) + (-0.218950419922677) * (f[(i - 1) * fsi]) +
	(+0.851362242383622) * (f[(i + 0) * fsi]) + (+0.379526310155835) * (f[(i + 1) * fsi]) +
	(-0.0448642978566481) * (f[(i + 2) * fsi]);
      fr23 =
	(-0.0448642978566481) * (f[(i - 3) * fsi]) + (+0.257247654523107) * (f[(i - 2) * fsi]) +
	(-0.667593398489158) * (f[(i - 1) * fsi]) + (+1.3000052209501) * (f[(i + 0) * fsi]) +
	(+0.155204820872595) * (f[(i + 1) * fsi]);
      fr24 =
	(+0.155204820872595) * (f[(i - 4) * fsi]) + (-0.820888402219624) * (f[(i - 3) * fsi]) +
	(+1.80929586324906) * (f[(i - 2) * fsi]) + (-2.21964160721511) * (f[(i - 1) * fsi]) +
	(+2.07602932531308) * (f[(i + 0) * fsi]);
      fs0 =
	(omega0) * (fr0) + (omega1) * (fr1) + (omega2) * (fr2) + (omega3) * (fr3) +
	(omega4) * (fr4);
      fs1 =
	(omega5) * (fr5) + (omega6) * (fr6) + (omega7) * (fr7) + (omega8) * (fr8) +
	(omega9) * (fr9);
      fs2 =
	((+2.08650310953906) *
	 ((omega10p) * (fr10) + (omega11p) * (fr11) + (omega12p) * (fr12) + (omega13p) * (fr13) +
	  (omega14p) * (fr14))) - ((+1.08650310953906) * ((omega10m) * (fr10) +
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
py_reconstruct_gauss_radau005005 (PyObject * self, PyObject * args)
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

  reconstruct_gauss_radau005005 (f, n, fsi, omega, wsi, wsl, wsr, fr, frsi, frsl);

  Py_INCREF (Py_None);
  return Py_None;
}
