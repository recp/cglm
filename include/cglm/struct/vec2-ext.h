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
   CGLM_DECL vec2s glms_vec2_fill(float val)
   CGLM_DECL bool  glms_vec2_eq(vec2s v, float val)
   CGLM_DECL bool  glms_vec2_eq_eps(vec2s v, float val)
   CGLM_DECL bool  glms_vec2_eq_all(vec2s v)
   CGLM_DECL bool  glms_vec2_eqv(vec2s a, vec2s b)
   CGLM_DECL bool  glms_vec2_eqv_eps(vec2s a, vec2s b)
   CGLM_DECL float glms_vec2_max(vec2s v)
   CGLM_DECL float glms_vec2_min(vec2s v)
   CGLM_DECL bool  glms_vec2_isnan(vec2s v)
   CGLM_DECL bool  glms_vec2_isinf(vec2s v)
   CGLM_DECL bool  glms_vec2_isvalid(vec2s v)
   CGLM_DECL vec2s glms_vec2_sign(vec2s v)
   CGLM_DECL vec2s glms_vec2_sqrt(vec2s v)
 */

#ifndef cglms_vec2s_ext_h
#define cglms_vec2s_ext_h

#include "../common.h"
#include "../types-struct.h"
#include "../util.h"
#include "../vec2-ext.h"

/*!
 * @brief fill a vector with specified value
 *
 * @param[in]  val  value
 * @returns         dest
 */
CGLM_DECL
vec2s
glms_vec2_fill(float val) CGLM_ENDD
#ifndef CGLM_LIB
{
  vec2s r;
  glm_vec2_fill(r.raw, val);
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
glms_vec2_eq(vec2s v, float val) CGLM_ENDD
#ifndef CGLM_LIB
{
  return glm_vec2_eq(v.raw, val);
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
glms_vec2_eq_eps(vec2s v, float val) CGLM_ENDD
#ifndef CGLM_LIB
{
  return glm_vec2_eq_eps(v.raw, val);
}
#endif

/*!
 * @brief check if vectors members are equal (without epsilon)
 *
 * @param[in] v   vector
 */
CGLM_DECL
bool
glms_vec2_eq_all(vec2s v) CGLM_ENDD
#ifndef CGLM_LIB
{
  return glm_vec2_eq_all(v.raw);
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
glms_vec2_eqv(vec2s a, vec2s b) CGLM_ENDD
#ifndef CGLM_LIB
{
  return glm_vec2_eqv(a.raw, b.raw);
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
glms_vec2_eqv_eps(vec2s a, vec2s b) CGLM_ENDD
#ifndef CGLM_LIB
{
  return glm_vec2_eqv_eps(a.raw, b.raw);
}
#endif

/*!
 * @brief max value of vector
 *
 * @param[in] v vector
 */
CGLM_DECL
float
glms_vec2_max(vec2s v) CGLM_ENDD
#ifndef CGLM_LIB
{
  return glm_vec2_max(v.raw);
}
#endif

/*!
 * @brief min value of vector
 *
 * @param[in] v vector
 */
CGLM_DECL
float
glms_vec2_min(vec2s v) CGLM_ENDD
#ifndef CGLM_LIB
{
  return glm_vec2_min(v.raw);
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
glms_vec2_isnan(vec2s v) CGLM_ENDD
#ifndef CGLM_LIB
{
  return glm_vec2_isnan(v.raw);
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
glms_vec2_isinf(vec2s v) CGLM_ENDD
#ifndef CGLM_LIB
{
  return glm_vec2_isinf(v.raw);
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
glms_vec2_isvalid(vec2s v) CGLM_ENDD
#ifndef CGLM_LIB
{
  return glm_vec2_isvalid(v.raw);
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
vec2s
glms_vec2_sign(vec2s v) CGLM_ENDD
#ifndef CGLM_LIB
{
  vec2s r;
  glm_vec2_sign(v.raw, r.raw);
  return r;
}
#endif

/*!
 * @brief square root of each vector item
 *
 * @param[in]  v    vector
 * @returns         destination vector
 */
CGLM_DECL
vec2s
glms_vec2_sqrt(vec2s v) CGLM_ENDD
#ifndef CGLM_LIB
{
  vec2s r;
  glm_vec2_sqrt(v.raw, r.raw);
  return r;
}
#endif

#endif /* cglms_vec2s_ext_h */
