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

TEST_IMPL(GLM_PREFIX, ivec2_dot) {
  ivec2 a = {2, 3};
  ivec2 b = {4, 4};
  int dot1, dot2;

  dot1 = GLM(ivec2_dot)(a, b);
  dot2 = a[0] * b[0] + a[1] * b[1];

  ASSERT(dot1 == dot2)
  ASSERT(dot1 == 20)

  TEST_SUCCESS
}

TEST_IMPL(GLM_PREFIX, ivec2_cross) {
  ivec2 a = {10, 9};
  ivec2 b = {1, 2};
  int cross1, cross2;

  cross1 = GLM(ivec2_cross)(a, b);
  cross2 = a[0] * b[1] - a[1] * b[0];

  ASSERT(cross1 == cross2)
  ASSERT(cross1 == 11)

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

TEST_IMPL(GLM_PREFIX, ivec2_div) {
  ivec2 v1 = {6, 5},
        v2 = {-2, 4},
        v3;
  
  GLM(ivec2_div)(v1, v2, v3);

  ASSERT(v1[0] / v2[0] == v3[0])
  ASSERT(v1[1] / v2[1] == v3[1])
  ASSERT(v3[0] == -3)
  ASSERT(v3[1] == 1)
  
  TEST_SUCCESS
}

TEST_IMPL(GLM_PREFIX, ivec2_divs) {
  ivec2  v1 = {16, -8}, v2;
  int s  = 4;
  
  GLM(ivec2_divs)(v1, s, v2);

  ASSERT(v1[0] / s == v2[0])
  ASSERT(v1[1] / s == v2[1])
  ASSERT(v2[0] == 4)
  ASSERT(v2[1] == -2)
  
  TEST_SUCCESS
}

TEST_IMPL(GLM_PREFIX, ivec2_mod) {
  ivec2 a = {16, -8};
  ivec2 b = {3, 5};
  ivec2 dest;

  GLM(ivec2_mod)(a, b, dest);

  ASSERT(a[0] % b[0] == dest[0])
  ASSERT(a[1] % b[1] == dest[1])
  ASSERT(dest[0] == 1)
  ASSERT(dest[1] == -3)

  TEST_SUCCESS
}

TEST_IMPL(GLM_PREFIX, ivec2_addadd) {
  ivec2 a = {2, -3},
        b = {-3, 4},
        c = {1, 2},
        d = {1, 2};

  GLM(ivec2_addadd)(a, b, c);

  ASSERT(d[0] + a[0] + b[0] == c[0])
  ASSERT(d[1] + a[1] + b[1] == c[1])

  TEST_SUCCESS
}

TEST_IMPL(GLM_PREFIX, ivec2_addadds) {
  ivec2 a = {2, -3},
        c = {1, 2},
        d = {1, 2};
  int s = 9;

  GLM(ivec2_addadds)(a, s, c);

  ASSERT(d[0] + a[0] + s == c[0])
  ASSERT(d[1] + a[1] + s == c[1])

  TEST_SUCCESS
}

TEST_IMPL(GLM_PREFIX, ivec2_subadd) {
  ivec2 a = {2, -3},
        b = {-3, 4},
        c = {1, 2},
        d = {1, 2};

  GLM(ivec2_subadd)(a, b, c);

  ASSERT(d[0] + (a[0] - b[0]) == c[0])
  ASSERT(d[1] + (a[1] - b[1]) == c[1])

  TEST_SUCCESS
}

TEST_IMPL(GLM_PREFIX, ivec2_subadds) {
  ivec2 a = {2, -3},
        c = {1, 2},
        d = {1, 2};
  int s = 9;

  GLM(ivec2_subadds)(a, s, c);

  ASSERT(d[0] + a[0] - s == c[0])
  ASSERT(d[1] + a[1] - s == c[1])

  TEST_SUCCESS
}

TEST_IMPL(GLM_PREFIX, ivec2_muladd) {
  ivec2 a = {2, -3},
        b = {-3, 4},
        c = {1, 2},
        d = {1, 2};

  GLM(ivec2_muladd)(a, b, c);

  ASSERT(d[0] + a[0] * b[0] == c[0])
  ASSERT(d[1] + a[1] * b[1] == c[1])

  TEST_SUCCESS
}

TEST_IMPL(GLM_PREFIX, ivec2_muladds) {
  ivec2 a = {2, -3},
        c = {1, 2},
        d = {1, 2};
  int s = 9;

  GLM(ivec2_muladds)(a, s, c);

  ASSERT(d[0] + a[0] * s == c[0])
  ASSERT(d[1] + a[1] * s == c[1])

  TEST_SUCCESS
}

TEST_IMPL(GLM_PREFIX, ivec2_maxadd) {
  ivec2 a = {2, -3},
        b = {-3, 4},
        c = {1, 2},
        d = {1, 2};

  GLM(ivec2_maxadd)(a, b, c);
  
  ASSERT(d[0] += glm_imax(a[0], b[0]) == c[0])
  ASSERT(d[1] += glm_imax(a[1], b[1]) == c[1])

  TEST_SUCCESS
}

TEST_IMPL(GLM_PREFIX, ivec2_minadd) {
  ivec2 a = {2, -3},
        b = {-3, 4},
        c = {1, 2},
        d = {1, 2};

  GLM(ivec2_minadd)(a, b, c);
  
  ASSERT(d[0] += glm_imin(a[0], b[0]) == c[0])
  ASSERT(d[1] += glm_imin(a[1], b[1]) == c[1])

  TEST_SUCCESS
}

TEST_IMPL(GLM_PREFIX, ivec2_subsub) {
  ivec2 a = {2, -3},
        b = {-3, 4},
        c = {1, 2},
        d = {1, 2};

  GLM(ivec2_subsub)(a, b, c);

  ASSERT(d[0] - (a[0] - b[0]) == c[0])
  ASSERT(d[1] - (a[1] - b[1]) == c[1])

  TEST_SUCCESS
}

TEST_IMPL(GLM_PREFIX, ivec2_subsubs) {
  ivec2 a = {2, -3},
        c = {1, 2},
        d = {1, 2};
  int s = 9;

  GLM(ivec2_subsubs)(a, s, c);

  ASSERT(d[0] - (a[0] - s) == c[0])
  ASSERT(d[1] - (a[1] - s) == c[1])

  TEST_SUCCESS
}

TEST_IMPL(GLM_PREFIX, ivec2_addsub) {
  ivec2 a = {2, -3},
        b = {-3, 4},
        c = {1, 2},
        d = {1, 2};

  GLM(ivec2_addsub)(a, b, c);

  ASSERT(d[0] - (a[0] + b[0]) == c[0])
  ASSERT(d[1] - (a[1] + b[1]) == c[1])

  TEST_SUCCESS
}

TEST_IMPL(GLM_PREFIX, ivec2_addsubs) {
  ivec2 a = {2, -3},
        c = {1, 2},
        d = {1, 2};
  int s = 9;

  GLM(ivec2_addsubs)(a, s, c);

  ASSERT(d[0] - (a[0] + s) == c[0])
  ASSERT(d[1] - (a[1] + s) == c[1])

  TEST_SUCCESS
}

TEST_IMPL(GLM_PREFIX, ivec2_mulsub) {
  ivec2 a = {2, -3},
        b = {-3, 4},
        c = {1, 2},
        d = {1, 2};

  GLM(ivec2_mulsub)(a, b, c);

  ASSERT(d[0] - a[0] * b[0] == c[0])
  ASSERT(d[1] - a[1] * b[1] == c[1])

  TEST_SUCCESS
}

TEST_IMPL(GLM_PREFIX, ivec2_mulsubs) {
  ivec2 a = {2, -3},
        c = {1, 2},
        d = {1, 2};
  int s = 9;

  GLM(ivec2_mulsubs)(a, s, c);

  ASSERT(d[0] - a[0] * s == c[0])
  ASSERT(d[1] - a[1] * s == c[1])

  TEST_SUCCESS
}

TEST_IMPL(GLM_PREFIX, ivec2_maxsub) {
  ivec2 a = {2, -3},
        b = {-3, 4},
        c = {1, 2},
        d = {1, 2};

  GLM(ivec2_maxsub)(a, b, c);
  
  ASSERT(d[0] -= glm_imax(a[0], b[0]) == c[0])
  ASSERT(d[1] -= glm_imax(a[1], b[1]) == c[1])

  TEST_SUCCESS
}

TEST_IMPL(GLM_PREFIX, ivec2_minsub) {
  ivec2 a = {2, -3},
        b = {-3, 4},
        c = {1, 2},
        d = {1, 2};

  GLM(ivec2_minsub)(a, b, c);

  ASSERT(d[0] -= glm_imin(a[0], b[0]) == c[0])
  ASSERT(d[1] -= glm_imin(a[1], b[1]) == c[1])

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
  ASSERT(test_eq(v, 5.8309518948f))

  TEST_SUCCESS
}

TEST_IMPL(GLM_PREFIX, ivec2_fill) {
  ivec2 v1;
  ivec2 v2 = {-1, 3};

  GLM(ivec2_fill)(v1, 1);
  GLM(ivec2_fill)(v2, 2);

  ASSERT(GLM(ivec2_eq)(v1, 1))
  ASSERT(GLM(ivec2_eq)(v2, 2))

  TEST_SUCCESS
}

TEST_IMPL(GLM_PREFIX, ivec2_eq) {
  ivec2 v1 = {-1, 2};

  GLM(ivec2_fill)(v1, 2);

  ASSERT(GLM(ivec2_eq)(v1, 2))

  TEST_SUCCESS
}

TEST_IMPL(GLM_PREFIX, ivec2_eqv) {
  ivec2 v1, v2, v3;

  GLM(ivec2_fill)(v1, 1);
  GLM(ivec2_fill)(v2, 2);
  GLM(ivec2_fill)(v3, 1);

  ASSERT(GLM(ivec2_eqv)(v1, v3))
  ASSERT(!GLM(ivec2_eqv)(v1, v2))

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

TEST_IMPL(GLM_PREFIX, ivec2_abs) {
  ivec2  v1 = {2, -3}, v2 = {-12, -31};
  ivec2  v3, v4;

  GLM(ivec2_abs)(v1, v3);
  GLM(ivec2_abs)(v2, v4);

  ASSERT(v3[0] == 2)
  ASSERT(v3[1] == 3)
  ASSERT(v4[0] == 12)
  ASSERT(v4[1] == 31)

  TEST_SUCCESS
}
