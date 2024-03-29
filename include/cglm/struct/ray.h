/*
 * Copyright (c), Recep Aslantas.
 *
 * MIT License (MIT), http://opensource.org/licenses/MIT
 * Full license can be found in the LICENSE file
 */

#ifndef cglms_ray_h
#define cglms_ray_h

#include "../common.h"
#include "../types-struct.h"
#include "../ray.h"

/* api definition */
#define glms_ray_(NAME) CGLM_STRUCTAPI(ray, NAME)

/*!
 * @brief Möller–Trumbore ray-triangle intersection algorithm
 *
 * @param[in] origin         origin of ray
 * @param[in] direction      direction of ray
 * @param[in] v0             first vertex of triangle
 * @param[in] v1             second vertex of triangle
 * @param[in] v2             third vertex of triangle
 * @param[in, out] d         distance to intersection
 * @return whether there is intersection
 */
CGLM_INLINE
bool
glms_ray_(triangle)(vec3s  origin,
                    vec3s  direction,
                    vec3s  v0,
                    vec3s  v1,
                    vec3s  v2,
                    float *d) {
  return glm_ray_triangle(origin.raw, direction.raw, v0.raw, v1.raw, v2.raw, d);
}

/*!
 * @brief ray sphere intersection
 *
 * returns false if there is no intersection if true:
 *
 * - t1 > 0, t2 > 0: ray intersects the sphere at t1 and t2 both ahead of the origin
 * - t1 < 0, t2 > 0: ray starts inside the sphere, exits at t2
 * - t1 < 0, t2 < 0: no intersection ahead of the ray ( returns false )
 * - the caller can check if the intersection points (t1 and t2) fall within a
 *   specific range (for example, tmin < t1, t2 < tmax) to determine if the
 *   intersections are within a desired segment of the ray
 *
 * @param[in]  origin ray origin
 * @param[out] dir    normalized ray direction
 * @param[in]  s      sphere  [center.x, center.y, center.z, radii]
 * @param[in]  t1     near point1 (closer to origin)
 * @param[in]  t2     far point2 (farther from origin)
 *
 * @returns whether there is intersection
 */
CGLM_INLINE
bool
glms_ray_(sphere)(vec3s origin,
                  vec3s dir,
                  vec4s s,
                  float * __restrict t1,
                  float * __restrict t2) {
  return glm_ray_sphere(origin.raw, dir.raw, s.raw, t1, t2);
}

/*!
 * @brief point using t by 𝐏(𝑡)=𝐀+𝑡𝐛
 *
 * @param[in]  orig  origin of ray
 * @param[in]  dir   direction of ray
 * @param[in]  t     parameter
 * @returns point point at t
 */
CGLM_INLINE
vec3s
glms_ray_(at)(vec3s orig, vec3s dir, float t) {
  vec3s r;
  glm_ray_at(orig.raw, dir.raw, t, r.raw);
  return r;
}

#endif /* cglms_ray_h */
