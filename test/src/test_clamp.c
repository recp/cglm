/*
 * Copyright (c), Recep Aslantas.
 *
 * MIT License (MIT), http://opensource.org/licenses/MIT
 * Full license can be found in the LICENSE file
 */

#include "test_common.h"

void
test_clamp(void **state) {
  vec3 v3 = {15.07, 0.4, 17.3};
  vec4 v4 = {5.07,  2.3, 1.3, 1.4};

  assert_true(glm_clamp(1.6f, 0.0f, 1.0f)  == 1.0f);
  assert_true(glm_clamp(-1.6f, 0.0f, 1.0f) == 0.0f);
  assert_true(glm_clamp(0.6f, 0.0f, 1.0f)  == 0.6f);

  glm_vec3_clamp(v3, 0.0, 1.0);
  glm_vec4_clamp(v4, 1.5, 3.0);

  assert_true(v3[0] == 1.0f);
  assert_true(v3[1] == 0.4f);
  assert_true(v3[2] == 1.0f);

  assert_true(v4[0] == 3.0f);
  assert_true(v4[1] == 2.3f);
  assert_true(v4[2] == 1.5f);
  assert_true(v4[3] == 1.5f);
}
