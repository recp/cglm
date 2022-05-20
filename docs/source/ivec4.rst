.. default-domain:: C

ivec4
=====

Header: cglm/ivec4.h

Table of contents (click to go):
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

Functions:

1. :c:func:`glm_ivec4`
#. :c:func:`glm_ivec4_copy`
#. :c:func:`glm_ivec4_zero`
#. :c:func:`glm_ivec4_one`
#. :c:func:`glm_ivec4_add`
#. :c:func:`glm_ivec4_adds`
#. :c:func:`glm_ivec4_sub`
#. :c:func:`glm_ivec4_subs`
#. :c:func:`glm_ivec4_mul`
#. :c:func:`glm_ivec4_scale`
#. :c:func:`glm_ivec4_distance2`
#. :c:func:`glm_ivec4_distance`
#. :c:func:`glm_ivec4_maxv`
#. :c:func:`glm_ivec4_minv`
#. :c:func:`glm_ivec4_clamp`

Functions documentation
~~~~~~~~~~~~~~~~~~~~~~~

.. c:function:: void glm_ivec4(ivec3 v3, int last, ivec4 dest)
    
    init ivec4 using ivec3
    
    Parameters:
      | *[in]*  **v**    vector
      | *[out]* **dest** destination

.. c:function:: void glm_ivec4_copy(ivec4 a, ivec4 dest)
    
    copy all members of [a] to [dest]

    Parameters:
      | *[in]*  **a**    source vector
      | *[out]* **dest** destination

.. c:function:: void glm_ivec4_zero(ivec4 v)

    set all members of [v] to zero

    Parameters:
      | *[out]* **v** vector

.. c:function:: void glm_ivec4_one(ivec4 v)

    set all members of [v] to one

    Parameters:
      | *[out]* **v** vector

.. c:function:: void glm_ivec4_add(ivec4 a, ivec4 b, ivec4 dest)

    add vector [a] to vector [b] and store result in [dest]

    Parameters:
      | *[in]*  **a**    first vector
      | *[in]*  **b**    second vector
      | *[out]* **dest** destination

.. c:function:: void glm_ivec4_adds(ivec4 v, int s, ivec4 dest)

    add scalar s to vector [v] and store result in [dest]
    
    Parameters:
      | *[in]*  **v**    vector
      | *[in]*  **s**    scalar
      | *[out]* **dest** destination

.. c:function:: void glm_ivec4_sub(ivec4 a, ivec4 b, ivec4 dest)

    subtract vector [b] from vector [a] and store result in [dest]

    Parameters:
      | *[in]*  **a**    first vector
      | *[in]*  **b**    second vector
      | *[out]* **dest** destination

.. c:function:: void glm_ivec4_subs(ivec4 v, int s, ivec4 dest)

    subtract scalar s from vector [v] and store result in [dest]
    
    Parameters:
      | *[in]*  **v**    vector
      | *[in]*  **s**    scalar
      | *[out]* **dest** destination

.. c:function:: void glm_ivec4_mul(ivec4 a, ivec4 b, ivec4 dest)

    multiply vector [a] with vector [b] and store result in [dest]

    Parameters:
      | *[in]*  **a**    first vector
      | *[in]*  **b**    second vector
      | *[out]* **dest** destination

.. c:function:: void glm_ivec4_scale(ivec4 v, int s, ivec4 dest)

    multiply vector [a] with scalar s and store result in [dest]
    
    Parameters:
      | *[in]*  **v**    vector
      | *[in]*  **s**    scalar
      | *[out]* **dest** destination

.. c:function:: int glm_ivec4_distance2(ivec4 a, ivec4 b)

    squared distance between two vectors

    Parameters:
      | *[in]*  **a**    first vector
      | *[in]*  **b**    second vector
    
    Returns:
        squared distance (distance * distance)

.. c:function:: float glm_ivec4_distance(ivec4 a, ivec4 b)

    distance between two vectors

    Parameters:
      | *[in]*  **a**    first vector
      | *[in]*  **b**    second vector
    
    Returns:
        distance

.. c:function:: void glm_ivec4_maxv(ivec4 a, ivec4 b, ivec4 dest)

    set each member of dest to greater of vector a and b

    Parameters:
      | *[in]*  **a**    first vector
      | *[in]*  **b**    second vector
      | *[out]* **dest** destination

.. c:function:: void glm_ivec4_minv(ivec4 a, ivec4 b, ivec4 dest)

    set each member of dest to lesser of vector a and b

    Parameters:
      | *[in]*  **a**    first vector
      | *[in]*  **b**    second vector
      | *[out]* **dest** destination

.. c:function:: void glm_ivec4_clamp(ivec4 v, int minVal, int maxVal)

    clamp each member of [v] between minVal and maxVal (inclusive)

    Parameters:
      | *[in, out]* **v**      vector
      | *[in]*      **minVal** minimum value
      | *[in]*      **maxVal** maximum value
