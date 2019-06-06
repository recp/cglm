.. default-domain:: C

Curve
================================================================================

Header: cglm/curve.h

Common helpers for common curves. For specific curve see its header/doc
e.g bezier

Table of contents (click to go):
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

Functions:

1. :c:func:`glm_smc`

Functions documentation
~~~~~~~~~~~~~~~~~~~~~~~

.. c:function:: float  glm_smc(float s, mat4 m, vec4 c)

    | helper function to calculate **S** * **M** * **C** multiplication for curves

    | this function does not encourage you to use SMC, instead it is a helper if you use SMC.

    | if you want to specify S as vector then use more generic glm_mat4_rmc() func.

    | Example usage:

    .. code-block:: c

       Bs = glm_smc(s, GLM_BEZIER_MAT, (vec4){p0, c0, c1, p1})

    Parameters:
      | *[in]*  **s**  parameter between 0 and 1 (this will be [s3, s2, s, 1])
      | *[in]*  **m**  basis matrix
      | *[out]* **c**  position/control vector

    Returns:
        scalar value e.g. Bs
