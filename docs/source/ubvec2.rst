.. default-domain:: C

ubvec2
=====

Header: cglm/ubvec2.h

Table of contents (click to go):
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

Macros:

1. GLM_UBVEC2_ONE_INIT
#. GLM_UBVEC2_ZERO_INIT
#. GLM_UBVEC2_ONE
#. GLM_UBVEC2_ZERO

Functions:

1. :c:func:`glm_ubvec2`
#. :c:func:`glm_ubvec2_copy`
#. :c:func:`glm_ubvec2_zero`
#. :c:func:`glm_ubvec2_one`
#. :c:func:`glm_ubvec2_add`
#. :c:func:`glm_ubvec2_adds`
#. :c:func:`glm_ubvec2_sub`
#. :c:func:`glm_ubvec2_subs`
#. :c:func:`glm_ubvec2_mul`
#. :c:func:`glm_ubvec2_scale`
#. :c:func:`glm_ubvec2_distance2`
#. :c:func:`glm_ubvec2_distance`
#. :c:func:`glm_ubvec2_maxv`
#. :c:func:`glm_ubvec2_minv`
#. :c:func:`glm_ubvec2_clamp`
#. :c:func:`glm_ubvec2_abs`

Functions documentation
~~~~~~~~~~~~~~~~~~~~~~~

.. c:function:: void glm_ubvec2(uint8_t * v, ubvec2 dest)
    
    init ubvec2 using vec3 or vec4
    
    Parameters:
      | *[in]*  **v**    vector
      | *[out]* **dest** destination

.. c:function:: void glm_ubvec2_copy(ubvec2 a, ubvec2 dest)
    
    copy all members of [a] to [dest]

    Parameters:
      | *[in]*  **a**    source vector
      | *[out]* **dest** destination

.. c:function:: void glm_ubvec2_zero(ubvec2 v)

    set all members of [v] to zero

    Parameters:
      | *[out]* **v** vector

.. c:function:: void glm_ubvec2_one(ubvec2 v)

    set all members of [v] to one

    Parameters:
      | *[out]* **v** vector

.. c:function:: void glm_ubvec2_add(ubvec2 a, ubvec2 b, ubvec2 dest)

    add vector [a] to vector [b] and store result in [dest]

    Parameters:
      | *[in]*  **a**    first vector
      | *[in]*  **b**    second vector
      | *[out]* **dest** destination

.. c:function:: void glm_ubvec2_adds(ubvec2 v, uint8_t s, ubvec2 dest)

    add scalar s to vector [v] and store result in [dest]
    
    Parameters:
      | *[in]*  **v**    vector
      | *[in]*  **s**    scalar
      | *[out]* **dest** destination

.. c:function:: void glm_ubvec2_sub(ubvec2 a, ubvec2 b, ubvec2 dest)

    subtract vector [b] from vector [a] and store result in [dest]

    Parameters:
      | *[in]*  **a**    first vector
      | *[in]*  **b**    second vector
      | *[out]* **dest** destination

.. c:function:: void glm_ubvec2_subs(ubvec2 v, uint8_t s, ubvec2 dest)

    subtract scalar s from vector [v] and store result in [dest]
    
    Parameters:
      | *[in]*  **v**    vector
      | *[in]*  **s**    scalar
      | *[out]* **dest** destination

.. c:function:: void glm_ubvec2_mul(ubvec2 a, ubvec2 b, ubvec2 dest)

    multiply vector [a] with vector [b] and store result in [dest]

    Parameters:
      | *[in]*  **a**    first vector
      | *[in]*  **b**    second vector
      | *[out]* **dest** destination

.. c:function:: void glm_ubvec2_scale(ubvec2 v, uint8_t s, ubvec2 dest)

    multiply vector [a] with scalar s and store result in [dest]
    
    Parameters:
      | *[in]*  **v**    vector
      | *[in]*  **s**    scalar
      | *[out]* **dest** destination

.. c:function:: uint8_t glm_ubvec2_distance2(ubvec2 a, ubvec2 b)

    squared distance between two vectors

    Parameters:
      | *[in]*  **a**    first vector
      | *[in]*  **b**    second vector
    
    Returns:
        squared distance (distance * distance)

.. c:function:: float glm_ubvec2_distance(ubvec2 a, ubvec2 b)

    distance between two vectors

    Parameters:
      | *[in]*  **a**    first vector
      | *[in]*  **b**    second vector
    
    Returns:
        distance

.. c:function:: void  glm_ubvec2_fill(ubvec2 v, uint8_t val)

    fill a vector with specified value

    Parameters:
      | *[out]*  **v**    vector
      | *[in]*   **val**  value

.. c:function:: bool  glm_ubvec2_eq(ubvec2 v, uint8_t val)

    check if vector is equal to value

    Parameters:
      | *[in]*  **v**    vector
      | *[in]*  **val**  value

.. c:function:: bool  glm_ubvec2_eqv(ubvec2 v1, ubvec2 v2)

    check if vector is equal to another vector

    Parameters:
      | *[in]*  **vec**   vector 1
      | *[in]*  **vec**   vector 2


.. c:function:: void glm_ubvec2_maxv(ubvec2 a, ubvec2 b, ubvec2 dest)

    set each member of dest to greater of vector a and b

    Parameters:
      | *[in]*  **a**    first vector
      | *[in]*  **b**    second vector
      | *[out]* **dest** destination

.. c:function:: void glm_ubvec2_minv(ubvec2 a, ubvec2 b, ubvec2 dest)

    set each member of dest to lesser of vector a and b

    Parameters:
      | *[in]*  **a**    first vector
      | *[in]*  **b**    second vector
      | *[out]* **dest** destination

.. c:function:: void glm_ubvec2_clamp(ubvec2 v, uint8_t minVal, uint8_t maxVal)

    clamp each member of [v] between minVal and maxVal (inclusive)

    Parameters:
      | *[in, out]* **v**      vector
      | *[in]*      **minVal** minimum value
      | *[in]*      **maxVal** maximum value

.. c:function:: void glm_ubvec2_abs(ubvec2 v, ubvec2 dest)

    absolute value of each vector item

    Parameters:
      | *[in]*   **v**     vector
      | *[out]*  **dest**  destination vector
