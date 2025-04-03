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
glmc_mat2x3_copy(mat2x3 src, mat2x3 dest) {
  glm_mat2x3_copy(src, dest);
}

CGLM_EXPORT
void
glmc_mat2x3_zero(mat2x3 m) {
  glm_mat2x3_zero(m);
}

CGLM_EXPORT
void
glmc_mat2x3_make(const float * __restrict src, mat2x3 dest) {
  glm_mat2x3_make(src, dest);
}

CGLM_EXPORT
void
glmc_mat2x3_mul(mat2x3 m1, mat3x2 m2, mat3 dest) {
  glm_mat2x3_mul(m1, m2, dest);
}

CGLM_EXPORT
void
glmc_mat2x3_mulv(mat2x3 m, vec2 v, vec3 dest) {
  glm_mat2x3_mulv(m, v, dest);
}

CGLM_EXPORT
void
glmc_mat2x3_transpose(mat2x3 src, mat3x2 dest) {
  glm_mat2x3_transpose(src, dest);
}

CGLM_EXPORT
void
glmc_mat2x3_scale(mat2x3 m, float s) {
  glm_mat2x3_scale(m, s);
}
