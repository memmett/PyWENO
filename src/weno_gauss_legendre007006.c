#include <Python.h>
#include <numpy/ndarrayobject.h>

void
gauss_legendre007006 (const double *restrict f, int n, int fsi,
		      const double *restrict sigma, int ssi, int ssr,
		      double *restrict fr, int frsi, int frsl)
{
  int i;
  double sigma0, sigma1, sigma2, sigma3, sigma4, sigma5, sigma6, omega10, omega41, omega18m,
    omega24m, omega13, omega25m, omega17p, omega36, omega24p, omega3, omega16p, omega17m, omega28,
    omega9, omega18p, omega40, omega32, omega12, omega14m, omega4, omega33, omega29, omega14p,
    omega23p, omega26m, omega39, omega0, omega22m, omega35, omega23m, omega19p, omega22p, omega20m,
    omega11, omega19m, omega20p, omega5, omega25p, omega30, omega7, omega27p, omega38, omega1,
    omega27m, omega15p, omega34, omega26p, omega16m, omega15m, omega8, omega6, omega21p, omega31,
    omega21m, omega37, omega2, accumulator, f10, f21, f39, f15, f41, f20, f13, f36, f19, f3, f28,
    f9, f24, f14, f32, f12, f27, f16, f38, f29, f8, f23, f0, f35, f33, f4, f40, f11, f17, f30, f7,
    f26, f1, f34, f37, f22, f2, f6, f31, f5, f25, f18, fr0, fr1, fr2, fr3, fr4, fr5;
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
      omega0 = +0.000688485629242954 / (1.0e-6 + sigma0) / (1.0e-6 + sigma0);
      accumulator += omega0;
      omega1 = +0.0267381457721216 / (1.0e-6 + sigma1) / (1.0e-6 + sigma1);
      accumulator += omega1;
      omega2 = +0.191606746235193 / (1.0e-6 + sigma2) / (1.0e-6 + sigma2);
      accumulator += omega2;
      omega3 = +0.410632339698374 / (1.0e-6 + sigma3) / (1.0e-6 + sigma3);
      accumulator += omega3;
      omega4 = +0.297734470167407 / (1.0e-6 + sigma4) / (1.0e-6 + sigma4);
      accumulator += omega4;
      omega5 = +0.0689372413724022 / (1.0e-6 + sigma5) / (1.0e-6 + sigma5);
      accumulator += omega5;
      omega6 = +0.00366257112525836 / (1.0e-6 + sigma6) / (1.0e-6 + sigma6);
      accumulator += omega6;
      omega0 /= accumulator;
      omega1 /= accumulator;
      omega2 /= accumulator;
      omega3 /= accumulator;
      omega4 /= accumulator;
      omega5 /= accumulator;
      omega6 /= accumulator;
      accumulator = 0.0;
      omega7 = +0.00147511461828889 / (1.0e-6 + sigma0) / (1.0e-6 + sigma0);
      accumulator += omega7;
      omega8 = +0.0390539070293413 / (1.0e-6 + sigma1) / (1.0e-6 + sigma1);
      accumulator += omega8;
      omega9 = +0.22737737000657 / (1.0e-6 + sigma2) / (1.0e-6 + sigma2);
      accumulator += omega9;
      omega10 = +0.415979380252612 / (1.0e-6 + sigma3) / (1.0e-6 + sigma3);
      accumulator += omega10;
      omega11 = +0.26152727669427 / (1.0e-6 + sigma4) / (1.0e-6 + sigma4);
      accumulator += omega11;
      omega12 = +0.0522663425874501 / (1.0e-6 + sigma5) / (1.0e-6 + sigma5);
      accumulator += omega12;
      omega13 = +0.00232060881146892 / (1.0e-6 + sigma6) / (1.0e-6 + sigma6);
      accumulator += omega13;
      omega7 /= accumulator;
      omega8 /= accumulator;
      omega9 /= accumulator;
      omega10 /= accumulator;
      omega11 /= accumulator;
      omega12 /= accumulator;
      omega13 /= accumulator;
      accumulator = 0.0;
      omega14p = +0.00278166732257204 / +2.00834500196772 / (1.0e-6 + sigma0) / (1.0e-6 + sigma0);
      accumulator += omega14p;
      omega15p = +0.470150255058578 / +2.00834500196772 / (1.0e-6 + sigma1) / (1.0e-6 + sigma1);
      accumulator += omega15p;
      omega16p = +0.461965013374552 / +2.00834500196772 / (1.0e-6 + sigma2) / (1.0e-6 + sigma2);
      accumulator += omega16p;
      omega17p = +0.698905127866605 / +2.00834500196772 / (1.0e-6 + sigma3) / (1.0e-6 + sigma3);
      accumulator += omega17p;
      omega18p = +0.324323098652355 / +2.00834500196772 / (1.0e-6 + sigma4) / (1.0e-6 + sigma4);
      accumulator += omega18p;
      omega19p = +0.0486629034997807 / +2.00834500196772 / (1.0e-6 + sigma5) / (1.0e-6 + sigma5);
      accumulator += omega19p;
      omega20p = +0.00155693619327271 / +2.00834500196772 / (1.0e-6 + sigma6) / (1.0e-6 + sigma6);
      accumulator += omega20p;
      omega14p /= accumulator;
      omega15p /= accumulator;
      omega16p /= accumulator;
      omega17p /= accumulator;
      omega18p /= accumulator;
      omega19p /= accumulator;
      omega20p /= accumulator;
      accumulator = 0.0;
      omega14m = +0.00556333464514409 / +1.00834500196772 / (1.0e-6 + sigma0) / (1.0e-6 + sigma0);
      accumulator += omega14m;
      omega15m = +0.235075127529289 / +1.00834500196772 / (1.0e-6 + sigma1) / (1.0e-6 + sigma1);
      accumulator += omega15m;
      omega16m = +0.230982506687276 / +1.00834500196772 / (1.0e-6 + sigma2) / (1.0e-6 + sigma2);
      accumulator += omega16m;
      omega17m = +0.349452563933303 / +1.00834500196772 / (1.0e-6 + sigma3) / (1.0e-6 + sigma3);
      accumulator += omega17m;
      omega18m = +0.162161549326178 / +1.00834500196772 / (1.0e-6 + sigma4) / (1.0e-6 + sigma4);
      accumulator += omega18m;
      omega19m = +0.0243314517498904 / +1.00834500196772 / (1.0e-6 + sigma5) / (1.0e-6 + sigma5);
      accumulator += omega19m;
      omega20m = +0.000778468096636354 / +1.00834500196772 / (1.0e-6 + sigma6) / (1.0e-6 + sigma6);
      accumulator += omega20m;
      omega14m /= accumulator;
      omega15m /= accumulator;
      omega16m /= accumulator;
      omega17m /= accumulator;
      omega18m /= accumulator;
      omega19m /= accumulator;
      omega20m /= accumulator;
      accumulator = 0.0;
      omega21p = +0.00155693619324066 / +2.00834500196769 / (1.0e-6 + sigma0) / (1.0e-6 + sigma0);
      accumulator += omega21p;
      omega22p = +0.0486629034998542 / +2.00834500196769 / (1.0e-6 + sigma1) / (1.0e-6 + sigma1);
      accumulator += omega22p;
      omega23p = +0.324323098652296 / +2.00834500196769 / (1.0e-6 + sigma2) / (1.0e-6 + sigma2);
      accumulator += omega23p;
      omega24p = +0.698905127866624 / +2.00834500196769 / (1.0e-6 + sigma3) / (1.0e-6 + sigma3);
      accumulator += omega24p;
      omega25p = +0.461965013374469 / +2.00834500196769 / (1.0e-6 + sigma4) / (1.0e-6 + sigma4);
      accumulator += omega25p;
      omega26p = +0.470150255058643 / +2.00834500196769 / (1.0e-6 + sigma5) / (1.0e-6 + sigma5);
      accumulator += omega26p;
      omega27p = +0.00278166732256489 / +2.00834500196769 / (1.0e-6 + sigma6) / (1.0e-6 + sigma6);
      accumulator += omega27p;
      omega21p /= accumulator;
      omega22p /= accumulator;
      omega23p /= accumulator;
      omega24p /= accumulator;
      omega25p /= accumulator;
      omega26p /= accumulator;
      omega27p /= accumulator;
      accumulator = 0.0;
      omega21m = +0.000778468096620329 / +1.00834500196769 / (1.0e-6 + sigma0) / (1.0e-6 + sigma0);
      accumulator += omega21m;
      omega22m = +0.0243314517499271 / +1.00834500196769 / (1.0e-6 + sigma1) / (1.0e-6 + sigma1);
      accumulator += omega22m;
      omega23m = +0.162161549326148 / +1.00834500196769 / (1.0e-6 + sigma2) / (1.0e-6 + sigma2);
      accumulator += omega23m;
      omega24m = +0.349452563933312 / +1.00834500196769 / (1.0e-6 + sigma3) / (1.0e-6 + sigma3);
      accumulator += omega24m;
      omega25m = +0.230982506687234 / +1.00834500196769 / (1.0e-6 + sigma4) / (1.0e-6 + sigma4);
      accumulator += omega25m;
      omega26m = +0.235075127529321 / +1.00834500196769 / (1.0e-6 + sigma5) / (1.0e-6 + sigma5);
      accumulator += omega26m;
      omega27m = +0.00556333464512978 / +1.00834500196769 / (1.0e-6 + sigma6) / (1.0e-6 + sigma6);
      accumulator += omega27m;
      omega21m /= accumulator;
      omega22m /= accumulator;
      omega23m /= accumulator;
      omega24m /= accumulator;
      omega25m /= accumulator;
      omega26m /= accumulator;
      omega27m /= accumulator;
      accumulator = 0.0;
      omega28 = +0.00232060881146036 / (1.0e-6 + sigma0) / (1.0e-6 + sigma0);
      accumulator += omega28;
      omega29 = +0.0522663425874773 / (1.0e-6 + sigma1) / (1.0e-6 + sigma1);
      accumulator += omega29;
      omega30 = +0.261527276694248 / (1.0e-6 + sigma2) / (1.0e-6 + sigma2);
      accumulator += omega30;
      omega31 = +0.415979380252615 / (1.0e-6 + sigma3) / (1.0e-6 + sigma3);
      accumulator += omega31;
      omega32 = +0.22737737000657 / (1.0e-6 + sigma4) / (1.0e-6 + sigma4);
      accumulator += omega32;
      omega33 = +0.0390539070293406 / (1.0e-6 + sigma5) / (1.0e-6 + sigma5);
      accumulator += omega33;
      omega34 = +0.00147511461828939 / (1.0e-6 + sigma6) / (1.0e-6 + sigma6);
      accumulator += omega34;
      omega28 /= accumulator;
      omega29 /= accumulator;
      omega30 /= accumulator;
      omega31 /= accumulator;
      omega32 /= accumulator;
      omega33 /= accumulator;
      omega34 /= accumulator;
      accumulator = 0.0;
      omega35 = +0.00366257112533316 / (1.0e-6 + sigma0) / (1.0e-6 + sigma0);
      accumulator += omega35;
      omega36 = +0.068937241372317 / (1.0e-6 + sigma1) / (1.0e-6 + sigma1);
      accumulator += omega36;
      omega37 = +0.297734470167453 / (1.0e-6 + sigma2) / (1.0e-6 + sigma2);
      accumulator += omega37;
      omega38 = +0.410632339698363 / (1.0e-6 + sigma3) / (1.0e-6 + sigma3);
      accumulator += omega38;
      omega39 = +0.191606746235192 / (1.0e-6 + sigma4) / (1.0e-6 + sigma4);
      accumulator += omega39;
      omega40 = +0.0267381457721243 / (1.0e-6 + sigma5) / (1.0e-6 + sigma5);
      accumulator += omega40;
      omega41 = +0.000688485629242034 / (1.0e-6 + sigma6) / (1.0e-6 + sigma6);
      accumulator += omega41;
      omega35 /= accumulator;
      omega36 /= accumulator;
      omega37 /= accumulator;
      omega38 /= accumulator;
      omega39 /= accumulator;
      omega40 /= accumulator;
      omega41 /= accumulator;
      f0 =
	+2.42143686151671 * f[(i + 0) * fsi] - 3.84949074030847 * f[(i + 1) * fsi] +
	5.22161580785208 * f[(i + 2) * fsi] - 4.73749576249414 * f[(i + 3) * fsi] +
	2.68745884246076 * f[(i + 4) * fsi] - 0.863826339303762 * f[(i + 5) * fsi] +
	0.120301330276821 * f[(i + 6) * fsi];
      f1 =
	+0.120301330276821 * f[(i - 1) * fsi] + 1.57932754957896 * f[(i + 0) * fsi] -
	1.32316280449523 * f[(i + 1) * fsi] + 1.01106924816335 * f[(i + 2) * fsi] -
	0.5269492028054 * f[(i + 3) * fsi] + 0.161130906647515 * f[(i + 4) * fsi] -
	0.021717027366015 * f[(i + 5) * fsi];
      f2 =
	-0.021717027366015 * f[(i - 2) * fsi] + 0.272320521838926 * f[(i - 1) * fsi] +
	1.12326997489265 * f[(i + 0) * fsi] - 0.563066846684704 * f[(i + 1) * fsi] +
	0.25097329035282 * f[(i + 2) * fsi] - 0.0708916281190851 * f[(i + 3) * fsi] +
	0.00911171508540965 * f[(i + 4) * fsi];
      f3 =
	+0.00911171508540965 * f[(i - 3) * fsi] - 0.0854990329638825 * f[(i - 2) * fsi] +
	0.463666538632529 * f[(i - 1) * fsi] + 0.80435994690331 * f[(i + 0) * fsi] -
	0.244156818695367 * f[(i + 1) * fsi] + 0.0596272735592179 * f[(i + 2) * fsi] -
	0.00710962252121759 * f[(i + 3) * fsi];
      f4 =
	-0.00710962252121759 * f[(i - 4) * fsi] + 0.0588790727339328 * f[(i - 3) * fsi] -
	0.234801105909452 * f[(i - 2) * fsi] + 0.712503326875144 * f[(i - 1) * fsi] +
	0.555523158660695 * f[(i + 0) * fsi] - 0.0948547457497972 * f[(i + 1) * fsi] +
	0.00985991591069483 * f[(i + 2) * fsi];
      f5 =
	+0.00985991591069483 * f[(i - 5) * fsi] - 0.0761290338960814 * f[(i - 4) * fsi] +
	0.265937306858524 * f[(i - 3) * fsi] - 0.579898162783771 * f[(i - 2) * fsi] +
	1.05760038374946 * f[(i - 1) * fsi] + 0.348464924536104 * f[(i + 0) * fsi] -
	0.0258353343749335 * f[(i + 1) * fsi];
      f6 =
	-0.0258353343749335 * f[(i - 6) * fsi] + 0.190707256535229 * f[(i - 5) * fsi] -
	0.618671055769684 * f[(i - 4) * fsi] + 1.1701740099812 * f[(i - 3) * fsi] -
	1.48413486590644 * f[(i - 2) * fsi] + 1.60014240562307 * f[(i - 1) * fsi] +
	0.167617583911569 * f[(i + 0) * fsi];
      f7 =
	+1.81843261781862 * f[(i + 0) * fsi] - 1.97098777752367 * f[(i + 1) * fsi] +
	2.3828640039035 * f[(i + 2) * fsi] - 2.05561009854 * f[(i + 3) * fsi] +
	1.13434365786589 * f[(i + 4) * fsi] - 0.358365161786001 * f[(i + 5) * fsi] +
	0.0493227582616641 * f[(i + 6) * fsi];
      f8 =
	+0.0493227582616641 * f[(i - 1) * fsi] + 1.47317330998697 * f[(i + 0) * fsi] -
	0.935209854028727 * f[(i + 1) * fsi] + 0.65656746474526 * f[(i + 2) * fsi] -
	0.329313559381756 * f[(i + 3) * fsi] + 0.0985657343709419 * f[(i + 4) * fsi] -
	0.0131058539543521 * f[(i + 5) * fsi];
      f9 =
	-0.0131058539543521 * f[(i - 2) * fsi] + 0.141063735942129 * f[(i - 1) * fsi] +
	1.19795037694558 * f[(i + 0) * fsi] - 0.476504965626403 * f[(i + 1) * fsi] +
	0.197862576342936 * f[(i + 2) * fsi] - 0.0540906263403619 * f[(i + 3) * fsi] +
	0.00682475669047717 * f[(i + 4) * fsi];
      f10 =
	+0.00682475669047717 * f[(i - 3) * fsi] - 0.0608791507876923 * f[(i - 2) * fsi] +
	0.284383626442149 * f[(i - 1) * fsi] + 0.959083892778874 * f[(i + 0) * fsi] -
	0.237638481459702 * f[(i + 1) * fsi] + 0.0545426858429158 * f[(i + 2) * fsi] -
	0.00631732950702171 * f[(i + 3) * fsi];
      f11 =
	-0.00631732950702171 * f[(i - 4) * fsi] + 0.0510460632396291 * f[(i - 3) * fsi] -
	0.193543070435148 * f[(i - 2) * fsi] + 0.505490159187909 * f[(i - 1) * fsi] +
	0.737977360033114 * f[(i + 0) * fsi] - 0.104974561812247 * f[(i + 1) * fsi] +
	0.0103213792937638 * f[(i + 2) * fsi];
      f12 =
	+0.0103213792937638 * f[(i - 5) * fsi] - 0.0785669845633686 * f[(i - 4) * fsi] +
	0.26779502840867 * f[(i - 3) * fsi] - 0.554791345716882 * f[(i - 2) * fsi] +
	0.866738434469643 * f[(i - 1) * fsi] + 0.521228394864074 * f[(i + 0) * fsi] -
	0.0327249067558997 * f[(i + 1) * fsi];
      f13 =
	-0.0327249067558997 * f[(i - 6) * fsi] + 0.239395726585062 * f[(i - 5) * fsi] -
	0.765790026437262 * f[(i - 4) * fsi] + 1.41316676486516 * f[(i - 3) * fsi] -
	1.70016308217337 * f[(i - 2) * fsi] + 1.55396147634354 * f[(i - 1) * fsi] +
	0.292154047572776 * f[(i + 0) * fsi];
      f14 =
	+1.11358942209243 * f[(i + 0) * fsi] - 0.0100107259387094 * f[(i + 1) * fsi] -
	0.316409292801657 * f[(i + 2) * fsi] + 0.388006408308962 * f[(i + 3) * fsi] -
	0.247644055558265 * f[(i + 4) * fsi] + 0.0847327475768467 * f[(i + 5) * fsi] -
	0.0122645036796067 * f[(i + 6) * fsi];
      f15 =
	-0.0122645036796067 * f[(i - 1) * fsi] + 1.19944094784967 * f[(i + 0) * fsi] -
	0.26756530321045 * f[(i + 1) * fsi] + 0.11284833598458 * f[(i + 2) * fsi] -
	0.0412512204772733 * f[(i + 3) * fsi] + 0.00991052171347739 * f[(i + 4) * fsi] -
	0.00111877818040088 * f[(i + 5) * fsi];
      f16 =
	-0.00111877818040088 * f[(i - 2) * fsi] - 0.00443305641680063 * f[(i - 1) * fsi] +
	1.17594660606126 * f[(i + 0) * fsi] - 0.228408066896419 * f[(i + 1) * fsi] +
	0.0736910996705492 * f[(i + 2) * fsi] - 0.0177568786888549 * f[(i + 3) * fsi] +
	0.00207907445067121 * f[(i + 4) * fsi];
      f17 =
	+0.00207907445067121 * f[(i - 3) * fsi] - 0.0156722993350993 * f[(i - 2) * fsi] +
	0.0392275070472948 * f[(i - 1) * fsi] + 1.10317900028776 * f[(i + 0) * fsi] -
	0.155640461122927 * f[(i + 1) * fsi] + 0.0300305362064538 * f[(i + 2) * fsi] -
	0.00320335753415645 * f[(i + 3) * fsi];
      f18 =
	-0.00320335753415645 * f[(i - 4) * fsi] + 0.0245025771897663 * f[(i - 3) * fsi] -
	0.0829428075523848 * f[(i - 2) * fsi] + 0.15134502074277 * f[(i - 1) * fsi] +
	0.991061486592287 * f[(i + 0) * fsi] - 0.0883699529056415 * f[(i + 1) * fsi] +
	0.00760703346735866 * f[(i + 2) * fsi];
      f19 =
	+0.00760703346735866 * f[(i - 5) * fsi] - 0.0564525918056671 * f[(i - 4) * fsi] +
	0.184250280004298 * f[(i - 3) * fsi] - 0.349188978909938 * f[(i - 2) * fsi] +
	0.417591192100323 * f[(i - 1) * fsi] + 0.831313783777755 * f[(i + 0) * fsi] -
	0.0351207186341309 * f[(i + 1) * fsi];
      f20 =
	-0.0351207186341309 * f[(i - 6) * fsi] + 0.253452063906275 * f[(i - 5) * fsi] -
	0.793987683122417 * f[(i - 4) * fsi] + 1.41347543219888 * f[(i - 3) * fsi] -
	1.57841413110452 * f[(i - 2) * fsi] + 1.15512628341707 * f[(i - 1) * fsi] +
	0.585468753338839 * f[(i + 0) * fsi];
      f21 =
	+0.585468753338838 * f[(i + 0) * fsi] + 1.15512628341707 * f[(i + 1) * fsi] -
	1.57841413110452 * f[(i + 2) * fsi] + 1.41347543219888 * f[(i + 3) * fsi] -
	0.793987683122416 * f[(i + 4) * fsi] + 0.253452063906276 * f[(i + 5) * fsi] -
	0.0351207186341309 * f[(i + 6) * fsi];
      f22 =
	-0.0351207186341309 * f[(i - 1) * fsi] + 0.831313783777755 * f[(i + 0) * fsi] +
	0.417591192100324 * f[(i + 1) * fsi] - 0.349188978909938 * f[(i + 2) * fsi] +
	0.184250280004298 * f[(i + 3) * fsi] - 0.0564525918056671 * f[(i + 4) * fsi] +
	0.00760703346735866 * f[(i + 5) * fsi];
      f23 =
	+0.00760703346735866 * f[(i - 2) * fsi] - 0.0883699529056415 * f[(i - 1) * fsi] +
	0.991061486592287 * f[(i + 0) * fsi] + 0.151345020742771 * f[(i + 1) * fsi] -
	0.0829428075523848 * f[(i + 2) * fsi] + 0.0245025771897664 * f[(i + 3) * fsi] -
	0.00320335753415645 * f[(i + 4) * fsi];
      f24 =
	-0.00320335753415645 * f[(i - 3) * fsi] + 0.0300305362064538 * f[(i - 2) * fsi] -
	0.155640461122927 * f[(i - 1) * fsi] + 1.10317900028776 * f[(i + 0) * fsi] +
	0.0392275070472948 * f[(i + 1) * fsi] - 0.0156722993350993 * f[(i + 2) * fsi] +
	0.00207907445067121 * f[(i + 3) * fsi];
      f25 =
	+0.00207907445067121 * f[(i - 4) * fsi] - 0.0177568786888549 * f[(i - 3) * fsi] +
	0.0736910996705492 * f[(i - 2) * fsi] - 0.228408066896419 * f[(i - 1) * fsi] +
	1.17594660606126 * f[(i + 0) * fsi] - 0.00443305641680056 * f[(i + 1) * fsi] -
	0.00111877818040088 * f[(i + 2) * fsi];
      f26 =
	-0.00111877818040088 * f[(i - 5) * fsi] + 0.00991052171347738 * f[(i - 4) * fsi] -
	0.0412512204772734 * f[(i - 3) * fsi] + 0.11284833598458 * f[(i - 2) * fsi] -
	0.26756530321045 * f[(i - 1) * fsi] + 1.19944094784967 * f[(i + 0) * fsi] -
	0.0122645036796067 * f[(i + 1) * fsi];
      f27 =
	-0.0122645036796067 * f[(i - 6) * fsi] + 0.0847327475768463 * f[(i - 5) * fsi] -
	0.247644055558264 * f[(i - 4) * fsi] + 0.388006408308962 * f[(i - 3) * fsi] -
	0.316409292801656 * f[(i - 2) * fsi] - 0.0100107259387086 * f[(i - 1) * fsi] +
	1.11358942209243 * f[(i + 0) * fsi];
      f28 =
	+0.292154047572777 * f[(i + 0) * fsi] + 1.55396147634353 * f[(i + 1) * fsi] -
	1.70016308217337 * f[(i + 2) * fsi] + 1.41316676486516 * f[(i + 3) * fsi] -
	0.765790026437261 * f[(i + 4) * fsi] + 0.239395726585062 * f[(i + 5) * fsi] -
	0.0327249067558996 * f[(i + 6) * fsi];
      f29 =
	-0.0327249067558995 * f[(i - 1) * fsi] + 0.521228394864074 * f[(i + 0) * fsi] +
	0.866738434469644 * f[(i + 1) * fsi] - 0.554791345716882 * f[(i + 2) * fsi] +
	0.26779502840867 * f[(i + 3) * fsi] - 0.0785669845633685 * f[(i + 4) * fsi] +
	0.0103213792937638 * f[(i + 5) * fsi];
      f30 =
	+0.0103213792937638 * f[(i - 2) * fsi] - 0.104974561812247 * f[(i - 1) * fsi] +
	0.737977360033114 * f[(i + 0) * fsi] + 0.505490159187909 * f[(i + 1) * fsi] -
	0.193543070435148 * f[(i + 2) * fsi] + 0.0510460632396291 * f[(i + 3) * fsi] -
	0.00631732950702171 * f[(i + 4) * fsi];
      f31 =
	-0.00631732950702171 * f[(i - 3) * fsi] + 0.0545426858429158 * f[(i - 2) * fsi] -
	0.237638481459703 * f[(i - 1) * fsi] + 0.959083892778874 * f[(i + 0) * fsi] +
	0.284383626442149 * f[(i + 1) * fsi] - 0.0608791507876923 * f[(i + 2) * fsi] +
	0.00682475669047717 * f[(i + 3) * fsi];
      f32 =
	+0.00682475669047717 * f[(i - 4) * fsi] - 0.0540906263403619 * f[(i - 3) * fsi] +
	0.197862576342936 * f[(i - 2) * fsi] - 0.476504965626404 * f[(i - 1) * fsi] +
	1.19795037694558 * f[(i + 0) * fsi] + 0.141063735942129 * f[(i + 1) * fsi] -
	0.0131058539543521 * f[(i + 2) * fsi];
      f33 =
	-0.0131058539543521 * f[(i - 5) * fsi] + 0.0985657343709419 * f[(i - 4) * fsi] -
	0.329313559381756 * f[(i - 3) * fsi] + 0.65656746474526 * f[(i - 2) * fsi] -
	0.935209854028727 * f[(i - 1) * fsi] + 1.47317330998697 * f[(i + 0) * fsi] +
	0.0493227582616641 * f[(i + 1) * fsi];
      f34 =
	+0.0493227582616641 * f[(i - 6) * fsi] - 0.358365161786001 * f[(i - 5) * fsi] +
	1.13434365786589 * f[(i - 4) * fsi] - 2.05561009854 * f[(i - 3) * fsi] +
	2.3828640039035 * f[(i - 2) * fsi] - 1.97098777752367 * f[(i - 1) * fsi] +
	1.81843261781862 * f[(i + 0) * fsi];
      f35 =
	+0.167617583911569 * f[(i + 0) * fsi] + 1.60014240562306 * f[(i + 1) * fsi] -
	1.48413486590644 * f[(i + 2) * fsi] + 1.1701740099812 * f[(i + 3) * fsi] -
	0.618671055769685 * f[(i + 4) * fsi] + 0.190707256535229 * f[(i + 5) * fsi] -
	0.0258353343749335 * f[(i + 6) * fsi];
      f36 =
	-0.0258353343749335 * f[(i - 1) * fsi] + 0.348464924536103 * f[(i + 0) * fsi] +
	1.05760038374946 * f[(i + 1) * fsi] - 0.579898162783771 * f[(i + 2) * fsi] +
	0.265937306858525 * f[(i + 3) * fsi] - 0.0761290338960813 * f[(i + 4) * fsi] +
	0.00985991591069485 * f[(i + 5) * fsi];
      f37 =
	+0.00985991591069484 * f[(i - 2) * fsi] - 0.0948547457497973 * f[(i - 1) * fsi] +
	0.555523158660695 * f[(i + 0) * fsi] + 0.712503326875144 * f[(i + 1) * fsi] -
	0.234801105909452 * f[(i + 2) * fsi] + 0.0588790727339328 * f[(i + 3) * fsi] -
	0.00710962252121759 * f[(i + 4) * fsi];
      f38 =
	-0.00710962252121759 * f[(i - 3) * fsi] + 0.0596272735592179 * f[(i - 2) * fsi] -
	0.244156818695367 * f[(i - 1) * fsi] + 0.80435994690331 * f[(i + 0) * fsi] +
	0.463666538632529 * f[(i + 1) * fsi] - 0.0854990329638825 * f[(i + 2) * fsi] +
	0.00911171508540964 * f[(i + 3) * fsi];
      f39 =
	+0.00911171508540965 * f[(i - 4) * fsi] - 0.0708916281190851 * f[(i - 3) * fsi] +
	0.250973290352821 * f[(i - 2) * fsi] - 0.563066846684704 * f[(i - 1) * fsi] +
	1.12326997489265 * f[(i + 0) * fsi] + 0.272320521838926 * f[(i + 1) * fsi] -
	0.021717027366015 * f[(i + 2) * fsi];
      f40 =
	-0.021717027366015 * f[(i - 5) * fsi] + 0.161130906647515 * f[(i - 4) * fsi] -
	0.5269492028054 * f[(i - 3) * fsi] + 1.01106924816335 * f[(i - 2) * fsi] -
	1.32316280449523 * f[(i - 1) * fsi] + 1.57932754957896 * f[(i + 0) * fsi] +
	0.120301330276821 * f[(i + 1) * fsi];
      f41 =
	+0.120301330276821 * f[(i - 6) * fsi] - 0.863826339303763 * f[(i - 5) * fsi] +
	2.68745884246076 * f[(i - 4) * fsi] - 4.73749576249414 * f[(i - 3) * fsi] +
	5.22161580785208 * f[(i - 2) * fsi] - 3.84949074030847 * f[(i - 1) * fsi] +
	2.42143686151671 * f[(i + 0) * fsi];
      fr0 =
	f0 * omega0 + f1 * omega1 + f2 * omega2 + f3 * omega3 + f4 * omega4 + f5 * omega5 +
	f6 * omega6;
      fr1 =
	f7 * omega7 + f8 * omega8 + f9 * omega9 + f10 * omega10 + f11 * omega11 + f12 * omega12 +
	f13 * omega13;
      fr2 =
	+2.00834500196772 * (f14 * omega14p + f15 * omega15p + f16 * omega16p + f17 * omega17p +
			     f18 * omega18p + f19 * omega19p + f20 * omega20p) -
	+1.00834500196772 * (f14 * omega14m + f15 * omega15m + f16 * omega16m + f17 * omega17m +
			     f18 * omega18m + f19 * omega19m + f20 * omega20m);
      fr3 =
	+2.00834500196769 * (f21 * omega21p + f22 * omega22p + f23 * omega23p + f24 * omega24p +
			     f25 * omega25p + f26 * omega26p + f27 * omega27p) -
	+1.00834500196769 * (f21 * omega21m + f22 * omega22m + f23 * omega23m + f24 * omega24m +
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
py_gauss_legendre007006 (PyObject * self, PyObject * args)
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

  gauss_legendre007006 (f, n, fsi, sigma, ssi, ssr, fr, frsi, frsl);

  Py_INCREF (Py_None);
  return Py_None;
}
