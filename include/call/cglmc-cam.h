/*
 * Copyright (c), Recep Aslantas.
 *
 * MIT License (MIT), http://opensource.org/licenses/MIT
 * Full license can be found in the LICENSE file
 */

#ifndef cglmc_cam_h
#define cglmc_cam_h

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
glmc_lookat(vec3 eye,
            vec3 center,
            vec3 up,
            mat4 dest);

#endif /* cglmc_cam_h */
