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
   CGLM_INLINE vec2s glms_vec2(vec3s v3)
   CGLM_INLINE void  glms_vec2_pack(vec2s dst[], vec2 src[], size_t len)
   CGLM_INLINE void  glms_vec2_unpack(vec2 dst[], vec2s src[], size_t len)
   CGLM_INLINE vec2s glms_vec2_zero(void)
   CGLM_INLINE vec2s glms_vec2_one(void)
   CGLM_INLINE float glms_vec2_dot(vec2s a, vec2s b)
   CGLM_INLINE float glms_vec2_cross(vec2s a, vec2s b)
   CGLM_INLINE float glms_vec2_norm2(vec2s v)
   CGLM_INLINE float glms_vec2_norm(vec2s v)
   CGLM_INLINE vec2s glms_vec2_add(vec2s a, vec2s b)
   CGLM_INLINE vec2s glms_vec2_adds(vec2s a, float s)
   CGLM_INLINE vec2s glms_vec2_sub(vec2s a, vec2s b)
   CGLM_INLINE vec2s glms_vec2_subs(vec2s a, float s)
   CGLM_INLINE vec2s glms_vec2_mul(vec2s a, vec2s b)
   CGLM_INLINE vec2s glms_vec2_scale(vec2s v, float s)
   CGLM_INLINE vec2s glms_vec2_scale_as(vec2s v, float s)
   CGLM_INLINE vec2s glms_vec2_div(vec2s a, vec2s b)
   CGLM_INLINE vec2s glms_vec2_divs(vec2s a, float s)
   CGLM_INLINE vec2s glms_vec2_addadd(vec2s a, vec2s b, vec2s dest)
   CGLM_INLINE vec2s glms_vec2_subadd(vec2s a, vec2s b, vec2s dest)
   CGLM_INLINE vec2s glms_vec2_muladd(vec2s a, vec2s b, vec2s dest)
   CGLM_INLINE vec2s glms_vec2_muladds(vec2s a, float s, vec2s dest)
   CGLM_INLINE vec2s glms_vec2_maxadd(vec2s a, vec2s b, vec2s dest)
   CGLM_INLINE vec2s glms_vec2_minadd(vec2s a, vec2s b, vec2s dest)
   CGLM_INLINE vec2s glms_vec2_subsub(vec2s a, vec2s b, vec2s dest)
   CGLM_INLINE vec2s glms_vec2_addsub(vec2s a, vec2s b, vec2s dest)
   CGLM_INLINE vec2s glms_vec2_mulsub(vec2s a, vec2s b, vec2s dest)
   CGLM_INLINE vec2s glms_vec2_mulsubs(vec2s a, float s, vec2s dest)
   CGLM_INLINE vec2s glms_vec2_maxsub(vec2s a, vec2s b, vec2s dest)
   CGLM_INLINE vec2s glms_vec2_minsub(vec2s a, vec2s b, vec2s dest)
   CGLM_INLINE vec2s glms_vec2_negate(vec2s v)
   CGLM_INLINE vec2s glms_vec2_normalize(vec2s v)
   CGLM_INLINE vec2s glms_vec2_rotate(vec2s v, float angle, vec2s axis)
   CGLM_INLINE vec2s glms_vec2_center(vec2s a, vec2s b)
   CGLM_INLINE float glms_vec2_distance(vec2s a, vec2s b)
   CGLM_INLINE float glms_vec2_distance2(vec2s a, vec2s b)
   CGLM_INLINE vec2s glms_vec2_maxv(vec2s a, vec2s b)
   CGLM_INLINE vec2s glms_vec2_minv(vec2s a, vec2s b)
   CGLM_INLINE vec2s glms_vec2_clamp(vec2s v, float minVal, float maxVal)
   CGLM_INLINE vec2s glms_vec2_lerp(vec2s from, vec2s to, float t)
   CGLM_INLINE vec2s glms_vec2_step(vec2s edge, vec2s x)
   CGLM_INLINE vec2s glms_vec2_make(float * restrict src)
   CGLM_INLINE vec2s glms_vec2_reflect(vec2s v, vec2s n)
   CGLM_INLINE bool  glms_vec2_refract(vec2s v, vec2s n, float eta, vec2s *dest)
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
CGLM_INLINE
vec2s
glms_vec2(vec3s v3) {
  vec2s r;
  glm_vec2(v3.raw, r.raw);
  return r;
}

/*!
 * @brief pack an array of vec2 into an array of vec2s
 *
 * @param[out] dst array of vec2
 * @param[in]  src array of vec2s
 * @param[in]  len number of elements
 */
CGLM_INLINE
void
glms_vec2_(pack)(vec2s dst[], vec2 src[], size_t len) {
  size_t i;

  for (i = 0; i < len; i++) {
    glm_vec2_copy(src[i], dst[i].raw);
  }
}

/*!
 * @brief unpack an array of vec2s into an array of vec2
 *
 * @param[out] dst array of vec2s
 * @param[in]  src array of vec2
 * @param[in]  len number of elements
 */
CGLM_INLINE
void
glms_vec2_(unpack)(vec2 dst[], vec2s src[], size_t len) {
  size_t i;

  for (i = 0; i < len; i++) {
    glm_vec2_copy(src[i].raw, dst[i]);
  }
}

/*!
 * @brief make vector zero
 *
 * @returns zero vector
 */
CGLM_INLINE
vec2s
glms_vec2_(zero)(void) {
  vec2s r;
  glm_vec2_zero(r.raw);
  return r;
}

/*!
 * @brief make vector one
 *
 * @returns one vector
 */
CGLM_INLINE
vec2s
glms_vec2_(one)(void) {
  vec2s r;
  glm_vec2_one(r.raw);
  return r;
}

/*!
 * @brief vec2 dot product
 *
 * @param[in] a vector1
 * @param[in] b vector2
 *
 * @return dot product
 */
CGLM_INLINE
float
glms_vec2_(dot)(vec2s a, vec2s b) {
  return glm_vec2_dot(a.raw, b.raw);
}

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
CGLM_INLINE
float
glms_vec2_(cross)(vec2s a, vec2s b) {
  return glm_vec2_cross(a.raw, b.raw);
}

/*!
 * @brief norm * norm (magnitude) of vec
 *
 * we can use this func instead of calling norm * norm, because it would call
 * sqrtf function twice but with this func we can avoid func call, maybe this is
 * not good name for this func
 *
 * @param[in] v vector
 *
 * @return norm * norm
 */
CGLM_INLINE
float
glms_vec2_(norm2)(vec2s v) {
  return glm_vec2_norm2(v.raw);
}

/*!
 * @brief norm (magnitude) of vec2
 *
 * @param[in] v vector
 *
 * @return norm
 */
CGLM_INLINE
float
glms_vec2_(norm)(vec2s v) {
  return glm_vec2_norm(v.raw);
}

/*!
 * @brief add a vector to b vector store result in dest
 *
 * @param[in]  a    vector1
 * @param[in]  b    vector2
 * @returns         destination vector
 */
CGLM_INLINE
vec2s
glms_vec2_(add)(vec2s a, vec2s b) {
  vec2s r;
  glm_vec2_add(a.raw, b.raw, r.raw);
  return r;
}

/*!
 * @brief add scalar to v vector store result in dest (d = v + s)
 *
 * @param[in]  a    vector
 * @param[in]  s    scalar
 * @returns         destination vector
 */
CGLM_INLINE
vec2s
glms_vec2_(adds)(vec2s a, float s) {
  vec2s r;
  glm_vec2_adds(a.raw, s, r.raw);
  return r;
}

/*!
 * @brief subtract b vector from a vector store result in dest
 *
 * @param[in]  a    vector1
 * @param[in]  b    vector2
 * @returns         destination vector
 */
CGLM_INLINE
vec2s
glms_vec2_(sub)(vec2s a, vec2s b) {
  vec2s r;
  glm_vec2_sub(a.raw, b.raw, r.raw);
  return r;
}

/*!
 * @brief subtract scalar from v vector store result in dest (d = v - s)
 *
 * @param[in]  a    vector
 * @param[in]  s    scalar
 * @returns         destination vector
 */
CGLM_INLINE
vec2s
glms_vec2_(subs)(vec2s a, float s) {
  vec2s r;
  glm_vec2_subs(a.raw, s, r.raw);
  return r;
}

/*!
 * @brief multiply two vectors (component-wise multiplication)
 *
 * @param     a     vector1
 * @param     b     vector2
 * @returns         result = (a[0] * b[0], a[1] * b[1])
 */
CGLM_INLINE
vec2s
glms_vec2_(mul)(vec2s a, vec2s b) {
  vec2s r;
  glm_vec2_mul(a.raw, b.raw, r.raw);
  return r;
}

/*!
 * @brief multiply/scale vec2 vector with scalar: result = v * s
 *
 * @param[in]  v    vector
 * @param[in]  s    scalar
 * @returns         destination vector
 */
CGLM_INLINE
vec2s
glms_vec2_(scale)(vec2s v, float s) {
  vec2s r;
  glm_vec2_scale(v.raw, s, r.raw);
  return r;
}

/*!
 * @brief make vec2 vector scale as specified: result = unit(v) * s
 *
 * @param[in]  v    vector
 * @param[in]  s    scalar
 * @returns         destination vector
 */
CGLM_INLINE
vec2s
glms_vec2_(scale_as)(vec2s v, float s) {
  vec2s r;
  glm_vec2_scale_as(v.raw, s, r.raw);
  return r;
}

/*!
 * @brief div vector with another component-wise division: d = a / b
 *
 * @param[in]  a    vector 1
 * @param[in]  b    vector 2
 * @returns         result = (a[0]/b[0], a[1]/b[1])
 */
CGLM_INLINE
vec2s
glms_vec2_(div)(vec2s a, vec2s b) {
  vec2s r;
  glm_vec2_div(a.raw, b.raw, r.raw);
  return r;
}

/*!
 * @brief div vector with scalar: d = v / s
 *
 * @param[in]  a    vector
 * @param[in]  s    scalar
 * @returns         result = (a[0]/s, a[1]/s)
 */
CGLM_INLINE
vec2s
glms_vec2_(divs)(vec2s a, float s) {
  vec2s r;
  glm_vec2_divs(a.raw, s, r.raw);
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
vec2s
glms_vec2_(addadd)(vec2s a, vec2s b, vec2s dest) {
  glm_vec2_addadd(a.raw, b.raw, dest.raw);
  return dest;
}

/*!
 * @brief sub two vectors and add result to dest
 *
 * it applies += operator so dest must be initialized
 *
 * @param[in]  a    vector 1
 * @param[in]  b    vector 2
 * @returns         dest += (a + b)
 */
CGLM_INLINE
vec2s
glms_vec2_(subadd)(vec2s a, vec2s b, vec2s dest) {
  glm_vec2_subadd(a.raw, b.raw, dest.raw);
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
vec2s
glms_vec2_(muladd)(vec2s a, vec2s b, vec2s dest) {
  glm_vec2_muladd(a.raw, b.raw, dest.raw);
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
vec2s
glms_vec2_(muladds)(vec2s a, float s, vec2s dest) {
  glm_vec2_muladds(a.raw, s, dest.raw);
  return dest;
}

/*!
 * @brief add max of two vectors to result/dest
 *
 * it applies += operator so dest must be initialized
 *
 * @param[in]  a    vector 1
 * @param[in]  b    vector 2
 * @returns         dest += max(a, b)
 */
CGLM_INLINE
vec2s
glms_vec2_(maxadd)(vec2s a, vec2s b, vec2s dest) {
  glm_vec2_maxadd(a.raw, b.raw, dest.raw);
  return dest;
}

/*!
 * @brief add min of two vectors to result/dest
 *
 * it applies += operator so dest must be initialized
 *
 * @param[in]  a    vector 1
 * @param[in]  b    vector 2
 * @returns         dest += min(a, b)
 */
CGLM_INLINE
vec2s
glms_vec2_(minadd)(vec2s a, vec2s b, vec2s dest) {
  glm_vec2_minadd(a.raw, b.raw, dest.raw);
  return dest;
}

/*!
 * @brief sub two vectors and sub result to dest
 *
 * it applies -= operator so dest must be initialized
 *
 * @param[in]  a    vector 1
 * @param[in]  b    vector 2
 * @returns         dest -= (a - b)
 */
CGLM_INLINE
vec2s
glms_vec2_(subsub)(vec2s a, vec2s b, vec2s dest) {
  glm_vec2_subsub(a.raw, b.raw, dest.raw);
  return dest;
}

/*!
 * @brief add two vectors and sub result to dest
 *
 * it applies -= operator so dest must be initialized
 *
 * @param[in]  a    vector 1
 * @param[in]  b    vector 2
 * @returns         dest -= (a + b)
 */
CGLM_INLINE
vec2s
glms_vec2_(addsub)(vec2s a, vec2s b, vec2s dest) {
  glm_vec2_addsub(a.raw, b.raw, dest.raw);
  return dest;
}

/*!
 * @brief mul two vectors and sub result to dest
 *
 * it applies -= operator so dest must be initialized
 *
 * @param[in]  a    vector 1
 * @param[in]  b    vector 2
 * @returns         dest -= (a * b)
 */
CGLM_INLINE
vec2s
glms_vec2_(mulsub)(vec2s a, vec2s b, vec2s dest) {
  glm_vec2_mulsub(a.raw, b.raw, dest.raw);
  return dest;
}

/*!
 * @brief mul vector with scalar and sub result to dest
 *
 * it applies -= operator so dest must be initialized
 *
 * @param[in]  a    vector
 * @param[in]  s    scalar
 * @returns         dest -= (a * b)
 */
CGLM_INLINE
vec2s
glms_vec2_(mulsubs)(vec2s a, float s, vec2s dest) {
  glm_vec2_mulsubs(a.raw, s, dest.raw);
  return dest;
}

/*!
 * @brief sub max of two vectors to dest
 *
 * it applies += operator so dest must be initialized
 *
 * @param[in]  a    vector 1
 * @param[in]  b    vector 2
 * @returns         dest -= max(a, b)
 */
CGLM_INLINE
vec2s
glms_vec2_(maxsub)(vec2s a, vec2s b, vec2s dest) {
  glm_vec2_maxsub(a.raw, b.raw, dest.raw);
  return dest;
}

/*!
 * @brief sub min of two vectors to dest
 *
 * it applies -= operator so dest must be initialized
 *
 * @param[in]  a    vector 1
 * @param[in]  b    vector 2
 * @returns         dest -= min(a, b)
 */
CGLM_INLINE
vec2s
glms_vec2_(minsub)(vec2s a, vec2s b, vec2s dest) {
  glm_vec2_minsub(a.raw, b.raw, dest.raw);
  return dest;
}

/*!
 * @brief negate vector components
 *
 * @param[in]  v  vector
 * @returns       negated vector
 */
CGLM_INLINE
vec2s
glms_vec2_(negate)(vec2s v) {
  glm_vec2_negate(v.raw);
  return v;
}

/*!
 * @brief normalize vec2 and store result in same vec
 *
 * @param[in] v vector
 * @returns     normalized vector
 */
CGLM_INLINE
vec2s
glms_vec2_(normalize)(vec2s v) {
  glm_vec2_normalize(v.raw);
  return v;
}

/*!
 * @brief rotate vec2 by angle using Rodrigues' rotation formula
 *
 * @param[in]     v     vector
 * @param[in]     angle angle by radians
 * @returns             rotated vector
 */
CGLM_INLINE
vec2s
glms_vec2_(rotate)(vec2s v, float angle) {
  vec2s r;
  glm_vec2_rotate(v.raw, angle, r.raw);
  return r;
}

/**
 * @brief find center point of two vector
 *
 * @param[in]  a    vector1
 * @param[in]  b    vector2
 * @returns         center point
 */
CGLM_INLINE
vec2s
glms_vec2_(center)(vec2s a, vec2s b) {
  vec2s r;
  glm_vec2_center(a.raw, b.raw, r.raw);
  return r;
}

/**
 * @brief distance between two vectors
 *
 * @param[in] a vector1
 * @param[in] b vector2
 * @return      distance
 */
CGLM_INLINE
float
glms_vec2_(distance)(vec2s a, vec2s b) {
  return glm_vec2_distance(a.raw, b.raw);
}

/**
 * @brief squared distance between two vectors
 *
 * @param[in] a vector1
 * @param[in] b vector2
 * @return      squared distance (distance * distance)
 */
CGLM_INLINE
float
glms_vec2_(distance2)(vec2s a, vec2s b) {
  return glm_vec2_distance2(a.raw, b.raw);
}

/*!
 * @brief max values of vectors
 *
 * @param[in]  a    vector1
 * @param[in]  b    vector2
 * @returns         destination
 */
CGLM_INLINE
vec2s
glms_vec2_(maxv)(vec2s a, vec2s b) {
  vec2s r;
  glm_vec2_maxv(a.raw, b.raw, r.raw);
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
vec2s
glms_vec2_(minv)(vec2s a, vec2s b) {
  vec2s r;
  glm_vec2_minv(a.raw, b.raw, r.raw);
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
vec2s
glms_vec2_(clamp)(vec2s v, float minVal, float maxVal) {
  glm_vec2_clamp(v.raw, minVal, maxVal);
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
vec2s
glms_vec2_(lerp)(vec2s from, vec2s to, float t) {
  vec2s r;
  glm_vec2_lerp(from.raw, to.raw, t, r.raw);
  return r;
}

/*!
 * @brief threshold function
 *
 * @param[in]   edge    threshold
 * @param[in]   x       value to test against threshold
 * @returns             destination
 */
CGLM_INLINE
vec2s
glms_vec2_(step)(vec2s edge, vec2s x) {
  vec2s r;
  glm_vec2_step(edge.raw, x.raw, r.raw);
  return r;
}

/*!
 * @brief Create two dimensional vector from pointer
 *
 * @param[in]  src  pointer to an array of floats
 * @returns constructed 2D vector from raw pointer
 */
CGLM_INLINE
vec2s
glms_vec2_(make)(const float * __restrict src) {
  vec2s dest;
  glm_vec2_make(src, dest.raw);
  return dest;
}

/*!
 * @brief reflection vector using an incident ray and a surface normal
 *
 * @param[in]  I    incident vector
 * @param[in]  N    normalized normal vector
 * @returns reflection result
 */
CGLM_INLINE
vec2s
glms_vec2_(reflect)(vec2s v, vec2s n) {
  vec2s dest;
  glm_vec2_reflect(v.raw, n.raw, dest.raw);
  return dest;
}

/*!
 * @brief computes refraction vector for an incident vector and a surface normal.
 *
 * calculates the refraction vector based on Snell's law. If total internal reflection
 * occurs (angle too great given eta), dest is set to zero and returns false.
 * Otherwise, computes refraction vector, stores it in dest, and returns true.
 *
 * @param[in]  v    normalized incident vector
 * @param[in]  n    normalized normal vector
 * @param[in]  eta  ratio of indices of refraction (incident/transmitted)
 * @param[out] dest refraction vector if refraction occurs; zero vector otherwise
 *
 * @returns true if refraction occurs; false if total internal reflection occurs.
 */
CGLM_INLINE
bool
glms_vec2_(refract)(vec2s v, vec2s n, float eta, vec2s * __restrict dest) {
  return glm_vec2_refract(v.raw, n.raw, eta, dest->raw);
}

#endif /* cglms_vec2s_h */
