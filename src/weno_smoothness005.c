#include <Python.h>
#include <numpy/ndarrayobject.h>

void
smoothness005 (const double *restrict f, int n, int fsi, double *restrict sigma, int ssi, int ssr)
{
  int i;
  double sigma0, sigma1, sigma2, sigma3, sigma4;
  for (i = 5; i < n - 5; i++)
    {
      sigma0 =
	((+21.4123015873016) * (f[(i + 0) * fsi])) * (f[(i + 0) * fsi]) +
	((-128.869246031746) * (f[(i + 0) * fsi])) * (f[(i + 1) * fsi]) +
	((+150.560119047619) * (f[(i + 0) * fsi])) * (f[(i + 2) * fsi]) +
	((-81.644246031746) * (f[(i + 0) * fsi])) * (f[(i + 3) * fsi]) +
	((+17.1287698412698) * (f[(i + 0) * fsi])) * (f[(i + 4) * fsi]) +
	((+202.492658730159) * (f[(i + 1) * fsi])) * (f[(i + 1) * fsi]) +
	((-488.507142857143) * (f[(i + 1) * fsi])) * (f[(i + 2) * fsi]) +
	((+269.535317460317) * (f[(i + 1) * fsi])) * (f[(i + 3) * fsi]) +
	((-57.144246031746) * (f[(i + 1) * fsi])) * (f[(i + 4) * fsi]) +
	((+301.86369047619) * (f[(i + 2) * fsi])) * (f[(i + 2) * fsi]) +
	((-338.173809523809) * (f[(i + 2) * fsi])) * (f[(i + 3) * fsi]) +
	((+72.3934523809524) * (f[(i + 2) * fsi])) * (f[(i + 4) * fsi]) +
	((+95.8259920634921) * (f[(i + 3) * fsi])) * (f[(i + 3) * fsi]) +
	((-41.369246031746) * (f[(i + 3) * fsi])) * (f[(i + 4) * fsi]) +
	((+4.49563492063492) * (f[(i + 4) * fsi])) * (f[(i + 4) * fsi]);
      sigma1 =
	((+4.49563492063492) * (f[(i - 1) * fsi])) * (f[(i - 1) * fsi]) +
	((-27.8275793650794) * (f[(i - 1) * fsi])) * (f[(i + 0) * fsi]) +
	((+32.7684523809524) * (f[(i - 1) * fsi])) * (f[(i + 1) * fsi]) +
	((-17.519246031746) * (f[(i - 1) * fsi])) * (f[(i + 2) * fsi]) +
	((+3.58710317460317) * (f[(i - 1) * fsi])) * (f[(i + 3) * fsi]) +
	((+48.1593253968254) * (f[(i + 0) * fsi])) * (f[(i + 0) * fsi]) +
	((-121.42380952381) * (f[(i + 0) * fsi])) * (f[(i + 1) * fsi]) +
	((+66.8686507936508) * (f[(i + 0) * fsi])) * (f[(i + 2) * fsi]) +
	((-13.9359126984127) * (f[(i + 0) * fsi])) * (f[(i + 3) * fsi]) +
	((+80.6136904761905) * (f[(i + 1) * fsi])) * (f[(i + 1) * fsi]) +
	((-92.2571428571429) * (f[(i + 1) * fsi])) * (f[(i + 2) * fsi]) +
	((+19.685119047619) * (f[(i + 1) * fsi])) * (f[(i + 3) * fsi]) +
	((+27.4926587301587) * (f[(i + 2) * fsi])) * (f[(i + 2) * fsi]) +
	((-12.0775793650794) * (f[(i + 2) * fsi])) * (f[(i + 3) * fsi]) +
	((+1.37063492063492) * (f[(i + 3) * fsi])) * (f[(i + 3) * fsi]);
      sigma2 =
	((+1.37063492063492) * (f[(i - 2) * fsi])) * (f[(i - 2) * fsi]) +
	((-10.119246031746) * (f[(i - 2) * fsi])) * (f[(i - 1) * fsi]) +
	((+13.4767857142857) * (f[(i - 2) * fsi])) * (f[(i + 0) * fsi]) +
	((-7.72757936507937) * (f[(i - 2) * fsi])) * (f[(i + 1) * fsi]) +
	((+1.62876984126984) * (f[(i - 2) * fsi])) * (f[(i + 2) * fsi]) +
	((+20.8259920634921) * (f[(i - 1) * fsi])) * (f[(i - 1) * fsi]) +
	((-59.3404761904762) * (f[(i - 1) * fsi])) * (f[(i + 0) * fsi]) +
	((+35.5353174603175) * (f[(i - 1) * fsi])) * (f[(i + 1) * fsi]) +
	((-7.72757936507937) * (f[(i - 1) * fsi])) * (f[(i + 2) * fsi]) +
	((+45.8636904761905) * (f[(i + 0) * fsi])) * (f[(i + 0) * fsi]) +
	((-59.3404761904762) * (f[(i + 0) * fsi])) * (f[(i + 1) * fsi]) +
	((+13.4767857142857) * (f[(i + 0) * fsi])) * (f[(i + 2) * fsi]) +
	((+20.8259920634921) * (f[(i + 1) * fsi])) * (f[(i + 1) * fsi]) +
	((-10.119246031746) * (f[(i + 1) * fsi])) * (f[(i + 2) * fsi]) +
	((+1.37063492063492) * (f[(i + 2) * fsi])) * (f[(i + 2) * fsi]);
      sigma3 =
	((+1.37063492063492) * (f[(i - 3) * fsi])) * (f[(i - 3) * fsi]) +
	((-12.0775793650794) * (f[(i - 3) * fsi])) * (f[(i - 2) * fsi]) +
	((+19.685119047619) * (f[(i - 3) * fsi])) * (f[(i - 1) * fsi]) +
	((-13.9359126984127) * (f[(i - 3) * fsi])) * (f[(i + 0) * fsi]) +
	((+3.58710317460317) * (f[(i - 3) * fsi])) * (f[(i + 1) * fsi]) +
	((+27.4926587301587) * (f[(i - 2) * fsi])) * (f[(i - 2) * fsi]) +
	((-92.2571428571429) * (f[(i - 2) * fsi])) * (f[(i - 1) * fsi]) +
	((+66.8686507936508) * (f[(i - 2) * fsi])) * (f[(i + 0) * fsi]) +
	((-17.519246031746) * (f[(i - 2) * fsi])) * (f[(i + 1) * fsi]) +
	((+80.6136904761905) * (f[(i - 1) * fsi])) * (f[(i - 1) * fsi]) +
	((-121.42380952381) * (f[(i - 1) * fsi])) * (f[(i + 0) * fsi]) +
	((+32.7684523809524) * (f[(i - 1) * fsi])) * (f[(i + 1) * fsi]) +
	((+48.1593253968254) * (f[(i + 0) * fsi])) * (f[(i + 0) * fsi]) +
	((-27.8275793650794) * (f[(i + 0) * fsi])) * (f[(i + 1) * fsi]) +
	((+4.49563492063492) * (f[(i + 1) * fsi])) * (f[(i + 1) * fsi]);
      sigma4 =
	((+4.49563492063492) * (f[(i - 4) * fsi])) * (f[(i - 4) * fsi]) +
	((-41.369246031746) * (f[(i - 4) * fsi])) * (f[(i - 3) * fsi]) +
	((+72.3934523809524) * (f[(i - 4) * fsi])) * (f[(i - 2) * fsi]) +
	((-57.144246031746) * (f[(i - 4) * fsi])) * (f[(i - 1) * fsi]) +
	((+17.1287698412698) * (f[(i - 4) * fsi])) * (f[(i + 0) * fsi]) +
	((+95.8259920634921) * (f[(i - 3) * fsi])) * (f[(i - 3) * fsi]) +
	((-338.173809523809) * (f[(i - 3) * fsi])) * (f[(i - 2) * fsi]) +
	((+269.535317460317) * (f[(i - 3) * fsi])) * (f[(i - 1) * fsi]) +
	((-81.644246031746) * (f[(i - 3) * fsi])) * (f[(i + 0) * fsi]) +
	((+301.86369047619) * (f[(i - 2) * fsi])) * (f[(i - 2) * fsi]) +
	((-488.507142857143) * (f[(i - 2) * fsi])) * (f[(i - 1) * fsi]) +
	((+150.560119047619) * (f[(i - 2) * fsi])) * (f[(i + 0) * fsi]) +
	((+202.492658730159) * (f[(i - 1) * fsi])) * (f[(i - 1) * fsi]) +
	((-128.869246031746) * (f[(i - 1) * fsi])) * (f[(i + 0) * fsi]) +
	((+21.4123015873016) * (f[(i + 0) * fsi])) * (f[(i + 0) * fsi]);
      sigma[i * ssi + 0 * ssr] = sigma0;
      sigma[i * ssi + 1 * ssr] = sigma1;
      sigma[i * ssi + 2 * ssr] = sigma2;
      sigma[i * ssi + 3 * ssr] = sigma3;
      sigma[i * ssi + 4 * ssr] = sigma4;
    }
}

PyObject *
py_smoothness005 (PyObject * self, PyObject * args)
{
  double *sigma, *f;
  PyArrayObject *f_py, *sigma_py;

  long int n;
  int ssi, ssr, fsi;

  /* parse options */

  if (!PyArg_ParseTuple (args, "OO", &f_py, &sigma_py))
    return NULL;

  if (sigma_py->nd != 2 || sigma_py->descr->type_num != PyArray_DOUBLE)
    {
      PyErr_SetString (PyExc_ValueError, "sigma must be two-dimensional and of type float");
      return NULL;
    }

  if (f_py->nd != 1 || f_py->descr->type_num != PyArray_DOUBLE)
    {
      PyErr_SetString (PyExc_ValueError, "f must be one-dimensional and of type float");
      return NULL;
    }

  /* get data, n, strides */
  sigma = (double *) PyArray_DATA (sigma_py);
  f = (double *) PyArray_DATA (f_py);

  n = PyArray_DIM (f_py, 0);

  ssi = sigma_py->strides[0] / sizeof (double);
  ssr = sigma_py->strides[1] / sizeof (double);

  fsi = f_py->strides[0] / sizeof (double);

  smoothness005 (f, n, fsi, sigma, ssi, ssr);

  Py_INCREF (Py_None);
  return Py_None;
}
