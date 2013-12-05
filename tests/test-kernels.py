
import pyweno

def test_kernels():

  k = 3

  for lang in ('c', 'fortran'):
    kernel = pyweno.kernels.KernelGenerator(lang, order=2*k-1, xi=[-1, 0, 1])
    kernel.smoothness(reuse=False)
    kernel.smoothness(reuse=True)
    kernel.weights()
    kernel.reconstruction()


if __name__ == '__main__':
  test_kernels()


