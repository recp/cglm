.. default-domain:: C

uvec3
=====

Header: cglm/uvec3.h

Table of contents (click to go):
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

Macros:

1. GLM_UVEC3_ONE_INIT
#. GLM_UVEC3_ZERO_INIT
#. GLM_UVEC3_ONE
#. GLM_UVEC3_ZERO

Functions:

1. :c:func:`glm_uvec3`
#. :c:func:`glm_uvec3_copy`
#. :c:func:`glm_uvec3_zero`
#. :c:func:`glm_uvec3_one`
#. :c:func:`glm_uvec3_add`
#. :c:func:`glm_uvec3_adds`
#. :c:func:`glm_uvec3_sub`
#. :c:func:`glm_uvec3_subs`
#. :c:func:`glm_uvec3_mul`
#. :c:func:`glm_uvec3_scale`
#. :c:func:`glm_uvec3_distance2`
#. :c:func:`glm_uvec3_distance`
#. :c:func:`glm_uvec3_fill`
#. :c:func:`glm_uvec3_eq`
#. :c:func:`glm_uvec3_eqv`
#. :c:func:`glm_uvec3_maxv`
#. :c:func:`glm_uvec3_minv`
#. :c:func:`glm_uvec3_clamp`
#. :c:func:`glm_uvec2_abs`

Functions documentation
~~~~~~~~~~~~~~~~~~~~~~~

.. c:function:: void glm_uvec3(uvec4 v4, uvec3 dest)
    
    init uvec3 using uvec4
    
    Parameters:
      | *[in]*  **v**    vector
      | *[out]* **dest** destination

.. c:function:: void glm_uvec3_copy(uvec3 a, uvec3 dest)
    
    copy all members of [a] to [dest]

    Parameters:
      | *[in]*  **a**    source vector
      | *[out]* **dest** destination

.. c:function:: void glm_uvec3_zero(uvec3 v)

    set all members of [v] to zero

    Parameters:
      | *[out]* **v** vector

.. c:function:: void glm_uvec3_one(uvec3 v)

    set all members of [v] to one

    Parameters:
      | *[out]* **v** vector

.. c:function:: void glm_uvec3_add(uvec3 a, uvec3 b, uvec3 dest)

    add vector [a] to vector [b] and store result in [dest]

    Parameters:
      | *[in]*  **a**    first vector
      | *[in]*  **b**    second vector
      | *[out]* **dest** destination

.. c:function:: void glm_uvec3_adds(uvec3 v, uint32_t s, uvec3 dest)

    add scalar s to vector [v] and store result in [dest]
    
    Parameters:
      | *[in]*  **v**    vector
      | *[in]*  **s**    scalar
      | *[out]* **dest** destination

.. c:function:: void glm_uvec3_sub(uvec3 a, uvec3 b, uvec3 dest)

    subtract vector [b] from vector [a] and store result in [dest]

    Parameters:
      | *[in]*  **a**    first vector
      | *[in]*  **b**    second vector
      | *[out]* **dest** destination

.. c:function:: void glm_uvec3_subs(uvec3 v, uint32_t s, uvec3 dest)

    subtract scalar s from vector [v] and store result in [dest]
    
    Parameters:
      | *[in]*  **v**    vector
      | *[in]*  **s**    scalar
      | *[out]* **dest** destination

.. c:function:: void glm_uvec3_mul(uvec3 a, uvec3 b, uvec3 dest)

    multiply vector [a] with vector [b] and store result in [dest]

    Parameters:
      | *[in]*  **a**    first vector
      | *[in]*  **b**    second vector
      | *[out]* **dest** destination

.. c:function:: void glm_uvec3_scale(uvec3 v, uint32_t s, uvec3 dest)

    multiply vector [a] with scalar s and store result in [dest]
    
    Parameters:
      | *[in]*  **v**    vector
      | *[in]*  **s**    scalar
      | *[out]* **dest** destination

.. c:function:: uint32_t glm_uvec3_distance2(uvec3 a, uvec3 b)

    squared distance between two vectors

    Parameters:
      | *[in]*  **a**    first vector
      | *[in]*  **b**    second vector
    
    Returns:
        squared distance (distance * distance)

.. c:function:: float glm_uvec3_distance(uvec3 a, uvec3 b)

    distance between two vectors

    Parameters:
      | *[in]*  **a**    first vector
      | *[in]*  **b**    second vector
    
    Returns:
        distance

.. c:function:: void  glm_uvec3_fill(uvec3 v, uint32_t val)

    fill a vector with specified value

    Parameters:
      | *[out]*  **v**    vector
      | *[in]*   **val**  value

.. c:function:: bool  glm_uvec3_eq(uvec3 v, uint32_t val)

    check if vector is equal to value

    Parameters:
      | *[in]*  **v**    vector
      | *[in]*  **val**  value

.. c:function:: bool  glm_uvec3_eqv(uvec3 v1, uvec3 v2)

    check if vector is equal to another vector

    Parameters:
      | *[in]*  **vec**   vector 1
      | *[in]*  **vec**   vector 2

.. c:function:: void glm_uvec3_maxv(uvec3 a, uvec3 b, uvec3 dest)

    set each member of dest to greater of vector a and b

    Parameters:
      | *[in]*  **a**    first vector
      | *[in]*  **b**    second vector
      | *[out]* **dest** destination

.. c:function:: void glm_uvec3_minv(uvec3 a, uvec3 b, uvec3 dest)

    set each member of dest to lesser of vector a and b

    Parameters:
      | *[in]*  **a**    first vector
      | *[in]*  **b**    second vector
      | *[out]* **dest** destination

.. c:function:: void glm_uvec3_clamp(uvec3 v, uint32_t minVal, uint32_t maxVal)

    clamp each member of [v] between minVal and maxVal (inclusive)

    Parameters:
      | *[in, out]* **v**      vector
      | *[in]*      **minVal** minimum value
      | *[in]*      **maxVal** maximum value

.. c:function:: void glm_uvec3_abs(uvec3 v, uvec3 dest)

    absolute value of each vector item

    Parameters:
      | *[in]*   **v**     vector
      | *[out]*  **dest**  destination vector
