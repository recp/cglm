/*
 * Copyright (c), Recep Aslantas.
 *
 * MIT License (MIT), http://opensource.org/licenses/MIT
 * Full license can be found in the LICENSE file
 */

#ifndef cglm_mat_h
#define cglm_mat_h

#include "cglm.h"
#include "cglm-mat-simd.h"
#include <assert.h>

#define GLM_MAT4_IDENTITY_INIT  {1.0f, 0.0f, 0.0f, 0.0f,                      \
                                 0.0f, 1.0f, 0.0f, 0.0f,                      \
                                 0.0f, 0.0f, 1.0f, 0.0f,                      \
                                 0.0f, 0.0f, 0.0f, 1.0f}

#define GLM_MAT4_IDENTITY (mat4)GLM_MAT4_IDENTITY_INIT

#define glm_mat4_mul_impl(l, r, d)                                            \
 do {                                                                         \
    d[0]  = l[0]  * r[0] + l[1]  * r[4] + l[2]  * r[8]  + l[3]  * r[12];      \
    d[1]  = l[0]  * r[1] + l[1]  * r[5] + l[2]  * r[9]  + l[3]  * r[13];      \
    d[2]  = l[0]  * r[2] + l[1]  * r[6] + l[2]  * r[10] + l[3]  * r[14];      \
    d[3]  = l[0]  * r[3] + l[1]  * r[7] + l[2]  * r[11] + l[3]  * r[15];      \
    d[4]  = l[4]  * r[0] + l[5]  * r[4] + l[6]  * r[8]  + l[7]  * r[12];      \
    d[5]  = l[4]  * r[1] + l[5]  * r[5] + l[6]  * r[9]  + l[7]  * r[13];      \
    d[6]  = l[4]  * r[2] + l[5]  * r[6] + l[6]  * r[10] + l[7]  * r[14];      \
    d[7]  = l[4]  * r[3] + l[5]  * r[7] + l[6]  * r[11] + l[7]  * r[15];      \
    d[8]  = l[8]  * r[0] + l[9]  * r[4] + l[10] * r[8]  + l[11] * r[12];      \
    d[9]  = l[8]  * r[1] + l[9]  * r[5] + l[10] * r[9]  + l[11] * r[13];      \
    d[10] = l[8]  * r[2] + l[9]  * r[6] + l[10] * r[10] + l[11] * r[14];      \
    d[11] = l[8]  * r[3] + l[9]  * r[7] + l[10] * r[11] + l[11] * r[15];      \
    d[12] = l[12] * r[0] + l[13] * r[4] + l[14] * r[8]  + l[15] * r[12];      \
    d[13] = l[12] * r[1] + l[13] * r[5] + l[14] * r[9]  + l[15] * r[13];      \
    d[14] = l[12] * r[2] + l[13] * r[6] + l[14] * r[10] + l[15] * r[14];      \
    d[15] = l[12] * r[3] + l[13] * r[7] + l[14] * r[11] + l[15] * r[15];      \
  } while (0)

CGLM_INLINE
void
glm_mat4_mul(mat4 m1, mat4 m2, mat4 dest) {
  float * __restrict d;
  float * __restrict l;

  d = (float *)dest;
  l = (float *)m1;

  if (m1 != m2) {
    float * __restrict r;

    r = (float *)m2;

#if defined( __SSE__ ) || defined( __SSE2__ )
    CGLM_MAT_MUL_SSE_4x4f(l, r, d);
#else
    glm_mat4_mul_impl(l, r, d);
#endif
  } else {
#if defined( __SSE__ ) || defined( __SSE2__ )
    CGLM_MAT_MUL_SSE_4x4f(l, l, d);
#else
    glm_mat4_mul_impl(l, l, d);
#endif
  }
}

CGLM_INLINE
void
glm_mat4_mulN(mat4 * __restrict matrices[], int len, mat4 dest) {
  int i;

  assert(len > 1 && "there must be least 2 matrices to go!");

  glm_mat4_mul(*matrices[0],
               *matrices[1],
               dest);

  for (i = 2; i < len; i++)
    glm_mat4_mul(dest,
                 *matrices[i],
                 dest);
}

CGLM_INLINE
void
glm_mat4_mulv(mat4 m, vec4 v, vec4 dest) {
  dest[0] = m[0][0] * v[0] + m[1][0] * v[1] + m[2][0] * v[2] + m[3][0] * v[3];
  dest[1] = m[0][1] * v[0] + m[1][1] * v[1] + m[2][1] * v[2] + m[3][1] * v[3];
  dest[2] = m[0][2] * v[0] + m[1][2] * v[1] + m[2][2] * v[2] + m[3][2] * v[3];
  dest[3] = m[0][3] * v[0] + m[1][3] * v[1] + m[2][3] * v[2] + m[3][3] * v[3];
}

CGLM_INLINE
void
glm_mat4_transpose_to(mat4 m, mat4 dest) {
#if defined( __SSE__ ) || defined( __SSE2__ )
  CGLM_MAT_TRANSP_SSE_4x4f(m, dest);
#else
  dest[0][0] = m[0][0];
  dest[0][1] = m[1][0];
  dest[0][2] = m[2][0];
  dest[0][3] = m[3][0];

  dest[1][0] = m[0][1];
  dest[1][1] = m[1][1];
  dest[1][2] = m[2][1];
  dest[1][3] = m[3][1];

  dest[2][0] = m[0][2];
  dest[2][1] = m[1][2];
  dest[2][2] = m[2][2];
  dest[2][3] = m[3][2];

  dest[3][0] = m[0][3];
  dest[3][1] = m[1][3];
  dest[3][2] = m[2][3];
  dest[3][3] = m[3][3];
#endif
}

CGLM_INLINE
void
glm_mat4_transpose(mat4 m) {
#if defined( __SSE__ ) || defined( __SSE2__ )
  CGLM_MAT_TRANSP_SSE_4x4f(m, m);
#else
  mat4 d;

  glm_mat4_transpose_to(m, d);

  glm__memcpy(float, m, d, sizeof(mat4));
#endif
}

CGLM_INLINE
void
glm_mat4_scale_p(mat4 m, float s) {
  m[0][0] *= s; m[0][1] *= s; m[0][2] *= s; m[0][3] *= s;
  m[1][0] *= s; m[1][1] *= s; m[1][2] *= s; m[1][3] *= s;
  m[2][0] *= s; m[2][1] *= s; m[2][2] *= s; m[2][3] *= s;
  m[3][0] *= s; m[3][1] *= s; m[3][2] *= s; m[3][3] *= s;
}

CGLM_INLINE
void
glm_mat4_scale(mat4 m, float s) {
#if defined( __SSE__ ) || defined( __SSE2__ )
  CGLM_MAT_SCALE_SSE_4x4f(m, s);
#else
  glm_mat4_scale_p(m, s);
#endif
}

CGLM_INLINE
float
glm_mat4_det(mat4 mat) {
#if defined( __SSE__ ) || defined( __SSE2__ )
  return glm_mat4_det_sse2(mat);
#else
  float t[6];
  float a, b, c, d,
        e, f, g, h,
        i, j, k, l,
        m, n, o, p;

  a = mat[0][0], b = mat[1][0], c = mat[2][0], d = mat[3][0],
  e = mat[0][1], f = mat[1][1], g = mat[2][1], h = mat[3][1],
  i = mat[0][2], j = mat[1][2], k = mat[2][2], l = mat[3][2],
  m = mat[0][3], n = mat[1][3], o = mat[2][3], p = mat[3][3];

  t[0] = k * p - o * l;
  t[1] = j * p - n * l;
  t[2] = j * o - n * k;
  t[3] = i * p - m * l;
  t[4] = i * o - m * k;
  t[5] = i * n - m * j;

  return   a * (f * t[0] - g * t[1] + h * t[2])
         - b * (e * t[0] - g * t[3] + h * t[4])
         + c * (e * t[1] - f * t[3] + h * t[5])
         - d * (e * t[2] - f * t[4] + g * t[5]);
#endif
}

CGLM_INLINE
void
glm_mat4_inv(mat4 mat, mat4 dest) {
#if defined( __SSE__ ) || defined( __SSE2__ )
  glm_mat4_inv_sse2(mat, dest);
#else
  float t[6];
  float det;
  float a, b, c, d,
        e, f, g, h,
        i, j, k, l,
        m, n, o, p;

  a = mat[0][0], b = mat[0][1], c = mat[0][2], d = mat[0][3],
  e = mat[1][0], f = mat[1][1], g = mat[1][2], h = mat[1][3],
  i = mat[2][0], j = mat[2][1], k = mat[2][2], l = mat[2][3],
  m = mat[3][0], n = mat[3][1], o = mat[3][2], p = mat[3][3];

  t[0] = k * p - o * l; t[1] = j * p - n * l; t[2] = j * o - n * k;
  t[3] = i * p - m * l; t[4] = i * o - m * k; t[5] = i * n - m * j;

  dest[0][0] =  f * t[0] - g * t[1] + h * t[2];
  dest[1][0] =-(e * t[0] - g * t[3] + h * t[4]);
  dest[2][0] =  e * t[1] - f * t[3] + h * t[5];
  dest[3][0] =-(e * t[2] - f * t[4] + g * t[5]);

  dest[0][1] =-(b * t[0] - c * t[1] + d * t[2]);
  dest[1][1] =  a * t[0] - c * t[3] + d * t[4];
  dest[2][1] =-(a * t[1] - b * t[3] + d * t[5]);
  dest[3][1] =  a * t[2] - b * t[4] + c * t[5];

  t[0] = g * p - o * h; t[1] = f * p - n * h; t[2] = f * o - n * g;
  t[3] = e * p - m * h; t[4] = e * o - m * g; t[5] = e * n - m * f;

  dest[0][2] =  b * t[0] - c * t[1] + d * t[2];
  dest[1][2] =-(a * t[0] - c * t[3] + d * t[4]);
  dest[2][2] =  a * t[1] - b * t[3] + d * t[5];
  dest[3][2] =-(a * t[2] - b * t[4] + c * t[5]);

  t[0] = g * l - k * h; t[1] = f * l - j * h; t[2] = f * k - j * g;
  t[3] = e * l - i * h; t[4] = e * k - i * g; t[5] = e * j - i * f;

  dest[0][3] =-(b * t[0] - c * t[1] + d * t[2]);
  dest[1][3] =  a * t[0] - c * t[3] + d * t[4];
  dest[2][3] =-(a * t[1] - b * t[3] + d * t[5]);
  dest[3][3] =  a * t[2] - b * t[4] + c * t[5];

  det = 1.0f / (a * dest[0][0] + b * dest[1][0]
              + c * dest[2][0] + d * dest[3][0]);

  glm_mat4_scale_p(dest, det);
#endif
}

#endif /* cglm_mat_h */
