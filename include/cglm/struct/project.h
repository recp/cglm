/*
 * Copyright (c), Recep Aslantas.
 *
 * MIT License (MIT), http://opensource.org/licenses/MIT
 * Full license can be found in the LICENSE file
 */

#ifndef cglms_projects_h
#define cglms_projects_h

#include "../common.h"
#include "../types-struct.h"
#include "../project.h"
#include "vec3.h"
#include "vec4.h"
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
 * @param[in]  pos      point/position in viewport coordinates
 * @param[in]  invMat   matrix (see brief)
 * @param[in]  vp       viewport as [x, y, width, height]
 * @returns             unprojected coordinates
 */
CGLM_DECL
vec3s
glms_unprojecti(vec3s pos, mat4s invMat, vec4s vp) CGLM_ENDD
#ifndef CGLM_LIB
{
  vec3s r;
  glm_unprojecti(pos.raw, invMat.raw, vp.raw, r.raw);
  return r;
}
#endif

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
 * @returns             unprojected coordinates
 */
CGLM_DECL
vec3s
glms_unproject(vec3s pos, mat4s m, vec4s vp) CGLM_ENDD
#ifndef CGLM_LIB
{
  vec3s r;
  glm_unproject(pos.raw, m.raw, vp.raw, r.raw);
  return r;
}
#endif

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
 * @returns projected coordinates
 */
CGLM_DECL
vec3s
glms_project(vec3s pos, mat4s m, vec4s vp) CGLM_ENDD
#ifndef CGLM_LIB
{
  vec3s r;
  glm_project(pos.raw, m.raw, vp.raw, r.raw);
  return r;
}
#endif

#endif /* cglms_projects_h */
