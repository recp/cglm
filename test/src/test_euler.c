/*
 * Copyright (c), Recep Aslantas.
 *
 * MIT License (MIT), http://opensource.org/licenses/MIT
 * Full license can be found in the LICENSE file
 */

#include "test_common.h"

void
test_euler(void **state) {
  mat4  rot1, rot2;
  vec3  inAngles, outAngles;

  inAngles[0] = glm_rad(-45.0f);  /* X angle */
  inAngles[1] = glm_rad(88.0f);   /* Y angle */
  inAngles[2] = glm_rad(18.0f);   /* Z angle */

  glm_euler_xyz(inAngles, rot1);

  /* extract angles */
  glmc_euler_angles(rot1, outAngles);

  /* angles must be equal in that range */
  test_assert_vec3_eq(inAngles, outAngles);

  /* matrices must be equal */
  glmc_euler_xyz(outAngles, rot2);
  test_assert_mat4_eq(rot1, rot2);

  /* change range */
  inAngles[0] = glm_rad(-145.0f);  /* X angle */
  inAngles[1] = glm_rad(818.0f);   /* Y angle */
  inAngles[2] = glm_rad(181.0f);   /* Z angle */

  glm_euler_xyz(inAngles, rot1);
  glmc_euler_angles(rot1, outAngles);

  /* angles may not be equal but matrices MUST! */

  /* matrices must be equal */
  glmc_euler_xyz(outAngles, rot2);
  test_assert_mat4_eq(rot1, rot2);
}
