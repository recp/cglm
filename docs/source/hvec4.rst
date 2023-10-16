.. default-domain:: C

hvec4
=====

Header: cglm/hvec4.h

Table of contents (click to go):
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

Macros:

1. GLM_HVEC4_ONE_INIT
#. GLM_HVEC4_ZERO_INIT
#. GLM_HVEC4_ONE
#. GLM_HVEC4_ZERO

Functions:

1. :c:func:`glm_hvec4`
#. :c:func:`glm_hvec4_copy`
#. :c:func:`glm_hvec4_zero`
#. :c:func:`glm_hvec4_one`
#. :c:func:`glm_hvec4_add`
#. :c:func:`glm_hvec4_adds`
#. :c:func:`glm_hvec4_sub`
#. :c:func:`glm_hvec4_subs`
#. :c:func:`glm_hvec4_mul`
#. :c:func:`glm_hvec4_scale`
#. :c:func:`glm_hvec4_distance2`
#. :c:func:`glm_hvec4_distance`
#. :c:func:`glm_hvec4_maxv`
#. :c:func:`glm_hvec4_minv`
#. :c:func:`glm_hvec4_clamp`
#. :c:func:`glm_hvec4_abs`

Functions documentation
~~~~~~~~~~~~~~~~~~~~~~~

.. c:function:: void glm_hvec4(hvec3 v3, int16_t last, hvec4 dest)
    
    init hvec4 using hvec3
    
    Parameters:
      | *[in]*  **v**    vector
      | *[out]* **dest** destination

.. c:function:: void glm_hvec4_copy(hvec4 a, hvec4 dest)
    
    copy all members of [a] to [dest]

    Parameters:
      | *[in]*  **a**    source vector
      | *[out]* **dest** destination

.. c:function:: void glm_hvec4_zero(hvec4 v)

    set all members of [v] to zero

    Parameters:
      | *[out]* **v** vector

.. c:function:: void glm_hvec4_one(hvec4 v)

    set all members of [v] to one

    Parameters:
      | *[out]* **v** vector

.. c:function:: void glm_hvec4_add(hvec4 a, hvec4 b, hvec4 dest)

    add vector [a] to vector [b] and store result in [dest]

    Parameters:
      | *[in]*  **a**    first vector
      | *[in]*  **b**    second vector
      | *[out]* **dest** destination

.. c:function:: void glm_hvec4_adds(hvec4 v, int16_t s, hvec4 dest)

    add scalar s to vector [v] and store result in [dest]
    
    Parameters:
      | *[in]*  **v**    vector
      | *[in]*  **s**    scalar
      | *[out]* **dest** destination

.. c:function:: void glm_hvec4_sub(hvec4 a, hvec4 b, hvec4 dest)

    subtract vector [b] from vector [a] and store result in [dest]

    Parameters:
      | *[in]*  **a**    first vector
      | *[in]*  **b**    second vector
      | *[out]* **dest** destination

.. c:function:: void glm_hvec4_subs(hvec4 v, int16_t s, hvec4 dest)

    subtract scalar s from vector [v] and store result in [dest]
    
    Parameters:
      | *[in]*  **v**    vector
      | *[in]*  **s**    scalar
      | *[out]* **dest** destination

.. c:function:: void glm_hvec4_mul(hvec4 a, hvec4 b, hvec4 dest)

    multiply vector [a] with vector [b] and store result in [dest]

    Parameters:
      | *[in]*  **a**    first vector
      | *[in]*  **b**    second vector
      | *[out]* **dest** destination

.. c:function:: void glm_hvec4_scale(hvec4 v, int16_t s, hvec4 dest)

    multiply vector [a] with scalar s and store result in [dest]
    
    Parameters:
      | *[in]*  **v**    vector
      | *[in]*  **s**    scalar
      | *[out]* **dest** destination

.. c:function:: int16_t glm_hvec4_distance2(hvec4 a, hvec4 b)

    squared distance between two vectors

    Parameters:
      | *[in]*  **a**    first vector
      | *[in]*  **b**    second vector
    
    Returns:
        squared distance (distance * distance)

.. c:function:: float glm_hvec4_distance(hvec4 a, hvec4 b)

    distance between two vectors

    Parameters:
      | *[in]*  **a**    first vector
      | *[in]*  **b**    second vector
    
    Returns:
        distance

.. c:function:: void glm_hvec4_maxv(hvec4 a, hvec4 b, hvec4 dest)

    set each member of dest to greater of vector a and b

    Parameters:
      | *[in]*  **a**    first vector
      | *[in]*  **b**    second vector
      | *[out]* **dest** destination

.. c:function:: void glm_hvec4_minv(hvec4 a, hvec4 b, hvec4 dest)

    set each member of dest to lesser of vector a and b

    Parameters:
      | *[in]*  **a**    first vector
      | *[in]*  **b**    second vector
      | *[out]* **dest** destination

.. c:function:: void glm_hvec4_clamp(hvec4 v, int16_t minVal, int16_t maxVal)

    clamp each member of [v] between minVal and maxVal (inclusive)

    Parameters:
      | *[in, out]* **v**      vector
      | *[in]*      **minVal** minimum value
      | *[in]*      **maxVal** maximum value

.. c:function:: void glm_hvec4_abs(hvec4 v, hvec4 dest)

    absolute value of each vector item

    Parameters:
      | *[in]*   **v**     vector
      | *[out]*  **dest**  destination vector
