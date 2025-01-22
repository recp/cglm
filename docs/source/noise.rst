.. default-domain:: C

perlin
================================================================================

Header: cglm/noise.h

Classic Perlin noise implementation.

Based on the work of Stefan Gustavson and Ashima Arts on "webgl-noise":
https://github.com/stegu/webgl-noise
Following Stefan Gustavson's paper "Simplex noise demystified":
http://www.itn.liu.se/~stegu/simplexnoise/simplexnoise.pdf

Implementation based on glm::perlin function:
https://github.com/g-truc/glm/blob/master/glm/gtc/noise.inl

Table of contents (click to go):
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

Functions:

1. :c:func:`glm_perlin_vec4`
#. :c:func:`glm_perlin_vec3`
#. :c:func:`glm_perlin_vec2`


Functions documentation
~~~~~~~~~~~~~~~~~~~~~~~

.. c:function:: float  glm_perlin_vec4(vec4 point)

    | Classic Perlin noise

    Parameters:
      | *[in]*  **point**  4D point

    Returns:
      | noise value


.. c:function:: float  glm_perlin_vec3(vec3 point)

    | Classic Perlin noise

    Parameters:
      | *[in]*  **point**  3D point

    Returns:
      | noise value

.. c:function:: float  glm_perlin_vec2(vec2 point)

    | Classic Perlin noise

    Parameters:
      | *[in]*  **point**  2D point

    Returns:
      | noise value
