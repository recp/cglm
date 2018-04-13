/*
 * Copyright (c), Recep Aslantas.
 *
 * MIT License (MIT), http://opensource.org/licenses/MIT
 * Full license can be found in the LICENSE file
 */

#include "test_common.h"

void
test_vec3(void **state) {
  vec3  v;

  /* test zero */
  glm_vec_zero(v);
  test_assert_vec3_eq(GLM_VEC3_ZERO, v);

  /* test one */
  glm_vec_one(v);
  test_assert_vec3_eq(GLM_VEC3_ONE, v);
}
