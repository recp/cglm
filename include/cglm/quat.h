/*
 * Copyright (c), Recep Aslantas.
 *
 * MIT License (MIT), http://opensource.org/licenses/MIT
 * Full license can be found in the LICENSE file
 */

/*
 Macros:
   GLM_QUAT_IDENTITY_INIT
   GLM_QUAT_IDENTITY

 Functions:
   CGLM_INLINE void glm_quat_identity(versor q);
   CGLM_INLINE void glm_quat_init(versor q, float x, float y, float z, float w);
   CGLM_INLINE void glm_quat(versor q, float angle, float x, float y, float z);
   CGLM_INLINE void glm_quatv(versor q, float angle, vec3 axis);
   CGLM_INLINE void glm_quat_copy(versor q, versor dest);
   CGLM_INLINE float glm_quat_norm(versor q);
   CGLM_INLINE void glm_quat_normalize(versor q);
   CGLM_INLINE void glm_quat_normalize_to(versor q, versor dest);
   CGLM_INLINE float glm_quat_dot(versor p, versor q);
   CGLM_INLINE void glm_quat_conjugate(versor q, versor dest);
   CGLM_INLINE void glm_quat_inv(versor q, versor dest);
   CGLM_INLINE void glm_quat_add(versor p, versor q, versor dest);
   CGLM_INLINE void glm_quat_sub(versor p, versor q, versor dest);
   CGLM_INLINE float glm_quat_real(versor q);
   CGLM_INLINE void glm_quat_imag(versor q, vec3 dest);
   CGLM_INLINE void glm_quat_imagn(versor q, vec3 dest);
   CGLM_INLINE float glm_quat_imaglen(versor q);
   CGLM_INLINE float glm_quat_angle(versor q);
   CGLM_INLINE void glm_quat_axis(versor q, vec3 dest);
   CGLM_INLINE void glm_quat_mul(versor p, versor q, versor dest);
   CGLM_INLINE void glm_quat_mat4(versor q, mat4 dest);
   CGLM_INLINE void glm_quat_mat4t(versor q, mat4 dest);
   CGLM_INLINE void glm_quat_mat3(versor q, mat3 dest);
   CGLM_INLINE void glm_quat_mat3t(versor q, mat3 dest);
   CGLM_INLINE void glm_quat_lerp(versor from, versor to, float t, versor dest);
   CGLM_INLINE void glm_quat_lerpc(versor from, versor to, float t, versor dest);
   CGLM_INLINE void glm_quat_slerp(versor q, versor r, float t, versor dest);
   CGLM_INLINE void glm_quat_look(vec3 eye, versor ori, mat4 dest);
   CGLM_INLINE void glm_quat_for(vec3 dir, vec3 fwd, vec3 up, versor dest);
   CGLM_INLINE void glm_quat_forp(vec3 from,
                                  vec3 to,
                                  vec3 fwd,
                                  vec3 up,
                                  versor dest);
   CGLM_INLINE void glm_quat_rotatev(versor q, vec3 v, vec3 dest);
   CGLM_INLINE void glm_quat_rotate(mat4 m, versor q, mat4 dest);
 */

#ifndef cglm_quat_h
#define cglm_quat_h

#include "common.h"
#include "vec3.h"
#include "vec4.h"
#include "mat4.h"
#include "mat3.h"
#include "affine-mat.h"

#ifdef CGLM_SSE_FP
#  include "simd/sse2/quat.h"
#endif

CGLM_INLINE
void
glm_mat4_identity(mat4 mat);

CGLM_INLINE
void
glm_mat4_mulv(mat4 m, vec4 v, vec4 dest);

CGLM_INLINE
void
glm_mul_rot(mat4 m1, mat4 m2, mat4 dest);

CGLM_INLINE
void
glm_translate(mat4 m, vec3 v);

/*
 * IMPORTANT:
 * ----------------------------------------------------------------------------
 * cglm stores quat as [x, y, z, w] since v0.3.6
 *
 * it was [w, x, y, z] before v0.3.6 it has been changed to [x, y, z, w]
 * with v0.3.6 version.
 * ----------------------------------------------------------------------------
 */

#define GLM_QUAT_IDENTITY_INIT  {0.0f, 0.0f, 0.0f, 1.0f}
#define GLM_QUAT_IDENTITY       ((versor)GLM_QUAT_IDENTITY_INIT)

/*!
 * @brief makes given quat to identity
 *
 * @param[in, out]  q  quaternion
 */
CGLM_INLINE
void
glm_quat_identity(versor q) {
  CGLM_ALIGN(16) versor v = GLM_QUAT_IDENTITY_INIT;
  glm_vec4_copy(v, q);
}

/*!
 * @brief make given quaternion array's each element identity quaternion
 *
 * @param[in, out]  q     quat array (must be aligned (16)
 *                        if alignment is not disabled)
 *
 * @param[in]       count count of quaternions
 */
CGLM_INLINE
void
glm_quat_identity_array(versor * __restrict q, size_t count) {
  CGLM_ALIGN(16) versor v = GLM_QUAT_IDENTITY_INIT;
  size_t i;

  for (i = 0; i < count; i++) {
    glm_vec4_copy(v, q[i]);
  }
}

/*!
 * @brief inits quaterion with raw values
 *
 * @param[out]  q     quaternion
 * @param[in]   x     x
 * @param[in]   y     y
 * @param[in]   z     z
 * @param[in]   w     w (real part)
 */
CGLM_INLINE
void
glm_quat_init(versor q, float x, float y, float z, float w) {
  q[0] = x;
  q[1] = y;
  q[2] = z;
  q[3] = w;
}

/*!
 * @brief creates NEW quaternion with axis vector
 *
 * @param[out]  q     quaternion
 * @param[in]   angle angle (radians)
 * @param[in]   axis  axis
 */
CGLM_INLINE
void
glm_quatv(versor q, float angle, vec3 axis) {
  CGLM_ALIGN(8) vec3 k;
  float a, c, s;

  a = angle * 0.5f;
  c = cosf(a);
  s = sinf(a);

  glm_normalize_to(axis, k);

  q[0] = s * k[0];
  q[1] = s * k[1];
  q[2] = s * k[2];
  q[3] = c;
}

/*!
 * @brief creates NEW quaternion with individual axis components
 *
 * @param[out]  q     quaternion
 * @param[in]   angle angle (radians)
 * @param[in]   x     axis.x
 * @param[in]   y     axis.y
 * @param[in]   z     axis.z
 */
CGLM_INLINE
void
glm_quat(versor q, float angle, float x, float y, float z) {
  CGLM_ALIGN(8) vec3 axis = {x, y, z};
  glm_quatv(q, angle, axis);
}

/*!
 * @brief copy quaternion to another one
 *
 * @param[in]  q     quaternion
 * @param[out] dest  destination
 */
CGLM_INLINE
void
glm_quat_copy(versor q, versor dest) {
  glm_vec4_copy(q, dest);
}

/*!
 * @brief returns norm (magnitude) of quaternion
 *
 * @param[out]  q  quaternion
 */
CGLM_INLINE
float
glm_quat_norm(versor q) {
  return glm_vec4_norm(q);
}

/*!
 * @brief normalize quaternion and store result in dest
 *
 * @param[in]   q     quaternion to normalze
 * @param[out]  dest  destination quaternion
 */
CGLM_INLINE
void
glm_quat_normalize_to(versor q, versor dest) {
#if defined( __SSE2__ ) || defined( __SSE2__ )
  __m128 xdot, x0;
  float  dot;

  x0   = glmm_load(q);
  xdot = glmm_vdot(x0, x0);
  dot  = _mm_cvtss_f32(xdot);

  if (dot <= 0.0f) {
    glm_quat_identity(dest);
    return;
  }

  glmm_store(dest, _mm_div_ps(x0, _mm_sqrt_ps(xdot)));
#else
  float dot;

  dot = glm_vec4_norm2(q);

  if (dot <= 0.0f) {
    glm_quat_identity(dest);
    return;
  }

  glm_vec4_scale(q, 1.0f / sqrtf(dot), dest);
#endif
}

/*!
 * @brief normalize quaternion
 *
 * @param[in, out]  q  quaternion
 */
CGLM_INLINE
void
glm_quat_normalize(versor q) {
  glm_quat_normalize_to(q, q);
}

/*!
 * @brief dot product of two quaternion
 *
 * @param[in]  p  quaternion 1
 * @param[in]  q  quaternion 2
 */
CGLM_INLINE
float
glm_quat_dot(versor p, versor q) {
  return glm_vec4_dot(p, q);
}

/*!
 * @brief conjugate of quaternion
 *
 * @param[in]   q     quaternion
 * @param[out]  dest  conjugate
 */
CGLM_INLINE
void
glm_quat_conjugate(versor q, versor dest) {
  glm_vec4_negate_to(q, dest);
  dest[3] = -dest[3];
}

/*!
 * @brief inverse of non-zero quaternion
 *
 * @param[in]   q    quaternion
 * @param[out]  dest inverse quaternion
 */
CGLM_INLINE
void
glm_quat_inv(versor q, versor dest) {
  CGLM_ALIGN(16) versor conj;
  glm_quat_conjugate(q, conj);
  glm_vec4_scale(conj, 1.0f / glm_vec4_norm2(q), dest);
}

/*!
 * @brief add (componentwise) two quaternions and store result in dest
 *
 * @param[in]   p    quaternion 1
 * @param[in]   q    quaternion 2
 * @param[out]  dest result quaternion
 */
CGLM_INLINE
void
glm_quat_add(versor p, versor q, versor dest) {
  glm_vec4_add(p, q, dest);
}

/*!
 * @brief subtract (componentwise) two quaternions and store result in dest
 *
 * @param[in]   p    quaternion 1
 * @param[in]   q    quaternion 2
 * @param[out]  dest result quaternion
 */
CGLM_INLINE
void
glm_quat_sub(versor p, versor q, versor dest) {
  glm_vec4_sub(p, q, dest);
}

/*!
 * @brief returns real part of quaternion
 *
 * @param[in]   q    quaternion
 */
CGLM_INLINE
float
glm_quat_real(versor q) {
  return q[3];
}

/*!
 * @brief returns imaginary part of quaternion
 *
 * @param[in]   q    quaternion
 * @param[out]  dest imag
 */
CGLM_INLINE
void
glm_quat_imag(versor q, vec3 dest) {
  dest[0] = q[0];
  dest[1] = q[1];
  dest[2] = q[2];
}

/*!
 * @brief returns normalized imaginary part of quaternion
 *
 * @param[in]   q    quaternion
 */
CGLM_INLINE
void
glm_quat_imagn(versor q, vec3 dest) {
  glm_normalize_to(q, dest);
}

/*!
 * @brief returns length of imaginary part of quaternion
 *
 * @param[in]   q    quaternion
 */
CGLM_INLINE
float
glm_quat_imaglen(versor q) {
  return glm_vec3_norm(q);
}

/*!
 * @brief returns angle of quaternion
 *
 * @param[in]   q    quaternion
 */
CGLM_INLINE
float
glm_quat_angle(versor q) {
  /*
   sin(theta / 2) = length(x*x + y*y + z*z)
   cos(theta / 2) = w
   theta          = 2 * atan(sin(theta / 2) / cos(theta / 2))
   */
  return 2.0f * atan2f(glm_quat_imaglen(q), glm_quat_real(q));
}

/*!
 * @brief axis of quaternion
 *
 * @param[in]   q    quaternion
 * @param[out]  dest axis of quaternion
 */
CGLM_INLINE
void
glm_quat_axis(versor q, vec3 dest) {
  glm_quat_imagn(q, dest);
}

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
 * @param[out]  dest  result quaternion
 */
CGLM_INLINE
void
glm_quat_mul(versor p, versor q, versor dest) {
  /*
    + (a1 b2 + b1 a2 + c1 d2 − d1 c2)i
    + (a1 c2 − b1 d2 + c1 a2 + d1 b2)j
    + (a1 d2 + b1 c2 − c1 b2 + d1 a2)k
       a1 a2 − b1 b2 − c1 c2 − d1 d2
   */
#if defined( __SSE__ ) || defined( __SSE2__ )
  glm_quat_mul_sse2(p, q, dest);
#else
  dest[0] = p[3] * q[0] + p[0] * q[3] + p[1] * q[2] - p[2] * q[1];
  dest[1] = p[3] * q[1] - p[0] * q[2] + p[1] * q[3] + p[2] * q[0];
  dest[2] = p[3] * q[2] + p[0] * q[1] - p[1] * q[0] + p[2] * q[3];
  dest[3] = p[3] * q[3] - p[0] * q[0] - p[1] * q[1] - p[2] * q[2];
#endif
}

/*!
 * @brief convert quaternion to mat4
 *
 * @param[in]   q     quaternion
 * @param[out]  dest  result matrix
 */
CGLM_INLINE
void
glm_quat_mat4(versor q, mat4 dest) {
  float w, x, y, z,
        xx, yy, zz,
        xy, yz, xz,
        wx, wy, wz, norm, s;

  norm = glm_quat_norm(q);
  s    = norm > 0.0f ? 2.0f / norm : 0.0f;

  x = q[0];
  y = q[1];
  z = q[2];
  w = q[3];

  xx = s * x * x;   xy = s * x * y;   wx = s * w * x;
  yy = s * y * y;   yz = s * y * z;   wy = s * w * y;
  zz = s * z * z;   xz = s * x * z;   wz = s * w * z;

  dest[0][0] = 1.0f - yy - zz;
  dest[1][1] = 1.0f - xx - zz;
  dest[2][2] = 1.0f - xx - yy;

  dest[0][1] = xy + wz;
  dest[1][2] = yz + wx;
  dest[2][0] = xz + wy;

  dest[1][0] = xy - wz;
  dest[2][1] = yz - wx;
  dest[0][2] = xz - wy;

  dest[0][3] = 0.0f;
  dest[1][3] = 0.0f;
  dest[2][3] = 0.0f;
  dest[3][0] = 0.0f;
  dest[3][1] = 0.0f;
  dest[3][2] = 0.0f;
  dest[3][3] = 1.0f;
}

/*!
 * @brief convert quaternion to mat4 (transposed)
 *
 * @param[in]   q     quaternion
 * @param[out]  dest  result matrix as transposed
 */
CGLM_INLINE
void
glm_quat_mat4t(versor q, mat4 dest) {
  float w, x, y, z,
        xx, yy, zz,
        xy, yz, xz,
        wx, wy, wz, norm, s;

  norm = glm_quat_norm(q);
  s    = norm > 0.0f ? 2.0f / norm : 0.0f;

  x = q[0];
  y = q[1];
  z = q[2];
  w = q[3];

  xx = s * x * x;   xy = s * x * y;   wx = s * w * x;
  yy = s * y * y;   yz = s * y * z;   wy = s * w * y;
  zz = s * z * z;   xz = s * x * z;   wz = s * w * z;

  dest[0][0] = 1.0f - yy - zz;
  dest[1][1] = 1.0f - xx - zz;
  dest[2][2] = 1.0f - xx - yy;

  dest[1][0] = xy + wz;
  dest[2][1] = yz + wx;
  dest[0][2] = xz + wy;

  dest[0][1] = xy - wz;
  dest[1][2] = yz - wx;
  dest[2][0] = xz - wy;

  dest[0][3] = 0.0f;
  dest[1][3] = 0.0f;
  dest[2][3] = 0.0f;
  dest[3][0] = 0.0f;
  dest[3][1] = 0.0f;
  dest[3][2] = 0.0f;
  dest[3][3] = 1.0f;
}

/*!
 * @brief convert quaternion to mat3
 *
 * @param[in]   q     quaternion
 * @param[out]  dest  result matrix
 */
CGLM_INLINE
void
glm_quat_mat3(versor q, mat3 dest) {
  float w, x, y, z,
        xx, yy, zz,
        xy, yz, xz,
        wx, wy, wz, norm, s;

  norm = glm_quat_norm(q);
  s    = norm > 0.0f ? 2.0f / norm : 0.0f;

  x = q[0];
  y = q[1];
  z = q[2];
  w = q[3];

  xx = s * x * x;   xy = s * x * y;   wx = s * w * x;
  yy = s * y * y;   yz = s * y * z;   wy = s * w * y;
  zz = s * z * z;   xz = s * x * z;   wz = s * w * z;

  dest[0][0] = 1.0f - yy - zz;
  dest[1][1] = 1.0f - xx - zz;
  dest[2][2] = 1.0f - xx - yy;

  dest[0][1] = xy + wz;
  dest[1][2] = yz + wx;
  dest[2][0] = xz + wy;

  dest[1][0] = xy - wz;
  dest[2][1] = yz - wx;
  dest[0][2] = xz - wy;
}

/*!
 * @brief convert quaternion to mat3 (transposed)
 *
 * @param[in]   q     quaternion
 * @param[out]  dest  result matrix
 */
CGLM_INLINE
void
glm_quat_mat3t(versor q, mat3 dest) {
  float w, x, y, z,
        xx, yy, zz,
        xy, yz, xz,
        wx, wy, wz, norm, s;

  norm = glm_quat_norm(q);
  s    = norm > 0.0f ? 2.0f / norm : 0.0f;

  x = q[0];
  y = q[1];
  z = q[2];
  w = q[3];

  xx = s * x * x;   xy = s * x * y;   wx = s * w * x;
  yy = s * y * y;   yz = s * y * z;   wy = s * w * y;
  zz = s * z * z;   xz = s * x * z;   wz = s * w * z;

  dest[0][0] = 1.0f - yy - zz;
  dest[1][1] = 1.0f - xx - zz;
  dest[2][2] = 1.0f - xx - yy;

  dest[1][0] = xy + wz;
  dest[2][1] = yz + wx;
  dest[0][2] = xz + wy;

  dest[0][1] = xy - wz;
  dest[1][2] = yz - wx;
  dest[2][0] = xz - wy;
}

/*!
 * @brief interpolates between two quaternions
 *        using linear interpolation (LERP)
 *
 * @param[in]   from  from
 * @param[in]   to    to
 * @param[in]   t     interpolant (amount)
 * @param[out]  dest  result quaternion
 */
CGLM_INLINE
void
glm_quat_lerp(versor from, versor to, float t, versor dest) {
  glm_vec4_lerp(from, to, t, dest);
}

/*!
 * @brief interpolates between two quaternions
 *        using linear interpolation (LERP)
 *
 * @param[in]   from  from
 * @param[in]   to    to
 * @param[in]   t     interpolant (amount) clamped between 0 and 1
 * @param[out]  dest  result quaternion
 */
CGLM_INLINE
void
glm_quat_lerpc(versor from, versor to, float t, versor dest) {
  glm_vec4_lerpc(from, to, t, dest);
}

/*!
 * @brief interpolates between two quaternions
 *        using spherical linear interpolation (SLERP)
 *
 * @param[in]   from  from
 * @param[in]   to    to
 * @param[in]   t     amout
 * @param[out]  dest  result quaternion
 */
CGLM_INLINE
void
glm_quat_slerp(versor from, versor to, float t, versor dest) {
  CGLM_ALIGN(16) vec4 q1, q2;
  float cosTheta, sinTheta, angle;

  cosTheta = glm_quat_dot(from, to);
  glm_quat_copy(from, q1);

  if (fabsf(cosTheta) >= 1.0f) {
    glm_quat_copy(q1, dest);
    return;
  }

  if (cosTheta < 0.0f) {
    glm_vec4_negate(q1);
    cosTheta = -cosTheta;
  }

  sinTheta = sqrtf(1.0f - cosTheta * cosTheta);

  /* LERP to avoid zero division */
  if (fabsf(sinTheta) < 0.001f) {
    glm_quat_lerp(from, to, t, dest);
    return;
  }

  /* SLERP */
  angle = acosf(cosTheta);
  glm_vec4_scale(q1, sinf((1.0f - t) * angle), q1);
  glm_vec4_scale(to, sinf(t * angle), q2);

  glm_vec4_add(q1, q2, q1);
  glm_vec4_scale(q1, 1.0f / sinTheta, dest);
}

/*!
 * @brief creates view matrix using quaternion as camera orientation
 *
 * @param[in]   eye   eye
 * @param[in]   ori   orientation in world space as quaternion
 * @param[out]  dest  view matrix
 */
CGLM_INLINE
void
glm_quat_look(vec3 eye, versor ori, mat4 dest) {
  /* orientation */
  glm_quat_mat4t(ori, dest);

  /* translate */
  glm_mat4_mulv3(dest, eye, 1.0f, dest[3]);
  glm_vec3_negate(dest[3]);
}

/*!
 * @brief creates look rotation quaternion
 *
 * @param[in]   dir   direction to look
 * @param[in]   fwd   forward vector
 * @param[in]   up    up vector
 * @param[out]  dest  destination quaternion
 */
CGLM_INLINE
void
glm_quat_for(vec3 dir, vec3 fwd, vec3 up, versor dest) {
  CGLM_ALIGN(8) vec3 axis;
  float dot, angle;

  dot = glm_vec3_dot(dir, fwd);
  if (fabsf(dot + 1.0f)  < 0.000001f) {
    glm_quat_init(dest, up[0], up[1], up[2], GLM_PIf);
    return;
  }

  if (fabsf(dot - 1.0f) < 0.000001f) {
    glm_quat_identity(dest);
    return;
  }

  angle = acosf(dot);
  glm_cross(fwd, dir, axis);
  glm_normalize(axis);

  glm_quatv(dest, angle, axis);
}

/*!
 * @brief creates look rotation quaternion using source and
 *        destination positions p suffix stands for position
 *
 * @param[in]   from  source point
 * @param[in]   to    destination point
 * @param[in]   fwd   forward vector
 * @param[in]   up    up vector
 * @param[out]  dest  destination quaternion
 */
CGLM_INLINE
void
glm_quat_forp(vec3 from, vec3 to, vec3 fwd, vec3 up, versor dest) {
  CGLM_ALIGN(8) vec3 dir;
  glm_vec3_sub(to, from, dir);
  glm_quat_for(dir, fwd, up, dest);
}

/*!
 * @brief rotate vector using using quaternion
 *
 * @param[in]   q     quaternion
 * @param[in]   v     vector to rotate
 * @param[out]  dest  rotated vector
 */
CGLM_INLINE
void
glm_quat_rotatev(versor q, vec3 v, vec3 dest) {
  CGLM_ALIGN(16) versor p;
  CGLM_ALIGN(8)  vec3   u, v1, v2;
  float s;

  glm_quat_normalize_to(q, p);
  glm_quat_imag(p, u);
  s = glm_quat_real(p);

  glm_vec3_scale(u, 2.0f * glm_vec3_dot(u, v), v1);
  glm_vec3_scale(v, s * s - glm_vec3_dot(u, u), v2);
  glm_vec3_add(v1, v2, v1);

  glm_vec3_cross(u, v, v2);
  glm_vec3_scale(v2, 2.0f * s, v2);

  glm_vec3_add(v1, v2, dest);
}

/*!
 * @brief rotate existing transform matrix using quaternion
 *
 * @param[in]   m     existing transform matrix
 * @param[in]   q     quaternion
 * @param[out]  dest  rotated matrix/transform
 */
CGLM_INLINE
void
glm_quat_rotate(mat4 m, versor q, mat4 dest) {
  CGLM_ALIGN_MAT mat4 rot;
  glm_quat_mat4(q, rot);
  glm_mul_rot(m, rot, dest);
}

/*!
 * @brief rotate existing transform matrix using quaternion at pivot point
 *
 * @param[in, out]   m     existing transform matrix
 * @param[in]        q     quaternion
 * @param[out]       pivot pivot
 */
CGLM_INLINE
void
glm_quat_rotate_at(mat4 m, versor q, vec3 pivot) {
  CGLM_ALIGN(8) vec3 pivotInv;

  glm_vec3_negate_to(pivot, pivotInv);

  glm_translate(m, pivot);
  glm_quat_rotate(m, q, m);
  glm_translate(m, pivotInv);
}

/*!
 * @brief rotate NEW transform matrix using quaternion at pivot point
 *
 * this creates rotation matrix, it assumes you don't have a matrix
 *
 * this should work faster than glm_quat_rotate_at because it reduces
 * one glm_translate.
 *
 * @param[out]  m     existing transform matrix
 * @param[in]   q     quaternion
 * @param[in]   pivot pivot
 */
CGLM_INLINE
void
glm_quat_rotate_atm(mat4 m, versor q, vec3 pivot) {
  CGLM_ALIGN(8) vec3 pivotInv;

  glm_vec3_negate_to(pivot, pivotInv);

  glm_translate_make(m, pivot);
  glm_quat_rotate(m, q, m);
  glm_translate(m, pivotInv);
}

#endif /* cglm_quat_h */
