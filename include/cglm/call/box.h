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

#include "../cglm.h"

CGLM_EXPORT
void
glmc_aabb_transform(vec3 box[2], mat4 m, vec3 dest[2]);

CGLM_EXPORT
void
glmc_aabb_merge(vec3 box1[2], vec3 box2[2], vec3 dest[2]);

CGLM_EXPORT
void
glmc_aabb_crop(vec3 box[2], vec3 cropBox[2], vec3 dest[2]);

CGLM_EXPORT
void
glmc_aabb_crop_until(vec3 box[2],
                     vec3 cropBox[2],
                     vec3 clampBox[2],
                     vec3 dest[2]);

CGLM_EXPORT
bool
glmc_aabb_frustum(vec3 box[2], vec4 planes[6]);

CGLM_EXPORT
void
glmc_aabb_invalidate(vec3 box[2]);

CGLM_EXPORT
bool
glmc_aabb_isvalid(vec3 box[2]);

CGLM_EXPORT
float
glmc_aabb_size(vec3 box[2]);

CGLM_EXPORT
float
glmc_aabb_radius(vec3 box[2]);

CGLM_EXPORT
void
glmc_aabb_center(vec3 box[2], vec3 dest);

CGLM_EXPORT
bool
glmc_aabb_aabb(vec3 box[2], vec3 other[2]);

CGLM_EXPORT
bool
glmc_aabb_point(vec3 box[2], vec3 point);

CGLM_EXPORT
bool
glmc_aabb_contains(vec3 box[2], vec3 other[2]);

CGLM_EXPORT
bool
glmc_aabb_sphere(vec3 box[2], vec4 s);

#ifdef __cplusplus
}
#endif
#endif /* cglmc_box_h */
