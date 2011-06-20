"""Generate the cweno extension module.

An easy to use interface this module can be found in
scikits.weno.reconstruct.

"""

import pyweno.points
import pyweno.symbolic
import pyweno.wrappers


#### generate

wrappers = []

for k in range(3, 5):

  print 'k:', k

  ## smoothness
  
  wrapper = pyweno.wrappers.WrapperGenerator('c')

  beta = pyweno.symbolic.jiang_shu_smoothness_coefficients(k)
  wrapper.set_smoothness(beta)

  base = 'smoothness%03d' % k
  with open('weno_' + base + '.c', 'w') as f:
    f.write('#include <Python.h>\n')
    f.write('#include <numpy/ndarrayobject.h>\n')
    f.write(wrapper.smoothness(base, wrapper=True))

  wrappers += wrapper.wrappers

  ## reconstructors

  for pts in [ 'left',
               'right',
#               'middle',
               'gauss_legendre',
               'gauss_lobatto',
               'gauss_radau' ]:

    print '  point:', pts

    if pts == 'left':
      func = lambda n: [ -1 ]
      N    = [ 1 ]
    elif pts == 'right':
      func = lambda n: [ 1 ]
      N    = [ 1 ]
    elif pts == 'middle':
      func = lambda n: [ 0 ]
      N    = [ 1 ]
    else:
      func = getattr(pyweno.points, pts)
      N    = range(2, k+1)
      xi   = func

    for n in N:

      wrapper = pyweno.wrappers.WrapperGenerator('c')
      wrapper.set_smoothness(beta)    
      
      xi = func(n)

      print '    n:', n

      try:
        (varpi, split) = pyweno.symbolic.optimal_weights(k, xi)
        coeffs = pyweno.symbolic.reconstruction_coefficients(k, xi)
      except ValueError:
        print '      - skipped'
        continue

      wrapper.set_optimal_weights(varpi, split)
      wrapper.set_reconstruction_coefficients(coeffs)

      base = pts + '%03d%03d' % (k, n)
      with open('weno_' + base + '.c', 'w') as f:
        f.write('#include <Python.h>\n')
        f.write('#include <numpy/ndarrayobject.h>\n')
        f.write(wrapper.weights('weights_' + base, wrapper=True))
        f.write(wrapper.reconstruction('reconstruct_' + base, wrapper=True))

      wrappers += wrapper.wrappers


#### python extension module

# create new wrapper, and set 'wrappers' manually
wrapper = pyweno.wrappers.WrapperGenerator('c')

wrapper.wrappers = wrappers
with open('cweno.c', 'w') as f:
  # c includes etc
  f.write(wrapper.header(module='cweno'))

  # prototypes
  for w in wrappers:
    f.write('PyObject *{wrapper}(PyObject *self, PyObject *args);\n'.format(
      wrapper=w[0]))

  # python module definition
  f.write(wrapper.footer())
