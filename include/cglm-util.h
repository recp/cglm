/*
 * Copyright (c), Recep Aslantas.
 *
 * MIT License (MIT), http://opensource.org/licenses/MIT
 * Full license can be found in the LICENSE file
 */

#ifndef cglm_util_h
#define cglm_util_h

#include "cglm-common.h"

CGLM_INLINE
float
glm_rad(float deg) {
  return deg * M_PI / 180.0f;
}

CGLM_INLINE
float
glm_deg(float rad) {
  return rad * 180.0f / M_PI;
}

#endif /* cglm_util_h */
