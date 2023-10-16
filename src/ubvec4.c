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
glmc_ubvec4(ubvec3 v3, uint8_t last, ubvec4 dest) {
  glm_ubvec4(v3, last, dest);
}

CGLM_EXPORT
void
glmc_ubvec4_copy(ubvec4 a, ubvec4 dest) {
  glm_ubvec4_copy(a, dest);
}

CGLM_EXPORT
void 
glmc_ubvec4_zero(ubvec4 v) {
  glm_ubvec4_zero(v);
}

CGLM_EXPORT
void
glmc_ubvec4_one(ubvec4 v) {
  glm_ubvec4_one(v);
}

CGLM_EXPORT
void
glmc_ubvec4_add(ubvec4 a, ubvec4 b, ubvec4 dest) {
  glm_ubvec4_add(a, b, dest);
}

CGLM_EXPORT
void
glmc_ubvec4_adds(ubvec4 v, uint8_t s, ubvec4 dest) {
  glm_ubvec4_adds(v, s, dest);
}

CGLM_EXPORT
void
glmc_ubvec4_sub(ubvec4 a, ubvec4 b, ubvec4 dest) {
  glm_ubvec4_sub(a, b, dest);
}

CGLM_EXPORT
void
glmc_ubvec4_subs(ubvec4 v, uint8_t s, ubvec4 dest) {
  glm_ubvec4_subs(v, s, dest);
}

CGLM_EXPORT
void
glmc_ubvec4_mul(ubvec4 a, ubvec4 b, ubvec4 dest) {
  glm_ubvec4_mul(a, b, dest);
}

CGLM_EXPORT
void
glmc_ubvec4_scale(ubvec4 v, uint8_t s, ubvec4 dest) {
  glm_ubvec4_scale(v, s, dest);
}

CGLM_EXPORT
int
glmc_ubvec4_distance2(ubvec4 a, ubvec4 b) {
  return glm_ubvec4_distance2(a, b);
}

CGLM_EXPORT
float
glmc_ubvec4_distance(ubvec4 a, ubvec4 b) {
  return glm_ubvec4_distance(a, b);
}

CGLM_EXPORT
void
glmc_ubvec4_maxv(ubvec4 a, ubvec4 b, ubvec4 dest) {
  glm_ubvec4_maxv(a, b, dest);
}

CGLM_EXPORT
void
glmc_ubvec4_minv(ubvec4 a, ubvec4 b, ubvec4 dest) {
  glm_ubvec4_minv(a, b, dest);
}

CGLM_EXPORT
void
glmc_ubvec4_clamp(ubvec4 v, uint8_t minVal, uint8_t maxVal) {
  glm_ubvec4_clamp(v, minVal, maxVal);
}

CGLM_EXPORT
void
glmc_ubvec4_abs(ubvec4 v, ubvec4 dest) {
  glm_ubvec4_abs(v, dest);
}

