/*
 * Copyright (c), Recep Aslantas.
 *
 * MIT License (MIT), http://opensource.org/licenses/MIT
 * Full license can be found in the LICENSE file
 */

#include "../../include/cglm/clipspace/ortho_rh_no.h"
#include "../../include/cglm/call/clipspace/ortho_rh_no.h"

CGLM_EXPORT
void
glmc_ortho_rh_no(float left,    float right,
                 float bottom,  float top,
                 float nearZ, float farZ,
                 mat4  dest) {
  glm_ortho_rh_no(left,   right,
                  bottom, top,
                  nearZ,  farZ,
                  dest);
}

CGLM_EXPORT
void
glmc_ortho_aabb_rh_no(vec3 box[2], mat4 dest) {
  glm_ortho_aabb_rh_no(box, dest);
}

CGLM_EXPORT
void
glmc_ortho_aabb_p_rh_no(vec3 box[2], float padding, mat4 dest) {
  glm_ortho_aabb_p_rh_no(box, padding, dest);
}

CGLM_EXPORT
void
glmc_ortho_aabb_pz_rh_no(vec3 box[2], float padding, mat4 dest) {
  glm_ortho_aabb_pz_rh_no(box, padding, dest);
}

CGLM_EXPORT
void
glmc_ortho_default_rh_no(float aspect, mat4 dest) {
  glm_ortho_default_rh_no(aspect, dest);
}

CGLM_EXPORT
void
glmc_ortho_default_s_rh_no(float aspect, float size, mat4 dest) {
  glm_ortho_default_s_rh_no(aspect, size, dest);
}
