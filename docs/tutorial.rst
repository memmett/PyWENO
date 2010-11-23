PyWENO Tutorial
===============

Below are a few quick examples demonstrating how PyWENO is used.  More
detailed examples can be found on the :doc:`examples <examples>` page.


Basic usage
-----------

Briefly, to use PyWENO to reconstruct a function given its cell
averages, we first define the grid::

  >>> x = np.linspace(-10.0, 10.0, 21)
  >>> grid = pyweno.grid.Grid(boundaries=x)

Next, we define a WENO reconstructor and tell it to pre-compute
everything needed to reconstruct a function at the left side of each
cell::

  >>> weno5 = pyweno.weno.WENO(grid=grid, order=3)
  >>> weno5.precompute_reconstruction('left')

Finally, given the cell averages ``f_avg`` of an unkown function *f*,
we can reconstruct *f* at the left side of each cell::

  >>> f_left = np.zeros(grid.size)
  >>> weno5.smoothness(f_avg)
  >>> weno5.reconstruct(f_avg, 'left', f_left)

The reconstructed values are stored in ``f_left``, which should be a
NumPy array.  **Please note** that the reconstructed values are not
returned in a new NumPy array, but are destructively stored in
``f_left``.


More reconstructions and caching
--------------------------------

Here we use PyWENO to reconstruct a function at the left and right
edges of each cell, and take advantage of PyWENOs caching features.

If the cache file doesn't exist we define the grid, pre-compute
everything we need to reconstruct, and cache the results for future
runs::

  >>> k = 3
  >>> cache = 'grid_k%d.h5' % (k)
  >>> if not os.access(cache, os.F_OK):
  >>>     grid = pyweno.grid.Grid(x)
  >>>     weno = pyweno.weno.WENO(grid=grid, order=k)
  >>>
  >>>     weno.precompute_reconstruction('left')
  >>>     weno.precompute_reconstruction('right')
  >>>     weno.cache(cache)

Next, we load from the cache::

  >>> weno = pyweno.weno.WENO(order=k, cache=cache)

Finally, we compute the smoothness of ``f_avg`` and reconstruct::

  >>> weno.smoothness(f_avg)
  >>> weno.reconstrct(f_avg, 'left', f_left)
  >>> weno.reconstrct(f_avg, 'right', f_right)


Version information
-------------------

Here we obtain the version of PyWENO::

  >>> import pyweno.version
  >>> pyweno.version.version()
  >>> pyweno.version.git_version()




