"""PyWENO version information.

   To obtain the version of PyWENO::

     >>> import pyweno.version
     >>> pyweno.version.version()
     >>> pyweno.version.git_version()
"""


def version():
    """Return current version."""
    from pyweno.__version__ import version as v

    return v


def git_version():
    """Return current *git* version (if available)."""
    from pyweno.__git_version__ import version as v

    return v
