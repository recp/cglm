/*
 * Copyright (c), Recep Aslantas.
 *
 * MIT License (MIT), http://opensource.org/licenses/MIT
 * Full license can be found in the LICENSE file
 */

#ifndef cglmc_project_h
#define cglmc_project_h
#ifdef __cplusplus
extern "C" {
#endif

#include "../common.h"

CGLM_EXPORT
void
glmc_unprojecti(const vec3 pos, CGLM_CONST mat4 invMat, const vec4 vp, vec3 dest);

CGLM_EXPORT
void
glmc_unproject(const vec3 pos, CGLM_CONST mat4 m, const vec4 vp, vec3 dest);

CGLM_EXPORT
void
glmc_project(const vec3 pos, CGLM_CONST mat4 m, const vec4 vp, vec3 dest);

CGLM_EXPORT
float
glmc_project_z(const vec3 pos, CGLM_CONST mat4 m);

CGLM_EXPORT
void
glmc_pickmatrix(const vec2 center, const vec2 size, const vec4 vp, mat4 dest);

#ifdef __cplusplus
}
#endif
#endif /* cglmc_project_h */
