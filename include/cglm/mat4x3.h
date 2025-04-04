/*
 * Copyright (c), Recep Aslantas.
 *
 * MIT License (MIT), http://opensource.org/licenses/MIT
 * Full license can be found in the LICENSE file
 */

/*
 Macros:
   GLM_MAT4X3_ZERO_INIT
   GLM_MAT4X3_ZERO

 Functions:
   CGLM_INLINE void glm_mat4x3_copy(mat4x3 src, mat4x3 dest);
   CGLM_INLINE void glm_mat4x3_zero(mat4x3 m);
   CGLM_INLINE void glm_mat4x3_make(const float * __restrict src, mat4x3 dest);
   CGLM_INLINE void glm_mat4x3_mul(mat4x3 m1, mat3x4 m2, mat3 dest);
   CGLM_INLINE void glm_mat4x3_mulv(mat4x3 m, vec4 v, vec3 dest);
   CGLM_INLINE void glm_mat4x3_transpose(mat4x3 src, mat3x4 dest);
   CGLM_INLINE void glm_mat4x3_scale(mat4x3 m, float s);
 */

#ifndef cglm_mat4x3_h
#define cglm_mat4x3_h

#include "common.h"

#define GLM_MAT4X3_ZERO_INIT {{0.0f, 0.0f, 0.0f}, {0.0f, 0.0f, 0.0f}, \
                              {0.0f, 0.0f, 0.0f}, {0.0f, 0.0f, 0.0f}}

/* for C only */
#define GLM_MAT4X3_ZERO GLM_MAT4X3_ZERO_INIT

/*!
 * @brief Copy mat4x3 (src) to mat4x3 (dest).
 *
 * @param[in]  src  mat4x3 (left)
 * @param[out] dest destination (result, mat4x3)
 */
CGLM_INLINE
void
glm_mat4x3_copy(mat4x3 src, mat4x3 dest) {
  glm_vec3_copy(src[0], dest[0]);
  glm_vec3_copy(src[1], dest[1]);
  glm_vec3_copy(src[2], dest[2]);
  glm_vec3_copy(src[3], dest[3]);
}

/*!
 * @brief Zero out the mat4x3 (m).
 *
 * @param[in, out] mat4x3 (src, dest)
 */
CGLM_INLINE
void
glm_mat4x3_zero(mat4x3 m) {
  CGLM_ALIGN_MAT mat4x3 t = GLM_MAT4X3_ZERO_INIT;
  glm_mat4x3_copy(t, m);
}

/*!
 * @brief Create mat4x3 (dest) from pointer (src).
 *
 * @param[in]  src  pointer to an array of floats (left)
 * @param[out] dest destination (result, mat4x3)
 */
CGLM_INLINE
void
glm_mat4x3_make(const float * __restrict src, mat4x3 dest) {
  dest[0][0] = src[0];
  dest[0][1] = src[1];
  dest[0][2] = src[2];

  dest[1][0] = src[3];
  dest[1][1] = src[4];
  dest[1][2] = src[5];

  dest[2][0] = src[6];
  dest[2][1] = src[7];
  dest[2][2] = src[8];

  dest[3][0] = src[9];
  dest[3][1] = src[10];
  dest[3][2] = src[11];
}

/*!
 * @brief Multiply mat4x3 (m1) by mat3x4 (m2) and store in mat3 (dest).
 *
 * @code
 * glm_mat4x3_mul(mat4x3, mat3x4, mat3);
 * @endcode
 *
 * @param[in]  m1   mat4x3 (left)
 * @param[in]  m2   mat3x4 (right)
 * @param[out] dest destination (result, mat3)
 */
CGLM_INLINE
void
glm_mat4x3_mul(mat4x3 m1, mat3x4 m2, mat3 dest) {
  float a00 = m1[0][0], a01 = m1[0][1], a02 = m1[0][2],
        a10 = m1[1][0], a11 = m1[1][1], a12 = m1[1][2],
        a20 = m1[2][0], a21 = m1[2][1], a22 = m1[2][2],
        a30 = m1[3][0], a31 = m1[3][1], a32 = m1[3][2],

        b00 = m2[0][0], b01 = m2[0][1], b02 = m2[0][2], b03 = m2[0][3],
        b10 = m2[1][0], b11 = m2[1][1], b12 = m2[1][2], b13 = m2[1][3],
        b20 = m2[2][0], b21 = m2[2][1], b22 = m2[2][2], b23 = m2[2][3];

  dest[0][0] = a00 * b00 + a10 * b01 + a20 * b02 + a30 * b03;
  dest[0][1] = a01 * b00 + a11 * b01 + a21 * b02 + a31 * b03;
  dest[0][2] = a02 * b00 + a12 * b01 + a22 * b02 + a32 * b03;

  dest[1][0] = a00 * b10 + a10 * b11 + a20 * b12 + a30 * b13;
  dest[1][1] = a01 * b10 + a11 * b11 + a21 * b12 + a31 * b13;
  dest[1][2] = a02 * b10 + a12 * b11 + a22 * b12 + a32 * b13;

  dest[2][0] = a00 * b20 + a10 * b21 + a20 * b22 + a30 * b23;
  dest[2][1] = a01 * b20 + a11 * b21 + a21 * b22 + a31 * b23;
  dest[2][2] = a02 * b20 + a12 * b21 + a22 * b22 + a32 * b23;
}

/*!
 * @brief Multiply mat4x3 (m) by vec4 (v) and store in vec3 (dest).
 *
 * @param[in]  m    mat4x3 (left)
 * @param[in]  v    vec3 (right, column vector)
 * @param[out] dest destination (result, column vector)
 */
CGLM_INLINE
void
glm_mat4x3_mulv(mat4x3 m, vec4 v, vec3 dest) {
  float v0 = v[0], v1 = v[1], v2 = v[2], v3 = v[3];

  dest[0] = m[0][0] * v0 + m[1][0] * v1 + m[2][0] * v2 + m[3][0] * v3;
  dest[1] = m[0][1] * v0 + m[1][1] * v1 + m[2][1] * v2 + m[3][1] * v3;
  dest[2] = m[0][2] * v0 + m[1][2] * v1 + m[2][2] * v2 + m[3][2] * v3;
}

/*!
 * @brief Transpose mat4x3 (src) and store in mat3x4 (dest).
 *
 * @param[in]  src  mat4x3 (left)
 * @param[out] dest destination (result, mat3x4)
 */
CGLM_INLINE
void
glm_mat4x3_transpose(mat4x3 src, mat3x4 dest) {
  dest[0][0] = src[0][0]; dest[0][1] = src[1][0]; dest[0][2] = src[2][0]; dest[0][3] = src[3][0];
  dest[1][0] = src[0][1]; dest[1][1] = src[1][1]; dest[1][2] = src[2][1]; dest[1][3] = src[3][1];
  dest[2][0] = src[0][2]; dest[2][1] = src[1][2]; dest[2][2] = src[2][2]; dest[2][3] = src[3][2];
}

/*!
 * @brief Multiply mat4x3 (m) by scalar constant (s).
 *
 * @param[in, out] m (src, dest)
 * @param[in]      s float (scalar)
 */
CGLM_INLINE
void
glm_mat4x3_scale(mat4x3 m, float s) {
  m[0][0] *= s;  m[0][1] *= s;  m[0][2] *= s;  m[1][0] *= s;
  m[1][1] *= s;  m[1][2] *= s;  m[2][0] *= s;  m[2][1] *= s;
  m[2][2] *= s;  m[3][0] *= s;  m[3][1] *= s;  m[3][2] *= s;
}

#endif /* cglm_mat4x3_h */
