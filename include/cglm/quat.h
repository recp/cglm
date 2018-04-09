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
   CGLM_INLINE void  glm_quat_identity(versor q);
   CGLM_INLINE void  glm_quat(versor q, float angle, float x, float y, float z);
   CGLM_INLINE void  glm_quatv(versor q, float angle, vec3 axis);
   CGLM_INLINE float glm_quat_norm(versor q);
   CGLM_INLINE void  glm_quat_normalize(versor q);
   CGLM_INLINE float glm_quat_dot(versor q, versor r);
   CGLM_INLINE void  glm_quat_mulv(versor q1, versor q2, versor dest);
   CGLM_INLINE void  glm_quat_mat4(versor q, mat4 dest);
   CGLM_INLINE void  glm_quat_slerp(versor q, versor r, float t, versor dest);
 */

#ifndef cglm_quat_h
#define cglm_quat_h

#include "common.h"
#include "vec4.h"

#ifdef CGLM_SSE_FP
#  include "simd/sse2/quat.h"
#endif

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
  versor v = GLM_QUAT_IDENTITY_INIT;
  glm_vec4_copy(v, q);
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
  float a, c, s;

  a = angle * 0.5f;
  c = cosf(a);
  s = sinf(a);

  q[0] = s * x;
  q[1] = s * y;
  q[2] = s * z;
  q[3] = c;
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
  float a, c, s;

  a = angle * 0.5f;
  c = cosf(a);
  s = sinf(a);

  q[0] = s * axis[0];
  q[1] = s * axis[1];
  q[2] = s * axis[2];
  q[3] = c;
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
 * @brief normalize quaternion
 *
 * @param[in, out]  q  quaternion
 */
CGLM_INLINE
void
glm_quat_normalize(versor q) {
  float sum;

  sum = glm_vec4_norm2(q);

  if (sum <= 0.0f) {
    glm_quat_identity(q);
    return;
  }

  glm_vec4_scale(q, 1.0f / sqrtf(sum), q);
}

/*!
 * @brief dot product of two quaternion
 *
 * @param[in]  q1  quaternion 1
 * @param[in]  q2  quaternion 2
 */
CGLM_INLINE
float
glm_quat_dot(versor q1, versor q2) {
  return glm_vec4_dot(q1, q2);
}

/*!
 * @brief multiplies two quaternion and stores result in dest
 *
 * @param[in]   q1    quaternion 1
 * @param[in]   q2    quaternion 2
 * @param[out]  dest  result quaternion
 */
CGLM_INLINE
void
glm_quat_mulv(versor q1, versor q2, versor dest) {
  dest[0] = q2[0] * q1[0] - q2[1] * q1[1] - q2[2] * q1[2] - q2[3] * q1[3];
  dest[1] = q2[0] * q1[1] + q2[1] * q1[0] - q2[2] * q1[3] + q2[3] * q1[2];
  dest[2] = q2[0] * q1[2] + q2[1] * q1[3] + q2[2] * q1[0] - q2[3] * q1[1];
  dest[3] = q2[0] * q1[3] - q2[1] * q1[2] + q2[2] * q1[1] + q2[3] * q1[0];

  glm_quat_normalize(dest);
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
  glm_vec4_copy(q, dest);
  glm_vec4_flipsign(dest);
  dest[3] = -dest[3];
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
 * @brief interpolates between two quaternions
 *        using spherical linear interpolation (SLERP)
 *
 * @param[in]   q     from
 * @param[in]   r     to
 * @param[in]   t     amout
 * @param[out]  dest  result quaternion
 */
CGLM_INLINE
void
glm_quat_slerp(versor q, versor r, float t, versor dest) {

  /* https://en.wikipedia.org/wiki/Slerp */
#if defined( __SSE__ ) || defined( __SSE2__ )
  glm_quat_slerp_sse2(q, r, t, dest);
#else
  float cosTheta, sinTheta, angle, a, b, c;

  cosTheta = glm_quat_dot(q, r);
  if (cosTheta < 0.0f) {
    q[0] *= -1.0f;
    q[1] *= -1.0f;
    q[2] *= -1.0f;
    q[3] *= -1.0f;

    cosTheta = -cosTheta;
  }

  if (fabs(cosTheta) >= 1.0f) {
    dest[0] = q[0];
    dest[1] = q[1];
    dest[2] = q[2];
    dest[3] = q[3];
    return;
  }

  sinTheta = sqrt(1.0f - cosTheta * cosTheta);

  c = 1.0f - t;

  /* LERP */
  /* TODO: FLT_EPSILON vs 0.001? */
  if (sinTheta < 0.001f) {
    dest[0] = c * q[0] + t * r[0];
    dest[1] = c * q[1] + t * r[1];
    dest[2] = c * q[2] + t * r[2];
    dest[3] = c * q[3] + t * r[3];
    return;
  }

  /* SLERP */
  angle = acosf(cosTheta);
  a = sinf(c * angle);
  b = sinf(t * angle);

  dest[0] = (q[0] * a + r[0] * b) / sinTheta;
  dest[1] = (q[1] * a + r[1] * b) / sinTheta;
  dest[2] = (q[2] * a + r[2] * b) / sinTheta;
  dest[3] = (q[3] * a + r[3] * b) / sinTheta;
#endif
}

#endif /* cglm_quat_h */
