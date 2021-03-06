"""PyWENO code generation helpers."""

from sympy.printing.fcode import FCodePrinter as SympyFCodePrinter
from sympy.printing.ccode import CCodePrinter as SympyCCodePrinter
from sympy.printing.precedence import precedence


class FCodePrinter(SympyFCodePrinter):
  pass

class CCodePrinter(SympyCCodePrinter):
  def _print_Pow(self, expr):
    if expr.exp == 2:
      PREC = precedence(expr)
      s = str(self.parenthesize(expr.base, PREC))
      return f'{s}*{s}'
    else:
      return super()._print_Pow(expr)
