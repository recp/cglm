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
glmc_uhvec4(uhvec3 v3, uint16_t last, uhvec4 dest) {
  glm_uhvec4(v3, last, dest);
}

CGLM_EXPORT
void
glmc_uhvec4_copy(uhvec4 a, uhvec4 dest) {
  glm_uhvec4_copy(a, dest);
}

CGLM_EXPORT
void 
glmc_uhvec4_zero(uhvec4 v) {
  glm_uhvec4_zero(v);
}

CGLM_EXPORT
void
glmc_uhvec4_one(uhvec4 v) {
  glm_uhvec4_one(v);
}

CGLM_EXPORT
void
glmc_uhvec4_add(uhvec4 a, uhvec4 b, uhvec4 dest) {
  glm_uhvec4_add(a, b, dest);
}

CGLM_EXPORT
void
glmc_uhvec4_adds(uhvec4 v, uint16_t s, uhvec4 dest) {
  glm_uhvec4_adds(v, s, dest);
}

CGLM_EXPORT
void
glmc_uhvec4_sub(uhvec4 a, uhvec4 b, uhvec4 dest) {
  glm_uhvec4_sub(a, b, dest);
}

CGLM_EXPORT
void
glmc_uhvec4_subs(uhvec4 v, uint16_t s, uhvec4 dest) {
  glm_uhvec4_subs(v, s, dest);
}

CGLM_EXPORT
void
glmc_uhvec4_mul(uhvec4 a, uhvec4 b, uhvec4 dest) {
  glm_uhvec4_mul(a, b, dest);
}

CGLM_EXPORT
void
glmc_uhvec4_scale(uhvec4 v, uint16_t s, uhvec4 dest) {
  glm_uhvec4_scale(v, s, dest);
}

CGLM_EXPORT
int
glmc_uhvec4_distance2(uhvec4 a, uhvec4 b) {
  return glm_uhvec4_distance2(a, b);
}

CGLM_EXPORT
float
glmc_uhvec4_distance(uhvec4 a, uhvec4 b) {
  return glm_uhvec4_distance(a, b);
}

CGLM_EXPORT
void
glmc_uhvec4_maxv(uhvec4 a, uhvec4 b, uhvec4 dest) {
  glm_uhvec4_maxv(a, b, dest);
}

CGLM_EXPORT
void
glmc_uhvec4_minv(uhvec4 a, uhvec4 b, uhvec4 dest) {
  glm_uhvec4_minv(a, b, dest);
}

CGLM_EXPORT
void
glmc_uhvec4_clamp(uhvec4 v, uint16_t minVal, uint16_t maxVal) {
  glm_uhvec4_clamp(v, minVal, maxVal);
}

CGLM_EXPORT
void
glmc_uhvec4_abs(uhvec4 v, uhvec4 dest) {
  glm_uhvec4_abs(v, dest);
}

