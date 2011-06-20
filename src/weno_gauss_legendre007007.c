#include <Python.h>
#include <numpy/ndarrayobject.h>

void
gauss_legendre007007 (const double *restrict f, int n, int fsi,
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
      omega0 = +0.000660577368856897 / (1.0e-6 + sigma0) / (1.0e-6 + sigma0);
      accumulator += omega0;
      omega1 = +0.0261606572823159 / (1.0e-6 + sigma1) / (1.0e-6 + sigma1);
      accumulator += omega1;
      omega2 = +0.189605406798468 / (1.0e-6 + sigma2) / (1.0e-6 + sigma2);
      accumulator += omega2;
      omega3 = +0.410010880540278 / (1.0e-6 + sigma3) / (1.0e-6 + sigma3);
      accumulator += omega3;
      omega4 = +0.299775861850925 / (1.0e-6 + sigma4) / (1.0e-6 + sigma4);
      accumulator += omega4;
      omega5 = +0.0700252837397488 / (1.0e-6 + sigma5) / (1.0e-6 + sigma5);
      accumulator += omega5;
      omega6 = +0.0037613324194078 / (1.0e-6 + sigma6) / (1.0e-6 + sigma6);
      accumulator += omega6;
      omega0 /= accumulator;
      omega1 /= accumulator;
      omega2 /= accumulator;
      omega3 /= accumulator;
      omega4 /= accumulator;
      omega5 /= accumulator;
      omega6 /= accumulator;
      accumulator = 0.0;
      omega7 = +0.00114509901815391 / (1.0e-6 + sigma0) / (1.0e-6 + sigma0);
      accumulator += omega7;
      omega8 = +0.0346569480536711 / (1.0e-6 + sigma1) / (1.0e-6 + sigma1);
      accumulator += omega8;
      omega9 = +0.215983476600744 / (1.0e-6 + sigma2) / (1.0e-6 + sigma2);
      accumulator += omega9;
      omega10 = +0.415470618361445 / (1.0e-6 + sigma3) / (1.0e-6 + sigma3);
      accumulator += omega10;
      omega11 = +0.273008516474741 / (1.0e-6 + sigma4) / (1.0e-6 + sigma4);
      accumulator += omega11;
      omega12 = +0.0570612144001226 / (1.0e-6 + sigma5) / (1.0e-6 + sigma5);
      accumulator += omega12;
      omega13 = +0.0026741270911219 / (1.0e-6 + sigma6) / (1.0e-6 + sigma6);
      accumulator += omega13;
      omega7 /= accumulator;
      omega8 /= accumulator;
      omega9 /= accumulator;
      omega10 /= accumulator;
      omega11 /= accumulator;
      omega12 /= accumulator;
      omega13 /= accumulator;
      accumulator = 0.0;
      omega14 = +0.00839533443963602 / (1.0e-6 + sigma0) / (1.0e-6 + sigma0);
      accumulator += omega14;
      omega15 = +0.0623791513345609 / (1.0e-6 + sigma1) / (1.0e-6 + sigma1);
      accumulator += omega15;
      omega16 = +0.271538846010698 / (1.0e-6 + sigma2) / (1.0e-6 + sigma2);
      accumulator += omega16;
      omega17 = +0.404451234929024 / (1.0e-6 + sigma3) / (1.0e-6 + sigma3);
      accumulator += omega17;
      omega18 = +0.215228378691828 / (1.0e-6 + sigma4) / (1.0e-6 + sigma4);
      accumulator += omega18;
      omega19 = +0.0366564008547923 / (1.0e-6 + sigma5) / (1.0e-6 + sigma5);
      accumulator += omega19;
      omega20 = +0.00135065373946081 / (1.0e-6 + sigma6) / (1.0e-6 + sigma6);
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
      omega28 = +0.00135065373946928 / (1.0e-6 + sigma0) / (1.0e-6 + sigma0);
      accumulator += omega28;
      omega29 = +0.0366564008547827 / (1.0e-6 + sigma1) / (1.0e-6 + sigma1);
      accumulator += omega29;
      omega30 = +0.215228378691834 / (1.0e-6 + sigma2) / (1.0e-6 + sigma2);
      accumulator += omega30;
      omega31 = +0.404451234929021 / (1.0e-6 + sigma3) / (1.0e-6 + sigma3);
      accumulator += omega31;
      omega32 = +0.271538846010701 / (1.0e-6 + sigma4) / (1.0e-6 + sigma4);
      accumulator += omega32;
      omega33 = +0.062379151334552 / (1.0e-6 + sigma5) / (1.0e-6 + sigma5);
      accumulator += omega33;
      omega34 = +0.00839533443964289 / (1.0e-6 + sigma6) / (1.0e-6 + sigma6);
      accumulator += omega34;
      omega28 /= accumulator;
      omega29 /= accumulator;
      omega30 /= accumulator;
      omega31 /= accumulator;
      omega32 /= accumulator;
      omega33 /= accumulator;
      omega34 /= accumulator;
      accumulator = 0.0;
      omega35 = +0.00267412709111595 / (1.0e-6 + sigma0) / (1.0e-6 + sigma0);
      accumulator += omega35;
      omega36 = +0.0570612144001252 / (1.0e-6 + sigma1) / (1.0e-6 + sigma1);
      accumulator += omega36;
      omega37 = +0.273008516474741 / (1.0e-6 + sigma2) / (1.0e-6 + sigma2);
      accumulator += omega37;
      omega38 = +0.415470618361448 / (1.0e-6 + sigma3) / (1.0e-6 + sigma3);
      accumulator += omega38;
      omega39 = +0.215983476600736 / (1.0e-6 + sigma4) / (1.0e-6 + sigma4);
      accumulator += omega39;
      omega40 = +0.0346569480536837 / (1.0e-6 + sigma5) / (1.0e-6 + sigma5);
      accumulator += omega40;
      omega41 = +0.00114509901814806 / (1.0e-6 + sigma6) / (1.0e-6 + sigma6);
      accumulator += omega41;
      omega35 /= accumulator;
      omega36 /= accumulator;
      omega37 /= accumulator;
      omega38 /= accumulator;
      omega39 /= accumulator;
      omega40 /= accumulator;
      omega41 /= accumulator;
      accumulator = 0.0;
      omega42 = +0.00376133241937168 / (1.0e-6 + sigma0) / (1.0e-6 + sigma0);
      accumulator += omega42;
      omega43 = +0.0700252837397702 / (1.0e-6 + sigma1) / (1.0e-6 + sigma1);
      accumulator += omega43;
      omega44 = +0.29977586185093 / (1.0e-6 + sigma2) / (1.0e-6 + sigma2);
      accumulator += omega44;
      omega45 = +0.410010880540272 / (1.0e-6 + sigma3) / (1.0e-6 + sigma3);
      accumulator += omega45;
      omega46 = +0.189605406798467 / (1.0e-6 + sigma4) / (1.0e-6 + sigma4);
      accumulator += omega46;
      omega47 = +0.0261606572823174 / (1.0e-6 + sigma5) / (1.0e-6 + sigma5);
      accumulator += omega47;
      omega48 = +0.000660577368856541 / (1.0e-6 + sigma6) / (1.0e-6 + sigma6);
      accumulator += omega48;
      omega42 /= accumulator;
      omega43 /= accumulator;
      omega44 /= accumulator;
      omega45 /= accumulator;
      omega46 /= accumulator;
      omega47 /= accumulator;
      omega48 /= accumulator;
      f0 =
	+2.46283837487234 * f[(i + 0) * fsi] - 3.98333348912859 * f[(i + 1) * fsi] +
	5.42972569595347 * f[(i + 2) * fsi] - 4.93679432832251 * f[(i + 3) * fsi] +
	2.80376889838237 * f[(i + 4) * fsi] - 0.901866443030812 * f[(i + 5) * fsi] +
	0.125661291273729 * f[(i + 6) * fsi];
      f1 =
	+0.125661291273729 * f[(i - 1) * fsi] + 1.58320933595623 * f[(i + 0) * fsi] -
	1.34444637238027 * f[(i + 1) * fsi] + 1.03158050137294 * f[(i + 2) * fsi] -
	0.538649133741976 * f[(i + 3) * fsi] + 0.164881781634049 * f[(i + 4) * fsi] -
	0.0222374041147059 * f[(i + 5) * fsi];
      f2 =
	-0.0222374041147059 * f[(i - 2) * fsi] + 0.281323120076671 * f[(i - 1) * fsi] +
	1.11622384954741 * f[(i + 0) * fsi] - 0.566137228365562 * f[(i + 1) * fsi] +
	0.253271357358234 * f[(i + 2) * fsi] - 0.0716636473331528 * f[(i + 3) * fsi] +
	0.00921995283110796 * f[(i + 4) * fsi];
      f3 =
	+0.00921995283110796 * f[(i - 3) * fsi] - 0.0867770739324616 * f[(i - 2) * fsi] +
	0.474942129529938 * f[(i - 1) * fsi] + 0.79352550045863 * f[(i + 0) * fsi] -
	0.243438879276784 * f[(i + 1) * fsi] + 0.0596523479049673 * f[(i + 2) * fsi] -
	0.00712397751539713 * f[(i + 3) * fsi];
      f4 =
	-0.00712397751539713 * f[(i - 4) * fsi] + 0.0590877954388878 * f[(i - 3) * fsi] -
	0.236380601755801 * f[(i - 2) * fsi] + 0.724281342568837 * f[(i - 1) * fsi] +
	0.54418628741973 * f[(i + 0) * fsi] - 0.0938353514534443 * f[(i + 1) * fsi] +
	0.0097845052971874 * f[(i + 2) * fsi];
      f5 =
	+0.0097845052971874 * f[(i - 5) * fsi] - 0.0756155145957089 * f[(i - 4) * fsi] +
	0.264562406679823 * f[(i - 3) * fsi] - 0.57883828715736 * f[(i - 2) * fsi] +
	1.0667390279704 * f[(i - 1) * fsi] + 0.338711676178795 * f[(i + 0) * fsi] -
	0.0253438143731326 * f[(i + 1) * fsi];
      f6 =
	-0.0253438143731326 * f[(i - 6) * fsi] + 0.187191205909115 * f[(i - 5) * fsi] -
	0.607835616431493 * f[(i - 4) * fsi] + 1.15159590973946 * f[(i - 3) * fsi] -
	1.465871790217 * f[(i - 2) * fsi] + 1.59895912980618 * f[(i - 1) * fsi] +
	0.161304975566867 * f[(i + 0) * fsi];
      f7 =
	+1.98342592395132 * f[(i + 0) * fsi] - 2.47043076930104 * f[(i + 1) * fsi] +
	3.1204343418154 * f[(i + 2) * fsi] - 2.74479191643459 * f[(i + 3) * fsi] +
	1.53096618828573 * f[(i + 4) * fsi] - 0.486930098932296 * f[(i + 5) * fsi] +
	0.0673263306154791 * f[(i + 6) * fsi];
      f8 =
	+0.0673263306154791 * f[(i - 1) * fsi] + 1.51214160964296 * f[(i + 0) * fsi] -
	1.05657782637598 * f[(i + 1) * fsi] + 0.764012770273634 * f[(i + 2) * fsi] -
	0.388370344892827 * f[(i + 3) * fsi] + 0.117113245360672 * f[(i + 4) * fsi] -
	0.0156457846239426 * f[(i + 5) * fsi];
      f9 =
	-0.0156457846239426 * f[(i - 2) * fsi] + 0.176846822983077 * f[(i - 1) * fsi] +
	1.18358013254017 * f[(i + 0) * fsi] - 0.508975364537988 * f[(i + 1) * fsi] +
	0.216410308435643 * f[(i + 2) * fsi] - 0.0598088677900319 * f[(i + 3) * fsi] +
	0.00759275299307351 * f[(i + 4) * fsi];
      f10 =
	+0.00759275299307351 * f[(i - 3) * fsi] - 0.0687950555754572 * f[(i - 2) * fsi] +
	0.336294635837621 * f[(i - 1) * fsi] + 0.917833777782597 * f[(i + 0) * fsi] -
	0.243229009780416 * f[(i + 1) * fsi] + 0.0569624955810989 * f[(i + 2) * fsi] -
	0.00665959683851736 * f[(i + 3) * fsi];
      f11 =
	-0.00665959683851736 * f[(i - 4) * fsi] + 0.054209930862695 * f[(i - 3) * fsi] -
	0.208646589184322 * f[(i - 2) * fsi] + 0.569380525185729 * f[(i - 1) * fsi] +
	0.684747888434489 * f[(i + 0) * fsi] - 0.103377476171551 * f[(i + 1) * fsi] +
	0.0103453177114773 * f[(i + 2) * fsi];
      f12 =
	+0.0103453177114773 * f[(i - 5) * fsi] - 0.0790768208188586 * f[(i - 4) * fsi] +
	0.271461602803719 * f[(i - 3) * fsi] - 0.570732709086028 * f[(i - 2) * fsi] +
	0.931466645087435 * f[(i - 1) * fsi] + 0.467496216493465 * f[(i + 0) * fsi] -
	0.0309602521912097 * f[(i + 1) * fsi];
      f13 =
	-0.0309602521912097 * f[(i - 6) * fsi] + 0.227067083049945 * f[(i - 5) * fsi] -
	0.729242116834262 * f[(i - 4) * fsi] + 1.35507042949606 * f[(i - 3) * fsi] -
	1.65434153577837 * f[(i - 2) * fsi] + 1.58163194110284 * f[(i - 1) * fsi] +
	0.250774451154997 * f[(i + 0) * fsi];
      f14 =
	+1.36197528603634 * f[(i + 0) * fsi] - 0.663008559486994 * f[(i + 1) * fsi] +
	0.536684865103452 * f[(i + 2) * fsi] - 0.365899687634299 * f[(i + 3) * fsi] +
	0.173042462090241 * f[(i + 4) * fsi] - 0.0490116647857755 * f[(i + 5) * fsi] +
	0.00621729867703373 * f[(i + 6) * fsi];
      f15 =
	+0.00621729867703374 * f[(i - 1) * fsi] + 1.31845419529711 * f[(i + 0) * fsi] -
	0.532445287269285 * f[(i + 1) * fsi] + 0.319079411407271 * f[(i + 2) * fsi] -
	0.148294233938118 * f[(i + 3) * fsi] + 0.0424791898725318 * f[(i + 4) * fsi] -
	0.00549057404653919 * f[(i + 5) * fsi];
      f16 =
	-0.00549057404653919 * f[(i - 2) * fsi] + 0.0446513170028081 * f[(i - 1) * fsi] +
	1.20315214031978 * f[(i + 0) * fsi] - 0.340275195640413 * f[(i + 1) * fsi] +
	0.126909319778399 * f[(i + 2) * fsi] - 0.0329921789607947 * f[(i + 3) * fsi] +
	0.00404517154675747 * f[(i + 4) * fsi];
      f17 =
	+0.00404517154675747 * f[(i - 3) * fsi] - 0.0338067748738415 * f[(i - 2) * fsi] +
	0.129599919484715 * f[(i - 1) * fsi] + 1.06157113618327 * f[(i + 0) * fsi] -
	0.198694191503902 * f[(i + 1) * fsi] + 0.0419607172964925 * f[(i + 2) * fsi] -
	0.00467597813349246 * f[(i + 3) * fsi];
      f18 =
	-0.00467597813349246 * f[(i - 4) * fsi] + 0.0367770184812047 * f[(i - 3) * fsi] -
	0.132002315677183 * f[(i - 2) * fsi] + 0.293259154156951 * f[(i - 1) * fsi] +
	0.897911901511035 * f[(i + 0) * fsi] - 0.10049865070056 * f[(i + 1) * fsi] +
	0.00922887036204527 * f[(i + 2) * fsi];
      f19 =
	+0.00922887036204527 * f[(i - 5) * fsi] - 0.0692780706678094 * f[(i - 4) * fsi] +
	0.230583296084155 * f[(i - 3) * fsi] - 0.455012778348768 * f[(i - 2) * fsi] +
	0.616269616828536 * f[(i - 1) * fsi] + 0.704105623908084 * f[(i + 0) * fsi] -
	0.0358965581662432 * f[(i + 1) * fsi];
      f20 =
	-0.0358965581662432 * f[(i - 6) * fsi] + 0.260504777525748 * f[(i - 5) * fsi] -
	0.823105792158917 * f[(i - 4) * fsi] + 1.48696283190267 * f[(i - 3) * fsi] -
	1.71139231416728 * f[(i - 2) * fsi] + 1.37009733831964 * f[(i - 1) * fsi] +
	0.452829716744381 * f[(i + 0) * fsi];
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
	+0.452829716744382 * f[(i + 0) * fsi] + 1.37009733831964 * f[(i + 1) * fsi] -
	1.71139231416728 * f[(i + 2) * fsi] + 1.48696283190267 * f[(i + 3) * fsi] -
	0.823105792158918 * f[(i + 4) * fsi] + 0.260504777525748 * f[(i + 5) * fsi] -
	0.0358965581662432 * f[(i + 6) * fsi];
      f29 =
	-0.0358965581662432 * f[(i - 1) * fsi] + 0.704105623908084 * f[(i + 0) * fsi] +
	0.616269616828535 * f[(i + 1) * fsi] - 0.455012778348768 * f[(i + 2) * fsi] +
	0.230583296084156 * f[(i + 3) * fsi] - 0.0692780706678093 * f[(i + 4) * fsi] +
	0.00922887036204527 * f[(i + 5) * fsi];
      f30 =
	+0.00922887036204527 * f[(i - 2) * fsi] - 0.10049865070056 * f[(i - 1) * fsi] +
	0.897911901511035 * f[(i + 0) * fsi] + 0.293259154156951 * f[(i + 1) * fsi] -
	0.132002315677183 * f[(i + 2) * fsi] + 0.0367770184812047 * f[(i + 3) * fsi] -
	0.00467597813349246 * f[(i + 4) * fsi];
      f31 =
	-0.00467597813349246 * f[(i - 3) * fsi] + 0.0419607172964925 * f[(i - 2) * fsi] -
	0.198694191503902 * f[(i - 1) * fsi] + 1.06157113618327 * f[(i + 0) * fsi] +
	0.129599919484715 * f[(i + 1) * fsi] - 0.0338067748738415 * f[(i + 2) * fsi] +
	0.00404517154675747 * f[(i + 3) * fsi];
      f32 =
	+0.00404517154675747 * f[(i - 4) * fsi] - 0.0329921789607947 * f[(i - 3) * fsi] +
	0.126909319778399 * f[(i - 2) * fsi] - 0.340275195640413 * f[(i - 1) * fsi] +
	1.20315214031978 * f[(i + 0) * fsi] + 0.0446513170028081 * f[(i + 1) * fsi] -
	0.00549057404653919 * f[(i + 2) * fsi];
      f33 =
	-0.00549057404653919 * f[(i - 5) * fsi] + 0.0424791898725318 * f[(i - 4) * fsi] -
	0.148294233938118 * f[(i - 3) * fsi] + 0.319079411407271 * f[(i - 2) * fsi] -
	0.532445287269285 * f[(i - 1) * fsi] + 1.31845419529711 * f[(i + 0) * fsi] +
	0.00621729867703374 * f[(i + 1) * fsi];
      f34 =
	+0.00621729867703373 * f[(i - 6) * fsi] - 0.0490116647857753 * f[(i - 5) * fsi] +
	0.17304246209024 * f[(i - 4) * fsi] - 0.365899687634298 * f[(i - 3) * fsi] +
	0.536684865103451 * f[(i - 2) * fsi] - 0.663008559486993 * f[(i - 1) * fsi] +
	1.36197528603634 * f[(i + 0) * fsi];
      f35 =
	+0.250774451154998 * f[(i + 0) * fsi] + 1.58163194110283 * f[(i + 1) * fsi] -
	1.65434153577837 * f[(i + 2) * fsi] + 1.35507042949605 * f[(i + 3) * fsi] -
	0.729242116834262 * f[(i + 4) * fsi] + 0.227067083049945 * f[(i + 5) * fsi] -
	0.0309602521912096 * f[(i + 6) * fsi];
      f36 =
	-0.0309602521912097 * f[(i - 1) * fsi] + 0.467496216493465 * f[(i + 0) * fsi] +
	0.931466645087435 * f[(i + 1) * fsi] - 0.570732709086027 * f[(i + 2) * fsi] +
	0.271461602803719 * f[(i + 3) * fsi] - 0.0790768208188586 * f[(i + 4) * fsi] +
	0.0103453177114773 * f[(i + 5) * fsi];
      f37 =
	+0.0103453177114773 * f[(i - 2) * fsi] - 0.103377476171551 * f[(i - 1) * fsi] +
	0.684747888434489 * f[(i + 0) * fsi] + 0.569380525185729 * f[(i + 1) * fsi] -
	0.208646589184322 * f[(i + 2) * fsi] + 0.0542099308626951 * f[(i + 3) * fsi] -
	0.00665959683851736 * f[(i + 4) * fsi];
      f38 =
	-0.00665959683851736 * f[(i - 3) * fsi] + 0.0569624955810989 * f[(i - 2) * fsi] -
	0.243229009780416 * f[(i - 1) * fsi] + 0.917833777782597 * f[(i + 0) * fsi] +
	0.336294635837621 * f[(i + 1) * fsi] - 0.0687950555754572 * f[(i + 2) * fsi] +
	0.00759275299307351 * f[(i + 3) * fsi];
      f39 =
	+0.00759275299307352 * f[(i - 4) * fsi] - 0.059808867790032 * f[(i - 3) * fsi] +
	0.216410308435643 * f[(i - 2) * fsi] - 0.508975364537988 * f[(i - 1) * fsi] +
	1.18358013254017 * f[(i + 0) * fsi] + 0.176846822983077 * f[(i + 1) * fsi] -
	0.0156457846239426 * f[(i + 2) * fsi];
      f40 =
	-0.0156457846239426 * f[(i - 5) * fsi] + 0.117113245360672 * f[(i - 4) * fsi] -
	0.388370344892827 * f[(i - 3) * fsi] + 0.764012770273634 * f[(i - 2) * fsi] -
	1.05657782637598 * f[(i - 1) * fsi] + 1.51214160964296 * f[(i + 0) * fsi] +
	0.0673263306154791 * f[(i + 1) * fsi];
      f41 =
	+0.0673263306154791 * f[(i - 6) * fsi] - 0.486930098932296 * f[(i - 5) * fsi] +
	1.53096618828573 * f[(i - 4) * fsi] - 2.7447919164346 * f[(i - 3) * fsi] +
	3.1204343418154 * f[(i - 2) * fsi] - 2.47043076930104 * f[(i - 1) * fsi] +
	1.98342592395132 * f[(i + 0) * fsi];
      f42 =
	+0.161304975566867 * f[(i + 0) * fsi] + 1.59895912980618 * f[(i + 1) * fsi] -
	1.465871790217 * f[(i + 2) * fsi] + 1.15159590973946 * f[(i + 3) * fsi] -
	0.607835616431496 * f[(i + 4) * fsi] + 0.187191205909115 * f[(i + 5) * fsi] -
	0.0253438143731325 * f[(i + 6) * fsi];
      f43 =
	-0.0253438143731326 * f[(i - 1) * fsi] + 0.338711676178795 * f[(i + 0) * fsi] +
	1.0667390279704 * f[(i + 1) * fsi] - 0.57883828715736 * f[(i + 2) * fsi] +
	0.264562406679823 * f[(i + 3) * fsi] - 0.075615514595709 * f[(i + 4) * fsi] +
	0.00978450529718741 * f[(i + 5) * fsi];
      f44 =
	+0.00978450529718743 * f[(i - 2) * fsi] - 0.0938353514534442 * f[(i - 1) * fsi] +
	0.544186287419731 * f[(i + 0) * fsi] + 0.724281342568837 * f[(i + 1) * fsi] -
	0.236380601755801 * f[(i + 2) * fsi] + 0.0590877954388879 * f[(i + 3) * fsi] -
	0.00712397751539713 * f[(i + 4) * fsi];
      f45 =
	-0.00712397751539713 * f[(i - 3) * fsi] + 0.0596523479049673 * f[(i - 2) * fsi] -
	0.243438879276784 * f[(i - 1) * fsi] + 0.79352550045863 * f[(i + 0) * fsi] +
	0.474942129529938 * f[(i + 1) * fsi] - 0.0867770739324615 * f[(i + 2) * fsi] +
	0.00921995283110796 * f[(i + 3) * fsi];
      f46 =
	+0.00921995283110796 * f[(i - 4) * fsi] - 0.0716636473331528 * f[(i - 3) * fsi] +
	0.253271357358234 * f[(i - 2) * fsi] - 0.566137228365563 * f[(i - 1) * fsi] +
	1.11622384954741 * f[(i + 0) * fsi] + 0.281323120076671 * f[(i + 1) * fsi] -
	0.0222374041147059 * f[(i + 2) * fsi];
      f47 =
	-0.0222374041147059 * f[(i - 5) * fsi] + 0.164881781634049 * f[(i - 4) * fsi] -
	0.538649133741976 * f[(i - 3) * fsi] + 1.03158050137294 * f[(i - 2) * fsi] -
	1.34444637238027 * f[(i - 1) * fsi] + 1.58320933595623 * f[(i + 0) * fsi] +
	0.125661291273729 * f[(i + 1) * fsi];
      f48 =
	+0.125661291273729 * f[(i - 6) * fsi] - 0.901866443030812 * f[(i - 5) * fsi] +
	2.80376889838237 * f[(i - 4) * fsi] - 4.93679432832251 * f[(i - 3) * fsi] +
	5.42972569595347 * f[(i - 2) * fsi] - 3.98333348912859 * f[(i - 1) * fsi] +
	2.46283837487234 * f[(i + 0) * fsi];
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
py_gauss_legendre007007 (PyObject * self, PyObject * args)
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

  gauss_legendre007007 (f, n, fsi, sigma, ssi, ssr, fr, frsi, frsl);

  Py_INCREF (Py_None);
  return Py_None;
}
