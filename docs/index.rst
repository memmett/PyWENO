PyWENO
======

PyWENO is a Python implementation of one-dimensional Weighted
Essentially Non-oscillatory (WENO) approximations over unstructured
(non-uniform) grids.

For all the gory details of the mathematics behind WENO
approximations, check out Matthew's :download:`WENO <weno.pdf>`
document.

To learn more about how PyWENO is used, check out some :doc:`examples
<examples>`.

Keep the :doc:`notation <notation>` guide handy to avoid becoming
horribly confused.


Obtaining PyWENO
----------------

Download, build, and install from source.

The latest source distribution is available in either zip_ or tar_
format.  You can also obtain the source code on GitHub through the
`PyWENO project page`_.  You can clone the project by running::

  $ git clone git://github.com/memmett/PyWENO

PyWENO uses the Python setuptools_ package for installation.


API documentation
-----------------

* :doc:`WENO, Grid, and Stencil classes <weno>`
* :doc:`Smoothness indicators <smoothness>`


Contributing
------------

Contributions are welcome!  Please send comments, suggestions, and/or
patches to the primary author (Matthew Emmett).  You will be credited.


If you plan to extend or modify PyWENO in a more substantial way,
please see the `PyWENO project page`_.



.. toctree::
   :hidden:

   self
   notation
   examples
   weno
   smoothness


.. _zip: http://github.com/memmett/PyWENO/zipball/master
.. _tar: http://github.com/memmett/PyWENO/tarball/master
.. _setuptools: http://pypi.python.org/pypi/setuptools
.. _`PyWENO project page`: http://github.com/memmett/PyWENO
