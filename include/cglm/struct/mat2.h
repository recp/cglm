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
   CGLM_INLINE void  glms_mat2_identity(mat2 mat)
   CGLM_INLINE void  glms_mat2_identity_array(mat2 * restrict mat, size_t count)
   CGLM_INLINE void  glms_mat2_zero(mat2 mat)
   CGLM_INLINE void  glms_mat2_mul(mat2 m1, mat2 m2, mat2 dest)
   CGLM_INLINE void  glms_mat2_transpose_to(mat2 m, mat2 dest)
   CGLM_INLINE void  glms_mat2_transpose(mat2 m)
   CGLM_INLINE void  glms_mat2_mulv(mat2 m, vec2 v, vec2 dest)
   CGLM_INLINE float glms_mat2_trace(mat2 m)
   CGLM_INLINE void  glms_mat2_scale(mat2 m, float s)
   CGLM_INLINE float glms_mat2_det(mat2 mat)
   CGLM_INLINE void  glms_mat2_inv(mat2 mat, mat2 dest)
   CGLM_INLINE void  glms_mat2_swap_col(mat2 mat, int col1, int col2)
   CGLM_INLINE void  glms_mat2_swap_row(mat2 mat, int row1, int row2)
   CGLM_INLINE float glms_mat2_rmc(vec2 r, mat2 m, vec2 c)
   CGLM_INLINE mat2s glms_mat2_make(float * __restrict src);
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
 * @returns identity matrix
 */
CGLM_INLINE
mat2s
glms_mat2_(identity)(void) {
  mat2s r;
  glm_mat2_identity(r.raw);
  return r;
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
glms_mat2_(identity_array)(mat2s * __restrict mat, size_t count) {
  CGLM_ALIGN_MAT mat2s t = GLMS_MAT2_IDENTITY_INIT;
  size_t i;

  for (i = 0; i < count; i++) {
    glm_mat2_copy(t.raw, mat[i].raw);
  }
}

/*!
 * @brief make given matrix zero.
 *
 * @returns  matrix
 */
CGLM_INLINE
mat2s
glms_mat2_(zero)(void) {
  mat2s r;
  glm_mat2_zero(r.raw);
  return r;
}

/*!
 * @brief multiply m1 and m2 to dest
 *
 * m1, m2 and dest matrices can be same matrix, it is possible to write this:
 *
 * @code
 * mat2 m = GLM_MAT2_IDENTITY_INIT;
 * r = glms_mat2_mul(m, m);
 * @endcode
 *
 * @param[in]  m1   left matrix
 * @param[in]  m2   right matrix
 *
 * @returns destination matrix
 */
CGLM_INLINE
mat2s
glms_mat2_(mul)(mat2s m1, mat2s m2) {
  mat2s r;
  glm_mat2_mul(m1.raw, m2.raw, r.raw);
  return r;
}

/*!
 * @brief transpose mat2
 *
 * @param[in] m matrix to transpose
 *
 * @returns transposed matrix
 */
CGLM_INLINE
mat2s
glms_mat2_(transpose)(mat2s m) {
  glm_mat2_transpose(m.raw);
  return m;
}

/*!
 * @brief multiply mat2 with vec2 (column vector) and store in dest vector
 *
 * @param[in]  m    mat2 (left)
 * @param[in]  v    vec2 (right, column vector)
 * @returns         vec2 (result, column vector)
 */
CGLM_INLINE
vec2s
glms_mat2_(mulv)(mat2s m, vec2s v) {
  vec2s r;
  glm_mat2_mulv(m.raw, v.raw, r.raw);
  return r;
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
glms_mat2_(trace)(mat2s m) {
  return glm_mat2_trace(m.raw);
}

/*!
 * @brief scale (multiply with scalar) matrix
 *
 * multiply matrix with scalar
 *
 * @param[in, out] m matrix
 * @param[in]      s scalar
 * @returns matrix
 */
CGLM_INLINE
mat2s
glms_mat2_(scale)(mat2s m, float s) {
  glm_mat2_scale(m.raw, s);
  return m;
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
glms_mat2_(det)(mat2s mat) {
  return glm_mat2_det(mat.raw);
}

/*!
 * @brief inverse mat2 and store in dest
 *
 * @param[in]  mat  matrix
 * @returns matrix
 */
CGLM_INLINE
mat2s
glms_mat2_(inv)(mat2s mat) {
  mat2s r;
  glm_mat2_inv(mat.raw, r.raw);
  return r;
}

/*!
 * @brief swap two matrix columns
 *
 * @param[in] mat  matrix
 * @param[in] col1 col1
 * @param[in] col2 col2
 * @returns matrix
 */
CGLM_INLINE
mat2s
glms_mat2_(swap_col)(mat2s mat, int col1, int col2) {
  glm_mat2_swap_col(mat.raw, col1, col2);
  return mat;
}

/*!
 * @brief swap two matrix rows
 *
 * @param[in] mat  matrix
 * @param[in] row1 row1
 * @param[in] row2 row2
 * @returns matrix
 */
CGLM_INLINE
mat2s
glms_mat2_(swap_row)(mat2s mat, int row1, int row2) {
  glm_mat2_swap_row(mat.raw, row1, row2);
  return mat;
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
glms_mat2_(rmc)(vec2s r, mat2s m, vec2s c) {
  return glm_mat2_rmc(r.raw, m.raw, c.raw);
}

/*!
 * @brief Create mat2 matrix from pointer
 *
 * @param[in]  src  pointer to an array of floats
 * @return constructed matrix from raw pointer
 */
CGLM_INLINE
mat2s
glms_mat2_(make)(float * __restrict src) {
  mat2s r;
  glm_mat2_make(src, r.raw);
  return r;
}

#endif /* cglms_mat2_h */
