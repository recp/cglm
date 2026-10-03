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
glmc_euler_angles(CGLM_CONST mat4 m, vec3 dest) {
  glm_euler_angles(m, dest);
}

CGLM_EXPORT
void
glmc_euler(const vec3 angles, mat4 dest) {
  glm_euler(angles, dest);
}

CGLM_EXPORT
void
glmc_euler_xyz(const vec3 angles,  mat4 dest) {
  glm_euler_xyz(angles, dest);
}

CGLM_EXPORT
void
glmc_euler_zyx(const vec3 angles,  mat4 dest) {
  glm_euler_zyx(angles, dest);
}

CGLM_EXPORT
void
glmc_euler_zxy(const vec3 angles, mat4 dest) {
  glm_euler_zxy(angles, dest);
}

CGLM_EXPORT
void
glmc_euler_xzy(const vec3 angles, mat4 dest) {
  glm_euler_xzy(angles, dest);
}

CGLM_EXPORT
void
glmc_euler_yzx(const vec3 angles, mat4 dest) {
  glm_euler_yzx(angles, dest);
}

CGLM_EXPORT
void
glmc_euler_yxz(const vec3 angles, mat4 dest) {
  glm_euler_yxz(angles, dest);
}

CGLM_EXPORT
void
glmc_euler_by_order(const vec3 angles, glm_euler_seq axis, mat4 dest) {
  glm_euler_by_order(angles, axis, dest);
}

CGLM_EXPORT
void
glmc_euler_xyz_quat(const vec3 angles, versor dest) {
  glm_euler_xyz_quat(angles, dest);
}

CGLM_EXPORT
void
glmc_euler_xzy_quat(const vec3 angles, versor dest) {
  glm_euler_xzy_quat(angles, dest);
}

CGLM_EXPORT
void
glmc_euler_yxz_quat(const vec3 angles, versor dest) {
  glm_euler_yxz_quat(angles, dest);
}

CGLM_EXPORT
void
glmc_euler_yzx_quat(const vec3 angles, versor dest) {
  glm_euler_yzx_quat(angles, dest);
}

CGLM_EXPORT
void
glmc_euler_zxy_quat(const vec3 angles, versor dest) {
  glm_euler_zxy_quat(angles, dest);
}

CGLM_EXPORT
void
glmc_euler_zyx_quat(const vec3 angles, versor dest) {
  glm_euler_zyx_quat(angles, dest);
}
