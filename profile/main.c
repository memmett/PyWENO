
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define N 1000000

void reconstruct(const double *restrict f, int n, int fsi,
		 double *restrict fr, int frsi, int frsl);


void
main(int argc, char **argv) {
  int i;
  double *f, *q;

  f = (double *) malloc(N*sizeof(double));
  q = (double *) malloc(2*N*sizeof(double));

  for (i=0; i<N; i++) {
    f[i] = sin(1.0*i);
  }

  for (i=0; i<100; i++) {
    reconstruct(f, N, 1, q, 2, 1);
  }

  free(f);
  free(q);
}
