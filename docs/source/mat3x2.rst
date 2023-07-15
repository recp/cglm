.. default-domain:: C

mat3x2
======

Header: cglm/mat3x2.h

Table of contents (click to go):
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

Macros:

1. GLM_MAT3X2_ZERO_INIT
#. GLM_MAT3x2_ZERO

Functions:

1. :c:func:`glm_mat3x2_make`

Functions documentation
~~~~~~~~~~~~~~~~~~~~~~~

.. c:function:: void glm_mat3x2_make(float * __restrict src, mat3x2 dest)

    Create mat3x2 matrix from pointer

    | NOTE: **@src** must contain at least 6 elements.
    Parameters:
      | *[in]*  **src**  pointer to an array of floats
      | *[out]* **dest** destination matrix3x2
