/*
 * Copyright (c), Recep Aslantas.
 *
 * MIT License (MIT), http://opensource.org/licenses/MIT
 * Full license can be found in the LICENSE file
 */

/*
 Macros:
   GLM_MAT2X4_ZERO_INIT
   GLM_MAT2X4_ZERO

 Functions:
   CGLM_INLINE void glm_mat2x4_copy(mat2x4 src, mat2x4 dest);
   CGLM_INLINE void glm_mat2x4_zero(mat2x4 m);
   CGLM_INLINE void glm_mat2x4_make(const float * __restrict src, mat2x4 dest);
   CGLM_INLINE void glm_mat2x4_mul(mat2x4 m1, mat4x2 m2, mat4 dest);
   CGLM_INLINE void glm_mat2x4_mulv(mat2x4 m, vec2 v, vec4 dest);
   CGLM_INLINE void glm_mat2x4_transpose(mat2x4 src, mat4x2 dest);
   CGLM_INLINE void glm_mat2x4_scale(mat2x4 m, float s);
 */

#ifndef cglm_mat2x4_h
#define cglm_mat2x4_h

#include "common.h"
#include "vec4.h"

#define GLM_MAT2X4_ZERO_INIT {{0.0f, 0.0f, 0.0f, 0.0f}, {0.0f, 0.0f, 0.0f, 0.0f}}

/* for C only */
#define GLM_MAT2X4_ZERO GLM_MAT2X4_ZERO_INIT

/*!
 * @brief Copy mat2x4 (src) to mat2x4 (dest).
 *
 * @param[in]  src  mat2x4 (left)
 * @param[out] dest destination (result, mat2x4)
 */
CGLM_INLINE
void
glm_mat2x4_copy(mat2x4 src, mat2x4 dest) {
  glm_vec4_ucopy(src[0], dest[0]);
  glm_vec4_ucopy(src[1], dest[1]);
}

/*!
 * @brief Zero out the mat2x4 (m).
 *
 * @param[in, out] mat2x4 (src, dest)
 */
CGLM_INLINE
void
glm_mat2x4_zero(mat2x4 m) {
  CGLM_ALIGN_MAT mat2x4 t = GLM_MAT2X4_ZERO_INIT;
  glm_mat2x4_copy(t, m);
}

/*!
 * @brief Create mat2x4 (dest) from pointer (src).
 *
 * @param[in]  src  pointer to an array of floats (left)
 * @param[out] dest destination (result, mat2x4)
 */
CGLM_INLINE
void
glm_mat2x4_make(const float * __restrict src, mat2x4 dest) {
  dest[0][0] = src[0];
  dest[0][1] = src[1];
  dest[0][2] = src[2];
  dest[0][3] = src[3];

  dest[1][0] = src[4];
  dest[1][1] = src[5];
  dest[1][2] = src[6];
  dest[1][3] = src[7];
}

/*!
 * @brief Multiply mat2x4 (m1) by mat4x2 (m2) and store in mat4 (dest).
 *
 * @code
 * glm_mat2x4_mul(mat2x4, mat4x2, mat4);
 * @endcode
 *
 * @param[in]  m1   mat2x4 (left)
 * @param[in]  m2   mat4x2 (right)
 * @param[out] dest destination (result, mat4)
 */
CGLM_INLINE
void
glm_mat2x4_mul(mat2x4 m1, mat4x2 m2, mat4 dest) {
  float a00 = m1[0][0], a01 = m1[0][1], a02 = m1[0][2], a03 = m1[0][3],
        a10 = m1[1][0], a11 = m1[1][1], a12 = m1[1][2], a13 = m1[1][3],

        b00 = m2[0][0], b01 = m2[0][1],
        b10 = m2[1][0], b11 = m2[1][1],
        b20 = m2[2][0], b21 = m2[2][1],
        b30 = m2[3][0], b31 = m2[3][1];

  dest[0][0] = a00 * b00 + a10 * b01;
  dest[0][1] = a01 * b00 + a11 * b01;
  dest[0][2] = a02 * b00 + a12 * b01;
  dest[0][3] = a03 * b00 + a13 * b01;

  dest[1][0] = a00 * b10 + a10 * b11;
  dest[1][1] = a01 * b10 + a11 * b11;
  dest[1][2] = a02 * b10 + a12 * b11;
  dest[1][3] = a03 * b10 + a13 * b11;

  dest[2][0] = a00 * b20 + a10 * b21;
  dest[2][1] = a01 * b20 + a11 * b21;
  dest[2][2] = a02 * b20 + a12 * b21;
  dest[2][3] = a03 * b20 + a13 * b21;

  dest[3][0] = a00 * b30 + a10 * b31;
  dest[3][1] = a01 * b30 + a11 * b31;
  dest[3][2] = a02 * b30 + a12 * b31;
  dest[3][3] = a03 * b30 + a13 * b31;
}

/*!
 * @brief Multiply mat2x4 (m) by vec2 (v) and store in vec4 (dest).
 *
 * @param[in]  m    mat2x4 (left)
 * @param[in]  v    vec2 (right, column vector)
 * @param[out] dest destination (result, column vector)
 */
CGLM_INLINE
void
glm_mat2x4_mulv(mat2x4 m, vec2 v, vec4 dest) {
  float v0 = v[0], v1 = v[1];

  dest[0] = m[0][0] * v0 + m[1][0] * v1;
  dest[1] = m[0][1] * v0 + m[1][1] * v1;
  dest[2] = m[0][2] * v0 + m[1][2] * v1;
  dest[3] = m[0][3] * v0 + m[1][3] * v1;
}

/*!
 * @brief Transpose mat2x4 (src) and store in mat4x2 (dest).
 *
 * @param[in]  src  mat2x4 (left)
 * @param[out] dest destination (result, mat4x2)
 */
CGLM_INLINE
void
glm_mat2x4_transpose(mat2x4 src, mat4x2 dest) {
  dest[0][0] = src[0][0];  dest[0][1] = src[1][0];
  dest[1][0] = src[0][1];  dest[1][1] = src[1][1];
  dest[2][0] = src[0][2];  dest[2][1] = src[1][2];
  dest[3][0] = src[0][3];  dest[3][1] = src[1][3];
}

/*!
 * @brief Multiply mat2x4 (m) by scalar constant (s).
 *
 * @param[in, out] m (src, dest)
 * @param[in]      s float (scalar)
 */
CGLM_INLINE
void
glm_mat2x4_scale(mat2x4 m, float s) {
  m[0][0] *= s;  m[0][1] *= s;  m[0][2] *= s;  m[0][3] *= s;
  m[1][0] *= s;  m[1][1] *= s;  m[1][2] *= s;  m[1][3] *= s;
}

#endif
