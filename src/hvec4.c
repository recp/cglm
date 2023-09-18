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
glmc_hvec4(hvec3 v3, int16_t last, hvec4 dest) {
  glm_hvec4(v3, last, dest);
}

CGLM_EXPORT
void
glmc_hvec4_copy(hvec4 a, hvec4 dest) {
  glm_hvec4_copy(a, dest);
}

CGLM_EXPORT
void 
glmc_hvec4_zero(hvec4 v) {
  glm_hvec4_zero(v);
}

CGLM_EXPORT
void
glmc_hvec4_one(hvec4 v) {
  glm_hvec4_one(v);
}

CGLM_EXPORT
void
glmc_hvec4_add(hvec4 a, hvec4 b, hvec4 dest) {
  glm_hvec4_add(a, b, dest);
}

CGLM_EXPORT
void
glmc_hvec4_adds(hvec4 v, int16_t s, hvec4 dest) {
  glm_hvec4_adds(v, s, dest);
}

CGLM_EXPORT
void
glmc_hvec4_sub(hvec4 a, hvec4 b, hvec4 dest) {
  glm_hvec4_sub(a, b, dest);
}

CGLM_EXPORT
void
glmc_hvec4_subs(hvec4 v, int16_t s, hvec4 dest) {
  glm_hvec4_subs(v, s, dest);
}

CGLM_EXPORT
void
glmc_hvec4_mul(hvec4 a, hvec4 b, hvec4 dest) {
  glm_hvec4_mul(a, b, dest);
}

CGLM_EXPORT
void
glmc_hvec4_scale(hvec4 v, int16_t s, hvec4 dest) {
  glm_hvec4_scale(v, s, dest);
}

CGLM_EXPORT
int
glmc_hvec4_distance2(hvec4 a, hvec4 b) {
  return glm_hvec4_distance2(a, b);
}

CGLM_EXPORT
float
glmc_hvec4_distance(hvec4 a, hvec4 b) {
  return glm_hvec4_distance(a, b);
}

CGLM_EXPORT
void
glmc_hvec4_maxv(hvec4 a, hvec4 b, hvec4 dest) {
  glm_hvec4_maxv(a, b, dest);
}

CGLM_EXPORT
void
glmc_hvec4_minv(hvec4 a, hvec4 b, hvec4 dest) {
  glm_hvec4_minv(a, b, dest);
}

CGLM_EXPORT
void
glmc_hvec4_clamp(hvec4 v, int16_t minVal, int16_t maxVal) {
  glm_hvec4_clamp(v, minVal, maxVal);
}

CGLM_EXPORT
void
glmc_hvec4_abs(hvec4 v, hvec4 dest) {
  glm_hvec4_abs(v, dest);
}

