/*
 * Copyright (c), Recep Aslantas.
 *
 * MIT License (MIT), http://opensource.org/licenses/MIT
 * Full license can be found in the LICENSE file
 */

#include "../include/cglm.h"

CGLM_EXPORT
void
glmc_vec_copy(vec3 a, vec3 dest) {
  glm_vec_copy(a, dest);
}

CGLM_EXPORT
void
glmc_vec4_copy3(vec4 a, vec3 dest) {
  glm_vec4_copy3(a, dest);
}

CGLM_EXPORT
void
glmc_vec4_copy(vec4 v, vec4 dest) {
  glm_vec4_copy(v, dest);
}

CGLM_EXPORT
float
glmc_vec_dot(vec3 a, vec3 b) {
  return glm_vec_dot(a, b);
}

CGLM_EXPORT
float
glmc_vec4_dot(vec4 a, vec4 b) {
  return glm_vec4_dot(a, b);
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
float
glmc_vec4_norm(vec4 vec) {
  return glm_vec4_norm(vec);
}

CGLM_EXPORT
void
glmc_vec_normalize_to(vec3 vec, vec3 dest) {
  glm_vec_normalize_to(vec, dest);
}

CGLM_EXPORT
void
glmc_vec4_normalize_to(vec4 vec, vec4 dest) {
  glm_vec4_normalize_to(vec, dest);
}

CGLM_EXPORT
void
glmc_vec_normalize(vec3 v) {
  glm_vec_normalize(v);
}

CGLM_EXPORT
void
glmc_vec4_normalize(vec4 v) {
  glm_vec4_normalize(v);
}

CGLM_EXPORT
float
glmc_vec_norm2(vec3 vec) {
  return glm_vec_norm2(vec);
}

CGLM_EXPORT
float
glmc_vec4_norm2(vec4 vec) {
  return glm_vec4_norm2(vec);
}

CGLM_EXPORT
void
glmc_vec_add(vec3 v1, vec3 v2, vec3 dest) {
  glm_vec_add(v1, v2, dest);
}

CGLM_EXPORT
void
glmc_vec4_add(vec4 v1, vec4 v2, vec4 dest) {
  glm_vec4_add(v1, v2, dest);
}

CGLM_EXPORT
void
glmc_vec_sub(vec3 v1, vec3 v2, vec3 dest) {
  glm_vec_sub(v1, v2, dest);
}

CGLM_EXPORT
void
glmc_vec4_sub(vec4 v1, vec4 v2, vec4 dest) {
  glm_vec4_sub(v1, v2, dest);
}

CGLM_EXPORT
void
glmc_vec_scale(vec3 v, float s, vec3 dest) {
  glm_vec_scale(v, s, dest);
}

CGLM_EXPORT
void
glmc_vec_flipsign(vec3 v) {
  glm_vec_flipsign(v);
}

CGLM_EXPORT
void
glmc_vec4_flipsign(vec4 v) {
  glm_vec4_flipsign(v);
}

CGLM_EXPORT
void
glmc_vec4_scale(vec4 v, float s, vec4 dest) {
  glm_vec4_scale(v, s, dest);
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
float
glmc_vec_distance(vec3 v1, vec3 v2) {
  return glm_vec_distance(v1, v2);
}

CGLM_EXPORT
float
glmc_vec4_distance(vec4 v1, vec4 v2) {
  return glm_vec4_distance(v1, v2);
}
