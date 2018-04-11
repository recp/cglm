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

void
test_vec4(void **state) {
  vec4  v;
  int   i;
  float d1, d2;

  /* test SSE/SIMD dot product */
  for (i = 0; i < 100; i++) {
    test_rand_vec4(v);
    d1 = glm_vec4_dot(v, v);
    d2 = test_vec4_dot(v, v);

    assert_true(fabsf(d1 - d2) <= 0.000009);
  }
}
