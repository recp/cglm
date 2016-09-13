/*
 * Copyright (c), Recep Aslantas.
 *
 * MIT License (MIT), http://opensource.org/licenses/MIT
 * Full license can be found in the LICENSE file
 */

#ifndef cglm_quat_h
#define cglm_quat_h

#include "cglm.h"
#include <math.h>

CGLM_INLINE
float
glm_quat_dot(versor q, versor r) {
  return q[0] * r[0] + q[1] * r[1] + q[2] * r[2] + q[3] * r[3];
}

CGLM_INLINE
void
glm_quat_slerp(versor q,
               versor r,
               float  t,
               versor dest) {
  float cosTheta, sinTheta, angle, a, b;

  cosTheta = glm_quat_dot(q, r);
  if (cosTheta < 0.0f) {
    q[0] *= -1.0f;
    q[1] *= -1.0f;
    q[2] *= -1.0f;
    q[3] *= -1.0f;

    cosTheta = glm_quat_dot(q, r);
  }

  if (fabs(cosTheta) >= 1.0f) {
    dest[0] = q[0];
    dest[1] = q[1];
    dest[2] = q[2];
    dest[3] = q[3];

    return;
  }

  sinTheta = sqrt(1.0f - cosTheta * cosTheta);

  /* LERP */
  if (fabs(sinTheta) < 0.001f) {
    dest[0] = (1.0f - t) * q[0] + t * r[0];
    dest[1] = (1.0f - t) * q[1] + t * r[1];
    dest[2] = (1.0f - t) * q[2] + t * r[2];
    dest[3] = (1.0f - t) * q[3] + t * r[3];
    return;
  }

  /* SLERP */
  angle = acos(cosTheta);
  a = sin((1.0f - t) * angle) / sinTheta;
  b = sin(t * angle) / sinTheta;

  dest[0] = q[0] * a + r[0] * b;
  dest[1] = q[1] * a + r[1] * b;
  dest[2] = q[2] * a + r[2] * b;
  dest[3] = q[3] * a + r[3] * b;
}

#endif /* cglm_quat_h */
