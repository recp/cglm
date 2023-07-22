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
#include "vec4.h"

#define GLM_MAT2X4_ZERO_INIT {{0.0f, 0.0f, 0.0f, 0.0f}, {0.0f, 0.0f, 0.0f, 0.0f}}

/* for C only */
#define GLM_MAT2X4_ZERO GLM_MAT2X4_ZERO_INIT

/*!
 * @brief copy all members of [mat] to [dest]
 *
 * @param[in]  mat  source
 * @param[out] dest destination
 */
CGLM_INLINE
void
glm_mat2x4_copy(mat2x4 mat, mat2x4 dest) {
  glm_vec4_ucopy(mat[0], dest[0]);
  glm_vec4_ucopy(mat[1], dest[1]);
}

/*!
 * @brief make given matrix zero.
 *
 * @param[in, out]  mat  matrix
 */
CGLM_INLINE
void
glm_mat2x4_zero(mat2x4 mat) {
  CGLM_ALIGN_MAT mat2x4 t = GLM_MAT2X4_ZERO_INIT;
  glm_mat2x4_copy(t, mat);
}

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

/*!
 * @brief multiply m1 and m2 to dest
 *
 * m1, m2 and dest matrices can be same matrix, it is possible to write this:
 *
 * @code
 * glm_mat2x4_mul(m, m, m);
 * @endcode
 *
 * @param[in]  m1   left matrix
 * @param[in]  m2   right matrix
 * @param[out] dest destination matrix
 */
CGLM_INLINE
void
glm_mat2x4_mul(mat2x4 m1, mat4x2 m2, mat2 dest) {
  float a00 = m1[0][0], a01 = m1[0][1],
        a10 = m1[1][0], a11 = m1[1][1],
        a20 = m1[2][0], a21 = m1[2][1],
        a30 = m1[3][0], a31 = m1[3][1],

        b00 = m2[0][0], b01 = m2[0][1],
        b10 = m2[1][0], b11 = m2[1][1],
        b20 = m2[2][0], b21 = m2[2][1],
        b30 = m2[3][0], b31 = m2[3][1];

  dest[0][0] = a00 * b00 + a10 * b01 + a20 * b20 + a30 * b30;
  dest[0][1] = a00 * b10 + a10 * b11 + a20 * b21 + a30 * b31;
  dest[1][0] = a01 * b00 + a11 * b01 + a21 * b20 + a31 * b30;
  dest[1][1] = a01 * b10 + a11 * b11 + a21 * b21 + a31 * b31;
}

#endif
