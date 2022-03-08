/*
 * Copyright (c), Recep Aslantas.
 *
 * MIT License (MIT), http://opensource.org/licenses/MIT
 * Full license can be found in the LICENSE file
 */

/*
 Functions:
   CGLM_INLINE void glm_lookat_lh(vec3 eye, vec3 center, vec3 up, mat4 dest)
   CGLM_INLINE void glm_look_lh(vec3 eye, vec3 dir, vec3 up, mat4 dest)
   CGLM_INLINE void glm_look_anyup_lh(vec3 eye, vec3 dir, mat4 dest)
 */

#ifndef cglm_view_lh_h
#define cglm_view_lh_h

#include "../common.h"
#include "../plane.h"

/*!
 * @brief set up view matrix (LH)
 *
 * NOTE: The UP vector must not be parallel to the line of sight from
 *       the eye point to the reference point
 *
 * @param[in]  eye    eye vector
 * @param[in]  center center vector
 * @param[in]  up     up vector
 * @param[out] dest   result matrix
 */
CGLM_INLINE
void
glm_lookat_lh(vec3 eye, vec3 center, vec3 up, mat4 dest) {
  CGLM_ALIGN(8) vec3 f, u, s;

  glm_vec3_sub(center, eye, f);
  glm_vec3_normalize(f);

  glm_vec3_crossn(up, f, s);
  glm_vec3_cross(f, s, u);

  dest[0][0] = s[0];
  dest[0][1] = u[0];
  dest[0][2] = f[0];
  dest[1][0] = s[1];
  dest[1][1] = u[1];
  dest[1][2] = f[1];
  dest[2][0] = s[2];
  dest[2][1] = u[2];
  dest[2][2] = f[2];
  dest[3][0] =-glm_vec3_dot(s, eye);
  dest[3][1] =-glm_vec3_dot(u, eye);
  dest[3][2] =-glm_vec3_dot(f, eye);
  dest[0][3] = dest[1][3] = dest[2][3] = 0.0f;
  dest[3][3] = 1.0f;
}

/*!
 * @brief set up view matrix with left handed coordinate system
 *
 * convenient wrapper for lookat: if you only have direction not target self
 * then this might be useful. Because you need to get target from direction.
 *
 * NOTE: The UP vector must not be parallel to the line of sight from
 *       the eye point to the reference point
 *
 * @param[in]  eye    eye vector
 * @param[in]  dir    direction vector
 * @param[in]  up     up vector
 * @param[out] dest   result matrix
 */
CGLM_INLINE
void
glm_look_lh(vec3 eye, vec3 dir, vec3 up, mat4 dest) {
  CGLM_ALIGN(8) vec3 target;
  glm_vec3_add(eye, dir, target);
  glm_lookat_lh(eye, target, up, dest);
}

/*!
 * @brief set up view matrix with left handed coordinate system
 *
 * convenient wrapper for look: if you only have direction and if you don't
 * care what UP vector is then this might be useful to create view matrix
 *
 * @param[in]  eye    eye vector
 * @param[in]  dir    direction vector
 * @param[out] dest   result matrix
 */
CGLM_INLINE
void
glm_look_anyup_lh(vec3 eye, vec3 dir, mat4 dest) {
  CGLM_ALIGN(8) vec3 up;
  glm_vec3_ortho(dir, up);
  glm_look_lh(eye, dir, up, dest);
}

#endif /*cglm_view_lh_h*/
