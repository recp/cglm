/*
 * Copyright (c), Recep Aslantas.
 *
 * MIT License (MIT), http://opensource.org/licenses/MIT
 * Full license can be found in the LICENSE file
 */

#include "test_common.h"

TEST_IMPL(GLM_PREFIX, uvec4) {
  uvec3 v3 = {2, 3, 5};
  uvec4 v4;

  GLM(uvec4)(v3, 7, v4);
  ASSERT(v4[0] == 2)
  ASSERT(v4[1] == 3)
  ASSERT(v4[2] == 5)
  ASSERT(v4[3] == 7)

  TEST_SUCCESS
}

TEST_IMPL(GLM_PREFIX, uvec4_copy) {
  uvec4 src = {7, 5, 2, 11};
  uvec4 dst = {99, 99, 99, 99};

  GLM(uvec4_copy)(src, dst);
  ASSERT(dst[0] == 7)
  ASSERT(dst[1] == 5)
  ASSERT(dst[2] == 2)
  ASSERT(dst[3] == 11)

  TEST_SUCCESS
}

TEST_IMPL(GLM_PREFIX, uvec4_zero) {
  uvec4 v = {2, 3, 5, 7};

  GLM(uvec4_zero)(v);
  ASSERT(v[0] == 0)
  ASSERT(v[1] == 0)
  ASSERT(v[2] == 0)
  ASSERT(v[3] == 0)

  TEST_SUCCESS
}

TEST_IMPL(GLM_PREFIX, uvec4_one) {
  uvec4 v = {-2, 9, 12, 7};

  GLM(uvec4_one)(v);
  ASSERT(v[0] == 1)
  ASSERT(v[1] == 1)
  ASSERT(v[2] == 1)
  ASSERT(v[3] == 1)

  TEST_SUCCESS
}

TEST_IMPL(GLM_PREFIX, uvec4_add) {
  uvec4 a = {14, 3, 2, -4};
  uvec4 b = {-3, 2, 1, -1};
  uvec4 v = {99, 99, 99, 99};

  GLM(uvec4_add)(a, b, v);
  ASSERT(v[0] == 11)
  ASSERT(v[1] == 5)
  ASSERT(v[2] == 3)
  ASSERT(v[3] == -5)

  TEST_SUCCESS
}

TEST_IMPL(GLM_PREFIX, uvec4_adds) {
  uvec4 a = {-3, 1, 4, 2};
  uvec4 v = {99, 99, 99, 99};
  uint32_t s = -2;

  GLM(uvec4_adds)(a, s, v);
  ASSERT(v[0] == -5)
  ASSERT(v[1] == -1)
  ASSERT(v[2] == 2)
  ASSERT(v[3] == 0)

  TEST_SUCCESS
}

TEST_IMPL(GLM_PREFIX, uvec4_sub) {
  uvec4 a = {-2, 9, 1, 5};
  uvec4 b = {3, 2, -1, 2};
  uvec4 v = {99, 99, 99, 99};

  GLM(uvec4_sub)(a, b, v);
  ASSERT(v[0] == -5)
  ASSERT(v[1] == 7)
  ASSERT(v[2] == 2)
  ASSERT(v[3] == 3)

  TEST_SUCCESS
}

TEST_IMPL(GLM_PREFIX, uvec4_subs) {
  uvec4 a = {5, -2, 6, 1};
  uvec4 v = {99, 99, 99, 99};
  uint32_t s = 2;

  GLM(uvec4_subs)(a, s, v);
  ASSERT(v[0] == 3)
  ASSERT(v[1] == -4)
  ASSERT(v[2] == 4)
  ASSERT(v[3] == -1)

  TEST_SUCCESS
}

TEST_IMPL(GLM_PREFIX, uvec4_mul) {
  uvec4 a = {3, 4, 5, -3};
  uvec4 b = {-2, 3, 1, 2};
  uvec4 v = {99, 99, 99, 99};

  GLM(uvec4_mul)(a, b, v);
  ASSERT(v[0] == -6)
  ASSERT(v[1] == 12)
  ASSERT(v[2] == 5)
  ASSERT(v[3] == -6)

  TEST_SUCCESS
}

TEST_IMPL(GLM_PREFIX, uvec4_scale) {
  uvec4 a = {-9, 2, 3, 0};
  uvec4 v = {99, 99, 99, 99};
  uint32_t s = -2;

  GLM(uvec4_scale)(a, s, v);
  ASSERT(v[0] == 18)
  ASSERT(v[1] == -4)
  ASSERT(v[2] == -6)
  ASSERT(v[3] == 0)

  TEST_SUCCESS
}

TEST_IMPL(GLM_PREFIX, uvec4_distance2) {
  uvec4 a = {-1, 3, 0, 4};
  uvec4 b = {5, 4, 2, 6};
  uint32_t v;

  v = GLM(uvec4_distance2)(a, b);
  ASSERT(v == 45)

  TEST_SUCCESS
}

TEST_IMPL(GLM_PREFIX, uvec4_distance) {
  uvec4 a = {3, 2, 4, -1};
  uvec4 b = {-2, 5, 2, 4};
  float v;

  v = GLM(uvec4_distance)(a, b);
  ASSERT(test_eq(v, 7.9372539331f))

  TEST_SUCCESS
}

TEST_IMPL(GLM_PREFIX, uvec4_maxv) {
  uvec4 a = {9, -20, 5, -3};
  uvec4 b = {8, -1, 2, 2};
  uvec4 v = {99, 99, 99, 99};

  GLM(uvec4_maxv)(a, b, v);
  ASSERT(v[0] == 9)
  ASSERT(v[1] == -1)
  ASSERT(v[2] == 5)
  ASSERT(v[3] == 2)

  TEST_SUCCESS
}

TEST_IMPL(GLM_PREFIX, uvec4_minv) {
  uvec4 a = {16, 0, 4, 5};
  uvec4 b = {-15, 10, 8, 2};
  uvec4 v = {99, 99, 99, 99};

  GLM(uvec4_minv)(a, b, v);
  ASSERT(v[0] == -15)
  ASSERT(v[1] == 0)
  ASSERT(v[2] == 4)
  ASSERT(v[3] == 2)

  TEST_SUCCESS
}

TEST_IMPL(GLM_PREFIX, uvec4_clamp) {
  uvec4 v = {3, -1, 10, -100};

  GLM(uvec4_clamp)(v, -2, 4);
  ASSERT(v[0] == 3)
  ASSERT(v[1] == -1)
  ASSERT(v[2] == 4)
  ASSERT(v[3] == -2)

  v[0] = -15;
  v[1] = 4;
  v[2] = 1;
  v[3] = 0;
  GLM(uvec4_clamp)(v, -9, 3);
  ASSERT(v[0] == -9)
  ASSERT(v[1] == 3)
  ASSERT(v[2] == 1)
  ASSERT(v[3] == 0)

  TEST_SUCCESS
}

TEST_IMPL(GLM_PREFIX, uvec4_abs) {
  uvec4  v1 = {2, -3, 4, -5}, v2 = {-12, -31, -42, -50};
  uvec4  v3, v4;

  GLM(uvec4_abs)(v1, v3);
  GLM(uvec4_abs)(v2, v4);

  ASSERT(v3[0] == 2)
  ASSERT(v3[1] == 3)
  ASSERT(v3[2] == 4)
  ASSERT(v3[3] == 5)
  ASSERT(v4[0] == 12)
  ASSERT(v4[1] == 31)
  ASSERT(v4[2] == 42)
  ASSERT(v4[3] == 50)

  TEST_SUCCESS
}
