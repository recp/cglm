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
glmc_vec2(float * __restrict v, vec2 dest) {
  glm_vec2(v, dest);
}

CGLM_EXPORT
void
glmc_vec2_fill(vec2 v, float val) {
  glm_vec2_fill(v, val);
}

CGLM_EXPORT
bool
glmc_vec2_eq(vec2 v, float val) {
  return glm_vec2_eq(v, val);
}

CGLM_EXPORT
bool
glmc_vec2_eqv(vec2 a, vec2 b) {
  return glm_vec2_eqv(a, b);
}

CGLM_EXPORT
void
glmc_vec2_copy(vec2 a, vec2 dest) {
  glm_vec2_copy(a, dest);
}

CGLM_EXPORT
void
glmc_vec2_zero(vec2 v) {
  glm_vec2_zero(v);
}

CGLM_EXPORT
void
glmc_vec2_one(vec2 v) {
  glm_vec2_one(v);
}

CGLM_EXPORT
float
glmc_vec2_dot(vec2 a, vec2 b) {
  return glm_vec2_dot(a, b);
}

CGLM_EXPORT
float
glmc_vec2_cross(vec2 a, vec2 b) {
  return glm_vec2_cross(a, b);
}

CGLM_EXPORT
float
glmc_vec2_norm2(vec2 v) {
  return glm_vec2_norm2(v);
}

CGLM_EXPORT
float
glmc_vec2_norm(vec2 v) {
  return glm_vec2_norm(v);
}

CGLM_EXPORT
void
glmc_vec2_add(vec2 a, vec2 b, vec2 dest) {
  glm_vec2_add(a, b, dest);
}

CGLM_EXPORT
void
glmc_vec2_adds(vec2 v, float s, vec2 dest) {
  glm_vec2_adds(v, s, dest);
}

CGLM_EXPORT
void
glmc_vec2_sub(vec2 a, vec2 b, vec2 dest) {
  glm_vec2_sub(a, b, dest);
}

CGLM_EXPORT
void
glmc_vec2_subs(vec2 v, float s, vec2 dest) {
  glm_vec2_subs(v, s, dest);
}

CGLM_EXPORT
void
glmc_vec2_mul(vec2 a, vec2 b, vec2 dest) {
  glm_vec2_mul(a, b, dest);
}

CGLM_EXPORT
void
glmc_vec2_scale(vec2 v, float s, vec2 dest) {
  glm_vec2_scale(v, s, dest);
}

CGLM_EXPORT
void
glmc_vec2_scale_as(vec2 v, float s, vec2 dest) {
  glm_vec2_scale_as(v, s, dest);
}

CGLM_EXPORT
void
glmc_vec2_div(vec2 a, vec2 b, vec2 dest) {
  glm_vec2_div(a, b, dest);
}

CGLM_EXPORT
void
glmc_vec2_divs(vec2 v, float s, vec2 dest) {
  glm_vec2_divs(v, s, dest);
}

CGLM_EXPORT
void
glmc_vec2_addadd(vec2 a, vec2 b, vec2 dest) {
  glm_vec2_addadd(a, b, dest);
}

CGLM_EXPORT
void
glmc_vec2_subadd(vec2 a, vec2 b, vec2 dest) {
  glm_vec2_subadd(a, b, dest);
}

CGLM_EXPORT
void
glmc_vec2_muladd(vec2 a, vec2 b, vec2 dest) {
  glm_vec2_muladd(a, b, dest);
}

CGLM_EXPORT
void
glmc_vec2_muladds(vec2 a, float s, vec2 dest) {
  glm_vec2_muladds(a, s, dest);
}

CGLM_EXPORT
void
glmc_vec2_maxadd(vec2 a, vec2 b, vec2 dest) {
  glm_vec2_maxadd(a, b, dest);
}

CGLM_EXPORT
void
glmc_vec2_minadd(vec2 a, vec2 b, vec2 dest) {
  glm_vec2_minadd(a, b, dest);
}

CGLM_EXPORT
void
glmc_vec2_subsub(vec2 a, vec2 b, vec2 dest) {
  glm_vec2_subsub(a, b, dest);
}

CGLM_EXPORT
void
glmc_vec2_addsub(vec2 a, vec2 b, vec2 dest) {
  glm_vec2_addsub(a, b, dest);
}

CGLM_EXPORT
void
glmc_vec2_mulsub(vec2 a, vec2 b, vec2 dest) {
  glm_vec2_mulsub(a, b, dest);
}

CGLM_EXPORT
void
glmc_vec2_mulsubs(vec2 a, float s, vec2 dest) {
  glm_vec2_mulsubs(a, s, dest);
}

CGLM_EXPORT
void
glmc_vec2_maxsub(vec2 a, vec2 b, vec2 dest) {
  glm_vec2_maxsub(a, b, dest);
}

CGLM_EXPORT
void
glmc_vec2_minsub(vec2 a, vec2 b, vec2 dest) {
  glm_vec2_minsub(a, b, dest);
}


CGLM_EXPORT
void
glmc_vec2_negate_to(vec2 v, vec2 dest) {
  glm_vec2_negate_to(v, dest);
}

CGLM_EXPORT
void
glmc_vec2_negate(vec2 v) {
  glm_vec2_negate(v);
}

CGLM_EXPORT
void
glmc_vec2_normalize(vec2 v) {
  glm_vec2_normalize(v);
}

CGLM_EXPORT
void
glmc_vec2_normalize_to(vec2 v, vec2 dest) {
  glm_vec2_normalize_to(v, dest);
}

CGLM_EXPORT
void
glmc_vec2_rotate(vec2 v, float angle, vec2 dest) {
  glm_vec2_rotate(v, angle, dest);
}

CGLM_EXPORT
void
glmc_vec2_center(vec2 a, vec2 b, vec2 dest) {
  glm_vec2_center(a, b, dest);
}

CGLM_EXPORT
float
glmc_vec2_distance2(vec2 a, vec2 b) {
  return glm_vec2_distance2(a, b);
}

CGLM_EXPORT
float
glmc_vec2_distance(vec2 a, vec2 b) {
  return glm_vec2_distance(a, b);
}

CGLM_EXPORT
void
glmc_vec2_maxv(vec2 a, vec2 b, vec2 dest) {
  glm_vec2_maxv(a, b, dest);
}

CGLM_EXPORT
void
glmc_vec2_minv(vec2 a, vec2 b, vec2 dest) {
  glm_vec2_minv(a, b, dest);
}

CGLM_EXPORT
void
glmc_vec2_clamp(vec2 v, float minval, float maxval) {
  glm_vec2_clamp(v, minval, maxval);
}

CGLM_EXPORT
void
glmc_vec2_abs(vec2 v, vec2 dest) {
  glm_vec2_abs(v, dest);
}

CGLM_EXPORT
void
glmc_vec2_fract(vec2 v, vec2 dest) {
  glm_vec2_fract(v, dest);
}

CGLM_EXPORT
void
glmc_vec2_floor(vec2 v, vec2 dest) {
  glm_vec2_floor(v, dest);
}

CGLM_EXPORT
void
glmc_vec2_mods(vec2 v, float s, vec2 dest) {
  glm_vec2_mods(v, s, dest);
}

CGLM_EXPORT
void
glmc_vec2_step(vec2 edge, vec2 v, vec2 dest) {
  glm_vec2_step(edge, v, dest);
}

CGLM_EXPORT
void
glmc_vec2_steps(float edge, vec2 v, vec2 dest) {
  glm_vec2_steps(edge, v, dest);
}

CGLM_EXPORT
void
glmc_vec2_stepr(vec2 edge, float v, vec2 dest) {
  glm_vec2_stepr(edge, v, dest);
}

CGLM_EXPORT
void
glmc_vec2_swizzle(vec2 v, int mask, vec2 dest) {
  glm_vec2_swizzle(v, mask, dest);
}

CGLM_EXPORT
void
glmc_vec2_lerp(vec2 from, vec2 to, float t, vec2 dest) {
  glm_vec2_lerp(from, to, t, dest);
}

CGLM_EXPORT
void
glmc_vec2_complex_mul(vec2 a, vec2 b, vec2 dest) {
  glm_vec2_complex_mul(a, b, dest);
}

CGLM_EXPORT
void
glmc_vec2_complex_div(vec2 a, vec2 b, vec2 dest) {
  glm_vec2_complex_div(a, b, dest);
}

CGLM_EXPORT
void
glmc_vec2_complex_conjugate(vec2 a, vec2 dest) {
  glm_vec2_complex_conjugate(a, dest);
}

CGLM_EXPORT
void
glmc_vec2_make(const float * __restrict src, vec2 dest) {
  glm_vec2_make(src, dest);
}

CGLM_EXPORT
void
glmc_vec2_reflect(vec2 v, vec2 n, vec2 dest) {
  glm_vec2_reflect(v, n, dest);
}

CGLM_EXPORT
bool
glmc_vec2_refract(vec2 v, vec2 n, float eta, vec2 dest) {
  return glm_vec2_refract(v, n, eta, dest);
}
