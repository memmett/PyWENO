#include <Python.h>
#include <numpy/ndarrayobject.h>

void
gauss_lobatto008004 (const double *restrict f, int n, int fsi,
		     const double *restrict sigma, int ssi, int ssr,
		     double *restrict fr, int frsi, int frsl)
{
  int i;
  double sigma0, sigma1, sigma2, sigma3, sigma4, sigma5, sigma6, sigma7, omega11, omega24, omega7,
    omega22, omega14, omega31, omega21, omega3, omega10, omega27, omega16, omega13, omega30,
    omega18, omega9, omega23, omega26, omega0, omega4, omega12, omega19, omega17, omega8, omega29,
    omega1, omega25, omega2, omega6, omega15, omega5, omega28, omega20, accumulator, f11, f24, f7,
    f22, f14, f31, f21, f3, f10, f27, f16, f13, f30, f18, f9, f23, f26, f0, f4, f12, f19, f17, f8,
    f29, f1, f25, f2, f6, f15, f5, f28, f20, fr0, fr1, fr2, fr3;
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
      omega8 = +0.00170444499212679 / (1.0e-6 + sigma0) / (1.0e-6 + sigma0);
      accumulator += omega8;
      omega9 = +0.0239603949664538 / (1.0e-6 + sigma1) / (1.0e-6 + sigma1);
      accumulator += omega9;
      omega10 = +0.151491618274736 / (1.0e-6 + sigma2) / (1.0e-6 + sigma2);
      accumulator += omega10;
      omega11 = +0.354952567453436 / (1.0e-6 + sigma3) / (1.0e-6 + sigma3);
      accumulator += omega11;
      omega12 = +0.331420722857237 / (1.0e-6 + sigma4) / (1.0e-6 + sigma4);
      accumulator += omega12;
      omega13 = +0.120955209084198 / (1.0e-6 + sigma5) / (1.0e-6 + sigma5);
      accumulator += omega13;
      omega14 = +0.0150857028609216 / (1.0e-6 + sigma6) / (1.0e-6 + sigma6);
      accumulator += omega14;
      omega15 = +0.000429339510890817 / (1.0e-6 + sigma7) / (1.0e-6 + sigma7);
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
      omega16 = +0.000429339510845537 / (1.0e-6 + sigma0) / (1.0e-6 + sigma0);
      accumulator += omega16;
      omega17 = +0.0150857028609848 / (1.0e-6 + sigma1) / (1.0e-6 + sigma1);
      accumulator += omega17;
      omega18 = +0.120955209084168 / (1.0e-6 + sigma2) / (1.0e-6 + sigma2);
      accumulator += omega18;
      omega19 = +0.331420722857237 / (1.0e-6 + sigma3) / (1.0e-6 + sigma3);
      accumulator += omega19;
      omega20 = +0.354952567453439 / (1.0e-6 + sigma4) / (1.0e-6 + sigma4);
      accumulator += omega20;
      omega21 = +0.151491618274746 / (1.0e-6 + sigma5) / (1.0e-6 + sigma5);
      accumulator += omega21;
      omega22 = +0.0239603949664129 / (1.0e-6 + sigma6) / (1.0e-6 + sigma6);
      accumulator += omega22;
      omega23 = +0.00170444499215734 / (1.0e-6 + sigma7) / (1.0e-6 + sigma7);
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
      omega24 = +0.00124320124317649 / (1.0e-6 + sigma0) / (1.0e-6 + sigma0);
      accumulator += omega24;
      omega25 = +0.0304584304584759 / (1.0e-6 + sigma1) / (1.0e-6 + sigma1);
      accumulator += omega25;
      omega26 = +0.182750582750552 / (1.0e-6 + sigma2) / (1.0e-6 + sigma2);
      accumulator += omega26;
      omega27 = +0.380730380730387 / (1.0e-6 + sigma3) / (1.0e-6 + sigma3);
      accumulator += omega27;
      omega28 = +0.304584304584304 / (1.0e-6 + sigma4) / (1.0e-6 + sigma4);
      accumulator += omega28;
      omega29 = +0.0913752913752916 / (1.0e-6 + sigma5) / (1.0e-6 + sigma5);
      accumulator += omega29;
      omega30 = +0.00870240870240869 / (1.0e-6 + sigma6) / (1.0e-6 + sigma6);
      accumulator += omega30;
      omega31 = +0.000155400155400156 / (1.0e-6 + sigma7) / (1.0e-6 + sigma7);
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
	+1.43695342422686 * f[(i + 0) * fsi] - 0.901552526364763 * f[(i + 1) * fsi] +
	0.948961910303272 * f[(i + 2) * fsi] - 0.860005376718935 * f[(i + 3) * fsi] +
	0.568284083147782 * f[(i + 4) * fsi] - 0.250395586746879 * f[(i + 5) * fsi] +
	0.0653988657603342 * f[(i + 6) * fsi] - 0.00764479360766851 * f[(i + 7) * fsi];
      f9 =
	+0.00764479360766851 * f[(i - 1) * fsi] + 1.37579507536551 * f[(i + 0) * fsi] -
	0.687498305350046 * f[(i + 1) * fsi] + 0.520853468273835 * f[(i + 2) * fsi] -
	0.324869824182139 * f[(i + 3) * fsi] + 0.140175641118343 * f[(i + 4) * fsi] -
	0.0363413657321612 * f[(i + 5) * fsi] + 0.00424051689898599 * f[(i + 6) * fsi];
      f10 =
	-0.00424051689898599 * f[(i - 2) * fsi] + 0.0415689287995565 * f[(i - 1) * fsi] +
	1.25706060219391 * f[(i + 0) * fsi] - 0.45002935900683 * f[(i + 1) * fsi] +
	0.224017285344815 * f[(i + 2) * fsi] - 0.0874008778389233 * f[(i + 3) * fsi] +
	0.0214411679467351 * f[(i + 4) * fsi] - 0.00241723054027316 * f[(i + 5) * fsi];
      f11 =
	+0.00241723054027316 * f[(i - 3) * fsi] - 0.0235783612211713 * f[(i - 2) * fsi] +
	0.109251383927205 * f[(i - 1) * fsi] + 1.12169569193861 * f[(i + 0) * fsi] -
	0.280823221187708 * f[(i + 1) * fsi] + 0.0886523750895181 * f[(i + 2) * fsi] -
	0.0197184227112747 * f[(i + 3) * fsi] + 0.0021033236245498 * f[(i + 4) * fsi];
      f12 =
	-0.0021033236245498 * f[(i - 4) * fsi] + 0.0192438195366716 * f[(i - 3) * fsi] -
	0.0824714227085658 * f[(i - 2) * fsi] + 0.227037506901994 * f[(i - 1) * fsi] +
	0.974463038220122 * f[(i + 0) * fsi] - 0.163037098212919 * f[(i + 1) * fsi] +
	0.0297593136021237 * f[(i + 2) * fsi] - 0.00289183371487634 * f[(i + 3) * fsi];
      f13 =
	+0.00289183371487634 * f[(i - 5) * fsi] - 0.0252379933435605 * f[(i - 4) * fsi] +
	0.100215163553209 * f[(i - 3) * fsi] - 0.244414110741641 * f[(i - 2) * fsi] +
	0.429465866943337 * f[(i - 1) * fsi] + 0.812520350187047 * f[(i + 0) * fsi] -
	0.0820657541963819 * f[(i + 1) * fsi] + 0.00662464388311298 * f[(i + 2) * fsi];
      f14 =
	-0.00662464388311298 * f[(i - 6) * fsi] + 0.0558889847797802 * f[(i - 5) * fsi] -
	0.210728022070724 * f[(i - 4) * fsi] + 0.471195221007536 * f[(i - 3) * fsi] -
	0.708139182559549 * f[(i - 2) * fsi] + 0.800445924397664 * f[(i - 1) * fsi] +
	0.627030321459884 * f[(i + 0) * fsi] - 0.029068603131478 * f[(i + 1) * fsi];
      f15 =
	+0.029068603131478 * f[(i - 7) * fsi] - 0.239173468934937 * f[(i - 6) * fsi] +
	0.869809872461165 * f[(i - 5) * fsi] - 1.83856979743349 * f[(i - 4) * fsi] +
	2.505997440211 * f[(i - 3) * fsi] - 2.33598095792232 * f[(i - 2) * fsi] +
	1.61436681207905 * f[(i - 1) * fsi] + 0.394481496408059 * f[(i + 0) * fsi];
      f16 =
	+0.394481496408059 * f[(i + 0) * fsi] + 1.61436681207905 * f[(i + 1) * fsi] -
	2.33598095792232 * f[(i + 2) * fsi] + 2.50599744021101 * f[(i + 3) * fsi] -
	1.83856979743349 * f[(i + 4) * fsi] + 0.869809872461167 * f[(i + 5) * fsi] -
	0.239173468934938 * f[(i + 6) * fsi] + 0.0290686031314781 * f[(i + 7) * fsi];
      f17 =
	-0.0290686031314781 * f[(i - 1) * fsi] + 0.627030321459884 * f[(i + 0) * fsi] +
	0.800445924397664 * f[(i + 1) * fsi] - 0.708139182559549 * f[(i + 2) * fsi] +
	0.471195221007536 * f[(i + 3) * fsi] - 0.210728022070724 * f[(i + 4) * fsi] +
	0.0558889847797802 * f[(i + 5) * fsi] - 0.00662464388311298 * f[(i + 6) * fsi];
      f18 =
	+0.00662464388311298 * f[(i - 2) * fsi] - 0.0820657541963818 * f[(i - 1) * fsi] +
	0.812520350187047 * f[(i + 0) * fsi] + 0.429465866943337 * f[(i + 1) * fsi] -
	0.244414110741641 * f[(i + 2) * fsi] + 0.100215163553209 * f[(i + 3) * fsi] -
	0.0252379933435605 * f[(i + 4) * fsi] + 0.00289183371487634 * f[(i + 5) * fsi];
      f19 =
	-0.00289183371487634 * f[(i - 3) * fsi] + 0.0297593136021237 * f[(i - 2) * fsi] -
	0.163037098212919 * f[(i - 1) * fsi] + 0.974463038220122 * f[(i + 0) * fsi] +
	0.227037506901994 * f[(i + 1) * fsi] - 0.0824714227085657 * f[(i + 2) * fsi] +
	0.0192438195366716 * f[(i + 3) * fsi] - 0.0021033236245498 * f[(i + 4) * fsi];
      f20 =
	+0.0021033236245498 * f[(i - 4) * fsi] - 0.0197184227112747 * f[(i - 3) * fsi] +
	0.0886523750895181 * f[(i - 2) * fsi] - 0.280823221187708 * f[(i - 1) * fsi] +
	1.12169569193861 * f[(i + 0) * fsi] + 0.109251383927205 * f[(i + 1) * fsi] -
	0.0235783612211713 * f[(i + 2) * fsi] + 0.00241723054027316 * f[(i + 3) * fsi];
      f21 =
	-0.00241723054027316 * f[(i - 5) * fsi] + 0.0214411679467351 * f[(i - 4) * fsi] -
	0.0874008778389233 * f[(i - 3) * fsi] + 0.224017285344815 * f[(i - 2) * fsi] -
	0.45002935900683 * f[(i - 1) * fsi] + 1.25706060219391 * f[(i + 0) * fsi] +
	0.0415689287995565 * f[(i + 1) * fsi] - 0.00424051689898599 * f[(i + 2) * fsi];
      f22 =
	+0.00424051689898599 * f[(i - 6) * fsi] - 0.0363413657321611 * f[(i - 5) * fsi] +
	0.140175641118343 * f[(i - 4) * fsi] - 0.324869824182139 * f[(i - 3) * fsi] +
	0.520853468273835 * f[(i - 2) * fsi] - 0.687498305350045 * f[(i - 1) * fsi] +
	1.37579507536551 * f[(i + 0) * fsi] + 0.0076447936076685 * f[(i + 1) * fsi];
      f23 =
	-0.0076447936076685 * f[(i - 7) * fsi] + 0.065398865760334 * f[(i - 6) * fsi] -
	0.250395586746879 * f[(i - 5) * fsi] + 0.568284083147779 * f[(i - 4) * fsi] -
	0.860005376718934 * f[(i - 3) * fsi] + 0.948961910303271 * f[(i - 2) * fsi] -
	0.901552526364763 * f[(i - 1) * fsi] + 1.43695342422686 * f[(i + 0) * fsi];
      f24 =
	+0.125 * f[(i + 0) * fsi] + 1.71785714285714 * f[(i + 1) * fsi] -
	1.78214285714285 * f[(i + 2) * fsi] + 1.71785714285716 * f[(i + 3) * fsi] -
	1.19880952380952 * f[(i + 4) * fsi] + 0.551190476190474 * f[(i + 5) * fsi] -
	0.148809523809524 * f[(i + 6) * fsi] + 0.0178571428571429 * f[(i + 7) * fsi];
      f25 =
	-0.0178571428571428 * f[(i - 1) * fsi] + 0.267857142857143 * f[(i + 0) * fsi] +
	1.21785714285714 * f[(i + 1) * fsi] - 0.782142857142857 * f[(i + 2) * fsi] +
	0.467857142857143 * f[(i + 3) * fsi] - 0.198809523809523 * f[(i + 4) * fsi] +
	0.0511904761904762 * f[(i + 5) * fsi] - 0.00595238095238096 * f[(i + 6) * fsi];
      f26 =
	+0.00595238095238096 * f[(i - 2) * fsi] - 0.0654761904761904 * f[(i - 1) * fsi] +
	0.43452380952381 * f[(i + 0) * fsi] + 0.884523809523809 * f[(i + 1) * fsi] -
	0.365476190476191 * f[(i + 2) * fsi] + 0.134523809523809 * f[(i + 3) * fsi] -
	0.0321428571428572 * f[(i + 4) * fsi] + 0.00357142857142857 * f[(i + 5) * fsi];
      f27 =
	-0.00357142857142857 * f[(i - 3) * fsi] + 0.0345238095238095 * f[(i - 2) * fsi] -
	0.16547619047619 * f[(i - 1) * fsi] + 0.63452380952381 * f[(i + 0) * fsi] +
	0.63452380952381 * f[(i + 1) * fsi] - 0.16547619047619 * f[(i + 2) * fsi] +
	0.0345238095238096 * f[(i + 3) * fsi] - 0.00357142857142857 * f[(i + 4) * fsi];
      f28 =
	+0.00357142857142857 * f[(i - 4) * fsi] - 0.0321428571428571 * f[(i - 3) * fsi] +
	0.13452380952381 * f[(i - 2) * fsi] - 0.365476190476191 * f[(i - 1) * fsi] +
	0.884523809523809 * f[(i + 0) * fsi] + 0.43452380952381 * f[(i + 1) * fsi] -
	0.0654761904761905 * f[(i + 2) * fsi] + 0.00595238095238095 * f[(i + 3) * fsi];
      f29 =
	-0.00595238095238095 * f[(i - 5) * fsi] + 0.0511904761904762 * f[(i - 4) * fsi] -
	0.198809523809524 * f[(i - 3) * fsi] + 0.467857142857143 * f[(i - 2) * fsi] -
	0.782142857142857 * f[(i - 1) * fsi] + 1.21785714285714 * f[(i + 0) * fsi] +
	0.267857142857143 * f[(i + 1) * fsi] - 0.0178571428571429 * f[(i + 2) * fsi];
      f30 =
	+0.0178571428571429 * f[(i - 6) * fsi] - 0.148809523809524 * f[(i - 5) * fsi] +
	0.551190476190476 * f[(i - 4) * fsi] - 1.19880952380952 * f[(i - 3) * fsi] +
	1.71785714285714 * f[(i - 2) * fsi] - 1.78214285714286 * f[(i - 1) * fsi] +
	1.71785714285714 * f[(i + 0) * fsi] + 0.125 * f[(i + 1) * fsi];
      f31 =
	-0.125 * f[(i - 7) * fsi] + 1.01785714285714 * f[(i - 6) * fsi] -
	3.64880952380952 * f[(i - 5) * fsi] + 7.55119047619048 * f[(i - 4) * fsi] -
	9.94880952380952 * f[(i - 3) * fsi] + 8.71785714285714 * f[(i - 2) * fsi] -
	5.28214285714286 * f[(i - 1) * fsi] + 2.71785714285714 * f[(i + 0) * fsi];
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
	f24 * omega24 + f25 * omega25 + f26 * omega26 + f27 * omega27 + f28 * omega28 +
	f29 * omega29 + f30 * omega30 + f31 * omega31;
      fr[i * frsi + 0 * frsl] = fr0;
      fr[i * frsi + 1 * frsl] = fr1;
      fr[i * frsi + 2 * frsl] = fr2;
      fr[i * frsi + 3 * frsl] = fr3;
    }
}

PyObject *
py_gauss_lobatto008004 (PyObject * self, PyObject * args)
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

  gauss_lobatto008004 (f, n, fsi, sigma, ssi, ssr, fr, frsi, frsl);

  Py_INCREF (Py_None);
  return Py_None;
}
