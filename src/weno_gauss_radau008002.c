#include <Python.h>
#include <numpy/ndarrayobject.h>

void
gauss_radau008002 (const double *restrict f, int n, int fsi,
		   const double *restrict sigma, int ssi, int ssr,
		   double *restrict fr, int frsi, int frsl)
{
  int i;
  double sigma0, sigma1, sigma2, sigma3, sigma4, sigma5, sigma6, sigma7, omega8p, omega11m, omega7,
    omega8m, omega11p, omega3, omega12p, omega15m, omega12m, omega15p, omega4, omega10p, omega10m,
    omega0, omega5, omega14p, omega9m, omega14m, omega1, omega9p, omega2, omega6, omega13m,
    omega13p, accumulator, f1, f10, f0, f13, f15, f7, f9, f6, f11, f5, f12, f4, f8, f14, f3, f2,
    fr0, fr1;
  for (i = 8; i < n - 8; i++)
    {
      sigma0 = sigma[i * ssi + 0 * ssr];
      sigma1 = sigma[i * ssi + 1 * ssr];
      sigma2 = sigma[i * ssi + 2 * ssr];
      sigma3 = sigma[i * ssi + 3 * ssr];
      sigma4 = sigma[i * ssi + 4 * ssr];
      sigma5 = sigma[i * ssi + 5 * ssr];
      sigma6 = sigma[i * ssi + 6 * ssr];
      sigma7 = sigma[i * ssi + 7 * ssr];
      accumulator = 0.0;
      omega0 = +0.000155400155400155 / (1.0e-6 + sigma0) / (1.0e-6 + sigma0);
      accumulator += omega0;
      omega1 = +0.0087024087024087 / (1.0e-6 + sigma1) / (1.0e-6 + sigma1);
      accumulator += omega1;
      omega2 = +0.0913752913752914 / (1.0e-6 + sigma2) / (1.0e-6 + sigma2);
      accumulator += omega2;
      omega3 = +0.304584304584305 / (1.0e-6 + sigma3) / (1.0e-6 + sigma3);
      accumulator += omega3;
      omega4 = +0.380730380730381 / (1.0e-6 + sigma4) / (1.0e-6 + sigma4);
      accumulator += omega4;
      omega5 = +0.182750582750583 / (1.0e-6 + sigma5) / (1.0e-6 + sigma5);
      accumulator += omega5;
      omega6 = +0.0304584304584305 / (1.0e-6 + sigma6) / (1.0e-6 + sigma6);
      accumulator += omega6;
      omega7 = +0.00124320124320124 / (1.0e-6 + sigma7) / (1.0e-6 + sigma7);
      accumulator += omega7;
      omega0 /= accumulator;
      omega1 /= accumulator;
      omega2 /= accumulator;
      omega3 /= accumulator;
      omega4 /= accumulator;
      omega5 /= accumulator;
      omega6 /= accumulator;
      omega7 /= accumulator;
      accumulator = 0.0;
      omega8p = +0.000625053280395403 / +2.00679080032989 / (1.0e-6 + sigma0) / (1.0e-6 + sigma0);
      accumulator += omega8p;
      omega9p = +0.0239477446016324 / +2.00679080032989 / (1.0e-6 + sigma1) / (1.0e-6 + sigma1);
      accumulator += omega9p;
      omega10p = +0.206718357490626 / +2.00679080032989 / (1.0e-6 + sigma2) / (1.0e-6 + sigma2);
      accumulator += omega10p;
      omega11p = +0.611527783381243 / +2.00679080032989 / (1.0e-6 + sigma3) / (1.0e-6 + sigma3);
      accumulator += omega11p;
      omega12p = +0.718530563313041 / +2.00679080032989 / (1.0e-6 + sigma4) / (1.0e-6 + sigma4);
      accumulator += omega12p;
      omega13p = +0.348658140209215 / +2.00679080032989 / (1.0e-6 + sigma5) / (1.0e-6 + sigma5);
      accumulator += omega13p;
      omega14p = +0.0945195579437635 / +2.00679080032989 / (1.0e-6 + sigma6) / (1.0e-6 + sigma6);
      accumulator += omega14p;
      omega15p = +0.00226360010996953 / +2.00679080032989 / (1.0e-6 + sigma7) / (1.0e-6 + sigma7);
      accumulator += omega15p;
      omega8p /= accumulator;
      omega9p /= accumulator;
      omega10p /= accumulator;
      omega11p /= accumulator;
      omega12p /= accumulator;
      omega13p /= accumulator;
      omega14p /= accumulator;
      omega15p /= accumulator;
      accumulator = 0.0;
      omega8m = +0.000312526640197701 / +1.0067908003299 / (1.0e-6 + sigma0) / (1.0e-6 + sigma0);
      accumulator += omega8m;
      omega9m = +0.0119738723008162 / +1.0067908003299 / (1.0e-6 + sigma1) / (1.0e-6 + sigma1);
      accumulator += omega9m;
      omega10m = +0.103359178745313 / +1.0067908003299 / (1.0e-6 + sigma2) / (1.0e-6 + sigma2);
      accumulator += omega10m;
      omega11m = +0.305763891690622 / +1.0067908003299 / (1.0e-6 + sigma3) / (1.0e-6 + sigma3);
      accumulator += omega11m;
      omega12m = +0.359265281656521 / +1.0067908003299 / (1.0e-6 + sigma4) / (1.0e-6 + sigma4);
      accumulator += omega12m;
      omega13m = +0.174329070104608 / +1.0067908003299 / (1.0e-6 + sigma5) / (1.0e-6 + sigma5);
      accumulator += omega13m;
      omega14m = +0.0472597789718818 / +1.0067908003299 / (1.0e-6 + sigma6) / (1.0e-6 + sigma6);
      accumulator += omega14m;
      omega15m = +0.00452720021993906 / +1.0067908003299 / (1.0e-6 + sigma7) / (1.0e-6 + sigma7);
      accumulator += omega15m;
      omega8m /= accumulator;
      omega9m /= accumulator;
      omega10m /= accumulator;
      omega11m /= accumulator;
      omega12m /= accumulator;
      omega13m /= accumulator;
      omega14m /= accumulator;
      omega15m /= accumulator;
      f0 =
	+2.71785714285714 * f[(i + 0) * fsi] - 5.28214285714286 * f[(i + 1) * fsi] +
	8.71785714285714 * f[(i + 2) * fsi] - 9.94880952380952 * f[(i + 3) * fsi] +
	7.55119047619048 * f[(i + 4) * fsi] - 3.64880952380952 * f[(i + 5) * fsi] +
	1.01785714285714 * f[(i + 6) * fsi] - 0.125 * f[(i + 7) * fsi];
      f1 =
	+0.125 * f[(i - 1) * fsi] + 1.71785714285714 * f[(i + 0) * fsi] -
	1.78214285714286 * f[(i + 1) * fsi] + 1.71785714285714 * f[(i + 2) * fsi] -
	1.19880952380952 * f[(i + 3) * fsi] + 0.551190476190476 * f[(i + 4) * fsi] -
	0.148809523809524 * f[(i + 5) * fsi] + 0.0178571428571429 * f[(i + 6) * fsi];
      f2 =
	-0.0178571428571429 * f[(i - 2) * fsi] + 0.267857142857143 * f[(i - 1) * fsi] +
	1.21785714285714 * f[(i + 0) * fsi] - 0.782142857142857 * f[(i + 1) * fsi] +
	0.467857142857143 * f[(i + 2) * fsi] - 0.198809523809524 * f[(i + 3) * fsi] +
	0.0511904761904762 * f[(i + 4) * fsi] - 0.00595238095238095 * f[(i + 5) * fsi];
      f3 =
	+0.00595238095238095 * f[(i - 3) * fsi] - 0.0654761904761905 * f[(i - 2) * fsi] +
	0.43452380952381 * f[(i - 1) * fsi] + 0.884523809523809 * f[(i + 0) * fsi] -
	0.36547619047619 * f[(i + 1) * fsi] + 0.13452380952381 * f[(i + 2) * fsi] -
	0.0321428571428571 * f[(i + 3) * fsi] + 0.00357142857142857 * f[(i + 4) * fsi];
      f4 =
	-0.00357142857142857 * f[(i - 4) * fsi] + 0.0345238095238095 * f[(i - 3) * fsi] -
	0.16547619047619 * f[(i - 2) * fsi] + 0.634523809523809 * f[(i - 1) * fsi] +
	0.634523809523809 * f[(i + 0) * fsi] - 0.16547619047619 * f[(i + 1) * fsi] +
	0.0345238095238095 * f[(i + 2) * fsi] - 0.00357142857142857 * f[(i + 3) * fsi];
      f5 =
	+0.00357142857142857 * f[(i - 5) * fsi] - 0.0321428571428571 * f[(i - 4) * fsi] +
	0.13452380952381 * f[(i - 3) * fsi] - 0.36547619047619 * f[(i - 2) * fsi] +
	0.884523809523809 * f[(i - 1) * fsi] + 0.43452380952381 * f[(i + 0) * fsi] -
	0.0654761904761905 * f[(i + 1) * fsi] + 0.00595238095238095 * f[(i + 2) * fsi];
      f6 =
	-0.00595238095238095 * f[(i - 6) * fsi] + 0.0511904761904762 * f[(i - 5) * fsi] -
	0.198809523809524 * f[(i - 4) * fsi] + 0.467857142857143 * f[(i - 3) * fsi] -
	0.782142857142857 * f[(i - 2) * fsi] + 1.21785714285714 * f[(i - 1) * fsi] +
	0.267857142857143 * f[(i + 0) * fsi] - 0.0178571428571429 * f[(i + 1) * fsi];
      f7 =
	+0.0178571428571429 * f[(i - 7) * fsi] - 0.148809523809524 * f[(i - 6) * fsi] +
	0.551190476190476 * f[(i - 5) * fsi] - 1.19880952380952 * f[(i - 4) * fsi] +
	1.71785714285714 * f[(i - 3) * fsi] - 1.78214285714286 * f[(i - 2) * fsi] +
	1.71785714285714 * f[(i - 1) * fsi] + 0.125 * f[(i + 0) * fsi];
      f8 =
	+0.477712275277434 * f[(i + 0) * fsi] + 1.49528944484363 * f[(i + 1) * fsi] -
	2.29388649378361 * f[(i + 2) * fsi] + 2.50987309570985 * f[(i + 3) * fsi] -
	1.85906202596874 * f[(i + 4) * fsi] + 0.884401876891589 * f[(i + 5) * fsi] -
	0.244066852468772 * f[(i + 6) * fsi] + 0.0297386794986246 * f[(i + 7) * fsi];
      f9 =
	-0.0297386794986246 * f[(i - 1) * fsi] + 0.71562171126643 * f[(i + 0) * fsi] +
	0.662606418882139 * f[(i + 1) * fsi] - 0.628520441860634 * f[(i + 2) * fsi] +
	0.428165530806134 * f[(i + 3) * fsi] - 0.193695974045768 * f[(i + 4) * fsi] +
	0.0517188509300992 * f[(i + 5) * fsi] - 0.00615741647977588 * f[(i + 6) * fsi];
      f10 =
	+0.00615741647977588 * f[(i - 2) * fsi] - 0.0789980113368316 * f[(i - 1) * fsi] +
	0.888029372700155 * f[(i + 0) * fsi] + 0.31779109601469 * f[(i + 1) * fsi] -
	0.197501288276323 * f[(i + 2) * fsi] + 0.0833502079386853 * f[(i + 3) * fsi] -
	0.0212883126120438 * f[(i + 4) * fsi] + 0.00245951909189221 * f[(i + 5) * fsi];
      f11 =
	-0.00245951909189221 * f[(i - 3) * fsi] + 0.0258335692149135 * f[(i - 2) * fsi] -
	0.147864545909813 * f[(i - 1) * fsi] + 1.02576244184612 * f[(i + 0) * fsi] +
	0.145624759582236 * f[(i + 1) * fsi] - 0.059768219130359 * f[(i + 2) * fsi] +
	0.0144836733657036 * f[(i + 3) * fsi] - 0.0016121598769061 * f[(i + 4) * fsi];
      f12 =
	+0.0016121598769061 * f[(i - 4) * fsi] - 0.015356798107141 * f[(i - 3) * fsi] +
	0.0709740457682845 * f[(i - 2) * fsi] - 0.238145499016555 * f[(i - 1) * fsi] +
	1.13861363322955 * f[(i + 0) * fsi] + 0.0553438064754937 * f[(i + 1) * fsi] -
	0.0146277425769881 * f[(i + 2) * fsi] + 0.00158639435045471 * f[(i + 3) * fsi];
      f13 =
	-0.00158639435045471 * f[(i - 5) * fsi] + 0.0143033146805438 * f[(i - 4) * fsi] -
	0.0597758399198728 * f[(i - 3) * fsi] + 0.159812129393748 * f[(i - 2) * fsi] -
	0.349193103548385 * f[(i - 1) * fsi] + 1.22745171685501 * f[(i + 0) * fsi] +
	0.0109247646627619 * f[(i + 1) * fsi] - 0.00193658777335046 * f[(i + 2) * fsi];
      f14 =
	+0.00193658777335046 * f[(i - 6) * fsi] - 0.0170790965372584 * f[(i - 5) * fsi] +
	0.0685277723343566 * f[(i - 4) * fsi] - 0.168224755227498 * f[(i - 3) * fsi] +
	0.29537327352828 * f[(i - 2) * fsi] - 0.45764201885601 * f[(i - 1) * fsi] +
	1.28167617450882 * f[(i + 0) * fsi] - 0.00456793752404179 * f[(i + 1) * fsi];
      f15 =
	+0.00456793752404179 * f[(i - 7) * fsi] - 0.0346069124189838 * f[(i - 6) * fsi] +
	0.110823154135912 * f[(i - 5) * fsi] - 0.187276729011983 * f[(i - 4) * fsi] +
	0.151530871455427 * f[(i - 3) * fsi] + 0.0395687721819405 * f[(i - 2) * fsi] -
	0.329739768182841 * f[(i - 1) * fsi] + 1.24513267431649 * f[(i + 0) * fsi];
      fr0 =
	f0 * omega0 + f1 * omega1 + f2 * omega2 + f3 * omega3 + f4 * omega4 + f5 * omega5 +
	f6 * omega6 + f7 * omega7;
      fr1 =
	+2.00679080032989 * (f8 * omega8p + f9 * omega9p + f10 * omega10p + f11 * omega11p +
			     f12 * omega12p + f13 * omega13p + f14 * omega14p + f15 * omega15p) -
	+1.0067908003299 * (f8 * omega8m + f9 * omega9m + f10 * omega10m + f11 * omega11m +
			    f12 * omega12m + f13 * omega13m + f14 * omega14m + f15 * omega15m);
      fr[i * frsi + 0 * frsl] = fr0;
      fr[i * frsi + 1 * frsl] = fr1;
    }
}

PyObject *
py_gauss_radau008002 (PyObject * self, PyObject * args)
{
  double *f, *sigma, *fr;
  PyArrayObject *f_py, *sigma_py, *fr_py;

  long int n;
  int fsi, frsi, frsl, ssi, ssr;

  /* parse options */

  if (!PyArg_ParseTuple (args, "OOO", &f_py, &sigma_py, &fr_py))
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

  if (sigma_py->nd != 2 || sigma_py->descr->type_num != PyArray_DOUBLE)
    {
      PyErr_SetString (PyExc_ValueError, "sigma must be two-dimensional and of type float");
      return NULL;
    }

  /* get data, n, strides */
  f = (double *) PyArray_DATA (f_py);
  fr = (double *) PyArray_DATA (fr_py);
  sigma = (double *) PyArray_DATA (sigma_py);

  n = PyArray_DIM (f_py, 0);

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

  ssi = sigma_py->strides[0] / sizeof (double);
  ssr = sigma_py->strides[1] / sizeof (double);

  gauss_radau008002 (f, n, fsi, sigma, ssi, ssr, fr, frsi, frsl);

  Py_INCREF (Py_None);
  return Py_None;
}
