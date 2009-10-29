"""Construct C file to compute reconstruction coefficients as a python
   extension module."""

from textwrap import dedent

K = range(3, 10)

######################################################################

def reconstruction_coeff_functions_d0(k):
    """Print the C function (and Python callable function) used to
    compute the reconstruction coefficients c_j of order *k* to
    reconstruct at the point *xi*."""

    print dedent('''\
             void
             reconstruction_coeffs_k%d_d0(double xi, long int i, int r, double *x, double *c)
             {
               double sum_l, sum_m, prod_n, prod_m;
             ''' % (k))

    print '  /*'
    print '   * compute reconstruction coeffs of order %d' % (k)
    print '   */'
    print ''

    for j in xrange(k):

        print ''
        print '  /* j = %d */' % (j)
        print '  sum_l = 0.0;'

        for l in xrange(j+1, k+1):

            print ''
            print '  /* l = %d */' % (l)
            print '  sum_m = 0.0;'

            ms = range(0,k+1)
            ms.remove(l)

            for m in ms:

                print ''
                print '  /* m = %d */' % (m)

                ns = range(0,k+1)
                ns.remove(l)
                ns.remove(m)

                print '  prod_n = 1.0;'

                for n in ns:
                    print '  prod_n *= xi - x[i-r+%d];  /* n = %d */' % (n,n)

                print '  sum_m += prod_n;'


            print ''
            print '  prod_m = 1.0;'
            for m in ms:
                print '  prod_m *= x[i-r+%d] - x[i-r+%d];' % (l,m)


            print ''
            print '  sum_l += sum_m / prod_m * (x[i-r+%d+1] - x[i-r+%d]);' % (j, j)

        print ''
        print '  c[%d] = sum_l;' % (j)

    print '}'
    print ''

    print dedent('''\
             PyObject *
             reconstruction_coeffs_k%(k)d_d0_py(PyObject *self, PyObject *args)
             {
               double *x, *c, xi;
               long int i;
               int r;

               PyObject *bndry, *coeffs;

               /*
                * parse options
                */

               if (! PyArg_ParseTuple(args, "dlidOO", &xi, &i, &r, &bndry, &coeffs))
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

               reconstruction_coeffs_k%(k)d_d0(xi, i, r, x, c);

               /*
                * done
                */
               Py_INCREF(Py_None);
               return Py_None;
             }
             ''' % {'k': k})

def reconstruction_coeff_generic_function_d0(K):

    print dedent('''\
             PyObject *
             reconstruction_coeffs_d0_py(PyObject *self, PyObject *args)
             {
               double *x, *c, xi;
               long int i;
               int r, k;

               PyObject *bndry, *coeffs;

               /*
                * parse options
                */

               if (! PyArg_ParseTuple(args, "dliiOO", &xi, &i, &r, &k, &bndry, &coeffs))
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
             ''')

    for k in K:
        print dedent('''\
                 case %(k)d:
                   reconstruction_coeffs_k%(k)d_d0(xi, i, r, x, c);
                   break;
                 ''' % {'k': k})

    print dedent('''\
               }

               /*
                * done
                */
               Py_INCREF(Py_None);
               return Py_None;
             }
             ''')


######################################################################


## c header
print dedent('''\
         #define PY_ARRAY_UNIQUE_SYMBOL PYWENO_ARRAY_API

         #include <stdio.h>

         #include <Python.h>
         #include <numpy/ndarrayobject.h>
         ''')

## specific reconstruction functions

for k in K:
    reconstruction_coeff_functions_d0(k)

## generic reconstruction functions

reconstruction_coeff_generic_function_d0(K)

## cstencil methods

print '''static PyMethodDef CStencilMethods[] = {
           {"reconstruction_coeffs", reconstruction_coeffs_d0_py, METH_VARARGS, "Compute the reconstruction coefficients to reconstruct at xi."},
      '''

for k in K:
    print '''  {"reconstruction_coeffs_k%(k)d_d0", reconstruction_coeffs_k%(k)d_d0_py, METH_VARARGS, "Compute the reconstruction coefficients for k=%(k)d to reconstruct at xi."},''' % {'k': k}

print '  {NULL, NULL, 0, NULL}'
print '};'

## init function

print dedent('''\
         PyMODINIT_FUNC
         initcstencil(void)
         {
           (void) Py_InitModule("cstencil", CStencilMethods);
           import_array();
         }
         ''')
