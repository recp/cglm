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
glmc_vec3(const vec4 v4, vec3 dest) {
  glm_vec3(v4, dest);
}

CGLM_EXPORT
void
glmc_vec3_copy(const vec3 a, vec3 dest) {
  glm_vec3_copy(a, dest);
}

CGLM_EXPORT
void
glmc_vec3_zero(vec3 v) {
  glm_vec3_zero(v);
}

CGLM_EXPORT
void
glmc_vec3_one(vec3 v) {
  glm_vec3_one(v);
}

CGLM_EXPORT
float
glmc_vec3_dot(const vec3 a, const vec3 b) {
  return glm_vec3_dot(a, b);
}

CGLM_EXPORT
void
glmc_vec3_cross(const vec3 a, const vec3 b, vec3 dest) {
  glm_vec3_cross(a, b, dest);
}

CGLM_EXPORT
void
glmc_vec3_crossn(const vec3 a, const vec3 b, vec3 dest) {
  glm_vec3_crossn(a, b, dest);
}

CGLM_EXPORT
float
glmc_vec3_norm(const vec3 v) {
  return glm_vec3_norm(v);
}

CGLM_EXPORT
void
glmc_vec3_normalize_to(const vec3 v, vec3 dest) {
  glm_vec3_normalize_to(v, dest);
}

CGLM_EXPORT
void
glmc_vec3_normalize(vec3 v) {
  glm_vec3_normalize(v);
}

CGLM_EXPORT
float
glmc_vec3_norm2(const vec3 v) {
  return glm_vec3_norm2(v);
}

CGLM_EXPORT
float
glmc_vec3_norm_one(const vec3 v) {
  return glm_vec3_norm_one(v);
}

CGLM_EXPORT
float
glmc_vec3_norm_inf(const vec3 v) {
  return glm_vec3_norm_inf(v);
}

CGLM_EXPORT
void
glmc_vec3_add(const vec3 a, const vec3 b, vec3 dest) {
  glm_vec3_add(a, b, dest);
}

CGLM_EXPORT
void
glmc_vec3_adds(const vec3 v, float s, vec3 dest) {
  glm_vec3_adds(v, s, dest);
}

CGLM_EXPORT
void
glmc_vec3_sub(const vec3 a, const vec3 b, vec3 dest) {
  glm_vec3_sub(a, b, dest);
}

CGLM_EXPORT
void
glmc_vec3_subs(const vec3 v, float s, vec3 dest) {
  glm_vec3_subs(v, s, dest);
}

CGLM_EXPORT
void
glmc_vec3_mul(const vec3 a, const vec3 b, vec3 d) {
  glm_vec3_mul(a, b, d);
}

CGLM_EXPORT
void
glmc_vec3_scale(const vec3 v, float s, vec3 dest) {
  glm_vec3_scale(v, s, dest);
}

CGLM_EXPORT
void
glmc_vec3_scale_as(const vec3 v, float s, vec3 dest) {
  glm_vec3_scale_as(v, s, dest);
}

CGLM_EXPORT
void
glmc_vec3_div(const vec3 a, const vec3 b, vec3 dest) {
  glm_vec3_div(a, b, dest);
}

CGLM_EXPORT
void
glmc_vec3_divs(const vec3 a, float s, vec3 dest) {
  glm_vec3_divs(a, s, dest);
}

CGLM_EXPORT
void
glmc_vec3_addadd(const vec3 a, const vec3 b, vec3 dest) {
  glm_vec3_addadd(a, b, dest);
}

CGLM_EXPORT
void
glmc_vec3_subadd(const vec3 a, const vec3 b, vec3 dest) {
  glm_vec3_subadd(a, b, dest);
}

CGLM_EXPORT
void
glmc_vec3_muladd(const vec3 a, const vec3 b, vec3 dest) {
  glm_vec3_muladd(a, b, dest);
}

CGLM_EXPORT
void
glmc_vec3_muladds(const vec3 a, float s, vec3 dest) {
  glm_vec3_muladds(a, s, dest);
}

CGLM_EXPORT
void
glmc_vec3_maxadd(const vec3 a, const vec3 b, vec3 dest) {
  glm_vec3_maxadd(a, b, dest);
}

CGLM_EXPORT
void
glmc_vec3_minadd(const vec3 a, const vec3 b, vec3 dest) {
  glm_vec3_minadd(a, b, dest);
}

CGLM_EXPORT
void
glmc_vec3_subsub(const vec3 a, const vec3 b, vec3 dest) {
  glm_vec3_subsub(a, b, dest);
}

CGLM_EXPORT
void
glmc_vec3_addsub(const vec3 a, const vec3 b, vec3 dest) {
  glm_vec3_addsub(a, b, dest);
}

CGLM_EXPORT
void
glmc_vec3_mulsub(const vec3 a, const vec3 b, vec3 dest) {
  glm_vec3_mulsub(a, b, dest);
}

CGLM_EXPORT
void
glmc_vec3_mulsubs(const vec3 a, float s, vec3 dest) {
  glm_vec3_mulsubs(a, s, dest);
}

CGLM_EXPORT
void
glmc_vec3_maxsub(const vec3 a, const vec3 b, vec3 dest) {
  glm_vec3_maxsub(a, b, dest);
}

CGLM_EXPORT
void
glmc_vec3_minsub(const vec3 a, const vec3 b, vec3 dest) {
  glm_vec3_minsub(a, b, dest);
}

CGLM_EXPORT
void
glmc_vec3_negate(vec3 v) {
  glm_vec3_negate(v);
}

CGLM_EXPORT
void
glmc_vec3_negate_to(const vec3 v, vec3 dest) {
  glm_vec3_negate_to(v, dest);
}

CGLM_EXPORT
float
glmc_vec3_angle(const vec3 a, const vec3 b) {
  return glm_vec3_angle(a, b);
}

CGLM_EXPORT
void
glmc_vec3_rotate(vec3 v, float angle, const vec3 axis) {
  glm_vec3_rotate(v, angle, axis);
}

CGLM_EXPORT
void
glmc_vec3_rotate_m4(CGLM_CONST mat4 m, const vec3 v, vec3 dest) {
  glm_vec3_rotate_m4(m, v, dest);
}

CGLM_EXPORT
void
glmc_vec3_rotate_m3(CGLM_CONST mat3 m, const vec3 v, vec3 dest) {
  glm_vec3_rotate_m3(m, v, dest);
}

CGLM_EXPORT
void
glmc_vec3_proj(const vec3 a, const vec3 b, vec3 dest) {
  glm_vec3_proj(a, b, dest);
}

CGLM_EXPORT
void
glmc_vec3_center(const vec3 a, const vec3 b, vec3 dest) {
  glm_vec3_center(a, b, dest);
}

CGLM_EXPORT
float
glmc_vec3_distance(const vec3 a, const vec3 b) {
  return glm_vec3_distance(a, b);
}

CGLM_EXPORT
float
glmc_vec3_distance2(const vec3 a, const vec3 b) {
  return glm_vec3_distance2(a, b);
}

CGLM_EXPORT
void
glmc_vec3_maxv(const vec3 a, const vec3 b, vec3 dest) {
  glm_vec3_maxv(a, b, dest);
}

CGLM_EXPORT
void
glmc_vec3_minv(const vec3 a, const vec3 b, vec3 dest) {
  glm_vec3_minv(a, b, dest);
}

CGLM_EXPORT
void
glmc_vec3_clamp(vec3 v, float minVal, float maxVal) {
  glm_vec3_clamp(v, minVal, maxVal);
}

CGLM_EXPORT
void
glmc_vec3_ortho(const vec3 v, vec3 dest) {
  glm_vec3_ortho(v, dest);
}

CGLM_EXPORT
void
glmc_vec3_lerp(const vec3 from, const vec3 to, float t, vec3 dest) {
  glm_vec3_lerp(from, to, t, dest);
}

CGLM_EXPORT
void
glmc_vec3_lerpc(const vec3 from, const vec3 to, float t, vec3 dest) {
  glm_vec3_lerpc(from, to, t, dest);
}

CGLM_EXPORT
void
glmc_vec3_step(const vec3 edge, const vec3 x, vec3 dest) {
  glm_vec3_step(edge, x, dest);
}

CGLM_EXPORT
void
glmc_vec3_smoothstep_uni(float edge0, float edge1, const vec3 x, vec3 dest) {
  glm_vec3_smoothstep_uni(edge0, edge1, x, dest);
}

CGLM_EXPORT
void
glmc_vec3_smoothstep(const vec3 edge0, const vec3 edge1, const vec3 x, vec3 dest) {
  glm_vec3_smoothstep(edge0, edge1, x, dest);
}

CGLM_EXPORT
void
glmc_vec3_smoothinterp(const vec3 from, const vec3 to, float t, vec3 dest) {
  glm_vec3_smoothinterp(from, to, t, dest);
}

CGLM_EXPORT
void
glmc_vec3_smoothinterpc(const vec3 from, const vec3 to, float t, vec3 dest) {
  glm_vec3_smoothinterpc(from, to, t, dest);
}

CGLM_EXPORT
void
glmc_vec3_swizzle(const vec3 v, int mask, vec3 dest) {
  glm_vec3_swizzle(v, mask, dest);
}

/* ext */

CGLM_EXPORT
void
glmc_vec3_mulv(vec3 a, vec3 b, vec3 d) {
  glm_vec3_mulv(a, b, d);
}

CGLM_EXPORT
void
glmc_vec3_broadcast(float val, vec3 d) {
  glm_vec3_broadcast(val, d);
}

CGLM_EXPORT
void
glmc_vec3_fill(vec3 v, float val) {
  glm_vec3_fill(v, val);
}

CGLM_EXPORT
bool
glmc_vec3_eq(const vec3 v, float val) {
  return glm_vec3_eq(v, val);
}

CGLM_EXPORT
bool
glmc_vec3_eq_eps(const vec3 v, float val) {
  return glm_vec3_eq_eps(v, val);
}

CGLM_EXPORT
bool
glmc_vec3_eq_all(const vec3 v) {
  return glm_vec3_eq_all(v);
}

CGLM_EXPORT
bool
glmc_vec3_eqv(const vec3 a, const vec3 b) {
  return glm_vec3_eqv(a, b);
}

CGLM_EXPORT
bool
glmc_vec3_eqv_eps(const vec3 a, const vec3 b) {
  return glm_vec3_eqv_eps(a, b);
}

CGLM_EXPORT
float
glmc_vec3_max(const vec3 v) {
  return glm_vec3_max(v);
}

CGLM_EXPORT
float
glmc_vec3_min(const vec3 v) {
  return glm_vec3_min(v);
}

CGLM_EXPORT
bool
glmc_vec3_isnan(const vec3 v) {
  return glm_vec3_isnan(v);
}

CGLM_EXPORT
bool
glmc_vec3_isinf(const vec3 v) {
  return glm_vec3_isinf(v);
}

CGLM_EXPORT
bool
glmc_vec3_isvalid(const vec3 v) {
  return glm_vec3_isvalid(v);
}

CGLM_EXPORT
void
glmc_vec3_sign(const vec3 v, vec3 dest) {
  glm_vec3_sign(v, dest);
}

CGLM_EXPORT
void
glmc_vec3_abs(const vec3 v, vec3 dest) {
  glm_vec3_abs(v, dest);
}

CGLM_EXPORT
void
glmc_vec3_fract(const vec3 v, vec3 dest) {
  glm_vec3_fract(v, dest);
}

CGLM_EXPORT
void
glmc_vec3_floor(const vec3 v, vec3 dest) {
  glm_vec3_floor(v, dest);
}

CGLM_EXPORT
void
glmc_vec3_mods(const vec3 v, float s, vec3 dest) {
  glm_vec3_mods(v, s, dest);
}

CGLM_EXPORT
void
glmc_vec3_steps(float edge, const vec3 v, vec3 dest) {
  glm_vec3_steps(edge, v, dest);
}

CGLM_EXPORT
void
glmc_vec3_stepr(const vec3 edge, float v, vec3 dest) {
  glm_vec3_stepr(edge, v, dest);
}

CGLM_EXPORT
float
glmc_vec3_hadd(const vec3 v) {
  return glm_vec3_hadd(v);
}

CGLM_EXPORT
void
glmc_vec3_sqrt(const vec3 v, vec3 dest) {
  glm_vec3_sqrt(v, dest);
}

CGLM_EXPORT
void
glmc_vec3_make(const float * __restrict src, vec3 dest) {
  glm_vec3_make(src, dest);
}

CGLM_EXPORT
void
glmc_vec3_faceforward(const vec3 n, const vec3 v, const vec3 nref, vec3 dest) {
  glm_vec3_faceforward(n, v, nref, dest);
}

CGLM_EXPORT
void
glmc_vec3_reflect(const vec3 v, const vec3 n, vec3 dest) {
  glm_vec3_reflect(v, n, dest);
}

CGLM_EXPORT
bool
glmc_vec3_refract(const vec3 v, const vec3 n, float eta, vec3 dest) {
  return glm_vec3_refract(v, n, eta, dest);
}

CGLM_EXPORT
void
glmc_vec3_swap(vec3 a, vec3 b) {
	glm_vec3_swap(a, b);
}
