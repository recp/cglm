/*
 * Copyright (c), Recep Aslantas.
 *
 * MIT License (MIT), http://opensource.org/licenses/MIT
 * Full license can be found in the LICENSE file
 */

#include "../include/cglm/cglm.h"
#include "../include/cglm/call.h"

CGLM_EXPORT
float
glmc_sphere_radii(vec4 s) {
  return glm_sphere_radii(s);
}

CGLM_EXPORT
void
glmc_sphere_transform(vec4 s, mat4 m, vec4 dest) {
  glm_sphere_transform(s, m, dest);
}

CGLM_EXPORT
void
glmc_sphere_merge(vec4 s1, vec4 s2, vec4 dest) {
  glm_sphere_merge(s1, s2, dest);
}

CGLM_EXPORT
bool
glmc_sphere_sphere(vec4 s1, vec4 s2) {
  return glm_sphere_sphere(s1, s2);
}

CGLM_EXPORT
bool
glmc_sphere_point(vec4 s, vec3 point) {
  return glm_sphere_point(s, point);
}
