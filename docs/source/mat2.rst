.. default-domain:: C

mat2
====

Header: cglm/mat2.h

Table of contents (click to go):
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

Macros:

1. GLM_mat2_IDENTITY_INIT
#. GLM_mat2_ZERO_INIT
#. GLM_mat2_IDENTITY
#. GLM_mat2_ZERO

Functions:

1. :c:func:`glm_mat2_copy`
#. :c:func:`glm_mat2_identity`
#. :c:func:`glm_mat2_identity_array`
#. :c:func:`glm_mat2_zero`
#. :c:func:`glm_mat2_mul`
#. :c:func:`glm_mat2_transpose_to`
#. :c:func:`glm_mat2_transpose`
#. :c:func:`glm_mat2_mulv`
#. :c:func:`glm_mat2_scale`
#. :c:func:`glm_mat2_det`
#. :c:func:`glm_mat2_inv`
#. :c:func:`glm_mat2_trace`
#. :c:func:`glm_mat2_swap_col`
#. :c:func:`glm_mat2_swap_row`
#. :c:func:`glm_mat2_rmc`
#. :c:func:`glm_mat2_make`

Functions documentation
~~~~~~~~~~~~~~~~~~~~~~~

.. c:function:: void glm_mat2_copy(mat2 mat, mat2 dest)

    copy mat2 to another one (dest).

    Parameters:
      | *[in]*  **mat**   source
      | *[out]* **dest**  destination

.. c:function:: void glm_mat2_identity(mat2 mat)

    copy identity mat2 to mat, or makes mat to identity

    Parameters:
      | *[out]* **mat**  matrix

.. c:function:: void glm_mat2_identity_array(mat2 * __restrict mat, size_t count)

    make given matrix array's each element identity matrix

    Parameters:
      | *[in,out]* **mat**  matrix array (must be aligned (16/32) if alignment is not disabled)
      | *[in]* **count**  count of matrices

.. c:function:: void glm_mat2_zero(mat2 mat)

    make given matrix zero

    Parameters:
      | *[in,out]* **mat**  matrix

.. c:function:: void glm_mat2_mul(mat2 m1, mat2 m2, mat2 dest)

    multiply m1 and m2 to dest

    m1, m2 and dest matrices can be same matrix, it is possible to write this:

    .. code-block:: c

       mat2 m = GLM_mat2_IDENTITY_INIT;
       glm_mat2_mul(m, m, m);

    Parameters:
      | *[in]*  **m1**    left matrix
      | *[in]*  **m2**    right matrix
      | *[out]* **dest**  destination matrix

.. c:function:: void glm_mat2_transpose_to(mat2 m, mat2 dest)

    transpose mat4 and store in dest
    source matrix will not be transposed unless dest is m

    Parameters:
      | *[in]*  **mat**   source
      | *[out]* **dest**  destination

.. c:function:: void glm_mat2_transpose(mat2 m)

    transpose mat2 and store result in same matrix

    Parameters:
      | *[in]*  **mat**   source
      | *[out]* **dest**  destination

.. c:function:: void glm_mat2_mulv(mat2 m, vec2 v, vec2 dest)

    multiply mat2 with vec2 (column vector) and store in dest vector

    Parameters:
      | *[in]*  **mat**   mat2 (left)
      | *[in]*  **v**     vec2 (right, column vector)
      | *[out]* **dest**  destination (result, column vector)

.. c:function:: void  glm_mat2_scale(mat2 m, float s)

    multiply matrix with scalar

    Parameters:
      | *[in, out]* **m**  matrix
      | *[in]*      **s**  scalar

.. c:function:: float  glm_mat2_det(mat2 mat)

    returns mat2 determinant

    Parameters:
      | *[in]*  **mat**   matrix

    Returns:
        mat2 determinant

.. c:function:: void glm_mat2_inv(mat2 mat, mat2 dest)

    inverse mat2 and store in dest

    Parameters:
      | *[in]*  **mat**  matrix
      | *[out]* **dest** destination (inverse matrix)

.. c:function:: void glm_mat2_trace(mat2 m)

    | sum of the elements on the main diagonal from upper left to the lower right

    Parameters:
      | *[in]*  **m**  matrix

    Returns:
        trace of matrix

.. c:function:: void glm_mat2_swap_col(mat2 mat, int col1, int col2)

    swap two matrix columns

    Parameters:
      | *[in, out]*  **mat**   matrix
      | *[in]*       **col1**  col1
      | *[in]*       **col2**  col2

.. c:function:: void glm_mat2_swap_row(mat2 mat, int row1, int row2)

    swap two matrix rows

    Parameters:
      | *[in, out]*  **mat**   matrix
      | *[in]*       **row1**  row1
      | *[in]*       **row2**  row2

.. c:function:: float glm_mat2_rmc(vec2 r, mat2 m, vec2 c)

    | **rmc** stands for **Row** * **Matrix** * **Column**

    | helper for  R (row vector) * M (matrix) * C (column vector)

    | the result is scalar because R * M = Matrix1x2 (row vector),
    | then Matrix1x2 * Vec2 (column vector) = Matrix1x1 (Scalar)

    Parameters:
      | *[in]*  **r**  row vector or matrix1x2
      | *[in]*  **m**  matrix2x2
      | *[in]*  **c**  column vector or matrix2x1

    Returns:
        scalar value e.g. Matrix1x1

.. c:function:: void glm_mat2_make(const float * __restrict src, mat2 dest)

    Create mat2 matrix from pointer

    .. note:: **@src** must contain at least 4 elements.

    Parameters:
      | *[in]*  **src**  pointer to an array of floats
      | *[out]* **dest** destination matrix2x2
