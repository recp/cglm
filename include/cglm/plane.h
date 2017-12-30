/*
 * Copyright (c), Recep Aslantas.
 *
 * MIT License (MIT), http://opensource.org/licenses/MIT
 * Full license can be found in the LICENSE file
 */

#ifndef cglm_plane_h
#define cglm_plane_h

#include "common.h"
#include "mat4.h"
#include "vec4.h"

/*
 Plane equation:  Ax + By + Cz + D = 0;

 It stored in vec4 as [A, B, C, D]. (A, B, C) is normal and D is distance
*/

/*
 Functions:
   CGLM_INLINE void  glm_plane_normalize(vec4 plane);
   CGLM_INLINE void  glm_plane_extract(mat4 projView, vec4 dest[6]);
 */

/*!
 * @brief normalizes a plane
 *
 * @param[in, out] plane pnale to normalize
 */
CGLM_INLINE
void
glm_plane_normalize(vec4 plane) {
  glm_vec4_scale(plane, 1.0f / glm_vec_norm(plane), plane);
}

/*!
 * @brief extracts view frustum planes
 *
 * computing projView: glm_mat4_mul(proj, view, projView);
 *
 * exracted planes order: [left, right, bottom, top, near, far]
 *
 * @param[in]  projView source
 * @param[out] dest     exracted view frustum planes (see brief)
 */
CGLM_INLINE
void
glm_plane_extract(mat4 projView, vec4 dest[6]) {
  mat4 m;

  glm_mat4_transpose_to(projView, m);

  glm_vec4_add(m[3], m[0], dest[0]);
  glm_vec4_sub(m[3], m[0], dest[1]);
  glm_vec4_add(m[3], m[1], dest[2]);
  glm_vec4_sub(m[3], m[1], dest[3]);
  glm_vec4_add(m[3], m[2], dest[4]);
  glm_vec4_sub(m[3], m[2], dest[5]);

  glm_plane_normalize(dest[0]);
  glm_plane_normalize(dest[1]);
  glm_plane_normalize(dest[2]);
  glm_plane_normalize(dest[3]);
  glm_plane_normalize(dest[4]);
  glm_plane_normalize(dest[5]);
}

#endif /* cglm_plane_h */
