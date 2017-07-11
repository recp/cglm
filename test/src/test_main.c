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
  };

  return cmocka_run_group_tests(tests,
                                NULL,
                                NULL);
}
