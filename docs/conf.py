#
# PyWENO documentation build configuration file
#

import os
import sys

# path to autogen'ed modules
sys.path.append(os.path.abspath('..'))

# mock out some extension modules
class Mock(object):
    def __init__(self, *args, **kwargs):
        pass

    def __call__(self, *args, **kwargs):
        return Mock()

    @classmethod
    def __getattr__(self, name):
        if name in ('__file__', '__path__'):
            return '/dev/null'
        elif name[0] == name[0].upper():
            return type(name, (), {})
        else:
            return Mock()

for mod_name in [ 'sympy', 'numpy', 'pyweno.codeprinters', 'pyweno.ccoeffs', 'pyweno.cweno' ]:
    sys.modules[mod_name] = Mock()

# extentions
extensions = ['sphinx.ext.autodoc', 'sphinx.ext.mathjax']

# general configuration
source_suffix  = '.rst'
master_doc     = 'index'

# html configuration
pygments_style = 'sphinx'
html_theme     = 'default'

html_sidebars = {
    '**': ['globaltoc.html', 'searchbox.html'],
    }

# project information
project   = 'PyWENO'
copyright = '2009, 2010, 2011, Matthew Emmett'

execfile('../version.py')               # this sets 'version'
release = version
