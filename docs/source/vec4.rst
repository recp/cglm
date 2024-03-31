.. default-domain:: C

vec4
====

Header: cglm/vec4.h

Table of contents (click to go):
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

Macros:

1. glm_vec4_dup3(v, dest)
#. glm_vec4_dup(v, dest)
#. GLM_VEC4_ONE_INIT
#. GLM_VEC4_BLACK_INIT
#. GLM_VEC4_ZERO_INIT
#. GLM_VEC4_ONE
#. GLM_VEC4_BLACK
#. GLM_VEC4_ZERO

Functions:

1. :c:func:`glm_vec4`
#. :c:func:`glm_vec4_copy3`
#. :c:func:`glm_vec4_copy`
#. :c:func:`glm_vec4_ucopy`
#. :c:func:`glm_vec4_zero`
#. :c:func:`glm_vec4_one`
#. :c:func:`glm_vec4_dot`
#. :c:func:`glm_vec4_norm2`
#. :c:func:`glm_vec4_norm`
#. :c:func:`glm_vec4_add`
#. :c:func:`glm_vec4_adds`
#. :c:func:`glm_vec4_sub`
#. :c:func:`glm_vec4_subs`
#. :c:func:`glm_vec4_mul`
#. :c:func:`glm_vec4_scale`
#. :c:func:`glm_vec4_scale_as`
#. :c:func:`glm_vec4_div`
#. :c:func:`glm_vec4_divs`
#. :c:func:`glm_vec4_addadd`
#. :c:func:`glm_vec4_subadd`
#. :c:func:`glm_vec4_muladd`
#. :c:func:`glm_vec4_muladds`
#. :c:func:`glm_vec4_maxadd`
#. :c:func:`glm_vec4_minadd`
#. :c:func:`glm_vec4_flipsign`
#. :c:func:`glm_vec4_flipsign_to`
#. :c:func:`glm_vec4_inv`
#. :c:func:`glm_vec4_inv_to`
#. :c:func:`glm_vec4_negate`
#. :c:func:`glm_vec4_negate_to`
#. :c:func:`glm_vec4_normalize`
#. :c:func:`glm_vec4_normalize_to`
#. :c:func:`glm_vec4_distance`
#. :c:func:`glm_vec4_maxv`
#. :c:func:`glm_vec4_minv`
#. :c:func:`glm_vec4_clamp`
#. :c:func:`glm_vec4_lerp`
#. :c:func:`glm_vec4_cubic`
#. :c:func:`glm_vec4_make`
#. :c:func:`glm_vec4_reflect`
#. :c:func:`glm_vec4_refract`

Functions documentation
~~~~~~~~~~~~~~~~~~~~~~~

.. c:function:: void  glm_vec4(vec3 v3, float last, vec4 dest)

    init vec4 using vec3, since you are initializing vec4 with vec3
    you need to set last item. cglm could set it zero but making it parameter
    gives more control

    Parameters:
      | *[in]*  **v3**    vector4
      | *[in]*  **last**  last item of vec4
      | *[out]* **dest**  destination

.. c:function:: void glm_vec4_copy3(vec4 a, vec3 dest)

    copy first 3 members of [a] to [dest]

    Parameters:
      | *[in]*  **a**     source
      | *[out]* **dest**  destination

.. c:function:: void  glm_vec4_copy(vec4 v, vec4 dest)

    copy all members of [a] to [dest]

    Parameters:
      | *[in]*  **v**     source
      | *[in]*  **dest**  destination

.. c:function:: void  glm_vec4_ucopy(vec4 v, vec4 dest)

    copy all members of [a] to [dest]

    | alignment is not required

    Parameters:
      | *[in]*  **v**     source
      | *[in]*  **dest**  destination

.. c:function:: void  glm_vec4_zero(vec4 v)

    makes all members zero

    Parameters:
      | *[in, out]*  **v**     vector

.. c:function:: void  glm_vec4_one(vec4 v)

    makes all members one

    Parameters:
      | *[in, out]*  **v**     vector

.. c:function:: float  glm_vec4_dot(vec4 a, vec4 b)

    dot product of vec4

    Parameters:
      | *[in]*  **a**  vector1
      | *[in]*  **b**  vector2

    Returns:
      dot product

.. c:function:: float  glm_vec4_norm2(vec4 v)

    norm * norm (magnitude) of vector

    we can use this func instead of calling norm * norm, because it would call
    sqrtf function twice but with this func we can avoid func call, maybe this is
    not good name for this func

    Parameters:
      | *[in]*  **v**   vector

    Returns:
      square of norm / magnitude

.. c:function:: float  glm_vec4_norm(vec4 vec)

    | euclidean norm (magnitude), also called L2 norm
    | this will give magnitude of vector in euclidean space

    Parameters:
      | *[in]*  **vec**   vector

.. c:function:: void  glm_vec4_add(vec4 a, vec4 b, vec4 dest)

    add a vector to b vector store result in dest

    Parameters:
      | *[in]*  **a**     vector1
      | *[in]*  **b**     vector2
      | *[out]* **dest**  destination vector

.. c:function:: void  glm_vec4_adds(vec4 v, float s, vec4 dest)

    add scalar to v vector store result in dest (d = v + vec(s))

    Parameters:
      | *[in]*  **v**     vector
      | *[in]*  **s**     scalar
      | *[out]* **dest**  destination vector

.. c:function:: void  glm_vec4_sub(vec4 a, vec4 b, vec4 dest)

    subtract b vector from a vector store result in dest (d = v1 - v2)

    Parameters:
      | *[in]*  **a**     vector1
      | *[in]*  **b**     vector2
      | *[out]* **dest**  destination vector

.. c:function:: void  glm_vec4_subs(vec4 v, float s, vec4 dest)

    subtract scalar from v vector store result in dest (d = v - vec(s))

    Parameters:
      | *[in]*  **v**     vector
      | *[in]*  **s**     scalar
      | *[out]* **dest**  destination vector

.. c:function:: void  glm_vec4_mul(vec4 a, vec4 b, vec4 d)

    multiply two vector (component-wise multiplication)

    Parameters:
      | *[in]*  **a**     vector1
      | *[in]*  **b**     vector2
      | *[out]* **dest**  result = (a[0] * b[0], a[1] * b[1], a[2] * b[2], a[3] * b[3])

.. c:function:: void glm_vec4_scale(vec4 v, float s, vec4 dest)

     multiply/scale vec4 vector with scalar: result = v * s

    Parameters:
      | *[in]*  **v**     vector
      | *[in]*  **s**     scalar
      | *[out]* **dest**  destination vector

.. c:function:: void  glm_vec4_scale_as(vec4 v, float s, vec4 dest)

    make vec4 vector scale as specified: result = unit(v) * s

    Parameters:
      | *[in]*  **v**     vector
      | *[in]*  **s**     scalar
      | *[out]* **dest**  destination vector

.. c:function:: void  glm_vec4_div(vec4 a, vec4 b, vec4 dest)

    div vector with another component-wise division: d = v1 / v2

    Parameters:
      | *[in]*  **a**     vector1
      | *[in]*  **b**     vector2
      | *[out]* **dest**  result = (a[0] / b[0], a[1] / b[1], a[2] / b[2], a[3] / b[3])

.. c:function:: void  glm_vec4_divs(vec4 v, float s, vec4 dest)

    div vector with scalar: d = v / s

    Parameters:
      | *[in]*  **v**     vector
      | *[in]*  **s**     scalar
      | *[out]* **dest**  result = (a[0] / s, a[1] / s, a[2] / s, a[3] / s)

.. c:function:: void  glm_vec4_addadd(vec4 a, vec4 b, vec4 dest)

    | add two vectors and add result to sum
    | it applies += operator so dest must be initialized

    Parameters:
      | *[in]*  **a**     vector 1
      | *[in]*  **b**     vector 2
      | *[out]* **dest**  dest += (a + b)

.. c:function:: void  glm_vec4_subadd(vec4 a, vec4 b, vec4 dest)

    | sub two vectors and add result to sum
    | it applies += operator so dest must be initialized

    Parameters:
      | *[in]*  **a**     vector 1
      | *[in]*  **b**     vector 2
      | *[out]* **dest**  dest += (a - b)

.. c:function:: void  glm_vec4_muladd(vec4 a, vec4 b, vec4 dest)

    | mul two vectors and add result to sum
    | it applies += operator so dest must be initialized

    Parameters:
      | *[in]*  **a**     vector 1
      | *[in]*  **b**     vector 2
      | *[out]* **dest**  dest += (a * b)

.. c:function:: void  glm_vec4_muladds(vec4 a, float s, vec4 dest)

    | mul vector with scalar and add result to sum
    | it applies += operator so dest must be initialized

    Parameters:
      | *[in]*  **a**     vector
      | *[in]*  **s**     scalar
      | *[out]* **dest**  dest += (a * b)

.. c:function:: void  glm_vec4_maxadd(vec4 a, vec4 b, vec4 dest)

    | add max of two vector to result/dest
    | it applies += operator so dest must be initialized

    Parameters:
      | *[in]*  **a**     vector 1
      | *[in]*  **b**     vector 2
      | *[out]* **dest**  dest += (a * b)

.. c:function:: void  glm_vec4_minadd(vec4 a, vec4 b, vec4 dest)

    | add min of two vector to result/dest
    | it applies += operator so dest must be initialized

    Parameters:
      | *[in]*  **a**     vector 1
      | *[in]*  **b**     vector 2
      | *[out]* **dest**  dest += (a * b)

.. c:function:: void  glm_vec4_flipsign(vec4 v)

    **DEPRECATED!**

    use :c:func:`glm_vec4_negate`

    Parameters:
    | *[in, out]*  **v**    vector

.. c:function:: void  glm_vec4_flipsign_to(vec4 v, vec4 dest)

    **DEPRECATED!**

    use :c:func:`glm_vec4_negate_to`

    Parameters:
      | *[in]*  **v**       vector
      | *[out]* **dest**    negated vector

.. c:function:: void  glm_vec4_inv(vec4 v)

    **DEPRECATED!**

    use :c:func:`glm_vec4_negate`

    Parameters:
      | *[in, out]*  **v**    vector

.. c:function:: void  glm_vec4_inv_to(vec4 v, vec4 dest)

    **DEPRECATED!**

    use :c:func:`glm_vec4_negate_to`

    Parameters:
      | *[in]*  **v**     source
      | *[out]* **dest**  destination

.. c:function:: void  glm_vec4_negate(vec4 v)

    negate vector components

    Parameters:
    | *[in, out]*  **v**    vector

.. c:function:: void  glm_vec4_negate_to(vec4 v, vec4 dest)

    negate vector components and store result in dest

    Parameters:
      | *[in]*  **v**       vector
      | *[out]* **dest**    negated vector

.. c:function:: void  glm_vec4_normalize(vec4 v)

    normalize vec4 and store result in same vec

    Parameters:
      | *[in, out]*  **v**    vector

.. c:function:: void  glm_vec4_normalize_to(vec4 vec, vec4 dest)

    normalize vec4 to dest

    Parameters:
      | *[in]*   **vec**   source
      | *[out]*  **dest**  destination

.. c:function:: float  glm_vec4_distance(vec4 v1, vec4 v2)

    distance between two vectors

    Parameters:
      | *[in]*  **mat**   vector1
      | *[in]*  **row1**  vector2

    Returns:
      | distance

.. c:function:: void  glm_vec4_maxv(vec4 v1, vec4 v2, vec4 dest)

    max values of vectors

    Parameters:
      | *[in]*  **v1**    vector1
      | *[in]*  **v2**    vector2
      | *[out]* **dest**  destination

.. c:function:: void  glm_vec4_minv(vec4 v1, vec4 v2, vec4 dest)

    min values of vectors

    Parameters:
      | *[in]*  **v1**    vector1
      | *[in]*  **v2**    vector2
      | *[out]* **dest**  destination

.. c:function:: void  glm_vec4_clamp(vec4 v, float minVal, float maxVal)

    constrain a value to lie between two further values

    Parameters:
      | *[in, out]*  **v**       vector
      | *[in]*       **minVal**  minimum value
      | *[in]*       **maxVal**  maximum value

.. c:function:: void  glm_vec4_lerp(vec4 from, vec4 to, float t, vec4 dest)

    linear interpolation between two vector

    | formula:  from + s * (to - from)

    Parameters:
      | *[in]*  **from**   from value
      | *[in]*  **to**     to value
      | *[in]*  **t**      interpolant (amount) clamped between 0 and 1
      | *[out]* **dest**   destination

.. c:function:: void  glm_vec4_cubic(float s, vec4 dest)

    helper to fill vec4 as [S^3, S^2, S, 1]

    Parameters:
      | *[in]*  **s**      parameter
      | *[out]* **dest**   destination

.. c:function:: void glm_vec4_make(const float * __restrict src, vec4 dest)

    Create four dimensional vector from pointer

    .. note:: **@src** must contain at least 4 elements.

    Parameters:
      | *[in]*  **src**  pointer to an array of floats
      | *[out]* **dest** destination vector

.. c:function:: bool glm_vec4_reflect(vec4 v, vec4 n, vec4 dest)

    Reflection vector using an incident ray and a surface normal

    Parameters:
      | *[in]*  **v**     incident vector
      | *[in]*  **n**     *❗️ normalized ❗️* normal vector
      | *[out]* **dest**  destination: reflection result

.. c:function:: bool glm_vec4_refract(vec4 v, vec4 n, float eta, vec4 dest)

    computes refraction vector for an incident vector and a surface normal.
   
    Calculates the refraction vector based on Snell's law. If total internal reflection
    occurs (angle too great given eta), dest is set to zero and returns false.
    Otherwise, computes refraction vector, stores it in dest, and returns true.
   
    This implementation does not explicitly preserve the 'w' component of the
    incident vector 'I' in the output 'dest', users requiring the preservation of
    the 'w' component should manually adjust 'dest' after calling this function.

    Parameters:
      | *[in]*  **v**     *❗️ normalized ❗️* incident vector
      | *[in]*  **n**     *❗️ normalized ❗️* normal vector
      | *[in]*  **eta**   ratio of indices of refraction (incident/transmitted)
      | *[out]* **dest**  refraction vector if refraction occurs; zero vector otherwise

    Returns:
      returns true if refraction occurs; false if total internal reflection occurs.
