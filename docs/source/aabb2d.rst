.. default-domain:: C

2d axis aligned bounding box (AABB)
================================================================================

Header: cglm/aabb2d.h

Some convenient functions provided for AABB.

**Definition of aabb:**

cglm defines an aabb as a two dimensional array of vec2's.
The first element is the **min** point and the second one is the **max** point.
If you have another type e.g. struct or even another representation then you must
convert it before and after calling a cglm aabb2d function.

Table of contents (click to go):
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

Macros:

1. :c:func:`glm_aabb2d_size`

Functions:

1. :c:func:`glm_aabb2d_copy`
#. :c:func:`glm_aabb2d_zero`
#. :c:func:`glm_aabb2d_transform`
#. :c:func:`glm_aabb2d_merge`
#. :c:func:`glm_aabb2d_crop`
#. :c:func:`glm_aabb2d_crop_until`
#. :c:func:`glm_aabb2d_invalidate`
#. :c:func:`glm_aabb2d_isvalid`
#. :c:func:`glm_aabb2d_diag`
#. :c:func:`glm_aabb2d_sizev`
#. :c:func:`glm_aabb2d_radius`
#. :c:func:`glm_aabb2d_center`
#. :c:func:`glm_aabb2d_aabb`
#. :c:func:`glm_aabb2d_circle`
#. :c:func:`glm_aabb2d_point`
#. :c:func:`glm_aabb2d_contains`

Functions documentation
~~~~~~~~~~~~~~~~~~~~~~~

.. c:function:: void  glm_aabb2d_copy(vec2 aabb[2], vec2 dest[2])

    | copy all members of [aabb] to [dest]

    Parameters:
      | *[in]*  **aabb**  bounding box
      | *[out]* **dest**  destination

.. c:function:: void  glm_aabb2d_zero(vec2 aabb[2])

    | makes all members of [aabb] 0.0f (zero)

    Parameters:
      | *[in, out]*  **aabb**     bounding box

.. c:function:: void  glm_aabb2d_transform(vec2 aabb[2], mat3 m, vec2 dest[2])

    | apply transform to Axis-Aligned Bounding Box

    Parameters:
      | *[in]*  **aabb**   bounding box
      | *[in]*  **m**     transform matrix
      | *[out]* **dest**  transformed bounding box

.. c:function:: void  glm_aabb2d_merge(vec2 aabb1[2], vec2 aabb2[2], vec2 dest[2])

    | merges two AABB bounding box and creates new one

    two aabb must be in the same space

    Parameters:
      | *[in]*  **aabb1** bounding box 1
      | *[in]*  **aabb2** bounding box 2
      | *[out]* **dest** merged bounding box

.. c:function:: void  glm_aabb2d_crop(vec2 aabb[2], vec2 cropAabb[2], vec2 dest[2])

    | crops a bounding box with another one.

    this could be useful for gettng a bbox which fits with view frustum and
    object bounding boxes. In this case you crop view frustum box with objects
    box

    Parameters:
      | *[in]*  **aabb**      bounding box 1
      | *[in]*  **cropAabb**  crop box
      | *[out]* **dest**     cropped bounding box

.. c:function:: void  glm_aabb2d_crop_until(vec2 aabb[2], vec2 cropAabb[2], vec2 clampAabb[2], vec2 dest[2])

    | crops a bounding box with another one.

    this could be useful for gettng a bbox which fits with view frustum and
    object bounding boxes. In this case you crop view frustum box with objects
    box

    Parameters:
      | *[in]*  **aabb**      bounding box
      | *[in]*  **cropAabb**  crop box
      | *[in]*  **clampAabb** minimum box
      | *[out]* **dest**     cropped bounding box

.. c:function:: void  glm_aabb2d_invalidate(vec2 aabb[2])

    | invalidate AABB min and max values

    | It fills *max* values with -FLT_MAX and *min* values with +FLT_MAX

    Parameters:
      | *[in, out]*   **aabb**     bounding box

.. c:function:: bool  glm_aabb2d_isvalid(vec2 aabb[2])

    | check if AABB is valid or not

    Parameters:
      | *[in]*   **aabb**     bounding box

    Returns:
      returns true if aabb is valid otherwise false

.. c:function:: float  glm_aabb2d_diag(vec2 aabb[2])

    | distance between min and max

    Parameters:
      | *[in]*   **aabb**     bounding box

    Returns:
      distance between min - max


.. c:function:: void  glm_aabb2d_sizev(vec2 aabb[2], vec2 dest)

    | size vector of aabb

    Parameters:
      | *[in]*   **aabb**     bounding box
      | *[out]*  **dest**     size vector

    Returns:
      size vector of aabb max - min

.. c:function:: float  glm_aabb2d_radius(vec2 aabb[2])

    | radius of sphere which surrounds AABB

    Parameters:
      | *[in]*   **aabb**     bounding box

.. c:function:: void  glm_aabb2d_center(vec2 aabb[2], vec2 dest)

    | computes center point of AABB

    Parameters:
      | *[in]*    **aabb**      bounding box
      | *[out]*   **dest**     center of bounding box

.. c:function:: bool  glm_aabb2d_aabb(vec2 aabb[2], vec2 other[2])

    | check if two AABB intersects

    Parameters:
      | *[in]*    **aabb**     bounding box
      | *[out]*   **other**   other bounding box

.. c:function:: bool  glm_aabb2d_circle(vec2 aabb[2], vec3 c)

    | check if AABB intersects with sphere

    | https://github.com/erich666/GraphicsGems/blob/master/gems/BoxSphere.c
    | Solid Box - Solid Sphere test.

    Parameters:
      | *[in]*    **aabb**     solid bounding box
      | *[out]*   **c**        solid circle

.. c:function:: bool  glm_aabb2d_point(vec2 aabb[2], vec2 point)

    | check if point is inside of AABB

    Parameters:
      | *[in]*    **aabb**     bounding box
      | *[out]*   **point**   point

.. c:function:: bool  glm_aabb2d_contains(vec2 aabb[2], vec2 other[2])

    | check if AABB contains other AABB

    Parameters:
      | *[in]*    **aabb**     bounding box
      | *[out]*   **other**   other bounding box

