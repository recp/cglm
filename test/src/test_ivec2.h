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
  ASSERT(v2[0] == 2)
  ASSERT(v2[1] == 3)

  GLM(ivec2)(v3, v2);
  ASSERT(v2[0] == 11)
  ASSERT(v2[1] == 13)

  TEST_SUCCESS
}

TEST_IMPL(GLM_PREFIX, ivec2_copy) {
  ivec2 src = {7, 5};
  ivec2 dst = {99, 99};

  GLM(ivec2_copy)(src, dst);
  ASSERT(dst[0] == 7)
  ASSERT(dst[1] == 5)

  TEST_SUCCESS
}

TEST_IMPL(GLM_PREFIX, ivec2_zero) {
  ivec2 v = {2, 3};

  GLM(ivec2_zero)(v);
  ASSERT(v[0] == 0)
  ASSERT(v[1] == 0)

  TEST_SUCCESS
}

TEST_IMPL(GLM_PREFIX, ivec2_one) {
  ivec2 v = {-2, 9};

  GLM(ivec2_one)(v);
  ASSERT(v[0] == 1)
  ASSERT(v[1] == 1)

  TEST_SUCCESS
}

TEST_IMPL(GLM_PREFIX, ivec2_add) {
  ivec2 a = {14, 3};
  ivec2 b = {-3, 2};
  ivec2 v = {99, 99};

  GLM(ivec2_add)(a, b, v);
  ASSERT(v[0] == 11)
  ASSERT(v[1] == 5)

  TEST_SUCCESS
}

TEST_IMPL(GLM_PREFIX, ivec2_adds) {
  ivec2 a = {-3, 1};
  ivec2 v = {99, 99};
  int s = 2;

  GLM(ivec2_adds)(a, s, v);
  ASSERT(v[0] == -1)
  ASSERT(v[1] == 3)

  TEST_SUCCESS
}

TEST_IMPL(GLM_PREFIX, ivec2_sub) {
  ivec2 a = {-2, 9};
  ivec2 b = {3, 2};
  ivec2 v = {99, 99};

  GLM(ivec2_sub)(a, b, v);
  ASSERT(v[0] == -5)
  ASSERT(v[1] == 7)

  TEST_SUCCESS
}

TEST_IMPL(GLM_PREFIX, ivec2_subs) {
  ivec2 a = {5, -2};
  ivec2 v = {99, 99};
  int s = -3;

  GLM(ivec2_subs)(a, s, v);
  ASSERT(v[0] == 8)
  ASSERT(v[1] == 1)

  TEST_SUCCESS
}

TEST_IMPL(GLM_PREFIX, ivec2_mul) {
  ivec2 a = {3, 4};
  ivec2 b = {-2, 3};
  ivec2 v = {99, 99};

  GLM(ivec2_mul)(a, b, v);
  ASSERT(v[0] == -6)
  ASSERT(v[1] == 12)

  TEST_SUCCESS
}

TEST_IMPL(GLM_PREFIX, ivec2_scale) {
  ivec2 a = {-9, 2};
  ivec2 v = {99, 99};
  int s = -2;

  GLM(ivec2_scale)(a, s, v);
  ASSERT(v[0] == 18)
  ASSERT(v[1] == -4)

  TEST_SUCCESS
}

TEST_IMPL(GLM_PREFIX, ivec2_distance2) {
  ivec2 a = {-1, 3};
  ivec2 b = {5, 4};
  int v;

  v = GLM(ivec2_distance2)(a, b);
  ASSERT(v == 37)

  TEST_SUCCESS
}

TEST_IMPL(GLM_PREFIX, ivec2_distance) {
  ivec2 a = {3, 2};
  ivec2 b = {-2, 5};
  float v;

  v = GLM(ivec2_distance)(a, b);
  ASSERT(test_eq(v, 5.8309518948))

  TEST_SUCCESS
}

TEST_IMPL(GLM_PREFIX, ivec2_maxv) {
  ivec2 a = {9, -20};
  ivec2 b = {8, -1};
  ivec2 v = {99, 99};

  GLM(ivec2_maxv)(a, b, v);
  ASSERT(v[0] == 9)
  ASSERT(v[1] == -1)

  TEST_SUCCESS
}

TEST_IMPL(GLM_PREFIX, ivec2_minv) {
  ivec2 a = {16, 0};
  ivec2 b = {-15, 10};
  ivec2 v = {99, 99};

  GLM(ivec2_minv)(a, b, v);
  ASSERT(v[0] == -15)
  ASSERT(v[1] == 0)

  TEST_SUCCESS
}

TEST_IMPL(GLM_PREFIX, ivec2_clamp) {
  ivec2 v = {3, -1};

  GLM(ivec2_clamp)(v, -2, 4);
  ASSERT(v[0] == 3)
  ASSERT(v[1] == -1)

  v[0] = -15;
  v[1] = 4;
  GLM(ivec2_clamp)(v, -9, 3);
  ASSERT(v[0] == -9)
  ASSERT(v[1] == 3)

  TEST_SUCCESS
}
