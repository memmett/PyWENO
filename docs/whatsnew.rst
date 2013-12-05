What's new
===========

**New in v0.11.0:**

* The kernel generator was cleaned up a lot and simplified.

* The function generator was removed.  It was hard to maintain and
  seldom used.  I recommend using the new kernel generator together
  with a template engine such as Jinja2 to incorporate the kernels
  into your codes.

* New symbolic C routines are used to compute variou non-uniform
  coefficients.

**New in v0.9.0:**

* A bunch of mush faster non-uniform code was contributed by Ben
  Thompson.
