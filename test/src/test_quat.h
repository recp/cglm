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
