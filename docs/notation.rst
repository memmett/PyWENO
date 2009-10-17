PyWENO notation
===============

A grid over an interval [*a*, *b*] with *N* cells has *N+1* cell
boundaries.  The boundaries are denoted by

.. math:: x_{i-1/2} \quad \text{ for } \quad i = 1,\ldots,N+1

so that

.. math:: a = x_{1/2} < x_{3/2} < \cdots < x_{N-1/2} < x_{N+1/2} = b.

The cells are denoted by

.. math:: C_i = [x_{i-1/2}, x_{i+1/2}] \quad \text{ for } \quad i=1,\ldots,N.


Python notation conventions
---------------------------

Throughout PyWENO:

* A quantity *q* that depends on the cell |C_i| is indexed as ``q[i-1]``.

* A quantity *q* that depends on the cell boundary at |xli| is
  indexed as ``q[i-1]``.

* The variables ``ql`` and ``qr`` denote the quantity *q* approximated
  at the **left** and **right** of the cell.  For example, ``ql[i-1]``
  is *q* approximated at the left boundary of |C_i|.

* The variables ``qm`` and ``qp`` denote the quantity *q* approximated
  at the cell boundaries from the left (minus) and right (plus).  For
  example, ``qm[i-1]`` is *q* approximated from the left at the
  boundary |xli|.



.. |C_i| replace:: :math:`C_i`
.. |xli| replace:: :math:`x_{i - 1/2}`

