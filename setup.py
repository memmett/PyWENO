'''PyWENO setup script.'''

import glob
import os
import re

from setuptools import setup, Extension
import numpy as np


###############################################################################
# version

with open('version.py', 'r') as f:
    exec(f.read())                  # this sets 'version'

with open('README', 'r') as file:
    long_description = file.read()


###############################################################################
# save git version to 'pyweno/__git_version__.py'

try:
    git_head_file = os.path.join(os.path.dirname(__file__), '.git', 'HEAD')
    with open(git_head_file) as f:
        m = re.match(r'ref: (.+)', f.readline())
        ref = m.group(1)

    git_head_file = os.path.join(os.path.dirname(__file__), '.git', ref)
    with open(git_head_file) as f:
        git_version = f.readline().rstrip()
except:
    git_version = 'not_available'

git_version_file = os.path.join(os.path.dirname(__file__),
                                'pyweno','__git_version__.py')
with open(git_version_file, 'w') as f:
    f.write("version = '%s'\n" % (git_version))


###############################################################################
# save version to 'pyweno/__version__.py'

version_file = os.path.join(os.path.dirname(__file__),
                            'pyweno','__version__.py')

with open(version_file, 'w') as f:
    f.write("version = '%s'\n" % (version))


###############################################################################
# setup!

setup(

    name         = "PyWENO",
    packages     = ['pyweno'],
    version      = version,
    author       = "Matthew Emmett",
    author_email = "matthew@emmett.ca",
    description  = "Weighted Essentially Non-oscillatory (WENO) reconstructions.",
    license      = "BSD",
    keywords     = "weno, interpolate, interpolation, finite, volume",
    url          = "http://readthedocs.org/docs/pyweno/en/latest/",

    ext_modules = [
        Extension('pyweno.ccoeffs',
                  sources = ['src/ccoeffs.c'] + glob.glob('src/coeffs*.c'),
                  include_dirs=[np.get_include()]
                  ),
        Extension('pyweno.cweno',
                  sources = ['src/cweno.c'] + glob.glob('src/weno*.c'),
                  include_dirs=[np.get_include()],
                  extra_compile_args = ['-std=c99'],
                  ),
        Extension('pyweno.cnonuniform',
                  sources = ['src/nfweno.c', 'src/poly.c'],
                  include_dirs=[np.get_include()],
                  extra_compile_args = ['-std=c99'],
                  )],

    long_description = long_description,

    classifiers = [
        'Development Status :: 4 - Beta',
        'Development Status :: 5 - Production/Stable',
#        'Development Status :: 6 - Mature',
        'Intended Audience :: Science/Research',
        'License :: OSI Approved :: BSD License',
        'Operating System :: OS Independent',
        'Programming Language :: Python ',
        'Programming Language :: C',
        'Programming Language :: Fortran',
        'Topic :: Scientific/Engineering',
        'Topic :: Scientific/Engineering :: Mathematics',
        ],

    )
