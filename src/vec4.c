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
glmc_vec4_dot(vec4 a, vec4 b) {
  return glm_vec4_dot(a, b);
}

CGLM_EXPORT
float
glmc_vec4_norm(vec4 vec) {
  return glm_vec4_norm(vec);
}

CGLM_EXPORT
void
glmc_vec4_normalize_to(vec4 vec, vec4 dest) {
  glm_vec4_normalize_to(vec, dest);
}

CGLM_EXPORT
void
glmc_vec4_normalize(vec4 v) {
  glm_vec4_normalize(v);
}

CGLM_EXPORT
float
glmc_vec4_norm2(vec4 vec) {
  return glm_vec4_norm2(vec);
}

CGLM_EXPORT
void
glmc_vec4_add(vec4 v1, vec4 v2, vec4 dest) {
  glm_vec4_add(v1, v2, dest);
}

CGLM_EXPORT
void
glmc_vec4_sub(vec4 v1, vec4 v2, vec4 dest) {
  glm_vec4_sub(v1, v2, dest);
}

CGLM_EXPORT
void
glmc_vec4_scale(vec4 v, float s, vec4 dest) {
  glm_vec4_scale(v, s, dest);
}

CGLM_EXPORT
void
glmc_vec4_scale_as(vec3 v, float s, vec3 dest) {
  glm_vec4_scale_as(v, s, dest);
}

CGLM_EXPORT
void
glmc_vec4_flipsign(vec4 v) {
  glm_vec4_flipsign(v);
}

CGLM_EXPORT
void
glmc_vec4_inv(vec4 v) {
  glm_vec4_inv(v);
}

CGLM_EXPORT
void
glmc_vec4_inv_to(vec4 v, vec4 dest) {
  glm_vec4_inv_to(v, dest);
}

CGLM_EXPORT
float
glmc_vec4_distance(vec4 v1, vec4 v2) {
  return glm_vec4_distance(v1, v2);
}

CGLM_EXPORT
void
glmc_vec4_maxv(vec4 v1, vec4 v2, vec4 dest) {
  glm_vec4_minv(v1, v2, dest);
}

CGLM_EXPORT
void
glmc_vec4_minv(vec4 v1, vec4 v2, vec4 dest) {
  glm_vec4_maxv(v1, v2, dest);
}
