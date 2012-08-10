
import pyweno.symbolic
import pyweno.functions

def test_functions():

  k = 3

  for lang in ('c', 'opencl', 'fortran'):

    function = pyweno.functions.FunctionGenerator(lang)
    beta = pyweno.symbolic.jiang_shu_smoothness_coefficients(k)
    function.set_smoothness(beta)

    function.smoothness()

    (varpi, split) = pyweno.symbolic.optimal_weights(k, [ -1 ])
    coeffs = pyweno.symbolic.reconstruction_coefficients(k, [ -1 ])

    function.set_optimal_weights(varpi, split)
    function.set_reconstruction_coefficients(coeffs)

    function.generate('testweno')


if __name__ == '__main__':
  test_functions()

  
