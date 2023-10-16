/*
 * Copyright (c), Recep Aslantas.
 *
 * MIT License (MIT), http://opensource.org/licenses/MIT
 * Full license can be found in the LICENSE file
 */

#include "test_common.h"

TEST_IMPL(GLM_PREFIX, uhvec3) {
  uhvec4 v4 = {2, 3, 5, 7};
  uhvec3 v3 = {99, 99, 99};

  GLM(uhvec3)(v4, v3);
  ASSERT(v3[0] == 2)
  ASSERT(v3[1] == 3)
  ASSERT(v3[2] == 5)

  TEST_SUCCESS
}

TEST_IMPL(GLM_PREFIX, uhvec3_copy) {
  uhvec3 src = {7, 5, 2};
  uhvec3 dst = {99, 99, 99};

  GLM(uhvec3_copy)(src, dst);
  ASSERT(dst[0] == 7)
  ASSERT(dst[1] == 5)
  ASSERT(dst[2] == 2)

  TEST_SUCCESS
}

TEST_IMPL(GLM_PREFIX, uhvec3_zero) {
  uhvec3 v = {2, 3, 5};

  GLM(uhvec3_zero)(v);
  ASSERT(v[0] == 0)
  ASSERT(v[1] == 0)
  ASSERT(v[2] == 0)

  TEST_SUCCESS
}

TEST_IMPL(GLM_PREFIX, uhvec3_one) {
  uhvec3 v = {-2, 9, 12};

  GLM(uhvec3_one)(v);
  ASSERT(v[0] == 1)
  ASSERT(v[1] == 1)
  ASSERT(v[2] == 1)

  TEST_SUCCESS
}

TEST_IMPL(GLM_PREFIX, uhvec3_add) {
  uhvec3 a = {14, 3, 2};
  uhvec3 b = {-3, 2, 1};
  uhvec3 v = {99, 99, 99};

  GLM(uhvec3_add)(a, b, v);
  ASSERT(v[0] == 11)
  ASSERT(v[1] == 5)
  ASSERT(v[2] == 3)

  TEST_SUCCESS
}

TEST_IMPL(GLM_PREFIX, uhvec3_adds) {
  uhvec3 a = {-3, 1, 4};
  uhvec3 v = {99, 99, 99};
  uint16_t s = 2;

  GLM(uhvec3_adds)(a, s, v);
  ASSERT(v[0] == -1)
  ASSERT(v[1] == 3)
  ASSERT(v[2] == 6)

  TEST_SUCCESS
}

TEST_IMPL(GLM_PREFIX, uhvec3_sub) {
  uhvec3 a = {-2, 9, 1};
  uhvec3 b = {3, 2, -1};
  uhvec3 v = {99, 99, 99};

  GLM(uhvec3_sub)(a, b, v);
  ASSERT(v[0] == -5)
  ASSERT(v[1] == 7)
  ASSERT(v[2] == 2)

  TEST_SUCCESS
}

TEST_IMPL(GLM_PREFIX, uhvec3_subs) {
  uhvec3 a = {5, -2, 6};
  uhvec3 v = {99, 99, 99};
  uint16_t s = -3;

  GLM(uhvec3_subs)(a, s, v);
  ASSERT(v[0] == 8)
  ASSERT(v[1] == 1)
  ASSERT(v[2] == 9)

  TEST_SUCCESS
}

TEST_IMPL(GLM_PREFIX, uhvec3_mul) {
  uhvec3 a = {3, 4, 5};
  uhvec3 b = {-2, 3, 1};
  uhvec3 v = {99, 99, 99};

  GLM(uhvec3_mul)(a, b, v);
  ASSERT(v[0] == -6)
  ASSERT(v[1] == 12)
  ASSERT(v[2] == 5)

  TEST_SUCCESS
}

TEST_IMPL(GLM_PREFIX, uhvec3_scale) {
  uhvec3 a = {-9, 2, 3};
  uhvec3 v = {99, 99, 99};
  uint16_t s = -2;

  GLM(uhvec3_scale)(a, s, v);
  ASSERT(v[0] == 18)
  ASSERT(v[1] == -4)
  ASSERT(v[2] == -6)

  TEST_SUCCESS
}

TEST_IMPL(GLM_PREFIX, uhvec3_distance2) {
  uhvec3 a = {-1, 3, 0};
  uhvec3 b = {5, 4, 2};
  uint16_t v;

  v = GLM(uhvec3_distance2)(a, b);
  ASSERT(v == 41)

  TEST_SUCCESS
}

TEST_IMPL(GLM_PREFIX, uhvec3_distance) {
  uhvec3 a = {3, 2, 4};
  uhvec3 b = {-2, 5, 2};
  float v;

  v = GLM(uhvec3_distance)(a, b);
  ASSERT(test_eq(v, 6.1644140029f))

  TEST_SUCCESS
}

TEST_IMPL(GLM_PREFIX, uhvec3_fill) {
  uhvec3 v1;
  uhvec3 v2 = {-1, 3, 4};

  GLM(uhvec3_fill)(v1, 1);
  GLM(uhvec3_fill)(v2, 2);

  ASSERT(GLM(uhvec3_eq)(v1, 1))
  ASSERT(GLM(uhvec3_eq)(v2, 2))

  TEST_SUCCESS
}

TEST_IMPL(GLM_PREFIX, uhvec3_eq) {
  uhvec3 v1 = { -1, 2, 4 };

  GLM(uhvec3_fill)(v1, 2);

  ASSERT(GLM(uhvec3_eq)(v1, 2))

  TEST_SUCCESS
}

TEST_IMPL(GLM_PREFIX, uhvec3_eqv) {
  uhvec3 v1, v2, v3;

  GLM(uhvec3_fill)(v1, 1);
  GLM(uhvec3_fill)(v2, 2);
  GLM(uhvec3_fill)(v3, 1);

  ASSERT(GLM(uhvec3_eqv)(v1, v3))
  ASSERT(!GLM(uhvec3_eqv)(v1, v2))

  TEST_SUCCESS
}

TEST_IMPL(GLM_PREFIX, uhvec3_maxv) {
  uhvec3 a = {9, -20, 5};
  uhvec3 b = {8, -1, 2};
  uhvec3 v = {99, 99, 99};

  GLM(uhvec3_maxv)(a, b, v);
  ASSERT(v[0] == 9)
  ASSERT(v[1] == -1)
  ASSERT(v[2] == 5)

  TEST_SUCCESS
}

TEST_IMPL(GLM_PREFIX, uhvec3_minv) {
  uhvec3 a = {16, 0, 4};
  uhvec3 b = {-15, 10, 8};
  uhvec3 v = {99, 99, 99};

  GLM(uhvec3_minv)(a, b, v);
  ASSERT(v[0] == -15)
  ASSERT(v[1] == 0)
  ASSERT(v[2] == 4)

  TEST_SUCCESS
}

TEST_IMPL(GLM_PREFIX, uhvec3_clamp) {
  uhvec3 v = {3, -1, 10};

  GLM(uhvec3_clamp)(v, -2, 4);
  ASSERT(v[0] == 3)
  ASSERT(v[1] == -1)
  ASSERT(v[2] == 4)

  v[0] = -15;
  v[1] = 4;
  v[2] = 1;
  GLM(uhvec3_clamp)(v, -9, 3);
  ASSERT(v[0] == -9)
  ASSERT(v[1] == 3)
  ASSERT(v[2] == 1)

  TEST_SUCCESS
}

TEST_IMPL(GLM_PREFIX, uhvec3_abs) {
  uhvec3  v1 = {2, -3, 4}, v2 = {-12, -31, -42};
  uhvec3  v3, v4;

  GLM(uhvec3_abs)(v1, v3);
  GLM(uhvec3_abs)(v2, v4);

  ASSERT(v3[0] == 2)
  ASSERT(v3[1] == 3)
  ASSERT(v3[2] == 4)
  ASSERT(v4[0] == 12)
  ASSERT(v4[1] == 31)
  ASSERT(v4[2] == 42)

  TEST_SUCCESS
}
