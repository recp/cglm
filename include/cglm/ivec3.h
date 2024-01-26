/*
 * Copyright (c), Recep Aslantas.
 *
 * MIT License (MIT), http://opensource.org/licenses/MIT
 * Full license can be found in the LICENSE file
 */

/*
 Macros:
   GLM_IVEC3_ONE_INIT
   GLM_IVEC3_ZERO_INIT
   GLM_IVEC3_ONE
   GLM_IVEC3_ZERO

 Functions:
  CGLM_INLINE void glm_ivec3(ivec4 v4, ivec3 dest)
  CGLM_INLINE void glm_ivec3_copy(ivec3 a, ivec3 dest)
  CGLM_INLINE void glm_ivec3_zero(ivec3 v)
  CGLM_INLINE void glm_ivec3_one(ivec3 v)
  CGLM_INLINE int glm_ivec3_dot(ivec3 a, ivec3 b)
  CGLM_INLINE int glm_ivec3_norm2(ivec3 v)
  CGLM_INLINE int glm_ivec3_norm(ivec3 v)
  CGLM_INLINE void glm_ivec3_add(ivec3 a, ivec3 b, ivec3 dest)
  CGLM_INLINE void glm_ivec3_adds(ivec3 v, int s, ivec3 dest)
  CGLM_INLINE void glm_ivec3_sub(ivec3 a, ivec3 b, ivec3 dest)
  CGLM_INLINE void glm_ivec3_subs(ivec3 v, int s, ivec3 dest)
  CGLM_INLINE void glm_ivec3_mul(ivec3 a, ivec3 b, ivec3 dest)
  CGLM_INLINE void glm_ivec3_scale(ivec3 v, int s, ivec3 dest)
  CGLM_INLINE void glm_ivec3_div(ivec3 a, ivec3 b, ivec3 dest)
  CGLM_INLINE void glm_ivec3_divs(ivec3 v, int s, ivec3 dest)
  CGLM_INLINE void glm_ivec3_mod(ivec3 a, ivec3 b, ivec3 dest)
  CGLM_INLINE void glm_ivec3_addadd(ivec3 a, ivec3 b, ivec3 dest)
  CGLM_INLINE void glm_ivec3_addadds(ivec3 a, int s, ivec3 dest)
  CGLM_INLINE void glm_ivec3_subadd(ivec3 a, ivec3 b, ivec3 dest)
  CGLM_INLINE void glm_ivec3_subadds(ivec3 a, int s, ivec3 dest)
  CGLM_INLINE void glm_ivec3_muladd(ivec3 a, ivec3 b, ivec3 dest)
  CGLM_INLINE void glm_ivec3_muladds(ivec3 a, int s, ivec3 dest)
  CGLM_INLINE void glm_ivec3_maxadd(ivec3 a, ivec3 b, ivec3 dest)
  CGLM_INLINE void glm_ivec3_minadd(ivec3 a, ivec3 b, ivec3 dest)
  CGLM_INLINE void glm_ivec3_subsub(ivec3 a, ivec3 b, ivec3 dest)
  CGLM_INLINE void glm_ivec3_subsubs(ivec3 a, int s, ivec3 dest)
  CGLM_INLINE void glm_ivec3_addsub(ivec3 a, ivec3 b, ivec3 dest)
  CGLM_INLINE void glm_ivec3_addsubs(ivec3 a, int s, ivec3 dest)
  CGLM_INLINE void glm_ivec3_mulsub(ivec3 a, ivec3 b, ivec3 dest)
  CGLM_INLINE void glm_ivec3_mulsubs(ivec3 a, int s, ivec3 dest)
  CGLM_INLINE void glm_ivec3_maxsub(ivec3 a, ivec3 b, ivec3 dest)
  CGLM_INLINE void glm_ivec3_minsub(ivec3 a, ivec3 b, ivec3 dest)
  CGLM_INLINE int glm_ivec3_distance2(ivec3 a, ivec3 b)
  CGLM_INLINE float glm_ivec3_distance(ivec3 a, ivec3 b)
  CGLM_INLINE void glm_ivec3_fill(ivec3 v, int val);
  CGLM_INLINE bool glm_ivec3_eq(ivec3 v, int val);
  CGLM_INLINE bool glm_ivec3_eqv(ivec3 a, ivec3 b);
  CGLM_INLINE void glm_ivec3_maxv(ivec3 a, ivec3 b, ivec3 dest)
  CGLM_INLINE void glm_ivec3_minv(ivec3 a, ivec3 b, ivec3 dest)
  CGLM_INLINE void glm_ivec3_clamp(ivec3 v, int minVal, int maxVal)
  CGLM_INLINE void glm_ivec3_abs(ivec3 v, ivec3 dest)
 */

#ifndef cglm_ivec3_h
#define cglm_ivec3_h

#include "common.h"
#include "util.h"

#define GLM_IVEC3_ONE_INIT   {1, 1, 1}
#define GLM_IVEC3_ZERO_INIT  {0, 0, 0}

#define GLM_IVEC3_ONE  ((ivec3)GLM_IVEC3_ONE_INIT)
#define GLM_IVEC3_ZERO ((ivec3)GLM_IVEC3_ZERO_INIT)

/*!
 * @brief init ivec3 using ivec4
 *
 * @param[in]  v4   vector4
 * @param[out] dest destination
 */
CGLM_INLINE
void
glm_ivec3(ivec4 v4, ivec3 dest) {
  dest[0] = v4[0];
  dest[1] = v4[1];
  dest[2] = v4[2];
}

/*!
 * @brief copy all members of [a] to [dest]
 *
 * @param[in]  a    source vector
 * @param[out] dest destination
 */
CGLM_INLINE
void
glm_ivec3_copy(ivec3 a, ivec3 dest) {
  dest[0] = a[0];
  dest[1] = a[1];
  dest[2] = a[2];
}

/*!
 * @brief set all members of [v] to zero
 *
 * @param[out] v vector
 */
CGLM_INLINE
void 
glm_ivec3_zero(ivec3 v) {
  v[0] = v[1] = v[2] = 0;
}

/*!
 * @brief set all members of [v] to one
 *
 * @param[out] v vector
 */
CGLM_INLINE
void
glm_ivec3_one(ivec3 v) {
  v[0] = v[1] = v[2] = 1;
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
glm_ivec3_dot(ivec3 a, ivec3 b) {
  return a[0] * b[0] + a[1] * b[1] + a[2] * b[2];
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
glm_ivec3_norm2(ivec3 v) {
  return glm_ivec3_dot(v, v);
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
glm_ivec3_norm(ivec3 v) {
  return (int)sqrtf(glm_ivec3_norm2(v));
}

/*!
 * @brief add vector [a] to vector [b] and store result in [dest]
 *
 * @param[in]  a    first vector
 * @param[in]  b    second vector
 * @param[out] dest destination
 */
CGLM_INLINE
void
glm_ivec3_add(ivec3 a, ivec3 b, ivec3 dest) {
  dest[0] = a[0] + b[0];
  dest[1] = a[1] + b[1];
  dest[2] = a[2] + b[2];
}

/*!
 * @brief add scalar s to vector [v] and store result in [dest]
 *
 * @param[in]  v    vector
 * @param[in]  s    scalar
 * @param[out] dest destination
 */
CGLM_INLINE
void
glm_ivec3_adds(ivec3 v, int s, ivec3 dest) {
  dest[0] = v[0] + s;
  dest[1] = v[1] + s;
  dest[2] = v[2] + s;
}

/*!
 * @brief subtract vector [b] from vector [a] and store result in [dest]
 *
 * @param[in]  a    first vector
 * @param[in]  b    second vector
 * @param[out] dest destination
 */
CGLM_INLINE
void
glm_ivec3_sub(ivec3 a, ivec3 b, ivec3 dest) {
  dest[0] = a[0] - b[0];
  dest[1] = a[1] - b[1];
  dest[2] = a[2] - b[2];
}

/*!
 * @brief subtract scalar s from vector [v] and store result in [dest]
 *
 * @param[in]  v    vector
 * @param[in]  s    scalar
 * @param[out] dest destination
 */
CGLM_INLINE
void
glm_ivec3_subs(ivec3 v, int s, ivec3 dest) {
  dest[0] = v[0] - s;
  dest[1] = v[1] - s;
  dest[2] = v[2] - s;
}

/*!
 * @brief multiply vector [a] with vector [b] and store result in [dest]
 *
 * @param[in]  a    frist vector
 * @param[in]  b    second vector
 * @param[out] dest destination
 */
CGLM_INLINE
void
glm_ivec3_mul(ivec3 a, ivec3 b, ivec3 dest) {
  dest[0] = a[0] * b[0];
  dest[1] = a[1] * b[1];
  dest[2] = a[2] * b[2];
}

/*!
 * @brief multiply vector [a] with scalar s and store result in [dest]
 *
 * @param[in]  v    vector
 * @param[in]  s    scalar
 * @param[out] dest destination
 */
CGLM_INLINE
void
glm_ivec3_scale(ivec3 v, int s, ivec3 dest) {
  dest[0] = v[0] * s;
  dest[1] = v[1] * s;
  dest[2] = v[2] * s;
}

/*!
 * @brief div vector with another component-wise division: d = a / b
 *
 * @param[in]  a    vector 1
 * @param[in]  b    vector 2
 * @param[out] dest result = (a[0]/b[0], a[1]/b[1], a[2]/b[2])
 */
CGLM_INLINE
void
glm_ivec3_div(ivec3 a, ivec3 b, ivec3 dest) {
  dest[0] = a[0] / b[0];
  dest[1] = a[1] / b[1];
  dest[2] = a[2] / b[2];
}

/*!
 * @brief div vector with scalar: d = v / s
 *
 * @param[in]  v    vector
 * @param[in]  s    scalar
 * @param[out] dest result = (a[0]/s, a[1]/s, a[2]/s)
 */
CGLM_INLINE
void
glm_ivec3_divs(ivec3 v, int s, ivec3 dest) {
  dest[0] = v[0] / s;
  dest[1] = v[1] / s;
  dest[2] = v[2] / s;
}

/*!
 * @brief Element-wise modulo operation on ivec3 vectors: dest = a % b
 *
 * Performs element-wise modulo on each component of vectors `a` and `b`.
 *
 * @param[in]  a    vector 1
 * @param[in]  b    vector 2
 * @param[out] dest result = (a[0]%b[0], a[1]%b[1], a[2]%b[2])
 */
CGLM_INLINE
void
glm_ivec3_mod(ivec3 a, ivec3 b, ivec3 dest) {
  dest[0] = a[0] % b[0];
  dest[1] = a[1] % b[1];
  dest[2] = a[2] % b[2];
}

/*!
 * @brief add vector [a] with vector [b] and add result to vector [dest]
 *
 * applies += operator so dest must be initialized
 *
 * @param[in]  a    first vector
 * @param[in]  b    second vector
 * @param[out] dest dest += (a + b)
 */
CGLM_INLINE 
void 
glm_ivec3_addadd(ivec3 a, ivec3 b, ivec3 dest) {
  dest[0] += a[0] + b[0];
  dest[1] += a[1] + b[1];
  dest[2] += a[2] + b[2];
}

/*!
 * @brief add scalar [s] onto vector [a] and add result to vector [dest]
 *
 * applies += operator so dest must be initialized
 *
 * @param[in]  a    vector
 * @param[in]  s    scalar
 * @param[out] dest dest += (a + s)
 */
CGLM_INLINE 
void 
glm_ivec3_addadds(ivec3 a, int s, ivec3 dest) {
  dest[0] += a[0] + s;
  dest[1] += a[1] + s;
  dest[2] += a[2] + s;
}

/*!
 * @brief subtract vector [a] from vector [b] and add result to [dest]
 *
 * applies += operator so dest must be initialized
 *
 * @param[in]  a    first vector
 * @param[in]  b    second vector
 * @param[out] dest dest += (a - b)  
 */
CGLM_INLINE 
void 
glm_ivec3_subadd(ivec3 a, ivec3 b, ivec3 dest) {
  dest[0] += a[0] - b[0];
  dest[1] += a[1] - b[1];
  dest[2] += a[2] - b[2];
}

/*!
 * @brief subtract scalar [s] from vector [a] and add result to [dest]
 *
 * applies += operator so dest must be initialized
 *
 * @param[in]  a    first
 * @param[in]  s    scalar
 * @param[out] dest dest += (a - s)
 */
CGLM_INLINE 
void 
glm_ivec3_subadds(ivec3 a, int s, ivec3 dest) {
  dest[0] += a[0] - s;
  dest[1] += a[1] - s;
  dest[2] += a[2] - s;
}

/*!
 * @brief multiply vector [a] with vector [b] and add result to [dest]
 *
 * applies += operator so dest must be initialized
 *
 * @param[in]  a    first vector
 * @param[in]  b    second vector
 * @param[out] dest dest += (a * b)
 */
CGLM_INLINE 
void 
glm_ivec3_muladd(ivec3 a, ivec3 b, ivec3 dest) {
  dest[0] += a[0] * b[0];
  dest[1] += a[1] * b[1];
  dest[2] += a[2] * b[2];
}

/*!
 * @brief multiply vector [a] with scalar [s] and add result to [dest]
 *
 * applies += operator so dest must be initialized
 *
 * @param[in]  a    vector
 * @param[in]  s    scalar
 * @param[out] dest dest += (a * s)
 */
CGLM_INLINE 
void 
glm_ivec3_muladds(ivec3 a, int s, ivec3 dest) {
  dest[0] += a[0] * s;
  dest[1] += a[1] * s;
  dest[2] += a[2] * s;
}

/*!
 * @brief add maximum of vector [a] and vector [b] to vector [dest]
 *
 * applies += operator so dest must be initialized
 *
 * @param[in]  a    first vector
 * @param[in]  b    second vector
 * @param[out] dest dest += max(a, b)
 */
CGLM_INLINE 
void 
glm_ivec3_maxadd(ivec3 a, ivec3 b, ivec3 dest) {
  dest[0] += glm_imax(a[0], b[0]);
  dest[1] += glm_imax(a[1], b[1]);
  dest[2] += glm_imax(a[2], b[2]);
}

/*!
 * @brief add minimum of vector [a] and vector [b] to vector [dest]
 *
 * applies += operator so dest must be initialized
 *
 * @param[in]  a    first vector
 * @param[in]  b    second vector
 * @param[out] dest dest += min(a, b)
 */
CGLM_INLINE 
void 
glm_ivec3_minadd(ivec3 a, ivec3 b, ivec3 dest) {
  dest[0] += glm_imin(a[0], b[0]);
  dest[1] += glm_imin(a[1], b[1]);
  dest[2] += glm_imin(a[2], b[2]);
}

/*!
 * @brief subtract vector [a] from vector [b] and subtract result from [dest]
 *
 * applies -= operator so dest must be initialized
 *
 * @param[in]  a    first vector
 * @param[in]  b    second vector
 * @param[out] dest dest -= (a - b)
 */
CGLM_INLINE 
void 
glm_ivec3_subsub(ivec3 a, ivec3 b, ivec3 dest) {
  dest[0] -= a[0] - b[0];
  dest[1] -= a[1] - b[1];
  dest[2] -= a[2] - b[2];
}

/*!
 * @brief subtract scalar [s] from vector [a] and subtract result from [dest]
 *
 * applies -= operator so dest must be initialized
 *
 * @param[in]  a    vector
 * @param[in]  s    scalar
 * @param[out] dest dest -= (a - s)
 */
CGLM_INLINE 
void 
glm_ivec3_subsubs(ivec3 a, int s, ivec3 dest) {
  dest[0] -= a[0] - s;
  dest[1] -= a[1] - s;
  dest[2] -= a[2] - s;
}

/*!
 * @brief add vector [a] to vector [b] and subtract the result from [dest]
 *
 * applies -= operator so dest must be initialized
 *
 * @param[in]  a    vector
 * @param[in]  b    scalar
 * @param[out] dest dest -= (a + b)
 */
CGLM_INLINE 
void 
glm_ivec3_addsub(ivec3 a, ivec3 b, ivec3 dest) {
  dest[0] -= a[0] + b[0];
  dest[1] -= a[1] + b[1];
  dest[2] -= a[2] + b[2];
}

/*!
 * @brief add scalar [s] to vector [a] and subtract the result from [dest]
 *
 * applies -= operator so dest must be initialized
 *
 * @param[in]  a    vector
 * @param[in]  s    scalar
 * @param[out] dest dest -= (a + b)
 */
CGLM_INLINE 
void 
glm_ivec3_addsubs(ivec3 a, int s, ivec3 dest) {
  dest[0] -= a[0] + s;
  dest[1] -= a[1] + s;
  dest[2] -= a[2] + s;
}

/*!
 * @brief multiply vector [a] and vector [b] and subtract the result from [dest]
 *
 * applies -= operator so dest must be initialized
 *
 * @param[in]  a    vector
 * @param[in]  b    scalar
 * @param[out] dest dest -= (a * b)
 */
CGLM_INLINE 
void 
glm_ivec3_mulsub(ivec3 a, ivec3 b, ivec3 dest) {
  dest[0] -= a[0] * b[0];
  dest[1] -= a[1] * b[1];
  dest[2] -= a[2] * b[2];
}

/*!
 * @brief multiply vector [a] with scalar [s] and subtract the result from [dest]
 *
 * applies -= operator so dest must be initialized
 *
 * @param[in]  a    vector
 * @param[in]  s    scalar
 * @param[out] dest dest -= (a * s)
 */
CGLM_INLINE 
void 
glm_ivec3_mulsubs(ivec3 a, int s, ivec3 dest) {
  dest[0] -= a[0] * s;
  dest[1] -= a[1] * s;
  dest[2] -= a[2] * s;
}

/*!
 * @brief subtract maximum of vector [a] and vector [b] from vector [dest]
 *
 * applies += operator so dest must be initialized
 *
 * @param[in]  a    first vector
 * @param[in]  b    second vector
 * @param[out] dest dest -= max(a, b)
 */
CGLM_INLINE 
void 
glm_ivec3_maxsub(ivec3 a, ivec3 b, ivec3 dest) {
  dest[0] -= glm_imax(a[0], b[0]);
  dest[1] -= glm_imax(a[1], b[1]);
  dest[2] -= glm_imax(a[2], b[2]);
}

/*!
 * @brief subtract minimum of vector [a] and vector [b] from vector [dest]
 *
 * applies -= operator so dest must be initialized
 *
 * @param[in]  a    first vector
 * @param[in]  b    second vector
 * @param[out] dest dest -= min(a, b)
 */
CGLM_INLINE 
void 
glm_ivec3_minsub(ivec3 a, ivec3 b, ivec3 dest) {
  dest[0] -= glm_imin(a[0], b[0]);
  dest[1] -= glm_imin(a[1], b[1]);
  dest[2] -= glm_imin(a[2], b[2]);
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
glm_ivec3_distance2(ivec3 a, ivec3 b) {
  int xd, yd, zd;
  xd = a[0] - b[0];
  yd = a[1] - b[1];
  zd = a[2] - b[2];
  return xd * xd + yd * yd + zd * zd;
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
glm_ivec3_distance(ivec3 a, ivec3 b) {
  return sqrtf((float)glm_ivec3_distance2(a, b));
}

/*!
 * @brief fill a vector with specified value
 *
 * @param[out] v   dest
 * @param[in]  val value
 */
CGLM_INLINE
void
glm_ivec3_fill(ivec3 v, int val) {
  v[0] = v[1] = v[2] = val;
}

/*!
 * @brief check if vector is equal to value
 *
 * @param[in] v   vector
 * @param[in] val value
 */
CGLM_INLINE
bool
glm_ivec3_eq(ivec3 v, int val) {
  return v[0] == val && v[0] == v[1] && v[0] == v[2];
}

/*!
 * @brief check if vector is equal to another
 *
 * @param[in] a vector
 * @param[in] b vector
 */
CGLM_INLINE
bool
glm_ivec3_eqv(ivec3 a, ivec3 b) {
  return a[0] == b[0]
         && a[1] == b[1]
         && a[2] == b[2];
}

/*!
 * @brief set each member of dest to greater of vector a and b
 *
 * @param[in]  a    first vector
 * @param[in]  b    second vector
 * @param[out] dest destination
 */
CGLM_INLINE
void
glm_ivec3_maxv(ivec3 a, ivec3 b, ivec3 dest) {
  dest[0] = a[0] > b[0] ? a[0] : b[0];
  dest[1] = a[1] > b[1] ? a[1] : b[1];
  dest[2] = a[2] > b[2] ? a[2] : b[2];
}

/*!
 * @brief set each member of dest to lesser of vector a and b
 *
 * @param[in]  a    first vector
 * @param[in]  b    second vector
 * @param[out] dest destination
 */
CGLM_INLINE
void
glm_ivec3_minv(ivec3 a, ivec3 b, ivec3 dest) {
  dest[0] = a[0] < b[0] ? a[0] : b[0];
  dest[1] = a[1] < b[1] ? a[1] : b[1];
  dest[2] = a[2] < b[2] ? a[2] : b[2];
}

/*!
 * @brief clamp each member of [v] between minVal and maxVal (inclusive)
 *
 * @param[in, out] v      vector
 * @param[in]      minVal minimum value
 * @param[in]      maxVal maximum value
 */
CGLM_INLINE
void
glm_ivec3_clamp(ivec3 v, int minVal, int maxVal) {
  if (v[0] < minVal)
    v[0] = minVal;
  else if(v[0] > maxVal)
    v[0] = maxVal;

  if (v[1] < minVal)
    v[1] = minVal;
  else if(v[1] > maxVal)
    v[1] = maxVal;

  if (v[2] < minVal)
    v[2] = minVal;
  else if(v[2] > maxVal)
    v[2] = maxVal;
}

/*!
 * @brief absolute value of v
 *
 * @param[in]	v	vector
 * @param[out]	dest	destination
 */
CGLM_INLINE
void
glm_ivec3_abs(ivec3 v, ivec3 dest) {
  dest[0] = abs(v[0]);
  dest[1] = abs(v[1]);
  dest[2] = abs(v[2]);
}

#endif /* cglm_ivec3_h */
