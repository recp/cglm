.. default-domain:: C

vec3 extra
==========

Header: cglm/vec3-ext.h

There are some functions are in called in extra header. These are called extra
because they are not used like other functions in vec3.h in the future some of
these functions ma be moved to vec3 header.

Table of contents (click to go):
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

Functions:

1. :c:func:`glm_vec3_mulv`
#. :c:func:`glm_vec3_broadcast`
#. :c:func:`glm_vec3_eq`
#. :c:func:`glm_vec3_eq_eps`
#. :c:func:`glm_vec3_eq_all`
#. :c:func:`glm_vec3_eqv`
#. :c:func:`glm_vec3_eqv_eps`
#. :c:func:`glm_vec3_max`
#. :c:func:`glm_vec3_min`
#. :c:func:`glm_vec3_isnan`
#. :c:func:`glm_vec3_isinf`
#. :c:func:`glm_vec3_isvalid`
#. :c:func:`glm_vec3_sign`
#. :c:func:`glm_vec3_sqrt`

Functions documentation
~~~~~~~~~~~~~~~~~~~~~~~

.. c:function:: void  glm_vec3_mulv(vec3 a, vec3 b, vec3 d)

    multiplies individual items

    Parameters:
      | *[in]*  **a**  vec1
      | *[in]*  **b**  vec2
      | *[out]* **d**  destination (v1[0] * v2[0], v1[1] * v2[1], v1[2] * v2[2])

.. c:function:: void  glm_vec3_broadcast(float val, vec3 d)

    fill a vector with specified value

    Parameters:
      | *[in]*  **val**   value
      | *[out]* **dest**  destination

.. c:function:: bool  glm_vec3_eq(vec3 v, float val)

    check if vector is equal to value (without epsilon)

    Parameters:
      | *[in]*  **v**    vector
      | *[in]*  **val**  value

.. c:function:: bool  glm_vec3_eq_eps(vec3 v, float val)

    check if vector is equal to value (with epsilon)

    Parameters:
      | *[in]*  **v**    vector
      | *[in]*  **val**  value

.. c:function:: bool  glm_vec3_eq_all(vec3 v)

    check if vectors members are equal (without epsilon)

    Parameters:
      | *[in]*  **v**   vector

.. c:function:: bool  glm_vec3_eqv(vec3 v1, vec3 v2)

    check if vector is equal to another (without epsilon) vector

    Parameters:
      | *[in]*  **vec**   vector 1
      | *[in]*  **vec**   vector 2

.. c:function:: bool  glm_vec3_eqv_eps(vec3 v1, vec3 v2)

    check if vector is equal to another (with epsilon)

    Parameters:
      | *[in]*  **v1**    vector1
      | *[in]*  **v2**    vector2

.. c:function:: float  glm_vec3_max(vec3 v)

    max value of vector

    Parameters:
      | *[in]*  **v**    vector

.. c:function:: float glm_vec3_min(vec3 v)

     min value of vector

    Parameters:
      | *[in]*  **v**  vector

.. c:function:: bool glm_vec3_isnan(vec3 v)

    | check if one of items is NaN (not a number)
    | you should only use this in DEBUG mode or very critical asserts

    Parameters:
      | *[in]*  **v**  vector

.. c:function:: bool glm_vec3_isinf(vec3 v)

    | check if one of items is INFINITY
    | you should only use this in DEBUG mode or very critical asserts

    Parameters:
      | *[in]*  **v**  vector

.. c:function:: bool glm_vec3_isvalid(vec3 v)

    | check if all items are valid number
    | you should only use this in DEBUG mode or very critical asserts

    Parameters:
      | *[in]*  **v**  vector

.. c:function:: void glm_vec3_sign(vec3 v, vec3 dest)

    get sign of 32 bit float as +1, -1, 0

    Parameters:
      | *[in]*   **v**     vector
      | *[out]*  **dest**  sign vector (only keeps signs as -1, 0, -1)

.. c:function:: void glm_vec3_sqrt(vec3 v, vec3 dest)

    square root of each vector item

    Parameters:
      | *[in]*   **v**     vector
      | *[out]*  **dest**  destination vector (sqrt(v))
