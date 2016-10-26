/*
 * Copyright (c), Recep Aslantas.
 *
 * MIT License (MIT), http://opensource.org/licenses/MIT
 * Full license can be found in the LICENSE file
 */

#include "../include/cglm.h"

CGLM_EXPORT
void
glmc_mat4_udup(mat4 mat, mat4 dest) {
  glm_mat4_dup(mat, dest);
}

CGLM_EXPORT
void
glmc_mat4_dup(mat4 mat, mat4 dest) {
  glm_mat4_dup(mat, dest);
}

CGLM_EXPORT
void
glmc_mat4_pick3(mat4 mat, mat3 dest) {
  glm_mat4_pick3(mat, dest);
}

CGLM_EXPORT
void
glmc_mat4_pick3t(mat4 mat, mat3 dest) {
  glm_mat4_pick3t(mat, dest);
}

CGLM_EXPORT
void
glmc_mat4_ins3(mat3 mat, mat4 dest) {
  glm_mat4_ins3(mat, dest);
}

CGLM_EXPORT
void
glmc_mat4_mul(mat4 m1, mat4 m2, mat4 dest) {
  glm_mat4_mul(m1, m2, dest);
}

CGLM_EXPORT
void
glmc_mat4_mulN(mat4 * __restrict matrices[], int len, mat4 dest) {
  glm_mat4_mulN(matrices, len, dest);
}

CGLM_EXPORT
void
glmc_mat4_mulv(mat4 m, vec4 v, vec4 dest) {
  glm_mat4_mulv(m, v, dest);
}

CGLM_EXPORT
void
glmc_mat4_transpose_to(mat4 m, mat4 dest) {
  glm_mat4_transpose_to(m, dest);
}

CGLM_EXPORT
void
glmc_mat4_transpose(mat4 m) {
  glm_mat4_transpose(m);
}

CGLM_EXPORT
void
glmc_mat4_scale_p(mat4 m, float s) {
  glm_mat4_scale_p(m, s);
}

CGLM_EXPORT
void
glmc_mat4_scale(mat4 m, float s) {
  glm_mat4_scale(m, s);
}

CGLM_EXPORT
float
glmc_mat4_det(mat4 mat) {
  return glm_mat4_det(mat);
}

CGLM_EXPORT
void
glmc_mat4_inv(mat4 mat, mat4 dest) {
  glm_mat4_inv(mat, dest);
}

CGLM_EXPORT
void
glmc_mat4_inv_precise(mat4 mat, mat4 dest) {
  glm_mat4_inv_precise(mat, dest);
}

CGLM_EXPORT
void
glmc_mat4_swap_col(mat4 mat, int col1, int col2) {
  glm_mat4_swap_col(mat, col1, col2);
}

CGLM_EXPORT
void
glmc_mat4_swap_row(mat4 mat, int row1, int row2) {
  glm_mat4_swap_row(mat, row1, row2);
}
