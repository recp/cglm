/*
 * Copyright (c), Recep Aslantas.
 *
 * MIT License (MIT), http://opensource.org/licenses/MIT
 * Full license can be found in the LICENSE file
 */

/*
 Functions:
   CGLM_INLINE void glm_lookat_lh_no(vec3 eye, vec3 center, vec3 up, mat4 dest)
   CGLM_INLINE void glm_look_lh_no(vec3 eye, vec3 dir, vec3 up, mat4 dest)
   CGLM_INLINE void glm_look_anyup_lh_no(vec3 eye, vec3 dir, mat4 dest)
 */

#ifndef cglm_view_lh_no_h
#define cglm_view_lh_no_h

#include "../common.h"
#include "view_lh.h"

/*!
 * @brief set up view matrix with left handed coordinate system.
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
glm_lookat_lh_no(vec3 eye, vec3 center, vec3 up, mat4 dest) {
  glm_lookat_lh(eye, center, up, dest);
}

/*!
 * @brief set up view matrix with left handed coordinate system.
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
glm_look_lh_no(vec3 eye, vec3 dir, vec3 up, mat4 dest) {
  glm_look_lh(eye, dir, up, dest);
}

/*!
 * @brief set up view matrix with left handed coordinate system.
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
glm_look_anyup_lh_no(vec3 eye, vec3 dir, mat4 dest) {
  glm_look_anyup_lh(eye, dir, dest);
}

#endif /*cglm_view_lh_no_h*/
