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

Table of contents (click to go):
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

Functions:

1. :c:func:`glm_mat4_print`
#. :c:func:`glm_mat3_print`
#. :c:func:`glm_vec4_print`
#. :c:func:`glm_vec3_print`
#. :c:func:`glm_ivec3_print`
#. :c:func:`glm_versor_print`
#. :c:func:`glm_aabb_print`

Functions documentation
~~~~~~~~~~~~~~~~~~~~~~~

.. c:function:: void  glm_mat4_print(mat4 matrix, FILE * __restrict ostream)

    | print mat4 to given stream

    Parameters:
      | *[in]*  **matrix**   matrix
      | *[in]*  **ostream**  FILE to write

.. c:function:: void  glm_mat3_print(mat3 matrix, FILE * __restrict ostream)

    | print mat3 to given stream

    Parameters:
      | *[in]*  **matrix**   matrix
      | *[in]*  **ostream**  FILE to write

.. c:function:: void  glm_vec4_print(vec4 vec, FILE * __restrict ostream)

    | print vec4 to given stream

    Parameters:
      | *[in]*  **vec**      vector
      | *[in]*  **ostream**  FILE to write

.. c:function:: void  glm_vec3_print(vec3 vec, FILE * __restrict ostream)

    | print vec3 to given stream

    Parameters:
      | *[in]*  **vec**      vector
      | *[in]*  **ostream**  FILE to write

.. c:function:: void  glm_ivec3_print(ivec3 vec, FILE * __restrict ostream)

    | print ivec3 to given stream

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
