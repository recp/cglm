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
