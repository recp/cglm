/*
 * Copyright (c), Recep Aslantas.
 *
 * MIT License (MIT), http://opensource.org/licenses/MIT
 * Full license can be found in the LICENSE file
 */

/*
 Functions:
   CGLM_INLINE void  glm_persp_decomp_far(mat4 proj, float *farZ)
   CGLM_INLINE float glm_persp_fovy(mat4 proj)
   CGLM_INLINE float glm_persp_aspect(mat4 proj)
   CGLM_INLINE void  glm_persp_sizes(mat4 proj, float fovy, vec4 dest)
 */

#ifndef cglm_persp_h
#define cglm_persp_h

#include "../common.h"
#include "../plane.h"
#include "../mat4.h"

/*!
 * @brief returns field of view angle along the Y-axis (in radians)
 *
 * if you need to degrees, use glm_deg to convert it or use this:
 * fovy_deg = glm_deg(glm_persp_fovy(projMatrix))
 *
 * @param[in] proj perspective projection matrix
 */
CGLM_INLINE
float
glm_persp_fovy(mat4 proj) {
  return 2.0f * atanf(1.0f / proj[1][1]);
}

/*!
 * @brief returns aspect ratio of perspective projection
 *
 * @param[in] proj perspective projection matrix
 */
CGLM_INLINE
float
glm_persp_aspect(mat4 proj) {
  return proj[1][1] / proj[0][0];
}

#endif /* cglm_persp_h */
