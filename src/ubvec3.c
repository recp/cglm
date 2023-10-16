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
glmc_ubvec3(ubvec4 v4, ubvec3 dest) {
  glm_ubvec3(v4, dest);
}

CGLM_EXPORT
void
glmc_ubvec3_copy(ubvec3 a, ubvec3 dest) {
  glm_ubvec3_copy(a, dest);
}

CGLM_EXPORT
void 
glmc_ubvec3_zero(ubvec3 v) {
  glm_ubvec3_zero(v);
}

CGLM_EXPORT
void
glmc_ubvec3_one(ubvec3 v) {
  glm_ubvec3_one(v);
}

CGLM_EXPORT
void
glmc_ubvec3_add(ubvec3 a, ubvec3 b, ubvec3 dest) {
  glm_ubvec3_add(a, b, dest);
}

CGLM_EXPORT
void
glmc_ubvec3_adds(ubvec3 v, uint8_t s, ubvec3 dest) {
  glm_ubvec3_adds(v, s, dest);
}

CGLM_EXPORT
void
glmc_ubvec3_sub(ubvec3 a, ubvec3 b, ubvec3 dest) {
  glm_ubvec3_sub(a, b, dest);
}

CGLM_EXPORT
void
glmc_ubvec3_subs(ubvec3 v, uint8_t s, ubvec3 dest) {
  glm_ubvec3_subs(v, s, dest);
}

CGLM_EXPORT
void
glmc_ubvec3_mul(ubvec3 a, ubvec3 b, ubvec3 dest) {
  glm_ubvec3_mul(a, b, dest);
}

CGLM_EXPORT
void
glmc_ubvec3_scale(ubvec3 v, uint8_t s, ubvec3 dest) {
  glm_ubvec3_scale(v, s, dest);
}

CGLM_EXPORT
int
glmc_ubvec3_distance2(ubvec3 a, ubvec3 b) {
  return glm_ubvec3_distance2(a, b);
}

CGLM_EXPORT
float
glmc_ubvec3_distance(ubvec3 a, ubvec3 b) {
  return glm_ubvec3_distance(a, b);
}

CGLM_EXPORT
void
glmc_ubvec3_fill(ubvec3 v, uint8_t val) {
  glm_ubvec3_fill(v, val);
}

CGLM_EXPORT
bool
glmc_ubvec3_eq(ubvec3 v, uint8_t val) {
  return glm_ubvec3_eq(v, val);
}

CGLM_EXPORT
bool
glmc_ubvec3_eqv(ubvec3 a, ubvec3 b) {
  return glm_ubvec3_eqv(a, b);
}

CGLM_EXPORT
void
glmc_ubvec3_maxv(ubvec3 a, ubvec3 b, ubvec3 dest) {
  glm_ubvec3_maxv(a, b, dest);
}

CGLM_EXPORT
void
glmc_ubvec3_minv(ubvec3 a, ubvec3 b, ubvec3 dest) {
  glm_ubvec3_minv(a, b, dest);
}

CGLM_EXPORT
void
glmc_ubvec3_clamp(ubvec3 v, uint8_t minVal, uint8_t maxVal) {
  glm_ubvec3_clamp(v, minVal, maxVal);
}

CGLM_EXPORT
void
glmc_ubvec3_abs(ubvec3 v, ubvec3 dest) {
  glm_ubvec3_abs(v, dest);
}

