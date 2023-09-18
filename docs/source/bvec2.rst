.. default-domain:: C

bvec2
=====

Header: cglm/bvec2.h

Table of contents (click to go):
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

Macros:

1. GLM_BVEC2_ONE_INIT
#. GLM_BVEC2_ZERO_INIT
#. GLM_BVEC2_ONE
#. GLM_BVEC2_ZERO

Functions:

1. :c:func:`glm_bvec2`
#. :c:func:`glm_bvec2_copy`
#. :c:func:`glm_bvec2_zero`
#. :c:func:`glm_bvec2_one`
#. :c:func:`glm_bvec2_add`
#. :c:func:`glm_bvec2_adds`
#. :c:func:`glm_bvec2_sub`
#. :c:func:`glm_bvec2_subs`
#. :c:func:`glm_bvec2_mul`
#. :c:func:`glm_bvec2_scale`
#. :c:func:`glm_bvec2_distance2`
#. :c:func:`glm_bvec2_distance`
#. :c:func:`glm_bvec2_maxv`
#. :c:func:`glm_bvec2_minv`
#. :c:func:`glm_bvec2_clamp`
#. :c:func:`glm_bvec2_abs`

Functions documentation
~~~~~~~~~~~~~~~~~~~~~~~

.. c:function:: void glm_bvec2(int8_t * v, bvec2 dest)
    
    init bvec2 using vec3 or vec4
    
    Parameters:
      | *[in]*  **v**    vector
      | *[out]* **dest** destination

.. c:function:: void glm_bvec2_copy(bvec2 a, bvec2 dest)
    
    copy all members of [a] to [dest]

    Parameters:
      | *[in]*  **a**    source vector
      | *[out]* **dest** destination

.. c:function:: void glm_bvec2_zero(bvec2 v)

    set all members of [v] to zero

    Parameters:
      | *[out]* **v** vector

.. c:function:: void glm_bvec2_one(bvec2 v)

    set all members of [v] to one

    Parameters:
      | *[out]* **v** vector

.. c:function:: void glm_bvec2_add(bvec2 a, bvec2 b, bvec2 dest)

    add vector [a] to vector [b] and store result in [dest]

    Parameters:
      | *[in]*  **a**    first vector
      | *[in]*  **b**    second vector
      | *[out]* **dest** destination

.. c:function:: void glm_bvec2_adds(bvec2 v, int8_t s, bvec2 dest)

    add scalar s to vector [v] and store result in [dest]
    
    Parameters:
      | *[in]*  **v**    vector
      | *[in]*  **s**    scalar
      | *[out]* **dest** destination

.. c:function:: void glm_bvec2_sub(bvec2 a, bvec2 b, bvec2 dest)

    subtract vector [b] from vector [a] and store result in [dest]

    Parameters:
      | *[in]*  **a**    first vector
      | *[in]*  **b**    second vector
      | *[out]* **dest** destination

.. c:function:: void glm_bvec2_subs(bvec2 v, int8_t s, bvec2 dest)

    subtract scalar s from vector [v] and store result in [dest]
    
    Parameters:
      | *[in]*  **v**    vector
      | *[in]*  **s**    scalar
      | *[out]* **dest** destination

.. c:function:: void glm_bvec2_mul(bvec2 a, bvec2 b, bvec2 dest)

    multiply vector [a] with vector [b] and store result in [dest]

    Parameters:
      | *[in]*  **a**    first vector
      | *[in]*  **b**    second vector
      | *[out]* **dest** destination

.. c:function:: void glm_bvec2_scale(bvec2 v, int8_t s, bvec2 dest)

    multiply vector [a] with scalar s and store result in [dest]
    
    Parameters:
      | *[in]*  **v**    vector
      | *[in]*  **s**    scalar
      | *[out]* **dest** destination

.. c:function:: int8_t glm_bvec2_distance2(bvec2 a, bvec2 b)

    squared distance between two vectors

    Parameters:
      | *[in]*  **a**    first vector
      | *[in]*  **b**    second vector
    
    Returns:
        squared distance (distance * distance)

.. c:function:: float glm_bvec2_distance(bvec2 a, bvec2 b)

    distance between two vectors

    Parameters:
      | *[in]*  **a**    first vector
      | *[in]*  **b**    second vector
    
    Returns:
        distance

.. c:function:: void  glm_bvec2_fill(bvec2 v, int8_t val)

    fill a vector with specified value

    Parameters:
      | *[out]*  **v**    vector
      | *[in]*   **val**  value

.. c:function:: bool  glm_bvec2_eq(bvec2 v, int8_t val)

    check if vector is equal to value

    Parameters:
      | *[in]*  **v**    vector
      | *[in]*  **val**  value

.. c:function:: bool  glm_bvec2_eqv(bvec2 v1, bvec2 v2)

    check if vector is equal to another vector

    Parameters:
      | *[in]*  **vec**   vector 1
      | *[in]*  **vec**   vector 2


.. c:function:: void glm_bvec2_maxv(bvec2 a, bvec2 b, bvec2 dest)

    set each member of dest to greater of vector a and b

    Parameters:
      | *[in]*  **a**    first vector
      | *[in]*  **b**    second vector
      | *[out]* **dest** destination

.. c:function:: void glm_bvec2_minv(bvec2 a, bvec2 b, bvec2 dest)

    set each member of dest to lesser of vector a and b

    Parameters:
      | *[in]*  **a**    first vector
      | *[in]*  **b**    second vector
      | *[out]* **dest** destination

.. c:function:: void glm_bvec2_clamp(bvec2 v, int8_t minVal, int8_t maxVal)

    clamp each member of [v] between minVal and maxVal (inclusive)

    Parameters:
      | *[in, out]* **v**      vector
      | *[in]*      **minVal** minimum value
      | *[in]*      **maxVal** maximum value

.. c:function:: void glm_bvec2_abs(bvec2 v, bvec2 dest)

    absolute value of each vector item

    Parameters:
      | *[in]*   **v**     vector
      | *[out]*  **dest**  destination vector
