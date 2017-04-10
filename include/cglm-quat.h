/*
 * Copyright (c), Recep Aslantas.
 *
 * MIT License (MIT), http://opensource.org/licenses/MIT
 * Full license can be found in the LICENSE file
 */

#ifndef cglm_quat_h
#define cglm_quat_h

#include "cglm-common.h"
#include "cglm-vec.h"
#include "arch/simd/cglm-intrin.h"
#include "arch/simd/cglm-quat-simd.h"

#define GLM_QUAT_IDENTITY_INIT  {0.0f, 0.0f, 0.0f, 1.0f}
#define GLM_QUAT_IDENTITY       (versor){0.0f, 0.0f, 0.0f, 1.0f}

CGLM_INLINE
void
glm_quat_identity(versor q) {
  glm_vec4_copy(GLM_QUAT_IDENTITY, q);
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

  w = q[0];
  x = q[1];
  y = q[2];
  z = q[3];

  dest[0][0] = 1.0f - 2.0f * (y * y + z * z);
  dest[0][1] = 2.0f * (x * y + w * z);
  dest[0][2] = 2.0f * (x * z - w * y);
  dest[0][3] = 0.0f;
  dest[1][0] = 2.0f * (x * y - w * z);
  dest[1][1] = 1.0f - 2.0f * (x * x + z * z);
  dest[1][2] = 2.0f * (y * z + w * x);
  dest[1][3] = 0.0f;
  dest[2][0] = 2.0f * (x * z + w * y);
  dest[2][1] = 2.0f * (y * z - w * x);
  dest[2][2] = 1.0f - 2.0f * (x * x + y * y);
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
