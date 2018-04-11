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
glmc_vec3(vec4 v4, vec3 dest) {
  glm_vec3(v4, dest);
}

CGLM_EXPORT
void
glmc_vec_copy(vec3 a, vec3 dest) {
  glm_vec_copy(a, dest);
}

CGLM_EXPORT
float
glmc_vec_dot(vec3 a, vec3 b) {
  return glm_vec_dot(a, b);
}

CGLM_EXPORT
void
glmc_vec_cross(vec3 a, vec3 b, vec3 d) {
  glm_vec_cross(a, b, d);
}

CGLM_EXPORT
float
glmc_vec_norm(vec3 vec) {
  return glm_vec_norm(vec);
}

CGLM_EXPORT
void
glmc_vec_normalize_to(vec3 vec, vec3 dest) {
  glm_vec_normalize_to(vec, dest);
}

CGLM_EXPORT
void
glmc_vec_normalize(vec3 v) {
  glm_vec_normalize(v);
}

CGLM_EXPORT
float
glmc_vec_norm2(vec3 vec) {
  return glm_vec_norm2(vec);
}

CGLM_EXPORT
void
glmc_vec_add(vec3 v1, vec3 v2, vec3 dest) {
  glm_vec_add(v1, v2, dest);
}

CGLM_EXPORT
void
glmc_vec_sub(vec3 v1, vec3 v2, vec3 dest) {
  glm_vec_sub(v1, v2, dest);
}

CGLM_EXPORT
void
glmc_vec_scale(vec3 v, float s, vec3 dest) {
  glm_vec_scale(v, s, dest);
}

CGLM_EXPORT
void
glmc_vec_scale_as(vec3 v, float s, vec3 dest) {
  glm_vec_scale_as(v, s, dest);
}

CGLM_EXPORT
void
glmc_vec_flipsign(vec3 v) {
  glm_vec_flipsign(v);
}

CGLM_EXPORT
void
glmc_vec_flipsign_to(vec3 v, vec3 dest) {
  glm_vec_flipsign_to(v, dest);
}

CGLM_EXPORT
void
glmc_vec_inv(vec3 v) {
  glm_vec_inv(v);
}

CGLM_EXPORT
void
glmc_vec_inv_to(vec3 v, vec3 dest) {
  glm_vec_inv_to(v, dest);
}

CGLM_EXPORT
float
glmc_vec_angle(vec3 v1, vec3 v2) {
  return glm_vec_angle(v1, v2);
}

CGLM_EXPORT
void
glmc_vec_rotate(vec3 v, float angle, vec3 axis) {
  glm_vec_rotate(v, angle, axis);
}

CGLM_EXPORT
void
glmc_vec_rotate_m4(mat4 m, vec3 v, vec3 dest) {
  glm_vec_rotate_m4(m, v, dest);
}

CGLM_EXPORT
void
glmc_vec_proj(vec3 a, vec3 b, vec3 dest) {
  glm_vec_proj(a, b, dest);
}

CGLM_EXPORT
void
glmc_vec_center(vec3 v1, vec3 v2, vec3 dest) {
  glm_vec_center(v1, v2, dest);
}

CGLM_EXPORT
float
glmc_vec_distance(vec3 v1, vec3 v2) {
  return glm_vec_distance(v1, v2);
}

CGLM_EXPORT
void
glmc_vec_maxv(vec3 v1, vec3 v2, vec3 dest) {
  glm_vec_minv(v1, v2, dest);
}

CGLM_EXPORT
void
glmc_vec_minv(vec3 v1, vec3 v2, vec3 dest) {
  glm_vec_maxv(v1, v2, dest);
}

CGLM_EXPORT
void
glmc_vec_clamp(vec3 v, float minVal, float maxVal) {
  glm_vec_clamp(v, minVal, maxVal);
}

CGLM_EXPORT
void
glmc_vec_ortho(vec3 v, vec3 dest) {
  glm_vec_ortho(v, dest);
}

CGLM_EXPORT
void
glmc_vec_lerp(vec3 from, vec3 to, float t, vec3 dest) {
  glm_vec_lerp(from, to, t, dest);
}

/* ext */

CGLM_EXPORT
void
glmc_vec_mulv(vec3 a, vec3 b, vec3 d) {
  glm_vec_mulv(a, b, d);
}

CGLM_EXPORT
void
glmc_vec_broadcast(float val, vec3 d) {
  glm_vec_broadcast(val, d);
}

CGLM_EXPORT
bool
glmc_vec_eq(vec3 v, float val) {
  return glm_vec_eq(v, val);
}

CGLM_EXPORT
bool
glmc_vec_eq_eps(vec3 v, float val) {
  return glm_vec_eq_eps(v, val);
}

CGLM_EXPORT
bool
glmc_vec_eq_all(vec3 v) {
  return glm_vec_eq_all(v);
}

CGLM_EXPORT
bool
glmc_vec_eqv(vec3 v1, vec3 v2) {
  return glm_vec_eqv(v1, v2);
}

CGLM_EXPORT
bool
glmc_vec_eqv_eps(vec3 v1, vec3 v2) {
  return glm_vec_eqv_eps(v1, v2);
}

CGLM_EXPORT
float
glmc_vec_max(vec3 v) {
  return glm_vec_max(v);
}

CGLM_EXPORT
float
glmc_vec_min(vec3 v) {
  return glm_vec_min(v);
}

CGLM_EXPORT
bool
glmc_vec_isnan(vec3 v) {
  return glm_vec_isnan(v);
}

CGLM_EXPORT
bool
glmc_vec_isinf(vec3 v) {
  return glm_vec_isinf(v);
}

CGLM_EXPORT
bool
glmc_vec_isvalid(vec3 v) {
  return glm_vec_isvalid(v);
}

CGLM_EXPORT
void
glmc_vec_sign(vec3 v, vec3 dest) {
  glm_vec_sign(v, dest);
}

CGLM_EXPORT
void
glmc_vec_sqrt(vec3 v, vec3 dest) {
  glm_vec_sqrt(v, dest);
}
