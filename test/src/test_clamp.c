/*
 * Copyright (c), Recep Aslantas.
 *
 * MIT License (MIT), http://opensource.org/licenses/MIT
 * Full license can be found in the LICENSE file
 */

#include "test_common.h"

TEST_IMPL(clamp) {
  vec3 v3 = {15.07f, 0.4f, 17.3f};
  vec4 v4 = {5.07f,  2.3f, 1.3f, 1.4f};

  ASSERT(glm_eq(glm_clamp(1.6f, 0.0f, 1.0f),  1.0f))
  ASSERT(glm_eq(glm_clamp(-1.6f, 0.0f, 1.0f), 0.0f))
  ASSERT(glm_eq(glm_clamp(0.6f, 0.0f, 1.0f),  0.6f))

  glm_vec3_clamp(v3, 0.0, 1.0);
  glm_vec4_clamp(v4, 1.5, 3.0);

  ASSERT(glm_eq(v3[0], 1.0f))
  ASSERT(glm_eq(v3[1], 0.4f))
  ASSERT(glm_eq(v3[2], 1.0f))

  ASSERT(glm_eq(v4[0], 3.0f))
  ASSERT(glm_eq(v4[1], 2.3f))
  ASSERT(glm_eq(v4[2], 1.5f))
  ASSERT(glm_eq(v4[3], 1.5f))
  
  TEST_SUCCESS
}
