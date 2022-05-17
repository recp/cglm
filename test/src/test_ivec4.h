/*
 * Copyright (c), Recep Aslantas.
 *
 * MIT License (MIT), http://opensource.org/licenses/MIT
 * Full license can be found in the LICENSE file
 */

#include "test_common.h"

TEST_IMPL(GLM_PREFIX, ivec4) {
  ivec3 v3 = {2, 3, 5};
  ivec4 v4;

  GLM(ivec4)(v3, 7, v4);
  ASSERT(test_eq(v4[0], v3[0]))
  ASSERT(test_eq(v4[1], v3[1]))
  ASSERT(test_eq(v4[2], v3[2]))
  ASSERT(test_eq(v4[3], 7))

  TEST_SUCCESS
}
