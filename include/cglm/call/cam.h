/*
 * Copyright (c), Recep Aslantas.
 *
 * MIT License (MIT), http://opensource.org/licenses/MIT
 * Full license can be found in the LICENSE file
 */

#ifndef cglmc_cam_h
#define cglmc_cam_h
#ifdef __cplusplus
extern "C" {
#endif

#include "../cglm.h"

CGLM_EXPORT
void
glmc_frustum(float left,
             float right,
             float bottom,
             float top,
             float nearVal,
             float farVal,
             mat4 dest);

CGLM_EXPORT
void
glmc_ortho(float left,
           float right,
           float bottom,
           float top,
           float nearVal,
           float farVal,
           mat4 dest);

CGLM_EXPORT
void
glmc_perspective(float fovy,
                 float aspect,
                 float nearVal,
                 float farVal,
                 mat4 dest);

CGLM_EXPORT
void
glmc_lookat(vec3 eye, vec3 center, vec3 up, mat4 dest);

CGLM_EXPORT
void
glmc_look(vec3 eye, vec3 dir, vec3 up, mat4 dest);

CGLM_EXPORT
void
glmc_look_anyup(vec3 eye, vec3 dir, mat4 dest);

CGLM_EXPORT
void
glmc_frustum_planes(mat4 m, vec4 dest[6]);

CGLM_EXPORT
void
glmc_frustum_corners(mat4 invMat, vec4 dest[8]);

CGLM_EXPORT
void
glmc_frustum_center(vec4 corners[8], vec4 dest);

#ifdef __cplusplus
}
#endif
#endif /* cglmc_cam_h */
