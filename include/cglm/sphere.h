/*
 * Copyright (c), Recep Aslantas.
 *
 * MIT License (MIT), http://opensource.org/licenses/MIT
 * Full license can be found in the LICENSE file
 */

#ifndef cglm_sphere_h
#define cglm_sphere_h

#include "common.h"
#include "mat4.h"

/*
  Sphere Representation in cglm: [center.x, center.y, center.z, radii]

  You could use this representation or you can convert it to vec4 before call
  any function
 */

CGLM_INLINE
void
glm_sphere_transform(vec4 s, mat4 m, vec4 dest) {
  glm_mat4_mulv3(m, s, 1.0f, dest);
  dest[3] = s[3];
}

CGLM_INLINE
void
glm_sphere_merge(vec4 s1, vec4 s2, vec4 dest) {
  float dist, radii;

  dist  = glm_vec_distance(s1, s2);
  radii = dist + s1[3] + s2[3];

  glm_vec_center(s1, s2, dest);
  dest[3] = radii;
}

#endif /* cglm_sphere_h */
