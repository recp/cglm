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
   CGLM_INLINE void  glm_quatv(versor q, float angle, vec3 v);
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

#define GLM_QUAT_IDENTITY_INIT  {1.0f, 0.0f, 0.0f, 0.0f}
#define GLM_QUAT_IDENTITY       (versor){1.0f, 0.0f, 0.0f, 0.0f}

CGLM_INLINE
void
glm_quat_identity(versor q) {
  versor v = GLM_QUAT_IDENTITY_INIT;
  glm_vec4_copy(v, q);
}

CGLM_INLINE
void
glm_quat(versor q,
         float  angle,
         float  x,
         float  y,
         float  z) {
  float a, c, s;

  a = angle * 0.5f;
  c = cosf(a);
  s = sinf(a);

  q[0] = c;
  q[1] = s * x;
  q[2] = s * y;
  q[3] = s * z;
}

CGLM_INLINE
void
glm_quatv(versor q,
          float  angle,
          vec3   v) {
  float a, c, s;

  a = angle * 0.5f;
  c = cosf(a);
  s = sinf(a);

  q[0] = c;
  q[1] = s * v[0];
  q[2] = s * v[1];
  q[3] = s * v[2];
}

CGLM_INLINE
float
glm_quat_norm(versor q) {
  return glm_vec4_norm(q);
}

CGLM_INLINE
void
glm_quat_normalize(versor q) {
  float sum;

  sum = q[0] * q[0] + q[1] * q[1]
          + q[2] * q[2] + q[3] * q[3];

  if (fabs(1.0f - sum) < 0.0001f)
    return;

  glm_vec4_scale(q, 1.0f / sqrtf(sum), q);
}

CGLM_INLINE
float
glm_quat_dot(versor q, versor r) {
  return glm_vec4_dot(q, r);
}

CGLM_INLINE
void
glm_quat_mulv(versor q1, versor q2, versor dest) {
  dest[0] = q2[0] * q1[0] - q2[1] * q1[1] - q2[2] * q1[2] - q2[3] * q1[3];
  dest[1] = q2[0] * q1[1] + q2[1] * q1[0] - q2[2] * q1[3] + q2[3] * q1[2];
  dest[2] = q2[0] * q1[2] + q2[1] * q1[3] + q2[2] * q1[0] - q2[3] * q1[1];
  dest[3] = q2[0] * q1[3] - q2[1] * q1[2] + q2[2] * q1[1] + q2[3] * q1[0];

  glm_quat_normalize(dest);
}

CGLM_INLINE
void
glm_quat_mat4(versor q, mat4 dest) {
  float w, x, y, z;
  float xx, yy, zz;
  float xy, yz, xz;
  float wx, wy, wz;

  w = q[0];
  x = q[1];
  y = q[2];
  z = q[3];

  xx = 2.0f * x * x;   xy = 2.0f * x * y;   wx = 2.0f * w * x;
  yy = 2.0f * y * y;   yz = 2.0f * y * z;   wy = 2.0f * w * y;
  zz = 2.0f * z * z;   xz = 2.0f * x * z;   wz = 2.0f * w * z;

  dest[0][0] = 1.0f - yy - zz;
  dest[1][1] = 1.0f - xx - zz;
  dest[2][2] = 1.0f - xx - yy;

  dest[0][1] = xy + wz;
  dest[1][2] = yz + wx;
  dest[2][0] = xz + wy;

  dest[1][0] = xy - wz;
  dest[2][1] = yz - wx;
  dest[0][2] = xz - wy;

  dest[1][3] = 0.0f;
  dest[0][3] = 0.0f;
  dest[2][3] = 0.0f;
  dest[3][0] = 0.0f;
  dest[3][1] = 0.0f;
  dest[3][2] = 0.0f;
  dest[3][3] = 1.0f;
}

CGLM_INLINE
void
glm_quat_slerp(versor q,
               versor r,
               float  t,
               versor dest) {
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
