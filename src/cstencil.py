"""Construct C file to compute reconstruction coefficients as a python
   extension module."""

######################################################################

def coeff_loops_boundary(k, b='left'):
    """Print the C loops used to compute the reconstruction
    coefficients :math:`c^r_{ij}`."""

    print "  /*"
    print "   * compute reconstruction (%s) coeffs of order %d" % (b, k)
    print "   */"
    print ""

    if b == 'left':
        print "  i--;"
        print "  r--;"

    for j in xrange(k):

        print ""
        print "  /* j = %d */" % (j)
        print "  sum_l = 0.0;"

        for l in xrange(j+1, k+1):

            print ""
            print "  /* l = %d */" % (l)
            print "  sum_m = 0.0;"

            ms = range(0,k+1)
            ms.remove(l)

            for m in ms:

                print ""
                print "  /* m = %d */" % (m)

                ns = range(0,k+1)
                ns.remove(l)
                ns.remove(m)

                print "  prod_n = 1.0;"

                for n in ns:
                    print "  prod_n *= x[i+1] - x[i-r+%d];  /* n = %d */" % (n,n)

                print "  sum_m += prod_n;"


            print ""
            print "  prod_m = 1.0;"
            for m in ms:
                print "  prod_m *= x[i-r+%d] - x[i-r+%d];" % (l,m)


            print ""
            print "  sum_l += sum_m / prod_m * (x[i-r+%d+1] - x[i-r+%d]);" % (j, j)

        print ""
        print "  c[%d] = sum_l;" % (j)

######################################################################

def coeff_loops_xi(k):
    """Print the C loops used to compute the reconstruction
    coefficients :math:`c^r_{ij}` to reconstruct at the point
    *xi*."""

    print "  /*"
    print "   * compute reconstruction (xi) coeffs of order %d" % (k)
    print "   */"
    print ""

    for j in xrange(k):

        print ""
        print "  /* j = %d */" % (j)
        print "  sum_l = 0.0;"

        for l in xrange(j+1, k+1):

            print ""
            print "  /* l = %d */" % (l)
            print "  sum_m = 0.0;"

            ms = range(0,k+1)
            ms.remove(l)

            for m in ms:

                print ""
                print "  /* m = %d */" % (m)

                ns = range(0,k+1)
                ns.remove(l)
                ns.remove(m)

                print "  prod_n = 1.0;"

                for n in ns:
                    print "  prod_n *= xi - x[i-r+%d];  /* n = %d */" % (n,n)

                print "  sum_m += prod_n;"


            print ""
            print "  prod_m = 1.0;"
            for m in ms:
                print "  prod_m *= x[i-r+%d] - x[i-r+%d];" % (l,m)


            print ""
            print "  sum_l += sum_m / prod_m * (x[i-r+%d+1] - x[i-r+%d]);" % (j, j)

        print ""
        print "  c[%d] = sum_l;" % (j)

######################################################################
## boundary

coeff_fcn_bndry_c_head = """
void
coeffs_%(k)d_%(bndry)s(long int i, int r, double *x, double *c)
{
  double sum_l, sum_m, prod_n, prod_m;
"""

coeff_fcn_bndry_c_foot = """
}
"""

coeff_fcn_bndry_py = """
PyObject *
coeffs_%(k)d_%(bndry)s_py(PyObject *self, PyObject *args)
{
  double *x, *c;
  long int i;
  int r;

  PyObject *bndry, *coeffs;

  /*
   * parse options
   */

  if (! PyArg_ParseTuple(args, "liOO", &i, &r, &bndry, &coeffs))
    return NULL;

  if ((PyArray_FLAGS(bndry) & NPY_IN_ARRAY) != NPY_IN_ARRAY) {
    PyErr_SetString(PyExc_TypeError, "bndry is not contiguous and/or aligned");
    return NULL;
  }
  Py_INCREF(bndry);
  x = (double *) PyArray_DATA(bndry);

  if ((PyArray_FLAGS(coeffs) & NPY_IN_ARRAY) != NPY_IN_ARRAY) {
    PyErr_SetString(PyExc_TypeError, "coeffs is not contiguous and/or aligned");
    return NULL;
  }
  Py_INCREF(coeffs);
  c = (double *) PyArray_DATA(coeffs);

  /*
   * dispatch
   */

  coeffs_%(k)d_%(bndry)s(i, r, x, c);

  /*
   * done
   */
  Py_INCREF(Py_None);
  return Py_None;
}

"""

def coeff_c_boundary(k, b):

    print coeff_fcn_bndry_c_head % {'k': k, 'bndry': b}
    coeff_loops_boundary(k, b)
    print coeff_fcn_bndry_c_foot


def coeff_py_boundary(k, b):

    print coeff_fcn_bndry_py % {'k': k, 'bndry': b}

######################################################################
## xi

coeff_fcn_xi_c_head = """
void
coeffs_%(k)d(long int i, int r, double xi, double *x, double *c)
{
  double sum_l, sum_m, prod_n, prod_m;
"""

coeff_fcn_xi_c_foot = """
}
"""

coeff_fcn_xi_py = """
PyObject *
coeffs_%(k)d_py(PyObject *self, PyObject *args)
{
  double *x, *c, xi;
  long int i;
  int r;

  PyObject *bndry, *coeffs;

  /*
   * parse options
   */

  if (! PyArg_ParseTuple(args, "lidOO", &i, &r, &xi, &bndry, &coeffs))
    return NULL;

  if ((PyArray_FLAGS(bndry) & NPY_IN_ARRAY) != NPY_IN_ARRAY) {
    PyErr_SetString(PyExc_TypeError, "bndry is not contiguous and/or aligned");
    return NULL;
  }
  Py_INCREF(bndry);
  x = (double *) PyArray_DATA(bndry);

  if ((PyArray_FLAGS(coeffs) & NPY_IN_ARRAY) != NPY_IN_ARRAY) {
    PyErr_SetString(PyExc_TypeError, "coeffs is not contiguous and/or aligned");
    return NULL;
  }
  Py_INCREF(coeffs);
  c = (double *) PyArray_DATA(coeffs);

  /*
   * dispatch
   */

  coeffs_%(k)d(i, r, xi, x, c);

  /*
   * done
   */
  Py_INCREF(Py_None);
  return Py_None;
}

"""

def coeff_c_xi(k):

    print coeff_fcn_xi_c_head % {'k': k}
    coeff_loops_xi(k)
    print coeff_fcn_xi_c_foot

def coeff_py_xi(k):

    print coeff_fcn_xi_py % {'k': k}


######################################################################
######################################################################

print """
#define PY_ARRAY_UNIQUE_SYMBOL PYWENO_ARRAY_API

#include <stdio.h>

#include <Python.h>
#include <numpy/ndarrayobject.h>
"""

K = range(3, 10)

for k in K:

    coeff_c_boundary(k, 'left')
    coeff_c_boundary(k, 'right')
    coeff_py_boundary(k, 'left')
    coeff_py_boundary(k, 'right')
    coeff_c_xi(k)
    coeff_py_xi(k)

print """
PyObject *
coeffs_xi_py(PyObject *self, PyObject *args)
{
  double *x, *c, xi;
  long int i;
  int r, k;

  PyObject *bndry, *coeffs;

  /*
   * parse options
   */

  if (! PyArg_ParseTuple(args, "liidOO", &i, &r, &k, &xi, &bndry, &coeffs))
    return NULL;

  if ((PyArray_FLAGS(bndry) & NPY_IN_ARRAY) != NPY_IN_ARRAY) {
    PyErr_SetString(PyExc_TypeError, "bndry is not contiguous and/or aligned");
    return NULL;
  }
  Py_INCREF(bndry);
  x = (double *) PyArray_DATA(bndry);

  if ((PyArray_FLAGS(coeffs) & NPY_IN_ARRAY) != NPY_IN_ARRAY) {
    PyErr_SetString(PyExc_TypeError, "coeffs is not contiguous and/or aligned");
    return NULL;
  }
  Py_INCREF(coeffs);
  c = (double *) PyArray_DATA(coeffs);

  /*
   * dispatch
   */

  switch (k) {
"""

for k in K:
    print """
  case %(k)d:
    coeffs_%(k)d(i, r, xi, x, c);
    break;
    """ % {'k': k}

print """
  }

  /*
   * done
   */
  Py_INCREF(Py_None);
  return Py_None;
}
"""

print 'static PyMethodDef CStencilMethods[] = {'
print '  {"reconstruction_coeffs", coeffs_xi_py, METH_VARARGS, "Compute the reconstruction coefficients to reconstruct at xi."},'

for k in K:
    print '  {"reconstruction_coeffs_%(k)d_left", coeffs_%(k)d_left_py, METH_VARARGS, "Compute the reconstruction coefficients (left) for k=%(k)d."},' % {'k': k}
    print '  {"reconstruction_coeffs_%(k)d_right", coeffs_%(k)d_right_py, METH_VARARGS, "Compute the reconstruction coefficients (right) for k=%(k)d."},' % {'k': k}
    print '  {"reconstruction_coeffs_%(k)d", coeffs_%(k)d_py, METH_VARARGS, "Compute the reconstruction coefficients for k=%(k)d to reconstruct at xi."},' % {'k': k}

print """  {NULL, NULL, 0, NULL}
};

PyMODINIT_FUNC
initcstencil(void)
{
  (void) Py_InitModule("cstencil", CStencilMethods);
  import_array();
}
"""
