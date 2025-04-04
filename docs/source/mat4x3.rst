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

1. :c:func:`glm_mat4x3_copy`
#. :c:func:`glm_mat4x3_zero`
#. :c:func:`glm_mat4x3_make`
#. :c:func:`glm_mat4x3_mul`
#. :c:func:`glm_mat4x3_mulv`
#. :c:func:`glm_mat4x3_transpose`
#. :c:func:`glm_mat4x3_scale`

Represented
~~~~~~~~~~~

.. csv-table:: mat4x3
   :header: "", "column 1", "column 2", "column 3", "column 4"

   "row 1", "m00", "m10", "m20", "m30"
   "row 2", "m01", "m11", "m21", "m31"
   "row 3", "m02", "m12", "m22", "m32"

Functions documentation
~~~~~~~~~~~~~~~~~~~~~~~

.. c:function:: void glm_mat4x3_copy(mat4x3 src, mat4x3 dest)

    Copy mat4x3 (src) to mat4x3 (dest).

    Parameters:
      | *[in]*  **src**  mat4x3 (left)
      | *[out]* **dest** destination (result, mat4x3)

    .. csv-table:: mat4x3 **(src)**
        :header: "", "column 1", "column 2", "column 3", "column 4"

        "row 1", "a00", "a10", "a20", "a30"
        "row 2", "a01", "a11", "a21", "a31"
        "row 3", "a02", "a12", "a22", "a32"

    .. csv-table:: mat4x3 **(dest)**
        :header: "", "column 1", "column 2", "column 3", "column 4"

        "row 1", "b00 = a00", "b10 = a10", "b20 = a20", "b30 = a30"
        "row 2", "b01 = a01", "b11 = a11", "b21 = a21", "b31 = a31"
        "row 3", "b02 = a02", "b12 = a12", "b22 = a22", "b32 = a32"

.. c:function:: void glm_mat4x3_zero(mat4x3 m)

    Zero out the mat4x3 (m).

    Parameters:
      | *[in, out]* **m** mat4x3 (src, dest)

    .. csv-table:: mat4x3 **(m)**
        :header: "", "column 1", "column 2", "column 3", "column 4"

        "row 1", "0.00", "2.00", "15.00", "44.00"
        "row 2", "5.00", "4.00", "6.00", "12.00"
        "row 3", "88.00", "8.00", "4.30", "15.00"

    .. csv-table:: mat4x3 **(m)**
        :header: "", "column 1", "column 2", "column 3", "column 4"

        "row 1", "0.00", "0.00", "0.00", "0.00"
        "row 2", "0.00", "0.00", "0.00", "0.00"
        "row3", "0.00", "0.00", "0.00", "0.00"

.. c:function:: void glm_mat4x3_make(const float * __restrict src, mat4x3 dest)

    Create mat4x3 (dest) from pointer (src).

    .. note:: **@src** must contain at least 12 elements.

    Parameters:
      | *[in]*  **src**  pointer to an array of floats (left)
      | *[out]* **dest** destination (result, mat4x3)

    .. csv-table:: float array (1x12) **(src)**
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
        "row 10", "v9"
        "row 11", "v10"
        "row 12", "v11"

    .. csv-table:: mat4x3 **(dest)**
        :header: "", "column 1", "column 2", "column 3", "column 4"

        "row 1", "v0", "v3", "v6", "v9"
        "row 2", "v1", "v4", "v7", "v10"
        "row 3", "v2", "v5", "v8", "v11"

.. c:function:: void glm_mat4x3_mul(mat4x3 m1, mat3x4 m2, mat3 dest)

    Multiply mat4x3 (m1) by mat3x4 (m2) and store in mat3 (dest).

    .. code-block:: c

       glm_mat4x3_mul(mat4x3, mat3x4, mat3);

    Parameters:
      | *[in]*  **m1**   mat4x3 (left)
      | *[in]*  **m2**   mat3x4 (right)
      | *[out]* **dest** destination (result, mat3)

    .. csv-table:: mat4x3 **(m1)**
        :header: "", "column 1", "column 2", "column 3", "column 4"

        "row 1", "a00", "a10", "a20", "a30"
        "row 2", "a01", "a11", "a21", "a31"
        "row 3", "a02", "a12", "a22", "a32"

    .. csv-table:: mat3x4 **(m2)**
        :header: "", "column 1", "column 2", "column 3"

        "row 1", "b00", "b10", "b20"
        "row 2", "b01", "b11", "b21"
        "row 3", "b02", "b12", "b22"
        "row 4", "b03", "b13", "b23"

    .. csv-table:: mat3x3 **(dest)**
        :header: "", "column 1", "column 2", "column 3"

        "row 1", "a00 * b00 + a10 * b01 + a20 * b02 + a30 * b03", "a00 * b10 + a10 * b11 + a20 * b12 + a30 * b13", "a00 * b20 + a10 * b21 + a20 * b22 + a30 * b23"
        "row 2", "a01 * b00 + a11 * b01 + a21 * b02 + a31 * b03", "a01 * b10 + a11 * b11 + a21 * b12 + a31 * b13", "a01 * b20 + a11 * b21 + a21 * b22 + a31 * b23"
        "row 3", "a02 * b00 + a12 * b01 + a22 * b02 + a32 * b03", "a02 * b10 + a12 * b11 + a22 * b12 + a32 * b13", "a02 * b20 + a12 * b21 + a22 * b22 + a32 * b23"

.. c:function:: void glm_mat4x3_mulv(mat4x3 m, vec4 v, vec3 dest)

    Multiply mat4x3 (m) by vec4 (v) and store in vec3 (dest).

    Parameters:
      | *[in]*  **m**    mat4x3 (left)
      | *[in]*  **v**    vec4 (right, column vector)
      | *[out]* **dest** destination (result, column vector)

    .. csv-table:: mat4x3 **(m)**
        :header: "", "column 1", "column 2", "column 3", "column 4"

        "row 1", "m00", "m10", "m20", "m30"
        "row 2", "m01", "m11", "m21", "m31"
        "row 3", "m02", "m12", "m22", "m32"

    .. csv-table:: column vec4 (1x4) **(v)**
        :header: "", "column 1"

        "row 1", "v0"
        "row 2", "v1"
        "row 3", "v2"
        "row 4", "v3"

    .. csv-table:: column vec3 (1x3) **(dest)**
        :header: "", "column 1"

        "row 1", "m00 * v0 + m10 * v1 + m20 * v2 + m30 * v3"
        "row 2", "m01 * v0 + m11 * v1 + m21 * v2 + m31 * v3"
        "row 3", "m02 * v0 + m12 * v1 + m22 * v2 + m32 * v3"

.. c:function:: void glm_mat4x3_transpose(mat4x3 src, mat3x4 dest)

    Transpose mat4x3 (src) and store in mat3x4 (dest).

    Parameters:
      | *[in]*  **src**  mat4x3 (left)
      | *[out]* **dest** destination (result, mat3x4)

    .. csv-table:: mat4x3 **(src)**
        :header: "", "column 1", "column 2", "column 3", "column 4"

        "row 1", "a00", "a10", "a20", "a30"
        "row 2", "a01", "a11", "a21", "a31"
        "row 3", "a02", "a12", "a22", "a32"

    .. csv-table:: mat3x4 **(dest)**
        :header: "", "column 1", "column 2", "column 3"

        "row 1", "b00 = a00", "b10 = a01", "b20 = a02"
        "row 2", "b01 = a10", "b11 = a11", "b21 = a12"
        "row 3", "b02 = a20", "b12 = a21", "b22 = a22"
        "row 4", "b03 = a30", "b13 = a31", "b23 = a32"

.. c:function:: void glm_mat4x3_scale(mat4x3 m, float s)

    Multiply mat4x3 (m) by scalar constant (s).

    Parameters:
      | *[in, out]* **m** mat4x3 (src, dest)
      | *[in]*      **s** float (scalar)

    .. csv-table:: mat4x3 **(m)**
        :header: "", "column 1", "column 2", "column 3", "column 4"

        "row 1", "m00 = m00 * s", "m10 = m10 * s", "m20 = m20 * s", "m30 = m30 * s"
        "row 2", "m01 = m01 * s", "m11 = m11 * s", "m21 = m21 * s", "m31 = m31 * s"
        "row 3", "m02 = m02 * s", "m12 = m12 * s", "m22 = m22 * s", "m32 = m32 * s"
