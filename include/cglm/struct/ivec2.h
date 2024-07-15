/*
 * Copyright (c), Recep Aslantas.
 *
 * MIT License (MIT), http://opensource.org/licenses/MIT
 * Full license can be found in the LICENSE file
 */

/*
 Macros:
  GLMS_IVEC2_ONE_INIT
  GLMS_IVEC2_ZERO_INIT
  GLMS_IVEC2_ONE
  GLMS_IVEC2_ZERO

 Functions:
  CGLM_INLINE ivec2s glms_ivec2(int * __restrict v)
  CGLM_INLINE void glms_ivec2_pack(ivec2s dst[], ivec2s src[], size_t len)
  CGLM_INLINE void glms_ivec2_unpack(ivec2 dst[], ivec2 src[], size_t len)
  CGLM_INLINE ivec2s glms_ivec2_zero(ivec2s v)
  CGLM_INLINE ivec2s glms_ivec2_one(ivec2s v)
  CGLM_INLINE int glms_ivec2_dot(ivec2s a, ivec2s b)
  CGLM_INLINE int glms_ivec2_cross(ivec2s a, ivec2s b)
  CGLM_INLINE ivec2s glms_ivec2_add(ivec2s a, ivec2s b)
  CGLM_INLINE ivec2s glms_ivec2_adds(ivec2s v, int s)
  CGLM_INLINE ivec2s glms_ivec2_sub(ivec2s a, ivec2s b)
  CGLM_INLINE ivec2s glms_ivec2_subs(ivec2s v, int s)
  CGLM_INLINE ivec2s glms_ivec2_mul(ivec2s a, ivec2s b)
  CGLM_INLINE ivec2s glms_ivec2_scale(ivec2s v, int s)
  CGLM_INLINE ivec2s glms_ivec2_div(ivec2s a, ivec2s b)
  CGLM_INLINE ivec2s glms_ivec2_divs(ivec2s v, int s)
  CGLM_INLINE ivec2s glms_ivec2_mod(ivec2s a, ivec2s b)
  CGLM_INLINE ivec2s glms_ivec2_addadd(ivec2s a, ivec2s b)
  CGLM_INLINE ivec2s glms_ivec2_addadds(ivec2s a, int s)
  CGLM_INLINE ivec2s glms_ivec2_subadd(ivec2s a, ivec2s b)
  CGLM_INLINE ivec2s glms_ivec2_subadds(ivec2s a, int s)
  CGLM_INLINE ivec2s glms_ivec2_muladd(ivec2s a, ivec2s b)
  CGLM_INLINE ivec2s glms_ivec2_muladds(ivec2s a, int s)
  CGLM_INLINE ivec2s glms_ivec2_maxadd(ivec2s a, ivec2s b)
  CGLM_INLINE ivec2s glms_ivec2_minadd(ivec2s a, ivec2s b)
  CGLM_INLINE ivec2s glms_ivec2_subsub(ivec2s a, ivec2s b)
  CGLM_INLINE ivec2s glms_ivec2_subsubs(ivec2s a, int s)
  CGLM_INLINE ivec2s glms_ivec2_addsub(ivec2s a, ivec2s b)
  CGLM_INLINE ivec2s glms_ivec2_addsubs(ivec2s a, int s)
  CGLM_INLINE ivec2s glms_ivec2_mulsub(ivec2s a, ivec2s b)
  CGLM_INLINE ivec2s glms_ivec2_mulsubs(ivec2s a, int s)
  CGLM_INLINE ivec2s glms_ivec2_maxsub(ivec2s a, ivec2s b)
  CGLM_INLINE ivec2s glms_ivec2_minsub(ivec2s a, ivec2s b)
  CGLM_INLINE int glms_ivec2_distance2(ivec2s a, ivec2s b)
  CGLM_INLINE float glms_ivec2_distance(ivec2s a, ivec2s b)
  CGLM_INLINE ivec2s glms_ivec2_fill(int val)
  CGLM_INLINE bool glms_ivec2_eq(ivec2s v, int val);
  CGLM_INLINE bool glms_ivec2_eqv(ivec2s a, ivec2s b);
  CGLM_INLINE ivec2s glms_ivec2_maxv(ivec2s a, ivec2s b)
  CGLM_INLINE ivec2s glms_ivec2_minv(ivec2s a, ivec2s b)
  CGLM_INLINE ivec2s glms_ivec2_clamp(ivec2s v, int minVal, int maxVal)
  CGLM_INLINE ivec2s glms_ivec2_abs(ivec2s v)
 */

#ifndef cglms_ivec2_h
#define cglms_ivec2_h

#include "../common.h"
#include "../types-struct.h"
#include "../ivec2.h"

#define glms_ivec2_(NAME) CGLM_STRUCTAPI(ivec2, NAME)

#define GLMS_IVEC2_ONE_INIT   {GLM_IVEC2_ONE_INIT}
#define GLMS_IVEC2_ZERO_INIT  {GLM_IVEC2_ZERO_INIT}

#define GLMS_IVEC2_ONE  ((ivec2s)GLMS_IVEC2_ONE_INIT)
#define GLMS_IVEC2_ZERO ((ivec2s)GLMS_IVEC2_ZERO_INIT)

/*!
 * @brief init ivec2 using ivec3 or ivec4
 *
 * @param[in]  v    vector
 * @returns         destination
 */
CGLM_INLINE
ivec2s
glms_ivec2(int * __restrict v) {
  ivec2s r;
  glm_ivec2(v, r.raw);
  return r;
}

/*!
 * @brief pack an array of ivec2 into an array of ivec2s
 *
 * @param[out] dst array of ivec2s
 * @param[in]  src array of ivec2
 * @param[in]  len number of elements
 */
CGLM_INLINE
void
glms_ivec2_(pack)(ivec2s dst[], ivec2 src[], size_t len) {
  size_t i;

  for (i = 0; i < len; i++) {
    glm_ivec2_copy(src[i], dst[i].raw);
  }
}

/*!
 * @brief unpack an array of ivec2s into an array of ivec2
 *
 * @param[out] dst array of ivec2
 * @param[in]  src array of ivec2s
 * @param[in]  len number of elements
 */
CGLM_INLINE
void
glms_ivec2_(unpack)(ivec2 dst[], ivec2s src[], size_t len) {
  size_t i;

  for (i = 0; i < len; i++) {
    glm_ivec2_copy(src[i].raw, dst[i]);
  }
}

/*!
 * @brief set all members of [v] to zero
 *
 * @returns vector
 */
CGLM_INLINE
ivec2s 
glms_ivec2_(zero)(void) {
  ivec2s r;
  glm_ivec2_zero(r.raw);
  return r;
}

/*!
 * @brief set all members of [v] to one
 *
 * @returns vector
 */
CGLM_INLINE
ivec2s
glms_ivec2_(one)(void) {
  ivec2s r;
  glm_ivec2_one(r.raw);
  return r;
}

/*!
 * @brief ivec2 dot product
 *
 * @param[in] a vector1
 * @param[in] b vector2
 *
 * @return dot product
 */
CGLM_INLINE
int
glms_ivec2_(dot)(ivec2s a, ivec2s b) {
  return glm_ivec2_dot(a.raw, b.raw);
}

/*!
 * @brief ivec2 cross product
 *
 * REF: http://allenchou.net/2013/07/cross-product-of-2d-vectors/
 *
 * @param[in]  a vector1
 * @param[in]  b vector2
 *
 * @return Z component of cross product
 */
CGLM_INLINE
int
glms_ivec2_(cross)(ivec2s a, ivec2s b) {
  return glm_ivec2_cross(a.raw, b.raw);
}

/*!
 * @brief add vector [a] to vector [b] and store result in [dest]
 *
 * @param[in]  a    first vector
 * @param[in]  b    second vector
 * @returns         destination
 */
CGLM_INLINE
ivec2s
glms_ivec2_(add)(ivec2s a, ivec2s b) {
  ivec2s r;
  glm_ivec2_add(a.raw, b.raw, r.raw);
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
ivec2s
glms_ivec2_(adds)(ivec2s v, int s) {
  ivec2s r;
  glm_ivec2_adds(v.raw, s, r.raw);
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
ivec2s
glms_ivec2_(sub)(ivec2s a, ivec2s b) {
  ivec2s r;
  glm_ivec2_sub(a.raw, b.raw, r.raw);
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
ivec2s
glms_ivec2_(subs)(ivec2s v, int s) {
  ivec2s r;
  glm_ivec2_subs(v.raw, s, r.raw);
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
ivec2s
glms_ivec2_(mul)(ivec2s a, ivec2s b) {
  ivec2s r;
  glm_ivec2_mul(a.raw, b.raw, r.raw);
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
ivec2s
glms_ivec2_(scale)(ivec2s v, int s) {
  ivec2s r;
  glm_ivec2_scale(v.raw, s, r.raw);
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
ivec2s
glms_ivec2_(div)(ivec2s a, ivec2s b) {
  ivec2s r;
  glm_ivec2_div(a.raw, b.raw, r.raw);
  return r;
}

/*!
 * @brief div vector with scalar: d = v / s
 *
 * @param[in]  v    vector
 * @param[in]  s    scalar
 * @returns         result = (a[0]/s, a[1]/s)
 */
CGLM_INLINE
ivec2s
glms_ivec2_(divs)(ivec2s v, int s) {
  ivec2s r;
  glm_ivec2_divs(v.raw, s, r.raw);
  return r;
}

/*!
 * @brief mod vector with another component-wise modulo: d = a % b
 *
 * @param[in]  a    vector 1
 * @param[in]  b    vector 2
 * @returns         result = (a[0]%b[0], a[1]%b[1])
 */
CGLM_INLINE
ivec2s
glms_ivec2_(mod)(ivec2s a, ivec2s b) {
  ivec2s r;
  glm_ivec2_mod(a.raw, b.raw, r.raw);
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
ivec2s 
glms_ivec2_(addadd)(ivec2s a, ivec2s b, ivec2s dest) {
  glm_ivec2_addadd(a.raw, b.raw, dest.raw);
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
ivec2s 
glms_ivec2_(addadds)(ivec2s a, int s, ivec2s dest) {
  glm_ivec2_addadds(a.raw, s, dest.raw);
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
ivec2s 
glms_ivec2_(subadd)(ivec2s a, ivec2s b, ivec2s dest) {
  glm_ivec2_subadd(a.raw, b.raw, dest.raw);
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
ivec2s 
glms_ivec2_(subadds)(ivec2s a, int s, ivec2s dest) {
  glm_ivec2_subadds(a.raw, s, dest.raw);
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
ivec2s 
glms_ivec2_(muladd)(ivec2s a, ivec2s b, ivec2s dest) {
  glm_ivec2_muladd(a.raw, b.raw, dest.raw);
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
ivec2s 
glms_ivec2_(muladds)(ivec2s a, int s, ivec2s dest) {
  glm_ivec2_muladds(a.raw, s, dest.raw);
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
ivec2s 
glms_ivec2_(maxadd)(ivec2s a, ivec2s b, ivec2s dest) {
  glm_ivec2_maxadd(a.raw, b.raw, dest.raw);
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
ivec2s 
glms_ivec2_(minadd)(ivec2s a, ivec2s b, ivec2s dest) {
  glm_ivec2_minadd(a.raw, b.raw, dest.raw);
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
ivec2s 
glms_ivec2_(subsub)(ivec2s a, ivec2s b, ivec2s dest) {
  glm_ivec2_subsub(a.raw, b.raw, dest.raw);
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
ivec2s 
glms_ivec2_(subsubs)(ivec2s a, int s, ivec2s dest) {
  glm_ivec2_subsubs(a.raw, s, dest.raw);
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
ivec2s 
glms_ivec2_(addsub)(ivec2s a, ivec2s b, ivec2s dest) {
  glm_ivec2_addsub(a.raw, b.raw, dest.raw);
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
ivec2s 
glms_ivec2_(addsubs)(ivec2s a, int s, ivec2s dest) {
  glm_ivec2_addsubs(a.raw, s, dest.raw);
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
ivec2s 
glms_ivec2_(mulsub)(ivec2s a, ivec2s b, ivec2s dest) {
  glm_ivec2_mulsub(a.raw, b.raw, dest.raw);
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
ivec2s 
glms_ivec2_(mulsubs)(ivec2s a, int s, ivec2s dest) {
  glm_ivec2_mulsubs(a.raw, s, dest.raw);
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
ivec2s 
glms_ivec2_(maxsub)(ivec2s a, ivec2s b, ivec2s dest) {
  glm_ivec2_maxsub(a.raw, b.raw, dest.raw);
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
ivec2s 
glms_ivec2_(minsub)(ivec2s a, ivec2s b, ivec2s dest) {
  glm_ivec2_minsub(a.raw, b.raw, dest.raw);
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
glms_ivec2_(distance2)(ivec2s a, ivec2s b) {
  return glm_ivec2_distance2(a.raw, b.raw);
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
glms_ivec2_(distance)(ivec2s a, ivec2s b) {
  return glm_ivec2_distance(a.raw, b.raw);
}

/*!
 * @brief fill a vector with specified value
 *
 * @param[in]  val value
 * @returns        dest
 */
CGLM_INLINE
ivec2s
glms_ivec2_(fill)(int val) {
  ivec2s r;
  glm_ivec2_fill(r.raw, val);
  return r;
}

/*!
 * @brief check if vector is equal to value
 *
 * @param[in] v   vector
 * @param[in] val value
 */
CGLM_INLINE
bool
glms_ivec2_(eq)(ivec2s v, int val) {
  return glm_ivec2_eq(v.raw, val);
}

/*!
 * @brief check if vector is equal to another
 *
 * @param[in] a vector
 * @param[in] b vector
 */
CGLM_INLINE
bool
glms_ivec2_(eqv)(ivec2s a, ivec2s b) {
  return glm_ivec2_eqv(a.raw, b.raw);
}

/*!
 * @brief set each member of dest to greater of vector a and b
 *
 * @param[in]  a    first vector
 * @param[in]  b    second vector
 * @returns         destination
 */
CGLM_INLINE
ivec2s
glms_ivec2_(maxv)(ivec2s a, ivec2s b) {
  ivec2s r;
  glm_ivec2_maxv(a.raw, b.raw, r.raw);
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
ivec2s
glms_ivec2_(minv)(ivec2s a, ivec2s b) {
  ivec2s r;
  glm_ivec2_minv(a.raw, b.raw, r.raw);
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
ivec2s
glms_ivec2_(clamp)(ivec2s v, int minVal, int maxVal) {
  glm_ivec2_clamp(v.raw, minVal, maxVal);
  return v;
}

/*!
 * @brief absolute value of v
 *
 * @param[in]	v	vector
 * @returns     destination
 */
CGLM_INLINE
ivec2s
glms_ivec2_(abs)(ivec2s v) {
  ivec2s r;
  glm_ivec2_abs(v.raw, r.raw);
  return r;
}

#endif /* cglms_ivec2_h */
