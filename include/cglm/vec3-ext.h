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
   CGLM_INLINE void  glm_vec3_broadcast(float val, vec3 d);
   CGLM_INLINE void  glm_vec3_fill(vec3 v, float val);
   CGLM_INLINE bool  glm_vec3_eq(vec3 v, float val);
   CGLM_INLINE bool  glm_vec3_eq_eps(vec3 v, float val);
   CGLM_INLINE bool  glm_vec3_eq_all(vec3 v);
   CGLM_INLINE bool  glm_vec3_eqv(vec3 a, vec3 b);
   CGLM_INLINE bool  glm_vec3_eqv_eps(vec3 a, vec3 b);
   CGLM_INLINE float glm_vec3_max(vec3 v);
   CGLM_INLINE float glm_vec3_min(vec3 v);
   CGLM_INLINE bool  glm_vec3_isnan(vec3 v);
   CGLM_INLINE bool  glm_vec3_isinf(vec3 v);
   CGLM_INLINE bool  glm_vec3_isvalid(vec3 v);
   CGLM_INLINE void  glm_vec3_sign(vec3 v, vec3 dest);
   CGLM_INLINE void  glm_vec3_abs(vec3 v, vec3 dest);
   CGLM_INLINE void  glm_vec3_fract(vec3 v, vec3 dest);
   CGLM_INLINE void  glm_vec3_floor(vec3 v, vec3 dest);
   CGLM_INLINE float glm_vec3_mods(vec3 v, float s, vec3 dest);
   CGLM_INLINE float glm_vec3_steps(float edge, vec3 v, vec3 dest);
   CGLM_INLINE void  glm_vec3_stepr(vec3 edge, float v, vec3 dest);
   CGLM_INLINE float glm_vec3_hadd(vec3 v);
   CGLM_INLINE void  glm_vec3_sqrt(vec3 v, vec3 dest);
 */

#ifndef cglm_vec3_ext_h
#define cglm_vec3_ext_h

#include "common.h"
#include "util.h"

/*!
 * @brief fill a vector with specified value
 *
 * @param[in]  val value
 * @param[out] d   dest
 */
CGLM_INLINE
void
glm_vec3_broadcast(float val, vec3 d) {
  d[0] = d[1] = d[2] = val;
}

/*!
 * @brief fill a vector with specified value
 *
 * @param[out] v   dest
 * @param[in]  val value
 */
CGLM_INLINE
void
glm_vec3_fill(vec3 v, float val) {
  v[0] = v[1] = v[2] = val;
}

/*!
 * @brief check if vector is equal to value (without epsilon)
 *
 * @param[in] v   vector
 * @param[in] val value
 */
CGLM_INLINE
bool
glm_vec3_eq(vec3 v, float val) {
  return v[0] == val && v[0] == v[1] && v[0] == v[2];
}

/*!
 * @brief check if vector is equal to value (with epsilon)
 *
 * @param[in] v   vector
 * @param[in] val value
 */
CGLM_INLINE
bool
glm_vec3_eq_eps(vec3 v, float val) {
  return fabsf(v[0] - val) <= GLM_FLT_EPSILON
         && fabsf(v[1] - val) <= GLM_FLT_EPSILON
         && fabsf(v[2] - val) <= GLM_FLT_EPSILON;
}

/*!
 * @brief check if vector members are equal (without epsilon)
 *
 * @param[in] v   vector
 */
CGLM_INLINE
bool
glm_vec3_eq_all(vec3 v) {
  return glm_vec3_eq_eps(v, v[0]);
}

/*!
 * @brief check if vector is equal to another (without epsilon)
 *
 * @param[in] a vector
 * @param[in] b vector
 */
CGLM_INLINE
bool
glm_vec3_eqv(vec3 a, vec3 b) {
  return a[0] == b[0]
         && a[1] == b[1]
         && a[2] == b[2];
}

/*!
 * @brief check if vector is equal to another (with epsilon)
 *
 * @param[in] a vector
 * @param[in] b vector
 */
CGLM_INLINE
bool
glm_vec3_eqv_eps(vec3 a, vec3 b) {
  return fabsf(a[0] - b[0]) <= GLM_FLT_EPSILON
         && fabsf(a[1] - b[1]) <= GLM_FLT_EPSILON
         && fabsf(a[2] - b[2]) <= GLM_FLT_EPSILON;
}

/*!
 * @brief max value of vector
 *
 * @param[in] v vector
 */
CGLM_INLINE
float
glm_vec3_max(vec3 v) {
  float max;

  max = v[0];
  if (v[1] > max)
    max = v[1];
  if (v[2] > max)
    max = v[2];

  return max;
}

/*!
 * @brief min value of vector
 *
 * @param[in] v vector
 */
CGLM_INLINE
float
glm_vec3_min(vec3 v) {
  float min;

  min = v[0];
  if (v[1] < min)
    min = v[1];
  if (v[2] < min)
    min = v[2];

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
glm_vec3_isnan(vec3 v) {
#ifndef CGLM_FAST_MATH
  return isnan(v[0]) || isnan(v[1]) || isnan(v[2]);
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
glm_vec3_isinf(vec3 v) {
#ifndef CGLM_FAST_MATH
  return isinf(v[0]) || isinf(v[1]) || isinf(v[2]);
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
glm_vec3_isvalid(vec3 v) {
  return !glm_vec3_isnan(v) && !glm_vec3_isinf(v);
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
glm_vec3_sign(vec3 v, vec3 dest) {
  dest[0] = glm_signf(v[0]);
  dest[1] = glm_signf(v[1]);
  dest[2] = glm_signf(v[2]);
}

/*!
 * @brief absolute value of each vector item
 *
 * @param[in]  v    vector
 * @param[out] dest destination vector
 */
CGLM_INLINE
void
glm_vec3_abs(vec3 v, vec3 dest) {
  dest[0] = fabsf(v[0]);
  dest[1] = fabsf(v[1]);
  dest[2] = fabsf(v[2]);
}

/*!
 * @brief fractional part of each vector item
 *
 * @param[in]  v    vector
 * @param[out] dest destination vector
 */
CGLM_INLINE
void
glm_vec3_fract(vec3 v, vec3 dest) {
  dest[0] = fminf(v[0] - floorf(v[0]), 0.999999940395355224609375f);
  dest[1] = fminf(v[1] - floorf(v[1]), 0.999999940395355224609375f);
  dest[2] = fminf(v[2] - floorf(v[2]), 0.999999940395355224609375f);
}

/*!
 * @brief floor of each vector item
 *
 * @param[in]  v    vector
 * @param[out] dest destination vector
 */
CGLM_INLINE
void
glm_vec3_floor(vec3 v, vec3 dest) {
  dest[0] = floorf(v[0]);
  dest[1] = floorf(v[1]);
  dest[2] = floorf(v[2]);
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
glm_vec3_mods(vec3 v, float s, vec3 dest) {
  dest[0] = fmodf(v[0], s);
  dest[1] = fmodf(v[1], s);
  dest[2] = fmodf(v[2], s);
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
glm_vec3_steps(float edge, vec3 x, vec3 dest) {
  dest[0] = glm_step(edge, x[0]);
  dest[1] = glm_step(edge, x[1]);
  dest[2] = glm_step(edge, x[2]);
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
glm_vec3_stepr(vec3 edge, float x, vec3 dest) {
  dest[0] = glm_step(edge[0], x);
  dest[1] = glm_step(edge[1], x);
  dest[2] = glm_step(edge[2], x);
}

/*!
 * @brief vector reduction by summation
 * @warning could overflow
 *
 * @param[in]  v    vector
 * @return     sum of all vector's elements
 */
CGLM_INLINE
float
glm_vec3_hadd(vec3 v) {
  return v[0] + v[1] + v[2];
}

/*!
 * @brief square root of each vector item
 *
 * @param[in]  v    vector
 * @param[out] dest destination vector
 */
CGLM_INLINE
void
glm_vec3_sqrt(vec3 v, vec3 dest) {
  dest[0] = sqrtf(v[0]);
  dest[1] = sqrtf(v[1]);
  dest[2] = sqrtf(v[2]);
}

#endif /* cglm_vec3_ext_h */
