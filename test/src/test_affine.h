/*
 * Copyright (c), Recep Aslantas.
 *
 * MIT License (MIT), http://opensource.org/licenses/MIT
 * Full license can be found in the LICENSE file
 */

#include "test_common.h"

TEST_IMPL(GLM_PREFIX, translate) {
  mat4 t1, t2, t3, t4, t5;
  mat4 m1;
  vec4 v1 = {1.0f, 2.0f, 3.0f, 1.0f}, v2;

  glm_mat4_identity(m1);
  GLM(translate)(m1, (vec3){13.0f, 11.0f, 7.0f});
  glm_mat4_mulv(m1, v1, v2);

  ASSERT(test_eq(v2[0], 14.0f))
  ASSERT(test_eq(v2[1], 13.0f))
  ASSERT(test_eq(v2[2], 10.0f))
  ASSERT(test_eq(v2[3], 1.0f))

  glm_mat4_identity(m1);
  GLM(translate)(m1, (vec3){1.0f, -1.0f, -5.0f});
  glm_mat4_mulv(m1, v2, v2);

  ASSERT(test_eq(v2[0], 15.0f))
  ASSERT(test_eq(v2[1], 12.0f))
  ASSERT(test_eq(v2[2], 5.0f))
  ASSERT(test_eq(v2[3], 1.0f))

  TEST_SUCCESS
}

TEST_IMPL(GLM_PREFIX, translate_to) {
  mat4 t1, t2, t3, t4, t5;
  mat4 m1, m2;
  vec4 v1 = {1.0f, 2.0f, 3.0f, 1.0f}, v2;

  glm_mat4_identity(m1);
  GLM(translate_to)(m1, (vec3){13.0f, 11.0f, 7.0f}, m2);
  glm_mat4_mulv(m2, v1, v2);

  ASSERT(test_eq(v2[0], 14.0f))
  ASSERT(test_eq(v2[1], 13.0f))
  ASSERT(test_eq(v2[2], 10.0f))
  ASSERT(test_eq(v2[3], 1.0f))

  glm_mat4_identity(m1);
  GLM(translate_to)(m1, (vec3){1.0f, -1.0f, -5.0f}, m2);
  glm_mat4_mulv(m2, v2, v2);

  ASSERT(test_eq(v2[0], 15.0f))
  ASSERT(test_eq(v2[1], 12.0f))
  ASSERT(test_eq(v2[2], 5.0f))
  ASSERT(test_eq(v2[3], 1.0f))

  TEST_SUCCESS
}

TEST_IMPL(GLM_PREFIX, translate_x) {
  mat4 t1, t2, t3, t4, t5;
  mat4 m1;
  vec4 v1 = {1.0f, 2.0f, 3.0f, 1.0f}, v2;

  glm_mat4_identity(m1);
  GLM(translate_x)(m1, 13.0f);
  glm_mat4_mulv(m1, v1, v2);

  ASSERT(test_eq(v2[0], 14.0f))
  ASSERT(test_eq(v2[1], 2.0f))
  ASSERT(test_eq(v2[2], 3.0f))
  ASSERT(test_eq(v2[3], 1.0f))

  glm_mat4_identity(m1);
  GLM(translate_x)(m1, -1.0f);
  glm_mat4_mulv(m1, v2, v2);

  ASSERT(test_eq(v2[0], 13.0f))
  ASSERT(test_eq(v2[1], 2.0f))
  ASSERT(test_eq(v2[2], 3.0f))
  ASSERT(test_eq(v2[3], 1.0f))

  TEST_SUCCESS
}

TEST_IMPL(GLM_PREFIX, translate_y) {
  mat4 t1, t2, t3, t4, t5;
  mat4 m1;
  vec4 v1 = {1.0f, 2.0f, 3.0f, 1.0f}, v2;

  glm_mat4_identity(m1);
  GLM(translate_y)(m1, 11.0f);
  glm_mat4_mulv(m1, v1, v2);

  ASSERT(test_eq(v2[0], 1.0f))
  ASSERT(test_eq(v2[1], 13.0f))
  ASSERT(test_eq(v2[2], 3.0f))
  ASSERT(test_eq(v2[3], 1.0f))

  glm_mat4_identity(m1);
  GLM(translate_y)(m1, -1.0f);
  glm_mat4_mulv(m1, v2, v2);

  ASSERT(test_eq(v2[0], 1.0f))
  ASSERT(test_eq(v2[1], 12.0f))
  ASSERT(test_eq(v2[2], 3.0f))
  ASSERT(test_eq(v2[3], 1.0f))

  TEST_SUCCESS
}

TEST_IMPL(GLM_PREFIX, translate_z) {
  mat4 t1, t2, t3, t4, t5;
  mat4 m1;
  vec4 v1 = {1.0f, 2.0f, 3.0f, 1.0f}, v2;

  glm_mat4_identity(m1);
  GLM(translate_z)(m1, 7.0f);
  glm_mat4_mulv(m1, v1, v2);

  ASSERT(test_eq(v2[0], 1.0f))
  ASSERT(test_eq(v2[1], 2.0f))
  ASSERT(test_eq(v2[2], 10.0f))
  ASSERT(test_eq(v2[3], 1.0f))

  glm_mat4_identity(m1);
  GLM(translate_z)(m1, -5.0f);
  glm_mat4_mulv(m1, v2, v2);

  ASSERT(test_eq(v2[0], 1.0f))
  ASSERT(test_eq(v2[1], 2.0f))
  ASSERT(test_eq(v2[2], 5.0f))
  ASSERT(test_eq(v2[3], 1.0f))

  TEST_SUCCESS
}

TEST_IMPL(GLM_PREFIX, translate_make) {
  mat4 t1, t2, t3, t4, t5;
  mat4 m1, m2;
  vec4 v1 = {1.0f, 2.0f, 3.0f, 1.0f}, v2;

  glm_mat4_identity(m1);
  GLM(translate_make)(m1, (vec3){13.0f, 11.0f, 7.0f});
  glm_mat4_mulv(m1, v1, v2);

  ASSERT(test_eq(v2[0], 14.0f))
  ASSERT(test_eq(v2[1], 13.0f))
  ASSERT(test_eq(v2[2], 10.0f))
  ASSERT(test_eq(v2[3], 1.0f))

  glm_mat4_identity(m1);
  GLM(translate_make)(m1, (vec3){1.0f, -1.0f, -5.0f});
  glm_mat4_mulv(m1, v2, v2);

  ASSERT(test_eq(v2[0], 15.0f))
  ASSERT(test_eq(v2[1], 12.0f))
  ASSERT(test_eq(v2[2], 5.0f))
  ASSERT(test_eq(v2[3], 1.0f))

  TEST_SUCCESS
}

TEST_IMPL(GLM_PREFIX, scale_to) {
  TEST_SUCCESS
}

TEST_IMPL(GLM_PREFIX, scale_make) {
  TEST_SUCCESS
}

TEST_IMPL(GLM_PREFIX, scale) {
  TEST_SUCCESS
}

TEST_IMPL(GLM_PREFIX, scale_uni) {
  TEST_SUCCESS
}

TEST_IMPL(GLM_PREFIX, rotate_x) {
  TEST_SUCCESS
}

TEST_IMPL(GLM_PREFIX, rotate_y) {
  TEST_SUCCESS
}

TEST_IMPL(GLM_PREFIX, rotate_z) {
  TEST_SUCCESS
}

TEST_IMPL(GLM_PREFIX, rotate_make) {
  TEST_SUCCESS
}

TEST_IMPL(GLM_PREFIX, rotate) {
  TEST_SUCCESS
}

TEST_IMPL(GLM_PREFIX, rotate_at) {
  TEST_SUCCESS
}

TEST_IMPL(GLM_PREFIX, rotate_atm) {
  TEST_SUCCESS
}

TEST_IMPL(GLM_PREFIX, decompose_scalev) {
  TEST_SUCCESS
}

TEST_IMPL(GLM_PREFIX, uniscaled) {
  TEST_SUCCESS
}

TEST_IMPL(GLM_PREFIX, decompose_rs) {
  TEST_SUCCESS
}

TEST_IMPL(GLM_PREFIX, decompose) {
  TEST_SUCCESS
}
