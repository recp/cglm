.. default-domain:: C

ray
====

Header: cglm/ray.h

This is for collision-checks used by ray-tracers and the like.

Table of contents (click to go):
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

Functions:

1. :c:func:`glm_ray_triangle`
#. :c:func:`glm_ray_sphere`
#. :c:func:`glm_ray_at`

Functions documentation
~~~~~~~~~~~~~~~~~~~~~~~

.. c:function:: bool  glm_ray_triangle(vec3 origin, vec3 direction, vec3 v0, vec3 v1, vec3 v2, float *d)

    Möller–Trumbore ray-triangle intersection algorithm

    Parameters:
      | *[in]*       **origin**        origin of ray
      | *[in]*       **direction**     direction of ray
      | *[in]*       **v0**            first vertex of triangle
      | *[in]*       **v1**            second vertex of triangle
      | *[in]*       **v2**            third vertex of triangle
      | *[in, out]*  **d**             float pointer to save distance to intersection
      | *[out]*      **intersection**  whether there is intersection

.. c:function:: bool glm_ray_sphere(vec3 origin, vec3 dir, vec4 s, float * __restrict t1, float * __restrict t2)

    ray sphere intersection

    returns false if there is no intersection if true:

    - t1 > 0, t2 > 0: ray intersects the sphere at t1 and t2 both ahead of the origin
    - t1 < 0, t2 > 0: ray starts inside the sphere, exits at t2
    - t1 < 0, t2 < 0: no intersection ahead of the ray ( returns false )
    - the caller can check if the intersection points (t1 and t2) fall within a
      specific range (for example, tmin < t1, t2 < tmax) to determine if the
      intersections are within a desired segment of the ray

    Parameters:
      | *[in]*   **origin**  ray origin
      | *[in]*   **dir**     normalized ray direction
      | *[in]*   **s**       sphere  [center.x, center.y, center.z, radii]
      | *[out]*  **t1**      near point1 (closer to origin)
      | *[out]*  **t2**      far point2 (farther from origin)

    Return:
      | whether there is intersection

.. c:function:: bool  glm_ray_at(vec3 orig, vec3 dir, float t, vec3 point)

    point using t by 𝐏(𝑡)=𝐀+𝑡𝐛

    Parameters:
      | *[in]*   **origin**  ray origin
      | *[in]*   **dir**     ray direction
      | *[out]*  **t**       parameter
      | *[out]*  **point**   point at t

    Return:
      | point at t
