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
glmc_aabb_transform(const vec3 box[2], const mat4 m, vec3 dest[2]) {
  glm_aabb_transform(box, m, dest);
}

CGLM_EXPORT
void
glmc_aabb_merge(const vec3 box1[2], const vec3 box2[2], vec3 dest[2]) {
  glm_aabb_merge(box1, box2, dest);
}

CGLM_EXPORT
void
glmc_aabb_crop(const vec3 box[2], const vec3 cropBox[2], vec3 dest[2]) {
  glm_aabb_crop(box, cropBox, dest);
}

CGLM_EXPORT
void
glmc_aabb_crop_until(const vec3 box[2],
                     const vec3 cropBox[2],
                     const vec3 clampBox[2],
                     vec3       dest[2]) {
  glm_aabb_crop_until(box, cropBox, clampBox, dest);
}

CGLM_EXPORT
bool
glmc_aabb_frustum(const vec3 box[2], vec4 planes[6]) {
  return glm_aabb_frustum(box, planes);
}

CGLM_EXPORT
void
glmc_aabb_invalidate(vec3 box[2]) {
  glm_aabb_invalidate(box);
}

CGLM_EXPORT
bool
glmc_aabb_isvalid(const vec3 box[2]) {
  return glm_aabb_isvalid(box);
}

CGLM_EXPORT
float
glmc_aabb_size(const vec3 box[2]) {
  return glm_aabb_size(box);
}

CGLM_EXPORT
float
glmc_aabb_radius(const vec3 box[2]) {
  return glm_aabb_radius(box);
}

CGLM_EXPORT
void
glmc_aabb_center(const vec3 box[2], vec3 dest) {
  glm_aabb_center(box, dest);
}

CGLM_EXPORT
bool
glmc_aabb_aabb(const vec3 box[2], const vec3 other[2]) {
  return glm_aabb_aabb(box, other);
}

CGLM_EXPORT
bool
glmc_aabb_point(const vec3 box[2], const vec3 point) {
  return glm_aabb_point(box, point);
}

CGLM_EXPORT
bool
glmc_aabb_contains(const vec3 box[2], const vec3 other[2]) {
  return glm_aabb_contains(box, other);
}

CGLM_EXPORT
bool
glmc_aabb_sphere(const vec3 box[2], const vec4 s) {
  return glm_aabb_sphere(box, s);
}
