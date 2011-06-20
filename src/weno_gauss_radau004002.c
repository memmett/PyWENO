#include <Python.h>
#include <numpy/ndarrayobject.h>

void
weights_gauss_radau004002 (const double *restrict sigma, int n, int ssi, int ssr,
			   double *restrict omega, int wsi, int wsl, int wsr)
{
  int i;
  double acc, sigma0, sigma1, sigma2, sigma3, omega1, omega6, omega0, omega2, omega7, omega4,
    omega3, omega5;
  for (i = 4; i < n - 4; i++)
    {
      sigma0 = sigma[i * ssi + 0 * ssr];
      sigma1 = sigma[i * ssi + 1 * ssr];
      sigma2 = sigma[i * ssi + 2 * ssr];
      sigma3 = sigma[i * ssi + 3 * ssr];
      acc = 0.0;
      omega0 = (+0.0285714285714286) / ((sigma0 + 1.0e-6) * (sigma0 + 1.0e-6));
      acc = acc + omega0;
      omega1 = (+0.342857142857143) / ((sigma1 + 1.0e-6) * (sigma1 + 1.0e-6));
      acc = acc + omega1;
      omega2 = (+0.514285714285714) / ((sigma2 + 1.0e-6) * (sigma2 + 1.0e-6));
      acc = acc + omega2;
      omega3 = (+0.114285714285714) / ((sigma3 + 1.0e-6) * (sigma3 + 1.0e-6));
      acc = acc + omega3;
      omega0 = (omega0) / (acc);
      omega1 = (omega1) / (acc);
      omega2 = (omega2) / (acc);
      omega3 = (omega3) / (acc);
      acc = 0.0;
      omega4 = (+0.041453262786594) / ((sigma0 + 1.0e-6) * (sigma0 + 1.0e-6));
      acc = acc + omega4;
      omega5 = (+0.344950456950459) / ((sigma1 + 1.0e-6) * (sigma1 + 1.0e-6));
      acc = acc + omega5;
      omega6 = (+0.425135710849996) / ((sigma2 + 1.0e-6) * (sigma2 + 1.0e-6));
      acc = acc + omega6;
      omega7 = (+0.188460569412951) / ((sigma3 + 1.0e-6) * (sigma3 + 1.0e-6));
      acc = acc + omega7;
      omega4 = (omega4) / (acc);
      omega5 = (omega5) / (acc);
      omega6 = (omega6) / (acc);
      omega7 = (omega7) / (acc);
      omega[i * wsi + 0 * wsl + 0 * wsr + 0] = omega0;
      omega[i * wsi + 0 * wsl + 1 * wsr + 0] = omega1;
      omega[i * wsi + 0 * wsl + 2 * wsr + 0] = omega2;
      omega[i * wsi + 0 * wsl + 3 * wsr + 0] = omega3;
      omega[i * wsi + 1 * wsl + 0 * wsr + 0] = omega4;
      omega[i * wsi + 1 * wsl + 1 * wsr + 0] = omega5;
      omega[i * wsi + 1 * wsl + 2 * wsr + 0] = omega6;
      omega[i * wsi + 1 * wsl + 3 * wsr + 0] = omega7;
    }
}

PyObject *
py_weights_gauss_radau004002 (PyObject * self, PyObject * args)
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

  weights_gauss_radau004002 (sigma, n, ssi, ssr, omega, wsi, wsl, wsr);

  Py_INCREF (Py_None);
  return Py_None;
}

void
reconstruct_gauss_radau004002 (const double *restrict f, int n, int fsi,
			       const double *restrict omega, int wsi, int wsl, int wsr,
			       double *restrict fr, int frsi, int frsl)
{
  int i;
  double omega1, omega6, omega0, omega2, omega7, omega4, omega3, omega5, fs0, fs1, fr1, fr6, fr0,
    fr2, fr7, fr4, fr3, fr5;
  for (i = 4; i < n - 4; i++)
    {
      omega0 = omega[i * wsi + 0 * wsl + 0 * wsr + 0];
      omega1 = omega[i * wsi + 0 * wsl + 1 * wsr + 0];
      omega2 = omega[i * wsi + 0 * wsl + 2 * wsr + 0];
      omega3 = omega[i * wsi + 0 * wsl + 3 * wsr + 0];
      omega4 = omega[i * wsi + 1 * wsl + 0 * wsr + 0];
      omega5 = omega[i * wsi + 1 * wsl + 1 * wsr + 0];
      omega6 = omega[i * wsi + 1 * wsl + 2 * wsr + 0];
      omega7 = omega[i * wsi + 1 * wsl + 3 * wsr + 0];
      fr0 =
	(+2.08333333333333) * (f[(i + 0) * fsi]) + (-1.91666666666667) * (f[(i + 1) * fsi]) +
	(+1.08333333333333) * (f[(i + 2) * fsi]) + (-0.25) * (f[(i + 3) * fsi]);
      fr1 =
	(+0.25) * (f[(i - 1) * fsi]) + (+1.08333333333333) * (f[(i + 0) * fsi]) +
	(-0.416666666666667) * (f[(i + 1) * fsi]) + (+0.0833333333333333) * (f[(i + 2) * fsi]);
      fr2 =
	(-0.0833333333333333) * (f[(i - 2) * fsi]) + (+0.583333333333333) * (f[(i - 1) * fsi]) +
	(+0.583333333333333) * (f[(i + 0) * fsi]) + (-0.0833333333333333) * (f[(i + 1) * fsi]);
      fr3 =
	(+0.0833333333333333) * (f[(i - 3) * fsi]) + (-0.416666666666667) * (f[(i - 2) * fsi]) +
	(+1.08333333333333) * (f[(i - 1) * fsi]) + (+0.25) * (f[(i + 0) * fsi]);
      fr4 =
	(+0.645061728395062) * (f[(i + 0) * fsi]) + (+0.62037037037037) * (f[(i + 1) * fsi]) +
	(-0.342592592592593) * (f[(i + 2) * fsi]) + (+0.0771604938271604) * (f[(i + 3) * fsi]);
      fr5 =
	(-0.0771604938271605) * (f[(i - 1) * fsi]) + (+0.953703703703704) * (f[(i + 0) * fsi]) +
	(+0.157407407407407) * (f[(i + 1) * fsi]) + (-0.0339506172839506) * (f[(i + 2) * fsi]);
      fr6 =
	(+0.0339506172839506) * (f[(i - 2) * fsi]) + (-0.212962962962963) * (f[(i - 1) * fsi]) +
	(+1.15740740740741) * (f[(i + 0) * fsi]) + (+0.0216049382716049) * (f[(i + 1) * fsi]);
      fr7 =
	(-0.0216049382716049) * (f[(i - 3) * fsi]) + (+0.12037037037037) * (f[(i - 2) * fsi]) +
	(-0.342592592592593) * (f[(i - 1) * fsi]) + (+1.24382716049383) * (f[(i + 0) * fsi]);
      fs0 = (omega0) * (fr0) + (omega1) * (fr1) + (omega2) * (fr2) + (omega3) * (fr3);
      fs1 = (omega4) * (fr4) + (omega5) * (fr5) + (omega6) * (fr6) + (omega7) * (fr7);
      fr[i * frsi + 0 * frsl] = fs0;
      fr[i * frsi + 1 * frsl] = fs1;
    }
}

PyObject *
py_reconstruct_gauss_radau004002 (PyObject * self, PyObject * args)
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

  reconstruct_gauss_radau004002 (f, n, fsi, omega, wsi, wsl, wsr, fr, frsi, frsl);

  Py_INCREF (Py_None);
  return Py_None;
}
