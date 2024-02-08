.. default-domain:: C

Sphere
================================================================================

Header: cglm/sphere.h

**Definition of sphere:**

Sphere Representation in cglm is *vec4*: **[center.x, center.y, center.z, radii]**

You can call any vec3 function by passing sphere. Because first three elements
defines center of sphere.

Table of contents (click to go):
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

Functions:

1. :c:func:`glm_sphere_radii`
#. :c:func:`glm_sphere_transform`
#. :c:func:`glm_sphere_merge`
#. :c:func:`glm_sphere_sphere`
#. :c:func:`glm_sphere_point`

Functions documentation
~~~~~~~~~~~~~~~~~~~~~~~

.. c:function:: float  glm_sphere_radii(vec4 s)

    | helper for getting sphere radius

    Parameters:
      | *[in]*  **s**   sphere

    Returns:
       returns radii

.. c:function:: void  glm_sphere_transform(vec4 s, mat4 m, vec4 dest)

    | apply transform to sphere, it is just wrapper for glm_mat4_mulv3

    Parameters:
      | *[in]*  **s**    sphere
      | *[in]*  **m**    transform matrix
      | *[out]* **dest** transformed sphere

.. c:function:: void  glm_sphere_merge(vec4 s1, vec4 s2, vec4 dest)

    | merges two spheres and creates a new one

    two sphere must be in same space, for instance if one in world space then
    the other must be in world space too, not in local space.

    Parameters:
      | *[in]*  **s1**      sphere 1
      | *[in]*  **s2**      sphere 2
      | *[out]* **dest**    merged/extended sphere

.. c:function:: bool  glm_sphere_sphere(vec4 s1, vec4 s2)

    | check if two sphere intersects

    Parameters:
      | *[in]*  **s1**      sphere
      | *[in]*  **s2**      other sphere

.. c:function:: bool  glm_sphere_point(vec4 s, vec3 point)

    | check if sphere intersects with point

    Parameters:
      | *[in]*  **s**       sphere
      | *[in]*  **point**   point
