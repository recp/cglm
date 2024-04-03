/*
 * Copyright (c), Recep Aslantas.
 *
 * MIT License (MIT), http://opensource.org/licenses/MIT
 * Full license can be found in the LICENSE file
 */

#include "test_common.h"

#define A_MATRIX3X2 {{1,2},{5,6},{3,7}}
#define A_MATRIX3X2_TRANSPOSE {{1,5,3}, {2,6,7}}

#ifndef CGLM_TEST_MAT3X2_ONCE
#define CGLM_TEST_MAT3X2_ONCE

TEST_IMPL(MACRO_GLM_MAT3X2_ZERO_INIT) {
  mat3x2 mat3x2_zero = GLM_MAT3X2_ZERO_INIT;
  test_assert_mat3x2_eq_zero(mat3x2_zero);
  TEST_SUCCESS
}

TEST_IMPL(MACRO_GLM_MAT3X2_ZERO) {
  mat3x2 mat3x2_zero = GLM_MAT3X2_ZERO;
  test_assert_mat3x2_eq_zero(mat3x2_zero);
  TEST_SUCCESS
}

#endif /* CGLM_TEST_MAT3X2_ONCE */

TEST_IMPL(GLM_PREFIX, mat3x2_copy) {
  mat3x2 m1 = A_MATRIX3X2;
  mat3x2 m2 = GLM_MAT3X2_ZERO_INIT;

  GLM(mat3x2_copy)(m1, m2);

  test_assert_mat3x2_eq(m1, m2);

  TEST_SUCCESS
}

TEST_IMPL(GLM_PREFIX, mat3x2_zero) {
  mat3x2 m1 = GLM_MAT3X2_ZERO_INIT;
  mat3x2 m2 = GLM_MAT3X2_ZERO_INIT;
  mat3x2 m3;

  GLM(mat3x2_zero)(m3);

  ASSERTIFY(test_assert_mat3x2_eq_zero(m1))
  ASSERTIFY(test_assert_mat3x2_eq_zero(m2))
  ASSERTIFY(test_assert_mat3x2_eq_zero(m3))

  TEST_SUCCESS
}

TEST_IMPL(GLM_PREFIX, mat3x2_make) {
  float src[18] = {
    0.5f, 1.7f, 10.3f, 4.2f, 8.9f, 1.1f,
    2.3f, 4.2f, 66.5f, 23.7f, 6.6f, 8.9f,
    5.3f, 4.8f, 96.3f, 13.7f, 4.7f, 5.5f
  };

  mat3x2 dest[3];

  float *srcp = src;
  unsigned int i, j, k;

  for (i = 0, j = 0, k = 0; i < sizeof(src) / sizeof(float); i+=6,j++) {
    GLM(mat3x2_make)(srcp + i, dest[j]);

    ASSERT(test_eq(src[ i ], dest[j][k][0]));
    ASSERT(test_eq(src[i+1], dest[j][k][1]));

    ASSERT(test_eq(src[i+2], dest[j][k+1][0]));
    ASSERT(test_eq(src[i+3], dest[j][k+1][1]));

    ASSERT(test_eq(src[i+4], dest[j][k+2][0]));
    ASSERT(test_eq(src[i+5], dest[j][k+2][1]));
  }

  TEST_SUCCESS
}

TEST_IMPL(GLM_PREFIX, mat3x2_mul) {
  mat3x2 m1 = GLM_MAT3X2_ZERO_INIT;
  mat2x3 m2 = GLM_MAT2X3_ZERO_INIT;

  mat2 m3 = GLM_MAT2_ZERO_INIT;
  mat2 m4 = GLM_MAT2_ZERO_INIT;

  int c, r, k;

  test_rand_mat3x2(m1);
  test_rand_mat2x3(m2);

  for (r = 0; r < 2; r++) {
    for (c = 0; c < 2; c++) {
      for (k = 0; k < 3; k++) {
        m4[c][r] += m1[k][r] * m2[c][k];
      }
    }
  }

  GLM(mat3x2_mul)(m1, m2, m3);
  ASSERTIFY(test_assert_mat2_eq(m3, m4))

  TEST_SUCCESS
}

TEST_IMPL(GLM_PREFIX, mat3x2_mulv) {
  mat3x2 mat = A_MATRIX3X2;
  vec3 v = {11.0f, 21.0f, 31.0f};

  int  i;
  vec2 dest;
  float res = 0.0;

  GLM(mat3x2_mulv)(mat, v, dest);

  for (i = 0; i < 2; i++) {
    res = mat[0][i] * v[0] + mat[1][i] * v[1] + mat[2][i] * v[2];
    ASSERT(test_eq(dest[i], res))
  }

  TEST_SUCCESS
}

TEST_IMPL(GLM_PREFIX, mat3x2_transpose) {
  mat3x2 m1 = A_MATRIX3X2;

  mat2x3 m2;
  mat2x3 m3 = A_MATRIX3X2_TRANSPOSE;
  GLM(mat3x2_transpose)(m1, m2);

  ASSERTIFY(test_assert_mat2x3_eq(m2, m3))

  TEST_SUCCESS
}

TEST_IMPL(GLM_PREFIX, mat3x2_scale) {
  mat3x2 m1 = A_MATRIX3X2;
  mat3x2 m2 = A_MATRIX3X2;
  int i, j, scale;

  scale = rand() % 100;

  GLM(mat3x2_scale)(m1, (float) scale);

  for (i = 0; i < 3; i++) {
    for (j = 0; j < 2; j++) {
      ASSERT(test_eq(m1[i][j], m2[i][j] * scale))
    }
  }

  TEST_SUCCESS
}
