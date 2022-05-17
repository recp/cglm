/*
 * Copyright (c), Recep Aslantas.
 *
 * MIT License (MIT), http://opensource.org/licenses/MIT
 * Full license can be found in the LICENSE file
 */

#include "test_common.h"

TEST_IMPL(GLM_PREFIX, ivec2) {
  ivec4 v4 = {2, 3, 5, 7};
  ivec3 v3 = {11, 13, 17};
  ivec2 v2;

  GLM(ivec2)(v4, v2);
  ASSERT(test_eq(v2[0], v4[0]))
  ASSERT(test_eq(v2[1], v4[1]))

  GLM(ivec2)(v3, v2);
  ASSERT(test_eq(v2[0], v3[0]))
  ASSERT(test_eq(v2[1], v3[1]))

  TEST_SUCCESS
}
