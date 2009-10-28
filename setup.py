"""PyWENO setup script."""

import setuptools
import numpy as np

setuptools.setup(

    name = "PyWENO",
    version = "0.1",
    packages = ['pyweno'],

    test_suite = 'nose.collector',

    install_requires = [ "numpy >= 1.0.3", "scipy >= 0.7.0", "h5py >= 1.1.0" ],

    ext_modules = [
        setuptools.Extension('pyweno.cstencil',
                             sources = ['src/cstencil.c'],
                             include_dirs=[np.get_include()]
                             )],

    author = "Matthew Emmett",
    author_email = "matthew.emmett@ualberta.ca",
    description = "Weighted Essentially Non-oscillatory (WENO) approximation.",
    license = "BSD",
    keywords = "weno",
    url = "http://www.math.ualberta.ca/~memmett/pyweno/"

    )
