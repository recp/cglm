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
glmc_uvec2(uint32_t * __restrict v, uvec2 dest) {
  glm_uvec2(v, dest);
}

CGLM_EXPORT
void
glmc_uvec2_copy(uvec2 a, uvec2 dest) {
  glm_uvec2_copy(a, dest);
}

CGLM_EXPORT
void
glmc_uvec2_zero(uvec2 v) {
  glm_uvec2_zero(v);
}

CGLM_EXPORT
void
glmc_uvec2_one(uvec2 v) {
  glm_uvec2_one(v);
}

CGLM_EXPORT
void
glmc_uvec2_add(uvec2 a, uvec2 b, uvec2 dest) {
  glm_uvec2_add(a, b, dest);
}

CGLM_EXPORT
void
glmc_uvec2_adds(uvec2 v, uint32_t s, uvec2 dest) {
  glm_uvec2_adds(v, s, dest);
}

CGLM_EXPORT
void
glmc_uvec2_sub(uvec2 a, uvec2 b, uvec2 dest) {
  glm_uvec2_sub(a, b, dest);
}

CGLM_EXPORT
void
glmc_uvec2_subs(uvec2 v, uint32_t s, uvec2 dest) {
  glm_uvec2_subs(v, s, dest);
}

CGLM_EXPORT
void
glmc_uvec2_mul(uvec2 a, uvec2 b, uvec2 dest) {
  glm_uvec2_mul(a, b, dest);
}

CGLM_EXPORT
void
glmc_uvec2_scale(uvec2 v, uint32_t s, uvec2 dest) {
  glm_uvec2_scale(v, s, dest);
}

CGLM_EXPORT
int
glmc_uvec2_distance2(uvec2 a, uvec2 b) {
  return glm_uvec2_distance2(a, b);
}

CGLM_EXPORT
float
glmc_uvec2_distance(uvec2 a, uvec2 b) {
  return glm_uvec2_distance(a, b);
}

CGLM_EXPORT
void
glmc_uvec2_fill(uvec2 v, uint32_t val) {
  glm_uvec2_fill(v, val);
}

CGLM_EXPORT
bool
glmc_uvec2_eq(uvec2 v, uint32_t val) {
  return glm_uvec2_eq(v, val);
}

CGLM_EXPORT
bool
glmc_uvec2_eqv(uvec2 a, uvec2 b) {
  return glm_uvec2_eqv(a, b);
}

CGLM_EXPORT
void
glmc_uvec2_maxv(uvec2 a, uvec2 b, uvec2 dest) {
  glm_uvec2_maxv(a, b, dest);
}

CGLM_EXPORT
void
glmc_uvec2_minv(uvec2 a, uvec2 b, uvec2 dest) {
  glm_uvec2_minv(a, b, dest);
}

CGLM_EXPORT
void
glmc_uvec2_clamp(uvec2 v, uint32_t minVal, uint32_t maxVal) {
  glm_uvec2_clamp(v, minVal, maxVal);
}

CGLM_EXPORT
void
glmc_uvec2_abs(uvec2 v, uvec2 dest) {
  glm_uvec2_abs(v, dest);
}

