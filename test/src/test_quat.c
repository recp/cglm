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
  mat4   inRot, outRot, view1, view2, rot1, rot2;
  versor inQuat, outQuat, q3, q4, q5;
  vec3   eye, axis;
  int    i;

  /* 1. test quat to mat and mat to quat */
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

  /* 2. test lookat */
  test_rand_vec3(eye);
  glm_quatv(q3, glm_rad(-90.0f), GLM_YUP);

  /* now X axis must be forward axis, Z must be right axis */
  glm_look(eye, GLM_XUP, GLM_YUP, view1);

  /* create view matrix with quaternion */
  glm_quat_look(eye, q3, view2);

  test_assert_mat4_eq2(view1, view2, 0.000009);

  /* 5. test quaternion rotation matrix result */
  test_rand_quat(q3);
  glm_quat_mat4(q3, rot1);

  /* 5.1 test axis and angle of quat */
  glm_quat_axis(q3, axis);
  glm_rotate_make(rot2, glm_quat_angle(q3), axis);

  test_assert_mat4_eq2(rot1, rot2, 0.000009);

  /* 6. test quaternion multiplication, first rotation + second = final */
  test_rand_quat(q3);
  test_rand_quat(q4);

  glm_quat_mul(q3, q4, q5);

  glm_quat_axis(q3, axis);
  glm_rotate_make(rot1, glm_quat_angle(q3), axis);

  glm_quat_axis(q4, axis);
  glm_rotate(rot1, glm_quat_angle(q4), axis);

  /* rot2 is combine of two rotation now test with quaternion result */
  glm_quat_mat4(q5, rot2);

  /* result must be same (almost) */
  test_assert_mat4_eq2(rot1, rot2, 0.000009);
}
