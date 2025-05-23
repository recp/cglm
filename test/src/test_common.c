/*
 * Copyright (c), Recep Aslantas.
 * MIT License (MIT), http://opensource.org/licenses/MIT
 */

#include "test_common.h"
#include <time.h>

void
test_rand_mat4(mat4 dest) {
  glm_mat4_copy(GLM_MAT4_IDENTITY, dest);

  /* random position */
  dest[3][0] = frand48();
  dest[3][1] = frand48();
  dest[3][2] = frand48();

  /* random rotatation around random axis with random angle */
  glm_rotate(dest, frand48(), (vec3){frand48(), frand48(), frand48()});

  /* random scale */
  /* glm_scale(dest, (vec3){frand48(), frand48(), frand48()}); */
}

void
test_rand_mat4x2(mat4x2 dest) {
  dest[0][0] = frand48();
  dest[0][1] = frand48();

  dest[1][0] = frand48();
  dest[1][1] = frand48();

  dest[2][0] = frand48();
  dest[2][1] = frand48();

  dest[3][0] = frand48();
  dest[3][1] = frand48();
}

void
test_rand_mat4x3(mat4x3 dest) {
  dest[0][0] = frand48();
  dest[0][1] = frand48();
  dest[0][2] = frand48();

  dest[1][0] = frand48();
  dest[1][1] = frand48();
  dest[1][2] = frand48();

  dest[2][0] = frand48();
  dest[2][1] = frand48();
  dest[2][2] = frand48();

  dest[3][0] = frand48();
  dest[3][1] = frand48();
  dest[3][2] = frand48();
}

void
test_rand_mat3(mat3 dest) {
  mat4 m4;

  /* random rotatation around random axis with random angle */
  glm_rotate_make(m4, frand48(), (vec3){frand48(), frand48(), frand48()});
  glm_mat4_pick3(m4, dest);
}

void
test_rand_mat3x2(mat3x2 dest) {
  dest[0][0] = frand48();
  dest[0][1] = frand48();
  dest[1][0] = frand48();
  dest[1][1] = frand48();
  dest[2][0] = frand48();
  dest[2][1] = frand48();
}

void
test_rand_mat3x4(mat3x4 dest) {
  dest[0][0] = frand48();
  dest[0][1] = frand48();
  dest[0][2] = frand48();
  dest[0][3] = frand48();

  dest[1][0] = frand48();
  dest[1][1] = frand48();
  dest[1][2] = frand48();
  dest[1][3] = frand48();

  dest[2][0] = frand48();
  dest[2][1] = frand48();
  dest[2][2] = frand48();
  dest[2][3] = frand48();
}

void
test_rand_mat2(mat2 dest) {
  dest[0][0] = frand48();
  dest[0][1] = frand48();
  dest[1][0] = frand48();
  dest[1][1] = frand48();
}

void
test_rand_mat2x3(mat2x3 dest) {
  dest[0][0] = frand48();
  dest[0][1] = frand48();
  dest[0][2] = frand48();
  dest[1][0] = frand48();
  dest[1][1] = frand48();
  dest[1][2] = frand48();
}

void
test_rand_mat2x4(mat2x4 dest) {
  dest[0][0] = frand48();
  dest[0][1] = frand48();
  dest[0][2] = frand48();
  dest[0][3] = frand48();
  dest[1][0] = frand48();
  dest[1][1] = frand48();
  dest[1][2] = frand48();
  dest[1][3] = frand48();
}

void
test_rand_transform2d(mat3 dest) {
  glm_translate2d_make(dest, (vec2) { frand48(), frand48() });
  glm_rotate2d(dest, frand48());
  glm_scale2d(dest, (vec2) { frand48(), frand48() });
}

void
test_rand_vec3(vec3 dest) {
  dest[0] = frand48();
  dest[1] = frand48();
  dest[2] = frand48();
}

vec3s
test_rand_vec3s(void) {
  vec3s r;
  test_rand_vec3(r.raw);
  return r;
}

void
test_rand_vec4(vec4 dest) {
  dest[0] = frand48();
  dest[1] = frand48();
  dest[2] = frand48();
  dest[3] = frand48();
}

vec4s
test_rand_vec4s(void) {
  vec4s r;
  test_rand_vec4(r.raw);
  return r;
}

float
test_rand(void) {
  return frand48();
}

void
test_rand_quat(versor q) {
  glm_quat(q, frand48(), frand48(), frand48(), frand48());
  glm_quat_normalize(q);
}

test_status_t
test_assert_mat4_eq(mat4 m1, mat4 m2) {
  int i, j;

  for (i = 0; i < 4; i++) {
    for (j = 0; j < 4; j++) {
      ASSERT(fabsf(m1[i][j] - m2[i][j]) <= 0.0000009f)
    }
  }

  TEST_SUCCESS
}

test_status_t
test_assert_mat4_eqt(mat4 m1, mat4 m2) {
  int i, j;

  for (i = 0; i < 4; i++) {
    for (j = 0; j < 4; j++) {
      ASSERT(fabsf(m1[j][i] - m2[i][j]) <= 0.0000009f)
    }
  }

  TEST_SUCCESS
}

test_status_t
test_assert_mat4_eq2(mat4 m1, mat4 m2, float eps) {
  int i, j;

  for (i = 0; i < 4; i++) {
    for (j = 0; j < 4; j++) {
      ASSERT(fabsf(m1[i][j] - m2[i][j]) <= eps);
    }
  }

  TEST_SUCCESS
}

test_status_t
test_assert_mat2_eqt(mat2 m1, mat2 m2) {
  int i, j;

  for (i = 0; i < 2; i++) {
    for (j = 0; j < 2; j++) {
      ASSERT(fabsf(m1[j][i] - m2[i][j]) <= 0.0000009f);
    }
  }

  TEST_SUCCESS
}

test_status_t
test_assert_mat2_eq(mat2 m1, mat2 m2) {
  int i, j;

  for (i = 0; i < 2; i++) {
    for (j = 0; j < 2; j++) {
      ASSERT(fabsf(m1[i][j] - m2[i][j]) <= 0.0000009f);
    }
  }

  TEST_SUCCESS
}

test_status_t
test_assert_mat2_eq_identity(mat2 m2) {
  int i, j;

  for (i = 0; i < 2; i++) {
    for (j = 0; j < 2; j++) {
      if (i == j) {
        ASSERT(test_eq(m2[i][j], 1.0f))
      } else {
        ASSERT(test_eq(m2[i][j], 0.0f))
      }
    }
  }

  TEST_SUCCESS
}

test_status_t
test_assert_mat2_eq_zero(mat2 m2) {
  int i, j;

  for (i = 0; i < 2; i++) {
    for (j = 0; j < 2; j++) {
      ASSERT(test_eq(m2[i][j], 0.0f))
    }
  }

  TEST_SUCCESS
}

test_status_t
test_assert_mat2x3_eq_zero(mat2x3 m2x3) {
  int i, j;

  for (i = 0; i < 2; i++) {
    for (j = 0; j < 3; j++) {
      ASSERT(test_eq(m2x3[i][j], 0.0f))
    }
  }

  TEST_SUCCESS
}

test_status_t
test_assert_mat2x3_eq(mat2x3 m1, mat2x3 m2) {
  int i, j;

  for (i = 0; i < 2; i++) {
    for (j = 0; j < 3; j++) {
      ASSERT(fabsf(m1[i][j] - m2[i][j]) <= 0.0000009f)
    }
  }

  TEST_SUCCESS
}

test_status_t
test_assert_mat2x4_eq_zero(mat2x4 m2x4) {
  int i, j;

  for (i = 0; i < 2; i++) {
    for (j = 0; j < 4; j++) {
      ASSERT(test_eq(m2x4[i][j], 0.0f))
    }
  }

  TEST_SUCCESS
}

test_status_t
test_assert_mat2x4_eq(mat2x4 m1, mat2x4 m2) {
  int i, j;

  for (i = 0; i < 2; i++) {
    for (j = 0; j < 4; j++) {
      ASSERT(fabsf(m1[i][j] - m2[i][j]) <= 0.0000009f)
    }
  }

  TEST_SUCCESS
}

test_status_t
test_assert_mat3_eq(mat3 m1, mat3 m2) {
  int i, j;

  for (i = 0; i < 3; i++) {
    for (j = 0; j < 3; j++) {
      ASSERT(fabsf(m1[i][j] - m2[i][j]) <= 0.0000009f);
    }
  }

  TEST_SUCCESS
}

test_status_t
test_assert_mat3_eqt(mat3 m1, mat3 m2) {
  int i, j;

  for (i = 0; i < 3; i++) {
    for (j = 0; j < 3; j++) {
      ASSERT(fabsf(m1[j][i] - m2[i][j]) <= 0.0000009f);
    }
  }

  TEST_SUCCESS
}

test_status_t
test_assert_mat3_eq_identity(mat3 m3) {
  int i, j;

  for (i = 0; i < 3; i++) {
    for (j = 0; j < 3; j++) {
      if (i == j) {
        ASSERT(test_eq(m3[i][j], 1.0f))
      } else {
        ASSERT(test_eq(m3[i][j], 0.0f))
      }
    }
  }

  TEST_SUCCESS
}

test_status_t
test_assert_mat3_eq_zero(mat3 m3) {
  int i, j;

  for (i = 0; i < 3; i++) {
    for (j = 0; j < 3; j++) {
      ASSERT(test_eq(m3[i][j], 0.0f))
    }
  }

  TEST_SUCCESS
}

test_status_t
test_assert_mat3x2_eq_zero(mat3x2 m3x2) {
  int i, j;

  for (i = 0; i < 3; i++) {
    for (j = 0; j < 2; j++) {
      ASSERT(test_eq(m3x2[i][j], 0.0f))
    }
  }

  TEST_SUCCESS
}

test_status_t
test_assert_mat3x2_eq(mat3x2 m1, mat3x2 m2) {
  int i, j;

  for (i = 0; i < 3; i++) {
    for (j = 0; j < 2; j++) {
      ASSERT(fabsf(m1[i][j] - m2[i][j]) <= 0.0000009f)
    }
  }

  TEST_SUCCESS
}

test_status_t
test_assert_mat3x4_eq_zero(mat3x4 m3x4) {
  int i, j;

  for (i = 0; i < 3; i++) {
    for (j = 0; j < 4; j++) {
      ASSERT(test_eq(m3x4[i][j], 0.0f))
    }
  }

  TEST_SUCCESS
}

test_status_t
test_assert_mat3x4_eq(mat3x4 m1, mat3x4 m2) {
  int i, j;

  for (i = 0; i < 3; i++) {
    for (j = 0; j < 4; j++) {
      ASSERT(fabsf(m1[i][j] - m2[i][j]) <= 0.0000009f)
    }
  }

  TEST_SUCCESS
}

test_status_t
test_assert_mat4_eq_identity(mat4 m4) {
  int i, j;

  for (i = 0; i < 4; i++) {
    for (j = 0; j < 4; j++) {
      if (i == j) {
        ASSERT(test_eq(m4[i][j], 1.0f))
      } else {
        ASSERT(test_eq(m4[i][j], 0.0f))
      }
    }
  }

  TEST_SUCCESS
}

test_status_t
test_assert_mat4_eq_zero(mat4 m4) {
  int i, j;

  for (i = 0; i < 4; i++) {
    for (j = 0; j < 4; j++) {
      ASSERT(test_eq(m4[i][j], 0.0f))
    }
  }

  TEST_SUCCESS
}

test_status_t
test_assert_mat4x2_eq_zero(mat4x2 m4x2) {
  int i, j;

  for (i = 0; i < 4; i++) {
    for (j = 0; j < 2; j++) {
      ASSERT(test_eq(m4x2[i][j], 0.0f))
    }
  }

  TEST_SUCCESS
}

test_status_t
test_assert_mat4x2_eq(mat4x2 m1, mat4x2 m2) {
  int i, j;

  for (i = 0; i < 4; i++) {
    for (j = 0; j < 2; j++) {
      ASSERT(fabsf(m1[i][j] - m2[i][j]) <= 0.0000009f)
    }
  }

  TEST_SUCCESS
}

test_status_t
test_assert_mat4x3_eq_zero(mat4x3 m4x3) {
  int i, j;

  for (i = 0; i < 4; i++) {
    for (j = 0; j < 3; j++) {
      ASSERT(test_eq(m4x3[i][j], 0.0f))
    }
  }

  TEST_SUCCESS
}

test_status_t
test_assert_mat4x3_eq(mat4x3 m1, mat4x3 m2) {
  int i, j;

  for (i = 0; i < 4; i++) {
    for (j = 0; j < 3; j++) {
      ASSERT(fabsf(m1[i][j] - m2[i][j]) <= 0.0000009f)
    }
  }

  TEST_SUCCESS
}

test_status_t
test_assert_eqf(float a, float b) {
  ASSERT(fabsf(a - b) <= 0.000009f); /* rounding errors */

  TEST_SUCCESS
}

test_status_t
test_assert_vec2_eq(vec2 v1, vec2 v2) {
  ASSERT(fabsf(v1[0] - v2[0]) <= 0.000009f); /* rounding errors */
  ASSERT(fabsf(v1[1] - v2[1]) <= 0.000009f);

  TEST_SUCCESS
}

test_status_t
test_assert_vec3_eq(vec3 v1, vec3 v2) {
  ASSERT(fabsf(v1[0] - v2[0]) <= 0.000009f); /* rounding errors */
  ASSERT(fabsf(v1[1] - v2[1]) <= 0.000009f);
  ASSERT(fabsf(v1[2] - v2[2]) <= 0.000009f);

  TEST_SUCCESS
}

test_status_t
test_assert_vec3s_eq(vec3s v1, vec3s v2) {
  test_assert_vec3_eq(v1.raw, v2.raw);

  TEST_SUCCESS
}

test_status_t
test_assert_vec4_eq(vec4 v1, vec4 v2) {
  ASSERT(fabsf(v1[0] - v2[0]) <= 0.000009f); /* rounding errors */
  ASSERT(fabsf(v1[1] - v2[1]) <= 0.000009f);
  ASSERT(fabsf(v1[2] - v2[2]) <= 0.000009f);
  ASSERT(fabsf(v1[3] - v2[3]) <= 0.000009f);

  TEST_SUCCESS
}

test_status_t
test_assert_vec4s_eq(vec4s v1, vec4s v2) {
  test_assert_vec4_eq(v1.raw, v2.raw);

  TEST_SUCCESS
}

test_status_t
test_assert_quat_eq_abs(versor v1, versor v2) {
  ASSERT(fabsf(fabsf(v1[0]) - fabsf(v2[0])) <= 0.0009f); /* rounding errors */
  ASSERT(fabsf(fabsf(v1[1]) - fabsf(v2[1])) <= 0.0009f);
  ASSERT(fabsf(fabsf(v1[2]) - fabsf(v2[2])) <= 0.0009f);
  ASSERT(fabsf(fabsf(v1[3]) - fabsf(v2[3])) <= 0.0009f);

  TEST_SUCCESS
}

test_status_t
test_assert_quat_eq(versor v1, versor v2) {
  ASSERT(fabsf(v1[0] - v2[0]) <= 0.000009f); /* rounding errors */
  ASSERT(fabsf(v1[1] - v2[1]) <= 0.000009f);
  ASSERT(fabsf(v1[2] - v2[2]) <= 0.000009f);
  ASSERT(fabsf(v1[3] - v2[3]) <= 0.000009f);

  TEST_SUCCESS
}

test_status_t
test_assert_quat_eq_identity(versor q) {
  versor p = GLM_QUAT_IDENTITY_INIT;

  ASSERT(fabsf(q[0] - p[0]) <= 0.000009f); /* rounding errors */
  ASSERT(fabsf(q[1] - p[1]) <= 0.000009f);
  ASSERT(fabsf(q[2] - p[2]) <= 0.000009f);
  ASSERT(fabsf(q[3] - p[3]) <= 0.000009f);

  TEST_SUCCESS
}
