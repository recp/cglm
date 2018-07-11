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

#endif /* cglm_bezier_h */
