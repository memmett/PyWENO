PyWENO
======

PyWENO is a Python module for computing high-order Weighted
Essentially Non-oscillatory (WENO) reconstructions of cell-averaged
data arrays.

The basic interface provides a simple routine to compute 1D
reconstructions at various points within each grid cell.  The points
at which the basic interface can reconstruct the original function at
include: left edge, right edge, Gauss-Legendre quadrature points,
Gauss-Lobatto quadrature points, and Guass-Radau quadrature points.

PyWENO can also be used as a code generator to build custom WENO
reconstructors in C, Fortran, and OpenCL on uniform grids.

Please see

  http://readthedocs.org/docs/pyweno/en/latest/

for more information.


Important links
---------------

  * Official project page: https://github.com/memmett/PyWENO
  * Documentation: http://readthedocs.org/docs/pyweno/en/latest/


Prerequisites
-------------

To install PyWENO, you need:

  * NumPy
  * SymPy    (optional if you avoid pyweno.symbolic)


Testing
-------

To build PyWENO and create symlinks to the extension modules:

  $ python setup.py build
  $ cd pyweno
  $ for so in ../build/lib*/pyweno/*.so; do ln -s $so; done

Now, nosetests should work:

  $ nosetests


License
-------

Please see LICENSE for copyright information.


Contributors
------------

* Matthew Emmett
* Michael Welter
* Ben Thompson
