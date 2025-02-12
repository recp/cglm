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
   CGLM_INLINE void  glm_vec4_fill(vec4 v, float val);
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
   CGLM_INLINE void  glm_vec4_abs(vec4 v, vec4 dest);
   CGLM_INLINE void  glm_vec4_fract(vec4 v, vec4 dest);
   CGLM_INLINE void  glm_vec4_floor(vec4 v, vec4 dest);
   CGLM_INLINE float glm_vec4_mods(vec4 v, float s, vec4 dest);
   CGLM_INLINE float glm_vec4_steps(float edge, vec4 v, vec4 dest);
   CGLM_INLINE void  glm_vec4_stepr(vec4 edge, float v, vec4 dest);
   CGLM_INLINE float glm_vec4_hadd(vec4 v);
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
#if defined(__wasm__) && defined(__wasm_simd128__)
  glmm_store(d, wasm_f32x4_splat(val));
#elif defined( __SSE__ ) || defined( __SSE2__ )
  glmm_store(d, glmm_set1(val));
#else
  d[0] = d[1] = d[2] = d[3] = val;
#endif
}

/*!
 * @brief fill a vector with specified value
 *
 * @param v   dest
 * @param val value
 */
CGLM_INLINE
void
glm_vec4_fill(vec4 v, float val) {
#if defined(__wasm__) && defined(__wasm_simd128__)
  glmm_store(v, wasm_f32x4_splat(val));
#elif defined( __SSE__ ) || defined( __SSE2__ )
  glmm_store(v, glmm_set1(val));
#else
  v[0] = v[1] = v[2] = v[3] = val;
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
  return fabsf(v[0] - val) <= GLM_FLT_EPSILON
         && fabsf(v[1] - val) <= GLM_FLT_EPSILON
         && fabsf(v[2] - val) <= GLM_FLT_EPSILON
         && fabsf(v[3] - val) <= GLM_FLT_EPSILON;
}

/*!
 * @brief check if vector members are equal (without epsilon)
 *
 * @param v   vector
 */
CGLM_INLINE
bool
glm_vec4_eq_all(vec4 v) {
  return glm_vec4_eq_eps(v, v[0]);
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
  return fabsf(a[0] - b[0]) <= GLM_FLT_EPSILON
         && fabsf(a[1] - b[1]) <= GLM_FLT_EPSILON
         && fabsf(a[2] - b[2]) <= GLM_FLT_EPSILON
         && fabsf(a[3] - b[3]) <= GLM_FLT_EPSILON;
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
#ifndef CGLM_FAST_MATH
  return isnan(v[0]) || isnan(v[1]) || isnan(v[2]) || isnan(v[3]);
#else
  return false;
#endif
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
#ifndef CGLM_FAST_MATH
  return isinf(v[0]) || isinf(v[1]) || isinf(v[2]) || isinf(v[3]);
#else
  return false;
#endif
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
#if defined( __SSE__ ) || defined( __SSE2__ )
  __m128 x0, x1, x2, x3, x4;

  x0 = glmm_load(v);
  x1 = _mm_set_ps(0.0f, 0.0f, 1.0f, -1.0f);
  x2 = glmm_splat(x1, 2);

  x3 = _mm_and_ps(_mm_cmpgt_ps(x0, x2), glmm_splat(x1, 1));
  x4 = _mm_and_ps(_mm_cmplt_ps(x0, x2), glmm_splat(x1, 0));

  glmm_store(dest, _mm_or_ps(x3, x4));
#else
  dest[0] = glm_signf(v[0]);
  dest[1] = glm_signf(v[1]);
  dest[2] = glm_signf(v[2]);
  dest[3] = glm_signf(v[3]);
#endif
}

/*!
 * @brief absolute value of each vector item
 *
 * @param[in]  v    vector
 * @param[out] dest destination vector
 */
CGLM_INLINE
void
glm_vec4_abs(vec4 v, vec4 dest) {
#if defined(__wasm__) && defined(__wasm_simd128__)
  glmm_store(dest, glmm_abs(glmm_load(v)));
#elif defined( __SSE__ ) || defined( __SSE2__ )
  glmm_store(dest, glmm_abs(glmm_load(v)));
#elif defined(CGLM_NEON_FP)
  vst1q_f32(dest, vabsq_f32(vld1q_f32(v)));
#else
  dest[0] = fabsf(v[0]);
  dest[1] = fabsf(v[1]);
  dest[2] = fabsf(v[2]);
  dest[3] = fabsf(v[3]);
#endif
}

/*!
 * @brief fractional part of each vector item
 *
 * @param[in]  v    vector
 * @param[out] dest destination vector
 */
CGLM_INLINE
void
glm_vec4_fract(vec4 v, vec4 dest) {
  dest[0] = fminf(v[0] - floorf(v[0]), 0.999999940395355224609375f);
  dest[1] = fminf(v[1] - floorf(v[1]), 0.999999940395355224609375f);
  dest[2] = fminf(v[2] - floorf(v[2]), 0.999999940395355224609375f);
  dest[3] = fminf(v[3] - floorf(v[3]), 0.999999940395355224609375f);
}

/*!
 * @brief floor of each vector item
 *
 * @param[in]  v    vector
 * @param[out] dest destination vector
 */
CGLM_INLINE
void
glm_vec4_floor(vec4 v, vec4 dest) {
  dest[0] = floorf(v[0]);
  dest[1] = floorf(v[1]);
  dest[2] = floorf(v[2]);
  dest[3] = floorf(v[3]);
}

/*!
 * @brief mod of each vector item, result is written to dest (dest = v % s)
 *
 * @param[in]  v    vector
 * @param[in]  s    scalar
 * @param[out] dest destination vector
 */
CGLM_INLINE
void
glm_vec4_mods(vec4 v, float s, vec4 dest) {
  dest[0] = fmodf(v[0], s);
  dest[1] = fmodf(v[1], s);
  dest[2] = fmodf(v[2], s);
  dest[3] = fmodf(v[3], s);
}

/*!
 * @brief threshold each vector item with scalar
 *        condition is: (x[i] < edge) ? 0.0 : 1.0
 *
 * @param[in]   edge    threshold
 * @param[in]   x       vector to test against threshold
 * @param[out]  dest    destination
 */
CGLM_INLINE
void
glm_vec4_steps(float edge, vec4 x, vec4 dest) {
  dest[0] = glm_step(edge, x[0]);
  dest[1] = glm_step(edge, x[1]);
  dest[2] = glm_step(edge, x[2]);
  dest[3] = glm_step(edge, x[3]);
}

/*!
 * @brief threshold a value with *vector* as the threshold
 *        condition is: (x < edge[i]) ? 0.0 : 1.0
 *
 * @param[in]   edge    threshold vector
 * @param[in]   x       value to test against threshold
 * @param[out]  dest    destination
 */
CGLM_INLINE
void
glm_vec4_stepr(vec4 edge, float x, vec4 dest) {
  dest[0] = glm_step(edge[0], x);
  dest[1] = glm_step(edge[1], x);
  dest[2] = glm_step(edge[2], x);
  dest[3] = glm_step(edge[3], x);
}

/*!
 * @brief vector reduction by summation
 * @warning could overflow
 *
 * @param[in]   v    vector
 * @return      sum of all vector's elements
 */
CGLM_INLINE
float
glm_vec4_hadd(vec4 v) {
#if defined(__wasm__) && defined(__wasm_simd128__)
  return glmm_hadd(glmm_load(v));
#elif defined( __SSE__ ) || defined( __SSE2__ )
  return glmm_hadd(glmm_load(v));
#else
  return v[0] + v[1] + v[2] + v[3];
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
#if defined(__wasm__) && defined(__wasm_simd128__)
  glmm_store(dest, wasm_f32x4_sqrt(glmm_load(v)));
#elif defined( __SSE__ ) || defined( __SSE2__ )
  glmm_store(dest, _mm_sqrt_ps(glmm_load(v)));
#else
  dest[0] = sqrtf(v[0]);
  dest[1] = sqrtf(v[1]);
  dest[2] = sqrtf(v[2]);
  dest[3] = sqrtf(v[3]);
#endif
}

#endif /* cglm_vec4_ext_h */
