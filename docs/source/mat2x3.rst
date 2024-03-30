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

.. c:function:: void glm_mat2x3_copy(mat2x3 mat, mat2x3 dest)

    copy mat2x3 to another one (dest).

    Parameters:
      | *[in]*  **mat**   source
      | *[out]* **dest**  destination

.. c:function:: void glm_mat2x3_zero(mat2x3 mat)

    make given matrix zero

    Parameters:
      | *[in,out]* **mat**  matrix

.. c:function:: void glm_mat2x3_make(const float * __restrict src, mat2x3 dest)

    Create mat2x3 matrix from pointer

    .. note:: **@src** must contain at least 6 elements.

    Parameters:
      | *[in]*  **src**  pointer to an array of floats
      | *[out]* **dest** destination matrix2x3

.. c:function:: void glm_mat2x3_mul(mat2x3 m1, mat3x2 m2, mat3 dest)

    multiply m1 and m2 to dest

    .. code-block:: c

       glm_mat2x3_mul(mat2x3, mat3x2, mat3);

    Parameters:
      | *[in]*  **m1**    left matrix (mat2x3)
      | *[in]*  **m2**    right matrix (mat3x2)
      | *[out]* **dest**  destination matrix (mat3)

    .. csv-table:: mat2x3
        :header: "", "column 1", "column 2"

        "row 1", "a00", "a10"
        "row 2", "a01", "a11"
        "row 3", "a02", "a12"

    .. csv-table:: mat3x2
        :header: "", "column 1", "column 2", "column 3"

        "row 1", "b00", "b10", "b20"
        "row 2", "b01", "b11", "b21"

    .. csv-table:: mat3x3
        :header: "", "column 1", "column 2", "column 3"

        "row 1", "a00 * b00 + a10 * b01", "a00 * b10 + a10 * b11", "a00 * b20 + a10 * b21"
        "row 2", "a01 * b00 + a11 * b01", "a01 * b10 + a11 * b11", "a01 * b20 + a11 * b21"
        "row 3", "a02 * b00 + a12 * b01", "a02 * b10 + a12 * b11", "a02 * b20 + a12 * b21"

.. c:function:: void glm_mat2x3_mulv(mat2x3 m, vec2 v, vec3 dest)

    multiply mat2x3 with vec2 (column vector) and store in dest column vector

    Parameters:
      | *[in]*  **m**     mat2x3 (left)
      | *[in]*  **v**     vec3 (right, column vector)
      | *[out]* **dest**  destination (result, column vector)

    .. csv-table:: mat2x3
        :header: "", "column 1", "column 2"

        "row 1", "m00", "m10"
        "row 2", "m01", "m11"
        "row 3", "m02", "m12"

    .. csv-table:: column vec2 (1x2)
        :header: "", "column 1"

        "row 1", "v0"
        "row 2", "v1"

    .. csv-table:: column vec3 (1x3)
        :header: "", "column 1"

        "row 1", "m00 * v0 + m10 * v1"
        "row 2", "m01 * v0 + m11 * v1"
        "row 3", "m02 * v0 + m12 * v1"

.. c:function:: void glm_mat2x3_transpose(mat2x3 m, mat3x2 dest)

    transpose matrix and store in dest

    Parameters:
      | *[in]*  **m**     matrix
      | *[out]* **dest**  destination

.. c:function:: void  glm_mat2x3_scale(mat2x3 m, float s)

    multiply matrix with scalar

    Parameters:
      | *[in, out]* **m** matrix
      | *[in]*      **s** scalar
