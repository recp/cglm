.. default-domain:: C

vec3
====

Header: cglm/vec3.h

We mostly use vectors in graphics math, to make writing code faster
and easy to read, some *vec3* functions are aliased in global namespace.
For instance :c:func:`glm_dot` is alias of :c:func:`glm_vec_dot`,
alias means inline wrapper here. There is no call verison of alias functions

There are also functions for rotating *vec3* vector. **_m4**, **_m3** prefixes
rotate *vec3* with matrix.

Table of contents (clik func/macro to go):
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

Macros:

1. glm_vec_dup(v, dest)
#. GLM_VEC3_ONE_INIT
#. GLM_VEC3_ZERO_INIT
#. GLM_VEC3_ONE
#. GLM_VEC3_ZERO
#. GLM_YUP
#. GLM_ZUP
#. GLM_XUP

Functions:

1. :c:func:`glm_vec3`
#. :c:func:`glm_vec_copy`
#. :c:func:`glm_vec_dot`
#. :c:func:`glm_vec_cross`
#. :c:func:`glm_vec_norm2`
#. :c:func:`glm_vec_norm`
#. :c:func:`glm_vec_add`
#. :c:func:`glm_vec_sub`
#. :c:func:`glm_vec_scale`
#. :c:func:`glm_vec_scale_as`
#. :c:func:`glm_vec_flipsign`
#. :c:func:`glm_vec_inv`
#. :c:func:`glm_vec_inv_to`
#. :c:func:`glm_vec_normalize`
#. :c:func:`glm_vec_normalize_to`
#. :c:func:`glm_vec_distance`
#. :c:func:`glm_vec_angle`
#. :c:func:`glm_vec_rotate`
#. :c:func:`glm_vec_rotate_m4`
#. :c:func:`glm_vec_proj`
#. :c:func:`glm_vec_center`
#. :c:func:`glm_vec_maxv`
#. :c:func:`glm_vec_minv`
#. :c:func:`glm_vec_ortho`

Functions documentation
~~~~~~~~~~~~~~~~~~~~~~~

.. c:function:: void  glm_vec3(vec4 v4, vec3 dest)

    init vec3 using vec4

    Parameters:
      | *[in]*  **v4**    vector4
      | *[out]* **dest**  destination

.. c:function:: void  glm_vec_copy(vec3 a, vec3 dest)

    copy all members of [a] to [dest]

    Parameters:
      | *[in]*  **a**     source
      | *[out]* **dest**  destination

.. c:function:: float  glm_vec_dot(vec3 a, vec3 b)

    dot product of vec3

    Parameters:
      | *[in]*  **a**  vector1
      | *[in]*  **b**  vector2

    Returns:
      dot product

.. c:function:: void  glm_vec_cross(vec3 a, vec3 b, vec3 d)

    cross product

    Parameters:
      | *[in]*  **a**  source 1
      | *[in]*  **b**  source 2
      | *[out]* **d**  destination

.. c:function:: float  glm_vec_norm2(vec3 v)

    norm * norm (magnitude) of vector

    we can use this func instead of calling norm * norm, because it would call
    sqrtf fuction twice but with this func we can avoid func call, maybe this is
    not good name for this func

    Parameters:
      | *[in]*  **v**   vector

    Returns:
      square of norm / magnitude

.. c:function:: float  glm_vec_norm(vec3 vec)

    norm (magnitude) of vec3

    Parameters:
      | *[in]*  **vec**   vector

.. c:function:: void  glm_vec_add(vec3 v1, vec3 v2, vec3 dest)

    add v2 vector to v1 vector store result in dest

    Parameters:
      | *[in]*  **v1**    vector1
      | *[in]*  **v2**    vector2
      | *[out]* **dest**  destination vector

.. c:function:: void  glm_vec_sub(vec3 v1, vec3 v2, vec3 dest)

    subtract v2 vector from v1 vector store result in dest

    Parameters:
      | *[in]*  **v1**    vector1
      | *[in]*  **v2**    vector2
      | *[out]* **dest**  destination vector

.. c:function:: void glm_vec_scale(vec3 v, float s, vec3 dest)

     multiply/scale vec3 vector with scalar: result = v * s


    Parameters:
      | *[in]*  **v**     vector
      | *[in]*  **s**     scalar
      | *[out]* **dest**  destination vector

.. c:function:: void  glm_vec_scale_as(vec3 v, float s, vec3 dest)

    make vec3 vector scale as specified: result = unit(v) * s

    Parameters:
      | *[in]*  **v**     vector
      | *[in]*  **s**     scalar
      | *[out]* **dest**  destination vector

.. c:function:: void  glm_vec_flipsign(vec3 v)

    flip sign of all vec3 members

    Parameters:
    | *[in, out]*  **v**    vector

.. c:function:: void  glm_vec_inv(vec3 v)

    make vector as inverse/opposite of itself

    Parameters:
      | *[in, out]*  **v**    vector

.. c:function:: void  glm_vec_inv_to(vec3 v, vec3 dest)

    inverse/opposite vector

    Parameters:
      | *[in]*  **v**     source
      | *[out]* **dest**  destination

.. c:function:: void  glm_vec_normalize(vec3 v)

    normalize vec3 and store result in same vec

    Parameters:
      | *[in, out]*  **v**    vector

.. c:function:: void  glm_vec_normalize_to(vec3 vec, vec3 dest)

     normalize vec3 to dest

    Parameters:
      | *[in]*   **vec**   source
      | *[out]*  **dest**  destination

.. c:function:: float  glm_vec_angle(vec3 v1, vec3 v2)

    angle betwen two vector

    Parameters:
      | *[in]*  **v1**   vector1
      | *[in]*  **v2**   vector2

    Return:
      | angle as radians

.. c:function:: void  glm_vec_rotate(vec3 v, float angle, vec3 axis)

     rotate vec3 around axis by angle using Rodrigues' rotation formula

    Parameters:
      | *[in, out]*  **v**      vector
      | *[in]*       **axis**   axis vector (must be unit vector)
      | *[out]*      **angle**  angle (radians)

.. c:function:: void  glm_vec_rotate_m4(mat4 m, vec3 v, vec3 dest)

    apply rotation matrix to vector

    Parameters:
      | *[in]*  **m**     affine matrix or rot matrix
      | *[in]*  **v**     vector
      | *[out]* **dest**  rotated vector

.. c:function:: void  glm_vec_proj(vec3 a, vec3 b, vec3 dest)

    project a vector onto b vector

    Parameters:
      | *[in]*  **a**     vector1
      | *[in]*  **b**     vector2
      | *[out]* **dest**  projected vector

.. c:function:: void  glm_vec_center(vec3 v1, vec3 v2, vec3 dest)

    find center point of two vector

    Parameters:
      | *[in]*  **v1**    vector1
      | *[in]*  **v2**    vector2
      | *[out]* **dest**  center point

.. c:function:: float  glm_vec_distance(vec3 v1, vec3 v2)

    distance between two vectors

    Parameters:
      | *[in]*  **mat**   vector1
      | *[in]*  **row1**  vector2

    Returns:
      | distance

.. c:function:: void  glm_vec_maxv(vec3 v1, vec3 v2, vec3 dest)

    max values of vectors

    Parameters:
      | *[in]*  **v1**    vector1
      | *[in]*  **v2**    vector2
      | *[out]* **dest**  destination

.. c:function:: void  glm_vec_minv(vec3 v1, vec3 v2, vec3 dest)

    min values of vectors

    Parameters:
      | *[in]*  **v1**    vector1
      | *[in]*  **v2**    vector2
      | *[out]* **dest**  destination

.. c:function:: void  glm_vec_ortho(vec3 v, vec3 dest)

    possible orthogonal/perpendicular vector

    Parameters:
      | *[in]*  **mat**   vector
      | *[out]* **dest**  orthogonal/perpendicular vector
