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
glmc_uvec3(uvec4 v4, uvec3 dest) {
  glm_uvec3(v4, dest);
}

CGLM_EXPORT
void
glmc_uvec3_copy(uvec3 a, uvec3 dest) {
  glm_uvec3_copy(a, dest);
}

CGLM_EXPORT
void 
glmc_uvec3_zero(uvec3 v) {
  glm_uvec3_zero(v);
}

CGLM_EXPORT
void
glmc_uvec3_one(uvec3 v) {
  glm_uvec3_one(v);
}

CGLM_EXPORT
void
glmc_uvec3_add(uvec3 a, uvec3 b, uvec3 dest) {
  glm_uvec3_add(a, b, dest);
}

CGLM_EXPORT
void
glmc_uvec3_adds(uvec3 v, uint32_t s, uvec3 dest) {
  glm_uvec3_adds(v, s, dest);
}

CGLM_EXPORT
void
glmc_uvec3_sub(uvec3 a, uvec3 b, uvec3 dest) {
  glm_uvec3_sub(a, b, dest);
}

CGLM_EXPORT
void
glmc_uvec3_subs(uvec3 v, uint32_t s, uvec3 dest) {
  glm_uvec3_subs(v, s, dest);
}

CGLM_EXPORT
void
glmc_uvec3_mul(uvec3 a, uvec3 b, uvec3 dest) {
  glm_uvec3_mul(a, b, dest);
}

CGLM_EXPORT
void
glmc_uvec3_scale(uvec3 v, uint32_t s, uvec3 dest) {
  glm_uvec3_scale(v, s, dest);
}

CGLM_EXPORT
int
glmc_uvec3_distance2(uvec3 a, uvec3 b) {
  return glm_uvec3_distance2(a, b);
}

CGLM_EXPORT
float
glmc_uvec3_distance(uvec3 a, uvec3 b) {
  return glm_uvec3_distance(a, b);
}

CGLM_EXPORT
void
glmc_uvec3_fill(uvec3 v, uint32_t val) {
  glm_uvec3_fill(v, val);
}

CGLM_EXPORT
bool
glmc_uvec3_eq(uvec3 v, uint32_t val) {
  return glm_uvec3_eq(v, val);
}

CGLM_EXPORT
bool
glmc_uvec3_eqv(uvec3 a, uvec3 b) {
  return glm_uvec3_eqv(a, b);
}

CGLM_EXPORT
void
glmc_uvec3_maxv(uvec3 a, uvec3 b, uvec3 dest) {
  glm_uvec3_maxv(a, b, dest);
}

CGLM_EXPORT
void
glmc_uvec3_minv(uvec3 a, uvec3 b, uvec3 dest) {
  glm_uvec3_minv(a, b, dest);
}

CGLM_EXPORT
void
glmc_uvec3_clamp(uvec3 v, uint32_t minVal, uint32_t maxVal) {
  glm_uvec3_clamp(v, minVal, maxVal);
}

CGLM_EXPORT
void
glmc_uvec3_abs(uvec3 v, uvec3 dest) {
  glm_uvec3_abs(v, dest);
}

