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

Represented
~~~~~~~~~~~

.. csv-table:: mat2x3
   :header: "", "column 1", "column 2"

   "row 1", "m00", "m10"
   "row 2", "m01", "m11"
   "row 3", "m02", "m12"

Functions documentation
~~~~~~~~~~~~~~~~~~~~~~~

.. c:function:: void glm_mat2x3_copy(mat2x3 src, mat2x3 dest)

    Copy mat2x3 (src) to mat2x3 (dest).

    Parameters:
      | *[in]*  **src**  mat2x3 (left)
      | *[out]* **dest** destination (result, mat2x3)

    .. csv-table:: mat2x3 **(src)**
        :header: "", "column 1", "column 2"

        "row 1", "a00", "a10"
        "row 2", "a01", "a11"
        "row 3", "a02", "a12"

    .. csv-table:: mat2x3 **(dest)**
        :header: "", "column 1", "column 2"

        "row 1", "b00 = a00", "b10 = a10"
        "row 2", "b01 = a01", "b11 = a11"
        "row 3", "b02 = a02", "b12 = a12"

.. c:function:: void glm_mat2x3_zero(mat2x3 m)

    Zero out the mat2x3 (m).

    Parameters:
      | *[in, out]* **m** mat2x3 (src, dest)

    .. csv-table:: mat2x3 **(m)**
        :header: "", "column 1", "column 2"

        "row 1", "0.00", "2.00"
        "row 2", "5.00", "4.00"
        "row 3", "7.00", "6.00"

    .. csv-table:: mat2x3 **(m)**
        :header: "", "column 1", "column 2"

        "row 1", "0.00", "0.00"
        "row 2", "0.00", "0.00"
        "row 3", "0.00", "0.00"

.. c:function:: void glm_mat2x3_make(const float * __restrict src, mat2x3 dest)

    Create mat2x3 (dest) from pointer (src).

    .. note:: **@src** must contain at least 6 elements.

    Parameters:
      | *[in]*  **src**  pointer to an array of floats (left)
      | *[out]* **dest** destination (result, mat2x3)

    .. csv-table:: float array (1x6) **(src)**
        :header: "", "column 1"

        "row 1", "v0"
        "row 2", "v1"
        "row 3", "v2"
        "row 4", "v3"
        "row 5", "v4"
        "row 6", "v5"

    .. csv-table:: mat2x3 **(dest)**
        :header: "", "column 1", "column 2"

        "row 1", "v0", "v3"
        "row 2", "v1", "v4"
        "row 3", "v2", "v5"

.. c:function:: void glm_mat2x3_mul(mat2x3 m1, mat3x2 m2, mat3 dest)

    Multiply mat2x3 (m1) by mat3x2 (m2) and store in mat3 (dest).

    .. code-block:: c

       glm_mat2x3_mul(mat2x3, mat3x2, mat3);

    Parameters:
      | *[in]*  **m1**    mat2x3 (left)
      | *[in]*  **m2**    mat3x2 (right)
      | *[out]* **dest**  destination (result, mat3)

    .. csv-table:: mat2x3 **(m1)**
        :header: "", "column 1", "column 2"

        "row 1", "a00", "a10"
        "row 2", "a01", "a11"
        "row 3", "a02", "a12"

    .. csv-table:: mat3x2 **(m2)**
        :header: "", "column 1", "column 2", "column 3"

        "row 1", "b00", "b10", "b20"
        "row 2", "b01", "b11", "b21"

    .. csv-table:: mat3 **(dest)**
        :header: "", "column 1", "column 2", "column 3"

        "row 1", "a00 * b00 + a10 * b01", "a00 * b10 + a10 * b11", "a00 * b20 + a10 * b21"
        "row 2", "a01 * b00 + a11 * b01", "a01 * b10 + a11 * b11", "a01 * b20 + a11 * b21"
        "row 3", "a02 * b00 + a12 * b01", "a02 * b10 + a12 * b11", "a02 * b20 + a12 * b21"

.. c:function:: void glm_mat2x3_mulv(mat2x3 m, vec2 v, vec3 dest)

    Multiply mat2x3 (m) by vec2 (v) and store in vec3 (dest).

    Parameters:
      | *[in]*  **m**    mat2x3 (left)
      | *[in]*  **v**    vec2 (right, column vector)
      | *[out]* **dest** destination (result, column vector)

    .. csv-table:: mat2x3 **(m)**
        :header: "", "column 1", "column 2"

        "row 1", "m00", "m10"
        "row 2", "m01", "m11"
        "row 3", "m02", "m12"

    .. csv-table:: column vec2 (1x2) **(v)**
        :header: "", "column 1"

        "row 1", "v0"
        "row 2", "v1"

    .. csv-table:: column vec3 (1x3) **(dest)**
        :header: "", "column 1"

        "row 1", "m00 * v0 + m10 * v1"
        "row 2", "m01 * v0 + m11 * v1"
        "row 3", "m02 * v0 + m12 * v1"

.. c:function:: void glm_mat2x3_transpose(mat2x3 src, mat3x2 dest)

    Transpose mat2x3 (src) and store in mat3x2 (dest).

    Parameters:
      | *[in]*  **src**  mat2x3 (left)
      | *[out]* **dest** destination (result, mat3x2)

    .. csv-table:: mat2x3 **(src)**
        :header: "", "column 1", "column 2"

        "row 1", "a00", "a10"
        "row 2", "a01", "a11"
        "row 3", "a02", "a12"

    .. csv-table:: mat3x2 **(dest)**
        :header: "", "column 1", "column 2", "column 3"

        "row 1", "b00 = a00", "b10 = a01", "b20 = a02"
        "row 2", "b01 = a10", "b11 = a11", "b21 = a12"

.. c:function:: void glm_mat2x3_scale(mat2x3 m, float s)

    Multiply mat2x3 (m) by scalar constant (s).

    Parameters:
      | *[in, out]* **m** mat2x3 (src, dest)
      | *[in]*      **s** float (scalar)

    .. csv-table:: mat2x3 **(m)**
        :header: "", "column 1", "column 2"

        "row 1", "m00 = m00 * s", "m10 = m10 * s"
        "row 2", "m01 = m01 * s", "m11 = m11 * s"
        "row 3", "m02 = m02 * s", "m12 = m12 * s"
