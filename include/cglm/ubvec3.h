/*
 * Copyright (c), Recep Aslantas.
 *
 * MIT License (MIT), http://opensource.org/licenses/MIT
 * Full license can be found in the LICENSE file
 */

/*
 Macros:
   GLM_UBVEC3_ONE_INIT
   GLM_UBVEC3_ZERO_INIT
   GLM_UBVEC3_ONE
   GLM_UBVEC3_ZERO

 Functions:
  CGLM_INLINE void glm_ubvec3(ubvec4 v4, ubvec3 dest)
  CGLM_INLINE void glm_ubvec3_copy(ubvec3 a, ubvec3 dest)
  CGLM_INLINE void glm_ubvec3_zero(ubvec3 v)
  CGLM_INLINE void glm_ubvec3_one(ubvec3 v)
  CGLM_INLINE void glm_ubvec3_add(ubvec3 a, ubvec3 b, ubvec3 dest)
  CGLM_INLINE void glm_ubvec3_adds(ubvec3 v, uint8_t s, ubvec3 dest)
  CGLM_INLINE void glm_ubvec3_sub(ubvec3 a, ubvec3 b, ubvec3 dest)
  CGLM_INLINE void glm_ubvec3_subs(ubvec3 v, uint8_t s, ubvec3 dest)
  CGLM_INLINE void glm_ubvec3_mul(ubvec3 a, ubvec3 b, ubvec3 dest)
  CGLM_INLINE void glm_ubvec3_scale(ubvec3 v, uint8_t s, ubvec3 dest)
  CGLM_INLINE uint8_t glm_ubvec3_distance2(ubvec3 a, ubvec3 b)
  CGLM_INLINE float glm_ubvec3_distance(ubvec3 a, ubvec3 b)
  CGLM_INLINE void glm_ubvec3_fill(ubvec3 v, uint8_t val);
  CGLM_INLINE bool glm_ubvec3_eq(ubvec3 v, uint8_t val);
  CGLM_INLINE bool glm_ubvec3_eqv(ubvec3 a, ubvec3 b);
  CGLM_INLINE void glm_ubvec3_maxv(ubvec3 a, ubvec3 b, ubvec3 dest)
  CGLM_INLINE void glm_ubvec3_minv(ubvec3 a, ubvec3 b, ubvec3 dest)
  CGLM_INLINE void glm_ubvec3_clamp(ubvec3 v, uint8_t minVal, uint8_t maxVal)
  CGLM_INLINE void glm_ubvec3_abs(ubvec3 v, ubvec3 dest)
 */

#ifndef cglm_ubvec3_h
#define cglm_ubvec3_h

#include "common.h"

#define GLM_UBVEC3_ONE_INIT   {1, 1, 1}
#define GLM_UBVEC3_ZERO_INIT  {0, 0, 0}

#define GLM_UBVEC3_ONE  ((ubvec3)GLM_UBVEC3_ONE_INIT)
#define GLM_UBVEC3_ZERO ((ubvec3)GLM_UBVEC3_ZERO_INIT)

/*!
 * @brief init ubvec3 using ubvec4
 *
 * @param[in]  v4   vector4
 * @param[out] dest destination
 */
CGLM_INLINE
void
glm_ubvec3(ubvec4 v4, ubvec3 dest) {
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
glm_ubvec3_copy(ubvec3 a, ubvec3 dest) {
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
glm_ubvec3_zero(ubvec3 v) {
  v[0] = v[1] = v[2] = 0;
}

/*!
 * @brief set all members of [v] to one
 *
 * @param[out] v vector
 */
CGLM_INLINE
void
glm_ubvec3_one(ubvec3 v) {
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
glm_ubvec3_add(ubvec3 a, ubvec3 b, ubvec3 dest) {
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
glm_ubvec3_adds(ubvec3 v, uint8_t s, ubvec3 dest) {
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
glm_ubvec3_sub(ubvec3 a, ubvec3 b, ubvec3 dest) {
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
glm_ubvec3_subs(ubvec3 v, uint8_t s, ubvec3 dest) {
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
glm_ubvec3_mul(ubvec3 a, ubvec3 b, ubvec3 dest) {
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
glm_ubvec3_scale(ubvec3 v, uint8_t s, ubvec3 dest) {
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
glm_ubvec3_distance2(ubvec3 a, ubvec3 b) {
  uint8_t xd, yd, zd;
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
glm_ubvec3_distance(ubvec3 a, ubvec3 b) {
  return sqrtf((float)glm_ubvec3_distance2(a, b));
}

/*!
 * @brief fill a vector with specified value
 *
 * @param[out] v   dest
 * @param[in]  val value
 */
CGLM_INLINE
void
glm_ubvec3_fill(ubvec3 v, uint8_t val) {
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
glm_ubvec3_eq(ubvec3 v, uint8_t val) {
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
glm_ubvec3_eqv(ubvec3 a, ubvec3 b) {
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
glm_ubvec3_maxv(ubvec3 a, ubvec3 b, ubvec3 dest) {
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
glm_ubvec3_minv(ubvec3 a, ubvec3 b, ubvec3 dest) {
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
glm_ubvec3_clamp(ubvec3 v, uint8_t minVal, uint8_t maxVal) {
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
glm_ubvec3_abs(ubvec3 v, ubvec3 dest) {
  dest[0] = abs(v[0]);
  dest[1] = abs(v[1]);
  dest[2] = abs(v[2]);
}

#endif /* cglm_ubvec3_h */
