/*
 * Copyright (c), Recep Aslantas.
 *
 * MIT License (MIT), http://opensource.org/licenses/MIT
 * Full license can be found in the LICENSE file
 */

#include "test_common.h"

TEST_IMPL(GLM_PREFIX, translate2d) {
  mat3 m1;
  vec3 v1 = {2.0f, 3.0f, 1.0f}, v2;

  glm_mat3_identity(m1);
  GLM(translate2d)(m1, (vec2){13.0f, 11.0f});
  glm_mat3_mulv(m1, v1, v2);

  ASSERT(test_eq(v2[0], 15.0f))
  ASSERT(test_eq(v2[1], 14.0f))
  ASSERT(test_eq(v2[2], 1.0f))

  glm_mat3_identity(m1);
  GLM(translate2d)(m1, (vec2){1.0f, -1.0f});
  glm_mat3_mulv(m1, v2, v2);

  ASSERT(test_eq(v2[0], 16.0f))
  ASSERT(test_eq(v2[1], 13.0f))
  ASSERT(test_eq(v2[2], 1.0f))

  TEST_SUCCESS
}

TEST_IMPL(GLM_PREFIX, translate2d_to) {
  mat3 m1, m2;
  vec3 v1 = {2.0f, 3.0f, 1.0f}, v2;

  glm_mat3_identity(m1);
  GLM(translate2d_to)(m1, (vec2){13.0f, 11.0f}, m2);
  glm_mat3_mulv(m2, v1, v2);

  ASSERT(test_eq(v2[0], 15.0f))
  ASSERT(test_eq(v2[1], 14.0f))
  ASSERT(test_eq(v2[2], 1.0f))

  glm_mat3_identity(m1);
  GLM(translate2d_to)(m1, (vec2){1.0f, -1.0f}, m2);
  glm_mat3_mulv(m2, v2, v2);

  ASSERT(test_eq(v2[0], 16.0f))
  ASSERT(test_eq(v2[1], 13.0f))
  ASSERT(test_eq(v2[2], 1.0f))

  TEST_SUCCESS
}

TEST_IMPL(GLM_PREFIX, translate2d_x) {
  mat3 m1;
  vec3 v1 = {2.0f, 3.0f, 1.0f}, v2;

  glm_mat3_identity(m1);
  GLM(translate2d_x)(m1, 13.0f);
  glm_mat3_mulv(m1, v1, v2);

  ASSERT(test_eq(v2[0], 15.0f))
  ASSERT(test_eq(v2[1], 3.0f))
  ASSERT(test_eq(v2[2], 1.0f))

  glm_mat3_identity(m1);
  GLM(translate2d_x)(m1, -1.0f);
  glm_mat3_mulv(m1, v2, v2);

  ASSERT(test_eq(v2[0], 14.0f))
  ASSERT(test_eq(v2[1], 3.0f))
  ASSERT(test_eq(v2[2], 1.0f))

  TEST_SUCCESS
}

TEST_IMPL(GLM_PREFIX, translate2d_y) {
  mat3 m1;
  vec3 v1 = {2.0f, 3.0f, 1.0f}, v2;

  glm_mat3_identity(m1);
  GLM(translate2d_y)(m1, 11.0f);
  glm_mat3_mulv(m1, v1, v2);
  

  ASSERT(test_eq(v2[0], 2.0f))
  ASSERT(test_eq(v2[1], 14.0f))
  ASSERT(test_eq(v2[2], 1.0f))

  glm_mat3_identity(m1);
  GLM(translate2d_y)(m1, -1.0f);
  glm_mat3_mulv(m1, v2, v2);

  ASSERT(test_eq(v2[0], 2.0f))
  ASSERT(test_eq(v2[1], 13.0f))
  ASSERT(test_eq(v2[2], 1.0f))
  
  TEST_SUCCESS
}

TEST_IMPL(GLM_PREFIX, translate2d_make) {
  mat3 m1;
  vec3 v1 = {2.0f, 3.0f, 1.0f}, v2;

  glm_mat3_identity(m1);
  GLM(translate2d_make)(m1, (vec2){13.0f, 11.0f});
  glm_mat3_mulv(m1, v1, v2);

  ASSERT(test_eq(v2[0], 15.0f))
  ASSERT(test_eq(v2[1], 14.0f))
  ASSERT(test_eq(v2[2], 1.0f))

  glm_mat3_identity(m1);
  GLM(translate2d_make)(m1, (vec2){-1.0f, -5.0f});
  glm_mat3_mulv(m1, v2, v2);

  ASSERT(test_eq(v2[0], 14.0f))
  ASSERT(test_eq(v2[1], 9.0f))
  ASSERT(test_eq(v2[2], 1.0f))

  TEST_SUCCESS
}

TEST_IMPL(GLM_PREFIX, scale2d_to) {
  mat3 m1, m2;
  vec3 v1 = {2.0f, 3.0f, 1.0f}, v2;

  glm_mat3_identity(m1);
  GLM(scale2d_to)(m1, (vec2){13.0f, 11.0f}, m2);
  glm_mat3_mulv(m2, v1, v2);

  ASSERT(test_eq(v2[0], 26.0f))
  ASSERT(test_eq(v2[1], 33.0f))
  ASSERT(test_eq(v2[2], 1.0f))

  glm_mat3_identity(m1);
  GLM(scale2d_to)(m1, (vec2){-1.0f, -5.0f}, m2);
  glm_mat3_mulv(m2, v2, v2);

  ASSERT(test_eq(v2[0], -26.0f))
  ASSERT(test_eq(v2[1], -165.0f))
  ASSERT(test_eq(v2[2],  1.0f))

  TEST_SUCCESS
}

TEST_IMPL(GLM_PREFIX, scale2d_make) {
  mat3 m1;
  vec3 v1 = {2.0f, 3.0f, 1.0f}, v2;

  GLM(scale2d_make)(m1, (vec2){13.0f, 11.0f});
  glm_mat3_mulv(m1, v1, v2);

  ASSERT(test_eq(v2[0], 26.0f))
  ASSERT(test_eq(v2[1], 33.0f))
  ASSERT(test_eq(v2[2], 1.0f))

  GLM(scale2d_make)(m1, (vec3){-1.0f, -5.0f});
  glm_mat3_mulv(m1, v2, v2);

  ASSERT(test_eq(v2[0], -26.0f))
  ASSERT(test_eq(v2[1], -165.0f))
  ASSERT(test_eq(v2[2],  1.0f))

  TEST_SUCCESS
}

TEST_IMPL(GLM_PREFIX, scale2d) {
  mat3 m1;
  vec3 v1 = {2.0f, 3.0f, 1.0f}, v2;

  glm_mat3_identity(m1);
  GLM(scale2d)(m1, (vec2){13.0f, 11.0f});
  glm_mat3_mulv(m1, v1, v2);

  ASSERT(test_eq(v2[0], 26.0f))
  ASSERT(test_eq(v2[1], 33.0f))
  ASSERT(test_eq(v2[2], 1.0f))

  glm_mat3_identity(m1);
  GLM(scale2d)(m1, (vec2){-1.0f, -5.0f});
  glm_mat3_mulv(m1, v2, v2);

  ASSERT(test_eq(v2[0], -26.0f))
  ASSERT(test_eq(v2[1], -165.0f))
  ASSERT(test_eq(v2[2],  1.0f))

  TEST_SUCCESS
}

TEST_IMPL(GLM_PREFIX, scale2d_uni) {
  mat3 m1;
  vec3 v1 = {2.0f, 3.0f, 1.0f}, v2;

  glm_mat3_identity(m1);
  GLM(scale2d_uni)(m1, 13.0f);
  glm_mat3_mulv(m1, v1, v2);

  ASSERT(test_eq(v2[0], 26.0f))
  ASSERT(test_eq(v2[1], 39.0f))
  ASSERT(test_eq(v2[2], 1.0f))

  glm_mat3_identity(m1);
  GLM(scale2d_uni)(m1, -5.0f);
  glm_mat3_mulv(m1, v2, v2);

  ASSERT(test_eq(v2[0], -130.0f))
  ASSERT(test_eq(v2[1], -195.0f))
  ASSERT(test_eq(v2[2],  1.0f))

  TEST_SUCCESS
}

TEST_IMPL(GLM_PREFIX, rotate2d_make) {
  mat3 m1 = GLM_MAT3_IDENTITY_INIT;
  vec3 v1 = {0.0f, 1.0f, 1.0f}, v2 = {0.0f, 1.0f, 1.0f};

  GLM(rotate2d_make)(m1, GLM_PI_2f);
  glm_mat3_mulv(m1, v1, v1);

  ASSERT(test_eq(v1[0], -1.0f))
  ASSERT(test_eq(v1[1],  0.0f))
  ASSERT(test_eq(v1[2],  1.0f))
  
  glm_vec3_copy(v2, v1);

  GLM(rotate2d_make)(m1, -GLM_PI_2f);
  glm_mat3_mulv(m1, v1, v1);

  ASSERT(test_eq(v1[0],  1.0f))
  ASSERT(test_eq(v1[1],  0.0f))
  ASSERT(test_eq(v1[2],  1.0f))

  glm_vec3_copy(v2, v1);

  GLM(rotate2d_make)(m1, GLM_PIf);
  glm_mat3_mulv(m1, v1, v1);

  ASSERT(test_eq(v1[0],  0.0f))
  ASSERT(test_eq(v1[1], -1.0f))
  ASSERT(test_eq(v1[2],  1.0f))

  TEST_SUCCESS
}

TEST_IMPL(GLM_PREFIX, rotate2d) {
  mat3 m1 = GLM_MAT3_IDENTITY_INIT;
  vec3 v1 = {0.0f, 1.0f, 1.0f}, v2 = {0.0f, 1.0f, 1.0f};

  GLM(rotate2d)(m1, GLM_PI_2f);
  glm_mat3_mulv(m1, v1, v1);

  ASSERT(test_eq(v1[0], -1.0f))
  ASSERT(test_eq(v1[1],  0.0f))
  ASSERT(test_eq(v1[2],  1.0f))
  
  glm_vec3_copy(v2, v1);

  GLM(rotate2d)(m1, GLM_PI_2f);
  glm_mat3_mulv(m1, v1, v1);

  ASSERT(test_eq(v1[0],  0.0f))
  ASSERT(test_eq(v1[1], -1.0f))
  ASSERT(test_eq(v1[2],  1.0f))

  glm_vec3_copy(v2, v1);

  GLM(rotate2d)(m1, GLM_PI_2f);
  glm_mat3_mulv(m1, v1, v1);

  ASSERT(test_eq(v1[0], 1.0f))
  ASSERT(test_eq(v1[1], 0.0f))
  ASSERT(test_eq(v1[2], 1.0f))

  TEST_SUCCESS
}

TEST_IMPL(GLM_PREFIX, rotate2d_to) {
  mat3 m1 = GLM_MAT3_IDENTITY_INIT, m2;
  vec3 v1 = {0.0f, 1.0f, 1.0f}, v2 = {0.0f, 1.0f, 1.0f};

  GLM(rotate2d_to)(m1, GLM_PI_2f, m1);
  glm_mat3_mulv(m1, v1, v1);

  ASSERT(test_eq(v1[0], -1.0f))
  ASSERT(test_eq(v1[1],  0.0f))
  ASSERT(test_eq(v1[2],  1.0f))
  
  glm_vec3_copy(v2, v1);

  GLM(rotate2d_to)(m1, GLM_PI_2f, m2);
  glm_mat3_mulv(m2, v1, v1);

  ASSERT(test_eq(v1[0],  0.0f))
  ASSERT(test_eq(v1[1], -1.0f))
  ASSERT(test_eq(v1[2],  1.0f))

  glm_vec3_copy(v2, v1);

  GLM(rotate2d_to)(m2, GLM_PI_2f, m1);
  glm_mat3_mulv(m1, v1, v1);

  ASSERT(test_eq(v1[0], 1.0f))
  ASSERT(test_eq(v1[1], 0.0f))
  ASSERT(test_eq(v1[2], 1.0f))

  TEST_SUCCESS
}
