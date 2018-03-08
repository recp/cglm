/*
 * Copyright (c), Recep Aslantas.
 *
 * MIT License (MIT), http://opensource.org/licenses/MIT
 * Full license can be found in the LICENSE file
 */

#ifndef cglm_project_h
#define cglm_project_h

#include "mat4.h"

/*!
 * @brief maps the specified viewport coordinates into specified space [1]
 *        the matrix should contain projection matrix.
 *
 * if you don't have ( and don't want to have ) an inverse matrix then use
 * glm_unproject version. You may use existing inverse of matrix in somewhere
 * else, this is why glm_unprojecti exists to save save inversion cost
 *
 * [1] space:
 *  1- if m = invProj:     View Space
 *  2- if m = invViewProj: World Space
 *  3- if m = invMVP:      Object Space
 *
 * You probably want to map the coordinates into object space
 * so use invMVP as m
 *
 * Computing viewProj:
 *   glm_mat4_mul(proj, view, viewProj);
 *   glm_mat4_mul(viewProj, model, MVP);
 *   glm_mat4_inv(viewProj, invMVP);
 *
 * @param[in]  invMat   matrix (see brief)
 * @param[in]  vp       viewport as [x, y, width, height]
 * @param[in]  coord    viewport coordinates
 * @param[out] dest     unprojected coordinates
 */
CGLM_INLINE
void
glm_unprojecti(mat4 invMat, vec4 vp, vec3 coord, vec4 dest) {
  vec4 v;

  v[0] = 2.0f * (coord[0] - vp[0]) / vp[2] - 1.0f;
  v[1] = 2.0f * (coord[1] - vp[1]) / vp[3] - 1.0f;
  v[2] = 2.0f *  coord[2]                  - 1.0f;
  v[3] = 1.0f;

  glm_mat4_mulv(invMat, v, dest);
}

/*!
 * @brief maps the specified viewport coordinates into specified space [1]
 *        the matrix should contain projection matrix.
 *
 * this is same as glm_unprojecti except this function get inverse matrix for
 * you.
 *
 * [1] space:
 *  1- if m = proj:     View Space
 *  2- if m = viewProj: World Space
 *  3- if m = MVP:      Object Space
 *
 * You probably want to map the coordinates into object space
 * so use MVP as m
 *
 * Computing viewProj:
 *   glm_mat4_mul(proj, view, viewProj);
 *   glm_mat4_mul(viewProj, model, MVP);
 *
 * @param[in]  m        matrix (see brief)
 * @param[in]  vp       viewport as [x, y, width, height]
 * @param[in]  coord    viewport coordinates
 * @param[out] dest     unprojected coordinates
 */
CGLM_INLINE
void
glm_unproject(mat4 m, vec4 vp, vec3 coord, vec4 dest) {
  mat4 inv;
  glm_mat4_inv(m, inv);
  glm_unprojecti(inv, vp, coord, dest);
}

#endif /* cglm_project_h */
