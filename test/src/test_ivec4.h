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
  ASSERT(v4[0] == 2)
  ASSERT(v4[1] == 3)
  ASSERT(v4[2] == 5)
  ASSERT(v4[3] == 7)

  TEST_SUCCESS
}

TEST_IMPL(GLM_PREFIX, ivec4_copy) {
  ivec4 src = {7, 5, 2, 11};
  ivec4 dst = {99, 99, 99, 99};

  GLM(ivec4_copy)(src, dst);
  ASSERT(dst[0] == 7)
  ASSERT(dst[1] == 5)
  ASSERT(dst[2] == 2)
  ASSERT(dst[3] == 11)

  TEST_SUCCESS
}

TEST_IMPL(GLM_PREFIX, ivec4_zero) {
  ivec4 v = {2, 3, 5, 7};

  GLM(ivec4_zero)(v);
  ASSERT(v[0] == 0)
  ASSERT(v[1] == 0)
  ASSERT(v[2] == 0)
  ASSERT(v[3] == 0)

  TEST_SUCCESS
}

TEST_IMPL(GLM_PREFIX, ivec4_one) {
  ivec4 v = {-2, 9, 12, 7};

  GLM(ivec4_one)(v);
  ASSERT(v[0] == 1)
  ASSERT(v[1] == 1)
  ASSERT(v[2] == 1)
  ASSERT(v[3] == 1)

  TEST_SUCCESS
}

TEST_IMPL(GLM_PREFIX, ivec4_add) {
  ivec4 a = {14, 3, 2, -4};
  ivec4 b = {-3, 2, 1, -1};
  ivec4 v = {99, 99, 99, 99};

  GLM(ivec4_add)(a, b, v);
  ASSERT(v[0] == 11)
  ASSERT(v[1] == 5)
  ASSERT(v[2] == 3)
  ASSERT(v[3] == -5)

  TEST_SUCCESS
}

TEST_IMPL(GLM_PREFIX, ivec4_adds) {
  ivec4 a = {-3, 1, 4, 2};
  ivec4 v = {99, 99, 99, 99};
  int s = -2;

  GLM(ivec4_adds)(a, s, v);
  ASSERT(v[0] == -5)
  ASSERT(v[1] == -1)
  ASSERT(v[2] == 2)
  ASSERT(v[3] == 0)

  TEST_SUCCESS
}

TEST_IMPL(GLM_PREFIX, ivec4_sub) {
  ivec4 a = {-2, 9, 1, 5};
  ivec4 b = {3, 2, -1, 2};
  ivec4 v = {99, 99, 99, 99};

  GLM(ivec4_sub)(a, b, v);
  ASSERT(v[0] == -5)
  ASSERT(v[1] == 7)
  ASSERT(v[2] == 2)
  ASSERT(v[3] == 3)

  TEST_SUCCESS
}

TEST_IMPL(GLM_PREFIX, ivec4_subs) {
  ivec4 a = {5, -2, 6, 1};
  ivec4 v = {99, 99, 99, 99};
  int s = 2;

  GLM(ivec4_subs)(a, s, v);
  ASSERT(v[0] == 3)
  ASSERT(v[1] == -4)
  ASSERT(v[2] == 4)
  ASSERT(v[3] == -1)

  TEST_SUCCESS
}

TEST_IMPL(GLM_PREFIX, ivec4_mul) {
  ivec4 a = {3, 4, 5, -3};
  ivec4 b = {-2, 3, 1, 2};
  ivec4 v = {99, 99, 99, 99};

  GLM(ivec4_mul)(a, b, v);
  ASSERT(v[0] == -6)
  ASSERT(v[1] == 12)
  ASSERT(v[2] == 5)
  ASSERT(v[3] == -6)

  TEST_SUCCESS
}

TEST_IMPL(GLM_PREFIX, ivec4_scale) {
  ivec4 a = {-9, 2, 3, 0};
  ivec4 v = {99, 99, 99, 99};
  int s = -2;

  GLM(ivec4_scale)(a, s, v);
  ASSERT(v[0] == 18)
  ASSERT(v[1] == -4)
  ASSERT(v[2] == -6)
  ASSERT(v[3] == 0)

  TEST_SUCCESS
}

TEST_IMPL(GLM_PREFIX, ivec4_distance2) {
  ivec4 a = {-1, 3, 0, 4};
  ivec4 b = {5, 4, 2, 6};
  int v;

  v = GLM(ivec4_distance2)(a, b);
  ASSERT(v == 45)

  TEST_SUCCESS
}

TEST_IMPL(GLM_PREFIX, ivec4_distance) {
  ivec4 a = {3, 2, 4, -1};
  ivec4 b = {-2, 5, 2, 4};
  float v;

  v = GLM(ivec4_distance)(a, b);
  ASSERT(test_eq(v, 7.9372539331f))

  TEST_SUCCESS
}

TEST_IMPL(GLM_PREFIX, ivec4_maxv) {
  ivec4 a = {9, -20, 5, -3};
  ivec4 b = {8, -1, 2, 2};
  ivec4 v = {99, 99, 99, 99};

  GLM(ivec4_maxv)(a, b, v);
  ASSERT(v[0] == 9)
  ASSERT(v[1] == -1)
  ASSERT(v[2] == 5)
  ASSERT(v[3] == 2)

  TEST_SUCCESS
}

TEST_IMPL(GLM_PREFIX, ivec4_minv) {
  ivec4 a = {16, 0, 4, 5};
  ivec4 b = {-15, 10, 8, 2};
  ivec4 v = {99, 99, 99, 99};

  GLM(ivec4_minv)(a, b, v);
  ASSERT(v[0] == -15)
  ASSERT(v[1] == 0)
  ASSERT(v[2] == 4)
  ASSERT(v[3] == 2)

  TEST_SUCCESS
}

TEST_IMPL(GLM_PREFIX, ivec4_clamp) {
  ivec4 v = {3, -1, 10, -100};

  GLM(ivec4_clamp)(v, -2, 4);
  ASSERT(v[0] == 3)
  ASSERT(v[1] == -1)
  ASSERT(v[2] == 4)
  ASSERT(v[3] == -2)

  v[0] = -15;
  v[1] = 4;
  v[2] = 1;
  v[3] = 0;
  GLM(ivec4_clamp)(v, -9, 3);
  ASSERT(v[0] == -9)
  ASSERT(v[1] == 3)
  ASSERT(v[2] == 1)
  ASSERT(v[3] == 0)

  TEST_SUCCESS
}

TEST_IMPL(GLM_PREFIX, ivec4_abs) {
  ivec4  v1 = {2, -3, 4, -5}, v2 = {-12, -31, -42, -50};
  ivec4  v3, v4;

  GLM(ivec4_abs)(v1, v3);
  GLM(ivec4_abs)(v2, v4);

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
