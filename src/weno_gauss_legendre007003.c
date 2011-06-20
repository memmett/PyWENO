#include <Python.h>
#include <numpy/ndarrayobject.h>

void
gauss_legendre007003 (const double *restrict f, int n, int fsi,
		      const double *restrict sigma, int ssi, int ssr,
		      double *restrict fr, int frsi, int frsl)
{
  int i;
  double sigma0, sigma1, sigma2, sigma3, sigma4, sigma5, sigma6, omega7p, omega10m, omega15,
    omega7m, omega10p, omega3, omega19, omega11p, omega14, omega11m, omega4, omega9p, omega9m,
    omega20, omega0, omega16, omega5, omega13p, omega18, omega8m, omega13m, omega1, omega8p, omega2,
    omega6, omega12m, omega17, omega12p, accumulator, f1, f9, f18, f0, f20, f12, f17, f16, f11, f8,
    f6, f10, f5, f15, f19, f4, f7, f13, f3, f14, f2, fr0, fr1, fr2;
  for (i = 7; i < n - 7; i++)
    {
      sigma0 = sigma[i * ssi + 0 * ssr];
      sigma1 = sigma[i * ssi + 1 * ssr];
      sigma2 = sigma[i * ssi + 2 * ssr];
      sigma3 = sigma[i * ssi + 3 * ssr];
      sigma4 = sigma[i * ssi + 4 * ssr];
      sigma5 = sigma[i * ssi + 5 * ssr];
      sigma6 = sigma[i * ssi + 6 * ssr];
      accumulator = 0.0;
      omega0 = +0.00104136635391303 / (1.0e-6 + sigma0) / (1.0e-6 + sigma0);
      accumulator += omega0;
      omega1 = +0.0330729442907792 / (1.0e-6 + sigma1) / (1.0e-6 + sigma1);
      accumulator += omega1;
      omega2 = +0.211528516773841 / (1.0e-6 + sigma2) / (1.0e-6 + sigma2);
      accumulator += omega2;
      omega3 = +0.414963203018752 / (1.0e-6 + sigma3) / (1.0e-6 + sigma3);
      accumulator += omega3;
      omega4 = +0.277507985993813 / (1.0e-6 + sigma4) / (1.0e-6 + sigma4);
      accumulator += omega4;
      omega5 = +0.0590570350431013 / (1.0e-6 + sigma5) / (1.0e-6 + sigma5);
      accumulator += omega5;
      omega6 = +0.00282894852580019 / (1.0e-6 + sigma6) / (1.0e-6 + sigma6);
      accumulator += omega6;
      omega0 /= accumulator;
      omega1 /= accumulator;
      omega2 /= accumulator;
      omega3 /= accumulator;
      omega4 /= accumulator;
      omega5 /= accumulator;
      omega6 /= accumulator;
      accumulator = 0.0;
      omega7p = +0.000149691116038702 / +3.94901979530886 / (1.0e-6 + sigma0) / (1.0e-6 + sigma0);
      accumulator += omega7p;
      omega8p = +0.0106349872873979 / +3.94901979530886 / (1.0e-6 + sigma1) / (1.0e-6 + sigma1);
      accumulator += omega8p;
      omega9p = +0.31405195414804 / +3.94901979530886 / (1.0e-6 + sigma2) / (1.0e-6 + sigma2);
      accumulator += omega9p;
      omega10p = +3.29934653020591 / +3.94901979530886 / (1.0e-6 + sigma3) / (1.0e-6 + sigma3);
      accumulator += omega10p;
      omega11p = +0.31405195414804 / +3.94901979530886 / (1.0e-6 + sigma4) / (1.0e-6 + sigma4);
      accumulator += omega11p;
      omega12p = +0.0106349872873979 / +3.94901979530886 / (1.0e-6 + sigma5) / (1.0e-6 + sigma5);
      accumulator += omega12p;
      omega13p = +0.000149691116038702 / +3.94901979530886 / (1.0e-6 + sigma6) / (1.0e-6 + sigma6);
      accumulator += omega13p;
      omega7p /= accumulator;
      omega8p /= accumulator;
      omega9p /= accumulator;
      omega10p /= accumulator;
      omega11p /= accumulator;
      omega12p /= accumulator;
      omega13p /= accumulator;
      accumulator = 0.0;
      omega7m = +0.000299382232077403 / +2.94901979530886 / (1.0e-6 + sigma0) / (1.0e-6 + sigma0);
      accumulator += omega7m;
      omega8m = +0.0212699745747958 / +2.94901979530886 / (1.0e-6 + sigma1) / (1.0e-6 + sigma1);
      accumulator += omega8m;
      omega9m = +0.628103908296079 / +2.94901979530886 / (1.0e-6 + sigma2) / (1.0e-6 + sigma2);
      accumulator += omega9m;
      omega10m = +1.64967326510295 / +2.94901979530886 / (1.0e-6 + sigma3) / (1.0e-6 + sigma3);
      accumulator += omega10m;
      omega11m = +0.628103908296079 / +2.94901979530886 / (1.0e-6 + sigma4) / (1.0e-6 + sigma4);
      accumulator += omega11m;
      omega12m = +0.0212699745747958 / +2.94901979530886 / (1.0e-6 + sigma5) / (1.0e-6 + sigma5);
      accumulator += omega12m;
      omega13m = +0.000299382232077403 / +2.94901979530886 / (1.0e-6 + sigma6) / (1.0e-6 + sigma6);
      accumulator += omega13m;
      omega7m /= accumulator;
      omega8m /= accumulator;
      omega9m /= accumulator;
      omega10m /= accumulator;
      omega11m /= accumulator;
      omega12m /= accumulator;
      omega13m /= accumulator;
      accumulator = 0.0;
      omega14 = +0.0028289485258006 / (1.0e-6 + sigma0) / (1.0e-6 + sigma0);
      accumulator += omega14;
      omega15 = +0.0590570350431045 / (1.0e-6 + sigma1) / (1.0e-6 + sigma1);
      accumulator += omega15;
      omega16 = +0.27750798599381 / (1.0e-6 + sigma2) / (1.0e-6 + sigma2);
      accumulator += omega16;
      omega17 = +0.414963203018754 / (1.0e-6 + sigma3) / (1.0e-6 + sigma3);
      accumulator += omega17;
      omega18 = +0.211528516773836 / (1.0e-6 + sigma4) / (1.0e-6 + sigma4);
      accumulator += omega18;
      omega19 = +0.0330729442907832 / (1.0e-6 + sigma5) / (1.0e-6 + sigma5);
      accumulator += omega19;
      omega20 = +0.0010413663539119 / (1.0e-6 + sigma6) / (1.0e-6 + sigma6);
      accumulator += omega20;
      omega14 /= accumulator;
      omega15 /= accumulator;
      omega16 /= accumulator;
      omega17 /= accumulator;
      omega18 /= accumulator;
      omega19 /= accumulator;
      omega20 /= accumulator;
      f0 =
	+2.05455752641391 * f[(i + 0) * fsi] - 2.68940249110621 * f[(i + 1) * fsi] +
	3.44818678590482 * f[(i + 2) * fsi] - 3.05298160608982 * f[(i + 3) * fsi] +
	1.70896029144146 * f[(i + 4) * fsi] - 0.544757276564395 * f[(i + 5) * fsi] +
	0.0754367700002342 * f[(i + 6) * fsi];
      f1 =
	+0.0754367700002343 * f[(i - 1) * fsi] + 1.52650013641227 * f[(i + 0) * fsi] -
	1.10523032110129 * f[(i + 1) * fsi] + 0.807899835896623 * f[(i + 2) * fsi] -
	0.41269465608162 * f[(i + 3) * fsi] + 0.124788121436544 * f[(i + 4) * fsi] -
	0.0166998865627555 * f[(i + 5) * fsi];
      f2 =
	-0.0166998865627555 * f[(i - 2) * fsi] + 0.192335975939523 * f[(i - 1) * fsi] +
	1.1758025185944 * f[(i + 0) * fsi] - 0.520734291404848 * f[(i + 1) * fsi] +
	0.22340380620018 * f[(i + 2) * fsi] - 0.0619970382637539 * f[(i + 3) * fsi] +
	0.00788891549725496 * f[(i + 4) * fsi];
      f3 =
	+0.00788891549725495 * f[(i - 3) * fsi] - 0.0719222950435402 * f[(i - 2) * fsi] +
	0.358003201381877 * f[(i - 1) * fsi] + 0.899690476190476 * f[(i + 0) * fsi] -
	0.244622249000924 * f[(i + 1) * fsi] + 0.0577365807578259 * f[(i + 2) * fsi] -
	0.00677462978296924 * f[(i + 3) * fsi];
      f4 =
	-0.00677462978296924 * f[(i - 4) * fsi] + 0.0553113239780396 * f[(i - 3) * fsi] -
	0.214189520485894 * f[(i - 2) * fsi] + 0.5951152437858 * f[(i - 1) * fsi] +
	0.662578433786553 * f[(i + 0) * fsi] - 0.10235502355857 * f[(i + 1) * fsi] +
	0.0103141722770412 * f[(i + 2) * fsi];
      f5 =
	+0.0103141722770412 * f[(i - 5) * fsi] - 0.0789738357222578 * f[(i - 4) * fsi] +
	0.271908941795905 * f[(i - 3) * fsi] - 0.575185550182337 * f[(i - 2) * fsi] +
	0.956111273482243 * f[(i - 1) * fsi] + 0.445980815968687 * f[(i + 0) * fsi] -
	0.0301558176192819 * f[(i + 1) * fsi];
      f6 =
	-0.0301558176192819 * f[(i - 6) * fsi] + 0.221404895612014 * f[(i - 5) * fsi] -
	0.712246005727177 * f[(i - 4) * fsi] + 1.32736255847077 * f[(i - 3) * fsi] -
	1.6306391668572 * f[(i - 2) * fsi] + 1.58938344348716 * f[(i - 1) * fsi] +
	0.234890092633714 * f[(i + 0) * fsi];
      f7 =
	+0.819094122023809 * f[(i + 0) * fsi] + 0.687518601190476 * f[(i + 1) * fsi] -
	1.13598400297619 * f[(i + 2) * fsi] + 1.07853422619048 * f[(i + 3) * fsi] -
	0.622963169642857 * f[(i + 4) * fsi] + 0.20210193452381 * f[(i + 5) * fsi] -
	0.0283017113095238 * f[(i + 6) * fsi];
      f8 =
	-0.0283017113095238 * f[(i - 1) * fsi] + 1.01720610119048 * f[(i + 0) * fsi] +
	0.0931826636904762 * f[(i + 1) * fsi] - 0.145424107142857 * f[(i + 2) * fsi] +
	0.0879743303571429 * f[(i + 3) * fsi] - 0.0286272321428571 * f[(i + 4) * fsi] +
	0.00398995535714286 * f[(i + 5) * fsi];
      f9 =
	+0.00398995535714286 * f[(i - 2) * fsi] - 0.0562313988095238 * f[(i - 1) * fsi] +
	1.10099516369048 * f[(i + 0) * fsi] - 0.0464657738095238 * f[(i + 1) * fsi] -
	0.00577566964285714 * f[(i + 2) * fsi] + 0.00418526785714286 * f[(i + 3) * fsi] -
	0.000697544642857143 * f[(i + 4) * fsi];
      f10 =
	-0.000697544642857143 * f[(i - 3) * fsi] + 0.00887276785714286 * f[(i - 2) * fsi] -
	0.0708798363095238 * f[(i - 1) * fsi] + 1.12540922619048 * f[(i + 0) * fsi] -
	0.0708798363095238 * f[(i + 1) * fsi] + 0.00887276785714286 * f[(i + 2) * fsi] -
	0.000697544642857143 * f[(i + 3) * fsi];
      f11 =
	-0.000697544642857143 * f[(i - 4) * fsi] + 0.00418526785714286 * f[(i - 3) * fsi] -
	0.00577566964285714 * f[(i - 2) * fsi] - 0.0464657738095238 * f[(i - 1) * fsi] +
	1.10099516369048 * f[(i + 0) * fsi] - 0.0562313988095238 * f[(i + 1) * fsi] +
	0.00398995535714286 * f[(i + 2) * fsi];
      f12 =
	+0.00398995535714286 * f[(i - 5) * fsi] - 0.0286272321428571 * f[(i - 4) * fsi] +
	0.0879743303571429 * f[(i - 3) * fsi] - 0.145424107142857 * f[(i - 2) * fsi] +
	0.0931826636904762 * f[(i - 1) * fsi] + 1.01720610119048 * f[(i + 0) * fsi] -
	0.0283017113095238 * f[(i + 1) * fsi];
      f13 =
	-0.0283017113095238 * f[(i - 6) * fsi] + 0.20210193452381 * f[(i - 5) * fsi] -
	0.622963169642857 * f[(i - 4) * fsi] + 1.07853422619048 * f[(i - 3) * fsi] -
	1.13598400297619 * f[(i - 2) * fsi] + 0.687518601190476 * f[(i - 1) * fsi] +
	0.819094122023809 * f[(i + 0) * fsi];
      f14 =
	+0.234890092633714 * f[(i + 0) * fsi] + 1.58938344348716 * f[(i + 1) * fsi] -
	1.6306391668572 * f[(i + 2) * fsi] + 1.32736255847077 * f[(i + 3) * fsi] -
	0.712246005727179 * f[(i + 4) * fsi] + 0.221404895612014 * f[(i + 5) * fsi] -
	0.0301558176192819 * f[(i + 6) * fsi];
      f15 =
	-0.0301558176192818 * f[(i - 1) * fsi] + 0.445980815968687 * f[(i + 0) * fsi] +
	0.956111273482243 * f[(i + 1) * fsi] - 0.575185550182337 * f[(i + 2) * fsi] +
	0.271908941795905 * f[(i + 3) * fsi] - 0.0789738357222576 * f[(i + 4) * fsi] +
	0.0103141722770412 * f[(i + 5) * fsi];
      f16 =
	+0.0103141722770412 * f[(i - 2) * fsi] - 0.10235502355857 * f[(i - 1) * fsi] +
	0.662578433786553 * f[(i + 0) * fsi] + 0.5951152437858 * f[(i + 1) * fsi] -
	0.214189520485894 * f[(i + 2) * fsi] + 0.0553113239780397 * f[(i + 3) * fsi] -
	0.00677462978296924 * f[(i + 4) * fsi];
      f17 =
	-0.00677462978296924 * f[(i - 3) * fsi] + 0.0577365807578259 * f[(i - 2) * fsi] -
	0.244622249000924 * f[(i - 1) * fsi] + 0.899690476190476 * f[(i + 0) * fsi] +
	0.358003201381877 * f[(i + 1) * fsi] - 0.0719222950435402 * f[(i + 2) * fsi] +
	0.00788891549725496 * f[(i + 3) * fsi];
      f18 =
	+0.00788891549725496 * f[(i - 4) * fsi] - 0.0619970382637539 * f[(i - 3) * fsi] +
	0.22340380620018 * f[(i - 2) * fsi] - 0.520734291404848 * f[(i - 1) * fsi] +
	1.1758025185944 * f[(i + 0) * fsi] + 0.192335975939523 * f[(i + 1) * fsi] -
	0.0166998865627555 * f[(i + 2) * fsi];
      f19 =
	-0.0166998865627555 * f[(i - 5) * fsi] + 0.124788121436544 * f[(i - 4) * fsi] -
	0.41269465608162 * f[(i - 3) * fsi] + 0.807899835896623 * f[(i - 2) * fsi] -
	1.10523032110129 * f[(i - 1) * fsi] + 1.52650013641227 * f[(i + 0) * fsi] +
	0.0754367700002342 * f[(i + 1) * fsi];
      f20 =
	+0.0754367700002342 * f[(i - 6) * fsi] - 0.544757276564395 * f[(i - 5) * fsi] +
	1.70896029144146 * f[(i - 4) * fsi] - 3.05298160608982 * f[(i - 3) * fsi] +
	3.44818678590482 * f[(i - 2) * fsi] - 2.68940249110621 * f[(i - 1) * fsi] +
	2.0545575264139 * f[(i + 0) * fsi];
      fr0 =
	f0 * omega0 + f1 * omega1 + f2 * omega2 + f3 * omega3 + f4 * omega4 + f5 * omega5 +
	f6 * omega6;
      fr1 =
	+3.94901979530886 * (f7 * omega7p + f8 * omega8p + f9 * omega9p + f10 * omega10p +
			     f11 * omega11p + f12 * omega12p + f13 * omega13p) -
	+2.94901979530886 * (f7 * omega7m + f8 * omega8m + f9 * omega9m + f10 * omega10m +
			     f11 * omega11m + f12 * omega12m + f13 * omega13m);
      fr2 =
	f14 * omega14 + f15 * omega15 + f16 * omega16 + f17 * omega17 + f18 * omega18 +
	f19 * omega19 + f20 * omega20;
      fr[i * frsi + 0 * frsl] = fr0;
      fr[i * frsi + 1 * frsl] = fr1;
      fr[i * frsi + 2 * frsl] = fr2;
    }
}

PyObject *
py_gauss_legendre007003 (PyObject * self, PyObject * args)
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

  gauss_legendre007003 (f, n, fsi, sigma, ssi, ssr, fr, frsi, frsl);

  Py_INCREF (Py_None);
  return Py_None;
}
