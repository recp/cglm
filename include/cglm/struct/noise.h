/*
 * Copyright (c), Recep Aslantas.
 *
 * MIT License (MIT), http://opensource.org/licenses/MIT
 * Full license can be found in the LICENSE file
 */

#ifndef cglms_noises_h
#define cglms_noises_h

#include "../common.h"
#include "../types-struct.h"
#include "../noise.h"
#include "vec4.h"

/*
 Functions:
   CGLM_INLINE float glms_perlin_vec4(vec4s point);
 */

/*!
 * @brief Classic perlin noise
 *
 * @param[in]  point  4D vector
 * @returns           perlin noise value
 */
CGLM_INLINE
float
glms_perlin_vec4(vec4s point) {
  return glm_perlin_vec4(point.raw);
}

/*!
 * @brief Classic perlin noise
 *
 * @param[in]  point  3D vector
 * @returns           perlin noise value
 */
CGLM_INLINE
float
glms_perlin_vec3(vec3s point) {
  return glm_perlin_vec3(point.raw);
}

/*!
 * @brief Classic perlin noise
 *
 * @param[in]  point  2D vector
 * @returns           perlin noise value
 */
CGLM_INLINE
float
glms_perlin_vec2(vec2s point) {
  return glm_perlin_vec2(point.raw);
}

#endif /* cglms_noises_h */
