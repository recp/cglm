.. default-domain:: C

mat2x3
======

Header: cglm/mat2x3.h

Table of contents (click to go):
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

Macros:

1. GLM_MAT2X3_ZERO_INIT
#. GLM_MAT2x3_ZERO

Functions:

1. :c:func:`glm_mat2x3_make`

Functions documentation
~~~~~~~~~~~~~~~~~~~~~~~

.. c:function:: void glm_mat2x3_make(float * __restrict src, mat2x3 dest)

    Create mat2x3 matrix from pointer

    | NOTE: **@src** must contain at least 6 elements.

    Parameters:
      | *[in]*  **src**  pointer to an array of floats
      | *[out]* **dest** destination matrix2x3
