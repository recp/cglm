.. default-domain:: C

vec4
====

Header: cglm/vec4.h

Table of contents (clik func/macro to go):
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

Macros:

1. glm_vec4_dup3(v, dest)
#. glm_vec4_dup(v, dest)
#. GLM_VEC4_ONE_INIT
#. GLM_VEC4_BLACK_INIT
#. GLM_VEC4_ZERO_INIT
#. GLM_VEC4_ONE
#. GLM_VEC4_BLACK
#. GLM_VEC4_ZERO

Functions:

1. :c:func:`glm_vec4`
#. :c:func:`glm_vec4_copy3`
#. :c:func:`glm_vec4_copy`
#. :c:func:`glm_vec4_dot`
#. :c:func:`glm_vec4_norm2`
#. :c:func:`glm_vec4_norm`
#. :c:func:`glm_vec4_add`
#. :c:func:`glm_vec4_sub`
#. :c:func:`glm_vec4_scale`
#. :c:func:`glm_vec4_scale_as`
#. :c:func:`glm_vec4_flipsign`
#. :c:func:`glm_vec4_inv`
#. :c:func:`glm_vec4_inv_to`
#. :c:func:`glm_vec4_normalize`
#. :c:func:`glm_vec4_normalize_to`
#. :c:func:`glm_vec4_distance`
#. :c:func:`glm_vec4_maxv`
#. :c:func:`glm_vec4_minv`

Functions documentation
~~~~~~~~~~~~~~~~~~~~~~~

.. c:function:: void  glm_vec4(vec3 v3, float last, vec4 dest)

    init vec4 using vec3, since you are initializing vec4 with vec3
    you need to set last item. cglm could set it zero but making it parameter
    gives more control

    Parameters:
      | *[in]*  **v3**    vector4
      | *[in]*  **last**  last item of vec4
      | *[out]* **dest**  destination

.. c:function:: void glm_vec4_copy3(vec4 a, vec3 dest)

    copy first 3 members of [a] to [dest]

    Parameters:
      | *[in]*  **a**     source
      | *[out]* **dest**  destination

.. c:function:: void  glm_vec4_copy(vec4 v, vec4 dest)

    copy all members of [a] to [dest]

    Parameters:
      | *[in]*  **v**     source
      | *[in]*  **dest**  destination

.. c:function:: float  glm_vec4_dot(vec4 a, vec4 b)

    dot product of vec4

    Parameters:
      | *[in]*  **a**  vector1
      | *[in]*  **b**  vector2

    Returns:
      dot product

.. c:function:: float  glm_vec4_norm2(vec4 v)

    norm * norm (magnitude) of vector

    we can use this func instead of calling norm * norm, because it would call
    sqrtf fuction twice but with this func we can avoid func call, maybe this is
    not good name for this func

    Parameters:
      | *[in]*  **v**   vector

    Returns:
      square of norm / magnitude

.. c:function:: float  glm_vec4_norm(vec4 vec)

    norm (magnitude) of vec4

    Parameters:
      | *[in]*  **vec**   vector

.. c:function:: void  glm_vec4_add(vec4 v1, vec4 v2, vec4 dest)

    add v2 vector to v1 vector store result in dest

    Parameters:
      | *[in]*  **v1**    vector1
      | *[in]*  **v2**    vector2
      | *[out]* **dest**  destination vector

.. c:function:: void  glm_vec4_sub(vec4 v1, vec4 v2, vec4 dest)

    subtract v2 vector from v1 vector store result in dest

    Parameters:
      | *[in]*  **v1**    vector1
      | *[in]*  **v2**    vector2
      | *[out]* **dest**  destination vector

.. c:function:: void glm_vec4_scale(vec4 v, float s, vec4 dest)

     multiply/scale vec4 vector with scalar: result = v * s

    Parameters:
      | *[in]*  **v**     vector
      | *[in]*  **s**     scalar
      | *[out]* **dest**  destination vector

.. c:function:: void  glm_vec4_scale_as(vec4 v, float s, vec4 dest)

    make vec4 vector scale as specified: result = unit(v) * s

    Parameters:
      | *[in]*  **v**     vector
      | *[in]*  **s**     scalar
      | *[out]* **dest**  destination vector

.. c:function:: void  glm_vec4_flipsign(vec4 v)

    flip sign of all vec4 members

    Parameters:
    | *[in, out]*  **v**    vector

.. c:function:: void  glm_vec4_inv(vec4 v)

    make vector as inverse/opposite of itself

    Parameters:
      | *[in, out]*  **v**    vector

.. c:function:: void  glm_vec4_inv_to(vec4 v, vec4 dest)

    inverse/opposite vector

    Parameters:
      | *[in]*  **v**     source
      | *[out]* **dest**  destination

.. c:function:: void  glm_vec4_normalize(vec4 v)

    normalize vec4 and store result in same vec

    Parameters:
      | *[in, out]*  **v**    vector

.. c:function:: void  glm_vec4_normalize_to(vec4 vec, vec4 dest)

    normalize vec4 to dest

    Parameters:
      | *[in]*   **vec**   source
      | *[out]*  **dest**  destination

.. c:function:: float  glm_vec4_distance(vec4 v1, vec4 v2)

    distance between two vectors

    Parameters:
      | *[in]*  **mat**   vector1
      | *[in]*  **row1**  vector2

    Returns:
      | distance

.. c:function:: void  glm_vec4_maxv(vec4 v1, vec4 v2, vec4 dest)

    max values of vectors

    Parameters:
      | *[in]*  **v1**    vector1
      | *[in]*  **v2**    vector2
      | *[out]* **dest**  destination

.. c:function:: void  glm_vec4_minv(vec4 v1, vec4 v2, vec4 dest)

    min values of vectors

    Parameters:
      | *[in]*  **v1**    vector1
      | *[in]*  **v2**    vector2
      | *[out]* **dest**  destination
