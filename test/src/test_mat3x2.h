/*
 * Copyright (c), Recep Aslantas.
 *
 * MIT License (MIT), http://opensource.org/licenses/MIT
 * Full license can be found in the LICENSE file
 */

#include "test_common.h"

#ifndef CGLM_TEST_MAT3X2_ONCE
#define CGLM_TEST_MAT3X2_ONCE

TEST_IMPL(MACRO_GLM_MAT3X2_ZERO_INIT) {
  mat3x2 mat3x2_zero = GLM_MAT3X2_ZERO_INIT;
  test_assert_mat3x2_eq_zero(mat3x2_zero);
  TEST_SUCCESS
}

TEST_IMPL(MACRO_GLM_MAT3X2_ZERO) {
  mat3x2 mat3x2_zero = GLM_MAT3X2_ZERO;
  test_assert_mat3x2_eq_zero(mat3x2_zero);
  TEST_SUCCESS
}

#endif /* CGLM_TEST_MAT3X2_ONCE */

TEST_IMPL(GLM_PREFIX, mat3x2_make) {
  float src[18] = {
    0.5f, 1.7f, 10.3f, 4.2f, 8.9f, 1.1f,
    2.3f, 4.2f, 66.5f, 23.7f, 6.6f, 8.9f,
    5.3f, 4.8f, 96.3f, 13.7f, 4.7f, 5.5f
  };

  mat3x2 dest[3];

  float *srcp = src;
  unsigned int i, j, k;

  for (i = 0, j = 0, k = 0; i < sizeof(src) / sizeof(float); i+=6,j++) {
    GLM(mat3x2_make)(srcp + i, dest[j]);

    ASSERT(test_eq(src[ i ], dest[j][k][0]));
    ASSERT(test_eq(src[i+1], dest[j][k][1]));

    ASSERT(test_eq(src[i+2], dest[j][k+1][0]));
    ASSERT(test_eq(src[i+3], dest[j][k+1][1]));

    ASSERT(test_eq(src[i+4], dest[j][k+2][0]));
    ASSERT(test_eq(src[i+5], dest[j][k+2][1]));
  }

  TEST_SUCCESS
}
