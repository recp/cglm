/*
 * Copyright (c), Recep Aslantas.
 *
 * MIT License (MIT), http://opensource.org/licenses/MIT
 * Full license can be found in the LICENSE file
 */

/*
 Macros:
   GLMS_MAT3_IDENTITY_INIT
   GLMS_MAT3_ZERO_INIT
   GLMS_MAT3_IDENTITY
   GLMS_MAT3_ZERO

 Functions:
   CGLM_INLINE mat3s  glms_mat3_copy(mat3s mat);
   CGLM_INLINE mat3s  glms_mat3_identity(void);
   CGLM_INLINE void   glms_mat3_identity_array(mat3s * __restrict mat, size_t count);
   CGLM_INLINE mat3s  glms_mat3_zero(void);
   CGLM_INLINE mat3s  glms_mat3_mul(mat3s m1, mat3s m2);
   CGLM_INLINE ma3s   glms_mat3_transpose(mat3s m);
   CGLM_INLINE vec3s  glms_mat3_mulv(mat3s m, vec3s v);
   CGLM_INLINE float  glms_mat3_trace(mat3s m);
   CGLM_INLINE versor glms_mat3_quat(mat3s m);
   CGLM_INLINE mat3s  glms_mat3_scale(mat3s m, float s);
   CGLM_INLINE float  glms_mat3_det(mat3s mat);
   CGLM_INLINE mat3s  glms_mat3_inv(mat3s mat);
   CGLM_INLINE mat3s  glms_mat3_swap_col(mat3s mat, int col1, int col2);
   CGLM_INLINE mat3s  glms_mat3_swap_row(mat3s mat, int row1, int row2);
   CGLM_INLINE float  glms_mat3_rmc(vec3s r, mat3s m, vec3s c);
   CGLM_INLINE mat3s  glms_mat3_make(float * __restrict src);
 */

#ifndef cglms_mat3s_h
#define cglms_mat3s_h

#include "../common.h"
#include "../types-struct.h"
#include "../mat3.h"
#include "vec3.h"

/* api definition */
#define glms_mat3_(NAME) CGLM_STRUCTAPI(mat3, NAME)

#define GLMS_MAT3_IDENTITY_INIT  {GLM_MAT3_IDENTITY_INIT}
#define GLMS_MAT3_ZERO_INIT      {GLM_MAT3_ZERO_INIT}

/* for C only */
#define GLMS_MAT3_IDENTITY ((mat3s)GLMS_MAT3_IDENTITY_INIT)
#define GLMS_MAT3_ZERO     ((mat3s)GLMS_MAT3_ZERO_INIT)

/*!
 * @brief copy all members of [mat] to [dest]
 *
 * @param[in]  mat  source
 * @returns         destination
 */
CGLM_INLINE
mat3s
glms_mat3_(copy)(mat3s mat) {
  mat3s r;
  glm_mat3_copy(mat.raw, r.raw);
  return r;
}

/*!
 * @brief make given matrix identity. It is identical with below,
 *        but it is more easy to do that with this func especially for members
 *        e.g. glm_mat3_identity(aStruct->aMatrix);
 *
 * @code
 * glm_mat3_copy(GLM_MAT3_IDENTITY, mat); // C only
 *
 * // or
 * mat3 mat = GLM_MAT3_IDENTITY_INIT;
 * @endcode
 *
 * @returns  destination
 */
CGLM_INLINE
mat3s
glms_mat3_(identity)(void) {
  mat3s r;
  glm_mat3_identity(r.raw);
  return r;
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
glms_mat3_(identity_array)(mat3s * __restrict mat, size_t count) {
  CGLM_ALIGN_MAT mat3s t = GLMS_MAT3_IDENTITY_INIT;
  size_t i;

  for (i = 0; i < count; i++) {
    glm_mat3_copy(t.raw, mat[i].raw);
  }
}

/*!
 * @brief make given matrix zero.
 *
 * @returns  matrix
 */
CGLM_INLINE
mat3s
glms_mat3_(zero)(void) {
  mat3s r;
  glm_mat3_zero(r.raw);
  return r;
}

/*!
 * @brief multiply m1 and m2 to dest
 *
 * m1, m2 and dest matrices can be same matrix, it is possible to write this:
 *
 * @code
 * mat3 m = GLM_MAT3_IDENTITY_INIT;
 * r = glms_mat3_mul(m, m);
 * @endcode
 *
 * @param[in]  m1   left matrix
 * @param[in]  m2   right matrix
 * @returns destination matrix
 */
CGLM_INLINE
mat3s
glms_mat3_(mul)(mat3s m1, mat3s m2) {
  mat3s r;
  glm_mat3_mul(m1.raw, m2.raw, r.raw);
  return r;
}

/*!
 * @brief tranpose mat3 and store result in same matrix
 *
 * @param[in, out] m source and dest
 */
CGLM_INLINE
mat3s
glms_mat3_(transpose)(mat3s m) {
  glm_mat3_transpose(m.raw);
  return m;
}

/*!
 * @brief multiply mat3 with vec3 (column vector) and store in dest vector
 *
 * @param[in]  m    mat3 (left)
 * @param[in]  v    vec3 (right, column vector)
 * @returns         vec3 (result, column vector)
 */
CGLM_INLINE
vec3s
glms_mat3_(mulv)(mat3s m, vec3s v) {
  vec3s r;
  glm_mat3_mulv(m.raw, v.raw, r.raw);
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
glms_mat3_(trace)(mat3s m) {
  return glm_mat3_trace(m.raw);
}

/*!
 * @brief convert mat3 to quaternion
 *
 * @param[in]  m    rotation matrix
 * @returns         destination quaternion
 */
CGLM_INLINE
versors
glms_mat3_(quat)(mat3s m) {
  versors r;
  glm_mat3_quat(m.raw, r.raw);
  return r;
}

/*!
 * @brief scale (multiply with scalar) matrix
 *
 * multiply matrix with scalar
 *
 * @param[in]      m matrix
 * @param[in]      s scalar
 * @returns          scaled matrix
 */
CGLM_INLINE
mat3s
glms_mat3_(scale)(mat3s m, float s) {
  glm_mat3_scale(m.raw, s);
  return m;
}

/*!
 * @brief mat3 determinant
 *
 * @param[in] mat matrix
 *
 * @return determinant
 */
CGLM_INLINE
float
glms_mat3_(det)(mat3s mat) {
  return glm_mat3_det(mat.raw);
}

/*!
 * @brief inverse mat3 and store in dest
 *
 * @param[in]  mat  matrix
 * @returns         inverse matrix
 */
CGLM_INLINE
mat3s
glms_mat3_(inv)(mat3s mat) {
  mat3s r;
  glm_mat3_inv(mat.raw, r.raw);
  return r;
}

/*!
 * @brief swap two matrix columns
 *
 * @param[in]     mat  matrix
 * @param[in]     col1 col1
 * @param[in]     col2 col2
 * @returns            matrix
 */
CGLM_INLINE
mat3s
glms_mat3_(swap_col)(mat3s mat, int col1, int col2) {
  glm_mat3_swap_col(mat.raw, col1, col2);
  return mat;
}

/*!
 * @brief swap two matrix rows
 *
 * @param[in]     mat  matrix
 * @param[in]     row1 row1
 * @param[in]     row2 row2
 * @returns            matrix
 */
CGLM_INLINE
mat3s
glms_mat3_(swap_row)(mat3s mat, int row1, int row2) {
  glm_mat3_swap_row(mat.raw, row1, row2);
  return mat;
}

/*!
 * @brief helper for  R (row vector) * M (matrix) * C (column vector)
 *
 * rmc stands for Row * Matrix * Column
 *
 * the result is scalar because R * M = Matrix1x3 (row vector),
 * then Matrix1x3 * Vec3 (column vector) = Matrix1x1 (Scalar)
 *
 * @param[in]  r   row vector or matrix1x3
 * @param[in]  m   matrix3x3
 * @param[in]  c   column vector or matrix3x1
 *
 * @return scalar value e.g. Matrix1x1
 */
CGLM_INLINE
float
glms_mat3_(rmc)(vec3s r, mat3s m, vec3s c) {
  return glm_mat3_rmc(r.raw, m.raw, c.raw);
}

/*!
 * @brief Create mat3 matrix from pointer
 *
 * @param[in]  src  pointer to an array of floats
 * @return constructed matrix from raw pointer
 */
CGLM_INLINE
mat3s
glms_mat3_(make)(float * __restrict src) {
  mat3s r;
  glm_mat3_make(src, r.raw);
  return r;
}

#endif /* cglms_mat3s_h */
