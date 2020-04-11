/*
 * Copyright (c), Recep Aslantas.
 *
 * MIT License (MIT), http://opensource.org/licenses/MIT
 * Full license can be found in the LICENSE file
 */

/*!
 * Most of functions in this header are optimized manually with SIMD
 * if available. You dont need to call/incude SIMD headers manually
 */

/*
 Macros:
   GLMS_MAT4_IDENTITY_INIT
   GLMS_MAT4_ZERO_INIT
   GLMS_MAT4_IDENTITY
   GLMS_MAT4_ZERO

 Functions:
   CGLM_DECL mat4s   glms_mat4_ucopy(mat4s mat);
   CGLM_DECL mat4s   glms_mat4_copy(mat4s mat);
   CGLM_DECL mat4s   glms_mat4_identity(void);
   CGLM_DECL void    glms_mat4_identity_array(mat4s * __restrict mat, size_t count);
   CGLM_DECL mat4s   glms_mat4_zero(void);
   CGLM_DECL mat3s   glms_mat4_pick3(mat4s mat);
   CGLM_DECL mat3s   glms_mat4_pick3t(mat4s mat);
   CGLM_DECL mat4s   glms_mat4_ins3(mat3s mat);
   CGLM_DECL mat4s   glms_mat4_mul(mat4s m1, mat4s m2);
   CGLM_DECL mat4s   glms_mat4_mulN(mat4s * __restrict matrices[], uint32_t len);
   CGLM_DECL vec4s   glms_mat4_mulv(mat4s m, vec4s v);
   CGLM_DECL float   glms_mat4_trace(mat4s m);
   CGLM_DECL float   glms_mat4_trace3(mat4s m);
   CGLM_DECL versors glms_mat4_quat(mat4s m);
   CGLM_DECL vec3s   glms_mat4_mulv3(mat4s m, vec3s v, float last);
   CGLM_DECL mat4s   glms_mat4_transpose(mat4s m);
   CGLM_DECL mat4s   glms_mat4_scale_p(mat4s m, float s);
   CGLM_DECL mat4s   glms_mat4_scale(mat4s m, float s);
   CGLM_DECL float   glms_mat4_det(mat4s mat);
   CGLM_DECL mat4s   glms_mat4_inv(mat4s mat);
   CGLM_DECL mat4s   glms_mat4_inv_fast(mat4s mat);
   CGLM_DECL mat4s   glms_mat4_swap_col(mat4s mat, int col1, int col2);
   CGLM_DECL mat4s   glms_mat4_swap_row(mat4s mat, int row1, int row2);
   CGLM_DECL float   glms_mat4_rmc(vec4s r, mat4s m, vec4s c);
 */

#ifndef cglms_mat4s_h
#define cglms_mat4s_h

#include "../common.h"
#include "../types-struct.h"
#include "../mat4.h"
#include "vec4.h"
#include "vec3.h"

#define GLMS_MAT4_IDENTITY_INIT  {GLM_MAT4_IDENTITY_INIT}
#define GLMS_MAT4_ZERO_INIT      {GLM_MAT4_ZERO_INIT}

/* for C only */
#define GLMS_MAT4_IDENTITY ((mat4s)GLMS_MAT4_IDENTITY_INIT)
#define GLMS_MAT4_ZERO     ((mat4s)GLMS_MAT4_ZERO_INIT)

/*!
 * @brief copy all members of [mat] to [dest]
 *
 * matrix may not be aligned, u stands for unaligned, this may be useful when
 * copying a matrix from external source e.g. asset importer...
 *
 * @param[in]  mat  source
 * @returns         destination
 */
CGLM_DECL
mat4s
glms_mat4_ucopy(mat4s mat) CGLM_ENDD
#ifndef CGLM_LIB
{
  mat4s r;
  glm_mat4_ucopy(mat.raw, r.raw);
  return r;
}
#endif

/*!
 * @brief copy all members of [mat] to [dest]
 *
 * @param[in]  mat  source
 * @returns         destination
 */
CGLM_DECL
mat4s
glms_mat4_copy(mat4s mat) CGLM_ENDD
#ifndef CGLM_LIB
{
  mat4s r;
  glm_mat4_copy(mat.raw, r.raw);
  return r;
}
#endif

/*!
 * @brief make given matrix identity. It is identical with below, 
 *        but it is more easy to do that with this func especially for members
 *        e.g. glm_mat4_identity(aStruct->aMatrix);
 *
 * @code
 * glm_mat4_copy(GLM_MAT4_IDENTITY, mat); // C only
 *
 * // or
 * mat4 mat = GLM_MAT4_IDENTITY_INIT;
 * @endcode
 *
 * @retuns  destination
 */
CGLM_DECL
mat4s
glms_mat4_identity(void) CGLM_ENDD
#ifndef CGLM_LIB
{
  mat4s r;
  glm_mat4_identity(r.raw);
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
glms_mat4_identity_array(mat4s * __restrict mat, size_t count) CGLM_ENDD
#ifndef CGLM_LIB
{
  CGLM_ALIGN_MAT mat4s t = GLMS_MAT4_IDENTITY_INIT;
  size_t i;

  for (i = 0; i < count; i++) {
    glm_mat4_copy(t.raw, mat[i].raw);
  }
}
#endif

/*!
 * @brief make given matrix zero.
 *
 * @returns  matrix
 */
CGLM_DECL
mat4s
glms_mat4_zero(void) CGLM_ENDD
#ifndef CGLM_LIB
{
  mat4s r;
  glm_mat4_zero(r.raw);
  return r;
}
#endif

/*!
 * @brief copy upper-left of mat4 to mat3
 *
 * @param[in]  mat  source
 * @returns         destination
 */
CGLM_DECL
mat3s
glms_mat4_pick3(mat4s mat) CGLM_ENDD
#ifndef CGLM_LIB
{
  mat3s r;
  glm_mat4_pick3(mat.raw, r.raw);
  return r;
}
#endif

/*!
 * @brief copy upper-left of mat4 to mat3 (transposed)
 *
 * the postfix t stands for transpose
 *
 * @param[in]  mat  source
 * @returns         destination
 */
CGLM_DECL
mat3s
glms_mat4_pick3t(mat4s mat) CGLM_ENDD
#ifndef CGLM_LIB
{
  mat3s r;
  glm_mat4_pick3t(mat.raw, r.raw);
  return r;
}
#endif

/*!
 * @brief copy mat3 to mat4's upper-left
 *
 * @param[in]  mat  source
 * @returns         destination
 */
CGLM_DECL
mat4s
glms_mat4_ins3(mat3s mat) CGLM_ENDD
#ifndef CGLM_LIB
{
  mat4s r;
  glm_mat4_ins3(mat.raw, r.raw);
  return r;
}
#endif

/*!
 * @brief multiply m1 and m2 to dest
 *
 * m1, m2 and dest matrices can be same matrix, it is possible to write this:
 *
 * @code
 * mat4 m = GLM_MAT4_IDENTITY_INIT;
 * glm_mat4_mul(m, m, m);
 * @endcode
 *
 * @param[in]  m1   left matrix
 * @param[in]  m2   right matrix
 * @returns         destination matrix
 */
CGLM_DECL
mat4s
glms_mat4_mul(mat4s m1, mat4s m2) CGLM_ENDD
#ifndef CGLM_LIB
{
  mat4s r;
  glm_mat4_mul(m1.raw, m2.raw, r.raw);
  return r;
}
#endif

/*!
 * @brief mupliply N mat4 matrices and store result in dest
 *
 * this function lets you multiply multiple (more than two or more...) matrices
 * <br><br>multiplication will be done in loop, this may reduce instructions
 * size but if <b>len</b> is too small then compiler may unroll whole loop,
 * usage:
 * @code
 * mat m1, m2, m3, m4, res;
 *
 * res = glm_mat4_mulN((mat4 *[]){&m1, &m2, &m3, &m4}, 4);
 * @endcode
 *
 * @warning matrices parameter is pointer array not mat4 array!
 *
 * @param[in]  matrices mat4 * array
 * @param[in]  len      matrices count
 * @returns             result matrix
 */
CGLM_DECL
mat4s
glms_mat4_mulN(mat4s * __restrict matrices[], uint32_t len) CGLM_ENDD
#ifndef CGLM_LIB
{
  CGLM_ALIGN_MAT mat4s r = GLMS_MAT4_IDENTITY_INIT;
  size_t i;

  for (i = 0; i < len; i++) {
    r = glms_mat4_mul(r, *matrices[i]);
  }
  
  return r;
}
#endif

/*!
 * @brief multiply mat4 with vec4 (column vector) and store in dest vector
 *
 * @param[in]  m    mat4 (left)
 * @param[in]  v    vec4 (right, column vector)
 * @returns         vec4 (result, column vector)
 */
CGLM_DECL
vec4s
glms_mat4_mulv(mat4s m, vec4s v) CGLM_ENDD
#ifndef CGLM_LIB
{
  vec4s r;
  glm_mat4_mulv(m.raw, v.raw, r.raw);
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
glms_mat4_trace(mat4s m) CGLM_ENDD
#ifndef CGLM_LIB
{
  return glm_mat4_trace(m.raw);
}
#endif

/*!
 * @brief trace of matrix (rotation part)
 *
 * sum of the elements on the main diagonal from upper left to the lower right
 *
 * @param[in]  m matrix
 */
CGLM_DECL
float
glms_mat4_trace3(mat4s m) CGLM_ENDD
#ifndef CGLM_LIB
{
  return glm_mat4_trace3(m.raw);
}
#endif

/*!
 * @brief convert mat4's rotation part to quaternion
 *
 * @param[in]  m    affine matrix
 * @returns         destination quaternion
 */
CGLM_DECL
versors
glms_mat4_quat(mat4s m) CGLM_ENDD
#ifndef CGLM_LIB
{
  versors r;
  glm_mat4_quat(m.raw, r.raw);
  return r;
}
#endif

/*!
 * @brief multiply vector with mat4
 *
 * @param[in]  m    mat4(affine transform)
 * @param[in]  v    vec3
 * @param[in]  last 4th item to make it vec4
 * @returns         result vector (vec3)
 */
CGLM_DECL
vec3s
glms_mat4_mulv3(mat4s m, vec3s v, float last) CGLM_ENDD
#ifndef CGLM_LIB
{
  vec3s r;
  glm_mat4_mulv3(m.raw, v.raw, last, r.raw);
  return r;
}
#endif

/*!
 * @brief tranpose mat4 and store result in same matrix
 *
 * @param[in] m source
 * @returns     result
 */
CGLM_DECL
mat4s
glms_mat4_transpose(mat4s m) CGLM_ENDD
#ifndef CGLM_LIB
{
  glm_mat4_transpose(m.raw);
  return m;
}
#endif

/*!
 * @brief scale (multiply with scalar) matrix without simd optimization
 *
 * multiply matrix with scalar
 *
 * @param[in] m matrix
 * @param[in] s scalar
 * @returns     matrix    
 */
CGLM_DECL
mat4s
glms_mat4_scale_p(mat4s m, float s) CGLM_ENDD
#ifndef CGLM_LIB
{
  glm_mat4_scale_p(m.raw, s);
  return m;
}
#endif

/*!
 * @brief scale (multiply with scalar) matrix
 *
 * multiply matrix with scalar
 *
 * @param[in] m matrix
 * @param[in] s scalar
 * @returns     matrix
 */
CGLM_DECL
mat4s
glms_mat4_scale(mat4s m, float s) CGLM_ENDD
#ifndef CGLM_LIB
{
  glm_mat4_scale(m.raw, s);
  return m;
}
#endif

/*!
 * @brief mat4 determinant
 *
 * @param[in] mat matrix
 *
 * @return determinant
 */
CGLM_DECL
float
glms_mat4_det(mat4s mat) CGLM_ENDD
#ifndef CGLM_LIB
{
  return glm_mat4_det(mat.raw);
}
#endif

/*!
 * @brief inverse mat4 and store in dest
 *
 * @param[in]  mat  matrix
 * @returns         inverse matrix
 */
CGLM_DECL
mat4s
glms_mat4_inv(mat4s mat) CGLM_ENDD
#ifndef CGLM_LIB
{
  mat4s r;
  glm_mat4_inv(mat.raw, r.raw);
  return r;
}
#endif

/*!
 * @brief inverse mat4 and store in dest
 *
 * this func uses reciprocal approximation without extra corrections
 * e.g Newton-Raphson. this should work faster than normal,
 * to get more precise use glm_mat4_inv version.
 *
 * NOTE: You will lose precision, glm_mat4_inv is more accurate
 *
 * @param[in]  mat  matrix
 * @returns         inverse matrix
 */
CGLM_DECL
mat4s
glms_mat4_inv_fast(mat4s mat) CGLM_ENDD
#ifndef CGLM_LIB
{
  mat4s r;
  glm_mat4_inv_fast(mat.raw, r.raw);
  return r;
}
#endif

/*!
 * @brief swap two matrix columns
 *
 * @param[in] mat  matrix
 * @param[in] col1 col1
 * @param[in] col2 col2
 * @returns        matrix
 */
CGLM_DECL
mat4s
glms_mat4_swap_col(mat4s mat, int col1, int col2) CGLM_ENDD
#ifndef CGLM_LIB
{
  glm_mat4_swap_col(mat.raw, col1, col2);
  return mat;
}
#endif

/*!
 * @brief swap two matrix rows
 *
 * @param[in] mat  matrix
 * @param[in] row1 row1
 * @param[in] row2 row2
 * @returns        matrix
 */
CGLM_DECL
mat4s
glms_mat4_swap_row(mat4s mat, int row1, int row2) CGLM_ENDD
#ifndef CGLM_LIB
{
  glm_mat4_swap_row(mat.raw, row1, row2);
  return mat;
}
#endif

/*!
 * @brief helper for  R (row vector) * M (matrix) * C (column vector)
 *
 * rmc stands for Row * Matrix * Column
 *
 * the result is scalar because R * M = Matrix1x4 (row vector),
 * then Matrix1x4 * Vec4 (column vector) = Matrix1x1 (Scalar)
 *
 * @param[in]  r   row vector or matrix1x4
 * @param[in]  m   matrix4x4
 * @param[in]  c   column vector or matrix4x1
 *
 * @return scalar value e.g. B(s)
 */
CGLM_DECL
float
glms_mat4_rmc(vec4s r, mat4s m, vec4s c) CGLM_ENDD
#ifndef CGLM_LIB
{
  return glm_mat4_rmc(r.raw, m.raw, c.raw);
}
#endif

#endif /* cglms_mat4s_h */
