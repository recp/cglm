/*
 * Copyright (c), Recep Aslantas.
 *
 * MIT License (MIT), http://opensource.org/licenses/MIT
 * Full license can be found in the LICENSE file
 */

#ifndef cglm_colors_h
#define cglm_colors_h

#include "../common.h"
#include "../types-struct.h"
#include "../color.h"
#include "vec3.h"

/*!
 * @brief averages the color channels into one value
 *
 * @param[in]  rgb RGB color
 */
CGLM_INLINE
float
glms_luminance(vec3s rgb) {
  return glm_luminance(rgb.raw);
}

#endif /* cglm_colors_h */
