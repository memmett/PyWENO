PyWENO Examples
===============

Reconstruct a function given its cell averages
----------------------------------------------

Use a 5th order ENO reconstruction to approximate the values of a
function f(x) given its cell averages on an unstructured grid.

.. sourcecode:: python

  k = 5
  r = k/2 + k%2

  x = np.array([-4.0, -3.5, -3.0, -2.5, -2.0, -1.5,
              -1.0, -0.8, -0.6, -0.4,
              -0.3, -0.2, -0.1, 0.0, 0.1, 0.2, 0.3,
              0.4, 0.6, 0.8, 1.0,
              1.5, 2.0, 2.5, 3.0, 3.5, 4.0])

  grid    = pyweno.grid.Grid(boundaries=x)
  stencil = pyweno.stencil.Stencil(grid=grid, order=k, shift=r)

  fbar = grid.average(f)

  f_m = np.zeros(x.size)
  f_p = np.zeros(x.size)
  for i in range(k, x.size-k):
      f_m[i]   = np.dot(stencil.c_m[i,:], fbar[i-r:i-r+k])
      f_p[i+1] = np.dot(stencil.c_p[i,:], fbar[i-r:i-r+k])


Cache
-----

Generate reconstruction coefficients (for cell boundaries and 3-point
quadrature points) and cache them.

.. sourcecode:: python

  k = 8
  x = np.linspace(-800.0,800.0,3200+1)

  cache = 'gridk%d.hdf5' % (k)
  if not os.access(cache, os.F_OK):
      grid = pyweno.grid.Grid(x)
      grid.cache(cache)

      stencil = pyweno.stencil.Stencil(grid=grid, order=k, quad=3, shift=k/2+k%2)
      stencil.cache(cache)

  grid    = pyweno.grid.Grid(cache=cache)
  stencil = pyweno.stencil.Stencil(cache=cache, order=k, shift=k/2+k%2)


Matrix
------

Build a sparse matrix in order to reconstruct a function at all
boundary points.

.. sourcecode:: python

  k = 5
  r = k/2 + k%2

  stencil = pyweno.stencil.Stencil(cache=cache, order=k, shift=r)

  A = scipy.sparse.lil_matrix((N,N))

  for i in xrange(2*k):
      A[i,i] = 1.0

  for i in xrange(2*k, N-2*k):
      A[i,i-r:i-r+k] = stencil.c_m[i,:]

  for i in xrange(N-2*k, N):
      A[i,i] = 1.0

  A = A.tocsr()

  # then, to reconstruct given cell averages fbar
  f = A * fbar
