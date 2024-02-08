/*
 * Copyright (c), Recep Aslantas.
 *
 * MIT License (MIT), http://opensource.org/licenses/MIT
 * Full license can be found in the LICENSE file
 */

/*
 Macros:
  GLMS_IVEC3_ONE_INIT
  GLMS_IVEC3_ZERO_INIT
  GLMS_IVEC3_ONE
  GLMS_IVEC3_ZERO

 Functions:
  CGLM_INLINE ivec3s glms_ivec3(ivec4s v4)
  CGLM_INLINE void glms_ivec3_pack(ivec3s dst[], ivec3 src[], size_t len)
  CGLM_INLINE void glms_ivec3_unpack(ivec3 dst[], ivec3s src[], size_t len)
  CGLM_INLINE ivec3s glms_ivec3_zero(void)
  CGLM_INLINE ivec3s glms_ivec3_one(void)
  CGLM_INLINE int glms_ivec3_dot(ivec3s a, ivec3s b)
  CGLM_INLINE int glms_ivec3_norm2(ivec3s v)
  CGLM_INLINE int glms_ivec3_norm(ivec3s v)
  CGLM_INLINE ivec3s glms_ivec3_add(ivec3s a, ivec3s b)
  CGLM_INLINE ivec3s glms_ivec3_adds(ivec3s v, int s)
  CGLM_INLINE ivec3s glms_ivec3_sub(ivec3s a, ivec3s b)
  CGLM_INLINE ivec3s glms_ivec3_subs(ivec3s v, int s)
  CGLM_INLINE ivec3s glms_ivec3_mul(ivec3s a, ivec3s b)
  CGLM_INLINE ivec3s glms_ivec3_scale(ivec3s v, int s)
  CGLM_INLINE ivec3s glms_ivec3_div(ivec3s a, ivec3s b)
  CGLM_INLINE ivec3s glms_ivec3_divs(ivec3s v, int s)
  CGLM_INLINE ivec3s glms_ivec3_mod(ivec3s a, ivec3s b)
  CGLM_INLINE ivec3s glms_ivec3_addadd(ivec3s a, ivec3s b, ivec3s dest)
  CGLM_INLINE ivec3s glms_ivec3_addadds(ivec3s a, int s, ivec3s dest)
  CGLM_INLINE ivec3s glms_ivec3_subadd(ivec3s a, ivec3s b, ivec3s dest)
  CGLM_INLINE ivec3s glms_ivec3_subadds(ivec3s a, int s, ivec3s dest)
  CGLM_INLINE ivec3s glms_ivec3_muladd(ivec3s a, ivec3s b, ivec3s dest)
  CGLM_INLINE ivec3s glms_ivec3_muladds(ivec3s a, int s, ivec3s dest)
  CGLM_INLINE ivec3s glms_ivec3_minadd(ivec3s a, ivec3s b, ivec3s dest)
  CGLM_INLINE ivec3s glms_ivec3_subsub(ivec3s a, ivec3s b, ivec3s dest)
  CGLM_INLINE ivec3s glms_ivec3_subsubs(ivec3s a, int s, ivec3s dest)
  CGLM_INLINE ivec3s glms_ivec3_addsub(ivec3s a, ivec3s b, ivec3s dest)
  CGLM_INLINE ivec3s glms_ivec3_addsubs(ivec3s a, int s, ivec3s dest)
  CGLM_INLINE ivec3s glms_ivec3_mulsub(ivec3s a, ivec3s b, ivec3s dest)
  CGLM_INLINE ivec3s glms_ivec3_mulsubs(ivec3s a, int s, ivec3s dest)
  CGLM_INLINE ivec3s glms_ivec3_maxsub(ivec3s a, ivec3s b, ivec3s dest)
  CGLM_INLINE ivec3s glms_ivec3_minsub(ivec3s a, ivec3s b, ivec3s dest)
  CGLM_INLINE int glms_ivec3_distance2(ivec3s a, ivec3s b)
  CGLM_INLINE float glms_ivec3_distance(ivec3s a, ivec3s b)
  CGLM_INLINE ivec3s glms_ivec3_fill(int val)
  CGLM_INLINE bool glms_ivec3_eq(ivec3s v, int val)
  CGLM_INLINE bool glms_ivec3_eqv(ivec3s a, ivec3s b)
  CGLM_INLINE ivec3s glms_ivec3_maxv(ivec3s a, ivec3s b)
  CGLM_INLINE ivec3s glms_ivec3_minv(ivec3s a, ivec3s b)
  CGLM_INLINE ivec3s glms_ivec3_clamp(ivec3s v, int minVal, int maxVal)
  CGLM_INLINE ivec3s glms_ivec3_abs(ivec3s v)
 */

#ifndef cglms_ivec3_h
#define cglms_ivec3_h

#include "../common.h"
#include "../types-struct.h"
#include "../ivec3.h"

#define glms_ivec3_(NAME) CGLM_STRUCTAPI(ivec3, NAME)

#define GLMS_IVEC3_ONE_INIT   {GLM_IVEC3_ONE_INIT}
#define GLMS_IVEC3_ZERO_INIT  {GLM_IVEC3_ZERO_INIT}

#define GLMS_IVEC3_ONE  ((ivec3s)GLMS_IVEC3_ONE_INIT)
#define GLMS_IVEC3_ZERO ((ivec3s)GLMS_IVEC3_ZERO_INIT)

/*!
 * @brief init ivec3 using ivec4
 *
 * @param[in]  v4   vector4
 * @returns         destination
 */
CGLM_INLINE
ivec3s
glms_ivec3(ivec4s v4) {
  ivec3s r;
  glm_ivec3(v4.raw, r.raw);
  return r;
}

/*!
 * @brief pack an array of ivec3 into an array of ivec3s
 *
 * @param[out] dst array of ivec3s
 * @param[in]  src array of ivec3
 * @param[in]  len number of elements
 */
CGLM_INLINE
void
glms_ivec3_(pack)(ivec3s dst[], ivec3 src[], size_t len) {
  size_t i;

  for (i = 0; i < len; i++) {
    glm_ivec3_copy(src[i], dst[i].raw);
  }
}

/*!
 * @brief unpack an array of ivec3s into an array of ivec3
 *
 * @param[out] dst array of ivec3
 * @param[in]  src array of ivec3s
 * @param[in]  len number of elements
 */
CGLM_INLINE
void
glms_ivec3_(unpack)(ivec3 dst[], ivec3s src[], size_t len) {
  size_t i;

  for (i = 0; i < len; i++) {
    glm_ivec3_copy(src[i].raw, dst[i]);
  }
}

/*!
 * @brief set all members of [v] to zero
 *
 * @returns vector
 */
CGLM_INLINE
ivec3s 
glms_ivec3_(zero)(void) {
  ivec3s r;
  glm_ivec3_zero(r.raw);
  return r;
}

/*!
 * @brief set all members of [v] to one
 *
 * @returns vector
 */
CGLM_INLINE
ivec3s
glms_ivec3_(one)(void) {
  ivec3s r;
  glm_ivec3_one(r.raw);
  return r;
}

/*!
 * @brief ivec3 dot product
 *
 * @param[in] a vector1
 * @param[in] b vector2
 *
 * @return dot product
 */
CGLM_INLINE
int
glms_ivec3_(dot)(ivec3s a, ivec3s b) {
  return glm_ivec3_dot(a.raw, b.raw);
}

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
CGLM_INLINE
int
glms_ivec3_(norm2)(ivec3s v) {
  return glm_ivec3_norm2(v.raw);
}

/*!
 * @brief euclidean norm (magnitude), also called L2 norm
 *        this will give magnitude of vector in euclidean space
 *
 * @param[in] v vector
 *
 * @return norm
 */
CGLM_INLINE
int
glms_ivec3_(norm)(ivec3s v) {
  return glm_ivec3_norm(v.raw);
}

/*!
 * @brief add vector [a] to vector [b] and store result in [dest]
 *
 * @param[in]  a    first vector
 * @param[in]  b    second vector
 * @returns         destination
 */
CGLM_INLINE
ivec3s
glms_ivec3_(add)(ivec3s a, ivec3s b) {
  ivec3s r;
  glm_ivec3_add(a.raw, b.raw, r.raw);
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
ivec3s
glms_ivec3_(adds)(ivec3s v, int s) {
  ivec3s r;
  glm_ivec3_adds(v.raw, s, r.raw);
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
ivec3s
glms_ivec3_(sub)(ivec3s a, ivec3s b) {
  ivec3s r;
  glm_ivec3_sub(a.raw, b.raw, r.raw);
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
ivec3s
glms_ivec3_(subs)(ivec3s v, int s) {
  ivec3s r;
  glm_ivec3_subs(v.raw, s, r.raw);
  return r;
}

/*!
 * @brief multiply vector [a] with vector [b] and store result in [dest]
 *
 * @param[in]  a    frist vector
 * @param[in]  b    second vector
 * @returns         destination
 */
CGLM_INLINE
ivec3s
glms_ivec3_(mul)(ivec3s a, ivec3s b) {
  ivec3s r;
  glm_ivec3_mul(a.raw, b.raw, r.raw);
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
ivec3s
glms_ivec3_(scale)(ivec3s v, int s) {
  ivec3s r;
  glm_ivec3_scale(v.raw, s, r.raw);
  return r;
}

/*!
 * @brief div vector with another component-wise division: d = a / b
 *
 * @param[in]  a    vector 1
 * @param[in]  b    vector 2
 * @returns         result = (a[0]/b[0], a[1]/b[1], a[2]/b[2])
 */
CGLM_INLINE
ivec3s
glms_ivec3_(div)(ivec3s a, ivec3s b) {
  ivec3s r;
  glm_ivec3_div(a.raw, b.raw, r.raw);
  return r;
}

/*!
 * @brief div vector with scalar: d = v / s
 *
 * @param[in]  v    vector
 * @param[in]  s    scalar
 * @returns         result = (a[0]/s, a[1]/s, a[2]/s)
 */
CGLM_INLINE
ivec3s
glms_ivec3_(divs)(ivec3s v, int s) {
  ivec3s r;
  glm_ivec3_divs(v.raw, s, r.raw);
  return r;
}

/*!
 * @brief Element-wise modulo operation on ivec3 vectors: dest = a % b
 *
 * Performs element-wise modulo on each component of vectors `a` and `b`.
 *
 * @param[in]  a    vector 1
 * @param[in]  b    vector 2
 * @returns         result = (a[0]%b[0], a[1]%b[1], a[2]%b[2])
 */
CGLM_INLINE
ivec3s
glms_ivec3_(mod)(ivec3s a, ivec3s b) {
  ivec3s r;
  glm_ivec3_mod(a.raw, b.raw, r.raw);
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
ivec3s 
glms_ivec3_(addadd)(ivec3s a, ivec3s b, ivec3s dest) {
  glm_ivec3_addadd(a.raw, b.raw, dest.raw);
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
ivec3s 
glms_ivec3_(addadds)(ivec3s a, int s, ivec3s dest) {
  glm_ivec3_addadds(a.raw, s, dest.raw);
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
ivec3s 
glms_ivec3_(subadd)(ivec3s a, ivec3s b, ivec3s dest) {
  glm_ivec3_subadd(a.raw, b.raw, dest.raw);
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
ivec3s 
glms_ivec3_(subadds)(ivec3s a, int s, ivec3s dest) {
  glm_ivec3_subadds(a.raw, s, dest.raw);
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
ivec3s 
glms_ivec3_(muladd)(ivec3s a, ivec3s b, ivec3s dest) {
  glm_ivec3_muladd(a.raw, b.raw, dest.raw);
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
ivec3s 
glms_ivec3_(muladds)(ivec3s a, int s, ivec3s dest) {
  glm_ivec3_muladds(a.raw, s, dest.raw);
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
ivec3s 
glms_ivec3_(maxadd)(ivec3s a, ivec3s b, ivec3s dest) {
  glm_ivec3_maxadd(a.raw, b.raw, dest.raw);
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
ivec3s 
glms_ivec3_(minadd)(ivec3s a, ivec3s b, ivec3s dest) {
  glm_ivec3_minadd(a.raw, b.raw, dest.raw);
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
ivec3s 
glms_ivec3_(subsub)(ivec3s a, ivec3s b, ivec3s dest) {
  glm_ivec3_subsub(a.raw, b.raw, dest.raw);
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
ivec3s 
glms_ivec3_(subsubs)(ivec3s a, int s, ivec3s dest) {
  glm_ivec3_subsubs(a.raw, s, dest.raw);
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
ivec3s 
glms_ivec3_(addsub)(ivec3s a, ivec3s b, ivec3s dest) {
  glm_ivec3_addsub(a.raw, b.raw, dest.raw);
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
ivec3s 
glms_ivec3_(addsubs)(ivec3s a, int s, ivec3s dest) {
  glm_ivec3_addsubs(a.raw, s, dest.raw);
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
ivec3s 
glms_ivec3_(mulsub)(ivec3s a, ivec3s b, ivec3s dest) {
  glm_ivec3_mulsub(a.raw, b.raw, dest.raw);
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
ivec3s 
glms_ivec3_(mulsubs)(ivec3s a, int s, ivec3s dest) {
  glm_ivec3_mulsubs(a.raw, s, dest.raw);
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
ivec3s 
glms_ivec3_(maxsub)(ivec3s a, ivec3s b, ivec3s dest) {
  glm_ivec3_maxsub(a.raw, b.raw, dest.raw);
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
ivec3s 
glms_ivec3_(minsub)(ivec3s a, ivec3s b, ivec3s dest) {
  glm_ivec3_minsub(a.raw, b.raw, dest.raw);
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
glms_ivec3_(distance2)(ivec3s a, ivec3s b) {
  return glm_ivec3_distance2(a.raw, b.raw);
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
glms_ivec3_(distance)(ivec3s a, ivec3s b) {
  return glm_ivec3_distance(a.raw, b.raw);
}

/*!
 * @brief fill a vector with specified value
 *
 * @param[in]  val value
 * @returns        destination
 */
CGLM_INLINE
ivec3s
glms_ivec3_(fill)(int val) {
  ivec3s r;
  glm_ivec3_fill(r.raw, val);
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
glms_ivec3_(eq)(ivec3s v, int val) {
  return glm_ivec3_eq(v.raw, val);
}

/*!
 * @brief check if vector is equal to another
 *
 * @param[in] a vector
 * @param[in] b vector
 */
CGLM_INLINE
bool
glms_ivec3_(eqv)(ivec3s a, ivec3s b) {
  return glm_ivec3_eqv(a.raw, b.raw);
}

/*!
 * @brief set each member of dest to greater of vector a and b
 *
 * @param[in]  a    first vector
 * @param[in]  b    second vector
 * @returns         destination
 */
CGLM_INLINE
ivec3s
glms_ivec3_(maxv)(ivec3s a, ivec3s b) {
  ivec3s r;
  glm_ivec3_maxv(a.raw, b.raw, r.raw);
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
ivec3s
glms_ivec3_(minv)(ivec3s a, ivec3s b) {
  ivec3s r;
  glm_ivec3_minv(a.raw, b.raw, r.raw);
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
ivec3s
glms_ivec3_(clamp)(ivec3s v, int minVal, int maxVal) {
  glm_ivec3_clamp(v.raw, minVal, maxVal);
  return v;
}

/*!
 * @brief absolute value of v
 *
 * @param[in]	v	vector
 * @returns     destination
 */
CGLM_INLINE
ivec3s
glms_ivec3_(abs)(ivec3s v) {
  ivec3s r;
  glm_ivec3_abs(v.raw, r.raw);
  return r;
}

#endif /* cglms_ivec3_h */
