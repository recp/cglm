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

Represented
~~~~~~~~~~~

.. csv-table:: mat3x4
   :header: "", "column 1", "column 2", "column 3"

   "row 1", "m00", "m10", "m20"
   "row 2", "m01", "m11", "m21"
   "row 3", "m02", "m12", "m22"
   "row 4", "m03", "m13", "m23"

Functions documentation
~~~~~~~~~~~~~~~~~~~~~~~

.. c:function:: void glm_mat3x4_copy(mat3x4 src, mat3x4 dest)

    Copy mat3x4 (src) to mat3x4 (dest).

    Parameters:
      | *[in]*  **src**  mat3x4 (left)
      | *[out]* **dest** destination (result, mat3x4)

    .. csv-table:: mat3x4 **(src)**
        :header: "", "column 1", "column 2", "column 3"

        "row 1", "a00", "a10", "a20"
        "row 2", "a01", "a11", "a21"
        "row 3", "a02", "a12", "a22"
        "row 4", "a03", "a13", "a23"

    .. csv-table:: mat3x4 **(dest)**
        :header: "", "column 1", "column 2", "column 3"

        "row 1", "b00 = a00", "b10 = a10", "b20 = a20"
        "row 2", "b01 = a01", "b11 = a11", "b21 = a21"
        "row 3", "b02 = a02", "b12 = a12", "b22 = a22"
        "row 4", "b03 = a03", "b13 = a13", "b23 = a23"

.. c:function:: void glm_mat3x4_zero(mat3x4 m)

    Zero out the mat3x4 (m).

    Parameters:
      | *[in, out]* **m** mat3x4 (src, dest)

    .. csv-table:: mat3x4 **(m)**
        :header: "", "column 1", "column 2", "column 3"

        "row 1", "0.00", "2.00", "78.00"
        "row 2", "5.00", "4.00", "12.00"
        "row 3", "7.00", "6.00", "32.00"
        "row 4", "23.00", "1.00", "9.00"

    .. csv-table:: mat3x4 **(m)**
        :header: "", "column 1", "column 2", "column 3"

        "row 1", "0.00", "0.00", "0.00"
        "row 2", "0.00", "0.00", "0.00"
        "row 3", "0.00", "0.00", "0.00"
        "row 4", "0.00", "0.00", "0.00"

.. c:function:: void glm_mat3x4_make(const float * __restrict src, mat3x4 dest)

    Create mat3x4 (dest) from pointer (src).

    .. note:: **@src** must contain at least 12 elements.

    Parameters:
      | *[in]*  **src**  pointer to an array of floats (left)
      | *[out]* **dest** destination (result, mat3x4)

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

    .. csv-table:: mat3x4 **(dest)**
        :header: "", "column 1", "column 2", "column 3"

        "row 1", "v0", "v4", "v8"
        "row 2", "v1", "v5", "v9"
        "row 3", "v2", "v6", "v10"
        "row 4", "v3", "v7", "v11"

.. c:function:: void glm_mat3x4_mul(mat3x4 m1, mat4x3 m2, mat4 dest)

    Multiply mat3x4 (m1) by mat4x3 (m2) and store in mat4 (dest).

    .. code-block:: c

       glm_mat3x4_mul(mat3x4, mat4x3, mat4);

    Parameters:
      | *[in]*  **m1**   mat2x4 (left)
      | *[in]*  **m2**   mat4x2 (right)
      | *[out]* **dest** destination (result, mat4)

    .. csv-table:: mat3x4 **(m1)**
        :header: "", "column 1", "column 2", "column 3"

        "row 1", "a00", "a10", "a20"
        "row 2", "a01", "a11", "a21"
        "row 3", "a02", "a12", "a22"
        "row 4", "a03", "a13", "a23"

    .. csv-table:: mat4x3 **(m2)**
        :header: "", "column 1", "column 2", "column 3", "column 4"

        "row 1", "b00", "b10", "b20", "b30"
        "row 2", "b01", "b11", "b21", "b31"
        "row 3", "b02", "b12", "b22", "b32"

    .. csv-table:: mat4x4 **(dest)**
        :header: "", "column 1", "column 2", "column 3", "column 4"

        "row 1", "a00 * b00 + a10 * b01 + a20 * b02", "a00 * b10 + a10 * b11 + a20 * b12", "a00 * b20 + a10 * b21 + a20 * b22", "a00 * b30 + a10 * b31 + a20 * b32"
        "row 2", "a01 * b00 + a11 * b01 + a21 * b02", "a01 * b10 + a11 * b11 + a21 * b12", "a01 * b20 + a11 * b21 + a21 * b22", "a01 * b30 + a11 * b31 + a21 * b32"
        "row 3", "a02 * b00 + a12 * b01 + a22 * b02", "a02 * b10 + a12 * b11 + a22 * b12", "a02 * b20 + a12 * b21 + a22 * b22", "a02 * b30 + a12 * b31 + a22 * b32"
        "row 4", "a03 * b00 + a13 * b01 + a23 * b02", "a03 * b10 + a13 * b11 + a23 * b12", "a03 * b20 + a13 * b21 + a23 * b22", "a03 * b30 + a13 * b31 + a23 * b32"

.. c:function:: void glm_mat3x4_mulv(mat3x4 m, vec3 v, vec4 dest)

    Multiply ma3x4 (m) by vec3 (v) and store in vec4 (dest).

    Parameters:
      | *[in]*  **m**    mat3x4 (left)
      | *[in]*  **v**    vec3 (right, column vector)
      | *[out]* **dest** destination (result, column vector)

    .. csv-table:: mat3x4 **(m)**
        :header: "", "column 1", "column 2", "column 3"

        "row 1", "m00", "m10", "m20"
        "row 2", "m01", "m11", "m21"
        "row 3", "m02", "m12", "m22"
        "row 4", "m03", "m13", "m23"

    .. csv-table:: column vec3 (1x3) **(v)**
        :header: "", "column 1"

        "row 1", "v0"
        "row 2", "v1"
        "row 3", "v2"

    .. csv-table:: column vec4 (1x4) **(dest)**
        :header: "", "column 1"

        "row 1", "m00 * v0 + m10 * v1 + m20 * v2"
        "row 2", "m01 * v0 + m11 * v1 + m21 * v2"
        "row 3", "m02 * v0 + m12 * v1 + m22 * v2"
        "row 4", "m03 * v0 + m13 * v1 + m23 * v2"

.. c:function:: void glm_mat3x4_transpose(mat3x4 src, mat4x3 dest)

    Transpose mat3x4 (src) and store in mat4x3 (dest).

    Parameters:
      | *[in]*  **src**  mat3x4 (left)
      | *[out]* **dest** destination (result, mat4x3)

    .. csv-table:: mat3x4 **(src)**
        :header: "", "column 1", "column 2", "column 3"

        "row 1", "a00", "a10", "a20"
        "row 2", "a01", "a11", "a21"
        "row 3", "a02", "a12", "a22"
        "row 4", "a03", "a13", "a23"

    .. csv-table:: mat4x3 **(dest)**
        :header: "", "column 1", "column 2", "column 3", "column 4"

        "row 1", "b00 = a00", "b10 = a01", "b20 = a02", "b30 = a03"
        "row 2", "b01 = a10", "b11 = a11", "b21 = a12", "b31 = a13"
        "row 3", "b02 = a20", "b12 = a21", "b22 = a22", "b32 = a23"

.. c:function:: void  glm_mat3x4_scale(mat3x4 m, float s)

    Multiply mat3x4 (m) by scalar constant (s).

    Parameters:
      | *[in, out]* **m** mat3x4 (src, dest)
      | *[in]*      **s** float (scalar)

    .. csv-table:: mat3x4 **(m)**
        :header: "", "column 1", "column 2", "column 3"

        "row 1", "m00 = m00 * s", "m10 = m10 * s", "m20 = m20 * s"
        "row 2", "m01 = m01 * s", "m11 = m11 * s", "m21 = m21 * s"
        "row 3", "m02 = m02 * s", "m12 = m12 * s", "m22 = m22 * s"
        "row 4", "m03 = m03 * s", "m13 = m13 * s", "m23 = m23 * s"
