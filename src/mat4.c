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
glmc_mat4_ucopy(CGLM_CONST mat4 mat, mat4 dest) {
  glm_mat4_copy(mat, dest);
}

CGLM_EXPORT
void
glmc_mat4_copy(CGLM_CONST mat4 mat, mat4 dest) {
  glm_mat4_copy(mat, dest);
}

CGLM_EXPORT
void
glmc_mat4_identity(mat4 mat) {
  glm_mat4_identity(mat);
}

CGLM_EXPORT
void
glmc_mat4_identity_array(mat4 * __restrict mat, size_t count) {
  glm_mat4_identity_array(mat, count);
}

CGLM_EXPORT
void
glmc_mat4_zero(mat4 mat) {
  glm_mat4_zero(mat);
}

CGLM_EXPORT
void
glmc_mat4_pick3(CGLM_CONST mat4 mat, mat3 dest) {
  glm_mat4_pick3(mat, dest);
}

CGLM_EXPORT
void
glmc_mat4_pick3t(CGLM_CONST mat4 mat, mat3 dest) {
  glm_mat4_pick3t(mat, dest);
}

CGLM_EXPORT
void
glmc_mat4_ins3(CGLM_CONST mat3 mat, mat4 dest) {
  glm_mat4_ins3(mat, dest);
}

CGLM_EXPORT
void
glmc_mat4_mul(CGLM_CONST mat4 m1, CGLM_CONST mat4 m2, mat4 dest) {
  glm_mat4_mul(m1, m2, dest);
}

CGLM_EXPORT
void
glmc_mat4_mulN(mat4 * const __restrict matrices[], uint32_t len, mat4 dest) {
  glm_mat4_mulN(matrices, len, dest);
}

CGLM_EXPORT
void
glmc_mat4_mulv(CGLM_CONST mat4 m, const vec4 v, vec4 dest) {
  glm_mat4_mulv(m, v, dest);
}

CGLM_EXPORT
void
glmc_mat4_mulv3(CGLM_CONST mat4 m, const vec3 v, float last, vec3 dest) {
  glm_mat4_mulv3(m, v, last, dest);
}

CGLM_EXPORT
float
glmc_mat4_trace(CGLM_CONST mat4 m) {
  return glm_mat4_trace(m);
}

CGLM_EXPORT
float
glmc_mat4_trace3(CGLM_CONST mat4 m) {
  return glm_mat4_trace3(m);
}

CGLM_EXPORT
void
glmc_mat4_quat(CGLM_CONST mat4 m, versor dest) {
  glm_mat4_quat(m, dest);
}

CGLM_EXPORT
void
glmc_mat4_transpose_to(CGLM_CONST mat4 m, mat4 dest) {
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
glmc_mat4_det(CGLM_CONST mat4 mat) {
  return glm_mat4_det(mat);
}

CGLM_EXPORT
void
glmc_mat4_inv(CGLM_CONST mat4 mat, mat4 dest) {
  glm_mat4_inv(mat, dest);
}

CGLM_EXPORT
void
glmc_mat4_inv_precise(mat4 mat, mat4 dest) {
  glm_mat4_inv_precise(mat, dest);
}

CGLM_EXPORT
void
glmc_mat4_inv_fast(CGLM_CONST mat4 mat, mat4 dest) {
  glm_mat4_inv_fast(mat, dest);
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

CGLM_EXPORT
float
glmc_mat4_rmc(const vec4 r, CGLM_CONST mat4 m, const vec4 c) {
  return glm_mat4_rmc(r, m, c);
}

CGLM_EXPORT
void
glmc_mat4_make(const float * __restrict src, mat4 dest) {
  glm_mat4_make(src, dest);
}

CGLM_EXPORT
void
glmc_mat4_textrans(float sx, float sy, float rot, float tx, float ty, mat4 dest) {
  glm_mat4_textrans(sx, sy, rot, tx, ty, dest);
}
