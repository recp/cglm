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
glmc_mat4x3_copy(mat4x3 mat, mat4x3 dest) {
  glm_mat4x3_copy(mat, dest);
}

CGLM_EXPORT
void
glmc_mat4x3_zero(mat4x3 mat) {
  glm_mat4x3_zero(mat);
}

CGLM_EXPORT
void
glmc_mat4x3_make(float * __restrict src, mat4x3 dest) {
  glm_mat4x3_make(src, dest);
}

CGLM_EXPORT
void
glmc_mat4x3_mul(mat4x3 m1, mat3x4 m2, mat4 dest) {
  glm_mat4x3_mul(m1, m2, dest);
}
