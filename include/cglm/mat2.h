/*
 * Copyright (c), Recep Aslantas.
 *
 * MIT License (MIT), http://opensource.org/licenses/MIT
 * Full license can be found in the LICENSE file
 */

/*

 */

#ifndef cglm_mat2_h
#define cglm_mat2_h

#include "common.h"
#include "vec2.h"

#ifdef CGLM_SSE_FP
#  include "simd/sse2/mat2.h"
#endif

#define GLM_MAT2_IDENTITY_INIT  {{1.0f, 0.0f}, {0.0f, 1.0f}}
#define GLM_MAT2_ZERO_INIT      {{0.0f, 0.0f}, {0.0f, 0.0f}}


/* for C only */
#define GLM_MAT2_IDENTITY ((mat3)GLM_MAT2_IDENTITY_INIT)
#define GLM_MAT2_ZERO     ((mat3)GLM_MAT2_ZERO_INIT)

/*!
 * @brief copy all members of [mat] to [dest]
 *
 * @param[in]  mat  source
 * @param[out] dest destination
 */
CGLM_INLINE
void
glm_mat2_copy(mat2 mat, mat2 dest) {
  dest[0][0] = mat[0][0];
  dest[0][1] = mat[0][1];
  dest[1][0] = mat[1][0];
  dest[1][1] = mat[1][1];
}

/*!
 * @brief make given matrix identity. It is identical with below,
 *        but it is more easy to do that with this func especially for members
 *        e.g. glm_mat2_identity(aStruct->aMatrix);
 *
 * @code
 * glm_mat2_copy(GLM_MAT2_IDENTITY, mat); // C only
 *
 * // or
 * mat2 mat = GLM_MAT2_IDENTITY_INIT;
 * @endcode
 *
 * @param[in, out]  mat  destination
 */
CGLM_INLINE
void
glm_mat2_identity(mat2 mat) {
  CGLM_ALIGN_MAT mat2 t = GLM_MAT2_IDENTITY_INIT;
  glm_mat2_copy(t, mat);
}

/*!
 * @brief make given matrix array's each element identity matrix
 *
 * @param[in, out]  mat   matrix array (must be aligned (16/32)
 *                        if alignment is not disabled)
 *
 * @param[in]       count count of matrices
 */
CGLM_INLINE
void
glm_mat2_identity_array(mat2 * __restrict mat, size_t count) {
  CGLM_ALIGN_MAT mat2 t = GLM_MAT2_IDENTITY_INIT;
  size_t i;

  for (i = 0; i < count; i++) {
    glm_mat2_copy(t, mat[i]);
  }
}

/*!
 * @brief make given matrix zero.
 *
 * @param[in, out]  mat  matrix
 */
CGLM_INLINE
void
glm_mat2_zero(mat2 mat) {
  CGLM_ALIGN_MAT mat2 t = GLM_MAT2_ZERO_INIT;
  glm_mat2_copy(t, mat);
}

/*!
 * @brief multiply m1 and m2 to dest
 *
 * m1, m2 and dest matrices can be same matrix, it is possible to write this:
 *
 * @code
 * mat3 m = GLM_MAT3_IDENTITY_INIT;
 * glm_mat3_mul(m, m, m);
 * @endcode
 *
 * @param[in]  m1   left matrix
 * @param[in]  m2   right matrix
 * @param[out] dest destination matrix
 */
CGLM_INLINE
void
glm_mat2_mul(mat2 m1, mat2 m2, mat2 dest) {
#if defined( __SSE__ ) || defined( __SSE2__ )
  glm_mat2_mul_sse2(m1, m2, dest);
#else
  float a00 = m1[0][0], a01 = m1[0][1],
        a10 = m1[1][0], a11 = m1[1][1],
        b00 = m2[0][0], b01 = m2[0][1],
        b10 = m2[1][0], b11 = m2[1][1];

  dest[0][0] = a00 * b00 + a10 * b01;
  dest[0][1] = a01 * b00 + a11 * b01;
  dest[1][0] = a00 * b10 + a10 * b11;
  dest[1][1] = a01 * b10 + a11 * b11;
#endif
}

/*!
 * @brief transpose mat3 and store in dest
 *
 * source matrix will not be transposed unless dest is m
 *
 * @param[in]  m     matrix
 * @param[out] dest  result
 */
CGLM_INLINE
void
glm_mat2_transpose_to(mat2 m, mat2 dest) {
#if defined( __SSE__ ) || defined( __SSE2__ )
  glm_mat2_transp_sse2(m, dest);
#else
  dest[0][0] = m[0][0];
  dest[0][1] = m[1][0];
  dest[1][0] = m[0][1];
  dest[1][1] = m[1][1];
#endif
}

/*!
 * @brief tranpose mat3 and store result in same matrix
 *
 * @param[in, out] m source and dest
 */
CGLM_INLINE
void
glm_mat2_transpose(mat2 m) {
  float tmp;
  tmp     = m[0][1];
  m[0][1] = m[1][0];
  m[1][0] = tmp;
}
#endif /* cglm_mat2_h */
