.. default-domain:: C

mat4x2
======

Header: cglm/mat4x2.h

Table of contents (click to go):
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

Macros:

1. GLM_MAT4X2_ZERO_INIT
#. GLM_MAT4X2_ZERO

Functions:

1. :c:func:`glm_mat4x2_make`

Functions documentation
~~~~~~~~~~~~~~~~~~~~~~~

.. c:function:: void glm_mat4x2_make(float * __restrict src, mat4x2 dest)

    Create mat4x2 matrix from pointer

    | NOTE: **@src** must contain at least 8 elements.
    Parameters:
      | *[in]*  **src**  pointer to an array of floats
      | *[out]* **dest** destination matrix4x2
