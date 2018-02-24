.. default-domain:: C

Affine Transforms
================================================================================

Header: cglm/affine.h

Functions with **_make** prefix expect you don't have a matrix and they create
a matrix for you. You don't need to pass identity matrix.

But other functions expect you have a matrix and you want to transform them. If
you didn't have any existing matrix you have to initialize matrix to identity
before sending to transfrom functions.

There are also functions to decompose transform matrix. These functions can't
decompose matrix after projected.

Table of contents (clik func/macro to go):
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
#. :c:func:`glm_scale1`
#. :c:func:`glm_scale_uni`
#. :c:func:`glm_rotate_x`
#. :c:func:`glm_rotate_y`
#. :c:func:`glm_rotate_z`
#. :c:func:`glm_rotate_ndc_make`
#. :c:func:`glm_rotate_make`
#. :c:func:`glm_rotate_ndc`
#. :c:func:`glm_rotate`
#. :c:func:`glm_decompose_scalev`
#. :c:func:`glm_uniscaled`
#. :c:func:`glm_decompose_rs`
#. :c:func:`glm_decompose`

Functions documentation
~~~~~~~~~~~~~~~~~~~~~~~

.. c:function:: void  glm_translate_to(mat4 m, vec3 v, mat4 dest)

    translate existing transform matrix by *v* vector and store result in dest

    Parameters:
      | *[in]*  **m**    affine transfrom
      | *[in]*  **v**    translate vector [x, y, z]
      | *[out]* **dest** translated matrix

.. c:function:: void  glm_translate(mat4 m, vec3 v)

    translate existing transform matrix by v vector
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

    translate existing transform matrix by y factor

    Parameters:
      | *[in, out]* **m**  affine transfrom
      | *[in]*      **v**  y factor

.. c:function:: void  glm_translate_z(mat4 m, float z)

    translate existing transform matrix by z factor

    Parameters:
      | *[in, out]* **m**  affine transfrom
      | *[in]*      **v**  z factor

.. c:function:: void  glm_translate_make(mat4 m, vec3 v)

    creates NEW translate transform matrix by v vector

    Parameters:
      | *[in, out]* **m**  affine transfrom
      | *[in]*      **v**  translate vector [x, y, z]

.. c:function:: void  glm_scale_to(mat4 m, vec3 v, mat4 dest)

    scale existing transform matrix by v vector and store result in dest

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

.. c:function:: void  glm_scale1(mat4 m, float s)

    DEPRECATED! Use glm_scale_uni

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

.. c:function:: void  glm_rotate_ndc_make(mat4 m, float angle, vec3 axis_ndc)

    creates NEW rotation matrix by angle and axis
    this name may change in the future. axis must be is normalized

    Parameters:
      | *[out]* **m**        affine transfrom
      | *[in]*  **angle**    angle (radians)
      | *[in]*  **axis_ndc** normalized axis

.. c:function:: void  glm_rotate_make(mat4 m, float angle, vec3 axis)

    creates NEW rotation matrix by angle and axis,
    axis will be normalized so you don't need to normalize it

    Parameters:
      | *[out]* **m**    affine transfrom
      | *[in]*  **axis** angle (radians)
      | *[in]*  **axis** axis

.. c:function:: void  glm_rotate_ndc(mat4 m, float angle, vec3 axis_ndc)

    rotate existing transform matrix around Z axis by angle and axis
    this name may change in the future, axis must be normalized.

    Parameters:
      | *[out]* **m**        affine transfrom
      | *[in]*  **angle**    angle (radians)
      | *[in]*  **axis_ndc** normalized axis

.. c:function:: void  glm_rotate(mat4 m, float angle, vec3 axis)

    rotate existing transform matrix around Z axis by angle and axis

    Parameters:
      | *[in, out]* **m**     affine transfrom
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
