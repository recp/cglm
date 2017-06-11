.. cglm documentation master file, created by
   sphinx-quickstart on Tue Jun  6 20:31:05 2017.
   You can adapt this file completely to your liking, but it should at least
   contain the root `toctree` directive.

Welcome to cglm's documentation!
================================

**cglm** is optimized 3D math library written in C99 (compatible with C89).
It is similar to original **glm** library except this is mainly for **C**

This library stores matrices as row-major order but in the future column-major
is considered to be supported as optional.

Also currently only **float** type is supported for most operations.

**Features**

* general purpose matrix operations (mat4, mat3)
* chain matrix multiplication (square only)
* general purpose vector operations (cross, dot, rotate, proj, angle...)
* affine transforms
* matrix decomposition (extract rotation, scaling factor)
* optimized affine transform matrices (mul, rigid-body inverse)
* camera (lookat)
* projections (ortho, perspective)
* quaternions
* euler angles / yaw-pitch-roll to matrix
* extract euler angles
* inline or pre-compiled function call
* more features (todo)

.. toctree::
   :maxdepth: 2
   :caption: Table Of Contents:

   build
   getting_started

Indices and tables
==================

* :ref:`genindex`
* :ref:`modindex`
* :ref:`search`
