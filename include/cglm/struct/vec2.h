/*
 * Copyright (c), Recep Aslantas.
 *
 * MIT License (MIT), http://opensource.org/licenses/MIT
 * Full license can be found in the LICENSE file
 */

/*
 Macros:
   GLMS_VEC2_ONE_INIT
   GLMS_VEC2_ZERO_INIT
   GLMS_VEC2_ONE
   GLMS_VEC2_ZERO

 Functions:
   CGLM_DECL vec2s glms_vec2(vec3s v3)
   CGLM_DECL void  glms_vec2_pack(vec2s dst[], vec2 src[], size_t len)
   CGLM_DECL void  glms_vec2_unpack(vec2 dst[], vec2s src[], size_t len)
   CGLM_DECL vec2s glms_vec2_zero(void)
   CGLM_DECL vec2s glms_vec2_one(void)
   CGLM_DECL float glms_vec2_dot(vec2s a, vec2s b)
   CGLM_DECL float glms_vec2_cross(vec2s a, vec2s b)
   CGLM_DECL float glms_vec2_norm2(vec2s v)
   CGLM_DECL float glms_vec2_norm(vec2s v)
   CGLM_DECL vec2s glms_vec2_add(vec2s a, vec2s b)
   CGLM_DECL vec2s glms_vec2_adds(vec2s a, float s)
   CGLM_DECL vec2s glms_vec2_sub(vec2s a, vec2s b)
   CGLM_DECL vec2s glms_vec2_subs(vec2s a, float s)
   CGLM_DECL vec2s glms_vec2_mul(vec2s a, vec2s b)
   CGLM_DECL vec2s glms_vec2_scale(vec2s v, float s)
   CGLM_DECL vec2s glms_vec2_scale_as(vec2s v, float s)
   CGLM_DECL vec2s glms_vec2_div(vec2s a, vec2s b)
   CGLM_DECL vec2s glms_vec2_divs(vec2s a, float s)
   CGLM_DECL vec2s glms_vec2_addadd(vec2s a, vec2s b, vec2s dest)
   CGLM_DECL vec2s glms_vec2_subadd(vec2s a, vec2s b, vec2s dest)
   CGLM_DECL vec2s glms_vec2_muladd(vec2s a, vec2s b, vec2s dest)
   CGLM_DECL vec2s glms_vec2_muladds(vec2s a, float s, vec2s dest)
   CGLM_DECL vec2s glms_vec2_maxadd(vec2s a, vec2s b, vec2s dest)
   CGLM_DECL vec2s glms_vec2_minadd(vec2s a, vec2s b, vec2s dest)
   CGLM_DECL vec2s glms_vec2_negate(vec2s v)
   CGLM_DECL vec2s glms_vec2_normalize(vec2s v)
   CGLM_DECL vec2s glms_vec2_rotate(vec2s v, float angle, vec2s axis)
   CGLM_DECL float glms_vec2_distance(vec2s a, vec2s b)
   CGLM_DECL float glms_vec2_distance2(vec2s a, vec2s b)
   CGLM_DECL vec2s glms_vec2_maxv(vec2s a, vec2s b)
   CGLM_DECL vec2s glms_vec2_minv(vec2s a, vec2s b)
   CGLM_DECL vec2s glms_vec2_clamp(vec2s v, float minVal, float maxVal)
   CGLM_DECL vec2s glms_vec2_lerp(vec2s from, vec2s to, float t)
 */

#ifndef cglms_vec2s_h
#define cglms_vec2s_h

#include "../common.h"
#include "../types-struct.h"
#include "../util.h"
#include "../vec2.h"
#include "vec2-ext.h"

#define GLMS_VEC2_ONE_INIT   {GLM_VEC2_ONE_INIT}
#define GLMS_VEC2_ZERO_INIT  {GLM_VEC2_ZERO_INIT}

#define GLMS_VEC2_ONE  ((vec2s)GLMS_VEC2_ONE_INIT)
#define GLMS_VEC2_ZERO ((vec2s)GLMS_VEC2_ZERO_INIT)

/*!
 * @brief init vec2 using vec2
 *
 * @param[in]  v3   vector3
 * @returns         destination
 */
CGLM_DECL
vec2s
glms_vec2(vec3s v3) CGLM_ENDD
#ifndef CGLM_LIB
{
  vec2s r;
  glm_vec2(v3.raw, r.raw);
  return r;
}
#endif

/*!
 * @brief pack an array of vec2 into an array of vec2s
 *
 * @param[out] dst array of vec2
 * @param[in]  src array of vec2s
 * @param[in]  len number of elements
 */
CGLM_DECL
void
glms_vec2_pack(vec2s dst[], vec2 src[], size_t len) CGLM_ENDD
#ifndef CGLM_LIB
{
  size_t i;

  for (i = 0; i < len; i++) {
    glm_vec2_copy(src[i], dst[i].raw);
  }
}
#endif

/*!
 * @brief unpack an array of vec2s into an array of vec2
 *
 * @param[out] dst array of vec2s
 * @param[in]  src array of vec2
 * @param[in]  len number of elements
 */
CGLM_DECL
void
glms_vec2_unpack(vec2 dst[], vec2s src[], size_t len) CGLM_ENDD
#ifndef CGLM_LIB
{
  size_t i;

  for (i = 0; i < len; i++) {
    glm_vec2_copy(src[i].raw, dst[i]);
  }
}
#endif

/*!
 * @brief make vector zero
 *
 * @returns zero vector
 */
CGLM_DECL
vec2s
glms_vec2_zero(void) CGLM_ENDD
#ifndef CGLM_LIB
{
  vec2s r;
  glm_vec2_zero(r.raw);
  return r;
}
#endif

/*!
 * @brief make vector one
 *
 * @returns one vector
 */
CGLM_DECL
vec2s
glms_vec2_one(void) CGLM_ENDD
#ifndef CGLM_LIB
{
  vec2s r;
  glm_vec2_one(r.raw);
  return r;
}
#endif

/*!
 * @brief vec2 dot product
 *
 * @param[in] a vector1
 * @param[in] b vector2
 *
 * @return dot product
 */
CGLM_DECL
float
glms_vec2_dot(vec2s a, vec2s b) CGLM_ENDD
#ifndef CGLM_LIB
{
  return glm_vec2_dot(a.raw, b.raw);
}
#endif

/*!
 * @brief vec2 cross product
 *
 * REF: http://allenchou.net/2013/07/cross-product-of-2d-vectors/
 *
 * @param[in]  a vector1
 * @param[in]  b vector2
 *
 * @return Z component of cross product
 */
CGLM_DECL
float
glms_vec2_cross(vec2s a, vec2s b) CGLM_ENDD
#ifndef CGLM_LIB
{
  return glm_vec2_cross(a.raw, b.raw);
}
#endif

/*!
 * @brief norm * norm (magnitude) of vec
 *
 * we can use this func instead of calling norm * norm, because it would call
 * sqrtf fuction twice but with this func we can avoid func call, maybe this is
 * not good name for this func
 *
 * @param[in] v vector
 *
 * @return norm * norm
 */
CGLM_DECL
float
glms_vec2_norm2(vec2s v) CGLM_ENDD
#ifndef CGLM_LIB
{
  return glm_vec2_norm2(v.raw);
}
#endif

/*!
 * @brief norm (magnitude) of vec2
 *
 * @param[in] v vector
 *
 * @return norm
 */
CGLM_DECL
float
glms_vec2_norm(vec2s v) CGLM_ENDD
#ifndef CGLM_LIB
{
  return glm_vec2_norm(v.raw);
}
#endif

/*!
 * @brief add a vector to b vector store result in dest
 *
 * @param[in]  a    vector1
 * @param[in]  b    vector2
 * @returns         destination vector
 */
CGLM_DECL
vec2s
glms_vec2_add(vec2s a, vec2s b) CGLM_ENDD
#ifndef CGLM_LIB
{
  vec2s r;
  glm_vec2_add(a.raw, b.raw, r.raw);
  return r;
}
#endif

/*!
 * @brief add scalar to v vector store result in dest (d = v + s)
 *
 * @param[in]  a    vector
 * @param[in]  s    scalar
 * @returns         destination vector
 */
CGLM_DECL
vec2s
glms_vec2_adds(vec2s a, float s) CGLM_ENDD
#ifndef CGLM_LIB
{
  vec2s r;
  glm_vec2_adds(a.raw, s, r.raw);
  return r;
}
#endif

/*!
 * @brief subtract b vector from a vector store result in dest
 *
 * @param[in]  a    vector1
 * @param[in]  b    vector2
 * @returns         destination vector
 */
CGLM_DECL
vec2s
glms_vec2_sub(vec2s a, vec2s b) CGLM_ENDD
#ifndef CGLM_LIB
{
  vec2s r;
  glm_vec2_sub(a.raw, b.raw, r.raw);
  return r;
}
#endif

/*!
 * @brief subtract scalar from v vector store result in dest (d = v - s)
 *
 * @param[in]  a    vector
 * @param[in]  s    scalar
 * @returns         destination vector
 */
CGLM_DECL
vec2s
glms_vec2_subs(vec2s a, float s) CGLM_ENDD
#ifndef CGLM_LIB
{
  vec2s r;
  glm_vec2_subs(a.raw, s, r.raw);
  return r;
}
#endif

/*!
 * @brief multiply two vector (component-wise multiplication)
 *
 * @param     a     vector1
 * @param     b     vector2
 * @returns         v3 = (a[0] * b[0], a[1] * b[1], a[2] * b[2])
 */
CGLM_DECL
vec2s
glms_vec2_mul(vec2s a, vec2s b) CGLM_ENDD
#ifndef CGLM_LIB
{
  vec2s r;
  glm_vec2_mul(a.raw, b.raw, r.raw);
  return r;
}
#endif

/*!
 * @brief multiply/scale vec2 vector with scalar: result = v * s
 *
 * @param[in]  v    vector
 * @param[in]  s    scalar
 * @returns         destination vector
 */
CGLM_DECL
vec2s
glms_vec2_scale(vec2s v, float s) CGLM_ENDD
#ifndef CGLM_LIB
{
  vec2s r;
  glm_vec2_scale(v.raw, s, r.raw);
  return r;
}
#endif

/*!
 * @brief make vec2 vector scale as specified: result = unit(v) * s
 *
 * @param[in]  v    vector
 * @param[in]  s    scalar
 * @returns         destination vector
 */
CGLM_DECL
vec2s
glms_vec2_scale_as(vec2s v, float s) CGLM_ENDD
#ifndef CGLM_LIB
{
  vec2s r;
  glm_vec2_scale_as(v.raw, s, r.raw);
  return r;
}
#endif

/*!
 * @brief div vector with another component-wise division: d = a / b
 *
 * @param[in]  a    vector 1
 * @param[in]  b    vector 2
 * @returns         result = (a[0]/b[0], a[1]/b[1], a[2]/b[2])
 */
CGLM_DECL
vec2s
glms_vec2_div(vec2s a, vec2s b) CGLM_ENDD
#ifndef CGLM_LIB
{
  vec2s r;
  glm_vec2_div(a.raw, b.raw, r.raw);
  return r;
}
#endif

/*!
 * @brief div vector with scalar: d = v / s
 *
 * @param[in]  a    vector
 * @param[in]  s    scalar
 * @returns         result = (a[0]/s, a[1]/s, a[2]/s)
 */
CGLM_DECL
vec2s
glms_vec2_divs(vec2s a, float s) CGLM_ENDD
#ifndef CGLM_LIB
{
  vec2s r;
  glm_vec2_divs(a.raw, s, r.raw);
  return r;
}
#endif

/*!
 * @brief add two vectors and add result to sum
 *
 * it applies += operator so dest must be initialized
 *
 * @param[in]  a    vector 1
 * @param[in]  b    vector 2
 * @returns         dest += (a + b)
 */
CGLM_DECL
vec2s
glms_vec2_addadd(vec2s a, vec2s b, vec2s dest) CGLM_ENDD
#ifndef CGLM_LIB
{
  glm_vec2_addadd(a.raw, b.raw, dest.raw);
  return dest;
}
#endif

/*!
 * @brief sub two vectors and add result to dest
 *
 * it applies += operator so dest must be initialized
 *
 * @param[in]  a    vector 1
 * @param[in]  b    vector 2
 * @returns         dest += (a + b)
 */
CGLM_DECL
vec2s
glms_vec2_subadd(vec2s a, vec2s b, vec2s dest) CGLM_ENDD
#ifndef CGLM_LIB
{
  glm_vec2_subadd(a.raw, b.raw, dest.raw);
  return dest;
}
#endif

/*!
 * @brief mul two vectors and add result to dest
 *
 * it applies += operator so dest must be initialized
 *
 * @param[in]  a    vector 1
 * @param[in]  b    vector 2
 * @returns         dest += (a * b)
 */
CGLM_DECL
vec2s
glms_vec2_muladd(vec2s a, vec2s b, vec2s dest) CGLM_ENDD
#ifndef CGLM_LIB
{
  glm_vec2_muladd(a.raw, b.raw, dest.raw);
  return dest;
}
#endif

/*!
 * @brief mul vector with scalar and add result to sum
 *
 * it applies += operator so dest must be initialized
 *
 * @param[in]  a    vector
 * @param[in]  s    scalar
 * @returns         dest += (a * b)
 */
CGLM_DECL
vec2s
glms_vec2_muladds(vec2s a, float s, vec2s dest) CGLM_ENDD
#ifndef CGLM_LIB
{
  glm_vec2_muladds(a.raw, s, dest.raw);
  return dest;
}
#endif

/*!
 * @brief add max of two vector to result/dest
 *
 * it applies += operator so dest must be initialized
 *
 * @param[in]  a    vector 1
 * @param[in]  b    vector 2
 * @returns         dest += max(a, b)
 */
CGLM_DECL
vec2s
glms_vec2_maxadd(vec2s a, vec2s b, vec2s dest) CGLM_ENDD
#ifndef CGLM_LIB
{
  glm_vec2_maxadd(a.raw, b.raw, dest.raw);
  return dest;
}
#endif

/*!
 * @brief add min of two vector to result/dest
 *
 * it applies += operator so dest must be initialized
 *
 * @param[in]  a    vector 1
 * @param[in]  b    vector 2
 * @returns         dest += min(a, b)
 */
CGLM_DECL
vec2s
glms_vec2_minadd(vec2s a, vec2s b, vec2s dest) CGLM_ENDD
#ifndef CGLM_LIB
{
  glm_vec2_minadd(a.raw, b.raw, dest.raw);
  return dest;
}
#endif

/*!
 * @brief negate vector components
 *
 * @param[in]  v  vector
 * @returns       negated vector
 */
CGLM_DECL
vec2s
glms_vec2_negate(vec2s v) CGLM_ENDD
#ifndef CGLM_LIB
{
  glm_vec2_negate(v.raw);
  return v;
}
#endif

/*!
 * @brief normalize vec2 and store result in same vec
 *
 * @param[in] v vector
 * @returns     normalized vector
 */
CGLM_DECL
vec2s
glms_vec2_normalize(vec2s v) CGLM_ENDD
#ifndef CGLM_LIB
{
  glm_vec2_normalize(v.raw);
  return v;
}
#endif

/*!
 * @brief rotate vec2 by angle using Rodrigues' rotation formula
 *
 * @param[in]     v     vector
 * @param[in]     angle angle by radians
 * @returns             rotated vector
 */
CGLM_DECL
vec2s
glms_vec2_rotate(vec2s v, float angle) CGLM_ENDD
#ifndef CGLM_LIB
{
  vec2s r;
  glm_vec2_rotate(v.raw, angle, r.raw);
  return r;
}
#endif

/**
 * @brief distance between two vectors
 *
 * @param[in] a vector1
 * @param[in] b vector2
 * @return      distance
 */
CGLM_DECL
float
glms_vec2_distance(vec2s a, vec2s b) CGLM_ENDD
#ifndef CGLM_LIB
{
  return glm_vec2_distance(a.raw, b.raw);
}
#endif

/**
 * @brief squared distance between two vectors
 *
 * @param[in] a vector1
 * @param[in] b vector2
 * @return      squared distance (distance * distance)
 */
CGLM_DECL
float
glms_vec2_distance2(vec2s a, vec2s b) CGLM_ENDD
#ifndef CGLM_LIB
{
  return glm_vec2_distance2(a.raw, b.raw);
}
#endif

/*!
 * @brief max values of vectors
 *
 * @param[in]  a    vector1
 * @param[in]  b    vector2
 * @returns         destination
 */
CGLM_DECL
vec2s
glms_vec2_maxv(vec2s a, vec2s b) CGLM_ENDD
#ifndef CGLM_LIB
{
  vec2s r;
  glm_vec2_maxv(a.raw, b.raw, r.raw);
  return r;
}
#endif

/*!
 * @brief min values of vectors
 *
 * @param[in]  a    vector1
 * @param[in]  b    vector2
 * @returns         destination
 */
CGLM_DECL
vec2s
glms_vec2_minv(vec2s a, vec2s b) CGLM_ENDD
#ifndef CGLM_LIB
{
  vec2s r;
  glm_vec2_minv(a.raw, b.raw, r.raw);
  return r;
}
#endif

/*!
 * @brief clamp vector's individual members between min and max values
 *
 * @param[in]       v       vector
 * @param[in]       minVal  minimum value
 * @param[in]       maxVal  maximum value
 * @returns                 clamped vector
 */
CGLM_DECL
vec2s
glms_vec2_clamp(vec2s v, float minVal, float maxVal) CGLM_ENDD
#ifndef CGLM_LIB
{
  glm_vec2_clamp(v.raw, minVal, maxVal);
  return v;
}
#endif

/*!
 * @brief linear interpolation between two vectors
 *
 * formula:  from + s * (to - from)
 *
 * @param[in]   from  from value
 * @param[in]   to    to value
 * @param[in]   t     interpolant (amount)
 * @returns           destination
 */
CGLM_DECL
vec2s
glms_vec2_lerp(vec2s from, vec2s to, float t) CGLM_ENDD
#ifndef CGLM_LIB
{
  vec2s r;
  glm_vec2_lerp(from.raw, to.raw, t, r.raw);
  return r;
}
#endif

#endif /* cglms_vec2s_h */
