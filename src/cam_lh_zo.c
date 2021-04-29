/*
 * Copyright (c), Recep Aslantas.
 *
 * MIT License (MIT), http://opensource.org/licenses/MIT
 * Full license can be found in the LICENSE file
 */

#include "../include/cglm/cglm.h"
#include "../include/cglm/cam_lh_zo.h"

CGLM_EXPORT
void
glmc_perspective_lh_zo(float fovy,
                       float aspect,
                       float nearVal,
                       float farVal,
                       mat4 dest) {
  glm_perspective_lh_zo(fovy,
                        aspect,
                        nearVal,
                        farVal,
                        dest);
}

