"""PyWENO CLWENO class (OpenCL based WENO class)."""


import numpy as np
import pyopencl as cl


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
# coefficient tables
#

beta_jiang_shu = [
    [ [          '',            '',            '',            '',            '' ],
      [          '',            '',            '',            '',            '' ],
      [          '',            '',  '(10.0/3.0)', '(-31.0/3.0)',  '(11.0/3.0)' ],
      [          '',            '',            '',  '(25.0/3.0)', '(-19.0/3.0)' ],
      [          '',            '',            '',            '',   '(4.0/3.0)' ] ],
    [ [          '',            '',            '',            '',            '' ],
      [          '',   '(4.0/3.0)', '(-13.0/3.0)',   '(5.0/3.0)',            '' ],
      [          '',            '',  '(13.0/3.0)', '(-13.0/3.0)',            '' ],
      [          '',            '',            '',   '(4.0/3.0)',            '' ],
      [          '',            '',            '',            '',            '' ] ],
    [ [ '(4.0/3.0)', '(-19.0/3.0)',  '(11.0/3.0)',            '',            '' ],
      [          '',  '(25.0/3.0)', '(-31.0/3.0)',            '',            '' ],
      [          '',            '',  '(10.0/3.0)',            '',            '' ],
      [          '',            '',            '',            '',            '' ],
      [          '',            '',            '',            '',            '' ] ] ]

beta = beta_jiang_shu

left_optimal_weights  = [ '(0.1)', '(0.6)', '(0.3)' ]
right_optimal_weights = [ '(0.3)', '(0.6)', '(0.1)' ]

left_reconstruction_coeffs  = [ ['(11.0/6.0)', '(-7.0/6.0)',  '(2.0/6.0)'],
                                [ '(2.0/6.0)',  '(5.0/6.0)', '(-1.0/6.0)'],
                                ['(-1.0/6.0)',  '(5.0/6.0)',  '(2.0/6.0)'] ]
right_reconstruction_coeffs = [ [ '(2.0/6.0)',  '(5.0/6.0)', '(-1.0/6.0)'],
                                ['(-1.0/6.0)',  '(5.0/6.0)',  '(2.0/6.0)'],
                                [ '(2.0/6.0)', '(-7.0/6.0)', '(11.0/6.0)'] ]


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
      """]

    k = 3

    # avoid boundaries...
    src.append('i = get_global_id(0) + %d;' % (k))
    #src.append('i = get_global_id(0);')

    # smoothness indicators
    src.append('/* smoothness indicators */')
    for r in range(k):
        sigma = 'sigma%d' % (r)
        src.append(sigma + ' = 0.0;')

        for m in range(k-r-1, 2*k-r-1):
            for n in range(m, 2*k-r-1):
                pm = -(k-1) + m
                pn = -(k-1) + n
                b  = beta[r][m][n]
                src.append(sigma + ' += %(b)s * f[i%(pm)+d] * f[i%(pn)+d];'
                           % { 'b': b, 'pm': pm, 'pn': pn })

        #src.append(('sigma[i*3+%d] = ' % (r)) + sigma + ';')

    # weights
    for (point, offset, optimal_weights, reconstruction_coeffs) in [
          ('plus',  0, left_optimal_weights,  left_reconstruction_coeffs),
          ('minus', 1, right_optimal_weights, right_reconstruction_coeffs) ]:

        src.append('/* %s weights */' % (point))
        for r in range(k):
            sigma = 'sigma%d' % (r)
            omega = 'omega%d' % (r)
            varpi = optimal_weights[r]

            src.append(omega + ' = %s / (10e-6 + %s) / (10e-6 + %s);' % (varpi, sigma, sigma))

        sum_omega = ' + '.join(['omega%d' % (r) for r in range(k)])
        src.append('alpha = ' + sum_omega + ';')

        for r in range(k):
            omega = 'omega%d' % (r)
            src.append(omega + ' /= alpha;')

        # reconstructions
        src.append('/* %s reconstructions */' % (point))
        for r in range(k):
            f = 'f%d' % (r)

            reconstruction = []
            for j in range(k):
                reconstruction.append('%s * f[i%+d]' % (reconstruction_coeffs[r][j], -r+j))

            src.append(f + ' = ' + ' + '.join(reconstruction) + ';')

        # weighted reconstruction
        reconstruction = []
        for r in range(k):
            reconstruction.append('f%d * omega%d' % (r, r))

        src.append(('f_%s[i+%d] = ' % (point, offset)) + ' + '.join(reconstruction) + ';')

    # done
    src.append('}')

    return "\n".join(src)
