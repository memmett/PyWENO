#include <Python.h>
#include <numpy/ndarrayobject.h>

void
weights_gauss_legendre006004 (const double *restrict sigma, int n, int ssi, int ssr,
			      double *restrict omega, int wsi, int wsl, int wsr)
{
  int i;
  double acc, sigma0, sigma1, sigma2, sigma3, sigma4, sigma5, omega9, omega18, omega13, omega17,
    omega3, omega8, omega21, omega11, omega14, omega7, omega20, omega0, omega4, omega10, omega5,
    omega6, omega23, omega1, omega19, omega2, omega12, omega15, omega22, omega16;
  for (i = 6; i < n - 6; i++)
    {
      sigma0 = sigma[i * ssi + 0 * ssr];
      sigma1 = sigma[i * ssi + 1 * ssr];
      sigma2 = sigma[i * ssi + 2 * ssr];
      sigma3 = sigma[i * ssi + 3 * ssr];
      sigma4 = sigma[i * ssi + 4 * ssr];
      sigma5 = sigma[i * ssi + 5 * ssr];
      acc = 0.0;
      omega0 = (+0.00298799392469506) / ((sigma0 + 1.0e-6) * (sigma0 + 1.0e-6));
      acc = acc + omega0;
      omega1 = (+0.0758230666028258) / ((sigma1 + 1.0e-6) * (sigma1 + 1.0e-6));
      acc = acc + omega1;
      omega2 = (+0.343207690238713) / ((sigma2 + 1.0e-6) * (sigma2 + 1.0e-6));
      acc = acc + omega2;
      omega3 = (+0.421599415177439) / ((sigma3 + 1.0e-6) * (sigma3 + 1.0e-6));
      acc = acc + omega3;
      omega4 = (+0.145789927466551) / ((sigma4 + 1.0e-6) * (sigma4 + 1.0e-6));
      acc = acc + omega4;
      omega5 = (+0.0105919065897758) / ((sigma5 + 1.0e-6) * (sigma5 + 1.0e-6));
      acc = acc + omega5;
      omega0 = (omega0) / (acc);
      omega1 = (omega1) / (acc);
      omega2 = (omega2) / (acc);
      omega3 = (omega3) / (acc);
      omega4 = (omega4) / (acc);
      omega5 = (omega5) / (acc);
      acc = 0.0;
      omega6 = (+0.109331592289754) / ((sigma0 + 1.0e-6) * (sigma0 + 1.0e-6));
      acc = acc + omega6;
      omega7 = (+0.0796026727722269) / ((sigma1 + 1.0e-6) * (sigma1 + 1.0e-6));
      acc = acc + omega7;
      omega8 = (+0.398701356360849) / ((sigma2 + 1.0e-6) * (sigma2 + 1.0e-6));
      acc = acc + omega8;
      omega9 = (+0.328908303175577) / ((sigma3 + 1.0e-6) * (sigma3 + 1.0e-6));
      acc = acc + omega9;
      omega10 = (+0.0795755314662704) / ((sigma4 + 1.0e-6) * (sigma4 + 1.0e-6));
      acc = acc + omega10;
      omega11 = (+0.00388054393532226) / ((sigma5 + 1.0e-6) * (sigma5 + 1.0e-6));
      acc = acc + omega11;
      omega6 = (omega6) / (acc);
      omega7 = (omega7) / (acc);
      omega8 = (omega8) / (acc);
      omega9 = (omega9) / (acc);
      omega10 = (omega10) / (acc);
      omega11 = (omega11) / (acc);
      acc = 0.0;
      omega12 = (+0.00388054393533242) / ((sigma0 + 1.0e-6) * (sigma0 + 1.0e-6));
      acc = acc + omega12;
      omega13 = (+0.0795755314662532) / ((sigma1 + 1.0e-6) * (sigma1 + 1.0e-6));
      acc = acc + omega13;
      omega14 = (+0.328908303175589) / ((sigma2 + 1.0e-6) * (sigma2 + 1.0e-6));
      acc = acc + omega14;
      omega15 = (+0.398701356360848) / ((sigma3 + 1.0e-6) * (sigma3 + 1.0e-6));
      acc = acc + omega15;
      omega16 = (+0.0796026727722381) / ((sigma4 + 1.0e-6) * (sigma4 + 1.0e-6));
      acc = acc + omega16;
      omega17 = (+0.109331592289742) / ((sigma5 + 1.0e-6) * (sigma5 + 1.0e-6));
      acc = acc + omega17;
      omega12 = (omega12) / (acc);
      omega13 = (omega13) / (acc);
      omega14 = (omega14) / (acc);
      omega15 = (omega15) / (acc);
      omega16 = (omega16) / (acc);
      omega17 = (omega17) / (acc);
      acc = 0.0;
      omega18 = (+0.0105919065897816) / ((sigma0 + 1.0e-6) * (sigma0 + 1.0e-6));
      acc = acc + omega18;
      omega19 = (+0.145789927466543) / ((sigma1 + 1.0e-6) * (sigma1 + 1.0e-6));
      acc = acc + omega19;
      omega20 = (+0.421599415177444) / ((sigma2 + 1.0e-6) * (sigma2 + 1.0e-6));
      acc = acc + omega20;
      omega21 = (+0.343207690238711) / ((sigma3 + 1.0e-6) * (sigma3 + 1.0e-6));
      acc = acc + omega21;
      omega22 = (+0.0758230666028287) / ((sigma4 + 1.0e-6) * (sigma4 + 1.0e-6));
      acc = acc + omega22;
      omega23 = (+0.00298799392469376) / ((sigma5 + 1.0e-6) * (sigma5 + 1.0e-6));
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
      omega[i * wsi + 2 * wsl + 0 * wsr + 0] = omega12;
      omega[i * wsi + 2 * wsl + 1 * wsr + 0] = omega13;
      omega[i * wsi + 2 * wsl + 2 * wsr + 0] = omega14;
      omega[i * wsi + 2 * wsl + 3 * wsr + 0] = omega15;
      omega[i * wsi + 2 * wsl + 4 * wsr + 0] = omega16;
      omega[i * wsi + 2 * wsl + 5 * wsr + 0] = omega17;
      omega[i * wsi + 3 * wsl + 0 * wsr + 0] = omega18;
      omega[i * wsi + 3 * wsl + 1 * wsr + 0] = omega19;
      omega[i * wsi + 3 * wsl + 2 * wsr + 0] = omega20;
      omega[i * wsi + 3 * wsl + 3 * wsr + 0] = omega21;
      omega[i * wsi + 3 * wsl + 4 * wsr + 0] = omega22;
      omega[i * wsi + 3 * wsl + 5 * wsr + 0] = omega23;
    }
}

PyObject *
py_weights_gauss_legendre006004 (PyObject * self, PyObject * args)
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

  weights_gauss_legendre006004 (sigma, n, ssi, ssr, omega, wsi, wsl, wsr);

  Py_INCREF (Py_None);
  return Py_None;
}

void
reconstruct_gauss_legendre006004 (const double *restrict f, int n, int fsi,
				  const double *restrict omega, int wsi, int wsl, int wsr,
				  double *restrict fr, int frsi, int frsl)
{
  int i;
  double omega9, omega18, omega13, omega17, omega3, omega8, omega21, omega11, omega14, omega7,
    omega20, omega0, omega4, omega10, omega5, omega6, omega23, omega1, omega19, omega2, omega12,
    omega15, omega22, omega16, fs0, fs1, fs2, fs3, fr9, fr18, fr13, fr17, fr3, fr8, fr21, fr11,
    fr14, fr7, fr20, fr0, fr4, fr10, fr5, fr6, fr23, fr1, fr19, fr2, fr12, fr15, fr22, fr16;
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
      omega18 = omega[i * wsi + 3 * wsl + 0 * wsr + 0];
      omega19 = omega[i * wsi + 3 * wsl + 1 * wsr + 0];
      omega20 = omega[i * wsi + 3 * wsl + 2 * wsr + 0];
      omega21 = omega[i * wsi + 3 * wsl + 3 * wsr + 0];
      omega22 = omega[i * wsi + 3 * wsl + 4 * wsr + 0];
      omega23 = omega[i * wsi + 3 * wsl + 5 * wsr + 0];
      fr0 =
	(+2.15122683558506) * (f[(i + 0) * fsi]) + (-2.7088503210327) * (f[(i + 1) * fsi]) +
	(+2.89539144454114) * (f[(i + 2) * fsi]) + (-1.95675626046466) * (f[(i + 3) * fsi]) +
	(+0.737173449308413) * (f[(i + 4) * fsi]) + (-0.118185147937257) * (f[(i + 5) * fsi]);
      fr1 =
	(+0.118185147937257) * (f[(i - 1) * fsi]) + (+1.44211594796152) * (f[(i + 0) * fsi]) +
	(-0.936073101973846) * (f[(i + 1) * fsi]) + (+0.531688485796003) * (f[(i + 2) * fsi]) +
	(-0.183979041405804) * (f[(i + 3) * fsi]) + (+0.0280625616848707) * (f[(i + 4) * fsi]);
      fr2 =
	(-0.0280625616848707) * (f[(i - 2) * fsi]) + (+0.286560518046481) * (f[(i - 1) * fsi]) +
	(+1.02117752268846) * (f[(i + 0) * fsi]) + (-0.374821868276432) * (f[(i + 1) * fsi]) +
	(+0.110750060522942) * (f[(i + 2) * fsi]) + (-0.0156036712965795) * (f[(i + 3) * fsi]);
      fr3 =
	(+0.0156036712965795) * (f[(i - 3) * fsi]) + (-0.121684589464348) * (f[(i - 2) * fsi]) +
	(+0.520615587495173) * (f[(i - 1) * fsi]) + (+0.709104096756869) * (f[(i + 0) * fsi]) +
	(-0.14076679882774) * (f[(i + 1) * fsi]) + (+0.0171280327434651) * (f[(i + 2) * fsi]);
      fr4 =
	(-0.0171280327434651) * (f[(i - 4) * fsi]) + (+0.11837186775737) * (f[(i - 3) * fsi]) +
	(-0.378605080616324) * (f[(i - 2) * fsi]) + (+0.863176242364475) * (f[(i - 1) * fsi]) +
	(+0.452183605604893) * (f[(i + 0) * fsi]) + (-0.0379986023669492) * (f[(i + 1) * fsi]);
      fr5 =
	(+0.0379986023669492) * (f[(i - 5) * fsi]) + (-0.24511964694516) * (f[(i - 4) * fsi]) +
	(+0.688350903261608) * (f[(i - 3) * fsi]) + (-1.13857712795531) * (f[(i - 2) * fsi]) +
	(+1.43315527786871) * (f[(i - 1) * fsi]) + (+0.224191991403198) * (f[(i + 0) * fsi]);
      fr6 =
	(+1.2615712729022) * (f[(i + 0) * fsi]) + (-0.399402120210929) * (f[(i + 1) * fsi]) +
	(+0.198350818833811) * (f[(i + 2) * fsi]) + (-0.0766133941089375) * (f[(i + 3) * fsi]) +
	(+0.0179169698416002) * (f[(i + 4) * fsi]) + (-0.0018235472577422) * (f[(i + 5) * fsi]);
      fr7 =
	(+0.00182354725774224) * (f[(i - 1) * fsi]) + (+1.25062998935574) * (f[(i + 0) * fsi]) +
	(-0.372048911344796) * (f[(i + 1) * fsi]) + (+0.161879873678967) * (f[(i + 2) * fsi]) +
	(-0.0492601852428037) * (f[(i + 3) * fsi]) + (+0.00697568629514672) * (f[(i + 4) * fsi]);
      fr8 =
	(-0.00697568629514671) * (f[(i - 2) * fsi]) + (+0.0436776650286225) * (f[(i - 1) * fsi]) +
	(+1.14599469492854) * (f[(i + 0) * fsi]) + (-0.232535185441861) * (f[(i + 1) * fsi]) +
	(+0.0572445792517663) * (f[(i + 2) * fsi]) + (-0.00740606747192341) * (f[(i + 3) * fsi]);
      fr9 =
	(+0.00740606747192341) * (f[(i - 3) * fsi]) + (-0.0514120911266872) * (f[(i - 2) * fsi]) +
	(+0.154768677107474) * (f[(i - 1) * fsi]) + (+0.997873345490075) * (f[(i + 0) * fsi]) +
	(-0.12144417336301) * (f[(i + 1) * fsi]) + (+0.0128081744202258) * (f[(i + 2) * fsi]);
      fr10 =
	(-0.0128081744202258) * (f[(i - 4) * fsi]) + (+0.0842551139932781) * (f[(i - 3) * fsi]) +
	(-0.243534707430074) * (f[(i - 2) * fsi]) + (+0.410932165511989) * (f[(i - 1) * fsi]) +
	(+0.805750729186688) * (f[(i + 0) * fsi]) + (-0.0445951268416554) * (f[(i + 1) * fsi]);
      fr11 =
	(+0.0445951268416554) * (f[(i - 5) * fsi]) + (-0.280378935470158) * (f[(i - 4) * fsi]) +
	(+0.75318201661811) * (f[(i - 3) * fsi]) + (-1.13543724426318) * (f[(i - 2) * fsi]) +
	(+1.07985906813682) * (f[(i - 1) * fsi]) + (+0.538179968136755) * (f[(i + 0) * fsi]);
      fr12 =
	(+0.538179968136755) * (f[(i + 0) * fsi]) + (+1.07985906813682) * (f[(i + 1) * fsi]) +
	(-1.13543724426318) * (f[(i + 2) * fsi]) + (+0.753182016618109) * (f[(i + 3) * fsi]) +
	(-0.280378935470159) * (f[(i + 4) * fsi]) + (+0.0445951268416554) * (f[(i + 5) * fsi]);
      fr13 =
	(-0.0445951268416553) * (f[(i - 1) * fsi]) + (+0.805750729186687) * (f[(i + 0) * fsi]) +
	(+0.41093216551199) * (f[(i + 1) * fsi]) + (-0.243534707430074) * (f[(i + 2) * fsi]) +
	(+0.0842551139932781) * (f[(i + 3) * fsi]) + (-0.0128081744202258) * (f[(i + 4) * fsi]);
      fr14 =
	(+0.0128081744202258) * (f[(i - 2) * fsi]) + (-0.12144417336301) * (f[(i - 1) * fsi]) +
	(+0.997873345490074) * (f[(i + 0) * fsi]) + (+0.154768677107474) * (f[(i + 1) * fsi]) +
	(-0.0514120911266872) * (f[(i + 2) * fsi]) + (+0.00740606747192341) * (f[(i + 3) * fsi]);
      fr15 =
	(-0.00740606747192341) * (f[(i - 3) * fsi]) + (+0.0572445792517663) * (f[(i - 2) * fsi]) +
	(-0.232535185441861) * (f[(i - 1) * fsi]) + (+1.14599469492854) * (f[(i + 0) * fsi]) +
	(+0.0436776650286225) * (f[(i + 1) * fsi]) + (-0.00697568629514671) * (f[(i + 2) * fsi]);
      fr16 =
	(+0.00697568629514671) * (f[(i - 4) * fsi]) + (-0.0492601852428037) * (f[(i - 3) * fsi]) +
	(+0.161879873678967) * (f[(i - 2) * fsi]) + (-0.372048911344796) * (f[(i - 1) * fsi]) +
	(+1.25062998935574) * (f[(i + 0) * fsi]) + (+0.00182354725774224) * (f[(i + 1) * fsi]);
      fr17 =
	(-0.00182354725774224) * (f[(i - 5) * fsi]) + (+0.0179169698416001) * (f[(i - 4) * fsi]) +
	(-0.0766133941089373) * (f[(i - 3) * fsi]) + (+0.198350818833812) * (f[(i - 2) * fsi]) +
	(-0.399402120210929) * (f[(i - 1) * fsi]) + (+1.2615712729022) * (f[(i + 0) * fsi]);
      fr18 =
	(+0.224191991403198) * (f[(i + 0) * fsi]) + (+1.43315527786871) * (f[(i + 1) * fsi]) +
	(-1.1385771279553) * (f[(i + 2) * fsi]) + (+0.688350903261608) * (f[(i + 3) * fsi]) +
	(-0.245119646945161) * (f[(i + 4) * fsi]) + (+0.0379986023669491) * (f[(i + 5) * fsi]);
      fr19 =
	(-0.0379986023669491) * (f[(i - 1) * fsi]) + (+0.452183605604893) * (f[(i + 0) * fsi]) +
	(+0.863176242364476) * (f[(i + 1) * fsi]) + (-0.378605080616324) * (f[(i + 2) * fsi]) +
	(+0.11837186775737) * (f[(i + 3) * fsi]) + (-0.0171280327434651) * (f[(i + 4) * fsi]);
      fr20 =
	(+0.0171280327434651) * (f[(i - 2) * fsi]) + (-0.14076679882774) * (f[(i - 1) * fsi]) +
	(+0.709104096756869) * (f[(i + 0) * fsi]) + (+0.520615587495173) * (f[(i + 1) * fsi]) +
	(-0.121684589464348) * (f[(i + 2) * fsi]) + (+0.0156036712965795) * (f[(i + 3) * fsi]);
      fr21 =
	(-0.0156036712965795) * (f[(i - 3) * fsi]) + (+0.110750060522942) * (f[(i - 2) * fsi]) +
	(-0.374821868276432) * (f[(i - 1) * fsi]) + (+1.02117752268846) * (f[(i + 0) * fsi]) +
	(+0.286560518046481) * (f[(i + 1) * fsi]) + (-0.0280625616848707) * (f[(i + 2) * fsi]);
      fr22 =
	(+0.0280625616848707) * (f[(i - 4) * fsi]) + (-0.183979041405804) * (f[(i - 3) * fsi]) +
	(+0.531688485796002) * (f[(i - 2) * fsi]) + (-0.936073101973846) * (f[(i - 1) * fsi]) +
	(+1.44211594796152) * (f[(i + 0) * fsi]) + (+0.118185147937257) * (f[(i + 1) * fsi]);
      fr23 =
	(-0.118185147937257) * (f[(i - 5) * fsi]) + (+0.737173449308412) * (f[(i - 4) * fsi]) +
	(-1.95675626046466) * (f[(i - 3) * fsi]) + (+2.89539144454114) * (f[(i - 2) * fsi]) +
	(-2.7088503210327) * (f[(i - 1) * fsi]) + (+2.15122683558506) * (f[(i + 0) * fsi]);
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
	(omega18) * (fr18) + (omega19) * (fr19) + (omega20) * (fr20) + (omega21) * (fr21) +
	(omega22) * (fr22) + (omega23) * (fr23);
      fr[i * frsi + 0 * frsl] = fs0;
      fr[i * frsi + 1 * frsl] = fs1;
      fr[i * frsi + 2 * frsl] = fs2;
      fr[i * frsi + 3 * frsl] = fs3;
    }
}

PyObject *
py_reconstruct_gauss_legendre006004 (PyObject * self, PyObject * args)
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

  reconstruct_gauss_legendre006004 (f, n, fsi, omega, wsi, wsl, wsr, fr, frsi, frsl);

  Py_INCREF (Py_None);
  return Py_None;
}
