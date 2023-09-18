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
glmc_uhvec2(uint16_t * __restrict v, uhvec2 dest) {
  glm_uhvec2(v, dest);
}

CGLM_EXPORT
void
glmc_uhvec2_copy(uhvec2 a, uhvec2 dest) {
  glm_uhvec2_copy(a, dest);
}

CGLM_EXPORT
void
glmc_uhvec2_zero(uhvec2 v) {
  glm_uhvec2_zero(v);
}

CGLM_EXPORT
void
glmc_uhvec2_one(uhvec2 v) {
  glm_uhvec2_one(v);
}

CGLM_EXPORT
void
glmc_uhvec2_add(uhvec2 a, uhvec2 b, uhvec2 dest) {
  glm_uhvec2_add(a, b, dest);
}

CGLM_EXPORT
void
glmc_uhvec2_adds(uhvec2 v, uint16_t s, uhvec2 dest) {
  glm_uhvec2_adds(v, s, dest);
}

CGLM_EXPORT
void
glmc_uhvec2_sub(uhvec2 a, uhvec2 b, uhvec2 dest) {
  glm_uhvec2_sub(a, b, dest);
}

CGLM_EXPORT
void
glmc_uhvec2_subs(uhvec2 v, uint16_t s, uhvec2 dest) {
  glm_uhvec2_subs(v, s, dest);
}

CGLM_EXPORT
void
glmc_uhvec2_mul(uhvec2 a, uhvec2 b, uhvec2 dest) {
  glm_uhvec2_mul(a, b, dest);
}

CGLM_EXPORT
void
glmc_uhvec2_scale(uhvec2 v, uint16_t s, uhvec2 dest) {
  glm_uhvec2_scale(v, s, dest);
}

CGLM_EXPORT
int
glmc_uhvec2_distance2(uhvec2 a, uhvec2 b) {
  return glm_uhvec2_distance2(a, b);
}

CGLM_EXPORT
float
glmc_uhvec2_distance(uhvec2 a, uhvec2 b) {
  return glm_uhvec2_distance(a, b);
}

CGLM_EXPORT
void
glmc_uhvec2_fill(uhvec2 v, uint16_t val) {
  glm_uhvec2_fill(v, val);
}

CGLM_EXPORT
bool
glmc_uhvec2_eq(uhvec2 v, uint16_t val) {
  return glm_uhvec2_eq(v, val);
}

CGLM_EXPORT
bool
glmc_uhvec2_eqv(uhvec2 a, uhvec2 b) {
  return glm_uhvec2_eqv(a, b);
}

CGLM_EXPORT
void
glmc_uhvec2_maxv(uhvec2 a, uhvec2 b, uhvec2 dest) {
  glm_uhvec2_maxv(a, b, dest);
}

CGLM_EXPORT
void
glmc_uhvec2_minv(uhvec2 a, uhvec2 b, uhvec2 dest) {
  glm_uhvec2_minv(a, b, dest);
}

CGLM_EXPORT
void
glmc_uhvec2_clamp(uhvec2 v, uint16_t minVal, uint16_t maxVal) {
  glm_uhvec2_clamp(v, minVal, maxVal);
}

CGLM_EXPORT
void
glmc_uhvec2_abs(uhvec2 v, uhvec2 dest) {
  glm_uhvec2_abs(v, dest);
}

