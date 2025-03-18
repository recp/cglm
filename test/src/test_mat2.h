/*
 * Copyright (c), Recep Aslantas.
 *
 * MIT License (MIT), http://opensource.org/licenses/MIT
 * Full license can be found in the LICENSE file
 */

#include "test_common.h"

#define A_MATRIX2x2 {{1,2},{5,6}}
#define MAT2_ARRAY {1, 5, 2, 7}

#ifndef CGLM_TEST_MAT2_ONCE
#define CGLM_TEST_MAT2_ONCE

TEST_IMPL(MACRO_GLM_MAT2_IDENTITY_INIT) {
  mat2 m = GLM_MAT2_IDENTITY_INIT;
  
  ASSERT(test_eq(m[0][0], 1.0f))
  ASSERT(test_eq(m[0][1], 0.0f))
  ASSERT(test_eq(m[1][0], 0.0f))
  ASSERT(test_eq(m[1][1], 1.0f))

  TEST_SUCCESS
}

TEST_IMPL(MACRO_GLM_MAT2_ZERO_INIT) {  
  mat2 m = GLM_MAT2_ZERO_INIT;
  
  ASSERT(test_eq(m[0][0], 0.0f))
  ASSERT(test_eq(m[0][1], 0.0f))
  ASSERT(test_eq(m[1][0], 0.0f))
  ASSERT(test_eq(m[1][1], 0.0f))

  TEST_SUCCESS
}

TEST_IMPL(MACRO_GLM_MAT2_IDENTITY) {
  ASSERT(test_eq(GLM_MAT2_IDENTITY[0][0], 1.0f))
  ASSERT(test_eq(GLM_MAT2_IDENTITY[0][1], 0.0f))
  ASSERT(test_eq(GLM_MAT2_IDENTITY[1][0], 0.0f))
  ASSERT(test_eq(GLM_MAT2_IDENTITY[1][1], 1.0f))

  TEST_SUCCESS
}

TEST_IMPL(MACRO_GLM_MAT2_ZERO) {
  ASSERT(test_eq(GLM_MAT2_ZERO[0][0], 0.0f))
  ASSERT(test_eq(GLM_MAT2_ZERO[0][1], 0.0f))
  ASSERT(test_eq(GLM_MAT2_ZERO[1][0], 0.0f))
  ASSERT(test_eq(GLM_MAT2_ZERO[1][1], 0.0f))

  TEST_SUCCESS
}

#endif /* CGLM_TEST_MAT2_ONCE */

TEST_IMPL(GLM_PREFIX, mat2_copy) {
  mat2 m1 = A_MATRIX2x2;
  mat2 m2 = GLM_MAT2_IDENTITY_INIT;

  GLM(mat2_copy)(m1, m2);

  test_assert_mat2_eq(m1, m2);

  TEST_SUCCESS
}

TEST_IMPL(GLM_PREFIX, mat2_identity) {
  mat2 m1 = GLM_MAT2_IDENTITY_INIT;
  mat2 m2 = GLM_MAT2_IDENTITY_INIT;
  mat2 m3;

  GLM(mat2_identity)(m3);

  ASSERTIFY(test_assert_mat2_eq_identity(m1))
  ASSERTIFY(test_assert_mat2_eq_identity(m2))
  ASSERTIFY(test_assert_mat2_eq_identity(m3))

  TEST_SUCCESS
}

TEST_IMPL(GLM_PREFIX, mat2_identity_array) {
  size_t i, count;
  mat2 matrices[4] = {
    A_MATRIX2x2,
    A_MATRIX2x2,
    A_MATRIX2x2,
    A_MATRIX2x2
  };

  count = 4;

  GLM(mat2_identity_array)(matrices, count);

  for (i = 0; i < count; i++) {
    ASSERTIFY(test_assert_mat2_eq_identity(matrices[i]))
  }

  TEST_SUCCESS
}

TEST_IMPL(GLM_PREFIX, mat2_zero) {
  mat2 m1 = GLM_MAT2_ZERO_INIT;
  mat2 m2 = GLM_MAT2_ZERO_INIT;
  mat2 m3;

  GLM(mat2_zero)(m3);

  ASSERTIFY(test_assert_mat2_eq_zero(m1))
  ASSERTIFY(test_assert_mat2_eq_zero(m2))
  ASSERTIFY(test_assert_mat2_eq_zero(m3))

  TEST_SUCCESS
}

TEST_IMPL(GLM_PREFIX, mat2_mul) {
  mat2 m1 = GLM_MAT2_IDENTITY_INIT;
  mat2 m2 = GLM_MAT2_IDENTITY_INIT;
  mat2 m3;
  mat2 m4 = GLM_MAT2_ZERO_INIT;
  int  i, j, k;

  /* test random matrices */
  /* random matrices */
  test_rand_mat2(m1);
  test_rand_mat2(m2);

  GLM(mat2_mul)(m1, m2, m3);
  for (i = 0; i < 2; i++) {
    for (j = 0; j < 2; j++) {
      for (k = 0; k < 2; k++)
        /* column-major */
        m4[i][j] += m1[k][j] * m2[i][k];
    }
  }

  ASSERTIFY(test_assert_mat2_eq(m3, m4))

  /* test pre compiled */
  GLM(mat2_mul)(m1, m2, m3);
  ASSERTIFY(test_assert_mat2_eq(m3, m4))

  TEST_SUCCESS
}

TEST_IMPL(GLM_PREFIX, mat2_transpose_to) {
  mat2 mat = A_MATRIX2x2;
  mat2 m1;

  GLM(mat2_transpose_to)(mat, m1);

  ASSERTIFY(test_assert_mat2_eqt(mat, m1))

  TEST_SUCCESS
}

TEST_IMPL(GLM_PREFIX, mat2_transpose) {
  mat2 mat = A_MATRIX2x2;
  mat2 m1;

  GLM(mat2_copy)(mat, m1);
  GLM(mat2_transpose)(m1);

  ASSERTIFY(test_assert_mat2_eqt(mat, m1))

  TEST_SUCCESS
}

TEST_IMPL(GLM_PREFIX, mat2_mulv) {
  vec2 res;
  mat2 mat = A_MATRIX2x2;
  vec2 v = {11.0f, 21.0f};
  int  i;

  GLM(mat2_mulv)(mat, v, res);

  for (i = 0; i < 2; i++) {
    ASSERT(test_eq(res[i], v[0] * mat[0][i] + v[1] * mat[1][i]))
  }

  TEST_SUCCESS
}

TEST_IMPL(GLM_PREFIX, mat2_trace) {
  mat2  mat = A_MATRIX2x2;
  float trace;

  trace = GLM(mat2_trace)(mat);

  ASSERT(test_eq(trace, mat[0][0] + mat[1][1]))

  TEST_SUCCESS
}

TEST_IMPL(GLM_PREFIX, mat2_scale) {
  mat2 m1 = A_MATRIX2x2;
  mat2 m2 = A_MATRIX2x2;
  int i, j;
  float scale;

  scale = rand() % 100;

  GLM(mat2_scale)(m1, scale);

  for (i = 0; i < 2; i++) {
    for (j = 0; j < 2; j++) {
      ASSERT(test_eq(m1[i][j], m2[i][j] * scale))
    }
  }

  TEST_SUCCESS
}

TEST_IMPL(GLM_PREFIX, mat2_det) {
  TEST_SUCCESS
}

TEST_IMPL(GLM_PREFIX, mat2_inv) {
  mat2 m1 = GLM_MAT2_IDENTITY_INIT;
  mat2 m2 = GLM_MAT2_IDENTITY_INIT;
  mat2 m3;
  int  i;

  m1[0][0] = 41.0f;
  m1[0][1] = 0.0f;
  m1[1][0] = 0.0f;
  m1[1][1] = 70.0f;

  for (i = 0; i < 10000; i++) {
    /* test inverse precise */
    GLM(mat2_inv)(m1, m2);
    GLM(mat2_inv)(m2, m3);
    
    ASSERTIFY(test_assert_mat2_eq(m1, m3))
  }

  TEST_SUCCESS
}

TEST_IMPL(GLM_PREFIX, mat2_swap_col) {
  mat2 m1 = A_MATRIX2x2;
  mat2 m2 = A_MATRIX2x2;

  GLM(mat2_swap_col)(m1, 0, 1);

  ASSERTIFY(test_assert_vec2_eq(m1[0], m2[1]))
  ASSERTIFY(test_assert_vec2_eq(m1[1], m2[0]))

  TEST_SUCCESS
}

TEST_IMPL(GLM_PREFIX, mat2_swap_row) {
  mat2 m1 = A_MATRIX2x2;
  mat2 m2 = A_MATRIX2x2;

  GLM(mat2_swap_row)(m1, 0, 1);

  ASSERT(test_eq(m1[0][0], m2[0][1]))
  ASSERT(test_eq(m1[0][1], m2[0][0]))

  ASSERT(test_eq(m1[1][0], m2[1][1]))
  ASSERT(test_eq(m1[1][1], m2[1][0]))

  TEST_SUCCESS
}

TEST_IMPL(GLM_PREFIX, mat2_rmc) {
  mat2  mat = A_MATRIX2x2;
  vec2  v   = {11.0f, 12.0f};
  vec2  v1;
  float r1, r2;
  int   i;

  r1 = GLM(mat2_rmc)(v, mat, v);

  for (i = 0; i < 2; i++) {
    v1[i] = v[0] * mat[i][0] + v[1] * mat[i][1];
  }

  r2 = v[0] * v1[0] + v[1] * v1[1];

  ASSERT(test_eq(r1, r2))

  TEST_SUCCESS
}

TEST_IMPL(GLM_PREFIX, mat2_make) {
  mat2 dest;
  unsigned int i, j;
  float src[4] = MAT2_ARRAY;

  GLM(mat2_make)(src, dest);

  for (i = 0, j = 0; i < sizeof(src) / sizeof(float); i+=2, j++) {
    ASSERT(test_eq(dest[j][0], src[i]))
    ASSERT(test_eq(dest[j][1], src[i+1]))
  }

  TEST_SUCCESS
}

#undef A_MATRIX2x2
