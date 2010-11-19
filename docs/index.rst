PyWENO
======

PyWENO is a Python implementation of one-dimensional Weighted
Essentially Non-oscillatory (WENO) approximations over unstructured
(non-uniform) grids.

**News**

* November 19 2010: PyWENO now has preliminary support for OpenCL (GPUs).
* October 17 2010: `PyWENO 0.5.7`_ released (see :doc:`what's new <whatsnew>`).
* February 22 2010: `PyWENO 0.5.0`_ released (see :doc:`what's new <whatsnew>`).
* January 29 2010: `PyWENO 0.4.0`_ released (see :doc:`what's new <whatsnew>`).
* January 29 2010: PyWENO now uses `semantic versioning`_.
* November 26 2009: PyWENO 0.3.a1 released.
* Fall 2009: PyWENO is in early development, and is a bit rough around
  the edges.

Please check out the documentation (below) or the `PyWENO project
page`_ for more infomation about using and contributing to PyWENO.

**Using PyWENO to solve PDEs**: if you are interested in using PyWENO
to solve PDEs, check out the `Python Balance LAW`_ package `PyBLAW`_.


Documentation
-------------

**Main parts of the documentation**

* :doc:`Tutorial <tutorial>` - basic usage.
* :doc:`Examples <examples>` - more detailed examples.
* :doc:`Reference <reference>` - reference documentation.
* :download:`Maths <weno.pdf>` (PDF) - the maths behind WENO approximations.


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

* Pre-computing the optimal weights is slow.
* Pre-computing the smoothness indicator coefficients is slow.


**Related projects**

Adrian Townsend (University of Washington) is working on a Python
implementation of WENO interpolations and reconstructions as well.

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
