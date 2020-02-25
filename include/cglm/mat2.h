/*
 * Copyright (c), Recep Aslantas.
 *
 * MIT License (MIT), http://opensource.org/licenses/MIT
 * Full license can be found in the LICENSE file
 */

/*
 Macros:
   GLM_MAT2_IDENTITY_INIT
   GLM_MAT2_ZERO_INIT
   GLM_MAT2_IDENTITY
   GLM_MAT2_ZERO

 Functions:
   CGLM_INLINE void  glm_mat2_copy(mat2 mat, mat2 dest)
   CGLM_INLINE void  glm_mat2_identity(mat2 mat)
   CGLM_INLINE void  glm_mat2_identity_array(mat2 * restrict mat, size_t count)
   CGLM_INLINE void  glm_mat2_zero(mat2 mat)
   CGLM_INLINE void  glm_mat2_mul(mat2 m1, mat2 m2, mat2 dest)
   CGLM_INLINE void  glm_mat2_transpose_to(mat2 m, mat2 dest)
   CGLM_INLINE void  glm_mat2_transpose(mat2 m)
   CGLM_INLINE void  glm_mat2_mulv(mat2 m, vec2 v, vec2 dest)
   CGLM_INLINE float glm_mat2_trace(mat2 m)
   CGLM_INLINE void  glm_mat2_scale(mat2 m, float s)
   CGLM_INLINE float glm_mat2_det(mat2 mat)
   CGLM_INLINE void  glm_mat2_inv(mat2 mat, mat2 dest)
   CGLM_INLINE void  glm_mat2_swap_col(mat2 mat, int col1, int col2)
   CGLM_INLINE void  glm_mat2_swap_row(mat2 mat, int row1, int row2)
   CGLM_INLINE float glm_mat2_rmc(vec2 r, mat2 m, vec2 c)
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
#define GLM_MAT2_IDENTITY ((mat2)GLM_MAT2_IDENTITY_INIT)
#define GLM_MAT2_ZERO     ((mat2)GLM_MAT2_ZERO_INIT)

/*!
 * @brief copy all members of [mat] to [dest]
 *
 * @param[in]  mat  source
 * @param[out] dest destination
 */
CGLM_INLINE
void
glm_mat2_copy(mat2 mat, mat2 dest) {
  glm_vec4_copy(mat[0], dest[0]);
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
 * @param[in, out]  mat   matrix array (must be aligned (16)
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
 * mat2 m = GLM_MAT2_IDENTITY_INIT;
 * glm_mat2_mul(m, m, m);
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
 * @brief transpose mat2 and store in dest
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
 * @brief tranpose mat2 and store result in same matrix
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

/*!
 * @brief multiply mat2 with vec2 (column vector) and store in dest vector
 *
 * @param[in]  m    mat2 (left)
 * @param[in]  v    vec2 (right, column vector)
 * @param[out] dest vec2 (result, column vector)
 */
CGLM_INLINE
void
glm_mat2_mulv(mat2 m, vec2 v, vec2 dest) {
  dest[0] = m[0][0] * v[0] + m[1][0] * v[1];
  dest[1] = m[0][1] * v[0] + m[1][1] * v[1];
}

/*!
 * @brief trace of matrix
 *
 * sum of the elements on the main diagonal from upper left to the lower right
 *
 * @param[in]  m matrix
 */
CGLM_INLINE
float
glm_mat2_trace(mat2 m) {
  return m[0][0] + m[1][1];
}

/*!
 * @brief scale (multiply with scalar) matrix
 *
 * multiply matrix with scalar
 *
 * @param[in, out] m matrix
 * @param[in]      s scalar
 */
CGLM_INLINE
void
glm_mat2_scale(mat2 m, float s) {
  glm_vec4_scale(m[0], s, m[0]);
}

/*!
 * @brief mat2 determinant
 *
 * @param[in] mat matrix
 *
 * @return determinant
 */
CGLM_INLINE
float
glm_mat2_det(mat2 mat) {
  return mat[0][0] * mat[1][1] - mat[1][0] * mat[0][1];
}

/*!
 * @brief inverse mat2 and store in dest
 *
 * @param[in]  mat  matrix
 * @param[out] dest inverse matrix
 */
CGLM_INLINE
void
glm_mat2_inv(mat2 mat, mat2 dest) {
  float det;
  float a = mat[0][0], b = mat[0][1],
        c = mat[1][0], d = mat[1][1];

  det = 1.0f / (a * d - b * c);

  dest[0][0] =  d * det;
  dest[0][1] = -b * det;
  dest[1][0] = -c * det;
  dest[1][1] =  a * det;
}

/*!
 * @brief swap two matrix columns
 *
 * @param[in,out] mat  matrix
 * @param[in]     col1 col1
 * @param[in]     col2 col2
 */
CGLM_INLINE
void
glm_mat2_swap_col(mat2 mat, int col1, int col2) {
  float a, b;

  a = mat[col1][0];
  b = mat[col1][1];

  mat[col1][0] = mat[col2][0];
  mat[col1][1] = mat[col2][1];

  mat[col2][0] = a;
  mat[col2][1] = b;
}

/*!
 * @brief swap two matrix rows
 *
 * @param[in,out] mat  matrix
 * @param[in]     row1 row1
 * @param[in]     row2 row2
 */
CGLM_INLINE
void
glm_mat2_swap_row(mat2 mat, int row1, int row2) {
  float a, b;

  a = mat[0][row1];
  b = mat[1][row1];

  mat[0][row1] = mat[0][row2];
  mat[1][row1] = mat[1][row2];

  mat[0][row2] = a;
  mat[1][row2] = b;
}

/*!
 * @brief helper for  R (row vector) * M (matrix) * C (column vector)
 *
 * rmc stands for Row * Matrix * Column
 *
 * the result is scalar because R * M = Matrix1x2 (row vector),
 * then Matrix1x2 * Vec2 (column vector) = Matrix1x1 (Scalar)
 *
 * @param[in]  r   row vector or matrix1x2
 * @param[in]  m   matrix2x2
 * @param[in]  c   column vector or matrix2x1
 *
 * @return scalar value e.g. Matrix1x1
 */
CGLM_INLINE
float
glm_mat2_rmc(vec2 r, mat2 m, vec2 c) {
  vec2 tmp;
  glm_mat2_mulv(m, c, tmp);
  return glm_vec2_dot(r, tmp);
}

#endif /* cglm_mat2_h */
