/*
 * Copyright (c), Recep Aslantas.
 *
 * MIT License (MIT), http://opensource.org/licenses/MIT
 * Full license can be found in the LICENSE file
 */

#include "test_common.h"

#define m 4
#define n 4

TEST_IMPL(mat4_identity) {
  mat4 m1 = GLM_MAT4_IDENTITY_INIT;
  mat4 m2 = GLM_MAT4_IDENTITY_INIT;
  mat4 m3;
  int  i, j;
  
  /* test identity matrix multiplication */
  glm_mat4_mul(m1, m2, m3);
  for (i = 0; i < m; i++) {
    for (j = 0; j < n; j++) {
      if (i == j) {
        ASSERT(glm_eq(m3[i][j], 1.0f))
      } else {
        ASSERT(glm_eq(m3[i][j], 0.0f))
      }
    }
  }
  
  TEST_SUCCESS
}

TEST_IMPL(mat4_mul) {
  mat4  m1 = GLM_MAT4_IDENTITY_INIT;
  mat4  m2 = GLM_MAT4_IDENTITY_INIT;
  mat4  m3;
  mat4  m4 = GLM_MAT4_ZERO_INIT;
  int   i, j, k;
  
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
  
  ASSERT(test_assert_mat4_eq(m3, m4).status == TEST_OK)
  
  /* test pre compiled */
  glmc_mat4_mul(m1, m2, m3);
  ASSERT(test_assert_mat4_eq(m3, m4).status == TEST_OK)
  
  TEST_SUCCESS
}

TEST_IMPL(mat4_all) {
  mat4 m1 = GLM_MAT4_IDENTITY_INIT;
  mat4 m3;
  mat4 m4 = GLM_MAT4_ZERO_INIT;
  mat4 m5;
  int  i;

  for (i = 0; i < 100000; i++) {
    test_rand_mat4(m3);
    test_rand_mat4(m4);
    
    /* test inverse precise */
    glm_mat4_inv_precise(m3, m4);
    glm_mat4_inv_precise(m4, m5);
    ASSERT(test_assert_mat4_eq(m3, m5).status == TEST_OK)
    
    test_rand_mat4(m3);
    test_rand_mat4(m4);

    glmc_mat4_inv_precise(m3, m4);
    glmc_mat4_inv_precise(m4, m5);
    ASSERT(test_assert_mat4_eq(m3, m5).status == TEST_OK)
    
    /* test inverse rcp */
    test_rand_mat4(m3);
    test_rand_mat4(m4);
    
    glm_mat4_inv_fast(m3, m4);
    glm_mat4_inv_fast(m4, m5);
    ASSERT(test_assert_mat4_eq2(m3, m5, 0.0009f).status == TEST_OK)
    
    test_rand_mat4(m3);
    test_rand_mat4(m4);
    
    glmc_mat4_inv(m3, m4);
    glmc_mat4_inv(m4, m5);
    ASSERT(test_assert_mat4_eq2(m3, m5, 0.0009f).status == TEST_OK)
  }

  /* test determinant */
  ASSERT(glm_mat4_det(m1) == glmc_mat4_det(m1))
#if defined( __SSE2__ )
  ASSERT(glmc_mat4_det(m1) == glm_mat4_det_sse2(m1))
#endif
  
  TEST_SUCCESS
}
