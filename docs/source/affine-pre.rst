.. default-domain:: C

3D Affine Transforms (pre)
================================================================================

Pre transform functions which are regular transform functions.

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
      | *[in]*  **m**    affine transform
      | *[in]*  **v**    translate vector [x, y, z]
      | *[out]* **dest** translated matrix

.. c:function:: void  glm_translate(mat4 m, vec3 v)

    translate existing transform matrix by *v* vector
    and stores result in same matrix

    Parameters:
      | *[in, out]* **m**  affine transform
      | *[in]*      **v**  translate vector [x, y, z]

.. c:function:: void  glm_translate_x(mat4 m, float x)

    translate existing transform matrix by x factor

    Parameters:
      | *[in, out]* **m**  affine transform
      | *[in]*      **v**  x factor

.. c:function:: void  glm_translate_y(mat4 m, float y)

    translate existing transform matrix by *y* factor

    Parameters:
      | *[in, out]* **m**  affine transform
      | *[in]*      **v**  y factor

.. c:function:: void  glm_translate_z(mat4 m, float z)

    translate existing transform matrix by *z* factor

    Parameters:
      | *[in, out]* **m**  affine transform
      | *[in]*      **v**  z factor

.. c:function:: void  glm_rotate_x(mat4 m, float angle, mat4 dest)

    rotate existing transform matrix around X axis by angle
    and store result in dest

    Parameters:
      | *[in]*  **m**     affine transform
      | *[in]*  **angle** angle (radians)
      | *[out]* **dest**  rotated matrix

.. c:function:: void  glm_rotate_y(mat4 m, float angle, mat4 dest)

    rotate existing transform matrix around Y axis by angle
    and store result in dest

    Parameters:
      | *[in]*  **m**     affine transform
      | *[in]*  **angle** angle (radians)
      | *[out]* **dest**  rotated matrix

.. c:function:: void  glm_rotate_z(mat4 m, float angle, mat4 dest)

    rotate existing transform matrix around Z axis by angle
    and store result in dest

    Parameters:
      | *[in]*  **m**     affine transform
      | *[in]*  **angle** angle (radians)
      | *[out]* **dest**  rotated matrix

.. c:function:: void  glm_rotate(mat4 m, float angle, vec3 axis)

    rotate existing transform matrix around given axis by angle at ORIGIN (0,0,0)

    **❗️IMPORTANT ❗️**
    
    If you need to rotate object around itself e.g. center of object or at
    some point [of object] then `glm_rotate_at()` would be better choice to do so.
    
    Even if object's model transform is identity, rotation may not be around
    center of object if object does not lay out at ORIGIN perfectly.
    
    Using `glm_rotate_at()` with center of bounding shape ( AABB, Sphere ... )
    would be an easy option to rotate around object if object is not at origin.
    
    One another option to rotate around itself at any point is `glm_spin()`
    which is perfect if only rotating around model position is desired e.g. not
    specific point on model for instance center of geometry or center of mass,
    again if geometry is not perfectly centered at origin at identity transform,
    rotation may not be around geometry.

    Parameters:
      | *[in, out]* **m**     affine transform
      | *[in]*      **angle** angle (radians)
      | *[in]*      **axis**  axis

.. c:function:: void  glm_rotate_at(mat4 m, vec3 pivot, float angle, vec3 axis)

    rotate existing transform around given axis by angle at given pivot point (rotation center)

    Parameters:
      | *[in, out]* **m**     affine transform
      | *[in]*      **pivot** pivot, anchor point, rotation center
      | *[in]*      **angle** angle (radians)
      | *[in]*      **axis**  axis

.. c:function:: void  glm_spin(mat4 m, float angle, vec3 axis)

    | rotate existing transform matrix around given axis by angle around self (doesn't affected by position)

    Parameters:
      | *[in, out]* **m**     affine transform
      | *[in]*      **angle** angle (radians)
      | *[in]*      **axis**  axis
