/*
 * Copyright (c), Recep Aslantas.
 *
 * MIT License (MIT), http://opensource.org/licenses/MIT
 * Full license can be found in the LICENSE file
 */

#ifndef cglms_perlins_h
#define cglms_perlins_h

#include "../common.h"
#include "../types-struct.h"
#include "../perlin.h"
#include "vec4.h"

/*
 Functions:
   CGLM_INLINE float glms_perlin(vec4s point);
 */

/*!
 * @brief Classic perlin noise
 *
 * @param[in]  point  4D vector
 * @returns           perlin noise value
 */
CGLM_INLINE
float
glms_perlin(vec4s point) {
  return glm_perlin(point.raw);
}

#endif /* cglms_perlins_h */
