.. default-domain:: C

mat2
====

Header: cglm/mat2.h

Table of contents (click to go):
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

Macros:

1. GLM_MAT2_IDENTITY_INIT
#. GLM_MAT2_ZERO_INIT
#. GLM_MAT2_IDENTITY
#. GLM_MAT2_ZERO

Functions:

1. :c:func:`glm_mat2_make`
#. :c:func:`glm_mat2_copy`
#. :c:func:`glm_mat2_identity`
#. :c:func:`glm_mat2_identity_array`
#. :c:func:`glm_mat2_zero`
#. :c:func:`glm_mat2_mul`
#. :c:func:`glm_mat2_mulv`
#. :c:func:`glm_mat2_transpose_to`
#. :c:func:`glm_mat2_transpose`
#. :c:func:`glm_mat2_scale`
#. :c:func:`glm_mat2_inv`
#. :c:func:`glm_mat2_swap_col`
#. :c:func:`glm_mat2_swap_row`
#. :c:func:`glm_mat2_det`
#. :c:func:`glm_mat2_trace`
#. :c:func:`glm_mat2_rmc`

Represented
~~~~~~~~~~~

.. csv-table:: mat2x2
   :header: "", "column 1", "column 2"

   "row 1", "m00", "m10"
   "row 2", "m01", "m11"

Functions documentation
~~~~~~~~~~~~~~~~~~~~~~~

.. c:function:: void glm_mat2_make(const float * __restrict src, mat2 dest)

    Create mat2 (dest) from pointer (src).

    .. note:: **@src** must contain at least 4 elements.

    Parameters:
      | *[in]*  **src**  pointer to an array of floats (left)
      | *[out]* **dest** destination (result, mat2)

    .. note:: Mathematical explanation

    .. csv-table:: float array (1x4) **(src)**
        :header: "", "column 1"

        "row 1", "v0"
        "row 2", "v1"
        "row 3", "v2"
        "row 4", "v3"

    .. csv-table:: mat2 **(dest)**
        :header: "", "column 1", "column 2"

        "row 1", "v0", "v2"
        "row 2", "v1", "v3"

    .. note:: Example

    .. code-block:: c

        mat2 dest = GLM_MAT2_ZERO_INIT;
        float src[4] = { 1.00, 5.00, 8.00, 11.00 };
        glm_mat2_make(src, dest);

    .. csv-table:: float array (1x4) **(src)**
        :header: "", "column 1"

        "row 1", "1.00"
        "row 2", "5.00"
        "row 3", "8.00"
        "row 4", "11.00"

    .. csv-table:: mat2 **(dest)** Before
        :header: "", "column 1", "column 2"

        "row 1", "0.00", "0.00"
        "row 2", "0.00", "0.00"

    .. csv-table:: mat2 **(dest)** After
        :header: "", "column 1", "column 2"

        "row 1", "1.00", "8.00"
        "row 2", "5.00", "11.00"

.. c:function:: void glm_mat2_copy(mat2 mat, mat2 dest)

    Copy mat2 (mat) to mat2 (dest).

    Parameters:
      | *[in]*  **mat**  mat2 (left,src)
      | *[out]* **dest** destination (result, mat2)

    .. note:: Mathematical explanation

    .. csv-table:: mat2 **(mat)**
        :header: "", "column 1", "column 2"

        "row 1", "m00", "m10"
        "row 2", "m01", "m11"

    .. csv-table:: mat2 **(dest)**
        :header: "", "column 1", "column 2"

        "row 1", "m00", "m10"
        "row 2", "m01", "m11"

    .. note:: Example

    .. code-block:: c

        mat2 mat = {{3.00,4.00},{7.00,8.00}};
        mat2 dest = GLM_MAT2_ZERO_INIT;
        glm_mat2_copy(mat, dest);

    .. csv-table:: mat2 **(mat)**
        :header: "", "column 1", "column 2"

        "row 1", "3.00", "7.00"
        "row 2", "4.00", "8.00"

    .. csv-table:: mat2 **(dest)** Before
        :header: "", "column 1", "column 2"

        "row 1", "0.00", "0.00"
        "row 2", "0.00", "0.00"

    .. csv-table:: mat2 **(dest)** After
        :header: "", "column 1", "column 2"

        "row 1", "3.00", "7.00"
        "row 2", "4.00", "8.00"

.. c:function:: void glm_mat2_identity(mat2 m)

    | Copy a mat2 identity to mat2 **(m)**, or makes mat2 **(m)** an identity.
    |
    | The same thing may be achieved with either of bellow methods,
    | but it is more easy to do that with this func especially for members
    | e.g. ``glm_mat2_identity(aStruct->aMatrix);``.

    .. code-block:: c

        glm_mat2_copy(GLM_MAT2_IDENTITY, m);

        // or
        mat2 mat = GLM_MAT2_IDENTITY_INIT;

    Parameters:
      | *[in, out]* **m** mat2 (src, dest)

    .. note:: Mathematical explanation

    .. csv-table:: mat2 **(m)**
        :header: "", "column 1", "column 2"

        "row 1", "m00", "m10"
        "row 2", "m01", "m11"

    .. csv-table:: mat2 **(m)**
        :header: "", "column 1", "column 2"

        "row 1", "1.00", "0.00"
        "row 2", "0.00", "1.00"

    .. note:: Example

    .. code-block:: c

        mat2 m = {{3.00,4.00},{7.00,8.00}};
        glm_mat2_identity(m);

    .. csv-table:: mat2 **(m)**
        :header: "", "column 1", "column 2"

        "row 1", "3.00", "7.00"
        "row 2", "4.00", "8.00"

    .. csv-table:: mat2 **(m)**
        :header: "", "column 1", "column 2"

        "row 1", "1.00", "0.00"
        "row 2", "0.00", "1.00"

.. c:function:: void glm_mat2_identity_array(mat2 * __restrict mats, size_t count)

    Given an array of mat2's **(mats)** make each matrix an identity matrix.

    Parameters:
      | *[in, out]* **mats** Array of mat2's (must be aligned (16/32) if alignment is not disabled)
      | *[in]* **count** Array size of ``mats`` or number of matrices

    .. note:: Mathematical explanation

    .. csv-table:: mat2 **(mats[index])**
        :header: "", "column 1", "column 2"

        "row 1", "m00", "m10"
        "row 2", "m01", "m11"

    .. csv-table:: mat2 **(mats[index])**
        :header: "", "column 1", "column 2"

        "row 1", "1.00", "0.00"
        "row 2", "0.00", "1.00"

    .. note:: Example

    .. code-block:: c

        size_t count = 3;

        mat2 matrices[count] = {
            {{1.00,2.00},{5.00,6.00}},
            {{3.00,4.00},{7.00,8.00}},
            {{5.00,6.00},{9.00,10.00}},
        };

        glm_mat2_identity_array(matrices, count);

    .. csv-table:: mat2 **(mats[0])** Before
        :header: "", "column 1", "column 2"

        "row 1", "1.00", "5.00"
        "row 2", "2.00", "6.00"

    .. csv-table:: mat2 **(mats[0])** After
        :header: "", "column 1", "column 2"

        "row 1", "1.00", "0.00"
        "row 2", "0.00", "1.00"

    .. csv-table:: mat2 **(mats[1])** Before
        :header: "", "column 1", "column 2"

        "row 1", "3.00", "7.00"
        "row 2", "4.00", "8.00"

    .. csv-table:: mat2 **(mats[1])** After
        :header: "", "column 1", "column 2"

        "row 1", "1.00", "0.00"
        "row 2", "0.00", "1.00"

    .. csv-table:: mat2 **(mats[2])** Before
        :header: "", "column 1", "column 2"

        "row 1", "5.00", "9.00"
        "row 2", "6.00", "10.00"

    .. csv-table:: mat2 **(mats[2])** After
        :header: "", "column 1", "column 2"

        "row 1", "1.00", "0.00"
        "row 2", "0.00", "1.00"

.. c:function:: void glm_mat2_zero(mat2 m)

    Zero out the mat2 (m).

    Parameters:
      | *[in, out]* **m** mat2 (src, dest)

    .. note:: Mathematical explanation

    .. csv-table:: mat2 **(m)**
        :header: "", "column 1", "column 2"

        "row 1", "m00", "m10"
        "row 2", "m01", "m11"

    .. csv-table:: mat2 **(m)**
        :header: "", "column 1", "column 2"

        "row 1", "0.00", "0.00"
        "row 2", "0.00", "0.00"

    .. note:: Example

    .. code-block:: c

        mat2 m = {{19.00,5.00},{2.00,4.00}};
        glm_mat2_zero(m);

    .. csv-table:: mat2 **(m)** Before
        :header: "", "column 1", "column 2"

        "row 1", "19.00", "2.00"
        "row 2", "5.00", "4.00"

    .. csv-table:: mat2 **(m)** After
        :header: "", "column 1", "column 2"

        "row 1", "0.00", "0.00"
        "row 2", "0.00", "0.00"

.. c:function:: void glm_mat2_mul(mat2 m1, mat2 m2, mat2 dest)

    | Multiply mat2 (m1) by mat2 (m2) and store in mat2 (dest).
    |
    | m1, m2 and dest matrices can be same matrix, it is possible to write this:

    .. code-block:: c

       mat2 m = GLM_MAT2_IDENTITY_INIT;
       glm_mat2_mul(m, m, m);

    Parameters:
      | *[in]*  **m1**   mat2 (left)
      | *[in]*  **m2**   mat2 (right)
      | *[out]* **dest** destination (result, mat2)

    .. note:: Mathematical explanation

    .. csv-table:: mat2 **(m1)**
        :header: "", "column 1", "column 2"

        "row 1", "a00", "a10"
        "row 2", "a01", "a11"

    .. csv-table:: mat2 **(m2)**
        :header: "", "column 1", "column 2"

        "row 1", "b00", "b10"
        "row 2", "b01", "b11"

    .. csv-table:: mat2 **(dest)**
        :header: "", "column 1", "column 2"

        "row 1", "a00 * b00 + a10 * b01", "a00 * b10 + a10 * b11"
        "row 2", "a01 * b00 + a11 * b01", "a01 * b10 + a11 * b11"

    .. note:: Example

    .. code-block:: c

        mat2 m = {{19.00,5.00},{2.00,4.00}};
        glm_mat2_mul(m, m, m);

    .. csv-table:: mat2 **(m1)**
        :header: "", "column 1", "column 2"

        "row 1", "19.00", "2.00"
        "row 2", "5.00", "4.00"

    .. csv-table:: mat2 **(m2)**
        :header: "", "column 1", "column 2"

        "row 1", "19.00", "2.00"
        "row 2", "5.00", "4.00"

    .. csv-table:: mat2 **(dest)**
        :header: "", "column 1", "column 2"

        "row 1", "**371.00** = 19.00 * 19.00 + 2.00 * 5.00", "**46.00** = 19.00 * 2.00 + 2.00 * 4.00"
        "row 2", "**115.00** = 5.00 * 19.00 + 4.00 * 5.00", "**18.00** = 5.00 * 2.00 + 4.00 * 4.00"

.. c:function:: void glm_mat2_mulv(mat2 m, vec2 v, vec2 dest)

    Multiply mat2 (m) by vec2 (v) and store in vec2 (dest).

    Parameters:
      | *[in]*  **m**    mat2 (left)
      | *[in]*  **v**    vec2 (right, column vector)
      | *[out]* **dest** destination (result, column vector)

    .. note:: Mathematical explanation

    .. csv-table:: mat2 **(m)**
        :header: "", "column 1", "column 2"

        "row 1", "m00", "m10"
        "row 2", "m01", "m11"

    .. csv-table:: column vec2 (1x2) **(v)**
        :header: "", "column 1"

        "row 1", "v0"
        "row 2", "v1"

    .. csv-table:: column vec2 (1x2) **(dest)**
        :header: "", "column 1"

        "row 1", "m00 * v0 + m10 * v1"
        "row 2", "m01 * v0 + m11 * v1"

    .. note:: Example

    .. code-block:: c

        vec2 dest;
        vec2 v = {33.00,55.00};
        mat2 m = {{1.00,2.00},{3.00,4.00}};
        glm_mat2_mulv(m, v, dest);

    .. csv-table:: mat2 **(m)**
        :header: "", "column 1", "column 2"

        "row 1", "1.00", "3.00"
        "row 2", "2.00", "4.00"

    .. csv-table:: column vec2 **(v)**
        :header: "", "column 1"

        "row 1", "33.00"
        "row 2", "55.00"

    .. csv-table:: vec2 **(dest)** Result
        :header: "", "column 1"

        "row 1", "**198.00** = 1.00 * 33.00 + 3.00 * 55.00"
        "row 2", "**286.00** = 2.00 * 33.00 + 4.00 * 55.00"

.. c:function:: void glm_mat2_transpose_to(mat2 mat, mat2 dest)

    Transpose mat2 (mat) and store in mat2 (dest).

    Parameters:
      | *[in]*  **mat**  mat2 (left,src)
      | *[out]* **dest** destination (result, mat2)

    .. note:: Mathematical explanation

    .. csv-table:: mat2 **(mat)**
        :header: "", "column 1", "column 2"

        "row 1", "m00", "m10"
        "row 2", "m01", "m11"

    .. csv-table:: mat2 **(dest)**
        :header: "", "column 1", "column 2"

        "row 1", "m00", "m01"
        "row 2", "m10", "m11"

    .. note:: Example

    .. code-block:: c

        mat2 mat = {{1.00,2.00},{3.00,4.00}};
        mat2 dest = GLM_MAT2_ZERO_INIT;
        glm_mat2_transpose_to(mat, dest);

    .. csv-table:: mat2 **(mat)**
        :header: "", "column 1", "column 2"

        "row 1", "1.00", "3.00"
        "row 2", "2.00", "4.00"

    .. csv-table:: mat2 **(dest)** Before
        :header: "", "column 1", "column 2"

        "row 1", "0.00", "0.00"
        "row 2", "0.00", "0.00"

    .. csv-table:: mat2 **(dest)** After
        :header: "", "column 1", "column 2"

        "row 1", "1.00", "2.00"
        "row 2", "3.00", "4.00"

.. c:function:: void glm_mat2_transpose(mat2 m)

    Transpose mat2 (m) and store result in the same matrix.

    Parameters:
      | *[in, out]* **m** mat2 (src, dest)

    .. note:: Mathematical explanation

    .. csv-table:: mat2 **(m)** src
        :header: "", "column 1", "column 2"

        "row 1", "m00", "m10"
        "row 2", "m01", "m11"

    .. csv-table:: mat2 **(m)** dest
        :header: "", "column 1", "column 2"

        "row 1", "m00", "m01"
        "row 2", "m10", "m11"

    .. note:: Example

    .. code-block:: c

        mat2 m = {{1.00,2.00},{3.00,4.00}};
        glm_mat2_transpose(m);

    .. csv-table:: mat2 **(m)** Before
        :header: "", "column 1", "column 2"

        "row 1", "1.00", "3.00"
        "row 2", "2.00", "4.00"

    .. csv-table:: mat2 **(m)** After
        :header: "", "column 1", "column 2"

        "row 1", "1.00", "2.00"
        "row 2", "3.00", "4.00"

.. c:function:: void glm_mat2_scale(mat2 m, float s)

    Multiply mat2 (m) by scalar constant (s).

    Parameters:
      | *[in, out]* **m** mat2 (src, dest)
      | *[in]*      **s** float (scalar)

    .. note:: Mathematical explanation

    .. csv-table:: mat2 **(m)**
        :header: "", "column 1", "column 2"

        "row 1", "m00 * s", "m10 * s"
        "row 2", "m01 * s", "m11 * s"

    .. note:: Example

    .. code-block:: c

        float s = 3.00f;
        mat2 m = {{1.00,2.00},{3.00,4.00}};
        glm_mat2_scale(m, s);

    .. csv-table:: mat2 **(m)** Before
        :header: "", "column 1", "column 2"

        "row 1", "1.00", "3.00"
        "row 2", "2.00", "4.00"

    .. csv-table:: mat2 **(m)** After
        :header: "", "column 1", "column 2"

        "row 1", "**3.00** = 1.00 * 3.00", "**9.00** = 3.00 * 3.00"
        "row 2", "**6.00** = 2.00 * 3.00", "**12.00** = 4.00 * 3.00"

.. c:function:: void glm_mat2_inv(mat2 mat, mat2 dest)

    Inverse mat2 (mat) and store in mat2 (dest).

    Parameters:
      | *[in]*  **mat**  mat2 (left,src)
      | *[out]* **dest** destination (result, inverse mat2)

    .. note:: Mathematical explanation

    .. csv-table:: mat2 **(mat)**
        :header: "", "column 1", "column 2"

        "row 1", "m00", "m10"
        "row 2", "m01", "m11"

    .. list-table:: mat2 **(dest)**
        :header-rows: 1

        * -
          - column 1
          - column 2
        * - row 1
          - m11 * (1.0f / (m00 * m11 - m01 * m10))
          - -m10 * (1.0f / (m00 * m11 - m01 * m10))
        * - row 2
          - -m01 * (1.0f / (m00 * m11 - m01 * m10))
          - m00 * (1.0f / (m00 * m11 - m01 * m10))

    .. note:: Example

    .. code-block:: c

        mat2 dest = GLM_MAT2_ZERO_INIT;
        mat2 mat = {{1.00,2.00},{3.00,4.00}};
        glm_mat2_inv(mat, dest);

    .. csv-table:: mat2 **(mat)** Before
        :header: "", "column 1", "column 2"

        "row 1", "1.00", "3.00"
        "row 2", "2.00", "4.00"

    .. list-table:: mat2 **(dest)** After
        :header-rows: 1

        * -
          - column 1
          - column 2
        * - row 1
          - **-2.00** = 4.00 * (1.00 / (1.00 * 4.00 - 2.00 * 3.00))
          - **1.50** = -3.00 * (1.00 / (1.00 * 4.00 - 2.00 * 3.00))
        * - row 2
          - **1.00** = -2.00 * (1.00 / (1.00 * 4.00 - 2.00 * 3.00))
          - **-0.50** = 1.00 * (1.00 / (1.00 * 4.00 - 2.00 * 3.00))

.. c:function:: void glm_mat2_swap_col(mat2 mat, int col1, int col2)

    Swap two columns in mat2 (mat) and store in same matrix.

    Parameters:
      | *[in, out]* **mat**   mat2 (src, dest)
      | *[in]*       **col1** Column 1 array index
      | *[in]*       **col2** Column 2 array index

    .. note:: Mathematical explanation

    .. csv-table:: mat2 **(mat)** Before
        :header: "", "column 1", "column 2"

        "row 1", "m00", "m10"
        "row 2", "m01", "m11"

    .. code-block:: c

        glm_mat2_swap_col(mat, 0, 1);

    .. csv-table:: mat2 **(mat)** After
        :header: "", "column 1", "column 2"

        "row 1", "m10", "m00"
        "row 2", "m11", "m01"

    .. note:: Example

    .. code-block:: c

        mat2 mat = {{76.00,5.00},{3.00,6.00}};
        glm_mat2_swap_col(mat, 0, 1);

    .. csv-table:: mat2 **(mat)** Before
        :header: "", "column 1", "column 2"

        "row 1", "76.00", "3.00"
        "row 2", "5.00", "6.00"

    .. csv-table:: mat2 **(mat)** After
        :header: "", "column 1", "column 2"

        "row 1", "3.00", "76.00"
        "row 2", "6.00", "5.00"

.. c:function:: void glm_mat2_swap_row(mat2 mat, int row1, int row2)

    Swap two rows in mat2 (mat) and store in same matrix.

    Parameters:
      | *[in, out]* **mat**  mat2 (src, dest)
      | *[in]*      **row1** Row 1 array index
      | *[in]*      **row2** Row 2 array index

    .. note:: Mathematical explanation

    .. csv-table:: mat2 **(mat)** Before
        :header: "", "column 1", "column 2"

        "row 1", "m00", "m10"
        "row 2", "m01", "m11"

    .. code-block:: c

        glm_mat2_swap_row(mat, 0, 1);

    .. csv-table:: mat2 **(mat)** After
        :header: "", "column 1", "column 2"

        "row 1", "m01", "m11"
        "row 2", "m00", "m10"

    .. note:: Example

    .. code-block:: c

        mat2 mat = {{76.00,5.00},{3.00,6.00}};
        glm_mat2_swap_row(mat, 0, 1);

    .. csv-table:: mat2 **(mat)** Before
        :header: "", "column 1", "column 2"

        "row 1", "76.00", "3.00"
        "row 2", "5.00", "6.00"

    .. csv-table:: mat2 **(mat)** After
        :header: "", "column 1", "column 2"

        "row 1", "5.00", "6.00"
        "row 2", "76.00", "3.00"

.. c:function:: float glm_mat2_det(mat2 m)

    Returns mat2 determinant.

    Parameters:
      | *[in]* **m** mat2 (src)

    Returns:
      | mat2 determinant (float)

    .. note:: Mathematical explanation

    .. csv-table:: mat2 **(m)**
        :header: "", "column 1", "column 2"

        "row 1", "m00", "m10"
        "row 2", "m01", "m11"

    .. code-block:: c

        m00 * m11 - m10 * m01;

    .. note:: Example

    .. code-block:: c

        mat2 m = {{76.00,5.00},{3.00,6.00}};
        glm_mat2_det(m);

    .. csv-table:: mat2 **(m)**
        :header: "", "column 1", "column 2"

        "row 1", "76.00", "3.00"
        "row 2", "5.00", "6.00"

    .. code-block:: c

        441.00 = 76.00 * 6.00 - 3.00 * 5.00;

.. c:function:: void glm_mat2_trace(mat2 m)

    | Returns trace of matrix. Which is:
    |
    | The sum of the elements on the main diagonal from
    | upper left corner to the bottom right corner.

    Parameters:
      | *[in]* **m** mat2 (src)

    Returns:
      | mat2 trace (float)

    .. note:: Mathematical explanation

    .. csv-table:: mat2 **(m)**
        :header: "", "column 1", "column 2"

        "row 1", "m00", "m10"
        "row 2", "m01", "m11"

    .. code-block:: c

        m00 + m11;

    .. note:: Example

    .. code-block:: c

        mat2 m = {{76.00,5.00},{3.00,6.00}};
        glm_mat2_trace(m);

    .. csv-table:: mat2 **(m)**
        :header: "", "column 1", "column 2"

        "row 1", "76.00", "3.00"
        "row 2", "5.00", "6.00"

    .. code-block:: c

        82.00 = 76.00 + 6.00;

.. c:function:: float glm_mat2_rmc(vec2 r, mat2 m, vec2 c)

    | Helper for  R (row vector) * M (matrix) * C (column vector)

    | **rmc** stands for **Row** * **Matrix** * **Column**

    | the result is scalar because M * C = ResC (1x2, column vector),
    | then if you take the dot_product(R (2x1), ResC (1x2)) = scalar value.

    Parameters:
      | *[in]* **r** vec2 (2x1, row vector)
      | *[in]* **m** mat2 (2x2, matrix)
      | *[in]* **c** vec2 (1x2, column vector)

    Returns:
      | Scalar value (float, 1x1)

    .. note:: Mathematical explanation

    .. csv-table:: row vec2 (2x1) **(r)**
        :header: "", "column 1", "column 2"

        "row 1", "a00", "a10"

    .. csv-table:: mat2 **(m)**
        :header: "", "column 1", "column 2"

        "row 1", "b00", "b10"
        "row 2", "b01", "b11"

    .. csv-table:: column vec2 (1x2) **(c)**
        :header: "", "column 1"

        "row 1", "c00"
        "row 2", "c01"

    .. code-block:: c

        M * C = C (column vector)
        dot_product(R, C)

    .. csv-table:: column vec2 (1x2) **(C)**
        :header: "", "column 1"

        "row 1", "b00 * c00 + b10 * c01"
        "row 2", "b01 * c00 + b11 * c01"

    .. csv-table:: float **(scalar)**
        :header: "", "column 1"

        "row 1", "a00 * (b00 * c00 + b10 * c01) + a10 * (b01 * c00 + b11 * c01)"

    .. note:: Example

    .. code-block:: c

        vec2 r = {8.00,4.00};
        vec2 c = {7.00,2.00};
        mat2 m = {{5.00,9.00},{3.00,6.00}};
        glm_mat2_rmc(r, m, c);

    .. csv-table:: row vec2 (2x1) **(r)**
        :header: "", "column 1", "column 2"

        "row 1", "8.00", "4.00"

    .. csv-table:: mat2 **(m)**
        :header: "", "column 1", "column 2"

        "row 1", "5.00", "3.00"
        "row 2", "9.00", "6.00"

    .. csv-table:: column vec2 (1x2) **(c)**
        :header: "", "column 1"

        "row 1", "7.00"
        "row 2", "2.00"

    .. csv-table:: column vec2 (1x2) **(C)**
        :header: "", "column 1"

        "row 1", "**41.00** = 5.00 * 7.00 + 3.00 * 2.00"
        "row 2", "**75.00** = 9.00 * 7.00 + 6.00 * 2.00"

    .. csv-table:: float (1x1) **(scalar)**
        :header: "", "column 1"

        "row 1", "**628.00** = 8.00 * 41.00 + 4.00 * 75.00"
