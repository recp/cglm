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
   CGLM_INLINE void  glm_mat2_make(float * restrict src, mat2 dest)
   CGLM_INLINE void  glm_mat2_copy(mat2 mat, mat2 dest)
   CGLM_INLINE void  glm_mat2_identity(mat2 m)
   CGLM_INLINE void  glm_mat2_identity_array(mat2 * restrict mats, size_t count)
   CGLM_INLINE void  glm_mat2_zero(mat2 m)
   CGLM_INLINE void  glm_mat2_mul(mat2 m1, mat2 m2, mat2 dest)
   CGLM_INLINE void  glm_mat2_mulv(mat2 m, vec2 v, vec2 dest)
   CGLM_INLINE void  glm_mat2_transpose_to(mat2 mat, mat2 dest)
   CGLM_INLINE void  glm_mat2_transpose(mat2 m)
   CGLM_INLINE void  glm_mat2_scale(mat2 m, float s)
   CGLM_INLINE void  glm_mat2_inv(mat2 mat, mat2 dest)
   CGLM_INLINE void  glm_mat2_swap_col(mat2 mat, int col1, int col2)
   CGLM_INLINE void  glm_mat2_swap_row(mat2 mat, int row1, int row2)
   CGLM_INLINE float glm_mat2_det(mat2 m)
   CGLM_INLINE float glm_mat2_trace(mat2 m)
   CGLM_INLINE float glm_mat2_rmc(vec2 r, mat2 m, vec2 c)
 */

#ifndef cglm_mat2_h
#define cglm_mat2_h

#include "common.h"
#include "vec2.h"

#ifdef CGLM_SSE_FP
#  include "simd/sse2/mat2.h"
#endif

#ifdef CGLM_NEON_FP
#  include "simd/neon/mat2.h"
#endif

#ifdef CGLM_SIMD_WASM
#  include "simd/wasm/mat2.h"
#endif

#define GLM_MAT2_IDENTITY_INIT  {{1.0f, 0.0f}, {0.0f, 1.0f}}
#define GLM_MAT2_ZERO_INIT      {{0.0f, 0.0f}, {0.0f, 0.0f}}

/* for C only */
#define GLM_MAT2_IDENTITY ((mat2)GLM_MAT2_IDENTITY_INIT)
#define GLM_MAT2_ZERO     ((mat2)GLM_MAT2_ZERO_INIT)

/*!
 * @brief Create mat2 (dest) from pointer (src).
 *
 * @param[in]  src  pointer to an array of floats (left)
 * @param[out] dest destination (result, mat2)
 */
CGLM_INLINE
void
glm_mat2_make(const float * __restrict src, mat2 dest) {
  dest[0][0] = src[0];
  dest[0][1] = src[1];
  dest[1][0] = src[2];
  dest[1][1] = src[3];
}

/*!
 * @brief Copy mat2 (mat) to mat2 (dest).
 *
 * @param[in]  mat  mat2 (left, src)
 * @param[out] dest destination (result, mat2)
 */
CGLM_INLINE
void
glm_mat2_copy(mat2 mat, mat2 dest) {
  glm_vec4_ucopy(mat[0], dest[0]);
}

/*!
 * @brief Copy a mat2 identity to mat2 (m), or makes mat2 (m) an identity.
 *
 *        The same thing may be achieved with either of bellow methods,
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
 * @param[in, out] m mat2 (src, dest)
 */
CGLM_INLINE
void
glm_mat2_identity(mat2 m) {
  CGLM_ALIGN_MAT mat2 t = GLM_MAT2_IDENTITY_INIT;
  glm_mat2_copy(t, m);
}

/*!
 * @brief Given an array of mat2’s (mats) make each matrix an identity matrix.
 *
 * @param[in, out] mats Array of mat2’s (must be aligned (16/32) if alignment is not disabled)
 * @param[in]      count Array size of mats or number of matrices
 */
CGLM_INLINE
void
glm_mat2_identity_array(mat2 * __restrict mats, size_t count) {
  CGLM_ALIGN_MAT mat2 t = GLM_MAT2_IDENTITY_INIT;
  size_t i;

  for (i = 0; i < count; i++) {
    glm_mat2_copy(t, mats[i]);
  }
}

/*!
 * @brief Zero out the mat2 (m).
 *
 * @param[in, out] m mat2 (src, dest)
 */
CGLM_INLINE
void
glm_mat2_zero(mat2 m) {
  CGLM_ALIGN_MAT mat2 t = GLM_MAT2_ZERO_INIT;
  glm_mat2_copy(t, m);
}

/*!
 * @brief Multiply mat2 (m1) by mat2 (m2) and store in mat2 (dest).
 *
 *        m1, m2 and dest matrices can be same matrix, it is possible to write this: 
 *
 * @code
 * mat2 m = GLM_MAT2_IDENTITY_INIT;
 * glm_mat2_mul(m, m, m);
 * @endcode
 *
 * @param[in]  m1   mat2 (left)
 * @param[in]  m2   mat2 (right)
 * @param[out] dest destination (result, mat2)
 */
CGLM_INLINE
void
glm_mat2_mul(mat2 m1, mat2 m2, mat2 dest) {
#if defined(__wasm__) && defined(__wasm_simd128__)
  glm_mat2_mul_wasm(m1, m2, dest);
#elif defined( __SSE__ ) || defined( __SSE2__ )
  glm_mat2_mul_sse2(m1, m2, dest);
#elif defined(CGLM_NEON_FP)
  glm_mat2_mul_neon(m1, m2, dest);
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
 * @brief Multiply mat2 (m) by vec2 (v) and store in vec2 (dest).
 *
 * @param[in]  m    mat2 (left)
 * @param[in]  v    vec2 (right, column vector)
 * @param[out] dest destination (result, column vector)
 */
CGLM_INLINE
void
glm_mat2_mulv(mat2 m, vec2 v, vec2 dest) {
  dest[0] = m[0][0] * v[0] + m[1][0] * v[1];
  dest[1] = m[0][1] * v[0] + m[1][1] * v[1];
}

/*!
 * @brief Transpose mat2 (mat) and store in mat2 (dest).
 *
 * @param[in]  mat  mat2 (left, src)
 * @param[out] dest destination (result, mat2)
 */
CGLM_INLINE
void
glm_mat2_transpose_to(mat2 mat, mat2 dest) {
#if defined(__wasm__) && defined(__wasm_simd128__)
  glm_mat2_transp_wasm(mat, dest);
#elif defined( __SSE__ ) || defined( __SSE2__ )
  glm_mat2_transp_sse2(mat, dest);
#else
  dest[0][0] = mat[0][0];
  dest[0][1] = mat[1][0];
  dest[1][0] = mat[0][1];
  dest[1][1] = mat[1][1];
#endif
}

/*!
 * @brief Transpose mat2 (m) and store result in the same matrix.
 *
 * @param[in, out] m mat2 (src, dest)
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
 * @brief Multiply mat2 (m) by scalar constant (s).
 *
 * @param[in, out] m mat2 (src, dest)
 * @param[in]      s float (scalar)
 */
CGLM_INLINE
void
glm_mat2_scale(mat2 m, float s) {
#if defined(__wasm__) && defined(__wasm_simd128__)
  glmm_store(m[0], wasm_f32x4_mul(wasm_v128_load(m[0]),
                                  wasm_f32x4_splat(s)));
#elif defined( __SSE__ ) || defined( __SSE2__ )
  glmm_store(m[0], _mm_mul_ps(_mm_loadu_ps(m[0]), glmm_set1(s)));
#elif defined(CGLM_NEON_FP)
  vst1q_f32(m[0], vmulq_f32(vld1q_f32(m[0]), vdupq_n_f32(s)));
#else
  m[0][0] = m[0][0] * s;
  m[0][1] = m[0][1] * s;
  m[1][0] = m[1][0] * s;
  m[1][1] = m[1][1] * s;
#endif
}

/*!
 * @brief Inverse mat2 (mat) and store in mat2 (dest).
 *
 * @param[in]  mat  mat2 (left, src)
 * @param[out] dest destination (result, inverse mat2)
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
 * @brief Swap two columns in mat2 (mat) and store in same matrix.
 *
 * @param[in, out] mat  mat2 (src, dest)
 * @param[in]      col1 Column 1 array index
 * @param[in]      col2 Column 2 array index
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
 * @brief Swap two rows in mat2 (mat) and store in same matrix.
 *
 * @param[in, out] mat  mat2 (src, dest)
 * @param[in]      row1 Row 1 array index
 * @param[in]      row2 Row 2 array index
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
 * @brief Returns mat2 determinant.
 *
 * @param[in] m mat2 (src)
 *
 * @return[out] mat2 determinant (float)
 */
CGLM_INLINE
float
glm_mat2_det(mat2 m) {
  return m[0][0] * m[1][1] - m[1][0] * m[0][1];
}

/*!
 * @brief Returns trace of matrix. Which is:
 *
 *        The sum of the elements on the main diagonal from
 *        upper left corner to the bottom right corner.
 *
 * @param[in] m mat2 (src)
 *
 * @return[out] mat2 trace (float)
 */
CGLM_INLINE
float
glm_mat2_trace(mat2 m) {
  return m[0][0] + m[1][1];
}

/*!
 * @brief Helper for  R (row vector) * M (matrix) * C (column vector)
 *
 *        rmc stands for Row * Matrix * Column
 *
 *        the result is scalar because M * C = ResC (1x2, column vector),
 *        then if you take the dot_product(R (2x1), ResC (1x2)) = scalar value.
 *
 * @param[in] r vec2 (2x1, row vector)
 * @param[in] m mat2 (2x2, matrix)
 * @param[in] c vec2 (1x2, column vector)
 *
 * @return[out] Scalar value (float, 1x1)
 */
CGLM_INLINE
float
glm_mat2_rmc(vec2 r, mat2 m, vec2 c) {
  vec2 tmp;
  glm_mat2_mulv(m, c, tmp);
  return glm_vec2_dot(r, tmp);
}

#endif /* cglm_mat2_h */
