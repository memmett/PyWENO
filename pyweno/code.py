
from sympy.printing.fcode import FCodePrinter as SympyFCodePrinter
from sympy.printing.ccode import CCodePrinter as SympyCCodePrinter


class FCodePrinter(SympyFCodePrinter):
  def _print_int(self, expr):
    return "%d.0d0" % int(expr)

class CCodePrinter(SympyCCodePrinter):
  pass
