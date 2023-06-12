/*
 * Copyright (c), Recep Aslantas.
 *
 * MIT License (MIT), http://opensource.org/licenses/MIT
 * Full license can be found in the LICENSE file
 */

#include "test_common.h"

#define A_MATRIX {{1,2,3},{5,6,7},{9,10,11}}
#define MAT3_ARRAY {1, 5, 2, 7, 12, 1, 4, 6, 0}

TEST_IMPL(GLM_PREFIX, mat3_copy) {
  mat3 m1 = A_MATRIX;
  mat3 m2 = GLM_MAT3_IDENTITY_INIT;

  GLM(mat3_copy)(m1, m2);

  test_assert_mat3_eq(m1, m2);

  TEST_SUCCESS
}

TEST_IMPL(GLM_PREFIX, mat3_identity) {
  mat3 m1 = GLM_MAT3_IDENTITY_INIT;
  mat3 m2 = GLM_MAT3_IDENTITY_INIT;
  mat3 m3;

  GLM(mat3_identity)(m3);

  ASSERTIFY(test_assert_mat3_eq_identity(m1))
  ASSERTIFY(test_assert_mat3_eq_identity(m2))
  ASSERTIFY(test_assert_mat3_eq_identity(m3))

  TEST_SUCCESS
}

TEST_IMPL(GLM_PREFIX, mat3_identity_array) {
  size_t i, count;
  mat3 matrices[4] = {
    A_MATRIX,
    A_MATRIX,
    A_MATRIX,
    A_MATRIX
  };

  count = 4;

  GLM(mat3_identity_array)(matrices, count);

  for (i = 0; i < count; i++) {
    ASSERTIFY(test_assert_mat3_eq_identity(matrices[i]))
  }

  TEST_SUCCESS
}

TEST_IMPL(GLM_PREFIX, mat3_zero) {
  mat3 m1 = GLM_MAT3_ZERO_INIT;
  mat3 m2 = GLM_MAT3_ZERO_INIT;
  mat3 m3;

  GLM(mat3_zero)(m3);

  ASSERTIFY(test_assert_mat3_eq_zero(m1))
  ASSERTIFY(test_assert_mat3_eq_zero(m2))
  ASSERTIFY(test_assert_mat3_eq_zero(m3))

  TEST_SUCCESS
}

TEST_IMPL(GLM_PREFIX, mat3_mul) {
  mat3 m1 = GLM_MAT3_IDENTITY_INIT;
  mat3 m2 = GLM_MAT3_IDENTITY_INIT;
  mat3 m3;
  mat3 m4 = GLM_MAT3_ZERO_INIT;
  int  i, j, k;

  /* test random matrices */
  /* random matrices */
  test_rand_mat3(m1);
  test_rand_mat3(m2);

  GLM(mat3_mul)(m1, m2, m3);
  for (i = 0; i < 3; i++) {
    for (j = 0; j < 3; j++) {
      for (k = 0; k < 3; k++)
        /* column-major */
        m4[i][j] += m1[k][j] * m2[i][k];
    }
  }

  ASSERTIFY(test_assert_mat3_eq(m3, m4))

  /* test pre compiled */
  GLM(mat3_mul)(m1, m2, m3);
  ASSERTIFY(test_assert_mat3_eq(m3, m4))

  TEST_SUCCESS
}

TEST_IMPL(GLM_PREFIX, mat3_mulv) {
  vec4 res;
  mat3 mat = A_MATRIX;
  vec4 v = {1.0f, 2.0f, 3.0f, 4.0f};
  int  i;

  GLM(mat3_mulv)(mat, v, res);

  for (i = 0; i < 3; i++) {
    ASSERT(test_eq(res[i],
                  v[0] * mat[0][i]
                  + v[1] * mat[1][i]
                  + v[2] * mat[2][i]))
  }

  TEST_SUCCESS
}

TEST_IMPL(GLM_PREFIX, mat3_trace) {
  mat3  mat = A_MATRIX;
  float trace;

  trace = GLM(mat3_trace)(mat);

  ASSERT(test_eq(trace, mat[0][0] + mat[1][1] + mat[2][2]))

  TEST_SUCCESS
}

TEST_IMPL(GLM_PREFIX, mat3_quat) {
  mat3   m1, m3;
  mat4   m2;
  versor q1, q2, q3;
  vec3   axis1;
  vec3   axis2 = {1.9f, 2.3f, 4.5f};

  GLM(quat)(q1, GLM_PI_4f, 1.9f, 2.3f, 4.5f);
  GLM(quat_mat3)(q1, m1);
  GLM(mat3_quat)(m1, q2);

  GLM(rotate_make)(m2, GLM_PI_4f, axis2);
  GLM(mat3_quat)(m1, q3);

  GLM(quat_axis)(q3, axis1);

  GLM(vec3_normalize)(axis1);
  GLM(vec3_normalize)(axis2);

  GLM(mat4_pick3)(m2, m3);

  ASSERT(test_eq(glm_quat_angle(q3), GLM_PI_4f))
  ASSERTIFY(test_assert_vec3_eq(axis1, axis2))
  ASSERTIFY(test_assert_vec4_eq(q1, q2))
  ASSERTIFY(test_assert_mat3_eq(m1, m3))
  ASSERTIFY(test_assert_vec4_eq(q1, q3))

  TEST_SUCCESS
}

TEST_IMPL(GLM_PREFIX, mat3_transpose_to) {
  mat3 mat = A_MATRIX;
  mat3 m1;

  GLM(mat3_transpose_to)(mat, m1);

  ASSERTIFY(test_assert_mat3_eqt(mat, m1))

  TEST_SUCCESS
}

TEST_IMPL(GLM_PREFIX, mat3_transpose) {
  mat3 mat = A_MATRIX;
  mat3 m1;

  GLM(mat3_copy)(mat, m1);
  GLM(mat3_transpose)(m1);

  ASSERTIFY(test_assert_mat3_eqt(mat, m1))

  TEST_SUCCESS
}

TEST_IMPL(GLM_PREFIX, mat3_scale) {
  mat3 m1 = A_MATRIX;
  mat3 m2 = A_MATRIX;
  int i, j, k, scale;

  scale = rand() % 100;

  GLM(mat3_scale)(m1, (float)scale);

  for (i = 0; i < 3; i++) {
    for (j = 0; j < 3; j++) {
      for (k = 0; k < 3; k++)
        ASSERT(test_eq(m1[i][j], m2[i][j] * scale))
    }
  }

  TEST_SUCCESS
}

TEST_IMPL(GLM_PREFIX, mat3_det) {
  mat3 mat;
  float a, b, c,
        d, e, f,
        g, h, i;
  float det1, det2;

  test_rand_mat3(mat);

  a = mat[0][0]; b = mat[0][1]; c = mat[0][2];
  d = mat[1][0]; e = mat[1][1]; f = mat[1][2];
  g = mat[2][0]; h = mat[2][1]; i = mat[2][2];

  det1 = a * (e * i - h * f) - d * (b * i - c * h) + g * (b * f - c * e);
  det2 = GLM(mat3_det)(mat);

  ASSERT(test_eq(det1, det2))

  TEST_SUCCESS
}

TEST_IMPL(GLM_PREFIX, mat3_inv) {
  mat3 m1 = GLM_MAT3_IDENTITY_INIT;
  mat3 m2 = GLM_MAT3_IDENTITY_INIT;
  mat3 m3;
  int  i;

  for (i = 0; i < 100000; i++) {
    test_rand_mat3(m1);
    test_rand_mat3(m2);

    /* test inverse precise */
    GLM(mat3_inv)(m1, m2);
    GLM(mat3_inv)(m2, m3);
    ASSERTIFY(test_assert_mat3_eq(m1, m3))
  }

  TEST_SUCCESS
}

TEST_IMPL(GLM_PREFIX, mat3_swap_col) {
  mat3 m1 = A_MATRIX;
  mat3 m2 = A_MATRIX;

  GLM(mat3_swap_col)(m1, 0, 1);

  ASSERTIFY(test_assert_vec3_eq(m1[0], m2[1]))
  ASSERTIFY(test_assert_vec3_eq(m1[1], m2[0]))

  TEST_SUCCESS
}

TEST_IMPL(GLM_PREFIX, mat3_swap_row) {
  mat3 m1 = A_MATRIX;
  mat3 m2 = A_MATRIX;

  GLM(mat3_swap_row)(m1, 0, 1);

  ASSERT(test_eq(m1[0][0], m2[0][1]))
  ASSERT(test_eq(m1[0][1], m2[0][0]))
  ASSERT(test_eq(m1[0][2], m2[0][2]))

  ASSERT(test_eq(m1[1][0], m2[1][1]))
  ASSERT(test_eq(m1[1][1], m2[1][0]))
  ASSERT(test_eq(m1[1][2], m2[1][2]))

  ASSERT(test_eq(m1[2][0], m2[2][1]))
  ASSERT(test_eq(m1[2][1], m2[2][0]))
  ASSERT(test_eq(m1[2][2], m2[2][2]))

  GLM(mat3_swap_row)(m1, 1, 2);

  ASSERT(test_eq(m1[0][0], m2[0][1]))
  ASSERT(test_eq(m1[0][1], m2[0][2]))
  ASSERT(test_eq(m1[0][2], m2[0][0]))

  ASSERT(test_eq(m1[1][0], m2[1][1]))
  ASSERT(test_eq(m1[1][1], m2[1][2]))
  ASSERT(test_eq(m1[1][2], m2[1][0]))

  ASSERT(test_eq(m1[2][0], m2[2][1]))
  ASSERT(test_eq(m1[2][1], m2[2][2]))
  ASSERT(test_eq(m1[2][2], m2[2][0]))

  TEST_SUCCESS
}

TEST_IMPL(GLM_PREFIX, mat3_rmc) {
  mat3  mat = A_MATRIX;
  vec3  v   = {11.0f, 12.0f, 13.0f};
  vec3  v1;
  float r1, r2;
  int   i;

  r1 = GLM(mat3_rmc)(v, mat, v);

  for (i = 0; i < 3; i++) {
    v1[i] = v[0] * mat[i][0]
          + v[1] * mat[i][1]
          + v[2] * mat[i][2];
  }

  r2 = v[0] * v1[0] + v[1] * v1[1] + v[2] * v1[2];

  ASSERT(test_eq(r1, r2))

  TEST_SUCCESS
}


TEST_IMPL(GLM_PREFIX, mat3_make) {
  mat3 dest;
  unsigned int i, j;
  float src[9] = MAT3_ARRAY;

  GLM(mat3_make)(src, dest);

  for (i = 0, j = 0; i < sizeof(src) / sizeof(float); i+=3, j++) {
    ASSERT(test_eq(dest[j][0], src[i]))
    ASSERT(test_eq(dest[j][1], src[i+1]))
    ASSERT(test_eq(dest[j][2], src[i+2]))
  }

  TEST_SUCCESS
}

#undef A_MATRIX
