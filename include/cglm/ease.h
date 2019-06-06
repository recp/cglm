/*
 * Copyright (c), Recep Aslantas.
 *
 * MIT License (MIT), http://opensource.org/licenses/MIT
 * Full license can be found in the LICENSE file
 */

#ifndef cglm_ease_h
#define cglm_ease_h

#include "common.h"

CGLM_INLINE
float
glm_ease_linear(float t) {
  return t;
}

CGLM_INLINE
float
glm_ease_sine_in(float t) {
  return sinf((t - 1.0f) * GLM_PI_2f) + 1.0f;
}

CGLM_INLINE
float
glm_ease_sine_out(float t) {
  return sinf(t * GLM_PI_2f);
}

CGLM_INLINE
float
glm_ease_sine_inout(float t) {
  return 0.5f * (1.0f - cosf(t * GLM_PIf));
}

CGLM_INLINE
float
glm_ease_quad_in(float t) {
  return t * t;
}

CGLM_INLINE
float
glm_ease_quad_out(float t) {
  return -(t * (t - 2.0f));
}

CGLM_INLINE
float
glm_ease_quad_inout(float t) {
  float tt;

  tt = t * t;
  if (t < 0.5f)
    return 2.0f * tt;

  return (-2.0f * tt) + (4.0f * t) - 1.0f;
}

CGLM_INLINE
float
glm_ease_cubic_in(float t) {
  return t * t * t;
}

CGLM_INLINE
float
glm_ease_cubic_out(float t) {
  float f;
  f = t - 1.0f;
  return f * f * f + 1.0f;
}

CGLM_INLINE
float
glm_ease_cubic_inout(float t) {
  float f;

  if (t < 0.5f)
    return 4.0f * t * t * t;

  f = 2.0f * t - 2.0f;

  return 0.5f * f * f * f + 1.0f;
}

CGLM_INLINE
float
glm_ease_quart_in(float t) {
  float f;
  f = t * t;
  return f * f;
}

CGLM_INLINE
float
glm_ease_quart_out(float t) {
  float f;

  f = t - 1.0f;

  return f * f * f * (1.0f - t) + 1.0f;
}

CGLM_INLINE
float
glm_ease_quart_inout(float t) {
  float f, g;

  if (t < 0.5f) {
    f = t * t;
    return 8.0f * f * f;
  }

  f = t - 1.0f;
  g = f * f;

  return -8.0f * g * g + 1.0f;
}

CGLM_INLINE
float
glm_ease_quint_in(float t) {
  float f;
  f = t * t;
  return f * f * t;
}

CGLM_INLINE
float
glm_ease_quint_out(float t) {
  float f, g;

  f = t - 1.0f;
  g = f * f;

  return g * g * f + 1.0f;
}

CGLM_INLINE
float
glm_ease_quint_inout(float t) {
  float f, g;

  if (t < 0.5f) {
    f = t * t;
    return 16.0f * f * f * t;
  }

  f = 2.0f * t - 2.0f;
  g = f * f;

  return 0.5f * g * g * f + 1.0f;
}

CGLM_INLINE
float
glm_ease_exp_in(float t) {
  if (t == 0.0f)
    return t;

  return powf(2.0f,  10.0f * (t - 1.0f));
}

CGLM_INLINE
float
glm_ease_exp_out(float t) {
  if (t == 1.0f)
    return t;

  return 1.0f - powf(2.0f, -10.0f * t);
}

CGLM_INLINE
float
glm_ease_exp_inout(float t) {
  if (t == 0.0f || t == 1.0f)
    return t;

  if (t < 0.5f)
    return 0.5f * powf(2.0f, (20.0f * t) - 10.0f);

  return -0.5f * powf(2.0f, (-20.0f * t) + 10.0f) + 1.0f;
}

CGLM_INLINE
float
glm_ease_circ_in(float t) {
  return 1.0f - sqrtf(1.0f - (t * t));
}

CGLM_INLINE
float
glm_ease_circ_out(float t) {
  return sqrtf((2.0f - t) * t);
}

CGLM_INLINE
float
glm_ease_circ_inout(float t) {
  if (t < 0.5f)
    return 0.5f * (1.0f - sqrtf(1.0f - 4.0f * (t * t)));

  return 0.5f * (sqrtf(-((2.0f * t) - 3.0f) * ((2.0f * t) - 1.0f)) + 1.0f);
}

CGLM_INLINE
float
glm_ease_back_in(float t) {
  float o, z;

  o = 1.70158f;
  z = ((o + 1.0f) * t) - o;

  return t * t * z;
}

CGLM_INLINE
float
glm_ease_back_out(float t) {
  float o, z, n;

  o = 1.70158f;
  n = t - 1.0f;
  z = (o + 1.0f) * n + o;

  return n * n * z + 1.0f;
}

CGLM_INLINE
float
glm_ease_back_inout(float t) {
  float o, z, n, m, s, x;

  o = 1.70158f;
  s = o * 1.525f;
  x = 0.5;
  n = t / 0.5f;

  if (n < 1.0f) {
    z = (s + 1) * n - s;
    m = n * n * z;
    return x * m;
  }

  n -= 2.0f;
  z  = (s + 1.0f) * n + s;
  m  = (n * n * z) + 2;

  return x * m;
}

CGLM_INLINE
float
glm_ease_elast_in(float t) {
  return sinf(13.0f * GLM_PI_2f * t) * powf(2.0f, 10.0f * (t - 1.0f));
}

CGLM_INLINE
float
glm_ease_elast_out(float t) {
  return sinf(-13.0f * GLM_PI_2f * (t + 1.0f)) * powf(2.0f, -10.0f * t) + 1.0f;
}

CGLM_INLINE
float
glm_ease_elast_inout(float t) {
  float a;

  a = 2.0f * t;

  if (t < 0.5f)
    return 0.5f * sinf(13.0f * GLM_PI_2f * a)
                * powf(2.0f, 10.0f * (a - 1.0f));

  return 0.5f * (sinf(-13.0f * GLM_PI_2f * a)
                 * powf(2.0f, -10.0f * (a - 1.0f)) + 2.0f);
}

CGLM_INLINE
float
glm_ease_bounce_out(float t) {
  float tt;

  tt = t * t;

  if (t < (4.0f / 11.0f))
    return (121.0f * tt) / 16.0f;

  if (t < 8.0f / 11.0f)
    return ((363.0f / 40.0f) * tt) - ((99.0f / 10.0f) * t) + (17.0f / 5.0f);

  if (t < (9.0f / 10.0f))
    return (4356.0f / 361.0f) * tt
            - (35442.0f / 1805.0f) * t
            + (16061.0f / 1805.0f);

  return ((54.0f / 5.0f) * tt) - ((513.0f / 25.0f) * t) + (268.0f / 25.0f);
}

CGLM_INLINE
float
glm_ease_bounce_in(float t) {
  return 1.0f - glm_ease_bounce_out(1.0f - t);
}

CGLM_INLINE
float
glm_ease_bounce_inout(float t) {
  if (t < 0.5f)
    return 0.5f * (1.0f - glm_ease_bounce_out(t * 2.0f));

  return 0.5f * glm_ease_bounce_out(t * 2.0f - 1.0f) + 0.5f;
}

#endif /* cglm_ease_h */
