#include <Python.h>
#include <numpy/ndarrayobject.h>

void
gauss_lobatto007006 (const double *restrict f, int n, int fsi,
		     const double *restrict sigma, int ssi, int ssr,
		     double *restrict fr, int frsi, int frsl)
{
  int i;
  double sigma0, sigma1, sigma2, sigma3, sigma4, sigma5, sigma6, omega10, omega41, omega18m,
    omega24m, omega13, omega25m, omega17p, omega36, omega24p, omega3, omega16p, omega17m, omega28,
    omega9, omega18p, omega40, omega32, omega12, omega14m, omega4, omega33, omega29, omega14p,
    omega23p, omega26m, omega39, omega0, omega22m, omega35, omega23m, omega19p, omega22p, omega20m,
    omega11, omega19m, omega20p, omega5, omega25p, omega30, omega7, omega27p, omega38, omega1,
    omega27m, omega15p, omega34, omega26p, omega16m, omega15m, omega8, omega6, omega21p, omega31,
    omega21m, omega37, omega2, accumulator, f10, f21, f39, f15, f41, f20, f13, f36, f19, f3, f28,
    f9, f24, f14, f32, f12, f27, f16, f38, f29, f8, f23, f0, f35, f33, f4, f40, f11, f17, f30, f7,
    f26, f1, f34, f37, f22, f2, f6, f31, f5, f25, f18, fr0, fr1, fr2, fr3, fr4, fr5;
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
      omega7 = +0.00106984045958373 / (1.0e-6 + sigma0) / (1.0e-6 + sigma0);
      accumulator += omega7;
      omega8 = +0.0335186125109979 / (1.0e-6 + sigma1) / (1.0e-6 + sigma1);
      accumulator += omega8;
      omega9 = +0.212801712161651 / (1.0e-6 + sigma2) / (1.0e-6 + sigma2);
      accumulator += omega9;
      omega10 = +0.415125588948063 / (1.0e-6 + sigma3) / (1.0e-6 + sigma3);
      accumulator += omega10;
      omega11 = +0.27622127872092 / (1.0e-6 + sigma4) / (1.0e-6 + sigma4);
      accumulator += omega11;
      omega12 = +0.05847929985698 / (1.0e-6 + sigma5) / (1.0e-6 + sigma5);
      accumulator += omega12;
      omega13 = +0.00278366734180508 / (1.0e-6 + sigma6) / (1.0e-6 + sigma6);
      accumulator += omega13;
      omega7 /= accumulator;
      omega8 /= accumulator;
      omega9 /= accumulator;
      omega10 /= accumulator;
      omega11 /= accumulator;
      omega12 /= accumulator;
      omega13 /= accumulator;
      accumulator = 0.0;
      omega14p = +0.00506896978131468 / +2.01520690934394 / (1.0e-6 + sigma0) / (1.0e-6 + sigma0);
      accumulator += omega14p;
      omega15p = +0.271949457658592 / +2.01520690934394 / (1.0e-6 + sigma1) / (1.0e-6 + sigma1);
      accumulator += omega15p;
      omega16p = +0.566640635195931 / +2.01520690934394 / (1.0e-6 + sigma2) / (1.0e-6 + sigma2);
      accumulator += omega16p;
      omega17p = +0.751781421588955 / +2.01520690934394 / (1.0e-6 + sigma3) / (1.0e-6 + sigma3);
      accumulator += omega17p;
      omega18p = +0.361629434901938 / +2.01520690934394 / (1.0e-6 + sigma4) / (1.0e-6 + sigma4);
      accumulator += omega18p;
      omega19p = +0.0562621777491655 / +2.01520690934394 / (1.0e-6 + sigma5) / (1.0e-6 + sigma5);
      accumulator += omega19p;
      omega20p = +0.00187481246804613 / +2.01520690934394 / (1.0e-6 + sigma6) / (1.0e-6 + sigma6);
      accumulator += omega20p;
      omega14p /= accumulator;
      omega15p /= accumulator;
      omega16p /= accumulator;
      omega17p /= accumulator;
      omega18p /= accumulator;
      omega19p /= accumulator;
      omega20p /= accumulator;
      accumulator = 0.0;
      omega14m = +0.0101379395626294 / +1.01520690934394 / (1.0e-6 + sigma0) / (1.0e-6 + sigma0);
      accumulator += omega14m;
      omega15m = +0.135974728829296 / +1.01520690934394 / (1.0e-6 + sigma1) / (1.0e-6 + sigma1);
      accumulator += omega15m;
      omega16m = +0.283320317597966 / +1.01520690934394 / (1.0e-6 + sigma2) / (1.0e-6 + sigma2);
      accumulator += omega16m;
      omega17m = +0.375890710794477 / +1.01520690934394 / (1.0e-6 + sigma3) / (1.0e-6 + sigma3);
      accumulator += omega17m;
      omega18m = +0.180814717450969 / +1.01520690934394 / (1.0e-6 + sigma4) / (1.0e-6 + sigma4);
      accumulator += omega18m;
      omega19m = +0.0281310888745827 / +1.01520690934394 / (1.0e-6 + sigma5) / (1.0e-6 + sigma5);
      accumulator += omega19m;
      omega20m = +0.000937406234023067 / +1.01520690934394 / (1.0e-6 + sigma6) / (1.0e-6 + sigma6);
      accumulator += omega20m;
      omega14m /= accumulator;
      omega15m /= accumulator;
      omega16m /= accumulator;
      omega17m /= accumulator;
      omega18m /= accumulator;
      omega19m /= accumulator;
      omega20m /= accumulator;
      accumulator = 0.0;
      omega21p = +0.00187481246808277 / +2.01520690934392 / (1.0e-6 + sigma0) / (1.0e-6 + sigma0);
      accumulator += omega21p;
      omega22p = +0.0562621777491247 / +2.01520690934392 / (1.0e-6 + sigma1) / (1.0e-6 + sigma1);
      accumulator += omega22p;
      omega23p = +0.361629434901954 / +2.01520690934392 / (1.0e-6 + sigma2) / (1.0e-6 + sigma2);
      accumulator += omega23p;
      omega24p = +0.751781421588945 / +2.01520690934392 / (1.0e-6 + sigma3) / (1.0e-6 + sigma3);
      accumulator += omega24p;
      omega25p = +0.566640635195962 / +2.01520690934392 / (1.0e-6 + sigma4) / (1.0e-6 + sigma4);
      accumulator += omega25p;
      omega26p = +0.27194945765855 / +2.01520690934392 / (1.0e-6 + sigma5) / (1.0e-6 + sigma5);
      accumulator += omega26p;
      omega27p = +0.00506896978130406 / +2.01520690934392 / (1.0e-6 + sigma6) / (1.0e-6 + sigma6);
      accumulator += omega27p;
      omega21p /= accumulator;
      omega22p /= accumulator;
      omega23p /= accumulator;
      omega24p /= accumulator;
      omega25p /= accumulator;
      omega26p /= accumulator;
      omega27p /= accumulator;
      accumulator = 0.0;
      omega21m = +0.000937406234041383 / +1.01520690934392 / (1.0e-6 + sigma0) / (1.0e-6 + sigma0);
      accumulator += omega21m;
      omega22m = +0.0281310888745624 / +1.01520690934392 / (1.0e-6 + sigma1) / (1.0e-6 + sigma1);
      accumulator += omega22m;
      omega23m = +0.180814717450977 / +1.01520690934392 / (1.0e-6 + sigma2) / (1.0e-6 + sigma2);
      accumulator += omega23m;
      omega24m = +0.375890710794472 / +1.01520690934392 / (1.0e-6 + sigma3) / (1.0e-6 + sigma3);
      accumulator += omega24m;
      omega25m = +0.283320317597981 / +1.01520690934392 / (1.0e-6 + sigma4) / (1.0e-6 + sigma4);
      accumulator += omega25m;
      omega26m = +0.135974728829275 / +1.01520690934392 / (1.0e-6 + sigma5) / (1.0e-6 + sigma5);
      accumulator += omega26m;
      omega27m = +0.0101379395626081 / +1.01520690934392 / (1.0e-6 + sigma6) / (1.0e-6 + sigma6);
      accumulator += omega27m;
      omega21m /= accumulator;
      omega22m /= accumulator;
      omega23m /= accumulator;
      omega24m /= accumulator;
      omega25m /= accumulator;
      omega26m /= accumulator;
      omega27m /= accumulator;
      accumulator = 0.0;
      omega28 = +0.00278366734183452 / (1.0e-6 + sigma0) / (1.0e-6 + sigma0);
      accumulator += omega28;
      omega29 = +0.058479299856949 / (1.0e-6 + sigma1) / (1.0e-6 + sigma1);
      accumulator += omega29;
      omega30 = +0.276221278720935 / (1.0e-6 + sigma2) / (1.0e-6 + sigma2);
      accumulator += omega30;
      omega31 = +0.41512558894806 / (1.0e-6 + sigma3) / (1.0e-6 + sigma3);
      accumulator += omega31;
      omega32 = +0.212801712161648 / (1.0e-6 + sigma4) / (1.0e-6 + sigma4);
      accumulator += omega32;
      omega33 = +0.0335186125110011 / (1.0e-6 + sigma5) / (1.0e-6 + sigma5);
      accumulator += omega33;
      omega34 = +0.0010698404595829 / (1.0e-6 + sigma6) / (1.0e-6 + sigma6);
      accumulator += omega34;
      omega28 /= accumulator;
      omega29 /= accumulator;
      omega30 /= accumulator;
      omega31 /= accumulator;
      omega32 /= accumulator;
      omega33 /= accumulator;
      omega34 /= accumulator;
      accumulator = 0.0;
      omega35 = +0.00407925407926976 / (1.0e-6 + sigma0) / (1.0e-6 + sigma0);
      accumulator += omega35;
      omega36 = +0.0734265734265464 / (1.0e-6 + sigma1) / (1.0e-6 + sigma1);
      accumulator += omega36;
      omega37 = +0.305944055944074 / (1.0e-6 + sigma2) / (1.0e-6 + sigma2);
      accumulator += omega37;
      omega38 = +0.407925407925404 / (1.0e-6 + sigma3) / (1.0e-6 + sigma3);
      accumulator += omega38;
      omega39 = +0.183566433566434 / (1.0e-6 + sigma4) / (1.0e-6 + sigma4);
      accumulator += omega39;
      omega40 = +0.0244755244755245 / (1.0e-6 + sigma5) / (1.0e-6 + sigma5);
      accumulator += omega40;
      omega41 = +0.000582750582750583 / (1.0e-6 + sigma6) / (1.0e-6 + sigma6);
      accumulator += omega41;
      omega35 /= accumulator;
      omega36 /= accumulator;
      omega37 /= accumulator;
      omega38 /= accumulator;
      omega39 /= accumulator;
      omega40 /= accumulator;
      omega41 /= accumulator;
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
	+2.03383562728501 * f[(i + 0) * fsi] - 2.62539596520806 * f[(i + 1) * fsi] +
	3.35212596084959 * f[(i + 2) * fsi] - 2.96253998113793 * f[(i + 3) * fsi] +
	1.65668860134516 * f[(i + 4) * fsi] - 0.527767378379921 * f[(i + 5) * fsi] +
	0.0730531352461512 * f[(i + 6) * fsi];
      f8 =
	+0.0730531352461511 * f[(i - 1) * fsi] + 1.52246368056195 * f[(i + 0) * fsi] -
	1.09128012503888 * f[(i + 1) * fsi] + 0.795266227234299 * f[(i + 2) * fsi] -
	0.405680247522636 * f[(i + 3) * fsi] + 0.122572761175982 * f[(i + 4) * fsi] -
	0.0163954316568633 * f[(i + 5) * fsi];
      f9 =
	-0.0163954316568633 * f[(i - 2) * fsi] + 0.187821156844194 * f[(i - 1) * fsi] +
	1.17815961576782 * f[(i + 0) * fsi] - 0.517440017048667 * f[(i + 1) * fsi] +
	0.221426119244083 * f[(i + 2) * fsi] - 0.0613761827285069 * f[(i + 3) * fsi] +
	0.00780473957793913 * f[(i + 4) * fsi];
      f10 =
	+0.00780473957793913 * f[(i - 3) * fsi] - 0.0710286087024372 * f[(i - 2) * fsi] +
	0.351720687980916 * f[(i - 1) * fsi] + 0.904993730539951 * f[(i + 0) * fsi] -
	0.244274131820798 * f[(i + 1) * fsi] + 0.0575265881073615 * f[(i + 2) * fsi] -
	0.00674300568293295 * f[(i + 3) * fsi];
      f11 =
	-0.00674300568293295 * f[(i - 4) * fsi] + 0.0550057793584697 * f[(i - 3) * fsi] -
	0.212631728044029 * f[(i - 2) * fsi] + 0.587725886883569 * f[(i - 1) * fsi] +
	0.668988531637298 * f[(i + 0) * fsi] - 0.102671012479206 * f[(i + 1) * fsi] +
	0.0103255483268309 * f[(i + 2) * fsi];
      f12 =
	+0.0103255483268309 * f[(i - 5) * fsi] - 0.0790218439707491 * f[(i - 4) * fsi] +
	0.271842294221918 * f[(i - 3) * fsi] - 0.57402591948311 * f[(i - 2) * fsi] +
	0.94912007832265 * f[(i - 1) * fsi] + 0.45215201677385 * f[(i + 0) * fsi] -
	0.0303921741913896 * f[(i + 1) * fsi];
      f13 =
	-0.0303921741913896 * f[(i - 6) * fsi] + 0.223070767666558 * f[(i - 5) * fsi] -
	0.71725750198993 * f[(i - 4) * fsi] + 1.33556839092055 * f[(i - 3) * fsi] -
	1.63775201618174 * f[(i - 2) * fsi] + 1.58735573634183 * f[(i - 1) * fsi] +
	0.239406797434123 * f[(i + 0) * fsi];
      f14 =
	+1.17912169400845 * f[(i + 0) * fsi] - 0.177361932025774 * f[(i + 1) * fsi] -
	0.10384298678565 * f[(i + 2) * fsi] + 0.20254100154858 * f[(i + 3) * fsi] -
	0.144881542896469 * f[(i + 4) * fsi] + 0.0522072826083049 * f[(i + 5) * fsi] -
	0.00778351645743997 * f[(i + 6) * fsi];
      f15 =
	-0.00778351645743997 * f[(i - 1) * fsi] + 1.23360630921053 * f[(i + 0) * fsi] -
	0.340815777632014 * f[(i + 1) * fsi] + 0.16858008922475 * f[(i + 2) * fsi] -
	0.069882074461819 * f[(i + 3) * fsi] + 0.0185723027097709 * f[(i + 4) * fsi] -
	0.00227733259377532 * f[(i + 5) * fsi];
      f16 =
	-0.00227733259377532 * f[(i - 2) * fsi] + 0.00815781169898729 * f[(i - 1) * fsi] +
	1.18578232474124 * f[(i + 0) * fsi] - 0.261109136849877 * f[(i + 1) * fsi] +
	0.0888734484426143 * f[(i + 2) * fsi] - 0.0220580899925373 * f[(i + 3) * fsi] +
	0.00263097455334365 * f[(i + 4) * fsi];
      f17 =
	+0.00263097455334365 * f[(i - 3) * fsi] - 0.0206941544671808 * f[(i - 2) * fsi] +
	0.0634082773192039 * f[(i - 1) * fsi] + 1.09369821537422 * f[(i + 0) * fsi] -
	0.16902502748285 * f[(i + 1) * fsi] + 0.0336229828223977 * f[(i + 2) * fsi] -
	0.00364126811913173 * f[(i + 3) * fsi];
      f18 =
	-0.00364126811913173 * f[(i - 4) * fsi] + 0.0281198513872657 * f[(i - 3) * fsi] -
	0.0971607849689471 * f[(i - 2) * fsi] + 0.190852661488814 * f[(i - 1) * fsi] +
	0.966253831204607 * f[(i + 0) * fsi] - 0.0925583969810833 * f[(i + 1) * fsi] +
	0.00813410598847558 * f[(i + 2) * fsi];
      f19 =
	+0.00813410598847558 * f[(i - 5) * fsi] - 0.0605800100384608 * f[(i - 4) * fsi] +
	0.198936077145253 * f[(i - 3) * fsi] - 0.381854494565592 * f[(i - 2) * fsi] +
	0.475546371085459 * f[(i - 1) * fsi] + 0.795437605446619 * f[(i + 0) * fsi] -
	0.0356196550617543 * f[(i + 1) * fsi];
      f20 =
	-0.0356196550617543 * f[(i - 6) * fsi] + 0.257471691420756 * f[(i - 5) * fsi] -
	0.808592766335301 * f[(i - 4) * fsi] + 1.44562400430665 * f[(i - 3) * fsi] -
	1.62854242172699 * f[(i - 2) * fsi] + 1.2235591273823 * f[(i - 1) * fsi] +
	0.546100020014339 * f[(i + 0) * fsi];
      f21 =
	+0.546100020014339 * f[(i + 0) * fsi] + 1.2235591273823 * f[(i + 1) * fsi] -
	1.628542421727 * f[(i + 2) * fsi] + 1.44562400430665 * f[(i + 3) * fsi] -
	0.808592766335302 * f[(i + 4) * fsi] + 0.257471691420756 * f[(i + 5) * fsi] -
	0.0356196550617543 * f[(i + 6) * fsi];
      f22 =
	-0.0356196550617543 * f[(i - 1) * fsi] + 0.795437605446619 * f[(i + 0) * fsi] +
	0.475546371085459 * f[(i + 1) * fsi] - 0.381854494565592 * f[(i + 2) * fsi] +
	0.198936077145253 * f[(i + 3) * fsi] - 0.0605800100384607 * f[(i + 4) * fsi] +
	0.00813410598847558 * f[(i + 5) * fsi];
      f23 =
	+0.00813410598847558 * f[(i - 2) * fsi] - 0.0925583969810833 * f[(i - 1) * fsi] +
	0.966253831204606 * f[(i + 0) * fsi] + 0.190852661488814 * f[(i + 1) * fsi] -
	0.0971607849689471 * f[(i + 2) * fsi] + 0.0281198513872657 * f[(i + 3) * fsi] -
	0.00364126811913173 * f[(i + 4) * fsi];
      f24 =
	-0.00364126811913173 * f[(i - 3) * fsi] + 0.0336229828223977 * f[(i - 2) * fsi] -
	0.16902502748285 * f[(i - 1) * fsi] + 1.09369821537422 * f[(i + 0) * fsi] +
	0.0634082773192038 * f[(i + 1) * fsi] - 0.0206941544671809 * f[(i + 2) * fsi] +
	0.00263097455334365 * f[(i + 3) * fsi];
      f25 =
	+0.00263097455334365 * f[(i - 4) * fsi] - 0.0220580899925372 * f[(i - 3) * fsi] +
	0.0888734484426143 * f[(i - 2) * fsi] - 0.261109136849877 * f[(i - 1) * fsi] +
	1.18578232474124 * f[(i + 0) * fsi] + 0.00815781169898729 * f[(i + 1) * fsi] -
	0.00227733259377532 * f[(i + 2) * fsi];
      f26 =
	-0.00227733259377532 * f[(i - 5) * fsi] + 0.0185723027097709 * f[(i - 4) * fsi] -
	0.069882074461819 * f[(i - 3) * fsi] + 0.16858008922475 * f[(i - 2) * fsi] -
	0.340815777632014 * f[(i - 1) * fsi] + 1.23360630921053 * f[(i + 0) * fsi] -
	0.00778351645743997 * f[(i + 1) * fsi];
      f27 =
	-0.00778351645743997 * f[(i - 6) * fsi] + 0.0522072826083045 * f[(i - 5) * fsi] -
	0.144881542896469 * f[(i - 4) * fsi] + 0.20254100154858 * f[(i - 3) * fsi] -
	0.103842986785649 * f[(i - 2) * fsi] - 0.177361932025774 * f[(i - 1) * fsi] +
	1.17912169400845 * f[(i + 0) * fsi];
      f28 =
	+0.239406797434122 * f[(i + 0) * fsi] + 1.58735573634183 * f[(i + 1) * fsi] -
	1.63775201618174 * f[(i + 2) * fsi] + 1.33556839092055 * f[(i + 3) * fsi] -
	0.71725750198993 * f[(i + 4) * fsi] + 0.223070767666559 * f[(i + 5) * fsi] -
	0.0303921741913895 * f[(i + 6) * fsi];
      f29 =
	-0.0303921741913895 * f[(i - 1) * fsi] + 0.45215201677385 * f[(i + 0) * fsi] +
	0.94912007832265 * f[(i + 1) * fsi] - 0.574025919483109 * f[(i + 2) * fsi] +
	0.271842294221918 * f[(i + 3) * fsi] - 0.0790218439707491 * f[(i + 4) * fsi] +
	0.0103255483268309 * f[(i + 5) * fsi];
      f30 =
	+0.0103255483268309 * f[(i - 2) * fsi] - 0.102671012479206 * f[(i - 1) * fsi] +
	0.668988531637298 * f[(i + 0) * fsi] + 0.587725886883569 * f[(i + 1) * fsi] -
	0.212631728044029 * f[(i + 2) * fsi] + 0.0550057793584698 * f[(i + 3) * fsi] -
	0.00674300568293295 * f[(i + 4) * fsi];
      f31 =
	-0.00674300568293295 * f[(i - 3) * fsi] + 0.0575265881073615 * f[(i - 2) * fsi] -
	0.244274131820798 * f[(i - 1) * fsi] + 0.904993730539951 * f[(i + 0) * fsi] +
	0.351720687980916 * f[(i + 1) * fsi] - 0.0710286087024372 * f[(i + 2) * fsi] +
	0.00780473957793913 * f[(i + 3) * fsi];
      f32 =
	+0.00780473957793913 * f[(i - 4) * fsi] - 0.0613761827285069 * f[(i - 3) * fsi] +
	0.221426119244083 * f[(i - 2) * fsi] - 0.517440017048667 * f[(i - 1) * fsi] +
	1.17815961576782 * f[(i + 0) * fsi] + 0.187821156844194 * f[(i + 1) * fsi] -
	0.0163954316568633 * f[(i + 2) * fsi];
      f33 =
	-0.0163954316568633 * f[(i - 5) * fsi] + 0.122572761175982 * f[(i - 4) * fsi] -
	0.405680247522636 * f[(i - 3) * fsi] + 0.795266227234299 * f[(i - 2) * fsi] -
	1.09128012503888 * f[(i - 1) * fsi] + 1.52246368056195 * f[(i + 0) * fsi] +
	0.0730531352461512 * f[(i + 1) * fsi];
      f34 =
	+0.0730531352461512 * f[(i - 6) * fsi] - 0.527767378379921 * f[(i - 5) * fsi] +
	1.65668860134516 * f[(i - 4) * fsi] - 2.96253998113793 * f[(i - 3) * fsi] +
	3.35212596084959 * f[(i - 2) * fsi] - 2.62539596520806 * f[(i - 1) * fsi] +
	2.03383562728501 * f[(i + 0) * fsi];
      f35 =
	+0.142857142857143 * f[(i + 0) * fsi] + 1.59285714285714 * f[(i + 1) * fsi] -
	1.40714285714286 * f[(i + 2) * fsi] + 1.09285714285714 * f[(i + 3) * fsi] -
	0.573809523809524 * f[(i + 4) * fsi] + 0.176190476190476 * f[(i + 5) * fsi] -
	0.0238095238095238 * f[(i + 6) * fsi];
      f36 =
	-0.0238095238095238 * f[(i - 1) * fsi] + 0.30952380952381 * f[(i + 0) * fsi] +
	1.09285714285714 * f[(i + 1) * fsi] - 0.573809523809524 * f[(i + 2) * fsi] +
	0.25952380952381 * f[(i + 3) * fsi] - 0.0738095238095238 * f[(i + 4) * fsi] +
	0.00952380952380954 * f[(i + 5) * fsi];
      f37 =
	+0.00952380952380954 * f[(i - 2) * fsi] - 0.0904761904761906 * f[(i - 1) * fsi] +
	0.50952380952381 * f[(i + 0) * fsi] + 0.759523809523809 * f[(i + 1) * fsi] -
	0.24047619047619 * f[(i + 2) * fsi] + 0.0595238095238095 * f[(i + 3) * fsi] -
	0.00714285714285715 * f[(i + 4) * fsi];
      f38 =
	-0.00714285714285714 * f[(i - 3) * fsi] + 0.0595238095238095 * f[(i - 2) * fsi] -
	0.240476190476191 * f[(i - 1) * fsi] + 0.75952380952381 * f[(i + 0) * fsi] +
	0.50952380952381 * f[(i + 1) * fsi] - 0.0904761904761905 * f[(i + 2) * fsi] +
	0.00952380952380952 * f[(i + 3) * fsi];
      f39 =
	+0.00952380952380952 * f[(i - 4) * fsi] - 0.0738095238095238 * f[(i - 3) * fsi] +
	0.259523809523809 * f[(i - 2) * fsi] - 0.573809523809524 * f[(i - 1) * fsi] +
	1.09285714285714 * f[(i + 0) * fsi] + 0.309523809523809 * f[(i + 1) * fsi] -
	0.0238095238095238 * f[(i + 2) * fsi];
      f40 =
	-0.0238095238095238 * f[(i - 5) * fsi] + 0.176190476190476 * f[(i - 4) * fsi] -
	0.573809523809524 * f[(i - 3) * fsi] + 1.09285714285714 * f[(i - 2) * fsi] -
	1.40714285714286 * f[(i - 1) * fsi] + 1.59285714285714 * f[(i + 0) * fsi] +
	0.142857142857143 * f[(i + 1) * fsi];
      f41 =
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
	+2.01520690934394 * (f14 * omega14p + f15 * omega15p + f16 * omega16p + f17 * omega17p +
			     f18 * omega18p + f19 * omega19p + f20 * omega20p) -
	+1.01520690934394 * (f14 * omega14m + f15 * omega15m + f16 * omega16m + f17 * omega17m +
			     f18 * omega18m + f19 * omega19m + f20 * omega20m);
      fr3 =
	+2.01520690934392 * (f21 * omega21p + f22 * omega22p + f23 * omega23p + f24 * omega24p +
			     f25 * omega25p + f26 * omega26p + f27 * omega27p) -
	+1.01520690934392 * (f21 * omega21m + f22 * omega22m + f23 * omega23m + f24 * omega24m +
			     f25 * omega25m + f26 * omega26m + f27 * omega27m);
      fr4 =
	f28 * omega28 + f29 * omega29 + f30 * omega30 + f31 * omega31 + f32 * omega32 +
	f33 * omega33 + f34 * omega34;
      fr5 =
	f35 * omega35 + f36 * omega36 + f37 * omega37 + f38 * omega38 + f39 * omega39 +
	f40 * omega40 + f41 * omega41;
      fr[i * frsi + 0 * frsl] = fr0;
      fr[i * frsi + 1 * frsl] = fr1;
      fr[i * frsi + 2 * frsl] = fr2;
      fr[i * frsi + 3 * frsl] = fr3;
      fr[i * frsi + 4 * frsl] = fr4;
      fr[i * frsi + 5 * frsl] = fr5;
    }
}

PyObject *
py_gauss_lobatto007006 (PyObject * self, PyObject * args)
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

  gauss_lobatto007006 (f, n, fsi, sigma, ssi, ssr, fr, frsi, frsl);

  Py_INCREF (Py_None);
  return Py_None;
}
