/*
 * Copyright (c), Recep Aslantas.
 *
 * MIT License (MIT), http://opensource.org/licenses/MIT
 * Full license can be found in the LICENSE file
 */

/*
 Macros:
   GLM_MAT3X4_ZERO_INIT
   GLM_MAT3X4_ZERO

 Functions:
   CGLM_INLINE void glm_mat3x4_copy(mat3x4 src, mat3x4 dest);
   CGLM_INLINE void glm_mat3x4_zero(mat3x4 m);
   CGLM_INLINE void glm_mat3x4_make(const float * __restrict src, mat3x4 dest);
   CGLM_INLINE void glm_mat3x4_mul(mat3x4 m1, mat4x3 m2, mat4 dest);
   CGLM_INLINE void glm_mat3x4_mulv(mat3x4 m, vec3 v, vec4 dest);
   CGLM_INLINE void glm_mat3x4_transpose(mat3x4 src, mat4x3 dest);
   CGLM_INLINE void glm_mat3x4_scale(mat3x4 m, float s);
 */

#ifndef cglm_mat3x4_h
#define cglm_mat3x4_h

#include "common.h"

#define GLM_MAT3X4_ZERO_INIT {{0.0f, 0.0f, 0.0f, 0.0f}, \
                              {0.0f, 0.0f, 0.0f, 0.0f}, \
                              {0.0f, 0.0f, 0.0f, 0.0f}}

/* for C only */
#define GLM_MAT3X4_ZERO GLM_MAT3X4_ZERO_INIT

/*!
 * @brief Copy mat3x4 (src) to mat3x4 (dest).
 *
 * @param[in]  src  mat3x4 (left)
 * @param[out] dest destination (result, mat3x4)
 */
CGLM_INLINE
void
glm_mat3x4_copy(mat3x4 src, mat3x4 dest) {
  glm_vec4_ucopy(src[0], dest[0]);
  glm_vec4_ucopy(src[1], dest[1]);
  glm_vec4_ucopy(src[2], dest[2]);
}

/*!
 * @brief Zero out the mat3x4 (m).
 *
 * @param[in, out] mat3x4 (src, dest)
 */
CGLM_INLINE
void
glm_mat3x4_zero(mat3x4 m) {
  CGLM_ALIGN_MAT mat3x4 t = GLM_MAT3X4_ZERO_INIT;
  glm_mat3x4_copy(t, m);
}

/*!
 * @brief Create mat3x4 (dest) from pointer (src).
 *
 * @param[in]  src  pointer to an array of floats (left)
 * @param[out] dest destination (result, mat3x4)
 */
CGLM_INLINE
void
glm_mat3x4_make(const float * __restrict src, mat3x4 dest) {
  dest[0][0] = src[0];
  dest[0][1] = src[1];
  dest[0][2] = src[2];
  dest[0][3] = src[3];

  dest[1][0] = src[4];
  dest[1][1] = src[5];
  dest[1][2] = src[6];
  dest[1][3] = src[7];

  dest[2][0] = src[8];
  dest[2][1] = src[9];
  dest[2][2] = src[10];
  dest[2][3] = src[11];
}

/*!
 * @brief Multiply mat3x4 (m1) by mat4x3 (m2) and store in mat4 (dest).
 *
 * @code
 * glm_mat3x4_mul(mat3x4, mat4x3, mat4);
 * @endcode
 *
 * @param[in]  m1   mat3x4 (left)
 * @param[in]  m2   mat4x3 (right)
 * @param[out] dest destination (result, mat4)
 */
CGLM_INLINE
void
glm_mat3x4_mul(mat3x4 m1, mat4x3 m2, mat4 dest) {
  float a00 = m1[0][0], a01 = m1[0][1], a02 = m1[0][2], a03 = m1[0][3],
        a10 = m1[1][0], a11 = m1[1][1], a12 = m1[1][2], a13 = m1[1][3],
        a20 = m1[2][0], a21 = m1[2][1], a22 = m1[2][2], a23 = m1[2][3],

        b00 = m2[0][0], b01 = m2[0][1], b02 = m2[0][2],
        b10 = m2[1][0], b11 = m2[1][1], b12 = m2[1][2],
        b20 = m2[2][0], b21 = m2[2][1], b22 = m2[2][2],
        b30 = m2[3][0], b31 = m2[3][1], b32 = m2[3][2];

  dest[0][0] = a00 * b00 + a10 * b01 + a20 * b02;
  dest[0][1] = a01 * b00 + a11 * b01 + a21 * b02;
  dest[0][2] = a02 * b00 + a12 * b01 + a22 * b02;
  dest[0][3] = a03 * b00 + a13 * b01 + a23 * b02;

  dest[1][0] = a00 * b10 + a10 * b11 + a20 * b12;
  dest[1][1] = a01 * b10 + a11 * b11 + a21 * b12;
  dest[1][2] = a02 * b10 + a12 * b11 + a22 * b12;
  dest[1][3] = a03 * b10 + a13 * b11 + a23 * b12;

  dest[2][0] = a00 * b20 + a10 * b21 + a20 * b22;
  dest[2][1] = a01 * b20 + a11 * b21 + a21 * b22;
  dest[2][2] = a02 * b20 + a12 * b21 + a22 * b22;
  dest[2][3] = a03 * b20 + a13 * b21 + a23 * b22;

  dest[3][0] = a00 * b30 + a10 * b31 + a20 * b32;
  dest[3][1] = a01 * b30 + a11 * b31 + a21 * b32;
  dest[3][2] = a02 * b30 + a12 * b31 + a22 * b32;
  dest[3][3] = a03 * b30 + a13 * b31 + a23 * b32;
}

/*!
 * @brief Multiply mat3x4 (m) by vec3 (v) and store in vec4 (dest).
 *
 * @param[in]  m    mat3x4 (left)
 * @param[in]  v    vec3 (right, column vector)
 * @param[out] dest destination (result, column vector)
 */
CGLM_INLINE
void
glm_mat3x4_mulv(mat3x4 m, vec3 v, vec4 dest) {
  float v0 = v[0], v1 = v[1], v2 = v[2];

  dest[0] = m[0][0] * v0 + m[1][0] * v1 + m[2][0] * v2;
  dest[1] = m[0][1] * v0 + m[1][1] * v1 + m[2][1] * v2;
  dest[2] = m[0][2] * v0 + m[1][2] * v1 + m[2][2] * v2;
  dest[3] = m[0][3] * v0 + m[1][3] * v1 + m[2][3] * v2;
}

/*!
 * @brief Transpose mat3x4 (src) and store in mat4x3 (dest).
 *
 * @param[in]  src  mat3x4 (left)
 * @param[out] dest destination (result, mat4x3)
 */
CGLM_INLINE
void
glm_mat3x4_transpose(mat3x4 src, mat4x3 dest) {
  dest[0][0] = src[0][0];  dest[0][1] = src[1][0];  dest[0][2] = src[2][0];
  dest[1][0] = src[0][1];  dest[1][1] = src[1][1];  dest[1][2] = src[2][1];
  dest[2][0] = src[0][2];  dest[2][1] = src[1][2];  dest[2][2] = src[2][2];
  dest[3][0] = src[0][3];  dest[3][1] = src[1][3];  dest[3][2] = src[2][3];
}

/*!
 * @brief Multiply mat3x4 (m) by scalar constant (s).
 *
 * @param[in, out] m (src, dest)
 * @param[in]      s float (scalar)
 */
CGLM_INLINE
void
glm_mat3x4_scale(mat3x4 m, float s) {
  m[0][0] *= s; m[0][1] *= s; m[0][2] *= s; m[0][3] *= s;
  m[1][0] *= s; m[1][1] *= s; m[1][2] *= s; m[1][3] *= s;
  m[2][0] *= s; m[2][1] *= s; m[2][2] *= s; m[2][3] *= s;
}

#endif
