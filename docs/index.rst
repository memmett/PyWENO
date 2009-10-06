PyWENO
======

PyWENO implements one-dimensional Weighted Essentially Non-oscillatory
(WENO) approximations over unstructured (non-uniform) grids.

Please see Matthew's :download:`WENO <WENO.pdf>` document for the
mathematics behind PyWENO.

Check out some :doc:`examples <examples>` to learn more about what
PyWENO is all about.

Obtaining PyWENO
----------------

Download, build, and install :download:`PyWENO 0.1
<PyWENO-0.1.tar.gz>` from source.

The following is helpful::

  $ python setup.py develop -d <your python path>


API
---

* :doc:`WENO, Grid, and Stencil classes <weno>`
* :doc:`Smoothness indicators <smoothness>`

Contributing
------------

Contributions are welcome!  Please send comments, suggestions, and/or
patches to the primary author (Matthew Emmett).  You will be credited.

If you plan to extend or modify PyWENO in a more substantial way,
please let the author know (so that we can create a central
repository).


.. toctree::
   :hidden:

   self
   examples
   weno
   smoothness
