/*
 * Copyright (c), Recep Aslantas.
 *
 * MIT License (MIT), http://opensource.org/licenses/MIT
 * Full license can be found in the LICENSE file
 */

/*
 Functions:
   CGLM_INLINE bool glm_line_triangle_intersect(vec3   origin,
                                                vec3   direction,
                                                vec3   v0,
                                                vec3   v1,
                                                vec3   v2,
                                                float *d);
*/

#ifndef cglm_ray_h
#define cglm_ray_h

#include "vec3.h"

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
glm_ray_triangle(vec3   origin,
                 vec3   direction,
                 vec3   v0,
                 vec3   v1,
                 vec3   v2,
                 float *d) {
  vec3        edge1, edge2, p, t, q;
  float       det, inv_det, u, v, dist;
  const float epsilon = 0.000001f;

  glm_vec3_sub(v1, v0, edge1);
  glm_vec3_sub(v2, v0, edge2);
  glm_vec3_cross(direction, edge2, p);

  det = glm_vec3_dot(edge1, p);
  if (det > -epsilon && det < epsilon)
    return false;

  inv_det = 1.0f / det;
  
  glm_vec3_sub(origin, v0, t);

  u = inv_det * glm_vec3_dot(t, p);
  if (u < 0.0f || u > 1.0f)
    return false;

  glm_vec3_cross(t, edge1, q);

  v = inv_det * glm_vec3_dot(direction, q);
  if (v < 0.0f || u + v > 1.0f)
    return false;

  dist = inv_det * glm_vec3_dot(edge2, q);

  if (d)
    *d = dist;

  return dist > epsilon;
}

#endif
