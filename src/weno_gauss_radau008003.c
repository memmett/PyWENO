#include <Python.h>
#include <numpy/ndarrayobject.h>

void
gauss_radau008003 (const double *restrict f, int n, int fsi,
		   const double *restrict sigma, int ssi, int ssr,
		   double *restrict fr, int frsi, int frsl)
{
  int i;
  double sigma0, sigma1, sigma2, sigma3, sigma4, sigma5, sigma6, sigma7, omega8p, omega11m, omega7,
    omega8m, omega11p, omega3, omega21, omega12p, omega16, omega15m, omega12m, omega15p, omega4,
    omega10p, omega10m, omega22, omega0, omega18, omega23, omega5, omega17, omega14p, omega20,
    omega9m, omega14m, omega1, omega9p, omega2, omega6, omega13m, omega19, omega13p, accumulator,
    f11, f7, f22, f14, f21, f3, f10, f16, f13, f18, f9, f23, f0, f4, f12, f19, f17, f8, f1, f2, f6,
    f15, f5, f20, fr0, fr1, fr2;
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
      omega8p = +0.00109375892223548 / +2.0032812767667 / (1.0e-6 + sigma0) / (1.0e-6 + sigma0);
      accumulator += omega8p;
      omega9p = +0.141125619325814 / +2.0032812767667 / (1.0e-6 + sigma1) / (1.0e-6 + sigma1);
      accumulator += omega9p;
      omega10p = +0.354679295420611 / +2.0032812767667 / (1.0e-6 + sigma2) / (1.0e-6 + sigma2);
      accumulator += omega10p;
      omega11p = +0.711916149941159 / +2.0032812767667 / (1.0e-6 + sigma3) / (1.0e-6 + sigma3);
      accumulator += omega11p;
      omega12p = +0.582083011083061 / +2.0032812767667 / (1.0e-6 + sigma4) / (1.0e-6 + sigma4);
      accumulator += omega12p;
      omega13p = +0.190445380066796 / +2.0032812767667 / (1.0e-6 + sigma5) / (1.0e-6 + sigma5);
      accumulator += omega13p;
      omega14p = +0.0213988057213385 / +2.0032812767667 / (1.0e-6 + sigma6) / (1.0e-6 + sigma6);
      accumulator += omega14p;
      omega15p = +0.00053925628568775 / +2.0032812767667 / (1.0e-6 + sigma7) / (1.0e-6 + sigma7);
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
      omega8m = +0.00218751784447095 / +1.0032812767667 / (1.0e-6 + sigma0) / (1.0e-6 + sigma0);
      accumulator += omega8m;
      omega9m = +0.0705628096629069 / +1.0032812767667 / (1.0e-6 + sigma1) / (1.0e-6 + sigma1);
      accumulator += omega9m;
      omega10m = +0.177339647710306 / +1.0032812767667 / (1.0e-6 + sigma2) / (1.0e-6 + sigma2);
      accumulator += omega10m;
      omega11m = +0.355958074970579 / +1.0032812767667 / (1.0e-6 + sigma3) / (1.0e-6 + sigma3);
      accumulator += omega11m;
      omega12m = +0.29104150554153 / +1.0032812767667 / (1.0e-6 + sigma4) / (1.0e-6 + sigma4);
      accumulator += omega12m;
      omega13m = +0.095222690033398 / +1.0032812767667 / (1.0e-6 + sigma5) / (1.0e-6 + sigma5);
      accumulator += omega13m;
      omega14m = +0.0106994028606693 / +1.0032812767667 / (1.0e-6 + sigma6) / (1.0e-6 + sigma6);
      accumulator += omega14m;
      omega15m = +0.000269628142843875 / +1.0032812767667 / (1.0e-6 + sigma7) / (1.0e-6 + sigma7);
      accumulator += omega15m;
      omega8m /= accumulator;
      omega9m /= accumulator;
      omega10m /= accumulator;
      omega11m /= accumulator;
      omega12m /= accumulator;
      omega13m /= accumulator;
      omega14m /= accumulator;
      omega15m /= accumulator;
      accumulator = 0.0;
      omega16 = +0.000718852710055079 / (1.0e-6 + sigma0) / (1.0e-6 + sigma0);
      accumulator += omega16;
      omega17 = +0.0214258264318814 / (1.0e-6 + sigma1) / (1.0e-6 + sigma1);
      accumulator += omega17;
      omega18 = +0.150117942512999 / (1.0e-6 + sigma2) / (1.0e-6 + sigma2);
      accumulator += omega18;
      omega19 = +0.360709294955485 / (1.0e-6 + sigma3) / (1.0e-6 + sigma3);
      accumulator += omega19;
      omega20 = +0.334049312325765 / (1.0e-6 + sigma4) / (1.0e-6 + sigma4);
      accumulator += omega20;
      omega21 = +0.118490035341196 / (1.0e-6 + sigma5) / (1.0e-6 + sigma5);
      accumulator += omega21;
      omega22 = +0.0141085978594981 / (1.0e-6 + sigma6) / (1.0e-6 + sigma6);
      accumulator += omega22;
      omega23 = +0.000380137863128136 / (1.0e-6 + sigma7) / (1.0e-6 + sigma7);
      accumulator += omega23;
      omega16 /= accumulator;
      omega17 /= accumulator;
      omega18 /= accumulator;
      omega19 /= accumulator;
      omega20 /= accumulator;
      omega21 /= accumulator;
      omega22 /= accumulator;
      omega23 /= accumulator;
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
	+1.17740439138502 * f[(i + 0) * fsi] - 0.135700709364532 * f[(i + 1) * fsi] -
	0.258587637014463 * f[(i + 2) * fsi] + 0.478065470693301 * f[(i + 3) * fsi] -
	0.429103006398158 * f[(i + 4) * fsi] + 0.225817755276349 * f[(i + 5) * fsi] -
	0.0663276982887714 * f[(i + 6) * fsi] + 0.00843143371125013 * f[(i + 7) * fsi];
      f9 =
	-0.00843143371125016 * f[(i - 1) * fsi] + 1.24485586107502 * f[(i + 0) * fsi] -
	0.371780853279535 * f[(i + 1) * fsi] + 0.213572650815546 * f[(i + 2) * fsi] -
	0.112134889094207 * f[(i + 3) * fsi] + 0.0430572814318479 * f[(i + 4) * fsi] -
	0.0102623886386548 * f[(i + 5) * fsi] + 0.00112377140122968 * f[(i + 6) * fsi];
      f10 =
	-0.00112377140122968 * f[(i - 2) * fsi] + 0.000558737498587314 * f[(i - 1) * fsi] +
	1.21339026184059 * f[(i + 0) * fsi] - 0.308849654810673 * f[(i + 1) * fsi] +
	0.134908652729468 * f[(i + 2) * fsi] - 0.0492036906253447 * f[(i + 3) * fsi] +
	0.0115916821974168 * f[(i + 4) * fsi] - 0.0012722174288173 * f[(i + 5) * fsi];
      f11 =
	+0.0012722174288173 * f[(i - 3) * fsi] - 0.0113015108317681 * f[(i - 2) * fsi] +
	0.0361808255054718 * f[(i - 1) * fsi] + 1.14214608582682 * f[(i + 0) * fsi] -
	0.219794434793462 * f[(i + 1) * fsi] + 0.0636644767156996 * f[(i + 2) * fsi] -
	0.0135816026184603 * f[(i + 3) * fsi] + 0.00141394276687842 * f[(i + 4) * fsi];
      f12 =
	-0.00141394276687842 * f[(i - 4) * fsi] + 0.0125837595638446 * f[(i - 3) * fsi] -
	0.0508919083043638 * f[(i - 2) * fsi] + 0.115361620450663 * f[(i - 1) * fsi] +
	1.04317009214533 * f[(i + 0) * fsi] - 0.140613639848271 * f[(i + 1) * fsi] +
	0.0240740792431039 * f[(i + 2) * fsi] - 0.00227006048343295 * f[(i + 3) * fsi];
      f13 =
	+0.00227006048343295 * f[(i - 5) * fsi] - 0.019574426634342 * f[(i - 4) * fsi] +
	0.0761454530999673 * f[(i - 3) * fsi] - 0.178015295376609 * f[(i - 2) * fsi] +
	0.27426585429097 * f[(i - 1) * fsi] + 0.916046705073089 * f[(i + 0) * fsi] -
	0.0770519463121482 * f[(i + 1) * fsi] + 0.00591359537564024 * f[(i + 2) * fsi];
      f14 =
	-0.00591359537564024 * f[(i - 6) * fsi] + 0.0495788234885549 * f[(i - 5) * fsi] -
	0.185155097152269 * f[(i - 4) * fsi] + 0.407306794135821 * f[(i - 3) * fsi] -
	0.591966971671426 * f[(i - 2) * fsi] + 0.605427195326823 * f[(i - 1) * fsi] +
	0.750466034555162 * f[(i + 0) * fsi] - 0.0297431833070262 * f[(i + 1) * fsi];
      f15 =
	+0.0297431833070262 * f[(i - 7) * fsi] - 0.24385906183185 * f[(i - 6) * fsi] +
	0.88238795608529 * f[(i - 5) * fsi] - 1.85077336234574 * f[(i - 4) * fsi] +
	2.48932962562766 * f[(i - 3) * fsi] - 2.2575852368649 * f[(i - 2) * fsi] +
	1.43823632792356 * f[(i - 1) * fsi] + 0.512520568098952 * f[(i + 0) * fsi];
      f16 =
	+0.251644169567359 * f[(i + 0) * fsi] + 1.74218660174548 * f[(i + 1) * fsi] -
	2.21636683060458 * f[(i + 2) * fsi] + 2.27828551502098 * f[(i + 3) * fsi] -
	1.63784040788755 * f[(i + 4) * fsi] + 0.765809750437934 * f[(i + 5) * fsi] -
	0.208983955996942 * f[(i + 6) * fsi] + 0.0252651577173212 * f[(i + 7) * fsi];
      f17 =
	-0.0252651577173212 * f[(i - 1) * fsi] + 0.453765431305928 * f[(i + 0) * fsi] +
	1.03476218566049 * f[(i + 1) * fsi] - 0.801517998434594 * f[(i + 2) * fsi] +
	0.509724474808493 * f[(i + 3) * fsi] - 0.222991575717562 * f[(i + 4) * fsi] +
	0.0583853343529405 * f[(i + 5) * fsi] - 0.00686269425837254 * f[(i + 6) * fsi];
      f18 =
	+0.00686269425837255 * f[(i - 2) * fsi] - 0.0801667117843013 * f[(i - 1) * fsi] +
	0.64592087054036 * f[(i + 0) * fsi] + 0.650451307191626 * f[(i + 1) * fsi] -
	0.321129400348516 * f[(i + 2) * fsi] + 0.12541359633963 * f[(i + 3) * fsi] -
	0.0308361364831311 * f[(i + 4) * fsi] + 0.00348378028596016 * f[(i + 5) * fsi];
      f19 =
	-0.00348378028596016 * f[(i - 3) * fsi] + 0.0347329365460538 * f[(i - 2) * fsi] -
	0.177712559791186 * f[(i - 1) * fsi] + 0.841012566554129 * f[(i + 0) * fsi] +
	0.406586687174415 * f[(i + 1) * fsi] - 0.126037704334747 * f[(i + 2) * fsi] +
	0.027867748332746 * f[(i + 3) * fsi] - 0.00296589419544985 * f[(i + 4) * fsi];
      f20 =
	+0.00296589419544985 * f[(i - 4) * fsi] - 0.0272109338495589 * f[(i - 3) * fsi] +
	0.11777797401865 * f[(i - 2) * fsi] - 0.343802634736378 * f[(i - 1) * fsi] +
	1.04862516023562 * f[(i + 0) * fsi] + 0.240496612229223 * f[(i + 1) * fsi] -
	0.0429926668621515 * f[(i + 2) * fsi] + 0.00414059476914724 * f[(i + 3) * fsi];
      f21 =
	-0.00414059476914724 * f[(i - 5) * fsi] + 0.0360906523486278 * f[(i - 4) * fsi] -
	0.143147587385682 * f[(i - 3) * fsi] + 0.349651281090895 * f[(i - 2) * fsi] -
	0.633644268576684 * f[(i - 1) * fsi] + 1.28049846730786 * f[(i + 0) * fsi] +
	0.124559958693101 * f[(i + 1) * fsi] - 0.00986790870897358 * f[(i + 2) * fsi];
      f22 =
	+0.00986790870897358 * f[(i - 6) * fsi] - 0.0830838644409358 * f[(i - 5) * fsi] +
	0.312392096199888 * f[(i - 4) * fsi] - 0.695750475088202 * f[(i - 3) * fsi] +
	1.04040489071905 * f[(i - 2) * fsi] - 1.1862471562792 * f[(i - 1) * fsi] +
	1.55679991115912 * f[(i + 0) * fsi] + 0.045616689021312 * f[(i + 1) * fsi];
      f23 =
	-0.045616689021312 * f[(i - 7) * fsi] + 0.374801420879469 * f[(i - 6) * fsi] -
	1.36035115703767 * f[(i - 5) * fsi] + 2.86692668139336 * f[(i - 4) * fsi] -
	3.88891870658004 * f[(i - 3) * fsi] + 3.59493947591252 * f[(i - 2) * fsi] -
	2.46351444887594 * f[(i - 1) * fsi] + 1.92173342332962 * f[(i + 0) * fsi];
      fr0 =
	f0 * omega0 + f1 * omega1 + f2 * omega2 + f3 * omega3 + f4 * omega4 + f5 * omega5 +
	f6 * omega6 + f7 * omega7;
      fr1 =
	+2.0032812767667 * (f8 * omega8p + f9 * omega9p + f10 * omega10p + f11 * omega11p +
			    f12 * omega12p + f13 * omega13p + f14 * omega14p + f15 * omega15p) -
	+1.0032812767667 * (f8 * omega8m + f9 * omega9m + f10 * omega10m + f11 * omega11m +
			    f12 * omega12m + f13 * omega13m + f14 * omega14m + f15 * omega15m);
      fr2 =
	f16 * omega16 + f17 * omega17 + f18 * omega18 + f19 * omega19 + f20 * omega20 +
	f21 * omega21 + f22 * omega22 + f23 * omega23;
      fr[i * frsi + 0 * frsl] = fr0;
      fr[i * frsi + 1 * frsl] = fr1;
      fr[i * frsi + 2 * frsl] = fr2;
    }
}

PyObject *
py_gauss_radau008003 (PyObject * self, PyObject * args)
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

  gauss_radau008003 (f, n, fsi, sigma, ssi, ssr, fr, frsi, frsl);

  Py_INCREF (Py_None);
  return Py_None;
}
