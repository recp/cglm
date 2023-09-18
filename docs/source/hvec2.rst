.. default-domain:: C

hvec2
=====

Header: cglm/hvec2.h

Table of contents (click to go):
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

Macros:

1. GLM_HVEC2_ONE_INIT
#. GLM_HVEC2_ZERO_INIT
#. GLM_HVEC2_ONE
#. GLM_HVEC2_ZERO

Functions:

1. :c:func:`glm_hvec2`
#. :c:func:`glm_hvec2_copy`
#. :c:func:`glm_hvec2_zero`
#. :c:func:`glm_hvec2_one`
#. :c:func:`glm_hvec2_add`
#. :c:func:`glm_hvec2_adds`
#. :c:func:`glm_hvec2_sub`
#. :c:func:`glm_hvec2_subs`
#. :c:func:`glm_hvec2_mul`
#. :c:func:`glm_hvec2_scale`
#. :c:func:`glm_hvec2_distance2`
#. :c:func:`glm_hvec2_distance`
#. :c:func:`glm_hvec2_maxv`
#. :c:func:`glm_hvec2_minv`
#. :c:func:`glm_hvec2_clamp`
#. :c:func:`glm_hvec2_abs`

Functions documentation
~~~~~~~~~~~~~~~~~~~~~~~

.. c:function:: void glm_hvec2(int16_t * v, hvec2 dest)
    
    init hvec2 using vec3 or vec4
    
    Parameters:
      | *[in]*  **v**    vector
      | *[out]* **dest** destination

.. c:function:: void glm_hvec2_copy(hvec2 a, hvec2 dest)
    
    copy all members of [a] to [dest]

    Parameters:
      | *[in]*  **a**    source vector
      | *[out]* **dest** destination

.. c:function:: void glm_hvec2_zero(hvec2 v)

    set all members of [v] to zero

    Parameters:
      | *[out]* **v** vector

.. c:function:: void glm_hvec2_one(hvec2 v)

    set all members of [v] to one

    Parameters:
      | *[out]* **v** vector

.. c:function:: void glm_hvec2_add(hvec2 a, hvec2 b, hvec2 dest)

    add vector [a] to vector [b] and store result in [dest]

    Parameters:
      | *[in]*  **a**    first vector
      | *[in]*  **b**    second vector
      | *[out]* **dest** destination

.. c:function:: void glm_hvec2_adds(hvec2 v, int16_t s, hvec2 dest)

    add scalar s to vector [v] and store result in [dest]
    
    Parameters:
      | *[in]*  **v**    vector
      | *[in]*  **s**    scalar
      | *[out]* **dest** destination

.. c:function:: void glm_hvec2_sub(hvec2 a, hvec2 b, hvec2 dest)

    subtract vector [b] from vector [a] and store result in [dest]

    Parameters:
      | *[in]*  **a**    first vector
      | *[in]*  **b**    second vector
      | *[out]* **dest** destination

.. c:function:: void glm_hvec2_subs(hvec2 v, int16_t s, hvec2 dest)

    subtract scalar s from vector [v] and store result in [dest]
    
    Parameters:
      | *[in]*  **v**    vector
      | *[in]*  **s**    scalar
      | *[out]* **dest** destination

.. c:function:: void glm_hvec2_mul(hvec2 a, hvec2 b, hvec2 dest)

    multiply vector [a] with vector [b] and store result in [dest]

    Parameters:
      | *[in]*  **a**    first vector
      | *[in]*  **b**    second vector
      | *[out]* **dest** destination

.. c:function:: void glm_hvec2_scale(hvec2 v, int16_t s, hvec2 dest)

    multiply vector [a] with scalar s and store result in [dest]
    
    Parameters:
      | *[in]*  **v**    vector
      | *[in]*  **s**    scalar
      | *[out]* **dest** destination

.. c:function:: int16_t glm_hvec2_distance2(hvec2 a, hvec2 b)

    squared distance between two vectors

    Parameters:
      | *[in]*  **a**    first vector
      | *[in]*  **b**    second vector
    
    Returns:
        squared distance (distance * distance)

.. c:function:: float glm_hvec2_distance(hvec2 a, hvec2 b)

    distance between two vectors

    Parameters:
      | *[in]*  **a**    first vector
      | *[in]*  **b**    second vector
    
    Returns:
        distance

.. c:function:: void  glm_hvec2_fill(hvec2 v, int16_t val)

    fill a vector with specified value

    Parameters:
      | *[out]*  **v**    vector
      | *[in]*   **val**  value

.. c:function:: bool  glm_hvec2_eq(hvec2 v, int16_t val)

    check if vector is equal to value

    Parameters:
      | *[in]*  **v**    vector
      | *[in]*  **val**  value

.. c:function:: bool  glm_hvec2_eqv(hvec2 v1, hvec2 v2)

    check if vector is equal to another vector

    Parameters:
      | *[in]*  **vec**   vector 1
      | *[in]*  **vec**   vector 2


.. c:function:: void glm_hvec2_maxv(hvec2 a, hvec2 b, hvec2 dest)

    set each member of dest to greater of vector a and b

    Parameters:
      | *[in]*  **a**    first vector
      | *[in]*  **b**    second vector
      | *[out]* **dest** destination

.. c:function:: void glm_hvec2_minv(hvec2 a, hvec2 b, hvec2 dest)

    set each member of dest to lesser of vector a and b

    Parameters:
      | *[in]*  **a**    first vector
      | *[in]*  **b**    second vector
      | *[out]* **dest** destination

.. c:function:: void glm_hvec2_clamp(hvec2 v, int16_t minVal, int16_t maxVal)

    clamp each member of [v] between minVal and maxVal (inclusive)

    Parameters:
      | *[in, out]* **v**      vector
      | *[in]*      **minVal** minimum value
      | *[in]*      **maxVal** maximum value

.. c:function:: void glm_hvec2_abs(hvec2 v, hvec2 dest)

    absolute value of each vector item

    Parameters:
      | *[in]*   **v**     vector
      | *[out]*  **dest**  destination vector
