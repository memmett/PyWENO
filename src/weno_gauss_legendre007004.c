#include <Python.h>
#include <numpy/ndarrayobject.h>

void
gauss_legendre007004 (const double *restrict f, int n, int fsi,
		      const double *restrict sigma, int ssi, int ssr,
		      double *restrict fr, int frsi, int frsl)
{
  int i;
  double sigma0, sigma1, sigma2, sigma3, sigma4, sigma5, sigma6, omega22, omega7p, omega10m,
    omega18m, omega7m, omega10p, omega17p, omega3, omega16p, omega17m, omega18p, omega11p, omega24,
    omega11m, omega21, omega14m, omega4, omega9p, omega14p, omega9m, omega23, omega0, omega27,
    omega19p, omega20m, omega19m, omega20p, omega5, omega13p, omega8m, omega13m, omega26, omega1,
    omega8p, omega15p, omega16m, omega15m, omega2, omega6, omega12m, omega25, omega12p, accumulator,
    f10, f21, f15, f20, f13, f19, f3, f9, f24, f14, f12, f27, f16, f8, f23, f0, f4, f11, f17, f7,
    f26, f1, f22, f2, f6, f5, f25, f18, fr0, fr1, fr2, fr3;
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
      omega0 = +0.000825131156997689 / (1.0e-6 + sigma0) / (1.0e-6 + sigma0);
      accumulator += omega0;
      omega1 = +0.0293876024178713 / (1.0e-6 + sigma1) / (1.0e-6 + sigma1);
      accumulator += omega1;
      omega2 = +0.200373413242582 / (1.0e-6 + sigma2) / (1.0e-6 + sigma2);
      accumulator += omega2;
      omega3 = +0.412952035307891 / (1.0e-6 + sigma3) / (1.0e-6 + sigma3);
      accumulator += omega3;
      omega4 = +0.288811812341037 / (1.0e-6 + sigma4) / (1.0e-6 + sigma4);
      accumulator += omega4;
      omega5 = +0.0643854858068164 / (1.0e-6 + sigma5) / (1.0e-6 + sigma5);
      accumulator += omega5;
      omega6 = +0.00326451972680444 / (1.0e-6 + sigma6) / (1.0e-6 + sigma6);
      accumulator += omega6;
      omega0 /= accumulator;
      omega1 /= accumulator;
      omega2 /= accumulator;
      omega3 /= accumulator;
      omega4 /= accumulator;
      omega5 /= accumulator;
      omega6 /= accumulator;
      accumulator = 0.0;
      omega7p = +0.0242307063021676 / +2.0726921189065 / (1.0e-6 + sigma0) / (1.0e-6 + sigma0);
      accumulator += omega7p;
      omega8p = +0.232720288153037 / +2.0726921189065 / (1.0e-6 + sigma1) / (1.0e-6 + sigma1);
      accumulator += omega8p;
      omega9p = +0.566372063353182 / +2.0726921189065 / (1.0e-6 + sigma2) / (1.0e-6 + sigma2);
      accumulator += omega9p;
      omega10p = +0.78622420906721 / +2.0726921189065 / (1.0e-6 + sigma3) / (1.0e-6 + sigma3);
      accumulator += omega10p;
      omega11p = +0.396535572333638 / +2.0726921189065 / (1.0e-6 + sigma4) / (1.0e-6 + sigma4);
      accumulator += omega11p;
      omega12p = +0.0643619100665377 / +2.0726921189065 / (1.0e-6 + sigma5) / (1.0e-6 + sigma5);
      accumulator += omega12p;
      omega13p = +0.00224736963073042 / +2.0726921189065 / (1.0e-6 + sigma6) / (1.0e-6 + sigma6);
      accumulator += omega13p;
      omega7p /= accumulator;
      omega8p /= accumulator;
      omega9p /= accumulator;
      omega10p /= accumulator;
      omega11p /= accumulator;
      omega12p /= accumulator;
      omega13p /= accumulator;
      accumulator = 0.0;
      omega7m = +0.0484614126043352 / +1.0726921189065 / (1.0e-6 + sigma0) / (1.0e-6 + sigma0);
      accumulator += omega7m;
      omega8m = +0.116360144076519 / +1.0726921189065 / (1.0e-6 + sigma1) / (1.0e-6 + sigma1);
      accumulator += omega8m;
      omega9m = +0.283186031676591 / +1.0726921189065 / (1.0e-6 + sigma2) / (1.0e-6 + sigma2);
      accumulator += omega9m;
      omega10m = +0.393112104533605 / +1.0726921189065 / (1.0e-6 + sigma3) / (1.0e-6 + sigma3);
      accumulator += omega10m;
      omega11m = +0.198267786166819 / +1.0726921189065 / (1.0e-6 + sigma4) / (1.0e-6 + sigma4);
      accumulator += omega11m;
      omega12m = +0.0321809550332689 / +1.0726921189065 / (1.0e-6 + sigma5) / (1.0e-6 + sigma5);
      accumulator += omega12m;
      omega13m = +0.00112368481536521 / +1.0726921189065 / (1.0e-6 + sigma6) / (1.0e-6 + sigma6);
      accumulator += omega13m;
      omega7m /= accumulator;
      omega8m /= accumulator;
      omega9m /= accumulator;
      omega10m /= accumulator;
      omega11m /= accumulator;
      omega12m /= accumulator;
      omega13m /= accumulator;
      accumulator = 0.0;
      omega14p = +0.00224736963069245 / +2.07269211890664 / (1.0e-6 + sigma0) / (1.0e-6 + sigma0);
      accumulator += omega14p;
      omega15p = +0.0643619100666162 / +2.07269211890664 / (1.0e-6 + sigma1) / (1.0e-6 + sigma1);
      accumulator += omega15p;
      omega16p = +0.396535572333567 / +2.07269211890664 / (1.0e-6 + sigma2) / (1.0e-6 + sigma2);
      accumulator += omega16p;
      omega17p = +0.78622420906724 / +2.07269211890664 / (1.0e-6 + sigma3) / (1.0e-6 + sigma3);
      accumulator += omega17p;
      omega18p = +0.566372063353188 / +2.07269211890664 / (1.0e-6 + sigma4) / (1.0e-6 + sigma4);
      accumulator += omega18p;
      omega19p = +0.232720288153123 / +2.07269211890664 / (1.0e-6 + sigma5) / (1.0e-6 + sigma5);
      accumulator += omega19p;
      omega20p = +0.0242307063022159 / +2.07269211890664 / (1.0e-6 + sigma6) / (1.0e-6 + sigma6);
      accumulator += omega20p;
      omega14p /= accumulator;
      omega15p /= accumulator;
      omega16p /= accumulator;
      omega17p /= accumulator;
      omega18p /= accumulator;
      omega19p /= accumulator;
      omega20p /= accumulator;
      accumulator = 0.0;
      omega14m = +0.00112368481534623 / +1.07269211890664 / (1.0e-6 + sigma0) / (1.0e-6 + sigma0);
      accumulator += omega14m;
      omega15m = +0.0321809550333081 / +1.07269211890664 / (1.0e-6 + sigma1) / (1.0e-6 + sigma1);
      accumulator += omega15m;
      omega16m = +0.198267786166783 / +1.07269211890664 / (1.0e-6 + sigma2) / (1.0e-6 + sigma2);
      accumulator += omega16m;
      omega17m = +0.39311210453362 / +1.07269211890664 / (1.0e-6 + sigma3) / (1.0e-6 + sigma3);
      accumulator += omega17m;
      omega18m = +0.283186031676594 / +1.07269211890664 / (1.0e-6 + sigma4) / (1.0e-6 + sigma4);
      accumulator += omega18m;
      omega19m = +0.116360144076562 / +1.07269211890664 / (1.0e-6 + sigma5) / (1.0e-6 + sigma5);
      accumulator += omega19m;
      omega20m = +0.0484614126044317 / +1.07269211890664 / (1.0e-6 + sigma6) / (1.0e-6 + sigma6);
      accumulator += omega20m;
      omega14m /= accumulator;
      omega15m /= accumulator;
      omega16m /= accumulator;
      omega17m /= accumulator;
      omega18m /= accumulator;
      omega19m /= accumulator;
      omega20m /= accumulator;
      accumulator = 0.0;
      omega21 = +0.00326451972679134 / (1.0e-6 + sigma0) / (1.0e-6 + sigma0);
      accumulator += omega21;
      omega22 = +0.0643854858068253 / (1.0e-6 + sigma1) / (1.0e-6 + sigma1);
      accumulator += omega22;
      omega23 = +0.288811812341036 / (1.0e-6 + sigma2) / (1.0e-6 + sigma2);
      accumulator += omega23;
      omega24 = +0.412952035307893 / (1.0e-6 + sigma3) / (1.0e-6 + sigma3);
      accumulator += omega24;
      omega25 = +0.200373413242574 / (1.0e-6 + sigma4) / (1.0e-6 + sigma4);
      accumulator += omega25;
      omega26 = +0.0293876024178815 / (1.0e-6 + sigma5) / (1.0e-6 + sigma5);
      accumulator += omega26;
      omega27 = +0.000825131156993965 / (1.0e-6 + sigma6) / (1.0e-6 + sigma6);
      accumulator += omega27;
      omega21 /= accumulator;
      omega22 /= accumulator;
      omega23 /= accumulator;
      omega24 /= accumulator;
      omega25 /= accumulator;
      omega26 /= accumulator;
      omega27 /= accumulator;
      f0 =
	+2.24995051948217 * f[(i + 0) * fsi] - 3.30119242441534 * f[(i + 1) * fsi] +
	4.37624670299775 * f[(i + 2) * fsi] - 3.9312299384068 * f[(i + 3) * fsi] +
	2.21802870776502 * f[(i + 4) * fsi] - 0.710527251319901 * f[(i + 5) * fsi] +
	0.0987236838971073 * f[(i + 6) * fsi];
      f1 =
	+0.0987236838971073 * f[(i - 1) * fsi] + 1.55888473220242 * f[(i + 0) * fsi] -
	1.22799506257609 * f[(i + 1) * fsi] + 0.920917766598995 * f[(i + 2) * fsi] -
	0.475901002008048 * f[(i + 3) * fsi] + 0.144831345925769 * f[(i + 4) * fsi] -
	0.0194614640401497 * f[(i + 5) * fsi];
      f2 =
	-0.0194614640401497 * f[(i - 2) * fsi] + 0.234953932178155 * f[(i - 1) * fsi] +
	1.15019398735927 * f[(i + 0) * fsi] - 0.546843821170853 * f[(i + 1) * fsi] +
	0.239766525193758 * f[(i + 2) * fsi] - 0.0672102571649058 * f[(i + 3) * fsi] +
	0.00860109764472105 * f[(i + 4) * fsi];
      f3 =
	+0.00860109764472105 * f[(i - 3) * fsi] - 0.079669147553197 * f[(i - 2) * fsi] +
	0.415576982717297 * f[(i - 1) * fsi] + 0.849155569794038 * f[(i + 0) * fsi] -
	0.245805403605616 * f[(i + 1) * fsi] + 0.0591434746546157 * f[(i + 2) * fsi] -
	0.00700257365185843 * f[(i + 3) * fsi];
      f4 =
	-0.00700257365185843 * f[(i - 4) * fsi] + 0.05761911320773 * f[(i - 3) * fsi] -
	0.226723194242224 * f[(i - 2) * fsi] + 0.660667060532342 * f[(i - 1) * fsi] +
	0.604065491978993 * f[(i + 0) * fsi] - 0.0987513569165892 * f[(i + 1) * fsi] +
	0.0101254590916067 * f[(i + 2) * fsi];
      f5 =
	+0.0101254590916067 * f[(i - 5) * fsi] - 0.0778807872931051 * f[(i - 4) * fsi] +
	0.27025375413147 * f[(i - 3) * fsi] - 0.581114262448458 * f[(i - 2) * fsi] +
	1.01505812873858 * f[(i - 1) * fsi] + 0.391430851055253 * f[(i + 0) * fsi] -
	0.0278731432753425 * f[(i + 1) * fsi];
      f6 =
	-0.0278731432753425 * f[(i - 6) * fsi] + 0.205237462019004 * f[(i - 5) * fsi] -
	0.663216796075298 * f[(i - 4) * fsi] + 1.24581376876846 * f[(i - 3) * fsi] -
	1.55667427708545 * f[(i - 2) * fsi] + 1.60039413752077 * f[(i - 1) * fsi] +
	0.196318848127855 * f[(i + 0) * fsi];
      f7 =
	+1.25969584049256 * f[(i + 0) * fsi] - 0.388149525753131 * f[(i + 1) * fsi] +
	0.170219332689315 * f[(i + 2) * fsi] - 0.0391047459162751 * f[(i + 3) * fsi] -
	0.010214516302896 * f[(i + 4) * fsi] + 0.00942904720005655 * f[(i + 5) * fsi] -
	0.00187543240963306 * f[(i + 6) * fsi];
      f8 =
	-0.00187543240963309 * f[(i - 1) * fsi] + 1.27282386736 * f[(i + 0) * fsi] -
	0.427533606355426 * f[(i + 1) * fsi] + 0.235859467026473 * f[(i + 2) * fsi] -
	0.104744880253433 * f[(i + 3) * fsi] + 0.0291695642993986 * f[(i + 4) * fsi] -
	0.00369897966737531 * f[(i + 5) * fsi];
      f9 =
	-0.00369897966737531 * f[(i - 2) * fsi] + 0.0240174252619941 * f[(i - 1) * fsi] +
	1.19514529434511 * f[(i + 0) * fsi] - 0.298069317997289 * f[(i + 1) * fsi] +
	0.106395178668337 * f[(i + 2) * fsi] - 0.0270663072385518 * f[(i + 3) * fsi] +
	0.0032767066277714 * f[(i + 4) * fsi];
      f10 =
	+0.0032767066277714 * f[(i - 3) * fsi] - 0.0266359260617751 * f[(i - 2) * fsi] +
	0.0928282644451935 * f[(i - 1) * fsi] + 1.08046056237311 * f[(i + 0) * fsi] -
	0.18338458602529 * f[(i + 1) * fsi] + 0.0375843394851378 * f[(i + 2) * fsi] -
	0.00412936084415201 * f[(i + 3) * fsi];
      f11 =
	-0.00412936084415201 * f[(i - 4) * fsi] + 0.0321822325368355 * f[(i - 3) * fsi] -
	0.113352503788967 * f[(i - 2) * fsi] + 0.237355893990514 * f[(i - 1) * fsi] +
	0.935932932827794 * f[(i + 0) * fsi] - 0.0966680082980981 * f[(i + 1) * fsi] +
	0.00867881357607378 * f[(i + 2) * fsi];
      f12 =
	+0.00867881357607378 * f[(i - 5) * fsi] - 0.0648810558766685 * f[(i - 4) * fsi] +
	0.214437317634385 * f[(i - 3) * fsi] - 0.41711097895155 * f[(i - 2) * fsi] +
	0.541114369153096 * f[(i - 1) * fsi] + 0.753677847730245 * f[(i + 0) * fsi] -
	0.0359163132655817 * f[(i + 1) * fsi];
      f13 =
	-0.0359163132655817 * f[(i - 6) * fsi] + 0.260093006435145 * f[(i - 5) * fsi] -
	0.819123634453883 * f[(i - 4) * fsi] + 1.47150828192974 * f[(i - 3) * fsi] -
	1.67418194324691 * f[(i - 2) * fsi] + 1.29535694773031 * f[(i - 1) * fsi] +
	0.502263654871173 * f[(i + 0) * fsi];
      f14 =
	+0.502263654871173 * f[(i + 0) * fsi] + 1.29535694773031 * f[(i + 1) * fsi] -
	1.67418194324691 * f[(i + 2) * fsi] + 1.47150828192974 * f[(i + 3) * fsi] -
	0.819123634453883 * f[(i + 4) * fsi] + 0.260093006435146 * f[(i + 5) * fsi] -
	0.0359163132655816 * f[(i + 6) * fsi];
      f15 =
	-0.0359163132655816 * f[(i - 1) * fsi] + 0.753677847730245 * f[(i + 0) * fsi] +
	0.541114369153097 * f[(i + 1) * fsi] - 0.41711097895155 * f[(i + 2) * fsi] +
	0.214437317634385 * f[(i + 3) * fsi] - 0.0648810558766684 * f[(i + 4) * fsi] +
	0.00867881357607379 * f[(i + 5) * fsi];
      f16 =
	+0.00867881357607378 * f[(i - 2) * fsi] - 0.0966680082980981 * f[(i - 1) * fsi] +
	0.935932932827794 * f[(i + 0) * fsi] + 0.237355893990514 * f[(i + 1) * fsi] -
	0.113352503788967 * f[(i + 2) * fsi] + 0.0321822325368355 * f[(i + 3) * fsi] -
	0.00412936084415201 * f[(i + 4) * fsi];
      f17 =
	-0.00412936084415201 * f[(i - 3) * fsi] + 0.0375843394851379 * f[(i - 2) * fsi] -
	0.18338458602529 * f[(i - 1) * fsi] + 1.08046056237311 * f[(i + 0) * fsi] +
	0.0928282644451935 * f[(i + 1) * fsi] - 0.0266359260617751 * f[(i + 2) * fsi] +
	0.0032767066277714 * f[(i + 3) * fsi];
      f18 =
	+0.0032767066277714 * f[(i - 4) * fsi] - 0.0270663072385518 * f[(i - 3) * fsi] +
	0.106395178668337 * f[(i - 2) * fsi] - 0.298069317997289 * f[(i - 1) * fsi] +
	1.19514529434511 * f[(i + 0) * fsi] + 0.0240174252619941 * f[(i + 1) * fsi] -
	0.00369897966737531 * f[(i + 2) * fsi];
      f19 =
	-0.00369897966737531 * f[(i - 5) * fsi] + 0.0291695642993986 * f[(i - 4) * fsi] -
	0.104744880253433 * f[(i - 3) * fsi] + 0.235859467026473 * f[(i - 2) * fsi] -
	0.427533606355425 * f[(i - 1) * fsi] + 1.27282386736 * f[(i + 0) * fsi] -
	0.00187543240963308 * f[(i + 1) * fsi];
      f20 =
	-0.00187543240963308 * f[(i - 6) * fsi] + 0.00942904720005619 * f[(i - 5) * fsi] -
	0.0102145163028962 * f[(i - 4) * fsi] - 0.0391047459162757 * f[(i - 3) * fsi] +
	0.170219332689315 * f[(i - 2) * fsi] - 0.388149525753131 * f[(i - 1) * fsi] +
	1.25969584049256 * f[(i + 0) * fsi];
      f21 =
	+0.196318848127855 * f[(i + 0) * fsi] + 1.60039413752077 * f[(i + 1) * fsi] -
	1.55667427708544 * f[(i + 2) * fsi] + 1.24581376876846 * f[(i + 3) * fsi] -
	0.663216796075298 * f[(i + 4) * fsi] + 0.205237462019005 * f[(i + 5) * fsi] -
	0.0278731432753424 * f[(i + 6) * fsi];
      f22 =
	-0.0278731432753424 * f[(i - 1) * fsi] + 0.391430851055253 * f[(i + 0) * fsi] +
	1.01505812873858 * f[(i + 1) * fsi] - 0.581114262448457 * f[(i + 2) * fsi] +
	0.270253754131471 * f[(i + 3) * fsi] - 0.0778807872931053 * f[(i + 4) * fsi] +
	0.0101254590916067 * f[(i + 5) * fsi];
      f23 =
	+0.0101254590916067 * f[(i - 2) * fsi] - 0.0987513569165895 * f[(i - 1) * fsi] +
	0.604065491978993 * f[(i + 0) * fsi] + 0.660667060532342 * f[(i + 1) * fsi] -
	0.226723194242224 * f[(i + 2) * fsi] + 0.0576191132077301 * f[(i + 3) * fsi] -
	0.00700257365185843 * f[(i + 4) * fsi];
      f24 =
	-0.00700257365185843 * f[(i - 3) * fsi] + 0.0591434746546157 * f[(i - 2) * fsi] -
	0.245805403605616 * f[(i - 1) * fsi] + 0.849155569794038 * f[(i + 0) * fsi] +
	0.415576982717297 * f[(i + 1) * fsi] - 0.079669147553197 * f[(i + 2) * fsi] +
	0.00860109764472106 * f[(i + 3) * fsi];
      f25 =
	+0.00860109764472106 * f[(i - 4) * fsi] - 0.0672102571649058 * f[(i - 3) * fsi] +
	0.239766525193758 * f[(i - 2) * fsi] - 0.546843821170853 * f[(i - 1) * fsi] +
	1.15019398735927 * f[(i + 0) * fsi] + 0.234953932178155 * f[(i + 1) * fsi] -
	0.0194614640401496 * f[(i + 2) * fsi];
      f26 =
	-0.0194614640401496 * f[(i - 5) * fsi] + 0.144831345925769 * f[(i - 4) * fsi] -
	0.475901002008048 * f[(i - 3) * fsi] + 0.920917766598995 * f[(i - 2) * fsi] -
	1.22799506257609 * f[(i - 1) * fsi] + 1.55888473220242 * f[(i + 0) * fsi] +
	0.0987236838971073 * f[(i + 1) * fsi];
      f27 =
	+0.0987236838971073 * f[(i - 6) * fsi] - 0.710527251319901 * f[(i - 5) * fsi] +
	2.21802870776502 * f[(i - 4) * fsi] - 3.9312299384068 * f[(i - 3) * fsi] +
	4.37624670299775 * f[(i - 2) * fsi] - 3.30119242441534 * f[(i - 1) * fsi] +
	2.24995051948217 * f[(i + 0) * fsi];
      fr0 =
	f0 * omega0 + f1 * omega1 + f2 * omega2 + f3 * omega3 + f4 * omega4 + f5 * omega5 +
	f6 * omega6;
      fr1 =
	+2.0726921189065 * (f7 * omega7p + f8 * omega8p + f9 * omega9p + f10 * omega10p +
			    f11 * omega11p + f12 * omega12p + f13 * omega13p) -
	+1.0726921189065 * (f7 * omega7m + f8 * omega8m + f9 * omega9m + f10 * omega10m +
			    f11 * omega11m + f12 * omega12m + f13 * omega13m);
      fr2 =
	+2.07269211890664 * (f14 * omega14p + f15 * omega15p + f16 * omega16p + f17 * omega17p +
			     f18 * omega18p + f19 * omega19p + f20 * omega20p) -
	+1.07269211890664 * (f14 * omega14m + f15 * omega15m + f16 * omega16m + f17 * omega17m +
			     f18 * omega18m + f19 * omega19m + f20 * omega20m);
      fr3 =
	f21 * omega21 + f22 * omega22 + f23 * omega23 + f24 * omega24 + f25 * omega25 +
	f26 * omega26 + f27 * omega27;
      fr[i * frsi + 0 * frsl] = fr0;
      fr[i * frsi + 1 * frsl] = fr1;
      fr[i * frsi + 2 * frsl] = fr2;
      fr[i * frsi + 3 * frsl] = fr3;
    }
}

PyObject *
py_gauss_legendre007004 (PyObject * self, PyObject * args)
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

  gauss_legendre007004 (f, n, fsi, sigma, ssi, ssr, fr, frsi, frsl);

  Py_INCREF (Py_None);
  return Py_None;
}
