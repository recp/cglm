/*
 * Copyright (c), Recep Aslantas.
 *
 * MIT License (MIT), http://opensource.org/licenses/MIT
 * Full license can be found in the LICENSE file
 */

/*
 Functions:
   CGLM_INLINE vec3s glms_unprojecti_no(vec3s pos, mat4s invMat, vec4s vp, vec3 dest)
   CGLM_INLINE vec3s glms_project_no(vec3s pos, mat4s m, vec4s vp, vec3s dest)
 */

#ifndef cglms_project_no_h
#define cglms_project_no_h

#include "../../common.h"
#include "../../types-struct.h"
#include "../../plane.h"
#include "../../cam.h"

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
 * @param[in]  pos          point/position in viewport coordinates
 * @param[in]  invMat   matrix (see brief)
 * @param[in]  vp            viewport as [x, y, width, height]
 *
 * @returns unprojected coordinates
 */
CGLM_INLINE
vec3s
glms_unprojecti_no(vec3s pos, mat4s invMat, vec4s vp, vec3 dest) {
  vec3s dest;
  glm_unprojecti_no(pos.raw, invMat.raw, vp.raw, dest.raw);
  return dest;
}

/*!
 * @brief map object coordinates to window coordinates
 *
 * Computing MVP:
 *   glm_mat4_mul(proj, view, viewProj);
 *   glm_mat4_mul(viewProj, model, MVP);
 *
 * @param[in]  pos      object coordinates
 * @param[in]  m          MVP matrix
 * @param[in]  vp        viewport as [x, y, width, height]
 *
 * @returns projected coordinates
 */
CGLM_INLINE
vec3s
glms_project_no(vec3s pos, mat4s m, vec4s vp, vec3s dest) {
  vec3s dest;
  glm_project_no(pos.raw, m.raw, vp.raw, dest.raw);
  return dest;
}

/*!
 * @brief map object's z coordinate to window coordinates
 *
 * Computing MVP:
 *   glm_mat4_mul(proj, view, viewProj);
 *   glm_mat4_mul(viewProj, model, MVP);
 *
 * @param[in]  v object coordinates
 * @param[in]  m MVP matrix
 *
 * @returns projected z coordinate
 */
CGLM_INLINE
vec3s
glms_project_z_no(vec3s v, mat4s m) {
  return glm_project_z_no(v.raw, m.raw);
}

#endif /* cglms_project_rh_no_h */
