/*
 * Copyright (c), Recep Aslantas.
 *
 * MIT License (MIT), http://opensource.org/licenses/MIT
 * Full license can be found in the LICENSE file
 */

#include "test_common.h"

#ifndef CGLM_TEST_QUAT_ONCE
#define CGLM_TEST_QUAT_ONCE

/* Macros */

TEST_IMPL(MACRO_GLM_QUAT_IDENTITY_INIT) {
  versor v = GLM_QUAT_IDENTITY_INIT;

  ASSERT(test_eq(v[0], 0.0f))
  ASSERT(test_eq(v[1], 0.0f))
  ASSERT(test_eq(v[2], 0.0f))
  ASSERT(test_eq(v[3], 1.0f))

  TEST_SUCCESS
}

TEST_IMPL(MACRO_GLM_QUAT_IDENTITY) {
  ASSERT(test_eq(GLM_QUAT_IDENTITY[0], 0.0f))
  ASSERT(test_eq(GLM_QUAT_IDENTITY[1], 0.0f))
  ASSERT(test_eq(GLM_QUAT_IDENTITY[2], 0.0f))
  ASSERT(test_eq(GLM_QUAT_IDENTITY[3], 1.0f))

  TEST_SUCCESS
}

#endif /* CGLM_TEST_QUAT_ONCE */

TEST_IMPL(GLM_PREFIX, quat_identity) {
  versor a = GLM_QUAT_IDENTITY_INIT;
  versor b = GLM_QUAT_IDENTITY_INIT;
  versor c;
  mat4   r;

  GLM(quat_identity)(c);

  ASSERTIFY(test_assert_quat_eq_identity(a))
  ASSERTIFY(test_assert_quat_eq_identity(b))
  ASSERTIFY(test_assert_quat_eq_identity(c))

  glm_quat_identity(c);
  ASSERT(test_eq(glm_quat_real(c), cosf(glm_rad(0.0f) * 0.5f)))

  glm_quat_mat4(c, r);
  ASSERTIFY(test_assert_mat4_eq2(r, GLM_MAT4_IDENTITY, 0.000009f))

  TEST_SUCCESS
}

TEST_IMPL(GLM_PREFIX, quat_identity_array) {
  int i, count;
  versor quats[4] = {
    {1.0f, 2.0f, 3.0f, 4.0f},
    {1.0f, 2.0f, 3.0f, 4.0f},
    {1.0f, 2.0f, 3.0f, 4.0f},
    {1.0f, 2.0f, 3.0f, 4.0f},
  };

  count = 4;

  GLM(quat_identity_array)(quats, count);

  for (i = 0; i < count; i++) {
    ASSERTIFY(test_assert_quat_eq_identity(quats[i]))
  }

  TEST_SUCCESS
}

TEST_IMPL(GLM_PREFIX, quat_init) {
  versor q1 = {1.0f, 2.0f, 3.0f, 4.0f};
  versor q2 = {1.0f, 2.0f, 3.0f, 4.0f};
  versor q3 = {1.0f, 2.0f, 3.0f, 4.0f};

  GLM(quat_init)(q1, 10.0f, 11.0f, 12.0f, 13.0f);
  GLM(quat_init)(q2, 100.0f, 110.0f, 120.0f, 130.0f);
  GLM(quat_init)(q3, 1000.0f, 1100.0f, 1200.0f, 1300.0f);

  ASSERT(q1[0] == 10.0f)
  ASSERT(q1[1] == 11.0f)
  ASSERT(q1[2] == 12.0f)
  ASSERT(q1[3] == 13.0f)

  ASSERT(q2[0] == 100.0f)
  ASSERT(q2[1] == 110.0f)
  ASSERT(q2[2] == 120.0f)
  ASSERT(q2[3] == 130.0f)

  ASSERT(q3[0] == 1000.0f)
  ASSERT(q3[1] == 1100.0f)
  ASSERT(q3[2] == 1200.0f)
  ASSERT(q3[3] == 1300.0f)

  TEST_SUCCESS
}

TEST_IMPL(GLM_PREFIX, quatv) {
  versor q1 = {1.0f, 2.0f, 3.0f, 4.0f};
  vec3   v1, v2;
  float  a1;

  test_rand_vec3(v1);
  GLM(quatv)(q1, glm_rad(60.0f), v1);

  glm_quat_axis(q1, v2);
  a1 = glm_quat_angle(q1);

  ASSERT(test_eq(a1, glm_rad(60.0f)))

  glm_vec3_normalize(v1);
  ASSERTIFY(test_assert_vec3_eq(v1, v2))

  TEST_SUCCESS
}

TEST_IMPL(GLM_PREFIX, quat) {
  versor q1 = {1.0f, 2.0f, 3.0f, 4.0f};
  vec3   v1, v2;
  float  a1;

  test_rand_vec3(v1);
  GLM(quat)(q1, glm_rad(60.0f), v1[0], v1[1], v1[2]);

  glm_quat_axis(q1, v2);
  a1 = glm_quat_angle(q1);

  ASSERT(test_eq(a1, glm_rad(60.0f)))

  glm_vec3_normalize(v1);
  ASSERTIFY(test_assert_vec3_eq(v1, v2))

  TEST_SUCCESS
}

TEST_IMPL(GLM_PREFIX, quat_copy) {
  versor v1 = {10.0f, 9.0f, 8.0f, 78.0f};
  versor v2 = {1.0f, 2.0f, 3.0f, 4.0f};

  GLM(quat_copy)(v1, v2);

  ASSERTIFY(test_assert_vec4_eq(v1, v2))

  TEST_SUCCESS
}

TEST_IMPL(GLM_PREFIX, quat_from_vecs) {
  versor q1, q2, q3, q4, q5, q6, q7;
  vec3   v1 = {1.f, 0.f, 0.f}, v2 = {1.f, 0.f, 0.f};      /* parallel       */
  vec3   v3 = {0.f, 1.f, 0.f}, v4 = {1.f, 0.f, 0.f};      /* perpendicular  */
  vec3   v5 = {0.f, 0.f, 1.f}, v6 = {0.f, 0.f, -1.f};     /* straight       */
  vec3   v7, v8;                                          /* random         */
  vec3   v9 = {0.57735026f, 0.57735026f, 0.57735026f},    /* acute          */
         v10 = {0.70710678f, 0.70710678f, 0.f};
  vec3   v11 = {0.87287156f, 0.21821789f, 0.43643578f},   /* obtuse         */
         v12 = {-0.87287156f, 0.21821789f, 0.43643578f};
  vec3   v13 = GLM_VEC3_ZERO_INIT;                        /* zero           */

  GLM(quat_from_vecs)(v1, v2, q1);
  ASSERTIFY(test_assert_quat_eq_identity(q1))

  GLM(quat_from_vecs)(v3, v4, q2);
  GLM(quat_rotatev)(q2, v3, v3);
  ASSERT(test_eq(GLM(vec3_dot)(v3, v4), 1.f))
  ASSERT(test_eq(q2[0], 0.f))
  ASSERT(test_eq(q2[1], 0.f))
  ASSERT(test_eq(q2[2], -0.707106781187f))
  ASSERT(test_eq(q2[3], 0.707106781187f))

  GLM(quat_from_vecs)(v5, v6, q3);
  GLM(quat_rotatev)(q3, v5, v5);
  ASSERT(test_eq(GLM(vec3_dot)(v5, v6), 1.f))
  ASSERT(test_eq(q3[0], 0.f))
  ASSERT(test_eq(q3[1], -1.f))
  ASSERT(test_eq(q3[2], 0.f))
  ASSERT(test_eq(q3[3], 0.f))

  test_rand_vec3(v7);
  test_rand_vec3(v8);
  GLM(vec3_normalize(v7));
  GLM(vec3_normalize(v8));
  GLM(quat_from_vecs)(v7, v8, q4);
  GLM(quat_rotatev)(q4, v7, v7);
  ASSERT(test_eq(GLM(vec3_dot)(v7, v8), 1.f))

  GLM(quat_from_vecs)(v9, v10, q5);
  GLM(quat_rotatev)(q5, v9, v9);
  ASSERT(test_eq(GLM(vec3_dot)(v9, v10), 1.f))

  GLM(quat_from_vecs)(v11, v12, q6);
  GLM(quat_rotatev)(q6, v11, v11);
  ASSERT(test_eq(GLM(vec3_dot)(v11, v12), 1.f))

  GLM(quat_from_vecs)(v13, v1, q7);
  ASSERTIFY(test_assert_quat_eq_identity(q7))

  TEST_SUCCESS
}

TEST_IMPL(GLM_PREFIX, quat_norm) {
  versor a = {10.0f, 9.0f, 8.0f, 78.0f};
  float  n1, n2;

  n1 = GLM(quat_norm)(a);
  n2 = sqrtf(a[0] * a[0] + a[1] * a[1] + a[2] * a[2] + a[3] * a[3]);

  ASSERT(test_eq(n1, n2))

  TEST_SUCCESS
}

TEST_IMPL(GLM_PREFIX, quat_normalize_to) {
  versor v1 = {2.0f, -3.0f, 4.0f, 5.0f}, v2;
  float  s  = 1.0f;
  float  norm;

  GLM(quat_normalize_to)(v1, v2);

  norm = sqrtf(v1[0] * v1[0] + v1[1] * v1[1] + v1[2] * v1[2] + v1[3] * v1[3]);
  if (norm <= 0.0f) {
    ASSERTIFY(test_assert_quat_eq_identity(v1))

    TEST_SUCCESS
  }

  norm = s / norm;

  ASSERT(test_eq(v1[0] * norm, v2[0]))
  ASSERT(test_eq(v1[1] * norm, v2[1]))
  ASSERT(test_eq(v1[2] * norm, v2[2]))
  ASSERT(test_eq(v1[3] * norm, v2[3]))

  glm_vec4_zero(v1);
  GLM(quat_normalize_to)(v1, v2);
  ASSERTIFY(test_assert_quat_eq_identity(v2))

  TEST_SUCCESS
}

TEST_IMPL(GLM_PREFIX, quat_normalize) {
  versor v1 = {2.0f, -3.0f, 4.0f, 5.0f}, v2 = {2.0f, -3.0f, 4.0f, 5.0f};
  float  s  = 1.0f;
  float  norm;

  GLM(quat_normalize)(v2);

  norm = sqrtf(v1[0] * v1[0] + v1[1] * v1[1] + v1[2] * v1[2] + v1[3] * v1[3]);
  if (norm <= 0.0f) {
    ASSERTIFY(test_assert_quat_eq_identity(v1))

    TEST_SUCCESS
  }

  norm = s / norm;

  ASSERT(test_eq(v1[0] * norm, v2[0]))
  ASSERT(test_eq(v1[1] * norm, v2[1]))
  ASSERT(test_eq(v1[2] * norm, v2[2]))
  ASSERT(test_eq(v1[3] * norm, v2[3]))

  glm_vec4_zero(v1);
  GLM(quat_normalize)(v1);
  ASSERTIFY(test_assert_quat_eq_identity(v1))

  TEST_SUCCESS
}

TEST_IMPL(GLM_PREFIX, quat_dot) {
  versor a = {10.0f, 9.0f, 8.0f, 78.0f};
  versor b = {1.0f, 2.0f, 3.0f, 4.0f};
  float  dot1, dot2;

  dot1 = GLM(quat_dot)(a, b);
  dot2 = a[0] * b[0] + a[1] * b[1] + a[2] * b[2] + a[3] * b[3];

  ASSERT(test_eq(dot1, dot2))

  TEST_SUCCESS
}

TEST_IMPL(GLM_PREFIX, quat_conjugate) {
  versor a = {10.0f, 9.0f, 8.0f, 78.0f};
  versor b = {1.0f, 2.0f, 3.0f, 4.0f};
  versor d, e;

  GLM(quat_conjugate)(a, d);
  GLM(quat_conjugate)(b, e);

  ASSERT(test_eq(d[0], -a[0]))
  ASSERT(test_eq(d[1], -a[1]))
  ASSERT(test_eq(d[2], -a[2]))
  ASSERT(test_eq(d[3],  a[3]))

  ASSERT(test_eq(e[0], -b[0]))
  ASSERT(test_eq(e[1], -b[1]))
  ASSERT(test_eq(e[2], -b[2]))
  ASSERT(test_eq(e[3],  b[3]))

  TEST_SUCCESS
}

TEST_IMPL(GLM_PREFIX, quat_inv) {
  versor a = {10.0f, 9.0f, 8.0f, 78.0f};
  versor b = {1.0f, 2.0f, 3.0f, 4.0f};
  versor d, e;
  float n1, n2;

  n1 = 1.0f / glm_vec4_norm2(a);
  n2 = 1.0f / glm_vec4_norm2(b);

  GLM(quat_inv)(a, d);
  GLM(quat_inv)(b, e);

  ASSERT(test_eq(d[0], -a[0] * n1))
  ASSERT(test_eq(d[1], -a[1] * n1))
  ASSERT(test_eq(d[2], -a[2] * n1))
  ASSERT(test_eq(d[3],  a[3] * n1))

  ASSERT(test_eq(e[0], -b[0] * n2))
  ASSERT(test_eq(e[1], -b[1] * n2))
  ASSERT(test_eq(e[2], -b[2] * n2))
  ASSERT(test_eq(e[3],  b[3] * n2))

  TEST_SUCCESS
}

TEST_IMPL(GLM_PREFIX, quat_add) {
  versor a = {-10.0f, 9.0f, -8.0f, 56.0f};
  versor b = {12.0f, 19.0f, -18.0f, 1.0f};
  versor c, d;

  c[0] = a[0] + b[0];
  c[1] = a[1] + b[1];
  c[2] = a[2] + b[2];
  c[3] = a[3] + b[3];

  GLM(quat_add)(a, b, d);

  ASSERTIFY(test_assert_quat_eq(c, d))

  TEST_SUCCESS
}

TEST_IMPL(GLM_PREFIX, quat_sub) {
  vec4 a = {-10.0f, 9.0f, -8.0f, 56.0f};
  vec4 b = {12.0f, 19.0f, -18.0f, 1.0f};
  vec4 c, d;

  c[0] = a[0] - b[0];
  c[1] = a[1] - b[1];
  c[2] = a[2] - b[2];
  c[3] = a[3] - b[3];

  GLM(quat_sub)(a, b, d);

  ASSERTIFY(test_assert_quat_eq(c, d))

  TEST_SUCCESS
}

TEST_IMPL(GLM_PREFIX, quat_real) {
  versor a = {10.0f, 9.0f, 8.0f, 78.0f};
  versor b = {1.0f, 2.0f, 3.0f, 4.0f};

  ASSERT(test_eq(GLM(quat_real)(a), 78.0f))
  ASSERT(test_eq(GLM(quat_real)(b), 4.0f))

  TEST_SUCCESS
}

TEST_IMPL(GLM_PREFIX, quat_imag) {
  versor a = {10.0f, 9.0f, 8.0f, 78.0f};
  versor b = {1.0f, 2.0f, 3.0f, 4.0f};
  vec3   d, e;

  GLM(quat_imag)(a, d);
  GLM(quat_imag)(b, e);

  ASSERT(test_eq(d[0], a[0]))
  ASSERT(test_eq(d[1], a[1]))
  ASSERT(test_eq(d[2], a[2]))

  ASSERT(test_eq(e[0], b[0]))
  ASSERT(test_eq(e[1], b[1]))
  ASSERT(test_eq(e[2], b[2]))

  TEST_SUCCESS
}

TEST_IMPL(GLM_PREFIX, quat_imagn) {
  versor a = {10.0f, 9.0f, 8.0f, 78.0f};
  versor b = {1.0f, 2.0f, 3.0f, 4.0f};
  vec3   d, e;

  GLM(quat_imagn)(a, d);
  GLM(quat_imagn)(b, e);

  glm_vec3_normalize(a);
  glm_vec3_normalize(b);
  glm_vec3_normalize(d);
  glm_vec3_normalize(e);

  ASSERT(test_eq(d[0], a[0]))
  ASSERT(test_eq(d[1], a[1]))
  ASSERT(test_eq(d[2], a[2]))

  ASSERT(test_eq(e[0], b[0]))
  ASSERT(test_eq(e[1], b[1]))
  ASSERT(test_eq(e[2], b[2]))

  TEST_SUCCESS
}

TEST_IMPL(GLM_PREFIX, quat_imaglen) {
  versor a = {10.0f, 9.0f, 8.0f, 78.0f};
  versor b = {1.0f, 2.0f, 3.0f, 4.0f};

  ASSERT(test_eq(GLM(quat_imaglen)(a), glm_vec3_norm(a)));
  ASSERT(test_eq(GLM(quat_imaglen)(b), glm_vec3_norm(b)));

  TEST_SUCCESS
}

TEST_IMPL(GLM_PREFIX, quat_angle) {
  versor q1 = {1.0f, 2.0f, 3.0f, 4.0f}, q2, q3;
  vec3   v1;
  float  a1, a2, a3;

  test_rand_vec3(v1);
  GLM(quatv)(q1, glm_rad(60.140f), v1);
  GLM(quatv)(q2, glm_rad(160.04f), v1);
  GLM(quatv)(q3, glm_rad(20.350f), v1);

  a1 = GLM(quat_angle)(q1);
  a2 = GLM(quat_angle)(q2);
  a3 = GLM(quat_angle)(q3);

  ASSERT(test_eq(a1, glm_rad(60.140f)))
  ASSERT(test_eq(a2, glm_rad(160.04f)))
  ASSERT(test_eq(a3, glm_rad(20.350f)))

  TEST_SUCCESS
}

TEST_IMPL(GLM_PREFIX, quat_axis) {
  versor q1 = {1.0f, 2.0f, 3.0f, 4.0f}, q2, q3;
  vec3   v1, v2;

  test_rand_vec3(v1);
  GLM(quatv)(q1, glm_rad(60.0f), v1);

  glm_quat_axis(q1, v2);
  glm_vec3_normalize(v1);
  ASSERTIFY(test_assert_vec3_eq(v1, v2))

  test_rand_vec3(v1);
  GLM(quatv)(q2, glm_rad(60.0f), v1);

  glm_quat_axis(q2, v2);
  glm_vec3_normalize(v1);
  ASSERTIFY(test_assert_vec3_eq(v1, v2))

  test_rand_vec3(v1);
  GLM(quatv)(q3, glm_rad(60.0f), v1);

  glm_quat_axis(q3, v2);
  glm_vec3_normalize(v1);
  ASSERTIFY(test_assert_vec3_eq(v1, v2))

  TEST_SUCCESS
}

TEST_IMPL(GLM_PREFIX, quat_mul) {
  versor q1 = {2.0f, 3.0f, 4.0f, 5.0f};
  versor q2 = {6.0f, 7.0f, 8.0f, 9.0f};
  versor q3;
  versor q4;
  vec3   v1 = {1.5f, 2.5f, 3.5f};

  GLM(quat_mul)(q1, q2, q3);

  ASSERT(test_eq(q3[0], q1[3] * q2[0] + q1[0] * q2[3] + q1[1] * q2[2] - q1[2] * q2[1]))
  ASSERT(test_eq(q3[1], q1[3] * q2[1] - q1[0] * q2[2] + q1[1] * q2[3] + q1[2] * q2[0]))
  ASSERT(test_eq(q3[2], q1[3] * q2[2] + q1[0] * q2[1] - q1[1] * q2[0] + q1[2] * q2[3]))
  ASSERT(test_eq(q3[3], q1[3] * q2[3] - q1[0] * q2[0] - q1[1] * q2[1] - q1[2] * q2[2]))

  glm_quatv(q1, glm_rad(30.0f), v1);
  glm_quatv(q2, glm_rad(20.0f), v1);
  glm_quatv(q3, glm_rad(50.0f), v1);

  GLM(quat_mul)(q1, q2, q4);

  ASSERTIFY(test_assert_quat_eq(q3, q4))

  TEST_SUCCESS
}

TEST_IMPL(GLM_PREFIX, quat_mat4) {
  mat4   m1, m2;
  versor q1, q2, q3;
  vec3   axis1;
  vec3   axis2 = {1.9f, 2.3f, 4.5f};
  int    i;

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

  /* 1. test quat to mat and mat to quat */
  for (i = 0; i < 1000; i++) {
    test_rand_quat(q1);

    GLM(quat_mat4)(q1, m1);
    GLM(mat4_quat)(m1, q2);
    GLM(quat_mat4)(q2, m2);

    /* 2. test first quat and generated one equality */
    ASSERTIFY(test_assert_quat_eq_abs(q1, q2));

    /* 3. test first rot and second rotation */
    /* almost equal */
    ASSERTIFY(test_assert_mat4_eq2(m1, m2, 0.000009f));
  }

  TEST_SUCCESS
}

TEST_IMPL(GLM_PREFIX, quat_mat4t) {
  mat4   m1, m2;
  versor q1, q2, q3;
  vec3   axis1;
  vec3   axis2 = {1.9f, 2.3f, 4.5f};
  int    i;

  GLM(quat)(q1, GLM_PI_4f, 1.9f, 2.3f, 4.5f);

  GLM(quat_mat4t)(q1, m1);
  glm_mat4_transpose(m1);

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

  /* 1. test quat to mat and mat to quat */
  for (i = 0; i < 1000; i++) {
    test_rand_quat(q1);

    GLM(quat_mat4t)(q1, m1);
    glm_mat4_transpose(m1);

    GLM(mat4_quat)(m1, q2);

    GLM(quat_mat4t)(q2, m2);
    glm_mat4_transpose(m2);

    /* 2. test first quat and generated one equality */
    ASSERTIFY(test_assert_quat_eq_abs(q1, q2));

    /* 3. test first rot and second rotation */
    /* almost equal */
    ASSERTIFY(test_assert_mat4_eq2(m1, m2, 0.000009f));
  }

  TEST_SUCCESS
}

TEST_IMPL(GLM_PREFIX, quat_mat3) {
  mat4   m1, m2;
  mat3   m3;
  versor q1, q2, q3;
  vec3   axis1;
  vec3   axis2 = {1.9f, 2.3f, 4.5f};
  int    i;

  GLM(quat)(q1, GLM_PI_4f, 1.9f, 2.3f, 4.5f);
  GLM(quat_mat3)(q1, m3);
  glm_mat4_identity(m1);
  glm_mat4_ins3(m3, m1);

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

  /* 1. test quat to mat and mat to quat */
  for (i = 0; i < 1000; i++) {
    test_rand_quat(q1);

    GLM(quat_mat3)(q1, m3);
    glm_mat4_identity(m1);
    glm_mat4_ins3(m3, m1);

    GLM(mat4_quat)(m1, q2);

    GLM(quat_mat3)(q2, m3);
    glm_mat4_identity(m2);
    glm_mat4_ins3(m3, m2);

    /* 2. test first quat and generated one equality */
    ASSERTIFY(test_assert_quat_eq_abs(q1, q2));

    /* 3. test first rot and second rotation */
    /* almost equal */
    ASSERTIFY(test_assert_mat4_eq2(m1, m2, 0.000009f));
  }

  TEST_SUCCESS
}

TEST_IMPL(GLM_PREFIX, quat_mat3t) {
  mat4   m1, m2;
  mat3   m3;
  versor q1, q2, q3;
  vec3   axis1;
  vec3   axis2 = {1.9f, 2.3f, 4.5f};
  int    i;

  GLM(quat)(q1, GLM_PI_4f, 1.9f, 2.3f, 4.5f);

  GLM(quat_mat3t)(q1, m3);
  glm_mat3_transpose(m3);
  glm_mat4_identity(m1);
  glm_mat4_ins3(m3, m1);

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

  /* 1. test quat to mat and mat to quat */
  for (i = 0; i < 1000; i++) {
    test_rand_quat(q1);

    GLM(quat_mat3t)(q1, m3);
    glm_mat3_transpose(m3);
    glm_mat4_identity(m1);
    glm_mat4_ins3(m3, m1);

    GLM(mat4_quat)(m1, q2);

    GLM(quat_mat3t)(q2, m3);
    glm_mat3_transpose(m3);
    glm_mat4_identity(m2);
    glm_mat4_ins3(m3, m2);

    /* 2. test first quat and generated one equality */
    ASSERTIFY(test_assert_quat_eq_abs(q1, q2));

    /* 3. test first rot and second rotation */
    /* almost equal */
    ASSERTIFY(test_assert_mat4_eq2(m1, m2, 0.000009f));
  }

  TEST_SUCCESS
}

TEST_IMPL(GLM_PREFIX, quat_lerp) {
  versor v1 = {-100.0f, -200.0f, -10.0f, -10.0f};
  versor v2 = {100.0f, 200.0f, 10.0f, 10.0f};
  versor v3;

  GLM(quat_lerp)(v1, v2, 0.5f, v3);
  ASSERT(test_eq(v3[0], 0.0f))
  ASSERT(test_eq(v3[1], 0.0f))
  ASSERT(test_eq(v3[2], 0.0f))
  ASSERT(test_eq(v3[3], 0.0f))

  GLM(quat_lerp)(v1, v2, 0.75f, v3);
  ASSERT(test_eq(v3[0], 50.0f))
  ASSERT(test_eq(v3[1], 100.0f))
  ASSERT(test_eq(v3[2], 5.0f))
  ASSERT(test_eq(v3[3], 5.0f))

  TEST_SUCCESS
}

TEST_IMPL(GLM_PREFIX, quat_lerpc) {
  versor v1 = {-100.0f, -200.0f, -10.0f, -10.0f};
  versor v2 = {100.0f, 200.0f, 10.0f, 10.0f};
  versor v3;

  GLM(quat_lerpc)(v1, v2, 0.5f, v3);
  ASSERT(test_eq(v3[0], 0.0f))
  ASSERT(test_eq(v3[1], 0.0f))
  ASSERT(test_eq(v3[2], 0.0f))
  ASSERT(test_eq(v3[3], 0.0f))

  GLM(quat_lerpc)(v1, v2, 0.75f, v3);
  ASSERT(test_eq(v3[0], 50.0f))
  ASSERT(test_eq(v3[1], 100.0f))
  ASSERT(test_eq(v3[2], 5.0f))
  ASSERT(test_eq(v3[3], 5.0f))

  GLM(quat_lerpc)(v1, v2, -1.75f, v3);
  ASSERT(test_eq(v3[0], -100.0f))
  ASSERT(test_eq(v3[1], -200.0f))
  ASSERT(test_eq(v3[2], -10.0f))
  ASSERT(test_eq(v3[3], -10.0f))

  GLM(quat_lerpc)(v1, v2, 1.75f, v3);
  ASSERT(test_eq(v3[0], 100.0f))
  ASSERT(test_eq(v3[1], 200.0f))
  ASSERT(test_eq(v3[2], 10.0f))
  ASSERT(test_eq(v3[3], 10.0f))

  TEST_SUCCESS
}

TEST_IMPL(GLM_PREFIX, quat_nlerp) {
  versor q1, q2, q3, q4;
  vec3 v1 = {10.0f, 0.0f, 0.0f}, v2;

  glm_quatv(q1, glm_rad(30.0f), v1);
  glm_quatv(q2, glm_rad(90.0f), v1);

  GLM(quat_nlerp)(q1, q2, 1.0f, q3);
  glm_quat_normalize(q2);
  ASSERTIFY(test_assert_quat_eq(q2, q3));

  glm_quatv(q1, glm_rad(30.001f), v1);
  glm_quatv(q2, glm_rad(30.002f), v1);
  GLM(quat_nlerp)(q1, q2, 0.7f, q3);
  glm_quat_lerp(q1, q2, 0.7f, q4);
  ASSERTIFY(test_assert_quat_eq(q3, q4));

  glm_quatv(q1, glm_rad(30.0f), v1);
  glm_quatv(q2, glm_rad(90.0f), v1);
  GLM(quat_nlerp)(q1, q2, 0.5f, q3);

  glm_quat_axis(q3, v2);
  glm_vec3_normalize(v1);
  glm_vec3_normalize(v2);

  ASSERT(glm_quat_angle(q3) > glm_rad(30.0f));
  ASSERT(glm_quat_angle(q3) < glm_rad(90.0f));
  ASSERTIFY(test_assert_vec3_eq(v1, v2))

  TEST_SUCCESS
}

TEST_IMPL(GLM_PREFIX, quat_slerp) {
  versor q1, q2, q3, q4;
  vec3 v1 = {10.0f, 0.0f, 0.0f}, v2;

  glm_quatv(q1, glm_rad(30.0f), v1);
  glm_quatv(q2, glm_rad(90.0f), v1);

  q1[0] = 10.0f;
  GLM(quat_slerp)(q1, q2, 1.0f, q3);
  ASSERTIFY(test_assert_quat_eq(q1, q3));

  glm_quatv(q1, glm_rad(30.001f), v1);
  glm_quatv(q2, glm_rad(30.002f), v1);
  GLM(quat_slerp)(q1, q2, 0.7f, q3);
  glm_quat_lerp(q1, q2, 0.7f, q4);
  ASSERTIFY(test_assert_quat_eq(q3, q4));

  glm_quatv(q1, glm_rad(30.0f), v1);
  glm_quatv(q2, glm_rad(90.0f), v1);
  GLM(quat_slerp)(q1, q2, 0.5f, q3);

  glm_quat_axis(q3, v2);
  glm_vec3_normalize(v1);
  glm_vec3_normalize(v2);

  ASSERT(glm_quat_angle(q3) > glm_rad(30.0f));
  ASSERT(glm_quat_angle(q3) < glm_rad(90.0f));
  ASSERTIFY(test_assert_vec3_eq(v1, v2))

  TEST_SUCCESS
}

TEST_IMPL(GLM_PREFIX, quat_look) {
  versor q1;
  vec3   v1 = {0.0f, 1.0f, 0.0f};
  mat4   m1, m2;
  
  glm_quat(q1, glm_rad(90.0f), 0.0f, 1.0f, 0.0f);
  GLM(quat_look)(v1, q1, m1);

  glm_look(v1, (vec3){-1.0f, 0.0f, 0.0f}, GLM_YUP, m2);
  ASSERTIFY(test_assert_mat4_eq(m1, m2));
  
  glm_quat(q1, glm_rad(180.0f), 1.0f, 0.0f, 0.0f);
  GLM(quat_look)(v1, q1, m1);
  
  glm_look(v1, (vec3){0.0f, 0.0f, 1.0f}, (vec3){0.0f, -1.0f, 0.0f}, m2);

  ASSERTIFY(test_assert_mat4_eq(m1, m2));

  TEST_SUCCESS
}

TEST_IMPL(GLM_PREFIX, quat_for) {
  versor q1, q2;

  glm_quat(q1, glm_rad(90.0f), 0.0f, 1.0f, 0.0f);
  GLM(quat_for)((vec3){-1.0f, 0.0f, 0.0f}, (vec3){0.0f, 1.0f, 0.0f}, q2);
  ASSERTIFY(test_assert_quat_eq(q1, q2));

  glm_quat(q2, glm_rad(90.0f), 1.0f, 0.0f, 0.0f);
  GLM(quat_for)((vec3){0.0f, 1.0f, 0.0f}, (vec3){0.0f, 0.0f, 1.0f}, q1);
  ASSERTIFY(test_assert_quat_eq(q1, q2));

  glm_quat(q2, glm_rad(180.0f), 1.0f, 0.0f, 0.0f);
  GLM(quat_for)((vec3){0.0f, 0.0f, 1.0f}, (vec3){0.0f, -1.0f, 0.0f}, q1);
  ASSERTIFY(test_assert_quat_eq(q1, q2));

  TEST_SUCCESS
}

TEST_IMPL(GLM_PREFIX, quat_forp) {
  versor q1, q2;

  glm_quat(q1, glm_rad(90.0f), 0.0f, 1.0f, 0.0f);
  GLM(quat_forp)((vec3){2.0f, 0.0f, 0.0f},
                 (vec3){1.0f, 0.0f, 0.0f}, 
                 (vec3){0.0f, 1.0f, 0.0f}, 
                 q2);
  ASSERTIFY(test_assert_quat_eq(q1, q2));

  glm_quat(q2, glm_rad(90.0f), 1.0f, 0.0f, 0.0f);
  GLM(quat_forp)((vec3){0.0f, 1.0f, 0.0f}, 
                 (vec3){0.0f, 2.0f, 0.0f},
                 (vec3){0.0f, 0.0f, 1.0f},
                 q1);
  ASSERTIFY(test_assert_quat_eq(q1, q2));

  glm_quat(q2, glm_rad(180.0f), 1.0f, 0.0f, 0.0f);
  GLM(quat_forp)((vec3){0.0f, 1.0f, 1.0f}, 
                 (vec3){0.0f, 1.0f, 2.0f},
                 (vec3){0.0f, -1.0f, 0.0f},
                 q1);
  ASSERTIFY(test_assert_quat_eq(q1, q2));

  TEST_SUCCESS
}

TEST_IMPL(GLM_PREFIX, quat_rotatev) {
  vec3   v1 = {1.0f, 0.0f, 0.0f}, v2 = {1.0f, 1.0f, 1.0f};
  versor q;

  /* rotate X around Y = -Z */
  glm_quatv(q, GLM_PI_2f, GLM_YUP);
  GLM(quat_rotatev)(q, v1, v1);

  ASSERT(test_eq(v1[0],  0.0f))
  ASSERT(test_eq(v1[1],  0.0f))
  ASSERT(test_eq(v1[2], -1.0f))

  /* rotate -Z around X = Y */
  glm_quatv(q, GLM_PI_2f, GLM_XUP);
  GLM(quat_rotatev)(q, v1, v1);

  ASSERT(test_eq(v1[0],  0.0f))
  ASSERT(test_eq(v1[1],  1.0f))
  ASSERT(test_eq(v1[2],  0.0f))

  /* rotate Y around Z = -X */
  glm_quatv(q, GLM_PI_2f, GLM_ZUP);
  GLM(quat_rotatev)(q, v1, v1);

  ASSERT(test_eq(v1[0], -1.0f))
  ASSERT(test_eq(v1[1],  0.0f))
  ASSERT(test_eq(v1[2],  0.0f))

  /* rotate v2 around Y by 90deg */
  glm_quatv(q, GLM_PI_2f, GLM_YUP);
  GLM(quat_rotatev)(q, v2, v2);

  ASSERT(test_eq(v2[0],  1.0f))
  ASSERT(test_eq(v2[1],  1.0f))
  ASSERT(test_eq(v2[2], -1.0f))

  /* rotate v2 around Y by 90deg */
  glm_quatv(q, GLM_PI_2f, GLM_YUP);
  GLM(quat_rotatev)(q, v2, v2);

  ASSERT(test_eq(v2[0], -1.0f))
  ASSERT(test_eq(v2[1],  1.0f))
  ASSERT(test_eq(v2[2], -1.0f))

  /* rotate v2 around Y by 90deg */
  glm_quatv(q, GLM_PI_2f, GLM_YUP);
  GLM(quat_rotatev)(q, v2, v2);

  ASSERT(test_eq(v2[0], -1.0f))
  ASSERT(test_eq(v2[1],  1.0f))
  ASSERT(test_eq(v2[2],  1.0f))

  /* rotate v2 around X by 90deg */
  glm_quatv(q, GLM_PI_2f, GLM_XUP);
  GLM(quat_rotatev)(q, v2, v2);

  ASSERT(test_eq(v2[0], -1.0f))
  ASSERT(test_eq(v2[1], -1.0f))
  ASSERT(test_eq(v2[2],  1.0f))

  /* rotate v2 around Z by 90deg */
  glm_quatv(q, GLM_PI_2f, GLM_ZUP);
  GLM(quat_rotatev)(q, v2, v2);

  ASSERT(test_eq(v2[0],  1.0f))
  ASSERT(test_eq(v2[1], -1.0f))
  ASSERT(test_eq(v2[2],  1.0f))

  TEST_SUCCESS
}

TEST_IMPL(GLM_PREFIX, quat_rotate) {
  mat4   m1 = GLM_MAT4_IDENTITY_INIT, m2;
  versor q1;
  vec4   v1 = {1.0f, 0.0f, 0.0f, 1.0f};

  /* rotate X around Y = -Z */
  glm_quatv(q1, GLM_PI_2f, GLM_YUP);
  GLM(quat_rotate)(m1, q1, m1);
  glm_rotate_make(m2, GLM_PI_2f, GLM_YUP);
  ASSERTIFY(test_assert_mat4_eq(m1, m2))
  glm_mat4_mulv(m1, v1, v1);

  ASSERT(test_eq(v1[0],  0.0f))
  ASSERT(test_eq(v1[1],  0.0f))
  ASSERT(test_eq(v1[2], -1.0f))

  glm_mat4_identity(m1);
  glm_mat4_identity(m2);
  
  /* rotate -Z around X = Y */
  glm_quatv(q1, GLM_PI_2f, GLM_XUP);
  GLM(quat_rotate)(m1, q1, m1);
  glm_rotate(m2, GLM_PI_2f, GLM_XUP);
  ASSERTIFY(test_assert_mat4_eq(m1, m2))
  glm_mat4_mulv(m1, v1, v1);

  ASSERT(test_eq(v1[0],  0.0f))
  ASSERT(test_eq(v1[1],  1.0f))
  ASSERT(test_eq(v1[2],  0.0f))

  glm_mat4_identity(m1);
  glm_mat4_identity(m2);

  /* rotate Y around X = +Z */
  glm_quatv(q1, GLM_PI_2f, GLM_XUP);
  GLM(quat_rotate)(m1, q1, m1);
  glm_rotate(m2, GLM_PI_2f, GLM_XUP);
  ASSERTIFY(test_assert_mat4_eq(m1, m2))
  glm_mat4_mulv(m1, v1, v1);

  ASSERT(test_eq(v1[0],  0.0f))
  ASSERT(test_eq(v1[1],  0.0f))
  ASSERT(test_eq(v1[2],  1.0f))

  TEST_SUCCESS
}

TEST_IMPL(GLM_PREFIX, quat_rotate_at) {
  mat4   m1 = GLM_MAT4_IDENTITY_INIT;
  versor q1;
  vec4   v1 = {1.0f, 0.0f, 0.0f, 1.0f};

  glm_quatv(q1, GLM_PI_2f, GLM_YUP);
  GLM(quat_rotate_at)(m1, q1, (vec3){0.5f, 0.0f, 0.0f});
  glm_mat4_mulv(m1, v1, v1);

  ASSERT(test_eq(v1[0],  0.5f))
  ASSERT(test_eq(v1[1],  0.0f))
  ASSERT(test_eq(v1[2], -0.5f))

  glm_mat4_identity(m1);

  glm_quatv(q1, GLM_PI_2f, GLM_ZUP);
  GLM(quat_rotate_at)(m1, q1, (vec3){0.0f, 0.0f, 0.0f});
  glm_mat4_mulv(m1, v1, v1);

  ASSERT(test_eq(v1[0],  0.0f))
  ASSERT(test_eq(v1[1],  0.5f))
  ASSERT(test_eq(v1[2], -0.5f))

  glm_mat4_identity(m1);

  v1[0] = 1.0f;
  v1[1] = 1.0f;
  v1[2] = 1.0f;

  glm_quatv(q1, GLM_PI_2f, GLM_XUP);
  GLM(quat_rotate_at)(m1, q1, GLM_VEC3_ZERO);
  glm_mat4_mulv(m1, v1, v1);

  ASSERT(test_eq(v1[0],  1.0f))
  ASSERT(test_eq(v1[1], -1.0f))
  ASSERT(test_eq(v1[2],  1.0f))

  TEST_SUCCESS
}

TEST_IMPL(GLM_PREFIX, quat_rotate_atm) {
  mat4   m1 = GLM_MAT4_IDENTITY_INIT;
  versor q1;
  vec4   v1 = {1.0f, 0.0f, 0.0f, 1.0f};

  glm_quatv(q1, GLM_PI_2f, GLM_YUP);
  GLM(quat_rotate_atm)(m1, q1, (vec3){0.5f, 0.0f, 0.0f});
  glm_mat4_mulv(m1, v1, v1);

  ASSERT(test_eq(v1[0],  0.5f))
  ASSERT(test_eq(v1[1],  0.0f))
  ASSERT(test_eq(v1[2], -0.5f))

  glm_quatv(q1, GLM_PI_2f, GLM_ZUP);
  GLM(quat_rotate_atm)(m1, q1, (vec3){0.0f, 0.0f, 0.0f});
  glm_mat4_mulv(m1, v1, v1);

  ASSERT(test_eq(v1[0],  0.0f))
  ASSERT(test_eq(v1[1],  0.5f))
  ASSERT(test_eq(v1[2], -0.5f))

  v1[0] = 1.0f;
  v1[1] = 1.0f;
  v1[2] = 1.0f;

  glm_quatv(q1, GLM_PI_2f, GLM_XUP);
  GLM(quat_rotate_atm)(m1, q1, GLM_VEC3_ZERO);
  glm_mat4_mulv(m1, v1, v1);

  ASSERT(test_eq(v1[0],  1.0f))
  ASSERT(test_eq(v1[1], -1.0f))
  ASSERT(test_eq(v1[2],  1.0f))

  TEST_SUCCESS
}
