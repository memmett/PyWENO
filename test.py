import pyweno.symbolic
import pyweno.kernels


kernel = pyweno.kernels.KernelGenerator('fortran')

beta = pyweno.symbolic.jiang_shu_smoothness_coefficients(3)
kernel.set_smoothness(beta)

print kernel.smoothness()


