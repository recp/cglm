/*
 * Copyright (c), Recep Aslantas.
 *
 * MIT License (MIT), http://opensource.org/licenses/MIT
 * Full license can be found in the LICENSE file
 */

#include "test_common.h"

#define A_MATRIX2X3 {{1,2,3},{5,6,7}}
#define A_MATRIX2X3_TRANSPOSE {{1,5}, {2,6}, {3,7}}

#ifndef CGLM_TEST_MAT2X3_ONCE
#define CGLM_TEST_MAT2X3_ONCE

TEST_IMPL(MACRO_GLM_MAT2X3_ZERO_INIT) {
  mat2x3 mat2x3_zero   = GLM_MAT2X3_ZERO_INIT;
  test_assert_mat2x3_eq_zero(mat2x3_zero);
  TEST_SUCCESS
}

TEST_IMPL(MACRO_GLM_MAT2X3_ZERO) {
  mat2x3 mat2x3_zero   = GLM_MAT2X3_ZERO;
  test_assert_mat2x3_eq_zero(mat2x3_zero);
  TEST_SUCCESS
}

#endif /* CGLM_TEST_MAT2X3_ONCE */

TEST_IMPL(GLM_PREFIX, mat2x3_copy) {
  mat2x3 m1 = A_MATRIX2X3;
  mat2x3 m2 = GLM_MAT2X3_ZERO_INIT;

  GLM(mat2x3_copy)(m1, m2);

  test_assert_mat2x3_eq(m1, m2);

  TEST_SUCCESS
}

TEST_IMPL(GLM_PREFIX, mat2x3_zero) {
  mat2x3 m1 = GLM_MAT2X3_ZERO_INIT;
  mat2x3 m2 = GLM_MAT2X3_ZERO_INIT;
  mat2x3 m3;

  GLM(mat2x3_zero)(m3);

  ASSERTIFY(test_assert_mat2x3_eq_zero(m1))
  ASSERTIFY(test_assert_mat2x3_eq_zero(m2))
  ASSERTIFY(test_assert_mat2x3_eq_zero(m3))

  TEST_SUCCESS
}

TEST_IMPL(GLM_PREFIX, mat2x3_make) {
  float src[18] = {
    0.5f, 1.7f, 10.3f, 4.2f, 8.9f, 1.1f,
    2.3f, 4.2f, 66.5f, 23.7f, 6.6f, 8.9f,
    5.3f, 4.8f, 96.3f, 13.7f, 4.7f, 5.5f
  };

  mat2x3 dest[3];

  float *srcp = src;
  unsigned int i, j, k;

  for (i = 0, j = 0, k = 0; i < sizeof(src) / sizeof(float); i+=6,j++) {
    GLM(mat2x3_make)(srcp + i, dest[j]);

    ASSERT(test_eq(src[ i ], dest[j][k][0]));
    ASSERT(test_eq(src[i+1], dest[j][k][1]));
    ASSERT(test_eq(src[i+2], dest[j][k][2]));

    ASSERT(test_eq(src[i+3], dest[j][k+1][0]));
    ASSERT(test_eq(src[i+4], dest[j][k+1][1]));
    ASSERT(test_eq(src[i+5], dest[j][k+1][2]));
  }

  TEST_SUCCESS
}

TEST_IMPL(GLM_PREFIX, mat2x3_mul) {
  mat2x3 m1 = GLM_MAT2X3_ZERO_INIT;
  mat3x2 m2 = GLM_MAT3X2_ZERO_INIT;

  mat3 m3 = GLM_MAT3_ZERO_INIT;
  mat3 m4 = GLM_MAT3_ZERO_INIT;

  int c, r, k;

  /* test random matrices */
  /* random matrices */
  test_rand_mat2x3(m1);
  test_rand_mat3x2(m2);

  for (r = 0; r < 3; r++) {
    for (c = 0; c < 3; c++) {
      for (k = 0; k < 2; k++) {
        m4[c][r] += m1[k][r] * m2[c][k];
      }
    }
  }

  GLM(mat2x3_mul)(m1, m2, m3);
  ASSERTIFY(test_assert_mat3_eq(m3, m4))

  TEST_SUCCESS
}

TEST_IMPL(GLM_PREFIX, mat2x3_mulv) {
  mat2x3 mat = A_MATRIX2X3;
  vec2 v = {11.0f, 21.0f};

  int  i;
  vec3 dest;
  float res = 0.0;

  GLM(mat2x3_mulv)(mat, v, dest);

  for (i = 0; i < 3; i++) {
    res = mat[0][i] * v[0] + mat[1][i] * v[1];
    ASSERT(test_eq(dest[i], res))
  }

  TEST_SUCCESS
}

TEST_IMPL(GLM_PREFIX, mat2x3_transpose) {
  mat2x3 m1 = A_MATRIX2X3;

  mat3x2 m2;
  mat3x2 m3 = A_MATRIX2X3_TRANSPOSE;
  GLM(mat2x3_transpose)(m1, m2);

  ASSERTIFY(test_assert_mat3x2_eq(m2, m3))

  TEST_SUCCESS
}

TEST_IMPL(GLM_PREFIX, mat2x3_scale) {
  mat2x3 m1 = A_MATRIX2X3;
  mat2x3 m2 = A_MATRIX2X3;
  int i, j, scale;

  scale = rand() % 100;

  GLM(mat2x3_scale)(m1, (float) scale);

  for (i = 0; i < 2; i++) {
    for (j = 0; j < 3; j++) {
      ASSERT(test_eq(m1[i][j], m2[i][j] * scale))
    }
  }

  TEST_SUCCESS
}
