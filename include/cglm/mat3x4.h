/*
 * Copyright (c), Recep Aslantas.
 *
 * MIT License (MIT), http://opensource.org/licenses/MIT
 * Full license can be found in the LICENSE file
 */

/*
 Macros:
   GLM_MAT3X4_ZERO_INIT
   GLM_MAT3X4_ZERO

 Functions:
   CGLM_INLINE void  glm_mat3x4_make(float * restrict src, mat3x4 dest)
 */

#ifndef cglm_mat3x4_h
#define cglm_mat3x4_h

#include "common.h"

#define GLM_MAT3X4_ZERO_INIT {{0.0f, 0.0f, 0.0f, 0.0f}, \
                              {0.0f, 0.0f, 0.0f, 0.0f}, \
                              {0.0f, 0.0f, 0.0f, 0.0f}}

/* for C only */
#define GLM_MAT3X4_ZERO GLM_MAT3X4_ZERO_INIT

/*!
 * @brief copy all members of [mat] to [dest]
 *
 * @param[in]  mat  source
 * @param[out] dest destination
 */
CGLM_INLINE
void
glm_mat3x4_copy(mat3x4 mat, mat3x4 dest) {
  glm_vec4_ucopy(mat[0], dest[0]);
  glm_vec4_ucopy(mat[1], dest[1]);
  glm_vec4_ucopy(mat[2], dest[2]);
}

/*!
 * @brief make given matrix zero.
 *
 * @param[in, out]  mat  matrix
 */
CGLM_INLINE
void
glm_mat3x4_zero(mat3x4 mat) {
  CGLM_ALIGN_MAT mat3x4 t = GLM_MAT3X4_ZERO_INIT;
  glm_mat3x4_copy(t, mat);
}

/*!
 * @brief Create mat3x4 matrix from pointer
 *
 * @param[in]  src  pointer to an array of floats
 * @param[out] dest matrix
 */
CGLM_INLINE
void
glm_mat3x4_make(float * __restrict src, mat3x4 dest) {
  dest[0][0] = src[0];
  dest[0][1] = src[1];
  dest[0][2] = src[2];
  dest[0][3] = src[3];

  dest[1][0] = src[4];
  dest[1][1] = src[5];
  dest[1][2] = src[6];
  dest[1][3] = src[7];

  dest[2][0] = src[8];
  dest[2][1] = src[9];
  dest[2][2] = src[10];
  dest[2][3] = src[11];
}

/*!
 * @brief multiply m1 and m2 to dest
 *
 * m1, m2 and dest matrices can be same matrix, it is possible to write this:
 *
 * @code
 * glm_mat3x4_mul(m, m, m);
 * @endcode
 *
 * @param[in]  m1   left matrix
 * @param[in]  m2   right matrix
 * @param[out] dest destination matrix
 */
CGLM_INLINE
void
glm_mat3x4_mul(mat3x4 m1, mat4x3 m2, mat3 dest) {
  float a00 = m1[0][0], a01 = m1[0][1], a02 = m1[0][2], a03 = m1[0][3],
        a10 = m1[1][0], a11 = m1[1][1], a12 = m1[1][2], a13 = m1[1][3],
        a20 = m1[2][0], a21 = m1[2][1], a22 = m1[2][2], a23 = m1[2][3],

        b00 = m2[0][0], b01 = m2[0][1], b02 = m2[0][2],
        b10 = m2[1][0], b11 = m2[1][1], b12 = m2[1][2],
        b20 = m2[2][0], b21 = m2[2][1], b22 = m2[2][2],
        b30 = m2[3][0], b31 = m2[3][1], b32 = m2[3][2];

  dest[0][0] = a00 * b00 + a01 * b10 + a02 * b20 + a03 * b30;
  dest[0][1] = a00 * b01 + a01 * b11 + a02 * b21 + a03 * b31;
  dest[0][2] = a00 * b02 + a01 * b12 + a02 * b22 + a03 * b32;

  dest[1][0] = a10 * b00 + a11 * b10 + a12 * b20 + a13 * b30;
  dest[1][1] = a10 * b01 + a11 * b11 + a12 * b21 + a13 * b31;
  dest[1][2] = a10 * b02 + a11 * b12 + a12 * b22 + a13 * b32;

  dest[2][0] = a20 * b00 + a21 * b10 + a22 * b20 + a23 * b30;
  dest[2][1] = a20 * b01 + a21 * b11 + a22 * b21 + a23 * b31;
  dest[2][2] = a20 * b02 + a21 * b12 + a22 * b22 + a23 * b32;
}

#endif
