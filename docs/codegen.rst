Code generation
===============


PyWENO contains two modules to help authors generate WENO codes in
C-like languages (ie, C, C++, OpenCL, and CUDA), and Fortran.  The
code-generation process is done in two stages:

#. Use the :doc:`symbolic <symbolic>` package to compute
   reconstruction coefficients and optimal weights (or provide your
   own).

#. Generate either code snippets (kernels) to use as building blocks
   for your own code.


Kernels
-------

First, let's generate a Fortran kernel to reconstruct at the left and
right endpoints of a cell to fifth order::

  >>> import pyweno
  >>> k = pyweno.kernels.KernelGenerator('Fortran', order=5, xi=[-1,1])
  >>> print k.smoothness()
  sigma0 = 3.3333333333333333333333333333333333d0*f(i+0)*f(i+0) - &
        10.333333333333333333333333333333333d0*f(i+0)*f(i+1) + &
        3.6666666666666666666666666666666667d0*f(i+0)*f(i+2) + &
        8.3333333333333333333333333333333333d0*f(i+1)*f(i+1) - &
        6.3333333333333333333333333333333333d0*f(i+1)*f(i+2) + &
        1.3333333333333333333333333333333333d0*f(i+2)*f(i+2)
  sigma1 = 4.3333333333333333333333333333333333d0*f(i+0)*f(i+0) - &
        4.3333333333333333333333333333333333d0*f(i+0)*f(i+1) - &
        4.3333333333333333333333333333333333d0*f(i+0)*f(i-1) + &
        1.3333333333333333333333333333333333d0*f(i+1)*f(i+1) + &
        1.6666666666666666666666666666666667d0*f(i+1)*f(i-1) + &
        1.3333333333333333333333333333333333d0*f(i-1)*f(i-1)
  sigma2 = 3.3333333333333333333333333333333333d0*f(i+0)*f(i+0) - &
        10.333333333333333333333333333333333d0*f(i+0)*f(i-1) + &
        3.6666666666666666666666666666666667d0*f(i+0)*f(i-2) + &
        8.3333333333333333333333333333333333d0*f(i-1)*f(i-1) - &
        6.3333333333333333333333333333333333d0*f(i-1)*f(i-2) + &
        1.3333333333333333333333333333333333d0*f(i-2)*f(i-2)
  >>> print k.weights()
  omega0 = 0.1d0/(sigma0 + 0.00000099999999999999995474811182588625869d0)*(sigma0 + &
        0.00000099999999999999995474811182588625869d0)
  omega1 = 0.6d0/(sigma1 + 0.00000099999999999999995474811182588625869d0)*(sigma1 + &
        0.00000099999999999999995474811182588625869d0)
  omega2 = 0.3d0/(sigma2 + 0.00000099999999999999995474811182588625869d0)*(sigma2 + &
        0.00000099999999999999995474811182588625869d0)
  acc = omega0 + omega1 + omega2
  omega0 = omega0/acc
  omega1 = omega1/acc
  omega2 = omega2/acc
  omega3 = 0.3d0/(sigma0 + 0.00000099999999999999995474811182588625869d0)*(sigma0 + &
        0.00000099999999999999995474811182588625869d0)
  omega4 = 0.6d0/(sigma1 + 0.00000099999999999999995474811182588625869d0)*(sigma1 + &
        0.00000099999999999999995474811182588625869d0)
  omega5 = 0.1d0/(sigma2 + 0.00000099999999999999995474811182588625869d0)*(sigma2 + &
        0.00000099999999999999995474811182588625869d0)
  acc = omega3 + omega4 + omega5
  omega3 = omega3/acc
  omega4 = omega4/acc
  omega5 = omega5/acc
  >>> print k.reconstruction()
  fr0 = 1.8333333333333333333333333333333333d0*f(i+0) - &
        1.1666666666666666666666666666666667d0*f(i+1) + &
        0.33333333333333333333333333333333333d0*f(i+2)
  fr1 = 0.83333333333333333333333333333333333d0*f(i+0) - &
        0.16666666666666666666666666666666667d0*f(i+1) + &
        0.33333333333333333333333333333333333d0*f(i-1)
  fr2 = 0.33333333333333333333333333333333333d0*f(i+0) + &
        0.83333333333333333333333333333333333d0*f(i-1) - &
        0.16666666666666666666666666666666667d0*f(i-2)
  fr3 = 0.33333333333333333333333333333333333d0*f(i+0) + &
        0.83333333333333333333333333333333333d0*f(i+1) - &
        0.16666666666666666666666666666666667d0*f(i+2)
  fr4 = 0.83333333333333333333333333333333333d0*f(i+0) + &
        0.33333333333333333333333333333333333d0*f(i+1) - &
        0.16666666666666666666666666666666667d0*f(i-1)
  fr5 = 1.8333333333333333333333333333333333d0*f(i+0) - &
        1.1666666666666666666666666666666667d0*f(i-1) + &
        0.33333333333333333333333333333333333d0*f(i-2)
  fs0 = fr0*omega0 + fr1*omega1 + fr2*omega2
  fs1 = fr3*omega3 + fr4*omega4 + fr5*omega5


As you can see, the code snippets above assume that you have defined
several variables, and that the cell-averaged unknown is stored in the
``f`` vector (indexed by ``i``).  Finally, the last snippet stores the
reconstructed values in ``fs0`` and ``fs1``.

You can optionally change the names of the variables used above, and
you can also supply your own reconstruction coeffs, optimal weights,
and smoothness coefficients instead of having them automactially
computed.

Please see the reference documentation for more information.
