/*
 * Copyright (c), Recep Aslantas.
 *
 * MIT License (MIT), http://opensource.org/licenses/MIT
 * Full license can be found in the LICENSE file
 */

#ifndef cglmc_ray_h
#define cglmc_ray_h
#ifdef __cplusplus
extern "C" {
#endif
#include "../cglm.h"

CGLM_EXPORT
bool
glmc_ray_triangle(vec3   origin,
                  vec3   direction,
                  vec3   v0,
                  vec3   v1,
                  vec3   v2,
                  float *d);
    
#ifdef __cplusplus
}
#endif
#endif /* cglmc_ray_h */
