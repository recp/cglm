/*
 * Copyright (c), Recep Aslantas.
 *
 * MIT License (MIT), http://opensource.org/licenses/MIT
 * Full license can be found in the LICENSE file
 */

#include "../../include/cglm/clipspace/view_rh_zo.h"
#include "../../include/cglm/call/clipspace/view_rh_zo.h"

CGLM_EXPORT
void
glmc_lookat_rh_zo(vec3 eye, vec3 center, vec3 up, mat4 dest) {
  glm_lookat_rh_zo(eye, center, up, dest);
}

CGLM_EXPORT
void
glmc_look_rh_zo(vec3 eye, vec3 dir, vec3 up, mat4 dest) {
  glm_look_rh_zo(eye, dir, up, dest);
}

CGLM_EXPORT
void
glmc_look_anyup_rh_zo(vec3 eye, vec3 dir, mat4 dest) {
  glm_look_anyup_rh_zo(eye, dir, dest);
}
