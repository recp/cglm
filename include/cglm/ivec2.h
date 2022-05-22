/*
 * Copyright (c), Recep Aslantas.
 *
 * MIT License (MIT), http://opensource.org/licenses/MIT
 * Full license can be found in the LICENSE file
 */

/*
FUNCTIONS:
  CGLM_INLINE void glm_ivec2(int * __restrict v, ivec2 dest)
  CGLM_INLINE void glm_ivec2_copy(ivec2 a, ivec2 dest)
  CGLM_INLINE void glm_ivec2_zero(ivec2 v)
  CGLM_INLINE void glm_ivec2_one(ivec2 v)
  CGLM_INLINE void glm_ivec2_add(ivec2 a, ivec2 b, ivec2 dest)
  CGLM_INLINE void glm_ivec2_adds(ivec2 v, int s, ivec2 dest)
  CGLM_INLINE void glm_ivec2_sub(ivec2 a, ivec2 b, ivec2 dest)
  CGLM_INLINE void glm_ivec2_subs(ivec2 v, int s, ivec2 dest)
  CGLM_INLINE void glm_ivec2_mul(ivec2 a, ivec2 b, ivec2 dest)
  CGLM_INLINE void glm_ivec2_scale(ivec2 v, int s, ivec2 dest)
  CGLM_INLINE int glm_ivec2_distance2(ivec2 a, ivec2 b)
  CGLM_INLINE float glm_ivec2_distance(ivec2 a, ivec2 b)
  CGLM_INLINE void glm_ivec2_maxv(ivec2 a, ivec2 b, ivec2 dest)
  CGLM_INLINE void glm_ivec2_minv(ivec2 a, ivec2 b, ivec2 dest)
  CGLM_INLINE void glm_ivec2_clamp(ivec2 v, int minVal, int maxVal)
 */

#ifndef cglm_ivec2_h
#define cglm_ivec2_h

#include "common.h"

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

#endif /* cglm_ivec2_h */
