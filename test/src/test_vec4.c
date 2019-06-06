/*
 * Copyright (c), Recep Aslantas.
 *
 * MIT License (MIT), http://opensource.org/licenses/MIT
 * Full license can be found in the LICENSE file
 */

#include "test_common.h"

CGLM_INLINE
float
test_vec4_dot(vec4 a, vec4 b) {
  return a[0] * b[0] + a[1] * b[1] + a[2] * b[2] + a[3] * b[3];
}

CGLM_INLINE
void
test_vec4_normalize_to(vec4 vec, vec4 dest) {
  float norm;

  norm = glm_vec4_norm(vec);

  if (norm == 0.0f) {
    dest[0] = dest[1] = dest[2] = dest[3] = 0.0f;
    return;
  }

  glm_vec4_scale(vec, 1.0f / norm, dest);
}

float
test_vec4_norm2(vec4 vec) {
  return test_vec4_dot(vec, vec);
}

float
test_vec4_norm(vec4 vec) {
  return sqrtf(test_vec4_dot(vec, vec));
}

void
test_vec4_maxv(vec4 v1, vec4 v2, vec4 dest) {
  dest[0] = glm_max(v1[0], v2[0]);
  dest[1] = glm_max(v1[1], v2[1]);
  dest[2] = glm_max(v1[2], v2[2]);
  dest[3] = glm_max(v1[3], v2[3]);
}

void
test_vec4_minv(vec4 v1, vec4 v2, vec4 dest) {
  dest[0] = glm_min(v1[0], v2[0]);
  dest[1] = glm_min(v1[1], v2[1]);
  dest[2] = glm_min(v1[2], v2[2]);
  dest[3] = glm_min(v1[3], v2[3]);
}

void
test_vec4_clamp(vec4 v, float minVal, float maxVal) {
  v[0] = glm_clamp(v[0], minVal, maxVal);
  v[1] = glm_clamp(v[1], minVal, maxVal);
  v[2] = glm_clamp(v[2], minVal, maxVal);
  v[3] = glm_clamp(v[3], minVal, maxVal);
}

void
test_vec4(void **state) {
  vec4  v, v1, v2, v3, v4;
  vec4s vs1, vs2, vs3, vs4;
  int   i;
  float d1, d2;

  for (i = 0; i < 1000; i++) {
    /* 1. test SSE/SIMD dot product */
    test_rand_vec4(v);
    d1 = glm_vec4_dot(v, v);
    d2 = test_vec4_dot(v, v);

    assert_true(fabsf(d1 - d2) <= 0.000009);

    /* 2. test SIMD normalize */
    test_vec4_normalize_to(v, v1);
    glm_vec4_normalize_to(v, v2);
    glm_vec4_normalize(v);

    /* all must be same */
    test_assert_vec4_eq(v1, v2);
    test_assert_vec4_eq(v, v2);

    /* 3. test SIMD norm */
    test_rand_vec4(v);
    test_assert_eqf(test_vec4_norm(v), glm_vec4_norm(v));

    /* 3. test SIMD norm2 */
    test_rand_vec4(v);
    test_assert_eqf(test_vec4_norm2(v), glm_vec4_norm2(v));

    /* 4. test SSE/SIMD distance */
    test_rand_vec4(v1);
    test_rand_vec4(v2);
    d1 = glm_vec4_distance(v1, v2);
    d2 = sqrtf(powf(v1[0]-v2[0], 2.0f) + pow(v1[1]-v2[1], 2.0f) + pow(v1[2]-v2[2], 2.0f) + pow(v1[3]-v2[3], 2.0f));
    assert_true(fabsf(d1 - d2) <= 0.000009);
  }

  /* test zero */
  glm_vec4_zero(v);
  test_assert_vec4_eq(GLM_VEC4_ZERO, v);

  /* test one */
  glm_vec4_one(v);
  test_assert_vec4_eq(GLM_VEC4_ONE, v);

  /* adds, subs, div, divs, mul */
  glm_vec4_add(v, GLM_VEC4_ONE, v);
  assert_true(glmc_vec4_eq_eps(v, 2));

  glm_vec4_adds(v, 10, v);
  assert_true(glmc_vec4_eq_eps(v, 12));

  glm_vec4_sub(v, GLM_VEC4_ONE, v);
  assert_true(glmc_vec4_eq_eps(v, 11));

  glm_vec4_subs(v, 1, v);
  assert_true(glmc_vec4_eq_eps(v, 10));

  glm_vec4_broadcast(2, v1);
  glm_vec4_div(v, v1, v);
  assert_true(glmc_vec4_eq_eps(v, 5));

  glm_vec4_divs(v, 0.5, v);
  assert_true(glmc_vec4_eq_eps(v, 10));

  glm_vec4_mul(v, v1, v);
  assert_true(glmc_vec4_eq_eps(v, 20));

  glm_vec4_scale(v, 0.5, v);
  assert_true(glmc_vec4_eq_eps(v, 10));

  glm_vec4_normalize_to(v, v1);
  glm_vec4_scale(v1, 0.8, v1);
  glm_vec4_scale_as(v, 0.8, v);
  test_assert_vec4_eq(v1, v);

  /* addadd, subadd, muladd */
  glm_vec4_one(v);

  glm_vec4_addadd(GLM_VEC4_ONE, GLM_VEC4_ONE, v);
  assert_true(glmc_vec4_eq_eps(v, 3));

  glm_vec4_subadd(GLM_VEC4_ONE, GLM_VEC4_ZERO, v);
  assert_true(glmc_vec4_eq_eps(v, 4));

  glm_vec4_broadcast(2, v1);
  glm_vec4_broadcast(3, v2);
  glm_vec4_muladd(v1, v2, v);
  assert_true(glmc_vec4_eq_eps(v, 10));

  /* min, max */
  test_rand_vec4(v1);
  test_rand_vec4(v2);

  glm_vec4_maxv(v1, v2, v3);
  test_vec4_maxv(v1, v2, v4);
  test_assert_vec4_eq(v3, v4);

  glm_vec4_minv(v1, v2, v3);
  test_vec4_minv(v1, v2, v4);
  test_assert_vec4_eq(v3, v4);

  glm_vec4_print(v3, stderr);
  glm_vec4_print(v4, stderr);

  /* clamp */
  glm_vec4_clamp(v3, 0.1, 0.8);
  test_vec4_clamp(v4, 0.1, 0.8);
  test_assert_vec4_eq(v3, v4);

  glm_vec4_print(v3, stderr);
  glm_vec4_print(v4, stderr);

  assert_true(v3[0] >= 0.0999 && v3[0] <= 0.80001); /* rounding erros */
  assert_true(v3[1] >= 0.0999 && v3[1] <= 0.80001);
  assert_true(v3[2] >= 0.0999 && v3[2] <= 0.80001);
  assert_true(v3[3] >= 0.0999 && v3[3] <= 0.80001);

  /* swizzle */

  /* ZYX */
  v1[0] = 1;
  v1[1] = 2;
  v1[2] = 3;
  v1[3] = 4;

  glm_vec4_swizzle(v1, GLM_WZYX, v1);
  test_assert_vec4_eq(v1, (vec4){4, 3, 2, 1});

  glm_vec4_swizzle(v1, GLM_XXXX, v1);
  test_assert_vec4_eq(v1, (vec4){4, 4, 4, 4});

  v1[0] = 1;
  v1[1] = 2;
  v1[2] = 3;
  v1[3] = 4;

  glm_vec4_swizzle(v1, GLM_YYYY, v1);
  test_assert_vec4_eq(v1, (vec4){2, 2, 2, 2});

  v1[0] = 1;
  v1[1] = 2;
  v1[2] = 3;
  v1[3] = 4;

  glm_vec4_swizzle(v1, GLM_ZZZZ, v1);
  test_assert_vec4_eq(v1, (vec4){3, 3, 3, 3});

  v1[0] = 1;
  v1[1] = 2;
  v1[2] = 3;
  v1[3] = 4;

  glm_vec4_swizzle(v1, GLM_WWWW, v1);
  test_assert_vec4_eq(v1, (vec4){4, 4, 4, 4});

  /* structs */
  vs1 = test_rand_vec4s();
  vs2 = test_rand_vec4s();

  vs3 = glms_vec4_add(vs1, vs2);
  vs4 = glms_vec4_maxv(vs1, vs3);
  test_assert_vec4s_eq(vs3, vs4);
}
