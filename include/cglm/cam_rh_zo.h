/*
 * Copyright (c), Recep Aslantas.
 *
 * MIT License (MIT), http://opensource.org/licenses/MIT
 * Full license can be found in the LICENSE file
 */

/*
 Functions:
   CGLM_INLINE void  glm_perspective_rh_zo(float fovy,
                                           float aspect,
                                           float nearVal,
                                           float farVal,
                                           mat4  dest)
 */

#ifndef cglm_cam_rh_zo_h
#define cglm_cam_rh_zo_h

#include "common.h"
#include "plane.h"

/*!
 * @brief set up perspective projection matrix with a right-hand coordinate
 * system (suitable for Vulkan) and a clip-space with depth values from zero
 * to one.
 *
 * https://github.com/godlikepanos/anki-3d-engine/blob/317cb379ff3a7b09f9034f49c7bdab0f96a1c0b3/AnKi/Math/Mat.h#L1254
 *
 * @param[in]  fovy    field of view angle
 * @param[in]  aspect  aspect ratio ( width / height )
 * @param[in]  nearVal near clipping plane
 * @param[in]  farVal  far clipping planes
 * @param[out] dest    result matrix
 */
CGLM_INLINE
void
glm_perspective_rh_zo(float fovy,
                      float aspect,
                      float nearVal,
                      float farVal,
                      mat4  dest) {
  /* Impl follows glm::perspectiveRH_ZO in glm/ext/matrix_clip_space.inl */
  float fl, fn;

  glm_mat4_zero(dest);

  fl = 1.0f / tanf(fovy * 0.5f);
  fn = 1.0f / (farVal - nearVal);

  dest[0][0] = fl / aspect;
  dest[1][1] = fl;
  dest[2][2] = -farVal * fn;
  dest[2][3] = -1.0f;
  dest[3][2] = -farVal * nearVal * fn;
}

#endif /*cglm_cam_lh_zo_h*/
