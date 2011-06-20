#include <Python.h>
#include <numpy/ndarrayobject.h>

void
gauss_lobatto008006 (const double *restrict f, int n, int fsi,
		     const double *restrict sigma, int ssi, int ssr,
		     double *restrict fr, int frsi, int frsl)
{
  int i;
  double sigma0, sigma1, sigma2, sigma3, sigma4, sigma5, sigma6, sigma7, omega23m, omega39, omega11,
    omega46, omega7, omega27m, omega14, omega28m, omega19p, omega41, omega27p, omega3, omega18p,
    omega19m, omega32, omega10, omega20p, omega45, omega36, omega31m, omega13, omega31p, omega16m,
    omega4, omega37, omega47, omega33, omega16p, omega26p, omega29m, omega44, omega0, omega25m,
    omega40, omega26m, omega21p, omega25p, omega22m, omega12, omega21m, omega22p, omega5, omega28p,
    omega20m, omega34, omega8, omega30p, omega43, omega1, omega30m, omega17p, omega38, omega29p,
    omega18m, omega17m, omega9, omega6, omega24p, omega35, omega15, omega24m, omega23p, omega42,
    omega2, accumulator, f39, f11, f24, f44, f7, f46, f22, f14, f41, f31, f21, f3, f32, f10, f27,
    f16, f36, f13, f30, f18, f47, f43, f33, f9, f23, f26, f0, f40, f37, f4, f45, f12, f19, f17, f34,
    f8, f29, f1, f38, f42, f25, f2, f6, f35, f15, f5, f28, f20, fr0, fr1, fr2, fr3, fr4, fr5;
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
      omega8 = +0.000297267164242143 / (1.0e-6 + sigma0) / (1.0e-6 + sigma0);
      accumulator += omega8;
      omega9 = +0.0124354305727715 / (1.0e-6 + sigma1) / (1.0e-6 + sigma1);
      accumulator += omega9;
      omega10 = +0.111006962111585 / (1.0e-6 + sigma2) / (1.0e-6 + sigma2);
      accumulator += omega10;
      omega11 = +0.327082493799919 / (1.0e-6 + sigma3) / (1.0e-6 + sigma3);
      accumulator += omega11;
      omega12 = +0.366708825680949 / (1.0e-6 + sigma4) / (1.0e-6 + sigma4);
      accumulator += omega12;
      omega13 = +0.158185137654457 / (1.0e-6 + sigma5) / (1.0e-6 + sigma5);
      accumulator += omega13;
      omega14 = +0.023458284349814 / (1.0e-6 + sigma6) / (1.0e-6 + sigma6);
      accumulator += omega14;
      omega15 = +0.000825598666262198 / (1.0e-6 + sigma7) / (1.0e-6 + sigma7);
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
      omega16p = +0.00103138817845927 / +2.00309416453538 / (1.0e-6 + sigma0) / (1.0e-6 + sigma0);
      accumulator += omega16p;
      omega17p = +0.150457815142815 / +2.00309416453538 / (1.0e-6 + sigma1) / (1.0e-6 + sigma1);
      accumulator += omega17p;
      omega18p = +0.352556047451987 / +2.00309416453538 / (1.0e-6 + sigma2) / (1.0e-6 + sigma2);
      accumulator += omega18p;
      omega19p = +0.710442472961014 / +2.00309416453538 / (1.0e-6 + sigma3) / (1.0e-6 + sigma3);
      accumulator += omega19p;
      omega20p = +0.57839800650861 / +2.00309416453538 / (1.0e-6 + sigma4) / (1.0e-6 + sigma4);
      accumulator += omega20p;
      omega21p = +0.188562011302018 / +2.00309416453538 / (1.0e-6 + sigma5) / (1.0e-6 + sigma5);
      accumulator += omega21p;
      omega22p = +0.0211163233732858 / +2.00309416453538 / (1.0e-6 + sigma6) / (1.0e-6 + sigma6);
      accumulator += omega22p;
      omega23p = +0.0005300996171949 / +2.00309416453538 / (1.0e-6 + sigma7) / (1.0e-6 + sigma7);
      accumulator += omega23p;
      omega16p /= accumulator;
      omega17p /= accumulator;
      omega18p /= accumulator;
      omega19p /= accumulator;
      omega20p /= accumulator;
      omega21p /= accumulator;
      omega22p /= accumulator;
      omega23p /= accumulator;
      accumulator = 0.0;
      omega16m = +0.00206277635691854 / +1.00309416453538 / (1.0e-6 + sigma0) / (1.0e-6 + sigma0);
      accumulator += omega16m;
      omega17m = +0.0752289075714074 / +1.00309416453538 / (1.0e-6 + sigma1) / (1.0e-6 + sigma1);
      accumulator += omega17m;
      omega18m = +0.176278023725993 / +1.00309416453538 / (1.0e-6 + sigma2) / (1.0e-6 + sigma2);
      accumulator += omega18m;
      omega19m = +0.355221236480507 / +1.00309416453538 / (1.0e-6 + sigma3) / (1.0e-6 + sigma3);
      accumulator += omega19m;
      omega20m = +0.289199003254305 / +1.00309416453538 / (1.0e-6 + sigma4) / (1.0e-6 + sigma4);
      accumulator += omega20m;
      omega21m = +0.094281005651009 / +1.00309416453538 / (1.0e-6 + sigma5) / (1.0e-6 + sigma5);
      accumulator += omega21m;
      omega22m = +0.0105581616866429 / +1.00309416453538 / (1.0e-6 + sigma6) / (1.0e-6 + sigma6);
      accumulator += omega22m;
      omega23m = +0.00026504980859745 / +1.00309416453538 / (1.0e-6 + sigma7) / (1.0e-6 + sigma7);
      accumulator += omega23m;
      omega16m /= accumulator;
      omega17m /= accumulator;
      omega18m /= accumulator;
      omega19m /= accumulator;
      omega20m /= accumulator;
      omega21m /= accumulator;
      omega22m /= accumulator;
      omega23m /= accumulator;
      accumulator = 0.0;
      omega24p = +0.000530099617252278 / +2.00309416453568 / (1.0e-6 + sigma0) / (1.0e-6 + sigma0);
      accumulator += omega24p;
      omega25p = +0.021116323373197 / +2.00309416453568 / (1.0e-6 + sigma1) / (1.0e-6 + sigma1);
      accumulator += omega25p;
      omega26p = +0.188562011302084 / +2.00309416453568 / (1.0e-6 + sigma2) / (1.0e-6 + sigma2);
      accumulator += omega26p;
      omega27p = +0.578398006508577 / +2.00309416453568 / (1.0e-6 + sigma3) / (1.0e-6 + sigma3);
      accumulator += omega27p;
      omega28p = +0.710442472961015 / +2.00309416453568 / (1.0e-6 + sigma4) / (1.0e-6 + sigma4);
      accumulator += omega28p;
      omega29p = +0.352556047452236 / +2.00309416453568 / (1.0e-6 + sigma5) / (1.0e-6 + sigma5);
      accumulator += omega29p;
      omega30p = +0.150457815142763 / +2.00309416453568 / (1.0e-6 + sigma6) / (1.0e-6 + sigma6);
      accumulator += omega30p;
      omega31p = +0.00103138817855607 / +2.00309416453568 / (1.0e-6 + sigma7) / (1.0e-6 + sigma7);
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
      omega24m = +0.000265049808626139 / +1.00309416453567 / (1.0e-6 + sigma0) / (1.0e-6 + sigma0);
      accumulator += omega24m;
      omega25m = +0.0105581616865985 / +1.00309416453567 / (1.0e-6 + sigma1) / (1.0e-6 + sigma1);
      accumulator += omega25m;
      omega26m = +0.0942810056510418 / +1.00309416453567 / (1.0e-6 + sigma2) / (1.0e-6 + sigma2);
      accumulator += omega26m;
      omega27m = +0.289199003254288 / +1.00309416453567 / (1.0e-6 + sigma3) / (1.0e-6 + sigma3);
      accumulator += omega27m;
      omega28m = +0.355221236480508 / +1.00309416453567 / (1.0e-6 + sigma4) / (1.0e-6 + sigma4);
      accumulator += omega28m;
      omega29m = +0.176278023726118 / +1.00309416453567 / (1.0e-6 + sigma5) / (1.0e-6 + sigma5);
      accumulator += omega29m;
      omega30m = +0.0752289075713816 / +1.00309416453567 / (1.0e-6 + sigma6) / (1.0e-6 + sigma6);
      accumulator += omega30m;
      omega31m = +0.00206277635711214 / +1.00309416453567 / (1.0e-6 + sigma7) / (1.0e-6 + sigma7);
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
      omega32 = +0.000825598666154517 / (1.0e-6 + sigma0) / (1.0e-6 + sigma0);
      accumulator += omega32;
      omega33 = +0.0234582843499763 / (1.0e-6 + sigma1) / (1.0e-6 + sigma1);
      accumulator += omega33;
      omega34 = +0.158185137654354 / (1.0e-6 + sigma2) / (1.0e-6 + sigma2);
      accumulator += omega34;
      omega35 = +0.366708825680975 / (1.0e-6 + sigma3) / (1.0e-6 + sigma3);
      accumulator += omega35;
      omega36 = +0.327082493799916 / (1.0e-6 + sigma4) / (1.0e-6 + sigma4);
      accumulator += omega36;
      omega37 = +0.111006962111596 / (1.0e-6 + sigma5) / (1.0e-6 + sigma5);
      accumulator += omega37;
      omega38 = +0.0124354305727546 / (1.0e-6 + sigma6) / (1.0e-6 + sigma6);
      accumulator += omega38;
      omega39 = +0.000297267164249461 / (1.0e-6 + sigma7) / (1.0e-6 + sigma7);
      accumulator += omega39;
      omega32 /= accumulator;
      omega33 /= accumulator;
      omega34 /= accumulator;
      omega35 /= accumulator;
      omega36 /= accumulator;
      omega37 /= accumulator;
      omega38 /= accumulator;
      omega39 /= accumulator;
      accumulator = 0.0;
      omega40 = +0.00124320124317649 / (1.0e-6 + sigma0) / (1.0e-6 + sigma0);
      accumulator += omega40;
      omega41 = +0.0304584304584759 / (1.0e-6 + sigma1) / (1.0e-6 + sigma1);
      accumulator += omega41;
      omega42 = +0.182750582750552 / (1.0e-6 + sigma2) / (1.0e-6 + sigma2);
      accumulator += omega42;
      omega43 = +0.380730380730387 / (1.0e-6 + sigma3) / (1.0e-6 + sigma3);
      accumulator += omega43;
      omega44 = +0.304584304584304 / (1.0e-6 + sigma4) / (1.0e-6 + sigma4);
      accumulator += omega44;
      omega45 = +0.0913752913752916 / (1.0e-6 + sigma5) / (1.0e-6 + sigma5);
      accumulator += omega45;
      omega46 = +0.00870240870240869 / (1.0e-6 + sigma6) / (1.0e-6 + sigma6);
      accumulator += omega46;
      omega47 = +0.000155400155400156 / (1.0e-6 + sigma7) / (1.0e-6 + sigma7);
      accumulator += omega47;
      omega40 /= accumulator;
      omega41 /= accumulator;
      omega42 /= accumulator;
      omega43 /= accumulator;
      omega44 /= accumulator;
      omega45 /= accumulator;
      omega46 /= accumulator;
      omega47 /= accumulator;
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
	+2.09512850589382 * f[(i + 0) * fsi] - 3.05444611546975 * f[(i + 1) * fsi] +
	4.63927641163466 * f[(i + 2) * fsi] - 5.10779073244638 * f[(i + 3) * fsi] +
	3.80193935265361 * f[(i + 4) * fsi] - 1.81491782916499 * f[(i + 5) * fsi] +
	0.502103285507841 * f[(i + 6) * fsi] - 0.0612928786088129 * f[(i + 7) * fsi];
      f9 =
	+0.0612928786088129 * f[(i - 1) * fsi] + 1.60478547702332 * f[(i + 0) * fsi] -
	1.33824551442299 * f[(i + 1) * fsi] + 1.20687520954114 * f[(i + 2) * fsi] -
	0.817289229829476 * f[(i + 3) * fsi] + 0.369538150560086 * f[(i + 4) * fsi] -
	0.0987172281182313 * f[(i + 5) * fsi] + 0.0117602566373383 * f[(i + 6) * fsi];
      f10 =
	-0.0117602566373383 * f[(i - 2) * fsi] + 0.155374931707519 * f[(i - 1) * fsi] +
	1.27549829117785 * f[(i + 0) * fsi] - 0.679671142732043 * f[(i + 1) * fsi] +
	0.383657244927459 * f[(i + 2) * fsi] - 0.158714858138532 * f[(i + 3) * fsi] +
	0.0402509647146142 * f[(i + 4) * fsi] - 0.00463517501952501 * f[(i + 5) * fsi];
      f11 =
	+0.00463517501952501 * f[(i - 3) * fsi] - 0.0488416567935384 * f[(i - 2) * fsi] +
	0.285159832254219 * f[(i - 1) * fsi] + 1.01592849008445 * f[(i + 0) * fsi] -
	0.355208891365292 * f[(i + 1) * fsi] + 0.124087443834058 * f[(i + 2) * fsi] -
	0.0289299575918318 * f[(i + 3) * fsi] + 0.00316956455841412 * f[(i + 4) * fsi];
      f12 =
	-0.00316956455841412 * f[(i - 4) * fsi] + 0.029991691486838 * f[(i - 3) * fsi] -
	0.137589464429134 * f[(i - 2) * fsi] + 0.46265544752541 * f[(i - 1) * fsi] +
	0.794058970995457 * f[(i + 0) * fsi] - 0.177713276094101 * f[(i + 1) * fsi] +
	0.0353396361984627 * f[(i + 2) * fsi] - 0.00357344112451883 * f[(i + 3) * fsi];
      f13 =
	+0.00357344112451883 * f[(i - 5) * fsi] - 0.0317570935545647 * f[(i - 4) * fsi] +
	0.130048042973365 * f[(i - 3) * fsi] - 0.337702167402188 * f[(i - 2) * fsi] +
	0.712796326241728 * f[(i - 1) * fsi] + 0.593946268022403 * f[(i + 0) * fsi] -
	0.077656924607574 * f[(i + 1) * fsi] + 0.00675210720231205 * f[(i + 2) * fsi];
      f14 =
	-0.00675210720231205 * f[(i - 6) * fsi] + 0.0575902987430153 * f[(i - 5) * fsi] -
	0.220816095219302 * f[(i - 4) * fsi] + 0.50816604630284 * f[(i - 3) * fsi] -
	0.810349671564032 * f[(i - 2) * fsi] + 1.0909143295712 * f[(i - 1) * fsi] +
	0.404887266357665 * f[(i + 0) * fsi] - 0.0236400669890775 * f[(i + 1) * fsi];
      f15 =
	+0.0236400669890775 * f[(i - 7) * fsi] - 0.195872643114932 * f[(i - 6) * fsi] +
	0.719512174437185 * f[(i - 5) * fsi] - 1.54465984660764 * f[(i - 4) * fsi] +
	2.16297073553827 * f[(i - 3) * fsi] - 2.13419342295237 * f[(i - 2) * fsi] +
	1.75283620526537 * f[(i - 1) * fsi] + 0.215766730445045 * f[(i + 0) * fsi];
      f16 =
	+1.17029947786846 * f[(i + 0) * fsi] - 0.115606419045881 * f[(i + 1) * fsi] -
	0.289109525725324 * f[(i + 2) * fsi] + 0.511318566448037 * f[(i + 3) * fsi] -
	0.453659107795932 * f[(i + 4) * fsi] + 0.237473821547982 * f[(i + 5) * fsi] -
	0.0695390294373325 * f[(i + 6) * fsi] + 0.00882221613998465 * f[(i + 7) * fsi];
      f17 =
	-0.00882221613998466 * f[(i - 1) * fsi] + 1.24087720698834 * f[(i + 0) * fsi] -
	0.362628470965451 * f[(i + 1) * fsi] + 0.204934578113813 * f[(i + 2) * fsi] -
	0.106236563350881 * f[(i + 3) * fsi] + 0.0403849960432084 * f[(i + 4) * fsi] -
	0.00954823037158782 * f[(i + 5) * fsi] + 0.00103869968254464 * f[(i + 6) * fsi];
      f18 =
	-0.00103869968254464 * f[(i - 2) * fsi] - 0.000512618679627541 * f[(i - 1) * fsi] +
	1.21179361587709 * f[(i + 0) * fsi] - 0.304461288742951 * f[(i + 1) * fsi] +
	0.132225600335688 * f[(i + 2) * fsi] - 0.0480693811283815 * f[(i + 3) * fsi] +
	0.0113014049319584 * f[(i + 4) * fsi] - 0.00123863291123068 * f[(i + 5) * fsi];
      f19 =
	+0.00123863291123068 * f[(i - 3) * fsi] - 0.0109477629723901 * f[(i - 2) * fsi] +
	0.0341691028348316 * f[(i - 1) * fsi] + 1.14243017284817 * f[(i + 0) * fsi] -
	0.217756984956803 * f[(i + 1) * fsi] + 0.06286215730677 * f[(i + 2) * fsi] -
	0.0133876596139225 * f[(i + 3) * fsi] + 0.00139234164211297 * f[(i + 4) * fsi];
      f20 =
	-0.00139234164211297 * f[(i - 4) * fsi] + 0.0123773660481344 * f[(i - 3) * fsi] -
	0.0499333289515532 * f[(i - 2) * fsi] + 0.112140234793158 * f[(i - 1) * fsi] +
	1.04496625790026 * f[(i + 0) * fsi] - 0.139785852998477 * f[(i + 1) * fsi] +
	0.0238765913276069 * f[(i + 2) * fsi] - 0.00224892647701876 * f[(i + 3) * fsi];
      f21 =
	+0.00224892647701876 * f[(i - 5) * fsi] - 0.019383753458263 * f[(i - 4) * fsi] +
	0.0753473074046597 * f[(i - 3) * fsi] - 0.175873211664604 * f[(i - 2) * fsi] +
	0.269565088184471 * f[(i - 1) * fsi] + 0.919026375187213 * f[(i + 0) * fsi] -
	0.076815911641952 * f[(i + 1) * fsi] + 0.00588517951145682 * f[(i + 2) * fsi];
      f22 =
	-0.00588517951145682 * f[(i - 6) * fsi] + 0.0493303625686733 * f[(i - 5) * fsi] -
	0.184168779779054 * f[(i - 4) * fsi] + 0.404917360046242 * f[(i - 3) * fsi] -
	0.587835777466581 * f[(i - 2) * fsi] + 0.599135140826053 * f[(i - 1) * fsi] +
	0.754241348866422 * f[(i + 0) * fsi] - 0.0297344755502975 * f[(i + 1) * fsi];
      f23 =
	+0.0297344755502975 * f[(i - 7) * fsi] - 0.243760983913837 * f[(i - 6) * fsi] +
	0.881895677977003 * f[(i - 5) * fsi] - 1.84929941059571 * f[(i - 4) * fsi] +
	2.48633064856706 * f[(i - 3) * fsi] - 2.25296640828324 * f[(i - 2) * fsi] +
	1.43170045623438 * f[(i - 1) * fsi] + 0.516365544464042 * f[(i + 0) * fsi];
      f24 =
	+0.516365544464042 * f[(i + 0) * fsi] + 1.43170045623438 * f[(i + 1) * fsi] -
	2.25296640828323 * f[(i + 2) * fsi] + 2.48633064856707 * f[(i + 3) * fsi] -
	1.84929941059571 * f[(i + 4) * fsi] + 0.881895677977001 * f[(i + 5) * fsi] -
	0.243760983913837 * f[(i + 6) * fsi] + 0.0297344755502975 * f[(i + 7) * fsi];
      f25 =
	-0.0297344755502974 * f[(i - 1) * fsi] + 0.754241348866422 * f[(i + 0) * fsi] +
	0.599135140826053 * f[(i + 1) * fsi] - 0.587835777466581 * f[(i + 2) * fsi] +
	0.404917360046242 * f[(i + 3) * fsi] - 0.184168779779054 * f[(i + 4) * fsi] +
	0.0493303625686733 * f[(i + 5) * fsi] - 0.00588517951145682 * f[(i + 6) * fsi];
      f26 =
	+0.00588517951145682 * f[(i - 2) * fsi] - 0.0768159116419522 * f[(i - 1) * fsi] +
	0.919026375187213 * f[(i + 0) * fsi] + 0.269565088184471 * f[(i + 1) * fsi] -
	0.175873211664604 * f[(i + 2) * fsi] + 0.0753473074046596 * f[(i + 3) * fsi] -
	0.019383753458263 * f[(i + 4) * fsi] + 0.00224892647701876 * f[(i + 5) * fsi];
      f27 =
	-0.00224892647701876 * f[(i - 3) * fsi] + 0.0238765913276069 * f[(i - 2) * fsi] -
	0.139785852998477 * f[(i - 1) * fsi] + 1.04496625790026 * f[(i + 0) * fsi] +
	0.112140234793158 * f[(i + 1) * fsi] - 0.0499333289515532 * f[(i + 2) * fsi] +
	0.0123773660481344 * f[(i + 3) * fsi] - 0.00139234164211297 * f[(i + 4) * fsi];
      f28 =
	+0.00139234164211297 * f[(i - 4) * fsi] - 0.0133876596139225 * f[(i - 3) * fsi] +
	0.06286215730677 * f[(i - 2) * fsi] - 0.217756984956804 * f[(i - 1) * fsi] +
	1.14243017284817 * f[(i + 0) * fsi] + 0.0341691028348316 * f[(i + 1) * fsi] -
	0.0109477629723901 * f[(i + 2) * fsi] + 0.00123863291123068 * f[(i + 3) * fsi];
      f29 =
	-0.00123863291123068 * f[(i - 5) * fsi] + 0.0113014049319584 * f[(i - 4) * fsi] -
	0.0480693811283815 * f[(i - 3) * fsi] + 0.132225600335688 * f[(i - 2) * fsi] -
	0.304461288742951 * f[(i - 1) * fsi] + 1.21179361587709 * f[(i + 0) * fsi] -
	0.000512618679627479 * f[(i + 1) * fsi] - 0.00103869968254464 * f[(i + 2) * fsi];
      f30 =
	+0.00103869968254464 * f[(i - 6) * fsi] - 0.00954823037158781 * f[(i - 5) * fsi] +
	0.0403849960432084 * f[(i - 4) * fsi] - 0.106236563350881 * f[(i - 3) * fsi] +
	0.204934578113813 * f[(i - 2) * fsi] - 0.362628470965451 * f[(i - 1) * fsi] +
	1.24087720698834 * f[(i + 0) * fsi] - 0.00882221613998461 * f[(i + 1) * fsi];
      f31 =
	+0.00882221613998461 * f[(i - 7) * fsi] - 0.0695390294373323 * f[(i - 6) * fsi] +
	0.237473821547981 * f[(i - 5) * fsi] - 0.45365910779593 * f[(i - 4) * fsi] +
	0.511318566448041 * f[(i - 3) * fsi] - 0.289109525725326 * f[(i - 2) * fsi] -
	0.115606419045882 * f[(i - 1) * fsi] + 1.17029947786846 * f[(i + 0) * fsi];
      f32 =
	+0.215766730445045 * f[(i + 0) * fsi] + 1.75283620526537 * f[(i + 1) * fsi] -
	2.13419342295237 * f[(i + 2) * fsi] + 2.16297073553828 * f[(i + 3) * fsi] -
	1.54465984660763 * f[(i + 4) * fsi] + 0.719512174437188 * f[(i + 5) * fsi] -
	0.195872643114932 * f[(i + 6) * fsi] + 0.0236400669890775 * f[(i + 7) * fsi];
      f33 =
	-0.0236400669890777 * f[(i - 1) * fsi] + 0.404887266357665 * f[(i + 0) * fsi] +
	1.0909143295712 * f[(i + 1) * fsi] - 0.81034967156403 * f[(i + 2) * fsi] +
	0.508166046302841 * f[(i + 3) * fsi] - 0.220816095219302 * f[(i + 4) * fsi] +
	0.0575902987430153 * f[(i + 5) * fsi] - 0.00675210720231205 * f[(i + 6) * fsi];
      f34 =
	+0.00675210720231205 * f[(i - 2) * fsi] - 0.077656924607574 * f[(i - 1) * fsi] +
	0.593946268022403 * f[(i + 0) * fsi] + 0.712796326241728 * f[(i + 1) * fsi] -
	0.337702167402189 * f[(i + 2) * fsi] + 0.130048042973365 * f[(i + 3) * fsi] -
	0.0317570935545648 * f[(i + 4) * fsi] + 0.00357344112451883 * f[(i + 5) * fsi];
      f35 =
	-0.00357344112451883 * f[(i - 3) * fsi] + 0.0353396361984627 * f[(i - 2) * fsi] -
	0.177713276094101 * f[(i - 1) * fsi] + 0.794058970995457 * f[(i + 0) * fsi] +
	0.46265544752541 * f[(i + 1) * fsi] - 0.137589464429134 * f[(i + 2) * fsi] +
	0.029991691486838 * f[(i + 3) * fsi] - 0.00316956455841412 * f[(i + 4) * fsi];
      f36 =
	+0.00316956455841412 * f[(i - 4) * fsi] - 0.0289299575918318 * f[(i - 3) * fsi] +
	0.124087443834058 * f[(i - 2) * fsi] - 0.355208891365292 * f[(i - 1) * fsi] +
	1.01592849008445 * f[(i + 0) * fsi] + 0.285159832254219 * f[(i + 1) * fsi] -
	0.0488416567935384 * f[(i + 2) * fsi] + 0.00463517501952501 * f[(i + 3) * fsi];
      f37 =
	-0.00463517501952501 * f[(i - 5) * fsi] + 0.0402509647146142 * f[(i - 4) * fsi] -
	0.158714858138532 * f[(i - 3) * fsi] + 0.383657244927459 * f[(i - 2) * fsi] -
	0.679671142732043 * f[(i - 1) * fsi] + 1.27549829117785 * f[(i + 0) * fsi] +
	0.155374931707519 * f[(i + 1) * fsi] - 0.0117602566373383 * f[(i + 2) * fsi];
      f38 =
	+0.0117602566373383 * f[(i - 6) * fsi] - 0.0987172281182313 * f[(i - 5) * fsi] +
	0.369538150560086 * f[(i - 4) * fsi] - 0.817289229829476 * f[(i - 3) * fsi] +
	1.20687520954114 * f[(i - 2) * fsi] - 1.33824551442299 * f[(i - 1) * fsi] +
	1.60478547702332 * f[(i + 0) * fsi] + 0.0612928786088129 * f[(i + 1) * fsi];
      f39 =
	-0.0612928786088129 * f[(i - 7) * fsi] + 0.502103285507841 * f[(i - 6) * fsi] -
	1.81491782916499 * f[(i - 5) * fsi] + 3.80193935265361 * f[(i - 4) * fsi] -
	5.10779073244638 * f[(i - 3) * fsi] + 4.63927641163466 * f[(i - 2) * fsi] -
	3.05444611546975 * f[(i - 1) * fsi] + 2.09512850589382 * f[(i + 0) * fsi];
      f40 =
	+0.125 * f[(i + 0) * fsi] + 1.71785714285714 * f[(i + 1) * fsi] -
	1.78214285714285 * f[(i + 2) * fsi] + 1.71785714285716 * f[(i + 3) * fsi] -
	1.19880952380952 * f[(i + 4) * fsi] + 0.551190476190474 * f[(i + 5) * fsi] -
	0.148809523809524 * f[(i + 6) * fsi] + 0.0178571428571429 * f[(i + 7) * fsi];
      f41 =
	-0.0178571428571428 * f[(i - 1) * fsi] + 0.267857142857143 * f[(i + 0) * fsi] +
	1.21785714285714 * f[(i + 1) * fsi] - 0.782142857142857 * f[(i + 2) * fsi] +
	0.467857142857143 * f[(i + 3) * fsi] - 0.198809523809523 * f[(i + 4) * fsi] +
	0.0511904761904762 * f[(i + 5) * fsi] - 0.00595238095238096 * f[(i + 6) * fsi];
      f42 =
	+0.00595238095238096 * f[(i - 2) * fsi] - 0.0654761904761904 * f[(i - 1) * fsi] +
	0.43452380952381 * f[(i + 0) * fsi] + 0.884523809523809 * f[(i + 1) * fsi] -
	0.365476190476191 * f[(i + 2) * fsi] + 0.134523809523809 * f[(i + 3) * fsi] -
	0.0321428571428572 * f[(i + 4) * fsi] + 0.00357142857142857 * f[(i + 5) * fsi];
      f43 =
	-0.00357142857142857 * f[(i - 3) * fsi] + 0.0345238095238095 * f[(i - 2) * fsi] -
	0.16547619047619 * f[(i - 1) * fsi] + 0.63452380952381 * f[(i + 0) * fsi] +
	0.63452380952381 * f[(i + 1) * fsi] - 0.16547619047619 * f[(i + 2) * fsi] +
	0.0345238095238096 * f[(i + 3) * fsi] - 0.00357142857142857 * f[(i + 4) * fsi];
      f44 =
	+0.00357142857142857 * f[(i - 4) * fsi] - 0.0321428571428571 * f[(i - 3) * fsi] +
	0.13452380952381 * f[(i - 2) * fsi] - 0.365476190476191 * f[(i - 1) * fsi] +
	0.884523809523809 * f[(i + 0) * fsi] + 0.43452380952381 * f[(i + 1) * fsi] -
	0.0654761904761905 * f[(i + 2) * fsi] + 0.00595238095238095 * f[(i + 3) * fsi];
      f45 =
	-0.00595238095238095 * f[(i - 5) * fsi] + 0.0511904761904762 * f[(i - 4) * fsi] -
	0.198809523809524 * f[(i - 3) * fsi] + 0.467857142857143 * f[(i - 2) * fsi] -
	0.782142857142857 * f[(i - 1) * fsi] + 1.21785714285714 * f[(i + 0) * fsi] +
	0.267857142857143 * f[(i + 1) * fsi] - 0.0178571428571429 * f[(i + 2) * fsi];
      f46 =
	+0.0178571428571429 * f[(i - 6) * fsi] - 0.148809523809524 * f[(i - 5) * fsi] +
	0.551190476190476 * f[(i - 4) * fsi] - 1.19880952380952 * f[(i - 3) * fsi] +
	1.71785714285714 * f[(i - 2) * fsi] - 1.78214285714286 * f[(i - 1) * fsi] +
	1.71785714285714 * f[(i + 0) * fsi] + 0.125 * f[(i + 1) * fsi];
      f47 =
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
	+2.00309416453538 * (f16 * omega16p + f17 * omega17p + f18 * omega18p + f19 * omega19p +
			     f20 * omega20p + f21 * omega21p + f22 * omega22p + f23 * omega23p) -
	+1.00309416453538 * (f16 * omega16m + f17 * omega17m + f18 * omega18m + f19 * omega19m +
			     f20 * omega20m + f21 * omega21m + f22 * omega22m + f23 * omega23m);
      fr3 =
	+2.00309416453568 * (f24 * omega24p + f25 * omega25p + f26 * omega26p + f27 * omega27p +
			     f28 * omega28p + f29 * omega29p + f30 * omega30p + f31 * omega31p) -
	+1.00309416453567 * (f24 * omega24m + f25 * omega25m + f26 * omega26m + f27 * omega27m +
			     f28 * omega28m + f29 * omega29m + f30 * omega30m + f31 * omega31m);
      fr4 =
	f32 * omega32 + f33 * omega33 + f34 * omega34 + f35 * omega35 + f36 * omega36 +
	f37 * omega37 + f38 * omega38 + f39 * omega39;
      fr5 =
	f40 * omega40 + f41 * omega41 + f42 * omega42 + f43 * omega43 + f44 * omega44 +
	f45 * omega45 + f46 * omega46 + f47 * omega47;
      fr[i * frsi + 0 * frsl] = fr0;
      fr[i * frsi + 1 * frsl] = fr1;
      fr[i * frsi + 2 * frsl] = fr2;
      fr[i * frsi + 3 * frsl] = fr3;
      fr[i * frsi + 4 * frsl] = fr4;
      fr[i * frsi + 5 * frsl] = fr5;
    }
}

PyObject *
py_gauss_lobatto008006 (PyObject * self, PyObject * args)
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

  gauss_lobatto008006 (f, n, fsi, sigma, ssi, ssr, fr, frsi, frsl);

  Py_INCREF (Py_None);
  return Py_None;
}
