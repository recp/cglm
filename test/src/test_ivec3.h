/*
 * Copyright (c), Recep Aslantas.
 *
 * MIT License (MIT), http://opensource.org/licenses/MIT
 * Full license can be found in the LICENSE file
 */

#include "test_common.h"

TEST_IMPL(GLM_PREFIX, ivec3) {
  ivec4 v4 = {2, 3, 5, 7};
  ivec3 v3;

  GLM(ivec3)(v4, v3);
  ASSERT(test_eq(v3[0], v4[0]))
  ASSERT(test_eq(v3[1], v4[1]))
  ASSERT(test_eq(v3[2], v4[2]))

  TEST_SUCCESS
}
