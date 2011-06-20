#include <Python.h>
#include <numpy/ndarrayobject.h>

void
weights_gauss_legendre006002 (const double *restrict sigma, int n, int ssi, int ssr,
			      double *restrict omega, int wsi, int wsl, int wsr)
{
  int i;
  double acc, sigma0, sigma1, sigma2, sigma3, sigma4, sigma5, omega1, omega8, omega0, omega10,
    omega7, omega11, omega9, omega5, omega4, omega6, omega3, omega2;
  for (i = 6; i < n - 6; i++)
    {
      sigma0 = sigma[i * ssi + 0 * ssr];
      sigma1 = sigma[i * ssi + 1 * ssr];
      sigma2 = sigma[i * ssi + 2 * ssr];
      sigma3 = sigma[i * ssi + 3 * ssr];
      sigma4 = sigma[i * ssi + 4 * ssr];
      sigma5 = sigma[i * ssi + 5 * ssr];
      acc = 0.0;
      omega0 = (+0.00671979357051542) / ((sigma0 + 1.0e-6) * (sigma0 + 1.0e-6));
      acc = acc + omega0;
      omega1 = (+0.106967886313321) / ((sigma1 + 1.0e-6) * (sigma1 + 1.0e-6));
      acc = acc + omega1;
      omega2 = (+0.380069523458872) / ((sigma2 + 1.0e-6) * (sigma2 + 1.0e-6));
      acc = acc + omega2;
      omega3 = (+0.387307933161757) / ((sigma3 + 1.0e-6) * (sigma3 + 1.0e-6));
      acc = acc + omega3;
      omega4 = (+0.112277618798139) / ((sigma4 + 1.0e-6) * (sigma4 + 1.0e-6));
      acc = acc + omega4;
      omega5 = (+0.0066572446973947) / ((sigma5 + 1.0e-6) * (sigma5 + 1.0e-6));
      acc = acc + omega5;
      omega0 = (omega0) / (acc);
      omega1 = (omega1) / (acc);
      omega2 = (omega2) / (acc);
      omega3 = (omega3) / (acc);
      omega4 = (omega4) / (acc);
      omega5 = (omega5) / (acc);
      acc = 0.0;
      omega6 = (+0.006657244697408) / ((sigma0 + 1.0e-6) * (sigma0 + 1.0e-6));
      acc = acc + omega6;
      omega7 = (+0.11227761879812) / ((sigma1 + 1.0e-6) * (sigma1 + 1.0e-6));
      acc = acc + omega7;
      omega8 = (+0.387307933161767) / ((sigma2 + 1.0e-6) * (sigma2 + 1.0e-6));
      acc = acc + omega8;
      omega9 = (+0.380069523458873) / ((sigma3 + 1.0e-6) * (sigma3 + 1.0e-6));
      acc = acc + omega9;
      omega10 = (+0.106967886313321) / ((sigma4 + 1.0e-6) * (sigma4 + 1.0e-6));
      acc = acc + omega10;
      omega11 = (+0.00671979357051419) / ((sigma5 + 1.0e-6) * (sigma5 + 1.0e-6));
      acc = acc + omega11;
      omega6 = (omega6) / (acc);
      omega7 = (omega7) / (acc);
      omega8 = (omega8) / (acc);
      omega9 = (omega9) / (acc);
      omega10 = (omega10) / (acc);
      omega11 = (omega11) / (acc);
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
    }
}

PyObject *
py_weights_gauss_legendre006002 (PyObject * self, PyObject * args)
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

  weights_gauss_legendre006002 (sigma, n, ssi, ssr, omega, wsi, wsl, wsr);

  Py_INCREF (Py_None);
  return Py_None;
}

void
reconstruct_gauss_legendre006002 (const double *restrict f, int n, int fsi,
				  const double *restrict omega, int wsi, int wsl, int wsr,
				  double *restrict fr, int frsi, int frsl)
{
  int i;
  double omega1, omega8, omega0, omega10, omega7, omega11, omega9, omega5, omega4, omega6, omega3,
    omega2, fs0, fs1, fr1, fr8, fr0, fr10, fr7, fr11, fr9, fr5, fr4, fr6, fr3, fr2;
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
      fr0 =
	(+1.62456787833418) * (f[(i + 0) * fsi]) + (-1.29880439758795) * (f[(i + 1) * fsi]) +
	(+1.20280860759726) * (f[(i + 2) * fsi]) + (-0.762240114929259) * (f[(i + 3) * fsi]) +
	(+0.277107740342429) * (f[(i + 4) * fsi]) + (-0.0434397137566648) * (f[(i + 5) * fsi]);
      fr1 =
	(+0.0434397137566648) * (f[(i - 1) * fsi]) + (+1.36392959579419) * (f[(i + 0) * fsi]) +
	(-0.647208691237974) * (f[(i + 1) * fsi]) + (+0.334014332463964) * (f[(i + 2) * fsi]) +
	(-0.110644408579287) * (f[(i + 3) * fsi]) + (+0.0164694578024397) * (f[(i + 4) * fsi]);
      fr2 =
	(-0.0164694578024397) * (f[(i - 2) * fsi]) + (+0.142256460571303) * (f[(i - 1) * fsi]) +
	(+1.1168877287576) * (f[(i + 0) * fsi]) + (-0.31781953518918) * (f[(i + 1) * fsi]) +
	(+0.0869724654273682) * (f[(i + 2) * fsi]) + (-0.0118276617646486) * (f[(i + 3) * fsi]);
      fr3 =
	(+0.0118276617646486) * (f[(i - 3) * fsi]) + (-0.0874354283903312) * (f[(i - 2) * fsi]) +
	(+0.319671387041032) * (f[(i - 1) * fsi]) + (+0.880334493464625) * (f[(i + 0) * fsi]) +
	(-0.140404608719451) * (f[(i + 1) * fsi]) + (+0.0160064948394767) * (f[(i + 2) * fsi]);
      fr4 =
	(-0.0160064948394767) * (f[(i - 4) * fsi]) + (+0.107866630801509) * (f[(i - 3) * fsi]) +
	(-0.327532850982482) * (f[(i - 2) * fsi]) + (+0.639801283830567) * (f[(i - 1) * fsi]) +
	(+0.640237070872474) * (f[(i + 0) * fsi]) + (-0.0443656396825908) * (f[(i + 1) * fsi]);
      fr5 =
	(+0.0443656396825908) * (f[(i - 5) * fsi]) + (-0.282200332935021) * (f[(i - 4) * fsi]) +
	(+0.77335122604037) * (f[(i - 3) * fsi]) + (-1.2148456446343) * (f[(i - 2) * fsi]) +
	(+1.30528587906943) * (f[(i - 1) * fsi]) + (+0.37404323277693) * (f[(i + 0) * fsi]);
      fr6 =
	(+0.37404323277693) * (f[(i + 0) * fsi]) + (+1.30528587906943) * (f[(i + 1) * fsi]) +
	(-1.2148456446343) * (f[(i + 2) * fsi]) + (+0.773351226040369) * (f[(i + 3) * fsi]) +
	(-0.282200332935021) * (f[(i + 4) * fsi]) + (+0.0443656396825908) * (f[(i + 5) * fsi]);
      fr7 =
	(-0.0443656396825908) * (f[(i - 1) * fsi]) + (+0.640237070872474) * (f[(i + 0) * fsi]) +
	(+0.639801283830567) * (f[(i + 1) * fsi]) + (-0.327532850982482) * (f[(i + 2) * fsi]) +
	(+0.107866630801509) * (f[(i + 3) * fsi]) + (-0.0160064948394767) * (f[(i + 4) * fsi]);
      fr8 =
	(+0.0160064948394767) * (f[(i - 2) * fsi]) + (-0.140404608719451) * (f[(i - 1) * fsi]) +
	(+0.880334493464625) * (f[(i + 0) * fsi]) + (+0.319671387041032) * (f[(i + 1) * fsi]) +
	(-0.0874354283903312) * (f[(i + 2) * fsi]) + (+0.0118276617646486) * (f[(i + 3) * fsi]);
      fr9 =
	(-0.0118276617646486) * (f[(i - 3) * fsi]) + (+0.0869724654273683) * (f[(i - 2) * fsi]) +
	(-0.31781953518918) * (f[(i - 1) * fsi]) + (+1.1168877287576) * (f[(i + 0) * fsi]) +
	(+0.142256460571303) * (f[(i + 1) * fsi]) + (-0.0164694578024397) * (f[(i + 2) * fsi]);
      fr10 =
	(+0.0164694578024397) * (f[(i - 4) * fsi]) + (-0.110644408579287) * (f[(i - 3) * fsi]) +
	(+0.334014332463964) * (f[(i - 2) * fsi]) + (-0.647208691237974) * (f[(i - 1) * fsi]) +
	(+1.36392959579419) * (f[(i + 0) * fsi]) + (+0.0434397137566648) * (f[(i + 1) * fsi]);
      fr11 =
	(-0.0434397137566648) * (f[(i - 5) * fsi]) + (+0.277107740342429) * (f[(i - 4) * fsi]) +
	(-0.762240114929259) * (f[(i - 3) * fsi]) + (+1.20280860759726) * (f[(i - 2) * fsi]) +
	(-1.29880439758795) * (f[(i - 1) * fsi]) + (+1.62456787833418) * (f[(i + 0) * fsi]);
      fs0 =
	(omega0) * (fr0) + (omega1) * (fr1) + (omega2) * (fr2) + (omega3) * (fr3) +
	(omega4) * (fr4) + (omega5) * (fr5);
      fs1 =
	(omega6) * (fr6) + (omega7) * (fr7) + (omega8) * (fr8) + (omega9) * (fr9) +
	(omega10) * (fr10) + (omega11) * (fr11);
      fr[i * frsi + 0 * frsl] = fs0;
      fr[i * frsi + 1 * frsl] = fs1;
    }
}

PyObject *
py_reconstruct_gauss_legendre006002 (PyObject * self, PyObject * args)
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

  reconstruct_gauss_legendre006002 (f, n, fsi, omega, wsi, wsl, wsr, fr, frsi, frsl);

  Py_INCREF (Py_None);
  return Py_None;
}
