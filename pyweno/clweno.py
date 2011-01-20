"""PyWENO CLWENO class (OpenCL based WENO class)."""


import numpy as np
import pyopencl as cl

import pyweno.weno
import pyweno.symbolic
import pyweno.opencl

######################################################################
# CLPMWENO
#

class CLPMWENO(object):
    """OpenCL plus/minus WENO class.

    This class is a highly optimised OpenCL WENO class for 2k-1 order
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

    **Arguments**

    * *k* - 2k-1 reconstruction order

    **Keyword arguments**

    * *ctx* - PyOpenCL context (if ``None``, a context is created)
    * *queue* - PyOpenCL queue (if ``None``, a queue is created)

    **Methods**

    """

    ##################################################################
    # init
    #

    def __init__(self, k, ctx=None, queue=None, **kwargs):

        if ctx is None:
            ctx = cl.create_some_context()

        if queue is None:
            queue = cl.CommandQueue(ctx)

        src = _kernel_pmweno(k)
        self.weno5 = cl.Program(ctx, src).build()

        self.ctx = ctx
        self.queue = queue

        self.k = k


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

        k = self.k

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
# CLWENO
#

class CLWENO(pyweno.weno.WENO):
    """OpenCL WENO class (see pyweno.weno.WENO).

    This class extends the PyWENO WENO class to add support for OpenCL
    through PyOpenCL.  It acts as a drop in replacement for the WENO
    class.

    Please see pyweno.weno.WENO for more information.

    Please note: all arrays are cast to numpy.float32 when using this
    class.

    **Keyword arguments**

    * *ctx*   - PyOpenCL context (if ``None``, a context is created)
    * *queue* - PyOpenCL queue (if ``None``, a queue is created)

    """

    ##################################################################
    # init
    #

    def __init__(self, ctx=None, queue=None, **kwargs):

        pyweno.weno.WENO.__init__(self, **kwargs)

        if not self.grid.uniform:
            raise NotImplementedError, 'Non-uniform grid not currently supported for OpenCL WENO.'

        if ctx is None:
            ctx = cl.create_some_context()

        if queue is None:
            queue = cl.CommandQueue(ctx)

        src = _smoothness_kernel_uniform(self.beta, self.grid.N, self.k)
        self.smoothness_prg = cl.Program(ctx, src).build()

        src = _weights_kernel_uniform(self.k, 1)
        self.weights_prg = cl.Program(ctx, src).build()

        self.ctx = ctx
        self.queue = queue


    ##################################################################
    # reconstruction
    #

    def precompute_reconstruction(self, *args, **kwargs):

        pyweno.weno.WENO.precompute_reconstruction(self, *args, **kwargs)


    ##################################################################
    # smoothness and reconstruction wrappers
    #

    def smoothness(self, q, imin=0, imax=-1):

        q32 = q.astype(np.float32)
        s32 = self.sigma.astype(np.float32)

        mf = cl.mem_flags
        q_buf = cl.Buffer(self.ctx, mf.READ_ONLY | mf.COPY_HOST_PTR, hostbuf=q32)
        s_buf = cl.Buffer(self.ctx, mf.WRITE_ONLY, s32.nbytes)

        self.smoothness_prg.smoothness(self.queue, q32.shape, None, q_buf, s_buf)
        cl.enqueue_read_buffer(self.queue, s_buf, s32).wait()

        self.sigma = s32.astype(self.sigma.dtype)


    def weights(self, key, imin=0, imax=-1, s=0):

        s32 = self.sigma.astype(np.float32)
        w32 = self.w[key].astype(np.float32)
        wr32 = self.wr[key].astype(np.float32)

        mf = cl.mem_flags
        s_buf = cl.Buffer(self.ctx, mf.READ_ONLY | mf.COPY_HOST_PTR, hostbuf=s32)
        w_buf = cl.Buffer(self.ctx, mf.READ_ONLY | mf.COPY_HOST_PTR, hostbuf=w32)
        wr_buf = cl.Buffer(self.ctx, mf.WRITE_ONLY, wr32.nbytes)

        self.weights_prg.weights(self.queue, wr32.shape, None, s_buf, w_buf, wr_buf)
        cl.enqueue_read_buffer(self.queue, wr_buf, wr32).wait()

        self.wr[key] = wr32.astype(self.wr[key].dtype).reshape(self.wr[key].shape)


    def reconstruct(self, q, key, qs, imin=0, imax=-1, s=0, compute_weights=True):

        pyweno.weno.WENO.reconstruct(self, q, key, qs, imin, imax, s, compute_weights)

        # XXX: write kernel for this


######################################################################
# kernels
#

def _smoothness_kernel_uniform(beta, N, k):
    """Fully un-rolled smoothness kernel for uniform grids.

       See src/csmoothness.c as a reference.
    """

    src = [r"""
      __kernel void smoothness(__global const float *f,
                               __global float *sigma) {
      int i = get_global_id(0);
      float sum;"""]


    for r in range(0, k):
        src.append('sum = 0.0;')

        for m in range(k-r-1, 2*k-r-1):
            for n in range(m, 2*k-r-1):
                pm = -(k-1) + m
                pn = -(k-1) + n
                b  = beta[r,m,n]
                src.append('sum += %(b).15g * f[i%(pm)+d] * f[i%(pn)+d];'
                           % { 'b': b, 'pm': pm, 'pn': pn })

        src.append('sigma[i*%(ss)d + %(r)d] = sum;'
                   % {'r': r, 'ss': k })

    src.append('}')

    return "\n".join(src)


######################################################################

def _weights_kernel_uniform(k, n):
    """Fully un-rolled weights kernel for uniform grids.

       See src/cweno.c as a reference.

       NOTE: If n>1 (the number of reconstruction points within each
       cell), the caller should flatten the appropriate arrays.
    """


    src = [r"""
      __kernel void weights(__global const float *sigma,
                            __global const float *varpi,
                            __global float *wr
                            ) {
      int i = get_global_id(0);
      float alpha, sum_alpha;"""]

    # rmin = max(0, i-(N-k));
    # rmax = min(k-1, i);
    rmin = 0
    rmax = k

    for l in range(n):
        src.append('sum_alpha = 0.0;')
        for r in range(rmin, rmax):
            sigma = 'sigma[i*%(k)d + %(r)d]' % { 'k': k, 'r': r };
            varpi = 'varpi[%d]' % (l*k + r)
            src.append('alpha = %s / (10e-6 + %s) / (10e-6 + %s);' % (varpi, sigma, sigma))
            src.append('wr[i*%(is)d + %(r)d] = alpha;' % { 'is': n*k, 'r': l*k + r })
            src.append('sum_alpha += alpha;')

        for r in range(rmin, rmax):
            src.append('wr[i*%(is)d + %(r)d] /= sum_alpha;' % { 'is': n*k, 'r': l*k + r })

    src.append('}')
    return "\n".join(src)


######################################################################

def _smoothness_kernel_nonuniform(N, k):
    """Fully un-rolled smoothness kernel for non-uniform grids.

       See src/csmoothness.c as a reference.
    """
    src = [r"""
      __kernel void smoothness(__global const float *f,
                               __global const float *beta,
                               __global float *sigma) {
      int i = get_global_id(0);
      float sum;"""]

    # strides
    sr = (2*k-1) * (2*k-1)      # beta: r stride
    sm = (2*k-1)                # beta: m stride
    ss = k                      # sigma: i stride

    for r in range(0, k):
        src.append('sum = 0.0;')

        for m in range(k-r-1, 2*k-r-1):
            for n in range(m, 2*k-r-1):
                pm = -(k-1) + m
                pn = -(k-1) + n
                src.append('''sum += beta[%(r)d*%(sr)d + %(m)d*%(sm)d + %(n)d]
                                       * f[i%(pm)+d] * f[i%(pn)+d];'''
                           % { 'r': r, 'k': k, 'm': m, 'n': n,
                               'pm': pm, 'pn': pn, 'sr': sr, 'sm': sm })

        src.append('sigma[i*%(ss)d + %(r)d] = sum;' % {'r': r, 'ss': ss })

    src.append('}')
    return "\n".join(src)


######################################################################
# PM kernel
#

def _kernel_pmweno(k):
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
