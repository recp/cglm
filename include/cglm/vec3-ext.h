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
   CGLM_DECL void  glm_vec3_broadcast(float val, vec3 d);
   CGLM_DECL void  glm_vec3_fill(vec3 v, float val);
   CGLM_DECL bool  glm_vec3_eq(vec3 v, float val);
   CGLM_DECL bool  glm_vec3_eq_eps(vec3 v, float val);
   CGLM_DECL bool  glm_vec3_eq_all(vec3 v);
   CGLM_DECL bool  glm_vec3_eqv(vec3 a, vec3 b);
   CGLM_DECL bool  glm_vec3_eqv_eps(vec3 a, vec3 b);
   CGLM_DECL float glm_vec3_max(vec3 v);
   CGLM_DECL float glm_vec3_min(vec3 v);
   CGLM_DECL bool  glm_vec3_isnan(vec3 v);
   CGLM_DECL bool  glm_vec3_isinf(vec3 v);
   CGLM_DECL bool  glm_vec3_isvalid(vec3 v);
   CGLM_DECL void  glm_vec3_sign(vec3 v, vec3 dest);
   CGLM_DECL void  glm_vec3_abs(vec3 v, vec3 dest);
   CGLM_DECL void  glm_vec3_fract(vec3 v, vec3 dest);
   CGLM_DECL float glm_vec3_hadd(vec3 v);
   CGLM_DECL void  glm_vec3_sqrt(vec3 v, vec3 dest);
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
CGLM_DECL
void
glm_vec3_broadcast(float val, vec3 d) CGLM_ENDD
#ifndef CGLM_LIB
{
  d[0] = d[1] = d[2] = val;
}
#endif

/*!
 * @brief fill a vector with specified value
 *
 * @param[out] v   dest
 * @param[in]  val value
 */
CGLM_DECL
void
glm_vec3_fill(vec3 v, float val) CGLM_ENDD
#ifndef CGLM_LIB
{
  v[0] = v[1] = v[2] = val;
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
glm_vec3_eq(vec3 v, float val) CGLM_ENDD
#ifndef CGLM_LIB
{
  return v[0] == val && v[0] == v[1] && v[0] == v[2];
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
glm_vec3_eq_eps(vec3 v, float val) CGLM_ENDD
#ifndef CGLM_LIB
{
  return fabsf(v[0] - val) <= FLT_EPSILON
         && fabsf(v[1] - val) <= FLT_EPSILON
         && fabsf(v[2] - val) <= FLT_EPSILON;
}
#endif

/*!
 * @brief check if vectors members are equal (without epsilon)
 *
 * @param[in] v   vector
 */
CGLM_DECL
bool
glm_vec3_eq_all(vec3 v) CGLM_ENDD
#ifndef CGLM_LIB
{
  return v[0] == v[1] && v[0] == v[2];
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
glm_vec3_eqv(vec3 a, vec3 b) CGLM_ENDD
#ifndef CGLM_LIB
{
  return a[0] == b[0]
         && a[1] == b[1]
         && a[2] == b[2];
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
glm_vec3_eqv_eps(vec3 a, vec3 b) CGLM_ENDD
#ifndef CGLM_LIB
{
  return fabsf(a[0] - b[0]) <= FLT_EPSILON
         && fabsf(a[1] - b[1]) <= FLT_EPSILON
         && fabsf(a[2] - b[2]) <= FLT_EPSILON;
}
#endif

/*!
 * @brief max value of vector
 *
 * @param[in] v vector
 */
CGLM_DECL
float
glm_vec3_max(vec3 v) CGLM_ENDD
#ifndef CGLM_LIB
{
  float max;

  max = v[0];
  if (v[1] > max)
    max = v[1];
  if (v[2] > max)
    max = v[2];

  return max;
}
#endif

/*!
 * @brief min value of vector
 *
 * @param[in] v vector
 */
CGLM_DECL
float
glm_vec3_min(vec3 v) CGLM_ENDD
#ifndef CGLM_LIB
{
  float min;

  min = v[0];
  if (v[1] < min)
    min = v[1];
  if (v[2] < min)
    min = v[2];

  return min;
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
glm_vec3_isnan(vec3 v) CGLM_ENDD
#ifndef CGLM_LIB
{
  return isnan(v[0]) || isnan(v[1]) || isnan(v[2]);
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
glm_vec3_isinf(vec3 v) CGLM_ENDD
#ifndef CGLM_LIB
{
  return isinf(v[0]) || isinf(v[1]) || isinf(v[2]);
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
glm_vec3_isvalid(vec3 v) CGLM_ENDD
#ifndef CGLM_LIB
{
  return !glm_vec3_isnan(v) && !glm_vec3_isinf(v);
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
glm_vec3_sign(vec3 v, vec3 dest) CGLM_ENDD
#ifndef CGLM_LIB
{
  dest[0] = glm_signf(v[0]);
  dest[1] = glm_signf(v[1]);
  dest[2] = glm_signf(v[2]);
}
#endif

/*!
 * @brief absolute value of each vector item
 *
 * @param[in]  v    vector
 * @param[out] dest destination vector
 */
CGLM_DECL
void
glm_vec3_abs(vec3 v, vec3 dest) CGLM_ENDD
#ifndef CGLM_LIB
{
  dest[0] = fabsf(v[0]);
  dest[1] = fabsf(v[1]);
  dest[2] = fabsf(v[2]);
}
#endif

/*!
 * @brief fractional part of each vector item
 *
 * @param[in]  v    vector
 * @param[out] dest destination vector
 */
CGLM_DECL
void
glm_vec3_fract(vec3 v, vec3 dest) CGLM_ENDD
#ifndef CGLM_LIB
{
  dest[0] = fminf(v[0] - floorf(v[0]), 0x1.fffffep-1f);
  dest[1] = fminf(v[1] - floorf(v[1]), 0x1.fffffep-1f);
  dest[2] = fminf(v[2] - floorf(v[2]), 0x1.fffffep-1f);
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
glm_vec3_hadd(vec3 v) CGLM_ENDD
#ifndef CGLM_LIB
{
  return v[0] + v[1] + v[2];
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
glm_vec3_sqrt(vec3 v, vec3 dest) CGLM_ENDD
#ifndef CGLM_LIB
{
  dest[0] = sqrtf(v[0]);
  dest[1] = sqrtf(v[1]);
  dest[2] = sqrtf(v[2]);
}
#endif

#endif /* cglm_vec3_ext_h */
