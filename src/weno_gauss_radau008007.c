#include <Python.h>
#include <numpy/ndarrayobject.h>

void
gauss_radau008007 (const double *restrict f, int n, int fsi,
		   const double *restrict sigma, int ssi, int ssr,
		   double *restrict fr, int frsi, int frsl)
{
  int i;
  double sigma0, sigma1, sigma2, sigma3, sigma4, sigma5, sigma6, sigma7, omega39p, omega11,
    omega36m, omega39m, omega46, omega36p, omega7, omega27m, omega22, omega14, omega28m, omega41,
    omega50, omega27p, omega21, omega35p, omega3, omega47, omega10, omega35m, omega52, omega45,
    omega28p, omega16, omega30p, omega54, omega31m, omega51, omega13, omega37p, omega29m, omega40,
    omega18, omega37m, omega9, omega31p, omega26p, omega23, omega44, omega0, omega25m, omega26m,
    omega4, omega48, omega12, omega55, omega38m, omega19, omega17, omega24m, omega38p, omega8,
    omega25p, omega53, omega43, omega1, omega30m, omega33p, omega29p, omega49, omega32p, omega34m,
    omega2, omega6, omega24p, omega32m, omega34p, omega15, omega5, omega42, omega20, omega33m,
    accumulator, f39, f11, f52, f24, f44, f7, f46, f22, f14, f41, f31, f21, f3, f32, f10, f55, f27,
    f16, f36, f51, f13, f30, f18, f47, f43, f33, f9, f23, f26, f0, f54, f40, f37, f4, f45, f12, f48,
    f19, f17, f34, f8, f53, f29, f1, f38, f42, f49, f25, f2, f6, f50, f35, f15, f5, f28, f20, fr0,
    fr1, fr2, fr3, fr4, fr5, fr6;
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
      omega8 = +0.00022948429341163 / (1.0e-6 + sigma0) / (1.0e-6 + sigma0);
      accumulator += omega8;
      omega9 = +0.0108181528407472 / (1.0e-6 + sigma1) / (1.0e-6 + sigma1);
      accumulator += omega9;
      omega10 = +0.1030479077952 / (1.0e-6 + sigma2) / (1.0e-6 + sigma2);
      accumulator += omega10;
      omega11 = +0.318723879144918 / (1.0e-6 + sigma3) / (1.0e-6 + sigma3);
      accumulator += omega11;
      omega12 = +0.372739531223262 / (1.0e-6 + sigma4) / (1.0e-6 + sigma4);
      accumulator += omega12;
      omega13 = +0.167508225975975 / (1.0e-6 + sigma5) / (1.0e-6 + sigma5);
      accumulator += omega13;
      omega14 = +0.0259664805240208 / (1.0e-6 + sigma6) / (1.0e-6 + sigma6);
      accumulator += omega14;
      omega15 = +0.00096633820246494 / (1.0e-6 + sigma7) / (1.0e-6 + sigma7);
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
      omega16 = +0.000750378755849019 / (1.0e-6 + sigma0) / (1.0e-6 + sigma0);
      accumulator += omega16;
      omega17 = +0.019038242342561 / (1.0e-6 + sigma1) / (1.0e-6 + sigma1);
      accumulator += omega17;
      omega18 = +0.136882808855279 / (1.0e-6 + sigma2) / (1.0e-6 + sigma2);
      accumulator += omega18;
      omega19 = +0.347650911442293 / (1.0e-6 + sigma3) / (1.0e-6 + sigma3);
      accumulator += omega19;
      omega20 = +0.344919196566064 / (1.0e-6 + sigma4) / (1.0e-6 + sigma4);
      accumulator += omega20;
      omega21 = +0.132760813753893 / (1.0e-6 + sigma5) / (1.0e-6 + sigma5);
      accumulator += omega21;
      omega22 = +0.0174674700081812 / (1.0e-6 + sigma6) / (1.0e-6 + sigma6);
      accumulator += omega22;
      omega23 = +0.000530178275880165 / (1.0e-6 + sigma7) / (1.0e-6 + sigma7);
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
      omega24p = +0.000218973348207007 / +7.15903300005099 / (1.0e-6 + sigma0) / (1.0e-6 + sigma0);
      accumulator += omega24p;
      omega25p = +0.0221732847040048 / +7.15903300005099 / (1.0e-6 + sigma1) / (1.0e-6 + sigma1);
      accumulator += omega25p;
      omega26p = +5.10584209978484 / +7.15903300005099 / (1.0e-6 + sigma2) / (1.0e-6 + sigma2);
      accumulator += omega26p;
      omega27p = +1.69728540863145 / +7.15903300005099 / (1.0e-6 + sigma3) / (1.0e-6 + sigma3);
      accumulator += omega27p;
      omega28p = +0.238840474554992 / +7.15903300005099 / (1.0e-6 + sigma4) / (1.0e-6 + sigma4);
      accumulator += omega28p;
      omega29p = +0.0855831786549371 / +7.15903300005099 / (1.0e-6 + sigma5) / (1.0e-6 + sigma5);
      accumulator += omega29p;
      omega30p = +0.00889233789801774 / +7.15903300005099 / (1.0e-6 + sigma6) / (1.0e-6 + sigma6);
      accumulator += omega30p;
      omega31p = +0.00019724247454037 / +7.15903300005099 / (1.0e-6 + sigma7) / (1.0e-6 + sigma7);
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
      omega24m = +0.000437946696414014 / +6.159033000051 / (1.0e-6 + sigma0) / (1.0e-6 + sigma0);
      accumulator += omega24m;
      omega25m = +0.0443465694080096 / +6.159033000051 / (1.0e-6 + sigma1) / (1.0e-6 + sigma1);
      accumulator += omega25m;
      omega26m = +2.55292104989242 / +6.159033000051 / (1.0e-6 + sigma2) / (1.0e-6 + sigma2);
      accumulator += omega26m;
      omega27m = +3.39457081726291 / +6.159033000051 / (1.0e-6 + sigma3) / (1.0e-6 + sigma3);
      accumulator += omega27m;
      omega28m = +0.119420237277496 / +6.159033000051 / (1.0e-6 + sigma4) / (1.0e-6 + sigma4);
      accumulator += omega28m;
      omega29m = +0.0427915893274686 / +6.159033000051 / (1.0e-6 + sigma5) / (1.0e-6 + sigma5);
      accumulator += omega29m;
      omega30m = +0.00444616894900887 / +6.159033000051 / (1.0e-6 + sigma6) / (1.0e-6 + sigma6);
      accumulator += omega30m;
      omega31m = +9.86212372701849e-05 / +6.159033000051 / (1.0e-6 + sigma7) / (1.0e-6 + sigma7);
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
      omega32p = +0.000610541457283598 / +2.00580681389013 / (1.0e-6 + sigma0) / (1.0e-6 + sigma0);
      accumulator += omega32p;
      omega33p = +0.0235283229594653 / +2.00580681389013 / (1.0e-6 + sigma1) / (1.0e-6 + sigma1);
      accumulator += omega33p;
      omega34p = +0.204125488058891 / +2.00580681389013 / (1.0e-6 + sigma2) / (1.0e-6 + sigma2);
      accumulator += omega34p;
      omega35p = +0.60710914177294 / +2.00580681389013 / (1.0e-6 + sigma3) / (1.0e-6 + sigma3);
      accumulator += omega35p;
      omega36p = +0.718100846903865 / +2.00580681389013 / (1.0e-6 + sigma4) / (1.0e-6 + sigma4);
      accumulator += omega36p;
      omega37p = +0.351224611619861 / +2.00580681389013 / (1.0e-6 + sigma5) / (1.0e-6 + sigma5);
      accumulator += omega37p;
      omega38p = +0.0991722564877777 / +2.00580681389013 / (1.0e-6 + sigma6) / (1.0e-6 + sigma6);
      accumulator += omega38p;
      omega39p = +0.00193560463004744 / +2.00580681389013 / (1.0e-6 + sigma7) / (1.0e-6 + sigma7);
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
      omega32m = +0.000305270728641799 / +1.00580681389014 / (1.0e-6 + sigma0) / (1.0e-6 + sigma0);
      accumulator += omega32m;
      omega33m = +0.0117641614797326 / +1.00580681389014 / (1.0e-6 + sigma1) / (1.0e-6 + sigma1);
      accumulator += omega33m;
      omega34m = +0.102062744029446 / +1.00580681389014 / (1.0e-6 + sigma2) / (1.0e-6 + sigma2);
      accumulator += omega34m;
      omega35m = +0.30355457088647 / +1.00580681389014 / (1.0e-6 + sigma3) / (1.0e-6 + sigma3);
      accumulator += omega35m;
      omega36m = +0.359050423451933 / +1.00580681389014 / (1.0e-6 + sigma4) / (1.0e-6 + sigma4);
      accumulator += omega36m;
      omega37m = +0.17561230580993 / +1.00580681389014 / (1.0e-6 + sigma5) / (1.0e-6 + sigma5);
      accumulator += omega37m;
      omega38m = +0.0495861282438888 / +1.00580681389014 / (1.0e-6 + sigma6) / (1.0e-6 + sigma6);
      accumulator += omega38m;
      omega39m = +0.00387120926009489 / +1.00580681389014 / (1.0e-6 + sigma7) / (1.0e-6 + sigma7);
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
      omega40 = +0.000737908364786229 / (1.0e-6 + sigma0) / (1.0e-6 + sigma0);
      accumulator += omega40;
      omega41 = +0.0217980371759074 / (1.0e-6 + sigma1) / (1.0e-6 + sigma1);
      accumulator += omega41;
      omega42 = +0.151633152709199 / (1.0e-6 + sigma2) / (1.0e-6 + sigma2);
      accumulator += omega42;
      omega43 = +0.36189510977496 / (1.0e-6 + sigma3) / (1.0e-6 + sigma3);
      accumulator += omega43;
      omega44 = +0.332763905038514 / (1.0e-6 + sigma4) / (1.0e-6 + sigma4);
      accumulator += omega44;
      omega45 = +0.117038400047745 / (1.0e-6 + sigma5) / (1.0e-6 + sigma5);
      accumulator += omega45;
      omega46 = +0.0137712630205917 / (1.0e-6 + sigma6) / (1.0e-6 + sigma6);
      accumulator += omega46;
      omega47 = +0.000362223868292532 / (1.0e-6 + sigma7) / (1.0e-6 + sigma7);
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
      omega48 = +0.00112414067511459 / (1.0e-6 + sigma0) / (1.0e-6 + sigma0);
      accumulator += omega48;
      omega49 = +0.0285899327766517 / (1.0e-6 + sigma1) / (1.0e-6 + sigma1);
      accumulator += omega49;
      omega50 = +0.176616867899453 / (1.0e-6 + sigma2) / (1.0e-6 + sigma2);
      accumulator += omega50;
      omega51 = +0.377779759381928 / (1.0e-6 + sigma3) / (1.0e-6 + sigma3);
      accumulator += omega51;
      omega52 = +0.310330566322444 / (1.0e-6 + sigma4) / (1.0e-6 + sigma4);
      accumulator += omega52;
      omega53 = +0.0958901640584047 / (1.0e-6 + sigma5) / (1.0e-6 + sigma5);
      accumulator += omega53;
      omega54 = +0.00948742863959227 / (1.0e-6 + sigma6) / (1.0e-6 + sigma6);
      accumulator += omega54;
      omega55 = +0.000181140246349535 / (1.0e-6 + sigma7) / (1.0e-6 + sigma7);
      accumulator += omega55;
      omega48 /= accumulator;
      omega49 /= accumulator;
      omega50 /= accumulator;
      omega51 /= accumulator;
      omega52 /= accumulator;
      omega53 /= accumulator;
      omega54 /= accumulator;
      omega55 /= accumulator;
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
	+2.3156736344548 * f[(i + 0) * fsi] - 3.82600329052017 * f[(i + 1) * fsi] +
	6.02923444914775 * f[(i + 2) * fsi] - 6.74476450181961 * f[(i + 3) * fsi] +
	5.06409580290921 * f[(i + 4) * fsi] - 2.43052035499474 * f[(i + 5) * fsi] +
	0.674889036058709 * f[(i + 6) * fsi] - 0.0826047752359449 * f[(i + 7) * fsi];
      f9 =
	+0.0826047752359449 * f[(i - 1) * fsi] + 1.65483543256724 * f[(i + 0) * fsi] -
	1.51306958391371 * f[(i + 1) * fsi] + 1.40336703593483 * f[(i + 2) * fsi] -
	0.962430235303472 * f[(i + 3) * fsi] + 0.438228389696299 * f[(i + 4) * fsi] -
	0.117586648388287 * f[(i + 5) * fsi] + 0.0140508341711499 * f[(i + 6) * fsi];
      f10 =
	-0.0140508341711499 * f[(i - 2) * fsi] + 0.195011448605144 * f[(i - 1) * fsi] +
	1.26141207577504 * f[(i + 0) * fsi] - 0.726222870329314 * f[(i + 1) * fsi] +
	0.41980864395434 * f[(i + 2) * fsi] - 0.175583521719077 * f[(i + 3) * fsi] +
	0.0448050329041017 * f[(i + 4) * fsi] - 0.00517997501908787 * f[(i + 5) * fsi];
      f11 =
	+0.00517997501908787 * f[(i - 3) * fsi] - 0.0554906343238529 * f[(i - 2) * fsi] +
	0.340050749139604 * f[(i - 1) * fsi] + 0.971333474706122 * f[(i + 0) * fsi] -
	0.363624618993163 * f[(i + 1) * fsi] + 0.129730042885419 * f[(i + 2) * fsi] -
	0.0305442211846163 * f[(i + 3) * fsi] + 0.00336523275139877 * f[(i + 4) * fsi];
      f12 =
	-0.00336523275139877 * f[(i - 4) * fsi] + 0.0321018370302781 * f[(i - 3) * fsi] -
	0.149717151363018 * f[(i - 2) * fsi] + 0.528503783217936 * f[(i - 1) * fsi] +
	0.735767182108208 * f[(i + 0) * fsi] - 0.175171584914832 * f[(i + 1) * fsi] +
	0.0355035258462536 * f[(i + 2) * fsi] - 0.00362235917342613 * f[(i + 3) * fsi];
      f13 =
	+0.00362235917342613 * f[(i - 5) * fsi] - 0.0323441061388078 * f[(i - 4) * fsi] +
	0.13352789388621 * f[(i - 3) * fsi] - 0.352569265074882 * f[(i - 2) * fsi] +
	0.782068925357765 * f[(i - 1) * fsi] + 0.532915068396345 * f[(i + 0) * fsi] -
	0.0737455280589006 * f[(i + 1) * fsi] + 0.00652465245884461 * f[(i + 2) * fsi];
      f14 =
	-0.00652465245884461 * f[(i - 6) * fsi] + 0.0558195788441831 * f[(i - 5) * fsi] -
	0.215034374986457 * f[(i - 4) * fsi] + 0.498908431581508 * f[(i - 3) * fsi] -
	0.809294937194005 * f[(i - 2) * fsi] + 1.14744946305306 * f[(i - 1) * fsi] +
	0.350224799548696 * f[(i + 0) * fsi] - 0.0215483083881437 * f[(i + 1) * fsi];
      f15 =
	+0.0215483083881437 * f[(i - 7) * fsi] - 0.178911119563994 * f[(i - 6) * fsi] +
	0.659172213712206 * f[(i - 5) * fsi] - 1.4217396447225 * f[(i - 4) * fsi] +
	2.00729001875157 * f[(i - 3) * fsi] - 2.01600020693005 * f[(i - 2) * fsi] +
	1.75080209792109 * f[(i - 1) * fsi] + 0.177838332443546 * f[(i + 0) * fsi];
      f16 =
	+1.60649547424959 * f[(i + 0) * fsi] - 1.43074809447979 * f[(i + 1) * fsi] +
	1.8230431500677 * f[(i + 2) * fsi] - 1.84898472066573 * f[(i + 3) * fsi] +
	1.31396007229141 * f[(i + 4) * fsi] - 0.608990062841045 * f[(i + 5) * fsi] +
	0.165077150293886 * f[(i + 6) * fsi] - 0.0198529689160302 * f[(i + 7) * fsi];
      f17 =
	+0.0198529689160303 * f[(i - 1) * fsi] + 1.44767172292135 * f[(i + 0) * fsi] -
	0.874864964830938 * f[(i + 1) * fsi] + 0.711276890770008 * f[(i + 2) * fsi] -
	0.45927689654361 * f[(i + 3) * fsi] + 0.202193812993714 * f[(i + 4) * fsi] -
	0.0531069331921984 * f[(i + 5) * fsi] + 0.00625339896564415 * f[(i + 6) * fsi];
      f18 =
	-0.00625339896564415 * f[(i - 2) * fsi] + 0.0698801606411835 * f[(i - 1) * fsi] +
	1.27257655188331 * f[(i + 0) * fsi] - 0.524674622754866 * f[(i + 1) * fsi] +
	0.273538963174917 * f[(i + 2) * fsi] - 0.109086554467538 * f[(i + 3) * fsi] +
	0.0270986419556777 * f[(i + 4) * fsi] - 0.00307974146704512 * f[(i + 5) * fsi];
      f19 =
	+0.00307974146704512 * f[(i - 3) * fsi] - 0.0308913307020051 * f[(i - 2) * fsi] +
	0.156112921718447 * f[(i - 1) * fsi] + 1.10011102972879 * f[(i + 0) * fsi] -
	0.309092720061707 * f[(i + 1) * fsi] + 0.10107344102039 * f[(i + 2) * fsi] -
	0.0228537933902743 * f[(i + 3) * fsi] + 0.00246071021931671 * f[(i + 4) * fsi];
      f20 =
	-0.00246071021931671 * f[(i - 4) * fsi] + 0.0227654232215788 * f[(i - 3) * fsi] -
	0.0997912168428731 * f[(i - 2) * fsi] + 0.293912694000183 * f[(i - 1) * fsi] +
	0.927861314376617 * f[(i + 0) * fsi] - 0.171292947779971 * f[(i + 1) * fsi] +
	0.0321735548795222 * f[(i + 2) * fsi] - 0.00316811163574062 * f[(i + 3) * fsi];
      f21 =
	+0.00316811163574062 * f[(i - 5) * fsi] - 0.0278056033052417 * f[(i - 4) * fsi] +
	0.111472549022316 * f[(i - 3) * fsi] - 0.277205468444348 * f[(i - 2) * fsi] +
	0.515680508502027 * f[(i - 1) * fsi] + 0.750447062775142 * f[(i + 0) * fsi] -
	0.0825858219792333 * f[(i + 1) * fsi] + 0.00682866179359726 * f[(i + 2) * fsi];
      f22 =
	-0.00682866179359726 * f[(i - 6) * fsi] + 0.0577974059845187 * f[(i - 5) * fsi] -
	0.219008133525965 * f[(i - 4) * fsi] + 0.493877609463763 * f[(i - 3) * fsi] -
	0.755211793996156 * f[(i - 2) * fsi] + 0.898085568943473 * f[(i - 1) * fsi] +
	0.559244532554419 * f[(i + 0) * fsi] - 0.0279565276304553 * f[(i + 1) * fsi];
      f23 =
	+0.0279565276304553 * f[(i - 7) * fsi] - 0.230480882837239 * f[(i - 6) * fsi] +
	0.840580179637266 * f[(i - 5) * fsi] - 1.78457368083146 * f[(i - 4) * fsi] +
	2.45083454359563 * f[(i - 3) * fsi] - 2.32077734130165 * f[(i - 2) * fsi] +
	1.68086834259622 * f[(i - 1) * fsi] + 0.335592311510777 * f[(i + 0) * fsi];
      f24 =
	+0.935630041656355 * f[(i + 0) * fsi] + 0.516520890562979 * f[(i + 1) * fsi] -
	1.20685515413046 * f[(i + 2) * fsi] + 1.49112552602327 * f[(i + 3) * fsi] -
	1.1691950245762 * f[(i + 4) * fsi] + 0.574758604571349 * f[(i + 5) * fsi] -
	0.162022585055671 * f[(i + 6) * fsi] + 0.0200377009483826 * f[(i + 7) * fsi];
      f25 =
	-0.0200377009483826 * f[(i - 1) * fsi] + 1.09593164924342 * f[(i + 0) * fsi] -
	0.0445347359917345 * f[(i + 1) * fsi] - 0.0847439010210323 * f[(i + 2) * fsi] +
	0.0884864596364846 * f[(i + 3) * fsi] - 0.0470837714667766 * f[(i + 4) * fsi] +
	0.0137029780166355 * f[(i + 5) * fsi] - 0.00172097746860965 * f[(i + 6) * fsi];
      f26 =
	+0.00172097746860965 * f[(i - 2) * fsi] - 0.0338055206972598 * f[(i - 1) * fsi] +
	1.14411901836449 * f[(i + 0) * fsi] - 0.140909474233875 * f[(i + 1) * fsi] +
	0.0357245217816433 * f[(i + 2) * fsi] - 0.0078882786056559 * f[(i + 3) * fsi] +
	0.0011035976542935 * f[(i + 4) * fsi] - 6.48417322417221e-05 * f[(i + 5) * fsi];
      f27 =
	+6.48417322417216e-05 * f[(i - 3) * fsi] + 0.00120224361067588 * f[(i - 2) * fsi] -
	0.0319899521944916 * f[(i - 1) * fsi] + 1.14048788135895 * f[(i + 0) * fsi] -
	0.136370552976954 * f[(i + 1) * fsi] + 0.0320933847761068 * f[(i + 2) * fsi] -
	0.00607271010288769 * f[(i + 3) * fsi] + 0.000584863796359735 * f[(i + 4) * fsi];
      f28 =
	-0.000584863796359735 * f[(i - 4) * fsi] + 0.0047437521031196 * f[(i - 3) * fsi] -
	0.0151739426873967 * f[(i - 2) * fsi] + 0.000762420401653463 * f[(i - 1) * fsi] +
	1.09954741561377 * f[(i + 0) * fsi] - 0.103618180380809 * f[(i + 1) * fsi] +
	0.0157171984780343 * f[(i + 2) * fsi] - 0.00139379973200982 * f[(i + 3) * fsi];
      f29 =
	+0.00139379973200982 * f[(i - 5) * fsi] - 0.0117352616524383 * f[(i - 4) * fsi] +
	0.0437701445993945 * f[(i - 3) * fsi] - 0.0932267276799464 * f[(i - 2) * fsi] +
	0.0983284016423408 * f[(i - 1) * fsi] + 1.02149463062122 * f[(i + 0) * fsi] -
	0.0645917878845344 * f[(i + 1) * fsi] + 0.00456680062195577 * f[(i + 2) * fsi];
      f30 =
	-0.00456680062195577 * f[(i - 6) * fsi] + 0.037928204707656 * f[(i - 5) * fsi] -
	0.1396056790672 * f[(i - 4) * fsi] + 0.299510979428918 * f[(i - 3) * fsi] -
	0.41290277121685 * f[(i - 2) * fsi] + 0.354069236471864 * f[(i - 1) * fsi] +
	0.893624213206457 * f[(i + 0) * fsi] - 0.0280573829088882 * f[(i + 1) * fsi];
      f31 =
	+0.0280573829088882 * f[(i - 7) * fsi] - 0.229025863893062 * f[(i - 6) * fsi] +
	0.823534926156526 * f[(i - 5) * fsi] - 1.71081912196494 * f[(i - 4) * fsi] +
	2.26352778305109 * f[(i - 3) * fsi] - 1.98411621411459 * f[(i - 2) * fsi] +
	1.13967595792073 * f[(i - 1) * fsi] + 0.669165149935351 * f[(i + 0) * fsi];
      f32 =
	+0.483442084174975 * f[(i + 0) * fsi] + 1.48616765863693 * f[(i + 1) * fsi] -
	2.28861193843293 * f[(i + 2) * fsi] + 2.50732923842763 * f[(i + 3) * fsi] -
	1.85833776128462 * f[(i + 4) * fsi] + 0.884379406151167 * f[(i + 5) * fsi] -
	0.244118640759581 * f[(i + 6) * fsi] + 0.0297499530864336 * f[(i + 7) * fsi];
      f33 =
	-0.0297499530864336 * f[(i - 1) * fsi] + 0.721441708866443 * f[(i + 0) * fsi] +
	0.653168972216793 * f[(i + 1) * fsi] - 0.622614565592651 * f[(i + 2) * fsi] +
	0.424832522377273 * f[(i + 3) * fsi] - 0.192340388444337 * f[(i + 4) * fsi] +
	0.051380719731025 * f[(i + 5) * fsi] - 0.0061190160681124 * f[(i + 6) * fsi];
      f34 =
	+0.00611901606811241 * f[(i - 2) * fsi] - 0.0787020816313328 * f[(i - 1) * fsi] +
	0.89277415877359 * f[(i + 0) * fsi] + 0.310504072402499 * f[(i + 1) * fsi] -
	0.194283440824783 * f[(i + 2) * fsi] + 0.0821676225629781 * f[(i + 3) * fsi] -
	0.0210079385371894 * f[(i + 4) * fsi] + 0.00242859118612571 * f[(i + 5) * fsi];
      f35 =
	-0.00242859118612571 * f[(i - 3) * fsi] + 0.0255477455571181 * f[(i - 2) * fsi] -
	0.146702634842853 * f[(i - 1) * fsi] + 1.02877526519663 * f[(i + 0) * fsi] +
	0.1405026893737 * f[(i + 1) * fsi] - 0.0582823344017437 * f[(i + 2) * fsi] +
	0.0141670693514582 * f[(i + 3) * fsi] - 0.00157920904818371 * f[(i + 4) * fsi];
      f36 =
	+0.0015792090481837 * f[(i - 4) * fsi] - 0.0150622635715953 * f[(i - 3) * fsi] +
	0.0697655989062618 * f[(i - 2) * fsi] - 0.23513834154114 * f[(i - 1) * fsi] +
	1.13931989856949 * f[(i + 0) * fsi] + 0.0520669826754121 * f[(i + 1) * fsi] -
	0.0140644810526 * f[(i + 2) * fsi] + 0.00153339696598862 * f[(i + 3) * fsi];
      f37 =
	-0.00153339696598862 * f[(i - 5) * fsi] + 0.0138463847760926 * f[(i - 4) * fsi] -
	0.0579973786192766 * f[(i - 3) * fsi] + 0.155635829001624 * f[(i - 2) * fsi] -
	0.342476129160343 * f[(i - 1) * fsi] + 1.22519012866485 * f[(i + 0) * fsi] +
	0.00913186762773091 * f[(i + 1) * fsi] - 0.00179730532469108 * f[(i + 2) * fsi];
      f38 =
	+0.00179730532469108 * f[(i - 6) * fsi] - 0.0159118395635173 * f[(i - 5) * fsi] +
	0.0641709338674429 * f[(i - 4) * fsi] - 0.158646476801977 * f[(i - 3) * fsi] +
	0.28144720173 * f[(i - 2) * fsi] - 0.443125227343044 * f[(i - 1) * fsi] +
	1.2755146777562 * f[(i + 0) * fsi] - 0.00524657496979777 * f[(i + 1) * fsi];
      f39 =
	+0.00524657496979777 * f[(i - 7) * fsi] - 0.0401752944336911 * f[(i - 6) * fsi] +
	0.13099225959082 * f[(i - 5) * fsi] - 0.229637264441233 * f[(i - 4) * fsi] +
	0.208613771083866 * f[(i - 3) * fsi] - 0.012360996578675 * f[(i - 2) * fsi] -
	0.296221128188706 * f[(i - 1) * fsi] + 1.23354207799782 * f[(i + 0) * fsi];
      f40 =
	+0.244712184505282 * f[(i + 0) * fsi] + 1.74508132412877 * f[(i + 1) * fsi] -
	2.20248574191937 * f[(i + 2) * fsi] + 2.25818533914943 * f[(i + 3) * fsi] -
	1.62142327554254 * f[(i + 4) * fsi] + 0.757608041566387 * f[(i + 5) * fsi] -
	0.206653540147136 * f[(i + 6) * fsi] + 0.0249756682591773 * f[(i + 7) * fsi];
      f41 =
	-0.0249756682591772 * f[(i - 1) * fsi] + 0.4445175305787 * f[(i + 0) * fsi] +
	1.04576261287181 * f[(i + 1) * fsi] - 0.803848319405445 * f[(i + 2) * fsi] +
	0.509888561007024 * f[(i + 3) * fsi] - 0.222785853028615 * f[(i + 4) * fsi] +
	0.058289330309424 * f[(i + 5) * fsi] - 0.00684819407371834 * f[(i + 6) * fsi];
      f42 =
	+0.00684819407371834 * f[(i - 2) * fsi] - 0.079761220848924 * f[(i - 1) * fsi] +
	0.636266964642814 * f[(i + 0) * fsi] + 0.662263744743581 * f[(i + 1) * fsi] -
	0.324474734245162 * f[(i + 2) * fsi] + 0.126389692878797 * f[(i + 3) * fsi] -
	0.0310364189645017 * f[(i + 4) * fsi] + 0.00350377771967728 * f[(i + 5) * fsi];
      f43 =
	-0.00350377771967728 * f[(i - 3) * fsi] + 0.0348784158311366 * f[(i - 2) * fsi] -
	0.177866996999888 * f[(i - 1) * fsi] + 0.832478516944741 * f[(i + 0) * fsi] +
	0.416999304366172 * f[(i + 1) * fsi] - 0.128263181943234 * f[(i + 2) * fsi] +
	0.0282839167278333 * f[(i + 3) * fsi] - 0.00300619720708352 * f[(i + 4) * fsi];
      f44 =
	+0.00300619720708352 * f[(i - 4) * fsi] - 0.0275533553763454 * f[(i - 3) * fsi] +
	0.119051937629475 * f[(i - 2) * fsi] - 0.346214040596565 * f[(i - 1) * fsi] +
	1.04291232144059 * f[(i + 0) * fsi] + 0.248652260769495 * f[(i + 1) * fsi] -
	0.0440896601448956 * f[(i + 2) * fsi] + 0.00423433907116516 * f[(i + 3) * fsi];
      f45 =
	-0.00423433907116516 * f[(i - 5) * fsi] + 0.0368809097764048 * f[(i - 4) * fsi] -
	0.14611484936897 * f[(i - 3) * fsi] + 0.356174925614724 * f[(i - 2) * fsi] -
	0.642617775578126 * f[(i - 1) * fsi] + 1.28003530942584 * f[(i + 0) * fsi] +
	0.13009076677687 * f[(i + 1) * fsi] - 0.0102149475755743 * f[(i + 2) * fsi];
      f46 =
	+0.0102149475755743 * f[(i - 6) * fsi] - 0.0859539196757597 * f[(i - 5) * fsi] +
	0.322899441892486 * f[(i - 4) * fsi] - 0.718151913601132 * f[(i - 3) * fsi] +
	1.07122125590493 * f[(i - 2) * fsi] - 1.21465483981029 * f[(i - 1) * fsi] +
	1.56605384154192 * f[(i + 0) * fsi] + 0.0483711861722755 * f[(i + 1) * fsi];
      f47 =
	-0.0483711861722755 * f[(i - 7) * fsi] + 0.397184436953778 * f[(i - 6) * fsi] -
	1.44034713249947 * f[(i - 5) * fsi] + 3.03168586753991 * f[(i - 4) * fsi] -
	4.10413494566042 * f[(i - 3) * fsi] + 3.78000768155235 * f[(i - 2) * fsi] -
	2.569048052634 * f[(i - 1) * fsi] + 1.95302333092012 * f[(i + 0) * fsi];
      f48 =
	+0.144860184446033 * f[(i + 0) * fsi] + 1.73510932062587 * f[(i + 1) * fsi] -
	1.88107412084015 * f[(i + 2) * fsi] + 1.83802288095294 * f[(i + 3) * fsi] -
	1.29063878357842 * f[(i + 4) * fsi] + 0.595478213407121 * f[(i + 5) * fsi] -
	0.16112178340765 * f[(i + 6) * fsi] + 0.0193640883942617 * f[(i + 7) * fsi];
      f49 =
	-0.0193640883942616 * f[(i - 1) * fsi] + 0.299772891600127 * f[(i + 0) * fsi] +
	1.19291484558654 * f[(i + 1) * fsi] - 0.796685170761491 * f[(i + 2) * fsi] +
	0.482536693354624 * f[(i + 3) * fsi] - 0.206249833499772 * f[(i + 4) * fsi] +
	0.053283738367792 * f[(i + 5) * fsi] - 0.00620907625355762 * f[(i + 6) * fsi];
      f50 =
	+0.00620907625355761 * f[(i - 2) * fsi] - 0.0690366984227224 * f[(i - 1) * fsi] +
	0.473627026699741 * f[(i + 0) * fsi] + 0.845206575387314 * f[(i + 1) * fsi] -
	0.362049833012459 * f[(i + 2) * fsi] + 0.134828423155398 * f[(i + 3) * fsi] -
	0.0323956984001593 * f[(i + 4) * fsi] + 0.00361112833933119 * f[(i + 5) * fsi];
      f51 =
	-0.00361112833933119 * f[(i - 3) * fsi] + 0.0350981029682072 * f[(i - 2) * fsi] -
	0.170148291923996 * f[(i - 1) * fsi] + 0.675850213702288 * f[(i + 0) * fsi] +
	0.59242759163413 * f[(i + 1) * fsi] - 0.159826646009912 * f[(i + 2) * fsi] +
	0.0337168296541244 * f[(i + 3) * fsi] - 0.00350667168550975 * f[(i + 4) * fsi];
      f52 =
	+0.00350667168550975 * f[(i - 4) * fsi] - 0.0316645018234092 * f[(i - 3) * fsi] +
	0.13328491016248 * f[(i - 2) * fsi] - 0.366521906312542 * f[(i - 1) * fsi] +
	0.92131723168797 * f[(i + 0) * fsi] + 0.396053977245584 * f[(i + 1) * fsi] -
	0.0616398388156392 * f[(i + 2) * fsi] + 0.00566345617004641 * f[(i + 3) * fsi];
      f53 =
	-0.00566345617004641 * f[(i - 5) * fsi] + 0.048814321045881 * f[(i - 4) * fsi] -
	0.190241274584709 * f[(i - 3) * fsi] + 0.450438455685079 * f[(i - 2) * fsi] -
	0.762963838215791 * f[(i - 1) * fsi] + 1.23847077721057 * f[(i + 0) * fsi] +
	0.237477204484284 * f[(i + 1) * fsi] - 0.0163321894552679 * f[(i + 2) * fsi];
      f54 =
	+0.0163321894552679 * f[(i - 6) * fsi] - 0.13632097181219 * f[(i - 5) * fsi] +
	0.506115625793383 * f[(i - 4) * fsi] - 1.10484388407971 * f[(i - 3) * fsi] +
	1.59369171755383 * f[(i - 2) * fsi] - 1.67756644771079 * f[(i - 1) * fsi] +
	1.69577208195807 * f[(i + 0) * fsi] + 0.106819688842141 * f[(i + 1) * fsi];
      f55 =
	-0.106819688842141 * f[(i - 7) * fsi] + 0.870889700192398 * f[(i - 6) * fsi] -
	3.12727225939214 * f[(i - 5) * fsi] + 6.48801820095329 * f[(i - 4) * fsi] -
	8.5822221030296 * f[(i - 3) * fsi] + 7.57559429271374 * f[(i - 2) * fsi] -
	4.66851773529075 * f[(i - 1) * fsi] + 2.5503295926952 * f[(i + 0) * fsi];
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
	+7.15903300005099 * (f24 * omega24p + f25 * omega25p + f26 * omega26p + f27 * omega27p +
			     f28 * omega28p + f29 * omega29p + f30 * omega30p + f31 * omega31p) -
	+6.159033000051 * (f24 * omega24m + f25 * omega25m + f26 * omega26m + f27 * omega27m +
			   f28 * omega28m + f29 * omega29m + f30 * omega30m + f31 * omega31m);
      fr4 =
	+2.00580681389013 * (f32 * omega32p + f33 * omega33p + f34 * omega34p + f35 * omega35p +
			     f36 * omega36p + f37 * omega37p + f38 * omega38p + f39 * omega39p) -
	+1.00580681389014 * (f32 * omega32m + f33 * omega33m + f34 * omega34m + f35 * omega35m +
			     f36 * omega36m + f37 * omega37m + f38 * omega38m + f39 * omega39m);
      fr5 =
	f40 * omega40 + f41 * omega41 + f42 * omega42 + f43 * omega43 + f44 * omega44 +
	f45 * omega45 + f46 * omega46 + f47 * omega47;
      fr6 =
	f48 * omega48 + f49 * omega49 + f50 * omega50 + f51 * omega51 + f52 * omega52 +
	f53 * omega53 + f54 * omega54 + f55 * omega55;
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
py_gauss_radau008007 (PyObject * self, PyObject * args)
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

  gauss_radau008007 (f, n, fsi, sigma, ssi, ssr, fr, frsi, frsl);

  Py_INCREF (Py_None);
  return Py_None;
}
