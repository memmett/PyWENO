"""PyWENO smooth reconstruction example."""

import math
import numpy
import pyweno.grid
import pyweno.weno

# explicitly define the function f that we will reconstruct ...
def f(x):
    """Test function (quadratic)."""

    return 1.0 - x + x*x

uf = numpy.frompyfunc(f, 1, 1)

# ... and it's derivative
def fp(x):
    """Derivative of test function."""

    return -1.0 + 2.0*x

# load the weno reconstructor from the cache
k = 3
cache = 'gridk%d.mat' % (k)

grid = pyweno.grid.Grid(cache=cache)
weno = pyweno.weno.WENO(order=k, cache=cache)

# average f
f_avg = grid.average(f)

# allocate arrays for reconstruction
f_left = numpy.zeros(grid.N)
f_right = numpy.zeros(grid.N)
f_gauss = numpy.zeros((grid.N, 3))
fp_gauss = numpy.zeros((grid.N, 3))

# compute smoothness indicators
weno.smoothness(f_avg)

# reconstruct!
weno.reconstruct(f_avg, 'left', f_left)
weno.reconstruct(f_avg, 'right', f_right)
weno.reconstruct(f_avg, 'gauss_quad3', f_gauss)
weno.reconstruct(f_avg, 'd|gauss_quad3', fp_gauss)

# plot results
import matplotlib
matplotlib.use('Agg')

import matplotlib.pyplot as plt

plt.plot(grid.x, uf(grid.x), '-k')
plt.plot(grid.x[:-1], f_left, 'or')
plt.plot(grid.x[1:], f_right, 'ob')

plt.title('PyWENO reconstruction')
plt.ylabel('f')
plt.xlabel('x')
plt.legend(['actual', 'left', 'right'])

plt.savefig('smooth.png', format='png')

# XXX: plot quadrature points
# XXX: plot derivative
