"""PyWENO quadrature points.

Requires SymPy.

"""

# Copyright (c) 2011, Matthew Emmett.  All rights reserved.
#
# Redistribution and use in source and binary forms, with or without
# modification, are permitted provided that the following conditions
# are met:
#
#   1. Redistributions of source code must retain the above copyright
#      notice, this list of conditions and the following disclaimer.
#
#   2. Redistributions in binary form must reproduce the above
#      copyright notice, this list of conditions and the following
#      disclaimer in the documentation and/or other materials provided
#      with the distribution.
#
# THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
# "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
# LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS
# FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL THE
# COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT,
# INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING,
# BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
# LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
# CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
# LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN
# ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
# POSSIBILITY OF SUCH DAMAGE.



import numpy as np
import sympy
import sympy.mpmath as mpmath


################################################################################
# polynomial generator, roots etc

def legendre_poly(n):
  '''Return Legendre polynomial P_n(x).

  :param n: polynomial degree
  '''

  x = sympy.var('x')
  p = (1.0*x**2 - 1.0)**n

  top = p.diff(x, n)
  bot = 2**n * 1.0*sympy.factorial(n)
  
  return (top / bot).as_poly()


def find_roots(p):
  '''Return set of roots of polynomial *p*.

  :param p: sympy polynomial

  This uses the *nroots* method of the SymPy polynomial class to give
  rough roots, and subsequently refines these roots to arbitrary
  precision using mpmath.

  Returns a sorted *set* of roots.
  '''

  x = sympy.var('x')
  roots = set()

  for x0 in p.nroots():
    xi = mpmath.findroot(lambda z: p.eval(x, z), x0)
    roots.add(xi)

  return sorted(roots)


################################################################################
# quadrature points


def gauss_legendre(n):
  '''Return Gauss-Legendre nodes.

  Gauss-Legendre nodes are roots of P_n(x).
  '''

  p = legendre_poly(n)
  r = find_roots(p)
  return r


def gauss_lobatto(n):
  """Return Gauss-Lobatto nodes.

  Gauss-Lobatto nodes are roots of P'_{n-1}(x) and -1, 1.
  """

  x = sympy.var('x')
  p = legendre_poly(n-1).diff(x)
  r = find_roots(p)
  r = [mpmath.mpf('-1.0'), mpmath.mpf('1.0')] + r
  return sorted(r)
  

def gauss_radau(n):
  '''Return Gauss-Radau nodes.

  Gauss-Radau nodes are roots of P_n(x) + P_{n-1}(x).
  '''

  p = legendre_poly(n) + legendre_poly(n-1)
  r = find_roots(p)
  return r
