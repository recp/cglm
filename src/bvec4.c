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
glmc_bvec4(bvec3 v3, int8_t last, bvec4 dest) {
  glm_bvec4(v3, last, dest);
}

CGLM_EXPORT
void
glmc_bvec4_copy(bvec4 a, bvec4 dest) {
  glm_bvec4_copy(a, dest);
}

CGLM_EXPORT
void 
glmc_bvec4_zero(bvec4 v) {
  glm_bvec4_zero(v);
}

CGLM_EXPORT
void
glmc_bvec4_one(bvec4 v) {
  glm_bvec4_one(v);
}

CGLM_EXPORT
void
glmc_bvec4_add(bvec4 a, bvec4 b, bvec4 dest) {
  glm_bvec4_add(a, b, dest);
}

CGLM_EXPORT
void
glmc_bvec4_adds(bvec4 v, int8_t s, bvec4 dest) {
  glm_bvec4_adds(v, s, dest);
}

CGLM_EXPORT
void
glmc_bvec4_sub(bvec4 a, bvec4 b, bvec4 dest) {
  glm_bvec4_sub(a, b, dest);
}

CGLM_EXPORT
void
glmc_bvec4_subs(bvec4 v, int8_t s, bvec4 dest) {
  glm_bvec4_subs(v, s, dest);
}

CGLM_EXPORT
void
glmc_bvec4_mul(bvec4 a, bvec4 b, bvec4 dest) {
  glm_bvec4_mul(a, b, dest);
}

CGLM_EXPORT
void
glmc_bvec4_scale(bvec4 v, int8_t s, bvec4 dest) {
  glm_bvec4_scale(v, s, dest);
}

CGLM_EXPORT
int
glmc_bvec4_distance2(bvec4 a, bvec4 b) {
  return glm_bvec4_distance2(a, b);
}

CGLM_EXPORT
float
glmc_bvec4_distance(bvec4 a, bvec4 b) {
  return glm_bvec4_distance(a, b);
}

CGLM_EXPORT
void
glmc_bvec4_maxv(bvec4 a, bvec4 b, bvec4 dest) {
  glm_bvec4_maxv(a, b, dest);
}

CGLM_EXPORT
void
glmc_bvec4_minv(bvec4 a, bvec4 b, bvec4 dest) {
  glm_bvec4_minv(a, b, dest);
}

CGLM_EXPORT
void
glmc_bvec4_clamp(bvec4 v, int8_t minVal, int8_t maxVal) {
  glm_bvec4_clamp(v, minVal, maxVal);
}

CGLM_EXPORT
void
glmc_bvec4_abs(bvec4 v, bvec4 dest) {
  glm_bvec4_abs(v, dest);
}

