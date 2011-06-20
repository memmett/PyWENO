void
coeffs008 (double xi, long int i, int r, double *x, double *c)
{
  double sum_l, sum_m, prod_n, prod_m;
  /* j = 0 */
  sum_l = 0.0;

  /* l = 1 */
  sum_m = 0.0;

  /* m = 0 */
  prod_n = 1.0;
  prod_n *= xi - x[i - r + 2];	/* n = 2 */
  prod_n *= xi - x[i - r + 3];	/* n = 3 */
  prod_n *= xi - x[i - r + 4];	/* n = 4 */
  prod_n *= xi - x[i - r + 5];	/* n = 5 */
  prod_n *= xi - x[i - r + 6];	/* n = 6 */
  prod_n *= xi - x[i - r + 7];	/* n = 7 */
  prod_n *= xi - x[i - r + 8];	/* n = 8 */
  sum_m += prod_n;

  /* m = 2 */
  prod_n = 1.0;
  prod_n *= xi - x[i - r + 0];	/* n = 0 */
  prod_n *= xi - x[i - r + 3];	/* n = 3 */
  prod_n *= xi - x[i - r + 4];	/* n = 4 */
  prod_n *= xi - x[i - r + 5];	/* n = 5 */
  prod_n *= xi - x[i - r + 6];	/* n = 6 */
  prod_n *= xi - x[i - r + 7];	/* n = 7 */
  prod_n *= xi - x[i - r + 8];	/* n = 8 */
  sum_m += prod_n;

  /* m = 3 */
  prod_n = 1.0;
  prod_n *= xi - x[i - r + 0];	/* n = 0 */
  prod_n *= xi - x[i - r + 2];	/* n = 2 */
  prod_n *= xi - x[i - r + 4];	/* n = 4 */
  prod_n *= xi - x[i - r + 5];	/* n = 5 */
  prod_n *= xi - x[i - r + 6];	/* n = 6 */
  prod_n *= xi - x[i - r + 7];	/* n = 7 */
  prod_n *= xi - x[i - r + 8];	/* n = 8 */
  sum_m += prod_n;

  /* m = 4 */
  prod_n = 1.0;
  prod_n *= xi - x[i - r + 0];	/* n = 0 */
  prod_n *= xi - x[i - r + 2];	/* n = 2 */
  prod_n *= xi - x[i - r + 3];	/* n = 3 */
  prod_n *= xi - x[i - r + 5];	/* n = 5 */
  prod_n *= xi - x[i - r + 6];	/* n = 6 */
  prod_n *= xi - x[i - r + 7];	/* n = 7 */
  prod_n *= xi - x[i - r + 8];	/* n = 8 */
  sum_m += prod_n;

  /* m = 5 */
  prod_n = 1.0;
  prod_n *= xi - x[i - r + 0];	/* n = 0 */
  prod_n *= xi - x[i - r + 2];	/* n = 2 */
  prod_n *= xi - x[i - r + 3];	/* n = 3 */
  prod_n *= xi - x[i - r + 4];	/* n = 4 */
  prod_n *= xi - x[i - r + 6];	/* n = 6 */
  prod_n *= xi - x[i - r + 7];	/* n = 7 */
  prod_n *= xi - x[i - r + 8];	/* n = 8 */
  sum_m += prod_n;

  /* m = 6 */
  prod_n = 1.0;
  prod_n *= xi - x[i - r + 0];	/* n = 0 */
  prod_n *= xi - x[i - r + 2];	/* n = 2 */
  prod_n *= xi - x[i - r + 3];	/* n = 3 */
  prod_n *= xi - x[i - r + 4];	/* n = 4 */
  prod_n *= xi - x[i - r + 5];	/* n = 5 */
  prod_n *= xi - x[i - r + 7];	/* n = 7 */
  prod_n *= xi - x[i - r + 8];	/* n = 8 */
  sum_m += prod_n;

  /* m = 7 */
  prod_n = 1.0;
  prod_n *= xi - x[i - r + 0];	/* n = 0 */
  prod_n *= xi - x[i - r + 2];	/* n = 2 */
  prod_n *= xi - x[i - r + 3];	/* n = 3 */
  prod_n *= xi - x[i - r + 4];	/* n = 4 */
  prod_n *= xi - x[i - r + 5];	/* n = 5 */
  prod_n *= xi - x[i - r + 6];	/* n = 6 */
  prod_n *= xi - x[i - r + 8];	/* n = 8 */
  sum_m += prod_n;

  /* m = 8 */
  prod_n = 1.0;
  prod_n *= xi - x[i - r + 0];	/* n = 0 */
  prod_n *= xi - x[i - r + 2];	/* n = 2 */
  prod_n *= xi - x[i - r + 3];	/* n = 3 */
  prod_n *= xi - x[i - r + 4];	/* n = 4 */
  prod_n *= xi - x[i - r + 5];	/* n = 5 */
  prod_n *= xi - x[i - r + 6];	/* n = 6 */
  prod_n *= xi - x[i - r + 7];	/* n = 7 */
  sum_m += prod_n;

  prod_m = 1.0;
  prod_m *= x[i - r + 1] - x[i - r + 0];
  prod_m *= x[i - r + 1] - x[i - r + 2];
  prod_m *= x[i - r + 1] - x[i - r + 3];
  prod_m *= x[i - r + 1] - x[i - r + 4];
  prod_m *= x[i - r + 1] - x[i - r + 5];
  prod_m *= x[i - r + 1] - x[i - r + 6];
  prod_m *= x[i - r + 1] - x[i - r + 7];
  prod_m *= x[i - r + 1] - x[i - r + 8];

  sum_l += sum_m / prod_m * (x[i - r + 0 + 1] - x[i - r + 0]);

  /* l = 2 */
  sum_m = 0.0;

  /* m = 0 */
  prod_n = 1.0;
  prod_n *= xi - x[i - r + 1];	/* n = 1 */
  prod_n *= xi - x[i - r + 3];	/* n = 3 */
  prod_n *= xi - x[i - r + 4];	/* n = 4 */
  prod_n *= xi - x[i - r + 5];	/* n = 5 */
  prod_n *= xi - x[i - r + 6];	/* n = 6 */
  prod_n *= xi - x[i - r + 7];	/* n = 7 */
  prod_n *= xi - x[i - r + 8];	/* n = 8 */
  sum_m += prod_n;

  /* m = 1 */
  prod_n = 1.0;
  prod_n *= xi - x[i - r + 0];	/* n = 0 */
  prod_n *= xi - x[i - r + 3];	/* n = 3 */
  prod_n *= xi - x[i - r + 4];	/* n = 4 */
  prod_n *= xi - x[i - r + 5];	/* n = 5 */
  prod_n *= xi - x[i - r + 6];	/* n = 6 */
  prod_n *= xi - x[i - r + 7];	/* n = 7 */
  prod_n *= xi - x[i - r + 8];	/* n = 8 */
  sum_m += prod_n;

  /* m = 3 */
  prod_n = 1.0;
  prod_n *= xi - x[i - r + 0];	/* n = 0 */
  prod_n *= xi - x[i - r + 1];	/* n = 1 */
  prod_n *= xi - x[i - r + 4];	/* n = 4 */
  prod_n *= xi - x[i - r + 5];	/* n = 5 */
  prod_n *= xi - x[i - r + 6];	/* n = 6 */
  prod_n *= xi - x[i - r + 7];	/* n = 7 */
  prod_n *= xi - x[i - r + 8];	/* n = 8 */
  sum_m += prod_n;

  /* m = 4 */
  prod_n = 1.0;
  prod_n *= xi - x[i - r + 0];	/* n = 0 */
  prod_n *= xi - x[i - r + 1];	/* n = 1 */
  prod_n *= xi - x[i - r + 3];	/* n = 3 */
  prod_n *= xi - x[i - r + 5];	/* n = 5 */
  prod_n *= xi - x[i - r + 6];	/* n = 6 */
  prod_n *= xi - x[i - r + 7];	/* n = 7 */
  prod_n *= xi - x[i - r + 8];	/* n = 8 */
  sum_m += prod_n;

  /* m = 5 */
  prod_n = 1.0;
  prod_n *= xi - x[i - r + 0];	/* n = 0 */
  prod_n *= xi - x[i - r + 1];	/* n = 1 */
  prod_n *= xi - x[i - r + 3];	/* n = 3 */
  prod_n *= xi - x[i - r + 4];	/* n = 4 */
  prod_n *= xi - x[i - r + 6];	/* n = 6 */
  prod_n *= xi - x[i - r + 7];	/* n = 7 */
  prod_n *= xi - x[i - r + 8];	/* n = 8 */
  sum_m += prod_n;

  /* m = 6 */
  prod_n = 1.0;
  prod_n *= xi - x[i - r + 0];	/* n = 0 */
  prod_n *= xi - x[i - r + 1];	/* n = 1 */
  prod_n *= xi - x[i - r + 3];	/* n = 3 */
  prod_n *= xi - x[i - r + 4];	/* n = 4 */
  prod_n *= xi - x[i - r + 5];	/* n = 5 */
  prod_n *= xi - x[i - r + 7];	/* n = 7 */
  prod_n *= xi - x[i - r + 8];	/* n = 8 */
  sum_m += prod_n;

  /* m = 7 */
  prod_n = 1.0;
  prod_n *= xi - x[i - r + 0];	/* n = 0 */
  prod_n *= xi - x[i - r + 1];	/* n = 1 */
  prod_n *= xi - x[i - r + 3];	/* n = 3 */
  prod_n *= xi - x[i - r + 4];	/* n = 4 */
  prod_n *= xi - x[i - r + 5];	/* n = 5 */
  prod_n *= xi - x[i - r + 6];	/* n = 6 */
  prod_n *= xi - x[i - r + 8];	/* n = 8 */
  sum_m += prod_n;

  /* m = 8 */
  prod_n = 1.0;
  prod_n *= xi - x[i - r + 0];	/* n = 0 */
  prod_n *= xi - x[i - r + 1];	/* n = 1 */
  prod_n *= xi - x[i - r + 3];	/* n = 3 */
  prod_n *= xi - x[i - r + 4];	/* n = 4 */
  prod_n *= xi - x[i - r + 5];	/* n = 5 */
  prod_n *= xi - x[i - r + 6];	/* n = 6 */
  prod_n *= xi - x[i - r + 7];	/* n = 7 */
  sum_m += prod_n;

  prod_m = 1.0;
  prod_m *= x[i - r + 2] - x[i - r + 0];
  prod_m *= x[i - r + 2] - x[i - r + 1];
  prod_m *= x[i - r + 2] - x[i - r + 3];
  prod_m *= x[i - r + 2] - x[i - r + 4];
  prod_m *= x[i - r + 2] - x[i - r + 5];
  prod_m *= x[i - r + 2] - x[i - r + 6];
  prod_m *= x[i - r + 2] - x[i - r + 7];
  prod_m *= x[i - r + 2] - x[i - r + 8];

  sum_l += sum_m / prod_m * (x[i - r + 0 + 1] - x[i - r + 0]);

  /* l = 3 */
  sum_m = 0.0;

  /* m = 0 */
  prod_n = 1.0;
  prod_n *= xi - x[i - r + 1];	/* n = 1 */
  prod_n *= xi - x[i - r + 2];	/* n = 2 */
  prod_n *= xi - x[i - r + 4];	/* n = 4 */
  prod_n *= xi - x[i - r + 5];	/* n = 5 */
  prod_n *= xi - x[i - r + 6];	/* n = 6 */
  prod_n *= xi - x[i - r + 7];	/* n = 7 */
  prod_n *= xi - x[i - r + 8];	/* n = 8 */
  sum_m += prod_n;

  /* m = 1 */
  prod_n = 1.0;
  prod_n *= xi - x[i - r + 0];	/* n = 0 */
  prod_n *= xi - x[i - r + 2];	/* n = 2 */
  prod_n *= xi - x[i - r + 4];	/* n = 4 */
  prod_n *= xi - x[i - r + 5];	/* n = 5 */
  prod_n *= xi - x[i - r + 6];	/* n = 6 */
  prod_n *= xi - x[i - r + 7];	/* n = 7 */
  prod_n *= xi - x[i - r + 8];	/* n = 8 */
  sum_m += prod_n;

  /* m = 2 */
  prod_n = 1.0;
  prod_n *= xi - x[i - r + 0];	/* n = 0 */
  prod_n *= xi - x[i - r + 1];	/* n = 1 */
  prod_n *= xi - x[i - r + 4];	/* n = 4 */
  prod_n *= xi - x[i - r + 5];	/* n = 5 */
  prod_n *= xi - x[i - r + 6];	/* n = 6 */
  prod_n *= xi - x[i - r + 7];	/* n = 7 */
  prod_n *= xi - x[i - r + 8];	/* n = 8 */
  sum_m += prod_n;

  /* m = 4 */
  prod_n = 1.0;
  prod_n *= xi - x[i - r + 0];	/* n = 0 */
  prod_n *= xi - x[i - r + 1];	/* n = 1 */
  prod_n *= xi - x[i - r + 2];	/* n = 2 */
  prod_n *= xi - x[i - r + 5];	/* n = 5 */
  prod_n *= xi - x[i - r + 6];	/* n = 6 */
  prod_n *= xi - x[i - r + 7];	/* n = 7 */
  prod_n *= xi - x[i - r + 8];	/* n = 8 */
  sum_m += prod_n;

  /* m = 5 */
  prod_n = 1.0;
  prod_n *= xi - x[i - r + 0];	/* n = 0 */
  prod_n *= xi - x[i - r + 1];	/* n = 1 */
  prod_n *= xi - x[i - r + 2];	/* n = 2 */
  prod_n *= xi - x[i - r + 4];	/* n = 4 */
  prod_n *= xi - x[i - r + 6];	/* n = 6 */
  prod_n *= xi - x[i - r + 7];	/* n = 7 */
  prod_n *= xi - x[i - r + 8];	/* n = 8 */
  sum_m += prod_n;

  /* m = 6 */
  prod_n = 1.0;
  prod_n *= xi - x[i - r + 0];	/* n = 0 */
  prod_n *= xi - x[i - r + 1];	/* n = 1 */
  prod_n *= xi - x[i - r + 2];	/* n = 2 */
  prod_n *= xi - x[i - r + 4];	/* n = 4 */
  prod_n *= xi - x[i - r + 5];	/* n = 5 */
  prod_n *= xi - x[i - r + 7];	/* n = 7 */
  prod_n *= xi - x[i - r + 8];	/* n = 8 */
  sum_m += prod_n;

  /* m = 7 */
  prod_n = 1.0;
  prod_n *= xi - x[i - r + 0];	/* n = 0 */
  prod_n *= xi - x[i - r + 1];	/* n = 1 */
  prod_n *= xi - x[i - r + 2];	/* n = 2 */
  prod_n *= xi - x[i - r + 4];	/* n = 4 */
  prod_n *= xi - x[i - r + 5];	/* n = 5 */
  prod_n *= xi - x[i - r + 6];	/* n = 6 */
  prod_n *= xi - x[i - r + 8];	/* n = 8 */
  sum_m += prod_n;

  /* m = 8 */
  prod_n = 1.0;
  prod_n *= xi - x[i - r + 0];	/* n = 0 */
  prod_n *= xi - x[i - r + 1];	/* n = 1 */
  prod_n *= xi - x[i - r + 2];	/* n = 2 */
  prod_n *= xi - x[i - r + 4];	/* n = 4 */
  prod_n *= xi - x[i - r + 5];	/* n = 5 */
  prod_n *= xi - x[i - r + 6];	/* n = 6 */
  prod_n *= xi - x[i - r + 7];	/* n = 7 */
  sum_m += prod_n;

  prod_m = 1.0;
  prod_m *= x[i - r + 3] - x[i - r + 0];
  prod_m *= x[i - r + 3] - x[i - r + 1];
  prod_m *= x[i - r + 3] - x[i - r + 2];
  prod_m *= x[i - r + 3] - x[i - r + 4];
  prod_m *= x[i - r + 3] - x[i - r + 5];
  prod_m *= x[i - r + 3] - x[i - r + 6];
  prod_m *= x[i - r + 3] - x[i - r + 7];
  prod_m *= x[i - r + 3] - x[i - r + 8];

  sum_l += sum_m / prod_m * (x[i - r + 0 + 1] - x[i - r + 0]);

  /* l = 4 */
  sum_m = 0.0;

  /* m = 0 */
  prod_n = 1.0;
  prod_n *= xi - x[i - r + 1];	/* n = 1 */
  prod_n *= xi - x[i - r + 2];	/* n = 2 */
  prod_n *= xi - x[i - r + 3];	/* n = 3 */
  prod_n *= xi - x[i - r + 5];	/* n = 5 */
  prod_n *= xi - x[i - r + 6];	/* n = 6 */
  prod_n *= xi - x[i - r + 7];	/* n = 7 */
  prod_n *= xi - x[i - r + 8];	/* n = 8 */
  sum_m += prod_n;

  /* m = 1 */
  prod_n = 1.0;
  prod_n *= xi - x[i - r + 0];	/* n = 0 */
  prod_n *= xi - x[i - r + 2];	/* n = 2 */
  prod_n *= xi - x[i - r + 3];	/* n = 3 */
  prod_n *= xi - x[i - r + 5];	/* n = 5 */
  prod_n *= xi - x[i - r + 6];	/* n = 6 */
  prod_n *= xi - x[i - r + 7];	/* n = 7 */
  prod_n *= xi - x[i - r + 8];	/* n = 8 */
  sum_m += prod_n;

  /* m = 2 */
  prod_n = 1.0;
  prod_n *= xi - x[i - r + 0];	/* n = 0 */
  prod_n *= xi - x[i - r + 1];	/* n = 1 */
  prod_n *= xi - x[i - r + 3];	/* n = 3 */
  prod_n *= xi - x[i - r + 5];	/* n = 5 */
  prod_n *= xi - x[i - r + 6];	/* n = 6 */
  prod_n *= xi - x[i - r + 7];	/* n = 7 */
  prod_n *= xi - x[i - r + 8];	/* n = 8 */
  sum_m += prod_n;

  /* m = 3 */
  prod_n = 1.0;
  prod_n *= xi - x[i - r + 0];	/* n = 0 */
  prod_n *= xi - x[i - r + 1];	/* n = 1 */
  prod_n *= xi - x[i - r + 2];	/* n = 2 */
  prod_n *= xi - x[i - r + 5];	/* n = 5 */
  prod_n *= xi - x[i - r + 6];	/* n = 6 */
  prod_n *= xi - x[i - r + 7];	/* n = 7 */
  prod_n *= xi - x[i - r + 8];	/* n = 8 */
  sum_m += prod_n;

  /* m = 5 */
  prod_n = 1.0;
  prod_n *= xi - x[i - r + 0];	/* n = 0 */
  prod_n *= xi - x[i - r + 1];	/* n = 1 */
  prod_n *= xi - x[i - r + 2];	/* n = 2 */
  prod_n *= xi - x[i - r + 3];	/* n = 3 */
  prod_n *= xi - x[i - r + 6];	/* n = 6 */
  prod_n *= xi - x[i - r + 7];	/* n = 7 */
  prod_n *= xi - x[i - r + 8];	/* n = 8 */
  sum_m += prod_n;

  /* m = 6 */
  prod_n = 1.0;
  prod_n *= xi - x[i - r + 0];	/* n = 0 */
  prod_n *= xi - x[i - r + 1];	/* n = 1 */
  prod_n *= xi - x[i - r + 2];	/* n = 2 */
  prod_n *= xi - x[i - r + 3];	/* n = 3 */
  prod_n *= xi - x[i - r + 5];	/* n = 5 */
  prod_n *= xi - x[i - r + 7];	/* n = 7 */
  prod_n *= xi - x[i - r + 8];	/* n = 8 */
  sum_m += prod_n;

  /* m = 7 */
  prod_n = 1.0;
  prod_n *= xi - x[i - r + 0];	/* n = 0 */
  prod_n *= xi - x[i - r + 1];	/* n = 1 */
  prod_n *= xi - x[i - r + 2];	/* n = 2 */
  prod_n *= xi - x[i - r + 3];	/* n = 3 */
  prod_n *= xi - x[i - r + 5];	/* n = 5 */
  prod_n *= xi - x[i - r + 6];	/* n = 6 */
  prod_n *= xi - x[i - r + 8];	/* n = 8 */
  sum_m += prod_n;

  /* m = 8 */
  prod_n = 1.0;
  prod_n *= xi - x[i - r + 0];	/* n = 0 */
  prod_n *= xi - x[i - r + 1];	/* n = 1 */
  prod_n *= xi - x[i - r + 2];	/* n = 2 */
  prod_n *= xi - x[i - r + 3];	/* n = 3 */
  prod_n *= xi - x[i - r + 5];	/* n = 5 */
  prod_n *= xi - x[i - r + 6];	/* n = 6 */
  prod_n *= xi - x[i - r + 7];	/* n = 7 */
  sum_m += prod_n;

  prod_m = 1.0;
  prod_m *= x[i - r + 4] - x[i - r + 0];
  prod_m *= x[i - r + 4] - x[i - r + 1];
  prod_m *= x[i - r + 4] - x[i - r + 2];
  prod_m *= x[i - r + 4] - x[i - r + 3];
  prod_m *= x[i - r + 4] - x[i - r + 5];
  prod_m *= x[i - r + 4] - x[i - r + 6];
  prod_m *= x[i - r + 4] - x[i - r + 7];
  prod_m *= x[i - r + 4] - x[i - r + 8];

  sum_l += sum_m / prod_m * (x[i - r + 0 + 1] - x[i - r + 0]);

  /* l = 5 */
  sum_m = 0.0;

  /* m = 0 */
  prod_n = 1.0;
  prod_n *= xi - x[i - r + 1];	/* n = 1 */
  prod_n *= xi - x[i - r + 2];	/* n = 2 */
  prod_n *= xi - x[i - r + 3];	/* n = 3 */
  prod_n *= xi - x[i - r + 4];	/* n = 4 */
  prod_n *= xi - x[i - r + 6];	/* n = 6 */
  prod_n *= xi - x[i - r + 7];	/* n = 7 */
  prod_n *= xi - x[i - r + 8];	/* n = 8 */
  sum_m += prod_n;

  /* m = 1 */
  prod_n = 1.0;
  prod_n *= xi - x[i - r + 0];	/* n = 0 */
  prod_n *= xi - x[i - r + 2];	/* n = 2 */
  prod_n *= xi - x[i - r + 3];	/* n = 3 */
  prod_n *= xi - x[i - r + 4];	/* n = 4 */
  prod_n *= xi - x[i - r + 6];	/* n = 6 */
  prod_n *= xi - x[i - r + 7];	/* n = 7 */
  prod_n *= xi - x[i - r + 8];	/* n = 8 */
  sum_m += prod_n;

  /* m = 2 */
  prod_n = 1.0;
  prod_n *= xi - x[i - r + 0];	/* n = 0 */
  prod_n *= xi - x[i - r + 1];	/* n = 1 */
  prod_n *= xi - x[i - r + 3];	/* n = 3 */
  prod_n *= xi - x[i - r + 4];	/* n = 4 */
  prod_n *= xi - x[i - r + 6];	/* n = 6 */
  prod_n *= xi - x[i - r + 7];	/* n = 7 */
  prod_n *= xi - x[i - r + 8];	/* n = 8 */
  sum_m += prod_n;

  /* m = 3 */
  prod_n = 1.0;
  prod_n *= xi - x[i - r + 0];	/* n = 0 */
  prod_n *= xi - x[i - r + 1];	/* n = 1 */
  prod_n *= xi - x[i - r + 2];	/* n = 2 */
  prod_n *= xi - x[i - r + 4];	/* n = 4 */
  prod_n *= xi - x[i - r + 6];	/* n = 6 */
  prod_n *= xi - x[i - r + 7];	/* n = 7 */
  prod_n *= xi - x[i - r + 8];	/* n = 8 */
  sum_m += prod_n;

  /* m = 4 */
  prod_n = 1.0;
  prod_n *= xi - x[i - r + 0];	/* n = 0 */
  prod_n *= xi - x[i - r + 1];	/* n = 1 */
  prod_n *= xi - x[i - r + 2];	/* n = 2 */
  prod_n *= xi - x[i - r + 3];	/* n = 3 */
  prod_n *= xi - x[i - r + 6];	/* n = 6 */
  prod_n *= xi - x[i - r + 7];	/* n = 7 */
  prod_n *= xi - x[i - r + 8];	/* n = 8 */
  sum_m += prod_n;

  /* m = 6 */
  prod_n = 1.0;
  prod_n *= xi - x[i - r + 0];	/* n = 0 */
  prod_n *= xi - x[i - r + 1];	/* n = 1 */
  prod_n *= xi - x[i - r + 2];	/* n = 2 */
  prod_n *= xi - x[i - r + 3];	/* n = 3 */
  prod_n *= xi - x[i - r + 4];	/* n = 4 */
  prod_n *= xi - x[i - r + 7];	/* n = 7 */
  prod_n *= xi - x[i - r + 8];	/* n = 8 */
  sum_m += prod_n;

  /* m = 7 */
  prod_n = 1.0;
  prod_n *= xi - x[i - r + 0];	/* n = 0 */
  prod_n *= xi - x[i - r + 1];	/* n = 1 */
  prod_n *= xi - x[i - r + 2];	/* n = 2 */
  prod_n *= xi - x[i - r + 3];	/* n = 3 */
  prod_n *= xi - x[i - r + 4];	/* n = 4 */
  prod_n *= xi - x[i - r + 6];	/* n = 6 */
  prod_n *= xi - x[i - r + 8];	/* n = 8 */
  sum_m += prod_n;

  /* m = 8 */
  prod_n = 1.0;
  prod_n *= xi - x[i - r + 0];	/* n = 0 */
  prod_n *= xi - x[i - r + 1];	/* n = 1 */
  prod_n *= xi - x[i - r + 2];	/* n = 2 */
  prod_n *= xi - x[i - r + 3];	/* n = 3 */
  prod_n *= xi - x[i - r + 4];	/* n = 4 */
  prod_n *= xi - x[i - r + 6];	/* n = 6 */
  prod_n *= xi - x[i - r + 7];	/* n = 7 */
  sum_m += prod_n;

  prod_m = 1.0;
  prod_m *= x[i - r + 5] - x[i - r + 0];
  prod_m *= x[i - r + 5] - x[i - r + 1];
  prod_m *= x[i - r + 5] - x[i - r + 2];
  prod_m *= x[i - r + 5] - x[i - r + 3];
  prod_m *= x[i - r + 5] - x[i - r + 4];
  prod_m *= x[i - r + 5] - x[i - r + 6];
  prod_m *= x[i - r + 5] - x[i - r + 7];
  prod_m *= x[i - r + 5] - x[i - r + 8];

  sum_l += sum_m / prod_m * (x[i - r + 0 + 1] - x[i - r + 0]);

  /* l = 6 */
  sum_m = 0.0;

  /* m = 0 */
  prod_n = 1.0;
  prod_n *= xi - x[i - r + 1];	/* n = 1 */
  prod_n *= xi - x[i - r + 2];	/* n = 2 */
  prod_n *= xi - x[i - r + 3];	/* n = 3 */
  prod_n *= xi - x[i - r + 4];	/* n = 4 */
  prod_n *= xi - x[i - r + 5];	/* n = 5 */
  prod_n *= xi - x[i - r + 7];	/* n = 7 */
  prod_n *= xi - x[i - r + 8];	/* n = 8 */
  sum_m += prod_n;

  /* m = 1 */
  prod_n = 1.0;
  prod_n *= xi - x[i - r + 0];	/* n = 0 */
  prod_n *= xi - x[i - r + 2];	/* n = 2 */
  prod_n *= xi - x[i - r + 3];	/* n = 3 */
  prod_n *= xi - x[i - r + 4];	/* n = 4 */
  prod_n *= xi - x[i - r + 5];	/* n = 5 */
  prod_n *= xi - x[i - r + 7];	/* n = 7 */
  prod_n *= xi - x[i - r + 8];	/* n = 8 */
  sum_m += prod_n;

  /* m = 2 */
  prod_n = 1.0;
  prod_n *= xi - x[i - r + 0];	/* n = 0 */
  prod_n *= xi - x[i - r + 1];	/* n = 1 */
  prod_n *= xi - x[i - r + 3];	/* n = 3 */
  prod_n *= xi - x[i - r + 4];	/* n = 4 */
  prod_n *= xi - x[i - r + 5];	/* n = 5 */
  prod_n *= xi - x[i - r + 7];	/* n = 7 */
  prod_n *= xi - x[i - r + 8];	/* n = 8 */
  sum_m += prod_n;

  /* m = 3 */
  prod_n = 1.0;
  prod_n *= xi - x[i - r + 0];	/* n = 0 */
  prod_n *= xi - x[i - r + 1];	/* n = 1 */
  prod_n *= xi - x[i - r + 2];	/* n = 2 */
  prod_n *= xi - x[i - r + 4];	/* n = 4 */
  prod_n *= xi - x[i - r + 5];	/* n = 5 */
  prod_n *= xi - x[i - r + 7];	/* n = 7 */
  prod_n *= xi - x[i - r + 8];	/* n = 8 */
  sum_m += prod_n;

  /* m = 4 */
  prod_n = 1.0;
  prod_n *= xi - x[i - r + 0];	/* n = 0 */
  prod_n *= xi - x[i - r + 1];	/* n = 1 */
  prod_n *= xi - x[i - r + 2];	/* n = 2 */
  prod_n *= xi - x[i - r + 3];	/* n = 3 */
  prod_n *= xi - x[i - r + 5];	/* n = 5 */
  prod_n *= xi - x[i - r + 7];	/* n = 7 */
  prod_n *= xi - x[i - r + 8];	/* n = 8 */
  sum_m += prod_n;

  /* m = 5 */
  prod_n = 1.0;
  prod_n *= xi - x[i - r + 0];	/* n = 0 */
  prod_n *= xi - x[i - r + 1];	/* n = 1 */
  prod_n *= xi - x[i - r + 2];	/* n = 2 */
  prod_n *= xi - x[i - r + 3];	/* n = 3 */
  prod_n *= xi - x[i - r + 4];	/* n = 4 */
  prod_n *= xi - x[i - r + 7];	/* n = 7 */
  prod_n *= xi - x[i - r + 8];	/* n = 8 */
  sum_m += prod_n;

  /* m = 7 */
  prod_n = 1.0;
  prod_n *= xi - x[i - r + 0];	/* n = 0 */
  prod_n *= xi - x[i - r + 1];	/* n = 1 */
  prod_n *= xi - x[i - r + 2];	/* n = 2 */
  prod_n *= xi - x[i - r + 3];	/* n = 3 */
  prod_n *= xi - x[i - r + 4];	/* n = 4 */
  prod_n *= xi - x[i - r + 5];	/* n = 5 */
  prod_n *= xi - x[i - r + 8];	/* n = 8 */
  sum_m += prod_n;

  /* m = 8 */
  prod_n = 1.0;
  prod_n *= xi - x[i - r + 0];	/* n = 0 */
  prod_n *= xi - x[i - r + 1];	/* n = 1 */
  prod_n *= xi - x[i - r + 2];	/* n = 2 */
  prod_n *= xi - x[i - r + 3];	/* n = 3 */
  prod_n *= xi - x[i - r + 4];	/* n = 4 */
  prod_n *= xi - x[i - r + 5];	/* n = 5 */
  prod_n *= xi - x[i - r + 7];	/* n = 7 */
  sum_m += prod_n;

  prod_m = 1.0;
  prod_m *= x[i - r + 6] - x[i - r + 0];
  prod_m *= x[i - r + 6] - x[i - r + 1];
  prod_m *= x[i - r + 6] - x[i - r + 2];
  prod_m *= x[i - r + 6] - x[i - r + 3];
  prod_m *= x[i - r + 6] - x[i - r + 4];
  prod_m *= x[i - r + 6] - x[i - r + 5];
  prod_m *= x[i - r + 6] - x[i - r + 7];
  prod_m *= x[i - r + 6] - x[i - r + 8];

  sum_l += sum_m / prod_m * (x[i - r + 0 + 1] - x[i - r + 0]);

  /* l = 7 */
  sum_m = 0.0;

  /* m = 0 */
  prod_n = 1.0;
  prod_n *= xi - x[i - r + 1];	/* n = 1 */
  prod_n *= xi - x[i - r + 2];	/* n = 2 */
  prod_n *= xi - x[i - r + 3];	/* n = 3 */
  prod_n *= xi - x[i - r + 4];	/* n = 4 */
  prod_n *= xi - x[i - r + 5];	/* n = 5 */
  prod_n *= xi - x[i - r + 6];	/* n = 6 */
  prod_n *= xi - x[i - r + 8];	/* n = 8 */
  sum_m += prod_n;

  /* m = 1 */
  prod_n = 1.0;
  prod_n *= xi - x[i - r + 0];	/* n = 0 */
  prod_n *= xi - x[i - r + 2];	/* n = 2 */
  prod_n *= xi - x[i - r + 3];	/* n = 3 */
  prod_n *= xi - x[i - r + 4];	/* n = 4 */
  prod_n *= xi - x[i - r + 5];	/* n = 5 */
  prod_n *= xi - x[i - r + 6];	/* n = 6 */
  prod_n *= xi - x[i - r + 8];	/* n = 8 */
  sum_m += prod_n;

  /* m = 2 */
  prod_n = 1.0;
  prod_n *= xi - x[i - r + 0];	/* n = 0 */
  prod_n *= xi - x[i - r + 1];	/* n = 1 */
  prod_n *= xi - x[i - r + 3];	/* n = 3 */
  prod_n *= xi - x[i - r + 4];	/* n = 4 */
  prod_n *= xi - x[i - r + 5];	/* n = 5 */
  prod_n *= xi - x[i - r + 6];	/* n = 6 */
  prod_n *= xi - x[i - r + 8];	/* n = 8 */
  sum_m += prod_n;

  /* m = 3 */
  prod_n = 1.0;
  prod_n *= xi - x[i - r + 0];	/* n = 0 */
  prod_n *= xi - x[i - r + 1];	/* n = 1 */
  prod_n *= xi - x[i - r + 2];	/* n = 2 */
  prod_n *= xi - x[i - r + 4];	/* n = 4 */
  prod_n *= xi - x[i - r + 5];	/* n = 5 */
  prod_n *= xi - x[i - r + 6];	/* n = 6 */
  prod_n *= xi - x[i - r + 8];	/* n = 8 */
  sum_m += prod_n;

  /* m = 4 */
  prod_n = 1.0;
  prod_n *= xi - x[i - r + 0];	/* n = 0 */
  prod_n *= xi - x[i - r + 1];	/* n = 1 */
  prod_n *= xi - x[i - r + 2];	/* n = 2 */
  prod_n *= xi - x[i - r + 3];	/* n = 3 */
  prod_n *= xi - x[i - r + 5];	/* n = 5 */
  prod_n *= xi - x[i - r + 6];	/* n = 6 */
  prod_n *= xi - x[i - r + 8];	/* n = 8 */
  sum_m += prod_n;

  /* m = 5 */
  prod_n = 1.0;
  prod_n *= xi - x[i - r + 0];	/* n = 0 */
  prod_n *= xi - x[i - r + 1];	/* n = 1 */
  prod_n *= xi - x[i - r + 2];	/* n = 2 */
  prod_n *= xi - x[i - r + 3];	/* n = 3 */
  prod_n *= xi - x[i - r + 4];	/* n = 4 */
  prod_n *= xi - x[i - r + 6];	/* n = 6 */
  prod_n *= xi - x[i - r + 8];	/* n = 8 */
  sum_m += prod_n;

  /* m = 6 */
  prod_n = 1.0;
  prod_n *= xi - x[i - r + 0];	/* n = 0 */
  prod_n *= xi - x[i - r + 1];	/* n = 1 */
  prod_n *= xi - x[i - r + 2];	/* n = 2 */
  prod_n *= xi - x[i - r + 3];	/* n = 3 */
  prod_n *= xi - x[i - r + 4];	/* n = 4 */
  prod_n *= xi - x[i - r + 5];	/* n = 5 */
  prod_n *= xi - x[i - r + 8];	/* n = 8 */
  sum_m += prod_n;

  /* m = 8 */
  prod_n = 1.0;
  prod_n *= xi - x[i - r + 0];	/* n = 0 */
  prod_n *= xi - x[i - r + 1];	/* n = 1 */
  prod_n *= xi - x[i - r + 2];	/* n = 2 */
  prod_n *= xi - x[i - r + 3];	/* n = 3 */
  prod_n *= xi - x[i - r + 4];	/* n = 4 */
  prod_n *= xi - x[i - r + 5];	/* n = 5 */
  prod_n *= xi - x[i - r + 6];	/* n = 6 */
  sum_m += prod_n;

  prod_m = 1.0;
  prod_m *= x[i - r + 7] - x[i - r + 0];
  prod_m *= x[i - r + 7] - x[i - r + 1];
  prod_m *= x[i - r + 7] - x[i - r + 2];
  prod_m *= x[i - r + 7] - x[i - r + 3];
  prod_m *= x[i - r + 7] - x[i - r + 4];
  prod_m *= x[i - r + 7] - x[i - r + 5];
  prod_m *= x[i - r + 7] - x[i - r + 6];
  prod_m *= x[i - r + 7] - x[i - r + 8];

  sum_l += sum_m / prod_m * (x[i - r + 0 + 1] - x[i - r + 0]);

  /* l = 8 */
  sum_m = 0.0;

  /* m = 0 */
  prod_n = 1.0;
  prod_n *= xi - x[i - r + 1];	/* n = 1 */
  prod_n *= xi - x[i - r + 2];	/* n = 2 */
  prod_n *= xi - x[i - r + 3];	/* n = 3 */
  prod_n *= xi - x[i - r + 4];	/* n = 4 */
  prod_n *= xi - x[i - r + 5];	/* n = 5 */
  prod_n *= xi - x[i - r + 6];	/* n = 6 */
  prod_n *= xi - x[i - r + 7];	/* n = 7 */
  sum_m += prod_n;

  /* m = 1 */
  prod_n = 1.0;
  prod_n *= xi - x[i - r + 0];	/* n = 0 */
  prod_n *= xi - x[i - r + 2];	/* n = 2 */
  prod_n *= xi - x[i - r + 3];	/* n = 3 */
  prod_n *= xi - x[i - r + 4];	/* n = 4 */
  prod_n *= xi - x[i - r + 5];	/* n = 5 */
  prod_n *= xi - x[i - r + 6];	/* n = 6 */
  prod_n *= xi - x[i - r + 7];	/* n = 7 */
  sum_m += prod_n;

  /* m = 2 */
  prod_n = 1.0;
  prod_n *= xi - x[i - r + 0];	/* n = 0 */
  prod_n *= xi - x[i - r + 1];	/* n = 1 */
  prod_n *= xi - x[i - r + 3];	/* n = 3 */
  prod_n *= xi - x[i - r + 4];	/* n = 4 */
  prod_n *= xi - x[i - r + 5];	/* n = 5 */
  prod_n *= xi - x[i - r + 6];	/* n = 6 */
  prod_n *= xi - x[i - r + 7];	/* n = 7 */
  sum_m += prod_n;

  /* m = 3 */
  prod_n = 1.0;
  prod_n *= xi - x[i - r + 0];	/* n = 0 */
  prod_n *= xi - x[i - r + 1];	/* n = 1 */
  prod_n *= xi - x[i - r + 2];	/* n = 2 */
  prod_n *= xi - x[i - r + 4];	/* n = 4 */
  prod_n *= xi - x[i - r + 5];	/* n = 5 */
  prod_n *= xi - x[i - r + 6];	/* n = 6 */
  prod_n *= xi - x[i - r + 7];	/* n = 7 */
  sum_m += prod_n;

  /* m = 4 */
  prod_n = 1.0;
  prod_n *= xi - x[i - r + 0];	/* n = 0 */
  prod_n *= xi - x[i - r + 1];	/* n = 1 */
  prod_n *= xi - x[i - r + 2];	/* n = 2 */
  prod_n *= xi - x[i - r + 3];	/* n = 3 */
  prod_n *= xi - x[i - r + 5];	/* n = 5 */
  prod_n *= xi - x[i - r + 6];	/* n = 6 */
  prod_n *= xi - x[i - r + 7];	/* n = 7 */
  sum_m += prod_n;

  /* m = 5 */
  prod_n = 1.0;
  prod_n *= xi - x[i - r + 0];	/* n = 0 */
  prod_n *= xi - x[i - r + 1];	/* n = 1 */
  prod_n *= xi - x[i - r + 2];	/* n = 2 */
  prod_n *= xi - x[i - r + 3];	/* n = 3 */
  prod_n *= xi - x[i - r + 4];	/* n = 4 */
  prod_n *= xi - x[i - r + 6];	/* n = 6 */
  prod_n *= xi - x[i - r + 7];	/* n = 7 */
  sum_m += prod_n;

  /* m = 6 */
  prod_n = 1.0;
  prod_n *= xi - x[i - r + 0];	/* n = 0 */
  prod_n *= xi - x[i - r + 1];	/* n = 1 */
  prod_n *= xi - x[i - r + 2];	/* n = 2 */
  prod_n *= xi - x[i - r + 3];	/* n = 3 */
  prod_n *= xi - x[i - r + 4];	/* n = 4 */
  prod_n *= xi - x[i - r + 5];	/* n = 5 */
  prod_n *= xi - x[i - r + 7];	/* n = 7 */
  sum_m += prod_n;

  /* m = 7 */
  prod_n = 1.0;
  prod_n *= xi - x[i - r + 0];	/* n = 0 */
  prod_n *= xi - x[i - r + 1];	/* n = 1 */
  prod_n *= xi - x[i - r + 2];	/* n = 2 */
  prod_n *= xi - x[i - r + 3];	/* n = 3 */
  prod_n *= xi - x[i - r + 4];	/* n = 4 */
  prod_n *= xi - x[i - r + 5];	/* n = 5 */
  prod_n *= xi - x[i - r + 6];	/* n = 6 */
  sum_m += prod_n;

  prod_m = 1.0;
  prod_m *= x[i - r + 8] - x[i - r + 0];
  prod_m *= x[i - r + 8] - x[i - r + 1];
  prod_m *= x[i - r + 8] - x[i - r + 2];
  prod_m *= x[i - r + 8] - x[i - r + 3];
  prod_m *= x[i - r + 8] - x[i - r + 4];
  prod_m *= x[i - r + 8] - x[i - r + 5];
  prod_m *= x[i - r + 8] - x[i - r + 6];
  prod_m *= x[i - r + 8] - x[i - r + 7];

  sum_l += sum_m / prod_m * (x[i - r + 0 + 1] - x[i - r + 0]);

  c[0] = sum_l;
  /* j = 1 */
  sum_l = 0.0;

  /* l = 2 */
  sum_m = 0.0;

  /* m = 0 */
  prod_n = 1.0;
  prod_n *= xi - x[i - r + 1];	/* n = 1 */
  prod_n *= xi - x[i - r + 3];	/* n = 3 */
  prod_n *= xi - x[i - r + 4];	/* n = 4 */
  prod_n *= xi - x[i - r + 5];	/* n = 5 */
  prod_n *= xi - x[i - r + 6];	/* n = 6 */
  prod_n *= xi - x[i - r + 7];	/* n = 7 */
  prod_n *= xi - x[i - r + 8];	/* n = 8 */
  sum_m += prod_n;

  /* m = 1 */
  prod_n = 1.0;
  prod_n *= xi - x[i - r + 0];	/* n = 0 */
  prod_n *= xi - x[i - r + 3];	/* n = 3 */
  prod_n *= xi - x[i - r + 4];	/* n = 4 */
  prod_n *= xi - x[i - r + 5];	/* n = 5 */
  prod_n *= xi - x[i - r + 6];	/* n = 6 */
  prod_n *= xi - x[i - r + 7];	/* n = 7 */
  prod_n *= xi - x[i - r + 8];	/* n = 8 */
  sum_m += prod_n;

  /* m = 3 */
  prod_n = 1.0;
  prod_n *= xi - x[i - r + 0];	/* n = 0 */
  prod_n *= xi - x[i - r + 1];	/* n = 1 */
  prod_n *= xi - x[i - r + 4];	/* n = 4 */
  prod_n *= xi - x[i - r + 5];	/* n = 5 */
  prod_n *= xi - x[i - r + 6];	/* n = 6 */
  prod_n *= xi - x[i - r + 7];	/* n = 7 */
  prod_n *= xi - x[i - r + 8];	/* n = 8 */
  sum_m += prod_n;

  /* m = 4 */
  prod_n = 1.0;
  prod_n *= xi - x[i - r + 0];	/* n = 0 */
  prod_n *= xi - x[i - r + 1];	/* n = 1 */
  prod_n *= xi - x[i - r + 3];	/* n = 3 */
  prod_n *= xi - x[i - r + 5];	/* n = 5 */
  prod_n *= xi - x[i - r + 6];	/* n = 6 */
  prod_n *= xi - x[i - r + 7];	/* n = 7 */
  prod_n *= xi - x[i - r + 8];	/* n = 8 */
  sum_m += prod_n;

  /* m = 5 */
  prod_n = 1.0;
  prod_n *= xi - x[i - r + 0];	/* n = 0 */
  prod_n *= xi - x[i - r + 1];	/* n = 1 */
  prod_n *= xi - x[i - r + 3];	/* n = 3 */
  prod_n *= xi - x[i - r + 4];	/* n = 4 */
  prod_n *= xi - x[i - r + 6];	/* n = 6 */
  prod_n *= xi - x[i - r + 7];	/* n = 7 */
  prod_n *= xi - x[i - r + 8];	/* n = 8 */
  sum_m += prod_n;

  /* m = 6 */
  prod_n = 1.0;
  prod_n *= xi - x[i - r + 0];	/* n = 0 */
  prod_n *= xi - x[i - r + 1];	/* n = 1 */
  prod_n *= xi - x[i - r + 3];	/* n = 3 */
  prod_n *= xi - x[i - r + 4];	/* n = 4 */
  prod_n *= xi - x[i - r + 5];	/* n = 5 */
  prod_n *= xi - x[i - r + 7];	/* n = 7 */
  prod_n *= xi - x[i - r + 8];	/* n = 8 */
  sum_m += prod_n;

  /* m = 7 */
  prod_n = 1.0;
  prod_n *= xi - x[i - r + 0];	/* n = 0 */
  prod_n *= xi - x[i - r + 1];	/* n = 1 */
  prod_n *= xi - x[i - r + 3];	/* n = 3 */
  prod_n *= xi - x[i - r + 4];	/* n = 4 */
  prod_n *= xi - x[i - r + 5];	/* n = 5 */
  prod_n *= xi - x[i - r + 6];	/* n = 6 */
  prod_n *= xi - x[i - r + 8];	/* n = 8 */
  sum_m += prod_n;

  /* m = 8 */
  prod_n = 1.0;
  prod_n *= xi - x[i - r + 0];	/* n = 0 */
  prod_n *= xi - x[i - r + 1];	/* n = 1 */
  prod_n *= xi - x[i - r + 3];	/* n = 3 */
  prod_n *= xi - x[i - r + 4];	/* n = 4 */
  prod_n *= xi - x[i - r + 5];	/* n = 5 */
  prod_n *= xi - x[i - r + 6];	/* n = 6 */
  prod_n *= xi - x[i - r + 7];	/* n = 7 */
  sum_m += prod_n;

  prod_m = 1.0;
  prod_m *= x[i - r + 2] - x[i - r + 0];
  prod_m *= x[i - r + 2] - x[i - r + 1];
  prod_m *= x[i - r + 2] - x[i - r + 3];
  prod_m *= x[i - r + 2] - x[i - r + 4];
  prod_m *= x[i - r + 2] - x[i - r + 5];
  prod_m *= x[i - r + 2] - x[i - r + 6];
  prod_m *= x[i - r + 2] - x[i - r + 7];
  prod_m *= x[i - r + 2] - x[i - r + 8];

  sum_l += sum_m / prod_m * (x[i - r + 1 + 1] - x[i - r + 1]);

  /* l = 3 */
  sum_m = 0.0;

  /* m = 0 */
  prod_n = 1.0;
  prod_n *= xi - x[i - r + 1];	/* n = 1 */
  prod_n *= xi - x[i - r + 2];	/* n = 2 */
  prod_n *= xi - x[i - r + 4];	/* n = 4 */
  prod_n *= xi - x[i - r + 5];	/* n = 5 */
  prod_n *= xi - x[i - r + 6];	/* n = 6 */
  prod_n *= xi - x[i - r + 7];	/* n = 7 */
  prod_n *= xi - x[i - r + 8];	/* n = 8 */
  sum_m += prod_n;

  /* m = 1 */
  prod_n = 1.0;
  prod_n *= xi - x[i - r + 0];	/* n = 0 */
  prod_n *= xi - x[i - r + 2];	/* n = 2 */
  prod_n *= xi - x[i - r + 4];	/* n = 4 */
  prod_n *= xi - x[i - r + 5];	/* n = 5 */
  prod_n *= xi - x[i - r + 6];	/* n = 6 */
  prod_n *= xi - x[i - r + 7];	/* n = 7 */
  prod_n *= xi - x[i - r + 8];	/* n = 8 */
  sum_m += prod_n;

  /* m = 2 */
  prod_n = 1.0;
  prod_n *= xi - x[i - r + 0];	/* n = 0 */
  prod_n *= xi - x[i - r + 1];	/* n = 1 */
  prod_n *= xi - x[i - r + 4];	/* n = 4 */
  prod_n *= xi - x[i - r + 5];	/* n = 5 */
  prod_n *= xi - x[i - r + 6];	/* n = 6 */
  prod_n *= xi - x[i - r + 7];	/* n = 7 */
  prod_n *= xi - x[i - r + 8];	/* n = 8 */
  sum_m += prod_n;

  /* m = 4 */
  prod_n = 1.0;
  prod_n *= xi - x[i - r + 0];	/* n = 0 */
  prod_n *= xi - x[i - r + 1];	/* n = 1 */
  prod_n *= xi - x[i - r + 2];	/* n = 2 */
  prod_n *= xi - x[i - r + 5];	/* n = 5 */
  prod_n *= xi - x[i - r + 6];	/* n = 6 */
  prod_n *= xi - x[i - r + 7];	/* n = 7 */
  prod_n *= xi - x[i - r + 8];	/* n = 8 */
  sum_m += prod_n;

  /* m = 5 */
  prod_n = 1.0;
  prod_n *= xi - x[i - r + 0];	/* n = 0 */
  prod_n *= xi - x[i - r + 1];	/* n = 1 */
  prod_n *= xi - x[i - r + 2];	/* n = 2 */
  prod_n *= xi - x[i - r + 4];	/* n = 4 */
  prod_n *= xi - x[i - r + 6];	/* n = 6 */
  prod_n *= xi - x[i - r + 7];	/* n = 7 */
  prod_n *= xi - x[i - r + 8];	/* n = 8 */
  sum_m += prod_n;

  /* m = 6 */
  prod_n = 1.0;
  prod_n *= xi - x[i - r + 0];	/* n = 0 */
  prod_n *= xi - x[i - r + 1];	/* n = 1 */
  prod_n *= xi - x[i - r + 2];	/* n = 2 */
  prod_n *= xi - x[i - r + 4];	/* n = 4 */
  prod_n *= xi - x[i - r + 5];	/* n = 5 */
  prod_n *= xi - x[i - r + 7];	/* n = 7 */
  prod_n *= xi - x[i - r + 8];	/* n = 8 */
  sum_m += prod_n;

  /* m = 7 */
  prod_n = 1.0;
  prod_n *= xi - x[i - r + 0];	/* n = 0 */
  prod_n *= xi - x[i - r + 1];	/* n = 1 */
  prod_n *= xi - x[i - r + 2];	/* n = 2 */
  prod_n *= xi - x[i - r + 4];	/* n = 4 */
  prod_n *= xi - x[i - r + 5];	/* n = 5 */
  prod_n *= xi - x[i - r + 6];	/* n = 6 */
  prod_n *= xi - x[i - r + 8];	/* n = 8 */
  sum_m += prod_n;

  /* m = 8 */
  prod_n = 1.0;
  prod_n *= xi - x[i - r + 0];	/* n = 0 */
  prod_n *= xi - x[i - r + 1];	/* n = 1 */
  prod_n *= xi - x[i - r + 2];	/* n = 2 */
  prod_n *= xi - x[i - r + 4];	/* n = 4 */
  prod_n *= xi - x[i - r + 5];	/* n = 5 */
  prod_n *= xi - x[i - r + 6];	/* n = 6 */
  prod_n *= xi - x[i - r + 7];	/* n = 7 */
  sum_m += prod_n;

  prod_m = 1.0;
  prod_m *= x[i - r + 3] - x[i - r + 0];
  prod_m *= x[i - r + 3] - x[i - r + 1];
  prod_m *= x[i - r + 3] - x[i - r + 2];
  prod_m *= x[i - r + 3] - x[i - r + 4];
  prod_m *= x[i - r + 3] - x[i - r + 5];
  prod_m *= x[i - r + 3] - x[i - r + 6];
  prod_m *= x[i - r + 3] - x[i - r + 7];
  prod_m *= x[i - r + 3] - x[i - r + 8];

  sum_l += sum_m / prod_m * (x[i - r + 1 + 1] - x[i - r + 1]);

  /* l = 4 */
  sum_m = 0.0;

  /* m = 0 */
  prod_n = 1.0;
  prod_n *= xi - x[i - r + 1];	/* n = 1 */
  prod_n *= xi - x[i - r + 2];	/* n = 2 */
  prod_n *= xi - x[i - r + 3];	/* n = 3 */
  prod_n *= xi - x[i - r + 5];	/* n = 5 */
  prod_n *= xi - x[i - r + 6];	/* n = 6 */
  prod_n *= xi - x[i - r + 7];	/* n = 7 */
  prod_n *= xi - x[i - r + 8];	/* n = 8 */
  sum_m += prod_n;

  /* m = 1 */
  prod_n = 1.0;
  prod_n *= xi - x[i - r + 0];	/* n = 0 */
  prod_n *= xi - x[i - r + 2];	/* n = 2 */
  prod_n *= xi - x[i - r + 3];	/* n = 3 */
  prod_n *= xi - x[i - r + 5];	/* n = 5 */
  prod_n *= xi - x[i - r + 6];	/* n = 6 */
  prod_n *= xi - x[i - r + 7];	/* n = 7 */
  prod_n *= xi - x[i - r + 8];	/* n = 8 */
  sum_m += prod_n;

  /* m = 2 */
  prod_n = 1.0;
  prod_n *= xi - x[i - r + 0];	/* n = 0 */
  prod_n *= xi - x[i - r + 1];	/* n = 1 */
  prod_n *= xi - x[i - r + 3];	/* n = 3 */
  prod_n *= xi - x[i - r + 5];	/* n = 5 */
  prod_n *= xi - x[i - r + 6];	/* n = 6 */
  prod_n *= xi - x[i - r + 7];	/* n = 7 */
  prod_n *= xi - x[i - r + 8];	/* n = 8 */
  sum_m += prod_n;

  /* m = 3 */
  prod_n = 1.0;
  prod_n *= xi - x[i - r + 0];	/* n = 0 */
  prod_n *= xi - x[i - r + 1];	/* n = 1 */
  prod_n *= xi - x[i - r + 2];	/* n = 2 */
  prod_n *= xi - x[i - r + 5];	/* n = 5 */
  prod_n *= xi - x[i - r + 6];	/* n = 6 */
  prod_n *= xi - x[i - r + 7];	/* n = 7 */
  prod_n *= xi - x[i - r + 8];	/* n = 8 */
  sum_m += prod_n;

  /* m = 5 */
  prod_n = 1.0;
  prod_n *= xi - x[i - r + 0];	/* n = 0 */
  prod_n *= xi - x[i - r + 1];	/* n = 1 */
  prod_n *= xi - x[i - r + 2];	/* n = 2 */
  prod_n *= xi - x[i - r + 3];	/* n = 3 */
  prod_n *= xi - x[i - r + 6];	/* n = 6 */
  prod_n *= xi - x[i - r + 7];	/* n = 7 */
  prod_n *= xi - x[i - r + 8];	/* n = 8 */
  sum_m += prod_n;

  /* m = 6 */
  prod_n = 1.0;
  prod_n *= xi - x[i - r + 0];	/* n = 0 */
  prod_n *= xi - x[i - r + 1];	/* n = 1 */
  prod_n *= xi - x[i - r + 2];	/* n = 2 */
  prod_n *= xi - x[i - r + 3];	/* n = 3 */
  prod_n *= xi - x[i - r + 5];	/* n = 5 */
  prod_n *= xi - x[i - r + 7];	/* n = 7 */
  prod_n *= xi - x[i - r + 8];	/* n = 8 */
  sum_m += prod_n;

  /* m = 7 */
  prod_n = 1.0;
  prod_n *= xi - x[i - r + 0];	/* n = 0 */
  prod_n *= xi - x[i - r + 1];	/* n = 1 */
  prod_n *= xi - x[i - r + 2];	/* n = 2 */
  prod_n *= xi - x[i - r + 3];	/* n = 3 */
  prod_n *= xi - x[i - r + 5];	/* n = 5 */
  prod_n *= xi - x[i - r + 6];	/* n = 6 */
  prod_n *= xi - x[i - r + 8];	/* n = 8 */
  sum_m += prod_n;

  /* m = 8 */
  prod_n = 1.0;
  prod_n *= xi - x[i - r + 0];	/* n = 0 */
  prod_n *= xi - x[i - r + 1];	/* n = 1 */
  prod_n *= xi - x[i - r + 2];	/* n = 2 */
  prod_n *= xi - x[i - r + 3];	/* n = 3 */
  prod_n *= xi - x[i - r + 5];	/* n = 5 */
  prod_n *= xi - x[i - r + 6];	/* n = 6 */
  prod_n *= xi - x[i - r + 7];	/* n = 7 */
  sum_m += prod_n;

  prod_m = 1.0;
  prod_m *= x[i - r + 4] - x[i - r + 0];
  prod_m *= x[i - r + 4] - x[i - r + 1];
  prod_m *= x[i - r + 4] - x[i - r + 2];
  prod_m *= x[i - r + 4] - x[i - r + 3];
  prod_m *= x[i - r + 4] - x[i - r + 5];
  prod_m *= x[i - r + 4] - x[i - r + 6];
  prod_m *= x[i - r + 4] - x[i - r + 7];
  prod_m *= x[i - r + 4] - x[i - r + 8];

  sum_l += sum_m / prod_m * (x[i - r + 1 + 1] - x[i - r + 1]);

  /* l = 5 */
  sum_m = 0.0;

  /* m = 0 */
  prod_n = 1.0;
  prod_n *= xi - x[i - r + 1];	/* n = 1 */
  prod_n *= xi - x[i - r + 2];	/* n = 2 */
  prod_n *= xi - x[i - r + 3];	/* n = 3 */
  prod_n *= xi - x[i - r + 4];	/* n = 4 */
  prod_n *= xi - x[i - r + 6];	/* n = 6 */
  prod_n *= xi - x[i - r + 7];	/* n = 7 */
  prod_n *= xi - x[i - r + 8];	/* n = 8 */
  sum_m += prod_n;

  /* m = 1 */
  prod_n = 1.0;
  prod_n *= xi - x[i - r + 0];	/* n = 0 */
  prod_n *= xi - x[i - r + 2];	/* n = 2 */
  prod_n *= xi - x[i - r + 3];	/* n = 3 */
  prod_n *= xi - x[i - r + 4];	/* n = 4 */
  prod_n *= xi - x[i - r + 6];	/* n = 6 */
  prod_n *= xi - x[i - r + 7];	/* n = 7 */
  prod_n *= xi - x[i - r + 8];	/* n = 8 */
  sum_m += prod_n;

  /* m = 2 */
  prod_n = 1.0;
  prod_n *= xi - x[i - r + 0];	/* n = 0 */
  prod_n *= xi - x[i - r + 1];	/* n = 1 */
  prod_n *= xi - x[i - r + 3];	/* n = 3 */
  prod_n *= xi - x[i - r + 4];	/* n = 4 */
  prod_n *= xi - x[i - r + 6];	/* n = 6 */
  prod_n *= xi - x[i - r + 7];	/* n = 7 */
  prod_n *= xi - x[i - r + 8];	/* n = 8 */
  sum_m += prod_n;

  /* m = 3 */
  prod_n = 1.0;
  prod_n *= xi - x[i - r + 0];	/* n = 0 */
  prod_n *= xi - x[i - r + 1];	/* n = 1 */
  prod_n *= xi - x[i - r + 2];	/* n = 2 */
  prod_n *= xi - x[i - r + 4];	/* n = 4 */
  prod_n *= xi - x[i - r + 6];	/* n = 6 */
  prod_n *= xi - x[i - r + 7];	/* n = 7 */
  prod_n *= xi - x[i - r + 8];	/* n = 8 */
  sum_m += prod_n;

  /* m = 4 */
  prod_n = 1.0;
  prod_n *= xi - x[i - r + 0];	/* n = 0 */
  prod_n *= xi - x[i - r + 1];	/* n = 1 */
  prod_n *= xi - x[i - r + 2];	/* n = 2 */
  prod_n *= xi - x[i - r + 3];	/* n = 3 */
  prod_n *= xi - x[i - r + 6];	/* n = 6 */
  prod_n *= xi - x[i - r + 7];	/* n = 7 */
  prod_n *= xi - x[i - r + 8];	/* n = 8 */
  sum_m += prod_n;

  /* m = 6 */
  prod_n = 1.0;
  prod_n *= xi - x[i - r + 0];	/* n = 0 */
  prod_n *= xi - x[i - r + 1];	/* n = 1 */
  prod_n *= xi - x[i - r + 2];	/* n = 2 */
  prod_n *= xi - x[i - r + 3];	/* n = 3 */
  prod_n *= xi - x[i - r + 4];	/* n = 4 */
  prod_n *= xi - x[i - r + 7];	/* n = 7 */
  prod_n *= xi - x[i - r + 8];	/* n = 8 */
  sum_m += prod_n;

  /* m = 7 */
  prod_n = 1.0;
  prod_n *= xi - x[i - r + 0];	/* n = 0 */
  prod_n *= xi - x[i - r + 1];	/* n = 1 */
  prod_n *= xi - x[i - r + 2];	/* n = 2 */
  prod_n *= xi - x[i - r + 3];	/* n = 3 */
  prod_n *= xi - x[i - r + 4];	/* n = 4 */
  prod_n *= xi - x[i - r + 6];	/* n = 6 */
  prod_n *= xi - x[i - r + 8];	/* n = 8 */
  sum_m += prod_n;

  /* m = 8 */
  prod_n = 1.0;
  prod_n *= xi - x[i - r + 0];	/* n = 0 */
  prod_n *= xi - x[i - r + 1];	/* n = 1 */
  prod_n *= xi - x[i - r + 2];	/* n = 2 */
  prod_n *= xi - x[i - r + 3];	/* n = 3 */
  prod_n *= xi - x[i - r + 4];	/* n = 4 */
  prod_n *= xi - x[i - r + 6];	/* n = 6 */
  prod_n *= xi - x[i - r + 7];	/* n = 7 */
  sum_m += prod_n;

  prod_m = 1.0;
  prod_m *= x[i - r + 5] - x[i - r + 0];
  prod_m *= x[i - r + 5] - x[i - r + 1];
  prod_m *= x[i - r + 5] - x[i - r + 2];
  prod_m *= x[i - r + 5] - x[i - r + 3];
  prod_m *= x[i - r + 5] - x[i - r + 4];
  prod_m *= x[i - r + 5] - x[i - r + 6];
  prod_m *= x[i - r + 5] - x[i - r + 7];
  prod_m *= x[i - r + 5] - x[i - r + 8];

  sum_l += sum_m / prod_m * (x[i - r + 1 + 1] - x[i - r + 1]);

  /* l = 6 */
  sum_m = 0.0;

  /* m = 0 */
  prod_n = 1.0;
  prod_n *= xi - x[i - r + 1];	/* n = 1 */
  prod_n *= xi - x[i - r + 2];	/* n = 2 */
  prod_n *= xi - x[i - r + 3];	/* n = 3 */
  prod_n *= xi - x[i - r + 4];	/* n = 4 */
  prod_n *= xi - x[i - r + 5];	/* n = 5 */
  prod_n *= xi - x[i - r + 7];	/* n = 7 */
  prod_n *= xi - x[i - r + 8];	/* n = 8 */
  sum_m += prod_n;

  /* m = 1 */
  prod_n = 1.0;
  prod_n *= xi - x[i - r + 0];	/* n = 0 */
  prod_n *= xi - x[i - r + 2];	/* n = 2 */
  prod_n *= xi - x[i - r + 3];	/* n = 3 */
  prod_n *= xi - x[i - r + 4];	/* n = 4 */
  prod_n *= xi - x[i - r + 5];	/* n = 5 */
  prod_n *= xi - x[i - r + 7];	/* n = 7 */
  prod_n *= xi - x[i - r + 8];	/* n = 8 */
  sum_m += prod_n;

  /* m = 2 */
  prod_n = 1.0;
  prod_n *= xi - x[i - r + 0];	/* n = 0 */
  prod_n *= xi - x[i - r + 1];	/* n = 1 */
  prod_n *= xi - x[i - r + 3];	/* n = 3 */
  prod_n *= xi - x[i - r + 4];	/* n = 4 */
  prod_n *= xi - x[i - r + 5];	/* n = 5 */
  prod_n *= xi - x[i - r + 7];	/* n = 7 */
  prod_n *= xi - x[i - r + 8];	/* n = 8 */
  sum_m += prod_n;

  /* m = 3 */
  prod_n = 1.0;
  prod_n *= xi - x[i - r + 0];	/* n = 0 */
  prod_n *= xi - x[i - r + 1];	/* n = 1 */
  prod_n *= xi - x[i - r + 2];	/* n = 2 */
  prod_n *= xi - x[i - r + 4];	/* n = 4 */
  prod_n *= xi - x[i - r + 5];	/* n = 5 */
  prod_n *= xi - x[i - r + 7];	/* n = 7 */
  prod_n *= xi - x[i - r + 8];	/* n = 8 */
  sum_m += prod_n;

  /* m = 4 */
  prod_n = 1.0;
  prod_n *= xi - x[i - r + 0];	/* n = 0 */
  prod_n *= xi - x[i - r + 1];	/* n = 1 */
  prod_n *= xi - x[i - r + 2];	/* n = 2 */
  prod_n *= xi - x[i - r + 3];	/* n = 3 */
  prod_n *= xi - x[i - r + 5];	/* n = 5 */
  prod_n *= xi - x[i - r + 7];	/* n = 7 */
  prod_n *= xi - x[i - r + 8];	/* n = 8 */
  sum_m += prod_n;

  /* m = 5 */
  prod_n = 1.0;
  prod_n *= xi - x[i - r + 0];	/* n = 0 */
  prod_n *= xi - x[i - r + 1];	/* n = 1 */
  prod_n *= xi - x[i - r + 2];	/* n = 2 */
  prod_n *= xi - x[i - r + 3];	/* n = 3 */
  prod_n *= xi - x[i - r + 4];	/* n = 4 */
  prod_n *= xi - x[i - r + 7];	/* n = 7 */
  prod_n *= xi - x[i - r + 8];	/* n = 8 */
  sum_m += prod_n;

  /* m = 7 */
  prod_n = 1.0;
  prod_n *= xi - x[i - r + 0];	/* n = 0 */
  prod_n *= xi - x[i - r + 1];	/* n = 1 */
  prod_n *= xi - x[i - r + 2];	/* n = 2 */
  prod_n *= xi - x[i - r + 3];	/* n = 3 */
  prod_n *= xi - x[i - r + 4];	/* n = 4 */
  prod_n *= xi - x[i - r + 5];	/* n = 5 */
  prod_n *= xi - x[i - r + 8];	/* n = 8 */
  sum_m += prod_n;

  /* m = 8 */
  prod_n = 1.0;
  prod_n *= xi - x[i - r + 0];	/* n = 0 */
  prod_n *= xi - x[i - r + 1];	/* n = 1 */
  prod_n *= xi - x[i - r + 2];	/* n = 2 */
  prod_n *= xi - x[i - r + 3];	/* n = 3 */
  prod_n *= xi - x[i - r + 4];	/* n = 4 */
  prod_n *= xi - x[i - r + 5];	/* n = 5 */
  prod_n *= xi - x[i - r + 7];	/* n = 7 */
  sum_m += prod_n;

  prod_m = 1.0;
  prod_m *= x[i - r + 6] - x[i - r + 0];
  prod_m *= x[i - r + 6] - x[i - r + 1];
  prod_m *= x[i - r + 6] - x[i - r + 2];
  prod_m *= x[i - r + 6] - x[i - r + 3];
  prod_m *= x[i - r + 6] - x[i - r + 4];
  prod_m *= x[i - r + 6] - x[i - r + 5];
  prod_m *= x[i - r + 6] - x[i - r + 7];
  prod_m *= x[i - r + 6] - x[i - r + 8];

  sum_l += sum_m / prod_m * (x[i - r + 1 + 1] - x[i - r + 1]);

  /* l = 7 */
  sum_m = 0.0;

  /* m = 0 */
  prod_n = 1.0;
  prod_n *= xi - x[i - r + 1];	/* n = 1 */
  prod_n *= xi - x[i - r + 2];	/* n = 2 */
  prod_n *= xi - x[i - r + 3];	/* n = 3 */
  prod_n *= xi - x[i - r + 4];	/* n = 4 */
  prod_n *= xi - x[i - r + 5];	/* n = 5 */
  prod_n *= xi - x[i - r + 6];	/* n = 6 */
  prod_n *= xi - x[i - r + 8];	/* n = 8 */
  sum_m += prod_n;

  /* m = 1 */
  prod_n = 1.0;
  prod_n *= xi - x[i - r + 0];	/* n = 0 */
  prod_n *= xi - x[i - r + 2];	/* n = 2 */
  prod_n *= xi - x[i - r + 3];	/* n = 3 */
  prod_n *= xi - x[i - r + 4];	/* n = 4 */
  prod_n *= xi - x[i - r + 5];	/* n = 5 */
  prod_n *= xi - x[i - r + 6];	/* n = 6 */
  prod_n *= xi - x[i - r + 8];	/* n = 8 */
  sum_m += prod_n;

  /* m = 2 */
  prod_n = 1.0;
  prod_n *= xi - x[i - r + 0];	/* n = 0 */
  prod_n *= xi - x[i - r + 1];	/* n = 1 */
  prod_n *= xi - x[i - r + 3];	/* n = 3 */
  prod_n *= xi - x[i - r + 4];	/* n = 4 */
  prod_n *= xi - x[i - r + 5];	/* n = 5 */
  prod_n *= xi - x[i - r + 6];	/* n = 6 */
  prod_n *= xi - x[i - r + 8];	/* n = 8 */
  sum_m += prod_n;

  /* m = 3 */
  prod_n = 1.0;
  prod_n *= xi - x[i - r + 0];	/* n = 0 */
  prod_n *= xi - x[i - r + 1];	/* n = 1 */
  prod_n *= xi - x[i - r + 2];	/* n = 2 */
  prod_n *= xi - x[i - r + 4];	/* n = 4 */
  prod_n *= xi - x[i - r + 5];	/* n = 5 */
  prod_n *= xi - x[i - r + 6];	/* n = 6 */
  prod_n *= xi - x[i - r + 8];	/* n = 8 */
  sum_m += prod_n;

  /* m = 4 */
  prod_n = 1.0;
  prod_n *= xi - x[i - r + 0];	/* n = 0 */
  prod_n *= xi - x[i - r + 1];	/* n = 1 */
  prod_n *= xi - x[i - r + 2];	/* n = 2 */
  prod_n *= xi - x[i - r + 3];	/* n = 3 */
  prod_n *= xi - x[i - r + 5];	/* n = 5 */
  prod_n *= xi - x[i - r + 6];	/* n = 6 */
  prod_n *= xi - x[i - r + 8];	/* n = 8 */
  sum_m += prod_n;

  /* m = 5 */
  prod_n = 1.0;
  prod_n *= xi - x[i - r + 0];	/* n = 0 */
  prod_n *= xi - x[i - r + 1];	/* n = 1 */
  prod_n *= xi - x[i - r + 2];	/* n = 2 */
  prod_n *= xi - x[i - r + 3];	/* n = 3 */
  prod_n *= xi - x[i - r + 4];	/* n = 4 */
  prod_n *= xi - x[i - r + 6];	/* n = 6 */
  prod_n *= xi - x[i - r + 8];	/* n = 8 */
  sum_m += prod_n;

  /* m = 6 */
  prod_n = 1.0;
  prod_n *= xi - x[i - r + 0];	/* n = 0 */
  prod_n *= xi - x[i - r + 1];	/* n = 1 */
  prod_n *= xi - x[i - r + 2];	/* n = 2 */
  prod_n *= xi - x[i - r + 3];	/* n = 3 */
  prod_n *= xi - x[i - r + 4];	/* n = 4 */
  prod_n *= xi - x[i - r + 5];	/* n = 5 */
  prod_n *= xi - x[i - r + 8];	/* n = 8 */
  sum_m += prod_n;

  /* m = 8 */
  prod_n = 1.0;
  prod_n *= xi - x[i - r + 0];	/* n = 0 */
  prod_n *= xi - x[i - r + 1];	/* n = 1 */
  prod_n *= xi - x[i - r + 2];	/* n = 2 */
  prod_n *= xi - x[i - r + 3];	/* n = 3 */
  prod_n *= xi - x[i - r + 4];	/* n = 4 */
  prod_n *= xi - x[i - r + 5];	/* n = 5 */
  prod_n *= xi - x[i - r + 6];	/* n = 6 */
  sum_m += prod_n;

  prod_m = 1.0;
  prod_m *= x[i - r + 7] - x[i - r + 0];
  prod_m *= x[i - r + 7] - x[i - r + 1];
  prod_m *= x[i - r + 7] - x[i - r + 2];
  prod_m *= x[i - r + 7] - x[i - r + 3];
  prod_m *= x[i - r + 7] - x[i - r + 4];
  prod_m *= x[i - r + 7] - x[i - r + 5];
  prod_m *= x[i - r + 7] - x[i - r + 6];
  prod_m *= x[i - r + 7] - x[i - r + 8];

  sum_l += sum_m / prod_m * (x[i - r + 1 + 1] - x[i - r + 1]);

  /* l = 8 */
  sum_m = 0.0;

  /* m = 0 */
  prod_n = 1.0;
  prod_n *= xi - x[i - r + 1];	/* n = 1 */
  prod_n *= xi - x[i - r + 2];	/* n = 2 */
  prod_n *= xi - x[i - r + 3];	/* n = 3 */
  prod_n *= xi - x[i - r + 4];	/* n = 4 */
  prod_n *= xi - x[i - r + 5];	/* n = 5 */
  prod_n *= xi - x[i - r + 6];	/* n = 6 */
  prod_n *= xi - x[i - r + 7];	/* n = 7 */
  sum_m += prod_n;

  /* m = 1 */
  prod_n = 1.0;
  prod_n *= xi - x[i - r + 0];	/* n = 0 */
  prod_n *= xi - x[i - r + 2];	/* n = 2 */
  prod_n *= xi - x[i - r + 3];	/* n = 3 */
  prod_n *= xi - x[i - r + 4];	/* n = 4 */
  prod_n *= xi - x[i - r + 5];	/* n = 5 */
  prod_n *= xi - x[i - r + 6];	/* n = 6 */
  prod_n *= xi - x[i - r + 7];	/* n = 7 */
  sum_m += prod_n;

  /* m = 2 */
  prod_n = 1.0;
  prod_n *= xi - x[i - r + 0];	/* n = 0 */
  prod_n *= xi - x[i - r + 1];	/* n = 1 */
  prod_n *= xi - x[i - r + 3];	/* n = 3 */
  prod_n *= xi - x[i - r + 4];	/* n = 4 */
  prod_n *= xi - x[i - r + 5];	/* n = 5 */
  prod_n *= xi - x[i - r + 6];	/* n = 6 */
  prod_n *= xi - x[i - r + 7];	/* n = 7 */
  sum_m += prod_n;

  /* m = 3 */
  prod_n = 1.0;
  prod_n *= xi - x[i - r + 0];	/* n = 0 */
  prod_n *= xi - x[i - r + 1];	/* n = 1 */
  prod_n *= xi - x[i - r + 2];	/* n = 2 */
  prod_n *= xi - x[i - r + 4];	/* n = 4 */
  prod_n *= xi - x[i - r + 5];	/* n = 5 */
  prod_n *= xi - x[i - r + 6];	/* n = 6 */
  prod_n *= xi - x[i - r + 7];	/* n = 7 */
  sum_m += prod_n;

  /* m = 4 */
  prod_n = 1.0;
  prod_n *= xi - x[i - r + 0];	/* n = 0 */
  prod_n *= xi - x[i - r + 1];	/* n = 1 */
  prod_n *= xi - x[i - r + 2];	/* n = 2 */
  prod_n *= xi - x[i - r + 3];	/* n = 3 */
  prod_n *= xi - x[i - r + 5];	/* n = 5 */
  prod_n *= xi - x[i - r + 6];	/* n = 6 */
  prod_n *= xi - x[i - r + 7];	/* n = 7 */
  sum_m += prod_n;

  /* m = 5 */
  prod_n = 1.0;
  prod_n *= xi - x[i - r + 0];	/* n = 0 */
  prod_n *= xi - x[i - r + 1];	/* n = 1 */
  prod_n *= xi - x[i - r + 2];	/* n = 2 */
  prod_n *= xi - x[i - r + 3];	/* n = 3 */
  prod_n *= xi - x[i - r + 4];	/* n = 4 */
  prod_n *= xi - x[i - r + 6];	/* n = 6 */
  prod_n *= xi - x[i - r + 7];	/* n = 7 */
  sum_m += prod_n;

  /* m = 6 */
  prod_n = 1.0;
  prod_n *= xi - x[i - r + 0];	/* n = 0 */
  prod_n *= xi - x[i - r + 1];	/* n = 1 */
  prod_n *= xi - x[i - r + 2];	/* n = 2 */
  prod_n *= xi - x[i - r + 3];	/* n = 3 */
  prod_n *= xi - x[i - r + 4];	/* n = 4 */
  prod_n *= xi - x[i - r + 5];	/* n = 5 */
  prod_n *= xi - x[i - r + 7];	/* n = 7 */
  sum_m += prod_n;

  /* m = 7 */
  prod_n = 1.0;
  prod_n *= xi - x[i - r + 0];	/* n = 0 */
  prod_n *= xi - x[i - r + 1];	/* n = 1 */
  prod_n *= xi - x[i - r + 2];	/* n = 2 */
  prod_n *= xi - x[i - r + 3];	/* n = 3 */
  prod_n *= xi - x[i - r + 4];	/* n = 4 */
  prod_n *= xi - x[i - r + 5];	/* n = 5 */
  prod_n *= xi - x[i - r + 6];	/* n = 6 */
  sum_m += prod_n;

  prod_m = 1.0;
  prod_m *= x[i - r + 8] - x[i - r + 0];
  prod_m *= x[i - r + 8] - x[i - r + 1];
  prod_m *= x[i - r + 8] - x[i - r + 2];
  prod_m *= x[i - r + 8] - x[i - r + 3];
  prod_m *= x[i - r + 8] - x[i - r + 4];
  prod_m *= x[i - r + 8] - x[i - r + 5];
  prod_m *= x[i - r + 8] - x[i - r + 6];
  prod_m *= x[i - r + 8] - x[i - r + 7];

  sum_l += sum_m / prod_m * (x[i - r + 1 + 1] - x[i - r + 1]);

  c[1] = sum_l;
  /* j = 2 */
  sum_l = 0.0;

  /* l = 3 */
  sum_m = 0.0;

  /* m = 0 */
  prod_n = 1.0;
  prod_n *= xi - x[i - r + 1];	/* n = 1 */
  prod_n *= xi - x[i - r + 2];	/* n = 2 */
  prod_n *= xi - x[i - r + 4];	/* n = 4 */
  prod_n *= xi - x[i - r + 5];	/* n = 5 */
  prod_n *= xi - x[i - r + 6];	/* n = 6 */
  prod_n *= xi - x[i - r + 7];	/* n = 7 */
  prod_n *= xi - x[i - r + 8];	/* n = 8 */
  sum_m += prod_n;

  /* m = 1 */
  prod_n = 1.0;
  prod_n *= xi - x[i - r + 0];	/* n = 0 */
  prod_n *= xi - x[i - r + 2];	/* n = 2 */
  prod_n *= xi - x[i - r + 4];	/* n = 4 */
  prod_n *= xi - x[i - r + 5];	/* n = 5 */
  prod_n *= xi - x[i - r + 6];	/* n = 6 */
  prod_n *= xi - x[i - r + 7];	/* n = 7 */
  prod_n *= xi - x[i - r + 8];	/* n = 8 */
  sum_m += prod_n;

  /* m = 2 */
  prod_n = 1.0;
  prod_n *= xi - x[i - r + 0];	/* n = 0 */
  prod_n *= xi - x[i - r + 1];	/* n = 1 */
  prod_n *= xi - x[i - r + 4];	/* n = 4 */
  prod_n *= xi - x[i - r + 5];	/* n = 5 */
  prod_n *= xi - x[i - r + 6];	/* n = 6 */
  prod_n *= xi - x[i - r + 7];	/* n = 7 */
  prod_n *= xi - x[i - r + 8];	/* n = 8 */
  sum_m += prod_n;

  /* m = 4 */
  prod_n = 1.0;
  prod_n *= xi - x[i - r + 0];	/* n = 0 */
  prod_n *= xi - x[i - r + 1];	/* n = 1 */
  prod_n *= xi - x[i - r + 2];	/* n = 2 */
  prod_n *= xi - x[i - r + 5];	/* n = 5 */
  prod_n *= xi - x[i - r + 6];	/* n = 6 */
  prod_n *= xi - x[i - r + 7];	/* n = 7 */
  prod_n *= xi - x[i - r + 8];	/* n = 8 */
  sum_m += prod_n;

  /* m = 5 */
  prod_n = 1.0;
  prod_n *= xi - x[i - r + 0];	/* n = 0 */
  prod_n *= xi - x[i - r + 1];	/* n = 1 */
  prod_n *= xi - x[i - r + 2];	/* n = 2 */
  prod_n *= xi - x[i - r + 4];	/* n = 4 */
  prod_n *= xi - x[i - r + 6];	/* n = 6 */
  prod_n *= xi - x[i - r + 7];	/* n = 7 */
  prod_n *= xi - x[i - r + 8];	/* n = 8 */
  sum_m += prod_n;

  /* m = 6 */
  prod_n = 1.0;
  prod_n *= xi - x[i - r + 0];	/* n = 0 */
  prod_n *= xi - x[i - r + 1];	/* n = 1 */
  prod_n *= xi - x[i - r + 2];	/* n = 2 */
  prod_n *= xi - x[i - r + 4];	/* n = 4 */
  prod_n *= xi - x[i - r + 5];	/* n = 5 */
  prod_n *= xi - x[i - r + 7];	/* n = 7 */
  prod_n *= xi - x[i - r + 8];	/* n = 8 */
  sum_m += prod_n;

  /* m = 7 */
  prod_n = 1.0;
  prod_n *= xi - x[i - r + 0];	/* n = 0 */
  prod_n *= xi - x[i - r + 1];	/* n = 1 */
  prod_n *= xi - x[i - r + 2];	/* n = 2 */
  prod_n *= xi - x[i - r + 4];	/* n = 4 */
  prod_n *= xi - x[i - r + 5];	/* n = 5 */
  prod_n *= xi - x[i - r + 6];	/* n = 6 */
  prod_n *= xi - x[i - r + 8];	/* n = 8 */
  sum_m += prod_n;

  /* m = 8 */
  prod_n = 1.0;
  prod_n *= xi - x[i - r + 0];	/* n = 0 */
  prod_n *= xi - x[i - r + 1];	/* n = 1 */
  prod_n *= xi - x[i - r + 2];	/* n = 2 */
  prod_n *= xi - x[i - r + 4];	/* n = 4 */
  prod_n *= xi - x[i - r + 5];	/* n = 5 */
  prod_n *= xi - x[i - r + 6];	/* n = 6 */
  prod_n *= xi - x[i - r + 7];	/* n = 7 */
  sum_m += prod_n;

  prod_m = 1.0;
  prod_m *= x[i - r + 3] - x[i - r + 0];
  prod_m *= x[i - r + 3] - x[i - r + 1];
  prod_m *= x[i - r + 3] - x[i - r + 2];
  prod_m *= x[i - r + 3] - x[i - r + 4];
  prod_m *= x[i - r + 3] - x[i - r + 5];
  prod_m *= x[i - r + 3] - x[i - r + 6];
  prod_m *= x[i - r + 3] - x[i - r + 7];
  prod_m *= x[i - r + 3] - x[i - r + 8];

  sum_l += sum_m / prod_m * (x[i - r + 2 + 1] - x[i - r + 2]);

  /* l = 4 */
  sum_m = 0.0;

  /* m = 0 */
  prod_n = 1.0;
  prod_n *= xi - x[i - r + 1];	/* n = 1 */
  prod_n *= xi - x[i - r + 2];	/* n = 2 */
  prod_n *= xi - x[i - r + 3];	/* n = 3 */
  prod_n *= xi - x[i - r + 5];	/* n = 5 */
  prod_n *= xi - x[i - r + 6];	/* n = 6 */
  prod_n *= xi - x[i - r + 7];	/* n = 7 */
  prod_n *= xi - x[i - r + 8];	/* n = 8 */
  sum_m += prod_n;

  /* m = 1 */
  prod_n = 1.0;
  prod_n *= xi - x[i - r + 0];	/* n = 0 */
  prod_n *= xi - x[i - r + 2];	/* n = 2 */
  prod_n *= xi - x[i - r + 3];	/* n = 3 */
  prod_n *= xi - x[i - r + 5];	/* n = 5 */
  prod_n *= xi - x[i - r + 6];	/* n = 6 */
  prod_n *= xi - x[i - r + 7];	/* n = 7 */
  prod_n *= xi - x[i - r + 8];	/* n = 8 */
  sum_m += prod_n;

  /* m = 2 */
  prod_n = 1.0;
  prod_n *= xi - x[i - r + 0];	/* n = 0 */
  prod_n *= xi - x[i - r + 1];	/* n = 1 */
  prod_n *= xi - x[i - r + 3];	/* n = 3 */
  prod_n *= xi - x[i - r + 5];	/* n = 5 */
  prod_n *= xi - x[i - r + 6];	/* n = 6 */
  prod_n *= xi - x[i - r + 7];	/* n = 7 */
  prod_n *= xi - x[i - r + 8];	/* n = 8 */
  sum_m += prod_n;

  /* m = 3 */
  prod_n = 1.0;
  prod_n *= xi - x[i - r + 0];	/* n = 0 */
  prod_n *= xi - x[i - r + 1];	/* n = 1 */
  prod_n *= xi - x[i - r + 2];	/* n = 2 */
  prod_n *= xi - x[i - r + 5];	/* n = 5 */
  prod_n *= xi - x[i - r + 6];	/* n = 6 */
  prod_n *= xi - x[i - r + 7];	/* n = 7 */
  prod_n *= xi - x[i - r + 8];	/* n = 8 */
  sum_m += prod_n;

  /* m = 5 */
  prod_n = 1.0;
  prod_n *= xi - x[i - r + 0];	/* n = 0 */
  prod_n *= xi - x[i - r + 1];	/* n = 1 */
  prod_n *= xi - x[i - r + 2];	/* n = 2 */
  prod_n *= xi - x[i - r + 3];	/* n = 3 */
  prod_n *= xi - x[i - r + 6];	/* n = 6 */
  prod_n *= xi - x[i - r + 7];	/* n = 7 */
  prod_n *= xi - x[i - r + 8];	/* n = 8 */
  sum_m += prod_n;

  /* m = 6 */
  prod_n = 1.0;
  prod_n *= xi - x[i - r + 0];	/* n = 0 */
  prod_n *= xi - x[i - r + 1];	/* n = 1 */
  prod_n *= xi - x[i - r + 2];	/* n = 2 */
  prod_n *= xi - x[i - r + 3];	/* n = 3 */
  prod_n *= xi - x[i - r + 5];	/* n = 5 */
  prod_n *= xi - x[i - r + 7];	/* n = 7 */
  prod_n *= xi - x[i - r + 8];	/* n = 8 */
  sum_m += prod_n;

  /* m = 7 */
  prod_n = 1.0;
  prod_n *= xi - x[i - r + 0];	/* n = 0 */
  prod_n *= xi - x[i - r + 1];	/* n = 1 */
  prod_n *= xi - x[i - r + 2];	/* n = 2 */
  prod_n *= xi - x[i - r + 3];	/* n = 3 */
  prod_n *= xi - x[i - r + 5];	/* n = 5 */
  prod_n *= xi - x[i - r + 6];	/* n = 6 */
  prod_n *= xi - x[i - r + 8];	/* n = 8 */
  sum_m += prod_n;

  /* m = 8 */
  prod_n = 1.0;
  prod_n *= xi - x[i - r + 0];	/* n = 0 */
  prod_n *= xi - x[i - r + 1];	/* n = 1 */
  prod_n *= xi - x[i - r + 2];	/* n = 2 */
  prod_n *= xi - x[i - r + 3];	/* n = 3 */
  prod_n *= xi - x[i - r + 5];	/* n = 5 */
  prod_n *= xi - x[i - r + 6];	/* n = 6 */
  prod_n *= xi - x[i - r + 7];	/* n = 7 */
  sum_m += prod_n;

  prod_m = 1.0;
  prod_m *= x[i - r + 4] - x[i - r + 0];
  prod_m *= x[i - r + 4] - x[i - r + 1];
  prod_m *= x[i - r + 4] - x[i - r + 2];
  prod_m *= x[i - r + 4] - x[i - r + 3];
  prod_m *= x[i - r + 4] - x[i - r + 5];
  prod_m *= x[i - r + 4] - x[i - r + 6];
  prod_m *= x[i - r + 4] - x[i - r + 7];
  prod_m *= x[i - r + 4] - x[i - r + 8];

  sum_l += sum_m / prod_m * (x[i - r + 2 + 1] - x[i - r + 2]);

  /* l = 5 */
  sum_m = 0.0;

  /* m = 0 */
  prod_n = 1.0;
  prod_n *= xi - x[i - r + 1];	/* n = 1 */
  prod_n *= xi - x[i - r + 2];	/* n = 2 */
  prod_n *= xi - x[i - r + 3];	/* n = 3 */
  prod_n *= xi - x[i - r + 4];	/* n = 4 */
  prod_n *= xi - x[i - r + 6];	/* n = 6 */
  prod_n *= xi - x[i - r + 7];	/* n = 7 */
  prod_n *= xi - x[i - r + 8];	/* n = 8 */
  sum_m += prod_n;

  /* m = 1 */
  prod_n = 1.0;
  prod_n *= xi - x[i - r + 0];	/* n = 0 */
  prod_n *= xi - x[i - r + 2];	/* n = 2 */
  prod_n *= xi - x[i - r + 3];	/* n = 3 */
  prod_n *= xi - x[i - r + 4];	/* n = 4 */
  prod_n *= xi - x[i - r + 6];	/* n = 6 */
  prod_n *= xi - x[i - r + 7];	/* n = 7 */
  prod_n *= xi - x[i - r + 8];	/* n = 8 */
  sum_m += prod_n;

  /* m = 2 */
  prod_n = 1.0;
  prod_n *= xi - x[i - r + 0];	/* n = 0 */
  prod_n *= xi - x[i - r + 1];	/* n = 1 */
  prod_n *= xi - x[i - r + 3];	/* n = 3 */
  prod_n *= xi - x[i - r + 4];	/* n = 4 */
  prod_n *= xi - x[i - r + 6];	/* n = 6 */
  prod_n *= xi - x[i - r + 7];	/* n = 7 */
  prod_n *= xi - x[i - r + 8];	/* n = 8 */
  sum_m += prod_n;

  /* m = 3 */
  prod_n = 1.0;
  prod_n *= xi - x[i - r + 0];	/* n = 0 */
  prod_n *= xi - x[i - r + 1];	/* n = 1 */
  prod_n *= xi - x[i - r + 2];	/* n = 2 */
  prod_n *= xi - x[i - r + 4];	/* n = 4 */
  prod_n *= xi - x[i - r + 6];	/* n = 6 */
  prod_n *= xi - x[i - r + 7];	/* n = 7 */
  prod_n *= xi - x[i - r + 8];	/* n = 8 */
  sum_m += prod_n;

  /* m = 4 */
  prod_n = 1.0;
  prod_n *= xi - x[i - r + 0];	/* n = 0 */
  prod_n *= xi - x[i - r + 1];	/* n = 1 */
  prod_n *= xi - x[i - r + 2];	/* n = 2 */
  prod_n *= xi - x[i - r + 3];	/* n = 3 */
  prod_n *= xi - x[i - r + 6];	/* n = 6 */
  prod_n *= xi - x[i - r + 7];	/* n = 7 */
  prod_n *= xi - x[i - r + 8];	/* n = 8 */
  sum_m += prod_n;

  /* m = 6 */
  prod_n = 1.0;
  prod_n *= xi - x[i - r + 0];	/* n = 0 */
  prod_n *= xi - x[i - r + 1];	/* n = 1 */
  prod_n *= xi - x[i - r + 2];	/* n = 2 */
  prod_n *= xi - x[i - r + 3];	/* n = 3 */
  prod_n *= xi - x[i - r + 4];	/* n = 4 */
  prod_n *= xi - x[i - r + 7];	/* n = 7 */
  prod_n *= xi - x[i - r + 8];	/* n = 8 */
  sum_m += prod_n;

  /* m = 7 */
  prod_n = 1.0;
  prod_n *= xi - x[i - r + 0];	/* n = 0 */
  prod_n *= xi - x[i - r + 1];	/* n = 1 */
  prod_n *= xi - x[i - r + 2];	/* n = 2 */
  prod_n *= xi - x[i - r + 3];	/* n = 3 */
  prod_n *= xi - x[i - r + 4];	/* n = 4 */
  prod_n *= xi - x[i - r + 6];	/* n = 6 */
  prod_n *= xi - x[i - r + 8];	/* n = 8 */
  sum_m += prod_n;

  /* m = 8 */
  prod_n = 1.0;
  prod_n *= xi - x[i - r + 0];	/* n = 0 */
  prod_n *= xi - x[i - r + 1];	/* n = 1 */
  prod_n *= xi - x[i - r + 2];	/* n = 2 */
  prod_n *= xi - x[i - r + 3];	/* n = 3 */
  prod_n *= xi - x[i - r + 4];	/* n = 4 */
  prod_n *= xi - x[i - r + 6];	/* n = 6 */
  prod_n *= xi - x[i - r + 7];	/* n = 7 */
  sum_m += prod_n;

  prod_m = 1.0;
  prod_m *= x[i - r + 5] - x[i - r + 0];
  prod_m *= x[i - r + 5] - x[i - r + 1];
  prod_m *= x[i - r + 5] - x[i - r + 2];
  prod_m *= x[i - r + 5] - x[i - r + 3];
  prod_m *= x[i - r + 5] - x[i - r + 4];
  prod_m *= x[i - r + 5] - x[i - r + 6];
  prod_m *= x[i - r + 5] - x[i - r + 7];
  prod_m *= x[i - r + 5] - x[i - r + 8];

  sum_l += sum_m / prod_m * (x[i - r + 2 + 1] - x[i - r + 2]);

  /* l = 6 */
  sum_m = 0.0;

  /* m = 0 */
  prod_n = 1.0;
  prod_n *= xi - x[i - r + 1];	/* n = 1 */
  prod_n *= xi - x[i - r + 2];	/* n = 2 */
  prod_n *= xi - x[i - r + 3];	/* n = 3 */
  prod_n *= xi - x[i - r + 4];	/* n = 4 */
  prod_n *= xi - x[i - r + 5];	/* n = 5 */
  prod_n *= xi - x[i - r + 7];	/* n = 7 */
  prod_n *= xi - x[i - r + 8];	/* n = 8 */
  sum_m += prod_n;

  /* m = 1 */
  prod_n = 1.0;
  prod_n *= xi - x[i - r + 0];	/* n = 0 */
  prod_n *= xi - x[i - r + 2];	/* n = 2 */
  prod_n *= xi - x[i - r + 3];	/* n = 3 */
  prod_n *= xi - x[i - r + 4];	/* n = 4 */
  prod_n *= xi - x[i - r + 5];	/* n = 5 */
  prod_n *= xi - x[i - r + 7];	/* n = 7 */
  prod_n *= xi - x[i - r + 8];	/* n = 8 */
  sum_m += prod_n;

  /* m = 2 */
  prod_n = 1.0;
  prod_n *= xi - x[i - r + 0];	/* n = 0 */
  prod_n *= xi - x[i - r + 1];	/* n = 1 */
  prod_n *= xi - x[i - r + 3];	/* n = 3 */
  prod_n *= xi - x[i - r + 4];	/* n = 4 */
  prod_n *= xi - x[i - r + 5];	/* n = 5 */
  prod_n *= xi - x[i - r + 7];	/* n = 7 */
  prod_n *= xi - x[i - r + 8];	/* n = 8 */
  sum_m += prod_n;

  /* m = 3 */
  prod_n = 1.0;
  prod_n *= xi - x[i - r + 0];	/* n = 0 */
  prod_n *= xi - x[i - r + 1];	/* n = 1 */
  prod_n *= xi - x[i - r + 2];	/* n = 2 */
  prod_n *= xi - x[i - r + 4];	/* n = 4 */
  prod_n *= xi - x[i - r + 5];	/* n = 5 */
  prod_n *= xi - x[i - r + 7];	/* n = 7 */
  prod_n *= xi - x[i - r + 8];	/* n = 8 */
  sum_m += prod_n;

  /* m = 4 */
  prod_n = 1.0;
  prod_n *= xi - x[i - r + 0];	/* n = 0 */
  prod_n *= xi - x[i - r + 1];	/* n = 1 */
  prod_n *= xi - x[i - r + 2];	/* n = 2 */
  prod_n *= xi - x[i - r + 3];	/* n = 3 */
  prod_n *= xi - x[i - r + 5];	/* n = 5 */
  prod_n *= xi - x[i - r + 7];	/* n = 7 */
  prod_n *= xi - x[i - r + 8];	/* n = 8 */
  sum_m += prod_n;

  /* m = 5 */
  prod_n = 1.0;
  prod_n *= xi - x[i - r + 0];	/* n = 0 */
  prod_n *= xi - x[i - r + 1];	/* n = 1 */
  prod_n *= xi - x[i - r + 2];	/* n = 2 */
  prod_n *= xi - x[i - r + 3];	/* n = 3 */
  prod_n *= xi - x[i - r + 4];	/* n = 4 */
  prod_n *= xi - x[i - r + 7];	/* n = 7 */
  prod_n *= xi - x[i - r + 8];	/* n = 8 */
  sum_m += prod_n;

  /* m = 7 */
  prod_n = 1.0;
  prod_n *= xi - x[i - r + 0];	/* n = 0 */
  prod_n *= xi - x[i - r + 1];	/* n = 1 */
  prod_n *= xi - x[i - r + 2];	/* n = 2 */
  prod_n *= xi - x[i - r + 3];	/* n = 3 */
  prod_n *= xi - x[i - r + 4];	/* n = 4 */
  prod_n *= xi - x[i - r + 5];	/* n = 5 */
  prod_n *= xi - x[i - r + 8];	/* n = 8 */
  sum_m += prod_n;

  /* m = 8 */
  prod_n = 1.0;
  prod_n *= xi - x[i - r + 0];	/* n = 0 */
  prod_n *= xi - x[i - r + 1];	/* n = 1 */
  prod_n *= xi - x[i - r + 2];	/* n = 2 */
  prod_n *= xi - x[i - r + 3];	/* n = 3 */
  prod_n *= xi - x[i - r + 4];	/* n = 4 */
  prod_n *= xi - x[i - r + 5];	/* n = 5 */
  prod_n *= xi - x[i - r + 7];	/* n = 7 */
  sum_m += prod_n;

  prod_m = 1.0;
  prod_m *= x[i - r + 6] - x[i - r + 0];
  prod_m *= x[i - r + 6] - x[i - r + 1];
  prod_m *= x[i - r + 6] - x[i - r + 2];
  prod_m *= x[i - r + 6] - x[i - r + 3];
  prod_m *= x[i - r + 6] - x[i - r + 4];
  prod_m *= x[i - r + 6] - x[i - r + 5];
  prod_m *= x[i - r + 6] - x[i - r + 7];
  prod_m *= x[i - r + 6] - x[i - r + 8];

  sum_l += sum_m / prod_m * (x[i - r + 2 + 1] - x[i - r + 2]);

  /* l = 7 */
  sum_m = 0.0;

  /* m = 0 */
  prod_n = 1.0;
  prod_n *= xi - x[i - r + 1];	/* n = 1 */
  prod_n *= xi - x[i - r + 2];	/* n = 2 */
  prod_n *= xi - x[i - r + 3];	/* n = 3 */
  prod_n *= xi - x[i - r + 4];	/* n = 4 */
  prod_n *= xi - x[i - r + 5];	/* n = 5 */
  prod_n *= xi - x[i - r + 6];	/* n = 6 */
  prod_n *= xi - x[i - r + 8];	/* n = 8 */
  sum_m += prod_n;

  /* m = 1 */
  prod_n = 1.0;
  prod_n *= xi - x[i - r + 0];	/* n = 0 */
  prod_n *= xi - x[i - r + 2];	/* n = 2 */
  prod_n *= xi - x[i - r + 3];	/* n = 3 */
  prod_n *= xi - x[i - r + 4];	/* n = 4 */
  prod_n *= xi - x[i - r + 5];	/* n = 5 */
  prod_n *= xi - x[i - r + 6];	/* n = 6 */
  prod_n *= xi - x[i - r + 8];	/* n = 8 */
  sum_m += prod_n;

  /* m = 2 */
  prod_n = 1.0;
  prod_n *= xi - x[i - r + 0];	/* n = 0 */
  prod_n *= xi - x[i - r + 1];	/* n = 1 */
  prod_n *= xi - x[i - r + 3];	/* n = 3 */
  prod_n *= xi - x[i - r + 4];	/* n = 4 */
  prod_n *= xi - x[i - r + 5];	/* n = 5 */
  prod_n *= xi - x[i - r + 6];	/* n = 6 */
  prod_n *= xi - x[i - r + 8];	/* n = 8 */
  sum_m += prod_n;

  /* m = 3 */
  prod_n = 1.0;
  prod_n *= xi - x[i - r + 0];	/* n = 0 */
  prod_n *= xi - x[i - r + 1];	/* n = 1 */
  prod_n *= xi - x[i - r + 2];	/* n = 2 */
  prod_n *= xi - x[i - r + 4];	/* n = 4 */
  prod_n *= xi - x[i - r + 5];	/* n = 5 */
  prod_n *= xi - x[i - r + 6];	/* n = 6 */
  prod_n *= xi - x[i - r + 8];	/* n = 8 */
  sum_m += prod_n;

  /* m = 4 */
  prod_n = 1.0;
  prod_n *= xi - x[i - r + 0];	/* n = 0 */
  prod_n *= xi - x[i - r + 1];	/* n = 1 */
  prod_n *= xi - x[i - r + 2];	/* n = 2 */
  prod_n *= xi - x[i - r + 3];	/* n = 3 */
  prod_n *= xi - x[i - r + 5];	/* n = 5 */
  prod_n *= xi - x[i - r + 6];	/* n = 6 */
  prod_n *= xi - x[i - r + 8];	/* n = 8 */
  sum_m += prod_n;

  /* m = 5 */
  prod_n = 1.0;
  prod_n *= xi - x[i - r + 0];	/* n = 0 */
  prod_n *= xi - x[i - r + 1];	/* n = 1 */
  prod_n *= xi - x[i - r + 2];	/* n = 2 */
  prod_n *= xi - x[i - r + 3];	/* n = 3 */
  prod_n *= xi - x[i - r + 4];	/* n = 4 */
  prod_n *= xi - x[i - r + 6];	/* n = 6 */
  prod_n *= xi - x[i - r + 8];	/* n = 8 */
  sum_m += prod_n;

  /* m = 6 */
  prod_n = 1.0;
  prod_n *= xi - x[i - r + 0];	/* n = 0 */
  prod_n *= xi - x[i - r + 1];	/* n = 1 */
  prod_n *= xi - x[i - r + 2];	/* n = 2 */
  prod_n *= xi - x[i - r + 3];	/* n = 3 */
  prod_n *= xi - x[i - r + 4];	/* n = 4 */
  prod_n *= xi - x[i - r + 5];	/* n = 5 */
  prod_n *= xi - x[i - r + 8];	/* n = 8 */
  sum_m += prod_n;

  /* m = 8 */
  prod_n = 1.0;
  prod_n *= xi - x[i - r + 0];	/* n = 0 */
  prod_n *= xi - x[i - r + 1];	/* n = 1 */
  prod_n *= xi - x[i - r + 2];	/* n = 2 */
  prod_n *= xi - x[i - r + 3];	/* n = 3 */
  prod_n *= xi - x[i - r + 4];	/* n = 4 */
  prod_n *= xi - x[i - r + 5];	/* n = 5 */
  prod_n *= xi - x[i - r + 6];	/* n = 6 */
  sum_m += prod_n;

  prod_m = 1.0;
  prod_m *= x[i - r + 7] - x[i - r + 0];
  prod_m *= x[i - r + 7] - x[i - r + 1];
  prod_m *= x[i - r + 7] - x[i - r + 2];
  prod_m *= x[i - r + 7] - x[i - r + 3];
  prod_m *= x[i - r + 7] - x[i - r + 4];
  prod_m *= x[i - r + 7] - x[i - r + 5];
  prod_m *= x[i - r + 7] - x[i - r + 6];
  prod_m *= x[i - r + 7] - x[i - r + 8];

  sum_l += sum_m / prod_m * (x[i - r + 2 + 1] - x[i - r + 2]);

  /* l = 8 */
  sum_m = 0.0;

  /* m = 0 */
  prod_n = 1.0;
  prod_n *= xi - x[i - r + 1];	/* n = 1 */
  prod_n *= xi - x[i - r + 2];	/* n = 2 */
  prod_n *= xi - x[i - r + 3];	/* n = 3 */
  prod_n *= xi - x[i - r + 4];	/* n = 4 */
  prod_n *= xi - x[i - r + 5];	/* n = 5 */
  prod_n *= xi - x[i - r + 6];	/* n = 6 */
  prod_n *= xi - x[i - r + 7];	/* n = 7 */
  sum_m += prod_n;

  /* m = 1 */
  prod_n = 1.0;
  prod_n *= xi - x[i - r + 0];	/* n = 0 */
  prod_n *= xi - x[i - r + 2];	/* n = 2 */
  prod_n *= xi - x[i - r + 3];	/* n = 3 */
  prod_n *= xi - x[i - r + 4];	/* n = 4 */
  prod_n *= xi - x[i - r + 5];	/* n = 5 */
  prod_n *= xi - x[i - r + 6];	/* n = 6 */
  prod_n *= xi - x[i - r + 7];	/* n = 7 */
  sum_m += prod_n;

  /* m = 2 */
  prod_n = 1.0;
  prod_n *= xi - x[i - r + 0];	/* n = 0 */
  prod_n *= xi - x[i - r + 1];	/* n = 1 */
  prod_n *= xi - x[i - r + 3];	/* n = 3 */
  prod_n *= xi - x[i - r + 4];	/* n = 4 */
  prod_n *= xi - x[i - r + 5];	/* n = 5 */
  prod_n *= xi - x[i - r + 6];	/* n = 6 */
  prod_n *= xi - x[i - r + 7];	/* n = 7 */
  sum_m += prod_n;

  /* m = 3 */
  prod_n = 1.0;
  prod_n *= xi - x[i - r + 0];	/* n = 0 */
  prod_n *= xi - x[i - r + 1];	/* n = 1 */
  prod_n *= xi - x[i - r + 2];	/* n = 2 */
  prod_n *= xi - x[i - r + 4];	/* n = 4 */
  prod_n *= xi - x[i - r + 5];	/* n = 5 */
  prod_n *= xi - x[i - r + 6];	/* n = 6 */
  prod_n *= xi - x[i - r + 7];	/* n = 7 */
  sum_m += prod_n;

  /* m = 4 */
  prod_n = 1.0;
  prod_n *= xi - x[i - r + 0];	/* n = 0 */
  prod_n *= xi - x[i - r + 1];	/* n = 1 */
  prod_n *= xi - x[i - r + 2];	/* n = 2 */
  prod_n *= xi - x[i - r + 3];	/* n = 3 */
  prod_n *= xi - x[i - r + 5];	/* n = 5 */
  prod_n *= xi - x[i - r + 6];	/* n = 6 */
  prod_n *= xi - x[i - r + 7];	/* n = 7 */
  sum_m += prod_n;

  /* m = 5 */
  prod_n = 1.0;
  prod_n *= xi - x[i - r + 0];	/* n = 0 */
  prod_n *= xi - x[i - r + 1];	/* n = 1 */
  prod_n *= xi - x[i - r + 2];	/* n = 2 */
  prod_n *= xi - x[i - r + 3];	/* n = 3 */
  prod_n *= xi - x[i - r + 4];	/* n = 4 */
  prod_n *= xi - x[i - r + 6];	/* n = 6 */
  prod_n *= xi - x[i - r + 7];	/* n = 7 */
  sum_m += prod_n;

  /* m = 6 */
  prod_n = 1.0;
  prod_n *= xi - x[i - r + 0];	/* n = 0 */
  prod_n *= xi - x[i - r + 1];	/* n = 1 */
  prod_n *= xi - x[i - r + 2];	/* n = 2 */
  prod_n *= xi - x[i - r + 3];	/* n = 3 */
  prod_n *= xi - x[i - r + 4];	/* n = 4 */
  prod_n *= xi - x[i - r + 5];	/* n = 5 */
  prod_n *= xi - x[i - r + 7];	/* n = 7 */
  sum_m += prod_n;

  /* m = 7 */
  prod_n = 1.0;
  prod_n *= xi - x[i - r + 0];	/* n = 0 */
  prod_n *= xi - x[i - r + 1];	/* n = 1 */
  prod_n *= xi - x[i - r + 2];	/* n = 2 */
  prod_n *= xi - x[i - r + 3];	/* n = 3 */
  prod_n *= xi - x[i - r + 4];	/* n = 4 */
  prod_n *= xi - x[i - r + 5];	/* n = 5 */
  prod_n *= xi - x[i - r + 6];	/* n = 6 */
  sum_m += prod_n;

  prod_m = 1.0;
  prod_m *= x[i - r + 8] - x[i - r + 0];
  prod_m *= x[i - r + 8] - x[i - r + 1];
  prod_m *= x[i - r + 8] - x[i - r + 2];
  prod_m *= x[i - r + 8] - x[i - r + 3];
  prod_m *= x[i - r + 8] - x[i - r + 4];
  prod_m *= x[i - r + 8] - x[i - r + 5];
  prod_m *= x[i - r + 8] - x[i - r + 6];
  prod_m *= x[i - r + 8] - x[i - r + 7];

  sum_l += sum_m / prod_m * (x[i - r + 2 + 1] - x[i - r + 2]);

  c[2] = sum_l;
  /* j = 3 */
  sum_l = 0.0;

  /* l = 4 */
  sum_m = 0.0;

  /* m = 0 */
  prod_n = 1.0;
  prod_n *= xi - x[i - r + 1];	/* n = 1 */
  prod_n *= xi - x[i - r + 2];	/* n = 2 */
  prod_n *= xi - x[i - r + 3];	/* n = 3 */
  prod_n *= xi - x[i - r + 5];	/* n = 5 */
  prod_n *= xi - x[i - r + 6];	/* n = 6 */
  prod_n *= xi - x[i - r + 7];	/* n = 7 */
  prod_n *= xi - x[i - r + 8];	/* n = 8 */
  sum_m += prod_n;

  /* m = 1 */
  prod_n = 1.0;
  prod_n *= xi - x[i - r + 0];	/* n = 0 */
  prod_n *= xi - x[i - r + 2];	/* n = 2 */
  prod_n *= xi - x[i - r + 3];	/* n = 3 */
  prod_n *= xi - x[i - r + 5];	/* n = 5 */
  prod_n *= xi - x[i - r + 6];	/* n = 6 */
  prod_n *= xi - x[i - r + 7];	/* n = 7 */
  prod_n *= xi - x[i - r + 8];	/* n = 8 */
  sum_m += prod_n;

  /* m = 2 */
  prod_n = 1.0;
  prod_n *= xi - x[i - r + 0];	/* n = 0 */
  prod_n *= xi - x[i - r + 1];	/* n = 1 */
  prod_n *= xi - x[i - r + 3];	/* n = 3 */
  prod_n *= xi - x[i - r + 5];	/* n = 5 */
  prod_n *= xi - x[i - r + 6];	/* n = 6 */
  prod_n *= xi - x[i - r + 7];	/* n = 7 */
  prod_n *= xi - x[i - r + 8];	/* n = 8 */
  sum_m += prod_n;

  /* m = 3 */
  prod_n = 1.0;
  prod_n *= xi - x[i - r + 0];	/* n = 0 */
  prod_n *= xi - x[i - r + 1];	/* n = 1 */
  prod_n *= xi - x[i - r + 2];	/* n = 2 */
  prod_n *= xi - x[i - r + 5];	/* n = 5 */
  prod_n *= xi - x[i - r + 6];	/* n = 6 */
  prod_n *= xi - x[i - r + 7];	/* n = 7 */
  prod_n *= xi - x[i - r + 8];	/* n = 8 */
  sum_m += prod_n;

  /* m = 5 */
  prod_n = 1.0;
  prod_n *= xi - x[i - r + 0];	/* n = 0 */
  prod_n *= xi - x[i - r + 1];	/* n = 1 */
  prod_n *= xi - x[i - r + 2];	/* n = 2 */
  prod_n *= xi - x[i - r + 3];	/* n = 3 */
  prod_n *= xi - x[i - r + 6];	/* n = 6 */
  prod_n *= xi - x[i - r + 7];	/* n = 7 */
  prod_n *= xi - x[i - r + 8];	/* n = 8 */
  sum_m += prod_n;

  /* m = 6 */
  prod_n = 1.0;
  prod_n *= xi - x[i - r + 0];	/* n = 0 */
  prod_n *= xi - x[i - r + 1];	/* n = 1 */
  prod_n *= xi - x[i - r + 2];	/* n = 2 */
  prod_n *= xi - x[i - r + 3];	/* n = 3 */
  prod_n *= xi - x[i - r + 5];	/* n = 5 */
  prod_n *= xi - x[i - r + 7];	/* n = 7 */
  prod_n *= xi - x[i - r + 8];	/* n = 8 */
  sum_m += prod_n;

  /* m = 7 */
  prod_n = 1.0;
  prod_n *= xi - x[i - r + 0];	/* n = 0 */
  prod_n *= xi - x[i - r + 1];	/* n = 1 */
  prod_n *= xi - x[i - r + 2];	/* n = 2 */
  prod_n *= xi - x[i - r + 3];	/* n = 3 */
  prod_n *= xi - x[i - r + 5];	/* n = 5 */
  prod_n *= xi - x[i - r + 6];	/* n = 6 */
  prod_n *= xi - x[i - r + 8];	/* n = 8 */
  sum_m += prod_n;

  /* m = 8 */
  prod_n = 1.0;
  prod_n *= xi - x[i - r + 0];	/* n = 0 */
  prod_n *= xi - x[i - r + 1];	/* n = 1 */
  prod_n *= xi - x[i - r + 2];	/* n = 2 */
  prod_n *= xi - x[i - r + 3];	/* n = 3 */
  prod_n *= xi - x[i - r + 5];	/* n = 5 */
  prod_n *= xi - x[i - r + 6];	/* n = 6 */
  prod_n *= xi - x[i - r + 7];	/* n = 7 */
  sum_m += prod_n;

  prod_m = 1.0;
  prod_m *= x[i - r + 4] - x[i - r + 0];
  prod_m *= x[i - r + 4] - x[i - r + 1];
  prod_m *= x[i - r + 4] - x[i - r + 2];
  prod_m *= x[i - r + 4] - x[i - r + 3];
  prod_m *= x[i - r + 4] - x[i - r + 5];
  prod_m *= x[i - r + 4] - x[i - r + 6];
  prod_m *= x[i - r + 4] - x[i - r + 7];
  prod_m *= x[i - r + 4] - x[i - r + 8];

  sum_l += sum_m / prod_m * (x[i - r + 3 + 1] - x[i - r + 3]);

  /* l = 5 */
  sum_m = 0.0;

  /* m = 0 */
  prod_n = 1.0;
  prod_n *= xi - x[i - r + 1];	/* n = 1 */
  prod_n *= xi - x[i - r + 2];	/* n = 2 */
  prod_n *= xi - x[i - r + 3];	/* n = 3 */
  prod_n *= xi - x[i - r + 4];	/* n = 4 */
  prod_n *= xi - x[i - r + 6];	/* n = 6 */
  prod_n *= xi - x[i - r + 7];	/* n = 7 */
  prod_n *= xi - x[i - r + 8];	/* n = 8 */
  sum_m += prod_n;

  /* m = 1 */
  prod_n = 1.0;
  prod_n *= xi - x[i - r + 0];	/* n = 0 */
  prod_n *= xi - x[i - r + 2];	/* n = 2 */
  prod_n *= xi - x[i - r + 3];	/* n = 3 */
  prod_n *= xi - x[i - r + 4];	/* n = 4 */
  prod_n *= xi - x[i - r + 6];	/* n = 6 */
  prod_n *= xi - x[i - r + 7];	/* n = 7 */
  prod_n *= xi - x[i - r + 8];	/* n = 8 */
  sum_m += prod_n;

  /* m = 2 */
  prod_n = 1.0;
  prod_n *= xi - x[i - r + 0];	/* n = 0 */
  prod_n *= xi - x[i - r + 1];	/* n = 1 */
  prod_n *= xi - x[i - r + 3];	/* n = 3 */
  prod_n *= xi - x[i - r + 4];	/* n = 4 */
  prod_n *= xi - x[i - r + 6];	/* n = 6 */
  prod_n *= xi - x[i - r + 7];	/* n = 7 */
  prod_n *= xi - x[i - r + 8];	/* n = 8 */
  sum_m += prod_n;

  /* m = 3 */
  prod_n = 1.0;
  prod_n *= xi - x[i - r + 0];	/* n = 0 */
  prod_n *= xi - x[i - r + 1];	/* n = 1 */
  prod_n *= xi - x[i - r + 2];	/* n = 2 */
  prod_n *= xi - x[i - r + 4];	/* n = 4 */
  prod_n *= xi - x[i - r + 6];	/* n = 6 */
  prod_n *= xi - x[i - r + 7];	/* n = 7 */
  prod_n *= xi - x[i - r + 8];	/* n = 8 */
  sum_m += prod_n;

  /* m = 4 */
  prod_n = 1.0;
  prod_n *= xi - x[i - r + 0];	/* n = 0 */
  prod_n *= xi - x[i - r + 1];	/* n = 1 */
  prod_n *= xi - x[i - r + 2];	/* n = 2 */
  prod_n *= xi - x[i - r + 3];	/* n = 3 */
  prod_n *= xi - x[i - r + 6];	/* n = 6 */
  prod_n *= xi - x[i - r + 7];	/* n = 7 */
  prod_n *= xi - x[i - r + 8];	/* n = 8 */
  sum_m += prod_n;

  /* m = 6 */
  prod_n = 1.0;
  prod_n *= xi - x[i - r + 0];	/* n = 0 */
  prod_n *= xi - x[i - r + 1];	/* n = 1 */
  prod_n *= xi - x[i - r + 2];	/* n = 2 */
  prod_n *= xi - x[i - r + 3];	/* n = 3 */
  prod_n *= xi - x[i - r + 4];	/* n = 4 */
  prod_n *= xi - x[i - r + 7];	/* n = 7 */
  prod_n *= xi - x[i - r + 8];	/* n = 8 */
  sum_m += prod_n;

  /* m = 7 */
  prod_n = 1.0;
  prod_n *= xi - x[i - r + 0];	/* n = 0 */
  prod_n *= xi - x[i - r + 1];	/* n = 1 */
  prod_n *= xi - x[i - r + 2];	/* n = 2 */
  prod_n *= xi - x[i - r + 3];	/* n = 3 */
  prod_n *= xi - x[i - r + 4];	/* n = 4 */
  prod_n *= xi - x[i - r + 6];	/* n = 6 */
  prod_n *= xi - x[i - r + 8];	/* n = 8 */
  sum_m += prod_n;

  /* m = 8 */
  prod_n = 1.0;
  prod_n *= xi - x[i - r + 0];	/* n = 0 */
  prod_n *= xi - x[i - r + 1];	/* n = 1 */
  prod_n *= xi - x[i - r + 2];	/* n = 2 */
  prod_n *= xi - x[i - r + 3];	/* n = 3 */
  prod_n *= xi - x[i - r + 4];	/* n = 4 */
  prod_n *= xi - x[i - r + 6];	/* n = 6 */
  prod_n *= xi - x[i - r + 7];	/* n = 7 */
  sum_m += prod_n;

  prod_m = 1.0;
  prod_m *= x[i - r + 5] - x[i - r + 0];
  prod_m *= x[i - r + 5] - x[i - r + 1];
  prod_m *= x[i - r + 5] - x[i - r + 2];
  prod_m *= x[i - r + 5] - x[i - r + 3];
  prod_m *= x[i - r + 5] - x[i - r + 4];
  prod_m *= x[i - r + 5] - x[i - r + 6];
  prod_m *= x[i - r + 5] - x[i - r + 7];
  prod_m *= x[i - r + 5] - x[i - r + 8];

  sum_l += sum_m / prod_m * (x[i - r + 3 + 1] - x[i - r + 3]);

  /* l = 6 */
  sum_m = 0.0;

  /* m = 0 */
  prod_n = 1.0;
  prod_n *= xi - x[i - r + 1];	/* n = 1 */
  prod_n *= xi - x[i - r + 2];	/* n = 2 */
  prod_n *= xi - x[i - r + 3];	/* n = 3 */
  prod_n *= xi - x[i - r + 4];	/* n = 4 */
  prod_n *= xi - x[i - r + 5];	/* n = 5 */
  prod_n *= xi - x[i - r + 7];	/* n = 7 */
  prod_n *= xi - x[i - r + 8];	/* n = 8 */
  sum_m += prod_n;

  /* m = 1 */
  prod_n = 1.0;
  prod_n *= xi - x[i - r + 0];	/* n = 0 */
  prod_n *= xi - x[i - r + 2];	/* n = 2 */
  prod_n *= xi - x[i - r + 3];	/* n = 3 */
  prod_n *= xi - x[i - r + 4];	/* n = 4 */
  prod_n *= xi - x[i - r + 5];	/* n = 5 */
  prod_n *= xi - x[i - r + 7];	/* n = 7 */
  prod_n *= xi - x[i - r + 8];	/* n = 8 */
  sum_m += prod_n;

  /* m = 2 */
  prod_n = 1.0;
  prod_n *= xi - x[i - r + 0];	/* n = 0 */
  prod_n *= xi - x[i - r + 1];	/* n = 1 */
  prod_n *= xi - x[i - r + 3];	/* n = 3 */
  prod_n *= xi - x[i - r + 4];	/* n = 4 */
  prod_n *= xi - x[i - r + 5];	/* n = 5 */
  prod_n *= xi - x[i - r + 7];	/* n = 7 */
  prod_n *= xi - x[i - r + 8];	/* n = 8 */
  sum_m += prod_n;

  /* m = 3 */
  prod_n = 1.0;
  prod_n *= xi - x[i - r + 0];	/* n = 0 */
  prod_n *= xi - x[i - r + 1];	/* n = 1 */
  prod_n *= xi - x[i - r + 2];	/* n = 2 */
  prod_n *= xi - x[i - r + 4];	/* n = 4 */
  prod_n *= xi - x[i - r + 5];	/* n = 5 */
  prod_n *= xi - x[i - r + 7];	/* n = 7 */
  prod_n *= xi - x[i - r + 8];	/* n = 8 */
  sum_m += prod_n;

  /* m = 4 */
  prod_n = 1.0;
  prod_n *= xi - x[i - r + 0];	/* n = 0 */
  prod_n *= xi - x[i - r + 1];	/* n = 1 */
  prod_n *= xi - x[i - r + 2];	/* n = 2 */
  prod_n *= xi - x[i - r + 3];	/* n = 3 */
  prod_n *= xi - x[i - r + 5];	/* n = 5 */
  prod_n *= xi - x[i - r + 7];	/* n = 7 */
  prod_n *= xi - x[i - r + 8];	/* n = 8 */
  sum_m += prod_n;

  /* m = 5 */
  prod_n = 1.0;
  prod_n *= xi - x[i - r + 0];	/* n = 0 */
  prod_n *= xi - x[i - r + 1];	/* n = 1 */
  prod_n *= xi - x[i - r + 2];	/* n = 2 */
  prod_n *= xi - x[i - r + 3];	/* n = 3 */
  prod_n *= xi - x[i - r + 4];	/* n = 4 */
  prod_n *= xi - x[i - r + 7];	/* n = 7 */
  prod_n *= xi - x[i - r + 8];	/* n = 8 */
  sum_m += prod_n;

  /* m = 7 */
  prod_n = 1.0;
  prod_n *= xi - x[i - r + 0];	/* n = 0 */
  prod_n *= xi - x[i - r + 1];	/* n = 1 */
  prod_n *= xi - x[i - r + 2];	/* n = 2 */
  prod_n *= xi - x[i - r + 3];	/* n = 3 */
  prod_n *= xi - x[i - r + 4];	/* n = 4 */
  prod_n *= xi - x[i - r + 5];	/* n = 5 */
  prod_n *= xi - x[i - r + 8];	/* n = 8 */
  sum_m += prod_n;

  /* m = 8 */
  prod_n = 1.0;
  prod_n *= xi - x[i - r + 0];	/* n = 0 */
  prod_n *= xi - x[i - r + 1];	/* n = 1 */
  prod_n *= xi - x[i - r + 2];	/* n = 2 */
  prod_n *= xi - x[i - r + 3];	/* n = 3 */
  prod_n *= xi - x[i - r + 4];	/* n = 4 */
  prod_n *= xi - x[i - r + 5];	/* n = 5 */
  prod_n *= xi - x[i - r + 7];	/* n = 7 */
  sum_m += prod_n;

  prod_m = 1.0;
  prod_m *= x[i - r + 6] - x[i - r + 0];
  prod_m *= x[i - r + 6] - x[i - r + 1];
  prod_m *= x[i - r + 6] - x[i - r + 2];
  prod_m *= x[i - r + 6] - x[i - r + 3];
  prod_m *= x[i - r + 6] - x[i - r + 4];
  prod_m *= x[i - r + 6] - x[i - r + 5];
  prod_m *= x[i - r + 6] - x[i - r + 7];
  prod_m *= x[i - r + 6] - x[i - r + 8];

  sum_l += sum_m / prod_m * (x[i - r + 3 + 1] - x[i - r + 3]);

  /* l = 7 */
  sum_m = 0.0;

  /* m = 0 */
  prod_n = 1.0;
  prod_n *= xi - x[i - r + 1];	/* n = 1 */
  prod_n *= xi - x[i - r + 2];	/* n = 2 */
  prod_n *= xi - x[i - r + 3];	/* n = 3 */
  prod_n *= xi - x[i - r + 4];	/* n = 4 */
  prod_n *= xi - x[i - r + 5];	/* n = 5 */
  prod_n *= xi - x[i - r + 6];	/* n = 6 */
  prod_n *= xi - x[i - r + 8];	/* n = 8 */
  sum_m += prod_n;

  /* m = 1 */
  prod_n = 1.0;
  prod_n *= xi - x[i - r + 0];	/* n = 0 */
  prod_n *= xi - x[i - r + 2];	/* n = 2 */
  prod_n *= xi - x[i - r + 3];	/* n = 3 */
  prod_n *= xi - x[i - r + 4];	/* n = 4 */
  prod_n *= xi - x[i - r + 5];	/* n = 5 */
  prod_n *= xi - x[i - r + 6];	/* n = 6 */
  prod_n *= xi - x[i - r + 8];	/* n = 8 */
  sum_m += prod_n;

  /* m = 2 */
  prod_n = 1.0;
  prod_n *= xi - x[i - r + 0];	/* n = 0 */
  prod_n *= xi - x[i - r + 1];	/* n = 1 */
  prod_n *= xi - x[i - r + 3];	/* n = 3 */
  prod_n *= xi - x[i - r + 4];	/* n = 4 */
  prod_n *= xi - x[i - r + 5];	/* n = 5 */
  prod_n *= xi - x[i - r + 6];	/* n = 6 */
  prod_n *= xi - x[i - r + 8];	/* n = 8 */
  sum_m += prod_n;

  /* m = 3 */
  prod_n = 1.0;
  prod_n *= xi - x[i - r + 0];	/* n = 0 */
  prod_n *= xi - x[i - r + 1];	/* n = 1 */
  prod_n *= xi - x[i - r + 2];	/* n = 2 */
  prod_n *= xi - x[i - r + 4];	/* n = 4 */
  prod_n *= xi - x[i - r + 5];	/* n = 5 */
  prod_n *= xi - x[i - r + 6];	/* n = 6 */
  prod_n *= xi - x[i - r + 8];	/* n = 8 */
  sum_m += prod_n;

  /* m = 4 */
  prod_n = 1.0;
  prod_n *= xi - x[i - r + 0];	/* n = 0 */
  prod_n *= xi - x[i - r + 1];	/* n = 1 */
  prod_n *= xi - x[i - r + 2];	/* n = 2 */
  prod_n *= xi - x[i - r + 3];	/* n = 3 */
  prod_n *= xi - x[i - r + 5];	/* n = 5 */
  prod_n *= xi - x[i - r + 6];	/* n = 6 */
  prod_n *= xi - x[i - r + 8];	/* n = 8 */
  sum_m += prod_n;

  /* m = 5 */
  prod_n = 1.0;
  prod_n *= xi - x[i - r + 0];	/* n = 0 */
  prod_n *= xi - x[i - r + 1];	/* n = 1 */
  prod_n *= xi - x[i - r + 2];	/* n = 2 */
  prod_n *= xi - x[i - r + 3];	/* n = 3 */
  prod_n *= xi - x[i - r + 4];	/* n = 4 */
  prod_n *= xi - x[i - r + 6];	/* n = 6 */
  prod_n *= xi - x[i - r + 8];	/* n = 8 */
  sum_m += prod_n;

  /* m = 6 */
  prod_n = 1.0;
  prod_n *= xi - x[i - r + 0];	/* n = 0 */
  prod_n *= xi - x[i - r + 1];	/* n = 1 */
  prod_n *= xi - x[i - r + 2];	/* n = 2 */
  prod_n *= xi - x[i - r + 3];	/* n = 3 */
  prod_n *= xi - x[i - r + 4];	/* n = 4 */
  prod_n *= xi - x[i - r + 5];	/* n = 5 */
  prod_n *= xi - x[i - r + 8];	/* n = 8 */
  sum_m += prod_n;

  /* m = 8 */
  prod_n = 1.0;
  prod_n *= xi - x[i - r + 0];	/* n = 0 */
  prod_n *= xi - x[i - r + 1];	/* n = 1 */
  prod_n *= xi - x[i - r + 2];	/* n = 2 */
  prod_n *= xi - x[i - r + 3];	/* n = 3 */
  prod_n *= xi - x[i - r + 4];	/* n = 4 */
  prod_n *= xi - x[i - r + 5];	/* n = 5 */
  prod_n *= xi - x[i - r + 6];	/* n = 6 */
  sum_m += prod_n;

  prod_m = 1.0;
  prod_m *= x[i - r + 7] - x[i - r + 0];
  prod_m *= x[i - r + 7] - x[i - r + 1];
  prod_m *= x[i - r + 7] - x[i - r + 2];
  prod_m *= x[i - r + 7] - x[i - r + 3];
  prod_m *= x[i - r + 7] - x[i - r + 4];
  prod_m *= x[i - r + 7] - x[i - r + 5];
  prod_m *= x[i - r + 7] - x[i - r + 6];
  prod_m *= x[i - r + 7] - x[i - r + 8];

  sum_l += sum_m / prod_m * (x[i - r + 3 + 1] - x[i - r + 3]);

  /* l = 8 */
  sum_m = 0.0;

  /* m = 0 */
  prod_n = 1.0;
  prod_n *= xi - x[i - r + 1];	/* n = 1 */
  prod_n *= xi - x[i - r + 2];	/* n = 2 */
  prod_n *= xi - x[i - r + 3];	/* n = 3 */
  prod_n *= xi - x[i - r + 4];	/* n = 4 */
  prod_n *= xi - x[i - r + 5];	/* n = 5 */
  prod_n *= xi - x[i - r + 6];	/* n = 6 */
  prod_n *= xi - x[i - r + 7];	/* n = 7 */
  sum_m += prod_n;

  /* m = 1 */
  prod_n = 1.0;
  prod_n *= xi - x[i - r + 0];	/* n = 0 */
  prod_n *= xi - x[i - r + 2];	/* n = 2 */
  prod_n *= xi - x[i - r + 3];	/* n = 3 */
  prod_n *= xi - x[i - r + 4];	/* n = 4 */
  prod_n *= xi - x[i - r + 5];	/* n = 5 */
  prod_n *= xi - x[i - r + 6];	/* n = 6 */
  prod_n *= xi - x[i - r + 7];	/* n = 7 */
  sum_m += prod_n;

  /* m = 2 */
  prod_n = 1.0;
  prod_n *= xi - x[i - r + 0];	/* n = 0 */
  prod_n *= xi - x[i - r + 1];	/* n = 1 */
  prod_n *= xi - x[i - r + 3];	/* n = 3 */
  prod_n *= xi - x[i - r + 4];	/* n = 4 */
  prod_n *= xi - x[i - r + 5];	/* n = 5 */
  prod_n *= xi - x[i - r + 6];	/* n = 6 */
  prod_n *= xi - x[i - r + 7];	/* n = 7 */
  sum_m += prod_n;

  /* m = 3 */
  prod_n = 1.0;
  prod_n *= xi - x[i - r + 0];	/* n = 0 */
  prod_n *= xi - x[i - r + 1];	/* n = 1 */
  prod_n *= xi - x[i - r + 2];	/* n = 2 */
  prod_n *= xi - x[i - r + 4];	/* n = 4 */
  prod_n *= xi - x[i - r + 5];	/* n = 5 */
  prod_n *= xi - x[i - r + 6];	/* n = 6 */
  prod_n *= xi - x[i - r + 7];	/* n = 7 */
  sum_m += prod_n;

  /* m = 4 */
  prod_n = 1.0;
  prod_n *= xi - x[i - r + 0];	/* n = 0 */
  prod_n *= xi - x[i - r + 1];	/* n = 1 */
  prod_n *= xi - x[i - r + 2];	/* n = 2 */
  prod_n *= xi - x[i - r + 3];	/* n = 3 */
  prod_n *= xi - x[i - r + 5];	/* n = 5 */
  prod_n *= xi - x[i - r + 6];	/* n = 6 */
  prod_n *= xi - x[i - r + 7];	/* n = 7 */
  sum_m += prod_n;

  /* m = 5 */
  prod_n = 1.0;
  prod_n *= xi - x[i - r + 0];	/* n = 0 */
  prod_n *= xi - x[i - r + 1];	/* n = 1 */
  prod_n *= xi - x[i - r + 2];	/* n = 2 */
  prod_n *= xi - x[i - r + 3];	/* n = 3 */
  prod_n *= xi - x[i - r + 4];	/* n = 4 */
  prod_n *= xi - x[i - r + 6];	/* n = 6 */
  prod_n *= xi - x[i - r + 7];	/* n = 7 */
  sum_m += prod_n;

  /* m = 6 */
  prod_n = 1.0;
  prod_n *= xi - x[i - r + 0];	/* n = 0 */
  prod_n *= xi - x[i - r + 1];	/* n = 1 */
  prod_n *= xi - x[i - r + 2];	/* n = 2 */
  prod_n *= xi - x[i - r + 3];	/* n = 3 */
  prod_n *= xi - x[i - r + 4];	/* n = 4 */
  prod_n *= xi - x[i - r + 5];	/* n = 5 */
  prod_n *= xi - x[i - r + 7];	/* n = 7 */
  sum_m += prod_n;

  /* m = 7 */
  prod_n = 1.0;
  prod_n *= xi - x[i - r + 0];	/* n = 0 */
  prod_n *= xi - x[i - r + 1];	/* n = 1 */
  prod_n *= xi - x[i - r + 2];	/* n = 2 */
  prod_n *= xi - x[i - r + 3];	/* n = 3 */
  prod_n *= xi - x[i - r + 4];	/* n = 4 */
  prod_n *= xi - x[i - r + 5];	/* n = 5 */
  prod_n *= xi - x[i - r + 6];	/* n = 6 */
  sum_m += prod_n;

  prod_m = 1.0;
  prod_m *= x[i - r + 8] - x[i - r + 0];
  prod_m *= x[i - r + 8] - x[i - r + 1];
  prod_m *= x[i - r + 8] - x[i - r + 2];
  prod_m *= x[i - r + 8] - x[i - r + 3];
  prod_m *= x[i - r + 8] - x[i - r + 4];
  prod_m *= x[i - r + 8] - x[i - r + 5];
  prod_m *= x[i - r + 8] - x[i - r + 6];
  prod_m *= x[i - r + 8] - x[i - r + 7];

  sum_l += sum_m / prod_m * (x[i - r + 3 + 1] - x[i - r + 3]);

  c[3] = sum_l;
  /* j = 4 */
  sum_l = 0.0;

  /* l = 5 */
  sum_m = 0.0;

  /* m = 0 */
  prod_n = 1.0;
  prod_n *= xi - x[i - r + 1];	/* n = 1 */
  prod_n *= xi - x[i - r + 2];	/* n = 2 */
  prod_n *= xi - x[i - r + 3];	/* n = 3 */
  prod_n *= xi - x[i - r + 4];	/* n = 4 */
  prod_n *= xi - x[i - r + 6];	/* n = 6 */
  prod_n *= xi - x[i - r + 7];	/* n = 7 */
  prod_n *= xi - x[i - r + 8];	/* n = 8 */
  sum_m += prod_n;

  /* m = 1 */
  prod_n = 1.0;
  prod_n *= xi - x[i - r + 0];	/* n = 0 */
  prod_n *= xi - x[i - r + 2];	/* n = 2 */
  prod_n *= xi - x[i - r + 3];	/* n = 3 */
  prod_n *= xi - x[i - r + 4];	/* n = 4 */
  prod_n *= xi - x[i - r + 6];	/* n = 6 */
  prod_n *= xi - x[i - r + 7];	/* n = 7 */
  prod_n *= xi - x[i - r + 8];	/* n = 8 */
  sum_m += prod_n;

  /* m = 2 */
  prod_n = 1.0;
  prod_n *= xi - x[i - r + 0];	/* n = 0 */
  prod_n *= xi - x[i - r + 1];	/* n = 1 */
  prod_n *= xi - x[i - r + 3];	/* n = 3 */
  prod_n *= xi - x[i - r + 4];	/* n = 4 */
  prod_n *= xi - x[i - r + 6];	/* n = 6 */
  prod_n *= xi - x[i - r + 7];	/* n = 7 */
  prod_n *= xi - x[i - r + 8];	/* n = 8 */
  sum_m += prod_n;

  /* m = 3 */
  prod_n = 1.0;
  prod_n *= xi - x[i - r + 0];	/* n = 0 */
  prod_n *= xi - x[i - r + 1];	/* n = 1 */
  prod_n *= xi - x[i - r + 2];	/* n = 2 */
  prod_n *= xi - x[i - r + 4];	/* n = 4 */
  prod_n *= xi - x[i - r + 6];	/* n = 6 */
  prod_n *= xi - x[i - r + 7];	/* n = 7 */
  prod_n *= xi - x[i - r + 8];	/* n = 8 */
  sum_m += prod_n;

  /* m = 4 */
  prod_n = 1.0;
  prod_n *= xi - x[i - r + 0];	/* n = 0 */
  prod_n *= xi - x[i - r + 1];	/* n = 1 */
  prod_n *= xi - x[i - r + 2];	/* n = 2 */
  prod_n *= xi - x[i - r + 3];	/* n = 3 */
  prod_n *= xi - x[i - r + 6];	/* n = 6 */
  prod_n *= xi - x[i - r + 7];	/* n = 7 */
  prod_n *= xi - x[i - r + 8];	/* n = 8 */
  sum_m += prod_n;

  /* m = 6 */
  prod_n = 1.0;
  prod_n *= xi - x[i - r + 0];	/* n = 0 */
  prod_n *= xi - x[i - r + 1];	/* n = 1 */
  prod_n *= xi - x[i - r + 2];	/* n = 2 */
  prod_n *= xi - x[i - r + 3];	/* n = 3 */
  prod_n *= xi - x[i - r + 4];	/* n = 4 */
  prod_n *= xi - x[i - r + 7];	/* n = 7 */
  prod_n *= xi - x[i - r + 8];	/* n = 8 */
  sum_m += prod_n;

  /* m = 7 */
  prod_n = 1.0;
  prod_n *= xi - x[i - r + 0];	/* n = 0 */
  prod_n *= xi - x[i - r + 1];	/* n = 1 */
  prod_n *= xi - x[i - r + 2];	/* n = 2 */
  prod_n *= xi - x[i - r + 3];	/* n = 3 */
  prod_n *= xi - x[i - r + 4];	/* n = 4 */
  prod_n *= xi - x[i - r + 6];	/* n = 6 */
  prod_n *= xi - x[i - r + 8];	/* n = 8 */
  sum_m += prod_n;

  /* m = 8 */
  prod_n = 1.0;
  prod_n *= xi - x[i - r + 0];	/* n = 0 */
  prod_n *= xi - x[i - r + 1];	/* n = 1 */
  prod_n *= xi - x[i - r + 2];	/* n = 2 */
  prod_n *= xi - x[i - r + 3];	/* n = 3 */
  prod_n *= xi - x[i - r + 4];	/* n = 4 */
  prod_n *= xi - x[i - r + 6];	/* n = 6 */
  prod_n *= xi - x[i - r + 7];	/* n = 7 */
  sum_m += prod_n;

  prod_m = 1.0;
  prod_m *= x[i - r + 5] - x[i - r + 0];
  prod_m *= x[i - r + 5] - x[i - r + 1];
  prod_m *= x[i - r + 5] - x[i - r + 2];
  prod_m *= x[i - r + 5] - x[i - r + 3];
  prod_m *= x[i - r + 5] - x[i - r + 4];
  prod_m *= x[i - r + 5] - x[i - r + 6];
  prod_m *= x[i - r + 5] - x[i - r + 7];
  prod_m *= x[i - r + 5] - x[i - r + 8];

  sum_l += sum_m / prod_m * (x[i - r + 4 + 1] - x[i - r + 4]);

  /* l = 6 */
  sum_m = 0.0;

  /* m = 0 */
  prod_n = 1.0;
  prod_n *= xi - x[i - r + 1];	/* n = 1 */
  prod_n *= xi - x[i - r + 2];	/* n = 2 */
  prod_n *= xi - x[i - r + 3];	/* n = 3 */
  prod_n *= xi - x[i - r + 4];	/* n = 4 */
  prod_n *= xi - x[i - r + 5];	/* n = 5 */
  prod_n *= xi - x[i - r + 7];	/* n = 7 */
  prod_n *= xi - x[i - r + 8];	/* n = 8 */
  sum_m += prod_n;

  /* m = 1 */
  prod_n = 1.0;
  prod_n *= xi - x[i - r + 0];	/* n = 0 */
  prod_n *= xi - x[i - r + 2];	/* n = 2 */
  prod_n *= xi - x[i - r + 3];	/* n = 3 */
  prod_n *= xi - x[i - r + 4];	/* n = 4 */
  prod_n *= xi - x[i - r + 5];	/* n = 5 */
  prod_n *= xi - x[i - r + 7];	/* n = 7 */
  prod_n *= xi - x[i - r + 8];	/* n = 8 */
  sum_m += prod_n;

  /* m = 2 */
  prod_n = 1.0;
  prod_n *= xi - x[i - r + 0];	/* n = 0 */
  prod_n *= xi - x[i - r + 1];	/* n = 1 */
  prod_n *= xi - x[i - r + 3];	/* n = 3 */
  prod_n *= xi - x[i - r + 4];	/* n = 4 */
  prod_n *= xi - x[i - r + 5];	/* n = 5 */
  prod_n *= xi - x[i - r + 7];	/* n = 7 */
  prod_n *= xi - x[i - r + 8];	/* n = 8 */
  sum_m += prod_n;

  /* m = 3 */
  prod_n = 1.0;
  prod_n *= xi - x[i - r + 0];	/* n = 0 */
  prod_n *= xi - x[i - r + 1];	/* n = 1 */
  prod_n *= xi - x[i - r + 2];	/* n = 2 */
  prod_n *= xi - x[i - r + 4];	/* n = 4 */
  prod_n *= xi - x[i - r + 5];	/* n = 5 */
  prod_n *= xi - x[i - r + 7];	/* n = 7 */
  prod_n *= xi - x[i - r + 8];	/* n = 8 */
  sum_m += prod_n;

  /* m = 4 */
  prod_n = 1.0;
  prod_n *= xi - x[i - r + 0];	/* n = 0 */
  prod_n *= xi - x[i - r + 1];	/* n = 1 */
  prod_n *= xi - x[i - r + 2];	/* n = 2 */
  prod_n *= xi - x[i - r + 3];	/* n = 3 */
  prod_n *= xi - x[i - r + 5];	/* n = 5 */
  prod_n *= xi - x[i - r + 7];	/* n = 7 */
  prod_n *= xi - x[i - r + 8];	/* n = 8 */
  sum_m += prod_n;

  /* m = 5 */
  prod_n = 1.0;
  prod_n *= xi - x[i - r + 0];	/* n = 0 */
  prod_n *= xi - x[i - r + 1];	/* n = 1 */
  prod_n *= xi - x[i - r + 2];	/* n = 2 */
  prod_n *= xi - x[i - r + 3];	/* n = 3 */
  prod_n *= xi - x[i - r + 4];	/* n = 4 */
  prod_n *= xi - x[i - r + 7];	/* n = 7 */
  prod_n *= xi - x[i - r + 8];	/* n = 8 */
  sum_m += prod_n;

  /* m = 7 */
  prod_n = 1.0;
  prod_n *= xi - x[i - r + 0];	/* n = 0 */
  prod_n *= xi - x[i - r + 1];	/* n = 1 */
  prod_n *= xi - x[i - r + 2];	/* n = 2 */
  prod_n *= xi - x[i - r + 3];	/* n = 3 */
  prod_n *= xi - x[i - r + 4];	/* n = 4 */
  prod_n *= xi - x[i - r + 5];	/* n = 5 */
  prod_n *= xi - x[i - r + 8];	/* n = 8 */
  sum_m += prod_n;

  /* m = 8 */
  prod_n = 1.0;
  prod_n *= xi - x[i - r + 0];	/* n = 0 */
  prod_n *= xi - x[i - r + 1];	/* n = 1 */
  prod_n *= xi - x[i - r + 2];	/* n = 2 */
  prod_n *= xi - x[i - r + 3];	/* n = 3 */
  prod_n *= xi - x[i - r + 4];	/* n = 4 */
  prod_n *= xi - x[i - r + 5];	/* n = 5 */
  prod_n *= xi - x[i - r + 7];	/* n = 7 */
  sum_m += prod_n;

  prod_m = 1.0;
  prod_m *= x[i - r + 6] - x[i - r + 0];
  prod_m *= x[i - r + 6] - x[i - r + 1];
  prod_m *= x[i - r + 6] - x[i - r + 2];
  prod_m *= x[i - r + 6] - x[i - r + 3];
  prod_m *= x[i - r + 6] - x[i - r + 4];
  prod_m *= x[i - r + 6] - x[i - r + 5];
  prod_m *= x[i - r + 6] - x[i - r + 7];
  prod_m *= x[i - r + 6] - x[i - r + 8];

  sum_l += sum_m / prod_m * (x[i - r + 4 + 1] - x[i - r + 4]);

  /* l = 7 */
  sum_m = 0.0;

  /* m = 0 */
  prod_n = 1.0;
  prod_n *= xi - x[i - r + 1];	/* n = 1 */
  prod_n *= xi - x[i - r + 2];	/* n = 2 */
  prod_n *= xi - x[i - r + 3];	/* n = 3 */
  prod_n *= xi - x[i - r + 4];	/* n = 4 */
  prod_n *= xi - x[i - r + 5];	/* n = 5 */
  prod_n *= xi - x[i - r + 6];	/* n = 6 */
  prod_n *= xi - x[i - r + 8];	/* n = 8 */
  sum_m += prod_n;

  /* m = 1 */
  prod_n = 1.0;
  prod_n *= xi - x[i - r + 0];	/* n = 0 */
  prod_n *= xi - x[i - r + 2];	/* n = 2 */
  prod_n *= xi - x[i - r + 3];	/* n = 3 */
  prod_n *= xi - x[i - r + 4];	/* n = 4 */
  prod_n *= xi - x[i - r + 5];	/* n = 5 */
  prod_n *= xi - x[i - r + 6];	/* n = 6 */
  prod_n *= xi - x[i - r + 8];	/* n = 8 */
  sum_m += prod_n;

  /* m = 2 */
  prod_n = 1.0;
  prod_n *= xi - x[i - r + 0];	/* n = 0 */
  prod_n *= xi - x[i - r + 1];	/* n = 1 */
  prod_n *= xi - x[i - r + 3];	/* n = 3 */
  prod_n *= xi - x[i - r + 4];	/* n = 4 */
  prod_n *= xi - x[i - r + 5];	/* n = 5 */
  prod_n *= xi - x[i - r + 6];	/* n = 6 */
  prod_n *= xi - x[i - r + 8];	/* n = 8 */
  sum_m += prod_n;

  /* m = 3 */
  prod_n = 1.0;
  prod_n *= xi - x[i - r + 0];	/* n = 0 */
  prod_n *= xi - x[i - r + 1];	/* n = 1 */
  prod_n *= xi - x[i - r + 2];	/* n = 2 */
  prod_n *= xi - x[i - r + 4];	/* n = 4 */
  prod_n *= xi - x[i - r + 5];	/* n = 5 */
  prod_n *= xi - x[i - r + 6];	/* n = 6 */
  prod_n *= xi - x[i - r + 8];	/* n = 8 */
  sum_m += prod_n;

  /* m = 4 */
  prod_n = 1.0;
  prod_n *= xi - x[i - r + 0];	/* n = 0 */
  prod_n *= xi - x[i - r + 1];	/* n = 1 */
  prod_n *= xi - x[i - r + 2];	/* n = 2 */
  prod_n *= xi - x[i - r + 3];	/* n = 3 */
  prod_n *= xi - x[i - r + 5];	/* n = 5 */
  prod_n *= xi - x[i - r + 6];	/* n = 6 */
  prod_n *= xi - x[i - r + 8];	/* n = 8 */
  sum_m += prod_n;

  /* m = 5 */
  prod_n = 1.0;
  prod_n *= xi - x[i - r + 0];	/* n = 0 */
  prod_n *= xi - x[i - r + 1];	/* n = 1 */
  prod_n *= xi - x[i - r + 2];	/* n = 2 */
  prod_n *= xi - x[i - r + 3];	/* n = 3 */
  prod_n *= xi - x[i - r + 4];	/* n = 4 */
  prod_n *= xi - x[i - r + 6];	/* n = 6 */
  prod_n *= xi - x[i - r + 8];	/* n = 8 */
  sum_m += prod_n;

  /* m = 6 */
  prod_n = 1.0;
  prod_n *= xi - x[i - r + 0];	/* n = 0 */
  prod_n *= xi - x[i - r + 1];	/* n = 1 */
  prod_n *= xi - x[i - r + 2];	/* n = 2 */
  prod_n *= xi - x[i - r + 3];	/* n = 3 */
  prod_n *= xi - x[i - r + 4];	/* n = 4 */
  prod_n *= xi - x[i - r + 5];	/* n = 5 */
  prod_n *= xi - x[i - r + 8];	/* n = 8 */
  sum_m += prod_n;

  /* m = 8 */
  prod_n = 1.0;
  prod_n *= xi - x[i - r + 0];	/* n = 0 */
  prod_n *= xi - x[i - r + 1];	/* n = 1 */
  prod_n *= xi - x[i - r + 2];	/* n = 2 */
  prod_n *= xi - x[i - r + 3];	/* n = 3 */
  prod_n *= xi - x[i - r + 4];	/* n = 4 */
  prod_n *= xi - x[i - r + 5];	/* n = 5 */
  prod_n *= xi - x[i - r + 6];	/* n = 6 */
  sum_m += prod_n;

  prod_m = 1.0;
  prod_m *= x[i - r + 7] - x[i - r + 0];
  prod_m *= x[i - r + 7] - x[i - r + 1];
  prod_m *= x[i - r + 7] - x[i - r + 2];
  prod_m *= x[i - r + 7] - x[i - r + 3];
  prod_m *= x[i - r + 7] - x[i - r + 4];
  prod_m *= x[i - r + 7] - x[i - r + 5];
  prod_m *= x[i - r + 7] - x[i - r + 6];
  prod_m *= x[i - r + 7] - x[i - r + 8];

  sum_l += sum_m / prod_m * (x[i - r + 4 + 1] - x[i - r + 4]);

  /* l = 8 */
  sum_m = 0.0;

  /* m = 0 */
  prod_n = 1.0;
  prod_n *= xi - x[i - r + 1];	/* n = 1 */
  prod_n *= xi - x[i - r + 2];	/* n = 2 */
  prod_n *= xi - x[i - r + 3];	/* n = 3 */
  prod_n *= xi - x[i - r + 4];	/* n = 4 */
  prod_n *= xi - x[i - r + 5];	/* n = 5 */
  prod_n *= xi - x[i - r + 6];	/* n = 6 */
  prod_n *= xi - x[i - r + 7];	/* n = 7 */
  sum_m += prod_n;

  /* m = 1 */
  prod_n = 1.0;
  prod_n *= xi - x[i - r + 0];	/* n = 0 */
  prod_n *= xi - x[i - r + 2];	/* n = 2 */
  prod_n *= xi - x[i - r + 3];	/* n = 3 */
  prod_n *= xi - x[i - r + 4];	/* n = 4 */
  prod_n *= xi - x[i - r + 5];	/* n = 5 */
  prod_n *= xi - x[i - r + 6];	/* n = 6 */
  prod_n *= xi - x[i - r + 7];	/* n = 7 */
  sum_m += prod_n;

  /* m = 2 */
  prod_n = 1.0;
  prod_n *= xi - x[i - r + 0];	/* n = 0 */
  prod_n *= xi - x[i - r + 1];	/* n = 1 */
  prod_n *= xi - x[i - r + 3];	/* n = 3 */
  prod_n *= xi - x[i - r + 4];	/* n = 4 */
  prod_n *= xi - x[i - r + 5];	/* n = 5 */
  prod_n *= xi - x[i - r + 6];	/* n = 6 */
  prod_n *= xi - x[i - r + 7];	/* n = 7 */
  sum_m += prod_n;

  /* m = 3 */
  prod_n = 1.0;
  prod_n *= xi - x[i - r + 0];	/* n = 0 */
  prod_n *= xi - x[i - r + 1];	/* n = 1 */
  prod_n *= xi - x[i - r + 2];	/* n = 2 */
  prod_n *= xi - x[i - r + 4];	/* n = 4 */
  prod_n *= xi - x[i - r + 5];	/* n = 5 */
  prod_n *= xi - x[i - r + 6];	/* n = 6 */
  prod_n *= xi - x[i - r + 7];	/* n = 7 */
  sum_m += prod_n;

  /* m = 4 */
  prod_n = 1.0;
  prod_n *= xi - x[i - r + 0];	/* n = 0 */
  prod_n *= xi - x[i - r + 1];	/* n = 1 */
  prod_n *= xi - x[i - r + 2];	/* n = 2 */
  prod_n *= xi - x[i - r + 3];	/* n = 3 */
  prod_n *= xi - x[i - r + 5];	/* n = 5 */
  prod_n *= xi - x[i - r + 6];	/* n = 6 */
  prod_n *= xi - x[i - r + 7];	/* n = 7 */
  sum_m += prod_n;

  /* m = 5 */
  prod_n = 1.0;
  prod_n *= xi - x[i - r + 0];	/* n = 0 */
  prod_n *= xi - x[i - r + 1];	/* n = 1 */
  prod_n *= xi - x[i - r + 2];	/* n = 2 */
  prod_n *= xi - x[i - r + 3];	/* n = 3 */
  prod_n *= xi - x[i - r + 4];	/* n = 4 */
  prod_n *= xi - x[i - r + 6];	/* n = 6 */
  prod_n *= xi - x[i - r + 7];	/* n = 7 */
  sum_m += prod_n;

  /* m = 6 */
  prod_n = 1.0;
  prod_n *= xi - x[i - r + 0];	/* n = 0 */
  prod_n *= xi - x[i - r + 1];	/* n = 1 */
  prod_n *= xi - x[i - r + 2];	/* n = 2 */
  prod_n *= xi - x[i - r + 3];	/* n = 3 */
  prod_n *= xi - x[i - r + 4];	/* n = 4 */
  prod_n *= xi - x[i - r + 5];	/* n = 5 */
  prod_n *= xi - x[i - r + 7];	/* n = 7 */
  sum_m += prod_n;

  /* m = 7 */
  prod_n = 1.0;
  prod_n *= xi - x[i - r + 0];	/* n = 0 */
  prod_n *= xi - x[i - r + 1];	/* n = 1 */
  prod_n *= xi - x[i - r + 2];	/* n = 2 */
  prod_n *= xi - x[i - r + 3];	/* n = 3 */
  prod_n *= xi - x[i - r + 4];	/* n = 4 */
  prod_n *= xi - x[i - r + 5];	/* n = 5 */
  prod_n *= xi - x[i - r + 6];	/* n = 6 */
  sum_m += prod_n;

  prod_m = 1.0;
  prod_m *= x[i - r + 8] - x[i - r + 0];
  prod_m *= x[i - r + 8] - x[i - r + 1];
  prod_m *= x[i - r + 8] - x[i - r + 2];
  prod_m *= x[i - r + 8] - x[i - r + 3];
  prod_m *= x[i - r + 8] - x[i - r + 4];
  prod_m *= x[i - r + 8] - x[i - r + 5];
  prod_m *= x[i - r + 8] - x[i - r + 6];
  prod_m *= x[i - r + 8] - x[i - r + 7];

  sum_l += sum_m / prod_m * (x[i - r + 4 + 1] - x[i - r + 4]);

  c[4] = sum_l;
  /* j = 5 */
  sum_l = 0.0;

  /* l = 6 */
  sum_m = 0.0;

  /* m = 0 */
  prod_n = 1.0;
  prod_n *= xi - x[i - r + 1];	/* n = 1 */
  prod_n *= xi - x[i - r + 2];	/* n = 2 */
  prod_n *= xi - x[i - r + 3];	/* n = 3 */
  prod_n *= xi - x[i - r + 4];	/* n = 4 */
  prod_n *= xi - x[i - r + 5];	/* n = 5 */
  prod_n *= xi - x[i - r + 7];	/* n = 7 */
  prod_n *= xi - x[i - r + 8];	/* n = 8 */
  sum_m += prod_n;

  /* m = 1 */
  prod_n = 1.0;
  prod_n *= xi - x[i - r + 0];	/* n = 0 */
  prod_n *= xi - x[i - r + 2];	/* n = 2 */
  prod_n *= xi - x[i - r + 3];	/* n = 3 */
  prod_n *= xi - x[i - r + 4];	/* n = 4 */
  prod_n *= xi - x[i - r + 5];	/* n = 5 */
  prod_n *= xi - x[i - r + 7];	/* n = 7 */
  prod_n *= xi - x[i - r + 8];	/* n = 8 */
  sum_m += prod_n;

  /* m = 2 */
  prod_n = 1.0;
  prod_n *= xi - x[i - r + 0];	/* n = 0 */
  prod_n *= xi - x[i - r + 1];	/* n = 1 */
  prod_n *= xi - x[i - r + 3];	/* n = 3 */
  prod_n *= xi - x[i - r + 4];	/* n = 4 */
  prod_n *= xi - x[i - r + 5];	/* n = 5 */
  prod_n *= xi - x[i - r + 7];	/* n = 7 */
  prod_n *= xi - x[i - r + 8];	/* n = 8 */
  sum_m += prod_n;

  /* m = 3 */
  prod_n = 1.0;
  prod_n *= xi - x[i - r + 0];	/* n = 0 */
  prod_n *= xi - x[i - r + 1];	/* n = 1 */
  prod_n *= xi - x[i - r + 2];	/* n = 2 */
  prod_n *= xi - x[i - r + 4];	/* n = 4 */
  prod_n *= xi - x[i - r + 5];	/* n = 5 */
  prod_n *= xi - x[i - r + 7];	/* n = 7 */
  prod_n *= xi - x[i - r + 8];	/* n = 8 */
  sum_m += prod_n;

  /* m = 4 */
  prod_n = 1.0;
  prod_n *= xi - x[i - r + 0];	/* n = 0 */
  prod_n *= xi - x[i - r + 1];	/* n = 1 */
  prod_n *= xi - x[i - r + 2];	/* n = 2 */
  prod_n *= xi - x[i - r + 3];	/* n = 3 */
  prod_n *= xi - x[i - r + 5];	/* n = 5 */
  prod_n *= xi - x[i - r + 7];	/* n = 7 */
  prod_n *= xi - x[i - r + 8];	/* n = 8 */
  sum_m += prod_n;

  /* m = 5 */
  prod_n = 1.0;
  prod_n *= xi - x[i - r + 0];	/* n = 0 */
  prod_n *= xi - x[i - r + 1];	/* n = 1 */
  prod_n *= xi - x[i - r + 2];	/* n = 2 */
  prod_n *= xi - x[i - r + 3];	/* n = 3 */
  prod_n *= xi - x[i - r + 4];	/* n = 4 */
  prod_n *= xi - x[i - r + 7];	/* n = 7 */
  prod_n *= xi - x[i - r + 8];	/* n = 8 */
  sum_m += prod_n;

  /* m = 7 */
  prod_n = 1.0;
  prod_n *= xi - x[i - r + 0];	/* n = 0 */
  prod_n *= xi - x[i - r + 1];	/* n = 1 */
  prod_n *= xi - x[i - r + 2];	/* n = 2 */
  prod_n *= xi - x[i - r + 3];	/* n = 3 */
  prod_n *= xi - x[i - r + 4];	/* n = 4 */
  prod_n *= xi - x[i - r + 5];	/* n = 5 */
  prod_n *= xi - x[i - r + 8];	/* n = 8 */
  sum_m += prod_n;

  /* m = 8 */
  prod_n = 1.0;
  prod_n *= xi - x[i - r + 0];	/* n = 0 */
  prod_n *= xi - x[i - r + 1];	/* n = 1 */
  prod_n *= xi - x[i - r + 2];	/* n = 2 */
  prod_n *= xi - x[i - r + 3];	/* n = 3 */
  prod_n *= xi - x[i - r + 4];	/* n = 4 */
  prod_n *= xi - x[i - r + 5];	/* n = 5 */
  prod_n *= xi - x[i - r + 7];	/* n = 7 */
  sum_m += prod_n;

  prod_m = 1.0;
  prod_m *= x[i - r + 6] - x[i - r + 0];
  prod_m *= x[i - r + 6] - x[i - r + 1];
  prod_m *= x[i - r + 6] - x[i - r + 2];
  prod_m *= x[i - r + 6] - x[i - r + 3];
  prod_m *= x[i - r + 6] - x[i - r + 4];
  prod_m *= x[i - r + 6] - x[i - r + 5];
  prod_m *= x[i - r + 6] - x[i - r + 7];
  prod_m *= x[i - r + 6] - x[i - r + 8];

  sum_l += sum_m / prod_m * (x[i - r + 5 + 1] - x[i - r + 5]);

  /* l = 7 */
  sum_m = 0.0;

  /* m = 0 */
  prod_n = 1.0;
  prod_n *= xi - x[i - r + 1];	/* n = 1 */
  prod_n *= xi - x[i - r + 2];	/* n = 2 */
  prod_n *= xi - x[i - r + 3];	/* n = 3 */
  prod_n *= xi - x[i - r + 4];	/* n = 4 */
  prod_n *= xi - x[i - r + 5];	/* n = 5 */
  prod_n *= xi - x[i - r + 6];	/* n = 6 */
  prod_n *= xi - x[i - r + 8];	/* n = 8 */
  sum_m += prod_n;

  /* m = 1 */
  prod_n = 1.0;
  prod_n *= xi - x[i - r + 0];	/* n = 0 */
  prod_n *= xi - x[i - r + 2];	/* n = 2 */
  prod_n *= xi - x[i - r + 3];	/* n = 3 */
  prod_n *= xi - x[i - r + 4];	/* n = 4 */
  prod_n *= xi - x[i - r + 5];	/* n = 5 */
  prod_n *= xi - x[i - r + 6];	/* n = 6 */
  prod_n *= xi - x[i - r + 8];	/* n = 8 */
  sum_m += prod_n;

  /* m = 2 */
  prod_n = 1.0;
  prod_n *= xi - x[i - r + 0];	/* n = 0 */
  prod_n *= xi - x[i - r + 1];	/* n = 1 */
  prod_n *= xi - x[i - r + 3];	/* n = 3 */
  prod_n *= xi - x[i - r + 4];	/* n = 4 */
  prod_n *= xi - x[i - r + 5];	/* n = 5 */
  prod_n *= xi - x[i - r + 6];	/* n = 6 */
  prod_n *= xi - x[i - r + 8];	/* n = 8 */
  sum_m += prod_n;

  /* m = 3 */
  prod_n = 1.0;
  prod_n *= xi - x[i - r + 0];	/* n = 0 */
  prod_n *= xi - x[i - r + 1];	/* n = 1 */
  prod_n *= xi - x[i - r + 2];	/* n = 2 */
  prod_n *= xi - x[i - r + 4];	/* n = 4 */
  prod_n *= xi - x[i - r + 5];	/* n = 5 */
  prod_n *= xi - x[i - r + 6];	/* n = 6 */
  prod_n *= xi - x[i - r + 8];	/* n = 8 */
  sum_m += prod_n;

  /* m = 4 */
  prod_n = 1.0;
  prod_n *= xi - x[i - r + 0];	/* n = 0 */
  prod_n *= xi - x[i - r + 1];	/* n = 1 */
  prod_n *= xi - x[i - r + 2];	/* n = 2 */
  prod_n *= xi - x[i - r + 3];	/* n = 3 */
  prod_n *= xi - x[i - r + 5];	/* n = 5 */
  prod_n *= xi - x[i - r + 6];	/* n = 6 */
  prod_n *= xi - x[i - r + 8];	/* n = 8 */
  sum_m += prod_n;

  /* m = 5 */
  prod_n = 1.0;
  prod_n *= xi - x[i - r + 0];	/* n = 0 */
  prod_n *= xi - x[i - r + 1];	/* n = 1 */
  prod_n *= xi - x[i - r + 2];	/* n = 2 */
  prod_n *= xi - x[i - r + 3];	/* n = 3 */
  prod_n *= xi - x[i - r + 4];	/* n = 4 */
  prod_n *= xi - x[i - r + 6];	/* n = 6 */
  prod_n *= xi - x[i - r + 8];	/* n = 8 */
  sum_m += prod_n;

  /* m = 6 */
  prod_n = 1.0;
  prod_n *= xi - x[i - r + 0];	/* n = 0 */
  prod_n *= xi - x[i - r + 1];	/* n = 1 */
  prod_n *= xi - x[i - r + 2];	/* n = 2 */
  prod_n *= xi - x[i - r + 3];	/* n = 3 */
  prod_n *= xi - x[i - r + 4];	/* n = 4 */
  prod_n *= xi - x[i - r + 5];	/* n = 5 */
  prod_n *= xi - x[i - r + 8];	/* n = 8 */
  sum_m += prod_n;

  /* m = 8 */
  prod_n = 1.0;
  prod_n *= xi - x[i - r + 0];	/* n = 0 */
  prod_n *= xi - x[i - r + 1];	/* n = 1 */
  prod_n *= xi - x[i - r + 2];	/* n = 2 */
  prod_n *= xi - x[i - r + 3];	/* n = 3 */
  prod_n *= xi - x[i - r + 4];	/* n = 4 */
  prod_n *= xi - x[i - r + 5];	/* n = 5 */
  prod_n *= xi - x[i - r + 6];	/* n = 6 */
  sum_m += prod_n;

  prod_m = 1.0;
  prod_m *= x[i - r + 7] - x[i - r + 0];
  prod_m *= x[i - r + 7] - x[i - r + 1];
  prod_m *= x[i - r + 7] - x[i - r + 2];
  prod_m *= x[i - r + 7] - x[i - r + 3];
  prod_m *= x[i - r + 7] - x[i - r + 4];
  prod_m *= x[i - r + 7] - x[i - r + 5];
  prod_m *= x[i - r + 7] - x[i - r + 6];
  prod_m *= x[i - r + 7] - x[i - r + 8];

  sum_l += sum_m / prod_m * (x[i - r + 5 + 1] - x[i - r + 5]);

  /* l = 8 */
  sum_m = 0.0;

  /* m = 0 */
  prod_n = 1.0;
  prod_n *= xi - x[i - r + 1];	/* n = 1 */
  prod_n *= xi - x[i - r + 2];	/* n = 2 */
  prod_n *= xi - x[i - r + 3];	/* n = 3 */
  prod_n *= xi - x[i - r + 4];	/* n = 4 */
  prod_n *= xi - x[i - r + 5];	/* n = 5 */
  prod_n *= xi - x[i - r + 6];	/* n = 6 */
  prod_n *= xi - x[i - r + 7];	/* n = 7 */
  sum_m += prod_n;

  /* m = 1 */
  prod_n = 1.0;
  prod_n *= xi - x[i - r + 0];	/* n = 0 */
  prod_n *= xi - x[i - r + 2];	/* n = 2 */
  prod_n *= xi - x[i - r + 3];	/* n = 3 */
  prod_n *= xi - x[i - r + 4];	/* n = 4 */
  prod_n *= xi - x[i - r + 5];	/* n = 5 */
  prod_n *= xi - x[i - r + 6];	/* n = 6 */
  prod_n *= xi - x[i - r + 7];	/* n = 7 */
  sum_m += prod_n;

  /* m = 2 */
  prod_n = 1.0;
  prod_n *= xi - x[i - r + 0];	/* n = 0 */
  prod_n *= xi - x[i - r + 1];	/* n = 1 */
  prod_n *= xi - x[i - r + 3];	/* n = 3 */
  prod_n *= xi - x[i - r + 4];	/* n = 4 */
  prod_n *= xi - x[i - r + 5];	/* n = 5 */
  prod_n *= xi - x[i - r + 6];	/* n = 6 */
  prod_n *= xi - x[i - r + 7];	/* n = 7 */
  sum_m += prod_n;

  /* m = 3 */
  prod_n = 1.0;
  prod_n *= xi - x[i - r + 0];	/* n = 0 */
  prod_n *= xi - x[i - r + 1];	/* n = 1 */
  prod_n *= xi - x[i - r + 2];	/* n = 2 */
  prod_n *= xi - x[i - r + 4];	/* n = 4 */
  prod_n *= xi - x[i - r + 5];	/* n = 5 */
  prod_n *= xi - x[i - r + 6];	/* n = 6 */
  prod_n *= xi - x[i - r + 7];	/* n = 7 */
  sum_m += prod_n;

  /* m = 4 */
  prod_n = 1.0;
  prod_n *= xi - x[i - r + 0];	/* n = 0 */
  prod_n *= xi - x[i - r + 1];	/* n = 1 */
  prod_n *= xi - x[i - r + 2];	/* n = 2 */
  prod_n *= xi - x[i - r + 3];	/* n = 3 */
  prod_n *= xi - x[i - r + 5];	/* n = 5 */
  prod_n *= xi - x[i - r + 6];	/* n = 6 */
  prod_n *= xi - x[i - r + 7];	/* n = 7 */
  sum_m += prod_n;

  /* m = 5 */
  prod_n = 1.0;
  prod_n *= xi - x[i - r + 0];	/* n = 0 */
  prod_n *= xi - x[i - r + 1];	/* n = 1 */
  prod_n *= xi - x[i - r + 2];	/* n = 2 */
  prod_n *= xi - x[i - r + 3];	/* n = 3 */
  prod_n *= xi - x[i - r + 4];	/* n = 4 */
  prod_n *= xi - x[i - r + 6];	/* n = 6 */
  prod_n *= xi - x[i - r + 7];	/* n = 7 */
  sum_m += prod_n;

  /* m = 6 */
  prod_n = 1.0;
  prod_n *= xi - x[i - r + 0];	/* n = 0 */
  prod_n *= xi - x[i - r + 1];	/* n = 1 */
  prod_n *= xi - x[i - r + 2];	/* n = 2 */
  prod_n *= xi - x[i - r + 3];	/* n = 3 */
  prod_n *= xi - x[i - r + 4];	/* n = 4 */
  prod_n *= xi - x[i - r + 5];	/* n = 5 */
  prod_n *= xi - x[i - r + 7];	/* n = 7 */
  sum_m += prod_n;

  /* m = 7 */
  prod_n = 1.0;
  prod_n *= xi - x[i - r + 0];	/* n = 0 */
  prod_n *= xi - x[i - r + 1];	/* n = 1 */
  prod_n *= xi - x[i - r + 2];	/* n = 2 */
  prod_n *= xi - x[i - r + 3];	/* n = 3 */
  prod_n *= xi - x[i - r + 4];	/* n = 4 */
  prod_n *= xi - x[i - r + 5];	/* n = 5 */
  prod_n *= xi - x[i - r + 6];	/* n = 6 */
  sum_m += prod_n;

  prod_m = 1.0;
  prod_m *= x[i - r + 8] - x[i - r + 0];
  prod_m *= x[i - r + 8] - x[i - r + 1];
  prod_m *= x[i - r + 8] - x[i - r + 2];
  prod_m *= x[i - r + 8] - x[i - r + 3];
  prod_m *= x[i - r + 8] - x[i - r + 4];
  prod_m *= x[i - r + 8] - x[i - r + 5];
  prod_m *= x[i - r + 8] - x[i - r + 6];
  prod_m *= x[i - r + 8] - x[i - r + 7];

  sum_l += sum_m / prod_m * (x[i - r + 5 + 1] - x[i - r + 5]);

  c[5] = sum_l;
  /* j = 6 */
  sum_l = 0.0;

  /* l = 7 */
  sum_m = 0.0;

  /* m = 0 */
  prod_n = 1.0;
  prod_n *= xi - x[i - r + 1];	/* n = 1 */
  prod_n *= xi - x[i - r + 2];	/* n = 2 */
  prod_n *= xi - x[i - r + 3];	/* n = 3 */
  prod_n *= xi - x[i - r + 4];	/* n = 4 */
  prod_n *= xi - x[i - r + 5];	/* n = 5 */
  prod_n *= xi - x[i - r + 6];	/* n = 6 */
  prod_n *= xi - x[i - r + 8];	/* n = 8 */
  sum_m += prod_n;

  /* m = 1 */
  prod_n = 1.0;
  prod_n *= xi - x[i - r + 0];	/* n = 0 */
  prod_n *= xi - x[i - r + 2];	/* n = 2 */
  prod_n *= xi - x[i - r + 3];	/* n = 3 */
  prod_n *= xi - x[i - r + 4];	/* n = 4 */
  prod_n *= xi - x[i - r + 5];	/* n = 5 */
  prod_n *= xi - x[i - r + 6];	/* n = 6 */
  prod_n *= xi - x[i - r + 8];	/* n = 8 */
  sum_m += prod_n;

  /* m = 2 */
  prod_n = 1.0;
  prod_n *= xi - x[i - r + 0];	/* n = 0 */
  prod_n *= xi - x[i - r + 1];	/* n = 1 */
  prod_n *= xi - x[i - r + 3];	/* n = 3 */
  prod_n *= xi - x[i - r + 4];	/* n = 4 */
  prod_n *= xi - x[i - r + 5];	/* n = 5 */
  prod_n *= xi - x[i - r + 6];	/* n = 6 */
  prod_n *= xi - x[i - r + 8];	/* n = 8 */
  sum_m += prod_n;

  /* m = 3 */
  prod_n = 1.0;
  prod_n *= xi - x[i - r + 0];	/* n = 0 */
  prod_n *= xi - x[i - r + 1];	/* n = 1 */
  prod_n *= xi - x[i - r + 2];	/* n = 2 */
  prod_n *= xi - x[i - r + 4];	/* n = 4 */
  prod_n *= xi - x[i - r + 5];	/* n = 5 */
  prod_n *= xi - x[i - r + 6];	/* n = 6 */
  prod_n *= xi - x[i - r + 8];	/* n = 8 */
  sum_m += prod_n;

  /* m = 4 */
  prod_n = 1.0;
  prod_n *= xi - x[i - r + 0];	/* n = 0 */
  prod_n *= xi - x[i - r + 1];	/* n = 1 */
  prod_n *= xi - x[i - r + 2];	/* n = 2 */
  prod_n *= xi - x[i - r + 3];	/* n = 3 */
  prod_n *= xi - x[i - r + 5];	/* n = 5 */
  prod_n *= xi - x[i - r + 6];	/* n = 6 */
  prod_n *= xi - x[i - r + 8];	/* n = 8 */
  sum_m += prod_n;

  /* m = 5 */
  prod_n = 1.0;
  prod_n *= xi - x[i - r + 0];	/* n = 0 */
  prod_n *= xi - x[i - r + 1];	/* n = 1 */
  prod_n *= xi - x[i - r + 2];	/* n = 2 */
  prod_n *= xi - x[i - r + 3];	/* n = 3 */
  prod_n *= xi - x[i - r + 4];	/* n = 4 */
  prod_n *= xi - x[i - r + 6];	/* n = 6 */
  prod_n *= xi - x[i - r + 8];	/* n = 8 */
  sum_m += prod_n;

  /* m = 6 */
  prod_n = 1.0;
  prod_n *= xi - x[i - r + 0];	/* n = 0 */
  prod_n *= xi - x[i - r + 1];	/* n = 1 */
  prod_n *= xi - x[i - r + 2];	/* n = 2 */
  prod_n *= xi - x[i - r + 3];	/* n = 3 */
  prod_n *= xi - x[i - r + 4];	/* n = 4 */
  prod_n *= xi - x[i - r + 5];	/* n = 5 */
  prod_n *= xi - x[i - r + 8];	/* n = 8 */
  sum_m += prod_n;

  /* m = 8 */
  prod_n = 1.0;
  prod_n *= xi - x[i - r + 0];	/* n = 0 */
  prod_n *= xi - x[i - r + 1];	/* n = 1 */
  prod_n *= xi - x[i - r + 2];	/* n = 2 */
  prod_n *= xi - x[i - r + 3];	/* n = 3 */
  prod_n *= xi - x[i - r + 4];	/* n = 4 */
  prod_n *= xi - x[i - r + 5];	/* n = 5 */
  prod_n *= xi - x[i - r + 6];	/* n = 6 */
  sum_m += prod_n;

  prod_m = 1.0;
  prod_m *= x[i - r + 7] - x[i - r + 0];
  prod_m *= x[i - r + 7] - x[i - r + 1];
  prod_m *= x[i - r + 7] - x[i - r + 2];
  prod_m *= x[i - r + 7] - x[i - r + 3];
  prod_m *= x[i - r + 7] - x[i - r + 4];
  prod_m *= x[i - r + 7] - x[i - r + 5];
  prod_m *= x[i - r + 7] - x[i - r + 6];
  prod_m *= x[i - r + 7] - x[i - r + 8];

  sum_l += sum_m / prod_m * (x[i - r + 6 + 1] - x[i - r + 6]);

  /* l = 8 */
  sum_m = 0.0;

  /* m = 0 */
  prod_n = 1.0;
  prod_n *= xi - x[i - r + 1];	/* n = 1 */
  prod_n *= xi - x[i - r + 2];	/* n = 2 */
  prod_n *= xi - x[i - r + 3];	/* n = 3 */
  prod_n *= xi - x[i - r + 4];	/* n = 4 */
  prod_n *= xi - x[i - r + 5];	/* n = 5 */
  prod_n *= xi - x[i - r + 6];	/* n = 6 */
  prod_n *= xi - x[i - r + 7];	/* n = 7 */
  sum_m += prod_n;

  /* m = 1 */
  prod_n = 1.0;
  prod_n *= xi - x[i - r + 0];	/* n = 0 */
  prod_n *= xi - x[i - r + 2];	/* n = 2 */
  prod_n *= xi - x[i - r + 3];	/* n = 3 */
  prod_n *= xi - x[i - r + 4];	/* n = 4 */
  prod_n *= xi - x[i - r + 5];	/* n = 5 */
  prod_n *= xi - x[i - r + 6];	/* n = 6 */
  prod_n *= xi - x[i - r + 7];	/* n = 7 */
  sum_m += prod_n;

  /* m = 2 */
  prod_n = 1.0;
  prod_n *= xi - x[i - r + 0];	/* n = 0 */
  prod_n *= xi - x[i - r + 1];	/* n = 1 */
  prod_n *= xi - x[i - r + 3];	/* n = 3 */
  prod_n *= xi - x[i - r + 4];	/* n = 4 */
  prod_n *= xi - x[i - r + 5];	/* n = 5 */
  prod_n *= xi - x[i - r + 6];	/* n = 6 */
  prod_n *= xi - x[i - r + 7];	/* n = 7 */
  sum_m += prod_n;

  /* m = 3 */
  prod_n = 1.0;
  prod_n *= xi - x[i - r + 0];	/* n = 0 */
  prod_n *= xi - x[i - r + 1];	/* n = 1 */
  prod_n *= xi - x[i - r + 2];	/* n = 2 */
  prod_n *= xi - x[i - r + 4];	/* n = 4 */
  prod_n *= xi - x[i - r + 5];	/* n = 5 */
  prod_n *= xi - x[i - r + 6];	/* n = 6 */
  prod_n *= xi - x[i - r + 7];	/* n = 7 */
  sum_m += prod_n;

  /* m = 4 */
  prod_n = 1.0;
  prod_n *= xi - x[i - r + 0];	/* n = 0 */
  prod_n *= xi - x[i - r + 1];	/* n = 1 */
  prod_n *= xi - x[i - r + 2];	/* n = 2 */
  prod_n *= xi - x[i - r + 3];	/* n = 3 */
  prod_n *= xi - x[i - r + 5];	/* n = 5 */
  prod_n *= xi - x[i - r + 6];	/* n = 6 */
  prod_n *= xi - x[i - r + 7];	/* n = 7 */
  sum_m += prod_n;

  /* m = 5 */
  prod_n = 1.0;
  prod_n *= xi - x[i - r + 0];	/* n = 0 */
  prod_n *= xi - x[i - r + 1];	/* n = 1 */
  prod_n *= xi - x[i - r + 2];	/* n = 2 */
  prod_n *= xi - x[i - r + 3];	/* n = 3 */
  prod_n *= xi - x[i - r + 4];	/* n = 4 */
  prod_n *= xi - x[i - r + 6];	/* n = 6 */
  prod_n *= xi - x[i - r + 7];	/* n = 7 */
  sum_m += prod_n;

  /* m = 6 */
  prod_n = 1.0;
  prod_n *= xi - x[i - r + 0];	/* n = 0 */
  prod_n *= xi - x[i - r + 1];	/* n = 1 */
  prod_n *= xi - x[i - r + 2];	/* n = 2 */
  prod_n *= xi - x[i - r + 3];	/* n = 3 */
  prod_n *= xi - x[i - r + 4];	/* n = 4 */
  prod_n *= xi - x[i - r + 5];	/* n = 5 */
  prod_n *= xi - x[i - r + 7];	/* n = 7 */
  sum_m += prod_n;

  /* m = 7 */
  prod_n = 1.0;
  prod_n *= xi - x[i - r + 0];	/* n = 0 */
  prod_n *= xi - x[i - r + 1];	/* n = 1 */
  prod_n *= xi - x[i - r + 2];	/* n = 2 */
  prod_n *= xi - x[i - r + 3];	/* n = 3 */
  prod_n *= xi - x[i - r + 4];	/* n = 4 */
  prod_n *= xi - x[i - r + 5];	/* n = 5 */
  prod_n *= xi - x[i - r + 6];	/* n = 6 */
  sum_m += prod_n;

  prod_m = 1.0;
  prod_m *= x[i - r + 8] - x[i - r + 0];
  prod_m *= x[i - r + 8] - x[i - r + 1];
  prod_m *= x[i - r + 8] - x[i - r + 2];
  prod_m *= x[i - r + 8] - x[i - r + 3];
  prod_m *= x[i - r + 8] - x[i - r + 4];
  prod_m *= x[i - r + 8] - x[i - r + 5];
  prod_m *= x[i - r + 8] - x[i - r + 6];
  prod_m *= x[i - r + 8] - x[i - r + 7];

  sum_l += sum_m / prod_m * (x[i - r + 6 + 1] - x[i - r + 6]);

  c[6] = sum_l;
  /* j = 7 */
  sum_l = 0.0;

  /* l = 8 */
  sum_m = 0.0;

  /* m = 0 */
  prod_n = 1.0;
  prod_n *= xi - x[i - r + 1];	/* n = 1 */
  prod_n *= xi - x[i - r + 2];	/* n = 2 */
  prod_n *= xi - x[i - r + 3];	/* n = 3 */
  prod_n *= xi - x[i - r + 4];	/* n = 4 */
  prod_n *= xi - x[i - r + 5];	/* n = 5 */
  prod_n *= xi - x[i - r + 6];	/* n = 6 */
  prod_n *= xi - x[i - r + 7];	/* n = 7 */
  sum_m += prod_n;

  /* m = 1 */
  prod_n = 1.0;
  prod_n *= xi - x[i - r + 0];	/* n = 0 */
  prod_n *= xi - x[i - r + 2];	/* n = 2 */
  prod_n *= xi - x[i - r + 3];	/* n = 3 */
  prod_n *= xi - x[i - r + 4];	/* n = 4 */
  prod_n *= xi - x[i - r + 5];	/* n = 5 */
  prod_n *= xi - x[i - r + 6];	/* n = 6 */
  prod_n *= xi - x[i - r + 7];	/* n = 7 */
  sum_m += prod_n;

  /* m = 2 */
  prod_n = 1.0;
  prod_n *= xi - x[i - r + 0];	/* n = 0 */
  prod_n *= xi - x[i - r + 1];	/* n = 1 */
  prod_n *= xi - x[i - r + 3];	/* n = 3 */
  prod_n *= xi - x[i - r + 4];	/* n = 4 */
  prod_n *= xi - x[i - r + 5];	/* n = 5 */
  prod_n *= xi - x[i - r + 6];	/* n = 6 */
  prod_n *= xi - x[i - r + 7];	/* n = 7 */
  sum_m += prod_n;

  /* m = 3 */
  prod_n = 1.0;
  prod_n *= xi - x[i - r + 0];	/* n = 0 */
  prod_n *= xi - x[i - r + 1];	/* n = 1 */
  prod_n *= xi - x[i - r + 2];	/* n = 2 */
  prod_n *= xi - x[i - r + 4];	/* n = 4 */
  prod_n *= xi - x[i - r + 5];	/* n = 5 */
  prod_n *= xi - x[i - r + 6];	/* n = 6 */
  prod_n *= xi - x[i - r + 7];	/* n = 7 */
  sum_m += prod_n;

  /* m = 4 */
  prod_n = 1.0;
  prod_n *= xi - x[i - r + 0];	/* n = 0 */
  prod_n *= xi - x[i - r + 1];	/* n = 1 */
  prod_n *= xi - x[i - r + 2];	/* n = 2 */
  prod_n *= xi - x[i - r + 3];	/* n = 3 */
  prod_n *= xi - x[i - r + 5];	/* n = 5 */
  prod_n *= xi - x[i - r + 6];	/* n = 6 */
  prod_n *= xi - x[i - r + 7];	/* n = 7 */
  sum_m += prod_n;

  /* m = 5 */
  prod_n = 1.0;
  prod_n *= xi - x[i - r + 0];	/* n = 0 */
  prod_n *= xi - x[i - r + 1];	/* n = 1 */
  prod_n *= xi - x[i - r + 2];	/* n = 2 */
  prod_n *= xi - x[i - r + 3];	/* n = 3 */
  prod_n *= xi - x[i - r + 4];	/* n = 4 */
  prod_n *= xi - x[i - r + 6];	/* n = 6 */
  prod_n *= xi - x[i - r + 7];	/* n = 7 */
  sum_m += prod_n;

  /* m = 6 */
  prod_n = 1.0;
  prod_n *= xi - x[i - r + 0];	/* n = 0 */
  prod_n *= xi - x[i - r + 1];	/* n = 1 */
  prod_n *= xi - x[i - r + 2];	/* n = 2 */
  prod_n *= xi - x[i - r + 3];	/* n = 3 */
  prod_n *= xi - x[i - r + 4];	/* n = 4 */
  prod_n *= xi - x[i - r + 5];	/* n = 5 */
  prod_n *= xi - x[i - r + 7];	/* n = 7 */
  sum_m += prod_n;

  /* m = 7 */
  prod_n = 1.0;
  prod_n *= xi - x[i - r + 0];	/* n = 0 */
  prod_n *= xi - x[i - r + 1];	/* n = 1 */
  prod_n *= xi - x[i - r + 2];	/* n = 2 */
  prod_n *= xi - x[i - r + 3];	/* n = 3 */
  prod_n *= xi - x[i - r + 4];	/* n = 4 */
  prod_n *= xi - x[i - r + 5];	/* n = 5 */
  prod_n *= xi - x[i - r + 6];	/* n = 6 */
  sum_m += prod_n;

  prod_m = 1.0;
  prod_m *= x[i - r + 8] - x[i - r + 0];
  prod_m *= x[i - r + 8] - x[i - r + 1];
  prod_m *= x[i - r + 8] - x[i - r + 2];
  prod_m *= x[i - r + 8] - x[i - r + 3];
  prod_m *= x[i - r + 8] - x[i - r + 4];
  prod_m *= x[i - r + 8] - x[i - r + 5];
  prod_m *= x[i - r + 8] - x[i - r + 6];
  prod_m *= x[i - r + 8] - x[i - r + 7];

  sum_l += sum_m / prod_m * (x[i - r + 7 + 1] - x[i - r + 7]);

  c[7] = sum_l;
}
