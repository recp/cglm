.. default-domain:: C

uhvec3
=====

Header: cglm/uhvec3.h

Table of contents (click to go):
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

Macros:

1. GLM_UHVEC3_ONE_INIT
#. GLM_UHVEC3_ZERO_INIT
#. GLM_UHVEC3_ONE
#. GLM_UHVEC3_ZERO

Functions:

1. :c:func:`glm_uhvec3`
#. :c:func:`glm_uhvec3_copy`
#. :c:func:`glm_uhvec3_zero`
#. :c:func:`glm_uhvec3_one`
#. :c:func:`glm_uhvec3_add`
#. :c:func:`glm_uhvec3_adds`
#. :c:func:`glm_uhvec3_sub`
#. :c:func:`glm_uhvec3_subs`
#. :c:func:`glm_uhvec3_mul`
#. :c:func:`glm_uhvec3_scale`
#. :c:func:`glm_uhvec3_distance2`
#. :c:func:`glm_uhvec3_distance`
#. :c:func:`glm_uhvec3_fill`
#. :c:func:`glm_uhvec3_eq`
#. :c:func:`glm_uhvec3_eqv`
#. :c:func:`glm_uhvec3_maxv`
#. :c:func:`glm_uhvec3_minv`
#. :c:func:`glm_uhvec3_clamp`
#. :c:func:`glm_uhvec2_abs`

Functions documentation
~~~~~~~~~~~~~~~~~~~~~~~

.. c:function:: void glm_uhvec3(uhvec4 v4, uhvec3 dest)
    
    init uhvec3 using uhvec4
    
    Parameters:
      | *[in]*  **v**    vector
      | *[out]* **dest** destination

.. c:function:: void glm_uhvec3_copy(uhvec3 a, uhvec3 dest)
    
    copy all members of [a] to [dest]

    Parameters:
      | *[in]*  **a**    source vector
      | *[out]* **dest** destination

.. c:function:: void glm_uhvec3_zero(uhvec3 v)

    set all members of [v] to zero

    Parameters:
      | *[out]* **v** vector

.. c:function:: void glm_uhvec3_one(uhvec3 v)

    set all members of [v] to one

    Parameters:
      | *[out]* **v** vector

.. c:function:: void glm_uhvec3_add(uhvec3 a, uhvec3 b, uhvec3 dest)

    add vector [a] to vector [b] and store result in [dest]

    Parameters:
      | *[in]*  **a**    first vector
      | *[in]*  **b**    second vector
      | *[out]* **dest** destination

.. c:function:: void glm_uhvec3_adds(uhvec3 v, uint16_t s, uhvec3 dest)

    add scalar s to vector [v] and store result in [dest]
    
    Parameters:
      | *[in]*  **v**    vector
      | *[in]*  **s**    scalar
      | *[out]* **dest** destination

.. c:function:: void glm_uhvec3_sub(uhvec3 a, uhvec3 b, uhvec3 dest)

    subtract vector [b] from vector [a] and store result in [dest]

    Parameters:
      | *[in]*  **a**    first vector
      | *[in]*  **b**    second vector
      | *[out]* **dest** destination

.. c:function:: void glm_uhvec3_subs(uhvec3 v, uint16_t s, uhvec3 dest)

    subtract scalar s from vector [v] and store result in [dest]
    
    Parameters:
      | *[in]*  **v**    vector
      | *[in]*  **s**    scalar
      | *[out]* **dest** destination

.. c:function:: void glm_uhvec3_mul(uhvec3 a, uhvec3 b, uhvec3 dest)

    multiply vector [a] with vector [b] and store result in [dest]

    Parameters:
      | *[in]*  **a**    first vector
      | *[in]*  **b**    second vector
      | *[out]* **dest** destination

.. c:function:: void glm_uhvec3_scale(uhvec3 v, uint16_t s, uhvec3 dest)

    multiply vector [a] with scalar s and store result in [dest]
    
    Parameters:
      | *[in]*  **v**    vector
      | *[in]*  **s**    scalar
      | *[out]* **dest** destination

.. c:function:: uint16_t glm_uhvec3_distance2(uhvec3 a, uhvec3 b)

    squared distance between two vectors

    Parameters:
      | *[in]*  **a**    first vector
      | *[in]*  **b**    second vector
    
    Returns:
        squared distance (distance * distance)

.. c:function:: float glm_uhvec3_distance(uhvec3 a, uhvec3 b)

    distance between two vectors

    Parameters:
      | *[in]*  **a**    first vector
      | *[in]*  **b**    second vector
    
    Returns:
        distance

.. c:function:: void  glm_uhvec3_fill(uhvec3 v, uint16_t val)

    fill a vector with specified value

    Parameters:
      | *[out]*  **v**    vector
      | *[in]*   **val**  value

.. c:function:: bool  glm_uhvec3_eq(uhvec3 v, uint16_t val)

    check if vector is equal to value

    Parameters:
      | *[in]*  **v**    vector
      | *[in]*  **val**  value

.. c:function:: bool  glm_uhvec3_eqv(uhvec3 v1, uhvec3 v2)

    check if vector is equal to another vector

    Parameters:
      | *[in]*  **vec**   vector 1
      | *[in]*  **vec**   vector 2

.. c:function:: void glm_uhvec3_maxv(uhvec3 a, uhvec3 b, uhvec3 dest)

    set each member of dest to greater of vector a and b

    Parameters:
      | *[in]*  **a**    first vector
      | *[in]*  **b**    second vector
      | *[out]* **dest** destination

.. c:function:: void glm_uhvec3_minv(uhvec3 a, uhvec3 b, uhvec3 dest)

    set each member of dest to lesser of vector a and b

    Parameters:
      | *[in]*  **a**    first vector
      | *[in]*  **b**    second vector
      | *[out]* **dest** destination

.. c:function:: void glm_uhvec3_clamp(uhvec3 v, uint16_t minVal, uint16_t maxVal)

    clamp each member of [v] between minVal and maxVal (inclusive)

    Parameters:
      | *[in, out]* **v**      vector
      | *[in]*      **minVal** minimum value
      | *[in]*      **maxVal** maximum value

.. c:function:: void glm_uhvec3_abs(uhvec3 v, uhvec3 dest)

    absolute value of each vector item

    Parameters:
      | *[in]*   **v**     vector
      | *[out]*  **dest**  destination vector
