/*
 * Copyright (c), Recep Aslantas.
 *
 * MIT License (MIT), http://opensource.org/licenses/MIT
 * Full license can be found in the LICENSE file
 */

#include "test_common.h"

#define A_MATRIX  {{1,2,3,4},{5,6,7,8},{9,10,11,12},{13,14,15,16}}
#define A_MATRIX3 {{1,2,3},{5,6,7},{9,10,11}}
#define MAT4_ARRAY {1, 5, 2, 7, 12, 1, 4, 6, 0, 8, 1, 0, 6, 5, 0, 1}

TEST_IMPL(GLM_PREFIX, mat4_ucopy) {
  mat4 m1 = A_MATRIX;
  mat4 m2 = GLM_MAT4_IDENTITY_INIT;

  GLM(mat4_ucopy)(m1, m2);

  ASSERTIFY(test_assert_mat4_eq(m1, m2))

  TEST_SUCCESS
}

TEST_IMPL(GLM_PREFIX, mat4_copy) {
  mat4 m1 = A_MATRIX;
  mat4 m2 = GLM_MAT4_IDENTITY_INIT;

  GLM(mat4_copy)(m1, m2);

  test_assert_mat4_eq(m1, m2);

  TEST_SUCCESS
}

TEST_IMPL(GLM_PREFIX, mat4_identity) {
  mat4 m1 = GLM_MAT4_IDENTITY_INIT;
  mat4 m2 = GLM_MAT4_IDENTITY_INIT;
  mat4 m3;

  GLM(mat4_identity)(m3);

  ASSERTIFY(test_assert_mat4_eq_identity(m1))
  ASSERTIFY(test_assert_mat4_eq_identity(m2))
  ASSERTIFY(test_assert_mat4_eq_identity(m3))

  TEST_SUCCESS
}

TEST_IMPL(GLM_PREFIX, mat4_identity_array) {
  size_t i, count;
  mat4 matrices[4] = {
    A_MATRIX,
    A_MATRIX,
    A_MATRIX,
    A_MATRIX
  };

  count = 4;

  GLM(mat4_identity_array)(matrices, count);

  for (i = 0; i < count; i++) {
    ASSERTIFY(test_assert_mat4_eq_identity(matrices[i]))
  }

  TEST_SUCCESS
}

TEST_IMPL(GLM_PREFIX, mat4_zero) {
  mat4 m1 = GLM_MAT4_ZERO_INIT;
  mat4 m2 = GLM_MAT4_ZERO_INIT;
  mat4 m3;

  GLM(mat4_zero)(m3);

  ASSERTIFY(test_assert_mat4_eq_zero(m1))
  ASSERTIFY(test_assert_mat4_eq_zero(m2))
  ASSERTIFY(test_assert_mat4_eq_zero(m3))

  TEST_SUCCESS
}

TEST_IMPL(GLM_PREFIX, mat4_pick3) {
  mat4 m1 = A_MATRIX;
  mat3 m2 = GLM_MAT3_ZERO_INIT;
  mat3 m3 = A_MATRIX3;

  GLM(mat4_pick3)(m1, m2);

  ASSERTIFY(test_assert_mat3_eq(m2, m3))

  TEST_SUCCESS
}

TEST_IMPL(GLM_PREFIX, mat4_pick3t) {
  mat4 m1 = A_MATRIX;
  mat3 m2 = GLM_MAT3_ZERO_INIT;
  mat3 m3 = A_MATRIX3;

  GLM(mat4_pick3t)(m1, m2);

  ASSERTIFY(test_assert_mat3_eqt(m2, m3))

  TEST_SUCCESS
}

TEST_IMPL(GLM_PREFIX, mat4_ins3) {
  mat4 m1 = GLM_MAT4_IDENTITY_INIT;
  mat3 m2 = A_MATRIX3;
  int i, j;

  GLM(mat4_ins3)(m2, m1);

  for (i = 0; i < 3; i++) {
    for (j = 0; j < 3; j++) {
      ASSERT(m1[i][j] == m2[i][j])
    }
  }

  ASSERT(test_eq(m1[3][0], 0.0f))
  ASSERT(test_eq(m1[3][1], 0.0f))
  ASSERT(test_eq(m1[3][2], 0.0f))
  ASSERT(test_eq(m1[3][3], 1.0f))

  TEST_SUCCESS
}

TEST_IMPL(GLM_PREFIX, mat4_mul) {
  mat4 m1 = GLM_MAT4_IDENTITY_INIT;
  mat4 m2 = GLM_MAT4_IDENTITY_INIT;
  mat4 m3;
  mat4 m4 = GLM_MAT4_ZERO_INIT;
  int  i, j, k;

  /* test random matrices */
  /* random matrices */
  test_rand_mat4(m1);
  test_rand_mat4(m2);

  GLM(mat4_mul)(m1, m2, m3);
  for (i = 0; i < 4; i++) {
    for (j = 0; j < 4; j++) {
      for (k = 0; k < 4; k++)
        /* column-major */
        m4[i][j] += m1[k][j] * m2[i][k];
    }
  }

  ASSERTIFY(test_assert_mat4_eq(m3, m4))

  /* test pre compiled */
  GLM(mat4_mul)(m1, m2, m3);
  ASSERTIFY(test_assert_mat4_eq(m3, m4))

  TEST_SUCCESS
}

TEST_IMPL(GLM_PREFIX, mat4_mulN) {
  mat4 res1, res2;
  mat4 m1 = A_MATRIX;
  mat4 m2 = A_MATRIX;
  mat4 m3 = A_MATRIX;

  mat4 *matrices[] = {
    &m1, &m2, &m3
  };

  GLM(mat4_mulN)(matrices, sizeof(matrices) / sizeof(matrices[0]), res1);

  GLM(mat4_mul)(*matrices[0], *matrices[1], res2);
  GLM(mat4_mul)(res2, *matrices[2], res2);

  ASSERTIFY(test_assert_mat4_eq(res1, res1))

  TEST_SUCCESS
}

TEST_IMPL(GLM_PREFIX, mat4_mulv) {
  vec4 res;
  mat4 mat = A_MATRIX;
  vec4 v = {1.0f, 2.0f, 3.0f, 4.0f};
  int  i;

  GLM(mat4_mulv)(mat, v, res);

  for (i = 0; i < 4; i++) {
    ASSERT(test_eq(res[i],
                  v[0] * mat[0][i]
                + v[1] * mat[1][i]
                + v[2] * mat[2][i]
                + v[3] * mat[3][i]))
  }

  TEST_SUCCESS
}

TEST_IMPL(GLM_PREFIX, mat4_mulv3) {
  vec4  res;
  mat4  mat = A_MATRIX;
  vec3  v = {1.0f, 2.0f, 3.0f};
  float last;
  int   i;

  last = 1.0f;

  GLM(mat4_mulv3)(mat, v, last, res);

  for (i = 0; i < 3; i++) {
    ASSERT(test_eq(res[i],
                  v[0] * mat[0][i]
                  + v[1] * mat[1][i]
                  + v[2] * mat[2][i]
                  + last * mat[3][i]))
  }

  TEST_SUCCESS
}

TEST_IMPL(GLM_PREFIX, mat4_trace) {
  mat4  mat = A_MATRIX;
  float trace;

  trace = GLM(mat4_trace)(mat);

  ASSERT(test_eq(trace, mat[0][0] + mat[1][1] + mat[2][2] + mat[3][3]))

  TEST_SUCCESS
}

TEST_IMPL(GLM_PREFIX, mat4_trace3) {
  mat4  mat = A_MATRIX;
  float trace;

  trace = GLM(mat4_trace3)(mat);

  ASSERT(test_eq(trace, mat[0][0] + mat[1][1] + mat[2][2]))

  TEST_SUCCESS
}

TEST_IMPL(GLM_PREFIX, mat4_quat) {
  mat4   m1, m2;
  versor q1, q2, q3;
  vec3   axis1;
  vec3   axis2 = {1.9f, 2.3f, 4.5f};
  
  GLM(quat)(q1, GLM_PI_4f, 1.9f, 2.3f, 4.5f);
  GLM(quat_mat4)(q1, m1);
  GLM(mat4_quat)(m1, q2);
  
  GLM(rotate_make)(m2, GLM_PI_4f, axis2);
  GLM(mat4_quat)(m1, q3);
  
  GLM(quat_axis)(q3, axis1);
  
  GLM(vec3_normalize)(axis1);
  GLM(vec3_normalize)(axis2);
  
  ASSERT(test_eq(glm_quat_angle(q3), GLM_PI_4f))
  ASSERTIFY(test_assert_vec3_eq(axis1, axis2))
  ASSERTIFY(test_assert_vec4_eq(q1, q2))
  ASSERTIFY(test_assert_mat4_eq(m1, m2))
  ASSERTIFY(test_assert_vec4_eq(q1, q3))

  TEST_SUCCESS
}

TEST_IMPL(GLM_PREFIX, mat4_transpose_to) {
  mat4  mat = A_MATRIX;
  mat4  m1;

  GLM(mat4_transpose_to)(mat, m1);
  
  ASSERTIFY(test_assert_mat4_eqt(mat, m1))

  TEST_SUCCESS
}

TEST_IMPL(GLM_PREFIX, mat4_transpose) {
  mat4 mat = A_MATRIX;
  mat4 m1;

  GLM(mat4_copy)(mat, m1);
  GLM(mat4_transpose)(m1);
  
  ASSERTIFY(test_assert_mat4_eqt(mat, m1))

  TEST_SUCCESS
}

TEST_IMPL(GLM_PREFIX, mat4_scale_p) {
  mat4 m1 = A_MATRIX;
  mat4 m2 = A_MATRIX;
  int i, j, k;
  float scale;

  scale = rand() % 100;
  
  GLM(mat4_scale_p)(m1, scale);

  for (i = 0; i < 4; i++) {
    for (j = 0; j < 4; j++) {
      for (k = 0; k < 4; k++)
        ASSERT(test_eq(m1[i][j], m2[i][j] * scale))
    }
  }

  TEST_SUCCESS
}

TEST_IMPL(GLM_PREFIX, mat4_scale) {
  mat4 m1 = A_MATRIX;
  mat4 m2 = A_MATRIX;
  int i, j, k;
  float scale;

  scale = rand() % 100;
  
  GLM(mat4_scale)(m1, scale);

  for (i = 0; i < 4; i++) {
    for (j = 0; j < 4; j++) {
      for (k = 0; k < 4; k++)
        ASSERT(test_eq(m1[i][j], m2[i][j] * scale))
    }
  }

  TEST_SUCCESS
}

TEST_IMPL(GLM_PREFIX, mat4_det) {
  mat4 mat = GLM_MAT4_IDENTITY_INIT;
  float t[6];
  float a, b, c, d,
        e, f, g, h,
        i, j, k, l,
        m, n, o, p;
  float det1, det2;

  test_rand_mat4(mat);

  a = mat[0][0]; b = mat[0][1]; c = mat[0][2]; d = mat[0][3];
  e = mat[1][0]; f = mat[1][1]; g = mat[1][2]; h = mat[1][3];
  i = mat[2][0]; j = mat[2][1]; k = mat[2][2]; l = mat[2][3];
  m = mat[3][0]; n = mat[3][1]; o = mat[3][2]; p = mat[3][3];

  t[0] = k * p - o * l;
  t[1] = j * p - n * l;
  t[2] = j * o - n * k;
  t[3] = i * p - m * l;
  t[4] = i * o - m * k;
  t[5] = i * n - m * j;

  det1 = a * (f * t[0] - g * t[1] + h * t[2])
       - b * (e * t[0] - g * t[3] + h * t[4])
       + c * (e * t[1] - f * t[3] + h * t[5])
       - d * (e * t[2] - f * t[4] + g * t[5]);

  det2 = GLM(mat4_det(mat));

  ASSERT(test_eq(det1, det2))

  TEST_SUCCESS
}

TEST_IMPL(GLM_PREFIX, mat4_inv) {
  mat4 m1, m2, m3;
  int  i;

  for (i = 0; i < 100000; i++) {
    test_rand_mat4(m1);
    test_rand_mat4(m2);

    /* test inverse precise */
    GLM(mat4_inv)(m1, m2);
    GLM(mat4_inv)(m2, m3);
    ASSERTIFY(test_assert_mat4_eq(m1, m3))
  }

  TEST_SUCCESS
}

TEST_IMPL(GLM_PREFIX, mat4_inv_precise) {
  mat4 m1, m2, m3;
  mat4 m4, m5, m6;
  int  i;

  for (i = 0; i < 100000; i++) {
    test_rand_mat4(m1);
    test_rand_mat4(m2);
    
    glm_mat4_inv_precise(m1, m2);
    glm_mat4_inv_precise(m2, m3);
    ASSERTIFY(test_assert_mat4_eq(m1, m3))
    
    test_rand_mat4(m4);
    test_rand_mat4(m5);
    
    glmc_mat4_inv_precise(m4, m5);
    glmc_mat4_inv_precise(m5, m6);
    ASSERTIFY(test_assert_mat4_eq(m4, m6))
  }

  TEST_SUCCESS
}

TEST_IMPL(GLM_PREFIX, mat4_inv_fast) {
  mat4 m1, m2, m3;
  int  i;
  
  for (i = 0; i < 100000; i++) {
    test_rand_mat4(m1);
    test_rand_mat4(m2);
    
    /* test inverse precise */
    GLM(mat4_inv_fast)(m1, m2);
    GLM(mat4_inv_fast)(m2, m3);
    ASSERTIFY(test_assert_mat4_eq2(m1, m3, 0.0009f))
  }
  
  TEST_SUCCESS
}

TEST_IMPL(GLM_PREFIX, mat4_swap_col) {
  mat4 m1 = A_MATRIX;
  mat4 m2 = A_MATRIX;
  
  GLM(mat4_swap_col)(m1, 0, 1);
  GLM(mat4_swap_col)(m1, 2, 3);

  ASSERTIFY(test_assert_vec4_eq(m1[0], m2[1]))
  ASSERTIFY(test_assert_vec4_eq(m1[1], m2[0]))
  ASSERTIFY(test_assert_vec4_eq(m1[2], m2[3]))
  ASSERTIFY(test_assert_vec4_eq(m1[3], m2[2]))
  
  TEST_SUCCESS
}

TEST_IMPL(GLM_PREFIX, mat4_swap_row) {
  mat4 m1 = A_MATRIX;
  mat4 m2 = A_MATRIX;
  
  GLM(mat4_swap_row)(m1, 0, 1);
  GLM(mat4_swap_row)(m1, 2, 3);
  
  ASSERT(test_eq(m1[0][0], m2[0][1]))
  ASSERT(test_eq(m1[0][1], m2[0][0]))
  ASSERT(test_eq(m1[0][2], m2[0][3]))
  ASSERT(test_eq(m1[0][3], m2[0][2]))
  ASSERT(test_eq(m1[1][0], m2[1][1]))
  ASSERT(test_eq(m1[1][1], m2[1][0]))
  ASSERT(test_eq(m1[1][2], m2[1][3]))
  ASSERT(test_eq(m1[1][3], m2[1][2]))
  ASSERT(test_eq(m1[2][0], m2[2][1]))
  ASSERT(test_eq(m1[2][1], m2[2][0]))
  ASSERT(test_eq(m1[2][2], m2[2][3]))
  ASSERT(test_eq(m1[2][3], m2[2][2]))
  ASSERT(test_eq(m1[3][0], m2[3][1]))
  ASSERT(test_eq(m1[3][1], m2[3][0]))
  ASSERT(test_eq(m1[3][2], m2[3][3]))
  ASSERT(test_eq(m1[3][3], m2[3][2]))

  TEST_SUCCESS
}

TEST_IMPL(GLM_PREFIX, mat4_rmc) {
  mat4  mat = A_MATRIX;
  vec4  v = {1.0f, 2.0f, 3.0f, 4.0f};
  vec4  v1;
  float r1, r2;
  int   i;

  r1 = GLM(mat4_rmc)(v, mat, v);

  for (i = 0; i < 4; i++) {
    v1[i] = v[0] * mat[i][0]
          + v[1] * mat[i][1]
          + v[2] * mat[i][2]
          + v[3] * mat[i][3];
  }
  
  r2 = v[0] * v1[0] + v[1] * v1[1] + v[2] * v1[2] + v[3] * v1[3];

  ASSERT(test_eq(r1, r2))

  TEST_SUCCESS
}

TEST_IMPL(GLM_PREFIX, mat4_make) {
  mat4 dest;
  unsigned int i, j;
  float src[16] = MAT4_ARRAY;

  GLM(mat4_make)(src, dest);

  for (i = 0, j = 0; i < sizeof(src) / sizeof(float); i+=4, j++) {
    ASSERT(test_eq(dest[j][0], src[i]))
    ASSERT(test_eq(dest[j][1], src[i+1]))
    ASSERT(test_eq(dest[j][2], src[i+2]))
    ASSERT(test_eq(dest[j][3], src[i+3]))
  }

  TEST_SUCCESS
}

TEST_IMPL(GLM_PREFIX, mat4_textrans) {
  mat4  m, expected;
  float sx = 2.0f, sy = 3.0f, rot = GLM_PI_4f;
  float tx = 10.0f, ty = 20.0f;

  GLM(mat4_textrans)(sx, sy, rot, tx, ty, m);

  ASSERT(test_eq(m[0][0], cosf(rot) * sx))
  ASSERT(test_eq(m[0][1],-sinf(rot) * sy))
  ASSERT(test_eq(m[1][0], sinf(rot) * sx))
  ASSERT(test_eq(m[1][1], cosf(rot) * sy))
  ASSERT(test_eq(m[3][0], tx))
  ASSERT(test_eq(m[3][1], ty))

  GLM(mat4_textrans)(1.0f, 1.0f, 0.0f, 0.0f, 0.0f, m);
  GLM(mat4_identity)(expected);

  ASSERTIFY(test_assert_mat4_eq(m, expected))

  TEST_SUCCESS
}

#undef A_MATRIX
#undef A_MATRIX3
