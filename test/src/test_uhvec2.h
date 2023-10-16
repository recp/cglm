/*
 * Copyright (c), Recep Aslantas.
 *
 * MIT License (MIT), http://opensource.org/licenses/MIT
 * Full license can be found in the LICENSE file
 */

#include "test_common.h"

TEST_IMPL(GLM_PREFIX, uhvec2) {
  uhvec4 v4 = {2, 3, 5, 7};
  uhvec3 v3 = {11, 13, 17};
  uhvec2 v2;

  GLM(uhvec2)(v4, v2);
  ASSERT(v2[0] == 2)
  ASSERT(v2[1] == 3)

  GLM(uhvec2)(v3, v2);
  ASSERT(v2[0] == 11)
  ASSERT(v2[1] == 13)

  TEST_SUCCESS
}

TEST_IMPL(GLM_PREFIX, uhvec2_copy) {
  uhvec2 src = {7, 5};
  uhvec2 dst = {99, 99};

  GLM(uhvec2_copy)(src, dst);
  ASSERT(dst[0] == 7)
  ASSERT(dst[1] == 5)

  TEST_SUCCESS
}

TEST_IMPL(GLM_PREFIX, uhvec2_zero) {
  uhvec2 v = {2, 3};

  GLM(uhvec2_zero)(v);
  ASSERT(v[0] == 0)
  ASSERT(v[1] == 0)

  TEST_SUCCESS
}

TEST_IMPL(GLM_PREFIX, uhvec2_one) {
  uhvec2 v = {-2, 9};

  GLM(uhvec2_one)(v);
  ASSERT(v[0] == 1)
  ASSERT(v[1] == 1)

  TEST_SUCCESS
}

TEST_IMPL(GLM_PREFIX, uhvec2_add) {
  uhvec2 a = {14, 3};
  uhvec2 b = {-3, 2};
  uhvec2 v = {99, 99};

  GLM(uhvec2_add)(a, b, v);
  ASSERT(v[0] == 11)
  ASSERT(v[1] == 5)

  TEST_SUCCESS
}

TEST_IMPL(GLM_PREFIX, uhvec2_adds) {
  uhvec2 a = {-3, 1};
  uhvec2 v = {99, 99};
  uint16_t s = 2;

  GLM(uhvec2_adds)(a, s, v);
  ASSERT(v[0] == -1)
  ASSERT(v[1] == 3)

  TEST_SUCCESS
}

TEST_IMPL(GLM_PREFIX, uhvec2_sub) {
  uhvec2 a = {-2, 9};
  uhvec2 b = {3, 2};
  uhvec2 v = {99, 99};

  GLM(uhvec2_sub)(a, b, v);
  ASSERT(v[0] == -5)
  ASSERT(v[1] == 7)

  TEST_SUCCESS
}

TEST_IMPL(GLM_PREFIX, uhvec2_subs) {
  uhvec2 a = {5, -2};
  uhvec2 v = {99, 99};
  uint16_t s = -3;

  GLM(uhvec2_subs)(a, s, v);
  ASSERT(v[0] == 8)
  ASSERT(v[1] == 1)

  TEST_SUCCESS
}

TEST_IMPL(GLM_PREFIX, uhvec2_mul) {
  uhvec2 a = {3, 4};
  uhvec2 b = {-2, 3};
  uhvec2 v = {99, 99};

  GLM(uhvec2_mul)(a, b, v);
  ASSERT(v[0] == -6)
  ASSERT(v[1] == 12)

  TEST_SUCCESS
}

TEST_IMPL(GLM_PREFIX, uhvec2_scale) {
  uhvec2 a = {-9, 2};
  uhvec2 v = {99, 99};
  uint16_t s = -2;

  GLM(uhvec2_scale)(a, s, v);
  ASSERT(v[0] == 18)
  ASSERT(v[1] == -4)

  TEST_SUCCESS
}

TEST_IMPL(GLM_PREFIX, uhvec2_distance2) {
  uhvec2 a = {-1, 3};
  uhvec2 b = {5, 4};
  uint16_t v;

  v = GLM(uhvec2_distance2)(a, b);
  ASSERT(v == 37)

  TEST_SUCCESS
}

TEST_IMPL(GLM_PREFIX, uhvec2_distance) {
  uhvec2 a = {3, 2};
  uhvec2 b = {-2, 5};
  float v;

  v = GLM(uhvec2_distance)(a, b);
  ASSERT(test_eq(v, 5.8309518948f))

  TEST_SUCCESS
}

TEST_IMPL(GLM_PREFIX, uhvec2_fill) {
  uhvec2 v1;
  uhvec2 v2 = {-1, 3};

  GLM(uhvec2_fill)(v1, 1);
  GLM(uhvec2_fill)(v2, 2);

  ASSERT(GLM(uhvec2_eq)(v1, 1))
  ASSERT(GLM(uhvec2_eq)(v2, 2))

  TEST_SUCCESS
}

TEST_IMPL(GLM_PREFIX, uhvec2_eq) {
  uhvec2 v1 = {-1, 2};

  GLM(uhvec2_fill)(v1, 2);

  ASSERT(GLM(uhvec2_eq)(v1, 2))

  TEST_SUCCESS
}

TEST_IMPL(GLM_PREFIX, uhvec2_eqv) {
  uhvec2 v1, v2, v3;

  GLM(uhvec2_fill)(v1, 1);
  GLM(uhvec2_fill)(v2, 2);
  GLM(uhvec2_fill)(v3, 1);

  ASSERT(GLM(uhvec2_eqv)(v1, v3))
  ASSERT(!GLM(uhvec2_eqv)(v1, v2))

  TEST_SUCCESS
}

TEST_IMPL(GLM_PREFIX, uhvec2_maxv) {
  uhvec2 a = {9, -20};
  uhvec2 b = {8, -1};
  uhvec2 v = {99, 99};

  GLM(uhvec2_maxv)(a, b, v);
  ASSERT(v[0] == 9)
  ASSERT(v[1] == -1)

  TEST_SUCCESS
}

TEST_IMPL(GLM_PREFIX, uhvec2_minv) {
  uhvec2 a = {16, 0};
  uhvec2 b = {-15, 10};
  uhvec2 v = {99, 99};

  GLM(uhvec2_minv)(a, b, v);
  ASSERT(v[0] == -15)
  ASSERT(v[1] == 0)

  TEST_SUCCESS
}

TEST_IMPL(GLM_PREFIX, uhvec2_clamp) {
  uhvec2 v = {3, -1};

  GLM(uhvec2_clamp)(v, -2, 4);
  ASSERT(v[0] == 3)
  ASSERT(v[1] == -1)

  v[0] = -15;
  v[1] = 4;
  GLM(uhvec2_clamp)(v, -9, 3);
  ASSERT(v[0] == -9)
  ASSERT(v[1] == 3)

  TEST_SUCCESS
}

TEST_IMPL(GLM_PREFIX, uhvec2_abs) {
  uhvec2  v1 = {2, -3}, v2 = {-12, -31};
  uhvec2  v3, v4;

  GLM(uhvec2_abs)(v1, v3);
  GLM(uhvec2_abs)(v2, v4);

  ASSERT(v3[0] == 2)
  ASSERT(v3[1] == 3)
  ASSERT(v4[0] == 12)
  ASSERT(v4[1] == 31)

  TEST_SUCCESS
}
