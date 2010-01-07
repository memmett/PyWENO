PyWENO
======

PyWENO is a Python implementation of one-dimensional Weighted
Essentially Non-oscillatory (WENO) approximations over unstructured
(non-uniform) grids.

**News**

* November 26 2009: `PyWENO 0.3.a1`_ released.
* Fall 2009: PyWENO is in early development, and is a bit rough around
  the edges.


Documentation
-------------

**Main parts of the documentation**

* :doc:`Tutorial <tutorial>` - basic usage.
* :doc:`Examples <examples>` - more detailed examples.
* :doc:`Reference <reference>` - reference documentation.
* :download:`Maths <weno.pdf>` - the maths behind WENO


**Features**

PyWENO is designed to:

* Work on unstructured (and structured) grids.

* Reconstruct at arbitrary points within each grid cell.  For
  example, we can reconstruct a function at the left edge, right
  edge, or at various quadrature points within each cell.

* Reconstruct derivatives at arbitrary points with each grid cell
  too.

* Cache the reconstruction coefficients, optimal weights, and
  smoothness indicator coefficients for a given grid (for future
  runs).

* Be fast (except for pre-computing).  The time sensitive routines
  (eg, that might appear in loops) are implemented in C.

* Be easy to use.


**Known issues**

PyWENO has a few known issues:

* Domain boundaries are avoided.
* Pre-computing the optimal weights is slow.
* Pre-computing the smoothness indicator coefficients is slow.


**Related projects**

Adrian Townsend (University of Washington) is working on a Python
implementation of WENO interpolations and reconstructions as well.


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
   reference
   examples
   download

.. _`PyWENO project page`: http://github.com/memmett/PyWENO
.. _`Matthew Emmett`: http://www.math.ualberta.ca/~memmett/
.. _`PyWENO 0.3.a1`: http://cloud.github.com/downloads/memmett/PyWENO/PyWENO-0.3.a1.tar.gz
