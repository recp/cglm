.. default-domain:: C

Bezier
================================================================================

Header: cglm/bezier.h

Common helpers for cubic bezier and similar curves.

Table of contents (click to go):
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

Functions:

1. :c:func:`glm_bezier`
2. :c:func:`glm_hermite`
3. :c:func:`glm_decasteljau`

Functions documentation
~~~~~~~~~~~~~~~~~~~~~~~

.. c:function:: float glm_bezier(float s, float p0, float c0, float c1, float p1)

    | cubic bezier interpolation
    | formula:

    .. code-block:: text

      B(s) = P0*(1-s)^3 + 3*C0*s*(1-s)^2 + 3*C1*s^2*(1-s) + P1*s^3

    | similar result using matrix:

    .. code-block:: text

      B(s) = glm_smc(t, GLM_BEZIER_MAT, (vec4){p0, c0, c1, p1})

    | glm_eq(glm_smc(...), glm_bezier(...)) should return TRUE

    Parameters:
      | *[in]*  **s**   parameter between 0 and 1
      | *[in]*  **p0**  begin point
      | *[in]*  **c0**  control point 1
      | *[in]*  **c1**  control point 2
      | *[in]*  **p1**  end point

    Returns:
        B(s)

.. c:function:: float glm_hermite(float s, float p0, float t0, float t1, float p1)

    | cubic hermite interpolation
    | formula:

    .. code-block:: text

      H(s) = P0*(2*s^3 - 3*s^2 + 1) + T0*(s^3 - 2*s^2 + s) + P1*(-2*s^3 + 3*s^2) + T1*(s^3 - s^2)

    | similar result using matrix:

    .. code-block:: text

      H(s) = glm_smc(t, GLM_HERMITE_MAT, (vec4){p0, p1, c0, c1})

    | glm_eq(glm_smc(...), glm_hermite(...)) should return TRUE


    Parameters:
      | *[in]*  **s**   parameter between 0 and 1
      | *[in]*  **p0**  begin point
      | *[in]*  **t0**  tangent 1
      | *[in]*  **t1**  tangent 2
      | *[in]*  **p1**  end point

    Returns:
        B(s)

.. c:function:: float glm_decasteljau(float prm, float p0, float c0, float c1, float p1)

    | iterative way to solve cubic equation

    Parameters:
      | *[in]*  **prm** parameter between 0 and 1
      | *[in]*  **p0**  begin point
      | *[in]*  **c0**  control point 1
      | *[in]*  **c1**  control point 2
      | *[in]*  **p1**  end point

    Returns:
        parameter to use in cubic equation
