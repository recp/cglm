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
glmc_mat3x2_make(float * __restrict src, mat3x2 dest) {
  glm_mat3x2_make(src, dest);
}
