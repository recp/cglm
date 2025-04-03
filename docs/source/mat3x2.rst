.. default-domain:: C

mat3x2
======

Header: cglm/mat3x2.h

Table of contents (click to go):
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

Macros:

1. GLM_MAT3X2_ZERO_INIT
#. GLM_MAT3X2_ZERO

Functions:

1. :c:func:`glm_mat3x2_copy`
#. :c:func:`glm_mat3x2_zero`
#. :c:func:`glm_mat3x2_make`
#. :c:func:`glm_mat3x2_mul`
#. :c:func:`glm_mat3x2_mulv`
#. :c:func:`glm_mat3x2_transpose`
#. :c:func:`glm_mat3x2_scale`

Represented
~~~~~~~~~~~

.. csv-table:: mat3x2
   :header: "", "column 1", "column 2", "column 3"

   "row 1", "m00", "m10", "m20"
   "row 2", "m01", "m11", "m21"

Functions documentation
~~~~~~~~~~~~~~~~~~~~~~~

.. c:function:: void glm_mat3x2_copy(mat3x2 src, mat3x2 dest)

    Copy mat3x2 (src) to mat3x2 (dest).

    Parameters:
      | *[in]*  **src**  mat3x2 (left)
      | *[out]* **dest** destination (result, mat3x2)

    .. csv-table:: mat3x2 **(src)**
        :header: "", "column 1", "column 2", "column 3"

        "row 1", "a00", "a10", "a20"
        "row 2", "a01", "a11", "a21"

    .. csv-table:: mat3x2 **(dest)**
        :header: "", "column 1", "column 2", "column 3"

        "row 1", "b00 = a00", "b10 = a10", "b20 = a20"
        "row 2", "b01 = a01", "b11 = a11", "b21 = a21"

.. c:function:: void glm_mat3x2_zero(mat3x2 m)

    Zero out the mat3x2 (m).

    Parameters:
      | *[in, out]* **m** mat3x2 (src, dest)

    .. csv-table:: mat3x2 **(m)**
        :header: "", "column 1", "column 2", "column 3"

        "row 1", "0.00", "2.00", "15.00"
        "row 2", "5.00", "4.00", "6.00"

    .. csv-table:: mat3x2 **(m)**
        :header: "", "column 1", "column 2", "column 3"

        "row 1", "0.00", "0.00", "0.00"
        "row 2", "0.00", "0.00", "0.00"

.. c:function:: void glm_mat3x2_make(const float * __restrict src, mat3x2 dest)

    Create mat3x2 (dest) from pointer (src).

    .. note:: **@src** must contain at least 6 elements.

    Parameters:
      | *[in]*  **src**  pointer to an array of floats (left)
      | *[out]* **dest** destination (result, mat3x2)

    .. csv-table:: float array (1x6) **(src)**
        :header: "", "column 1"

        "row 1", "v0"
        "row 2", "v1"
        "row 3", "v2"
        "row 4", "v3"
        "row 5", "v4"
        "row 6", "v5"

    .. csv-table:: mat3x2 **(dest)**
        :header: "", "column 1", "column 2", "column 3"

        "row 1", "v0", "v2", "v4"
        "row 2", "v1", "v3", "v5"

.. c:function:: void glm_mat3x2_mul(mat3x2 m1, mat2x3 m2, mat2 dest)

    Multiply mat3x2 (m1) by mat2x3 (m2) and store in mat2 (dest).

    .. code-block:: c

       glm_mat3x2_mul(mat3x2, mat2x3, mat2);

    Parameters:
      | *[in]*  **m1**    mat3x2 (left)
      | *[in]*  **m2**    mat2x3 (right)
      | *[out]* **dest**  destination (result, mat2)

    .. csv-table:: mat3x2 **(m1)**
        :header: "", "column 1", "column 2", "column 3"

        "row 1", "a00", "a10", "a20"
        "row 2", "a01", "a11", "a21"

    .. csv-table:: mat2x3 **(m2)**
        :header: "", "column 1", "column 2"

        "row 1", "b00", "b10"
        "row 2", "b01", "b11"
        "row 3", "b02", "b12"

    .. csv-table:: mat2x2 **(dest)**
        :header: "", "column 1", "column 2"

        "row 1", "a00 * b00 + a10 * b01 + a20 * b02", "a00 * b10 + a10 * b11 + a20 * b12"
        "row 2", "a01 * b00 + a11 * b01 + a21 * b02", "a01 * b10 + a11 * b11 + a21 * b12"

.. c:function:: void glm_mat3x2_mulv(mat3x2 m, vec3 v, vec2 dest)

    Multiply mat3x2 (m) by vec3 (v) and store in vec2 (dest).

    Parameters:
      | *[in]*  **m**    mat3x2 (left)
      | *[in]*  **v**    vec3 (right, column vector)
      | *[out]* **dest** destination (result, column vector)

    .. csv-table:: mat3x2 **(m)**
        :header: "", "column 1", "column 2", "column 3"

        "row 1", "m00", "m10", "m20"
        "row 2", "m01", "m11", "m21"

    .. csv-table:: column vec3 (1x3) **(v)**
        :header: "", "column 1"

        "row 1", "v0"
        "row 2", "v1"
        "row 3", "v2"

    .. csv-table:: column vec2 (1x2) **(dest)**
        :header: "", "column 1"

        "row 1", "m00 * v0 + m10 * v1 + m20 * v2"
        "row 2", "m01 * v0 + m11 * v1 + m21 * v2"

.. c:function:: void glm_mat3x2_transpose(mat3x2 src, mat2x3 dest)

    Transpose mat3x2 (src) and store in mat2x3 (dest).

    Parameters:
      | *[in]*  **src**  mat3x2 (left)
      | *[out]* **dest** destination (result, mat2x3)

    .. csv-table:: mat3x2 **(src)**
        :header: "", "column 1", "column 2", "column 3"

        "row 1", "a00", "a10", "a20"
        "row 2", "a01", "a11", "a21"

    .. csv-table:: mat2x3 **(dest)**
        :header: "", "column 1", "column 2"

        "row 1", "b00 = a00", "b10 = a01"
        "row 2", "b01 = a10", "b11 = a11"
        "row 3", "b02 = a20", "b12 = a21"

.. c:function:: void glm_mat3x2_scale(mat3x2 m, float s)

    Multiply mat3x2 (m) by scalar constant (s).

    Parameters:
      | *[in, out]* **m** mat3x2 (src, dest)
      | *[in]*      **s** float (scalar)

    .. csv-table:: mat3x2 **(m)**
        :header: "", "column 1", "column 2", "column 3"

        "row 1", "m00 = m00 * s", "m10 = m10 * s", "m20 = m20 * s"
        "row 2", "m01 = m01 * s", "m11 = m11 * s", "m21 = m21 * s"
