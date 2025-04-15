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

1. :c:func:`glm_mat3_make`
#. :c:func:`glm_mat3_copy`
#. :c:func:`glm_mat3_identity`
#. :c:func:`glm_mat3_identity_array`
#. :c:func:`glm_mat3_zero`
#. :c:func:`glm_mat3_mul`
#. :c:func:`glm_mat3_mulv`
#. :c:func:`glm_mat3_transpose_to`
#. :c:func:`glm_mat3_transpose`
#. :c:func:`glm_mat3_scale`
#. :c:func:`glm_mat3_inv`
#. :c:func:`glm_mat3_swap_col`
#. :c:func:`glm_mat3_swap_row`
#. :c:func:`glm_mat3_quat`
#. :c:func:`glm_mat3_textrans`
#. :c:func:`glm_mat3_det`
#. :c:func:`glm_mat3_trace`
#. :c:func:`glm_mat3_rmc`

Represented
~~~~~~~~~~~

.. csv-table:: mat3x3
   :header: "", "column 1", "column 2", "column 3"

   "row 1", "m00", "m10", "m20"
   "row 2", "m01", "m11", "m21"
   "row 3", "m02", "m12", "m22"

Functions documentation
~~~~~~~~~~~~~~~~~~~~~~~

.. c:function:: void glm_mat3_make(const float * __restrict src, mat3 dest)

    Create mat3 (dest) from pointer (src).

    .. note:: **@src** must contain at least 9 elements.

    Parameters:
      | *[in]*  **src**  pointer to an array of floats (left)
      | *[out]* **dest** destination (result, mat3)

    .. note:: Mathematical explanation

    .. csv-table:: float array (1x9) **(src)**
        :header: "", "column 1"

        "row 1", "v0"
        "row 2", "v1"
        "row 3", "v2"
        "row 4", "v3"
        "row 5", "v4"
        "row 6", "v5"
        "row 7", "v6"
        "row 8", "v7"
        "row 9", "v8"

    .. csv-table:: mat3 **(dest)**
        :header: "", "column 1", "column 2", "column 3"

        "row 1", "v0", "v3", "v6"
        "row 2", "v1", "v4", "v7"
        "row 3", "v2", "v5", "v8"

    .. note:: Example

    .. code-block:: c

        float src[9] = {
            1.00, 5.00, 8.00,
            11.00, 42.00, 33.00,
            95.00, 59.00, 88.00,
        };
        mat3 dest = GLM_MAT3_ZERO_INIT;
        glm_mat3_make(src, dest);

    .. csv-table:: float array (1x9) **(src)**
        :header: "", "column 1"

        "row 1", "1.00"
        "row 2", "5.00"
        "row 3", "8.00"
        "row 4", "11.00"
        "row 5", "42.00"
        "row 6", "33.00"
        "row 7", "95.00"
        "row 8", "59.00"
        "row 9", "88.00"

    .. csv-table:: mat3 **(dest)** Before
        :header: "", "column 1", "column 2", "column 3"

        "row 1", "0.00", "0.00", "0.00"
        "row 2", "0.00", "0.00", "0.00"
        "row 3", "0.00", "0.00", "0.00"

    .. csv-table:: mat3 **(dest)** After
        :header: "", "column 1", "column 2", "column 3"

        "row 1", "1.00", "11.00", "95.00"
        "row 2", "5.00", "42.00", "59.00"
        "row 3", "8.00", "33.00", "88.00"

.. c:function:: void glm_mat3_copy(mat3 mat, mat3 dest)

    Copy mat3 (mat) to mat3 (dest).

    Parameters:
      | *[in]*  **mat**  mat3 (left, src)
      | *[out]* **dest** destination (result, mat3)

    .. note:: Mathematical explanation

    .. csv-table:: mat3 **(mat)**
        :header: "", "column 1", "column 2", "column 3"

        "row 1", "m00", "m10", "m20"
        "row 2", "m01", "m11", "m21"
        "row 3", "m02", "m12", "m22"

    .. csv-table:: mat3 **(dest)**
        :header: "", "column 1", "column 2", "column 3"

        "row 1", "m00", "m10", "m20"
        "row 2", "m01", "m11", "m21"
        "row 3", "m02", "m12", "m22"

    .. note:: Example

    .. code-block:: c

        mat3 mat = {
            {3.00,4.00,5.00},
            {7.00,8.00,9.00},
            {17.00,18.00,19.00},
        };
        mat3 dest = GLM_MAT2_ZERO_INIT;
        glm_mat3_copy(mat, dest);

    .. csv-table:: mat3 **(mat)**
        :header: "", "column 1", "column 2", "column 3"

        "row 1", "3.00", "4.00", "5.00"
        "row 2", "7.00", "8.00", "9.00"
        "row 3", "17.00", "18.00", "19.00"

    .. csv-table:: mat3 **(dest)** Before
        :header: "", "column 1", "column 2", "column 3"

        "row 1", "0.00", "0.00", "0.00"
        "row 2", "0.00", "0.00", "0.00"
        "row 3", "0.00", "0.00", "0.00"

    .. csv-table:: mat3 **(dest)** After
        :header: "", "column 1", "column 2", "column 3"

        "row 1", "3.00", "4.00", "5.00"
        "row 2", "7.00", "8.00", "9.00"
        "row 3", "17.00", "18.00", "19.00"

.. c:function:: void glm_mat3_identity(mat3 m)

    | Copy a mat3 identity to mat3 **(m)**, or makes mat3 **(m)** an identity.
    |
    | The same thing may be achieved with either of bellow methods,
    | but it is more easy to do that with this func especially for members
    | e.g. ``glm_mat3_identity(aStruct->aMatrix);``.

    .. code-block:: c

        glm_mat3_copy(GLM_MAT3_IDENTITY, m);

        // or
        mat3 mat = GLM_MAT3_IDENTITY_INIT;

    Parameters:
      | *[in, out]* **m** mat3 (src, dest)

    .. note:: Mathematical explanation

    .. csv-table:: mat3 **(m)**
        :header: "", "column 1", "column 2", "column 3"

        "row 1", "m00", "m10", "m20"
        "row 2", "m01", "m11", "m21"
        "row 3", "m02", "m12", "m22"

    .. csv-table:: mat3 **(m)**
        :header: "", "column 1", "column 2", "column 3"

        "row 1", "1.00", "0.00", "0.00"
        "row 2", "0.00", "1.00", "0.00"
        "row 3", "0.00", "0.00", "1.00"

    .. note:: Example

    .. code-block:: c

        mat3 m = {
            {3.00,4.00,5.00},
            {7.00,8.00,9.00},
            {17.00,18.00,19.00},
        };
        glm_mat3_identity(m);

    .. csv-table:: mat3 **(m)**
        :header: "", "column 1", "column 2", "column 3"

        "row 1", "3.00", "4.00", "5.00"
        "row 2", "7.00", "8.00", "9.00"
        "row 3", "17.00", "18.00", "19.00"

    .. csv-table:: mat3 **(m)**
        :header: "", "column 1", "column 2", "column 3"

        "row 1", "1.00", "0.00", "0.00"
        "row 2", "0.00", "1.00", "0.00"
        "row 3", "0.00", "0.00", "1.00"

.. c:function:: void glm_mat3_identity_array(mat3 * __restrict mats, size_t count)

    Given an array of mat3's **(mats)** make each matrix an identity matrix.

    Parameters:
      | *[in, out]* **mats** Array of mat3's (must be aligned (16/32) if alignment is not disabled)
      | *[in]* **count** Array size of ``mats`` or number of matrices

    .. note:: Mathematical explanation

    .. csv-table:: mat3 **(mats[index])**
        :header: "", "column 1", "column 2", "column 3"

        "row 1", "m00", "m10", "m20"
        "row 2", "m01", "m11", "m21"
	"row 3", "m02", "m12", "m22"

    .. csv-table:: mat3 **(mats[index])**
        :header: "", "column 1", "column 2", "column 3"

        "row 1", "1.00", "0.00", "0.00"
        "row 2", "0.00", "1.00", "0.00"
        "row 3", "0.00", "0.00", "1.00"

    .. note:: Example

    .. code-block:: c

        size_t count = 3;
        mat3 matrices[count] = {
            {{1.00,2.00,3.00},{10.00,11.00,12.00},{19.00,20.00,21.00}},
            {{4.00,5.00,6.00},{13.00,14.00,15.00},{22.00,23.00,24.00}},
            {{7.00,8.00,9.00},{16.00,17.00,18.00},{25.00,26.00,27.00}},
        };
        glm_mat3_identity_array(matrices, count);

    .. csv-table:: mat3 **(mats[0])** Before
        :header: "", "column 1", "column 2", "column 3"

        "row 1", "1.00", "10.00", "19.00"
        "row 2", "2.00", "11.00", "20.00"
        "row 3", "3.00", "12.00", "21.00"

    .. csv-table:: mat3 **(mats[0])** After
        :header: "", "column 1", "column 2", "column 3"

        "row 1", "1.00", "0.00", "0.00"
        "row 2", "0.00", "1.00", "0.00"
        "row 3", "0.00", "0.00", "1.00"

    .. csv-table:: mat3 **(mats[1])** Before
        :header: "", "column 1", "column 2", "column 3"

        "row 1", "4.00", "13.00", "22.00"
        "row 2", "5.00", "14.00", "23.00"
        "row 3", "6.00", "15.00", "24.00"

    .. csv-table:: mat3 **(mats[1])** After
        :header: "", "column 1", "column 2", "column 3"

        "row 1", "1.00", "0.00", "0.00"
        "row 2", "0.00", "1.00", "0.00"
        "row 3", "0.00", "0.00", "1.00"

    .. csv-table:: mat3 **(mats[2])** Before
        :header: "", "column 1", "column 2", "column 3"

        "row 1", "7.00", "16.00", "25.00"
        "row 2", "8.00", "17.00", "26.00"
        "row 3", "9.00", "18.00", "27.00"

    .. csv-table:: mat3 **(mats[2])** After
        :header: "", "column 1", "column 2", "column 3"

        "row 1", "1.00", "0.00", "0.00"
        "row 2", "0.00", "1.00", "0.00"
        "row 3", "0.00", "0.00", "1.00"

.. c:function:: void glm_mat3_zero(mat3 m)

    Zero out the mat3 (m).

    Parameters:
      | *[in, out]* **m** mat3 (src, dest)

    .. note:: Mathematical explanation

    .. csv-table:: mat3 **(m)**
        :header: "", "column 1", "column 2", "column 3"

        "row 1", "m00", "m10", "m20"
        "row 2", "m01", "m11", "m21"
        "row 3", "m02", "m12", "m22"

    .. csv-table:: mat3 **(m)**
        :header: "", "column 1", "column 2", "column 3"

        "row 1", "0.00", "0.00", "0.00"
        "row 2", "0.00", "0.00", "0.00"
        "row 3", "0.00", "0.00", "0.00"

    .. note:: Example

    .. code-block:: c

        mat3 m = {
            {19.00,5.00,7.00},
            {2.00,4.00,6.00},
            {12.00,24.00,54.00},
        };
        glm_mat3_zero(m);

    .. csv-table:: mat3 **(m)** Before
        :header: "", "column 1", "column 2", "column 3"

        "row 1", "19.00", "2.00", "12.00"
        "row 2", "5.00", "4.00", "24.00"
        "row 3", "7.00", "6.00", "54.00"

    .. csv-table:: mat3 **(m)** After
        :header: "", "column 1", "column 2", "column 3"

        "row 1", "0.00", "0.00", "0.00"
        "row 2", "0.00", "0.00", "0.00"
        "row 3", "0.00", "0.00", "0.00"

.. c:function:: void glm_mat3_mul(mat3 m1, mat3 m2, mat3 dest)

    Multiply mat3 (m1) by mat3 (m2) and store in mat3 (dest).

    m1, m2 and dest matrices can be same matrix, it is possible to write this:

    .. code-block:: c

       mat3 m = GLM_MAT3_IDENTITY_INIT;
       glm_mat3_mul(m, m, m);

    Parameters:
      | *[in]*  **m1**   mat3 (left)
      | *[in]*  **m2**   mat3 (right)
      | *[out]* **dest** destination (result, mat3)

    .. note:: Mathematical explanation

    .. csv-table:: mat3 **(m1)**
        :header: "", "column 1", "column 2", "column 3"

        "row 1", "a00", "a10", "a20"
        "row 2", "a01", "a11", "a21"
        "row 3", "a02", "a12", "a22"

    .. csv-table:: mat3 **(m2)**
        :header: "", "column 1", "column 2", "column 3"

        "row 1", "b00", "b10", "b20"
        "row 2", "b01", "b11", "b21"
        "row 3", "b02", "b12", "b22"

    .. list-table:: mat3 **(dest)**
        :header-rows: 1

        * -
          - column 1
          - column 2
          - column 3
        * - row 1
          - a00 * b00 + a10 * b01 + a20 * b02
          - a00 * b10 + a10 * b11 + a20 * b12
          - a00 * b20 + a10 * b21 + a20 * b22
        * - row 2
          - a01 * b00 + a11 * b01 + a21 * b02
          - a01 * b10 + a11 * b11 + a21 * b12
          - a01 * b20 + a11 * b21 + a21 * b22
        * - row 3
          - a02 * b00 + a12 * b01 + a22 * b02
          - a02 * b10 + a12 * b11 + a22 * b12
          - a02 * b20 + a12 * b21 + a22 * b22

    .. note:: Example

    .. code-block:: c

        mat3 m = {
            {19.00,5.00,6.00},
            {2.00,4.00,8.00},
            {1.00,3.00,7.00},
        };
        glm_mat3_mul(m, m, m);

    .. csv-table:: mat3 **(m1)**
        :header: "", "column 1", "column 2", "column 3"

        "row 1", "19.00", "2.00", "1.00"
        "row 2", "5.00", "4.00", "3.00"
        "row 3", "6.00", "8.00", "7.00"

    .. csv-table:: mat3 **(m2)**
        :header: "", "column 1", "column 2", "column 3"

        "row 1", "19.00", "2.00", "1.00"
        "row 2", "5.00", "4.00", "3.00"
        "row 3", "6.00", "8.00", "7.00"

    .. list-table:: mat3 **(dest)**
        :header-rows: 1

        * -
          - column 1
          - column 2
          - column 3
        * - row 1
          - **377.00** = 19.00 * 19.00 + 2.00 * 5.00 + 1.00 * 6.00
          - **54.00** = 19.00 * 2.00 + 2.00 * 4.00 + 1.00 * 8.00
          - **32.00** = 19.00 * 1.00 + 2.00 * 3.00 + 1.00 * 7.00
        * - row 2
          - **133.00** = 5.00 * 19.00 + 4.00 * 5.00 + 3.00 * 6.00
          - **50.00** = 5.00 * 2.00 + 4.00 * 4.00 + 3.00 * 8.00
          - **38.00** = 5.00 * 1.00 + 4.00 * 3.00 + 3.00 * 7.00
        * - row 3
          - **196.00** = 6.00 * 19.00 + 8.00 * 5.00 + 7.00 * 6.00
          - **100.00** = 6.00 * 2.00 + 8.00 * 4.00 + 7.00 * 8.00
          - **79.00** = 6.00 * 1.00 + 8.00 * 3.00 + 7.00 * 7.00

.. c:function:: void glm_mat3_mulv(mat3 m, vec3 v, vec3 dest)

    Multiply mat3 (m) by vec3 (v) and store in vec3 (dest).

    Parameters:
      | *[in]*  **m**    mat3 (left)
      | *[in]*  **v**    vec3 (right, column vector)
      | *[out]* **dest** destination (result, column vector)

    .. note:: Mathematical explanation

    .. csv-table:: mat3 **(m)**
        :header: "", "column 1", "column 2", "column 3"

        "row 1", "m00", "m10", "m20"
        "row 2", "m01", "m11", "m21"
        "row 3", "m02", "m12", "m22"

    .. csv-table:: column vec3 (1x3) **(v)**
        :header: "", "column 1"

        "row 1", "v0"
        "row 2", "v1"
        "row 3", "v2"

    .. csv-table:: column vec3 (1x3) **(dest)**
        :header: "", "column 1"

        "row 1", "m00 * v0 + m10 * v1 + m20 * v2"
        "row 2", "m01 * v0 + m11 * v1 + m21 * v2"
        "row 3", "m02 * v0 + m12 * v1 + m22 * v2"

    .. note:: Example

    .. code-block:: c

        vec3 dest;
        vec3 v = {33.00,55.00,77.00};
        mat3 m = {
            {1.00,2.00,3.00},
            {4.00,5.00,6.00},
            {7.00,8.00,9.00},
        };
        glm_mat3_mulv(m, v, dest);

    .. csv-table:: mat3 **(m)**
        :header: "", "column 1", "column 2", "column 3"

        "row 1", "1.00", "4.00", "7.00"
        "row 2", "2.00", "5.00", "8.00"
        "row 3", "3.00", "6.00", "9.00"

    .. csv-table:: column vec3 **(v)**
        :header: "", "column 1"

        "row 1", "33.00"
        "row 2", "55.00"
        "row 3", "77.00"

    .. csv-table:: vec2 **(dest)** Result
        :header: "", "column 1"

        "row 1", "**792.00** = 1.00 * 33.00 + 4.00 * 55.00 + 7.00 * 77.00"
        "row 2", "**957.00** = 2.00 * 33.00 + 5.00 * 55.00 + 8.00 * 77.00"
        "row 3", "**1122.00** = 3.00 * 33.00 + 6.00 * 55.00 + 9.00 * 77.00"

.. c:function:: void glm_mat3_transpose_to(mat3 mat, mat3 dest)

    Transpose mat3 (mat) and store in mat3 (dest).

    Parameters:
      | *[in]*  **mat**  mat3 (left,src)
      | *[out]* **dest** destination (result, mat3)

    .. note:: Mathematical explanation

    .. csv-table:: mat3 **(mat)**
        :header: "", "column 1", "column 2", "column 3"

        "row 1", "m00", "m10", "m20"
        "row 2", "m01", "m11", "m21"
        "row 3", "m02", "m12", "m22"

    .. csv-table:: mat3 **(dest)**
        :header: "", "column 1", "column 2", "column 3"

        "row 1", "m00", "m01", "m02"
        "row 2", "m10", "m11", "m12"
        "row 3", "m20", "m21", "m22"

    .. note:: Example

    .. code-block:: c

        mat3 mat = {
            {1.00,2.00,3.00},
            {4.00,5.00,6.00},
            {7.00,8.00,9.00},
        };
        mat3 dest = GLM_MAT3_ZERO_INIT;
        glm_mat3_transpose_to(mat, dest);

    .. csv-table:: mat3 **(mat)**
        :header: "", "column 1", "column 2", "column 3"

        "row 1", "1.00", "4.00", "7.00"
        "row 2", "2.00", "5.00", "8.00"
        "row 3", "3.00", "6.00", "9.00"

    .. csv-table:: mat3 **(dest)** Before
        :header: "", "column 1", "column 2", "column 3"

        "row 1", "0.00", "0.00", "0.00"
        "row 2", "0.00", "0.00", "0.00"
        "row 3", "0.00", "0.00", "0.00"

    .. csv-table:: mat3 **(dest)** After
        :header: "", "column 1", "column 2", "column 3"

        "row 1", "1.00", "2.00", "3.00"
        "row 2", "4.00", "5.00", "6.00"
        "row 2", "7.00", "8.00", "9.00"

.. c:function:: void glm_mat3_transpose(mat3 m)

    Transpose mat3 (m) and store result in the same matrix.

    Parameters:
      | *[in, out]* **m** mat3 (src, dest)

    .. note:: Mathematical explanation

    .. csv-table:: mat3 **(m)** src
        :header: "", "column 1", "column 2", "column 3"

        "row 1", "m00", "m10", "m20"
        "row 2", "m01", "m11", "m21"
        "row 2", "m02", "m12", "m22"

    .. csv-table:: mat3 **(m)** dest
        :header: "", "column 1", "column 2", "column 3"

        "row 1", "m00", "m01", "m02"
        "row 2", "m10", "m11", "m12"
        "row 3", "m20", "m21", "m22"

    .. note:: Example

    .. code-block:: c

        mat3 mat = {
            {1.00,2.00,3.00},
            {4.00,5.00,6.00},
            {7.00,8.00,9.00},
        };
        glm_mat3_transpose(m);

    .. csv-table:: mat3 **(m)** Before
        :header: "", "column 1", "column 2", "column 3"

        "row 1", "1.00", "4.00", "7.00"
        "row 2", "2.00", "5.00", "8.00"
        "row 3", "3.00", "6.00", "9.00"

    .. csv-table:: mat3 **(m)** After
        :header: "", "column 1", "column 2", "column 3"

        "row 1", "1.00", "2.00", "3.00"
        "row 2", "4.00", "5.00", "6.00"
        "row 2", "7.00", "8.00", "9.00"

.. c:function:: void glm_mat3_scale(mat3 m, float s)

    Multiply mat3 (m) by scalar constant (s).

    Parameters:
      | *[in, out]* **m** mat3 (src, dest)
      | *[in]*      **s** float (scalar)

    .. note:: Mathematical explanation

    .. csv-table:: mat3 **(m)**
        :header: "", "column 1", "column 2", "column 3"

        "row 1", "m00 * s", "m10 * s", "m20 * s"
        "row 2", "m01 * s", "m11 * s", "m21 * s"
        "row 3", "m02 * s", "m12 * s", "m22 * s"

    .. note:: Example

    .. code-block:: c

        mat3 m = {
            {1.00,2.00,3.00},
            {4.00,5.00,6.00},
            {7.00,8.00,9.00},
        };
        float s = 3.00f;
        glm_mat3_scale(m, s);

    .. csv-table:: mat3 **(m)** Before
        :header: "", "column 1", "column 2", "column 3"

        "row 1", "1.00", "4.00", "7.00"
        "row 2", "2.00", "5.00", "8.00"
        "row 3", "3.00", "6.00", "9.00"

    .. list-table:: mat3 **(m)** After
        :header-rows: 1

        * -
          - column 1
          - column 2
          - column 3
        * - row 1
          - **3.00** = 1.00 * 3.00
          - **12.00** = 4.00 * 3.00
          - **21.00** = 7.00 * 3.00
        * - row 2
          - **6.00** = 2.00 * 3.00
          - **15.00** = 5.00 * 3.00
          - **24.00** = 8.00 * 3.00
        * - row 3
          - **9.00** = 3.00 * 3.00 
          - **18.00** = 6.00 * 3.00
          - **27.00** = 9.00 * 3.00

.. c:function:: void glm_mat3_inv(mat3 mat, mat3 dest)

    Inverse mat3 (mat) and store in mat3 (dest).

    Parameters:
      | *[in]*  **mat**  mat3 (left, src)
      | *[out]* **dest** destination (result, inverse mat3)

    .. note:: Mathematical explanation

    .. csv-table:: mat3 **(mat)**
        :header: "", "column 1", "column 2", "column 3", "", ""

        "row 1", "m00",     "m10",     "m20",     "**m00**", "**m10**"
        "row 2", "m01",     "m11",     "m21",     "**m01**", "**m11**"
        "row 3", "m02",     "m12",     "m22",     "**m02**", "**m12**"
        "     ", "**m00**", "**m10**", "**m20**", "**m00**", "**m10**"
        "     ", "**m01**", "**m11**", "**m21**", "**m01**", "**m11**"

    | For more information see `How to find the inverse of a 3 by 3 matrix (the fast way)[youtube]`_.
    | Remember we are in column major not row major. So, the way the table is populated is slightly different.
    | In terms of multiplication priority goes from m00,m01,m02,m11,...,m22.
    | May utilize the distributive law to acquire bellow equations

    .. math::

        (m00 * m11 * m22) - (m00 * m21 * m12) = m00 * (m11 * m22 - m21 * m12)

    .. list-table:: mat3 **(dest)**
        :header-rows: 1

        * -
          - column 1
          - column 2
          - column 3
        * - row 1
          - | 1.0f / (
            |    m00 * (m11 * m22 - m12 * m21) -
            |    m01 * (m10 * m22 - m20 * m12) +
            |    m02 * (m10 * m21 - m20 * m11)
            | ) * (m11 * m22 - m12 * m21)
          - | -( 1.0f / (
            |    m00 * (m11 * m22 - m12 * m21) -
            |    m01 * (m10 * m22 - m20 * m12) +
            |    m02 * (m10 * m21 - m20 * m11)
            | ) ) * (m10 * m22 - m20 * m12)
          - | 1.0f / (
            |    m00 * (m11 * m22 - m12 * m21) -
            |    m01 * (m10 * m22 - m20 * m12) +
            |    m02 * (m10 * m21 - m20 * m11)
            | ) * (m10 * m21 - m11 * m20)
        * - row 2
          - | -( 1.0f / (
            |    m00 * (m11 * m22 - m12 * m21) -
            |    m01 * (m10 * m22 - m20 * m12) +
            |    m02 * (m10 * m21 - m20 * m11)
            | ) ) * (m01 * m22 - m21 * m02)
          - | 1.0f / (
            |    m00 * (m11 * m22 - m12 * m21) -
            |    m01 * (m10 * m22 - m20 * m12) +
            |    m02 * (m10 * m21 - m20 * m11)
            | ) * (m00 * m22 - m20 * m02)
          - | -( 1.0f / (
            |    m00 * (m11 * m22 - m12 * m21) -
            |    m01 * (m10 * m22 - m20 * m12) +
            |    m02 * (m10 * m21 - m20 * m11)
            | ) ) * (m00 * m21 - m20 * m01)
        * - row 3
          - | 1.0f / (
            |    m00 * (m11 * m22 - m12 * m21) -
            |    m01 * (m10 * m22 - m20 * m12) +
            |    m02 * (m10 * m21 - m20 * m11)
            | ) * (m01 * m12 - m11 * m02)
          - | -( 1.0f / (
            |    m00 * (m11 * m22 - m12 * m21) -
            |    m01 * (m10 * m22 - m20 * m12) +
            |    m02 * (m10 * m21 - m20 * m11)
            | ) ) * (m00 * m12 - m10 * m02)
	  - | 1.0f / (
            |    m00 * (m11 * m22 - m12 * m21) -
            |    m01 * (m10 * m22 - m20 * m12) +
            |    m02 * (m10 * m21 - m20 * m11)
	    | ) * (m00 * m11 - m10 * m01)

    .. note:: Example

    .. code-block:: c

        mat3 mat = {
            {8.00,6.00,5.00},
            {16.00,31.00,25.00},
            {13.00,18.00,7.00},
        };
        mat3 dest = GLM_MAT3_ZERO_INIT;
        glm_mat3_inv(mat, dest);

    .. csv-table:: mat3 **(mat)** Before
        :header: "", "column 1", "column 2", "column 3", "", ""

        "row 1", "8.00",     "16.00",    "13.00",      "**8.00**", "**16.00**"
        "row 2", "6.00",     "31.00",    "18.00",      "**6.00**", "**31.00**"
        "row 3", "5.00",     "25.00",    "7.00",       "**5.00**", "**25.00**"
        "     ", "**8.00**", "**16.00**", "**13.00**", "**8.00**", "**16.00**"
        "     ", "**6.00**", "**31.00**", "**18.00**", "**6.00**", "**31.00**"

    .. list-table:: mat3 **(dest)** After
        :header-rows: 1

        * -
          - column 1
          - column 2
          - column 3
        * - row 1
          - | **0.200** = 1.0 / (
            |    8.00 * (31.00 * 7.00 - 25.00 * 18.00) -
            |    6.00 * (16.00 * 7.00 - 13.00 * 25.00) +
            |    5.00 * (16.00 * 18.00 - 13.00 * 31.00)
            | ) * (31.00 * 7.00 - 25.00 * 18.00)
          - | **-0.184** = -( 1.0 / (
            |    8.00 * (31.00 * 7.00 - 25.00 * 18.00) -
            |    6.00 * (16.00 * 7.00 - 13.00 * 25.00) +
            |    5.00 * (16.00 * 18.00 - 13.00 * 31.00)
            | ) ) * (16.00 * 7.00 - 13.00 * 25.00)
          - | **0.099** = 1.0 / (
            |    8.00 * (31.00 * 7.00 - 25.00 * 18.00) -
            |    6.00 * (16.00 * 7.00 - 13.00 * 25.00) +
            |    5.00 * (16.00 * 18.00 - 13.00 * 31.00)
            | ) * (16.00 * 18.00 - 31.00 * 13.00)
        * - row 2
          - | **-0.041** = -( 1.0 / (
            |    8.00 * (31.00 * 7.00 - 25.00 * 18.00) -
            |    6.00 * (16.00 * 7.00 - 13.00 * 25.00) +
            |    5.00 * (16.00 * 18.00 - 13.00 * 31.00)
            | ) ) * (6.00 * 7.00 - 18.00 * 5.00)
          - | **0.007** = 1.0 / (
            |    8.00 * (31.00 * 7.00 - 25.00 * 18.00) -
            |    6.00 * (16.00 * 7.00 - 13.00 * 25.00) +
            |    5.00 * (16.00 * 18.00 - 13.00 * 31.00)
            | ) * (8.00 * 7.00 - 13.00 * 5.00)
          - | **-0.056** = -( 1.0 / (
            |    8.00 * (31.00 * 7.00 - 25.00 * 18.00) -
            |    6.00 * (16.00 * 7.00 - 13.00 * 25.00) +
            |    5.00 * (16.00 * 18.00 - 13.00 * 31.00)
            | ) ) * (8.00 * 18.00 - 13.00 * 6.00)
        * - row 3
          - | **0.004** = 1.0 / (
            |    8.00 * (31.00 * 7.00 - 25.00 * 18.00) -
            |    6.00 * (16.00 * 7.00 - 13.00 * 25.00) +
            |    5.00 * (16.00 * 18.00 - 13.00 * 31.00)
            | ) * (6.00 * 25.00 - 31.00 * 5.00)
          - | **0.103** = -( 1.0 / (
            |    8.00 * (31.00 * 7.00 - 25.00 * 18.00) -
            |    6.00 * (16.00 * 7.00 - 13.00 * 25.00) +
            |    5.00 * (16.00 * 18.00 - 13.00 * 31.00)
            | ) ) * (8.00 * 25.00 - 16.00 * 5.00)
	  - | **-0.130** = 1.0 / (
            |    8.00 * (31.00 * 7.00 - 25.00 * 18.00) -
            |    6.00 * (16.00 * 7.00 - 13.00 * 25.00) +
            |    5.00 * (16.00 * 18.00 - 13.00 * 31.00)
	    | ) * (8.00 * 31.00 - 16.00 * 6.00)

.. c:function:: void glm_mat3_swap_col(mat3 mat, int col1, int col2)

    Swap two columns in mat3 (mat) and store in same matrix.

    Parameters:
      | *[in, out]* **mat**   mat3 (src, dest)
      | *[in]*       **col1** Column 1 array index
      | *[in]*       **col2** Column 2 array index

    .. note:: Mathematical explanation

    .. csv-table:: mat3 **(mat)** Before
        :header: "", "column 1", "column 2", "column 3"

        "row 1", "m00", "m10", "m20"
        "row 2", "m01", "m11", "m21"
        "row 3", "m02", "m12", "m22"

    .. code-block:: c

        glm_mat3_swap_col(mat, 0, 1);

    .. csv-table:: mat3 **(mat)** After
        :header: "", "column 1", "column 2", "column 3"

        "row 1", "m10", "m00", "m20"
        "row 2", "m11", "m01", "m21"
        "row 3", "m12", "m02", "m22"

    .. note:: Example

    .. code-block:: c

        mat3 mat = {
            {8.00,6.00,5.00},
            {16.00,31.00,25.00},
            {13.00,18.00,7.00},
        };
        glm_mat3_swap_col(mat, 0, 1);

    .. csv-table:: mat3 **(mat)** Before
        :header: "", "column 1", "column 2", "column 3"

        "row 1", "8.00", "16.00", "13.00"
        "row 2", "6.00", "31.00", "18.00"
        "row 3", "5.00", "25.00", "7.00"

    .. csv-table:: mat3 **(mat)** After
        :header: "", "column 1", "column 2", "column 3"

        "row 1", "16.00", "8.00", "13.00"
        "row 2", "31.00", "6.00", "18.00"
        "row 3", "25.00", "5.00", "7.00"

.. c:function:: void glm_mat3_swap_row(mat3 mat, int row1, int row2)

    Swap two rows in mat3 (mat) and store in same matrix.

    Parameters:
      | *[in, out]* **mat**  mat3 (src, dest)
      | *[in]*      **row1** Row 1 array index
      | *[in]*      **row2** Row 2 array index

    .. note:: Mathematical explanation

    .. csv-table:: mat3 **(mat)** Before
        :header: "", "column 1", "column 2", "column 3"

        "row 1", "m00", "m10", "m20"
        "row 2", "m01", "m11", "m21"
        "row 3", "m02", "m12", "m22"

    .. code-block:: c

        glm_mat3_swap_row(mat, 0, 1);

    .. csv-table:: mat3 **(mat)** After
        :header: "", "column 1", "column 2", "column 3"

        "row 1", "m01", "m11", "m21"
        "row 2", "m00", "m10", "m20"
        "row 3", "m02", "m12", "m22"

    .. note:: Example

    .. code-block:: c

        mat3 mat = {
            {8.00,6.00,5.00},
            {16.00,31.00,25.00},
            {13.00,18.00,7.00},
        };
        glm_mat3_swap_col(mat, 0, 1);

    .. csv-table:: mat3 **(mat)** Before
        :header: "", "column 1", "column 2", "column 3"

        "row 1", "8.00", "16.00", "13.00"
        "row 2", "6.00", "31.00", "18.00"
        "row 3", "5.00", "25.00", "7.00"

    .. csv-table:: mat3 **(mat)** After
        :header: "", "column 1", "column 2", "column 3"

        "row 1", "6.00", "31.00", "18.00"
        "row 2", "8.00", "16.00", "13.00"
        "row 3", "5.00", "25.00", "7.00"

.. c:function:: void glm_mat3_quat(mat3 m, versor dest)

    convert mat3 to quaternion

    Parameters:
      | *[in]*  **m**     rotation matrix
      | *[out]* **dest**  destination quaternion

.. c:function:: void glm_mat3_textrans(float sx, float sy, float rot, float tx, float ty, mat3 dest) 
  
    Create texture transformation matrix, rotation is in radians CCW/RH

    Parameters:
      | *[in]*  **sx**   scale x
      | *[in]*  **sy**   scale y
      | *[in]*  **rot**  rotation in radians CCW/RH
      | *[in]*  **tx**   translation x
      | *[in]*  **ty**   translation y
      | *[out]* **dest** destination matrix3x3

.. c:function:: float glm_mat3_det(mat3 m)

    Returns mat3 determinant.

    Parameters:
      | *[in]* **m** mat3 (src)

    Returns:
      | mat3 determinant (float)

    .. note:: Mathematical explanation

    .. csv-table:: mat3 **(mat)**
        :header: "", "column 1", "column 2", "column 3", "", ""

        "row 1", "m00",     "m10",     "m20",     "**m00**", "**m10**"
        "row 2", "m01",     "m11",     "m21",     "**m01**", "**m11**"
        "row 3", "m02",     "m12",     "m22",     "**m02**", "**m12**"
        "     ", "**m00**", "**m10**", "**m20**", "**m00**", "**m10**"
        "     ", "**m01**", "**m11**", "**m21**", "**m01**", "**m11**"

    | For more information see first portion of
    | `How to find the inverse of a 3 by 3 matrix (the fast way)[youtube]`_.

    .. code-block:: c

        m00 * (m11 * m22 - m12 * m21) -
        m01 * (m10 * m22 - m20 * m12) +
        m02 * (m10 * m21 - m20 * m11)

    .. note:: Example

    .. code-block:: c

        mat3 m = {
            {8.00,6.00,5.00},
            {16.00,31.00,25.00},
            {13.00,18.00,7.00},
        };
        glm_mat3_det(m);

    .. csv-table:: mat3 **(m)**
        :header: "", "column 1", "column 2", "column 3", "", ""

        "row 1", "8.00", "16.00", "13.00", "**8.00**", "**16.00**"
        "row 2", "6.00", "31.00", "18.00", "**6.00**", "**31.00**"
        "row 3", "5.00", "25.00", "7.00",  "**5.00**", "**25.00**"

    .. code-block:: c

        -1161.00 = 8.00 * (31.00 * 7.00 - 25.00 * 18.00) -
                   6.00 * (16.00 * 7.00 - 13.00 * 25.00) +
                   5.00 * (16.00 * 18.00 - 13.00 * 31.00)

.. c:function:: void glm_mat3_trace(mat3 m)

    | Returns trace of matrix. Which is:
    |
    | The sum of the elements on the main diagonal from
    | upper left corner to the bottom right corner.

    Parameters:
      | *[in]* **m** mat3 (src)

    Returns:
      | mat3 trace (float)

    .. note:: Mathematical explanation

    .. csv-table:: mat3 **(m)**
        :header: "", "column 1", "column 2", "column 3"

        "row 1", "m00", "m10", "m20"
        "row 2", "m01", "m11", "m21"
        "row 3", "m02", "m12", "m22"

    .. code-block:: c

        m00 + m11 + m22

    .. note:: Example

    .. code-block:: c

        mat3 m = {
            {8.00,6.00,5.00},
            {16.00,31.00,25.00},
            {13.00,18.00,7.00},
        };
        glm_mat3_trace(m);

    .. csv-table:: mat3 **(m)**
        :header: "", "column 1", "column 2", "column 3"

        "row 1", "8.00", "16.00", "13.00"
        "row 2", "6.00", "31.00", "18.00"
        "row 3", "5.00", "25.00", "7.00"

    .. code-block:: c

        82.00 = 8.00 + 31.00 + 7.00

.. c:function:: float glm_mat3_rmc(vec3 r, mat3 m, vec3 c)

    | Helper for  R (row vector) * M (matrix) * C (column vector)
    |
    | **rmc** stands for **Row** * **Matrix** * **Column**
    |
    | the result is scalar because M * C = ResC (1x2, column vector),
    | then if you take the dot_product(R (3x1), ResC (1x3)) = scalar value.

    Parameters:
      | *[in]* **r** vec3 (3x1, row vector)
      | *[in]* **m** mat3 (2x2, matrix)
      | *[in]* **c** vec3 (1x3, column vector)

    Returns:
      | Scalar value (float, 1x1)

    .. note:: Mathematical explanation

    .. csv-table:: row vec3 (3x1) **(r)**
        :header: "", "column 1", "column 2", "column 3"

        "row 1", "a00", "a10", "a20"

    .. csv-table:: mat3 **(m)**
        :header: "", "column 1", "column 2", "column 3"

        "row 1", "b00", "b10", "b20"
        "row 2", "b01", "b11", "b21"
        "row 3", "b02", "b12", "b22"

    .. csv-table:: column vec3 (1x3) **(c)**
        :header: "", "column 1"

        "row 1", "c00"
        "row 2", "c01"
        "row 3", "c02"

    .. code-block:: c

        M * C = C (column vector)
        dot_product(R, C)

    .. csv-table:: column vec3 (1x3) **(C)**
        :header: "", "column 1"

        "row 1", "b00 * c00 + b10 * c01 + b20 * c02"
        "row 2", "b01 * c00 + b11 * c01 + b21 * c02"
        "row 3", "b02 * c00 + b11 * c01 + b22 * c02"

    .. list-table:: float **(scalar)**
        :header-rows: 1

        * -
          - column 1
        * - row 1
          - | a00 * (b00 * c00 + b10 * c01 + b20 * c02) +
            | a10 * (b01 * c00 + b11 * c01 + b21 * c02) +
            | a20 * (b02 * c00 + b11 * c01 + b22 * c02)

    .. note:: Example

    .. code-block:: c

        vec3 r = {8.00,4.00,13.00};
        vec3 c = {7.00,2.00,9.00};
        mat3 m = {
            {8.00,6.00,5.00},
            {16.00,31.00,25.00},
            {13.00,18.00,7.00},
        };
        glm_mat3_rmc(r, m, c);

    .. csv-table:: row vec3 (3x1) **(r)**
        :header: "", "column 1", "column 2", "column 3"

        "row 1", "8.00", "4.00", "13.00"

    .. csv-table:: mat3 **(m)**
        :header: "", "column 1", "column 2", "column 3"

        "row 1", "8.00", "16.00", "13.00"
        "row 2", "6.00", "31.00", "18.00"
        "row 3", "5.00", "25.00", "7.00"

    .. csv-table:: column vec3 (1x3) **(c)**
        :header: "", "column 1"

        "row 1", "7.00"
        "row 2", "2.00"
        "row 3", "9.00"

    .. csv-table:: column vec3 (1x3) **(C)**
        :header: "", "column 1"

        "row 1", "**205.00** = 8.00 * 7.00 + 16.00 * 2.00 + 13.00 * 9.00"
        "row 2", "**266.00** = 6.00 * 7.00 + 31.00 * 2.00 + 18.00 * 9.00"
        "row 3", "**148.00** = 5.00 * 7.00 + 25.00 * 2.00 + 7.00 * 9.00"

    .. csv-table:: float (1x1) **(scalar)**
        :header: "", "column 1"

        "row 1", "**4628.00** = 8.00 * 205.00 + 4.00 * 266.00 + 13.00 * 148.00"

.. _How to find the inverse of a 3 by 3 matrix (the fast way)[youtube]: https://www.youtube.com/watch?v=p8VnTCfJHAo
