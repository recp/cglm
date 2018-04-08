/*
 * Copyright (c), Recep Aslantas.
 *
 * MIT License (MIT), http://opensource.org/licenses/MIT
 * Full license can be found in the LICENSE file
 */

#include "test_common.h"

void
test_quat(void **state) {
  mat4   inRot, outRot;
  versor inQuat, outQuat;
  int    i;

  for (i = 0; i < 1000; i++) {
    test_rand_quat(inQuat);
    glmc_quat_mat4(inQuat, inRot);
    glmc_mat4_quat(inRot, outQuat);
    glmc_quat_mat4(outQuat, outRot);
    test_assert_quat_eq(inQuat, outQuat);
    test_assert_mat4_eq2(inRot, outRot, 0.000009); /* almost equal */
  }
}
