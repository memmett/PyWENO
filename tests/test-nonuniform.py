
import numpy as np
import pyweno

def test_coeffs():
    correct = np.array([[[ 1.83333333, -1.16666667,  0.33333333],
                         [ 0.33333333,  0.83333333, -0.16666667],
                         [-0.16666667,  0.83333333,  0.33333333]],
                        [[ 0.33333333,  0.83333333, -0.16666667],
                         [-0.16666667,  0.83333333,  0.33333333],
                         [ 0.33333333, -1.16666667,  1.83333333]]])

    result, _, _ = pyweno.nonuniform.coefficients(3, [-1.0, 1.0],
                                         [1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0])
    np.testing.assert_almost_equal(correct, result[2])


def test_coeffs_stress():
    x = np.linspace(0, 100000, 100000)
    result, _, _ = pyweno.nonuniform.coefficients(3, [1.0], x)
    np.testing.assert_almost_equal(result[5][0], result[-5][0])


def test_weights():
    weights = np.array([0.3, 0.6, 0.1])
    _, _, result = pyweno.nonuniform.coefficients(
        3, [-1.0, 1.0], [1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0])
    np.testing.assert_almost_equal(result[2][1], weights)


def test_jiang_shu_smoothness_coefficients():
    correct = np.array(
        [[[3.33333333, -10.33333333,   3.66666667],
         [0.,            8.33333333,  -6.33333333],
         [0.,            0.,           1.33333333]],
         [[1.33333333,  -4.33333333,   1.66666667],
          [0.,           4.33333333,  -4.33333333],
          [0.,           0.,           1.33333333]],
         [[1.33333333,  -6.33333333,   3.66666667],
          [0.,           8.33333333, -10.33333333],
          [0.,           0.,           3.33333333]]])

    _, beta, _ = pyweno.nonuniform.coefficients(3, [], np.linspace(0, 10000, 10000))
    np.testing.assert_almost_equal(beta[9500], correct)

    # Make sure it doesn't fail in the case of a non-uniform grid.
    # How to check correctness?
    # beta2 = jiang_shu_smoothness_coefficients(3, [1, 2, 3, 3.5, 5, 6, 7])
    # assert(beta2 is not None)

if __name__ == '__main__':
    test_coeffs()
    test_jiang_shu_smoothness_coefficients()
