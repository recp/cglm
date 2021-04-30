/*
 * Copyright (c), Recep Aslantas.
 *
 * MIT License (MIT), http://opensource.org/licenses/MIT
 * Full license can be found in the LICENSE file
 */

#include "../include/cglm/cglm.h"

CGLM_EXPORT
void
glmc_perspective_rh_no(float fovy,
                       float aspect,
                       float nearVal,
                       float farVal,
                       mat4 dest) {
  glm_perspective_rh_no(fovy,
                        aspect,
                        nearVal,
                        farVal,
                        dest);
}

