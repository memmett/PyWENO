#include <Python.h>
#include <numpy/ndarrayobject.h>

void
weights_middle003001 (const double *restrict sigma, int n, int ssi, int ssr,
		      double *restrict omega, int wsi, int wsl, int wsr)
{
  int i;
  double acc, sigma0, sigma1, sigma2, omega1m, omega2p, omega0m, omega0p, omega1p, omega2m;
  for (i = 3; i < n - 3; i++)
    {
      sigma0 = sigma[i * ssi + 0 * ssr];
      sigma1 = sigma[i * ssi + 1 * ssr];
      sigma2 = sigma[i * ssi + 2 * ssr];
      acc = 0.0;
      omega0p = ((+0.1125) / (+2.675)) / ((sigma0 + 1.0e-6) * (sigma0 + 1.0e-6));
      acc = acc + omega0p;
      omega1p = ((+2.45) / (+2.675)) / ((sigma1 + 1.0e-6) * (sigma1 + 1.0e-6));
      acc = acc + omega1p;
      omega2p = ((+0.1125) / (+2.675)) / ((sigma2 + 1.0e-6) * (sigma2 + 1.0e-6));
      acc = acc + omega2p;
      omega0p = (omega0p) / (acc);
      omega1p = (omega1p) / (acc);
      omega2p = (omega2p) / (acc);
      acc = 0.0;
      omega0m = ((+0.225) / (+1.675)) / ((sigma0 + 1.0e-6) * (sigma0 + 1.0e-6));
      acc = acc + omega0m;
      omega1m = ((+1.225) / (+1.675)) / ((sigma1 + 1.0e-6) * (sigma1 + 1.0e-6));
      acc = acc + omega1m;
      omega2m = ((+0.225) / (+1.675)) / ((sigma2 + 1.0e-6) * (sigma2 + 1.0e-6));
      acc = acc + omega2m;
      omega0m = (omega0m) / (acc);
      omega1m = (omega1m) / (acc);
      omega2m = (omega2m) / (acc);
      omega[i * wsi + 0 * wsl + 0 * wsr + 0] = omega0p;
      omega[i * wsi + 0 * wsl + 0 * wsr + 1] = omega0m;
      omega[i * wsi + 0 * wsl + 1 * wsr + 0] = omega1p;
      omega[i * wsi + 0 * wsl + 1 * wsr + 1] = omega1m;
      omega[i * wsi + 0 * wsl + 2 * wsr + 0] = omega2p;
      omega[i * wsi + 0 * wsl + 2 * wsr + 1] = omega2m;
    }
}

PyObject *
py_weights_middle003001 (PyObject * self, PyObject * args)
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

  weights_middle003001 (sigma, n, ssi, ssr, omega, wsi, wsl, wsr);

  Py_INCREF (Py_None);
  return Py_None;
}

void
reconstruct_middle003001 (const double *restrict f, int n, int fsi,
			  const double *restrict omega, int wsi, int wsl, int wsr,
			  double *restrict fr, int frsi, int frsl)
{
  int i;
  double omega1m, omega2p, omega0m, omega0p, omega1p, omega2m, fs0, fr1, fr0, fr2;
  for (i = 3; i < n - 3; i++)
    {
      omega0p = omega[i * wsi + 0 * wsl + 0 * wsr + 0];
      omega0m = omega[i * wsi + 0 * wsl + 0 * wsr + 1];
      omega1p = omega[i * wsi + 0 * wsl + 1 * wsr + 0];
      omega1m = omega[i * wsi + 0 * wsl + 1 * wsr + 1];
      omega2p = omega[i * wsi + 0 * wsl + 2 * wsr + 0];
      omega2m = omega[i * wsi + 0 * wsl + 2 * wsr + 1];
      fr0 =
	(+0.958333333333333) * (f[(i + 0) * fsi]) + (+0.0833333333333333) * (f[(i + 1) * fsi]) +
	(-0.0416666666666667) * (f[(i + 2) * fsi]);
      fr1 =
	(-0.0416666666666667) * (f[(i - 1) * fsi]) + (+1.08333333333333) * (f[(i + 0) * fsi]) +
	(-0.0416666666666667) * (f[(i + 1) * fsi]);
      fr2 =
	(-0.0416666666666667) * (f[(i - 2) * fsi]) + (+0.0833333333333333) * (f[(i - 1) * fsi]) +
	(+0.958333333333333) * (f[(i + 0) * fsi]);
      fs0 =
	((+2.675) * ((omega0p) * (fr0) + (omega1p) * (fr1) + (omega2p) * (fr2))) -
	((+1.675) * ((omega0m) * (fr0) + (omega1m) * (fr1) + (omega2m) * (fr2)));
      fr[i * frsi + 0 * frsl] = fs0;
    }
}

PyObject *
py_reconstruct_middle003001 (PyObject * self, PyObject * args)
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

  reconstruct_middle003001 (f, n, fsi, omega, wsi, wsl, wsr, fr, frsi, frsl);

  Py_INCREF (Py_None);
  return Py_None;
}
