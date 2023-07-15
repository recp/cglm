.. default-domain:: C

mat2x4
======

Header: cglm/mat2x4.h

Table of contents (click to go):
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

Macros:

1. GLM_MAT2X4_ZERO_INIT
#. GLM_MAT2x4_ZERO

Functions:

1. :c:func:`glm_mat2x4_make`

Functions documentation
~~~~~~~~~~~~~~~~~~~~~~~

.. c:function:: void glm_mat2x4_make(float * __restrict src, mat2x4 dest)

    Create mat2x4 matrix from pointer

    | NOTE: **@src** must contain at least 8 elements.

    Parameters:
      | *[in]*  **src**  pointer to an array of floats
      | *[out]* **dest** destination matrix2x4
