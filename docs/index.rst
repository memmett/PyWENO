PyWENO
======

PyWENO is a Python implementation of one-dimensional Weighted
Essentially Non-oscillatory (WENO) approximations over unstructured
(non-uniform) grids.


News
----

PyWENO is in early development, and is a bit rough around the edges.


Documentation
-------------

Check out the :doc:`documentation page <documentation>` for a
tutorial, reference, and the maths behind PyWENO.


Features
--------

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
    that would appear in loops are implemented in C.

  * Be easy to use.


Usage
-----

Briefly, to use PyWENO to reconstruct a function given its cell
averages, we first define the grid::

  >>> x = np.linspace(-10.0, 10.0, 21)
  >>> grid = pyweno.grid.Grid(boundaries=x)

Next, we define a WENO reconstructor and tell it to pre-compute
everything needed to reconstruct a function at the left side of each
cell::

  >>> weno5 = pyweno.weno.WENO(grid=grid, order=3)
  >>> weno5.precompute_reconstruction('left')

Finally, given the cell averages f_avg of f, we reconstruct f at the
left side of each cell::

  >>> f_left = np.zeros(grid.size)
  >>> weno5.smoothness(f_avg)
  >>> weno5.reconstruct(f_avg, 'left', f_left)


Known issues
------------

PyWENO has a few known issues:

  * Domain boundaries are avoided.
  * Pre-computing the optimal weights is slow.
  * Pre-computing the smoothness indicator coefficients is slow.


Download
--------

Check out the :doc:`download page <download>` for instructions on
obtaining and installing PyWENO.


Related projects
----------------

Adrian Townsend (University of Washington) is working on a Python
implementation of WENO interpolations and reconstructions as well.


Contributing
------------

Contributions are welcome!  Please send comments, suggestions, and/or
patches to the primary author (`Matthew Emmett`_).  You will be credited.


If you plan to extend or modify PyWENO in a more substantial way,
please see the `PyWENO project page`_.


.. toctree::
   :hidden:

   self
   documentation
   download

.. _`PyWENO project page`: http://github.com/memmett/PyWENO
.. _`Matthew Emmett`: http://www.math.ualberta.ca/~memmett/
