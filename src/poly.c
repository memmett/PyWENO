/*
 * Polynomial (monomial basis) routines.  No side effects or explicit
 * memory management.
 */

#include <stdio.h>
#include "nfweno.h"

poly poly_empty(int n)
{
  poly p = { n };
  return p;
}

poly poly_zero(int n)
{
  poly p = { n };
  for (int j=0; j<=n; j++)
    p.p[j] = 0;
  return p;
}

poly poly_one(int n)
{
  poly p = { n };
  p.p[0] = 1;
  for (int j=1; j<=n; j++)
    p.p[j] = 0;
  return p;
}

dtype poly_eval(const poly p, dtype x)
{
  dtype v;
  v = p.p[p.n];
  for (int j=p.n-1; j>=0; j--)
    v = x * v + p.p[j];
  return v;
}

poly poly_diff(const poly p, int n)
{
  poly q = p;
  for (int i=0; i<n; i++) {
    for (int j=1; j<=q.n-i; j++)
      q.p[j-1] = j * q.p[j];
    q.p[q.n--] = 0;
  }
  return q;
}

poly poly_antidiff(const poly p)
{
  poly q = poly_empty(p.n+1);
  for (int j=p.n; j>=0; j--)
    q.p[j+1] = p.p[j] / (j+1);
  return q;
}

dtype poly_int(const poly p, dtype a, dtype b)
{
  poly q = poly_antidiff(p);
  return poly_eval(q, b) - poly_eval(q, a);
}

poly poly_mult(const poly p1, const poly p2)
{
  poly q = poly_zero(p1.n+p2.n);
  for (int j=0; j<=p1.n; j++)
    for (int i=0; i<=p2.n; i++)
      q.p[i+j] += p1.p[j] * p2.p[i];
  return q;
}

poly poly_sq(const poly p)
{
  return poly_mult(p, p);
}

poly poly_add(const poly p1, const poly p2)
{
  poly q;
  if (p1.n > p2.n) {
    q = p1;
    for (int j=0; j<=p2.n; j++)
      q.p[j] += p2.p[j];
  } else {
    q = p2;
    for (int j=0; j<=p1.n; j++)
      q.p[j] += p1.p[j];
  }
  return q;
}

poly poly_scale(const poly p, dtype a)
{
  poly q = p;
  for (int j=0; j<=p.n; j++)
    q.p[j] *= a;
  return q;
}

void poly_print(const poly p)
{
  for (int j=0; j<p.n; j++)
    printf("%le x^%d + ", p.p[j], j);
  printf("%le x^%d\n", p.p[p.n], p.n);
}

poly poly_interp(const dtype *x, const dtype *y, int nx)
{
  int  n = nx-1;
  poly p = poly_zero(n);
  poly t = poly_empty(n);
  for (int i=0; i<nx; i++) {
    t.p[0] = y[i];
    for (int k=1; k<=n; k++)
      t.p[k] = 0;
    for (int j=0; j<=n; j++) {
      if (i == j) continue;
      dtype dxinv = 1.0 / (x[i] - x[j]);
      for (int k=n; k>=1; k--)
	t.p[k] = (t.p[k-1] - x[j] * t.p[k]) * dxinv;
      t.p[0] = (- x[j] * t.p[0]) * dxinv;
    }
    for (int k=0; k<=n; k++) p.p[k] += t.p[k];
  }
  return p;
}


/* note that x are cell boundaries and y are cell averages */
poly poly_primitive_interp(const dtype *x, const dtype *Y, int nx)
{
  dtype y[nx];
  y[0] = 0;
  for (int i=1; i<nx; i++)
    y[i] = y[i-1] + Y[i-1] * (x[i] - x[i-1]);
  return poly_interp(x, y, nx);
}
