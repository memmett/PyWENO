"""PyWENO smooth reconstruction example."""

import math
import numpy
import pyweno.grid
import pyweno.weno

# explicitly define the function f that we will reconstruct ...
def f(x):
    if x <= 0.0:
        return 1.0

    return 0.0

# build weno reconstructor
x = numpy.linspace(-1.0, 1.0, 21)
grid = pyweno.grid.Grid(x)

weno = pyweno.weno.WENO(order=5, grid=grid)
weno.precompute_reconstruction('left')
weno.precompute_reconstruction('right')

# average f
f_avg = grid.average(f)

# allocate arrays for reconstruction
f_left = numpy.zeros(grid.N)
f_right = numpy.zeros(grid.N)

# compute smoothness indicators
weno.smoothness(f_avg)

# reconstruct!
weno.reconstruct(f_avg, 'left', f_left)
weno.reconstruct(f_avg, 'right', f_right)

# plot results
import matplotlib
matplotlib.use('Agg')

import matplotlib.pyplot as plt

plt.subplot(2,1,1)

x = numpy.linspace(-1.0, 1.0, 1001);
uf = numpy.frompyfunc(f, 1, 1)
plt.plot(x, uf(x), '-k')

plt.plot(grid.x[:-1], f_left, 'or')
plt.plot(grid.x[1:], f_right, 'ob')

plt.title('PyWENO reconstruction and smoothness indicators')
plt.ylabel('f')
plt.xlabel('x')
plt.legend(['actual', 'left', 'right'])

plt.subplot(2,1,2)

plt.plot(grid.centres(), weno.sigma[:,0], 'o')
plt.plot(grid.centres(), weno.sigma[:,1], 'o')
plt.plot(grid.centres(), weno.sigma[:,2], 'o')
plt.plot(grid.centres(), weno.sigma[:,3], 'o')
plt.plot(grid.centres(), weno.sigma[:,4], 'o')

plt.ylabel('sigma')
plt.xlabel('x')
plt.legend(['r=0', 'r=1', 'r=2', 'r=3', 'r=4'])

plt.savefig('step.png', format='png')


