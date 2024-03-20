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

CGLM_EXPORT
bool
glmc_ray_sphere(vec3 origin,
                vec3 dir,
                vec4 s,
                float * __restrict t1,
                float * __restrict t2);

CGLM_EXPORT
void
glmc_ray_at(vec3 orig, vec3 dir, float t, vec3 point);

#ifdef __cplusplus
}
#endif
#endif /* cglmc_ray_h */
