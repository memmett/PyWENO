#
# PyWENO documentation build configuration file
#

import os
import sys

try:
    from importlib import metadata
except ImportError:
    import importlib_metadata as metadata

# path to autogen'ed modules
sys.path.append(os.path.abspath('..'))
m = metadata.metadata('PyWENO')

# extentions
extensions = [
    'sphinx.ext.autodoc',
    'sphinx.ext.mathjax',
    ]

# general configuration
source_suffix  = '.rst'
master_doc     = 'index'

# html configuration
pygments_style = 'sphinx'
html_theme     = 'sphinx_rtd_theme'

html_sidebars = {
    '**': ['globaltoc.html', 'searchbox.html'],
    }

# project information
project   = m['Name']
author = m['Author-email']
copyright = f'2009, 2010, 2011 {author}'
release = m['Version']
