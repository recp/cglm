.. default-domain:: C

io (input / output e.g. print)
================================================================================

Header: cglm/io.h

There are some built-in print functions which may save your time,
especially for debugging.

All functions accept **FILE** parameter which makes very flexible.
You can even print it to file on disk.

In general you will want to print them to console to see results.
You can use **stdout** and **stderr** to write results to console.
Some programs may occupy **stdout** but you can still use **stderr**.
Using **stderr** is suggested.

Example to print mat4 matrix:

.. code-block:: c

   mat4 transform;
   /* ... */
   glm_mat4_print(transform, stderr);

**NOTE:** print functions use **%0.4f** precision if you need more
(you probably will in some cases), you can change it temporary.
cglm may provide precision parameter in the future

Changes since **v0.7.3**:
* Now mis-alignment of columns are fixed: larger numbers are printed via %g and others are printed via %f. Column withs are calculated before print.
* Now values are colorful ;)
* Some print improvements
* New options with default values:

.. code-block:: c

    #define CGLM_PRINT_PRECISION    5
    #define CGLM_PRINT_MAX_TO_SHORT 1e5
    #define CGLM_PRINT_COLOR        "\033[36m"
    #define CGLM_PRINT_COLOR_RESET  "\033[0m"

* Inline prints are only enabled in DEBUG mode and if **CGLM_DEFINE_PRINTS** is defined.

Check options page.

Table of contents (click to go):
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

Functions:

1. :c:func:`glm_mat4_print`
#. :c:func:`glm_mat3_print`
#. :c:func:`glm_vec4_print`
#. :c:func:`glm_ivec4_print`
#. :c:func:`glm_uvec4_print`
#. :c:func:`glm_hvec4_print`
#. :c:func:`glm_uhvec4_print`
#. :c:func:`glm_bvec4_print`
#. :c:func:`glm_ubvec4_print`
#. :c:func:`glm_vec3_print`
#. :c:func:`glm_ivec3_print`
#. :c:func:`glm_uvec3_print`
#. :c:func:`glm_hvec3_print`
#. :c:func:`glm_uhvec3_print`
#. :c:func:`glm_bvec3_print`
#. :c:func:`glm_ubvec3_print`
#. :c:func:`glm_vec2_print`
#. :c:func:`glm_ivec2_print`
#. :c:func:`glm_uvec2_print`
#. :c:func:`glm_hvec2_print`
#. :c:func:`glm_uhvec2_print`
#. :c:func:`glm_bvec2_print`
#. :c:func:`glm_ubvec2_print`
#. :c:func:`glm_versor_print`
#. :c:func:`glm_aabb_print`

Functions documentation
~~~~~~~~~~~~~~~~~~~~~~~

.. c:function:: void  glm_mat4_print(mat4 matrix, FILE * __restrict ostream)

    | print matrix to given stream

    Parameters:
      | *[in]*  **matrix**   matrix
      | *[in]*  **ostream**  FILE to write

.. c:function:: void  glm_mat3_print(mat3 matrix, FILE * __restrict ostream)

    | print matrix to given stream

    Parameters:
      | *[in]*  **matrix**   matrix
      | *[in]*  **ostream**  FILE to write

.. c:function:: void  glm_vec4_print(vec4 vec, FILE * __restrict ostream)

    | print vector to given stream

    Parameters:
      | *[in]*  **vec**      vector
      | *[in]*  **ostream**  FILE to write

.. c:function:: void  glm_ivec4_print(ivec4 vec, FILE * __restrict ostream)

    | print vector to given stream

    Parameters:
      | *[in]*  **vec**      vector
      | *[in]*  **ostream**  FILE to write

.. c:function:: void  glm_uvec4_print(uvec4 vec, FILE * __restrict ostream)

    | print vector to given stream

    Parameters:
      | *[in]*  **vec**      vector
      | *[in]*  **ostream**  FILE to write

.. c:function:: void  glm_hvec4_print(hvec4 vec, FILE * __restrict ostream)

    | print vector to given stream

    Parameters:
      | *[in]*  **vec**      vector
      | *[in]*  **ostream**  FILE to write

.. c:function:: void  glm_uhvec4_print(uhvec4 vec, FILE * __restrict ostream)

    | print vector to given stream

    Parameters:
      | *[in]*  **vec**      vector
      | *[in]*  **ostream**  FILE to write

.. c:function:: void  glm_bvec4_print(bvec4 vec, FILE * __restrict ostream)

    | print vector to given stream

    Parameters:
      | *[in]*  **vec**      vector
      | *[in]*  **ostream**  FILE to write

.. c:function:: void  glm_ubvec4_print(ubvec4 vec, FILE * __restrict ostream)

    | print vector to given stream

    Parameters:
      | *[in]*  **vec**      vector
      | *[in]*  **ostream**  FILE to write

.. c:function:: void  glm_vec3_print(vec3 vec, FILE * __restrict ostream)

    | print vector to given stream

    Parameters:
      | *[in]*  **vec**      vector
      | *[in]*  **ostream**  FILE to write

.. c:function:: void  glm_ivec3_print(ivec3 vec, FILE * __restrict ostream)

    | print vector to given stream

    Parameters:
      | *[in]*  **vec**      vector
      | *[in]*  **ostream**  FILE to write

.. c:function:: void  glm_uvec3_print(uvec3 vec, FILE * __restrict ostream)

    | print vector to given stream

    Parameters:
      | *[in]*  **vec**      vector
      | *[in]*  **ostream**  FILE to write

.. c:function:: void  glm_hvec3_print(hvec3 vec, FILE * __restrict ostream)

    | print vector to given stream

    Parameters:
      | *[in]*  **vec**      vector
      | *[in]*  **ostream**  FILE to write

.. c:function:: void  glm_uhvec3_print(uhvec3 vec, FILE * __restrict ostream)

    | print vector to given stream

    Parameters:
      | *[in]*  **vec**      vector
      | *[in]*  **ostream**  FILE to write

.. c:function:: void  glm_bvec3_print(bvec3 vec, FILE * __restrict ostream)

    | print vector to given stream

    Parameters:
      | *[in]*  **vec**      vector
      | *[in]*  **ostream**  FILE to write

.. c:function:: void  glm_ubvec3_print(ubvec3 vec, FILE * __restrict ostream)

    | print vector to given stream

    Parameters:
      | *[in]*  **vec**      vector
      | *[in]*  **ostream**  FILE to write

.. c:function:: void  glm_vec2_print(vec2 vec, FILE * __restrict ostream)

    | print vector to given stream

    Parameters:
      | *[in]*  **vec**      vector
      | *[in]*  **ostream**  FILE to write

.. c:function:: void  glm_ivec2_print(ivec2 vec, FILE * __restrict ostream)

    | print vector to given stream

    Parameters:
      | *[in]*  **vec**      vector
      | *[in]*  **ostream**  FILE to write

.. c:function:: void  glm_uvec2_print(uvec2 vec, FILE * __restrict ostream)

    | print vector to given stream

    Parameters:
      | *[in]*  **vec**      vector
      | *[in]*  **ostream**  FILE to write

.. c:function:: void  glm_hvec2_print(hvec2 vec, FILE * __restrict ostream)

    | print vector to given stream

    Parameters:
      | *[in]*  **vec**      vector
      | *[in]*  **ostream**  FILE to write

.. c:function:: void  glm_uhvec2_print(uhvec2 vec, FILE * __restrict ostream)

    | print vector to given stream

    Parameters:
      | *[in]*  **vec**      vector
      | *[in]*  **ostream**  FILE to write

.. c:function:: void  glm_bvec2_print(bvec2 vec, FILE * __restrict ostream)

    | print vector to given stream

    Parameters:
      | *[in]*  **vec**      vector
      | *[in]*  **ostream**  FILE to write

.. c:function:: void  glm_ubvec2_print(ubvec2 vec, FILE * __restrict ostream)

    | print vector to given stream

    Parameters:
      | *[in]*  **vec**      vector
      | *[in]*  **ostream**  FILE to write

.. c:function:: void  glm_versor_print(versor vec, FILE * __restrict ostream)

    | print quaternion to given stream

    Parameters:
      | *[in]*  **vec**      quaternion
      | *[in]*  **ostream**  FILE to write

.. c:function:: void  glm_aabb_print(versor vec, const char * __restrict tag, FILE * __restrict ostream)

    | print aabb to given stream

    Parameters:
      | *[in]*  **vec**      aabb (axis-aligned bounding box)
      | *[in]*  **tag**      tag to find it more easly in logs
      | *[in]*  **ostream**  FILE to write
