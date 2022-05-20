/*
 * Copyright (c), Recep Aslantas.
 *
 * MIT License (MIT), http://opensource.org/licenses/MIT
 * Full license can be found in the LICENSE file
 */

#include "test_common.h"

TEST_IMPL(GLM_PREFIX, ivec3) {
  ivec4 v4 = {2, 3, 5, 7};
  ivec3 v3 = {99, 99, 99};

  GLM(ivec3)(v4, v3);
  ASSERT(v3[0] == 2)
  ASSERT(v3[1] == 3)
  ASSERT(v3[2] == 5)

  TEST_SUCCESS
}

TEST_IMPL(GLM_PREFIX, ivec3_copy) {
  ivec3 src = {7, 5, 2};
  ivec3 dst = {99, 99, 99};

  GLM(ivec3_copy)(src, dst);
  ASSERT(dst[0] == 7)
  ASSERT(dst[1] == 5)
  ASSERT(dst[2] == 2)

  TEST_SUCCESS
}

TEST_IMPL(GLM_PREFIX, ivec3_zero) {
  ivec3 v = {2, 3, 5};

  GLM(ivec3_zero)(v);
  ASSERT(v[0] == 0)
  ASSERT(v[1] == 0)
  ASSERT(v[2] == 0)

  TEST_SUCCESS
}

TEST_IMPL(GLM_PREFIX, ivec3_one) {
  ivec3 v = {-2, 9, 12};

  GLM(ivec3_one)(v);
  ASSERT(v[0] == 1)
  ASSERT(v[1] == 1)
  ASSERT(v[2] == 1)

  TEST_SUCCESS
}

TEST_IMPL(GLM_PREFIX, ivec3_add) {
  ivec3 a = {14, 3, 2};
  ivec3 b = {-3, 2, 1};
  ivec3 v = {99, 99, 99};

  GLM(ivec3_add)(a, b, v);
  ASSERT(v[0] == 11)
  ASSERT(v[1] == 5)
  ASSERT(v[2] == 3)

  TEST_SUCCESS
}

TEST_IMPL(GLM_PREFIX, ivec3_adds) {
  ivec3 a = {-3, 1, 4};
  ivec3 v = {99, 99, 99};
  int s = 2;

  GLM(ivec3_adds)(a, s, v);
  ASSERT(v[0] == -1)
  ASSERT(v[1] == 3)
  ASSERT(v[2] == 6)

  TEST_SUCCESS
}

TEST_IMPL(GLM_PREFIX, ivec3_sub) {
  ivec3 a = {-2, 9, 1};
  ivec3 b = {3, 2, -1};
  ivec3 v = {99, 99, 99};

  GLM(ivec3_sub)(a, b, v);
  ASSERT(v[0] == -5)
  ASSERT(v[1] == 7)
  ASSERT(v[2] == 2)

  TEST_SUCCESS
}

TEST_IMPL(GLM_PREFIX, ivec3_subs) {
  ivec3 a = {5, -2, 6};
  ivec3 v = {99, 99, 99};
  int s = -3;

  GLM(ivec3_subs)(a, s, v);
  ASSERT(v[0] == 8)
  ASSERT(v[1] == 1)
  ASSERT(v[2] == 9)

  TEST_SUCCESS
}

TEST_IMPL(GLM_PREFIX, ivec3_mul) {
  ivec3 a = {3, 4, 5};
  ivec3 b = {-2, 3, 1};
  ivec3 v = {99, 99, 99};

  GLM(ivec3_mul)(a, b, v);
  ASSERT(v[0] == -6)
  ASSERT(v[1] == 12)
  ASSERT(v[2] == 5)

  TEST_SUCCESS
}

TEST_IMPL(GLM_PREFIX, ivec3_scale) {
  ivec3 a = {-9, 2, 3};
  ivec3 v = {99, 99, 99};
  int s = -2;

  GLM(ivec3_scale)(a, s, v);
  ASSERT(v[0] == 18)
  ASSERT(v[1] == -4)
  ASSERT(v[2] == -6)

  TEST_SUCCESS
}

TEST_IMPL(GLM_PREFIX, ivec3_distance2) {
  ivec3 a = {-1, 3, 0};
  ivec3 b = {5, 4, 2};
  int v;

  v = GLM(ivec3_distance2)(a, b);
  ASSERT(v == 41)

  TEST_SUCCESS
}

TEST_IMPL(GLM_PREFIX, ivec3_distance) {
  ivec3 a = {3, 2, 4};
  ivec3 b = {-2, 5, 2};
  float v;

  v = GLM(ivec3_distance)(a, b);
  ASSERT(test_eq(v, 6.1644140029))

  TEST_SUCCESS
}

TEST_IMPL(GLM_PREFIX, ivec3_maxv) {
  ivec3 a = {9, -20, 5};
  ivec3 b = {8, -1, 2};
  ivec3 v = {99, 99, 99};

  GLM(ivec3_maxv)(a, b, v);
  ASSERT(v[0] == 9)
  ASSERT(v[1] == -1)
  ASSERT(v[2] == 5)

  TEST_SUCCESS
}

TEST_IMPL(GLM_PREFIX, ivec3_minv) {
  ivec3 a = {16, 0, 4};
  ivec3 b = {-15, 10, 8};
  ivec3 v = {99, 99, 99};

  GLM(ivec3_minv)(a, b, v);
  ASSERT(v[0] == -15)
  ASSERT(v[1] == 0)
  ASSERT(v[2] == 4)

  TEST_SUCCESS
}

TEST_IMPL(GLM_PREFIX, ivec3_clamp) {
  ivec3 v = {3, -1, 10};

  GLM(ivec3_clamp)(v, -2, 4);
  ASSERT(v[0] == 3)
  ASSERT(v[1] == -1)
  ASSERT(v[2] == 4)

  v[0] = -15;
  v[1] = 4;
  v[2] = 1;
  GLM(ivec3_clamp)(v, -9, 3);
  ASSERT(v[0] == -9)
  ASSERT(v[1] == 3)
  ASSERT(v[2] == 1)

  TEST_SUCCESS
}
