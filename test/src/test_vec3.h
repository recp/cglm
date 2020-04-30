/*
 * Copyright (c), Recep Aslantas.
 *
 * MIT License (MIT), http://opensource.org/licenses/MIT
 * Full license can be found in the LICENSE file
 */

#include "test_common.h"

#define TEST_GLM_SHUFFLE3(z, y, x) (((z) << 4) | ((y) << 2) | (x))

#ifndef CGLM_TEST_VEC3_ONCE
#define CGLM_TEST_VEC3_ONCE

/* Macros */

TEST_IMPL(MACRO_GLM_VEC3_ONE_INIT) {
  vec3 v = GLM_VEC3_ONE_INIT;
  
  ASSERT(test_eq(v[0], 1.0f))
  ASSERT(test_eq(v[1], 1.0f))
  ASSERT(test_eq(v[2], 1.0f))
  
  TEST_SUCCESS
}

TEST_IMPL(MACRO_GLM_VEC3_ZERO_INIT) {
  vec3 v = GLM_VEC3_ZERO_INIT;
  
  ASSERT(test_eq(v[0], 0.0f))
  ASSERT(test_eq(v[1], 0.0f))
  ASSERT(test_eq(v[2], 0.0f))
  
  TEST_SUCCESS
}

TEST_IMPL(MACRO_GLM_VEC3_ONE) {
  ASSERT(test_eq(GLM_VEC3_ONE[0], 1.0f))
  ASSERT(test_eq(GLM_VEC3_ONE[1], 1.0f))
  ASSERT(test_eq(GLM_VEC3_ONE[2], 1.0f))
  
  TEST_SUCCESS
}

TEST_IMPL(MACRO_GLM_VEC3_ZERO) {
  ASSERT(test_eq(GLM_VEC3_ZERO[0], 0.0f))
  ASSERT(test_eq(GLM_VEC3_ZERO[1], 0.0f))
  ASSERT(test_eq(GLM_VEC3_ZERO[2], 0.0f))
  
  TEST_SUCCESS
}

TEST_IMPL(MACRO_GLM_YUP) {
  ASSERT(test_eq(GLM_YUP[0], 0.0f))
  ASSERT(test_eq(GLM_YUP[1], 1.0f))
  ASSERT(test_eq(GLM_YUP[2], 0.0f))
  
  TEST_SUCCESS
}

TEST_IMPL(MACRO_GLM_ZUP) {
  ASSERT(test_eq(GLM_ZUP[0], 0.0f))
  ASSERT(test_eq(GLM_ZUP[1], 0.0f))
  ASSERT(test_eq(GLM_ZUP[2], 1.0f))
  
  TEST_SUCCESS
}

TEST_IMPL(MACRO_GLM_XUP) {
  ASSERT(test_eq(GLM_XUP[0], 1.0f))
  ASSERT(test_eq(GLM_XUP[1], 0.0f))
  ASSERT(test_eq(GLM_XUP[2], 0.0f))
  
  TEST_SUCCESS
}

TEST_IMPL(MACRO_GLM_FORWARD_RH) {
  ASSERT(test_eq(GLM_FORWARD[0],  0.0f))
  ASSERT(test_eq(GLM_FORWARD[1],  0.0f))
  ASSERT(test_eq(GLM_FORWARD[2], -1.0f))
  
  TEST_SUCCESS
}

TEST_IMPL(MACRO_GLM_SHUFFLE3) {
  ASSERT(TEST_GLM_SHUFFLE3(1, 0, 0) == GLM_SHUFFLE3(1, 0, 0))
  ASSERT(TEST_GLM_SHUFFLE3(0, 1, 0) == GLM_SHUFFLE3(0, 1, 0))
  ASSERT(TEST_GLM_SHUFFLE3(0, 0, 1) == GLM_SHUFFLE3(0, 0, 1))
  ASSERT(TEST_GLM_SHUFFLE3(1, 0, 0) == GLM_SHUFFLE3(1, 0, 0))
  ASSERT(TEST_GLM_SHUFFLE3(1, 0, 1) == GLM_SHUFFLE3(1, 0, 1))

  TEST_SUCCESS
}

TEST_IMPL(MACRO_GLM_XXX) {
  ASSERT(TEST_GLM_SHUFFLE3(0, 0, 0) == GLM_XXX)
  TEST_SUCCESS
}

TEST_IMPL(MACRO_GLM_YYY) {
  ASSERT(TEST_GLM_SHUFFLE3(1, 1, 1) == GLM_YYY)
  TEST_SUCCESS
}

TEST_IMPL(MACRO_GLM_ZZZ) {
  ASSERT(TEST_GLM_SHUFFLE3(2, 2, 2) == GLM_ZZZ)
  TEST_SUCCESS
}

TEST_IMPL(MACRO_GLM_ZYX) {
  ASSERT(TEST_GLM_SHUFFLE3(0, 1, 2) == GLM_ZYX)
  TEST_SUCCESS
}

/* Deprecated */

TEST_IMPL(MACRO_glm_vec3_dup) {
  vec3 v1 = {13.0f, 12.0f, 11.0f}, v2;
  
  glm_vec3_dup(v1, v2);
  
  ASSERTIFY(test_assert_vec3_eq(v1, v2))
  
  TEST_SUCCESS
}

TEST_IMPL(MACRO_glm_vec3_flipsign) {
  vec3 v1 = {13.0f, -12.0f, 11.0f},
       v2 = {13.0f, -12.0f, 11.0f},
       v3 = {-13.0f, 12.0f, -11.0f};
  
  glm_vec3_flipsign(v1);
  glm_vec3_flipsign(v2);

  ASSERTIFY(test_assert_vec3_eq(v1, v3))
  ASSERTIFY(test_assert_vec3_eq(v2, v3))
  
  TEST_SUCCESS
}

TEST_IMPL(MACRO_glm_vec3_flipsign_to) {
  vec3 v1 = {13.0f, -12.0f, 11.0f},
       v2 = {-13.0f, 12.0f, -11.0f},
       v3, v4;
  
  glm_vec3_flipsign_to(v1, v3);
  glm_vec3_flipsign_to(v1, v4);

  ASSERTIFY(test_assert_vec3_eq(v2, v3))
  ASSERTIFY(test_assert_vec3_eq(v2, v4))
  
  TEST_SUCCESS
}

TEST_IMPL(MACRO_glm_vec3_inv) {
  vec3 v1 = {13.0f, -12.0f, 11.0f},
       v2 = {13.0f, -12.0f, 11.0f},
       v3 = {-13.0f, 12.0f, -11.0f};
  
  glm_vec3_inv(v1);
  glm_vec3_inv(v2);

  ASSERTIFY(test_assert_vec3_eq(v1, v3))
  ASSERTIFY(test_assert_vec3_eq(v2, v3))
  
  TEST_SUCCESS
}

TEST_IMPL(MACRO_glm_vec3_inv_to) {
  vec3 v1 = {13.0f, -12.0f, 11.0f},
       v2 = {-13.0f, 12.0f, -11.0f},
       v3, v4;

  glm_vec3_inv_to(v1, v3);
  glm_vec3_inv_to(v1, v4);

  ASSERTIFY(test_assert_vec3_eq(v3, v4))
  ASSERTIFY(test_assert_vec3_eq(v2, v3))
  
  TEST_SUCCESS
}

TEST_IMPL(MACRO_glm_vec3_mulv) {
  vec3 v1 = {2.0f, -3.0f, 4.0f},
       v2 = {-3.0f, 4.0f, -5.0f},
       v3, v4;

  glm_vec3_mulv(v1, v2, v3);
  glm_vec3_mulv(v1, v2, v4);

  ASSERTIFY(test_assert_vec3_eq(v3, v4))

  ASSERT(test_eq(v1[0] * v2[0], v3[0]))
  ASSERT(test_eq(v1[1] * v2[1], v3[1]))
  ASSERT(test_eq(v1[2] * v2[2], v3[2]))
  
  TEST_SUCCESS
}

#endif /* CGLM_TEST_VEC3_ONCE */

/* --- */

TEST_IMPL(GLM_PREFIX, vec3) {
  vec4 v4 = {10.0f, 9.0f, 8.0f, 7.0f};
  vec3 v3;
  
  GLM(vec3)(v4, v3);
  
  ASSERT(test_eq(v3[0], v4[0]))
  ASSERT(test_eq(v3[1], v4[1]))
  ASSERT(test_eq(v3[2], v4[2]))
  
  TEST_SUCCESS
}

TEST_IMPL(GLM_PREFIX, vec3_copy) {
  vec3 v1 = {10.0f, 9.0f, 8.0f};
  vec3 v2 = {1.0f, 2.0f, 3.0f};
  
  GLM(vec3_copy)(v1, v2);
  
  ASSERTIFY(test_assert_vec3_eq(v1, v2))
  
  TEST_SUCCESS
}

TEST_IMPL(GLM_PREFIX, vec3_zero) {
  vec3 v1 = {10.0f, 9.0f, 8.0f};
  vec3 v2 = {1.0f, 2.0f, 3.0f};
  
  GLM(vec3_zero)(v1);
  GLM(vec3_zero)(v2);
  
  ASSERTIFY(test_assert_vec3_eq(v1, GLM_VEC3_ZERO))
  ASSERTIFY(test_assert_vec3_eq(v2, GLM_VEC3_ZERO))
  
  TEST_SUCCESS
}

TEST_IMPL(GLM_PREFIX, vec3_one) {
  vec3 v1 = {10.0f, 9.0f, 8.0f};
  vec3 v2 = {1.0f, 2.0f, 3.0f};
  
  GLM(vec3_one)(v1);
  GLM(vec3_one)(v2);
  
  ASSERTIFY(test_assert_vec3_eq(v1, GLM_VEC3_ONE))
  ASSERTIFY(test_assert_vec3_eq(v1, GLM_VEC3_ONE))
  
  TEST_SUCCESS
}

TEST_IMPL(GLM_PREFIX, vec3_dot) {
  vec3  a = {10.0f, 9.0f, 8.0f};
  vec3  b = {1.0f, 2.0f, 3.0f};
  float dot1, dot2;
  
  dot1 = GLM(vec3_dot)(a, b);
  dot2 = a[0] * b[0] + a[1] * b[1] + a[2] * b[2];
  
  ASSERT(test_eq(dot1, dot2))
  
  TEST_SUCCESS
}


TEST_IMPL(GLM_PREFIX, dot) {
  /* SAME AS VEC3_DOT */

  vec3  a = {10.0f, 9.0f, 8.0f};
  vec3  b = {1.0f, 2.0f, 3.0f};
  float dot1, dot2;

  dot1 = GLM(vec3_dot)(a, b);
  dot2 = a[0] * b[0] + a[1] * b[1] + a[2] * b[2];

  ASSERT(test_eq(dot1, dot2))

  TEST_SUCCESS
}

TEST_IMPL(GLM_PREFIX, vec3_norm2) {
  vec3 a = {10.0f, 9.0f, 8.0f};
  float n1, n2;
  
  n1 = GLM(vec3_norm2)(a);
  n2 = a[0] * a[0] + a[1] * a[1] + a[2] * a[2];

  ASSERT(test_eq(n1, n2))

  TEST_SUCCESS
}

TEST_IMPL(GLM_PREFIX, vec3_norm) {
  vec3  a = {10.0f, 9.0f, 8.0f};
  float n1, n2;
  
  n1 = GLM(vec3_norm)(a);
  n2 = sqrtf(a[0] * a[0] + a[1] * a[1] + a[2] * a[2]);

  ASSERT(test_eq(n1, n2))

  TEST_SUCCESS
}

TEST_IMPL(GLM_PREFIX, vec3_norm_one) {
  vec3  a = {-10.0f, 9.0f, -8.0f};
  float n1, n2;
  
  n1 = GLM(vec3_norm_one)(a);
  n2 = fabsf(a[0]) + fabsf(a[1]) + fabsf(a[2]);

  ASSERT(test_eq(n1, n2))

  TEST_SUCCESS
}

TEST_IMPL(GLM_PREFIX, vec3_norm_inf) {
  vec3  a = {-10.0f, 9.0f, -8.0f};
  float n1, n2;
  
  n1 = GLM(vec3_norm_inf)(a);
  n2 = fabsf(a[0]);
  
  if (n2 < fabsf(a[1]))
    n2 = fabsf(a[1]);
  
  if (n2 < fabsf(a[2]))
    n2 = fabsf(a[2]);
  
  ASSERT(test_eq(n1, n2))

  TEST_SUCCESS
}

TEST_IMPL(GLM_PREFIX, vec3_add) {
  vec3 a = {-10.0f, 9.0f, -8.0f};
  vec3 b = {12.0f, 19.0f, -18.0f};
  vec3 c, d;
  
  c[0] = a[0] + b[0];
  c[1] = a[1] + b[1];
  c[2] = a[2] + b[2];
  
  GLM(vec3_add)(a, b, d);
  
  ASSERTIFY(test_assert_vec3_eq(c, d))

  TEST_SUCCESS
}

TEST_IMPL(GLM_PREFIX, vec3_adds) {
  vec3  a = {-10.0f, 9.0f, -8.0f};
  vec3  c, d;
  float s = 7.0f;
  
  c[0] = a[0] + s;
  c[1] = a[1] + s;
  c[2] = a[2] + s;
  
  GLM(vec3_adds)(a, s, d);
  
  ASSERTIFY(test_assert_vec3_eq(c, d))

  TEST_SUCCESS
}

TEST_IMPL(GLM_PREFIX, vec3_sub) {
  vec3 a = {-10.0f, 9.0f, -8.0f};
  vec3 b = {12.0f, 19.0f, -18.0f};
  vec3 c, d;
  
  c[0] = a[0] - b[0];
  c[1] = a[1] - b[1];
  c[2] = a[2] - b[2];
  
  GLM(vec3_sub)(a, b, d);
  
  ASSERTIFY(test_assert_vec3_eq(c, d))

  TEST_SUCCESS
}

TEST_IMPL(GLM_PREFIX, vec3_subs) {
  vec3  a = {-10.0f, 9.0f, -8.0f};
  vec3  c, d;
  float s = 7.0f;
  
  c[0] = a[0] - s;
  c[1] = a[1] - s;
  c[2] = a[2] - s;
  
  GLM(vec3_subs)(a, s, d);
  
  ASSERTIFY(test_assert_vec3_eq(c, d))

  TEST_SUCCESS
}

TEST_IMPL(GLM_PREFIX, vec3_mul) {
  vec3 v1 = {2.0f, -3.0f, 4.0f},
       v2 = {-3.0f, 4.0f, -5.0f},
       v3;
  
  GLM(vec3_mul)(v1, v2, v3);

  ASSERT(test_eq(v1[0] * v2[0], v3[0]))
  ASSERT(test_eq(v1[1] * v2[1], v3[1]))
  ASSERT(test_eq(v1[2] * v2[2], v3[2]))
  
  TEST_SUCCESS
}

TEST_IMPL(GLM_PREFIX, vec3_scale) {
  vec3  v1 = {2.0f, -3.0f, 4.0f}, v2;
  float s  = 7.0f;
  
  GLM(vec3_scale)(v1, s, v2);

  ASSERT(test_eq(v1[0] * s, v2[0]))
  ASSERT(test_eq(v1[1] * s, v2[1]))
  ASSERT(test_eq(v1[2] * s, v2[2]))
  
  TEST_SUCCESS
}

TEST_IMPL(GLM_PREFIX, vec3_scale_as) {
  vec3  v1 = {2.0f, -3.0f, 4.0f}, v2;
  float s  = 7.0f;
  float norm;

  GLM(vec3_scale_as)(v1, s, v2);

  norm = sqrtf(v1[0] * v1[0] + v1[1] * v1[1] + v1[2] * v1[2]);
  if (norm == 0.0f) {
    ASSERT(test_eq(v1[0], 0.0f))
    ASSERT(test_eq(v1[1], 0.0f))
    ASSERT(test_eq(v1[2], 0.0f))

    TEST_SUCCESS
  }
  
  norm = s / norm;
  
  ASSERT(test_eq(v1[0] * norm, v2[0]))
  ASSERT(test_eq(v1[1] * norm, v2[1]))
  ASSERT(test_eq(v1[2] * norm, v2[2]))

  TEST_SUCCESS
}

TEST_IMPL(GLM_PREFIX, vec3_div) {
  vec3 v1 = {2.0f, -3.0f, 4.0f},
       v2 = {-3.0f, 4.0f, -5.0f},
       v3;
  
  GLM(vec3_div)(v1, v2, v3);

  ASSERT(test_eq(v1[0] / v2[0], v3[0]))
  ASSERT(test_eq(v1[1] / v2[1], v3[1]))
  ASSERT(test_eq(v1[2] / v2[2], v3[2]))
  
  TEST_SUCCESS
}

TEST_IMPL(GLM_PREFIX, vec3_divs) {
  vec3  v1 = {2.0f, -3.0f, 4.0f}, v2;
  float s  = 7.0f;
  
  GLM(vec3_divs)(v1, s, v2);

  ASSERT(test_eq(v1[0] / s, v2[0]))
  ASSERT(test_eq(v1[1] / s, v2[1]))
  ASSERT(test_eq(v1[2] / s, v2[2]))
  
  TEST_SUCCESS
}

TEST_IMPL(GLM_PREFIX, vec3_addadd) {
  vec3 v1 = {2.0f, -3.0f, 4.0f},
       v2 = {-3.0f, 4.0f, -5.0f},
       v3 = {1.0f, 2.0f, 3.0f},
       v4 = {1.0f, 2.0f, 3.0f};
  
  GLM(vec3_addadd)(v1, v2, v4);

  ASSERT(test_eq(v3[0] + v1[0] + v2[0], v4[0]))
  ASSERT(test_eq(v3[1] + v1[1] + v2[1], v4[1]))
  ASSERT(test_eq(v3[2] + v1[2] + v2[2], v4[2]))
  
  TEST_SUCCESS
}

TEST_IMPL(GLM_PREFIX, vec3_subadd) {
  vec3 v1 = {2.0f, -3.0f, 4.0f},
       v2 = {-3.0f, 4.0f, -5.0f},
       v3 = {1.0f, 2.0f, 3.0f},
       v4 = {1.0f, 2.0f, 3.0f};
  
  GLM(vec3_subadd)(v1, v2, v4);

  ASSERT(test_eq(v3[0] + v1[0] - v2[0], v4[0]))
  ASSERT(test_eq(v3[1] + v1[1] - v2[1], v4[1]))
  ASSERT(test_eq(v3[2] + v1[2] - v2[2], v4[2]))
  
  TEST_SUCCESS
}

TEST_IMPL(GLM_PREFIX, vec3_muladd) {
  vec3 v1 = {2.0f, -3.0f, 4.0f},
       v2 = {-3.0f, 4.0f, -5.0f},
       v3 = {1.0f, 2.0f, 3.0f},
       v4 = {1.0f, 2.0f, 3.0f};
  
  GLM(vec3_muladd)(v1, v2, v4);

  ASSERT(test_eq(v3[0] + v1[0] * v2[0], v4[0]))
  ASSERT(test_eq(v3[1] + v1[1] * v2[1], v4[1]))
  ASSERT(test_eq(v3[2] + v1[2] * v2[2], v4[2]))
  
  TEST_SUCCESS
}

TEST_IMPL(GLM_PREFIX, vec3_muladds) {
  vec3 v1 = {2.0f, -3.0f, 4.0f},
       v2 = {1.0f, 2.0f, 3.0f},
       v3 = {1.0f, 2.0f, 3.0f};
  float s = 9.0f;
  
  GLM(vec3_muladds)(v1, s, v3);

  ASSERT(test_eq(v2[0] + v1[0] * s, v3[0]))
  ASSERT(test_eq(v2[1] + v1[1] * s, v3[1]))
  ASSERT(test_eq(v2[2] + v1[2] * s, v3[2]))
  
  TEST_SUCCESS
}

TEST_IMPL(GLM_PREFIX, vec3_maxadd) {
  vec3 v1 = {2.0f, -3.0f, 4.0f},
       v2 = {-3.0f, 4.0f, -5.0f},
       v3 = {1.0f, 2.0f, 3.0f},
       v4 = {1.0f, 2.0f, 3.0f};
  
  GLM(vec3_maxadd)(v1, v2, v4);

  ASSERT(test_eq(v3[0] + glm_max(v1[0], v2[0]), v4[0]))
  ASSERT(test_eq(v3[1] + glm_max(v1[1], v2[1]), v4[1]))
  ASSERT(test_eq(v3[2] + glm_max(v1[2], v2[2]), v4[2]))
  
  TEST_SUCCESS
}

TEST_IMPL(GLM_PREFIX, vec3_minadd) {
  vec3 v1 = {2.0f, -3.0f, 4.0f},
       v2 = {-3.0f, 4.0f, -5.0f},
       v3 = {1.0f, 2.0f, 3.0f},
       v4 = {1.0f, 2.0f, 3.0f};
  
  GLM(vec3_minadd)(v1, v2, v4);

  ASSERT(test_eq(v3[0] + glm_min(v1[0], v2[0]), v4[0]))
  ASSERT(test_eq(v3[1] + glm_min(v1[1], v2[1]), v4[1]))
  ASSERT(test_eq(v3[2] + glm_min(v1[2], v2[2]), v4[2]))
  
  TEST_SUCCESS
}

TEST_IMPL(GLM_PREFIX, vec3_negate_to) {
  vec3 v1 = {2.0f, -3.0f, 4.0f},
       v2 = {-3.0f, 4.0f, -5.0f},
       v3, v4;
  
  GLM(vec3_negate_to)(v1, v3);
  GLM(vec3_negate_to)(v2, v4);

  ASSERT(test_eq(-v1[0], v3[0]))
  ASSERT(test_eq(-v1[1], v3[1]))
  ASSERT(test_eq(-v1[2], v3[2]))
  
  ASSERT(test_eq(-v2[0], v4[0]))
  ASSERT(test_eq(-v2[1], v4[1]))
  ASSERT(test_eq(-v2[2], v4[2]))
  
  TEST_SUCCESS
}

TEST_IMPL(GLM_PREFIX, vec3_negate) {
  vec3 v1 = {2.0f, -3.0f, 4.0f},
       v2 = {-3.0f, 4.0f, -5.0f},
       v3 = {2.0f, -3.0f, 4.0f},
       v4 = {-3.0f, 4.0f, -5.0f};
  
  GLM(vec3_negate)(v1);
  GLM(vec3_negate)(v2);

  ASSERT(test_eq(-v1[0], v3[0]))
  ASSERT(test_eq(-v1[1], v3[1]))
  ASSERT(test_eq(-v1[2], v3[2]))
  
  ASSERT(test_eq(-v2[0], v4[0]))
  ASSERT(test_eq(-v2[1], v4[1]))
  ASSERT(test_eq(-v2[2], v4[2]))
  
  TEST_SUCCESS
}

TEST_IMPL(GLM_PREFIX, vec3_normalize) {
  vec3  v1 = {2.0f, -3.0f, 4.0f}, v2 = {2.0f, -3.0f, 4.0f};
  float s  = 1.0f;
  float norm;

  GLM(vec3_normalize)(v2);

  norm = sqrtf(v1[0] * v1[0] + v1[1] * v1[1] + v1[2] * v1[2]);
  if (norm == 0.0f) {
    ASSERT(test_eq(v1[0], 0.0f))
    ASSERT(test_eq(v1[1], 0.0f))
    ASSERT(test_eq(v1[2], 0.0f))

    TEST_SUCCESS
  }
  
  norm = s / norm;
  
  ASSERT(test_eq(v1[0] * norm, v2[0]))
  ASSERT(test_eq(v1[1] * norm, v2[1]))
  ASSERT(test_eq(v1[2] * norm, v2[2]))

  glm_vec3_zero(v1);
  GLM(vec3_normalize)(v1);
  ASSERTIFY(test_assert_vec3_eq(v1, GLM_VEC3_ZERO))

  TEST_SUCCESS
}

TEST_IMPL(GLM_PREFIX, vec3_normalize_to) {
  vec3 v1 = {2.0f, -3.0f, 4.0f}, v2;
  float s  = 1.0f;
  float norm;

  GLM(vec3_normalize_to)(v1, v2);

  norm = sqrtf(v1[0] * v1[0] + v1[1] * v1[1] + v1[2] * v1[2]);
  if (norm == 0.0f) {
    ASSERT(test_eq(v1[0], 0.0f))
    ASSERT(test_eq(v1[1], 0.0f))
    ASSERT(test_eq(v1[2], 0.0f))

    TEST_SUCCESS
  }
  
  norm = s / norm;
  
  ASSERT(test_eq(v1[0] * norm, v2[0]))
  ASSERT(test_eq(v1[1] * norm, v2[1]))
  ASSERT(test_eq(v1[2] * norm, v2[2]))

  glm_vec3_zero(v1);
  GLM(vec3_normalize_to)(v1, v2);
  ASSERTIFY(test_assert_vec3_eq(v2, GLM_VEC3_ZERO))

  TEST_SUCCESS
}

TEST_IMPL(GLM_PREFIX, normalize) {
  /* SAME AS VEC3_NORMALIZE */

  vec3  v1 = {2.0f, -3.0f, 4.0f}, v2 = {2.0f, -3.0f, 4.0f};
  float s  = 1.0f;
  float norm;

  GLM(vec3_normalize)(v2);

  norm = sqrtf(v1[0] * v1[0] + v1[1] * v1[1] + v1[2] * v1[2]);
  if (norm == 0.0f) {
    ASSERT(test_eq(v1[0], 0.0f))
    ASSERT(test_eq(v1[1], 0.0f))
    ASSERT(test_eq(v1[2], 0.0f))

    TEST_SUCCESS
  }

  norm = s / norm;

  ASSERT(test_eq(v1[0] * norm, v2[0]))
  ASSERT(test_eq(v1[1] * norm, v2[1]))
  ASSERT(test_eq(v1[2] * norm, v2[2]))

  glm_vec3_zero(v1);
  GLM(vec3_normalize)(v1);
  ASSERTIFY(test_assert_vec3_eq(v1, GLM_VEC3_ZERO))

  TEST_SUCCESS
}

TEST_IMPL(GLM_PREFIX, normalize_to) {
  /* SAME AS VEC3_NORMALIZE_TO */

  vec3 v1 = {2.0f, -3.0f, 4.0f}, v2;
  float s  = 1.0f;
  float norm;

  GLM(vec3_normalize_to)(v1, v2);

  norm = sqrtf(v1[0] * v1[0] + v1[1] * v1[1] + v1[2] * v1[2]);
  if (norm == 0.0f) {
    ASSERT(test_eq(v1[0], 0.0f))
    ASSERT(test_eq(v1[1], 0.0f))
    ASSERT(test_eq(v1[2], 0.0f))

    TEST_SUCCESS
  }

  norm = s / norm;

  ASSERT(test_eq(v1[0] * norm, v2[0]))
  ASSERT(test_eq(v1[1] * norm, v2[1]))
  ASSERT(test_eq(v1[2] * norm, v2[2]))

  glm_vec3_zero(v1);
  GLM(vec3_normalize_to)(v1, v2);
  ASSERTIFY(test_assert_vec3_eq(v2, GLM_VEC3_ZERO))

  TEST_SUCCESS
}

TEST_IMPL(GLM_PREFIX, vec3_cross) {
  /* (u2.v3 - u3.v2, u3.v1 - u1.v3, u1.v2 - u2.v1) */
  vec3 v1 = {2.0f, -3.0f, 4.0f}, v2 = {12.0f, -31.0f, 43.0f}, v3, v4;
  
  GLM(vec3_cross)(v1, v2, v3);
  
  v4[0] = v1[1] * v2[2] - v1[2] * v2[1];
  v4[1] = v1[2] * v2[0] - v1[0] * v2[2];
  v4[2] = v1[0] * v2[1] - v1[1] * v2[0];
  
  ASSERTIFY(test_assert_vec3_eq(v3, v4))

  TEST_SUCCESS
}

TEST_IMPL(GLM_PREFIX, vec3_crossn) {
  /* (u2.v3 - u3.v2, u3.v1 - u1.v3, u1.v2 - u2.v1) */
  vec3 v1 = {2.0f, -3.0f, 4.0f}, v2 = {12.0f, -31.0f, 43.0f}, v3, v4;
  
  GLM(vec3_crossn)(v1, v2, v3);
  
  v4[0] = v1[1] * v2[2] - v1[2] * v2[1];
  v4[1] = v1[2] * v2[0] - v1[0] * v2[2];
  v4[2] = v1[0] * v2[1] - v1[1] * v2[0];

  glm_normalize(v4);

  ASSERTIFY(test_assert_vec3_eq(v3, v4))

  TEST_SUCCESS
}

TEST_IMPL(GLM_PREFIX, cross) {
  /* SAME AS VEC3_CROSS */

  /* (u2.v3 - u3.v2, u3.v1 - u1.v3, u1.v2 - u2.v1) */
  vec3 v1 = {2.0f, -3.0f, 4.0f}, v2 = {12.0f, -31.0f, 43.0f}, v3, v4;

  GLM(vec3_cross)(v1, v2, v3);

  v4[0] = v1[1] * v2[2] - v1[2] * v2[1];
  v4[1] = v1[2] * v2[0] - v1[0] * v2[2];
  v4[2] = v1[0] * v2[1] - v1[1] * v2[0];

  ASSERTIFY(test_assert_vec3_eq(v3, v4))

  TEST_SUCCESS
}

TEST_IMPL(GLM_PREFIX, vec3_angle) {
  vec3 v1 = {1.0f, 0.0f, 0.0f},
       v2 = {1.0f, 0.0f, 1.0f},
       v3 = {0.0f, 1.0f, 0.0f};
  float a;

  a = GLM(vec3_angle)(v1, v1);
  ASSERT(!isinf(a))
  ASSERT(!isnan(a))
  ASSERT(test_eq(a, 0.0f))

  a = GLM(vec3_angle)(v1, v2);
  ASSERT(!isinf(a))
  ASSERT(!isnan(a))
  ASSERT(test_eq(a, GLM_PI_4f))

  a = GLM(vec3_angle)(v1, v3);
  ASSERT(!isinf(a))
  ASSERT(!isnan(a))
  ASSERT(test_eq(a, GLM_PI_2f))

  TEST_SUCCESS
}

TEST_IMPL(GLM_PREFIX, vec3_rotate) {
  vec3 v1 = {1.0f, 0.0f, 0.0f}, v2 = {1.0f, 1.0f, 1.0f};

  /* rotate X around Y = -Z */
  GLM(vec3_rotate)(v1, GLM_PI_2f, GLM_YUP);

  ASSERT(test_eq(v1[0],  0.0f))
  ASSERT(test_eq(v1[1],  0.0f))
  ASSERT(test_eq(v1[2], -1.0f))

  /* rotate -Z around X = Y */
  GLM(vec3_rotate)(v1, GLM_PI_2f, GLM_XUP);

  ASSERT(test_eq(v1[0],  0.0f))
  ASSERT(test_eq(v1[1],  1.0f))
  ASSERT(test_eq(v1[2],  0.0f))

  /* rotate Y around Z = -X */
  GLM(vec3_rotate)(v1, GLM_PI_2f, GLM_ZUP);

  ASSERT(test_eq(v1[0], -1.0f))
  ASSERT(test_eq(v1[1],  0.0f))
  ASSERT(test_eq(v1[2],  0.0f))

  /* rotate v2 around Y by 90deg */
  GLM(vec3_rotate)(v2, GLM_PI_2f, GLM_YUP);

  ASSERT(test_eq(v2[0],  1.0f))
  ASSERT(test_eq(v2[1],  1.0f))
  ASSERT(test_eq(v2[2], -1.0f))

  /* rotate v2 around Y by 90deg */
  GLM(vec3_rotate)(v2, GLM_PI_2f, GLM_YUP);

  ASSERT(test_eq(v2[0], -1.0f))
  ASSERT(test_eq(v2[1],  1.0f))
  ASSERT(test_eq(v2[2], -1.0f))

  /* rotate v2 around Y by 90deg */
  GLM(vec3_rotate)(v2, GLM_PI_2f, GLM_YUP);

  ASSERT(test_eq(v2[0], -1.0f))
  ASSERT(test_eq(v2[1],  1.0f))
  ASSERT(test_eq(v2[2],  1.0f))

  /* rotate v2 around X by 90deg */
  GLM(vec3_rotate)(v2, GLM_PI_2f, GLM_XUP);

  ASSERT(test_eq(v2[0], -1.0f))
  ASSERT(test_eq(v2[1], -1.0f))
  ASSERT(test_eq(v2[2],  1.0f))

  /* rotate v2 around Z by 90deg */
  GLM(vec3_rotate)(v2, GLM_PI_2f, GLM_ZUP);

  ASSERT(test_eq(v2[0],  1.0f))
  ASSERT(test_eq(v2[1], -1.0f))
  ASSERT(test_eq(v2[2],  1.0f))

  TEST_SUCCESS
}

TEST_IMPL(GLM_PREFIX, vec3_rotate_m4) {
  vec3 v1 = {1.0f, 0.0f, 0.0f}, v2 = {1.0f, 1.0f, 1.0f};
  mat4 x, y, z;

  glm_rotate_make(x, GLM_PI_2f, GLM_XUP);
  glm_rotate_make(y, GLM_PI_2f, GLM_YUP);
  glm_rotate_make(z, GLM_PI_2f, GLM_ZUP);

  /* rotate X around Y = -Z */
  GLM(vec3_rotate_m4)(y, v1, v1);

  ASSERT(test_eq(v1[0],  0.0f))
  ASSERT(test_eq(v1[1],  0.0f))
  ASSERT(test_eq(v1[2], -1.0f))

  /* rotate -Z around X = Y */
  GLM(vec3_rotate_m4)(x, v1, v1);

  ASSERT(test_eq(v1[0],  0.0f))
  ASSERT(test_eq(v1[1],  1.0f))
  ASSERT(test_eq(v1[2],  0.0f))

  /* rotate Y around X = -X */
  GLM(vec3_rotate_m4)(z, v1, v1);

  ASSERT(test_eq(v1[0], -1.0f))
  ASSERT(test_eq(v1[1],  0.0f))
  ASSERT(test_eq(v1[2],  0.0f))

  /* rotate v2 around Y by 90deg */
  GLM(vec3_rotate_m4)(y, v2, v2);

  ASSERT(test_eq(v2[0],  1.0f))
  ASSERT(test_eq(v2[1],  1.0f))
  ASSERT(test_eq(v2[2], -1.0f))

  /* rotate v2 around Y by 90deg */
  GLM(vec3_rotate_m4)(y, v2, v2);

  ASSERT(test_eq(v2[0], -1.0f))
  ASSERT(test_eq(v2[1],  1.0f))
  ASSERT(test_eq(v2[2], -1.0f))

  /* rotate v2 around Y by 90deg */
  GLM(vec3_rotate_m4)(y, v2, v2);

  ASSERT(test_eq(v2[0], -1.0f))
  ASSERT(test_eq(v2[1],  1.0f))
  ASSERT(test_eq(v2[2],  1.0f))

  /* rotate v2 around X by 90deg */
  GLM(vec3_rotate_m4)(x, v2, v2);

  ASSERT(test_eq(v2[0], -1.0f))
  ASSERT(test_eq(v2[1], -1.0f))
  ASSERT(test_eq(v2[2],  1.0f))

  /* rotate v2 around Z by 90deg */
  GLM(vec3_rotate_m4)(z, v2, v2);

  ASSERT(test_eq(v2[0],  1.0f))
  ASSERT(test_eq(v2[1], -1.0f))
  ASSERT(test_eq(v2[2],  1.0f))

  TEST_SUCCESS
}

TEST_IMPL(GLM_PREFIX, vec3_rotate_m3) {
  vec3 v1 = {1.0f, 0.0f, 0.0f}, v2 = {1.0f, 1.0f, 1.0f};
  mat4 x0, y0, z0;
  mat3 x, y, z;

  glm_rotate_make(x0, GLM_PI_2f, GLM_XUP);
  glm_rotate_make(y0, GLM_PI_2f, GLM_YUP);
  glm_rotate_make(z0, GLM_PI_2f, GLM_ZUP);

  glm_mat4_pick3(x0, x);
  glm_mat4_pick3(y0, y);
  glm_mat4_pick3(z0, z);

  /* rotate X around Y = -Z */
  GLM(vec3_rotate_m3)(y, v1, v1);

  ASSERT(test_eq(v1[0],  0.0f))
  ASSERT(test_eq(v1[1],  0.0f))
  ASSERT(test_eq(v1[2], -1.0f))

  /* rotate -Z around X = Y */
  GLM(vec3_rotate_m3)(x, v1, v1);

  ASSERT(test_eq(v1[0],  0.0f))
  ASSERT(test_eq(v1[1],  1.0f))
  ASSERT(test_eq(v1[2],  0.0f))

  /* rotate Y around Z = -X */
  GLM(vec3_rotate_m3)(z, v1, v1);

  ASSERT(test_eq(v1[0], -1.0f))
  ASSERT(test_eq(v1[1],  0.0f))
  ASSERT(test_eq(v1[2],  0.0f))

  /* rotate v2 around Y by 90deg */
  GLM(vec3_rotate_m3)(y, v2, v2);

  ASSERT(test_eq(v2[0],  1.0f))
  ASSERT(test_eq(v2[1],  1.0f))
  ASSERT(test_eq(v2[2], -1.0f))

  /* rotate v2 around Y by 90deg */
  GLM(vec3_rotate_m3)(y, v2, v2);

  ASSERT(test_eq(v2[0], -1.0f))
  ASSERT(test_eq(v2[1],  1.0f))
  ASSERT(test_eq(v2[2], -1.0f))

  /* rotate v2 around Y by 90deg */
  GLM(vec3_rotate_m3)(y, v2, v2);

  ASSERT(test_eq(v2[0], -1.0f))
  ASSERT(test_eq(v2[1],  1.0f))
  ASSERT(test_eq(v2[2],  1.0f))

  /* rotate v2 around X by 90deg */
  GLM(vec3_rotate_m3)(x, v2, v2);

  ASSERT(test_eq(v2[0], -1.0f))
  ASSERT(test_eq(v2[1], -1.0f))
  ASSERT(test_eq(v2[2],  1.0f))

  /* rotate v2 around Z by 90deg */
  GLM(vec3_rotate_m3)(z, v2, v2);

  ASSERT(test_eq(v2[0],  1.0f))
  ASSERT(test_eq(v2[1], -1.0f))
  ASSERT(test_eq(v2[2],  1.0f))

  TEST_SUCCESS
}

TEST_IMPL(GLM_PREFIX, vec3_proj) {
  vec3 v1 = {3.0f,  4.0f, 0.0f},
       v2 = {10.0f, 0.0f, 0.0f},
       v3 = {0.0f,  10.0f, 0.0f},
       v4 = {3.0f,  0.0f, 0.0f},
       v5 = {0.0f,  4.0f, 0.0f},
       v6;

  GLM(vec3_proj)(v1, v2, v6);
  ASSERTIFY(test_assert_vec3_eq(v4, v6))

  GLM(vec3_proj)(v1, v3, v6);
  ASSERTIFY(test_assert_vec3_eq(v5, v6))

  TEST_SUCCESS
}

TEST_IMPL(GLM_PREFIX, vec3_center) {
  vec3 v1 = {30.0f, 0.0f, 0.0f},
       v2 = {0.0f, 0.0f, 0.0f},
       v3 = {15.0f, 0.0f, 0.0f},
       v4 = {3.0f, 10.0f, 120.0f},
       v5 = {0.46f, 4.0f, 14.0f},
       v6;

  GLM(vec3_center)(v1, v2, v6);
  ASSERTIFY(test_assert_vec3_eq(v3, v6))

  GLM(vec3_center)(v4, v5, v6);
  ASSERT(test_eq((v4[0] + v5[0]) * 0.5f, v6[0]))
  ASSERT(test_eq((v4[1] + v5[1]) * 0.5f, v6[1]))
  ASSERT(test_eq((v4[2] + v5[2]) * 0.5f, v6[2]))

  TEST_SUCCESS
}

TEST_IMPL(GLM_PREFIX, vec3_distance2) {
  vec3 v1 = {30.0f, 0.0f, 0.0f},
       v2 = {0.0f, 0.0f, 0.0f},
       v3 = {3.0f, 10.0f, 120.0f},
       v4 = {0.46f, 4.0f, 14.0f};
  float d;

  d = GLM(vec3_distance2)(v1, v2);
  ASSERT(test_eq(d, 30.0f * 30.0f))

  d = GLM(vec3_distance2)(v3, v4);
  ASSERT(test_eq(powf(v3[0] - v4[0], 2.0f)
               + powf(v3[1] - v4[1], 2.0f)
               + powf(v3[2] - v4[2], 2.0f), d))

  TEST_SUCCESS
}

TEST_IMPL(GLM_PREFIX, vec3_distance) {
  vec3 v1 = {30.0f, 0.0f, 0.0f},
       v2 = {0.0f, 0.0f, 0.0f},
       v3 = {3.0f, 10.0f, 120.0f},
       v4 = {0.46f, 4.0f, 14.0f};
  float d;

  d = GLM(vec3_distance)(v1, v2);
  ASSERT(test_eq(d, 30.0f))

  d = GLM(vec3_distance)(v3, v4);
  ASSERT(test_eq(sqrtf(powf(v3[0] - v4[0], 2.0f)
                     + powf(v3[1] - v4[1], 2.0f)
                     + powf(v3[2] - v4[2], 2.0f)), d))

  TEST_SUCCESS
}

TEST_IMPL(GLM_PREFIX, vec3_maxv) {
  vec3 v1, v2, v3;
  vec3 v5 = {-1.456f, -1.456f, 241.456f};
  vec3 v6 = {11.0f, 11.0f, 11.0f};
  vec3 v7 = {78.0f, -78.0f, 7.0f};

  GLM(vec3_maxv)(v5, v6, v1);
  GLM(vec3_maxv)(v5, v7, v2);
  GLM(vec3_maxv)(v6, v7, v3);

  ASSERT(test_eq(v1[0], 11.0f))
  ASSERT(test_eq(v1[1], 11.0f))
  ASSERT(test_eq(v1[2], 241.456f))

  ASSERT(test_eq(v2[0], 78.0f))
  ASSERT(test_eq(v2[1], -1.456f))
  ASSERT(test_eq(v2[2], 241.456f))

  ASSERT(test_eq(v3[0], 78.0f))
  ASSERT(test_eq(v3[1], 11.0f))
  ASSERT(test_eq(v3[2], 11.0f))

  TEST_SUCCESS
}

TEST_IMPL(GLM_PREFIX, vec3_minv) {
  vec3 v1, v2, v3;
  vec3 v5 = {-1.456f, -1.456f, 241.456f};
  vec3 v6 = {11.0f, 11.0f, 11.0f};
  vec3 v7 = {78.0f, -78.0f, 7.0f};

  GLM(vec3_minv)(v5, v6, v1);
  GLM(vec3_minv)(v5, v7, v2);
  GLM(vec3_minv)(v6, v7, v3);

  ASSERT(test_eq(v1[0], -1.456f))
  ASSERT(test_eq(v1[1], -1.456f))
  ASSERT(test_eq(v1[2], 11.0f))

  ASSERT(test_eq(v2[0], -1.456f))
  ASSERT(test_eq(v2[1], -78.0f))
  ASSERT(test_eq(v2[2], 7.0f))

  ASSERT(test_eq(v3[0], 11.0f))
  ASSERT(test_eq(v3[1], -78.0f))
  ASSERT(test_eq(v3[2], 7.0f))

  TEST_SUCCESS
}

TEST_IMPL(GLM_PREFIX, vec3_ortho) {
  vec3  v1, v2, v3;
  vec3  v5, v6, v7;
  float a;

  test_rand_vec3(v1);
  test_rand_vec3(v2);
  test_rand_vec3(v3);

  GLM(vec3_ortho)(v1, v5);
  GLM(vec3_ortho)(v2, v6);
  GLM(vec3_ortho)(v3, v7);
  
  a = glm_vec3_angle(v1, v5);
  ASSERT(!isinf(a))
  ASSERT(!isnan(a))
  ASSERT(test_eq(a, GLM_PI_2f))
  
  a = glm_vec3_angle(v2, v6);
  ASSERT(!isinf(a))
  ASSERT(!isnan(a))
  ASSERT(test_eq(a, GLM_PI_2f))
  
  a = glm_vec3_angle(v3, v7);
  ASSERT(!isinf(a))
  ASSERT(!isnan(a))
  ASSERT(test_eq(a, GLM_PI_2f))

  TEST_SUCCESS
}

TEST_IMPL(GLM_PREFIX, vec3_clamp) {
  vec3 v1 = {-1.456f, -11.456f, 31.456f};
  vec3 v2 = {0.110f, 111.0f, 11.0f};
  vec3 v3 = {78.0f, 32.0f, -78.0f};

  GLM(vec3_clamp)(v1, -1.03f, 30.0f);
  GLM(vec3_clamp)(v2,  0.11f, 111.0f);
  GLM(vec3_clamp)(v3, -88.0f, 70.0f);

  ASSERT(test_eq(v1[0], -1.03f))
  ASSERT(test_eq(v1[1], -1.03f))
  ASSERT(test_eq(v1[2],  30.0f))
  
  ASSERT(test_eq(v2[0],  0.11f))
  ASSERT(test_eq(v2[1],  111.0f))
  ASSERT(test_eq(v2[2],  11.0f))
  
  ASSERT(test_eq(v3[0],  70.0f))
  ASSERT(test_eq(v3[1],  32.0f))
  ASSERT(test_eq(v3[2], -78.0f))

  TEST_SUCCESS
}

TEST_IMPL(GLM_PREFIX, vec3_lerp) {
  vec3 v1 = {-100.0f, -200.0f, -10.0f};
  vec3 v2 = {100.0f, 200.0f, 10.0f};
  vec3 v3;

  GLM(vec3_lerp)(v1, v2, 0.5f, v3);
  ASSERT(test_eq(v3[0], 0.0f))
  ASSERT(test_eq(v3[1], 0.0f))
  ASSERT(test_eq(v3[2], 0.0f))
  
  GLM(vec3_lerp)(v1, v2, 0.75f, v3);
  ASSERT(test_eq(v3[0], 50.0f))
  ASSERT(test_eq(v3[1], 100.0f))
  ASSERT(test_eq(v3[2], 5.0f))

  TEST_SUCCESS
}

TEST_IMPL(GLM_PREFIX, vec3_lerpc) {
  vec3 v1 = {-100.0f, -200.0f, -10.0f};
  vec3 v2 = {100.0f, 200.0f, 10.0f};
  vec3 v3;

  GLM(vec3_lerpc)(v1, v2, 0.5f, v3);
  ASSERT(test_eq(v3[0], 0.0f))
  ASSERT(test_eq(v3[1], 0.0f))
  ASSERT(test_eq(v3[2], 0.0f))
  
  GLM(vec3_lerpc)(v1, v2, 0.75f, v3);
  ASSERT(test_eq(v3[0], 50.0f))
  ASSERT(test_eq(v3[1], 100.0f))
  ASSERT(test_eq(v3[2], 5.0f))
  
  GLM(vec3_lerpc)(v1, v2, -1.75f, v3);
  ASSERT(test_eq(v3[0], -100.0f))
  ASSERT(test_eq(v3[1], -200.0f))
  ASSERT(test_eq(v3[2], -10.0f))
  
  GLM(vec3_lerpc)(v1, v2, 1.75f, v3);
  ASSERT(test_eq(v3[0], 100.0f))
  ASSERT(test_eq(v3[1], 200.0f))
  ASSERT(test_eq(v3[2], 10.0f))

  TEST_SUCCESS
}

TEST_IMPL(GLM_PREFIX, vec3_mix) {
  vec3 v1 = {-100.0f, -200.0f, -10.0f};
  vec3 v2 = {100.0f, 200.0f, 10.0f};
  vec3 v3;

  GLM(vec3_mix)(v1, v2, 0.5f, v3);
  ASSERT(test_eq(v3[0], 0.0f))
  ASSERT(test_eq(v3[1], 0.0f))
  ASSERT(test_eq(v3[2], 0.0f))
  
  GLM(vec3_mix)(v1, v2, 0.75f, v3);
  ASSERT(test_eq(v3[0], 50.0f))
  ASSERT(test_eq(v3[1], 100.0f))
  ASSERT(test_eq(v3[2], 5.0f))

  TEST_SUCCESS
}

TEST_IMPL(GLM_PREFIX, vec3_mixc) {
  vec3 v1 = {-100.0f, -200.0f, -10.0f};
  vec3 v2 = {100.0f, 200.0f, 10.0f};
  vec3 v3;

  GLM(vec3_mixc)(v1, v2, 0.5f, v3);
  ASSERT(test_eq(v3[0], 0.0f))
  ASSERT(test_eq(v3[1], 0.0f))
  ASSERT(test_eq(v3[2], 0.0f))
  
  GLM(vec3_mixc)(v1, v2, 0.75f, v3);
  ASSERT(test_eq(v3[0], 50.0f))
  ASSERT(test_eq(v3[1], 100.0f))
  ASSERT(test_eq(v3[2], 5.0f))
  
  GLM(vec3_mixc)(v1, v2, -1.75f, v3);
  ASSERT(test_eq(v3[0], -100.0f))
  ASSERT(test_eq(v3[1], -200.0f))
  ASSERT(test_eq(v3[2], -10.0f))
  
  GLM(vec3_mixc)(v1, v2, 1.75f, v3);
  ASSERT(test_eq(v3[0], 100.0f))
  ASSERT(test_eq(v3[1], 200.0f))
  ASSERT(test_eq(v3[2], 10.0f))

  TEST_SUCCESS
}

TEST_IMPL(GLM_PREFIX, vec3_step_uni) {
  vec3 v1 = {-100.0f, -200.0f, -10.0f};
  vec3 v2;

  GLM(vec3_step_uni)(-2.5f, v1, v2);
  ASSERT(test_eq(v2[0], 0.0f))
  ASSERT(test_eq(v2[1], 0.0f))
  ASSERT(test_eq(v2[2], 0.0f))
  
  GLM(vec3_step_uni)(-10.0f, v1, v2);
  ASSERT(test_eq(v2[0], 0.0f))
  ASSERT(test_eq(v2[1], 0.0f))
  ASSERT(test_eq(v2[2], 1.0f))
  
  GLM(vec3_step_uni)(-1000.0f, v1, v2);
  ASSERT(test_eq(v2[0], 1.0f))
  ASSERT(test_eq(v2[1], 1.0f))
  ASSERT(test_eq(v2[2], 1.0f))

  TEST_SUCCESS
}

TEST_IMPL(GLM_PREFIX, vec3_step) {
  vec3 v1 = {-100.0f, -200.0f, -10.0f};
  vec3 s1 = {-100.0f, 0.0f,  10.0f};
  vec3 s2 = {100.0f, -220.0f, -10.0f};
  vec3 s3 = {100.0f, 200.0f, 10.0f};
  vec3 v2;

  GLM(vec3_step)(s1, v1, v2);
  ASSERT(test_eq(v2[0], 1.0f))
  ASSERT(test_eq(v2[1], 0.0f))
  ASSERT(test_eq(v2[2], 0.0f))
  
  GLM(vec3_step)(s2, v1, v2);
  ASSERT(test_eq(v2[0], 0.0f))
  ASSERT(test_eq(v2[1], 1.0f))
  ASSERT(test_eq(v2[2], 1.0f))
  
  GLM(vec3_step)(s3, v1, v2);
  ASSERT(test_eq(v2[0], 0.0f))
  ASSERT(test_eq(v2[1], 0.0f))
  ASSERT(test_eq(v2[2], 0.0f))

  TEST_SUCCESS
}

TEST_IMPL(GLM_PREFIX, vec3_smoothstep_uni) {
  vec3 v1 = {-100.0f, -200.0f, -10.0f};
  vec3 v2;

  GLM(vec3_smoothstep_uni)(-200.0f, -100.0f, v1, v2);
  ASSERT(test_eq_th(v2[0], 1.0f, 1e-5f))
  ASSERT(test_eq_th(v2[1], 0.0f, 1e-5f))
  ASSERT(test_eq_th(v2[2], 1.0f, 1e-5f))
  
  GLM(vec3_smoothstep_uni)(-250.0f, -200.0f, v1, v2);
  ASSERT(test_eq_th(v2[0], 1.0f, 1e-5f))
  ASSERT(test_eq_th(v2[1], 1.0f, 1e-5f))
  ASSERT(test_eq_th(v2[2], 1.0f, 1e-5f))
  
  GLM(vec3_smoothstep_uni)(-200.0f, 200, v1, v2);
  ASSERT(v2[0] > 0.0f && v2[0] < 0.25f)
  ASSERT(test_eq(v2[1], 0.0f))
  ASSERT(v2[2] > 0.0f && v2[2] < 0.5f)

  TEST_SUCCESS
}

TEST_IMPL(GLM_PREFIX, vec3_smoothstep) {
  vec3 v1   = {-100.0f, -200.0f, -10.0f};
  vec3 e1_0 = {-100.0f, 0.0f, -11.0f};
  vec3 e1_1 = {50.0f, 10.0f, 20.0f};
  vec3 e2_0 = {-180.0f, -300.0f, -93.0f};
  vec3 e2_1 = {100.0f, 120.0f, -10.0f};
  vec3 e3_0 = {-12.0f, 100.0f, 0.0f};
  vec3 e3_1 = {100.0f, 200.0f, 10.0f};
  vec3 v2;

  GLM(vec3_smoothstep)(e1_0, e1_1, v1, v2);
  ASSERT(test_eq_th(v2[0], 0.0f, 1e-5f))
  ASSERT(test_eq_th(v2[1], 0.0f, 1e-5f))
  ASSERT(v2[2] > 0.0f && v2[2] < 0.1f)
  
  GLM(vec3_smoothstep)(e2_0, e2_1, v1, v2);
  ASSERT(v2[0] > 0.0f && v2[0] < 0.25f)
  ASSERT(v2[1] > 0.0f && v2[1] < 0.15f)
  ASSERT(test_eq_th(v2[2], 1.0f, 1e-5f))
  
  GLM(vec3_smoothstep)(e3_0, e3_1, v1, v2);
  ASSERT(test_eq_th(v2[0], 0.0f, 1e-5f))
  ASSERT(test_eq_th(v2[1], 0.0f, 1e-5f))
  ASSERT(test_eq_th(v2[2], 0.0f, 1e-5f))

  TEST_SUCCESS
}

TEST_IMPL(GLM_PREFIX, vec3_smoothinterp) {
  vec3 e1_0 = {-100.0f, 0.0f,  -11.0f};
  vec3 e1_1 = {50.0f, 10.0f,  20.0f};
  vec3 e2_0 = {80.0f, -220.0f, -19.0f};
  vec3 e2_1 = {100.0f, -200.0f, -10.0f};
  vec3 e3_0 = {-12.0f, 100.0f, 0.0f};
  vec3 e3_1 = {100.0f, 200.0f, 10.0f};
  vec3 v2;

  GLM(vec3_smoothinterp)(e1_0, e1_1, 0.5f, v2);
  ASSERT(v2[0] >= e1_0[0] && v2[0] <= e1_1[0])
  ASSERT(v2[1] >= e1_0[1] && v2[1] <= e1_1[1])
  ASSERT(v2[2] >= e1_0[2] && v2[2] <= e1_1[2])
  
  GLM(vec3_smoothinterp)(e2_0, e2_1, 0.5, v2);
  ASSERT(v2[0] >= e2_0[0] && v2[0] <= e2_1[0])
  ASSERT(v2[1] >= e2_0[1] && v2[1] <= e2_1[1])
  ASSERT(v2[2] >= e2_0[2] && v2[2] <= e2_1[2])
  
  GLM(vec3_smoothinterp)(e3_0, e3_1, 1.0, v2);
  ASSERT(v2[0] >= e3_0[0] && v2[0] <= e3_1[0])
  ASSERT(v2[1] >= e3_0[1] && v2[1] <= e3_1[1])
  ASSERT(v2[2] >= e3_0[2] && v2[2] <= e3_1[2])

  TEST_SUCCESS
}

TEST_IMPL(GLM_PREFIX, vec3_smoothinterpc) {
  vec3 e1_0 = {-100.0f, 0.0f,  -11.0f};
  vec3 e1_1 = {50.0f, 10.0f,  20.0f};
  vec3 e2_0 = {80.0f, -220.0f, -19.0f};
  vec3 e2_1 = {100.0f, -200.0f, -10.0f};
  vec3 e3_0 = {-12.0f, 100.0f, 0.0f};
  vec3 e3_1 = {100.0f, 200.0f, 10.0f};
  vec3 v2;

  GLM(vec3_smoothinterpc)(e1_0, e1_1, -0.5f, v2);
  ASSERT(v2[0] >= e1_0[0] && v2[0] <= e1_1[0])
  ASSERT(v2[1] >= e1_0[1] && v2[1] <= e1_1[1])
  ASSERT(v2[2] >= e1_0[2] && v2[2] <= e1_1[2])

  GLM(vec3_smoothinterpc)(e2_0, e2_1, 0.5f, v2);
  ASSERT(v2[0] >= e2_0[0] && v2[0] <= e2_1[0])
  ASSERT(v2[1] >= e2_0[1] && v2[1] <= e2_1[1])
  ASSERT(v2[2] >= e2_0[2] && v2[2] <= e2_1[2])

  GLM(vec3_smoothinterpc)(e3_0, e3_1, 2.0f, v2);
  ASSERT(v2[0] >= e3_0[0] && v2[0] <= e3_1[0])
  ASSERT(v2[1] >= e3_0[1] && v2[1] <= e3_1[1])
  ASSERT(v2[2] >= e3_0[2] && v2[2] <= e3_1[2])

  TEST_SUCCESS
}

TEST_IMPL(GLM_PREFIX, vec3_swizzle) {
  vec3 v;

  /* ZYX */
  v[0] = 1;
  v[1] = 2;
  v[2] = 3;

  glm_vec3_swizzle(v, GLM_ZYX, v);
  ASSERTIFY(test_assert_vec3_eq(v, (vec3){3, 2, 1}))

  glm_vec3_swizzle(v, GLM_XXX, v);
  ASSERTIFY(test_assert_vec3_eq(v, (vec3){3, 3, 3}))

  v[0] = 1;
  v[1] = 2;
  v[2] = 3;

  glm_vec3_swizzle(v, GLM_YYY, v);
  ASSERTIFY(test_assert_vec3_eq(v, (vec3){2, 2, 2}))

  v[0] = 1;
  v[1] = 2;
  v[2] = 3;

  glm_vec3_swizzle(v, GLM_ZZZ, v);
  ASSERTIFY(test_assert_vec3_eq(v, (vec3){3, 3, 3}))

  TEST_SUCCESS
}

TEST_IMPL(GLM_PREFIX, vec3_broadcast) {
  vec3 v1, v2, v3;
  vec3 v5 = {-1.456f, -1.456f, -1.456f};
  vec3 v6 = {11.0f, 11.0f, 11.0f};
  vec3 v7 = {78.0f, 78.0f, 78.0f};

  GLM(vec3_broadcast)(-1.456f, v1);
  GLM(vec3_broadcast)(11.0f,   v2);
  GLM(vec3_broadcast)(78.0f,   v3);

  ASSERTIFY(test_assert_vec3_eq(v1, v5))
  ASSERTIFY(test_assert_vec3_eq(v2, v6))
  ASSERTIFY(test_assert_vec3_eq(v3, v7))

  TEST_SUCCESS
}

TEST_IMPL(GLM_PREFIX, vec3_fill) {
  vec3 v1, v2, v3;
  vec3 v5 = {-1.456f, -1.456f, -1.456f};
  vec3 v6 = {11.0f, 11.0f, 11.0f};
  vec3 v7 = {78.0f, 78.0f, 78.0f};

  GLM(vec3_fill)(v1, -1.456f);
  GLM(vec3_fill)(v2, 11.0f);
  GLM(vec3_fill)(v3, 78.0f);

  ASSERTIFY(test_assert_vec3_eq(v1, v5))
  ASSERTIFY(test_assert_vec3_eq(v2, v6))
  ASSERTIFY(test_assert_vec3_eq(v3, v7))

  TEST_SUCCESS
}

TEST_IMPL(GLM_PREFIX, vec3_eq) {
  vec3 v1, v2, v3;

  GLM(vec3_fill)(v1, -1.456f);
  GLM(vec3_fill)(v2, 11.0f);
  GLM(vec3_fill)(v3, 78.1f);

  ASSERT(GLM(vec3_eq)(v1, -1.456f))
  ASSERT(GLM(vec3_eq)(v2, 11.0f))
  ASSERT(!GLM(vec3_eq)(v3, 78.0f))

  TEST_SUCCESS
}

TEST_IMPL(GLM_PREFIX, vec3_eq_eps) {
  vec3 v1, v2, v3;

  GLM(vec3_fill)(v1, -1.456f);
  GLM(vec3_fill)(v2, 11.0f);
  GLM(vec3_fill)(v3, 78.1f);

  ASSERT(GLM(vec3_eq_eps)(v1, -1.456f))
  ASSERT(GLM(vec3_eq_eps)(v2, 11.0f))
  ASSERT(!GLM(vec3_eq_eps)(v3, 78.0f))

  TEST_SUCCESS
}

TEST_IMPL(GLM_PREFIX, vec3_eq_all) {
  vec3 v1, v2, v3;
  vec3 v4 = {2.104f, -3.012f, -4.10f};
  vec3 v5 = {-12.35f, -31.140f, -43.502f};

  GLM(vec3_fill)(v1, -1.456f);
  GLM(vec3_fill)(v2, 11.0f);
  GLM(vec3_fill)(v3, 78.0f);

  ASSERT(GLM(vec3_eq_all)(v1))
  ASSERT(GLM(vec3_eq_all)(v2))
  ASSERT(GLM(vec3_eq_all)(v3))
  ASSERT(!GLM(vec3_eq_all)(v4))
  ASSERT(!GLM(vec3_eq_all)(v5))

  TEST_SUCCESS
}

TEST_IMPL(GLM_PREFIX, vec3_eqv) {
  vec3 v1, v2, v3, v4, v5;
  vec3 v6 = {-1.456f, -1.456f, -1.456f};
  vec3 v7 = {11.0f, 11.0f, 11.0f};
  vec3 v8 = {78.0f, 78.0f, -43.502f};

  GLM(vec3_fill)(v1, -1.456f);
  GLM(vec3_fill)(v2, 11.0f);
  GLM(vec3_fill)(v3, 78.0f);

  test_rand_vec3(v4);
  test_rand_vec3(v5);

  ASSERT(GLM(vec3_eqv)(v1, v6))
  ASSERT(GLM(vec3_eqv)(v2, v7))
  ASSERT(!GLM(vec3_eqv)(v3, v8))
  ASSERT(!GLM(vec3_eqv)(v4, v5))
  ASSERT(GLM(vec3_eqv)(v5, v5))

  TEST_SUCCESS
}

TEST_IMPL(GLM_PREFIX, vec3_eqv_eps) {
  vec3 v1, v2, v3, v4, v5;
  vec3 v6 = {-1.456f, -1.456f, -1.456f};
  vec3 v7 = {11.0f, 11.0f, 11.0f};
  vec3 v8 = {78.0f, 78.0f, -43.502f};

  GLM(vec3_fill)(v1, -1.456f);
  GLM(vec3_fill)(v2, 11.0f);
  GLM(vec3_fill)(v3, 78.0f);

  test_rand_vec3(v4);
  test_rand_vec3(v5);

  ASSERT(GLM(vec3_eqv_eps)(v1, v6))
  ASSERT(GLM(vec3_eqv_eps)(v2, v7))
  ASSERT(!GLM(vec3_eqv_eps)(v3, v8))
  ASSERT(!GLM(vec3_eqv_eps)(v4, v5))
  ASSERT(GLM(vec3_eqv_eps)(v5, v5))

  TEST_SUCCESS
}

TEST_IMPL(GLM_PREFIX, vec3_max) {
  vec3 v1 = {2.104f, -3.012f, -4.10f}, v2 = {-12.35f, -31.140f, -43.502f};
  vec3 v3 = {INFINITY, 0.0f, 0.0f}, v4 = {NAN, INFINITY, 2.0f};
  vec3 v5 = {NAN, -1.0f, -1.0f}, v6 = {-1.0f, -11.0f, 11.0f};

  ASSERT(test_eq(GLM(vec3_max)(v1),  2.104f))
  ASSERT(test_eq(GLM(vec3_max)(v2), -12.35f))
  ASSERT(isinf(GLM(vec3_max)(v3)))
  ASSERT(isnan(GLM(vec3_max)(v4)))
  ASSERT(isnan(GLM(vec3_max)(v5)))
  ASSERT(test_eq(GLM(vec3_max)(v6),  11.0f))

  TEST_SUCCESS
}

TEST_IMPL(GLM_PREFIX, vec3_min) {
  vec3  v1 = {2.104f, -3.012f, -4.10f}, v2 = {-12.35f, -31.140f, -43.502f};
  vec3  v3 = {INFINITY, 0.0f, 0.0f}, v4 = {NAN, INFINITY, 2.0f};
  vec3  v5 = {NAN, -1.0f, -1.0f}, v6 = {-1.0f, -11.0f, 11.0f};

  ASSERT(test_eq(GLM(vec3_min)(v1), -4.10f))
  ASSERT(test_eq(GLM(vec3_min)(v2), -43.502f))
  ASSERT(test_eq(GLM(vec3_min)(v3),  0.0f))
  ASSERT(isnan(GLM(vec3_min)(v4)))
  ASSERT(isnan(GLM(vec3_min)(v5)))
  ASSERT(test_eq(GLM(vec3_min)(v6), -11.0f))

  TEST_SUCCESS
}

TEST_IMPL(GLM_PREFIX, vec3_isnan) {
  vec3  v1 = {2.104f, -3.012f, -4.10f}, v2 = {-12.35f, -31.140f, -43.502f};
  vec3  v3 = {INFINITY, 0.0f, 0.0f}, v4 = {NAN, INFINITY, 2.0f};
  vec3  v5 = {NAN, -1.0f, -1.0f}, v6 = {-1.0f, -1.0f, 11.0f};

  ASSERT(!GLM(vec3_isnan)(v1))
  ASSERT(!GLM(vec3_isnan)(v2))
  ASSERT(!GLM(vec3_isnan)(v3))
  ASSERT(GLM(vec3_isnan)(v4))
  ASSERT(GLM(vec3_isnan)(v5))
  ASSERT(!GLM(vec3_isnan)(v6))

  TEST_SUCCESS
}

TEST_IMPL(GLM_PREFIX, vec3_isinf) {
  vec3  v1 = {2.104f, -3.012f, -4.10f}, v2 = {-12.35f, -31.140f, -43.502f};
  vec3  v3 = {INFINITY, 0.0f, 0.0f}, v4 = {NAN, INFINITY, 2.0f};
  vec3  v5 = {NAN, -1.0f, -1.0f}, v6 = {-1.0f, -1.0f, 11.0f};

  ASSERT(!GLM(vec3_isinf)(v1))
  ASSERT(!GLM(vec3_isinf)(v2))
  ASSERT(GLM(vec3_isinf)(v3))
  ASSERT(GLM(vec3_isinf)(v4))
  ASSERT(!GLM(vec3_isinf)(v5))
  ASSERT(!GLM(vec3_isinf)(v6))

  TEST_SUCCESS
}

TEST_IMPL(GLM_PREFIX, vec3_isvalid) {
  vec3  v1 = {2.104f, -3.012f, -4.10f}, v2 = {-12.35f, -31.140f, -43.502f};
  vec3  v3 = {INFINITY, 0.0f, 0.0f}, v4 = {NAN, INFINITY, 2.0f};
  vec3  v5 = {NAN, -1.0f, -1.0f}, v6 = {-1.0f, -1.0f, 11.0f};

  ASSERT(GLM(vec3_isvalid)(v1))
  ASSERT(GLM(vec3_isvalid)(v2))
  ASSERT(!GLM(vec3_isvalid)(v3))
  ASSERT(!GLM(vec3_isvalid)(v4))
  ASSERT(!GLM(vec3_isvalid)(v5))
  ASSERT(GLM(vec3_isvalid)(v6))

  TEST_SUCCESS
}

TEST_IMPL(GLM_PREFIX, vec3_sign) {
  vec3  v1 = {2.104f, -3.012f, -4.10f}, v2 = {-12.35f, -31.140f, -43.502f};
  vec3  v3, v4;
  vec3  v5 = {1.0f, -1.0f, -1.0f}, v6 = {-1.0f, -1.0f, -1.0f};

  GLM(vec3_sign)(v1, v3);
  GLM(vec3_sign)(v2, v4);

  ASSERTIFY(test_assert_vec3_eq(v3, v5))
  ASSERTIFY(test_assert_vec3_eq(v4, v6))

  TEST_SUCCESS
}

TEST_IMPL(GLM_PREFIX, vec3_abs) {
  vec3  v1 = {2.104f, -3.012f, -4.10f}, v2 = {-12.35f, -31.140f, -43.502f};
  vec3  v3, v4;
  vec3  v5 = {2.104f, 3.012f, 4.10f}, v6 = {12.35f, 31.140f, 43.502f};

  GLM(vec3_abs)(v1, v3);
  GLM(vec3_abs)(v2, v4);

  ASSERTIFY(test_assert_vec3_eq(v3, v5))
  ASSERTIFY(test_assert_vec3_eq(v4, v6))

  TEST_SUCCESS
}

TEST_IMPL(GLM_PREFIX, vec3_fract) {
  vec3  v1 = {2.104f, 3.012f, 4.10f}, v2 = {12.35f, 31.140f, 43.502f}, v3, v4;
  vec3  v5 = {0.104f, 0.012f, 0.10f}, v6 = {0.35f, 0.140f, 0.502f};

  GLM(vec3_fract)(v1, v3);
  GLM(vec3_fract)(v2, v4);

  ASSERTIFY(test_assert_vec3_eq(v3, v5))
  ASSERTIFY(test_assert_vec3_eq(v4, v6))

  TEST_SUCCESS
}

TEST_IMPL(GLM_PREFIX, vec3_hadd) {
  vec3  v1 = {2.0f, 3.0f, 4.0f}, v2 = {12.0f, 31.0f, 43.0f};
  float r1, r2, r3, r4;
  
  r1 = GLM(vec3_hadd)(v1);
  r2 = GLM(vec3_hadd)(v2);
  
  r3 = v1[0] + v1[1] + v1[2];
  r4 = v2[0] + v2[1] + v2[2];

  ASSERT(test_eq(r1, r3))
  ASSERT(test_eq(r2, r4))

  TEST_SUCCESS
}

TEST_IMPL(GLM_PREFIX, vec3_sqrt) {
  vec3  v1 = {2.0f, 3.0f, 4.0f}, v2 = {12.0f, 31.0f, 43.0f}, v3, v4;
  
  GLM(vec3_sqrt)(v1, v3);
  GLM(vec3_sqrt)(v2, v4);

  ASSERT(test_eq(sqrtf(v1[0]), v3[0]))
  ASSERT(test_eq(sqrtf(v1[1]), v3[1]))
  ASSERT(test_eq(sqrtf(v1[2]), v3[2]))

  ASSERT(test_eq(sqrtf(v2[0]), v4[0]))
  ASSERT(test_eq(sqrtf(v2[1]), v4[1]))
  ASSERT(test_eq(sqrtf(v2[2]), v4[2]))

  TEST_SUCCESS
}
