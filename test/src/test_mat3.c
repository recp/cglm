/*
 * Copyright (c), Recep Aslantas.
 *
 * MIT License (MIT), http://opensource.org/licenses/MIT
 * Full license can be found in the LICENSE file
 */

#include "test_common.h"

#define m 3
#define n 3

void
test_mat3(void **state) {
  mat3  m1 = GLM_MAT3_IDENTITY_INIT;
  mat3  m2 = GLM_MAT3_IDENTITY_INIT;
  mat3  m3;
  mat3  m4 = GLM_MAT3_ZERO_INIT;
  mat3  m5;
  int   i, j, k;

  /* test identity matrix multiplication */
  glmc_mat3_mul(m1, m2, m3);
  for (i = 0; i < m; i++) {
    for (j = 0; j < n; j++) {
      if (i == j)
        assert_true(glm_eq(m3[i][j], 1.0f));
      else
        assert_true(glm_eq(m3[i][j], 0.0f));
    }
  }

  /* test random matrices */
  /* random matrices */
  test_rand_mat3(m1);
  test_rand_mat3(m2);

  glmc_mat3_mul(m1, m2, m3);
  for (i = 0; i < m; i++) {
    for (j = 0; j < n; j++) {
      for (k = 0; k < m; k++)
        /* column-major */
        m4[i][j] += m1[k][j] * m2[i][k];
    }
  }

  test_assert_mat3_eq(m3, m4);

  for (i = 0; i < 100000; i++) {
    test_rand_mat3(m3);
    test_rand_mat3(m4);

    /* test inverse precise */
    glmc_mat3_inv(m3, m4);
    glmc_mat3_inv(m4, m5);
    test_assert_mat3_eq(m3, m5);
  }
}
