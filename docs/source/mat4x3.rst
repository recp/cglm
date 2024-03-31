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
   :header: "", "column 1", "column 2", "column 3", "column4"

   "row 1", "m00", "m10", "m20", "m30"
   "row 2", "m01", "m11", "m21", "m31"
   "row 3", "m02", "m12", "m22", "m32"

Functions documentation
~~~~~~~~~~~~~~~~~~~~~~~

.. c:function:: void glm_mat4x3_copy(mat4x3 mat, mat4x3 dest)

    copy mat4x3 to another one (dest).

    Parameters:
      | *[in]*  **mat**   source
      | *[out]* **dest**  destination

.. c:function:: void glm_mat4x3_zero(mat4x3 mat)

    make given matrix zero

    Parameters:
      | *[in,out]* **mat**  matrix

.. c:function:: void glm_mat4x3_make(const float * __restrict src, mat4x3 dest)

    Create mat4x3 matrix from pointer

    .. note:: **@src** must contain at least 12 elements.

    Parameters:
      | *[in]*  **src**  pointer to an array of floats
      | *[out]* **dest** destination matrix4x3

.. c:function:: void glm_mat4x3_mul(mat4x3 m1, mat3x4 m2, mat3 dest)

    multiply m1 and m2 to dest

    .. code-block:: c

       glm_mat4x3_mul(mat4x3, mat3x4, mat3);

    Parameters:
      | *[in]*  **m1**    left matrix (mat4x3)
      | *[in]*  **m2**    right matrix (mat3x4)
      | *[out]* **dest**  destination matrix (mat3)

    .. csv-table:: mat4x3
        :header: "", "column 1", "column 2", "column 3", "column 4"

        "row 1", "a00", "a10", "a20", "a30"
        "row 2", "a01", "a11", "a21", "a31"
        "row 3", "a02", "a12", "a22", "a32"

    .. csv-table:: mat3x4
        :header: "", "column 1", "column 2", "column 3"

        "row 1", "b00", "b10", "b20"
        "row 2", "b01", "b11", "b21"
        "row 3", "b02", "b12", "b22"
        "row 4", "b03", "b13", "b23"

    .. csv-table:: mat3x3
        :header: "", "column 1", "column 2", "column 3"

        "row 1", "a00 * b00 + a10 * b01 + a20 * b02 + a30 * b03", "a00 * b10 + a10 * b11 + a20 * b12 + a30 * b13", "a00 * b20 + a10 * b21 + a20 * b22 + a30 * b23"
        "row 2", "a01 * b00 + a11 * b01 + a21 * b02 + a31 * b03", "a01 * b10 + a11 * b11 + a21 * b12 + a31 * b13", "a01 * b20 + a11 * b21 + a21 * b22 + a31 * b23"
        "row 3", "a02 * b00 + a12 * b01 + a22 * b02 + a32 * b03", "a02 * b10 + a12 * b11 + a22 * b12 + a32 * b13", "a02 * b20 + a12 * b21 + a22 * b22 + a32 * b23"

.. c:function:: void glm_mat4x3_mulv(mat4x3 m, vec4 v, vec3 dest)

    multiply mat4x3 with vec4 (column vector) and store in dest column vector

    Parameters:
      | *[in]*  **m**     mat4x3 (left)
      | *[in]*  **v**     vec4 (right, column vector)
      | *[out]* **dest**  destination (result, column vector)

    .. csv-table:: mat4x3
        :header: "", "column 1", "column 2", "column 3", "column 4"

        "row 1", "m00", "m10", "m20", "m30"
        "row 2", "m01", "m11", "m21", "m31"
        "row 3", "m02", "m12", "m22", "m32"

    .. csv-table:: column vec4 (1x4)
        :header: "", "column 1"

        "row 1", "v0"
        "row 2", "v1"
        "row 3", "v2"
        "row 4", "v3"

    .. csv-table:: column vec3 (1x3)
        :header: "", "column 1"

        "row 1", "m00 * v0 + m10 * v1 + m20 * v2 + m30 * v3"
        "row 2", "m01 * v0 + m11 * v1 + m21 * v2 + m31 * v3"
        "row 3", "m02 * v0 + m12 * v1 + m22 * v2 + m32 * v3"

.. c:function:: void glm_mat4x3_transpose(mat4x3 m, mat3x4 dest)

    transpose matrix and store in dest

    Parameters:
      | *[in]*  **m**     matrix
      | *[out]* **dest**  destination

.. c:function:: void  glm_mat4x3_scale(mat4x3 m, float s)

    multiply matrix with scalar

    Parameters:
      | *[in, out]* **m** matrix
      | *[in]*      **s** scalar
