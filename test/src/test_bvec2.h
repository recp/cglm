/*
 * Copyright (c), Recep Aslantas.
 *
 * MIT License (MIT), http://opensource.org/licenses/MIT
 * Full license can be found in the LICENSE file
 */

#include "test_common.h"

TEST_IMPL(GLM_PREFIX, bvec2) {
  bvec4 v4 = {2, 3, 5, 7};
  bvec3 v3 = {11, 13, 17};
  bvec2 v2;

  GLM(bvec2)(v4, v2);
  ASSERT(v2[0] == 2)
  ASSERT(v2[1] == 3)

  GLM(bvec2)(v3, v2);
  ASSERT(v2[0] == 11)
  ASSERT(v2[1] == 13)

  TEST_SUCCESS
}

TEST_IMPL(GLM_PREFIX, bvec2_copy) {
  bvec2 src = {7, 5};
  bvec2 dst = {99, 99};

  GLM(bvec2_copy)(src, dst);
  ASSERT(dst[0] == 7)
  ASSERT(dst[1] == 5)

  TEST_SUCCESS
}

TEST_IMPL(GLM_PREFIX, bvec2_zero) {
  bvec2 v = {2, 3};

  GLM(bvec2_zero)(v);
  ASSERT(v[0] == 0)
  ASSERT(v[1] == 0)

  TEST_SUCCESS
}

TEST_IMPL(GLM_PREFIX, bvec2_one) {
  bvec2 v = {-2, 9};

  GLM(bvec2_one)(v);
  ASSERT(v[0] == 1)
  ASSERT(v[1] == 1)

  TEST_SUCCESS
}

TEST_IMPL(GLM_PREFIX, bvec2_add) {
  bvec2 a = {14, 3};
  bvec2 b = {-3, 2};
  bvec2 v = {99, 99};

  GLM(bvec2_add)(a, b, v);
  ASSERT(v[0] == 11)
  ASSERT(v[1] == 5)

  TEST_SUCCESS
}

TEST_IMPL(GLM_PREFIX, bvec2_adds) {
  bvec2 a = {-3, 1};
  bvec2 v = {99, 99};
  int8_t s = 2;

  GLM(bvec2_adds)(a, s, v);
  ASSERT(v[0] == -1)
  ASSERT(v[1] == 3)

  TEST_SUCCESS
}

TEST_IMPL(GLM_PREFIX, bvec2_sub) {
  bvec2 a = {-2, 9};
  bvec2 b = {3, 2};
  bvec2 v = {99, 99};

  GLM(bvec2_sub)(a, b, v);
  ASSERT(v[0] == -5)
  ASSERT(v[1] == 7)

  TEST_SUCCESS
}

TEST_IMPL(GLM_PREFIX, bvec2_subs) {
  bvec2 a = {5, -2};
  bvec2 v = {99, 99};
  int8_t s = -3;

  GLM(bvec2_subs)(a, s, v);
  ASSERT(v[0] == 8)
  ASSERT(v[1] == 1)

  TEST_SUCCESS
}

TEST_IMPL(GLM_PREFIX, bvec2_mul) {
  bvec2 a = {3, 4};
  bvec2 b = {-2, 3};
  bvec2 v = {99, 99};

  GLM(bvec2_mul)(a, b, v);
  ASSERT(v[0] == -6)
  ASSERT(v[1] == 12)

  TEST_SUCCESS
}

TEST_IMPL(GLM_PREFIX, bvec2_scale) {
  bvec2 a = {-9, 2};
  bvec2 v = {99, 99};
  int8_t s = -2;

  GLM(bvec2_scale)(a, s, v);
  ASSERT(v[0] == 18)
  ASSERT(v[1] == -4)

  TEST_SUCCESS
}

TEST_IMPL(GLM_PREFIX, bvec2_distance2) {
  bvec2 a = {-1, 3};
  bvec2 b = {5, 4};
  int8_t v;

  v = GLM(bvec2_distance2)(a, b);
  ASSERT(v == 37)

  TEST_SUCCESS
}

TEST_IMPL(GLM_PREFIX, bvec2_distance) {
  bvec2 a = {3, 2};
  bvec2 b = {-2, 5};
  float v;

  v = GLM(bvec2_distance)(a, b);
  ASSERT(test_eq(v, 5.8309518948f))

  TEST_SUCCESS
}

TEST_IMPL(GLM_PREFIX, bvec2_fill) {
  bvec2 v1;
  bvec2 v2 = {-1, 3};

  GLM(bvec2_fill)(v1, 1);
  GLM(bvec2_fill)(v2, 2);

  ASSERT(GLM(bvec2_eq)(v1, 1))
  ASSERT(GLM(bvec2_eq)(v2, 2))

  TEST_SUCCESS
}

TEST_IMPL(GLM_PREFIX, bvec2_eq) {
  bvec2 v1 = {-1, 2};

  GLM(bvec2_fill)(v1, 2);

  ASSERT(GLM(bvec2_eq)(v1, 2))

  TEST_SUCCESS
}

TEST_IMPL(GLM_PREFIX, bvec2_eqv) {
  bvec2 v1, v2, v3;

  GLM(bvec2_fill)(v1, 1);
  GLM(bvec2_fill)(v2, 2);
  GLM(bvec2_fill)(v3, 1);

  ASSERT(GLM(bvec2_eqv)(v1, v3))
  ASSERT(!GLM(bvec2_eqv)(v1, v2))

  TEST_SUCCESS
}

TEST_IMPL(GLM_PREFIX, bvec2_maxv) {
  bvec2 a = {9, -20};
  bvec2 b = {8, -1};
  bvec2 v = {99, 99};

  GLM(bvec2_maxv)(a, b, v);
  ASSERT(v[0] == 9)
  ASSERT(v[1] == -1)

  TEST_SUCCESS
}

TEST_IMPL(GLM_PREFIX, bvec2_minv) {
  bvec2 a = {16, 0};
  bvec2 b = {-15, 10};
  bvec2 v = {99, 99};

  GLM(bvec2_minv)(a, b, v);
  ASSERT(v[0] == -15)
  ASSERT(v[1] == 0)

  TEST_SUCCESS
}

TEST_IMPL(GLM_PREFIX, bvec2_clamp) {
  bvec2 v = {3, -1};

  GLM(bvec2_clamp)(v, -2, 4);
  ASSERT(v[0] == 3)
  ASSERT(v[1] == -1)

  v[0] = -15;
  v[1] = 4;
  GLM(bvec2_clamp)(v, -9, 3);
  ASSERT(v[0] == -9)
  ASSERT(v[1] == 3)

  TEST_SUCCESS
}

TEST_IMPL(GLM_PREFIX, bvec2_abs) {
  bvec2  v1 = {2, -3}, v2 = {-12, -31};
  bvec2  v3, v4;

  GLM(bvec2_abs)(v1, v3);
  GLM(bvec2_abs)(v2, v4);

  ASSERT(v3[0] == 2)
  ASSERT(v3[1] == 3)
  ASSERT(v4[0] == 12)
  ASSERT(v4[1] == 31)

  TEST_SUCCESS
}
