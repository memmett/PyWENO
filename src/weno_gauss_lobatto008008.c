#include <Python.h>
#include <numpy/ndarrayobject.h>

void
gauss_lobatto008008 (const double *restrict f, int n, int fsi,
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
      omega8 = +0.00021843131107999 / (1.0e-6 + sigma0) / (1.0e-6 + sigma0);
      accumulator += omega8;
      omega9 = +0.0105285395438688 / (1.0e-6 + sigma1) / (1.0e-6 + sigma1);
      accumulator += omega9;
      omega10 = +0.101539744490223 / (1.0e-6 + sigma2) / (1.0e-6 + sigma2);
      accumulator += omega10;
      omega11 = +0.317026075867508 / (1.0e-6 + sigma3) / (1.0e-6 + sigma3);
      accumulator += omega11;
      omega12 = +0.373834625136336 / (1.0e-6 + sigma4) / (1.0e-6 + sigma4);
      accumulator += omega12;
      omega13 = +0.169367864203607 / (1.0e-6 + sigma5) / (1.0e-6 + sigma5);
      accumulator += omega13;
      omega14 = +0.0264878823229253 / (1.0e-6 + sigma6) / (1.0e-6 + sigma6);
      accumulator += omega14;
      omega15 = +0.000996837124450925 / (1.0e-6 + sigma7) / (1.0e-6 + sigma7);
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
      omega16 = +0.000564573777670417 / (1.0e-6 + sigma0) / (1.0e-6 + sigma0);
      accumulator += omega16;
      omega17 = +0.0169720010076365 / (1.0e-6 + sigma1) / (1.0e-6 + sigma1);
      accumulator += omega17;
      omega18 = +0.129767149044965 / (1.0e-6 + sigma2) / (1.0e-6 + sigma2);
      accumulator += omega18;
      omega19 = +0.342973759901546 / (1.0e-6 + sigma3) / (1.0e-6 + sigma3);
      accumulator += omega19;
      omega20 = +0.351184907384642 / (1.0e-6 + sigma4) / (1.0e-6 + sigma4);
      accumulator += omega20;
      omega21 = +0.139096458871288 / (1.0e-6 + sigma5) / (1.0e-6 + sigma5);
      accumulator += omega21;
      omega22 = +0.0188481022953595 / (1.0e-6 + sigma6) / (1.0e-6 + sigma6);
      accumulator += omega22;
      omega23 = +0.00059304771689319 / (1.0e-6 + sigma7) / (1.0e-6 + sigma7);
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
      omega24p = +0.000483236250430046 / +2.63896328947083 / (1.0e-6 + sigma0) / (1.0e-6 + sigma0);
      accumulator += omega24p;
      omega25p = +0.212504526906512 / +2.63896328947083 / (1.0e-6 + sigma1) / (1.0e-6 + sigma1);
      accumulator += omega25p;
      omega26p = +1.13259580308871 / +2.63896328947083 / (1.0e-6 + sigma2) / (1.0e-6 + sigma2);
      accumulator += omega26p;
      omega27p = +0.629043114569843 / +2.63896328947083 / (1.0e-6 + sigma3) / (1.0e-6 + sigma3);
      accumulator += omega27p;
      omega28p = +0.495053485994406 / +2.63896328947083 / (1.0e-6 + sigma4) / (1.0e-6 + sigma4);
      accumulator += omega28p;
      omega29p = +0.152708527750827 / +2.63896328947083 / (1.0e-6 + sigma5) / (1.0e-6 + sigma5);
      accumulator += omega29p;
      omega30p = +0.0161930495069737 / +2.63896328947083 / (1.0e-6 + sigma6) / (1.0e-6 + sigma6);
      accumulator += omega30p;
      omega31p = +0.000381545403126488 / +2.63896328947083 / (1.0e-6 + sigma7) / (1.0e-6 + sigma7);
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
      omega24m = +0.000966472500860091 / +1.63896328947083 / (1.0e-6 + sigma0) / (1.0e-6 + sigma0);
      accumulator += omega24m;
      omega25m = +0.425009053813023 / +1.63896328947083 / (1.0e-6 + sigma1) / (1.0e-6 + sigma1);
      accumulator += omega25m;
      omega26m = +0.566297901544355 / +1.63896328947083 / (1.0e-6 + sigma2) / (1.0e-6 + sigma2);
      accumulator += omega26m;
      omega27m = +0.314521557284922 / +1.63896328947083 / (1.0e-6 + sigma3) / (1.0e-6 + sigma3);
      accumulator += omega27m;
      omega28m = +0.247526742997203 / +1.63896328947083 / (1.0e-6 + sigma4) / (1.0e-6 + sigma4);
      accumulator += omega28m;
      omega29m = +0.0763542638754134 / +1.63896328947083 / (1.0e-6 + sigma5) / (1.0e-6 + sigma5);
      accumulator += omega29m;
      omega30m = +0.00809652475348687 / +1.63896328947083 / (1.0e-6 + sigma6) / (1.0e-6 + sigma6);
      accumulator += omega30m;
      omega31m = +0.000190772701563244 / +1.63896328947083 / (1.0e-6 + sigma7) / (1.0e-6 + sigma7);
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
      omega32p = +0.000381545402903228 / +2.6389632894705 / (1.0e-6 + sigma0) / (1.0e-6 + sigma0);
      accumulator += omega32p;
      omega33p = +0.0161930495074029 / +2.6389632894705 / (1.0e-6 + sigma1) / (1.0e-6 + sigma1);
      accumulator += omega33p;
      omega34p = +0.152708527750477 / +2.6389632894705 / (1.0e-6 + sigma2) / (1.0e-6 + sigma2);
      accumulator += omega34p;
      omega35p = +0.495053485994542 / +2.6389632894705 / (1.0e-6 + sigma3) / (1.0e-6 + sigma3);
      accumulator += omega35p;
      omega36p = +0.629043114569824 / +2.6389632894705 / (1.0e-6 + sigma4) / (1.0e-6 + sigma4);
      accumulator += omega36p;
      omega37p = +1.13259580308851 / +2.6389632894705 / (1.0e-6 + sigma5) / (1.0e-6 + sigma5);
      accumulator += omega37p;
      omega38p = +0.21250452690639 / +2.6389632894705 / (1.0e-6 + sigma6) / (1.0e-6 + sigma6);
      accumulator += omega38p;
      omega39p = +0.00048323625045303 / +2.6389632894705 / (1.0e-6 + sigma7) / (1.0e-6 + sigma7);
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
      omega32m = +0.000190772701451614 / +1.63896328947051 / (1.0e-6 + sigma0) / (1.0e-6 + sigma0);
      accumulator += omega32m;
      omega33m = +0.00809652475370144 / +1.63896328947051 / (1.0e-6 + sigma1) / (1.0e-6 + sigma1);
      accumulator += omega33m;
      omega34m = +0.0763542638752386 / +1.63896328947051 / (1.0e-6 + sigma2) / (1.0e-6 + sigma2);
      accumulator += omega34m;
      omega35m = +0.247526742997271 / +1.63896328947051 / (1.0e-6 + sigma3) / (1.0e-6 + sigma3);
      accumulator += omega35m;
      omega36m = +0.314521557284912 / +1.63896328947051 / (1.0e-6 + sigma4) / (1.0e-6 + sigma4);
      accumulator += omega36m;
      omega37m = +0.566297901544253 / +1.63896328947051 / (1.0e-6 + sigma5) / (1.0e-6 + sigma5);
      accumulator += omega37m;
      omega38m = +0.425009053812781 / +1.63896328947051 / (1.0e-6 + sigma6) / (1.0e-6 + sigma6);
      accumulator += omega38m;
      omega39m = +0.00096647250090606 / +1.63896328947051 / (1.0e-6 + sigma7) / (1.0e-6 + sigma7);
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
      omega40 = +0.000593047716834193 / (1.0e-6 + sigma0) / (1.0e-6 + sigma0);
      accumulator += omega40;
      omega41 = +0.0188481022954695 / (1.0e-6 + sigma1) / (1.0e-6 + sigma1);
      accumulator += omega41;
      omega42 = +0.139096458871195 / (1.0e-6 + sigma2) / (1.0e-6 + sigma2);
      accumulator += omega42;
      omega43 = +0.351184907384677 / (1.0e-6 + sigma3) / (1.0e-6 + sigma3);
      accumulator += omega43;
      omega44 = +0.34297375990154 / (1.0e-6 + sigma4) / (1.0e-6 + sigma4);
      accumulator += omega44;
      omega45 = +0.129767149044968 / (1.0e-6 + sigma5) / (1.0e-6 + sigma5);
      accumulator += omega45;
      omega46 = +0.0169720010076285 / (1.0e-6 + sigma6) / (1.0e-6 + sigma6);
      accumulator += omega46;
      omega47 = +0.000564573777675351 / (1.0e-6 + sigma7) / (1.0e-6 + sigma7);
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
      omega48 = +0.000996837124369463 / (1.0e-6 + sigma0) / (1.0e-6 + sigma0);
      accumulator += omega48;
      omega49 = +0.0264878823230314 / (1.0e-6 + sigma1) / (1.0e-6 + sigma1);
      accumulator += omega49;
      omega50 = +0.169367864203546 / (1.0e-6 + sigma2) / (1.0e-6 + sigma2);
      accumulator += omega50;
      omega51 = +0.37383462513635 / (1.0e-6 + sigma3) / (1.0e-6 + sigma3);
      accumulator += omega51;
      omega52 = +0.317026075867517 / (1.0e-6 + sigma4) / (1.0e-6 + sigma4);
      accumulator += omega52;
      omega53 = +0.1015397444902 / (1.0e-6 + sigma5) / (1.0e-6 + sigma5);
      accumulator += omega53;
      omega54 = +0.0105285395438905 / (1.0e-6 + sigma6) / (1.0e-6 + sigma6);
      accumulator += omega54;
      omega55 = +0.000218431311073099 / (1.0e-6 + sigma7) / (1.0e-6 + sigma7);
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
      omega56 = +0.00124320124317649 / (1.0e-6 + sigma0) / (1.0e-6 + sigma0);
      accumulator += omega56;
      omega57 = +0.0304584304584759 / (1.0e-6 + sigma1) / (1.0e-6 + sigma1);
      accumulator += omega57;
      omega58 = +0.182750582750552 / (1.0e-6 + sigma2) / (1.0e-6 + sigma2);
      accumulator += omega58;
      omega59 = +0.380730380730387 / (1.0e-6 + sigma3) / (1.0e-6 + sigma3);
      accumulator += omega59;
      omega60 = +0.304584304584304 / (1.0e-6 + sigma4) / (1.0e-6 + sigma4);
      accumulator += omega60;
      omega61 = +0.0913752913752916 / (1.0e-6 + sigma5) / (1.0e-6 + sigma5);
      accumulator += omega61;
      omega62 = +0.00870240870240869 / (1.0e-6 + sigma6) / (1.0e-6 + sigma6);
      accumulator += omega62;
      omega63 = +0.000155400155400156 / (1.0e-6 + sigma7) / (1.0e-6 + sigma7);
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
	+2.36211002816619 * f[(i + 0) * fsi] - 3.99105301167193 * f[(i + 1) * fsi] +
	6.32998322010539 * f[(i + 2) * fsi] - 7.10088430970408 * f[(i + 3) * fsi] +
	5.33951881855795 * f[(i + 4) * fsi] - 2.5651180381092 * f[(i + 5) * fsi] +
	0.712718705957018 * f[(i + 6) * fsi] - 0.0872754133013305 * f[(i + 7) * fsi];
      f9 =
	+0.0872754133013306 * f[(i - 1) * fsi] + 1.66390672175555 * f[(i + 0) * fsi] -
	1.54734143923468 * f[(i + 1) * fsi] + 1.44256007523087 * f[(i + 2) * fsi] -
	0.99160537861094 * f[(i + 3) * fsi] + 0.452095673683443 * f[(i + 4) * fsi] -
	0.121406465671947 * f[(i + 5) * fsi] + 0.014515399546374 * f[(i + 6) * fsi];
      f10 =
	-0.014515399546374 * f[(i - 2) * fsi] + 0.203398609672323 * f[(i - 1) * fsi] +
	1.25747553445707 * f[(i + 0) * fsi] - 0.734479064637734 * f[(i + 1) * fsi] +
	0.426482106984692 * f[(i + 2) * fsi] - 0.178743004013994 * f[(i + 3) * fsi] +
	0.04566448638497 * f[(i + 4) * fsi] - 0.00528326930095517 * f[(i + 5) * fsi];
      f11 =
	+0.00528326930095517 * f[(i - 3) * fsi] - 0.0567815539540154 * f[(i - 2) * fsi] +
	0.351330150099067 * f[(i - 1) * fsi] + 0.961612453603583 * f[(i + 0) * fsi] -
	0.364650213570873 * f[(i + 1) * fsi] + 0.130619026131202 * f[(i + 2) * fsi] -
	0.0308114635872493 * f[(i + 3) * fsi] + 0.00339833197732867 * f[(i + 4) * fsi];
      f12 =
	-0.00339833197732867 * f[(i - 4) * fsi] + 0.0324699251195845 * f[(i - 3) * fsi] -
	0.151934849319218 * f[(i - 2) * fsi] + 0.541636740829473 * f[(i - 1) * fsi] +
	0.723729215190577 * f[(i + 0) * fsi] - 0.174343622840467 * f[(i + 1) * fsi] +
	0.0354657307659996 * f[(i + 2) * fsi] - 0.00362480776861993 * f[(i + 3) * fsi];
      f13 =
	+0.00362480776861993 * f[(i - 5) * fsi] - 0.0323967941262881 * f[(i - 4) * fsi] +
	0.133964542640943 * f[(i - 3) * fsi] - 0.354924084361934 * f[(i - 2) * fsi] +
	0.795373284632868 * f[(i - 1) * fsi] + 0.520739980147861 * f[(i + 0) * fsi] -
	0.072849005319109 * f[(i + 1) * fsi] + 0.00646726861704014 * f[(i + 2) * fsi];
      f14 =
	-0.00646726861704014 * f[(i - 6) * fsi] + 0.0553629567049411 * f[(i - 5) * fsi] -
	0.213480315403412 * f[(i - 4) * fsi] + 0.496131585195191 * f[(i - 3) * fsi] -
	0.807632887554744 * f[(i - 2) * fsi] + 1.15754032718712 * f[(i - 1) * fsi] +
	0.339656458870737 * f[(i + 0) * fsi] - 0.0211108563827879 * f[(i + 1) * fsi];
      f15 =
	+0.0211108563827879 * f[(i - 7) * fsi] - 0.175354119679343 * f[(i - 6) * fsi] +
	0.646466935423001 * f[(i - 5) * fsi] - 1.39568827283953 * f[(i - 4) * fsi] +
	1.97389153199034 * f[(i - 3) * fsi] - 1.98984084499086 * f[(i - 2) * fsi] +
	1.74864430590518 * f[(i - 1) * fsi] + 0.170769607808434 * f[(i + 0) * fsi];
      f16 =
	+1.71232259611934 * f[(i + 0) * fsi] - 1.77089484635864 * f[(i + 1) * fsi] +
	2.39803548892387 * f[(i + 2) * fsi] - 2.50643514854014 * f[(i + 3) * fsi] +
	1.81255561921387 * f[(i + 4) * fsi] - 0.849640117686494 * f[(i + 5) * fsi] +
	0.232137523305625 * f[(i + 6) * fsi] - 0.0280811149774257 * f[(i + 7) * fsi];
      f17 =
	+0.0280811149774257 * f[(i - 1) * fsi] + 1.48767367629994 * f[(i + 0) * fsi] -
	0.984623626990718 * f[(i + 1) * fsi] + 0.82549305018803 * f[(i + 2) * fsi] -
	0.540757100120343 * f[(i + 3) * fsi] + 0.240013180478024 * f[(i + 4) * fsi] -
	0.0633688983185748 * f[(i + 5) * fsi] + 0.00748860348621968 * f[(i + 6) * fsi];
      f18 =
	-0.00748860348621968 * f[(i - 2) * fsi] + 0.0879899428671831 * f[(i - 1) * fsi] +
	1.27799277868578 * f[(i + 0) * fsi] - 0.565261831762416 * f[(i + 1) * fsi] +
	0.301290806152652 * f[(i + 2) * fsi] - 0.121395304892041 * f[(i + 3) * fsi] +
	0.0303322828638734 * f[(i + 4) * fsi] - 0.00346007042881733 * f[(i + 5) * fsi];
      f19 =
	+0.00346007042881733 * f[(i - 3) * fsi] - 0.0351691669167583 * f[(i - 2) * fsi] +
	0.184871914874068 * f[(i - 1) * fsi] + 1.08422883467201 * f[(i + 0) * fsi] -
	0.323056901745203 * f[(i + 1) * fsi] + 0.107526862138882 * f[(i + 2) * fsi] -
	0.0245133328851557 * f[(i + 3) * fsi] + 0.00265171943333476 * f[(i + 4) * fsi];
      f20 =
	-0.00265171943333476 * f[(i - 4) * fsi] + 0.0246738258954954 * f[(i - 3) * fsi] -
	0.109417311050132 * f[(i - 2) * fsi] + 0.333368203140815 * f[(i - 1) * fsi] +
	0.898608474338581 * f[(i + 0) * fsi] - 0.174560613478456 * f[(i + 1) * fsi] +
	0.0332787180055085 * f[(i + 2) * fsi] - 0.00329957741847763 * f[(i + 3) * fsi];
      f21 =
	+0.00329957741847763 * f[(i - 5) * fsi] - 0.0290483387811558 * f[(i - 4) * fsi] +
	0.117061993612869 * f[(i - 3) * fsi] - 0.294193646484879 * f[(i - 2) * fsi] +
	0.564338622434249 * f[(i - 1) * fsi] + 0.713832138903834 * f[(i + 0) * fsi] -
	0.0821724457610827 * f[(i + 1) * fsi] + 0.00688209865768744 * f[(i + 2) * fsi];
      f22 =
	-0.00688209865768744 * f[(i - 6) * fsi] + 0.0583563666799772 * f[(i - 5) * fsi] -
	0.221747101196404 * f[(i - 4) * fsi] + 0.502459518443366 * f[(i - 3) * fsi] -
	0.775940552523 * f[(i - 2) * fsi] + 0.949736147264746 * f[(i - 1) * fsi] +
	0.521133376488586 * f[(i + 0) * fsi] - 0.0271156564995831 * f[(i + 1) * fsi];
      f23 =
	+0.0271156564995831 * f[(i - 7) * fsi] - 0.223807350654352 * f[(i - 6) * fsi] +
	0.817594748668304 * f[(i - 5) * fsi] - 1.74022386517306 * f[(i - 4) * fsi] +
	2.40055547341418 * f[(i - 3) * fsi] - 2.29441731649965 * f[(i - 2) * fsi] +
	1.70897452925307 * f[(i - 1) * fsi] + 0.304208124491921 * f[(i + 0) * fsi];
      f24 =
	+1.05921749875536 * f[(i + 0) * fsi] + 0.191631103051517 * f[(i + 1) * fsi] -
	0.746379041759901 * f[(i + 2) * fsi] + 1.00496459168962 * f[(i + 3) * fsi] -
	0.816365873001057 * f[(i + 4) * fsi] + 0.409098028672438 * f[(i + 5) * fsi] -
	0.116721096946036 * f[(i + 6) * fsi] + 0.0145547895380636 * f[(i + 7) * fsi];
      f25 =
	-0.0145547895380636 * f[(i - 1) * fsi] + 1.17565581505986 * f[(i + 0) * fsi] -
	0.215903004014265 * f[(i + 1) * fsi] + 0.0686891723716657 * f[(i + 2) * fsi] -
	0.0138706759748355 * f[(i + 3) * fsi] - 0.00129765886949419 * f[(i + 4) * fsi] +
	0.00156392160665553 * f[(i + 5) * fsi] - 0.000282780641527243 * f[(i + 6) * fsi];
      f26 =
	+0.000282780641527245 * f[(i - 2) * fsi] - 0.0168170346702816 * f[(i - 1) * fsi] +
	1.18357367302263 * f[(i + 0) * fsi] - 0.23173871993979 * f[(i + 1) * fsi] +
	0.0884838172785721 * f[(i + 2) * fsi] - 0.0297063919003609 * f[(i + 3) * fsi] +
	0.00662019909326848 * f[(i + 4) * fsi] - 0.000698323525562374 * f[(i + 5) * fsi];
      f27 =
	+0.000698323525562374 * f[(i - 3) * fsi] - 0.00530380756297176 * f[(i - 2) * fsi] +
	0.00273602404546488 * f[(i - 1) * fsi] + 1.14446755559113 * f[(i + 0) * fsi] -
	0.182856073150424 * f[(i + 1) * fsi] + 0.0493776998470792 * f[(i + 2) * fsi] -
	0.0101533331846144 * f[(i + 3) * fsi] + 0.00103361088876948 * f[(i + 4) * fsi];
      f28 =
	-0.00103361088876948 * f[(i - 4) * fsi] + 0.00896721063571822 * f[(i - 3) * fsi] -
	0.0342449124485172 * f[(i - 2) * fsi] + 0.0606182338165557 * f[(i - 1) * fsi] +
	1.07211479337727 * f[(i + 0) * fsi] - 0.124973863379333 * f[(i + 1) * fsi] +
	0.0204365949615337 * f[(i + 2) * fsi] - 0.00188444607445857 * f[(i + 3) * fsi];
      f29 =
	+0.00188444607445857 * f[(i - 5) * fsi] - 0.016109179484438 * f[(i - 4) * fsi] +
	0.0617317007205581 * f[(i - 3) * fsi] - 0.139773892618197 * f[(i - 2) * fsi] +
	0.192529459028656 * f[(i - 1) * fsi] + 0.966585813207591 * f[(i + 0) * fsi] -
	0.0722093732944931 * f[(i + 1) * fsi] + 0.00536102636586516 * f[(i + 2) * fsi];
      f30 =
	-0.00536102636586516 * f[(i - 6) * fsi] + 0.0447726570013799 * f[(i - 5) * fsi] -
	0.166217917728663 * f[(i - 4) * fsi] + 0.361949177209007 * f[(i - 3) * fsi] -
	0.515045738228758 * f[(i - 2) * fsi] + 0.492746935517105 * f[(i - 1) * fsi] +
	0.816477074963366 * f[(i + 0) * fsi] - 0.0293211623675718 * f[(i + 1) * fsi];
      f31 =
	+0.0293211623675718 * f[(i - 7) * fsi] - 0.239930325306439 * f[(i - 6) * fsi] +
	0.86576520329339 * f[(i - 5) * fsi] - 1.80820301031268 * f[(i - 4) * fsi] +
	2.41443054293903 * f[(i - 3) * fsi] - 2.15703083081278 * f[(i - 2) * fsi] +
	1.31373948180911 * f[(i - 1) * fsi] + 0.581907776022792 * f[(i + 0) * fsi];
      f32 =
	+0.581907776022792 * f[(i + 0) * fsi] + 1.31373948180912 * f[(i + 1) * fsi] -
	2.15703083081277 * f[(i + 2) * fsi] + 2.41443054293903 * f[(i + 3) * fsi] -
	1.80820301031267 * f[(i + 4) * fsi] + 0.865765203293391 * f[(i + 5) * fsi] -
	0.239930325306439 * f[(i + 6) * fsi] + 0.0293211623675718 * f[(i + 7) * fsi];
      f33 =
	-0.0293211623675719 * f[(i - 1) * fsi] + 0.816477074963366 * f[(i + 0) * fsi] +
	0.492746935517105 * f[(i + 1) * fsi] - 0.515045738228758 * f[(i + 2) * fsi] +
	0.361949177209007 * f[(i + 3) * fsi] - 0.166217917728662 * f[(i + 4) * fsi] +
	0.0447726570013799 * f[(i + 5) * fsi] - 0.00536102636586517 * f[(i + 6) * fsi];
      f34 =
	+0.00536102636586517 * f[(i - 2) * fsi] - 0.0722093732944931 * f[(i - 1) * fsi] +
	0.966585813207591 * f[(i + 0) * fsi] + 0.192529459028656 * f[(i + 1) * fsi] -
	0.139773892618197 * f[(i + 2) * fsi] + 0.0617317007205582 * f[(i + 3) * fsi] -
	0.016109179484438 * f[(i + 4) * fsi] + 0.00188444607445857 * f[(i + 5) * fsi];
      f35 =
	-0.00188444607445857 * f[(i - 3) * fsi] + 0.0204365949615337 * f[(i - 2) * fsi] -
	0.124973863379333 * f[(i - 1) * fsi] + 1.07211479337727 * f[(i + 0) * fsi] +
	0.0606182338165559 * f[(i + 1) * fsi] - 0.0342449124485172 * f[(i + 2) * fsi] +
	0.00896721063571823 * f[(i + 3) * fsi] - 0.00103361088876948 * f[(i + 4) * fsi];
      f36 =
	+0.00103361088876948 * f[(i - 4) * fsi] - 0.0101533331846144 * f[(i - 3) * fsi] +
	0.0493776998470792 * f[(i - 2) * fsi] - 0.182856073150424 * f[(i - 1) * fsi] +
	1.14446755559113 * f[(i + 0) * fsi] + 0.0027360240454649 * f[(i + 1) * fsi] -
	0.00530380756297175 * f[(i + 2) * fsi] + 0.000698323525562375 * f[(i + 3) * fsi];
      f37 =
	-0.000698323525562375 * f[(i - 5) * fsi] + 0.00662019909326848 * f[(i - 4) * fsi] -
	0.0297063919003609 * f[(i - 3) * fsi] + 0.0884838172785723 * f[(i - 2) * fsi] -
	0.23173871993979 * f[(i - 1) * fsi] + 1.18357367302263 * f[(i + 0) * fsi] -
	0.0168170346702816 * f[(i + 1) * fsi] + 0.000282780641527241 * f[(i + 2) * fsi];
      f38 =
	-0.000282780641527242 * f[(i - 6) * fsi] + 0.00156392160665556 * f[(i - 5) * fsi] -
	0.00129765886949429 * f[(i - 4) * fsi] - 0.0138706759748354 * f[(i - 3) * fsi] +
	0.0686891723716653 * f[(i - 2) * fsi] - 0.215903004014265 * f[(i - 1) * fsi] +
	1.17565581505986 * f[(i + 0) * fsi] - 0.0145547895380637 * f[(i + 1) * fsi];
      f39 =
	+0.0145547895380637 * f[(i - 7) * fsi] - 0.116721096946036 * f[(i - 6) * fsi] +
	0.409098028672438 * f[(i - 5) * fsi] - 0.816365873001059 * f[(i - 4) * fsi] +
	1.00496459168962 * f[(i - 3) * fsi] - 0.746379041759898 * f[(i - 2) * fsi] +
	0.191631103051517 * f[(i - 1) * fsi] + 1.05921749875535 * f[(i + 0) * fsi];
      f40 =
	+0.304208124491921 * f[(i + 0) * fsi] + 1.70897452925307 * f[(i + 1) * fsi] -
	2.29441731649966 * f[(i + 2) * fsi] + 2.40055547341419 * f[(i + 3) * fsi] -
	1.74022386517306 * f[(i + 4) * fsi] + 0.817594748668305 * f[(i + 5) * fsi] -
	0.223807350654353 * f[(i + 6) * fsi] + 0.0271156564995832 * f[(i + 7) * fsi];
      f41 =
	-0.0271156564995833 * f[(i - 1) * fsi] + 0.521133376488586 * f[(i + 0) * fsi] +
	0.949736147264746 * f[(i + 1) * fsi] - 0.775940552522999 * f[(i + 2) * fsi] +
	0.502459518443366 * f[(i + 3) * fsi] - 0.221747101196404 * f[(i + 4) * fsi] +
	0.0583563666799772 * f[(i + 5) * fsi] - 0.00688209865768745 * f[(i + 6) * fsi];
      f42 =
	+0.00688209865768745 * f[(i - 2) * fsi] - 0.0821724457610827 * f[(i - 1) * fsi] +
	0.713832138903834 * f[(i + 0) * fsi] + 0.564338622434248 * f[(i + 1) * fsi] -
	0.294193646484879 * f[(i + 2) * fsi] + 0.117061993612869 * f[(i + 3) * fsi] -
	0.0290483387811558 * f[(i + 4) * fsi] + 0.00329957741847763 * f[(i + 5) * fsi];
      f43 =
	-0.00329957741847763 * f[(i - 3) * fsi] + 0.0332787180055085 * f[(i - 2) * fsi] -
	0.174560613478456 * f[(i - 1) * fsi] + 0.898608474338582 * f[(i + 0) * fsi] +
	0.333368203140815 * f[(i + 1) * fsi] - 0.109417311050132 * f[(i + 2) * fsi] +
	0.0246738258954954 * f[(i + 3) * fsi] - 0.00265171943333476 * f[(i + 4) * fsi];
      f44 =
	+0.00265171943333476 * f[(i - 4) * fsi] - 0.0245133328851557 * f[(i - 3) * fsi] +
	0.107526862138882 * f[(i - 2) * fsi] - 0.323056901745203 * f[(i - 1) * fsi] +
	1.08422883467201 * f[(i + 0) * fsi] + 0.184871914874068 * f[(i + 1) * fsi] -
	0.0351691669167583 * f[(i + 2) * fsi] + 0.00346007042881733 * f[(i + 3) * fsi];
      f45 =
	-0.00346007042881733 * f[(i - 5) * fsi] + 0.0303322828638734 * f[(i - 4) * fsi] -
	0.121395304892041 * f[(i - 3) * fsi] + 0.301290806152652 * f[(i - 2) * fsi] -
	0.565261831762416 * f[(i - 1) * fsi] + 1.27799277868578 * f[(i + 0) * fsi] +
	0.0879899428671831 * f[(i + 1) * fsi] - 0.00748860348621968 * f[(i + 2) * fsi];
      f46 =
	+0.00748860348621968 * f[(i - 6) * fsi] - 0.0633688983185747 * f[(i - 5) * fsi] +
	0.240013180478024 * f[(i - 4) * fsi] - 0.540757100120343 * f[(i - 3) * fsi] +
	0.825493050188029 * f[(i - 2) * fsi] - 0.984623626990718 * f[(i - 1) * fsi] +
	1.48767367629994 * f[(i + 0) * fsi] + 0.0280811149774257 * f[(i + 1) * fsi];
      f47 =
	-0.0280811149774257 * f[(i - 7) * fsi] + 0.232137523305625 * f[(i - 6) * fsi] -
	0.849640117686495 * f[(i - 5) * fsi] + 1.81255561921386 * f[(i - 4) * fsi] -
	2.50643514854014 * f[(i - 3) * fsi] + 2.39803548892387 * f[(i - 2) * fsi] -
	1.77089484635864 * f[(i - 1) * fsi] + 1.71232259611934 * f[(i + 0) * fsi];
      f48 =
	+0.170769607808434 * f[(i + 0) * fsi] + 1.74864430590518 * f[(i + 1) * fsi] -
	1.98984084499086 * f[(i + 2) * fsi] + 1.97389153199035 * f[(i + 3) * fsi] -
	1.39568827283952 * f[(i + 4) * fsi] + 0.646466935423001 * f[(i + 5) * fsi] -
	0.175354119679344 * f[(i + 6) * fsi] + 0.0211108563827879 * f[(i + 7) * fsi];
      f49 =
	-0.0211108563827879 * f[(i - 1) * fsi] + 0.339656458870736 * f[(i + 0) * fsi] +
	1.15754032718711 * f[(i + 1) * fsi] - 0.807632887554744 * f[(i + 2) * fsi] +
	0.496131585195191 * f[(i + 3) * fsi] - 0.213480315403412 * f[(i + 4) * fsi] +
	0.0553629567049411 * f[(i + 5) * fsi] - 0.00646726861704014 * f[(i + 6) * fsi];
      f50 =
	+0.00646726861704014 * f[(i - 2) * fsi] - 0.0728490053191088 * f[(i - 1) * fsi] +
	0.520739980147861 * f[(i + 0) * fsi] + 0.795373284632868 * f[(i + 1) * fsi] -
	0.354924084361934 * f[(i + 2) * fsi] + 0.133964542640943 * f[(i + 3) * fsi] -
	0.0323967941262882 * f[(i + 4) * fsi] + 0.00362480776861994 * f[(i + 5) * fsi];
      f51 =
	-0.00362480776861993 * f[(i - 3) * fsi] + 0.0354657307659996 * f[(i - 2) * fsi] -
	0.174343622840467 * f[(i - 1) * fsi] + 0.723729215190577 * f[(i + 0) * fsi] +
	0.541636740829473 * f[(i + 1) * fsi] - 0.151934849319218 * f[(i + 2) * fsi] +
	0.0324699251195845 * f[(i + 3) * fsi] - 0.00339833197732867 * f[(i + 4) * fsi];
      f52 =
	+0.00339833197732867 * f[(i - 4) * fsi] - 0.0308114635872493 * f[(i - 3) * fsi] +
	0.130619026131202 * f[(i - 2) * fsi] - 0.364650213570873 * f[(i - 1) * fsi] +
	0.961612453603584 * f[(i + 0) * fsi] + 0.351330150099067 * f[(i + 1) * fsi] -
	0.0567815539540154 * f[(i + 2) * fsi] + 0.00528326930095517 * f[(i + 3) * fsi];
      f53 =
	-0.00528326930095517 * f[(i - 5) * fsi] + 0.04566448638497 * f[(i - 4) * fsi] -
	0.178743004013994 * f[(i - 3) * fsi] + 0.426482106984692 * f[(i - 2) * fsi] -
	0.734479064637734 * f[(i - 1) * fsi] + 1.25747553445707 * f[(i + 0) * fsi] +
	0.203398609672323 * f[(i + 1) * fsi] - 0.014515399546374 * f[(i + 2) * fsi];
      f54 =
	+0.014515399546374 * f[(i - 6) * fsi] - 0.121406465671947 * f[(i - 5) * fsi] +
	0.452095673683443 * f[(i - 4) * fsi] - 0.991605378610939 * f[(i - 3) * fsi] +
	1.44256007523087 * f[(i - 2) * fsi] - 1.54734143923468 * f[(i - 1) * fsi] +
	1.66390672175555 * f[(i + 0) * fsi] + 0.0872754133013306 * f[(i + 1) * fsi];
      f55 =
	-0.0872754133013306 * f[(i - 7) * fsi] + 0.712718705957018 * f[(i - 6) * fsi] -
	2.5651180381092 * f[(i - 5) * fsi] + 5.33951881855795 * f[(i - 4) * fsi] -
	7.10088430970408 * f[(i - 3) * fsi] + 6.32998322010538 * f[(i - 2) * fsi] -
	3.99105301167194 * f[(i - 1) * fsi] + 2.36211002816619 * f[(i + 0) * fsi];
      f56 =
	+0.125 * f[(i + 0) * fsi] + 1.71785714285714 * f[(i + 1) * fsi] -
	1.78214285714285 * f[(i + 2) * fsi] + 1.71785714285716 * f[(i + 3) * fsi] -
	1.19880952380952 * f[(i + 4) * fsi] + 0.551190476190474 * f[(i + 5) * fsi] -
	0.148809523809524 * f[(i + 6) * fsi] + 0.0178571428571429 * f[(i + 7) * fsi];
      f57 =
	-0.0178571428571428 * f[(i - 1) * fsi] + 0.267857142857143 * f[(i + 0) * fsi] +
	1.21785714285714 * f[(i + 1) * fsi] - 0.782142857142857 * f[(i + 2) * fsi] +
	0.467857142857143 * f[(i + 3) * fsi] - 0.198809523809523 * f[(i + 4) * fsi] +
	0.0511904761904762 * f[(i + 5) * fsi] - 0.00595238095238096 * f[(i + 6) * fsi];
      f58 =
	+0.00595238095238096 * f[(i - 2) * fsi] - 0.0654761904761904 * f[(i - 1) * fsi] +
	0.43452380952381 * f[(i + 0) * fsi] + 0.884523809523809 * f[(i + 1) * fsi] -
	0.365476190476191 * f[(i + 2) * fsi] + 0.134523809523809 * f[(i + 3) * fsi] -
	0.0321428571428572 * f[(i + 4) * fsi] + 0.00357142857142857 * f[(i + 5) * fsi];
      f59 =
	-0.00357142857142857 * f[(i - 3) * fsi] + 0.0345238095238095 * f[(i - 2) * fsi] -
	0.16547619047619 * f[(i - 1) * fsi] + 0.63452380952381 * f[(i + 0) * fsi] +
	0.63452380952381 * f[(i + 1) * fsi] - 0.16547619047619 * f[(i + 2) * fsi] +
	0.0345238095238096 * f[(i + 3) * fsi] - 0.00357142857142857 * f[(i + 4) * fsi];
      f60 =
	+0.00357142857142857 * f[(i - 4) * fsi] - 0.0321428571428571 * f[(i - 3) * fsi] +
	0.13452380952381 * f[(i - 2) * fsi] - 0.365476190476191 * f[(i - 1) * fsi] +
	0.884523809523809 * f[(i + 0) * fsi] + 0.43452380952381 * f[(i + 1) * fsi] -
	0.0654761904761905 * f[(i + 2) * fsi] + 0.00595238095238095 * f[(i + 3) * fsi];
      f61 =
	-0.00595238095238095 * f[(i - 5) * fsi] + 0.0511904761904762 * f[(i - 4) * fsi] -
	0.198809523809524 * f[(i - 3) * fsi] + 0.467857142857143 * f[(i - 2) * fsi] -
	0.782142857142857 * f[(i - 1) * fsi] + 1.21785714285714 * f[(i + 0) * fsi] +
	0.267857142857143 * f[(i + 1) * fsi] - 0.0178571428571429 * f[(i + 2) * fsi];
      f62 =
	+0.0178571428571429 * f[(i - 6) * fsi] - 0.148809523809524 * f[(i - 5) * fsi] +
	0.551190476190476 * f[(i - 4) * fsi] - 1.19880952380952 * f[(i - 3) * fsi] +
	1.71785714285714 * f[(i - 2) * fsi] - 1.78214285714286 * f[(i - 1) * fsi] +
	1.71785714285714 * f[(i + 0) * fsi] + 0.125 * f[(i + 1) * fsi];
      f63 =
	-0.125 * f[(i - 7) * fsi] + 1.01785714285714 * f[(i - 6) * fsi] -
	3.64880952380952 * f[(i - 5) * fsi] + 7.55119047619048 * f[(i - 4) * fsi] -
	9.94880952380952 * f[(i - 3) * fsi] + 8.71785714285714 * f[(i - 2) * fsi] -
	5.28214285714286 * f[(i - 1) * fsi] + 2.71785714285714 * f[(i + 0) * fsi];
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
	+2.63896328947083 * (f24 * omega24p + f25 * omega25p + f26 * omega26p + f27 * omega27p +
			     f28 * omega28p + f29 * omega29p + f30 * omega30p + f31 * omega31p) -
	+1.63896328947083 * (f24 * omega24m + f25 * omega25m + f26 * omega26m + f27 * omega27m +
			     f28 * omega28m + f29 * omega29m + f30 * omega30m + f31 * omega31m);
      fr4 =
	+2.6389632894705 * (f32 * omega32p + f33 * omega33p + f34 * omega34p + f35 * omega35p +
			    f36 * omega36p + f37 * omega37p + f38 * omega38p + f39 * omega39p) -
	+1.63896328947051 * (f32 * omega32m + f33 * omega33m + f34 * omega34m + f35 * omega35m +
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
py_gauss_lobatto008008 (PyObject * self, PyObject * args)
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

  gauss_lobatto008008 (f, n, fsi, sigma, ssi, ssr, fr, frsi, frsl);

  Py_INCREF (Py_None);
  return Py_None;
}
