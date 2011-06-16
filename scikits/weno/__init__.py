
from weno import reconstruct
from reconstruction_coeffs import reconstruction_coeffs as coeffs

# try:
#   from clweno import reconstruct as clreconstruct
# except:
#   clreconstruct = None
  

# def reconstruct(*args, use_opencl=False, **kwargs):
#   if use_opencl:
#     if clreconstruct:
#       clreconstruct(*args, **kwargs)
#     else:
#       raise ValueError, 'use_opencl is True, but pyopencl was not imported successfully'
#   else:
#     creconstruct(*args, **kwargs)
