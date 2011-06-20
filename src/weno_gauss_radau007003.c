#include <Python.h>
#include <numpy/ndarrayobject.h>

void
gauss_radau007003 (const double *restrict f, int n, int fsi,
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
      omega0 = +0.000582750582750583 / (1.0e-6 + sigma0) / (1.0e-6 + sigma0);
      accumulator += omega0;
      omega1 = +0.0244755244755245 / (1.0e-6 + sigma1) / (1.0e-6 + sigma1);
      accumulator += omega1;
      omega2 = +0.183566433566434 / (1.0e-6 + sigma2) / (1.0e-6 + sigma2);
      accumulator += omega2;
      omega3 = +0.407925407925408 / (1.0e-6 + sigma3) / (1.0e-6 + sigma3);
      accumulator += omega3;
      omega4 = +0.305944055944056 / (1.0e-6 + sigma4) / (1.0e-6 + sigma4);
      accumulator += omega4;
      omega5 = +0.0734265734265734 / (1.0e-6 + sigma5) / (1.0e-6 + sigma5);
      accumulator += omega5;
      omega6 = +0.00407925407925408 / (1.0e-6 + sigma6) / (1.0e-6 + sigma6);
      accumulator += omega6;
      omega0 /= accumulator;
      omega1 /= accumulator;
      omega2 /= accumulator;
      omega3 /= accumulator;
      omega4 /= accumulator;
      omega5 /= accumulator;
      omega6 /= accumulator;
      accumulator = 0.0;
      omega7p = +0.0054705801709656 / +2.0164117405129 / (1.0e-6 + sigma0) / (1.0e-6 + sigma0);
      accumulator += omega7p;
      omega8p = +0.262903869350252 / +2.0164117405129 / (1.0e-6 + sigma1) / (1.0e-6 + sigma1);
      accumulator += omega8p;
      omega9p = +0.568633859363123 / +2.0164117405129 / (1.0e-6 + sigma2) / (1.0e-6 + sigma2);
      accumulator += omega9p;
      omega10p = +0.755590543195758 / +2.0164117405129 / (1.0e-6 + sigma3) / (1.0e-6 + sigma3);
      accumulator += omega10p;
      omega11p = +0.364923367492448 / +2.0164117405129 / (1.0e-6 + sigma4) / (1.0e-6 + sigma4);
      accumulator += omega11p;
      omega12p = +0.0569829903038208 / +2.0164117405129 / (1.0e-6 + sigma5) / (1.0e-6 + sigma5);
      accumulator += omega12p;
      omega13p = +0.00190653063652787 / +2.0164117405129 / (1.0e-6 + sigma6) / (1.0e-6 + sigma6);
      accumulator += omega13p;
      omega7p /= accumulator;
      omega8p /= accumulator;
      omega9p /= accumulator;
      omega10p /= accumulator;
      omega11p /= accumulator;
      omega12p /= accumulator;
      omega13p /= accumulator;
      accumulator = 0.0;
      omega7m = +0.0109411603419312 / +1.0164117405129 / (1.0e-6 + sigma0) / (1.0e-6 + sigma0);
      accumulator += omega7m;
      omega8m = +0.131451934675126 / +1.0164117405129 / (1.0e-6 + sigma1) / (1.0e-6 + sigma1);
      accumulator += omega8m;
      omega9m = +0.284316929681562 / +1.0164117405129 / (1.0e-6 + sigma2) / (1.0e-6 + sigma2);
      accumulator += omega9m;
      omega10m = +0.377795271597879 / +1.0164117405129 / (1.0e-6 + sigma3) / (1.0e-6 + sigma3);
      accumulator += omega10m;
      omega11m = +0.182461683746224 / +1.0164117405129 / (1.0e-6 + sigma4) / (1.0e-6 + sigma4);
      accumulator += omega11m;
      omega12m = +0.0284914951519104 / +1.0164117405129 / (1.0e-6 + sigma5) / (1.0e-6 + sigma5);
      accumulator += omega12m;
      omega13m = +0.000953265318263936 / +1.0164117405129 / (1.0e-6 + sigma6) / (1.0e-6 + sigma6);
      accumulator += omega13m;
      omega7m /= accumulator;
      omega8m /= accumulator;
      omega9m /= accumulator;
      omega10m /= accumulator;
      omega11m /= accumulator;
      omega12m /= accumulator;
      omega13m /= accumulator;
      accumulator = 0.0;
      omega14 = +0.00244346113386661 / (1.0e-6 + sigma0) / (1.0e-6 + sigma0);
      accumulator += omega14;
      omega15 = +0.0539730663452662 / (1.0e-6 + sigma1) / (1.0e-6 + sigma1);
      accumulator += omega15;
      omega16 = +0.265729088328229 / (1.0e-6 + sigma2) / (1.0e-6 + sigma2);
      accumulator += omega16;
      omega17 = +0.415927096688649 / (1.0e-6 + sigma3) / (1.0e-6 + sigma3);
      accumulator += omega17;
      omega18 = +0.223204605356455 / (1.0e-6 + sigma4) / (1.0e-6 + sigma4);
      accumulator += omega18;
      omega19 = +0.0373811874243024 / (1.0e-6 + sigma5) / (1.0e-6 + sigma5);
      accumulator += omega19;
      omega20 = +0.00134149472323173 / (1.0e-6 + sigma6) / (1.0e-6 + sigma6);
      accumulator += omega20;
      omega14 /= accumulator;
      omega15 /= accumulator;
      omega16 /= accumulator;
      omega17 /= accumulator;
      omega18 /= accumulator;
      omega19 /= accumulator;
      omega20 /= accumulator;
      f0 =
	+2.59285714285714 * f[(i + 0) * fsi] - 4.40714285714286 * f[(i + 1) * fsi] +
	6.09285714285714 * f[(i + 2) * fsi] - 5.57380952380952 * f[(i + 3) * fsi] +
	3.17619047619048 * f[(i + 4) * fsi] - 1.02380952380952 * f[(i + 5) * fsi] +
	0.142857142857143 * f[(i + 6) * fsi];
      f1 =
	+0.142857142857143 * f[(i - 1) * fsi] + 1.59285714285714 * f[(i + 0) * fsi] -
	1.40714285714286 * f[(i + 1) * fsi] + 1.09285714285714 * f[(i + 2) * fsi] -
	0.573809523809524 * f[(i + 3) * fsi] + 0.176190476190476 * f[(i + 4) * fsi] -
	0.0238095238095238 * f[(i + 5) * fsi];
      f2 =
	-0.0238095238095238 * f[(i - 2) * fsi] + 0.30952380952381 * f[(i - 1) * fsi] +
	1.09285714285714 * f[(i + 0) * fsi] - 0.573809523809524 * f[(i + 1) * fsi] +
	0.25952380952381 * f[(i + 2) * fsi] - 0.0738095238095238 * f[(i + 3) * fsi] +
	0.00952380952380952 * f[(i + 4) * fsi];
      f3 =
	+0.00952380952380952 * f[(i - 3) * fsi] - 0.0904761904761905 * f[(i - 2) * fsi] +
	0.509523809523809 * f[(i - 1) * fsi] + 0.759523809523809 * f[(i + 0) * fsi] -
	0.24047619047619 * f[(i + 1) * fsi] + 0.0595238095238095 * f[(i + 2) * fsi] -
	0.00714285714285714 * f[(i + 3) * fsi];
      f4 =
	-0.00714285714285714 * f[(i - 4) * fsi] + 0.0595238095238095 * f[(i - 3) * fsi] -
	0.24047619047619 * f[(i - 2) * fsi] + 0.759523809523809 * f[(i - 1) * fsi] +
	0.509523809523809 * f[(i + 0) * fsi] - 0.0904761904761905 * f[(i + 1) * fsi] +
	0.00952380952380952 * f[(i + 2) * fsi];
      f5 =
	+0.00952380952380952 * f[(i - 5) * fsi] - 0.0738095238095238 * f[(i - 4) * fsi] +
	0.25952380952381 * f[(i - 3) * fsi] - 0.573809523809524 * f[(i - 2) * fsi] +
	1.09285714285714 * f[(i - 1) * fsi] + 0.30952380952381 * f[(i + 0) * fsi] -
	0.0238095238095238 * f[(i + 1) * fsi];
      f6 =
	-0.0238095238095238 * f[(i - 6) * fsi] + 0.176190476190476 * f[(i - 5) * fsi] -
	0.573809523809524 * f[(i - 4) * fsi] + 1.09285714285714 * f[(i - 3) * fsi] -
	1.40714285714286 * f[(i - 2) * fsi] + 1.59285714285714 * f[(i - 1) * fsi] +
	0.142857142857143 * f[(i + 0) * fsi];
      f7 =
	+1.18583582509627 * f[(i + 0) * fsi] - 0.194720745343283 * f[(i + 1) * fsi] -
	0.0815275290782099 * f[(i + 2) * fsi] + 0.182965290799547 * f[(i + 3) * fsi] -
	0.134002826504405 * f[(i + 4) * fsi] + 0.0487576473400965 * f[(i + 5) * fsi] -
	0.00730766231002045 * f[(i + 6) * fsi];
      f8 =
	-0.00730766231002045 * f[(i - 1) * fsi] + 1.23698946126642 * f[(i + 0) * fsi] -
	0.348181653853712 * f[(i + 1) * fsi] + 0.174240651772507 * f[(i + 2) * fsi] -
	0.0728028900511679 * f[(i + 3) * fsi] + 0.0194580820060246 * f[(i + 4) * fsi] -
	0.00239598883004698 * f[(i + 5) * fsi];
      f9 =
	-0.00239598883004698 * f[(i - 2) * fsi] + 0.00946425950030844 * f[(i - 1) * fsi] +
	1.18667369583543 * f[(i + 0) * fsi] - 0.264322044802068 * f[(i + 1) * fsi] +
	0.0903810427208629 * f[(i + 2) * fsi] - 0.0224871246201814 * f[(i + 3) * fsi] +
	0.00268616019569572 * f[(i + 4) * fsi];
      f10 =
	+0.00268616019569572 * f[(i - 3) * fsi] - 0.021199110199917 * f[(i - 2) * fsi] +
	0.0658736236099184 * f[(i - 1) * fsi] + 1.09265808898608 * f[(i + 0) * fsi] -
	0.170306437952718 * f[(i + 1) * fsi] + 0.0339716786112528 * f[(i + 2) * fsi] -
	0.00368400325031137 * f[(i + 3) * fsi];
      f11 =
	-0.00368400325031137 * f[(i - 4) * fsi] + 0.0284741829478753 * f[(i - 3) * fsi] -
	0.0985631784564558 * f[(i - 2) * fsi] + 0.194813737370817 * f[(i - 1) * fsi] +
	0.963717975225181 * f[(i + 0) * fsi] - 0.0929423696961789 * f[(i + 1) * fsi] +
	0.0081836558590732 * f[(i + 2) * fsi];
      f12 =
	+0.0081836558590732 * f[(i - 5) * fsi] - 0.0609695942638237 * f[(i - 4) * fsi] +
	0.200330955988412 * f[(i - 3) * fsi] - 0.384991133524018 * f[(i - 2) * fsi] +
	0.481241692438378 * f[(i - 1) * fsi] + 0.791861202184644 * f[(i + 0) * fsi] -
	0.0356567786826665 * f[(i + 1) * fsi];
      f13 =
	-0.0356567786826665 * f[(i - 6) * fsi] + 0.257781106637739 * f[(i - 5) * fsi] -
	0.80976194659982 * f[(i - 4) * fsi] + 1.44831820988174 * f[(i - 3) * fsi] -
	1.63297838741734 * f[(i - 2) * fsi] + 1.23003404477437 * f[(i - 1) * fsi] +
	0.542263751405978 * f[(i + 0) * fsi];
      f14 =
	+0.27690932728468 * f[(i + 0) * fsi] + 1.56533049772423 * f[(i + 1) * fsi] -
	1.68579851854084 * f[(i + 2) * fsi] + 1.39400499491474 * f[(i + 3) * fsi] -
	0.75355988778131 * f[(i + 4) * fsi] + 0.23524143837419 * f[(i + 5) * fsi] -
	0.0321278519756938 * f[(i + 6) * fsi];
      f15 =
	-0.0321278519756937 * f[(i - 1) * fsi] + 0.501804291114537 * f[(i + 0) * fsi] +
	0.890645606234664 * f[(i + 1) * fsi] - 0.561323699391555 * f[(i + 2) * fsi] +
	0.269530175765454 * f[(i + 3) * fsi] - 0.0788749962917388 * f[(i + 4) * fsi] +
	0.0103464745443327 * f[(i + 5) * fsi];
      f16 =
	+0.0103464745443327 * f[(i - 2) * fsi] - 0.104553173786023 * f[(i - 1) * fsi] +
	0.719080256545523 * f[(i + 0) * fsi] + 0.52851899718302 * f[(i + 1) * fsi] -
	0.19919709033991 * f[(i + 2) * fsi] + 0.0522542103344671 * f[(i + 3) * fsi] -
	0.00644967448141001 * f[(i + 4) * fsi];
      f17 =
	-0.00644967448141001 * f[(i - 3) * fsi] + 0.0554941959142027 * f[(i - 2) * fsi] -
	0.239996337895633 * f[(i - 1) * fsi] + 0.944818863394873 * f[(i + 0) * fsi] +
	0.30278039033367 * f[(i + 1) * fsi] - 0.0637539262303004 * f[(i + 2) * fsi] +
	0.00710648896459709 * f[(i + 3) * fsi];
      f18 =
	+0.00710648896459709 * f[(i - 4) * fsi] - 0.0561950972335896 * f[(i - 3) * fsi] +
	0.204730464170742 * f[(i - 2) * fsi] - 0.488723451656531 * f[(i - 1) * fsi] +
	1.19354597715577 * f[(i + 0) * fsi] + 0.153544122077131 * f[(i + 1) * fsi] -
	0.0140085034781208 * f[(i + 2) * fsi];
      f19 =
	-0.0140085034781208 * f[(i - 5) * fsi] + 0.105166013311443 * f[(i - 4) * fsi] -
	0.350373670274127 * f[(i - 3) * fsi] + 0.69502808590497 * f[(i - 2) * fsi] -
	0.97902107339076 * f[(i - 1) * fsi] + 1.48772455019631 * f[(i + 0) * fsi] +
	0.0554845977302855 * f[(i + 1) * fsi];
      f20 =
	+0.0554845977302855 * f[(i - 6) * fsi] - 0.40240068759012 * f[(i - 5) * fsi] +
	1.27034256564744 * f[(i - 4) * fsi] - 2.29233459083412 * f[(i - 3) * fsi] +
	2.63698900646496 * f[(i - 2) * fsi] - 2.14419762572676 * f[(i - 1) * fsi] +
	1.87611673430831 * f[(i + 0) * fsi];
      fr0 =
	f0 * omega0 + f1 * omega1 + f2 * omega2 + f3 * omega3 + f4 * omega4 + f5 * omega5 +
	f6 * omega6;
      fr1 =
	+2.0164117405129 * (f7 * omega7p + f8 * omega8p + f9 * omega9p + f10 * omega10p +
			    f11 * omega11p + f12 * omega12p + f13 * omega13p) -
	+1.0164117405129 * (f7 * omega7m + f8 * omega8m + f9 * omega9m + f10 * omega10m +
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
py_gauss_radau007003 (PyObject * self, PyObject * args)
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

  gauss_radau007003 (f, n, fsi, sigma, ssi, ssr, fr, frsi, frsl);

  Py_INCREF (Py_None);
  return Py_None;
}
