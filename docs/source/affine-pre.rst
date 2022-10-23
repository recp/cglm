.. default-domain:: C

3D Affine Transforms (pre)
================================================================================

Pre transfrom functions which are regular transfrom functions.

Table of contents (click to go):
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

Functions:

1. :c:func:`glm_translate_to`
#. :c:func:`glm_translate`
#. :c:func:`glm_translate_x`
#. :c:func:`glm_translate_y`
#. :c:func:`glm_translate_z`
#. :c:func:`glm_translate_make`
#. :c:func:`glm_scale_to`
#. :c:func:`glm_scale_make`
#. :c:func:`glm_scale`
#. :c:func:`glm_scale_uni`
#. :c:func:`glm_rotate_x`
#. :c:func:`glm_rotate_y`
#. :c:func:`glm_rotate_z`
#. :c:func:`glm_rotate_make`
#. :c:func:`glm_rotate`
#. :c:func:`glm_rotate_at`
#. :c:func:`glm_rotate_atm`
#. :c:func:`glm_decompose_scalev`
#. :c:func:`glm_uniscaled`
#. :c:func:`glm_decompose_rs`
#. :c:func:`glm_decompose`
#. :c:func:`glm_spin`

Functions documentation
~~~~~~~~~~~~~~~~~~~~~~~

.. c:function:: void  glm_translate_to(mat4 m, vec3 v, mat4 dest)

    translate existing transform matrix by *v* vector and store result in dest

    Parameters:
      | *[in]*  **m**    affine transfrom
      | *[in]*  **v**    translate vector [x, y, z]
      | *[out]* **dest** translated matrix

.. c:function:: void  glm_translate(mat4 m, vec3 v)

    translate existing transform matrix by *v* vector
    and stores result in same matrix

    Parameters:
      | *[in, out]* **m**  affine transfrom
      | *[in]*      **v**  translate vector [x, y, z]

.. c:function:: void  glm_translate_x(mat4 m, float x)

    translate existing transform matrix by x factor

    Parameters:
      | *[in, out]* **m**  affine transfrom
      | *[in]*      **v**  x factor

.. c:function:: void  glm_translate_y(mat4 m, float y)

    translate existing transform matrix by *y* factor

    Parameters:
      | *[in, out]* **m**  affine transfrom
      | *[in]*      **v**  y factor

.. c:function:: void  glm_translate_z(mat4 m, float z)

    translate existing transform matrix by *z* factor

    Parameters:
      | *[in, out]* **m**  affine transfrom
      | *[in]*      **v**  z factor

.. c:function:: void  glm_translate_make(mat4 m, vec3 v)

    creates NEW translate transform matrix by *v* vector.

    Parameters:
      | *[in, out]* **m**  affine transfrom
      | *[in]*      **v**  translate vector [x, y, z]

.. c:function:: void  glm_scale_to(mat4 m, vec3 v, mat4 dest)

    scale existing transform matrix by *v* vector and store result in dest

    Parameters:
      | *[in]*  **m**    affine transfrom
      | *[in]*  **v**    scale vector [x, y, z]
      | *[out]* **dest** scaled matrix

.. c:function:: void  glm_scale_make(mat4 m, vec3 v)

    creates NEW scale matrix by v vector

    Parameters:
      | *[out]* **m** affine transfrom
      | *[in]*  **v** scale vector [x, y, z]

.. c:function:: void  glm_scale(mat4 m, vec3 v)

    scales existing transform matrix by v vector
    and stores result in same matrix

    Parameters:
      | *[in, out]* **m** affine transfrom
      | *[in]*      **v** scale vector [x, y, z]

.. c:function:: void  glm_scale_uni(mat4 m, float s)

    applies uniform scale to existing transform matrix v = [s, s, s]
    and stores result in same matrix

    Parameters:
      | *[in, out]* **m** affine transfrom
      | *[in]*      **v** scale factor

.. c:function:: void  glm_rotate_x(mat4 m, float angle, mat4 dest)

    rotate existing transform matrix around X axis by angle
    and store result in dest

    Parameters:
      | *[in]*  **m**     affine transfrom
      | *[in]*  **angle** angle (radians)
      | *[out]* **dest**  rotated matrix

.. c:function:: void  glm_rotate_y(mat4 m, float angle, mat4 dest)

    rotate existing transform matrix around Y axis by angle
    and store result in dest

    Parameters:
      | *[in]*  **m**     affine transfrom
      | *[in]*  **angle** angle (radians)
      | *[out]* **dest**  rotated matrix

.. c:function:: void  glm_rotate_z(mat4 m, float angle, mat4 dest)

    rotate existing transform matrix around Z axis by angle
    and store result in dest

    Parameters:
      | *[in]*  **m**     affine transfrom
      | *[in]*  **angle** angle (radians)
      | *[out]* **dest**  rotated matrix

.. c:function:: void  glm_rotate_make(mat4 m, float angle, vec3 axis)

    creates NEW rotation matrix by angle and axis,
    axis will be normalized so you don't need to normalize it

    Parameters:
      | *[out]* **m**    affine transfrom
      | *[in]*  **axis** angle (radians)
      | *[in]*  **axis** axis

.. c:function:: void  glm_rotate(mat4 m, float angle, vec3 axis)

    rotate existing transform matrix around Z axis by angle and axis

    Parameters:
      | *[in, out]* **m**     affine transfrom
      | *[in]*      **angle** angle (radians)
      | *[in]*      **axis**  axis

.. c:function:: void  glm_rotate_at(mat4 m, vec3 pivot, float angle, vec3 axis)

    rotate existing transform around given axis by angle at given pivot point (rotation center)

    Parameters:
      | *[in, out]* **m**     affine transfrom
      | *[in]*      **pivot** pivot, anchor point, rotation center
      | *[in]*      **angle** angle (radians)
      | *[in]*      **axis**  axis

.. c:function:: void  glm_rotate_atm(mat4 m, vec3 pivot, float angle, vec3 axis)

    | creates NEW rotation matrix by angle and axis at given point
    | this creates rotation matrix, it assumes you don't have a matrix

    | this should work faster than glm_rotate_at because it reduces one glm_translate.

    Parameters:
      | *[in, out]* **m**     affine transfrom
      | *[in]*      **pivot** pivot, anchor point, rotation center
      | *[in]*      **angle** angle (radians)
      | *[in]*      **axis**  axis

.. c:function:: void  glm_decompose_scalev(mat4 m, vec3 s)

    decompose scale vector

    Parameters:
      | *[in]*  **m**  affine transform
      | *[out]* **s**  scale vector (Sx, Sy, Sz)

.. c:function:: bool  glm_uniscaled(mat4 m)

    returns true if matrix is uniform scaled.
    This is helpful for creating normal matrix.

    Parameters:
      | *[in]*  **m**   matrix

.. c:function:: void  glm_decompose_rs(mat4 m, mat4 r, vec3 s)

    decompose rotation matrix (mat4) and scale vector [Sx, Sy, Sz]
    DON'T pass projected matrix here

    Parameters:
      | *[in]*  **m** affine transform
      | *[out]* **r** rotation matrix
      | *[out]* **s** scale matrix

.. c:function:: void  glm_decompose(mat4 m, vec4 t, mat4 r, vec3 s)

    decompose affine transform, TODO: extract shear factors.
    DON'T pass projected matrix here

    Parameters:
      | *[in]*  **m** affine transfrom
      | *[out]* **t** translation vector
      | *[out]* **r** rotation matrix (mat4)
      | *[out]* **s** scaling vector [X, Y, Z]

.. c:function:: void  glm_spin(mat4 m, float angle, vec3 axis)

    | rotate existing transform matrix around given axis by angle around self (doesn't affected by position)

    Parameters:
      | *[in, out]* **m**     affine transfrom
      | *[in]*      **angle** angle (radians)
      | *[in]*      **axis**  axis
