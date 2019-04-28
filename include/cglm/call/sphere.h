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
glmc_sphere_radii(const vec4 s);

CGLM_EXPORT
void
glmc_sphere_transform(const vec4 s, const mat4 m, vec4 dest);

CGLM_EXPORT
void
glmc_sphere_merge(const vec4 s1, const vec4 s2, vec4 dest);

CGLM_EXPORT
bool
glmc_sphere_sphere(const vec4 s1, const vec4 s2);

CGLM_EXPORT
bool
glmc_sphere_point(const vec4 s, const vec3 point);

#ifdef __cplusplus
}
#endif
#endif /* cglmc_sphere_h */
