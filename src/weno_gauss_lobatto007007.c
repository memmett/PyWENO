#include <Python.h>
#include <numpy/ndarrayobject.h>

void
gauss_lobatto007007 (const double *restrict f, int n, int fsi,
		     const double *restrict sigma, int ssi, int ssr,
		     double *restrict fr, int frsi, int frsl)
{
  int i;
  double sigma0, sigma1, sigma2, sigma3, sigma4, sigma5, sigma6, omega10, omega46, omega41, omega15,
    omega24m, omega20, omega13, omega25m, omega36, omega24p, omega19, omega3, omega28, omega9,
    omega40, omega14, omega48, omega27p, omega32, omega45, omega12, omega35, omega16, omega29,
    omega8, omega23p, omega26m, omega39, omega0, omega22m, omega23m, omega33, omega4, omega42,
    omega11, omega17, omega25p, omega21m, omega30, omega7, omega22p, omega47, omega38, omega1,
    omega27m, omega34, omega26p, omega43, omega2, omega6, omega21p, omega44, omega31, omega5,
    omega37, omega18, accumulator, f10, f48, f21, f39, f15, f41, f20, f13, f36, f19, f3, f28, f9,
    f24, f14, f32, f45, f12, f27, f16, f38, f29, f8, f46, f23, f0, f35, f33, f4, f40, f11, f42, f17,
    f30, f7, f47, f26, f1, f34, f37, f43, f22, f2, f6, f44, f31, f5, f25, f18, fr0, fr1, fr2, fr3,
    fr4, fr5, fr6;
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
      omega7 = +0.000894784662366575 / (1.0e-6 + sigma0) / (1.0e-6 + sigma0);
      accumulator += omega7;
      omega8 = +0.0306367015221415 / (1.0e-6 + sigma1) / (1.0e-6 + sigma1);
      accumulator += omega8;
      omega9 = +0.204283520472124 / (1.0e-6 + sigma2) / (1.0e-6 + sigma2);
      accumulator += omega9;
      omega10 = +0.413776819056312 / (1.0e-6 + sigma3) / (1.0e-6 + sigma3);
      accumulator += omega10;
      omega11 = +0.284843169654343 / (1.0e-6 + sigma4) / (1.0e-6 + sigma4);
      accumulator += omega11;
      omega12 = +0.0624615079003265 / (1.0e-6 + sigma5) / (1.0e-6 + sigma5);
      accumulator += omega12;
      omega13 = +0.00310349673238642 / (1.0e-6 + sigma6) / (1.0e-6 + sigma6);
      accumulator += omega13;
      omega7 /= accumulator;
      omega8 /= accumulator;
      omega9 /= accumulator;
      omega10 /= accumulator;
      omega11 /= accumulator;
      omega12 /= accumulator;
      omega13 /= accumulator;
      accumulator = 0.0;
      omega14 = +0.00386651133732587 / (1.0e-6 + sigma0) / (1.0e-6 + sigma0);
      accumulator += omega14;
      omega15 = +0.0552521245990446 / (1.0e-6 + sigma1) / (1.0e-6 + sigma1);
      accumulator += omega15;
      omega16 = +0.259405396334304 / (1.0e-6 + sigma2) / (1.0e-6 + sigma2);
      accumulator += omega16;
      omega17 = +0.410427378768024 / (1.0e-6 + sigma3) / (1.0e-6 + sigma3);
      accumulator += omega17;
      omega18 = +0.228798058004498 / (1.0e-6 + sigma4) / (1.0e-6 + sigma4);
      accumulator += omega18;
      omega19 = +0.0406766485837971 / (1.0e-6 + sigma5) / (1.0e-6 + sigma5);
      accumulator += omega19;
      omega20 = +0.0015738823730065 / (1.0e-6 + sigma6) / (1.0e-6 + sigma6);
      accumulator += omega20;
      omega14 /= accumulator;
      omega15 /= accumulator;
      omega16 /= accumulator;
      omega17 /= accumulator;
      omega18 /= accumulator;
      omega19 /= accumulator;
      omega20 /= accumulator;
      accumulator = 0.0;
      omega21p = +0.000149691116038702 / +3.94901979530886 / (1.0e-6 + sigma0) / (1.0e-6 + sigma0);
      accumulator += omega21p;
      omega22p = +0.0106349872873979 / +3.94901979530886 / (1.0e-6 + sigma1) / (1.0e-6 + sigma1);
      accumulator += omega22p;
      omega23p = +0.31405195414804 / +3.94901979530886 / (1.0e-6 + sigma2) / (1.0e-6 + sigma2);
      accumulator += omega23p;
      omega24p = +3.29934653020591 / +3.94901979530886 / (1.0e-6 + sigma3) / (1.0e-6 + sigma3);
      accumulator += omega24p;
      omega25p = +0.31405195414804 / +3.94901979530886 / (1.0e-6 + sigma4) / (1.0e-6 + sigma4);
      accumulator += omega25p;
      omega26p = +0.0106349872873979 / +3.94901979530886 / (1.0e-6 + sigma5) / (1.0e-6 + sigma5);
      accumulator += omega26p;
      omega27p = +0.000149691116038702 / +3.94901979530886 / (1.0e-6 + sigma6) / (1.0e-6 + sigma6);
      accumulator += omega27p;
      omega21p /= accumulator;
      omega22p /= accumulator;
      omega23p /= accumulator;
      omega24p /= accumulator;
      omega25p /= accumulator;
      omega26p /= accumulator;
      omega27p /= accumulator;
      accumulator = 0.0;
      omega21m = +0.000299382232077403 / +2.94901979530886 / (1.0e-6 + sigma0) / (1.0e-6 + sigma0);
      accumulator += omega21m;
      omega22m = +0.0212699745747958 / +2.94901979530886 / (1.0e-6 + sigma1) / (1.0e-6 + sigma1);
      accumulator += omega22m;
      omega23m = +0.628103908296079 / +2.94901979530886 / (1.0e-6 + sigma2) / (1.0e-6 + sigma2);
      accumulator += omega23m;
      omega24m = +1.64967326510295 / +2.94901979530886 / (1.0e-6 + sigma3) / (1.0e-6 + sigma3);
      accumulator += omega24m;
      omega25m = +0.628103908296079 / +2.94901979530886 / (1.0e-6 + sigma4) / (1.0e-6 + sigma4);
      accumulator += omega25m;
      omega26m = +0.0212699745747958 / +2.94901979530886 / (1.0e-6 + sigma5) / (1.0e-6 + sigma5);
      accumulator += omega26m;
      omega27m = +0.000299382232077403 / +2.94901979530886 / (1.0e-6 + sigma6) / (1.0e-6 + sigma6);
      accumulator += omega27m;
      omega21m /= accumulator;
      omega22m /= accumulator;
      omega23m /= accumulator;
      omega24m /= accumulator;
      omega25m /= accumulator;
      omega26m /= accumulator;
      omega27m /= accumulator;
      accumulator = 0.0;
      omega28 = +0.00157388237302191 / (1.0e-6 + sigma0) / (1.0e-6 + sigma0);
      accumulator += omega28;
      omega29 = +0.0406766485837681 / (1.0e-6 + sigma1) / (1.0e-6 + sigma1);
      accumulator += omega29;
      omega30 = +0.228798058004521 / (1.0e-6 + sigma2) / (1.0e-6 + sigma2);
      accumulator += omega30;
      omega31 = +0.410427378768016 / (1.0e-6 + sigma3) / (1.0e-6 + sigma3);
      accumulator += omega31;
      omega32 = +0.259405396334309 / (1.0e-6 + sigma4) / (1.0e-6 + sigma4);
      accumulator += omega32;
      omega33 = +0.0552521245990328 / (1.0e-6 + sigma5) / (1.0e-6 + sigma5);
      accumulator += omega33;
      omega34 = +0.00386651133733421 / (1.0e-6 + sigma6) / (1.0e-6 + sigma6);
      accumulator += omega34;
      omega28 /= accumulator;
      omega29 /= accumulator;
      omega30 /= accumulator;
      omega31 /= accumulator;
      omega32 /= accumulator;
      omega33 /= accumulator;
      omega34 /= accumulator;
      accumulator = 0.0;
      omega35 = +0.00310349673238984 / (1.0e-6 + sigma0) / (1.0e-6 + sigma0);
      accumulator += omega35;
      omega36 = +0.0624615079003212 / (1.0e-6 + sigma1) / (1.0e-6 + sigma1);
      accumulator += omega36;
      omega37 = +0.284843169654345 / (1.0e-6 + sigma2) / (1.0e-6 + sigma2);
      accumulator += omega37;
      omega38 = +0.413776819056313 / (1.0e-6 + sigma3) / (1.0e-6 + sigma3);
      accumulator += omega38;
      omega39 = +0.204283520472122 / (1.0e-6 + sigma4) / (1.0e-6 + sigma4);
      accumulator += omega39;
      omega40 = +0.0306367015221433 / (1.0e-6 + sigma5) / (1.0e-6 + sigma5);
      accumulator += omega40;
      omega41 = +0.000894784662366343 / (1.0e-6 + sigma6) / (1.0e-6 + sigma6);
      accumulator += omega41;
      omega35 /= accumulator;
      omega36 /= accumulator;
      omega37 /= accumulator;
      omega38 /= accumulator;
      omega39 /= accumulator;
      omega40 /= accumulator;
      omega41 /= accumulator;
      accumulator = 0.0;
      omega42 = +0.00407925407926976 / (1.0e-6 + sigma0) / (1.0e-6 + sigma0);
      accumulator += omega42;
      omega43 = +0.0734265734265464 / (1.0e-6 + sigma1) / (1.0e-6 + sigma1);
      accumulator += omega43;
      omega44 = +0.305944055944074 / (1.0e-6 + sigma2) / (1.0e-6 + sigma2);
      accumulator += omega44;
      omega45 = +0.407925407925404 / (1.0e-6 + sigma3) / (1.0e-6 + sigma3);
      accumulator += omega45;
      omega46 = +0.183566433566434 / (1.0e-6 + sigma4) / (1.0e-6 + sigma4);
      accumulator += omega46;
      omega47 = +0.0244755244755245 / (1.0e-6 + sigma5) / (1.0e-6 + sigma5);
      accumulator += omega47;
      omega48 = +0.000582750582750583 / (1.0e-6 + sigma6) / (1.0e-6 + sigma6);
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
	+2.17859507756452 * f[(i + 0) * fsi] - 3.07609571677607 * f[(i + 1) * fsi] +
	4.03279045272597 * f[(i + 2) * fsi] - 3.60530513626671 * f[(i + 3) * fsi] +
	2.02881170958062 * f[(i + 4) * fsi] - 0.648849754632457 * f[(i + 5) * fsi] +
	0.0900533678041341 * f[(i + 6) * fsi];
      f8 =
	+0.0900533678041341 * f[(i - 1) * fsi] + 1.54822150293558 * f[(i + 0) * fsi] -
	1.18497499288925 * f[(i + 1) * fsi] + 0.880922579581271 * f[(i + 2) * fsi] -
	0.453437263122015 * f[(i + 3) * fsi] + 0.137690985693798 * f[(i + 4) * fsi] -
	0.0184761800035179 * f[(i + 5) * fsi];
      f9 =
	-0.0184761800035179 * f[(i - 2) * fsi] + 0.219386627828759 * f[(i - 1) * fsi] +
	1.1602217228617 * f[(i + 0) * fsi] - 0.538308692766124 * f[(i + 1) * fsi] +
	0.234256279458145 * f[(i + 2) * fsi] - 0.0654374830481402 * f[(i + 3) * fsi] +
	0.00835772566917335 * f[(i + 4) * fsi];
      f10 =
	+0.00835772566917335 * f[(i - 3) * fsi] - 0.0769802596877313 * f[(i - 2) * fsi] +
	0.394898866881399 * f[(i - 1) * fsi] + 0.867701324440637 * f[(i + 0) * fsi] -
	0.245788294345057 * f[(i + 1) * fsi] + 0.0587440404055052 * f[(i + 2) * fsi] -
	0.00693340336392676 * f[(i + 3) * fsi];
      f11 =
	-0.00693340336392676 * f[(i - 4) * fsi] + 0.0568915492166607 * f[(i - 3) * fsi] -
	0.222581730330193 * f[(i - 2) * fsi] + 0.637567984618836 * f[(i - 1) * fsi] +
	0.6250322067032 * f[(i + 0) * fsi] - 0.100186823702595 * f[(i + 1) * fsi] +
	0.0102102168580179 * f[(i + 2) * fsi];
      f12 =
	+0.0102102168580179 * f[(i - 5) * fsi] - 0.0784049213700522 * f[(i - 4) * fsi] +
	0.271306103235037 * f[(i - 3) * fsi] - 0.57993932036082 * f[(i - 2) * fsi] +
	0.994925574649463 * f[(i - 1) * fsi] + 0.410617652684824 * f[(i + 0) * fsi] -
	0.0287153056964693 * f[(i + 1) * fsi];
      f13 =
	-0.0287153056964693 * f[(i - 6) * fsi] + 0.211217356733303 * f[(i - 5) * fsi] -
	0.681426340995908 * f[(i - 4) * fsi] + 1.27634180261146 * f[(i - 3) * fsi] -
	1.58497501973725 * f[(i - 2) * fsi] + 1.59794699427532 * f[(i - 1) * fsi] +
	0.209610512809538 * f[(i + 0) * fsi];
      f14 =
	+1.46550009483912 * f[(i + 0) * fsi] - 0.948744361412908 * f[(i + 1) * fsi] +
	0.92696150452797 * f[(i + 2) * fsi] - 0.717736972211502 * f[(i + 3) * fsi] +
	0.371528995279152 * f[(i + 4) * fsi] - 0.112547457270491 * f[(i + 5) * fsi] +
	0.0150381962486614 * f[(i + 6) * fsi];
      f15 =
	+0.0150381962486615 * f[(i - 1) * fsi] + 1.36023272109849 * f[(i + 0) * fsi] -
	0.632942240191018 * f[(i + 1) * fsi] + 0.400624635824821 * f[(i + 2) * fsi] -
	0.191400103508354 * f[(i + 3) * fsi] + 0.055726874057262 * f[(i + 4) * fsi] -
	0.00728008352986136 * f[(i + 5) * fsi];
      f16 =
	-0.00728008352986136 * f[(i - 2) * fsi] + 0.0659987809576909 * f[(i - 1) * fsi] +
	1.2073509669714 * f[(i + 0) * fsi] - 0.37813931664587 * f[(i + 1) * fsi] +
	0.145821712279673 * f[(i + 2) * fsi] - 0.038518349381265 * f[(i + 3) * fsi] +
	0.00476628934823248 * f[(i + 4) * fsi];
      f17 =
	+0.00476628934823248 * f[(i - 3) * fsi] - 0.0406441089674887 * f[(i - 2) * fsi] +
	0.166090857270573 * f[(i - 1) * fsi] + 1.04053083978326 * f[(i + 0) * fsi] -
	0.211319189457733 * f[(i + 1) * fsi] + 0.0457296359667911 * f[(i + 2) * fsi] -
	0.00515432394363764 * f[(i + 3) * fsi];
      f18 =
	-0.00515432394363764 * f[(i - 4) * fsi] + 0.0408465569536959 * f[(i - 3) * fsi] -
	0.148884911783879 * f[(i - 2) * fsi] + 0.34649219529789 * f[(i - 1) * fsi] +
	0.860129501755946 * f[(i + 0) * fsi] - 0.103078386641343 * f[(i + 1) * fsi] +
	0.00964936836132763 * f[(i + 2) * fsi];
      f19 =
	+0.00964936836132763 * f[(i - 5) * fsi] - 0.0726999024729311 * f[(i - 4) * fsi] +
	0.243483292541576 * f[(i - 3) * fsi] - 0.486612804430346 * f[(i - 2) * fsi] +
	0.684220087944357 * f[(i - 1) * fsi] + 0.657492766168065 * f[(i + 0) * fsi] -
	0.0355328081120495 * f[(i + 1) * fsi];
      f20 =
	-0.0355328081120495 * f[(i - 6) * fsi] + 0.258379025145674 * f[(i - 5) * fsi] -
	0.818888872825971 * f[(i - 4) * fsi] + 1.48713157646331 * f[(i - 3) * fsi] -
	1.73026108835208 * f[(i - 2) * fsi] + 1.4304090582974 * f[(i - 1) * fsi] +
	0.408763109383719 * f[(i + 0) * fsi];
      f21 =
	+0.819094122023809 * f[(i + 0) * fsi] + 0.687518601190476 * f[(i + 1) * fsi] -
	1.13598400297619 * f[(i + 2) * fsi] + 1.07853422619048 * f[(i + 3) * fsi] -
	0.622963169642857 * f[(i + 4) * fsi] + 0.20210193452381 * f[(i + 5) * fsi] -
	0.0283017113095238 * f[(i + 6) * fsi];
      f22 =
	-0.0283017113095238 * f[(i - 1) * fsi] + 1.01720610119048 * f[(i + 0) * fsi] +
	0.0931826636904762 * f[(i + 1) * fsi] - 0.145424107142857 * f[(i + 2) * fsi] +
	0.0879743303571429 * f[(i + 3) * fsi] - 0.0286272321428571 * f[(i + 4) * fsi] +
	0.00398995535714286 * f[(i + 5) * fsi];
      f23 =
	+0.00398995535714286 * f[(i - 2) * fsi] - 0.0562313988095238 * f[(i - 1) * fsi] +
	1.10099516369048 * f[(i + 0) * fsi] - 0.0464657738095238 * f[(i + 1) * fsi] -
	0.00577566964285714 * f[(i + 2) * fsi] + 0.00418526785714286 * f[(i + 3) * fsi] -
	0.000697544642857143 * f[(i + 4) * fsi];
      f24 =
	-0.000697544642857143 * f[(i - 3) * fsi] + 0.00887276785714286 * f[(i - 2) * fsi] -
	0.0708798363095238 * f[(i - 1) * fsi] + 1.12540922619048 * f[(i + 0) * fsi] -
	0.0708798363095238 * f[(i + 1) * fsi] + 0.00887276785714286 * f[(i + 2) * fsi] -
	0.000697544642857143 * f[(i + 3) * fsi];
      f25 =
	-0.000697544642857143 * f[(i - 4) * fsi] + 0.00418526785714286 * f[(i - 3) * fsi] -
	0.00577566964285714 * f[(i - 2) * fsi] - 0.0464657738095238 * f[(i - 1) * fsi] +
	1.10099516369048 * f[(i + 0) * fsi] - 0.0562313988095238 * f[(i + 1) * fsi] +
	0.00398995535714286 * f[(i + 2) * fsi];
      f26 =
	+0.00398995535714286 * f[(i - 5) * fsi] - 0.0286272321428571 * f[(i - 4) * fsi] +
	0.0879743303571429 * f[(i - 3) * fsi] - 0.145424107142857 * f[(i - 2) * fsi] +
	0.0931826636904762 * f[(i - 1) * fsi] + 1.01720610119048 * f[(i + 0) * fsi] -
	0.0283017113095238 * f[(i + 1) * fsi];
      f27 =
	-0.0283017113095238 * f[(i - 6) * fsi] + 0.20210193452381 * f[(i - 5) * fsi] -
	0.622963169642857 * f[(i - 4) * fsi] + 1.07853422619048 * f[(i - 3) * fsi] -
	1.13598400297619 * f[(i - 2) * fsi] + 0.687518601190476 * f[(i - 1) * fsi] +
	0.819094122023809 * f[(i + 0) * fsi];
      f28 =
	+0.408763109383719 * f[(i + 0) * fsi] + 1.4304090582974 * f[(i + 1) * fsi] -
	1.73026108835208 * f[(i + 2) * fsi] + 1.48713157646331 * f[(i + 3) * fsi] -
	0.818888872825972 * f[(i + 4) * fsi] + 0.258379025145675 * f[(i + 5) * fsi] -
	0.0355328081120495 * f[(i + 6) * fsi];
      f29 =
	-0.0355328081120495 * f[(i - 1) * fsi] + 0.657492766168065 * f[(i + 0) * fsi] +
	0.684220087944357 * f[(i + 1) * fsi] - 0.486612804430346 * f[(i + 2) * fsi] +
	0.243483292541576 * f[(i + 3) * fsi] - 0.072699902472931 * f[(i + 4) * fsi] +
	0.00964936836132763 * f[(i + 5) * fsi];
      f30 =
	+0.00964936836132763 * f[(i - 2) * fsi] - 0.103078386641343 * f[(i - 1) * fsi] +
	0.860129501755946 * f[(i + 0) * fsi] + 0.34649219529789 * f[(i + 1) * fsi] -
	0.148884911783879 * f[(i + 2) * fsi] + 0.0408465569536959 * f[(i + 3) * fsi] -
	0.00515432394363763 * f[(i + 4) * fsi];
      f31 =
	-0.00515432394363763 * f[(i - 3) * fsi] + 0.0457296359667911 * f[(i - 2) * fsi] -
	0.211319189457733 * f[(i - 1) * fsi] + 1.04053083978326 * f[(i + 0) * fsi] +
	0.166090857270573 * f[(i + 1) * fsi] - 0.0406441089674887 * f[(i + 2) * fsi] +
	0.00476628934823248 * f[(i + 3) * fsi];
      f32 =
	+0.00476628934823249 * f[(i - 4) * fsi] - 0.038518349381265 * f[(i - 3) * fsi] +
	0.145821712279673 * f[(i - 2) * fsi] - 0.37813931664587 * f[(i - 1) * fsi] +
	1.2073509669714 * f[(i + 0) * fsi] + 0.065998780957691 * f[(i + 1) * fsi] -
	0.00728008352986136 * f[(i + 2) * fsi];
      f33 =
	-0.00728008352986136 * f[(i - 5) * fsi] + 0.055726874057262 * f[(i - 4) * fsi] -
	0.191400103508354 * f[(i - 3) * fsi] + 0.400624635824821 * f[(i - 2) * fsi] -
	0.632942240191018 * f[(i - 1) * fsi] + 1.36023272109849 * f[(i + 0) * fsi] +
	0.0150381962486614 * f[(i + 1) * fsi];
      f34 =
	+0.0150381962486614 * f[(i - 6) * fsi] - 0.112547457270491 * f[(i - 5) * fsi] +
	0.371528995279152 * f[(i - 4) * fsi] - 0.717736972211504 * f[(i - 3) * fsi] +
	0.926961504527971 * f[(i - 2) * fsi] - 0.948744361412908 * f[(i - 1) * fsi] +
	1.46550009483912 * f[(i + 0) * fsi];
      f35 =
	+0.209610512809538 * f[(i + 0) * fsi] + 1.59794699427532 * f[(i + 1) * fsi] -
	1.58497501973725 * f[(i + 2) * fsi] + 1.27634180261146 * f[(i + 3) * fsi] -
	0.681426340995911 * f[(i + 4) * fsi] + 0.211217356733305 * f[(i + 5) * fsi] -
	0.0287153056964694 * f[(i + 6) * fsi];
      f36 =
	-0.0287153056964694 * f[(i - 1) * fsi] + 0.410617652684824 * f[(i + 0) * fsi] +
	0.994925574649463 * f[(i + 1) * fsi] - 0.57993932036082 * f[(i + 2) * fsi] +
	0.271306103235037 * f[(i + 3) * fsi] - 0.0784049213700521 * f[(i + 4) * fsi] +
	0.0102102168580179 * f[(i + 5) * fsi];
      f37 =
	+0.0102102168580179 * f[(i - 2) * fsi] - 0.100186823702595 * f[(i - 1) * fsi] +
	0.6250322067032 * f[(i + 0) * fsi] + 0.637567984618836 * f[(i + 1) * fsi] -
	0.222581730330193 * f[(i + 2) * fsi] + 0.0568915492166607 * f[(i + 3) * fsi] -
	0.00693340336392676 * f[(i + 4) * fsi];
      f38 =
	-0.00693340336392676 * f[(i - 3) * fsi] + 0.0587440404055052 * f[(i - 2) * fsi] -
	0.245788294345057 * f[(i - 1) * fsi] + 0.867701324440637 * f[(i + 0) * fsi] +
	0.3948988668814 * f[(i + 1) * fsi] - 0.0769802596877313 * f[(i + 2) * fsi] +
	0.00835772566917335 * f[(i + 3) * fsi];
      f39 =
	+0.00835772566917335 * f[(i - 4) * fsi] - 0.0654374830481402 * f[(i - 3) * fsi] +
	0.234256279458145 * f[(i - 2) * fsi] - 0.538308692766124 * f[(i - 1) * fsi] +
	1.1602217228617 * f[(i + 0) * fsi] + 0.219386627828759 * f[(i + 1) * fsi] -
	0.0184761800035179 * f[(i + 2) * fsi];
      f40 =
	-0.0184761800035179 * f[(i - 5) * fsi] + 0.137690985693799 * f[(i - 4) * fsi] -
	0.453437263122016 * f[(i - 3) * fsi] + 0.880922579581271 * f[(i - 2) * fsi] -
	1.18497499288925 * f[(i - 1) * fsi] + 1.54822150293558 * f[(i + 0) * fsi] +
	0.0900533678041342 * f[(i + 1) * fsi];
      f41 =
	+0.0900533678041342 * f[(i - 6) * fsi] - 0.648849754632457 * f[(i - 5) * fsi] +
	2.02881170958062 * f[(i - 4) * fsi] - 3.60530513626671 * f[(i - 3) * fsi] +
	4.03279045272597 * f[(i - 2) * fsi] - 3.07609571677607 * f[(i - 1) * fsi] +
	2.17859507756452 * f[(i + 0) * fsi];
      f42 =
	+0.142857142857143 * f[(i + 0) * fsi] + 1.59285714285714 * f[(i + 1) * fsi] -
	1.40714285714286 * f[(i + 2) * fsi] + 1.09285714285714 * f[(i + 3) * fsi] -
	0.573809523809524 * f[(i + 4) * fsi] + 0.176190476190476 * f[(i + 5) * fsi] -
	0.0238095238095238 * f[(i + 6) * fsi];
      f43 =
	-0.0238095238095238 * f[(i - 1) * fsi] + 0.30952380952381 * f[(i + 0) * fsi] +
	1.09285714285714 * f[(i + 1) * fsi] - 0.573809523809524 * f[(i + 2) * fsi] +
	0.25952380952381 * f[(i + 3) * fsi] - 0.0738095238095238 * f[(i + 4) * fsi] +
	0.00952380952380954 * f[(i + 5) * fsi];
      f44 =
	+0.00952380952380954 * f[(i - 2) * fsi] - 0.0904761904761906 * f[(i - 1) * fsi] +
	0.50952380952381 * f[(i + 0) * fsi] + 0.759523809523809 * f[(i + 1) * fsi] -
	0.24047619047619 * f[(i + 2) * fsi] + 0.0595238095238095 * f[(i + 3) * fsi] -
	0.00714285714285715 * f[(i + 4) * fsi];
      f45 =
	-0.00714285714285714 * f[(i - 3) * fsi] + 0.0595238095238095 * f[(i - 2) * fsi] -
	0.240476190476191 * f[(i - 1) * fsi] + 0.75952380952381 * f[(i + 0) * fsi] +
	0.50952380952381 * f[(i + 1) * fsi] - 0.0904761904761905 * f[(i + 2) * fsi] +
	0.00952380952380952 * f[(i + 3) * fsi];
      f46 =
	+0.00952380952380952 * f[(i - 4) * fsi] - 0.0738095238095238 * f[(i - 3) * fsi] +
	0.259523809523809 * f[(i - 2) * fsi] - 0.573809523809524 * f[(i - 1) * fsi] +
	1.09285714285714 * f[(i + 0) * fsi] + 0.309523809523809 * f[(i + 1) * fsi] -
	0.0238095238095238 * f[(i + 2) * fsi];
      f47 =
	-0.0238095238095238 * f[(i - 5) * fsi] + 0.176190476190476 * f[(i - 4) * fsi] -
	0.573809523809524 * f[(i - 3) * fsi] + 1.09285714285714 * f[(i - 2) * fsi] -
	1.40714285714286 * f[(i - 1) * fsi] + 1.59285714285714 * f[(i + 0) * fsi] +
	0.142857142857143 * f[(i + 1) * fsi];
      f48 =
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
	f14 * omega14 + f15 * omega15 + f16 * omega16 + f17 * omega17 + f18 * omega18 +
	f19 * omega19 + f20 * omega20;
      fr3 =
	+3.94901979530886 * (f21 * omega21p + f22 * omega22p + f23 * omega23p + f24 * omega24p +
			     f25 * omega25p + f26 * omega26p + f27 * omega27p) -
	+2.94901979530886 * (f21 * omega21m + f22 * omega22m + f23 * omega23m + f24 * omega24m +
			     f25 * omega25m + f26 * omega26m + f27 * omega27m);
      fr4 =
	f28 * omega28 + f29 * omega29 + f30 * omega30 + f31 * omega31 + f32 * omega32 +
	f33 * omega33 + f34 * omega34;
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
py_gauss_lobatto007007 (PyObject * self, PyObject * args)
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

  gauss_lobatto007007 (f, n, fsi, sigma, ssi, ssr, fr, frsi, frsl);

  Py_INCREF (Py_None);
  return Py_None;
}
