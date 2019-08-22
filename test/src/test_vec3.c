/*
 * Copyright (c), Recep Aslantas.
 *
 * MIT License (MIT), http://opensource.org/licenses/MIT
 * Full license can be found in the LICENSE file
 */

#include "test_common.h"

void
test_vec3(void **state) {
  mat3 rot1m3;
  mat4 rot1;
  vec3 v, v1, v2;
  vec3s vs1, vs2, vs3, vs4;

  /* test zero */
  glm_vec3_zero(v);
  test_assert_vec3_eq(GLM_VEC3_ZERO, v);

  /* test one */
  glm_vec3_one(v);
  test_assert_vec3_eq(GLM_VEC3_ONE, v);

  /* adds, subs, div, divs, mul */
  glm_vec3_add(v, GLM_VEC3_ONE, v);
  assert_true(glmc_vec3_eq_eps(v, 2));

  glm_vec3_adds(v, 10, v);
  assert_true(glmc_vec3_eq_eps(v, 12));

  glm_vec3_sub(v, GLM_VEC3_ONE, v);
  assert_true(glmc_vec3_eq_eps(v, 11));

  glm_vec3_subs(v, 1, v);
  assert_true(glmc_vec3_eq_eps(v, 10));

  glm_vec3_broadcast(2, v1);
  glm_vec3_div(v, v1, v);
  assert_true(glmc_vec3_eq_eps(v, 5));

  glm_vec3_divs(v, 0.5, v);
  assert_true(glmc_vec3_eq_eps(v, 10));

  glm_vec3_mul(v, v1, v);
  assert_true(glmc_vec3_eq_eps(v, 20));

  glm_vec3_scale(v, 0.5, v);
  assert_true(glmc_vec3_eq_eps(v, 10));

  glm_vec3_normalize_to(v, v1);
  glm_vec3_scale(v1, 0.8, v1);
  glm_vec3_scale_as(v, 0.8, v);
  test_assert_vec3_eq(v1, v);

  /* addadd, subadd, muladd */
  glm_vec3_one(v);

  glm_vec3_addadd(GLM_VEC3_ONE, GLM_VEC3_ONE, v);
  assert_true(glmc_vec3_eq_eps(v, 3));

  glm_vec3_subadd(GLM_VEC3_ONE, GLM_VEC3_ZERO, v);
  assert_true(glmc_vec3_eq_eps(v, 4));

  glm_vec3_broadcast(2, v1);
  glm_vec3_broadcast(3, v2);
  glm_vec3_muladd(v1, v2, v);
  assert_true(glmc_vec3_eq_eps(v, 10));

  /* rotate */
  glm_vec3_copy(GLM_YUP, v);
  glm_rotate_make(rot1, glm_rad(90), GLM_XUP);
  glm_vec3_rotate_m4(rot1, v, v1);
  glm_mat4_pick3(rot1, rot1m3);
  glm_vec3_rotate_m3(rot1m3, v, v2);

  test_assert_vec3_eq(v1, v2);
  test_assert_vec3_eq(v1, GLM_ZUP);

  /* structs */
  vs1 = test_rand_vec3s();
  vs2 = test_rand_vec3s();

  vs3 = glms_vec3_add(vs1, vs2);
  vs4 = glms_vec3_maxv(vs1, vs3);
  test_assert_vec3s_eq(vs3, vs4);

  /* swizzle */

  /* ZYX */
  v1[0] = 1;
  v1[1] = 2;
  v1[2] = 3;
  glm_vec3_swizzle(v1, GLM_ZYX, v1);
  test_assert_vec3_eq(v1, (vec3){3, 2, 1});

  glm_vec3_swizzle(v1, GLM_XXX, v1);
  test_assert_vec3_eq(v1, (vec3){3, 3, 3});

  v1[0] = 1;
  v1[1] = 2;
  v1[2] = 3;

  glm_vec3_swizzle(v1, GLM_YYY, v1);
  test_assert_vec3_eq(v1, (vec3){2, 2, 2});

  v1[0] = 1;
  v1[1] = 2;
  v1[2] = 3;

  glm_vec3_swizzle(v1, GLM_ZZZ, v1);
  test_assert_vec3_eq(v1, (vec3){3, 3, 3});
}
