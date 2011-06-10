"""PyWENO setup script."""

import glob
import os
import re

from distutils.core import setup
from distutils.extension import Extension as extension

import numpy as np

######################################################################
# version
execfile('version.py')                  # this sets 'version'


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

setup(

    name = "PyWENO",
    version = version,
    packages = ['pyweno'],

    # XXX
    requires = [],

    ext_modules = [
        extension('pyweno.cstencil',
                  sources = ['src/cstencil.c'] + glob.glob('src/reconstruction*.c'),
                  include_dirs=[np.get_include()]
                  ),
        extension('pyweno.cweno',
                  sources = ['src/cweno.c'],
                  include_dirs=[np.get_include()]
                  ),
        extension('pyweno.csmoothness',
                  sources = ['src/csmoothness.c'],
                  include_dirs=[np.get_include()]
                  )],

    package_data = {'': ['__version__.py', '__git_version__.py']},

    author = "Matthew Emmett",
    author_email = "memmett@unc.edu",
    description = "Weighted Essentially Non-oscillatory (WENO) approximation.",
    license = "BSD",
    keywords = "weno",
    url = "http://memmett.github.com/PyWENO/"

    )
