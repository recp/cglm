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
#. :c:func:`glm_aabb_invalidate`
#. :c:func:`glm_aabb_isvalid`
#. :c:func:`glm_aabb_size`
#. :c:func:`glm_aabb_radius`
#. :c:func:`glm_aabb_center`
#. :c:func:`glm_aabb_aabb`
#. :c:func:`glm_aabb_sphere`
#. :c:func:`glm_aabb_point`
#. :c:func:`glm_aabb_contains`

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

    this could be useful for getting a bbox which fits with view frustum and
    object bounding boxes. In this case you crop view frustum box with objects
    box

    Parameters:
      | *[in]*  **box**      bounding box 1
      | *[in]*  **cropBox**  crop box
      | *[out]* **dest**     cropped bounding box

.. c:function:: void  glm_aabb_crop_until(vec3 box[2], vec3 cropBox[2], vec3 clampBox[2], vec3 dest[2])

    | crops a bounding box with another one.

    this could be useful for getting a bbox which fits with view frustum and
    object bounding boxes. In this case you crop view frustum box with objects
    box

    Parameters:
      | *[in]*  **box**      bounding box
      | *[in]*  **cropBox**  crop box
      | *[in]*  **clampBox** minimum box
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

.. c:function:: void  glm_aabb_invalidate(vec3 box[2])

    | invalidate AABB min and max values

    | It fills *max* values with -FLT_MAX and *min* values with +FLT_MAX

    Parameters:
      | *[in, out]*   **box**     bounding box

.. c:function:: bool  glm_aabb_isvalid(vec3 box[2])

    | check if AABB is valid or not

    Parameters:
      | *[in]*   **box**     bounding box

    Returns:
      returns true if aabb is valid otherwise false

.. c:function:: float  glm_aabb_size(vec3 box[2])

    | distance between of min and max

    Parameters:
      | *[in]*   **box**     bounding box

    Returns:
      distance between min - max

.. c:function:: float  glm_aabb_radius(vec3 box[2])

    | radius of sphere which surrounds AABB

    Parameters:
      | *[in]*   **box**     bounding box

.. c:function:: void  glm_aabb_center(vec3 box[2], vec3 dest)

    | computes center point of AABB

    Parameters:
      | *[in]*    **box**      bounding box
      | *[out]*   **dest**     center of bounding box

.. c:function:: bool  glm_aabb_aabb(vec3 box[2], vec3 other[2])

    | check if two AABB intersects

    Parameters:
      | *[in]*    **box**     bounding box
      | *[out]*   **other**   other bounding box

.. c:function:: bool  glm_aabb_sphere(vec3 box[2], vec4 s)

    | check if AABB intersects with sphere

    | https://github.com/erich666/GraphicsGems/blob/master/gems/BoxSphere.c
    | Solid Box - Solid Sphere test.

    Parameters:
      | *[in]*    **box**     solid bounding box
      | *[out]*   **s**       solid sphere

.. c:function:: bool  glm_aabb_point(vec3 box[2], vec3 point)

    | check if point is inside of AABB

    Parameters:
      | *[in]*    **box**     bounding box
      | *[out]*   **point**   point

.. c:function:: bool  glm_aabb_contains(vec3 box[2], vec3 other[2])

    | check if AABB contains other AABB

    Parameters:
      | *[in]*    **box**     bounding box
      | *[out]*   **other**   other bounding box
