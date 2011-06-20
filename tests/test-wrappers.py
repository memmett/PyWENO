
import pyweno.symbolic
import pyweno.wrappers

def test_wrappers():

  k = 3

  for lang in ('c', 'opencl', 'fortran'):

    wrapper = pyweno.wrappers.WrapperGenerator(lang)
    beta = pyweno.symbolic.jiang_shu_smoothness_coefficients(k)
    wrapper.set_smoothness(beta)

    wrapper.smoothness()

    (varpi, split) = pyweno.symbolic.optimal_weights(k, [ -1 ])
    coeffs = pyweno.symbolic.reconstruction_coefficients(k, [ -1 ])

    wrapper.set_optimal_weights(varpi, split)
    wrapper.set_reconstruction_coefficients(coeffs)

    wrapper.weights()
    wrapper.reconstruction()
    wrapper.reconstruction(compute_weights=True)
    wrapper.reconstruction(compute_smoothness=True)


if __name__ == '__main__':
  test_wrappers()

  
