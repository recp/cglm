/*
 * Copyright (c), Recep Aslantas.
 *
 * MIT License (MIT), http://opensource.org/licenses/MIT
 * Full license can be found in the LICENSE file
 */

#ifndef cglm_vec_h
#define cglm_vec_h

#include "cglm.h"

CGLM_INLINE
float
glm_vec_dot(vec3 a, vec3 b) {
  return a[0] * b[0] + a[1] * b[1] + a[2] * b[2];
}

CGLM_INLINE
float
glm_vec_dot4(vec4 a, vec4 b) {
  return a[0] * b[0] + a[1] * b[1] + a[2] * b[2] + a[3] * b[3];
}

CGLM_INLINE
void
glm_vec_cross(vec3 a, vec3 b, vec3 d) {
  /* (u2.v3 - u3.v2, u3.v1 - u1.v3, u1.v2 - u2.v1) */
  d[0] = a[1] * b[2] - a[2] * b[1];
  d[1] = a[2] * b[0] - a[0] * b[2];
  d[2] = a[0] * b[1] - a[1] * b[0];
}

CGLM_INLINE
float
glm_vec_norm(vec3 vec) {
  return sqrt(vec[0] * vec[0] + vec[1] * vec[1] + vec[2] * vec[2]);
}

CGLM_INLINE
void
glm_vec_normalize(vec3 vec, vec3 dest) {
  float norm;

  norm = glm_vec_norm(vec);

  if (norm == 0.0f) {
    dest[0] = dest[1] = dest[2] = 0.0f;
    return;
  }

  dest[0] = vec[0] / norm;
  dest[1] = vec[1] / norm;
  dest[2] = vec[2] / norm;
}

#endif /* cglm_vec_h */
