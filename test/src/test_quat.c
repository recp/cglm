/*
 * Copyright (c), Recep Aslantas.
 *
 * MIT License (MIT), http://opensource.org/licenses/MIT
 * Full license can be found in the LICENSE file
 */

#include "test_common.h"

CGLM_INLINE
void
test_quat_mul_raw(versor p, versor q, versor dest) {
  dest[0] = p[3] * q[0] + p[0] * q[3] + p[1] * q[2] - p[2] * q[1];
  dest[1] = p[3] * q[1] - p[0] * q[2] + p[1] * q[3] + p[2] * q[0];
  dest[2] = p[3] * q[2] + p[0] * q[1] - p[1] * q[0] + p[2] * q[3];
  dest[3] = p[3] * q[3] - p[0] * q[0] - p[1] * q[1] - p[2] * q[2];
}

void
test_quat(void **state) {
  mat4   inRot, outRot;
  versor inQuat, outQuat, q3, q4;
  int    i;

  for (i = 0; i < 1000; i++) {
    test_rand_quat(inQuat);
    glmc_quat_mat4(inQuat, inRot);
    glmc_mat4_quat(inRot, outQuat);
    glmc_quat_mat4(outQuat, outRot);
    test_assert_quat_eq_abs(inQuat, outQuat);
    test_assert_mat4_eq2(inRot, outRot, 0.000009); /* almost equal */

    test_quat_mul_raw(inQuat, outQuat, q3);
    glm_quat_mul_sse2(inQuat, outQuat, q4);

    test_assert_quat_eq(q3, q4);
  }
}
