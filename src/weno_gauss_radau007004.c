#include <Python.h>
#include <numpy/ndarrayobject.h>

void
gauss_radau007004 (const double *restrict f, int n, int fsi,
		   const double *restrict sigma, int ssi, int ssr,
		   double *restrict fr, int frsi, int frsl)
{
  int i;
  double sigma0, sigma1, sigma2, sigma3, sigma4, sigma5, sigma6, omega10, omega21, omega18m,
    omega13, omega17p, omega3, omega16p, omega17m, omega9, omega18p, omega22, omega24, omega12,
    omega14m, omega4, omega14p, omega23, omega0, omega27, omega19p, omega20m, omega11, omega19m,
    omega20p, omega5, omega7, omega26, omega1, omega15p, omega16m, omega15m, omega8, omega6,
    omega25, omega2, accumulator, f10, f21, f15, f20, f13, f19, f3, f9, f24, f14, f12, f27, f16, f8,
    f23, f0, f4, f11, f17, f7, f26, f1, f22, f2, f6, f5, f25, f18, fr0, fr1, fr2, fr3;
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
      omega7 = +0.00205563150300911 / (1.0e-6 + sigma0) / (1.0e-6 + sigma0);
      accumulator += omega7;
      omega8 = +0.0449810399929134 / (1.0e-6 + sigma1) / (1.0e-6 + sigma1);
      accumulator += omega8;
      omega9 = +0.240709291686706 / (1.0e-6 + sigma2) / (1.0e-6 + sigma2);
      accumulator += omega9;
      omega10 = +0.415044811419464 / (1.0e-6 + sigma3) / (1.0e-6 + sigma3);
      accumulator += omega10;
      omega11 = +0.248081820248601 / (1.0e-6 + sigma4) / (1.0e-6 + sigma4);
      accumulator += omega11;
      omega12 = +0.047154973027625 / (1.0e-6 + sigma5) / (1.0e-6 + sigma5);
      accumulator += omega12;
      omega13 = +0.00197243212168181 / (1.0e-6 + sigma6) / (1.0e-6 + sigma6);
      accumulator += omega13;
      omega7 /= accumulator;
      omega8 /= accumulator;
      omega9 /= accumulator;
      omega10 /= accumulator;
      omega11 /= accumulator;
      omega12 /= accumulator;
      omega13 /= accumulator;
      accumulator = 0.0;
      omega14p = +0.0011571752950611 / +4.60510041775139 / (1.0e-6 + sigma0) / (1.0e-6 + sigma0);
      accumulator += omega14p;
      omega15p = +0.0379434063031336 / +4.60510041775139 / (1.0e-6 + sigma1) / (1.0e-6 + sigma1);
      accumulator += omega15p;
      omega16p = +0.262064845655614 / +4.60510041775139 / (1.0e-6 + sigma2) / (1.0e-6 + sigma2);
      accumulator += omega16p;
      omega17p = +0.557265501845393 / +4.60510041775139 / (1.0e-6 + sigma3) / (1.0e-6 + sigma3);
      accumulator += omega17p;
      omega18p = +2.87830268273507 / +4.60510041775139 / (1.0e-6 + sigma4) / (1.0e-6 + sigma4);
      accumulator += omega18p;
      omega19p = +0.866776957038973 / +4.60510041775139 / (1.0e-6 + sigma5) / (1.0e-6 + sigma5);
      accumulator += omega19p;
      omega20p = +0.00158984887815163 / +4.60510041775139 / (1.0e-6 + sigma6) / (1.0e-6 + sigma6);
      accumulator += omega20p;
      omega14p /= accumulator;
      omega15p /= accumulator;
      omega16p /= accumulator;
      omega17p /= accumulator;
      omega18p /= accumulator;
      omega19p /= accumulator;
      omega20p /= accumulator;
      accumulator = 0.0;
      omega14m = +0.000578587647530549 / +3.60510041775138 / (1.0e-6 + sigma0) / (1.0e-6 + sigma0);
      accumulator += omega14m;
      omega15m = +0.0189717031515668 / +3.60510041775138 / (1.0e-6 + sigma1) / (1.0e-6 + sigma1);
      accumulator += omega15m;
      omega16m = +0.131032422827807 / +3.60510041775138 / (1.0e-6 + sigma2) / (1.0e-6 + sigma2);
      accumulator += omega16m;
      omega17m = +0.278632750922697 / +3.60510041775138 / (1.0e-6 + sigma3) / (1.0e-6 + sigma3);
      accumulator += omega17m;
      omega18m = +1.43915134136753 / +3.60510041775138 / (1.0e-6 + sigma4) / (1.0e-6 + sigma4);
      accumulator += omega18m;
      omega19m = +1.73355391407795 / +3.60510041775138 / (1.0e-6 + sigma5) / (1.0e-6 + sigma5);
      accumulator += omega19m;
      omega20m = +0.00317969775630325 / +3.60510041775138 / (1.0e-6 + sigma6) / (1.0e-6 + sigma6);
      accumulator += omega20m;
      omega14m /= accumulator;
      omega15m /= accumulator;
      omega16m /= accumulator;
      omega17m /= accumulator;
      omega18m /= accumulator;
      omega19m /= accumulator;
      omega20m /= accumulator;
      accumulator = 0.0;
      omega21 = +0.00306588409840069 / (1.0e-6 + sigma0) / (1.0e-6 + sigma0);
      accumulator += omega21;
      omega22 = +0.0620046328863957 / (1.0e-6 + sigma1) / (1.0e-6 + sigma1);
      accumulator += omega22;
      omega23 = +0.283882520229667 / (1.0e-6 + sigma2) / (1.0e-6 + sigma2);
      accumulator += omega23;
      omega24 = +0.413957245864592 / (1.0e-6 + sigma3) / (1.0e-6 + sigma3);
      accumulator += omega24;
      omega25 = +0.205231039256657 / (1.0e-6 + sigma4) / (1.0e-6 + sigma4);
      accumulator += omega25;
      omega26 = +0.0309460867691462 / (1.0e-6 + sigma5) / (1.0e-6 + sigma5);
      accumulator += omega26;
      omega27 = +0.000912590895159414 / (1.0e-6 + sigma6) / (1.0e-6 + sigma6);
      accumulator += omega27;
      omega21 /= accumulator;
      omega22 /= accumulator;
      omega23 /= accumulator;
      omega24 /= accumulator;
      omega25 /= accumulator;
      omega26 /= accumulator;
      omega27 /= accumulator;
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
	+1.65373819140628 * f[(i + 0) * fsi] - 1.48545794431326 * f[(i + 1) * fsi] +
	1.6811546742347 * f[(i + 2) * fsi] - 1.40648507704608 * f[(i + 3) * fsi] +
	0.762868113756635 * f[(i + 4) * fsi] - 0.238379658424392 * f[(i + 5) * fsi] +
	0.0325617003861114 * f[(i + 6) * fsi];
      f8 =
	+0.0325617003861115 * f[(i - 1) * fsi] + 1.4258062887035 * f[(i + 0) * fsi] -
	0.801662236204918 * f[(i + 1) * fsi] + 0.541495160720797 * f[(i + 2) * fsi] -
	0.266825563532177 * f[(i + 3) * fsi] + 0.0790724056482944 * f[(i + 4) * fsi] -
	0.0104477557216116 * f[(i + 5) * fsi];
      f9 =
	-0.0104477557216116 * f[(i - 2) * fsi] + 0.105695990437393 * f[(i - 1) * fsi] +
	1.20640341854966 * f[(i + 0) * fsi] - 0.43599078594851 * f[(i + 1) * fsi] +
	0.17582371046439 * f[(i + 2) * fsi] - 0.0474226933783331 * f[(i + 3) * fsi] +
	0.00593811559701302 * f[(i + 4) * fsi];
      f10 =
	+0.00593811559701303 * f[(i - 3) * fsi] - 0.0520145649007028 * f[(i - 2) * fsi] +
	0.230396417974666 * f[(i - 1) * fsi] + 0.998569372654204 * f[(i + 0) * fsi] -
	0.228156740053055 * f[(i + 1) * fsi] + 0.0511232829271166 * f[(i + 2) * fsi] -
	0.0058558841992419 * f[(i + 3) * fsi];
      f11 =
	-0.0058558841992419 * f[(i - 4) * fsi] + 0.0469293049917063 * f[(i - 3) * fsi] -
	0.174988133084783 * f[(i - 2) * fsi] + 0.435352364948133 * f[(i - 1) * fsi] +
	0.793613425680737 * f[(i + 0) * fsi] - 0.105183171868975 * f[(i + 1) * fsi] +
	0.0101320935324233 * f[(i + 2) * fsi];
      f12 =
	+0.0101320935324233 * f[(i - 5) * fsi] - 0.0767805389262049 * f[(i - 4) * fsi] +
	0.259703269172595 * f[(i - 3) * fsi] - 0.529611406719598 * f[(i - 2) * fsi] +
	0.789975638582948 * f[(i - 1) * fsi] + 0.580839461499848 * f[(i + 0) * fsi] -
	0.0342585171420118 * f[(i + 1) * fsi];
      f13 =
	-0.0342585171420118 * f[(i - 6) * fsi] + 0.249941713526506 * f[(i - 5) * fsi] -
	0.796209398908453 * f[(i - 4) * fsi] + 1.45875136914301 * f[(i - 3) * fsi] -
	1.72865950669001 * f[(i - 2) * fsi] + 1.5094044985652 * f[(i - 1) * fsi] +
	0.341029841505765 * f[(i + 0) * fsi];
      f14 =
	+0.636780252246698 * f[(i + 0) * fsi] + 1.06087819756886 * f[(i + 1) * fsi] -
	1.50128090434496 * f[(i + 2) * fsi] + 1.35996708841202 * f[(i + 3) * fsi] -
	0.7682023864809 * f[(i + 4) * fsi] + 0.246021488221822 * f[(i + 5) * fsi] -
	0.0341637356235419 * f[(i + 6) * fsi];
      f15 =
	-0.0341637356235419 * f[(i - 1) * fsi] + 0.875926401611491 * f[(i + 0) * fsi] +
	0.343439749474478 * f[(i + 1) * fsi] - 0.305550157520989 * f[(i + 2) * fsi] +
	0.164236341588053 * f[(i + 3) * fsi] - 0.0507639383865186 * f[(i + 4) * fsi] +
	0.00687533885702825 * f[(i + 5) * fsi];
      f16 =
	+0.00687533885702825 * f[(i - 2) * fsi] - 0.0822911076227396 * f[(i - 1) * fsi] +
	1.02030851760908 * f[(i + 0) * fsi] + 0.102802889478489 * f[(i + 1) * fsi] -
	0.0649132975250005 * f[(i + 2) * fsi] + 0.0198542255904592 * f[(i + 3) * fsi] -
	0.00263656638732086 * f[(i + 4) * fsi];
      f17 =
	-0.00263656638732086 * f[(i - 3) * fsi] + 0.0253313035682743 * f[(i - 2) * fsi] -
	0.137659001756478 * f[(i - 1) * fsi] + 1.11258834116531 * f[(i + 0) * fsi] +
	0.0105230659222594 * f[(i + 1) * fsi] - 0.00954540339126263 * f[(i + 2) * fsi] +
	0.00139826087921316 * f[(i + 3) * fsi];
      f18 =
	+0.00139826087921315 * f[(i - 4) * fsi] - 0.0124243925418129 * f[(i - 3) * fsi] +
	0.0546947820317505 * f[(i - 2) * fsi] - 0.186598132528938 * f[(i - 1) * fsi] +
	1.16152747193777 * f[(i + 0) * fsi] - 0.0188404125412168 * f[(i + 1) * fsi] +
	0.000242422763229467 * f[(i + 2) * fsi];
      f19 =
	+0.000242422763229467 * f[(i - 5) * fsi] - 0.000298698463393102 * f[(i - 4) * fsi] -
	0.00733351451399405 * f[(i - 3) * fsi] + 0.046209985318719 * f[(i - 2) * fsi] -
	0.178113335815907 * f[(i - 1) * fsi] + 1.15643659390996 * f[(i + 0) * fsi] -
	0.0171434531986106 * f[(i + 1) * fsi];
      f20 =
	-0.0171434531986106 * f[(i - 6) * fsi] + 0.120246595153503 * f[(i - 5) * fsi] -
	0.360311215634215 * f[(i - 4) * fsi] + 0.592687347437376 * f[(i - 3) * fsi] -
	0.553810876632651 * f[(i - 2) * fsi] + 0.181899181354915 * f[(i - 1) * fsi] +
	1.03643242151968 * f[(i + 0) * fsi];
      f21 =
	+0.212871323082533 * f[(i + 0) * fsi] + 1.59712109714545 * f[(i + 1) * fsi] -
	1.59144868057038 * f[(i + 2) * fsi] + 1.2834280346183 * f[(i + 3) * fsi] -
	0.685675793942972 * f[(i + 4) * fsi] + 0.21261674160281 * f[(i + 5) * fsi] -
	0.0289127219357429 * f[(i + 6) * fsi];
      f22 =
	-0.028912721935743 * f[(i - 1) * fsi] + 0.415260376632734 * f[(i + 0) * fsi] +
	0.989953936494852 * f[(i + 1) * fsi] - 0.579503412819382 * f[(i + 2) * fsi] +
	0.2714827668673 * f[(i + 3) * fsi] - 0.0785086332923696 * f[(i + 4) * fsi] +
	0.0102276880526088 * f[(i + 5) * fsi];
      f23 =
	+0.0102276880526088 * f[(i - 2) * fsi] - 0.100506538304004 * f[(i - 1) * fsi] +
	0.630041825737518 * f[(i + 0) * fsi] + 0.631984854653545 * f[(i + 1) * fsi] -
	0.221534330978075 * f[(i + 2) * fsi] + 0.056701317762516 * f[(i + 3) * fsi] -
	0.00691481692410821 * f[(i + 4) * fsi];
      f24 =
	-0.00691481692410821 * f[(i - 3) * fsi] + 0.0586314065213663 * f[(i - 2) * fsi] -
	0.245717693710277 * f[(i - 1) * fsi] + 0.872060418081306 * f[(i + 0) * fsi] +
	0.389966262309757 * f[(i + 1) * fsi] - 0.0763231755718027 * f[(i + 2) * fsi] +
	0.00829759929375852 * f[(i + 3) * fsi];
      f25 =
	+0.00829759929375852 * f[(i - 4) * fsi] - 0.0649980119804178 * f[(i - 3) * fsi] +
	0.232880991690295 * f[(i - 2) * fsi] - 0.536133668991825 * f[(i - 1) * fsi] +
	1.16247639336285 * f[(i + 0) * fsi] + 0.215716677140828 * f[(i + 1) * fsi] -
	0.0182399805154931 * f[(i + 2) * fsi];
      f26 =
	-0.0182399805154931 * f[(i - 5) * fsi] + 0.13597746290221 * f[(i - 4) * fsi] -
	0.448037602805773 * f[(i - 3) * fsi] + 0.871280309732554 * f[(i - 2) * fsi] -
	1.17453298703408 * f[(i - 1) * fsi] + 1.54551598418821 * f[(i + 0) * fsi] +
	0.0880368135323764 * f[(i + 1) * fsi];
      f27 =
	+0.0880368135323764 * f[(i - 6) * fsi] - 0.634497675242128 * f[(i - 5) * fsi] +
	1.98475054708211 * f[(i - 4) * fsi] - 3.52932607643895 * f[(i - 3) * fsi] +
	3.95256878336573 * f[(i - 2) * fsi] - 3.02330607121399 * f[(i - 1) * fsi] +
	2.16177367891484 * f[(i + 0) * fsi];
      fr0 =
	f0 * omega0 + f1 * omega1 + f2 * omega2 + f3 * omega3 + f4 * omega4 + f5 * omega5 +
	f6 * omega6;
      fr1 =
	f7 * omega7 + f8 * omega8 + f9 * omega9 + f10 * omega10 + f11 * omega11 + f12 * omega12 +
	f13 * omega13;
      fr2 =
	+4.60510041775139 * (f14 * omega14p + f15 * omega15p + f16 * omega16p + f17 * omega17p +
			     f18 * omega18p + f19 * omega19p + f20 * omega20p) -
	+3.60510041775138 * (f14 * omega14m + f15 * omega15m + f16 * omega16m + f17 * omega17m +
			     f18 * omega18m + f19 * omega19m + f20 * omega20m);
      fr3 =
	f21 * omega21 + f22 * omega22 + f23 * omega23 + f24 * omega24 + f25 * omega25 +
	f26 * omega26 + f27 * omega27;
      fr[i * frsi + 0 * frsl] = fr0;
      fr[i * frsi + 1 * frsl] = fr1;
      fr[i * frsi + 2 * frsl] = fr2;
      fr[i * frsi + 3 * frsl] = fr3;
    }
}

PyObject *
py_gauss_radau007004 (PyObject * self, PyObject * args)
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

  gauss_radau007004 (f, n, fsi, sigma, ssi, ssr, fr, frsi, frsl);

  Py_INCREF (Py_None);
  return Py_None;
}
