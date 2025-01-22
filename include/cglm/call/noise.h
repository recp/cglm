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

#include "../cglm.h"

CGLM_EXPORT
float
glmc_perlin_vec4(vec4 point);

CGLM_EXPORT
float
glmc_perlin_vec3(vec3 point);

CGLM_EXPORT
float
glmc_perlin_vec2(vec2 point);

#ifdef __cplusplus
}
#endif
#endif /* cglmc_noise_h */
