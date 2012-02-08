# build a cache if jiang_shu polynomials...

import pickle

import sympy
import pyweno.symbolic as symbolic

K = range(3, 4)

x = sympy.var('x')
jiang_shu_polys = {}

for k in K:
  jiang_shu_polys[k] = {}  

  print 'generating poly:', k

  # build array of cell boundaries (sympy vars x[i])
  xs = []
  for j in range(k+1):
    xs.append(sympy.var('x%d' % j))

  X1 = sympy.var('X1')
  X2 = sympy.var('X2')

  # build array of y values
  ys = []
  for j in range(k):
    ys.append(sympy.var('y%d' % j))

  # build polynomial
  p = symbolic.primitive_polynomial_interpolator(xs, ys)
  p = p.as_poly(x)
  p = p.diff(x)

  
  for r in range(0, k):
    # sum of L^2 norms of derivatives
    s = 0
    for j in range(1, k):
      pp = (p.diff((0,j)))**2
      pp = pp.integrate(x)
      pp = (X2 - X1)**(2*j-1) * (
        pp.subs(x, X2) - pp.subs(x, X1) )
      s = s + pp

    jiang_shu_polys[k][r] = s


with open('pyweno/jiang_shu.pkl', 'w') as f:
  pickle.dump(jiang_shu_polys, f)



