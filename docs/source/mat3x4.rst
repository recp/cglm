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

1. :c:func:`glm_mat3x4_copy`
#. :c:func:`glm_mat3x4_zero`
#. :c:func:`glm_mat3x4_make`
#. :c:func:`glm_mat3x4_mul`
#. :c:func:`glm_mat3x4_mulv`
#. :c:func:`glm_mat3x4_transpose`
#. :c:func:`glm_mat3x4_scale`

Functions documentation
~~~~~~~~~~~~~~~~~~~~~~~

.. c:function:: void glm_mat3x4_copy(mat3x4 mat, mat3x4 dest)

    copy mat3x4 to another one (dest).

    Parameters:
      | *[in]*  **mat**   source
      | *[out]* **dest**  destination

.. c:function:: void glm_mat3x4_zero(mat3x4 mat)

    make given matrix zero

    Parameters:
      | *[in,out]* **mat**  matrix

.. c:function:: void glm_mat3x4_make(float * __restrict src, mat3x4 dest)

    Create mat3x4 matrix from pointer

    | NOTE: **@src** must contain at least 12 elements.
    Parameters:
      | *[in]*  **src**  pointer to an array of floats
      | *[out]* **dest** destination matrix3x4

.. c:function:: void glm_mat3x4_mul(mat3x4 m1, mat4x3 m2, mat3 dest)

    multiply m1 and m2 to dest

    m1, m2 and dest matrices can be same matrix, it is possible to write this:

    .. code-block:: c

       glm_mat3x4_mul(m, m, m);

    Parameters:
      | *[in]*  **m1**    left matrix
      | *[in]*  **m2**    right matrix
      | *[out]* **dest**  destination matrix

.. c:function:: void glm_mat3x4_mulv(mat3x4 m, vec4 v, vec3 dest)

    multiply mat3x4 with vec4 (column vector) and store in dest vector

    Parameters:
      | *[in]*  **m**     mat3x4 (left)
      | *[in]*  **v**     vec4 (right, column vector)
      | *[out]* **dest**  destination (result, column vector)

.. c:function:: void glm_mat3x4_transpose(mat3x4 m, mat4x3 dest)

    transpose matrix and store in dest

    Parameters:
      | *[in]*  **m**     matrix
      | *[out]* **dest**  destination

.. c:function:: void  glm_mat3x4_scale(mat3x4 m, float s)

    multiply matrix with scalar

    Parameters:
      | *[in, out]* **m** matrix
      | *[in]*      **s** scalar
