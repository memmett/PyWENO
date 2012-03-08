
from ctypes import *

import pyweno.symbolic
import pyweno.kernels
import pyweno.wrappers
import os
import pstats

import cProfile

import numpy as np

from os import system

cc = os.environ.get('CC', None) or 'gcc'
fc = os.environ.get('FC', None) or 'gfortran'

cflags = os.environ.get('CFLAGS', None) or '-std=c99 -O3 -pg -fPIC -shared'
fflags = os.environ.get('FFLAGS', None) or '-O3 -pg -fPIC -shared'

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

        void profrecon(int repeat,
                       const double *restrict f, int n, int fsi,
                       double *restrict fr, int frsi, int frsl)
        {
          int i;
        
          for (i=0; i<repeat; i++) {
            reconstruct(f, n, fsi, fr, frsi, frsl);
          }
        }'''
    }


def make(src, so='prof', lang='c', verbose=True):

    # write src to temporary file
    tmp = so + extensions[lang]
    with open(tmp, 'w') as f:
        f.write(src)

    # compile
    cmd = compilers[lang]
    cmd.extend([tmp, '-o', so + '.so'])
    cmd = ' '.join(cmd)

    if system(cmd):
        raise ValueError

    # return shared object name
    return so


def reconstruct(k, lang='c'):

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


def profile(k, lang='c'):

    # generate profiler and load compiled shared object
    src = reconstruct(k, lang)
    make(src)
    prof = CDLL('./prof.so')


    # test function
    f = np.cos
    F = np.sin

    # cell averages
    x = np.linspace(0.0, 2*np.pi, 201)
    a = (F(x[1:]) - F(x[:-1]))/(x[1]-x[0])

    # allocate destination
    fr = np.zeros((a.shape[0],2))

    # run the profiler!
    dptr = POINTER(c_double)

    ctx = {}
    ctx.update(globals())
    ctx.update(locals())

    cProfile.runctx('''prof.profrecon(
                         c_int(1000000),
                         a.ctypes.data_as(dptr), c_int(a.shape[0]), c_int(1),
                         fr.ctypes.data_as(dptr), c_int(2), c_int(1))
    ''', ctx, ctx, 'prof.stats')

    p = pstats.Stats('prof.stats')
    p.strip_dirs().sort_stats('time').print_stats(20)


if __name__ == '__main__':
    profile(3)
