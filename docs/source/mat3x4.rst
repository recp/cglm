.. default-domain:: C

mat3x4
======

Header: cglm/mat3x4.h

Table of contents (click to go):
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

Macros:

1. GLM_MAT3X4_ZERO_INIT
#. GLM_MAT3X4_ZERO

Functions:

1. :c:func:`glm_mat3x4_make`

Functions documentation
~~~~~~~~~~~~~~~~~~~~~~~

.. c:function:: void glm_mat3x4_make(float * __restrict src, mat3x4 dest)

    Create mat3x4 matrix from pointer

    | NOTE: **@src** must contain at least 12 elements.
    Parameters:
      | *[in]*  **src**  pointer to an array of floats
      | *[out]* **dest** destination matrix3x4
