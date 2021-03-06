"""Generate the cweno extension module."""

import pathlib

import jinja2
import pyweno

jinja2.filters.FILTERS['pm']  = lambda x: "{:+d}".format(x)
jinja2.filters.FILTERS['pmr'] = lambda x: "{:+d}".format(x).replace('-','m').replace('+','p')

gendir = pathlib.Path(__file__).parent
srcdir = gendir.parent / 'src'

with open(gendir / 'weno_smoothness.tmpl.c', 'r') as f:
  smoothness = jinja2.Template(f.read())

with open(gendir / 'weno_reconstruction.tmpl.c', 'r') as f:
  reconstruction = jinja2.Template(f.read())

for k in range(3, 4):
  print('k:', k)
  kernel = pyweno.kernels.KernelGenerator('c', order=2*k-1)
  ksmoothness = kernel.smoothness(reuse=True)

  name = f'smoothness{k:03d}'
  with open(srcdir / f'weno_{name}.c', 'w') as f:
    f.write(smoothness.render(
        name=name, k=k, burnin=kernel.burnin, kernel=ksmoothness))

  for pts in [ 'left', 'right', 'middle' ]:
#               'gauss_legendre', 'gauss_lobatto', 'gauss_radau' ]:

    print('  point:', pts)

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
      kernel = pyweno.kernels.KernelGenerator('c', order=2*k-1, xi=func(n))
      kweights = kernel.weights()
      kreconstruction = kernel.reconstruction()
      sigma = pyweno.symbols.sigma.all(k)
      omega = pyweno.symbols.omega.all(n, k, kernel.split)
      fr    = pyweno.symbols.fr.all(n, k)
      fs    = pyweno.symbols.fs.all(n)

      name = pts + f'{k:03d}{n:03d}'
      with open(srcdir / f'weno_{name}.c', 'w') as f:
        f.write(reconstruction.render(
            name=name, k=k, n=n,
            omega=omega,
            variables={'weights': [ x['name'] for x in sigma ],
                       'reconstruct': [ x['name'] for x in sigma ]
                                    + [ x['name'] for x in omega ]
                                    + [ x['name'] for x in fr ]
                                    + [ x['name'] for x in fs ] },
            weights=kweights, reconstruction=kreconstruction))
