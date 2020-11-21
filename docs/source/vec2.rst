.. default-domain:: C

vec2
====

Header: cglm/vec2.h

Table of contents (click to go):
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

Macros:

1. GLM_vec2_ONE_INIT
#. GLM_vec2_ZERO_INIT
#. GLM_vec2_ONE
#. GLM_vec2_ZERO

Functions:

1. :c:func:`glm_vec2`
#. :c:func:`glm_vec2_copy`
#. :c:func:`glm_vec2_zero`
#. :c:func:`glm_vec2_one`
#. :c:func:`glm_vec2_dot`
#. :c:func:`glm_vec2_cross`
#. :c:func:`glm_vec2_norm2`
#. :c:func:`glm_vec2_norm`
#. :c:func:`glm_vec2_add`
#. :c:func:`glm_vec2_adds`
#. :c:func:`glm_vec2_sub`
#. :c:func:`glm_vec2_subs`
#. :c:func:`glm_vec2_mul`
#. :c:func:`glm_vec2_scale`
#. :c:func:`glm_vec2_scale_as`
#. :c:func:`glm_vec2_div`
#. :c:func:`glm_vec2_divs`
#. :c:func:`glm_vec2_addadd`
#. :c:func:`glm_vec2_subadd`
#. :c:func:`glm_vec2_muladd`
#. :c:func:`glm_vec2_muladds`
#. :c:func:`glm_vec2_maxadd`
#. :c:func:`glm_vec2_minadd`
#. :c:func:`glm_vec2_negate`
#. :c:func:`glm_vec2_negate_to`
#. :c:func:`glm_vec2_normalize`
#. :c:func:`glm_vec2_normalize_to`
#. :c:func:`glm_vec2_rotate`
#. :c:func:`glm_vec2_distance2`
#. :c:func:`glm_vec2_distance`
#. :c:func:`glm_vec2_maxv`
#. :c:func:`glm_vec2_minv`
#. :c:func:`glm_vec2_clamp`
#. :c:func:`glm_vec2_lerp`

Functions documentation
~~~~~~~~~~~~~~~~~~~~~~~

.. c:function:: void glm_vec2(float * v, vec2 dest)

    init vec2 using vec3 or vec4

    Parameters:
      | *[in]*  **v**     vector
      | *[out]* **dest**  destination

.. c:function:: void glm_vec2_copy(vec2 a, vec2 dest)

    copy all members of [a] to [dest]

    Parameters:
      | *[in]*  **a**     source
      | *[out]* **dest**  destination

.. c:function:: void glm_vec2_zero(vec2 v)

    makes all members 0.0f (zero)

    Parameters:
      | *[in, out]*  **v**     vector

.. c:function:: void  glm_vec2_one(vec2 v)

    makes all members 1.0f (one)

    Parameters:
      | *[in, out]*  **v**     vector

.. c:function:: float glm_vec2_dot(vec2 a, vec2 b)

    dot product of vec2

    Parameters:
      | *[in]*  **a**  vector1
      | *[in]*  **b**  vector2

    Returns:
      dot product

.. c:function:: void glm_vec2_cross(vec2 a, vec2 b, vec2 d)

    cross product of two vector (RH)

    | ref: http://allenchou.net/2013/07/cross-product-of-2d-vectors/

    Parameters:
      | *[in]*  **a**     vector 1
      | *[in]*  **b**     vector 2
      | *[out]* **dest**  destination

    Returns:
      Z component of cross product

.. c:function:: float glm_vec2_norm2(vec2 v)

    norm * norm (magnitude) of vector

    we can use this func instead of calling norm * norm, because it would call
    sqrtf fuction twice but with this func we can avoid func call, maybe this is
    not good name for this func

    Parameters:
      | *[in]*  **v**   vector

    Returns:
      square of norm / magnitude

.. c:function:: float glm_vec2_norm(vec2 vec)

    | euclidean norm (magnitude), also called L2 norm
    | this will give magnitude of vector in euclidean space

    Parameters:
      | *[in]*  **vec**   vector

.. c:function:: void glm_vec2_add(vec2 a, vec2 b, vec2 dest)

    add a vector to b vector store result in dest

    Parameters:
      | *[in]*  **a**     vector1
      | *[in]*  **b**     vector2
      | *[out]* **dest**  destination vector

.. c:function:: void glm_vec2_adds(vec2 a, float s, vec2 dest)

    add scalar to v vector store result in dest (d = v + vec(s))

    Parameters:
      | *[in]*  **v**     vector
      | *[in]*  **s**     scalar
      | *[out]* **dest**  destination vector

.. c:function:: void glm_vec2_sub(vec2 v1, vec2 v2, vec2 dest)

    subtract b vector from a vector store result in dest (d = v1 - v2)

    Parameters:
      | *[in]*  **a**     vector1
      | *[in]*  **b**     vector2
      | *[out]* **dest**  destination vector

.. c:function:: void glm_vec2_subs(vec2 v, float s, vec2 dest)

    subtract scalar from v vector store result in dest (d = v - vec(s))

    Parameters:
      | *[in]*  **v**     vector
      | *[in]*  **s**     scalar
      | *[out]* **dest**  destination vector

.. c:function:: void glm_vec2_mul(vec2 a, vec2 b, vec2 d)

    multiply two vector (component-wise multiplication)

    Parameters:
      | *[in]*  **a**     vector
      | *[in]*  **b**     scalar
      | *[out]* **d**     result = (a[0] * b[0], a[1] * b[1], a[2] * b[2])

.. c:function:: void glm_vec2_scale(vec2 v, float s, vec2 dest)

     multiply/scale vec2 vector with scalar: result = v * s


    Parameters:
      | *[in]*  **v**     vector
      | *[in]*  **s**     scalar
      | *[out]* **dest**  destination vector

.. c:function:: void glm_vec2_scale_as(vec2 v, float s, vec2 dest)

    make vec2 vector scale as specified: result = unit(v) * s

    Parameters:
      | *[in]*  **v**     vector
      | *[in]*  **s**     scalar
      | *[out]* **dest**  destination vector

.. c:function:: void glm_vec2_div(vec2 a, vec2 b, vec2 dest)

    div vector with another component-wise division: d = a / b

    Parameters:
      | *[in]*  **a**     vector 1
      | *[in]*  **b**     vector 2
      | *[out]* **dest**  result = (a[0] / b[0], a[1] / b[1], a[2] / b[2])

.. c:function:: void glm_vec2_divs(vec2 v, float s, vec2 dest)

    div vector with scalar: d = v / s

    Parameters:
      | *[in]*  **v**     vector
      | *[in]*  **s**     scalar
      | *[out]* **dest**  result = (a[0] / s, a[1] / s, a[2] / s])

.. c:function:: void glm_vec2_addadd(vec2 a, vec2 b, vec2 dest)

    | add two vectors and add result to sum
    | it applies += operator so dest must be initialized

    Parameters:
      | *[in]*  **a**     vector 1
      | *[in]*  **b**     vector 2
      | *[out]* **dest**  dest += (a + b)

.. c:function:: void glm_vec2_subadd(vec2 a, vec2 b, vec2 dest)

    | sub two vectors and add result to sum
    | it applies += operator so dest must be initialized

    Parameters:
      | *[in]*  **a**     vector 1
      | *[in]*  **b**     vector 2
      | *[out]* **dest**  dest += (a - b)

.. c:function:: void glm_vec2_muladd(vec2 a, vec2 b, vec2 dest)

    | mul two vectors and add result to sum
    | it applies += operator so dest must be initialized

    Parameters:
      | *[in]*  **a**     vector 1
      | *[in]*  **b**     vector 2
      | *[out]* **dest**  dest += (a * b)

.. c:function:: void glm_vec2_muladds(vec2 a, float s, vec2 dest)

    | mul vector with scalar and add result to sum
    | it applies += operator so dest must be initialized

    Parameters:
      | *[in]*  **a**     vector
      | *[in]*  **s**     scalar
      | *[out]* **dest**  dest += (a * b)

.. c:function:: void glm_vec2_maxadd(vec2 a, vec2 b, vec2 dest)

    | add max of two vector to result/dest
    | it applies += operator so dest must be initialized

    Parameters:
      | *[in]*  **a**     vector 1
      | *[in]*  **b**     vector 2
      | *[out]* **dest**  dest += (a * b)

.. c:function:: void glm_vec2_minadd(vec2 a, vec2 b, vec2 dest)

    | add min of two vector to result/dest
    | it applies += operator so dest must be initialized

    Parameters:
      | *[in]*  **a**     vector 1
      | *[in]*  **b**     vector 2
      | *[out]* **dest**  dest += (a * b)

.. c:function:: void glm_vec2_negate(vec2 v)

    negate vector components

    Parameters:
      | *[in, out]*  **v**    vector

.. c:function:: void glm_vec2_negate_to(vec2 v, vec2 dest)

    negate vector components and store result in dest

    Parameters:
      | *[in]*  **v**       vector
      | *[out]* **dest**    negated vector

.. c:function:: void glm_vec2_normalize(vec2 v)

    normalize vec2 and store result in same vec

    Parameters:
      | *[in, out]*  **v**    vector

.. c:function:: void glm_vec2_normalize_to(vec2 vec, vec2 dest)

     normalize vec2 to dest

    Parameters:
      | *[in]*   **vec**   source
      | *[out]*  **dest**  destination

.. c:function:: void glm_vec2_rotate(vec2 v, float angle, vec2 dest)

     rotate vec2 around axis by angle using Rodrigues' rotation formula

    Parameters:
      | *[in]*  **v**      vector
      | *[in]*  **axis**   axis vector
      | *[out]* **dest**   destination

.. c:function:: float glm_vec2_distance2(vec2 v1, vec2 v2)

    squared distance between two vectors

    Parameters:
      | *[in]*  **mat**   vector1
      | *[in]*  **row1**  vector2

    Returns:
      | squared distance (distance * distance)

.. c:function:: float glm_vec2_distance(vec2 v1, vec2 v2)

    distance between two vectors

    Parameters:
      | *[in]*  **mat**   vector1
      | *[in]*  **row1**  vector2

    Returns:
      | distance

.. c:function:: void glm_vec2_maxv(vec2 v1, vec2 v2, vec2 dest)

    max values of vectors

    Parameters:
      | *[in]*  **v1**    vector1
      | *[in]*  **v2**    vector2
      | *[out]* **dest**  destination

.. c:function:: void glm_vec2_minv(vec2 v1, vec2 v2, vec2 dest)

    min values of vectors

    Parameters:
      | *[in]*  **v1**    vector1
      | *[in]*  **v2**    vector2
      | *[out]* **dest**  destination

.. c:function:: void glm_vec2_clamp(vec2 v, float minVal, float maxVal)

    constrain a value to lie between two further values

    Parameters:
      | *[in, out]*  **v**       vector
      | *[in]*       **minVal**  minimum value
      | *[in]*       **maxVal**  maximum value

.. c:function:: void glm_vec2_lerp(vec2 from, vec2 to, float t, vec2 dest)

    linear interpolation between two vector

    | formula:  from + s * (to - from)

    Parameters:
      | *[in]*  **from**   from value
      | *[in]*  **to**     to value
      | *[in]*  **t**      interpolant (amount) clamped between 0 and 1
      | *[out]* **dest**   destination
