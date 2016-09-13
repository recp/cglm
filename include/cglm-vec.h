/*
 * Copyright (c), Recep Aslantas.
 *
 * MIT License (MIT), http://opensource.org/licenses/MIT
 * Full license can be found in the LICENSE file
 */

#ifndef cglm_vec_h
#define cglm_vec_h

#include "cglm.h"
#include "cglm-intrin.h"
#include <math.h>

CGLM_INLINE
void
glm_vec_dup(vec3 a, vec3 dest) {
  dest[0] = a[0];
  dest[1] = a[1];
  dest[2] = a[2];
}

CGLM_INLINE
void
glm_vec4_dup(vec4 v, vec4 dest) {
#if defined( __SSE__ ) || defined( __SSE2__ )
  _mm_store_ps(dest, _mm_load_ps(v));
#else
  dest[0] = v[0];
  dest[1] = v[1];
  dest[2] = v[2];
  dest[3] = v[3];
#endif
}

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
  return sqrtf(vec[0] * vec[0] + vec[1] * vec[1] + vec[2] * vec[2]);
}

CGLM_INLINE
void
glm_vec_normalize_to(vec3 vec, vec3 dest) {
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

CGLM_INLINE
void
glm_vec_normalize(vec3 v) {
  float norm;

  norm = glm_vec_norm(v);

  if (norm == 0.0f) {
    v[0] = v[1] = v[2] = 0.0f;
    return;
  }

  v[0] = v[0] / norm;
  v[1] = v[1] / norm;
  v[2] = v[2] / norm;
}

CGLM_INLINE
void
glm_vec_add(vec3 v1, vec3 v2, vec3 dest) {
  dest[0] = v1[0] + v2[0];
  dest[1] = v1[1] + v2[1];
  dest[2] = v1[2] + v2[2];
}

CGLM_INLINE
void
glm_vec4_add(vec4 v1, vec4 v2, vec4 dest) {
#if defined( __SSE__ ) || defined( __SSE2__ )
  _mm_store_ps(dest,
               _mm_add_ps(_mm_load_ps(v1),
                          _mm_load_ps(v2)));
#else
  dest[0] = v1[0] + v2[0];
  dest[1] = v1[1] + v2[1];
  dest[2] = v1[2] + v2[2];
  dest[3] = v1[3] + v2[3];
#endif
}

CGLM_INLINE
void
glm_vec_sub(vec3 v1, vec3 v2, vec3 dest) {
  dest[0] = v1[0] - v2[0];
  dest[1] = v1[1] - v2[1];
  dest[2] = v1[2] - v2[2];
}

CGLM_INLINE
void
glm_vec4_sub(vec4 v1, vec4 v2, vec4 dest) {
#if defined( __SSE__ ) || defined( __SSE2__ )
  _mm_store_ps(dest,
               _mm_sub_ps(_mm_load_ps(v1),
                          _mm_load_ps(v2)));
#else
  dest[0] = v1[0] - v2[0];
  dest[1] = v1[1] - v2[1];
  dest[2] = v1[2] - v2[2];
  dest[3] = v1[3] - v2[3];
#endif
}

CGLM_INLINE
void
glm_vec_scale(vec3 v, float s, vec3 dest) {
  dest[0] = v[0] * s;
  dest[1] = v[1] * s;
  dest[2] = v[2] * s;
}

CGLM_INLINE
void
glm_vec4_scale(vec4 v, float s, vec4 dest) {
#if defined( __SSE__ ) || defined( __SSE2__ )
  _mm_store_ps(dest,
               _mm_mul_ps(_mm_load_ps(v),
                          _mm_set1_ps(s)));
#else
  dest[0] = v[0] * s;
  dest[1] = v[1] * s;
  dest[2] = v[2] * s;
  dest[3] = v[3] * s;
#endif
}

CGLM_INLINE
void
glm_vec_addvN(vec3 * __restrict vecs[], int len, vec3 dest) {
  /* TODO: */
}

#endif /* cglm_vec_h */
