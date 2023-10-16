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
glmc_uvec4(uvec3 v3, uint32_t last, uvec4 dest) {
  glm_uvec4(v3, last, dest);
}

CGLM_EXPORT
void
glmc_uvec4_copy(uvec4 a, uvec4 dest) {
  glm_uvec4_copy(a, dest);
}

CGLM_EXPORT
void 
glmc_uvec4_zero(uvec4 v) {
  glm_uvec4_zero(v);
}

CGLM_EXPORT
void
glmc_uvec4_one(uvec4 v) {
  glm_uvec4_one(v);
}

CGLM_EXPORT
void
glmc_uvec4_add(uvec4 a, uvec4 b, uvec4 dest) {
  glm_uvec4_add(a, b, dest);
}

CGLM_EXPORT
void
glmc_uvec4_adds(uvec4 v, uint32_t s, uvec4 dest) {
  glm_uvec4_adds(v, s, dest);
}

CGLM_EXPORT
void
glmc_uvec4_sub(uvec4 a, uvec4 b, uvec4 dest) {
  glm_uvec4_sub(a, b, dest);
}

CGLM_EXPORT
void
glmc_uvec4_subs(uvec4 v, uint32_t s, uvec4 dest) {
  glm_uvec4_subs(v, s, dest);
}

CGLM_EXPORT
void
glmc_uvec4_mul(uvec4 a, uvec4 b, uvec4 dest) {
  glm_uvec4_mul(a, b, dest);
}

CGLM_EXPORT
void
glmc_uvec4_scale(uvec4 v, uint32_t s, uvec4 dest) {
  glm_uvec4_scale(v, s, dest);
}

CGLM_EXPORT
int
glmc_uvec4_distance2(uvec4 a, uvec4 b) {
  return glm_uvec4_distance2(a, b);
}

CGLM_EXPORT
float
glmc_uvec4_distance(uvec4 a, uvec4 b) {
  return glm_uvec4_distance(a, b);
}

CGLM_EXPORT
void
glmc_uvec4_maxv(uvec4 a, uvec4 b, uvec4 dest) {
  glm_uvec4_maxv(a, b, dest);
}

CGLM_EXPORT
void
glmc_uvec4_minv(uvec4 a, uvec4 b, uvec4 dest) {
  glm_uvec4_minv(a, b, dest);
}

CGLM_EXPORT
void
glmc_uvec4_clamp(uvec4 v, uint32_t minVal, uint32_t maxVal) {
  glm_uvec4_clamp(v, minVal, maxVal);
}

CGLM_EXPORT
void
glmc_uvec4_abs(uvec4 v, uvec4 dest) {
  glm_uvec4_abs(v, dest);
}

