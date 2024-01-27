.. default-domain:: C

ivec2
=====

Header: cglm/ivec2.h

Table of contents (click to go):
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

Macros:

1. GLM_IVEC2_ONE_INIT
#. GLM_IVEC2_ZERO_INIT
#. GLM_IVEC2_ONE
#. GLM_IVEC2_ZERO

Functions:

1. :c:func:`glm_ivec2`
#. :c:func:`glm_ivec2_copy`
#. :c:func:`glm_ivec2_zero`
#. :c:func:`glm_ivec2_one`
#. :c:func:`glm_ivec2_dot`
#. :c:func:`glm_ivec2_cross`
#. :c:func:`glm_ivec2_add`
#. :c:func:`glm_ivec2_adds`
#. :c:func:`glm_ivec2_sub`
#. :c:func:`glm_ivec2_subs`
#. :c:func:`glm_ivec2_mul`
#. :c:func:`glm_ivec2_scale`
#. :c:func:`glm_ivec2_div`
#. :c:func:`glm_ivec2_divs`
#. :c:func:`glm_ivec2_mod`
#. :c:func:`glm_ivec2_distance2`
#. :c:func:`glm_ivec2_distance`
#. :c:func:`glm_ivec2_maxv`
#. :c:func:`glm_ivec2_minv`
#. :c:func:`glm_ivec2_clamp`
#. :c:func:`glm_ivec2_abs`

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

.. c:function:: int glm_ivec2_dot(ivec2 a, ivec2 b)

    dot product of ivec2

    Parameters:
      | *[in]*  **a**  vector1
      | *[in]*  **b**  vector2

    Returns:
      dot product

.. c:function:: int glm_ivec2_cross(ivec2 a, ivec2 b)

    cross product of two vector (RH)

    | ref: http://allenchou.net/2013/07/cross-product-of-2d-vectors/

    Parameters:
      | *[in]*  **a**     vector 1
      | *[in]*  **b**     vector 2

    Returns:
      Z component of cross product

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

.. c:function:: void glm_ivec2_div(ivec2 a, ivec2 b, ivec2 dest)

    div vector with another component-wise division: d = a / b

    Parameters:
      | *[in]*  **a**     vector 1
      | *[in]*  **b**     vector 2
      | *[out]* **dest**  result = (a[0] / b[0], a[1] / b[1], a[2] / b[2])

.. c:function:: void glm_ivec2_divs(ivec2 v, int s, ivec2 dest)

    div vector with scalar: d = v / s

    Parameters:
      | *[in]*  **v**     vector
      | *[in]*  **s**     scalar
      | *[out]* **dest**  result = (a[0] / s, a[1] / s, a[2] / s)

.. c:function:: void glm_ivec2_mod(ivec2 a, ivec2 b, ivec2 dest)

    mod vector with another component-wise modulo: d = a % b

    Parameters:
      | *[in]*  **a**     vector
      | *[in]*  **b**     scalar
      | *[out]* **dest**  result = (a[0] % b[0], a[1] % b[1])

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

.. c:function:: void  glm_ivec2_fill(ivec2 v, int val)

    fill a vector with specified value

    Parameters:
      | *[out]*  **v**    vector
      | *[in]*   **val**  value

.. c:function:: bool  glm_ivec2_eq(ivec2 v, int val)

    check if vector is equal to value

    Parameters:
      | *[in]*  **v**    vector
      | *[in]*  **val**  value

.. c:function:: bool  glm_ivec2_eqv(ivec2 v1, ivec2 v2)

    check if vector is equal to another vector

    Parameters:
      | *[in]*  **vec**   vector 1
      | *[in]*  **vec**   vector 2


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

.. c:function:: void glm_ivec2_abs(ivec2 v, ivec2 dest)

    absolute value of each vector item

    Parameters:
      | *[in]*   **v**     vector
      | *[out]*  **dest**  destination vector
