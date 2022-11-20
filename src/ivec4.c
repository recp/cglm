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
glmc_ivec4(ivec3 v3, int last, ivec4 dest) {
  glm_ivec4(v3, last, dest);
}

CGLM_EXPORT
void
glmc_ivec4_copy(ivec4 a, ivec4 dest) {
  glm_ivec4_copy(a, dest);
}

CGLM_EXPORT
void 
glmc_ivec4_zero(ivec4 v) {
  glm_ivec4_zero(v);
}

CGLM_EXPORT
void
glmc_ivec4_one(ivec4 v) {
  glm_ivec4_one(v);
}

CGLM_EXPORT
void
glmc_ivec4_add(ivec4 a, ivec4 b, ivec4 dest) {
  glm_ivec4_add(a, b, dest);
}

CGLM_EXPORT
void
glmc_ivec4_adds(ivec4 v, int s, ivec4 dest) {
  glm_ivec4_adds(v, s, dest);
}

CGLM_EXPORT
void
glmc_ivec4_sub(ivec4 a, ivec4 b, ivec4 dest) {
  glm_ivec4_sub(a, b, dest);
}

CGLM_EXPORT
void
glmc_ivec4_subs(ivec4 v, int s, ivec4 dest) {
  glm_ivec4_subs(v, s, dest);
}

CGLM_EXPORT
void
glmc_ivec4_mul(ivec4 a, ivec4 b, ivec4 dest) {
  glm_ivec4_mul(a, b, dest);
}

CGLM_EXPORT
void
glmc_ivec4_scale(ivec4 v, int s, ivec4 dest) {
  glm_ivec4_scale(v, s, dest);
}

CGLM_EXPORT
int
glmc_ivec4_distance2(ivec4 a, ivec4 b) {
  return glm_ivec4_distance2(a, b);
}

CGLM_EXPORT
float
glmc_ivec4_distance(ivec4 a, ivec4 b) {
  return glm_ivec4_distance(a, b);
}

CGLM_EXPORT
void
glmc_ivec4_maxv(ivec4 a, ivec4 b, ivec4 dest) {
  glm_ivec4_maxv(a, b, dest);
}

CGLM_EXPORT
void
glmc_ivec4_minv(ivec4 a, ivec4 b, ivec4 dest) {
  glm_ivec4_minv(a, b, dest);
}

CGLM_EXPORT
void
glmc_ivec4_clamp(ivec4 v, int minVal, int maxVal) {
  glm_ivec4_clamp(v, minVal, maxVal);
}

CGLM_EXPORT
void
glmc_ivec4_abs(ivec4 v, ivec4 dest) {
  glm_ivec4_abs(v, dest);
}

