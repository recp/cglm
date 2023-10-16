.. default-domain:: C

uhvec2
=====

Header: cglm/uhvec2.h

Table of contents (click to go):
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

Macros:

1. GLM_UHVEC2_ONE_INIT
#. GLM_UHVEC2_ZERO_INIT
#. GLM_UHVEC2_ONE
#. GLM_UHVEC2_ZERO

Functions:

1. :c:func:`glm_uhvec2`
#. :c:func:`glm_uhvec2_copy`
#. :c:func:`glm_uhvec2_zero`
#. :c:func:`glm_uhvec2_one`
#. :c:func:`glm_uhvec2_add`
#. :c:func:`glm_uhvec2_adds`
#. :c:func:`glm_uhvec2_sub`
#. :c:func:`glm_uhvec2_subs`
#. :c:func:`glm_uhvec2_mul`
#. :c:func:`glm_uhvec2_scale`
#. :c:func:`glm_uhvec2_distance2`
#. :c:func:`glm_uhvec2_distance`
#. :c:func:`glm_uhvec2_maxv`
#. :c:func:`glm_uhvec2_minv`
#. :c:func:`glm_uhvec2_clamp`
#. :c:func:`glm_uhvec2_abs`

Functions documentation
~~~~~~~~~~~~~~~~~~~~~~~

.. c:function:: void glm_uhvec2(uint16_t * v, uhvec2 dest)
    
    init uhvec2 using vec3 or vec4
    
    Parameters:
      | *[in]*  **v**    vector
      | *[out]* **dest** destination

.. c:function:: void glm_uhvec2_copy(uhvec2 a, uhvec2 dest)
    
    copy all members of [a] to [dest]

    Parameters:
      | *[in]*  **a**    source vector
      | *[out]* **dest** destination

.. c:function:: void glm_uhvec2_zero(uhvec2 v)

    set all members of [v] to zero

    Parameters:
      | *[out]* **v** vector

.. c:function:: void glm_uhvec2_one(uhvec2 v)

    set all members of [v] to one

    Parameters:
      | *[out]* **v** vector

.. c:function:: void glm_uhvec2_add(uhvec2 a, uhvec2 b, uhvec2 dest)

    add vector [a] to vector [b] and store result in [dest]

    Parameters:
      | *[in]*  **a**    first vector
      | *[in]*  **b**    second vector
      | *[out]* **dest** destination

.. c:function:: void glm_uhvec2_adds(uhvec2 v, uint16_t s, uhvec2 dest)

    add scalar s to vector [v] and store result in [dest]
    
    Parameters:
      | *[in]*  **v**    vector
      | *[in]*  **s**    scalar
      | *[out]* **dest** destination

.. c:function:: void glm_uhvec2_sub(uhvec2 a, uhvec2 b, uhvec2 dest)

    subtract vector [b] from vector [a] and store result in [dest]

    Parameters:
      | *[in]*  **a**    first vector
      | *[in]*  **b**    second vector
      | *[out]* **dest** destination

.. c:function:: void glm_uhvec2_subs(uhvec2 v, uint16_t s, uhvec2 dest)

    subtract scalar s from vector [v] and store result in [dest]
    
    Parameters:
      | *[in]*  **v**    vector
      | *[in]*  **s**    scalar
      | *[out]* **dest** destination

.. c:function:: void glm_uhvec2_mul(uhvec2 a, uhvec2 b, uhvec2 dest)

    multiply vector [a] with vector [b] and store result in [dest]

    Parameters:
      | *[in]*  **a**    first vector
      | *[in]*  **b**    second vector
      | *[out]* **dest** destination

.. c:function:: void glm_uhvec2_scale(uhvec2 v, uint16_t s, uhvec2 dest)

    multiply vector [a] with scalar s and store result in [dest]
    
    Parameters:
      | *[in]*  **v**    vector
      | *[in]*  **s**    scalar
      | *[out]* **dest** destination

.. c:function:: uint16_t glm_uhvec2_distance2(uhvec2 a, uhvec2 b)

    squared distance between two vectors

    Parameters:
      | *[in]*  **a**    first vector
      | *[in]*  **b**    second vector
    
    Returns:
        squared distance (distance * distance)

.. c:function:: float glm_uhvec2_distance(uhvec2 a, uhvec2 b)

    distance between two vectors

    Parameters:
      | *[in]*  **a**    first vector
      | *[in]*  **b**    second vector
    
    Returns:
        distance

.. c:function:: void  glm_uhvec2_fill(uhvec2 v, uint16_t val)

    fill a vector with specified value

    Parameters:
      | *[out]*  **v**    vector
      | *[in]*   **val**  value

.. c:function:: bool  glm_uhvec2_eq(uhvec2 v, uint16_t val)

    check if vector is equal to value

    Parameters:
      | *[in]*  **v**    vector
      | *[in]*  **val**  value

.. c:function:: bool  glm_uhvec2_eqv(uhvec2 v1, uhvec2 v2)

    check if vector is equal to another vector

    Parameters:
      | *[in]*  **vec**   vector 1
      | *[in]*  **vec**   vector 2


.. c:function:: void glm_uhvec2_maxv(uhvec2 a, uhvec2 b, uhvec2 dest)

    set each member of dest to greater of vector a and b

    Parameters:
      | *[in]*  **a**    first vector
      | *[in]*  **b**    second vector
      | *[out]* **dest** destination

.. c:function:: void glm_uhvec2_minv(uhvec2 a, uhvec2 b, uhvec2 dest)

    set each member of dest to lesser of vector a and b

    Parameters:
      | *[in]*  **a**    first vector
      | *[in]*  **b**    second vector
      | *[out]* **dest** destination

.. c:function:: void glm_uhvec2_clamp(uhvec2 v, uint16_t minVal, uint16_t maxVal)

    clamp each member of [v] between minVal and maxVal (inclusive)

    Parameters:
      | *[in, out]* **v**      vector
      | *[in]*      **minVal** minimum value
      | *[in]*      **maxVal** maximum value

.. c:function:: void glm_uhvec2_abs(uhvec2 v, uhvec2 dest)

    absolute value of each vector item

    Parameters:
      | *[in]*   **v**     vector
      | *[out]*  **dest**  destination vector
