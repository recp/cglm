/*
 * Copyright (c), Recep Aslantas.
 *
 * MIT License (MIT), http://opensource.org/licenses/MIT
 * Full license can be found in the LICENSE file
 */

/*
 Functions:
   CGLM_INLINE void glm_ortho_lh_zo(float left,    float right,
                                    float bottom,  float top,
                                    float nearZ, float farZ,
                                    mat4  dest)
   CGLM_INLINE void glm_ortho_aabb_lh_zo(vec3 box[2], mat4 dest)
   CGLM_INLINE void glm_ortho_aabb_p_lh_zo(vec3 box[2],
                                           float padding,
                                           mat4 dest)
   CGLM_INLINE void glm_ortho_aabb_pz_lh_zo(vec3 box[2],
                                            float padding,
                                            mat4 dest)
   CGLM_INLINE void glm_ortho_default_lh_zo(float aspect,
                                            mat4 dest)
   CGLM_INLINE void glm_ortho_default_s_lh_zo(float aspect,
                                              float size,
                                              mat4 dest)
 */

#ifndef cglm_ortho_lh_zo_h
#define cglm_ortho_lh_zo_h

#include "../common.h"
#include "../plane.h"
#include "../mat4.h"

/*!
 * @brief set up orthographic projection matrix with a left-hand coordinate
 *        system and a clip-space of [0, 1].
 *
 * @param[in]  left    viewport.left
 * @param[in]  right   viewport.right
 * @param[in]  bottom  viewport.bottom
 * @param[in]  top     viewport.top
 * @param[in]  nearZ   near clipping plane
 * @param[in]  farZ    far clipping plane
 * @param[out] dest    result matrix
 */
CGLM_INLINE
void
glm_ortho_lh_zo(float left,    float right,
                float bottom,  float top,
                float nearZ, float farZ,
                mat4  dest) {
  float rl, tb, fn;

  glm_mat4_zero(dest);

  rl = 1.0f / (right  - left);
  tb = 1.0f / (top    - bottom);
  fn =-1.0f / (farZ - nearZ);

  dest[0][0] = 2.0f * rl;
  dest[1][1] = 2.0f * tb;
  dest[2][2] =-fn;
  dest[3][0] =-(right  + left)    * rl;
  dest[3][1] =-(top    + bottom)  * tb;
  dest[3][2] = nearZ * fn;
  dest[3][3] = 1.0f;
}

/*!
 * @brief set up orthographic projection matrix using bounding box
 *        with a left-hand coordinate system and a clip-space of [0, 1].
 *
 * bounding box (AABB) must be in view space
 *
 * @param[in]  box   AABB
 * @param[out] dest  result matrix
 */
CGLM_INLINE
void
glm_ortho_aabb_lh_zo(vec3 box[2], mat4 dest) {
  glm_ortho_lh_zo(box[0][0],  box[1][0],
                  box[0][1],  box[1][1],
                 -box[1][2], -box[0][2],
                  dest);
}

/*!
 * @brief set up orthographic projection matrix using bounding box
 *        with a left-hand coordinate system and a clip-space of [0, 1].
 *
 * bounding box (AABB) must be in view space
 *
 * @param[in]  box     AABB
 * @param[in]  padding padding
 * @param[out] dest    result matrix
 */
CGLM_INLINE
void
glm_ortho_aabb_p_lh_zo(vec3 box[2], float padding, mat4 dest) {
  glm_ortho_lh_zo(box[0][0] - padding,    box[1][0] + padding,
                  box[0][1] - padding,    box[1][1] + padding,
                -(box[1][2] + padding), -(box[0][2] - padding),
                  dest);
}

/*!
 * @brief set up orthographic projection matrix using bounding box
 *        with a left-hand coordinate system and a clip-space of [0, 1].
 *
 * bounding box (AABB) must be in view space
 *
 * @param[in]  box     AABB
 * @param[in]  padding padding for near and far
 * @param[out] dest    result matrix
 */
CGLM_INLINE
void
glm_ortho_aabb_pz_lh_zo(vec3 box[2], float padding, mat4 dest) {
  glm_ortho_lh_zo(box[0][0],              box[1][0],
                  box[0][1],              box[1][1],
                -(box[1][2] + padding), -(box[0][2] - padding),
                  dest);
}

/*!
 * @brief set up unit orthographic projection matrix
 *        with a left-hand coordinate system and a clip-space of [0, 1].
 *
 * @param[in]  aspect aspect ration ( width / height )
 * @param[out] dest   result matrix
 */
CGLM_INLINE
void
glm_ortho_default_lh_zo(float aspect, mat4 dest) {
  if (aspect >= 1.0f) {
    glm_ortho_lh_zo(-aspect, aspect, -1.0f, 1.0f, -100.0f, 100.0f, dest);
    return;
  }

  aspect = 1.0f / aspect;

  glm_ortho_lh_zo(-1.0f, 1.0f, -aspect, aspect, -100.0f, 100.0f, dest);
}

/*!
 * @brief set up orthographic projection matrix with given CUBE size
 *        with a left-hand coordinate system and a clip-space of [0, 1].
 *
 * @param[in]  aspect aspect ratio ( width / height )
 * @param[in]  size   cube size
 * @param[out] dest   result matrix
 */
CGLM_INLINE
void
glm_ortho_default_s_lh_zo(float aspect, float size, mat4 dest) {
  if (aspect >= 1.0f) {
    glm_ortho_lh_zo(-size * aspect,
                     size * aspect,
                    -size,
                     size,
                    -size - 100.0f,
                     size + 100.0f,
                     dest);
    return;
  }

  glm_ortho_lh_zo(-size,
                   size,
                  -size / aspect,
                   size / aspect,
                  -size - 100.0f,
                   size + 100.0f,
                   dest);
}

#endif /*cglm_ortho_lh_zo_h*/
