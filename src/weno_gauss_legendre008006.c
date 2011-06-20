#include <Python.h>
#include <numpy/ndarrayobject.h>

void
gauss_legendre008006 (const double *restrict f, int n, int fsi,
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
      omega0 = +0.000185454984938948 / (1.0e-6 + sigma0) / (1.0e-6 + sigma0);
      accumulator += omega0;
      omega1 = +0.00961335477354165 / (1.0e-6 + sigma1) / (1.0e-6 + sigma1);
      accumulator += omega1;
      omega2 = +0.0965932796956175 / (1.0e-6 + sigma2) / (1.0e-6 + sigma2);
      accumulator += omega2;
      omega3 = +0.311193284596056 / (1.0e-6 + sigma3) / (1.0e-6 + sigma3);
      accumulator += omega3;
      omega4 = +0.377303221585198 / (1.0e-6 + sigma4) / (1.0e-6 + sigma4);
      accumulator += omega4;
      omega5 = +0.175689584054757 / (1.0e-6 + sigma5) / (1.0e-6 + sigma5);
      accumulator += omega5;
      omega6 = +0.0283147432082758 / (1.0e-6 + sigma6) / (1.0e-6 + sigma6);
      accumulator += omega6;
      omega7 = +0.00110707710161335 / (1.0e-6 + sigma7) / (1.0e-6 + sigma7);
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
      omega8 = +0.000421910662764846 / (1.0e-6 + sigma0) / (1.0e-6 + sigma0);
      accumulator += omega8;
      omega9 = +0.0148491683890896 / (1.0e-6 + sigma1) / (1.0e-6 + sigma1);
      accumulator += omega9;
      omega10 = +0.12158138942745 / (1.0e-6 + sigma2) / (1.0e-6 + sigma2);
      accumulator += omega10;
      omega11 = +0.336682046705106 / (1.0e-6 + sigma3) / (1.0e-6 + sigma3);
      accumulator += omega11;
      omega12 = +0.35815171973648 / (1.0e-6 + sigma4) / (1.0e-6 + sigma4);
      accumulator += omega12;
      omega13 = +0.146967330147332 / (1.0e-6 + sigma5) / (1.0e-6 + sigma5);
      accumulator += omega13;
      omega14 = +0.0206657997962523 / (1.0e-6 + sigma6) / (1.0e-6 + sigma6);
      accumulator += omega14;
      omega15 = +0.000680635135524925 / (1.0e-6 + sigma7) / (1.0e-6 + sigma7);
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
      omega16p = +0.000628744803332587 / +2.04145761412373 / (1.0e-6 + sigma0) / (1.0e-6 + sigma0);
      accumulator += omega16p;
      omega17p = +0.628023513130632 / +2.04145761412373 / (1.0e-6 + sigma1) / (1.0e-6 + sigma1);
      accumulator += omega17p;
      omega18p = +0.0131904599045775 / +2.04145761412373 / (1.0e-6 + sigma2) / (1.0e-6 + sigma2);
      accumulator += omega18p;
      omega19p = +0.679446960879483 / +2.04145761412373 / (1.0e-6 + sigma3) / (1.0e-6 + sigma3);
      accumulator += omega19p;
      omega20p = +0.533656694819353 / +2.04145761412373 / (1.0e-6 + sigma4) / (1.0e-6 + sigma4);
      accumulator += omega20p;
      omega21p = +0.167895194154111 / +2.04145761412373 / (1.0e-6 + sigma5) / (1.0e-6 + sigma5);
      accumulator += omega21p;
      omega22p = +0.0181771148576749 / +2.04145761412373 / (1.0e-6 + sigma6) / (1.0e-6 + sigma6);
      accumulator += omega22p;
      omega23p = +0.000438931574566521 / +2.04145761412373 / (1.0e-6 + sigma7) / (1.0e-6 + sigma7);
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
      omega16m = +0.00125748960666517 / +1.04145761412373 / (1.0e-6 + sigma0) / (1.0e-6 + sigma0);
      accumulator += omega16m;
      omega17m = +0.314011756565316 / +1.04145761412373 / (1.0e-6 + sigma1) / (1.0e-6 + sigma1);
      accumulator += omega17m;
      omega18m = +0.0263809198091549 / +1.04145761412373 / (1.0e-6 + sigma2) / (1.0e-6 + sigma2);
      accumulator += omega18m;
      omega19m = +0.339723480439741 / +1.04145761412373 / (1.0e-6 + sigma3) / (1.0e-6 + sigma3);
      accumulator += omega19m;
      omega20m = +0.266828347409677 / +1.04145761412373 / (1.0e-6 + sigma4) / (1.0e-6 + sigma4);
      accumulator += omega20m;
      omega21m = +0.0839475970770557 / +1.04145761412373 / (1.0e-6 + sigma5) / (1.0e-6 + sigma5);
      accumulator += omega21m;
      omega22m = +0.00908855742883744 / +1.04145761412373 / (1.0e-6 + sigma6) / (1.0e-6 + sigma6);
      accumulator += omega22m;
      omega23m = +0.00021946578728326 / +1.04145761412373 / (1.0e-6 + sigma7) / (1.0e-6 + sigma7);
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
      omega24p = +0.000438931574428836 / +2.04145761412418 / (1.0e-6 + sigma0) / (1.0e-6 + sigma0);
      accumulator += omega24p;
      omega25p = +0.0181771148580013 / +2.04145761412418 / (1.0e-6 + sigma1) / (1.0e-6 + sigma1);
      accumulator += omega25p;
      omega26p = +0.167895194153764 / +2.04145761412418 / (1.0e-6 + sigma2) / (1.0e-6 + sigma2);
      accumulator += omega26p;
      omega27p = +0.533656694819528 / +2.04145761412418 / (1.0e-6 + sigma3) / (1.0e-6 + sigma3);
      accumulator += omega27p;
      omega28p = +0.679446960879477 / +2.04145761412418 / (1.0e-6 + sigma4) / (1.0e-6 + sigma4);
      accumulator += omega28p;
      omega29p = +0.0131904599047336 / +2.04145761412418 / (1.0e-6 + sigma5) / (1.0e-6 + sigma5);
      accumulator += omega29p;
      omega30p = +0.628023513130919 / +2.04145761412418 / (1.0e-6 + sigma6) / (1.0e-6 + sigma6);
      accumulator += omega30p;
      omega31p = +0.000628744803333502 / +2.04145761412418 / (1.0e-6 + sigma7) / (1.0e-6 + sigma7);
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
      omega24m = +0.000219465787214418 / +1.04145761412419 / (1.0e-6 + sigma0) / (1.0e-6 + sigma0);
      accumulator += omega24m;
      omega25m = +0.00908855742900066 / +1.04145761412419 / (1.0e-6 + sigma1) / (1.0e-6 + sigma1);
      accumulator += omega25m;
      omega26m = +0.083947597076882 / +1.04145761412419 / (1.0e-6 + sigma2) / (1.0e-6 + sigma2);
      accumulator += omega26m;
      omega27m = +0.266828347409764 / +1.04145761412419 / (1.0e-6 + sigma3) / (1.0e-6 + sigma3);
      accumulator += omega27m;
      omega28m = +0.339723480439738 / +1.04145761412419 / (1.0e-6 + sigma4) / (1.0e-6 + sigma4);
      accumulator += omega28m;
      omega29m = +0.0263809198094672 / +1.04145761412419 / (1.0e-6 + sigma5) / (1.0e-6 + sigma5);
      accumulator += omega29m;
      omega30m = +0.314011756565459 / +1.04145761412419 / (1.0e-6 + sigma6) / (1.0e-6 + sigma6);
      accumulator += omega30m;
      omega31m = +0.001257489606667 / +1.04145761412419 / (1.0e-6 + sigma7) / (1.0e-6 + sigma7);
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
      omega32 = +0.000680635135481405 / (1.0e-6 + sigma0) / (1.0e-6 + sigma0);
      accumulator += omega32;
      omega33 = +0.0206657997963102 / (1.0e-6 + sigma1) / (1.0e-6 + sigma1);
      accumulator += omega33;
      omega34 = +0.1469673301473 / (1.0e-6 + sigma2) / (1.0e-6 + sigma2);
      accumulator += omega34;
      omega35 = +0.358151719736487 / (1.0e-6 + sigma3) / (1.0e-6 + sigma3);
      accumulator += omega35;
      omega36 = +0.336682046705118 / (1.0e-6 + sigma4) / (1.0e-6 + sigma4);
      accumulator += omega36;
      omega37 = +0.121581389427414 / (1.0e-6 + sigma5) / (1.0e-6 + sigma5);
      accumulator += omega37;
      omega38 = +0.0148491683891303 / (1.0e-6 + sigma6) / (1.0e-6 + sigma6);
      accumulator += omega38;
      omega39 = +0.00042191066274908 / (1.0e-6 + sigma7) / (1.0e-6 + sigma7);
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
      omega40 = +0.00110707710154956 / (1.0e-6 + sigma0) / (1.0e-6 + sigma0);
      accumulator += omega40;
      omega41 = +0.0283147432083475 / (1.0e-6 + sigma1) / (1.0e-6 + sigma1);
      accumulator += omega41;
      omega42 = +0.175689584054732 / (1.0e-6 + sigma2) / (1.0e-6 + sigma2);
      accumulator += omega42;
      omega43 = +0.377303221585195 / (1.0e-6 + sigma3) / (1.0e-6 + sigma3);
      accumulator += omega43;
      omega44 = +0.31119328459606 / (1.0e-6 + sigma4) / (1.0e-6 + sigma4);
      accumulator += omega44;
      omega45 = +0.0965932796956124 / (1.0e-6 + sigma5) / (1.0e-6 + sigma5);
      accumulator += omega45;
      omega46 = +0.00961335477355098 / (1.0e-6 + sigma6) / (1.0e-6 + sigma6);
      accumulator += omega46;
      omega47 = +0.000185454984934621 / (1.0e-6 + sigma7) / (1.0e-6 + sigma7);
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
	+2.52563817628959 * f[(i + 0) * fsi] - 4.5788999437186 * f[(i + 1) * fsi] +
	7.40984341808246 * f[(i + 2) * fsi] - 8.38454177954476 * f[(i + 3) * fsi] +
	6.33450485951138 * f[(i + 4) * fsi] - 3.05205394953413 * f[(i + 5) * fsi] +
	0.849710533686945 * f[(i + 6) * fsi] - 0.104201314772875 * f[(i + 7) * fsi];
      f1 =
	+0.104201314772875 * f[(i - 1) * fsi] + 1.69202765810659 * f[(i + 0) * fsi] -
	1.6612631300781 * f[(i + 1) * fsi] + 1.57456979080146 * f[(i + 2) * fsi] -
	1.09044974544352 * f[(i + 3) * fsi] + 0.499231232230386 * f[(i + 4) * fsi] -
	0.134417135893639 * f[(i + 5) * fsi] + 0.0161000155039462 * f[(i + 6) * fsi];
      f2 =
	-0.0161000155039462 * f[(i - 2) * fsi] + 0.233001438804445 * f[(i - 1) * fsi] +
	1.24122722399609 * f[(i + 0) * fsi] - 0.759662261857111 * f[(i + 1) * fsi] +
	0.447568705525228 * f[(i + 2) * fsi] - 0.188848877222529 * f[(i + 3) * fsi] +
	0.0484307981198911 * f[(i + 4) * fsi] - 0.00561701186206878 * f[(i + 5) * fsi];
      f3 =
	+0.00561701186206878 * f[(i - 3) * fsi] - 0.0610361104004964 * f[(i - 2) * fsi] +
	0.39027777094237 * f[(i - 1) * fsi] + 0.926674559720241 * f[(i + 0) * fsi] -
	0.366471431512297 * f[(i + 1) * fsi] + 0.133016041249376 * f[(i + 2) * fsi] -
	0.0315725450846037 * f[(i + 3) * fsi] + 0.00349470322334087 * f[(i + 4) * fsi];
      f4 =
	-0.00349470322334087 * f[(i - 4) * fsi] + 0.0335746376487957 * f[(i - 3) * fsi] -
	0.158887800654041 * f[(i - 2) * fsi] + 0.585981151449459 * f[(i - 1) * fsi] +
	0.68204533408638 * f[(i + 0) * fsi] - 0.170768051005208 * f[(i + 1) * fsi] +
	0.0351643509958318 * f[(i + 2) * fsi] - 0.00361491929787672 * f[(i + 3) * fsi];
      f5 =
	+0.00361491929787672 * f[(i - 5) * fsi] - 0.0324140576063546 * f[(i - 4) * fsi] +
	0.134792377989344 * f[(i - 3) * fsi] - 0.361323281335137 * f[(i - 2) * fsi] +
	0.839025502300829 * f[(i - 1) * fsi] + 0.479609853405284 * f[(i + 0) * fsi] -
	0.0695503106646602 * f[(i + 1) * fsi] + 0.00624499661281811 * f[(i + 2) * fsi];
      f6 =
	-0.00624499661281811 * f[(i - 6) * fsi] + 0.0535748922004216 * f[(i - 5) * fsi] -
	0.207273962765262 * f[(i - 4) * fsi] + 0.484512188307158 * f[(i - 3) * fsi] -
	0.798473044232405 * f[(i - 2) * fsi] + 1.18874531261864 * f[(i - 1) * fsi] +
	0.304749948246377 * f[(i + 0) * fsi] - 0.0195903377621154 * f[(i + 1) * fsi];
      f7 =
	+0.0195903377621154 * f[(i - 7) * fsi] - 0.162967698709741 * f[(i - 6) * fsi] +
	0.602104349539652 * f[(i - 5) * fsi] - 1.30433287744372 * f[(i - 4) * fsi] +
	1.85583583165523 * f[(i - 3) * fsi] - 1.89553195891086 * f[(i - 2) * fsi] +
	1.73727476995787 * f[(i - 1) * fsi] + 0.148027246149454 * f[(i + 0) * fsi];
      f8 =
	+1.85859476677663 * f[(i + 0) * fsi] - 2.25212282022974 * f[(i + 1) * fsi] +
	3.22626913202171 * f[(i + 2) * fsi] - 3.46128531207034 * f[(i + 3) * fsi] +
	2.54001887139623 * f[(i + 4) * fsi] - 1.20177028990421 * f[(i + 5) * fsi] +
	0.330457800967733 * f[(i + 6) * fsi] - 0.0401621489580098 * f[(i + 7) * fsi];
      f9 =
	+0.0401621489580098 * f[(i - 1) * fsi] + 1.53729757511255 * f[(i + 0) * fsi] -
	1.12758264940547 * f[(i + 1) * fsi] + 0.97718879037316 * f[(i + 2) * fsi] -
	0.649934885009656 * f[(i + 3) * fsi] + 0.290938529747682 * f[(i + 4) * fsi] -
	0.0772301190799322 * f[(i + 5) * fsi] + 0.00916060930365429 * f[(i + 6) * fsi];
      f10 =
	-0.00916060930365429 * f[(i - 2) * fsi] + 0.113447023387244 * f[(i - 1) * fsi] +
	1.28080051461023 * f[(i + 0) * fsi] - 0.614588528400827 * f[(i + 1) * fsi] +
	0.33594613911736 * f[(i + 2) * fsi] - 0.136940764005016 * f[(i + 3) * fsi] +
	0.0344414692453619 * f[(i + 4) * fsi] - 0.00394524465069781 * f[(i + 5) * fsi];
      f11 =
	+0.00394524465069781 * f[(i - 3) * fsi] - 0.0407225665092368 * f[(i - 2) * fsi] +
	0.223913873606783 * f[(i - 1) * fsi] + 1.05986681417115 * f[(i + 0) * fsi] -
	0.33842140285198 * f[(i + 1) * fsi] + 0.115012438678282 * f[(i + 2) * fsi] -
	0.0264739137854772 * f[(i + 3) * fsi] + 0.00287951203977936 * f[(i + 4) * fsi];
      f12 =
	-0.00287951203977936 * f[(i - 4) * fsi] + 0.0269813409689327 * f[(i - 3) * fsi] -
	0.121348903623059 * f[(i - 2) * fsi] + 0.385166547834427 * f[(i - 1) * fsi] +
	0.858300971386596 * f[(i + 0) * fsi] - 0.177168728624336 * f[(i + 1) * fsi] +
	0.0343861015644603 * f[(i + 2) * fsi] - 0.00343781746724234 * f[(i + 3) * fsi];
      f13 =
	+0.00343781746724234 * f[(i - 5) * fsi] - 0.0303820517777181 * f[(i - 4) * fsi] +
	0.123240230051718 * f[(i - 3) * fsi] - 0.31386668178863 * f[(i - 2) * fsi] +
	0.625813770541391 * f[(i - 1) * fsi] + 0.665783193221025 * f[(i + 0) * fsi] -
	0.0809098395415501 * f[(i + 1) * fsi] + 0.00688356182652149 * f[(i + 2) * fsi];
      f14 =
	-0.00688356182652149 * f[(i - 6) * fsi] + 0.0585063120794143 * f[(i - 5) * fsi] -
	0.22312178292032 * f[(i - 4) * fsi] + 0.508719692336922 * f[(i - 3) * fsi] -
	0.795716009645135 * f[(i - 2) * fsi] + 1.01129323282659 * f[(i - 1) * fsi] +
	0.473043462078423 * f[(i + 0) * fsi] - 0.0258413449293782 * f[(i + 1) * fsi];
      f15 =
	+0.0258413449293782 * f[(i - 7) * fsi] - 0.213614321261547 * f[(i - 6) * fsi] +
	0.782063970102004 * f[(i - 5) * fsi] - 1.6702370989655 * f[(i - 4) * fsi] +
	2.31761383739339 * f[(i - 3) * fsi] - 2.24283132569031 * f[(i - 2) * fsi] +
	1.73485089084918 * f[(i - 1) * fsi] + 0.266312702643398 * f[(i + 0) * fsi];
      f16 =
	+1.10111157271227 * f[(i + 0) * fsi] + 0.0773342197224052 * f[(i + 1) * fsi] -
	0.578444129784995 * f[(i + 2) * fsi] + 0.824731136614527 * f[(i + 3) * fsi] -
	0.684368783863828 * f[(i + 4) * fsi] + 0.346767584560185 * f[(i + 5) * fsi] -
	0.0996094493407192 * f[(i + 6) * fsi] + 0.012477849380159 * f[(i + 7) * fsi];
      f17 =
	-0.0124778493801589 * f[(i - 1) * fsi] + 1.20093436775354 * f[(i + 0) * fsi] -
	0.272045562922046 * f[(i + 1) * fsi] + 0.120315435503907 * f[(i + 2) * fsi] -
	0.0487183199966 * f[(i + 3) * fsi] + 0.0143907814250735 * f[(i + 4) * fsi] -
	0.00261219808426621 * f[(i + 5) * fsi] + 0.000213345700552188 * f[(i + 6) * fsi];
      f18 =
	-0.000213345700552187 * f[(i - 2) * fsi] - 0.0107710837757415 * f[(i - 1) * fsi] +
	1.19496068813808 * f[(i + 0) * fsi] - 0.260098203691123 * f[(i + 1) * fsi] +
	0.105381236465253 * f[(i + 2) * fsi] - 0.0367709607656774 * f[(i + 3) * fsi] +
	0.00841710180961203 * f[(i + 4) * fsi] - 0.000905432479848689 * f[(i + 5) * fsi];
      f19 =
	+0.000905432479848689 * f[(i - 3) * fsi] - 0.0074568055393417 * f[(i - 2) * fsi] +
	0.014581025660022 * f[(i - 1) * fsi] + 1.14425646926655 * f[(i + 0) * fsi] -
	0.196717930101715 * f[(i + 1) * fsi] + 0.0546770175937267 * f[(i + 2) * fsi] -
	0.0114188513299141 * f[(i + 3) * fsi] + 0.00117364197082252 * f[(i + 4) * fsi];
      f20 =
	-0.00117364197082252 * f[(i - 4) * fsi] + 0.0102945682464288 * f[(i - 3) * fsi] -
	0.0403187807223722 * f[(i - 2) * fsi] + 0.0803049760260828 * f[(i - 1) * fsi] +
	1.06210153130897 * f[(i + 0) * fsi] - 0.130993979735654 * f[(i + 1) * fsi] +
	0.0218150424106962 * f[(i + 2) * fsi] - 0.00202971556333393 * f[(i + 3) * fsi];
      f21 =
	+0.00202971556333393 * f[(i - 5) * fsi] - 0.017411366477494 * f[(i - 4) * fsi] +
	0.0671266040197789 * f[(i - 3) * fsi] - 0.153982852269072 * f[(i - 2) * fsi] +
	0.222385065459458 * f[(i - 1) * fsi] + 0.948437459762275 * f[(i + 0) * fsi] -
	0.074161943962304 * f[(i + 1) * fsi] + 0.00557731790402473 * f[(i + 2) * fsi];
      f22 =
	-0.00557731790402473 * f[(i - 6) * fsi] + 0.0466482587955318 * f[(i - 5) * fsi] -
	0.173576267790186 * f[(i - 4) * fsi] + 0.379456406645164 * f[(i - 3) * fsi] -
	0.544395105550804 * f[(i - 2) * fsi] + 0.534714868084843 * f[(i - 1) * fsi] +
	0.792272558449582 * f[(i + 0) * fsi] - 0.0295434007301062 * f[(i + 1) * fsi];
      f23 =
	+0.0295434007301062 * f[(i - 7) * fsi] - 0.241924523744874 * f[(i - 6) * fsi] +
	0.873863479238505 * f[(i - 5) * fsi] - 1.82800670867613 * f[(i - 4) * fsi] +
	2.4474944577526 * f[(i - 3) * fsi] - 2.19882554643675 * f[(i - 2) * fsi] +
	1.36193008852782 * f[(i - 1) * fsi] + 0.555925352608733 * f[(i + 0) * fsi];
      f24 =
	+0.555925352608733 * f[(i + 0) * fsi] + 1.36193008852782 * f[(i + 1) * fsi] -
	2.19882554643675 * f[(i + 2) * fsi] + 2.4474944577526 * f[(i + 3) * fsi] -
	1.82800670867613 * f[(i + 4) * fsi] + 0.873863479238504 * f[(i + 5) * fsi] -
	0.241924523744874 * f[(i + 6) * fsi] + 0.0295434007301062 * f[(i + 7) * fsi];
      f25 =
	-0.0295434007301062 * f[(i - 1) * fsi] + 0.792272558449582 * f[(i + 0) * fsi] +
	0.534714868084843 * f[(i + 1) * fsi] - 0.544395105550804 * f[(i + 2) * fsi] +
	0.379456406645164 * f[(i + 3) * fsi] - 0.173576267790186 * f[(i + 4) * fsi] +
	0.0466482587955318 * f[(i + 5) * fsi] - 0.00557731790402474 * f[(i + 6) * fsi];
      f26 =
	+0.00557731790402474 * f[(i - 2) * fsi] - 0.0741619439623041 * f[(i - 1) * fsi] +
	0.948437459762275 * f[(i + 0) * fsi] + 0.222385065459458 * f[(i + 1) * fsi] -
	0.153982852269072 * f[(i + 2) * fsi] + 0.0671266040197789 * f[(i + 3) * fsi] -
	0.017411366477494 * f[(i + 4) * fsi] + 0.00202971556333393 * f[(i + 5) * fsi];
      f27 =
	-0.00202971556333393 * f[(i - 3) * fsi] + 0.0218150424106962 * f[(i - 2) * fsi] -
	0.130993979735654 * f[(i - 1) * fsi] + 1.06210153130897 * f[(i + 0) * fsi] +
	0.080304976026083 * f[(i + 1) * fsi] - 0.0403187807223722 * f[(i + 2) * fsi] +
	0.0102945682464288 * f[(i + 3) * fsi] - 0.00117364197082252 * f[(i + 4) * fsi];
      f28 =
	+0.00117364197082252 * f[(i - 4) * fsi] - 0.0114188513299141 * f[(i - 3) * fsi] +
	0.0546770175937267 * f[(i - 2) * fsi] - 0.196717930101715 * f[(i - 1) * fsi] +
	1.14425646926655 * f[(i + 0) * fsi] + 0.0145810256600219 * f[(i + 1) * fsi] -
	0.00745680553934171 * f[(i + 2) * fsi] + 0.000905432479848691 * f[(i + 3) * fsi];
      f29 =
	-0.000905432479848691 * f[(i - 5) * fsi] + 0.00841710180961205 * f[(i - 4) * fsi] -
	0.0367709607656774 * f[(i - 3) * fsi] + 0.105381236465253 * f[(i - 2) * fsi] -
	0.260098203691123 * f[(i - 1) * fsi] + 1.19496068813808 * f[(i + 0) * fsi] -
	0.0107710837757414 * f[(i + 1) * fsi] - 0.000213345700552192 * f[(i + 2) * fsi];
      f30 =
	+0.000213345700552192 * f[(i - 6) * fsi] - 0.00261219808426622 * f[(i - 5) * fsi] +
	0.0143907814250734 * f[(i - 4) * fsi] - 0.0487183199966001 * f[(i - 3) * fsi] +
	0.120315435503907 * f[(i - 2) * fsi] - 0.272045562922046 * f[(i - 1) * fsi] +
	1.20093436775354 * f[(i + 0) * fsi] - 0.0124778493801589 * f[(i + 1) * fsi];
      f31 =
	+0.0124778493801589 * f[(i - 7) * fsi] - 0.0996094493407192 * f[(i - 6) * fsi] +
	0.346767584560184 * f[(i - 5) * fsi] - 0.684368783863827 * f[(i - 4) * fsi] +
	0.824731136614524 * f[(i - 3) * fsi] - 0.578444129784993 * f[(i - 2) * fsi] +
	0.0773342197224034 * f[(i - 1) * fsi] + 1.10111157271227 * f[(i + 0) * fsi];
      f32 =
	+0.266312702643397 * f[(i + 0) * fsi] + 1.73485089084918 * f[(i + 1) * fsi] -
	2.2428313256903 * f[(i + 2) * fsi] + 2.3176138373934 * f[(i + 3) * fsi] -
	1.67023709896549 * f[(i + 4) * fsi] + 0.782063970102002 * f[(i + 5) * fsi] -
	0.213614321261547 * f[(i + 6) * fsi] + 0.0258413449293781 * f[(i + 7) * fsi];
      f33 =
	-0.0258413449293782 * f[(i - 1) * fsi] + 0.473043462078423 * f[(i + 0) * fsi] +
	1.01129323282659 * f[(i + 1) * fsi] - 0.795716009645134 * f[(i + 2) * fsi] +
	0.508719692336922 * f[(i + 3) * fsi] - 0.22312178292032 * f[(i + 4) * fsi] +
	0.0585063120794143 * f[(i + 5) * fsi] - 0.00688356182652149 * f[(i + 6) * fsi];
      f34 =
	+0.00688356182652149 * f[(i - 2) * fsi] - 0.0809098395415501 * f[(i - 1) * fsi] +
	0.665783193221025 * f[(i + 0) * fsi] + 0.625813770541391 * f[(i + 1) * fsi] -
	0.31386668178863 * f[(i + 2) * fsi] + 0.123240230051718 * f[(i + 3) * fsi] -
	0.0303820517777181 * f[(i + 4) * fsi] + 0.00343781746724235 * f[(i + 5) * fsi];
      f35 =
	-0.00343781746724235 * f[(i - 3) * fsi] + 0.0343861015644603 * f[(i - 2) * fsi] -
	0.177168728624336 * f[(i - 1) * fsi] + 0.858300971386596 * f[(i + 0) * fsi] +
	0.385166547834427 * f[(i + 1) * fsi] - 0.121348903623059 * f[(i + 2) * fsi] +
	0.0269813409689327 * f[(i + 3) * fsi] - 0.00287951203977936 * f[(i + 4) * fsi];
      f36 =
	+0.00287951203977936 * f[(i - 4) * fsi] - 0.0264739137854772 * f[(i - 3) * fsi] +
	0.115012438678282 * f[(i - 2) * fsi] - 0.33842140285198 * f[(i - 1) * fsi] +
	1.05986681417115 * f[(i + 0) * fsi] + 0.223913873606783 * f[(i + 1) * fsi] -
	0.0407225665092368 * f[(i + 2) * fsi] + 0.00394524465069781 * f[(i + 3) * fsi];
      f37 =
	-0.00394524465069781 * f[(i - 5) * fsi] + 0.0344414692453619 * f[(i - 4) * fsi] -
	0.136940764005016 * f[(i - 3) * fsi] + 0.33594613911736 * f[(i - 2) * fsi] -
	0.614588528400827 * f[(i - 1) * fsi] + 1.28080051461023 * f[(i + 0) * fsi] +
	0.113447023387244 * f[(i + 1) * fsi] - 0.00916060930365429 * f[(i + 2) * fsi];
      f38 =
	+0.00916060930365429 * f[(i - 6) * fsi] - 0.0772301190799321 * f[(i - 5) * fsi] +
	0.290938529747682 * f[(i - 4) * fsi] - 0.649934885009656 * f[(i - 3) * fsi] +
	0.97718879037316 * f[(i - 2) * fsi] - 1.12758264940547 * f[(i - 1) * fsi] +
	1.53729757511255 * f[(i + 0) * fsi] + 0.0401621489580098 * f[(i + 1) * fsi];
      f39 =
	-0.0401621489580098 * f[(i - 7) * fsi] + 0.330457800967733 * f[(i - 6) * fsi] -
	1.20177028990421 * f[(i - 5) * fsi] + 2.54001887139623 * f[(i - 4) * fsi] -
	3.46128531207034 * f[(i - 3) * fsi] + 3.22626913202171 * f[(i - 2) * fsi] -
	2.25212282022974 * f[(i - 1) * fsi] + 1.85859476677663 * f[(i + 0) * fsi];
      f40 =
	+0.148027246149454 * f[(i + 0) * fsi] + 1.73727476995788 * f[(i + 1) * fsi] -
	1.89553195891086 * f[(i + 2) * fsi] + 1.85583583165523 * f[(i + 3) * fsi] -
	1.30433287744372 * f[(i + 4) * fsi] + 0.60210434953965 * f[(i + 5) * fsi] -
	0.162967698709741 * f[(i + 6) * fsi] + 0.0195903377621154 * f[(i + 7) * fsi];
      f41 =
	-0.0195903377621155 * f[(i - 1) * fsi] + 0.304749948246376 * f[(i + 0) * fsi] +
	1.18874531261864 * f[(i + 1) * fsi] - 0.798473044232405 * f[(i + 2) * fsi] +
	0.484512188307158 * f[(i + 3) * fsi] - 0.207273962765261 * f[(i + 4) * fsi] +
	0.0535748922004217 * f[(i + 5) * fsi] - 0.00624499661281813 * f[(i + 6) * fsi];
      f42 =
	+0.00624499661281812 * f[(i - 2) * fsi] - 0.0695503106646602 * f[(i - 1) * fsi] +
	0.479609853405284 * f[(i + 0) * fsi] + 0.839025502300829 * f[(i + 1) * fsi] -
	0.361323281335137 * f[(i + 2) * fsi] + 0.134792377989344 * f[(i + 3) * fsi] -
	0.0324140576063546 * f[(i + 4) * fsi] + 0.00361491929787672 * f[(i + 5) * fsi];
      f43 =
	-0.00361491929787672 * f[(i - 3) * fsi] + 0.0351643509958319 * f[(i - 2) * fsi] -
	0.170768051005208 * f[(i - 1) * fsi] + 0.68204533408638 * f[(i + 0) * fsi] +
	0.585981151449459 * f[(i + 1) * fsi] - 0.158887800654041 * f[(i + 2) * fsi] +
	0.0335746376487957 * f[(i + 3) * fsi] - 0.00349470322334087 * f[(i + 4) * fsi];
      f44 =
	+0.00349470322334087 * f[(i - 4) * fsi] - 0.0315725450846036 * f[(i - 3) * fsi] +
	0.133016041249376 * f[(i - 2) * fsi] - 0.366471431512297 * f[(i - 1) * fsi] +
	0.926674559720241 * f[(i + 0) * fsi] + 0.39027777094237 * f[(i + 1) * fsi] -
	0.0610361104004964 * f[(i + 2) * fsi] + 0.00561701186206878 * f[(i + 3) * fsi];
      f45 =
	-0.00561701186206878 * f[(i - 5) * fsi] + 0.0484307981198911 * f[(i - 4) * fsi] -
	0.188848877222529 * f[(i - 3) * fsi] + 0.447568705525228 * f[(i - 2) * fsi] -
	0.759662261857111 * f[(i - 1) * fsi] + 1.24122722399609 * f[(i + 0) * fsi] +
	0.233001438804445 * f[(i + 1) * fsi] - 0.0161000155039462 * f[(i + 2) * fsi];
      f46 =
	+0.0161000155039462 * f[(i - 6) * fsi] - 0.134417135893639 * f[(i - 5) * fsi] +
	0.499231232230386 * f[(i - 4) * fsi] - 1.09044974544352 * f[(i - 3) * fsi] +
	1.57456979080146 * f[(i - 2) * fsi] - 1.6612631300781 * f[(i - 1) * fsi] +
	1.69202765810659 * f[(i + 0) * fsi] + 0.104201314772875 * f[(i + 1) * fsi];
      f47 =
	-0.104201314772875 * f[(i - 7) * fsi] + 0.849710533686945 * f[(i - 6) * fsi] -
	3.05205394953413 * f[(i - 5) * fsi] + 6.33450485951137 * f[(i - 4) * fsi] -
	8.38454177954476 * f[(i - 3) * fsi] + 7.40984341808246 * f[(i - 2) * fsi] -
	4.5788999437186 * f[(i - 1) * fsi] + 2.52563817628959 * f[(i + 0) * fsi];
      fr0 =
	f0 * omega0 + f1 * omega1 + f2 * omega2 + f3 * omega3 + f4 * omega4 + f5 * omega5 +
	f6 * omega6 + f7 * omega7;
      fr1 =
	f8 * omega8 + f9 * omega9 + f10 * omega10 + f11 * omega11 + f12 * omega12 + f13 * omega13 +
	f14 * omega14 + f15 * omega15;
      fr2 =
	+2.04145761412373 * (f16 * omega16p + f17 * omega17p + f18 * omega18p + f19 * omega19p +
			     f20 * omega20p + f21 * omega21p + f22 * omega22p + f23 * omega23p) -
	+1.04145761412373 * (f16 * omega16m + f17 * omega17m + f18 * omega18m + f19 * omega19m +
			     f20 * omega20m + f21 * omega21m + f22 * omega22m + f23 * omega23m);
      fr3 =
	+2.04145761412418 * (f24 * omega24p + f25 * omega25p + f26 * omega26p + f27 * omega27p +
			     f28 * omega28p + f29 * omega29p + f30 * omega30p + f31 * omega31p) -
	+1.04145761412419 * (f24 * omega24m + f25 * omega25m + f26 * omega26m + f27 * omega27m +
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
py_gauss_legendre008006 (PyObject * self, PyObject * args)
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

  gauss_legendre008006 (f, n, fsi, sigma, ssi, ssr, fr, frsi, frsl);

  Py_INCREF (Py_None);
  return Py_None;
}
