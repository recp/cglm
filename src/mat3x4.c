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
glmc_mat3x4_copy(mat3x4 src, mat3x4 dest) {
  glm_mat3x4_copy(src, dest);
}

CGLM_EXPORT
void
glmc_mat3x4_zero(mat3x4 m) {
  glm_mat3x4_zero(m);
}

CGLM_EXPORT
void
glmc_mat3x4_make(const float * __restrict src, mat3x4 dest) {
  glm_mat3x4_make(src, dest);
}

CGLM_EXPORT
void
glmc_mat3x4_mul(mat3x4 m1, mat4x3 m2, mat4 dest) {
  glm_mat3x4_mul(m1, m2, dest);
}

CGLM_EXPORT
void
glmc_mat3x4_mulv(mat3x4 m, vec3 v, vec4 dest) {
  glm_mat3x4_mulv(m, v, dest);
}

CGLM_EXPORT
void
glmc_mat3x4_transpose(mat3x4 src, mat4x3 dest) {
  glm_mat3x4_transpose(src, dest);
}

CGLM_EXPORT
void
glmc_mat3x4_scale(mat3x4 m, float s) {
  glm_mat3x4_scale(m, s);
}
