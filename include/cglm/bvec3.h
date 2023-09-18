/*
 * Copyright (c), Recep Aslantas.
 *
 * MIT License (MIT), http://opensource.org/licenses/MIT
 * Full license can be found in the LICENSE file
 */

/*
 Macros:
   GLM_BVEC3_ONE_INIT
   GLM_BVEC3_ZERO_INIT
   GLM_BVEC3_ONE
   GLM_BVEC3_ZERO

 Functions:
  CGLM_INLINE void glm_bvec3(bvec4 v4, bvec3 dest)
  CGLM_INLINE void glm_bvec3_copy(bvec3 a, bvec3 dest)
  CGLM_INLINE void glm_bvec3_zero(bvec3 v)
  CGLM_INLINE void glm_bvec3_one(bvec3 v)
  CGLM_INLINE void glm_bvec3_add(bvec3 a, bvec3 b, bvec3 dest)
  CGLM_INLINE void glm_bvec3_adds(bvec3 v, int8_t s, bvec3 dest)
  CGLM_INLINE void glm_bvec3_sub(bvec3 a, bvec3 b, bvec3 dest)
  CGLM_INLINE void glm_bvec3_subs(bvec3 v, int8_t s, bvec3 dest)
  CGLM_INLINE void glm_bvec3_mul(bvec3 a, bvec3 b, bvec3 dest)
  CGLM_INLINE void glm_bvec3_scale(bvec3 v, int8_t s, bvec3 dest)
  CGLM_INLINE int8_t glm_bvec3_distance2(bvec3 a, bvec3 b)
  CGLM_INLINE float glm_bvec3_distance(bvec3 a, bvec3 b)
  CGLM_INLINE void glm_bvec3_fill(bvec3 v, int8_t val);
  CGLM_INLINE bool glm_bvec3_eq(bvec3 v, int8_t val);
  CGLM_INLINE bool glm_bvec3_eqv(bvec3 a, bvec3 b);
  CGLM_INLINE void glm_bvec3_maxv(bvec3 a, bvec3 b, bvec3 dest)
  CGLM_INLINE void glm_bvec3_minv(bvec3 a, bvec3 b, bvec3 dest)
  CGLM_INLINE void glm_bvec3_clamp(bvec3 v, int8_t minVal, int8_t maxVal)
  CGLM_INLINE void glm_bvec3_abs(bvec3 v, bvec3 dest)
 */

#ifndef cglm_bvec3_h
#define cglm_bvec3_h

#include "common.h"

#define GLM_BVEC3_ONE_INIT   {1, 1, 1}
#define GLM_BVEC3_ZERO_INIT  {0, 0, 0}

#define GLM_BVEC3_ONE  ((bvec3)GLM_BVEC3_ONE_INIT)
#define GLM_BVEC3_ZERO ((bvec3)GLM_BVEC3_ZERO_INIT)

/*!
 * @brief init bvec3 using bvec4
 *
 * @param[in]  v4   vector4
 * @param[out] dest destination
 */
CGLM_INLINE
void
glm_bvec3(bvec4 v4, bvec3 dest) {
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
glm_bvec3_copy(bvec3 a, bvec3 dest) {
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
glm_bvec3_zero(bvec3 v) {
  v[0] = v[1] = v[2] = 0;
}

/*!
 * @brief set all members of [v] to one
 *
 * @param[out] v vector
 */
CGLM_INLINE
void
glm_bvec3_one(bvec3 v) {
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
glm_bvec3_add(bvec3 a, bvec3 b, bvec3 dest) {
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
glm_bvec3_adds(bvec3 v, int8_t s, bvec3 dest) {
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
glm_bvec3_sub(bvec3 a, bvec3 b, bvec3 dest) {
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
glm_bvec3_subs(bvec3 v, int8_t s, bvec3 dest) {
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
glm_bvec3_mul(bvec3 a, bvec3 b, bvec3 dest) {
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
glm_bvec3_scale(bvec3 v, int8_t s, bvec3 dest) {
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
glm_bvec3_distance2(bvec3 a, bvec3 b) {
  int8_t xd, yd, zd;
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
glm_bvec3_distance(bvec3 a, bvec3 b) {
  return sqrtf((float)glm_bvec3_distance2(a, b));
}

/*!
 * @brief fill a vector with specified value
 *
 * @param[out] v   dest
 * @param[in]  val value
 */
CGLM_INLINE
void
glm_bvec3_fill(bvec3 v, int8_t val) {
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
glm_bvec3_eq(bvec3 v, int8_t val) {
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
glm_bvec3_eqv(bvec3 a, bvec3 b) {
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
glm_bvec3_maxv(bvec3 a, bvec3 b, bvec3 dest) {
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
glm_bvec3_minv(bvec3 a, bvec3 b, bvec3 dest) {
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
glm_bvec3_clamp(bvec3 v, int8_t minVal, int8_t maxVal) {
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
glm_bvec3_abs(bvec3 v, bvec3 dest) {
  dest[0] = abs(v[0]);
  dest[1] = abs(v[1]);
  dest[2] = abs(v[2]);
}

#endif /* cglm_bvec3_h */
