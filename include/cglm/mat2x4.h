/*
 * Copyright (c), Recep Aslantas.
 *
 * MIT License (MIT), http://opensource.org/licenses/MIT
 * Full license can be found in the LICENSE file
 */

/*
 Macros:
   GLM_MAT2X4_ZERO_INIT
   GLM_MAT2X4_ZERO

 Functions:
   CGLM_INLINE void  glm_mat2x4_make(float * restrict src, mat2x4 dest)
 */

#ifndef cglm_mat2x4_h
#define cglm_mat2x4_h

#include "common.h"

#define GLM_MAT2X4_ZERO_INIT {{0.0f, 0.0f, 0.0f, 0.0f}, {0.0f, 0.0f, 0.0f, 0.0f}}

/* for C only */
#define GLM_MAT2X4_ZERO GLM_MAT2X4_ZERO_INIT

/*!
 * @brief Create mat2x4 matrix from pointer
 *
 * @param[in]  src  pointer to an array of floats
 * @param[out] dest matrix
 */
CGLM_INLINE
void
glm_mat2x4_make(float * __restrict src, mat2x4 dest) {
  dest[0][0] = src[0];
  dest[0][1] = src[1];
  dest[0][2] = src[2];
  dest[0][3] = src[3];

  dest[1][0] = src[4];
  dest[1][1] = src[5];
  dest[1][2] = src[6];
  dest[1][3] = src[7];
}

#endif
