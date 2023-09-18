.. default-domain:: C

uvec4
=====

Header: cglm/uvec4.h

Table of contents (click to go):
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

Macros:

1. GLM_UVEC4_ONE_INIT
#. GLM_UVEC4_ZERO_INIT
#. GLM_UVEC4_ONE
#. GLM_UVEC4_ZERO

Functions:

1. :c:func:`glm_uvec4`
#. :c:func:`glm_uvec4_copy`
#. :c:func:`glm_uvec4_zero`
#. :c:func:`glm_uvec4_one`
#. :c:func:`glm_uvec4_add`
#. :c:func:`glm_uvec4_adds`
#. :c:func:`glm_uvec4_sub`
#. :c:func:`glm_uvec4_subs`
#. :c:func:`glm_uvec4_mul`
#. :c:func:`glm_uvec4_scale`
#. :c:func:`glm_uvec4_distance2`
#. :c:func:`glm_uvec4_distance`
#. :c:func:`glm_uvec4_maxv`
#. :c:func:`glm_uvec4_minv`
#. :c:func:`glm_uvec4_clamp`
#. :c:func:`glm_uvec4_abs`

Functions documentation
~~~~~~~~~~~~~~~~~~~~~~~

.. c:function:: void glm_uvec4(uvec3 v3, uint32_t last, uvec4 dest)
    
    init uvec4 using uvec3
    
    Parameters:
      | *[in]*  **v**    vector
      | *[out]* **dest** destination

.. c:function:: void glm_uvec4_copy(uvec4 a, uvec4 dest)
    
    copy all members of [a] to [dest]

    Parameters:
      | *[in]*  **a**    source vector
      | *[out]* **dest** destination

.. c:function:: void glm_uvec4_zero(uvec4 v)

    set all members of [v] to zero

    Parameters:
      | *[out]* **v** vector

.. c:function:: void glm_uvec4_one(uvec4 v)

    set all members of [v] to one

    Parameters:
      | *[out]* **v** vector

.. c:function:: void glm_uvec4_add(uvec4 a, uvec4 b, uvec4 dest)

    add vector [a] to vector [b] and store result in [dest]

    Parameters:
      | *[in]*  **a**    first vector
      | *[in]*  **b**    second vector
      | *[out]* **dest** destination

.. c:function:: void glm_uvec4_adds(uvec4 v, uint32_t s, uvec4 dest)

    add scalar s to vector [v] and store result in [dest]
    
    Parameters:
      | *[in]*  **v**    vector
      | *[in]*  **s**    scalar
      | *[out]* **dest** destination

.. c:function:: void glm_uvec4_sub(uvec4 a, uvec4 b, uvec4 dest)

    subtract vector [b] from vector [a] and store result in [dest]

    Parameters:
      | *[in]*  **a**    first vector
      | *[in]*  **b**    second vector
      | *[out]* **dest** destination

.. c:function:: void glm_uvec4_subs(uvec4 v, uint32_t s, uvec4 dest)

    subtract scalar s from vector [v] and store result in [dest]
    
    Parameters:
      | *[in]*  **v**    vector
      | *[in]*  **s**    scalar
      | *[out]* **dest** destination

.. c:function:: void glm_uvec4_mul(uvec4 a, uvec4 b, uvec4 dest)

    multiply vector [a] with vector [b] and store result in [dest]

    Parameters:
      | *[in]*  **a**    first vector
      | *[in]*  **b**    second vector
      | *[out]* **dest** destination

.. c:function:: void glm_uvec4_scale(uvec4 v, uint32_t s, uvec4 dest)

    multiply vector [a] with scalar s and store result in [dest]
    
    Parameters:
      | *[in]*  **v**    vector
      | *[in]*  **s**    scalar
      | *[out]* **dest** destination

.. c:function:: uint32_t glm_uvec4_distance2(uvec4 a, uvec4 b)

    squared distance between two vectors

    Parameters:
      | *[in]*  **a**    first vector
      | *[in]*  **b**    second vector
    
    Returns:
        squared distance (distance * distance)

.. c:function:: float glm_uvec4_distance(uvec4 a, uvec4 b)

    distance between two vectors

    Parameters:
      | *[in]*  **a**    first vector
      | *[in]*  **b**    second vector
    
    Returns:
        distance

.. c:function:: void glm_uvec4_maxv(uvec4 a, uvec4 b, uvec4 dest)

    set each member of dest to greater of vector a and b

    Parameters:
      | *[in]*  **a**    first vector
      | *[in]*  **b**    second vector
      | *[out]* **dest** destination

.. c:function:: void glm_uvec4_minv(uvec4 a, uvec4 b, uvec4 dest)

    set each member of dest to lesser of vector a and b

    Parameters:
      | *[in]*  **a**    first vector
      | *[in]*  **b**    second vector
      | *[out]* **dest** destination

.. c:function:: void glm_uvec4_clamp(uvec4 v, uint32_t minVal, uint32_t maxVal)

    clamp each member of [v] between minVal and maxVal (inclusive)

    Parameters:
      | *[in, out]* **v**      vector
      | *[in]*      **minVal** minimum value
      | *[in]*      **maxVal** maximum value

.. c:function:: void glm_uvec4_abs(uvec4 v, uvec4 dest)

    absolute value of each vector item

    Parameters:
      | *[in]*   **v**     vector
      | *[out]*  **dest**  destination vector
