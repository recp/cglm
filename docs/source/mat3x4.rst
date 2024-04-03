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

.. c:function:: void glm_mat3x4_copy(mat3x4 mat, mat3x4 dest)

    copy mat3x4 to another one (dest).

    Parameters:
      | *[in]*  **mat**   source
      | *[out]* **dest**  destination

.. c:function:: void glm_mat3x4_zero(mat3x4 mat)

    make given matrix zero

    Parameters:
      | *[in,out]* **mat**  matrix

.. c:function:: void glm_mat3x4_make(const float * __restrict src, mat3x4 dest)

    Create mat3x4 matrix from pointer

    .. note::: **@src** must contain at least 12 elements.

    Parameters:
      | *[in]*  **src**  pointer to an array of floats
      | *[out]* **dest** destination matrix3x4

.. c:function:: void glm_mat3x4_mul(mat3x4 m1, mat4x3 m2, mat4 dest)

    multiply m1 and m2 to dest

    .. code-block:: c

       glm_mat3x4_mul(mat3x4, mat4x3, mat4);

    Parameters:
      | *[in]*  **m1**    left matrix (mat3x4)
      | *[in]*  **m2**    right matrix (mat4x3)
      | *[out]* **dest**  destination matrix (mat4)

    .. csv-table:: mat3x4
        :header: "", "column 1", "column 2", "column 3"

        "row 1", "a00", "a10", "a20"
        "row 2", "a01", "a11", "a21"
        "row 3", "a02", "a12", "a22"
        "row 4", "a03", "a13", "a23"

    .. csv-table:: mat4x3
        :header: "", "column 1", "column 2", "column 3", "column 4"

        "row 1", "b00", "b10", "b20", "b30"
        "row 2", "b01", "b11", "b21", "b31"
        "row 3", "b02", "b12", "b22", "b32"

    .. csv-table:: mat4x4
        :header: "", "column 1", "column 2", "column 3", "column 4"

        "row 1", "a00 * b00 + a10 * b01 + a20 * b02", "a00 * b10 + a10 * b11 + a20 * b12", "a00 * b20 + a10 * b21 + a20 * b22", "a00 * b30 + a10 * b31 + a20 * b32"
        "row 2", "a01 * b00 + a11 * b01 + a21 * b02", "a01 * b10 + a11 * b11 + a21 * b12", "a01 * b20 + a11 * b21 + a21 * b22", "a01 * b30 + a11 * b31 + a21 * b32"
        "row 3", "a02 * b00 + a12 * b01 + a22 * b02", "a02 * b10 + a12 * b11 + a22 * b12", "a02 * b20 + a12 * b21 + a22 * b22", "a02 * b30 + a12 * b31 + a22 * b32"
        "row 4", "a03 * b00 + a13 * b01 + a23 * b02", "a03 * b10 + a13 * b11 + a23 * b12", "a03 * b20 + a13 * b21 + a23 * b22", "a03 * b30 + a13 * b31 + a23 * b32"

.. c:function:: void glm_mat3x4_mulv(mat3x4 m, vec3 v, vec4 dest)

    multiply mat3x4 with vec3 (column vector) and store in dest vector

    Parameters:
      | *[in]*  **m**     mat3x4 (left)
      | *[in]*  **v**     vec3 (right, column vector)
      | *[out]* **dest**  destination (result, column vector)

    .. csv-table:: mat3x4
        :header: "", "column 1", "column 2", "column 3"

        "row 1", "m00", "m10", "m20"
        "row 2", "m01", "m11", "m21"
        "row 3", "m02", "m12", "m22"
        "row 4", "m03", "m13", "m23"

    .. csv-table:: column vec3 (1x3)
        :header: "", "column 1"

        "row 1", "v0"
        "row 2", "v1"
        "row 3", "v2"

    .. csv-table:: column vec4 (1x4)
        :header: "", "column 1"

        "row 1", "m00 * v0 + m10 * v1 + m20 * v2"
        "row 2", "m01 * v0 + m11 * v1 + m21 * v2"
        "row 3", "m02 * v0 + m12 * v1 + m22 * v2"
        "row 4", "m03 * v0 + m13 * v1 + m23 * v2"

.. c:function:: void glm_mat3x4_transpose(mat3x4 m, mat4x3 dest)

    transpose matrix and store in dest

    Parameters:
      | *[in]*  **m**     matrix
      | *[out]* **dest**  destination

.. c:function:: void  glm_mat3x4_scale(mat3x4 m, float s)

    multiply matrix with scalar

    Parameters:
      | *[in, out]* **m** matrix
      | *[in]*      **s** scalar
