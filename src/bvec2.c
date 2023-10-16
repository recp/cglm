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
glmc_bvec2(int8_t * __restrict v, bvec2 dest) {
  glm_bvec2(v, dest);
}

CGLM_EXPORT
void
glmc_bvec2_copy(bvec2 a, bvec2 dest) {
  glm_bvec2_copy(a, dest);
}

CGLM_EXPORT
void
glmc_bvec2_zero(bvec2 v) {
  glm_bvec2_zero(v);
}

CGLM_EXPORT
void
glmc_bvec2_one(bvec2 v) {
  glm_bvec2_one(v);
}

CGLM_EXPORT
void
glmc_bvec2_add(bvec2 a, bvec2 b, bvec2 dest) {
  glm_bvec2_add(a, b, dest);
}

CGLM_EXPORT
void
glmc_bvec2_adds(bvec2 v, int8_t s, bvec2 dest) {
  glm_bvec2_adds(v, s, dest);
}

CGLM_EXPORT
void
glmc_bvec2_sub(bvec2 a, bvec2 b, bvec2 dest) {
  glm_bvec2_sub(a, b, dest);
}

CGLM_EXPORT
void
glmc_bvec2_subs(bvec2 v, int8_t s, bvec2 dest) {
  glm_bvec2_subs(v, s, dest);
}

CGLM_EXPORT
void
glmc_bvec2_mul(bvec2 a, bvec2 b, bvec2 dest) {
  glm_bvec2_mul(a, b, dest);
}

CGLM_EXPORT
void
glmc_bvec2_scale(bvec2 v, int8_t s, bvec2 dest) {
  glm_bvec2_scale(v, s, dest);
}

CGLM_EXPORT
int
glmc_bvec2_distance2(bvec2 a, bvec2 b) {
  return glm_bvec2_distance2(a, b);
}

CGLM_EXPORT
float
glmc_bvec2_distance(bvec2 a, bvec2 b) {
  return glm_bvec2_distance(a, b);
}

CGLM_EXPORT
void
glmc_bvec2_fill(bvec2 v, int8_t val) {
  glm_bvec2_fill(v, val);
}

CGLM_EXPORT
bool
glmc_bvec2_eq(bvec2 v, int8_t val) {
  return glm_bvec2_eq(v, val);
}

CGLM_EXPORT
bool
glmc_bvec2_eqv(bvec2 a, bvec2 b) {
  return glm_bvec2_eqv(a, b);
}

CGLM_EXPORT
void
glmc_bvec2_maxv(bvec2 a, bvec2 b, bvec2 dest) {
  glm_bvec2_maxv(a, b, dest);
}

CGLM_EXPORT
void
glmc_bvec2_minv(bvec2 a, bvec2 b, bvec2 dest) {
  glm_bvec2_minv(a, b, dest);
}

CGLM_EXPORT
void
glmc_bvec2_clamp(bvec2 v, int8_t minVal, int8_t maxVal) {
  glm_bvec2_clamp(v, minVal, maxVal);
}

CGLM_EXPORT
void
glmc_bvec2_abs(bvec2 v, bvec2 dest) {
  glm_bvec2_abs(v, dest);
}

