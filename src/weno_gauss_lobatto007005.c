#include <Python.h>
#include <numpy/ndarrayobject.h>

void
gauss_lobatto007005 (const double *restrict f, int n, int fsi,
		     const double *restrict sigma, int ssi, int ssr,
		     double *restrict fr, int frsi, int frsl)
{
  int i;
  double sigma0, sigma1, sigma2, sigma3, sigma4, sigma5, sigma6, omega10, omega21, omega18m,
    omega13, omega17p, omega3, omega16p, omega17m, omega28, omega9, omega18p, omega22, omega24,
    omega32, omega12, omega14m, omega4, omega33, omega29, omega14p, omega23, omega0, omega27,
    omega19p, omega20m, omega11, omega19m, omega20p, omega5, omega30, omega7, omega26, omega1,
    omega15p, omega34, omega16m, omega15m, omega8, omega6, omega31, omega25, omega2, accumulator,
    f10, f21, f15, f20, f13, f19, f3, f28, f9, f24, f14, f32, f12, f27, f16, f29, f8, f23, f0, f33,
    f4, f11, f17, f30, f7, f26, f1, f34, f22, f2, f6, f31, f5, f25, f18, fr0, fr1, fr2, fr3, fr4;
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
      omega7 = +0.00150878923652102 / (1.0e-6 + sigma0) / (1.0e-6 + sigma0);
      accumulator += omega7;
      omega8 = +0.0394546263903746 / (1.0e-6 + sigma1) / (1.0e-6 + sigma1);
      accumulator += omega8;
      omega9 = +0.228348788654154 / (1.0e-6 + sigma2) / (1.0e-6 + sigma2);
      accumulator += omega9;
      omega10 = +0.415968769633897 / (1.0e-6 + sigma3) / (1.0e-6 + sigma3);
      accumulator += omega10;
      omega11 = +0.260549222547883 / (1.0e-6 + sigma4) / (1.0e-6 + sigma4);
      accumulator += omega11;
      omega12 = +0.0518767742445356 / (1.0e-6 + sigma5) / (1.0e-6 + sigma5);
      accumulator += omega12;
      omega13 = +0.00229302929263342 / (1.0e-6 + sigma6) / (1.0e-6 + sigma6);
      accumulator += omega13;
      omega7 /= accumulator;
      omega8 /= accumulator;
      omega9 /= accumulator;
      omega10 /= accumulator;
      omega11 /= accumulator;
      omega12 /= accumulator;
      omega13 /= accumulator;
      accumulator = 0.0;
      omega14p = +0.000149691116038702 / +3.94901979530886 / (1.0e-6 + sigma0) / (1.0e-6 + sigma0);
      accumulator += omega14p;
      omega15p = +0.0106349872873979 / +3.94901979530886 / (1.0e-6 + sigma1) / (1.0e-6 + sigma1);
      accumulator += omega15p;
      omega16p = +0.31405195414804 / +3.94901979530886 / (1.0e-6 + sigma2) / (1.0e-6 + sigma2);
      accumulator += omega16p;
      omega17p = +3.29934653020591 / +3.94901979530886 / (1.0e-6 + sigma3) / (1.0e-6 + sigma3);
      accumulator += omega17p;
      omega18p = +0.31405195414804 / +3.94901979530886 / (1.0e-6 + sigma4) / (1.0e-6 + sigma4);
      accumulator += omega18p;
      omega19p = +0.0106349872873979 / +3.94901979530886 / (1.0e-6 + sigma5) / (1.0e-6 + sigma5);
      accumulator += omega19p;
      omega20p = +0.000149691116038702 / +3.94901979530886 / (1.0e-6 + sigma6) / (1.0e-6 + sigma6);
      accumulator += omega20p;
      omega14p /= accumulator;
      omega15p /= accumulator;
      omega16p /= accumulator;
      omega17p /= accumulator;
      omega18p /= accumulator;
      omega19p /= accumulator;
      omega20p /= accumulator;
      accumulator = 0.0;
      omega14m = +0.000299382232077403 / +2.94901979530886 / (1.0e-6 + sigma0) / (1.0e-6 + sigma0);
      accumulator += omega14m;
      omega15m = +0.0212699745747958 / +2.94901979530886 / (1.0e-6 + sigma1) / (1.0e-6 + sigma1);
      accumulator += omega15m;
      omega16m = +0.628103908296079 / +2.94901979530886 / (1.0e-6 + sigma2) / (1.0e-6 + sigma2);
      accumulator += omega16m;
      omega17m = +1.64967326510295 / +2.94901979530886 / (1.0e-6 + sigma3) / (1.0e-6 + sigma3);
      accumulator += omega17m;
      omega18m = +0.628103908296079 / +2.94901979530886 / (1.0e-6 + sigma4) / (1.0e-6 + sigma4);
      accumulator += omega18m;
      omega19m = +0.0212699745747958 / +2.94901979530886 / (1.0e-6 + sigma5) / (1.0e-6 + sigma5);
      accumulator += omega19m;
      omega20m = +0.000299382232077403 / +2.94901979530886 / (1.0e-6 + sigma6) / (1.0e-6 + sigma6);
      accumulator += omega20m;
      omega14m /= accumulator;
      omega15m /= accumulator;
      omega16m /= accumulator;
      omega17m /= accumulator;
      omega18m /= accumulator;
      omega19m /= accumulator;
      omega20m /= accumulator;
      accumulator = 0.0;
      omega21 = +0.00229302929262629 / (1.0e-6 + sigma0) / (1.0e-6 + sigma0);
      accumulator += omega21;
      omega22 = +0.0518767742445351 / (1.0e-6 + sigma1) / (1.0e-6 + sigma1);
      accumulator += omega22;
      omega23 = +0.260549222547891 / (1.0e-6 + sigma2) / (1.0e-6 + sigma2);
      accumulator += omega23;
      omega24 = +0.415968769633893 / (1.0e-6 + sigma3) / (1.0e-6 + sigma3);
      accumulator += omega24;
      omega25 = +0.228348788654152 / (1.0e-6 + sigma4) / (1.0e-6 + sigma4);
      accumulator += omega25;
      omega26 = +0.0394546263903806 / (1.0e-6 + sigma5) / (1.0e-6 + sigma5);
      accumulator += omega26;
      omega27 = +0.00150878923651778 / (1.0e-6 + sigma6) / (1.0e-6 + sigma6);
      accumulator += omega27;
      omega21 /= accumulator;
      omega22 /= accumulator;
      omega23 /= accumulator;
      omega24 /= accumulator;
      omega25 /= accumulator;
      omega26 /= accumulator;
      omega27 /= accumulator;
      accumulator = 0.0;
      omega28 = +0.00407925407926976 / (1.0e-6 + sigma0) / (1.0e-6 + sigma0);
      accumulator += omega28;
      omega29 = +0.0734265734265464 / (1.0e-6 + sigma1) / (1.0e-6 + sigma1);
      accumulator += omega29;
      omega30 = +0.305944055944074 / (1.0e-6 + sigma2) / (1.0e-6 + sigma2);
      accumulator += omega30;
      omega31 = +0.407925407925404 / (1.0e-6 + sigma3) / (1.0e-6 + sigma3);
      accumulator += omega31;
      omega32 = +0.183566433566434 / (1.0e-6 + sigma4) / (1.0e-6 + sigma4);
      accumulator += omega32;
      omega33 = +0.0244755244755245 / (1.0e-6 + sigma5) / (1.0e-6 + sigma5);
      accumulator += omega33;
      omega34 = +0.000582750582750583 / (1.0e-6 + sigma6) / (1.0e-6 + sigma6);
      accumulator += omega34;
      omega28 /= accumulator;
      omega29 /= accumulator;
      omega30 /= accumulator;
      omega31 /= accumulator;
      omega32 /= accumulator;
      omega33 /= accumulator;
      omega34 /= accumulator;
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
	+1.8054420576557 * f[(i + 0) * fsi] - 1.93219774347488 * f[(i + 1) * fsi] +
	2.32621153077662 * f[(i + 2) * fsi] - 2.00294855866185 * f[(i + 3) * fsi] +
	1.10412541759084 * f[(i + 4) * fsi] - 0.348588075508419 * f[(i + 5) * fsi] +
	0.0479553716219888 * f[(i + 6) * fsi];
      f8 =
	+0.0479553716219887 * f[(i - 1) * fsi] + 1.46975445630178 * f[(i + 0) * fsi] -
	0.925134939413112 * f[(i + 1) * fsi] + 0.647773524007009 * f[(i + 2) * fsi] -
	0.324510551892243 * f[(i + 3) * fsi] + 0.0970626135290781 * f[(i + 4) * fsi] -
	0.0129004741544982 * f[(i + 5) * fsi];
      f9 =
	-0.0129004741544982 * f[(i - 2) * fsi] + 0.138258690703476 * f[(i - 1) * fsi] +
	1.19884449905731 * f[(i + 0) * fsi] - 0.473618344005674 * f[(i + 1) * fsi] +
	0.196256928599572 * f[(i + 2) * fsi] - 0.0536005946477803 * f[(i + 3) * fsi] +
	0.00675929444759062 * f[(i + 4) * fsi];
      f10 =
	+0.00675929444759061 * f[(i - 3) * fsi] - 0.0602155352876325 * f[(i - 2) * fsi] +
	0.280203874102879 * f[(i - 1) * fsi] + 0.962269193391642 * f[(i + 0) * fsi] -
	0.237043038340003 * f[(i + 1) * fsi] + 0.0543117452001689 * f[(i + 2) * fsi] -
	0.00628553351464601 * f[(i + 3) * fsi];
      f11 =
	-0.00628553351464601 * f[(i - 4) * fsi] + 0.0507580290501127 * f[(i - 3) * fsi] -
	0.192211739095199 * f[(i - 2) * fsi] + 0.500197547115489 * f[(i - 1) * fsi] +
	0.742275520379032 * f[(i + 0) * fsi] - 0.105046834532436 * f[(i + 1) * fsi] +
	0.0103130105976469 * f[(i + 2) * fsi];
      f12 =
	+0.0103130105976469 * f[(i - 5) * fsi] - 0.0784766076981743 * f[(i - 4) * fsi] +
	0.267331251600698 * f[(i - 3) * fsi] - 0.55316711001284 * f[(i - 2) * fsi] +
	0.861152918033131 * f[(i - 1) * fsi] + 0.525702297828447 * f[(i + 0) * fsi] -
	0.0328557603489081 * f[(i + 1) * fsi];
      f13 =
	-0.0328557603489081 * f[(i - 6) * fsi] + 0.240303333040004 * f[(i - 5) * fsi] -
	0.768447575025244 * f[(i - 4) * fsi] + 1.41728286381248 * f[(i - 3) * fsi] -
	1.70311872222462 * f[(i - 2) * fsi] + 1.5511238853602 * f[(i - 1) * fsi] +
	0.295711975386091 * f[(i + 0) * fsi];
      f14 =
	+0.819094122023809 * f[(i + 0) * fsi] + 0.687518601190476 * f[(i + 1) * fsi] -
	1.13598400297619 * f[(i + 2) * fsi] + 1.07853422619048 * f[(i + 3) * fsi] -
	0.622963169642857 * f[(i + 4) * fsi] + 0.20210193452381 * f[(i + 5) * fsi] -
	0.0283017113095238 * f[(i + 6) * fsi];
      f15 =
	-0.0283017113095238 * f[(i - 1) * fsi] + 1.01720610119048 * f[(i + 0) * fsi] +
	0.0931826636904762 * f[(i + 1) * fsi] - 0.145424107142857 * f[(i + 2) * fsi] +
	0.0879743303571429 * f[(i + 3) * fsi] - 0.0286272321428571 * f[(i + 4) * fsi] +
	0.00398995535714286 * f[(i + 5) * fsi];
      f16 =
	+0.00398995535714286 * f[(i - 2) * fsi] - 0.0562313988095238 * f[(i - 1) * fsi] +
	1.10099516369048 * f[(i + 0) * fsi] - 0.0464657738095238 * f[(i + 1) * fsi] -
	0.00577566964285714 * f[(i + 2) * fsi] + 0.00418526785714286 * f[(i + 3) * fsi] -
	0.000697544642857143 * f[(i + 4) * fsi];
      f17 =
	-0.000697544642857143 * f[(i - 3) * fsi] + 0.00887276785714286 * f[(i - 2) * fsi] -
	0.0708798363095238 * f[(i - 1) * fsi] + 1.12540922619048 * f[(i + 0) * fsi] -
	0.0708798363095238 * f[(i + 1) * fsi] + 0.00887276785714286 * f[(i + 2) * fsi] -
	0.000697544642857143 * f[(i + 3) * fsi];
      f18 =
	-0.000697544642857143 * f[(i - 4) * fsi] + 0.00418526785714286 * f[(i - 3) * fsi] -
	0.00577566964285714 * f[(i - 2) * fsi] - 0.0464657738095238 * f[(i - 1) * fsi] +
	1.10099516369048 * f[(i + 0) * fsi] - 0.0562313988095238 * f[(i + 1) * fsi] +
	0.00398995535714286 * f[(i + 2) * fsi];
      f19 =
	+0.00398995535714286 * f[(i - 5) * fsi] - 0.0286272321428571 * f[(i - 4) * fsi] +
	0.0879743303571429 * f[(i - 3) * fsi] - 0.145424107142857 * f[(i - 2) * fsi] +
	0.0931826636904762 * f[(i - 1) * fsi] + 1.01720610119048 * f[(i + 0) * fsi] -
	0.0283017113095238 * f[(i + 1) * fsi];
      f20 =
	-0.0283017113095238 * f[(i - 6) * fsi] + 0.20210193452381 * f[(i - 5) * fsi] -
	0.622963169642857 * f[(i - 4) * fsi] + 1.07853422619048 * f[(i - 3) * fsi] -
	1.13598400297619 * f[(i - 2) * fsi] + 0.687518601190476 * f[(i - 1) * fsi] +
	0.819094122023809 * f[(i + 0) * fsi];
      f21 =
	+0.29571197538609 * f[(i + 0) * fsi] + 1.5511238853602 * f[(i + 1) * fsi] -
	1.70311872222462 * f[(i + 2) * fsi] + 1.41728286381248 * f[(i + 3) * fsi] -
	0.768447575025245 * f[(i + 4) * fsi] + 0.240303333040004 * f[(i + 5) * fsi] -
	0.032855760348908 * f[(i + 6) * fsi];
      f22 =
	-0.032855760348908 * f[(i - 1) * fsi] + 0.525702297828447 * f[(i + 0) * fsi] +
	0.861152918033131 * f[(i + 1) * fsi] - 0.55316711001284 * f[(i + 2) * fsi] +
	0.267331251600698 * f[(i + 3) * fsi] - 0.0784766076981743 * f[(i + 4) * fsi] +
	0.0103130105976469 * f[(i + 5) * fsi];
      f23 =
	+0.0103130105976469 * f[(i - 2) * fsi] - 0.105046834532436 * f[(i - 1) * fsi] +
	0.742275520379032 * f[(i + 0) * fsi] + 0.500197547115489 * f[(i + 1) * fsi] -
	0.192211739095199 * f[(i + 2) * fsi] + 0.0507580290501127 * f[(i + 3) * fsi] -
	0.00628553351464601 * f[(i + 4) * fsi];
      f24 =
	-0.00628553351464601 * f[(i - 3) * fsi] + 0.054311745200169 * f[(i - 2) * fsi] -
	0.237043038340003 * f[(i - 1) * fsi] + 0.962269193391642 * f[(i + 0) * fsi] +
	0.280203874102879 * f[(i + 1) * fsi] - 0.0602155352876325 * f[(i + 2) * fsi] +
	0.00675929444759062 * f[(i + 3) * fsi];
      f25 =
	+0.00675929444759062 * f[(i - 4) * fsi] - 0.0536005946477803 * f[(i - 3) * fsi] +
	0.196256928599572 * f[(i - 2) * fsi] - 0.473618344005674 * f[(i - 1) * fsi] +
	1.19884449905731 * f[(i + 0) * fsi] + 0.138258690703476 * f[(i + 1) * fsi] -
	0.0129004741544982 * f[(i + 2) * fsi];
      f26 =
	-0.0129004741544982 * f[(i - 5) * fsi] + 0.0970626135290781 * f[(i - 4) * fsi] -
	0.324510551892243 * f[(i - 3) * fsi] + 0.647773524007009 * f[(i - 2) * fsi] -
	0.925134939413112 * f[(i - 1) * fsi] + 1.46975445630178 * f[(i + 0) * fsi] +
	0.0479553716219888 * f[(i + 1) * fsi];
      f27 =
	+0.0479553716219888 * f[(i - 6) * fsi] - 0.34858807550842 * f[(i - 5) * fsi] +
	1.10412541759084 * f[(i - 4) * fsi] - 2.00294855866185 * f[(i - 3) * fsi] +
	2.32621153077662 * f[(i - 2) * fsi] - 1.93219774347488 * f[(i - 1) * fsi] +
	1.8054420576557 * f[(i + 0) * fsi];
      f28 =
	+0.142857142857143 * f[(i + 0) * fsi] + 1.59285714285714 * f[(i + 1) * fsi] -
	1.40714285714286 * f[(i + 2) * fsi] + 1.09285714285714 * f[(i + 3) * fsi] -
	0.573809523809524 * f[(i + 4) * fsi] + 0.176190476190476 * f[(i + 5) * fsi] -
	0.0238095238095238 * f[(i + 6) * fsi];
      f29 =
	-0.0238095238095238 * f[(i - 1) * fsi] + 0.30952380952381 * f[(i + 0) * fsi] +
	1.09285714285714 * f[(i + 1) * fsi] - 0.573809523809524 * f[(i + 2) * fsi] +
	0.25952380952381 * f[(i + 3) * fsi] - 0.0738095238095238 * f[(i + 4) * fsi] +
	0.00952380952380954 * f[(i + 5) * fsi];
      f30 =
	+0.00952380952380954 * f[(i - 2) * fsi] - 0.0904761904761906 * f[(i - 1) * fsi] +
	0.50952380952381 * f[(i + 0) * fsi] + 0.759523809523809 * f[(i + 1) * fsi] -
	0.24047619047619 * f[(i + 2) * fsi] + 0.0595238095238095 * f[(i + 3) * fsi] -
	0.00714285714285715 * f[(i + 4) * fsi];
      f31 =
	-0.00714285714285714 * f[(i - 3) * fsi] + 0.0595238095238095 * f[(i - 2) * fsi] -
	0.240476190476191 * f[(i - 1) * fsi] + 0.75952380952381 * f[(i + 0) * fsi] +
	0.50952380952381 * f[(i + 1) * fsi] - 0.0904761904761905 * f[(i + 2) * fsi] +
	0.00952380952380952 * f[(i + 3) * fsi];
      f32 =
	+0.00952380952380952 * f[(i - 4) * fsi] - 0.0738095238095238 * f[(i - 3) * fsi] +
	0.259523809523809 * f[(i - 2) * fsi] - 0.573809523809524 * f[(i - 1) * fsi] +
	1.09285714285714 * f[(i + 0) * fsi] + 0.309523809523809 * f[(i + 1) * fsi] -
	0.0238095238095238 * f[(i + 2) * fsi];
      f33 =
	-0.0238095238095238 * f[(i - 5) * fsi] + 0.176190476190476 * f[(i - 4) * fsi] -
	0.573809523809524 * f[(i - 3) * fsi] + 1.09285714285714 * f[(i - 2) * fsi] -
	1.40714285714286 * f[(i - 1) * fsi] + 1.59285714285714 * f[(i + 0) * fsi] +
	0.142857142857143 * f[(i + 1) * fsi];
      f34 =
	+0.142857142857143 * f[(i - 6) * fsi] - 1.02380952380952 * f[(i - 5) * fsi] +
	3.17619047619048 * f[(i - 4) * fsi] - 5.57380952380953 * f[(i - 3) * fsi] +
	6.09285714285714 * f[(i - 2) * fsi] - 4.40714285714286 * f[(i - 1) * fsi] +
	2.59285714285714 * f[(i + 0) * fsi];
      fr0 =
	f0 * omega0 + f1 * omega1 + f2 * omega2 + f3 * omega3 + f4 * omega4 + f5 * omega5 +
	f6 * omega6;
      fr1 =
	f7 * omega7 + f8 * omega8 + f9 * omega9 + f10 * omega10 + f11 * omega11 + f12 * omega12 +
	f13 * omega13;
      fr2 =
	+3.94901979530886 * (f14 * omega14p + f15 * omega15p + f16 * omega16p + f17 * omega17p +
			     f18 * omega18p + f19 * omega19p + f20 * omega20p) -
	+2.94901979530886 * (f14 * omega14m + f15 * omega15m + f16 * omega16m + f17 * omega17m +
			     f18 * omega18m + f19 * omega19m + f20 * omega20m);
      fr3 =
	f21 * omega21 + f22 * omega22 + f23 * omega23 + f24 * omega24 + f25 * omega25 +
	f26 * omega26 + f27 * omega27;
      fr4 =
	f28 * omega28 + f29 * omega29 + f30 * omega30 + f31 * omega31 + f32 * omega32 +
	f33 * omega33 + f34 * omega34;
      fr[i * frsi + 0 * frsl] = fr0;
      fr[i * frsi + 1 * frsl] = fr1;
      fr[i * frsi + 2 * frsl] = fr2;
      fr[i * frsi + 3 * frsl] = fr3;
      fr[i * frsi + 4 * frsl] = fr4;
    }
}

PyObject *
py_gauss_lobatto007005 (PyObject * self, PyObject * args)
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

  gauss_lobatto007005 (f, n, fsi, sigma, ssi, ssr, fr, frsi, frsl);

  Py_INCREF (Py_None);
  return Py_None;
}
