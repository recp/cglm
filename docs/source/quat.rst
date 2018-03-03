.. default-domain:: C

quaternions
===========

Header: cglm/quat.h

 **Important:** *cglm* stores quaternion as [w, x, y, z] in memory, don't
 forget that when changing quaternion items manually. For instance *quat[3]*
 is *quat.z* and *quat[0*] is *quat.w*. This may change in the future if *cglm*
 will got enough request to do that. Probably it will not be changed in near
 future

There are some TODOs for quaternions check TODO list to see them.

Also **versor** is identity quaternion so the type may change to **vec4** or
something else. This will not affect existing functions for your engine because
*versor* is alias of *vec4*

Table of contents (click to go):
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

Macros:

1. GLM_QUAT_IDENTITY_INIT
#. GLM_QUAT_IDENTITY

Functions:

1. :c:func:`glm_quat_identity`
#. :c:func:`glm_quat`
#. :c:func:`glm_quatv`
#. :c:func:`glm_quat_norm`
#. :c:func:`glm_quat_normalize`
#. :c:func:`glm_quat_dot`
#. :c:func:`glm_quat_mulv`
#. :c:func:`glm_quat_mat4`
#. :c:func:`glm_quat_slerp`

Functions documentation
~~~~~~~~~~~~~~~~~~~~~~~

.. c:function:: void  glm_quat_identity(versor q)

    | makes given quat to identity

    Parameters:
      | *[in, out]*  **q**    quaternion

.. c:function:: void  glm_quat(versor q, float  angle, float  x, float  y, float  z)

    | creates NEW quaternion with individual axis components

    Parameters:
      | *[out]* **q**      quaternion
      | *[in]*  **angle**  angle (radians)
      | *[in]*  **x**      axis.x
      | *[in]*  **y**      axis.y
      | *[in]*  **z**      axis.z

.. c:function:: void  glm_quatv(versor q, float  angle, vec3   v)

    | creates NEW quaternion with axis vector

    Parameters:
      | *[out]* **q**      quaternion
      | *[in]*  **angle**  angle (radians)
      | *[in]*  **v**      axis

.. c:function:: float  glm_quat_norm(versor q)

    | returns norm (magnitude) of quaternion

    Parameters:
      | *[in]*  **a**  quaternion

    Returns:
      norm (magnitude)

.. c:function:: void  glm_quat_normalize(versor q)

    | normalize quaternion

    Parameters:
      | *[in, out]*  **q** quaternion

.. c:function:: float  glm_quat_dot(versor q, versor r)

    dot product of two quaternion

    Parameters:
      | *[in]*  **q1**   quaternion 1
      | *[in]*  **q2**   quaternion 2

    Returns:
      dot product

.. c:function:: void  glm_quat_mulv(versor q1, versor q2, versor dest)

    | multiplies two quaternion and stores result in dest

    Parameters:
      | *[in]*  **q1**    quaternion 1
      | *[in]*  **q2**    quaternion 2
      | *[out]* **dest**  result quaternion

.. c:function:: void  glm_quat_mat4(versor q, mat4 dest)

    | convert quaternion to mat4

    Parameters:
      | *[in]*  **q**     quaternion
      | *[out]* **dest**  result matrix

.. c:function:: void glm_quat_slerp(versor q, versor r, float  t, versor dest)

    | interpolates between two quaternions
    | using spherical linear interpolation (SLERP)

    Parameters:
      | *[in]*  **q**     from
      | *[in]*  **r**     to
      | *[in]*  **t**     amout
      | *[out]* **dest**  result quaternion
