/*
 * Copyright (c), Recep Aslantas.
 *
 * MIT License (MIT), http://opensource.org/licenses/MIT
 * Full license can be found in the LICENSE file
 */

#include "test_common.h"

TEST_IMPL(GLM_PREFIX, unprojecti) {
  mat4 model, view, proj, mvp;
  vec4 viewport = {0.0f, 0.0f, 800.0f, 600.0f};
  vec3 pos      = {13.0f, 45.0f, 0.74f};
  vec3 projected, unprojected;

  glm_translate_make(model, (vec3){0.0f, 0.0f, -10.0f});
  glm_lookat((vec3){0.0f, 0.0f, 0.0f}, pos, GLM_YUP, view);

  glm_perspective_default(0.5f, proj);
  glm_mat4_mulN((mat4 *[]){&proj, &view, &model}, 3, mvp);

  GLM(project)(pos, mvp, viewport, projected);

  glm_mat4_inv(mvp, mvp);
  GLM(unprojecti)(projected, mvp, viewport, unprojected);

  /* unprojected of projected vector must be same as original one */
  /* we used 0.01 because of projection floating point errors */
#ifndef CGLM_FAST_MATH
  ASSERT(fabsf(pos[0] - unprojected[0]) < 0.01)
  ASSERT(fabsf(pos[1] - unprojected[1]) < 0.01)
  ASSERT(fabsf(pos[2] - unprojected[2]) < 0.01)
#else
  ASSERT(fabsf(pos[0] - unprojected[0]) < 0.1)
  ASSERT(fabsf(pos[1] - unprojected[1]) < 0.1)
  ASSERT(fabsf(pos[2] - unprojected[2]) < 0.1)
#endif

  TEST_SUCCESS
}

TEST_IMPL(GLM_PREFIX, unproject) {
  mat4 model, view, proj, mvp;
  vec4 viewport = {0.0f, 0.0f, 800.0f, 600.0f};
  vec3 pos      = {13.0f, 45.0f, 0.74f};
  vec3 projected, unprojected;

  glm_translate_make(model, (vec3){0.0f, 0.0f, -10.0f});
  glm_lookat((vec3){0.0f, 0.0f, 0.0f}, pos, GLM_YUP, view);

  glm_perspective_default(0.5f, proj);
  glm_mat4_mulN((mat4 *[]){&proj, &view, &model}, 3, mvp);

  GLM(project)(pos, mvp, viewport, projected);
  GLM(unproject)(projected, mvp, viewport, unprojected);

  /* unprojected of projected vector must be same as original one */
  /* we used 0.01 because of projection floating point errors */

#ifndef CGLM_FAST_MATH
  ASSERT(fabsf(pos[0] - unprojected[0]) < 0.01)
  ASSERT(fabsf(pos[1] - unprojected[1]) < 0.01)
  ASSERT(fabsf(pos[2] - unprojected[2]) < 0.01)
#else
  ASSERT(fabsf(pos[0] - unprojected[0]) < 0.1)
  ASSERT(fabsf(pos[1] - unprojected[1]) < 0.1)
  ASSERT(fabsf(pos[2] - unprojected[2]) < 0.1)
#endif

  TEST_SUCCESS
}

TEST_IMPL(GLM_PREFIX, project) {
  mat4 model, view, proj, mvp;
  vec4 viewport = {0.0f, 0.0f, 800.0f, 600.0f};
  vec3 pos      = {13.0f, 45.0f, 0.74f};
  vec3 projected, unprojected;

  glm_translate_make(model, (vec3){0.0f, 0.0f, -10.0f});
  glm_lookat((vec3){0.0f, 0.0f, 0.0f}, pos, GLM_YUP, view);

  glm_perspective_default(0.5f, proj);
  glm_mat4_mulN((mat4 *[]){&proj, &view, &model}, 3, mvp);

  GLM(project)(pos, mvp, viewport, projected);
  GLM(unproject)(projected, mvp, viewport, unprojected);

  /* unprojected of projected vector must be same as original one */
  /* we used 0.01 because of projection floating point errors */

#ifndef CGLM_FAST_MATH
  ASSERT(fabsf(pos[0] - unprojected[0]) < 0.01)
  ASSERT(fabsf(pos[1] - unprojected[1]) < 0.01)
  ASSERT(fabsf(pos[2] - unprojected[2]) < 0.01)
#else
  ASSERT(fabsf(pos[0] - unprojected[0]) < 0.1)
  ASSERT(fabsf(pos[1] - unprojected[1]) < 0.1)
  ASSERT(fabsf(pos[2] - unprojected[2]) < 0.1)
#endif

  /* test with no projection */
  glm_mat4_identity(mvp);

  GLM(project)(pos, mvp, viewport, projected);
  GLM(unproject)(projected, mvp, viewport, unprojected);

  ASSERT(test_eq(pos[0], unprojected[0]))
  ASSERT(test_eq(pos[1], unprojected[1]))
  ASSERT(test_eq(pos[2], unprojected[2]))

  TEST_SUCCESS
}
