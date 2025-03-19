/*
 * Copyright (c), Recep Aslantas.
 *
 * MIT License (MIT), http://opensource.org/licenses/MIT
 * Full license can be found in the LICENSE file
 */

#include "../include/cglm/cglm.h"
#include "../include/cglm/call.h"

CGLM_EXPORT
float
glmc_perlin_vec4(vec4 p) {
  return glm_perlin_vec4(p);
}

CGLM_EXPORT
float
glmc_perlin_vec3(vec3 p) {
  return glm_perlin_vec3(p);
}

CGLM_EXPORT
float
glmc_perlin_vec2(vec2 p) {
  return glm_perlin_vec2(p);
}
