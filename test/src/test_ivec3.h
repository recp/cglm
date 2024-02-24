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

TEST_IMPL(GLM_PREFIX, ivec3_dot) {
  ivec3 a = {2, 3, 1};
  ivec3 b = {4, 4, 2};
  int dot1, dot2;

  dot1 = GLM(ivec3_dot)(a, b);
  dot2 = a[0] * b[0] + a[1] * b[1] + a[2] * b[2];

  ASSERT(dot1 == dot2)
  ASSERT(dot1 == 22)

  TEST_SUCCESS
}

TEST_IMPL(GLM_PREFIX, ivec3_norm2) {
  ivec3 v = {2, 3, 4};
  int norm2_1, norm2_2;

  norm2_1 = GLM(ivec3_norm2)(v);
  norm2_2 = v[0] * v[0] + v[1] * v[1] + v[2] * v[2];
  
  ASSERT(norm2_1 == norm2_2)
  ASSERT(norm2_1 == 29)

  TEST_SUCCESS
}

TEST_IMPL(GLM_PREFIX, ivec3_norm) {
  ivec3 v = {2, 3, 4};
  int norm1, norm2;

  norm1 = GLM(ivec3_norm)(v);
  norm2 = (int)sqrtf((float)(v[0] * v[0] + v[1] * v[1] + v[2] * v[2]));

  ASSERT(norm1 == norm2)
  ASSERT(norm1 == 5)

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

TEST_IMPL(GLM_PREFIX, ivec3_div) {
  ivec3 v1 = {6, 5, 8},
        v2 = {-2, 4, 2},
        v3;
  
  GLM(ivec3_div)(v1, v2, v3);

  ASSERT(v1[0] / v2[0] == v3[0])
  ASSERT(v1[1] / v2[1] == v3[1])
  ASSERT(v1[2] / v2[2] == v3[2])
  ASSERT(v3[0] == -3)
  ASSERT(v3[1] == 1)
  ASSERT(v3[2] == 4)
  
  TEST_SUCCESS
}

TEST_IMPL(GLM_PREFIX, ivec3_divs) {
  ivec3  v1 = {16, -8, 12}, v2;
  int s  = 4;
  
  GLM(ivec3_divs)(v1, s, v2);

  ASSERT(v1[0] / s == v2[0])
  ASSERT(v1[1] / s == v2[1])
  ASSERT(v1[2] / s == v2[2])
  ASSERT(v2[0] == 4)
  ASSERT(v2[1] == -2)
  ASSERT(v2[2] == 3)
  
  TEST_SUCCESS
}

TEST_IMPL(GLM_PREFIX, ivec3_mod) {
  ivec3 a = {16, -8, 10};
  ivec3 b = {3, 5, 4};
  ivec3 dest;

  GLM(ivec3_mod)(a, b, dest);

  ASSERT(a[0] % b[0] == dest[0])
  ASSERT(a[1] % b[1] == dest[1])
  ASSERT(a[2] % b[2] == dest[2])
  ASSERT(dest[0] == 1)
  ASSERT(dest[1] == -3)
  ASSERT(dest[2] == 2)

  TEST_SUCCESS
}

TEST_IMPL(GLM_PREFIX, ivec3_addadd) {
  ivec3 a = {2, -3, 8},
        b = {-3, 4, 5},
        c = {1, 2, 6},
        d = {1, 2, 6};

  GLM(ivec3_addadd)(a, b, c);

  ASSERT(d[0] + a[0] + b[0] == c[0])
  ASSERT(d[1] + a[1] + b[1] == c[1])
  ASSERT(d[2] + a[2] + b[2] == c[2])

  TEST_SUCCESS
}

TEST_IMPL(GLM_PREFIX, ivec3_addadds) {
  ivec3 a = {2, -3, 5},
        c = {1, 2, -9},
        d = {1, 2, -9};
  int s = 9;

  GLM(ivec3_addadds)(a, s, c);

  ASSERT(d[0] + a[0] + s == c[0])
  ASSERT(d[1] + a[1] + s == c[1])
  ASSERT(d[2] + a[2] + s == c[2])

  TEST_SUCCESS
}

TEST_IMPL(GLM_PREFIX, ivec3_subadd) {
  ivec3 a = {2, -3, 8},
        b = {-3, 4, 5},
        c = {1, 2, 6},
        d = {1, 2, 6};

  GLM(ivec3_subadd)(a, b, c);

  ASSERT(d[0] + a[0] - b[0] == c[0])
  ASSERT(d[1] + a[1] - b[1] == c[1])
  ASSERT(d[2] + a[2] - b[2] == c[2])

  TEST_SUCCESS
}

TEST_IMPL(GLM_PREFIX, ivec3_subadds) {
  ivec3 a = {2, -3, 5},
        c = {1, 2, -9},
        d = {1, 2, -9};
  int s = 9;

  GLM(ivec3_subadds)(a, s, c);

  ASSERT(d[0] + a[0] - s == c[0])
  ASSERT(d[1] + a[1] - s == c[1])
  ASSERT(d[2] + a[2] - s == c[2])

  TEST_SUCCESS
}

TEST_IMPL(GLM_PREFIX, ivec3_muladd) {
  ivec3 a = {2, -3, 8},
        b = {-3, 4, 5},
        c = {1, 2, 6},
        d = {1, 2, 6};

  GLM(ivec3_muladd)(a, b, c);

  ASSERT(d[0] + a[0] * b[0] == c[0])
  ASSERT(d[1] + a[1] * b[1] == c[1])
  ASSERT(d[2] + a[2] * b[2] == c[2])

  TEST_SUCCESS
}

TEST_IMPL(GLM_PREFIX, ivec3_muladds) {
  ivec3 a = {2, -3, 5},
        c = {1, 2, -9},
        d = {1, 2, -9};
  int s = 9;

  GLM(ivec3_muladds)(a, s, c);

  ASSERT(d[0] + a[0] * s == c[0])
  ASSERT(d[1] + a[1] * s == c[1])
  ASSERT(d[2] + a[2] * s == c[2])

  TEST_SUCCESS
}

TEST_IMPL(GLM_PREFIX, ivec3_maxadd) {
  ivec3 a = {2, -3, 8},
        b = {-3, 4, 5},
        c = {1, 2, 6},
        d = {1, 2, 6};

  GLM(ivec3_maxadd)(a, b, c);
  
  ASSERT(d[0] += glm_imax(a[0], b[0]) == c[0])
  ASSERT(d[1] += glm_imax(a[1], b[1]) == c[1])
  ASSERT(d[2] += glm_imax(a[2], b[2]) == c[2])

  TEST_SUCCESS
}

TEST_IMPL(GLM_PREFIX, ivec3_minadd) {
  ivec3 a = {2, -3, 8},
        b = {-3, 4, 5},
        c = {1, 2, 6},
        d = {1, 2, 6};

  GLM(ivec3_minadd)(a, b, c);
  
  ASSERT(d[0] += glm_imin(a[0], b[0]) == c[0])
  ASSERT(d[1] += glm_imin(a[1], b[1]) == c[1])
  ASSERT(d[2] += glm_imin(a[2], b[2]) == c[2])

  TEST_SUCCESS
}

TEST_IMPL(GLM_PREFIX, ivec3_subsub) {
  ivec3 a = {2, -3, 8},
        b = {-3, 4, 5},
        c = {1, 2, 6},
        d = {1, 2, 6};

  GLM(ivec3_subsub)(a, b, c);

  ASSERT(d[0] - (a[0] - b[0]) == c[0])
  ASSERT(d[1] - (a[1] - b[1]) == c[1])
  ASSERT(d[2] - (a[2] - b[2]) == c[2])

  TEST_SUCCESS
}

TEST_IMPL(GLM_PREFIX, ivec3_subsubs) {
  ivec3 a = {2, -3, 5},
        c = {1, 2, -9},
        d = {1, 2, -9};
  int s = 9;

  GLM(ivec3_subsubs)(a, s, c);

  ASSERT(d[0] - (a[0] - s) == c[0])
  ASSERT(d[1] - (a[1] - s) == c[1])
  ASSERT(d[2] - (a[2] - s) == c[2])

  TEST_SUCCESS
}

TEST_IMPL(GLM_PREFIX, ivec3_addsub) {
  ivec3 a = {2, -3, 8},
        b = {-3, 4, 5},
        c = {1, 2, 6},
        d = {1, 2, 6};

  GLM(ivec3_addsub)(a, b, c);

  ASSERT(d[0] - (a[0] + b[0]) == c[0])
  ASSERT(d[1] - (a[1] + b[1]) == c[1])
  ASSERT(d[2] - (a[2] + b[2]) == c[2])

  TEST_SUCCESS
}

TEST_IMPL(GLM_PREFIX, ivec3_addsubs) {
  ivec3 a = {2, -3, 5},
        c = {1, 2, -9},
        d = {1, 2, -9};
  int s = 9;

  GLM(ivec3_addsubs)(a, s, c);

  ASSERT(d[0] - (a[0] + s) == c[0])
  ASSERT(d[1] - (a[1] + s) == c[1])
  ASSERT(d[2] - (a[2] + s) == c[2])

  TEST_SUCCESS
}

TEST_IMPL(GLM_PREFIX, ivec3_mulsub) {
  ivec3 a = {2, -3, 8},
        b = {-3, 4, 5},
        c = {1, 2, 6},
        d = {1, 2, 6};

  GLM(ivec3_mulsub)(a, b, c);

  ASSERT(d[0] - a[0] * b[0] == c[0])
  ASSERT(d[1] - a[1] * b[1] == c[1])
  ASSERT(d[2] - a[2] * b[2] == c[2])

  TEST_SUCCESS
}

TEST_IMPL(GLM_PREFIX, ivec3_mulsubs) {
  ivec3 a = {2, -3, 5},
        c = {1, 2, -9},
        d = {1, 2, -9};
  int s = 9;

  GLM(ivec3_mulsubs)(a, s, c);

  ASSERT(d[0] - a[0] * s == c[0])
  ASSERT(d[1] - a[1] * s == c[1])
  ASSERT(d[2] - a[2] * s == c[2])

  TEST_SUCCESS
}

TEST_IMPL(GLM_PREFIX, ivec3_maxsub) {
  ivec3 a = {2, -3, 8},
        b = {-3, 4, 5},
        c = {1, 2, 6},
        d = {1, 2, 6};

  GLM(ivec3_maxsub)(a, b, c);

  ASSERT(d[0] -= glm_imax(a[0], b[0]) == c[0])
  ASSERT(d[1] -= glm_imax(a[1], b[1]) == c[1])
  ASSERT(d[2] -= glm_imax(a[2], b[2]) == c[2])

  TEST_SUCCESS
}

TEST_IMPL(GLM_PREFIX, ivec3_minsub) {
  ivec3 a = {2, -3, 8},
        b = {-3, 4, 5},
        c = {1, 2, 6},
        d = {1, 2, 6};

  GLM(ivec3_minsub)(a, b, c);

  ASSERT(d[0] -= glm_imin(a[0], b[0]) == c[0])
  ASSERT(d[1] -= glm_imin(a[1], b[1]) == c[1])
  ASSERT(d[2] -= glm_imin(a[2], b[2]) == c[2])

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
  ASSERT(test_eq(v, 6.1644140029f))

  TEST_SUCCESS
}

TEST_IMPL(GLM_PREFIX, ivec3_fill) {
  ivec3 v1;
  ivec3 v2 = {-1, 3, 4};

  GLM(ivec3_fill)(v1, 1);
  GLM(ivec3_fill)(v2, 2);

  ASSERT(GLM(ivec3_eq)(v1, 1))
  ASSERT(GLM(ivec3_eq)(v2, 2))

  TEST_SUCCESS
}

TEST_IMPL(GLM_PREFIX, ivec3_eq) {
  ivec3 v1 = { -1, 2, 4 };

  GLM(ivec3_fill)(v1, 2);

  ASSERT(GLM(ivec3_eq)(v1, 2))

  TEST_SUCCESS
}

TEST_IMPL(GLM_PREFIX, ivec3_eqv) {
  ivec3 v1, v2, v3;

  GLM(ivec3_fill)(v1, 1);
  GLM(ivec3_fill)(v2, 2);
  GLM(ivec3_fill)(v3, 1);

  ASSERT(GLM(ivec3_eqv)(v1, v3))
  ASSERT(!GLM(ivec3_eqv)(v1, v2))

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

TEST_IMPL(GLM_PREFIX, ivec3_abs) {
  ivec3  v1 = {2, -3, 4}, v2 = {-12, -31, -42};
  ivec3  v3, v4;

  GLM(ivec3_abs)(v1, v3);
  GLM(ivec3_abs)(v2, v4);

  ASSERT(v3[0] == 2)
  ASSERT(v3[1] == 3)
  ASSERT(v3[2] == 4)
  ASSERT(v4[0] == 12)
  ASSERT(v4[1] == 31)
  ASSERT(v4[2] == 42)

  TEST_SUCCESS
}
