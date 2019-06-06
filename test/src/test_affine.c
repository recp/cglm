/*
 * Copyright (c), Recep Aslantas.
 *
 * MIT License (MIT), http://opensource.org/licenses/MIT
 * Full license can be found in the LICENSE file
 */

#include "test_common.h"

void
test_affine(void **state) {
  mat4 t1, t2, t3, t4, t5;

  /* test translate is postmultiplied */
  glmc_rotate_make(t1, GLM_PI_4f, GLM_YUP);
  glm_translate_make(t2, (vec3){34, 57, 36});

  glmc_mat4_mul(t1, t2, t3); /* R * T */

  glm_translate(t1, (vec3){34, 57, 36});
  test_assert_mat4_eq(t1, t3);

  /* test rotate is postmultiplied */
  glmc_rotate_make(t1, GLM_PI_4f, GLM_YUP);
  glm_translate_make(t2, (vec3){34, 57, 36});

  glmc_mat4_mul(t2, t1, t3); /* T * R */

  glm_rotate(t2, GLM_PI_4f, GLM_YUP);
  test_assert_mat4_eq(t2, t3);

  /* test scale is postmultiplied */
  glmc_rotate_make(t1, GLM_PI_4f, GLM_YUP);
  glm_translate_make(t2, (vec3){34, 57, 36});
  glm_scale_make(t4, (vec3){3, 5, 6});

  glmc_mat4_mul(t2, t1, t3); /* T * R */
  glmc_mat4_mul(t3, t4, t5); /* T * R * S */

  glm_scale(t3, (vec3){3, 5, 6});
  test_assert_mat4_eq(t3, t5);

  /* test translate_x */
  glmc_rotate_make(t1, GLM_PI_4f, GLM_YUP);
  glm_translate_make(t2, (vec3){34, 0, 0});

  glmc_mat4_mul(t1, t2, t3); /* R * T */
  glm_translate_x(t1, 34);
  test_assert_mat4_eq(t1, t3);

  /* test translate_y */
  glmc_rotate_make(t1, GLM_PI_4f, GLM_YUP);
  glm_translate_make(t2, (vec3){0, 57, 0});

  glmc_mat4_mul(t1, t2, t3); /* R * T */
  glm_translate_y(t1, 57);
  test_assert_mat4_eq(t1, t3);

  /* test translate_z */
  glmc_rotate_make(t1, GLM_PI_4f, GLM_YUP);
  glm_translate_make(t2, (vec3){0, 0, 36});

  glmc_mat4_mul(t1, t2, t3); /* R * T */
  glm_translate_z(t1, 36);
  test_assert_mat4_eq(t1, t3);

  /* test rotate_x */
  glmc_rotate_make(t1, GLM_PI_4f, (vec3){1, 0, 0});
  glm_translate_make(t2, (vec3){34, 57, 36});

  glmc_mat4_mul(t2, t1, t3); /* T * R */

  glm_rotate_x(t2, GLM_PI_4f, t2);
  test_assert_mat4_eq(t2, t3);

  /* test rotate_y */
  glmc_rotate_make(t1, GLM_PI_4f, (vec3){0, 1, 0});
  glm_translate_make(t2, (vec3){34, 57, 36});

  glmc_mat4_mul(t2, t1, t3); /* T * R */

  glm_rotate_y(t2, GLM_PI_4f, t2);
  test_assert_mat4_eq(t2, t3);

  /* test rotate_z */
  glmc_rotate_make(t1, GLM_PI_4f, (vec3){0, 0, 1});
  glm_translate_make(t2, (vec3){34, 57, 36});

  glmc_mat4_mul(t2, t1, t3); /* T * R */

  glm_rotate_z(t2, GLM_PI_4f, t2);
  test_assert_mat4_eq(t2, t3);

  /* test rotate */
  glmc_rotate_make(t1, GLM_PI_4f, (vec3){0, 0, 1});
  glm_translate_make(t2, (vec3){34, 57, 36});

  glmc_mat4_mul(t2, t1, t3); /* T * R */
  glmc_rotate(t2, GLM_PI_4f, (vec3){0, 0, 1});

  test_assert_mat4_eq(t3, t2);

  /* test scale_uni */
  glmc_rotate_make(t1, GLM_PI_4f, GLM_YUP);
  glm_translate_make(t2, (vec3){34, 57, 36});
  glm_scale_make(t4, (vec3){3, 3, 3});

  glmc_mat4_mul(t2, t1, t3); /* T * R */
  glmc_mat4_mul(t3, t4, t5); /* T * R * S */

  glm_scale_uni(t3, 3);
  test_assert_mat4_eq(t3, t5);
}
