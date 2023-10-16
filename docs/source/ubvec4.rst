.. default-domain:: C

ubvec4
=====

Header: cglm/ubvec4.h

Table of contents (click to go):
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

Macros:

1. GLM_UBVEC4_ONE_INIT
#. GLM_UBVEC4_ZERO_INIT
#. GLM_UBVEC4_ONE
#. GLM_UBVEC4_ZERO

Functions:

1. :c:func:`glm_ubvec4`
#. :c:func:`glm_ubvec4_copy`
#. :c:func:`glm_ubvec4_zero`
#. :c:func:`glm_ubvec4_one`
#. :c:func:`glm_ubvec4_add`
#. :c:func:`glm_ubvec4_adds`
#. :c:func:`glm_ubvec4_sub`
#. :c:func:`glm_ubvec4_subs`
#. :c:func:`glm_ubvec4_mul`
#. :c:func:`glm_ubvec4_scale`
#. :c:func:`glm_ubvec4_distance2`
#. :c:func:`glm_ubvec4_distance`
#. :c:func:`glm_ubvec4_maxv`
#. :c:func:`glm_ubvec4_minv`
#. :c:func:`glm_ubvec4_clamp`
#. :c:func:`glm_ubvec4_abs`

Functions documentation
~~~~~~~~~~~~~~~~~~~~~~~

.. c:function:: void glm_ubvec4(ubvec3 v3, uint8_t last, ubvec4 dest)
    
    init ubvec4 using ubvec3
    
    Parameters:
      | *[in]*  **v**    vector
      | *[out]* **dest** destination

.. c:function:: void glm_ubvec4_copy(ubvec4 a, ubvec4 dest)
    
    copy all members of [a] to [dest]

    Parameters:
      | *[in]*  **a**    source vector
      | *[out]* **dest** destination

.. c:function:: void glm_ubvec4_zero(ubvec4 v)

    set all members of [v] to zero

    Parameters:
      | *[out]* **v** vector

.. c:function:: void glm_ubvec4_one(ubvec4 v)

    set all members of [v] to one

    Parameters:
      | *[out]* **v** vector

.. c:function:: void glm_ubvec4_add(ubvec4 a, ubvec4 b, ubvec4 dest)

    add vector [a] to vector [b] and store result in [dest]

    Parameters:
      | *[in]*  **a**    first vector
      | *[in]*  **b**    second vector
      | *[out]* **dest** destination

.. c:function:: void glm_ubvec4_adds(ubvec4 v, uint8_t s, ubvec4 dest)

    add scalar s to vector [v] and store result in [dest]
    
    Parameters:
      | *[in]*  **v**    vector
      | *[in]*  **s**    scalar
      | *[out]* **dest** destination

.. c:function:: void glm_ubvec4_sub(ubvec4 a, ubvec4 b, ubvec4 dest)

    subtract vector [b] from vector [a] and store result in [dest]

    Parameters:
      | *[in]*  **a**    first vector
      | *[in]*  **b**    second vector
      | *[out]* **dest** destination

.. c:function:: void glm_ubvec4_subs(ubvec4 v, uint8_t s, ubvec4 dest)

    subtract scalar s from vector [v] and store result in [dest]
    
    Parameters:
      | *[in]*  **v**    vector
      | *[in]*  **s**    scalar
      | *[out]* **dest** destination

.. c:function:: void glm_ubvec4_mul(ubvec4 a, ubvec4 b, ubvec4 dest)

    multiply vector [a] with vector [b] and store result in [dest]

    Parameters:
      | *[in]*  **a**    first vector
      | *[in]*  **b**    second vector
      | *[out]* **dest** destination

.. c:function:: void glm_ubvec4_scale(ubvec4 v, uint8_t s, ubvec4 dest)

    multiply vector [a] with scalar s and store result in [dest]
    
    Parameters:
      | *[in]*  **v**    vector
      | *[in]*  **s**    scalar
      | *[out]* **dest** destination

.. c:function:: uint8_t glm_ubvec4_distance2(ubvec4 a, ubvec4 b)

    squared distance between two vectors

    Parameters:
      | *[in]*  **a**    first vector
      | *[in]*  **b**    second vector
    
    Returns:
        squared distance (distance * distance)

.. c:function:: float glm_ubvec4_distance(ubvec4 a, ubvec4 b)

    distance between two vectors

    Parameters:
      | *[in]*  **a**    first vector
      | *[in]*  **b**    second vector
    
    Returns:
        distance

.. c:function:: void glm_ubvec4_maxv(ubvec4 a, ubvec4 b, ubvec4 dest)

    set each member of dest to greater of vector a and b

    Parameters:
      | *[in]*  **a**    first vector
      | *[in]*  **b**    second vector
      | *[out]* **dest** destination

.. c:function:: void glm_ubvec4_minv(ubvec4 a, ubvec4 b, ubvec4 dest)

    set each member of dest to lesser of vector a and b

    Parameters:
      | *[in]*  **a**    first vector
      | *[in]*  **b**    second vector
      | *[out]* **dest** destination

.. c:function:: void glm_ubvec4_clamp(ubvec4 v, uint8_t minVal, uint8_t maxVal)

    clamp each member of [v] between minVal and maxVal (inclusive)

    Parameters:
      | *[in, out]* **v**      vector
      | *[in]*      **minVal** minimum value
      | *[in]*      **maxVal** maximum value

.. c:function:: void glm_ubvec4_abs(ubvec4 v, ubvec4 dest)

    absolute value of each vector item

    Parameters:
      | *[in]*   **v**     vector
      | *[out]*  **dest**  destination vector
