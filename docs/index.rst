PyWENO
======

PyWENO is a Python implementation of one-dimensional Weighted
Essentially Non-oscillatory (WENO) approximations over non-uniform
grids.

**News**

* November 27 2010: `PyWENO 0.5.9`_ released (see :doc:`what's new <whatsnew>`).
* November 19 2010: PyWENO now has preliminary support for OpenCL (GPUs).
* October 17 2010: `PyWENO 0.5.7`_ released (see :doc:`what's new <whatsnew>`).
* February 22 2010: `PyWENO 0.5.0`_ released (see :doc:`what's new <whatsnew>`).
* January 29 2010: `PyWENO 0.4.0`_ released (see :doc:`what's new <whatsnew>`).
* January 29 2010: PyWENO now uses `semantic versioning`_.

PyWENO is useful for:

* Numerically reconstructing an unknown function based on its cell
  averages over uniform or non-uniform grids.

* Exploring WENO methods symbolically.

* Building custom high-performance OpenCL based WENO codes.

If you are interested in using PyWENO to solve systems of hyperbolic
PDEs, check out the `Python Balance LAW`_ package `PyBLAW`_.

Please check out the documentation (below) or the `PyWENO project
page`_ for more information about using and contributing to PyWENO.


Documentation
-------------

**Main parts of the documentation**

* :doc:`Tutorial <tutorial>` - basic numerical usage.
* :doc:`Symbolic <symbolic>` - the symbolic toolkit.
* :doc:`OpenCL <opencl>` - the OpenCL code generator.
* :doc:`Examples <examples>` - some examples.
* :doc:`Reference <reference>` - reference documentation.
* :download:`Maths <weno.pdf>` (PDF) - the maths behind WENO approximations.


**Features**

PyWENO is designed to:

* Work on non-uniform and uniform grids.

* Reconstruct at arbitrary points within each grid cell.  For
  example, we can reconstruct a function at the left edge, right
  edge, or at various quadrature points within each cell.

* Be fast (except for pre-computing); time sensitive routines are
  implemented in C.  Some specialized routines are also implemented in
  OpenCL.

* Provide a set of symbolic tools to help authors develop specialized
  WENO methods.

* Provide a set of OpenCL kernels and OpenCL code generation tools to
  help authors develop specialized WENO methods.

* Be easy to use.

* For non-uniform grids, cache the reconstruction coefficients,
  optimal weights, and smoothness indicator coefficients for a given
  grid (for future runs).


**Known issues**

PyWENO has a few known issues:

* Pre-computing the optimal weights on non-uniform grids is slow.
* Pre-computing the smoothness indicator coefficients on non-uniform
  grids is slow.


**Related projects**

Adrian Townsend (University of Washington) is working on a Python
implementation of WENO interpolations and reconstructions as well.

David Ketcheson (KAUST) wrote WENOCLAW, which uses WENO methods to
solve conservation laws, and is based on the CLAWPACK software of
R.J. LeVeque.

**Using PyWENO to solve PDEs**: if you are interested in using PyWENO
to solve PDEs, check out the `Python Balance LAW`_ package `PyBLAW`_.


Download
--------

Check out the :doc:`download page <download>` for instructions on
obtaining and installing PyWENO.


Contributing
------------

Contributions are welcome!  Please send comments, suggestions, and/or
patches to the primary author (`Matthew Emmett`_).  You will be credited.

If you plan to extend or modify PyWENO in a more substantial way,
please see the `PyWENO project page`_.


.. toctree::
   :hidden:

   self
   tutorial
   symbolic
   opencl
   reference
   examples
   whatsnew
   download

.. _`PyWENO project page`: http://github.com/memmett/PyWENO
.. _`Matthew Emmett`: http://www.math.ualberta.ca/~memmett/
.. _`semantic versioning`: http://semver.org/
.. _`PyBLAW`: http://memmett.github.com/PyBLAW
.. _`Python Balance LAW`: http://memmett.github.com/PyBLAW
.. _`PyWENO 0.4.0`: http://github.com/memmett/PyWENO/downloads
.. _`PyWENO 0.5.0`: http://github.com/memmett/PyWENO/downloads
.. _`PyWENO 0.5.7`: http://github.com/memmett/PyWENO/downloads
.. _`PyWENO 0.5.9`: http://github.com/memmett/PyWENO/downloads
