/*
 * Copyright (c), Recep Aslantas.
 *
 * MIT License (MIT), http://opensource.org/licenses/MIT
 * Full license can be found in the LICENSE file
 */

#include "test_common.h"

TEST_IMPL(mat3s_identity_init) {
  mat3s mat3_identity   = GLMS_MAT3_IDENTITY_INIT;
  mat3  mat3_identity_a =  GLM_MAT3_IDENTITY_INIT;
  test_assert_mat3_eq(mat3_identity.raw, mat3_identity_a);
  TEST_SUCCESS
}

TEST_IMPL(mat3s_zero_init) {
  mat3s mat3_zero   = GLMS_MAT3_ZERO_INIT;
  mat3  mat3_zero_a =  GLM_MAT3_ZERO_INIT;
  test_assert_mat3_eq(mat3_zero.raw, mat3_zero_a);
  TEST_SUCCESS
}

TEST_IMPL(mat4s_identity_init) {
  mat4s mat4_identity   = GLMS_MAT4_IDENTITY_INIT;
  mat4  mat4_identity_a =  GLM_MAT4_IDENTITY_INIT;
  test_assert_mat4_eq(mat4_identity.raw, mat4_identity_a);
  TEST_SUCCESS
}

TEST_IMPL(mat4s_zero_init) {
  mat4s mat4_zero   = GLMS_MAT4_ZERO_INIT;
  mat4  mat4_zero_a =  GLM_MAT4_ZERO_INIT;
  test_assert_mat4_eq(mat4_zero.raw, mat4_zero_a);
  TEST_SUCCESS
}

TEST_IMPL(quats_zero_init) {
  versors quat_zero   = GLMS_QUAT_IDENTITY_INIT;
  versor  quat_zero_a =  GLM_QUAT_IDENTITY_INIT;
  test_assert_quat_eq(quat_zero.raw, quat_zero_a);
  TEST_SUCCESS
}

TEST_IMPL(vec3s_one_init) {
  vec3s vec3_one   = GLMS_VEC3_ONE_INIT;
  vec3  vec3_one_a =  GLM_VEC3_ONE_INIT;
  test_assert_vec3_eq(vec3_one.raw, vec3_one_a);
  TEST_SUCCESS
}

TEST_IMPL(vec3s_zero_init) {
  vec3s vec3_zero   = GLMS_VEC3_ZERO_INIT;
  vec3  vec3_zero_a =  GLM_VEC3_ZERO_INIT;
  test_assert_vec3_eq(vec3_zero.raw, vec3_zero_a);
  TEST_SUCCESS
}

TEST_IMPL(vec4s_black_init) {
  vec4s vec4_black   = GLMS_VEC4_BLACK_INIT;
  vec4  vec4_black_a =  GLM_VEC4_BLACK_INIT;
  test_assert_vec4_eq(vec4_black.raw, vec4_black_a);
  TEST_SUCCESS
}

TEST_IMPL(vec4s_one_init) {
  vec4s vec4_one   = GLMS_VEC4_ONE_INIT;
  vec4  vec4_one_a =  GLM_VEC4_ONE_INIT;
  test_assert_vec4_eq(vec4_one.raw, vec4_one_a);
  TEST_SUCCESS
}

TEST_IMPL(vec4s_zero_init) {
  vec4s vec4_zero   = GLMS_VEC4_ZERO_INIT;
  vec4  vec4_zero_a =  GLM_VEC4_ZERO_INIT;
  test_assert_vec4_eq(vec4_zero.raw, vec4_zero_a);
  TEST_SUCCESS
}
