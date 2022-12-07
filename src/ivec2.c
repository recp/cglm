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
glmc_ivec2(int * __restrict v, ivec2 dest) {
  glm_ivec2(v, dest);
}

CGLM_EXPORT
void
glmc_ivec2_copy(ivec2 a, ivec2 dest) {
  glm_ivec2_copy(a, dest);
}

CGLM_EXPORT
void
glmc_ivec2_zero(ivec2 v) {
  glm_ivec2_zero(v);
}

CGLM_EXPORT
void
glmc_ivec2_one(ivec2 v) {
  glm_ivec2_one(v);
}

CGLM_EXPORT
void
glmc_ivec2_add(ivec2 a, ivec2 b, ivec2 dest) {
  glm_ivec2_add(a, b, dest);
}

CGLM_EXPORT
void
glmc_ivec2_adds(ivec2 v, int s, ivec2 dest) {
  glm_ivec2_adds(v, s, dest);
}

CGLM_EXPORT
void
glmc_ivec2_sub(ivec2 a, ivec2 b, ivec2 dest) {
  glm_ivec2_sub(a, b, dest);
}

CGLM_EXPORT
void
glmc_ivec2_subs(ivec2 v, int s, ivec2 dest) {
  glm_ivec2_subs(v, s, dest);
}

CGLM_EXPORT
void
glmc_ivec2_mul(ivec2 a, ivec2 b, ivec2 dest) {
  glm_ivec2_mul(a, b, dest);
}

CGLM_EXPORT
void
glmc_ivec2_scale(ivec2 v, int s, ivec2 dest) {
  glm_ivec2_scale(v, s, dest);
}

CGLM_EXPORT
int
glmc_ivec2_distance2(ivec2 a, ivec2 b) {
  return glm_ivec2_distance2(a, b);
}

CGLM_EXPORT
float
glmc_ivec2_distance(ivec2 a, ivec2 b) {
  return glm_ivec2_distance(a, b);
}

CGLM_EXPORT
void
glmc_ivec2_maxv(ivec2 a, ivec2 b, ivec2 dest) {
  glm_ivec2_maxv(a, b, dest);
}

CGLM_EXPORT
void
glmc_ivec2_minv(ivec2 a, ivec2 b, ivec2 dest) {
  glm_ivec2_minv(a, b, dest);
}

CGLM_EXPORT
void
glmc_ivec2_clamp(ivec2 v, int minVal, int maxVal) {
  glm_ivec2_clamp(v, minVal, maxVal);
}

CGLM_EXPORT
void
glmc_ivec2_abs(ivec2 v, ivec2 dest) {
  glm_ivec2_abs(v, dest);
}

