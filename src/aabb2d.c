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
glmc_aabb2d_zero(vec2 aabb[2]) {
  glm_aabb2d_zero(aabb);
}

CGLM_EXPORT
void
glmc_aabb2d_copy(vec2 aabb[2], vec2 dest[2]) {
  glm_aabb2d_copy(aabb, dest);
}

CGLM_EXPORT
void
glmc_aabb2d_transform(vec2 aabb[2], mat3 m, vec2 dest[2]) {
  glm_aabb2d_transform(aabb, m, dest);
}

CGLM_EXPORT
void
glmc_aabb2d_merge(vec2 aabb1[2], vec2 aabb2[2], vec2 dest[2]) {
  glm_aabb2d_merge(aabb1, aabb2, dest);
}

CGLM_EXPORT
void
glmc_aabb2d_crop(vec2 aabb[2], vec2 cropAabb[2], vec2 dest[2]) {
  glm_aabb2d_crop(aabb, cropAabb, dest);
}

CGLM_EXPORT
void
glmc_aabb2d_crop_until(vec2 aabb[2],
                     vec2 cropAabb[2],
                     vec2 clampAabb[2],
                     vec2 dest[2]) {
  glm_aabb2d_crop_until(aabb, cropAabb, clampAabb, dest);
}

CGLM_EXPORT
void
glmc_aabb2d_invalidate(vec2 aabb[2]) {
  glm_aabb2d_invalidate(aabb);
}

CGLM_EXPORT
bool
glmc_aabb2d_isvalid(vec2 aabb[2]) {
  return glm_aabb2d_isvalid(aabb);
}

CGLM_EXPORT
float
glmc_aabb2d_diag(vec2 aabb[2]) {
  return glm_aabb2d_diag(aabb);
}

CGLM_EXPORT
void
glmc_aabb2d_sizev(vec2 aabb[2], vec2 dest) {
  glm_aabb2d_sizev(aabb, dest);
}

CGLM_EXPORT
float
glmc_aabb2d_radius(vec2 aabb[2]) {
  return glm_aabb2d_radius(aabb);
}

CGLM_EXPORT
void
glmc_aabb2d_center(vec2 aabb[2], vec2 dest) {
  glm_aabb2d_center(aabb, dest);
}

CGLM_EXPORT
bool
glmc_aabb2d_aabb(vec2 aabb[2], vec2 other[2]) {
  return glm_aabb2d_aabb(aabb, other);
}

CGLM_EXPORT
bool
glmc_aabb2d_point(vec2 aabb[2], vec2 point) {
  return glm_aabb2d_point(aabb, point);
}

CGLM_EXPORT
bool
glmc_aabb2d_contains(vec2 aabb[2], vec2 other[2]) {
  return glm_aabb2d_contains(aabb, other);
}

CGLM_EXPORT
bool
glmc_aabb2d_circle(vec2 aabb[2], vec3 s) {
  return glm_aabb2d_circle(aabb, s);
}
