"""The PyWENO module."""

try:
  from importlib import metadata
except ImportError:
  import importlib_metadata as metadata

from . import points
from . import kernels
from . import nonuniform
from . import symbolic
from . import symbols
from . import weno
from . import cweno

__version__ = version = metadata.version('PyWENO')

__all__ = (
  'points',
  'kernels',
  'nonuniform',
  'symbolic',
  'symbols',
  'weno',
  'cweno',
  'version',
  '__version__',
  )
