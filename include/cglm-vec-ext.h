/*
 * Copyright (c), Recep Aslantas.
 *
 * MIT License (MIT), http://opensource.org/licenses/MIT
 * Full license can be found in the LICENSE file
 */

/*!
 * @brief SIMD like functions
 */

#ifndef cglm_vec_ext_h
#define cglm_vec_ext_h

#include "cglm-common.h"
#include "cglm-intrin.h"

/*!
 * @brief multiplies individual items, just for convenient like SIMD
 *
 * @param a vec1
 * @param b vec2
 * @param d vec3 = (v1[0] * v2[0],  v1[1] * v2[1], v1[2] * v2[2])
 */
CGLM_INLINE
void
glm_vec_mulv(vec3 a, vec3 b, vec3 d) {
  d[0] = a[0] * b[0];
  d[1] = a[1] * b[1];
  d[2] = a[2] * b[2];
}

/*!
 * @brief multiplies individual items, just for convenient like SIMD
 *
 * @param a v1
 * @param b v2
 * @param d v3 = (v1[0] * v2[0],  v1[1] * v2[1], v1[2] * v2[2], v1[3] * v2[3])
 */
CGLM_INLINE
void
glm_vec4_mulv(vec4 a, vec4 b, vec4 d) {
#if defined( __SSE__ ) || defined( __SSE2__ )
  _mm_store_ps(d, _mm_mul_ps(_mm_load_ps(a), _mm_load_ps(b)));
#else
  d[0] = a[0] * b[0];
  d[1] = a[1] * b[1];
  d[2] = a[2] * b[2];
  d[3] = a[3] * b[3];
#endif
}

CGLM_INLINE
void
glm_vec_broadcast(float val, vec3 d) {
  d[0] = d[1] = d[2] = val;
}

CGLM_INLINE
void
glm_vec4_broadcast(float val, vec3 d) {
#if defined( __SSE__ ) || defined( __SSE2__ )
  _mm_store_ps(d, _mm_set1_ps(val));
#else
  d[0] = d[1] = d[2] = d[3] = val;
#endif
}

#endif /* cglm_vec_ext_h */
