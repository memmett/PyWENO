Examples
========

The following are a few selected examples from the ``examples``
directory of PyWENO.


Reconstructing with OpenCL
--------------------------

In this example we use the CLWENO5PM class to reconstruct a
discontinuous function on a uniform grid using OpenCL.

.. literalinclude:: ../examples/clweno5.py

The resulting plot is:

.. image:: ../examples/clweno5.png


Reconstructing a discontinous function on a uniform grid
--------------------------------------------------------

In this example we reconstruct a discontinuous function on a
uniform grid and plot the result.

.. literalinclude:: ../examples/uniform_discontinuous.py

The resulting plot is:

.. image:: ../examples/uniform_discontinuous.png


Pre-computing and caching
-------------------------

In this example we pre-compute all the reconstruction coefficients,
optimal weights, and smoothness indicator ceofficients for a
non-uniform grid and cache everything.

.. literalinclude:: ../examples/cache.py


Reconstructing a smooth function
--------------------------------

In this example we reconstruct a polynomial on a non-uniform grid and
plot the result.

.. literalinclude:: ../examples/smooth.py

The resulting plot is:

.. image:: ../examples/smooth.png


Reconstructing a discontinuous function
---------------------------------------

In this example we reconstruct a discontinuous function on a
non-uniform grid and plot the result.

.. literalinclude:: ../examples/discontinuous.py

The resulting plot is:

.. image:: ../examples/discontinuous.png
