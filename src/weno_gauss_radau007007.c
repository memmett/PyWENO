#include <Python.h>
#include <numpy/ndarrayobject.h>

void
gauss_radau007007 (const double *restrict f, int n, int fsi,
		   const double *restrict sigma, int ssi, int ssr,
		   double *restrict fr, int frsi, int frsl)
{
  int i;
  double sigma0, sigma1, sigma2, sigma3, sigma4, sigma5, sigma6, omega10, omega32m, omega46,
    omega41, omega32p, omega15, omega24m, omega20, omega13, omega25m, omega36, omega44, omega24p,
    omega19, omega31p, omega3, omega9, omega31m, omega40, omega14, omega27p, omega48, omega45,
    omega12, omega33p, omega35, omega16, omega33m, omega8, omega23p, omega26m, omega39, omega0,
    omega22m, omega23m, omega4, omega42, omega11, omega34m, omega17, omega25p, omega21m, omega34p,
    omega7, omega22p, omega47, omega38, omega1, omega27m, omega29p, omega26p, omega43, omega28p,
    omega30m, omega2, omega6, omega21p, omega28m, omega30p, omega5, omega37, omega18, omega29m,
    accumulator, f10, f48, f21, f39, f15, f41, f20, f13, f36, f19, f3, f28, f9, f24, f14, f32, f45,
    f12, f27, f16, f38, f29, f8, f46, f23, f0, f35, f33, f4, f40, f11, f42, f17, f30, f7, f47, f26,
    f1, f34, f37, f43, f22, f2, f6, f44, f31, f5, f25, f18, fr0, fr1, fr2, fr3, fr4, fr5, fr6;
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
      omega7 = +0.000840809747749484 / (1.0e-6 + sigma0) / (1.0e-6 + sigma0);
      accumulator += omega7;
      omega8 = +0.0296743302280462 / (1.0e-6 + sigma1) / (1.0e-6 + sigma1);
      accumulator += omega8;
      omega9 = +0.20128314526554 / (1.0e-6 + sigma2) / (1.0e-6 + sigma2);
      accumulator += omega9;
      omega10 = +0.4131554579084 / (1.0e-6 + sigma3) / (1.0e-6 + sigma3);
      accumulator += omega10;
      omega11 = +0.287887836662686 / (1.0e-6 + sigma4) / (1.0e-6 + sigma4);
      accumulator += omega11;
      omega12 = +0.0639322192560773 / (1.0e-6 + sigma5) / (1.0e-6 + sigma5);
      accumulator += omega12;
      omega13 = +0.00322620093150114 / (1.0e-6 + sigma6) / (1.0e-6 + sigma6);
      accumulator += omega13;
      omega7 /= accumulator;
      omega8 /= accumulator;
      omega9 /= accumulator;
      omega10 /= accumulator;
      omega11 /= accumulator;
      omega12 /= accumulator;
      omega13 /= accumulator;
      accumulator = 0.0;
      omega14 = +0.00245464463079135 / (1.0e-6 + sigma0) / (1.0e-6 + sigma0);
      accumulator += omega14;
      omega15 = +0.0480885370153846 / (1.0e-6 + sigma1) / (1.0e-6 + sigma1);
      accumulator += omega15;
      omega16 = +0.24688435027527 / (1.0e-6 + sigma2) / (1.0e-6 + sigma2);
      accumulator += omega16;
      omega17 = +0.413993689256407 / (1.0e-6 + sigma3) / (1.0e-6 + sigma3);
      accumulator += omega17;
      omega18 = +0.241806306014024 / (1.0e-6 + sigma4) / (1.0e-6 + sigma4);
      accumulator += omega18;
      omega19 = +0.044941596441245 / (1.0e-6 + sigma5) / (1.0e-6 + sigma5);
      accumulator += omega19;
      omega20 = +0.00183087636687712 / (1.0e-6 + sigma6) / (1.0e-6 + sigma6);
      accumulator += omega20;
      omega14 /= accumulator;
      omega15 /= accumulator;
      omega16 /= accumulator;
      omega17 /= accumulator;
      omega18 /= accumulator;
      omega19 /= accumulator;
      omega20 /= accumulator;
      accumulator = 0.0;
      omega21p = +0.000889990315267937 / +2.33602978652134 / (1.0e-6 + sigma0) / (1.0e-6 + sigma0);
      accumulator += omega21p;
      omega22p = +0.091739450899808 / +2.33602978652134 / (1.0e-6 + sigma1) / (1.0e-6 + sigma1);
      accumulator += omega22p;
      omega23p = +2.04816165924967 / +2.33602978652134 / (1.0e-6 + sigma2) / (1.0e-6 + sigma2);
      accumulator += omega23p;
      omega24p = +0.0193804876253686 / +2.33602978652134 / (1.0e-6 + sigma3) / (1.0e-6 + sigma3);
      accumulator += omega24p;
      omega25p = +0.151849505674257 / +2.33602978652134 / (1.0e-6 + sigma4) / (1.0e-6 + sigma4);
      accumulator += omega25p;
      omega26p = +0.0233154889549536 / +2.33602978652134 / (1.0e-6 + sigma5) / (1.0e-6 + sigma5);
      accumulator += omega26p;
      omega27p = +0.000693203802011996 / +2.33602978652134 / (1.0e-6 + sigma6) / (1.0e-6 + sigma6);
      accumulator += omega27p;
      omega21p /= accumulator;
      omega22p /= accumulator;
      omega23p /= accumulator;
      omega24p /= accumulator;
      omega25p /= accumulator;
      omega26p /= accumulator;
      omega27p /= accumulator;
      accumulator = 0.0;
      omega21m = +0.00177998063053587 / +1.33602978652134 / (1.0e-6 + sigma0) / (1.0e-6 + sigma0);
      accumulator += omega21m;
      omega22m = +0.183478901799616 / +1.33602978652134 / (1.0e-6 + sigma1) / (1.0e-6 + sigma1);
      accumulator += omega22m;
      omega23m = +1.02408082962483 / +1.33602978652134 / (1.0e-6 + sigma2) / (1.0e-6 + sigma2);
      accumulator += omega23m;
      omega24m = +0.0387609752507371 / +1.33602978652134 / (1.0e-6 + sigma3) / (1.0e-6 + sigma3);
      accumulator += omega24m;
      omega25m = +0.0759247528371286 / +1.33602978652134 / (1.0e-6 + sigma4) / (1.0e-6 + sigma4);
      accumulator += omega25m;
      omega26m = +0.0116577444774768 / +1.33602978652134 / (1.0e-6 + sigma5) / (1.0e-6 + sigma5);
      accumulator += omega26m;
      omega27m = +0.000346601901005998 / +1.33602978652134 / (1.0e-6 + sigma6) / (1.0e-6 + sigma6);
      accumulator += omega27m;
      omega21m /= accumulator;
      omega22m /= accumulator;
      omega23m /= accumulator;
      omega24m /= accumulator;
      omega25m /= accumulator;
      omega26m /= accumulator;
      omega27m /= accumulator;
      accumulator = 0.0;
      omega28p = +0.00215224446336954 / +2.03822361848461 / (1.0e-6 + sigma0) / (1.0e-6 + sigma0);
      accumulator += omega28p;
      omega29p = +0.0623660141904771 / +2.03822361848461 / (1.0e-6 + sigma1) / (1.0e-6 + sigma1);
      accumulator += omega29p;
      omega30p = +0.388342991653909 / +2.03822361848461 / (1.0e-6 + sigma2) / (1.0e-6 + sigma2);
      accumulator += omega30p;
      omega31p = +0.779251102225147 / +2.03822361848461 / (1.0e-6 + sigma3) / (1.0e-6 + sigma3);
      accumulator += omega31p;
      omega32p = +0.569638525601895 / +2.03822361848461 / (1.0e-6 + sigma4) / (1.0e-6 + sigma4);
      accumulator += omega32p;
      omega33p = +0.223731534188273 / +2.03822361848461 / (1.0e-6 + sigma5) / (1.0e-6 + sigma5);
      accumulator += omega33p;
      omega34p = +0.0127412061615399 / +2.03822361848461 / (1.0e-6 + sigma6) / (1.0e-6 + sigma6);
      accumulator += omega34p;
      omega28p /= accumulator;
      omega29p /= accumulator;
      omega30p /= accumulator;
      omega31p /= accumulator;
      omega32p /= accumulator;
      omega33p /= accumulator;
      omega34p /= accumulator;
      accumulator = 0.0;
      omega28m = +0.00107612223168477 / +1.03822361848462 / (1.0e-6 + sigma0) / (1.0e-6 + sigma0);
      accumulator += omega28m;
      omega29m = +0.0311830070952385 / +1.03822361848462 / (1.0e-6 + sigma1) / (1.0e-6 + sigma1);
      accumulator += omega29m;
      omega30m = +0.194171495826955 / +1.03822361848462 / (1.0e-6 + sigma2) / (1.0e-6 + sigma2);
      accumulator += omega30m;
      omega31m = +0.389625551112574 / +1.03822361848462 / (1.0e-6 + sigma3) / (1.0e-6 + sigma3);
      accumulator += omega31m;
      omega32m = +0.284819262800947 / +1.03822361848462 / (1.0e-6 + sigma4) / (1.0e-6 + sigma4);
      accumulator += omega32m;
      omega33m = +0.111865767094137 / +1.03822361848462 / (1.0e-6 + sigma5) / (1.0e-6 + sigma5);
      accumulator += omega33m;
      omega34m = +0.0254824123230799 / +1.03822361848462 / (1.0e-6 + sigma6) / (1.0e-6 + sigma6);
      accumulator += omega34m;
      omega28m /= accumulator;
      omega29m /= accumulator;
      omega30m /= accumulator;
      omega31m /= accumulator;
      omega32m /= accumulator;
      omega33m /= accumulator;
      omega34m /= accumulator;
      accumulator = 0.0;
      omega35 = +0.00250450286040109 / (1.0e-6 + sigma0) / (1.0e-6 + sigma0);
      accumulator += omega35;
      omega36 = +0.0548045023787322 / (1.0e-6 + sigma1) / (1.0e-6 + sigma1);
      accumulator += omega36;
      omega37 = +0.267728715601761 / (1.0e-6 + sigma2) / (1.0e-6 + sigma2);
      accumulator += omega37;
      omega38 = +0.415847344796905 / (1.0e-6 + sigma3) / (1.0e-6 + sigma3);
      accumulator += omega38;
      omega39 = +0.221219663715112 / (1.0e-6 + sigma4) / (1.0e-6 + sigma4);
      accumulator += omega39;
      omega40 = +0.0366117486513791 / (1.0e-6 + sigma5) / (1.0e-6 + sigma5);
      accumulator += omega40;
      omega41 = +0.00128352199570789 / (1.0e-6 + sigma6) / (1.0e-6 + sigma6);
      accumulator += omega41;
      omega35 /= accumulator;
      omega36 /= accumulator;
      omega37 /= accumulator;
      omega38 /= accumulator;
      omega39 /= accumulator;
      omega40 /= accumulator;
      omega41 /= accumulator;
      accumulator = 0.0;
      omega42 = +0.00371508559479618 / (1.0e-6 + sigma0) / (1.0e-6 + sigma0);
      accumulator += omega42;
      omega43 = +0.069517720107534 / (1.0e-6 + sigma1) / (1.0e-6 + sigma1);
      accumulator += omega43;
      omega44 = +0.298827794344072 / (1.0e-6 + sigma2) / (1.0e-6 + sigma2);
      accumulator += omega44;
      omega45 = +0.41030372301391 / (1.0e-6 + sigma3) / (1.0e-6 + sigma3);
      accumulator += omega45;
      omega46 = +0.19053468833929 / (1.0e-6 + sigma4) / (1.0e-6 + sigma4);
      accumulator += omega46;
      omega47 = +0.0264275913644135 / (1.0e-6 + sigma5) / (1.0e-6 + sigma5);
      accumulator += omega47;
      omega48 = +0.000673397235982129 / (1.0e-6 + sigma6) / (1.0e-6 + sigma6);
      accumulator += omega48;
      omega42 /= accumulator;
      omega43 /= accumulator;
      omega44 /= accumulator;
      omega45 /= accumulator;
      omega46 /= accumulator;
      omega47 /= accumulator;
      omega48 /= accumulator;
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
	+2.23306885921885 * f[(i + 0) * fsi] - 3.24776986386855 * f[(i + 1) * fsi] +
	4.2945341691929 * f[(i + 2) * fsi] - 3.85359736856154 * f[(i + 3) * fsi] +
	2.17292866965114 * f[(i + 4) * fsi] - 0.695820075039901 * f[(i + 5) * fsi] +
	0.0966556094070948 * f[(i + 6) * fsi];
      f8 =
	+0.0966556094070948 * f[(i - 1) * fsi] + 1.55647959336919 * f[(i + 0) * fsi] -
	1.21800206631956 * f[(i + 1) * fsi] + 0.911587839944587 * f[(i + 2) * fsi] -
	0.470651039313225 * f[(i + 3) * fsi] + 0.143160872102151 * f[(i + 4) * fsi] -
	0.0192308091902378 * f[(i + 5) * fsi];
      f9 =
	-0.0192308091902378 * f[(i - 2) * fsi] + 0.231271273738759 * f[(i - 1) * fsi] +
	1.1526326003742 * f[(i + 0) * fsi] - 0.544923744661239 * f[(i + 1) * fsi] +
	0.238509518286264 * f[(i + 2) * fsi] - 0.0668040463182314 * f[(i + 3) * fsi] +
	0.00854520777048664 * f[(i + 4) * fsi];
      f10 =
	+0.00854520777048664 * f[(i - 3) * fsi] - 0.0790472635836443 * f[(i - 2) * fsi] +
	0.410720636918979 * f[(i - 1) * fsi] + 0.853550328407165 * f[(i + 0) * fsi] -
	0.245841472694206 * f[(i + 1) * fsi] + 0.059060155106045 * f[(i + 2) * fsi] -
	0.0069875919248249 * f[(i + 3) * fsi];
      f11 =
	-0.0069875919248249 * f[(i - 4) * fsi] + 0.0574583512442609 * f[(i - 3) * fsi] -
	0.225786694004967 * f[(i - 2) * fsi] + 0.65528635428785 * f[(i - 1) * fsi] +
	0.608984611038294 * f[(i + 0) * fsi] - 0.0991020422728835 * f[(i + 1) * fsi] +
	0.0101470116322707 * f[(i + 2) * fsi];
      f12 =
	+0.0101470116322707 * f[(i - 5) * fsi] - 0.0780166733507201 * f[(i - 4) * fsi] +
	0.270545595521947 * f[(i - 3) * fsi] - 0.580932101134443 * f[(i - 2) * fsi] +
	1.01043176141733 * f[(i - 1) * fsi] + 0.395897366760608 * f[(i + 0) * fsi] -
	0.0280729608469883 * f[(i + 1) * fsi];
      f13 =
	-0.0280729608469883 * f[(i - 6) * fsi] + 0.206657737561189 * f[(i - 5) * fsi] -
	0.667548851137475 * f[(i - 4) * fsi] + 1.25309922516654 * f[(i - 3) * fsi] -
	1.56348573077903 * f[(i - 2) * fsi] + 1.59996393920408 * f[(i - 1) * fsi] +
	0.19938664083169 * f[(i + 0) * fsi];
      f14 =
	+1.58664250533356 * f[(i + 0) * fsi] - 1.29177731206757 * f[(i + 1) * fsi] +
	1.40613080283107 * f[(i + 2) * fsi] - 1.15413080860467 * f[(i + 3) * fsi] +
	0.619106160230349 * f[(i + 4) * fsi] - 0.19207771560441 * f[(i + 5) * fsi] +
	0.0261063678816744 * f[(i + 6) * fsi];
      f15 =
	+0.0261063678816744 * f[(i - 1) * fsi] + 1.40389793016184 * f[(i + 0) * fsi] -
	0.743543586552411 * f[(i + 1) * fsi] + 0.492407926972462 * f[(i + 2) * fsi] -
	0.240407932746065 * f[(i + 3) * fsi] + 0.0708724347151868 * f[(i + 4) * fsi] -
	0.00933314043268928 * f[(i + 5) * fsi];
      f16 =
	-0.00933314043268928 * f[(i - 2) * fsi] + 0.0914383509104994 * f[(i - 1) * fsi] +
	1.20790198107537 * f[(i + 0) * fsi] - 0.416883671408286 * f[(i + 1) * fsi] +
	0.165748011828338 * f[(i + 2) * fsi] - 0.0444119836595902 * f[(i + 3) * fsi] +
	0.00554045168636184 * f[(i + 4) * fsi];
      f17 =
	+0.00554045168636184 * f[(i - 3) * fsi] - 0.0481163022372221 * f[(i - 2) * fsi] +
	0.207787836324098 * f[(i - 1) * fsi] + 1.0139861720527 * f[(i + 0) * fsi] -
	0.222967862385622 * f[(i + 1) * fsi] + 0.0493985264147392 * f[(i + 2) * fsi] -
	0.00562882185505734 * f[(i + 3) * fsi];
      f18 =
	-0.00562882185505734 * f[(i - 4) * fsi] + 0.0449422046717632 * f[(i - 3) * fsi] -
	0.166321561193426 * f[(i - 2) * fsi] + 0.404796601251105 * f[(i - 1) * fsi] +
	0.816977407125695 * f[(i + 0) * fsi] - 0.104762603429418 * f[(i + 1) * fsi] +
	0.00999677342933789 * f[(i + 2) * fsi];
      f19 =
	+0.00999677342933789 * f[(i - 5) * fsi] - 0.0756062358604225 * f[(i - 4) * fsi] +
	0.254874446687859 * f[(i - 3) * fsi] - 0.516208631220252 * f[(i - 2) * fsi] +
	0.754683671277931 * f[(i - 1) * fsi] + 0.6070451651096 * f[(i + 0) * fsi] -
	0.0347851894240525 * f[(i + 1) * fsi];
      f20 =
	-0.0347851894240525 * f[(i - 6) * fsi] + 0.253493099397706 * f[(i - 5) * fsi] -
	0.806095213765525 * f[(i - 4) * fsi] + 1.4723560765297 * f[(i - 3) * fsi] -
	1.73369026106209 * f[(i - 2) * fsi] + 1.48517264918303 * f[(i - 1) * fsi] +
	0.363548839141232 * f[(i + 0) * fsi];
      f21 =
	+0.955667742604738 * f[(i + 0) * fsi] + 0.3762569839243 * f[(i + 1) * fsi] -
	0.786063434214423 * f[(i + 2) * fsi] + 0.789805992829874 * f[(i + 3) * fsi] -
	0.467875491382811 * f[(i + 4) * fsi] + 0.153966884655314 * f[(i + 5) * fsi] -
	0.0217586784169922 * f[(i + 6) * fsi];
      f22 =
	-0.0217586784169922 * f[(i - 1) * fsi] + 1.10797849152368 * f[(i + 0) * fsi] -
	0.080675262832537 * f[(i + 1) * fsi] - 0.0245096896196944 * f[(i + 2) * fsi] +
	0.0282522482351467 * f[(i + 3) * fsi] - 0.010943244625974 * f[(i + 4) * fsi] +
	0.00165613573636793 * f[(i + 5) * fsi];
      f23 =
	+0.00165613573636793 * f[(i - 2) * fsi] - 0.0333516285715678 * f[(i - 1) * fsi] +
	1.14275734198741 * f[(i + 0) * fsi] - 0.138640013605415 * f[(i + 1) * fsi] +
	0.0334550611531831 * f[(i + 2) * fsi] - 0.00652660222857975 * f[(i + 3) * fsi] +
	0.000649705528601457 * f[(i + 4) * fsi];
      f24 =
	+0.000649705528601457 * f[(i - 3) * fsi] - 0.00289180296384226 * f[(i - 2) * fsi] -
	0.0197078124709372 * f[(i - 1) * fsi] + 1.12001764848636 * f[(i + 0) * fsi] -
	0.115900320104364 * f[(i + 1) * fsi] + 0.0198112450525524 * f[(i + 2) * fsi] -
	0.00197866352836955 * f[(i + 3) * fsi];
      f25 =
	-0.00197866352836955 * f[(i - 4) * fsi] + 0.0145003502271883 * f[(i - 3) * fsi] -
	0.0444437370596029 * f[(i - 2) * fsi] + 0.0495454110219972 * f[(i - 1) * fsi] +
	1.05076442499342 * f[(i + 0) * fsi] - 0.0743483860086031 * f[(i + 1) * fsi] +
	0.00596060035396559 * f[(i + 2) * fsi];
      f26 =
	+0.00596060035396559 * f[(i - 5) * fsi] - 0.0437028660061286 * f[(i - 4) * fsi] +
	0.139672957660466 * f[(i - 3) * fsi] - 0.253064749448398 * f[(i - 2) * fsi] +
	0.258166423410793 * f[(i - 1) * fsi] + 0.925591817560147 * f[(i + 0) * fsi] -
	0.032624183530844 * f[(i + 1) * fsi];
      f27 =
	-0.032624183530844 * f[(i - 6) * fsi] + 0.234329885069874 * f[(i - 5) * fsi] -
	0.728810720153853 * f[(i - 4) * fsi] + 1.28151938124001 * f[(i - 3) * fsi] -
	1.39491117302794 * f[(i - 2) * fsi] + 0.943274277558517 * f[(i - 1) * fsi] +
	0.697222532844239 * f[(i + 0) * fsi];
      f28 =
	+0.513192037261408 * f[(i + 0) * fsi] + 1.2779179870319 * f[(i + 1) * fsi] -
	1.66386292361783 * f[(i + 2) * fsi] + 1.46608088040245 * f[(i + 3) * fsi] -
	0.817089403259444 * f[(i + 4) * fsi] + 0.259630391336061 * f[(i + 5) * fsi] -
	0.035868969154546 * f[(i + 6) * fsi];
      f29 =
	-0.0358689691545461 * f[(i - 1) * fsi] + 0.76427482134323 * f[(i + 0) * fsi] +
	0.524669634786433 * f[(i + 1) * fsi] - 0.408449003208718 * f[(i + 2) * fsi] +
	0.210666959993339 * f[(i + 3) * fsi] - 0.0638410510139761 * f[(i + 4) * fsi] +
	0.00854760725423811 * f[(i + 5) * fsi];
      f30 =
	+0.00854760725423811 * f[(i - 2) * fsi] - 0.0957022199342129 * f[(i - 1) * fsi] +
	0.94377457368223 * f[(i + 0) * fsi] + 0.225503380888099 * f[(i + 1) * fsi] -
	0.109282749310384 * f[(i + 2) * fsi] + 0.0311672076543382 * f[(i + 3) * fsi] -
	0.00400780023430941 * f[(i + 4) * fsi];
      f31 =
	-0.00400780023430941 * f[(i - 3) * fsi] + 0.036602208894404 * f[(i - 2) * fsi] -
	0.17986602485471 * f[(i - 1) * fsi] + 1.08404758188306 * f[(i + 0) * fsi] +
	0.0852303726872699 * f[(i + 1) * fsi] - 0.0251189443898859 * f[(i + 2) * fsi] +
	0.00311260601417232 * f[(i + 3) * fsi];
      f32 =
	+0.00311260601417232 * f[(i - 4) * fsi] - 0.0257960423335157 * f[(i - 3) * fsi] +
	0.101966935192023 * f[(i - 2) * fsi] - 0.288807235350742 * f[(i - 1) * fsi] +
	1.19298879237909 * f[(i + 0) * fsi] + 0.0198656463896512 * f[(i + 1) * fsi] -
	0.0033307022906797 * f[(i + 2) * fsi];
      f33 =
	-0.0033307022906797 * f[(i - 5) * fsi] + 0.0264275220489302 * f[(i - 4) * fsi] -
	0.0957407904377892 * f[(i - 3) * fsi] + 0.218541515365812 * f[(i - 2) * fsi] -
	0.405381815524531 * f[(i - 1) * fsi] + 1.26293354048336 * f[(i + 0) * fsi] -
	0.00344926964510669 * f[(i + 1) * fsi];
      f34 =
	-0.00344926964510669 * f[(i - 6) * fsi] + 0.0208141852250671 * f[(i - 5) * fsi] -
	0.0460071404983103 * f[(i - 4) * fsi] + 0.0249836471409446 * f[(i - 3) * fsi] +
	0.0978170777870777 * f[(i - 2) * fsi] - 0.332947152977291 * f[(i - 1) * fsi] +
	1.23878865296762 * f[(i + 0) * fsi];
      f35 =
	+0.269687852764459 * f[(i + 0) * fsi] + 1.57025164631453 * f[(i + 1) * fsi] -
	1.67799670847665 * f[(i + 2) * fsi] + 1.38403695007823 * f[(i + 3) * fsi] -
	0.747274886471338 * f[(i + 4) * fsi] + 0.233119008123666 * f[(i + 5) * fsi] -
	0.0318238623328956 * f[(i + 6) * fsi];
      f36 =
	-0.0318238623328956 * f[(i - 1) * fsi] + 0.492454889094729 * f[(i + 0) * fsi] +
	0.901950537323722 * f[(i + 1) * fsi] - 0.564161526825304 * f[(i + 2) * fsi] +
	0.270201768426882 * f[(i + 3) * fsi] - 0.0789737774805301 * f[(i + 4) * fsi] +
	0.0103519717933956 * f[(i + 5) * fsi];
      f37 =
	+0.0103519717933956 * f[(i - 2) * fsi] - 0.104287664886665 * f[(i - 1) * fsi] +
	0.709846296756037 * f[(i + 0) * fsi] + 0.539631524554876 * f[(i + 1) * fsi] -
	0.201842514056457 * f[(i + 2) * fsi] + 0.0528103607655743 * f[(i + 3) * fsi] -
	0.0065099749267608 * f[(i + 4) * fsi];
      f38 =
	-0.0065099749267608 * f[(i - 3) * fsi] + 0.0559217962807212 * f[(i - 2) * fsi] -
	0.240997138348642 * f[(i - 1) * fsi] + 0.937695419192664 * f[(i + 0) * fsi] +
	0.311782402118248 * f[(i + 1) * fsi] - 0.0651330405944802 * f[(i + 2) * fsi] +
	0.00724053627824868 * f[(i + 3) * fsi];
      f39 =
	+0.00724053627824868 * f[(i - 4) * fsi] - 0.0571937288745016 * f[(i - 3) * fsi] +
	0.207973058123943 * f[(i - 2) * fsi] - 0.494415908087345 * f[(i - 1) * fsi] +
	1.19111418893137 * f[(i + 0) * fsi] + 0.159731140275026 * f[(i + 1) * fsi] -
	0.0144492866467395 * f[(i + 2) * fsi];
      f40 =
	-0.0144492866467395 * f[(i - 5) * fsi] + 0.108385542805425 * f[(i - 4) * fsi] -
	0.360628748456031 * f[(i - 3) * fsi] + 0.713698090759825 * f[(i - 2) * fsi] -
	1.00014094072323 * f[(i - 1) * fsi] + 1.4945492085129 * f[(i + 0) * fsi] +
	0.0585861337478498 * f[(i + 1) * fsi];
      f41 =
	+0.0585861337478498 * f[(i - 6) * fsi] - 0.424552222881688 * f[(i - 5) * fsi] +
	1.33869435151027 * f[(i - 4) * fsi] - 2.41114342963077 * f[(i - 3) * fsi] +
	2.76421277193457 * f[(i - 2) * fsi] - 2.23044974942807 * f[(i - 1) * fsi] +
	1.90465214474785 * f[(i + 0) * fsi];
      f42 =
	+0.164224272840295 * f[(i + 0) * fsi] + 1.59956070186603 * f[(i + 1) * fsi] -
	1.47442826456065 * f[(i + 2) * fsi] + 1.16027978715378 * f[(i + 3) * fsi] -
	0.61289568977927 * f[(i + 4) * fsi] + 0.188832357127624 * f[(i + 5) * fsi] -
	0.0255731646478193 * f[(i + 6) * fsi];
      f43 =
	-0.0255731646478192 * f[(i - 1) * fsi] + 0.343236425375031 * f[(i + 0) * fsi] +
	1.06252424426183 * f[(i + 1) * fsi] - 0.579367501886975 * f[(i + 2) * fsi] +
	0.265219024480108 * f[(i + 3) * fsi] - 0.0758592321750626 * f[(i + 4) * fsi] +
	0.00982020459288881 * f[(i + 5) * fsi];
      f44 =
	+0.00982020459288881 * f[(i - 2) * fsi] - 0.0943145967980407 * f[(i - 1) * fsi] +
	0.549460721825695 * f[(i + 0) * fsi] + 0.718817083510722 * f[(i + 1) * fsi] -
	0.235660341135867 * f[(i + 2) * fsi] + 0.0589947280294428 * f[(i + 3) * fsi] -
	0.00711780002484095 * f[(i + 4) * fsi];
      f45 =
	-0.00711780002484095 * f[(i - 3) * fsi] + 0.0596448047667755 * f[(i - 2) * fsi] -
	0.243788397319701 * f[(i - 1) * fsi] + 0.798583722695129 * f[(i + 0) * fsi] +
	0.469694082641289 * f[(i + 1) * fsi] - 0.0861865406142075 * f[(i + 2) * fsi] +
	0.00917012785555616 * f[(i + 3) * fsi];
      f46 =
	+0.00917012785555616 * f[(i - 4) * fsi] - 0.0713086950137341 * f[(i - 3) * fsi] +
	0.252217489733455 * f[(i - 2) * fsi] - 0.564742872264167 * f[(i - 1) * fsi] +
	1.11953819763959 * f[(i + 0) * fsi] + 0.277121397674609 * f[(i + 1) * fsi] -
	0.0219956456253143 * f[(i + 2) * fsi];
      f47 =
	-0.0219956456253143 * f[(i - 5) * fsi] + 0.163139647232756 * f[(i - 4) * fsi] -
	0.533217253145335 * f[(i - 3) * fsi] + 1.02206508661946 * f[(i - 2) * fsi] -
	1.33459046915017 * f[(i - 1) * fsi] + 1.5814467557712 * f[(i + 0) * fsi] +
	0.123151878297409 * f[(i + 1) * fsi];
      f48 =
	+0.123151878297409 * f[(i - 6) * fsi] - 0.884058793707178 * f[(i - 5) * fsi] +
	2.74932909147835 * f[(i - 4) * fsi] - 4.84353299355465 * f[(i - 3) * fsi] +
	5.33238082702877 * f[(i - 2) * fsi] - 3.92077991339576 * f[(i - 1) * fsi] +
	2.44350990385306 * f[(i + 0) * fsi];
      fr0 =
	f0 * omega0 + f1 * omega1 + f2 * omega2 + f3 * omega3 + f4 * omega4 + f5 * omega5 +
	f6 * omega6;
      fr1 =
	f7 * omega7 + f8 * omega8 + f9 * omega9 + f10 * omega10 + f11 * omega11 + f12 * omega12 +
	f13 * omega13;
      fr2 =
	f14 * omega14 + f15 * omega15 + f16 * omega16 + f17 * omega17 + f18 * omega18 +
	f19 * omega19 + f20 * omega20;
      fr3 =
	+2.33602978652134 * (f21 * omega21p + f22 * omega22p + f23 * omega23p + f24 * omega24p +
			     f25 * omega25p + f26 * omega26p + f27 * omega27p) -
	+1.33602978652134 * (f21 * omega21m + f22 * omega22m + f23 * omega23m + f24 * omega24m +
			     f25 * omega25m + f26 * omega26m + f27 * omega27m);
      fr4 =
	+2.03822361848461 * (f28 * omega28p + f29 * omega29p + f30 * omega30p + f31 * omega31p +
			     f32 * omega32p + f33 * omega33p + f34 * omega34p) -
	+1.03822361848462 * (f28 * omega28m + f29 * omega29m + f30 * omega30m + f31 * omega31m +
			     f32 * omega32m + f33 * omega33m + f34 * omega34m);
      fr5 =
	f35 * omega35 + f36 * omega36 + f37 * omega37 + f38 * omega38 + f39 * omega39 +
	f40 * omega40 + f41 * omega41;
      fr6 =
	f42 * omega42 + f43 * omega43 + f44 * omega44 + f45 * omega45 + f46 * omega46 +
	f47 * omega47 + f48 * omega48;
      fr[i * frsi + 0 * frsl] = fr0;
      fr[i * frsi + 1 * frsl] = fr1;
      fr[i * frsi + 2 * frsl] = fr2;
      fr[i * frsi + 3 * frsl] = fr3;
      fr[i * frsi + 4 * frsl] = fr4;
      fr[i * frsi + 5 * frsl] = fr5;
      fr[i * frsi + 6 * frsl] = fr6;
    }
}

PyObject *
py_gauss_radau007007 (PyObject * self, PyObject * args)
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

  gauss_radau007007 (f, n, fsi, sigma, ssi, ssr, fr, frsi, frsl);

  Py_INCREF (Py_None);
  return Py_None;
}
