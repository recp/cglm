/*
 * Copyright (c), Recep Aslantas.
 *
 * MIT License (MIT), http://opensource.org/licenses/MIT
 * Full license can be found in the LICENSE file
 */

#include "../../include/cglm/clipspace/project_zo.h"
#include "../../include/cglm/call/clipspace/project_zo.h"

CGLM_EXPORT
void
glmc_unprojecti_zo(vec3 pos, mat4 invMat, vec4 vp, vec3 dest) {
  glm_unprojecti_zo(pos, invMat, vp, dest);
}

CGLM_EXPORT
void
glmc_project_zo(vec3 pos, mat4 m, vec4 vp, vec3 dest) {
  glm_project_zo(pos, m, vp, dest);
}

CGLM_EXPORT
float
glmc_project_z_zo(vec3 pos, mat4 m) {
  return glm_project_z_zo(pos, m);
}
