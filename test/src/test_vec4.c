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
test_vec4(void **state) {
  vec4  v, v1, v2;
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
  }

  /* test zero */
  glm_vec4_zero(v);
  test_assert_vec4_eq(GLM_VEC4_ZERO, v);

  /* test one */
  glm_vec4_one(v);
  test_assert_vec4_eq(GLM_VEC4_ONE, v);
}
