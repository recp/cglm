.. default-domain:: C

hvec3
=====

Header: cglm/hvec3.h

Table of contents (click to go):
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

Macros:

1. GLM_HVEC3_ONE_INIT
#. GLM_HVEC3_ZERO_INIT
#. GLM_HVEC3_ONE
#. GLM_HVEC3_ZERO

Functions:

1. :c:func:`glm_hvec3`
#. :c:func:`glm_hvec3_copy`
#. :c:func:`glm_hvec3_zero`
#. :c:func:`glm_hvec3_one`
#. :c:func:`glm_hvec3_add`
#. :c:func:`glm_hvec3_adds`
#. :c:func:`glm_hvec3_sub`
#. :c:func:`glm_hvec3_subs`
#. :c:func:`glm_hvec3_mul`
#. :c:func:`glm_hvec3_scale`
#. :c:func:`glm_hvec3_distance2`
#. :c:func:`glm_hvec3_distance`
#. :c:func:`glm_hvec3_fill`
#. :c:func:`glm_hvec3_eq`
#. :c:func:`glm_hvec3_eqv`
#. :c:func:`glm_hvec3_maxv`
#. :c:func:`glm_hvec3_minv`
#. :c:func:`glm_hvec3_clamp`
#. :c:func:`glm_hvec2_abs`

Functions documentation
~~~~~~~~~~~~~~~~~~~~~~~

.. c:function:: void glm_hvec3(hvec4 v4, hvec3 dest)
    
    init hvec3 using hvec4
    
    Parameters:
      | *[in]*  **v**    vector
      | *[out]* **dest** destination

.. c:function:: void glm_hvec3_copy(hvec3 a, hvec3 dest)
    
    copy all members of [a] to [dest]

    Parameters:
      | *[in]*  **a**    source vector
      | *[out]* **dest** destination

.. c:function:: void glm_hvec3_zero(hvec3 v)

    set all members of [v] to zero

    Parameters:
      | *[out]* **v** vector

.. c:function:: void glm_hvec3_one(hvec3 v)

    set all members of [v] to one

    Parameters:
      | *[out]* **v** vector

.. c:function:: void glm_hvec3_add(hvec3 a, hvec3 b, hvec3 dest)

    add vector [a] to vector [b] and store result in [dest]

    Parameters:
      | *[in]*  **a**    first vector
      | *[in]*  **b**    second vector
      | *[out]* **dest** destination

.. c:function:: void glm_hvec3_adds(hvec3 v, int16_t s, hvec3 dest)

    add scalar s to vector [v] and store result in [dest]
    
    Parameters:
      | *[in]*  **v**    vector
      | *[in]*  **s**    scalar
      | *[out]* **dest** destination

.. c:function:: void glm_hvec3_sub(hvec3 a, hvec3 b, hvec3 dest)

    subtract vector [b] from vector [a] and store result in [dest]

    Parameters:
      | *[in]*  **a**    first vector
      | *[in]*  **b**    second vector
      | *[out]* **dest** destination

.. c:function:: void glm_hvec3_subs(hvec3 v, int16_t s, hvec3 dest)

    subtract scalar s from vector [v] and store result in [dest]
    
    Parameters:
      | *[in]*  **v**    vector
      | *[in]*  **s**    scalar
      | *[out]* **dest** destination

.. c:function:: void glm_hvec3_mul(hvec3 a, hvec3 b, hvec3 dest)

    multiply vector [a] with vector [b] and store result in [dest]

    Parameters:
      | *[in]*  **a**    first vector
      | *[in]*  **b**    second vector
      | *[out]* **dest** destination

.. c:function:: void glm_hvec3_scale(hvec3 v, int16_t s, hvec3 dest)

    multiply vector [a] with scalar s and store result in [dest]
    
    Parameters:
      | *[in]*  **v**    vector
      | *[in]*  **s**    scalar
      | *[out]* **dest** destination

.. c:function:: int16_t glm_hvec3_distance2(hvec3 a, hvec3 b)

    squared distance between two vectors

    Parameters:
      | *[in]*  **a**    first vector
      | *[in]*  **b**    second vector
    
    Returns:
        squared distance (distance * distance)

.. c:function:: float glm_hvec3_distance(hvec3 a, hvec3 b)

    distance between two vectors

    Parameters:
      | *[in]*  **a**    first vector
      | *[in]*  **b**    second vector
    
    Returns:
        distance

.. c:function:: void  glm_hvec3_fill(hvec3 v, int16_t val)

    fill a vector with specified value

    Parameters:
      | *[out]*  **v**    vector
      | *[in]*   **val**  value

.. c:function:: bool  glm_hvec3_eq(hvec3 v, int16_t val)

    check if vector is equal to value

    Parameters:
      | *[in]*  **v**    vector
      | *[in]*  **val**  value

.. c:function:: bool  glm_hvec3_eqv(hvec3 v1, hvec3 v2)

    check if vector is equal to another vector

    Parameters:
      | *[in]*  **vec**   vector 1
      | *[in]*  **vec**   vector 2

.. c:function:: void glm_hvec3_maxv(hvec3 a, hvec3 b, hvec3 dest)

    set each member of dest to greater of vector a and b

    Parameters:
      | *[in]*  **a**    first vector
      | *[in]*  **b**    second vector
      | *[out]* **dest** destination

.. c:function:: void glm_hvec3_minv(hvec3 a, hvec3 b, hvec3 dest)

    set each member of dest to lesser of vector a and b

    Parameters:
      | *[in]*  **a**    first vector
      | *[in]*  **b**    second vector
      | *[out]* **dest** destination

.. c:function:: void glm_hvec3_clamp(hvec3 v, int16_t minVal, int16_t maxVal)

    clamp each member of [v] between minVal and maxVal (inclusive)

    Parameters:
      | *[in, out]* **v**      vector
      | *[in]*      **minVal** minimum value
      | *[in]*      **maxVal** maximum value

.. c:function:: void glm_hvec3_abs(hvec3 v, hvec3 dest)

    absolute value of each vector item

    Parameters:
      | *[in]*   **v**     vector
      | *[out]*  **dest**  destination vector
