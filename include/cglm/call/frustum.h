/*
 * Copyright (c), Recep Aslantas.
 *
 * MIT License (MIT), http://opensource.org/licenses/MIT
 * Full license can be found in the LICENSE file
 */

#ifndef cglmc_frustum_h
#define cglmc_frustum_h
#ifdef __cplusplus
extern "C" {
#endif

#include "../cglm.h"

CGLM_EXPORT
void
glmc_frustum_planes(mat4 m, vec4 dest[6]);

CGLM_EXPORT
void
glmc_frustum_corners(mat4 invMat, vec4 dest[8]);

CGLM_EXPORT
void
glmc_frustum_center(vec4 corners[8], vec4 dest);

CGLM_EXPORT
void
glmc_frustum_box(vec4 corners[8], mat4 m, vec3 box[2]);

#ifdef __cplusplus
}
#endif
#endif /* cglmc_frustum_h */
