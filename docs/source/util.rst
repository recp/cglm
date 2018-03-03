.. default-domain:: C

utils / helpers
================================================================================

Header: cglm/util.h



Table of contents (click to go):
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

Functions:

1. :c:func:`glm_sign`
#. :c:func:`glm_rad`
#. :c:func:`glm_deg`
#. :c:func:`glm_make_rad`
#. :c:func:`glm_make_deg`
#. :c:func:`glm_pow2`

Functions documentation
~~~~~~~~~~~~~~~~~~~~~~~

.. c:function:: int  glm_sign(int val)

    | returns sign of 32 bit integer as +1 or -1

    Parameters:
      | *[in]*  **val**   an integer

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
