.. default-domain:: C

affine transforms
================================================================================

Header: cglm/affine.h

Initialize Transform Matrices
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
Functions with **_make** prefix expect you don't have a matrix and they create
a matrix for you. You don't need to pass identity matrix.

But other functions expect you have a matrix and you want to transform them. If
you didn't have any existing matrix you have to initialize matrix to identity
before sending to transfrom functions.

There are also functions to decompose transform matrix. These functions can't
decompose matrix after projected.

Rotation Center
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

Rotating functions uses origin as rotation center (pivot/anchor point),
since scale factors are stored in rotation matrix, same may also true for scalling.
cglm provides some functions for rotating around at given point e.g.
**glm_rotate_at**, **glm_quat_rotate_at**. Use them or follow next section for algorihm ("Rotate or Scale around specific Point (Pivot Point / Anchor Point)").

Rotate or Scale around specific Point (Anchor Point)
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

If you want to rotate model around arbibtrary point follow these steps:

1. Move model from pivot point to origin: **translate(-pivot.x, -pivot.y, -pivot.z)**
2. Apply rotation (or scaling maybe)
3. Move model back from origin to pivot (reverse of step-1): **translate(pivot.x, pivot.y, pivot.z)**

**glm_rotate_at**, **glm_quat_rotate_at** and their helper functions works that way.

The implementation would be:

.. code-block:: c
  :linenos:

  glm_translate(m, pivot);
  glm_rotate(m, angle, axis);
  glm_translate(m, pivotInv); /* pivotInv = -pivot */

Transforms Order
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

It is important to understand this part especially if you call transform
functions multiple times

`glm_translate`, `glm_rotate`, `glm_scale` and `glm_quat_rotate` and their
helpers functions works like this (cglm may provide reverse order too as alternative in the future):

.. code-block:: c
  :linenos:

  TransformMatrix = TransformMatrix * TraslateMatrix; // glm_translate()
  TransformMatrix = TransformMatrix * RotateMatrix;   // glm_rotate(), glm_quat_rotate()
  TransformMatrix = TransformMatrix * ScaleMatrix;    // glm_scale()

As you can see it is multipled as right matrix. For instance what will happen if you call `glm_translate` twice?

.. code-block:: c
  :linenos:

  glm_translate(transform, translate1); /* transform = transform * translate1 */
  glm_translate(transform, translate2); /* transform = transform * translate2 */
  glm_rotate(transform, angle, axis)    /* transform = transform * rotation   */

Now lets try to understand this:

1. You call translate using `translate1` and you expect it will be first transform
because you call it first, do you?

Result will be **`transform = transform * translate1`**

2. Then you call translate using `translate2` and you expect it will be second transform?

Result will be **`transform = transform * translate2`**. Now lets expand transform,
it was `transform * translate1` before second call.

Now it is **`transform = transform * translate1 * translate2`**, now do you understand what I say?

3. After last call transform will be:

**`transform = transform * translate1 * translate2 * rotation`**

The order will be; **rotation will be applied first**, then **translate2** then **translate1**

It is all about matrix multiplication order. It is similar to MVP matrix:
`MVP = Projection * View * Model`, model will be applied first, then view then projection.

**Confused?**

In the end the last function call applied first in shaders.

As alternative way, you can create transform matrices individually then combine manually,
but don't forget that `glm_translate`, `glm_rotate`, `glm_scale`... are optimized and should be faster (an smaller assembly output) than manual multiplication

.. code-block:: c
  :linenos:

  mat4 transform1, transform2, transform3, finalTransform;

  glm_translate_make(transform1, translate1);
  glm_translate_make(transform2, translate2);
  glm_rotate_make(transform3, angle, axis);

  /* first apply transform1, then transform2, thentransform3 */
  glm_mat4_mulN((mat4 *[]){&transform3, &transform2, &transform1}, 3, finalTransform);

  /* if you don't want to use mulN, same as above */
  glm_mat4_mul(transform3, transform2, finalTransform);
  glm_mat4_mul(finalTransform, transform1, finalTransform);

Now transform1 will be applied first, then transform2 then transform3

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
