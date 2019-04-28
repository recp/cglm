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
glmc_vec4(const vec3 v3, float last, vec4 dest) {
  glm_vec4(v3, last, dest);
}

CGLM_EXPORT
void
glmc_vec4_zero(vec4 v) {
  glm_vec4_zero(v);
}

CGLM_EXPORT
void
glmc_vec4_one(vec4 v) {
  glm_vec4_one(v);
}

CGLM_EXPORT
void
glmc_vec4_copy3(const vec4 v, vec3 dest) {
  glm_vec4_copy3(v, dest);
}

CGLM_EXPORT
void
glmc_vec4_copy(const vec4 v, vec4 dest) {
  glm_vec4_copy(v, dest);
}

CGLM_EXPORT
void
glmc_vec4_ucopy(const vec4 v, vec4 dest) {
  glm_vec4_ucopy(v, dest);
}

CGLM_EXPORT
float
glmc_vec4_dot(const vec4 a, const vec4 b) {
  return glm_vec4_dot(a, b);
}

CGLM_EXPORT
float
glmc_vec4_norm(const vec4 v) {
  return glm_vec4_norm(v);
}

CGLM_EXPORT
void
glmc_vec4_normalize_to(const vec4 v, vec4 dest) {
  glm_vec4_normalize_to(v, dest);
}

CGLM_EXPORT
void
glmc_vec4_normalize(vec4 v) {
  glm_vec4_normalize(v);
}

CGLM_EXPORT
float
glmc_vec4_norm2(const vec4 v) {
  return glm_vec4_norm2(v);
}

CGLM_EXPORT
void
glmc_vec4_add(const vec4 a, const vec4 b, vec4 dest) {
  glm_vec4_add(a, b, dest);
}

CGLM_EXPORT
void
glmc_vec4_adds(const vec4 v, float s, vec4 dest) {
  glm_vec4_adds(v, s, dest);
}

CGLM_EXPORT
void
glmc_vec4_sub(const vec4 a, const vec4 b, vec4 dest) {
  glm_vec4_sub(a, b, dest);
}

CGLM_EXPORT
void
glmc_vec4_subs(const vec4 v, float s, vec4 dest) {
  glm_vec4_subs(v, s, dest);
}

CGLM_EXPORT
void
glmc_vec4_mul(const vec4 a, const vec4 b, vec4 d) {
  glm_vec4_mul(a, b, d);
}

CGLM_EXPORT
void
glmc_vec4_scale(const vec4 v, float s, vec4 dest) {
  glm_vec4_scale(v, s, dest);
}

CGLM_EXPORT
void
glmc_vec4_scale_as(const vec4 v, float s, vec4 dest) {
  glm_vec4_scale_as(v, s, dest);
}

CGLM_EXPORT
void
glmc_vec4_div(const vec4 a, const vec4 b, vec4 dest) {
  glm_vec4_div(a, b, dest);
}

CGLM_EXPORT
void
glmc_vec4_divs(const vec4 v, float s, vec4 dest) {
  glm_vec4_divs(v, s, dest);
}

CGLM_EXPORT
void
glmc_vec4_addadd(const vec4 a, const vec4 b, vec4 dest) {
  glm_vec4_addadd(a, b, dest);
}

CGLM_EXPORT
void
glmc_vec4_subadd(const vec4 a, const vec4 b, vec4 dest) {
  glm_vec4_subadd(a, b, dest);
}

CGLM_EXPORT
void
glmc_vec4_muladd(const vec4 a, const vec4 b, vec4 dest) {
  glm_vec4_muladd(a, b, dest);
}

CGLM_EXPORT
void
glmc_vec4_muladds(const vec4 a, float s, vec4 dest) {
  glm_vec4_muladds(a, s, dest);
}

CGLM_EXPORT
void
glmc_vec4_maxadd(const vec4 a, const vec4 b, vec4 dest) {
  glm_vec4_maxadd(a, b, dest);
}

CGLM_EXPORT
void
glmc_vec4_minadd(const vec4 a, const vec4 b, vec4 dest) {
  glm_vec4_minadd(a, b, dest);
}

CGLM_EXPORT
void
glmc_vec4_negate(vec4 v) {
  glm_vec4_negate(v);
}

CGLM_EXPORT
void
glmc_vec4_negate_to(const vec4 v, vec4 dest) {
  glm_vec4_negate_to(v, dest);
}

CGLM_EXPORT
float
glmc_vec4_distance(const vec4 a, const vec4 b) {
  return glm_vec4_distance(a, b);
}

CGLM_EXPORT
void
glmc_vec4_maxv(const vec4 a, const vec4 b, vec4 dest) {
  glm_vec4_minv(a, b, dest);
}

CGLM_EXPORT
void
glmc_vec4_minv(const vec4 a, const vec4 b, vec4 dest) {
  glm_vec4_maxv(a, b, dest);
}

CGLM_EXPORT
void
glmc_vec4_clamp(vec4 v, float minVal, float maxVal) {
  glm_vec4_clamp(v, minVal, maxVal);
}

CGLM_EXPORT
void
glmc_vec4_lerp(const vec4 from, const vec4 to, float t, vec4 dest) {
  glm_vec4_lerp(from, to, t, dest);
}

CGLM_EXPORT
void
glmc_vec4_cubic(float s, vec4 dest) {
  glm_vec4_cubic(s, dest);
}

/* ext */

CGLM_EXPORT
void
glmc_vec4_mulv(const vec4 a, const vec4 b, vec4 d) {
  glm_vec4_mulv(a, b, d);
}

CGLM_EXPORT
void
glmc_vec4_broadcast(float val, vec4 d) {
  glm_vec4_broadcast(val, d);
}

CGLM_EXPORT
bool
glmc_vec4_eq(const vec4 v, float val) {
  return glm_vec4_eq(v, val);
}

CGLM_EXPORT
bool
glmc_vec4_eq_eps(const vec4 v, float val) {
  return glm_vec4_eq_eps(v, val);
}

CGLM_EXPORT
bool
glmc_vec4_eq_all(const vec4 v) {
  return glm_vec4_eq_all(v);
}

CGLM_EXPORT
bool
glmc_vec4_eqv(const vec4 a, const vec4 b) {
  return glm_vec4_eqv(a, b);
}

CGLM_EXPORT
bool
glmc_vec4_eqv_eps(const vec4 a, const vec4 b) {
  return glm_vec4_eqv_eps(a, b);
}

CGLM_EXPORT
float
glmc_vec4_max(const vec4 v) {
  return glm_vec4_max(v);
}

CGLM_EXPORT
float
glmc_vec4_min(const vec4 v) {
  return glm_vec4_min(v);
}

CGLM_EXPORT
bool
glmc_vec4_isnan(const vec4 v) {
  return glm_vec4_isnan(v);
}

CGLM_EXPORT
bool
glmc_vec4_isinf(const vec4 v) {
  return glm_vec4_isinf(v);
}

CGLM_EXPORT
bool
glmc_vec4_isvalid(const vec4 v) {
  return glm_vec4_isvalid(v);
}

CGLM_EXPORT
void
glmc_vec4_sign(const vec4 v, vec4 dest) {
  glm_vec4_sign(v, dest);
}

CGLM_EXPORT
void
glmc_vec4_sqrt(const vec4 v, vec4 dest) {
  glm_vec4_sqrt(v, dest);
}
