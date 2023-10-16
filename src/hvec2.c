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
glmc_hvec2(int16_t * __restrict v, hvec2 dest) {
  glm_hvec2(v, dest);
}

CGLM_EXPORT
void
glmc_hvec2_copy(hvec2 a, hvec2 dest) {
  glm_hvec2_copy(a, dest);
}

CGLM_EXPORT
void
glmc_hvec2_zero(hvec2 v) {
  glm_hvec2_zero(v);
}

CGLM_EXPORT
void
glmc_hvec2_one(hvec2 v) {
  glm_hvec2_one(v);
}

CGLM_EXPORT
void
glmc_hvec2_add(hvec2 a, hvec2 b, hvec2 dest) {
  glm_hvec2_add(a, b, dest);
}

CGLM_EXPORT
void
glmc_hvec2_adds(hvec2 v, int16_t s, hvec2 dest) {
  glm_hvec2_adds(v, s, dest);
}

CGLM_EXPORT
void
glmc_hvec2_sub(hvec2 a, hvec2 b, hvec2 dest) {
  glm_hvec2_sub(a, b, dest);
}

CGLM_EXPORT
void
glmc_hvec2_subs(hvec2 v, int16_t s, hvec2 dest) {
  glm_hvec2_subs(v, s, dest);
}

CGLM_EXPORT
void
glmc_hvec2_mul(hvec2 a, hvec2 b, hvec2 dest) {
  glm_hvec2_mul(a, b, dest);
}

CGLM_EXPORT
void
glmc_hvec2_scale(hvec2 v, int16_t s, hvec2 dest) {
  glm_hvec2_scale(v, s, dest);
}

CGLM_EXPORT
int
glmc_hvec2_distance2(hvec2 a, hvec2 b) {
  return glm_hvec2_distance2(a, b);
}

CGLM_EXPORT
float
glmc_hvec2_distance(hvec2 a, hvec2 b) {
  return glm_hvec2_distance(a, b);
}

CGLM_EXPORT
void
glmc_hvec2_fill(hvec2 v, int16_t val) {
  glm_hvec2_fill(v, val);
}

CGLM_EXPORT
bool
glmc_hvec2_eq(hvec2 v, int16_t val) {
  return glm_hvec2_eq(v, val);
}

CGLM_EXPORT
bool
glmc_hvec2_eqv(hvec2 a, hvec2 b) {
  return glm_hvec2_eqv(a, b);
}

CGLM_EXPORT
void
glmc_hvec2_maxv(hvec2 a, hvec2 b, hvec2 dest) {
  glm_hvec2_maxv(a, b, dest);
}

CGLM_EXPORT
void
glmc_hvec2_minv(hvec2 a, hvec2 b, hvec2 dest) {
  glm_hvec2_minv(a, b, dest);
}

CGLM_EXPORT
void
glmc_hvec2_clamp(hvec2 v, int16_t minVal, int16_t maxVal) {
  glm_hvec2_clamp(v, minVal, maxVal);
}

CGLM_EXPORT
void
glmc_hvec2_abs(hvec2 v, hvec2 dest) {
  glm_hvec2_abs(v, dest);
}

