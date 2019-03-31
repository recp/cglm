/*
 * Copyright (c), Recep Aslantas.
 *
 * MIT License (MIT), http://opensource.org/licenses/MIT
 * Full license can be found in the LICENSE file
 */

#ifndef cglm_bezier_h
#define cglm_bezier_h

#include "common.h"

#define GLM_BEZIER_MAT_INIT  {{-1.0f,  3.0f, -3.0f,  1.0f},                   \
                              { 3.0f, -6.0f,  3.0f,  0.0f},                   \
                              {-3.0f,  3.0f,  0.0f,  0.0f},                   \
                              { 1.0f,  0.0f,  0.0f,  0.0f}}
#define GLM_HERMITE_MAT_INIT {{ 2.0f, -3.0f,  0.0f,  1.0f},                   \
                              {-2.0f,  3.0f,  0.0f,  0.0f},                   \
                              { 1.0f, -2.0f,  1.0f,  0.0f},                   \
                              { 1.0f, -1.0f,  0.0f,  0.0f}}
/* for C only */
#define GLM_BEZIER_MAT  ((mat4)GLM_BEZIER_MAT_INIT)
#define GLM_HERMITE_MAT ((mat4)GLM_HERMITE_MAT_INIT)

#define CGLM_DECASTEL_EPS   1e-9
#define CGLM_DECASTEL_MAX   1000
#define CGLM_DECASTEL_SMALL 1e-20

/*!
 * @brief cubic bezier interpolation
 *
 * Formula:
 *  B(s) = P0*(1-s)^3 + 3*C0*s*(1-s)^2 + 3*C1*s^2*(1-s) + P1*s^3
 *
 * similar result using matrix:
 *  B(s) = glm_smc(t, GLM_BEZIER_MAT, (vec4){p0, c0, c1, p1})
 *
 * glm_eq(glm_smc(...), glm_bezier(...)) should return TRUE
 *
 * @param[in]  s    parameter between 0 and 1
 * @param[in]  p0   begin point
 * @param[in]  c0   control point 1
 * @param[in]  c1   control point 2
 * @param[in]  p1   end point
 *
 * @return B(s)
 */
CGLM_INLINE
float
glm_bezier(float s, float p0, float c0, float c1, float p1) {
  float x, xx, ss, xs3, a;

  x   = 1.0f - s;
  xx  = x * x;
  ss  = s * s;
  xs3 = (s - ss) * 3.0f;
  a   = p0 * xx + c0 * xs3;

  return a + s * (c1 * xs3 + p1 * ss - a);
}

/*!
 * @brief cubic hermite interpolation
 *
 * Formula:
 *  H(s) = P0*(2*s^3 - 3*s^2 + 1) + T0*(s^3 - 2*s^2 + s)
 *            + P1*(-2*s^3 + 3*s^2) + T1*(s^3 - s^2)
 *
 * similar result using matrix:
 *  H(s) = glm_smc(t, GLM_HERMITE_MAT, (vec4){p0, p1, c0, c1})
 *
 * glm_eq(glm_smc(...), glm_hermite(...)) should return TRUE
 *
 * @param[in]  s    parameter between 0 and 1
 * @param[in]  p0   begin point
 * @param[in]  t0   tangent 1
 * @param[in]  t1   tangent 2
 * @param[in]  p1   end point
 *
 * @return H(s)
 */
CGLM_INLINE
float
glm_hermite(float s, float p0, float t0, float t1, float p1) {
  float ss, d, a, b, c, e, f;

  ss = s  * s;
  a  = ss + ss;
  c  = a  + ss;
  b  = a  * s;
  d  = s  * ss;
  f  = d  - ss;
  e  = b  - c;

  return p0 * (e + 1.0f) + t0 * (f - ss + s) + t1 * f - p1 * e;
}

/*!
 * @brief iterative way to solve cubic equation
 *
 * @param[in]  prm  parameter between 0 and 1
 * @param[in]  p0   begin point
 * @param[in]  c0   control point 1
 * @param[in]  c1   control point 2
 * @param[in]  p1   end point
 *
 * @return parameter to use in cubic equation
 */
CGLM_INLINE
float
glm_decasteljau(float prm, float p0, float c0, float c1, float p1) {
  float u, v, a, b, c, d, e, f;
  int   i;

  if (prm - p0 < CGLM_DECASTEL_SMALL)
    return 0.0f;

  if (p1 - prm < CGLM_DECASTEL_SMALL)
    return 1.0f;

  u  = 0.0f;
  v  = 1.0f;

  for (i = 0; i < CGLM_DECASTEL_MAX; i++) {
    /* de Casteljau Subdivision */
    a  = (p0 + c0) * 0.5f;
    b  = (c0 + c1) * 0.5f;
    c  = (c1 + p1) * 0.5f;
    d  = (a  + b)  * 0.5f;
    e  = (b  + c)  * 0.5f;
    f  = (d  + e)  * 0.5f; /* this one is on the curve! */

    /* The curve point is close enough to our wanted t */
    if (fabsf(f - prm) < CGLM_DECASTEL_EPS)
      return glm_clamp_zo((u  + v) * 0.5f);

    /* dichotomy */
    if (f < prm) {
      p0 = f;
      c0 = e;
      c1 = c;
      u  = (u  + v) * 0.5f;
    } else {
      c0 = a;
      c1 = d;
      p1 = f;
      v  = (u  + v) * 0.5f;
    }
  }

  return glm_clamp_zo((u  + v) * 0.5f);
}

#endif /* cglm_bezier_h */
