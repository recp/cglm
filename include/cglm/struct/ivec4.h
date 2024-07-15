/*
 * Copyright (c), Recep Aslantas.
 *
 * MIT License (MIT), http://opensource.org/licenses/MIT
 * Full license can be found in the LICENSE file
 */

/*
 Macros:
  GLMS_IVEC4_ONE_INIT
  GLMS_IVEC4_ZERO_INIT
  GLMS_IVEC4_ONE
  GLMS_IVEC4_ZERO

 Functions:
  CGLM_INLINE ivec4s glms_ivec4(ivec3s v3, int last)
  CGLM_INLINE void glms_ivec4_pack(ivec4s dst[], ivec4 src[], size_t len)
  CGLM_INLINE void glms_ivec4_unpack(ivec4 dst[], ivec4s src[], size_t len)
  CGLM_INLINE ivec4s  glms_ivec4_zero(void)
  CGLM_INLINE ivec4s glms_ivec4_one(void)
  CGLM_INLINE ivec4s glms_ivec4_add(ivec4s a, ivec4s b)
  CGLM_INLINE ivec4s glms_ivec4_adds(ivec4s v, int s)
  CGLM_INLINE ivec4s glms_ivec4_sub(ivec4s a, ivec4s b)
  CGLM_INLINE ivec4s glms_ivec4_subs(ivec4s v, int s)
  CGLM_INLINE ivec4s glms_ivec4_mul(ivec4s a, ivec4s b)
  CGLM_INLINE ivec4s glms_ivec4_scale(ivec4s v, int s)
  CGLM_INLINE ivec4s glms_ivec4_addadd(ivec4s a, ivec4s b, ivec4s dest)
  CGLM_INLINE ivec4s glms_ivec4_addadds(ivec4s a, int s, ivec4s dest)
  CGLM_INLINE ivec4s glms_ivec4_subadd(ivec4s a, ivec4s b, ivec4s dest)
  CGLM_INLINE ivec4s glms_ivec4_subadds(ivec4s a, int s, ivec4s dest)
  CGLM_INLINE ivec4s glms_ivec4_muladd(ivec4s a, ivec4s b, ivec4s dest)
  CGLM_INLINE ivec4s glms_ivec4_muladds(ivec4s a, int s, ivec4s dest)
  CGLM_INLINE ivec4s glms_ivec4_maxadd(ivec4s a, ivec4s b, ivec4s dest)
  CGLM_INLINE ivec4s glms_ivec4_minadd(ivec4s a, ivec4s b, ivec4s dest)
  CGLM_INLINE ivec4s glms_ivec4_subsub(ivec4s a, ivec4s b, ivec4s dest)
  CGLM_INLINE ivec4s glms_ivec4_subsubs(ivec4s a, int s, ivec4s dest)
  CGLM_INLINE ivec4s glms_ivec4_addsub(ivec4s a, ivec4s b, ivec4s dest)
  CGLM_INLINE ivec4s glms_ivec4_addsubs(ivec4s a, int s, ivec4s dest)
  CGLM_INLINE ivec4s glms_ivec4_mulsub(ivec4s a, ivec4s b, ivec4s dest)
  CGLM_INLINE ivec4s glms_ivec4_mulsubs(ivec4s a, int s, ivec4s dest)
  CGLM_INLINE ivec4s glms_ivec4_maxsub(ivec4s a, ivec4s b, ivec4s dest)
  CGLM_INLINE ivec4s glms_ivec4_minsub(ivec4s a, ivec4s b, ivec4s dest)
  CGLM_INLINE int glms_ivec4_distance2(ivec4s a, ivec4s b)
  CGLM_INLINE float glms_ivec4_distance(ivec4s a, ivec4s b)
  CGLM_INLINE ivec4s glms_ivec4_maxv(ivec4s a, ivec4s b)
  CGLM_INLINE ivec4s glms_ivec4_minv(ivec4s a, ivec4s b)
  CGLM_INLINE ivec4s glms_ivec4_clamp(ivec4s v, int minVal, int maxVal)
  CGLM_INLINE ivec4s glms_ivec4_abs(ivec4s v)
 */

#ifndef cglms_ivec4_h
#define cglms_ivec4_h

#include "../common.h"
#include "../types-struct.h"
#include "../ivec4.h"

#define glms_ivec4_(NAME) CGLM_STRUCTAPI(ivec4, NAME)

#define GLMS_IVEC4_ONE_INIT   {GLM_IVEC4_ONE_INIT}
#define GLMS_IVEC4_ZERO_INIT  {GLM_IVEC4_ZERO_INIT}

#define GLMS_IVEC4_ONE  ((ivec4s)GLMS_IVEC4_ONE_INIT)
#define GLMS_IVEC4_ZERO ((ivec4s)GLMS_IVEC4_ZERO_INIT)

/*!
 * @brief init ivec4 using ivec3
 *
 * @param[in]  v3   vector3
 * @param[in]  last last item
 * @returns         destination
 */
CGLM_INLINE
ivec4s
glms_ivec4(ivec3s v3, int last) {
  ivec4s r;
  glm_ivec4(v3.raw, last, r.raw);
  return r;
}

/*!
 * @brief pack an array of ivec4 into an array of ivec4s
 *
 * @param[out] dst array of ivec4s
 * @param[in]  src array of ivec4
 * @param[in]  len number of elements
 */
CGLM_INLINE
void
glms_ivec4_(pack)(ivec4s dst[], ivec4 src[], size_t len) {
  size_t i;

  for (i = 0; i < len; i++) {
    glm_ivec4_copy(src[i], dst[i].raw);
  }
}

/*!
 * @brief unpack an array of ivec4s into an array of ivec4
 *
 * @param[out] dst array of ivec4
 * @param[in]  src array of ivec4s
 * @param[in]  len number of elements
 */
CGLM_INLINE
void
glms_ivec4_(unpack)(ivec4 dst[], ivec4s src[], size_t len) {
  size_t i;

  for (i = 0; i < len; i++) {
    glm_ivec4_copy(src[i].raw, dst[i]);
  }
}

/*!
 * @brief set all members of [v] to zero
 *
 * @returns vector
 */
CGLM_INLINE
ivec4s 
glms_ivec4_(zero)(void) {
  ivec4s r;
  glm_ivec4_zero(r.raw);
  return r;
}

/*!
 * @brief set all members of [v] to one
 *
 * @returns vector
 */
CGLM_INLINE
ivec4s
glms_ivec4_(one)(void) {
  ivec4s r;
  glm_ivec4_one(r.raw);
  return r;
}

/*!
 * @brief add vector [a] to vector [b] and store result in [dest]
 *
 * @param[in]  a    first vector
 * @param[in]  b    second vector
 * @returns         destination
 */
CGLM_INLINE
ivec4s
glms_ivec4_(add)(ivec4s a, ivec4s b) {
  ivec4s r;
  glm_ivec4_add(a.raw, b.raw, r.raw);
  return r;
}

/*!
 * @brief add scalar s to vector [v] and store result in [dest]
 *
 * @param[in]  v    vector
 * @param[in]  s    scalar
 * @returns         destination
 */
CGLM_INLINE
ivec4s
glms_ivec4_(adds)(ivec4s v, int s) {
  ivec4s r;
  glm_ivec4_adds(v.raw, s, r.raw);
  return r;
}

/*!
 * @brief subtract vector [b] from vector [a] and store result in [dest]
 *
 * @param[in]  a    first vector
 * @param[in]  b    second vector
 * @returns         destination
 */
CGLM_INLINE
ivec4s
glms_ivec4_(sub)(ivec4s a, ivec4s b) {
  ivec4s r;
  glm_ivec4_sub(a.raw, b.raw, r.raw);
  return r;
}

/*!
 * @brief subtract scalar s from vector [v] and store result in [dest]
 *
 * @param[in]  v    vector
 * @param[in]  s    scalar
 * @returns         destination
 */
CGLM_INLINE
ivec4s
glms_ivec4_(subs)(ivec4s v, int s) {
  ivec4s r;
  glm_ivec4_subs(v.raw, s, r.raw);
  return r;
}

/*!
 * @brief multiply vector [a] with vector [b] and store result in [dest]
 *
 * @param[in]  a    first vector
 * @param[in]  b    second vector
 * @returns         destination
 */
CGLM_INLINE
ivec4s
glms_ivec4_(mul)(ivec4s a, ivec4s b) {
  ivec4s r;
  glm_ivec4_mul(a.raw, b.raw, r.raw);
  return r;
}

/*!
 * @brief multiply vector [a] with scalar s and store result in [dest]
 *
 * @param[in]  v    vector
 * @param[in]  s    scalar
 * @returns         destination
 */
CGLM_INLINE
ivec4s
glms_ivec4_(scale)(ivec4s v, int s) {
  ivec4s r;
  glm_ivec4_scale(v.raw, s, r.raw);
  return r;
}

/*!
 * @brief add vector [a] with vector [b] and add result to vector [dest]
 *
 * applies += operator so dest must be initialized
 *
 * @param[in]  a    first vector
 * @param[in]  b    second vector
 * @param[in]  dest dest += (a + b)
 * @returns         dest
 */
CGLM_INLINE 
ivec4s 
glms_ivec4_(addadd)(ivec4s a, ivec4s b, ivec4s dest) {
  glm_ivec4_addadd(a.raw, b.raw, dest.raw);
  return dest;
}

/*!
 * @brief add scalar [s] onto vector [a] and add result to vector [dest]
 *
 * applies += operator so dest must be initialized
 *
 * @param[in]  a    vector
 * @param[in]  s    scalar
 * @param[in]  dest dest += (a + s)
 * @returns         dest
 */
CGLM_INLINE 
ivec4s 
glms_ivec4_(addadds)(ivec4s a, int s, ivec4s dest) {
  glm_ivec4_addadds(a.raw, s, dest.raw);
  return dest;
}

/*!
 * @brief subtract vector [a] from vector [b] and add result to [dest]
 *
 * applies += operator so dest must be initialized
 *
 * @param[in]  a    first vector
 * @param[in]  b    second vector
 * @param[in]  dest dest += (a - b)  
 * @returns         dest
 */
CGLM_INLINE 
ivec4s 
glms_ivec4_(subadd)(ivec4s a, ivec4s b, ivec4s dest) {
  glm_ivec4_subadd(a.raw, b.raw, dest.raw);
  return dest;
}

/*!
 * @brief subtract scalar [s] from vector [a] and add result to [dest]
 *
 * applies += operator so dest must be initialized
 *
 * @param[in]  a    first
 * @param[in]  s    scalar
 * @param[in]  dest dest += (a - s)
 * @returns         dest
 */
CGLM_INLINE 
ivec4s 
glms_ivec4_(subadds)(ivec4s a, int s, ivec4s dest) {
  glm_ivec4_subadds(a.raw, s, dest.raw);
  return dest;
}

/*!
 * @brief multiply vector [a] with vector [b] and add result to [dest]
 *
 * applies += operator so dest must be initialized
 *
 * @param[in]  a    first vector
 * @param[in]  b    second vector
 * @param[in]  dest dest += (a * b)
 * @returns         dest
 */
CGLM_INLINE 
ivec4s 
glms_ivec4_(muladd)(ivec4s a, ivec4s b, ivec4s dest) {
  glm_ivec4_muladd(a.raw, b.raw, dest.raw);
  return dest;
}

/*!
 * @brief multiply vector [a] with scalar [s] and add result to [dest]
 *
 * applies += operator so dest must be initialized
 *
 * @param[in]  a    vector
 * @param[in]  s    scalar
 * @param[in]  dest dest += (a * s)
 * @returns         dest
 */
CGLM_INLINE 
ivec4s 
glms_ivec4_(muladds)(ivec4s a, int s, ivec4s dest) {
  glm_ivec4_muladds(a.raw, s, dest.raw);
  return dest;
}

/*!
 * @brief add maximum of vector [a] and vector [b] to vector [dest]
 *
 * applies += operator so dest must be initialized
 *
 * @param[in]  a    first vector
 * @param[in]  b    second vector
 * @param[in]  dest dest += max(a, b)
 * @returns         dest
 */
CGLM_INLINE 
ivec4s 
glms_ivec4_(maxadd)(ivec4s a, ivec4s b, ivec4s dest) {
  glm_ivec4_maxadd(a.raw, b.raw, dest.raw);
  return dest;
}

/*!
 * @brief add minimum of vector [a] and vector [b] to vector [dest]
 *
 * applies += operator so dest must be initialized
 *
 * @param[in]  a    first vector
 * @param[in]  b    second vector
 * @param[in]  dest dest += min(a, b)
 * @returns         dest
 */
CGLM_INLINE 
ivec4s 
glms_ivec4_(minadd)(ivec4s a, ivec4s b, ivec4s dest) {
  glm_ivec4_minadd(a.raw, b.raw, dest.raw);
  return dest;
}

/*!
 * @brief subtract vector [a] from vector [b] and subtract result from [dest]
 *
 * applies -= operator so dest must be initialized
 *
 * @param[in]  a    first vector
 * @param[in]  b    second vector
 * @param[in]  dest dest -= (a - b)
 * @returns         dest
 */
CGLM_INLINE 
ivec4s 
glms_ivec4_(subsub)(ivec4s a, ivec4s b, ivec4s dest) {
  glm_ivec4_subsub(a.raw, b.raw, dest.raw);
  return dest;
}

/*!
 * @brief subtract scalar [s] from vector [a] and subtract result from [dest]
 *
 * applies -= operator so dest must be initialized
 *
 * @param[in]  a    vector
 * @param[in]  s    scalar
 * @param[in]  dest dest -= (a - s)
 * @returns         dest
 */
CGLM_INLINE 
ivec4s 
glms_ivec4_(subsubs)(ivec4s a, int s, ivec4s dest) {
  glm_ivec4_subsubs(a.raw, s, dest.raw);
  return dest;
}

/*!
 * @brief add vector [a] to vector [b] and subtract the result from [dest]
 *
 * applies -= operator so dest must be initialized
 *
 * @param[in]  a    vector
 * @param[in]  b    scalar
 * @param[in]  dest dest -= (a + b)
 * @returns         dest
 */
CGLM_INLINE 
ivec4s 
glms_ivec4_(addsub)(ivec4s a, ivec4s b, ivec4s dest) {
  glm_ivec4_addsub(a.raw, b.raw, dest.raw);
  return dest;
}

/*!
 * @brief add scalar [s] to vector [a] and subtract the result from [dest]
 *
 * applies -= operator so dest must be initialized
 *
 * @param[in]  a    vector
 * @param[in]  s    scalar
 * @param[in]  dest dest -= (a + b)
 * @returns         dest
 */
CGLM_INLINE 
ivec4s 
glms_ivec4_(addsubs)(ivec4s a, int s, ivec4s dest) {
  glm_ivec4_addsubs(a.raw, s, dest.raw);
  return dest;
}

/*!
 * @brief multiply vector [a] and vector [b] and subtract the result from [dest]
 *
 * applies -= operator so dest must be initialized
 *
 * @param[in]  a    vector
 * @param[in]  b    scalar
 * @param[in]  dest dest -= (a * b)
 * @returns         dest
 */
CGLM_INLINE 
ivec4s 
glms_ivec4_(mulsub)(ivec4s a, ivec4s b, ivec4s dest) {
  glm_ivec4_mulsub(a.raw, b.raw, dest.raw);
  return dest;
}

/*!
 * @brief multiply vector [a] with scalar [s] and subtract the result from [dest]
 *
 * applies -= operator so dest must be initialized
 *
 * @param[in]  a    vector
 * @param[in]  s    scalar
 * @param[in]  dest dest -= (a * s)
 * @returns         dest
 */
CGLM_INLINE 
ivec4s 
glms_ivec4_(mulsubs)(ivec4s a, int s, ivec4s dest) {
  glm_ivec4_mulsubs(a.raw, s, dest.raw);
  return dest;
}

/*!
 * @brief subtract maximum of vector [a] and vector [b] from vector [dest]
 *
 * applies += operator so dest must be initialized
 *
 * @param[in]  a    first vector
 * @param[in]  b    second vector
 * @param[in]  dest dest -= max(a, b)
 * @returns         dest
 */
CGLM_INLINE 
ivec4s 
glms_ivec4_(maxsub)(ivec4s a, ivec4s b, ivec4s dest) {
  glm_ivec4_maxsub(a.raw, b.raw, dest.raw);
  return dest;
}

/*!
 * @brief subtract minimum of vector [a] and vector [b] from vector [dest]
 *
 * applies -= operator so dest must be initialized
 *
 * @param[in]  a    first vector
 * @param[in]  b    second vector
 * @param[in]  dest dest -= min(a, b)
 * @returns         dest
 */
CGLM_INLINE 
ivec4s 
glms_ivec4_(minsub)(ivec4s a, ivec4s b, ivec4s dest) {
  glm_ivec4_minsub(a.raw, b.raw, dest.raw);
  return dest;
}

/*!
 * @brief squared distance between two vectors
 *
 * @param[in] a first vector
 * @param[in] b second vector
 * @return returns squared distance (distance * distance)
 */
CGLM_INLINE
int
glms_ivec4_(distance2)(ivec4s a, ivec4s b) {
  return glm_ivec4_distance2(a.raw, b.raw);
}

/*!
 * @brief distance between two vectors
 *
 * @param[in] a first vector
 * @param[in] b second vector
 * @return returns distance
 */
CGLM_INLINE
float
glms_ivec4_(distance)(ivec4s a, ivec4s b) {
  return glm_ivec4_distance(a.raw, b.raw);
}

/*!
 * @brief set each member of dest to greater of vector a and b
 *
 * @param[in]  a    first vector
 * @param[in]  b    second vector
 * @returns         destination
 */
CGLM_INLINE
ivec4s
glms_ivec4_(maxv)(ivec4s a, ivec4s b) {
  ivec4s r;
  glm_ivec4_maxv(a.raw, b.raw, r.raw);
  return r;
}

/*!
 * @brief set each member of dest to lesser of vector a and b
 *
 * @param[in]  a    first vector
 * @param[in]  b    second vector
 * @returns         destination
 */
CGLM_INLINE
ivec4s
glms_ivec4_(minv)(ivec4s a, ivec4s b) {
  ivec4s r;
  glm_ivec4_minv(a.raw, b.raw, r.raw);
  return r;
}

/*!
 * @brief clamp each member of [v] between minVal and maxVal (inclusive)
 *
 * @param[in]      v      vector
 * @param[in]      minVal minimum value
 * @param[in]      maxVal maximum value
 * @returns               clamped vector
 */
CGLM_INLINE
ivec4s
glms_ivec4_(clamp)(ivec4s v, int minVal, int maxVal) {
  glm_ivec4_clamp(v.raw, minVal, maxVal);
  return v;
}

/*!
 * @brief absolute value of v
 *
 * @param[in]	v	vector
 * @returns     destination
 */
CGLM_INLINE
ivec4s
glms_ivec4_(abs)(ivec4s v) {
  ivec4s r;
  glm_ivec4_abs(v.raw, r.raw);
  return r;
}

#endif /* cglms_ivec4_h */
