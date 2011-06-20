#include <Python.h>
#include <numpy/ndarrayobject.h>

void
gauss_radau008004 (const double *restrict f, int n, int fsi,
		   const double *restrict sigma, int ssi, int ssr,
		   double *restrict fr, int frsi, int frsl)
{
  int i;
  double sigma0, sigma1, sigma2, sigma3, sigma4, sigma5, sigma6, sigma7, omega23m, omega11, omega24,
    omega7, omega14, omega19p, omega31, omega3, omega18p, omega19m, omega10, omega20p, omega25,
    omega27, omega13, omega16m, omega4, omega16p, omega26, omega0, omega30, omega21p, omega22m,
    omega12, omega21m, omega22p, omega5, omega20m, omega8, omega29, omega1, omega17p, omega18m,
    omega17m, omega9, omega6, omega15, omega23p, omega28, omega2, accumulator, f11, f24, f7, f22,
    f14, f31, f21, f3, f10, f27, f16, f13, f30, f18, f9, f23, f26, f0, f4, f12, f19, f17, f8, f29,
    f1, f25, f2, f6, f15, f5, f28, f20, fr0, fr1, fr2, fr3;
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
      omega8 = +0.000611618683642063 / (1.0e-6 + sigma0) / (1.0e-6 + sigma0);
      accumulator += omega8;
      omega9 = +0.017558882724207 / (1.0e-6 + sigma1) / (1.0e-6 + sigma1);
      accumulator += omega9;
      omega10 = +0.131867570640969 / (1.0e-6 + sigma2) / (1.0e-6 + sigma2);
      accumulator += omega10;
      omega11 = +0.344430637603237 / (1.0e-6 + sigma3) / (1.0e-6 + sigma3);
      accumulator += omega11;
      omega12 = +0.349355021540756 / (1.0e-6 + sigma4) / (1.0e-6 + sigma4);
      accumulator += omega12;
      omega13 = +0.137180111300869 / (1.0e-6 + sigma5) / (1.0e-6 + sigma5);
      accumulator += omega13;
      omega14 = +0.0184228159623023 / (1.0e-6 + sigma6) / (1.0e-6 + sigma6);
      accumulator += omega14;
      omega15 = +0.000573341544018272 / (1.0e-6 + sigma7) / (1.0e-6 + sigma7);
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
      omega16p = +0.00032591831239633 / +2.21671164613761 / (1.0e-6 + sigma0) / (1.0e-6 + sigma0);
      accumulator += omega16p;
      omega17p = +0.0141531909020551 / +2.21671164613761 / (1.0e-6 + sigma1) / (1.0e-6 + sigma1);
      accumulator += omega17p;
      omega18p = +0.135889218959098 / +2.21671164613761 / (1.0e-6 + sigma2) / (1.0e-6 + sigma2);
      accumulator += omega18p;
      omega19p = +0.445505562426469 / +2.21671164613761 / (1.0e-6 + sigma3) / (1.0e-6 + sigma3);
      accumulator += omega19p;
      omega20p = +0.518104208530332 / +2.21671164613761 / (1.0e-6 + sigma4) / (1.0e-6 + sigma4);
      accumulator += omega20p;
      omega21p = +1.03049633162806 / +2.21671164613761 / (1.0e-6 + sigma5) / (1.0e-6 + sigma5);
      accumulator += omega21p;
      omega22p = +0.0718569663984915 / +2.21671164613761 / (1.0e-6 + sigma6) / (1.0e-6 + sigma6);
      accumulator += omega22p;
      omega23p = +0.000380248980714796 / +2.21671164613761 / (1.0e-6 + sigma7) / (1.0e-6 + sigma7);
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
      omega16m = +0.000162959156198165 / +1.21671164613761 / (1.0e-6 + sigma0) / (1.0e-6 + sigma0);
      accumulator += omega16m;
      omega17m = +0.00707659545102756 / +1.21671164613761 / (1.0e-6 + sigma1) / (1.0e-6 + sigma1);
      accumulator += omega17m;
      omega18m = +0.0679446094795488 / +1.21671164613761 / (1.0e-6 + sigma2) / (1.0e-6 + sigma2);
      accumulator += omega18m;
      omega19m = +0.222752781213235 / +1.21671164613761 / (1.0e-6 + sigma3) / (1.0e-6 + sigma3);
      accumulator += omega19m;
      omega20m = +0.259052104265166 / +1.21671164613761 / (1.0e-6 + sigma4) / (1.0e-6 + sigma4);
      accumulator += omega20m;
      omega21m = +0.515248165814028 / +1.21671164613761 / (1.0e-6 + sigma5) / (1.0e-6 + sigma5);
      accumulator += omega21m;
      omega22m = +0.143713932796983 / +1.21671164613761 / (1.0e-6 + sigma6) / (1.0e-6 + sigma6);
      accumulator += omega22m;
      omega23m = +0.000760497961429593 / +1.21671164613761 / (1.0e-6 + sigma7) / (1.0e-6 + sigma7);
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
      omega24 = +0.000915114994764859 / (1.0e-6 + sigma0) / (1.0e-6 + sigma0);
      accumulator += omega24;
      omega25 = +0.0250738231614237 / (1.0e-6 + sigma1) / (1.0e-6 + sigma1);
      accumulator += omega25;
      omega26 = +0.164263855168315 / (1.0e-6 + sigma2) / (1.0e-6 + sigma2);
      accumulator += omega26;
      omega27 = +0.370744890828354 / (1.0e-6 + sigma3) / (1.0e-6 + sigma3);
      accumulator += omega27;
      omega28 = +0.321663449012093 / (1.0e-6 + sigma4) / (1.0e-6 + sigma4);
      accumulator += omega28;
      omega29 = +0.105740260862526 / (1.0e-6 + sigma5) / (1.0e-6 + sigma5);
      accumulator += omega29;
      omega30 = +0.0113480810768709 / (1.0e-6 + sigma6) / (1.0e-6 + sigma6);
      accumulator += omega30;
      omega31 = +0.000250524895642771 / (1.0e-6 + sigma7) / (1.0e-6 + sigma7);
      accumulator += omega31;
      omega24 /= accumulator;
      omega25 /= accumulator;
      omega26 /= accumulator;
      omega27 /= accumulator;
      omega28 /= accumulator;
      omega29 /= accumulator;
      omega30 /= accumulator;
      omega31 /= accumulator;
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
	+1.67919584372994 * f[(i + 0) * fsi] - 1.66366151057882 * f[(i + 1) * fsi] +
	2.21576537303139 * f[(i + 2) * fsi] - 2.2975029083739 * f[(i + 3) * fsi] +
	1.65388594508446 * f[(i + 4) * fsi] - 0.772990357221084 * f[(i + 5) * fsi] +
	0.210765266651676 * f[(i + 6) * fsi] - 0.025457652323652 * f[(i + 7) * fsi];
      f9 =
	+0.025457652323652 * f[(i - 1) * fsi] + 1.47553462514072 * f[(i + 0) * fsi] -
	0.950847245516566 * f[(i + 1) * fsi] + 0.790136842906877 * f[(i + 2) * fsi] -
	0.515467245718257 * f[(i + 3) * fsi] + 0.228257414959943 * f[(i + 4) * fsi] -
	0.0601760921588277 * f[(i + 5) * fsi] + 0.00710404806245944 * f[(i + 6) * fsi];
      f10 =
	-0.00710404806245944 * f[(i - 2) * fsi] + 0.0822900368233275 * f[(i - 1) * fsi] +
	1.27662127939185 * f[(i + 0) * fsi] - 0.553020554018837 * f[(i + 1) * fsi] +
	0.292853478534716 * f[(i + 2) * fsi] - 0.117640554220529 * f[(i + 3) * fsi] +
	0.0293440692110783 * f[(i + 4) * fsi] - 0.00334370765915218 * f[(i + 5) * fsi];
      f11 =
	+0.00334370765915218 * f[(i - 3) * fsi] - 0.0338537093356769 * f[(i - 2) * fsi] +
	0.175913851279589 * f[(i - 1) * fsi] + 1.08937365047933 * f[(i + 0) * fsi] -
	0.318961017878184 * f[(i + 1) * fsi] + 0.105605849622194 * f[(i + 2) * fsi] -
	0.0240167397642678 * f[(i + 3) * fsi] + 0.00259440793786084 * f[(i + 4) * fsi];
      f12 =
	-0.00259440793786084 * f[(i - 4) * fsi] + 0.0240989711620389 * f[(i - 3) * fsi] -
	0.106497131595781 * f[(i - 2) * fsi] + 0.321200695799796 * f[(i - 1) * fsi] +
	0.907765094829074 * f[(i + 0) * fsi] - 0.173674173357977 * f[(i + 1) * fsi] +
	0.0329624273620907 * f[(i + 2) * fsi] - 0.00326147626138106 * f[(i + 3) * fsi];
      f13 =
	+0.00326147626138106 * f[(i - 5) * fsi] - 0.0286862180289093 * f[(i - 4) * fsi] +
	0.115420306480709 * f[(i - 3) * fsi] - 0.28913980223312 * f[(i - 2) * fsi] +
	0.54950403409647 * f[(i - 1) * fsi] + 0.725122424191735 * f[(i + 0) * fsi] -
	0.0823528380393074 * f[(i + 1) * fsi] + 0.00687061727104222 * f[(i + 2) * fsi];
      f14 =
	-0.00687061727104222 * f[(i - 6) * fsi] + 0.0582264144297188 * f[(i - 5) * fsi] -
	0.221063501618092 * f[(i - 4) * fsi] + 0.500174873659073 * f[(i - 3) * fsi] -
	0.770083011206075 * f[(i - 2) * fsi] + 0.934258601274834 * f[(i - 1) * fsi] +
	0.532745140602552 * f[(i + 0) * fsi] - 0.0273878998709696 * f[(i + 1) * fsi];
      f15 =
	+0.0273878998709696 * f[(i - 7) * fsi] - 0.225973816238799 * f[(i - 6) * fsi] +
	0.825087610816867 * f[(i - 5) * fsi] - 1.75478589439239 * f[(i - 4) * fsi] +
	2.41732786462694 * f[(i - 3) * fsi] - 2.30380540398037 * f[(i - 2) * fsi] +
	1.70111979766198 * f[(i - 1) * fsi] + 0.313641941634796 * f[(i + 0) * fsi];
      f16 =
	+0.607752511561176 * f[(i + 0) * fsi] + 1.26407238236751 * f[(i + 1) * fsi] -
	2.11086345874091 * f[(i + 2) * fsi] + 2.37593801240528 * f[(i + 3) * fsi] -
	1.78417331047415 * f[(i + 4) * fsi] + 0.855604042617776 * f[(i + 5) * fsi] -
	0.237357920422193 * f[(i + 6) * fsi] + 0.0290277406855216 * f[(i + 7) * fsi];
      f17 =
	-0.0290277406855217 * f[(i - 1) * fsi] + 0.839974437045349 * f[(i + 0) * fsi] +
	0.451295643172903 * f[(i + 1) * fsi] - 0.485309980351697 * f[(i + 2) * fsi] +
	0.343996164418761 * f[(i + 3) * fsi] - 0.158619832084944 * f[(i + 4) * fsi] +
	0.0428273034231699 * f[(i + 5) * fsi] - 0.00513599493802024 * f[(i + 6) * fsi];
      f18 =
	+0.00513599493802024 * f[(i - 2) * fsi] - 0.0701157001896835 * f[(i - 1) * fsi] +
	0.983782295309916 * f[(i + 0) * fsi] + 0.16367992664377 * f[(i + 1) * fsi] -
	0.125790334690281 * f[(i + 2) * fsi] + 0.0563804478896274 * f[(i + 3) * fsi] -
	0.014811973820377 * f[(i + 4) * fsi] + 0.00173934391900801 * f[(i + 5) * fsi];
      f19 =
	-0.00173934391900801 * f[(i - 3) * fsi] + 0.0190507462900844 * f[(i - 2) * fsi] -
	0.118817329921908 * f[(i - 1) * fsi] + 1.08118555477436 * f[(i + 0) * fsi] +
	0.041925852313209 * f[(i + 1) * fsi] - 0.0283870752258323 * f[(i + 2) * fsi] +
	0.00767881815740308 * f[(i + 3) * fsi] - 0.000897222468312843 * f[(i + 4) * fsi];
      f20 =
	+0.000897222468312844 * f[(i - 4) * fsi] - 0.00891712366551076 * f[(i - 3) * fsi] +
	0.044172975402844 * f[(i - 2) * fsi] - 0.169061788147427 * f[(i - 1) * fsi] +
	1.14399112755626 * f[(i + 0) * fsi] - 0.00831860591231035 * f[(i + 1) * fsi] -
	0.00326484611307271 * f[(i + 2) * fsi] + 0.000501038410900312 * f[(i + 3) * fsi];
      f21 =
	-0.000501038410900311 * f[(i - 5) * fsi] + 0.00490552975551534 * f[(i - 4) * fsi] -
	0.0229461991707195 * f[(i - 3) * fsi] + 0.0722311264132615 * f[(i - 2) * fsi] -
	0.204134476910449 * f[(i - 1) * fsi] + 1.17204927856668 * f[(i + 0) * fsi] -
	0.022347681417519 * f[(i + 1) * fsi] + 0.000743461174129778 * f[(i + 2) * fsi];
      f22 =
	-0.000743461174129779 * f[(i - 6) * fsi] + 0.00544665098213792 * f[(i - 5) * fsi] -
	0.0159113831201184 * f[(i - 4) * fsi] + 0.0186876265805482 * f[(i - 3) * fsi] +
	0.0201888442241768 * f[(i - 2) * fsi] - 0.162500651159181 * f[(i - 1) * fsi] +
	1.15123236569105 * f[(i + 0) * fsi] - 0.0163999920244808 * f[(i + 1) * fsi];
      f23 =
	+0.0163999920244808 * f[(i - 7) * fsi] - 0.131943397369976 * f[(i - 6) * fsi] +
	0.4646464276676 * f[(i - 5) * fsi] - 0.934310936491043 * f[(i - 4) * fsi] +
	1.1666870682942 * f[(i - 3) * fsi] - 0.898210709146747 * f[(i - 2) * fsi] +
	0.296699125526281 * f[(i - 1) * fsi] + 1.0200324294952 * f[(i + 0) * fsi];
      f24 =
	+0.190574056150323 * f[(i + 0) * fsi] + 1.75320196567092 * f[(i + 1) * fsi] -
	2.05969128614681 * f[(i + 2) * fsi] + 2.06383237724566 * f[(i + 3) * fsi] -
	1.46608013657033 * f[(i + 4) * fsi] + 0.680859347179221 * f[(i + 5) * fsi] -
	0.184993590461215 * f[(i + 6) * fsi] + 0.0222972669322101 * f[(i + 7) * fsi];
      f25 =
	-0.0222972669322102 * f[(i - 1) * fsi] + 0.368952191608006 * f[(i + 0) * fsi] +
	1.12887849156904 * f[(i + 1) * fsi] - 0.811044337943026 * f[(i + 2) * fsi] +
	0.503023691990945 * f[(i + 3) * fsi] - 0.217433188366556 * f[(i + 4) * fsi] +
	0.0565358730773377 * f[(i + 5) * fsi] - 0.00661545500353269 * f[(i + 6) * fsi];
      f26 =
	+0.00661545500353269 * f[(i - 2) * fsi] - 0.0752209069604717 * f[(i - 1) * fsi] +
	0.554184931706921 * f[(i + 0) * fsi] + 0.758413011371208 * f[(i + 1) * fsi] -
	0.347962487695738 * f[(i + 2) * fsi] + 0.132558211793114 * f[(i + 3) * fsi] -
	0.0322004482676408 * f[(i + 4) * fsi] + 0.00361223304907608 * f[(i + 5) * fsi];
      f27 =
	-0.00361223304907608 * f[(i - 3) * fsi] + 0.0355133193961414 * f[(i - 2) * fsi] -
	0.176363432334602 * f[(i - 1) * fsi] + 0.756469982455181 * f[(i + 0) * fsi] +
	0.505556697935882 * f[(i + 1) * fsi] - 0.145677436947478 * f[(i + 2) * fsi] +
	0.0314156864189834 * f[(i + 3) * fsi] - 0.00330258387503214 * f[(i + 4) * fsi];
      f28 =
	+0.00330258387503213 * f[(i - 4) * fsi] - 0.0300329040493331 * f[(i - 3) * fsi] +
	0.127985667897041 * f[(i - 2) * fsi] - 0.361308129336401 * f[(i - 1) * fsi] +
	0.98765085370743 * f[(i + 0) * fsi] + 0.320612000934082 * f[(i + 1) * fsi] -
	0.0532050884465778 * f[(i + 2) * fsi] + 0.00499501541872638 * f[(i + 3) * fsi];
      f29 =
	-0.00499501541872638 * f[(i - 5) * fsi] + 0.0432627072248432 * f[(i - 4) * fsi] -
	0.169893335773672 * f[(i - 3) * fsi] + 0.407706531345718 * f[(i - 2) * fsi] -
	0.710959208647248 * f[(i - 1) * fsi] + 1.26737171715611 * f[(i + 0) * fsi] +
	0.180751569209744 * f[(i + 1) * fsi] - 0.0132449650967667 * f[(i + 2) * fsi];
      f30 =
	+0.0132449650967667 * f[(i - 6) * fsi] - 0.11095473619286 * f[(i - 5) * fsi] +
	0.414121729934312 * f[(i - 4) * fsi] - 0.91161138119261 * f[(i - 3) * fsi] +
	1.33485408811939 * f[(i - 2) * fsi] - 1.45267725406619 * f[(i - 1) * fsi] +
	1.63823073986558 * f[(i + 0) * fsi] + 0.0747918484356097 * f[(i + 1) * fsi];
      f31 =
	-0.0747918484356097 * f[(i - 7) * fsi] + 0.611579752581644 * f[(i - 6) * fsi] -
	2.20512649238993 * f[(i - 5) * fsi] + 4.60246524232845 * f[(i - 4) * fsi] -
	6.14704077168529 * f[(i - 3) * fsi] + 5.52319760051353 * f[(i - 2) * fsi] -
	3.54684901026326 * f[(i - 1) * fsi] + 2.23656552735045 * f[(i + 0) * fsi];
      fr0 =
	f0 * omega0 + f1 * omega1 + f2 * omega2 + f3 * omega3 + f4 * omega4 + f5 * omega5 +
	f6 * omega6 + f7 * omega7;
      fr1 =
	f8 * omega8 + f9 * omega9 + f10 * omega10 + f11 * omega11 + f12 * omega12 + f13 * omega13 +
	f14 * omega14 + f15 * omega15;
      fr2 =
	+2.21671164613761 * (f16 * omega16p + f17 * omega17p + f18 * omega18p + f19 * omega19p +
			     f20 * omega20p + f21 * omega21p + f22 * omega22p + f23 * omega23p) -
	+1.21671164613761 * (f16 * omega16m + f17 * omega17m + f18 * omega18m + f19 * omega19m +
			     f20 * omega20m + f21 * omega21m + f22 * omega22m + f23 * omega23m);
      fr3 =
	f24 * omega24 + f25 * omega25 + f26 * omega26 + f27 * omega27 + f28 * omega28 +
	f29 * omega29 + f30 * omega30 + f31 * omega31;
      fr[i * frsi + 0 * frsl] = fr0;
      fr[i * frsi + 1 * frsl] = fr1;
      fr[i * frsi + 2 * frsl] = fr2;
      fr[i * frsi + 3 * frsl] = fr3;
    }
}

PyObject *
py_gauss_radau008004 (PyObject * self, PyObject * args)
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

  gauss_radau008004 (f, n, fsi, sigma, ssi, ssr, fr, frsi, frsl);

  Py_INCREF (Py_None);
  return Py_None;
}
