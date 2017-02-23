/*
 * Copyright (c), Recep Aslantas.
 *
 * MIT License (MIT), http://opensource.org/licenses/MIT
 * Full license can be found in the LICENSE file
 */

#include "../include/cglm.h"

CGLM_EXPORT
void
glmc_mat3_copy(mat3 mat, mat3 dest) {
  glm_mat3_copy(mat, dest);
}

CGLM_EXPORT
void
glmc_mat3_mul(mat3 m1, mat3 m2, mat3 dest) {
  glm_mat3_mul(m1, m2, dest);
}

CGLM_EXPORT
void
glmc_mat3_transpose_to(mat3 m, mat3 dest) {
  glm_mat3_transpose_to(m, dest);
}

CGLM_EXPORT
void
glmc_mat3_transpose(mat3 m) {
  glm_mat3_transpose(m);
}

CGLM_EXPORT
void
glmc_mat3_mulv(mat3 m, vec3 v, vec3 dest) {
  glm_mat3_mulv(m, v, dest);
}

CGLM_EXPORT
void
glmc_mat3_scale(mat3 m, float s) {
  glm_mat3_scale(m, s);
}

CGLM_EXPORT
float
glmc_mat3_det(mat3 mat) {
  return glm_mat3_det(mat);
}

CGLM_EXPORT
void
glmc_mat3_inv(mat3 mat, mat3 dest) {
  glm_mat3_inv(mat, dest);
}

CGLM_EXPORT
void
glmc_mat3_swap_col(mat3 mat, int col1, int col2) {
  glm_mat3_swap_col(mat, col1, col2);
}

CGLM_EXPORT
void
glmc_mat3_swap_row(mat3 mat, int row1, int row2) {
  glm_mat3_swap_row(mat, row1, row2);
}
