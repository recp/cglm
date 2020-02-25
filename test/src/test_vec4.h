/*
 * Copyright (c), Recep Aslantas.
 *
 * MIT License (MIT), http://opensource.org/licenses/MIT
 * Full license can be found in the LICENSE file
 */

#include "test_common.h"

#define TEST_GLM_SHUFFLE4(z, y, x, w) (((z) << 6) | ((y) << 4) | ((x) << 2)|(w))

#ifndef CGLM_TEST_VEC4_ONCE
#define CGLM_TEST_VEC4_ONCE

/* Macros */

TEST_IMPL(MACRO_GLM_VEC4_ONE_INIT) {
  vec4 v = GLM_VEC4_ONE_INIT;
  
  ASSERT(test_eq(v[0], 1.0f))
  ASSERT(test_eq(v[1], 1.0f))
  ASSERT(test_eq(v[2], 1.0f))
  ASSERT(test_eq(v[3], 1.0f))
  
  TEST_SUCCESS
}

TEST_IMPL(MACRO_GLM_VEC4_ZERO_INIT) {
  vec4 v = GLM_VEC4_ZERO_INIT;
  
  ASSERT(test_eq(v[0], 0.0f))
  ASSERT(test_eq(v[1], 0.0f))
  ASSERT(test_eq(v[2], 0.0f))
  ASSERT(test_eq(v[3], 0.0f))
  
  TEST_SUCCESS
}

TEST_IMPL(MACRO_GLM_VEC4_ONE) {
  ASSERT(test_eq(GLM_VEC4_ONE[0], 1.0f))
  ASSERT(test_eq(GLM_VEC4_ONE[1], 1.0f))
  ASSERT(test_eq(GLM_VEC4_ONE[2], 1.0f))
  ASSERT(test_eq(GLM_VEC4_ONE[3], 1.0f))
  
  TEST_SUCCESS
}

TEST_IMPL(MACRO_GLM_VEC4_ZERO) {
  ASSERT(test_eq(GLM_VEC4_ZERO[0], 0.0f))
  ASSERT(test_eq(GLM_VEC4_ZERO[1], 0.0f))
  ASSERT(test_eq(GLM_VEC4_ZERO[2], 0.0f))
  ASSERT(test_eq(GLM_VEC4_ZERO[3], 0.0f))
  
  TEST_SUCCESS
}

TEST_IMPL(MACRO_GLM_XXXX) {
  ASSERT(TEST_GLM_SHUFFLE4(0, 0, 0, 0) == GLM_XXXX)
  TEST_SUCCESS
}

TEST_IMPL(MACRO_GLM_YYYY) {
  ASSERT(TEST_GLM_SHUFFLE4(1, 1, 1, 1) == GLM_YYYY)
  TEST_SUCCESS
}

TEST_IMPL(MACRO_GLM_ZZZZ) {
  ASSERT(TEST_GLM_SHUFFLE4(2, 2, 2, 2) == GLM_ZZZZ)
  TEST_SUCCESS
}

TEST_IMPL(MACRO_GLM_WZYX) {
  ASSERT(TEST_GLM_SHUFFLE4(0, 1, 2, 3) == GLM_WZYX)
  TEST_SUCCESS
}

/* Deprecated */

TEST_IMPL(MACRO_glm_vec4_dup) {
  vec4 v1 = {13.0f, 12.0f, 11.0f, 56.0f}, v2;
  
  glm_vec4_dup(v1, v2);
  
  ASSERTIFY(test_assert_vec4_eq(v1, v2))

  TEST_SUCCESS
}

TEST_IMPL(MACRO_glm_vec4_flipsign) {
  vec4 v1 = {13.0f, -12.0f, 11.0f, 56.0f},
       v2 = {13.0f, -12.0f, 11.0f, 56.0f},
       v3 = {-13.0f, 12.0f, -11.0f, -56.0f};
  
  glm_vec4_flipsign(v1);
  glmc_vec4_flipsign(v2);

  ASSERTIFY(test_assert_vec4_eq(v1, v3))
  ASSERTIFY(test_assert_vec4_eq(v2, v3))
  
  TEST_SUCCESS
}

TEST_IMPL(MACRO_glm_vec4_flipsign_to) {
  vec4 v1 = {13.0f, -12.0f, 11.0f, 56.0f},
       v2 = {-13.0f, 12.0f, -11.0f, -56.0f},
       v3, v4;
  
  glm_vec4_flipsign_to(v1, v3);
  glmc_vec4_flipsign_to(v1, v4);

  ASSERTIFY(test_assert_vec4_eq(v2, v3))
  ASSERTIFY(test_assert_vec4_eq(v2, v4))
  
  TEST_SUCCESS
}

TEST_IMPL(MACRO_glm_vec4_inv) {
  vec4 v1 = {13.0f, -12.0f, 11.0f, 56.0f},
       v2 = {13.0f, -12.0f, 11.0f, 56.0f},
       v3 = {-13.0f, 12.0f, -11.0f, -56.0f};
  
  glm_vec4_inv(v1);
  glmc_vec4_inv(v2);

  ASSERTIFY(test_assert_vec4_eq(v1, v3))
  ASSERTIFY(test_assert_vec4_eq(v2, v3))
  
  TEST_SUCCESS
}

TEST_IMPL(MACRO_glm_vec4_inv_to) {
  vec4 v1 = {13.0f, -12.0f, 11.0f, 56.0f},
       v2 = {-13.0f, 12.0f, -11.0f, -56.0f},
       v3, v4;

  glm_vec4_inv_to(v1, v3);
  glmc_vec4_inv_to(v1, v4);

  ASSERTIFY(test_assert_vec4_eq(v3, v4))
  ASSERTIFY(test_assert_vec4_eq(v2, v3))
  
  TEST_SUCCESS
}

TEST_IMPL(MACRO_glm_vec4_mulv) {
  vec4 v1 = {2.0f, -3.0f, 4.0f, 56.0f},
       v2 = {-3.0f, 4.0f, -5.0f, 56.0f},
       v3, v4;

  glm_vec4_mulv(v1, v2, v3);
  glmc_vec4_mulv(v1, v2, v4);

  ASSERTIFY(test_assert_vec4_eq(v3, v4))

  ASSERT(test_eq(v1[0] * v2[0], v3[0]))
  ASSERT(test_eq(v1[1] * v2[1], v3[1]))
  ASSERT(test_eq(v1[2] * v2[2], v3[2]))
  ASSERT(test_eq(v1[3] * v2[3], v3[3]))
  
  TEST_SUCCESS
}

#endif /* CGLM_TEST_VEC4_ONCE */

/* --- */

TEST_IMPL(GLM_PREFIX, vec4) {
  vec4 v1 = {10.0f, 9.0f, 8.0f};
  vec4 v2 = {10.0f, 9.0f, 8.0f, 7.0f};
  vec4 v3;
  
  GLM(vec4)(v1, 7.0f, v3);
  
  ASSERTIFY(test_assert_vec4_eq(v2, v3))

  TEST_SUCCESS
}

TEST_IMPL(GLM_PREFIX, vec4_copy3) {
  vec4 v4 = {10.0f, 9.0f, 8.0f, 7.0f};
  vec3 v3;
  
  GLM(vec4_copy3)(v4, v3);
  
  ASSERTIFY(test_assert_vec3_eq(v3, v4))
  
  TEST_SUCCESS
}

TEST_IMPL(GLM_PREFIX, vec4_copy) {
  vec4 v1 = {10.0f, 9.0f, 8.0f, 78.0f};
  vec4 v2 = {1.0f, 2.0f, 3.0f, 4.0f};
  
  GLM(vec4_copy)(v1, v2);
  
  ASSERTIFY(test_assert_vec4_eq(v1, v2))
  
  TEST_SUCCESS
}

TEST_IMPL(GLM_PREFIX, vec4_ucopy) {
  vec4 v1 = {10.0f, 9.0f, 8.0f, 78.0f};
  vec4 v2 = {1.0f, 2.0f, 3.0f, 4.0f};
  
  GLM(vec4_ucopy)(v1, v2);
  
  ASSERTIFY(test_assert_vec4_eq(v1, v2))
  
  TEST_SUCCESS
}

TEST_IMPL(GLM_PREFIX, vec4_zero) {
  vec4 v1 = {10.0f, 9.0f, 8.0f, 78.0f};
  vec4 v2 = {1.0f, 2.0f, 3.0f, 4.0f};
  
  GLM(vec4_zero)(v1);
  GLM(vec4_zero)(v2);
  
  ASSERTIFY(test_assert_vec4_eq(v1, GLM_VEC4_ZERO))
  ASSERTIFY(test_assert_vec4_eq(v2, GLM_VEC4_ZERO))
  
  TEST_SUCCESS
}

TEST_IMPL(GLM_PREFIX, vec4_one) {
  vec4 v1 = {10.0f, 9.0f, 8.0f, 78.0f};
  vec4 v2 = {1.0f, 2.0f, 3.0f, 4.0f};
  
  GLM(vec4_one)(v1);
  GLM(vec4_one)(v2);
  
  ASSERTIFY(test_assert_vec4_eq(v1, GLM_VEC4_ONE))
  ASSERTIFY(test_assert_vec4_eq(v2, GLM_VEC4_ONE))
  
  TEST_SUCCESS
}

TEST_IMPL(GLM_PREFIX, vec4_dot) {
  vec4  a = {10.0f, 9.0f, 8.0f, 78.0f};
  vec4  b = {1.0f, 2.0f, 3.0f, 4.0f};
  float dot1, dot2;
  
  dot1 = GLM(vec4_dot)(a, b);
  dot2 = a[0] * b[0] + a[1] * b[1] + a[2] * b[2] + a[3] * b[3];
  
  ASSERT(test_eq(dot1, dot2))
  
  TEST_SUCCESS
}

TEST_IMPL(GLM_PREFIX, vec4_norm2) {
  vec4  a = {10.0f, 9.0f, 8.0f, 78.0f};
  float n1, n2;
  
  n1 = GLM(vec4_norm2)(a);
  n2 = a[0] * a[0] + a[1] * a[1] + a[2] * a[2] + a[3] * a[3];

  ASSERT(test_eq(n1, n2))

  TEST_SUCCESS
}

TEST_IMPL(GLM_PREFIX, vec4_norm) {
  vec4  a = {10.0f, 9.0f, 8.0f, 78.0f};
  float n1, n2;
  
  n1 = GLM(vec4_norm)(a);
  n2 = sqrtf(a[0] * a[0] + a[1] * a[1] + a[2] * a[2] + a[3] * a[3]);

  ASSERT(test_eq(n1, n2))

  TEST_SUCCESS
}

TEST_IMPL(GLM_PREFIX, vec4_norm_one) {
  vec4  a = {-10.0f, 9.0f, -8.0f, 78.0f};
  float n1, n2;
  
  n1 = GLM(vec4_norm_one)(a);
  n2 = fabsf(a[0]) + fabsf(a[1]) + fabsf(a[2]) + fabsf(a[3]);

  ASSERT(test_eq(n1, n2))

  TEST_SUCCESS
}

TEST_IMPL(GLM_PREFIX, vec4_norm_inf) {
  vec4  a = {-10.0f, 9.0f, -8.0f, 78.0f};
  float n1, n2;
  
  n1 = GLM(vec4_norm_inf)(a);
  n2 = fabsf(a[0]);
  
  if (n2 < fabsf(a[1]))
    n2 = fabsf(a[1]);
  
  if (n2 < fabsf(a[2]))
    n2 = fabsf(a[2]);
  
  if (n2 < fabsf(a[3]))
    n2 = fabsf(a[3]);
  
  ASSERT(test_eq(n1, n2))

  TEST_SUCCESS
}

TEST_IMPL(GLM_PREFIX, vec4_add) {
  vec4 a = {-10.0f, 9.0f, -8.0f, 56.0f};
  vec4 b = {12.0f, 19.0f, -18.0f, 1.0f};
  vec4 c, d;
  
  c[0] = a[0] + b[0];
  c[1] = a[1] + b[1];
  c[2] = a[2] + b[2];
  c[3] = a[3] + b[3];
  
  GLM(vec4_add)(a, b, d);
  
  ASSERTIFY(test_assert_vec4_eq(c, d))

  TEST_SUCCESS
}

TEST_IMPL(GLM_PREFIX, vec4_adds) {
  vec4  a = {-10.0f, 9.0f, -8.0f, 56.0f};
  vec4  c, d;
  float s = 7.0f;
  
  c[0] = a[0] + s;
  c[1] = a[1] + s;
  c[2] = a[2] + s;
  c[3] = a[3] + s;
  
  GLM(vec4_adds)(a, s, d);
  
  ASSERTIFY(test_assert_vec4_eq(c, d))

  TEST_SUCCESS
}

TEST_IMPL(GLM_PREFIX, vec4_sub) {
  vec4 a = {-10.0f, 9.0f, -8.0f, 56.0f};
  vec4 b = {12.0f, 19.0f, -18.0f, 1.0f};
  vec4 c, d;
  
  c[0] = a[0] - b[0];
  c[1] = a[1] - b[1];
  c[2] = a[2] - b[2];
  c[3] = a[3] - b[3];
  
  GLM(vec4_sub)(a, b, d);
  
  ASSERTIFY(test_assert_vec4_eq(c, d))

  TEST_SUCCESS
}

TEST_IMPL(GLM_PREFIX, vec4_subs) {
  vec4  a = {-10.0f, 9.0f, -8.0f, 74.0f};
  vec4  c, d;
  float s = 7.0f;
  
  c[0] = a[0] - s;
  c[1] = a[1] - s;
  c[2] = a[2] - s;
  c[3] = a[3] - s;
  
  GLM(vec4_subs)(a, s, d);
  
  ASSERTIFY(test_assert_vec4_eq(c, d))

  TEST_SUCCESS
}

TEST_IMPL(GLM_PREFIX, vec4_mul) {
  vec4 v1 = {2.0f, -3.0f, 4.0f, 56.0f},
       v2 = {-3.0f, 4.0f, -5.0f, 46.0f},
       v3;
  
  GLM(vec4_mul)(v1, v2, v3);

  ASSERT(test_eq(v1[0] * v2[0], v3[0]))
  ASSERT(test_eq(v1[1] * v2[1], v3[1]))
  ASSERT(test_eq(v1[2] * v2[2], v3[2]))
  ASSERT(test_eq(v1[3] * v2[3], v3[3]))
  
  TEST_SUCCESS
}

TEST_IMPL(GLM_PREFIX, vec4_scale) {
  vec4  v1 = {2.0f, -3.0f, 4.0f, 5.0f}, v2;
  float s  = 7.0f;
  
  GLM(vec4_scale)(v1, s, v2);

  ASSERT(test_eq(v1[0] * s, v2[0]))
  ASSERT(test_eq(v1[1] * s, v2[1]))
  ASSERT(test_eq(v1[2] * s, v2[2]))
  ASSERT(test_eq(v1[3] * s, v2[3]))
  
  TEST_SUCCESS
}

TEST_IMPL(GLM_PREFIX, vec4_scale_as) {
  vec4  v1 = {2.0f, -3.0f, 4.0f, 5.0f}, v2;
  float s  = 7.0f;
  float norm;

  GLM(vec4_scale_as)(v1, s, v2);

  norm = sqrtf(v1[0] * v1[0] + v1[1] * v1[1] + v1[2] * v1[2] + v1[3] * v1[3]);
  if (norm == 0.0f) {
    ASSERT(test_eq(v1[0], 0.0f))
    ASSERT(test_eq(v1[1], 0.0f))
    ASSERT(test_eq(v1[2], 0.0f))
    ASSERT(test_eq(v1[3], 0.0f))

    TEST_SUCCESS
  }
  
  norm = s / norm;
  
  ASSERT(test_eq(v1[0] * norm, v2[0]))
  ASSERT(test_eq(v1[1] * norm, v2[1]))
  ASSERT(test_eq(v1[2] * norm, v2[2]))
  ASSERT(test_eq(v1[3] * norm, v2[3]))

  TEST_SUCCESS
}

TEST_IMPL(GLM_PREFIX, vec4_div) {
  vec4 v1 = {2.0f, -3.0f, 4.0f, 40.0f},
       v2 = {-3.0f, 4.0f, -5.0f, 2.0f},
       v3;
  
  GLM(vec4_div)(v1, v2, v3);

  ASSERT(test_eq(v1[0] / v2[0], v3[0]))
  ASSERT(test_eq(v1[1] / v2[1], v3[1]))
  ASSERT(test_eq(v1[2] / v2[2], v3[2]))
  ASSERT(test_eq(v1[3] / v2[3], v3[3]))
  
  TEST_SUCCESS
}

TEST_IMPL(GLM_PREFIX, vec4_divs) {
  vec4  v1 = {2.0f, -3.0f, 4.0f, 40.0f}, v2;
  float s  = 7.0f;
  
  GLM(vec4_divs)(v1, s, v2);

  ASSERT(test_eq(v1[0] / s, v2[0]))
  ASSERT(test_eq(v1[1] / s, v2[1]))
  ASSERT(test_eq(v1[2] / s, v2[2]))
  ASSERT(test_eq(v1[3] / s, v2[3]))
  
  TEST_SUCCESS
}

TEST_IMPL(GLM_PREFIX, vec4_addadd) {
  vec4 v1 = {2.0f, -3.0f, 4.0f, 4.0f},
       v2 = {-3.0f, 4.0f, -5.0f, 20.0f},
       v3 = {1.0f, 2.0f, 3.0f, 130.0f},
       v4 = {1.0f, 2.0f, 3.0f, 130.0f};
  
  GLM(vec4_addadd)(v1, v2, v4);

  ASSERT(test_eq(v3[0] + v1[0] + v2[0], v4[0]))
  ASSERT(test_eq(v3[1] + v1[1] + v2[1], v4[1]))
  ASSERT(test_eq(v3[2] + v1[2] + v2[2], v4[2]))
  ASSERT(test_eq(v3[3] + v1[3] + v2[3], v4[3]))
  
  TEST_SUCCESS
}

TEST_IMPL(GLM_PREFIX, vec4_subadd) {
  vec4 v1 = {2.0f, -3.0f, 4.0f, 4.0f},
       v2 = {-3.0f, 4.0f, -5.0f, 20.0f},
       v3 = {1.0f, 2.0f, 3.0f, 130.0f},
       v4 = {1.0f, 2.0f, 3.0f, 130.0f};
  
  GLM(vec4_subadd)(v1, v2, v4);

  ASSERT(test_eq(v3[0] + v1[0] - v2[0], v4[0]))
  ASSERT(test_eq(v3[1] + v1[1] - v2[1], v4[1]))
  ASSERT(test_eq(v3[2] + v1[2] - v2[2], v4[2]))
  ASSERT(test_eq(v3[3] + v1[3] - v2[3], v4[3]))
  
  TEST_SUCCESS
}

TEST_IMPL(GLM_PREFIX, vec4_muladd) {
  vec4 v1 = {2.0f, -3.0f, 4.0f, 4.0f},
       v2 = {-3.0f, 4.0f, -5.0f, 20.0f},
       v3 = {1.0f, 2.0f, 3.0f, 130.0f},
       v4 = {1.0f, 2.0f, 3.0f, 130.0f};
  
  GLM(vec4_muladd)(v1, v2, v4);

  ASSERT(test_eq(v3[0] + v1[0] * v2[0], v4[0]))
  ASSERT(test_eq(v3[1] + v1[1] * v2[1], v4[1]))
  ASSERT(test_eq(v3[2] + v1[2] * v2[2], v4[2]))
  ASSERT(test_eq(v3[3] + v1[3] * v2[3], v4[3]))
  
  TEST_SUCCESS
}

TEST_IMPL(GLM_PREFIX, vec4_muladds) {
  vec4 v1 = {2.0f, -3.0f, 4.0f, 4.0f},
       v2 = {-3.0f, 4.0f, -5.0f, 20.0f},
       v3 = {-3.0f, 4.0f, -5.0f, 20.0f};
  float s = 9.0f;
  
  GLM(vec4_muladds)(v1, s, v3);

  ASSERT(test_eq(v2[0] + v1[0] * s, v3[0]))
  ASSERT(test_eq(v2[1] + v1[1] * s, v3[1]))
  ASSERT(test_eq(v2[2] + v1[2] * s, v3[2]))
  ASSERT(test_eq(v2[3] + v1[3] * s, v3[3]))
  
  TEST_SUCCESS
}

TEST_IMPL(GLM_PREFIX, vec4_maxadd) {
  vec4 v1 = {2.0f, -3.0f, 4.0f, 4.0f},
       v2 = {-3.0f, 4.0f, -5.0f, 20.0f},
       v3 = {1.0f, 2.0f, 3.0f, 130.0f},
       v4 = {1.0f, 2.0f, 3.0f, 130.0f};
  
  GLM(vec4_maxadd)(v1, v2, v4);

  ASSERT(test_eq(v3[0] + glm_max(v1[0], v2[0]), v4[0]))
  ASSERT(test_eq(v3[1] + glm_max(v1[1], v2[1]), v4[1]))
  ASSERT(test_eq(v3[2] + glm_max(v1[2], v2[2]), v4[2]))
  ASSERT(test_eq(v3[3] + glm_max(v1[3], v2[3]), v4[3]))
  
  TEST_SUCCESS
}

TEST_IMPL(GLM_PREFIX, vec4_minadd) {
  vec4 v1 = {2.0f, -3.0f, 4.0f, 4.0f},
       v2 = {-3.0f, 4.0f, -5.0f, 20.0f},
       v3 = {1.0f, 2.0f, 3.0f, 130.0f},
       v4 = {1.0f, 2.0f, 3.0f, 130.0f};
  
  GLM(vec4_minadd)(v1, v2, v4);

  ASSERT(test_eq(v3[0] + glm_min(v1[0], v2[0]), v4[0]))
  ASSERT(test_eq(v3[1] + glm_min(v1[1], v2[1]), v4[1]))
  ASSERT(test_eq(v3[2] + glm_min(v1[2], v2[2]), v4[2]))
  ASSERT(test_eq(v3[3] + glm_min(v1[3], v2[3]), v4[3]))
  
  TEST_SUCCESS
}

TEST_IMPL(GLM_PREFIX, vec4_negate_to) {
  vec4 v1 = {2.0f, -3.0f, 4.0f, 60.0f},
       v2 = {-3.0f, 4.0f, -5.0f, 34.0f},
       v3, v4;
  
  GLM(vec4_negate_to)(v1, v3);
  GLM(vec4_negate_to)(v2, v4);

  ASSERT(test_eq(-v1[0], v3[0]))
  ASSERT(test_eq(-v1[1], v3[1]))
  ASSERT(test_eq(-v1[2], v3[2]))
  ASSERT(test_eq(-v1[3], v3[3]))
  
  ASSERT(test_eq(-v2[0], v4[0]))
  ASSERT(test_eq(-v2[1], v4[1]))
  ASSERT(test_eq(-v2[2], v4[2]))
  ASSERT(test_eq(-v2[3], v4[3]))
  
  TEST_SUCCESS
}

TEST_IMPL(GLM_PREFIX, vec4_negate) {
  vec4 v1 = {2.0f, -3.0f, 4.0f, 60.0f},
       v2 = {-3.0f, 4.0f, -5.0f, 34.0f},
       v3 = {2.0f, -3.0f, 4.0f, 60.0f},
       v4 = {-3.0f, 4.0f, -5.0f, 34.0f};
  
  GLM(vec4_negate)(v1);
  GLM(vec4_negate)(v2);

  ASSERT(test_eq(-v1[0], v3[0]))
  ASSERT(test_eq(-v1[1], v3[1]))
  ASSERT(test_eq(-v1[2], v3[2]))
  ASSERT(test_eq(-v1[3], v3[3]))
  
  ASSERT(test_eq(-v2[0], v4[0]))
  ASSERT(test_eq(-v2[1], v4[1]))
  ASSERT(test_eq(-v2[2], v4[2]))
  ASSERT(test_eq(-v2[3], v4[3]))
  
  TEST_SUCCESS
}

TEST_IMPL(GLM_PREFIX, vec4_normalize) {
  vec4  v1 = {2.0f, -3.0f, 4.0f, 5.0f}, v2 = {2.0f, -3.0f, 4.0f, 5.0f};
  float s  = 1.0f;
  float norm;

  GLM(vec4_normalize)(v2);

  norm = sqrtf(v1[0] * v1[0] + v1[1] * v1[1] + v1[2] * v1[2] + v1[3] * v1[3]);
  if (norm == 0.0f) {
    ASSERT(test_eq(v1[0], 0.0f))
    ASSERT(test_eq(v1[1], 0.0f))
    ASSERT(test_eq(v1[2], 0.0f))
    ASSERT(test_eq(v1[3], 0.0f))

    TEST_SUCCESS
  }
  
  norm = s / norm;
  
  ASSERT(test_eq(v1[0] * norm, v2[0]))
  ASSERT(test_eq(v1[1] * norm, v2[1]))
  ASSERT(test_eq(v1[2] * norm, v2[2]))
  ASSERT(test_eq(v1[3] * norm, v2[3]))

  glm_vec4_zero(v1);
  GLM(vec4_normalize)(v1);
  ASSERTIFY(test_assert_vec4_eq(v1, GLM_VEC4_ZERO))

  TEST_SUCCESS
}

TEST_IMPL(GLM_PREFIX, vec4_normalize_to) {
  vec4  v1 = {2.0f, -3.0f, 4.0f, 5.0f}, v2;
  float s  = 1.0f;
  float norm;

  GLM(vec4_normalize_to)(v1, v2);

  norm = sqrtf(v1[0] * v1[0] + v1[1] * v1[1] + v1[2] * v1[2] + v1[3] * v1[3]);
  if (norm == 0.0f) {
    ASSERT(test_eq(v1[0], 0.0f))
    ASSERT(test_eq(v1[1], 0.0f))
    ASSERT(test_eq(v1[2], 0.0f))
    ASSERT(test_eq(v1[3], 0.0f))

    TEST_SUCCESS
  }
  
  norm = s / norm;
  
  ASSERT(test_eq(v1[0] * norm, v2[0]))
  ASSERT(test_eq(v1[1] * norm, v2[1]))
  ASSERT(test_eq(v1[2] * norm, v2[2]))
  ASSERT(test_eq(v1[3] * norm, v2[3]))

  glm_vec4_zero(v1);
  GLM(vec4_normalize_to)(v1, v2);
  ASSERTIFY(test_assert_vec4_eq(v2, GLM_VEC4_ZERO))

  TEST_SUCCESS
}

TEST_IMPL(GLM_PREFIX, vec4_distance2) {
  vec4 v1 = {30.0f, 0.0f, 0.0f, 0.0f},
       v2 = {0.0f, 0.0f, 0.0f, 0.0f},
       v3 = {3.0f, 10.0f, 120.0f, 140.0f},
       v4 = {0.46f, 4.0f, 14.0f, 10.0f};
  float d;

  d = GLM(vec4_distance2)(v1, v2);
  ASSERT(test_eq(d, 30.0f * 30.0f))

  d = GLM(vec4_distance2)(v3, v4);
  ASSERT(test_eq(powf(v3[0] - v4[0], 2.0f)
               + powf(v3[1] - v4[1], 2.0f)
               + powf(v3[2] - v4[2], 2.0f)
               + powf(v3[3] - v4[3], 2.0f), d))

  TEST_SUCCESS
}

TEST_IMPL(GLM_PREFIX, vec4_distance) {
  vec4 v1 = {30.0f, 0.0f, 0.0f, 0.0f},
       v2 = {0.0f, 0.0f, 0.0f, 0.0f},
       v3 = {3.0f, 10.0f, 120.0f, 140.0f},
       v4 = {0.46f, 4.0f, 14.0f, 10.0f};
  float d;

  d = GLM(vec4_distance)(v1, v2);
  ASSERT(test_eq(d, 30.0f))

  d = GLM(vec4_distance)(v3, v4);
  ASSERT(test_eq(sqrtf(powf(v3[0] - v4[0], 2.0f)
                     + powf(v3[1] - v4[1], 2.0f)
                     + powf(v3[2] - v4[2], 2.0f)
                     + powf(v3[3] - v4[3], 2.0f)), d))

  TEST_SUCCESS
}

TEST_IMPL(GLM_PREFIX, vec4_maxv) {
  vec4 v1, v2, v3;
  vec4 v5 = {-1.456f, -1.456f, 241.456f, 10.0f};
  vec4 v6 = {11.0f, 11.0f, 11.0f, 90.0f};
  vec4 v7 = {78.0f, -78.0f, 7.0f, 5.0f};

  GLM(vec4_maxv)(v5, v6, v1);
  GLM(vec4_maxv)(v5, v7, v2);
  GLM(vec4_maxv)(v6, v7, v3);
  
  ASSERT(test_eq(v1[0], 11.0f))
  ASSERT(test_eq(v1[1], 11.0f))
  ASSERT(test_eq(v1[2], 241.456f))
  ASSERT(test_eq(v1[3], 90.0f))

  ASSERT(test_eq(v2[0], 78.0f))
  ASSERT(test_eq(v2[1], -1.456f))
  ASSERT(test_eq(v2[2], 241.456f))
  ASSERT(test_eq(v2[3], 10.0f))

  ASSERT(test_eq(v3[0], 78.0f))
  ASSERT(test_eq(v3[1], 11.0f))
  ASSERT(test_eq(v3[2], 11.0f))
  ASSERT(test_eq(v3[3], 90.0f))

  TEST_SUCCESS
}

TEST_IMPL(GLM_PREFIX, vec4_minv) {
  vec4 v1, v2, v3;
  vec4 v5 = {-1.456f, -1.456f, 241.456f, 10.0f};
  vec4 v6 = {11.0f, 11.0f, 11.0f, 90.0f};
  vec4 v7 = {78.0f, -78.0f, 7.0f, 5.0f};

  GLM(vec4_minv)(v5, v6, v1);
  GLM(vec4_minv)(v5, v7, v2);
  GLM(vec4_minv)(v6, v7, v3);

  ASSERT(test_eq(v1[0], -1.456f))
  ASSERT(test_eq(v1[1], -1.456f))
  ASSERT(test_eq(v1[2], 11.0f))
  ASSERT(test_eq(v1[3], 10.0f))

  ASSERT(test_eq(v2[0], -1.456f))
  ASSERT(test_eq(v2[1], -78.0f))
  ASSERT(test_eq(v2[2], 7.0f))
  ASSERT(test_eq(v2[3], 5.0f))

  ASSERT(test_eq(v3[0], 11.0f))
  ASSERT(test_eq(v3[1], -78.0f))
  ASSERT(test_eq(v3[2], 7.0f))
  ASSERT(test_eq(v3[3], 5.0f))

  TEST_SUCCESS
}

TEST_IMPL(GLM_PREFIX, vec4_clamp) {
  vec4 v1 = {-1.456f, -11.456f, 31.456f, 67.04f};
  vec4 v2 = {0.110f, 111.0f, 11.0f, 90.0f};
  vec4 v3 = {78.0f, 32.0f, -78.0f, 3.0f};

  GLM(vec4_clamp)(v1, -1.03f, 30.0f);
  GLM(vec4_clamp)(v2,  0.11f, 111.0f);
  GLM(vec4_clamp)(v3, -88.0f, 70.0f);

  ASSERT(test_eq(v1[0], -1.03f))
  ASSERT(test_eq(v1[1], -1.03f))
  ASSERT(test_eq(v1[2],  30.0f))
  ASSERT(test_eq(v1[3],  30.0f))
  
  ASSERT(test_eq(v2[0],  0.11f))
  ASSERT(test_eq(v2[1],  111.0f))
  ASSERT(test_eq(v2[2],  11.0f))
  ASSERT(test_eq(v2[3],  90.0f))
  
  ASSERT(test_eq(v3[0],  70.0f))
  ASSERT(test_eq(v3[1],  32.0f))
  ASSERT(test_eq(v3[2], -78.0f))
  ASSERT(test_eq(v3[3],  3.0f))

  TEST_SUCCESS
}

TEST_IMPL(GLM_PREFIX, vec4_lerp) {
  vec4 v1 = {-100.0f, -200.0f, -10.0f, -10.0f};
  vec4 v2 = {100.0f, 200.0f, 10.0f, 10.0f};
  vec4 v3;

  GLM(vec4_lerp)(v1, v2, 0.5f, v3);
  ASSERT(test_eq(v3[0], 0.0f))
  ASSERT(test_eq(v3[1], 0.0f))
  ASSERT(test_eq(v3[2], 0.0f))
  ASSERT(test_eq(v3[3], 0.0f))
  
  GLM(vec4_lerp)(v1, v2, 0.75f, v3);
  ASSERT(test_eq(v3[0], 50.0f))
  ASSERT(test_eq(v3[1], 100.0f))
  ASSERT(test_eq(v3[2], 5.0f))
  ASSERT(test_eq(v3[3], 5.0f))

  TEST_SUCCESS
}

TEST_IMPL(GLM_PREFIX, vec4_lerpc) {
  vec4 v1 = {-100.0f, -200.0f, -10.0f, -10.0f};
  vec4 v2 = {100.0f, 200.0f, 10.0f, 10.0f};
  vec4 v3;

  GLM(vec4_lerpc)(v1, v2, 0.5f, v3);
  ASSERT(test_eq(v3[0], 0.0f))
  ASSERT(test_eq(v3[1], 0.0f))
  ASSERT(test_eq(v3[2], 0.0f))
  ASSERT(test_eq(v3[3], 0.0f))
  
  GLM(vec4_lerpc)(v1, v2, 0.75f, v3);
  ASSERT(test_eq(v3[0], 50.0f))
  ASSERT(test_eq(v3[1], 100.0f))
  ASSERT(test_eq(v3[2], 5.0f))
  ASSERT(test_eq(v3[3], 5.0f))
  
  GLM(vec4_lerpc)(v1, v2, -1.75f, v3);
  ASSERT(test_eq(v3[0], -100.0f))
  ASSERT(test_eq(v3[1], -200.0f))
  ASSERT(test_eq(v3[2], -10.0f))
  ASSERT(test_eq(v3[3], -10.0f))
  
  GLM(vec4_lerpc)(v1, v2, 1.75f, v3);
  ASSERT(test_eq(v3[0], 100.0f))
  ASSERT(test_eq(v3[1], 200.0f))
  ASSERT(test_eq(v3[2], 10.0f))
  ASSERT(test_eq(v3[3], 10.0f))

  TEST_SUCCESS
}

TEST_IMPL(GLM_PREFIX, vec4_mix) {
  vec4 v1 = {-100.0f, -200.0f, -10.0f, -10.0f};
  vec4 v2 = {100.0f, 200.0f, 10.0f, 10.0f};
  vec4 v3;

  GLM(vec4_mix)(v1, v2, 0.5f, v3);
  ASSERT(test_eq(v3[0], 0.0f))
  ASSERT(test_eq(v3[1], 0.0f))
  ASSERT(test_eq(v3[2], 0.0f))
  ASSERT(test_eq(v3[3], 0.0f))

  GLM(vec4_mix)(v1, v2, 0.75f, v3);
  ASSERT(test_eq(v3[0], 50.0f))
  ASSERT(test_eq(v3[1], 100.0f))
  ASSERT(test_eq(v3[2], 5.0f))
  ASSERT(test_eq(v3[3], 5.0f))

  TEST_SUCCESS
}

TEST_IMPL(GLM_PREFIX, vec4_mixc) {
  vec4 v1 = {-100.0f, -200.0f, -10.0f, -10.0f};
  vec4 v2 = {100.0f, 200.0f, 10.0f, 10.0f};
  vec4 v3;

  GLM(vec4_mixc)(v1, v2, 0.5f, v3);
  ASSERT(test_eq(v3[0], 0.0f))
  ASSERT(test_eq(v3[1], 0.0f))
  ASSERT(test_eq(v3[2], 0.0f))
  ASSERT(test_eq(v3[3], 0.0f))
  
  GLM(vec4_mixc)(v1, v2, 0.75f, v3);
  ASSERT(test_eq(v3[0], 50.0f))
  ASSERT(test_eq(v3[1], 100.0f))
  ASSERT(test_eq(v3[2], 5.0f))
  ASSERT(test_eq(v3[3], 5.0f))
  
  GLM(vec4_mixc)(v1, v2, -1.75f, v3);
  ASSERT(test_eq(v3[0], -100.0f))
  ASSERT(test_eq(v3[1], -200.0f))
  ASSERT(test_eq(v3[2], -10.0f))
  ASSERT(test_eq(v3[3], -10.0f))
  
  GLM(vec4_mixc)(v1, v2, 1.75f, v3);
  ASSERT(test_eq(v3[0], 100.0f))
  ASSERT(test_eq(v3[1], 200.0f))
  ASSERT(test_eq(v3[2], 10.0f))
  ASSERT(test_eq(v3[3], 10.0f))

  TEST_SUCCESS
}

TEST_IMPL(GLM_PREFIX, vec4_step_uni) {
  vec4 v1 = {-100.0f, -200.0f, -10.0f, -10.0f};
  vec4 v2;

  GLM(vec4_step_uni)(-2.5f, v1, v2);
  ASSERT(test_eq(v2[0], 0.0f))
  ASSERT(test_eq(v2[1], 0.0f))
  ASSERT(test_eq(v2[2], 0.0f))
  ASSERT(test_eq(v2[3], 0.0f))
  
  GLM(vec4_step_uni)(-10.0f, v1, v2);
  ASSERT(test_eq(v2[0], 0.0f))
  ASSERT(test_eq(v2[1], 0.0f))
  ASSERT(test_eq(v2[2], 1.0f))
  ASSERT(test_eq(v2[3], 1.0f))
  
  GLM(vec4_step_uni)(-1000.0f, v1, v2);
  ASSERT(test_eq(v2[0], 1.0f))
  ASSERT(test_eq(v2[1], 1.0f))
  ASSERT(test_eq(v2[2], 1.0f))
  ASSERT(test_eq(v2[3], 1.0f))

  TEST_SUCCESS
}

TEST_IMPL(GLM_PREFIX, vec4_step) {
  vec4 v1 = {-100.0f, -200.0f, -10.0f, -10.0f};
  vec4 s1 = {-100.0f, 0.0f, 10.0f, 10.0f};
  vec4 s2 = {100.0f, -220.0f, -10.0f, -10.0f};
  vec4 s3 = {100.0f, 200.0f, 10.0f, 10.0f};
  vec4 v2;

  GLM(vec4_step)(s1, v1, v2);
  ASSERT(test_eq(v2[0], 1.0f))
  ASSERT(test_eq(v2[1], 0.0f))
  ASSERT(test_eq(v2[2], 0.0f))
  ASSERT(test_eq(v2[3], 0.0f))
  
  GLM(vec4_step)(s2, v1, v2);
  ASSERT(test_eq(v2[0], 0.0f))
  ASSERT(test_eq(v2[1], 1.0f))
  ASSERT(test_eq(v2[2], 1.0f))
  ASSERT(test_eq(v2[3], 1.0f))
  
  GLM(vec4_step)(s3, v1, v2);
  ASSERT(test_eq(v2[0], 0.0f))
  ASSERT(test_eq(v2[1], 0.0f))
  ASSERT(test_eq(v2[2], 0.0f))
  ASSERT(test_eq(v2[3], 0.0f))

  TEST_SUCCESS
}

TEST_IMPL(GLM_PREFIX, vec4_smoothstep_uni) {
  vec4 v1 = {-100.0f, -200.0f, -10.0f, -10.0f};
  vec4 v2;

  GLM(vec4_smoothstep_uni)(-200.0f, -100.0f, v1, v2);
  ASSERT(test_eq_th(v2[0], 1.0f, 1e-5f))
  ASSERT(test_eq_th(v2[1], 0.0f, 1e-5f))
  ASSERT(test_eq_th(v2[2], 1.0f, 1e-5f))
  ASSERT(test_eq_th(v2[3], 1.0f, 1e-5f))
  
  GLM(vec4_smoothstep_uni)(-250.0f, -200.0f, v1, v2);
  ASSERT(test_eq_th(v2[0], 1.0f, 1e-5f))
  ASSERT(test_eq_th(v2[1], 1.0f, 1e-5f))
  ASSERT(test_eq_th(v2[2], 1.0f, 1e-5f))
  ASSERT(test_eq_th(v2[3], 1.0f, 1e-5f))
  
  GLM(vec4_smoothstep_uni)(-200.0f, 200.0f, v1, v2);
  ASSERT(v2[0] > 0.0f && v2[0] < 0.25f)
  ASSERT(test_eq(v2[1], 0.0f))
  ASSERT(v2[2] > 0.0f && v2[2] < 0.5f)
  ASSERT(v2[3] > 0.0f && v2[3] < 0.5f)

  TEST_SUCCESS
}

TEST_IMPL(GLM_PREFIX, vec4_smoothstep) {
  vec4 v1   = {-100.0f, -200.0f, -10.0f, -10.0f};
  vec4 e1_0 = {-100.0f, 0.0f, -11.0f, -11.0f};
  vec4 e1_1 = {50.0f, 10.0f, 20.0f, 20.0f};
  vec4 e2_0 = {-180.0f, -300.0f, -93.0f, -93.0f};
  vec4 e2_1 = {100.0f, 120.0f, -10.0f, -10.0f};
  vec4 e3_0 = {-12.0f, 100.0f, 0.0f, 0.0f};
  vec4 e3_1 = {100.0f, 200.0f, 10.0f, 10.0f};
  vec4 v2;

  GLM(vec4_smoothstep)(e1_0, e1_1, v1, v2);
  ASSERT(test_eq_th(v2[0], 0.0f, 1e-5f))
  ASSERT(test_eq_th(v2[1], 0.0f, 1e-5f))
  ASSERT(v2[2] > 0.0f && v2[2] < 0.1f)
  ASSERT(v2[3] > 0.0f && v2[3] < 0.1f)
  
  GLM(vec4_smoothstep)(e2_0, e2_1, v1, v2);
  ASSERT(v2[0] > 0.0f && v2[0] < 0.25f)
  ASSERT(v2[1] > 0.0f && v2[1] < 0.15f)
  ASSERT(test_eq_th(v2[2], 1.0f, 1e-5f))
  ASSERT(test_eq_th(v2[3], 1.0f, 1e-5f))
  
  GLM(vec4_smoothstep)(e3_0, e3_1, v1, v2);
  ASSERT(test_eq_th(v2[0], 0.0f, 1e-5f))
  ASSERT(test_eq_th(v2[1], 0.0f, 1e-5f))
  ASSERT(test_eq_th(v2[2], 0.0f, 1e-5f))
  ASSERT(test_eq_th(v2[3], 0.0f, 1e-5f))

  TEST_SUCCESS
}

TEST_IMPL(GLM_PREFIX, vec4_smoothinterp) {
  vec4 e1_0 = {-100.0f, 0.0f, -11.0f, -11.0f};
  vec4 e1_1 = {50.0f, 10.0f, 20.0f, 20.0f};
  vec4 e2_0 = {80.0f, -220.0f, -19.0f, -19.0f};
  vec4 e2_1 = {100.0f, -200.0f, -10.0f, -10.0f};
  vec4 e3_0 = {-12.0f, 100.0f, 0.0f, 0.0f};
  vec4 e3_1 = {100.0f, 200.0f, 10.0f, 10.0f};
  vec4 v2;

  GLM(vec4_smoothinterp)(e1_0, e1_1, 0.5f, v2);
  ASSERT(v2[0] >= e1_0[0] && v2[0] <= e1_1[0])
  ASSERT(v2[1] >= e1_0[1] && v2[1] <= e1_1[1])
  ASSERT(v2[2] >= e1_0[2] && v2[2] <= e1_1[2])
  ASSERT(v2[3] >= e1_0[3] && v2[3] <= e1_1[3])
  
  GLM(vec4_smoothinterp)(e2_0, e2_1, 0.5f, v2);
  ASSERT(v2[0] >= e2_0[0] && v2[0] <= e2_1[0])
  ASSERT(v2[1] >= e2_0[1] && v2[1] <= e2_1[1])
  ASSERT(v2[2] >= e2_0[2] && v2[2] <= e2_1[2])
  ASSERT(v2[3] >= e2_0[3] && v2[3] <= e2_1[3])
  
  GLM(vec4_smoothinterp)(e3_0, e3_1, 1.0f, v2);
  ASSERT(v2[0] >= e3_0[0] && v2[0] <= e3_1[0])
  ASSERT(v2[1] >= e3_0[1] && v2[1] <= e3_1[1])
  ASSERT(v2[2] >= e3_0[2] && v2[2] <= e3_1[2])
  ASSERT(v2[3] >= e3_0[3] && v2[3] <= e3_1[3])

  TEST_SUCCESS
}

TEST_IMPL(GLM_PREFIX, vec4_smoothinterpc) {
  vec4 e1_0 = {-100.0f, 0.0f, -11.0f, -11.0f};
  vec4 e1_1 = {50.0f, 10.0f, 20.0f, 20.0f};
  vec4 e2_0 = {80.0f, -220.0f, -19.0f, -19.0f};
  vec4 e2_1 = {100.0f, -200.0f, -10.0f, -10.0f};
  vec4 e3_0 = {-12.0f, 100.0f, 0.0f, 0.0f};
  vec4 e3_1 = {100.0f, 200.0f, 10.0f, 10.0f};
  vec4 v2;

  GLM(vec4_smoothinterpc)(e1_0, e1_1, -0.5f, v2);
  ASSERT(v2[0] >= e1_0[0] && v2[0] <= e1_1[0])
  ASSERT(v2[1] >= e1_0[1] && v2[1] <= e1_1[1])
  ASSERT(v2[2] >= e1_0[2] && v2[2] <= e1_1[2])
  ASSERT(v2[3] >= e1_0[3] && v2[3] <= e1_1[3])

  GLM(vec4_smoothinterpc)(e2_0, e2_1, 0.5f, v2);
  ASSERT(v2[0] >= e2_0[0] && v2[0] <= e2_1[0])
  ASSERT(v2[1] >= e2_0[1] && v2[1] <= e2_1[1])
  ASSERT(v2[2] >= e2_0[2] && v2[2] <= e2_1[2])
  ASSERT(v2[3] >= e2_0[3] && v2[3] <= e2_1[3])

  GLM(vec4_smoothinterpc)(e3_0, e3_1, 2.0f, v2);
  ASSERT(v2[0] >= e3_0[0] && v2[0] <= e3_1[0])
  ASSERT(v2[1] >= e3_0[1] && v2[1] <= e3_1[1])
  ASSERT(v2[2] >= e3_0[2] && v2[2] <= e3_1[2])
  ASSERT(v2[3] >= e3_0[3] && v2[3] <= e3_1[3])

  TEST_SUCCESS
}

TEST_IMPL(GLM_PREFIX, vec4_cubic) {
  vec4 v1 = {125.0f, 25.0f, 5.0f, 1.0f};
  vec4 v2 = {216.0f, 36.0f, 6.0f, 1.0f};
  vec4 v3, v4;

  ASSERT(test_eq(v1[0], v1[2] * v1[2] * v1[2]))
  ASSERT(test_eq(v1[1], v1[2] * v1[2]))
  ASSERT(test_eq(v1[3], 1.0f))

  ASSERT(test_eq(v2[0], v2[2] * v2[2] * v2[2]))
  ASSERT(test_eq(v2[1], v2[2] * v2[2]))
  ASSERT(test_eq(v2[3], 1.0f))

  GLM(vec4_cubic)(test_rand(), v3);
  ASSERT(test_eq(v3[0], v3[2] * v3[2] * v3[2]))
  ASSERT(test_eq(v3[1], v3[2] * v3[2]))
  ASSERT(test_eq(v3[3], 1.0f))

  GLM(vec4_cubic)(test_rand(), v4);
  ASSERT(test_eq(v4[0], v4[2] * v4[2] * v4[2]))
  ASSERT(test_eq(v4[1], v4[2] * v4[2]))
  ASSERT(test_eq(v4[3], 1.0f))

  TEST_SUCCESS
}

TEST_IMPL(GLM_PREFIX, vec4_swizzle) {
  vec4 v;

  /* ZYX */
  v[0] = 1;
  v[1] = 2;
  v[2] = 3;
  v[3] = 4;
  
  glm_vec4_swizzle(v, GLM_WZYX, v);
  ASSERTIFY(test_assert_vec4_eq(v, (vec4){4, 3, 2, 1}))
  
  glm_vec4_swizzle(v, GLM_XXXX, v);
  ASSERTIFY(test_assert_vec4_eq(v, (vec4){4, 4, 4, 4}))
  
  v[0] = 1;
  v[1] = 2;
  v[2] = 3;
  v[3] = 4;
  
  glm_vec4_swizzle(v, GLM_YYYY, v);
  ASSERTIFY(test_assert_vec4_eq(v, (vec4){2, 2, 2, 2}))
  
  v[0] = 1;
  v[1] = 2;
  v[2] = 3;
  v[3] = 4;
  
  glm_vec4_swizzle(v, GLM_ZZZZ, v);
  ASSERTIFY(test_assert_vec4_eq(v, (vec4){3, 3, 3, 3}))
  
  v[0] = 1;
  v[1] = 2;
  v[2] = 3;
  v[3] = 4;
  
  glm_vec4_swizzle(v, GLM_WWWW, v);
  ASSERTIFY(test_assert_vec4_eq(v, (vec4){4, 4, 4, 4}))

  TEST_SUCCESS
}

TEST_IMPL(GLM_PREFIX, vec4_broadcast) {
  vec4 v1, v2, v3;
  vec4 v5 = {-1.456f, -1.456f, -1.456f, -1.456f};
  vec4 v6 = {11.0f, 11.0f, 11.0f, 11.0f};
  vec4 v7 = {78.0f, 78.0f, 78.0f, 78.0f};

  GLM(vec4_broadcast)(-1.456f, v1);
  GLM(vec4_broadcast)(11.0f,   v2);
  GLM(vec4_broadcast)(78.0f,   v3);

  ASSERTIFY(test_assert_vec4_eq(v1, v5))
  ASSERTIFY(test_assert_vec4_eq(v2, v6))
  ASSERTIFY(test_assert_vec4_eq(v3, v7))

  TEST_SUCCESS
}

TEST_IMPL(GLM_PREFIX, vec4_fill) {
  vec4 v1, v2, v3;
  vec4 v5 = {-1.456f, -1.456f, -1.456f, -1.456f};
  vec4 v6 = {11.0f, 11.0f, 11.0f, 11.0f};
  vec4 v7 = {78.0f, 78.0f, 78.0f, 78.0f};

  GLM(vec4_fill)(v1, -1.456f);
  GLM(vec4_fill)(v2, 11.0f);
  GLM(vec4_fill)(v3, 78.0f);

  ASSERTIFY(test_assert_vec4_eq(v1, v5))
  ASSERTIFY(test_assert_vec4_eq(v2, v6))
  ASSERTIFY(test_assert_vec4_eq(v3, v7))

  TEST_SUCCESS
}

TEST_IMPL(GLM_PREFIX, vec4_eq) {
  vec4 v1, v2, v3;

  GLM(vec4_fill)(v1, -1.456f);
  GLM(vec4_fill)(v2, 11.0f);
  GLM(vec4_fill)(v3, 78.1f);

  ASSERT(GLM(vec4_eq)(v1, -1.456f))
  ASSERT(GLM(vec4_eq)(v2, 11.0f))
  ASSERT(!GLM(vec4_eq)(v3, 78.0f))

  TEST_SUCCESS
}

TEST_IMPL(GLM_PREFIX, vec4_eq_eps) {
  vec4 v1, v2, v3;

  GLM(vec4_fill)(v1, -1.456f);
  GLM(vec4_fill)(v2, 11.0f);
  GLM(vec4_fill)(v3, 78.1f);

  ASSERT(GLM(vec4_eq_eps)(v1, -1.456f))
  ASSERT(GLM(vec4_eq_eps)(v2, 11.0f))
  ASSERT(!GLM(vec4_eq_eps)(v3, 78.0f))

  TEST_SUCCESS
}

TEST_IMPL(GLM_PREFIX, vec4_eq_all) {
  vec4 v1, v2, v3;
  vec4 v4 = {2.104f, -3.012f, -4.10f, -4.10f};
  vec4 v5 = {-12.35f, -31.140f, -43.502f, -43.502f};

  GLM(vec4_fill)(v1, -1.456f);
  GLM(vec4_fill)(v2, 11.0f);
  GLM(vec4_fill)(v3, 78.0f);

  ASSERT(GLM(vec4_eq_all)(v1))
  ASSERT(GLM(vec4_eq_all)(v2))
  ASSERT(GLM(vec4_eq_all)(v3))
  ASSERT(!GLM(vec4_eq_all)(v4))
  ASSERT(!GLM(vec4_eq_all)(v5))

  TEST_SUCCESS
}

TEST_IMPL(GLM_PREFIX, vec4_eqv) {
  vec4 v1, v2, v3, v4, v5;
  vec4 v6 = {-1.456f, -1.456f, -1.456f, -1.456f};
  vec4 v7 = {11.0f, 11.0f, 11.0f, 11.0f};
  vec4 v8 = {78.0f, 78.0f, -43.502f, -43.502f};

  GLM(vec4_fill)(v1, -1.456f);
  GLM(vec4_fill)(v2, 11.0f);
  GLM(vec4_fill)(v3, 78.0f);

  test_rand_vec4(v4);
  test_rand_vec4(v5);

  ASSERT(GLM(vec4_eqv)(v1, v6))
  ASSERT(GLM(vec4_eqv)(v2, v7))
  ASSERT(!GLM(vec4_eqv)(v3, v8))
  ASSERT(!GLM(vec4_eqv)(v4, v5))
  ASSERT(GLM(vec4_eqv)(v5, v5))

  TEST_SUCCESS
}

TEST_IMPL(GLM_PREFIX, vec4_eqv_eps) {
  vec4 v1, v2, v3, v4, v5;
  vec4 v6 = {-1.456f, -1.456f, -1.456f, -1.456f};
  vec4 v7 = {11.0f, 11.0f, 11.0f, 11.0f};
  vec4 v8 = {78.0f, 78.0f, -43.502f, -43.502f};

  GLM(vec4_fill)(v1, -1.456f);
  GLM(vec4_fill)(v2, 11.0f);
  GLM(vec4_fill)(v3, 78.0f);

  test_rand_vec4(v4);
  test_rand_vec4(v5);

  ASSERT(GLM(vec4_eqv_eps)(v1, v6))
  ASSERT(GLM(vec4_eqv_eps)(v2, v7))
  ASSERT(!GLM(vec4_eqv_eps)(v3, v8))
  ASSERT(!GLM(vec4_eqv_eps)(v4, v5))
  ASSERT(GLM(vec4_eqv_eps)(v5, v5))

  TEST_SUCCESS
}

TEST_IMPL(GLM_PREFIX, vec4_max) {
  vec4 v1 = {2.104f, -3.012f, -4.10f, -4.10f};
  vec4 v2 = {-12.35f, -31.140f, -43.502f, -43.502f};
  vec4 v3 = {INFINITY, 0.0f, 0.0f, 0.0f};
  vec4 v4 = {NAN, INFINITY, 2.0f, 2.0f};
  vec4 v5 = {NAN, -1.0f, -1.0f, -1.0f};
  vec4 v6 = {-1.0f, -11.0f, 11.0f, 11.0f};

  ASSERT(test_eq(GLM(vec4_max)(v1),  2.104f))
  ASSERT(test_eq(GLM(vec4_max)(v2), -12.35f))
  ASSERT(isinf(GLM(vec4_max)(v3)))
  ASSERT(isnan(GLM(vec4_max)(v4)))
  ASSERT(isnan(GLM(vec4_max)(v5)))
  ASSERT(test_eq(GLM(vec4_max)(v6),  11.0f))

  TEST_SUCCESS
}

TEST_IMPL(GLM_PREFIX, vec4_min) {
  vec4 v1 = {2.104f, -3.012f, -4.10f, -4.10f};
  vec4 v2 = {-12.35f, -31.140f, -43.502f, -43.502f};
  vec4 v3 = {INFINITY, 0.0f, 0.0f, 0.0f};
  vec4 v4 = {NAN, INFINITY, 2.0f, 2.0f};
  vec4 v5 = {NAN, -1.0f, -1.0f, -1.0f};
  vec4 v6 = {-1.0f, -11.0f, 11.0f, 11.0f};

  ASSERT(test_eq(GLM(vec4_min)(v1), -4.10f))
  ASSERT(test_eq(GLM(vec4_min)(v2), -43.502f))
  ASSERT(test_eq(GLM(vec4_min)(v3),  0.0f))
  ASSERT(isnan(GLM(vec4_min)(v4)))
  ASSERT(isnan(GLM(vec4_min)(v5)))
  ASSERT(test_eq(GLM(vec4_min)(v6), -11.0f))

  TEST_SUCCESS
}

TEST_IMPL(GLM_PREFIX, vec4_isnan) {
  vec4 v1 = {2.104f, -3.012f, -4.10f, -4.10f};
  vec4 v2 = {-12.35f, -31.140f, -43.502f, -43.502f};
  vec4 v3 = {INFINITY, 0.0f, 0.0f, 0.0f};
  vec4 v4 = {NAN, INFINITY, 2.0f, 2.0f};
  vec4 v5 = {NAN, -1.0f, -1.0f, -1.0f};
  vec4 v6 = {-1.0f, -1.0f, 11.0f, 11.0f};

  ASSERT(!GLM(vec4_isnan)(v1))
  ASSERT(!GLM(vec4_isnan)(v2))
  ASSERT(!GLM(vec4_isnan)(v3))
  ASSERT(GLM(vec4_isnan)(v4))
  ASSERT(GLM(vec4_isnan)(v5))
  ASSERT(!GLM(vec4_isnan)(v6))

  TEST_SUCCESS
}

TEST_IMPL(GLM_PREFIX, vec4_isinf) {
  vec4 v1 = {2.104f, -3.012f, -4.10f, -4.10f};
  vec4 v2 = {-12.35f, -31.140f, -43.502f, -43.502f};
  vec4 v3 = {INFINITY, 0.0f, 0.0f, 0.0f};
  vec4 v4 = {NAN, INFINITY, 2.0f, 2.0f};
  vec4 v5 = {NAN, -1.0f, -1.0f, -1.0f};
  vec4 v6 = {-1.0f, -1.0f, 11.0f, 11.0f};

  ASSERT(!GLM(vec4_isinf)(v1))
  ASSERT(!GLM(vec4_isinf)(v2))
  ASSERT(GLM(vec4_isinf)(v3))
  ASSERT(GLM(vec4_isinf)(v4))
  ASSERT(!GLM(vec4_isinf)(v5))
  ASSERT(!GLM(vec4_isinf)(v6))

  TEST_SUCCESS
}

TEST_IMPL(GLM_PREFIX, vec4_isvalid) {
  vec4 v1 = {2.104f, -3.012f, -4.10f, -4.10f};
  vec4 v2 = {-12.35f, -31.140f, -43.502f, -43.502f};
  vec4 v3 = {INFINITY, 0.0f, 0.0f, 0.0f};
  vec4 v4 = {NAN, INFINITY, 2.0f, 2.0f};
  vec4 v5 = {NAN, -1.0f, -1.0f, -1.0f};
  vec4 v6 = {-1.0f, -1.0f, 11.0f, 11.0f};

  ASSERT(GLM(vec4_isvalid)(v1))
  ASSERT(GLM(vec4_isvalid)(v2))
  ASSERT(!GLM(vec4_isvalid)(v3))
  ASSERT(!GLM(vec4_isvalid)(v4))
  ASSERT(!GLM(vec4_isvalid)(v5))
  ASSERT(GLM(vec4_isvalid)(v6))

  TEST_SUCCESS
}

TEST_IMPL(GLM_PREFIX, vec4_sign) {
  vec4 v1 = {2.104f, -3.012f, -4.10f, -4.10f};
  vec4 v2 = {-12.35f, -31.140f, -43.502f, -43.502f};
  vec4 v3, v4;
  vec4 v5 = {1.0f, -1.0f, -1.0f, -1.0f};
  vec4 v6 = {-1.0f, -1.0f, -1.0f, -1.0f};

  GLM(vec4_sign)(v1, v3);
  GLM(vec4_sign)(v2, v4);

  ASSERTIFY(test_assert_vec4_eq(v3, v5))
  ASSERTIFY(test_assert_vec4_eq(v4, v6))

  TEST_SUCCESS
}

TEST_IMPL(GLM_PREFIX, vec4_abs) {
  vec4 v1 = {2.104f, -3.012f, -4.10f, -4.10f};
  vec4 v2 = {-12.35f, -31.140f, -43.502f, -43.502f};
  vec4 v3, v4;
  vec4 v5 = {2.104f, 3.012f, 4.10f, 4.10f};
  vec4 v6 = {12.35f, 31.140f, 43.502f, 43.502f};

  GLM(vec4_abs)(v1, v3);
  GLM(vec4_abs)(v2, v4);

  ASSERTIFY(test_assert_vec4_eq(v3, v5))
  ASSERTIFY(test_assert_vec4_eq(v4, v6))

  TEST_SUCCESS
}

TEST_IMPL(GLM_PREFIX, vec4_fract) {
  vec4 v1 = {2.104f, 3.012f, 4.10f, 4.10f};
  vec4 v2 = {12.35f, 31.140f, 43.502f, 43.502f};
  vec4 v3, v4;
  vec4 v5 = {0.104f, 0.012f, 0.10f, 0.10f};
  vec4 v6 = {0.35f, 0.140f, 0.502f, 0.502f};

  GLM(vec4_fract)(v1, v3);
  GLM(vec4_fract)(v2, v4);

  ASSERTIFY(test_assert_vec4_eq(v3, v5))
  ASSERTIFY(test_assert_vec4_eq(v4, v6))

  TEST_SUCCESS
}

TEST_IMPL(GLM_PREFIX, vec4_hadd) {
  vec4  v1 = {2.0f, 3.0f, 4.0f, 4.0f}, v2 = {12.0f, 31.0f, 43.0f, 43.0f};
  float r1, r2, r3, r4;
  
  r1 = GLM(vec4_hadd)(v1);
  r2 = GLM(vec4_hadd)(v2);
  
  r3 = v1[0] + v1[1] + v1[2] + v1[3];
  r4 = v2[0] + v2[1] + v2[2] + v2[3];

  ASSERT(test_eq(r1, r3))
  ASSERT(test_eq(r2, r4))

  TEST_SUCCESS
}

TEST_IMPL(GLM_PREFIX, vec4_sqrt) {
  vec4 v1 = {2.0f, 3.0f, 4.0f, 4.0f}, v2 = {12.0f, 31.0f, 43.0f, 43.0f};
  vec4 v3, v4;
  
  GLM(vec4_sqrt)(v1, v3);
  GLM(vec4_sqrt)(v2, v4);

  ASSERT(test_eq(sqrtf(v1[0]), v3[0]))
  ASSERT(test_eq(sqrtf(v1[1]), v3[1]))
  ASSERT(test_eq(sqrtf(v1[2]), v3[2]))
  ASSERT(test_eq(sqrtf(v1[3]), v3[3]))

  ASSERT(test_eq(sqrtf(v2[0]), v4[0]))
  ASSERT(test_eq(sqrtf(v2[1]), v4[1]))
  ASSERT(test_eq(sqrtf(v2[2]), v4[2]))
  ASSERT(test_eq(sqrtf(v2[3]), v4[3]))

  TEST_SUCCESS
}
