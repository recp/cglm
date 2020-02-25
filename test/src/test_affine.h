/*
 * Copyright (c), Recep Aslantas.
 *
 * MIT License (MIT), http://opensource.org/licenses/MIT
 * Full license can be found in the LICENSE file
 */

#include "test_common.h"

TEST_IMPL(GLM_PREFIX, translate) {
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
  mat4 m1;
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
  mat4 m1, m2;
  vec4 v1 = {1.0f, 2.0f, 3.0f, 1.0f}, v2;

  glm_mat4_identity(m1);
  GLM(scale_to)(m1, (vec3){13.0f, 11.0f, 7.0f}, m2);
  glm_mat4_mulv(m2, v1, v2);

  ASSERT(test_eq(v2[0], 13.0f))
  ASSERT(test_eq(v2[1], 22.0f))
  ASSERT(test_eq(v2[2], 21.0f))
  ASSERT(test_eq(v2[3], 1.0f))

  glm_mat4_identity(m1);
  GLM(scale_to)(m1, (vec3){1.0f, -1.0f, -5.0f}, m2);
  glm_mat4_mulv(m2, v2, v2);

  ASSERT(test_eq(v2[0],  13.0f))
  ASSERT(test_eq(v2[1], -22.0f))
  ASSERT(test_eq(v2[2], -105.0f))
  ASSERT(test_eq(v2[3],  1.0f))

  TEST_SUCCESS
}

TEST_IMPL(GLM_PREFIX, scale_make) {
  mat4 m1;
  vec4 v1 = {1.0f, 2.0f, 3.0f, 1.0f}, v2;

  GLM(scale_make)(m1, (vec3){13.0f, 11.0f, 7.0f});
  glm_mat4_mulv(m1, v1, v2);

  ASSERT(test_eq(v2[0], 13.0f))
  ASSERT(test_eq(v2[1], 22.0f))
  ASSERT(test_eq(v2[2], 21.0f))
  ASSERT(test_eq(v2[3], 1.0f))

  GLM(scale_make)(m1, (vec3){1.0f, -1.0f, -5.0f});
  glm_mat4_mulv(m1, v2, v2);

  ASSERT(test_eq(v2[0],  13.0f))
  ASSERT(test_eq(v2[1], -22.0f))
  ASSERT(test_eq(v2[2], -105.0f))
  ASSERT(test_eq(v2[3],  1.0f))

  TEST_SUCCESS
}

TEST_IMPL(GLM_PREFIX, scale) {
  mat4 m1;
  vec4 v1 = {1.0f, 2.0f, 3.0f, 1.0f}, v2;

  glm_mat4_identity(m1);
  GLM(scale)(m1, (vec3){13.0f, 11.0f, 7.0f});
  glm_mat4_mulv(m1, v1, v2);

  ASSERT(test_eq(v2[0], 13.0f))
  ASSERT(test_eq(v2[1], 22.0f))
  ASSERT(test_eq(v2[2], 21.0f))
  ASSERT(test_eq(v2[3], 1.0f))

  glm_mat4_identity(m1);
  GLM(scale)(m1, (vec3){1.0f, -1.0f, -5.0f});
  glm_mat4_mulv(m1, v2, v2);

  ASSERT(test_eq(v2[0],  13.0f))
  ASSERT(test_eq(v2[1], -22.0f))
  ASSERT(test_eq(v2[2], -105.0f))
  ASSERT(test_eq(v2[3],  1.0f))

  TEST_SUCCESS
}

TEST_IMPL(GLM_PREFIX, scale_uni) {
  mat4 m1;
  vec4 v1 = {1.0f, 2.0f, 3.0f, 1.0f}, v2;

  glm_mat4_identity(m1);
  GLM(scale_uni)(m1, 13.0f);
  glm_mat4_mulv(m1, v1, v2);

  ASSERT(test_eq(v2[0], 13.0f))
  ASSERT(test_eq(v2[1], 26.0f))
  ASSERT(test_eq(v2[2], 39.0f))
  ASSERT(test_eq(v2[3], 1.0f))

  glm_mat4_identity(m1);
  GLM(scale_uni)(m1, -5.0f);
  glm_mat4_mulv(m1, v2, v2);

  ASSERT(test_eq(v2[0], -65.0f))
  ASSERT(test_eq(v2[1], -130.0f))
  ASSERT(test_eq(v2[2], -195.0f))
  ASSERT(test_eq(v2[3],  1.0f))

  TEST_SUCCESS
}

TEST_IMPL(GLM_PREFIX, rotate_x) {
  mat4   m1 = GLM_MAT4_IDENTITY_INIT;
  vec4   v1 = {0.0f, 1.0f, 0.0f, 1.0f}, v2 = {0.0f, 1.0f, 0.0f, 1.0f};

  GLM(rotate_x)(m1, GLM_PI_2f, m1);
  glm_mat4_mulv(m1, v1, v1);

  ASSERT(test_eq(v1[0], 0.0f))
  ASSERT(test_eq(v1[1], 0.0f))
  ASSERT(test_eq(v1[2], 1.0f))

  glm_vec3_copy(v2, v1);

  GLM(rotate_x)(m1, GLM_PI_2f, m1);
  glm_mat4_mulv(m1, v1, v1);

  ASSERT(test_eq(v1[0],  0.0f))
  ASSERT(test_eq(v1[1], -1.0f))
  ASSERT(test_eq(v1[2],  0.0f))

  glm_vec3_copy(v2, v1);

  GLM(rotate_x)(m1, GLM_PI_2f, m1);
  glm_mat4_mulv(m1, v1, v1);

  ASSERT(test_eq(v1[0],  0.0f))
  ASSERT(test_eq(v1[1],  0.0f))
  ASSERT(test_eq(v1[2], -1.0f))

  TEST_SUCCESS
}

TEST_IMPL(GLM_PREFIX, rotate_y) {
  mat4   m1 = GLM_MAT4_IDENTITY_INIT;
  vec4   v1 = {1.0f, 0.0f, 0.0f, 1.0f}, v2 = {1.0f, 0.0f, 0.0f, 1.0f};

  GLM(rotate_y)(m1, GLM_PI_2f, m1);
  glm_mat4_mulv(m1, v1, v1);

  ASSERT(test_eq(v1[0],  0.0f))
  ASSERT(test_eq(v1[1],  0.0f))
  ASSERT(test_eq(v1[2], -1.0f))

  glm_vec3_copy(v2, v1);

  GLM(rotate_y)(m1, GLM_PI_2f, m1);
  glm_mat4_mulv(m1, v1, v1);

  ASSERT(test_eq(v1[0], -1.0f))
  ASSERT(test_eq(v1[1],  0.0f))
  ASSERT(test_eq(v1[2],  0.0f))

  glm_vec3_copy(v2, v1);

  GLM(rotate_y)(m1, GLM_PI_2f, m1);
  glm_mat4_mulv(m1, v1, v1);

  ASSERT(test_eq(v1[0], 0.0f))
  ASSERT(test_eq(v1[1], 0.0f))
  ASSERT(test_eq(v1[2], 1.0f))

  TEST_SUCCESS
}

TEST_IMPL(GLM_PREFIX, rotate_z) {
  mat4   m1 = GLM_MAT4_IDENTITY_INIT;
  vec4   v1 = {0.0f, 1.0f, 0.0f, 1.0f}, v2 = {0.0f, 1.0f, 0.0f, 1.0f};

  GLM(rotate_z)(m1, GLM_PI_2f, m1);
  glm_mat4_mulv(m1, v1, v1);

  ASSERT(test_eq(v1[0], -1.0f))
  ASSERT(test_eq(v1[1],  0.0f))
  ASSERT(test_eq(v1[2],  0.0f))

  glm_vec3_copy(v2, v1);

  GLM(rotate_z)(m1, GLM_PI_2f, m1);
  glm_mat4_mulv(m1, v1, v1);

  ASSERT(test_eq(v1[0],  0.0f))
  ASSERT(test_eq(v1[1], -1.0f))
  ASSERT(test_eq(v1[2],  0.0f))

  glm_vec3_copy(v2, v1);

  GLM(rotate_z)(m1, GLM_PI_2f, m1);
  glm_mat4_mulv(m1, v1, v1);

  ASSERT(test_eq(v1[0], 1.0f))
  ASSERT(test_eq(v1[1], 0.0f))
  ASSERT(test_eq(v1[2], 0.0f))

  TEST_SUCCESS
}

TEST_IMPL(GLM_PREFIX, rotate_make) {
  mat4   m1 = GLM_MAT4_IDENTITY_INIT;
  vec4   v1 = {1.0f, 0.0f, 0.0f, 1.0f};

  /* rotate X around Y = -Z */
  GLM(rotate_make)(m1, GLM_PI_2f, GLM_YUP);
  glm_mat4_mulv(m1, v1, v1);

  ASSERT(test_eq(v1[0],  0.0f))
  ASSERT(test_eq(v1[1],  0.0f))
  ASSERT(test_eq(v1[2], -1.0f))

  /* rotate -Z around X = Y */
  GLM(rotate_make)(m1, GLM_PI_2f, GLM_XUP);
  glm_mat4_mulv(m1, v1, v1);

  ASSERT(test_eq(v1[0],  0.0f))
  ASSERT(test_eq(v1[1],  1.0f))
  ASSERT(test_eq(v1[2],  0.0f))

  /* rotate Y around X = +Z */
  GLM(rotate_make)(m1, GLM_PI_2f, GLM_XUP);
  glm_mat4_mulv(m1, v1, v1);

  ASSERT(test_eq(v1[0],  0.0f))
  ASSERT(test_eq(v1[1],  0.0f))
  ASSERT(test_eq(v1[2],  1.0f))

  TEST_SUCCESS
}

TEST_IMPL(GLM_PREFIX, rotate) {
  mat4 m1 = GLM_MAT4_IDENTITY_INIT, m2 = GLM_MAT4_IDENTITY_INIT;
  vec4 v1 = {1.0f, 0.0f, 0.0f, 1.0f};

  /* 360 deg */
  glm_rotate(m1, GLM_PI_2f, GLM_YUP);
  glm_rotate(m1, GLM_PI_2f, GLM_YUP);
  glm_rotate(m1, GLM_PI_2f, GLM_YUP);
  glm_rotate(m1, GLM_PI_2f, GLM_YUP);
  ASSERTIFY(test_assert_mat4_eq(m1, m2))

  /* rotate X around Y = -Z */
  GLM(rotate)(m1, GLM_PI_2f, GLM_YUP);
  glm_mat4_mulv(m1, v1, v1);

  ASSERT(test_eq(v1[0],  0.0f))
  ASSERT(test_eq(v1[1],  0.0f))
  ASSERT(test_eq(v1[2], -1.0f))

  glm_mat4_identity(m1);

  /* rotate -Z around X = Y */
  GLM(rotate)(m1, GLM_PI_2f, GLM_XUP);
  glm_mat4_mulv(m1, v1, v1);

  ASSERT(test_eq(v1[0],  0.0f))
  ASSERT(test_eq(v1[1],  1.0f))
  ASSERT(test_eq(v1[2],  0.0f))

  glm_mat4_identity(m1);

  /* rotate Y around X = +Z */
  GLM(rotate)(m1, GLM_PI_2f, GLM_XUP);
  glm_mat4_mulv(m1, v1, v1);

  ASSERT(test_eq(v1[0],  0.0f))
  ASSERT(test_eq(v1[1],  0.0f))
  ASSERT(test_eq(v1[2],  1.0f))

  TEST_SUCCESS
}

TEST_IMPL(GLM_PREFIX, rotate_at) {
  mat4 m1 = GLM_MAT4_IDENTITY_INIT;
  vec4 v1 = {1.0f, 0.0f, 0.0f, 1.0f};

  GLM(rotate_at)(m1, (vec3){0.5f, 0.0f, 0.0f}, GLM_PI_2f, GLM_YUP);
  glm_mat4_mulv(m1, v1, v1);

  ASSERT(test_eq(v1[0],  0.5f))
  ASSERT(test_eq(v1[1],  0.0f))
  ASSERT(test_eq(v1[2], -0.5f))

  glm_mat4_identity(m1);

  GLM(rotate_at)(m1, GLM_VEC3_ZERO, GLM_PI_2f, GLM_ZUP);
  glm_mat4_mulv(m1, v1, v1);

  ASSERT(test_eq(v1[0],  0.0f))
  ASSERT(test_eq(v1[1],  0.5f))
  ASSERT(test_eq(v1[2], -0.5f))

  glm_mat4_identity(m1);

  v1[0] = 1.0f;
  v1[1] = 1.0f;
  v1[2] = 1.0f;

  GLM(rotate_at)(m1, GLM_VEC3_ZERO, GLM_PI_2f, GLM_XUP);
  glm_mat4_mulv(m1, v1, v1);

  ASSERT(test_eq(v1[0],  1.0f))
  ASSERT(test_eq(v1[1], -1.0f))
  ASSERT(test_eq(v1[2],  1.0f))

  TEST_SUCCESS
}

TEST_IMPL(GLM_PREFIX, rotate_atm) {
  mat4 m1 = GLM_MAT4_IDENTITY_INIT;
  vec4 v1 = {1.0f, 0.0f, 0.0f, 1.0f};

  GLM(rotate_atm)(m1, (vec3){0.5f, 0.0f, 0.0f}, GLM_PI_2f, GLM_YUP);
  glm_mat4_mulv(m1, v1, v1);

  ASSERT(test_eq(v1[0],  0.5f))
  ASSERT(test_eq(v1[1],  0.0f))
  ASSERT(test_eq(v1[2], -0.5f))

  GLM(rotate_atm)(m1, GLM_VEC3_ZERO, GLM_PI_2f, GLM_ZUP);
  glm_mat4_mulv(m1, v1, v1);

  ASSERT(test_eq(v1[0],  0.0f))
  ASSERT(test_eq(v1[1],  0.5f))
  ASSERT(test_eq(v1[2], -0.5f))

  v1[0] = 1.0f;
  v1[1] = 1.0f;
  v1[2] = 1.0f;

  GLM(rotate_atm)(m1, GLM_VEC3_ZERO, GLM_PI_2f, GLM_XUP);
  glm_mat4_mulv(m1, v1, v1);

  ASSERT(test_eq(v1[0],  1.0f))
  ASSERT(test_eq(v1[1], -1.0f))
  ASSERT(test_eq(v1[2],  1.0f))

  TEST_SUCCESS
}

TEST_IMPL(GLM_PREFIX, decompose_scalev) {
  mat4 m1;
  vec3 s1;

  GLM(scale_make)(m1, (vec3){7.0f, 8.0f, 9.0f});
  GLM(decompose_scalev)(m1, s1);

  ASSERT(test_eq(s1[0], 7.0f))
  ASSERT(test_eq(s1[1], 8.0f))
  ASSERT(test_eq(s1[2], 9.0f))

  GLM(scale)(m1, (vec3){7.0f, 8.0f, 9.0f});
  GLM(decompose_scalev)(m1, s1);

  ASSERT(test_eq(s1[0], 49.0f))
  ASSERT(test_eq(s1[1], 64.0f))
  ASSERT(test_eq(s1[2], 81.0f))

  glm_rotate(m1, GLM_PI_4f, (vec3){23.0f, 45.0f, 66.0f});
  ASSERT(test_eq(s1[0], 49.0f))
  ASSERT(test_eq(s1[1], 64.0f))
  ASSERT(test_eq(s1[2], 81.0f))

  glm_translate(m1, (vec3){4.0f, 5.0f, 6.0f});
  ASSERT(test_eq(s1[0], 49.0f))
  ASSERT(test_eq(s1[1], 64.0f))
  ASSERT(test_eq(s1[2], 81.0f))

  TEST_SUCCESS
}

TEST_IMPL(GLM_PREFIX, uniscaled) {
  mat4 m1;

  GLM(scale_make)(m1, (vec3){7.0f, 8.0f, 9.0f});
  ASSERT(!GLM(uniscaled)(m1))

  GLM(scale_make)(m1, (vec3){7.0f, 7.0f, 7.0f});
  ASSERT(GLM(uniscaled)(m1))

  glm_rotate(m1, GLM_PI_4f, (vec3){23.0f, 45.0f, 66.0f});
  ASSERT(GLM(uniscaled)(m1))

  glm_translate(m1, (vec3){4.0f, 5.0f, 6.0f});
  ASSERT(GLM(uniscaled)(m1))

  TEST_SUCCESS
}

TEST_IMPL(GLM_PREFIX, decompose_rs) {
  mat4 m1, m2, r;
  vec3 s1;

  GLM(scale_make)(m1, (vec3){7.0f, 8.0f, 9.0f});
  GLM(decompose_rs)(m1, r, s1);

  ASSERT(test_eq(s1[0], 7.0f))
  ASSERT(test_eq(s1[1], 8.0f))
  ASSERT(test_eq(s1[2], 9.0f))
  ASSERTIFY(test_assert_mat4_eq_identity(r));

  GLM(scale)(m1, (vec3){7.0f, 8.0f, 9.0f});
  GLM(decompose_rs)(m1, r, s1);

  ASSERT(test_eq(s1[0], 49.0f))
  ASSERT(test_eq(s1[1], 64.0f))
  ASSERT(test_eq(s1[2], 81.0f))
  ASSERTIFY(test_assert_mat4_eq_identity(r));

  glm_rotate(m1, GLM_PI_4f, (vec3){23.0f, 45.0f, 66.0f});
  ASSERT(test_eq(s1[0], 49.0f))
  ASSERT(test_eq(s1[1], 64.0f))
  ASSERT(test_eq(s1[2], 81.0f))
  GLM(decompose_rs)(m1, r, s1);

  glm_mat4_identity(m2);
  glm_mat4_mul(m2, r, m2);
  glm_scale(m2, s1);

  ASSERTIFY(test_assert_mat4_eq2(m1, m2, 0.00001f));

  TEST_SUCCESS
}

TEST_IMPL(GLM_PREFIX, decompose) {
  mat4 m1, m2, r;
  vec4 t;
  vec3 s;

  GLM(scale_make)(m1, (vec3){7.0f, 8.0f, 9.0f});
  GLM(decompose)(m1, t, r, s);

  ASSERT(test_eq(s[0], 7.0f))
  ASSERT(test_eq(s[1], 8.0f))
  ASSERT(test_eq(s[2], 9.0f))
  ASSERTIFY(test_assert_mat4_eq_identity(r));

  GLM(scale)(m1, (vec3){7.0f, 8.0f, 9.0f});
  GLM(decompose)(m1, t, r, s);

  ASSERT(test_eq(s[0], 49.0f))
  ASSERT(test_eq(s[1], 64.0f))
  ASSERT(test_eq(s[2], 81.0f))
  ASSERTIFY(test_assert_mat4_eq_identity(r));

  glm_rotate(m1, GLM_PI_4f, (vec3){23.0f, 45.0f, 66.0f});
  ASSERT(test_eq(s[0], 49.0f))
  ASSERT(test_eq(s[1], 64.0f))
  ASSERT(test_eq(s[2], 81.0f))
  GLM(decompose)(m1, t, r, s);

  glm_mat4_identity(m2);
  glm_mat4_mul(m2, r, m2);
  glm_scale(m2, s);

  ASSERTIFY(test_assert_mat4_eq2(m1, m2, 0.00001f));

  glm_mat4_identity(m1);
  glm_translate(m1, (vec3){56.0f, 13.0f, 90.0f});
  glm_rotate(m1, GLM_PI_4f, (vec3){23.0f, 45.0f, 66.0f});
  glm_scale(m1, (vec3){12.0f, 34.0f, 23.0f});

  GLM(decompose)(m1, t, r, s);

  ASSERT(test_eq(t[0], 56.0f))
  ASSERT(test_eq(t[1], 13.0f))
  ASSERT(test_eq(t[2], 90.0f))

  ASSERT(test_eq(s[0], 12.0f))
  ASSERT(test_eq(s[1], 34.0f))
  ASSERT(test_eq(s[2], 23.0f))

  glm_mat4_identity(m2);
  glm_translate(m2, t);
  glm_mat4_mul(m2, r, m2);
  glm_scale(m2, s);
  ASSERTIFY(test_assert_mat4_eq2(m1, m2, 0.00001f));

  TEST_SUCCESS
}
