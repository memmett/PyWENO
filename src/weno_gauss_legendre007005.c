#include <Python.h>
#include <numpy/ndarrayobject.h>

void
gauss_legendre007005 (const double *restrict f, int n, int fsi,
		      const double *restrict sigma, int ssi, int ssr,
		      double *restrict fr, int frsi, int frsl)
{
  int i;
  double sigma0, sigma1, sigma2, sigma3, sigma4, sigma5, sigma6, omega10, omega21, omega18m,
    omega13, omega17p, omega3, omega16p, omega17m, omega28, omega9, omega18p, omega22, omega24,
    omega32, omega12, omega14m, omega4, omega33, omega29, omega14p, omega23, omega0, omega27,
    omega19p, omega20m, omega11, omega19m, omega20p, omega5, omega30, omega7, omega26, omega1,
    omega15p, omega34, omega16m, omega15m, omega8, omega6, omega31, omega25, omega2, accumulator,
    f10, f21, f15, f20, f13, f19, f3, f28, f9, f24, f14, f32, f12, f27, f16, f29, f8, f23, f0, f33,
    f4, f11, f17, f30, f7, f26, f1, f34, f22, f2, f6, f31, f5, f25, f18, fr0, fr1, fr2, fr3, fr4;
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
      omega0 = +0.000735419036443374 / (1.0e-6 + sigma0) / (1.0e-6 + sigma0);
      accumulator += omega0;
      omega1 = +0.0276801852278923 / (1.0e-6 + sigma1) / (1.0e-6 + sigma1);
      accumulator += omega1;
      omega2 = +0.194800303204442 / (1.0e-6 + sigma2) / (1.0e-6 + sigma2);
      accumulator += omega2;
      omega3 = +0.411552993800919 / (1.0e-6 + sigma3) / (1.0e-6 + sigma3);
      accumulator += omega3;
      omega4 = +0.294480278545107 / (1.0e-6 + sigma4) / (1.0e-6 + sigma4);
      accumulator += omega4;
      omega5 = +0.067239547636157 / (1.0e-6 + sigma5) / (1.0e-6 + sigma5);
      accumulator += omega5;
      omega6 = +0.00351127254903999 / (1.0e-6 + sigma6) / (1.0e-6 + sigma6);
      accumulator += omega6;
      omega0 /= accumulator;
      omega1 /= accumulator;
      omega2 /= accumulator;
      omega3 /= accumulator;
      omega4 /= accumulator;
      omega5 /= accumulator;
      omega6 /= accumulator;
      accumulator = 0.0;
      omega7 = +0.00245462423696136 / (1.0e-6 + sigma0) / (1.0e-6 + sigma0);
      accumulator += omega7;
      omega8 = +0.0480883941210288 / (1.0e-6 + sigma1) / (1.0e-6 + sigma1);
      accumulator += omega8;
      omega9 = +0.246884077937901 / (1.0e-6 + sigma2) / (1.0e-6 + sigma2);
      accumulator += omega9;
      omega10 = +0.413993745048807 / (1.0e-6 + sigma3) / (1.0e-6 + sigma3);
      accumulator += omega10;
      omega11 = +0.241806584085243 / (1.0e-6 + sigma4) / (1.0e-6 + sigma4);
      accumulator += omega11;
      omega12 = +0.0449416921997912 / (1.0e-6 + sigma5) / (1.0e-6 + sigma5);
      accumulator += omega12;
      omega13 = +0.00183088237026829 / (1.0e-6 + sigma6) / (1.0e-6 + sigma6);
      accumulator += omega13;
      omega7 /= accumulator;
      omega8 /= accumulator;
      omega9 /= accumulator;
      omega10 /= accumulator;
      omega11 /= accumulator;
      omega12 /= accumulator;
      omega13 /= accumulator;
      accumulator = 0.0;
      omega14p = +0.000149691116038702 / +3.94901979530886 / (1.0e-6 + sigma0) / (1.0e-6 + sigma0);
      accumulator += omega14p;
      omega15p = +0.0106349872873979 / +3.94901979530886 / (1.0e-6 + sigma1) / (1.0e-6 + sigma1);
      accumulator += omega15p;
      omega16p = +0.31405195414804 / +3.94901979530886 / (1.0e-6 + sigma2) / (1.0e-6 + sigma2);
      accumulator += omega16p;
      omega17p = +3.29934653020591 / +3.94901979530886 / (1.0e-6 + sigma3) / (1.0e-6 + sigma3);
      accumulator += omega17p;
      omega18p = +0.31405195414804 / +3.94901979530886 / (1.0e-6 + sigma4) / (1.0e-6 + sigma4);
      accumulator += omega18p;
      omega19p = +0.0106349872873979 / +3.94901979530886 / (1.0e-6 + sigma5) / (1.0e-6 + sigma5);
      accumulator += omega19p;
      omega20p = +0.000149691116038702 / +3.94901979530886 / (1.0e-6 + sigma6) / (1.0e-6 + sigma6);
      accumulator += omega20p;
      omega14p /= accumulator;
      omega15p /= accumulator;
      omega16p /= accumulator;
      omega17p /= accumulator;
      omega18p /= accumulator;
      omega19p /= accumulator;
      omega20p /= accumulator;
      accumulator = 0.0;
      omega14m = +0.000299382232077403 / +2.94901979530886 / (1.0e-6 + sigma0) / (1.0e-6 + sigma0);
      accumulator += omega14m;
      omega15m = +0.0212699745747958 / +2.94901979530886 / (1.0e-6 + sigma1) / (1.0e-6 + sigma1);
      accumulator += omega15m;
      omega16m = +0.628103908296079 / +2.94901979530886 / (1.0e-6 + sigma2) / (1.0e-6 + sigma2);
      accumulator += omega16m;
      omega17m = +1.64967326510295 / +2.94901979530886 / (1.0e-6 + sigma3) / (1.0e-6 + sigma3);
      accumulator += omega17m;
      omega18m = +0.628103908296079 / +2.94901979530886 / (1.0e-6 + sigma4) / (1.0e-6 + sigma4);
      accumulator += omega18m;
      omega19m = +0.0212699745747958 / +2.94901979530886 / (1.0e-6 + sigma5) / (1.0e-6 + sigma5);
      accumulator += omega19m;
      omega20m = +0.000299382232077403 / +2.94901979530886 / (1.0e-6 + sigma6) / (1.0e-6 + sigma6);
      accumulator += omega20m;
      omega14m /= accumulator;
      omega15m /= accumulator;
      omega16m /= accumulator;
      omega17m /= accumulator;
      omega18m /= accumulator;
      omega19m /= accumulator;
      omega20m /= accumulator;
      accumulator = 0.0;
      omega21 = +0.00183088237027339 / (1.0e-6 + sigma0) / (1.0e-6 + sigma0);
      accumulator += omega21;
      omega22 = +0.0449416921997827 / (1.0e-6 + sigma1) / (1.0e-6 + sigma1);
      accumulator += omega22;
      omega23 = +0.241806584085252 / (1.0e-6 + sigma2) / (1.0e-6 + sigma2);
      accumulator += omega23;
      omega24 = +0.413993745048801 / (1.0e-6 + sigma3) / (1.0e-6 + sigma3);
      accumulator += omega24;
      omega25 = +0.246884077937905 / (1.0e-6 + sigma4) / (1.0e-6 + sigma4);
      accumulator += omega25;
      omega26 = +0.0480883941210218 / (1.0e-6 + sigma5) / (1.0e-6 + sigma5);
      accumulator += omega26;
      omega27 = +0.00245462423696582 / (1.0e-6 + sigma6) / (1.0e-6 + sigma6);
      accumulator += omega27;
      omega21 /= accumulator;
      omega22 /= accumulator;
      omega23 /= accumulator;
      omega24 /= accumulator;
      omega25 /= accumulator;
      omega26 /= accumulator;
      omega27 /= accumulator;
      accumulator = 0.0;
      omega28 = +0.00351127254907459 / (1.0e-6 + sigma0) / (1.0e-6 + sigma0);
      accumulator += omega28;
      omega29 = +0.0672395476361022 / (1.0e-6 + sigma1) / (1.0e-6 + sigma1);
      accumulator += omega29;
      omega30 = +0.294480278545145 / (1.0e-6 + sigma2) / (1.0e-6 + sigma2);
      accumulator += omega30;
      omega31 = +0.411552993800907 / (1.0e-6 + sigma3) / (1.0e-6 + sigma3);
      accumulator += omega31;
      omega32 = +0.194800303204446 / (1.0e-6 + sigma4) / (1.0e-6 + sigma4);
      accumulator += omega32;
      omega33 = +0.0276801852278882 / (1.0e-6 + sigma5) / (1.0e-6 + sigma5);
      accumulator += omega33;
      omega34 = +0.000735419036445142 / (1.0e-6 + sigma6) / (1.0e-6 + sigma6);
      accumulator += omega34;
      omega28 /= accumulator;
      omega29 /= accumulator;
      omega30 /= accumulator;
      omega31 /= accumulator;
      omega32 /= accumulator;
      omega33 /= accumulator;
      omega34 /= accumulator;
      f0 =
	+2.35711088549496 * f[(i + 0) * fsi] - 3.64264788158522 * f[(i + 1) * fsi] +
	4.90131302994763 * f[(i + 2) * fsi] - 4.43136534043243 * f[(i + 3) * fsi] +
	2.50900652385207 * f[(i + 4) * fsi] - 0.805505128271721 * f[(i + 5) * fsi] +
	0.11208791099471 * f[(i + 6) * fsi];
      f1 =
	+0.11208791099471 * f[(i - 1) * fsi] + 1.572495508532 * f[(i + 0) * fsi] -
	1.28880175069631 * f[(i + 1) * fsi] + 0.978236145132786 * f[(i + 2) * fsi] -
	0.508288455617592 * f[(i + 3) * fsi] + 0.155160392963164 * f[(i + 4) * fsi] -
	0.0208897513087525 * f[(i + 5) * fsi];
      f2 =
	-0.0208897513087525 * f[(i - 2) * fsi] + 0.258316170155977 * f[(i - 1) * fsi] +
	1.13381073104819 * f[(i + 0) * fsi] - 0.557660454889971 * f[(i + 1) * fsi] +
	0.247094849326447 * f[(i + 2) * fsi] - 0.0696036781337893 * f[(i + 3) * fsi] +
	0.00893213380189628 * f[(i + 4) * fsi];
      f3 =
	+0.00893213380189628 * f[(i - 3) * fsi] - 0.0834146879220265 * f[(i - 2) * fsi] +
	0.445890979995799 * f[(i - 1) * fsi] + 0.821186047981822 * f[(i + 0) * fsi] -
	0.245035771823602 * f[(i + 1) * fsi] + 0.0595200394866254 * f[(i + 2) * fsi] -
	0.00707874152051537 * f[(i + 3) * fsi];
      f4 =
	-0.00707874152051537 * f[(i - 4) * fsi] + 0.0584833244455038 * f[(i - 3) * fsi] -
	0.232068259852849 * f[(i - 2) * fsi] + 0.693646933213837 * f[(i - 1) * fsi] +
	0.573430094763785 * f[(i + 0) * fsi] - 0.0963821998927789 * f[(i + 1) * fsi] +
	0.00996884884301789 * f[(i + 2) * fsi];
      f5 =
	+0.00996884884301789 * f[(i - 5) * fsi] - 0.0768606834216406 * f[(i - 4) * fsi] +
	0.26782915014888 * f[(i - 3) * fsi] - 0.580977969358475 * f[(i - 2) * fsi] +
	1.04255664271946 * f[(i - 1) * fsi] + 0.364084269060409 * f[(i + 0) * fsi] -
	0.0266002579916537 * f[(i + 1) * fsi];
      f6 =
	-0.0266002579916537 * f[(i - 6) * fsi] + 0.196170654784594 * f[(i - 5) * fsi] -
	0.635466101246367 * f[(i - 4) * fsi] + 1.19883817985676 * f[(i - 3) * fsi] -
	1.51198699906635 * f[(i - 2) * fsi] + 1.60116206054419 * f[(i - 1) * fsi] +
	0.177882463118833 * f[(i + 0) * fsi];
      f7 =
	+1.58664534816301 * f[(i + 0) * fsi] - 1.291785464484 * f[(i + 1) * fsi] +
	1.40614231467313 * f[(i + 2) * fsi] - 1.15414134453932 * f[(i + 3) * fsi] +
	0.619112153838744 * f[(i + 4) * fsi] - 0.192079644257257 * f[(i + 5) * fsi] +
	0.0261066366056928 * f[(i + 6) * fsi];
      f8 =
	+0.0261066366056928 * f[(i - 1) * fsi] + 1.40389889192316 * f[(i + 0) * fsi] -
	0.74354609576445 * f[(i + 1) * fsi] + 0.492410033473882 * f[(i + 2) * fsi] -
	0.24040906334007 * f[(i + 3) * fsi] + 0.070872785119197 * f[(i + 4) * fsi] -
	0.00933318801740802 * f[(i + 5) * fsi];
      f9 =
	-0.00933318801740802 * f[(i - 2) * fsi] + 0.0914389527275489 * f[(i - 1) * fsi] +
	1.20790194355759 * f[(i + 0) * fsi] - 0.416884515155169 * f[(i + 1) * fsi] +
	0.165748452864602 * f[(i + 2) * fsi] - 0.044412114974502 * f[(i + 3) * fsi] +
	0.00554046899734081 * f[(i + 4) * fsi];
      f10 =
	+0.00554046899734081 * f[(i - 3) * fsi] - 0.0481164709987937 * f[(i - 2) * fsi] +
	0.207788801671706 * f[(i - 1) * fsi] + 1.01398552865066 * f[(i + 0) * fsi] -
	0.222968100248241 * f[(i + 1) * fsi] + 0.0493986039204446 * f[(i + 2) * fsi] -
	0.00562883199311631 * f[(i + 3) * fsi];
      f11 =
	-0.00562883199311631 * f[(i - 4) * fsi] + 0.044942292949155 * f[(i - 3) * fsi] -
	0.166321942854236 * f[(i - 2) * fsi] + 0.404797921430777 * f[(i - 1) * fsi] +
	0.816976408891589 * f[(i + 0) * fsi] - 0.104762628392799 * f[(i + 1) * fsi] +
	0.00999677996863049 * f[(i + 2) * fsi];
      f12 =
	+0.00999677996863049 * f[(i - 5) * fsi] - 0.0756062917735297 * f[(i - 4) * fsi] +
	0.254874672290395 * f[(i - 3) * fsi] - 0.516209241756303 * f[(i - 2) * fsi] +
	0.754685220332844 * f[(i - 1) * fsi] + 0.607044029550349 * f[(i + 0) * fsi] -
	0.0347851686123851 * f[(i + 1) * fsi];
      f13 =
	-0.0347851686123851 * f[(i - 6) * fsi] + 0.253492960255326 * f[(i - 5) * fsi] -
	0.806094832633617 * f[(i - 4) * fsi] + 1.47235557372387 * f[(i - 3) * fsi] -
	1.73369014318978 * f[(i - 2) * fsi] + 1.48517376119293 * f[(i - 1) * fsi] +
	0.363547849263653 * f[(i + 0) * fsi];
      f14 =
	+0.819094122023809 * f[(i + 0) * fsi] + 0.687518601190476 * f[(i + 1) * fsi] -
	1.13598400297619 * f[(i + 2) * fsi] + 1.07853422619048 * f[(i + 3) * fsi] -
	0.622963169642857 * f[(i + 4) * fsi] + 0.20210193452381 * f[(i + 5) * fsi] -
	0.0283017113095238 * f[(i + 6) * fsi];
      f15 =
	-0.0283017113095238 * f[(i - 1) * fsi] + 1.01720610119048 * f[(i + 0) * fsi] +
	0.0931826636904762 * f[(i + 1) * fsi] - 0.145424107142857 * f[(i + 2) * fsi] +
	0.0879743303571429 * f[(i + 3) * fsi] - 0.0286272321428571 * f[(i + 4) * fsi] +
	0.00398995535714286 * f[(i + 5) * fsi];
      f16 =
	+0.00398995535714286 * f[(i - 2) * fsi] - 0.0562313988095238 * f[(i - 1) * fsi] +
	1.10099516369048 * f[(i + 0) * fsi] - 0.0464657738095238 * f[(i + 1) * fsi] -
	0.00577566964285714 * f[(i + 2) * fsi] + 0.00418526785714286 * f[(i + 3) * fsi] -
	0.000697544642857143 * f[(i + 4) * fsi];
      f17 =
	-0.000697544642857143 * f[(i - 3) * fsi] + 0.00887276785714286 * f[(i - 2) * fsi] -
	0.0708798363095238 * f[(i - 1) * fsi] + 1.12540922619048 * f[(i + 0) * fsi] -
	0.0708798363095238 * f[(i + 1) * fsi] + 0.00887276785714286 * f[(i + 2) * fsi] -
	0.000697544642857143 * f[(i + 3) * fsi];
      f18 =
	-0.000697544642857143 * f[(i - 4) * fsi] + 0.00418526785714286 * f[(i - 3) * fsi] -
	0.00577566964285714 * f[(i - 2) * fsi] - 0.0464657738095238 * f[(i - 1) * fsi] +
	1.10099516369048 * f[(i + 0) * fsi] - 0.0562313988095238 * f[(i + 1) * fsi] +
	0.00398995535714286 * f[(i + 2) * fsi];
      f19 =
	+0.00398995535714286 * f[(i - 5) * fsi] - 0.0286272321428571 * f[(i - 4) * fsi] +
	0.0879743303571429 * f[(i - 3) * fsi] - 0.145424107142857 * f[(i - 2) * fsi] +
	0.0931826636904762 * f[(i - 1) * fsi] + 1.01720610119048 * f[(i + 0) * fsi] -
	0.0283017113095238 * f[(i + 1) * fsi];
      f20 =
	-0.0283017113095238 * f[(i - 6) * fsi] + 0.20210193452381 * f[(i - 5) * fsi] -
	0.622963169642857 * f[(i - 4) * fsi] + 1.07853422619048 * f[(i - 3) * fsi] -
	1.13598400297619 * f[(i - 2) * fsi] + 0.687518601190476 * f[(i - 1) * fsi] +
	0.819094122023809 * f[(i + 0) * fsi];
      f21 =
	+0.363547849263654 * f[(i + 0) * fsi] + 1.48517376119293 * f[(i + 1) * fsi] -
	1.73369014318978 * f[(i + 2) * fsi] + 1.47235557372387 * f[(i + 3) * fsi] -
	0.806094832633618 * f[(i + 4) * fsi] + 0.253492960255327 * f[(i + 5) * fsi] -
	0.034785168612385 * f[(i + 6) * fsi];
      f22 =
	-0.034785168612385 * f[(i - 1) * fsi] + 0.607044029550349 * f[(i + 0) * fsi] +
	0.754685220332844 * f[(i + 1) * fsi] - 0.516209241756303 * f[(i + 2) * fsi] +
	0.254874672290395 * f[(i + 3) * fsi] - 0.0756062917735296 * f[(i + 4) * fsi] +
	0.00999677996863049 * f[(i + 5) * fsi];
      f23 =
	+0.0099967799686305 * f[(i - 2) * fsi] - 0.104762628392798 * f[(i - 1) * fsi] +
	0.816976408891589 * f[(i + 0) * fsi] + 0.404797921430776 * f[(i + 1) * fsi] -
	0.166321942854236 * f[(i + 2) * fsi] + 0.044942292949155 * f[(i + 3) * fsi] -
	0.0056288319931163 * f[(i + 4) * fsi];
      f24 =
	-0.0056288319931163 * f[(i - 3) * fsi] + 0.0493986039204446 * f[(i - 2) * fsi] -
	0.222968100248241 * f[(i - 1) * fsi] + 1.01398552865066 * f[(i + 0) * fsi] +
	0.207788801671706 * f[(i + 1) * fsi] - 0.0481164709987937 * f[(i + 2) * fsi] +
	0.00554046899734081 * f[(i + 3) * fsi];
      f25 =
	+0.00554046899734081 * f[(i - 4) * fsi] - 0.044412114974502 * f[(i - 3) * fsi] +
	0.165748452864602 * f[(i - 2) * fsi] - 0.416884515155169 * f[(i - 1) * fsi] +
	1.20790194355759 * f[(i + 0) * fsi] + 0.0914389527275489 * f[(i + 1) * fsi] -
	0.00933318801740801 * f[(i + 2) * fsi];
      f26 =
	-0.00933318801740801 * f[(i - 5) * fsi] + 0.0708727851191969 * f[(i - 4) * fsi] -
	0.24040906334007 * f[(i - 3) * fsi] + 0.492410033473882 * f[(i - 2) * fsi] -
	0.74354609576445 * f[(i - 1) * fsi] + 1.40389889192316 * f[(i + 0) * fsi] +
	0.0261066366056927 * f[(i + 1) * fsi];
      f27 =
	+0.0261066366056927 * f[(i - 6) * fsi] - 0.192079644257257 * f[(i - 5) * fsi] +
	0.619112153838745 * f[(i - 4) * fsi] - 1.15414134453932 * f[(i - 3) * fsi] +
	1.40614231467313 * f[(i - 2) * fsi] - 1.291785464484 * f[(i - 1) * fsi] +
	1.58664534816301 * f[(i + 0) * fsi];
      f28 =
	+0.177882463118833 * f[(i + 0) * fsi] + 1.60116206054419 * f[(i + 1) * fsi] -
	1.51198699906635 * f[(i + 2) * fsi] + 1.19883817985676 * f[(i + 3) * fsi] -
	0.635466101246367 * f[(i + 4) * fsi] + 0.196170654784593 * f[(i + 5) * fsi] -
	0.0266002579916537 * f[(i + 6) * fsi];
      f29 =
	-0.0266002579916537 * f[(i - 1) * fsi] + 0.364084269060409 * f[(i + 0) * fsi] +
	1.04255664271946 * f[(i + 1) * fsi] - 0.580977969358476 * f[(i + 2) * fsi] +
	0.267829150148879 * f[(i + 3) * fsi] - 0.0768606834216407 * f[(i + 4) * fsi] +
	0.00996884884301789 * f[(i + 5) * fsi];
      f30 =
	+0.00996884884301789 * f[(i - 2) * fsi] - 0.0963821998927788 * f[(i - 1) * fsi] +
	0.573430094763785 * f[(i + 0) * fsi] + 0.693646933213837 * f[(i + 1) * fsi] -
	0.232068259852849 * f[(i + 2) * fsi] + 0.0584833244455038 * f[(i + 3) * fsi] -
	0.00707874152051536 * f[(i + 4) * fsi];
      f31 =
	-0.00707874152051537 * f[(i - 3) * fsi] + 0.0595200394866255 * f[(i - 2) * fsi] -
	0.245035771823602 * f[(i - 1) * fsi] + 0.821186047981822 * f[(i + 0) * fsi] +
	0.445890979995799 * f[(i + 1) * fsi] - 0.0834146879220265 * f[(i + 2) * fsi] +
	0.00893213380189628 * f[(i + 3) * fsi];
      f32 =
	+0.00893213380189628 * f[(i - 4) * fsi] - 0.0696036781337893 * f[(i - 3) * fsi] +
	0.247094849326447 * f[(i - 2) * fsi] - 0.557660454889972 * f[(i - 1) * fsi] +
	1.13381073104819 * f[(i + 0) * fsi] + 0.258316170155977 * f[(i + 1) * fsi] -
	0.0208897513087525 * f[(i + 2) * fsi];
      f33 =
	-0.0208897513087525 * f[(i - 5) * fsi] + 0.155160392963164 * f[(i - 4) * fsi] -
	0.508288455617592 * f[(i - 3) * fsi] + 0.978236145132785 * f[(i - 2) * fsi] -
	1.28880175069631 * f[(i - 1) * fsi] + 1.572495508532 * f[(i + 0) * fsi] +
	0.11208791099471 * f[(i + 1) * fsi];
      f34 =
	+0.11208791099471 * f[(i - 6) * fsi] - 0.805505128271721 * f[(i - 5) * fsi] +
	2.50900652385207 * f[(i - 4) * fsi] - 4.43136534043243 * f[(i - 3) * fsi] +
	4.90131302994763 * f[(i - 2) * fsi] - 3.64264788158521 * f[(i - 1) * fsi] +
	2.35711088549496 * f[(i + 0) * fsi];
      fr0 =
	f0 * omega0 + f1 * omega1 + f2 * omega2 + f3 * omega3 + f4 * omega4 + f5 * omega5 +
	f6 * omega6;
      fr1 =
	f7 * omega7 + f8 * omega8 + f9 * omega9 + f10 * omega10 + f11 * omega11 + f12 * omega12 +
	f13 * omega13;
      fr2 =
	+3.94901979530886 * (f14 * omega14p + f15 * omega15p + f16 * omega16p + f17 * omega17p +
			     f18 * omega18p + f19 * omega19p + f20 * omega20p) -
	+2.94901979530886 * (f14 * omega14m + f15 * omega15m + f16 * omega16m + f17 * omega17m +
			     f18 * omega18m + f19 * omega19m + f20 * omega20m);
      fr3 =
	f21 * omega21 + f22 * omega22 + f23 * omega23 + f24 * omega24 + f25 * omega25 +
	f26 * omega26 + f27 * omega27;
      fr4 =
	f28 * omega28 + f29 * omega29 + f30 * omega30 + f31 * omega31 + f32 * omega32 +
	f33 * omega33 + f34 * omega34;
      fr[i * frsi + 0 * frsl] = fr0;
      fr[i * frsi + 1 * frsl] = fr1;
      fr[i * frsi + 2 * frsl] = fr2;
      fr[i * frsi + 3 * frsl] = fr3;
      fr[i * frsi + 4 * frsl] = fr4;
    }
}

PyObject *
py_gauss_legendre007005 (PyObject * self, PyObject * args)
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

  gauss_legendre007005 (f, n, fsi, sigma, ssi, ssr, fr, frsi, frsl);

  Py_INCREF (Py_None);
  return Py_None;
}
