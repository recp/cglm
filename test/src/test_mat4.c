/*
 * Copyright (c), Recep Aslantas.
 *
 * MIT License (MIT), http://opensource.org/licenses/MIT
 * Full license can be found in the LICENSE file
 */

#include "test_common.h"

#define m 4
#define n 4

void
test_mat4(void **state) {
  mat4  m1 = GLM_MAT4_IDENTITY_INIT;
  mat4  m2 = GLM_MAT4_IDENTITY_INIT;
  mat4  m3;
  mat4  m4 = GLM_MAT4_ZERO_INIT;
  int   i, j, k;

  /* test identity matrix multiplication */
  glm_mat4_mul(m1, m2, m3);
  for (i = 0; i < m; i++) {
    for (j = 0; j < n; j++) {
      if (i == j)
        assert_true(m3[i][j] == 1.0f);
      else
        assert_true(m3[i][j] == 0.0f);
    }
  }

  /* test random matrices */
  /* random matrices */
  test_rand_mat4(m1);
  test_rand_mat4(m2);

  glm_mat4_mul(m1, m2, m3);
  for (i = 0; i < m; i++) {
    for (j = 0; j < n; j++) {
      for (k = 0; k < m; k++)
        /* column-major */
        m4[i][j] += m1[k][j] * m2[i][k];
    }
  }

  test_assert_mat4_eq(m3, m4);

  /* test pre compiled */
  glmc_mat4_mul(m1, m2, m3);
  test_assert_mat4_eq(m3, m4);
}
