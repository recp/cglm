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
   CGLM_INLINE mat2s glms_mat2_make(const float * __restrict src);
   CGLM_INLINE mat2s glms_mat2_identity(void)
   CGLM_INLINE void  glms_mat2_identity_array(mat2 * restrict mats, size_t count)
   CGLM_INLINE mat2s glms_mat2_zero(void)
   CGLM_INLINE mat2s glms_mat2_mul(mat2 m1, mat2 m2)
   CGLM_INLINE vec2s glms_mat2_mulv(mat2 m, vec2 v)
   CGLM_INLINE mat2s glms_mat2_transpose(mat2 m)
   CGLM_INLINE mat2s glms_mat2_scale(mat2 m, float s)
   CGLM_INLINE mat2s glms_mat2_inv(mat2 m)
   CGLM_INLINE mat2s glms_mat2_swap_col(mat2 mat, int col1, int col2)
   CGLM_INLINE mat2s glms_mat2_swap_row(mat2 mat, int row1, int row2)
   CGLM_INLINE float glms_mat2_det(mat2 m)
   CGLM_INLINE float glms_mat2_trace(mat2 m)
   CGLM_INLINE float glms_mat2_rmc(vec2 r, mat2 m, vec2 c)
 */

#ifndef cglms_mat2_h
#define cglms_mat2_h

#include "../common.h"
#include "../types-struct.h"
#include "../mat2.h"

/* api definition */
#define glms_mat2_(NAME) CGLM_STRUCTAPI(mat2, NAME)

#define GLMS_MAT2_IDENTITY_INIT {GLM_MAT2_IDENTITY_INIT}
#define GLMS_MAT2_ZERO_INIT     {GLM_MAT2_ZERO_INIT}

/* for C only */
#define GLMS_MAT2_IDENTITY ((mat2s)GLMS_MAT2_IDENTITY_INIT)
#define GLMS_MAT2_ZERO     ((mat2s)GLMS_MAT2_ZERO_INIT)

/*!
 * @brief Returns mat2s (r) from pointer (src).
 *
 * @param[in]   src pointer to an array of floats
 * @return[out] r   constructed mat2s from raw pointer
 */
CGLM_INLINE
mat2s
glms_mat2_(make)(const float * __restrict src) {
  mat2s r;
  glm_mat2_make(src, r.raw);
  return r;
}

/*!
 * @brief Return a identity mat2s (r).
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
 * @return[out] r constructed mat2s from raw pointer
 */
CGLM_INLINE
mat2s
glms_mat2_(identity)(void) {
  mat2s r;
  glm_mat2_identity(r.raw);
  return r;
}

/*!
 * @brief Given an array of mat2s’s (mats) make each matrix an identity matrix.
 *
 * @param[in, out] mats  Array of mat2s’s (must be aligned (16/32) if alignment is not disabled)
 * @param[in]      count Array size of mats or number of matrices
 */
CGLM_INLINE
void
glms_mat2_(identity_array)(mat2s * __restrict mats, size_t count) {
  CGLM_ALIGN_MAT mat2s t = GLMS_MAT2_IDENTITY_INIT;
  size_t i;

  for (i = 0; i < count; i++) {
    glm_mat2_copy(t.raw, mats[i].raw);
  }
}

/*!
 * @brief Return zero'd out mat2 (r).
 *
 * @return[out] r constructed mat2s from raw pointer
 */
CGLM_INLINE
mat2s
glms_mat2_(zero)(void) {
  mat2s r;
  glm_mat2_zero(r.raw);
  return r;
}

/*!
 * @brief Multiply mat2 (m1) by mat2 (m2) and return in mat2s (r)
 *
 *        m1 and m2 matrices can be the same matrix, it is possible to write this:
 *
 * @code
 * mat2 m = GLM_MAT2_IDENTITY_INIT;
 * mat2s r = glms_mat2_mul(m, m);
 * @endcode
 *
 * @param[in]   m1 mat2s (left)
 * @param[in]   m2 mat2s (right)
 * @return[out] r  constructed mat2s from raw pointers
 */
CGLM_INLINE
mat2s
glms_mat2_(mul)(mat2s m1, mat2s m2) {
  mat2s r;
  glm_mat2_mul(m1.raw, m2.raw, r.raw);
  return r;
}

/*
 * @brief Multiply mat2s (m) by vec2s (v) and return in vec2s (r).
 *
 * @param[in]   m mat2s (left)
 * @param[in]   v vec2s (right, column vector)
 * @return[out] r constructed vec2s from raw pointers
 */
CGLM_INLINE
vec2s
glms_mat2_(mulv)(mat2s m, vec2s v) {
  vec2s r;
  glm_mat2_mulv(m.raw, v.raw, r.raw);
  return r;
}

/*!
 * @brief Transpose mat2s (m) and store result in the same matrix.
 *
 * @param[in]   m mat2s (src)
 * @return[out] m constructed mat2s from raw pointers
 */
CGLM_INLINE
mat2s
glms_mat2_(transpose)(mat2s m) {
  glm_mat2_transpose(m.raw);
  return m;
}

/*!
 * @brief Multiply mat2s (m) by scalar constant (s)
 *
 * @param[in]   m mat2s (src)
 * @param[in]   s scalar value
 * @return[out] m constructed mat2s from raw pointers
 */
CGLM_INLINE
mat2s
glms_mat2_(scale)(mat2s m, float s) {
  glm_mat2_scale(m.raw, s);
  return m;
}

/*!
 * @brief Inverse mat2s (m) and return in mat2s (r).
 *
 * @param[in]   m mat2s (left, src)
 * @return[out] r constructed mat2s from raw pointers
 */
CGLM_INLINE
mat2s
glms_mat2_(inv)(mat2s m) {
  mat2s r;
  glm_mat2_inv(m.raw, r.raw);
  return r;
}

/*!
 * @brief Swap two columns in mat2s (mat) and store in same matrix.
 *
 * @param[in]   mat  mat2s
 * @param[in]   col1 column 1 array index
 * @param[in]   col2 column 2 array index
 * @return[out] mat  constructed mat2s from raw pointers columns swapped
 */
CGLM_INLINE
mat2s
glms_mat2_(swap_col)(mat2s mat, int col1, int col2) {
  glm_mat2_swap_col(mat.raw, col1, col2);
  return mat;
}

/*!
 * @brief Swap two rows in mat2s (mat) and store in same matrix.
 *
 * @param[in]   mat  mat2s
 * @param[in]   row1 row 1 array index
 * @param[in]   row2 row 2 array index
 * @return[out] mat  constructed mat2s from raw pointers rows swapped
 */
CGLM_INLINE
mat2s
glms_mat2_(swap_row)(mat2s mat, int row1, int row2) {
  glm_mat2_swap_row(mat.raw, row1, row2);
  return mat;
}

/*!
 * @brief Returns mat2 determinant.
 *
 * @param[in] m mat2 (src)
 *
 * @return[out] mat2s raw pointers determinant (float)
 */
CGLM_INLINE
float
glms_mat2_(det)(mat2s m) {
  return glm_mat2_det(m.raw);
}

/*!
 * @brief Returns trace of matrix. Which is:
 *
 *        The sum of the elements on the main diagonal from
 *        upper left corner to the bottom right corner.
 *
 * @param[in] m mat2 (m)
 *
 * @return[out] mat2s raw pointers trace (float)
 */
CGLM_INLINE
float
glms_mat2_(trace)(mat2s m) {
  return glm_mat2_trace(m.raw);
}

/*!
 * @brief Helper for  R (row vector) * M (matrix) * C (column vector)
 *
 *        rmc stands for Row * Matrix * Column
 *
 *        the result is scalar because M * C = ResC (1x2, column vector),
 *        then if you take the dot_product(R (2x1), ResC (1x2)) = scalar value.
 *
 * @param[in] r vec2s (2x1, row vector)
 * @param[in] m mat2s (2x2, matrix)
 * @param[in] c vec2s (1x2, column vector)
 *
 * @return[out] Scalar value (float, 1x1)
 */
CGLM_INLINE
float
glms_mat2_(rmc)(vec2s r, mat2s m, vec2s c) {
  return glm_mat2_rmc(r.raw, m.raw, c.raw);
}

#endif /* cglms_mat2_h */
