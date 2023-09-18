.. default-domain:: C

bvec4
=====

Header: cglm/bvec4.h

Table of contents (click to go):
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

Macros:

1. GLM_BVEC4_ONE_INIT
#. GLM_BVEC4_ZERO_INIT
#. GLM_BVEC4_ONE
#. GLM_BVEC4_ZERO

Functions:

1. :c:func:`glm_bvec4`
#. :c:func:`glm_bvec4_copy`
#. :c:func:`glm_bvec4_zero`
#. :c:func:`glm_bvec4_one`
#. :c:func:`glm_bvec4_add`
#. :c:func:`glm_bvec4_adds`
#. :c:func:`glm_bvec4_sub`
#. :c:func:`glm_bvec4_subs`
#. :c:func:`glm_bvec4_mul`
#. :c:func:`glm_bvec4_scale`
#. :c:func:`glm_bvec4_distance2`
#. :c:func:`glm_bvec4_distance`
#. :c:func:`glm_bvec4_maxv`
#. :c:func:`glm_bvec4_minv`
#. :c:func:`glm_bvec4_clamp`
#. :c:func:`glm_bvec4_abs`

Functions documentation
~~~~~~~~~~~~~~~~~~~~~~~

.. c:function:: void glm_bvec4(bvec3 v3, int8_t last, bvec4 dest)
    
    init bvec4 using bvec3
    
    Parameters:
      | *[in]*  **v**    vector
      | *[out]* **dest** destination

.. c:function:: void glm_bvec4_copy(bvec4 a, bvec4 dest)
    
    copy all members of [a] to [dest]

    Parameters:
      | *[in]*  **a**    source vector
      | *[out]* **dest** destination

.. c:function:: void glm_bvec4_zero(bvec4 v)

    set all members of [v] to zero

    Parameters:
      | *[out]* **v** vector

.. c:function:: void glm_bvec4_one(bvec4 v)

    set all members of [v] to one

    Parameters:
      | *[out]* **v** vector

.. c:function:: void glm_bvec4_add(bvec4 a, bvec4 b, bvec4 dest)

    add vector [a] to vector [b] and store result in [dest]

    Parameters:
      | *[in]*  **a**    first vector
      | *[in]*  **b**    second vector
      | *[out]* **dest** destination

.. c:function:: void glm_bvec4_adds(bvec4 v, int8_t s, bvec4 dest)

    add scalar s to vector [v] and store result in [dest]
    
    Parameters:
      | *[in]*  **v**    vector
      | *[in]*  **s**    scalar
      | *[out]* **dest** destination

.. c:function:: void glm_bvec4_sub(bvec4 a, bvec4 b, bvec4 dest)

    subtract vector [b] from vector [a] and store result in [dest]

    Parameters:
      | *[in]*  **a**    first vector
      | *[in]*  **b**    second vector
      | *[out]* **dest** destination

.. c:function:: void glm_bvec4_subs(bvec4 v, int8_t s, bvec4 dest)

    subtract scalar s from vector [v] and store result in [dest]
    
    Parameters:
      | *[in]*  **v**    vector
      | *[in]*  **s**    scalar
      | *[out]* **dest** destination

.. c:function:: void glm_bvec4_mul(bvec4 a, bvec4 b, bvec4 dest)

    multiply vector [a] with vector [b] and store result in [dest]

    Parameters:
      | *[in]*  **a**    first vector
      | *[in]*  **b**    second vector
      | *[out]* **dest** destination

.. c:function:: void glm_bvec4_scale(bvec4 v, int8_t s, bvec4 dest)

    multiply vector [a] with scalar s and store result in [dest]
    
    Parameters:
      | *[in]*  **v**    vector
      | *[in]*  **s**    scalar
      | *[out]* **dest** destination

.. c:function:: int8_t glm_bvec4_distance2(bvec4 a, bvec4 b)

    squared distance between two vectors

    Parameters:
      | *[in]*  **a**    first vector
      | *[in]*  **b**    second vector
    
    Returns:
        squared distance (distance * distance)

.. c:function:: float glm_bvec4_distance(bvec4 a, bvec4 b)

    distance between two vectors

    Parameters:
      | *[in]*  **a**    first vector
      | *[in]*  **b**    second vector
    
    Returns:
        distance

.. c:function:: void glm_bvec4_maxv(bvec4 a, bvec4 b, bvec4 dest)

    set each member of dest to greater of vector a and b

    Parameters:
      | *[in]*  **a**    first vector
      | *[in]*  **b**    second vector
      | *[out]* **dest** destination

.. c:function:: void glm_bvec4_minv(bvec4 a, bvec4 b, bvec4 dest)

    set each member of dest to lesser of vector a and b

    Parameters:
      | *[in]*  **a**    first vector
      | *[in]*  **b**    second vector
      | *[out]* **dest** destination

.. c:function:: void glm_bvec4_clamp(bvec4 v, int8_t minVal, int8_t maxVal)

    clamp each member of [v] between minVal and maxVal (inclusive)

    Parameters:
      | *[in, out]* **v**      vector
      | *[in]*      **minVal** minimum value
      | *[in]*      **maxVal** maximum value

.. c:function:: void glm_bvec4_abs(bvec4 v, bvec4 dest)

    absolute value of each vector item

    Parameters:
      | *[in]*   **v**     vector
      | *[out]*  **dest**  destination vector
