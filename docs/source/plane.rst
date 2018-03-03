.. default-domain:: C

plane
================================================================================

Header: cglm/plane.h

Plane extract functions are in frustum header and documented
in :doc:`frustum` page.

**Definition of plane:**

Plane equation:  **Ax + By + Cz + D = 0**

Plan is stored in **vec4** as **[A, B, C, D]**. (A, B, C) is normal and D is distance

Table of contents (click to go):
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

Functions:

1. :c:func:`glm_plane_normalize`


Functions documentation
~~~~~~~~~~~~~~~~~~~~~~~

.. c:function:: void  glm_plane_normalize(vec4 plane)

    | normalizes a plane

    Parameters:
      | *[in, out]*  **plane**  pnale to normalize
