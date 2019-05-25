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
  vec3   eye, axis, imag, v1, v2;
  int    i;

  /* 0. test identiy quat */
  glm_quat_identity(q4);
  assert_true(glm_eq(glm_quat_real(q4), cosf(glm_rad(0.0f) * 0.5f)));
  glm_quat_mat4(q4, rot1);
  test_assert_mat4_eq2(rot1, GLM_MAT4_IDENTITY, 0.000009);

  /* 1. test quat to mat and mat to quat */
  for (i = 0; i < 1000; i++) {
    test_rand_quat(inQuat);

    glmc_quat_mat4(inQuat, inRot);
    glmc_mat4_quat(inRot, outQuat);
    glmc_quat_mat4(outQuat, outRot);

    /* 2. test first quat and generated one equality */
    test_assert_quat_eq_abs(inQuat, outQuat);

    /* 3. test first rot and second rotation */
    test_assert_mat4_eq2(inRot, outRot, 0.000009); /* almost equal */

    /* 4. test SSE mul and raw mul */
#if defined( __SSE__ ) || defined( __SSE2__ )
    test_quat_mul_raw(inQuat, outQuat, q3);
    glm_quat_mul_sse2(inQuat, outQuat, q4);
    test_assert_quat_eq(q3, q4);
#endif
  }

  /* 5. test lookat */
  test_rand_vec3(eye);
  glm_quatv(q3, glm_rad(-90.0f), GLM_YUP);

  /* now X axis must be forward axis, Z must be right axis */
  glm_look(eye, GLM_XUP, GLM_YUP, view1);

  /* create view matrix with quaternion */
  glm_quat_look(eye, q3, view2);

  test_assert_mat4_eq2(view1, view2, 0.000009);

  /* 6. test quaternion rotation matrix result */
  test_rand_quat(q3);
  glm_quat_mat4(q3, rot1);

  /* 6.1 test axis and angle of quat */
  glm_quat_axis(q3, axis);
  glm_rotate_make(rot2, glm_quat_angle(q3), axis);

  test_assert_mat4_eq2(rot1, rot2, 0.000009);

  /* 7. test quaternion multiplication (hamilton product),
        final rotation = first rotation + second = quat1 * quat2
   */
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

  /* 8. test quaternion for look rotation */

  /* 8.1 same direction */
  /* look at from 0, 0, 1 to zero, direction = 0, 0, -1 */
  glm_quat_for((vec3){0, 0, -1}, (vec3){0, 0, -1}, GLM_YUP, q3);

  /* result must be identity */
  glm_quat_identity(q4);
  test_assert_quat_eq(q3, q4);

  /* look at from 0, 0, 1 to zero, direction = 0, 0, -1 */
  glm_quat_forp(GLM_ZUP, GLM_VEC3_ZERO, (vec3){0, 0, -1}, GLM_YUP, q3);

  /* result must be identity */
  glm_quat_identity(q4);
  test_assert_quat_eq(q3, q4);

  /* 8.2 perpendicular */
  glm_quat_for(GLM_XUP, (vec3){0, 0, -1}, GLM_YUP, q3);

  /* result must be -90 */
  glm_quatv(q4, glm_rad(-90.0f), GLM_YUP);
  test_assert_quat_eq(q3, q4);

  /* 9. test imag, real */

  /* 9.1 real */
  assert_true(glm_eq(glm_quat_real(q4), cosf(glm_rad(-90.0f) * 0.5f)));

  /* 9.1 imag */
  glm_quat_imag(q4, imag);

  /* axis = Y_UP * sinf(angle * 0.5), YUP = 0, 1, 0 */
  axis[0] = 0.0f;
  axis[1] = sinf(glm_rad(-90.0f) * 0.5f) * 1.0f;
  axis[2] = 0.0f;

  assert_true(glm_vec3_eqv_eps(imag, axis));

  /* 9.2 axis */
  glm_quat_axis(q4, axis);
  imag[0] =  0.0f;
  imag[1] = -1.0f;
  imag[2] =  0.0f;

  test_assert_vec3_eq(imag, axis);

  /* 10. test rotate vector using quat */
  /* (0,0,-1) around (1,0,0) must give (0,1,0) */
  v1[0] = 0.0f; v1[1] = 0.0f; v1[2] = -1.0f;
  v2[0] = 0.0f; v2[1] = 0.0f; v2[2] = -1.0f;

  glm_vec3_rotate(v1, glm_rad(90.0f), (vec3){1.0f, 0.0f, 0.0f});
  glm_quatv(q3, glm_rad(90.0f), (vec3){1.0f, 0.0f, 0.0f});

  glm_vec4_scale(q3, 1.5, q3);
  glm_quat_rotatev(q3, v2, v2);

  /* result must be : (0,1,0) */
  assert_true(fabsf(v1[0]) <= 0.00009f
              && fabsf(v1[1] - 1.0f) <= 0.00009f
              && fabsf(v1[2]) <= 0.00009f);

  test_assert_vec3_eq(v1, v2);

  /* 11. test rotate transform */
  glm_translate_make(rot1, (vec3){-10.0, 45.0f, 8.0f});
  glm_rotate(rot1, glm_rad(-90), GLM_ZUP);

  glm_quatv(q3, glm_rad(-90.0f), GLM_ZUP);
  glm_translate_make(rot2, (vec3){-10.0, 45.0f, 8.0f});
  glm_quat_rotate(rot2, q3, rot2);

  /* result must be same (almost) */
  test_assert_mat4_eq2(rot1, rot2, 0.000009);

  glm_rotate_make(rot1, glm_rad(-90), GLM_ZUP);
  glm_translate(rot1, (vec3){-10.0, 45.0f, 8.0f});

  glm_quatv(q3, glm_rad(-90.0f), GLM_ZUP);
  glm_mat4_identity(rot2);
  glm_quat_rotate(rot2, q3, rot2);
  glm_translate(rot2, (vec3){-10.0, 45.0f, 8.0f});

  /* result must be same (almost) */
  test_assert_mat4_eq2(rot1, rot2, 0.000009);

  /* reverse */
  glm_rotate_make(rot1, glm_rad(-90), GLM_ZUP);
  glm_quatv(q3, glm_rad(90.0f), GLM_ZUP);
  glm_quat_rotate(rot1, q3, rot1);

  /* result must be identity */
  test_assert_mat4_eq2(rot1, GLM_MAT4_IDENTITY, 0.000009);

  test_rand_quat(q3);

  /* 12. inverse of quat, multiplication must be IDENTITY */
  glm_quat_inv(q3, q4);
  glm_quat_mul(q3, q4, q5);

  glm_quat_identity(q3);
  test_assert_quat_eq(q3, q5);

  /* TODO: add tests for slerp, lerp */
}
