/*
 * Copyright (c), Recep Aslantas.
 *
 * MIT License (MIT), http://opensource.org/licenses/MIT
 * Full license can be found in the LICENSE file
 */

/*
 Macros:
   GLMS_VEC3_ONE_INIT
   GLMS_VEC3_ZERO_INIT
   GLMS_VEC3_ONE
   GLMS_VEC3_ZERO
   GLMS_YUP
   GLMS_ZUP
   GLMS_XUP

 Functions:
   CGLM_DECL vec3s glms_vec3(vec4s v4);
   CGLM_DECL void  glms_vec3_pack(vec3s dst[], vec3 src[], size_t len);
   CGLM_DECL void  glms_vec3_unpack(vec3 dst[], vec3s src[], size_t len);
   CGLM_DECL vec3s glms_vec3_zero(void);
   CGLM_DECL vec3s glms_vec3_one(void);
   CGLM_DECL float glms_vec3_dot(vec3s a, vec3s b);
   CGLM_DECL float glms_vec3_norm2(vec3s v);
   CGLM_DECL float glms_vec3_norm(vec3s v);
   CGLM_DECL float glms_vec3_norm_one(vec3s v);
   CGLM_DECL float glms_vec3_norm_inf(vec3s v);
   CGLM_DECL vec3s glms_vec3_add(vec3s a, vec3s b);
   CGLM_DECL vec3s glms_vec3_adds(vec3s a, float s);
   CGLM_DECL vec3s glms_vec3_sub(vec3s a, vec3s b);
   CGLM_DECL vec3s glms_vec3_subs(vec3s a, float s);
   CGLM_DECL vec3s glms_vec3_mul(vec3s a, vec3s b);
   CGLM_DECL vec3s glms_vec3_scale(vec3s v, float s);
   CGLM_DECL vec3s glms_vec3_scale_as(vec3s v, float s);
   CGLM_DECL vec3s glms_vec3_div(vec3s a, vec3s b);
   CGLM_DECL vec3s glms_vec3_divs(vec3s a, float s);
   CGLM_DECL vec3s glms_vec3_addadd(vec3s a, vec3s b, vec3s dest);
   CGLM_DECL vec3s glms_vec3_subadd(vec3s a, vec3s b, vec3s dest);
   CGLM_DECL vec3s glms_vec3_muladd(vec3s a, vec3s b, vec3s dest);
   CGLM_DECL vec3s glms_vec3_muladds(vec3s a, float s, vec3s dest);
   CGLM_DECL vec3s glms_vec3_maxadd(vec3s a, vec3s b, vec3s dest);
   CGLM_DECL vec3s glms_vec3_minadd(vec3s a, vec3s b, vec3s dest);
   CGLM_DECL vec3s glms_vec3_flipsign(vec3s v);
   CGLM_DECL vec3s glms_vec3_negate(vec3s v);
   CGLM_DECL vec3s glms_vec3_inv(vec3s v);
   CGLM_DECL vec3s glms_vec3_normalize(vec3s v);
   CGLM_DECL vec3s glms_vec3_cross(vec3s a, vec3s b);
   CGLM_DECL vec3s glms_vec3_crossn(vec3s a, vec3s b);
   CGLM_DECL float glms_vec3_angle(vec3s a, vec3s b);
   CGLM_DECL vec3s glms_vec3_rotate(vec3s v, float angle, vec3s axis);
   CGLM_DECL vec3s glms_vec3_rotate_m4(mat4s m, vec3s v);
   CGLM_DECL vec3s glms_vec3_rotate_m3(mat3s m, vec3s v);
   CGLM_DECL vec3s glms_vec3_proj(vec3s a, vec3s b);
   CGLM_DECL vec3s glms_vec3_center(vec3s a, vec3s b);
   CGLM_DECL float glms_vec3_distance(vec3s a, vec3s b);
   CGLM_DECL float glms_vec3_distance2(vec3s a, vec3s b);
   CGLM_DECL vec3s glms_vec3_maxv(vec3s a, vec3s b);
   CGLM_DECL vec3s glms_vec3_minv(vec3s a, vec3s b);
   CGLM_DECL vec3s glms_vec3_ortho(vec3s v);
   CGLM_DECL vec3s glms_vec3_clamp(vec3s v, float minVal, float maxVal);
   CGLM_DECL vec3s glms_vec3_lerp(vec3s from, vec3s to, float t);
   CGLM_DECL vec3s glms_vec3_lerpc(vec3s from, vec3s to, float t);
   CGLM_DECL vec3s glms_vec3_mix(vec3s from, vec3s to, float t);
   CGLM_DECL vec3s glms_vec3_mixc(vec3s from, vec3s to, float t);
   CGLM_DECL vec3s glms_vec3_step_uni(float edge, vec3s x);
   CGLM_DECL vec3s glms_vec3_step(vec3s edge, vec3s x);
   CGLM_DECL vec3s glms_vec3_smoothstep_uni(float edge0, float edge1, vec3s x);
   CGLM_DECL vec3s glms_vec3_smoothstep(vec3s edge0, vec3s edge1, vec3s x);
   CGLM_DECL vec3s glms_vec3_smoothinterp(vec3s from, vec3s to, float t);
   CGLM_DECL vec3s glms_vec3_smoothinterpc(vec3s from, vec3s to, float t);
   CGLM_DECL vec3s glms_vec3_swizzle(vec3s v, int mask);

 Convenient:
   CGLM_DECL vec3s glms_cross(vec3s a, vec3s b);
   CGLM_DECL float glms_dot(vec3s a, vec3s b);
   CGLM_DECL vec3s glms_normalize(vec3s v);
 */

#ifndef cglms_vec3s_h
#define cglms_vec3s_h

#include "../common.h"
#include "../types-struct.h"
#include "../util.h"
#include "../vec3.h"
#include "vec3-ext.h"

#define GLMS_VEC3_ONE_INIT   {GLM_VEC3_ONE_INIT}
#define GLMS_VEC3_ZERO_INIT  {GLM_VEC3_ZERO_INIT}

#define GLMS_VEC3_ONE  ((vec3s)GLMS_VEC3_ONE_INIT)
#define GLMS_VEC3_ZERO ((vec3s)GLMS_VEC3_ZERO_INIT)

#define GLMS_YUP  ((vec3s){{0.0f, 1.0f, 0.0f}})
#define GLMS_ZUP  ((vec3s){{0.0f, 0.0f, 1.0f}})
#define GLMS_XUP  ((vec3s){{1.0f, 0.0f, 0.0f}})

/*!
 * @brief init vec3 using vec4
 *
 * @param[in]  v4   vector4
 * @returns         destination
 */
CGLM_DECL
vec3s
glms_vec3(vec4s v4) CGLM_ENDD
#ifndef CGLM_LIB
{
  vec3s r;
  glm_vec3(v4.raw, r.raw);
  return r;
}
#endif

/*!
 * @brief pack an array of vec3 into an array of vec3s
 *
 * @param[out] dst array of vec3
 * @param[in]  src array of vec3s
 * @param[in]  len number of elements
 */
CGLM_DECL
void
glms_vec3_pack(vec3s dst[], vec3 src[], size_t len) CGLM_ENDD
#ifndef CGLM_LIB
{
  size_t i;

  for (i = 0; i < len; i++) {
    glm_vec3_copy(src[i], dst[i].raw);
  }
}
#endif

/*!
 * @brief unpack an array of vec3s into an array of vec3
 *
 * @param[out] dst array of vec3s
 * @param[in]  src array of vec3
 * @param[in]  len number of elements
 */
CGLM_DECL
void
glms_vec3_unpack(vec3 dst[], vec3s src[], size_t len) CGLM_ENDD
#ifndef CGLM_LIB
{
  size_t i;

  for (i = 0; i < len; i++) {
    glm_vec3_copy(src[i].raw, dst[i]);
  }
}
#endif

/*!
 * @brief make vector zero
 *
 * @returns       zero vector
 */
CGLM_DECL
vec3s
glms_vec3_zero(void) CGLM_ENDD
#ifndef CGLM_LIB
{
  vec3s r;
  glm_vec3_zero(r.raw);
  return r;
}
#endif

/*!
 * @brief make vector one
 *
 * @returns       one vector
 */
CGLM_DECL
vec3s
glms_vec3_one(void) CGLM_ENDD
#ifndef CGLM_LIB
{
  vec3s r;
  glm_vec3_one(r.raw);
  return r;
}
#endif

/*!
 * @brief vec3 dot product
 *
 * @param[in] a vector1
 * @param[in] b vector2
 *
 * @return dot product
 */
CGLM_DECL
float
glms_vec3_dot(vec3s a, vec3s b) CGLM_ENDD
#ifndef CGLM_LIB
{
  return glm_vec3_dot(a.raw, b.raw);
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
glms_vec3_norm2(vec3s v) CGLM_ENDD
#ifndef CGLM_LIB
{
  return glm_vec3_norm2(v.raw);
}
#endif

/*!
 * @brief norm (magnitude) of vec3
 *
 * @param[in] v vector
 *
 * @return norm
 */
CGLM_DECL
float
glms_vec3_norm(vec3s v) CGLM_ENDD
#ifndef CGLM_LIB
{
  return glm_vec3_norm(v.raw);
}
#endif

/*!
 * @brief L1 norm of vec3
 * Also known as Manhattan Distance or Taxicab norm.
 * L1 Norm is the sum of the magnitudes of the vectors in a space.
 * It is calculated as the sum of the absolute values of the vector components.
 * In this norm, all the components of the vector are weighted equally.
 *
 * This computes:
 * R = |v[0]| + |v[1]| + |v[2]|
 *
 * @param[in] v vector
 *
 * @return L1 norm
 */
CGLM_DECL
float
glms_vec3_norm_one(vec3s v) CGLM_ENDD
#ifndef CGLM_LIB
{
  return glm_vec3_norm_one(v.raw);
}
#endif

/*!
 * @brief Infinity norm of vec3
 * Also known as Maximum norm.
 * Infinity Norm is the largest magnitude among each element of a vector.
 * It is calculated as the maximum of the absolute values of the vector components.
 *
 * This computes:
 * inf norm = max(|v[0]|, |v[1]|, |v[2]|)
 *
 * @param[in] v vector
 *
 * @return Infinity norm
 */
CGLM_DECL
float
glms_vec3_norm_inf(vec3s v) CGLM_ENDD
#ifndef CGLM_LIB
{
  return glm_vec3_norm_inf(v.raw);
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
vec3s
glms_vec3_add(vec3s a, vec3s b) CGLM_ENDD
#ifndef CGLM_LIB
{
  vec3s r;
  glm_vec3_add(a.raw, b.raw, r.raw);
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
vec3s
glms_vec3_adds(vec3s a, float s) CGLM_ENDD
#ifndef CGLM_LIB
{
  vec3s r;
  glm_vec3_adds(a.raw, s, r.raw);
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
vec3s
glms_vec3_sub(vec3s a, vec3s b) CGLM_ENDD
#ifndef CGLM_LIB
{
  vec3s r;
  glm_vec3_sub(a.raw, b.raw, r.raw);
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
vec3s
glms_vec3_subs(vec3s a, float s) CGLM_ENDD
#ifndef CGLM_LIB
{
  vec3s r;
  glm_vec3_subs(a.raw, s, r.raw);
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
vec3s
glms_vec3_mul(vec3s a, vec3s b) CGLM_ENDD
#ifndef CGLM_LIB
{
  vec3s r;
  glm_vec3_mul(a.raw, b.raw, r.raw);
  return r;
}
#endif

/*!
 * @brief multiply/scale vec3 vector with scalar: result = v * s
 *
 * @param[in]  v    vector
 * @param[in]  s    scalar
 * @returns         destination vector
 */
CGLM_DECL
vec3s
glms_vec3_scale(vec3s v, float s) CGLM_ENDD
#ifndef CGLM_LIB
{
  vec3s r;
  glm_vec3_scale(v.raw, s, r.raw);
  return r;
}
#endif

/*!
 * @brief make vec3 vector scale as specified: result = unit(v) * s
 *
 * @param[in]  v    vector
 * @param[in]  s    scalar
 * @returns         destination vector
 */
CGLM_DECL
vec3s
glms_vec3_scale_as(vec3s v, float s) CGLM_ENDD
#ifndef CGLM_LIB
{
  vec3s r;
  glm_vec3_scale_as(v.raw, s, r.raw);
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
vec3s
glms_vec3_div(vec3s a, vec3s b) CGLM_ENDD
#ifndef CGLM_LIB
{
  vec3s r;
  glm_vec3_div(a.raw, b.raw, r.raw);
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
vec3s
glms_vec3_divs(vec3s a, float s) CGLM_ENDD
#ifndef CGLM_LIB
{
  vec3s r;
  glm_vec3_divs(a.raw, s, r.raw);
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
vec3s
glms_vec3_addadd(vec3s a, vec3s b, vec3s dest) CGLM_ENDD
#ifndef CGLM_LIB
{
  glm_vec3_addadd(a.raw, b.raw, dest.raw);
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
vec3s
glms_vec3_subadd(vec3s a, vec3s b, vec3s dest) CGLM_ENDD
#ifndef CGLM_LIB
{
  glm_vec3_subadd(a.raw, b.raw, dest.raw);
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
vec3s
glms_vec3_muladd(vec3s a, vec3s b, vec3s dest) CGLM_ENDD
#ifndef CGLM_LIB
{
  glm_vec3_muladd(a.raw, b.raw, dest.raw);
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
vec3s
glms_vec3_muladds(vec3s a, float s, vec3s dest) CGLM_ENDD
#ifndef CGLM_LIB
{
  glm_vec3_muladds(a.raw, s, dest.raw);
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
vec3s
glms_vec3_maxadd(vec3s a, vec3s b, vec3s dest) CGLM_ENDD
#ifndef CGLM_LIB
{
  glm_vec3_maxadd(a.raw, b.raw, dest.raw);
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
vec3s
glms_vec3_minadd(vec3s a, vec3s b, vec3s dest) CGLM_ENDD
#ifndef CGLM_LIB
{
  glm_vec3_minadd(a.raw, b.raw, dest.raw);
  return dest;
}
#endif

/*!
 * @brief negate vector components and store result in dest
 *
 * @param[in]   v     vector
 * @returns           result vector
 */
CGLM_DECL
vec3s
glms_vec3_flipsign(vec3s v) CGLM_ENDD
#ifndef CGLM_LIB
{
  glm_vec3_flipsign(v.raw);
  return v;
}
#endif

/*!
 * @brief negate vector components
 *
 * @param[in]  v  vector
 * @returns       negated vector
 */
CGLM_DECL
vec3s
glms_vec3_negate(vec3s v) CGLM_ENDD
#ifndef CGLM_LIB
{
  glm_vec3_negate(v.raw);
  return v;
}
#endif

/*!
 * @brief normalize vec3 and store result in same vec
 *
 * @param[in] v vector
 * @returns     normalized vector
 */
CGLM_DECL
vec3s
glms_vec3_normalize(vec3s v) CGLM_ENDD
#ifndef CGLM_LIB
{
  glm_vec3_normalize(v.raw);
  return v;
}
#endif

/*!
 * @brief cross product of two vector (RH)
 *
 * @param[in]  a    vector 1
 * @param[in]  b    vector 2
 * @returns         destination
 */
CGLM_DECL
vec3s
glms_vec3_cross(vec3s a, vec3s b) CGLM_ENDD
#ifndef CGLM_LIB
{
  vec3s r;
  glm_vec3_cross(a.raw, b.raw, r.raw);
  return r;
}
#endif

/*!
 * @brief cross product of two vector (RH) and normalize the result
 *
 * @param[in]  a    vector 1
 * @param[in]  b    vector 2
 * @returns         destination
 */
CGLM_DECL
vec3s
glms_vec3_crossn(vec3s a, vec3s b) CGLM_ENDD
#ifndef CGLM_LIB
{
  vec3s r;
  glm_vec3_crossn(a.raw, b.raw, r.raw);
  return r;
}
#endif

/*!
 * @brief angle betwen two vector
 *
 * @param[in] a  vector1
 * @param[in] b  vector2
 *
 * @return angle as radians
 */
CGLM_DECL
float
glms_vec3_angle(vec3s a, vec3s b) CGLM_ENDD
#ifndef CGLM_LIB
{
  return glm_vec3_angle(a.raw, b.raw);
}
#endif

/*!
 * @brief rotate vec3 around axis by angle using Rodrigues' rotation formula
 *
 * @param[in]     v     vector
 * @param[in]     axis  axis vector (must be unit vector)
 * @param[in]     angle angle by radians
 * @returns             rotated vector
 */
CGLM_DECL
vec3s
glms_vec3_rotate(vec3s v, float angle, vec3s axis) CGLM_ENDD
#ifndef CGLM_LIB
{
  glm_vec3_rotate(v.raw, angle, axis.raw);
  return v;
}
#endif

/*!
 * @brief apply rotation matrix to vector
 *
 *  matrix format should be (no perspective):
 *   a  b  c  x
 *   e  f  g  y
 *   i  j  k  z
 *   0  0  0  w
 *
 * @param[in]  m    affine matrix or rot matrix
 * @param[in]  v    vector
 * @returns         rotated vector
 */
CGLM_DECL
vec3s
glms_vec3_rotate_m4(mat4s m, vec3s v) CGLM_ENDD
#ifndef CGLM_LIB
{
  vec3s r;
  glm_vec3_rotate_m4(m.raw, v.raw, r.raw);
  return r;
}
#endif

/*!
 * @brief apply rotation matrix to vector
 *
 * @param[in]  m    affine matrix or rot matrix
 * @param[in]  v    vector
 * @returns         rotated vector
 */
CGLM_DECL
vec3s
glms_vec3_rotate_m3(mat3s m, vec3s v) CGLM_ENDD
#ifndef CGLM_LIB
{
  vec3s r;
  glm_vec3_rotate_m3(m.raw, v.raw, r.raw);
  return r;
}
#endif

/*!
 * @brief project a vector onto b vector
 *
 * @param[in]  a    vector1
 * @param[in]  b    vector2
 * @returns         projected vector
 */
CGLM_DECL
vec3s
glms_vec3_proj(vec3s a, vec3s b) CGLM_ENDD
#ifndef CGLM_LIB
{
  vec3s r;
  glm_vec3_proj(a.raw, b.raw, r.raw);
  return r;
}
#endif

/**
 * @brief find center point of two vector
 *
 * @param[in]  a    vector1
 * @param[in]  b    vector2
 * @returns         center point
 */
CGLM_DECL
vec3s
glms_vec3_center(vec3s a, vec3s b) CGLM_ENDD
#ifndef CGLM_LIB
{
  vec3s r;
  glm_vec3_center(a.raw, b.raw, r.raw);
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
glms_vec3_distance(vec3s a, vec3s b) CGLM_ENDD
#ifndef CGLM_LIB
{
  return glm_vec3_distance(a.raw, b.raw);
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
glms_vec3_distance2(vec3s a, vec3s b) CGLM_ENDD
#ifndef CGLM_LIB
{
  return glm_vec3_distance2(a.raw, b.raw);
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
vec3s
glms_vec3_maxv(vec3s a, vec3s b) CGLM_ENDD
#ifndef CGLM_LIB
{
  vec3s r;
  glm_vec3_maxv(a.raw, b.raw, r.raw);
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
vec3s
glms_vec3_minv(vec3s a, vec3s b) CGLM_ENDD
#ifndef CGLM_LIB
{
  vec3s r;
  glm_vec3_minv(a.raw, b.raw, r.raw);
  return r;
}
#endif

/*!
 * @brief possible orthogonal/perpendicular vector
 *
 * @param[in]  v    vector
 * @returns         orthogonal/perpendicular vector
 */
CGLM_DECL
vec3s
glms_vec3_ortho(vec3s v) CGLM_ENDD
#ifndef CGLM_LIB
{
  vec3s r;
  glm_vec3_ortho(v.raw, r.raw);
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
vec3s
glms_vec3_clamp(vec3s v, float minVal, float maxVal) CGLM_ENDD
#ifndef CGLM_LIB
{
  glm_vec3_clamp(v.raw, minVal, maxVal);
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
vec3s
glms_vec3_lerp(vec3s from, vec3s to, float t) CGLM_ENDD
#ifndef CGLM_LIB
{
  vec3s r;
  glm_vec3_lerp(from.raw, to.raw, t, r.raw);
  return r;
}
#endif

/*!
 * @brief linear interpolation between two vectors (clamped)
 *
 * formula:  from + s * (to - from)
 *
 * @param[in]   from  from value
 * @param[in]   to    to value
 * @param[in]   t     interpolant (amount) clamped between 0 and 1
 * @returns           destination
 */
CGLM_DECL
vec3s
glms_vec3_lerpc(vec3s from, vec3s to, float t) CGLM_ENDD
#ifndef CGLM_LIB
{
  vec3s r;
  glm_vec3_lerpc(from.raw, to.raw, t, r.raw);
  return r;
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
vec3s
glms_vec3_mix(vec3s from, vec3s to, float t) CGLM_ENDD
#ifndef CGLM_LIB
{
  vec3s r;
  glm_vec3_mix(from.raw, to.raw, t, r.raw);
  return r;
}
#endif

/*!
 * @brief linear interpolation between two vectors (clamped)
 *
 * formula:  from + s * (to - from)
 *
 * @param[in]   from  from value
 * @param[in]   to    to value
 * @param[in]   t     interpolant (amount) clamped between 0 and 1
 * @returns           destination
 */
CGLM_DECL
vec3s
glms_vec3_mixc(vec3s from, vec3s to, float t) CGLM_ENDD
#ifndef CGLM_LIB
{
  vec3s r;
  glm_vec3_mixc(from.raw, to.raw, t, r.raw);
  return r;
}
#endif

/*!
 * @brief threshold function (unidimensional)
 *
 * @param[in]   edge    threshold
 * @param[in]   x       value to test against threshold
 * @returns             0.0 if x < edge, else 1.0
 */
CGLM_DECL
vec3s
glms_vec3_step_uni(float edge, vec3s x) CGLM_ENDD
#ifndef CGLM_LIB
{
  vec3s r;
  glm_vec3_step_uni(edge, x.raw, r.raw);
  return r;
}
#endif

/*!
 * @brief threshold function
 *
 * @param[in]   edge    threshold
 * @param[in]   x       value to test against threshold
 * @returns             0.0 if x < edge, else 1.0
 */
CGLM_DECL
vec3s
glms_vec3_step(vec3s edge, vec3s x) CGLM_ENDD
#ifndef CGLM_LIB
{
  vec3s r;
  glm_vec3_step(edge.raw, x.raw, r.raw);
  return r;
}
#endif

/*!
 * @brief threshold function with a smooth transition (unidimensional)
 *
 * @param[in]   edge0   low threshold
 * @param[in]   edge1   high threshold
 * @param[in]   x       value to test against threshold
 * @returns             destination
 */
CGLM_DECL
vec3s
glms_vec3_smoothstep_uni(float edge0, float edge1, vec3s x) CGLM_ENDD
#ifndef CGLM_LIB
{
  vec3s r;
  glm_vec3_smoothstep_uni(edge0, edge1, x.raw, r.raw);
  return r;
}
#endif

/*!
 * @brief threshold function with a smooth transition
 *
 * @param[in]   edge0   low threshold
 * @param[in]   edge1   high threshold
 * @param[in]   x       value to test against threshold
 * @returns             destination
 */
CGLM_DECL
vec3s
glms_vec3_smoothstep(vec3s edge0, vec3s edge1, vec3s x) CGLM_ENDD
#ifndef CGLM_LIB
{
  vec3s r;
  glm_vec3_smoothstep(edge0.raw, edge1.raw, x.raw, r.raw);
  return r;
}
#endif

/*!
 * @brief smooth Hermite interpolation between two vectors
 *
 * formula:  from + s * (to - from)
 *
 * @param[in]   from    from value
 * @param[in]   to      to value
 * @param[in]   t       interpolant (amount)
 * @returns             destination
 */
CGLM_DECL
vec3s
glms_vec3_smoothinterp(vec3s from, vec3s to, float t) CGLM_ENDD
#ifndef CGLM_LIB
{
  vec3s r;
  glm_vec3_smoothinterp(from.raw, to.raw, t, r.raw);
  return r;
}
#endif

/*!
 * @brief smooth Hermite interpolation between two vectors (clamped)
 *
 * formula:  from + s * (to - from)
 *
 * @param[in]   from    from value
 * @param[in]   to      to value
 * @param[in]   t       interpolant (amount) clamped between 0 and 1
 * @returns             destination
 */
CGLM_DECL
vec3s
glms_vec3_smoothinterpc(vec3s from, vec3s to, float t) CGLM_ENDD
#ifndef CGLM_LIB
{
  vec3s r;
  glm_vec3_smoothinterpc(from.raw, to.raw, t, r.raw);
  return r;
}
#endif

/*!
 * @brief vec3 cross product
 *
 * this is just convenient wrapper
 *
 * @param[in]  a  source 1
 * @param[in]  b  source 2
 * @returns       destination
 */
CGLM_DECL
vec3s
glms_cross(vec3s a, vec3s b) CGLM_ENDD
#ifndef CGLM_LIB
{
  vec3s r;
  glm_cross(a.raw, b.raw, r.raw);
  return r;
}
#endif

/*!
 * @brief vec3 dot product
 *
 * this is just convenient wrapper
 *
 * @param[in] a vector1
 * @param[in] b vector2
 * @return      dot product
 */
CGLM_DECL
float
glms_dot(vec3s a, vec3s b) CGLM_ENDD
#ifndef CGLM_LIB
{
  return glm_dot(a.raw, b.raw);
}
#endif

/*!
 * @brief normalize vec3 and store result in same vec
 *
 * this is just convenient wrapper
 *
 * @param[in]   v   vector
 * @returns         normalized vector
 */
CGLM_DECL
vec3s
glms_normalize(vec3s v) CGLM_ENDD
#ifndef CGLM_LIB
{
  glm_normalize(v.raw);
  return v;
}
#endif

/*!
 * @brief swizzle vector components
 *
 * you can use existin masks e.g. GLM_XXX, GLM_ZYX
 *
 * @param[in]  v    source
 * @param[in]  mask mask
 * @returns swizzled vector
 */
CGLM_DECL
vec3s
glms_vec3_swizzle(vec3s v, int mask) CGLM_ENDD
#ifndef CGLM_LIB
{
  vec3s dest;
  glm_vec3_swizzle(v.raw, mask, dest.raw);
  return dest;
}
#endif

#endif /* cglms_vec3s_h */
