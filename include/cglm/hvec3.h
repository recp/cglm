/*
 * Copyright (c), Recep Aslantas.
 *
 * MIT License (MIT), http://opensource.org/licenses/MIT
 * Full license can be found in the LICENSE file
 */

/*
 Macros:
   GLM_HVEC3_ONE_INIT
   GLM_HVEC3_ZERO_INIT
   GLM_HVEC3_ONE
   GLM_HVEC3_ZERO

 Functions:
  CGLM_INLINE void glm_hvec3(hvec4 v4, hvec3 dest)
  CGLM_INLINE void glm_hvec3_copy(hvec3 a, hvec3 dest)
  CGLM_INLINE void glm_hvec3_zero(hvec3 v)
  CGLM_INLINE void glm_hvec3_one(hvec3 v)
  CGLM_INLINE void glm_hvec3_add(hvec3 a, hvec3 b, hvec3 dest)
  CGLM_INLINE void glm_hvec3_adds(hvec3 v, int16_t s, hvec3 dest)
  CGLM_INLINE void glm_hvec3_sub(hvec3 a, hvec3 b, hvec3 dest)
  CGLM_INLINE void glm_hvec3_subs(hvec3 v, int16_t s, hvec3 dest)
  CGLM_INLINE void glm_hvec3_mul(hvec3 a, hvec3 b, hvec3 dest)
  CGLM_INLINE void glm_hvec3_scale(hvec3 v, int16_t s, hvec3 dest)
  CGLM_INLINE int16_t glm_hvec3_distance2(hvec3 a, hvec3 b)
  CGLM_INLINE float glm_hvec3_distance(hvec3 a, hvec3 b)
  CGLM_INLINE void glm_hvec3_fill(hvec3 v, int16_t val);
  CGLM_INLINE bool glm_hvec3_eq(hvec3 v, int16_t val);
  CGLM_INLINE bool glm_hvec3_eqv(hvec3 a, hvec3 b);
  CGLM_INLINE void glm_hvec3_maxv(hvec3 a, hvec3 b, hvec3 dest)
  CGLM_INLINE void glm_hvec3_minv(hvec3 a, hvec3 b, hvec3 dest)
  CGLM_INLINE void glm_hvec3_clamp(hvec3 v, int16_t minVal, int16_t maxVal)
  CGLM_INLINE void glm_hvec3_abs(hvec3 v, hvec3 dest)
 */

#ifndef cglm_hvec3_h
#define cglm_hvec3_h

#include "common.h"

#define GLM_HVEC3_ONE_INIT   {1, 1, 1}
#define GLM_HVEC3_ZERO_INIT  {0, 0, 0}

#define GLM_HVEC3_ONE  ((hvec3)GLM_HVEC3_ONE_INIT)
#define GLM_HVEC3_ZERO ((hvec3)GLM_HVEC3_ZERO_INIT)

/*!
 * @brief init hvec3 using hvec4
 *
 * @param[in]  v4   vector4
 * @param[out] dest destination
 */
CGLM_INLINE
void
glm_hvec3(hvec4 v4, hvec3 dest) {
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
glm_hvec3_copy(hvec3 a, hvec3 dest) {
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
glm_hvec3_zero(hvec3 v) {
  v[0] = v[1] = v[2] = 0;
}

/*!
 * @brief set all members of [v] to one
 *
 * @param[out] v vector
 */
CGLM_INLINE
void
glm_hvec3_one(hvec3 v) {
  v[0] = v[1] = v[2] = 1;
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
glm_hvec3_add(hvec3 a, hvec3 b, hvec3 dest) {
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
glm_hvec3_adds(hvec3 v, int16_t s, hvec3 dest) {
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
glm_hvec3_sub(hvec3 a, hvec3 b, hvec3 dest) {
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
glm_hvec3_subs(hvec3 v, int16_t s, hvec3 dest) {
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
glm_hvec3_mul(hvec3 a, hvec3 b, hvec3 dest) {
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
glm_hvec3_scale(hvec3 v, int16_t s, hvec3 dest) {
  dest[0] = v[0] * s;
  dest[1] = v[1] * s;
  dest[2] = v[2] * s;
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
glm_hvec3_distance2(hvec3 a, hvec3 b) {
  int16_t xd, yd, zd;
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
glm_hvec3_distance(hvec3 a, hvec3 b) {
  return sqrtf((float)glm_hvec3_distance2(a, b));
}

/*!
 * @brief fill a vector with specified value
 *
 * @param[out] v   dest
 * @param[in]  val value
 */
CGLM_INLINE
void
glm_hvec3_fill(hvec3 v, int16_t val) {
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
glm_hvec3_eq(hvec3 v, int16_t val) {
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
glm_hvec3_eqv(hvec3 a, hvec3 b) {
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
glm_hvec3_maxv(hvec3 a, hvec3 b, hvec3 dest) {
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
glm_hvec3_minv(hvec3 a, hvec3 b, hvec3 dest) {
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
glm_hvec3_clamp(hvec3 v, int16_t minVal, int16_t maxVal) {
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
glm_hvec3_abs(hvec3 v, hvec3 dest) {
  dest[0] = abs(v[0]);
  dest[1] = abs(v[1]);
  dest[2] = abs(v[2]);
}

#endif /* cglm_hvec3_h */
