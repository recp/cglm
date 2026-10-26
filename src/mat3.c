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
glmc_mat3_copy(CGLM_CONST mat3 mat, mat3 dest) {
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
glmc_mat3_mul(CGLM_CONST mat3 m1, CGLM_CONST mat3 m2, mat3 dest) {
  glm_mat3_mul(m1, m2, dest);
}

CGLM_EXPORT
void
glmc_mat3_transpose_to(CGLM_CONST mat3 m, mat3 dest) {
  glm_mat3_transpose_to(m, dest);
}

CGLM_EXPORT
void
glmc_mat3_transpose(mat3 m) {
  glm_mat3_transpose(m);
}

CGLM_EXPORT
void
glmc_mat3_mulv(CGLM_CONST mat3 m, const vec3 v, vec3 dest) {
  glm_mat3_mulv(m, v, dest);
}

CGLM_EXPORT
float
glmc_mat3_trace(CGLM_CONST mat3 m) {
  return glm_mat3_trace(m);
}

CGLM_EXPORT
void
glmc_mat3_quat(CGLM_CONST mat3 m, versor dest) {
  glm_mat3_quat(m, dest);
}

CGLM_EXPORT
void
glmc_mat3_scale(mat3 m, float s) {
  glm_mat3_scale(m, s);
}

CGLM_EXPORT
float
glmc_mat3_det(CGLM_CONST mat3 mat) {
  return glm_mat3_det(mat);
}

CGLM_EXPORT
void
glmc_mat3_inv(CGLM_CONST mat3 mat, mat3 dest) {
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
glmc_mat3_rmc(const vec3 r, CGLM_CONST mat3 m, const vec3 c) {
  return glm_mat3_rmc(r, m, c);
}

CGLM_EXPORT
void
glmc_mat3_make(const float * __restrict src, mat3 dest) {
  glm_mat3_make(src, dest);
}

CGLM_EXPORT
void
glmc_mat3_textrans(float sx, float sy, float rot, float tx, float ty, mat3 dest) {
  glm_mat3_textrans(sx, sy, rot, tx, ty, dest);
}
