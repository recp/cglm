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
   CGLM_DECL vec4s glms_vec4_broadcast(float val);
   CGLM_DECL vec4s glms_vec4_fill(float val);
   CGLM_DECL bool  glms_vec4_eq(vec4s v, float val);
   CGLM_DECL bool  glms_vec4_eq_eps(vec4s v, float val);
   CGLM_DECL bool  glms_vec4_eq_all(vec4s v);
   CGLM_DECL bool  glms_vec4_eqv(vec4s a, vec4s b);
   CGLM_DECL bool  glms_vec4_eqv_eps(vec4s a, vec4s b);
   CGLM_DECL float glms_vec4_max(vec4s v);
   CGLM_DECL float glms_vec4_min(vec4s v);
   CGLM_DECL bool  glms_vec4_isnan(vec4s v);
   CGLM_DECL bool  glms_vec4_isinf(vec4s v);
   CGLM_DECL bool  glms_vec4_isvalid(vec4s v);
   CGLM_DECL vec4s glms_vec4_sign(vec4s v);
   CGLM_DECL vec4s glms_vec4_abs(vec4s v);
   CGLM_DECL vec4s glms_vec4_fract(vec4s v);
   CGLM_DECL float glms_vec4_hadd(vec4s v);
   CGLM_DECL vec4s glms_vec4_sqrt(vec4s v);
 */

#ifndef cglms_vec4s_ext_h
#define cglms_vec4s_ext_h

#include "../common.h"
#include "../types-struct.h"
#include "../util.h"
#include "../vec4-ext.h"

/*!
 * @brief fill a vector with specified value
 *
 * @param val value
 * @returns   dest
 */
CGLM_DECL
vec4s
glms_vec4_broadcast(float val) CGLM_ENDD
#ifndef CGLM_LIB
{
  vec4s r;
  glm_vec4_broadcast(val, r.raw);
  return r;
}
#endif

/*!
 * @brief fill a vector with specified value
 *
 * @param val value
 * @returns   dest
 */
CGLM_DECL
vec4s
glms_vec4_fill(float val) CGLM_ENDD
#ifndef CGLM_LIB
{
  vec4s r;
  glm_vec4_fill(r.raw, val);
  return r;
}
#endif

/*!
 * @brief check if vector is equal to value (without epsilon)
 *
 * @param v   vector
 * @param val value
 */
CGLM_DECL
bool
glms_vec4_eq(vec4s v, float val) CGLM_ENDD
#ifndef CGLM_LIB
{
  return glm_vec4_eq(v.raw, val);
}
#endif

/*!
 * @brief check if vector is equal to value (with epsilon)
 *
 * @param v   vector
 * @param val value
 */
CGLM_DECL
bool
glms_vec4_eq_eps(vec4s v, float val) CGLM_ENDD
#ifndef CGLM_LIB
{
  return glm_vec4_eq_eps(v.raw, val);
}
#endif

/*!
 * @brief check if vectors members are equal (without epsilon)
 *
 * @param v   vector
 */
CGLM_DECL
bool
glms_vec4_eq_all(vec4s v) CGLM_ENDD
#ifndef CGLM_LIB
{
  return glm_vec4_eq_all(v.raw);
}
#endif

/*!
 * @brief check if vector is equal to another (without epsilon)
 *
 * @param a vector
 * @param b vector
 */
CGLM_DECL
bool
glms_vec4_eqv(vec4s a, vec4s b) CGLM_ENDD
#ifndef CGLM_LIB
{
  return glm_vec4_eqv(a.raw, b.raw);
}
#endif

/*!
 * @brief check if vector is equal to another (with epsilon)
 *
 * @param a vector
 * @param b vector
 */
CGLM_DECL
bool
glms_vec4_eqv_eps(vec4s a, vec4s b) CGLM_ENDD
#ifndef CGLM_LIB
{
  return glm_vec4_eqv_eps(a.raw, b.raw);
}
#endif

/*!
 * @brief max value of vector
 *
 * @param v vector
 */
CGLM_DECL
float
glms_vec4_max(vec4s v) CGLM_ENDD
#ifndef CGLM_LIB
{
  return glm_vec4_max(v.raw);
}
#endif

/*!
 * @brief min value of vector
 *
 * @param v vector
 */
CGLM_DECL
float
glms_vec4_min(vec4s v) CGLM_ENDD
#ifndef CGLM_LIB
{
  return glm_vec4_min(v.raw);
}
#endif

/*!
 * @brief check if one of items is NaN (not a number)
 *        you should only use this in DEBUG mode or very critical asserts
 *
 * @param[in] v vector
 */
CGLM_DECL
bool
glms_vec4_isnan(vec4s v) CGLM_ENDD
#ifndef CGLM_LIB
{
  return glm_vec4_isnan(v.raw);
}
#endif

/*!
 * @brief check if one of items is INFINITY
 *        you should only use this in DEBUG mode or very critical asserts
 *
 * @param[in] v vector
 */
CGLM_DECL
bool
glms_vec4_isinf(vec4s v) CGLM_ENDD
#ifndef CGLM_LIB
{
  return glm_vec4_isinf(v.raw);
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
glms_vec4_isvalid(vec4s v) CGLM_ENDD
#ifndef CGLM_LIB
{
  return glm_vec4_isvalid(v.raw);
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
vec4s
glms_vec4_sign(vec4s v) CGLM_ENDD
#ifndef CGLM_LIB
{
  vec4s r;
  glm_vec4_sign(v.raw, r.raw);
  return r;
}
#endif

/*!
 * @brief absolute value of each vector item
 *
 * @param[in]  v    vector
 * @returns         destination vector
 */
CGLM_DECL
vec4s
glms_vec4_abs(vec4s v) CGLM_ENDD
#ifndef CGLM_LIB
{
  vec4s r;
  glm_vec4_abs(v.raw, r.raw);
  return r;
}
#endif

/*!
 * @brief fractional part of each vector item
 *
 * @param[in]  v    vector
 * @returns          dest destination vector
 */
CGLM_DECL
vec4s
glms_vec4_fract(vec4s v) CGLM_ENDD
#ifndef CGLM_LIB
{
  vec4s r;
  glm_vec4_fract(v.raw, r.raw);
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
glms_vec4_hadd(vec4s v) CGLM_ENDD
#ifndef CGLM_LIB
{
  return glm_vec4_hadd(v.raw);
}
#endif

/*!
 * @brief square root of each vector item
 *
 * @param[in]  v    vector
 * @returns         destination vector
 */
CGLM_DECL
vec4s
glms_vec4_sqrt(vec4s v) CGLM_ENDD
#ifndef CGLM_LIB
{
  vec4s r;
  glm_vec4_sqrt(v.raw, r.raw);
  return r;
}
#endif

#endif /* cglms_vec4s_ext_h */
