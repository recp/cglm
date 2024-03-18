.. default-domain:: C

mat3
====

Header: cglm/mat3.h

Table of contents (click to go):
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

Macros:

1. GLM_MAT3_IDENTITY_INIT
#. GLM_MAT3_ZERO_INIT
#. GLM_MAT3_IDENTITY
#. GLM_MAT3_ZERO
#. glm_mat3_dup(mat, dest)

Functions:

1. :c:func:`glm_mat3_copy`
#. :c:func:`glm_mat3_identity`
#. :c:func:`glm_mat3_identity_array`
#. :c:func:`glm_mat3_zero`
#. :c:func:`glm_mat3_mul`
#. :c:func:`glm_mat3_transpose_to`
#. :c:func:`glm_mat3_transpose`
#. :c:func:`glm_mat3_mulv`
#. :c:func:`glm_mat3_quat`
#. :c:func:`glm_mat3_scale`
#. :c:func:`glm_mat3_det`
#. :c:func:`glm_mat3_inv`
#. :c:func:`glm_mat3_trace`
#. :c:func:`glm_mat3_swap_col`
#. :c:func:`glm_mat3_swap_row`
#. :c:func:`glm_mat3_rmc`
#. :c:func:`glm_mat3_make`

Functions documentation
~~~~~~~~~~~~~~~~~~~~~~~

.. c:function:: void  glm_mat3_copy(mat3 mat, mat3 dest)

    copy mat3 to another one (dest).

    Parameters:
      | *[in]*  **mat**   source
      | *[out]* **dest**  destination

.. c:function:: void  glm_mat3_identity(mat3 mat)

    copy identity mat3 to mat, or makes mat to identity

    Parameters:
      | *[out]* **mat**  matrix

.. c:function:: void  glm_mat3_identity_array(mat3 * __restrict mat, size_t count)

    make given matrix array's each element identity matrix

    Parameters:
      | *[in,out]* **mat**  matrix array (must be aligned (16/32) if alignment is not disabled)
      | *[in]* **count**  count of matrices

.. c:function:: void  glm_mat3_zero(mat3 mat)

    make given matrix zero

    Parameters:
      | *[in,out]* **mat**  matrix to

.. c:function:: void  glm_mat3_mul(mat3 m1, mat3 m2, mat3 dest)

    multiply m1 and m2 to dest

    m1, m2 and dest matrices can be same matrix, it is possible to write this:

    .. code-block:: c

       mat3 m = GLM_MAT3_IDENTITY_INIT;
       glm_mat3_mul(m, m, m);

    Parameters:
      | *[in]*  **m1**    left matrix
      | *[in]*  **m2**    right matrix
      | *[out]* **dest**  destination matrix

.. c:function:: void  glm_mat3_transpose_to(mat3 m, mat3 dest)

    transpose mat4 and store in dest
    source matrix will not be transposed unless dest is m

    Parameters:
      | *[in]*  **mat**   source
      | *[out]* **dest**  destination

.. c:function:: void  glm_mat3_transpose(mat3 m)

    transpose mat3 and store result in same matrix

    Parameters:
      | *[in]*  **mat**   source
      | *[out]* **dest**  destination

.. c:function:: void  glm_mat3_mulv(mat3 m, vec3 v, vec3 dest)

    multiply mat3 with vec3 (column vector) and store in dest vector

    Parameters:
      | *[in]*  **m**     mat3 (left)
      | *[in]*  **v**     vec3 (right, column vector)
      | *[out]* **dest**  destination (result, column vector)

.. c:function:: void  glm_mat3_quat(mat3 m, versor dest)

    convert mat3 to quaternion

    Parameters:
      | *[in]*  **m**     rotation matrix
      | *[out]* **dest**  destination quaternion

.. c:function:: void  glm_mat3_scale(mat3 m, float s)

    multiply matrix with scalar

    Parameters:
      | *[in, out]* **m** matrix
      | *[in]*      **s** scalar

.. c:function:: float  glm_mat3_det(mat3 mat)

    returns mat3 determinant

    Parameters:
      | *[in]*  **mat**   matrix

    Returns:
        mat3 determinant

.. c:function:: void glm_mat3_inv(mat3 mat, mat3 dest)

    inverse mat3 and store in dest

    Parameters:
      | *[in]*  **mat**  matrix
      | *[out]* **dest** destination (inverse matrix)

.. c:function:: void glm_mat3_trace(mat3 m)

    | sum of the elements on the main diagonal from upper left to the lower right

    Parameters:
      | *[in]*  **m**  matrix

    Returns:
        trace of matrix

.. c:function:: void  glm_mat3_swap_col(mat3 mat, int col1, int col2)

    swap two matrix columns

    Parameters:
      | *[in, out]*  **mat**   matrix
      | *[in]*       **col1**  col1
      | *[in]*       **col2**  col2

.. c:function:: void  glm_mat3_swap_row(mat3 mat, int row1, int row2)

    swap two matrix rows

    Parameters:
      | *[in, out]*  **mat**   matrix
      | *[in]*       **row1**  row1
      | *[in]*       **row2**  row2

.. c:function:: float  glm_mat3_rmc(vec3 r, mat3 m, vec3 c)

    | **rmc** stands for **Row** * **Matrix** * **Column**

    | helper for  R (row vector) * M (matrix) * C (column vector)

    | the result is scalar because R * M = Matrix1x3 (row vector),
    | then Matrix1x3 * Vec3 (column vector) = Matrix1x1 (Scalar)

    Parameters:
      | *[in]*  **r**  row vector or matrix1x3
      | *[in]*  **m**  matrix3x3
      | *[in]*  **c**  column vector or matrix3x1

    Returns:
        scalar value e.g. Matrix1x1

.. c:function:: void glm_mat3_make(const float * __restrict src, mat3 dest)

    Create mat3 matrix from pointer

    .. note:: **@src** must contain at least 9 elements.

    Parameters:
      | *[in]*  **src**  pointer to an array of floats
      | *[out]* **dest** destination matrix3x3
