.. default-domain:: C

3D Affine Transforms
================================================================================

Header: cglm/affine.h

Before starting, **cglm** provides two kind of transform functions; pre and post. 

Pre functions (`T' = Tnew * T`) are like `glm_translate`, `glm_rotate` which means it will translate the vector first and then apply the model transformation.
Post functions (`T' = T * Tnew`) are like `glm_translated`, `glm_rotated` which means it will apply the model transformation first and then translate the vector.

`glm_translate`, `glm_rotate` are pre functions and are similar to C++ **glm** which you are familiar with. 

In new versions of **cglm** we added `glm_translated`, `glm_rotated`... which are post functions, 
they are useful in some cases, e.g. append transform to existing transform (apply/append transform as last transform T' = T * Tnew).

Post functions are named after pre functions with `ed` suffix, e.g. `glm_translate` -> `glm_translated`. So don't mix them up.

Initialize Transform Matrices
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
Functions with **_make** prefix expect you don't have a matrix and they create
a matrix for you. You don't need to pass identity matrix.

But other functions expect you have a matrix and you want to transform them. If
you didn't have any existing matrix you have to initialize matrix to identity
before sending to transform functions.

There are also functions to decompose transform matrix. These functions can't
decompose matrix after projected.

Rotation Center
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

Rotating functions uses origin as rotation center (pivot/anchor point),
since scale factors are stored in rotation matrix, same may also true for scalling.
cglm provides some functions for rotating around at given point e.g.
**glm_rotate_at**, **glm_quat_rotate_at**. Use them or follow next section for algorithm ("Rotate or Scale around specific Point (Pivot Point / Anchor Point)").

Also **cglm** provides :c:func:`glm_spin` and :c:func:`glm_spinned` functions to rotate around itself. No need to give pivot.
These functions are useful for rotating around center of object. 

Rotate or Scale around specific Point (Anchor Point)
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

If you want to rotate model around arbitrary point follow these steps:

1. Move model from pivot point to origin: **translate(-pivot.x, -pivot.y, -pivot.z)**
2. Apply rotation (or scaling maybe)
3. Move model back from origin to pivot (reverse of step-1): **translate(pivot.x, pivot.y, pivot.z)**

**glm_rotate_at**, **glm_quat_rotate_at** and their helper functions works that way. 
So if you use them you don't need to do these steps manually which are done by **cglm**.

The implementation would be:

.. code-block:: c
  :linenos:

  glm_translate(m, pivot);
  glm_rotate(m, angle, axis);
  glm_translate(m, pivotInv); /* pivotInv = -pivot */

or just:

.. code-block:: c
  :linenos:

  glm_rotate_at(m, pivot, angle, axis);

.. _TransformsOrder:

Transforms Order
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

It is important to understand this part especially if you call transform
functions multiple times

`glm_translate`, `glm_rotate`, `glm_scale` and `glm_quat_rotate` and their
helpers functions works like this (cglm provides reverse order as `ed` suffix e.g `glm_translated`, `glm_rotated` see post transforms):

.. code-block:: c
  :linenos:

  TransformMatrix = TransformMatrix * TranslateMatrix; // glm_translate()
  TransformMatrix = TransformMatrix * RotateMatrix;   // glm_rotate(), glm_quat_rotate()
  TransformMatrix = TransformMatrix * ScaleMatrix;    // glm_scale()

As you can see it is multiplied as right matrix. For instance what will happen if you call `glm_translate` twice?

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

Post functions (**NEW**):

1. :c:func:`glm_translated_to`
#. :c:func:`glm_translated`
#. :c:func:`glm_translated_x`
#. :c:func:`glm_translated_y`
#. :c:func:`glm_translated_z`
#. :c:func:`glm_rotated_x`
#. :c:func:`glm_rotated_y`
#. :c:func:`glm_rotated_z`
#. :c:func:`glm_rotated`
#. :c:func:`glm_rotated_at`
#. :c:func:`glm_spinned`

Functions documentation
~~~~~~~~~~~~~~~~~~~~~~~

.. toctree::
   :maxdepth: 1
   :caption: Affine categories:

   affine-common
   affine-pre
   affine-post
