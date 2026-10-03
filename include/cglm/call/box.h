/*
 * Copyright (c), Recep Aslantas.
 *
 * MIT License (MIT), http://opensource.org/licenses/MIT
 * Full license can be found in the LICENSE file
 */

#ifndef cglmc_box_h
#define cglmc_box_h
#ifdef __cplusplus
extern "C" {
#endif

#include "../common.h"

CGLM_EXPORT
void
glmc_aabb_transform(CGLM_CONST vec3 box[2], CGLM_CONST mat4 m, vec3 dest[2]);

CGLM_EXPORT
void
glmc_aabb_merge(CGLM_CONST vec3 box1[2], CGLM_CONST vec3 box2[2], vec3 dest[2]);

CGLM_EXPORT
void
glmc_aabb_crop(CGLM_CONST vec3 box[2], CGLM_CONST vec3 cropBox[2], vec3 dest[2]);

CGLM_EXPORT
void
glmc_aabb_crop_until(CGLM_CONST vec3 box[2],
                     CGLM_CONST vec3 cropBox[2],
                     CGLM_CONST vec3 clampBox[2],
                     vec3 dest[2]);

CGLM_EXPORT
bool
glmc_aabb_frustum(CGLM_CONST vec3 box[2], CGLM_CONST vec4 planes[6]);

CGLM_EXPORT
void
glmc_aabb_invalidate(vec3 box[2]);

CGLM_EXPORT
bool
glmc_aabb_isvalid(CGLM_CONST vec3 box[2]);

CGLM_EXPORT
float
glmc_aabb_size(CGLM_CONST vec3 box[2]);

CGLM_EXPORT
float
glmc_aabb_radius(CGLM_CONST vec3 box[2]);

CGLM_EXPORT
void
glmc_aabb_center(CGLM_CONST vec3 box[2], vec3 dest);

CGLM_EXPORT
bool
glmc_aabb_aabb(CGLM_CONST vec3 box[2], CGLM_CONST vec3 other[2]);

CGLM_EXPORT
bool
glmc_aabb_point(CGLM_CONST vec3 box[2], const vec3 point);

CGLM_EXPORT
bool
glmc_aabb_contains(CGLM_CONST vec3 box[2], CGLM_CONST vec3 other[2]);

CGLM_EXPORT
bool
glmc_aabb_sphere(CGLM_CONST vec3 box[2], const vec4 s);

#ifdef __cplusplus
}
#endif
#endif /* cglmc_box_h */
