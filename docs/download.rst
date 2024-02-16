Downloading and installing
==========================

From PyPI
---------

The PyWENO package is registered on the Python package index.  If you
have `pip`_ installed, you can install PyWENO by::

  $ pip install pyweno

From GitHub
-----------

The latest source distribution is also available in either zip_ or
tar_ format.  Finally, you can also obtain the source code on GitHub
through the `PyWENO project page`_.

When using the source code from GitHub, keep in mind that PyWENO uses the
`meson-python <https://meson-python.readthedocs.io>`__ build system and requires
both ``meson`` and ``ninja`` to be available locally to build the project. For
development, an editable build is recommended::

  $ pip install --no-build-isolation --editable .

To create wheels or your own source distributions, you can use::

  $ python -m build --wheel
  $ python -m build --sdist

Tracking the development repository
-----------------------------------

You can clone the project by running::

  $ git clone git://github.com/memmett/PyWENO

.. _zip: http://github.com/memmett/PyWENO/zipball/master
.. _tar: http://github.com/memmett/PyWENO/tarball/master
.. _`PyWENO project page`: http://github.com/memmett/PyWENO
.. _`pip`: http://pypi.python.org/pypi/pip

