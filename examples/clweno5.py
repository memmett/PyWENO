"""PyWENO discontinuous reconstruction example using OpenCL."""

import math
import numpy
import pyweno.grid
import pyweno.clweno5

# explicitly define the function f that we will reconstruct ...
def f(x):
    if x < 0.0:
        return math.sin(x)

    return math.cos(x)

uf = numpy.frompyfunc(f, 1, 1)

# load the weno reconstructor from the cache
x = numpy.linspace(-5.0, 5.0, 21)
grid = pyweno.grid.Grid(x)
weno = pyweno.clweno5.CLWENO5PM()

# average f
fb = grid.average(f)

# allocate arrays for reconstruction
fm = numpy.zeros(grid.N)
fp = numpy.zeros(grid.N)

# reconstruct!
weno.reconstruct(fb, fp, fm)

# plot results
import matplotlib
matplotlib.use('Agg')

import matplotlib.pyplot as plt

x = numpy.linspace(-5.0, 5.0, 1001);
uf = numpy.frompyfunc(f, 1, 1)
plt.plot(x, uf(x), '-k')

plt.plot(grid.x[:-1], fp, 'or')
plt.plot(grid.x[:-1],  fm, 'ob')

plt.title('PyWENO (CL5) reconstruction')
plt.ylabel('f')
plt.xlabel('x')
plt.legend(['actual', 'plus', 'minus'])

# draw grid boundaries
for i in range(grid.N+1):
    plt.plot([grid.x[i], grid.x[i]], [-0.1, 0.1], color='0.5')

plt.savefig('clweno5.png', format='png')


