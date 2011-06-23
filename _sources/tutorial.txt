WENO SciKit
===========

WENO reconstructions
--------------------

High-order WENO reconstructions for 1d arrays of cell-average
quantities can be computed with the ``scikits.weno`` module.

For example, to reconstruct *sin(x)* at the left edge of each cell to
fifth order accuracy::

  >>> import numpy as np
  >>> import scikits.weno
  >>> x = np.linspace(0.0, 2*np.pi, 21)
  >>> f = (np.cos(x[1:]) - np.cos(x[:-1])) / (x[1] - x[0])
  >>> q = scikits.weno.reconstruct(f, 5, 'left')

Please see the :doc:`reference documentation <reference>` for more
information.

Smooth reconstruction
^^^^^^^^^^^^^^^^^^^^^

Here we reconstruct *sin(x)* at the left and right edges of each cell
to fifth order accuracy and plot the results:

.. image:: ../examples/smooth.png

The code to generate the above is in :download:`smooth.py <../examples/smooth.py>`.


Discontinuous reconstruction
^^^^^^^^^^^^^^^^^^^^^^^^^^^^

Here we reconstruct a discontinuous function (*sin(x)* for *x<0*,
*cos(x)* for *x>0*) at the left and right edges of each cell to fifth
order accuracy and plot the results:

.. image:: ../examples/discontinuous.png

The code to generate the above is in :download:`discontinuous.py <../examples/discontinuous.py>`.


Non-uniform reconstruction coefficients
---------------------------------------

Reconstruction coefficients for arbitrary points within a non-uniform
grid can be computed with the ``scikits.weno`` as well.

For example, XXX


Version information
-------------------

Here we obtain the version of PyWENO::

  >>> import pyweno.version
  >>> pyweno.version.version()
  >>> pyweno.version.git_version()




