.. default-domain:: C

3D Affine Transform Matrix (specialized functions)
================================================================================

Header: cglm/affine-mat.h

We mostly use glm_mat4_* for 4x4 general and transform matrices. **cglm**
provides optimized version of some functions. Because affine transform matrix is
a known format, for instance all last item of first three columns is zero.

You should be careful when using these functions. For instance :c:func:`glm_mul`
assumes matrix will be this format:

.. code-block:: text

   R  R  R  X
   R  R  R  Y
   R  R  R  Z
   0  0  0  W

if you override zero values here then use :c:func:`glm_mat4_mul` version.
You cannot use :c:func:`glm_mul` anymore.

Same is also true for :c:func:`glm_inv_tr` if you only have rotation and
translation then it will work as expected, otherwise you cannot use that.

In the future it may accept scale factors too but currectly it does not.

Table of contents (click func go):
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

Functions:

1. :c:func:`glm_mul`
#. :c:func:`glm_mul_rot`
#. :c:func:`glm_inv_tr`

Functions documentation
~~~~~~~~~~~~~~~~~~~~~~~

.. c:function:: void  glm_mul(mat4 m1, mat4 m2, mat4 dest)

    | this is similar to glm_mat4_mul but specialized to affine transform

    Matrix format should be:

    .. code-block:: text

       R  R  R  X
       R  R  R  Y
       R  R  R  Z
       0  0  0  W

    this reduces some multiplications. It should be faster than mat4_mul.
    if you are not sure about matrix format then DON'T use this! use mat4_mul

    Parameters:
      | *[in]*  **m1**    affine matrix 1
      | *[in]*  **m2**    affine matrix 2
      | *[out]* **dest**  result matrix

.. c:function:: void  glm_mul_rot(mat4 m1, mat4 m2, mat4 dest)

    | this is similar to glm_mat4_mul but specialized to rotation matrix

    Right Matrix format should be (left is free):

    .. code-block:: text

       R  R  R  0
       R  R  R  0
       R  R  R  0
       0  0  0  1

    this reduces some multiplications. It should be faster than mat4_mul.
    if you are not sure about matrix format then DON'T use this! use mat4_mul

    Parameters:
      | *[in]*  **m1**    affine matrix 1
      | *[in]*  **m2**    affine matrix 2
      | *[out]* **dest**  result matrix

.. c:function:: void  glm_inv_tr(mat4 mat)

    | inverse orthonormal rotation + translation matrix (ridig-body)

    .. code-block:: text

       X = | R  T |   X' = | R' -R'T |
           | 0  1 |        | 0     1 |

    use this if you only have rotation + translation, this should work faster
    than :c:func:`glm_mat4_inv`

    Don't use this if your matrix includes other things e.g. scale, shear...

    Parameters:
      | *[in,out]*  **mat**  affine matrix
