#!/usr/local/bin/python

import cProfile as profile
import pstats

import numpy as np

import pyweno.stencil
import pyweno.cstencil


r = 2
k = 4

x = np.linspace(-100.0, 100.0, 5000+1)

c1 = np.zeros((x.size, k))
c2 = np.zeros((x.size, k))


def gen_stencil():

    for i in range(k, x.size-k):
        pyweno.stencil._reconstruction_coeffs(i, r, k, x, c1, '-')

def gen_cstencil():

    for i in range(k, x.size-k):
        pyweno.cstencil.reconstruction_coeffs_4m(i, r, x, c2)
    

def run():
    print "stencil"
    gen_stencil()
    print "cstencil"
    gen_cstencil()
    print "done"
    

profile.run("run()", 'dambreak.prof')

p = pstats.Stats('dambreak.prof')
p.sort_stats('time', 'cum').print_stats(10)
