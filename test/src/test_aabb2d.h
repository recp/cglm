/*
 * Copyright (c), Recep Aslantas.
 *
 * MIT License (MIT), http://opensource.org/licenses/MIT
 * Full license can be found in the LICENSE file
 */

#include "test_common.h"

#ifndef CGLM_TEST_AABB2D_ONCE
#define CGLM_TEST_AABB2D_ONCE

/* Macros */
/* Deprecated */

#endif /* CGLM_TEST_VEC4_ONCE */

/* --- */
TEST_IMPL(GLM_PREFIX, aabb2d_sizev) {
  vec2 a[2] = {{10.0f, 10.0f}, {20.0f, 20.0f}};
  vec2 size = {0};

  GLM(aabb2d_sizev)(a, size);

  ASSERTIFY(test_assert_vec2_eq(size, (vec2){10.0f, 10.0f}))

  TEST_SUCCESS
}
