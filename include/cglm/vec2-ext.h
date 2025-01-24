/*
 * Copyright (c), Recep Aslantas.
 *
 * MIT License (MIT), http://opensource.org/licenses/MIT
 * Full license can be found in the LICENSE file
 */

/*
 Functions:
   CGLM_INLINE void  glm_vec2_fill(vec2 v, float val)
   CGLM_INLINE bool  glm_vec2_eq(vec2 v, float val);
   CGLM_INLINE bool  glm_vec2_eq_eps(vec2 v, float val);
   CGLM_INLINE bool  glm_vec2_eq_all(vec2 v);
   CGLM_INLINE bool  glm_vec2_eqv(vec2 a, vec2 b);
   CGLM_INLINE bool  glm_vec2_eqv_eps(vec2 a, vec2 b);
   CGLM_INLINE float glm_vec2_max(vec2 v);
   CGLM_INLINE float glm_vec2_min(vec2 v);
   CGLM_INLINE bool  glm_vec2_isnan(vec2 v);
   CGLM_INLINE bool  glm_vec2_isinf(vec2 v);
   CGLM_INLINE bool  glm_vec2_isvalid(vec2 v);
   CGLM_INLINE void  glm_vec2_sign(vec2 v, vec2 dest);
   CGLM_INLINE void  glm_vec2_abs(vec2 v, vec2 dest);
   CGLM_INLINE void  glm_vec2_fract(vec2 v, vec2 dest);
   CGLM_INLINE void  glm_vec2_floor(vec2 v, vec2 dest);
   CGLM_INLINE float glm_vec2_mods(vec2 v, float s, vec2 dest);
   CGLM_INLINE float glm_vec2_steps(float edge, vec2 v, vec2 dest);
   CGLM_INLINE void  glm_vec2_stepr(vec2 edge, float v, vec2 dest);
   CGLM_INLINE void  glm_vec2_sqrt(vec2 v, vec2 dest);
   CGLM_INLINE void  glm_vec2_complex_mul(vec2 a, vec2 b, vec2 dest)
   CGLM_INLINE void  glm_vec2_complex_div(vec2 a, vec2 b, vec2 dest)
   CGLM_INLINE void  glm_vec2_complex_conjugate(vec2 a, vec2 dest)
 */

#ifndef cglm_vec2_ext_h
#define cglm_vec2_ext_h

#include "common.h"
#include "util.h"

/*!
 * @brief fill a vector with specified value
 *
 * @param[out] v   dest
 * @param[in]  val value
 */
CGLM_INLINE
void
glm_vec2_fill(vec2 v, float val) {
  v[0] = v[1] = val;
}

/*!
 * @brief check if vector is equal to value (without epsilon)
 *
 * @param[in] v   vector
 * @param[in] val value
 */
CGLM_INLINE
bool
glm_vec2_eq(vec2 v, float val) {
  return v[0] == val && v[0] == v[1];
}

/*!
 * @brief check if vector is equal to value (with epsilon)
 *
 * @param[in] v   vector
 * @param[in] val value
 */
CGLM_INLINE
bool
glm_vec2_eq_eps(vec2 v, float val) {
  return fabsf(v[0] - val) <= GLM_FLT_EPSILON
         && fabsf(v[1] - val) <= GLM_FLT_EPSILON;
}

/*!
 * @brief check if vector members are equal (without epsilon)
 *
 * @param[in] v   vector
 */
CGLM_INLINE
bool
glm_vec2_eq_all(vec2 v) {
  return glm_vec2_eq_eps(v, v[0]);
}

/*!
 * @brief check if vector is equal to another (without epsilon)
 *
 * @param[in] a vector
 * @param[in] b vector
 */
CGLM_INLINE
bool
glm_vec2_eqv(vec2 a, vec2 b) {
  return a[0] == b[0] && a[1] == b[1];
}

/*!
 * @brief check if vector is equal to another (with epsilon)
 *
 * @param[in] a vector
 * @param[in] b vector
 */
CGLM_INLINE
bool
glm_vec2_eqv_eps(vec2 a, vec2 b) {
  return fabsf(a[0] - b[0]) <= GLM_FLT_EPSILON
         && fabsf(a[1] - b[1]) <= GLM_FLT_EPSILON;
}

/*!
 * @brief max value of vector
 *
 * @param[in] v vector
 */
CGLM_INLINE
float
glm_vec2_max(vec2 v) {
  return glm_max(v[0], v[1]);
}

/*!
 * @brief min value of vector
 *
 * @param[in] v vector
 */
CGLM_INLINE
float
glm_vec2_min(vec2 v) {
  return glm_min(v[0], v[1]);
}

/*!
 * @brief check if one of items is NaN (not a number)
 *        you should only use this in DEBUG mode or very critical asserts
 *
 * @param[in] v vector
 */
CGLM_INLINE
bool
glm_vec2_isnan(vec2 v) {
#ifndef CGLM_FAST_MATH
  return isnan(v[0]) || isnan(v[1]);
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
glm_vec2_isinf(vec2 v) {
#ifndef CGLM_FAST_MATH
  return isinf(v[0]) || isinf(v[1]);
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
glm_vec2_isvalid(vec2 v) {
  return !glm_vec2_isnan(v) && !glm_vec2_isinf(v);
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
glm_vec2_sign(vec2 v, vec2 dest) {
  dest[0] = glm_signf(v[0]);
  dest[1] = glm_signf(v[1]);
}

/*!
 * @brief absolute value of v
 *
 * @param[in]	v	vector
 * @param[out]	dest	destination
 */
CGLM_INLINE
void
glm_vec2_abs(vec2 v, vec2 dest) {
  dest[0] = fabsf(v[0]);
  dest[1] = fabsf(v[1]);
}

/*!
 * @brief fractional part of each vector item
 *
 * @param[in]  v    vector
 * @param[out] dest destination vector
 */
CGLM_INLINE
void
glm_vec2_fract(vec2 v, vec2 dest) {
  dest[0] = fminf(v[0] - floorf(v[0]), 0.999999940395355224609375f);
  dest[1] = fminf(v[1] - floorf(v[1]), 0.999999940395355224609375f);
}

/*!
 * @brief floor of each vector item
 *
 * @param[in]  v    vector
 * @param[out] dest destination vector
 */
CGLM_INLINE
void
glm_vec2_floor(vec2 v, vec2 dest) {
  dest[0] = floorf(v[0]);
  dest[1] = floorf(v[1]);
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
glm_vec2_mods(vec2 v, float s, vec2 dest) {
  dest[0] = fmodf(v[0], s);
  dest[1] = fmodf(v[1], s);
}

/*!
 * @brief square root of each vector item
 *
 * @param[in]  v    vector
 * @param[out] dest destination vector
 */
CGLM_INLINE
void
glm_vec2_sqrt(vec2 v, vec2 dest) {
  dest[0] = sqrtf(v[0]);
  dest[1] = sqrtf(v[1]);
}

/*!
 * @brief treat vectors as complex numbers and multiply them as such.
 *
 * @param[in]  a    left number
 * @param[in]  b    right number
 * @param[out] dest destination number
 */
CGLM_INLINE
void
glm_vec2_complex_mul(vec2 a, vec2 b, vec2 dest) {
  float tr, ti;
  tr = a[0] * b[0] - a[1] * b[1];
  ti = a[0] * b[1] + a[1] * b[0];
  dest[0] = tr;
  dest[1] = ti;
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
glm_vec2_steps(float edge, vec2 x, vec2 dest) {
  dest[0] = glm_step(edge, x[0]);
  dest[1] = glm_step(edge, x[1]);
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
glm_vec2_stepr(vec2 edge, float x, vec2 dest) {
  dest[0] = glm_step(edge[0], x);
  dest[1] = glm_step(edge[1], x);
}

/*!
 * @brief treat vectors as complex numbers and divide them as such.
 *
 * @param[in]  a    left number (numerator)
 * @param[in]  b    right number (denominator)
 * @param[out] dest destination number
 */
CGLM_INLINE
void
glm_vec2_complex_div(vec2 a, vec2 b, vec2 dest) {
  float tr, ti;
  float const ibnorm2 = 1.0f / (b[0] * b[0] + b[1] * b[1]);
  tr = ibnorm2 * (a[0] * b[0] + a[1] * b[1]);
  ti = ibnorm2 * (a[1] * b[0] - a[0] * b[1]);
  dest[0] = tr;
  dest[1] = ti;
}

/*!
 * @brief treat the vector as a complex number and conjugate it as such.
 *
 * @param[in]  a    the number
 * @param[out] dest destination number
 */
CGLM_INLINE
void
glm_vec2_complex_conjugate(vec2 a, vec2 dest) {
  dest[0] =  a[0];
  dest[1] = -a[1];
}

#endif /* cglm_vec2_ext_h */
