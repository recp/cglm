/*
 * Copyright (c), Recep Aslantas.
 *
 * MIT License (MIT), http://opensource.org/licenses/MIT
 * Full license can be found in the LICENSE file
 */

#include "test_common.h"

TEST_IMPL(GLM_PREFIX, bvec3) {
  bvec4 v4 = {2, 3, 5, 7};
  bvec3 v3 = {99, 99, 99};

  GLM(bvec3)(v4, v3);
  ASSERT(v3[0] == 2)
  ASSERT(v3[1] == 3)
  ASSERT(v3[2] == 5)

  TEST_SUCCESS
}

TEST_IMPL(GLM_PREFIX, bvec3_copy) {
  bvec3 src = {7, 5, 2};
  bvec3 dst = {99, 99, 99};

  GLM(bvec3_copy)(src, dst);
  ASSERT(dst[0] == 7)
  ASSERT(dst[1] == 5)
  ASSERT(dst[2] == 2)

  TEST_SUCCESS
}

TEST_IMPL(GLM_PREFIX, bvec3_zero) {
  bvec3 v = {2, 3, 5};

  GLM(bvec3_zero)(v);
  ASSERT(v[0] == 0)
  ASSERT(v[1] == 0)
  ASSERT(v[2] == 0)

  TEST_SUCCESS
}

TEST_IMPL(GLM_PREFIX, bvec3_one) {
  bvec3 v = {-2, 9, 12};

  GLM(bvec3_one)(v);
  ASSERT(v[0] == 1)
  ASSERT(v[1] == 1)
  ASSERT(v[2] == 1)

  TEST_SUCCESS
}

TEST_IMPL(GLM_PREFIX, bvec3_add) {
  bvec3 a = {14, 3, 2};
  bvec3 b = {-3, 2, 1};
  bvec3 v = {99, 99, 99};

  GLM(bvec3_add)(a, b, v);
  ASSERT(v[0] == 11)
  ASSERT(v[1] == 5)
  ASSERT(v[2] == 3)

  TEST_SUCCESS
}

TEST_IMPL(GLM_PREFIX, bvec3_adds) {
  bvec3 a = {-3, 1, 4};
  bvec3 v = {99, 99, 99};
  int8_t s = 2;

  GLM(bvec3_adds)(a, s, v);
  ASSERT(v[0] == -1)
  ASSERT(v[1] == 3)
  ASSERT(v[2] == 6)

  TEST_SUCCESS
}

TEST_IMPL(GLM_PREFIX, bvec3_sub) {
  bvec3 a = {-2, 9, 1};
  bvec3 b = {3, 2, -1};
  bvec3 v = {99, 99, 99};

  GLM(bvec3_sub)(a, b, v);
  ASSERT(v[0] == -5)
  ASSERT(v[1] == 7)
  ASSERT(v[2] == 2)

  TEST_SUCCESS
}

TEST_IMPL(GLM_PREFIX, bvec3_subs) {
  bvec3 a = {5, -2, 6};
  bvec3 v = {99, 99, 99};
  int8_t s = -3;

  GLM(bvec3_subs)(a, s, v);
  ASSERT(v[0] == 8)
  ASSERT(v[1] == 1)
  ASSERT(v[2] == 9)

  TEST_SUCCESS
}

TEST_IMPL(GLM_PREFIX, bvec3_mul) {
  bvec3 a = {3, 4, 5};
  bvec3 b = {-2, 3, 1};
  bvec3 v = {99, 99, 99};

  GLM(bvec3_mul)(a, b, v);
  ASSERT(v[0] == -6)
  ASSERT(v[1] == 12)
  ASSERT(v[2] == 5)

  TEST_SUCCESS
}

TEST_IMPL(GLM_PREFIX, bvec3_scale) {
  bvec3 a = {-9, 2, 3};
  bvec3 v = {99, 99, 99};
  int8_t s = -2;

  GLM(bvec3_scale)(a, s, v);
  ASSERT(v[0] == 18)
  ASSERT(v[1] == -4)
  ASSERT(v[2] == -6)

  TEST_SUCCESS
}

TEST_IMPL(GLM_PREFIX, bvec3_distance2) {
  bvec3 a = {-1, 3, 0};
  bvec3 b = {5, 4, 2};
  int8_t v;

  v = GLM(bvec3_distance2)(a, b);
  ASSERT(v == 41)

  TEST_SUCCESS
}

TEST_IMPL(GLM_PREFIX, bvec3_distance) {
  bvec3 a = {3, 2, 4};
  bvec3 b = {-2, 5, 2};
  float v;

  v = GLM(bvec3_distance)(a, b);
  ASSERT(test_eq(v, 6.1644140029f))

  TEST_SUCCESS
}

TEST_IMPL(GLM_PREFIX, bvec3_fill) {
  bvec3 v1;
  bvec3 v2 = {-1, 3, 4};

  GLM(bvec3_fill)(v1, 1);
  GLM(bvec3_fill)(v2, 2);

  ASSERT(GLM(bvec3_eq)(v1, 1))
  ASSERT(GLM(bvec3_eq)(v2, 2))

  TEST_SUCCESS
}

TEST_IMPL(GLM_PREFIX, bvec3_eq) {
  bvec3 v1 = { -1, 2, 4 };

  GLM(bvec3_fill)(v1, 2);

  ASSERT(GLM(bvec3_eq)(v1, 2))

  TEST_SUCCESS
}

TEST_IMPL(GLM_PREFIX, bvec3_eqv) {
  bvec3 v1, v2, v3;

  GLM(bvec3_fill)(v1, 1);
  GLM(bvec3_fill)(v2, 2);
  GLM(bvec3_fill)(v3, 1);

  ASSERT(GLM(bvec3_eqv)(v1, v3))
  ASSERT(!GLM(bvec3_eqv)(v1, v2))

  TEST_SUCCESS
}

TEST_IMPL(GLM_PREFIX, bvec3_maxv) {
  bvec3 a = {9, -20, 5};
  bvec3 b = {8, -1, 2};
  bvec3 v = {99, 99, 99};

  GLM(bvec3_maxv)(a, b, v);
  ASSERT(v[0] == 9)
  ASSERT(v[1] == -1)
  ASSERT(v[2] == 5)

  TEST_SUCCESS
}

TEST_IMPL(GLM_PREFIX, bvec3_minv) {
  bvec3 a = {16, 0, 4};
  bvec3 b = {-15, 10, 8};
  bvec3 v = {99, 99, 99};

  GLM(bvec3_minv)(a, b, v);
  ASSERT(v[0] == -15)
  ASSERT(v[1] == 0)
  ASSERT(v[2] == 4)

  TEST_SUCCESS
}

TEST_IMPL(GLM_PREFIX, bvec3_clamp) {
  bvec3 v = {3, -1, 10};

  GLM(bvec3_clamp)(v, -2, 4);
  ASSERT(v[0] == 3)
  ASSERT(v[1] == -1)
  ASSERT(v[2] == 4)

  v[0] = -15;
  v[1] = 4;
  v[2] = 1;
  GLM(bvec3_clamp)(v, -9, 3);
  ASSERT(v[0] == -9)
  ASSERT(v[1] == 3)
  ASSERT(v[2] == 1)

  TEST_SUCCESS
}

TEST_IMPL(GLM_PREFIX, bvec3_abs) {
  bvec3  v1 = {2, -3, 4}, v2 = {-12, -31, -42};
  bvec3  v3, v4;

  GLM(bvec3_abs)(v1, v3);
  GLM(bvec3_abs)(v2, v4);

  ASSERT(v3[0] == 2)
  ASSERT(v3[1] == 3)
  ASSERT(v3[2] == 4)
  ASSERT(v4[0] == 12)
  ASSERT(v4[1] == 31)
  ASSERT(v4[2] == 42)

  TEST_SUCCESS
}
