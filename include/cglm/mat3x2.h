/*
 * Copyright (c), Recep Aslantas.
 *
 * MIT License (MIT), http://opensource.org/licenses/MIT
 * Full license can be found in the LICENSE file
 */

/*
 Macros:
   GLM_MAT3X2_ZERO_INIT
   GLM_MAT3X2_ZERO

 Functions:
   CGLM_INLINE void  glm_mat3x2_make(float * restrict src, mat3x2 dest)
 */

#ifndef cglm_mat3x2_h
#define cglm_mat3x2_h

#include "common.h"

#define GLM_MAT3X2_ZERO_INIT {{0.0f, 0.0f}, {0.0f, 0.0f}, {0.0f, 0.0f}}

/* for C only */
#define GLM_MAT3X2_ZERO GLM_MAT3X2_ZERO_INIT

/*!
 * @brief Create mat3x2 matrix from pointer
 *
 * @param[in]  src  pointer to an array of floats
 * @param[out] dest matrix
 */
CGLM_INLINE
void
glm_mat3x2_make(float * __restrict src, mat3x2 dest) {
  dest[0][0] = src[0];
  dest[0][1] = src[1];

  dest[1][0] = src[2];
  dest[1][1] = src[3];

  dest[2][0] = src[4];
  dest[2][1] = src[5];
}

#endif
