.. default-domain:: C

mat2x3
======

Header: cglm/mat2x3.h

Table of contents (click to go):
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

Macros:

1. GLM_MAT2X3_ZERO_INIT
#. GLM_MAT2X3_ZERO

Functions:

1. :c:func:`glm_mat2x3_copy`
#. :c:func:`glm_mat2x3_zero`
#. :c:func:`glm_mat2x3_make`
#. :c:func:`glm_mat2x3_mul`
#. :c:func:`glm_mat2x3_mulv`
#. :c:func:`glm_mat2x3_transpose`
#. :c:func:`glm_mat2x3_scale`

Functions documentation
~~~~~~~~~~~~~~~~~~~~~~~

.. c:function:: void glm_mat2x3_copy(mat2x3 mat, mat2x3 dest)

    copy mat2x3 to another one (dest).

    Parameters:
      | *[in]*  **mat**   source
      | *[out]* **dest**  destination

.. c:function:: void glm_mat2x3_zero(mat2x3 mat)

    make given matrix zero

    Parameters:
      | *[in,out]* **mat**  matrix

.. c:function:: void glm_mat2x3_make(float * __restrict src, mat2x3 dest)

    Create mat2x3 matrix from pointer

    | NOTE: **@src** must contain at least 6 elements.

    Parameters:
      | *[in]*  **src**  pointer to an array of floats
      | *[out]* **dest** destination matrix2x3

.. c:function:: void glm_mat2x3_mul(mat2x3 m1, mat3x2 m2, mat2 dest)

    multiply m1 and m2 to dest

    m1, m2 and dest matrices can be same matrix, it is possible to write this:

    .. code-block:: c

       glm_mat2x3_mul(m, m, m);

    Parameters:
      | *[in]*  **m1**    left matrix
      | *[in]*  **m2**    right matrix
      | *[out]* **dest**  destination matrix

.. c:function:: void glm_mat2x3_mulv(mat2x3 m, vec3 v, vec2 dest)

    multiply mat2x3 with vec3 (column vector) and store in dest vector

    Parameters:
      | *[in]*  **m**     mat2x3 (left)
      | *[in]*  **v**     vec3 (right, column vector)
      | *[out]* **dest**  destination (result, column vector)

.. c:function:: void glm_mat2x3_transpose(mat2x3 m, mat3x2 dest)

    transpose matrix and store in dest

    Parameters:
      | *[in]*  **m**     matrix
      | *[out]* **dest**  destination

.. c:function:: void  glm_mat2x3_scale(mat2x3 m, float s)

    multiply matrix with scalar

    Parameters:
      | *[in, out]* **m** matrix
      | *[in]*      **s** scalar
