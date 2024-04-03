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

.. c:function:: void glm_mat2x4_copy(mat2x4 mat, mat2x4 dest)

    copy mat2x4 to another one (dest).

    Parameters:
      | *[in]*  **mat**   source
      | *[out]* **dest**  destination

.. c:function:: void glm_mat2x4_zero(mat2x4 mat)

    make given matrix zero

    Parameters:
      | *[in,out]* **mat**  matrix

.. c:function:: void glm_mat2x4_make(const float * __restrict src, mat2x4 dest)

    Create mat2x4 matrix from pointer

    .. note:: **@src** must contain at least 8 elements.

    Parameters:
      | *[in]*  **src**  pointer to an array of floats
      | *[out]* **dest** destination matrix2x4

.. c:function:: void glm_mat2x4_mul(mat2x4 m1, mat4x2 m2, mat4 dest)

    multiply m1 and m2 to dest

    .. code-block:: c

       glm_mat2x4_mul(mat2x4, mat4x2, mat4);

    Parameters:
      | *[in]*  **m1**    left matrix (mat2x4)
      | *[in]*  **m2**    right matrix (mat4x2)
      | *[out]* **dest**  destination matrix (mat4)

    .. csv-table:: mat2x4
        :header: "", "column 1", "column 2"

        "row 1", "a00", "a10"
        "row 2", "a01", "a11"
        "row 3", "a02", "a12"
        "row 4", "a03", "a13"

    .. csv-table:: mat4x2
        :header: "", "column 1", "column 2", "column 3", "column 4"

        "row 1", "b00", "b10", "b20", "b30"
        "row 2", "b01", "b11", "b21", "b31"

    .. csv-table:: mat4x4
        :header: "", "column 1", "column 2", "column 3", "column 4"

        "row 1", "a00 * b00 + a10 * b01", "a00 * b10 + a10 * b11", "a00 * b20 + a10 * b21", "a00 * b30 + a10 * b31"
        "row 2", "a01 * b00 + a11 * b01", "a01 * b10 + a11 * b11", "a01 * b20 + a11 * b21", "a01 * b30 + a11 * b31"
        "row 3", "a02 * b00 + a12 * b01", "a02 * b10 + a12 * b11", "a02 * b20 + a12 * b21", "a02 * b30 + a12 * b31"
        "row 4", "a03 * b00 + a13 * b01", "a03 * b10 + a13 * b11", "a03 * b20 + a13 * b21", "a03 * b30 + a13 * b31"

.. c:function:: void glm_mat2x4_mulv(mat2x4 m, vec2 v, vec4 dest)

    multiply mat2x4 with vec2 (column vector) and store in dest column vector

    Parameters:
      | *[in]*  **m**     mat2x4 (left)
      | *[in]*  **v**     vec2 (right, column vector)
      | *[out]* **dest**  destination (result, column vector)

    .. csv-table:: mat2x4
        :header: "", "column 1", "column 2"

        "row 1", "m00", "m10"
        "row 2", "m01", "m11"
        "row 3", "m02", "m12"
        "row 4", "m03", "m13"

    .. csv-table:: column vec2 (1x2)
        :header: "", "column 1"

        "row 1", "v0"
        "row 2", "v1"

    .. csv-table:: column vec4 (1x4)
        :header: "", "column 1"

        "row 1", "m00 * v0 + m10 * v1"
        "row 2", "m01 * v0 + m11 * v1"
        "row 3", "m02 * v0 + m12 * v1"
        "row 4", "m03 * v0 + m13 * v1"

.. c:function:: void glm_mat2x4_transpose(mat2x4 m, mat4x2 dest)

    transpose matrix and store in dest

    Parameters:
      | *[in]*  **m**     matrix
      | *[out]* **dest**  destination

.. c:function:: void  glm_mat2x4_scale(mat2x4 m, float s)

    multiply matrix with scalar

    Parameters:
      | *[in, out]* **m** matrix
      | *[in]*      **s** scalar
