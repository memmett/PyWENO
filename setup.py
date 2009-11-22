"""PyWENO setup script."""

import glob
import os
import re

import setuptools

import numpy as np

######################################################################
# version
version = '0.3'
release = False

if not release:
    version += '.a1.dev'


######################################################################
# save git version to 'pyweno/__git_version__.py'

try:
    git_head_file = os.path.join(os.path.dirname(__file__), '.git', 'HEAD')
    f = open(git_head_file)
    m = re.match(r'ref: (.+)', f.readline())
    ref = m.group(1)
    f.close()

    git_head_file = os.path.join(os.path.dirname(__file__), '.git', ref)
    f = open(git_head_file)
    git_version = f.readline().rstrip()
    f.close()

except:
    git_version = 'not_available'

git_version_file = os.path.join(os.path.dirname(__file__),
                                'pyweno','__git_version__.py')
f = open(git_version_file, 'w')
f.write("version = '%s'\n" % (git_version))
f.close()


######################################################################
# save version to 'pyweno/__version__.py'

version_file = os.path.join(os.path.dirname(__file__),
                            'pyweno','__version__.py')
f = open(version_file, 'w')
f.write("version = '%s'\n" % (version))
f.close()


######################################################################
# setup!

setuptools.setup(

    name = "PyWENO",
    version = version,
    packages = ['pyweno'],

    test_suite = 'nose.collector',

    install_requires = [ "numpy >= 1.0.3", "scipy >= 0.7.0", "sympy >= 0.6.5" ],

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

    package_data = {'': ['__version__.py', '__git_version__.py']},
    exclude_package_data = {'': ['.gitignore']},

    author = "Matthew Emmett",
    author_email = "matthew.emmett@ualberta.ca",
    description = "Weighted Essentially Non-oscillatory (WENO) approximation.",
    license = "BSD",
    keywords = "weno",
    url = "http://www.math.ualberta.ca/~memmett/pyweno/"

    )
