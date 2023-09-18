/*
 * Copyright (c), Recep Aslantas.
 *
 * MIT License (MIT), http://opensource.org/licenses/MIT
 * Full license can be found in the LICENSE file
 */

/*
 Macros:
   GLM_HVEC4_ONE_INIT
   GLM_HVEC4_ZERO_INIT
   GLM_HVEC4_ONE
   GLM_HVEC4_ZERO

 Functions:
  CGLM_INLINE void glm_hvec4(hvec3 v3, int16_t last, hvec4 dest)
  CGLM_INLINE void glm_hvec4_copy(hvec4 a, hvec4 dest)
  CGLM_INLINE void glm_hvec4_zero(hvec4 v)
  CGLM_INLINE void glm_hvec4_one(hvec4 v)
  CGLM_INLINE void glm_hvec4_add(hvec4 a, hvec4 b, hvec4 dest)
  CGLM_INLINE void glm_hvec4_adds(hvec4 v, int16_t s, hvec4 dest)
  CGLM_INLINE void glm_hvec4_sub(hvec4 a, hvec4 b, hvec4 dest)
  CGLM_INLINE void glm_hvec4_subs(hvec4 v, int16_t s, hvec4 dest)
  CGLM_INLINE void glm_hvec4_mul(hvec4 a, hvec4 b, hvec4 dest)
  CGLM_INLINE void glm_hvec4_scale(hvec4 v, int16_t s, hvec4 dest)
  CGLM_INLINE int16_t glm_hvec4_distance2(hvec4 a, hvec4 b)
  CGLM_INLINE float glm_hvec4_distance(hvec4 a, hvec4 b)
  CGLM_INLINE void glm_hvec4_maxv(hvec4 a, hvec4 b, hvec4 dest)
  CGLM_INLINE void glm_hvec4_minv(hvec4 a, hvec4 b, hvec4 dest)
  CGLM_INLINE void glm_hvec4_clamp(hvec4 v, int16_t minVal, int16_t maxVal)
  CGLM_INLINE void glm_hvec4_abs(hvec4 v, hvec4 dest)
 */

#ifndef cglm_hvec4_h
#define cglm_hvec4_h

#include "common.h"

#define GLM_HVEC4_ONE_INIT   {1, 1, 1, 1}
#define GLM_HVEC4_ZERO_INIT  {0, 0, 0, 0}

#define GLM_HVEC4_ONE  ((hvec4)GLM_HVEC4_ONE_INIT)
#define GLM_HVEC4_ZERO ((hvec4)GLM_HVEC4_ZERO_INIT)

/*!
 * @brief init hvec4 using hvec3
 *
 * @param[in]  v3   vector3
 * @param[in]  last last item
 * @param[out] dest destination
 */
CGLM_INLINE
void
glm_hvec4(hvec3 v3, int16_t last, hvec4 dest) {
  dest[0] = v3[0];
  dest[1] = v3[1];
  dest[2] = v3[2];
  dest[3] = last;
}

/*!
 * @brief copy all members of [a] to [dest]
 *
 * @param[in]  a    source vector
 * @param[out] dest destination
 */
CGLM_INLINE
void
glm_hvec4_copy(hvec4 a, hvec4 dest) {
  dest[0] = a[0];
  dest[1] = a[1];
  dest[2] = a[2];
  dest[3] = a[3];
}

/*!
 * @brief set all members of [v] to zero
 *
 * @param[out] v vector
 */
CGLM_INLINE
void 
glm_hvec4_zero(hvec4 v) {
  v[0] = v[1] = v[2] = v[3] = 0;
}

/*!
 * @brief set all members of [v] to one
 *
 * @param[out] v vector
 */
CGLM_INLINE
void
glm_hvec4_one(hvec4 v) {
  v[0] = v[1] = v[2] = v[3] = 1;
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
glm_hvec4_add(hvec4 a, hvec4 b, hvec4 dest) {
  dest[0] = a[0] + b[0];
  dest[1] = a[1] + b[1];
  dest[2] = a[2] + b[2];
  dest[3] = a[3] + b[3];
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
glm_hvec4_adds(hvec4 v, int16_t s, hvec4 dest) {
  dest[0] = v[0] + s;
  dest[1] = v[1] + s;
  dest[2] = v[2] + s;
  dest[3] = v[3] + s;
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
glm_hvec4_sub(hvec4 a, hvec4 b, hvec4 dest) {
  dest[0] = a[0] - b[0];
  dest[1] = a[1] - b[1];
  dest[2] = a[2] - b[2];
  dest[3] = a[3] - b[3];
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
glm_hvec4_subs(hvec4 v, int16_t s, hvec4 dest) {
  dest[0] = v[0] - s;
  dest[1] = v[1] - s;
  dest[2] = v[2] - s;
  dest[3] = v[3] - s;
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
glm_hvec4_mul(hvec4 a, hvec4 b, hvec4 dest) {
  dest[0] = a[0] * b[0];
  dest[1] = a[1] * b[1];
  dest[2] = a[2] * b[2];
  dest[3] = a[3] * b[3];
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
glm_hvec4_scale(hvec4 v, int16_t s, hvec4 dest) {
  dest[0] = v[0] * s;
  dest[1] = v[1] * s;
  dest[2] = v[2] * s;
  dest[3] = v[3] * s;
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
glm_hvec4_distance2(hvec4 a, hvec4 b) {
  int16_t xd, yd, zd, wd;
  xd = a[0] - b[0];
  yd = a[1] - b[1];
  zd = a[2] - b[2];
  wd = a[3] - b[3];
  return xd * xd + yd * yd + zd * zd + wd * wd;
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
glm_hvec4_distance(hvec4 a, hvec4 b) {
  return sqrtf((float)glm_hvec4_distance2(a, b));
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
glm_hvec4_maxv(hvec4 a, hvec4 b, hvec4 dest) {
  dest[0] = a[0] > b[0] ? a[0] : b[0];
  dest[1] = a[1] > b[1] ? a[1] : b[1];
  dest[2] = a[2] > b[2] ? a[2] : b[2];
  dest[3] = a[3] > b[3] ? a[3] : b[3];
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
glm_hvec4_minv(hvec4 a, hvec4 b, hvec4 dest) {
  dest[0] = a[0] < b[0] ? a[0] : b[0];
  dest[1] = a[1] < b[1] ? a[1] : b[1];
  dest[2] = a[2] < b[2] ? a[2] : b[2];
  dest[3] = a[3] < b[3] ? a[3] : b[3];
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
glm_hvec4_clamp(hvec4 v, int16_t minVal, int16_t maxVal) {
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

  if (v[3] < minVal)
    v[3] = minVal;
  else if(v[3] > maxVal)
    v[3] = maxVal;
}

/*!
 * @brief absolute value of v
 *
 * @param[in]	v	vector
 * @param[out]	dest	destination
 */
CGLM_INLINE
void
glm_hvec4_abs(hvec4 v, hvec4 dest) {
  dest[0] = abs(v[0]);
  dest[1] = abs(v[1]);
  dest[2] = abs(v[2]);
  dest[3] = abs(v[3]);
}

#endif /* cglm_hvec4_h */
