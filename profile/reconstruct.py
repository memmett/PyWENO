import pyweno.symbolic
import pyweno.kernels
import pyweno.wrappers

import numpy as np

wrapper = pyweno.wrappers.WrapperGenerator('c')
# print wrapper.header('test')

k = 3

# set smoothness
beta = pyweno.symbolic.jiang_shu_smoothness_coefficients(k)
wrapper.set_smoothness(beta)

# reconstructions: -1=left, 1=right
(varpi, split) = pyweno.symbolic.optimal_weights(k, [ -1, 1 ])
coeffs = pyweno.symbolic.reconstruction_coefficients(k, [ -1, 1 ])

wrapper.set_optimal_weights(varpi, split)
wrapper.set_reconstruction_coefficients(coeffs)

print wrapper.reconstruction(compute_weights=True, compute_smoothness=True)
print wrapper.footer()
