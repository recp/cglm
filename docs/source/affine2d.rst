.. default-domain:: C

2D Affine Transforms
================================================================================

Header: cglm/affine2d.h

2D Transforms uses `2d` suffix for naming. If there is no 2D suffix it is 3D function.

Initialize Transform Matrices
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
Functions with **_make** prefix expect you don't have a matrix and they create
a matrix for you. You don't need to pass identity matrix.

But other functions expect you have a matrix and you want to transform them. If
you didn't have any existing matrix you have to initialize matrix to identity
before sending to transform functions.

Transforms Order
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

See :ref:`TransformsOrder` to read similar section.


Table of contents (click to go):
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

Functions:

1. :c:func:`glm_translate2d`
#. :c:func:`glm_translate2d_to`
#. :c:func:`glm_translate2d_x`
#. :c:func:`glm_translate2d_y`
#. :c:func:`glm_translate2d_make`
#. :c:func:`glm_scale2d_to`
#. :c:func:`glm_scale2d_make`
#. :c:func:`glm_scale2d`
#. :c:func:`glm_scale2d_uni`
#. :c:func:`glm_rotate2d_make`
#. :c:func:`glm_rotate2d`
#. :c:func:`glm_rotate2d_to`

.. c:function:: void glm_translate2d(mat3 m, vec2 v)

    translate existing 2d transform matrix by *v* vector and stores result in same matrix

    Parameters:
      | *[in, out]*  **m**    2d affine transform
      | *[in]*       **v**    translate vector [x, y]

.. c:function:: void glm_translate2d_to(mat3 m, vec2 v, mat3 dest)

    translate existing 2d transform matrix by *v* vector and store result in dest

    Parameters:
      | *[in]*  **m**    2d affine transform
      | *[in]*  **v**    translate vector [x, y]
      | *[out]* **dest** translated matrix

.. c:function:: void glm_translate2d_x(mat3 m, float x)

    translate existing 2d transform matrix by x factor

    Parameters:
      | *[in, out]*  **m**    2d affine transform
      | *[in]*       **x**    x factor

.. c:function:: void glm_translate2d_y(mat3 m, float y)

    translate existing 2d transform matrix by y factor

    Parameters:
      | *[in, out]*  **m**    2d affine transform
      | *[in]*       **y**    y factor

.. c:function:: void glm_translate2d_make(mat3 m, vec2 v)

    creates NEW translate 2d transform matrix by *v* vector

    Parameters:
      | *[in, out]*  **m**    affine transform
      | *[in]*       **v**    translate vector [x, y]

.. c:function:: void glm_scale2d_to(mat3 m, vec2 v, mat3 dest)

    scale existing 2d transform matrix by *v* vector and store result in dest

    Parameters:
      | *[in]*  **m**    affine transform
      | *[in]*  **v**    scale vector [x, y]
      | *[out]* **dest** scaled matrix

.. c:function:: void glm_scale2d_make(mat3 m, vec2 v)

    creates NEW 2d scale matrix by *v* vector

    Parameters:
      | *[in, out]*  **m**    affine transform
      | *[in]*       **v**    scale vector [x, y]

.. c:function:: void glm_scale2d(mat3 m, vec2 v)

    scales existing 2d transform matrix by *v* vector and stores result in same matrix

    Parameters:
      | *[in, out]*  **m**    affine transform
      | *[in]*       **v**    translate vector [x, y]

.. c:function:: void glm_scale2d_uni(mat3 m, float s)

    applies uniform scale to existing 2d transform matrix v = [s, s] and stores result in same matrix

    Parameters:
      | *[in, out]*  **m**  affine transform
      | *[in]*       **s**  scale factor

.. c:function:: void glm_rotate2d_make(mat3 m, float angle)

    creates NEW rotation matrix by angle around *Z* axis

    Parameters:
      | *[in, out]*  **m**      affine transform
      | *[in]*       **angle**  angle (radians)

.. c:function:: void glm_rotate2d(mat3 m, float angle)

    rotate existing 2d transform matrix around *Z* axis by angle and store result in same matrix

    Parameters:
      | *[in, out]*  **m**      affine transform
      | *[in]*       **angle**  angle (radians)

.. c:function:: void glm_rotate2d_to(mat3 m, float angle, mat3 dest)

    rotate existing 2d transform matrix around *Z* axis by angle and store result in dest

    Parameters:
      | *[in]*  **m**      affine transform
      | *[in]*  **angle**  angle (radians)
      | *[out]* **dest**   rotated matrix