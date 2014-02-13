'''Generate the ccoeffs extension module.'''

from textwrap import dedent

# set of k values to generate reconstruction functions for
K = range(3, 10)


######################################################################
# write each reconstruction coeff function in its own file

def reconstruction_coeff_functions(k):

  f = open('../coeffs%03d.c' % k, 'w')

  f.write(dedent('''\
       void
       coeffs%03d(double xi, long int i, int r, double *x, double *c)
       {
         double sum_l, sum_m, prod_n, prod_m;
       ''' % k))

  for j in xrange(k):

    f.write('  /* j = %d */\n' % (j))
    f.write('  sum_l = 0.0;\n')

    for l in xrange(j+1, k+1):

      f.write('\n')
      f.write('  /* l = %d */\n' % (l))
      f.write('  sum_m = 0.0;\n')

      ms = range(0,k+1)
      ms.remove(l)

      for m in ms:

        f.write('\n')
        f.write('  /* m = %d */\n' % (m))

        ns = range(0,k+1)
        ns.remove(l)
        ns.remove(m)

        f.write('  prod_n = 1.0;\n')

        for n in ns:
          f.write('  prod_n *= xi - x[i-r+%d];  /* n = %d */\n' % (n,n))

        f.write('  sum_m += prod_n;\n')


      f.write('\n')
      f.write('  prod_m = 1.0;\n')
      for m in ms:
        f.write('  prod_m *= x[i-r+%d] - x[i-r+%d];\n' % (l,m))


      f.write('\n')
      f.write('  sum_l += sum_m / prod_m * (x[i-r+%d+1] - x[i-r+%d]);\n' % (j, j))

    f.write('\n')
    f.write('  c[%d] = sum_l;\n' % (j))

  f.write('}\n')

  f.close()

for k in K:
  reconstruction_coeff_functions(k)



######################################################################
# write the python c extension file

f = open('../ccoeffs.c', 'w')

f.write(dedent('''\
     #define PY_ARRAY_UNIQUE_SYMBOL PYWENO_ARRAY_API

     #include <stdio.h>

     #include <Python.h>
     #include <numpy/ndarrayobject.h>

     '''))

for k in K:
  f.write(dedent('''\
       void coeffs%03d(double xi, long int i, int r, double *x, double *c);
       ''' % k))

f.write(dedent('''\

     PyObject *
     reconstruction_coeffs_py(PyObject *self, PyObject *args)
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
     '''))

for k in K:
  f.write(dedent('''\
       case %(k)d:
         coeffs%(k)03d(xi, i, r, x, c);
         break;
       ''' % {'k': k}))

f.write(dedent('''\
       default:
         return NULL;
       }

       /*
        * done
        */
       Py_INCREF(Py_None);
       return Py_None;
     }

     static PyMethodDef ccoeffsmethods[] = {
       {"reconstruction_coeffs", reconstruction_coeffs_py, METH_VARARGS, "Compute the reconstruction coefficients to reconstruct at xi."},
       {NULL, NULL, 0, NULL}
     };

     PyMODINIT_FUNC
     initccoeffs(void)
     {
       (void) Py_InitModule("ccoeffs", ccoeffsmethods);
       import_array();
     }
     '''))

f.close()
