
#ifndef _WENO_H_
#define _WENO_H_

#define MAX_DEGREE 8

#define WENO_BAD_STATE 1
#define WENO_BAD_ALLOC 2

#define dtype double

typedef struct poly {
  int n; dtype p[MAX_DEGREE+1];
} poly;

typedef struct weno {

  int       k;		/* size of base stencil */
  dtype*    x;		/* nonuniform grid (cell edges) */
  int       nx;		/* number of cell edges */
  int       nc;		/* number of cells */
  dtype*    xi;		/* reconstruction points in [ -1, 1 ] */
  int       nxi;	/* number of reconstruction points */

  /* strides */
  int       csi, csl, csr, csj;
  int       bsi, bsr, bsm, bsn;
  int       vsi, vsl, vsr;

  poly*     c_irj_x;	/* base reconstruction polynomials p^r_{i,j}(x), based on x  */
  poly*     c2_ij_x;	/* optimal weight reconstruction polynomials p^r_{i,j}(x), based on x  */
  dtype*    c_ilrj;	/* reconstruction coeffs c[i,l,r,j] (based on xi) */
  dtype*    beta;	/* smoothness coeffs beta[i,r,m,n] */
  dtype*    varpi;	/* optimal weights varpi[i,l,r] */

} weno;

poly poly_empty(int n);
poly poly_zero(int n);
poly poly_one(int n);
poly poly_diff(const poly p, int n);
poly poly_antidiff(const poly p);
poly poly_mult(const poly p1, const poly p2);
poly poly_sq(const poly p);
poly poly_add(const poly p1, const poly p2);
poly poly_scale(const poly p, dtype a);
poly poly_interp(const dtype *x, const dtype *y, int nx);
poly poly_primitive_interp(const dtype *x, const dtype *Y, int nx);

dtype poly_eval(const poly p, dtype x);
dtype poly_int(const poly p, dtype a, dtype b);

void poly_print(const poly p);

weno weno_recon_polys(const weno w);
weno weno_recon_coefs(const weno w);
weno weno_smoothness_coefs(const weno w);

#endif
