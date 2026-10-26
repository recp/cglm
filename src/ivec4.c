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
glmc_ivec4(const ivec3 v3, int last, ivec4 dest) {
  glm_ivec4(v3, last, dest);
}

CGLM_EXPORT
void
glmc_ivec4_copy(const ivec4 a, ivec4 dest) {
  glm_ivec4_copy(a, dest);
}

CGLM_EXPORT
void 
glmc_ivec4_zero(ivec4 v) {
  glm_ivec4_zero(v);
}

CGLM_EXPORT
void
glmc_ivec4_one(ivec4 v) {
  glm_ivec4_one(v);
}

CGLM_EXPORT
void
glmc_ivec4_add(const ivec4 a, const ivec4 b, ivec4 dest) {
  glm_ivec4_add(a, b, dest);
}

CGLM_EXPORT
void
glmc_ivec4_adds(const ivec4 v, int s, ivec4 dest) {
  glm_ivec4_adds(v, s, dest);
}

CGLM_EXPORT
void
glmc_ivec4_sub(const ivec4 a, const ivec4 b, ivec4 dest) {
  glm_ivec4_sub(a, b, dest);
}

CGLM_EXPORT
void
glmc_ivec4_subs(const ivec4 v, int s, ivec4 dest) {
  glm_ivec4_subs(v, s, dest);
}

CGLM_EXPORT
void
glmc_ivec4_mul(const ivec4 a, const ivec4 b, ivec4 dest) {
  glm_ivec4_mul(a, b, dest);
}

CGLM_EXPORT
void
glmc_ivec4_scale(const ivec4 v, int s, ivec4 dest) {
  glm_ivec4_scale(v, s, dest);
}

CGLM_EXPORT 
void 
glmc_ivec4_addadd(const ivec4 a, const ivec4 b, ivec4 dest) {
  glm_ivec4_addadd(a, b, dest);
}

CGLM_EXPORT 
void 
glmc_ivec4_addadds(const ivec4 a, int s, ivec4 dest) {
  glm_ivec4_addadds(a, s, dest);
}

CGLM_EXPORT 
void 
glmc_ivec4_subadd(const ivec4 a, const ivec4 b, ivec4 dest) {
  glm_ivec4_subadd(a, b, dest);
}

CGLM_EXPORT 
void 
glmc_ivec4_subadds(const ivec4 a, int s, ivec4 dest) {
  glm_ivec4_subadds(a, s, dest);
}

CGLM_EXPORT 
void 
glmc_ivec4_muladd(const ivec4 a, const ivec4 b, ivec4 dest) {
  glm_ivec4_muladd(a, b, dest);
}

CGLM_EXPORT 
void 
glmc_ivec4_muladds(const ivec4 a, int s, ivec4 dest) {
  glm_ivec4_muladds(a, s, dest);
}

CGLM_EXPORT 
void 
glmc_ivec4_maxadd(const ivec4 a, const ivec4 b, ivec4 dest) {
  glm_ivec4_maxadd(a, b, dest);
}

CGLM_EXPORT 
void 
glmc_ivec4_minadd(const ivec4 a, const ivec4 b, ivec4 dest) {
  glm_ivec4_minadd(a, b, dest);
}

CGLM_EXPORT 
void 
glmc_ivec4_subsub(const ivec4 a, const ivec4 b, ivec4 dest) {
  glm_ivec4_subsub(a, b, dest);
}

CGLM_EXPORT 
void 
glmc_ivec4_subsubs(const ivec4 a, int s, ivec4 dest) {
  glm_ivec4_subsubs(a, s, dest);
}

CGLM_EXPORT 
void 
glmc_ivec4_addsub(const ivec4 a, const ivec4 b, ivec4 dest) {
  glm_ivec4_addsub(a, b, dest);
}

CGLM_EXPORT 
void 
glmc_ivec4_addsubs(const ivec4 a, int s, ivec4 dest) {
  glm_ivec4_addsubs(a, s, dest);
}

CGLM_EXPORT 
void 
glmc_ivec4_mulsub(const ivec4 a, const ivec4 b, ivec4 dest) {
  glm_ivec4_mulsub(a, b, dest);
}

CGLM_EXPORT 
void 
glmc_ivec4_mulsubs(const ivec4 a, int s, ivec4 dest) {
  glm_ivec4_mulsubs(a, s, dest);
}

CGLM_EXPORT 
void 
glmc_ivec4_maxsub(const ivec4 a, const ivec4 b, ivec4 dest) {
  glm_ivec4_maxsub(a, b, dest);
}

CGLM_EXPORT 
void 
glmc_ivec4_minsub(const ivec4 a, const ivec4 b, ivec4 dest) {
  glm_ivec4_minsub(a, b, dest);
}

CGLM_EXPORT
int
glmc_ivec4_distance2(const ivec4 a, const ivec4 b) {
  return glm_ivec4_distance2(a, b);
}

CGLM_EXPORT
float
glmc_ivec4_distance(const ivec4 a, const ivec4 b) {
  return glm_ivec4_distance(a, b);
}

CGLM_EXPORT
void
glmc_ivec4_maxv(const ivec4 a, const ivec4 b, ivec4 dest) {
  glm_ivec4_maxv(a, b, dest);
}

CGLM_EXPORT
void
glmc_ivec4_minv(const ivec4 a, const ivec4 b, ivec4 dest) {
  glm_ivec4_minv(a, b, dest);
}

CGLM_EXPORT
void
glmc_ivec4_clamp(ivec4 v, int minVal, int maxVal) {
  glm_ivec4_clamp(v, minVal, maxVal);
}

CGLM_EXPORT
void
glmc_ivec4_abs(const ivec4 v, ivec4 dest) {
  glm_ivec4_abs(v, dest);
}
