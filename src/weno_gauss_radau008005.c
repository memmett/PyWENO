#include <Python.h>
#include <numpy/ndarrayobject.h>

void
gauss_radau008005 (const double *restrict f, int n, int fsi,
		   const double *restrict sigma, int ssi, int ssr,
		   double *restrict fr, int frsi, int frsl)
{
  int i;
  double sigma0, sigma1, sigma2, sigma3, sigma4, sigma5, sigma6, sigma7, omega23m, omega39, omega11,
    omega24, omega7, omega14, omega19p, omega31, omega3, omega18p, omega19m, omega32, omega10,
    omega20p, omega25, omega27, omega36, omega13, omega16m, omega4, omega37, omega33, omega16p,
    omega26, omega0, omega30, omega21p, omega22m, omega12, omega21m, omega22p, omega5, omega20m,
    omega34, omega8, omega29, omega1, omega17p, omega38, omega18m, omega17m, omega9, omega6,
    omega35, omega15, omega23p, omega28, omega2, accumulator, f39, f11, f24, f7, f22, f14, f31, f21,
    f3, f32, f10, f27, f16, f36, f13, f30, f18, f33, f9, f23, f26, f0, f37, f4, f12, f19, f17, f34,
    f8, f29, f1, f38, f25, f2, f6, f35, f15, f5, f28, f20, fr0, fr1, fr2, fr3, fr4;
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
      omega8 = +0.000342553026518552 / (1.0e-6 + sigma0) / (1.0e-6 + sigma0);
      accumulator += omega8;
      omega9 = +0.013386099919757 / (1.0e-6 + sigma1) / (1.0e-6 + sigma1);
      accumulator += omega9;
      omega10 = +0.115346506233777 / (1.0e-6 + sigma2) / (1.0e-6 + sigma2);
      accumulator += omega10;
      omega11 = +0.331225844075017 / (1.0e-6 + sigma3) / (1.0e-6 + sigma3);
      accumulator += omega11;
      omega12 = +0.363264332730434 / (1.0e-6 + sigma4) / (1.0e-6 + sigma4);
      accumulator += omega12;
      omega13 = +0.153428783399777 / (1.0e-6 + sigma5) / (1.0e-6 + sigma5);
      accumulator += omega13;
      omega14 = +0.0222448065363015 / (1.0e-6 + sigma6) / (1.0e-6 + sigma6);
      accumulator += omega14;
      omega15 = +0.000761074078418359 / (1.0e-6 + sigma7) / (1.0e-6 + sigma7);
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
      omega16p = +0.000338409144269175 / +2.15702909768515 / (1.0e-6 + sigma0) / (1.0e-6 + sigma0);
      accumulator += omega16p;
      omega17p = +0.0520046234174499 / +2.15702909768515 / (1.0e-6 + sigma1) / (1.0e-6 + sigma1);
      accumulator += omega17p;
      omega18p = +1.14000238931619 / +2.15702909768515 / (1.0e-6 + sigma2) / (1.0e-6 + sigma2);
      accumulator += omega18p;
      omega19p = +0.410034340705271 / +2.15702909768515 / (1.0e-6 + sigma3) / (1.0e-6 + sigma3);
      accumulator += omega19p;
      omega20p = +0.41464288858203 / +2.15702909768515 / (1.0e-6 + sigma4) / (1.0e-6 + sigma4);
      accumulator += omega20p;
      omega21p = +0.126614503900561 / +2.15702909768515 / (1.0e-6 + sigma5) / (1.0e-6 + sigma5);
      accumulator += omega21p;
      omega22p = +0.0130936127356878 / +2.15702909768515 / (1.0e-6 + sigma6) / (1.0e-6 + sigma6);
      accumulator += omega22p;
      omega23p = +0.000298329883695929 / +2.15702909768515 / (1.0e-6 + sigma7) / (1.0e-6 + sigma7);
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
      omega16m = +0.000676818288538349 / +1.15702909768516 / (1.0e-6 + sigma0) / (1.0e-6 + sigma0);
      accumulator += omega16m;
      omega17m = +0.1040092468349 / +1.15702909768516 / (1.0e-6 + sigma1) / (1.0e-6 + sigma1);
      accumulator += omega17m;
      omega18m = +0.570001194658095 / +1.15702909768516 / (1.0e-6 + sigma2) / (1.0e-6 + sigma2);
      accumulator += omega18m;
      omega19m = +0.205017170352635 / +1.15702909768516 / (1.0e-6 + sigma3) / (1.0e-6 + sigma3);
      accumulator += omega19m;
      omega20m = +0.207321444291015 / +1.15702909768516 / (1.0e-6 + sigma4) / (1.0e-6 + sigma4);
      accumulator += omega20m;
      omega21m = +0.0633072519502805 / +1.15702909768516 / (1.0e-6 + sigma5) / (1.0e-6 + sigma5);
      accumulator += omega21m;
      omega22m = +0.0065468063678439 / +1.15702909768516 / (1.0e-6 + sigma6) / (1.0e-6 + sigma6);
      accumulator += omega22m;
      omega23m = +0.000149164941847965 / +1.15702909768516 / (1.0e-6 + sigma7) / (1.0e-6 + sigma7);
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
      omega24 = +0.000428382571583039 / (1.0e-6 + sigma0) / (1.0e-6 + sigma0);
      accumulator += omega24;
      omega25 = +0.0150619323552484 / (1.0e-6 + sigma1) / (1.0e-6 + sigma1);
      accumulator += omega25;
      omega26 = +0.120830987920844 / (1.0e-6 + sigma2) / (1.0e-6 + sigma2);
      accumulator += omega26;
      omega27 = +0.331264587429644 / (1.0e-6 + sigma3) / (1.0e-6 + sigma3);
      accumulator += omega27;
      omega28 = +0.355016199455826 / (1.0e-6 + sigma4) / (1.0e-6 + sigma4);
      accumulator += omega28;
      omega29 = +0.151654268350307 / (1.0e-6 + sigma5) / (1.0e-6 + sigma5);
      accumulator += omega29;
      omega30 = +0.024017137783767 / (1.0e-6 + sigma6) / (1.0e-6 + sigma6);
      accumulator += omega30;
      omega31 = +0.00172650413278827 / (1.0e-6 + sigma7) / (1.0e-6 + sigma7);
      accumulator += omega31;
      omega24 /= accumulator;
      omega25 /= accumulator;
      omega26 /= accumulator;
      omega27 /= accumulator;
      omega28 /= accumulator;
      omega29 /= accumulator;
      omega30 /= accumulator;
      omega31 /= accumulator;
      accumulator = 0.0;
      omega32 = +0.00102142874422297 / (1.0e-6 + sigma0) / (1.0e-6 + sigma0);
      accumulator += omega32;
      omega33 = +0.0269030661940048 / (1.0e-6 + sigma1) / (1.0e-6 + sigma1);
      accumulator += omega33;
      omega34 = +0.170830635265074 / (1.0e-6 + sigma2) / (1.0e-6 + sigma2);
      accumulator += omega34;
      omega35 = +0.374671816247603 / (1.0e-6 + sigma3) / (1.0e-6 + sigma3);
      accumulator += omega35;
      omega36 = +0.315684519240329 / (1.0e-6 + sigma4) / (1.0e-6 + sigma4);
      accumulator += omega36;
      omega37 = +0.100370799830257 / (1.0e-6 + sigma5) / (1.0e-6 + sigma5);
      accumulator += omega37;
      omega38 = +0.0103075335511012 / (1.0e-6 + sigma6) / (1.0e-6 + sigma6);
      accumulator += omega38;
      omega39 = +0.000210200927404103 / (1.0e-6 + sigma7) / (1.0e-6 + sigma7);
      accumulator += omega39;
      omega32 /= accumulator;
      omega33 /= accumulator;
      omega34 /= accumulator;
      omega35 /= accumulator;
      omega36 /= accumulator;
      omega37 /= accumulator;
      omega38 /= accumulator;
      omega39 /= accumulator;
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
	+1.99087539968267 * f[(i + 0) * fsi] - 2.69737853708759 * f[(i + 1) * fsi] +
	4.00592503723584 * f[(i + 2) * fsi] - 4.36732833771565 * f[(i + 3) * fsi] +
	3.23337758209812 * f[(i + 4) * fsi] - 1.53833773661356 * f[(i + 5) * fsi] +
	0.424614452019206 * f[(i + 6) * fsi] - 0.051747859619042 * f[(i + 7) * fsi];
      f9 =
	+0.051747859619042 * f[(i - 1) * fsi] + 1.57689252273033 * f[(i + 0) * fsi] -
	1.24843846775441 * f[(i + 1) * fsi] + 1.10804489856949 * f[(i + 2) * fsi] -
	0.744978164382706 * f[(i + 3) * fsi] + 0.335497443431768 * f[(i + 4) * fsi] -
	0.0893976672803825 * f[(i + 5) * fsi] + 0.0106315750668706 * f[(i + 6) * fsi];
      f10 =
	-0.0106315750668706 * f[(i - 2) * fsi] + 0.136800460154007 * f[(i - 1) * fsi] +
	1.27920842085796 * f[(i + 0) * fsi] - 0.65307026400966 * f[(i + 1) * fsi] +
	0.363834643888546 * f[(i + 2) * fsi] - 0.149609960637954 * f[(i + 3) * fsi] +
	0.0378133415593911 * f[(i + 4) * fsi] - 0.00434506674541777 * f[(i + 5) * fsi];
      f11 =
	+0.00434506674541777 * f[(i - 3) * fsi] - 0.0453921090302128 * f[(i - 2) * fsi] +
	0.258462329025704 * f[(i - 1) * fsi] + 1.03588468311456 * f[(i + 0) * fsi] -
	0.348915591830416 * f[(i + 1) * fsi] + 0.12051090614515 * f[(i + 2) * fsi] -
	0.0279480917662558 * f[(i + 3) * fsi] + 0.00305280759604887 * f[(i + 4) * fsi];
      f12 =
	-0.00305280759604887 * f[(i - 4) * fsi] + 0.0287675275138087 * f[(i - 3) * fsi] -
	0.130870721719581 * f[(i - 2) * fsi] + 0.429419554404441 * f[(i - 1) * fsi] +
	0.822188151391142 * f[(i + 0) * fsi] - 0.177958366451679 * f[(i + 1) * fsi] +
	0.0350322934557819 * f[(i + 2) * fsi] - 0.00352563099786484 * f[(i + 3) * fsi];
      f13 =
	+0.00352563099786484 * f[(i - 5) * fsi] - 0.0312578555789676 * f[(i - 4) * fsi] +
	0.127485195454024 * f[(i - 3) * fsi] - 0.328306057600012 * f[(i - 2) * fsi] +
	0.67621372425498 * f[(i - 1) * fsi] + 0.624752815510711 * f[(i + 0) * fsi] -
	0.0792406985114637 * f[(i + 1) * fsi] + 0.00682724547286318 * f[(i + 2) * fsi];
      f14 =
	-0.00682724547286318 * f[(i - 6) * fsi] + 0.0581435947807703 * f[(i - 5) * fsi] -
	0.222420728819137 * f[(i - 4) * fsi] + 0.509810941934362 * f[(i - 3) * fsi] -
	0.806213240700435 * f[(i - 2) * fsi] + 1.05853947073532 * f[(i - 1) * fsi] +
	0.433589942270542 * f[(i + 0) * fsi] - 0.0246227347285582 * f[(i + 1) * fsi];
      f15 =
	+0.0246227347285582 * f[(i - 7) * fsi] - 0.203809123301329 * f[(i - 6) * fsi] +
	0.747580167180401 * f[(i - 5) * fsi] - 1.6012938736184 * f[(i - 4) * fsi] +
	2.23340237293344 * f[(i - 3) * fsi] - 2.1850863854997 * f[(i - 2) * fsi] +
	1.74797604313495 * f[(i - 1) * fsi] + 0.236608064442076 * f[(i + 0) * fsi];
      f16 =
	+1.00116903066309 * f[(i + 0) * fsi] + 0.346616904025364 * f[(i + 1) * fsi] -
	0.969422150192397 * f[(i + 2) * fsi] + 1.24209073435202 * f[(i + 3) * fsi] -
	0.98912305273897 * f[(i + 4) * fsi] + 0.490407873646602 * f[(i + 5) * fsi] -
	0.138992981947246 * f[(i + 6) * fsi] + 0.0172536421915458 * f[(i + 7) * fsi];
      f17 =
	-0.0172536421915458 * f[(i - 1) * fsi] + 1.13919816819545 * f[(i + 0) * fsi] -
	0.13648507733792 * f[(i + 1) * fsi] - 0.00321818746582843 * f[(i + 2) * fsi] +
	0.0343357809438091 * f[(i + 3) * fsi] - 0.0229190900124081 * f[(i + 4) * fsi] +
	0.00730589228331897 * f[(i + 5) * fsi] - 0.000963844414879401 * f[(i + 6) * fsi];
      f18 =
	+0.000963844414879401 * f[(i - 2) * fsi] - 0.024964397510581 * f[(i - 1) * fsi] +
	1.16618581181208 * f[(i + 0) * fsi] - 0.190460364571166 * f[(i + 1) * fsi] +
	0.06425092157573 * f[(i + 2) * fsi] - 0.0196395062894374 * f[(i + 3) * fsi] +
	0.00406855360421502 * f[(i + 4) * fsi] - 0.000404863035716217 * f[(i + 5) * fsi];
      f19 =
	+0.000404863035716217 * f[(i - 3) * fsi] - 0.00227505987085033 * f[(i - 2) * fsi] -
	0.0136282325105269 * f[(i - 1) * fsi] + 1.14351348181197 * f[(i + 0) * fsi] -
	0.162119952071031 * f[(i + 1) * fsi] + 0.0415785915756219 * f[(i + 2) * fsi] -
	0.00830334128938335 * f[(i + 3) * fsi] + 0.000829649318485302 * f[(i + 4) * fsi];
      f20 =
	-0.000829649318485302 * f[(i - 4) * fsi] + 0.00704205758359864 * f[(i - 3) * fsi] -
	0.0255052407884388 * f[(i - 2) * fsi] + 0.0328321293246499 * f[(i - 1) * fsi] +
	1.085438029518 * f[(i + 0) * fsi] - 0.115659590235854 * f[(i + 1) * fsi] +
	0.0183484106580334 * f[(i + 2) * fsi] - 0.00166614674150094 * f[(i + 3) * fsi];
      f21 =
	+0.00166614674150094 * f[(i - 5) * fsi] - 0.0141588232504928 * f[(i - 4) * fsi] +
	0.0536941663456249 * f[(i - 3) * fsi] - 0.118809458312491 * f[(i - 2) * fsi] +
	0.149462401229715 * f[(i - 1) * fsi] + 0.992133811993944 * f[(i + 0) * fsi] -
	0.0690074814738275 * f[(i + 1) * fsi] + 0.0050192367260259 * f[(i + 2) * fsi];
      f22 =
	-0.0050192367260259 * f[(i - 6) * fsi] + 0.0418200405497082 * f[(i - 5) * fsi] -
	0.154697451579218 * f[(i - 4) * fsi] + 0.334771423003076 * f[(i - 3) * fsi] -
	0.470156029134305 * f[(i - 2) * fsi] + 0.430539657887166 * f[(i - 1) * fsi] +
	0.851595183665219 * f[(i + 0) * fsi] - 0.0288535876656203 * f[(i + 1) * fsi];
      f23 =
	+0.0288535876656203 * f[(i - 7) * fsi] - 0.235847938050988 * f[(i - 6) * fsi] +
	0.849720495187075 * f[(i - 5) * fsi] - 1.77049836085395 * f[(i - 4) * fsi] +
	2.35452255959649 * f[(i - 3) * fsi] - 2.08595693840904 * f[(i - 2) * fsi] +
	1.23844011252453 * f[(i - 1) * fsi] + 0.620766482340257 * f[(i + 0) * fsi];
      f24 =
	+0.395095467390138 * f[(i + 0) * fsi] + 1.61358892835788 * f[(i + 1) * fsi] -
	2.33592683537241 * f[(i + 2) * fsi] + 2.50632675646183 * f[(i + 3) * fsi] -
	1.83894835924041 * f[(i + 4) * fsi] + 0.870026594375344 * f[(i + 5) * fsi] -
	0.239239788254888 * f[(i + 6) * fsi] + 0.0290772362825118 * f[(i + 7) * fsi];
      f25 =
	-0.0290772362825118 * f[(i - 1) * fsi] + 0.627713357650232 * f[(i + 0) * fsi] +
	0.799426312447555 * f[(i + 1) * fsi] - 0.707601603551746 * f[(i + 2) * fsi] +
	0.470920216686008 * f[(i + 3) * fsi] - 0.210623127419756 * f[(i + 4) * fsi] +
	0.0558639784650131 * f[(i + 5) * fsi] - 0.00662189799479391 * f[(i + 6) * fsi];
      f26 =
	+0.00662189799479391 * f[(i - 2) * fsi] - 0.082052420240863 * f[(i - 1) * fsi] +
	0.813126501504461 * f[(i + 0) * fsi] + 0.428600024739097 * f[(i + 1) * fsi] -
	0.244068743916174 * f[(i + 2) * fsi] + 0.10009392897755 * f[(i + 3) * fsi] -
	0.0252099835655267 * f[(i + 4) * fsi] + 0.00288879450666189 * f[(i + 5) * fsi];
      f27 =
	-0.00288879450666189 * f[(i - 3) * fsi] + 0.029732254048089 * f[(i - 2) * fsi] -
	0.162938666427396 * f[(i - 1) * fsi] + 0.974898993877527 * f[(i + 0) * fsi] +
	0.226384409272765 * f[(i + 1) * fsi] - 0.0822962515431081 * f[(i + 2) * fsi] +
	0.0192076827910169 * f[(i + 3) * fsi] - 0.00209962751223164 * f[(i + 4) * fsi];
      f28 =
	+0.00209962751223164 * f[(i - 4) * fsi] - 0.019685814604515 * f[(i - 3) * fsi] +
	0.088521824390575 * f[(i - 2) * fsi] - 0.280517807112368 * f[(i - 1) * fsi] +
	1.12187291973374 * f[(i + 0) * fsi] + 0.108805268587793 * f[(i + 1) * fsi] -
	0.0235066812006221 * f[(i + 2) * fsi] + 0.00241066269316372 * f[(i + 3) * fsi];
      f29 =
	-0.00241066269316372 * f[(i - 5) * fsi] + 0.0213849290575414 * f[(i - 4) * fsi] -
	0.0871843700130993 * f[(i - 3) * fsi] + 0.223518935207744 * f[(i - 2) * fsi] -
	0.449264195633828 * f[(i - 1) * fsi] + 1.25687003055091 * f[(i + 0) * fsi] +
	0.0413067131792086 * f[(i + 1) * fsi] - 0.00422137965531228 * f[(i + 2) * fsi];
      f30 =
	+0.00422137965531228 * f[(i - 6) * fsi] - 0.036181699935662 * f[(i - 5) * fsi] +
	0.139583559406285 * f[(i - 4) * fsi] - 0.323581630710587 * f[(i - 3) * fsi] +
	0.519015511079603 * f[(i - 2) * fsi] - 0.685661456331316 * f[(i - 1) * fsi] +
	1.37506866089965 * f[(i + 0) * fsi] + 0.0075356759367103 * f[(i + 1) * fsi];
      f31 =
	-0.0075356759367103 * f[(i - 7) * fsi] + 0.0645067871489948 * f[(i - 6) * fsi] -
	0.24718062616355 * f[(i - 5) * fsi] + 0.561581411862062 * f[(i - 4) * fsi] -
	0.851078946280308 * f[(i - 3) * fsi] + 0.94101336353538 * f[(i - 2) * fsi] -
	0.896660382559205 * f[(i - 1) * fsi] + 1.43535406839334 * f[(i + 0) * fsi];
      f32 =
	+0.165329575463981 * f[(i + 0) * fsi] + 1.74655816937676 * f[(i + 1) * fsi] -
	1.96872990232101 * f[(i + 2) * fsi] + 1.9471609018312 * f[(i + 3) * fsi] -
	1.37490704043335 * f[(i + 4) * fsi] + 0.636350062755308 * f[(i + 5) * fsi] -
	0.172524948324229 * f[(i + 6) * fsi] + 0.02076318165134 * f[(i + 7) * fsi];
      f33 =
	-0.0207631816513398 * f[(i - 1) * fsi] + 0.331435028674699 * f[(i + 0) * fsi] +
	1.16518908313925 * f[(i + 1) * fsi] - 0.805991729845979 * f[(i + 2) * fsi] +
	0.493738186237408 * f[(i + 3) * fsi] - 0.212168867958321 * f[(i + 4) * fsi] +
	0.0549809765177963 * f[(i + 5) * fsi] - 0.00641949511351079 * f[(i + 6) * fsi];
      f34 =
	+0.00641949511351078 * f[(i - 2) * fsi] - 0.0721191425594264 * f[(i - 1) * fsi] +
	0.511180891853002 * f[(i + 0) * fsi] + 0.805697356782644 * f[(i + 1) * fsi] -
	0.356627071900224 * f[(i + 2) * fsi] + 0.134246459880803 * f[(i + 3) * fsi] -
	0.0324230047800191 * f[(i + 4) * fsi] + 0.00362501560970989 * f[(i + 5) * fsi];
      f35 =
	-0.00362501560970989 * f[(i - 3) * fsi] + 0.03541961999119 * f[(i - 2) * fsi] -
	0.173619579631303 * f[(i - 1) * fsi] + 0.714181765996756 * f[(i + 0) * fsi] +
	0.551946264102951 * f[(i + 1) * fsi] - 0.15362619775647 * f[(i + 2) * fsi] +
	0.0327460228089262 * f[(i + 3) * fsi] - 0.00342287990233993 * f[(i + 4) * fsi];
      f36 =
	+0.00342287990233993 * f[(i - 4) * fsi] - 0.0310080548284293 * f[(i - 3) * fsi] +
	0.131260257256708 * f[(i - 2) * fsi] - 0.365300854162339 * f[(i - 1) * fsi] +
	0.953783359160551 * f[(i + 0) * fsi] + 0.360264989571915 * f[(i + 1) * fsi] -
	0.0577855604909524 * f[(i + 2) * fsi] + 0.00536298359020681 * f[(i + 3) * fsi];
      f37 =
	-0.00536298359020681 * f[(i - 5) * fsi] + 0.0463267486239944 * f[(i - 4) * fsi] -
	0.18117159535422 * f[(i - 3) * fsi] + 0.431587338308289 * f[(i - 2) * fsi] -
	0.740709705476816 * f[(i - 1) * fsi] + 1.25411044021213 * f[(i + 0) * fsi] +
	0.210101449046125 * f[(i + 1) * fsi] - 0.0148816917692979 * f[(i + 2) * fsi];
      f38 =
	+0.0148816917692979 * f[(i - 6) * fsi] - 0.12441651774459 * f[(i - 5) * fsi] +
	0.463014118164337 * f[(i - 4) * fsi] - 1.01454633443491 * f[(i - 3) * fsi] +
	1.47330576215915 * f[(i - 2) * fsi] - 1.5740844445575 * f[(i - 1) * fsi] +
	1.67079780975248 * f[(i + 0) * fsi] + 0.0910479148917409 * f[(i + 1) * fsi];
      f39 =
	-0.091047914891741 * f[(i - 7) * fsi] + 0.743265010903225 * f[(i - 6) * fsi] -
	2.67375813471334 * f[(i - 5) * fsi] + 5.56169735210183 * f[(i - 4) * fsi] -
	7.38790037685677 * f[(i - 3) * fsi] + 6.57198899609664 * f[(i - 2) * fsi] -
	4.12342606152625 * f[(i - 1) * fsi] + 2.3991811288864 * f[(i + 0) * fsi];
      fr0 =
	f0 * omega0 + f1 * omega1 + f2 * omega2 + f3 * omega3 + f4 * omega4 + f5 * omega5 +
	f6 * omega6 + f7 * omega7;
      fr1 =
	f8 * omega8 + f9 * omega9 + f10 * omega10 + f11 * omega11 + f12 * omega12 + f13 * omega13 +
	f14 * omega14 + f15 * omega15;
      fr2 =
	+2.15702909768515 * (f16 * omega16p + f17 * omega17p + f18 * omega18p + f19 * omega19p +
			     f20 * omega20p + f21 * omega21p + f22 * omega22p + f23 * omega23p) -
	+1.15702909768516 * (f16 * omega16m + f17 * omega17m + f18 * omega18m + f19 * omega19m +
			     f20 * omega20m + f21 * omega21m + f22 * omega22m + f23 * omega23m);
      fr3 =
	f24 * omega24 + f25 * omega25 + f26 * omega26 + f27 * omega27 + f28 * omega28 +
	f29 * omega29 + f30 * omega30 + f31 * omega31;
      fr4 =
	f32 * omega32 + f33 * omega33 + f34 * omega34 + f35 * omega35 + f36 * omega36 +
	f37 * omega37 + f38 * omega38 + f39 * omega39;
      fr[i * frsi + 0 * frsl] = fr0;
      fr[i * frsi + 1 * frsl] = fr1;
      fr[i * frsi + 2 * frsl] = fr2;
      fr[i * frsi + 3 * frsl] = fr3;
      fr[i * frsi + 4 * frsl] = fr4;
    }
}

PyObject *
py_gauss_radau008005 (PyObject * self, PyObject * args)
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

  gauss_radau008005 (f, n, fsi, sigma, ssi, ssr, fr, frsi, frsl);

  Py_INCREF (Py_None);
  return Py_None;
}
