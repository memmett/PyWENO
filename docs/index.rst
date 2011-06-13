PyWENO
======

The PyWENO project provides a set of open sources tools for
constructing high-order Weighted Essentially Non-oscillatory (WENO)
methods and performing high-order WENO reconstructions.

The project consists of four main parts:

#. A set of :doc:`symbolic tools <symbolic>` for exploring and
   constructing WENO methods;

#. A C, Fortran, and OpenCL :doc:`code generator <codegen>` to build WENO
   reconstruction routines; 

#. An easy to use :doc:`interface <tutorial>` to compute WENO
   reconstructions; and

#. Various other WENO related tools, including: a routine for
   computing high-order finite-volume interpolation coefficients for
   non-uniform grids.

**News**

* June 13 2011: A new `WENO SciKit`_ built using PyWENO is now available.
* June 13 2011: PyWENO has been significantly refactored and
  simplified.  A lot of code was removed in favour of focusing on code
  generation and an easy to use WENO SciKit.
* January 20 2011: `PyWENO 0.5.11`_ released (see :doc:`what's new <whatsnew>`).

Please check out the documentation (below) or the `PyWENO project
page`_ for more information about using and contributing to PyWENO.


Documentation
-------------

**Main parts of the documentation**

* :doc:`WENO SciKit Tutorial <tutorial>` - basic WENO reconstructions.
* :doc:`Symbolics <symbolic>` - the symbolic tool kit.
* :doc:`Code generation <codegen>` - the code generation tool kit.
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
   reference
   whatsnew
   download

.. _`WENO SciKit`: XXX
.. _`SciKit interface`: 
.. _`PyWENO project page`: http://github.com/memmett/PyWENO
.. _`Matthew Emmett`: http://www.math.ualberta.ca/~memmett/
.. _`semantic versioning`: http://semver.org/
.. _`PyBLAW`: http://memmett.github.com/PyBLAW
.. _`Python Balance LAW`: http://memmett.github.com/PyBLAW
.. _`PyWENO 0.4.0`: http://github.com/memmett/PyWENO/downloads
.. _`PyWENO 0.5.0`: http://github.com/memmett/PyWENO/downloads
.. _`PyWENO 0.5.7`: http://github.com/memmett/PyWENO/downloads
.. _`PyWENO 0.5.9`: http://github.com/memmett/PyWENO/downloads
.. _`PyWENO 0.5.11`: http://github.com/memmett/PyWENO/downloads
