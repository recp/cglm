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
  ASSERTIFY(test_assert_vec4_eq(v1, GLM_VEC4_ZERO))
  
  TEST_SUCCESS
}

TEST_IMPL(GLM_PREFIX, vec4_one) {
  vec4 v1 = {10.0f, 9.0f, 8.0f, 78.0f};
  vec4 v2 = {1.0f, 2.0f, 3.0f, 4.0f};
  
  GLM(vec4_one)(v1);
  GLM(vec4_one)(v2);
  
  ASSERTIFY(test_assert_vec3_eq(v1, GLM_VEC4_ONE))
  ASSERTIFY(test_assert_vec3_eq(v1, GLM_VEC4_ONE))
  
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
  vec3  a = {10.0f, 9.0f, 8.0f};
  float n1, n2;
  
  n1 = GLM(vec3_norm)(a);
  n2 = sqrtf(a[0] * a[0] + a[1] * a[1] + a[2] * a[2]);

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
