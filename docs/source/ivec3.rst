.. default-domain:: C

ivec3
=====

Header: cglm/ivec3.h

Table of contents (click to go):
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

Macros:

1. GLM_IVEC3_ONE_INIT
#. GLM_IVEC3_ZERO_INIT
#. GLM_IVEC3_ONE
#. GLM_IVEC3_ZERO

Functions:

1. :c:func:`glm_ivec3`
#. :c:func:`glm_ivec3_copy`
#. :c:func:`glm_ivec3_zero`
#. :c:func:`glm_ivec3_one`
#. :c:func:`glm_ivec3_dot`
#. :c:func:`glm_ivec3_norm2`
#. :c:func:`glm_ivec3_norm`
#. :c:func:`glm_ivec3_add`
#. :c:func:`glm_ivec3_adds`
#. :c:func:`glm_ivec3_sub`
#. :c:func:`glm_ivec3_subs`
#. :c:func:`glm_ivec3_mul`
#. :c:func:`glm_ivec3_scale`
#. :c:func:`glm_ivec3_div`
#. :c:func:`glm_ivec3_divs`
#. :c:func:`glm_ivec3_mod`
#. :c:func:`glm_ivec3_distance2`
#. :c:func:`glm_ivec3_distance`
#. :c:func:`glm_ivec3_fill`
#. :c:func:`glm_ivec3_eq`
#. :c:func:`glm_ivec3_eqv`
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

.. c:function:: int glm_ivec3_dot(ivec3 a, ivec3 b)

    dot product of ivec3

    Parameters:
      | *[in]*  **a**  vector1
      | *[in]*  **b**  vector2

    Returns:
      dot product

.. c:function:: int glm_ivec3_norm2(ivec3 v)

    norm * norm (magnitude) of vector

    we can use this func instead of calling norm * norm, because it would call
    sqrtf function twice but with this func we can avoid func call, maybe this is
    not good name for this func

    Parameters:
      | *[in]*  **v**   vector

    Returns:
      square of norm / magnitude, cast to an integer

.. c:function:: int glm_ivec3_norm(ivec3 vec)

    | euclidean norm (magnitude), also called L2 norm
    | this will give magnitude of vector in euclidean space

    Parameters:
      | *[in]*  **vec**   vector

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

.. c:function:: void glm_ivec3_div(ivec3 a, ivec3 b, ivec3 dest)

    div vector with another component-wise division: d = a / b

    Parameters:
      | *[in]*  **a**     vector 1
      | *[in]*  **b**     vector 2
      | *[out]* **dest**  result = (a[0] / b[0], a[1] / b[1], a[2] / b[2])

.. c:function:: void glm_ivec3_divs(ivec3 v, int s, ivec3 dest)

    div vector with scalar: d = v / s

    Parameters:
      | *[in]*  **v**     vector
      | *[in]*  **s**     scalar
      | *[out]* **dest**  result = (a[0] / s, a[1] / s, a[2] / s)

.. c:function:: void glm_ivec3_mod(ivec3 a, ivec3 b, ivec3 dest)

    mod vector with another component-wise modulo: d = a % b

    Parameters:
      | *[in]*  **a**     vector
      | *[in]*  **b**     scalar
      | *[out]* **dest**  result = (a[0] % b[0], a[1] % b[1], a[2] % b[2])

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

.. c:function:: void  glm_ivec3_fill(ivec3 v, int val)

    fill a vector with specified value

    Parameters:
      | *[out]*  **v**    vector
      | *[in]*   **val**  value

.. c:function:: bool  glm_ivec3_eq(ivec3 v, int val)

    check if vector is equal to value

    Parameters:
      | *[in]*  **v**    vector
      | *[in]*  **val**  value

.. c:function:: bool  glm_ivec3_eqv(ivec3 v1, ivec3 v2)

    check if vector is equal to another vector

    Parameters:
      | *[in]*  **vec**   vector 1
      | *[in]*  **vec**   vector 2

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
