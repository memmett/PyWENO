#include <Python.h>
#include <numpy/ndarrayobject.h>

void
gauss_radau007005 (const double *restrict f, int n, int fsi,
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
      omega0 = +0.000582750582750583 / (1.0e-6 + sigma0) / (1.0e-6 + sigma0);
      accumulator += omega0;
      omega1 = +0.0244755244755245 / (1.0e-6 + sigma1) / (1.0e-6 + sigma1);
      accumulator += omega1;
      omega2 = +0.183566433566434 / (1.0e-6 + sigma2) / (1.0e-6 + sigma2);
      accumulator += omega2;
      omega3 = +0.407925407925408 / (1.0e-6 + sigma3) / (1.0e-6 + sigma3);
      accumulator += omega3;
      omega4 = +0.305944055944056 / (1.0e-6 + sigma4) / (1.0e-6 + sigma4);
      accumulator += omega4;
      omega5 = +0.0734265734265734 / (1.0e-6 + sigma5) / (1.0e-6 + sigma5);
      accumulator += omega5;
      omega6 = +0.00407925407925408 / (1.0e-6 + sigma6) / (1.0e-6 + sigma6);
      accumulator += omega6;
      omega0 /= accumulator;
      omega1 /= accumulator;
      omega2 /= accumulator;
      omega3 /= accumulator;
      omega4 /= accumulator;
      omega5 /= accumulator;
      omega6 /= accumulator;
      accumulator = 0.0;
      omega7 = +0.00121939226039659 / (1.0e-6 + sigma0) / (1.0e-6 + sigma0);
      accumulator += omega7;
      omega8 = +0.0357274717318441 / (1.0e-6 + sigma1) / (1.0e-6 + sigma1);
      accumulator += omega8;
      omega9 = +0.218885913399421 / (1.0e-6 + sigma2) / (1.0e-6 + sigma2);
      accumulator += omega9;
      omega10 = +0.415709037183488 / (1.0e-6 + sigma3) / (1.0e-6 + sigma3);
      accumulator += omega10;
      omega11 = +0.270080906899534 / (1.0e-6 + sigma4) / (1.0e-6 + sigma4);
      accumulator += omega11;
      omega12 = +0.0557987537066396 / (1.0e-6 + sigma5) / (1.0e-6 + sigma5);
      accumulator += omega12;
      omega13 = +0.0025785248186778 / (1.0e-6 + sigma6) / (1.0e-6 + sigma6);
      accumulator += omega13;
      omega7 /= accumulator;
      omega8 /= accumulator;
      omega9 /= accumulator;
      omega10 /= accumulator;
      omega11 /= accumulator;
      omega12 /= accumulator;
      omega13 /= accumulator;
      accumulator = 0.0;
      omega14p = +0.0014030767484578 / +3.0641123835583 / (1.0e-6 + sigma0) / (1.0e-6 + sigma0);
      accumulator += omega14p;
      omega15p = +0.35330105110431 / +3.0641123835583 / (1.0e-6 + sigma1) / (1.0e-6 + sigma1);
      accumulator += omega15p;
      omega16p = +1.93569181545457 / +3.0641123835583 / (1.0e-6 + sigma2) / (1.0e-6 + sigma2);
      accumulator += omega16p;
      omega17p = +0.494670528481526 / +3.0641123835583 / (1.0e-6 + sigma3) / (1.0e-6 + sigma3);
      accumulator += omega17p;
      omega18p = +0.242931934502193 / +3.0641123835583 / (1.0e-6 + sigma4) / (1.0e-6 + sigma4);
      accumulator += omega18p;
      omega19p = +0.0350554451197829 / +3.0641123835583 / (1.0e-6 + sigma5) / (1.0e-6 + sigma5);
      accumulator += omega19p;
      omega20p = +0.00105853214746292 / +3.0641123835583 / (1.0e-6 + sigma6) / (1.0e-6 + sigma6);
      accumulator += omega20p;
      omega14p /= accumulator;
      omega15p /= accumulator;
      omega16p /= accumulator;
      omega17p /= accumulator;
      omega18p /= accumulator;
      omega19p /= accumulator;
      omega20p /= accumulator;
      accumulator = 0.0;
      omega14m = +0.0028061534969156 / +2.0641123835583 / (1.0e-6 + sigma0) / (1.0e-6 + sigma0);
      accumulator += omega14m;
      omega15m = +0.70660210220862 / +2.0641123835583 / (1.0e-6 + sigma1) / (1.0e-6 + sigma1);
      accumulator += omega15m;
      omega16m = +0.967845907727286 / +2.0641123835583 / (1.0e-6 + sigma2) / (1.0e-6 + sigma2);
      accumulator += omega16m;
      omega17m = +0.247335264240763 / +2.0641123835583 / (1.0e-6 + sigma3) / (1.0e-6 + sigma3);
      accumulator += omega17m;
      omega18m = +0.121465967251096 / +2.0641123835583 / (1.0e-6 + sigma4) / (1.0e-6 + sigma4);
      accumulator += omega18m;
      omega19m = +0.0175277225598914 / +2.0641123835583 / (1.0e-6 + sigma5) / (1.0e-6 + sigma5);
      accumulator += omega19m;
      omega20m = +0.000529266073731461 / +2.0641123835583 / (1.0e-6 + sigma6) / (1.0e-6 + sigma6);
      accumulator += omega20m;
      omega14m /= accumulator;
      omega15m /= accumulator;
      omega16m /= accumulator;
      omega17m /= accumulator;
      omega18m /= accumulator;
      omega19m /= accumulator;
      omega20m /= accumulator;
      accumulator = 0.0;
      omega21 = +0.0014931665940464 / (1.0e-6 + sigma0) / (1.0e-6 + sigma0);
      accumulator += omega21;
      omega22 = +0.0392608637990718 / (1.0e-6 + sigma1) / (1.0e-6 + sigma1);
      accumulator += omega22;
      omega23 = +0.22417793306837 / (1.0e-6 + sigma2) / (1.0e-6 + sigma2);
      accumulator += omega23;
      omega24 = +0.408669295973763 / (1.0e-6 + sigma3) / (1.0e-6 + sigma3);
      accumulator += omega24;
      omega25 = +0.26368779251812 / (1.0e-6 + sigma4) / (1.0e-6 + sigma4);
      accumulator += omega25;
      omega26 = +0.0579412173250924 / (1.0e-6 + sigma5) / (1.0e-6 + sigma5);
      accumulator += omega26;
      omega27 = +0.0047697307215365 / (1.0e-6 + sigma6) / (1.0e-6 + sigma6);
      accumulator += omega27;
      omega21 /= accumulator;
      omega22 /= accumulator;
      omega23 /= accumulator;
      omega24 /= accumulator;
      omega25 /= accumulator;
      omega26 /= accumulator;
      omega27 /= accumulator;
      accumulator = 0.0;
      omega28 = +0.00339771402760298 / (1.0e-6 + sigma0) / (1.0e-6 + sigma0);
      accumulator += omega28;
      omega29 = +0.0659396689445614 / (1.0e-6 + sigma1) / (1.0e-6 + sigma1);
      accumulator += omega29;
      omega30 = +0.291930054467664 / (1.0e-6 + sigma2) / (1.0e-6 + sigma2);
      accumulator += omega30;
      omega31 = +0.412214559083486 / (1.0e-6 + sigma3) / (1.0e-6 + sigma3);
      accumulator += omega31;
      omega32 = +0.197305957193209 / (1.0e-6 + sigma4) / (1.0e-6 + sigma4);
      accumulator += omega32;
      omega33 = +0.028437588461703 / (1.0e-6 + sigma5) / (1.0e-6 + sigma5);
      accumulator += omega33;
      omega34 = +0.000774457821797884 / (1.0e-6 + sigma6) / (1.0e-6 + sigma6);
      accumulator += omega34;
      omega28 /= accumulator;
      omega29 /= accumulator;
      omega30 /= accumulator;
      omega31 /= accumulator;
      omega32 /= accumulator;
      omega33 /= accumulator;
      omega34 /= accumulator;
      f0 =
	+2.59285714285714 * f[(i + 0) * fsi] - 4.40714285714286 * f[(i + 1) * fsi] +
	6.09285714285714 * f[(i + 2) * fsi] - 5.57380952380952 * f[(i + 3) * fsi] +
	3.17619047619048 * f[(i + 4) * fsi] - 1.02380952380952 * f[(i + 5) * fsi] +
	0.142857142857143 * f[(i + 6) * fsi];
      f1 =
	+0.142857142857143 * f[(i - 1) * fsi] + 1.59285714285714 * f[(i + 0) * fsi] -
	1.40714285714286 * f[(i + 1) * fsi] + 1.09285714285714 * f[(i + 2) * fsi] -
	0.573809523809524 * f[(i + 3) * fsi] + 0.176190476190476 * f[(i + 4) * fsi] -
	0.0238095238095238 * f[(i + 5) * fsi];
      f2 =
	-0.0238095238095238 * f[(i - 2) * fsi] + 0.30952380952381 * f[(i - 1) * fsi] +
	1.09285714285714 * f[(i + 0) * fsi] - 0.573809523809524 * f[(i + 1) * fsi] +
	0.25952380952381 * f[(i + 2) * fsi] - 0.0738095238095238 * f[(i + 3) * fsi] +
	0.00952380952380952 * f[(i + 4) * fsi];
      f3 =
	+0.00952380952380952 * f[(i - 3) * fsi] - 0.0904761904761905 * f[(i - 2) * fsi] +
	0.509523809523809 * f[(i - 1) * fsi] + 0.759523809523809 * f[(i + 0) * fsi] -
	0.24047619047619 * f[(i + 1) * fsi] + 0.0595238095238095 * f[(i + 2) * fsi] -
	0.00714285714285714 * f[(i + 3) * fsi];
      f4 =
	-0.00714285714285714 * f[(i - 4) * fsi] + 0.0595238095238095 * f[(i - 3) * fsi] -
	0.24047619047619 * f[(i - 2) * fsi] + 0.759523809523809 * f[(i - 1) * fsi] +
	0.509523809523809 * f[(i + 0) * fsi] - 0.0904761904761905 * f[(i + 1) * fsi] +
	0.00952380952380952 * f[(i + 2) * fsi];
      f5 =
	+0.00952380952380952 * f[(i - 5) * fsi] - 0.0738095238095238 * f[(i - 4) * fsi] +
	0.25952380952381 * f[(i - 3) * fsi] - 0.573809523809524 * f[(i - 2) * fsi] +
	1.09285714285714 * f[(i - 1) * fsi] + 0.30952380952381 * f[(i + 0) * fsi] -
	0.0238095238095238 * f[(i + 1) * fsi];
      f6 =
	-0.0238095238095238 * f[(i - 6) * fsi] + 0.176190476190476 * f[(i - 5) * fsi] -
	0.573809523809524 * f[(i - 4) * fsi] + 1.09285714285714 * f[(i - 3) * fsi] -
	1.40714285714286 * f[(i - 2) * fsi] + 1.59285714285714 * f[(i - 1) * fsi] +
	0.142857142857143 * f[(i + 0) * fsi];
      f7 =
	+1.93912754006363 * f[(i + 0) * fsi] - 2.3351435197543 * f[(i + 1) * fsi] +
	2.91921998523596 * f[(i + 2) * fsi] - 2.55615325104918 * f[(i + 3) * fsi] +
	1.42220249543165 * f[(i + 4) * fsi] - 0.451632684613676 * f[(i + 5) * fsi] +
	0.0623794346859126 * f[(i + 6) * fsi];
      f8 =
	+0.0623794346859126 * f[(i - 1) * fsi] + 1.50247149726224 * f[(i + 0) * fsi] -
	1.02517539135013 * f[(i + 1) * fsi] + 0.735939771229016 * f[(i + 2) * fsi] -
	0.372873037042236 * f[(i + 3) * fsi] + 0.112234367027485 * f[(i + 4) * fsi] -
	0.0149766418122884 * f[(i + 5) * fsi];
      f9 =
	-0.0149766418122884 * f[(i - 2) * fsi] + 0.167215927371931 * f[(i - 1) * fsi] +
	1.18796201920419 * f[(i + 0) * fsi] - 0.500992927920038 * f[(i + 1) * fsi] +
	0.211757307798924 * f[(i + 2) * fsi] - 0.0583635589841802 * f[(i + 3) * fsi] +
	0.00739787434146665 * f[(i + 4) * fsi];
      f10 =
	+0.00739787434146665 * f[(i - 3) * fsi] - 0.0667617622025549 * f[(i - 2) * fsi] +
	0.322571288542731 * f[(i - 1) * fsi] + 0.929036417252853 * f[(i + 0) * fsi] -
	0.242067325968705 * f[(i + 1) * fsi] + 0.056401946628124 * f[(i + 2) * fsi] -
	0.00657843859391371 * f[(i + 3) * fsi];
      f11 =
	-0.00657843859391371 * f[(i - 4) * fsi] + 0.0534469444988626 * f[(i - 3) * fsi] -
	0.204908972674743 * f[(i - 2) * fsi] + 0.55281663932971 * f[(i - 1) * fsi] +
	0.698791066465873 * f[(i + 0) * fsi] - 0.103920115496518 * f[(i + 1) * fsi] +
	0.010352876470728 * f[(i + 2) * fsi];
      f12 =
	+0.010352876470728 * f[(i - 5) * fsi] - 0.0790485738890098 * f[(i - 4) * fsi] +
	0.270857350384151 * f[(i - 3) * fsi] - 0.567259649150223 * f[(i - 2) * fsi] +
	0.915167315805191 * f[(i - 1) * fsi] + 0.481380660580585 * f[(i + 0) * fsi] -
	0.0314499802014214 * f[(i + 1) * fsi];
      f13 =
	-0.0314499802014214 * f[(i - 6) * fsi] + 0.230502737880678 * f[(i - 5) * fsi] -
	0.73949815811886 * f[(i - 4) * fsi] + 1.3716066574339 * f[(i - 3) * fsi] -
	1.66800895619997 * f[(i - 2) * fsi] + 1.57561690003504 * f[(i - 1) * fsi] +
	0.261230799170635 * f[(i + 0) * fsi];
      f14 =
	+1.01842267285463 * f[(i + 0) * fsi] + 0.225841408684541 * f[(i + 1) * fsi] -
	0.607095664169932 * f[(i + 2) * fsi] + 0.638213257647912 * f[(i + 3) * fsi] -
	0.385245576034871 * f[(i + 4) * fsi] + 0.12808138762414 * f[(i + 5) * fsi] -
	0.0182174866064252 * f[(i + 6) * fsi];
      f15 =
	-0.0182174866064251 * f[(i - 1) * fsi] + 1.14594507909961 * f[(i + 0) * fsi] -
	0.156725810050387 * f[(i + 1) * fsi] + 0.0305163670549508 * f[(i + 2) * fsi] +
	0.000601226423030093 * f[(i + 3) * fsi] - 0.00267835729994073 * f[(i + 4) * fsi] +
	0.00055898137916318 * f[(i + 5) * fsi];
      f16 =
	+0.000558981379163183 * f[(i - 2) * fsi] - 0.0221303562605674 * f[(i - 1) * fsi] +
	1.15768368806204 * f[(i + 0) * fsi] - 0.176290158321098 * f[(i + 1) * fsi] +
	0.0500807153256624 * f[(i + 2) * fsi] - 0.0111373825393969 * f[(i + 3) * fsi] +
	0.00123451235420152 * f[(i + 4) * fsi];
      f17 =
	+0.00123451235420152 * f[(i - 3) * fsi] - 0.00808260510024744 * f[(i - 2) * fsi] +
	0.00379440317766444 * f[(i - 1) * fsi] + 1.11447575566498 * f[(i + 0) * fsi] -
	0.133082225924045 * f[(i + 1) * fsi] + 0.0241559558874305 * f[(i + 2) * fsi] -
	0.00249579605998624 * f[(i + 3) * fsi];
      f18 =
	-0.00249579605998624 * f[(i - 4) * fsi] + 0.0187050847741052 * f[(i - 3) * fsi] -
	0.0604943223599585 * f[(i - 2) * fsi] + 0.0911472652771826 * f[(i - 1) * fsi] +
	1.02712289356546 * f[(i + 0) * fsi] - 0.080670508664334 * f[(i + 1) * fsi] +
	0.00668538346752684 * f[(i + 2) * fsi];
      f19 =
	+0.00668538346752684 * f[(i - 5) * fsi] - 0.0492934803326741 * f[(i - 4) * fsi] +
	0.159098137592169 * f[(i - 3) * fsi] - 0.294482743723398 * f[(i - 2) * fsi] +
	0.325135686640622 * f[(i - 1) * fsi] + 0.8867298407474 * f[(i + 0) * fsi] -
	0.0338728243916461 * f[(i + 1) * fsi];
      f20 =
	-0.0338728243916461 * f[(i - 6) * fsi] + 0.24379515420905 * f[(i - 5) * fsi] -
	0.760622792557244 * f[(i - 4) * fsi] + 1.34464699129978 * f[(i - 3) * fsi] -
	1.48003159743101 * f[(i - 2) * fsi] + 1.03646499886519 * f[(i - 1) * fsi] +
	0.649620070005877 * f[(i + 0) * fsi];
      f21 =
	+0.42417270367265 * f[(i + 0) * fsi] + 1.4100482743803 * f[(i + 1) * fsi] -
	1.72530487343966 * f[(i + 2) * fsi] + 1.48862348657392 * f[(i + 3) * fsi] -
	0.821245089352505 * f[(i + 4) * fsi] + 0.259404632442596 * f[(i + 5) * fsi] -
	0.0356991342773058 * f[(i + 6) * fsi];
      f22 =
	-0.0356991342773058 * f[(i - 1) * fsi] + 0.674066643613789 * f[(i + 0) * fsi] +
	0.660366454556883 * f[(i + 1) * fsi] - 0.47583517373396 * f[(i + 2) * fsi] +
	0.239153786868222 * f[(i + 3) * fsi] - 0.0715632695290839 * f[(i + 4) * fsi] +
	0.00951069250145579 * f[(i + 5) * fsi];
      f23 =
	+0.00951069250145579 * f[(i - 2) * fsi] - 0.102273981787496 * f[(i - 1) * fsi] +
	0.873791186144361 * f[(i + 0) * fsi] + 0.327492217005931 * f[(i + 1) * fsi] -
	0.142960936183008 * f[(i + 2) * fsi] + 0.0394292443376501 * f[(i + 3) * fsi] -
	0.00498842201889353 * f[(i + 4) * fsi];
      f24 =
	-0.00498842201889353 * f[(i - 3) * fsi] + 0.0444296466337105 * f[(i - 2) * fsi] -
	0.20703084418426 * f[(i - 1) * fsi] + 1.04838595680563 * f[(i + 0) * fsi] +
	0.152897446344657 * f[(i + 1) * fsi] - 0.0382040737862436 * f[(i + 2) * fsi] +
	0.00451029020539537 * f[(i + 3) * fsi];
      f25 =
	+0.00451029020539537 * f[(i - 4) * fsi] - 0.0365604534566611 * f[(i - 3) * fsi] +
	0.139145740947013 * f[(i - 2) * fsi] - 0.364891001373098 * f[(i - 1) * fsi] +
	1.20624611399447 * f[(i + 0) * fsi] + 0.0581813520313546 * f[(i + 1) * fsi] -
	0.006632042348476 * f[(i + 2) * fsi];
      f26 =
	-0.00663204234847601 * f[(i - 5) * fsi] + 0.0509345866447274 * f[(i - 4) * fsi] -
	0.175833342774657 * f[(i - 3) * fsi] + 0.371267223143673 * f[(i - 2) * fsi] -
	0.597012483569758 * f[(i - 1) * fsi] + 1.34551900331247 * f[(i + 0) * fsi] +
	0.0117570555920226 * f[(i + 1) * fsi];
      f27 =
	+0.0117570555920226 * f[(i - 6) * fsi] - 0.0889314314926342 * f[(i - 5) * fsi] +
	0.297832754077202 * f[(i - 4) * fsi] - 0.587330288495448 * f[(i - 3) * fsi] +
	0.782764168864464 * f[(i - 2) * fsi] - 0.843910651002233 * f[(i - 1) * fsi] +
	1.42781839245663 * f[(i + 0) * fsi];
      f28 =
	+0.186092757115321 * f[(i + 0) * fsi] + 1.60121589781739 * f[(i + 1) * fsi] -
	1.53270308764287 * f[(i + 2) * fsi] + 1.2204495440343 * f[(i + 3) * fsi] -
	0.648195682636461 * f[(i + 4) * fsi] + 0.200323248077176 * f[(i + 5) * fsi] -
	0.0271826767648506 * f[(i + 6) * fsi];
      f29 =
	-0.0271826767648506 * f[(i - 1) * fsi] + 0.376371494469275 * f[(i + 0) * fsi] +
	1.03037968575552 * f[(i + 1) * fsi] - 0.581309400873102 * f[(i + 2) * fsi] +
	0.26905585726453 * f[(i + 3) * fsi] - 0.0773594705745946 * f[(i + 4) * fsi] +
	0.0100445107232207 * f[(i + 5) * fsi];
      f30 =
	+0.0100445107232207 * f[(i - 2) * fsi] - 0.0974942518273955 * f[(i - 1) * fsi] +
	0.58730621965691 * f[(i + 0) * fsi] + 0.678821810442797 * f[(i + 1) * fsi] -
	0.229751525560378 * f[(i + 2) * fsi] + 0.0581211320768955 * f[(i + 3) * fsi] -
	0.00704789551204982 * f[(i + 4) * fsi];
      f31 =
	-0.00704789551204982 * f[(i - 3) * fsi] + 0.0593797793075694 * f[(i - 2) * fsi] -
	0.245500057580442 * f[(i - 1) * fsi] + 0.833982562578653 * f[(i + 0) * fsi] +
	0.432145467521054 * f[(i + 1) * fsi] - 0.0817457198073319 * f[(i + 2) * fsi] +
	0.00878586349254674 * f[(i + 3) * fsi];
      f32 =
	+0.00878586349254674 * f[(i - 4) * fsi] - 0.068548939959877 * f[(i - 3) * fsi] +
	0.243882912651051 * f[(i - 2) * fsi] - 0.553005279819578 * f[(i - 1) * fsi] +
	1.14148778481779 * f[(i + 0) * fsi] + 0.247642334177572 * f[(i + 1) * fsi] -
	0.0202446753595048 * f[(i + 2) * fsi];
      f33 =
	-0.0202446753595048 * f[(i - 5) * fsi] + 0.15049859100908 * f[(i - 4) * fsi] -
	0.493687122509477 * f[(i - 3) * fsi] + 0.952446550233718 * f[(i - 2) * fsi] -
	1.26156891740224 * f[(i - 1) * fsi] + 1.56662596736739 * f[(i + 0) * fsi] +
	0.105929606661039 * f[(i + 1) * fsi];
      f34 =
	+0.105929606661039 * f[(i - 6) * fsi] - 0.761751921986777 * f[(i - 5) * fsi] +
	2.3750203308909 * f[(i - 4) * fsi] - 4.20122335564584 * f[(i - 3) * fsi] +
	4.65998278337008 * f[(i - 2) * fsi] - 3.48609065728406 * f[(i - 1) * fsi] +
	2.30813321399466 * f[(i + 0) * fsi];
      fr0 =
	f0 * omega0 + f1 * omega1 + f2 * omega2 + f3 * omega3 + f4 * omega4 + f5 * omega5 +
	f6 * omega6;
      fr1 =
	f7 * omega7 + f8 * omega8 + f9 * omega9 + f10 * omega10 + f11 * omega11 + f12 * omega12 +
	f13 * omega13;
      fr2 =
	+3.0641123835583 * (f14 * omega14p + f15 * omega15p + f16 * omega16p + f17 * omega17p +
			    f18 * omega18p + f19 * omega19p + f20 * omega20p) -
	+2.0641123835583 * (f14 * omega14m + f15 * omega15m + f16 * omega16m + f17 * omega17m +
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
py_gauss_radau007005 (PyObject * self, PyObject * args)
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

  gauss_radau007005 (f, n, fsi, sigma, ssi, ssr, fr, frsi, frsl);

  Py_INCREF (Py_None);
  return Py_None;
}
