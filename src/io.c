/*
 * Copyright (c), Recep Aslantas.
 *
 * MIT License (MIT), http://opensource.org/licenses/MIT
 * Full license can be found in the LICENSE file
 */

#define CGLM_LIB_SRC

#include "../include/cglm/cglm.h"
#include "../include/cglm/call.h"

CGLM_EXPORT
void
glmc_mat4_print(CGLM_CONST mat4   matrix,
                FILE * __restrict ostream) {
  glm_mat4_print(matrix, ostream);
}

CGLM_EXPORT
void
glmc_mat3_print(CGLM_CONST mat3 matrix,
                FILE * __restrict ostream) {
  glm_mat3_print(matrix, ostream);
}

CGLM_EXPORT
void
glmc_vec4_print(const vec4 vec,
                FILE * __restrict ostream) {
  glm_vec4_print(vec, ostream);
}

CGLM_EXPORT
void
glmc_vec3_print(const vec3 vec,
                FILE * __restrict ostream) {
  glm_vec3_print(vec, ostream);
}

CGLM_EXPORT
void
glmc_versor_print(const versor vec,
                  FILE * __restrict ostream) {
  glm_versor_print(vec, ostream);
}
