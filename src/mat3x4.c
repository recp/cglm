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
glmc_mat3x4_copy(mat3x4 mat, mat3x4 dest) {
  glm_mat3x4_copy(mat, dest);
}

CGLM_EXPORT
void
glmc_mat3x4_zero(mat3x4 mat) {
  glm_mat3x4_zero(mat);
}

CGLM_EXPORT
void
glmc_mat3x4_make(float * __restrict src, mat3x4 dest) {
  glm_mat3x4_make(src, dest);
}
