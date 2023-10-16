.. default-domain:: C

uhvec4
=====

Header: cglm/uhvec4.h

Table of contents (click to go):
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

Macros:

1. GLM_UHVEC4_ONE_INIT
#. GLM_UHVEC4_ZERO_INIT
#. GLM_UHVEC4_ONE
#. GLM_UHVEC4_ZERO

Functions:

1. :c:func:`glm_uhvec4`
#. :c:func:`glm_uhvec4_copy`
#. :c:func:`glm_uhvec4_zero`
#. :c:func:`glm_uhvec4_one`
#. :c:func:`glm_uhvec4_add`
#. :c:func:`glm_uhvec4_adds`
#. :c:func:`glm_uhvec4_sub`
#. :c:func:`glm_uhvec4_subs`
#. :c:func:`glm_uhvec4_mul`
#. :c:func:`glm_uhvec4_scale`
#. :c:func:`glm_uhvec4_distance2`
#. :c:func:`glm_uhvec4_distance`
#. :c:func:`glm_uhvec4_maxv`
#. :c:func:`glm_uhvec4_minv`
#. :c:func:`glm_uhvec4_clamp`
#. :c:func:`glm_uhvec4_abs`

Functions documentation
~~~~~~~~~~~~~~~~~~~~~~~

.. c:function:: void glm_uhvec4(uhvec3 v3, uint16_t last, uhvec4 dest)
    
    init uhvec4 using uhvec3
    
    Parameters:
      | *[in]*  **v**    vector
      | *[out]* **dest** destination

.. c:function:: void glm_uhvec4_copy(uhvec4 a, uhvec4 dest)
    
    copy all members of [a] to [dest]

    Parameters:
      | *[in]*  **a**    source vector
      | *[out]* **dest** destination

.. c:function:: void glm_uhvec4_zero(uhvec4 v)

    set all members of [v] to zero

    Parameters:
      | *[out]* **v** vector

.. c:function:: void glm_uhvec4_one(uhvec4 v)

    set all members of [v] to one

    Parameters:
      | *[out]* **v** vector

.. c:function:: void glm_uhvec4_add(uhvec4 a, uhvec4 b, uhvec4 dest)

    add vector [a] to vector [b] and store result in [dest]

    Parameters:
      | *[in]*  **a**    first vector
      | *[in]*  **b**    second vector
      | *[out]* **dest** destination

.. c:function:: void glm_uhvec4_adds(uhvec4 v, uint16_t s, uhvec4 dest)

    add scalar s to vector [v] and store result in [dest]
    
    Parameters:
      | *[in]*  **v**    vector
      | *[in]*  **s**    scalar
      | *[out]* **dest** destination

.. c:function:: void glm_uhvec4_sub(uhvec4 a, uhvec4 b, uhvec4 dest)

    subtract vector [b] from vector [a] and store result in [dest]

    Parameters:
      | *[in]*  **a**    first vector
      | *[in]*  **b**    second vector
      | *[out]* **dest** destination

.. c:function:: void glm_uhvec4_subs(uhvec4 v, uint16_t s, uhvec4 dest)

    subtract scalar s from vector [v] and store result in [dest]
    
    Parameters:
      | *[in]*  **v**    vector
      | *[in]*  **s**    scalar
      | *[out]* **dest** destination

.. c:function:: void glm_uhvec4_mul(uhvec4 a, uhvec4 b, uhvec4 dest)

    multiply vector [a] with vector [b] and store result in [dest]

    Parameters:
      | *[in]*  **a**    first vector
      | *[in]*  **b**    second vector
      | *[out]* **dest** destination

.. c:function:: void glm_uhvec4_scale(uhvec4 v, uint16_t s, uhvec4 dest)

    multiply vector [a] with scalar s and store result in [dest]
    
    Parameters:
      | *[in]*  **v**    vector
      | *[in]*  **s**    scalar
      | *[out]* **dest** destination

.. c:function:: uint16_t glm_uhvec4_distance2(uhvec4 a, uhvec4 b)

    squared distance between two vectors

    Parameters:
      | *[in]*  **a**    first vector
      | *[in]*  **b**    second vector
    
    Returns:
        squared distance (distance * distance)

.. c:function:: float glm_uhvec4_distance(uhvec4 a, uhvec4 b)

    distance between two vectors

    Parameters:
      | *[in]*  **a**    first vector
      | *[in]*  **b**    second vector
    
    Returns:
        distance

.. c:function:: void glm_uhvec4_maxv(uhvec4 a, uhvec4 b, uhvec4 dest)

    set each member of dest to greater of vector a and b

    Parameters:
      | *[in]*  **a**    first vector
      | *[in]*  **b**    second vector
      | *[out]* **dest** destination

.. c:function:: void glm_uhvec4_minv(uhvec4 a, uhvec4 b, uhvec4 dest)

    set each member of dest to lesser of vector a and b

    Parameters:
      | *[in]*  **a**    first vector
      | *[in]*  **b**    second vector
      | *[out]* **dest** destination

.. c:function:: void glm_uhvec4_clamp(uhvec4 v, uint16_t minVal, uint16_t maxVal)

    clamp each member of [v] between minVal and maxVal (inclusive)

    Parameters:
      | *[in, out]* **v**      vector
      | *[in]*      **minVal** minimum value
      | *[in]*      **maxVal** maximum value

.. c:function:: void glm_uhvec4_abs(uhvec4 v, uhvec4 dest)

    absolute value of each vector item

    Parameters:
      | *[in]*   **v**     vector
      | *[out]*  **dest**  destination vector
