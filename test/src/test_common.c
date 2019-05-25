/*
 * Copyright (c), Recep Aslantas.
 * MIT License (MIT), http://opensource.org/licenses/MIT
 */

#include "test_common.h"
#include <stdlib.h>
#include <math.h>

#define m 4
#define n 4

void
test_rand_mat4(mat4 dest) {
  glm_mat4_copy(GLM_MAT4_IDENTITY, dest);
  
  srand((unsigned int)time(NULL));

  /* random position */
  dest[3][0] = drand48();
  dest[3][1] = drand48();
  dest[3][2] = drand48();
  
  /* random rotatation around random axis with random angle */
  glm_rotate(dest, drand48(), (vec3){drand48(), drand48(), drand48()});
  
  /* random scale */
  /* glm_scale(dest, (vec3){drand48(), drand48(), drand48()}); */
}

void
test_rand_mat3(mat3 dest) {
  mat4 m4;

  srand((unsigned int)time(NULL));

  /* random rotatation around random axis with random angle */
  glm_rotate_make(m4, drand48(), (vec3){drand48(), drand48(), drand48()});
  glm_mat4_pick3(m4, dest);
}

void
test_rand_vec3(vec3 dest) {
  srand((unsigned int)time(NULL));

  dest[0] = drand48();
  dest[1] = drand48();
  dest[2] = drand48();
}

vec3s
test_rand_vec3s() {
  vec3s r;
  test_rand_vec3(r.raw);
  return r;
}

void
test_rand_vec4(vec4 dest) {
  srand((unsigned int)time(NULL));

  dest[0] = drand48();
  dest[1] = drand48();
  dest[2] = drand48();
  dest[3] = drand48();
}

vec4s
test_rand_vec4s() {
  vec4s r;
  test_rand_vec4(r.raw);
  return r;
}

float
test_rand(void) {
  srand((unsigned int)time(NULL));
  return drand48();
}

void
test_rand_quat(versor q) {
  srand((unsigned int)time(NULL));

  glm_quat(q, drand48(), drand48(), drand48(), drand48());
  glm_quat_normalize(q);
}

void
test_assert_mat4_eq(mat4 m1, mat4 m2) {
  int i, j, k;

  for (i = 0; i < m; i++) {
    for (j = 0; j < n; j++) {
      for (k = 0; k < m; k++)
        assert_true(fabsf(m1[i][j] - m2[i][j]) <= 0.0000009);
    }
  }
}

void
test_assert_mat4_eq2(mat4 m1, mat4 m2, float eps) {
  int i, j, k;
  
  for (i = 0; i < m; i++) {
    for (j = 0; j < n; j++) {
      for (k = 0; k < m; k++)
        assert_true(fabsf(m1[i][j] - m2[i][j]) <= eps);
    }
  }
}

void
test_assert_mat3_eq(mat3 m1, mat3 m2) {
  int i, j, k;

  for (i = 0; i < 3; i++) {
    for (j = 0; j < 3; j++) {
      for (k = 0; k < 3; k++)
        assert_true(fabsf(m1[i][j] - m2[i][j]) <= 0.0000009);
    }
  }
}

void
test_assert_eqf(float a, float b) {
  assert_true(fabsf(a - b) <= 0.000009); /* rounding errors */
}

void
test_assert_vec3_eq(vec3 v1, vec3 v2) {
  assert_true(fabsf(v1[0] - v2[0]) <= 0.000009); /* rounding errors */
  assert_true(fabsf(v1[1] - v2[1]) <= 0.000009);
  assert_true(fabsf(v1[2] - v2[2]) <= 0.000009);
}

void
test_assert_vec3s_eq(vec3s v1, vec3s v2) {
  test_assert_vec3_eq(v1.raw, v2.raw);
}

void
test_assert_vec4_eq(vec4 v1, vec4 v2) {
  assert_true(fabsf(v1[0] - v2[0]) <= 0.000009); /* rounding errors */
  assert_true(fabsf(v1[1] - v2[1]) <= 0.000009);
  assert_true(fabsf(v1[2] - v2[2]) <= 0.000009);
  assert_true(fabsf(v1[3] - v2[3]) <= 0.000009);
}

void
test_assert_vec4s_eq(vec4s v1, vec4s v2) {
  test_assert_vec4_eq(v1.raw, v2.raw);
}

void
test_assert_quat_eq_abs(versor v1, versor v2) {
  assert_true(fabsf(fabsf(v1[0]) - fabsf(v2[0])) <= 0.0009); /* rounding errors */
  assert_true(fabsf(fabsf(v1[1]) - fabsf(v2[1])) <= 0.0009);
  assert_true(fabsf(fabsf(v1[2]) - fabsf(v2[2])) <= 0.0009);
  assert_true(fabsf(fabsf(v1[3]) - fabsf(v2[3])) <= 0.0009);
}

void
test_assert_quat_eq(versor v1, versor v2) {
  assert_true(fabsf(v1[0] - v2[0]) <= 0.000009); /* rounding errors */
  assert_true(fabsf(v1[1] - v2[1]) <= 0.000009);
  assert_true(fabsf(v1[2] - v2[2]) <= 0.000009);
  assert_true(fabsf(v1[3] - v2[3]) <= 0.000009);
}

