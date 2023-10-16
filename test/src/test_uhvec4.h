/*
 * Copyright (c), Recep Aslantas.
 *
 * MIT License (MIT), http://opensource.org/licenses/MIT
 * Full license can be found in the LICENSE file
 */

#include "test_common.h"

TEST_IMPL(GLM_PREFIX, uhvec4) {
  uhvec3 v3 = {2, 3, 5};
  uhvec4 v4;

  GLM(uhvec4)(v3, 7, v4);
  ASSERT(v4[0] == 2)
  ASSERT(v4[1] == 3)
  ASSERT(v4[2] == 5)
  ASSERT(v4[3] == 7)

  TEST_SUCCESS
}

TEST_IMPL(GLM_PREFIX, uhvec4_copy) {
  uhvec4 src = {7, 5, 2, 11};
  uhvec4 dst = {99, 99, 99, 99};

  GLM(uhvec4_copy)(src, dst);
  ASSERT(dst[0] == 7)
  ASSERT(dst[1] == 5)
  ASSERT(dst[2] == 2)
  ASSERT(dst[3] == 11)

  TEST_SUCCESS
}

TEST_IMPL(GLM_PREFIX, uhvec4_zero) {
  uhvec4 v = {2, 3, 5, 7};

  GLM(uhvec4_zero)(v);
  ASSERT(v[0] == 0)
  ASSERT(v[1] == 0)
  ASSERT(v[2] == 0)
  ASSERT(v[3] == 0)

  TEST_SUCCESS
}

TEST_IMPL(GLM_PREFIX, uhvec4_one) {
  uhvec4 v = {-2, 9, 12, 7};

  GLM(uhvec4_one)(v);
  ASSERT(v[0] == 1)
  ASSERT(v[1] == 1)
  ASSERT(v[2] == 1)
  ASSERT(v[3] == 1)

  TEST_SUCCESS
}

TEST_IMPL(GLM_PREFIX, uhvec4_add) {
  uhvec4 a = {14, 3, 2, -4};
  uhvec4 b = {-3, 2, 1, -1};
  uhvec4 v = {99, 99, 99, 99};

  GLM(uhvec4_add)(a, b, v);
  ASSERT(v[0] == 11)
  ASSERT(v[1] == 5)
  ASSERT(v[2] == 3)
  ASSERT(v[3] == -5)

  TEST_SUCCESS
}

TEST_IMPL(GLM_PREFIX, uhvec4_adds) {
  uhvec4 a = {-3, 1, 4, 2};
  uhvec4 v = {99, 99, 99, 99};
  uint16_t s = -2;

  GLM(uhvec4_adds)(a, s, v);
  ASSERT(v[0] == -5)
  ASSERT(v[1] == -1)
  ASSERT(v[2] == 2)
  ASSERT(v[3] == 0)

  TEST_SUCCESS
}

TEST_IMPL(GLM_PREFIX, uhvec4_sub) {
  uhvec4 a = {-2, 9, 1, 5};
  uhvec4 b = {3, 2, -1, 2};
  uhvec4 v = {99, 99, 99, 99};

  GLM(uhvec4_sub)(a, b, v);
  ASSERT(v[0] == -5)
  ASSERT(v[1] == 7)
  ASSERT(v[2] == 2)
  ASSERT(v[3] == 3)

  TEST_SUCCESS
}

TEST_IMPL(GLM_PREFIX, uhvec4_subs) {
  uhvec4 a = {5, -2, 6, 1};
  uhvec4 v = {99, 99, 99, 99};
  uint16_t s = 2;

  GLM(uhvec4_subs)(a, s, v);
  ASSERT(v[0] == 3)
  ASSERT(v[1] == -4)
  ASSERT(v[2] == 4)
  ASSERT(v[3] == -1)

  TEST_SUCCESS
}

TEST_IMPL(GLM_PREFIX, uhvec4_mul) {
  uhvec4 a = {3, 4, 5, -3};
  uhvec4 b = {-2, 3, 1, 2};
  uhvec4 v = {99, 99, 99, 99};

  GLM(uhvec4_mul)(a, b, v);
  ASSERT(v[0] == -6)
  ASSERT(v[1] == 12)
  ASSERT(v[2] == 5)
  ASSERT(v[3] == -6)

  TEST_SUCCESS
}

TEST_IMPL(GLM_PREFIX, uhvec4_scale) {
  uhvec4 a = {-9, 2, 3, 0};
  uhvec4 v = {99, 99, 99, 99};
  uint16_t s = -2;

  GLM(uhvec4_scale)(a, s, v);
  ASSERT(v[0] == 18)
  ASSERT(v[1] == -4)
  ASSERT(v[2] == -6)
  ASSERT(v[3] == 0)

  TEST_SUCCESS
}

TEST_IMPL(GLM_PREFIX, uhvec4_distance2) {
  uhvec4 a = {-1, 3, 0, 4};
  uhvec4 b = {5, 4, 2, 6};
  uint16_t v;

  v = GLM(uhvec4_distance2)(a, b);
  ASSERT(v == 45)

  TEST_SUCCESS
}

TEST_IMPL(GLM_PREFIX, uhvec4_distance) {
  uhvec4 a = {3, 2, 4, -1};
  uhvec4 b = {-2, 5, 2, 4};
  float v;

  v = GLM(uhvec4_distance)(a, b);
  ASSERT(test_eq(v, 7.9372539331f))

  TEST_SUCCESS
}

TEST_IMPL(GLM_PREFIX, uhvec4_maxv) {
  uhvec4 a = {9, -20, 5, -3};
  uhvec4 b = {8, -1, 2, 2};
  uhvec4 v = {99, 99, 99, 99};

  GLM(uhvec4_maxv)(a, b, v);
  ASSERT(v[0] == 9)
  ASSERT(v[1] == -1)
  ASSERT(v[2] == 5)
  ASSERT(v[3] == 2)

  TEST_SUCCESS
}

TEST_IMPL(GLM_PREFIX, uhvec4_minv) {
  uhvec4 a = {16, 0, 4, 5};
  uhvec4 b = {-15, 10, 8, 2};
  uhvec4 v = {99, 99, 99, 99};

  GLM(uhvec4_minv)(a, b, v);
  ASSERT(v[0] == -15)
  ASSERT(v[1] == 0)
  ASSERT(v[2] == 4)
  ASSERT(v[3] == 2)

  TEST_SUCCESS
}

TEST_IMPL(GLM_PREFIX, uhvec4_clamp) {
  uhvec4 v = {3, -1, 10, -100};

  GLM(uhvec4_clamp)(v, -2, 4);
  ASSERT(v[0] == 3)
  ASSERT(v[1] == -1)
  ASSERT(v[2] == 4)
  ASSERT(v[3] == -2)

  v[0] = -15;
  v[1] = 4;
  v[2] = 1;
  v[3] = 0;
  GLM(uhvec4_clamp)(v, -9, 3);
  ASSERT(v[0] == -9)
  ASSERT(v[1] == 3)
  ASSERT(v[2] == 1)
  ASSERT(v[3] == 0)

  TEST_SUCCESS
}

TEST_IMPL(GLM_PREFIX, uhvec4_abs) {
  uhvec4  v1 = {2, -3, 4, -5}, v2 = {-12, -31, -42, -50};
  uhvec4  v3, v4;

  GLM(uhvec4_abs)(v1, v3);
  GLM(uhvec4_abs)(v2, v4);

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
