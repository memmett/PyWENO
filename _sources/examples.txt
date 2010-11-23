PyWENO Examples
===============

Throughout these examples we will reconstruct:

* functions at the left and right edges of each cell,

* functions at the Gaussian 3-point quadrature points within each cell,

* and the first derivative of functions at the Gaussian 3-point
  quadrature points.


Reconstructing with OpenCL
--------------------------

In this example we use the CLWENO5PM class to reconstruct using
OpenCL.

.. literalinclude:: ../examples/clweno5.py

The resulting plot is:

.. image:: ../examples/clweno5.png



Pre-computing and caching
-------------------------

In this example we pre-compute all the reconstruction coefficients,
optimal weights, and smoothness indicator ceofficients and cache
everything.

.. literalinclude:: ../examples/cache.py


Reconstructing a smooth function
--------------------------------

In this example we reconstruct a polynomial and plot the result.

.. literalinclude:: ../examples/smooth.py

The resulting plot is:

.. image:: ../examples/smooth.png


Reconstructing a discontinuous function
---------------------------------------

In this example we reconstruct a discontinuous function and plot the
result.

.. literalinclude:: ../examples/discontinuous.py

The resulting plot is:

.. image:: ../examples/discontinuous.png

