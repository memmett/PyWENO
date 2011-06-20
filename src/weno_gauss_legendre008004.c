#include <Python.h>
#include <numpy/ndarrayobject.h>

void
gauss_legendre008004 (const double *restrict f, int n, int fsi,
		      const double *restrict sigma, int ssi, int ssr,
		      double *restrict fr, int frsi, int frsl)
{
  int i;
  double sigma0, sigma1, sigma2, sigma3, sigma4, sigma5, sigma6, sigma7, omega23m, omega25, omega8p,
    omega11m, omega7, omega8m, omega11p, omega19p, omega31, omega3, omega18p, omega19m, omega20p,
    omega12p, omega27, omega15m, omega12m, omega15p, omega24, omega16m, omega4, omega10p, omega16p,
    omega10m, omega26, omega0, omega30, omega20m, omega21p, omega22m, omega21m, omega22p, omega5,
    omega14p, omega9m, omega14m, omega29, omega1, omega9p, omega17p, omega18m, omega17m, omega2,
    omega6, omega13m, omega23p, omega28, omega13p, accumulator, f11, f24, f7, f22, f14, f31, f21,
    f3, f10, f27, f16, f13, f30, f18, f9, f23, f26, f0, f4, f12, f19, f17, f8, f29, f1, f25, f2, f6,
    f15, f5, f28, f20, fr0, fr1, fr2, fr3;
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
      omega0 = +0.000224913325603482 / (1.0e-6 + sigma0) / (1.0e-6 + sigma0);
      accumulator += omega0;
      omega1 = +0.0106993584734208 / (1.0e-6 + sigma1) / (1.0e-6 + sigma1);
      accumulator += omega1;
      omega2 = +0.102432490936028 / (1.0e-6 + sigma2) / (1.0e-6 + sigma2);
      accumulator += omega2;
      omega3 = +0.318035552326206 / (1.0e-6 + sigma3) / (1.0e-6 + sigma3);
      accumulator += omega3;
      omega4 = +0.37318838491795 / (1.0e-6 + sigma4) / (1.0e-6 + sigma4);
      accumulator += omega4;
      omega5 = +0.168263343387249 / (1.0e-6 + sigma5) / (1.0e-6 + sigma5);
      accumulator += omega5;
      omega6 = +0.0261773360994467 / (1.0e-6 + sigma6) / (1.0e-6 + sigma6);
      accumulator += omega6;
      omega7 = +0.000978620534097347 / (1.0e-6 + sigma7) / (1.0e-6 + sigma7);
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
      omega8p = +0.0026669173456977 / +2.00800075203709 / (1.0e-6 + sigma0) / (1.0e-6 + sigma0);
      accumulator += omega8p;
      omega9p = +0.0910688208987362 / +2.00800075203709 / (1.0e-6 + sigma1) / (1.0e-6 + sigma1);
      accumulator += omega9p;
      omega10p = +0.346123757962068 / +2.00800075203709 / (1.0e-6 + sigma2) / (1.0e-6 + sigma2);
      accumulator += omega10p;
      omega11p = +0.718749539833487 / +2.00800075203709 / (1.0e-6 + sigma3) / (1.0e-6 + sigma3);
      accumulator += omega11p;
      omega12p = +0.615392342419793 / +2.00800075203709 / (1.0e-6 + sigma4) / (1.0e-6 + sigma4);
      accumulator += omega12p;
      omega13p = +0.209034330435424 / +2.00800075203709 / (1.0e-6 + sigma5) / (1.0e-6 + sigma5);
      accumulator += omega13p;
      omega14p = +0.0243267427366704 / +2.00800075203709 / (1.0e-6 + sigma6) / (1.0e-6 + sigma6);
      accumulator += omega14p;
      omega15p = +0.000638300405214925 / +2.00800075203709 / (1.0e-6 + sigma7) / (1.0e-6 + sigma7);
      accumulator += omega15p;
      omega8p /= accumulator;
      omega9p /= accumulator;
      omega10p /= accumulator;
      omega11p /= accumulator;
      omega12p /= accumulator;
      omega13p /= accumulator;
      omega14p /= accumulator;
      omega15p /= accumulator;
      accumulator = 0.0;
      omega8m = +0.00533383469139539 / +1.00800075203709 / (1.0e-6 + sigma0) / (1.0e-6 + sigma0);
      accumulator += omega8m;
      omega9m = +0.0455344104493681 / +1.00800075203709 / (1.0e-6 + sigma1) / (1.0e-6 + sigma1);
      accumulator += omega9m;
      omega10m = +0.173061878981034 / +1.00800075203709 / (1.0e-6 + sigma2) / (1.0e-6 + sigma2);
      accumulator += omega10m;
      omega11m = +0.359374769916744 / +1.00800075203709 / (1.0e-6 + sigma3) / (1.0e-6 + sigma3);
      accumulator += omega11m;
      omega12m = +0.307696171209897 / +1.00800075203709 / (1.0e-6 + sigma4) / (1.0e-6 + sigma4);
      accumulator += omega12m;
      omega13m = +0.104517165217712 / +1.00800075203709 / (1.0e-6 + sigma5) / (1.0e-6 + sigma5);
      accumulator += omega13m;
      omega14m = +0.0121633713683352 / +1.00800075203709 / (1.0e-6 + sigma6) / (1.0e-6 + sigma6);
      accumulator += omega14m;
      omega15m = +0.000319150202607463 / +1.00800075203709 / (1.0e-6 + sigma7) / (1.0e-6 + sigma7);
      accumulator += omega15m;
      omega8m /= accumulator;
      omega9m /= accumulator;
      omega10m /= accumulator;
      omega11m /= accumulator;
      omega12m /= accumulator;
      omega13m /= accumulator;
      omega14m /= accumulator;
      omega15m /= accumulator;
      accumulator = 0.0;
      omega16p = +0.000638300405016162 / +2.00800075203699 / (1.0e-6 + sigma0) / (1.0e-6 + sigma0);
      accumulator += omega16p;
      omega17p = +0.024326742736997 / +2.00800075203699 / (1.0e-6 + sigma1) / (1.0e-6 + sigma1);
      accumulator += omega17p;
      omega18p = +0.209034330435197 / +2.00800075203699 / (1.0e-6 + sigma2) / (1.0e-6 + sigma2);
      accumulator += omega18p;
      omega19p = +0.61539234241986 / +2.00800075203699 / (1.0e-6 + sigma3) / (1.0e-6 + sigma3);
      accumulator += omega19p;
      omega20p = +0.718749539833502 / +2.00800075203699 / (1.0e-6 + sigma4) / (1.0e-6 + sigma4);
      accumulator += omega20p;
      omega21p = +0.346123757962016 / +2.00800075203699 / (1.0e-6 + sigma5) / (1.0e-6 + sigma5);
      accumulator += omega21p;
      omega22p = +0.0910688208987234 / +2.00800075203699 / (1.0e-6 + sigma6) / (1.0e-6 + sigma6);
      accumulator += omega22p;
      omega23p = +0.00266691734567425 / +2.00800075203699 / (1.0e-6 + sigma7) / (1.0e-6 + sigma7);
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
      omega16m = +0.000319150202508081 / +1.008000752037 / (1.0e-6 + sigma0) / (1.0e-6 + sigma0);
      accumulator += omega16m;
      omega17m = +0.0121633713684985 / +1.008000752037 / (1.0e-6 + sigma1) / (1.0e-6 + sigma1);
      accumulator += omega17m;
      omega18m = +0.104517165217599 / +1.008000752037 / (1.0e-6 + sigma2) / (1.0e-6 + sigma2);
      accumulator += omega18m;
      omega19m = +0.30769617120993 / +1.008000752037 / (1.0e-6 + sigma3) / (1.0e-6 + sigma3);
      accumulator += omega19m;
      omega20m = +0.359374769916751 / +1.008000752037 / (1.0e-6 + sigma4) / (1.0e-6 + sigma4);
      accumulator += omega20m;
      omega21m = +0.173061878981008 / +1.008000752037 / (1.0e-6 + sigma5) / (1.0e-6 + sigma5);
      accumulator += omega21m;
      omega22m = +0.0455344104493617 / +1.008000752037 / (1.0e-6 + sigma6) / (1.0e-6 + sigma6);
      accumulator += omega22m;
      omega23m = +0.0053338346913485 / +1.008000752037 / (1.0e-6 + sigma7) / (1.0e-6 + sigma7);
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
      omega24 = +0.000978620533870462 / (1.0e-6 + sigma0) / (1.0e-6 + sigma0);
      accumulator += omega24;
      omega25 = +0.0261773360996929 / (1.0e-6 + sigma1) / (1.0e-6 + sigma1);
      accumulator += omega25;
      omega26 = +0.168263343387138 / (1.0e-6 + sigma2) / (1.0e-6 + sigma2);
      accumulator += omega26;
      omega27 = +0.373188384917968 / (1.0e-6 + sigma3) / (1.0e-6 + sigma3);
      accumulator += omega27;
      omega28 = +0.318035552326206 / (1.0e-6 + sigma4) / (1.0e-6 + sigma4);
      accumulator += omega28;
      omega29 = +0.102432490936025 / (1.0e-6 + sigma5) / (1.0e-6 + sigma5);
      accumulator += omega29;
      omega30 = +0.0106993584734244 / (1.0e-6 + sigma6) / (1.0e-6 + sigma6);
      accumulator += omega30;
      omega31 = +0.00022491332560213 / (1.0e-6 + sigma7) / (1.0e-6 + sigma7);
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
	+2.33443491186382 * f[(i + 0) * fsi] - 3.89258317108691 * f[(i + 1) * fsi] +
	6.15041894301244 * f[(i + 2) * fsi] - 6.88818367176462 * f[(i + 3) * fsi] +
	5.17498244112284 * f[(i + 4) * fsi] - 2.48469949133459 * f[(i + 5) * fsi] +
	0.69011443056867 * f[(i + 6) * fsi] - 0.0844843923816518 * f[(i + 7) * fsi];
      f1 =
	+0.0844843923816518 * f[(i - 1) * fsi] + 1.65855977281061 * f[(i + 0) * fsi] -
	1.52702018440066 * f[(i + 1) * fsi] + 1.41929296963994 * f[(i + 2) * fsi] -
	0.974276205048991 * f[(i + 3) * fsi] + 0.443856467750334 * f[(i + 4) * fsi] -
	0.119136504648338 * f[(i + 5) * fsi] + 0.0142392915154555 * f[(i + 6) * fsi];
      f2 =
	-0.0142392915154555 * f[(i - 2) * fsi] + 0.198398724505296 * f[(i - 1) * fsi] +
	1.25985961037785 * f[(i + 0) * fsi] - 0.729619859535148 * f[(i + 1) * fsi] +
	0.422542563558052 * f[(i + 2) * fsi] - 0.176875880183483 * f[(i + 3) * fsi] +
	0.04515630531758 * f[(i + 4) * fsi] - 0.00522217252469413 * f[(i + 5) * fsi];
      f3 =
	+0.00522217252469413 * f[(i - 3) * fsi] - 0.0560166717130086 * f[(i - 2) * fsi] +
	0.344619555196732 * f[(i - 1) * fsi] + 0.96741794899498 * f[(i + 0) * fsi] -
	0.364067782806558 * f[(i + 1) * fsi] + 0.130100902175181 * f[(i + 2) * fsi] -
	0.0306550494920469 * f[(i + 3) * fsi] + 0.00337892512002692 * f[(i + 4) * fsi];
      f4 =
	-0.00337892512002692 * f[(i - 4) * fsi] + 0.0322535734849095 * f[(i - 3) * fsi] -
	0.150626575073762 * f[(i - 2) * fsi] + 0.533839361918239 * f[(i - 1) * fsi] +
	0.730893190593096 * f[(i + 0) * fsi] - 0.174847976085051 * f[(i + 1) * fsi] +
	0.0354909988144272 * f[(i + 2) * fsi] - 0.0036236485318315 * f[(i + 3) * fsi];
      f5 =
	+0.0036236485318315 * f[(i - 5) * fsi] - 0.032368113374679 * f[(i - 4) * fsi] +
	0.133715732376192 * f[(i - 3) * fsi] - 0.353550892856327 * f[(i - 2) * fsi] +
	0.787494759146445 * f[(i - 1) * fsi] + 0.527968872810531 * f[(i + 0) * fsi] -
	0.0733858171937687 * f[(i + 1) * fsi] + 0.00650181055977517 * f[(i + 2) * fsi];
      f6 =
	-0.00650181055977517 * f[(i - 6) * fsi] + 0.0556381330100329 * f[(i - 5) * fsi] -
	0.214418809048384 * f[(i - 4) * fsi] + 0.497817123723601 * f[(i - 3) * fsi] -
	0.808677632040589 * f[(i - 2) * fsi] + 1.15159615049385 * f[(i - 1) * fsi] +
	0.345918177136827 * f[(i + 0) * fsi] - 0.0213713327155674 * f[(i + 1) * fsi];
      f7 =
	+0.0213713327155674 * f[(i - 7) * fsi] - 0.177472472284314 * f[(i - 6) * fsi] +
	0.654035449045919 * f[(i - 5) * fsi] - 1.41121344112016 * f[(i - 4) * fsi] +
	1.99381041381332 * f[(i - 3) * fsi] - 2.00547226411236 * f[(i - 2) * fsi] +
	1.74999346652974 * f[(i - 1) * fsi] + 0.174947515412288 * f[(i + 0) * fsi];
      f8 =
	+1.25575611825831 * f[(i + 0) * fsi] - 0.360571470113346 * f[(i + 1) * fsi] +
	0.0874851657699605 * f[(i + 2) * fsi] + 0.0987855322826434 * f[(i + 3) * fsi] -
	0.148104794501812 * f[(i + 4) * fsi] + 0.0921632141194084 * f[(i + 5) * fsi] -
	0.0294534880494172 * f[(i + 6) * fsi] + 0.00393972223425486 * f[(i + 7) * fsi];
      f9 =
	-0.00393972223425484 * f[(i - 1) * fsi] + 1.28727389613235 * f[(i + 0) * fsi] -
	0.470883692672482 * f[(i + 1) * fsi] + 0.308109610888235 * f[(i + 2) * fsi] -
	0.176995024115195 * f[(i + 3) * fsi] + 0.0725196506164557 * f[(i + 4) * fsi] -
	0.0181490084397277 * f[(i + 5) * fsi] + 0.00206428982462176 * f[(i + 6) * fsi];
      f10 =
	-0.00206428982462176 * f[(i - 2) * fsi] + 0.0125745963627193 * f[(i - 1) * fsi] +
	1.22947378104294 * f[(i + 0) * fsi] - 0.355283462493663 * f[(i + 1) * fsi] +
	0.163609323164711 * f[(i + 2) * fsi] - 0.0613947939363763 * f[(i + 3) * fsi] +
	0.0147195355270462 * f[(i + 4) * fsi] - 0.00163468984275355 * f[(i + 5) * fsi];
      f11 =
	+0.00163468984275355 * f[(i - 3) * fsi] - 0.0151418085666501 * f[(i - 2) * fsi] +
	0.0583459119598186 * f[(i - 1) * fsi] + 1.13793114984874 * f[(i + 0) * fsi] -
	0.240855173500915 * f[(i + 1) * fsi] + 0.0720666919705128 * f[(i + 2) * fsi] -
	0.015623478339277 * f[(i + 3) * fsi] + 0.00164201678501785 * f[(i + 4) * fsi];
      f12 =
	-0.00164201678501785 * f[(i - 4) * fsi] + 0.0147708241228964 * f[(i - 3) * fsi] -
	0.0611182785471501 * f[(i - 2) * fsi] + 0.150298851920818 * f[(i - 1) * fsi] +
	1.02298997489749 * f[(i + 0) * fsi] - 0.148902233539915 * f[(i + 1) * fsi] +
	0.0260902219900129 * f[(i + 2) * fsi] - 0.00248734405913415 * f[(i + 3) * fsi];
      f13 =
	+0.00248734405913415 * f[(i - 5) * fsi] - 0.0215407692580911 * f[(i - 4) * fsi] +
	0.0844164577786527 * f[(i - 3) * fsi] - 0.200409545858663 * f[(i - 2) * fsi] +
	0.324412936060209 * f[(i - 1) * fsi] + 0.883698707585977 * f[(i + 0) * fsi] -
	0.079256599884159 * f[(i + 1) * fsi] + 0.00619146951693962 * f[(i + 2) * fsi];
      f14 =
	-0.00619146951693962 * f[(i - 6) * fsi] + 0.0520191001946511 * f[(i - 5) * fsi] -
	0.194901915732401 * f[(i - 4) * fsi] + 0.431138750727272 * f[(i - 3) * fsi] -
	0.633812412044436 * f[(i - 2) * fsi] + 0.671135229008828 * f[(i - 1) * fsi] +
	0.710337561111668 * f[(i + 0) * fsi] - 0.029724843748642 * f[(i + 1) * fsi];
      f15 =
	+0.029724843748642 * f[(i - 7) * fsi] - 0.243990219506076 * f[(i - 6) * fsi] +
	0.884314725156628 * f[(i - 5) * fsi] - 1.85949316565635 * f[(i - 4) * fsi] +
	2.51187781313221 * f[(i - 3) * fsi] - 2.29840366196839 * f[(i - 2) * fsi] +
	1.50343085397081 * f[(i - 1) * fsi] + 0.472538811122531 * f[(i + 0) * fsi];
      f16 =
	+0.472538811122532 * f[(i + 0) * fsi] + 1.5034308539708 * f[(i + 1) * fsi] -
	2.29840366196839 * f[(i + 2) * fsi] + 2.51187781313222 * f[(i + 3) * fsi] -
	1.85949316565635 * f[(i + 4) * fsi] + 0.884314725156627 * f[(i + 5) * fsi] -
	0.243990219506075 * f[(i + 6) * fsi] + 0.029724843748642 * f[(i + 7) * fsi];
      f17 =
	-0.029724843748642 * f[(i - 1) * fsi] + 0.710337561111667 * f[(i + 0) * fsi] +
	0.671135229008828 * f[(i + 1) * fsi] - 0.633812412044436 * f[(i + 2) * fsi] +
	0.431138750727272 * f[(i + 3) * fsi] - 0.194901915732401 * f[(i + 4) * fsi] +
	0.0520191001946512 * f[(i + 5) * fsi] - 0.00619146951693963 * f[(i + 6) * fsi];
      f18 =
	+0.00619146951693963 * f[(i - 2) * fsi] - 0.079256599884159 * f[(i - 1) * fsi] +
	0.883698707585977 * f[(i + 0) * fsi] + 0.324412936060209 * f[(i + 1) * fsi] -
	0.200409545858663 * f[(i + 2) * fsi] + 0.0844164577786528 * f[(i + 3) * fsi] -
	0.0215407692580911 * f[(i + 4) * fsi] + 0.00248734405913415 * f[(i + 5) * fsi];
      f19 =
	-0.00248734405913415 * f[(i - 3) * fsi] + 0.0260902219900129 * f[(i - 2) * fsi] -
	0.148902233539915 * f[(i - 1) * fsi] + 1.02298997489749 * f[(i + 0) * fsi] +
	0.150298851920819 * f[(i + 1) * fsi] - 0.0611182785471501 * f[(i + 2) * fsi] +
	0.0147708241228964 * f[(i + 3) * fsi] - 0.00164201678501785 * f[(i + 4) * fsi];
      f20 =
	+0.00164201678501786 * f[(i - 4) * fsi] - 0.015623478339277 * f[(i - 3) * fsi] +
	0.0720666919705128 * f[(i - 2) * fsi] - 0.240855173500915 * f[(i - 1) * fsi] +
	1.13793114984874 * f[(i + 0) * fsi] + 0.0583459119598186 * f[(i + 1) * fsi] -
	0.0151418085666501 * f[(i + 2) * fsi] + 0.00163468984275355 * f[(i + 3) * fsi];
      f21 =
	-0.00163468984275355 * f[(i - 5) * fsi] + 0.0147195355270462 * f[(i - 4) * fsi] -
	0.0613947939363763 * f[(i - 3) * fsi] + 0.163609323164712 * f[(i - 2) * fsi] -
	0.355283462493664 * f[(i - 1) * fsi] + 1.22947378104294 * f[(i + 0) * fsi] +
	0.0125745963627193 * f[(i + 1) * fsi] - 0.00206428982462176 * f[(i + 2) * fsi];
      f22 =
	+0.00206428982462176 * f[(i - 6) * fsi] - 0.0181490084397277 * f[(i - 5) * fsi] +
	0.0725196506164557 * f[(i - 4) * fsi] - 0.176995024115195 * f[(i - 3) * fsi] +
	0.308109610888235 * f[(i - 2) * fsi] - 0.470883692672482 * f[(i - 1) * fsi] +
	1.28727389613235 * f[(i + 0) * fsi] - 0.00393972223425485 * f[(i + 1) * fsi];
      f23 =
	+0.00393972223425485 * f[(i - 7) * fsi] - 0.0294534880494171 * f[(i - 6) * fsi] +
	0.0921632141194079 * f[(i - 5) * fsi] - 0.148104794501816 * f[(i - 4) * fsi] +
	0.0987855322826441 * f[(i - 3) * fsi] + 0.087485165769964 * f[(i - 2) * fsi] -
	0.360571470113347 * f[(i - 1) * fsi] + 1.25575611825831 * f[(i + 0) * fsi];
      f24 =
	+0.174947515412288 * f[(i + 0) * fsi] + 1.74999346652974 * f[(i + 1) * fsi] -
	2.00547226411237 * f[(i + 2) * fsi] + 1.99381041381332 * f[(i + 3) * fsi] -
	1.41121344112014 * f[(i + 4) * fsi] + 0.654035449045917 * f[(i + 5) * fsi] -
	0.177472472284314 * f[(i + 6) * fsi] + 0.0213713327155674 * f[(i + 7) * fsi];
      f25 =
	-0.0213713327155673 * f[(i - 1) * fsi] + 0.345918177136826 * f[(i + 0) * fsi] +
	1.15159615049385 * f[(i + 1) * fsi] - 0.808677632040588 * f[(i + 2) * fsi] +
	0.497817123723601 * f[(i + 3) * fsi] - 0.214418809048384 * f[(i + 4) * fsi] +
	0.055638133010033 * f[(i + 5) * fsi] - 0.00650181055977517 * f[(i + 6) * fsi];
      f26 =
	+0.00650181055977516 * f[(i - 2) * fsi] - 0.0733858171937684 * f[(i - 1) * fsi] +
	0.527968872810531 * f[(i + 0) * fsi] + 0.787494759146445 * f[(i + 1) * fsi] -
	0.353550892856327 * f[(i + 2) * fsi] + 0.133715732376192 * f[(i + 3) * fsi] -
	0.032368113374679 * f[(i + 4) * fsi] + 0.00362364853183151 * f[(i + 5) * fsi];
      f27 =
	-0.00362364853183151 * f[(i - 3) * fsi] + 0.0354909988144272 * f[(i - 2) * fsi] -
	0.174847976085051 * f[(i - 1) * fsi] + 0.730893190593096 * f[(i + 0) * fsi] +
	0.53383936191824 * f[(i + 1) * fsi] - 0.150626575073762 * f[(i + 2) * fsi] +
	0.0322535734849095 * f[(i + 3) * fsi] - 0.00337892512002692 * f[(i + 4) * fsi];
      f28 =
	+0.00337892512002692 * f[(i - 4) * fsi] - 0.0306550494920469 * f[(i - 3) * fsi] +
	0.130100902175181 * f[(i - 2) * fsi] - 0.364067782806559 * f[(i - 1) * fsi] +
	0.96741794899498 * f[(i + 0) * fsi] + 0.344619555196731 * f[(i + 1) * fsi] -
	0.0560166717130086 * f[(i + 2) * fsi] + 0.00522217252469413 * f[(i + 3) * fsi];
      f29 =
	-0.00522217252469413 * f[(i - 5) * fsi] + 0.04515630531758 * f[(i - 4) * fsi] -
	0.176875880183483 * f[(i - 3) * fsi] + 0.422542563558053 * f[(i - 2) * fsi] -
	0.729619859535148 * f[(i - 1) * fsi] + 1.25985961037785 * f[(i + 0) * fsi] +
	0.198398724505296 * f[(i + 1) * fsi] - 0.0142392915154555 * f[(i + 2) * fsi];
      f30 =
	+0.0142392915154555 * f[(i - 6) * fsi] - 0.119136504648338 * f[(i - 5) * fsi] +
	0.443856467750334 * f[(i - 4) * fsi] - 0.974276205048991 * f[(i - 3) * fsi] +
	1.41929296963994 * f[(i - 2) * fsi] - 1.52702018440066 * f[(i - 1) * fsi] +
	1.65855977281061 * f[(i + 0) * fsi] + 0.0844843923816518 * f[(i + 1) * fsi];
      f31 =
	-0.0844843923816518 * f[(i - 7) * fsi] + 0.69011443056867 * f[(i - 6) * fsi] -
	2.48469949133459 * f[(i - 5) * fsi] + 5.17498244112283 * f[(i - 4) * fsi] -
	6.88818367176462 * f[(i - 3) * fsi] + 6.15041894301244 * f[(i - 2) * fsi] -
	3.89258317108691 * f[(i - 1) * fsi] + 2.33443491186382 * f[(i + 0) * fsi];
      fr0 =
	f0 * omega0 + f1 * omega1 + f2 * omega2 + f3 * omega3 + f4 * omega4 + f5 * omega5 +
	f6 * omega6 + f7 * omega7;
      fr1 =
	+2.00800075203709 * (f8 * omega8p + f9 * omega9p + f10 * omega10p + f11 * omega11p +
			     f12 * omega12p + f13 * omega13p + f14 * omega14p + f15 * omega15p) -
	+1.00800075203709 * (f8 * omega8m + f9 * omega9m + f10 * omega10m + f11 * omega11m +
			     f12 * omega12m + f13 * omega13m + f14 * omega14m + f15 * omega15m);
      fr2 =
	+2.00800075203699 * (f16 * omega16p + f17 * omega17p + f18 * omega18p + f19 * omega19p +
			     f20 * omega20p + f21 * omega21p + f22 * omega22p + f23 * omega23p) -
	+1.008000752037 * (f16 * omega16m + f17 * omega17m + f18 * omega18m + f19 * omega19m +
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
py_gauss_legendre008004 (PyObject * self, PyObject * args)
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

  gauss_legendre008004 (f, n, fsi, sigma, ssi, ssr, fr, frsi, frsl);

  Py_INCREF (Py_None);
  return Py_None;
}
