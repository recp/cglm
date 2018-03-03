.. default-domain:: C

axis aligned bounding box (AABB)
================================================================================

Header: cglm/box.h

Some convenient functions provided for AABB.

**Definition of box:**

cglm defines box as two dimensional array of vec3.
The first element is **min** point and the second one is **max** point.
If you have another type e.g. struct or even another representation then you must
convert it before and after call cglm box function.

Table of contents (click to go):
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

Functions:

1. :c:func:`glm_aabb_transform`
#. :c:func:`glm_aabb_merge`
#. :c:func:`glm_aabb_crop`
#. :c:func:`glm_aabb_crop_until`
#. :c:func:`glm_aabb_frustum`

Functions documentation
~~~~~~~~~~~~~~~~~~~~~~~

.. c:function:: void  glm_aabb_transform(vec3 box[2], mat4 m, vec3 dest[2])

    | apply transform to Axis-Aligned Bounding Box

    Parameters:
      | *[in]*  **box**   bounding box
      | *[in]*  **m**     transform matrix
      | *[out]* **dest**  transformed bounding box

.. c:function:: void  glm_aabb_merge(vec3 box1[2], vec3 box2[2], vec3 dest[2])

    | merges two AABB bounding box and creates new one

    two box must be in same space, if one of box is in different space then
    you should consider to convert it's space by glm_box_space

    Parameters:
      | *[in]*  **box1** bounding box 1
      | *[in]*  **box2** bounding box 2
      | *[out]* **dest** merged bounding box

.. c:function:: void  glm_aabb_crop(vec3 box[2], vec3 cropBox[2], vec3 dest[2])

    | crops a bounding box with another one.

    this could be useful for gettng a bbox which fits with view frustum and
    object bounding boxes. In this case you crop view frustum box with objects
    box

    Parameters:
      | *[in]*  **box**      bounding box 1
      | *[in]*  **cropBox**  crop box
      | *[out]* **dest**     cropped bounding box

.. c:function:: void  glm_aabb_crop_until(vec3 box[2], vec3 cropBox[2], vec3 clampBox[2], vec3 dest[2])

    | crops a bounding box with another one.

    this could be useful for gettng a bbox which fits with view frustum and
    object bounding boxes. In this case you crop view frustum box with objects
    box

    Parameters:
      | *[in]*  **box**      bounding box
      | *[in]*  **cropBox**  crop box
      | *[in]*  **clampBox** miniumum box
      | *[out]* **dest**     cropped bounding box

.. c:function:: bool  glm_aabb_frustum(vec3 box[2], vec4 planes[6])

    | check if AABB intersects with frustum planes

    this could be useful for frustum culling using AABB.

    OPTIMIZATION HINT:
       if planes order is similar to LEFT, RIGHT, BOTTOM, TOP, NEAR, FAR
       then this method should run even faster because it would only use two
       planes if object is not inside the two planes
       fortunately cglm extracts planes as this order! just pass what you got!

    Parameters:
      | *[in]*   **box**     bounding box
      | *[out]*  **planes**  frustum planes
