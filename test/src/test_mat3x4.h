/*
 * Copyright (c), Recep Aslantas.
 *
 * MIT License (MIT), http://opensource.org/licenses/MIT
 * Full license can be found in the LICENSE file
 */

#include "test_common.h"

#define A_MATRIX3X4 {{1,2,4,5},{6,7,8,9},{10,11,12,13}}
#define A_MATRIX3X4_TRANSPOSE {{1,6,10}, {2,7,1}, {4,8,12}, {5,9,13}}

#ifndef CGLM_TEST_MAT3X4_ONCE
#define CGLM_TEST_MAT3X4_ONCE

TEST_IMPL(MACRO_GLM_MAT3X4_ZERO_INIT) {
  mat3x4 mat3x4_zero = GLM_MAT3X4_ZERO_INIT;
  test_assert_mat3x4_eq_zero(mat3x4_zero);
  TEST_SUCCESS
}

TEST_IMPL(MACRO_GLM_MAT3X4_ZERO) {
  mat3x4 mat3x4_zero = GLM_MAT3X4_ZERO;
  test_assert_mat3x4_eq_zero(mat3x4_zero);
  TEST_SUCCESS
}

#endif /* CGLM_TEST_MAT3X4_ONCE */

TEST_IMPL(GLM_PREFIX, mat3x4_copy) {
  mat3x4 m1 = A_MATRIX3X4;
  mat3x4 m2 = GLM_MAT3X4_ZERO_INIT;

  GLM(mat3x4_copy)(m1, m2);

  test_assert_mat3x4_eq(m1, m2);

  TEST_SUCCESS
}

TEST_IMPL(GLM_PREFIX, mat3x4_zero) {
  mat3x4 m1 = GLM_MAT3X4_ZERO_INIT;
  mat3x4 m2 = GLM_MAT3X4_ZERO_INIT;
  mat3x4 m3;

  GLM(mat3x4_zero)(m3);

  ASSERTIFY(test_assert_mat3x4_eq_zero(m1))
  ASSERTIFY(test_assert_mat3x4_eq_zero(m2))
  ASSERTIFY(test_assert_mat3x4_eq_zero(m3))

  TEST_SUCCESS
}

TEST_IMPL(GLM_PREFIX, mat3x4_make) {
  float src[36] = {
    0.5f, 1.7f, 10.3f, 4.2f, 8.9f, 1.1f, 2.3f, 4.2f, 66.5f, 23.7f, 6.6f, 8.9f,
    2.3f, 4.2f, 66.5f, 23.7f, 6.6f, 8.9f, 0.5f, 1.7f, 10.3f, 4.2f, 8.9f, 1.1f,
    5.3f, 4.8f, 96.3f, 13.7f, 4.7f, 5.5f, 2.3f, 4.2f, 66.5f, 23.7f, 6.6f, 8.9f
  };

  mat3x4 dest[3];

  float *srcp = src;
  unsigned int i, j, k;

  for (i = 0, j = 0, k = 0; i < sizeof(src) / sizeof(float); i+=12,j++) {
    GLM(mat3x4_make)(srcp + i, dest[j]);

    ASSERT(test_eq(src[ i ], dest[j][k][0]));
    ASSERT(test_eq(src[i+1], dest[j][k][1]));
    ASSERT(test_eq(src[i+2], dest[j][k][2]));
    ASSERT(test_eq(src[i+3], dest[j][k][3]));

    ASSERT(test_eq(src[i+4], dest[j][k+1][0]));
    ASSERT(test_eq(src[i+5], dest[j][k+1][1]));
    ASSERT(test_eq(src[i+6], dest[j][k+1][2]));
    ASSERT(test_eq(src[i+7], dest[j][k+1][3]));

    ASSERT(test_eq(src[i+8], dest[j][k+2][0]));
    ASSERT(test_eq(src[i+9], dest[j][k+2][1]));
    ASSERT(test_eq(src[i+10], dest[j][k+2][2]));
    ASSERT(test_eq(src[i+11], dest[j][k+2][3]));
  }

  TEST_SUCCESS
}

TEST_IMPL(GLM_PREFIX, mat3x4_mul) {
  mat3x4 m1 = GLM_MAT3X4_ZERO_INIT;
  mat4x3 m2 = GLM_MAT4X3_ZERO_INIT;

  mat4 m3 = GLM_MAT4_ZERO_INIT;
  mat4 m4 = GLM_MAT4_ZERO_INIT;

  int c, r, k;

  test_rand_mat3x4(m1);
  test_rand_mat4x3(m2);

  for (r = 0; r < 4; r++) {
    for (c = 0; c < 4; c++) {
      for (k = 0; k < 3; k++) {
        m4[c][r] += m1[k][r] * m2[c][k];
      }
    }
  }

  GLM(mat3x4_mul)(m1, m2, m3);
  ASSERTIFY(test_assert_mat4_eq(m3, m4))

  TEST_SUCCESS
}

TEST_IMPL(GLM_PREFIX, mat3x4_mulv) {
  mat3x4 mat = A_MATRIX3X4;
  vec4 v = {11.0f, 21.0f, 31.0f};

  int  i;
  vec4 dest;
  float res = 0.0;

  GLM(mat3x4_mulv)(mat, v, dest);

  for (i = 0; i < 4; i++) {
    res = mat[0][i] * v[0] + mat[1][i] * v[1] + mat[2][i] * v[2];
    ASSERT(test_eq(dest[i], res))
  }

  TEST_SUCCESS
}

TEST_IMPL(GLM_PREFIX, mat3x4_transpose) {
  mat3x4 m1 = A_MATRIX3X4;

  mat4x3 m2;
  mat4x3 m3 = A_MATRIX3X2_TRANSPOSE;
  GLM(mat3x4_transpose)(m1, m2);

  ASSERTIFY(test_assert_mat4x3_eq(m2, m3))

  TEST_SUCCESS
}

TEST_IMPL(GLM_PREFIX, mat3x4_scale) {
  mat3x4 m1 = A_MATRIX3X4;
  mat3x4 m2 = A_MATRIX3X4;
  int i, j;
  float scale;

  scale = rand() % 100;

  GLM(mat3x4_scale)(m1, scale);

  for (i = 0; i < 3; i++) {
    for (j = 0; j < 4; j++) {
      ASSERT(test_eq(m1[i][j], m2[i][j] * scale))
    }
  }

  TEST_SUCCESS
}
