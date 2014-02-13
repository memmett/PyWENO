Non-uniform grids
=================

PyWENO contains a module to compute all of the various WENO
reconstruction coefficients on non-uniform grids.  The routines to
compute the WENO coefficients in the non-uniform module are very
similiar to those in the symbolic module, except they accept lists (or
NumPy arrays) of cell edges and return NumPy arrays.

Let's compute the reconstruction coefficients to reconstruct at the
left and right endpoints of a cell to fifth order::

  >>> import pyweno.nonuniform
  >>> edges = [ 0.0, 1.0, 2.5, 3.9, 4.7, 5.5, 6.3, 7.8, 8.8, 9.9, 10.5 ]
  >>> c, beta, varpi = pyweno.nonuniform.coefficients(3, [ -1, 1 ], edges)
  >>> c[5]
  array([[[ 1.59025033, -0.81328063,  0.2230303 ],
          [ 0.37096774,  0.71879383, -0.08976157],
          [-0.16666667,  0.83333333,  0.33333333]],

         [[ 0.49407115,  0.6513834 , -0.14545455],
          [-0.24193548,  1.06241234,  0.17952314],
          [ 0.33333333, -1.16666667,  1.83333333]]])

Note that the ``c`` array is indexed according to ``c[i,l,r,j]`` where
``i`` is the cell number, ``l`` is the reconstruction point (eg, 0 is
the left edge and 1 is the right edge), ``r`` is the left-shift of the
stencil, and ``j`` is the summation index.




