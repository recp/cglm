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
   CGLM_DECL mat3s  glms_mat3_copy(mat3s mat);
   CGLM_DECL mat3s  glms_mat3_identity(void);
   CGLM_DECL void   glms_mat3_identity_array(mat3s * __restrict mat, size_t count);
   CGLM_DECL mat3s  glms_mat3_zero(void);
   CGLM_DECL mat3s  glms_mat3_mul(mat3s m1, mat3s m2);
   CGLM_DECL ma3s   glms_mat3_transpose(mat3s m);
   CGLM_DECL vec3s  glms_mat3_mulv(mat3s m, vec3s v);
   CGLM_DECL float  glms_mat3_trace(mat3s m);
   CGLM_DECL versor glms_mat3_quat(mat3s m);
   CGLM_DECL mat3s  glms_mat3_scale(mat3s m, float s);
   CGLM_DECL float  glms_mat3_det(mat3s mat);
   CGLM_DECL mat3s  glms_mat3_inv(mat3s mat);
   CGLM_DECL mat3s  glms_mat3_swap_col(mat3s mat, int col1, int col2);
   CGLM_DECL mat3s  glms_mat3_swap_row(mat3s mat, int row1, int row2);
   CGLM_DECL float  glms_mat3_rmc(vec3s r, mat3s m, vec3s c);
 */

#ifndef cglms_mat3s_h
#define cglms_mat3s_h

#include "../common.h"
#include "../types-struct.h"
#include "../mat3.h"
#include "vec3.h"

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
CGLM_DECL
mat3s
glms_mat3_copy(mat3s mat) CGLM_ENDD
#ifndef CGLM_LIB
{
  mat3s r;
  glm_mat3_copy(mat.raw, r.raw);
  return r;
}
#endif

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
CGLM_DECL
mat3s
glms_mat3_identity(void) CGLM_ENDD
#ifndef CGLM_LIB
{
  mat3s r;
  glm_mat3_identity(r.raw);
  return r;
}
#endif

/*!
 * @brief make given matrix array's each element identity matrix
 *
 * @param[in, out]  mat   matrix array (must be aligned (16/32)
 *                        if alignment is not disabled)
 *
 * @param[in]       count count of matrices
 */
CGLM_DECL
void
glms_mat3_identity_array(mat3s * __restrict mat, size_t count) CGLM_ENDD
#ifndef CGLM_LIB
{
  CGLM_ALIGN_MAT mat3s t = GLMS_MAT3_IDENTITY_INIT;
  size_t i;

  for (i = 0; i < count; i++) {
    glm_mat3_copy(t.raw, mat[i].raw);
  }
}
#endif

/*!
 * @brief make given matrix zero.
 *
 * @returns  matrix
 */
CGLM_DECL
mat3s
glms_mat3_zero(void) CGLM_ENDD
#ifndef CGLM_LIB
{
  mat3s r;
  glm_mat3_zero(r.raw);
  return r;
}
#endif

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
 * @returns         destination matrix
 */
CGLM_DECL
mat3s
glms_mat3_mul(mat3s m1, mat3s m2) CGLM_ENDD
#ifndef CGLM_LIB
{
  mat3s r;
  glm_mat3_mul(m1.raw, m2.raw, r.raw);
  return r;
}
#endif

/*!
 * @brief tranpose mat3 and store result in same matrix
 *
 * @param[in, out] m source and dest
 */
CGLM_DECL
mat3s
glms_mat3_transpose(mat3s m) CGLM_ENDD
#ifndef CGLM_LIB
{
  glm_mat3_transpose(m.raw);
  return m;
}
#endif

/*!
 * @brief multiply mat3 with vec3 (column vector) and store in dest vector
 *
 * @param[in]  m    mat3 (left)
 * @param[in]  v    vec3 (right, column vector)
 * @returns         vec3 (result, column vector)
 */
CGLM_DECL
vec3s
glms_mat3_mulv(mat3s m, vec3s v) CGLM_ENDD
#ifndef CGLM_LIB
{
  vec3s r;
  glm_mat3_mulv(m.raw, v.raw, r.raw);
  return r;
}
#endif

/*!
 * @brief trace of matrix
 *
 * sum of the elements on the main diagonal from upper left to the lower right
 *
 * @param[in]  m matrix
 */
CGLM_DECL
float
glms_mat3_trace(mat3s m) CGLM_ENDD
#ifndef CGLM_LIB
{
  return glm_mat3_trace(m.raw);
}
#endif

/*!
 * @brief convert mat3 to quaternion
 *
 * @param[in]  m    rotation matrix
 * @returns         destination quaternion
 */
CGLM_DECL
versors
glms_mat3_quat(mat3s m) CGLM_ENDD
#ifndef CGLM_LIB
{
  versors r;
  glm_mat3_quat(m.raw, r.raw);
  return r;
}
#endif

/*!
 * @brief scale (multiply with scalar) matrix
 *
 * multiply matrix with scalar
 *
 * @param[in]      m matrix
 * @param[in]      s scalar
 * @returns          scaled matrix
 */
CGLM_DECL
mat3s
glms_mat3_scale(mat3s m, float s) CGLM_ENDD
#ifndef CGLM_LIB
{
  glm_mat3_scale(m.raw, s);
  return m;
}
#endif

/*!
 * @brief mat3 determinant
 *
 * @param[in] mat matrix
 *
 * @return determinant
 */
CGLM_DECL
float
glms_mat3_det(mat3s mat) CGLM_ENDD
#ifndef CGLM_LIB
{
  return glm_mat3_det(mat.raw);
}
#endif

/*!
 * @brief inverse mat3 and store in dest
 *
 * @param[in]  mat  matrix
 * @returns         inverse matrix
 */
CGLM_DECL
mat3s
glms_mat3_inv(mat3s mat) CGLM_ENDD
#ifndef CGLM_LIB
{
  mat3s r;
  glm_mat3_inv(mat.raw, r.raw);
  return r;
}
#endif

/*!
 * @brief swap two matrix columns
 *
 * @param[in]     mat  matrix
 * @param[in]     col1 col1
 * @param[in]     col2 col2
 * @returns            matrix
 */
CGLM_DECL
mat3s
glms_mat3_swap_col(mat3s mat, int col1, int col2) CGLM_ENDD
#ifndef CGLM_LIB
{
  glm_mat3_swap_col(mat.raw, col1, col2);
  return mat;
}
#endif

/*!
 * @brief swap two matrix rows
 *
 * @param[in]     mat  matrix
 * @param[in]     row1 row1
 * @param[in]     row2 row2
 * @returns            matrix
 */
CGLM_DECL
mat3s
glms_mat3_swap_row(mat3s mat, int row1, int row2) CGLM_ENDD
#ifndef CGLM_LIB
{
  glm_mat3_swap_row(mat.raw, row1, row2);
  return mat;
}
#endif

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
CGLM_DECL
float
glms_mat3_rmc(vec3s r, mat3s m, vec3s c) CGLM_ENDD
#ifndef CGLM_LIB
{
  return glm_mat3_rmc(r.raw, m.raw, c.raw);
}
#endif

#endif /* cglms_mat3s_h */
