#include <Python.h>
#include <numpy/ndarrayobject.h>

void
weights_middle005001 (const double *restrict sigma, int n, int ssi, int ssr,
		      double *restrict omega, int wsi, int wsl, int wsr)
{
  int i;
  double acc, sigma0, sigma1, sigma2, sigma3, sigma4, omega1m, omega2p, omega3p, omega0m, omega3m,
    omega4m, omega0p, omega1p, omega4p, omega2m;
  for (i = 5; i < n - 5; i++)
    {
      sigma0 = sigma[i * ssi + 0 * ssr];
      sigma1 = sigma[i * ssi + 1 * ssr];
      sigma2 = sigma[i * ssi + 2 * ssr];
      sigma3 = sigma[i * ssi + 3 * ssr];
      sigma4 = sigma[i * ssi + 4 * ssr];
      acc = 0.0;
      omega0p =
	((+0.0032093603286385) / (+3.34858630952381)) / ((sigma0 + 1.0e-6) * (sigma0 + 1.0e-6));
      acc = acc + omega0p;
      omega1p =
	((+0.221555024591996) / (+3.34858630952381)) / ((sigma1 + 1.0e-6) * (sigma1 + 1.0e-6));
      acc = acc + omega1p;
      omega2p =
	((+2.89905753968254) / (+3.34858630952381)) / ((sigma2 + 1.0e-6) * (sigma2 + 1.0e-6));
      acc = acc + omega2p;
      omega3p =
	((+0.221555024591996) / (+3.34858630952381)) / ((sigma3 + 1.0e-6) * (sigma3 + 1.0e-6));
      acc = acc + omega3p;
      omega4p =
	((+0.0032093603286385) / (+3.34858630952381)) / ((sigma4 + 1.0e-6) * (sigma4 + 1.0e-6));
      acc = acc + omega4p;
      omega0p = (omega0p) / (acc);
      omega1p = (omega1p) / (acc);
      omega2p = (omega2p) / (acc);
      omega3p = (omega3p) / (acc);
      omega4p = (omega4p) / (acc);
      acc = 0.0;
      omega0m =
	((+0.006418720657277) / (+2.34858630952381)) / ((sigma0 + 1.0e-6) * (sigma0 + 1.0e-6));
      acc = acc + omega0m;
      omega1m =
	((+0.443110049183993) / (+2.34858630952381)) / ((sigma1 + 1.0e-6) * (sigma1 + 1.0e-6));
      acc = acc + omega1m;
      omega2m =
	((+1.44952876984127) / (+2.34858630952381)) / ((sigma2 + 1.0e-6) * (sigma2 + 1.0e-6));
      acc = acc + omega2m;
      omega3m =
	((+0.443110049183993) / (+2.34858630952381)) / ((sigma3 + 1.0e-6) * (sigma3 + 1.0e-6));
      acc = acc + omega3m;
      omega4m =
	((+0.006418720657277) / (+2.34858630952381)) / ((sigma4 + 1.0e-6) * (sigma4 + 1.0e-6));
      acc = acc + omega4m;
      omega0m = (omega0m) / (acc);
      omega1m = (omega1m) / (acc);
      omega2m = (omega2m) / (acc);
      omega3m = (omega3m) / (acc);
      omega4m = (omega4m) / (acc);
      omega[i * wsi + 0 * wsl + 0 * wsr + 0] = omega0p;
      omega[i * wsi + 0 * wsl + 0 * wsr + 1] = omega0m;
      omega[i * wsi + 0 * wsl + 1 * wsr + 0] = omega1p;
      omega[i * wsi + 0 * wsl + 1 * wsr + 1] = omega1m;
      omega[i * wsi + 0 * wsl + 2 * wsr + 0] = omega2p;
      omega[i * wsi + 0 * wsl + 2 * wsr + 1] = omega2m;
      omega[i * wsi + 0 * wsl + 3 * wsr + 0] = omega3p;
      omega[i * wsi + 0 * wsl + 3 * wsr + 1] = omega3m;
      omega[i * wsi + 0 * wsl + 4 * wsr + 0] = omega4p;
      omega[i * wsi + 0 * wsl + 4 * wsr + 1] = omega4m;
    }
}

PyObject *
py_weights_middle005001 (PyObject * self, PyObject * args)
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

  weights_middle005001 (sigma, n, ssi, ssr, omega, wsi, wsl, wsr);

  Py_INCREF (Py_None);
  return Py_None;
}

void
reconstruct_middle005001 (const double *restrict f, int n, int fsi,
			  const double *restrict omega, int wsi, int wsl, int wsr,
			  double *restrict fr, int frsi, int frsl)
{
  int i;
  double omega1m, omega2p, omega3p, omega0m, omega3m, omega4m, omega0p, omega1p, omega4p, omega2m,
    fs0, fr1, fr3, fr0, fr2, fr4;
  for (i = 5; i < n - 5; i++)
    {
      omega0p = omega[i * wsi + 0 * wsl + 0 * wsr + 0];
      omega0m = omega[i * wsi + 0 * wsl + 0 * wsr + 1];
      omega1p = omega[i * wsi + 0 * wsl + 1 * wsr + 0];
      omega1m = omega[i * wsi + 0 * wsl + 1 * wsr + 1];
      omega2p = omega[i * wsi + 0 * wsl + 2 * wsr + 0];
      omega2m = omega[i * wsi + 0 * wsl + 2 * wsr + 1];
      omega3p = omega[i * wsi + 0 * wsl + 3 * wsr + 0];
      omega3m = omega[i * wsi + 0 * wsl + 3 * wsr + 1];
      omega4p = omega[i * wsi + 0 * wsl + 4 * wsr + 0];
      omega4m = omega[i * wsi + 0 * wsl + 4 * wsr + 1];
      fr0 =
	(+0.8796875) * (f[(i + 0) * fsi]) + (+0.35625) * (f[(i + 1) * fsi]) +
	(-0.388541666666667) * (f[(i + 2) * fsi]) + (+0.189583333333333) * (f[(i + 3) * fsi]) +
	(-0.0369791666666667) * (f[(i + 4) * fsi]);
      fr1 =
	(-0.0369791666666667) * (f[(i - 1) * fsi]) + (+1.06458333333333) * (f[(i + 0) * fsi]) +
	(-0.0135416666666667) * (f[(i + 1) * fsi]) + (-0.01875) * (f[(i + 2) * fsi]) +
	(+0.0046875) * (f[(i + 3) * fsi]);
      fr2 =
	(+0.0046875) * (f[(i - 2) * fsi]) + (-0.0604166666666667) * (f[(i - 1) * fsi]) +
	(+1.11145833333333) * (f[(i + 0) * fsi]) + (-0.0604166666666667) * (f[(i + 1) * fsi]) +
	(+0.0046875) * (f[(i + 2) * fsi]);
      fr3 =
	(+0.0046875) * (f[(i - 3) * fsi]) + (-0.01875) * (f[(i - 2) * fsi]) +
	(-0.0135416666666667) * (f[(i - 1) * fsi]) + (+1.06458333333333) * (f[(i + 0) * fsi]) +
	(-0.0369791666666667) * (f[(i + 1) * fsi]);
      fr4 =
	(-0.0369791666666667) * (f[(i - 4) * fsi]) + (+0.189583333333333) * (f[(i - 3) * fsi]) +
	(-0.388541666666667) * (f[(i - 2) * fsi]) + (+0.35625) * (f[(i - 1) * fsi]) +
	(+0.8796875) * (f[(i + 0) * fsi]);
      fs0 =
	((+3.34858630952381) *
	 ((omega0p) * (fr0) + (omega1p) * (fr1) + (omega2p) * (fr2) + (omega3p) * (fr3) +
	  (omega4p) * (fr4))) - ((+2.34858630952381) * ((omega0m) * (fr0) + (omega1m) * (fr1) +
							(omega2m) * (fr2) + (omega3m) * (fr3) +
							(omega4m) * (fr4)));
      fr[i * frsi + 0 * frsl] = fs0;
    }
}

PyObject *
py_reconstruct_middle005001 (PyObject * self, PyObject * args)
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

  reconstruct_middle005001 (f, n, fsi, omega, wsi, wsl, wsr, fr, frsi, frsl);

  Py_INCREF (Py_None);
  return Py_None;
}
