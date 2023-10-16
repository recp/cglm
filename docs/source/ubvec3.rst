.. default-domain:: C

ubvec3
=====

Header: cglm/ubvec3.h

Table of contents (click to go):
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

Macros:

1. GLM_UBVEC3_ONE_INIT
#. GLM_UBVEC3_ZERO_INIT
#. GLM_UBVEC3_ONE
#. GLM_UBVEC3_ZERO

Functions:

1. :c:func:`glm_ubvec3`
#. :c:func:`glm_ubvec3_copy`
#. :c:func:`glm_ubvec3_zero`
#. :c:func:`glm_ubvec3_one`
#. :c:func:`glm_ubvec3_add`
#. :c:func:`glm_ubvec3_adds`
#. :c:func:`glm_ubvec3_sub`
#. :c:func:`glm_ubvec3_subs`
#. :c:func:`glm_ubvec3_mul`
#. :c:func:`glm_ubvec3_scale`
#. :c:func:`glm_ubvec3_distance2`
#. :c:func:`glm_ubvec3_distance`
#. :c:func:`glm_ubvec3_fill`
#. :c:func:`glm_ubvec3_eq`
#. :c:func:`glm_ubvec3_eqv`
#. :c:func:`glm_ubvec3_maxv`
#. :c:func:`glm_ubvec3_minv`
#. :c:func:`glm_ubvec3_clamp`
#. :c:func:`glm_ubvec2_abs`

Functions documentation
~~~~~~~~~~~~~~~~~~~~~~~

.. c:function:: void glm_ubvec3(ubvec4 v4, ubvec3 dest)
    
    init ubvec3 using ubvec4
    
    Parameters:
      | *[in]*  **v**    vector
      | *[out]* **dest** destination

.. c:function:: void glm_ubvec3_copy(ubvec3 a, ubvec3 dest)
    
    copy all members of [a] to [dest]

    Parameters:
      | *[in]*  **a**    source vector
      | *[out]* **dest** destination

.. c:function:: void glm_ubvec3_zero(ubvec3 v)

    set all members of [v] to zero

    Parameters:
      | *[out]* **v** vector

.. c:function:: void glm_ubvec3_one(ubvec3 v)

    set all members of [v] to one

    Parameters:
      | *[out]* **v** vector

.. c:function:: void glm_ubvec3_add(ubvec3 a, ubvec3 b, ubvec3 dest)

    add vector [a] to vector [b] and store result in [dest]

    Parameters:
      | *[in]*  **a**    first vector
      | *[in]*  **b**    second vector
      | *[out]* **dest** destination

.. c:function:: void glm_ubvec3_adds(ubvec3 v, uint8_t s, ubvec3 dest)

    add scalar s to vector [v] and store result in [dest]
    
    Parameters:
      | *[in]*  **v**    vector
      | *[in]*  **s**    scalar
      | *[out]* **dest** destination

.. c:function:: void glm_ubvec3_sub(ubvec3 a, ubvec3 b, ubvec3 dest)

    subtract vector [b] from vector [a] and store result in [dest]

    Parameters:
      | *[in]*  **a**    first vector
      | *[in]*  **b**    second vector
      | *[out]* **dest** destination

.. c:function:: void glm_ubvec3_subs(ubvec3 v, uint8_t s, ubvec3 dest)

    subtract scalar s from vector [v] and store result in [dest]
    
    Parameters:
      | *[in]*  **v**    vector
      | *[in]*  **s**    scalar
      | *[out]* **dest** destination

.. c:function:: void glm_ubvec3_mul(ubvec3 a, ubvec3 b, ubvec3 dest)

    multiply vector [a] with vector [b] and store result in [dest]

    Parameters:
      | *[in]*  **a**    first vector
      | *[in]*  **b**    second vector
      | *[out]* **dest** destination

.. c:function:: void glm_ubvec3_scale(ubvec3 v, uint8_t s, ubvec3 dest)

    multiply vector [a] with scalar s and store result in [dest]
    
    Parameters:
      | *[in]*  **v**    vector
      | *[in]*  **s**    scalar
      | *[out]* **dest** destination

.. c:function:: uint8_t glm_ubvec3_distance2(ubvec3 a, ubvec3 b)

    squared distance between two vectors

    Parameters:
      | *[in]*  **a**    first vector
      | *[in]*  **b**    second vector
    
    Returns:
        squared distance (distance * distance)

.. c:function:: float glm_ubvec3_distance(ubvec3 a, ubvec3 b)

    distance between two vectors

    Parameters:
      | *[in]*  **a**    first vector
      | *[in]*  **b**    second vector
    
    Returns:
        distance

.. c:function:: void  glm_ubvec3_fill(ubvec3 v, uint8_t val)

    fill a vector with specified value

    Parameters:
      | *[out]*  **v**    vector
      | *[in]*   **val**  value

.. c:function:: bool  glm_ubvec3_eq(ubvec3 v, uint8_t val)

    check if vector is equal to value

    Parameters:
      | *[in]*  **v**    vector
      | *[in]*  **val**  value

.. c:function:: bool  glm_ubvec3_eqv(ubvec3 v1, ubvec3 v2)

    check if vector is equal to another vector

    Parameters:
      | *[in]*  **vec**   vector 1
      | *[in]*  **vec**   vector 2

.. c:function:: void glm_ubvec3_maxv(ubvec3 a, ubvec3 b, ubvec3 dest)

    set each member of dest to greater of vector a and b

    Parameters:
      | *[in]*  **a**    first vector
      | *[in]*  **b**    second vector
      | *[out]* **dest** destination

.. c:function:: void glm_ubvec3_minv(ubvec3 a, ubvec3 b, ubvec3 dest)

    set each member of dest to lesser of vector a and b

    Parameters:
      | *[in]*  **a**    first vector
      | *[in]*  **b**    second vector
      | *[out]* **dest** destination

.. c:function:: void glm_ubvec3_clamp(ubvec3 v, uint8_t minVal, uint8_t maxVal)

    clamp each member of [v] between minVal and maxVal (inclusive)

    Parameters:
      | *[in, out]* **v**      vector
      | *[in]*      **minVal** minimum value
      | *[in]*      **maxVal** maximum value

.. c:function:: void glm_ubvec3_abs(ubvec3 v, ubvec3 dest)

    absolute value of each vector item

    Parameters:
      | *[in]*   **v**     vector
      | *[out]*  **dest**  destination vector
