Documentation
=============

Tutorial
--------

Briefly, to use PyWENO to reconstruct a function given its cell
averages, we first define the grid::

  >>> x = np.linspace(-10.0, 10.0, 21)
  >>> grid = pyweno.grid.Grid(boundaries=x)

Next, we define a WENO reconstructor and tell it to pre-compute
everything needed to reconstruct a function at the left side of each
cell::

  >>> weno5 = pyweno.weno.WENO(grid=grid, order=3)
  >>> weno5.reconstruction('left')

Finally, given the cell averages f_avg of f, we can reconstruct f at
the left side of each cell::

  >>> f_left = np.zeros(grid.size)
  >>> sigma = np.zeros((grid.size, weno.order))
  >>> weno5.smoothness(f_avg, sigma)
  >>> weno5.reconstruct(f_avg, 'left', sigma, f_left)

To learn more about how PyWENO is used, check out some :doc:`examples
<examples>`.

To obtain the version of PyWENO::

  >>> import pyweno.version
  >>> pyweno.version.version()
  >>> pyweno.version.git_version()


.. XXX, this needs work!  perhaps some of the examples should be moved here...


Mathematics
-----------

For all the gory details of the mathematics behind WENO
approximations, check out Matthew's :download:`WENO <weno.pdf>`
document.


Reference
---------

* :doc:`WENO, Grid, and Stencil classes <weno>`
* :doc:`Smoothness indicators <smoothness>`

.. XXX, add version information

.. toctree::
   :hidden:

   examples
   weno
   smoothness
