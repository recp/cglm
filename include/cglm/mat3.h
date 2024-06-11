/*
 * Copyright (c), Recep Aslantas.
 *
 * MIT License (MIT), http://opensource.org/licenses/MIT
 * Full license can be found in the LICENSE file
 */

/*
 Macros:
   GLM_MAT3_IDENTITY_INIT
   GLM_MAT3_ZERO_INIT
   GLM_MAT3_IDENTITY
   GLM_MAT3_ZERO
   glm_mat3_dup(mat, dest)

 Functions:
   CGLM_INLINE void  glm_mat3_copy(mat3 mat, mat3 dest);
   CGLM_INLINE void  glm_mat3_identity(mat3 mat);
   CGLM_INLINE void  glm_mat3_identity_array(mat3 * restrict mat, size_t count);
   CGLM_INLINE void  glm_mat3_zero(mat3 mat);
   CGLM_INLINE void  glm_mat3_mul(mat3 m1, mat3 m2, mat3 dest);
   CGLM_INLINE void  glm_mat3_transpose_to(mat3 m, mat3 dest);
   CGLM_INLINE void  glm_mat3_transpose(mat3 m);
   CGLM_INLINE void  glm_mat3_mulv(mat3 m, vec3 v, vec3 dest);
   CGLM_INLINE float glm_mat3_trace(mat3 m);
   CGLM_INLINE void  glm_mat3_quat(mat3 m, versor dest);
   CGLM_INLINE void  glm_mat3_scale(mat3 m, float s);
   CGLM_INLINE float glm_mat3_det(mat3 mat);
   CGLM_INLINE void  glm_mat3_inv(mat3 mat, mat3 dest);
   CGLM_INLINE void  glm_mat3_swap_col(mat3 mat, int col1, int col2);
   CGLM_INLINE void  glm_mat3_swap_row(mat3 mat, int row1, int row2);
   CGLM_INLINE float glm_mat3_rmc(vec3 r, mat3 m, vec3 c);
   CGLM_INLINE void  glm_mat3_make(float * restrict src, mat3 dest);
 */

#ifndef cglm_mat3_h
#define cglm_mat3_h

#include "common.h"
#include "vec3.h"

#ifdef CGLM_SSE_FP
#  include "simd/sse2/mat3.h"
#endif

#ifdef CGLM_SIMD_WASM
#  include "simd/wasm/mat3.h"
#endif

#define GLM_MAT3_IDENTITY_INIT  {{1.0f, 0.0f, 0.0f},                          \
                                 {0.0f, 1.0f, 0.0f},                          \
                                 {0.0f, 0.0f, 1.0f}}
#define GLM_MAT3_ZERO_INIT      {{0.0f, 0.0f, 0.0f},                          \
                                 {0.0f, 0.0f, 0.0f},                          \
                                 {0.0f, 0.0f, 0.0f}}


/* for C only */
#define GLM_MAT3_IDENTITY ((mat3)GLM_MAT3_IDENTITY_INIT)
#define GLM_MAT3_ZERO     ((mat3)GLM_MAT3_ZERO_INIT)

/* DEPRECATED! use _copy, _ucopy versions */
#define glm_mat3_dup(mat, dest) glm_mat3_copy(mat, dest)

/*!
 * @brief copy all members of [mat] to [dest]
 *
 * @param[in]  mat  source
 * @param[out] dest destination
 */
CGLM_INLINE
void
glm_mat3_copy(mat3 mat, mat3 dest) {
  dest[0][0] = mat[0][0];
  dest[0][1] = mat[0][1];
  dest[0][2] = mat[0][2];

  dest[1][0] = mat[1][0];
  dest[1][1] = mat[1][1];
  dest[1][2] = mat[1][2];

  dest[2][0] = mat[2][0];
  dest[2][1] = mat[2][1];
  dest[2][2] = mat[2][2];
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
 * @param[in, out]  mat  destination
 */
CGLM_INLINE
void
glm_mat3_identity(mat3 mat) {
  CGLM_ALIGN_MAT mat3 t = GLM_MAT3_IDENTITY_INIT;
  glm_mat3_copy(t, mat);
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
glm_mat3_identity_array(mat3 * __restrict mat, size_t count) {
  CGLM_ALIGN_MAT mat3 t = GLM_MAT3_IDENTITY_INIT;
  size_t i;

  for (i = 0; i < count; i++) {
    glm_mat3_copy(t, mat[i]);
  }
}

/*!
 * @brief make given matrix zero.
 *
 * @param[in, out]  mat  matrix
 */
CGLM_INLINE
void
glm_mat3_zero(mat3 mat) {
  CGLM_ALIGN_MAT mat3 t = GLM_MAT3_ZERO_INIT;
  glm_mat3_copy(t, mat);
}

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
 * @param[out] dest destination matrix
 */
CGLM_INLINE
void
glm_mat3_mul(mat3 m1, mat3 m2, mat3 dest) {
#if defined(__wasm__) && defined(__wasm_simd128__)
  glm_mat3_mul_wasm(m1, m2, dest);
#elif defined( __SSE__ ) || defined( __SSE2__ )
  glm_mat3_mul_sse2(m1, m2, dest);
#else
  float a00 = m1[0][0], a01 = m1[0][1], a02 = m1[0][2],
        a10 = m1[1][0], a11 = m1[1][1], a12 = m1[1][2],
        a20 = m1[2][0], a21 = m1[2][1], a22 = m1[2][2],

        b00 = m2[0][0], b01 = m2[0][1], b02 = m2[0][2],
        b10 = m2[1][0], b11 = m2[1][1], b12 = m2[1][2],
        b20 = m2[2][0], b21 = m2[2][1], b22 = m2[2][2];

  dest[0][0] = a00 * b00 + a10 * b01 + a20 * b02;
  dest[0][1] = a01 * b00 + a11 * b01 + a21 * b02;
  dest[0][2] = a02 * b00 + a12 * b01 + a22 * b02;
  dest[1][0] = a00 * b10 + a10 * b11 + a20 * b12;
  dest[1][1] = a01 * b10 + a11 * b11 + a21 * b12;
  dest[1][2] = a02 * b10 + a12 * b11 + a22 * b12;
  dest[2][0] = a00 * b20 + a10 * b21 + a20 * b22;
  dest[2][1] = a01 * b20 + a11 * b21 + a21 * b22;
  dest[2][2] = a02 * b20 + a12 * b21 + a22 * b22;
#endif
}

/*!
 * @brief transpose mat3 and store in dest
 *
 * source matrix will not be transposed unless dest is m
 *
 * @param[in]  m     matrix
 * @param[out] dest  result
 */
CGLM_INLINE
void
glm_mat3_transpose_to(mat3 m, mat3 dest) {
  dest[0][0] = m[0][0];
  dest[0][1] = m[1][0];
  dest[0][2] = m[2][0];
  dest[1][0] = m[0][1];
  dest[1][1] = m[1][1];
  dest[1][2] = m[2][1];
  dest[2][0] = m[0][2];
  dest[2][1] = m[1][2];
  dest[2][2] = m[2][2];
}

/*!
 * @brief transpose mat3 and store result in same matrix
 *
 * @param[in, out] m source and dest
 */
CGLM_INLINE
void
glm_mat3_transpose(mat3 m) {
  CGLM_ALIGN_MAT mat3 tmp;

  tmp[0][1] = m[1][0];
  tmp[0][2] = m[2][0];
  tmp[1][0] = m[0][1];
  tmp[1][2] = m[2][1];
  tmp[2][0] = m[0][2];
  tmp[2][1] = m[1][2];

  m[0][1] = tmp[0][1];
  m[0][2] = tmp[0][2];
  m[1][0] = tmp[1][0];
  m[1][2] = tmp[1][2];
  m[2][0] = tmp[2][0];
  m[2][1] = tmp[2][1];
}

/*!
 * @brief multiply mat3 with vec3 (column vector) and store in dest vector
 *
 * @param[in]  m    mat3 (left)
 * @param[in]  v    vec3 (right, column vector)
 * @param[out] dest vec3 (result, column vector)
 */
CGLM_INLINE
void
glm_mat3_mulv(mat3 m, vec3 v, vec3 dest) {
  vec3 res;
  res[0] = m[0][0] * v[0] + m[1][0] * v[1] + m[2][0] * v[2];
  res[1] = m[0][1] * v[0] + m[1][1] * v[1] + m[2][1] * v[2];
  res[2] = m[0][2] * v[0] + m[1][2] * v[1] + m[2][2] * v[2];
  glm_vec3_copy(res, dest);
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
glm_mat3_trace(mat3 m) {
  return m[0][0] + m[1][1] + m[2][2];
}

/*!
 * @brief convert mat3 to quaternion
 *
 * @param[in]  m    rotation matrix
 * @param[out] dest destination quaternion
 */
CGLM_INLINE
void
glm_mat3_quat(mat3 m, versor dest) {
  float trace, r, rinv;

  /* it seems using like m12 instead of m[1][2] causes extra instructions */

  trace = m[0][0] + m[1][1] + m[2][2];
  if (trace >= 0.0f) {
    r       = sqrtf(1.0f + trace);
    rinv    = 0.5f / r;

    dest[0] = rinv * (m[1][2] - m[2][1]);
    dest[1] = rinv * (m[2][0] - m[0][2]);
    dest[2] = rinv * (m[0][1] - m[1][0]);
    dest[3] = r    * 0.5f;
  } else if (m[0][0] >= m[1][1] && m[0][0] >= m[2][2]) {
    r       = sqrtf(1.0f - m[1][1] - m[2][2] + m[0][0]);
    rinv    = 0.5f / r;

    dest[0] = r    * 0.5f;
    dest[1] = rinv * (m[0][1] + m[1][0]);
    dest[2] = rinv * (m[0][2] + m[2][0]);
    dest[3] = rinv * (m[1][2] - m[2][1]);
  } else if (m[1][1] >= m[2][2]) {
    r       = sqrtf(1.0f - m[0][0] - m[2][2] + m[1][1]);
    rinv    = 0.5f / r;

    dest[0] = rinv * (m[0][1] + m[1][0]);
    dest[1] = r    * 0.5f;
    dest[2] = rinv * (m[1][2] + m[2][1]);
    dest[3] = rinv * (m[2][0] - m[0][2]);
  } else {
    r       = sqrtf(1.0f - m[0][0] - m[1][1] + m[2][2]);
    rinv    = 0.5f / r;

    dest[0] = rinv * (m[0][2] + m[2][0]);
    dest[1] = rinv * (m[1][2] + m[2][1]);
    dest[2] = r    * 0.5f;
    dest[3] = rinv * (m[0][1] - m[1][0]);
  }
}

/*!
 * @brief scale (multiply with scalar) matrix
 *
 * multiply matrix with scalar
 *
 * @param[in, out] m matrix
 * @param[in]      s scalar
 */
CGLM_INLINE
void
glm_mat3_scale(mat3 m, float s) {
  m[0][0] *= s; m[0][1] *= s; m[0][2] *= s;
  m[1][0] *= s; m[1][1] *= s; m[1][2] *= s;
  m[2][0] *= s; m[2][1] *= s; m[2][2] *= s;
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
glm_mat3_det(mat3 mat) {
  float a = mat[0][0], b = mat[0][1], c = mat[0][2],
        d = mat[1][0], e = mat[1][1], f = mat[1][2],
        g = mat[2][0], h = mat[2][1], i = mat[2][2];

  return a * (e * i - h * f) - d * (b * i - h * c) + g * (b * f - e * c);
}

/*!
 * @brief inverse mat3 and store in dest
 *
 * @param[in]  mat  matrix
 * @param[out] dest inverse matrix
 */
CGLM_INLINE
void
glm_mat3_inv(mat3 mat, mat3 dest) {
  float a = mat[0][0], b = mat[0][1], c = mat[0][2],
        d = mat[1][0], e = mat[1][1], f = mat[1][2],
        g = mat[2][0], h = mat[2][1], i = mat[2][2],

        c1  = e * i - f * h, c2 = d * i - g * f, c3 = d * h - g * e,
        idt = 1.0f / (a * c1 - b * c2 + c * c3), ndt = -idt;

  dest[0][0] = idt * c1;
  dest[0][1] = ndt * (b * i - h * c);
  dest[0][2] = idt * (b * f - e * c);
  dest[1][0] = ndt * c2;
  dest[1][1] = idt * (a * i - g * c);
  dest[1][2] = ndt * (a * f - d * c);
  dest[2][0] = idt * c3;
  dest[2][1] = ndt * (a * h - g * b);
  dest[2][2] = idt * (a * e - d * b);
}

/*!
 * @brief swap two matrix columns
 *
 * @param[in,out] mat  matrix
 * @param[in]     col1 col1
 * @param[in]     col2 col2
 */
CGLM_INLINE
void
glm_mat3_swap_col(mat3 mat, int col1, int col2) {
  vec3 tmp;
  glm_vec3_copy(mat[col1], tmp);
  glm_vec3_copy(mat[col2], mat[col1]);
  glm_vec3_copy(tmp, mat[col2]);
}

/*!
 * @brief swap two matrix rows
 *
 * @param[in,out] mat  matrix
 * @param[in]     row1 row1
 * @param[in]     row2 row2
 */
CGLM_INLINE
void
glm_mat3_swap_row(mat3 mat, int row1, int row2) {
  vec3 tmp;
  tmp[0] = mat[0][row1];
  tmp[1] = mat[1][row1];
  tmp[2] = mat[2][row1];

  mat[0][row1] = mat[0][row2];
  mat[1][row1] = mat[1][row2];
  mat[2][row1] = mat[2][row2];

  mat[0][row2] = tmp[0];
  mat[1][row2] = tmp[1];
  mat[2][row2] = tmp[2];
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
glm_mat3_rmc(vec3 r, mat3 m, vec3 c) {
  vec3 tmp;
  glm_mat3_mulv(m, c, tmp);
  return glm_vec3_dot(r, tmp);
}

/*!
 * @brief Create mat3 matrix from pointer
 *
 * @param[in]  src  pointer to an array of floats
 * @param[out] dest matrix
 */
CGLM_INLINE
void
glm_mat3_make(const float * __restrict src, mat3 dest) {
  dest[0][0] = src[0];
  dest[0][1] = src[1];
  dest[0][2] = src[2];

  dest[1][0] = src[3];
  dest[1][1] = src[4];
  dest[1][2] = src[5];

  dest[2][0] = src[6];
  dest[2][1] = src[7];
  dest[2][2] = src[8];
}

#endif /* cglm_mat3_h */
