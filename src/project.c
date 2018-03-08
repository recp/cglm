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
glmc_unprojecti(mat4 invMat, vec4 vp, vec3 coord, vec3 dest) {
  glm_unprojecti(invMat, vp, coord, dest);
}

CGLM_EXPORT
void
glmc_unproject(mat4 m, vec4 vp, vec3 coord, vec3 dest) {
  glm_unproject(m, vp, coord, dest);
}
