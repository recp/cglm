/*
 * Copyright (c), Recep Aslantas.
 *
 * MIT License (MIT), http://opensource.org/licenses/MIT
 * Full license can be found in the LICENSE file
 */

#ifndef cglmc_sphere_h
#define cglmc_sphere_h
#ifdef __cplusplus
extern "C" {
#endif

#include "../cglm.h"

CGLM_EXPORT
float
glmc_sphere_radii(vec4 s);

CGLM_EXPORT
void
glmc_sphere_transform(vec4 s, mat4 m, vec4 dest);

CGLM_EXPORT
void
glmc_sphere_merge(vec4 s1, vec4 s2, vec4 dest);

CGLM_EXPORT
bool
glmc_sphere_sphere(vec4 s1, vec4 s2);

CGLM_EXPORT
bool
glmc_sphere_point(vec4 s, vec3 point);

#ifdef __cplusplus
}
#endif
#endif /* cglmc_sphere_h */
