/*
 * Copyright (c), Recep Aslantas.
 *
 * MIT License (MIT), http://opensource.org/licenses/MIT
 * Full license can be found in the LICENSE file
 */

/*
 Functions:
   CGLM_DECL int   glm_sign(int val);
   CGLM_DECL float glm_signf(float val);
   CGLM_DECL float glm_rad(float deg);
   CGLM_DECL float glm_deg(float rad);
   CGLM_DECL void  glm_make_rad(float *deg);
   CGLM_DECL void  glm_make_deg(float *rad);
   CGLM_DECL float glm_pow2(float x);
   CGLM_DECL float glm_min(float a, float b);
   CGLM_DECL float glm_max(float a, float b);
   CGLM_DECL float glm_clamp(float val, float minVal, float maxVal);
   CGLM_DECL float glm_clamp_zo(float val, float minVal, float maxVal);
   CGLM_DECL float glm_lerp(float from, float to, float t);
   CGLM_DECL float glm_lerpc(float from, float to, float t);
   CGLM_DECL float glm_step(float edge, float x);
   CGLM_DECL float glm_smooth(float t);
   CGLM_DECL float glm_smoothstep(float edge0, float edge1, float x);
   CGLM_DECL float glm_smoothinterp(float from, float to, float t);
   CGLM_DECL float glm_smoothinterpc(float from, float to, float t);
   CGLM_DECL bool  glm_eq(float a, float b);
   CGLM_DECL float glm_percent(float from, float to, float current);
   CGLM_DECL float glm_percentc(float from, float to, float current);
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
CGLM_DECL
int
glm_sign(int val) CGLM_ENDD
#ifndef CGLM_LIB
{
  return ((val >> 31) - (-val >> 31));
}
#endif

/*!
 * @brief get sign of 32 bit float as +1, -1, 0
 *
 * Important: It returns 0 for zero/NaN input
 *
 * @param val float value
 */
CGLM_DECL
float
glm_signf(float val) CGLM_ENDD
#ifndef CGLM_LIB
{
  return (float)((val > 0.0f) - (val < 0.0f));
}
#endif

/*!
 * @brief convert degree to radians
 *
 * @param[in] deg angle in degrees
 */
CGLM_DECL
float
glm_rad(float deg) CGLM_ENDD
#ifndef CGLM_LIB
{
  return deg * GLM_PIf / 180.0f;
}
#endif

/*!
 * @brief convert radians to degree
 *
 * @param[in] rad angle in radians
 */
CGLM_DECL
float
glm_deg(float rad) CGLM_ENDD
#ifndef CGLM_LIB
{
  return rad * 180.0f / GLM_PIf;
}
#endif

/*!
 * @brief convert exsisting degree to radians. this will override degrees value
 *
 * @param[in, out] deg pointer to angle in degrees
 */
CGLM_DECL
void
glm_make_rad(float *deg) CGLM_ENDD
#ifndef CGLM_LIB
{
  *deg = *deg * GLM_PIf / 180.0f;
}
#endif

/*!
 * @brief convert exsisting radians to degree. this will override radians value
 *
 * @param[in, out] rad pointer to angle in radians
 */
CGLM_DECL
void
glm_make_deg(float *rad) CGLM_ENDD
#ifndef CGLM_LIB
{
  *rad = *rad * 180.0f / GLM_PIf;
}
#endif

/*!
 * @brief multiplies given parameter with itself = x * x or powf(x, 2)
 *
 * @param[in] x x
 */
CGLM_DECL
float
glm_pow2(float x) CGLM_ENDD
#ifndef CGLM_LIB
{
  return x * x;
}
#endif

/*!
 * @brief find minimum of given two values
 *
 * @param[in] a number 1
 * @param[in] b number 2
 */
CGLM_DECL
float
glm_min(float a, float b) CGLM_ENDD
#ifndef CGLM_LIB
{
  if (a < b)
    return a;
  return b;
}
#endif

/*!
 * @brief find maximum of given two values
 *
 * @param[in] a number 1
 * @param[in] b number 2
 */
CGLM_DECL
float
glm_max(float a, float b) CGLM_ENDD
#ifndef CGLM_LIB
{
  if (a > b)
    return a;
  return b;
}
#endif

/*!
 * @brief clamp a number between min and max
 *
 * @param[in] val    value to clamp
 * @param[in] minVal minimum value
 * @param[in] maxVal maximum value
 */
CGLM_DECL
float
glm_clamp(float val, float minVal, float maxVal) CGLM_ENDD
#ifndef CGLM_LIB
{
  return glm_min(glm_max(val, minVal), maxVal);
}
#endif

/*!
 * @brief clamp a number to zero and one
 *
 * @param[in] val value to clamp
 */
CGLM_DECL
float
glm_clamp_zo(float val) CGLM_ENDD
#ifndef CGLM_LIB
{
  return glm_clamp(val, 0.0f, 1.0f);
}
#endif

/*!
 * @brief linear interpolation between two numbers
 *
 * formula:  from + t * (to - from)
 *
 * @param[in]   from from value
 * @param[in]   to   to value
 * @param[in]   t    interpolant (amount)
 */
CGLM_DECL
float
glm_lerp(float from, float to, float t) CGLM_ENDD
#ifndef CGLM_LIB
{
  return from + t * (to - from);
}
#endif

/*!
 * @brief clamped linear interpolation between two numbers
 *
 * formula:  from + t * (to - from)
 *
 * @param[in]   from    from value
 * @param[in]   to      to value
 * @param[in]   t       interpolant (amount) clamped between 0 and 1
 */
CGLM_DECL
float
glm_lerpc(float from, float to, float t) CGLM_ENDD
#ifndef CGLM_LIB
{
  return glm_lerp(from, to, glm_clamp_zo(t));
}
#endif

/*!
 * @brief threshold function
 *
 * @param[in]   edge    threshold
 * @param[in]   x       value to test against threshold
 * @return      returns 0.0 if x < edge, else 1.0
 */
CGLM_DECL
float
glm_step(float edge, float x) CGLM_ENDD
#ifndef CGLM_LIB
{
  /* branching - no type conversion */
  return (x < edge) ? 0.0f : 1.0f;
  /*
   * An alternative implementation without branching
   * but with type conversion could be:
   * return !(x < edge);
   */
}
#endif

/*!
 * @brief smooth Hermite interpolation
 *
 * formula:  t^2 * (3-2t)
 *
 * @param[in]   t    interpolant (amount)
 */
CGLM_DECL
float
glm_smooth(float t) CGLM_ENDD
#ifndef CGLM_LIB
{
  return t * t * (3.0f - 2.0f * t);
}
#endif

/*!
 * @brief threshold function with a smooth transition (according to OpenCL specs)
 *
 * formula:  t^2 * (3-2t)
 *
 * @param[in]   edge0 low threshold
 * @param[in]   edge1 high threshold
 * @param[in]   x     interpolant (amount)
 */
CGLM_DECL
float
glm_smoothstep(float edge0, float edge1, float x) CGLM_ENDD
#ifndef CGLM_LIB
{
  float t;
  t = glm_clamp_zo((x - edge0) / (edge1 - edge0));
  return glm_smooth(t);
}
#endif

/*!
 * @brief smoothstep interpolation between two numbers
 *
 * formula:  from + smoothstep(t) * (to - from)
 *
 * @param[in]   from from value
 * @param[in]   to   to value
 * @param[in]   t    interpolant (amount)
 */
CGLM_DECL
float
glm_smoothinterp(float from, float to, float t) CGLM_ENDD
#ifndef CGLM_LIB
{
  return from + glm_smooth(t) * (to - from);
}
#endif

/*!
 * @brief clamped smoothstep interpolation between two numbers
 *
 * formula:  from + smoothstep(t) * (to - from)
 *
 * @param[in]   from from value
 * @param[in]   to   to value
 * @param[in]   t    interpolant (amount) clamped between 0 and 1
 */
CGLM_DECL
float
glm_smoothinterpc(float from, float to, float t) CGLM_ENDD
#ifndef CGLM_LIB
{
  return glm_smoothinterp(from, to, glm_clamp_zo(t));
}
#endif

/*!
 * @brief check if two float equal with using EPSILON
 *
 * @param[in]   a   a
 * @param[in]   b   b
 */
CGLM_DECL
bool
glm_eq(float a, float b) CGLM_ENDD
#ifndef CGLM_LIB
{
  return fabsf(a - b) <= FLT_EPSILON;
}
#endif

/*!
 * @brief percentage of current value between start and end value
 *
 * maybe fraction could be alternative name.
 *
 * @param[in]   from    from value
 * @param[in]   to      to value
 * @param[in]   current current value
 */
CGLM_DECL
float
glm_percent(float from, float to, float current) CGLM_ENDD
#ifndef CGLM_LIB
{
  float t;

  if ((t = to - from) == 0.0f)
    return 1.0f;

  return (current - from) / t;
}
#endif

/*!
 * @brief clamped percentage of current value between start and end value
 *
 * @param[in]   from    from value
 * @param[in]   to      to value
 * @param[in]   current current value
 */
CGLM_DECL
float
glm_percentc(float from, float to, float current) CGLM_ENDD
#ifndef CGLM_LIB
{
  return glm_clamp_zo(glm_percent(from, to, current));
}
#endif

/*!
* @brief swap two float values
*
* @param[in]   a float value 1 (pointer)
* @param[in]   b float value 2 (pointer)
*/
CGLM_DECL
void
glm_swapf(float * __restrict a, float * __restrict b) CGLM_ENDD
#ifndef CGLM_LIB
{
  float t;
  t  = *a;
  *a = *b;
  *b = t;
}
#endif

#endif /* cglm_util_h */
