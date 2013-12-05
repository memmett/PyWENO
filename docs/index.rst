PyWENO
======

The PyWENO project provides a set of open source tools for
constructing high-order Weighted Essentially Non-oscillatory (WENO)
methods and performing high-order WENO reconstructions.

PyWENO consists of four main parts:

* :doc:`WENO toolkit <tutorial>` - an easy to use toolkit to easily
  compute WENO reconstructions in Python.

* :doc:`Symbolics <symbolic>` - tools for exploring and constructing
  WENO methods.

* :doc:`Code generation <codegen>` - tools for generating custom C, Fortran,
  and OpenCL WENO routines.

* :doc:`Non-uniform <nonuniform>` - tools for generating WENO methods
  on non-uniform grids.

**News**

* December 4 2013: The kernel generator has been simplified a lot and
  the functional generator was removed.  Several more (speed)
  improvements were made to the non-uniform module.
* November 12 2013: Several improvements were made to the non-uniform
  module.  These were contributed by Ben Thompson.
* May 15 2012: Several routines were added for computing
  reconstructions of derivatives.  These were contributed by Michael
  Welter.
* January 23 2012: The non-uniform codes have been resurrected.

Please check out the documentation (below) or the `PyWENO project
page`_ for more information about using and contributing to PyWENO.


Documentation
-------------

**Main parts of the documentation**

* :doc:`WENO tutorial <tutorial>` - basic WENO reconstructions.
* :doc:`Symbolics <symbolic>` - the symbolic tool kit.
* :doc:`Code generation <codegen>` - the code generation tool kit.
* :doc:`Non-uniform <nonuniform>` - the non-uniform grid tool kit.
* :doc:`Reference <reference>` - reference documentation.
* :doc:`Download <download>` - download and installation instructions.


Contributing
------------

Contributions are welcome!  Please send comments, suggestions, and/or
patches to the primary author (`Matthew Emmett`_).  You will be credited.

.. toctree::
   :hidden:

   self
   tutorial
   symbolic
   codegen
   nonuniform
   reference
   download

.. _`PyWENO project page`: http://github.com/memmett/PyWENO
.. _`Matthew Emmett`: http://www.unc.edu/~mwemmett/

