"""Time various WENO reconstructions."""

raise NotImplementedError

import timeit

import pyweno.clweno5

N = 100001

setup = """
import numpy as np
import pyweno.grid
import pyweno.weno

x    = np.linspace(0.0, 100.0, %d)
grid = pyweno.grid.Grid(x)
q    = grid.average(lambda x: x)
qs   = np.zeros(grid.N)

weno5 = pyweno.weno.WENO(grid=grid, k=3)
weno5.precompute_reconstruction('left')
weno5.precompute_reconstruction('right')
""" % N

statement = """
weno5.smoothness(q, imin=%(imin)d, imax=%(imax)d)
weno5.reconstruct(q, 'left', qs, imin=%(imin)d, imax=%(imax)d)
weno5.reconstruct(q, 'right', qs, imin=%(imin)d, imax=%(imax)d)
""" % {'imin': 5, 'imax': N-5}

t_weno = timeit.timeit(statement, setup, number=2000)

setup = r"""
import numpy as np
import pyweno.clweno5

x    = np.linspace(0.0, 100.0, %d)
grid = pyweno.grid.Grid(x)
q    = grid.average(lambda x: x)
qp   = np.zeros(grid.N)
qm   = np.zeros(grid.N)

clweno5 = pyweno.clweno5.CLWENO5PM()
""" % N

statement = "clweno5.reconstruct(q, qp, qm)"

t_clweno = timeit.timeit(statement, setup, number=2000)

print 'weno: %14.7f, clweno: %14.7f, speedup: %14.7f' % (t_weno, t_clweno, t_weno/t_clweno)

