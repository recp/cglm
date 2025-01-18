.. default-domain:: C

vec4 extra
==========

Header: cglm/vec4-ext.h

There are some functions are in called in extra header. These are called extra
because they are not used like other functions in vec4.h in the future some of
these functions ma be moved to vec4 header.

Table of contents (click to go):
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

Functions:

1. :c:func:`glm_vec4_mulv`
#. :c:func:`glm_vec4_broadcast`
#. :c:func:`glm_vec4_eq`
#. :c:func:`glm_vec4_eq_eps`
#. :c:func:`glm_vec4_eq_all`
#. :c:func:`glm_vec4_eqv`
#. :c:func:`glm_vec4_eqv_eps`
#. :c:func:`glm_vec4_max`
#. :c:func:`glm_vec4_min`
#. :c:func:`glm_vec4_isnan`
#. :c:func:`glm_vec4_isinf`
#. :c:func:`glm_vec4_isvalid`
#. :c:func:`glm_vec4_sign`
#. :c:func:`glm_vec4_abs`
#. :c:func:`glm_vec4_fract`
#. :c:func:`glm_vec4_floor`
#. :c:func:`glm_vec4_sqrt`


Functions documentation
~~~~~~~~~~~~~~~~~~~~~~~

.. c:function:: void  glm_vec4_mulv(vec4 a, vec4 b, vec4 d)

    multiplies individual items

    Parameters:
      | *[in]*  **a**  vec1
      | *[in]*  **b**  vec2
      | *[out]* **d**  destination

.. c:function:: void  glm_vec4_broadcast(float val, vec4 d)

    fill a vector with specified value

    Parameters:
      | *[in]*  **val**   value
      | *[out]* **dest**  destination

.. c:function:: bool  glm_vec4_eq(vec4 v, float val)

    check if vector is equal to value (without epsilon)

    Parameters:
      | *[in]*  **v**    vector
      | *[in]*  **val**  value

.. c:function:: bool  glm_vec4_eq_eps(vec4 v, float val)

    check if vector is equal to value (with epsilon)

    Parameters:
      | *[in]*  **v**    vector
      | *[in]*  **val**  value

.. c:function:: bool  glm_vec4_eq_all(vec4 v)

    check if vectors members are equal (without epsilon)

    Parameters:
      | *[in]*  **v**   vector

.. c:function:: bool  glm_vec4_eqv(vec4 v1, vec4 v2)

    check if vector is equal to another (without epsilon) vector

    Parameters:
      | *[in]*  **vec**   vector 1
      | *[in]*  **vec**   vector 2

.. c:function:: bool  glm_vec4_eqv_eps(vec4 v1, vec4 v2)

    check if vector is equal to another (with epsilon)

    Parameters:
      | *[in]*  **v1**    vector1
      | *[in]*  **v2**    vector2

.. c:function:: float  glm_vec4_max(vec4 v)

    max value of vector

    Parameters:
      | *[in]*  **v**    vector

.. c:function:: float glm_vec4_min(vec4 v)

     min value of vector

    Parameters:
      | *[in]*  **v**  vector

.. c:function:: bool glm_vec4_isnan(vec4 v)

    | check if one of items is NaN (not a number)
    | you should only use this in DEBUG mode or very critical asserts

    Parameters:
      | *[in]*  **v**  vector

.. c:function:: bool glm_vec4_isinf(vec4 v)

    | check if one of items is INFINITY
    | you should only use this in DEBUG mode or very critical asserts

    Parameters:
      | *[in]*  **v**  vector

.. c:function:: bool glm_vec4_isvalid(vec4 v)

    | check if all items are valid number
    | you should only use this in DEBUG mode or very critical asserts

    Parameters:
      | *[in]*  **v**  vector

.. c:function:: void glm_vec4_sign(vec4 v, vec4 dest)

    get sign of 32 bit float as +1, -1, 0

    Parameters:
      | *[in]*   **v**     vector
      | *[out]*  **dest**  sign vector (only keeps signs as -1, 0, -1)

.. c:function:: void glm_vec4_abs(vec4 v, vec4 dest)

    absolute value of each vector item

    Parameters:
      | *[in]*   **v**     vector
      | *[out]*  **dest**  destination vector (abs(v))

.. c:function:: void glm_vec4_fract(vec4 v, vec4 dest)

    fractional part of each vector item

    Parameters:
      | *[in]*   **v**     vector
      | *[out]*  **dest**  destination vector (fract(v))

.. c:function:: void glm_vec4_floor(vec4 v, vec4 dest)
    
    floor of each vector item

    Parameters:
      | *[in]*   **v**     vector
      | *[out]*  **dest**  destination vector (floor(v))

.. c:function:: void glm_vec4_sqrt(vec4 v, vec4 dest)

    square root of each vector item

    Parameters:
      | *[in]*   **v**     vector
      | *[out]*  **dest**  destination vector (sqrt(v))
