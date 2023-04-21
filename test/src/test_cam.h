/*
 * Copyright (c), Recep Aslantas.
 *
 * MIT License (MIT), http://opensource.org/licenses/MIT
 * Full license can be found in the LICENSE file
 */

#include "test_common.h"

TEST_IMPL(GLM_PREFIX, frustum) {
  mat4  proj;
  vec4  vp = {0.0f, 0.0f, 800.0f, 600.0f};
  float left, right, top, bottom, znear, zfar;

  znear  =  0.1f;
  zfar   =  100.0f;
  left   = -100.0f;
  right  =  100.0f;
  bottom = -100.0f;
  top    =  100.0f;

  GLM(frustum)(left, right, bottom, top, znear, zfar, proj);

  ASSERT(test_eq(proj[0][1], 0.0f))
  ASSERT(test_eq(proj[0][2], 0.0f))
  ASSERT(test_eq(proj[0][3], 0.0f))

  ASSERT(test_eq(proj[1][0], 0.0f))
  ASSERT(test_eq(proj[1][2], 0.0f))
  ASSERT(test_eq(proj[1][3], 0.0f))

  ASSERT(test_eq(proj[2][3], -1.0f))

  ASSERT(test_eq(proj[3][0], 0.0f))
  ASSERT(test_eq(proj[3][1], 0.0f))
  ASSERT(test_eq(proj[3][3], 0.0f))

  vec4  v1 = {1.0f, 20.0f, znear};
  vec4  v2 = {1.0f, 20.0f, zfar};
  vec4  v3, v4;

  /* perspective test */
  GLM(mat4_mulv)(proj, v1, v3);
  GLM(project)(v3, proj, vp, v3);

  ASSERT(v3[0] > v1[0])
  ASSERT(v3[1] > v1[1])

  GLM(mat4_mulv)(proj, v2, v4);
  GLM(project)(v4, proj, vp, v4);

  ASSERT(v4[0] < v3[0])
  ASSERT(v4[1] < v3[1])

  /* not infinity */
  ASSERT(!GLM(vec4_isinf)(proj[0]))
  ASSERT(!GLM(vec4_isinf)(proj[1]))
  ASSERT(!GLM(vec4_isinf)(proj[2]))
  ASSERT(!GLM(vec4_isinf)(proj[3]))

  /* not NaN */
  ASSERT(!GLM(vec4_isnan)(proj[0]))
  ASSERT(!GLM(vec4_isnan)(proj[1]))
  ASSERT(!GLM(vec4_isnan)(proj[2]))
  ASSERT(!GLM(vec4_isnan)(proj[3]))

  TEST_SUCCESS
}

TEST_IMPL(GLM_PREFIX, camera_lookat) {
  mat4 view1, view2;
  vec3 center,
       eye = {0.024f, 14.6f, 67.04f},
       dir = {0.0f, 0.0f, -1.0f},
       up  = {0.0f, 1.0f, 0.0f};

  glm_vec3_add(eye, dir, center);
  glm_lookat(eye, center, up, view1);

  glm_look(eye, dir, up, view2);

  ASSERTIFY(test_assert_mat4_eq(view1, view2))

  TEST_SUCCESS
}

TEST_IMPL(GLM_PREFIX, camera_decomp) {
  mat4  proj, proj2;
  vec4  sizes;
  float aspect, fovy, nearZ, farZ;

  aspect  = 0.782f;
  fovy    = glm_rad(49.984f);
  nearZ   = 0.1f;
  farZ    = 100.0f;

  glm_perspective(fovy, aspect, nearZ, farZ, proj);
  ASSERT(fabsf(aspect  - glm_persp_aspect(proj)) < GLM_FLT_EPSILON)
  ASSERT(fabsf(fovy    - glm_persp_fovy(proj))   < GLM_FLT_EPSILON)
  ASSERT(fabsf(49.984f - glm_deg(glm_persp_fovy(proj))) < GLM_FLT_EPSILON)

  glm_persp_sizes(proj, fovy, sizes);

  glm_frustum(-sizes[0] * 0.5f,
               sizes[0] * 0.5f,
              -sizes[1] * 0.5f,
               sizes[1] * 0.5f,
               nearZ,
               farZ,
               proj2);

  ASSERTIFY(test_assert_mat4_eq(proj, proj2))

  TEST_SUCCESS
}
