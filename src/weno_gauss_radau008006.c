#include <Python.h>
#include <numpy/ndarrayobject.h>

void
gauss_radau008006 (const double *restrict f, int n, int fsi,
		   const double *restrict sigma, int ssi, int ssr,
		   double *restrict fr, int frsi, int frsl)
{
  int i;
  double sigma0, sigma1, sigma2, sigma3, sigma4, sigma5, sigma6, sigma7, omega39, omega11, omega46,
    omega7, omega27m, omega22, omega14, omega28m, omega41, omega27p, omega21, omega3, omega32,
    omega10, omega45, omega28p, omega16, omega30p, omega36, omega31m, omega13, omega29m, omega40,
    omega18, omega33, omega9, omega31p, omega26p, omega23, omega44, omega0, omega25m, omega26m,
    omega37, omega4, omega12, omega19, omega17, omega24m, omega34, omega8, omega25p, omega43,
    omega1, omega30m, omega38, omega29p, omega47, omega2, omega6, omega24p, omega35, omega15,
    omega5, omega42, omega20, accumulator, f39, f11, f24, f44, f7, f46, f22, f14, f41, f31, f21, f3,
    f32, f10, f27, f16, f36, f13, f30, f18, f47, f43, f33, f9, f23, f26, f0, f40, f37, f4, f45, f12,
    f19, f17, f34, f8, f29, f1, f38, f42, f25, f2, f6, f35, f15, f5, f28, f20, fr0, fr1, fr2, fr3,
    fr4, fr5;
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
      omega8 = +0.000265378733869745 / (1.0e-6 + sigma0) / (1.0e-6 + sigma0);
      accumulator += omega8;
      omega9 = +0.0117064211824668 / (1.0e-6 + sigma1) / (1.0e-6 + sigma1);
      accumulator += omega9;
      omega10 = +0.107513253912723 / (1.0e-6 + sigma2) / (1.0e-6 + sigma2);
      accumulator += omega10;
      omega11 = +0.32353621424711 / (1.0e-6 + sigma3) / (1.0e-6 + sigma3);
      accumulator += omega11;
      omega12 = +0.369405167393987 / (1.0e-6 + sigma4) / (1.0e-6 + sigma4);
      accumulator += omega12;
      omega13 = +0.162178716590763 / (1.0e-6 + sigma5) / (1.0e-6 + sigma5);
      accumulator += omega13;
      omega14 = +0.0245113650408801 / (1.0e-6 + sigma6) / (1.0e-6 + sigma6);
      accumulator += omega14;
      omega15 = +0.000883482898202071 / (1.0e-6 + sigma7) / (1.0e-6 + sigma7);
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
      omega16 = +0.00966826378212015 / (1.0e-6 + sigma0) / (1.0e-6 + sigma0);
      accumulator += omega16;
      omega17 = +0.0224051745899589 / (1.0e-6 + sigma1) / (1.0e-6 + sigma1);
      accumulator += omega17;
      omega18 = +0.162434993658721 / (1.0e-6 + sigma2) / (1.0e-6 + sigma2);
      accumulator += omega18;
      omega19 = +0.358309803405691 / (1.0e-6 + sigma3) / (1.0e-6 + sigma3);
      accumulator += omega19;
      omega20 = +0.320445223916675 / (1.0e-6 + sigma4) / (1.0e-6 + sigma4);
      accumulator += omega20;
      omega21 = +0.112787611388599 / (1.0e-6 + sigma5) / (1.0e-6 + sigma5);
      accumulator += omega21;
      omega22 = +0.0135783111438629 / (1.0e-6 + sigma6) / (1.0e-6 + sigma6);
      accumulator += omega22;
      omega23 = +0.000370618114371009 / (1.0e-6 + sigma7) / (1.0e-6 + sigma7);
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
      omega24p = +0.000211088141352459 / +4.27395969883794 / (1.0e-6 + sigma0) / (1.0e-6 + sigma0);
      accumulator += omega24p;
      omega25p = +0.00950050036540072 / +4.27395969883794 / (1.0e-6 + sigma1) / (1.0e-6 + sigma1);
      accumulator += omega25p;
      omega26p = +0.0919886657267216 / +4.27395969883794 / (1.0e-6 + sigma2) / (1.0e-6 + sigma2);
      accumulator += omega26p;
      omega27p = +0.271303532928674 / +4.27395969883794 / (1.0e-6 + sigma3) / (1.0e-6 + sigma3);
      accumulator += omega27p;
      omega28p = +0.733229914668533 / +4.27395969883794 / (1.0e-6 + sigma4) / (1.0e-6 + sigma4);
      accumulator += omega28p;
      omega29p = +3.14296934539648 / +4.27395969883794 / (1.0e-6 + sigma5) / (1.0e-6 + sigma5);
      accumulator += omega29p;
      omega30p = +0.024523759642022 / +4.27395969883794 / (1.0e-6 + sigma6) / (1.0e-6 + sigma6);
      accumulator += omega30p;
      omega31p = +0.000232891968760521 / +4.27395969883794 / (1.0e-6 + sigma7) / (1.0e-6 + sigma7);
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
      omega24m = +0.00010554407067623 / +3.27395969883794 / (1.0e-6 + sigma0) / (1.0e-6 + sigma0);
      accumulator += omega24m;
      omega25m = +0.00475025018270036 / +3.27395969883794 / (1.0e-6 + sigma1) / (1.0e-6 + sigma1);
      accumulator += omega25m;
      omega26m = +0.0459943328633608 / +3.27395969883794 / (1.0e-6 + sigma2) / (1.0e-6 + sigma2);
      accumulator += omega26m;
      omega27m = +0.135651766464337 / +3.27395969883794 / (1.0e-6 + sigma3) / (1.0e-6 + sigma3);
      accumulator += omega27m;
      omega28m = +1.46645982933707 / +3.27395969883794 / (1.0e-6 + sigma4) / (1.0e-6 + sigma4);
      accumulator += omega28m;
      omega29m = +1.57148467269824 / +3.27395969883794 / (1.0e-6 + sigma5) / (1.0e-6 + sigma5);
      accumulator += omega29m;
      omega30m = +0.0490475192840441 / +3.27395969883794 / (1.0e-6 + sigma6) / (1.0e-6 + sigma6);
      accumulator += omega30m;
      omega31m = +0.000465783937521042 / +3.27395969883794 / (1.0e-6 + sigma7) / (1.0e-6 + sigma7);
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
      omega32 = +0.000608033916428637 / (1.0e-6 + sigma0) / (1.0e-6 + sigma0);
      accumulator += omega32;
      omega33 = +0.0191672678874425 / (1.0e-6 + sigma1) / (1.0e-6 + sigma1);
      accumulator += omega33;
      omega34 = +0.140515120679808 / (1.0e-6 + sigma2) / (1.0e-6 + sigma2);
      accumulator += omega34;
      omega35 = +0.352504658875921 / (1.0e-6 + sigma3) / (1.0e-6 + sigma3);
      accumulator += omega35;
      omega36 = +0.341874433359514 / (1.0e-6 + sigma4) / (1.0e-6 + sigma4);
      accumulator += omega36;
      omega37 = +0.128240218086116 / (1.0e-6 + sigma5) / (1.0e-6 + sigma5);
      accumulator += omega37;
      omega38 = +0.0165567429013989 / (1.0e-6 + sigma6) / (1.0e-6 + sigma6);
      accumulator += omega38;
      omega39 = +0.000533524293381427 / (1.0e-6 + sigma7) / (1.0e-6 + sigma7);
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
      omega40 = +0.00108428383332179 / (1.0e-6 + sigma0) / (1.0e-6 + sigma0);
      accumulator += omega40;
      omega41 = +0.0279440863656904 / (1.0e-6 + sigma1) / (1.0e-6 + sigma1);
      accumulator += omega41;
      omega42 = +0.17443052178329 / (1.0e-6 + sigma2) / (1.0e-6 + sigma2);
      accumulator += omega42;
      omega43 = +0.376643140520915 / (1.0e-6 + sigma3) / (1.0e-6 + sigma3);
      accumulator += omega43;
      omega44 = +0.312361920663785 / (1.0e-6 + sigma4) / (1.0e-6 + sigma4);
      accumulator += omega44;
      omega45 = +0.0975569397584915 / (1.0e-6 + sigma5) / (1.0e-6 + sigma5);
      accumulator += omega45;
      omega46 = +0.00978759495889775 / (1.0e-6 + sigma6) / (1.0e-6 + sigma6);
      accumulator += omega46;
      omega47 = +0.000191512115565768 / (1.0e-6 + sigma7) / (1.0e-6 + sigma7);
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
	+2.18703615122483 * f[(i + 0) * fsi] - 3.37341329077579 * f[(i + 1) * fsi] +
	5.21054889976479 * f[(i + 2) * fsi] - 5.77872149936885 * f[(i + 3) * fsi] +
	4.31843397582863 * f[(i + 4) * fsi] - 2.066579428697 * f[(i + 5) * fsi] +
	0.572690028841657 * f[(i + 6) * fsi] - 0.0699948368182738 * f[(i + 7) * fsi];
      f9 =
	+0.0699948368182738 * f[(i - 1) * fsi] + 1.62707745667864 * f[(i + 0) * fsi] -
	1.41355785986413 * f[(i + 1) * fsi] + 1.29083803794145 * f[(i + 2) * fsi] -
	0.879082922089679 * f[(i + 3) * fsi] + 0.398723114005302 * f[(i + 4) * fsi] -
	0.10672399778533 * f[(i + 5) * fsi] + 0.0127313342954667 * f[(i + 6) * fsi];
      f10 =
	-0.0127313342954667 * f[(i - 2) * fsi] + 0.171845511182007 * f[(i - 1) * fsi] +
	1.27060009640557 * f[(i + 0) * fsi] - 0.700603139317991 * f[(i + 1) * fsi] +
	0.399644637258785 * f[(i + 2) * fsi] - 0.166128201543544 * f[(i + 3) * fsi] +
	0.0422457537322344 * f[(i + 4) * fsi] - 0.00487332342159677 * f[(i + 5) * fsi];
      f11 =
	+0.00487332342159677 * f[(i - 3) * fsi] - 0.0517179216682409 * f[(i - 2) * fsi] +
	0.308298566986717 * f[(i - 1) * fsi] + 0.997693984796153 * f[(i + 0) * fsi] -
	0.359470499806217 * f[(i + 1) * fsi] + 0.126738525649366 * f[(i + 2) * fsi] -
	0.0296751457388348 * f[(i + 3) * fsi] + 0.00325916635946019 * f[(i + 4) * fsi];
      f12 =
	-0.00325916635946019 * f[(i - 4) * fsi] + 0.0309466542972783 * f[(i - 3) * fsi] -
	0.142974579733126 * f[(i - 2) * fsi] + 0.490811883116488 * f[(i - 1) * fsi] +
	0.769552339633939 * f[(i + 0) * fsi] - 0.176957183676446 * f[(i + 1) * fsi] +
	0.0354818675844809 * f[(i + 2) * fsi] - 0.00360181486315328 * f[(i + 3) * fsi];
      f13 =
	+0.00360181486315328 * f[(i - 5) * fsi] - 0.0320736852646865 * f[(i - 4) * fsi] +
	0.13179747046557 * f[(i - 3) * fsi] - 0.34467621206971 * f[(i - 2) * fsi] +
	0.742938923537217 * f[(i - 1) * fsi] + 0.567850707297355 * f[(i + 0) * fsi] -
	0.0761063675081542 * f[(i + 1) * fsi] + 0.00666734867925465 * f[(i + 2) * fsi];
      f14 =
	-0.00666734867925465 * f[(i - 6) * fsi] + 0.0569406042971905 * f[(i - 5) * fsi] -
	0.218759448283817 * f[(i - 4) * fsi] + 0.505168996503831 * f[(i - 3) * fsi] -
	0.811390619617535 * f[(i - 2) * fsi] + 1.11631044957548 * f[(i - 1) * fsi] +
	0.381164944278225 * f[(i + 0) * fsi] - 0.0227675780741171 * f[(i + 1) * fsi];
      f15 =
	+0.0227675780741171 * f[(i - 7) * fsi] - 0.188807973272191 * f[(i - 6) * fsi] +
	0.694432790372469 * f[(i - 5) * fsi] - 1.49374382043437 * f[(i - 4) * fsi] +
	2.09889946169203 * f[(i - 3) * fsi] - 2.08637499176809 * f[(i - 2) * fsi] +
	1.75380263565076 * f[(i - 1) * fsi] + 0.199024319685288 * f[(i + 0) * fsi];
      f16 =
	+1.33950304832409 * f[(i + 0) * fsi] - 0.607172135960933 * f[(i + 1) * fsi] +
	0.475572436686003 * f[(i + 2) * fsi] - 0.330835619889965 * f[(i + 3) * fsi] +
	0.171952844328262 * f[(i + 4) * fsi] - 0.0605969046861807 * f[(i + 5) * fsi] +
	0.0127913233680047 * f[(i + 6) * fsi] - 0.00121499216928351 * f[(i + 7) * fsi];
      f17 =
	+0.00121499216928353 * f[(i - 1) * fsi] + 1.32978311096982 * f[(i + 0) * fsi] -
	0.573152355220995 * f[(i + 1) * fsi] + 0.407532875206126 * f[(i + 2) * fsi] -
	0.245786168040118 * f[(i + 3) * fsi] + 0.103913282848384 * f[(i + 4) * fsi] -
	0.0265771239462423 * f[(i + 5) * fsi] + 0.0030713860137366 * f[(i + 6) * fsi];
      f18 =
	-0.00307138601373661 * f[(i - 2) * fsi] + 0.0257860802791764 * f[(i - 1) * fsi] +
	1.2437843025852 * f[(i + 0) * fsi] - 0.401154738451745 * f[(i + 1) * fsi] +
	0.192535854244564 * f[(i + 2) * fsi] - 0.0737885512708678 * f[(i + 3) * fsi] +
	0.0179144744637586 * f[(i + 4) * fsi] - 0.00200603583634948 * f[(i + 5) * fsi];
      f19 =
	+0.00200603583634948 * f[(i - 3) * fsi] - 0.0191196727045325 * f[(i - 2) * fsi] +
	0.0819550836969618 * f[(i - 1) * fsi] + 1.13144629574963 * f[(i + 0) * fsi] -
	0.260732229907281 * f[(i + 1) * fsi] + 0.0801978474089933 * f[(i + 2) * fsi] -
	0.0176195478530823 * f[(i + 3) * fsi] + 0.00186618777296271 * f[(i + 4) * fsi];
      f20 =
	-0.00186618777296271 * f[(i - 4) * fsi] + 0.0169355380200511 * f[(i - 3) * fsi] -
	0.0713729303474882 * f[(i - 2) * fsi] + 0.186461598982873 * f[(i - 1) * fsi] +
	1.00081315164224 * f[(i + 0) * fsi] - 0.15622571462137 * f[(i + 1) * fsi] +
	0.0279445897660375 * f[(i + 2) * fsi] - 0.00269004566938069 * f[(i + 3) * fsi];
      f21 =
	+0.00269004566938069 * f[(i - 5) * fsi] - 0.0233865531280082 * f[(i - 4) * fsi] +
	0.0922568167627105 * f[(i - 3) * fsi] - 0.222015487832807 * f[(i - 2) * fsi] +
	0.374764795839522 * f[(i - 1) * fsi] + 0.85017059415692 * f[(i + 0) * fsi] -
	0.0809044358787102 * f[(i + 1) * fsi] + 0.00642422441099199 * f[(i + 2) * fsi];
      f22 =
	-0.00642422441099198 * f[(i - 6) * fsi] + 0.0540838409573166 * f[(i - 5) * fsi] -
	0.203264836635784 * f[(i - 4) * fsi] + 0.452013383778262 * f[(i - 3) * fsi] -
	0.671711196602246 * f[(i - 2) * fsi] + 0.734521362855073 * f[(i - 1) * fsi] +
	0.670292310649145 * f[(i + 0) * fsi] - 0.0295106405907743 * f[(i + 1) * fsi];
      f23 =
	+0.0295106405907743 * f[(i - 7) * fsi] - 0.242509349137186 * f[(i - 6) * fsi] +
	0.880381777498997 * f[(i - 5) * fsi] - 1.85586070971914 * f[(i - 4) * fsi] +
	2.51775822513246 * f[(i - 3) * fsi] - 2.32430706968561 * f[(i - 2) * fsi] +
	1.56081929939675 * f[(i - 1) * fsi] + 0.43420718592295 * f[(i + 0) * fsi];
      f24 =
	+0.662495241552487 * f[(i + 0) * fsi] + 1.1535967138899 * f[(i + 1) * fsi] -
	1.99898441281358 * f[(i + 2) * fsi] + 2.27709808203838 * f[(i + 3) * fsi] -
	1.71984583044421 * f[(i + 4) * fsi] + 0.827535508310682 * f[(i + 5) * fsi] -
	0.230075953333773 * f[(i + 6) * fsi] + 0.0281806508001168 * f[(i + 7) * fsi];
      f25 =
	-0.0281806508001168 * f[(i - 1) * fsi] + 0.88794044795342 * f[(i + 0) * fsi] +
	0.364538491486634 * f[(i + 1) * fsi] - 0.420867968007044 * f[(i + 2) * fsi] +
	0.304452526030208 * f[(i + 3) * fsi] - 0.141729385637675 * f[(i + 4) * fsi] +
	0.0384772859074127 * f[(i + 5) * fsi] - 0.00463074693283928 * f[(i + 6) * fsi];
      f26 =
	+0.00463074693283928 * f[(i - 2) * fsi] - 0.0652266262628309 * f[(i - 1) * fsi] +
	1.01760136207292 * f[(i + 0) * fsi] + 0.105216663247634 * f[(i + 1) * fsi] -
	0.0967156827082946 * f[(i + 2) * fsi] + 0.0451306977912084 * f[(i + 3) * fsi] -
	0.0120684715181754 * f[(i + 4) * fsi] + 0.00143131044469853 * f[(i + 5) * fsi];
      f27 =
	-0.00143131044469853 * f[(i - 3) * fsi] + 0.0160812304904275 * f[(i - 2) * fsi] -
	0.10530331871439 * f[(i - 1) * fsi] + 1.09775474697604 * f[(i + 0) * fsi] +
	0.00502493211873778 * f[(i + 1) * fsi] - 0.0165622978051772 * f[(i + 2) * fsi] +
	0.00505400533964965 * f[(i + 3) * fsi] - 0.000617987960587184 * f[(i + 4) * fsi];
      f28 =
	+0.000617987960587184 * f[(i - 4) * fsi] - 0.00637521412939599 * f[(i - 3) * fsi] +
	0.0333848933868686 * f[(i - 2) * fsi] - 0.139910644507272 * f[(i - 1) * fsi] +
	1.14101390421714 * f[(i + 0) * fsi] - 0.0295823936741446 * f[(i + 1) * fsi] +
	0.000741365091263983 * f[(i + 2) * fsi] + 0.000110101654952179 * f[(i + 3) * fsi];
      f29 =
	-0.000110101654952178 * f[(i - 5) * fsi] + 0.00149880120020461 * f[(i - 4) * fsi] -
	0.00945806046805697 * f[(i - 3) * fsi] + 0.0395505860641907 * f[(i - 2) * fsi] -
	0.147617760353924 * f[(i - 1) * fsi] + 1.14717959689446 * f[(i + 0) * fsi] -
	0.0326652400128056 * f[(i + 1) * fsi] + 0.0016221783308814 * f[(i + 2) * fsi];
      f30 =
	-0.0016221783308814 * f[(i - 6) * fsi] + 0.012867324992099 * f[(i - 5) * fsi] -
	0.0439221920644745 * f[(i - 4) * fsi] + 0.0813839260613013 * f[(i - 3) * fsi] -
	0.0740018970975073 * f[(i - 2) * fsi] - 0.0567757738245662 * f[(i - 1) * fsi] +
	1.10175860362978 * f[(i + 0) * fsi] - 0.0196878133657544 * f[(i + 1) * fsi];
      f31 =
	+0.0196878133657544 * f[(i - 7) * fsi] - 0.159124685256917 * f[(i - 6) * fsi] +
	0.564126099233222 * f[(i - 5) * fsi] - 1.14643974054672 * f[(i - 4) * fsi] +
	1.45953086166411 * f[(i - 3) * fsi] - 1.17651944557975 * f[(i - 2) * fsi] +
	0.494483000416557 * f[(i - 1) * fsi] + 0.944256096703748 * f[(i + 0) * fsi];
      f32 =
	+0.297268163345398 * f[(i + 0) * fsi] + 1.71440940352323 * f[(i + 1) * fsi] -
	2.2866679239896 * f[(i + 2) * fsi] + 2.38726669512716 * f[(i + 3) * fsi] -
	1.72880823729031 * f[(i + 4) * fsi] + 0.811749795306206 * f[(i + 5) * fsi] -
	0.222122185985653 * f[(i + 6) * fsi] + 0.0269042899635739 * f[(i + 7) * fsi];
      f33 =
	-0.0269042899635739 * f[(i - 1) * fsi] + 0.512502483053989 * f[(i + 0) * fsi] +
	0.961089284543159 * f[(i + 1) * fsi] - 0.780027686029469 * f[(i + 2) * fsi] +
	0.503966397676993 * f[(i + 3) * fsi] - 0.22216799933017 * f[(i + 4) * fsi] +
	0.0584296763261353 * f[(i + 5) * fsi] - 0.00688786627706251 * f[(i + 6) * fsi];
      f34 =
	+0.00688786627706251 * f[(i - 2) * fsi] - 0.0820072201800739 * f[(i - 1) * fsi] +
	0.705362738811739 * f[(i + 0) * fsi] + 0.575368773027658 * f[(i + 1) * fsi] -
	0.297877046635094 * f[(i + 2) * fsi] + 0.118245886161492 * f[(i + 3) * fsi] -
	0.0293077435724198 * f[(i + 4) * fsi] + 0.00332674610963511 * f[(i + 5) * fsi];
      f35 =
	-0.00332674610963511 * f[(i - 3) * fsi] + 0.0335018351541434 * f[(i - 2) * fsi] -
	0.175156111249857 * f[(i - 1) * fsi] + 0.891660520951306 * f[(i + 0) * fsi] +
	0.342496545353201 * f[(i + 1) * fsi] - 0.111579264495527 * f[(i + 2) * fsi] +
	0.0250969950917085 * f[(i + 3) * fsi] - 0.00269377469533889 * f[(i + 4) * fsi];
      f36 =
	+0.00269377469533889 * f[(i - 4) * fsi] - 0.0248769436723462 * f[(i - 3) * fsi] +
	0.108927526623632 * f[(i - 2) * fsi] - 0.326007494188835 * f[(i - 1) * fsi] +
	1.08022474962503 * f[(i + 0) * fsi] + 0.191645162414223 * f[(i + 1) * fsi] -
	0.0361535730260384 * f[(i + 2) * fsi] + 0.00354679752899741 * f[(i + 3) * fsi];
      f37 =
	-0.00354679752899741 * f[(i - 5) * fsi] + 0.0310681549273182 * f[(i - 4) * fsi] -
	0.124187274484274 * f[(i - 3) * fsi] + 0.307548188247487 * f[(i - 2) * fsi] -
	0.574283321218654 * f[(i - 1) * fsi] + 1.27884541124888 * f[(i + 0) * fsi] +
	0.0923348316022956 * f[(i + 1) * fsi] - 0.00777919279405913 * f[(i + 2) * fsi];
      f38 =
	+0.00777919279405913 * f[(i - 6) * fsi] - 0.0657803398814704 * f[(i - 5) * fsi] +
	0.248885553160974 * f[(i - 4) * fsi] - 0.559822070951585 * f[(i - 3) * fsi] +
	0.852091683831626 * f[(i - 2) * fsi] - 1.00991811768596 * f[(i - 1) * fsi] +
	1.49666280948254 * f[(i + 0) * fsi] + 0.0301012892498226 * f[(i + 1) * fsi];
      f39 =
	-0.0301012892498226 * f[(i - 7) * fsi] + 0.24858950679264 * f[(i - 6) * fsi] -
	0.908616438876503 * f[(i - 5) * fsi] + 1.93455775115104 * f[(i - 4) * fsi] -
	2.66691231843917 * f[(i - 3) * fsi] + 2.53776388182169 * f[(i - 2) * fsi] -
	1.852754216681 * f[(i - 1) * fsi] + 1.73747312348112 * f[(i + 0) * fsi];
      f40 =
	+0.152396806949889 * f[(i + 0) * fsi] + 1.74001755378569 * f[(i + 1) * fsi] -
	1.91492436856862 * f[(i + 2) * fsi] + 1.87983972582765 * f[(i + 3) * fsi] -
	1.3228220523165 * f[(i + 4) * fsi] + 0.611060122938181 * f[(i + 5) * fsi] -
	0.165464263706264 * f[(i + 6) * fsi] + 0.0198964750899675 * f[(i + 7) * fsi];
      f41 =
	-0.0198964750899676 * f[(i - 1) * fsi] + 0.311568607669629 * f[(i + 0) * fsi] +
	1.18291625126659 * f[(i + 1) * fsi] - 0.800721763530434 * f[(i + 2) * fsi] +
	0.487086469529924 * f[(i + 3) * fsi] - 0.208619447278314 * f[(i + 4) * fsi] +
	0.0539588204190955 * f[(i + 5) * fsi] - 0.00629246298652466 * f[(i + 6) * fsi];
      f42 =
	+0.00629246298652466 * f[(i - 2) * fsi] - 0.0702361789821649 * f[(i - 1) * fsi] +
	0.48775757129232 * f[(i + 0) * fsi] + 0.830538324021213 * f[(i + 1) * fsi] -
	0.360249354473708 * f[(i + 2) * fsi] + 0.134708542284542 * f[(i + 3) * fsi] -
	0.0324304836556244 * f[(i + 4) * fsi] + 0.00361911652689816 * f[(i + 5) * fsi];
      f43 =
	-0.00361911652689815 * f[(i - 3) * fsi] + 0.0352453952017099 * f[(i - 2) * fsi] -
	0.171571441735313 * f[(i - 1) * fsi] + 0.690428096798616 * f[(i + 0) * fsi] +
	0.577200167138342 * f[(i + 1) * fsi] - 0.157578828967412 * f[(i + 2) * fsi] +
	0.0333732795313937 * f[(i + 3) * fsi] - 0.00347755144043913 * f[(i + 4) * fsi];
      f44 =
	+0.00347755144043913 * f[(i - 4) * fsi] - 0.0314395280504111 * f[(i - 3) * fsi] +
	0.132616835534005 * f[(i - 2) * fsi] - 0.366314322399904 * f[(i - 1) * fsi] +
	0.933856697629355 * f[(i + 0) * fsi] + 0.382457286473751 * f[(i + 1) * fsi] -
	0.060207388635116 * f[(i + 2) * fsi] + 0.0055528680078807 * f[(i + 3) * fsi];
      f45 =
	-0.00555286800788071 * f[(i - 5) * fsi] + 0.0479004955034848 * f[(i - 4) * fsi] -
	0.186919832271071 * f[(i - 3) * fsi] + 0.443577443975325 * f[(i - 2) * fsi] -
	0.755015082951554 * f[(i - 1) * fsi] + 1.24481730607067 * f[(i + 0) * fsi] +
	0.226976982253091 * f[(i + 1) * fsi] - 0.0157844445720704 * f[(i + 2) * fsi];
      f46 =
	+0.0157844445720704 * f[(i - 6) * fsi] - 0.131828424584444 * f[(i - 5) * fsi] +
	0.489864943521456 * f[(i - 4) * fsi] - 1.07084872830701 * f[(i - 3) * fsi] +
	1.54848856402025 * f[(i - 2) * fsi] - 1.6389439789875 * f[(i - 1) * fsi] +
	1.68678175408865 * f[(i + 0) * fsi] + 0.100701425676528 * f[(i + 1) * fsi];
      f47 =
	-0.100701425676528 * f[(i - 7) * fsi] + 0.821395849984295 * f[(i - 6) * fsi] -
	2.95146834352723 * f[(i - 5) * fsi] + 6.12914478140703 * f[(i - 4) * fsi] -
	8.11994852566398 * f[(i - 3) * fsi] + 7.18776840190583 * f[(i - 2) * fsi] -
	4.45858389793028 * f[(i - 1) * fsi] + 2.49239315950087 * f[(i + 0) * fsi];
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
	+4.27395969883794 * (f24 * omega24p + f25 * omega25p + f26 * omega26p + f27 * omega27p +
			     f28 * omega28p + f29 * omega29p + f30 * omega30p + f31 * omega31p) -
	+3.27395969883794 * (f24 * omega24m + f25 * omega25m + f26 * omega26m + f27 * omega27m +
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
py_gauss_radau008006 (PyObject * self, PyObject * args)
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

  gauss_radau008006 (f, n, fsi, sigma, ssi, ssr, fr, frsi, frsl);

  Py_INCREF (Py_None);
  return Py_None;
}
