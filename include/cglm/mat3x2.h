/*
 * Copyright (c), Recep Aslantas.
 *
 * MIT License (MIT), http://opensource.org/licenses/MIT
 * Full license can be found in the LICENSE file
 */

/*
 Macros:
   GLM_MAT3X2_ZERO_INIT
   GLM_MAT3X2_ZERO

 Functions:
   CGLM_INLINE void glm_mat3x2_copy(mat3x2 mat, mat3x2 dest);
   CGLM_INLINE void glm_mat3x2_zero(mat3x2 mat);
   CGLM_INLINE void glm_mat3x2_make(float * __restrict src, mat3x2 dest);
   CGLM_INLINE void glm_mat3x2_mul(mat3x2 m1, mat2x3 m2, mat3 dest);
   CGLM_INLINE void glm_mat3x2_mulv(mat3x2 m, vec2 v, vec3 dest);
   CGLM_INLINE void glm_mat3x2_transpose(mat3x2 m, mat2x3 dest);
   CGLM_INLINE void glm_mat3x2_scale(mat3x2 m, float s);
 */

#ifndef cglm_mat3x2_h
#define cglm_mat3x2_h

#include "common.h"

#define GLM_MAT3X2_ZERO_INIT {{0.0f, 0.0f}, {0.0f, 0.0f}, {0.0f, 0.0f}}

/* for C only */
#define GLM_MAT3X2_ZERO GLM_MAT3X2_ZERO_INIT

/*!
 * @brief copy all members of [mat] to [dest]
 *
 * @param[in]  mat  source
 * @param[out] dest destination
 */
CGLM_INLINE
void
glm_mat3x2_copy(mat3x2 mat, mat3x2 dest) {
  dest[0][0] = mat[0][0];
  dest[0][1] = mat[0][1];

  dest[1][0] = mat[1][0];
  dest[1][1] = mat[1][1];

  dest[2][0] = mat[2][0];
  dest[2][1] = mat[2][1];
}

/*!
 * @brief make given matrix zero.
 *
 * @param[in, out]  mat  matrix
 */
CGLM_INLINE
void
glm_mat3x2_zero(mat3x2 mat) {
  CGLM_ALIGN_MAT mat3x2 t = GLM_MAT3X2_ZERO_INIT;
  glm_mat3x2_copy(t, mat);
}

/*!
 * @brief Create mat3x2 matrix from pointer
 *
 * @param[in]  src  pointer to an array of floats
 * @param[out] dest matrix
 */
CGLM_INLINE
void
glm_mat3x2_make(float * __restrict src, mat3x2 dest) {
  dest[0][0] = src[0];
  dest[0][1] = src[1];

  dest[1][0] = src[2];
  dest[1][1] = src[3];

  dest[2][0] = src[4];
  dest[2][1] = src[5];
}

/*!
 * @brief multiply m1 and m2 to dest
 *
 * @code
 * glm_mat3x2_mul(mat3x2, mat2x3, mat3);
 * @endcode
 *
 * @param[in]  m1   left matrix (mat3x2)
 * @param[in]  m2   right matrix (mat2x3)
 * @param[out] dest destination matrix (mat3)
 */
CGLM_INLINE
void
glm_mat3x2_mul(mat3x2 m1, mat2x3 m2, mat3 dest) {
  float a00 = m1[0][0], a01 = m1[0][1],
        a10 = m1[1][0], a11 = m1[1][1],
        a20 = m1[2][0], a21 = m1[2][1],

        b00 = m2[0][0], b01 = m2[0][1], b02 = m2[0][2],
        b10 = m2[1][0], b11 = m2[1][1], b12 = m2[1][2];

  dest[0][0] = a00 * b00 + a01 * b10;
  dest[0][1] = a00 * b01 + a01 * b11;
  dest[0][2] = a00 * b02 + a01 * b12;

  dest[1][0] = a10 * b00 + a11 * b10;
  dest[1][1] = a10 * b01 + a11 * b11;
  dest[1][2] = a10 * b02 + a11 * b12;

  dest[2][0] = a20 * b00 + a21 * b10;
  dest[2][1] = a20 * b01 + a21 * b11;
  dest[2][2] = a20 * b02 + a21 * b12;
}

/*!
 * @brief multiply matrix with column vector and store in dest vector
 *
 * @param[in]  m    matrix (left)
 * @param[in]  v    vector (right, column vector)
 * @param[out] dest result vector
 */
CGLM_INLINE
void
glm_mat3x2_mulv(mat3x2 m, vec2 v, vec3 dest) {
  float v0 = v[0], v1 = v[1];

  dest[0] = m[0][0] * v0 + m[0][1] * v1;
  dest[1] = m[1][0] * v0 + m[1][1] * v1;
  dest[2] = m[2][0] * v0 + m[2][1] * v1;
}

/*!
 * @brief transpose matrix and store in dest
 *
 * @param[in]  m     matrix
 * @param[out] dest  result
 */
CGLM_INLINE
void
glm_mat3x2_transpose(mat3x2 m, mat2x3 dest) {
  dest[0][0] = m[0][0];  dest[0][1] = m[1][0];  dest[0][2] = m[2][0];
  dest[1][0] = m[0][1];  dest[1][1] = m[1][1];  dest[1][2] = m[2][1];
}

/*!
 * @brief scale (multiply with scalar) matrix
 *
 * multiply matrix with scalar
 *
 * @param[in, out] m matrix
 * @param[in]    s scalar
 */
CGLM_INLINE
void
glm_mat3x2_scale(mat3x2 m, float s) {
  m[0][0] *= s;  m[0][1] *= s;  m[1][0] *= s;
  m[1][1] *= s;  m[2][0] *= s;  m[2][1] *= s;
}

#endif
