/*
 * Copyright (c), Recep Aslantas.
 *
 * MIT License (MIT), http://opensource.org/licenses/MIT
 * Full license can be found in the LICENSE file
 */

#ifndef cglm_bezier_h
#define cglm_bezier_h

#include "common.h"

/*!
 * @brief cubic bezier interpolation
 *
 * @param[in]  t    time between 0 and 1
 * @param[in]  p0   begin point
 * @param[in]  c0   control point 1
 * @param[in]  c1   control point 2
 * @param[in]  p1   end point
 *
 * @return B(s)
 */
CGLM_INLINE
float
glm_bezier_cubic(float t, float p0, float c0, float c1, float p1) {
  float s, ss, tt;

  s  = 1.0f - t;
  ss = s * s;
  tt = t * t;

  return p0 * ss * s + 3.0f * c0 * t * ss + 3.0f * c1 * tt * s + p1 * tt * t;
}

/*!
 * @brief cubic bezier interpolation for vec3
 *
 * @param[in]  t    time between 0 and 1
 * @param[in]  p0   begin point
 * @param[in]  c0   control point 1
 * @param[in]  c1   control point 2
 * @param[in]  p1   end point
 * @param[in]  dest destination
 */
CGLM_INLINE
void
glm_bezier_cubicv3(float t, vec3 p0, vec3 c0, vec3 c1, vec3 p1, vec3 dest) {
  vec3  Bs, tmp0, tmp1, tmp2;
  float s, ss, tt;

  s  = 1.0f - t;
  ss = s * s;
  tt = t * t;

  glm_vec_scale(p0, ss * s, Bs);
  glm_vec_scale(c0, 3.0f * t * ss, tmp0);
  glm_vec_scale(c1, 3.0f * tt * s, tmp1);
  glm_vec_scale(p1, tt * t, tmp2);

  glm_vec_add(Bs, tmp0, Bs);
  glm_vec_add(Bs, tmp1, Bs);
  glm_vec_add(Bs, tmp2, Bs);

  glm_vec_copy(Bs, dest);
}

/*!
 * @brief cubic hermite interpolation
 *
 * @param[in]  t    time between 0 and 1
 * @param[in]  p0   begin point
 * @param[in]  t0   tangent 1
 * @param[in]  t1   tangent 2
 * @param[in]  p1   end point
 *
 * @return B(s)
 */
CGLM_INLINE
float
glm_hermite_cubic(float t, float p0, float t0, float t1, float p1) {
  float tt, ttt;

  tt  = t * t;
  ttt = tt * t;

  return p0 * (2.0f * ttt - 3.0f * tt + 1)
          + t0 * (ttt - 2.0f * tt + t)
          + p1 * (3.0f * tt - 2.0f * ttt)
          - t1 * (ttt - tt);
}

/*!
 * @brief cubic hermite interpolation for vec3
 *
 * @param[in]  t    time between 0 and 1
 * @param[in]  p0   begin point
 * @param[in]  t0   tangent 1
 * @param[in]  t1   tangent 2
 * @param[in]  p1   end point
 * @param[in]  dest destination
 */
CGLM_INLINE
void
glm_hermite_cubicv3(float t, vec3 p0, vec3 t0, vec3 t1, vec3 p1, vec3 dest) {
  vec3  Hs, tmp0, tmp1, tmp2;
  float tt, ttt;

  tt  = t * t;
  ttt = tt * t;

  glm_vec_scale(p0, 2.0f * ttt - 3.0f * tt + 1, Hs);
  glm_vec_scale(t0, ttt - 2.0f * tt + t, tmp0);
  glm_vec_scale(p1, 3.0f * tt - 2.0f * ttt, tmp1);
  glm_vec_scale(t1, ttt - tt, tmp2);

  glm_vec_add(Hs, tmp0, Hs);
  glm_vec_add(Hs, tmp1, Hs);
  glm_vec_add(Hs, tmp2, Hs);

  glm_vec_copy(Hs, dest);
}

#endif /* cglm_bezier_h */
