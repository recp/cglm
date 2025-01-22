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
   CGLM_INLINE vec4s glms_vec4_broadcast(float val);
   CGLM_INLINE vec4s glms_vec4_fill(float val);
   CGLM_INLINE bool  glms_vec4_eq(vec4s v, float val);
   CGLM_INLINE bool  glms_vec4_eq_eps(vec4s v, float val);
   CGLM_INLINE bool  glms_vec4_eq_all(vec4s v);
   CGLM_INLINE bool  glms_vec4_eqv(vec4s a, vec4s b);
   CGLM_INLINE bool  glms_vec4_eqv_eps(vec4s a, vec4s b);
   CGLM_INLINE float glms_vec4_max(vec4s v);
   CGLM_INLINE float glms_vec4_min(vec4s v);
   CGLM_INLINE bool  glms_vec4_isnan(vec4s v);
   CGLM_INLINE bool  glms_vec4_isinf(vec4s v);
   CGLM_INLINE bool  glms_vec4_isvalid(vec4s v);
   CGLM_INLINE vec4s glms_vec4_sign(vec4s v);
   CGLM_INLINE vec4s glms_vec4_abs(vec4s v);
   CGLM_INLINE vec4s glms_vec4_fract(vec4s v);
   CGLM_INLINE float glms_vec4_floor(vec4s v);
   CGLM_INLINE float glms_vec4_mods(vec4s v, float s);
   CGLM_INLINE float glms_vec4_steps(float edge, vec4s v);
   CGLM_INLINE void  glms_vec4_stepr(vec4s edge, float v);
   CGLM_INLINE float glms_vec4_hadd(vec4s v);
   CGLM_INLINE vec4s glms_vec4_sqrt(vec4s v);
 */

#ifndef cglms_vec4s_ext_h
#define cglms_vec4s_ext_h

#include "../common.h"
#include "../types-struct.h"
#include "../util.h"
#include "../vec4-ext.h"

/* api definition */
#define glms_vec4_(NAME) CGLM_STRUCTAPI(vec4, NAME)

/*!
 * @brief fill a vector with specified value
 *
 * @param val value
 * @returns   dest
 */
CGLM_INLINE
vec4s
glms_vec4_(broadcast)(float val) {
  vec4s r;
  glm_vec4_broadcast(val, r.raw);
  return r;
}

/*!
 * @brief fill a vector with specified value
 *
 * @param val value
 * @returns   dest
 */
CGLM_INLINE
vec4s
glms_vec4_(fill)(float val) {
  vec4s r;
  glm_vec4_fill(r.raw, val);
  return r;
}

/*!
 * @brief check if vector is equal to value (without epsilon)
 *
 * @param v   vector
 * @param val value
 */
CGLM_INLINE
bool
glms_vec4_(eq)(vec4s v, float val) {
  return glm_vec4_eq(v.raw, val);
}

/*!
 * @brief check if vector is equal to value (with epsilon)
 *
 * @param v   vector
 * @param val value
 */
CGLM_INLINE
bool
glms_vec4_(eq_eps)(vec4s v, float val) {
  return glm_vec4_eq_eps(v.raw, val);
}

/*!
 * @brief check if vector members are equal (without epsilon)
 *
 * @param v   vector
 */
CGLM_INLINE
bool
glms_vec4_(eq_all)(vec4s v) {
  return glm_vec4_eq_all(v.raw);
}

/*!
 * @brief check if vector is equal to another (without epsilon)
 *
 * @param a vector
 * @param b vector
 */
CGLM_INLINE
bool
glms_vec4_(eqv)(vec4s a, vec4s b) {
  return glm_vec4_eqv(a.raw, b.raw);
}

/*!
 * @brief check if vector is equal to another (with epsilon)
 *
 * @param a vector
 * @param b vector
 */
CGLM_INLINE
bool
glms_vec4_(eqv_eps)(vec4s a, vec4s b) {
  return glm_vec4_eqv_eps(a.raw, b.raw);
}

/*!
 * @brief max value of vector
 *
 * @param v vector
 */
CGLM_INLINE
float
glms_vec4_(max)(vec4s v) {
  return glm_vec4_max(v.raw);
}

/*!
 * @brief min value of vector
 *
 * @param v vector
 */
CGLM_INLINE
float
glms_vec4_(min)(vec4s v) {
  return glm_vec4_min(v.raw);
}

/*!
 * @brief check if one of items is NaN (not a number)
 *        you should only use this in DEBUG mode or very critical asserts
 *
 * @param[in] v vector
 */
CGLM_INLINE
bool
glms_vec4_(isnan)(vec4s v) {
  return glm_vec4_isnan(v.raw);
}

/*!
 * @brief check if one of items is INFINITY
 *        you should only use this in DEBUG mode or very critical asserts
 *
 * @param[in] v vector
 */
CGLM_INLINE
bool
glms_vec4_(isinf)(vec4s v) {
  return glm_vec4_isinf(v.raw);
}

/*!
 * @brief check if all items are valid number
 *        you should only use this in DEBUG mode or very critical asserts
 *
 * @param[in] v vector
 */
CGLM_INLINE
bool
glms_vec4_(isvalid)(vec4s v) {
  return glm_vec4_isvalid(v.raw);
}

/*!
 * @brief get sign of 32 bit float as +1, -1, 0
 *
 * Important: It returns 0 for zero/NaN input
 *
 * @param   v   vector
 * @returns     sign vector
 */
CGLM_INLINE
vec4s
glms_vec4_(sign)(vec4s v) {
  vec4s r;
  glm_vec4_sign(v.raw, r.raw);
  return r;
}

/*!
 * @brief absolute value of each vector item
 *
 * @param[in]  v    vector
 * @returns         destination vector
 */
CGLM_INLINE
vec4s
glms_vec4_(abs)(vec4s v) {
  vec4s r;
  glm_vec4_abs(v.raw, r.raw);
  return r;
}

/*!
 * @brief fractional part of each vector item
 *
 * @param[in]  v    vector
 * @returns          dest destination vector
 */
CGLM_INLINE
vec4s
glms_vec4_(fract)(vec4s v) {
  vec4s r;
  glm_vec4_fract(v.raw, r.raw);
  return r;
}

/*!
 * @brief floor of each vector item
 *
 * @param[in]  v    vector
 * @returns          dest destination vector
 */
CGLM_INLINE
vec4s
glms_vec4_(floor)(vec4s v) {
  vec4s r;
  glm_vec4_floor(v.raw, r.raw);
  return r;
}

/*!
 * @brief mod of each vector item by scalar
 *
 * @param[in]  v    vector
 * @param[in]  s    scalar
 * @returns         destination vector
 */
CGLM_INLINE
vec4s
glms_vec4_(mods)(vec4s v, float s) {
  vec4s r;
  glm_vec4_mods(v.raw, s, r.raw);
  return r;
}

/*!
 * @brief threshold each vector item with scalar
 *        condition is: (x[i] < edge) ? 0.0 : 1.0
 *
 * @param[in]   edge   threshold
 * @param[in]   x      vector to test against threshold
 * @returns            destination
 */
CGLM_INLINE
vec4s
glms_vec4_(steps)(float edge, vec4s x) {
  vec4s r;
  glm_vec4_steps(edge, x.raw, r.raw);
  return r;
}

/*!
 * @brief threshold a value with *vector* as the threshold
 *        condition is: (x < edge[i]) ? 0.0 : 1.0
 *
 * @param[in]   edge   threshold vector
 * @param[in]   x      value to test against threshold
 * @returns            destination
 */
CGLM_INLINE
vec4s
glms_vec4_(stepr)(vec4s edge, float x) {
  vec4s r;
  glm_vec4_stepr(edge.raw, x, r.raw);
  return r;
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
glms_vec4_(hadd)(vec4s v) {
  return glm_vec4_hadd(v.raw);
}

/*!
 * @brief square root of each vector item
 *
 * @param[in]  v    vector
 * @returns         destination vector
 */
CGLM_INLINE
vec4s
glms_vec4_(sqrt)(vec4s v) {
  vec4s r;
  glm_vec4_sqrt(v.raw, r.raw);
  return r;
}

#endif /* cglms_vec4s_ext_h */
