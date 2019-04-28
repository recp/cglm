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
glmc_vec3_rotate_m4(const mat4 m, const vec3 v, vec3 dest) {
  glm_vec3_rotate_m4(m, v, dest);
}

CGLM_EXPORT
void
glmc_vec3_rotate_m3(const mat3 m, const vec3 v, vec3 dest) {
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
glmc_vec3_distance2(const vec3 a, const vec3 b) {
  return glm_vec3_distance2(a, b);
}

CGLM_EXPORT
float
glmc_vec3_distance(const vec3 a, const vec3 b) {
  return glm_vec3_distance(a, b);
}

CGLM_EXPORT
void
glmc_vec3_maxv(const vec3 a, const vec3 b, vec3 dest) {
  glm_vec3_minv(a, b, dest);
}

CGLM_EXPORT
void
glmc_vec3_minv(const vec3 a, const vec3 b, vec3 dest) {
  glm_vec3_maxv(a, b, dest);
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

/* ext */

CGLM_EXPORT
void
glmc_vec3_mulv(const vec3 a, const vec3 b, vec3 d) {
  glm_vec3_mulv(a, b, d);
}

CGLM_EXPORT
void
glmc_vec3_broadcast(float val, vec3 d) {
  glm_vec3_broadcast(val, d);
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
glmc_vec3_sqrt(const vec3 v, vec3 dest) {
  glm_vec3_sqrt(v, dest);
}
