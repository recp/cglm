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
  return fabsf(v[0] - val) <= FLT_EPSILON
         && fabsf(v[1] - val) <= FLT_EPSILON
         && fabsf(v[2] - val) <= FLT_EPSILON;
}

/*!
 * @brief check if vectors members are equal (without epsilon)
 *
 * @param[in] v   vector
 */
CGLM_INLINE
bool
glm_vec3_eq_all(vec3 v) {
  return v[0] == v[1] && v[0] == v[2];
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
  return fabsf(a[0] - b[0]) <= FLT_EPSILON
         && fabsf(a[1] - b[1]) <= FLT_EPSILON
         && fabsf(a[2] - b[2]) <= FLT_EPSILON;
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
 * @brief check if all items are NaN (not a number)
 *        you should only use this in DEBUG mode or very critical asserts
 *
 * @param[in] v vector
 */
CGLM_INLINE
bool
glm_vec3_isnan(vec3 v) {
  return isnan(v[0]) || isnan(v[1]) || isnan(v[2]);
}

/*!
 * @brief check if all items are INFINITY
 *        you should only use this in DEBUG mode or very critical asserts
 *
 * @param[in] v vector
 */
CGLM_INLINE
bool
glm_vec3_isinf(vec3 v) {
  return isinf(v[0]) || isinf(v[1]) || isinf(v[2]);
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
