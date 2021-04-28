/*
 * Copyright (c), Recep Aslantas.
 *
 * MIT License (MIT), http://opensource.org/licenses/MIT
 * Full license can be found in the LICENSE file
 */

#include "test_common.h"

#ifndef glm_affine_mat_test_guard
#define glm_affine_mat_test_guard
CGLM_INLINE
void
glm_inv_tr_raw(mat4 mat) {
  CGLM_ALIGN_MAT mat3 r;
  CGLM_ALIGN(8)  vec3 t;

  /* rotate */
  glm_mat4_pick3t(mat, r);
  glm_mat4_ins3(r, mat);

  /* translate */
  glm_mat3_mulv(r, mat[3], t);
  glm_vec3_negate(t);
  glm_vec3_copy(t, mat[3]);
}
#endif

TEST_IMPL(GLM_PREFIX, mul) {
  mat4 m1 = GLM_MAT4_IDENTITY_INIT;
  mat4 m2 = GLM_MAT4_IDENTITY_INIT;
  mat4 m3;
  mat4 m4 = GLM_MAT4_ZERO_INIT;
  int  i, j, k;

  test_rand_mat4(m1);
  test_rand_mat4(m2);

  GLM(mul)(m1, m2, m3);
  for (i = 0; i < 4; i++) {
    for (j = 0; j < 4; j++) {
      for (k = 0; k < 4; k++)
        /* column-major */
        m4[i][j] += m1[k][j] * m2[i][k];
    }
  }

  ASSERTIFY(test_assert_mat4_eq(m3, m4))

  /* test pre compiled */
  GLM(mul)(m1, m2, m3);
  ASSERTIFY(test_assert_mat4_eq(m3, m4))

  TEST_SUCCESS
}

TEST_IMPL(GLM_PREFIX, mul_rot) {
  mat4 m1 = GLM_MAT4_IDENTITY_INIT;
  mat4 m2 = GLM_MAT4_IDENTITY_INIT;
  mat4 m3;
  mat4 m4 = GLM_MAT4_ZERO_INIT;
  int  i, j, k;

  glm_rotate(m1, drand48(), (vec3){drand48(), drand48(), drand48()});
  glm_rotate(m2, drand48(), (vec3){drand48(), drand48(), drand48()});

  GLM(mul_rot)(m1, m2, m3);
  for (i = 0; i < 4; i++) {
    for (j = 0; j < 4; j++) {
      for (k = 0; k < 4; k++)
        /* column-major */
        m4[i][j] += m1[k][j] * m2[i][k];
    }
  }

  ASSERTIFY(test_assert_mat4_eq(m3, m4))

  /* test pre compiled */
  GLM(mul_rot)(m1, m2, m3);
  ASSERTIFY(test_assert_mat4_eq(m3, m4))

  TEST_SUCCESS
}

TEST_IMPL(GLM_PREFIX, inv_tr) {
  mat4 m1, m2;
  int  i;

  for (i = 0; i < 10000; i++) {
    test_rand_mat4(m1);

    glm_mat4_copy(m1, m2);

    /* test inverse precise */
    GLM(inv_tr)(m1);
    GLM(inv_tr)(m1);
    ASSERTIFY(test_assert_mat4_eq(m1, m2))

    /* test inverse precise */
    GLM(mat4_inv)(m1, m2);
    GLM(inv_tr)(m2);
    ASSERTIFY(test_assert_mat4_eq(m1, m2))
    
    /* test with raw */
    glm_mat4_copy(m1, m2);
    glm_inv_tr_raw(m2);
    GLM(inv_tr)(m1);
    ASSERTIFY(test_assert_mat4_eq(m1, m2))
  }

  TEST_SUCCESS
}
