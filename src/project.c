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
glmc_unprojecti(const vec3 pos, const mat4 invMat, const vec4 vp, vec3 dest) {
  glm_unprojecti(pos, invMat, vp, dest);
}

CGLM_EXPORT
void
glmc_unproject(const vec3 pos, const mat4 m, const vec4 vp, vec3 dest) {
  glm_unproject(pos, m, vp, dest);
}

CGLM_EXPORT
void
glmc_project(const vec3 pos, const mat4 m, const vec4 vp, vec3 dest) {
  glm_project(pos, m, vp, dest);
}
