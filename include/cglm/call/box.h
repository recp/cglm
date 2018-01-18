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

#ifdef __cplusplus
}
#endif
#endif /* cglmc_box_h */

