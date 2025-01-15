/*
 * Copyright (c), Recep Aslantas.
 *
 * MIT License (MIT), http://opensource.org/licenses/MIT
 * Full license can be found in the LICENSE file
 */

#include "test_common.h"

TEST_IMPL(GLM_PREFIX, perlin) {
  vec4 p1[] = {
    {0.1f, 0.2f, 0.3f, 0.4f},
    {0.2f, 0.3f, 0.4f, 0.5f},
    {0.3f, 0.4f, 0.5f, 0.6f},
    {0.4f, 0.5f, 0.6f, 0.7f},
    {0.5f, 0.6f, 0.7f, 0.8f},
    {0.6f, 0.7f, 0.8f, 0.9f},
    {0.7f, 0.8f, 0.9f, 1.0f},
    {0.8f, 0.9f, 1.0f, 1.1f},
    {0.9f, 1.0f, 1.1f, 1.2f},
    {1.0f, 1.1f, 1.2f, 1.3f},
  };

  // expected values calculated by glm::perlin
  float e[] = {
    -0.5091819763183594f,
    -0.4375732541084290f,
    -0.3212279379367828f,
    -0.2279999703168869f,
    -0.1577337533235550f,
    -0.0445968918502331f,
    0.1069696992635727f,
    0.2067739963531494f,
    0.2106968611478806f,
    0.1397782564163208f
  };
  
  for (int i = 0; i < 10; i++) {
    ASSERT(test_eq(GLM(perlin)(p1[i]), e[i]));
  }

  TEST_SUCCESS
}
