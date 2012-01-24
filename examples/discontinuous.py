"""PyWENO smooth reconstruction example."""

import numpy as np
import pyweno.weno

import matplotlib
matplotlib.use('Agg')
import matplotlib.pyplot as plt

def f(x):
    r = np.zeros(x.shape)

    i = x > 0
    r[i] = np.cos(x[i])

    i = x <= 0
    r[i] = np.sin(x[i])

    return r

def F(x):
    r = np.zeros(x.shape)

    i = x > 0
    r[i] = np.sin(x[i])

    i = x <= 0
    r[i] = -np.cos(x[i])

    return r

x = np.linspace(-2*np.pi, 2*np.pi, 41)
a = (F(x[1:]) - F(x[:-1]))/(x[1]-x[0])
a[20:21] = (F(x[21:22]) - 0.0)/(x[1]-x[0]) # fix middle cell average
l, s = pyweno.weno.reconstruct(a, 5, 'left', return_smoothness=True)
r    = pyweno.weno.reconstruct(a, 5, 'right')

plt.title('pyweno.weno reconstruction and smoothness indicators')

plt.subplot(2,1,1)

x2 = np.linspace(x[0], x[-1], 1001)
plt.plot(x2, f(x2), '-k')
plt.plot(x[:-1], l, 'or')
plt.plot(x[1:],  r, 'ob')

plt.ylabel('f')
plt.xlabel('x')
plt.legend(['actual', 'left', 'right'])

plt.subplot(2,1,2)

c = 0.5*(x[1:] + x[:-1])

plt.plot(c, s[:,0], 'or')
plt.plot(c, s[:,1], 'ok')
plt.plot(c, s[:,2], 'ob')

plt.ylabel('smoothness')
plt.xlabel('x')
plt.legend(['r=0', 'r=1', 'r=2'])

plt.savefig('discontinuous.png', format='png')
