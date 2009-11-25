"""PyWENO smooth reconstruction example."""

import math
import numpy
import pyweno.grid
import pyweno.weno

# explicitly define the function f that we will reconstruct ...
def f(x):
    """Test function."""

    if x < 0.0:
        return math.sin(x)

    return math.cos(x)

uf = numpy.frompyfunc(f, 1, 1)

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

plt.subplot(2,1,1)

x = numpy.linspace(-4.0, 4.0, 1001);
plt.plot(x, uf(x), '-k')

plt.plot(grid.x[:-1], f_left, 'or')
plt.plot(grid.x[1:], f_right, 'ob')

plt.title('PyWENO reconstruction and smoothness indicators')
plt.ylabel('f')
plt.xlabel('x')
plt.legend(['actual', 'left', 'right'])

plt.subplot(2,1,2)

plt.plot(grid.centres(), weno.sigma[:,0], 'or')
plt.plot(grid.centres(), weno.sigma[:,1], 'ok')
plt.plot(grid.centres(), weno.sigma[:,2], 'ob')

plt.ylabel('sigma')
plt.xlabel('x')
plt.legend(['r=0', 'r=1', 'r=2'])

plt.savefig('discontinuous.png', format='png')

# XXX: plot quadrature points
# XXX: plot derivative


