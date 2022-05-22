.. default-domain:: C

ivec2
=====

Header: cglm/ivec2.h

Table of contents (click to go):
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

Functions:

1. :c:func:`glm_ivec2`
#. :c:func:`glm_ivec2_copy`
#. :c:func:`glm_ivec2_zero`
#. :c:func:`glm_ivec2_one`
#. :c:func:`glm_ivec2_add`
#. :c:func:`glm_ivec2_adds`
#. :c:func:`glm_ivec2_sub`
#. :c:func:`glm_ivec2_subs`
#. :c:func:`glm_ivec2_mul`
#. :c:func:`glm_ivec2_scale`
#. :c:func:`glm_ivec2_distance2`
#. :c:func:`glm_ivec2_distance`
#. :c:func:`glm_ivec2_maxv`
#. :c:func:`glm_ivec2_minv`
#. :c:func:`glm_ivec2_clamp`

Functions documentation
~~~~~~~~~~~~~~~~~~~~~~~

.. c:function:: void glm_ivec2(int * v, ivec2 dest)
    
    init ivec2 using vec3 or vec4
    
    Parameters:
      | *[in]*  **v**    vector
      | *[out]* **dest** destination

.. c:function:: void glm_ivec2_copy(ivec2 a, ivec2 dest)
    
    copy all members of [a] to [dest]

    Parameters:
      | *[in]*  **a**    source vector
      | *[out]* **dest** destination

.. c:function:: void glm_ivec2_zero(ivec2 v)

    set all members of [v] to zero

    Parameters:
      | *[out]* **v** vector

.. c:function:: void glm_ivec2_one(ivec2 v)

    set all members of [v] to one

    Parameters:
      | *[out]* **v** vector

.. c:function:: void glm_ivec2_add(ivec2 a, ivec2 b, ivec2 dest)

    add vector [a] to vector [b] and store result in [dest]

    Parameters:
      | *[in]*  **a**    first vector
      | *[in]*  **b**    second vector
      | *[out]* **dest** destination

.. c:function:: void glm_ivec2_adds(ivec2 v, int s, ivec2 dest)

    add scalar s to vector [v] and store result in [dest]
    
    Parameters:
      | *[in]*  **v**    vector
      | *[in]*  **s**    scalar
      | *[out]* **dest** destination

.. c:function:: void glm_ivec2_sub(ivec2 a, ivec2 b, ivec2 dest)

    subtract vector [b] from vector [a] and store result in [dest]

    Parameters:
      | *[in]*  **a**    first vector
      | *[in]*  **b**    second vector
      | *[out]* **dest** destination

.. c:function:: void glm_ivec2_subs(ivec2 v, int s, ivec2 dest)

    subtract scalar s from vector [v] and store result in [dest]
    
    Parameters:
      | *[in]*  **v**    vector
      | *[in]*  **s**    scalar
      | *[out]* **dest** destination

.. c:function:: void glm_ivec2_mul(ivec2 a, ivec2 b, ivec2 dest)

    multiply vector [a] with vector [b] and store result in [dest]

    Parameters:
      | *[in]*  **a**    first vector
      | *[in]*  **b**    second vector
      | *[out]* **dest** destination

.. c:function:: void glm_ivec2_scale(ivec2 v, int s, ivec2 dest)

    multiply vector [a] with scalar s and store result in [dest]
    
    Parameters:
      | *[in]*  **v**    vector
      | *[in]*  **s**    scalar
      | *[out]* **dest** destination

.. c:function:: int glm_ivec2_distance2(ivec2 a, ivec2 b)

    squared distance between two vectors

    Parameters:
      | *[in]*  **a**    first vector
      | *[in]*  **b**    second vector
    
    Returns:
        squared distance (distance * distance)

.. c:function:: float glm_ivec2_distance(ivec2 a, ivec2 b)

    distance between two vectors

    Parameters:
      | *[in]*  **a**    first vector
      | *[in]*  **b**    second vector
    
    Returns:
        distance

.. c:function:: void glm_ivec2_maxv(ivec2 a, ivec2 b, ivec2 dest)

    set each member of dest to greater of vector a and b

    Parameters:
      | *[in]*  **a**    first vector
      | *[in]*  **b**    second vector
      | *[out]* **dest** destination

.. c:function:: void glm_ivec2_minv(ivec2 a, ivec2 b, ivec2 dest)

    set each member of dest to lesser of vector a and b

    Parameters:
      | *[in]*  **a**    first vector
      | *[in]*  **b**    second vector
      | *[out]* **dest** destination

.. c:function:: void glm_ivec2_clamp(ivec2 v, int minVal, int maxVal)

    clamp each member of [v] between minVal and maxVal (inclusive)

    Parameters:
      | *[in, out]* **v**      vector
      | *[in]*      **minVal** minimum value
      | *[in]*      **maxVal** maximum value
