#include <Python.h>
#include <numpy/ndarrayobject.h>

void
weights_gauss_legendre003003 (const double *restrict sigma, int n, int ssi, int ssr,
			      double *restrict omega, int wsi, int wsl, int wsr)
{
  int i;
  double acc, sigma0, sigma1, sigma2, omega1, omega4p, omega0, omega5m, omega3p, omega7, omega3m,
    omega6, omega5p, omega8, omega4m, omega2;
  for (i = 3; i < n - 3; i++)
    {
      sigma0 = sigma[i * ssi + 0 * ssr];
      sigma1 = sigma[i * ssi + 1 * ssr];
      sigma2 = sigma[i * ssi + 2 * ssr];
      acc = 0.0;
      omega0 = (+0.139888966110548) / ((sigma0 + 1.0e-6) * (sigma0 + 1.0e-6));
      acc = acc + omega0;
      omega1 = (+0.615267175572519) / ((sigma1 + 1.0e-6) * (sigma1 + 1.0e-6));
      acc = acc + omega1;
      omega2 = (+0.244843858316933) / ((sigma2 + 1.0e-6) * (sigma2 + 1.0e-6));
      acc = acc + omega2;
      omega0 = (omega0) / (acc);
      omega1 = (omega1) / (acc);
      omega2 = (omega2) / (acc);
      acc = 0.0;
      omega3p = ((+0.1125) / (+2.675)) / ((sigma0 + 1.0e-6) * (sigma0 + 1.0e-6));
      acc = acc + omega3p;
      omega4p = ((+2.45) / (+2.675)) / ((sigma1 + 1.0e-6) * (sigma1 + 1.0e-6));
      acc = acc + omega4p;
      omega5p = ((+0.1125) / (+2.675)) / ((sigma2 + 1.0e-6) * (sigma2 + 1.0e-6));
      acc = acc + omega5p;
      omega3p = (omega3p) / (acc);
      omega4p = (omega4p) / (acc);
      omega5p = (omega5p) / (acc);
      acc = 0.0;
      omega3m = ((+0.225) / (+1.675)) / ((sigma0 + 1.0e-6) * (sigma0 + 1.0e-6));
      acc = acc + omega3m;
      omega4m = ((+1.225) / (+1.675)) / ((sigma1 + 1.0e-6) * (sigma1 + 1.0e-6));
      acc = acc + omega4m;
      omega5m = ((+0.225) / (+1.675)) / ((sigma2 + 1.0e-6) * (sigma2 + 1.0e-6));
      acc = acc + omega5m;
      omega3m = (omega3m) / (acc);
      omega4m = (omega4m) / (acc);
      omega5m = (omega5m) / (acc);
      acc = 0.0;
      omega6 = (+0.244843858316933) / ((sigma0 + 1.0e-6) * (sigma0 + 1.0e-6));
      acc = acc + omega6;
      omega7 = (+0.615267175572519) / ((sigma1 + 1.0e-6) * (sigma1 + 1.0e-6));
      acc = acc + omega7;
      omega8 = (+0.139888966110548) / ((sigma2 + 1.0e-6) * (sigma2 + 1.0e-6));
      acc = acc + omega8;
      omega6 = (omega6) / (acc);
      omega7 = (omega7) / (acc);
      omega8 = (omega8) / (acc);
      omega[i * wsi + 0 * wsl + 0 * wsr + 0] = omega0;
      omega[i * wsi + 0 * wsl + 1 * wsr + 0] = omega1;
      omega[i * wsi + 0 * wsl + 2 * wsr + 0] = omega2;
      omega[i * wsi + 1 * wsl + 0 * wsr + 0] = omega3p;
      omega[i * wsi + 1 * wsl + 0 * wsr + 1] = omega3m;
      omega[i * wsi + 1 * wsl + 1 * wsr + 0] = omega4p;
      omega[i * wsi + 1 * wsl + 1 * wsr + 1] = omega4m;
      omega[i * wsi + 1 * wsl + 2 * wsr + 0] = omega5p;
      omega[i * wsi + 1 * wsl + 2 * wsr + 1] = omega5m;
      omega[i * wsi + 2 * wsl + 0 * wsr + 0] = omega6;
      omega[i * wsi + 2 * wsl + 1 * wsr + 0] = omega7;
      omega[i * wsi + 2 * wsl + 2 * wsr + 0] = omega8;
    }
}

PyObject *
py_weights_gauss_legendre003003 (PyObject * self, PyObject * args)
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

  weights_gauss_legendre003003 (sigma, n, ssi, ssr, omega, wsi, wsl, wsr);

  Py_INCREF (Py_None);
  return Py_None;
}

void
reconstruct_gauss_legendre003003 (const double *restrict f, int n, int fsi,
				  const double *restrict omega, int wsi, int wsl, int wsr,
				  double *restrict fr, int frsi, int frsl)
{
  int i;
  double omega1, omega4p, omega0, omega5m, omega3p, omega7, omega3m, omega6, omega5p, omega8,
    omega4m, omega2, fs0, fs1, fs2, fr1, fr5, fr0, fr7, fr4, fr6, fr8, fr3, fr2;
  for (i = 3; i < n - 3; i++)
    {
      omega0 = omega[i * wsi + 0 * wsl + 0 * wsr + 0];
      omega1 = omega[i * wsi + 0 * wsl + 1 * wsr + 0];
      omega2 = omega[i * wsi + 0 * wsl + 2 * wsr + 0];
      omega3p = omega[i * wsi + 1 * wsl + 0 * wsr + 0];
      omega3m = omega[i * wsi + 1 * wsl + 0 * wsr + 1];
      omega4p = omega[i * wsi + 1 * wsl + 1 * wsr + 0];
      omega4m = omega[i * wsi + 1 * wsl + 1 * wsr + 1];
      omega5p = omega[i * wsi + 1 * wsl + 2 * wsr + 0];
      omega5m = omega[i * wsi + 1 * wsl + 2 * wsr + 1];
      omega6 = omega[i * wsi + 2 * wsl + 0 * wsr + 0];
      omega7 = omega[i * wsi + 2 * wsl + 1 * wsr + 0];
      omega8 = omega[i * wsi + 2 * wsl + 2 * wsr + 0];
      fr0 =
	(+1.61428083526445) * (f[(i + 0) * fsi]) + (-0.84126333590815) * (f[(i + 1) * fsi]) +
	(+0.226982500643704) * (f[(i + 2) * fsi]);
      fr1 =
	(+0.226982500643704) * (f[(i - 1) * fsi]) + (+0.933333333333333) * (f[(i + 0) * fsi]) +
	(-0.160315833977037) * (f[(i + 1) * fsi]);
      fr2 =
	(-0.160315833977037) * (f[(i - 2) * fsi]) + (+0.707930002574817) * (f[(i - 1) * fsi]) +
	(+0.452385831402221) * (f[(i + 0) * fsi]);
      fr3 =
	(+0.958333333333333) * (f[(i + 0) * fsi]) + (+0.0833333333333333) * (f[(i + 1) * fsi]) +
	(-0.0416666666666667) * (f[(i + 2) * fsi]);
      fr4 =
	(-0.0416666666666667) * (f[(i - 1) * fsi]) + (+1.08333333333333) * (f[(i + 0) * fsi]) +
	(-0.0416666666666667) * (f[(i + 1) * fsi]);
      fr5 =
	(-0.0416666666666667) * (f[(i - 2) * fsi]) + (+0.0833333333333333) * (f[(i - 1) * fsi]) +
	(+0.958333333333333) * (f[(i + 0) * fsi]);
      fr6 =
	(+0.452385831402221) * (f[(i + 0) * fsi]) + (+0.707930002574817) * (f[(i + 1) * fsi]) +
	(-0.160315833977038) * (f[(i + 2) * fsi]);
      fr7 =
	(-0.160315833977038) * (f[(i - 1) * fsi]) + (+0.933333333333333) * (f[(i + 0) * fsi]) +
	(+0.226982500643704) * (f[(i + 1) * fsi]);
      fr8 =
	(+0.226982500643704) * (f[(i - 2) * fsi]) + (-0.84126333590815) * (f[(i - 1) * fsi]) +
	(+1.61428083526445) * (f[(i + 0) * fsi]);
      fs0 = (omega0) * (fr0) + (omega1) * (fr1) + (omega2) * (fr2);
      fs1 =
	((+2.675) * ((omega3p) * (fr3) + (omega4p) * (fr4) + (omega5p) * (fr5))) -
	((+1.675) * ((omega3m) * (fr3) + (omega4m) * (fr4) + (omega5m) * (fr5)));
      fs2 = (omega6) * (fr6) + (omega7) * (fr7) + (omega8) * (fr8);
      fr[i * frsi + 0 * frsl] = fs0;
      fr[i * frsi + 1 * frsl] = fs1;
      fr[i * frsi + 2 * frsl] = fs2;
    }
}

PyObject *
py_reconstruct_gauss_legendre003003 (PyObject * self, PyObject * args)
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

  reconstruct_gauss_legendre003003 (f, n, fsi, omega, wsi, wsl, wsr, fr, frsi, frsl);

  Py_INCREF (Py_None);
  return Py_None;
}
