"""Profiling routines."""

import os

import numpy as np

import pyweno.symbolic
import pyweno.kernels
import pyweno.wrappers


###############################################################################
# config

cc = os.environ.get('CC', None) or 'gcc'
fc = os.environ.get('FC', None) or 'gfortran'

cflags = os.environ.get('CFLAGS', None) or '-std=c99 -O2 -lm'
fflags = os.environ.get('FFLAGS', None) or '-O2'

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

#define N 1000000

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
'''
    }


###############################################################################
# helpers

def make(src, exe='prof', lang='c', verbose=True):
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


def reconstruct(k=3, lang='c'):
    """Build reconstruction routine of order *k*."""

    wrapper = pyweno.wrappers.WrapperGenerator(lang)

    # set smoothness
    beta = pyweno.symbolic.jiang_shu_smoothness_coefficients(k)
    wrapper.set_smoothness(beta)

    # reconstructions: -1=left, 1=right
    (varpi, split) = pyweno.symbolic.optimal_weights(k, [ -1, 1 ])
    coeffs = pyweno.symbolic.reconstruction_coefficients(k, [ -1, 1 ])

    wrapper.set_optimal_weights(varpi, split)
    wrapper.set_reconstruction_coefficients(coeffs)

    src = wrapper.reconstruction(compute_weights=True, compute_smoothness=True)

    src += profrecon[lang]

    return src


def profile(**kwargs):
    """Build a reconstruction routine (all keyword arguments are
    passed to *reconstruct*, compile, and run the profiling
    executable."""

    # generate profiler and load compiled shared object
    src = reconstruct(**kwargs)
    exe = make(src)

    # run the profiler and time it
    os.system('time ./' + exe)


if __name__ == '__main__':
    profile(k=5)
