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
glmc_quat_identity(versor q) {
  glm_quat_identity(q);
}

CGLM_EXPORT
void
glmc_quat(versor q, float angle, float x, float y, float z) {
  glm_quat(q, angle, x, y, z);
}

CGLM_EXPORT
void
glmc_quatv(versor q, float angle, vec3 v) {
  glm_quatv(q, angle, v);
}

CGLM_EXPORT
float
glmc_quat_norm(versor q) {
  return glm_quat_norm(q);
}

CGLM_EXPORT
void
glmc_quat_normalize(versor q) {
  glm_quat_normalize(q);
}

CGLM_EXPORT
float
glmc_quat_dot(versor q, versor r) {
  return glm_quat_dot(q, r);
}

CGLM_EXPORT
void
glmc_quat_mulv(versor q1, versor q2, versor dest) {
  glm_quat_mul(q1, q2, dest);
}

CGLM_EXPORT
void
glmc_quat_mat4(versor q, mat4 dest) {
  glm_quat_mat4(q, dest);
}

CGLM_EXPORT
void
glmc_quat_mat3(versor q, mat3 dest) {
  glm_quat_mat3(q, dest);
}

CGLM_EXPORT
void
glmc_quat_slerp(versor q,
                versor r,
                float  t,
                versor dest) {
  glm_quat_slerp(q, r, t, dest);
}
