#include <Python.h>
#include <numpy/ndarrayobject.h>

void
gauss_radau007006 (const double *restrict f, int n, int fsi,
		   const double *restrict sigma, int ssi, int ssr,
		   double *restrict fr, int frsi, int frsl)
{
  int i;
  double sigma0, sigma1, sigma2, sigma3, sigma4, sigma5, sigma6, omega10, omega41, omega15,
    omega24m, omega20, omega13, omega25m, omega36, omega24p, omega19, omega3, omega28, omega9,
    omega40, omega14, omega27p, omega32, omega12, omega35, omega16, omega29, omega8, omega23p,
    omega26m, omega39, omega0, omega22m, omega23m, omega33, omega4, omega11, omega17, omega25p,
    omega21m, omega30, omega7, omega22p, omega38, omega1, omega27m, omega34, omega26p, omega2,
    omega6, omega21p, omega31, omega5, omega37, omega18, accumulator, f10, f21, f39, f15, f41, f20,
    f13, f36, f19, f3, f28, f9, f24, f14, f32, f12, f27, f16, f38, f29, f8, f23, f0, f35, f33, f4,
    f40, f11, f17, f30, f7, f26, f1, f34, f37, f22, f2, f6, f31, f5, f25, f18, fr0, fr1, fr2, fr3,
    fr4, fr5;
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
      omega7 = +0.000962888113649304 / (1.0e-6 + sigma0) / (1.0e-6 + sigma0);
      accumulator += omega7;
      omega8 = +0.0317993379439317 / (1.0e-6 + sigma1) / (1.0e-6 + sigma1);
      accumulator += omega8;
      omega9 = +0.207802231069796 / (1.0e-6 + sigma2) / (1.0e-6 + sigma2);
      accumulator += omega9;
      omega10 = +0.41440859669389 / (1.0e-6 + sigma3) / (1.0e-6 + sigma3);
      accumulator += omega10;
      omega11 = +0.281277750353089 / (1.0e-6 + sigma4) / (1.0e-6 + sigma4);
      accumulator += omega11;
      omega12 = +0.0607827329408917 / (1.0e-6 + sigma5) / (1.0e-6 + sigma5);
      accumulator += omega12;
      omega13 = +0.00296646288475067 / (1.0e-6 + sigma6) / (1.0e-6 + sigma6);
      accumulator += omega13;
      omega7 /= accumulator;
      omega8 /= accumulator;
      omega9 /= accumulator;
      omega10 /= accumulator;
      omega11 /= accumulator;
      omega12 /= accumulator;
      omega13 /= accumulator;
      accumulator = 0.0;
      omega14 = +0.0118311455274312 / (1.0e-6 + sigma0) / (1.0e-6 + sigma0);
      accumulator += omega14;
      omega15 = +0.0626398955537863 / (1.0e-6 + sigma1) / (1.0e-6 + sigma1);
      accumulator += omega15;
      omega16 = +0.274417356620531 / (1.0e-6 + sigma2) / (1.0e-6 + sigma2);
      accumulator += omega16;
      omega17 = +0.402460682548186 / (1.0e-6 + sigma3) / (1.0e-6 + sigma3);
      accumulator += omega17;
      omega18 = +0.2116801420173 / (1.0e-6 + sigma4) / (1.0e-6 + sigma4);
      accumulator += omega18;
      omega19 = +0.0356719826271393 / (1.0e-6 + sigma5) / (1.0e-6 + sigma5);
      accumulator += omega19;
      omega20 = +0.00129879510562613 / (1.0e-6 + sigma6) / (1.0e-6 + sigma6);
      accumulator += omega20;
      omega14 /= accumulator;
      omega15 /= accumulator;
      omega16 /= accumulator;
      omega17 /= accumulator;
      omega18 /= accumulator;
      omega19 /= accumulator;
      omega20 /= accumulator;
      accumulator = 0.0;
      omega21p = +0.000743618730218618 / +2.31650342984778 / (1.0e-6 + sigma0) / (1.0e-6 + sigma0);
      accumulator += omega21p;
      omega22p = +0.0250445123361719 / +2.31650342984778 / (1.0e-6 + sigma1) / (1.0e-6 + sigma1);
      accumulator += omega22p;
      omega23p = +0.166794105502837 / +2.31650342984778 / (1.0e-6 + sigma2) / (1.0e-6 + sigma2);
      accumulator += omega23p;
      omega24p = +0.0880107730113661 / +2.31650342984778 / (1.0e-6 + sigma3) / (1.0e-6 + sigma3);
      accumulator += omega24p;
      omega25p = +1.93040927698459 / +2.31650342984778 / (1.0e-6 + sigma4) / (1.0e-6 + sigma4);
      accumulator += omega25p;
      omega26p = +0.10455283994211 / +2.31650342984778 / (1.0e-6 + sigma5) / (1.0e-6 + sigma5);
      accumulator += omega26p;
      omega27p = +0.000948303340484448 / +2.31650342984778 / (1.0e-6 + sigma6) / (1.0e-6 + sigma6);
      accumulator += omega27p;
      omega21p /= accumulator;
      omega22p /= accumulator;
      omega23p /= accumulator;
      omega24p /= accumulator;
      omega25p /= accumulator;
      omega26p /= accumulator;
      omega27p /= accumulator;
      accumulator = 0.0;
      omega21m = +0.000371809365109309 / +1.31650342984778 / (1.0e-6 + sigma0) / (1.0e-6 + sigma0);
      accumulator += omega21m;
      omega22m = +0.0125222561680859 / +1.31650342984778 / (1.0e-6 + sigma1) / (1.0e-6 + sigma1);
      accumulator += omega22m;
      omega23m = +0.0833970527514186 / +1.31650342984778 / (1.0e-6 + sigma2) / (1.0e-6 + sigma2);
      accumulator += omega23m;
      omega24m = +0.0440053865056831 / +1.31650342984778 / (1.0e-6 + sigma3) / (1.0e-6 + sigma3);
      accumulator += omega24m;
      omega25m = +0.965204638492295 / +1.31650342984778 / (1.0e-6 + sigma4) / (1.0e-6 + sigma4);
      accumulator += omega25m;
      omega26m = +0.209105679884219 / +1.31650342984778 / (1.0e-6 + sigma5) / (1.0e-6 + sigma5);
      accumulator += omega26m;
      omega27m = +0.0018966066809689 / +1.31650342984778 / (1.0e-6 + sigma6) / (1.0e-6 + sigma6);
      accumulator += omega27m;
      omega21m /= accumulator;
      omega22m /= accumulator;
      omega23m /= accumulator;
      omega24m /= accumulator;
      omega25m /= accumulator;
      omega26m /= accumulator;
      omega27m /= accumulator;
      accumulator = 0.0;
      omega28 = +0.00208556681083947 / (1.0e-6 + sigma0) / (1.0e-6 + sigma0);
      accumulator += omega28;
      omega29 = +0.0488642839201852 / (1.0e-6 + sigma1) / (1.0e-6 + sigma1);
      accumulator += omega29;
      omega30 = +0.252731862691 / (1.0e-6 + sigma2) / (1.0e-6 + sigma2);
      accumulator += omega30;
      omega31 = +0.415564622531411 / (1.0e-6 + sigma3) / (1.0e-6 + sigma3);
      accumulator += omega31;
      omega32 = +0.236107495042469 / (1.0e-6 + sigma4) / (1.0e-6 + sigma4);
      accumulator += omega32;
      omega33 = +0.042824429810294 / (1.0e-6 + sigma5) / (1.0e-6 + sigma5);
      accumulator += omega33;
      omega34 = +0.00182173919380487 / (1.0e-6 + sigma6) / (1.0e-6 + sigma6);
      accumulator += omega34;
      omega28 /= accumulator;
      omega29 /= accumulator;
      omega30 /= accumulator;
      omega31 /= accumulator;
      omega32 /= accumulator;
      omega33 /= accumulator;
      omega34 /= accumulator;
      accumulator = 0.0;
      omega35 = +0.00359229367834514 / (1.0e-6 + sigma0) / (1.0e-6 + sigma0);
      accumulator += omega35;
      omega36 = +0.0681534100997492 / (1.0e-6 + sigma1) / (1.0e-6 + sigma1);
      accumulator += omega36;
      omega37 = +0.296242587303329 / (1.0e-6 + sigma2) / (1.0e-6 + sigma2);
      accumulator += omega37;
      omega38 = +0.411065074038262 / (1.0e-6 + sigma3) / (1.0e-6 + sigma3);
      accumulator += omega38;
      omega39 = +0.193070324494971 / (1.0e-6 + sigma4) / (1.0e-6 + sigma4);
      accumulator += omega39;
      omega40 = +0.0271666932168213 / (1.0e-6 + sigma5) / (1.0e-6 + sigma5);
      accumulator += omega40;
      omega41 = +0.000709617168528575 / (1.0e-6 + sigma6) / (1.0e-6 + sigma6);
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
	+2.11704131440656 * f[(i + 0) * fsi] - 2.88344943304788 * f[(i + 1) * fsi] +
	3.74065732658104 * f[(i + 2) * fsi] - 3.32890221072926 * f[(i + 3) * fsi] +
	1.86861468718905 * f[(i + 4) * fsi] - 0.596687855513247 * f[(i + 5) * fsi] +
	0.0827261711137405 * f[(i + 6) * fsi];
      f8 =
	+0.0827261711137405 * f[(i - 1) * fsi] + 1.53795811661037 * f[(i + 0) * fsi] -
	1.14619983965933 * f[(i + 1) * fsi] + 0.845241337600119 * f[(i + 2) * fsi] -
	0.433486221748345 * f[(i + 3) * fsi] + 0.131365093800501 * f[(i + 4) * fsi] -
	0.0176046577170635 * f[(i + 5) * fsi];
      f9 =
	-0.0176046577170635 * f[(i - 2) * fsi] + 0.205958775133185 * f[(i - 1) * fsi] +
	1.16826030455204 * f[(i + 0) * fsi] - 0.530036819562104 * f[(i + 1) * fsi] +
	0.229078317502899 * f[(i + 2) * fsi] - 0.0637884096900122 * f[(i + 3) * fsi] +
	0.00813248978105697 * f[(i + 4) * fsi];
      f10 =
	+0.00813248978105697 * f[(i - 3) * fsi] - 0.0745320861844622 * f[(i - 2) * fsi] +
	0.376741060535381 * f[(i - 1) * fsi] + 0.883623162215046 * f[(i + 0) * fsi] -
	0.24539967722511 * f[(i + 1) * fsi] + 0.0582960321007023 * f[(i + 2) * fsi] -
	0.00686098122261348 * f[(i + 3) * fsi];
      f11 =
	-0.00686098122261348 * f[(i - 4) * fsi] + 0.0561593583393513 * f[(i - 3) * fsi] -
	0.218612691859345 * f[(i - 2) * fsi] + 0.616875403326853 * f[(i - 1) * fsi] +
	0.643488819423574 * f[(i + 0) * fsi] - 0.101319071550227 * f[(i + 1) * fsi] +
	0.0102691635424079 * f[(i + 2) * fsi];
      f12 =
	+0.0102691635424079 * f[(i - 5) * fsi] - 0.078745126019469 * f[(i - 4) * fsi] +
	0.271811792729918 * f[(i - 3) * fsi] - 0.578033415843623 * f[(i - 2) * fsi] +
	0.97629612731113 * f[(i - 1) * fsi] + 0.427836385033008 * f[(i + 0) * fsi] -
	0.0294349267533717 * f[(i + 1) * fsi];
      f13 =
	-0.0294349267533717 * f[(i - 6) * fsi] + 0.21631365081601 * f[(i - 5) * fsi] -
	0.696878587840275 * f[(i - 4) * fsi] + 1.30203422909793 * f[(i - 3) * fsi] -
	1.60825585221163 * f[(i - 2) * fsi] + 1.59442958913194 * f[(i - 1) * fsi] +
	0.221791897759405 * f[(i + 0) * fsi];
      f14 =
	+1.33828805615481 * f[(i + 0) * fsi] - 0.598667190775949 * f[(i + 1) * fsi] +
	0.450057601131051 * f[(i + 2) * fsi] - 0.28831089396504 * f[(i + 3) * fsi] +
	0.129428118403337 * f[(i + 4) * fsi] - 0.0350820691312268 * f[(i + 5) * fsi] +
	0.00428637818302013 * f[(i + 6) * fsi];
      f15 =
	+0.00428637818302013 * f[(i - 1) * fsi] + 1.30828340887367 * f[(i + 0) * fsi] -
	0.508653248932526 * f[(i + 1) * fsi] + 0.300034364725345 * f[(i + 2) * fsi] -
	0.138287657559337 * f[(i + 3) * fsi] + 0.0394141765599148 * f[(i + 4) * fsi] -
	0.00507742185008609 * f[(i + 5) * fsi];
      f16 =
	-0.00507742185008609 * f[(i - 2) * fsi] + 0.0398283311336228 * f[(i - 1) * fsi] +
	1.20165755002186 * f[(i + 0) * fsi] - 0.330943484179513 * f[(i + 1) * fsi] +
	0.122324599972332 * f[(i + 2) * fsi] - 0.0316617987075287 * f[(i + 3) * fsi] +
	0.00387222360931219 * f[(i + 4) * fsi];
      f17 =
	+0.00387222360931219 * f[(i - 3) * fsi] - 0.0321829871152714 * f[(i - 2) * fsi] +
	0.121145026929179 * f[(i - 1) * fsi] + 1.06612972369593 * f[(i + 0) * fsi] -
	0.195415657853586 * f[(i + 1) * fsi] + 0.0410079041767765 * f[(i + 2) * fsi] -
	0.0045562334423434 * f[(i + 3) * fsi];
      f18 =
	-0.0045562334423434 * f[(i - 4) * fsi] + 0.035765857705716 * f[(i - 3) * fsi] -
	0.127863889404483 * f[(i - 2) * fsi] + 0.280613197411198 * f[(i - 1) * fsi] +
	0.906661553213915 * f[(i + 0) * fsi] - 0.099734755564375 * f[(i + 1) * fsi] +
	0.00911427008037268 * f[(i + 2) * fsi];
      f19 =
	+0.00911427008037268 * f[(i - 5) * fsi] - 0.0683561240049522 * f[(i - 4) * fsi] +
	0.227165529393542 * f[(i - 3) * fsi] - 0.446863342217526 * f[(i - 2) * fsi] +
	0.599612650224241 * f[(i - 1) * fsi] + 0.715261881526089 * f[(i + 0) * fsi] -
	0.0359348650017663 * f[(i + 1) * fsi];
      f20 =
	-0.0359348650017663 * f[(i - 6) * fsi] + 0.260658325092737 * f[(i - 5) * fsi] -
	0.822988289042044 * f[(i - 4) * fsi] + 1.48488580445536 * f[(i - 3) * fsi] -
	1.70458361727935 * f[(i - 2) * fsi] + 1.35424481526133 * f[(i - 1) * fsi] +
	0.463717826513725 * f[(i + 0) * fsi];
      f21 =
	+0.690675892352604 * f[(i + 0) * fsi] + 0.956332158289084 * f[(i + 1) * fsi] -
	1.40719074601113 * f[(i + 2) * fsi] + 1.29077530403429 * f[(i + 3) * fsi] -
	0.733523052440127 * f[(i + 4) * fsi] + 0.23574184150823 * f[(i + 5) * fsi] -
	0.032811397732956 * f[(i + 6) * fsi];
      f22 =
	-0.032811397732956 * f[(i - 1) * fsi] + 0.920355676483296 * f[(i + 0) * fsi] +
	0.267292805897009 * f[(i + 1) * fsi] - 0.258791825357669 * f[(i + 2) * fsi] +
	0.142376383380833 * f[(i + 3) * fsi] - 0.0444837000480503 * f[(i + 4) * fsi] +
	0.00606205737753781 * f[(i + 5) * fsi];
      f23 =
	+0.00606205737753781 * f[(i - 2) * fsi] - 0.0752457993757206 * f[(i - 1) * fsi] +
	1.04765888141159 * f[(i + 0) * fsi] + 0.0551207976831862 * f[(i + 1) * fsi] -
	0.0466198171438462 * f[(i + 2) * fsi] + 0.0150731784525393 * f[(i + 3) * fsi] -
	0.00204929840528571 * f[(i + 4) * fsi];
      f24 =
	-0.00204929840528571 * f[(i - 3) * fsi] + 0.0204071462145378 * f[(i - 2) * fsi] -
	0.118281065886721 * f[(i - 1) * fsi] + 1.11938432559659 * f[(i + 0) * fsi] -
	0.0166046465018137 * f[(i + 1) * fsi] - 0.00358455063284631 * f[(i + 2) * fsi] +
	0.000728089615539364 * f[(i + 3) * fsi];
      f25 =
	+0.000728089615539363 * f[(i - 4) * fsi] - 0.00714592571406124 * f[(i - 3) * fsi] +
	0.0356970281408644 * f[(i - 2) * fsi] - 0.143764202430598 * f[(i - 1) * fsi] +
	1.14486746214047 * f[(i + 0) * fsi] - 0.0318945284281403 * f[(i + 1) * fsi] +
	0.00151207667592922 * f[(i + 2) * fsi];
      f26 =
	+0.00151207667592922 * f[(i - 5) * fsi] - 0.00985644711596517 * f[(i - 4) * fsi] +
	0.0246076844804524 * f[(i - 3) * fsi] - 0.0172256555166583 * f[(i - 2) * fsi] -
	0.0908415187730757 * f[(i - 1) * fsi] + 1.11311385194595 * f[(i + 0) * fsi] -
	0.0213099916966358 * f[(i + 1) * fsi];
      f27 =
	-0.0213099916966358 * f[(i - 6) * fsi] + 0.15068201855238 * f[(i - 5) * fsi] -
	0.457366272745317 * f[(i - 4) * fsi] + 0.770457393862705 * f[(i - 3) * fsi] -
	0.763075364898911 * f[(i - 2) * fsi] + 0.356668306856276 * f[(i - 1) * fsi] +
	0.963943910069503 * f[(i + 0) * fsi];
      f28 =
	+0.324172453308972 * f[(i + 0) * fsi] + 1.52607937377821 * f[(i + 1) * fsi] -
	1.72167783475456 * f[(i + 2) * fsi] + 1.44561654640208 * f[(i + 3) * fsi] -
	0.787158088565222 * f[(i + 4) * fsi] + 0.246759706071153 * f[(i + 5) * fsi] -
	0.0337921562406364 * f[(i + 6) * fsi];
      f29 =
	-0.0337921562406363 * f[(i - 1) * fsi] + 0.560717546993427 * f[(i + 0) * fsi] +
	0.816444092724846 * f[(i + 1) * fsi] - 0.538952366332281 * f[(i + 2) * fsi] +
	0.262891077979804 * f[(i + 3) * fsi] - 0.0775228075118574 * f[(i + 4) * fsi] +
	0.0102146123866976 * f[(i + 5) * fsi];
      f30 =
	+0.0102146123866976 * f[(i - 2) * fsi] - 0.10529444294752 * f[(i - 1) * fsi] +
	0.775224407114077 * f[(i + 0) * fsi] + 0.458932659190429 * f[(i + 1) * fsi] -
	0.181440932797864 * f[(i + 2) * fsi] + 0.0483842178591543 * f[(i + 3) * fsi] -
	0.006020520804974 * f[(i + 4) * fsi];
      f31 =
	-0.006020520804974 * f[(i - 3) * fsi] + 0.0523582580215156 * f[(i - 2) * fsi] -
	0.231725379851974 * f[(i - 1) * fsi] + 0.985942635288166 * f[(i + 0) * fsi] +
	0.24821443101634 * f[(i + 1) * fsi] - 0.0550099958934106 * f[(i + 2) * fsi] +
	0.0062405722243363 * f[(i + 3) * fsi];
      f32 =
	+0.0062405722243363 * f[(i - 4) * fsi] - 0.0497045263753281 * f[(i - 3) * fsi] +
	0.183410274732578 * f[(i - 2) * fsi] - 0.450145407703744 * f[(i - 1) * fsi] +
	1.20436266313994 * f[(i + 0) * fsi] + 0.117162414305278 * f[(i + 1) * fsi] -
	0.0113259903230565 * f[(i + 2) * fsi];
      f33 =
	-0.0113259903230565 * f[(i - 5) * fsi] + 0.0855225044857321 * f[(i - 4) * fsi] -
	0.287550323159515 * f[(i - 3) * fsi] + 0.579819936039557 * f[(i - 2) * fsi] -
	0.846555069010723 * f[(i - 1) * fsi] + 1.44220845992412 * f[(i + 0) * fsi] +
	0.0378804820438817 * f[(i + 1) * fsi];
      f34 =
	+0.0378804820438817 * f[(i - 6) * fsi] - 0.276489364630229 * f[(i - 5) * fsi] +
	0.881012627407248 * f[(i - 4) * fsi] - 1.61336719469538 * f[(i - 3) * fsi] +
	1.90563680757542 * f[(i - 2) * fsi] - 1.64204519193224 * f[(i - 1) * fsi] +
	1.7073718342313 * f[(i + 0) * fsi];
      f35 =
	+0.172293282039856 * f[(i + 0) * fsi] + 1.60074222815591 * f[(i + 1) * fsi] -
	1.4970983916793 * f[(i + 2) * fsi] + 1.18346309767878 * f[(i + 3) * fsi] -
	0.626445424167631 * f[(i + 4) * fsi] + 0.193234146048868 * f[(i + 5) * fsi] -
	0.0261889380764921 * f[(i + 6) * fsi];
      f36 =
	-0.0261889380764921 * f[(i - 1) * fsi] + 0.355615848575302 * f[(i + 0) * fsi] +
	1.05077452854958 * f[(i + 1) * fsi] - 0.580485559002071 * f[(i + 2) * fsi] +
	0.26685026500156 * f[(i + 3) * fsi] - 0.0764777245612969 * f[(i + 4) * fsi] +
	0.00991157951342282 * f[(i + 5) * fsi];
      f37 =
	+0.00991157951342282 * f[(i - 2) * fsi] - 0.0955699946704518 * f[(i - 1) * fsi] +
	0.563759018357181 * f[(i + 0) * fsi] + 0.703869245579778 * f[(i + 1) * fsi] -
	0.233580276032273 * f[(i + 2) * fsi] + 0.0587070952196808 * f[(i + 3) * fsi] -
	0.00709666796733728 * f[(i + 4) * fsi];
      f38 =
	-0.00709666796733728 * f[(i - 3) * fsi] + 0.0595882552847838 * f[(i - 2) * fsi] -
	0.244600021984535 * f[(i - 1) * fsi] + 0.812142397213986 * f[(i + 0) * fsi] +
	0.455485866722972 * f[(i + 1) * fsi] - 0.0845502487181899 * f[(i + 2) * fsi] +
	0.00903041944831983 * f[(i + 3) * fsi];
      f39 =
	+0.00903041944831983 * f[(i - 4) * fsi] - 0.0703096041055761 * f[(i - 3) * fsi] +
	0.2492270636995 * f[(i - 2) * fsi] - 0.560664702675729 * f[(i - 1) * fsi] +
	1.12820707790518 * f[(i + 0) * fsi] + 0.265847058308256 * f[(i + 1) * fsi] -
	0.0213373125799511 * f[(i + 2) * fsi];
      f40 =
	-0.0213373125799511 * f[(i - 5) * fsi] + 0.158391607507978 * f[(i - 4) * fsi] -
	0.51839316828455 * f[(i - 3) * fsi] + 0.996033003997789 * f[(i - 2) * fsi] -
	1.30747064297402 * f[(i - 1) * fsi] + 1.57629064208415 * f[(i + 0) * fsi] +
	0.116485870248598 * f[(i + 1) * fsi];
      f41 =
	+0.116485870248599 * f[(i - 6) * fsi] - 0.83673840432014 * f[(i - 5) * fsi] +
	2.60459488272855 * f[(i - 4) * fsi] - 4.5953986269855 * f[(i - 3) * fsi] +
	5.07303846269874 * f[(i - 2) * fsi] - 3.75367391819459 * f[(i - 1) * fsi] +
	2.39169173382434 * f[(i + 0) * fsi];
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
	+2.31650342984778 * (f21 * omega21p + f22 * omega22p + f23 * omega23p + f24 * omega24p +
			     f25 * omega25p + f26 * omega26p + f27 * omega27p) -
	+1.31650342984778 * (f21 * omega21m + f22 * omega22m + f23 * omega23m + f24 * omega24m +
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
py_gauss_radau007006 (PyObject * self, PyObject * args)
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

  gauss_radau007006 (f, n, fsi, sigma, ssi, ssr, fr, frsi, frsl);

  Py_INCREF (Py_None);
  return Py_None;
}
