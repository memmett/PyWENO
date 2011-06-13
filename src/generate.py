
import pyweno.points
import pyweno.symbolic
import pyweno.kernels
import pyweno.wrappers

kernel  = pyweno.kernels.KernelGenerator('c')
wrapper = pyweno.wrappers.WrapperGenerator(kernel)

for k in range(3, 4):

  beta = pyweno.symbolic.jiang_shu_smoothness_coefficients(k)
  kernel.set_smoothness(beta)

  print wrapper.smoothness()

  # test
  xi = pyweno.points.gauss_legendre(3)
  (varpi, split) = pyweno.symbolic.optimal_weights(k, xi)
  coeffs = pyweno.symbolic.reconstruction_coefficients(k, xi)

  kernel.set_optimal_weights(varpi, split)
  kernel.set_reconstruction_coefficients(coeffs)

  print wrapper.reconstruction(local_weights=False)

  
