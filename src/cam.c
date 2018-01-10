/*
 * Copyright (c), Recep Aslantas.
 *
 * MIT License (MIT), http://opensource.org/licenses/MIT
 * Full license can be found in the LICENSE file
 */

#include "../include/cglm/cglm.h"
#include "../include/cglm/call.h"

CGLM_EXPORT
void
glmc_frustum(float left,
             float right,
             float bottom,
             float top,
             float nearVal,
             float farVal,
             mat4 dest) {
  glm_frustum(left,
              right,
              bottom,
              top,
              nearVal,
              farVal,
              dest);
}

CGLM_EXPORT
void
glmc_ortho(float left,
           float right,
           float bottom,
           float top,
           float nearVal,
           float farVal,
           mat4 dest) {
  glm_ortho(left,
            right,
            bottom,
            top,
            nearVal,
            farVal,
            dest);
}

CGLM_EXPORT
void
glmc_perspective(float fovy,
                 float aspect,
                 float nearVal,
                 float farVal,
                 mat4 dest) {
  glm_perspective(fovy,
                  aspect,
                  nearVal,
                  farVal,
                  dest);
}

CGLM_EXPORT
void
glmc_lookat(vec3 eye,
            vec3 center,
            vec3 up,
            mat4 dest) {
  glm_lookat(eye, center, up, dest);
}

CGLM_EXPORT
void
glmc_look(vec3 eye, vec3 dir, vec3 up, mat4 dest) {
  glm_look(eye, dir, up, dest);
}

CGLM_EXPORT
void
glmc_look_any(vec3 eye, vec3 dir, mat4 dest) {
  glm_look_any(eye, dir, dest);
}

CGLM_EXPORT
void
glmc_frustum_planes(mat4 m, vec4 dest[6]) {
  glm_frustum_planes(m, dest);
}

CGLM_EXPORT
void
glmc_frustum_corners(mat4 invMat, vec4 dest[8]) {
  glm_frustum_corners(invMat, dest);
}

CGLM_EXPORT
void
glmc_frustum_center(vec4 corners[8], vec4 dest) {
  glm_frustum_center(corners, dest);
}
