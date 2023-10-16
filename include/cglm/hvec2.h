/*
 * Copyright (c), Recep Aslantas.
 *
 * MIT License (MIT), http://opensource.org/licenses/MIT
 * Full license can be found in the LICENSE file
 */

/*
 Macros:
   GLM_HVEC2_ONE_INIT
   GLM_HVEC2_ZERO_INIT
   GLM_HVEC2_ONE
   GLM_HVEC2_ZERO

 Functions:
  CGLM_INLINE void glm_hvec2(int16_t * __restrict v, hvec2 dest)
  CGLM_INLINE void glm_hvec2_copy(hvec2 a, hvec2 dest)
  CGLM_INLINE void glm_hvec2_zero(hvec2 v)
  CGLM_INLINE void glm_hvec2_one(hvec2 v)
  CGLM_INLINE void glm_hvec2_add(hvec2 a, hvec2 b, hvec2 dest)
  CGLM_INLINE void glm_hvec2_adds(hvec2 v, int16_t s, hvec2 dest)
  CGLM_INLINE void glm_hvec2_sub(hvec2 a, hvec2 b, hvec2 dest)
  CGLM_INLINE void glm_hvec2_subs(hvec2 v, int16_t s, hvec2 dest)
  CGLM_INLINE void glm_hvec2_mul(hvec2 a, hvec2 b, hvec2 dest)
  CGLM_INLINE void glm_hvec2_scale(hvec2 v, int16_t s, hvec2 dest)
  CGLM_INLINE int16_t glm_hvec2_distance2(hvec2 a, hvec2 b)
  CGLM_INLINE float glm_hvec2_distance(hvec2 a, hvec2 b)
  CGLM_INLINE void glm_hvec2_fill(hvec2 v, int16_t val);
  CGLM_INLINE bool glm_hvec2_eq(hvec2 v, int16_t val);
  CGLM_INLINE bool glm_hvec2_eqv(hvec2 a, hvec2 b);
  CGLM_INLINE void glm_hvec2_maxv(hvec2 a, hvec2 b, hvec2 dest)
  CGLM_INLINE void glm_hvec2_minv(hvec2 a, hvec2 b, hvec2 dest)
  CGLM_INLINE void glm_hvec2_clamp(hvec2 v, int16_t minVal, int16_t maxVal)
  CGLM_INLINE void glm_hvec2_abs(hvec2 v, hvec2 dest)
 */

#ifndef cglm_hvec2_h
#define cglm_hvec2_h

#include "common.h"

#define GLM_HVEC2_ONE_INIT   {1, 1}
#define GLM_HVEC2_ZERO_INIT  {0, 0}

#define GLM_HVEC2_ONE  ((hvec2)GLM_HVEC2_ONE_INIT)
#define GLM_HVEC2_ZERO ((hvec2)GLM_HVEC2_ZERO_INIT)

/*!
 * @brief init hvec2 using vec3 or vec4
 *
 * @param[in]  v    vector
 * @param[out] dest destination
 */
CGLM_INLINE
void
glm_hvec2(int16_t * __restrict v, hvec2 dest) {
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
glm_hvec2_copy(hvec2 a, hvec2 dest) {
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
glm_hvec2_zero(hvec2 v) {
  v[0] = v[1] = 0;
}

/*!
 * @brief set all members of [v] to one
 *
 * @param[out] v vector
 */
CGLM_INLINE
void
glm_hvec2_one(hvec2 v) {
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
glm_hvec2_add(hvec2 a, hvec2 b, hvec2 dest) {
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
glm_hvec2_adds(hvec2 v, int16_t s, hvec2 dest) {
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
glm_hvec2_sub(hvec2 a, hvec2 b, hvec2 dest) {
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
glm_hvec2_subs(hvec2 v, int16_t s, hvec2 dest) {
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
glm_hvec2_mul(hvec2 a, hvec2 b, hvec2 dest) {
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
glm_hvec2_scale(hvec2 v, int16_t s, hvec2 dest) {
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
glm_hvec2_distance2(hvec2 a, hvec2 b) {
  int16_t xd, yd;
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
glm_hvec2_distance(hvec2 a, hvec2 b) {
  return sqrtf((float)glm_hvec2_distance2(a, b));
}


/*!
 * @brief fill a vector with specified value
 *
 * @param[out] v   dest
 * @param[in]  val value
 */
CGLM_INLINE
void
glm_hvec2_fill(hvec2 v, int16_t val) {
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
glm_hvec2_eq(hvec2 v, int16_t val) {
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
glm_hvec2_eqv(hvec2 a, hvec2 b) {
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
glm_hvec2_maxv(hvec2 a, hvec2 b, hvec2 dest) {
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
glm_hvec2_minv(hvec2 a, hvec2 b, hvec2 dest) {
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
glm_hvec2_clamp(hvec2 v, int16_t minVal, int16_t maxVal) {
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
glm_hvec2_abs(hvec2 v, hvec2 dest) {
  dest[0] = abs(v[0]);
  dest[1] = abs(v[1]);
}

#endif /* cglm_hvec2_h */
