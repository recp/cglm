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
glmc_translate2d_make(mat3 m, vec2 v) {
  glm_translate2d_make(m, v);
}

CGLM_EXPORT
void
glmc_translate2d_to(mat3 m, vec2 v, mat3 dest) {
  glm_translate2d_to(m, v, dest);
}

CGLM_EXPORT
void
glmc_translate2d(mat3 m, vec2 v) {
  glm_translate2d(m, v);
}

CGLM_EXPORT
void
glmc_translate2d_x(mat3 m, float to) {
  glm_translate2d_x(m, to);
}

CGLM_EXPORT
void
glmc_translate2d_y(mat3 m, float to) {
  glm_translate2d_y(m, to);
}

CGLM_EXPORT
void
glmc_scale2d_to(mat3 m, vec2 v, mat3 dest) {
  glm_scale2d_to(m, v, dest);
}

CGLM_EXPORT
void
glmc_scale2d_make(mat3 m, vec2 v) {
  glm_scale2d_make(m, v);
}

CGLM_EXPORT
void
glmc_scale2d(mat3 m, vec2 v) {
  glm_scale2d(m, v);
}

CGLM_EXPORT
void
glmc_scale2d_uni(mat3 m, float s) {
  glm_scale2d_uni(m, s);
}

CGLM_EXPORT
void
glmc_rotate2d_make(mat3 m, float angle) {
  glm_rotate2d_make(m, angle);
}

CGLM_EXPORT
void
glmc_rotate2d(mat3 m, float angle) {
  glm_rotate2d(m, angle);
}

CGLM_EXPORT
void
glmc_rotate2d_to(mat3 m, float angle, mat3 dest) {
  glm_rotate2d_to(m, angle, dest);
}
