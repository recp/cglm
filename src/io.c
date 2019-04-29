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
glmc_mat4_print(const mat4   matrix,
                FILE * const __restrict ostream) {
  glm_mat4_print(matrix, ostream);
}

CGLM_EXPORT
void
glmc_mat3_print(const mat3 matrix,
                FILE * const __restrict ostream) {
  glm_mat3_print(matrix, ostream);
}

CGLM_EXPORT
void
glmc_vec4_print(const vec4 vec,
                FILE * const __restrict ostream) {
  glm_vec4_print(vec, ostream);
}

CGLM_EXPORT
void
glmc_vec3_print(const vec3 vec,
                FILE * const __restrict ostream) {
  glm_vec3_print(vec, ostream);
}

CGLM_EXPORT
void
glmc_versor_print(const versor vec,
                  FILE * const __restrict ostream) {
  glm_versor_print(vec, ostream);
}
