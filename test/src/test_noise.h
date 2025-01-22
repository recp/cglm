/*
 * Copyright (c), Recep Aslantas.
 *
 * MIT License (MIT), http://opensource.org/licenses/MIT
 * Full license can be found in the LICENSE file
 */

#include "test_common.h"

TEST_IMPL(GLM_PREFIX, perlin_vec4) {
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

  /* expected values calculated by glm::perlin */
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
    ASSERT(test_eq(GLM(perlin_vec4)(p1[i]), e[i]));
  }

  TEST_SUCCESS
}

TEST_IMPL(GLM_PREFIX, perlin_vec3) {
  vec3 p1[] = {
    {0.1f, 0.2f, 0.3f},
    {0.2f, 0.3f, 0.4f},
    {0.3f, 0.4f, 0.5f},
    {0.4f, 0.5f, 0.6f},
    {0.5f, 0.6f, 0.7f},
    {0.6f, 0.7f, 0.8f},
    {0.7f, 0.8f, 0.9f},
    {0.8f, 0.9f, 1.0f},
    {0.9f, 1.0f, 1.1f},
    {1.0f, 1.1f, 1.2f},
  };

  /* expected values calculated by glm::perlin */
  float e[] = {
    -0.2909241318702698f,
    -0.4667602181434631f,
    -0.4679279625415802f,
    -0.2616460621356964f,
    0.0562822706997395f,
    0.3178773224353790f,
    0.3981811404228210f,
    0.3011017739772797f,
    0.1263920217752457f,
    -0.0602480024099350f
  };
  
  for (int i = 0; i < 10; i++) {
    ASSERT(test_eq(GLM(perlin_vec3)(p1[i]), e[i]));
  }

  TEST_SUCCESS
}


TEST_IMPL(GLM_PREFIX, perlin_vec2) {
  vec2 p1[] = {
    {0.1f, 0.2f},
    {0.2f, 0.3f},
    {0.3f, 0.4f},
    {0.4f, 0.5f},
    {0.5f, 0.6f},
    {0.6f, 0.7f},
    {0.7f, 0.8f},
    {0.8f, 0.9f},
    {0.9f, 1.0f},
    {1.0f, 1.1f},
  };

  /* expected values calculated by glm::perlin */
  float e[] = {
    0.2841092348098755f,
    0.2328013032674789f,
    -0.0017980185803026f,
    -0.3300299644470215f,
    -0.5998955368995667f,
    -0.6914522647857666f,
    -0.5896517634391785f,
    -0.3778679668903351f,
    -0.1557840555906296f,
    0.0453133136034012f
  };
  
  for (int i = 0; i < 10; i++) {
    ASSERT(test_eq(GLM(perlin_vec2)(p1[i]), e[i]));
  }

  TEST_SUCCESS
}




