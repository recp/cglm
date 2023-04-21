/*
 * Copyright (c), Recep Aslantas.
 *
 * MIT License (MIT), http://opensource.org/licenses/MIT
 * Full license can be found in the LICENSE file
 */

/*
 Macros:
   GLMS_VEC4_ONE_INIT
   GLMS_VEC4_BLACK_INIT
   GLMS_VEC4_ZERO_INIT
   GLMS_VEC4_ONE
   GLMS_VEC4_BLACK
   GLMS_VEC4_ZERO

 Functions:
   CGLM_INLINE vec4s glms_vec4(vec3s v3, float last);
   CGLM_INLINE vec3s glms_vec4_copy3(vec4s v);
   CGLM_INLINE vec4s glms_vec4_copy(vec4s v);
   CGLM_INLINE vec4s glms_vec4_ucopy(vec4s v);
   CGLM_INLINE void  glms_vec4_pack(vec4s dst[], vec4 src[], size_t len);
   CGLM_INLINE void  glms_vec4_unpack(vec4 dst[], vec4s src[], size_t len);
   CGLM_INLINE float glms_vec4_dot(vec4s a, vec4s b);
   CGLM_INLINE float glms_vec4_norm2(vec4s v);
   CGLM_INLINE float glms_vec4_norm(vec4s v);
   CGLM_INLINE float glms_vec4_norm_one(vec4s v);
   CGLM_INLINE float glms_vec4_norm_inf(vec4s v);
   CGLM_INLINE vec4s glms_vec4_add(vec4s a, vec4s b);
   CGLM_INLINE vec4s glms_vec4_adds(vec4s v, float s);
   CGLM_INLINE vec4s glms_vec4_sub(vec4s a, vec4s b);
   CGLM_INLINE vec4s glms_vec4_subs(vec4s v, float s);
   CGLM_INLINE vec4s glms_vec4_mul(vec4s a, vec4s b);
   CGLM_INLINE vec4s glms_vec4_scale(vec4s v, float s);
   CGLM_INLINE vec4s glms_vec4_scale_as(vec4s v, float s);
   CGLM_INLINE vec4s glms_vec4_div(vec4s a, vec4s b);
   CGLM_INLINE vec4s glms_vec4_divs(vec4s v, float s);
   CGLM_INLINE vec4s glms_vec4_addadd(vec4s a, vec4s b, vec4s dest);
   CGLM_INLINE vec4s glms_vec4_subadd(vec4s a, vec4s b, vec4s dest);
   CGLM_INLINE vec4s glms_vec4_muladd(vec4s a, vec4s b, vec4s dest);
   CGLM_INLINE vec4s glms_vec4_muladds(vec4s a, float s, vec4s dest);
   CGLM_INLINE vec4s glms_vec4_maxadd(vec4s a, vec4s b, vec4s dest);
   CGLM_INLINE vec4s glms_vec4_minadd(vec4s a, vec4s b, vec4s dest);
   CGLM_INLINE vec4s glms_vec4_negate(vec4s v);
   CGLM_INLINE vec4s glms_vec4_inv(vec4s v);
   CGLM_INLINE vec4s glms_vec4_normalize(vec4s v);
   CGLM_INLINE float glms_vec4_distance(vec4s a, vec4s b);
   CGLM_INLINE float glms_vec4_distance2(vec4s a, vec4s b);
   CGLM_INLINE vec4s glms_vec4_maxv(vec4s a, vec4s b);
   CGLM_INLINE vec4s glms_vec4_minv(vec4s a, vec4s b);
   CGLM_INLINE vec4s glms_vec4_clamp(vec4s v, float minVal, float maxVal);
   CGLM_INLINE vec4s glms_vec4_lerp(vec4s from, vec4s to, float t);
   CGLM_INLINE vec4s glms_vec4_lerpc(vec4s from, vec4s to, float t);
   CGLM_INLINE vec4s glms_vec4_mix(vec4s from, vec4s to, float t);
   CGLM_INLINE vec4s glms_vec4_mixc(vec4s from, vec4s to, float t);
   CGLM_INLINE vec4s glms_vec4_step_uni(float edge, vec4s x);
   CGLM_INLINE vec4s glms_vec4_step(vec4s edge, vec4s x);
   CGLM_INLINE vec4s glms_vec4_smoothstep_uni(float edge0, float edge1, vec4s x);
   CGLM_INLINE vec4s glms_vec4_smoothstep(vec4s edge0, vec4s edge1, vec4s x);
   CGLM_INLINE vec4s glms_vec4_smoothinterp(vec4s from, vec4s to, float t);
   CGLM_INLINE vec4s glms_vec4_smoothinterpc(vec4s from, vec4s to, float t);
   CGLM_INLINE vec4s glms_vec4_cubic(float s);
   CGLM_INLINE vec4s glms_vec4_swizzle(vec4s v, int mask);
 */

#ifndef cglms_vec4s_h
#define cglms_vec4s_h

#include "../common.h"
#include "../types-struct.h"
#include "../util.h"
#include "../vec4.h"
#include "vec4-ext.h"

#define GLMS_VEC4_ONE_INIT   {GLM_VEC4_ONE_INIT}
#define GLMS_VEC4_BLACK_INIT {GLM_VEC4_BLACK_INIT}
#define GLMS_VEC4_ZERO_INIT  {GLM_VEC4_ZERO_INIT}

#define GLMS_VEC4_ONE        ((vec4s)GLM_VEC4_ONE_INIT)
#define GLMS_VEC4_BLACK      ((vec4s)GLM_VEC4_BLACK_INIT)
#define GLMS_VEC4_ZERO       ((vec4s)GLM_VEC4_ZERO_INIT)

/*!
 * @brief init vec4 using vec3
 *
 * @param[in]  v3   vector3
 * @param[in]  last last item
 * @returns         destination
 */
CGLM_INLINE
vec4s
glms_vec4(vec3s v3, float last) {
  vec4s r;
  glm_vec4(v3.raw, last, r.raw);
  return r;
}

/*!
 * @brief copy first 3 members of [a] to [dest]
 *
 * @param[in]  v    source
 * @returns         vec3
 */
CGLM_INLINE
vec3s
glms_vec4_(copy3)(vec4s v) {
  vec3s r;
  glm_vec4_copy3(v.raw, r.raw);
  return r;
}

/*!
 * @brief copy all members of [a] to [dest]
 *
 * @param[in]  v    source
 * @returns         destination
 */
CGLM_INLINE
vec4s
glms_vec4_(copy)(vec4s v) {
  vec4s r;
  glm_vec4_copy(v.raw, r.raw);
  return r;
}

/*!
 * @brief copy all members of [a] to [dest]
 *
 * alignment is not required
 *
 * @param[in]  v    source
 * @returns         destination
 */
CGLM_INLINE
vec4s
glms_vec4_(ucopy)(vec4s v) {
  vec4s r;
  glm_vec4_ucopy(v.raw, r.raw);
  return r;
}

/*!
 * @brief pack an array of vec4 into an array of vec4s
 *
 * @param[out] dst array of vec4
 * @param[in]  src array of vec4s
 * @param[in]  len number of elements
 */
CGLM_INLINE
void
glms_vec4_(pack)(vec4s dst[], vec4 src[], size_t len) {
  size_t i;

  for (i = 0; i < len; i++) {
    glm_vec4_copy(src[i], dst[i].raw);
  }
}

/*!
 * @brief unpack an array of vec4s into an array of vec4
 *
 * @param[out] dst array of vec4s
 * @param[in]  src array of vec4
 * @param[in]  len number of elements
 */
CGLM_INLINE
void
glms_vec4_(unpack)(vec4 dst[], vec4s src[], size_t len) {
  size_t i;

  for (i = 0; i < len; i++) {
    glm_vec4_copy(src[i].raw, dst[i]);
  }
}

/*!
 * @brief make vector zero
 *
 * @returns      zero vector
 */
CGLM_INLINE
vec4s
glms_vec4_(zero)(void) {
  vec4s r;
  glm_vec4_zero(r.raw);
  return r;
}

/*!
 * @brief make vector one
 *
 * @returns      one vector
 */
CGLM_INLINE
vec4s
glms_vec4_(one)(void) {
  vec4s r;
  glm_vec4_one(r.raw);
  return r;
}

/*!
 * @brief vec4 dot product
 *
 * @param[in] a vector1
 * @param[in] b vector2
 *
 * @return dot product
 */
CGLM_INLINE
float
glms_vec4_(dot)(vec4s a, vec4s b) {
  return glm_vec4_dot(a.raw, b.raw);
}

/*!
 * @brief norm * norm (magnitude) of vec
 *
 * we can use this func instead of calling norm * norm, because it would call
 * sqrtf fuction twice but with this func we can avoid func call, maybe this is
 * not good name for this func
 *
 * @param[in] v vec4
 *
 * @return norm * norm
 */
CGLM_INLINE
float
glms_vec4_(norm2)(vec4s v) {
  return glm_vec4_norm2(v.raw);
}

/*!
 * @brief norm (magnitude) of vec4
 *
 * @param[in] v vector
 *
 * @return norm
 */
CGLM_INLINE
float
glms_vec4_(norm)(vec4s v) {
  return glm_vec4_norm(v.raw);
}

/*!
 * @brief L1 norm of vec4
 * Also known as Manhattan Distance or Taxicab norm.
 * L1 Norm is the sum of the magnitudes of the vectors in a space.
 * It is calculated as the sum of the absolute values of the vector components.
 * In this norm, all the components of the vector are weighted equally.
 *
 * This computes:
 * R = |v[0]| + |v[1]| + |v[2]| + |v[3]|
 *
 * @param[in] v vector
 *
 * @return L1 norm
 */
CGLM_INLINE
float
glms_vec4_(norm_one)(vec4s v) {
  return glm_vec4_norm_one(v.raw);
}

/*!
 * @brief Infinity norm of vec4
 * Also known as Maximum norm.
 * Infinity Norm is the largest magnitude among each element of a vector.
 * It is calculated as the maximum of the absolute values of the vector components.
 *
 * This computes:
 * inf norm = max(|v[0]|, |v[1]|, |v[2]|, |v[3]|)
 *
 * @param[in] v vector
 *
 * @return Infinity norm
 */
CGLM_INLINE
float
glms_vec4_(norm_inf)(vec4s v) {
  return glm_vec4_norm_inf(v.raw);
}

/*!
 * @brief add b vector to a vector store result in dest
 *
 * @param[in]  a    vector1
 * @param[in]  b    vector2
 * @returns         destination vector
 */
CGLM_INLINE
vec4s
glms_vec4_(add)(vec4s a, vec4s b) {
  vec4s r;
  glm_vec4_add(a.raw, b.raw, r.raw);
  return r;
}

/*!
 * @brief add scalar to v vector store result in dest (d = v + vec(s))
 *
 * @param[in]  v    vector
 * @param[in]  s    scalar
 * @returns         destination vector
 */
CGLM_INLINE
vec4s
glms_vec4_(adds)(vec4s v, float s) {
  vec4s r;
  glm_vec4_adds(v.raw, s, r.raw);
  return r;
}

/*!
 * @brief subtract b vector from a vector store result in dest (d = a - b)
 *
 * @param[in]  a    vector1
 * @param[in]  b    vector2
 * @returns         destination vector
 */
CGLM_INLINE
vec4s
glms_vec4_(sub)(vec4s a, vec4s b) {
  vec4s r;
  glm_vec4_sub(a.raw, b.raw, r.raw);
  return r;
}

/*!
 * @brief subtract scalar from v vector store result in dest (d = v - vec(s))
 *
 * @param[in]  v    vector
 * @param[in]  s    scalar
 * @returns         destination vector
 */
CGLM_INLINE
vec4s
glms_vec4_(subs)(vec4s v, float s) {
  vec4s r;
  glm_vec4_subs(v.raw, s, r.raw);
  return r;
}

/*!
 * @brief multiply two vector (component-wise multiplication)
 *
 * @param a    vector1
 * @param b    vector2
 * @returns    dest = (a[0] * b[0], a[1] * b[1], a[2] * b[2], a[3] * b[3])
 */
CGLM_INLINE
vec4s
glms_vec4_(mul)(vec4s a, vec4s b) {
  vec4s r;
  glm_vec4_mul(a.raw, b.raw, r.raw);
  return r;
}

/*!
 * @brief multiply/scale vec4 vector with scalar: result = v * s
 *
 * @param[in]  v    vector
 * @param[in]  s    scalar
 * @returns         destination vector
 */
CGLM_INLINE
vec4s
glms_vec4_(scale)(vec4s v, float s) {
  vec4s r;
  glm_vec4_scale(v.raw, s, r.raw);
  return r;
}

/*!
 * @brief make vec4 vector scale as specified: result = unit(v) * s
 *
 * @param[in]  v    vector
 * @param[in]  s    scalar
 * @returns         destination vector
 */
CGLM_INLINE
vec4s
glms_vec4_(scale_as)(vec4s v, float s) {
  vec4s r;
  glm_vec4_scale_as(v.raw, s, r.raw);
  return r;
}

/*!
 * @brief div vector with another component-wise division: d = a / b
 *
 * @param[in]  a    vector 1
 * @param[in]  b    vector 2
 * @returns         result = (a[0]/b[0], a[1]/b[1], a[2]/b[2], a[3]/b[3])
 */
CGLM_INLINE
vec4s
glms_vec4_(div)(vec4s a, vec4s b) {
  vec4s r;
  glm_vec4_div(a.raw, b.raw, r.raw);
  return r;
}

/*!
 * @brief div vec4 vector with scalar: d = v / s
 *
 * @param[in]  v    vector
 * @param[in]  s    scalar
 * @returns         destination vector
 */
CGLM_INLINE
vec4s
glms_vec4_(divs)(vec4s v, float s) {
  vec4s r;
  glm_vec4_divs(v.raw, s, r.raw);
  return r;
}

/*!
 * @brief add two vectors and add result to sum
 *
 * it applies += operator so dest must be initialized
 *
 * @param[in]  a    vector 1
 * @param[in]  b    vector 2
 * @returns         dest += (a + b)
 */
CGLM_INLINE
vec4s
glms_vec4_(addadd)(vec4s a, vec4s b, vec4s dest) {
  glm_vec4_addadd(a.raw, b.raw, dest.raw);
  return dest;
}

/*!
 * @brief sub two vectors and add result to dest
 *
 * it applies += operator so dest must be initialized
 *
 * @param[in]  a    vector 1
 * @param[in]  b    vector 2
 * @returns         dest += (a - b)
 */
CGLM_INLINE
vec4s
glms_vec4_(subadd)(vec4s a, vec4s b, vec4s dest) {
  glm_vec4_subadd(a.raw, b.raw, dest.raw);
  return dest;
}

/*!
 * @brief mul two vectors and add result to dest
 *
 * it applies += operator so dest must be initialized
 *
 * @param[in]  a    vector 1
 * @param[in]  b    vector 2
 * @returns         dest += (a * b)
 */
CGLM_INLINE
vec4s
glms_vec4_(muladd)(vec4s a, vec4s b, vec4s dest) {
  glm_vec4_muladd(a.raw, b.raw, dest.raw);
  return dest;
}

/*!
 * @brief mul vector with scalar and add result to sum
 *
 * it applies += operator so dest must be initialized
 *
 * @param[in]  a    vector
 * @param[in]  s    scalar
 * @returns         dest += (a * b)
 */
CGLM_INLINE
vec4s
glms_vec4_(muladds)(vec4s a, float s, vec4s dest) {
  glm_vec4_muladds(a.raw, s, dest.raw);
  return dest;
}

/*!
 * @brief add max of two vector to result/dest
 *
 * it applies += operator so dest must be initialized
 *
 * @param[in]  a    vector 1
 * @param[in]  b    vector 2
 * @returns         dest += max(a, b)
 */
CGLM_INLINE
vec4s
glms_vec4_(maxadd)(vec4s a, vec4s b, vec4s dest) {
  glm_vec4_maxadd(a.raw, b.raw, dest.raw);
  return dest;
}

/*!
 * @brief add min of two vector to result/dest
 *
 * it applies += operator so dest must be initialized
 *
 * @param[in]  a    vector 1
 * @param[in]  b    vector 2
 * @returns         dest += min(a, b)
 */
CGLM_INLINE
vec4s
glms_vec4_(minadd)(vec4s a, vec4s b, vec4s dest) {
  glm_vec4_minadd(a.raw, b.raw, dest.raw);
  return dest;
}

/*!
 * @brief negate vector components and store result in dest
 *
 * @param[in]  v     vector
 * @returns          result vector
 */
CGLM_INLINE
vec4s
glms_vec4_(negate)(vec4s v) {
  glm_vec4_negate(v.raw);
  return v;
}

/*!
 * @brief normalize vec4 and store result in same vec
 *
 * @param[in] v   vector
 * @returns       normalized vector
 */
CGLM_INLINE
vec4s
glms_vec4_(normalize)(vec4s v) {
  glm_vec4_normalize(v.raw);
  return v;
}

/**
 * @brief distance between two vectors
 *
 * @param[in] a vector1
 * @param[in] b vector2
 * @return returns distance
 */
CGLM_INLINE
float
glms_vec4_(distance)(vec4s a, vec4s b) {
  return glm_vec4_distance(a.raw, b.raw);
}

/**
 * @brief squared distance between two vectors
 *
 * @param[in] a vector1
 * @param[in] b vector2
 * @return returns squared distance
 */
CGLM_INLINE
float
glms_vec4_(distance2)(vec4s a, vec4s b) {
  return glm_vec4_distance2(a.raw, b.raw);
}

/*!
 * @brief max values of vectors
 *
 * @param[in]  a    vector1
 * @param[in]  b    vector2
 * @returns         destination
 */
CGLM_INLINE
vec4s
glms_vec4_(maxv)(vec4s a, vec4s b) {
  vec4s r;
  glm_vec4_maxv(a.raw, b.raw, r.raw);
  return r;
}

/*!
 * @brief min values of vectors
 *
 * @param[in]  a    vector1
 * @param[in]  b    vector2
 * @returns         destination
 */
CGLM_INLINE
vec4s
glms_vec4_(minv)(vec4s a, vec4s b) {
  vec4s r;
  glm_vec4_minv(a.raw, b.raw, r.raw);
  return r;
}

/*!
 * @brief clamp vector's individual members between min and max values
 *
 * @param[in]       v       vector
 * @param[in]       minVal  minimum value
 * @param[in]       maxVal  maximum value
 * @returns                 clamped vector
 */
CGLM_INLINE
vec4s
glms_vec4_(clamp)(vec4s v, float minVal, float maxVal) {
  glm_vec4_clamp(v.raw, minVal, maxVal);
  return v;
}

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
CGLM_INLINE
vec4s
glms_vec4_(lerp)(vec4s from, vec4s to, float t) {
  vec4s r;
  glm_vec4_lerp(from.raw, to.raw, t, r.raw);
  return r;
}

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
CGLM_INLINE
vec4s
glms_vec4_(lerpc)(vec4s from, vec4s to, float t) {
  vec4s r;
  glm_vec4_lerpc(from.raw, to.raw, t, r.raw);
  return r;
}

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
CGLM_INLINE
vec4s
glms_vec4_(mix)(vec4s from, vec4s to, float t) {
  vec4s r;
  glm_vec4_mix(from.raw, to.raw, t, r.raw);
  return r;
}

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
CGLM_INLINE
vec4s
glms_vec4_(mixc)(vec4s from, vec4s to, float t) {
  vec4s r;
  glm_vec4_mixc(from.raw, to.raw, t, r.raw);
  return r;
}

/*!
 * @brief threshold function (unidimensional)
 *
 * @param[in]   edge    threshold
 * @param[in]   x       value to test against threshold
 * @returns             0.0 if x < edge, else 1.0
 */
CGLM_INLINE
vec4s
glms_vec4_(step_uni)(float edge, vec4s x) {
  vec4s r;
  glm_vec4_step_uni(edge, x.raw, r.raw);
  return r;
}

/*!
 * @brief threshold function
 *
 * @param[in]   edge    threshold
 * @param[in]   x       value to test against threshold
 * @returns             0.0 if x < edge, else 1.0
 */
CGLM_INLINE
vec4s
glms_vec4_(step)(vec4s edge, vec4s x) {
  vec4s r;
  glm_vec4_step(edge.raw, x.raw, r.raw);
  return r;
}

/*!
 * @brief threshold function with a smooth transition (unidimensional)
 *
 * @param[in]   edge0   low threshold
 * @param[in]   edge1   high threshold
 * @param[in]   x       value to test against threshold
 * @returns             destination
 */
CGLM_INLINE
vec4s
glms_vec4_(smoothstep_uni)(float edge0, float edge1, vec4s x) {
  vec4s r;
  glm_vec4_smoothstep_uni(edge0, edge1, x.raw, r.raw);
  return r;
}

/*!
 * @brief threshold function with a smooth transition
 *
 * @param[in]   edge0   low threshold
 * @param[in]   edge1   high threshold
 * @param[in]   x       value to test against threshold
 * @returns             destination
 */
CGLM_INLINE
vec4s
glms_vec4_(smoothstep)(vec4s edge0, vec4s edge1, vec4s x) {
  vec4s r;
  glm_vec4_smoothstep(edge0.raw, edge1.raw, x.raw, r.raw);
  return r;
}

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
CGLM_INLINE
vec4s
glms_vec4_(smoothinterp)(vec4s from, vec4s to, float t) {
  vec4s r;
  glm_vec4_smoothinterp(from.raw, to.raw, t, r.raw);
  return r;
}

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
CGLM_INLINE
vec4s
glms_vec4_(smoothinterpc)(vec4s from, vec4s to, float t) {
  vec4s r;
  glm_vec4_smoothinterpc(from.raw, to.raw, t, r.raw);
  return r;
}

/*!
 * @brief helper to fill vec4 as [S^3, S^2, S, 1]
 *
 * @param[in]   s     parameter
 * @returns           destination
 */
CGLM_INLINE
vec4s
glms_vec4_(cubic)(float s) {
  vec4s r;
  glm_vec4_cubic(s, r.raw);
  return r;
}

/*!
 * @brief swizzle vector components
 *
 * you can use existin masks e.g. GLM_XXXX, GLM_WZYX
 *
 * @param[in]  v    source
 * @param[in]  mask mask
 * @returns swizzled vector
 */
CGLM_INLINE
vec4s
glms_vec4_(swizzle)(vec4s v, int mask) {
  vec4s dest;
  glm_vec4_swizzle(v.raw, mask, dest.raw);
  return dest;
}

#endif /* cglms_vec4s_h */
