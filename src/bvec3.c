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
glmc_bvec3(bvec4 v4, bvec3 dest) {
  glm_bvec3(v4, dest);
}

CGLM_EXPORT
void
glmc_bvec3_copy(bvec3 a, bvec3 dest) {
  glm_bvec3_copy(a, dest);
}

CGLM_EXPORT
void 
glmc_bvec3_zero(bvec3 v) {
  glm_bvec3_zero(v);
}

CGLM_EXPORT
void
glmc_bvec3_one(bvec3 v) {
  glm_bvec3_one(v);
}

CGLM_EXPORT
void
glmc_bvec3_add(bvec3 a, bvec3 b, bvec3 dest) {
  glm_bvec3_add(a, b, dest);
}

CGLM_EXPORT
void
glmc_bvec3_adds(bvec3 v, int8_t s, bvec3 dest) {
  glm_bvec3_adds(v, s, dest);
}

CGLM_EXPORT
void
glmc_bvec3_sub(bvec3 a, bvec3 b, bvec3 dest) {
  glm_bvec3_sub(a, b, dest);
}

CGLM_EXPORT
void
glmc_bvec3_subs(bvec3 v, int8_t s, bvec3 dest) {
  glm_bvec3_subs(v, s, dest);
}

CGLM_EXPORT
void
glmc_bvec3_mul(bvec3 a, bvec3 b, bvec3 dest) {
  glm_bvec3_mul(a, b, dest);
}

CGLM_EXPORT
void
glmc_bvec3_scale(bvec3 v, int8_t s, bvec3 dest) {
  glm_bvec3_scale(v, s, dest);
}

CGLM_EXPORT
int
glmc_bvec3_distance2(bvec3 a, bvec3 b) {
  return glm_bvec3_distance2(a, b);
}

CGLM_EXPORT
float
glmc_bvec3_distance(bvec3 a, bvec3 b) {
  return glm_bvec3_distance(a, b);
}

CGLM_EXPORT
void
glmc_bvec3_fill(bvec3 v, int8_t val) {
  glm_bvec3_fill(v, val);
}

CGLM_EXPORT
bool
glmc_bvec3_eq(bvec3 v, int8_t val) {
  return glm_bvec3_eq(v, val);
}

CGLM_EXPORT
bool
glmc_bvec3_eqv(bvec3 a, bvec3 b) {
  return glm_bvec3_eqv(a, b);
}

CGLM_EXPORT
void
glmc_bvec3_maxv(bvec3 a, bvec3 b, bvec3 dest) {
  glm_bvec3_maxv(a, b, dest);
}

CGLM_EXPORT
void
glmc_bvec3_minv(bvec3 a, bvec3 b, bvec3 dest) {
  glm_bvec3_minv(a, b, dest);
}

CGLM_EXPORT
void
glmc_bvec3_clamp(bvec3 v, int8_t minVal, int8_t maxVal) {
  glm_bvec3_clamp(v, minVal, maxVal);
}

CGLM_EXPORT
void
glmc_bvec3_abs(bvec3 v, bvec3 dest) {
  glm_bvec3_abs(v, dest);
}

