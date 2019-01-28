/*
 * Copyright (c), Recep Aslantas.
 *
 * MIT License (MIT), http://opensource.org/licenses/MIT
 * Full license can be found in the LICENSE file
 */

#ifndef cglm_bezier_h
#define cglm_bezier_h

#define GLM_BEZIER_MAT_INIT  {{-1.0f,  3.0f, -3.0f, 1.0f},                    \
                              { 3.0f, -6.0f,  3.0f, 0.0f},                    \
                              {-3.0f,  3.0f,  0.0f, 0.0f},                    \
                              { 1.0f,  0.0f,  0.0f, 0.0f}}

/* for C only */
#define GLM_BEZIER_MAT ((mat4)GLM_BEZIER_MAT_INIT)

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

#endif /* cglm_bezier_h */
