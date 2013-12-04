PyWENO
======

The PyWENO project provides a set of open source tools for
constructing high-order Weighted Essentially Non-oscillatory (WENO)
methods and performing high-order WENO reconstructions.

PyWENO consists of four main parts:

* :doc:`Symbolics <symbolic>` - tools for exploring and constructing
  WENO methods.

* :doc:`Code generation <codegen>` - tools for generating custom C, Fortran,
  and OpenCL WENO routines.

* :doc:`WENO toolkit <tutorial>` - an easy to use toolkit to easily
  compute WENO reconstructions in Python.

* :doc:`Non-uniform <nonuniform>` - tools for generating WENO methods
  on non-uniform grids.

**News**

* November 12 2013: Several improvements were made to the non-uniform
  module.  These were contributed by Ben Thompson.
* May 15 2012: Several routines were added for computing
  reconstructions of derivatives.  These were contributed by Michael
  Welter.
* January 23 2012: The non-uniform codes have been resurrected.
* June 13 2011: PyWENO has been significantly refactored and
  simplified.  A lot of code was removed in favour of focusing on code
  generation and an easy to use WENO toolkit.

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
   whatsnew
   download

.. _`PyWENO project page`: http://github.com/memmett/PyWENO
.. _`Matthew Emmett`: http://www.unc.edu/~mwemmett/

