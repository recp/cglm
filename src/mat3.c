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
glmc_mat3_copy(mat3 mat, mat3 dest) {
  glm_mat3_copy(mat, dest);
}

CGLM_EXPORT
void
glmc_mat3_identity(mat3 mat) {
  glm_mat3_identity(mat);
}

CGLM_EXPORT
void
glmc_mat3_zero(mat3 mat) {
  glm_mat3_zero(mat);
}

CGLM_EXPORT
void
glmc_mat3_identity_array(mat3 * __restrict mat, size_t count) {
  glm_mat3_identity_array(mat, count);
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
float
glmc_mat3_trace(mat3 m) {
  return glm_mat3_trace(m);
}

CGLM_EXPORT
void
glmc_mat3_quat(mat3 m, versor dest) {
  glm_mat3_quat(m, dest);
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

CGLM_EXPORT
float
glmc_mat3_rmc(vec3 r, mat3 m, vec3 c) {
  return glm_mat3_rmc(r, m, c);
}

CGLM_EXPORT
void
glmc_mat3_make(const float * __restrict src, mat3 dest) {
  glm_mat3_make(src, dest);
}
