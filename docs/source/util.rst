.. default-domain:: C

utils / helpers
================================================================================

Header: cglm/util.h



Table of contents (click to go):
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

Functions:

1. :c:func:`glm_sign`
#. :c:func:`glm_signf`
#. :c:func:`glm_rad`
#. :c:func:`glm_deg`
#. :c:func:`glm_make_rad`
#. :c:func:`glm_make_deg`
#. :c:func:`glm_pow2`
#. :c:func:`glm_min`
#. :c:func:`glm_max`
#. :c:func:`glm_clamp`
#. :c:func:`glm_lerp`
#. :c:func:`glm_swapf`

Functions documentation
~~~~~~~~~~~~~~~~~~~~~~~

.. c:function:: int  glm_sign(int val)

    | returns sign of 32 bit integer as +1, -1, 0

    | **Important**: It returns 0 for zero input

    Parameters:
      | *[in]*  **val**   an integer

    Returns:
      sign of given number

.. c:function:: float  glm_signf(float val)

    | returns sign of 32 bit integer as +1.0, -1.0, 0.0

    | **Important**: It returns 0.0f for zero input

    Parameters:
      | *[in]*  **val**   a float

    Returns:
      sign of given number

.. c:function:: float  glm_rad(float deg)

    | convert degree to radians

    Parameters:
      | *[in]*  **deg**   angle in degrees

.. c:function:: float glm_deg(float rad)

    | convert radians to degree

    Parameters:
      | *[in]*  **rad**      angle in radians

.. c:function:: void  glm_make_rad(float *degm)

    | convert exsisting degree to radians. this will override degrees value

    Parameters:
      | *[in, out]*  **deg**      pointer to angle in degrees

.. c:function:: void  glm_make_deg(float *rad)

    | convert exsisting radians to degree. this will override radians value

    Parameters:
      | *[in, out]*  **rad**      pointer to angle in radians

.. c:function:: float  glm_pow2(float x)

    | multiplies given parameter with itself = x * x or powf(x, 2)

    Parameters:
      | *[in]*  **x** value

    Returns:
      square of a given number

.. c:function:: float  glm_min(float a, float b)

    | returns minimum of given two values

    Parameters:
      | *[in]*  **a** number 1
      | *[in]*  **b** number 2

    Returns:
      minimum value

.. c:function:: float  glm_max(float a, float b)

    | returns maximum of given two values

    Parameters:
      | *[in]*  **a** number 1
      | *[in]*  **b** number 2

    Returns:
      maximum value

.. c:function:: void  glm_clamp(float val, float minVal, float maxVal)

    constrain a value to lie between two further values

    Parameters:
      | *[in]*  **val**     input value
      | *[in]*  **minVal**  minimum value
      | *[in]*  **maxVal**  maximum value

    Returns:
      clamped value

.. c:function:: float  glm_lerp(float from, float to, float t)

    linear interpolation between two number

    | formula:  from + s * (to - from)

    Parameters:
      | *[in]*  **from**   from value
      | *[in]*  **to**     to value
      | *[in]*  **t**      interpolant (amount) clamped between 0 and 1

    Returns:
       interpolated value

.. c:function:: bool glm_eq(float a, float b)

    check if two float equal with using EPSILON

    Parameters:
      | *[in]*  **a**   a
      | *[in]*  **b**   b

    Returns:
       true if a and b are equal

.. c:function:: float glm_percent(float from, float to, float current)

    percentage of current value between start and end value

    Parameters:
      | *[in]*  **from**   from value
      | *[in]*  **to**     to value
      | *[in]*  **current**   value between from and to values

    Returns:
       percentage of current value

.. c:function:: float glm_percentc(float from, float to, float current)

    clamped percentage of current value between start and end value

    Parameters:
      | *[in]*  **from**      from value
      | *[in]*  **to**        to value
      | *[in]*  **current**   value between from and to values

    Returns:
       clamped normalized percent (0-100 in 0-1)

.. c:function:: void glm_swapf(float *a, float *b) 

    swap two float values

    Parameters:
      | *[in]*  **a**      float 1
      | *[in]*  **b**      float 2
