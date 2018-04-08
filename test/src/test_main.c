/*
 * Copyright (c), Recep Aslantas.
 * MIT License (MIT), http://opensource.org/licenses/MIT
 */

#include "test_common.h"
#include "test_tests.h"

int
main(int argc, const char * argv[]) {
  const struct CMUnitTest tests[] = {
    /* mat4 */
    cmocka_unit_test(test_mat4),

    /* camera */
    cmocka_unit_test(test_camera_lookat),
    cmocka_unit_test(test_camera_decomp),

    /* project */
    cmocka_unit_test(test_project),

    /* vector */
    cmocka_unit_test(test_clamp),

    /* euler */
    cmocka_unit_test(test_euler),

    /* quaternion */
    cmocka_unit_test(test_quat),

    /* vec4 */
    cmocka_unit_test(test_vec4)
  };

  return cmocka_run_group_tests(tests, NULL, NULL);
}
