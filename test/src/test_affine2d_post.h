/*
 * Copyright (c), Recep Aslantas.
 *
 * MIT License (MIT), http://opensource.org/licenses/MIT
 * Full license can be found in the LICENSE file
 */

#include "test_common.h"

TEST_IMPL(GLM_PREFIX, translated2d) {
  mat3 m1, m2, tmp;
  vec2 v = { 1.2f, 3.4f };

  test_rand_transform2d(m1);
  glm_mat3_copy(m1, m2);
  GLM(translated2d)(m2, v);

  glm_translate2d_make(tmp, v);
  glm_mat3_mul(tmp, m1, m1);

  test_assert_mat3_eq(m1, m2);

  TEST_SUCCESS
}

TEST_IMPL(GLM_PREFIX, translated2d_x) {
  mat3 m1, m2, tmp;
  float x = test_rand();

  test_rand_transform2d(m1);
  glm_mat3_copy(m1, m2);
  GLM(translated2d_x)(m2, x);

  glm_translate2d_make(tmp, (vec2) { x, 0.0f });
  glm_mat3_mul(tmp, m1, m1);

  test_assert_mat3_eq(m1, m2);

  TEST_SUCCESS
}

TEST_IMPL(GLM_PREFIX, translated2d_y) {
  mat3 m1, m2, tmp;
  float y = test_rand();

  test_rand_transform2d(m1);
  glm_mat3_copy(m1, m2);
  GLM(translated2d_y)(m2, y);

  glm_translate2d_make(tmp, (vec2) { 0.0f, y });
  glm_mat3_mul(tmp, m1, m1);

  test_assert_mat3_eq(m1, m2);

  TEST_SUCCESS
}

TEST_IMPL(GLM_PREFIX, rotated2d) {
  mat3 m1, m2, tmp;
  float a = test_rand();

  test_rand_transform2d(m1);
  glm_mat3_copy(m1, m2);
  GLM(rotated2d)(m2, a);

  glm_rotate2d_make(tmp, a);
  glm_mat3_mul(tmp, m1, m1);

  test_assert_mat3_eq(m1, m2);

  TEST_SUCCESS
}

TEST_IMPL(GLM_PREFIX, scaled2d) {
  mat3 m1, m2, tmp;
  vec2 v = { test_rand(), test_rand() };

  test_rand_transform2d(m1);
  glm_mat3_copy(m1, m2);
  GLM(scaled2d)(m2, v);

  glm_scale2d_make(tmp, v);
  glm_mat3_mul(tmp, m1, m1);

  test_assert_mat3_eq(m1, m2);

  TEST_SUCCESS
}

TEST_IMPL(GLM_PREFIX, scaled2d_uni) {
  mat3 m1, m2, tmp;
  float s = test_rand();

  test_rand_transform2d(m1);
  glm_mat3_copy(m1, m2);
  GLM(scaled2d_uni)(m2, s);

  glm_scale2d_make(tmp, (vec2) { s, s });
  glm_mat3_mul(tmp, m1, m1);

  test_assert_mat3_eq(m1, m2);

  TEST_SUCCESS
}
