/*
 * Copyright (c), Recep Aslantas.
 *
 * MIT License (MIT), http://opensource.org/licenses/MIT
 * Full license can be found in the LICENSE file
 */

/*
 Macros:
   GLM_MAT4X2_ZERO_INIT
   GLM_MAT4X2_ZERO

 Functions:
   CGLM_INLINE void glm_mat4x2_copy(mat4x2 src, mat4x2 dest);
   CGLM_INLINE void glm_mat4x2_zero(mat4x2 m);
   CGLM_INLINE void glm_mat4x2_make(const float * __restrict src, mat4x2 dest);
   CGLM_INLINE void glm_mat4x2_mul(mat4x2 m1, mat2x4 m2, mat2 dest);
   CGLM_INLINE void glm_mat4x2_mulv(mat4x2 m, vec4 v, vec2 dest);
   CGLM_INLINE void glm_mat4x2_transpose(mat4x2 src, mat2x4 dest);
   CGLM_INLINE void glm_mat4x2_scale(mat4x2 m, float s);
 */

#ifndef cglm_mat4x2_h
#define cglm_mat4x2_h

#include "common.h"

#define GLM_MAT4X2_ZERO_INIT {{0.0f, 0.0f}, {0.0f, 0.0f}, {0.0f, 0.0f}, {0.0f, 0.0f}}

/* for C only */
#define GLM_MAT4X2_ZERO GLM_MAT4X2_ZERO_INIT

/*!
 * @brief Copy mat4x2 (src) to mat4x2 (dest).
 *
 * @param[in]  src  mat4x2 (left)
 * @param[out] dest destination (result, mat4x2)
 */
CGLM_INLINE
void
glm_mat4x2_copy(mat4x2 src, mat4x2 dest) {
  glm_vec2_copy(src[0], dest[0]);
  glm_vec2_copy(src[1], dest[1]);
  glm_vec2_copy(src[2], dest[2]);
  glm_vec2_copy(src[3], dest[3]);
}

/*!
 * @brief Zero out the mat4x2 (m).
 *
 * @param[in, out] mat4x2 (src, dest)
 */
CGLM_INLINE
void
glm_mat4x2_zero(mat4x2 m) {
  CGLM_ALIGN_MAT mat4x2 t = GLM_MAT4X2_ZERO_INIT;
  glm_mat4x2_copy(t, m);
}

/*!
 * @brief Create mat4x2 (dest) from pointer (src).
 *
 * @param[in]  src  pointer to an array of floats (left)
 * @param[out] dest destination (result, mat4x2)
 */
CGLM_INLINE
void
glm_mat4x2_make(const float * __restrict src, mat4x2 dest) {
  dest[0][0] = src[0];
  dest[0][1] = src[1];

  dest[1][0] = src[2];
  dest[1][1] = src[3];

  dest[2][0] = src[4];
  dest[2][1] = src[5];

  dest[3][0] = src[6];
  dest[3][1] = src[7];
}

/*!
 * @brief Multiply mat4x2 (m1) by mat2x4 (m2) and store in mat2 (dest).
 *
 * @code
 * glm_mat4x2_mul(mat4x2, mat2x4, mat2);
 * @endcode
 *
 * @param[in]  m1   mat4x2 (left)
 * @param[in]  m2   mat2x4 (right)
 * @param[out] dest destination (result, mat2)
 */
CGLM_INLINE
void
glm_mat4x2_mul(mat4x2 m1, mat2x4 m2, mat2 dest) {
  float a00 = m1[0][0], a01 = m1[0][1],
        a10 = m1[1][0], a11 = m1[1][1],
        a20 = m1[2][0], a21 = m1[2][1],
        a30 = m1[3][0], a31 = m1[3][1],

        b00 = m2[0][0], b01 = m2[0][1], b02 = m2[0][2], b03 = m2[0][3],
        b10 = m2[1][0], b11 = m2[1][1], b12 = m2[1][2], b13 = m2[1][3];

  dest[0][0] = a00 * b00 + a10 * b01 + a20 * b02 + a30 * b03;
  dest[0][1] = a01 * b00 + a11 * b01 + a21 * b02 + a31 * b03;

  dest[1][0] = a00 * b10 + a10 * b11 + a20 * b12 + a30 * b13;
  dest[1][1] = a01 * b10 + a11 * b11 + a21 * b12 + a31 * b13;
}

/*!
 * @brief Multiply mat4x2 (m) by vec4 (v) and store in vec2 (dest).
 *
 * @param[in]  m    mat4x2 (left)
 * @param[in]  v    vec4 (right, column vector)
 * @param[out] dest destination (result, column vector)
 */
CGLM_INLINE
void
glm_mat4x2_mulv(mat4x2 m, vec4 v, vec2 dest) {
  float v0 = v[0], v1 = v[1], v2 = v[2], v3 = v[3];

  dest[0] = m[0][0] * v0 + m[1][0] * v1 + m[2][0] * v2 + m[3][0] * v3;
  dest[1] = m[0][1] * v0 + m[1][1] * v1 + m[2][1] * v2 + m[3][1] * v3;
}

/*!
 * @brief Transpose mat4x2 (src) and store in mat2x4 (dest).
 *
 * @param[in]  src  mat4x2 (left)
 * @param[out] dest destination (result, mat2x4)
 */
CGLM_INLINE
void
glm_mat4x2_transpose(mat4x2 m, mat2x4 dest) {
  dest[0][0] = m[0][0]; dest[0][1] = m[1][0]; dest[0][2] = m[2][0]; dest[0][3] = m[3][0];
  dest[1][0] = m[0][1]; dest[1][1] = m[1][1]; dest[1][2] = m[2][1]; dest[1][3] = m[3][1];
}

/*!
 * @brief Multiply mat4x2 (m) by scalar constant (s).
 *
 * @param[in, out] m (src, dest)
 * @param[in]      s float (scalar)
 */
CGLM_INLINE
void
glm_mat4x2_scale(mat4x2 m, float s) {
  m[0][0] *= s;  m[0][1] *= s;  m[1][0] *= s;  m[1][1] *= s;
  m[2][0] *= s;  m[2][1] *= s;  m[3][0] *= s;  m[3][1] *= s;
}

#endif
