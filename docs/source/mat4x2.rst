.. default-domain:: C

mat4x2
======

Header: cglm/mat4x2.h

Table of contents (click to go):
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

Macros:

1. GLM_MAT4X2_ZERO_INIT
#. GLM_MAT4X2_ZERO

Functions:

1. :c:func:`glm_mat4x2_copy`
#. :c:func:`glm_mat4x2_zero`
#. :c:func:`glm_mat4x2_make`
#. :c:func:`glm_mat4x2_mul`
#. :c:func:`glm_mat4x2_mulv`
#. :c:func:`glm_mat4x2_transpose`
#. :c:func:`glm_mat4x2_scale`

Represented
~~~~~~~~~~~

.. csv-table:: mat4x2
   :header: "", "column 1", "column 2", "column 3", "column4"

   "row 1", "m00", "m10", "m20", "m30"
   "row 2", "m01", "m11", "m21", "m31"

Functions documentation
~~~~~~~~~~~~~~~~~~~~~~~

.. c:function:: void glm_mat4x2_copy(mat4x2 mat, mat4x2 dest)

    copy mat4x2 to another one (dest).

    Parameters:
      | *[in]*  **mat**   source
      | *[out]* **dest**  destination

.. c:function:: void glm_mat4x2_zero(mat4x2 mat)

    make given matrix zero

    Parameters:
      | *[in,out]* **mat**  matrix

.. c:function:: void glm_mat4x2_make(const float * __restrict src, mat4x2 dest)

    Create mat4x2 matrix from pointer

    .. note:: **@src** must contain at least 8 elements.

    Parameters:
      | *[in]*  **src**  pointer to an array of floats
      | *[out]* **dest** destination matrix4x2

.. c:function:: void glm_mat4x2_mul(mat4x2 m1, mat2x4 m2, mat2 dest)

    multiply m1 and m2 to dest

    .. code-block:: c

       glm_mat4x2_mul(mat4x2, mat2x4, mat2);

    Parameters:
      | *[in]*  **m1**    left matrix (mat4x2)
      | *[in]*  **m2**    right matrix (mat2x4)
      | *[out]* **dest**  destination matrix (mat2)

    .. csv-table:: mat4x2
        :header: "", "column 1", "column 2", "column 3", "column 4"

        "row 1", "a00", "a10", "a20", "a30"
        "row 2", "a01", "a11", "a21", "a31"

    .. csv-table:: mat2x4
        :header: "", "column 1", "column 2"

        "row 1", "b00", "b10"
        "row 2", "b01", "b11"
        "row 3", "b02", "b12"
        "row 4", "b03", "b13"

    .. csv-table:: mat2x2
        :header: "", "column 1", "column 2"

        "row 1", "a00 * b00 + a10 * b01 + a20 * b02 + a30 * b03", "a00 * b10 + a10 * b11 + a20 * b12 + a30 * b13"
        "row 2", "a01 * b00 + a11 * b01 + a21 * b02 + a31 * b03", "a01 * b10 + a11 * b11 + a21 * b12 + a31 * b13"

.. c:function:: void glm_mat4x2_mulv(mat4x2 m, vec4 v, vec2 dest)

    multiply mat4x2 with vec4 (column vector) and store in dest vector

    Parameters:
      | *[in]*  **m**     mat4x2 (left)
      | *[in]*  **v**     vec4 (right, column vector)
      | *[out]* **dest**  destination (result, column vector)

    .. csv-table:: mat4x2
        :header: "", "column 1", "column 2", "column 3"

        "row 1", "m00", "m10", "m20"
        "row 2", "m01", "m11", "m21"
        "row 3", "m02", "m12", "m22"
        "row 4", "m03", "m13", "m23"

    .. csv-table:: column vec4 (1x4)
        :header: "", "column 1"

        "row 1", "v0"
        "row 2", "v1"
        "row 3", "v2"
        "row 4", "v3"

    .. csv-table:: column vec2 (1x2)
        :header: "", "column 1"

        "row 1", "m00 * v0 + m10 * v1 + m20 * v2 + m30 * v3"
        "row 2", "m01 * v0 + m11 * v1 + m21 * v2 + m31 * v3"

.. c:function:: void glm_mat4x2_transpose(mat4x2 m, mat2x4 dest)

    transpose matrix and store in dest

    Parameters:
      | *[in]*  **m**     matrix
      | *[out]* **dest**  destination

.. c:function:: void  glm_mat4x2_scale(mat4x2 m, float s)

    multiply matrix with scalar

    Parameters:
      | *[in, out]* **m** matrix
      | *[in]*      **s** scalar
