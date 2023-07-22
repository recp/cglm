/*
 * Copyright (c), Recep Aslantas.
 *
 * MIT License (MIT), http://opensource.org/licenses/MIT
 * Full license can be found in the LICENSE file
 */

/*
 Macros:
   GLM_MAT4X2_ZERO_INIT
   GLM_MAT4X2_ZERO

 Functions:
   CGLM_INLINE void  glm_mat4x2_make(float * restrict src, mat4x2 dest)
 */

#ifndef cglm_mat4x2_h
#define cglm_mat4x2_h

#include "common.h"

#define GLM_MAT4X2_ZERO_INIT {{0.0f, 0.0f}, {0.0f, 0.0f}, {0.0f, 0.0f}, {0.0f, 0.0f}}

/* for C only */
#define GLM_MAT4X2_ZERO GLM_MAT4X2_ZERO_INIT

/*!
 * @brief copy all members of [mat] to [dest]
 *
 * @param[in]  mat  source
 * @param[out] dest destination
 */
CGLM_INLINE
void
glm_mat4x2_copy(mat4x2 mat, mat4x2 dest) {
  dest[0][0] = mat[0][0];
  dest[0][1] = mat[0][1];

  dest[1][0] = mat[1][0];
  dest[1][1] = mat[1][1];

  dest[2][0] = mat[2][0];
  dest[2][1] = mat[2][1];

  dest[3][0] = mat[3][0];
  dest[3][1] = mat[3][1];
}

/*!
 * @brief make given matrix zero.
 *
 * @param[in, out]  mat  matrix
 */
CGLM_INLINE
void
glm_mat4x2_zero(mat4x2 mat) {
  CGLM_ALIGN_MAT mat4x2 t = GLM_MAT4X2_ZERO_INIT;
  glm_mat4x2_copy(t, mat);
}

/*!
 * @brief Create mat4x2 matrix from pointer
 *
 * @param[in]  src  pointer to an array of floats
 * @param[out] dest matrix
 */
CGLM_INLINE
void
glm_mat4x2_make(float * __restrict src, mat4x2 dest) {
  dest[0][0] = src[0];
  dest[0][1] = src[1];

  dest[1][0] = src[2];
  dest[1][1] = src[3];

  dest[2][0] = src[4];
  dest[2][1] = src[5];

  dest[3][0] = src[6];
  dest[3][1] = src[7];
}

/*!
 * @brief multiply m1 and m2 to dest
 *
 * m1, m2 and dest matrices can be same matrix, it is possible to write this:
 *
 * @code
 * glm_mat4x2_mul(m, m, m);
 * @endcode
 *
 * @param[in]  m1   left matrix
 * @param[in]  m2   right matrix
 * @param[out] dest destination matrix
 */
CGLM_INLINE
void
glm_mat4x2_mul(mat4x2 m1, mat2x4 m2, mat4 dest) {
  float a00 = m1[0][0], a01 = m1[0][1],
        a10 = m1[1][0], a11 = m1[1][1],
        a20 = m1[2][0], a21 = m1[2][1],
        a30 = m1[3][0], a31 = m1[3][1],

        b00 = m2[0][0], b01 = m2[0][1], b02 = m2[0][2], b03 = m2[0][3],
        b10 = m2[1][0], b11 = m2[1][1], b12 = m2[1][2], b13 = m2[1][3];

  dest[0][0] = a00 * b00 + a10 * b10;
  dest[0][1] = a00 * b01 + a10 * b11;
  dest[0][2] = a00 * b02 + a10 * b12;
  dest[0][3] = a00 * b03 + a10 * b13;

  dest[1][0] = a01 * b00 + a11 * b10;
  dest[1][1] = a01 * b01 + a11 * b11;
  dest[1][2] = a01 * b02 + a11 * b12;
  dest[1][3] = a01 * b03 + a11 * b13;

  dest[2][0] = a20 * b00 + a21 * b10;
  dest[2][1] = a20 * b01 + a21 * b11;
  dest[2][2] = a20 * b02 + a21 * b12;
  dest[2][3] = a20 * b03 + a21 * b13;

  dest[3][0] = a30 * b00 + a31 * b10;
  dest[3][1] = a30 * b01 + a31 * b11;
  dest[3][2] = a30 * b02 + a31 * b12;
  dest[3][3] = a30 * b03 + a31 * b13;
}

#endif
