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
   CGLM_DECL vec3s glms_vec3_broadcast(float val);
   CGLM_DECL vec3s glms_vec3_fill(float val);
   CGLM_DECL bool  glms_vec3_eq(vec3s v, float val);
   CGLM_DECL bool  glms_vec3_eq_eps(vec3s v, float val);
   CGLM_DECL bool  glms_vec3_eq_all(vec3s v);
   CGLM_DECL bool  glms_vec3_eqv(vec3s a, vec3s b);
   CGLM_DECL bool  glms_vec3_eqv_eps(vec3s a, vec3s b);
   CGLM_DECL float glms_vec3_max(vec3s v);
   CGLM_DECL float glms_vec3_min(vec3s v);
   CGLM_DECL bool  glms_vec3_isnan(vec3s v);
   CGLM_DECL bool  glms_vec3_isinf(vec3s v);
   CGLM_DECL bool  glms_vec3_isvalid(vec3s v);
   CGLM_DECL vec3s glms_vec3_sign(vec3s v);
   CGLM_DECL vec3s glms_vec3_abs(vec3s v);
   CGLM_DECL vec3s glms_vec3_fract(vec3s v);
   CGLM_DECL float glms_vec3_hadd(vec3s v);
   CGLM_DECL vec3s glms_vec3_sqrt(vec3s v);
 */

#ifndef cglms_vec3s_ext_h
#define cglms_vec3s_ext_h

#include "../common.h"
#include "../types-struct.h"
#include "../util.h"
#include "../vec3-ext.h"

/*!
 * @brief fill a vector with specified value
 *
 * @param[in]  val  value
 * @returns         dest
 */
CGLM_DECL
vec3s
glms_vec3_broadcast(float val) CGLM_ENDD
#ifndef CGLM_LIB
{
  vec3s r;
  glm_vec3_broadcast(val, r.raw);
  return r;
}
#endif

/*!
 * @brief fill a vector with specified value
 *
 * @param[in]  val  value
 * @returns         dest
 */
CGLM_DECL
vec3s
glms_vec3_fill(float val) CGLM_ENDD
#ifndef CGLM_LIB
{
  vec3s r;
  glm_vec3_fill(r.raw, val);
  return r;
}
#endif

/*!
 * @brief check if vector is equal to value (without epsilon)
 *
 * @param[in] v   vector
 * @param[in] val value
 */
CGLM_DECL
bool
glms_vec3_eq(vec3s v, float val) CGLM_ENDD
#ifndef CGLM_LIB
{
  return glm_vec3_eq(v.raw, val);
}
#endif

/*!
 * @brief check if vector is equal to value (with epsilon)
 *
 * @param[in] v   vector
 * @param[in] val value
 */
CGLM_DECL
bool
glms_vec3_eq_eps(vec3s v, float val) CGLM_ENDD
#ifndef CGLM_LIB
{
  return glm_vec3_eq_eps(v.raw, val);
}
#endif

/*!
 * @brief check if vectors members are equal (without epsilon)
 *
 * @param[in] v   vector
 */
CGLM_DECL
bool
glms_vec3_eq_all(vec3s v) CGLM_ENDD
#ifndef CGLM_LIB
{
  return glm_vec3_eq_all(v.raw);
}
#endif

/*!
 * @brief check if vector is equal to another (without epsilon)
 *
 * @param[in] a vector
 * @param[in] b vector
 */
CGLM_DECL
bool
glms_vec3_eqv(vec3s a, vec3s b) CGLM_ENDD
#ifndef CGLM_LIB
{
  return glm_vec3_eqv(a.raw, b.raw);
}
#endif

/*!
 * @brief check if vector is equal to another (with epsilon)
 *
 * @param[in] a vector
 * @param[in] b vector
 */
CGLM_DECL
bool
glms_vec3_eqv_eps(vec3s a, vec3s b) CGLM_ENDD
#ifndef CGLM_LIB
{
  return glm_vec3_eqv_eps(a.raw, b.raw);
}
#endif

/*!
 * @brief max value of vector
 *
 * @param[in] v vector
 */
CGLM_DECL
float
glms_vec3_max(vec3s v) CGLM_ENDD
#ifndef CGLM_LIB
{
  return glm_vec3_max(v.raw);
}
#endif

/*!
 * @brief min value of vector
 *
 * @param[in] v vector
 */
CGLM_DECL
float
glms_vec3_min(vec3s v) CGLM_ENDD
#ifndef CGLM_LIB
{
  return glm_vec3_min(v.raw);
}
#endif

/*!
 * @brief check if all items are NaN (not a number)
 *        you should only use this in DEBUG mode or very critical asserts
 *
 * @param[in] v vector
 */
CGLM_DECL
bool
glms_vec3_isnan(vec3s v) CGLM_ENDD
#ifndef CGLM_LIB
{
  return glm_vec3_isnan(v.raw);
}
#endif

/*!
 * @brief check if all items are INFINITY
 *        you should only use this in DEBUG mode or very critical asserts
 *
 * @param[in] v vector
 */
CGLM_DECL
bool
glms_vec3_isinf(vec3s v) CGLM_ENDD
#ifndef CGLM_LIB
{
  return glm_vec3_isinf(v.raw);
}
#endif

/*!
 * @brief check if all items are valid number
 *        you should only use this in DEBUG mode or very critical asserts
 *
 * @param[in] v vector
 */
CGLM_DECL
bool
glms_vec3_isvalid(vec3s v) CGLM_ENDD
#ifndef CGLM_LIB
{
  return glm_vec3_isvalid(v.raw);
}
#endif

/*!
 * @brief get sign of 32 bit float as +1, -1, 0
 *
 * Important: It returns 0 for zero/NaN input
 *
 * @param   v   vector
 * @returns     sign vector
 */
CGLM_DECL
vec3s
glms_vec3_sign(vec3s v) CGLM_ENDD
#ifndef CGLM_LIB
{
  vec3s r;
  glm_vec3_sign(v.raw, r.raw);
  return r;
}
#endif

/*!
 * @brief absolute value of each vector item
 *
 * @param[in]  v    vector
 * @return          destination vector
 */
CGLM_DECL
vec3s
glms_vec3_abs(vec3s v) CGLM_ENDD
#ifndef CGLM_LIB
{
  vec3s r;
  glm_vec3_abs(v.raw, r.raw);
  return r;
}
#endif

/*!
 * @brief fractional part of each vector item
 *
 * @param[in]  v    vector
 * @return          dest destination vector
 */
CGLM_DECL
vec3s
glms_vec3_fract(vec3s v) CGLM_ENDD
#ifndef CGLM_LIB
{
  vec3s r;
  glm_vec3_fract(v.raw, r.raw);
  return r;
}
#endif

/*!
 * @brief vector reduction by summation
 * @warning could overflow
 *
 * @param[in]  v    vector
 * @return     sum of all vector's elements
 */
CGLM_DECL
float
glms_vec3_hadd(vec3s v) CGLM_ENDD
#ifndef CGLM_LIB
{
  return glm_vec3_hadd(v.raw);
}
#endif

/*!
 * @brief square root of each vector item
 *
 * @param[in]  v    vector
 * @returns         destination vector
 */
CGLM_DECL
vec3s
glms_vec3_sqrt(vec3s v) CGLM_ENDD
#ifndef CGLM_LIB
{
  vec3s r;
  glm_vec3_sqrt(v.raw, r.raw);
  return r;
}
#endif

#endif /* cglms_vec3s_ext_h */
