.. default-domain:: C

ivec3
=====

Header: cglm/ivec3.h

Table of contents (click to go):
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

Functions:

1. :c:func:`glm_ivec3`
#. :c:func:`glm_ivec3_copy`
#. :c:func:`glm_ivec3_zero`
#. :c:func:`glm_ivec3_one`
#. :c:func:`glm_ivec3_add`
#. :c:func:`glm_ivec3_adds`
#. :c:func:`glm_ivec3_sub`
#. :c:func:`glm_ivec3_subs`
#. :c:func:`glm_ivec3_mul`
#. :c:func:`glm_ivec3_scale`
#. :c:func:`glm_ivec3_distance2`
#. :c:func:`glm_ivec3_distance`
#. :c:func:`glm_ivec3_maxv`
#. :c:func:`glm_ivec3_minv`
#. :c:func:`glm_ivec3_clamp`
#. :c:func:`glm_ivec2_abs`

Functions documentation
~~~~~~~~~~~~~~~~~~~~~~~

.. c:function:: void glm_ivec3(ivec4 v4, ivec3 dest)
    
    init ivec3 using ivec4
    
    Parameters:
      | *[in]*  **v**    vector
      | *[out]* **dest** destination

.. c:function:: void glm_ivec3_copy(ivec3 a, ivec3 dest)
    
    copy all members of [a] to [dest]

    Parameters:
      | *[in]*  **a**    source vector
      | *[out]* **dest** destination

.. c:function:: void glm_ivec3_zero(ivec3 v)

    set all members of [v] to zero

    Parameters:
      | *[out]* **v** vector

.. c:function:: void glm_ivec3_one(ivec3 v)

    set all members of [v] to one

    Parameters:
      | *[out]* **v** vector

.. c:function:: void glm_ivec3_add(ivec3 a, ivec3 b, ivec3 dest)

    add vector [a] to vector [b] and store result in [dest]

    Parameters:
      | *[in]*  **a**    first vector
      | *[in]*  **b**    second vector
      | *[out]* **dest** destination

.. c:function:: void glm_ivec3_adds(ivec3 v, int s, ivec3 dest)

    add scalar s to vector [v] and store result in [dest]
    
    Parameters:
      | *[in]*  **v**    vector
      | *[in]*  **s**    scalar
      | *[out]* **dest** destination

.. c:function:: void glm_ivec3_sub(ivec3 a, ivec3 b, ivec3 dest)

    subtract vector [b] from vector [a] and store result in [dest]

    Parameters:
      | *[in]*  **a**    first vector
      | *[in]*  **b**    second vector
      | *[out]* **dest** destination

.. c:function:: void glm_ivec3_subs(ivec3 v, int s, ivec3 dest)

    subtract scalar s from vector [v] and store result in [dest]
    
    Parameters:
      | *[in]*  **v**    vector
      | *[in]*  **s**    scalar
      | *[out]* **dest** destination

.. c:function:: void glm_ivec3_mul(ivec3 a, ivec3 b, ivec3 dest)

    multiply vector [a] with vector [b] and store result in [dest]

    Parameters:
      | *[in]*  **a**    first vector
      | *[in]*  **b**    second vector
      | *[out]* **dest** destination

.. c:function:: void glm_ivec3_scale(ivec3 v, int s, ivec3 dest)

    multiply vector [a] with scalar s and store result in [dest]
    
    Parameters:
      | *[in]*  **v**    vector
      | *[in]*  **s**    scalar
      | *[out]* **dest** destination

.. c:function:: int glm_ivec3_distance2(ivec3 a, ivec3 b)

    squared distance between two vectors

    Parameters:
      | *[in]*  **a**    first vector
      | *[in]*  **b**    second vector
    
    Returns:
        squared distance (distance * distance)

.. c:function:: float glm_ivec3_distance(ivec3 a, ivec3 b)

    distance between two vectors

    Parameters:
      | *[in]*  **a**    first vector
      | *[in]*  **b**    second vector
    
    Returns:
        distance

.. c:function:: void glm_ivec3_maxv(ivec3 a, ivec3 b, ivec3 dest)

    set each member of dest to greater of vector a and b

    Parameters:
      | *[in]*  **a**    first vector
      | *[in]*  **b**    second vector
      | *[out]* **dest** destination

.. c:function:: void glm_ivec3_minv(ivec3 a, ivec3 b, ivec3 dest)

    set each member of dest to lesser of vector a and b

    Parameters:
      | *[in]*  **a**    first vector
      | *[in]*  **b**    second vector
      | *[out]* **dest** destination

.. c:function:: void glm_ivec3_clamp(ivec3 v, int minVal, int maxVal)

    clamp each member of [v] between minVal and maxVal (inclusive)

    Parameters:
      | *[in, out]* **v**      vector
      | *[in]*      **minVal** minimum value
      | *[in]*      **maxVal** maximum value

.. c:function:: void glm_ivec3_abs(ivec3 v, ivec3 dest)

    absolute value of each vector item

    Parameters:
      | *[in]*   **v**     vector
      | *[out]*  **dest**  destination vector
