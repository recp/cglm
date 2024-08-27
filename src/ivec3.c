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
glmc_ivec3(ivec4 v4, ivec3 dest) {
  glm_ivec3(v4, dest);
}

CGLM_EXPORT
void
glmc_ivec3_copy(ivec3 a, ivec3 dest) {
  glm_ivec3_copy(a, dest);
}

CGLM_EXPORT
void 
glmc_ivec3_zero(ivec3 v) {
  glm_ivec3_zero(v);
}

CGLM_EXPORT
void
glmc_ivec3_one(ivec3 v) {
  glm_ivec3_one(v);
}

CGLM_EXPORT
int
glmc_ivec3_dot(ivec3 a, ivec3 b) {
  return glm_ivec3_dot(a, b);
}

CGLM_EXPORT
int
glmc_ivec3_norm2(ivec3 v) {
  return glm_ivec3_norm2(v);
}

CGLM_EXPORT
int
glmc_ivec3_norm(ivec3 v) {
  return glm_ivec3_norm(v);
}

CGLM_EXPORT
void
glmc_ivec3_add(ivec3 a, ivec3 b, ivec3 dest) {
  glm_ivec3_add(a, b, dest);
}

CGLM_EXPORT
void
glmc_ivec3_adds(ivec3 v, int s, ivec3 dest) {
  glm_ivec3_adds(v, s, dest);
}

CGLM_EXPORT
void
glmc_ivec3_sub(ivec3 a, ivec3 b, ivec3 dest) {
  glm_ivec3_sub(a, b, dest);
}

CGLM_EXPORT
void
glmc_ivec3_subs(ivec3 v, int s, ivec3 dest) {
  glm_ivec3_subs(v, s, dest);
}

CGLM_EXPORT
void
glmc_ivec3_mul(ivec3 a, ivec3 b, ivec3 dest) {
  glm_ivec3_mul(a, b, dest);
}

CGLM_EXPORT
void
glmc_ivec3_scale(ivec3 v, int s, ivec3 dest) {
  glm_ivec3_scale(v, s, dest);
}

CGLM_EXPORT
void
glmc_ivec3_div(ivec3 a, ivec3 b, ivec3 dest) {
  glm_ivec3_div(a, b, dest);
}

CGLM_EXPORT
void
glmc_ivec3_divs(ivec3 v, int s, ivec3 dest) {
  glm_ivec3_divs(v, s, dest);
}

CGLM_EXPORT
void
glmc_ivec3_mod(ivec3 a, ivec3 b, ivec3 dest) {
  glm_ivec3_mod(a, b, dest);
}

CGLM_EXPORT 
void 
glmc_ivec3_addadd(ivec3 a, ivec3 b, ivec3 dest) {
  glm_ivec3_addadd(a, b, dest);
}

CGLM_EXPORT 
void 
glmc_ivec3_addadds(ivec3 a, int s, ivec3 dest) {
  glm_ivec3_addadds(a, s, dest);
}

CGLM_EXPORT 
void 
glmc_ivec3_subadd(ivec3 a, ivec3 b, ivec3 dest) {
  glm_ivec3_subadd(a, b, dest);
}

CGLM_EXPORT 
void 
glmc_ivec3_subadds(ivec3 a, int s, ivec3 dest) {
  glm_ivec3_subadds(a, s, dest);
}

CGLM_EXPORT 
void 
glmc_ivec3_muladd(ivec3 a, ivec3 b, ivec3 dest) {
  glm_ivec3_muladd(a, b, dest);
}

CGLM_EXPORT 
void 
glmc_ivec3_muladds(ivec3 a, int s, ivec3 dest) {
  glm_ivec3_muladds(a, s, dest);
}

CGLM_EXPORT 
void 
glmc_ivec3_maxadd(ivec3 a, ivec3 b, ivec3 dest) {
  glm_ivec3_maxadd(a, b, dest);
}

CGLM_EXPORT 
void 
glmc_ivec3_minadd(ivec3 a, ivec3 b, ivec3 dest) {
  glm_ivec3_minadd(a, b, dest);
}

CGLM_EXPORT 
void 
glmc_ivec3_subsub(ivec3 a, ivec3 b, ivec3 dest) {
  glm_ivec3_subsub(a, b, dest);
}

CGLM_EXPORT 
void 
glmc_ivec3_subsubs(ivec3 a, int s, ivec3 dest) {
  glm_ivec3_subsubs(a, s, dest);
}

CGLM_EXPORT 
void 
glmc_ivec3_addsub(ivec3 a, ivec3 b, ivec3 dest) {
  glm_ivec3_addsub(a, b, dest);
}

CGLM_EXPORT 
void 
glmc_ivec3_addsubs(ivec3 a, int s, ivec3 dest) {
  glm_ivec3_addsubs(a, s, dest);
}

CGLM_EXPORT 
void 
glmc_ivec3_mulsub(ivec3 a, ivec3 b, ivec3 dest) {
  glm_ivec3_mulsub(a, b, dest);
}

CGLM_EXPORT 
void 
glmc_ivec3_mulsubs(ivec3 a, int s, ivec3 dest) {
  glm_ivec3_mulsubs(a, s, dest);
}

CGLM_EXPORT 
void 
glmc_ivec3_maxsub(ivec3 a, ivec3 b, ivec3 dest) {
  glm_ivec3_maxsub(a, b, dest);
}

CGLM_EXPORT 
void 
glmc_ivec3_minsub(ivec3 a, ivec3 b, ivec3 dest) {
  glm_ivec3_minsub(a, b, dest);
}

CGLM_EXPORT
int
glmc_ivec3_distance2(ivec3 a, ivec3 b) {
  return glm_ivec3_distance2(a, b);
}

CGLM_EXPORT
float
glmc_ivec3_distance(ivec3 a, ivec3 b) {
  return glm_ivec3_distance(a, b);
}

CGLM_EXPORT
void
glmc_ivec3_fill(ivec3 v, int val) {
  glm_ivec3_fill(v, val);
}

CGLM_EXPORT
bool
glmc_ivec3_eq(ivec3 v, int val) {
  return glm_ivec3_eq(v, val);
}

CGLM_EXPORT
bool
glmc_ivec3_eqv(ivec3 a, ivec3 b) {
  return glm_ivec3_eqv(a, b);
}

CGLM_EXPORT
void
glmc_ivec3_maxv(ivec3 a, ivec3 b, ivec3 dest) {
  glm_ivec3_maxv(a, b, dest);
}

CGLM_EXPORT
void
glmc_ivec3_minv(ivec3 a, ivec3 b, ivec3 dest) {
  glm_ivec3_minv(a, b, dest);
}

CGLM_EXPORT
void
glmc_ivec3_clamp(ivec3 v, int minVal, int maxVal) {
  glm_ivec3_clamp(v, minVal, maxVal);
}

CGLM_EXPORT
void
glmc_ivec3_abs(ivec3 v, ivec3 dest) {
  glm_ivec3_abs(v, dest);
}
