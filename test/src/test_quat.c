/*
 * Copyright (c), Recep Aslantas.
 *
 * MIT License (MIT), http://opensource.org/licenses/MIT
 * Full license can be found in the LICENSE file
 */

#include "test_common.h"

void
test_quat(void **state) {
  mat4   rot;
  versor inQuat, outQuat;
  int    i;

  for (i = 0; i < 10000; i++) {
    test_rand_quat(inQuat);
    glmc_quat_mat4(inQuat, rot);
    glm_mat4_quat(rot, outQuat);
    test_assert_quat_eq(inQuat, outQuat);
  }
}
