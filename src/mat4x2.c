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
glmc_mat4x2_copy(mat4x2 mat, mat4x2 dest) {
  glm_mat4x2_copy(mat, dest);
}

CGLM_EXPORT
void
glmc_mat4x2_zero(mat4x2 mat) {
  glm_mat4x2_zero(mat);
}

CGLM_EXPORT
void
glmc_mat4x2_make(float * __restrict src, mat4x2 dest) {
  glm_mat4x2_make(src, dest);
}
