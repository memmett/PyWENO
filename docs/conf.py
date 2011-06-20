#
# PyWENO documentation build configuration file
#

import sys, os

# path to autogen'ed modules
sys.path.append(os.path.abspath('..'))

# extentions
extensions = ['sphinx.ext.autodoc', 'sphinx.ext.jsmath']
extensions = ['sphinx.ext.autodoc', 'sphinx.ext.jsmath']
jsmath_path = 'http://www.unc.edu/~mwemmett/jsmath/easy/load.js'

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
