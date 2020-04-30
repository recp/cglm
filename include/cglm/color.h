/*
 * Copyright (c), Recep Aslantas.
 *
 * MIT License (MIT), http://opensource.org/licenses/MIT
 * Full license can be found in the LICENSE file
 */

#ifndef cglm_color_h
#define cglm_color_h

#include "common.h"
#include "vec3.h"

/*!
 * @brief averages the color channels into one value
 *
 * @param[in]  rgb RGB color
 */
CGLM_DECL
float
glm_luminance(vec3 rgb) CGLM_ENDD
#ifndef CGLM_LIB
{
  vec3 l = {0.212671f, 0.715160f, 0.072169f};
  return glm_dot(rgb, l);
}
#endif

#endif /* cglm_color_h */
