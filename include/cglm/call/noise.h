/*
 * Copyright (c), Recep Aslantas.
 *
 * MIT License (MIT), http://opensource.org/licenses/MIT
 * Full license can be found in the LICENSE file
 */

#ifndef cglmc_noise_h
#define cglmc_noise_h
#ifdef __cplusplus
extern "C" {
#endif

#include "../common.h"

CGLM_EXPORT
float
glmc_perlin_vec4(const vec4 point);

CGLM_EXPORT
float
glmc_perlin_vec3(const vec3 point);

CGLM_EXPORT
float
glmc_perlin_vec2(const vec2 point);

#ifdef __cplusplus
}
#endif
#endif /* cglmc_noise_h */
