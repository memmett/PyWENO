#include <Python.h>
#include <numpy/ndarrayobject.h>

void
gauss_radau008008 (const double *restrict f, int n, int fsi,
		   const double *restrict sigma, int ssi, int ssr,
		   double *restrict fr, int frsi, int frsl)
{
  int i;
  double sigma0, sigma1, sigma2, sigma3, sigma4, sigma5, sigma6, sigma7, omega39p, omega59, omega11,
    omega36m, omega39m, omega46, omega57, omega36p, omega63, omega7, omega27m, omega22, omega14,
    omega28m, omega41, omega50, omega27p, omega21, omega35p, omega3, omega58, omega47, omega10,
    omega35m, omega52, omega45, omega28p, omega16, omega30p, omega62, omega54, omega31m, omega51,
    omega13, omega37p, omega29m, omega40, omega18, omega37m, omega9, omega31p, omega26p, omega23,
    omega44, omega0, omega25m, omega26m, omega4, omega48, omega12, omega55, omega38m, omega61,
    omega19, omega17, omega24m, omega38p, omega8, omega25p, omega53, omega43, omega1, omega56,
    omega30m, omega33p, omega29p, omega49, omega32p, omega34m, omega2, omega60, omega6, omega24p,
    omega32m, omega34p, omega15, omega5, omega42, omega20, omega33m, accumulator, f59, f39, f11,
    f52, f24, f44, f7, f46, f22, f14, f41, f31, f21, f3, f58, f32, f10, f55, f27, f16, f62, f36,
    f51, f13, f30, f18, f63, f47, f43, f33, f9, f23, f26, f0, f54, f40, f57, f37, f4, f45, f12, f48,
    f61, f19, f17, f34, f8, f53, f29, f1, f56, f38, f42, f49, f25, f2, f60, f6, f50, f35, f15, f5,
    f28, f20, fr0, fr1, fr2, fr3, fr4, fr5, fr6, fr7;
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
      omega8 = +0.000209241149446126 / (1.0e-6 + sigma0) / (1.0e-6 + sigma0);
      accumulator += omega8;
      omega9 = +0.0102814536717515 / (1.0e-6 + sigma1) / (1.0e-6 + sigma1);
      accumulator += omega9;
      omega10 = +0.100231808965762 / (1.0e-6 + sigma2) / (1.0e-6 + sigma2);
      accumulator += omega10;
      omega11 = +0.315523503981047 / (1.0e-6 + sigma3) / (1.0e-6 + sigma3);
      accumulator += omega11;
      omega12 = +0.374770667605141 / (1.0e-6 + sigma4) / (1.0e-6 + sigma4);
      accumulator += omega12;
      omega13 = +0.171005823329177 / (1.0e-6 + sigma5) / (1.0e-6 + sigma5);
      accumulator += omega13;
      omega14 = +0.0269530912197157 / (1.0e-6 + sigma6) / (1.0e-6 + sigma6);
      accumulator += omega14;
      omega15 = +0.0010244100779584 / (1.0e-6 + sigma7) / (1.0e-6 + sigma7);
      accumulator += omega15;
      omega8 /= accumulator;
      omega9 /= accumulator;
      omega10 /= accumulator;
      omega11 /= accumulator;
      omega12 /= accumulator;
      omega13 /= accumulator;
      omega14 /= accumulator;
      omega15 /= accumulator;
      accumulator = 0.0;
      omega16 = +0.000458938797072336 / (1.0e-6 + sigma0) / (1.0e-6 + sigma0);
      accumulator += omega16;
      omega17 = +0.0154563727946238 / (1.0e-6 + sigma1) / (1.0e-6 + sigma1);
      accumulator += omega17;
      omega18 = +0.124021857551235 / (1.0e-6 + sigma2) / (1.0e-6 + sigma2);
      accumulator += omega18;
      omega19 = +0.338660590316919 / (1.0e-6 + sigma3) / (1.0e-6 + sigma3);
      accumulator += omega19;
      omega20 = +0.356103158965203 / (1.0e-6 + sigma4) / (1.0e-6 + sigma4);
      accumulator += omega20;
      omega21 = +0.144550973703477 / (1.0e-6 + sigma5) / (1.0e-6 + sigma5);
      accumulator += omega21;
      omega22 = +0.0200955338214904 / (1.0e-6 + sigma6) / (1.0e-6 + sigma6);
      accumulator += omega22;
      omega23 = +0.000652574049980053 / (1.0e-6 + sigma7) / (1.0e-6 + sigma7);
      accumulator += omega23;
      omega16 /= accumulator;
      omega17 /= accumulator;
      omega18 /= accumulator;
      omega19 /= accumulator;
      omega20 /= accumulator;
      omega21 /= accumulator;
      omega22 /= accumulator;
      omega23 /= accumulator;
      accumulator = 0.0;
      omega24p = +0.00116570682553983 / +2.00349712047662 / (1.0e-6 + sigma0) / (1.0e-6 + sigma0);
      accumulator += omega24p;
      omega25p = +0.132784941358544 / +2.00349712047662 / (1.0e-6 + sigma1) / (1.0e-6 + sigma1);
      accumulator += omega25p;
      omega26p = +0.355891961306022 / +2.00349712047662 / (1.0e-6 + sigma2) / (1.0e-6 + sigma2);
      accumulator += omega26p;
      omega27p = +0.713249121889274 / +2.00349712047662 / (1.0e-6 + sigma3) / (1.0e-6 + sigma3);
      accumulator += omega27p;
      omega28p = +0.585792719342741 / +2.00349712047662 / (1.0e-6 + sigma4) / (1.0e-6 + sigma4);
      accumulator += omega28p;
      omega29p = +0.19237328097919 / +2.00349712047662 / (1.0e-6 + sigma5) / (1.0e-6 + sigma5);
      accumulator += omega29p;
      omega30p = +0.0216906005814556 / +2.00349712047662 / (1.0e-6 + sigma6) / (1.0e-6 + sigma6);
      accumulator += omega30p;
      omega31p = +0.000548788193851588 / +2.00349712047662 / (1.0e-6 + sigma7) / (1.0e-6 + sigma7);
      accumulator += omega31p;
      omega24p /= accumulator;
      omega25p /= accumulator;
      omega26p /= accumulator;
      omega27p /= accumulator;
      omega28p /= accumulator;
      omega29p /= accumulator;
      omega30p /= accumulator;
      omega31p /= accumulator;
      accumulator = 0.0;
      omega24m = +0.00233141365107966 / +1.00349712047662 / (1.0e-6 + sigma0) / (1.0e-6 + sigma0);
      accumulator += omega24m;
      omega25m = +0.0663924706792722 / +1.00349712047662 / (1.0e-6 + sigma1) / (1.0e-6 + sigma1);
      accumulator += omega25m;
      omega26m = +0.177945980653011 / +1.00349712047662 / (1.0e-6 + sigma2) / (1.0e-6 + sigma2);
      accumulator += omega26m;
      omega27m = +0.356624560944637 / +1.00349712047662 / (1.0e-6 + sigma3) / (1.0e-6 + sigma3);
      accumulator += omega27m;
      omega28m = +0.29289635967137 / +1.00349712047662 / (1.0e-6 + sigma4) / (1.0e-6 + sigma4);
      accumulator += omega28m;
      omega29m = +0.0961866404895951 / +1.00349712047662 / (1.0e-6 + sigma5) / (1.0e-6 + sigma5);
      accumulator += omega29m;
      omega30m = +0.0108453002907278 / +1.00349712047662 / (1.0e-6 + sigma6) / (1.0e-6 + sigma6);
      accumulator += omega30m;
      omega31m = +0.000274394096925794 / +1.00349712047662 / (1.0e-6 + sigma7) / (1.0e-6 + sigma7);
      accumulator += omega31m;
      omega24m /= accumulator;
      omega25m /= accumulator;
      omega26m /= accumulator;
      omega27m /= accumulator;
      omega28m /= accumulator;
      omega29m /= accumulator;
      omega30m /= accumulator;
      omega31m /= accumulator;
      accumulator = 0.0;
      omega32p = +0.000148934687541203 / +6.78748705871543 / (1.0e-6 + sigma0) / (1.0e-6 + sigma0);
      accumulator += omega32p;
      omega33p = +0.00667758580117684 / +6.78748705871543 / (1.0e-6 + sigma1) / (1.0e-6 + sigma1);
      accumulator += omega33p;
      omega34p = +0.0607182647732327 / +6.78748705871543 / (1.0e-6 + sigma2) / (1.0e-6 + sigma2);
      accumulator += omega34p;
      omega35p = +0.0894913025338132 / +6.78748705871543 / (1.0e-6 + sigma3) / (1.0e-6 + sigma3);
      accumulator += omega35p;
      omega36p = +5.03462195134786 / +6.78748705871543 / (1.0e-6 + sigma4) / (1.0e-6 + sigma4);
      accumulator += omega36p;
      omega37p = +1.5797936244192 / +6.78748705871543 / (1.0e-6 + sigma5) / (1.0e-6 + sigma5);
      accumulator += omega37p;
      omega38p = +0.0158604780644728 / +6.78748705871543 / (1.0e-6 + sigma6) / (1.0e-6 + sigma6);
      accumulator += omega38p;
      omega39p = +0.000174917088124619 / +6.78748705871543 / (1.0e-6 + sigma7) / (1.0e-6 + sigma7);
      accumulator += omega39p;
      omega32p /= accumulator;
      omega33p /= accumulator;
      omega34p /= accumulator;
      omega35p /= accumulator;
      omega36p /= accumulator;
      omega37p /= accumulator;
      omega38p /= accumulator;
      omega39p /= accumulator;
      accumulator = 0.0;
      omega32m = +7.44673437706015e-05 / +5.78748705871542 / (1.0e-6 + sigma0) / (1.0e-6 + sigma0);
      accumulator += omega32m;
      omega33m = +0.00333879290058842 / +5.78748705871542 / (1.0e-6 + sigma1) / (1.0e-6 + sigma1);
      accumulator += omega33m;
      omega34m = +0.0303591323866163 / +5.78748705871542 / (1.0e-6 + sigma2) / (1.0e-6 + sigma2);
      accumulator += omega34m;
      omega35m = +0.0447456512669066 / +5.78748705871542 / (1.0e-6 + sigma3) / (1.0e-6 + sigma3);
      accumulator += omega35m;
      omega36m = +2.51731097567393 / +5.78748705871542 / (1.0e-6 + sigma4) / (1.0e-6 + sigma4);
      accumulator += omega36m;
      omega37m = +3.15958724883841 / +5.78748705871542 / (1.0e-6 + sigma5) / (1.0e-6 + sigma5);
      accumulator += omega37m;
      omega38m = +0.0317209561289455 / +5.78748705871542 / (1.0e-6 + sigma6) / (1.0e-6 + sigma6);
      accumulator += omega38m;
      omega39m = +0.000349834176249237 / +5.78748705871542 / (1.0e-6 + sigma7) / (1.0e-6 + sigma7);
      accumulator += omega39m;
      omega32m /= accumulator;
      omega33m /= accumulator;
      omega34m /= accumulator;
      omega35m /= accumulator;
      omega36m /= accumulator;
      omega37m /= accumulator;
      omega38m /= accumulator;
      omega39m /= accumulator;
      accumulator = 0.0;
      omega40 = +0.000452090083634848 / (1.0e-6 + sigma0) / (1.0e-6 + sigma0);
      accumulator += omega40;
      omega41 = +0.0156438011587619 / (1.0e-6 + sigma1) / (1.0e-6 + sigma1);
      accumulator += omega41;
      omega42 = +0.123832904371527 / (1.0e-6 + sigma2) / (1.0e-6 + sigma2);
      accumulator += omega42;
      omega43 = +0.334950894822153 / (1.0e-6 + sigma3) / (1.0e-6 + sigma3);
      accumulator += omega43;
      omega44 = +0.353389580878719 / (1.0e-6 + sigma4) / (1.0e-6 + sigma4);
      accumulator += omega44;
      omega45 = +0.147771770653401 / (1.0e-6 + sigma5) / (1.0e-6 + sigma5);
      accumulator += omega45;
      omega46 = +0.0226466917396712 / (1.0e-6 + sigma6) / (1.0e-6 + sigma6);
      accumulator += omega46;
      omega47 = +0.00131226629213273 / (1.0e-6 + sigma7) / (1.0e-6 + sigma7);
      accumulator += omega47;
      omega40 /= accumulator;
      omega41 /= accumulator;
      omega42 /= accumulator;
      omega43 /= accumulator;
      omega44 /= accumulator;
      omega45 /= accumulator;
      omega46 /= accumulator;
      omega47 /= accumulator;
      accumulator = 0.0;
      omega48 = +0.000833952512578875 / (1.0e-6 + sigma0) / (1.0e-6 + sigma0);
      accumulator += omega48;
      omega49 = +0.0236122523268813 / (1.0e-6 + sigma1) / (1.0e-6 + sigma1);
      accumulator += omega49;
      omega50 = +0.158776557496749 / (1.0e-6 + sigma2) / (1.0e-6 + sigma2);
      accumulator += omega50;
      omega51 = +0.367119166984924 / (1.0e-6 + sigma3) / (1.0e-6 + sigma3);
      accumulator += omega51;
      omega52 = +0.326560922733886 / (1.0e-6 + sigma4) / (1.0e-6 + sigma4);
      accumulator += omega52;
      omega53 = +0.110481199175238 / (1.0e-6 + sigma5) / (1.0e-6 + sigma5);
      accumulator += omega53;
      omega54 = +0.0123237197911692 / (1.0e-6 + sigma6) / (1.0e-6 + sigma6);
      accumulator += omega54;
      omega55 = +0.000292228978517338 / (1.0e-6 + sigma7) / (1.0e-6 + sigma7);
      accumulator += omega55;
      omega48 /= accumulator;
      omega49 /= accumulator;
      omega50 /= accumulator;
      omega51 /= accumulator;
      omega52 /= accumulator;
      omega53 /= accumulator;
      omega54 /= accumulator;
      omega55 /= accumulator;
      accumulator = 0.0;
      omega56 = +0.00115085664247663 / (1.0e-6 + sigma0) / (1.0e-6 + sigma0);
      accumulator += omega56;
      omega57 = +0.0290169424973553 / (1.0e-6 + sigma1) / (1.0e-6 + sigma1);
      accumulator += omega57;
      omega58 = +0.178043303411865 / (1.0e-6 + sigma2) / (1.0e-6 + sigma2);
      accumulator += omega58;
      omega59 = +0.378497039564481 / (1.0e-6 + sigma3) / (1.0e-6 + sigma3);
      accumulator += omega59;
      omega60 = +0.309000220059846 / (1.0e-6 + sigma4) / (1.0e-6 + sigma4);
      accumulator += omega60;
      omega61 = +0.0948193301444038 / (1.0e-6 + sigma5) / (1.0e-6 + sigma5);
      accumulator += omega61;
      omega62 = +0.00929757419112021 / (1.0e-6 + sigma6) / (1.0e-6 + sigma6);
      accumulator += omega62;
      omega63 = +0.000174733488489024 / (1.0e-6 + sigma7) / (1.0e-6 + sigma7);
      accumulator += omega63;
      omega56 /= accumulator;
      omega57 /= accumulator;
      omega58 /= accumulator;
      omega59 /= accumulator;
      omega60 /= accumulator;
      omega61 /= accumulator;
      omega62 /= accumulator;
      omega63 /= accumulator;
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
	+2.40365260802838 * f[(i + 0) * fsi] - 4.139428798326 * f[(i + 1) * fsi] +
	6.60129248458942 * f[(i + 2) * fsi] - 7.42268081750136 * f[(i + 3) * fsi] +
	5.5886326648633 * f[(i + 4) * fsi] - 2.68693258174787 * f[(i + 5) * fsi] +
	0.746969989184631 * f[(i + 6) * fsi] - 0.0915055490904955 * f[(i + 7) * fsi];
      f9 =
	+0.0915055490904955 * f[(i - 1) * fsi] + 1.67160821530441 * f[(i + 0) * fsi] -
	1.57727342379213 * f[(i + 1) * fsi] + 1.47698173552168 * f[(i + 2) * fsi] -
	1.01729238116667 * f[(i + 3) * fsi] + 0.464321915795547 * f[(i + 4) * fsi] -
	0.124777207213994 * f[(i + 5) * fsi] + 0.014925596460667 * f[(i + 6) * fsi];
      f10 =
	-0.014925596460667 * f[(i - 2) * fsi] + 0.210910320775832 * f[(i - 1) * fsi] +
	1.25369151440574 * f[(i + 0) * fsi] - 0.741440021994776 * f[(i + 1) * fsi] +
	0.432189983274983 * f[(i + 2) * fsi] - 0.181458979369321 * f[(i + 3) * fsi] +
	0.0464052148968704 * f[(i + 4) * fsi] - 0.00537243552865763 * f[(i + 5) * fsi];
      f11 =
	+0.00537243552865763 * f[(i - 3) * fsi] - 0.0579050806899281 * f[(i - 2) * fsi] +
	0.361338515578245 * f[(i - 1) * fsi] + 0.95283512480091 * f[(i + 0) * fsi] -
	0.365369534988742 * f[(i + 1) * fsi] + 0.131333593670155 * f[(i + 2) * fsi] -
	0.0310307845669074 * f[(i + 3) * fsi] + 0.0034257306676094 * f[(i + 4) * fsi];
      f12 =
	-0.0034257306676094 * f[(i - 4) * fsi] + 0.0327782808695328 * f[(i - 3) * fsi] -
	0.153825539382991 * f[(i - 2) * fsi] + 0.553179432964372 * f[(i - 1) * fsi] +
	0.713033978068252 * f[(i + 0) * fsi] - 0.173528617602616 * f[(i + 1) * fsi] +
	0.0354131349770923 * f[(i + 2) * fsi] - 0.00362493922603222 * f[(i + 3) * fsi];
      f13 =
	+0.00362493922603222 * f[(i - 5) * fsi] - 0.0324252444758671 * f[(i - 4) * fsi] +
	0.134276579198435 * f[(i - 3) * fsi] - 0.356822136040795 * f[(i - 2) * fsi] +
	0.806925178786627 * f[(i - 1) * fsi] + 0.510037381410448 * f[(i + 0) * fsi] -
	0.0720303192737137 * f[(i + 1) * fsi] + 0.0064136211688346 * f[(i + 2) * fsi];
      f14 =
	-0.0064136211688346 * f[(i - 6) * fsi] + 0.054933908576709 * f[(i - 5) * fsi] -
	0.212006637203236 * f[(i - 4) * fsi] + 0.493439364653173 * f[(i - 3) * fsi] -
	0.805775617859217 * f[(i - 2) * fsi] + 1.16608796424136 * f[(i - 1) * fsi] +
	0.330455988683079 * f[(i + 0) * fsi] - 0.0207213499230369 * f[(i + 1) * fsi];
      f15 =
	+0.0207213499230369 * f[(i - 7) * fsi] - 0.17218442055313 * f[(i - 6) * fsi] +
	0.635131706421743 * f[(i - 5) * fsi] - 1.3724022328933 * f[(i - 4) * fsi] +
	1.94393385926576 * f[(i - 3) * fsi] - 1.96617121354928 * f[(i - 2) * fsi] +
	1.7462857620864 * f[(i - 1) * fsi] + 0.164685189298784 * f[(i + 0) * fsi];
      f16 =
	+1.81194274618263 * f[(i + 0) * fsi] - 2.09731563044896 * f[(i + 1) * fsi] +
	2.9580920605483 * f[(i + 2) * fsi] - 3.15118442185058 * f[(i + 3) * fsi] +
	2.3033716655335 * f[(i + 4) * fsi] - 1.08710043942689 * f[(i + 5) * fsi] +
	0.298417134592562 * f[(i + 6) * fsi] - 0.0362231151305586 * f[(i + 7) * fsi];
      f17 =
	+0.0362231151305586 * f[(i - 1) * fsi] + 1.52215782513817 * f[(i + 0) * fsi] -
	1.08306840679332 * f[(i + 1) * fsi] + 0.929597613237016 * f[(i + 2) * fsi] -
	0.61556636271148 * f[(i + 3) * fsi] + 0.274877218222219 * f[(i + 4) * fsi] -
	0.0728532157712515 * f[(i + 5) * fsi] + 0.00863221354809355 * f[(i + 6) * fsi];
      f18 =
	-0.00863221354809355 * f[(i - 2) * fsi] + 0.105280823515307 * f[(i - 1) * fsi] +
	1.28045584579155 * f[(i + 0) * fsi] - 0.599664448100082 * f[(i + 1) * fsi] +
	0.325342664870467 * f[(i + 2) * fsi] - 0.132162404018241 * f[(i + 3) * fsi] +
	0.0331752388755995 * f[(i + 4) * fsi] - 0.00379550738650305 * f[(i + 5) * fsi];
      f19 =
	+0.00379550738650305 * f[(i - 3) * fsi] - 0.038996272640118 * f[(i - 2) * fsi] +
	0.211555030337392 * f[(i - 1) * fsi] + 1.06790743214738 * f[(i + 0) * fsi] -
	0.333978931044869 * f[(i + 1) * fsi] + 0.112794251226297 * f[(i + 2) * fsi] -
	0.0258881971961555 * f[(i + 3) * fsi] + 0.00281117978357516 * f[(i + 4) * fsi];
      f20 =
	-0.00281117978357516 * f[(i - 4) * fsi] + 0.0262849456551043 * f[(i - 3) * fsi] -
	0.117709306580222 * f[(i - 2) * fsi] + 0.368981098217601 * f[(i - 1) * fsi] +
	0.871124847297114 * f[(i + 0) * fsi] - 0.17655286316466 * f[(i + 1) * fsi] +
	0.0340812172861921 * f[(i + 2) * fsi] - 0.00339875892755428 * f[(i + 3) * fsi];
      f21 =
	+0.00339875892755428 * f[(i - 5) * fsi] - 0.0300012512040094 * f[(i - 4) * fsi] +
	0.121450195626624 * f[(i - 3) * fsi] - 0.308039806523262 * f[(i - 2) * fsi] +
	0.606894223146401 * f[(i - 1) * fsi] + 0.680794347354075 * f[(i + 0) * fsi] -
	0.0813876131931403 * f[(i + 1) * fsi] + 0.00689114586575785 * f[(i + 2) * fsi];
      f22 =
	-0.00689114586575785 * f[(i - 6) * fsi] + 0.0585279258536171 * f[(i - 5) * fsi] -
	0.222953335445229 * f[(i - 4) * fsi] + 0.507354364109064 * f[(i - 3) * fsi] -
	0.790420017126311 * f[(i - 2) * fsi] + 0.99279839162884 * f[(i - 1) * fsi] +
	0.487842263112855 * f[(i + 0) * fsi] - 0.0262584462670775 * f[(i + 1) * fsi];
      f23 =
	+0.0262584462670775 * f[(i - 7) * fsi] - 0.216958716002378 * f[(i - 6) * fsi] +
	0.793764421331787 * f[(i - 5) * fsi] - 1.69342632640157 * f[(i - 4) * fsi] +
	2.34544560280449 * f[(i - 3) * fsi] - 2.26089300808265 * f[(i - 2) * fsi] +
	1.72803488710701 * f[(i - 1) * fsi] + 0.277774692976235 * f[(i + 0) * fsi];
      f24 =
	+1.18482771281332 * f[(i + 0) * fsi] - 0.156749679942556 * f[(i + 1) * fsi] -
	0.226541447128986 * f[(i + 2) * fsi] + 0.443115168454828 * f[(i + 3) * fsi] -
	0.403278736494048 * f[(i + 4) * fsi] + 0.213555309202442 * f[(i + 5) * fsi] -
	0.0629484742481587 * f[(i + 6) * fsi] + 0.00802014734316739 * f[(i + 7) * fsi];
      f25 =
	-0.00802014734316739 * f[(i - 1) * fsi] + 1.24898889155866 * f[(i + 0) * fsi] -
	0.381313805551242 * f[(i + 1) * fsi] + 0.222586804088386 * f[(i + 2) * fsi] -
	0.118295145566892 * f[(i + 3) * fsi] + 0.0458495147233235 * f[(i + 4) * fsi] -
	0.0110088164062452 * f[(i + 5) * fsi] + 0.00121270449718036 * f[(i + 6) * fsi];
      f26 =
	-0.00121270449718036 * f[(i - 2) * fsi] + 0.00168148863427547 * f[(i - 1) * fsi] +
	1.21503316563761 * f[(i + 0) * fsi] - 0.313402353709142 * f[(i + 1) * fsi] +
	0.137697489285761 * f[(i + 2) * fsi] - 0.0503836937247922 * f[(i + 3) * fsi] +
	0.0118937888022733 * f[(i + 4) * fsi] - 0.0013071804288023 * f[(i + 5) * fsi];
      f27 =
	+0.0013071804288023 * f[(i - 3) * fsi] - 0.0116701479275987 * f[(i - 2) * fsi] +
	0.0382825406407398 * f[(i - 1) * fsi] + 1.14183106162468 * f[(i + 0) * fsi] -
	0.221899723692981 * f[(i + 1) * fsi] + 0.0644953852728321 * f[(i + 2) * fsi] -
	0.013782641718328 * f[(i + 3) * fsi] + 0.00143634537185494 * f[(i + 4) * fsi];
      f28 =
	-0.00143634537185494 * f[(i - 4) * fsi] + 0.0127979434036418 * f[(i - 3) * fsi] -
	0.0518878183395371 * f[(i - 2) * fsi] + 0.118717881464617 * f[(i - 1) * fsi] +
	1.04128688559483 * f[(i + 0) * fsi] - 0.141464382869104 * f[(i + 1) * fsi] +
	0.0242777148608937 * f[(i + 2) * fsi] - 0.00229187874348845 * f[(i + 3) * fsi];
      f29 =
	+0.00229187874348845 * f[(i - 5) * fsi] - 0.0197713753197625 * f[(i - 4) * fsi] +
	0.0769705482213184 * f[(i - 3) * fsi] - 0.18023302797489 * f[(i - 2) * fsi] +
	0.279149393508808 * f[(i - 1) * fsi] + 0.91294167595948 * f[(i + 0) * fsi] -
	0.0772917780514277 * f[(i + 1) * fsi] + 0.00594268491298608 * f[(i + 2) * fsi];
      f30 =
	-0.00594268491298608 * f[(i - 6) * fsi] + 0.0498333580473771 * f[(i - 5) * fsi] -
	0.186166552883373 * f[(i - 4) * fsi] + 0.409760903348539 * f[(i - 3) * fsi] -
	0.596220971883916 * f[(i - 2) * fsi] + 0.611939748636028 * f[(i - 1) * fsi] +
	0.746546498395869 * f[(i + 0) * fsi] - 0.0297502987475391 * f[(i + 1) * fsi];
      f31 =
	+0.0297502987475391 * f[(i - 7) * fsi] - 0.243945074893299 * f[(i - 6) * fsi] +
	0.882841722978471 * f[(i - 5) * fsi] - 1.85218328274556 * f[(i - 4) * fsi] +
	2.49228181567627 * f[(i - 3) * fsi] - 2.2622377017461 * f[(i - 2) * fsi] +
	1.44494811356712 * f[(i - 1) * fsi] + 0.508544108415557 * f[(i + 0) * fsi];
      f32 =
	+0.692449910220645 * f[(i + 0) * fsi] + 1.09033854329075 * f[(i + 1) * fsi] -
	1.93021272910915 * f[(i + 2) * fsi] + 2.21367272686274 * f[(i + 3) * fsi] -
	1.67737002233525 * f[(i + 4) * fsi] + 0.808621227348841 * f[(i + 5) * fsi] -
	0.225093907216698 * f[(i + 6) * fsi] + 0.0275942509381239 * f[(i + 7) * fsi];
      f33 =
	-0.0275942509381239 * f[(i - 1) * fsi] + 0.913203917725635 * f[(i + 0) * fsi] +
	0.317699517023279 * f[(i + 1) * fsi] - 0.38493467657421 * f[(i + 2) * fsi] +
	0.282075161194064 * f[(i + 3) * fsi] - 0.132091969800311 * f[(i + 4) * fsi] +
	0.0359822010813736 * f[(i + 5) * fsi] - 0.00433989971170764 * f[(i + 6) * fsi];
      f34 =
	+0.00433989971170763 * f[(i - 2) * fsi] - 0.0623134486317849 * f[(i - 1) * fsi] +
	1.03472110965345 * f[(i + 0) * fsi] + 0.0746651331676518 * f[(i + 1) * fsi] -
	0.0811416967546755 * f[(i + 2) * fsi] + 0.0390407773384366 * f[(i + 3) * fsi] -
	0.0105747778724968 * f[(i + 4) * fsi] + 0.00126300338771252 * f[(i + 5) * fsi];
      f35 =
	-0.00126300338771252 * f[(i - 3) * fsi] + 0.0144439268134078 * f[(i - 2) * fsi] -
	0.0976775434877353 * f[(i - 1) * fsi] + 1.10544929936535 * f[(i + 0) * fsi] -
	0.0137451039722242 * f[(i + 1) * fsi] - 0.0104135070427747 * f[(i + 2) * fsi] +
	0.00367668248248612 * f[(i + 3) * fsi] - 0.000470750770796673 * f[(i + 4) * fsi];
      f36 =
	+0.000470750770796674 * f[(i - 4) * fsi] - 0.0050290095540859 * f[(i - 3) * fsi] +
	0.0276249483957146 * f[(i - 2) * fsi] - 0.124039586652349 * f[(i - 1) * fsi] +
	1.13840185332112 * f[(i + 0) * fsi] - 0.040107147136838 * f[(i + 1) * fsi] +
	0.0027675145395322 * f[(i + 2) * fsi] - 8.93236838872815e-05 * f[(i + 3) * fsi];
      f37 =
	+8.93236838872813e-05 * f[(i - 5) * fsi] - 0.00024383870030157 * f[(i - 4) * fsi] -
	0.002527946405242 * f[(i - 3) * fsi] + 0.0226228220980269 * f[(i - 2) * fsi] -
	0.11778692878024 * f[(i - 1) * fsi] + 1.13339972702343 * f[(i + 0) * fsi] -
	0.0376060839879941 * f[(i + 1) * fsi] + 0.00205292506843395 * f[(i + 2) * fsi];
      f38 =
	-0.00205292506843395 * f[(i - 6) * fsi] + 0.0165127242313589 * f[(i - 5) * fsi] -
	0.0577257406164522 * f[(i - 4) * fsi] + 0.112435857427059 * f[(i - 3) * fsi] -
	0.12108193269235 * f[(i - 2) * fsi] - 0.00282312494793812 * f[(i - 1) * fsi] +
	1.07591782510728 * f[(i + 0) * fsi] - 0.0211826834405225 * f[(i + 1) * fsi];
      f39 =
	+0.0211826834405225 * f[(i - 7) * fsi] - 0.171514392592614 * f[(i - 6) * fsi] +
	0.609627860565989 * f[(i - 5) * fsi] - 1.24395601328571 * f[(i - 4) * fsi] +
	1.59522369826364 * f[(i - 3) * fsi] - 1.30731220536161 * f[(i - 2) * fsi] +
	0.590292011386692 * f[(i - 1) * fsi] + 0.906456357583098 * f[(i + 0) * fsi];
      f40 =
	+0.380201299132279 * f[(i + 0) * fsi] + 1.63199256632294 * f[(i + 1) * fsi] -
	2.33605987350472 * f[(i + 2) * fsi] + 2.49696704711475 * f[(i + 3) * fsi] -
	1.82873367452591 * f[(i + 4) * fsi] + 0.864276084303211 * f[(i + 5) * fsi] -
	0.237494635043114 * f[(i + 6) * fsi] + 0.0288511862005626 * f[(i + 7) * fsi];
      f41 =
	-0.0288511862005625 * f[(i - 1) * fsi] + 0.611010788736781 * f[(i + 0) * fsi] +
	0.824159352707187 * f[(i + 1) * fsi] - 0.720393446273208 * f[(i + 2) * fsi] +
	0.477384013075364 * f[(i + 3) * fsi] - 0.213067247294406 * f[(i + 4) * fsi] +
	0.0564428706874565 * f[(i + 5) * fsi] - 0.00668514543861235 * f[(i + 6) * fsi];
      f42 =
	+0.00668514543861235 * f[(i - 2) * fsi] - 0.0823323497094614 * f[(i - 1) * fsi] +
	0.798194861017927 * f[(i + 0) * fsi] + 0.449791208144896 * f[(i + 1) * fsi] -
	0.252433265570344 * f[(i + 2) * fsi] + 0.103015868513073 * f[(i + 3) * fsi] -
	0.0258831750132607 * f[(i + 4) * fsi] + 0.00296170717855784 * f[(i + 5) * fsi];
      f43 =
	-0.00296170717855784 * f[(i - 3) * fsi] + 0.030378802867075 * f[(i - 2) * fsi] -
	0.165260150709081 * f[(i - 1) * fsi] + 0.964050463017165 * f[(i + 0) * fsi] +
	0.242471705645848 * f[(i + 1) * fsi] - 0.0865776635711053 * f[(i + 2) * fsi] +
	0.0200880675134537 * f[(i + 3) * fsi] - 0.00218951758479801 * f[(i + 4) * fsi];
      f44 =
	+0.00218951758479801 * f[(i - 4) * fsi] - 0.0204778478569419 * f[(i - 3) * fsi] +
	0.0916852952414192 * f[(i - 2) * fsi] - 0.287873135457769 * f[(i - 1) * fsi] +
	1.11731669395303 * f[(i + 0) * fsi] + 0.11985872089716 * f[(i + 1) * fsi] -
	0.0252711711967612 * f[(i + 2) * fsi] + 0.00257192683506968 * f[(i + 3) * fsi];
      f45 =
	-0.00257192683506968 * f[(i - 5) * fsi] + 0.0227649322653555 * f[(i - 4) * fsi] -
	0.0924917992388929 * f[(i - 3) * fsi] + 0.235713198005321 * f[(i - 2) * fsi] -
	0.467908013912647 * f[(i - 1) * fsi] + 1.26134459671693 * f[(i + 0) * fsi] +
	0.0478447695152086 * f[(i + 1) * fsi] - 0.00469575651620379 * f[(i + 2) * fsi];
      f46 =
	+0.00469575651620379 * f[(i - 6) * fsi] - 0.0401379789647 * f[(i - 5) * fsi] +
	0.154246114719062 * f[(i - 4) * fsi] - 0.355454164146305 * f[(i - 3) * fsi] +
	0.564416154139587 * f[(i - 2) * fsi] - 0.730870378820059 * f[(i - 1) * fsi] +
	1.39282577917063 * f[(i + 0) * fsi] + 0.0102787173855783 * f[(i + 1) * fsi];
      f47 =
	-0.0102787173855783 * f[(i - 7) * fsi] + 0.0869254956008301 * f[(i - 6) * fsi] -
	0.327942065760892 * f[(i - 5) * fsi] + 0.729854288311446 * f[(i - 4) * fsi] -
	1.07496438113679 * f[(i - 3) * fsi] + 1.14002432773197 * f[(i - 2) * fsi] -
	1.01867446561625 * f[(i - 1) * fsi] + 1.47505551825526 * f[(i + 0) * fsi];
      f48 =
	+0.213242284353678 * f[(i + 0) * fsi] + 1.75315712786169 * f[(i + 1) * fsi] -
	2.12739523678503 * f[(i + 2) * fsi] + 2.1537530807077 * f[(i + 3) * fsi] -
	1.53730252439326 * f[(i + 4) * fsi] + 0.715879862346986 * f[(i + 5) * fsi] -
	0.194847994904844 * f[(i + 6) * fsi] + 0.0235134008130722 * f[(i + 7) * fsi];
      f49 =
	-0.023513400813072 * f[(i - 1) * fsi] + 0.401349490858255 * f[(i + 0) * fsi] +
	1.09478190509567 * f[(i + 1) * fsi] - 0.810644791252991 * f[(i + 2) * fsi] +
	0.507815023792656 * f[(i + 3) * fsi] - 0.220552078861214 * f[(i + 4) * fsi] +
	0.0575046395809647 * f[(i + 5) * fsi] - 0.00674078840026635 * f[(i + 6) * fsi];
      f50 =
	+0.00674078840026634 * f[(i - 2) * fsi] - 0.077439708015203 * f[(i - 1) * fsi] +
	0.590091566065713 * f[(i + 0) * fsi] + 0.717297754680752 * f[(i + 1) * fsi] -
	0.338789603234348 * f[(i + 2) * fsi] + 0.130330873377742 * f[(i + 3) * fsi] -
	0.0318100036537568 * f[(i + 4) * fsi] + 0.00357833237883411 * f[(i + 5) * fsi];
      f51 =
	-0.00357833237883411 * f[(i - 3) * fsi] + 0.0353674474309392 * f[(i - 2) * fsi] -
	0.177633014622558 * f[(i - 1) * fsi] + 0.790478179280423 * f[(i + 0) * fsi] +
	0.466814488162365 * f[(i + 1) * fsi] - 0.138402990019638 * f[(i + 2) * fsi] +
	0.0301375667703867 * f[(i + 3) * fsi] - 0.00318334462308393 * f[(i + 4) * fsi];
      f52 =
	+0.00318334462308393 * f[(i - 4) * fsi] - 0.0290450893635055 * f[(i - 3) * fsi] +
	0.124501096877289 * f[(i - 2) * fsi] - 0.355900313515258 * f[(i - 1) * fsi] +
	1.0133123028963 * f[(i + 0) * fsi] + 0.288547189269665 * f[(i + 1) * fsi] -
	0.0492693405732877 * f[(i + 2) * fsi] + 0.00467080978571533 * f[(i + 3) * fsi];
      f53 =
	-0.00467080978571533 * f[(i - 5) * fsi] + 0.0405498229088066 * f[(i - 4) * fsi] -
	0.159827763363535 * f[(i - 3) * fsi] + 0.386066444877348 * f[(i - 2) * fsi] -
	0.682856998515331 * f[(i - 1) * fsi] + 1.27487765089636 * f[(i + 0) * fsi] +
	0.157764515269636 * f[(i + 1) * fsi] - 0.0119028622875651 * f[(i + 2) * fsi];
      f54 =
	+0.0119028622875651 * f[(i - 6) * fsi] - 0.0998937080862357 * f[(i - 5) * fsi] +
	0.373829966960628 * f[(i - 4) * fsi] - 0.826388051467178 * f[(i - 3) * fsi] +
	1.2192668050069 * f[(i - 2) * fsi] - 1.34941728661897 * f[(i - 1) * fsi] +
	1.60815779494818 * f[(i + 0) * fsi] + 0.0625416169691152 * f[(i + 1) * fsi];
      f55 =
	-0.0625416169691152 * f[(i - 7) * fsi] + 0.512235798040487 * f[(i - 6) * fsi] -
	1.85105898322146 * f[(i - 5) * fsi] + 3.87616051723108 * f[(i - 4) * fsi] -
	5.20430123930524 * f[(i - 3) * fsi] + 4.72159735527735 * f[(i - 2) * fsi] -
	3.1005825617542 * f[(i - 1) * fsi] + 2.1084907307011 * f[(i + 0) * fsi];
      f56 =
	+0.140072892380947 * f[(i + 0) * fsi] + 1.73154325833008 * f[(i + 1) * fsi] -
	1.8585582028113 * f[(i + 2) * fsi] + 1.81041680253212 * f[(i + 3) * fsi] -
	1.26945920327455 * f[(i + 4) * fsi] + 0.585241521165866 * f[(i + 5) * fsi] -
	0.158272038788416 * f[(i + 6) * fsi] + 0.0190149704652622 * f[(i + 7) * fsi];
      f57 =
	-0.019014970465262 * f[(i - 1) * fsi] + 0.292192656103044 * f[(i + 0) * fsi] +
	1.19912408530274 * f[(i + 1) * fsi] - 0.793719856756617 * f[(i + 2) * fsi] +
	0.479368869963759 * f[(i + 3) * fsi] - 0.204620857219865 * f[(i + 4) * fsi] +
	0.052822348138524 * f[(i + 5) * fsi] - 0.00615227506631896 * f[(i + 6) * fsi];
      f58 =
	+0.00615227506631897 * f[(i - 2) * fsi] - 0.0682331709958139 * f[(i - 1) * fsi] +
	0.464456357959975 * f[(i + 0) * fsi] + 0.854596681588874 * f[(i + 1) * fsi] -
	0.36306060211429 * f[(i + 2) * fsi] + 0.134841466249897 * f[(i + 3) * fsi] -
	0.0323571553629338 * f[(i + 4) * fsi] + 0.00360414760797235 * f[(i + 5) * fsi];
      f59 =
	-0.00360414760797235 * f[(i - 3) * fsi] + 0.0349854559300978 * f[(i - 2) * fsi] -
	0.16914930401904 * f[(i - 1) * fsi] + 0.666288624006427 * f[(i + 0) * fsi] +
	0.60230634903081 * f[(i + 1) * fsi] - 0.161228336067838 * f[(i + 2) * fsi] +
	0.0339253332266709 * f[(i + 3) * fsi] - 0.00352397449915501 * f[(i + 4) * fsi];
      f60 =
	+0.00352397449915501 * f[(i - 4) * fsi] - 0.0317959436012124 * f[(i - 3) * fsi] +
	0.133656741906438 * f[(i - 2) * fsi] - 0.36649187597172 * f[(i - 1) * fsi] +
	0.912966838947277 * f[(i + 0) * fsi] + 0.40496377707813 * f[(i + 1) * fsi] -
	0.062557050091498 * f[(i + 2) * fsi] + 0.0057335372334308 * f[(i + 3) * fsi];
      f61 =
	-0.0057335372334308 * f[(i - 5) * fsi] + 0.0493922723666014 * f[(i - 4) * fsi] -
	0.192334986137275 * f[(i - 3) * fsi] + 0.454734826978563 * f[(i - 2) * fsi] -
	0.767839482311876 * f[(i - 1) * fsi] + 1.2340449240194 * f[(i + 0) * fsi] +
	0.244424734542067 * f[(i + 1) * fsi] - 0.0166887522240516 * f[(i + 2) * fsi];
      f62 =
	+0.0166887522240516 * f[(i - 6) * fsi] - 0.139243555025844 * f[(i - 5) * fsi] +
	0.516677334640047 * f[(i - 4) * fsi] - 1.12690511068416 * f[(i - 3) * fsi] +
	1.62294748266218 * f[(i - 2) * fsi] - 1.70240960685877 * f[(i - 1) * fsi] +
	1.70132998629285 * f[(i + 0) * fsi] + 0.110914716749654 * f[(i + 1) * fsi];
      f63 =
	-0.110914716749654 * f[(i - 7) * fsi] + 0.904006486221287 * f[(i - 6) * fsi] -
	3.24485562401617 * f[(i - 5) * fsi] + 6.7279014726207 * f[(i - 4) * fsi] -
	8.89093528315998 * f[(i - 3) * fsi] + 7.83417162064283 * f[(i - 2) * fsi] -
	4.80802167584909 * f[(i - 1) * fsi] + 2.58864772029008 * f[(i + 0) * fsi];
      fr0 =
	f0 * omega0 + f1 * omega1 + f2 * omega2 + f3 * omega3 + f4 * omega4 + f5 * omega5 +
	f6 * omega6 + f7 * omega7;
      fr1 =
	f8 * omega8 + f9 * omega9 + f10 * omega10 + f11 * omega11 + f12 * omega12 + f13 * omega13 +
	f14 * omega14 + f15 * omega15;
      fr2 =
	f16 * omega16 + f17 * omega17 + f18 * omega18 + f19 * omega19 + f20 * omega20 +
	f21 * omega21 + f22 * omega22 + f23 * omega23;
      fr3 =
	+2.00349712047662 * (f24 * omega24p + f25 * omega25p + f26 * omega26p + f27 * omega27p +
			     f28 * omega28p + f29 * omega29p + f30 * omega30p + f31 * omega31p) -
	+1.00349712047662 * (f24 * omega24m + f25 * omega25m + f26 * omega26m + f27 * omega27m +
			     f28 * omega28m + f29 * omega29m + f30 * omega30m + f31 * omega31m);
      fr4 =
	+6.78748705871543 * (f32 * omega32p + f33 * omega33p + f34 * omega34p + f35 * omega35p +
			     f36 * omega36p + f37 * omega37p + f38 * omega38p + f39 * omega39p) -
	+5.78748705871542 * (f32 * omega32m + f33 * omega33m + f34 * omega34m + f35 * omega35m +
			     f36 * omega36m + f37 * omega37m + f38 * omega38m + f39 * omega39m);
      fr5 =
	f40 * omega40 + f41 * omega41 + f42 * omega42 + f43 * omega43 + f44 * omega44 +
	f45 * omega45 + f46 * omega46 + f47 * omega47;
      fr6 =
	f48 * omega48 + f49 * omega49 + f50 * omega50 + f51 * omega51 + f52 * omega52 +
	f53 * omega53 + f54 * omega54 + f55 * omega55;
      fr7 =
	f56 * omega56 + f57 * omega57 + f58 * omega58 + f59 * omega59 + f60 * omega60 +
	f61 * omega61 + f62 * omega62 + f63 * omega63;
      fr[i * frsi + 0 * frsl] = fr0;
      fr[i * frsi + 1 * frsl] = fr1;
      fr[i * frsi + 2 * frsl] = fr2;
      fr[i * frsi + 3 * frsl] = fr3;
      fr[i * frsi + 4 * frsl] = fr4;
      fr[i * frsi + 5 * frsl] = fr5;
      fr[i * frsi + 6 * frsl] = fr6;
      fr[i * frsi + 7 * frsl] = fr7;
    }
}

PyObject *
py_gauss_radau008008 (PyObject * self, PyObject * args)
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

  gauss_radau008008 (f, n, fsi, sigma, ssi, ssr, fr, frsi, frsl);

  Py_INCREF (Py_None);
  return Py_None;
}
