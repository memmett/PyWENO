PyWENO
======

PyWENO is a Python module for computing high-order Weighted
Essentially Non-oscillatory (WENO) reconstructions.

The PyWENO project is comprised of three main parts:

#. A set of symbolic tools for exploring and constructing WENO
   methods;

#. A code generator (C, Fortran, and OpenCL) that generates code to
   compute WENO reconstructions at arbitrary points on one-dimensional
   uniform grids; and

#. An easy to use SciKit interace to compute WENO reconstructions at
   various points.


**News**

* June 13 2011: A new `WENO SciKit`_ built using PyWENO is now available.
* June 13 2011: PyWENO has been significantly refactored.  A lot of
  code was removed in favour of focusing on code generation and a very
  simple WENO SciKit.
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


Download
--------

Check out the :doc:`download page <download>` for instructions on
obtaining and installing PyWENO.


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
