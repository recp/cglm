/*
 * Copyright (c), Recep Aslantas.
 *
 * MIT License (MIT), http://opensource.org/licenses/MIT
 * Full license can be found in the LICENSE file
 */

#include "test_common.h"

TEST_IMPL(perspective_lh_no) {
  mat4 dst;
  const float fovy     = glm_rad(45.0f);
  const float aspect   = 640/480.0f;
  const float zNearVal = 0.1f;
  const float zFarVal  = 100.0f;

  glm_perspective_lh_no(fovy, aspect, zNearVal, zFarVal, dst);

  /* Sanity mk. I: longhand version */
  ASSERT(test_eq(dst[0][0],  1.0f / (tanf(fovy / 2) * aspect)))
  ASSERT(test_eq(dst[1][1],  1.0f / tanf(fovy / 2)))
  ASSERT(test_eq(dst[2][2],  (zFarVal + zNearVal) / (zFarVal - zNearVal)))
  ASSERT(test_eq(dst[2][3],  1.0f))
  ASSERT(test_eq(dst[3][2], -2 * zFarVal * zNearVal / (zFarVal - zNearVal)))

  /* Sanity mk. II */
  /*reference test data for glm_perspective_lh_no*/
  mat4 cmp = {0};
  cmp[0][0] =  1.8106601f;
  cmp[1][1] =  2.4142134f;
  cmp[2][2] =  1.0020020f;
  cmp[2][3] =  1.0000000f;
  cmp[3][2] = -0.2002002f;

  return test_assert_mat4_eq(dst, cmp);
}
