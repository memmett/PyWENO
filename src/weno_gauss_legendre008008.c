#include <Python.h>
#include <numpy/ndarrayobject.h>

void
gauss_legendre008008 (const double *restrict f, int n, int fsi,
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
      omega0 = +0.000172343446536813 / (1.0e-6 + sigma0) / (1.0e-6 + sigma0);
      accumulator += omega0;
      omega1 = +0.00922584480747484 / (1.0e-6 + sigma1) / (1.0e-6 + sigma1);
      accumulator += omega1;
      omega2 = +0.0944113324396715 / (1.0e-6 + sigma2) / (1.0e-6 + sigma2);
      accumulator += omega2;
      omega3 = +0.308488082635939 / (1.0e-6 + sigma3) / (1.0e-6 + sigma3);
      accumulator += omega3;
      omega4 = +0.378767571344285 / (1.0e-6 + sigma4) / (1.0e-6 + sigma4);
      accumulator += omega4;
      omega5 = +0.178591350601291 / (1.0e-6 + sigma5) / (1.0e-6 + sigma5);
      accumulator += omega5;
      omega6 = +0.0291822006066151 / (1.0e-6 + sigma6) / (1.0e-6 + sigma6);
      accumulator += omega6;
      omega7 = +0.00116127411818649 / (1.0e-6 + sigma7) / (1.0e-6 + sigma7);
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
      omega8 = +0.000270306412730579 / (1.0e-6 + sigma0) / (1.0e-6 + sigma0);
      accumulator += omega8;
      omega9 = +0.0118225734703371 / (1.0e-6 + sigma1) / (1.0e-6 + sigma1);
      accumulator += omega9;
      omega10 = +0.108079944684974 / (1.0e-6 + sigma2) / (1.0e-6 + sigma2);
      accumulator += omega10;
      omega11 = +0.324124355676526 / (1.0e-6 + sigma3) / (1.0e-6 + sigma3);
      accumulator += omega11;
      omega12 = +0.368972783242558 / (1.0e-6 + sigma4) / (1.0e-6 + sigma4);
      accumulator += omega12;
      omega13 = +0.161520666662618 / (1.0e-6 + sigma5) / (1.0e-6 + sigma5);
      accumulator += omega13;
      omega14 = +0.0243356660445955 / (1.0e-6 + sigma6) / (1.0e-6 + sigma6);
      accumulator += omega14;
      omega15 = +0.000873703805660031 / (1.0e-6 + sigma7) / (1.0e-6 + sigma7);
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
      omega16 = +0.000814744690499243 / (1.0e-6 + sigma0) / (1.0e-6 + sigma0);
      accumulator += omega16;
      omega17 = +0.0196184178412349 / (1.0e-6 + sigma1) / (1.0e-6 + sigma1);
      accumulator += omega17;
      omega18 = +0.138749294473838 / (1.0e-6 + sigma2) / (1.0e-6 + sigma2);
      accumulator += omega18;
      omega19 = +0.348756566971766 / (1.0e-6 + sigma3) / (1.0e-6 + sigma3);
      accumulator += omega19;
      omega20 = +0.343244369998645 / (1.0e-6 + sigma4) / (1.0e-6 + sigma4);
      accumulator += omega20;
      omega21 = +0.131169207122397 / (1.0e-6 + sigma5) / (1.0e-6 + sigma5);
      accumulator += omega21;
      omega22 = +0.01713201152241 / (1.0e-6 + sigma6) / (1.0e-6 + sigma6);
      accumulator += omega22;
      omega23 = +0.000515387379209371 / (1.0e-6 + sigma7) / (1.0e-6 + sigma7);
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
      omega24p = +0.000387887406003562 / +2.23073251131246 / (1.0e-6 + sigma0) / (1.0e-6 + sigma0);
      accumulator += omega24p;
      omega25p = +0.0765229496981494 / +2.23073251131246 / (1.0e-6 + sigma1) / (1.0e-6 + sigma1);
      accumulator += omega25p;
      omega26p = +1.01977051907231 / +2.23073251131246 / (1.0e-6 + sigma2) / (1.0e-6 + sigma2);
      accumulator += omega26p;
      omega27p = +0.531713096820557 / +2.23073251131246 / (1.0e-6 + sigma3) / (1.0e-6 + sigma3);
      accumulator += omega27p;
      omega28p = +0.450278376665416 / +2.23073251131246 / (1.0e-6 + sigma4) / (1.0e-6 + sigma4);
      accumulator += omega28p;
      omega29p = +0.137399129882376 / +2.23073251131246 / (1.0e-6 + sigma5) / (1.0e-6 + sigma5);
      accumulator += omega29p;
      omega30p = +0.0143299454776163 / +2.23073251131246 / (1.0e-6 + sigma6) / (1.0e-6 + sigma6);
      accumulator += omega30p;
      omega31p = +0.000330606290035781 / +2.23073251131246 / (1.0e-6 + sigma7) / (1.0e-6 + sigma7);
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
      omega24m = +0.000775774812007124 / +1.23073251131246 / (1.0e-6 + sigma0) / (1.0e-6 + sigma0);
      accumulator += omega24m;
      omega25m = +0.153045899396299 / +1.23073251131246 / (1.0e-6 + sigma1) / (1.0e-6 + sigma1);
      accumulator += omega25m;
      omega26m = +0.509885259536153 / +1.23073251131246 / (1.0e-6 + sigma2) / (1.0e-6 + sigma2);
      accumulator += omega26m;
      omega27m = +0.265856548410279 / +1.23073251131246 / (1.0e-6 + sigma3) / (1.0e-6 + sigma3);
      accumulator += omega27m;
      omega28m = +0.225139188332708 / +1.23073251131246 / (1.0e-6 + sigma4) / (1.0e-6 + sigma4);
      accumulator += omega28m;
      omega29m = +0.0686995649411878 / +1.23073251131246 / (1.0e-6 + sigma5) / (1.0e-6 + sigma5);
      accumulator += omega29m;
      omega30m = +0.00716497273880815 / +1.23073251131246 / (1.0e-6 + sigma6) / (1.0e-6 + sigma6);
      accumulator += omega30m;
      omega31m = +0.000165303145017891 / +1.23073251131246 / (1.0e-6 + sigma7) / (1.0e-6 + sigma7);
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
      omega32p = +0.000330606290014966 / +2.23073251131247 / (1.0e-6 + sigma0) / (1.0e-6 + sigma0);
      accumulator += omega32p;
      omega33p = +0.0143299454776922 / +2.23073251131247 / (1.0e-6 + sigma1) / (1.0e-6 + sigma1);
      accumulator += omega33p;
      omega34p = +0.13739912988227 / +2.23073251131247 / (1.0e-6 + sigma2) / (1.0e-6 + sigma2);
      accumulator += omega34p;
      omega35p = +0.450278376665482 / +2.23073251131247 / (1.0e-6 + sigma3) / (1.0e-6 + sigma3);
      accumulator += omega35p;
      omega36p = +0.531713096820563 / +2.23073251131247 / (1.0e-6 + sigma4) / (1.0e-6 + sigma4);
      accumulator += omega36p;
      omega37p = +1.01977051907229 / +2.23073251131247 / (1.0e-6 + sigma5) / (1.0e-6 + sigma5);
      accumulator += omega37p;
      omega38p = +0.07652294969814 / +2.23073251131247 / (1.0e-6 + sigma6) / (1.0e-6 + sigma6);
      accumulator += omega38p;
      omega39p = +0.00038788740601569 / +2.23073251131247 / (1.0e-6 + sigma7) / (1.0e-6 + sigma7);
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
      omega32m = +0.000165303145007483 / +1.23073251131247 / (1.0e-6 + sigma0) / (1.0e-6 + sigma0);
      accumulator += omega32m;
      omega33m = +0.0071649727388461 / +1.23073251131247 / (1.0e-6 + sigma1) / (1.0e-6 + sigma1);
      accumulator += omega33m;
      omega34m = +0.068699564941135 / +1.23073251131247 / (1.0e-6 + sigma2) / (1.0e-6 + sigma2);
      accumulator += omega34m;
      omega35m = +0.225139188332741 / +1.23073251131247 / (1.0e-6 + sigma3) / (1.0e-6 + sigma3);
      accumulator += omega35m;
      omega36m = +0.265856548410282 / +1.23073251131247 / (1.0e-6 + sigma4) / (1.0e-6 + sigma4);
      accumulator += omega36m;
      omega37m = +0.509885259536144 / +1.23073251131247 / (1.0e-6 + sigma5) / (1.0e-6 + sigma5);
      accumulator += omega37m;
      omega38m = +0.15304589939628 / +1.23073251131247 / (1.0e-6 + sigma6) / (1.0e-6 + sigma6);
      accumulator += omega38m;
      omega39m = +0.00077577481203138 / +1.23073251131247 / (1.0e-6 + sigma7) / (1.0e-6 + sigma7);
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
      omega40 = +0.000515387379103101 / (1.0e-6 + sigma0) / (1.0e-6 + sigma0);
      accumulator += omega40;
      omega41 = +0.0171320115225683 / (1.0e-6 + sigma1) / (1.0e-6 + sigma1);
      accumulator += omega41;
      omega42 = +0.131169207122295 / (1.0e-6 + sigma2) / (1.0e-6 + sigma2);
      accumulator += omega42;
      omega43 = +0.343244369998677 / (1.0e-6 + sigma3) / (1.0e-6 + sigma3);
      accumulator += omega43;
      omega44 = +0.34875656697176 / (1.0e-6 + sigma4) / (1.0e-6 + sigma4);
      accumulator += omega44;
      omega45 = +0.138749294473839 / (1.0e-6 + sigma5) / (1.0e-6 + sigma5);
      accumulator += omega45;
      omega46 = +0.0196184178412382 / (1.0e-6 + sigma6) / (1.0e-6 + sigma6);
      accumulator += omega46;
      omega47 = +0.00081474469049712 / (1.0e-6 + sigma7) / (1.0e-6 + sigma7);
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
      omega48 = +0.00087370380561823 / (1.0e-6 + sigma0) / (1.0e-6 + sigma0);
      accumulator += omega48;
      omega49 = +0.0243356660446407 / (1.0e-6 + sigma1) / (1.0e-6 + sigma1);
      accumulator += omega49;
      omega50 = +0.161520666662593 / (1.0e-6 + sigma2) / (1.0e-6 + sigma2);
      accumulator += omega50;
      omega51 = +0.368972783242566 / (1.0e-6 + sigma3) / (1.0e-6 + sigma3);
      accumulator += omega51;
      omega52 = +0.324124355676525 / (1.0e-6 + sigma4) / (1.0e-6 + sigma4);
      accumulator += omega52;
      omega53 = +0.108079944684975 / (1.0e-6 + sigma5) / (1.0e-6 + sigma5);
      accumulator += omega53;
      omega54 = +0.011822573470334 / (1.0e-6 + sigma6) / (1.0e-6 + sigma6);
      accumulator += omega54;
      omega55 = +0.00027030641273236 / (1.0e-6 + sigma7) / (1.0e-6 + sigma7);
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
      omega56 = +0.00116127411804176 / (1.0e-6 + sigma0) / (1.0e-6 + sigma0);
      accumulator += omega56;
      omega57 = +0.0291822006067421 / (1.0e-6 + sigma1) / (1.0e-6 + sigma1);
      accumulator += omega57;
      omega58 = +0.178591350601254 / (1.0e-6 + sigma2) / (1.0e-6 + sigma2);
      accumulator += omega58;
      omega59 = +0.378767571344283 / (1.0e-6 + sigma3) / (1.0e-6 + sigma3);
      accumulator += omega59;
      omega60 = +0.308488082635944 / (1.0e-6 + sigma4) / (1.0e-6 + sigma4);
      accumulator += omega60;
      omega61 = +0.0944113324396694 / (1.0e-6 + sigma5) / (1.0e-6 + sigma5);
      accumulator += omega61;
      omega62 = +0.00922584480747479 / (1.0e-6 + sigma6) / (1.0e-6 + sigma6);
      accumulator += omega62;
      omega63 = +0.000172343446537023 / (1.0e-6 + sigma7) / (1.0e-6 + sigma7);
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
	+2.60347605498316 * f[(i + 0) * fsi] - 4.86214462562595 * f[(i + 1) * fsi] +
	7.9346715496119 * f[(i + 2) * fsi] - 9.01102601414878 * f[(i + 3) * fsi] +
	6.82126382082207 * f[(i + 4) * fsi] - 3.29063370093778 * f[(i + 5) * fsi] +
	0.916902545067321 * f[(i + 6) * fsi] - 0.112509629771942 * f[(i + 7) * fsi];
      f1 =
	+0.112509629771942 * f[(i - 1) * fsi] + 1.70339901680762 * f[(i + 0) * fsi] -
	1.71187499201158 * f[(i + 1) * fsi] + 1.63413228238316 * f[(i + 2) * fsi] -
	1.13535193011285 * f[(i + 3) * fsi] + 0.520724553593327 * f[(i + 4) * fsi] -
	0.140364067323406 * f[(i + 5) * fsi] + 0.0168255068917857 * f[(i + 6) * fsi];
      f2 =
	-0.0168255068917857 * f[(i - 2) * fsi] + 0.247113684906227 * f[(i - 1) * fsi] +
	1.23228482383762 * f[(i + 0) * fsi] - 0.769646606071578 * f[(i + 1) * fsi] +
	0.456346799958163 * f[(i + 2) * fsi] - 0.193123544172856 * f[(i + 3) * fsi] +
	0.0496103606233281 * f[(i + 4) * fsi] - 0.00576001218912098 * f[(i + 5) * fsi];
      f3 =
	+0.00576001218912098 * f[(i - 3) * fsi] - 0.0629056044047535 * f[(i - 2) * fsi] +
	0.408394026201615 * f[(i - 1) * fsi] + 0.909724141246847 * f[(i + 0) * fsi] -
	0.366445752833109 * f[(i + 1) * fsi] + 0.133786117367388 * f[(i + 2) * fsi] -
	0.0318432028774681 * f[(i + 3) * fsi] + 0.00353026311036026 * f[(i + 4) * fsi];
      f4 =
	-0.00353026311036026 * f[(i - 4) * fsi] + 0.0340021170720031 * f[(i - 3) * fsi] -
	0.161752971494841 * f[(i - 2) * fsi] + 0.606088760381789 * f[(i - 1) * fsi] +
	0.662605723521629 * f[(i + 0) * fsi] - 0.168751018652934 * f[(i + 1) * fsi] +
	0.0349387502773002 * f[(i + 2) * fsi] - 0.00360109799458602 * f[(i + 3) * fsi];
      f5 =
	+0.00360109799458602 * f[(i - 5) * fsi] - 0.0323390470670485 * f[(i - 4) * fsi] +
	0.134832860920412 * f[(i - 3) * fsi] - 0.363414459191658 * f[(i - 2) * fsi] +
	0.858165620002811 * f[(i - 1) * fsi] + 0.460944235824812 * f[(i + 0) * fsi] -
	0.0679202748045258 * f[(i + 1) * fsi] + 0.00612996632061196 * f[(i + 2) * fsi];
      f6 =
	-0.00612996632061196 * f[(i - 6) * fsi] + 0.0526408285594817 * f[(i - 5) * fsi] -
	0.203978104044183 * f[(i - 4) * fsi] + 0.478110974874681 * f[(i - 3) * fsi] -
	0.792512101634495 * f[(i - 2) * fsi] + 1.20144373395708 * f[(i - 1) * fsi] +
	0.289305178847677 * f[(i + 0) * fsi] - 0.0188805442396301 * f[(i + 1) * fsi];
      f7 =
	+0.0188805442396301 * f[(i - 7) * fsi] - 0.157174320237653 * f[(i - 6) * fsi] +
	0.581296067269125 * f[(i - 5) * fsi] - 1.26128858146347 * f[(i - 4) * fsi] +
	1.79974907164879 * f[(i - 3) * fsi] - 1.84982257905378 * f[(i - 2) * fsi] +
	1.73009897266672 * f[(i - 1) * fsi] + 0.138260824930636 * f[(i + 0) * fsi];
      f8 =
	+2.17162266811665 * f[(i + 0) * fsi] - 3.31965732036525 * f[(i + 1) * fsi] +
	5.11392725056139 * f[(i + 2) * fsi] - 5.6650529952341 * f[(i + 3) * fsi] +
	4.23084669165628 * f[(i + 4) * fsi] - 2.02387676469207 * f[(i + 5) * fsi] +
	0.560707666626518 * f[(i + 6) * fsi] - 0.0685171966694168 * f[(i + 7) * fsi];
      f9 =
	+0.0685171966694168 * f[(i - 1) * fsi] + 1.62348509476131 * f[(i + 0) * fsi] -
	1.40117581362158 * f[(i + 1) * fsi] + 1.27696423707405 * f[(i + 2) * fsi] -
	0.868849228374924 * f[(i + 3) * fsi] + 0.393883678168945 * f[(i + 4) * fsi] -
	0.105395257948405 * f[(i + 5) * fsi] + 0.0125700932711838 * f[(i + 6) * fsi];
      f10 =
	-0.0125700932711838 * f[(i - 2) * fsi] + 0.169077942838887 * f[(i - 1) * fsi] +
	1.27152248316817 * f[(i + 0) * fsi] - 0.697250590435284 * f[(i + 1) * fsi] +
	0.397057708091181 * f[(i + 2) * fsi] - 0.164924005188631 * f[(i + 3) * fsi] +
	0.0419210665757981 * f[(i + 4) * fsi] - 0.00483451177893436 * f[(i + 5) * fsi];
      f11 =
	+0.00483451177893436 * f[(i - 3) * fsi] - 0.0512461875026587 * f[(i - 2) * fsi] +
	0.304444272649049 * f[(i - 1) * fsi] + 1.00078982354784 * f[(i + 0) * fsi] -
	0.358834765909879 * f[(i + 1) * fsi] + 0.126325048470857 * f[(i + 2) * fsi] -
	0.0295576753784687 * f[(i + 3) * fsi] + 0.00324497234432326 * f[(i + 4) * fsi];
      f12 =
	-0.00324497234432326 * f[(i - 4) * fsi] + 0.0307942905335204 * f[(i - 3) * fsi] -
	0.14210541314371 * f[(i - 2) * fsi] + 0.486162723931152 * f[(i - 1) * fsi] +
	0.773641759445215 * f[(i + 0) * fsi] - 0.177116314627777 * f[(i + 1) * fsi] +
	0.0354658228298058 * f[(i + 2) * fsi] - 0.00359789662388271 * f[(i + 3) * fsi];
      f13 =
	+0.00359789662388271 * f[(i - 5) * fsi] - 0.0320281453353849 * f[(i - 4) * fsi] +
	0.131535396002236 * f[(i - 3) * fsi] - 0.343587624081141 * f[(i - 2) * fsi] +
	0.738015487602941 * f[(i - 1) * fsi] + 0.572159548507783 * f[(i + 0) * fsi] -
	0.0763752091590609 * f[(i + 1) * fsi] + 0.00668264983874413 * f[(i + 2) * fsi];
      f14 =
	-0.00668264983874413 * f[(i - 6) * fsi] + 0.0570590953338357 * f[(i - 5) * fsi] -
	0.21914234082022 * f[(i - 4) * fsi] + 0.505763786971907 * f[(i - 3) * fsi] -
	0.81137311279323 * f[(i - 2) * fsi] + 1.11224387857261 * f[(i - 1) * fsi] +
	0.385045353022948 * f[(i + 0) * fsi] - 0.0229140104491079 * f[(i + 1) * fsi];
      f15 =
	+0.0229140104491079 * f[(i - 7) * fsi] - 0.189994733431607 * f[(i - 6) * fsi] +
	0.698651387908857 * f[(i - 5) * fsi] - 1.50232692597026 * f[(i - 4) * fsi] +
	2.10974451840946 * f[(i - 3) * fsi] - 2.09455769794327 * f[(i - 2) * fsi] +
	1.75383617114763 * f[(i - 1) * fsi] + 0.201733269430084 * f[(i + 0) * fsi];
      f16 =
	+1.5815651119531 * f[(i + 0) * fsi] - 1.35167166083851 * f[(i + 1) * fsi] +
	1.69075370894815 * f[(i + 2) * fsi] - 1.69844078070112 * f[(i + 3) * fsi] +
	1.20009112635422 * f[(i + 4) * fsi] - 0.554121517979353 * f[(i + 5) * fsi] +
	0.149804621277324 * f[(i + 6) * fsi] - 0.0179806090138082 * f[(i + 7) * fsi];
      f17 =
	+0.0179806090138082 * f[(i - 1) * fsi] + 1.43772023984263 * f[(i + 0) * fsi] -
	0.848214608451878 * f[(i + 1) * fsi] + 0.683839604174886 * f[(i + 2) * fsi] -
	0.439798149734542 * f[(i + 3) * fsi] + 0.19317702158096 * f[(i + 4) * fsi] -
	0.0506644655927231 * f[(i + 5) * fsi] + 0.00595974916685827 * f[(i + 6) * fsi];
      f18 =
	-0.00595974916685827 * f[(i - 2) * fsi] + 0.0656586023486744 * f[(i - 1) * fsi] +
	1.2708472631706 * f[(i + 0) * fsi] - 0.514468655107814 * f[(i + 1) * fsi] +
	0.266657162494806 * f[(i + 2) * fsi] - 0.106052196390478 * f[(i + 3) * fsi] +
	0.0263040449089286 * f[(i + 4) * fsi] - 0.00298647225785693 * f[(i + 5) * fsi];
      f19 =
	+0.00298647225785693 * f[(i - 3) * fsi] - 0.0298515272297137 * f[(i - 2) * fsi] +
	0.149279825568669 * f[(i - 1) * fsi] + 1.10360481673061 * f[(i + 0) * fsi] -
	0.305415597057829 * f[(i + 1) * fsi] + 0.0994147160548181 * f[(i + 2) * fsi] -
	0.0224309731704841 * f[(i + 3) * fsi] + 0.00241226684607314 * f[(i + 4) * fsi];
      f20 =
	-0.00241226684607314 * f[(i - 4) * fsi] + 0.0222846070264421 * f[(i - 3) * fsi] -
	0.0973949989197617 * f[(i - 2) * fsi] + 0.284366768948765 * f[(i - 1) * fsi] +
	0.93474613750549 * f[(i + 0) * fsi] - 0.170328653677733 * f[(i + 1) * fsi] +
	0.0318712443647702 * f[(i + 2) * fsi] - 0.00313283840189896 * f[(i + 3) * fsi];
      f21 =
	+0.00313283840189896 * f[(i - 5) * fsi] - 0.0274749740612648 * f[(i - 4) * fsi] +
	0.110004082279613 * f[(i - 3) * fsi] - 0.272833949426103 * f[(i - 2) * fsi] +
	0.503665457081692 * f[(i - 1) * fsi] + 0.759307186999148 * f[(i + 0) * fsi] -
	0.0826091784245623 * f[(i + 1) * fsi] + 0.00680853714957848 * f[(i + 2) * fsi];
      f22 =
	-0.00680853714957848 * f[(i - 6) * fsi] + 0.0576011355985268 * f[(i - 5) * fsi] -
	0.218114014249462 * f[(i - 4) * fsi] + 0.491282162656008 * f[(i - 3) * fsi] -
	0.749431549896597 * f[(i - 2) * fsi] + 0.884943537458086 * f[(i - 1) * fsi] +
	0.568668146810951 * f[(i + 0) * fsi] - 0.0281408812279345 * f[(i + 1) * fsi];
      f23 =
	+0.0281408812279345 * f[(i - 7) * fsi] - 0.231935586973054 * f[(i - 6) * fsi] +
	0.845545809980693 * f[(i - 5) * fsi] - 1.79400336301379 * f[(i - 4) * fsi] +
	2.46114384861142 * f[(i - 3) * fsi] - 2.32532089866093 * f[(i - 2) * fsi] +
	1.67288821184025 * f[(i - 1) * fsi] + 0.343541096987475 * f[(i + 0) * fsi];
      f24 =
	+1.02327657991024 * f[(i + 0) * fsi] + 0.288070217593972 * f[(i + 1) * fsi] -
	0.885838832343234 * f[(i + 2) * fsi] + 1.15355660612309 * f[(i + 3) * fsi] -
	0.924753952837543 * f[(i + 4) * fsi] + 0.460151058134428 * f[(i + 5) * fsi] -
	0.130712564220108 * f[(i + 6) * fsi] + 0.0162508876391552 * f[(i + 7) * fsi];
      f25 =
	-0.0162508876391552 * f[(i - 1) * fsi] + 1.15328368102348 * f[(i + 0) * fsi] -
	0.166954636302372 * f[(i + 1) * fsi] + 0.0242108754494569 * f[(i + 2) * fsi] +
	0.0159944713822262 * f[(i + 3) * fsi] - 0.014704245044852 * f[(i + 4) * fsi] +
	0.00512620423808199 * f[(i + 5) * fsi] - 0.000705463106866888 * f[(i + 6) * fsi];
      f26 =
	+0.000705463106866889 * f[(i - 2) * fsi] - 0.0218945924940903 * f[(i - 1) * fsi] +
	1.17303664801575 * f[(i + 0) * fsi] - 0.206460570286918 * f[(i + 1) * fsi] +
	0.0735932929301388 * f[(i + 2) * fsi] - 0.0235114626023195 * f[(i + 3) * fsi] +
	0.00504872194742077 * f[(i + 4) * fsi] - 0.000517500616853109 * f[(i + 5) * fsi];
      f27 =
	+0.000517500616853109 * f[(i - 3) * fsi] - 0.003434541827958 * f[(i - 2) * fsi] -
	0.00740457522220318 * f[(i - 1) * fsi] + 1.14405661347198 * f[(i + 0) * fsi] -
	0.1702355271072 * f[(i + 1) * fsi] + 0.0446132583863647 * f[(i + 2) * fsi] -
	0.00902144533043246 * f[(i + 3) * fsi] + 0.000908717012595893 * f[(i + 4) * fsi];
      f28 =
	-0.000908717012595893 * f[(i - 4) * fsi] + 0.00778723671762025 * f[(i - 3) * fsi] -
	0.028878618180643 * f[(i - 2) * fsi] + 0.0434835774831667 * f[(i - 1) * fsi] +
	1.08044642259027 * f[(i + 0) * fsi] - 0.11934737440183 * f[(i + 1) * fsi] +
	0.0191691820336797 * f[(i + 2) * fsi] - 0.00175170922966532 * f[(i + 3) * fsi];
      f29 =
	+0.00175170922966532 * f[(i - 5) * fsi] - 0.0149223908499185 * f[(i - 4) * fsi] +
	0.0568350951482493 * f[(i - 3) * fsi] - 0.126974335041901 * f[(i - 2) * fsi] +
	0.166103223559739 * f[(i - 1) * fsi] + 0.98235070572901 * f[(i + 0) * fsi] -
	0.0702995159712014 * f[(i + 1) * fsi] + 0.00515550819635714 * f[(i + 2) * fsi];
      f30 =
	-0.00515550819635714 * f[(i - 6) * fsi] + 0.0429957748005224 * f[(i - 5) * fsi] -
	0.159276620347918 * f[(i - 4) * fsi] + 0.345543554144249 * f[(i - 3) * fsi] -
	0.487859908786901 * f[(i - 2) * fsi] + 0.454811682555739 * f[(i - 1) * fsi] +
	0.83799647623101 * f[(i + 0) * fsi] - 0.0290554504003443 * f[(i + 1) * fsi];
      f31 =
	+0.0290554504003443 * f[(i - 7) * fsi] - 0.237599111399111 * f[(i - 6) * fsi] +
	0.856548386010162 * f[(i - 5) * fsi] - 1.7863818427672 * f[(i - 4) * fsi] +
	2.37942508216835 * f[(i - 3) * fsi] - 2.11496513120618 * f[(i - 2) * fsi] +
	1.26836429376538 * f[(i - 1) * fsi] + 0.605552873028256 * f[(i + 0) * fsi];
      f32 =
	+0.605552873028256 * f[(i + 0) * fsi] + 1.26836429376538 * f[(i + 1) * fsi] -
	2.11496513120618 * f[(i + 2) * fsi] + 2.37942508216834 * f[(i + 3) * fsi] -
	1.7863818427672 * f[(i + 4) * fsi] + 0.856548386010163 * f[(i + 5) * fsi] -
	0.237599111399111 * f[(i + 6) * fsi] + 0.0290554504003443 * f[(i + 7) * fsi];
      f33 =
	-0.0290554504003442 * f[(i - 1) * fsi] + 0.83799647623101 * f[(i + 0) * fsi] +
	0.454811682555739 * f[(i + 1) * fsi] - 0.4878599087869 * f[(i + 2) * fsi] +
	0.345543554144249 * f[(i + 3) * fsi] - 0.159276620347918 * f[(i + 4) * fsi] +
	0.0429957748005224 * f[(i + 5) * fsi] - 0.00515550819635714 * f[(i + 6) * fsi];
      f34 =
	+0.00515550819635714 * f[(i - 2) * fsi] - 0.0702995159712015 * f[(i - 1) * fsi] +
	0.98235070572901 * f[(i + 0) * fsi] + 0.166103223559739 * f[(i + 1) * fsi] -
	0.126974335041901 * f[(i + 2) * fsi] + 0.0568350951482494 * f[(i + 3) * fsi] -
	0.0149223908499185 * f[(i + 4) * fsi] + 0.00175170922966532 * f[(i + 5) * fsi];
      f35 =
	-0.00175170922966532 * f[(i - 3) * fsi] + 0.0191691820336797 * f[(i - 2) * fsi] -
	0.11934737440183 * f[(i - 1) * fsi] + 1.08044642259027 * f[(i + 0) * fsi] +
	0.0434835774831669 * f[(i + 1) * fsi] - 0.028878618180643 * f[(i + 2) * fsi] +
	0.00778723671762027 * f[(i + 3) * fsi] - 0.000908717012595895 * f[(i + 4) * fsi];
      f36 =
	+0.000908717012595895 * f[(i - 4) * fsi] - 0.00902144533043247 * f[(i - 3) * fsi] +
	0.0446132583863647 * f[(i - 2) * fsi] - 0.170235527107201 * f[(i - 1) * fsi] +
	1.14405661347198 * f[(i + 0) * fsi] - 0.00740457522220317 * f[(i + 1) * fsi] -
	0.003434541827958 * f[(i + 2) * fsi] + 0.000517500616853111 * f[(i + 3) * fsi];
      f37 =
	-0.000517500616853112 * f[(i - 5) * fsi] + 0.00504872194742079 * f[(i - 4) * fsi] -
	0.0235114626023196 * f[(i - 3) * fsi] + 0.073593292930139 * f[(i - 2) * fsi] -
	0.206460570286918 * f[(i - 1) * fsi] + 1.17303664801575 * f[(i + 0) * fsi] -
	0.0218945924940903 * f[(i + 1) * fsi] + 0.000705463106866886 * f[(i + 2) * fsi];
      f38 =
	-0.000705463106866886 * f[(i - 6) * fsi] + 0.00512620423808197 * f[(i - 5) * fsi] -
	0.014704245044852 * f[(i - 4) * fsi] + 0.015994471382226 * f[(i - 3) * fsi] +
	0.0242108754494571 * f[(i - 2) * fsi] - 0.166954636302373 * f[(i - 1) * fsi] +
	1.15328368102348 * f[(i + 0) * fsi] - 0.0162508876391552 * f[(i + 1) * fsi];
      f39 =
	+0.0162508876391552 * f[(i - 7) * fsi] - 0.130712564220108 * f[(i - 6) * fsi] +
	0.460151058134427 * f[(i - 5) * fsi] - 0.924753952837543 * f[(i - 4) * fsi] +
	1.15355660612309 * f[(i - 3) * fsi] - 0.885838832343234 * f[(i - 2) * fsi] +
	0.288070217593973 * f[(i - 1) * fsi] + 1.02327657991024 * f[(i + 0) * fsi];
      f40 =
	+0.343541096987475 * f[(i + 0) * fsi] + 1.67288821184025 * f[(i + 1) * fsi] -
	2.32532089866093 * f[(i + 2) * fsi] + 2.46114384861143 * f[(i + 3) * fsi] -
	1.79400336301379 * f[(i + 4) * fsi] + 0.845545809980694 * f[(i + 5) * fsi] -
	0.231935586973055 * f[(i + 6) * fsi] + 0.0281408812279346 * f[(i + 7) * fsi];
      f41 =
	-0.0281408812279346 * f[(i - 1) * fsi] + 0.568668146810951 * f[(i + 0) * fsi] +
	0.884943537458086 * f[(i + 1) * fsi] - 0.749431549896597 * f[(i + 2) * fsi] +
	0.491282162656008 * f[(i + 3) * fsi] - 0.218114014249462 * f[(i + 4) * fsi] +
	0.0576011355985268 * f[(i + 5) * fsi] - 0.00680853714957848 * f[(i + 6) * fsi];
      f42 =
	+0.00680853714957848 * f[(i - 2) * fsi] - 0.0826091784245624 * f[(i - 1) * fsi] +
	0.759307186999149 * f[(i + 0) * fsi] + 0.503665457081692 * f[(i + 1) * fsi] -
	0.272833949426104 * f[(i + 2) * fsi] + 0.110004082279613 * f[(i + 3) * fsi] -
	0.0274749740612648 * f[(i + 4) * fsi] + 0.00313283840189896 * f[(i + 5) * fsi];
      f43 =
	-0.00313283840189896 * f[(i - 3) * fsi] + 0.0318712443647702 * f[(i - 2) * fsi] -
	0.170328653677733 * f[(i - 1) * fsi] + 0.93474613750549 * f[(i + 0) * fsi] +
	0.284366768948765 * f[(i + 1) * fsi] - 0.0973949989197617 * f[(i + 2) * fsi] +
	0.0222846070264421 * f[(i + 3) * fsi] - 0.00241226684607314 * f[(i + 4) * fsi];
      f44 =
	+0.00241226684607314 * f[(i - 4) * fsi] - 0.0224309731704841 * f[(i - 3) * fsi] +
	0.0994147160548181 * f[(i - 2) * fsi] - 0.305415597057829 * f[(i - 1) * fsi] +
	1.10360481673061 * f[(i + 0) * fsi] + 0.149279825568669 * f[(i + 1) * fsi] -
	0.0298515272297137 * f[(i + 2) * fsi] + 0.00298647225785693 * f[(i + 3) * fsi];
      f45 =
	-0.00298647225785693 * f[(i - 5) * fsi] + 0.0263040449089286 * f[(i - 4) * fsi] -
	0.106052196390478 * f[(i - 3) * fsi] + 0.266657162494806 * f[(i - 2) * fsi] -
	0.514468655107815 * f[(i - 1) * fsi] + 1.2708472631706 * f[(i + 0) * fsi] +
	0.0656586023486744 * f[(i + 1) * fsi] - 0.00595974916685827 * f[(i + 2) * fsi];
      f46 =
	+0.00595974916685827 * f[(i - 6) * fsi] - 0.0506644655927231 * f[(i - 5) * fsi] +
	0.19317702158096 * f[(i - 4) * fsi] - 0.439798149734541 * f[(i - 3) * fsi] +
	0.683839604174885 * f[(i - 2) * fsi] - 0.848214608451878 * f[(i - 1) * fsi] +
	1.43772023984263 * f[(i + 0) * fsi] + 0.0179806090138082 * f[(i + 1) * fsi];
      f47 =
	-0.0179806090138082 * f[(i - 7) * fsi] + 0.149804621277324 * f[(i - 6) * fsi] -
	0.554121517979353 * f[(i - 5) * fsi] + 1.20009112635422 * f[(i - 4) * fsi] -
	1.69844078070112 * f[(i - 3) * fsi] + 1.69075370894815 * f[(i - 2) * fsi] -
	1.35167166083851 * f[(i - 1) * fsi] + 1.5815651119531 * f[(i + 0) * fsi];
      f48 =
	+0.201733269430084 * f[(i + 0) * fsi] + 1.75383617114764 * f[(i + 1) * fsi] -
	2.09455769794327 * f[(i + 2) * fsi] + 2.10974451840947 * f[(i + 3) * fsi] -
	1.50232692597027 * f[(i + 4) * fsi] + 0.698651387908859 * f[(i + 5) * fsi] -
	0.189994733431607 * f[(i + 6) * fsi] + 0.0229140104491079 * f[(i + 7) * fsi];
      f49 =
	-0.022914010449108 * f[(i - 1) * fsi] + 0.385045353022948 * f[(i + 0) * fsi] +
	1.11224387857261 * f[(i + 1) * fsi] - 0.811373112793229 * f[(i + 2) * fsi] +
	0.505763786971908 * f[(i + 3) * fsi] - 0.21914234082022 * f[(i + 4) * fsi] +
	0.0570590953338357 * f[(i + 5) * fsi] - 0.00668264983874412 * f[(i + 6) * fsi];
      f50 =
	+0.00668264983874412 * f[(i - 2) * fsi] - 0.076375209159061 * f[(i - 1) * fsi] +
	0.572159548507783 * f[(i + 0) * fsi] + 0.738015487602941 * f[(i + 1) * fsi] -
	0.343587624081141 * f[(i + 2) * fsi] + 0.131535396002236 * f[(i + 3) * fsi] -
	0.0320281453353849 * f[(i + 4) * fsi] + 0.00359789662388271 * f[(i + 5) * fsi];
      f51 =
	-0.00359789662388271 * f[(i - 3) * fsi] + 0.0354658228298058 * f[(i - 2) * fsi] -
	0.177116314627777 * f[(i - 1) * fsi] + 0.773641759445215 * f[(i + 0) * fsi] +
	0.486162723931152 * f[(i + 1) * fsi] - 0.14210541314371 * f[(i + 2) * fsi] +
	0.0307942905335204 * f[(i + 3) * fsi] - 0.00324497234432325 * f[(i + 4) * fsi];
      f52 =
	+0.00324497234432326 * f[(i - 4) * fsi] - 0.0295576753784687 * f[(i - 3) * fsi] +
	0.126325048470857 * f[(i - 2) * fsi] - 0.358834765909879 * f[(i - 1) * fsi] +
	1.00078982354784 * f[(i + 0) * fsi] + 0.304444272649049 * f[(i + 1) * fsi] -
	0.0512461875026587 * f[(i + 2) * fsi] + 0.00483451177893436 * f[(i + 3) * fsi];
      f53 =
	-0.00483451177893436 * f[(i - 5) * fsi] + 0.0419210665757981 * f[(i - 4) * fsi] -
	0.164924005188631 * f[(i - 3) * fsi] + 0.397057708091181 * f[(i - 2) * fsi] -
	0.697250590435284 * f[(i - 1) * fsi] + 1.27152248316817 * f[(i + 0) * fsi] +
	0.169077942838887 * f[(i + 1) * fsi] - 0.0125700932711838 * f[(i + 2) * fsi];
      f54 =
	+0.0125700932711838 * f[(i - 6) * fsi] - 0.105395257948405 * f[(i - 5) * fsi] +
	0.393883678168945 * f[(i - 4) * fsi] - 0.868849228374924 * f[(i - 3) * fsi] +
	1.27696423707405 * f[(i - 2) * fsi] - 1.40117581362158 * f[(i - 1) * fsi] +
	1.62348509476131 * f[(i + 0) * fsi] + 0.0685171966694168 * f[(i + 1) * fsi];
      f55 =
	-0.0685171966694168 * f[(i - 7) * fsi] + 0.560707666626518 * f[(i - 6) * fsi] -
	2.02387676469207 * f[(i - 5) * fsi] + 4.23084669165628 * f[(i - 4) * fsi] -
	5.6650529952341 * f[(i - 3) * fsi] + 5.11392725056139 * f[(i - 2) * fsi] -
	3.31965732036525 * f[(i - 1) * fsi] + 2.17162266811665 * f[(i + 0) * fsi];
      f56 =
	+0.138260824930636 * f[(i + 0) * fsi] + 1.73009897266673 * f[(i + 1) * fsi] -
	1.84982257905378 * f[(i + 2) * fsi] + 1.7997490716488 * f[(i + 3) * fsi] -
	1.26128858146348 * f[(i + 4) * fsi] + 0.581296067269122 * f[(i + 5) * fsi] -
	0.157174320237652 * f[(i + 6) * fsi] + 0.0188805442396301 * f[(i + 7) * fsi];
      f57 =
	-0.01888054423963 * f[(i - 1) * fsi] + 0.289305178847677 * f[(i + 0) * fsi] +
	1.20144373395708 * f[(i + 1) * fsi] - 0.792512101634495 * f[(i + 2) * fsi] +
	0.478110974874681 * f[(i + 3) * fsi] - 0.203978104044183 * f[(i + 4) * fsi] +
	0.0526408285594817 * f[(i + 5) * fsi] - 0.00612996632061194 * f[(i + 6) * fsi];
      f58 =
	+0.00612996632061195 * f[(i - 2) * fsi] - 0.0679202748045257 * f[(i - 1) * fsi] +
	0.460944235824812 * f[(i + 0) * fsi] + 0.858165620002811 * f[(i + 1) * fsi] -
	0.363414459191658 * f[(i + 2) * fsi] + 0.134832860920412 * f[(i + 3) * fsi] -
	0.0323390470670485 * f[(i + 4) * fsi] + 0.00360109799458602 * f[(i + 5) * fsi];
      f59 =
	-0.00360109799458603 * f[(i - 3) * fsi] + 0.0349387502773002 * f[(i - 2) * fsi] -
	0.168751018652934 * f[(i - 1) * fsi] + 0.662605723521629 * f[(i + 0) * fsi] +
	0.60608876038179 * f[(i + 1) * fsi] - 0.161752971494841 * f[(i + 2) * fsi] +
	0.0340021170720031 * f[(i + 3) * fsi] - 0.00353026311036027 * f[(i + 4) * fsi];
      f60 =
	+0.00353026311036026 * f[(i - 4) * fsi] - 0.0318432028774682 * f[(i - 3) * fsi] +
	0.133786117367388 * f[(i - 2) * fsi] - 0.366445752833109 * f[(i - 1) * fsi] +
	0.909724141246848 * f[(i + 0) * fsi] + 0.408394026201615 * f[(i + 1) * fsi] -
	0.0629056044047535 * f[(i + 2) * fsi] + 0.00576001218912098 * f[(i + 3) * fsi];
      f61 =
	-0.00576001218912098 * f[(i - 5) * fsi] + 0.0496103606233281 * f[(i - 4) * fsi] -
	0.193123544172856 * f[(i - 3) * fsi] + 0.456346799958163 * f[(i - 2) * fsi] -
	0.769646606071578 * f[(i - 1) * fsi] + 1.23228482383762 * f[(i + 0) * fsi] +
	0.247113684906227 * f[(i + 1) * fsi] - 0.0168255068917857 * f[(i + 2) * fsi];
      f62 =
	+0.0168255068917857 * f[(i - 6) * fsi] - 0.140364067323406 * f[(i - 5) * fsi] +
	0.520724553593327 * f[(i - 4) * fsi] - 1.13535193011285 * f[(i - 3) * fsi] +
	1.63413228238316 * f[(i - 2) * fsi] - 1.71187499201158 * f[(i - 1) * fsi] +
	1.70339901680762 * f[(i + 0) * fsi] + 0.112509629771942 * f[(i + 1) * fsi];
      f63 =
	-0.112509629771942 * f[(i - 7) * fsi] + 0.916902545067321 * f[(i - 6) * fsi] -
	3.29063370093778 * f[(i - 5) * fsi] + 6.82126382082207 * f[(i - 4) * fsi] -
	9.01102601414879 * f[(i - 3) * fsi] + 7.93467154961191 * f[(i - 2) * fsi] -
	4.86214462562595 * f[(i - 1) * fsi] + 2.60347605498316 * f[(i + 0) * fsi];
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
	+2.23073251131246 * (f24 * omega24p + f25 * omega25p + f26 * omega26p + f27 * omega27p +
			     f28 * omega28p + f29 * omega29p + f30 * omega30p + f31 * omega31p) -
	+1.23073251131246 * (f24 * omega24m + f25 * omega25m + f26 * omega26m + f27 * omega27m +
			     f28 * omega28m + f29 * omega29m + f30 * omega30m + f31 * omega31m);
      fr4 =
	+2.23073251131247 * (f32 * omega32p + f33 * omega33p + f34 * omega34p + f35 * omega35p +
			     f36 * omega36p + f37 * omega37p + f38 * omega38p + f39 * omega39p) -
	+1.23073251131247 * (f32 * omega32m + f33 * omega33m + f34 * omega34m + f35 * omega35m +
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
py_gauss_legendre008008 (PyObject * self, PyObject * args)
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

  gauss_legendre008008 (f, n, fsi, sigma, ssi, ssr, fr, frsi, frsl);

  Py_INCREF (Py_None);
  return Py_None;
}
