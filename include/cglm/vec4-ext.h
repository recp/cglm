/*
 * Copyright (c), Recep Aslantas.
 *
 * MIT License (MIT), http://opensource.org/licenses/MIT
 * Full license can be found in the LICENSE file
 */

/*!
 * @brief SIMD like functions
 */

/*
 Functions:
   CGLM_INLINE void  glm_vec4_broadcast(float val, vec4 d);
   CGLM_INLINE bool  glm_vec4_eq(vec4 v, float val);
   CGLM_INLINE bool  glm_vec4_eq_eps(vec4 v, float val);
   CGLM_INLINE bool  glm_vec4_eq_all(vec4 v);
   CGLM_INLINE bool  glm_vec4_eqv(vec4 a, vec4 b);
   CGLM_INLINE bool  glm_vec4_eqv_eps(vec4 a, vec4 b);
   CGLM_INLINE float glm_vec4_max(vec4 v);
   CGLM_INLINE float glm_vec4_min(vec4 v);
   CGLM_INLINE bool  glm_vec4_isnan(vec4 v);
   CGLM_INLINE bool  glm_vec4_isinf(vec4 v);
   CGLM_INLINE bool  glm_vec4_isvalid(vec4 v);
   CGLM_INLINE void  glm_vec4_sign(vec4 v, vec4 dest);
   CGLM_INLINE void  glm_vec4_sqrt(vec4 v, vec4 dest);
 */

#ifndef cglm_vec4_ext_h
#define cglm_vec4_ext_h

#include "common.h"
#include "vec3-ext.h"

/*!
 * @brief fill a vector with specified value
 *
 * @param val value
 * @param d   dest
 */
CGLM_INLINE
void
glm_vec4_broadcast(float val, vec4 d) {
#if defined( __SSE__ ) || defined( __SSE2__ )
  glmm_store(d, _mm_set1_ps(val));
#else
  d[0] = d[1] = d[2] = d[3] = val;
#endif
}

/*!
 * @brief check if vector is equal to value (without epsilon)
 *
 * @param v   vector
 * @param val value
 */
CGLM_INLINE
bool
glm_vec4_eq(vec4 v, float val) {
  return v[0] == val
         && v[0] == v[1]
         && v[0] == v[2]
         && v[0] == v[3];
}

/*!
 * @brief check if vector is equal to value (with epsilon)
 *
 * @param v   vector
 * @param val value
 */
CGLM_INLINE
bool
glm_vec4_eq_eps(vec4 v, float val) {
  return fabsf(v[0] - val) <= FLT_EPSILON
         && fabsf(v[1] - val) <= FLT_EPSILON
         && fabsf(v[2] - val) <= FLT_EPSILON
         && fabsf(v[3] - val) <= FLT_EPSILON;
}

/*!
 * @brief check if vectors members are equal (without epsilon)
 *
 * @param v   vector
 */
CGLM_INLINE
bool
glm_vec4_eq_all(vec4 v) {
  return v[0] == v[1]
         && v[0] == v[2]
         && v[0] == v[3];
}

/*!
 * @brief check if vector is equal to another (without epsilon)
 *
 * @param a vector
 * @param b vector
 */
CGLM_INLINE
bool
glm_vec4_eqv(vec4 a, vec4 b) {
  return a[0] == b[0]
         && a[1] == b[1]
         && a[2] == b[2]
         && a[3] == b[3];
}

/*!
 * @brief check if vector is equal to another (with epsilon)
 *
 * @param a vector
 * @param b vector
 */
CGLM_INLINE
bool
glm_vec4_eqv_eps(vec4 a, vec4 b) {
  return fabsf(a[0] - b[0]) <= FLT_EPSILON
         && fabsf(a[1] - b[1]) <= FLT_EPSILON
         && fabsf(a[2] - b[2]) <= FLT_EPSILON
         && fabsf(a[3] - b[3]) <= FLT_EPSILON;
}

/*!
 * @brief max value of vector
 *
 * @param v vector
 */
CGLM_INLINE
float
glm_vec4_max(vec4 v) {
  float max;

  max = glm_vec3_max(v);
  if (v[3] > max)
    max = v[3];

  return max;
}

/*!
 * @brief min value of vector
 *
 * @param v vector
 */
CGLM_INLINE
float
glm_vec4_min(vec4 v) {
  float min;

  min = glm_vec3_min(v);
  if (v[3] < min)
    min = v[3];

  return min;
}

/*!
 * @brief check if one of items is NaN (not a number)
 *        you should only use this in DEBUG mode or very critical asserts
 *
 * @param[in] v vector
 */
CGLM_INLINE
bool
glm_vec4_isnan(vec4 v) {
  return isnan(v[0]) || isnan(v[1]) || isnan(v[2]) || isnan(v[3]);
}

/*!
 * @brief check if one of items is INFINITY
 *        you should only use this in DEBUG mode or very critical asserts
 *
 * @param[in] v vector
 */
CGLM_INLINE
bool
glm_vec4_isinf(vec4 v) {
  return isinf(v[0]) || isinf(v[1]) || isinf(v[2]) || isinf(v[3]);
}

/*!
 * @brief check if all items are valid number
 *        you should only use this in DEBUG mode or very critical asserts
 *
 * @param[in] v vector
 */
CGLM_INLINE
bool
glm_vec4_isvalid(vec4 v) {
  return !glm_vec4_isnan(v) && !glm_vec4_isinf(v);
}

/*!
 * @brief get sign of 32 bit float as +1, -1, 0
 *
 * Important: It returns 0 for zero/NaN input
 *
 * @param v vector
 */
CGLM_INLINE
void
glm_vec4_sign(vec4 v, vec4 dest) {
#if defined( __SSE2__ ) || defined( __SSE2__ )
  __m128 x0, x1, x2, x3, x4;

  x0 = glmm_load(v);
  x1 = _mm_set_ps(0.0f, 0.0f, 1.0f, -1.0f);
  x2 = glmm_shuff1x(x1, 2);

  x3 = _mm_and_ps(_mm_cmpgt_ps(x0, x2), glmm_shuff1x(x1, 1));
  x4 = _mm_and_ps(_mm_cmplt_ps(x0, x2), glmm_shuff1x(x1, 0));

  glmm_store(dest, _mm_or_ps(x3, x4));
#else
  dest[0] = glm_signf(v[0]);
  dest[1] = glm_signf(v[1]);
  dest[2] = glm_signf(v[2]);
  dest[3] = glm_signf(v[3]);
#endif
}

/*!
 * @brief square root of each vector item
 *
 * @param[in]  v    vector
 * @param[out] dest destination vector
 */
CGLM_INLINE
void
glm_vec4_sqrt(vec4 v, vec4 dest) {
#if defined( __SSE__ ) || defined( __SSE2__ )
  glmm_store(dest, _mm_sqrt_ps(glmm_load(v)));
#else
  dest[0] = sqrtf(v[0]);
  dest[1] = sqrtf(v[1]);
  dest[2] = sqrtf(v[2]);
  dest[3] = sqrtf(v[3]);
#endif
}

#endif /* cglm_vec4_ext_h */
