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

1. :c:func:`glm_mat4x2_copy`
#. :c:func:`glm_mat4x2_zero`
#. :c:func:`glm_mat4x2_make`
#. :c:func:`glm_mat4x2_mul`
#. :c:func:`glm_mat4x2_mulv`
#. :c:func:`glm_mat4x2_transpose`
#. :c:func:`glm_mat4x2_scale`

Functions documentation
~~~~~~~~~~~~~~~~~~~~~~~

.. c:function:: void glm_mat4x2_copy(mat4x2 mat, mat4x2 dest)

    copy mat4x2 to another one (dest).

    Parameters:
      | *[in]*  **mat**   source
      | *[out]* **dest**  destination

.. c:function:: void glm_mat4x2_zero(mat4x2 mat)

    make given matrix zero

    Parameters:
      | *[in,out]* **mat**  matrix

.. c:function:: void glm_mat4x2_make(float * __restrict src, mat4x2 dest)

    Create mat4x2 matrix from pointer

    | NOTE: **@src** must contain at least 8 elements.
    Parameters:
      | *[in]*  **src**  pointer to an array of floats
      | *[out]* **dest** destination matrix4x2

.. c:function:: void glm_mat4x2_mul(mat4x2 m1, mat2x4 m2, mat4 dest)

    multiply m1 and m2 to dest

    m1, m2 and dest matrices can be same matrix, it is possible to write this:

    .. code-block:: c

       glm_mat4x2_mul(m, m, m);

    Parameters:
      | *[in]*  **m1**    left matrix
      | *[in]*  **m2**    right matrix
      | *[out]* **dest**  destination matrix

.. c:function:: void glm_mat4x2_mulv(mat4x2 m, vec2 v, vec4 dest)

    multiply mat4x2 with vec2 (column vector) and store in dest vector

    Parameters:
      | *[in]*  **m**     mat4x2 (left)
      | *[in]*  **v**     vec2 (right, column vector)
      | *[out]* **dest**  destination (result, column vector)

.. c:function:: void glm_mat4x2_transpose(mat4x2 m, mat2x4 dest)

    transpose matrix and store in dest

    Parameters:
      | *[in]*  **m**     matrix
      | *[out]* **dest**  destination

.. c:function:: void  glm_mat4x2_scale(mat4x2 m, float s)

    multiply matrix with scalar

    Parameters:
      | *[in, out]* **m** matrix
      | *[in]*      **s** scalar
