.. default-domain:: C

mat4x3
======

Header: cglm/mat4x3.h

Table of contents (click to go):
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

Macros:

1. GLM_MAT4X3_ZERO_INIT
#. GLM_MAT4X3_ZERO

Functions:

1. :c:func:`glm_mat4x3_make`

Functions documentation
~~~~~~~~~~~~~~~~~~~~~~~

.. c:function:: void glm_mat4x3_make(float * __restrict src, mat4x3 dest)

    Create mat4x3 matrix from pointer

    | NOTE: **@src** must contain at least 12 elements.
    Parameters:
      | *[in]*  **src**  pointer to an array of floats
      | *[out]* **dest** destination matrix4x3
