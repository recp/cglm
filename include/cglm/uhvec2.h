/*
 * Copyright (c), Recep Aslantas.
 *
 * MIT License (MIT), http://opensource.org/licenses/MIT
 * Full license can be found in the LICENSE file
 */

/*
 Macros:
   GLM_UHVEC2_ONE_INIT
   GLM_UHVEC2_ZERO_INIT
   GLM_UHVEC2_ONE
   GLM_UHVEC2_ZERO

 Functions:
  CGLM_INLINE void glm_uhvec2(uint16_t * __restrict v, uhvec2 dest)
  CGLM_INLINE void glm_uhvec2_copy(uhvec2 a, uhvec2 dest)
  CGLM_INLINE void glm_uhvec2_zero(uhvec2 v)
  CGLM_INLINE void glm_uhvec2_one(uhvec2 v)
  CGLM_INLINE void glm_uhvec2_add(uhvec2 a, uhvec2 b, uhvec2 dest)
  CGLM_INLINE void glm_uhvec2_adds(uhvec2 v, uint16_t s, uhvec2 dest)
  CGLM_INLINE void glm_uhvec2_sub(uhvec2 a, uhvec2 b, uhvec2 dest)
  CGLM_INLINE void glm_uhvec2_subs(uhvec2 v, uint16_t s, uhvec2 dest)
  CGLM_INLINE void glm_uhvec2_mul(uhvec2 a, uhvec2 b, uhvec2 dest)
  CGLM_INLINE void glm_uhvec2_scale(uhvec2 v, uint16_t s, uhvec2 dest)
  CGLM_INLINE uint16_t glm_uhvec2_distance2(uhvec2 a, uhvec2 b)
  CGLM_INLINE float glm_uhvec2_distance(uhvec2 a, uhvec2 b)
  CGLM_INLINE void glm_uhvec2_fill(uhvec2 v, uint16_t val);
  CGLM_INLINE bool glm_uhvec2_eq(uhvec2 v, uint16_t val);
  CGLM_INLINE bool glm_uhvec2_eqv(uhvec2 a, uhvec2 b);
  CGLM_INLINE void glm_uhvec2_maxv(uhvec2 a, uhvec2 b, uhvec2 dest)
  CGLM_INLINE void glm_uhvec2_minv(uhvec2 a, uhvec2 b, uhvec2 dest)
  CGLM_INLINE void glm_uhvec2_clamp(uhvec2 v, uint16_t minVal, uint16_t maxVal)
  CGLM_INLINE void glm_uhvec2_abs(uhvec2 v, uhvec2 dest)
 */

#ifndef cglm_uhvec2_h
#define cglm_uhvec2_h

#include "common.h"

#define GLM_UHVEC2_ONE_INIT   {1, 1}
#define GLM_UHVEC2_ZERO_INIT  {0, 0}

#define GLM_UHVEC2_ONE  ((uhvec2)GLM_UHVEC2_ONE_INIT)
#define GLM_UHVEC2_ZERO ((uhvec2)GLM_UHVEC2_ZERO_INIT)

/*!
 * @brief init uhvec2 using vec3 or vec4
 *
 * @param[in]  v    vector
 * @param[out] dest destination
 */
CGLM_INLINE
void
glm_uhvec2(uint16_t * __restrict v, uhvec2 dest) {
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
glm_uhvec2_copy(uhvec2 a, uhvec2 dest) {
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
glm_uhvec2_zero(uhvec2 v) {
  v[0] = v[1] = 0;
}

/*!
 * @brief set all members of [v] to one
 *
 * @param[out] v vector
 */
CGLM_INLINE
void
glm_uhvec2_one(uhvec2 v) {
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
glm_uhvec2_add(uhvec2 a, uhvec2 b, uhvec2 dest) {
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
glm_uhvec2_adds(uhvec2 v, uint16_t s, uhvec2 dest) {
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
glm_uhvec2_sub(uhvec2 a, uhvec2 b, uhvec2 dest) {
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
glm_uhvec2_subs(uhvec2 v, uint16_t s, uhvec2 dest) {
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
glm_uhvec2_mul(uhvec2 a, uhvec2 b, uhvec2 dest) {
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
glm_uhvec2_scale(uhvec2 v, uint16_t s, uhvec2 dest) {
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
glm_uhvec2_distance2(uhvec2 a, uhvec2 b) {
  uint16_t xd, yd;
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
glm_uhvec2_distance(uhvec2 a, uhvec2 b) {
  return sqrtf((float)glm_uhvec2_distance2(a, b));
}


/*!
 * @brief fill a vector with specified value
 *
 * @param[out] v   dest
 * @param[in]  val value
 */
CGLM_INLINE
void
glm_uhvec2_fill(uhvec2 v, uint16_t val) {
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
glm_uhvec2_eq(uhvec2 v, uint16_t val) {
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
glm_uhvec2_eqv(uhvec2 a, uhvec2 b) {
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
glm_uhvec2_maxv(uhvec2 a, uhvec2 b, uhvec2 dest) {
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
glm_uhvec2_minv(uhvec2 a, uhvec2 b, uhvec2 dest) {
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
glm_uhvec2_clamp(uhvec2 v, uint16_t minVal, uint16_t maxVal) {
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
glm_uhvec2_abs(uhvec2 v, uhvec2 dest) {
  dest[0] = abs(v[0]);
  dest[1] = abs(v[1]);
}

#endif /* cglm_uhvec2_h */
