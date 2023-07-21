/*
 * Copyright (c), Recep Aslantas.
 *
 * MIT License (MIT), http://opensource.org/licenses/MIT
 * Full license can be found in the LICENSE file
 */

/*
 Macros:
   GLM_MAT2X3_ZERO_INIT
   GLM_MAT2X3_ZERO

 Functions:
   CGLM_INLINE void  glm_mat2x3_make(float * restrict src, mat2x3 dest)
 */

#ifndef cglm_mat2x3_h
#define cglm_mat2x3_h

#include "common.h"

#define GLM_MAT2X3_ZERO_INIT {{0.0f, 0.0f, 0.0f}, {0.0f, 0.0f, 0.0f}}

/* for C only */
#define GLM_MAT2X3_ZERO GLM_MAT2X3_ZERO_INIT

/*!
 * @brief copy all members of [mat] to [dest]
 *
 * @param[in]  mat  source
 * @param[out] dest destination
 */
CGLM_INLINE
void
glm_mat2x3_copy(mat2x3 mat, mat2x3 dest) {
  dest[0][0] = mat[0][0];
  dest[0][1] = mat[0][1];
  dest[0][2] = mat[0][2];

  dest[1][0] = mat[1][0];
  dest[1][1] = mat[1][1];
  dest[1][2] = mat[1][2];
}

/*!
 * @brief make given matrix zero.
 *
 * @param[in, out]  mat  matrix
 */
CGLM_INLINE
void
glm_mat2x3_zero(mat2x3 mat) {
  CGLM_ALIGN_MAT mat2x3 t = GLM_MAT2X3_ZERO_INIT;
  glm_mat2x3_copy(t, mat);
}

/*!
 * @brief Create mat2x3 matrix from pointer
 *
 * @param[in]  src  pointer to an array of floats
 * @param[out] dest matrix
 */
CGLM_INLINE
void
glm_mat2x3_make(float * __restrict src, mat2x3 dest) {
  dest[0][0] = src[0];
  dest[0][1] = src[1];
  dest[0][2] = src[2];

  dest[1][0] = src[3];
  dest[1][1] = src[4];
  dest[1][2] = src[5];
}

#endif
