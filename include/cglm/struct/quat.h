/*
 * Copyright (c), Recep Aslantas.
 *
 * MIT License (MIT), http://opensource.org/licenses/MIT
 * Full license can be found in the LICENSE file
 */

/*
 Macros:
   GLMS_QUAT_IDENTITY_INIT
   GLMS_QUAT_IDENTITY

 Functions:
   CGLM_DECL versors glms_quat_identity(void)
   CGLM_DECL void    glms_quat_identity_array(versor *q, size_t count)
   CGLM_DECL versors glms_quat_init(float x, float y, float z, float w)
   CGLM_DECL versors glms_quatv(float angle, vec3s axis)
   CGLM_DECL versors glms_quat(float angle, float x, float y, float z)
   CGLM_DECL float   glms_quat_norm(versors q)
   CGLM_DECL versors glms_quat_normalize(versors q)
   CGLM_DECL float   glms_quat_dot(versors p, versors q)
   CGLM_DECL versors glms_quat_conjugate(versors q)
   CGLM_DECL versors glms_quat_inv(versors q)
   CGLM_DECL versors glms_quat_add(versors p, versors q)
   CGLM_DECL versors glms_quat_sub(versors p, versors q)
   CGLM_DECL vec3s   glms_quat_imagn(versors q)
   CGLM_DECL float   glms_quat_imaglen(versors q)
   CGLM_DECL float   glms_quat_angle(versors q)
   CGLM_DECL vec3s   glms_quat_axis(versors q)
   CGLM_DECL versors glms_quat_mul(versors p, versors q)
   CGLM_DECL mat4s   glms_quat_mat4(versors q)
   CGLM_DECL mat4s   glms_quat_mat4t(versors q)
   CGLM_DECL mat3s   glms_quat_mat3(versors q)
   CGLM_DECL mat3s   glms_quat_mat3t(versors q)
   CGLM_DECL versors glms_quat_lerp(versors from, versors to, float t)
   CGLM_DECL versors glms_quat_lerpc(versors from, versors to, float t)
   CGLM_DECL versors glms_quat_slerp(versors from, versors to, float t)
   CGLM_DECL mat4s.  glms_quat_look(vec3s eye, versors ori)
   CGLM_DECL versors glms_quat_for(vec3s dir, vec3s fwd, vec3s up)
   CGLM_DECL versors glms_quat_forp(vec3s from, vec3s to, vec3s fwd, vec3s up)
   CGLM_DECL vec3s   glms_quat_rotatev(versors q, vec3s v)
   CGLM_DECL mat4s   glms_quat_rotate(mat4s m, versors q)
   CGLM_DECL mat4s   glms_quat_rotate_at(mat4s m, versors q, vec3s pivot)
   CGLM_DECL mat4s   glms_quat_rotate_atm(versors q, vec3s pivot)
 */

#ifndef cglms_quat_h
#define cglms_quat_h

#include "../common.h"
#include "../types-struct.h"
#include "../plane.h"
#include "../quat.h"

/*
 * IMPORTANT:
 * ----------------------------------------------------------------------------
 * cglm stores quat as [x, y, z, w] since v0.3.6
 *
 * it was [w, x, y, z] before v0.3.6 it has been changed to [x, y, z, w]
 * with v0.3.6 version.
 * ----------------------------------------------------------------------------
 */

#define GLMS_QUAT_IDENTITY_INIT  {GLM_QUAT_IDENTITY_INIT}
#define GLMS_QUAT_IDENTITY       ((versors)GLMS_QUAT_IDENTITY_INIT)

/*!
 * @brief makes given quat to identity
 *
 * @returns identity quaternion
 */
CGLM_DECL
versors
glms_quat_identity(void) CGLM_ENDD
#ifndef CGLM_LIB
{
  versors dest;
  glm_quat_identity(dest.raw);
  return dest;
}
#endif

/*!
 * @brief make given quaternion array's each element identity quaternion
 *
 * @param[in, out]  q     quat array (must be aligned (16)
 *                        if alignment is not disabled)
 *
 * @param[in]       count count of quaternions
 */
CGLM_DECL
void
glms_quat_identity_array(versors * __restrict q, size_t count) CGLM_ENDD
#ifndef CGLM_LIB
{
  CGLM_ALIGN(16) versor v = GLM_QUAT_IDENTITY_INIT;
  size_t i;

  for (i = 0; i < count; i++) {
    glm_vec4_copy(v, q[i].raw);
  }
}
#endif

/*!
 * @brief inits quaterion with raw values
 *
 * @param[in]   x     x
 * @param[in]   y     y
 * @param[in]   z     z
 * @param[in]   w     w (real part)
 * @returns quaternion
 */
CGLM_DECL
versors
glms_quat_init(float x, float y, float z, float w) CGLM_ENDD
#ifndef CGLM_LIB
{
  versors dest;
  glm_quat_init(dest.raw, x, y, z, w);
  return dest;
}
#endif

/*!
 * @brief creates NEW quaternion with axis vector
 *
 * @param[in]   angle angle (radians)
 * @param[in]   axis  axis
 * @returns quaternion
 */
CGLM_DECL
versors
glms_quatv(float angle, vec3s axis) CGLM_ENDD
#ifndef CGLM_LIB
{
  versors dest;
  glm_quatv(dest.raw, angle, axis.raw);
  return dest;
}
#endif

/*!
 * @brief creates NEW quaternion with individual axis components
 *
 * @param[in]   angle angle (radians)
 * @param[in]   x     axis.x
 * @param[in]   y     axis.y
 * @param[in]   z     axis.z
 * @returns quaternion
 */
CGLM_DECL
versors
glms_quat(float angle, float x, float y, float z) CGLM_ENDD
#ifndef CGLM_LIB
{
  versors dest;
  glm_quat(dest.raw, angle, x, y, z);
  return dest;
}
#endif

/*!
 * @brief returns norm (magnitude) of quaternion
 *
 * @param[out]  q  quaternion
 */
CGLM_DECL
float
glms_quat_norm(versors q) CGLM_ENDD
#ifndef CGLM_LIB
{
  return glm_quat_norm(q.raw);
}
#endif

/*!
 * @brief normalize quaternion
 *
 * @param[in]  q  quaternion
 * @returns    quaternion
 */
CGLM_DECL
versors
glms_quat_normalize(versors q) CGLM_ENDD
#ifndef CGLM_LIB
{
  versors dest;
  glm_quat_normalize_to(q.raw, dest.raw);
  return dest;
}
#endif

/*!
 * @brief dot product of two quaternion
 *
 * @param[in]  p  quaternion 1
 * @param[in]  q  quaternion 2
 * @returns    dot product
 */
CGLM_DECL
float
glms_quat_dot(versors p, versors q) CGLM_ENDD
#ifndef CGLM_LIB
{
  return glm_quat_dot(p.raw, q.raw);
}
#endif

/*!
 * @brief conjugate of quaternion
 *
 * @param[in]   q     quaternion
 * @returns    conjugate
 */
CGLM_DECL
versors
glms_quat_conjugate(versors q) CGLM_ENDD
#ifndef CGLM_LIB
{
  versors dest;
  glm_quat_conjugate(q.raw, dest.raw);
  return dest;
}
#endif

/*!
 * @brief inverse of non-zero quaternion
 *
 * @param[in]  q    quaternion
 * @returns    inverse quaternion
 */
CGLM_DECL
versors
glms_quat_inv(versors q) CGLM_ENDD
#ifndef CGLM_LIB
{
  versors dest;
  glm_quat_inv(q.raw, dest.raw);
  return dest;
}
#endif

/*!
 * @brief add (componentwise) two quaternions and store result in dest
 *
 * @param[in]   p    quaternion 1
 * @param[in]   q    quaternion 2
 * @returns result quaternion
 */
CGLM_DECL
versors
glms_quat_add(versors p, versors q) CGLM_ENDD
#ifndef CGLM_LIB
{
  versors dest;
  glm_quat_add(p.raw, q.raw, dest.raw);
  return dest;
}
#endif

/*!
 * @brief subtract (componentwise) two quaternions and store result in dest
 *
 * @param[in]   p    quaternion 1
 * @param[in]   q    quaternion 2
 * @returns result quaternion
 */
CGLM_DECL
versors
glms_quat_sub(versors p, versors q) CGLM_ENDD
#ifndef CGLM_LIB
{
  versors dest;
  glm_quat_sub(p.raw, q.raw, dest.raw);
  return dest;
}
#endif

/*!
 * @brief returns normalized imaginary part of quaternion
 *
 * @param[in]   q    quaternion
 */
CGLM_DECL
vec3s
glms_quat_imagn(versors q) CGLM_ENDD
#ifndef CGLM_LIB
{
  vec3s dest;
  glm_normalize_to(q.raw, dest.raw);
  return dest;
}
#endif

/*!
 * @brief returns length of imaginary part of quaternion
 *
 * @param[in]   q    quaternion
 */
CGLM_DECL
float
glms_quat_imaglen(versors q) CGLM_ENDD
#ifndef CGLM_LIB
{
  return glm_quat_imaglen(q.raw);
}
#endif

/*!
 * @brief returns angle of quaternion
 *
 * @param[in]   q    quaternion
 */
CGLM_DECL
float
glms_quat_angle(versors q) CGLM_ENDD
#ifndef CGLM_LIB
{
  return glm_quat_angle(q.raw);
}
#endif

/*!
 * @brief axis of quaternion
 *
 * @param[in]   q    quaternion
 * @returns axis of quaternion
 */
CGLM_DECL
vec3s
glms_quat_axis(versors q) CGLM_ENDD
#ifndef CGLM_LIB
{
  vec3s dest;
  glm_quat_axis(q.raw, dest.raw);
  return dest;
}
#endif

/*!
 * @brief multiplies two quaternion and stores result in dest
 *        this is also called Hamilton Product
 *
 * According to WikiPedia:
 * The product of two rotation quaternions [clarification needed] will be
 * equivalent to the rotation q followed by the rotation p
 *
 * @param[in]   p     quaternion 1
 * @param[in]   q     quaternion 2
 * @returns  result quaternion
 */
CGLM_DECL
versors
glms_quat_mul(versors p, versors q) CGLM_ENDD
#ifndef CGLM_LIB
{
  versors dest;
  glm_quat_mul(p.raw, q.raw, dest.raw);
  return dest;
}
#endif

/*!
 * @brief convert quaternion to mat4
 *
 * @param[in]   q     quaternion
 * @returns  result matrix
 */
CGLM_DECL
mat4s
glms_quat_mat4(versors q) CGLM_ENDD
#ifndef CGLM_LIB
{
  mat4s dest;
  glm_quat_mat4(q.raw, dest.raw);
  return dest;
}
#endif

/*!
 * @brief convert quaternion to mat4 (transposed)
 *
 * @param[in]   q     quaternion
 * @returns  result matrix as transposed
 */
CGLM_DECL
mat4s
glms_quat_mat4t(versors q) CGLM_ENDD
#ifndef CGLM_LIB
{
  mat4s dest;
  glm_quat_mat4t(q.raw, dest.raw);
  return dest;
}
#endif

/*!
 * @brief convert quaternion to mat3
 *
 * @param[in]   q     quaternion
 * @returns  result matrix
 */
CGLM_DECL
mat3s
glms_quat_mat3(versors q) CGLM_ENDD
#ifndef CGLM_LIB
{
  mat3s dest;
  glm_quat_mat3(q.raw, dest.raw);
  return dest;
}
#endif

/*!
 * @brief convert quaternion to mat3 (transposed)
 *
 * @param[in]   q     quaternion
 * @returns  result matrix
 */
CGLM_DECL
mat3s
glms_quat_mat3t(versors q) CGLM_ENDD
#ifndef CGLM_LIB
{
  mat3s dest;
  glm_quat_mat3t(q.raw, dest.raw);
  return dest;
}
#endif

/*!
 * @brief interpolates between two quaternions
 *        using linear interpolation (LERP)
 *
 * @param[in]   from  from
 * @param[in]   to    to
 * @param[in]   t     interpolant (amount)
 * @returns  result quaternion
 */
CGLM_DECL
versors
glms_quat_lerp(versors from, versors to, float t) CGLM_ENDD
#ifndef CGLM_LIB
{
  versors dest;
  glm_quat_lerp(from.raw, to.raw, t, dest.raw);
  return dest;
}
#endif

/*!
 * @brief interpolates between two quaternions
 *        using linear interpolation (LERP)
 *
 * @param[in]   from  from
 * @param[in]   to    to
 * @param[in]   t     interpolant (amount) clamped between 0 and 1
 * @returns  result quaternion
 */
CGLM_DECL
versors
glms_quat_lerpc(versors from, versors to, float t) CGLM_ENDD
#ifndef CGLM_LIB
{
  versors dest;
  glm_quat_lerpc(from.raw, to.raw, t, dest.raw);
  return dest;
}
#endif

/*!
 * @brief interpolates between two quaternions
 *        using spherical linear interpolation (SLERP)
 *
 * @param[in]   from  from
 * @param[in]   to    to
 * @param[in]   t     amout
 * @returns result quaternion
 */
CGLM_DECL
versors
glms_quat_slerp(versors from, versors to, float t) CGLM_ENDD
#ifndef CGLM_LIB
{
  versors dest;
  glm_quat_slerp(from.raw, to.raw, t, dest.raw);
  return dest;
}
#endif

/*!
 * @brief creates view matrix using quaternion as camera orientation
 *
 * @param[in]   eye   eye
 * @param[in]   ori   orientation in world space as quaternion
 * @returns  view matrix
 */
CGLM_DECL
mat4s
glms_quat_look(vec3s eye, versors ori) CGLM_ENDD
#ifndef CGLM_LIB
{
  mat4s dest;
  glm_quat_look(eye.raw, ori.raw, dest.raw);
  return dest;
}
#endif

/*!
 * @brief creates look rotation quaternion
 *
 * @param[in]   dir   direction to look
 * @param[in]   up    up vector
 * @returns  destination quaternion
 */
CGLM_DECL
versors
glms_quat_for(vec3s dir, vec3s up) CGLM_ENDD
#ifndef CGLM_LIB
{
  versors dest;
  glm_quat_for(dir.raw, up.raw, dest.raw);
  return dest;
}
#endif

/*!
 * @brief creates look rotation quaternion using source and
 *        destination positions p suffix stands for position
 *
 * @param[in]   from  source point
 * @param[in]   to    destination point
 * @param[in]   up    up vector
 * @returns  destination quaternion
 */
CGLM_DECL
versors
glms_quat_forp(vec3s from, vec3s to, vec3s up) CGLM_ENDD
#ifndef CGLM_LIB
{
  versors dest;
  glm_quat_forp(from.raw, to.raw, up.raw, dest.raw);
  return dest;
}
#endif

/*!
 * @brief rotate vector using using quaternion
 *
 * @param[in]   q     quaternion
 * @param[in]   v     vector to rotate
 * @returns  rotated vector
 */
CGLM_DECL
vec3s
glms_quat_rotatev(versors q, vec3s v) CGLM_ENDD
#ifndef CGLM_LIB
{
  vec3s dest;
  glm_quat_rotatev(q.raw, v.raw, dest.raw);
  return dest;
}
#endif

/*!
 * @brief rotate existing transform matrix using quaternion
 *
 * @param[in]   m     existing transform matrix
 * @param[in]   q     quaternion
 * @returns  rotated matrix/transform
 */
CGLM_DECL
mat4s
glms_quat_rotate(mat4s m, versors q) CGLM_ENDD
#ifndef CGLM_LIB
{
  glm_quat_rotate(m.raw, q.raw, m.raw);
  return m;
}
#endif

/*!
 * @brief rotate existing transform matrix using quaternion at pivot point
 *
 * @param[in, out]   m     existing transform matrix
 * @param[in]        q     quaternion
 * @returns pivot
 */
CGLM_DECL
mat4s
glms_quat_rotate_at(mat4s m, versors q, vec3s pivot) CGLM_ENDD
#ifndef CGLM_LIB
{
  glm_quat_rotate_at(m.raw, q.raw, pivot.raw);
  return m;
}
#endif

/*!
 * @brief rotate NEW transform matrix using quaternion at pivot point
 *
 * this creates rotation matrix, it assumes you don't have a matrix
 *
 * this should work faster than glm_quat_rotate_at because it reduces
 * one glm_translate.
 *
 * @param[in]   q     quaternion
 * @returns pivot
 */
CGLM_DECL
mat4s
glms_quat_rotate_atm(versors q, vec3s pivot) CGLM_ENDD
#ifndef CGLM_LIB
{
  mat4s dest;
  glm_quat_rotate_atm(dest.raw, q.raw, pivot.raw);
  return dest;
}
#endif

#endif /* cglms_quat_h */
