"""PyWENO setup script."""

import setuptools

import glob
import numpy as np

setuptools.setup(

    name = "PyWENO",
    version = "0.1",
    packages = ['pyweno'],
    exclude_package_data = {'': ['.gitignore']},

    test_suite = 'nose.collector',

    install_requires = [ "numpy >= 1.0.3", "scipy >= 0.7.0" ],

    ext_modules = [
        setuptools.Extension('pyweno.cstencil',
                             sources = ['src/cstencil.c'] + glob.glob('src/reconstruction*.c'),
                             include_dirs=[np.get_include()]
                             ),
        setuptools.Extension('pyweno.cweno',
                             sources = ['src/cweno.c'],
                             include_dirs=[np.get_include()]
                             ),
        setuptools.Extension('pyweno.csmoothness',
                             sources = ['src/csmoothness.c'],
                             include_dirs=[np.get_include()]
                             )],

    author = "Matthew Emmett",
    author_email = "matthew.emmett@ualberta.ca",
    description = "Weighted Essentially Non-oscillatory (WENO) approximation.",
    license = "BSD",
    keywords = "weno",
    url = "http://www.math.ualberta.ca/~memmett/pyweno/"

    )
