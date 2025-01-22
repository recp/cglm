/*
 * Copyright (c), Recep Aslantas.
 *
 * MIT License (MIT), http://opensource.org/licenses/MIT
 * Full license can be found in the LICENSE file
 */

#include "test_common.h"

#ifndef CGLM_TEST_VEC2_ONCE
#define CGLM_TEST_VEC2_ONCE

/* Macros */

TEST_IMPL(MACRO_GLM_VEC2_ONE_INIT) {
  vec2 v = GLM_VEC2_ONE_INIT;
  
  ASSERT(test_eq(v[0], 1.0f))
  ASSERT(test_eq(v[1], 1.0f))
  
  TEST_SUCCESS
}

TEST_IMPL(MACRO_GLM_VEC2_ZERO_INIT) {
  vec2 v = GLM_VEC2_ZERO_INIT;
  
  ASSERT(test_eq(v[0], 0.0f))
  ASSERT(test_eq(v[1], 0.0f))
  
  TEST_SUCCESS
}

TEST_IMPL(MACRO_GLM_VEC2_ONE) {
  ASSERT(test_eq(GLM_VEC2_ONE[0], 1.0f))
  ASSERT(test_eq(GLM_VEC2_ONE[1], 1.0f))
  
  TEST_SUCCESS
}

TEST_IMPL(MACRO_GLM_VEC2_ZERO) {
  ASSERT(test_eq(GLM_VEC2_ZERO[0], 0.0f))
  ASSERT(test_eq(GLM_VEC2_ZERO[0], 0.0f))
  
  TEST_SUCCESS
}

#endif /* CGLM_TEST_VEC2_ONCE */

TEST_IMPL(GLM_PREFIX, vec2) {
  vec4 v4 = {10.0f, 9.0f, 8.0f, 7.0f};
  vec3 v3 = {11.0f, 12.0f, 13.0f};
  vec2 v2;
  
  GLM(vec2)(v4, v2);
  ASSERT(test_eq(v2[0], v4[0]))
  ASSERT(test_eq(v2[1], v4[1]))
  
  GLM(vec2)(v3, v2);
  ASSERT(test_eq(v2[0], v3[0]))
  ASSERT(test_eq(v2[1], v3[1]))

  TEST_SUCCESS
}

TEST_IMPL(GLM_PREFIX, vec2_copy) {
  vec2 v1 = {10.0f, 9.0f};
  vec2 v2 = {1.0f, 2.0f};
  
  GLM(vec2_copy)(v1, v2);
  
  ASSERTIFY(test_assert_vec2_eq(v1, v2))
  
  TEST_SUCCESS
}

TEST_IMPL(GLM_PREFIX, vec2_zero) {
  vec2 v1 = {10.0f, 9.0f};
  vec2 v2 = {1.0f, 2.0f};
  
  GLM(vec2_zero)(v1);
  GLM(vec2_zero)(v2);
  
  ASSERTIFY(test_assert_vec2_eq(v1, GLM_VEC2_ZERO))
  ASSERTIFY(test_assert_vec2_eq(v2, GLM_VEC2_ZERO))
  
  TEST_SUCCESS
}

TEST_IMPL(GLM_PREFIX, vec2_one) {
  vec2 v1 = {10.0f, 9.0f};
  vec2 v2 = {1.0f, 2.0f};
  
  GLM(vec2_one)(v1);
  GLM(vec2_one)(v2);
  
  ASSERTIFY(test_assert_vec2_eq(v1, GLM_VEC2_ONE))
  ASSERTIFY(test_assert_vec2_eq(v2, GLM_VEC2_ONE))
  
  TEST_SUCCESS
}

TEST_IMPL(GLM_PREFIX, vec2_dot) {
  vec2  a = {10.0f, 9.0f};
  vec2  b = {1.0f, 2.0f};
  float dot1, dot2;
  
  dot1 = GLM(vec2_dot)(a, b);
  dot2 = a[0] * b[0] + a[1] * b[1];
  
  ASSERT(test_eq(dot1, dot2))
  
  TEST_SUCCESS
}

TEST_IMPL(GLM_PREFIX, vec2_cross) {
  vec2  a = {10.0f, 9.0f};
  vec2  b = {1.0f, 2.0f};
  float cprod;

  cprod = a[0] * b[1] - a[1] * b[0];

  ASSERT(test_eq(glm_vec2_cross(a, b), cprod))

  TEST_SUCCESS
}

TEST_IMPL(GLM_PREFIX, vec2_norm2) {
  vec2 a = {10.0f, 9.0f};
  float n1, n2;
  
  n1 = GLM(vec2_norm2)(a);
  n2 = a[0] * a[0] + a[1] * a[1];

  ASSERT(test_eq(n1, n2))

  TEST_SUCCESS
}

TEST_IMPL(GLM_PREFIX, vec2_norm) {
  vec2  a = {10.0f, 9.0f};
  float n1, n2;
  
  n1 = GLM(vec2_norm)(a);
  n2 = sqrtf(a[0] * a[0] + a[1] * a[1]);

  ASSERT(test_eq(n1, n2))

  TEST_SUCCESS
}

TEST_IMPL(GLM_PREFIX, vec2_add) {
  vec2 a = {-10.0f, 9.0f};
  vec2 b = {12.0f, 19.0f};
  vec2 c, d;
  
  c[0] = a[0] + b[0];
  c[1] = a[1] + b[1];
  
  GLM(vec2_add)(a, b, d);
  
  ASSERTIFY(test_assert_vec2_eq(c, d))

  TEST_SUCCESS
}

TEST_IMPL(GLM_PREFIX, vec2_adds) {
  vec4  a = {-10.0f, 9.0f};
  vec4  c, d;
  float s = 7.0f;
  
  c[0] = a[0] + s;
  c[1] = a[1] + s;
  
  GLM(vec2_adds)(a, s, d);
  
  ASSERTIFY(test_assert_vec2_eq(c, d))

  TEST_SUCCESS
}

TEST_IMPL(GLM_PREFIX, vec2_sub) {
  vec2 a = {-10.0f, 9.0f};
  vec2 b = {12.0f, 19.0f};
  vec2 c, d;
  
  c[0] = a[0] - b[0];
  c[1] = a[1] - b[1];
  
  GLM(vec2_sub)(a, b, d);
  
  ASSERTIFY(test_assert_vec2_eq(c, d))

  TEST_SUCCESS
}

TEST_IMPL(GLM_PREFIX, vec2_subs) {
  vec2  a = {-10.0f, 9.0f};
  vec2  c, d;
  float s = 7.0f;
  
  c[0] = a[0] - s;
  c[1] = a[1] - s;
  
  GLM(vec2_subs)(a, s, d);
  
  ASSERTIFY(test_assert_vec2_eq(c, d))

  TEST_SUCCESS
}

TEST_IMPL(GLM_PREFIX, vec2_mul) {
  vec2 v1 = {2.0f, -3.0f},
       v2 = {-3.0f, 4.0f},
       v3;
  
  GLM(vec2_mul)(v1, v2, v3);

  ASSERT(test_eq(v1[0] * v2[0], v3[0]))
  ASSERT(test_eq(v1[1] * v2[1], v3[1]))
  
  TEST_SUCCESS
}

TEST_IMPL(GLM_PREFIX, vec2_scale) {
  vec2  v1 = {2.0f, -3.0f}, v2;
  float s  = 7.0f;
  
  GLM(vec2_scale)(v1, s, v2);

  ASSERT(test_eq(v1[0] * s, v2[0]))
  ASSERT(test_eq(v1[1] * s, v2[1]))
  
  TEST_SUCCESS
}

TEST_IMPL(GLM_PREFIX, vec2_scale_as) {
  vec2  v1 = {2.0f, -3.0f}, v2;
  float s  = 7.0f;
  float norm;

  GLM(vec2_scale_as)(v1, s, v2);

  norm = sqrtf(v1[0] * v1[0] + v1[1] * v1[1]);
  if (norm < FLT_EPSILON) {
    ASSERT(test_eq(v1[0], 0.0f))
    ASSERT(test_eq(v1[1], 0.0f))

    TEST_SUCCESS
  }
  
  norm = s / norm;
  
  ASSERT(test_eq(v1[0] * norm, v2[0]))
  ASSERT(test_eq(v1[1] * norm, v2[1]))

  TEST_SUCCESS
}

TEST_IMPL(GLM_PREFIX, vec2_div) {
  vec2 v1 = {2.0f, -3.0f},
       v2 = {-3.0f, 4.0f},
       v3;
  
  GLM(vec2_div)(v1, v2, v3);

  ASSERT(test_eq(v1[0] / v2[0], v3[0]))
  ASSERT(test_eq(v1[1] / v2[1], v3[1]))
  
  TEST_SUCCESS
}

TEST_IMPL(GLM_PREFIX, vec2_divs) {
  vec2  v1 = {2.0f, -3.0f}, v2;
  float s  = 7.0f;
  
  GLM(vec2_divs)(v1, s, v2);

  ASSERT(test_eq(v1[0] / s, v2[0]))
  ASSERT(test_eq(v1[1] / s, v2[1]))
  
  TEST_SUCCESS
}

TEST_IMPL(GLM_PREFIX, vec2_addadd) {
  vec2 v1 = {2.0f, -3.0f},
       v2 = {-3.0f, 4.0f},
       v3 = {1.0f, 2.0f},
       v4 = {1.0f, 2.0f};
  
  GLM(vec2_addadd)(v1, v2, v4);

  ASSERT(test_eq(v3[0] + v1[0] + v2[0], v4[0]))
  ASSERT(test_eq(v3[1] + v1[1] + v2[1], v4[1]))
  
  TEST_SUCCESS
}

TEST_IMPL(GLM_PREFIX, vec2_subadd) {
  vec2 v1 = {2.0f, -3.0f},
       v2 = {-3.0f, 4.0f},
       v3 = {1.0f, 2.0f},
       v4 = {1.0f, 2.0f};
  
  GLM(vec2_subadd)(v1, v2, v4);

  ASSERT(test_eq(v3[0] + v1[0] - v2[0], v4[0]))
  ASSERT(test_eq(v3[1] + v1[1] - v2[1], v4[1]))
  
  TEST_SUCCESS
}

TEST_IMPL(GLM_PREFIX, vec2_muladd) {
  vec2 v1 = {2.0f, -3.0f},
       v2 = {-3.0f, 4.0f},
       v3 = {1.0f, 2.0f},
       v4 = {1.0f, 2.0f};
  
  GLM(vec2_muladd)(v1, v2, v4);

  ASSERT(test_eq(v3[0] + v1[0] * v2[0], v4[0]))
  ASSERT(test_eq(v3[1] + v1[1] * v2[1], v4[1]))
  
  TEST_SUCCESS
}

TEST_IMPL(GLM_PREFIX, vec2_muladds) {
  vec2 v1 = {2.0f, -3.0f},
       v2 = {1.0f, 2.0f},
       v3 = {1.0f, 2.0f};
  float s = 9.0f;
  
  GLM(vec2_muladds)(v1, s, v3);

  ASSERT(test_eq(v2[0] + v1[0] * s, v3[0]))
  ASSERT(test_eq(v2[1] + v1[1] * s, v3[1]))
  
  TEST_SUCCESS
}

TEST_IMPL(GLM_PREFIX, vec2_maxadd) {
  vec2 v1 = {2.0f, -3.0f},
       v2 = {-3.0f, 4.0f},
       v3 = {1.0f, 2.0f},
       v4 = {1.0f, 2.0f};
  
  GLM(vec2_maxadd)(v1, v2, v4);

  ASSERT(test_eq(v3[0] + glm_max(v1[0], v2[0]), v4[0]))
  ASSERT(test_eq(v3[1] + glm_max(v1[1], v2[1]), v4[1]))
  
  TEST_SUCCESS
}

TEST_IMPL(GLM_PREFIX, vec2_minadd) {
  vec2 v1 = {2.0f, -3.0f},
       v2 = {-3.0f, 4.0f},
       v3 = {1.0f, 2.0f},
       v4 = {1.0f, 2.0f};
  
  GLM(vec2_minadd)(v1, v2, v4);

  ASSERT(test_eq(v3[0] + glm_min(v1[0], v2[0]), v4[0]))
  ASSERT(test_eq(v3[1] + glm_min(v1[1], v2[1]), v4[1]))
  
  TEST_SUCCESS
}

TEST_IMPL(GLM_PREFIX, vec2_subsub) {
  vec2 v1 = {2.0f, -3.0f},
       v2 = {-3.0f, 4.0f},
       v3 = {1.0f, 2.0f},
       v4 = {1.0f, 2.0f};
  
  GLM(vec2_subsub)(v1, v2, v4);

  ASSERT(test_eq(v3[0] - (v1[0] - v2[0]), v4[0]))
  ASSERT(test_eq(v3[1] - (v1[1] - v2[1]), v4[1]))
  
  TEST_SUCCESS
}

TEST_IMPL(GLM_PREFIX, vec2_addsub) {
  vec2 v1 = {2.0f, -3.0f},
       v2 = {-3.0f, 4.0f},
       v3 = {1.0f, 2.0f},
       v4 = {1.0f, 2.0f};
  
  GLM(vec2_addsub)(v1, v2, v4);

  ASSERT(test_eq(v3[0] - (v1[0] + v2[0]), v4[0]))
  ASSERT(test_eq(v3[1] - (v1[1] + v2[1]), v4[1]))
  
  TEST_SUCCESS
}

TEST_IMPL(GLM_PREFIX, vec2_mulsub) {
  vec2 v1 = {2.0f, -3.0f},
       v2 = {-3.0f, 4.0f},
       v3 = {1.0f, 2.0f},
       v4 = {1.0f, 2.0f};
  
  GLM(vec2_mulsub)(v1, v2, v4);

  ASSERT(test_eq(v3[0] - v1[0] * v2[0], v4[0]))
  ASSERT(test_eq(v3[1] - v1[1] * v2[1], v4[1]))
  
  TEST_SUCCESS
}

TEST_IMPL(GLM_PREFIX, vec2_mulsubs) {
  vec2 v1 = {2.0f, -3.0f},
       v2 = {1.0f, 2.0f},
       v3 = {1.0f, 2.0f};
  float s = 9.0f;
  
  GLM(vec2_mulsubs)(v1, s, v3);

  ASSERT(test_eq(v2[0] - v1[0] * s, v3[0]))
  ASSERT(test_eq(v2[1] - v1[1] * s, v3[1]))
  
  TEST_SUCCESS
}

TEST_IMPL(GLM_PREFIX, vec2_maxsub) {
  vec2 v1 = {2.0f, -3.0f},
       v2 = {-3.0f, 4.0f},
       v3 = {1.0f, 2.0f},
       v4 = {1.0f, 2.0f};
  
  GLM(vec2_maxsub)(v1, v2, v4);

  ASSERT(test_eq(v3[0] - glm_max(v1[0], v2[0]), v4[0]))
  ASSERT(test_eq(v3[1] - glm_max(v1[1], v2[1]), v4[1]))
  
  TEST_SUCCESS
}

TEST_IMPL(GLM_PREFIX, vec2_minsub) {
  vec2 v1 = {2.0f, -3.0f},
       v2 = {-3.0f, 4.0f},
       v3 = {1.0f, 2.0f},
       v4 = {1.0f, 2.0f};
  
  GLM(vec2_minsub)(v1, v2, v4);

  ASSERT(test_eq(v3[0] - glm_min(v1[0], v2[0]), v4[0]))
  ASSERT(test_eq(v3[1] - glm_min(v1[1], v2[1]), v4[1]))
  
  TEST_SUCCESS
}

TEST_IMPL(GLM_PREFIX, vec2_negate_to) {
  vec2 v1 = {2.0f, -3.0f},
       v2 = {-3.0f, 4.0f},
       v3, v4;
  
  GLM(vec2_negate_to)(v1, v3);
  GLM(vec2_negate_to)(v2, v4);

  ASSERT(test_eq(-v1[0], v3[0]))
  ASSERT(test_eq(-v1[1], v3[1]))
  
  ASSERT(test_eq(-v2[0], v4[0]))
  ASSERT(test_eq(-v2[1], v4[1]))
  
  TEST_SUCCESS
}

TEST_IMPL(GLM_PREFIX, vec2_negate) {
  vec2 v1 = {2.0f, -3.0f},
       v2 = {-3.0f, 4.0f},
       v3 = {2.0f, -3.0f},
       v4 = {-3.0f, 4.0f};
  
  GLM(vec2_negate)(v1);
  GLM(vec2_negate)(v2);

  ASSERT(test_eq(-v1[0], v3[0]))
  ASSERT(test_eq(-v1[1], v3[1]))
  
  ASSERT(test_eq(-v2[0], v4[0]))
  ASSERT(test_eq(-v2[1], v4[1]))
  
  TEST_SUCCESS
}

TEST_IMPL(GLM_PREFIX, vec2_normalize) {
  vec2  v1 = {2.0f, -3.0f}, v2 = {2.0f, -3.0f};
  float s  = 1.0f;
  float norm;

  GLM(vec2_normalize)(v2);

  norm = sqrtf(v1[0] * v1[0] + v1[1] * v1[1]);
  if (norm < FLT_EPSILON) {
    ASSERT(test_eq(v1[0], 0.0f))
    ASSERT(test_eq(v1[1], 0.0f))

    TEST_SUCCESS
  }
  
  norm = s / norm;
  
  ASSERT(test_eq(v1[0] * norm, v2[0]))
  ASSERT(test_eq(v1[1] * norm, v2[1]))

  glm_vec2_zero(v1);
  GLM(vec2_normalize)(v1);
  ASSERTIFY(test_assert_vec2_eq(v1, GLM_VEC2_ZERO))

  TEST_SUCCESS
}

TEST_IMPL(GLM_PREFIX, vec2_normalize_to) {
  vec2 v1 = {2.0f, -3.0f}, v2;
  float s  = 1.0f;
  float norm;

  GLM(vec2_normalize_to)(v1, v2);

  norm = sqrtf(v1[0] * v1[0] + v1[1] * v1[1]);
  if (norm < FLT_EPSILON) {
    ASSERT(test_eq(v1[0], 0.0f))
    ASSERT(test_eq(v1[1], 0.0f))

    TEST_SUCCESS
  }
  
  norm = s / norm;
  
  ASSERT(test_eq(v1[0] * norm, v2[0]))
  ASSERT(test_eq(v1[1] * norm, v2[1]))

  glm_vec2_zero(v1);
  GLM(vec2_normalize_to)(v1, v2);
  ASSERTIFY(test_assert_vec2_eq(v2, GLM_VEC2_ZERO))

  TEST_SUCCESS
}

TEST_IMPL(GLM_PREFIX, vec2_rotate) {
  vec2 v1 = {1.0f, 0.0f};

  GLM(vec2_rotate)(v1, GLM_PI_2f, v1);

  ASSERT(test_eq(v1[0], 0.0f))
  ASSERT(test_eq(v1[1], 1.0f))

  GLM(vec2_rotate)(v1, GLM_PI_2f, v1);

  ASSERT(test_eq(v1[0], -1.0f))
  ASSERT(test_eq(v1[1],  0.0f))

  GLM(vec2_rotate)(v1, GLM_PI_2f, v1);

  ASSERT(test_eq(v1[0],  0.0f))
  ASSERT(test_eq(v1[1], -1.0f))

  GLM(vec2_rotate)(v1, GLM_PI_2f, v1);

  ASSERT(test_eq(v1[0], 1.0f))
  ASSERT(test_eq(v1[1], 0.0f))

  TEST_SUCCESS
}

TEST_IMPL(GLM_PREFIX, vec2_center) {
  vec2 v1 = {1.0f, 1.0f},
       v2 = {0.0f, 0.0f};
  vec2 dest;
  GLM(vec2_center)(v1, v2, dest);

  ASSERTIFY(test_assert_vec2_eq(dest, (vec2){ 0.5f, 0.5f }))

  TEST_SUCCESS
}

TEST_IMPL(GLM_PREFIX, vec2_distance2) {
  vec2 v1 = {30.0f, 0.0f},
       v2 = {0.0f, 0.0f},
       v3 = {3.0f, 10.0f},
       v4 = {0.46f, 4.0f};
  float d;

  d = GLM(vec2_distance2)(v1, v2);
  ASSERT(test_eq(d, 30.0f * 30.0f))

  d = GLM(vec2_distance2)(v3, v4);
  ASSERT(test_eq(powf(v3[0] - v4[0], 2.0f)
               + powf(v3[1] - v4[1], 2.0f), d))

  TEST_SUCCESS
}

TEST_IMPL(GLM_PREFIX, vec2_distance) {
  vec2 v1 = {30.0f, 0.0f},
       v2 = {0.0f, 0.0f},
       v3 = {3.0f, 10.0f},
       v4 = {0.46f, 4.0f};
  float d;

  d = GLM(vec2_distance)(v1, v2);
  ASSERT(test_eq(d, 30.0f))

  d = GLM(vec2_distance)(v3, v4);
  ASSERT(test_eq(sqrtf(powf(v3[0] - v4[0], 2.0f)
                     + powf(v3[1] - v4[1], 2.0f)), d))

  TEST_SUCCESS
}

TEST_IMPL(GLM_PREFIX, vec2_maxv) {
  vec2 v1, v2, v3;
  vec2 v5 = {-1.456f, -1.456f};
  vec2 v6 = {11.0f, 11.0f};
  vec2 v7 = {78.0f, -78.0f};

  GLM(vec2_maxv)(v5, v6, v1);
  GLM(vec2_maxv)(v5, v7, v2);
  GLM(vec2_maxv)(v6, v7, v3);

  ASSERT(test_eq(v1[0], 11.0f))
  ASSERT(test_eq(v1[1], 11.0f))

  ASSERT(test_eq(v2[0], 78.0f))
  ASSERT(test_eq(v2[1], -1.456f))

  ASSERT(test_eq(v3[0], 78.0f))
  ASSERT(test_eq(v3[1], 11.0f))

  TEST_SUCCESS
}

TEST_IMPL(GLM_PREFIX, vec2_minv) {
  vec2 v1, v2, v3;
  vec2 v5 = {-1.456f, -1.456f};
  vec2 v6 = {11.0f, 11.0f};
  vec2 v7 = {78.0f, -78.0f};

  GLM(vec2_minv)(v5, v6, v1);
  GLM(vec2_minv)(v5, v7, v2);
  GLM(vec2_minv)(v6, v7, v3);

  ASSERT(test_eq(v1[0], -1.456f))
  ASSERT(test_eq(v1[1], -1.456f))

  ASSERT(test_eq(v2[0], -1.456f))
  ASSERT(test_eq(v2[1], -78.0f))

  ASSERT(test_eq(v3[0], 11.0f))
  ASSERT(test_eq(v3[1], -78.0f))

  TEST_SUCCESS
}

TEST_IMPL(GLM_PREFIX, vec2_clamp) {
  vec2 v1 = {-1.456f, -11.456f};
  vec2 v2 = {0.110f, 111.0f};
  vec2 v3 = {78.0f, 32.0f};

  GLM(vec2_clamp)(v1, -1.03f, 30.0f);
  GLM(vec2_clamp)(v2,  0.11f, 111.0f);
  GLM(vec2_clamp)(v3, -88.0f, 70.0f);

  ASSERT(test_eq(v1[0], -1.03f))
  ASSERT(test_eq(v1[1], -1.03f))
  
  ASSERT(test_eq(v2[0],  0.11f))
  ASSERT(test_eq(v2[1],  111.0f))
  
  ASSERT(test_eq(v3[0],  70.0f))
  ASSERT(test_eq(v3[1],  32.0f))

  TEST_SUCCESS
}

TEST_IMPL(GLM_PREFIX, vec2_abs) {
  vec2  v1 = {2, -3}, v2 = {-12, -31};
  vec2  v3, v4;
  vec2  v5 = {2, 3}, v6 = {12, 31};

  GLM(vec2_abs)(v1, v3);
  GLM(vec2_abs)(v2, v4);

  ASSERTIFY(test_assert_vec2_eq(v3, v5))
  ASSERTIFY(test_assert_vec2_eq(v4, v6))

  TEST_SUCCESS
}

TEST_IMPL(GLM_PREFIX, vec2_fract) {
  vec2 v1 = {2.104f, 3.012f}, v2 = {12.35f, 31.140f}, v3, v4;
  vec2 v5 = {0.104f, 0.012f}, v6 = {0.35f, 0.140f};

  GLM(vec2_fract)(v1, v3);
  GLM(vec2_fract)(v2, v4);

  ASSERTIFY(test_assert_vec2_eq(v3, v5))
  ASSERTIFY(test_assert_vec2_eq(v4, v6))

  TEST_SUCCESS
}

TEST_IMPL(GLM_PREFIX, vec2_floor) {
  vec2 v1 = {2.104f, 3.012f}, v2 = {12.35f, 31.140f}, v3, v4;
  vec2 v5 = {2.0f, 3.0f}, v6 = {12.0f, 31.0f};

  GLM(vec2_floor)(v1, v3);
  GLM(vec2_floor)(v2, v4);

  ASSERTIFY(test_assert_vec2_eq(v3, v5))
  ASSERTIFY(test_assert_vec2_eq(v4, v6))

  TEST_SUCCESS
}

TEST_IMPL(GLM_PREFIX, vec2_mods) {
  vec2 v1 = {2.104f, 3.012f}, v2 = {12.35f, 31.140f}, v3, v4;
  vec2 v5 = {0.104f, 0.012f}, v6 = {0.35f, 0.140f};

  /* Mod 1 - leaves just the fractional part */
  GLM(vec2_mods)(v1, 1.0f, v3);
  GLM(vec2_mods)(v2, 1.0f, v4);

  ASSERTIFY(test_assert_vec2_eq(v3, v5))
  ASSERTIFY(test_assert_vec2_eq(v4, v6))

  /* Mod 2 - parity + fractional part */
  GLM(vec2_mods)(v1, 2.0f, v3);
  GLM(vec2_mods)(v2, 2.0f, v4);

  vec2 v7 = {0.104f, 1.012f}, v8 = {0.35f, 1.140f};

  ASSERTIFY(test_assert_vec2_eq(v3, v7))
  ASSERTIFY(test_assert_vec2_eq(v4, v8))

  TEST_SUCCESS
}

TEST_IMPL(GLM_PREFIX, vec2_swizzle) {
  vec2 v;

  v[0] = 1;
  v[1] = 2;
  
  GLM(vec2_swizzle)(v, GLM_SHUFFLE2(1, 0), v);
  ASSERTIFY(test_assert_vec2_eq(v, (vec2){2, 1}))
  
  GLM(vec2_swizzle)(v, GLM_SHUFFLE2(0, 0), v);
  ASSERTIFY(test_assert_vec2_eq(v, (vec2){1, 1}))
  
  TEST_SUCCESS
}

TEST_IMPL(GLM_PREFIX, vec2_lerp) {
  vec2 v1 = {-100.0f, -200.0f};
  vec2 v2 = {100.0f, 200.0f};
  vec2 v3;

  GLM(vec2_lerp)(v1, v2, 0.5f, v3);
  ASSERT(test_eq(v3[0], 0.0f))
  ASSERT(test_eq(v3[1], 0.0f))
  
  GLM(vec2_lerp)(v1, v2, 0.75f, v3);
  ASSERT(test_eq(v3[0], 50.0f))
  ASSERT(test_eq(v3[1], 100.0f))

  TEST_SUCCESS
}

TEST_IMPL(GLM_PREFIX, vec2_steps) {
  vec2 v1 = {-100.0f, -200.0f};
  vec2 v2;

  GLM(vec2_steps)(-2.5f, v1, v2);
  ASSERT(test_eq(v2[0], 0.0f))
  ASSERT(test_eq(v2[1], 0.0f))
  
  GLM(vec2_steps)(-150.0f, v1, v2);
  ASSERT(test_eq(v2[0], 1.0f))
  ASSERT(test_eq(v2[1], 0.0f))
  
  GLM(vec2_steps)(-300.0f, v1, v2);
  ASSERT(test_eq(v2[0], 1.0f))
  ASSERT(test_eq(v2[1], 1.0f))

  TEST_SUCCESS
}

TEST_IMPL(GLM_PREFIX, vec2_stepr) {
  vec2 v1 = {-2.5f, -150.0f};
  vec2 v2;

  GLM(vec2_stepr)(v1, -200.0f, v2);
  ASSERT(test_eq(v2[0], 0.0f))
  ASSERT(test_eq(v2[1], 0.0f))
  
  GLM(vec2_stepr)(v1, -150.0f, v2);
  ASSERT(test_eq(v2[0], 0.0f))
  ASSERT(test_eq(v2[1], 1.0f))
  
  GLM(vec2_stepr)(v1, 0.0f, v2);
  ASSERT(test_eq(v2[0], 1.0f))
  ASSERT(test_eq(v2[1], 1.0f))

  TEST_SUCCESS
}

TEST_IMPL(GLM_PREFIX, vec2_step) {
  vec2 v1 = {-100.0f, -200.0f};
  vec2 s1 = {-100.0f, 0.0f};
  vec2 s2 = {100.0f, -220.0f};
  vec2 s3 = {100.0f, 200.0f};
  vec2 v2;

  GLM(vec2_step)(s1, v1, v2);
  ASSERT(test_eq(v2[0], 1.0f))
  ASSERT(test_eq(v2[1], 0.0f))
  
  GLM(vec2_step)(s2, v1, v2);
  ASSERT(test_eq(v2[0], 0.0f))
  ASSERT(test_eq(v2[1], 1.0f))
  
  GLM(vec2_step)(s3, v1, v2);
  ASSERT(test_eq(v2[0], 0.0f))
  ASSERT(test_eq(v2[1], 0.0f))

  TEST_SUCCESS
}

TEST_IMPL(GLM_PREFIX, vec2_complex_mul) {
  vec2 v1 = { 3.0f,  5.0f },
       v2 = { 7.0f, 11.0f },
       v3 = { cosf(GLM_PIf/4.0f), sinf(GLM_PIf/4.0f) };

  GLM(vec2_complex_mul)(v1, v2, v2);
  ASSERTIFY(test_assert_vec2_eq(v2, (vec2){ -34, 68 }))

  GLM(vec2_complex_mul)(v3, v3, v3);
  ASSERTIFY(test_assert_vec2_eq(v3, (vec2){ 0.0f, 1.0f }))

  TEST_SUCCESS
}

TEST_IMPL(GLM_PREFIX, vec2_complex_div) {
  vec2 v1 = { -34.0f,  68.0f },
       v2 = {   3.0f,   5.0f },
       v3 = { cosf(GLM_PIf/4.0f),  sinf(GLM_PIf/4.0f) },
       v4 = { cosf(GLM_PIf/4.0f), -sinf(GLM_PIf/4.0f) };
  
  GLM(vec2_complex_div)(v1, v2, v2);
  ASSERTIFY(test_assert_vec2_eq(v2, (vec2){ 7.0f, 11.0f }))

  GLM(vec2_complex_div)(v3, v4, v4);
  ASSERTIFY(test_assert_vec2_eq(v4, (vec2){ 0.0f, 1.0f }))

  TEST_SUCCESS
}

TEST_IMPL(GLM_PREFIX, vec2_make) {
  float src[6] = {
    7.2f, 1.0f,
    2.5f, 6.1f,
    17.7f, 4.3f
  };
  vec2 dest[3];

  float *srcp = src;
  unsigned int i, j;

  for (i = 0, j = 0; i < sizeof(src) / sizeof(float); i+=2,j++) {
    GLM(vec2_make)(srcp + i, dest[j]);
    ASSERT(test_eq(src[ i ], dest[j][0]));
    ASSERT(test_eq(src[i+1], dest[j][1]));
  }

  TEST_SUCCESS
}

TEST_IMPL(GLM_PREFIX, vec2_reflect) {
  vec2 dest;

  /* Reflecting off a "horizontal" surface in 2D */
  vec2 I1 = {1.0f, -1.0f}; /* Incoming vector */
  vec2 N1 = {0.0f, 1.0f};  /* Normal vector */
  GLM(vec2_reflect)(I1, N1, dest);
  ASSERT(fabsf(dest[0] - 1.0f) < 0.00001f &&
         fabsf(dest[1] - 1.0f) < 0.00001f); /* Expect reflection upwards */

  /* Reflecting at an angle in 2D */
  vec2 I2 = {sqrtf(2)/2, -sqrtf(2)/2}; /* Incoming vector at 45 degrees */
  vec2 N2 = {0.0f, 1.0f}; /* Upwards normal vector */
  GLM(vec2_reflect)(I2, N2, dest);
  ASSERT(fabsf(dest[0] - sqrtf(2)/2) < 0.00001f &&
         fabsf(dest[1] - sqrtf(2)/2) < 0.00001f); /* Expect reflection upwards */

  /* Reflecting off a line in 2D representing a "vertical" surface analogy */
  vec2 I3 = {1.0f, 0.0f};  /* Incoming vector */
  vec2 N3 = {-1.0f, 0.0f}; /* Normal vector representing a "vertical" line */
  GLM(vec2_reflect)(I3, N3, dest);
  ASSERT(fabsf(dest[0] + 1.0f) < 0.00001f &&
         fabsf(dest[1]) < 0.00001f); /* Expect reflection to the left */

  TEST_SUCCESS
}

TEST_IMPL(GLM_PREFIX, vec2_refract) {
  vec2  v = {sqrtf(0.5f), -sqrtf(0.5f)}; /* Incoming vector at 45 degrees to normal */
  vec2  N = {0.0f, 1.0f};                /* Surface normal */
  vec2  dest;
  float eta;
  float r;

  /* Water to Air (eta = 1.33/1.0) */
  eta = 1.33f / 1.0f;
  r = GLM(vec2_refract)(v, N, eta, dest);
  // In 2D, we expect a similar bending behavior as in 3D, so we check dest[1]
  if (!(dest[0] == 0.0f && dest[1] == 0.0f)) {
    ASSERT(dest[1] < -0.3f); // Refracted ray bends away from the normal
    ASSERT(r == true);
  } else {
    ASSERT(dest[0] == 0.0f && dest[1] == 0.0f); // Total internal reflection
    ASSERT(r == false);
  }

  /* Air to Glass (eta = 1.0 / 1.5) */
  eta = 1.0f / 1.5f;
  r = GLM(vec2_refract)(v, N, eta, dest);
  ASSERT(r == true);
  ASSERT(dest[1] < -sqrtf(0.5f)); // Expect bending towards the normal

  /* Glass to Water (eta = 1.5 / 1.33) */
  eta = 1.5f / 1.33f;
  r = GLM(vec2_refract)(v, N, eta, dest);
  ASSERT(r == true);
  ASSERT(dest[1] < -0.6f); // Expect bending towards the normal, less bending than air to glass

  /* Diamond to Air (eta = 2.42 / 1.0) */
  eta = 2.42f / 1.0f;
  r = GLM(vec2_refract)(v, N, eta, dest);
  if (!(dest[0] == 0.0f && dest[1] == 0.0f)) {
    /* High potential for total internal reflection, but if it occurs, expect significant bending */
    ASSERT(dest[1] < -sqrtf(0.5f));
    ASSERT(r == true);
  } else {
    ASSERT(dest[0] == 0.0f && dest[1] == 0.0f); // Total internal reflection
    ASSERT(r == false);
  }

  TEST_SUCCESS
}
