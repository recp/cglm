/*
 * Copyright (c), Recep Aslantas.
 *
 * MIT License (MIT), http://opensource.org/licenses/MIT
 * Full license can be found in the LICENSE file
 */

/*
 Macros:
   GLM_IVEC2_ONE_INIT
   GLM_IVEC2_ZERO_INIT
   GLM_IVEC2_ONE
   GLM_IVEC2_ZERO

 Functions:
  CGLM_INLINE void glm_ivec2(int * __restrict v, ivec2 dest)
  CGLM_INLINE void glm_ivec2_copy(ivec2 a, ivec2 dest)
  CGLM_INLINE void glm_ivec2_zero(ivec2 v)
  CGLM_INLINE void glm_ivec2_one(ivec2 v)
  CGLM_INLINE int glm_ivec2_dot(ivec2 a, ivec2 b)
  CGLM_INLINE int glm_ivec2_cross(ivec2 a, ivec2 b)
  CGLM_INLINE void glm_ivec2_add(ivec2 a, ivec2 b, ivec2 dest)
  CGLM_INLINE void glm_ivec2_adds(ivec2 v, int s, ivec2 dest)
  CGLM_INLINE void glm_ivec2_sub(ivec2 a, ivec2 b, ivec2 dest)
  CGLM_INLINE void glm_ivec2_subs(ivec2 v, int s, ivec2 dest)
  CGLM_INLINE void glm_ivec2_mul(ivec2 a, ivec2 b, ivec2 dest)
  CGLM_INLINE void glm_ivec2_scale(ivec2 v, int s, ivec2 dest)
  CGLM_INLINE void glm_ivec2_div(ivec2 a, ivec2 b, ivec2 dest)
  CGLM_INLINE void glm_ivec2_divs(ivec2 v, int s, ivec2 dest)
  CGLM_INLINE void glm_ivec2_mod(ivec2 a, ivec2 b, ivec2 dest)
  CGLM_INLINE void glm_ivec2_addadd(ivec2 a, ivec2 b, ivec2 dest)
  CGLM_INLINE void glm_ivec2_addadds(ivec2 a, int s, ivec2 dest)
  CGLM_INLINE void glm_ivec2_subadd(ivec2 a, ivec2 b, ivec2 dest)
  CGLM_INLINE void glm_ivec2_subadds(ivec2 a, int s, ivec2 dest)
  CGLM_INLINE void glm_ivec2_muladd(ivec2 a, ivec2 b, ivec2 dest)
  CGLM_INLINE void glm_ivec2_muladds(ivec2 a, int s, ivec2 dest)
  CGLM_INLINE void glm_ivec2_maxadd(ivec2 a, ivec2 b, ivec2 dest)
  CGLM_INLINE void glm_ivec2_minadd(ivec2 a, ivec2 b, ivec2 dest)
  CGLM_INLINE void glm_ivec2_subsub(ivec2 a, ivec2 b, ivec2 dest)
  CGLM_INLINE void glm_ivec2_subsubs(ivec2 a, int s, ivec2 dest)
  CGLM_INLINE void glm_ivec2_addsub(ivec2 a, ivec2 b, ivec2 dest)
  CGLM_INLINE void glm_ivec2_addsubs(ivec2 a, int s, ivec2 dest)
  CGLM_INLINE void glm_ivec2_mulsub(ivec2 a, ivec2 b, ivec2 dest)
  CGLM_INLINE void glm_ivec2_mulsubs(ivec2 a, int s, ivec2 dest)
  CGLM_INLINE void glm_ivec2_maxsub(ivec2 a, ivec2 b, ivec2 dest)
  CGLM_INLINE void glm_ivec2_minsub(ivec2 a, ivec2 b, ivec2 dest)
  CGLM_INLINE int glm_ivec2_distance2(ivec2 a, ivec2 b)
  CGLM_INLINE float glm_ivec2_distance(ivec2 a, ivec2 b)
  CGLM_INLINE void glm_ivec2_fill(ivec2 v, int val);
  CGLM_INLINE bool glm_ivec2_eq(ivec2 v, int val);
  CGLM_INLINE bool glm_ivec2_eqv(ivec2 a, ivec2 b);
  CGLM_INLINE void glm_ivec2_maxv(ivec2 a, ivec2 b, ivec2 dest)
  CGLM_INLINE void glm_ivec2_minv(ivec2 a, ivec2 b, ivec2 dest)
  CGLM_INLINE void glm_ivec2_clamp(ivec2 v, int minVal, int maxVal)
  CGLM_INLINE void glm_ivec2_abs(ivec2 v, ivec2 dest)
 */

#ifndef cglm_ivec2_h
#define cglm_ivec2_h

#include "common.h"
#include "util.h"

#define GLM_IVEC2_ONE_INIT   {1, 1}
#define GLM_IVEC2_ZERO_INIT  {0, 0}

#define GLM_IVEC2_ONE  ((ivec2)GLM_IVEC2_ONE_INIT)
#define GLM_IVEC2_ZERO ((ivec2)GLM_IVEC2_ZERO_INIT)

/*!
 * @brief init ivec2 using vec3 or vec4
 *
 * @param[in]  v    vector
 * @param[out] dest destination
 */
CGLM_INLINE
void
glm_ivec2(int * __restrict v, ivec2 dest) {
  dest[0] = v[0];
  dest[1] = v[1];
}

/*!
 * @brief copy all members of [a] to [dest]
 *
 * @param[in]  a    source vector
 * @param[out] dest destination
 */
CGLM_INLINE
void
glm_ivec2_copy(ivec2 a, ivec2 dest) {
  dest[0] = a[0];
  dest[1] = a[1];
}

/*!
 * @brief set all members of [v] to zero
 *
 * @param[out] v vector
 */
CGLM_INLINE
void 
glm_ivec2_zero(ivec2 v) {
  v[0] = v[1] = 0;
}

/*!
 * @brief set all members of [v] to one
 *
 * @param[out] v vector
 */
CGLM_INLINE
void
glm_ivec2_one(ivec2 v) {
  v[0] = v[1] = 1;
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
glm_ivec2_dot(ivec2 a, ivec2 b) {
  return a[0] * b[0] + a[1] * b[1];
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
glm_ivec2_cross(ivec2 a, ivec2 b) {
  return a[0] * b[1] - a[1] * b[0];
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
glm_ivec2_add(ivec2 a, ivec2 b, ivec2 dest) {
  dest[0] = a[0] + b[0];
  dest[1] = a[1] + b[1];
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
glm_ivec2_adds(ivec2 v, int s, ivec2 dest) {
  dest[0] = v[0] + s;
  dest[1] = v[1] + s;
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
glm_ivec2_sub(ivec2 a, ivec2 b, ivec2 dest) {
  dest[0] = a[0] - b[0];
  dest[1] = a[1] - b[1];
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
glm_ivec2_subs(ivec2 v, int s, ivec2 dest) {
  dest[0] = v[0] - s;
  dest[1] = v[1] - s;
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
glm_ivec2_mul(ivec2 a, ivec2 b, ivec2 dest) {
  dest[0] = a[0] * b[0];
  dest[1] = a[1] * b[1];
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
glm_ivec2_scale(ivec2 v, int s, ivec2 dest) {
  dest[0] = v[0] * s;
  dest[1] = v[1] * s;
}

/*!
 * @brief div vector with another component-wise division: d = a / b
 *
 * @param[in]  a    vector 1
 * @param[in]  b    vector 2
 * @param[out] dest result = (a[0]/b[0], a[1]/b[1])
 */
CGLM_INLINE
void
glm_ivec2_div(ivec2 a, ivec2 b, ivec2 dest) {
  dest[0] = a[0] / b[0];
  dest[1] = a[1] / b[1];
}

/*!
 * @brief div vector with scalar: d = v / s
 *
 * @param[in]  v    vector
 * @param[in]  s    scalar
 * @param[out] dest result = (a[0]/s, a[1]/s)
 */
CGLM_INLINE
void
glm_ivec2_divs(ivec2 v, int s, ivec2 dest) {
  dest[0] = v[0] / s;
  dest[1] = v[1] / s;
}

/*!
 * @brief mod vector with another component-wise modulo: d = a % b
 *
 * @param[in]  a    vector 1
 * @param[in]  b    vector 2
 * @param[out] dest result = (a[0]%b[0], a[1]%b[1])
 */
CGLM_INLINE
void
glm_ivec2_mod(ivec2 a, ivec2 b, ivec2 dest) {
  dest[0] = a[0] % b[0];
  dest[1] = a[1] % b[1];
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
glm_ivec2_addadd(ivec2 a, ivec2 b, ivec2 dest) {
  dest[0] += a[0] + b[0];
  dest[1] += a[1] + b[1];
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
glm_ivec2_addadds(ivec2 a, int s, ivec2 dest) {
  dest[0] += a[0] + s;
  dest[1] += a[1] + s;
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
glm_ivec2_subadd(ivec2 a, ivec2 b, ivec2 dest) {
  dest[0] += a[0] - b[0];
  dest[1] += a[1] - b[1];
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
glm_ivec2_subadds(ivec2 a, int s, ivec2 dest) {
  dest[0] += a[0] - s;
  dest[1] += a[1] - s;
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
glm_ivec2_muladd(ivec2 a, ivec2 b, ivec2 dest) {
  dest[0] += a[0] * b[0];
  dest[1] += a[1] * b[1];
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
glm_ivec2_muladds(ivec2 a, int s, ivec2 dest) {
  dest[0] += a[0] * s;
  dest[1] += a[1] * s;
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
glm_ivec2_maxadd(ivec2 a, ivec2 b, ivec2 dest) {
  dest[0] += glm_imax(a[0], b[0]);
  dest[1] += glm_imax(a[1], b[1]);
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
glm_ivec2_minadd(ivec2 a, ivec2 b, ivec2 dest) {
  dest[0] += glm_imin(a[0], b[0]);
  dest[1] += glm_imin(a[1], b[1]);
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
glm_ivec2_subsub(ivec2 a, ivec2 b, ivec2 dest) {
  dest[0] -= a[0] - b[0];
  dest[1] -= a[1] - b[1];
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
glm_ivec2_subsubs(ivec2 a, int s, ivec2 dest) {
  dest[0] -= a[0] - s;
  dest[1] -= a[1] - s;
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
glm_ivec2_addsub(ivec2 a, ivec2 b, ivec2 dest) {
  dest[0] -= a[0] + b[0];
  dest[1] -= a[1] + b[1];
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
glm_ivec2_addsubs(ivec2 a, int s, ivec2 dest) {
  dest[0] -= a[0] + s;
  dest[1] -= a[1] + s;
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
glm_ivec2_mulsub(ivec2 a, ivec2 b, ivec2 dest) {
  dest[0] -= a[0] * b[0];
  dest[1] -= a[1] * b[1];
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
glm_ivec2_mulsubs(ivec2 a, int s, ivec2 dest) {
  dest[0] -= a[0] * s;
  dest[1] -= a[1] * s;
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
glm_ivec2_maxsub(ivec2 a, ivec2 b, ivec2 dest) {
  dest[0] -= glm_imax(a[0], b[0]);
  dest[1] -= glm_imax(a[1], b[1]);
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
glm_ivec2_minsub(ivec2 a, ivec2 b, ivec2 dest) {
  dest[0] -= glm_imin(a[0], b[0]);
  dest[1] -= glm_imin(a[1], b[1]);
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
glm_ivec2_distance2(ivec2 a, ivec2 b) {
  int xd, yd;
  xd = a[0] - b[0];
  yd = a[1] - b[1];
  return xd * xd + yd * yd;
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
glm_ivec2_distance(ivec2 a, ivec2 b) {
  return sqrtf((float)glm_ivec2_distance2(a, b));
}


/*!
 * @brief fill a vector with specified value
 *
 * @param[out] v   dest
 * @param[in]  val value
 */
CGLM_INLINE
void
glm_ivec2_fill(ivec2 v, int val) {
  v[0] = v[1] = val;
}

/*!
 * @brief check if vector is equal to value
 *
 * @param[in] v   vector
 * @param[in] val value
 */
CGLM_INLINE
bool
glm_ivec2_eq(ivec2 v, int val) {
  return v[0] == val && v[0] == v[1];
}

/*!
 * @brief check if vector is equal to another
 *
 * @param[in] a vector
 * @param[in] b vector
 */
CGLM_INLINE
bool
glm_ivec2_eqv(ivec2 a, ivec2 b) {
  return a[0] == b[0]
         && a[1] == b[1];
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
glm_ivec2_maxv(ivec2 a, ivec2 b, ivec2 dest) {
  dest[0] = a[0] > b[0] ? a[0] : b[0];
  dest[1] = a[1] > b[1] ? a[1] : b[1];
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
glm_ivec2_minv(ivec2 a, ivec2 b, ivec2 dest) {
  dest[0] = a[0] < b[0] ? a[0] : b[0];
  dest[1] = a[1] < b[1] ? a[1] : b[1];
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
glm_ivec2_clamp(ivec2 v, int minVal, int maxVal) {
  if (v[0] < minVal)
    v[0] = minVal;
  else if(v[0] > maxVal)
    v[0] = maxVal;

  if (v[1] < minVal)
    v[1] = minVal;
  else if(v[1] > maxVal)
    v[1] = maxVal;
}

/*!
 * @brief absolute value of v
 *
 * @param[in]	v	vector
 * @param[out]	dest	destination
 */
CGLM_INLINE
void
glm_ivec2_abs(ivec2 v, ivec2 dest) {
  dest[0] = abs(v[0]);
  dest[1] = abs(v[1]);
}

#endif /* cglm_ivec2_h */
