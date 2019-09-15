/*
 * Copyright (c), Recep Aslantas.
 *
 * MIT License (MIT), http://opensource.org/licenses/MIT
 * Full license can be found in the LICENSE file
 */

#include "test_common.h"

#define A_MATRIX  {{1,2,3,4},{5,6,7,8},{9,10,11,12},{13,14,15,16}}
#define A_MATRIX3 {{1,2,3},{5,6,7},{9,10,11}}

TEST_IMPL(glm_mat4_ucopy) {
  mat4 m1 = A_MATRIX;
  mat4 m2 = GLM_MAT4_IDENTITY_INIT;

  glm_mat4_ucopy(m1, m2);

  ASSERTIFY(test_assert_mat4_eq(m1, m2))

  TEST_SUCCESS
}

TEST_IMPL(glm_mat4_copy) {
  mat4 m1 = A_MATRIX;
  mat4 m2 = GLM_MAT4_IDENTITY_INIT;

  glm_mat4_copy(m1, m2);

  test_assert_mat4_eq(m1, m2);

  TEST_SUCCESS
}

TEST_IMPL(glm_mat4_identity) {
  mat4 m1 = GLM_MAT4_IDENTITY_INIT;
  mat4 m2 = GLM_MAT4_IDENTITY_INIT;
  mat4 m3;

  glm_mat4_identity(m3);

  ASSERTIFY(test_assert_mat4_eq_identity(m1))
  ASSERTIFY(test_assert_mat4_eq_identity(m2))
  ASSERTIFY(test_assert_mat4_eq_identity(m3))

  TEST_SUCCESS
}

TEST_IMPL(glm_mat4_identity_array) {
  int i, count;
  mat4 matrices[4] = {
    A_MATRIX,
    A_MATRIX,
    A_MATRIX,
    A_MATRIX
  };

  count = 4;

  glm_mat4_identity_array(matrices, count);

  for (i = 0; i < count; i++) {
    ASSERTIFY(test_assert_mat4_eq_identity(matrices[i]))
  }

  TEST_SUCCESS
}

TEST_IMPL(glm_mat4_zero) {
  mat4 m1 = GLM_MAT4_ZERO_INIT;
  mat4 m2 = GLM_MAT4_ZERO_INIT;
  mat4 m3;

  glm_mat4_zero(m3);

  ASSERTIFY(test_assert_mat4_eq_zero(m1))
  ASSERTIFY(test_assert_mat4_eq_zero(m2))
  ASSERTIFY(test_assert_mat4_eq_zero(m3))

  TEST_SUCCESS
}

TEST_IMPL(glm_mat4_pick3) {
  mat4 m1 = A_MATRIX;
  mat3 m2 = GLM_MAT3_ZERO_INIT;
  mat3 m3 = A_MATRIX3;

  glm_mat4_pick3(m1, m2);

  ASSERTIFY(test_assert_mat3_eq(m2, m3))

  TEST_SUCCESS
}

TEST_IMPL(glm_mat4_pick3t) {
  mat4 m1 = A_MATRIX;
  mat3 m2 = GLM_MAT3_ZERO_INIT;
  mat3 m3 = A_MATRIX3;

  glm_mat4_pick3t(m1, m2);

  ASSERTIFY(test_assert_mat3_eqt(m2, m3))

  TEST_SUCCESS
}

TEST_IMPL(glm_mat4_ins3) {
  mat4 m1 = GLM_MAT4_IDENTITY_INIT;
  mat3 m2 = A_MATRIX3;
  int i, j;

  glm_mat4_ins3(m2, m1);

  for (i = 0; i < 3; i++) {
    for (j = 0; j < 3; j++) {
      ASSERT(m1[i][j] == m2[i][j])
    }
  }

  ASSERT(glm_eq(m1[3][0], 0.0f))
  ASSERT(glm_eq(m1[3][1], 0.0f))
  ASSERT(glm_eq(m1[3][2], 0.0f))
  ASSERT(glm_eq(m1[3][3], 1.0f))

  TEST_SUCCESS
}

TEST_IMPL(glm_mat4_mul) {
  mat4 m1 = GLM_MAT4_IDENTITY_INIT;
  mat4 m2 = GLM_MAT4_IDENTITY_INIT;
  mat4 m3;
  mat4 m4 = GLM_MAT4_ZERO_INIT;
  int  i, j, k;

  /* test random matrices */
  /* random matrices */
  test_rand_mat4(m1);
  test_rand_mat4(m2);

  glm_mat4_mul(m1, m2, m3);
  for (i = 0; i < 4; i++) {
    for (j = 0; j < 4; j++) {
      for (k = 0; k < 4; k++)
        /* column-major */
        m4[i][j] += m1[k][j] * m2[i][k];
    }
  }

  ASSERTIFY(test_assert_mat4_eq(m3, m4))

  /* test pre compiled */
  glmc_mat4_mul(m1, m2, m3);
  ASSERTIFY(test_assert_mat4_eq(m3, m4))

  TEST_SUCCESS
}

TEST_IMPL(glm_mat4_mulN) {
  mat4 res1, res2;
  mat4 m1 = A_MATRIX;
  mat4 m2 = A_MATRIX;
  mat4 m3 = A_MATRIX;

  mat4 *matrices[] = {
    &m1, &m2, &m3
  };

  glm_mat4_mulN(matrices, sizeof(matrices) / sizeof(matrices[0]), res1);

  glm_mat4_mul(*matrices[0], *matrices[1], res2);
  glm_mat4_mul(res2, *matrices[2], res2);

  ASSERTIFY(test_assert_mat4_eq(res1, res1))

  TEST_SUCCESS
}

TEST_IMPL(glm_mat4_mulv) {
  vec4 res;
  mat4 mat = A_MATRIX;
  vec4 v = {1.0f, 2.0f, 3.0f, 4.0f};
  int  i;

  glm_mat4_mulv(mat, v, res);

  for (i = 0; i < 4; i++) {
    ASSERT(glm_eq(res[i],
                  v[0] * mat[0][i]
                + v[1] * mat[1][i]
                + v[2] * mat[2][i]
                + v[3] * mat[3][i]))
  }

  TEST_SUCCESS
}

TEST_IMPL(glm_mat4_mulv3) {
  vec4  res;
  mat4  mat = A_MATRIX;
  vec3  v = {1.0f, 2.0f, 3.0f};
  float last;
  int   i;

  last = 1.0f;

  glm_mat4_mulv3(mat, v, last, res);

  for (i = 0; i < 3; i++) {
    ASSERT(glm_eq(res[i],
                  v[0] * mat[0][i]
                  + v[1] * mat[1][i]
                  + v[2] * mat[2][i]
                  + last * mat[3][i]))
  }

  TEST_SUCCESS
}

TEST_IMPL(glm_mat4_trace) {
  mat4  mat = A_MATRIX;
  float trace;

  trace = glm_mat4_trace(mat);

  ASSERT(glm_eq(trace, mat[0][0] + mat[1][1] + mat[2][2] + mat[3][3]))

  TEST_SUCCESS
}

TEST_IMPL(glm_mat4_trace3) {
  mat4  mat = A_MATRIX;
  float trace;

  trace = glm_mat4_trace3(mat);

  ASSERT(glm_eq(trace, mat[0][0] + mat[1][1] + mat[2][2]))

  TEST_SUCCESS
}

TEST_IMPL(glm_mat4_quat) {
  TEST_SUCCESS
}

TEST_IMPL(glm_mat4_transpose_to) {
  TEST_SUCCESS
}

TEST_IMPL(glm_mat4_transpose) {
  TEST_SUCCESS
}

TEST_IMPL(glm_mat4_scale_p) {
  TEST_SUCCESS
}

TEST_IMPL(glm_mat4_scale) {
  TEST_SUCCESS
}

TEST_IMPL(glm_mat4_det) {
  mat4 m1 = GLM_MAT4_IDENTITY_INIT;

  test_rand_mat4(m1);

  /* test determinant */
  ASSERT(glm_mat4_det(m1) == glmc_mat4_det(m1))
#if defined( __SSE2__ )
  ASSERT(glmc_mat4_det(m1) == glm_mat4_det_sse2(m1))
#endif

  TEST_SUCCESS
}

TEST_IMPL(glm_mat4_inv) {
  mat4 m1 = GLM_MAT4_IDENTITY_INIT;
  mat4 m3;
  mat4 m4 = GLM_MAT4_ZERO_INIT;
  mat4 m5;
  int  i;

  for (i = 0; i < 100000; i++) {
    test_rand_mat4(m3);
    test_rand_mat4(m4);

    /* test inverse precise */
    glm_mat4_inv(m3, m4);
    glm_mat4_inv(m4, m5);
    ASSERTIFY(test_assert_mat4_eq(m3, m5))

    test_rand_mat4(m3);
    test_rand_mat4(m4);

    glmc_mat4_inv_precise(m3, m4);
    glmc_mat4_inv_precise(m4, m5);
    ASSERTIFY(test_assert_mat4_eq(m3, m5))

    /* test inverse rcp */
    test_rand_mat4(m3);
    test_rand_mat4(m4);

    glm_mat4_inv_fast(m3, m4);
    glm_mat4_inv_fast(m4, m5);
    ASSERTIFY(test_assert_mat4_eq2(m3, m5, 0.0009f))

    test_rand_mat4(m3);
    test_rand_mat4(m4);

    glmc_mat4_inv(m3, m4);
    glmc_mat4_inv(m4, m5);
    ASSERTIFY(test_assert_mat4_eq2(m3, m5, 0.0009f))
  }

  /* test determinant */
  ASSERT(glm_mat4_det(m1) == glmc_mat4_det(m1))
#if defined( __SSE2__ )
  ASSERT(glmc_mat4_det(m1) == glm_mat4_det_sse2(m1))
#endif

  TEST_SUCCESS
}

TEST_IMPL(glm_mat4_inv_fast) {
  TEST_SUCCESS
}

TEST_IMPL(glm_mat4_swap_col) {
  TEST_SUCCESS
}

TEST_IMPL(glm_mat4_swap_row) {
  TEST_SUCCESS
}

TEST_IMPL(glm_mat4_rmc) {
  TEST_SUCCESS
}
