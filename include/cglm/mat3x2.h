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
   CGLM_INLINE void glm_mat3x2_copy(mat3x2 src, mat3x2 dest);
   CGLM_INLINE void glm_mat3x2_zero(mat3x2 m);
   CGLM_INLINE void glm_mat3x2_make(const float * __restrict src, mat3x2 dest);
   CGLM_INLINE void glm_mat3x2_mul(mat3x2 m1, mat2x3 m2, mat2 dest);
   CGLM_INLINE void glm_mat3x2_mulv(mat3x2 m, vec3 v, vec2 dest);
   CGLM_INLINE void glm_mat3x2_transpose(mat3x2 src, mat2x3 dest);
   CGLM_INLINE void glm_mat3x2_scale(mat3x2 m, float s);
 */

#ifndef cglm_mat3x2_h
#define cglm_mat3x2_h

#include "common.h"

#define GLM_MAT3X2_ZERO_INIT {{0.0f, 0.0f}, {0.0f, 0.0f}, {0.0f, 0.0f}}

/* for C only */
#define GLM_MAT3X2_ZERO GLM_MAT3X2_ZERO_INIT

/*!
 * @brief Copy mat3x2 (src) to mat3x2 (dest).
 *
 * @param[in]  src  mat3x2 (left)
 * @param[out] dest destination (result, mat3x2)
 */
CGLM_INLINE
void
glm_mat3x2_copy(mat3x2 src, mat3x2 dest) {
  glm_vec2_copy(src[0], dest[0]);
  glm_vec2_copy(src[1], dest[1]);
  glm_vec2_copy(src[2], dest[2]);
}

/*!
 * @brief Zero out the mat3x2 (m).
 *
 * @param[in, out] mat3x2 (src, dest)
 */
CGLM_INLINE
void
glm_mat3x2_zero(mat3x2 m) {
  CGLM_ALIGN_MAT mat3x2 t = GLM_MAT3X2_ZERO_INIT;
  glm_mat3x2_copy(t, m);
}

/*!
 * @brief Create mat3x2 (dest) from pointer (src).
 *
 * @param[in]  src  pointer to an array of floats (left)
 * @param[out] dest destination (result, mat3x2)
 */
CGLM_INLINE
void
glm_mat3x2_make(const float * __restrict src, mat3x2 dest) {
  dest[0][0] = src[0];
  dest[0][1] = src[1];

  dest[1][0] = src[2];
  dest[1][1] = src[3];

  dest[2][0] = src[4];
  dest[2][1] = src[5];
}

/*!
 * @brief Multiply mat3x2 (m1) by mat2x3 (m2) and store in mat2 (dest).
 *
 * @code
 * glm_mat3x2_mul(mat3x2, mat2x3, mat2);
 * @endcode
 *
 * @param[in]  m1   mat3x2 (left)
 * @param[in]  m2   mat2x3 (right)
 * @param[out] dest destination (result, mat2)
 */
CGLM_INLINE
void
glm_mat3x2_mul(mat3x2 m1, mat2x3 m2, mat2 dest) {
  float a00 = m1[0][0], a01 = m1[0][1],
        a10 = m1[1][0], a11 = m1[1][1],
        a20 = m1[2][0], a21 = m1[2][1],

        b00 = m2[0][0], b01 = m2[0][1], b02 = m2[0][2],
        b10 = m2[1][0], b11 = m2[1][1], b12 = m2[1][2];

  dest[0][0] = a00 * b00 + a10 * b01 + a20 * b02;
  dest[0][1] = a01 * b00 + a11 * b01 + a21 * b02;

  dest[1][0] = a00 * b10 + a10 * b11 + a20 * b12;
  dest[1][1] = a01 * b10 + a11 * b11 + a21 * b12;
}

/*!
 * @brief Multiply mat3x2 (m) by vec3 (v) and store in vec2 (dest).
 *
 * @param[in]  m    mat3x2 (left)
 * @param[in]  v    vec3 (right, column vector)
 * @param[out] dest destination (result, column vector)
 */
CGLM_INLINE
void
glm_mat3x2_mulv(mat3x2 m, vec3 v, vec2 dest) {
  float v0 = v[0], v1 = v[1], v2 = v[2];

  dest[0] = m[0][0] * v0 + m[1][0] * v1 + m[2][0] * v2;
  dest[1] = m[0][1] * v0 + m[1][1] * v1 + m[2][1] * v2;
}

/*!
 * @brief Transpose mat3x2 (src) and store in mat2x3 (dest).
 *
 * @param[in]  src  mat3x2 (left)
 * @param[out] dest destination (result, mat2x3)
 */
CGLM_INLINE
void
glm_mat3x2_transpose(mat3x2 src, mat2x3 dest) {
  dest[0][0] = src[0][0];  dest[0][1] = src[1][0];  dest[0][2] = src[2][0];
  dest[1][0] = src[0][1];  dest[1][1] = src[1][1];  dest[1][2] = src[2][1];
}

/*!
 * @brief Multiply mat3x2 (m) by scalar constant (s).
 *
 * @param[in, out] m (src, dest)
 * @param[in]      s float (scalar)
 */
CGLM_INLINE
void
glm_mat3x2_scale(mat3x2 m, float s) {
  m[0][0] *= s;  m[0][1] *= s;  m[1][0] *= s;
  m[1][1] *= s;  m[2][0] *= s;  m[2][1] *= s;
}

#endif
