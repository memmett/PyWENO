#
# PyWENO documentation build configuration file
#

import sys, os

# path to autogen'ed modules
sys.path.append(os.path.abspath('..'))

# extentions
extensions = ['sphinx.ext.autodoc', 'sphinx.ext.pngmath']

# general configuration
#exclude_trees  = ['_build']
source_suffix  = '.rst'
master_doc     = 'index'

# html configuration
pygments_style = 'sphinx'
html_theme     = 'default'

# project information
project   = 'PyWENO'
copyright = '2009, Matthew Emmett'
version   = '0.1'
release   = '0.1'
