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

/*!
 * @brief helper for getting sphere radius
 *
 * @param[in]   s  sphere
 *
 * @return returns radii
 */
CGLM_INLINE
float
glm_sphere_radii(vec4 s) {
  return s[3];
}

/*!
 * @brief apply transform to sphere, it is just wrapper for glm_mat4_mulv3
 *
 * @param[in]  s    sphere
 * @param[in]  m    transform matrix
 * @param[out] dest transformed sphere
 */
CGLM_INLINE
void
glm_sphere_transform(vec4 s, mat4 m, vec4 dest) {
  glm_mat4_mulv3(m, s, 1.0f, dest);
  dest[3] = s[3];
}

/*!
 * @brief merges two spheres and creates a new one
 *
 * two sphere must be in same space, for instance if one in world space then
 * the other must be in world space too, not in local space.
 *
 * @param[in]  s1   sphere 1
 * @param[in]  s2   sphere 2
 * @param[out] dest merged/extended sphere
 */
CGLM_INLINE
void
glm_sphere_merge(vec4 s1, vec4 s2, vec4 dest) {
  float dist, radii;

  dist  = glm_vec3_distance(s1, s2);
  radii = dist + s1[3] + s2[3];

  radii = glm_max(radii, s1[3]);
  radii = glm_max(radii, s2[3]);

  glm_vec3_center(s1, s2, dest);
  dest[3] = radii;
}

/*!
 * @brief check if two sphere intersects
 *
 * @param[in]   s1  sphere
 * @param[in]   s2  other sphere
 */
CGLM_INLINE
bool
glm_sphere_sphere(vec4 s1, vec4 s2) {
  return glm_vec3_distance2(s1, s2) <= glm_pow2(s1[3] + s2[3]);
}

/*!
 * @brief check if sphere intersects with point
 *
 * @param[in]   s      sphere
 * @param[in]   point  point
 */
CGLM_INLINE
bool
glm_sphere_point(vec4 s, vec3 point) {
  float rr;
  rr = s[3] * s[3];
  return glm_vec3_distance2(point, s) <= rr;
}

#endif /* cglm_sphere_h */
