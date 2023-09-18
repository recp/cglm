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
glmc_hvec3(hvec4 v4, hvec3 dest) {
  glm_hvec3(v4, dest);
}

CGLM_EXPORT
void
glmc_hvec3_copy(hvec3 a, hvec3 dest) {
  glm_hvec3_copy(a, dest);
}

CGLM_EXPORT
void 
glmc_hvec3_zero(hvec3 v) {
  glm_hvec3_zero(v);
}

CGLM_EXPORT
void
glmc_hvec3_one(hvec3 v) {
  glm_hvec3_one(v);
}

CGLM_EXPORT
void
glmc_hvec3_add(hvec3 a, hvec3 b, hvec3 dest) {
  glm_hvec3_add(a, b, dest);
}

CGLM_EXPORT
void
glmc_hvec3_adds(hvec3 v, int16_t s, hvec3 dest) {
  glm_hvec3_adds(v, s, dest);
}

CGLM_EXPORT
void
glmc_hvec3_sub(hvec3 a, hvec3 b, hvec3 dest) {
  glm_hvec3_sub(a, b, dest);
}

CGLM_EXPORT
void
glmc_hvec3_subs(hvec3 v, int16_t s, hvec3 dest) {
  glm_hvec3_subs(v, s, dest);
}

CGLM_EXPORT
void
glmc_hvec3_mul(hvec3 a, hvec3 b, hvec3 dest) {
  glm_hvec3_mul(a, b, dest);
}

CGLM_EXPORT
void
glmc_hvec3_scale(hvec3 v, int16_t s, hvec3 dest) {
  glm_hvec3_scale(v, s, dest);
}

CGLM_EXPORT
int
glmc_hvec3_distance2(hvec3 a, hvec3 b) {
  return glm_hvec3_distance2(a, b);
}

CGLM_EXPORT
float
glmc_hvec3_distance(hvec3 a, hvec3 b) {
  return glm_hvec3_distance(a, b);
}

CGLM_EXPORT
void
glmc_hvec3_fill(hvec3 v, int16_t val) {
  glm_hvec3_fill(v, val);
}

CGLM_EXPORT
bool
glmc_hvec3_eq(hvec3 v, int16_t val) {
  return glm_hvec3_eq(v, val);
}

CGLM_EXPORT
bool
glmc_hvec3_eqv(hvec3 a, hvec3 b) {
  return glm_hvec3_eqv(a, b);
}

CGLM_EXPORT
void
glmc_hvec3_maxv(hvec3 a, hvec3 b, hvec3 dest) {
  glm_hvec3_maxv(a, b, dest);
}

CGLM_EXPORT
void
glmc_hvec3_minv(hvec3 a, hvec3 b, hvec3 dest) {
  glm_hvec3_minv(a, b, dest);
}

CGLM_EXPORT
void
glmc_hvec3_clamp(hvec3 v, int16_t minVal, int16_t maxVal) {
  glm_hvec3_clamp(v, minVal, maxVal);
}

CGLM_EXPORT
void
glmc_hvec3_abs(hvec3 v, hvec3 dest) {
  glm_hvec3_abs(v, dest);
}

