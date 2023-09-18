.. default-domain:: C

uvec2
=====

Header: cglm/uvec2.h

Table of contents (click to go):
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

Macros:

1. GLM_UVEC2_ONE_INIT
#. GLM_UVEC2_ZERO_INIT
#. GLM_UVEC2_ONE
#. GLM_UVEC2_ZERO

Functions:

1. :c:func:`glm_uvec2`
#. :c:func:`glm_uvec2_copy`
#. :c:func:`glm_uvec2_zero`
#. :c:func:`glm_uvec2_one`
#. :c:func:`glm_uvec2_add`
#. :c:func:`glm_uvec2_adds`
#. :c:func:`glm_uvec2_sub`
#. :c:func:`glm_uvec2_subs`
#. :c:func:`glm_uvec2_mul`
#. :c:func:`glm_uvec2_scale`
#. :c:func:`glm_uvec2_distance2`
#. :c:func:`glm_uvec2_distance`
#. :c:func:`glm_uvec2_maxv`
#. :c:func:`glm_uvec2_minv`
#. :c:func:`glm_uvec2_clamp`
#. :c:func:`glm_uvec2_abs`

Functions documentation
~~~~~~~~~~~~~~~~~~~~~~~

.. c:function:: void glm_uvec2(uint32_t * v, uvec2 dest)
    
    init uvec2 using vec3 or vec4
    
    Parameters:
      | *[in]*  **v**    vector
      | *[out]* **dest** destination

.. c:function:: void glm_uvec2_copy(uvec2 a, uvec2 dest)
    
    copy all members of [a] to [dest]

    Parameters:
      | *[in]*  **a**    source vector
      | *[out]* **dest** destination

.. c:function:: void glm_uvec2_zero(uvec2 v)

    set all members of [v] to zero

    Parameters:
      | *[out]* **v** vector

.. c:function:: void glm_uvec2_one(uvec2 v)

    set all members of [v] to one

    Parameters:
      | *[out]* **v** vector

.. c:function:: void glm_uvec2_add(uvec2 a, uvec2 b, uvec2 dest)

    add vector [a] to vector [b] and store result in [dest]

    Parameters:
      | *[in]*  **a**    first vector
      | *[in]*  **b**    second vector
      | *[out]* **dest** destination

.. c:function:: void glm_uvec2_adds(uvec2 v, uint32_t s, uvec2 dest)

    add scalar s to vector [v] and store result in [dest]
    
    Parameters:
      | *[in]*  **v**    vector
      | *[in]*  **s**    scalar
      | *[out]* **dest** destination

.. c:function:: void glm_uvec2_sub(uvec2 a, uvec2 b, uvec2 dest)

    subtract vector [b] from vector [a] and store result in [dest]

    Parameters:
      | *[in]*  **a**    first vector
      | *[in]*  **b**    second vector
      | *[out]* **dest** destination

.. c:function:: void glm_uvec2_subs(uvec2 v, uint32_t s, uvec2 dest)

    subtract scalar s from vector [v] and store result in [dest]
    
    Parameters:
      | *[in]*  **v**    vector
      | *[in]*  **s**    scalar
      | *[out]* **dest** destination

.. c:function:: void glm_uvec2_mul(uvec2 a, uvec2 b, uvec2 dest)

    multiply vector [a] with vector [b] and store result in [dest]

    Parameters:
      | *[in]*  **a**    first vector
      | *[in]*  **b**    second vector
      | *[out]* **dest** destination

.. c:function:: void glm_uvec2_scale(uvec2 v, uint32_t s, uvec2 dest)

    multiply vector [a] with scalar s and store result in [dest]
    
    Parameters:
      | *[in]*  **v**    vector
      | *[in]*  **s**    scalar
      | *[out]* **dest** destination

.. c:function:: uint32_t glm_uvec2_distance2(uvec2 a, uvec2 b)

    squared distance between two vectors

    Parameters:
      | *[in]*  **a**    first vector
      | *[in]*  **b**    second vector
    
    Returns:
        squared distance (distance * distance)

.. c:function:: float glm_uvec2_distance(uvec2 a, uvec2 b)

    distance between two vectors

    Parameters:
      | *[in]*  **a**    first vector
      | *[in]*  **b**    second vector
    
    Returns:
        distance

.. c:function:: void  glm_uvec2_fill(uvec2 v, uint32_t val)

    fill a vector with specified value

    Parameters:
      | *[out]*  **v**    vector
      | *[in]*   **val**  value

.. c:function:: bool  glm_uvec2_eq(uvec2 v, uint32_t val)

    check if vector is equal to value

    Parameters:
      | *[in]*  **v**    vector
      | *[in]*  **val**  value

.. c:function:: bool  glm_uvec2_eqv(uvec2 v1, uvec2 v2)

    check if vector is equal to another vector

    Parameters:
      | *[in]*  **vec**   vector 1
      | *[in]*  **vec**   vector 2


.. c:function:: void glm_uvec2_maxv(uvec2 a, uvec2 b, uvec2 dest)

    set each member of dest to greater of vector a and b

    Parameters:
      | *[in]*  **a**    first vector
      | *[in]*  **b**    second vector
      | *[out]* **dest** destination

.. c:function:: void glm_uvec2_minv(uvec2 a, uvec2 b, uvec2 dest)

    set each member of dest to lesser of vector a and b

    Parameters:
      | *[in]*  **a**    first vector
      | *[in]*  **b**    second vector
      | *[out]* **dest** destination

.. c:function:: void glm_uvec2_clamp(uvec2 v, uint32_t minVal, uint32_t maxVal)

    clamp each member of [v] between minVal and maxVal (inclusive)

    Parameters:
      | *[in, out]* **v**      vector
      | *[in]*      **minVal** minimum value
      | *[in]*      **maxVal** maximum value

.. c:function:: void glm_uvec2_abs(uvec2 v, uvec2 dest)

    absolute value of each vector item

    Parameters:
      | *[in]*   **v**     vector
      | *[out]*  **dest**  destination vector
