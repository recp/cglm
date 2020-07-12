.. default-domain:: C

mat4
====

Header: cglm/mat4.h

Important: :c:func:`glm_mat4_scale` multiplies mat4 with scalar, if you need to
apply scale transform use :c:func:`glm_scale` functions.

Table of contents (click to go):
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

Macros:

1. GLM_MAT4_IDENTITY_INIT
#. GLM_MAT4_ZERO_INIT
#. GLM_MAT4_IDENTITY
#. GLM_MAT4_ZERO
#. glm_mat4_udup(mat, dest)
#. glm_mat4_dup(mat, dest)

Functions:

1. :c:func:`glm_mat4_ucopy`
#. :c:func:`glm_mat4_copy`
#. :c:func:`glm_mat4_identity`
#. :c:func:`glm_mat4_identity_array`
#. :c:func:`glm_mat4_zero`
#. :c:func:`glm_mat4_pick3`
#. :c:func:`glm_mat4_pick3t`
#. :c:func:`glm_mat4_ins3`
#. :c:func:`glm_mat4_mul`
#. :c:func:`glm_mat4_mulN`
#. :c:func:`glm_mat4_mulv`
#. :c:func:`glm_mat4_mulv3`
#. :c:func:`glm_mat3_trace`
#. :c:func:`glm_mat3_trace3`
#. :c:func:`glm_mat4_quat`
#. :c:func:`glm_mat4_transpose_to`
#. :c:func:`glm_mat4_transpose`
#. :c:func:`glm_mat4_scale_p`
#. :c:func:`glm_mat4_scale`
#. :c:func:`glm_mat4_det`
#. :c:func:`glm_mat4_inv`
#. :c:func:`glm_mat4_inv_fast`
#. :c:func:`glm_mat4_swap_col`
#. :c:func:`glm_mat4_swap_row`
#. :c:func:`glm_mat4_rmc`

Functions documentation
~~~~~~~~~~~~~~~~~~~~~~~

.. c:function:: void  glm_mat4_ucopy(mat4 mat, mat4 dest)

    copy mat4 to another one (dest). u means align is not required for dest

    Parameters:
      | *[in]*  **mat**   source
      | *[out]* **dest**  destination

.. c:function:: void  glm_mat4_copy(mat4 mat, mat4 dest)

    copy mat4 to another one (dest).

    Parameters:
      | *[in]*  **mat**   source
      | *[out]* **dest**  destination

.. c:function:: void  glm_mat4_identity(mat4 mat)

    copy identity mat4 to mat, or makes mat to identiy

    Parameters:
      | *[out]* **mat**  matrix

.. c:function:: void  glm_mat4_identity_array(mat4 * __restrict mat, size_t count)

    make given matrix array's each element identity matrix

    Parameters:
      | *[in,out]* **mat**  matrix array (must be aligned (16/32) if alignment is not disabled)
      | *[in]* **count**  count of matrices

.. c:function:: void  glm_mat4_zero(mat4 mat)

    make given matrix zero

    Parameters:
      | *[in,out]* **mat**  matrix to

.. c:function:: void  glm_mat4_pick3(mat4 mat, mat3 dest)

    copy upper-left of mat4 to mat3

    Parameters:
      | *[in]*  **mat**   source
      | *[out]* **dest**  destination

.. c:function:: void  glm_mat4_pick3t(mat4 mat, mat4 dest)

    copy upper-left of mat4 to mat3 (transposed)
    the postfix t stands for transpose

    Parameters:
      | *[in]*  **mat**   source
      | *[out]* **dest**  destination

.. c:function:: void  glm_mat4_ins3(mat3 mat, mat4 dest)

    copy mat3 to mat4's upper-left. this function does not fill mat4's other
    elements. To do that use glm_mat4.

    Parameters:
      | *[in]*  **mat**   source
      | *[out]* **dest**  destination

.. c:function:: void  glm_mat4_mul(mat4 m1, mat4 m2, mat4 dest)

    multiply m1 and m2 to dest
    m1, m2 and dest matrices can be same matrix, it is possible to write this:

    .. code-block:: c

       mat4 m = GLM_MAT4_IDENTITY_INIT;
       glm_mat4_mul(m, m, m);

    Parameters:
      | *[in]*  **m1**    left matrix
      | *[in]*  **m2**    right matrix
      | *[out]* **dest**  destination matrix

.. c:function:: void glm_mat4_mulN(mat4 * __restrict matrices[], int len, mat4 dest)

    mupliply N mat4 matrices and store result in dest
    | this function lets you multiply multiple (more than two or more...)
    | matrices

    | multiplication will be done in loop, this may reduce instructions
    | size but if **len** is too small then compiler may unroll whole loop

    .. code-block:: c

       mat m1, m2, m3, m4, res;
       glm_mat4_mulN((mat4 *[]){&m1, &m2, &m3, &m4}, 4, res);

    Parameters:
      | *[in]*  **matrices** array of mat4
      | *[in]*  **len**      matrices count
      | *[out]* **dest**     destination matrix

.. c:function:: void  glm_mat4_mulv(mat4 m, vec4 v, vec4 dest)

    multiply mat4 with vec4 (column vector) and store in dest vector

    Parameters:
      | *[in]*  **m**     mat4 (left)
      | *[in]*  **v**     vec4 (right, column vector)
      | *[in]*  **last**  4th item to make it vec4
      | *[out]* **dest**  vec4 (result, column vector)

.. c:function:: void  glm_mat4_mulv3(mat4 m, vec3 v, float last, vec3 dest)

    | multiply **vec3** with **mat4** and get **vec3** as result
    |
    | actually the result is **vec4**, after multiplication, 
      the last component is trimmed, if you need the result's last component 
      then don't use this function and consider to use **glm_mat4_mulv()**

    Parameters:
      | *[in]*  **m**     mat4(affine transform)
      | *[in]*  **v**     vec3
      | *[in]*  **last**  4th item to make it vec4
      | *[out]* **dest**  result vector (vec3)

.. c:function:: void  glm_mat4_trace(mat4 m)

    | sum of the elements on the main diagonal from upper left to the lower right

    Parameters:
      | *[in]*  **m**  matrix

    Returns:
        trace of matrix

.. c:function:: void  glm_mat4_trace3(mat4 m)

    | trace of matrix (rotation part)
    | sum of the elements on the main diagonal from upper left to the lower right

    Parameters:
      | *[in]*  **m**  matrix

    Returns:
        trace of matrix

.. c:function:: void  glm_mat4_quat(mat4 m, versor dest)

    convert mat4's rotation part to quaternion

    Parameters:
    | *[in]*  **m**     affine matrix
    | *[out]* **dest**  destination quaternion

.. c:function:: void  glm_mat4_transpose_to(mat4 m, mat4 dest)

    transpose mat4 and store in dest
    source matrix will not be transposed unless dest is m

    Parameters:
      | *[in]*  **m**     matrix
      | *[out]* **dest**  destination matrix

.. c:function:: void  glm_mat4_transpose(mat4 m)

    tranpose mat4 and store result in same matrix

    Parameters:
      | *[in]*  **m**     source
      | *[out]* **dest**  destination matrix

.. c:function:: void  glm_mat4_scale_p(mat4 m, float s)

    scale (multiply with scalar) matrix without simd optimization

    Parameters:
      | *[in, out]*  **m**  matrix
      | *[in]*       **s**  scalar

.. c:function:: void  glm_mat4_scale(mat4 m, float s)

    scale (multiply with scalar) matrix
    THIS IS NOT SCALE TRANSFORM, use glm_scale for that.

    Parameters:
      | *[in, out]*  **m**  matrix
      | *[in]*       **s**  scalar

.. c:function:: float  glm_mat4_det(mat4 mat)

    mat4 determinant

    Parameters:
      | *[in]*  **mat**   matrix

    Return:
      | determinant

.. c:function:: void  glm_mat4_inv(mat4 mat, mat4 dest)

    inverse mat4 and store in dest

    Parameters:
      | *[in]*  **mat**   source
      | *[out]* **dest**  destination matrix (inverse matrix)

.. c:function:: void  glm_mat4_inv_fast(mat4 mat, mat4 dest)

    inverse mat4 and store in dest

    | this func uses reciprocal approximation without extra corrections
    | e.g Newton-Raphson. this should work faster than normal,
    | to get more precise use glm_mat4_inv version.

    | NOTE: You will lose precision, glm_mat4_inv is more accurate

    Parameters:
      | *[in]*  **mat**   source
      | *[out]* **dest**  destination

.. c:function:: void  glm_mat4_swap_col(mat4 mat, int col1, int col2)

    swap two matrix columns

    Parameters:
      | *[in, out]*  **mat**   matrix
      | *[in]*       **col1**  col1
      | *[in]*       **col2**  col2

.. c:function:: void  glm_mat4_swap_row(mat4 mat, int row1, int row2)

    swap two matrix rows

    Parameters:
      | *[in, out]*  **mat**   matrix
      | *[in]*       **row1**  row1
      | *[in]*       **row2**  row2

.. c:function:: float  glm_mat4_rmc(vec4 r, mat4 m, vec4 c)

    | **rmc** stands for **Row** * **Matrix** * **Column**

    | helper for  R (row vector) * M (matrix) * C (column vector)

    | the result is scalar because R * M = Matrix1x4 (row vector),
    | then Matrix1x4 * Vec4 (column vector) = Matrix1x1 (Scalar)

    Parameters:
      | *[in]*  **r**  row vector or matrix1x4
      | *[in]*  **m**  matrix4x4
      | *[in]*  **c**  column vector or matrix4x1

    Returns:
        scalar value e.g. Matrix1x1
