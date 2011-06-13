WENO SciKit
===========

Below are a few quick examples demonstrating how to use the WENO
SciKit to compute WENO reconstructions.


Basic usage
-----------

Given an array *f* with cell-averaged quantities, various WENO
reconstructions can be computed with the WENO SciKit ``scikits.weno``.
For example, to reconstruct *sin(x)* at the left edge of each cell to
fifth order accuracy::

  >>> x = np.linspace(0.0, 2*np.pi, 21)
  >>> f = np.cos(x[1:]) - np.cos(x[:-1])
  >>>
  >>> import scikits.weno
  >>> q = scikits.weno.reconstruct(f, 5, 'left')

Please see the :doc:`reference documentation <reference>` for more
information.

.. ::
   XXX: another example with a plot would be nice


Version information
-------------------

Here we obtain the version of PyWENO::

  >>> import pyweno.version
  >>> pyweno.version.version()
  >>> pyweno.version.git_version()




