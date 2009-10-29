void
reconstruction_coeffs_k5_d1(double xi, long int i, int r, double *x, double *c)
{
  double sum_l, sum_m, sum_n, prod_p, prod_m;
  /* j = 0 */
  sum_l = 0.0;

  /* l = 1 */
  sum_m = 0.0;

  /* m = 0 */
  sum_n = 0.0;

  /* n = 2 */
  prod_p = 1.0;
  prod_p *= xi - x[i-r+3];  /* p = 3 */
  prod_p *= xi - x[i-r+4];  /* p = 4 */
  prod_p *= xi - x[i-r+5];  /* p = 5 */
  sum_n += prod_p;

  /* n = 3 */
  prod_p = 1.0;
  prod_p *= xi - x[i-r+2];  /* p = 2 */
  prod_p *= xi - x[i-r+4];  /* p = 4 */
  prod_p *= xi - x[i-r+5];  /* p = 5 */
  sum_n += prod_p;

  /* n = 4 */
  prod_p = 1.0;
  prod_p *= xi - x[i-r+2];  /* p = 2 */
  prod_p *= xi - x[i-r+3];  /* p = 3 */
  prod_p *= xi - x[i-r+5];  /* p = 5 */
  sum_n += prod_p;

  /* n = 5 */
  prod_p = 1.0;
  prod_p *= xi - x[i-r+2];  /* p = 2 */
  prod_p *= xi - x[i-r+3];  /* p = 3 */
  prod_p *= xi - x[i-r+4];  /* p = 4 */
  sum_n += prod_p;
  sum_m += sum_n;

  /* m = 2 */
  sum_n = 0.0;

  /* n = 0 */
  prod_p = 1.0;
  prod_p *= xi - x[i-r+3];  /* p = 3 */
  prod_p *= xi - x[i-r+4];  /* p = 4 */
  prod_p *= xi - x[i-r+5];  /* p = 5 */
  sum_n += prod_p;

  /* n = 3 */
  prod_p = 1.0;
  prod_p *= xi - x[i-r+0];  /* p = 0 */
  prod_p *= xi - x[i-r+4];  /* p = 4 */
  prod_p *= xi - x[i-r+5];  /* p = 5 */
  sum_n += prod_p;

  /* n = 4 */
  prod_p = 1.0;
  prod_p *= xi - x[i-r+0];  /* p = 0 */
  prod_p *= xi - x[i-r+3];  /* p = 3 */
  prod_p *= xi - x[i-r+5];  /* p = 5 */
  sum_n += prod_p;

  /* n = 5 */
  prod_p = 1.0;
  prod_p *= xi - x[i-r+0];  /* p = 0 */
  prod_p *= xi - x[i-r+3];  /* p = 3 */
  prod_p *= xi - x[i-r+4];  /* p = 4 */
  sum_n += prod_p;
  sum_m += sum_n;

  /* m = 3 */
  sum_n = 0.0;

  /* n = 0 */
  prod_p = 1.0;
  prod_p *= xi - x[i-r+2];  /* p = 2 */
  prod_p *= xi - x[i-r+4];  /* p = 4 */
  prod_p *= xi - x[i-r+5];  /* p = 5 */
  sum_n += prod_p;

  /* n = 2 */
  prod_p = 1.0;
  prod_p *= xi - x[i-r+0];  /* p = 0 */
  prod_p *= xi - x[i-r+4];  /* p = 4 */
  prod_p *= xi - x[i-r+5];  /* p = 5 */
  sum_n += prod_p;

  /* n = 4 */
  prod_p = 1.0;
  prod_p *= xi - x[i-r+0];  /* p = 0 */
  prod_p *= xi - x[i-r+2];  /* p = 2 */
  prod_p *= xi - x[i-r+5];  /* p = 5 */
  sum_n += prod_p;

  /* n = 5 */
  prod_p = 1.0;
  prod_p *= xi - x[i-r+0];  /* p = 0 */
  prod_p *= xi - x[i-r+2];  /* p = 2 */
  prod_p *= xi - x[i-r+4];  /* p = 4 */
  sum_n += prod_p;
  sum_m += sum_n;

  /* m = 4 */
  sum_n = 0.0;

  /* n = 0 */
  prod_p = 1.0;
  prod_p *= xi - x[i-r+2];  /* p = 2 */
  prod_p *= xi - x[i-r+3];  /* p = 3 */
  prod_p *= xi - x[i-r+5];  /* p = 5 */
  sum_n += prod_p;

  /* n = 2 */
  prod_p = 1.0;
  prod_p *= xi - x[i-r+0];  /* p = 0 */
  prod_p *= xi - x[i-r+3];  /* p = 3 */
  prod_p *= xi - x[i-r+5];  /* p = 5 */
  sum_n += prod_p;

  /* n = 3 */
  prod_p = 1.0;
  prod_p *= xi - x[i-r+0];  /* p = 0 */
  prod_p *= xi - x[i-r+2];  /* p = 2 */
  prod_p *= xi - x[i-r+5];  /* p = 5 */
  sum_n += prod_p;

  /* n = 5 */
  prod_p = 1.0;
  prod_p *= xi - x[i-r+0];  /* p = 0 */
  prod_p *= xi - x[i-r+2];  /* p = 2 */
  prod_p *= xi - x[i-r+3];  /* p = 3 */
  sum_n += prod_p;
  sum_m += sum_n;

  /* m = 5 */
  sum_n = 0.0;

  /* n = 0 */
  prod_p = 1.0;
  prod_p *= xi - x[i-r+2];  /* p = 2 */
  prod_p *= xi - x[i-r+3];  /* p = 3 */
  prod_p *= xi - x[i-r+4];  /* p = 4 */
  sum_n += prod_p;

  /* n = 2 */
  prod_p = 1.0;
  prod_p *= xi - x[i-r+0];  /* p = 0 */
  prod_p *= xi - x[i-r+3];  /* p = 3 */
  prod_p *= xi - x[i-r+4];  /* p = 4 */
  sum_n += prod_p;

  /* n = 3 */
  prod_p = 1.0;
  prod_p *= xi - x[i-r+0];  /* p = 0 */
  prod_p *= xi - x[i-r+2];  /* p = 2 */
  prod_p *= xi - x[i-r+4];  /* p = 4 */
  sum_n += prod_p;

  /* n = 4 */
  prod_p = 1.0;
  prod_p *= xi - x[i-r+0];  /* p = 0 */
  prod_p *= xi - x[i-r+2];  /* p = 2 */
  prod_p *= xi - x[i-r+3];  /* p = 3 */
  sum_n += prod_p;
  sum_m += sum_n;

  prod_m = 1.0;
  prod_m *= x[i-r+1] - x[i-r+0];
  prod_m *= x[i-r+1] - x[i-r+2];
  prod_m *= x[i-r+1] - x[i-r+3];
  prod_m *= x[i-r+1] - x[i-r+4];
  prod_m *= x[i-r+1] - x[i-r+5];

  sum_l += sum_m / prod_m * (x[i-r+0+1] - x[i-r+0]);

  /* l = 2 */
  sum_m = 0.0;

  /* m = 0 */
  sum_n = 0.0;

  /* n = 1 */
  prod_p = 1.0;
  prod_p *= xi - x[i-r+3];  /* p = 3 */
  prod_p *= xi - x[i-r+4];  /* p = 4 */
  prod_p *= xi - x[i-r+5];  /* p = 5 */
  sum_n += prod_p;

  /* n = 3 */
  prod_p = 1.0;
  prod_p *= xi - x[i-r+1];  /* p = 1 */
  prod_p *= xi - x[i-r+4];  /* p = 4 */
  prod_p *= xi - x[i-r+5];  /* p = 5 */
  sum_n += prod_p;

  /* n = 4 */
  prod_p = 1.0;
  prod_p *= xi - x[i-r+1];  /* p = 1 */
  prod_p *= xi - x[i-r+3];  /* p = 3 */
  prod_p *= xi - x[i-r+5];  /* p = 5 */
  sum_n += prod_p;

  /* n = 5 */
  prod_p = 1.0;
  prod_p *= xi - x[i-r+1];  /* p = 1 */
  prod_p *= xi - x[i-r+3];  /* p = 3 */
  prod_p *= xi - x[i-r+4];  /* p = 4 */
  sum_n += prod_p;
  sum_m += sum_n;

  /* m = 1 */
  sum_n = 0.0;

  /* n = 0 */
  prod_p = 1.0;
  prod_p *= xi - x[i-r+3];  /* p = 3 */
  prod_p *= xi - x[i-r+4];  /* p = 4 */
  prod_p *= xi - x[i-r+5];  /* p = 5 */
  sum_n += prod_p;

  /* n = 3 */
  prod_p = 1.0;
  prod_p *= xi - x[i-r+0];  /* p = 0 */
  prod_p *= xi - x[i-r+4];  /* p = 4 */
  prod_p *= xi - x[i-r+5];  /* p = 5 */
  sum_n += prod_p;

  /* n = 4 */
  prod_p = 1.0;
  prod_p *= xi - x[i-r+0];  /* p = 0 */
  prod_p *= xi - x[i-r+3];  /* p = 3 */
  prod_p *= xi - x[i-r+5];  /* p = 5 */
  sum_n += prod_p;

  /* n = 5 */
  prod_p = 1.0;
  prod_p *= xi - x[i-r+0];  /* p = 0 */
  prod_p *= xi - x[i-r+3];  /* p = 3 */
  prod_p *= xi - x[i-r+4];  /* p = 4 */
  sum_n += prod_p;
  sum_m += sum_n;

  /* m = 3 */
  sum_n = 0.0;

  /* n = 0 */
  prod_p = 1.0;
  prod_p *= xi - x[i-r+1];  /* p = 1 */
  prod_p *= xi - x[i-r+4];  /* p = 4 */
  prod_p *= xi - x[i-r+5];  /* p = 5 */
  sum_n += prod_p;

  /* n = 1 */
  prod_p = 1.0;
  prod_p *= xi - x[i-r+0];  /* p = 0 */
  prod_p *= xi - x[i-r+4];  /* p = 4 */
  prod_p *= xi - x[i-r+5];  /* p = 5 */
  sum_n += prod_p;

  /* n = 4 */
  prod_p = 1.0;
  prod_p *= xi - x[i-r+0];  /* p = 0 */
  prod_p *= xi - x[i-r+1];  /* p = 1 */
  prod_p *= xi - x[i-r+5];  /* p = 5 */
  sum_n += prod_p;

  /* n = 5 */
  prod_p = 1.0;
  prod_p *= xi - x[i-r+0];  /* p = 0 */
  prod_p *= xi - x[i-r+1];  /* p = 1 */
  prod_p *= xi - x[i-r+4];  /* p = 4 */
  sum_n += prod_p;
  sum_m += sum_n;

  /* m = 4 */
  sum_n = 0.0;

  /* n = 0 */
  prod_p = 1.0;
  prod_p *= xi - x[i-r+1];  /* p = 1 */
  prod_p *= xi - x[i-r+3];  /* p = 3 */
  prod_p *= xi - x[i-r+5];  /* p = 5 */
  sum_n += prod_p;

  /* n = 1 */
  prod_p = 1.0;
  prod_p *= xi - x[i-r+0];  /* p = 0 */
  prod_p *= xi - x[i-r+3];  /* p = 3 */
  prod_p *= xi - x[i-r+5];  /* p = 5 */
  sum_n += prod_p;

  /* n = 3 */
  prod_p = 1.0;
  prod_p *= xi - x[i-r+0];  /* p = 0 */
  prod_p *= xi - x[i-r+1];  /* p = 1 */
  prod_p *= xi - x[i-r+5];  /* p = 5 */
  sum_n += prod_p;

  /* n = 5 */
  prod_p = 1.0;
  prod_p *= xi - x[i-r+0];  /* p = 0 */
  prod_p *= xi - x[i-r+1];  /* p = 1 */
  prod_p *= xi - x[i-r+3];  /* p = 3 */
  sum_n += prod_p;
  sum_m += sum_n;

  /* m = 5 */
  sum_n = 0.0;

  /* n = 0 */
  prod_p = 1.0;
  prod_p *= xi - x[i-r+1];  /* p = 1 */
  prod_p *= xi - x[i-r+3];  /* p = 3 */
  prod_p *= xi - x[i-r+4];  /* p = 4 */
  sum_n += prod_p;

  /* n = 1 */
  prod_p = 1.0;
  prod_p *= xi - x[i-r+0];  /* p = 0 */
  prod_p *= xi - x[i-r+3];  /* p = 3 */
  prod_p *= xi - x[i-r+4];  /* p = 4 */
  sum_n += prod_p;

  /* n = 3 */
  prod_p = 1.0;
  prod_p *= xi - x[i-r+0];  /* p = 0 */
  prod_p *= xi - x[i-r+1];  /* p = 1 */
  prod_p *= xi - x[i-r+4];  /* p = 4 */
  sum_n += prod_p;

  /* n = 4 */
  prod_p = 1.0;
  prod_p *= xi - x[i-r+0];  /* p = 0 */
  prod_p *= xi - x[i-r+1];  /* p = 1 */
  prod_p *= xi - x[i-r+3];  /* p = 3 */
  sum_n += prod_p;
  sum_m += sum_n;

  prod_m = 1.0;
  prod_m *= x[i-r+2] - x[i-r+0];
  prod_m *= x[i-r+2] - x[i-r+1];
  prod_m *= x[i-r+2] - x[i-r+3];
  prod_m *= x[i-r+2] - x[i-r+4];
  prod_m *= x[i-r+2] - x[i-r+5];

  sum_l += sum_m / prod_m * (x[i-r+0+1] - x[i-r+0]);

  /* l = 3 */
  sum_m = 0.0;

  /* m = 0 */
  sum_n = 0.0;

  /* n = 1 */
  prod_p = 1.0;
  prod_p *= xi - x[i-r+2];  /* p = 2 */
  prod_p *= xi - x[i-r+4];  /* p = 4 */
  prod_p *= xi - x[i-r+5];  /* p = 5 */
  sum_n += prod_p;

  /* n = 2 */
  prod_p = 1.0;
  prod_p *= xi - x[i-r+1];  /* p = 1 */
  prod_p *= xi - x[i-r+4];  /* p = 4 */
  prod_p *= xi - x[i-r+5];  /* p = 5 */
  sum_n += prod_p;

  /* n = 4 */
  prod_p = 1.0;
  prod_p *= xi - x[i-r+1];  /* p = 1 */
  prod_p *= xi - x[i-r+2];  /* p = 2 */
  prod_p *= xi - x[i-r+5];  /* p = 5 */
  sum_n += prod_p;

  /* n = 5 */
  prod_p = 1.0;
  prod_p *= xi - x[i-r+1];  /* p = 1 */
  prod_p *= xi - x[i-r+2];  /* p = 2 */
  prod_p *= xi - x[i-r+4];  /* p = 4 */
  sum_n += prod_p;
  sum_m += sum_n;

  /* m = 1 */
  sum_n = 0.0;

  /* n = 0 */
  prod_p = 1.0;
  prod_p *= xi - x[i-r+2];  /* p = 2 */
  prod_p *= xi - x[i-r+4];  /* p = 4 */
  prod_p *= xi - x[i-r+5];  /* p = 5 */
  sum_n += prod_p;

  /* n = 2 */
  prod_p = 1.0;
  prod_p *= xi - x[i-r+0];  /* p = 0 */
  prod_p *= xi - x[i-r+4];  /* p = 4 */
  prod_p *= xi - x[i-r+5];  /* p = 5 */
  sum_n += prod_p;

  /* n = 4 */
  prod_p = 1.0;
  prod_p *= xi - x[i-r+0];  /* p = 0 */
  prod_p *= xi - x[i-r+2];  /* p = 2 */
  prod_p *= xi - x[i-r+5];  /* p = 5 */
  sum_n += prod_p;

  /* n = 5 */
  prod_p = 1.0;
  prod_p *= xi - x[i-r+0];  /* p = 0 */
  prod_p *= xi - x[i-r+2];  /* p = 2 */
  prod_p *= xi - x[i-r+4];  /* p = 4 */
  sum_n += prod_p;
  sum_m += sum_n;

  /* m = 2 */
  sum_n = 0.0;

  /* n = 0 */
  prod_p = 1.0;
  prod_p *= xi - x[i-r+1];  /* p = 1 */
  prod_p *= xi - x[i-r+4];  /* p = 4 */
  prod_p *= xi - x[i-r+5];  /* p = 5 */
  sum_n += prod_p;

  /* n = 1 */
  prod_p = 1.0;
  prod_p *= xi - x[i-r+0];  /* p = 0 */
  prod_p *= xi - x[i-r+4];  /* p = 4 */
  prod_p *= xi - x[i-r+5];  /* p = 5 */
  sum_n += prod_p;

  /* n = 4 */
  prod_p = 1.0;
  prod_p *= xi - x[i-r+0];  /* p = 0 */
  prod_p *= xi - x[i-r+1];  /* p = 1 */
  prod_p *= xi - x[i-r+5];  /* p = 5 */
  sum_n += prod_p;

  /* n = 5 */
  prod_p = 1.0;
  prod_p *= xi - x[i-r+0];  /* p = 0 */
  prod_p *= xi - x[i-r+1];  /* p = 1 */
  prod_p *= xi - x[i-r+4];  /* p = 4 */
  sum_n += prod_p;
  sum_m += sum_n;

  /* m = 4 */
  sum_n = 0.0;

  /* n = 0 */
  prod_p = 1.0;
  prod_p *= xi - x[i-r+1];  /* p = 1 */
  prod_p *= xi - x[i-r+2];  /* p = 2 */
  prod_p *= xi - x[i-r+5];  /* p = 5 */
  sum_n += prod_p;

  /* n = 1 */
  prod_p = 1.0;
  prod_p *= xi - x[i-r+0];  /* p = 0 */
  prod_p *= xi - x[i-r+2];  /* p = 2 */
  prod_p *= xi - x[i-r+5];  /* p = 5 */
  sum_n += prod_p;

  /* n = 2 */
  prod_p = 1.0;
  prod_p *= xi - x[i-r+0];  /* p = 0 */
  prod_p *= xi - x[i-r+1];  /* p = 1 */
  prod_p *= xi - x[i-r+5];  /* p = 5 */
  sum_n += prod_p;

  /* n = 5 */
  prod_p = 1.0;
  prod_p *= xi - x[i-r+0];  /* p = 0 */
  prod_p *= xi - x[i-r+1];  /* p = 1 */
  prod_p *= xi - x[i-r+2];  /* p = 2 */
  sum_n += prod_p;
  sum_m += sum_n;

  /* m = 5 */
  sum_n = 0.0;

  /* n = 0 */
  prod_p = 1.0;
  prod_p *= xi - x[i-r+1];  /* p = 1 */
  prod_p *= xi - x[i-r+2];  /* p = 2 */
  prod_p *= xi - x[i-r+4];  /* p = 4 */
  sum_n += prod_p;

  /* n = 1 */
  prod_p = 1.0;
  prod_p *= xi - x[i-r+0];  /* p = 0 */
  prod_p *= xi - x[i-r+2];  /* p = 2 */
  prod_p *= xi - x[i-r+4];  /* p = 4 */
  sum_n += prod_p;

  /* n = 2 */
  prod_p = 1.0;
  prod_p *= xi - x[i-r+0];  /* p = 0 */
  prod_p *= xi - x[i-r+1];  /* p = 1 */
  prod_p *= xi - x[i-r+4];  /* p = 4 */
  sum_n += prod_p;

  /* n = 4 */
  prod_p = 1.0;
  prod_p *= xi - x[i-r+0];  /* p = 0 */
  prod_p *= xi - x[i-r+1];  /* p = 1 */
  prod_p *= xi - x[i-r+2];  /* p = 2 */
  sum_n += prod_p;
  sum_m += sum_n;

  prod_m = 1.0;
  prod_m *= x[i-r+3] - x[i-r+0];
  prod_m *= x[i-r+3] - x[i-r+1];
  prod_m *= x[i-r+3] - x[i-r+2];
  prod_m *= x[i-r+3] - x[i-r+4];
  prod_m *= x[i-r+3] - x[i-r+5];

  sum_l += sum_m / prod_m * (x[i-r+0+1] - x[i-r+0]);

  /* l = 4 */
  sum_m = 0.0;

  /* m = 0 */
  sum_n = 0.0;

  /* n = 1 */
  prod_p = 1.0;
  prod_p *= xi - x[i-r+2];  /* p = 2 */
  prod_p *= xi - x[i-r+3];  /* p = 3 */
  prod_p *= xi - x[i-r+5];  /* p = 5 */
  sum_n += prod_p;

  /* n = 2 */
  prod_p = 1.0;
  prod_p *= xi - x[i-r+1];  /* p = 1 */
  prod_p *= xi - x[i-r+3];  /* p = 3 */
  prod_p *= xi - x[i-r+5];  /* p = 5 */
  sum_n += prod_p;

  /* n = 3 */
  prod_p = 1.0;
  prod_p *= xi - x[i-r+1];  /* p = 1 */
  prod_p *= xi - x[i-r+2];  /* p = 2 */
  prod_p *= xi - x[i-r+5];  /* p = 5 */
  sum_n += prod_p;

  /* n = 5 */
  prod_p = 1.0;
  prod_p *= xi - x[i-r+1];  /* p = 1 */
  prod_p *= xi - x[i-r+2];  /* p = 2 */
  prod_p *= xi - x[i-r+3];  /* p = 3 */
  sum_n += prod_p;
  sum_m += sum_n;

  /* m = 1 */
  sum_n = 0.0;

  /* n = 0 */
  prod_p = 1.0;
  prod_p *= xi - x[i-r+2];  /* p = 2 */
  prod_p *= xi - x[i-r+3];  /* p = 3 */
  prod_p *= xi - x[i-r+5];  /* p = 5 */
  sum_n += prod_p;

  /* n = 2 */
  prod_p = 1.0;
  prod_p *= xi - x[i-r+0];  /* p = 0 */
  prod_p *= xi - x[i-r+3];  /* p = 3 */
  prod_p *= xi - x[i-r+5];  /* p = 5 */
  sum_n += prod_p;

  /* n = 3 */
  prod_p = 1.0;
  prod_p *= xi - x[i-r+0];  /* p = 0 */
  prod_p *= xi - x[i-r+2];  /* p = 2 */
  prod_p *= xi - x[i-r+5];  /* p = 5 */
  sum_n += prod_p;

  /* n = 5 */
  prod_p = 1.0;
  prod_p *= xi - x[i-r+0];  /* p = 0 */
  prod_p *= xi - x[i-r+2];  /* p = 2 */
  prod_p *= xi - x[i-r+3];  /* p = 3 */
  sum_n += prod_p;
  sum_m += sum_n;

  /* m = 2 */
  sum_n = 0.0;

  /* n = 0 */
  prod_p = 1.0;
  prod_p *= xi - x[i-r+1];  /* p = 1 */
  prod_p *= xi - x[i-r+3];  /* p = 3 */
  prod_p *= xi - x[i-r+5];  /* p = 5 */
  sum_n += prod_p;

  /* n = 1 */
  prod_p = 1.0;
  prod_p *= xi - x[i-r+0];  /* p = 0 */
  prod_p *= xi - x[i-r+3];  /* p = 3 */
  prod_p *= xi - x[i-r+5];  /* p = 5 */
  sum_n += prod_p;

  /* n = 3 */
  prod_p = 1.0;
  prod_p *= xi - x[i-r+0];  /* p = 0 */
  prod_p *= xi - x[i-r+1];  /* p = 1 */
  prod_p *= xi - x[i-r+5];  /* p = 5 */
  sum_n += prod_p;

  /* n = 5 */
  prod_p = 1.0;
  prod_p *= xi - x[i-r+0];  /* p = 0 */
  prod_p *= xi - x[i-r+1];  /* p = 1 */
  prod_p *= xi - x[i-r+3];  /* p = 3 */
  sum_n += prod_p;
  sum_m += sum_n;

  /* m = 3 */
  sum_n = 0.0;

  /* n = 0 */
  prod_p = 1.0;
  prod_p *= xi - x[i-r+1];  /* p = 1 */
  prod_p *= xi - x[i-r+2];  /* p = 2 */
  prod_p *= xi - x[i-r+5];  /* p = 5 */
  sum_n += prod_p;

  /* n = 1 */
  prod_p = 1.0;
  prod_p *= xi - x[i-r+0];  /* p = 0 */
  prod_p *= xi - x[i-r+2];  /* p = 2 */
  prod_p *= xi - x[i-r+5];  /* p = 5 */
  sum_n += prod_p;

  /* n = 2 */
  prod_p = 1.0;
  prod_p *= xi - x[i-r+0];  /* p = 0 */
  prod_p *= xi - x[i-r+1];  /* p = 1 */
  prod_p *= xi - x[i-r+5];  /* p = 5 */
  sum_n += prod_p;

  /* n = 5 */
  prod_p = 1.0;
  prod_p *= xi - x[i-r+0];  /* p = 0 */
  prod_p *= xi - x[i-r+1];  /* p = 1 */
  prod_p *= xi - x[i-r+2];  /* p = 2 */
  sum_n += prod_p;
  sum_m += sum_n;

  /* m = 5 */
  sum_n = 0.0;

  /* n = 0 */
  prod_p = 1.0;
  prod_p *= xi - x[i-r+1];  /* p = 1 */
  prod_p *= xi - x[i-r+2];  /* p = 2 */
  prod_p *= xi - x[i-r+3];  /* p = 3 */
  sum_n += prod_p;

  /* n = 1 */
  prod_p = 1.0;
  prod_p *= xi - x[i-r+0];  /* p = 0 */
  prod_p *= xi - x[i-r+2];  /* p = 2 */
  prod_p *= xi - x[i-r+3];  /* p = 3 */
  sum_n += prod_p;

  /* n = 2 */
  prod_p = 1.0;
  prod_p *= xi - x[i-r+0];  /* p = 0 */
  prod_p *= xi - x[i-r+1];  /* p = 1 */
  prod_p *= xi - x[i-r+3];  /* p = 3 */
  sum_n += prod_p;

  /* n = 3 */
  prod_p = 1.0;
  prod_p *= xi - x[i-r+0];  /* p = 0 */
  prod_p *= xi - x[i-r+1];  /* p = 1 */
  prod_p *= xi - x[i-r+2];  /* p = 2 */
  sum_n += prod_p;
  sum_m += sum_n;

  prod_m = 1.0;
  prod_m *= x[i-r+4] - x[i-r+0];
  prod_m *= x[i-r+4] - x[i-r+1];
  prod_m *= x[i-r+4] - x[i-r+2];
  prod_m *= x[i-r+4] - x[i-r+3];
  prod_m *= x[i-r+4] - x[i-r+5];

  sum_l += sum_m / prod_m * (x[i-r+0+1] - x[i-r+0]);

  /* l = 5 */
  sum_m = 0.0;

  /* m = 0 */
  sum_n = 0.0;

  /* n = 1 */
  prod_p = 1.0;
  prod_p *= xi - x[i-r+2];  /* p = 2 */
  prod_p *= xi - x[i-r+3];  /* p = 3 */
  prod_p *= xi - x[i-r+4];  /* p = 4 */
  sum_n += prod_p;

  /* n = 2 */
  prod_p = 1.0;
  prod_p *= xi - x[i-r+1];  /* p = 1 */
  prod_p *= xi - x[i-r+3];  /* p = 3 */
  prod_p *= xi - x[i-r+4];  /* p = 4 */
  sum_n += prod_p;

  /* n = 3 */
  prod_p = 1.0;
  prod_p *= xi - x[i-r+1];  /* p = 1 */
  prod_p *= xi - x[i-r+2];  /* p = 2 */
  prod_p *= xi - x[i-r+4];  /* p = 4 */
  sum_n += prod_p;

  /* n = 4 */
  prod_p = 1.0;
  prod_p *= xi - x[i-r+1];  /* p = 1 */
  prod_p *= xi - x[i-r+2];  /* p = 2 */
  prod_p *= xi - x[i-r+3];  /* p = 3 */
  sum_n += prod_p;
  sum_m += sum_n;

  /* m = 1 */
  sum_n = 0.0;

  /* n = 0 */
  prod_p = 1.0;
  prod_p *= xi - x[i-r+2];  /* p = 2 */
  prod_p *= xi - x[i-r+3];  /* p = 3 */
  prod_p *= xi - x[i-r+4];  /* p = 4 */
  sum_n += prod_p;

  /* n = 2 */
  prod_p = 1.0;
  prod_p *= xi - x[i-r+0];  /* p = 0 */
  prod_p *= xi - x[i-r+3];  /* p = 3 */
  prod_p *= xi - x[i-r+4];  /* p = 4 */
  sum_n += prod_p;

  /* n = 3 */
  prod_p = 1.0;
  prod_p *= xi - x[i-r+0];  /* p = 0 */
  prod_p *= xi - x[i-r+2];  /* p = 2 */
  prod_p *= xi - x[i-r+4];  /* p = 4 */
  sum_n += prod_p;

  /* n = 4 */
  prod_p = 1.0;
  prod_p *= xi - x[i-r+0];  /* p = 0 */
  prod_p *= xi - x[i-r+2];  /* p = 2 */
  prod_p *= xi - x[i-r+3];  /* p = 3 */
  sum_n += prod_p;
  sum_m += sum_n;

  /* m = 2 */
  sum_n = 0.0;

  /* n = 0 */
  prod_p = 1.0;
  prod_p *= xi - x[i-r+1];  /* p = 1 */
  prod_p *= xi - x[i-r+3];  /* p = 3 */
  prod_p *= xi - x[i-r+4];  /* p = 4 */
  sum_n += prod_p;

  /* n = 1 */
  prod_p = 1.0;
  prod_p *= xi - x[i-r+0];  /* p = 0 */
  prod_p *= xi - x[i-r+3];  /* p = 3 */
  prod_p *= xi - x[i-r+4];  /* p = 4 */
  sum_n += prod_p;

  /* n = 3 */
  prod_p = 1.0;
  prod_p *= xi - x[i-r+0];  /* p = 0 */
  prod_p *= xi - x[i-r+1];  /* p = 1 */
  prod_p *= xi - x[i-r+4];  /* p = 4 */
  sum_n += prod_p;

  /* n = 4 */
  prod_p = 1.0;
  prod_p *= xi - x[i-r+0];  /* p = 0 */
  prod_p *= xi - x[i-r+1];  /* p = 1 */
  prod_p *= xi - x[i-r+3];  /* p = 3 */
  sum_n += prod_p;
  sum_m += sum_n;

  /* m = 3 */
  sum_n = 0.0;

  /* n = 0 */
  prod_p = 1.0;
  prod_p *= xi - x[i-r+1];  /* p = 1 */
  prod_p *= xi - x[i-r+2];  /* p = 2 */
  prod_p *= xi - x[i-r+4];  /* p = 4 */
  sum_n += prod_p;

  /* n = 1 */
  prod_p = 1.0;
  prod_p *= xi - x[i-r+0];  /* p = 0 */
  prod_p *= xi - x[i-r+2];  /* p = 2 */
  prod_p *= xi - x[i-r+4];  /* p = 4 */
  sum_n += prod_p;

  /* n = 2 */
  prod_p = 1.0;
  prod_p *= xi - x[i-r+0];  /* p = 0 */
  prod_p *= xi - x[i-r+1];  /* p = 1 */
  prod_p *= xi - x[i-r+4];  /* p = 4 */
  sum_n += prod_p;

  /* n = 4 */
  prod_p = 1.0;
  prod_p *= xi - x[i-r+0];  /* p = 0 */
  prod_p *= xi - x[i-r+1];  /* p = 1 */
  prod_p *= xi - x[i-r+2];  /* p = 2 */
  sum_n += prod_p;
  sum_m += sum_n;

  /* m = 4 */
  sum_n = 0.0;

  /* n = 0 */
  prod_p = 1.0;
  prod_p *= xi - x[i-r+1];  /* p = 1 */
  prod_p *= xi - x[i-r+2];  /* p = 2 */
  prod_p *= xi - x[i-r+3];  /* p = 3 */
  sum_n += prod_p;

  /* n = 1 */
  prod_p = 1.0;
  prod_p *= xi - x[i-r+0];  /* p = 0 */
  prod_p *= xi - x[i-r+2];  /* p = 2 */
  prod_p *= xi - x[i-r+3];  /* p = 3 */
  sum_n += prod_p;

  /* n = 2 */
  prod_p = 1.0;
  prod_p *= xi - x[i-r+0];  /* p = 0 */
  prod_p *= xi - x[i-r+1];  /* p = 1 */
  prod_p *= xi - x[i-r+3];  /* p = 3 */
  sum_n += prod_p;

  /* n = 3 */
  prod_p = 1.0;
  prod_p *= xi - x[i-r+0];  /* p = 0 */
  prod_p *= xi - x[i-r+1];  /* p = 1 */
  prod_p *= xi - x[i-r+2];  /* p = 2 */
  sum_n += prod_p;
  sum_m += sum_n;

  prod_m = 1.0;
  prod_m *= x[i-r+5] - x[i-r+0];
  prod_m *= x[i-r+5] - x[i-r+1];
  prod_m *= x[i-r+5] - x[i-r+2];
  prod_m *= x[i-r+5] - x[i-r+3];
  prod_m *= x[i-r+5] - x[i-r+4];

  sum_l += sum_m / prod_m * (x[i-r+0+1] - x[i-r+0]);

  c[0] = sum_l;
  /* j = 1 */
  sum_l = 0.0;

  /* l = 2 */
  sum_m = 0.0;

  /* m = 0 */
  sum_n = 0.0;

  /* n = 1 */
  prod_p = 1.0;
  prod_p *= xi - x[i-r+3];  /* p = 3 */
  prod_p *= xi - x[i-r+4];  /* p = 4 */
  prod_p *= xi - x[i-r+5];  /* p = 5 */
  sum_n += prod_p;

  /* n = 3 */
  prod_p = 1.0;
  prod_p *= xi - x[i-r+1];  /* p = 1 */
  prod_p *= xi - x[i-r+4];  /* p = 4 */
  prod_p *= xi - x[i-r+5];  /* p = 5 */
  sum_n += prod_p;

  /* n = 4 */
  prod_p = 1.0;
  prod_p *= xi - x[i-r+1];  /* p = 1 */
  prod_p *= xi - x[i-r+3];  /* p = 3 */
  prod_p *= xi - x[i-r+5];  /* p = 5 */
  sum_n += prod_p;

  /* n = 5 */
  prod_p = 1.0;
  prod_p *= xi - x[i-r+1];  /* p = 1 */
  prod_p *= xi - x[i-r+3];  /* p = 3 */
  prod_p *= xi - x[i-r+4];  /* p = 4 */
  sum_n += prod_p;
  sum_m += sum_n;

  /* m = 1 */
  sum_n = 0.0;

  /* n = 0 */
  prod_p = 1.0;
  prod_p *= xi - x[i-r+3];  /* p = 3 */
  prod_p *= xi - x[i-r+4];  /* p = 4 */
  prod_p *= xi - x[i-r+5];  /* p = 5 */
  sum_n += prod_p;

  /* n = 3 */
  prod_p = 1.0;
  prod_p *= xi - x[i-r+0];  /* p = 0 */
  prod_p *= xi - x[i-r+4];  /* p = 4 */
  prod_p *= xi - x[i-r+5];  /* p = 5 */
  sum_n += prod_p;

  /* n = 4 */
  prod_p = 1.0;
  prod_p *= xi - x[i-r+0];  /* p = 0 */
  prod_p *= xi - x[i-r+3];  /* p = 3 */
  prod_p *= xi - x[i-r+5];  /* p = 5 */
  sum_n += prod_p;

  /* n = 5 */
  prod_p = 1.0;
  prod_p *= xi - x[i-r+0];  /* p = 0 */
  prod_p *= xi - x[i-r+3];  /* p = 3 */
  prod_p *= xi - x[i-r+4];  /* p = 4 */
  sum_n += prod_p;
  sum_m += sum_n;

  /* m = 3 */
  sum_n = 0.0;

  /* n = 0 */
  prod_p = 1.0;
  prod_p *= xi - x[i-r+1];  /* p = 1 */
  prod_p *= xi - x[i-r+4];  /* p = 4 */
  prod_p *= xi - x[i-r+5];  /* p = 5 */
  sum_n += prod_p;

  /* n = 1 */
  prod_p = 1.0;
  prod_p *= xi - x[i-r+0];  /* p = 0 */
  prod_p *= xi - x[i-r+4];  /* p = 4 */
  prod_p *= xi - x[i-r+5];  /* p = 5 */
  sum_n += prod_p;

  /* n = 4 */
  prod_p = 1.0;
  prod_p *= xi - x[i-r+0];  /* p = 0 */
  prod_p *= xi - x[i-r+1];  /* p = 1 */
  prod_p *= xi - x[i-r+5];  /* p = 5 */
  sum_n += prod_p;

  /* n = 5 */
  prod_p = 1.0;
  prod_p *= xi - x[i-r+0];  /* p = 0 */
  prod_p *= xi - x[i-r+1];  /* p = 1 */
  prod_p *= xi - x[i-r+4];  /* p = 4 */
  sum_n += prod_p;
  sum_m += sum_n;

  /* m = 4 */
  sum_n = 0.0;

  /* n = 0 */
  prod_p = 1.0;
  prod_p *= xi - x[i-r+1];  /* p = 1 */
  prod_p *= xi - x[i-r+3];  /* p = 3 */
  prod_p *= xi - x[i-r+5];  /* p = 5 */
  sum_n += prod_p;

  /* n = 1 */
  prod_p = 1.0;
  prod_p *= xi - x[i-r+0];  /* p = 0 */
  prod_p *= xi - x[i-r+3];  /* p = 3 */
  prod_p *= xi - x[i-r+5];  /* p = 5 */
  sum_n += prod_p;

  /* n = 3 */
  prod_p = 1.0;
  prod_p *= xi - x[i-r+0];  /* p = 0 */
  prod_p *= xi - x[i-r+1];  /* p = 1 */
  prod_p *= xi - x[i-r+5];  /* p = 5 */
  sum_n += prod_p;

  /* n = 5 */
  prod_p = 1.0;
  prod_p *= xi - x[i-r+0];  /* p = 0 */
  prod_p *= xi - x[i-r+1];  /* p = 1 */
  prod_p *= xi - x[i-r+3];  /* p = 3 */
  sum_n += prod_p;
  sum_m += sum_n;

  /* m = 5 */
  sum_n = 0.0;

  /* n = 0 */
  prod_p = 1.0;
  prod_p *= xi - x[i-r+1];  /* p = 1 */
  prod_p *= xi - x[i-r+3];  /* p = 3 */
  prod_p *= xi - x[i-r+4];  /* p = 4 */
  sum_n += prod_p;

  /* n = 1 */
  prod_p = 1.0;
  prod_p *= xi - x[i-r+0];  /* p = 0 */
  prod_p *= xi - x[i-r+3];  /* p = 3 */
  prod_p *= xi - x[i-r+4];  /* p = 4 */
  sum_n += prod_p;

  /* n = 3 */
  prod_p = 1.0;
  prod_p *= xi - x[i-r+0];  /* p = 0 */
  prod_p *= xi - x[i-r+1];  /* p = 1 */
  prod_p *= xi - x[i-r+4];  /* p = 4 */
  sum_n += prod_p;

  /* n = 4 */
  prod_p = 1.0;
  prod_p *= xi - x[i-r+0];  /* p = 0 */
  prod_p *= xi - x[i-r+1];  /* p = 1 */
  prod_p *= xi - x[i-r+3];  /* p = 3 */
  sum_n += prod_p;
  sum_m += sum_n;

  prod_m = 1.0;
  prod_m *= x[i-r+2] - x[i-r+0];
  prod_m *= x[i-r+2] - x[i-r+1];
  prod_m *= x[i-r+2] - x[i-r+3];
  prod_m *= x[i-r+2] - x[i-r+4];
  prod_m *= x[i-r+2] - x[i-r+5];

  sum_l += sum_m / prod_m * (x[i-r+1+1] - x[i-r+1]);

  /* l = 3 */
  sum_m = 0.0;

  /* m = 0 */
  sum_n = 0.0;

  /* n = 1 */
  prod_p = 1.0;
  prod_p *= xi - x[i-r+2];  /* p = 2 */
  prod_p *= xi - x[i-r+4];  /* p = 4 */
  prod_p *= xi - x[i-r+5];  /* p = 5 */
  sum_n += prod_p;

  /* n = 2 */
  prod_p = 1.0;
  prod_p *= xi - x[i-r+1];  /* p = 1 */
  prod_p *= xi - x[i-r+4];  /* p = 4 */
  prod_p *= xi - x[i-r+5];  /* p = 5 */
  sum_n += prod_p;

  /* n = 4 */
  prod_p = 1.0;
  prod_p *= xi - x[i-r+1];  /* p = 1 */
  prod_p *= xi - x[i-r+2];  /* p = 2 */
  prod_p *= xi - x[i-r+5];  /* p = 5 */
  sum_n += prod_p;

  /* n = 5 */
  prod_p = 1.0;
  prod_p *= xi - x[i-r+1];  /* p = 1 */
  prod_p *= xi - x[i-r+2];  /* p = 2 */
  prod_p *= xi - x[i-r+4];  /* p = 4 */
  sum_n += prod_p;
  sum_m += sum_n;

  /* m = 1 */
  sum_n = 0.0;

  /* n = 0 */
  prod_p = 1.0;
  prod_p *= xi - x[i-r+2];  /* p = 2 */
  prod_p *= xi - x[i-r+4];  /* p = 4 */
  prod_p *= xi - x[i-r+5];  /* p = 5 */
  sum_n += prod_p;

  /* n = 2 */
  prod_p = 1.0;
  prod_p *= xi - x[i-r+0];  /* p = 0 */
  prod_p *= xi - x[i-r+4];  /* p = 4 */
  prod_p *= xi - x[i-r+5];  /* p = 5 */
  sum_n += prod_p;

  /* n = 4 */
  prod_p = 1.0;
  prod_p *= xi - x[i-r+0];  /* p = 0 */
  prod_p *= xi - x[i-r+2];  /* p = 2 */
  prod_p *= xi - x[i-r+5];  /* p = 5 */
  sum_n += prod_p;

  /* n = 5 */
  prod_p = 1.0;
  prod_p *= xi - x[i-r+0];  /* p = 0 */
  prod_p *= xi - x[i-r+2];  /* p = 2 */
  prod_p *= xi - x[i-r+4];  /* p = 4 */
  sum_n += prod_p;
  sum_m += sum_n;

  /* m = 2 */
  sum_n = 0.0;

  /* n = 0 */
  prod_p = 1.0;
  prod_p *= xi - x[i-r+1];  /* p = 1 */
  prod_p *= xi - x[i-r+4];  /* p = 4 */
  prod_p *= xi - x[i-r+5];  /* p = 5 */
  sum_n += prod_p;

  /* n = 1 */
  prod_p = 1.0;
  prod_p *= xi - x[i-r+0];  /* p = 0 */
  prod_p *= xi - x[i-r+4];  /* p = 4 */
  prod_p *= xi - x[i-r+5];  /* p = 5 */
  sum_n += prod_p;

  /* n = 4 */
  prod_p = 1.0;
  prod_p *= xi - x[i-r+0];  /* p = 0 */
  prod_p *= xi - x[i-r+1];  /* p = 1 */
  prod_p *= xi - x[i-r+5];  /* p = 5 */
  sum_n += prod_p;

  /* n = 5 */
  prod_p = 1.0;
  prod_p *= xi - x[i-r+0];  /* p = 0 */
  prod_p *= xi - x[i-r+1];  /* p = 1 */
  prod_p *= xi - x[i-r+4];  /* p = 4 */
  sum_n += prod_p;
  sum_m += sum_n;

  /* m = 4 */
  sum_n = 0.0;

  /* n = 0 */
  prod_p = 1.0;
  prod_p *= xi - x[i-r+1];  /* p = 1 */
  prod_p *= xi - x[i-r+2];  /* p = 2 */
  prod_p *= xi - x[i-r+5];  /* p = 5 */
  sum_n += prod_p;

  /* n = 1 */
  prod_p = 1.0;
  prod_p *= xi - x[i-r+0];  /* p = 0 */
  prod_p *= xi - x[i-r+2];  /* p = 2 */
  prod_p *= xi - x[i-r+5];  /* p = 5 */
  sum_n += prod_p;

  /* n = 2 */
  prod_p = 1.0;
  prod_p *= xi - x[i-r+0];  /* p = 0 */
  prod_p *= xi - x[i-r+1];  /* p = 1 */
  prod_p *= xi - x[i-r+5];  /* p = 5 */
  sum_n += prod_p;

  /* n = 5 */
  prod_p = 1.0;
  prod_p *= xi - x[i-r+0];  /* p = 0 */
  prod_p *= xi - x[i-r+1];  /* p = 1 */
  prod_p *= xi - x[i-r+2];  /* p = 2 */
  sum_n += prod_p;
  sum_m += sum_n;

  /* m = 5 */
  sum_n = 0.0;

  /* n = 0 */
  prod_p = 1.0;
  prod_p *= xi - x[i-r+1];  /* p = 1 */
  prod_p *= xi - x[i-r+2];  /* p = 2 */
  prod_p *= xi - x[i-r+4];  /* p = 4 */
  sum_n += prod_p;

  /* n = 1 */
  prod_p = 1.0;
  prod_p *= xi - x[i-r+0];  /* p = 0 */
  prod_p *= xi - x[i-r+2];  /* p = 2 */
  prod_p *= xi - x[i-r+4];  /* p = 4 */
  sum_n += prod_p;

  /* n = 2 */
  prod_p = 1.0;
  prod_p *= xi - x[i-r+0];  /* p = 0 */
  prod_p *= xi - x[i-r+1];  /* p = 1 */
  prod_p *= xi - x[i-r+4];  /* p = 4 */
  sum_n += prod_p;

  /* n = 4 */
  prod_p = 1.0;
  prod_p *= xi - x[i-r+0];  /* p = 0 */
  prod_p *= xi - x[i-r+1];  /* p = 1 */
  prod_p *= xi - x[i-r+2];  /* p = 2 */
  sum_n += prod_p;
  sum_m += sum_n;

  prod_m = 1.0;
  prod_m *= x[i-r+3] - x[i-r+0];
  prod_m *= x[i-r+3] - x[i-r+1];
  prod_m *= x[i-r+3] - x[i-r+2];
  prod_m *= x[i-r+3] - x[i-r+4];
  prod_m *= x[i-r+3] - x[i-r+5];

  sum_l += sum_m / prod_m * (x[i-r+1+1] - x[i-r+1]);

  /* l = 4 */
  sum_m = 0.0;

  /* m = 0 */
  sum_n = 0.0;

  /* n = 1 */
  prod_p = 1.0;
  prod_p *= xi - x[i-r+2];  /* p = 2 */
  prod_p *= xi - x[i-r+3];  /* p = 3 */
  prod_p *= xi - x[i-r+5];  /* p = 5 */
  sum_n += prod_p;

  /* n = 2 */
  prod_p = 1.0;
  prod_p *= xi - x[i-r+1];  /* p = 1 */
  prod_p *= xi - x[i-r+3];  /* p = 3 */
  prod_p *= xi - x[i-r+5];  /* p = 5 */
  sum_n += prod_p;

  /* n = 3 */
  prod_p = 1.0;
  prod_p *= xi - x[i-r+1];  /* p = 1 */
  prod_p *= xi - x[i-r+2];  /* p = 2 */
  prod_p *= xi - x[i-r+5];  /* p = 5 */
  sum_n += prod_p;

  /* n = 5 */
  prod_p = 1.0;
  prod_p *= xi - x[i-r+1];  /* p = 1 */
  prod_p *= xi - x[i-r+2];  /* p = 2 */
  prod_p *= xi - x[i-r+3];  /* p = 3 */
  sum_n += prod_p;
  sum_m += sum_n;

  /* m = 1 */
  sum_n = 0.0;

  /* n = 0 */
  prod_p = 1.0;
  prod_p *= xi - x[i-r+2];  /* p = 2 */
  prod_p *= xi - x[i-r+3];  /* p = 3 */
  prod_p *= xi - x[i-r+5];  /* p = 5 */
  sum_n += prod_p;

  /* n = 2 */
  prod_p = 1.0;
  prod_p *= xi - x[i-r+0];  /* p = 0 */
  prod_p *= xi - x[i-r+3];  /* p = 3 */
  prod_p *= xi - x[i-r+5];  /* p = 5 */
  sum_n += prod_p;

  /* n = 3 */
  prod_p = 1.0;
  prod_p *= xi - x[i-r+0];  /* p = 0 */
  prod_p *= xi - x[i-r+2];  /* p = 2 */
  prod_p *= xi - x[i-r+5];  /* p = 5 */
  sum_n += prod_p;

  /* n = 5 */
  prod_p = 1.0;
  prod_p *= xi - x[i-r+0];  /* p = 0 */
  prod_p *= xi - x[i-r+2];  /* p = 2 */
  prod_p *= xi - x[i-r+3];  /* p = 3 */
  sum_n += prod_p;
  sum_m += sum_n;

  /* m = 2 */
  sum_n = 0.0;

  /* n = 0 */
  prod_p = 1.0;
  prod_p *= xi - x[i-r+1];  /* p = 1 */
  prod_p *= xi - x[i-r+3];  /* p = 3 */
  prod_p *= xi - x[i-r+5];  /* p = 5 */
  sum_n += prod_p;

  /* n = 1 */
  prod_p = 1.0;
  prod_p *= xi - x[i-r+0];  /* p = 0 */
  prod_p *= xi - x[i-r+3];  /* p = 3 */
  prod_p *= xi - x[i-r+5];  /* p = 5 */
  sum_n += prod_p;

  /* n = 3 */
  prod_p = 1.0;
  prod_p *= xi - x[i-r+0];  /* p = 0 */
  prod_p *= xi - x[i-r+1];  /* p = 1 */
  prod_p *= xi - x[i-r+5];  /* p = 5 */
  sum_n += prod_p;

  /* n = 5 */
  prod_p = 1.0;
  prod_p *= xi - x[i-r+0];  /* p = 0 */
  prod_p *= xi - x[i-r+1];  /* p = 1 */
  prod_p *= xi - x[i-r+3];  /* p = 3 */
  sum_n += prod_p;
  sum_m += sum_n;

  /* m = 3 */
  sum_n = 0.0;

  /* n = 0 */
  prod_p = 1.0;
  prod_p *= xi - x[i-r+1];  /* p = 1 */
  prod_p *= xi - x[i-r+2];  /* p = 2 */
  prod_p *= xi - x[i-r+5];  /* p = 5 */
  sum_n += prod_p;

  /* n = 1 */
  prod_p = 1.0;
  prod_p *= xi - x[i-r+0];  /* p = 0 */
  prod_p *= xi - x[i-r+2];  /* p = 2 */
  prod_p *= xi - x[i-r+5];  /* p = 5 */
  sum_n += prod_p;

  /* n = 2 */
  prod_p = 1.0;
  prod_p *= xi - x[i-r+0];  /* p = 0 */
  prod_p *= xi - x[i-r+1];  /* p = 1 */
  prod_p *= xi - x[i-r+5];  /* p = 5 */
  sum_n += prod_p;

  /* n = 5 */
  prod_p = 1.0;
  prod_p *= xi - x[i-r+0];  /* p = 0 */
  prod_p *= xi - x[i-r+1];  /* p = 1 */
  prod_p *= xi - x[i-r+2];  /* p = 2 */
  sum_n += prod_p;
  sum_m += sum_n;

  /* m = 5 */
  sum_n = 0.0;

  /* n = 0 */
  prod_p = 1.0;
  prod_p *= xi - x[i-r+1];  /* p = 1 */
  prod_p *= xi - x[i-r+2];  /* p = 2 */
  prod_p *= xi - x[i-r+3];  /* p = 3 */
  sum_n += prod_p;

  /* n = 1 */
  prod_p = 1.0;
  prod_p *= xi - x[i-r+0];  /* p = 0 */
  prod_p *= xi - x[i-r+2];  /* p = 2 */
  prod_p *= xi - x[i-r+3];  /* p = 3 */
  sum_n += prod_p;

  /* n = 2 */
  prod_p = 1.0;
  prod_p *= xi - x[i-r+0];  /* p = 0 */
  prod_p *= xi - x[i-r+1];  /* p = 1 */
  prod_p *= xi - x[i-r+3];  /* p = 3 */
  sum_n += prod_p;

  /* n = 3 */
  prod_p = 1.0;
  prod_p *= xi - x[i-r+0];  /* p = 0 */
  prod_p *= xi - x[i-r+1];  /* p = 1 */
  prod_p *= xi - x[i-r+2];  /* p = 2 */
  sum_n += prod_p;
  sum_m += sum_n;

  prod_m = 1.0;
  prod_m *= x[i-r+4] - x[i-r+0];
  prod_m *= x[i-r+4] - x[i-r+1];
  prod_m *= x[i-r+4] - x[i-r+2];
  prod_m *= x[i-r+4] - x[i-r+3];
  prod_m *= x[i-r+4] - x[i-r+5];

  sum_l += sum_m / prod_m * (x[i-r+1+1] - x[i-r+1]);

  /* l = 5 */
  sum_m = 0.0;

  /* m = 0 */
  sum_n = 0.0;

  /* n = 1 */
  prod_p = 1.0;
  prod_p *= xi - x[i-r+2];  /* p = 2 */
  prod_p *= xi - x[i-r+3];  /* p = 3 */
  prod_p *= xi - x[i-r+4];  /* p = 4 */
  sum_n += prod_p;

  /* n = 2 */
  prod_p = 1.0;
  prod_p *= xi - x[i-r+1];  /* p = 1 */
  prod_p *= xi - x[i-r+3];  /* p = 3 */
  prod_p *= xi - x[i-r+4];  /* p = 4 */
  sum_n += prod_p;

  /* n = 3 */
  prod_p = 1.0;
  prod_p *= xi - x[i-r+1];  /* p = 1 */
  prod_p *= xi - x[i-r+2];  /* p = 2 */
  prod_p *= xi - x[i-r+4];  /* p = 4 */
  sum_n += prod_p;

  /* n = 4 */
  prod_p = 1.0;
  prod_p *= xi - x[i-r+1];  /* p = 1 */
  prod_p *= xi - x[i-r+2];  /* p = 2 */
  prod_p *= xi - x[i-r+3];  /* p = 3 */
  sum_n += prod_p;
  sum_m += sum_n;

  /* m = 1 */
  sum_n = 0.0;

  /* n = 0 */
  prod_p = 1.0;
  prod_p *= xi - x[i-r+2];  /* p = 2 */
  prod_p *= xi - x[i-r+3];  /* p = 3 */
  prod_p *= xi - x[i-r+4];  /* p = 4 */
  sum_n += prod_p;

  /* n = 2 */
  prod_p = 1.0;
  prod_p *= xi - x[i-r+0];  /* p = 0 */
  prod_p *= xi - x[i-r+3];  /* p = 3 */
  prod_p *= xi - x[i-r+4];  /* p = 4 */
  sum_n += prod_p;

  /* n = 3 */
  prod_p = 1.0;
  prod_p *= xi - x[i-r+0];  /* p = 0 */
  prod_p *= xi - x[i-r+2];  /* p = 2 */
  prod_p *= xi - x[i-r+4];  /* p = 4 */
  sum_n += prod_p;

  /* n = 4 */
  prod_p = 1.0;
  prod_p *= xi - x[i-r+0];  /* p = 0 */
  prod_p *= xi - x[i-r+2];  /* p = 2 */
  prod_p *= xi - x[i-r+3];  /* p = 3 */
  sum_n += prod_p;
  sum_m += sum_n;

  /* m = 2 */
  sum_n = 0.0;

  /* n = 0 */
  prod_p = 1.0;
  prod_p *= xi - x[i-r+1];  /* p = 1 */
  prod_p *= xi - x[i-r+3];  /* p = 3 */
  prod_p *= xi - x[i-r+4];  /* p = 4 */
  sum_n += prod_p;

  /* n = 1 */
  prod_p = 1.0;
  prod_p *= xi - x[i-r+0];  /* p = 0 */
  prod_p *= xi - x[i-r+3];  /* p = 3 */
  prod_p *= xi - x[i-r+4];  /* p = 4 */
  sum_n += prod_p;

  /* n = 3 */
  prod_p = 1.0;
  prod_p *= xi - x[i-r+0];  /* p = 0 */
  prod_p *= xi - x[i-r+1];  /* p = 1 */
  prod_p *= xi - x[i-r+4];  /* p = 4 */
  sum_n += prod_p;

  /* n = 4 */
  prod_p = 1.0;
  prod_p *= xi - x[i-r+0];  /* p = 0 */
  prod_p *= xi - x[i-r+1];  /* p = 1 */
  prod_p *= xi - x[i-r+3];  /* p = 3 */
  sum_n += prod_p;
  sum_m += sum_n;

  /* m = 3 */
  sum_n = 0.0;

  /* n = 0 */
  prod_p = 1.0;
  prod_p *= xi - x[i-r+1];  /* p = 1 */
  prod_p *= xi - x[i-r+2];  /* p = 2 */
  prod_p *= xi - x[i-r+4];  /* p = 4 */
  sum_n += prod_p;

  /* n = 1 */
  prod_p = 1.0;
  prod_p *= xi - x[i-r+0];  /* p = 0 */
  prod_p *= xi - x[i-r+2];  /* p = 2 */
  prod_p *= xi - x[i-r+4];  /* p = 4 */
  sum_n += prod_p;

  /* n = 2 */
  prod_p = 1.0;
  prod_p *= xi - x[i-r+0];  /* p = 0 */
  prod_p *= xi - x[i-r+1];  /* p = 1 */
  prod_p *= xi - x[i-r+4];  /* p = 4 */
  sum_n += prod_p;

  /* n = 4 */
  prod_p = 1.0;
  prod_p *= xi - x[i-r+0];  /* p = 0 */
  prod_p *= xi - x[i-r+1];  /* p = 1 */
  prod_p *= xi - x[i-r+2];  /* p = 2 */
  sum_n += prod_p;
  sum_m += sum_n;

  /* m = 4 */
  sum_n = 0.0;

  /* n = 0 */
  prod_p = 1.0;
  prod_p *= xi - x[i-r+1];  /* p = 1 */
  prod_p *= xi - x[i-r+2];  /* p = 2 */
  prod_p *= xi - x[i-r+3];  /* p = 3 */
  sum_n += prod_p;

  /* n = 1 */
  prod_p = 1.0;
  prod_p *= xi - x[i-r+0];  /* p = 0 */
  prod_p *= xi - x[i-r+2];  /* p = 2 */
  prod_p *= xi - x[i-r+3];  /* p = 3 */
  sum_n += prod_p;

  /* n = 2 */
  prod_p = 1.0;
  prod_p *= xi - x[i-r+0];  /* p = 0 */
  prod_p *= xi - x[i-r+1];  /* p = 1 */
  prod_p *= xi - x[i-r+3];  /* p = 3 */
  sum_n += prod_p;

  /* n = 3 */
  prod_p = 1.0;
  prod_p *= xi - x[i-r+0];  /* p = 0 */
  prod_p *= xi - x[i-r+1];  /* p = 1 */
  prod_p *= xi - x[i-r+2];  /* p = 2 */
  sum_n += prod_p;
  sum_m += sum_n;

  prod_m = 1.0;
  prod_m *= x[i-r+5] - x[i-r+0];
  prod_m *= x[i-r+5] - x[i-r+1];
  prod_m *= x[i-r+5] - x[i-r+2];
  prod_m *= x[i-r+5] - x[i-r+3];
  prod_m *= x[i-r+5] - x[i-r+4];

  sum_l += sum_m / prod_m * (x[i-r+1+1] - x[i-r+1]);

  c[1] = sum_l;
  /* j = 2 */
  sum_l = 0.0;

  /* l = 3 */
  sum_m = 0.0;

  /* m = 0 */
  sum_n = 0.0;

  /* n = 1 */
  prod_p = 1.0;
  prod_p *= xi - x[i-r+2];  /* p = 2 */
  prod_p *= xi - x[i-r+4];  /* p = 4 */
  prod_p *= xi - x[i-r+5];  /* p = 5 */
  sum_n += prod_p;

  /* n = 2 */
  prod_p = 1.0;
  prod_p *= xi - x[i-r+1];  /* p = 1 */
  prod_p *= xi - x[i-r+4];  /* p = 4 */
  prod_p *= xi - x[i-r+5];  /* p = 5 */
  sum_n += prod_p;

  /* n = 4 */
  prod_p = 1.0;
  prod_p *= xi - x[i-r+1];  /* p = 1 */
  prod_p *= xi - x[i-r+2];  /* p = 2 */
  prod_p *= xi - x[i-r+5];  /* p = 5 */
  sum_n += prod_p;

  /* n = 5 */
  prod_p = 1.0;
  prod_p *= xi - x[i-r+1];  /* p = 1 */
  prod_p *= xi - x[i-r+2];  /* p = 2 */
  prod_p *= xi - x[i-r+4];  /* p = 4 */
  sum_n += prod_p;
  sum_m += sum_n;

  /* m = 1 */
  sum_n = 0.0;

  /* n = 0 */
  prod_p = 1.0;
  prod_p *= xi - x[i-r+2];  /* p = 2 */
  prod_p *= xi - x[i-r+4];  /* p = 4 */
  prod_p *= xi - x[i-r+5];  /* p = 5 */
  sum_n += prod_p;

  /* n = 2 */
  prod_p = 1.0;
  prod_p *= xi - x[i-r+0];  /* p = 0 */
  prod_p *= xi - x[i-r+4];  /* p = 4 */
  prod_p *= xi - x[i-r+5];  /* p = 5 */
  sum_n += prod_p;

  /* n = 4 */
  prod_p = 1.0;
  prod_p *= xi - x[i-r+0];  /* p = 0 */
  prod_p *= xi - x[i-r+2];  /* p = 2 */
  prod_p *= xi - x[i-r+5];  /* p = 5 */
  sum_n += prod_p;

  /* n = 5 */
  prod_p = 1.0;
  prod_p *= xi - x[i-r+0];  /* p = 0 */
  prod_p *= xi - x[i-r+2];  /* p = 2 */
  prod_p *= xi - x[i-r+4];  /* p = 4 */
  sum_n += prod_p;
  sum_m += sum_n;

  /* m = 2 */
  sum_n = 0.0;

  /* n = 0 */
  prod_p = 1.0;
  prod_p *= xi - x[i-r+1];  /* p = 1 */
  prod_p *= xi - x[i-r+4];  /* p = 4 */
  prod_p *= xi - x[i-r+5];  /* p = 5 */
  sum_n += prod_p;

  /* n = 1 */
  prod_p = 1.0;
  prod_p *= xi - x[i-r+0];  /* p = 0 */
  prod_p *= xi - x[i-r+4];  /* p = 4 */
  prod_p *= xi - x[i-r+5];  /* p = 5 */
  sum_n += prod_p;

  /* n = 4 */
  prod_p = 1.0;
  prod_p *= xi - x[i-r+0];  /* p = 0 */
  prod_p *= xi - x[i-r+1];  /* p = 1 */
  prod_p *= xi - x[i-r+5];  /* p = 5 */
  sum_n += prod_p;

  /* n = 5 */
  prod_p = 1.0;
  prod_p *= xi - x[i-r+0];  /* p = 0 */
  prod_p *= xi - x[i-r+1];  /* p = 1 */
  prod_p *= xi - x[i-r+4];  /* p = 4 */
  sum_n += prod_p;
  sum_m += sum_n;

  /* m = 4 */
  sum_n = 0.0;

  /* n = 0 */
  prod_p = 1.0;
  prod_p *= xi - x[i-r+1];  /* p = 1 */
  prod_p *= xi - x[i-r+2];  /* p = 2 */
  prod_p *= xi - x[i-r+5];  /* p = 5 */
  sum_n += prod_p;

  /* n = 1 */
  prod_p = 1.0;
  prod_p *= xi - x[i-r+0];  /* p = 0 */
  prod_p *= xi - x[i-r+2];  /* p = 2 */
  prod_p *= xi - x[i-r+5];  /* p = 5 */
  sum_n += prod_p;

  /* n = 2 */
  prod_p = 1.0;
  prod_p *= xi - x[i-r+0];  /* p = 0 */
  prod_p *= xi - x[i-r+1];  /* p = 1 */
  prod_p *= xi - x[i-r+5];  /* p = 5 */
  sum_n += prod_p;

  /* n = 5 */
  prod_p = 1.0;
  prod_p *= xi - x[i-r+0];  /* p = 0 */
  prod_p *= xi - x[i-r+1];  /* p = 1 */
  prod_p *= xi - x[i-r+2];  /* p = 2 */
  sum_n += prod_p;
  sum_m += sum_n;

  /* m = 5 */
  sum_n = 0.0;

  /* n = 0 */
  prod_p = 1.0;
  prod_p *= xi - x[i-r+1];  /* p = 1 */
  prod_p *= xi - x[i-r+2];  /* p = 2 */
  prod_p *= xi - x[i-r+4];  /* p = 4 */
  sum_n += prod_p;

  /* n = 1 */
  prod_p = 1.0;
  prod_p *= xi - x[i-r+0];  /* p = 0 */
  prod_p *= xi - x[i-r+2];  /* p = 2 */
  prod_p *= xi - x[i-r+4];  /* p = 4 */
  sum_n += prod_p;

  /* n = 2 */
  prod_p = 1.0;
  prod_p *= xi - x[i-r+0];  /* p = 0 */
  prod_p *= xi - x[i-r+1];  /* p = 1 */
  prod_p *= xi - x[i-r+4];  /* p = 4 */
  sum_n += prod_p;

  /* n = 4 */
  prod_p = 1.0;
  prod_p *= xi - x[i-r+0];  /* p = 0 */
  prod_p *= xi - x[i-r+1];  /* p = 1 */
  prod_p *= xi - x[i-r+2];  /* p = 2 */
  sum_n += prod_p;
  sum_m += sum_n;

  prod_m = 1.0;
  prod_m *= x[i-r+3] - x[i-r+0];
  prod_m *= x[i-r+3] - x[i-r+1];
  prod_m *= x[i-r+3] - x[i-r+2];
  prod_m *= x[i-r+3] - x[i-r+4];
  prod_m *= x[i-r+3] - x[i-r+5];

  sum_l += sum_m / prod_m * (x[i-r+2+1] - x[i-r+2]);

  /* l = 4 */
  sum_m = 0.0;

  /* m = 0 */
  sum_n = 0.0;

  /* n = 1 */
  prod_p = 1.0;
  prod_p *= xi - x[i-r+2];  /* p = 2 */
  prod_p *= xi - x[i-r+3];  /* p = 3 */
  prod_p *= xi - x[i-r+5];  /* p = 5 */
  sum_n += prod_p;

  /* n = 2 */
  prod_p = 1.0;
  prod_p *= xi - x[i-r+1];  /* p = 1 */
  prod_p *= xi - x[i-r+3];  /* p = 3 */
  prod_p *= xi - x[i-r+5];  /* p = 5 */
  sum_n += prod_p;

  /* n = 3 */
  prod_p = 1.0;
  prod_p *= xi - x[i-r+1];  /* p = 1 */
  prod_p *= xi - x[i-r+2];  /* p = 2 */
  prod_p *= xi - x[i-r+5];  /* p = 5 */
  sum_n += prod_p;

  /* n = 5 */
  prod_p = 1.0;
  prod_p *= xi - x[i-r+1];  /* p = 1 */
  prod_p *= xi - x[i-r+2];  /* p = 2 */
  prod_p *= xi - x[i-r+3];  /* p = 3 */
  sum_n += prod_p;
  sum_m += sum_n;

  /* m = 1 */
  sum_n = 0.0;

  /* n = 0 */
  prod_p = 1.0;
  prod_p *= xi - x[i-r+2];  /* p = 2 */
  prod_p *= xi - x[i-r+3];  /* p = 3 */
  prod_p *= xi - x[i-r+5];  /* p = 5 */
  sum_n += prod_p;

  /* n = 2 */
  prod_p = 1.0;
  prod_p *= xi - x[i-r+0];  /* p = 0 */
  prod_p *= xi - x[i-r+3];  /* p = 3 */
  prod_p *= xi - x[i-r+5];  /* p = 5 */
  sum_n += prod_p;

  /* n = 3 */
  prod_p = 1.0;
  prod_p *= xi - x[i-r+0];  /* p = 0 */
  prod_p *= xi - x[i-r+2];  /* p = 2 */
  prod_p *= xi - x[i-r+5];  /* p = 5 */
  sum_n += prod_p;

  /* n = 5 */
  prod_p = 1.0;
  prod_p *= xi - x[i-r+0];  /* p = 0 */
  prod_p *= xi - x[i-r+2];  /* p = 2 */
  prod_p *= xi - x[i-r+3];  /* p = 3 */
  sum_n += prod_p;
  sum_m += sum_n;

  /* m = 2 */
  sum_n = 0.0;

  /* n = 0 */
  prod_p = 1.0;
  prod_p *= xi - x[i-r+1];  /* p = 1 */
  prod_p *= xi - x[i-r+3];  /* p = 3 */
  prod_p *= xi - x[i-r+5];  /* p = 5 */
  sum_n += prod_p;

  /* n = 1 */
  prod_p = 1.0;
  prod_p *= xi - x[i-r+0];  /* p = 0 */
  prod_p *= xi - x[i-r+3];  /* p = 3 */
  prod_p *= xi - x[i-r+5];  /* p = 5 */
  sum_n += prod_p;

  /* n = 3 */
  prod_p = 1.0;
  prod_p *= xi - x[i-r+0];  /* p = 0 */
  prod_p *= xi - x[i-r+1];  /* p = 1 */
  prod_p *= xi - x[i-r+5];  /* p = 5 */
  sum_n += prod_p;

  /* n = 5 */
  prod_p = 1.0;
  prod_p *= xi - x[i-r+0];  /* p = 0 */
  prod_p *= xi - x[i-r+1];  /* p = 1 */
  prod_p *= xi - x[i-r+3];  /* p = 3 */
  sum_n += prod_p;
  sum_m += sum_n;

  /* m = 3 */
  sum_n = 0.0;

  /* n = 0 */
  prod_p = 1.0;
  prod_p *= xi - x[i-r+1];  /* p = 1 */
  prod_p *= xi - x[i-r+2];  /* p = 2 */
  prod_p *= xi - x[i-r+5];  /* p = 5 */
  sum_n += prod_p;

  /* n = 1 */
  prod_p = 1.0;
  prod_p *= xi - x[i-r+0];  /* p = 0 */
  prod_p *= xi - x[i-r+2];  /* p = 2 */
  prod_p *= xi - x[i-r+5];  /* p = 5 */
  sum_n += prod_p;

  /* n = 2 */
  prod_p = 1.0;
  prod_p *= xi - x[i-r+0];  /* p = 0 */
  prod_p *= xi - x[i-r+1];  /* p = 1 */
  prod_p *= xi - x[i-r+5];  /* p = 5 */
  sum_n += prod_p;

  /* n = 5 */
  prod_p = 1.0;
  prod_p *= xi - x[i-r+0];  /* p = 0 */
  prod_p *= xi - x[i-r+1];  /* p = 1 */
  prod_p *= xi - x[i-r+2];  /* p = 2 */
  sum_n += prod_p;
  sum_m += sum_n;

  /* m = 5 */
  sum_n = 0.0;

  /* n = 0 */
  prod_p = 1.0;
  prod_p *= xi - x[i-r+1];  /* p = 1 */
  prod_p *= xi - x[i-r+2];  /* p = 2 */
  prod_p *= xi - x[i-r+3];  /* p = 3 */
  sum_n += prod_p;

  /* n = 1 */
  prod_p = 1.0;
  prod_p *= xi - x[i-r+0];  /* p = 0 */
  prod_p *= xi - x[i-r+2];  /* p = 2 */
  prod_p *= xi - x[i-r+3];  /* p = 3 */
  sum_n += prod_p;

  /* n = 2 */
  prod_p = 1.0;
  prod_p *= xi - x[i-r+0];  /* p = 0 */
  prod_p *= xi - x[i-r+1];  /* p = 1 */
  prod_p *= xi - x[i-r+3];  /* p = 3 */
  sum_n += prod_p;

  /* n = 3 */
  prod_p = 1.0;
  prod_p *= xi - x[i-r+0];  /* p = 0 */
  prod_p *= xi - x[i-r+1];  /* p = 1 */
  prod_p *= xi - x[i-r+2];  /* p = 2 */
  sum_n += prod_p;
  sum_m += sum_n;

  prod_m = 1.0;
  prod_m *= x[i-r+4] - x[i-r+0];
  prod_m *= x[i-r+4] - x[i-r+1];
  prod_m *= x[i-r+4] - x[i-r+2];
  prod_m *= x[i-r+4] - x[i-r+3];
  prod_m *= x[i-r+4] - x[i-r+5];

  sum_l += sum_m / prod_m * (x[i-r+2+1] - x[i-r+2]);

  /* l = 5 */
  sum_m = 0.0;

  /* m = 0 */
  sum_n = 0.0;

  /* n = 1 */
  prod_p = 1.0;
  prod_p *= xi - x[i-r+2];  /* p = 2 */
  prod_p *= xi - x[i-r+3];  /* p = 3 */
  prod_p *= xi - x[i-r+4];  /* p = 4 */
  sum_n += prod_p;

  /* n = 2 */
  prod_p = 1.0;
  prod_p *= xi - x[i-r+1];  /* p = 1 */
  prod_p *= xi - x[i-r+3];  /* p = 3 */
  prod_p *= xi - x[i-r+4];  /* p = 4 */
  sum_n += prod_p;

  /* n = 3 */
  prod_p = 1.0;
  prod_p *= xi - x[i-r+1];  /* p = 1 */
  prod_p *= xi - x[i-r+2];  /* p = 2 */
  prod_p *= xi - x[i-r+4];  /* p = 4 */
  sum_n += prod_p;

  /* n = 4 */
  prod_p = 1.0;
  prod_p *= xi - x[i-r+1];  /* p = 1 */
  prod_p *= xi - x[i-r+2];  /* p = 2 */
  prod_p *= xi - x[i-r+3];  /* p = 3 */
  sum_n += prod_p;
  sum_m += sum_n;

  /* m = 1 */
  sum_n = 0.0;

  /* n = 0 */
  prod_p = 1.0;
  prod_p *= xi - x[i-r+2];  /* p = 2 */
  prod_p *= xi - x[i-r+3];  /* p = 3 */
  prod_p *= xi - x[i-r+4];  /* p = 4 */
  sum_n += prod_p;

  /* n = 2 */
  prod_p = 1.0;
  prod_p *= xi - x[i-r+0];  /* p = 0 */
  prod_p *= xi - x[i-r+3];  /* p = 3 */
  prod_p *= xi - x[i-r+4];  /* p = 4 */
  sum_n += prod_p;

  /* n = 3 */
  prod_p = 1.0;
  prod_p *= xi - x[i-r+0];  /* p = 0 */
  prod_p *= xi - x[i-r+2];  /* p = 2 */
  prod_p *= xi - x[i-r+4];  /* p = 4 */
  sum_n += prod_p;

  /* n = 4 */
  prod_p = 1.0;
  prod_p *= xi - x[i-r+0];  /* p = 0 */
  prod_p *= xi - x[i-r+2];  /* p = 2 */
  prod_p *= xi - x[i-r+3];  /* p = 3 */
  sum_n += prod_p;
  sum_m += sum_n;

  /* m = 2 */
  sum_n = 0.0;

  /* n = 0 */
  prod_p = 1.0;
  prod_p *= xi - x[i-r+1];  /* p = 1 */
  prod_p *= xi - x[i-r+3];  /* p = 3 */
  prod_p *= xi - x[i-r+4];  /* p = 4 */
  sum_n += prod_p;

  /* n = 1 */
  prod_p = 1.0;
  prod_p *= xi - x[i-r+0];  /* p = 0 */
  prod_p *= xi - x[i-r+3];  /* p = 3 */
  prod_p *= xi - x[i-r+4];  /* p = 4 */
  sum_n += prod_p;

  /* n = 3 */
  prod_p = 1.0;
  prod_p *= xi - x[i-r+0];  /* p = 0 */
  prod_p *= xi - x[i-r+1];  /* p = 1 */
  prod_p *= xi - x[i-r+4];  /* p = 4 */
  sum_n += prod_p;

  /* n = 4 */
  prod_p = 1.0;
  prod_p *= xi - x[i-r+0];  /* p = 0 */
  prod_p *= xi - x[i-r+1];  /* p = 1 */
  prod_p *= xi - x[i-r+3];  /* p = 3 */
  sum_n += prod_p;
  sum_m += sum_n;

  /* m = 3 */
  sum_n = 0.0;

  /* n = 0 */
  prod_p = 1.0;
  prod_p *= xi - x[i-r+1];  /* p = 1 */
  prod_p *= xi - x[i-r+2];  /* p = 2 */
  prod_p *= xi - x[i-r+4];  /* p = 4 */
  sum_n += prod_p;

  /* n = 1 */
  prod_p = 1.0;
  prod_p *= xi - x[i-r+0];  /* p = 0 */
  prod_p *= xi - x[i-r+2];  /* p = 2 */
  prod_p *= xi - x[i-r+4];  /* p = 4 */
  sum_n += prod_p;

  /* n = 2 */
  prod_p = 1.0;
  prod_p *= xi - x[i-r+0];  /* p = 0 */
  prod_p *= xi - x[i-r+1];  /* p = 1 */
  prod_p *= xi - x[i-r+4];  /* p = 4 */
  sum_n += prod_p;

  /* n = 4 */
  prod_p = 1.0;
  prod_p *= xi - x[i-r+0];  /* p = 0 */
  prod_p *= xi - x[i-r+1];  /* p = 1 */
  prod_p *= xi - x[i-r+2];  /* p = 2 */
  sum_n += prod_p;
  sum_m += sum_n;

  /* m = 4 */
  sum_n = 0.0;

  /* n = 0 */
  prod_p = 1.0;
  prod_p *= xi - x[i-r+1];  /* p = 1 */
  prod_p *= xi - x[i-r+2];  /* p = 2 */
  prod_p *= xi - x[i-r+3];  /* p = 3 */
  sum_n += prod_p;

  /* n = 1 */
  prod_p = 1.0;
  prod_p *= xi - x[i-r+0];  /* p = 0 */
  prod_p *= xi - x[i-r+2];  /* p = 2 */
  prod_p *= xi - x[i-r+3];  /* p = 3 */
  sum_n += prod_p;

  /* n = 2 */
  prod_p = 1.0;
  prod_p *= xi - x[i-r+0];  /* p = 0 */
  prod_p *= xi - x[i-r+1];  /* p = 1 */
  prod_p *= xi - x[i-r+3];  /* p = 3 */
  sum_n += prod_p;

  /* n = 3 */
  prod_p = 1.0;
  prod_p *= xi - x[i-r+0];  /* p = 0 */
  prod_p *= xi - x[i-r+1];  /* p = 1 */
  prod_p *= xi - x[i-r+2];  /* p = 2 */
  sum_n += prod_p;
  sum_m += sum_n;

  prod_m = 1.0;
  prod_m *= x[i-r+5] - x[i-r+0];
  prod_m *= x[i-r+5] - x[i-r+1];
  prod_m *= x[i-r+5] - x[i-r+2];
  prod_m *= x[i-r+5] - x[i-r+3];
  prod_m *= x[i-r+5] - x[i-r+4];

  sum_l += sum_m / prod_m * (x[i-r+2+1] - x[i-r+2]);

  c[2] = sum_l;
  /* j = 3 */
  sum_l = 0.0;

  /* l = 4 */
  sum_m = 0.0;

  /* m = 0 */
  sum_n = 0.0;

  /* n = 1 */
  prod_p = 1.0;
  prod_p *= xi - x[i-r+2];  /* p = 2 */
  prod_p *= xi - x[i-r+3];  /* p = 3 */
  prod_p *= xi - x[i-r+5];  /* p = 5 */
  sum_n += prod_p;

  /* n = 2 */
  prod_p = 1.0;
  prod_p *= xi - x[i-r+1];  /* p = 1 */
  prod_p *= xi - x[i-r+3];  /* p = 3 */
  prod_p *= xi - x[i-r+5];  /* p = 5 */
  sum_n += prod_p;

  /* n = 3 */
  prod_p = 1.0;
  prod_p *= xi - x[i-r+1];  /* p = 1 */
  prod_p *= xi - x[i-r+2];  /* p = 2 */
  prod_p *= xi - x[i-r+5];  /* p = 5 */
  sum_n += prod_p;

  /* n = 5 */
  prod_p = 1.0;
  prod_p *= xi - x[i-r+1];  /* p = 1 */
  prod_p *= xi - x[i-r+2];  /* p = 2 */
  prod_p *= xi - x[i-r+3];  /* p = 3 */
  sum_n += prod_p;
  sum_m += sum_n;

  /* m = 1 */
  sum_n = 0.0;

  /* n = 0 */
  prod_p = 1.0;
  prod_p *= xi - x[i-r+2];  /* p = 2 */
  prod_p *= xi - x[i-r+3];  /* p = 3 */
  prod_p *= xi - x[i-r+5];  /* p = 5 */
  sum_n += prod_p;

  /* n = 2 */
  prod_p = 1.0;
  prod_p *= xi - x[i-r+0];  /* p = 0 */
  prod_p *= xi - x[i-r+3];  /* p = 3 */
  prod_p *= xi - x[i-r+5];  /* p = 5 */
  sum_n += prod_p;

  /* n = 3 */
  prod_p = 1.0;
  prod_p *= xi - x[i-r+0];  /* p = 0 */
  prod_p *= xi - x[i-r+2];  /* p = 2 */
  prod_p *= xi - x[i-r+5];  /* p = 5 */
  sum_n += prod_p;

  /* n = 5 */
  prod_p = 1.0;
  prod_p *= xi - x[i-r+0];  /* p = 0 */
  prod_p *= xi - x[i-r+2];  /* p = 2 */
  prod_p *= xi - x[i-r+3];  /* p = 3 */
  sum_n += prod_p;
  sum_m += sum_n;

  /* m = 2 */
  sum_n = 0.0;

  /* n = 0 */
  prod_p = 1.0;
  prod_p *= xi - x[i-r+1];  /* p = 1 */
  prod_p *= xi - x[i-r+3];  /* p = 3 */
  prod_p *= xi - x[i-r+5];  /* p = 5 */
  sum_n += prod_p;

  /* n = 1 */
  prod_p = 1.0;
  prod_p *= xi - x[i-r+0];  /* p = 0 */
  prod_p *= xi - x[i-r+3];  /* p = 3 */
  prod_p *= xi - x[i-r+5];  /* p = 5 */
  sum_n += prod_p;

  /* n = 3 */
  prod_p = 1.0;
  prod_p *= xi - x[i-r+0];  /* p = 0 */
  prod_p *= xi - x[i-r+1];  /* p = 1 */
  prod_p *= xi - x[i-r+5];  /* p = 5 */
  sum_n += prod_p;

  /* n = 5 */
  prod_p = 1.0;
  prod_p *= xi - x[i-r+0];  /* p = 0 */
  prod_p *= xi - x[i-r+1];  /* p = 1 */
  prod_p *= xi - x[i-r+3];  /* p = 3 */
  sum_n += prod_p;
  sum_m += sum_n;

  /* m = 3 */
  sum_n = 0.0;

  /* n = 0 */
  prod_p = 1.0;
  prod_p *= xi - x[i-r+1];  /* p = 1 */
  prod_p *= xi - x[i-r+2];  /* p = 2 */
  prod_p *= xi - x[i-r+5];  /* p = 5 */
  sum_n += prod_p;

  /* n = 1 */
  prod_p = 1.0;
  prod_p *= xi - x[i-r+0];  /* p = 0 */
  prod_p *= xi - x[i-r+2];  /* p = 2 */
  prod_p *= xi - x[i-r+5];  /* p = 5 */
  sum_n += prod_p;

  /* n = 2 */
  prod_p = 1.0;
  prod_p *= xi - x[i-r+0];  /* p = 0 */
  prod_p *= xi - x[i-r+1];  /* p = 1 */
  prod_p *= xi - x[i-r+5];  /* p = 5 */
  sum_n += prod_p;

  /* n = 5 */
  prod_p = 1.0;
  prod_p *= xi - x[i-r+0];  /* p = 0 */
  prod_p *= xi - x[i-r+1];  /* p = 1 */
  prod_p *= xi - x[i-r+2];  /* p = 2 */
  sum_n += prod_p;
  sum_m += sum_n;

  /* m = 5 */
  sum_n = 0.0;

  /* n = 0 */
  prod_p = 1.0;
  prod_p *= xi - x[i-r+1];  /* p = 1 */
  prod_p *= xi - x[i-r+2];  /* p = 2 */
  prod_p *= xi - x[i-r+3];  /* p = 3 */
  sum_n += prod_p;

  /* n = 1 */
  prod_p = 1.0;
  prod_p *= xi - x[i-r+0];  /* p = 0 */
  prod_p *= xi - x[i-r+2];  /* p = 2 */
  prod_p *= xi - x[i-r+3];  /* p = 3 */
  sum_n += prod_p;

  /* n = 2 */
  prod_p = 1.0;
  prod_p *= xi - x[i-r+0];  /* p = 0 */
  prod_p *= xi - x[i-r+1];  /* p = 1 */
  prod_p *= xi - x[i-r+3];  /* p = 3 */
  sum_n += prod_p;

  /* n = 3 */
  prod_p = 1.0;
  prod_p *= xi - x[i-r+0];  /* p = 0 */
  prod_p *= xi - x[i-r+1];  /* p = 1 */
  prod_p *= xi - x[i-r+2];  /* p = 2 */
  sum_n += prod_p;
  sum_m += sum_n;

  prod_m = 1.0;
  prod_m *= x[i-r+4] - x[i-r+0];
  prod_m *= x[i-r+4] - x[i-r+1];
  prod_m *= x[i-r+4] - x[i-r+2];
  prod_m *= x[i-r+4] - x[i-r+3];
  prod_m *= x[i-r+4] - x[i-r+5];

  sum_l += sum_m / prod_m * (x[i-r+3+1] - x[i-r+3]);

  /* l = 5 */
  sum_m = 0.0;

  /* m = 0 */
  sum_n = 0.0;

  /* n = 1 */
  prod_p = 1.0;
  prod_p *= xi - x[i-r+2];  /* p = 2 */
  prod_p *= xi - x[i-r+3];  /* p = 3 */
  prod_p *= xi - x[i-r+4];  /* p = 4 */
  sum_n += prod_p;

  /* n = 2 */
  prod_p = 1.0;
  prod_p *= xi - x[i-r+1];  /* p = 1 */
  prod_p *= xi - x[i-r+3];  /* p = 3 */
  prod_p *= xi - x[i-r+4];  /* p = 4 */
  sum_n += prod_p;

  /* n = 3 */
  prod_p = 1.0;
  prod_p *= xi - x[i-r+1];  /* p = 1 */
  prod_p *= xi - x[i-r+2];  /* p = 2 */
  prod_p *= xi - x[i-r+4];  /* p = 4 */
  sum_n += prod_p;

  /* n = 4 */
  prod_p = 1.0;
  prod_p *= xi - x[i-r+1];  /* p = 1 */
  prod_p *= xi - x[i-r+2];  /* p = 2 */
  prod_p *= xi - x[i-r+3];  /* p = 3 */
  sum_n += prod_p;
  sum_m += sum_n;

  /* m = 1 */
  sum_n = 0.0;

  /* n = 0 */
  prod_p = 1.0;
  prod_p *= xi - x[i-r+2];  /* p = 2 */
  prod_p *= xi - x[i-r+3];  /* p = 3 */
  prod_p *= xi - x[i-r+4];  /* p = 4 */
  sum_n += prod_p;

  /* n = 2 */
  prod_p = 1.0;
  prod_p *= xi - x[i-r+0];  /* p = 0 */
  prod_p *= xi - x[i-r+3];  /* p = 3 */
  prod_p *= xi - x[i-r+4];  /* p = 4 */
  sum_n += prod_p;

  /* n = 3 */
  prod_p = 1.0;
  prod_p *= xi - x[i-r+0];  /* p = 0 */
  prod_p *= xi - x[i-r+2];  /* p = 2 */
  prod_p *= xi - x[i-r+4];  /* p = 4 */
  sum_n += prod_p;

  /* n = 4 */
  prod_p = 1.0;
  prod_p *= xi - x[i-r+0];  /* p = 0 */
  prod_p *= xi - x[i-r+2];  /* p = 2 */
  prod_p *= xi - x[i-r+3];  /* p = 3 */
  sum_n += prod_p;
  sum_m += sum_n;

  /* m = 2 */
  sum_n = 0.0;

  /* n = 0 */
  prod_p = 1.0;
  prod_p *= xi - x[i-r+1];  /* p = 1 */
  prod_p *= xi - x[i-r+3];  /* p = 3 */
  prod_p *= xi - x[i-r+4];  /* p = 4 */
  sum_n += prod_p;

  /* n = 1 */
  prod_p = 1.0;
  prod_p *= xi - x[i-r+0];  /* p = 0 */
  prod_p *= xi - x[i-r+3];  /* p = 3 */
  prod_p *= xi - x[i-r+4];  /* p = 4 */
  sum_n += prod_p;

  /* n = 3 */
  prod_p = 1.0;
  prod_p *= xi - x[i-r+0];  /* p = 0 */
  prod_p *= xi - x[i-r+1];  /* p = 1 */
  prod_p *= xi - x[i-r+4];  /* p = 4 */
  sum_n += prod_p;

  /* n = 4 */
  prod_p = 1.0;
  prod_p *= xi - x[i-r+0];  /* p = 0 */
  prod_p *= xi - x[i-r+1];  /* p = 1 */
  prod_p *= xi - x[i-r+3];  /* p = 3 */
  sum_n += prod_p;
  sum_m += sum_n;

  /* m = 3 */
  sum_n = 0.0;

  /* n = 0 */
  prod_p = 1.0;
  prod_p *= xi - x[i-r+1];  /* p = 1 */
  prod_p *= xi - x[i-r+2];  /* p = 2 */
  prod_p *= xi - x[i-r+4];  /* p = 4 */
  sum_n += prod_p;

  /* n = 1 */
  prod_p = 1.0;
  prod_p *= xi - x[i-r+0];  /* p = 0 */
  prod_p *= xi - x[i-r+2];  /* p = 2 */
  prod_p *= xi - x[i-r+4];  /* p = 4 */
  sum_n += prod_p;

  /* n = 2 */
  prod_p = 1.0;
  prod_p *= xi - x[i-r+0];  /* p = 0 */
  prod_p *= xi - x[i-r+1];  /* p = 1 */
  prod_p *= xi - x[i-r+4];  /* p = 4 */
  sum_n += prod_p;

  /* n = 4 */
  prod_p = 1.0;
  prod_p *= xi - x[i-r+0];  /* p = 0 */
  prod_p *= xi - x[i-r+1];  /* p = 1 */
  prod_p *= xi - x[i-r+2];  /* p = 2 */
  sum_n += prod_p;
  sum_m += sum_n;

  /* m = 4 */
  sum_n = 0.0;

  /* n = 0 */
  prod_p = 1.0;
  prod_p *= xi - x[i-r+1];  /* p = 1 */
  prod_p *= xi - x[i-r+2];  /* p = 2 */
  prod_p *= xi - x[i-r+3];  /* p = 3 */
  sum_n += prod_p;

  /* n = 1 */
  prod_p = 1.0;
  prod_p *= xi - x[i-r+0];  /* p = 0 */
  prod_p *= xi - x[i-r+2];  /* p = 2 */
  prod_p *= xi - x[i-r+3];  /* p = 3 */
  sum_n += prod_p;

  /* n = 2 */
  prod_p = 1.0;
  prod_p *= xi - x[i-r+0];  /* p = 0 */
  prod_p *= xi - x[i-r+1];  /* p = 1 */
  prod_p *= xi - x[i-r+3];  /* p = 3 */
  sum_n += prod_p;

  /* n = 3 */
  prod_p = 1.0;
  prod_p *= xi - x[i-r+0];  /* p = 0 */
  prod_p *= xi - x[i-r+1];  /* p = 1 */
  prod_p *= xi - x[i-r+2];  /* p = 2 */
  sum_n += prod_p;
  sum_m += sum_n;

  prod_m = 1.0;
  prod_m *= x[i-r+5] - x[i-r+0];
  prod_m *= x[i-r+5] - x[i-r+1];
  prod_m *= x[i-r+5] - x[i-r+2];
  prod_m *= x[i-r+5] - x[i-r+3];
  prod_m *= x[i-r+5] - x[i-r+4];

  sum_l += sum_m / prod_m * (x[i-r+3+1] - x[i-r+3]);

  c[3] = sum_l;
  /* j = 4 */
  sum_l = 0.0;

  /* l = 5 */
  sum_m = 0.0;

  /* m = 0 */
  sum_n = 0.0;

  /* n = 1 */
  prod_p = 1.0;
  prod_p *= xi - x[i-r+2];  /* p = 2 */
  prod_p *= xi - x[i-r+3];  /* p = 3 */
  prod_p *= xi - x[i-r+4];  /* p = 4 */
  sum_n += prod_p;

  /* n = 2 */
  prod_p = 1.0;
  prod_p *= xi - x[i-r+1];  /* p = 1 */
  prod_p *= xi - x[i-r+3];  /* p = 3 */
  prod_p *= xi - x[i-r+4];  /* p = 4 */
  sum_n += prod_p;

  /* n = 3 */
  prod_p = 1.0;
  prod_p *= xi - x[i-r+1];  /* p = 1 */
  prod_p *= xi - x[i-r+2];  /* p = 2 */
  prod_p *= xi - x[i-r+4];  /* p = 4 */
  sum_n += prod_p;

  /* n = 4 */
  prod_p = 1.0;
  prod_p *= xi - x[i-r+1];  /* p = 1 */
  prod_p *= xi - x[i-r+2];  /* p = 2 */
  prod_p *= xi - x[i-r+3];  /* p = 3 */
  sum_n += prod_p;
  sum_m += sum_n;

  /* m = 1 */
  sum_n = 0.0;

  /* n = 0 */
  prod_p = 1.0;
  prod_p *= xi - x[i-r+2];  /* p = 2 */
  prod_p *= xi - x[i-r+3];  /* p = 3 */
  prod_p *= xi - x[i-r+4];  /* p = 4 */
  sum_n += prod_p;

  /* n = 2 */
  prod_p = 1.0;
  prod_p *= xi - x[i-r+0];  /* p = 0 */
  prod_p *= xi - x[i-r+3];  /* p = 3 */
  prod_p *= xi - x[i-r+4];  /* p = 4 */
  sum_n += prod_p;

  /* n = 3 */
  prod_p = 1.0;
  prod_p *= xi - x[i-r+0];  /* p = 0 */
  prod_p *= xi - x[i-r+2];  /* p = 2 */
  prod_p *= xi - x[i-r+4];  /* p = 4 */
  sum_n += prod_p;

  /* n = 4 */
  prod_p = 1.0;
  prod_p *= xi - x[i-r+0];  /* p = 0 */
  prod_p *= xi - x[i-r+2];  /* p = 2 */
  prod_p *= xi - x[i-r+3];  /* p = 3 */
  sum_n += prod_p;
  sum_m += sum_n;

  /* m = 2 */
  sum_n = 0.0;

  /* n = 0 */
  prod_p = 1.0;
  prod_p *= xi - x[i-r+1];  /* p = 1 */
  prod_p *= xi - x[i-r+3];  /* p = 3 */
  prod_p *= xi - x[i-r+4];  /* p = 4 */
  sum_n += prod_p;

  /* n = 1 */
  prod_p = 1.0;
  prod_p *= xi - x[i-r+0];  /* p = 0 */
  prod_p *= xi - x[i-r+3];  /* p = 3 */
  prod_p *= xi - x[i-r+4];  /* p = 4 */
  sum_n += prod_p;

  /* n = 3 */
  prod_p = 1.0;
  prod_p *= xi - x[i-r+0];  /* p = 0 */
  prod_p *= xi - x[i-r+1];  /* p = 1 */
  prod_p *= xi - x[i-r+4];  /* p = 4 */
  sum_n += prod_p;

  /* n = 4 */
  prod_p = 1.0;
  prod_p *= xi - x[i-r+0];  /* p = 0 */
  prod_p *= xi - x[i-r+1];  /* p = 1 */
  prod_p *= xi - x[i-r+3];  /* p = 3 */
  sum_n += prod_p;
  sum_m += sum_n;

  /* m = 3 */
  sum_n = 0.0;

  /* n = 0 */
  prod_p = 1.0;
  prod_p *= xi - x[i-r+1];  /* p = 1 */
  prod_p *= xi - x[i-r+2];  /* p = 2 */
  prod_p *= xi - x[i-r+4];  /* p = 4 */
  sum_n += prod_p;

  /* n = 1 */
  prod_p = 1.0;
  prod_p *= xi - x[i-r+0];  /* p = 0 */
  prod_p *= xi - x[i-r+2];  /* p = 2 */
  prod_p *= xi - x[i-r+4];  /* p = 4 */
  sum_n += prod_p;

  /* n = 2 */
  prod_p = 1.0;
  prod_p *= xi - x[i-r+0];  /* p = 0 */
  prod_p *= xi - x[i-r+1];  /* p = 1 */
  prod_p *= xi - x[i-r+4];  /* p = 4 */
  sum_n += prod_p;

  /* n = 4 */
  prod_p = 1.0;
  prod_p *= xi - x[i-r+0];  /* p = 0 */
  prod_p *= xi - x[i-r+1];  /* p = 1 */
  prod_p *= xi - x[i-r+2];  /* p = 2 */
  sum_n += prod_p;
  sum_m += sum_n;

  /* m = 4 */
  sum_n = 0.0;

  /* n = 0 */
  prod_p = 1.0;
  prod_p *= xi - x[i-r+1];  /* p = 1 */
  prod_p *= xi - x[i-r+2];  /* p = 2 */
  prod_p *= xi - x[i-r+3];  /* p = 3 */
  sum_n += prod_p;

  /* n = 1 */
  prod_p = 1.0;
  prod_p *= xi - x[i-r+0];  /* p = 0 */
  prod_p *= xi - x[i-r+2];  /* p = 2 */
  prod_p *= xi - x[i-r+3];  /* p = 3 */
  sum_n += prod_p;

  /* n = 2 */
  prod_p = 1.0;
  prod_p *= xi - x[i-r+0];  /* p = 0 */
  prod_p *= xi - x[i-r+1];  /* p = 1 */
  prod_p *= xi - x[i-r+3];  /* p = 3 */
  sum_n += prod_p;

  /* n = 3 */
  prod_p = 1.0;
  prod_p *= xi - x[i-r+0];  /* p = 0 */
  prod_p *= xi - x[i-r+1];  /* p = 1 */
  prod_p *= xi - x[i-r+2];  /* p = 2 */
  sum_n += prod_p;
  sum_m += sum_n;

  prod_m = 1.0;
  prod_m *= x[i-r+5] - x[i-r+0];
  prod_m *= x[i-r+5] - x[i-r+1];
  prod_m *= x[i-r+5] - x[i-r+2];
  prod_m *= x[i-r+5] - x[i-r+3];
  prod_m *= x[i-r+5] - x[i-r+4];

  sum_l += sum_m / prod_m * (x[i-r+4+1] - x[i-r+4]);

  c[4] = sum_l;
}
