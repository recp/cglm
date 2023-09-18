/*
 * Copyright (c), Recep Aslantas.
 *
 * MIT License (MIT), http://opensource.org/licenses/MIT
 * Full license can be found in the LICENSE file
 */

/*
 Macros:
   GLM_BVEC2_ONE_INIT
   GLM_BVEC2_ZERO_INIT
   GLM_BVEC2_ONE
   GLM_BVEC2_ZERO

 Functions:
  CGLM_INLINE void glm_bvec2(int8_t * __restrict v, bvec2 dest)
  CGLM_INLINE void glm_bvec2_copy(bvec2 a, bvec2 dest)
  CGLM_INLINE void glm_bvec2_zero(bvec2 v)
  CGLM_INLINE void glm_bvec2_one(bvec2 v)
  CGLM_INLINE void glm_bvec2_add(bvec2 a, bvec2 b, bvec2 dest)
  CGLM_INLINE void glm_bvec2_adds(bvec2 v, int8_t s, bvec2 dest)
  CGLM_INLINE void glm_bvec2_sub(bvec2 a, bvec2 b, bvec2 dest)
  CGLM_INLINE void glm_bvec2_subs(bvec2 v, int8_t s, bvec2 dest)
  CGLM_INLINE void glm_bvec2_mul(bvec2 a, bvec2 b, bvec2 dest)
  CGLM_INLINE void glm_bvec2_scale(bvec2 v, int8_t s, bvec2 dest)
  CGLM_INLINE int8_t glm_bvec2_distance2(bvec2 a, bvec2 b)
  CGLM_INLINE float glm_bvec2_distance(bvec2 a, bvec2 b)
  CGLM_INLINE void glm_bvec2_fill(bvec2 v, int8_t val);
  CGLM_INLINE bool glm_bvec2_eq(bvec2 v, int8_t val);
  CGLM_INLINE bool glm_bvec2_eqv(bvec2 a, bvec2 b);
  CGLM_INLINE void glm_bvec2_maxv(bvec2 a, bvec2 b, bvec2 dest)
  CGLM_INLINE void glm_bvec2_minv(bvec2 a, bvec2 b, bvec2 dest)
  CGLM_INLINE void glm_bvec2_clamp(bvec2 v, int8_t minVal, int8_t maxVal)
  CGLM_INLINE void glm_bvec2_abs(bvec2 v, bvec2 dest)
 */

#ifndef cglm_bvec2_h
#define cglm_bvec2_h

#include "common.h"

#define GLM_BVEC2_ONE_INIT   {1, 1}
#define GLM_BVEC2_ZERO_INIT  {0, 0}

#define GLM_BVEC2_ONE  ((bvec2)GLM_BVEC2_ONE_INIT)
#define GLM_BVEC2_ZERO ((bvec2)GLM_BVEC2_ZERO_INIT)

/*!
 * @brief init bvec2 using vec3 or vec4
 *
 * @param[in]  v    vector
 * @param[out] dest destination
 */
CGLM_INLINE
void
glm_bvec2(int8_t * __restrict v, bvec2 dest) {
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
glm_bvec2_copy(bvec2 a, bvec2 dest) {
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
glm_bvec2_zero(bvec2 v) {
  v[0] = v[1] = 0;
}

/*!
 * @brief set all members of [v] to one
 *
 * @param[out] v vector
 */
CGLM_INLINE
void
glm_bvec2_one(bvec2 v) {
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
glm_bvec2_add(bvec2 a, bvec2 b, bvec2 dest) {
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
glm_bvec2_adds(bvec2 v, int8_t s, bvec2 dest) {
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
glm_bvec2_sub(bvec2 a, bvec2 b, bvec2 dest) {
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
glm_bvec2_subs(bvec2 v, int8_t s, bvec2 dest) {
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
glm_bvec2_mul(bvec2 a, bvec2 b, bvec2 dest) {
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
glm_bvec2_scale(bvec2 v, int8_t s, bvec2 dest) {
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
glm_bvec2_distance2(bvec2 a, bvec2 b) {
  int8_t xd, yd;
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
glm_bvec2_distance(bvec2 a, bvec2 b) {
  return sqrtf((float)glm_bvec2_distance2(a, b));
}


/*!
 * @brief fill a vector with specified value
 *
 * @param[out] v   dest
 * @param[in]  val value
 */
CGLM_INLINE
void
glm_bvec2_fill(bvec2 v, int8_t val) {
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
glm_bvec2_eq(bvec2 v, int8_t val) {
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
glm_bvec2_eqv(bvec2 a, bvec2 b) {
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
glm_bvec2_maxv(bvec2 a, bvec2 b, bvec2 dest) {
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
glm_bvec2_minv(bvec2 a, bvec2 b, bvec2 dest) {
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
glm_bvec2_clamp(bvec2 v, int8_t minVal, int8_t maxVal) {
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
glm_bvec2_abs(bvec2 v, bvec2 dest) {
  dest[0] = abs(v[0]);
  dest[1] = abs(v[1]);
}

#endif /* cglm_bvec2_h */
