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
glmc_mat3x2_copy(mat3x2 mat, mat3x2 dest) {
  glm_mat3x2_copy(mat, dest);
}

CGLM_EXPORT
void
glmc_mat3x2_zero(mat3x2 mat) {
  glm_mat3x2_zero(mat);
}

CGLM_EXPORT
void
glmc_mat3x2_make(const float * __restrict src, mat3x2 dest) {
  glm_mat3x2_make(src, dest);
}

CGLM_EXPORT
void
glmc_mat3x2_mul(mat3x2 m1, mat2x3 m2, mat2 dest) {
  glm_mat3x2_mul(m1, m2, dest);
}

CGLM_EXPORT
void
glmc_mat3x2_mulv(mat3x2 m, vec3 v, vec2 dest) {
  glm_mat3x2_mulv(m, v, dest);
}

CGLM_EXPORT
void
glmc_mat3x2_transpose(mat3x2 m, mat2x3 dest) {
  glm_mat3x2_transpose(m, dest);
}

CGLM_EXPORT
void
glmc_mat3x2_scale(mat3x2 m, float s) {
  glm_mat3x2_scale(m, s);
}
