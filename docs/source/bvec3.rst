.. default-domain:: C

bvec3
=====

Header: cglm/bvec3.h

Table of contents (click to go):
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

Macros:

1. GLM_BVEC3_ONE_INIT
#. GLM_BVEC3_ZERO_INIT
#. GLM_BVEC3_ONE
#. GLM_BVEC3_ZERO

Functions:

1. :c:func:`glm_bvec3`
#. :c:func:`glm_bvec3_copy`
#. :c:func:`glm_bvec3_zero`
#. :c:func:`glm_bvec3_one`
#. :c:func:`glm_bvec3_add`
#. :c:func:`glm_bvec3_adds`
#. :c:func:`glm_bvec3_sub`
#. :c:func:`glm_bvec3_subs`
#. :c:func:`glm_bvec3_mul`
#. :c:func:`glm_bvec3_scale`
#. :c:func:`glm_bvec3_distance2`
#. :c:func:`glm_bvec3_distance`
#. :c:func:`glm_bvec3_fill`
#. :c:func:`glm_bvec3_eq`
#. :c:func:`glm_bvec3_eqv`
#. :c:func:`glm_bvec3_maxv`
#. :c:func:`glm_bvec3_minv`
#. :c:func:`glm_bvec3_clamp`
#. :c:func:`glm_bvec2_abs`

Functions documentation
~~~~~~~~~~~~~~~~~~~~~~~

.. c:function:: void glm_bvec3(bvec4 v4, bvec3 dest)
    
    init bvec3 using bvec4
    
    Parameters:
      | *[in]*  **v**    vector
      | *[out]* **dest** destination

.. c:function:: void glm_bvec3_copy(bvec3 a, bvec3 dest)
    
    copy all members of [a] to [dest]

    Parameters:
      | *[in]*  **a**    source vector
      | *[out]* **dest** destination

.. c:function:: void glm_bvec3_zero(bvec3 v)

    set all members of [v] to zero

    Parameters:
      | *[out]* **v** vector

.. c:function:: void glm_bvec3_one(bvec3 v)

    set all members of [v] to one

    Parameters:
      | *[out]* **v** vector

.. c:function:: void glm_bvec3_add(bvec3 a, bvec3 b, bvec3 dest)

    add vector [a] to vector [b] and store result in [dest]

    Parameters:
      | *[in]*  **a**    first vector
      | *[in]*  **b**    second vector
      | *[out]* **dest** destination

.. c:function:: void glm_bvec3_adds(bvec3 v, int8_t s, bvec3 dest)

    add scalar s to vector [v] and store result in [dest]
    
    Parameters:
      | *[in]*  **v**    vector
      | *[in]*  **s**    scalar
      | *[out]* **dest** destination

.. c:function:: void glm_bvec3_sub(bvec3 a, bvec3 b, bvec3 dest)

    subtract vector [b] from vector [a] and store result in [dest]

    Parameters:
      | *[in]*  **a**    first vector
      | *[in]*  **b**    second vector
      | *[out]* **dest** destination

.. c:function:: void glm_bvec3_subs(bvec3 v, int8_t s, bvec3 dest)

    subtract scalar s from vector [v] and store result in [dest]
    
    Parameters:
      | *[in]*  **v**    vector
      | *[in]*  **s**    scalar
      | *[out]* **dest** destination

.. c:function:: void glm_bvec3_mul(bvec3 a, bvec3 b, bvec3 dest)

    multiply vector [a] with vector [b] and store result in [dest]

    Parameters:
      | *[in]*  **a**    first vector
      | *[in]*  **b**    second vector
      | *[out]* **dest** destination

.. c:function:: void glm_bvec3_scale(bvec3 v, int8_t s, bvec3 dest)

    multiply vector [a] with scalar s and store result in [dest]
    
    Parameters:
      | *[in]*  **v**    vector
      | *[in]*  **s**    scalar
      | *[out]* **dest** destination

.. c:function:: int8_t glm_bvec3_distance2(bvec3 a, bvec3 b)

    squared distance between two vectors

    Parameters:
      | *[in]*  **a**    first vector
      | *[in]*  **b**    second vector
    
    Returns:
        squared distance (distance * distance)

.. c:function:: float glm_bvec3_distance(bvec3 a, bvec3 b)

    distance between two vectors

    Parameters:
      | *[in]*  **a**    first vector
      | *[in]*  **b**    second vector
    
    Returns:
        distance

.. c:function:: void  glm_bvec3_fill(bvec3 v, int8_t val)

    fill a vector with specified value

    Parameters:
      | *[out]*  **v**    vector
      | *[in]*   **val**  value

.. c:function:: bool  glm_bvec3_eq(bvec3 v, int8_t val)

    check if vector is equal to value

    Parameters:
      | *[in]*  **v**    vector
      | *[in]*  **val**  value

.. c:function:: bool  glm_bvec3_eqv(bvec3 v1, bvec3 v2)

    check if vector is equal to another vector

    Parameters:
      | *[in]*  **vec**   vector 1
      | *[in]*  **vec**   vector 2

.. c:function:: void glm_bvec3_maxv(bvec3 a, bvec3 b, bvec3 dest)

    set each member of dest to greater of vector a and b

    Parameters:
      | *[in]*  **a**    first vector
      | *[in]*  **b**    second vector
      | *[out]* **dest** destination

.. c:function:: void glm_bvec3_minv(bvec3 a, bvec3 b, bvec3 dest)

    set each member of dest to lesser of vector a and b

    Parameters:
      | *[in]*  **a**    first vector
      | *[in]*  **b**    second vector
      | *[out]* **dest** destination

.. c:function:: void glm_bvec3_clamp(bvec3 v, int8_t minVal, int8_t maxVal)

    clamp each member of [v] between minVal and maxVal (inclusive)

    Parameters:
      | *[in, out]* **v**      vector
      | *[in]*      **minVal** minimum value
      | *[in]*      **maxVal** maximum value

.. c:function:: void glm_bvec3_abs(bvec3 v, bvec3 dest)

    absolute value of each vector item

    Parameters:
      | *[in]*   **v**     vector
      | *[out]*  **dest**  destination vector
