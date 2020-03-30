.. default-domain:: C

ray
====

Header: cglm/ray.h

This is for collision-checks used by ray-tracers and the like.

Table of contents (click to go):
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

Functions:

1. :c:func:`glm_ray_triangle`

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
