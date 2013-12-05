
import cProfile as profile

import numpy as np
import pyweno

def test_cnonuniform():

    k  = 3
    x  = np.linspace(0.0, 10000.0, 10000+1)
    xi = np.array([-1.0, 1.0])

    # running these profiling, the symbolic c routines are much
    # faster than the python+fortran routines.

    # profile.runctx('c, beta = pyweno.nonuniform.ccoeffs(3, xi, x)',
    #                globals(), locals())
    # profile.runctx('beta, c = pyweno.nonuniform.jiang_shu_smoothness_coefficients(k, x), pyweno.nonuniform.reconstruction_coefficients(k, xi, x)',
    #                globals(), locals())

    c0 = np.array([[[1.83333333, -1.16666667,  0.33333333],
                    [0.33333333,  0.83333333, -0.16666667],
                    [-0.16666667,  0.83333333,  0.33333333]],
                   [[0.33333333,  0.83333333, -0.16666667],
                    [-0.16666667,  0.83333333,  0.33333333],
                    [0.33333333, -1.16666667,  1.83333333]]])

    beta0 = np.array(
        [[[3.33333333, -10.33333333,   3.66666667],
          [0.,   8.33333333,  -6.33333333],
          [0.,   0.,   1.33333333]],
         [[1.33333333,  -4.33333333,   1.66666667],
          [0.,   4.33333333,  -4.33333333],
          [0.,   0.,   1.33333333]],
         [[1.33333333,  -6.33333333,   3.66666667],
          [0.,   8.33333333, -10.33333333],
          [0.,   0.,   3.33333333]]])

    varpi0 = np.array([[0.1, 0.6, 0.3], [0.3, 0.6, 0.1]])

    c, beta, varpi = pyweno.nonuniform.coefficients(3, xi, x)

    np.testing.assert_almost_equal(c0, c[2])
    np.testing.assert_almost_equal(beta0, beta[9500])
    np.testing.assert_almost_equal(varpi0, varpi[100])


if __name__ == '__main__':
    test_cnonuniform()

