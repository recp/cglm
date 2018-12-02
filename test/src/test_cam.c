/*
 * Copyright (c), Recep Aslantas.
 *
 * MIT License (MIT), http://opensource.org/licenses/MIT
 * Full license can be found in the LICENSE file
 */

#include "test_common.h"

void
test_camera_lookat(void **state) {
  mat4  view1, view2;
  vec3 center,
       eye    = {0.024f, 14.6f, 67.04f},
       dir    = {0.0f, 0.0f, -1.0f},
       up     = {0.0f, 1.0f, 0.0f}
  ;

  glm_vec3_add(eye, dir, center);
  glm_lookat(eye, center, up, view1);

  glm_look(eye, dir, up, view2);

  test_assert_mat4_eq(view1, view2);
}

void
test_camera_decomp(void **state) {
  mat4  proj, proj2;
  vec4  sizes;
  float aspect, fovy, nearVal, farVal;

  aspect  = 0.782f;
  fovy    = glm_rad(49.984f);
  nearVal = 0.1f;
  farVal  = 100.0f;

  glm_perspective(fovy, aspect, nearVal, farVal, proj);
  assert_true(fabsf(aspect  - glm_persp_aspect(proj)) < FLT_EPSILON);
  assert_true(fabsf(fovy    - glm_persp_fovy(proj))   < FLT_EPSILON);
  assert_true(fabsf(49.984f - glm_deg(glm_persp_fovy(proj))) < FLT_EPSILON);

  glm_persp_sizes(proj, fovy, sizes);

  glm_frustum(-sizes[0] * 0.5,
               sizes[0] * 0.5,
              -sizes[1] * 0.5,
               sizes[1] * 0.5,
               nearVal,
               farVal,
               proj2);

  test_assert_mat4_eq(proj, proj2);
}
