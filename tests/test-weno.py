"""Test WENO reconstruction on an unstructured grid."""

import math

import numpy as np

import pyweno.grid
import pyweno.weno


# test function and it's derivative

def f(x):
    return 1.0 - x + x*x
uf = np.frompyfunc(f, 1, 1)

def fp(x):
    return -1.0 + 2.0*x
ufp = np.frompyfunc(fp, 1, 1)


######################################################################

def test_weno():

    K = range(3, 5)
    x = np.array([-4.0, -3.5, -3.0, -2.5, -2.0, -1.5,
                  -1.0, -0.8, -0.6, -0.4,
                  -0.3, -0.2, -0.1, 0.0, 0.1, 0.2, 0.3,
                  0.4, 0.6, 0.8, 1.0,
                  1.5, 2.0, 2.5, 3.0, 3.5, 4.0])
    grid = pyweno.grid.Grid(boundaries=x)

    # f and f' evaluated at boundaries
    fbndry = uf(x)
    fpbndry = ufp(x)

    # average of f (we're testing striding too, hence the extra component)
    fbar = np.zeros((3,grid.N))
    fbar[0,:] = grid.average(f)

    for k in K:
        weno = pyweno.weno.WENO(grid=grid, order=k)
        weno.precompute_reconstruction('left')
        weno.precompute_reconstruction('d|left')

        # f reconstructed at boundaries
        frcnst = np.zeros((x.size,3))
        fprcnst = np.zeros((x.size,3))

        weno.smoothness(fbar[0,:])
        weno.reconstruct(fbar[0,:], 'left', frcnst[:,0])
        weno.reconstruct(fbar[0,:], 'd|left', fprcnst[:,0])

        # assert
        d  = fbndry[k+1:-k-1] - frcnst[k+1:-k-1,0]
        l2 = math.sqrt(np.dot(d, d))
        assert l2 < 1e-10, "WENO (k=%d, left) is broken" % (k)

        d  = fpbndry[k+1:-k-1] - fprcnst[k+1:-k-1,0]
        l2 = math.sqrt(np.dot(d, d))
        assert l2 < 1e-10, "WENO (k=%d, d|left) is broken" % (k)


######################################################################


if __name__ == '__main__':
    import cProfile as profile
    import pstats

    profile.run("test_weno()", 'weno.prof')
    p = pstats.Stats('weno.prof')
    p.strip_dirs().sort_stats('time', 'cum').print_stats(10)
