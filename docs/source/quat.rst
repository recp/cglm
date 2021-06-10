.. default-domain:: C

quaternions
===========

Header: cglm/quat.h

 **Important:** *cglm* stores quaternion as **[x, y, z, w]** in memory
 since **v0.4.0** it was **[w, x, y, z]**
 before v0.4.0 ( **v0.3.5 and earlier** ). w is real part.

What you can do with quaternions with existing functions is (Some of them):

- You can rotate transform matrix using quaterion
- You can rotate vector using quaterion
- You can create view matrix using quaterion
- You can create a lookrotation (from source point to dest)

Table of contents (click to go):
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

Macros:

1. GLM_QUAT_IDENTITY_INIT
#. GLM_QUAT_IDENTITY

Functions:

1. :c:func:`glm_quat_identity`
#. :c:func:`glm_quat_identity_array`
#. :c:func:`glm_quat_init`
#. :c:func:`glm_quat`
#. :c:func:`glm_quatv`
#. :c:func:`glm_quat_copy`
#. :c:func:`glm_quat_from_vecs`
#. :c:func:`glm_quat_norm`
#. :c:func:`glm_quat_normalize`
#. :c:func:`glm_quat_normalize_to`
#. :c:func:`glm_quat_dot`
#. :c:func:`glm_quat_conjugate`
#. :c:func:`glm_quat_inv`
#. :c:func:`glm_quat_add`
#. :c:func:`glm_quat_sub`
#. :c:func:`glm_quat_real`
#. :c:func:`glm_quat_imag`
#. :c:func:`glm_quat_imagn`
#. :c:func:`glm_quat_imaglen`
#. :c:func:`glm_quat_angle`
#. :c:func:`glm_quat_axis`
#. :c:func:`glm_quat_mul`
#. :c:func:`glm_quat_mat4`
#. :c:func:`glm_quat_mat4t`
#. :c:func:`glm_quat_mat3`
#. :c:func:`glm_quat_mat3t`
#. :c:func:`glm_quat_lerp`
#. :c:func:`glm_quat_nlerp`
#. :c:func:`glm_quat_slerp`
#. :c:func:`glm_quat_look`
#. :c:func:`glm_quat_for`
#. :c:func:`glm_quat_forp`
#. :c:func:`glm_quat_rotatev`
#. :c:func:`glm_quat_rotate`
#. :c:func:`glm_quat_rotate_at`
#. :c:func:`glm_quat_rotate_atm`

Functions documentation
~~~~~~~~~~~~~~~~~~~~~~~

.. c:function:: void  glm_quat_identity(versor q)

    | makes given quat to identity

    Parameters:
      | *[in, out]*  **q**    quaternion

.. c:function:: void  glm_quat_identity_array(versor * __restrict q, size_t count)

    | make given quaternion array's each element identity quaternion

    Parameters:
      | *[in, out]*  **q**   quat array (must be aligned (16) if alignment is not disabled)
      | *[in]*  **count**    count of quaternions

.. c:function:: void  glm_quat_init(versor q, float x, float y, float z, float w)

    | inits quaternion with given values

    Parameters:
      | *[out]* **q**      quaternion
      | *[in]*  **x**      imag.x
      | *[in]*  **y**      imag.y
      | *[in]*  **z**      imag.z
      | *[in]*  **w**      w (real part)

.. c:function:: void  glm_quat(versor q, float  angle, float  x, float  y, float  z)

    | creates NEW quaternion with individual axis components

    | given axis will be normalized

    Parameters:
      | *[out]* **q**      quaternion
      | *[in]*  **angle**  angle (radians)
      | *[in]*  **x**      axis.x
      | *[in]*  **y**      axis.y
      | *[in]*  **z**      axis.z

.. c:function:: void  glm_quatv(versor q, float  angle, vec3   axis)

    | creates NEW quaternion with axis vector

    | given axis will be normalized

    Parameters:
      | *[out]* **q**      quaternion
      | *[in]*  **angle**  angle (radians)
      | *[in]*  **axis**   axis (will be normalized)

.. c:function:: void  glm_quat_copy(versor q, versor dest)

    | copy quaternion to another one

    Parameters:
      | *[in]*  **q**     source quaternion
      | *[out]* **dest**  destination quaternion

.. c:function:: void  glm_quat_from_vecs(vec3 a, vec3 b, versor dest)

    | compute unit quaternion needed to rotate a into b

    References:
      * `Finding quaternion representing the rotation from one vector to another <https://stackoverflow.com/a/11741520/183120>`_
      * `Quaternion from two vectors <http://lolengine.net/blog/2014/02/24/quaternion-from-two-vectors-final>`_
      * `Angle between vectors <http://www.euclideanspace.com/maths/algebra/vectors/angleBetween/minorlogic.htm>`_

    Parameters:
      | *[in]*  **a**     unit vector
      | *[in]*  **b**     unit vector
      | *[in]*  **dest**  unit quaternion

.. c:function:: float  glm_quat_norm(versor q)

    | returns norm (magnitude) of quaternion

    Parameters:
      | *[in]*  **a**  quaternion

    Returns:
      norm (magnitude)

.. c:function:: void  glm_quat_normalize_to(versor q, versor dest)

    | normalize quaternion and store result in dest, original one will not be normalized

    Parameters:
      | *[in]*  **q**    quaternion to normalize into
      | *[out]* **dest** destination quaternion

.. c:function:: void  glm_quat_normalize(versor q)

    | normalize quaternion

    Parameters:
      | *[in, out]*  **q** quaternion

.. c:function:: float  glm_quat_dot(versor p, versor q)

    dot product of two quaternion

    Parameters:
      | *[in]*  **p**   quaternion 1
      | *[in]*  **q**   quaternion 2

    Returns:
      dot product

.. c:function:: void  glm_quat_conjugate(versor q, versor dest)

    conjugate of quaternion

    Parameters:
      | *[in]*  **q**      quaternion
      | *[in]*  **dest**   conjugate

.. c:function:: void  glm_quat_inv(versor q, versor dest)

    inverse of non-zero quaternion

    Parameters:
      | *[in]*  **q**      quaternion
      | *[in]*  **dest**   inverse quaternion

.. c:function:: void  glm_quat_add(versor p, versor q, versor dest)

    add (componentwise) two quaternions and store result in dest

    Parameters:
      | *[in]*  **p**      quaternion 1
      | *[in]*  **q**      quaternion 2
      | *[in]*  **dest**   result quaternion

.. c:function:: void  glm_quat_sub(versor p, versor q, versor dest)

    subtract (componentwise) two quaternions and store result in dest

    Parameters:
      | *[in]*  **p**      quaternion 1
      | *[in]*  **q**      quaternion 2
      | *[in]*  **dest**   result quaternion

.. c:function:: float  glm_quat_real(versor q)

    returns real part of quaternion

    Parameters:
      | *[in]*  **q**   quaternion

    Returns:
      real part (quat.w)

.. c:function:: void  glm_quat_imag(versor q, vec3 dest)

    returns imaginary part of quaternion

    Parameters:
      | *[in]*   **q**      quaternion
      | *[out]*  **dest**   imag

.. c:function:: void  glm_quat_imagn(versor q, vec3 dest)

    returns normalized imaginary part of quaternion

    Parameters:
      | *[in]*   **q**      quaternion
      | *[out]*  **dest**   imag

.. c:function:: float  glm_quat_imaglen(versor q)

    returns length of imaginary part of quaternion

    Parameters:
      | *[in]*   **q**      quaternion

    Returns:
      norm of imaginary part

.. c:function:: float  glm_quat_angle(versor q)

    returns angle of quaternion

    Parameters:
      | *[in]*  **q**   quaternion

    Returns:
      angles of quat (radians)

.. c:function:: void  glm_quat_axis(versor q, versor dest)

    axis of quaternion

    Parameters:
      | *[in]*   **p**      quaternion
      | *[out]*  **dest**   axis of quaternion

.. c:function:: void  glm_quat_mul(versor p, versor q, versor dest)

    | multiplies two quaternion and stores result in dest

    | this is also called Hamilton Product

    | According to WikiPedia:
    | The product of two rotation quaternions [clarification needed] will be
      equivalent to the rotation q followed by the rotation p

    Parameters:
      | *[in]*  **p**     quaternion 1 (first rotation)
      | *[in]*  **q**     quaternion 2 (second rotation)
      | *[out]* **dest**  result quaternion

.. c:function:: void  glm_quat_mat4(versor q, mat4 dest)

    | convert quaternion to mat4

    Parameters:
      | *[in]*  **q**     quaternion
      | *[out]* **dest**  result matrix

.. c:function:: void  glm_quat_mat4t(versor q, mat4 dest)

    | convert quaternion to mat4 (transposed). This is transposed version of glm_quat_mat4

    Parameters:
      | *[in]*  **q**     quaternion
      | *[out]* **dest**  result matrix

.. c:function:: void  glm_quat_mat3(versor q, mat3 dest)

    | convert quaternion to mat3

    Parameters:
      | *[in]*  **q**     quaternion
      | *[out]* **dest**  result matrix

.. c:function:: void  glm_quat_mat3t(versor q, mat3 dest)

    | convert quaternion to mat3 (transposed). This is transposed version of glm_quat_mat3

    Parameters:
      | *[in]*  **q**     quaternion
      | *[out]* **dest**  result matrix

.. c:function:: void  glm_quat_lerp(versor from, versor to, float t, versor dest)

    | interpolates between two quaternions
    | using spherical linear interpolation (LERP)

    Parameters:
      | *[in]*  **from**  from
      | *[in]*  **to**    to
      | *[in]*  **t**     interpolant (amount) clamped between 0 and 1
      | *[out]* **dest**  result quaternion

.. c:function:: void glm_quat_nlerp(versor q, versor r, float  t, versor dest)

    | interpolates between two quaternions
    | taking the shortest rotation path using
    | normalized linear interpolation (NLERP)

    | This is a cheaper alternative to slerp; most games use nlerp
    | for animations as it visually makes little difference.

    References:
      * `Understanding Slerp, Then Not Using it <http://number-none.com/product/Understanding%20Slerp,%20Then%20Not%20Using%20It>`_
      * `Lerp, Slerp and Nlerp <https://keithmaggio.wordpress.com/2011/02/15/math-magician-lerp-slerp-and-nlerp/>`_

    Parameters:
      | *[in]*  **from**  from
      | *[in]*  **to**    to
      | *[in]*  **t**     interpolant (amount) clamped between 0 and 1
      | *[out]* **dest**  result quaternion

.. c:function:: void glm_quat_slerp(versor q, versor r, float  t, versor dest)

    | interpolates between two quaternions
    | using spherical linear interpolation (SLERP)

    Parameters:
      | *[in]*  **from**  from
      | *[in]*  **to**    to
      | *[in]*  **t**     interpolant (amount) clamped between 0 and 1
      | *[out]* **dest**  result quaternion

.. c:function:: void  glm_quat_look(vec3 eye, versor ori, mat4 dest)

    | creates view matrix using quaternion as camera orientation

    Parameters:
      | *[in]*  **eye**   eye
      | *[in]*  **ori**   orientation in world space as quaternion
      | *[out]* **dest**  result matrix

.. c:function:: void  glm_quat_for(vec3 dir, vec3 up, versor dest)

    | creates look rotation quaternion

    Parameters:
      | *[in]*  **dir**   direction to look
      | *[in]*  **up**    up vector
      | *[out]* **dest**  result matrix

.. c:function:: void  glm_quat_forp(vec3 from, vec3 to, vec3 up, versor dest)

    | creates look rotation quaternion using source and destination positions p suffix stands for position

    | this is similar to glm_quat_for except this computes direction for glm_quat_for for you.

    Parameters:
      | *[in]*  **from**  source point
      | *[in]*  **to**    destination point
      | *[in]*  **up**    up vector
      | *[out]* **dest**  result matrix

.. c:function:: void  glm_quat_rotatev(versor q, vec3 v, vec3 dest)

    | crotate vector using using quaternion

    Parameters:
      | *[in]*  **q**     quaternion
      | *[in]*  **v**     vector to rotate
      | *[out]* **dest**  rotated vector

.. c:function:: void glm_quat_rotate(mat4 m, versor q, mat4 dest)

    | rotate existing transform matrix using quaternion

    instead of passing identity matrix, consider to use quat_mat4 functions

    Parameters:
      | *[in]*  **m**     existing transform matrix to rotate
      | *[in]*  **q**     quaternion
      | *[out]* **dest**  rotated matrix/transform

.. c:function:: void glm_quat_rotate_at(mat4 m, versor q, vec3 pivot)

    | rotate existing transform matrix using quaternion at pivot point

    Parameters:
      | *[in, out]*  **m**      existing transform matrix to rotate
      | *[in]*       **q**      quaternion
      | *[in]*       **pivot**  pivot

.. c:function:: void glm_quat_rotate_atm(mat4 m, versor q, vec3 pivot)

    | rotate NEW transform matrix using quaternion at pivot point
    | this creates rotation matrix, it assumes you don't have a matrix

    | this should work faster than glm_quat_rotate_at because it reduces one glm_translate.

    Parameters:
      | *[in, out]*  **m**      existing transform matrix to rotate
      | *[in]*       **q**      quaternion
      | *[in]*       **pivot**  pivot
