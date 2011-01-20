PyWENO OpenCL toolkit
=====================

PyWENO contains an OpenCL module to help authors develop their own
specialized WENO methods on GPUs by generating WENO code.  Below are a
few quick examples demonstrating how the OpenCL routines of PyWENO are
used.


Half of a FVWENO5 kernel
------------------------

In this example we'll build an OpenCL kernel to reconstruct a function
based on its cell averages in a global OpenCL array ``f``.  We will
build approximations at the left (plus) side of each cell boundary.

The steps to generate a full FV OpenCL WENO kernel are contained in
:mod:`pyweno.opencl`.

First, we'll define the OpenCL function and the local variables that
will be used::

   src = [r"""
     __kernel void weno5_plus(__global const float *f,
                              __global float *f_plus) {
       int i;
       float sigma0, sigma1, sigma2;
       float omega0, omega1, omega2, alpha;
       float f0, f1, f2;
       float accumulator;

       i = get_global_id(0);
       """]

Subsequently, we'll append kernel snippets returned by the PyWENO
OpenCL routines onto the ``src`` array.  Note that ``sigma0`` denotes
the smoothness indicator with a left-shift of zero.

Next, we'll use Jiang-Shu smoothness coefficients to compute the
smoothness indicators ``sigma0``, ``sigma1``, and ``sigma2``::

  >>> beta       = pyweno.symbolic.jiang_shu_smoothness_coefficients(3)
  >>> smoothness = pyweno.opencl.uniform_smoothness_kernel(3, beta, function=False)
  >>> src.append(smoothness)
  >>> print smoothness
  sigma0 = 0.0;
  sigma0 += 3.33333333333333 * f[i+0] * f[i+0];
  sigma0 += -10.3333333333333 * f[i+0] * f[i+1];
  sigma0 += 3.66666666666667 * f[i+0] * f[i+2];
  sigma0 += 8.33333333333333 * f[i+1] * f[i+1];
  sigma0 += -6.33333333333333 * f[i+1] * f[i+2];
  sigma0 += 1.33333333333333 * f[i+2] * f[i+2];
  sigma1 = 0.0;
  sigma1 += 1.33333333333333 * f[i-1] * f[i-1];
  sigma1 += -4.33333333333333 * f[i-1] * f[i+0];
  sigma1 += 1.66666666666667 * f[i-1] * f[i+1];
  sigma1 += 4.33333333333333 * f[i+0] * f[i+0];
  sigma1 += -4.33333333333333 * f[i+0] * f[i+1];
  sigma1 += 1.33333333333333 * f[i+1] * f[i+1];
  sigma2 = 0.0;
  sigma2 += 1.33333333333333 * f[i-2] * f[i-2];
  sigma2 += -6.33333333333333 * f[i-2] * f[i-1];
  sigma2 += 3.66666666666667 * f[i-2] * f[i+0];
  sigma2 += 8.33333333333333 * f[i-1] * f[i-1];
  sigma2 += -10.3333333333333 * f[i-1] * f[i+0];
  sigma2 += 3.33333333333333 * f[i+0] * f[i+0];

Next, we'll compute the weights for reconstructing at the side of each
cell::

  >>> varpi    = pyweno.symbolic.optimal_weights(3, 'left')
  >>> weights  = pyweno.opencl.uniform_weights_kernel(3, varpi, function=False)
  >>> src.append(weights)
  >>> print weights
  accumulator = 0.0;
  alpha = 0.1 / (10e-6 + sigma0) / (10e-6 + sigma0);
  omega0 = alpha;
  accumulator += alpha;
  alpha = 0.6 / (10e-6 + sigma1) / (10e-6 + sigma1);
  omega1 = alpha;
  accumulator += alpha;
  alpha = 0.3 / (10e-6 + sigma2) / (10e-6 + sigma2);
  omega2 = alpha;
  accumulator += alpha;
  omega0 /= accumulator;
  omega1 /= accumulator;
  omega2 /= accumulator;

Next, we reconstruct the function on the left side of each cell, and
store the result in the ``f_plus`` array::

  >>> coeffs = pyweno.symbolic.reconstruction_coefficients(3, 'left')
  >>> reconstruct = pyweno.opencl.uniform_reconstruction_kernel(3, coeffs, rf='f_plus[i]', function=False)
  >>> src.append(reconstruct)
  >>> print reconstruct
  f0 = 1.83333333333333 * f[i+0] + -1.16666666666667 * f[i+1] + 0.333333333333333 * f[i+2];
  f1 = 0.333333333333333 * f[i-1] + 0.833333333333333 * f[i+0] + -0.166666666666667 * f[i+1];
  f2 = -0.166666666666667 * f[i-2] + 0.833333333333333 * f[i-1] + 0.333333333333333 * f[i+0];
  f_plus[i] = f0 * omega0 + f1 * omega1 + f2 * omega2;

Finally, the source code for OpenCL kernel would be::

  >>> src.append('}')
  >>> kernel_source = '\n'.join(src)

One could add the right (minus) reconstruction to the above as well.

Furthermore, when solving hyperbolic PDEs, one could add the code
necessary to compute the flux at each cell boundary by appending onto
the ``src`` array above (before appending the last ``}``).  In this
way, one can put as much code as possible into a single OpenCL kernel
that only references one global array.
