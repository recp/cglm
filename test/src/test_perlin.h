/*
 * Copyright (c), Recep Aslantas.
 *
 * MIT License (MIT), http://opensource.org/licenses/MIT
 * Full license can be found in the LICENSE file
 */

#include "test_common.h"

TEST_IMPL(GLM_PREFIX, perlin) {
  vec4  p = {1.0f, 2.0f, 3.0f, 4.0f};
  
  float out = GLM(perlin)(p);
  ASSERT(test_eq(out, 10.0f))
  TEST_SUCCESS
}
