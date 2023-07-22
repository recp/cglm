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
glmc_mat2x3_copy(mat2x3 mat, mat2x3 dest) {
  glm_mat2x3_copy(mat, dest);
}

CGLM_EXPORT
void
glmc_mat2x3_zero(mat2x3 mat) {
  glm_mat2x3_zero(mat);
}

CGLM_EXPORT
void
glmc_mat2x3_make(float * __restrict src, mat2x3 dest) {
  glm_mat2x3_make(src, dest);
}

CGLM_EXPORT
void
glmc_mat2x3_mul(mat2x3 m1, mat3x2 m2, mat2 dest) {
  glm_mat2x3_mul(m1, m2, dest);
}
