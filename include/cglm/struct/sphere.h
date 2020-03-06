/*
 * Copyright (c), Recep Aslantas.
 *
 * MIT License (MIT), http://opensource.org/licenses/MIT
 * Full license can be found in the LICENSE file
 */

#ifndef cglms_spheres_h
#define cglms_spheres_h

#include "../common.h"
#include "../types-struct.h"
#include "../sphere.h"
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
glms_sphere_radii(vec4s s) {
  return glm_sphere_radii(s.raw);
}

/*!
 * @brief apply transform to sphere, it is just wrapper for glm_mat4_mulv3
 *
 * @param[in]  s    sphere
 * @param[in]  m    transform matrix
 * @returns         transformed sphere
 */
CGLM_INLINE
vec4s
glms_sphere_transform(vec4s s, mat4s m) {
  vec4s r;
  glm_sphere_transform(s.raw, m.raw, r.raw);
  return r;
}

/*!
 * @brief merges two spheres and creates a new one
 *
 * two sphere must be in same space, for instance if one in world space then
 * the other must be in world space too, not in local space.
 *
 * @param[in]  s1   sphere 1
 * @param[in]  s2   sphere 2
 * returns          merged/extended sphere
 */
CGLM_INLINE
vec4s
glms_sphere_merge(vec4s s1, vec4s s2) {
  vec4s r;
  glm_sphere_merge(s1.raw, s2.raw, r.raw);
  return r;
}

/*!
 * @brief check if two sphere intersects
 *
 * @param[in]   s1  sphere
 * @param[in]   s2  other sphere
 */
CGLM_INLINE
bool
glms_sphere_sphere(vec4s s1, vec4s s2) {
  return glm_sphere_sphere(s1.raw, s2.raw);
}

/*!
 * @brief check if sphere intersects with point
 *
 * @param[in]   s      sphere
 * @param[in]   point  point
 */
CGLM_INLINE
bool
glms_sphere_point(vec4s s, vec3s point) {
  return glm_sphere_point(s.raw, point.raw);
}

#endif /* cglms_spheres_h */
