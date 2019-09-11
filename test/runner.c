/*
 * Copyright (c), Recep Aslantas.
 *
 * MIT License (MIT), http://opensource.org/licenses/MIT
 * Full license can be found in the LICENSE file
 */

#include "include/common.h"
#include "tests.h"

#include <stdlib.h>

int
main(int argc, const char * argv[]) {
  test_entry_t *entry;
  test_status_t st;
  int32_t       i, count, passed, failed;

  passed = failed = 0;
  count  = sizeof(tests) / sizeof(tests[0]);
 
  fprintf(stderr, CYAN "\nWelcome to cglm tests\n\n" RESET);
  
  for (i = 0; i < count; i++) {
    entry = tests + i;
    st    = entry->entry();

    if (!st.status) {
      if (st.msg) {
        fprintf(stderr, "TEST FAIL (%s): %s\n", entry->name, st.msg);
      }

      failed++;
    } else {
      passed++;
    }
  }
  
  if (failed == 0) {
    fprintf(stderr, BOLDGREEN "  All tests are passed 🎉\n" RESET);
  }
 
  fprintf(stderr,
          CYAN "\ncglm test results:\n" RESET
          "------------------\n"
          
          BOLDMAGENTA "%d" RESET " tests are runned, "
          BOLDGREEN   "%d" RESET " are passed, "
          BOLDRED     "%d" RESET " are failed\n\n",
          passed + failed,
          passed,
          failed);

  return failed;
}
