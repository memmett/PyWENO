void
coeffs003 (double xi, long int i, int r, double *x, double *c)
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
  sum_m += prod_n;

  /* m = 2 */
  prod_n = 1.0;
  prod_n *= xi - x[i - r + 0];	/* n = 0 */
  prod_n *= xi - x[i - r + 3];	/* n = 3 */
  sum_m += prod_n;

  /* m = 3 */
  prod_n = 1.0;
  prod_n *= xi - x[i - r + 0];	/* n = 0 */
  prod_n *= xi - x[i - r + 2];	/* n = 2 */
  sum_m += prod_n;

  prod_m = 1.0;
  prod_m *= x[i - r + 1] - x[i - r + 0];
  prod_m *= x[i - r + 1] - x[i - r + 2];
  prod_m *= x[i - r + 1] - x[i - r + 3];

  sum_l += sum_m / prod_m * (x[i - r + 0 + 1] - x[i - r + 0]);

  /* l = 2 */
  sum_m = 0.0;

  /* m = 0 */
  prod_n = 1.0;
  prod_n *= xi - x[i - r + 1];	/* n = 1 */
  prod_n *= xi - x[i - r + 3];	/* n = 3 */
  sum_m += prod_n;

  /* m = 1 */
  prod_n = 1.0;
  prod_n *= xi - x[i - r + 0];	/* n = 0 */
  prod_n *= xi - x[i - r + 3];	/* n = 3 */
  sum_m += prod_n;

  /* m = 3 */
  prod_n = 1.0;
  prod_n *= xi - x[i - r + 0];	/* n = 0 */
  prod_n *= xi - x[i - r + 1];	/* n = 1 */
  sum_m += prod_n;

  prod_m = 1.0;
  prod_m *= x[i - r + 2] - x[i - r + 0];
  prod_m *= x[i - r + 2] - x[i - r + 1];
  prod_m *= x[i - r + 2] - x[i - r + 3];

  sum_l += sum_m / prod_m * (x[i - r + 0 + 1] - x[i - r + 0]);

  /* l = 3 */
  sum_m = 0.0;

  /* m = 0 */
  prod_n = 1.0;
  prod_n *= xi - x[i - r + 1];	/* n = 1 */
  prod_n *= xi - x[i - r + 2];	/* n = 2 */
  sum_m += prod_n;

  /* m = 1 */
  prod_n = 1.0;
  prod_n *= xi - x[i - r + 0];	/* n = 0 */
  prod_n *= xi - x[i - r + 2];	/* n = 2 */
  sum_m += prod_n;

  /* m = 2 */
  prod_n = 1.0;
  prod_n *= xi - x[i - r + 0];	/* n = 0 */
  prod_n *= xi - x[i - r + 1];	/* n = 1 */
  sum_m += prod_n;

  prod_m = 1.0;
  prod_m *= x[i - r + 3] - x[i - r + 0];
  prod_m *= x[i - r + 3] - x[i - r + 1];
  prod_m *= x[i - r + 3] - x[i - r + 2];

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
  sum_m += prod_n;

  /* m = 1 */
  prod_n = 1.0;
  prod_n *= xi - x[i - r + 0];	/* n = 0 */
  prod_n *= xi - x[i - r + 3];	/* n = 3 */
  sum_m += prod_n;

  /* m = 3 */
  prod_n = 1.0;
  prod_n *= xi - x[i - r + 0];	/* n = 0 */
  prod_n *= xi - x[i - r + 1];	/* n = 1 */
  sum_m += prod_n;

  prod_m = 1.0;
  prod_m *= x[i - r + 2] - x[i - r + 0];
  prod_m *= x[i - r + 2] - x[i - r + 1];
  prod_m *= x[i - r + 2] - x[i - r + 3];

  sum_l += sum_m / prod_m * (x[i - r + 1 + 1] - x[i - r + 1]);

  /* l = 3 */
  sum_m = 0.0;

  /* m = 0 */
  prod_n = 1.0;
  prod_n *= xi - x[i - r + 1];	/* n = 1 */
  prod_n *= xi - x[i - r + 2];	/* n = 2 */
  sum_m += prod_n;

  /* m = 1 */
  prod_n = 1.0;
  prod_n *= xi - x[i - r + 0];	/* n = 0 */
  prod_n *= xi - x[i - r + 2];	/* n = 2 */
  sum_m += prod_n;

  /* m = 2 */
  prod_n = 1.0;
  prod_n *= xi - x[i - r + 0];	/* n = 0 */
  prod_n *= xi - x[i - r + 1];	/* n = 1 */
  sum_m += prod_n;

  prod_m = 1.0;
  prod_m *= x[i - r + 3] - x[i - r + 0];
  prod_m *= x[i - r + 3] - x[i - r + 1];
  prod_m *= x[i - r + 3] - x[i - r + 2];

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
  sum_m += prod_n;

  /* m = 1 */
  prod_n = 1.0;
  prod_n *= xi - x[i - r + 0];	/* n = 0 */
  prod_n *= xi - x[i - r + 2];	/* n = 2 */
  sum_m += prod_n;

  /* m = 2 */
  prod_n = 1.0;
  prod_n *= xi - x[i - r + 0];	/* n = 0 */
  prod_n *= xi - x[i - r + 1];	/* n = 1 */
  sum_m += prod_n;

  prod_m = 1.0;
  prod_m *= x[i - r + 3] - x[i - r + 0];
  prod_m *= x[i - r + 3] - x[i - r + 1];
  prod_m *= x[i - r + 3] - x[i - r + 2];

  sum_l += sum_m / prod_m * (x[i - r + 2 + 1] - x[i - r + 2]);

  c[2] = sum_l;
}
