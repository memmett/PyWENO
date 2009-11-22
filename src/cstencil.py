"""Construct the C files that comprise the cstencil extension module.

   The purpose of the cstencil extension module is to speed up the
   computation of the reconstruction coefficients.

   This file generates fully un-rolled C functions.

   First, for each k, we generate two C files to compute reconstruct
   coefficients for a function (d0) and its derivative (d1).

   Next, we generate a C file that defines a Python callable
   dispatcher and the cstencil extension module.

   """

from textwrap import dedent

# set of k values to generate reconstruction functions for
K = range(3, 10)


######################################################################
# write each reconstruction coeff function in its own file

def reconstruction_coeff_functions_d0(k):

    f = open('reconstruction_coeffs_k%d_d%d.c' % (k, 0), 'w')

    f.write(dedent('''\
             void
             reconstruction_coeffs_k%d_d%d(double xi, long int i, int r, double *x, double *c)
             {
               double sum_l, sum_m, prod_n, prod_m;
             ''' % (k, 0)))

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


def reconstruction_coeff_functions_d1(k):

    f = open('reconstruction_coeffs_k%d_d%d.c' % (k, 1), 'w')

    f.write(dedent('''\
             void
             reconstruction_coeffs_k%d_d%d(double xi, long int i, int r, double *x, double *c)
             {
               double sum_l, sum_m, sum_n, prod_p, prod_m;
             ''' % (k,1)))

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

                f.write('  sum_n = 0.0;\n')

                for n in ns:

                    f.write('\n')
                    f.write('  /* n = %d */\n' % (n))

                    ps = range(0,k+1)
                    ps.remove(l)
                    ps.remove(m)
                    ps.remove(n)

                    f.write('  prod_p = 1.0;\n')

                    for p in ps:
                        f.write('  prod_p *= xi - x[i-r+%d];  /* p = %d */\n' % (p, p))

                    f.write('  sum_n += prod_p;\n')

                f.write('  sum_m += sum_n;\n')


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
    reconstruction_coeff_functions_d0(k)
    reconstruction_coeff_functions_d1(k)


######################################################################
# write the python c extension (cstenil.c) file

f = open('cstencil.c', 'w')

f.write(dedent('''\
         #define PY_ARRAY_UNIQUE_SYMBOL PYWENO_ARRAY_API

         #include <stdio.h>

         #include <Python.h>
         #include <numpy/ndarrayobject.h>

         '''))

for k in K:
    f.write(dedent('''\
             void reconstruction_coeffs_k%(k)d_d0(double xi, long int i, int r, double *x, double *c);
             void reconstruction_coeffs_k%(k)d_d1(double xi, long int i, int r, double *x, double *c);
             ''' % {'k': k}))

f.write(dedent('''\


         PyObject *
         reconstruction_coeffs_py(PyObject *self, PyObject *args)
         {
           double *x, *c, xi;
           long int i;
           int r, k, d=0;

           PyObject *bndry, *coeffs;

           /*
            * parse options
            */

           if (! PyArg_ParseTuple(args, "dliiiOO", &xi, &i, &r, &k, &d, &bndry, &coeffs))
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
               if (d==0)
                 reconstruction_coeffs_k%(k)d_d0(xi, i, r, x, c);
               else if (d==1)
                 reconstruction_coeffs_k%(k)d_d1(xi, i, r, x, c);
               break;
             ''' % {'k': k}))

f.write(dedent('''\
           }

           /*
            * done
            */
           Py_INCREF(Py_None);
           return Py_None;
         }

         static PyMethodDef CStencilMethods[] = {
           {"reconstruction_coeffs", reconstruction_coeffs_py, METH_VARARGS, "Compute the reconstruction coefficients to reconstruct at xi."},
           {NULL, NULL, 0, NULL}
         };

         PyMODINIT_FUNC
         initcstencil(void)
         {
           (void) Py_InitModule("cstencil", CStencilMethods);
           import_array();
         }
         '''))

f.close()
