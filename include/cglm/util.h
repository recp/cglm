/*
 * Copyright (c), Recep Aslantas.
 *
 * MIT License (MIT), http://opensource.org/licenses/MIT
 * Full license can be found in the LICENSE file
 */

/*
 Functions:
   CGLM_INLINE int   glm_sign(int val);
   CGLM_INLINE float glm_rad(float deg);
   CGLM_INLINE float glm_deg(float rad);
   CGLM_INLINE void  glm_make_rad(float *deg);
   CGLM_INLINE void  glm_make_deg(float *rad);
   CGLM_INLINE float glm_pow2(float x);
 */

#ifndef cglm_util_h
#define cglm_util_h

#include "common.h"

#define GLM_MIN(X, Y) (((X) < (Y)) ? (X) : (Y))
#define GLM_MAX(X, Y) (((X) > (Y)) ? (X) : (Y))

/*!
 * @brief get sign of 32 bit integer as +1, -1, 0
 *
 * Important: It returns 0 for zero input
 *
 * @param val integer value
 */
CGLM_INLINE
int
glm_sign(int val) {
  return ((val >> 31) - (-val >> 31));
}

/*!
 * @brief get sign of 32 bit float as +1, -1, 0
 *
 * Important: It returns 0 for zero/NaN input
 *
 * @param val float value
 */
CGLM_INLINE
float
glm_signf(float val) {
  return (float)((val > 0.0f) - (val < 0.0f));
}

/*!
 * @brief convert degree to radians
 *
 * @param[in] deg angle in degrees
 */
CGLM_INLINE
float
glm_rad(float deg) {
  return deg * GLM_PIf / 180.0f;
}

/*!
 * @brief convert radians to degree
 *
 * @param[in] rad angle in radians
 */
CGLM_INLINE
float
glm_deg(float rad) {
  return rad * 180.0f / GLM_PIf;
}

/*!
 * @brief convert exsisting degree to radians. this will override degrees value
 *
 * @param[in, out] deg pointer to angle in degrees
 */
CGLM_INLINE
void
glm_make_rad(float *deg) {
  *deg = *deg * GLM_PIf / 180.0f;
}

/*!
 * @brief convert exsisting radians to degree. this will override radians value
 *
 * @param[in, out] rad pointer to angle in radians
 */
CGLM_INLINE
void
glm_make_deg(float *rad) {
  *rad = *rad * 180.0f / GLM_PIf;
}

/*!
 * @brief multiplies given parameter with itself = x * x or powf(x, 2)
 *
 * @param[in] x x
 */
CGLM_INLINE
float
glm_pow2(float x) {
  return x * x;
}

/*!
 * @brief find minimum of given two values
 *
 * @param[in] a number 1
 * @param[in] b number 2
 */
CGLM_INLINE
float
glm_min(float a, float b) {
  if (a < b)
    return a;
  return b;
}

/*!
 * @brief find maximum of given two values
 *
 * @param[in] a number 1
 * @param[in] b number 2
 */
CGLM_INLINE
float
glm_max(float a, float b) {
  if (a > b)
    return a;
  return b;
}

/*!
 * @brief clamp a number between min and max
 *
 * @param[in] val    value to clamp
 * @param[in] minVal minimum value
 * @param[in] maxVal maximum value
 */
CGLM_INLINE
float
glm_clamp(float val, float minVal, float maxVal) {
  return glm_min(glm_max(val, minVal), maxVal);
}

/*!
 * @brief clamp a number to zero and one
 *
 * @param[in] val value to clamp
 */
CGLM_INLINE
float
glm_clamp_zo(float val) {
  return glm_clamp(val, 0.0f, 1.0f);
}

/*!
 * @brief linear interpolation between two number
 *
 * formula:  from + s * (to - from)
 *
 * @param[in]   from from value
 * @param[in]   to   to value
 * @param[in]   t    interpolant (amount) clamped between 0 and 1
 */
CGLM_INLINE
float
glm_lerp(float from, float to, float t) {
  return from + glm_clamp_zo(t) * (to - from);
}

/*!
 * @brief check if two float equal with using EPSILON
 *
 * @param[in]   a   a
 * @param[in]   b   b
 */
CGLM_INLINE
bool
glm_eq(float a, float b) {
  return fabsf(a - b) <= FLT_EPSILON;
}

/*!
 * @brief percentage of current value between start and end value
 *
 * maybe fraction could be alternative name.
 *
 * @param[in]   from    from value
 * @param[in]   to      to value
 * @param[in]   current current value
 */
CGLM_INLINE
float
glm_percent(float from, float to, float current) {
  float t;

  if ((t = to - from) == 0.0f)
    return 1.0f;

  return (current - from) / t;
}

/*!
 * @brief clamped percentage of current value between start and end value
 *
 * @param[in]   from    from value
 * @param[in]   to      to value
 * @param[in]   current current value
 */
CGLM_INLINE
float
glm_percentc(float from, float to, float current) {
  return glm_clamp(glm_percent(from, to, current), 0.0f, 1.0f);
}

#endif /* cglm_util_h */
