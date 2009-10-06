import setuptools

# XXX: use distutils instead, add dependencies

setuptools.setup(

    name = "PyWENO",
    version = "0.1",
    packages = ['pyweno'],

    test_suite = 'nose.collector',

    ext_modules = [
        setuptools.Extension('pyweno.cstencil',
                             sources = ['src/cstencil.c'],
                             include_dirs=["/usr/local/lib/python2.5/site-packages/numpy/core/include/numpy/"]
                             )],

    author = "Matthew Emmett",
    author_email = "matthew.emmett@ualberta.ca",
    description = "Weighted Essentially Non-oscillatory (WENO) approximation.",
    license = "BSD",
    keywords = "weno",
    url = "http://www.math.ualberta.ca/~memmett/pyweno/"

    )
