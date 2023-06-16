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
   CGLM_INLINE vec2s glms_vec2_fill(float val)
   CGLM_INLINE bool  glms_vec2_eq(vec2s v, float val)
   CGLM_INLINE bool  glms_vec2_eq_eps(vec2s v, float val)
   CGLM_INLINE bool  glms_vec2_eq_all(vec2s v)
   CGLM_INLINE bool  glms_vec2_eqv(vec2s a, vec2s b)
   CGLM_INLINE bool  glms_vec2_eqv_eps(vec2s a, vec2s b)
   CGLM_INLINE float glms_vec2_max(vec2s v)
   CGLM_INLINE float glms_vec2_min(vec2s v)
   CGLM_INLINE bool  glms_vec2_isnan(vec2s v)
   CGLM_INLINE bool  glms_vec2_isinf(vec2s v)
   CGLM_INLINE bool  glms_vec2_isvalid(vec2s v)
   CGLM_INLINE vec2s glms_vec2_sign(vec2s v)
   CGLM_INLINE vec2s glms_vec2_sqrt(vec2s v)
 */

#ifndef cglms_vec2s_ext_h
#define cglms_vec2s_ext_h

#include "../common.h"
#include "../types-struct.h"
#include "../util.h"
#include "../vec2-ext.h"

/* api definition */
#define glms_vec2_(NAME) CGLM_STRUCTAPI(vec2, NAME)

/*!
 * @brief fill a vector with specified value
 *
 * @param[in]  val  value
 * @returns         dest
 */
CGLM_INLINE
vec2s
glms_vec2_(fill)(float val) {
  vec2s r;
  glm_vec2_fill(r.raw, val);
  return r;
}

/*!
 * @brief check if vector is equal to value (without epsilon)
 *
 * @param[in] v   vector
 * @param[in] val value
 */
CGLM_INLINE
bool
glms_vec2_(eq)(vec2s v, float val) {
  return glm_vec2_eq(v.raw, val);
}

/*!
 * @brief check if vector is equal to value (with epsilon)
 *
 * @param[in] v   vector
 * @param[in] val value
 */
CGLM_INLINE
bool
glms_vec2_(eq_eps)(vec2s v, float val) {
  return glm_vec2_eq_eps(v.raw, val);
}

/*!
 * @brief check if vector members are equal (without epsilon)
 *
 * @param[in] v   vector
 */
CGLM_INLINE
bool
glms_vec2_(eq_all)(vec2s v) {
  return glm_vec2_eq_all(v.raw);
}

/*!
 * @brief check if vector is equal to another (without epsilon)
 *
 * @param[in] a vector
 * @param[in] b vector
 */
CGLM_INLINE
bool
glms_vec2_(eqv)(vec2s a, vec2s b) {
  return glm_vec2_eqv(a.raw, b.raw);
}

/*!
 * @brief check if vector is equal to another (with epsilon)
 *
 * @param[in] a vector
 * @param[in] b vector
 */
CGLM_INLINE
bool
glms_vec2_(eqv_eps)(vec2s a, vec2s b) {
  return glm_vec2_eqv_eps(a.raw, b.raw);
}

/*!
 * @brief max value of vector
 *
 * @param[in] v vector
 */
CGLM_INLINE
float
glms_vec2_(max)(vec2s v) {
  return glm_vec2_max(v.raw);
}

/*!
 * @brief min value of vector
 *
 * @param[in] v vector
 */
CGLM_INLINE
float
glms_vec2_min(vec2s v) {
  return glm_vec2_min(v.raw);
}

/*!
 * @brief check if all items are NaN (not a number)
 *        you should only use this in DEBUG mode or very critical asserts
 *
 * @param[in] v vector
 */
CGLM_INLINE
bool
glms_vec2_(isnan)(vec2s v) {
  return glm_vec2_isnan(v.raw);
}

/*!
 * @brief check if all items are INFINITY
 *        you should only use this in DEBUG mode or very critical asserts
 *
 * @param[in] v vector
 */
CGLM_INLINE
bool
glms_vec2_(isinf)(vec2s v) {
  return glm_vec2_isinf(v.raw);
}

/*!
 * @brief check if all items are valid number
 *        you should only use this in DEBUG mode or very critical asserts
 *
 * @param[in] v vector
 */
CGLM_INLINE
bool
glms_vec2_isvalid(vec2s v) {
  return glm_vec2_isvalid(v.raw);
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
vec2s
glms_vec2_(sign)(vec2s v) {
  vec2s r;
  glm_vec2_sign(v.raw, r.raw);
  return r;
}

/*!
 * @brief square root of each vector item
 *
 * @param[in]  v    vector
 * @returns         destination vector
 */
CGLM_INLINE
vec2s
glms_vec2_(sqrt)(vec2s v) {
  vec2s r;
  glm_vec2_sqrt(v.raw, r.raw);
  return r;
}

/*!
 * @brief treat vectors as complex numbers and multiply them as such.
 *
 * @param[in]  a    left number
 * @param[in]  b    right number
 * @param[out] dest destination number
 */
CGLM_INLINE
vec2s
glms_vec2_(complex_mul)(vec2s a, vec2s b, vec2s dest) {
  glm_vec2_complex_mul(a.raw, b.raw, dest.raw);
  return dest;
}

/*!
 * @brief treat vectors as complex numbers and divide them as such.
 *
 * @param[in]  a    left number (numerator)
 * @param[in]  b    right number (denominator)
 * @param[out] dest destination number
 */
CGLM_INLINE
vec2s
glms_vec2_(complex_div)(vec2s a, vec2s b, vec2s dest) {
  glm_vec2_complex_div(a.raw, b.raw, dest.raw);
  return dest;
}

/*!
 * @brief treat the vector as a complex number and conjugate it as such.
 *
 * @param[in]  a    the number
 * @param[out] dest destination number
 */
CGLM_INLINE
vec2s
glms_vec2_(complex_conjugate)(vec2s a, vec2s dest) {
  glm_vec2_complex_conjugate(a.raw, dest.raw);
  return dest;
}

#endif /* cglms_vec2s_ext_h */
