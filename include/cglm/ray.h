/*
 * Copyright (c), Recep Aslantas.
 *
 * MIT License (MIT), http://opensource.org/licenses/MIT
 * Full license can be found in the LICENSE file
 */

/*
 Functions:
   CGLM_INLINE bool glm_ray_triangle(vec3   origin,
                                     vec3   direction,
                                     vec3   v0,
                                     vec3   v1,
                                     vec3   v2,
                                     float *d);
 CGLM_INLINE bool glm_ray_sphere(vec3 origin,
                                 vec3 dir,
                                 vec4 s,
                                 float * __restrict t1,
                                 float * __restrict t2)
 CGLM_INLINE void glm_ray_at(vec3 orig, vec3 dir, float t, vec3 point);
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
glm_ray_sphere(vec3 origin,
               vec3 dir,
               vec4 s,
               float * __restrict t1,
               float * __restrict t2) {
  vec3  dp;
  float r2, ddp, dpp, dscr, q, tmp, _t1, _t2;

  glm_vec3_sub(s, origin, dp);

  ddp = glm_vec3_dot(dir, dp);
  dpp = glm_vec3_norm2(dp);

  /* compute the remedy term for numerical stability */
  glm_vec3_mulsubs(dir, ddp, dp); /* dp: remedy term */

  r2   = s[3] * s[3];
  dscr = r2 - glm_vec3_norm2(dp);

  if (dscr < 0.0f) {
    /* no intersection */
    return false;
  }

  dscr = sqrtf(dscr);
  q    = (ddp >= 0.0f) ? (ddp + dscr) : (ddp - dscr);

  /*
     include Press, William H., Saul A. Teukolsky,
     William T. Vetterling, and Brian P. Flannery,
     "Numerical Recipes in C," Cambridge University Press, 1992.
   */
  _t1 = q;
  _t2 = (dpp - r2) / q;

  /* adjust t1 and t2 to ensure t1 is the closer intersection */
  if (_t1 > _t2) {
    tmp = _t1;
    _t1 = _t2;
    _t2 = tmp;
  }

  *t1 = _t1;
  *t2 = _t2;

  /* check if the closest intersection (t1) is behind the ray's origin */
  if (_t1 < 0.0f && _t2 < 0.0f) {
    /* both intersections are behind the ray, no visible intersection */
    return false;
  }

  return true;
}

/*!
 * @brief point using t by 𝐏(𝑡)=𝐀+𝑡𝐛
 *
 * @param[in]  orig  origin of ray
 * @param[in]  dir   direction of ray
 * @param[in]  t     parameter
 * @param[out] point point at t
 */
CGLM_INLINE
void
glm_ray_at(vec3 orig, vec3 dir, float t, vec3 point) {
  vec3 dst;
  glm_vec3_scale(dir, t, dst);
  glm_vec3_add(orig, dst, point);
}

#endif
