WENO toolkit
============

WENO reconstructions
--------------------

High-order WENO reconstructions for 1d arrays of cell-average
quantities can be computed with the ``pyweno.weno`` module.

For example, to reconstruct *sin(x)* at the left edge of each cell to
fifth order accuracy::

  >>> import numpy as np
  >>> import pyweno.weno
  >>> x = np.linspace(0.0, 2*np.pi, 21)
  >>> f = (np.cos(x[1:]) - np.cos(x[:-1])) / (x[1] - x[0])
  >>> q = pyweno.weno.reconstruct(f, 5, 'left')

Please see the :doc:`reference documentation <reference>` for more
information.

Smooth reconstruction
^^^^^^^^^^^^^^^^^^^^^

Here we reconstruct *sin(x)* at the left and right edges of each cell
to fifth order accuracy and plot the results:

.. image:: ../examples/smooth.png

The code to generate the above is in
:download:`smooth.py <../examples/smooth.py>`.


Discontinuous reconstruction
^^^^^^^^^^^^^^^^^^^^^^^^^^^^

Here we reconstruct a discontinuous function (*sin(x)* for *x<0*,
*cos(x)* for *x>0*) at the left and right edges of each cell to fifth
order accuracy and plot the results:

.. image:: ../examples/discontinuous.png

The code to generate the above is in
:download:`discontinuous.py <../examples/discontinuous.py>`.


Version information
-------------------

PyWENO uses standard Python packaging, so its version information can be obtained
through ``importlib``. However, you can also get it from the module itself::

  >>> from pyweno import __version__
  >>> __version__
  '0.11.2'




