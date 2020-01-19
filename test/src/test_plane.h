/*
 * Copyright (c), Recep Aslantas.
 *
 * MIT License (MIT), http://opensource.org/licenses/MIT
 * Full license can be found in the LICENSE file
 */

#include "test_common.h"

TEST_IMPL(GLM_PREFIX, plane_normalize) {
  vec4  p1 = {2.0f, -3.0f, 4.0f, 5.0f}, p2 = {2.0f, -3.0f, 4.0f, 5.0f};
  float s  = 1.0f;
  float norm;

  GLM(plane_normalize)(p2);

  norm = sqrtf(p1[0] * p1[0] + p1[1] * p1[1] + p1[2] * p1[2]);
  if (norm == 0.0f) {
    ASSERT(test_eq(p1[0], 0.0f))
    ASSERT(test_eq(p1[1], 0.0f))
    ASSERT(test_eq(p1[2], 0.0f))
    ASSERT(test_eq(p1[3], 0.0f))

    TEST_SUCCESS
  }
  
  norm = s / norm;
  
  ASSERT(test_eq(p1[0] * norm, p2[0]))
  ASSERT(test_eq(p1[1] * norm, p2[1]))
  ASSERT(test_eq(p1[2] * norm, p2[2]))
  ASSERT(test_eq(p1[3] * norm, p2[3]))

  glm_vec4_zero(p1);
  GLM(plane_normalize)(p1);
  ASSERTIFY(test_assert_vec4_eq(p1, GLM_VEC4_ZERO))

  TEST_SUCCESS
}
