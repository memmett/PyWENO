"""PyWENO symbol generators."""

import sympy

real = lambda x: sympy.Symbol(str(x), real=True)

class names(object):
  lang   = 'c'
  sigma  = 'sigma{}'
  omega  = 'omega{}r{}'
  f_star = 'fs{}'
  f_r    = 'fr{}r{}'
  f_mn   = 'f{:+d}{:+d}'
  f = {
    'c':       'f[(i{:+d})*fsi]',
    'opencl':  'f[(i{:+d})*fsi]',
    'fortran': 'f(i{:+d})'
    }

class SigmaGenerator(object):
  def __getitem__(self, idx):
    tmp = getattr(names, 'sigma')
    return real(tmp.format(idx))
  def all(self, k):
    return [ { 'r': r, 'name': self[r] } for r in range(0, k) ]

sigma = SigmaGenerator()

class OmegaGenerator(object):
  def __getitem__(self, idx):
    tmp = getattr(names, 'omega')
    if len(idx) == 3:
      return real(tmp.format(*idx[:2]) + ['p','m'][idx[2]])
    return real(tmp.format(*idx))
  def all(self, n, k, split):
    all = []
    for l in range(n):
      if not split[l]:
        for r in range(0, k):
          all.append({ 'l': l, 'r': r, 's': 0, 'pm': '', 'name': self[l,r] })
      else:
        for r in range(0, k):
          all.append({ 'l': l, 'r': r, 's': 0, 'pm': 'p', 'name': self[l,r,0] })
          all.append({ 'l': l, 'r': r, 's': 1, 'pm': 'm', 'name': self[l,r,1] })
    return all

omega = OmegaGenerator()

class FStarGenerator(object):
  def __getitem__(self, idx):
    tmp = getattr(names, 'f_star')
    return real(tmp.format(idx))
  def all(self, n):
    return [ { 'l': l, 'name': self[l] } for l in range(n) ]

fs = FStarGenerator()

class FRGenerator(object):
  def __getitem__(self, idx):
    tmp = getattr(names, 'f_r')
    return real(tmp.format(*idx))
  def all(self, n, k):
    return [ { 'l': l, 'r': r, 'name': self[l,r] } for l in range(n) for r in range(k) ]

fr = FRGenerator()

class FGenerator(object):
  def __getitem__(self, idx):
    tmp = getattr(names, 'f')[names.lang]
    return real(tmp.format(idx))

f = FGenerator()

class FMNGenerator(object):
  def __getitem__(self, idx):
    tmp = getattr(names, 'f_mn')
    return real(tmp.format(*idx).replace('-','m').replace('+','p'))

fmn = FMNGenerator()
