.. default-domain:: C

mat2x4
======

Header: cglm/mat2x4.h

Table of contents (click to go):
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

Macros:

1. GLM_MAT2X4_ZERO_INIT
#. GLM_MAT2X4_ZERO

Functions:

1. :c:func:`glm_mat2x4_copy`
#. :c:func:`glm_mat2x4_zero`
#. :c:func:`glm_mat2x4_make`
#. :c:func:`glm_mat2x4_mul`
#. :c:func:`glm_mat2x4_mulv`
#. :c:func:`glm_mat2x4_transpose`
#. :c:func:`glm_mat2x4_scale`

Represented
~~~~~~~~~~~

.. csv-table:: mat2x4
   :header: "", "column 1", "column 2"

   "row 1", "m00", "m10"
   "row 2", "m01", "m11"
   "row 3", "m02", "m12"
   "row 4", "m03", "m13"

Functions documentation
~~~~~~~~~~~~~~~~~~~~~~~

.. c:function:: void glm_mat2x4_copy(mat2x4 src, mat2x4 dest)

    Copy mat2x4 (src) to mat2x4 (dest).

    Parameters:
      | *[in]*  **src**  mat2x4 (left)
      | *[out]* **dest** destination (result, mat2x4)

    .. csv-table:: mat2x4 **(src)**
        :header: "", "column 1", "column 2"

        "row 1", "a00", "a10"
        "row 2", "a01", "a11"
        "row 3", "a02", "a12"
        "row 4", "a03", "a13"

    .. csv-table:: mat2x4 **(dest)**
        :header: "", "column 1", "column 2"

        "row 1", "b00 = a00", "b10 = a10"
        "row 2", "b01 = a01", "b11 = a11"
        "row 3", "b02 = a02", "b12 = a12"
        "row 4", "b03 = a03", "b13 = a13"

.. c:function:: void glm_mat2x4_zero(mat2x4 m)

    Zero out the mat2x4 (m).

    Parameters:
      | *[in, out]* **m** mat2x4 (src, dest)

    .. csv-table:: mat2x4 **(m)**
        :header: "", "column 1", "column 2"

        "row 1", "0.00", "2.00"
        "row 2", "5.00", "4.00"
        "row 3", "7.00", "6.00"
        "row 4", "23.00", "1.00"

    .. csv-table:: mat2x4 **(m)**
        :header: "", "column 1", "column 2"

        "row 1", "0.00", "0.00"
        "row 2", "0.00", "0.00"
        "row 3", "0.00", "0.00"
        "row 4", "0.00", "0.00"

.. c:function:: void glm_mat2x4_make(const float * __restrict src, mat2x4 dest)

    Create mat2x4 (dest) from pointer (src).

    .. note:: **@src** must contain at least 8 elements.

    Parameters:
      | *[in]*  **src**  pointer to an array of floats (left)
      | *[out]* **dest** destination (result, mat2x4)

    .. csv-table:: float array (1x8) **(src)**
        :header: "", "column 1"

        "row 1", "v0"
        "row 2", "v1"
        "row 3", "v2"
        "row 4", "v3"
        "row 5", "v4"
        "row 6", "v5"
        "row 7", "v6"
        "row 8", "v7"

    .. csv-table:: mat2x4 **(dest)**
        :header: "", "column 1", "column 2"

        "row 1", "v0", "v4"
        "row 2", "v1", "v5"
        "row 3", "v2", "v6"
        "row 4", "v3", "v7"

.. c:function:: void glm_mat2x4_mul(mat2x4 m1, mat4x2 m2, mat4 dest)

    Multiply mat2x4 (m1) by mat4x2 (m2) and store in mat4 (dest).

    .. code-block:: c

       glm_mat2x4_mul(mat2x4, mat4x2, mat4);

    Parameters:
      | *[in]*  **m1**   mat2x4 (left)
      | *[in]*  **m2**   mat4x2 (right)
      | *[out]* **dest** destination (result, mat4)

    .. csv-table:: mat2x4 **(m1)**
        :header: "", "column 1", "column 2"

        "row 1", "a00", "a10"
        "row 2", "a01", "a11"
        "row 3", "a02", "a12"
        "row 4", "a03", "a13"

    .. csv-table:: mat4x2 **(m2)**
        :header: "", "column 1", "column 2", "column 3", "column 4"

        "row 1", "b00", "b10", "b20", "b30"
        "row 2", "b01", "b11", "b21", "b31"

    .. csv-table:: mat4x4 **(dest)**
        :header: "", "column 1", "column 2", "column 3", "column 4"

        "row 1", "a00 * b00 + a10 * b01", "a00 * b10 + a10 * b11", "a00 * b20 + a10 * b21", "a00 * b30 + a10 * b31"
        "row 2", "a01 * b00 + a11 * b01", "a01 * b10 + a11 * b11", "a01 * b20 + a11 * b21", "a01 * b30 + a11 * b31"
        "row 3", "a02 * b00 + a12 * b01", "a02 * b10 + a12 * b11", "a02 * b20 + a12 * b21", "a02 * b30 + a12 * b31"
        "row 4", "a03 * b00 + a13 * b01", "a03 * b10 + a13 * b11", "a03 * b20 + a13 * b21", "a03 * b30 + a13 * b31"

.. c:function:: void glm_mat2x4_mulv(mat2x4 m, vec2 v, vec4 dest)

    Multiply mat2x4 (m) by vec2 (v) and store in vec4 (dest).

    Parameters:
      | *[in]*  **m**    mat2x4 (left)
      | *[in]*  **v**    vec2 (right, column vector)
      | *[out]* **dest** destination (result, column vector)

    .. csv-table:: mat2x4 **(m)**
        :header: "", "column 1", "column 2"

        "row 1", "m00", "m10"
        "row 2", "m01", "m11"
        "row 3", "m02", "m12"
        "row 4", "m03", "m13"

    .. csv-table:: column vec2 (1x2) **(v)**
        :header: "", "column 1"

        "row 1", "v0"
        "row 2", "v1"

    .. csv-table:: column vec4 (1x4) **(dest)**
        :header: "", "column 1"

        "row 1", "m00 * v0 + m10 * v1"
        "row 2", "m01 * v0 + m11 * v1"
        "row 3", "m02 * v0 + m12 * v1"
        "row 4", "m03 * v0 + m13 * v1"

.. c:function:: void glm_mat2x4_transpose(mat2x4 src, mat4x2 dest)

    Transpose mat2x4 (src) and store in mat4x2 (dest).

    Parameters:
      | *[in]*  **src**  mat2x4 (left)
      | *[out]* **dest** destination (result, mat4x2)

    .. csv-table:: mat2x4 **(src)**
        :header: "", "column 1", "column 2"

        "row 1", "a00", "a10"
        "row 2", "a01", "a11"
        "row 3", "a02", "a12"
        "row 4", "a03", "a13"

    .. csv-table:: mat4x2 **(dest)**
        :header: "", "column 1", "column 2", "column 3", "column 4"

        "row 1", "b00 = a00", "b10 = a01", "b20 = a02", "b30 = a03"
        "row 2", "b01 = a10", "b11 = a11", "b21 = a12", "b31 = a13"

.. c:function:: void  glm_mat2x4_scale(mat2x4 m, float s)

    Multiply mat2x4 (m) by scalar constant (s).

    Parameters:
      | *[in, out]* **m** mat2x4 (src, dest)
      | *[in]*      **s** float (scalar)

    .. csv-table:: mat2x4 **(m)**
        :header: "", "column 1", "column 2"

        "row 1", "m00 = m00 * s", "m10 = m10 * s"
        "row 2", "m01 = m01 * s", "m11 = m11 * s"
        "row 3", "m02 = m02 * s", "m12 = m12 * s"
        "row 4", "m03 = m03 * s", "m13 = m13 * s"
