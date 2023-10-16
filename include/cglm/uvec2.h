/*
 * Copyright (c), Recep Aslantas.
 *
 * MIT License (MIT), http://opensource.org/licenses/MIT
 * Full license can be found in the LICENSE file
 */

/*
 Macros:
   GLM_UVEC2_ONE_INIT
   GLM_UVEC2_ZERO_INIT
   GLM_UVEC2_ONE
   GLM_UVEC2_ZERO

 Functions:
  CGLM_INLINE void glm_uvec2(uint32_t * __restrict v, uvec2 dest)
  CGLM_INLINE void glm_uvec2_copy(uvec2 a, uvec2 dest)
  CGLM_INLINE void glm_uvec2_zero(uvec2 v)
  CGLM_INLINE void glm_uvec2_one(uvec2 v)
  CGLM_INLINE void glm_uvec2_add(uvec2 a, uvec2 b, uvec2 dest)
  CGLM_INLINE void glm_uvec2_adds(uvec2 v, uint32_t s, uvec2 dest)
  CGLM_INLINE void glm_uvec2_sub(uvec2 a, uvec2 b, uvec2 dest)
  CGLM_INLINE void glm_uvec2_subs(uvec2 v, uint32_t s, uvec2 dest)
  CGLM_INLINE void glm_uvec2_mul(uvec2 a, uvec2 b, uvec2 dest)
  CGLM_INLINE void glm_uvec2_scale(uvec2 v, uint32_t s, uvec2 dest)
  CGLM_INLINE uint32_t glm_uvec2_distance2(uvec2 a, uvec2 b)
  CGLM_INLINE float glm_uvec2_distance(uvec2 a, uvec2 b)
  CGLM_INLINE void glm_uvec2_fill(uvec2 v, uint32_t val);
  CGLM_INLINE bool glm_uvec2_eq(uvec2 v, uint32_t val);
  CGLM_INLINE bool glm_uvec2_eqv(uvec2 a, uvec2 b);
  CGLM_INLINE void glm_uvec2_maxv(uvec2 a, uvec2 b, uvec2 dest)
  CGLM_INLINE void glm_uvec2_minv(uvec2 a, uvec2 b, uvec2 dest)
  CGLM_INLINE void glm_uvec2_clamp(uvec2 v, uint32_t minVal, uint32_t maxVal)
  CGLM_INLINE void glm_uvec2_abs(uvec2 v, uvec2 dest)
 */

#ifndef cglm_uvec2_h
#define cglm_uvec2_h

#include "common.h"

#define GLM_UVEC2_ONE_INIT   {1, 1}
#define GLM_UVEC2_ZERO_INIT  {0, 0}

#define GLM_UVEC2_ONE  ((uvec2)GLM_UVEC2_ONE_INIT)
#define GLM_UVEC2_ZERO ((uvec2)GLM_UVEC2_ZERO_INIT)

/*!
 * @brief init uvec2 using vec3 or vec4
 *
 * @param[in]  v    vector
 * @param[out] dest destination
 */
CGLM_INLINE
void
glm_uvec2(uint32_t * __restrict v, uvec2 dest) {
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
glm_uvec2_copy(uvec2 a, uvec2 dest) {
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
glm_uvec2_zero(uvec2 v) {
  v[0] = v[1] = 0;
}

/*!
 * @brief set all members of [v] to one
 *
 * @param[out] v vector
 */
CGLM_INLINE
void
glm_uvec2_one(uvec2 v) {
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
glm_uvec2_add(uvec2 a, uvec2 b, uvec2 dest) {
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
glm_uvec2_adds(uvec2 v, uint32_t s, uvec2 dest) {
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
glm_uvec2_sub(uvec2 a, uvec2 b, uvec2 dest) {
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
glm_uvec2_subs(uvec2 v, uint32_t s, uvec2 dest) {
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
glm_uvec2_mul(uvec2 a, uvec2 b, uvec2 dest) {
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
glm_uvec2_scale(uvec2 v, uint32_t s, uvec2 dest) {
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
glm_uvec2_distance2(uvec2 a, uvec2 b) {
  uint32_t xd, yd;
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
glm_uvec2_distance(uvec2 a, uvec2 b) {
  return sqrtf((float)glm_uvec2_distance2(a, b));
}


/*!
 * @brief fill a vector with specified value
 *
 * @param[out] v   dest
 * @param[in]  val value
 */
CGLM_INLINE
void
glm_uvec2_fill(uvec2 v, uint32_t val) {
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
glm_uvec2_eq(uvec2 v, uint32_t val) {
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
glm_uvec2_eqv(uvec2 a, uvec2 b) {
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
glm_uvec2_maxv(uvec2 a, uvec2 b, uvec2 dest) {
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
glm_uvec2_minv(uvec2 a, uvec2 b, uvec2 dest) {
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
glm_uvec2_clamp(uvec2 v, uint32_t minVal, uint32_t maxVal) {
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
glm_uvec2_abs(uvec2 v, uvec2 dest) {
  dest[0] = abs(v[0]);
  dest[1] = abs(v[1]);
}

#endif /* cglm_uvec2_h */
