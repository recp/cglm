/*
 * Copyright (c), Recep Aslantas.
 *
 * MIT License (MIT), http://opensource.org/licenses/MIT
 * Full license can be found in the LICENSE file
 */

#ifndef cglm_project_h
#define cglm_project_h

#include "common.h"
#include "vec3.h"
#include "vec4.h"
#include "mat4.h"

#ifndef CGLM_CLIPSPACE_INCLUDE_ALL
#  if CGLM_CONFIG_CLIP_CONTROL & CGLM_CLIP_CONTROL_ZO_BIT
#    include "clipspace/project_zo.h"
#  elif CGLM_CONFIG_CLIP_CONTROL & CGLM_CLIP_CONTROL_NO_BIT
#    include "clipspace/project_no.h"
#  endif
#else
#  include "clipspace/project_zo.h"
#  include "clipspace/project_no.h"
#endif

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
 * @param[in]  pos      point/position in viewport coordinates
 * @param[in]  invMat   matrix (see brief)
 * @param[in]  vp       viewport as [x, y, width, height]
 * @param[out] dest     unprojected coordinates
 */
CGLM_INLINE
void
glm_unprojecti(vec3 pos, mat4 invMat, vec4 vp, vec3 dest) {
#if CGLM_CONFIG_CLIP_CONTROL & CGLM_CLIP_CONTROL_ZO_BIT
  glm_unprojecti_zo(pos, invMat, vp, dest);
#elif CGLM_CONFIG_CLIP_CONTROL & CGLM_CLIP_CONTROL_NO_BIT
  glm_unprojecti_no(pos, invMat, vp, dest);
#endif
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
 * Computing viewProj and MVP:
 *   glm_mat4_mul(proj, view, viewProj);
 *   glm_mat4_mul(viewProj, model, MVP);
 *
 * @param[in]  pos      point/position in viewport coordinates
 * @param[in]  m        matrix (see brief)
 * @param[in]  vp       viewport as [x, y, width, height]
 * @param[out] dest     unprojected coordinates
 */
CGLM_INLINE
void
glm_unproject(vec3 pos, mat4 m, vec4 vp, vec3 dest) {
  mat4 inv;
  glm_mat4_inv(m, inv);
  glm_unprojecti(pos, inv, vp, dest);
}

/*!
 * @brief map object coordinates to window coordinates
 *
 * Computing MVP:
 *   glm_mat4_mul(proj, view, viewProj);
 *   glm_mat4_mul(viewProj, model, MVP);
 *
 * @param[in]  pos      object coordinates
 * @param[in]  m        MVP matrix
 * @param[in]  vp       viewport as [x, y, width, height]
 * @param[out] dest     projected coordinates
 */
CGLM_INLINE
void
glm_project(vec3 pos, mat4 m, vec4 vp, vec3 dest) {
#if CGLM_CONFIG_CLIP_CONTROL & CGLM_CLIP_CONTROL_ZO_BIT
  glm_project_zo(pos, m, vp, dest);
#elif CGLM_CONFIG_CLIP_CONTROL & CGLM_CLIP_CONTROL_NO_BIT
  glm_project_no(pos, m, vp, dest);
#endif
}

/*!
 * @brief map object's z coordinate to window coordinates
 *
 * Computing MVP:
 *   glm_mat4_mul(proj, view, viewProj);
 *   glm_mat4_mul(viewProj, model, MVP);
 *
 * @param[in]  v  object coordinates
 * @param[in]  m  MVP matrix
 *
 * @returns projected z coordinate
 */
CGLM_INLINE
float
glm_project_z(vec3 v, mat4 m) {
#if CGLM_CONFIG_CLIP_CONTROL & CGLM_CLIP_CONTROL_ZO_BIT
  return glm_project_z_zo(v, m);
#elif CGLM_CONFIG_CLIP_CONTROL & CGLM_CLIP_CONTROL_NO_BIT
  return glm_project_z_no(v, m);
#endif
}

/*!
 * @brief define a picking region
 *
 * @param[in]  center   center [x, y] of a picking region in window coordinates
 * @param[in]  size     size [width, height] of the picking region in window coordinates
 * @param[in]  vp       viewport as [x, y, width, height]
 * @param[out] dest     projected coordinates
 */
CGLM_INLINE
void
glm_pickmatrix(vec2 center, vec2 size, vec4 vp, mat4 dest) {
  mat4 res;
  vec3 v;

  if (size[0] <= 0.0f || size[1] <= 0.0f)
    return;
  
  /* Translate and scale the picked region to the entire window */
  v[0] = (vp[2] - 2.0f * (center[0] - vp[0])) / size[0];
  v[1] = (vp[3] - 2.0f * (center[1] - vp[1])) / size[1];
  v[2] = 0.0f;

  glm_translate_make(res, v);
  
  v[0] = vp[2] / size[0];
  v[1] = vp[3] / size[1];
  v[2] = 1.0f;

  glm_scale(res, v);

  glm_mat4_copy(res, dest);
}

#endif /* cglm_project_h */
