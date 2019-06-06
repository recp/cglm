.. default-domain:: C

color
================================================================================

Header: cglm/color.h

Table of contents (click to go):
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

Functions:

1. :c:func:`glm_luminance`

Functions documentation
~~~~~~~~~~~~~~~~~~~~~~~

.. c:function:: float  glm_luminance(vec3 rgb)

    | averages the color channels into one value

    This function uses formula in COLLADA 1.5 spec which is

    .. code-block:: text

       luminance = (color.r * 0.212671) +
                   (color.g * 0.715160) +
                   (color.b * 0.072169)

    It is based on the ISO/CIE color standards (see ITU-R Recommendation BT.709-4),
    that averages the color channels into one value

    Parameters:
      | *[in]*  **rgb**   RGB color
