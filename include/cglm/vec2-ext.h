/*
 * Copyright (c), Recep Aslantas.
 *
 * MIT License (MIT), http://opensource.org/licenses/MIT
 * Full license can be found in the LICENSE file
 */

/*
 Functions:
   CGLM_DECL void  glm_vec2_fill(vec2 v, float val)
   CGLM_DECL bool  glm_vec2_eq(vec2 v, float val);
   CGLM_DECL bool  glm_vec2_eq_eps(vec2 v, float val);
   CGLM_DECL bool  glm_vec2_eq_all(vec2 v);
   CGLM_DECL bool  glm_vec2_eqv(vec2 a, vec2 b);
   CGLM_DECL bool  glm_vec2_eqv_eps(vec2 a, vec2 b);
   CGLM_DECL float glm_vec2_max(vec2 v);
   CGLM_DECL float glm_vec2_min(vec2 v);
   CGLM_DECL bool  glm_vec2_isnan(vec2 v);
   CGLM_DECL bool  glm_vec2_isinf(vec2 v);
   CGLM_DECL bool  glm_vec2_isvalid(vec2 v);
   CGLM_DECL void  glm_vec2_sign(vec2 v, vec2 dest);
   CGLM_DECL void  glm_vec2_sqrt(vec2 v, vec2 dest);
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
CGLM_DECL
void
glm_vec2_fill(vec2 v, float val) CGLM_ENDD
#ifndef CGLM_LIB
{
  v[0] = v[1] = val;
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
glm_vec2_eq(vec2 v, float val) CGLM_ENDD
#ifndef CGLM_LIB
{
  return v[0] == val && v[0] == v[1];
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
glm_vec2_eq_eps(vec2 v, float val) CGLM_ENDD
#ifndef CGLM_LIB
{
  return fabsf(v[0] - val) <= FLT_EPSILON
         && fabsf(v[1] - val) <= FLT_EPSILON;
}
#endif

/*!
 * @brief check if vectors members are equal (without epsilon)
 *
 * @param[in] v   vector
 */
CGLM_DECL
bool
glm_vec2_eq_all(vec2 v) CGLM_ENDD
#ifndef CGLM_LIB
{
  return v[0] == v[1];
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
glm_vec2_eqv(vec2 a, vec2 b) CGLM_ENDD
#ifndef CGLM_LIB
{
  return a[0] == b[0] && a[1] == b[1];
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
glm_vec2_eqv_eps(vec2 a, vec2 b) CGLM_ENDD
#ifndef CGLM_LIB
{
  return fabsf(a[0] - b[0]) <= FLT_EPSILON
         && fabsf(a[1] - b[1]) <= FLT_EPSILON;
}
#endif

/*!
 * @brief max value of vector
 *
 * @param[in] v vector
 */
CGLM_DECL
float
glm_vec2_max(vec2 v) CGLM_ENDD
#ifndef CGLM_LIB
{
  return glm_max(v[0], v[1]);
}
#endif

/*!
 * @brief min value of vector
 *
 * @param[in] v vector
 */
CGLM_DECL
float
glm_vec2_min(vec2 v) CGLM_ENDD
#ifndef CGLM_LIB
{
  return glm_min(v[0], v[1]);
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
glm_vec2_isnan(vec2 v) CGLM_ENDD
#ifndef CGLM_LIB
{
  return isnan(v[0]) || isnan(v[1]);
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
glm_vec2_isinf(vec2 v) CGLM_ENDD
#ifndef CGLM_LIB
{
  return isinf(v[0]) || isinf(v[1]);
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
glm_vec2_isvalid(vec2 v) CGLM_ENDD
#ifndef CGLM_LIB
{
  return !glm_vec2_isnan(v) && !glm_vec2_isinf(v);
}
#endif

/*!
 * @brief get sign of 32 bit float as +1, -1, 0
 *
 * Important: It returns 0 for zero/NaN input
 *
 * @param v vector
 */
CGLM_DECL
void
glm_vec2_sign(vec2 v, vec2 dest) CGLM_ENDD
#ifndef CGLM_LIB
{
  dest[0] = glm_signf(v[0]);
  dest[1] = glm_signf(v[1]);
}
#endif

/*!
 * @brief square root of each vector item
 *
 * @param[in]  v    vector
 * @param[out] dest destination vector
 */
CGLM_DECL
void
glm_vec2_sqrt(vec2 v, vec2 dest) CGLM_ENDD
#ifndef CGLM_LIB
{
  dest[0] = sqrtf(v[0]);
  dest[1] = sqrtf(v[1]);
}
#endif

#endif /* cglm_vec2_ext_h */
