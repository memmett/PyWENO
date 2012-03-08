"""Profiling routines."""

import os

import numpy as np

import pyweno.symbolic
import pyweno.functions


###############################################################################
# config

cc = os.environ.get('CC', None) or 'gcc'
fc = os.environ.get('FC', None) or 'gfortran'

cflags = os.environ.get('CFLAGS', None) or '-std=c99 -O2 -lm -msse2'
fflags = os.environ.get('FFLAGS', None) or '-O3 -msse2'

compilers = {
    'c': [cc, cflags],
    'fortran': [fc, fflags]
    }

extensions = {
    'c': '.c',
    'fortran': '.f90'
    }

profrecon = {
    'c': '''
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define N 100000

%s

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
''',
    'fortran': '''
program profile
  integer, parameter :: N = 100000
  real(8) :: f(N), fr(N,0:1)
  integer :: i

  do i = 1, N
    f(i) = sin(dble(i))
  end do

  do i = 1, 100
    call reconstruct(f, N, fr)
  end do
  
contains
  %s
end program profile
'''
    }


###############################################################################
# helpers

def make(src, exe='prof', lang='c', **kwargs):
    """Compile the source code in *src* (a string) into the executable
    *exe*."""

    # write src to temporary file
    tmp = exe + extensions[lang]
    with open(tmp, 'w') as f:
        f.write(src)

    # compile
    cmd = compilers[lang]
    cmd.extend([tmp, '-o', exe])
    cmd = ' '.join(cmd)

    if os.system(cmd):
        raise ValueError

    # return executable name
    return exe


def reconstruct(k=3, lang='c', vectorize=False, **kwargs):
    """Build reconstruction routine of order *k*."""

    gen = pyweno.functions.FunctionGenerator(lang, vectorize=vectorize, normalise=False)

    # set smoothness
    beta = pyweno.symbolic.jiang_shu_smoothness_coefficients(k)
    gen.set_smoothness(beta)

    # reconstructions: -1=left, 1=right
    (varpi, split) = pyweno.symbolic.optimal_weights(k, [ -1, 1 ])
    coeffs = pyweno.symbolic.reconstruction_coefficients(k, [ -1, 1 ])

    gen.set_optimal_weights(varpi, split)
    gen.set_reconstruction_coefficients(coeffs)

    src = gen.generate('reconstruct', weights=True, smoothness=True)

    return profrecon[lang] % (src)


def profile(**kwargs):
    """Build a reconstruction routine (all keyword arguments are
    passed to *reconstruct*, compile, and run the profiling
    executable."""

    # generate profiler and load compiled shared object
    src = reconstruct(**kwargs)
    exe = make(src, **kwargs)

    # run the profiler and time it
    os.system('time ./' + exe)


if __name__ == '__main__':
    profile(k=3, lang='fortran', vectorize=True)
