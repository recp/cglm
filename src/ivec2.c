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
glmc_ivec2(int * __restrict v, ivec2 dest) {
  glm_ivec2(v, dest);
}

CGLM_EXPORT
void
glmc_ivec2_copy(ivec2 a, ivec2 dest) {
  glm_ivec2_copy(a, dest);
}

CGLM_EXPORT
void
glmc_ivec2_zero(ivec2 v) {
  glm_ivec2_zero(v);
}

CGLM_EXPORT
void
glmc_ivec2_one(ivec2 v) {
  glm_ivec2_one(v);
}

CGLM_EXPORT
int
glmc_ivec2_dot(ivec2 a, ivec2 b) {
  return glm_ivec2_dot(a, b);
}

CGLM_EXPORT
int
glmc_ivec2_cross(ivec2 a, ivec2 b) {
  return glm_ivec2_cross(a, b);
}

CGLM_EXPORT
void
glmc_ivec2_add(ivec2 a, ivec2 b, ivec2 dest) {
  glm_ivec2_add(a, b, dest);
}

CGLM_EXPORT
void
glmc_ivec2_adds(ivec2 v, int s, ivec2 dest) {
  glm_ivec2_adds(v, s, dest);
}

CGLM_EXPORT
void
glmc_ivec2_sub(ivec2 a, ivec2 b, ivec2 dest) {
  glm_ivec2_sub(a, b, dest);
}

CGLM_EXPORT
void
glmc_ivec2_subs(ivec2 v, int s, ivec2 dest) {
  glm_ivec2_subs(v, s, dest);
}

CGLM_EXPORT
void
glmc_ivec2_mul(ivec2 a, ivec2 b, ivec2 dest) {
  glm_ivec2_mul(a, b, dest);
}

CGLM_EXPORT
void
glmc_ivec2_scale(ivec2 v, int s, ivec2 dest) {
  glm_ivec2_scale(v, s, dest);
}

CGLM_EXPORT
void
glmc_ivec2_div(ivec2 a, ivec2 b, ivec2 dest) {
  glm_ivec2_div(a, b, dest);
}

CGLM_EXPORT
void
glmc_ivec2_divs(ivec2 v, int s, ivec2 dest) {
  glm_ivec2_divs(v, s, dest);
}

CGLM_EXPORT
void
glmc_ivec2_mod(ivec2 a, ivec2 b, ivec2 dest) {
  glm_ivec2_mod(a, b, dest);
}

CGLM_EXPORT
void
glmc_ivec2_addadd(ivec2 a, ivec2 b, ivec2 dest) {
  glm_ivec2_addadd(a, b, dest);
}

CGLM_EXPORT
void
glmc_ivec2_addadds(ivec2 a, int s, ivec2 dest) {
  glm_ivec2_addadds(a, s, dest);
}

CGLM_EXPORT
void
glmc_ivec2_subadd(ivec2 a, ivec2 b, ivec2 dest) {
  glm_ivec2_subadd(a, b, dest);
}

CGLM_EXPORT
void
glmc_ivec2_subadds(ivec2 a, int s, ivec2 dest) {
  glm_ivec2_subadds(a, s, dest);
}

CGLM_EXPORT
void
glmc_ivec2_muladd(ivec2 a, ivec2 b, ivec2 dest) {
  glm_ivec2_muladd(a, b, dest);
}

CGLM_EXPORT
void
glmc_ivec2_muladds(ivec2 a, int s, ivec2 dest) {
  glm_ivec2_muladds(a, s, dest);
}

CGLM_EXPORT
void
glmc_ivec2_maxadd(ivec2 a, ivec2 b, ivec2 dest) {
  glm_ivec2_maxadd(a, b, dest);
}

CGLM_EXPORT
void
glmc_ivec2_minadd(ivec2 a, ivec2 b, ivec2 dest) {
  glm_ivec2_minadd(a, b, dest);
}

CGLM_EXPORT
void
glmc_ivec2_subsub(ivec2 a, ivec2 b, ivec2 dest) {
  glm_ivec2_subsub(a, b, dest);
}

CGLM_EXPORT
void
glmc_ivec2_subsubs(ivec2 a, int s, ivec2 dest) {
  glm_ivec2_subsubs(a, s, dest);
}

CGLM_EXPORT
void
glmc_ivec2_addsub(ivec2 a, ivec2 b, ivec2 dest) {
  glm_ivec2_addsub(a, b, dest);
}

CGLM_EXPORT
void
glmc_ivec2_addsubs(ivec2 a, int s, ivec2 dest) {
  glm_ivec2_addsubs(a, s, dest);
}

CGLM_EXPORT
void
glmc_ivec2_mulsub(ivec2 a, ivec2 b, ivec2 dest) {
  glm_ivec2_mulsub(a, b, dest);
}

CGLM_EXPORT
void
glmc_ivec2_mulsubs(ivec2 a, int s, ivec2 dest) {
  glm_ivec2_mulsubs(a, s, dest);
}

CGLM_EXPORT
void
glmc_ivec2_maxsub(ivec2 a, ivec2 b, ivec2 dest) {
  glm_ivec2_maxsub(a, b, dest);
}

CGLM_EXPORT
void
glmc_ivec2_minsub(ivec2 a, ivec2 b, ivec2 dest) {
  glm_ivec2_minsub(a, b, dest);
}

CGLM_EXPORT
int
glmc_ivec2_distance2(ivec2 a, ivec2 b) {
  return glm_ivec2_distance2(a, b);
}

CGLM_EXPORT
float
glmc_ivec2_distance(ivec2 a, ivec2 b) {
  return glm_ivec2_distance(a, b);
}

CGLM_EXPORT
void
glmc_ivec2_fill(ivec2 v, int val) {
  glm_ivec2_fill(v, val);
}

CGLM_EXPORT
bool
glmc_ivec2_eq(ivec2 v, int val) {
  return glm_ivec2_eq(v, val);
}

CGLM_EXPORT
bool
glmc_ivec2_eqv(ivec2 a, ivec2 b) {
  return glm_ivec2_eqv(a, b);
}

CGLM_EXPORT
void
glmc_ivec2_maxv(ivec2 a, ivec2 b, ivec2 dest) {
  glm_ivec2_maxv(a, b, dest);
}

CGLM_EXPORT
void
glmc_ivec2_minv(ivec2 a, ivec2 b, ivec2 dest) {
  glm_ivec2_minv(a, b, dest);
}

CGLM_EXPORT
void
glmc_ivec2_clamp(ivec2 v, int minVal, int maxVal) {
  glm_ivec2_clamp(v, minVal, maxVal);
}

CGLM_EXPORT
void
glmc_ivec2_abs(ivec2 v, ivec2 dest) {
  glm_ivec2_abs(v, dest);
}

