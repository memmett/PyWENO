project('PyWENO', 'c',
  version: '0.11.2',
  license: 'BSD-3-Clause',
  meson_version: '>=1.1.0',
  default_options : ['warning_level=2', 'c_std=c99'],
)

# get dependencies
py_mod = import('python')
py = py_mod.find_installation(pure: false)
py_dep = py.dependency()

# NOTE: meson does not like absolute paths, so we dance around it
incdir_numpy = run_command(py,
  [
    '-c',
    '''import os
import numpy as np
try:
  incdir = os.path.relpath(np.get_include())
except Exception:
  incdir = np.get_include()
print(incdir)
  '''], check: true).stdout().strip()
inc_numpy = include_directories(incdir_numpy)

# create extension modules
py.extension_module(
  'ccoeffs', [
  'src/ccoeffs.c',
  'src/coeffs003.c',
  'src/coeffs004.c',
  'src/coeffs005.c',
  'src/coeffs006.c',
  'src/coeffs007.c',
  'src/coeffs008.c',
  'src/coeffs009.c',
  ],
  include_directories: [inc_numpy],
  install: true,
  subdir: 'pyweno')

py.extension_module(
  'cweno', [
  'src/cweno.c',
  'src/weno_gauss_legendre003002.c',
  'src/weno_gauss_legendre003003.c',
  'src/weno_gauss_legendre004002.c',
  'src/weno_gauss_legendre004004.c',
  'src/weno_gauss_legendre005002.c',
  'src/weno_gauss_legendre005003.c',
  'src/weno_gauss_legendre005004.c',
  'src/weno_gauss_legendre005005.c',
  'src/weno_gauss_legendre006002.c',
  'src/weno_gauss_legendre006004.c',
  'src/weno_gauss_legendre006006.c',
  'src/weno_gauss_legendre007002.c',
  'src/weno_gauss_legendre007003.c',
  'src/weno_gauss_legendre007004.c',
  'src/weno_gauss_legendre007005.c',
  'src/weno_gauss_legendre007006.c',
  'src/weno_gauss_legendre007007.c',
  'src/weno_gauss_legendre008002.c',
  'src/weno_gauss_legendre008004.c',
  'src/weno_gauss_legendre008006.c',
  'src/weno_gauss_legendre008008.c',
  'src/weno_gauss_lobatto003002.c',
  'src/weno_gauss_lobatto003003.c',
  'src/weno_gauss_lobatto004002.c',
  'src/weno_gauss_lobatto004004.c',
  'src/weno_gauss_lobatto005002.c',
  'src/weno_gauss_lobatto005003.c',
  'src/weno_gauss_lobatto005004.c',
  'src/weno_gauss_lobatto005005.c',
  'src/weno_gauss_lobatto006002.c',
  'src/weno_gauss_lobatto006004.c',
  'src/weno_gauss_lobatto006006.c',
  'src/weno_gauss_lobatto007002.c',
  'src/weno_gauss_lobatto007003.c',
  'src/weno_gauss_lobatto007004.c',
  'src/weno_gauss_lobatto007005.c',
  'src/weno_gauss_lobatto007006.c',
  'src/weno_gauss_lobatto007007.c',
  'src/weno_gauss_lobatto008002.c',
  'src/weno_gauss_lobatto008004.c',
  'src/weno_gauss_lobatto008006.c',
  'src/weno_gauss_lobatto008008.c',
  'src/weno_gauss_radau003002.c',
  'src/weno_gauss_radau003003.c',
  'src/weno_gauss_radau004002.c',
  'src/weno_gauss_radau004003.c',
  'src/weno_gauss_radau004004.c',
  'src/weno_gauss_radau005002.c',
  'src/weno_gauss_radau005003.c',
  'src/weno_gauss_radau005004.c',
  'src/weno_gauss_radau005005.c',
  'src/weno_gauss_radau006002.c',
  'src/weno_gauss_radau006003.c',
  'src/weno_gauss_radau006004.c',
  'src/weno_gauss_radau006005.c',
  'src/weno_gauss_radau006006.c',
  'src/weno_gauss_radau007002.c',
  'src/weno_gauss_radau007003.c',
  'src/weno_gauss_radau007004.c',
  'src/weno_gauss_radau007005.c',
  'src/weno_gauss_radau007006.c',
  'src/weno_gauss_radau007007.c',
  'src/weno_gauss_radau008002.c',
  'src/weno_gauss_radau008003.c',
  'src/weno_gauss_radau008004.c',
  'src/weno_gauss_radau008005.c',
  'src/weno_gauss_radau008006.c',
  'src/weno_gauss_radau008007.c',
  'src/weno_gauss_radau008008.c',
  'src/weno_left003001.c',
  'src/weno_left004001.c',
  'src/weno_left005001.c',
  'src/weno_left006001.c',
  'src/weno_left007001.c',
  'src/weno_left008001.c',
  'src/weno_middle003001.c',
  'src/weno_middle005001.c',
  'src/weno_middle007001.c',
  'src/weno_right003001.c',
  'src/weno_right004001.c',
  'src/weno_right005001.c',
  'src/weno_right006001.c',
  'src/weno_right007001.c',
  'src/weno_right008001.c',
  'src/weno_smoothness003.c',
  'src/weno_smoothness004.c',
  'src/weno_smoothness005.c',
  'src/weno_smoothness006.c',
  'src/weno_smoothness007.c',
  'src/weno_smoothness008.c',
  'src/weno_smoothness009.c',
  ],
  include_directories: [inc_numpy],
  install: true,
  subdir: 'pyweno')

py.extension_module(
  'cnonuniform', [
    'src/nfweno.c',
    'src/poly.c',
  ],
  include_directories: [inc_numpy],
  install: true,
  subdir: 'pyweno')

# add sources
py.install_sources([
  'pyweno/__init__.py',
  'pyweno/codeprinters.py',
  'pyweno/kernels.py',
  'pyweno/nonuniform.py',
  'pyweno/points.py',
  'pyweno/reconstruction_coeffs.py',
  'pyweno/symbolic.py',
  'pyweno/symbols.py',
  'pyweno/version.py',
  'pyweno/weno.py',
  ],
  subdir: 'pyweno')
