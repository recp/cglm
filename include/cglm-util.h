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

#include "cglm-common.h"

/*!
 * @brief get sign of 32 bit integer as +1 or -1
 *
 * @param X integer value
 */
CGLM_INLINE
int
glm_sign(int val) {
  return ((val >> 31) - (-val >> 31));
}

CGLM_INLINE
float
glm_rad(float deg) {
  return deg * CGLM_PI / 180.0f;
}

CGLM_INLINE
float
glm_deg(float rad) {
  return rad * 180.0f / CGLM_PI;
}

CGLM_INLINE
void
glm_make_rad(float *deg) {
  *deg = *deg * CGLM_PI / 180.0f;
}

CGLM_INLINE
void
glm_make_deg(float *rad) {
  *rad = *rad * 180.0f / CGLM_PI;
}

CGLM_INLINE
float
glm_pow2(float x) {
  return x * x;
}

#endif /* cglm_util_h */
