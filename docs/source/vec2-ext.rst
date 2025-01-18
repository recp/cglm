.. default-domain:: C

vec2 extra
==========

Header: cglm/vec2-ext.h

There are some functions are in called in extra header. These are called extra
because they are not used like other functions in vec2.h in the future some of
these functions ma be moved to vec2 header.

Table of contents (click to go):
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

Functions:

1. :c:func:`glm_vec2_fill`
#. :c:func:`glm_vec2_eq`
#. :c:func:`glm_vec2_eq_eps`
#. :c:func:`glm_vec2_eq_all`
#. :c:func:`glm_vec2_eqv`
#. :c:func:`glm_vec2_eqv_eps`
#. :c:func:`glm_vec2_max`
#. :c:func:`glm_vec2_min`
#. :c:func:`glm_vec2_isnan`
#. :c:func:`glm_vec2_isinf`
#. :c:func:`glm_vec2_isvalid`
#. :c:func:`glm_vec2_sign`
#. :c:func:`glm_vec2_abs`
#. :c:func:`glm_vec2_fract`
#. :c:func:`glm_vec2_floor`
#. :c:func:`glm_vec2_sqrt`

Functions documentation
~~~~~~~~~~~~~~~~~~~~~~~

.. c:function:: void glm_vec2_fill(vec2 v, float val)

    fill a vector with specified value

    Parameters:
      | *[in,out]* **dest**  destination
      | *[in]*     **val**   value
      

.. c:function:: bool glm_vec2_eq(vec2 v, float val)

    check if vector is equal to value (without epsilon)

    Parameters:
      | *[in]*  **v**    vector
      | *[in]*  **val**  value

.. c:function:: bool glm_vec2_eq_eps(vec2 v, float val)

    check if vector is equal to value (with epsilon)

    Parameters:
      | *[in]*  **v**    vector
      | *[in]*  **val**  value

.. c:function:: bool glm_vec2_eq_all(vec2 v)

    check if vectors members are equal (without epsilon)

    Parameters:
      | *[in]*  **v**   vector

.. c:function:: bool glm_vec2_eqv(vec2 v1, vec2 v2)

    check if vector is equal to another (without epsilon) vector

    Parameters:
      | *[in]*  **vec**   vector 1
      | *[in]*  **vec**   vector 2

.. c:function:: bool glm_vec2_eqv_eps(vec2 v1, vec2 v2)

    check if vector is equal to another (with epsilon)

    Parameters:
      | *[in]*  **v1**    vector1
      | *[in]*  **v2**    vector2

.. c:function:: float glm_vec2_max(vec2 v)

    max value of vector

    Parameters:
      | *[in]*  **v**    vector

.. c:function:: float glm_vec2_min(vec2 v)

     min value of vector

    Parameters:
      | *[in]*  **v**  vector

.. c:function:: bool glm_vec2_isnan(vec2 v)

    | check if one of items is NaN (not a number)
    | you should only use this in DEBUG mode or very critical asserts

    Parameters:
      | *[in]*  **v**  vector

.. c:function:: bool glm_vec2_isinf(vec2 v)

    | check if one of items is INFINITY
    | you should only use this in DEBUG mode or very critical asserts

    Parameters:
      | *[in]*  **v**  vector

.. c:function:: bool glm_vec2_isvalid(vec2 v)

    | check if all items are valid number
    | you should only use this in DEBUG mode or very critical asserts

    Parameters:
      | *[in]*  **v**  vector

.. c:function:: void glm_vec2_sign(vec2 v, vec2 dest)

    get sign of 32 bit float as +1, -1, 0

    Parameters:
      | *[in]*   **v**     vector
      | *[out]*  **dest**  sign vector (only keeps signs as -1, 0, -1)

.. c:function:: void glm_vec2_abs(vec2 v, vec2 dest)

    absolute value of each vector item

    Parameters:
      | *[in]*   **v**     vector
      | *[out]*  **dest**  destination vector

.. c:function:: void glm_vec2_fract(vec2 v, vec2 dest)
    
    get fractional part of each vector item

    Parameters:
      | *[in]*   **v**     vector
      | *[out]*  **dest**  destination vector

.. c:function:: void glm_vec2_floor(vec2 v, vec2 dest)

    floor value of each vector item

    Parameters:
      | *[in]*   **v**     vector
      | *[out]*  **dest**  destination vector

.. c:function:: void glm_vec2_sqrt(vec2 v, vec2 dest)

    square root of each vector item

    Parameters:
      | *[in]*   **v**     vector
      | *[out]*  **dest**  destination vector (sqrt(v))
