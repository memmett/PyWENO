"""PyWENO CLWENO class (OpenCL based WENO class)."""


import numpy as np
import pyopencl as cl

import pyweno.symbolic
import pyweno.opencl


######################################################################
# WENO
#

class CLWENO5PM(object):
    """OpenCL WENO5 class.

    This class is a highly optimised OpenCL WENO class for 5th order
    reconstructions at the left boundary of each cell on uniform
    grids.

    Two reconstructions are computed for each cell boundary.  These
    reconstructions are called the *plus* and *minus* reconstructions,
    and can be thought of as right and left limits as in calculus.

    **Basic usage**

    To reconstruct *f* from ``f_avg``::

    >>> f_plus  = np.zeros(grid.size)
    >>> f_minus = np.zeros(grid.size)
    >>> weno = pyweno.clweno5.CLWENO5PM()
    >>> weno.reconstruct(f_avg, f_plus, f_minus)

    **Keyword arguments**

    * *ctx* - PyOpenCL context (if ``None``, a context is created)
    * *queue* - PyOpenCL queue (if ``None``, a queue is created)

    **Methods**

    """

    ##################################################################
    # init
    #

    def __init__(self, ctx=None, queue=None, **kwargs):

        if ctx is None:
            ctx = cl.create_some_context()

        if queue is None:
            queue = cl.CommandQueue(ctx)

        src = _kernel_weno5()
        self.weno5 = cl.Program(ctx, src).build()

        self.ctx = ctx
        self.queue = queue


    ##################################################################
    # reconstruct
    #

    def reconstruct(self, q, q_plus, q_minus):
        """Reconstruct *q* at the left edge of each cell and store the
           results in *q_plus* (right/+ limit) and *q_minus* (left/-
           limit).

           **Arguments:**

           * *q* - cell averages of function to reconstruct
           * *q_plus* - store + reconstruction here
           * *q_minus* - store - reconstruction here

           NOTE: the domain boundaries are avoided (zeroed out in
           *q_plus* and *q_minus*).
        """

        k = 3

        q32 = q.astype(np.float32)
        p32 = q_plus.astype(np.float32)
        m32 = q_minus.astype(np.float32)

        mf = cl.mem_flags
        q_buf = cl.Buffer(self.ctx, mf.READ_ONLY | mf.COPY_HOST_PTR, hostbuf=q32)
        p_buf = cl.Buffer(self.ctx, mf.WRITE_ONLY, p32.nbytes)
        m_buf = cl.Buffer(self.ctx, mf.WRITE_ONLY, m32.nbytes)

        length = (q32.shape[0] - (2*k-1),)
        #length = (q32.shape[0],)

        self.weno5.weno5(self.queue, length, None, q_buf, p_buf, m_buf)
        cl.enqueue_read_buffer(self.queue, p_buf, p32).wait()
        cl.enqueue_read_buffer(self.queue, m_buf, m32).wait()

        q_plus[:]  = p32.astype(q_plus.dtype)
        q_minus[:] = m32.astype(q_minus.dtype)

        # zero out boundaries
        q_plus[:k] = np.zeros(k, dtype=q_plus.dtype)
        q_minus[:k] = np.zeros(k, dtype=q_plus.dtype)
        q_plus[-k+1:] = np.zeros(k-1, dtype=q_plus.dtype)
        q_minus[-k+1:] = np.zeros(k-1, dtype=q_plus.dtype)


######################################################################
# kernel
#

def _kernel_weno5():
    """Fully un-rolled WENO5 kernel."""

    src = [r"""
__kernel void weno5(__global const float *f,
                    __global float *f_plus,
                    __global float *f_minus) {

int i;
float sigma0, sigma1, sigma2;
float omega0, omega1, omega2, alpha;
float f0, f1, f2;
float accumulator;
"""]

    k = 3

    # avoid boundaries...
    src.append('i = get_global_id(0) + %d;' % (k))
    #src.append('i = get_global_id(0);')

    # smoothness indicators
    beta       = pyweno.symbolic.jiang_shu_smoothness_coefficients(k)
    smoothness = pyweno.opencl.uniform_smoothness_kernel(
        k, beta, function=False)

    src.append('')
    src.append('/* smoothness indicators */')
    src.append(smoothness)

    # left reconstruction
    coeffs   = pyweno.symbolic.reconstruction_coefficients(
        k, 'left')
    varpi    = pyweno.symbolic.optimal_weights(k, 'left')
    weights  = pyweno.opencl.uniform_weights_kernel(
        k, varpi, function=False)
    reconstruct = pyweno.opencl.uniform_reconstruction_kernel(
        k, coeffs, rf='f_plus[i]', function=False)

    src.append('')
    src.append('/* left weights */')
    src.append(weights)

    src.append('')
    src.append('/* left (+) reconstruction */')
    src.append(reconstruct)

    # right reconstruction
    coeffs   = pyweno.symbolic.reconstruction_coefficients(
        k, 'right')
    varpi    = pyweno.symbolic.optimal_weights(k, 'right')
    weights  = pyweno.opencl.uniform_weights_kernel(
        k, varpi, function=False)
    reconstruct = pyweno.opencl.uniform_reconstruction_kernel(
        k, coeffs, rf='f_minus[i+1]', function=False)

    src.append('')
    src.append('/* right weights */')
    src.append(weights)

    src.append('')
    src.append('/* right (-) reconstruction */')
    src.append(reconstruct)

    # done
    src.append('')
    src.append('}')

    return "\n".join(src)
